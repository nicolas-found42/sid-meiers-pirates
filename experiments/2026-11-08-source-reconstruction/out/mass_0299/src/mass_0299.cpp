// Sid Meier's Pirates! (2004) reconstruction — batch mass_0299
// Provider: Ghidra 12.2 pseudocode; PE32 i386. Names are FUN_<address>.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- helpers referenced by the assigment listings -------------------------
extern void* FUN_00533c78(uint32_t size);
extern void operator_delete(void* ptr);
extern void FUN_00412770(void* self, uint32_t size, uint32_t cookie, void (*dtor)());
extern void FUN_004127b0(void* dst, uint32_t size, int32_t count, void* ctor);
extern void FUN_00646ae9();
extern void FUN_0063e40b();
extern void FUN_00641a99();
extern void FUN_0064058d(uint8_t* a, uint8_t* b, uint8_t* c, uint32_t d, uint32_t e, uint32_t f);
extern void FUN_00640dc6(uint8_t* a, uint8_t* b, uint8_t* c, uint32_t d, uint32_t e);
extern uint32_t FUN_00641260(uint32_t a);
extern int32_t FUN_006294f9(uint32_t value, void* out);
extern void FUN_0063e62c(uint32_t obj);
extern int32_t FUN_0063eb76(uint32_t a, void* b, void* c);
extern uint32_t FUN_0063ec91(uint32_t a, void* b, void* c);
extern int32_t FUN_0060afb7(int32_t* a, uint32_t* b, uint32_t* c);
extern int32_t FUN_006439a7(int32_t a, int32_t b, int32_t* c);
extern uint16_t FUN_0063dc77(uint32_t* value, int32_t count);
extern int32_t FUN_0063ea6b(uint32_t a, int32_t b);
extern int32_t FUN_0063f27d(uint32_t a, int32_t b);
extern int32_t FUN_0063f23c(uint32_t a, int32_t b);
extern int32_t FUN_0063da83(uint16_t handle, uint32_t a, int32_t b);
extern void thunk_FUN_005f2399(void* a, void* b);
extern int32_t FUN_0063f9ca(uint32_t a, uint32_t b, uint32_t c);
extern int32_t FUN_0063f926(uint32_t a, uint32_t b, uint32_t c);
extern int32_t FUN_0063f86e(uint32_t a, uint32_t b, uint32_t c);
extern int32_t FUN_00640a26(int32_t** a, int32_t** b, uint32_t** c, int32_t d, int32_t* e);
extern void FUN_00641ac9(void* a, void* b, void* c, uint32_t d, uint32_t e, void* f, uint32_t g);
extern void FUN_00641ef0(void* a, void* b, void* c, uint32_t d, uint32_t e, void* f, uint32_t g);
extern void FUN_00642362(void* a, void* b, void* c, uint32_t d, uint32_t e, void* f, uint32_t g);
extern void FUN_0064270e(void* a, void* b, void* c, uint32_t d, uint32_t e, void* f, uint32_t g);
extern void FUN_00642b18(void* a, void* b, void* c, uint32_t d, uint32_t e, void* f, uint32_t g);
extern int32_t FUN_00642e5e(uint32_t a, uint32_t b);
extern void FUN_005f8ea2(int32_t a);
extern int32_t ftol();
extern void LAB_0063e2f2();

// table @ 0x6eac9c .. 0x6eacac (0x1c-byte records); referenced individually.
extern uint8_t DAT_006eac9c;
extern uint8_t DAT_006eaca0;
extern uint8_t DAT_006eaca4;
extern uint8_t DAT_006eaca8;
extern uint8_t DAT_006eacac;

// 0x643f6c — observed shape
// Clears bit 0 of (arg+0x14), re-acquires both cached interfaces from the
// object at (arg+4) (vtbl+0x10 and vtbl+0xc), rebuilds the (arg+8) interface
// through FUN_006294f9 when absent or too small, then feeds the secondary
// object's vtbl+0xc value into the primary vtbl+0x10. When that result is
// non-negative and the secondary object is not self[3], releases the primary
// interface and calls FUN_0063e62c. Temporary interfaces are always released.
int FUN_00643f6c(void* self_, uint32_t param_1)
{
    const int32_t self = (int32_t)(uintptr_t)self_;
    int32_t* local_8 = nullptr;
    int32_t* local_c = nullptr;
    int32_t iVar3;
    uint32_t uVar2 = param_1;
    uint32_t uVar4;
    int32_t uVar5;
    int32_t primary;
    int32_t primaryVtbl;
    int32_t secondary;
    int32_t secondaryVtbl;
    int32_t piVar1;

    *(uint32_t*)(param_1 + 0x14) = *(uint32_t*)(param_1 + 0x14) & 0xfffffffeu;

    primary = *(int32_t*)(param_1 + 4);
    primaryVtbl = *(int32_t*)primary;
    iVar3 = ((int32_t(*)(int32_t, int32_t, uint32_t*))(*(int32_t*)(primaryVtbl + 0x10)))(primary, 0, &param_1);
    if (iVar3 < 0) goto LAB_00644038;

    primary = *(int32_t*)(uVar2 + 4);
    primaryVtbl = *(int32_t*)primary;
    iVar3 = ((int32_t(*)(int32_t, int32_t**))(*(int32_t*)(primaryVtbl + 0xc)))(primary, &local_c);
    if (iVar3 < 0) goto LAB_00644038;

    piVar1 = *(int32_t*)(uVar2 + 8);
    if (piVar1 == 0) {
    LAB_00643fca:
        iVar3 = FUN_006294f9(param_1, &local_8);
        if (iVar3 < 0) goto LAB_00644038;
        piVar1 = *(int32_t*)(uVar2 + 8);
        if (piVar1 != 0) {
            ((void(*)(int32_t))(*(int32_t*)(*(int32_t*)piVar1 + 8)))(piVar1);
            *(uint32_t*)(uVar2 + 8) = 0;
        }
        *(int32_t*)(uVar2 + 8) = (int32_t)(uintptr_t)local_8;
        local_8 = nullptr;
    } else {
        uVar4 = ((uint32_t(*)(int32_t))(*(int32_t*)(*(int32_t*)piVar1 + 0x10)))(piVar1);
        if (uVar4 < param_1) goto LAB_00643fca;
    }

    primary = *(int32_t*)(uVar2 + 4);
    primaryVtbl = *(int32_t*)primary;
    secondary = *(int32_t*)(uVar2 + 8);
    secondaryVtbl = *(int32_t*)secondary;
    uVar5 = ((int32_t(*)(int32_t, uint32_t*))(*(int32_t*)(secondaryVtbl + 0xc)))(secondary, &param_1);
    iVar3 = ((int32_t(*)(int32_t, int32_t))(*(int32_t*)(primaryVtbl + 0x10)))(primary, uVar5);
    if (-1 < iVar3 && local_c != *(int32_t**)(self + 0xc)) {
        piVar1 = *(int32_t*)(uVar2 + 4);
        if (piVar1 != 0) {
            ((void(*)(int32_t))(*(int32_t*)(*(int32_t*)piVar1 + 8)))(piVar1);
            *(uint32_t*)(uVar2 + 8) = 0;
        }
        FUN_0063e62c(uVar2);
    }
LAB_00644038:
    if (local_8 != nullptr) {
        ((void(*)(int32_t*))(*(int32_t*)(*local_8 + 8)))(local_8);
        local_8 = nullptr;
    }
    if (local_c != nullptr) {
        ((void(*)(int32_t*))(*(int32_t*)(*local_c + 8)))(local_c);
    }
    return iVar3;
}

// 0x64405e — observed shape
// Scalar/vector deleting-destructor thunk for a 0x28-byte object: runs
// FUN_00646ae9 for the non-vector case, or delegates to FUN_00412770 with the
// stored allocation size when the vector-delete flag bit 1 is set. Bit 0
// releases storage, using the pointer preceding the object for vectors.
void FUN_0064405e(void* self, uint8_t param_1)
{
    if ((param_1 & 2) == 0) {
        FUN_00646ae9();
        if ((param_1 & 1) != 0) {
            operator_delete(self);
        }
    } else {
        FUN_00412770(self, 0x28, *(uint32_t*)((char*)self - 4), FUN_00646ae9);
        if ((param_1 & 1) != 0) {
            operator_delete((char*)self - 4);
        }
    }
}

// 0x6440ac — observed shape
// Scalar/vector deleting-destructor thunk for a 0x18-byte object: runs
// FUN_0063e40b, or vector-deletes through FUN_00412770 with the recorded
// allocation size. Bit 0 releases storage.
void FUN_006440ac(void* self, uint8_t param_1)
{
    if ((param_1 & 2) == 0) {
        FUN_0063e40b();
        if ((param_1 & 1) != 0) {
            operator_delete(self);
        }
    } else {
        FUN_00412770(self, 0x18, *(uint32_t*)((char*)self - 4), FUN_0063e40b);
        if ((param_1 & 1) != 0) {
            operator_delete((char*)self - 4);
        }
    }
}

// 0x6440fa — observed shape
// Resolves a surface-level descriptor from self[0x2c][param_1[5]] plus
// param_1[6] (adding self[8], or self[0xe][4] when the owner's +0x40 is set),
// then copies local_8 rows using the row kind at descriptor+4: <2 dword copy
// with a per-row stride of uVar2, <4 strip-copy with thunk_FUN_005f2399 per
// row, ==5 the packed FUN_0063eb76 path with the owner's vtbl+0x50 callback.
// Advances the caller's cursor by 0x10 / 0x40 / iVar6 bytes respectively.
int FUN_006440fa(void* self_, int32_t* param_1, int32_t* param_2, int32_t* param_3, int32_t* param_4)
{
    const int32_t* self = (const int32_t*)self_;
    int32_t* piVar4 = param_1;
    int32_t* piVar11;
    const int32_t* piVar1 = piVar4;
    int32_t iVar6;
    int32_t iVar5;
    uint32_t local_8;
    uint32_t local_14 = 0;
    uint32_t uVar7;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t* puVar8;
    uint32_t* puVar9;
    uint32_t* puVar10;
    int32_t* puVar1;

    iVar6 = *(int32_t*)(self[0x2c] + param_1[5] * 4);
    if (*(int32_t*)(iVar6 + 0x40) == 0) {
        iVar5 = self[8];
    } else {
        iVar5 = *(int32_t*)(self[0xe] + 0x10);
    }
    iVar5 = *(int32_t*)(iVar6 + 0x2c) + param_1[6] + iVar5;
    local_8 = *(uint32_t*)(iVar5 + 0x10);
    uVar7 = *(uint32_t*)(iVar5 + 4);
    if (local_8 < 2) {
        local_8 = 1;
    }
    uVar2 = *(uint32_t*)(iVar5 + 0x14);
    uVar3 = *(uint32_t*)(iVar5 + 0x18);

    if (uVar7 < 2) {
        piVar11 = param_1 + 0xc;
        param_1 = (int32_t*)(*param_2 + self[8]);
        puVar8 = (uint32_t*)(*piVar11 + self[8]);
        if (local_8 != 0) {
            param_4 = (int32_t*)local_8;
            do {
                puVar10 = puVar8;
                puVar9 = (uint32_t*)param_1;
                for (uVar7 = uVar2 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *puVar9 = *puVar10;
                    puVar10 = puVar10 + 1;
                    puVar9 = puVar9 + 1;
                }
                puVar8 = puVar8 + uVar2;
                param_1 = param_1 + 4;
                param_4 = (int32_t*)((int32_t)param_4 - 1);
                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *(uint8_t*)puVar9 = *(uint8_t*)puVar10;
                    puVar10 = (uint32_t*)((int32_t)puVar10 + 1);
                    puVar9 = (uint32_t*)((int32_t)puVar9 + 1);
                }
            } while (param_4 != nullptr);
        }
        piVar4[0xc] = *param_2;
        *param_2 = *param_2 + local_8 * 0x10;
    } else if (uVar7 < 4) {
        puVar8 = (uint32_t*)(param_1[0xc] + self[8]);
        param_1 = (int32_t*)(*param_3 + self[8]);
        piVar11 = param_3;
        if (local_8 != 0) {
            param_2 = (int32_t*)puVar8;
            local_14 = local_8;
            do {
                puVar10 = (uint32_t*)param_1;
                if (uVar2 != 0) {
                    puVar9 = puVar8;
                    param_4 = (int32_t*)uVar2;
                    do {
                        puVar8 = (uint32_t*)(param_2 + uVar3);
                        puVar1 = param_1 + 4;
                        for (uVar7 = uVar3 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
                            *param_1 = (int32_t)*puVar9;
                            puVar9 = puVar9 + 1;
                            param_1 = param_1 + 1;
                        }
                        param_4 = (int32_t*)((int32_t)param_4 - 1);
                        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                            *(uint8_t*)param_1 = *(uint8_t*)puVar9;
                            puVar9 = (uint32_t*)((int32_t)puVar9 + 1);
                            param_1 = (int32_t*)((int32_t)param_1 + 1);
                        }
                        puVar9 = puVar8;
                        param_1 = puVar1;
                        param_2 = (int32_t*)puVar8;
                    } while (param_4 != nullptr);
                    param_4 = nullptr;
                    piVar11 = param_3;
                }
                param_1 = param_1 + (4 - uVar2) * 4;
                thunk_FUN_005f2399(puVar10, puVar10);
                local_14 = local_14 - 1;
            } while (local_14 != 0);
        }
        piVar4[0xc] = *piVar11;
        *piVar11 = *piVar11 + local_8 * 0x40;
    } else if (uVar7 == 5) {
        param_3 = (int32_t*)param_1[0xc];
        param_2 = (int32_t*)param_1[0xb];
        iVar6 = FUN_0063eb76(self[8], &param_2, &param_3);
        param_1[0xc] = *param_4;
        *param_4 = *param_4 + iVar6;
        *param_1 = param_1[0xc] + self[8];
        param_1[1] = self[8] + param_1[0xb];
        iVar6 = ((int32_t(*)(void*))(*(int32_t*)(*self + 0x50)))((void*)self);
        if (iVar6 < 0) {
            return iVar6;
        }
    }
    return 0;
}

// 0x6442a6 — observed shape
// Re-encodes one 0x64-byte record at self->+0x2c[param_1]->+0x4 + param_2*100
// from a four-dword parameter stream (param_4 is the cursor): bytes +0x52,
// dwords +0x54, +0x20, +0x24, validated against the 0x1c-byte format table at
// 0x6eac9c..0x6eacac. The format id then selects the row-size computation
// (<<4, <<2, 4, or pitch*count*4) and a few side effects on the owning
// surface's +0x18/+0x20 tables and on the record's +0x56/+0x58 fields.
uint32_t FUN_006442a6(void* self_, uint32_t param_1, uint32_t param_2, int32_t* param_3, uint32_t* param_4)
{
    const int32_t self = (int32_t)(uintptr_t)self_;
    uint16_t uVar2 = 0;
    uint16_t uVar3 = 0;
    uint32_t uVar4;
    int32_t iVar5;
    int32_t iVar6 = 0;
    uint32_t* puVar7;
    int32_t iVar8;

    iVar8 = (int32_t)((param_1 & 0xffff) * 100) + *(int32_t*)(self + 0x2c);
    puVar7 = (uint32_t*)(((param_2 & 0xffff) * 100) + *(int32_t*)(iVar8 + 4));
    *puVar7 = 0;
    puVar7[7] = 0;

    if (param_3 != nullptr &&
        (uVar4 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3), *param_4 + 1 <= uVar4)) {
        iVar5 = ((int32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0xc)))(param_3);
        *(uint32_t*)((int32_t)puVar7 + 0x52) = *(uint32_t*)(iVar5 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;

    if (param_3 != nullptr &&
        (uVar4 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3), *param_4 + 1 <= uVar4)) {
        iVar5 = ((int32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0xc)))(param_3);
        puVar7[0x15] = *(uint32_t*)(iVar5 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;

    if (param_3 != nullptr &&
        (uVar4 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3), *param_4 + 1 <= uVar4)) {
        iVar5 = ((int32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0xc)))(param_3);
        puVar7[8] = *(uint32_t*)(iVar5 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;

    if (param_3 != nullptr &&
        (uVar4 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3), *param_4 + 1 <= uVar4)) {
        iVar5 = ((int32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0xc)))(param_3);
        puVar7[9] = *(uint32_t*)(iVar5 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;

    if (param_3 == nullptr) return 0x80004005;
    uVar4 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3);
    if (uVar4 < *param_4 || 0xb5 < *(uint16_t*)((int32_t)puVar7 + 0x52)) {
        return 0x80004005;
    }

    iVar5 = (int32_t)((uint32_t)*(uint16_t*)((int32_t)puVar7 + 0x52) * 0x1c);
    uVar4 = *(uint32_t*)(&DAT_006eaca8 + iVar5);
    if (uVar4 != 0 && uVar4 <= *(uint16_t*)(puVar7 + 0x15)) {
        return 0x80004005;
    }
    if (uVar4 == 0x105) {
        uVar2 = *(uint16_t*)(puVar7 + 0x15);
        if ((uVar2 < 0x10 || uVar2 == 0x101) ||
            (uVar2 == 0x102 || (uVar2 == 0x103 || uVar2 == 0x104))) {
            if (*(int32_t*)(&DAT_006eacac + iVar5) == 0x300000d) {
                return 0x80004005;
            }
        } else if (uVar2 != 0x100) {
            return 0x80004005;
        }
    }

    *(uint16_t*)((int32_t)puVar7 + 0x56) = 0;
    uVar4 = *(uint32_t*)(&DAT_006eacac + iVar5);
    puVar7[0x16] = uVar4;

    if (uVar4 < 0xc020001) {
        if (uVar4 == 0xc020000) {
        LAB_0064466d:
            param_2 = puVar7[8] + *(int32_t*)(self + 0x20);
            uVar2 = FUN_0063dc77(&param_2, 4);
            *(uint16_t*)((int32_t)puVar7 + 0x56) = uVar2;
        } else {
            if (uVar4 < 0xc000002) {
                if (uVar4 != 0xc000001) {
                    if (uVar4 == 0x9000000) {
                        *(uint32_t*)(*(int32_t*)(self + 0x18) +
                                     *(int32_t*)(puVar7[9] + *(int32_t*)(self + 0x20)) * 0x18) =
                            *(uint32_t*)(&DAT_006eac9c + iVar5);
                    } else {
                        if (uVar4 == 0xa000000) {
                            *(uint16_t*)(iVar8 + 0x18) = (uint16_t)param_2;
                        } else {
                            if (uVar4 != 0xb000000) {
                                if (uVar4 == 0xc000000) goto LAB_006445ba;
                                goto LAB_00644619;
                            }
                            *(uint16_t*)(iVar8 + 0x1a) = (uint16_t)param_2;
                        }
                        *(uint32_t*)(*(int32_t*)(self + 0x18) +
                                     *(int32_t*)(puVar7[9] + *(int32_t*)(self + 0x20)) * 0x18) =
                            *(uint32_t*)(&DAT_006eac9c +
                                         (uint32_t)*(uint16_t*)((int32_t)puVar7 + 0x52) * 0x1c);
                    }
                    *puVar7 = 0;
                    puVar7[0xc] = puVar7[0xc] & 0xfffffffd;
                    *(uint16_t*)((int32_t)puVar7 + 0x56) = 1;
                    goto LAB_006444a6;
                }
            } else {
                if (uVar4 != 0xc000002) {
                    if (uVar4 != 0xc000003) {
                        if (uVar4 != 0xc000004) {
                            if (uVar4 == 0xc010000) goto LAB_006444d8;
                            goto LAB_00644619;
                        }
                        goto LAB_0064456a;
                    }
                    goto LAB_00644570;
                }
            LAB_00644574:
                *(int16_t*)((int32_t)puVar7 + 0x56) = *(int16_t*)((int32_t)puVar7 + 0x56) + 1;
            }
        LAB_00644578:
            *(int16_t*)((int32_t)puVar7 + 0x56) = *(int16_t*)((int32_t)puVar7 + 0x56) + 1;
            iVar5 = *(int32_t*)(&DAT_006eacac + iVar5);
            if (iVar5 == 0xd000001 || iVar5 == 0xd000002 ||
                iVar5 == 0xd000003 || iVar5 == 0xd000004) {
                *(uint16_t*)((int32_t)puVar7 + 0x52) = 0x9c;
                puVar7[0x16] = 0xd000000;
            } else {
                *(uint16_t*)((int32_t)puVar7 + 0x52) = 0x94;
                puVar7[0x16] = 0xc000000;
            }
        LAB_006445ba:
            if (*(int32_t*)(&DAT_006eacac +
                            (uint32_t)*(uint16_t*)((int32_t)puVar7 + 0x52) * 0x1c) == 0xd000000 ||
                *(int32_t*)(&DAT_006eacac +
                            (uint32_t)*(uint16_t*)((int32_t)puVar7 + 0x52) * 0x1c) == 0xc000000) {
                param_2 = puVar7[8] + *(int32_t*)(self + 0x20);
                uVar3 = FUN_0063dc77(&param_2, 4);
                *(uint16_t*)((int32_t)puVar7 + 0x56) = uVar3;
            }
            uVar2 = *(uint16_t*)((int32_t)puVar7 + 0x56);
        }
        iVar6 = (uint32_t)uVar2 << 4;
        *puVar7 = 1;
    } else {
        if (uVar4 < 0xd000005) {
            if (uVar4 == 0xd000004) {
            LAB_0064456a:
                *(uint16_t*)((int32_t)puVar7 + 0x56) = 1;
            LAB_00644570:
                *(int16_t*)((int32_t)puVar7 + 0x56) = *(int16_t*)((int32_t)puVar7 + 0x56) + 1;
                goto LAB_00644574;
            }
            if (uVar4 == 0xd000000) goto LAB_006445ba;
            if (uVar4 == 0xd000001) goto LAB_00644578;
            if (uVar4 == 0xd000002) goto LAB_00644574;
            if (uVar4 == 0xd000003) goto LAB_00644570;
        } else {
            if (uVar4 == 0xd010000) {
            LAB_006444d8:
                param_2 = puVar7[8] + *(int32_t*)(self + 0x20);
                uVar2 = FUN_0063dc77(&param_2, 1);
                *(uint16_t*)((int32_t)puVar7 + 0x56) = uVar2;
                iVar6 = (uint32_t)uVar2 << 2;
                *puVar7 = 1;
                goto LAB_006444fd;
            }
            if (uVar4 == 0xd020000) goto LAB_0064466d;
            if (uVar4 == 0xe000000 || uVar4 == 0xf000000) {
                *(uint16_t*)((int32_t)puVar7 + 0x56) = 1;
                *(int16_t*)(iVar8 + 0x34) = *(int16_t*)(iVar8 + 0x34) + 1;
                *puVar7 = 0;
                puVar7[0xc] = puVar7[0xc] & 0xfffffffd;
                iVar6 = 4;
                goto LAB_00644505;
            }
        }
    LAB_00644619:
        iVar6 = *(int32_t*)(&DAT_006eac9c + iVar5);
        if (iVar6 == 1 || iVar6 == 2 || iVar6 == 3 || iVar6 == 0xf20000) {
            iVar6 = 4;
        } else {
            iVar6 = 0;
        }
        iVar6 = *(int32_t*)(&DAT_006eaca4 + iVar5) * *(int32_t*)(&DAT_006eaca0 + iVar5) * iVar6;
        *(uint16_t*)((int32_t)puVar7 + 0x56) = 1;
        *puVar7 = 1;
    }
LAB_006444fd:
    puVar7[0xc] = puVar7[0xc] & 0xfffffffd;
    if (iVar6 != 0) {
    LAB_00644505:
        uVar4 = (*(uint32_t*)(iVar8 + 0xc) & 3) + (*(uint32_t*)(iVar8 + 0xc) & 0xfffffffc);
        uVar4 = (uVar4 & 1) + (uVar4 & 0xfffffffe);
        uVar4 = (uVar4 & 3) + (uVar4 & 0xfffffffc);
        uVar4 = (uVar4 & 3) + (uVar4 & 0xfffffffc);
        iVar5 = (int32_t)((uVar4 & 3) + (uVar4 & 0xfffffffc));
        *(int32_t*)(iVar8 + 0xc) = iVar5;
        puVar7[0x12] = iVar5;
        *(int32_t*)(iVar8 + 0xc) = *(int32_t*)(iVar8 + 0xc) + iVar6;
        return 0;
    }
LAB_006444a6:
    puVar7[0x12] = 0;
    return 0;
}

// 0x644699 — observed shape
// Loads the record at self->+0x2c[param_1]->+0x4 + param_2*100. Consumes one
// size dword from the parameter stream (param_4 is the cursor), rebuilds the
// record's +0x38 sub-object with FUN_006294f9, copies that many dwords plus
// the 0..3 tail bytes from the stream, derives two spans via FUN_0060afb7,
// re-encodes via FUN_006439a7, then stores a 4-aligned power-of-two mask of a
// 4-bit sample count in the record's dwords +0/+4 and advances the surface's
// +0xc cursor by uVar1*8+8. Returns -0x7fffbffb when the stream runs out.
int32_t FUN_00644699(void* self_, int32_t param_1, int32_t param_2, int32_t* param_3, uint32_t* param_4)
{
    const int32_t self = (int32_t)(uintptr_t)self_;
    uint32_t uVar1 = 0;
    int32_t iVar2;
    int32_t* piVar3;
    int32_t iVar4;
    int32_t iVar5;
    uint32_t* puVar6;
    int32_t* piVar7;
    uint32_t* puVar8;
    int32_t* piVar9;
    uint32_t local_c = 0;

    iVar5 = param_1 * 100 + *(int32_t*)(self + 0x2c);
    puVar6 = (uint32_t*)(param_2 * 100 + *(int32_t*)(iVar5 + 4));
    if (param_3 == nullptr) {
        puVar8 = param_4;
    } else {
        uVar1 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3);
        puVar8 = param_4;
        if (*param_4 + 1 <= uVar1) {
            iVar2 = ((int32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0xc)))(param_3);
            local_c = *(uint32_t*)(iVar2 + *puVar8 * 4);
        }
    }
    *puVar8 = *puVar8 + 1;

    if (param_3 != nullptr &&
        (uVar1 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3), *puVar8 <= uVar1)) {
        iVar2 = FUN_006294f9(local_c + 0x20, puVar6 + 0xe);
        if (iVar2 < 0) {
            return iVar2;
        }
        piVar3 = (int32_t*)puVar6[0xe];
        piVar3 = (int32_t*)((int32_t(*)(int32_t*))(*(int32_t*)(*piVar3 + 0xc)))(piVar3);
        piVar3[2] = 0;
        if (local_c == 0) {
            return iVar2;
        }
        iVar2 = (int32_t)((local_c & 3) != 0) + (int32_t)(local_c >> 2);
        uVar1 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3);
        if (*param_4 + iVar2 <= uVar1) {
            iVar4 = ((int32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0xc)))(param_3);
            piVar7 = (int32_t*)(iVar4 + *param_4 * 4);
            piVar9 = piVar3 + 8;
            for (uVar1 = local_c >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
                *piVar9 = *piVar7;
                piVar7 = piVar7 + 1;
                piVar9 = piVar9 + 1;
            }
            for (uVar1 = local_c & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
                *(char*)piVar9 = (char)*piVar7;
                piVar7 = (int32_t*)((int32_t)piVar7 + 1);
                piVar9 = (int32_t*)((int32_t)piVar9 + 1);
            }
        }
        *param_4 = *param_4 + iVar2;
        iVar2 = FUN_0060afb7(piVar3 + 8, puVar6 + 0x10, puVar6 + 0x11);
        if (iVar2 < 0) {
            return iVar2;
        }
        uVar1 = ((uint32_t(*)(int32_t*))(*(int32_t*)(*param_3 + 0x10)))(param_3);
        if (*param_4 <= uVar1) {
            iVar2 = FUN_0060afb7(piVar3 + 8, puVar6 + 0x10, puVar6 + 0x11);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = FUN_006439a7(param_1, param_2, piVar3);
            if (iVar2 < 0) {
                return iVar2;
            }
            param_3 = (int32_t*)(puVar6[8] + *(int32_t*)(self + 0x20));
            iVar4 = FUN_0063dc77((uint32_t*)&param_3, 4);
            *piVar3 = iVar4;
            iVar4 = iVar4 * 4;
            piVar3[1] = iVar4;
            if (iVar4 != 0) {
                piVar3[1] = iVar4 + -1;
            }
            uVar1 = (uint32_t)piVar3[1] >> 1 | (uint32_t)piVar3[1];
            uVar1 = uVar1 >> 2 | uVar1;
            uVar1 = uVar1 >> 4 | uVar1;
            uVar1 = uVar1 >> 8 | uVar1;
            uVar1 = uVar1 >> 0x10 | uVar1;
            piVar3[1] = (int32_t)uVar1;
            iVar4 = (int32_t)((*(uint32_t*)(iVar5 + 0xc) & 7) +
                              (*(uint32_t*)(iVar5 + 0xc) & 0xfffffff8));
            *(int32_t*)(iVar5 + 0xc) = iVar4;
            piVar3[3] = iVar4;
            *(int32_t*)(iVar5 + 0xc) = *(int32_t*)(iVar5 + 0xc) + (int32_t)uVar1 * 8 + 8;
            *puVar6 = 1;
            return iVar2;
        }
    }
    return -0x7fffbffb;
}

// 0x644897 — observed shape
// Rebuilds the object's +0x20 array of param_2 0x28-byte entries: frees any
// previous block through FUN_0064405e(3) on the old pointer, allocates
// param_2*0x28+4 bytes via FUN_00533c78 with a leading count dword, runs the
// FUN_004127b0 constructor over the entries, then fills each entry's +0xc,
// +0x10, +0x14, +0x18, +0x1c and +4/+0 from the owner's current surface
// (self->+0xb0[+0x14]) using FUN_0063ec91 / FUN_0063eb76 and the surface's
// +0x2c/+0x30 origins. Returns 0x8007000e when allocation fails.
uint32_t FUN_00644897(void* self_, int32_t param_1, int32_t param_2)
{
    const int32_t self = (int32_t)(uintptr_t)self_;
    int32_t* piVar1;
    int32_t iVar2;
    int32_t iVar3;
    uint32_t uVar4 = 0;
    int32_t iVar5;
    int32_t iVar6;
    int32_t iVar7;
    int32_t local_14 = 0;
    int32_t local_10 = 0;
    int32_t* local_c;
    int32_t local_8 = 0;

    iVar3 = param_1;
    if (*(int32_t*)(param_1 + 0x20) != 0) {
        FUN_0064405e((void*)(uintptr_t)*(uint32_t*)(param_1 + 0x20), 3);
        *(uint32_t*)(iVar3 + 0x20) = 0;
    }
    iVar7 = param_2;
    local_c = (int32_t*)FUN_00533c78(param_2 * 0x28 + 4);
    if (local_c == nullptr) {
        local_c = nullptr;
    } else {
        *local_c = iVar7;
        local_c = local_c + 1;
        FUN_004127b0(local_c, 0x28, iVar7, (void*)&LAB_0063e2f2);
    }
    *(int32_t**)(iVar3 + 0x20) = local_c;
    if (local_c == nullptr) {
        uVar4 = 0x8007000e;
    } else {
        piVar1 = (int32_t*)(*(int32_t*)(self + 0xb0) + *(int32_t*)(iVar3 + 0x14) * 4);
        param_1 = *(int32_t*)(*piVar1 + 0x2c) + 0x18 + *(int32_t*)(iVar3 + 0x18);
        local_10 = *(int32_t*)(*piVar1 + 0x30) + *(int32_t*)(iVar3 + 0x1c);
        if (iVar7 != 0) {
            iVar7 = 0;
            local_c = (int32_t*)param_2;
            local_14 = param_1;
            local_8 = local_10;
            do {
                *(uint32_t*)(iVar7 + 0x10 + *(int32_t*)(iVar3 + 0x20)) = 3;
                *(uint32_t*)(iVar7 + 0x14 + *(int32_t*)(iVar3 + 0x20)) =
                    *(uint32_t*)(iVar3 + 0x14);
                *(int32_t*)(iVar7 + 0x18 + *(int32_t*)(iVar3 + 0x20)) =
                    param_1 - *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) +
                                                      *(int32_t*)(iVar3 + 0x14) * 4) + 0x2c);
                *(int32_t*)(iVar7 + 0x1c + *(int32_t*)(iVar3 + 0x20)) =
                    local_8 - *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) +
                                                      *(int32_t*)(iVar3 + 0x14) * 4) + 0x30);
                if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) +
                                            *(int32_t*)(iVar3 + 0x14) * 4) + 0x40) == 0) {
                    uVar4 = *(uint32_t*)(self + 0x20);
                } else {
                    uVar4 = *(uint32_t*)(*(int32_t*)(self + 0x38) + 0x10);
                }
                uVar4 = FUN_0063ec91(uVar4, &param_1, &local_10);
                *(uint32_t*)(iVar7 + 0xc + *(int32_t*)(iVar3 + 0x20)) = uVar4;
                if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) +
                                            *(int32_t*)(iVar3 + 0x14) * 4) + 0x40) == 0) {
                    uVar4 = *(uint32_t*)(self + 0x20);
                } else {
                    uVar4 = *(uint32_t*)(*(int32_t*)(self + 0x38) + 0x10);
                }
                FUN_0063eb76(uVar4, &local_14, &local_8);
                iVar2 = iVar7 + *(int32_t*)(iVar3 + 0x20);
                iVar5 = *(int32_t*)(iVar2 + 0x14) * 4;
                if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) + iVar5) + 0x40) == 0) {
                    iVar6 = *(int32_t*)(self + 0x20);
                } else {
                    iVar6 = *(int32_t*)(*(int32_t*)(self + 0x38) + 0x10);
                }
                *(int32_t*)(iVar2 + 4) =
                    *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) + iVar5) + 0x2c) +
                    *(int32_t*)(iVar2 + 0x18) + iVar6;
                piVar1 = (int32_t*)(iVar7 + *(int32_t*)(iVar3 + 0x20));
                if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) + piVar1[5] * 4) + 0x40) == 0) {
                    param_2 = *(int32_t*)(self + 0x20);
                } else {
                    param_2 = *(int32_t*)(*(int32_t*)(self + 0x38) + 0x10);
                }
                iVar7 = iVar7 + 0x28;
                local_c = (int32_t*)((int32_t)local_c - 1);
                *piVar1 = *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) + piVar1[5] * 4) + 0x30) +
                          piVar1[7] + param_2;
            } while (local_c != nullptr);
        }
        uVar4 = 0;
    }
    return uVar4;
}

// 0x644a71 — observed shape
// Walks three fallback lookups on the handle (level 10) until one succeeds,
// picks the child base (+0x2c/+0x30) or sibling base (+0x38/+0x3c), then walks
// param_3 sibling links from +0x3c and returns the complement of the reached
// node. Returns 0 when the handle or the index is out of range.
uint32_t FUN_00644a71(uint32_t param_1, int32_t param_2, uint32_t param_3)
{
    int32_t iVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    if (param_2 != 0) {
        iVar1 = FUN_0063ea6b(param_2, 10);
        if (iVar1 == 0) {
            iVar1 = FUN_0063f27d(param_2, 10);
            if (iVar1 == 0) {
                iVar1 = FUN_0063f23c(param_2, 10);
                if (iVar1 == 0) {
                    return 0;
                }
            }
            uVar3 = *(uint32_t*)(iVar1 + 0x2c);
            uVar2 = *(uint32_t*)(iVar1 + 0x30);
        } else {
            uVar3 = *(uint32_t*)(iVar1 + 0x38);
            uVar2 = *(uint32_t*)(iVar1 + 0x3c);
        }
        if (param_3 < uVar3) {
            if (param_3 != 0) {
                do {
                    param_3 = param_3 - 1;
                    uVar2 = *(uint32_t*)(uVar2 + 0x3c);
                } while (param_3 != 0);
            }
            return ~uVar2;
        }
    }
    return 0;
}

// 0x644ad5 — observed shape
// Selects layer row param_1->+0x42 from the level object returned by
// FUN_0063f27d(param_2,1). Refuses when the object is in state 4 or the lookup
// fails (-0x7789f794); otherwise flushes a pending +0x44 entry through
// FUN_0063da83, publishes the new row index, recomputes the row pointer at
// +0xb8 = +0xb4 + index*stride*4 and, when the current row changed, marks the
// cells of the new row (through the +0xbc occupancy bytes and the per-column
// pointer arrays at +0xb8) by writing 1 at each referenced cell and at the
// record at +0x2c[column]->+0x4 + row*100.
int32_t FUN_00644ad5(int32_t param_1, uint32_t param_2)
{
    uint16_t uVar1;
    int16_t sVar2;
    int32_t iVar3;
    int32_t* piVar4;
    uint32_t uVar5;
    int32_t local_8 = 0;

    if (*(int32_t*)(param_1 + 0x3c) == 4) {
        local_8 = -0x7789f794;
    } else {
        iVar3 = FUN_0063f27d(param_2, 1);
        if (iVar3 == 0) {
            local_8 = -0x7789f794;
        } else {
            if (*(uint16_t*)(param_1 + 0x44) != 0xffff) {
                local_8 = FUN_0063da83(
                    *(uint16_t*)(uintptr_t)(
                        *(int32_t*)(uintptr_t)((uint32_t)*(uint16_t*)(param_1 + 0x42) * 0xb4 + 0x38 +
                                              *(int32_t*)(param_1 + 0xa4)) +
                        0x34 + (uint32_t)*(uint16_t*)(param_1 + 0x44) * 0x38),
                    0xffffffff,
                    (*(uint16_t*)(param_1 + 0x40) != *(uint16_t*)(param_1 + 0x42)) - 1);
                if (local_8 < 0) {
                    return local_8;
                }
                *(uint16_t*)(param_1 + 0x44) = 0xffff;
            }
            uVar1 = *(uint16_t*)(iVar3 + 0x14);
            sVar2 = *(int16_t*)(param_1 + 0x42);
            *(uint16_t*)(param_1 + 0x42) = uVar1;
            *(uint32_t*)(param_1 + 0xb8) = *(int32_t*)(param_1 + 0xb4) +
                                           (uint32_t)uVar1 * *(int32_t*)(param_1 + 0xac) * 4;
            uVar5 = 0;
            if (*(int32_t*)(param_1 + 0xb4) != 0 && sVar2 != *(int16_t*)(param_1 + 0x42) &&
                *(int32_t*)(param_1 + 0xac) != 0) {
                do {
                    if (*(char*)(uintptr_t)(uVar5 + *(uint32_t*)(param_1 + 0xbc)) != '\0') {
                        piVar4 = *(int32_t**)(uintptr_t)(*(uint32_t*)(param_1 + 0xb8) + uVar5 * 4);
                        if (piVar4 != nullptr) {
                            for (; *piVar4 != 0; piVar4 = piVar4 + 1) {
                                *(uint32_t*)(uintptr_t)(*piVar4) = 1;
                                *(uint32_t*)(uintptr_t)(
                                    (uint32_t)*(uint16_t*)(uintptr_t)(*piVar4 + 0x16) * 100 +
                                    *(int32_t*)(uintptr_t)(
                                        (uint32_t)*(uint16_t*)(uintptr_t)(*piVar4 + 0x14) * 100 + 4 +
                                        *(int32_t*)(param_1 + 0x2c))) = 1;
                            }
                        }
                    }
                    uVar5 = uVar5 + 1;
                } while (uVar5 < *(uint32_t*)(param_1 + 0xac));
            }
        }
    }
    return local_8;
}

// 0x644bfc — observed shape
// Forwards the six arguments (the first three by address) to FUN_0064058d.
void FUN_00644bfc(uint8_t param_1, uint8_t param_2, uint8_t param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6)
{
    FUN_0064058d(&param_1, &param_2, &param_3, param_4, param_5, param_6);
    return;
}

// 0x644c1f — observed shape
// Copies a source image described by param_1[0] (pixels) and param_1[1]
// (format record: +0=source format, +4=pixel kind, +0x10..+0x18 geometry) into
// the destination described by the same pair, honouring param_1[2] as the row
// count override. Kind <2 is a flat dword copy, <4 is a per-column strided
// copy (three source formats), 4 dispatches to FUN_0063f9ca / FUN_0063f926 /
// FUN_0063f86e per pixel, and 5 walks the per-column sub-descriptors through
// FUN_00640a26. Returns the last error or 0; -0x7fffbffb for bad geometry.
int32_t FUN_00644c1f(void* self_, int32_t* param_1, uint32_t* param_2)
{
    const int32_t self = (int32_t)(uintptr_t)self_;
    uint32_t uVar1 = 0;
    int32_t* piVar2;
    int32_t* piVar3;
    int32_t iVar4;
    uint32_t* puVar5;
    int32_t iVar6;
    int32_t iVar7;
    uint32_t* puVar8;
    int32_t local_18 = 0;
    int32_t local_14 = 0;
    uint32_t local_10 = 0;
    uint32_t local_8 = 0;
    int32_t* local_c;

    piVar2 = param_1;
    puVar8 = (uint32_t*)(uintptr_t)*param_1;
    local_c = (int32_t*)(uintptr_t)param_1[1];
    if (param_1[2] != -1 || ((local_18 = local_c[4]) == 0)) {
        local_18 = 1;
    }
    iVar4 = local_c[1];
    iVar6 = *local_c;
    if (iVar4 < 0) {
    LAB_00644f7e:
        iVar4 = -0x7fffbffb;
    } else {
        if (iVar4 < 2) {
            iVar4 = local_c[5];
            puVar5 = puVar8 + local_18 * 4;
            for (; puVar8 < puVar5; puVar8 = puVar8 + (4 - iVar4)) {
                if (iVar4 != 0) {
                    local_18 = iVar4;
                    do {
                        *puVar8 = *param_2;
                        puVar8 = puVar8 + 1;
                        param_2 = param_2 + 1;
                        local_18 = local_18 + -1;
                    } while (local_18 != 0);
                }
            }
        } else {
            param_1 = (int32_t*)(uintptr_t)puVar8;
            if (iVar4 < 4) {
                iVar4 = local_c[5];
                uVar1 = (uint32_t)local_c[6];
                local_14 = local_18;
                if (iVar6 == 1) {
                    if (local_18 != 0) {
                        do {
                            local_8 = 0;
                            if (uVar1 != 0) {
                                do {
                                    if (iVar4 != 0) {
                                        iVar6 = (int32_t)(local_8 << 4);
                                        iVar7 = (int32_t)(local_8 << 2);
                                        local_18 = iVar4;
                                        do {
                                            *(uint32_t*)(uintptr_t)(iVar6 + (int32_t)(uintptr_t)param_1) =
                                                (uint32_t)(*(int32_t*)(uintptr_t)(iVar7 + (int32_t)(uintptr_t)param_2) != 0);
                                            iVar6 = iVar6 + 4;
                                            iVar7 = iVar7 + (int32_t)(uVar1 * 4);
                                            local_18 = local_18 + -1;
                                        } while (local_18 != 0);
                                    }
                                    local_8 = local_8 + 1;
                                } while (local_8 < uVar1);
                            }
                            param_1 = param_1 + 0x10;
                            param_2 = param_2 + uVar1 * iVar4;
                            local_14 = local_14 + -1;
                        } while (local_14 != 0);
                    }
                } else if (iVar6 == 2) {
                    if (local_18 != 0) {
                        do {
                            local_8 = 0;
                            if (uVar1 != 0) {
                                do {
                                    if (iVar4 != 0) {
                                        iVar6 = (int32_t)(local_8 << 4);
                                        iVar7 = (int32_t)(local_8 << 2);
                                        local_18 = iVar4;
                                        do {
                                            *(uint32_t*)(uintptr_t)(iVar6 + (int32_t)(uintptr_t)param_1) =
                                                *(uint32_t*)(uintptr_t)(iVar7 + (int32_t)(uintptr_t)param_2);
                                            iVar6 = iVar6 + 4;
                                            iVar7 = iVar7 + (int32_t)(uVar1 * 4);
                                            local_18 = local_18 + -1;
                                        } while (local_18 != 0);
                                    }
                                    local_8 = local_8 + 1;
                                } while (local_8 < uVar1);
                            }
                            param_1 = param_1 + 0x10;
                            param_2 = param_2 + uVar1 * iVar4;
                            local_14 = local_14 + -1;
                        } while (local_14 != 0);
                    }
                } else if (iVar6 == 3 && local_18 != 0) {
                    do {
                        local_8 = 0;
                        if (uVar1 != 0) {
                            do {
                                if (iVar4 != 0) {
                                    iVar6 = (int32_t)(local_8 << 4);
                                    iVar7 = (int32_t)(local_8 << 2);
                                    local_14 = iVar4;
                                    do {
                                        *(uint32_t*)(uintptr_t)(iVar6 + (int32_t)(uintptr_t)param_1) =
                                            *(uint32_t*)(uintptr_t)(iVar7 + (int32_t)(uintptr_t)param_2);
                                        iVar6 = iVar6 + 4;
                                        iVar7 = iVar7 + (int32_t)(uVar1 * 4);
                                        local_14 = local_14 + -1;
                                    } while (local_14 != 0);
                                }
                                local_8 = local_8 + 1;
                            } while (local_8 < uVar1);
                        }
                        param_1 = param_1 + 0x10;
                        param_2 = param_2 + uVar1 * iVar4;
                        local_18 = local_18 + -1;
                    } while (local_18 != 0);
                }
            } else {
                local_8 = (uint32_t)local_18;
                if (iVar4 == 4) {
                    if (iVar6 == 4) {
                        for (; local_8 != 0; local_8 = local_8 + -1) {
                            iVar4 = FUN_0063f9ca(
                                *param_2, (uint32_t)*param_1,
                                *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) + piVar2[5] * 4) + 0x40));
                            if (iVar4 < 0) {
                                return iVar4;
                            }
                            param_2 = param_2 + 1;
                            param_1 = param_1 + 1;
                        }
                    } else if (4 < iVar6) {
                        if (iVar6 < 10) {
                            for (; local_8 != 0; local_8 = local_8 + -1) {
                                iVar4 = FUN_0063f926(
                                    *param_2, (uint32_t)*param_1,
                                    *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) + piVar2[5] * 4) + 0x40));
                                if (iVar4 < 0) {
                                    return iVar4;
                                }
                                param_2 = param_2 + 1;
                                param_1 = param_1 + 1;
                            }
                        } else if (iVar6 == 0xf) {
                            for (; local_8 != 0; local_8 = local_8 + -1) {
                                iVar4 = FUN_0063f86e(
                                    *param_2, (uint32_t)*param_1,
                                    *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) + piVar2[5] * 4) + 0x40));
                                if (iVar4 < 0) {
                                    return iVar4;
                                }
                                param_2 = param_2 + 1;
                                param_1 = param_1 + 1;
                            }
                        } else if (iVar6 == 0x10) {
                            for (; local_8 != 0; local_8 = local_8 + -1) {
                                iVar4 = FUN_0063f86e(
                                    *param_2, (uint32_t)*param_1,
                                    *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0xb0) + piVar2[5] * 4) + 0x40));
                                if (iVar4 < 0) {
                                    return iVar4;
                                }
                                param_2 = param_2 + 1;
                                param_1 = param_1 + 1;
                            }
                        }
                    }
                } else {
                    if (iVar4 != 5) goto LAB_00644f7e;
                    uVar1 = (uint32_t)local_c[5];
                    piVar3 = local_c + 6;
                    for (; local_8 != 0; local_8 = local_8 + -1) {
                        local_10 = 0;
                        local_c = piVar3;
                        if (uVar1 != 0) {
                            do {
                                iVar4 = local_c[4];
                                if (iVar4 == 0) {
                                    iVar4 = 1;
                                }
                                iVar4 = FUN_00640a26(&local_c, &param_1, &param_2, iVar4, piVar2);
                                if (iVar4 < 0) {
                                    return iVar4;
                                }
                                local_10 = local_10 + 1;
                            } while (local_10 < uVar1);
                        }
                    }
                }
            }
        }
        iVar4 = 0;
    }
    return iVar4;
}

// 0x644f8a — observed shape
// Forwards the five arguments (the first three by address) to FUN_00640dc6.
void FUN_00644f8a(uint8_t param_1, uint8_t param_2, uint8_t param_3, uint32_t param_4,
                  uint32_t param_5)
{
    FUN_00640dc6(&param_1, &param_2, &param_3, param_4, param_5);
    return;
}

// 0x644fc1 — observed shape
// Returns 0x8876086c for a null argument, otherwise delegates to
// FUN_00641260; the unused first argument is preserved.
uint32_t FUN_00644fc1(uint32_t param_1, int32_t param_2)
{
    uint32_t uVar1;

    if (param_2 == 0) {
        uVar1 = 0x8876086c;
    } else {
        uVar1 = FUN_00641260(param_2);
    }
    return uVar1;
}

// 0x644fe5 — observed shape
// Scalar/vector deleting-destructor thunk for an 8-byte object: runs
// FUN_00641a99, or vector-deletes through FUN_00412770 with the recorded
// allocation size. Bit 0 releases storage.
void FUN_00644fe5(void* self, uint8_t param_1)
{
    if ((param_1 & 2) == 0) {
        FUN_00641a99();
        if ((param_1 & 1) != 0) {
            operator_delete(self);
        }
    } else {
        FUN_00412770(self, 8, *(uint32_t*)((char*)self - 4), FUN_00641a99);
        if ((param_1 & 1) != 0) {
            operator_delete((char*)self - 4);
        }
    }
}

// 0x645033 — observed shape
// Formats a source surface (param_1[0] pixels, param_1[1] format record) into
// a float destination. The destination kind (param_4 == 0 ? record[1] : the
// ushort at param_5->+0xc + param_4) selects: 2 = per-column int->float
// expand for source formats 1..3, 3 = the same expand loop, 5 = per-column
// sub-descriptors through FUN_00641ac9, otherwise the strided copy driven by
// the source format (+0) and the column/row counts (+0x14/+0x18). Row count
// defaults to record[4] or 1; *param_6 receives the produced dword count.
void FUN_00645033(uint32_t* param_1, float* param_2, uint16_t* param_3, int32_t param_4,
                  uint32_t param_5, uint32_t* param_6, float* param_7)
{
    float fVar1;
    int32_t* piVar2 = (int32_t*)(uintptr_t)param_1[1];
    float* local_8 = (float*)(uintptr_t)*param_1;
    float* pfVar4 = param_2;
    float* pfVar9 = param_2;
    float* pfVar7;
    uint32_t uVar3;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar13;
    int32_t iVar8;
    uintptr_t limit;
    uintptr_t row;
    uint16_t* puVar11;
    uint32_t* puVar12;
    int32_t* local_14;
    uint32_t local_10 = 0;
    uint32_t local_c = 0;

    if (param_4 == 0) {
        uVar6 = (uint32_t)piVar2[1];
        puVar11 = param_3;
    } else {
        puVar11 = (uint16_t*)(uintptr_t)(*(int32_t*)(param_5 + 0xc) + param_4);
        uVar6 = (uint32_t)*puVar11;
    }
    if (param_7 == (float*)(uintptr_t)0xffffffff) {
        limit = (uintptr_t)(uint32_t)piVar2[4];
        if (limit == 0) {
            limit = 1;
        }
    } else {
        limit = (uintptr_t)param_7;
    }
    pfVar9 = param_2;
    if ((int32_t)uVar6 < 0) goto LAB_006453dc;

    if (1 < (int32_t)uVar6) {
        if (uVar6 == 2) {
            uVar6 = (uint32_t)piVar2[5];
            uVar3 = (uint32_t)piVar2[6];
            iVar8 = *piVar2;
            if (iVar8 == 1) {
                row = 0;
                while (row < limit) {
                    uVar13 = 0;
                    pfVar9 = param_2;
                    if (param_3 == nullptr) break;
                    if (uVar6 != 0) {
                        do {
                            uVar5 = 0;
                            if (param_3 == nullptr) break;
                            if (uVar3 != 0) {
                                iVar8 = (int32_t)(uVar13 << 2);
                                do {
                                    int32_t* p = (int32_t*)(uintptr_t)(iVar8 + (int32_t)(uintptr_t)local_8);
                                    iVar8 = iVar8 + 0x10;
                                    param_2[uVar5] = (float)*p;
                                    uVar5 = uVar5 + 1;
                                } while (uVar5 < uVar3);
                            }
                            param_2 = param_2 + 4;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            uVar13 = uVar13 + 1;
                        } while (uVar13 < uVar6);
                    }
                    row = row + 1;
                    pfVar9 = param_2;
                }
            } else if (iVar8 == 2) {
                row = 0;
                while (row < limit) {
                    uVar13 = 0;
                    pfVar9 = param_2;
                    if (param_3 == nullptr) break;
                    if (uVar6 != 0) {
                        do {
                            uVar5 = 0;
                            if (param_3 == nullptr) break;
                            if (uVar3 != 0) {
                                iVar8 = (int32_t)(uVar13 << 2);
                                do {
                                    int32_t* p = (int32_t*)(uintptr_t)(iVar8 + (int32_t)(uintptr_t)local_8);
                                    iVar8 = iVar8 + 0x10;
                                    param_2[uVar5] = (float)*p;
                                    uVar5 = uVar5 + 1;
                                } while (uVar5 < uVar3);
                            }
                            param_2 = param_2 + 4;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            uVar13 = uVar13 + 1;
                        } while (uVar13 < uVar6);
                    }
                    row = row + 1;
                    pfVar9 = param_2;
                }
            } else if (iVar8 == 3) {
                float* srcRow = local_8;
                local_c = 0;
                if (limit != 0) {
                    do {
                        uVar13 = 0;
                        if (param_3 == nullptr) break;
                        if (uVar6 != 0) {
                            pfVar9 = srcRow;
                            do {
                                if (param_3 == nullptr) break;
                                uVar5 = 0;
                                if (uVar3 != 0) {
                                    pfVar7 = pfVar9;
                                    do {
                                        fVar1 = *pfVar7;
                                        pfVar7 = pfVar7 + 4;
                                        param_2[uVar5] = fVar1;
                                        uVar5 = uVar5 + 1;
                                    } while (uVar5 < uVar3);
                                }
                                param_2 = param_2 + 4;
                                param_3 = (uint16_t*)((int32_t)param_3 - 1);
                                uVar13 = uVar13 + 1;
                                pfVar9 = pfVar9 + 1;
                            } while (uVar13 < uVar6);
                        }
                        srcRow = srcRow + 0x10;
                        local_c = local_c + 1;
                    } while (local_c < limit);
                }
                pfVar9 = param_2;
            }
            goto LAB_006453dc;
        }
        if (uVar6 != 3) {
            if (uVar6 == 5) {
                local_10 = 0;
                if (param_4 != 0) {
                    local_c = (uint32_t)(*(int32_t*)(puVar11 + 6) + param_4);
                }
                row = 0;
                uVar6 = (uint32_t)piVar2[5];
                if (limit != 0) {
                    do {
                        if (param_3 == nullptr) break;
                        param_5 = 0;
                        if (uVar6 != 0) {
                            puVar12 = (uint32_t*)(uintptr_t)(local_c + 4);
                            local_14 = piVar2 + 6;
                            do {
                                if (param_3 == nullptr) break;
                                if (param_4 != 0) {
                                    local_10 = *puVar12;
                                }
                                FUN_00641ac9(&local_14, &local_8, &param_2, (uint32_t)param_4,
                                             local_10, &param_3, 0xffffffff);
                                param_5 = param_5 + 1;
                                puVar12 = puVar12 + 2;
                                pfVar9 = param_2;
                            } while (param_5 < uVar6);
                        }
                        row = row + 1;
                    } while (row < limit);
                }
            }
            goto LAB_006453dc;
        }
    }

    iVar8 = piVar2[5];
    uVar3 = (uint32_t)piVar2[6];
    {
        int32_t iVar10 = *piVar2;
        float* skip = nullptr;
        if (uVar6 == 3) {
            skip = (float*)(uintptr_t)((4 - uVar3) * 4);
        }
        if (iVar10 == 1) {
            local_c = 0;
            if (limit != 0) {
                do {
                    if (param_3 == nullptr) break;
                    local_10 = 0;
                    if (uVar3 != 0) {
                        do {
                            if (param_3 == nullptr) break;
                            if (iVar8 != 0) {
                                pfVar9 = param_2;
                                iVar10 = iVar8;
                                do {
                                    *pfVar9 = (float)*(int32_t*)(uintptr_t)(((int32_t)(uintptr_t)local_8 -
                                                                            (int32_t)(uintptr_t)param_2) +
                                                                           (int32_t)(uintptr_t)pfVar9);
                                    pfVar9 = pfVar9 + 1;
                                    iVar10 = iVar10 + -1;
                                } while (iVar10 != 0);
                            }
                            param_2 = param_2 + 4;
                            local_8 = local_8 + 4;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            local_10 = local_10 + 1;
                        } while (local_10 < uVar3);
                    }
                    local_c = local_c + 1;
                    local_8 = local_8 + (int32_t)(uintptr_t)skip;
                } while (local_c < limit);
            }
        } else {
            if (iVar10 != 2) {
                if (iVar10 == 3) {
                    row = 0;
                    if (limit != 0) {
                        do {
                            pfVar9 = param_2;
                            if (param_3 == nullptr) break;
                            uVar13 = 0;
                            if (uVar3 != 0) {
                                do {
                                    param_2 = pfVar9;
                                    if (param_3 == nullptr) break;
                                    *pfVar9 = *local_8;
                                    pfVar9[1] = local_8[1];
                                    pfVar9[2] = local_8[2];
                                    pfVar7 = local_8 + 3;
                                    param_2 = pfVar9 + 4;
                                    local_8 = local_8 + 4;
                                    pfVar9[3] = *pfVar7;
                                    param_3 = (uint16_t*)((int32_t)param_3 - 1);
                                    uVar13 = uVar13 + 1;
                                    pfVar9 = param_2;
                                } while (uVar13 < uVar3);
                            }
                            row = row + 1;
                            local_8 = local_8 + (int32_t)(uintptr_t)skip;
                            pfVar9 = param_2;
                        } while (row < limit);
                    }
                }
                goto LAB_006453dc;
            }
            local_10 = 0;
            if (limit != 0) {
                do {
                    if (param_3 == nullptr) break;
                    local_c = 0;
                    if (uVar3 != 0) {
                        do {
                            if (param_3 == nullptr) break;
                            if (iVar8 != 0) {
                                pfVar9 = param_2;
                                iVar10 = iVar8;
                                do {
                                    *pfVar9 = (float)*(int32_t*)(uintptr_t)(((int32_t)(uintptr_t)local_8 -
                                                                            (int32_t)(uintptr_t)param_2) +
                                                                           (int32_t)(uintptr_t)pfVar9);
                                    pfVar9 = pfVar9 + 1;
                                    iVar10 = iVar10 + -1;
                                } while (iVar10 != 0);
                            }
                            param_2 = param_2 + 4;
                            local_8 = local_8 + 4;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            local_c = local_c + 1;
                        } while (local_c < uVar3);
                    }
                    local_10 = local_10 + 1;
                    local_8 = local_8 + (int32_t)(uintptr_t)skip;
                } while (local_10 < limit);
            }
        }
    }
    pfVar9 = param_2;
LAB_006453dc:
    *param_6 = (uint32_t)((int32_t)(uintptr_t)pfVar9 - (int32_t)(uintptr_t)pfVar4) >> 4;
    return;
}

// 0x6453ee — observed shape
// Same walk as 0x645033, but the destination is a packed dword surface
// (uint16_t* stepped by 8 halves per cell). Destination kind 2/3 expands each
// source column into param_4 dwords at +0/2/4/6 halves, kind 5 walks the
// per-column sub-descriptors through FUN_00641ef0, and the default path uses
// the source format (+0) with the counts at +0x14/+0x18. *param_6 receives the
// produced dword count.
// NEEDS_MANUAL: the listing's ftol() calls convert an implicit x87 operand;
// the source float they consume is not named in the provider output.
void FUN_006453ee(int32_t* param_1, uint16_t* param_2, int32_t param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t* param_6, uint16_t* param_7)
{
    int32_t* piVar1;
    uint16_t* puVar2 = param_2;
    uint16_t* puVar5;
    uint16_t* puVar9 = param_2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar6;
    int32_t iVar7;
    uint32_t* puVar8;
    int32_t* local_1c = (int32_t*)(uintptr_t)param_1[1];
    uint32_t local_18 = 0;
    int32_t local_14 = 0;
    uint32_t local_10 = 0;
    int32_t local_c = 0;
    int32_t local_8 = *param_1;
    uintptr_t limit;

    if (param_4 == 0) {
        uVar6 = (uint32_t)local_1c[1];
        puVar5 = param_2;
    } else {
        puVar5 = (uint16_t*)(uintptr_t)(*(int32_t*)(param_5 + 0xc) + param_4);
        uVar6 = (uint32_t)*puVar5;
    }
    if (param_7 == (uint16_t*)(uintptr_t)0xffffffff) {
        limit = (uintptr_t)(uint32_t)local_1c[4];
        if (limit == 0) {
            limit = 1;
        }
    } else {
        limit = (uintptr_t)param_7;
    }
    puVar9 = param_2;
    if ((int32_t)uVar6 < 0) goto LAB_006457e0;

    if (1 < (int32_t)uVar6) {
        if (uVar6 == 2) {
            param_5 = (uint32_t)local_1c[5];
            param_4 = (uint32_t)local_1c[6];
            iVar7 = *local_1c;
            if (iVar7 == 1) {
                uintptr_t row = 0;
                while (row < limit) {
                    uVar6 = 0;
                    puVar9 = param_2;
                    if (param_3 == 0) break;
                    if (param_5 != 0) {
                        do {
                            if (param_3 == 0) break;
                            uVar3 = 0;
                            if (param_4 != 0) {
                                iVar7 = (int32_t)(uVar6 << 2);
                                do {
                                    *(uint32_t*)(uintptr_t)(param_2 + uVar3 * 2) =
                                        *(uint32_t*)(uintptr_t)(iVar7 + local_8);
                                    uVar3 = uVar3 + 1;
                                    iVar7 = iVar7 + 0x10;
                                } while (uVar3 < param_4);
                            }
                            param_2 = param_2 + 8;
                            param_3 = param_3 + -1;
                            uVar6 = uVar6 + 1;
                        } while (uVar6 < param_5);
                    }
                    row = row + 1;
                    puVar9 = param_2;
                }
            } else if (iVar7 == 2) {
                uintptr_t row = 0;
                while (row < limit) {
                    uVar6 = 0;
                    puVar9 = param_2;
                    if (param_3 == 0) break;
                    if (param_5 != 0) {
                        do {
                            if (param_3 == 0) break;
                            uVar3 = 0;
                            if (param_4 != 0) {
                                iVar7 = (int32_t)(uVar6 << 2);
                                do {
                                    *(uint32_t*)(uintptr_t)(param_2 + uVar3 * 2) =
                                        *(uint32_t*)(uintptr_t)(iVar7 + local_8);
                                    uVar3 = uVar3 + 1;
                                    iVar7 = iVar7 + 0x10;
                                } while (uVar3 < param_4);
                            }
                            param_2 = param_2 + 8;
                            param_3 = param_3 + -1;
                            uVar6 = uVar6 + 1;
                        } while (uVar6 < param_5);
                    }
                    row = row + 1;
                    puVar9 = param_2;
                }
            } else if (iVar7 == 3) {
                local_18 = 0;
                param_7 = param_2;
                iVar7 = param_3;
                local_14 = local_8;
                if (limit != 0) {
                    do {
                        if (iVar7 == 0) break;
                        local_10 = 0;
                        if (param_5 != 0) {
                            local_c = local_14;
                            do {
                                uVar6 = 0;
                                if (iVar7 == 0) break;
                                if (param_4 != 0) {
                                    do {
                                        uVar4 = (uint32_t)ftol();
                                        *(uint32_t*)(uintptr_t)(param_7 + uVar6 * 2) = uVar4;
                                        uVar6 = uVar6 + 1;
                                    } while (uVar6 < param_4);
                                }
                                param_7 = param_7 + 8;
                                local_c = local_c + 4;
                                iVar7 = iVar7 + -1;
                                local_10 = local_10 + 1;
                            } while (local_10 < param_5);
                        }
                        local_14 = local_14 + 0x40;
                        local_18 = local_18 + 1;
                    } while (local_18 < limit);
                }
                param_2 = param_7;
                puVar9 = param_2;
            }
            goto LAB_006457e0;
        }
        if (uVar6 != 3) {
            if (uVar6 == 5) {
                local_18 = 0;
                if (param_4 != 0) {
                    local_14 = *(int32_t*)(puVar5 + 6) + (int32_t)param_4;
                }
                uVar6 = (uint32_t)local_1c[5];
                piVar1 = local_1c + 6;
                param_7 = nullptr;
                if (limit != 0) {
                    do {
                        puVar9 = param_2;
                        if (param_3 == 0) break;
                        param_5 = 0;
                        if (uVar6 != 0) {
                            puVar8 = (uint32_t*)(uintptr_t)(local_14 + 4);
                            local_1c = piVar1;
                            do {
                                if (param_3 == 0) break;
                                if (param_4 != 0) {
                                    local_18 = *puVar8;
                                }
                                FUN_00641ef0(&local_1c, &local_8, &param_2, param_4, local_18,
                                             &param_3, 0xffffffff);
                                param_5 = param_5 + 1;
                                puVar8 = puVar8 + 2;
                            } while (param_5 < uVar6);
                        }
                        param_7 = (uint16_t*)((int32_t)param_7 + 1);
                        puVar9 = param_2;
                    } while ((uintptr_t)param_7 < limit);
                }
            }
            goto LAB_006457e0;
        }
    }

    local_10 = (uint32_t)local_1c[5];
    param_4 = (uint32_t)local_1c[6];
    iVar7 = *local_1c;
    param_5 = 0;
    if (uVar6 == 3) {
        param_5 = (4 - param_4) * 4;
    }
    if (iVar7 == 1) {
        local_18 = 0;
        if (limit != 0) {
            do {
                puVar9 = param_2;
                if (param_3 == 0) break;
                param_7 = nullptr;
                if (param_4 != 0) {
                    do {
                        if (param_3 == 0) break;
                        if (local_10 != 0) {
                            puVar5 = param_2;
                            local_14 = (int32_t)local_10;
                            do {
                                *(uint32_t*)(uintptr_t)puVar5 =
                                    *(uint32_t*)(uintptr_t)((local_8 - (int32_t)(uintptr_t)param_2) +
                                                            (int32_t)(uintptr_t)puVar5);
                                puVar5 = puVar5 + 2;
                                local_14 = local_14 + -1;
                            } while (local_14 != 0);
                        }
                        param_2 = param_2 + 8;
                        local_8 = local_8 + 0x10;
                        param_3 = param_3 + -1;
                        param_7 = (uint16_t*)((int32_t)param_7 + 1);
                    } while ((uintptr_t)param_7 < (uintptr_t)param_4);
                }
                local_18 = local_18 + 1;
                local_8 = local_8 + (int32_t)(param_5 * 4);
                puVar9 = param_2;
            } while (local_18 < limit);
        }
    } else if (iVar7 == 2) {
        local_18 = 0;
        if (limit != 0) {
            do {
                puVar9 = param_2;
                if (param_3 == 0) break;
                param_7 = nullptr;
                if (param_4 != 0) {
                    do {
                        if (param_3 == 0) break;
                        if (local_10 != 0) {
                            puVar5 = param_2;
                            local_14 = (int32_t)local_10;
                            do {
                                *(uint32_t*)(uintptr_t)puVar5 =
                                    *(uint32_t*)(uintptr_t)((local_8 - (int32_t)(uintptr_t)param_2) +
                                                            (int32_t)(uintptr_t)puVar5);
                                puVar5 = puVar5 + 2;
                                local_14 = local_14 + -1;
                            } while (local_14 != 0);
                        }
                        param_2 = param_2 + 8;
                        local_8 = local_8 + 0x10;
                        param_3 = param_3 + -1;
                        param_7 = (uint16_t*)((int32_t)param_7 + 1);
                    } while ((uintptr_t)param_7 < (uintptr_t)param_4);
                }
                local_18 = local_18 + 1;
                local_8 = local_8 + (int32_t)(param_5 * 4);
                puVar9 = param_2;
            } while (local_18 < limit);
        }
    } else if (iVar7 == 3) {
        local_18 = 0;
        iVar7 = param_3;
        if (limit != 0) {
            do {
                if (iVar7 == 0) break;
                param_7 = nullptr;
                if (param_4 != 0) {
                    do {
                        if (iVar7 == 0) break;
                        uVar4 = (uint32_t)ftol();
                        *(uint32_t*)(uintptr_t)puVar9 = uVar4;
                        uVar4 = (uint32_t)ftol();
                        *(uint32_t*)(uintptr_t)(puVar9 + 2) = uVar4;
                        uVar4 = (uint32_t)ftol();
                        *(uint32_t*)(uintptr_t)(puVar9 + 4) = uVar4;
                        uVar4 = (uint32_t)ftol();
                        *(uint32_t*)(uintptr_t)(puVar9 + 6) = uVar4;
                        puVar9 = puVar9 + 8;
                        iVar7 = iVar7 + -1;
                        param_7 = (uint16_t*)((int32_t)param_7 + 1);
                    } while ((uintptr_t)param_7 < (uintptr_t)param_4);
                }
                local_18 = local_18 + 1;
            } while (local_18 < limit);
        }
    }
LAB_006457e0:
    param_2 = puVar9;
    *param_6 = (uint32_t)((int32_t)(uintptr_t)param_2 - (int32_t)(uintptr_t)puVar2) >> 4;
    return;
}

// 0x6457f4 — observed shape
// Copies the source surface (param_1[0] pixels, param_1[1] format record) into
// a dword destination. Destination kind 2 handles one column per cell, kind 3
// expands each source column into four consecutive dwords (ftol per component),
// kind 5 walks the per-column sub-descriptors through FUN_00642362, and the
// default path emits the source format's columns via the record counts at
// +0x14/+0x18. *param_6 receives the produced dword count.
// NEEDS_MANUAL: the listing's ftol() calls convert an implicit x87 operand;
// the source float they consume is not named in the provider output.
void FUN_006457f4(int32_t* param_1, uint32_t* param_2, uint16_t* param_3, uint32_t param_4,
                  uint16_t* param_5, uint32_t* param_6, uint32_t param_7)
{
    int32_t* piVar1;
    int32_t iVar2;
    uint32_t* puVar3 = param_2;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    uint16_t* puVar9;
    int32_t* local_14 = (int32_t*)(uintptr_t)param_1[1];
    uint32_t local_10 = 0;
    int32_t local_c = 0;
    uint32_t* local_8 = (uint32_t*)(uintptr_t)*param_1;
    uintptr_t limit;

    if (param_4 == 0) {
        uVar6 = (uint32_t)local_14[1];
        puVar9 = param_3;
    } else {
        puVar9 = (uint16_t*)(uintptr_t)(*(int32_t*)((int32_t)param_5 + 0xc) + (int32_t)param_4);
        uVar6 = (uint32_t)*puVar9;
    }
    if (param_7 == 0xffffffff) {
        limit = (uintptr_t)(uint32_t)local_14[4];
        if (limit == 0) {
            limit = 1;
        }
    } else {
        limit = (uintptr_t)param_7;
    }
    puVar7 = param_2;
    if ((int32_t)uVar6 < 0) goto LAB_00645b13;

    if (1 < (int32_t)uVar6) {
        if (uVar6 == 2) {
            param_4 = (uint32_t)local_14[5];
            iVar2 = *local_14;
            if (iVar2 == 1) {
                uintptr_t row = 0;
                while (row < limit) {
                    if (param_3 == nullptr) break;
                    uVar4 = 0;
                    if (param_4 != 0) {
                        do {
                            if (param_3 == nullptr) break;
                            *param_2 = local_8[uVar4];
                            param_2 = param_2 + 1;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            uVar4 = uVar4 + 1;
                        } while (uVar4 < param_4);
                    }
                    row = row + 1;
                }
            } else {
                if (iVar2 != 2) {
                    if (iVar2 == 3) {
                        uintptr_t row = 0;
                        puVar9 = param_3;
                        param_5 = (uint16_t*)(uintptr_t)local_8;
                        while (row < limit) {
                            uVar6 = 0;
                            if (puVar9 == nullptr) break;
                            if (param_4 != 0) {
                                do {
                                    if (puVar9 == nullptr) break;
                                    uVar5 = (uint32_t)ftol();
                                    *puVar7 = uVar5;
                                    puVar7 = puVar7 + 1;
                                    puVar9 = (uint16_t*)((int32_t)puVar9 - 1);
                                    uVar6 = uVar6 + 1;
                                } while (uVar6 < param_4);
                            }
                            param_5 = (uint16_t*)((int32_t)param_5 + 0x40);
                            row = row + 1;
                        }
                    }
                    goto LAB_00645b13;
                }
                {
                    uintptr_t row = 0;
                    while (row < limit) {
                        if (param_3 == nullptr) break;
                        uVar4 = 0;
                        if (param_4 != 0) {
                            do {
                                if (param_3 == nullptr) break;
                                *param_2 = local_8[uVar4];
                                param_2 = param_2 + 1;
                                param_3 = (uint16_t*)((int32_t)param_3 - 1);
                                uVar4 = uVar4 + 1;
                            } while (uVar4 < param_4);
                        }
                        row = row + 1;
                    }
                }
            }
            puVar7 = param_2;
            goto LAB_00645b13;
        }
        if (uVar6 != 3) {
            if (uVar6 == 5) {
                local_10 = 0;
                if (param_4 != 0) {
                    local_c = *(int32_t*)(puVar9 + 6) + (int32_t)param_4;
                }
                uVar6 = (uint32_t)local_14[5];
                piVar1 = local_14 + 6;
                param_7 = 0;
                if (limit != 0) {
                    do {
                        if (param_3 == nullptr) break;
                        param_5 = nullptr;
                        if (uVar6 != 0) {
                            puVar8 = (uint32_t*)(uintptr_t)(local_c + 4);
                            local_14 = piVar1;
                            do {
                                if (param_3 == nullptr) break;
                                if (param_4 != 0) {
                                    local_10 = *puVar8;
                                }
                                FUN_00642362(&local_14, &local_8, &param_2, param_4, local_10,
                                             &param_3, 0xffffffff);
                                param_5 = (uint16_t*)((int32_t)param_5 + 1);
                                puVar8 = puVar8 + 2;
                                puVar7 = param_2;
                            } while ((uintptr_t)param_5 < (uintptr_t)uVar6);
                        }
                        param_7 = param_7 + 1;
                    } while (param_7 < limit);
                }
            }
            goto LAB_00645b13;
        }
    }

    iVar2 = *local_14;
    param_4 = (uint32_t)local_14[6];
    local_c = 0;
    if (uVar6 == 3) {
        local_c = (int32_t)((4 - param_4) * 4);
    }
    if (iVar2 == 1) {
        uintptr_t row = 0;
        while (row < limit) {
            puVar7 = param_2;
            if (param_3 == nullptr) break;
            uVar6 = 0;
            if (param_4 != 0) {
                do {
                    if (param_3 == nullptr) break;
                    uVar5 = *local_8;
                    local_8 = local_8 + 4;
                    *param_2 = uVar5;
                    param_2 = param_2 + 1;
                    param_3 = (uint16_t*)((int32_t)param_3 - 1);
                    uVar6 = uVar6 + 1;
                } while (uVar6 < param_4);
            }
            row = row + 1;
            local_8 = local_8 + local_c;
            puVar7 = param_2;
        }
    } else if (iVar2 == 2) {
        uintptr_t row = 0;
        while (row < limit) {
            if (param_3 == nullptr) break;
            uVar6 = 0;
            if (param_4 != 0) {
                do {
                    if (param_3 == nullptr) break;
                    uVar5 = *local_8;
                    local_8 = local_8 + 4;
                    *puVar7 = uVar5;
                    puVar7 = puVar7 + 1;
                    param_3 = (uint16_t*)((int32_t)param_3 - 1);
                    uVar6 = uVar6 + 1;
                } while (uVar6 < param_4);
            }
            row = row + 1;
            local_8 = local_8 + local_c;
        }
    } else if (iVar2 == 3) {
        uintptr_t row = 0;
        param_5 = param_3;
        local_10 = 0;
        if (limit != 0) {
            do {
                if (param_5 == nullptr) break;
                param_7 = 0;
                puVar8 = puVar7;
                if (param_4 != 0) {
                    do {
                        puVar7 = puVar8;
                        if (param_5 == nullptr) break;
                        uVar5 = (uint32_t)ftol();
                        *puVar8 = uVar5;
                        puVar7 = puVar8 + 1;
                        uVar5 = (uint32_t)ftol();
                        *puVar7 = uVar5;
                        uVar5 = (uint32_t)ftol();
                        puVar8[2] = uVar5;
                        uVar5 = (uint32_t)ftol();
                        param_5 = (uint16_t*)((int32_t)param_5 - 1);
                        param_7 = param_7 + 1;
                        puVar8[3] = uVar5;
                        puVar8 = puVar7;
                    } while (param_7 < param_4);
                }
                local_10 = local_10 + 1;
            } while (local_10 < limit);
        }
    }
LAB_00645b13:
    *param_6 = (uint32_t)((int32_t)(uintptr_t)puVar7 - (int32_t)(uintptr_t)puVar3) >> 2;
    return;
}

// 0x645b25 — observed shape
// Float-to-double conversion of the source surface (param_1[0] pixels,
// param_1[1] format record). Destination kind 2 copies one column per cell as
// doubles, kind 3 widens four consecutive floats per cell, kind 5 walks the
// per-column sub-descriptors through FUN_0064270e, and the default path emits
// the record's columns (+0x14) and rows (+0x18) with the (4 - rows)*4 skip.
// *param_6 receives the produced double count.
void FUN_00645b25(uint32_t* param_1, double* param_2, uint16_t* param_3, int32_t param_4,
                  uint32_t param_5, uint32_t* param_6, float* param_7)
{
    float fVar1;
    int32_t* piVar2 = (int32_t*)(uintptr_t)param_1[1];
    float* local_8 = (float*)(uintptr_t)*param_1;
    float* pfVar5;
    float* pfVar7;
    double* pdVar3 = param_2;
    double* pdVar8 = param_2;
    uint32_t uVar4;
    uint32_t uVar9 = 0;
    uint32_t uVar12;
    uint32_t uVar13;
    int32_t iVar6;
    uint16_t* puVar10;
    uint32_t* puVar11;
    int32_t local_14 = 0;
    int32_t* local_10;
    uint32_t local_c = 0;
    uintptr_t limit;

    if (param_4 == 0) {
        uVar4 = (uint32_t)piVar2[1];
        puVar10 = param_3;
    } else {
        puVar10 = (uint16_t*)(uintptr_t)(*(int32_t*)(param_5 + 0xc) + param_4);
        uVar4 = (uint32_t)*puVar10;
    }
    if (param_7 == (float*)(uintptr_t)0xffffffff) {
        limit = (uintptr_t)(uint32_t)piVar2[4];
        if (limit == 0) {
            limit = 1;
        }
    } else {
        limit = (uintptr_t)param_7;
    }
    pdVar8 = param_2;
    if ((int32_t)uVar4 < 0) goto LAB_00645eac;

    if (1 < (int32_t)uVar4) {
        if (uVar4 == 2) {
            uVar4 = (uint32_t)piVar2[5];
            uVar13 = (uint32_t)piVar2[6];
            iVar6 = *piVar2;
            if (iVar6 == 1) {
                uintptr_t row = 0;
                while (row < limit) {
                    uVar12 = 0;
                    pdVar8 = param_2;
                    if (param_3 == nullptr) break;
                    if (uVar4 != 0) {
                        do {
                            uVar9 = 0;
                            if (param_3 == nullptr) break;
                            if (uVar13 != 0) {
                                iVar6 = (int32_t)(uVar12 << 2);
                                do {
                                    int32_t* p = (int32_t*)(uintptr_t)(iVar6 + (int32_t)(uintptr_t)local_8);
                                    iVar6 = iVar6 + 0x10;
                                    param_2[uVar9] = (double)*p;
                                    uVar9 = uVar9 + 1;
                                } while (uVar9 < uVar13);
                            }
                            param_2 = param_2 + 4;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            uVar12 = uVar12 + 1;
                        } while (uVar12 < uVar4);
                    }
                    row = row + 1;
                    pdVar8 = param_2;
                }
            } else if (iVar6 == 2) {
                uintptr_t row = 0;
                while (row < limit) {
                    uVar12 = 0;
                    pdVar8 = param_2;
                    if (param_3 == nullptr) break;
                    if (uVar4 != 0) {
                        do {
                            uVar9 = 0;
                            if (param_3 == nullptr) break;
                            if (uVar13 != 0) {
                                iVar6 = (int32_t)(uVar12 << 2);
                                do {
                                    int32_t* p = (int32_t*)(uintptr_t)(iVar6 + (int32_t)(uintptr_t)local_8);
                                    iVar6 = iVar6 + 0x10;
                                    param_2[uVar9] = (double)*p;
                                    uVar9 = uVar9 + 1;
                                } while (uVar9 < uVar13);
                            }
                            param_2 = param_2 + 4;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            uVar12 = uVar12 + 1;
                        } while (uVar12 < uVar4);
                    }
                    row = row + 1;
                    pdVar8 = param_2;
                }
            } else if (iVar6 == 3) {
                float* srcRow = local_8;
                local_c = 0;
                if (limit != 0) {
                    do {
                        uVar12 = 0;
                        if (param_3 == nullptr) break;
                        if (uVar4 != 0) {
                            pfVar7 = srcRow;
                            do {
                                if (param_3 == nullptr) break;
                                uVar9 = 0;
                                if (uVar13 != 0) {
                                    pfVar5 = pfVar7;
                                    do {
                                        fVar1 = *pfVar5;
                                        pfVar5 = pfVar5 + 4;
                                        param_2[uVar9] = (double)fVar1;
                                        uVar9 = uVar9 + 1;
                                    } while (uVar9 < uVar13);
                                }
                                param_2 = param_2 + 4;
                                param_3 = (uint16_t*)((int32_t)param_3 - 1);
                                uVar12 = uVar12 + 1;
                                pfVar7 = pfVar7 + 1;
                            } while (uVar12 < uVar4);
                        }
                        srcRow = srcRow + 0x10;
                        local_c = local_c + 1;
                    } while (local_c < limit);
                }
                pdVar8 = param_2;
            }
            goto LAB_00645eac;
        }
        if (uVar4 != 3) {
            if (uVar4 == 5) {
                local_c = 0;
                if (param_4 != 0) {
                    local_14 = *(int32_t*)(puVar10 + 6) + param_4;
                }
                param_7 = nullptr;
                uVar4 = (uint32_t)piVar2[5];
                if (limit != 0) {
                    do {
                        if (param_3 == nullptr) break;
                        param_5 = 0;
                        if (uVar4 != 0) {
                            puVar11 = (uint32_t*)(uintptr_t)(local_14 + 4);
                            local_10 = piVar2 + 6;
                            do {
                                if (param_3 == nullptr) break;
                                if (param_4 != 0) {
                                    local_c = *puVar11;
                                }
                                FUN_0064270e(&local_10, &local_8, &param_2, (uint32_t)param_4,
                                             local_c, &param_3, 0xffffffff);
                                param_5 = param_5 + 1;
                                puVar11 = puVar11 + 2;
                                pdVar8 = param_2;
                            } while (param_5 < uVar4);
                        }
                        param_7 = (float*)((int32_t)param_7 + 1);
                    } while ((uintptr_t)param_7 < limit);
                }
            }
            goto LAB_00645eac;
        }
    }

    uVar13 = (uint32_t)piVar2[5];
    uVar12 = (uint32_t)piVar2[6];
    iVar6 = *piVar2;
    param_5 = 0;
    if (uVar4 == 3) {
        param_5 = (4 - uVar12) * 4;
    }
    if (iVar6 == 1) {
        uintptr_t row = 0;
        while (row < limit) {
            if (param_3 == nullptr) break;
            uVar4 = 0;
            if (uVar12 != 0) {
                do {
                    if (param_3 == nullptr) break;
                    uVar9 = 0;
                    if (uVar13 != 0) {
                        do {
                            param_2[uVar9] = (double)(int32_t)local_8[uVar9];
                            uVar9 = uVar9 + 1;
                        } while (uVar9 < uVar13);
                    }
                    param_2 = param_2 + 4;
                    local_8 = local_8 + 4;
                    param_3 = (uint16_t*)((int32_t)param_3 - 1);
                    uVar4 = uVar4 + 1;
                } while (uVar4 < uVar12);
            }
            row = row + 1;
            local_8 = local_8 + param_5;
        }
    } else {
        if (iVar6 != 2) {
            if (iVar6 == 3) {
                uintptr_t row = 0;
                while (row < limit) {
                    pdVar8 = param_2;
                    if (param_3 == nullptr) break;
                    uVar13 = 0;
                    pfVar7 = local_8;
                    if (uVar12 != 0) {
                        do {
                            pfVar7 = local_8;
                            param_2 = pdVar8;
                            if (param_3 == nullptr) break;
                            pfVar7 = local_8 + 4;
                            *pdVar8 = (double)*local_8;
                            param_2 = pdVar8 + 4;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            pdVar8[1] = (double)local_8[1];
                            uVar13 = uVar13 + 1;
                            pdVar8[2] = (double)local_8[2];
                            pdVar8[3] = (double)local_8[3];
                            local_8 = pfVar7;
                            pdVar8 = param_2;
                        } while (uVar13 < uVar12);
                    }
                    row = row + 1;
                    local_8 = pfVar7 + param_5;
                    pdVar8 = param_2;
                }
            }
            goto LAB_00645eac;
        }
        {
            uintptr_t row = 0;
            while (row < limit) {
                if (param_3 == nullptr) break;
                uVar4 = 0;
                if (uVar12 != 0) {
                    do {
                        if (param_3 == nullptr) break;
                        uVar9 = 0;
                        if (uVar13 != 0) {
                            do {
                                param_2[uVar9] = (double)(int32_t)local_8[uVar9];
                                uVar9 = uVar9 + 1;
                            } while (uVar9 < uVar13);
                        }
                        param_2 = param_2 + 4;
                        local_8 = local_8 + 4;
                        param_3 = (uint16_t*)((int32_t)param_3 - 1);
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < uVar12);
                }
                row = row + 1;
                local_8 = local_8 + param_5;
            }
        }
    }
    pdVar8 = param_2;
LAB_00645eac:
    *param_6 = (uint32_t)((int32_t)(uintptr_t)pdVar8 - (int32_t)(uintptr_t)pdVar3) >> 5;
    return;
}

// 0x645ebe — observed shape
// Float-to-double conversion with the source width taken from the record's
// +0x18. Kinds below 2 and kind 3 share the FUN_006460a4 path (one double per
// source float, skipping (4 - rows)*4 floats per row for kind 3); kind 2 emits
// one double per column of the raw float data; kind 5 walks the per-column
// sub-descriptors through FUN_00642b18. *param_6 receives the double count.
void FUN_00645ebe(uint32_t* param_1, double* param_2, uint16_t* param_3, int32_t param_4,
                  uint32_t param_5, uint32_t* param_6, uint32_t param_7)
{
    float fVar1;
    int32_t* piVar2 = (int32_t*)(uintptr_t)param_1[1];
    float* local_8 = (float*)(uintptr_t)*param_1;
    int32_t iVar3;
    double* pdVar4 = param_2;
    double* pdVar6 = param_2;
    float* pfVar5;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar11;
    uint16_t* puVar9;
    uint32_t* puVar10;
    int32_t local_14 = 0;
    int32_t* local_c;
    uintptr_t limit;

    if (param_4 == 0) {
        uVar7 = (uint32_t)piVar2[1];
        puVar9 = param_3;
    } else {
        puVar9 = (uint16_t*)(uintptr_t)(*(int32_t*)(param_5 + 0xc) + param_4);
        uVar7 = (uint32_t)*puVar9;
    }
    if (param_7 == 0xffffffff) {
        limit = (uintptr_t)(uint32_t)piVar2[4];
        if (limit == 0) {
            limit = 1;
        }
    } else {
        limit = (uintptr_t)param_7;
    }
    pdVar6 = param_2;
    if ((int32_t)uVar7 < 0) goto LAB_006461b5;

    if ((int32_t)uVar7 < 2) {
    LAB_006460a4:
        uVar8 = (uint32_t)piVar2[6];
        iVar3 = *piVar2;
        param_4 = 0;
        if (uVar7 == 3) {
            param_4 = (int32_t)((4 - uVar8) * 4);
        }
        if (iVar3 == 1) {
            uintptr_t row = 0;
            while (row < limit) {
                if (param_3 == nullptr) break;
                uVar7 = 0;
                if (uVar8 != 0) {
                    do {
                        if (param_3 == nullptr) break;
                        fVar1 = *local_8;
                        local_8 = local_8 + 4;
                        *param_2 = (double)(int32_t)fVar1;
                        param_2 = param_2 + 1;
                        param_3 = (uint16_t*)((int32_t)param_3 - 1);
                        uVar7 = uVar7 + 1;
                    } while (uVar7 < uVar8);
                }
                row = row + 1;
                local_8 = local_8 + param_4;
            }
        } else {
            if (iVar3 != 2) {
                if (iVar3 == 3) {
                    uintptr_t row = 0;
                    while (row < limit) {
                        pdVar6 = param_2;
                        if (param_3 == nullptr) break;
                        uVar11 = 0;
                        pfVar5 = local_8;
                        if (uVar8 != 0) {
                            do {
                                pfVar5 = local_8;
                                param_2 = pdVar6;
                                if (param_3 == nullptr) break;
                                param_2 = pdVar6 + 1;
                                *pdVar6 = (double)*local_8;
                                pfVar5 = local_8 + 4;
                                param_3 = (uint16_t*)((int32_t)param_3 - 1);
                                *param_2 = (double)local_8[1];
                                uVar11 = uVar11 + 1;
                                pdVar6[2] = (double)local_8[2];
                                pdVar6[3] = (double)local_8[3];
                                local_8 = pfVar5;
                                pdVar6 = param_2;
                            } while (uVar11 < uVar8);
                        }
                        row = row + 1;
                        local_8 = pfVar5 + param_4;
                        pdVar6 = param_2;
                    }
                }
                goto LAB_006461b5;
            }
            {
                uintptr_t row = 0;
                while (row < limit) {
                    if (param_3 == nullptr) break;
                    uVar7 = 0;
                    if (uVar8 != 0) {
                        do {
                            if (param_3 == nullptr) break;
                            fVar1 = *local_8;
                            local_8 = local_8 + 4;
                            *param_2 = (double)(int32_t)fVar1;
                            param_2 = param_2 + 1;
                            param_3 = (uint16_t*)((int32_t)param_3 - 1);
                            uVar7 = uVar7 + 1;
                        } while (uVar7 < uVar8);
                    }
                    row = row + 1;
                    local_8 = local_8 + param_4;
                }
            }
        }
    } else {
        if (uVar7 != 2) {
            if (uVar7 != 3) {
                if (uVar7 == 5) {
                    param_7 = 0;
                    if (param_4 != 0) {
                        local_14 = *(int32_t*)(puVar9 + 6) + param_4;
                    }
                    uVar7 = (uint32_t)piVar2[5];
                    param_5 = 0;
                    if (limit != 0) {
                        do {
                            if (param_3 == nullptr) break;
                            uVar8 = 0;
                            if (uVar7 != 0) {
                                puVar10 = (uint32_t*)(uintptr_t)(local_14 + 4);
                                local_c = piVar2 + 6;
                                do {
                                    if (param_3 == nullptr) break;
                                    if (param_4 != 0) {
                                        param_7 = *puVar10;
                                    }
                                    FUN_00642b18(&local_c, &local_8, &param_2, (uint32_t)param_4,
                                                 param_7, &param_3, 0xffffffff);
                                    uVar8 = uVar8 + 1;
                                    puVar10 = puVar10 + 2;
                                    pdVar6 = param_2;
                                } while (uVar8 < uVar7);
                            }
                            param_5 = param_5 + 1;
                        } while (param_5 < limit);
                    }
                }
                goto LAB_006461b5;
            }
            goto LAB_006460a4;
        }
        uVar7 = (uint32_t)piVar2[5];
        iVar3 = *piVar2;
        if (iVar3 == 1) {
            uintptr_t row = 0;
            while (row < limit) {
                if (param_3 == nullptr) break;
                uVar11 = 0;
                if (uVar7 != 0) {
                    do {
                        if (param_3 == nullptr) break;
                        *pdVar6 = (double)(int32_t)local_8[uVar11];
                        pdVar6 = pdVar6 + 1;
                        param_3 = (uint16_t*)((int32_t)param_3 - 1);
                        uVar11 = uVar11 + 1;
                    } while (uVar11 < uVar7);
                }
                row = row + 1;
            }
            goto LAB_006461b5;
        }
        if (iVar3 == 2) {
            uintptr_t row = 0;
            while (row < limit) {
                if (param_3 == nullptr) break;
                uVar11 = 0;
                if (uVar7 != 0) {
                    do {
                        if (param_3 == nullptr) break;
                        *pdVar6 = (double)(int32_t)local_8[uVar11];
                        pdVar6 = pdVar6 + 1;
                        param_3 = (uint16_t*)((int32_t)param_3 - 1);
                        uVar11 = uVar11 + 1;
                    } while (uVar11 < uVar7);
                }
                row = row + 1;
            }
            goto LAB_006461b5;
        }
        if (iVar3 != 3) goto LAB_006461b5;
        {
            uintptr_t row = 0;
            while (row < limit) {
                if (param_3 == nullptr) break;
                uVar11 = 0;
                if (uVar7 != 0) {
                    do {
                        if (param_3 == nullptr) break;
                        *param_2 = (double)local_8[uVar11];
                        param_2 = param_2 + 1;
                        param_3 = (uint16_t*)((int32_t)param_3 - 1);
                        uVar11 = uVar11 + 1;
                    } while (uVar11 < uVar7);
                }
                local_8 = local_8 + 0x10;
                row = row + 1;
            }
        }
    }
    pdVar6 = param_2;
LAB_006461b5:
    *param_6 = (uint32_t)((int32_t)(uintptr_t)pdVar6 - (int32_t)(uintptr_t)pdVar4) >> 3;
    return;
}

// 0x6461c7 — observed shape
// Acquires up to two interfaces through self->+0xc's vtbl+0xf0 / +0xf4 around
// a FUN_00642e5e(param_1, param_2) call, then swaps the reference stored in
// the self->+0xa4 record at +0x94: the current object is released through
// vtbl+8 when its vtbl+0x10/+0x14 checks all succeed, and the newly acquired
// second interface is installed. Both temporaries are released on exit.
int32_t FUN_006461c7(void* self_, uint32_t param_1, uint32_t param_2)
{
    const int32_t self = (int32_t)(uintptr_t)self_;
    int32_t* piVar1;
    int32_t* piVar2;
    int32_t iVar3 = 0;
    int32_t* local_18[3];
    int32_t** local_c;
    uint32_t local_8;
    int32_t obj;
    int32_t vtbl;

    local_18[2] = (int32_t*)(uintptr_t)((uint32_t)*(uint16_t*)(self + 0x42) * 0xb4 + 0x94 +
                                        *(int32_t*)(self + 0xa4));
    local_18[0] = nullptr;
    local_18[1] = nullptr;
    if ((*(uint8_t*)(self + 0x119) & 2) == 0) {
        local_c = local_18;
        local_8 = 0;
        do {
            obj = *(int32_t*)(self + 0xc);
            vtbl = *(int32_t*)(uintptr_t)obj;
            iVar3 = ((int32_t(*)(int32_t))(*(int32_t*)(vtbl + 0xf0)))(obj);
            if (iVar3 < 0) goto LAB_006462d2;
            FUN_005f8ea2(1);
            iVar3 = FUN_00642e5e(param_1, param_2);
            FUN_005f8ea2(0);
            if (iVar3 < 0) {
                obj = *(int32_t*)(self + 0xc);
                vtbl = *(int32_t*)(uintptr_t)obj;
                ((void(*)(int32_t, int32_t**))(*(int32_t*)(vtbl + 0xf4)))(obj, local_18 + local_8);
                goto LAB_006462d2;
            }
            obj = *(int32_t*)(self + 0xc);
            vtbl = *(int32_t*)(uintptr_t)obj;
            iVar3 = ((int32_t(*)(int32_t, int32_t**))(*(int32_t*)(vtbl + 0xf4)))(obj, local_c);
            if (iVar3 < 0) goto LAB_006462d2;
            local_8 = local_8 + 1;
            local_c = local_c + 1;
        } while (local_8 < 2);
    }
    iVar3 = ((int32_t(*)(int32_t*))(*(int32_t*)(*local_18[0] + 0x10)))(local_18[0]);
    piVar2 = local_18[2];
    if (-1 < iVar3) {
        piVar1 = (int32_t*)(uintptr_t)*piVar2;
        if (piVar1 == nullptr) {
            iVar3 = 0;
        } else {
            iVar3 = ((int32_t(*)(int32_t*))(*(int32_t*)(*piVar1 + 0x14)))(piVar1);
        }
        if (-1 < iVar3) {
            iVar3 = ((int32_t(*)(int32_t*))(*(int32_t*)(*local_18[1] + 0x10)))(local_18[1]);
            if (-1 < iVar3) {
                iVar3 = ((int32_t(*)(int32_t*))(*(int32_t*)(*local_18[0] + 0x14)))(local_18[0]);
                if (-1 < iVar3) {
                    piVar1 = (int32_t*)(uintptr_t)*piVar2;
                    if (piVar1 != nullptr) {
                        ((void(*)(int32_t*))(*(int32_t*)(*piVar1 + 8)))(piVar1);
                        *piVar2 = 0;
                    }
                    *piVar2 = (int32_t)(uintptr_t)local_18[1];
                    local_18[1] = nullptr;
                }
            }
        }
    }
LAB_006462d2:
    if (local_18[0] != nullptr) {
        ((void(*)(int32_t*))(*(int32_t*)(*local_18[0] + 8)))(local_18[0]);
        local_18[0] = nullptr;
    }
    if (local_18[1] != nullptr) {
        ((void(*)(int32_t*))(*(int32_t*)(*local_18[1] + 8)))(local_18[1]);
    }
    return iVar3;
}
