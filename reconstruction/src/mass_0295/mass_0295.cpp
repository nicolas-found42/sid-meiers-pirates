// Reconstruction batch mass_0295
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Derived from Ghidra 12.2 pseudocode; candidate reconstruction, not original source.

#include <cstdint>
#include <cstddef>
#include <new>
#include <windows.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int16_t  s16;
typedef int32_t  s32;

static inline void operator_delete(void* p) { ::operator delete(p); }

extern "C" {
int   FUN_005f7bc9(u32 handle, void* out, u32* pcb);
int   FUN_005f7ad0(u32 handle, u32 tag, void** out, u32* pcb);
void* FUN_00533c78(u32 size);
int   FUN_006294f9(u32 cb, int** slot);
void  FUN_005f8ea2(int enable);
void  FUN_00646ae9(void* self);
int   ftol();
}

extern int32_t DAT_006ea4b8[];
extern const u32 DAT_006dd2a4[4];
extern const u32 DAT_006f5200[4];

// 0x63da83 — observed shape
u32 FUN_0063da83(void* self, u32 param_1, u32 param_2, u32 param_3)
{
    int32_t* piVar8 = (int32_t*)((uintptr_t)param_1 * 100 + *(int32_t*)((u8*)self + 0x2c));
    s16 sVar5 = (s16)param_2;

    if (-1 < (s32)((u32)*(u16*)(piVar8 + 0xf) + (s32)sVar5)) {
        *(u16*)(piVar8 + 0xf) = *(u16*)(piVar8 + 0xf) + sVar5;
    }
    s16 sVar6 = (s16)param_3;
    if (-1 < (s32)((u32)*(u16*)((u8*)piVar8 + 0x3a) + (s32)sVar6)) {
        *(u16*)((u8*)piVar8 + 0x3a) = *(u16*)((u8*)piVar8 + 0x3a) + sVar6;
    }

    int32_t iVar1 = piVar8[5];
    int32_t iVar2 = *piVar8;
    param_1 = 0;
    if ((s16)piVar8[0xd] != 0) {
        do {
            int32_t iVar4 = (u32)*(u16*)(uintptr_t)(iVar1 + iVar2 + (int32_t)param_1 * 2) * 100 + piVar8[1];
            u16* puVar9 = (u16*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x48) + *piVar8);
            if (*puVar9 != 0) {
                u32 uVar3 = *(u32*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0xc) + 0x10);
                u32 local_8 = 0;
                while (true) {
                    u32 uVar7 = uVar3;
                    if (uVar3 == 0) {
                        uVar7 = 1;
                    }
                    if (uVar7 <= (local_8 & 0xffff)) break;
                    if (sVar6 != 0) {
                        FUN_0063da83(self, (*puVar9 - 1) + (local_8 & 0xffff), 0, param_3);
                    }
                    local_8 = local_8 + 1;
                }
                if (sVar5 != 0) {
                    FUN_0063da83(self, (puVar9[1] - 1) + (u32)*puVar9, param_2, 0);
                }
            }
            param_1 = param_1 + 1;
        } while (param_1 < *(u16*)(piVar8 + 0xd));
    }
    return 0;
}

// 0x63db6f — observed shape
int32_t FUN_0063db6f(void* self, u32 param_1)
{
    s32 iVar2;
    u32 uVar3;
    // Flattened stack frame: local_418 at frame+0, auStack_414 at frame+4.
    u8 frame[0x620] = {};
    u8* const local_418  = frame;
    u8* const auStack_414 = frame + 4;
    int32_t* local_8 = nullptr;

    if (param_1 == 0) {
        int32_t* piVar1 = (int32_t*)((u8*)self + 0x100);
        if (*piVar1 != 0) {
            uintptr_t obj = (uintptr_t)(u32)*piVar1;
            (*(void (**)(uintptr_t))(*(uintptr_t*)obj + 4))(obj);
        }
        local_8 = (int32_t*)*piVar1;
    }
    else {
        iVar2 = FUN_005f7bc9(param_1, local_418, &param_1);
        if (iVar2 < 0) goto LAB_0063dc61;
        if (0x40 < param_1) {
            iVar2 = -0x7fffbffb;
            goto LAB_0063dc61;
        }
        uVar3 = 0;
        if (param_1 != 0) {
            do {
                s32 iVar = (s32)(uVar3 * 8);
                *(u16*)(auStack_414 + iVar + 0x204) = 0;
                *(s16*)(auStack_414 + iVar + 0x206) = (s16)uVar3 * 0xc;
                auStack_414[iVar + 0x208] = 2;
                auStack_414[iVar + 0x209] = 0;
                auStack_414[iVar + 0x20a] = local_418[iVar];
                uVar3 = uVar3 + 1;
                auStack_414[iVar + 0x20b] = auStack_414[iVar];
            } while (uVar3 < param_1);
        }
        *(u32*)(auStack_414 + uVar3 * 8 + 0x204) = 0xff;
        *(u32*)(auStack_414 + uVar3 * 8 + 0x208) = 0x11;
        {
            void* comObj = *(void**)((u8*)self + 0xc);
            iVar2 = (*(s32 (**)(void*, void*, int32_t**))(*(uintptr_t*)comObj + 0x158))(
                comObj, auStack_414 + 0x204, &local_8);
        }
        if (iVar2 < 0) goto LAB_0063dc61;
    }
    {
        void* comObj = *(void**)((u8*)self + 0xc);
        iVar2 = (*(s32 (**)(void*, int32_t*))(*(uintptr_t*)comObj + 0x15c))(comObj, local_8);
    }
LAB_0063dc61:
    if (local_8 != nullptr) {
        (*(void (**)(int32_t*))(*(int32_t*)local_8 + 8))(local_8);
    }
    return iVar2;
}

// 0x63dc77 — observed shape
int32_t FUN_0063dc77(u8** param_1, u32 param_2)
{
    u8** piVar3 = param_1;
    u8* iVar4 = *param_1;
    s32 iVar5 = *(s32*)(iVar4 + 0x10);
    s32 iVar1 = *(s32*)(iVar4 + 4);

    if (iVar5 == 0) {
        iVar5 = 1;
    }
    if (-1 < iVar1) {
        if (iVar1 < 4) {
            u32 uVar2 = *(u32*)(iVar4 + 0x14);
            s32 iVar6 = *(s32*)(iVar4 + 0x18);
            *param_1 = iVar4 + 0x1c;
            return (s32)(((u32)(uVar2 % param_2 != 0) + uVar2 / param_2) * (u32)iVar6 * (u32)iVar5);
        }
        if ((iVar1 != 4) && (iVar1 == 5)) {
            s32 iVarCount = *(s32*)(iVar4 + 0x14);
            s32 iVar6 = 0;
            *param_1 = iVar4 + 0x18;
            if (iVarCount != 0) {
                s32 n = iVarCount;
                do {
                    s32 iVar = FUN_0063dc77(piVar3, param_2);
                    iVar6 = iVar6 + iVar;
                    n = n - 1;
                } while (n != 0);
            }
            return iVar6 * iVar5;
        }
    }
    return 0;
}

// 0x63dcf6 — observed shape
u32 FUN_0063dcf6(u8** param_1)
{
    u8* iVar3 = *param_1;
    s32 iVar1 = *(s32*)(iVar3 + 4);
    u32 uVar4;

    if (iVar1 < 0) {
        return 0;
    }
    if (iVar1 < 2) {
        *param_1 = iVar3 + 0x1c;
        return 1;
    }
    if (((iVar1 < 4) || (iVar1 == 4)) || (iVar1 != 5)) {
        return 0;
    }
    {
        u32 uVar2 = *(u32*)(iVar3 + 0x14);
        u32 uVar5 = 0;
        *param_1 = iVar3 + 0x18;
        if (uVar2 != 0) {
            do {
                if (FUN_0063dcf6(param_1) == 0) return 0;
                uVar5 = uVar5 + 1;
            } while (uVar5 < uVar2);
        }
    }
    return 1;
}

// 0x63dd50 — observed shape
// NEEDS_MANUAL: the provider elided the source operand of both ftol() conversions in the
// type-1 and type-2 copy loops; the surrounding stride and offset arithmetic is preserved.
int32_t FUN_0063dd50(u8** param_1, int32_t* param_2, int32_t* param_3, u32* param_4)
{
    u32* puVar6 = param_4;
    int32_t* piVar5 = param_3;
    int32_t* piVar1 = (int32_t*)*param_1;
    s32 iVar9 = piVar1[1];
    u32 local_c = (u32)piVar1[4];
    s32 local_14 = 0;

    if (local_c == 0) {
        local_c = 1;
    }
    if (-1 < iVar9) {
        if (iVar9 < 4) {
            u32 uVar2 = (u32)piVar1[5];
            u32 uVar3 = (u32)piVar1[6];
            s32 iVarType = *piVar1;
            u32 uVar11 = (uVar2 >> 2) + (u32)((uVar2 & 3) != 0);
            u32 local_10 = uVar11;
            u32 local_8 = uVar2;
            u32 local_28, local_1c, local_18, uVar7, uVar4, uVar12;

            if (iVarType == 1) {
                local_18 = 0;
                uVar12 = uVar11;
                if (local_c != 0) {
                    do {
                        uVar7 = 0;
                        if (*param_4 == 0) break;
                        if (uVar3 != 0) {
                            do {
                                uVar4 = *param_4;
                                if (uVar4 == 0) break;
                                if (uVar4 < uVar11) {
                                    local_8 = uVar4 << 2;
                                    local_10 = uVar4;
                                }
                                if (local_8 != 0) {
                                    local_1c = uVar7 << 2;
                                    local_28 = local_8;
                                    do {
                                        u32 uVar8 = (u32)ftol();
                                        *(u32*)(uintptr_t)(local_1c + (u32)*param_2) = uVar8;
                                        local_1c = local_1c + uVar3 * 4;
                                        local_28 = local_28 - 1;
                                    } while (local_28 != 0);
                                }
                                *param_4 = *param_4 - local_10;
                                uVar7 = uVar7 + 1;
                                uVar12 = local_10;
                            } while (uVar7 < uVar3);
                        }
                        *param_3 = *param_3 + (int32_t)(uVar7 * uVar12 * 8);
                        *param_2 = *param_2 + (int32_t)(uVar3 * uVar2 * 4);
                        local_18 = local_18 + 1;
                    } while (local_18 < local_c);
                }
            }
            else if (iVarType == 2) {
                local_1c = 0;
                uVar12 = uVar11;
                if (local_c != 0) {
                    do {
                        uVar7 = 0;
                        if (*param_4 == 0) break;
                        if (uVar3 != 0) {
                            do {
                                uVar4 = *param_4;
                                if (uVar4 == 0) break;
                                if (uVar4 < uVar11) {
                                    local_8 = uVar4 << 2;
                                    local_10 = uVar4;
                                }
                                if (local_8 != 0) {
                                    local_18 = uVar7 << 2;
                                    local_28 = local_8;
                                    do {
                                        u32 uVar8 = (u32)ftol();
                                        *(u32*)(uintptr_t)(local_18 + (u32)*param_2) = uVar8;
                                        local_18 = local_18 + uVar3 * 4;
                                        local_28 = local_28 - 1;
                                    } while (local_28 != 0);
                                }
                                *param_4 = *param_4 - local_10;
                                uVar7 = uVar7 + 1;
                                uVar12 = local_10;
                            } while (uVar7 < uVar3);
                        }
                        *param_3 = *param_3 + (int32_t)(uVar7 * uVar12 * 8);
                        *param_2 = *param_2 + (int32_t)(uVar3 * uVar2 * 4);
                        local_1c = local_1c + 1;
                    } while (local_1c < local_c);
                }
            }
            else {
                if (iVarType != 3) {
                    return -0x7fffbffb;
                }
                local_18 = 0;
                if (local_c != 0) {
                    uVar12 = uVar11;
                    do {
                        uVar7 = 0;
                        if (*param_4 == 0) break;
                        if (uVar3 != 0) {
                            do {
                                uVar4 = *param_4;
                                if (uVar4 == 0) break;
                                if (uVar4 < uVar11) {
                                    local_8 = uVar4 << 2;
                                    local_10 = uVar4;
                                }
                                if (local_8 != 0) {
                                    u32 iDst = uVar7 << 2;
                                    u32 iSrc = uVar7 << 3;
                                    u32 nCopy = local_8;
                                    do {
                                        *(float*)(uintptr_t)(iDst + (u32)*param_2) =
                                            (float)*(double*)(uintptr_t)(iSrc + (u32)*piVar5);
                                        iSrc = iSrc + uVar3 * 8;
                                        iDst = iDst + uVar3 * 4;
                                        nCopy = nCopy - 1;
                                    } while (nCopy != 0);
                                }
                                *param_4 = *param_4 - local_10;
                                uVar7 = uVar7 + 1;
                                uVar12 = local_10;
                            } while (uVar7 < uVar3);
                        }
                        *piVar5 = *piVar5 + (int32_t)(uVar7 * uVar12 * 8);
                        *param_2 = *param_2 + (int32_t)(uVar3 * uVar2 * 4);
                        local_18 = local_18 + 1;
                    } while (local_18 < local_c);
                }
            }
            *param_1 = (u8*)(piVar1 + 7);
            return 0;
        }
        if (iVar9 == 5) {
            u32 local_10 = 0;
            u32 uVar2 = (u32)piVar1[5];
            *param_1 = (u8*)(piVar1 + 6);
            if (local_c == 0) {
                return 0;
            }
            do {
                if (*puVar6 == 0) {
                    return local_14;
                }
                u32 n = 0;
                *param_1 = (u8*)(piVar1 + 6);
                if (uVar2 != 0) {
                    do {
                        if (*puVar6 == 0) break;
                        local_14 = FUN_0063dd50(param_1, param_2, param_3, puVar6);
                        if (local_14 < 0) {
                            return local_14;
                        }
                        n = n + 1;
                    } while (n < uVar2);
                }
                local_10 = local_10 + 1;
                if (local_c <= local_10) {
                    return local_14;
                }
            } while (true);
        }
    }
    return -0x7fffbffb;
}

// 0x63e055 — observed shape
u32 FUN_0063e055(u32 param_1, int32_t* param_2, s16* param_3, u16* param_4, u16* param_5)
{
    u16* puVar4 = param_5;
    u16* puVar3 = param_4;
    s16* psVar2 = param_3;
    u32 local_8 = 0;

    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_4[0] = 0xffff;
    param_4[1] = 0xffff;
    param_4[2] = 0xffff;
    param_4[3] = 0xffff;
    param_5[0] = 0;
    param_5[1] = 0;
    param_5[2] = 0;
    param_5[3] = 0;
    *param_2 = 0;

    if (param_1 != 0) {
        u8* table = nullptr;
        u32 size = param_1;
        int32_t iVar5 = FUN_005f7ad0(param_1, 0x42415443, (void**)&table, &size);
        if (iVar5 < 0) {
            return 0;
        }
        if (table != nullptr) {
            bool bad = false;
            if ((size < 0x1c) || (size < *(u32*)(table + 0xc) * 4u + 0x1cU)) {
                bad = true;
            }
            else {
                u32 count = 0;
                u32* puVar6 = (u32*)(uintptr_t)(*(u32*)(table + 0x10) + (uintptr_t)table);
                if (*(s32*)(table + 0xc) != 0) {
                    do {
                        s32 len = 0;
                        for (u32 uVar8 = *puVar6;
                             (uVar8 < size && (*(char*)(uintptr_t)(uVar8 + (uintptr_t)table) != '\0'));
                             uVar8 = uVar8 + 1) {
                            len = len + 1;
                        }
                        if (size <= *puVar6 + (u32)len) {
                            bad = true;
                            break;
                        }
                        s16 sVar1 = (s16)puVar6[1];
                        s32 elemSize;
                        if (sVar1 == 0) {
                            psVar2[1] = psVar2[1] + (s16)puVar6[2];
                            u16 uVar7 = puVar4[1];
                            elemSize = 4;
                            if ((u32)uVar7 <= (u32)(u16)puVar6[2] + (u32)*(u16*)((u8*)puVar6 + 6)) {
                                uVar7 = (u16)((s16)puVar6[2] + *(s16*)((u8*)puVar6 + 6));
                            }
                            puVar4[1] = uVar7;
                            uVar7 = puVar3[1];
                            if (*(u16*)((u8*)puVar6 + 6) <= puVar3[1]) {
                                uVar7 = *(u16*)((u8*)puVar6 + 6);
                            }
                            puVar3[1] = uVar7;
                        }
                        else if (sVar1 == 1) {
                            psVar2[2] = psVar2[2] + (s16)puVar6[2];
                            u16 uVar7 = puVar4[2];
                            elemSize = 0x10;
                            if ((u32)uVar7 <= (u32)(u16)puVar6[2] + (u32)*(u16*)((u8*)puVar6 + 6)) {
                                uVar7 = (u16)((s16)puVar6[2] + *(s16*)((u8*)puVar6 + 6));
                            }
                            puVar4[2] = uVar7;
                            uVar7 = puVar3[2];
                            if (*(u16*)((u8*)puVar6 + 6) <= puVar3[2]) {
                                uVar7 = *(u16*)((u8*)puVar6 + 6);
                            }
                            puVar3[2] = uVar7;
                        }
                        else if (sVar1 == 2) {
                            *psVar2 = *psVar2 + (s16)puVar6[2];
                            u16 uVar7 = *puVar4;
                            elemSize = 0x10;
                            if ((u32)uVar7 <= (u32)(u16)puVar6[2] + (u32)*(u16*)((u8*)puVar6 + 6)) {
                                uVar7 = (u16)((s16)puVar6[2] + *(s16*)((u8*)puVar6 + 6));
                            }
                            *puVar4 = uVar7;
                            uVar7 = *puVar3;
                            if (*(u16*)((u8*)puVar6 + 6) <= *puVar3) {
                                uVar7 = *(u16*)((u8*)puVar6 + 6);
                            }
                            *puVar3 = uVar7;
                        }
                        else {
                            if (sVar1 != 3) {
                                bad = true;
                                break;
                            }
                            psVar2[3] = psVar2[3] + (s16)puVar6[2];
                            elemSize = 0;
                            u16 uVar7 = puVar4[3];
                            if ((u32)uVar7 <= (u32)(u16)puVar6[2] + (u32)*(u16*)((u8*)puVar6 + 6)) {
                                uVar7 = (u16)((s16)puVar6[2] + *(s16*)((u8*)puVar6 + 6));
                            }
                            puVar4[3] = uVar7;
                            uVar7 = puVar3[3];
                            if (*(u16*)((u8*)puVar6 + 6) <= puVar3[3]) {
                                uVar7 = *(u16*)((u8*)puVar6 + 6);
                            }
                            puVar3[3] = uVar7;
                        }
                        iVar5 = (s32)((u32)(u16)puVar6[2] * (u32)elemSize);
                        if ((iVar5 != 0) && (size <= puVar6[4] + (u32)iVar5)) {
                            bad = true;
                            break;
                        }
                        count = count + 1;
                        puVar6 = puVar6 + 5;
                    } while (count < *(u32*)(table + 0xc));
                }
            }
            if (bad) {
                local_8 = 0x80004005;
            }
            else {
                *param_2 = (int32_t)(intptr_t)table;
            }
        }
    }
    return local_8;
}

// 0x63e2a9 — observed shape
int32_t FUN_0063e2a9(int32_t** param_1, int32_t** param_2)
{
    int32_t iVar1 = DAT_006ea4b8[*(u16*)((u8*)(uintptr_t)*param_1 + 4)] -
                    DAT_006ea4b8[*(u16*)((u8*)(uintptr_t)*param_2 + 4)];
    if (iVar1 == 0) {
        iVar1 = (int32_t)((u32)*(u16*)((u8*)(uintptr_t)*param_1 + 6) -
                          (u32)*(u16*)((u8*)(uintptr_t)*param_2 + 6));
    }
    return iVar1;
}

// 0x63e306 — observed shape
void FUN_0063e306(void* self, u8 param_1)
{
    FUN_00646ae9(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x63e327 — observed shape
void FUN_0063e327(void* self)
{
    u32* p = (u32*)self;

    p[2] = p[2] & 0xffffffe0;
    *(u16*)((u8*)p + 0x3e) = 0xffff;
    p[0] = 0;
    p[3] = 0;
    p[4] = 0;
    p[1] = 0;
    *(u16*)(p + 0xd) = 0;
    *(u16*)((u8*)p + 0x36) = 0;
    *(u16*)(p + 0xe) = 0;
    *(u16*)(p + 0xf) = 0;
    *(u16*)((u8*)p + 0x3a) = 0;

    u8* puVar3 = (u8*)(p + 0xb);
    u32* puVar4 = p + 7;
    u32* puVar1 = p + 6;
    s32 local_8 = 2;
    do {
        *(u16*)puVar1 = 0xffff;
        u32 uVar2 = 0;
        do {
            *(u8*)(puVar3 + uVar2) = 0;
            *(u16*)puVar4 = 0;
            uVar2 = uVar2 + 1;
            puVar4 = (u32*)((u8*)puVar4 + 2);
        } while (uVar2 < 4);
        puVar1 = (u32*)((u8*)puVar1 + 2);
        puVar3 = puVar3 + 4;
        local_8 = local_8 - 1;
    } while (local_8 != 0);
}

// 0x63e391 — observed shape
u32 FUN_0063e391(void* self)
{
    u32* p = (u32*)self;
    s32 iVar2 = (s32)((p[3] & 1U) + (p[3] & 0xfffffffeU));
    p[5] = (u32)iVar2;
    u32 uVar1 = (u32)iVar2 + (u32)*(u16*)((u8*)p + 0x34) * 2u;
    u32 uVar3 = 0;

    p[3] = uVar1;
    if (p[4] < uVar1) {
        void* pv = FUN_00533c78(uVar1);
        if (pv == nullptr) {
            uVar3 = 0x8007000e;
        }
        else {
            if ((void*)(uintptr_t)p[0] != nullptr) {
                operator_delete((void*)(uintptr_t)p[0]);
                p[0] = 0;
            }
            p[0] = (u32)(uintptr_t)pv;
            p[4] = p[3];
        }
    }
    return uVar3;
}

// 0x63e40b — observed shape
void FUN_0063e40b(void* self)
{
    u32* p = (u32*)self;
    int32_t* piVar1 = (int32_t*)(uintptr_t)p[1];

    if ((piVar1 != nullptr) &&
        ((p[0] == 4) || ((4 < p[0]) && (((p[0] < 10) || (p[0] == 0xf)) || (p[0] == 0x10))))) {
        (*(void (**)(int32_t*))(*(int32_t*)piVar1 + 8))(piVar1);
        p[1] = 0;
    }
    piVar1 = (int32_t*)(uintptr_t)p[2];
    if (piVar1 != nullptr) {
        (*(void (**)(int32_t*))(*(int32_t*)piVar1 + 8))(piVar1);
        p[2] = 0;
    }
}

// 0x63e44e — observed shape
void FUN_0063e44e(void* self)
{
    u8* base = (u8*)self;
    u32 uVar1 = 0;

    if (*(s32*)(base + 0xb4) != 0) {
        if (*(s32*)(base + 0xa0) != 0) {
            do {
                u32 uVar2 = 0;
                *(u32*)(base + 0xb8) = (u32)(*(s32*)(base + 0xb4) +
                                             *(s32*)(base + 0xac) * (s32)uVar1 * 4);
                if (*(s32*)(base + 0xac) != 0) {
                    do {
                        operator_delete(*(void**)(uintptr_t)(*(u32*)(base + 0xb8) + uVar2 * 4));
                        uVar2 = uVar2 + 1;
                    } while (uVar2 < *(u32*)(base + 0xac));
                }
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(u32*)(base + 0xa0));
        }
        operator_delete(*(void**)(base + 0xb4));
        *(u32*)(base + 0xb4) = 0;
    }

    uVar1 = 0;
    if (*(s32*)(base + 0xc0) != 0) {
        if (*(s32*)(base + 0xa0) != 0) {
            do {
                u32 uVar2 = 0;
                *(u32*)(base + 0xb8) = (u32)(*(s32*)(base + 0xc0) +
                                             *(s32*)(base + 0xac) * (s32)uVar1 * 4);
                if (*(s32*)(base + 0xac) != 0) {
                    do {
                        operator_delete(*(void**)(uintptr_t)(*(u32*)(base + 0xb8) + uVar2 * 4));
                        uVar2 = uVar2 + 1;
                    } while (uVar2 < *(u32*)(base + 0xac));
                }
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(u32*)(base + 0xa0));
        }
        operator_delete(*(void**)(base + 0xc0));
        *(u32*)(base + 0xc0) = 0;
    }
}

// 0x63e536 — observed shape
u32 FUN_0063e536(int32_t* param_1, u32* param_2, u32* param_3)
{
    u32 uVar2 = 0;
    s32 iVar1;
    bool bVar5;
    u32* piVar3;

    if (param_3 == nullptr) {
        return 0x80004005;
    }

    iVar1 = 4;
    bVar5 = true;
    piVar3 = param_2;
    const u32* piVar4 = DAT_006dd2a4;
    do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 - 1;
        bVar5 = *piVar3 == *piVar4;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
    } while (bVar5);

    if (!bVar5) {
        iVar1 = 4;
        bVar5 = true;
        piVar3 = param_2;
        const u32* piVarOther = DAT_006f5200;
        do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 - 1;
            bVar5 = *piVar3 == *piVarOther;
            piVar3 = piVar3 + 1;
            piVarOther = piVarOther + 1;
        } while (bVar5);
        if (!bVar5) {
            return 0x80004002;
        }
    }
    *param_3 = (u32)(uintptr_t)param_1;
    (*(void (**)(int32_t*))(*(int32_t*)param_1 + 4))(param_1);
    return uVar2;
}

// 0x63e58b — observed shape
u32 FUN_0063e58b(void* self)
{
    u8* base = (u8*)self;
    u32 uVar2 = 0;

    operator_delete(*(void**)(base + 0x108));
    void* pv = FUN_00533c78(0x400);
    *(void**)(base + 0x108) = pv;
    if (pv == nullptr) {
        uVar2 = 0x8007000e;
    }
    else {
        *(u32*)(base + 0x10c) = 0;
        *(u32*)(base + 0x110) = 0x100;
        uVar2 = 0;
    }
    return uVar2;
}

// 0x63e5ce — observed shape
void FUN_0063e5ce(void* self, u8* param_1)
{
    u8* base = (u8*)self;

    FUN_005f8ea2(1);
    if ((*(u8*)(base + 0x119) & 2) == 0) {
        s32 iVar2 = *(s32*)*(int32_t**)(base + 0xc);
        u32 uVar1 = (*(u32 (**)(void*, u8*))(*(int32_t*)*(int32_t**)(param_1 + 8) + 0xc))(
            *(void**)(param_1 + 8), param_1 + 4);
        iVar2 = (*(s32 (**)(void*, u32))(*(int32_t*)*(int32_t**)(base + 0xc) + 0x16c))(
            *(void**)(base + 0xc), uVar1);
        if (iVar2 < 0) {
            FUN_005f8ea2(0);
            *(u32*)(param_1 + 4) = 0;
            *(u32*)(param_1 + 0x14) = *(u32*)(param_1 + 0x14) & 0xfffffffc;
        }
        else {
            FUN_005f8ea2(0);
            *(u32*)(param_1 + 0x14) = *(u32*)(param_1 + 0x14) | 3;
        }
    }
}

// 0x63e62c — observed shape
void FUN_0063e62c(void* self, u8* param_1)
{
    u8* base = (u8*)self;

    FUN_005f8ea2(1);
    if ((*(u8*)(base + 0x119) & 2) == 0) {
        s32 iVar2 = *(s32*)*(int32_t**)(base + 0xc);
        u32 uVar1 = (*(u32 (**)(void*, u8*))(*(int32_t*)*(int32_t**)(param_1 + 8) + 0xc))(
            *(void**)(param_1 + 8), param_1 + 4);
        iVar2 = (*(s32 (**)(void*, u32))(*(int32_t*)*(int32_t**)(base + 0xc) + 0x1a8))(
            *(void**)(base + 0xc), uVar1);
        if (iVar2 < 0) {
            FUN_005f8ea2(0);
            *(u32*)(param_1 + 4) = 0;
            *(u32*)(param_1 + 0x14) = *(u32*)(param_1 + 0x14) & 0xfffffffc;
        }
        else {
            FUN_005f8ea2(0);
            *(u32*)(param_1 + 0x14) = *(u32*)(param_1 + 0x14) | 3;
        }
    }
}

// 0x63e68a — observed shape
int32_t FUN_0063e68a(void* self, int32_t* param_1, u32* param_2)
{
    u8* base = (u8*)self;
    u32* puVar4 = param_2;
    u32 n = 0;
    u32 local_10 = 0;
    u32 uVar5 = 0;
    u32* puVar7 = nullptr;
    int32_t result = 0;
    s32 iVar6 = 0;
    s32 iVarCount = 0;
    int32_t* piVar3 = nullptr;
    int32_t* piVar1 = nullptr;
    int32_t* piVar2 = nullptr;
    u32 uVarCopy = 0;
    u32 uVarTail = 0;

    if (param_1 != nullptr) {
        uVar5 = (*(u32 (**)(int32_t*))(*(int32_t*)param_1 + 0x10))(param_1);
        if (*param_2 + 1 <= uVar5) {
            iVar6 = (*(s32 (**)(int32_t*))(*(int32_t*)param_1 + 0xc))(param_1);
            local_10 = *(u32*)((u8*)(uintptr_t)iVar6 + *param_2 * 4);
        }
    }
    *param_2 = *param_2 + 1;
    if (param_1 != nullptr) {
        uVar5 = (*(u32 (**)(int32_t*))(*(int32_t*)param_1 + 0x10))(param_1);
        if (*param_2 + 1 <= uVar5) {
            iVar6 = (*(s32 (**)(int32_t*))(*(int32_t*)param_1 + 0xc))(param_1);
            n = *(u32*)((u8*)(uintptr_t)iVar6 + *param_2 * 4);
        }
    }
    *puVar4 = *puVar4 + 1;

    if (param_1 == nullptr) {
        return -0x7fffbffb;
    }
    uVar5 = (*(u32 (**)(int32_t*))(*(int32_t*)param_1 + 0x10))(param_1);
    if ((uVar5 < *puVar4) || (*(u32*)(base + 0x14) <= local_10)) {
        return -0x7fffbffb;
    }

    puVar7 = (u32*)FUN_00533c78(n);
    if (puVar7 == nullptr) {
        return 0x8007000e;
    }

    uVarCopy = (u32)((((n & 3) != 0) ? 1 : 0) + (n >> 2));
    uVar5 = (*(u32 (**)(int32_t*))(*(int32_t*)param_1 + 0x10))(param_1);
    if (*puVar4 + uVarCopy <= uVar5) {
        iVar6 = (*(s32 (**)(int32_t*))(*(int32_t*)param_1 + 0xc))(param_1);
        u32* src = (u32*)((u8*)(uintptr_t)iVar6 + *puVar4 * 4);
        u32* dst = puVar7;
        for (u32 k = n >> 2; k != 0; k = k - 1) {
            *dst = *src;
            src = src + 1;
            dst = dst + 1;
        }
        u8* s8 = (u8*)src;
        u8* d8 = (u8*)dst;
        for (u32 k = n & 3; k != 0; k = k - 1) {
            *d8 = *s8;
            s8 = s8 + 1;
            d8 = d8 + 1;
        }
    }
    *puVar4 = *puVar4 + uVarCopy;

    uVar5 = (*(u32 (**)(int32_t*))(*(int32_t*)param_1 + 0x10))(param_1);
    if (*puVar4 <= uVar5) {
        result = 0;
        piVar3 = (int32_t*)(uintptr_t)(*(s32*)(base + 0x18) + (s32)local_10 * 0x18);
        piVar1 = piVar3 + 1;
        piVar2 = piVar3 + 2;
        if ((*piVar1 == 0) && (*piVar2 == 0)) {
            if (n == 0) goto LAB_0063e8a3;
            iVarCount = *piVar3;
            if (iVarCount == 4) {
                if (*((u8*)puVar7 + (n - 1)) == '\0') {
                    result = FUN_006294f9(n, piVar1);
                    if (-1 < result) {
                        u8* dstBuf = (u8*)(uintptr_t)
                            (*(u32 (**)(int32_t*))(*(int32_t*)*piVar1 + 0xc))((int32_t*)*piVar1);
                        const u8* srcBuf = (const u8*)puVar7;
                        for (u32 k = n >> 2; k != 0; k = k - 1) {
                            *(u32*)dstBuf = *(const u32*)srcBuf;
                            srcBuf = srcBuf + 4;
                            dstBuf = dstBuf + 4;
                        }
                        for (u32 k = n & 3; k != 0; k = k - 1) {
                            *dstBuf = *srcBuf;
                            srcBuf = srcBuf + 1;
                            dstBuf = dstBuf + 1;
                        }
                    }
                    goto LAB_0063e8a3;
                }
            }
            else if ((0xe < iVarCount) && (iVarCount < 0x11)) {
                result = FUN_006294f9(n, piVar2);
                if (-1 < result) {
                    u8* dstBuf = (u8*)(uintptr_t)
                        (*(u32 (**)(int32_t*))(*(int32_t*)*piVar2 + 0xc))((int32_t*)*piVar2);
                    const u8* srcBuf = (const u8*)puVar7;
                    for (u32 k = n >> 2; k != 0; k = k - 1) {
                        *(u32*)dstBuf = *(const u32*)srcBuf;
                        srcBuf = srcBuf + 4;
                        dstBuf = dstBuf + 4;
                    }
                    for (u32 k = n & 3; k != 0; k = k - 1) {
                        *dstBuf = *srcBuf;
                        srcBuf = srcBuf + 1;
                        dstBuf = dstBuf + 1;
                    }
                    if (*piVar3 == 0x10) {
                        FUN_0063e5ce(self, (u8*)piVar3);
                        *(u16*)(uintptr_t)(*(s32*)(base + 0x2c) +
                                           (u32)*(u16*)((u8*)piVar3 + 0x10) * 100 + 0x18) = 0;
                    }
                    else if (*piVar3 == 0xf) {
                        FUN_0063e62c(self, (u8*)piVar3);
                        *(u16*)(uintptr_t)(*(s32*)(base + 0x2c) +
                                           (u32)*(u16*)((u8*)piVar3 + 0x10) * 100 + 0x1a) = 0;
                    }
                    **(u32**)(uintptr_t)(*(s32*)(base + 0x2c) +
                                        (u32)*(u16*)((u8*)piVar3 + 0x10) * 100 + 4) = 1;
                }
                goto LAB_0063e8a3;
            }
        }
    }
    result = 0x80004005;
LAB_0063e8a3:
    if (puVar7 != nullptr) {
        operator_delete(puVar7);
    }
    return result;
}

// 0x63e8bc — observed shape
u32 FUN_0063e8bc(void* self, s32 param_1)
{
    u8* base = (u8*)self;
    u32 uVar2 = (u32)(-(s32)((u32)(*(s32*)(base + 0x1c) + *(s32*)(base + 0x20)) <
                             (u32)(*(s32*)(base + 0x20) + 4 + param_1))) & 0x80004005u;

    if (-1 < (s32)uVar2) {
        s32 iVar1 = *(s32*)(uintptr_t)(*(s32*)(base + 0x20) + param_1);
        if (iVar1 != 0) {
            uVar2 = (u32)(-(s32)((u32)(*(s32*)(base + 0x20) + *(s32*)(base + 0x1c)) <
                                 (u32)(*(s32*)(base + 0x20) + iVar1 + param_1 + 4))) & 0x80004005u;
            if ((-1 < (s32)uVar2) &&
                (*(char*)(uintptr_t)(*(s32*)(base + 0x20) + iVar1 + -1 + param_1 + 4) != '\0')) {
                uVar2 = 0x80004005;
            }
        }
    }
    return uVar2;
}

// 0x63e918 — observed shape
u32 FUN_0063e918(void* self, s32 param_1)
{
    u8* base = (u8*)self;
    u32 uVar2 = (u32)(-(s32)((u32)(*(s32*)(base + 0x1c) + *(s32*)(base + 0x20)) <
                             (u32)(*(s32*)(base + 0x20) + 4 + param_1))) & 0x80004005u;

    if (-1 < (s32)uVar2) {
        u32* puVar3 = (u32*)(uintptr_t)(param_1 + *(s32*)(base + 0x20));
        if (*puVar3 < 2) {
            uVar2 = 0x80004005;
        }
        else {
            uVar2 = FUN_0063e8bc(self, param_1);
            if (-1 < (s32)uVar2) {
                for (puVar3 = puVar3 + 1; *(char*)puVar3 != '\0'; puVar3 = (u32*)((u8*)puVar3 + 1)) {
                    char cVar1 = *(char*)puVar3;
                    if (((cVar1 == '.') || (cVar1 == '@')) || ((cVar1 == '[') || (cVar1 == ']'))) {
                        uVar2 = 0x80004005;
                        break;
                    }
                }
            }
        }
    }
    return uVar2;
}

// 0x63e97c — observed shape
u32 FUN_0063e97c(void* self, s32 param_1, s32 param_2, s32 param_3, s32 param_4, u32 param_5)
{
    u8* base = (u8*)self;
    s32 iVar3 = param_2 * 100 +
                *(s32*)(uintptr_t)(*(s32*)(base + 0x2c) + param_1 * 100 + 4);
    u32* puVar2 = (u32*)(uintptr_t)(*(s32*)(uintptr_t)(iVar3 + 0x34) + param_3 * 0x20);

    puVar2[4] = param_5;
    puVar2[2] = (u32)iVar3;
    *puVar2 = 1;
    puVar2[3] = (u32)param_4;
    *(s16*)(puVar2 + 5) = (s16)param_1;
    *(s16*)((u8*)puVar2 + 0x16) = (s16)param_2;

    s32 iArray = *(s32*)(base + 0xb0);
    s32 iVar1 = *(s32*)(uintptr_t)(iArray + *(s32*)(uintptr_t)(param_4 + 0x14) * 4);
    if (*(s32*)(uintptr_t)(iVar1 + 0x34) == 0) {
        *(u32**)(uintptr_t)(iVar1 + 0x34) = puVar2;
    }
    else {
        s32 iListHead = *(s32*)(uintptr_t)(iVar1 + 0x34);
        s32 iPrev = *(s32*)(uintptr_t)(iListHead + 0x18);
        puVar2[6] = (u32)iPrev;
        puVar2[7] = (u32)iListHead;
        *(u32**)(uintptr_t)(iPrev + 0x1c) = puVar2;
        *(u32**)(uintptr_t)(iListHead + 0x18) = puVar2;
    }
    if ((*(u8*)(uintptr_t)(iVar1 + 0x28) & 1) != 0) {
        puVar2[1] = 1;
        if ((*(s32*)(uintptr_t)(iVar3 + 0x58) != 0xa000000) &&
            (*(s32*)(uintptr_t)(iVar3 + 0x58) != 0xb000000)) {
            *(u32*)(uintptr_t)(iVar3 + 4) = 1;
        }
    }
    if (((*(u8*)(base + 0x119) & 8) == 0) && (*(s32*)(base + 0xb4) != 0)) {
        FUN_0063e44e(self);
    }
    return 0;
}
