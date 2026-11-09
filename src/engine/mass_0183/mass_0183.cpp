// Reconstruction batch mass_0183 — Sid Meier's Pirates! (2004), PE32 i386.
// Translated from Ghidra 12.2 pseudocode corpus listings; observed field
// offsets, constants, call order, return shape and conditional structure
// are preserved. Register receivers (in_ECX) use an explicit self pointer.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// Helpers and globals referenced by the assigned listings.
extern int FUN_00580580(int param_1);
extern void FUN_005805e0(void* self);
extern void FUN_00580880(void* self, void* param_1);
extern void FUN_005808d0(void* self, void* param_1);
extern void FUN_00580980(void* self, uint8_t param_1);
extern void FUN_005809e0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, char param_4);
extern void FUN_00580a60(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, char param_4);
extern void FUN_00580ae0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, char param_4);
extern int FUN_00580b60(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_00580d10(int param_1);
extern void FUN_00580e30(void* self, uint8_t param_1);
extern void FUN_00580e80(void* self, int* param_1);
extern void FUN_00580ed0(void* self);
extern void FUN_00580f40(void* self);
extern int FUN_005810a0(uint32_t param_1, uint32_t param_2, int param_3);
extern uint8_t FUN_005812c0(void* self, uint32_t param_1);
extern void FUN_00581300(void* self, uint32_t param_1, int* param_2);
extern void FUN_00581390(void* self);
extern void FUN_005813e0(void* self, uint8_t param_1);
extern void FUN_00581500(void* self, int* param_1);

extern int FUN_00552bc0(int param_1);
extern int FUN_00552c80(void* self);
extern void FUN_00552d20(void* self);
extern int FUN_00552b90(uint32_t param_1);
extern void FUN_00552e30(void* self, int param_1);
extern void FUN_00552ef0(int target, uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_005530e0(void* self);
extern int FUN_005531c0(int param_1);
extern int FUN_00533c78(uint32_t size);
extern int* FUN_00538580(uint32_t* local);
extern int FUN_00538680(void);
extern void FUN_00557b10(uint32_t arg);
extern void FUN_005606f0(uint32_t a, uint32_t* b);
extern void FUN_00576320(int a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t* g, uint32_t* h);
extern void FUN_0057fc00(void);
extern void FUN_0057fd30(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_0057ff30(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_00575bb0(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_00577e50(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_00573780(uint32_t arg);
extern void FUN_0053f2c0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern void FUN_00548120(uint32_t a, uint32_t b);
extern void FUN_00548600(uint8_t* arg);
extern void FUN_005734e0(void* self);
extern void FUN_006b34a0(uint32_t arg);

extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t DAT_00717a68;
extern uint32_t DAT_00717a6c;
extern uint32_t DAT_00717a70;
extern uint32_t DAT_00717a74;
extern uint32_t DAT_00728a3c;
extern uint32_t DAT_00727598;
extern void* PTR_FUN_006c4cb8;
extern void* PTR_FUN_006c4d20;
extern void* PTR_FUN_006c4d90;

extern void operator_delete(void* ptr);

typedef void (*code_fn)(void);

// 0x580580 — observed shape: forwards source (+0x50) ref to self (+0x50);
// vtable call at +0x1c on dest when both non-null/matching; returns
// concat(high,1) or high<<8 based on extraout flags.
int FUN_00580580_recon(void* self, int param_1)
{
    // FUN_00552bc0 produces uVar2 with side flags in extraout_AL.
    int ret = FUN_00552bc0(param_1);
    uint32_t uVar2 = (uint32_t)ret & 0xffffff00u; // uint3 part observed
    bool hasExtra = (ret & 0x1000000) != 0; // extraout_AL projection
    if (hasExtra) {
        int* piVar1 = *(int**)((char*)self + 0x50);
        bool selfNull = (piVar1 == nullptr);
        bool paramNull = (*(int*)((char*)&param_1 + 0x50) == 0);
        if (selfNull == paramNull) {
            if (piVar1 != nullptr) {
                int dest = *(int*)((char*)&param_1 + 0x50);
                code_fn vt = *(code_fn*)(*(int*)piVar1 + 0x1c);
                vt((void*)(intptr_t)dest);
                // second extraout_AL_00 observed
                bool secondFlag = false;
                (void)secondFlag;
                if (secondFlag) return (int)(uVar2 << 8);
            }
            return (int)(uVar2 | 1u);
        }
    }
    return (int)(uVar2 << 8);
}

// 0x5805e0 — observed shape: seeds self+0x18 = FLT_MAX, self+0x1c = -FLT_MAX;
// folds min/max over descriptor at +0x50 (fields +0x10..+0x28), handling
// 3-stream (type 4) and single-stream cases, stride via byte at +1.
void FUN_005805e0_recon(void* self)
{
    float* base = (float*)self;
    int iVar5 = *(int*)((char*)self + 0x50);
    *(uint32_t*)((char*)self + 0x18) = 0x7f7fffffu;
    *(uint32_t*)((char*)self + 0x1c) = 0xff7fffffu;
    if (iVar5 == 0) return;
    float* pfVar3 = *(float**)(iVar5 + 0x10);
    int iVar4 = *(int*)(iVar5 + 0xc);
    if (pfVar3 != nullptr) {
        uint16_t uVar6 = 0xffffu;
        if (*(int*)(iVar5 + 0x14) == 4) {
            float fVar1 = pfVar3[6];
            if (fVar1 != 0.0f) {
                float* pfVar2 = (float*)(uintptr_t)pfVar3[0xd];
                if (*pfVar2 < 3.4028235e+38f) {
                    *(float*)((char*)self + 0x18) = *pfVar2;
                }
                int iVar4b = (int)((uint8_t)*(pfVar2 + 1) * ((int)fVar1 - 1));
                if (-3.4028235e+38f < *(float*)((char*)pfVar2 + iVar4b)) {
                    *(float*)((char*)self + 0x1c) = *(float*)((char*)pfVar2 + iVar4b);
                }
            }
            fVar1 = pfVar3[7];
            if (fVar1 != 0.0f) {
                float* pfVar2 = (float*)(uintptr_t)pfVar3[0xe];
                if (*pfVar2 < *(float*)((char*)self + 0x18)) {
                    *(float*)((char*)self + 0x18) = *pfVar2;
                }
                int iVar4c = (int)((uint8_t)*(pfVar2 + 1) * ((int)fVar1 - 1));
                if (*(float*)((char*)self + 0x1c) < *(float*)((char*)pfVar2 + iVar4c)) {
                    *(float*)((char*)self + 0x1c) = *(float*)((char*)pfVar2 + iVar4c);
                }
            }
            fVar1 = pfVar3[8];
            if (fVar1 != 0.0f) {
                pfVar3 = (float*)(uintptr_t)pfVar3[0xf];
                if (*pfVar3 < *(float*)((char*)self + 0x18)) {
                    *(float*)((char*)self + 0x18) = *pfVar3;
                }
                int iVar4d = (int)((uint8_t)*(pfVar3 + 1) * ((int)fVar1 - 1));
                float fLast = *(float*)((char*)pfVar3 + iVar4d);
                uVar6 = (uint16_t)((fLast < *(float*)((char*)self + 0x1c)) << 8)
                      | (uint16_t)((fLast == *(float*)((char*)self + 0x1c)) << 0xe);
                pfVar3 = (float*)((char*)pfVar3 + iVar4d);
            }
        } else {
            if (*pfVar3 < 3.4028235e+38f) {
                *(float*)((char*)self + 0x18) = *pfVar3;
            }
            int iVar4e = (int)((uint8_t)*(pfVar3 + 1) * (iVar4 - 1));
            float fLast = *(float*)((char*)pfVar3 + iVar4e);
            uVar6 = (uint16_t)((fLast < -3.4028235e+38f) << 8)
                  | (uint16_t)((fLast == -3.4028235e+38f) << 0xe);
            pfVar3 = (float*)((char*)pfVar3 + iVar4e);
        }
        if (uVar6 == 0) {
            *(float*)((char*)self + 0x1c) = *pfVar3;
        }
    }
    if (iVar5 != 0) {
        pfVar3 = *(float**)(iVar5 + 0x1c);
        iVar4 = *(int*)(iVar5 + 0x18);
        if (pfVar3 != nullptr) {
            if (*pfVar3 < *(float*)((char*)self + 0x18)) {
                *(float*)((char*)self + 0x18) = *pfVar3;
            }
            int iVar4f = (int)((uint8_t)*(pfVar3 + 1) * (iVar4 - 1));
            if (*(float*)((char*)self + 0x1c) < *(float*)((char*)pfVar3 + iVar4f)) {
                *(float*)((char*)self + 0x1c) = *(float*)((char*)pfVar3 + iVar4f);
            }
        }
        if (iVar5 != 0) {
            pfVar3 = *(float**)(iVar5 + 0x28);
            iVar5 = *(int*)(iVar5 + 0x24);
            if (pfVar3 != nullptr) {
                if (*pfVar3 < *(float*)((char*)self + 0x18)) {
                    *(float*)((char*)self + 0x18) = *pfVar3;
                }
                int iVar5b = (int)((uint8_t)*(pfVar3 + 1) * (iVar5 - 1));
                if (*(float*)((char*)self + 0x1c) < *(float*)((char*)pfVar3 + iVar5b)) {
                    *(float*)((char*)self + 0x1c) = *(float*)((char*)pfVar3 + iVar5b);
                }
            }
        }
    }
    (void)base;
}

// 0x580880 — observed shape: ref-assign self+0x50 with new ptr param_1,
// zero +0x44/+0x4c/+0x48, then FUN_005805e0.
void FUN_00580880_recon(void* self, void* param_1)
{
    uint32_t* q = (uint32_t*)self;
    uint32_t* puVar2 = *(uint32_t**)((char*)self + 0x50);
    if (puVar2 != (uint32_t*)param_1) {
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                code_fn vt = *(code_fn*)*puVar2;
                // called as (**(code**)*puVar2)(1)
                ((void(*)(int))vt)(1);
            }
        }
        *(void**)((char*)self + 0x50) = param_1;
        if (param_1 != nullptr) {
            ((uint32_t*)param_1)[1] += 1;
        }
    }
    q[0x44 / 4] = 0;
    q[0x4c / 4] = 0;
    q[0x48 / 4] = 0;
    FUN_005805e0(self);
}

// 0x5808d0 — observed shape: ctor-style init; vptr = PTR_FUN_006c4cb8,
// defaults from DAT globals, max seed 0xff7fffff, ref-assign +0x50 slot
// (index 0x14 dwords = +0x50), zero +0x44/+0x48/+0x4c, then FUN_005805e0.
void FUN_005808d0_recon(void* self, void* param_1)
{
    FUN_00552c80(self);
    uint32_t* q = (uint32_t*)self;
    q[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4cb8;
    q[0x14] = 0;
    q[0x11] = 0;
    q[0x12] = 0;
    q[0x13] = 0;
    *(uint8_t*)((char*)self + 0x30) = 0; // (in_ECX + 0xc) dwords = +0x30
    q[0x15] = DAT_00727430;
    q[0x16] = DAT_00727434;
    q[0x17] = DAT_00727438;
    q[0x18] = DAT_00717a68;
    q[0x19] = DAT_00717a6c;
    q[0x1a] = DAT_00717a70;
    q[0x1b] = DAT_00717a74;
    q[0x1c] = 0xff7fffffu;
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)q[0x14];
    if (puVar2 != (uint32_t*)param_1) {
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                code_fn vt = *(code_fn*)*puVar2;
                ((void(*)(int))vt)(1);
            }
        }
        q[0x14] = (uint32_t)(uintptr_t)param_1;
        if (param_1 != nullptr) {
            ((uint32_t*)param_1)[1] += 1;
        }
    }
    q[0x11] = 0;
    q[0x13] = 0;
    q[0x12] = 0;
    FUN_005805e0(self);
}

// 0x580980 — observed shape: dtor-style; vptr = PTR_FUN_006c4cb8, release
// +0x50 ref (clearing slot), release again (no clear), FUN_00552d20,
// conditional operator_delete on param_1 & 1.
void FUN_00580980_recon(void* self, uint8_t param_1)
{
    uint32_t* q = (uint32_t*)self;
    q[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4cb8;
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)q[0x14];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            code_fn vt = *(code_fn*)*puVar2;
            ((void(*)(int))vt)(1);
        }
        q[0x14] = 0;
    }
    puVar2 = (uint32_t*)(uintptr_t)q[0x14];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            code_fn vt = *(code_fn*)*puVar2;
            ((void(*)(int))vt)(1);
        }
    }
    FUN_00552d20(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// Appended definitions for the retry addresses 0x5809e0 .. 0x581500.
// ---------------------------------------------------------------------------

extern void operator_delete__(void* ptr);

// The listings use the result of FUN_0057fc00 / FUN_00557b10 even though the
// shared prototypes above declare them void; reinterpret at the call site to
// preserve the observed value-returning call.

// 0x5809e0 — observed shape: lazily creates the +0x50 descriptor through
// FUN_00533c78(0x30) + FUN_0057fc00, ref-assigns it (release old, incref new),
// then FUN_0057ff30 on the three args, clears +0x44, and re-folds bounds
// through FUN_005805e0 when param_4 is non-zero.
void FUN_005809e0_recon(void* self, uint32_t param_1, uint32_t param_2,
                        uint32_t param_3, char param_4)
{
    if (*(int*)((char*)self + 0x50) == 0) {
        int iVar3 = FUN_00533c78(0x30);
        uint32_t* puVar4 = nullptr;
        if (iVar3 != 0) {
            puVar4 = ((uint32_t* (*)(void))FUN_0057fc00)();
        }
        uint32_t* puVar2 = *(uint32_t**)((char*)self + 0x50);
        if (puVar2 != puVar4) {
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    code_fn vt = *(code_fn*)*puVar2;
                    ((void(*)(int))vt)(1);
                }
            }
            *(uint32_t**)((char*)self + 0x50) = puVar4;
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
    }
    FUN_0057ff30(param_1, param_2, param_3);
    *(uint32_t*)((char*)self + 0x44) = 0;
    if (param_4 != '\0') {
        FUN_005805e0(self);
    }
}

// 0x580a60 — observed shape: same lazy +0x50 descriptor creation/ref-assign as
// 0x5809e0, but initialises with FUN_0057fd30, clears +0x48, then re-folds
// bounds through FUN_005805e0 when param_4 is non-zero.
void FUN_00580a60_recon(void* self, uint32_t param_1, uint32_t param_2,
                        uint32_t param_3, char param_4)
{
    if (*(int*)((char*)self + 0x50) == 0) {
        int iVar3 = FUN_00533c78(0x30);
        uint32_t* puVar4 = nullptr;
        if (iVar3 != 0) {
            puVar4 = ((uint32_t* (*)(void))FUN_0057fc00)();
        }
        uint32_t* puVar2 = *(uint32_t**)((char*)self + 0x50);
        if (puVar2 != puVar4) {
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    code_fn vt = *(code_fn*)*puVar2;
                    ((void(*)(int))vt)(1);
                }
            }
            *(uint32_t**)((char*)self + 0x50) = puVar4;
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
    }
    FUN_0057fd30(param_1, param_2, param_3);
    *(uint32_t*)((char*)self + 0x48) = 0;
    if (param_4 != '\0') {
        FUN_005805e0(self);
    }
}

// 0x580ae0 — observed shape: same lazy +0x50 descriptor creation/ref-assign as
// 0x5809e0, but initialises with FUN_00577e50, clears +0x4c, then re-folds
// bounds through FUN_005805e0 when param_4 is non-zero.
void FUN_00580ae0_recon(void* self, uint32_t param_1, uint32_t param_2,
                        uint32_t param_3, char param_4)
{
    if (*(int*)((char*)self + 0x50) == 0) {
        int iVar3 = FUN_00533c78(0x30);
        uint32_t* puVar4 = nullptr;
        if (iVar3 != 0) {
            puVar4 = ((uint32_t* (*)(void))FUN_0057fc00)();
        }
        uint32_t* puVar2 = *(uint32_t**)((char*)self + 0x50);
        if (puVar2 != puVar4) {
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    code_fn vt = *(code_fn*)*puVar2;
                    ((void(*)(int))vt)(1);
                }
            }
            *(uint32_t**)((char*)self + 0x50) = puVar4;
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
    }
    FUN_00577e50(param_1, param_2, param_3);
    *(uint32_t*)((char*)self + 0x4c) = 0;
    if (param_4 != '\0') {
        FUN_005805e0(self);
    }
}

// 0x580b60 — observed shape: copies the shared descriptor returned by
// FUN_00538580 (release of its temp, incref of the copy), builds a new object
// with FUN_00538680, initialises it with FUN_00552ef0, ref-assigns +0x50,
// clears +0x44/+0x48/+0x4c, folds bounds with FUN_005805e0, then emits the
// type-2 (+0x10/+0x14/+0xc), type-1 (+0x1c/+0x20/+0x18) and type-0
// (+0x28/+0x2c/+0x24) stream index sets via FUN_00576320 and the matching
// setters, finally releasing the copied descriptor. Returns the new object.
int FUN_00580b60_recon(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t* local_4 = nullptr;
    int* piVar5 = FUN_00538580(&local_4);
    uint32_t* puVar1 = (uint32_t*)*piVar5;
    if (puVar1 != nullptr) {
        puVar1[1] = puVar1[1] + 1;
    }
    if ((local_4 != nullptr) &&
        (piVar5 = (int*)(local_4 + 1), *piVar5 = *piVar5 - 1, *piVar5 == 0)) {
        code_fn vt = *(code_fn*)*local_4;
        ((void(*)(int))vt)(1);
    }
    int iVar6 = FUN_00538680();
    FUN_00552ef0(iVar6, param_1, param_2, param_3);
    uint32_t* puVar2 = *(uint32_t**)(iVar6 + 0x50);
    if (puVar2 != puVar1) {
        if (puVar2 != nullptr) {
            piVar5 = (int*)(puVar2 + 1);
            *piVar5 = *piVar5 - 1;
            if (*piVar5 == 0) {
                code_fn vt = *(code_fn*)*puVar2;
                ((void(*)(int))vt)(1);
            }
        }
        *(uint32_t**)(iVar6 + 0x50) = puVar1;
        if (puVar1 != nullptr) {
            puVar1[1] = puVar1[1] + 1;
        }
    }
    *(uint32_t*)(iVar6 + 0x44) = 0;
    *(uint32_t*)(iVar6 + 0x4c) = 0;
    *(uint32_t*)(iVar6 + 0x48) = 0;
    FUN_005805e0((void*)(intptr_t)iVar6);
    uint32_t uStack_c = 0;
    uint32_t uStack_8 = 0;
    int iVar3 = *(int*)(iVar6 + 0x50);
    if (iVar3 != 0) {
        uint32_t uVar4 = *(uint32_t*)(iVar3 + 0x14);
        if (*(int*)(iVar3 + 0xc) != 0) {
            FUN_00576320(2, uVar4, *(uint32_t*)(iVar3 + 0x10),
                         *(uint32_t*)(iVar3 + 0xc), param_1, param_2,
                         &uStack_8, &uStack_c);
            FUN_005809e0((void*)(intptr_t)iVar6, uStack_8, uStack_c, uVar4, 1);
        }
    }
    iVar3 = *(int*)(iVar6 + 0x50);
    if (iVar3 != 0) {
        uint32_t uVar4 = *(uint32_t*)(iVar3 + 0x20);
        if (*(int*)(iVar3 + 0x18) != 0) {
            FUN_00576320(1, uVar4, *(uint32_t*)(iVar3 + 0x1c),
                         *(uint32_t*)(iVar3 + 0x18), param_1, param_2,
                         &uStack_8, &uStack_c);
            FUN_00580a60((void*)(intptr_t)iVar6, uStack_8, uStack_c, uVar4, 1);
        }
    }
    iVar3 = *(int*)(iVar6 + 0x50);
    if (iVar3 != 0) {
        uint32_t uVar4 = *(uint32_t*)(iVar3 + 0x2c);
        if (*(int*)(iVar3 + 0x24) != 0) {
            FUN_00576320(0, uVar4, *(uint32_t*)(iVar3 + 0x28),
                         *(uint32_t*)(iVar3 + 0x24), param_1, param_2,
                         &uStack_8, &uStack_c);
            FUN_00580ae0((void*)(intptr_t)iVar6, uStack_8, uStack_c, uVar4, 1);
        }
    }
    if (puVar1 != nullptr) {
        piVar5 = (int*)(puVar1 + 1);
        *piVar5 = *piVar5 - 1;
        if (*piVar5 == 0) {
            code_fn vt = *(code_fn*)*puVar1;
            ((void(*)(int))vt)(1);
        }
    }
    return iVar6;
}

// 0x580d10 — observed shape: FUN_005531c0 on param_1, then assigns the result
// of FUN_00557b10(DAT_00728a3c); reads the element count at +0xc, grows the
// +0x14 backing store through FUN_006b34a0 when +0x8 <= count (offsetting by
// the count), then FUN_005606f0(count, &value).
void FUN_00580d10_recon(int param_1)
{
    int iVar2 = param_1;
    FUN_005531c0(param_1);
    // Listing assigns FUN_00557b10's result although the shared prototype is
    // void; call it with the observed value-returning shape.
    uint32_t paramVar = ((uint32_t (*)(uint32_t))FUN_00557b10)(DAT_00728a3c);
    uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &paramVar);
}

// 0x580e30 — observed shape: dtor-style; vptr = PTR_FUN_006c4d20, delete the
// field at +0x54 through operator_delete__, FUN_005734e0 on self, and
// conditional operator_delete when param_1 bit 0 is set.
void FUN_00580e30_recon(void* self, uint8_t param_1)
{
    uint32_t* q = (uint32_t*)self;
    q[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4d20;
    operator_delete__((void*)(uintptr_t)q[0x15]);
    FUN_005734e0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x580e80 — observed shape: when param_1 is non-null, walks the list returned
// by its virtual +4 entry looking for the DAT_00727598 sentinel; on match
// FUN_00552e30(self, param_1) and invoke self's virtual +0x6c, otherwise
// FUN_00552e30(self, 0).
void FUN_00580e80_recon(void* self, int* param_1)
{
    if (param_1 != nullptr) {
        void* puVar1 = ((void* (*)(void))(uintptr_t) * (int*)(*param_1 + 4))();
        for (; puVar1 != nullptr; puVar1 = *(void**)((char*)puVar1 + 4)) {
            if (puVar1 == (void*)&DAT_00727598) {
                FUN_00552e30(self, (int)(intptr_t)param_1);
                code_fn vt = *(code_fn*)(*(int*)self + 0x6c);
                vt();
                return;
            }
        }
    }
    FUN_00552e30(self, 0);
}

// 0x580ed0 — observed shape: guarded by byte +0x4c; FUN_00573780(+0x2c); when
// byte +0x50 is set, clear the +0x34 owner's +0xbc object through
// FUN_0053f2c0(field +0x20, self +0x58, self +0x54, owner +0xc) and clear
// +0x50; then set bit 0 of that object's +0x32 flags and, when bit 0 of +0x44
// and object[9] are non-zero, invoke its virtual +0x3c; finally clear +0x4c.
void FUN_00580ed0_recon(void* self)
{
    if (*(uint8_t*)((char*)self + 0x4c) != 0) {
        FUN_00573780(*(uint32_t*)((char*)self + 0x2c));
        if (*(uint8_t*)((char*)self + 0x50) != 0) {
            int iVar1 = *(int*)(*(int*)((char*)self + 0x34) + 0xbc);
            FUN_0053f2c0(*(uint32_t*)(iVar1 + 0x20), *(uint32_t*)((char*)self + 0x58),
                         *(uint32_t*)((char*)self + 0x54), *(uint16_t*)(iVar1 + 0xc));
            *(uint8_t*)((char*)self + 0x50) = 0;
        }
        int* piVar2 = *(int**)(*(int*)((char*)self + 0x34) + 0xbc);
        *(uint16_t*)((char*)piVar2 + 0x32) = *(uint16_t*)((char*)piVar2 + 0x32) | 1;
        if (((*(uint8_t*)((char*)self + 0x44) & 1) != 0) && (piVar2[9] != 0)) {
            code_fn vt = *(code_fn*)(*piVar2 + 0x3c);
            vt();
        }
        *(uint8_t*)((char*)self + 0x4c) = 0;
    }
}

// 0x580f40 — observed shape: when the +0x48 descriptor's count +0xc is zero,
// seed a 4-dword record from DAT_00727430/34/38 with 0; otherwise for the
// first entry pass (+0x10, entry[0]) to FUN_00548120 and, for every further
// 0x14-strided entry, FUN_00548120(+0x10, entry[0]) followed by
// FUN_00548600(local buffer). Writes the 4 dwords into the +0x34 owner's
// +0xbc object at +0x10..+0x1c.
void FUN_00580f40_recon(void* self)
{
    uint32_t local_20 = 0;
    uint32_t local_1c = 0;
    uint32_t local_18 = 0;
    uint32_t local_14 = 0;
    uint8_t local_10[16];
    int iVar5 = *(int*)((char*)self + 0x48);
    uint32_t uVar1 = *(uint32_t*)(iVar5 + 0xc);
    if (uVar1 == 0) {
        local_20 = DAT_00727430;
        local_1c = DAT_00727434;
        local_18 = DAT_00727438;
        local_14 = 0;
    } else {
        uint32_t* puVar3;
        if (uVar1 == 0) {
            puVar3 = nullptr;
        } else {
            puVar3 = *(uint32_t**)(iVar5 + 0x14);
        }
        FUN_00548120(*(uint32_t*)(iVar5 + 0x10), *puVar3);
        uint32_t uVar4 = 1;
        if (1 < uVar1) {
            iVar5 = 0x14;
            do {
                int iVar2 = *(int*)((char*)self + 0x48);
                if (uVar4 < *(uint32_t*)(iVar2 + 0xc)) {
                    puVar3 = (uint32_t*)(*(int*)(iVar2 + 0x14) + iVar5);
                } else {
                    puVar3 = nullptr;
                }
                FUN_00548120(*(uint32_t*)(iVar2 + 0x10), *puVar3);
                FUN_00548600(local_10);
                uVar4 = uVar4 + 1;
                iVar5 = iVar5 + 0x14;
            } while (uVar4 < uVar1);
        }
    }
    iVar5 = *(int*)(*(int*)((char*)self + 0x34) + 0xbc);
    *(uint32_t*)(iVar5 + 0x10) = local_20;
    *(uint32_t*)(iVar5 + 0x14) = local_1c;
    *(uint32_t*)(iVar5 + 0x18) = local_18;
    *(uint32_t*)(iVar5 + 0x1c) = local_14;
}

// 0x5810a0 — observed shape: copies the shared descriptor via FUN_00538580
// (incref copy, release temp), builds a new object with FUN_00538680,
// FUN_00552ef0 on the args, ref-assigns +0x48, then walks the descriptor's
// 0x14-strided entries of count +0xc emitting each through FUN_00576320(0,..)
// and FUN_00575bb0; releases the copy and returns the new object.
int FUN_005810a0_recon(uint32_t param_1, uint32_t param_2, int param_3)
{
    uint32_t* local_10 = nullptr;
    int* piVar4 = FUN_00538580(&local_10);
    uint32_t* puVar1 = (uint32_t*)*piVar4;
    if (puVar1 != nullptr) {
        puVar1[1] = puVar1[1] + 1;
    }
    if ((local_10 != nullptr) &&
        (piVar4 = (int*)(local_10 + 1), *piVar4 = *piVar4 - 1, *piVar4 == 0)) {
        code_fn vt = *(code_fn*)*local_10;
        ((void(*)(int))vt)(1);
    }
    int iVar5 = FUN_00538680();
    int iStack_4 = iVar5;
    FUN_00552ef0(iVar5, param_1, param_2, (uint32_t)param_3);
    uint32_t* puVar2 = *(uint32_t**)(iVar5 + 0x48);
    if (puVar2 != puVar1) {
        if (puVar2 != nullptr) {
            piVar4 = (int*)(puVar2 + 1);
            *piVar4 = *piVar4 - 1;
            if (*piVar4 == 0) {
                code_fn vt = *(code_fn*)*puVar2;
                ((void(*)(int))vt)(1);
            }
        }
        *(uint32_t**)(iVar5 + 0x48) = puVar1;
        if (puVar1 != nullptr) {
            puVar1[1] = puVar1[1] + 1;
        }
    }
    uint32_t uStack_c = 0;
    uint32_t uStack_8 = 0;
    uint32_t uVar6 = 0;
    if (puVar1[3] != 0) {
        param_3 = 0;
        if (puVar1[3] == 0) {
            iVar5 = 0;
        } else {
            do {
                iVar5 = (int)(puVar1[5] + (uint32_t)param_3);
                uint32_t uVar3 = *(uint32_t*)(iVar5 + 8);
                if (*(int*)(iVar5 + 0xc) != 0) {
                    FUN_00576320(0, uVar3, *(uint32_t*)(iVar5 + 0xc),
                                 *(uint32_t*)(iVar5 + 4), param_1, param_2,
                                 &uStack_8, &uStack_c);
                    FUN_00575bb0(uStack_8, uStack_c, uVar3);
                }
                uVar6 = uVar6 + 1;
                param_3 = param_3 + 0x14;
            } while (uVar6 < puVar1[3]);
            iVar5 = iStack_4;
        }
    }
    piVar4 = (int*)(puVar1 + 1);
    *piVar4 = *piVar4 - 1;
    if (*piVar4 == 0) {
        code_fn vt = *(code_fn*)*puVar1;
        ((void(*)(int))vt)(1);
    }
    return iVar5;
}

// 0x5812c0 — observed shape: FUN_00552b90(param_1) gate returning 0 on zero;
// otherwise walk the +0x50 count of the +0x48 array and invoke each non-null
// element's virtual +0x14 with param_1; return 1.
uint8_t FUN_005812c0_recon(void* self, uint32_t param_1)
{
    int cVar3 = FUN_00552b90(param_1);
    if (cVar3 == 0) {
        return 0;
    }
    uint32_t uVar1 = *(uint32_t*)((char*)self + 0x50);
    uint32_t uVar4 = 0;
    if (uVar1 != 0) {
        do {
            int* piVar2 = *(int**)(*(int*)((char*)self + 0x48) + uVar4 * 4);
            if (piVar2 != nullptr) {
                void (*vt)(uint32_t) = (void (*)(uint32_t))(uintptr_t)(*piVar2 + 0x14);
                vt(param_1);
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
    }
    return 1;
}

// 0x581300 — observed shape: bounds-check param_1 against +0x8; when
// param_1 < +0xc compare the existing +0x4 element slot against *param_2 and
// adjust the +0x10 count (-1 when the slot is non-null and *param_2 is null,
// +1 when the slot is null and *param_2 is non-null); otherwise grow +0xc to
// param_1+1 and, when *param_2 is non-null, +0x10. Finally ref-assign the
// element slot (release old, incref new).
void FUN_00581300_recon(void* self, uint32_t param_1, int* param_2)
{
    if (*(uint32_t*)((char*)self + 8) <= param_1) {
        return;
    }
    int iVar4;
    if (param_1 < *(uint32_t*)((char*)self + 0xc)) {
        iVar4 = *(int*)(*(int*)((char*)self + 4) + param_1 * 4);
        if (*param_2 == 0) {
            if (iVar4 == 0) goto lab_00581359;
            iVar4 = *(int*)((char*)self + 0x10) - 1;
        } else {
            if (iVar4 != 0) goto lab_00581359;
            iVar4 = *(int*)((char*)self + 0x10) + 1;
        }
    } else {
        *(uint32_t*)((char*)self + 0xc) = param_1 + 1;
        if (*param_2 == 0) goto lab_00581359;
        iVar4 = *(int*)((char*)self + 0x10) + 1;
    }
    *(int*)((char*)self + 0x10) = iVar4;
lab_00581359:
    int* piVar2 = (int*)(*(int*)((char*)self + 4) + param_1 * 4);
    uint32_t* puVar3 = (uint32_t*)(uintptr_t)(uint32_t)*piVar2;
    if (puVar3 != (uint32_t*)(uintptr_t)(uint32_t)*param_2) {
        if (puVar3 != nullptr) {
            int* piVar1 = (int*)(puVar3 + 1);
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                code_fn vt = *(code_fn*)*puVar3;
                ((void(*)(int))vt)(1);
            }
        }
        int iVar4b = *param_2;
        *piVar2 = iVar4b;
        if (iVar4b != 0) {
            *(int*)(iVar4b + 4) = *(int*)(iVar4b + 4) + 1;
        }
    }
}

// 0x581390 — observed shape: dtor-style; vptr = PTR_FUN_006c4d90, release each
// element of the +0x4 array (count stored at array-4) from the end backwards,
// then operator_delete__ the array header at array-4.
void FUN_00581390_recon(void* self)
{
    uint32_t* q = (uint32_t*)self;
    q[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4d90;
    int iVar2 = (int)q[1];
    if (iVar2 != 0) {
        int iVar4 = *(int*)(iVar2 - 4);
        int iVar5 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 - 1) {
            do {
                uint32_t* puVar3 = *(uint32_t**)(iVar5 - 4);
                iVar5 = iVar5 - 4;
                if (puVar3 != nullptr) {
                    int* piVar1 = (int*)(puVar3 + 1);
                    *piVar1 = *piVar1 - 1;
                    if (*piVar1 == 0) {
                        code_fn vt = *(code_fn*)*puVar3;
                        ((void(*)(int))vt)(1);
                    }
                }
                iVar4 = iVar4 - 1;
            } while (iVar4 != 0);
        }
        operator_delete__((void*)(intptr_t)(iVar2 - 4));
    }
}

// 0x5813e0 — observed shape: calls the 0x581390 destructor body with self and
// conditional operator_delete on param_1 bit 0.
void FUN_005813e0_recon(void* self, uint8_t param_1)
{
    FUN_00581390(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x581500 — observed shape: FUN_005530e0 on self, then through the writer
// vtable at param_1[0x58]+0xc writes 4 bytes at self+0x60, 4 bytes at
// self+0x64, 4 bytes at self+0x6c and the +0x50 dword; then emits each of the
// +0x48 array entries through param_1's virtual +0x2c. The listing reuses the
// register holding the self+0x64 buffer address as the loop bound, preserved
// literally below.
void FUN_00581500_recon(void* self, int* param_1)
{
    FUN_005530e0(self);
    void (*writer)(void*, uint32_t) =
        (void (*)(void*, uint32_t))(uintptr_t)(*(int*)param_1[0x58] + 0xc);
    writer((void*)((char*)self + 0x60), 4);
    uint32_t uVar2 = (uint32_t)(uintptr_t)((char*)self + 100);
    writer((void*)(uintptr_t)uVar2, 4);
    writer((void*)((char*)self + 0x6c), 4);
    uint32_t iStack_14 = *(uint32_t*)((char*)self + 0x50);
    writer(&iStack_14, 4);
    uint32_t uVar1 = 0;
    if (uVar2 != 0) {
        do {
            void (*visit)(void*, uint32_t) =
                (void (*)(void*, uint32_t))(uintptr_t)(*param_1 + 0x2c);
            uint32_t arg = *(uint32_t*)(*(int*)((char*)self + 0x48) + uVar1 * 4);
            visit(param_1, arg);
            uVar1 = uVar1 + 1;
        } while (uVar1 < uVar2);
    }
}
