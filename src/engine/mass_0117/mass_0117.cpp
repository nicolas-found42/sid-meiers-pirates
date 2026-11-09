#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <windows.h>

extern uint32_t DAT_008ed4c0;
extern uint32_t DAT_008ed4bc;
extern uint32_t* DAT_008ecd7c;
extern uint32_t DAT_00727080;
extern uint32_t DAT_008ecd78;
extern uint32_t DAT_007187f8;
extern uint32_t DAT_008ed5bc;
extern uint32_t DAT_006c062c;
extern float FUN_00532230();
extern float FUN_0052c130();
extern void FUN_0052c690(void* a, uint32_t b, void* c);
extern int FUN_005f0ddc();
extern void* FUN_00531bb0(void* out, uint32_t a, float b);
extern void FUN_00491640();
extern void FUN_00533b9d();
extern int FUN_004abab0();
extern int _callnewh(size_t n);
extern uint32_t FUN_005281c0();
extern uint32_t FUN_005285f0(void* a, uint32_t b, uint32_t c);
extern void* thunk_FUN_00533c78(size_t n);
extern void operator_delete__(void* p);
extern uint32_t FUN_00533ac0(uint32_t a, uint32_t b, uint32_t c);

// 0x532810 — observed shape
float FUN_00532810(void* self_param) {
    uint8_t* self = (uint8_t*)self_param;
    float fVar6 = FUN_00532230();
    float fVar2 = fVar6;
    float fVar4 = *(float*)(self + 0x70) * *(float*)(self + 0x70);
    float fVar5 = *(float*)(self + 0x74) * *(float*)(self + 0x74);
    float fVar6b;
    if (fVar2 <= fVar5) {
        if ((std::isnan(fVar2) || std::isnan(fVar4) || (fVar2 < fVar4) >= (fVar2 == fVar4) && (fVar2 < fVar4 || fVar2 == fVar4)) &&
            (fVar6b = (float)fVar5 - (float)fVar4, fVar6b != 0.0f)) {
            fVar6b = *(float*)(self + 0x78) - ((float)fVar2 - (float)fVar4) / fVar6b;
        }
        else {
            fVar6b = *(float*)(self + 0x78);
        }
    }
    else {
        fVar6b = 0.0f;
    }
    float fVar7;
    int iVar3;
    uint32_t b0 = *(uint32_t*)(self + 0xb0);
    bool useOne;
    if ((b0 == 0) || (iVar3 = (int)*(int*)(*(uint32_t*)(self + 0xb0) + 8), iVar3 < 0) ||
        (DAT_008ed4c0 <= (uint32_t)iVar3)) {
        useOne = true;
    }
    else {
        float* pfVar1 = (float*)(DAT_008ed4bc + (uint32_t)iVar3 * 8);
        if (pfVar1 == nullptr) useOne = true;
        else {
            useOne = false;
            fVar7 = *pfVar1;
            if (pfVar1[1] != 0.0f) {
                float extraout = FUN_0052c130();
                return fVar7 * extraout * *(float*)(self + 0x84) * fVar6b;
            }
        }
    }
    if (useOne) fVar7 = 1.0f;
    return fVar7 * *(float*)(self + 0x84) * fVar6b;
}

// 0x5328f0 — observed shape
void FUN_005328f0(void* self_param) {
    uint8_t* self = (uint8_t*)self_param;
    uint32_t iVar1 = *DAT_008ecd7c;
    if (*(char*)(self + 0x18) == '\0') {
        float fVar2 = FUN_00532810(self_param);
        (*(void(**)(int, uint32_t, float))*(uint32_t*)(iVar1 + 0x60))(1, *(uint32_t*)(self + 0xc), fVar2);
        return;
    }
    float fVar2 = FUN_00532810(self_param);
    (*(void(**)(int, uint32_t, float))*(uint32_t*)(iVar1 + 0x60))(3, *(uint32_t*)(self + 0x10), fVar2);
    return;
}

// 0x532960 — observed shape
void FUN_00532960(void* self_param) {
    uint32_t* self = (uint32_t*)self_param;
    if (self[0x2c] == 0) return;
    (*(void(**)())*(uint32_t*)(*self + 0x104))();
    (*(void(**)())*(uint32_t*)(*self + 0x108))();
    (*(void(**)())*(uint32_t*)(*self + 0xfc))();
    (*(void(**)())*(uint32_t*)(*self + 0x100))();
    return;
}

// 0x532c60 — observed shape
void FUN_00532c60(void* self_param) {
    uint32_t* self = (uint32_t*)self_param;
    float fStack_34=0, fStack_30=0, fStack_2c=0, fStack_28=0, fStack_24=0, fStack_20=0;
    float fStack_1c=0, fStack_18=0, fStack_14=0, fStack_10=0, fStack_c=0, fStack_8=0;
    if ((*(void**(void*, uint32_t))*(uint32_t*)(*(uint32_t*)self + 0x94))(self, 4) == '\0') {
        uint32_t iVar7 = DAT_00727080 * 0x343fd + 0x269ec3;
        DAT_00727080 = iVar7;
        int iVar3 = FUN_005f0ddc();
        DAT_00727080 = iVar7 * 0x343fd + 0x269ec3;
        int iVar3b = *(int*)(self[0x2c] + 0x38) - iVar3;
        uint32_t iVar7b = self[0x2c];
        int iVar4 = FUN_005f0ddc();
        float fVar1 = (float)iVar3b;
        int iVar4b = *(int*)(iVar7b + 0x30) - iVar4;
        float fVar9 = fVar1;
        float* pfVar5 = (float*)FUN_00531bb0(&fStack_1c, *(uint32_t*)(iVar7b + 0x28), fVar1);
        fStack_34 = *pfVar5; fStack_30 = pfVar5[1]; fStack_2c = pfVar5[2];
        pfVar5 = (float*)FUN_00531bb0(&fStack_1c, *(uint32_t*)(self[0x2c] + 0x2c), fVar1);
        fStack_28 = *pfVar5; fStack_24 = pfVar5[1]; fStack_20 = pfVar5[2];
        fStack_1c = fStack_28 - fStack_34;
        fStack_18 = fStack_24 - fStack_30;
        fStack_14 = fStack_20 - fStack_2c;
        fStack_10 = fStack_1c; fStack_c = fStack_18; fStack_8 = fStack_14;
        FUN_00491640();
        uint32_t iVar7c = (*(uint32_t(*)())*(uint32_t*)(DAT_008ecd78 + 0x38))();
        if (iVar7c == 0) {
            fStack_1c = 0.0f; self[0xf] = 0; fStack_18 = 0.0f; fStack_14 = 0.0f; self[0x10] = 0; self[0x11] = 0;
        }
        else {
            uint32_t* piVar6 = (uint32_t*)(*(uint32_t(**)(uint32_t, float, int))*(uint32_t*)(DAT_008ecd78 + 0x38))(4, fVar9, iVar4b);
            (*(void(**)(void*))*(uint32_t*)(*piVar6 + 0x20))(&fStack_28);
            fStack_1c = fStack_34 - fStack_28;
            self[0xf] = (int)fStack_1c;
            fStack_18 = fStack_30 - fStack_24;
            self[0x10] = (int)fStack_18;
            fStack_14 = fStack_2c - fStack_20;
            self[0x11] = (int)fStack_14;
        }
        (*(void(**)(void*))*(uint32_t*)(*(uint32_t*)self + 0xc0))(&fStack_34);
        (*(void(**)(float))*(uint32_t*)(*(uint32_t*)self + 0xcc))((float)(int)fVar9);
        fStack_24 = 0.0f; fStack_20 = 0.0f; fStack_1c = 1.0f;
        (*(void(**)(void*, void*))*(uint32_t*)(*(uint32_t*)self + 0xe4))(&fStack_18, &fStack_24);
    }
    return;
}

// 0x532ed0 — observed shape
void FUN_00532ed0(void* self_param, float unaff_retaddr) {
    uint32_t* self = (uint32_t*)self_param;
    float fStack_1c = 5.60519e-45f;
    float fStack_18=0, fStack_14=0, fStack_10=0, fStack_c=0, fStack_8=0;
    if ((*(char(*)())*(uint32_t*)(*(uint32_t*)self + 0x94))() == '\0') {
        uint32_t iVar4 = (*(uint32_t(*)())*(uint32_t*)(DAT_008ecd78 + 0x38))();
        float fVar1 = (float)self[0x12];
        float fVar2 = fVar1 * (float)self[0x14];
        if (iVar4 == 0) {
            fStack_14 = fVar1 * (float)self[0x15] * unaff_retaddr;
            fStack_10 = fVar1 * (float)self[0x13] * unaff_retaddr + (float)self[9];
            fStack_c = fVar2 * unaff_retaddr + (float)self[10];
            fStack_8 = fStack_14 + (float)self[0xb];
        }
        else {
            fStack_14 = fVar1 * (float)self[0x15];
            fStack_8 = fStack_14 * unaff_retaddr;
            self[0xf] = (int)(fVar1 * (float)self[0x13] * unaff_retaddr + (float)self[0xf]);
            self[0x10] = (int)(fVar2 * unaff_retaddr + (float)self[0x10]);
            self[0x11] = (int)(fStack_8 + (float)self[0x11]);
            fStack_18 = fVar2;
            uint32_t* piVar5 = (uint32_t*)(*(uint32_t(*)())*(uint32_t*)(DAT_008ecd78 + 0x38))();
            (*(void(**)(void*))*(uint32_t*)(*piVar5 + 0x20))(&fStack_1c);
            fStack_10 = fStack_1c + (float)self[0xf];
            fStack_c = fStack_18 + (float)self[0x10];
            fStack_8 = fStack_14 + (float)self[0x11];
        }
        (*(void(**)(void*))*(uint32_t*)(*(uint32_t*)self + 0xc0))(&fStack_10);
    }
    return;
}

// 0x5332f0 — observed shape
float FUN_005332f0(void* self_param) {
    uint32_t* self = (uint32_t*)self_param;
    if ((*(char(*)())*(uint32_t*)(*(uint32_t*)self + 0x40))() == '\0') {
        return (float)self[0x32];
    }
    return 0.0f;
}

// 0x5333e0 — observed shape
void FUN_005333e0(void* self_param, float unaff_retaddr) {
    uint32_t* self = (uint32_t*)self_param;
    if ((*(char(*)(int))*(uint32_t*)(*(uint32_t*)self + 0x94))(4) != '\0') {
        float fVar1 = 1.0f / (unaff_retaddr * 1000.0f);
        if ((char)self[6] != '\0') {
            (*(void(*)(int, uint32_t))*(uint32_t*)(*DAT_008ecd7c + 0x80))(3, self[4]);
            return;
        }
        (*(void(*)(int, uint32_t, float, float, float))*(uint32_t*)(*DAT_008ecd7c + 0x80))(
            1, self[3], fVar1 * ((float)self[9] - (float)self[0xc]),
            ((float)self[10] - (float)self[0xd]) * fVar1,
            ((float)self[0xb] - (float)self[0xe]) * fVar1);
    }
    return;
}

// 0x5335e0 — observed shape
uint32_t FUN_005335e0(void* self_param, uint32_t* param_1, uint32_t* param_2) {
    uint8_t* self = (uint8_t*)self_param;
    *(uint32_t*)(self + 0x4c) = *param_1;
    *(uint32_t*)(self + 0x50) = param_1[1];
    *(uint32_t*)(self + 0x54) = param_1[2];
    *(uint32_t*)(self + 0x58) = *param_2;
    *(uint32_t*)(self + 0x5c) = param_2[1];
    *(uint32_t*)(self + 0x60) = param_2[2];
    if (*(char*)(self + 0x18) == '\0') {
        (*(void(*)(int, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))*(uint32_t*)(*DAT_008ecd7c + 0x98))(
            1, *(uint32_t*)(self + 0xc), *(uint32_t*)(self + 0x4c),
            *(uint32_t*)(self + 0x50), *(uint32_t*)(self + 0x54), *param_2, param_2[1], param_2[2]);
        return 1;
    }
    (*(void(*)(int, uint32_t))*(uint32_t*)(*DAT_008ecd7c + 0x98))(3, *(uint32_t*)(self + 0x10));
    return 1;
}

// 0x5337b0 — observed shape
// NEEDS_MANUAL: stack-passing via Ghidra CONCAT/uStack slots; preserved comparison/count structure.
uint64_t FUN_005337b0(void* self_a, void* self_b) {
    uint32_t* esi = (uint32_t*)self_a;
    uint32_t* ebx = (uint32_t*)self_b;
    int iVar5 = 0;
    if ((uint32_t)esi[8] < (uint32_t)ebx[8]) iVar5 = -1;
    else if ((uint32_t)ebx[8] < (uint32_t)esi[8]) iVar5 = 1;
    if ((*(char(*)())*(uint32_t*)(*(uint32_t*)esi + 0x40))() != '\0') iVar5 += 1;
    if ((*(char(*)())*(uint32_t*)(*(uint32_t*)ebx + 0x40))() != '\0') iVar5 += -1;
    float fVar6 = (*(float(*)())*(uint32_t*)(*(uint32_t*)esi + 0xa8))();
    float fStack_2c = fVar6;
    float fVar6b = (*(float(*)())*(uint32_t*)(*(uint32_t*)esi + 0xa8))();
    if (fVar6b <= fStack_2c) {
        float fVar6c = (*(float(*)())*(uint32_t*)(*(uint32_t*)esi + 0xa8))();
        fStack_2c = fVar6c;
        float fVar6d = (*(float(*)())*(uint32_t*)(*(uint32_t*)esi + 0xa8))();
        if (fVar6d < fStack_2c) iVar5 += 1;
    }
    else iVar5 += -1;
    (*(void(*)())*(uint32_t*)(DAT_008ecd78 + 0x38))();
    (*(void(**)(void*))*(uint32_t*)(DAT_008ecd78 + 0x38))();
    (*(void(**)(void*))*(uint32_t*)(*(uint32_t*)esi + 0xc4))(nullptr);
    (*(void(**)(void*))*(uint32_t*)(*(uint32_t*)ebx + 0xc4))(nullptr);
    float fD8a = 0.0f, fD8b = 0.0f, t1 = 0.0f, t2 = 0.0f;
    (*(void(**)(void*))*(uint32_t*)(*(uint32_t*)esi + 0xd8))(&t1);
    if (t1 <= t2) iVar5 += -2;
    (*(void(**)(void*))*(uint32_t*)(*(uint32_t*)ebx + 0xd8))(&fD8b);
    (void)fD8a;
    if (t1 <= fD8b) iVar5 += 2;
    uint16_t uVar1 = (uint16_t)(t1 < fD8b);
    (void)fVar6; (void)fVar6b;
    uint64_t status = ((uint64_t)uVar1 << 32) | (uint64_t)(uint32_t)(iVar5 + (iVar5 < 0 ? -1 : 1) < 0 ? 0xffffffffu : 0u);
    return status;
}

// 0x533980 — observed shape
void FUN_00533980(void* self_param, void* edi_param) {
    uint8_t* self = (uint8_t*)self_param;
    uint8_t* edi = (uint8_t*)edi_param;
    int iVar1 = *(int*)(self + 0x14);
    uint32_t local_4 = *(uint32_t*)(edi + 4);
    if ((iVar1 == 0) || ((uint32_t)((*(int*)(self + 0x1c) - iVar1) >> 2) <= (uint32_t)((*(int*)(self + 0x18) - iVar1) >> 2))) {
        FUN_0052c690(self + 0x10, *(uint32_t*)(self + 0x18), &local_4);
        *(uint32_t*)(edi + 4) = 0xffffffff;
        return;
    }
    uint32_t* puVar2 = *(uint32_t**)(self + 0x18);
    *puVar2 = local_4;
    *(uint32_t**)(self + 0x18) = puVar2 + 1;
    *(uint32_t*)(edi + 4) = 0xffffffff;
    return;
}

// 0x5339f0 — observed shape
uint32_t FUN_005339f0(void* self_param) {
    uint32_t* self = (uint32_t*)self_param;
    for (int i = 1; i <= 10; i++) self[i] = 0xffffffff;
    self[0xc] = 0xbf800000; self[0xd] = 0xbf800000;
    *self = 0;
    *(uint8_t*)((uint8_t*)self + 0x3d) = 0;
    self[0xb] = 0;
    self[0xe] = 0xbf800000;
    *(uint8_t*)(self + 0xf) = 0;
    return 1;
}

// 0x533a60 — observed shape
void FUN_00533a60(void* self_param) {
    uint32_t* self = (uint32_t*)self_param;
    int iVar1 = 0;
    if (((char)self[0xf] != '\0') && (*(char*)((uint8_t*)self + 0x3d) != '\0')) {
        *(uint8_t*)((uint8_t*)self + 0x3d) = 0;
        uint32_t* piVar2 = self;
        while ((piVar2 = piVar2 + 1, *piVar2 == (uint32_t)-1) ) {
            iVar1 += 1;
            if (9 < iVar1) return;
        }
        if (iVar1 != -1) {
            FUN_00533ac0(self[0xc], self[0xd], self[0xe]);
        }
    }
    return;
}

// 0x533ac0 — observed shape
uint32_t FUN_00533ac0_external(void* self_param, uint32_t* out_ptr);
uint32_t FUN_00533ac0(void* self_param, uint32_t in_ECX_val, uint32_t* unaff_ESI) {
    if (in_ECX_val == 1) {
        *unaff_ESI = FUN_005281c0();
        return 1;
    }
    if (in_ECX_val == 2) {
        *unaff_ESI = FUN_005285f0(&DAT_008ecd78, 0, 0);
        return 1;
    }
    (void)self_param;
    return 0;
}

// 0x533bcd — observed shape
void FUN_00533bcd(void* self_param) {
    uint32_t* self = (uint32_t*)self_param;
    uint32_t local_8 = DAT_007187f8;
    (void)local_8;
    FUN_00533b9d();
    self[2] = 0x400000; self[1] = 0x400000; *self = 0x3c;
    *(uint8_t*)(self + 3) = 0;
    OSVERSIONINFOA local_9c;
    memset(&local_9c, 0, 0x94);
    local_9c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_9c);
    bool setFlag = false;
    if (local_9c.dwPlatformId == 2) {
        setFlag = (local_9c.dwMajorVersion >= 5);
    }
    else if (local_9c.dwPlatformId == 1) {
        setFlag = !(local_9c.dwMajorVersion < 5 && (local_9c.dwMajorVersion != 4 || local_9c.dwMinorVersion == 0));
    }
    if (setFlag) *(uint8_t*)(self + 3) = 1;
    self[4] = 0x710;
    self[5] = &DAT_006c062c;
    if (FUN_004abab0() < 0) {
        DAT_008ed5bc = 1;
    }
    return;
}

// 0x533c78 — observed shape
void FUN_00533c78(size_t param_1) {
    while (true) {
        void* pvVar2 = malloc(param_1);
        if (pvVar2 != nullptr) break;
        if (_callnewh(param_1) == 0) {
            // std::_Nomemory() — linker-backed; abort-equivalent if unavailable.
            abort();
        }
    }
    return;
}

// 0x533cb0 — observed shape
void FUN_00533cb0(void* self_param, int param_1) {
    uint32_t* self = (uint32_t*)self_param;
    if (param_1 != (int)self[1]) {
        int iVar1;
        if (param_1 == 0) {
            iVar1 = 0;
        }
        else {
            iVar1 = (int)(intptr_t)thunk_FUN_00533c78((size_t)param_1 * 2);
            uint32_t uVar2 = 0;
            if (self[2] != 0) {
                do {
                    *(uint16_t*)(iVar1 + uVar2 * 2) = *(uint16_t*)(*self + uVar2 * 2);
                    uVar2 += 1;
                } while (uVar2 < self[2]);
            }
        }
        operator_delete__((void*)*self);
        *self = (uint32_t)iVar1;
        self[1] = (uint32_t)param_1;
    }
    return;
}

// 0x533d10 — observed shape
void FUN_00533d10(void* self_param, uint32_t param_1, uint32_t param_2) {
    uint32_t* self = (uint32_t*)self_param;
    (*(void(**)(uint32_t, uint32_t))*(uint32_t*)(*(uint32_t*)self + 0x48))(param_1, param_2);
    if ((void*)self[9] != nullptr) {
        (*(void(**)())*(uint32_t*)(*(uint32_t*)self[9] + 0x80))();
    }
    return;
}

// 0x533d50 — observed shape
void FUN_00533d50(void* self_param, uint32_t param_1) {
    uint32_t* self = (uint32_t*)self_param;
    if ((void*)self[9] == nullptr) {
        self[9] = param_1;
        return;
    }
    uint32_t* local_4 = self;
    (*(void(**)(void*))*(uint32_t*)(*(uint32_t*)self[9] + 0x74))(&local_4);
    if (self == nullptr) {
        // Ghidra puRam00000024 write to absolute address — not reproduced.
        return;
    }
    uint32_t iVar1 = self[1];
    self[1] = iVar1 - 1;
    if (iVar1 - 1 == 0) {
        (*(void(**)(int))*(uint32_t*)(*self))(1);
    }
    self[9] = (uint32_t)(intptr_t)local_4;
    return;
}

// 0x533db0 — observed shape
uint32_t* FUN_00533db0(void* self_param, int param_1) {
    uint8_t* self = (uint8_t*)self_param;
    uint32_t* puVar1 = *(uint32_t**)(self + 0xa4);
    do {
        if (puVar1 == nullptr) return nullptr;
        uint32_t* piVar2 = (uint32_t*)puVar1[2];
        puVar1 = (uint32_t*)*puVar1;
        if (piVar2 != nullptr) {
            int iVar3 = (*(int(*)())*(uint32_t*)(*(uint32_t*)piVar2 + 0x34))();
            if (iVar3 == param_1) return piVar2;
        }
    } while (true);
}

// 0x533df0 — observed shape
uint16_t FUN_00533df0(void* self_param, int param_1) {
    uint8_t* self = (uint8_t*)self_param;
    (void)self;
    uint32_t uVar3 = 0;
    float* pfVar5 = (float*)(param_1 + 400);
    uint16_t in_AX = 0;
    do {
        uint32_t uVar4 = 1u << ((uint8_t)uVar3 & 0x1f);
        if ((uVar4 & *(uint32_t*)(param_1 + 0x1ec)) != 0) {
            float fVar2 = (*(float*)(self + 0x2c) * *pfVar5 +
                           pfVar5[-1] * *(float*)(self + 0x28) + pfVar5[1] * *(float*)(self + 0x30)) -
                          pfVar5[2];
            float fVar1 = -*((float*)(self + 0x34));
            if ((!std::isnan(fVar2) && !std::isnan(fVar1)) && ((fVar2 < fVar1) != (fVar2 == fVar1))) {
                return (uint16_t)(1u | (uint16_t)(((fVar2 < fVar1) ? 1u : 0u) | ((std::isnan(fVar2) || std::isnan(fVar1)) ? 0x400u : 0u) | ((fVar2 == fVar1) ? 0x4000u : 0u)) << 8);
            }
            fVar1 = *(float*)(self + 0x34);
            in_AX = (uint16_t)((fVar2 < fVar1) ? 0x100u : 0u) | (uint16_t)((std::isnan(fVar2) || std::isnan(fVar1)) ? 0x400u : 0u) | (uint16_t)((fVar2 == fVar1) ? 0x4000u : 0u);
            if (fVar2 >= fVar1) {
                *(uint32_t*)(param_1 + 0x1ec) = ~uVar4 & *(uint32_t*)(param_1 + 0x1ec);
            }
        }
        uVar3 += 1;
        pfVar5 += 4;
    } while (uVar3 < 6);
    return (uint16_t)(in_AX & 0xff00);
}
