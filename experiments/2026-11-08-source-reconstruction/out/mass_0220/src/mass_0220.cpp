// Reconstruction batch mass_0220 — Sid Meier's Pirates! (2004), PE32 i386
#include <cstdint>
#include <cstddef>

extern int* DAT_00728e34;
extern void FUN_005cb660(int count);
extern void FUN_005cb7c0();
extern void* PTR_FUN_006c7d90;
extern void* PTR_FUN_006c7d60;
extern void FUN_005e1490();
extern void operator_delete__(void* p);
typedef void (*CallbackFn)(int);
typedef void (*CallbackFn0)();

// 0x5cb870 — observed shape
int* FUN_005cb870(int* param_1)
{
    int* piVar3 = DAT_00728e34;
    int* piVar1 = DAT_00728e34 + 2;
    if (DAT_00728e34[2] == 0) {
        int* piVar2 = DAT_00728e34 + 3;
        FUN_005cb660(DAT_00728e34[3]);
        *piVar2 = *piVar2 << 1;
    }
    piVar3 = (int*)*piVar3;
    int iVar4 = *piVar3;
    int iVar5 = *piVar1 + -1;
    *piVar1 = iVar5;
    *piVar3 = piVar3[iVar5];
    if (iVar4 != 0) {
        *(int*)(iVar4 + 100) = *(int*)(iVar4 + 100) + 1;
    }
    *(uint8_t*)(iVar4 + 0x61) = 1;
    *param_1 = iVar4;
    iVar5 = *(int*)(iVar4 + 100);
    *(int*)(iVar4 + 100) = iVar5 + 1;
    *(int*)(iVar4 + 100) = iVar5;
    if (iVar5 == 0) {
        FUN_005cb7c0();
    }
    return param_1;
}

// 0x5cb8e0 — observed shape
void FUN_005cb8e0(uint32_t param_1, uint32_t* param_2, uint32_t* param_3)
{
    switch (param_1) {
    case 0x46:
        *param_2 = 0x10;
        *param_3 = 0;
        return;
    case 0x47:
        *param_2 = 0x20;
        *param_3 = 0;
        return;
    default:
        *param_2 = 0;
        *param_3 = 0;
        return;
    case 0x49:
        *param_2 = 0xf;
        *param_3 = 1;
        return;
    case 0x4b:
        *param_2 = 0x18;
        *param_3 = 8;
        return;
    case 0x4d:
        *param_2 = 0x18;
        *param_3 = 0;
        return;
    case 0x4f:
        *param_2 = 0x18;
        *param_3 = 4;
        return;
    case 0x50:
        *param_2 = 0x10;
        *param_3 = 0;
        return;
    }
}

// 0x5cbce0 — observed shape
int32_t FUN_005cbce0(int32_t param_1)
{
    bool bVar1 = false;
    if (param_1 < 0x50) {
        if (param_1 != 0x4f) {
            switch (param_1) {
            case 0:
                return 0;
            default:
                return 0xffffffff;
            case 0x14:
                return 0x18;
            case 0x15:
            case 0x16:
            case 0x1f:
            case 0x20:
            case 0x21:
            case 0x23:
            case 0x3e:
            case 0x3f:
            case 0x40:
            case 0x43:
            case 0x47:
            case 0x4b:
            case 0x4d:
                break;
            case 0x17:
            case 0x18:
            case 0x19:
            case 0x1a:
            case 0x1d:
            case 0x1e:
            case 0x22:
            case 0x28:
            case 0x33:
            case 0x3c:
            case 0x3d:
            case 0x46:
            case 0x49:
                return 0x10;
            case 0x1b:
            case 0x1c:
            case 0x29:
            case 0x32:
            case 0x34:
                return 8;
            case 0x24:
                return 0x40;
            }
        }
        return 0x20;
    }
    if (param_1 < 0x75) {
        if (param_1 == 0x74) {
            return 0x80;
        }
        switch (param_1) {
        case 0x50:
        case 0x51:
        case 0x65:
        case 0x6f:
            return 0x10;
        case 0x52:
        case 0x53:
        case 0x66:
        case 0x70:
        case 0x72:
            return 0x20;
        default:
            return 0xffffffff;
        case 100:
            return 0;
        case 0x6e:
        case 0x71:
        case 0x73:
            return 0x40;
        }
    }
    if (param_1 < (int32_t)0x33545845) {
        if (param_1 == (int32_t)0x33545844) {
            return 0;
        }
        if (param_1 < (int32_t)0x31545845) {
            if (param_1 == (int32_t)0x31545844) {
                return 0;
            }
            if (param_1 == 0x75) {
                return 0x10;
            }
            bVar1 = (param_1 == (int32_t)0x3154454d);
        } else {
            if (param_1 == (int32_t)0x32545844) {
                return 0;
            }
            bVar1 = (param_1 == (int32_t)0x32595559);
        }
    } else if (param_1 < (int32_t)0x42475248) {
        if (param_1 == (int32_t)0x42475247) {
            return 0;
        }
        if (param_1 == (int32_t)0x34545844) {
            return 0;
        }
        bVar1 = (param_1 == (int32_t)0x35545844);
    } else {
        if (param_1 == (int32_t)0x47424752) {
            return 0;
        }
        bVar1 = (param_1 == (int32_t)0x59565955);
    }
    if (!bVar1) {
        return 0xffffffff;
    }
    return 0;
}

// 0x5cbe40 — observed shape
int32_t FUN_005cbe40(uint32_t param_1)
{
    switch (param_1) {
    default:
        return 0;
    case 0x14:
        return 1;
    case 0x15:
        return 2;
    case 0x16:
        return 3;
    case 0x17:
        return 4;
    case 0x18:
        return 5;
    case 0x19:
        return 6;
    case 0x1a:
        return 7;
    case 0x1b:
        return 8;
    case 0x1c:
        return 9;
    case 0x1d:
        return 10;
    case 0x1e:
        return 0xb;
    }
}

// 0x5cc020 — observed shape
void FUN_005cc020(void* self)
{
    uint8_t* base = (uint8_t*)self;
    int32_t** piVar1 = (int32_t**)(base + 8);
    uint32_t uVar3 = 0;
    int32_t* piVar6 = nullptr;
    if (*(uint32_t*)(base + 0xc) != 0) {
        int32_t** piVar6p = *(int32_t***)(base + 0x10);
        while (true) {
            if (*piVar6p != nullptr) {
                piVar6 = (*(int32_t***)(base + 0x10))[uVar3];
                break;
            }
            uVar3 = uVar3 + 1;
            piVar6p = piVar6p + 1;
            if (!(uVar3 < *(uint32_t*)(base + 0xc))) {
                piVar6 = nullptr;
                break;
            }
        }
    }
    while (true) {
        if (piVar6 == nullptr) {
            *piVar1 = (int32_t*)&PTR_FUN_006c7d90;
            FUN_005e1490();
            *piVar1 = (int32_t*)&PTR_FUN_006c7d60;
            FUN_005e1490();
            operator_delete__(*(void**)(base + 0x10));
            return;
        }
        int32_t* piVar7 = (int32_t*)*piVar6;
        uint32_t* puVar2 = (uint32_t*)piVar6[2];
        if (piVar7 == nullptr) {
            int32_t iVar4 = (*(int32_t(**)(int32_t))(*piVar1 + 4))(piVar6[1]);
            uVar3 = (uint32_t)(iVar4 + 1);
            if (uVar3 < *(uint32_t*)(base + 0xc)) {
                uint32_t* puVar5 = (uint32_t*)(*(int32_t*)(base + 0x10) + uVar3 * 4);
                while (true) {
                    piVar7 = (int32_t*)*puVar5;
                    if (piVar7 != nullptr) break;
                    uVar3 = uVar3 + 1;
                    puVar5 = puVar5 + 1;
                    if (!(uVar3 < *(uint32_t*)(base + 0xc))) {
                        piVar7 = nullptr;
                        break;
                    }
                }
            }
            else {
                piVar7 = nullptr;
            }
        }
        piVar6 = piVar7;
        if (puVar2 != nullptr) {
            (*(CallbackFn*)*puVar2)(1);
        }
    }
}

// ---- retry batch: 0x5cc0d0 .. 0x5cccb0 ----

typedef uint32_t (*VtblFn10)(int32_t* self);
typedef void (*VtblFn14)(int32_t* self, uint32_t a, int32_t b, uint32_t* out);
typedef uint32_t (*VtblFn18)(int32_t* self, uint32_t a, int32_t b);
typedef int32_t (*VtblFn1c)(int32_t* self, uint32_t a, int32_t b, uint32_t idx, int32_t* out);
typedef void (*VtblFn20)(int32_t* self, uint32_t a, uint32_t* out);
typedef int32_t (*VtblFn24)(int32_t* self, uint32_t a, uint32_t b, int32_t c, int32_t d, int32_t e);
typedef int32_t (*VtblFn28)(int32_t* self, uint32_t a, uint32_t b, uint32_t c, int32_t d, int32_t e, uint32_t f);
typedef int32_t (*VtblFn30)(int32_t* self, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
typedef int32_t (*VtblFn38)(int32_t* self, uint32_t a, uint32_t b, uint32_t* out);
typedef uint32_t* (*AllocFn)(void);
typedef void (*ReleaseFn)(int32_t* self, int32_t flag);
typedef void (*VtblDtorFn)(uint32_t* p);

extern void* PTR_FUN_006c7d88;
extern void* PTR_FUN_006c7d8c;
extern void* PTR_FUN_006c7dac;
extern void* PTR_LAB_006c7d7c;
extern void* PTR_LAB_0071199c;
extern void* PTR_FUN_00711b1c;
extern uint8_t DAT_00717cc8;
extern uint8_t DAT_005ccdbc;
extern uint64_t FUN_005cbce0(int32_t param_1);
extern int8_t FUN_005bd960(int32_t param_1, int32_t* param_2);
extern void FUN_005edba0(void);
extern void* FUN_00533c78(uint32_t size);
extern void* thunk_FUN_00533c78(uint32_t size);
extern uint32_t FUN_005bfdb0(uint32_t param_1);
extern void FUN_00545310(uint32_t param_1, void* param_2);
extern void FUN_006b34a0(uint32_t param_1);
extern void operator_delete(void* p);

// 0x5cc0d0 — observed shape
uint32_t FUN_005cc0d0(int32_t param_1, int32_t param_2, int32_t param_3)
{
    int8_t cVar5 = FUN_005bd960(param_1, &param_1);
    if (cVar5 == 0) {
        return 0;
    }
    uint8_t* puVar1 = *(uint8_t**)(param_1 + 4);
    uint32_t local_4 = 0;
    int32_t local_8 = 0;
    int32_t iVar3 = 0;
    int32_t iVar4 = param_2;
    while (puVar1 != nullptr) {
        uint32_t uVar2 = *(uint32_t*)(puVar1 + 8);
        puVar1 = *(uint8_t**)puVar1;
        int32_t local_c = 0;
        int32_t out1 = 0;
        FUN_005cb8e0(uVar2, (uint32_t*)&local_c, (uint32_t*)&out1);
        uint32_t uVar6 = (uint32_t)(local_c - iVar4);
        uint32_t uVar8 = (uint32_t)((int32_t)uVar6 >> 0x1f);
        uint32_t uVar7 = (uint32_t)(iVar3 - iVar4);
        uint32_t uVar9 = (uint32_t)((int32_t)uVar7 >> 0x1f);
        if ((int32_t)((uVar6 ^ uVar8) - uVar8) <= (int32_t)((uVar7 ^ uVar9) - uVar9)) {
            uint32_t dVar1 = (uint32_t)(out1 - param_3);
            uint32_t dVar2 = (uint32_t)(local_8 - param_3);
            uint32_t sVar1 = (uint32_t)((int32_t)dVar1 >> 0x1f);
            uint32_t sVar2 = (uint32_t)((int32_t)dVar2 >> 0x1f);
            if ((int32_t)((dVar1 ^ sVar1) - sVar1) <= (int32_t)((dVar2 ^ sVar2) - sVar2)) {
                iVar3 = local_c;
                local_4 = uVar2;
                local_8 = out1;
            }
        }
    }
    return local_4;
}

// 0x5cc1b0 — observed shape
uint32_t FUN_005cc1b0(void* self, char param_1, int32_t param_2)
{
    uint8_t* base = (uint8_t*)self;
    if (param_1 == '\0') {
        uint32_t* puVar3 = *(uint32_t**)(base + 0x138);
        if (puVar3 != nullptr) {
            do {
                uint32_t* puVar1 = (uint32_t*)puVar3[2];
                puVar3 = (uint32_t*)*puVar3;
                if ((puVar1 != nullptr) && (*(int8_t*)((uint8_t*)puVar1 + 5) != 0)) {
                    uint64_t uVar4 = FUN_005cbce0((int32_t)*puVar1);
                    // the recorded high half of the EDX:EAX return replaces the list cursor
                    puVar3 = (uint32_t*)(uintptr_t)((uint64_t)uVar4 >> 0x20);
                    if ((int32_t)uVar4 == param_2) {
                        return FUN_005cbe40(*puVar1);
                    }
                }
            } while (puVar3 != nullptr);
            return 0;
        }
    }
    else {
        uint32_t* puVar3 = *(uint32_t**)(base + 0x138);
        while (puVar3 != nullptr) {
            uint32_t* puVar1 = (uint32_t*)puVar3[2];
            puVar3 = (uint32_t*)*puVar3;
            if ((puVar1 != nullptr) && (*(int8_t*)(puVar1 + 1) != 0)) {
                return FUN_005cbe40(*puVar1);
            }
        }
    }
    return 0;
}

// 0x5cc240 — observed shape
uint32_t FUN_005cc240(void* self, int32_t param_1, uint32_t param_2, uint32_t param_3, int32_t param_4)
{
    uint8_t* base = (uint8_t*)self;
    uint32_t* puVar2 = *(uint32_t**)(base + 0x138);
    int32_t* piVar1;
    do {
        if (puVar2 == nullptr) {
            return 0;
        }
        piVar1 = (int32_t*)(puVar2 + 2);
        puVar2 = (uint32_t*)*puVar2;
    } while ((*piVar1 == 0) || (*(int32_t*)*piVar1 != param_1));
    if (param_4 != 0) {
        if (param_3 < 0x11) {
            if (param_4 == 1) {
                return FUN_005cc0d0((int32_t)param_2, 0xf, 1);
            }
            return FUN_005cc0d0((int32_t)param_2, 0x18, 8);
        }
        param_3 = 0x18;
        if (param_4 != 1) {
            return FUN_005cc0d0((int32_t)param_2, 0x18, 8);
        }
    }
    return FUN_005cc0d0((int32_t)param_2, (int32_t)param_3, param_4);
}

// 0x5cc2e0 — observed shape
int32_t FUN_005cc2e0(void* self, int32_t param_1)
{
    uint8_t* base = (uint8_t*)self;
    if (param_1 == 0) {
        return 0;
    }
    int32_t* piVar3 = (int32_t*)**(int32_t***)(base + 0x14);
    uint32_t uVar2 = (uint32_t)((*(int32_t**)(base + 0x14))[2] - param_1);
    uint32_t uVar4 = (uint32_t)((int32_t)uVar2 >> 0x1f);
    uVar4 = (uVar2 ^ uVar4) - uVar4;
    if (piVar3 == nullptr) {
        return param_1;
    }
    do {
        int32_t* piVar1 = piVar3 + 2;
        piVar3 = (int32_t*)*piVar3;
        uVar2 = (uint32_t)(*piVar1 - param_1);
        uint32_t uVar5 = (uint32_t)((int32_t)uVar2 >> 0x1f);
        uVar5 = (uVar2 ^ uVar5) - uVar5;
        if (uVar5 < uVar4) {
            param_1 = *piVar1;
            uVar4 = uVar5;
        }
    } while (piVar3 != nullptr);
    return param_1;
}

// 0x5cc340 — observed shape
void FUN_005cc340(void* self)
{
    uint8_t* base = (uint8_t*)self;
    uint32_t* puVar1 = *(uint32_t**)(base + 0x138);
    while (puVar1 != nullptr) {
        void* pvVar2 = (void*)puVar1[2];
        puVar1 = (uint32_t*)*puVar1;
        if (pvVar2 != nullptr) {
            // the listing shows no explicit receiver: ECX still holds the entry self
            FUN_005cc020(self);
            operator_delete(pvVar2);
        }
    }
    *(void**)(base + 0x134) = (void*)&PTR_FUN_006c7dac;
    FUN_005edba0();
    *(void**)(base + 0x134) = (void*)&PTR_LAB_006c7d7c;
}

// 0x5cc390 — observed shape
void FUN_005cc390(void* self, uint32_t* param_1)
{
    uint32_t* ctx = (uint32_t*)self;
    ctx[0] = param_1[0];
    ctx[1] = param_1[1];
    ctx[3] = param_1[3];
    ctx[7] = 0;
    ctx[5] = 0;
    ctx[6] = 0;
    ctx[4] = (uint32_t)&PTR_FUN_00711b1c;
    uint32_t* puVar1 = (*(AllocFn)(ctx[4] + 4))();
    puVar1[2] = param_1[2];
    puVar1[1] = 0;
    *puVar1 = ctx[5];
    if (ctx[5] == 0) {
        ctx[6] = (uint32_t)puVar1;
    }
    else {
        *(uint32_t*)(ctx[5] + 4) = (uint32_t)puVar1;
    }
    ctx[5] = (uint32_t)puVar1;
    ctx[7] = ctx[7] + 1;
    uint32_t uVar2 = (uint32_t)FUN_005cbce0((int32_t)param_1[3]);
    ctx[2] = uVar2;
}

// 0x5cc410 — observed shape
int32_t* FUN_005cc410(void* self, int32_t param_1, int32_t param_2, int32_t param_3, uint32_t* param_4)
{
    uint8_t* base = (uint8_t*)self;
    int32_t* piVar3 = nullptr;
    uint32_t uVar4 = 0;
    if (*(int32_t*)(base + 0x45c) != 0) {
        do {
            int32_t* piVar1 = *(int32_t**)(*(int32_t*)(base + 0x454) + uVar4 * 4);
            if ((piVar1 != nullptr) && (piVar1[3] == param_1) && (*piVar1 == param_2) &&
                (piVar1[1] == param_3)) {
                uint32_t uVar2 = (uint32_t)FUN_005cc2e0((void*)base, (int32_t)*param_4);
                *param_4 = uVar2;
                piVar3 = piVar1;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint32_t*)(base + 0x45c));
    }
    return piVar3;
}

// 0x5cc480 — observed shape
uint32_t* FUN_005cc480(void* self, int32_t* param_1, uint32_t param_2, uint32_t param_3,
                       uint32_t param_4, uint8_t param_5, uint8_t param_6)
{
    uint32_t* ctx = (uint32_t*)self;
    ctx[2] = (uint32_t)&PTR_FUN_006c7d60;
    ctx[3] = 0x25;
    ctx[5] = 0;
    uint32_t* puVar2 = (uint32_t*)thunk_FUN_00533c78(0x94);
    ctx[4] = (uint32_t)puVar2;
    for (uint32_t uVar5 = ctx[3] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    // decompiler tail loop with a zero trip count
    for (int32_t iVar6 = 0; iVar6 != 0; iVar6 = iVar6 - 1) {
        *(uint8_t*)puVar2 = 0;
        puVar2 = (uint32_t*)((uint8_t*)puVar2 + 1);
    }
    ctx[2] = (uint32_t)&PTR_FUN_006c7d90;
    *ctx = param_4;
    *(uint8_t*)((uint8_t*)ctx + 5) = param_5;
    *(uint8_t*)(ctx + 1) = param_6;
    uint32_t idx = 0;
    do {
        if (idx != 0) {
            uint32_t uVar3 = FUN_005bfdb0(idx);
            int32_t iVar6 = (*(VtblFn28)(*param_1 + 0x28))(param_1, param_2, param_3, param_4,
                                                           1, 1, uVar3);
            if (-1 < iVar6) {
                int32_t* piVar4 = (int32_t*)FUN_00533c78(0x10);
                int32_t* piVar7 = nullptr;
                if (piVar4 != nullptr) {
                    piVar4[3] = 0;
                    piVar4[1] = 0;
                    piVar4[2] = 0;
                    *piVar4 = (int32_t)&PTR_FUN_00711b1c;
                    piVar7 = piVar4;
                }
                uint32_t uVar5 = 0;
                do {
                    uint32_t uVar1 = *(uint32_t*)((uint8_t*)&DAT_00717cc8 + uVar5);
                    iVar6 = (*(VtblFn28)(*param_1 + 0x28))(param_1, param_2, param_3, param_4,
                                                            2, 1, uVar1);
                    if (-1 < iVar6) {
                        iVar6 = (*(VtblFn30)(*param_1 + 0x30))(param_1, param_2, param_3, param_4,
                                                               uVar3, uVar1);
                        if (-1 < iVar6) {
                            puVar2 = (*(AllocFn)(*piVar7 + 4))();
                            puVar2[2] = uVar1;
                            *puVar2 = 0;
                            puVar2[1] = (uint32_t)piVar7[2];
                            if ((int32_t*)piVar7[2] == nullptr) {
                                piVar7[1] = (int32_t)puVar2;
                            }
                            else {
                                *(uint32_t*)(piVar7[2]) = (uint32_t)puVar2;
                            }
                            piVar7[2] = (int32_t)puVar2;
                            piVar7[3] = piVar7[3] + 1;
                        }
                    }
                    uVar5 = uVar5 + 4;
                } while (uVar5 < 0x1c);
                if (piVar7[3] == 0) {
                    (*(ReleaseFn)(*piVar7))(piVar7, 1);
                }
                else {
                    FUN_00545310(uVar3, piVar7);
                }
            }
        }
        idx = idx + 1;
    } while (idx < 0xc);
    return ctx;
}

// 0x5cc610 — observed shape
uint32_t* FUN_005cc610(void* self, int32_t* param_1, uint32_t param_2, uint32_t param_3,
                       int32_t param_4)
{
    uint32_t* ctx = (uint32_t*)self;
    int32_t* piVar1 = param_1;
    *ctx = param_3;
    ctx[0x50] = 0;
    ctx[0x4e] = 0;
    ctx[0x4f] = 0;
    ctx[0x4d] = (uint32_t)&PTR_FUN_006c7dac;
    int32_t iVar3 = (*(VtblFn38)(*param_1 + 0x38))(param_1, param_2, *ctx, ctx + 1);
    if (iVar3 < 0) {
        ctx[1] = 0;
    }
    else {
        int32_t* piVar4 = (int32_t*)param_1[1];
        if (piVar4 != nullptr) {
            do {
                int32_t* piVar2 = (int32_t*)*piVar4;
                int32_t iVar7node = piVar4[2];
                if (iVar7node != 0) {
                    uint32_t uVar5 = (*(VtblFn18)(*piVar1 + 0x18))(piVar1, param_2, iVar7node);
                    uint32_t uStack_c = 0;
                    if (uVar5 != 0) {
                        do {
                            int32_t local_20[4] = {0, 0, 0, 0}; // listing leaves this buffer unwritten
                            uint8_t uStack_10 = 0;
                            uint32_t flag_a = 0;
                            uint32_t flag_b = 0;
                            flag_b = flag_b & 0xffffff00;
                            flag_a = flag_a & 0xffffff00;
                            int32_t iVar6 = (*(VtblFn1c)(*piVar1 + 0x1c))(piVar1, param_2, iVar7node,
                                                                         uStack_c, local_20);
                            if (-1 < iVar6) {
                                (*(VtblFn24)(*piVar1 + 0x24))(piVar1, param_2, (uint32_t)local_20[0],
                                                              iVar7node, iVar7node, 0);
                                uStack_10 = 1;
                            }
                            int32_t iVar7b = (*(VtblFn24)(*piVar1 + 0x24))(piVar1, param_2,
                                                                          (uint32_t)local_20[0],
                                                                          local_20[3], iVar7node, 1);
                            if (-1 < iVar7b) {
                                flag_b = (flag_b & 0xffffff00) | 1;
                            }
                            if ((-1 < iVar6) || ((uint8_t)flag_b != 0)) {
                                uint32_t* puVar9 = (uint32_t*)ctx[0x4e];
                                while (true) {
                                    if (puVar9 == nullptr) {
                                        int32_t iVar6b = (int32_t)(uintptr_t)FUN_00533c78(0x18);
                                        uint32_t uVar8;
                                        if (iVar6b == 0) {
                                            uVar8 = 0;
                                        }
                                        else {
                                            uVar8 = (uint32_t)FUN_005cc480((void*)(uintptr_t)iVar6b,
                                                                           piVar1, param_2, *ctx,
                                                                           (uint32_t)local_20[3],
                                                                           (uint8_t)flag_a,
                                                                           (uint8_t)flag_b);
                                        }
                                        uint32_t* puVar9n = (*(AllocFn)(ctx[0x4d] + 4))();
                                        puVar9n[2] = uVar8;
                                        *puVar9n = 0;
                                        puVar9n[1] = ctx[0x4f];
                                        if (ctx[0x4f] == 0) {
                                            ctx[0x4e] = (uint32_t)puVar9n;
                                        }
                                        else {
                                            *(uint32_t*)(ctx[0x4f]) = (uint32_t)puVar9n;
                                        }
                                        ctx[0x4f] = (uint32_t)puVar9n;
                                        ctx[0x50] = ctx[0x50] + 1;
                                        break;
                                    }
                                    int32_t** payload = (int32_t**)(puVar9 + 2);
                                    puVar9 = (uint32_t*)*puVar9;
                                    if ((*payload != nullptr) &&
                                        (*(int32_t*)*payload == local_20[3])) {
                                        break;
                                    }
                                }
                            }
                            uStack_c = uStack_c + 1;
                            (void)uStack_10;
                        } while (uStack_c < uVar5);
                    }
                }
                if (piVar2 == nullptr) break;
                piVar4 = piVar2;
            } while (true);
        }
    }
    int32_t* entry = nullptr;
    uint32_t* scan = (uint32_t*)ctx[0x4e];
    while (scan != nullptr) {
        int32_t** payload = (int32_t**)(scan + 2);
        scan = (uint32_t*)*scan;
        if (*(int32_t*)*payload == param_4) {
            entry = (int32_t*)*payload;
            break;
        }
    }
    if ((entry != nullptr) && ((int8_t)entry[1] != 0)) {
        *((uint8_t*)ctx + 0x144) = 1;
        return ctx;
    }
    *((uint8_t*)ctx + 0x144) = 0;
    return ctx;
}

// 0x5cc820 — observed shape
void FUN_005cc820(void* self, int32_t* param_1, uint32_t param_2, int32_t* param_3)
{
    uint32_t* ctx = (uint32_t*)self;
    *ctx = param_2;
    ctx[0x114] = (uint32_t)&PTR_FUN_006c7d88;
    ctx[0x116] = 0x20;
    ctx[0x119] = 0x10;
    ctx[0x117] = 0;
    ctx[0x118] = 0;
    uint32_t uVar2 = (uint32_t)thunk_FUN_00533c78(0x80);
    ctx[0x115] = uVar2;
    (*(VtblFn14)(*param_1 + 0x14))(param_1, *ctx, 0, ctx + 1);
    int32_t* piVar8 = (int32_t*)param_3[1];
    if (piVar8 != nullptr) {
        do {
            int32_t iVar7 = piVar8[2];
            piVar8 = (int32_t*)*piVar8;
            if (iVar7 != 0) {
                uint32_t uVar3 = (*(VtblFn18)(*param_1 + 0x18))(param_1, *ctx, iVar7);
                uint32_t uVar11 = 0;
                if (uVar3 != 0) {
                    do {
                        int32_t stack_30[4] = {0, 0, 0, 0};
                        int32_t iVar4 = (*(VtblFn1c)(*param_1 + 0x1c))(param_1, *ctx, iVar7,
                                                                      uVar11, stack_30);
                        if (-1 < iVar4) {
                            int32_t* piVar10 = nullptr;
                            uint32_t uVar9 = 0;
                            if (ctx[0x117] != 0) {
                                do {
                                    int32_t* piVar1 = *(int32_t**)(ctx[0x115] + uVar9 * 4);
                                    if (piVar1 != nullptr) {
                                        if ((piVar1[3] == iVar7) && (*piVar1 == stack_30[0]) &&
                                            (piVar1[1] == stack_30[1])) {
                                            uint32_t* puVar5 = (*(AllocFn)(piVar1[4] + 4))();
                                            puVar5[2] = (uint32_t)stack_30[2];
                                            *puVar5 = 0;
                                            puVar5[1] = (uint32_t)piVar1[6];
                                            if ((uint32_t*)piVar1[6] == nullptr) {
                                                piVar1[5] = (int32_t)puVar5;
                                            }
                                            else {
                                                *(uint32_t*)(piVar1[6]) = (uint32_t)puVar5;
                                            }
                                            piVar1[6] = (int32_t)puVar5;
                                            piVar1[7] = piVar1[7] + 1;
                                            piVar10 = piVar1;
                                        }
                                    }
                                    uVar9 = uVar9 + 1;
                                } while (uVar9 < ctx[0x117]);
                            }
                            if (piVar10 == nullptr) {
                                int32_t iVar6 = (int32_t)(uintptr_t)FUN_00533c78(0x20);
                                if (iVar6 == 0) {
                                    iVar6 = 0;
                                }
                                else {
                                    iVar6 = (int32_t)(uintptr_t)FUN_005cc390(
                                        (void*)(uintptr_t)iVar6, (uint32_t*)stack_30);
                                }
                                uint32_t uVar9b = ctx[0x117];
                                if ((uVar9b < ctx[0x116]) ||
                                    (FUN_006b34a0(ctx[0x119] + uVar9b), uVar9b < ctx[0x116])) {
                                    if (uVar9b < ctx[0x117]) {
                                        if (iVar6 == 0) {
                                            if (*(int32_t*)(ctx[0x115] + uVar9b * 4) != 0) {
                                                ctx[0x118] = ctx[0x118] - 1;
                                            }
                                        }
                                        else if (*(int32_t*)(ctx[0x115] + uVar9b * 4) == 0) {
                                            ctx[0x118] = ctx[0x118] + 1;
                                        }
                                    }
                                    else {
                                        ctx[0x117] = uVar9b + 1;
                                        if (iVar6 != 0) {
                                            ctx[0x118] = ctx[0x118] + 1;
                                        }
                                    }
                                    *(int32_t*)(ctx[0x115] + uVar9b * 4) = iVar6;
                                }
                            }
                        }
                        uVar11 = uVar11 + 1;
                    } while (uVar11 < uVar3);
                }
            }
        } while (piVar8 != nullptr);
    }
    uint32_t auStack_20[4] = {0, 0, 0, 0};
    (*(VtblFn20)(*param_1 + 0x20))(param_1, *ctx, auStack_20);
    int32_t iVar7a = (int32_t)(uintptr_t)FUN_00533c78(0x148);
    if (iVar7a == 0) {
        uVar2 = 0;
    }
    else {
        // the caller also pushes a trailing flag; the callee listing does not consume it
        uVar2 = (uint32_t)FUN_005cc610((void*)(uintptr_t)iVar7a, param_1, param_2, 1,
                                       (int32_t)auStack_20[0]);
    }
    ctx[0x11a] = uVar2;
    int32_t iVar7b = (int32_t)(uintptr_t)FUN_00533c78(0x148);
    if (iVar7b == 0) {
        ctx[0x11b] = 0;
        return;
    }
    uVar2 = (uint32_t)FUN_005cc610((void*)(uintptr_t)iVar7b, param_1, param_2, 2,
                                   (int32_t)auStack_20[0]);
    ctx[0x11b] = uVar2;
}

// 0x5ccaa0 — observed shape
void FUN_005ccaa0(void* self)
{
    uint8_t* base = (uint8_t*)self;
    uint32_t local_8 = 0;
    if (*(int32_t*)(base + 0x45c) != 0) {
        do {
            void* pvVar2 = *(void**)(*(int32_t*)(base + 0x454) + local_8 * 4);
            if (pvVar2 != nullptr) {
                int32_t* piVar1 = (int32_t*)((uint8_t*)pvVar2 + 0x10);
                *piVar1 = (int32_t)&PTR_FUN_00711b1c;
                uint32_t* puVar4 = *(uint32_t**)((uint8_t*)pvVar2 + 0x14);
                while (puVar4 != nullptr) {
                    uint32_t* puVar3 = (uint32_t*)*puVar4;
                    (*(VtblDtorFn)(*piVar1 + 8))(puVar4);
                    puVar4 = puVar3;
                }
                *(uint32_t*)((uint8_t*)pvVar2 + 0x1c) = 0;
                *(uint32_t*)((uint8_t*)pvVar2 + 0x14) = 0;
                *(uint32_t*)((uint8_t*)pvVar2 + 0x18) = 0;
                *piVar1 = (int32_t)&PTR_LAB_0071199c;
                operator_delete(pvVar2);
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint32_t*)(base + 0x45c));
    }
    void* pvVar2 = *(void**)(base + 0x468);
    if (pvVar2 != nullptr) {
        // the listing shows no explicit receiver: ECX still holds the entry self
        FUN_005cc340(self);
        operator_delete(pvVar2);
    }
    pvVar2 = *(void**)(base + 0x46c);
    if (pvVar2 != nullptr) {
        FUN_005cc340(self);
        operator_delete(pvVar2);
    }
    *(void**)(base + 0x450) = (void*)&PTR_FUN_006c7d88;
    operator_delete__(*(void**)(base + 0x454));
}

// 0x5ccb80 — observed shape
void FUN_005ccb80(void* self, int32_t* param_1)
{
    uint32_t* ctx = (uint32_t*)self;
    uint32_t uVar1 = (*(VtblFn10)(*param_1 + 0x10))(param_1);
    *ctx = uVar1;
    FUN_006b34a0(uVar1);
    uVar1 = 0;
    if (*ctx != 0) {
        do {
            int32_t iVar2 = (int32_t)(uintptr_t)FUN_00533c78(0x470);
            if (iVar2 == 0) {
                iVar2 = 0;
            }
            else {
                iVar2 = (int32_t)(uintptr_t)FUN_005cc820((void*)(uintptr_t)iVar2, param_1, uVar1,
                                                         param_1);
            }
            if (uVar1 < ctx[3]) {
                if (uVar1 < ctx[4]) {
                    if (iVar2 == 0) {
                        if (*(int32_t*)(ctx[2] + uVar1 * 4) != 0) {
                            ctx[5] = ctx[5] - 1;
                        }
                    }
                    else if (*(int32_t*)(ctx[2] + uVar1 * 4) == 0) {
                        ctx[5] = ctx[5] + 1;
                    }
                }
                else {
                    ctx[4] = uVar1 + 1;
                    if (iVar2 != 0) {
                        ctx[5] = ctx[5] + 1;
                    }
                }
                *(int32_t*)(ctx[2] + uVar1 * 4) = iVar2;
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < *ctx);
    }
}

// 0x5ccc20 — observed shape
void FUN_005ccc20(void* self, int32_t* param_1, uint32_t param_2)
{
    uint32_t* ctx = (uint32_t*)self;
    ctx[3] = 0;
    ctx[4] = 0;
    ctx[5] = 0;
    ctx[2] = 0;
    ctx[1] = (uint32_t)&PTR_FUN_006c7d8c;
    ctx[6] = 1;
    *ctx = 0;
    // the caller also pushes param_2; the callee listing does not consume it
    FUN_005ccb80(self, param_1);
}

// 0x5ccc60 — observed shape
void FUN_005ccc60(void* self)
{
    uint8_t* base = (uint8_t*)self;
    uint32_t uVar2 = 0;
    if (*(int32_t*)(base + 0x10) != 0) {
        do {
            void* pvVar1 = *(void**)(*(int32_t*)(base + 8) + uVar2 * 4);
            if (pvVar1 != nullptr) {
                // the listing shows no explicit receiver: ECX still holds the entry self
                FUN_005ccaa0(self);
                operator_delete(pvVar1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(base + 0x10));
    }
    *(void**)(base + 4) = (void*)&PTR_FUN_006c7d8c;
    operator_delete__(*(void**)(base + 8));
}

// 0x5cccb0 — observed shape
int32_t FUN_005cccb0(uint32_t param_1, uint32_t* param_2, int32_t param_3)
{
    uint32_t uVar1 = param_2[2];
    uint32_t uVar3 = *param_2;
    if (uVar3 == 6) {
        uVar3 = 2;
    }
    else if (uVar3 == 0) {
        if ((uVar1 == 3) || (uVar1 == 0)) {
            if (*(int32_t*)(param_3 + 0x18) != 0) {
                return *(int32_t*)(param_3 + 0x18);
            }
        }
        else if (((uVar1 == 1) || (uVar1 == 2)) && (*(int32_t*)(param_3 + 0x1c) != 0)) {
            return *(int32_t*)(param_3 + 0x1c);
        }
    }
    else if (3 < uVar3) {
        return 0;
    }
    // NEEDS_MANUAL: the four jump-table targets at 0x005ccdbc are not present in the corpus;
    // only the indirect dispatch through the table is recorded.
    int32_t (*target)(uint32_t, uint32_t*, int32_t) =
        (int32_t (*)(uint32_t, uint32_t*, int32_t)) * (void**)((uint8_t*)&DAT_005ccdbc + uVar3 * 4);
    return target(param_1, param_2, param_3);
}
