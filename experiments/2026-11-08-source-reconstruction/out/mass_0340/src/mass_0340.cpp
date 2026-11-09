// Reconstruction candidates for batch mass_0340 — Sid Meier's Pirates! (2004), PE32 i386.
// UNVERIFIED: translated by hand from Ghidra 12.2 pseudocode listings; no build was run.
// Corpus: analysis/pseudocode/functions/0x6a4aab.c ... 0x6a5c42.c
// Each provider listing receives a `void* self` for the register receiver in_ECX.
#include <cstdint>
#include <cstddef>
#include <cstdio>

// ---------------------------------------------------------------------------
// External helpers referenced by the translated listings.
// ---------------------------------------------------------------------------
extern int FUN_006a48dd(uint32_t token);
extern int FUN_0069fcf5(void);
extern int FUN_006a2b66(uint32_t value);
extern int FUN_0061273f(char* name, uint32_t id, int flag);
extern uintptr_t FUN_00610ba0(const char* name);
extern void FUN_0065cc6f(int index, void* out);
extern void FUN_006626da(void);

// Address of the receiver's virtual dispatch table (first dword of the object).
static inline uint32_t vtbl(void* self) { return *reinterpret_cast<uint32_t*>(self); }

// ---------------------------------------------------------------------------
// 0x6a4aab — observed shape
// ---------------------------------------------------------------------------
int FUN_006a4aab(void* self, int param_1, int* param_2, uint32_t param_3, int* param_4,
                 int* param_5, int* param_6, uint32_t param_7, uint32_t param_8,
                 uint32_t param_9, uint32_t param_10, int param_11)
{
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    int iVar4 = param_1;
    int iVar3;
    int* piVar1;

    uint32_t uVar2 = ((uint32_t (__cdecl*)(void*, int))(vtbl(self) + 0x5c))(self, param_1);
    iVar3 = FUN_006a48dd(uVar2);
    piVar1 = param_2;
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*, uint32_t*))(
                 vtbl(self) + 0x6c))(self,
                                     *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *param_2 * 4),
                                     &local_8, &local_18, &local_14);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, int*, uint32_t, int*, uint32_t))(vtbl(self) + 0x70))(
        self, piVar1, param_3, &param_1, local_14);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x64))(
        self, (-(uint32_t)(param_11 != 0) & 0x400000u) | local_8, (uint32_t)param_1, local_18);
    piVar1 = param_4;
    if (iVar3 < 0) {
        return iVar3;
    }
    if (iVar4 == 8) {
        param_1 = 0x70000;
    } else if (iVar4 == 9) {
        param_1 = 0xf0000;
    } else if (iVar4 == 0x5a) {
        param_1 = 0x30000;
    } else if (iVar4 == 6 || iVar4 == 0xe || iVar4 == 0xf || iVar4 == 7) {
        param_1 = 0x10000;
    } else if (iVar4 == 0x25) {
        param_1 = 0xf0000;
    }
    if (param_4 != (int*)0) {
        iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
            self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *param_4 * 4), &local_8, &local_c);
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = ((int (__cdecl*)(void*, int*, uint32_t, int, uint32_t*))(vtbl(self) + 0x78))(
            self, piVar1, param_7, param_1, &local_10);
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
            self, local_8 ^ param_8, local_10, local_c);
        if (iVar3 < 0) {
            return iVar3;
        }
    }
    if (param_5 != (int*)0) {
        piVar1 = param_5;
        iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
            self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *param_5 * 4), &local_8, &local_c);
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = ((int (__cdecl*)(void*, int*, uint32_t, int, uint32_t*))(vtbl(self) + 0x78))(
            self, piVar1, param_7, param_1, &local_10);
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
            self, local_8 ^ param_9, local_10, local_c);
        if (iVar3 < 0) {
            return iVar3;
        }
    }
    if (param_6 != (int*)0) {
        piVar1 = param_6;
        iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
            self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *param_6 * 4), &local_8, &local_c);
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = ((int (__cdecl*)(void*, int*, uint32_t, int, uint32_t*))(vtbl(self) + 0x78))(
            self, piVar1, param_7, param_1, &local_10);
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
            self, local_8 ^ param_10, local_10, local_c);
        if (iVar3 < 0) {
            return iVar3;
        }
    }
    iVar3 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = FUN_0069fcf5();
    if (iVar3 < 0) {
        return iVar3;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a4ca4 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a4ca4(void* self, uint32_t param_1, uint32_t* param_2)
{
    uint32_t uVar1;
    int iVar2;
    char local_24[32];
    uintptr_t obj;

    if (((int32_t*)self)[0x56] == 0) {
        if (param_1 < 0x800) {
            uVar1 = (param_1 & 0x7ff) | 0xa0000000u;
        } else if (param_1 < 0x1000) {
            uVar1 = (param_1 & 0x7ff) | 0xb0000800u;
        } else if (param_1 < 0x1800) {
            uVar1 = (param_1 & 0x7ff) | 0xc0000800u;
        } else {
            uVar1 = (param_1 & 0x7ff) | 0xd0000800u;
        }
        iVar2 = FUN_006a48dd(0x51);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x64))(
            self, uVar1, 0xf0000, 0);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = FUN_006a2b66(param_2[0]);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = FUN_006a2b66(param_2[1]);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = FUN_006a2b66(param_2[2]);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = FUN_006a2b66(param_2[3]);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = FUN_0069fcf5();
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = 0;
    } else {
        sprintf(local_24, "c_$zz%d", param_1);
        iVar2 = FUN_0061273f(local_24, param_1, 1);
        if (iVar2 < 0) {
            return iVar2;
        }
        obj = FUN_00610ba0(local_24);
        *(uint32_t*)(obj + 0xc) = 1;
        *(uint32_t*)(obj + 0x10) = param_2[0];
        *(uint32_t*)(obj + 0x14) = param_2[1];
        *(uint32_t*)(obj + 0x18) = param_2[2];
        *(uint32_t*)(obj + 0x1c) = param_2[3];
        ((int32_t*)self)[0x7d] = ((int32_t*)self)[0x7d] + 1;
        iVar2 = 0;
    }
    return iVar2;
}

// ---------------------------------------------------------------------------
// 0x6a4de1 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a4de1(void* self, uint32_t param_1, uint32_t* param_2)
{
    int iVar1;
    char local_24[32];
    uintptr_t obj;

    if (((int32_t*)self)[0x56] == 0) {
        iVar1 = FUN_006a48dd(0x30);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x64))(
            self, (param_1 & 0x7ff) | 0xf0000000u, 0xf0000, 0);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = FUN_006a2b66(param_2[0]);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = FUN_006a2b66(param_2[1]);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = FUN_006a2b66(param_2[2]);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = FUN_006a2b66(param_2[3]);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = FUN_0069fcf5();
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = 0;
    } else {
        sprintf(local_24, "i_$zz%d", param_1);
        iVar1 = FUN_0061273f(local_24, param_1, 1);
        if (iVar1 < 0) {
            return iVar1;
        }
        obj = FUN_00610ba0(local_24);
        *(uint32_t*)(obj + 0xc) = 1;
        *(uint32_t*)(obj + 0x10) = param_2[0];
        *(uint32_t*)(obj + 0x14) = param_2[1];
        *(uint32_t*)(obj + 0x18) = param_2[2];
        *(uint32_t*)(obj + 0x1c) = param_2[3];
        ((int32_t*)self)[0x7d] = ((int32_t*)self)[0x7d] + 1;
        iVar1 = 0;
    }
    return iVar1;
}

// ---------------------------------------------------------------------------
// 0x6a4ee3 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a4ee3(void* self)
{
    int iVar1;

    iVar1 = FUN_006a48dd(0x27);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = FUN_0069fcf5();
    if (iVar1 < 0) {
        return iVar1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a4f0d — observed shape
// ---------------------------------------------------------------------------
int FUN_006a4f0d(void* self)
{
    int iVar1;

    iVar1 = FUN_006a48dd(0x1d);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = FUN_0069fcf5();
    if (iVar1 < 0) {
        return iVar1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a4f37 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a4f37(void* self)
{
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    int iVar2 = 0;
    uint32_t base = (uint32_t)((int32_t*)self)[0x40];
    uint32_t uVar1 = *(uint32_t*)(uintptr_t)base & 0xfff00000u;
    uint32_t uVar3 = *(uint32_t*)(uintptr_t)base & 0xfffffu;

    if (uVar1 != 0x74300000u) {
        if (uVar1 == 0x74400000u) {
            iVar2 = 5;
            goto LAB_006a4f8d;
        }
        if (uVar1 != 0x74500000u) {
            if (uVar1 == 0x74600000u) {
                iVar2 = 4;
            } else if (uVar1 == 0x74700000u) {
                iVar2 = 3;
            }
            goto LAB_006a4f8d;
        }
    }
    iVar2 = 2;
LAB_006a4f8d:
    iVar2 = FUN_006a48dd((uint32_t)(iVar2 << 0x10 | 0x2d));
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
        self,
        *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + **(int32_t**)(uintptr_t)(base + 8) * 4),
        &local_10, &local_8);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                 vtbl(self) + 0x78))(self, *(uint32_t*)(uintptr_t)(base + 8), uVar3, 0xf0000,
                                     &local_c);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_10, local_c, local_8);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
        self,
        *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                *(int32_t*)(uintptr_t)(uVar3 * 4 +
                                                       *(int32_t*)(uintptr_t)(base + 8)) *
                                    4),
        &local_10, &local_8);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                 vtbl(self) + 0x78))(self, *(uint32_t*)(uintptr_t)(base + 8) + uVar3 * 4, uVar3,
                                     0xf0000, &local_c);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_10, local_c, local_8);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = FUN_0069fcf5();
    if (iVar2 < 0) {
        return iVar2;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a507d — observed shape
// ---------------------------------------------------------------------------
void FUN_006a507d(void* self)
{
    uint32_t local_c;
    uint32_t local_8;
    uint32_t* puVar1 = *(uint32_t**)((char*)self + 0x100);
    uint32_t uVar2 = puVar1[3];
    uint32_t uVar3 = *puVar1;
    uint32_t uVar4 = puVar1[4];

    FUN_0065cc6f(0, &local_8);
    FUN_0065cc6f(1, &local_c);
    FUN_006a4aab(self, 0x42, (int*)(uintptr_t)uVar4, uVar2, (int*)(uintptr_t)local_c,
                 (int*)(uintptr_t)local_8, (int*)0, uVar3 & 0xfffff, 0, 0, 0, 0);
}

// ---------------------------------------------------------------------------
// 0x6a50e1 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a50e1(void* self)
{
    uint32_t local_30;
    uint32_t local_2c;
    uint32_t local_28;
    int* local_24;
    int* local_20;
    int* local_1c;
    int* local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    int iVar3;
    int* piVar1;
    uint32_t base;

    base = (uint32_t)((int32_t*)self)[0x40];
    local_2c = ((uint32_t*)(uintptr_t)base)[3];
    uint32_t uVar4 = *(uint32_t*)(uintptr_t)base & 0xfffffu;
    FUN_0065cc6f(0, &local_1c);
    FUN_0065cc6f(1, &local_18);
    FUN_0065cc6f(2, &local_20);
    FUN_0065cc6f(3, &local_24);
    piVar1 = (int*)(uintptr_t)(*(uint32_t*)(uintptr_t)(base + 0x10));
    uint32_t uVar2 = ((uint32_t (__cdecl*)(void*, uint32_t))(vtbl(self) + 0x5c))(self, 0x5d);
    iVar3 = FUN_006a48dd(uVar2);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*, uint32_t*))(
                 vtbl(self) + 0x6c))(self,
                                     *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *piVar1 * 4),
                                     &local_8, &local_30, &local_28);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, int*, uint32_t, uint32_t*, uint32_t))(vtbl(self) + 0x70))(
        self, piVar1, local_2c, &local_14, local_28);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x64))(
        self, local_8, local_14, local_30);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
        self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *local_18 * 4), &local_8, &local_c);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                 vtbl(self) + 0x78))(self, (uint32_t)(uintptr_t)local_18, uVar4, local_14,
                                     &local_10);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_8, local_10, local_c);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
        self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *local_1c * 4), &local_8, &local_c);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                 vtbl(self) + 0x78))(self, (uint32_t)(uintptr_t)local_1c, uVar4, local_14,
                                     &local_10);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_8, local_10, local_c);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
        self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *local_20 * 4), &local_8, &local_c);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                 vtbl(self) + 0x78))(self, (uint32_t)(uintptr_t)local_20, uVar4, local_14,
                                     &local_10);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_8, local_10, local_c);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
        self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + *local_24 * 4), &local_8, &local_c);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                 vtbl(self) + 0x78))(self, (uint32_t)(uintptr_t)local_24, uVar4, local_14,
                                     &local_10);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_8, local_10, local_c);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = FUN_0069fcf5();
    if (iVar3 < 0) {
        return iVar3;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a5310 — observed shape
// ---------------------------------------------------------------------------
void FUN_006a5310(void* self)
{
    uint32_t local_c;
    uint32_t local_8;
    uint32_t* puVar1 = *(uint32_t**)((char*)self + 0x100);
    uint32_t uVar2 = puVar1[3];
    uint32_t uVar3 = *puVar1;
    uint32_t uVar4 = puVar1[4];

    FUN_0065cc6f(0, &local_8);
    FUN_0065cc6f(1, &local_c);
    FUN_006a4aab(self, 0x10042, (int*)(uintptr_t)uVar4, uVar2, (int*)(uintptr_t)local_c,
                 (int*)(uintptr_t)local_8, (int*)0, uVar3 & 0xfffff, 0, 0, 0, 0);
}

// ---------------------------------------------------------------------------
// 0x6a5377 — observed shape
// ---------------------------------------------------------------------------
void FUN_006a5377(void* self)
{
    uint32_t local_c;
    uint32_t local_8;
    uint32_t* puVar1 = *(uint32_t**)((char*)self + 0x100);
    uint32_t uVar2 = puVar1[3];
    uint32_t uVar3 = *puVar1;
    uint32_t uVar4 = puVar1[4];

    FUN_0065cc6f(0, &local_8);
    FUN_0065cc6f(1, &local_c);
    FUN_006a4aab(self, 0x20042, (int*)(uintptr_t)uVar4, uVar2, (int*)(uintptr_t)local_c,
                 (int*)(uintptr_t)local_8, (int*)0, uVar3 & 0xfffff, 0, 0, 0, 0);
}

// ---------------------------------------------------------------------------
// 0x6a53de — observed shape
// ---------------------------------------------------------------------------
void FUN_006a53de(void* self)
{
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    uint32_t* puVar1 = *(uint32_t**)((char*)self + 0x100);
    uint32_t uVar2;

    local_8 = puVar1[3];
    uVar2 = *puVar1;
    local_c = puVar1[4];
    FUN_0065cc6f(0, &local_14);
    FUN_0065cc6f(1, &local_10);
    FUN_006a4aab(self, 0x5f, (int*)(uintptr_t)local_c, local_8, (int*)(uintptr_t)local_10,
                 (int*)(uintptr_t)local_14, (int*)0, uVar2 & 0xfffff, 0, 0, 0, 0);
}

// ---------------------------------------------------------------------------
// 0x6a5442 — observed shape
// ---------------------------------------------------------------------------
void FUN_006a5442(void* self)
{
    uint32_t* puVar1 = *(uint32_t**)((char*)self + 0x100);
    uint32_t uVar2 = puVar1[2];
    uint32_t uVar3 = *puVar1 & 0xfffff;

    FUN_006a4aab(self, 0x5a, (int*)(uintptr_t)puVar1[4], puVar1[3], (int*)(uintptr_t)uVar2,
                 (int*)(uintptr_t)(uVar2 + uVar3 * 4), (int*)(uintptr_t)(uVar2 + uVar3 * 8),
                 uVar3, 0, 0, 0, 0);
}

// ---------------------------------------------------------------------------
// 0x6a5478 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a5478(void* self)
{
    uint32_t local_c;
    uint32_t local_8;
    uint32_t local_10;
    uint32_t uVar5;
    uint32_t uVar4;
    uint32_t uVar2;
    int iVar1 = ((int32_t*)self)[0x40];

    if ((*((uint8_t*)self + 0x6e) & 0x40) == 0) {
        if (*(int32_t*)(uintptr_t)(iVar1 + 4) != 4) {
            goto LAB_006a55ba;
        }
    } else {
        uVar4 = 0;
        uVar2 = 0;
        if (*(int32_t*)(uintptr_t)(iVar1 + 4) != 0) {
            int32_t* piVar3 = *(int32_t**)(uintptr_t)(iVar1 + 8);
            do {
                if (*(uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(
                                                ((int32_t*)self)[5] + *piVar3 * 4) +
                                            0x10) != uVar4) {
                    goto LAB_006a55ba;
                }
                uVar2 = *(uint32_t*)(uintptr_t)(iVar1 + 4);
                uVar4 = uVar4 + 1;
                piVar3 = piVar3 + 1;
            } while (uVar4 < uVar2);
        }
        if (uVar2 != 3) {
            goto LAB_006a55ba;
        }
    }
    iVar1 = *(int32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                   **(int32_t**)(uintptr_t)(iVar1 + 8) * 4);
    if (*(int32_t*)(uintptr_t)(iVar1 + 4) == ((int32_t*)self)[0x20]) {
        iVar1 = ((int (__cdecl*)(void*, uint32_t*, uint32_t*))(vtbl(self) + 0x88))(
            self, &local_c, &local_8);
        if (-1 < iVar1) {
            goto LAB_006a553b;
        }
    } else if (*(int32_t*)(uintptr_t)(iVar1 + 4) == ((int32_t*)self)[0x22]) {
        local_8 = 0;
        local_c = *(uint32_t*)(uintptr_t)(iVar1 + 0xc);
LAB_006a553b:
        uVar5 = local_8 | 0xfffffff8u;
        uVar4 = local_8 & 0x18u;
        uVar2 = local_c & 0x7ffu;
        iVar1 = FUN_006a48dd(0x41);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = ((int (__cdecl*)(void*, uint32_t, uint32_t*))(vtbl(self) + 0x7c))(
            self,
            *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                    **(int32_t**)(uintptr_t)(((int32_t*)self)[0x40] + 0x10) * 4),
            &local_10);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x64))(
            self, (uint32_t)((uVar5 << 0x14 | uVar4) << 8 | uVar2), 0xf0000, local_10);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = FUN_0069fcf5();
        if (iVar1 < 0) {
            return iVar1;
        }
        return 0;
    }
LAB_006a55ba:
    FUN_006626da();
    return -0x7fffbffb;
}

// ---------------------------------------------------------------------------
// 0x6a55cd — observed shape
// ---------------------------------------------------------------------------
uint32_t FUN_006a55cd(void* self)
{
    int32_t local_14[4];
    int32_t iVar2;
    int32_t iVar3;
    int32_t iVar4;
    int32_t iVar5;
    bool flag;

    local_14[3] = 0;
    iVar2 = *(int32_t*)((char*)self + 0x100);
    local_14[2] = 0;
    iVar3 = *(int32_t*)((char*)self + 0x10);
    do {
        iVar4 = *(int32_t*)(uintptr_t)(local_14[2] + *(int32_t*)(uintptr_t)(iVar2 + 0x10));
        iVar5 = *(int32_t*)(uintptr_t)(*(int32_t*)((char*)self + 0x14) + iVar4 * 4);
        if (((*(uint8_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(
                                         iVar3 + *(int32_t*)(uintptr_t)(iVar5 + 4) * 4) +
                                     4) & 1) == 0) ||
            (*(int32_t*)(uintptr_t)(iVar5 + 0x5c) != 0)) {
            int32_t* piVar1 = local_14 + local_14[3];
            local_14[3] = local_14[3] + 1;
            *piVar1 = iVar4;
        }
        local_14[2] = local_14[2] + 4;
    } while ((uint32_t)local_14[2] < 8);
    if (local_14[3] == 0) {
        return 0;
    }
    flag = *(int32_t*)((char*)self + 0x18c) != 0;
    return FUN_006a4aab(self, 0x25, local_14, (uint32_t)local_14[3],
                        flag ? (int*)((char*)self + 400) : (int*)0,
                        flag ? (int*)((char*)self + 0x1a0) : (int*)0, 4, 0, 0, 0, 0);
}

// ---------------------------------------------------------------------------
// 0x6a566b — observed shape
// ---------------------------------------------------------------------------
int FUN_006a566b(void* self)
{
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    int iVar2 = 0;
    uint32_t uVar1;
    uint32_t uVar3;
    uint32_t base;

    if (((int32_t*)self)[0xd] == 0) {
        return -0x7fffbfff;
    }
    uVar1 = *(uint32_t*)(uintptr_t)(((int32_t*)self)[0x40]) & 0xfff00000u;
    uVar3 = *(uint32_t*)(uintptr_t)(((int32_t*)self)[0x40]) & 0xfffffu;
    if (uVar1 != 0x10f00000u) {
        if (uVar1 == 0x73500000u) {
            iVar2 = 3;
            goto LAB_006a56d2;
        }
        if (uVar1 == 0x73600000u) {
            iVar2 = 4;
            goto LAB_006a56d2;
        }
        if (uVar1 != 0x73700000u) {
            if (uVar1 == 0x73800000u) {
                iVar2 = 2;
            }
            goto LAB_006a56d2;
        }
    }
    iVar2 = 5;
LAB_006a56d2:
    iVar2 = FUN_006a48dd((uint32_t)(iVar2 << 0x10 | 0x5e));
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t, uint32_t*))(
                 vtbl(self) + 0x6c))(
        self,
        *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                **(int32_t**)(uintptr_t)(((int32_t*)self)[0x40] + 0x10) * 4),
        &local_8, 0, &local_18);
    if (iVar2 < 0) {
        return iVar2;
    }
    base = (uint32_t)((int32_t*)self)[0x40];
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t*, uint32_t))(
                 vtbl(self) + 0x70))(self, *(uint32_t*)(uintptr_t)(base + 0x10),
                                     *(uint32_t*)(uintptr_t)(base + 0xc), &local_14, local_18);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x64))(
        self, local_8, local_14, 0);
    if (iVar2 < 0) {
        return iVar2;
    }
    if ((*(uint32_t*)(uintptr_t)(((int32_t*)self)[0x40]) & 0xfff00000u) == 0x10f00000u) {
        // Listing calls slot 0x74 with no out-parameters here, so local_c stays uninitialized
        // and is consumed by the 0x68 call below exactly as the provider pseudocode shows.
        iVar2 = ((int (__cdecl*)(void*))(vtbl(self) + 0x74))(self);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                     vtbl(self) + 0x78))(self, *(uint32_t*)(uintptr_t)(base + 8),
                                         *(uint32_t*)(uintptr_t)(base + 0xc), local_14,
                                         &local_10);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
            self, local_8, local_10, local_c);
        if (iVar2 < 0) {
            return iVar2;
        }
        local_10 = local_10 ^ 0x1000000u;
    } else {
        iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
            self,
            *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                    ((uint32_t*)(uintptr_t)base)[2] * 4),
            &local_8, &local_c);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                     vtbl(self) + 0x78))(self, *(uint32_t*)(uintptr_t)(base + 8), uVar3,
                                         local_14, &local_10);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
            self, local_8, local_10, local_c);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
            self,
            *(uint32_t*)(uintptr_t)(
                ((int32_t*)self)[5] +
                *(int32_t*)(uintptr_t)(uVar3 * 4 + *(int32_t*)(uintptr_t)(base + 8)) * 4),
            &local_8, &local_c);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                     vtbl(self) + 0x78))(self, *(uint32_t*)(uintptr_t)(base + 8) + uVar3 * 4,
                                         uVar3, local_14, &local_10);
        if (iVar2 < 0) {
            return iVar2;
        }
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_8, local_10, local_c);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = FUN_0069fcf5();
    if (iVar2 < 0) {
        return iVar2;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a5874 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a5874(void* self)
{
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t base;
    uint32_t count;

    if (((int32_t*)self)[0xd] == 0) {
        iVar2 = -0x7fffbfff;
    } else if (*(int32_t*)(uintptr_t)(((int32_t*)self)[0x40] + 0xc) == 0) {
        iVar2 = 0;
    } else {
        iVar2 = *(int32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                       **(int32_t**)(uintptr_t)(((int32_t*)self)[0x40] + 0x10) * 4);
        local_8 = 0;
        do {
            base = (uint32_t)((int32_t*)self)[0x40];
            count = *(uint32_t*)(uintptr_t)(base + 0xc);
            iVar4 = *(int32_t*)(uintptr_t)(
                ((int32_t*)self)[5] +
                *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(base + 8) + count * local_8 * 4) * 4);
            if ((((*(int32_t*)(uintptr_t)(iVar4 + 4) != *(int32_t*)(uintptr_t)(iVar2 + 4)) ||
                  (*(int32_t*)(uintptr_t)(iVar4 + 8) != *(int32_t*)(uintptr_t)(iVar2 + 8))) ||
                 (*(int32_t*)(uintptr_t)(iVar4 + 0xc) != *(int32_t*)(uintptr_t)(iVar2 + 0xc))) ||
                (*(int32_t*)(uintptr_t)(iVar4 + 0x10) != *(int32_t*)(uintptr_t)(iVar2 + 0x10))) {
                iVar3 = FUN_006a48dd(1);
                if (iVar3 < 0) {
                    return iVar3;
                }
                iVar3 = *(int32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                               *(int32_t*)(uintptr_t)(iVar4 + 0x14) * 4);
                iVar1 = *(int32_t*)(uintptr_t)(iVar3 + 0x10);
                uVar5 = *(uint32_t*)(uintptr_t)(iVar3 + 0xc) & 0x7ffu;
                uVar6 = uVar5 | 0xb0001000u;
                if (iVar1 != 0) {
                    if (iVar1 == 1) {
                        uVar6 = uVar5 | 0xb0551000u;
                    } else if (iVar1 == 2) {
                        uVar6 = uVar5 | 0xb0aa1000u;
                    } else if (iVar1 == 3) {
                        uVar6 = uVar5 | 0xb0ff1000u;
                    }
                }
                if (*(int32_t*)(uintptr_t)(iVar4 + 0x18) == 0) {
                    uVar6 = uVar6 | 0xd000000u;
                }
                iVar4 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t, uint32_t*))(
                             vtbl(self) + 0x6c))(
                    self,
                    *(uint32_t*)(uintptr_t)(
                        ((int32_t*)self)[5] +
                        **(int32_t**)(uintptr_t)(((int32_t*)self)[0x40] + 0x10) * 4),
                    &local_c, 0, &local_14);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t*, uint32_t))(
                             vtbl(self) + 0x70))(
                    self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[0x40] + 0x10),
                    *(uint32_t*)(uintptr_t)(((int32_t*)self)[0x40] + 0xc), &local_10, local_14);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x64))(
                    self, local_c, local_10, uVar6);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(
                             vtbl(self) + 0x74))(
                    self,
                    *(uint32_t*)(uintptr_t)(
                        ((int32_t*)self)[5] +
                        *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(base + 8) +
                                               count * local_8 * 4) *
                            4),
                    &local_c, &local_18);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = *(int32_t*)(uintptr_t)(((int32_t*)self)[0x40] + 0xc);
                iVar4 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                             vtbl(self) + 0x78))(
                    self, *(uint32_t*)(uintptr_t)(((int32_t*)self)[0x40] + 8) + iVar4 * local_8 * 4,
                    (uint32_t)iVar4, local_10, &local_1c);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
                    self, local_c, local_1c, local_18);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = FUN_0069fcf5();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < 2);
        iVar2 = 0;
    }
    return iVar2;
}

// ---------------------------------------------------------------------------
// 0x6a5a43 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a5a43(void* self)
{
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    int iVar2 = 0;
    uint32_t base = (uint32_t)((int32_t*)self)[0x40];
    uint32_t uVar1 = *(uint32_t*)(uintptr_t)base & 0xfff00000u;
    uint32_t uVar3 = *(uint32_t*)(uintptr_t)base & 0xfffffu;

    if (uVar1 != 0x73000000u) {
        if (uVar1 == 0x73900000u) {
            iVar2 = 3;
            goto LAB_006a5a99;
        }
        if (uVar1 == 0x73a00000u) {
            iVar2 = 4;
            goto LAB_006a5a99;
        }
        if (uVar1 == 0x73b00000u) {
            iVar2 = 5;
            goto LAB_006a5a99;
        }
        if (uVar1 != 0x73c00000u) {
            goto LAB_006a5a99;
        }
    }
    iVar2 = 2;
LAB_006a5a99:
    iVar2 = FUN_006a48dd((uint32_t)(iVar2 << 0x10 | 0x29));
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
        self,
        *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] + **(int32_t**)(uintptr_t)(base + 8) * 4),
        &local_10, &local_8);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                 vtbl(self) + 0x78))(self, *(uint32_t*)(uintptr_t)(base + 8), uVar3, 0xf0000,
                                     &local_c);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_10, local_c, local_8);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t*, uint32_t*))(vtbl(self) + 0x74))(
        self,
        *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                *(int32_t*)(uintptr_t)(uVar3 * 4 +
                                                       *(int32_t*)(uintptr_t)(base + 8)) *
                                    4),
        &local_10, &local_8);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t, uint32_t*))(
                 vtbl(self) + 0x78))(self, *(uint32_t*)(uintptr_t)(base + 8) + uVar3 * 4, uVar3,
                                     0xf0000, &local_c);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, local_10, local_c, local_8);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar2 < 0) {
        return iVar2;
    }
    iVar2 = FUN_0069fcf5();
    if (iVar2 < 0) {
        return iVar2;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a5b9e — observed shape
// ---------------------------------------------------------------------------
int FUN_006a5b9e(void* self, int param_1)
{
    int* local_c = (int*)self;
    int* local_8 = (int*)self;
    int iVar1;

    iVar1 = FUN_006a48dd(0x28);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = ((int (__cdecl*)(void*, uint32_t, int**, int**))(vtbl(self) + 0x74))(
        self,
        *(uint32_t*)(uintptr_t)(((int32_t*)self)[5] +
                                **(int32_t**)(uintptr_t)(((int32_t*)self)[0x40] + 8) * 4),
        &local_c, &local_8);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = ((int (__cdecl*)(void*, uint32_t, uint32_t, uint32_t))(vtbl(self) + 0x68))(
        self, (-(uint32_t)(param_1 != 0) & 0xd000000u) | (uint32_t)(uintptr_t)local_c, 0xe40000,
        (uint32_t)(uintptr_t)local_8);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = FUN_0069fcf5();
    if (iVar1 < 0) {
        return iVar1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a5c18 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a5c18(void* self)
{
    int iVar1;

    iVar1 = FUN_006a48dd(0x2a);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = FUN_0069fcf5();
    if (iVar1 < 0) {
        return iVar1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6a5c42 — observed shape
// ---------------------------------------------------------------------------
int FUN_006a5c42(void* self)
{
    int iVar1;

    iVar1 = FUN_006a48dd(0x2b);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = ((int (__cdecl*)(void*))(vtbl(self) + 0x60))(self);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = FUN_0069fcf5();
    if (iVar1 < 0) {
        return iVar1;
    }
    return 0;
}
