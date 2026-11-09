// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Reconstruction batch mass_0123: 0x538d70-0x53a0f0 (stream/quaternion-adjacent helpers).
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00513ce0(void*);
extern void FUN_00513dc0(void*);
extern void* FUN_00545600();
extern int FUN_00545630();
extern void* FUN_00533c78(size_t);
extern void* FUN_0053a4c0(uint32_t);
extern void FUN_00558fc0(uint32_t, uint32_t);
extern void FUN_005383d0(void*);
extern void FUN_00538400(void*);
extern void FUN_00538430(void*, int);
extern void FUN_005386f0(int);
extern void FUN_00559000(void*);
extern int FUN_00557b10(int);
extern void FUN_006b34a0(int);
extern void FUN_005606f0(uint32_t, int*);
extern void FUN_00540c50(void*);
extern void FUN_00540c90(void*);
extern void thunk_FUN_00540af0(uint32_t);
extern char thunk_FUN_00540b70(uint32_t);
extern int FUN_00497420(int);
extern int FUN_0054acf0(int);
extern void FUN_0053a110(void*);
extern void operator_delete(void*);

extern void* PTR_FUN_006c0a10;
extern void* PTR_FUN_006c0a50;
extern void* PTR_FUN_006c0a90;
extern int DAT_00727514;
extern uint8_t DAT_0072751c;
extern uint8_t DAT_007279a8;
extern int DAT_007279c0;
extern int DAT_007279c4;
extern int DAT_00727994;
extern int DAT_00727998;
extern int* DAT_00727c30;
extern uint8_t DAT_007179a0;

struct RefObj {
    void* vtbl;
    int refs;
};

static inline void release_ref(RefObj* o) {
    auto fn = (void(__thiscall*)(void*, int))(*(void***)o->vtbl)[0];
    fn(o, 1);
}

// 0x538d70 — observed shape
void FUN_00538d70(uint32_t* self, int param_1, uint32_t in_EBX) {
    int iVar1 = param_1;
    void* reader = *(void**)((uint8_t*)(uintptr_t)param_1 + 0x15c);
    uint32_t uStack_1c;                 // outgoing 4-byte read buffer
    uint32_t* puStack_18 = (uint32_t*)&param_1;  // call-argument slot
    uint32_t uStack_14 = 4;

    (*(void(__thiscall*)(void*))(*(void***)reader)[2])(reader);
    *self = in_EBX;
    uint32_t* puVar2 = self + 2;
    int iVar3 = 4;
    do {
        (*(void(__thiscall*)(void*, void*))(*(void***)reader)[2])(reader, puVar2);
        puVar2 = puVar2 + 1;
        iVar3 = iVar3 - 1;
    } while (iVar3 != 0);
    (*(void(__thiscall*)(void*, void*))(*(void***)reader)[2])(reader, self + 6);
    (*(void(__thiscall*)(void*, void*))(*(void***)reader)[2])(reader, self + 7);
    (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)reader)[2])(reader, self + 8, 4);
    (void)puStack_18;
    (void)uStack_14;
    if (0xa00010a < *(uint32_t*)((uint8_t*)(uintptr_t)iVar1 + 0x1c)) {
        (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)reader)[2])(reader, &uStack_1c, 4);
        self[1] = 4;
        return;
    }
    if ((*(uint32_t*)((uint8_t*)(uintptr_t)iVar1 + 0x1c) == 0xa000100) &&
        ((self[0] & 0x10000) != 0)) {
        self[1] = 1;
        self[0] = self[0] & 0xfffeffff;
    }
    return;
}

// 0x538e40 — observed shape
void FUN_00538e40(void* self, int param_1) {
    void* writer = *(void**)((uint8_t*)(uintptr_t)param_1 + 0x160);
    uint8_t* b = (uint8_t*)self;

    (*(void(__thiscall*)(void*))(*(void***)writer)[3])(writer);
    uint8_t* iVar1 = b + 8;
    int iVar2 = 4;
    do {
        (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writer)[3])(writer, iVar1, 4);
        iVar1 = iVar1 + 4;
        iVar2 = iVar2 - 1;
    } while (iVar2 != 0);
    (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writer)[3])(writer, b + 0x18, 4);
    (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writer)[3])(writer, b + 0x1c, 4);
    (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writer)[3])(writer, b + 0x20, 4);
    (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writer)[3])(writer, b + 4, 4);
    return;
}

// 0x538ec0 — observed shape
uint32_t FUN_00538ec0(uint32_t param_1, uint32_t param_2) {
    uint32_t uVar1;
    uint32_t uVar2;

    if ((param_1 == 0) || (param_2 == 0)) {
        uVar1 = 0;
    } else {
        uVar2 = 1;
        for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
            uVar2 = uVar2 + 1;
        }
        uVar1 = 1;
        if ((param_1 & 0xfffffffe) == 0) {
            for (; (param_2 & 1) == 0; param_2 = param_2 >> 1) {
                uVar1 = uVar1 + 1;
            }
            if ((param_2 & 0xfffffffe) != 0) {
                return 1;
            }
            if (uVar1 < uVar2) {
                return uVar2;
            }
        }
    }
    return uVar1;
}

// 0x538f60 — observed shape
void FUN_00538f60(void* self, uint32_t param_1) {
    FUN_00513ce0((void*)(uintptr_t)param_1);
    RefObj* puVar3 = (RefObj*)FUN_00545600();
    RefObj* puVar2 = *(RefObj**)((uint8_t*)self + 0x30);
    if (puVar2 != puVar3) {
        if (puVar2 != (RefObj*)0x0) {
            puVar2->refs = puVar2->refs - 1;
            if (puVar2->refs == 0) {
                release_ref(puVar2);
            }
        }
        *(RefObj**)((uint8_t*)self + 0x30) = puVar3;
        if (puVar3 != (RefObj*)0x0) {
            puVar3->refs = puVar3->refs + 1;
        }
    }
    return;
}

// 0x5390b0 — observed shape
void FUN_005390b0(uint32_t* self, int param_1) {
    uint32_t* puVar2;
    uint32_t* puVar8;
    uint32_t local_c0[16];
    uint32_t auStack_80[16];
    uint32_t auStack_40[16];
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;

    FUN_005383d0(self);
    ((void**)self)[0] = (void*)&PTR_FUN_006c0a10;
    FUN_00513dc0(self);
    self[0xc] = 0;
    puVar2 = (uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0xc);
    puVar8 = self + 3;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar8 = puVar8 + 1;
    }
    if (*(int*)((uint8_t*)(uintptr_t)param_1 + 0x30) != 0) {
        iVar3 = (int)(intptr_t)FUN_00533c78(0x28);
        if (iVar3 == 0) {
            puVar2 = (uint32_t*)0x0;
        } else {
            puVar2 = (uint32_t*)FUN_0053a4c0(*(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x30));
        }
        RefObj* cur = (RefObj*)(uintptr_t)self[0xc];
        RefObj* nxt = (RefObj*)puVar2;
        if (cur != nxt) {
            if (cur != (RefObj*)0x0) {
                cur->refs = cur->refs - 1;
                if (cur->refs == 0) {
                    release_ref(cur);
                }
            }
            self[0xc] = (uint32_t)(uintptr_t)nxt;
            if (nxt != (RefObj*)0x0) {
                nxt->refs = nxt->refs + 1;
            }
        }
    }
    uVar5 = *(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x44);
    self[0x11] = uVar5;
    self[0x12] = *(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x48);
    if (uVar5 != 0) {
        uint32_t* puVar6 = *(uint32_t**)((uint8_t*)(uintptr_t)param_1 + 0x40);
        uint32_t* puVar7 = local_c0;
        for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
        }
        puVar2 = *(uint32_t**)((uint8_t*)(uintptr_t)param_1 + 0x3c);
        puVar8 = auStack_40;
        for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar8 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar8 = puVar8 + 1;
        }
        puVar2 = *(uint32_t**)((uint8_t*)(uintptr_t)param_1 + 0x38);
        puVar8 = auStack_80;
        for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar8 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar8 = puVar8 + 1;
        }
    }
    uVar4 = *(uint32_t*)(*(int*)((uint8_t*)(uintptr_t)param_1 + 0x40) + uVar5 * 4);
    local_c0[uVar5] = uVar4;
    FUN_00558fc0(uVar5, uVar4);
    puVar2 = auStack_80;
    puVar8 = (uint32_t*)(uintptr_t)self[0xe];
    for (uVar5 = self[0x11] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar8 = puVar8 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar8 = *(uint8_t*)puVar2;
        puVar2 = (uint32_t*)((int)puVar2 + 1);
        puVar8 = (uint32_t*)((int)puVar8 + 1);
    }
    puVar2 = auStack_40;
    puVar8 = (uint32_t*)(uintptr_t)self[0xf];
    for (uVar5 = self[0x11] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar8 = puVar8 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar8 = *(uint8_t*)puVar2;
        puVar2 = (uint32_t*)((int)puVar2 + 1);
        puVar8 = (uint32_t*)((int)puVar8 + 1);
    }
    {
        uint32_t* puVar6 = local_c0;
        uint32_t* puVar7 = (uint32_t*)(uintptr_t)self[0x10];
        for (uVar5 = self[0x11] * 4 + 4U >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar7 = *(uint8_t*)puVar6;
            puVar6 = (uint32_t*)((int)puVar6 + 1);
            puVar7 = (uint32_t*)((int)puVar7 + 1);
        }
    }
    puVar2 = *(uint32_t**)((uint8_t*)(uintptr_t)param_1 + 0x34);
    puVar8 = (uint32_t*)(uintptr_t)self[0xd];
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar8 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar8 = puVar8 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(uint8_t*)puVar8 = *(uint8_t*)puVar2;
        puVar2 = (uint32_t*)((int)puVar2 + 1);
        puVar8 = (uint32_t*)((int)puVar8 + 1);
    }
    self[0x13] = 1;
    return;
}

// 0x539210 — observed shape
uint32_t* FUN_00539210(uint32_t* self, uint32_t param_1, uint32_t param_2, int* param_3, int param_4) {
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar3;
    int* piVar8;
    int* piVar10;
    uint32_t* puVar7;
    uint32_t* puVar9;
    int local_c0[16];
    uint32_t local_80[16];
    uint32_t local_40[16];

    FUN_005383d0(self);
    ((void**)self)[0] = (void*)&PTR_FUN_006c0a10;
    FUN_00513dc0(self);
    self[0xc] = 0;
    piVar8 = param_3;
    piVar10 = (int*)(self + 3);
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar10 = *piVar8;
        piVar8 = piVar8 + 1;
        piVar10 = piVar10 + 1;
    }
    if (param_4 == 0) {
        param_4 = (int)FUN_00538ec0(param_1, param_2);
    }
    self[0x11] = (uint32_t)param_4;
    local_c0[0] = 0;
    if ((*param_3 < 4) || (6 < *param_3)) {
        uVar6 = (uint32_t)(*(uint8_t*)((uint8_t*)param_3 + 0x18) >> 3);
        self[0x12] = uVar6;
        if (uVar6 == 0) {
            uVar6 = self[0x11];
            if (uVar6 != 0) {
                uVar2 = 0;
                do {
                    uVar5 = param_1;
                    if (param_1 == 0) {
                        uVar5 = 1;
                    }
                    local_80[uVar2] = uVar5;
                    uVar4 = param_2;
                    if (param_2 == 0) {
                        uVar4 = 1;
                    }
                    local_40[uVar2] = uVar4;
                    param_1 = param_1 >> 1;
                    param_2 = param_2 >> 1;
                    local_c0[uVar2 + 1] = (int)((uVar4 * uVar5 >> 1) + (uint32_t)local_c0[uVar2]);
                    uVar2 = uVar2 + 1;
                } while (uVar2 < uVar6);
            }
        } else {
            uVar2 = 0;
            if (self[0x11] != 0) {
                do {
                    uVar5 = param_1;
                    if (param_1 == 0) {
                        uVar5 = 1;
                    }
                    local_80[uVar2] = uVar5;
                    uVar4 = param_2;
                    if (param_2 == 0) {
                        uVar4 = 1;
                    }
                    local_40[uVar2] = uVar4;
                    uVar1 = self[0x11];
                    param_1 = param_1 >> 1;
                    param_2 = param_2 >> 1;
                    local_c0[uVar2 + 1] = (int)(uVar6 * uVar4 * uVar5 + (uint32_t)local_c0[uVar2]);
                    uVar2 = uVar2 + 1;
                } while (uVar2 < uVar1);
            }
        }
    } else {
        self[0x12] = 0;
        iVar3 = *param_3;
        uVar6 = 0;
        if (self[0x11] != 0) {
            do {
                uVar2 = param_1;
                if (param_1 == 0) {
                    uVar2 = 1;
                }
                local_80[uVar6] = uVar2;
                uVar5 = param_2;
                if (param_2 == 0) {
                    uVar5 = 1;
                }
                local_40[uVar6] = uVar5;
                local_c0[uVar6 + 1] =
                    (int)((((((uVar5 + 3) & 0xfffffffc) * ((uVar2 + 3) & 0xfffffffc)) >> 4) *
                           ((uint32_t)(iVar3 != 4) * 8 + 8)) +
                          (uint32_t)local_c0[uVar6]);
                param_1 = param_1 >> 1;
                param_2 = param_2 >> 1;
                uVar6 = uVar6 + 1;
            } while (uVar6 < self[0x11]);
        }
    }
    FUN_00558fc0(self[0x11], (uint32_t)local_c0[self[0x11]]);
    puVar7 = local_80;
    puVar9 = (uint32_t*)(uintptr_t)self[0xe];
    for (uVar6 = self[0x11] & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar9 = *(uint8_t*)puVar7;
        puVar7 = (uint32_t*)((int)puVar7 + 1);
        puVar9 = (uint32_t*)((int)puVar9 + 1);
    }
    puVar7 = local_40;
    puVar9 = (uint32_t*)(uintptr_t)self[0xf];
    for (uVar6 = self[0x11] & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar9 = *(uint8_t*)puVar7;
        puVar7 = (uint32_t*)((int)puVar7 + 1);
        puVar9 = (uint32_t*)((int)puVar9 + 1);
    }
    {
        int* piSrc = local_c0;
        int* piDst = (int*)(uintptr_t)self[0x10];
        for (uVar6 = self[0x11] * 4 + 4U >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *piDst = *piSrc;
            piSrc = piSrc + 1;
            piDst = piDst + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)piDst = *(uint8_t*)piSrc;
            piSrc = (int*)((int)piSrc + 1);
            piDst = (int*)((int)piDst + 1);
        }
    }
    self[0x13] = 1;
    return self;
}

// 0x5395d0 — observed shape
void FUN_005395d0(void* self, int* param_1) {
    int iVar1;
    uint32_t uVar2;
    uint8_t* b = (uint8_t*)self;

    FUN_00538430(self, (int)(intptr_t)param_1);
    FUN_00538e40(self, (int)(intptr_t)param_1);
    (*(void(__thiscall*)(int*, uint32_t))(*(void***)param_1)[0xb])(param_1, *(uint32_t*)(b + 0x30));
    void* writerObj = *(void**)((uint8_t*)param_1 + 0x160);
    (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writerObj)[3])(writerObj, b + 0x44, 4);
    (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writerObj)[3])(writerObj, b + 0x48, 4);
    uVar2 = 0;
    if (*(int*)(b + 0x44) != 0) {
        do {
            iVar1 = (int)(uVar2 * 4);
            (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writerObj)[3])(
                writerObj, (void*)(uintptr_t)(*(int*)(b + 0x38) + iVar1), 4);
            (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writerObj)[3])(
                writerObj, (void*)(uintptr_t)(*(int*)(b + 0x3c) + iVar1), 4);
            (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writerObj)[3])(
                writerObj, (void*)(uintptr_t)(*(int*)(b + 0x40) + iVar1), 4);
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(b + 0x44));
    }
    (*(void(__thiscall*)(void*, void*, uint32_t))(*(void***)writerObj)[3])(
        writerObj,
        (void*)(uintptr_t)(*(int*)(b + 0x40) + *(int*)(b + 0x44) * 4), 4);
    (*(void(__thiscall*)(void*, uint32_t, uint32_t))(*(void***)writerObj)[3])(
        writerObj,
        *(uint32_t*)(b + 0x34),
        *(uint32_t*)(*(int*)(b + 0x40) + *(int*)(b + 0x44) * 4));
    return;
}

// 0x5396b0 — observed shape
void FUN_005396b0(void* self, uint8_t param_1) {
    uint32_t* s = (uint32_t*)self;

    ((void**)self)[0] = (void*)&PTR_FUN_006c0a10;
    RefObj* puVar2 = (RefObj*)(uintptr_t)s[0xc];
    if (puVar2 != (RefObj*)0x0) {
        puVar2->refs = puVar2->refs - 1;
        if (puVar2->refs == 0) {
            release_ref(puVar2);
        }
        s[0xc] = 0;
    }
    FUN_00559000(self);
    puVar2 = (RefObj*)(uintptr_t)s[0xc];
    if (puVar2 != (RefObj*)0x0) {
        puVar2->refs = puVar2->refs - 1;
        if (puVar2->refs == 0) {
            release_ref(puVar2);
        }
    }
    FUN_00538400(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x539710 — observed shape
void FUN_00539710(int param_1) {
    uint32_t uVar1;
    int iVar2;

    iVar2 = param_1;
    FUN_005386f0(param_1);
    param_1 = FUN_00557b10(DAT_00727514);
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    return;
}

// 0x539760 — observed shape
void FUN_00539760(void* self) {
    DWORD DVar1;

    DVar1 = GetCurrentThreadId();
    if (DAT_007279c0 != (int)DVar1) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_007279a8);
        DAT_007279c0 = (int)DVar1;
    }
    DAT_007279c4 = DAT_007279c4 + 1;
    if (DAT_00727994 == 0) {
        DAT_00727994 = (int)(intptr_t)self;
    }
    if (DAT_00727998 == 0) {
        *(uint32_t*)((uint8_t*)self + 0x30) = 0;
    } else {
        *(int*)(DAT_00727998 + 0x34) = (int)(intptr_t)self;
        *(int*)((uint8_t*)self + 0x30) = DAT_00727998;
    }
    DAT_00727998 = (int)(intptr_t)self;
    *(uint32_t*)((uint8_t*)self + 0x34) = 0;
    DVar1 = GetCurrentThreadId();
    if ((DAT_007279c0 == (int)DVar1) &&
        (DAT_007279c4 = DAT_007279c4 + -1, DAT_007279c4 == 0)) {
        DAT_007279c0 = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_007279a8);
    }
    return;
}

// 0x5397f0 — observed shape
void FUN_005397f0(void* self) {
    DWORD DVar1;

    DVar1 = GetCurrentThreadId();
    if (DAT_007279c0 != (int)DVar1) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_007279a8);
        DAT_007279c0 = (int)DVar1;
    }
    DAT_007279c4 = DAT_007279c4 + 1;
    if (DAT_00727994 == (int)(intptr_t)self) {
        DAT_00727994 = *(int*)((uint8_t*)self + 0x34);
    }
    if (DAT_00727998 == (int)(intptr_t)self) {
        DAT_00727998 = *(int*)((uint8_t*)self + 0x30);
    }
    if (*(int*)((uint8_t*)self + 0x30) != 0) {
        *(uint32_t*)(*(int*)((uint8_t*)self + 0x30) + 0x34) =
            *(uint32_t*)((uint8_t*)self + 0x34);
    }
    if (*(int*)((uint8_t*)self + 0x34) != 0) {
        *(uint32_t*)(*(int*)((uint8_t*)self + 0x34) + 0x30) =
            *(uint32_t*)((uint8_t*)self + 0x30);
    }
    DVar1 = GetCurrentThreadId();
    if ((DAT_007279c0 == (int)DVar1) &&
        (DAT_007279c4 = DAT_007279c4 + -1, DAT_007279c4 == 0)) {
        DAT_007279c0 = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_007279a8);
    }
    return;
}

// 0x539890 — observed shape
uint32_t FUN_00539890(uint32_t* self, uint32_t in_EAX) {
    if (DAT_00727c30 != (int*)0x0) {
        auto fn = (uint32_t(__thiscall*)(int*))(*(void***)DAT_00727c30)[0x40];
        in_EAX = fn(DAT_00727c30);
        if ((uint8_t)in_EAX == 0) {
            return in_EAX;
        }
    }
    // Ghidra models the upper return bytes from register residue; low byte is 0/1.
    if ((DAT_0072751c != 0) && (self[0xb] != 0) && ((uint8_t)self[0x11] != 0)) {
        auto fn = (void(__thiscall*)(uint32_t*))(*(void***)self)[0x10];
        fn(self);
    }
    return 1;
}

// 0x5399a0 — observed shape
void FUN_005399a0(void* self, uint32_t param_1) {
    int iVar3;

    thunk_FUN_00540af0(param_1);
    iVar3 = FUN_00545630();
    if (iVar3 != 0) {
        RefObj* puVar4 = (RefObj*)FUN_00545600();
        RefObj* puVar2 = *(RefObj**)((uint8_t*)self + 0x40);
        if (puVar2 != puVar4) {
            if (puVar2 != (RefObj*)0x0) {
                puVar2->refs = puVar2->refs - 1;
                if (puVar2->refs == 0) {
                    release_ref(puVar2);
                }
            }
            *(RefObj**)((uint8_t*)self + 0x40) = puVar4;
            if (puVar4 != (RefObj*)0x0) {
                puVar4->refs = puVar4->refs + 1;
            }
        }
    }
    return;
}

// 0x539a60 — observed shape
uint8_t FUN_00539a60(void* self, uint32_t param_1) {
    char cVar1;
    uint8_t uVar2;

    cVar1 = thunk_FUN_00540b70(param_1);
    if (cVar1 == '\0') {
        return 0;
    }
    int* obj = *(int**)((uint8_t*)self + 0x40);
    if (obj == (int*)0x0) {
        return 1;
    }
    uVar2 = (*(uint8_t(__thiscall*)(int*, uint32_t))(*(void***)obj)[5])(obj, param_1);
    return uVar2;
}

// 0x539b70 — observed shape
void FUN_00539b70(void* self) {
    uint32_t* s = (uint32_t*)self;

    ((void**)self)[0] = (void*)&PTR_FUN_006c0a50;
    void* obj = (void*)(uintptr_t)s[0xb];
    if (obj != (void*)0x0) {
        auto fn = (void(__thiscall*)(void*, int))(*(void***)obj)[0];
        fn(obj, 1);
    }
    FUN_005397f0(self);
    FUN_00540c90(self);
    return;
}

// 0x539ba0 — observed shape
void FUN_00539ba0(void* self) {
    uint32_t* s = (uint32_t*)self;
    RefObj* puVar2;

    FUN_00540c50(self);
    ((void**)self)[0] = (void*)&PTR_FUN_006c0a50;
    s[8] = 6;
    s[9] = 2;
    s[10] = 3;
    s[0xb] = 0;
    FUN_00539760(self);
    ((void**)self)[0] = (void*)&PTR_FUN_006c0a90;
    s[0x10] = 0;
    s[0xe] = 0;
    s[0xf] = 0;
    puVar2 = (RefObj*)(uintptr_t)s[0x10];
    if (puVar2 != (RefObj*)0x0) {
        puVar2->refs = puVar2->refs - 1;
        if (puVar2->refs == 0) {
            release_ref(puVar2);
        }
        s[0x10] = 0;
    }
    *(uint8_t*)((uint8_t*)self + 0x44) = 1;
    return;
}

// 0x539c10 — observed shape
int* FUN_00539c10(char* param_1, int* param_2) {
    char cVar1;
    int iVar2;
    int* piVar3;
    char* pcVar4;

    iVar2 = (int)(intptr_t)FUN_00533c78(0x48);
    if (iVar2 == 0) {
        piVar3 = (int*)0x0;
    } else {
        piVar3 = (int*)(uintptr_t)iVar2;
        FUN_00539ba0(piVar3);
    }
    piVar3[8] = *param_2;
    piVar3[9] = param_2[1];
    piVar3[10] = param_2[2];
    pcVar4 = param_1;
    do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = (char*)FUN_00533c78(
        (size_t)(uintptr_t)(pcVar4 + (1 - (intptr_t)(param_1 + 1))));
    piVar3[0xe] = (int)(intptr_t)pcVar4;
    do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00497420(piVar3[0xe]);
    iVar2 = FUN_0054acf0(piVar3[0xe]);
    piVar3[0xf] = iVar2;
    if (DAT_007179a0 != '\0') {
        cVar1 = (*(char(__thiscall*)(int*))(*(void***)piVar3)[0x11])(piVar3);
        if (cVar1 == '\0') {
            (*(void(__thiscall*)(int*, int))(*(void***)piVar3)[0])(piVar3, 1);
            return (int*)0x0;
        }
    }
    return piVar3;
}

// 0x539cc0 — observed shape
int* FUN_00539cc0(uint32_t* param_1, int* param_2) {
    char cVar3;
    int iVar4;
    int* piVar5;
    RefObj* puVar2;

    iVar4 = (int)(intptr_t)FUN_00533c78(0x48);
    if (iVar4 == 0) {
        piVar5 = (int*)0x0;
    } else {
        piVar5 = (int*)(uintptr_t)iVar4;
        FUN_00539ba0(piVar5);
    }
    piVar5[8] = *param_2;
    piVar5[9] = param_2[1];
    piVar5[10] = param_2[2];
    puVar2 = (RefObj*)(uintptr_t)piVar5[0x10];
    RefObj* rp = (RefObj*)param_1;
    if (puVar2 != rp) {
        if (puVar2 != (RefObj*)0x0) {
            puVar2->refs = puVar2->refs - 1;
            if (puVar2->refs == 0) {
                release_ref(puVar2);
            }
        }
        piVar5[0x10] = (int)(intptr_t)rp;
        if (rp != (RefObj*)0x0) {
            rp->refs = rp->refs + 1;
        }
    }
    if (DAT_007179a0 != '\0') {
        cVar3 = (*(char(__thiscall*)(int*))(*(void***)piVar5)[0x11])(piVar5);
        if (cVar3 == '\0') {
            (*(void(__thiscall*)(int*, int))(*(void***)piVar5)[0])(piVar5, 1);
            return (int*)0x0;
        }
    }
    return piVar5;
}

// 0x53a0b0 — observed shape
void FUN_0053a0b0(void* self, uint8_t param_1) {
    uint32_t* s = (uint32_t*)self;

    ((void**)self)[0] = (void*)&PTR_FUN_006c0a50;
    void* obj = (void*)(uintptr_t)s[0xb];
    if (obj != (void*)0x0) {
        auto fn = (void(__thiscall*)(void*, int))(*(void***)obj)[0];
        fn(obj, 1);
    }
    FUN_005397f0(self);
    FUN_00540c90(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x53a0f0 — observed shape
void FUN_0053a0f0(void* self, uint8_t param_1) {
    FUN_0053a110(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}
