#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00491640();
extern void* FUN_005580b0(void* a, void* b);
extern void FUN_004916d0(void* a, void* b);
extern void FUN_0053c6f0(void* a, void* b, void* c);
extern void* FUN_0053ce40(void* a, void* b);

// 0x5365d0 — observed shape
void FUN_5365d0(void* self, float param_1) {
    char* s = (char*)self;
    float local_10 = param_1 * *(float*)(s + 0x110) + *(float*)(s + 0x104);
    float fVar1 = param_1 * *(float*)(s + 0x114) + *(float*)(s + 0x108);
    float fVar2 = param_1 * *(float*)(s + 0x118) + *(float*)(s + 0x10c);
    float local_1c = -*(float*)(s + 0x124) * fVar1 - -*(float*)(s + 0x120) * fVar2;
    float local_18 = fVar2 * -*(float*)(s + 0x11c) - -*(float*)(s + 0x124) * local_10;
    float local_14 = -*(float*)(s + 0x120) * local_10 - fVar1 * -*(float*)(s + 0x11c);
    FUN_00491640();
    uint32_t* puVar3 = (uint32_t*)FUN_005580b0(&local_1c, s + 0x90);
    *(uint32_t*)(s + 0x1dc) = puVar3[0];
    *(uint32_t*)(s + 0x1e0) = puVar3[1];
    *(uint32_t*)(s + 0x1e4) = puVar3[2];
    *(uint32_t*)(s + 0x1e8) = puVar3[3];
}

// 0x5366d0 — observed shape
void FUN_5366d0(void* self) {
    char* s = (char*)self;
    float fVar1 = -*(float*)(s + 0x11c) * *(float*)(s + 0x90) + -*(float*)(s + 0x120) * *(float*)(s + 0x94) + -*(float*)(s + 0x124) * *(float*)(s + 0x98);
    float fVar2 = -*(float*)(s + 0x110) * *(float*)(s + 0x90) + -*(float*)(s + 0x114) * *(float*)(s + 0x94) + -*(float*)(s + 0x118) * *(float*)(s + 0x98);
    float fVar3 = -*(float*)(s + 0x104) * *(float*)(s + 0x90) + -*(float*)(s + 0x108) * *(float*)(s + 0x94) + -*(float*)(s + 0x10c) * *(float*)(s + 0x98);
    float fVar4 = *(float*)(s + 0x128) + *(float*)(s + 300);
    float fVar6 = *(float*)(s + 0x134) + *(float*)(s + 0x130);
    float fVar7 = 1.0f / (*(float*)(s + 300) - *(float*)(s + 0x128));
    float fVar8 = 1.0f / (*(float*)(s + 0x130) - *(float*)(s + 0x134));
    float fVar9 = 1.0f / (*(float*)(s + 0x13c) - *(float*)(s + 0x138));
    float fVar5 = fVar7 + fVar7;
    *(float*)(s + 0xfc) = fVar5;
    float fVar10 = fVar8 + fVar8;
    *(float*)(s + 0x100) = fVar10;
    if (*(char*)(s + 0x140) == '\0') {
        fVar4 = -(fVar7 * fVar4);
        *(uint32_t*)(s + 0xe8) = *(uint32_t*)(s + 0x104);
        fVar6 = -(fVar8 * fVar6);
        fVar7 = fVar9 * *(float*)(s + 0x13c);
        *(float*)(s + 0xb8) = fVar5 * *(float*)(s + 0x11c) + fVar4 * *(float*)(s + 0x104);
        *(float*)(s + 0xbc) = fVar4 * *(float*)(s + 0x108) + fVar5 * *(float*)(s + 0x120);
        *(float*)(s + 0xc0) = fVar4 * *(float*)(s + 0x10c) + fVar5 * *(float*)(s + 0x124);
        *(float*)(s + 0xc4) = fVar5 * fVar1 + fVar4 * fVar3;
        *(float*)(s + 200) = fVar10 * *(float*)(s + 0x110) + fVar6 * *(float*)(s + 0x104);
        *(float*)(s + 0xcc) = fVar6 * *(float*)(s + 0x108) + fVar10 * *(float*)(s + 0x114);
        *(float*)(s + 0xd0) = fVar6 * *(float*)(s + 0x10c) + fVar10 * *(float*)(s + 0x118);
        *(float*)(s + 0xd4) = fVar10 * fVar2 + fVar6 * fVar3;
        *(float*)(s + 0xd8) = fVar7 * *(float*)(s + 0x104);
        *(float*)(s + 0xdc) = fVar7 * *(float*)(s + 0x108);
        *(float*)(s + 0xe0) = fVar7 * *(float*)(s + 0x10c);
        *(float*)(s + 0xe4) = fVar7 * fVar3 + -(fVar9 * *(float*)(s + 0x138) * *(float*)(s + 0x13c));
        *(float*)(s + 0xf4) = fVar3;
        *(uint32_t*)(s + 0xf0) = *(uint32_t*)(s + 0x10c);
        *(uint32_t*)(s + 0xec) = *(uint32_t*)(s + 0x108);
        return;
    }
    *(uint32_t*)(s + 0xe8) = 0;
    *(uint32_t*)(s + 0xf0) = 0;
    float fVar11 = 1.0f / fVar9;
    *(uint32_t*)(s + 0xf4) = 0x3f800000;
    *(uint32_t*)(s + 0xec) = 0;
    *(float*)(s + 0xb8) = fVar5 * *(float*)(s + 0x11c);
    *(float*)(s + 0xbc) = fVar5 * *(float*)(s + 0x120);
    *(float*)(s + 0xc0) = fVar5 * *(float*)(s + 0x124);
    *(float*)(s + 0xc4) = fVar5 * fVar1 + fVar4 / fVar7;
    *(float*)(s + 200) = fVar10 * *(float*)(s + 0x110);
    *(float*)(s + 0xcc) = fVar10 * *(float*)(s + 0x114);
    *(float*)(s + 0xd0) = fVar10 * *(float*)(s + 0x118);
    *(float*)(s + 0xd4) = fVar10 * fVar2 + fVar6 / fVar8;
    *(float*)(s + 0xd8) = fVar11 * *(float*)(s + 0x104);
    *(float*)(s + 0xdc) = fVar11 * *(float*)(s + 0x108);
    *(float*)(s + 0xe0) = fVar11 * *(float*)(s + 0x10c);
    *(float*)(s + 0xe4) = fVar11 * fVar3 + (-1.0f / fVar9) * *(float*)(s + 0x138);
}

// 0x536a60 — observed shape
void FUN_536a60(void* self, float* param_1, float* param_2) {
    char* s = (char*)self;
    float fVar1 = (param_1[0] - *(float*)(s + 0x90)) * *(float*)(s + 0x104) + (param_1[1] - *(float*)(s + 0x94)) * *(float*)(s + 0x108) + (param_1[2] - *(float*)(s + 0x98)) * *(float*)(s + 0x10c);
    if (fVar1 < 1e-05f) {
        if (-1e-05f < fVar1) {
            param_2[0] = 3.4028235e+38f;
            param_2[1] = 3.4028235e+38f;
            return;
        }
        fVar1 = -fVar1;
    }
    if (*(char*)(s + 0x140) == '\0') {
        fVar1 = param_1[3] / fVar1;
    } else {
        fVar1 = param_1[3];
    }
    param_2[0] = fVar1 * *(float*)(s + 0xfc);
    param_2[1] = fVar1 * *(float*)(s + 0x100);
}

// 0x536b00 — observed shape
uint32_t FUN_536b00(void* self, float* param_1) {
    int32_t* in_ECX = (int32_t*)self;
    float local_78 = (float)in_ECX[0x24] - param_1[0];
    int iVar2 = in_ECX[9];
    float local_74 = (float)in_ECX[0x25] - param_1[1];
    float local_70 = (float)in_ECX[0x26] - param_1[2];
    if (1e-10f <= local_78 * local_78 + local_74 * local_74 + local_70 * local_70) {
        float local_6c, local_68, local_64, local_60, local_5c, local_58, local_54, local_50, local_4c;
        int32_t local_48[9];
        uint8_t local_24[36];
        FUN_00491640();
        FUN_004916d0(&local_6c, &local_78);
        if (0.5f <= local_6c * local_6c + local_68 * local_68 + local_64 * local_64) {
            FUN_004916d0(&local_60, &local_6c);
            if (0.5f <= local_60 * local_60 + local_5c * local_5c + local_58 * local_58) {
                local_54 = -local_78;
                local_50 = -local_74;
                local_4c = -local_70;
                FUN_0053c6f0(&local_54, &local_60, &local_6c);
                if (iVar2 != 0) {
                    int32_t* piVar1 = (int32_t*)FUN_0053ce40(local_24, local_48);
                    int32_t* piVar4 = local_48;
                    for (int i = 9; i != 0; i--) { *piVar4++ = *piVar1++; }
                }
                int32_t iVar2b = *in_ECX;
                int32_t* piVar1 = local_48;
                int32_t* piVar4 = in_ECX + 0xe;
                for (int i = 9; i != 0; i--) { *piVar4++ = *piVar1++; }
                auto vtbl = *(uint32_t**)in_ECX;
                ((void(*)())vtbl[0x6c / 4])();
                ((void(*)())vtbl[0x68 / 4])();
                (void)iVar2b;
                return 1;
            }
        }
    }
    return 0;
}

// 0x536c70 — observed shape
uint32_t FUN_536c70(void* self, float param_1, float param_2, float* param_3, float* param_4) {
    char* s = (char*)self;
    if (*(char*)(s + 0x140) == '\0') {
        float fVar1 = *(float*)(s + 0x114);
        float fVar2 = *(float*)(s + 0x118);
        float fVar3 = *(float*)(s + 0x120);
        float fVar4 = *(float*)(s + 0x124);
        float fVar5 = *(float*)(s + 0x108);
        float fVar6 = *(float*)(s + 0x10c);
        param_4[0] = param_1 * *(float*)(s + 0x11c) + *(float*)(s + 0x104) + param_2 * *(float*)(s + 0x110);
        param_4[1] = param_1 * fVar3 + fVar5 + param_2 * fVar1;
        param_4[2] = param_1 * fVar4 + fVar6 + param_2 * fVar2;
        FUN_00491640();
        param_3[0] = *(float*)(s + 0x90);
        param_3[1] = *(float*)(s + 0x94);
        param_3[2] = *(float*)(s + 0x98);
        return 1;
    }
    param_4[0] = *(float*)(s + 0x104);
    param_4[1] = *(float*)(s + 0x108);
    param_4[2] = *(float*)(s + 0x10c);
    FUN_00491640();
    float fVar1 = *(float*)(s + 0x114);
    float fVar2 = *(float*)(s + 0x118);
    float fVar3 = *(float*)(s + 0x120);
    float fVar4 = *(float*)(s + 0x124);
    float fVar5 = *(float*)(s + 0x94);
    float fVar6 = *(float*)(s + 0x98);
    param_3[0] = param_1 * *(float*)(s + 0x11c) + *(float*)(s + 0x90) + param_2 * *(float*)(s + 0x110);
    param_3[1] = param_1 * fVar3 + fVar5 + param_2 * fVar1;
    param_3[2] = param_1 * fVar4 + fVar6 + param_2 * fVar2;
    fVar5 = -(*(float*)(s + 300) + *(float*)(s + 0x128));
    fVar6 = -(*(float*)(s + 0x134) + *(float*)(s + 0x130));
    fVar1 = *(float*)(s + 0x114);
    fVar2 = *(float*)(s + 0x118);
    fVar3 = *(float*)(s + 0x120);
    fVar4 = *(float*)(s + 0x124);
    param_3[0] = fVar5 * *(float*)(s + 0x11c) + param_3[0] + fVar6 * *(float*)(s + 0x110);
    param_3[1] = fVar5 * fVar3 + param_3[1] + fVar6 * fVar1;
    param_3[2] = fVar5 * fVar4 + param_3[2] + fVar6 * fVar2;
    return 1;
}

extern uint32_t FUN_005511f0(uint32_t a, uint32_t b, void* c, void* d);
extern uint32_t FUN_00535cc0(uint32_t a, uint32_t b, void* c, void* d);
extern uint32_t FUN_536c70(void* self, float a, float b, float* c, float* d);
extern void FUN_005538c0(uint32_t a);
extern void FUN_005580f0(uint32_t a);
extern void FUN_00533f30(int32_t* a);

// 0x536ec0 — observed shape
uint32_t FUN_536ec0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    char* s = (char*)self;
    uint32_t in_EAX = 0;
    if (*(int32_t*)(s + 0x188) != 0) {
        in_EAX = FUN_005511f0(param_1, param_2, &param_1, &param_2);
        if ((char)in_EAX != '\0') {
            uint32_t local_4, local_8;
            in_EAX = FUN_00535cc0(param_1, param_2, &local_4, &local_8);
            if ((char)in_EAX != '\0') {
                return FUN_536c70(self, *(float*)&local_4, *(float*)&local_8, (float*)param_3, (float*)param_4);
            }
        }
    }
    return in_EAX & 0xffffff00u;
}

// 0x536f40 — observed shape
void FUN_536f40(void* self) {
    char* s = (char*)self;
    uint32_t uVar1 = 0;
    if (*(int32_t*)(s + 0x164) != 0) {
        do {
            if (*(int32_t*)(*(intptr_t*)(s + 0x15c) + uVar1 * 4) != 0) {
                FUN_005538c0(*(uint32_t*)(s + 0x188));
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint32_t*)(s + 0x164));
    }
}

// 0x536f80 — observed shape
void FUN_536f80(void* self) {
    char* s = (char*)self;
    uint32_t uVar3 = 0;
    if (*(int32_t*)(s + 0x164) != 0) {
        do {
            int32_t iVar2 = *(int32_t*)(*(intptr_t*)(s + 0x15c) + uVar3 * 4);
            if (iVar2 != 0) {
                uint8_t* pbVar1 = (uint8_t*)(iVar2 + 0x20);
                *pbVar1 = *pbVar1 | 1;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)(s + 0x164));
    }
}

// 0x536fb0 — observed shape
void FUN_536fb0(void* self) {
    char* s = (char*)self;
    uint32_t uVar1 = 0;
    if (*(int32_t*)(s + 0x17c) != 0) {
        do {
            if (*(int32_t*)(*(intptr_t*)(s + 0x174) + uVar1 * 4) != 0) {
                FUN_005580f0(*(uint32_t*)(s + 0x188));
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint32_t*)(s + 0x17c));
    }
}

// 0x536ff0 — observed shape
void FUN_536ff0(void* self, int32_t* param_1) {
    char* s = (char*)self;
    FUN_00533f30(param_1);
    uint32_t uVar2 = 0;
    if (*(int32_t*)(s + 0x164) != 0) {
        do {
            int32_t iVar1 = *(int32_t*)(*(intptr_t*)(s + 0x15c) + uVar2 * 4);
            if (iVar1 != 0) {
                auto vtbl = *(uint32_t**)param_1;
                ((void(*)(int32_t))vtbl[0xfc / 4])(iVar1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(s + 0x164));
    }
    uVar2 = 0;
    if (*(int32_t*)(s + 0x17c) != 0) {
        do {
            int32_t iVar1 = *(int32_t*)(*(intptr_t*)(s + 0x174) + uVar2 * 4);
            if (iVar1 != 0) {
                auto vtbl = *(uint32_t**)param_1;
                ((void(*)(int32_t))vtbl[0xf0 / 4])(iVar1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(s + 0x17c));
    }
}

extern uint32_t FUN_00533f50(uint32_t a);
extern char FUN_005348e0(int32_t a);
extern void FUN_00533e70(void* a);
extern void FUN_004d4b80(void* a);
extern void FUN_00536220(uint32_t a);
extern void FUN_005362a0(uint32_t a);
extern void FUN_00536350(uint32_t a);
extern void FUN_00536420(uint32_t a);
extern void FUN_00536500(uint32_t a);
extern void FUN_00535e20(uint32_t a);
extern void FUN_00535f20(uint32_t a);
extern void FUN_00536020(uint32_t a);
extern void FUN_00536120(uint32_t a);
extern void FUN_005373f0(void* a);
extern void FUN_004db0a0();
extern void FUN_5366d0(void* self);

// 0x537070 — observed shape
uint32_t FUN_537070(void* self, uint32_t param_1) {
    char* s = (char*)self;
    uint32_t uVar2 = FUN_00533f50(param_1);
    if ((char)uVar2 == '\0') return uVar2;
    if (*(int32_t**)(s + 0x154) != nullptr) {
        int32_t* pi = *(int32_t**)(s + 0x154);
        auto vtbl = *(uint32_t**)pi;
        ((void(*)(uint32_t))vtbl[0x14 / 4])(param_1);
    }
    uint32_t uVar3 = 0;
    if (*(int32_t*)(s + 0x164) != 0) {
        do {
            int32_t* piVar1 = *(int32_t**)(*(intptr_t*)(s + 0x15c) + uVar3 * 4);
            if (piVar1 != nullptr) {
                auto vtbl = *(uint32_t**)piVar1;
                ((void(*)(uint32_t))vtbl[0x14 / 4])(param_1);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)(s + 0x164));
    }
    uVar3 = 0;
    if (*(int32_t*)(s + 0x17c) != 0) {
        uint32_t uVar4 = 0;
        do {
            int32_t* piVar1 = *(int32_t**)(*(intptr_t*)(s + 0x174) + uVar4 * 4);
            if (piVar1 != nullptr) {
                auto vtbl = *(uint32_t**)piVar1;
                ((void(*)(uint32_t))vtbl[0x14 / 4])(param_1);
            }
            uVar3 = *(uint32_t*)(s + 0x17c);
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar3);
    }
    return (uint32_t)((uVar3 >> 8) << 8) | 1u;
}

// 0x537100 — observed shape
uint32_t FUN_537100(void* self, int32_t param_1) {
    char* s = (char*)self;
    char* p = (char*)(intptr_t)param_1;
    char cVar4 = FUN_005348e0(param_1);
    if (cVar4 == '\0' || *(float*)(s + 0x128) != *(float*)(p + 0x128) || *(float*)(s + 300) != *(float*)(p + 300) || *(float*)(s + 0x130) != *(float*)(p + 0x130) || *(float*)(s + 0x134) != *(float*)(p + 0x134) || *(float*)(s + 0x138) != *(float*)(p + 0x138) || *(float*)(s + 0x13c) != *(float*)(p + 0x13c) || *(float*)(s + 0x144) != *(float*)(p + 0x144) || *(float*)(s + 0x148) != *(float*)(p + 0x148) || *(float*)(s + 0x14c) != *(float*)(p + 0x14c) || *(float*)(s + 0x150) != *(float*)(p + 0x150) || *(float*)(s + 0x1f0) != *(float*)(p + 0x1f0)) return 0;
    uint32_t uVar1 = *(uint32_t*)(s + 0x164);
    if (uVar1 != *(uint32_t*)(p + 0x164)) return 0;
    uint32_t uVar5 = 0;
    if (uVar1 != 0) {
        do {
            int32_t* piVar2 = *(int32_t**)(*(intptr_t*)(s + 0x15c) + uVar5 * 4);
            int32_t iVar3 = *(int32_t*)(*(intptr_t*)(p + 0x15c) + uVar5 * 4);
            if (piVar2 == nullptr) { if (iVar3 != 0) return 0; }
            else {
                if (iVar3 == 0) return 0;
                auto vtbl = *(uint32_t**)piVar2;
                char r = ((char(*)(int32_t))vtbl[0x1c / 4])(iVar3);
                if (r == '\0') return 0;
            }
            uVar5++;
        } while (uVar5 < uVar1);
    }
    uVar1 = *(uint32_t*)(s + 0x17c);
    if (uVar1 != *(uint32_t*)(p + 0x17c)) return 0;
    uVar5 = 0;
    if (uVar1 != 0) {
        do {
            int32_t* piVar2 = *(int32_t**)(*(intptr_t*)(s + 0x174) + uVar5 * 4);
            int32_t iVar3 = *(int32_t*)(*(intptr_t*)(p + 0x174) + uVar5 * 4);
            if (piVar2 == nullptr) { if (iVar3 != 0) return 0; }
            else {
                if (iVar3 == 0) return 0;
                auto vtbl = *(uint32_t**)piVar2;
                char r = ((char(*)(int32_t))vtbl[0x1c / 4])(iVar3);
                if (r == '\0') return 0;
            }
            uVar5++;
        } while (uVar5 < uVar1);
    }
    return 1;
}

// 0x5372e0 — observed shape
void FUN_5372e0(void* self) {
    char* s = (char*)self;
    int32_t* f188 = *(int32_t**)(s + 0x188);
    if (f188 == nullptr) return;
    {
        auto vtbl = *(uint32_t**)f188;
        ((void(*)(void*, void*, void*, void*, void*, void*))vtbl[0xc4 / 4])(s + 0x90, s + 0x104, s + 0x110, s + 0x11c, s + 0x128, s + 0x144);
    }
    {
        auto vtbl = *(uint32_t**)f188;
        ((void(*)())vtbl[0xbc / 4])();
    }
    if (*(int32_t*)(s + 0x154) != 0 && *(float*)(*(intptr_t*)(s + 0x154) + 0x34) != 0.0f) {
        int32_t* piVar1 = *(int32_t**)(*(intptr_t*)(s + 0x188) + 0xc);
        if (piVar1 != nullptr) {
            piVar1[1] = piVar1[1] + 1;
            auto vtbl = *(uint32_t**)piVar1;
            char cVar5 = ((char(*)())vtbl[0x34 / 4])();
            if (cVar5 == '\0') {
                int32_t iVar2 = *(int32_t*)(s + 0x188);
                uint32_t* puVar3 = *(uint32_t**)(iVar2 + 0xc);
                if (puVar3 != nullptr) {
                    int32_t* piVar4 = (int32_t*)(puVar3 + 1);
                    *piVar4 = *piVar4 + -1;
                    if (*piVar4 == 0) { auto vt = *(uint32_t**)puVar3; ((void(*)(int32_t))vt[0])(1); }
                    *(uint32_t*)(iVar2 + 0xc) = 0;
                }
            }
        }
        FUN_00533e70(s);
        int32_t* piVar4b = *(int32_t**)(*(intptr_t*)(s + 0x188) + 0xc);
        if (piVar4b != nullptr) { auto vt = *(uint32_t**)piVar4; ((void(*)())vt[0x38 / 4])(); }
        FUN_004d4b80(piVar1);
        if (piVar1 != nullptr) {
            int32_t* piVar4 = piVar1 + 1;
            *piVar4 = *piVar4 + -1;
            if (*piVar4 == 0) { auto vt = *(uint32_t**)piVar1; ((void(*)(int32_t))vt[0])(1); }
        }
    }
    FUN_536f40(s);
    FUN_536fb0(s);
    {
        auto vt = *(uint32_t**)*(intptr_t**)(s + 0x188);
        ((void(*)())vt[0xc0 / 4])();
    }
}

// 0x5373f0 — observed shape
void FUN_5373f0(uint32_t* param_1) {
    FUN_00536220(param_1[4]);
    FUN_005362a0(param_1[5]);
    if (*(char*)((char*)param_1 + 24) == '\0') {
        FUN_00536350(param_1[0]);
        FUN_00536420(param_1[1]);
        FUN_00536500(param_1[2]);
        FUN_5365d0((void*)(intptr_t)param_1[3], 0.0f);
        return;
    }
    FUN_00535e20(param_1[0]);
    FUN_00535f20(param_1[1]);
    FUN_00536020(param_1[2]);
    FUN_00536120(param_1[3]);
}

// 0x537480 — observed shape
void FUN_537480(void* self) {
    char* s = (char*)self;
    FUN_004db0a0();
    *(uint32_t*)(s + 0x104) = *(uint32_t*)(s + 0x6c);
    *(uint32_t*)(s + 0x108) = *(uint32_t*)(s + 0x78);
    *(uint32_t*)(s + 0x10c) = *(uint32_t*)(s + 0x84);
    *(uint32_t*)(s + 0x110) = *(uint32_t*)(s + 0x70);
    *(uint32_t*)(s + 0x114) = *(uint32_t*)(s + 0x7c);
    *(uint32_t*)(s + 0x118) = *(uint32_t*)(s + 0x88);
    *(uint32_t*)(s + 0x11c) = *(uint32_t*)(s + 0x74);
    *(uint32_t*)(s + 0x120) = *(uint32_t*)(s + 0x80);
    *(uint32_t*)(s + 0x124) = *(uint32_t*)(s + 0x8c);
    FUN_005373f0((void*)(s + 0x128));
    FUN_5366d0(s);
}

extern void* PTR_FUN_006c08b8;
extern void* PTR_FUN_006c08bc;
extern void* PTR_FUN_006c08c0;
extern void FUN_005349d0();
extern void FUN_0054a9f0(uint32_t a);
extern void FUN_00558050();
extern void FUN_00537480();
extern void FUN_00581300(uint32_t a, void* b);
extern void FUN_0056f540();
extern void FUN_00534040();
extern void FUN_00534cf0(uint32_t a, uint32_t b);
extern void FUN_0057a3f0(uint32_t a);
extern void operator_delete(void* a);
extern void FUN_004127b0(void* a, uint32_t b, uint32_t c, void* d);
extern void* thunk_FUN_00533c78(uint32_t a);
extern uint8_t LAB_004c2970[];

// 0x537870 — observed shape
void FUN_537870(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)(intptr_t)&PTR_FUN_006c08b8;
    int32_t iVar2 = (int32_t)(intptr_t)in_ECX[1];
    if (iVar2 != 0) {
        int32_t iVar4 = *(int32_t*)(iVar2 - 4);
        int32_t iVar5 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 - 1) {
            do {
                uint32_t* puVar3 = *(uint32_t**)(iVar5 - 4);
                iVar5 = iVar5 - 4;
                if (puVar3 != nullptr) {
                    int32_t* piVar1 = (int32_t*)(puVar3 + 1);
                    *piVar1 = *piVar1 - 1;
                    if (*piVar1 == 0) { auto vt = *(uint32_t**)puVar3; ((void(*)(int32_t))vt[0])(1); }
                }
                iVar4 = iVar4 - 1;
            } while (iVar4 != 0);
        }
        operator_delete((void*)(intptr_t)(iVar2 - 4));
    }
}

// 0x5378c0 — observed shape
void FUN_5378c0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)(intptr_t)&PTR_FUN_006c08bc;
    int32_t iVar2 = (int32_t)(intptr_t)in_ECX[1];
    if (iVar2 != 0) {
        int32_t iVar4 = *(int32_t*)(iVar2 - 4);
        int32_t iVar5 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 - 1) {
            do {
                uint32_t* puVar3 = *(uint32_t**)(iVar5 - 4);
                iVar5 = iVar5 - 4;
                if (puVar3 != nullptr) {
                    int32_t* piVar1 = (int32_t*)(puVar3 + 1);
                    *piVar1 = *piVar1 - 1;
                    if (*piVar1 == 0) { auto vt = *(uint32_t**)puVar3; ((void(*)(int32_t))vt[0])(1); }
                }
                iVar4 = iVar4 - 1;
            } while (iVar4 != 0);
        }
        operator_delete((void*)(intptr_t)(iVar2 - 4));
    }
}

// 0x537950 — observed shape
void FUN_537950(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_005349d0();
    in_ECX[0] = (uint32_t)(intptr_t)&PTR_FUN_006c08c0;
    FUN_0054a9f0(0);
    in_ECX[0x51] = 0; in_ECX[0x52] = 0; in_ECX[0x53] = 0; in_ECX[0x54] = 0; in_ECX[0x55] = 0;
    in_ECX[0x56] = (uint32_t)(intptr_t)&PTR_FUN_006c08b8;
    in_ECX[0x58] = 5; in_ECX[0x5b] = 5; in_ECX[0x59] = 0; in_ECX[0x5a] = 0;
    {
        uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(0x18);
        uint32_t* puVar3 = nullptr;
        if (puVar1 != nullptr) { puVar3 = puVar1 + 1; puVar1[0] = 5; FUN_004127b0(puVar3, 4, 5, LAB_004c2970); }
        in_ECX[0x57] = (uint32_t)(intptr_t)puVar3;
    }
    in_ECX[0x5c] = (uint32_t)(intptr_t)&PTR_FUN_006c08bc;
    in_ECX[0x5e] = 5; in_ECX[0x61] = 5; in_ECX[0x5f] = 0; in_ECX[0x60] = 0;
    {
        uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(0x18);
        uint32_t* puVar3 = nullptr;
        if (puVar1 != nullptr) { puVar3 = puVar1 + 1; puVar1[0] = 5; FUN_004127b0(puVar3, 4, 5, LAB_004c2970); }
        in_ECX[0x5d] = (uint32_t)(intptr_t)puVar3;
    }
    in_ECX[0x62] = 0;
    int32_t iVar2 = 6;
    do { FUN_00558050(); iVar2--; } while (iVar2 != 0);
    *(uint16_t*)((char*)in_ECX + 0x2d * 4) = 0;
    in_ECX[0x4e] = 0x3f800000; in_ECX[0x4f] = 0x40000000; in_ECX[0x4c] = 0x3f000000;
    in_ECX[0x4d] = 0xbf000000; in_ECX[0x4a] = 0xbf000000; in_ECX[0x4b] = 0x3f000000;
    *(uint8_t*)((char*)in_ECX + 0x50 * 4) = 0;
    in_ECX[0x53] = 0x3f800000; in_ECX[0x54] = 0; in_ECX[0x51] = 0; in_ECX[0x52] = 0x3f800000;
    FUN_00537480();
    in_ECX[10] = in_ECX[0x24]; in_ECX[0xb] = in_ECX[0x25]; in_ECX[0x7c] = 0x3f800000;
    in_ECX[0xc] = in_ECX[0x26]; in_ECX[0x7b] = 0x3f;
}

// 0x537af0 — observed shape
void FUN_537af0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t uVar5 = 0;
    in_ECX[0] = (uint32_t)(intptr_t)&PTR_FUN_006c08c0;
    uint32_t* local_4 = in_ECX;
    if (in_ECX[0x59] != 0) {
        local_4 = nullptr;
        do { FUN_00581300(uVar5, &local_4); uVar5++; } while (uVar5 < in_ECX[0x59]);
    }
    FUN_0056f540();
    if (in_ECX[0x5f] != 0) {
        local_4 = nullptr; uVar5 = 0;
        do { FUN_00581300(uVar5, &local_4); uVar5++; } while (uVar5 < in_ECX[0x5f]);
    }
    uVar5 = 0;
    if (in_ECX[0x5f] != 0) {
        do {
            int32_t iVar2 = (int32_t)in_ECX[0x5d];
            uint32_t* puVar3 = *(uint32_t**)(iVar2 + uVar5 * 4);
            if (puVar3 != nullptr) {
                int32_t* piVar1 = (int32_t*)(puVar3 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) { auto vt = *(uint32_t**)puVar3; ((void(*)(int32_t))vt[0])(1); }
                *(uint32_t*)(iVar2 + uVar5 * 4) = 0;
            }
            uVar5++;
        } while (uVar5 < in_ECX[0x5f]);
    }
    in_ECX[0x5f] = 0; in_ECX[0x60] = 0;
    {
        uint32_t* puVar3 = (uint32_t*)(intptr_t)in_ECX[0x62];
        if (puVar3 != nullptr) { int32_t* piVar1 = (int32_t*)(puVar3 + 1); *piVar1--; if (*piVar1 == 0) { auto vt = *(uint32_t**)puVar3; ((void(*)(int32_t))vt[0])(1); } }
    }
    int32_t iVar2 = (int32_t)in_ECX[0x5d];
    in_ECX[0x5c] = (uint32_t)(intptr_t)&PTR_FUN_006c08bc;
    if (iVar2 != 0) {
        int32_t iVar4 = *(int32_t*)(iVar2 - 4); int32_t iVar6 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 - 1) { do { uint32_t* puVar3 = *(uint32_t**)(iVar6 - 4); iVar6 -= 4; if (puVar3) { int32_t* piVar1 = (int32_t*)(puVar3 + 1); *piVar1--; if (*piVar1 == 0) { auto vt = *(uint32_t**)puVar3; ((void(*)(int32_t))vt[0])(1); } } iVar4--; } while (iVar4 != 0); }
        operator_delete((void*)(intptr_t)(iVar2 - 4));
    }
    iVar2 = (int32_t)in_ECX[0x57];
    in_ECX[0x56] = (uint32_t)(intptr_t)&PTR_FUN_006c08b8;
    if (iVar2 != 0) {
        int32_t iVar4 = *(int32_t*)(iVar2 - 4); int32_t iVar6 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 - 1) { do { uint32_t* puVar3 = *(uint32_t**)(iVar6 - 4); iVar6 -= 4; if (puVar3) { int32_t* piVar1 = (int32_t*)(puVar3 + 1); *piVar1--; if (*piVar1 == 0) { auto vt = *(uint32_t**)puVar3; ((void(*)(int32_t))vt[0])(1); } } iVar4--; } while (iVar4 != 0); }
        operator_delete((void*)(intptr_t)(iVar2 - 4));
    }
    {
        uint32_t* puVar3 = (uint32_t*)(intptr_t)in_ECX[0x55];
        if (puVar3 != nullptr) { int32_t* piVar1 = (int32_t*)(puVar3 + 1); *piVar1--; if (*piVar1 == 0) { auto vt = *(uint32_t**)puVar3; ((void(*)(int32_t))vt[0])(1); } }
    }
    FUN_00534040();
}

// 0x537c70 — observed shape
void FUN_537c70(void* self, uint32_t param_1, uint32_t param_2) {
    uint32_t* in_ECX = (uint32_t*)self;
    int32_t iVar3 = (int32_t)param_1;
    FUN_00534cf0(param_1, param_2);
    *(uint16_t*)(iVar3 + 0xb4) = *(uint16_t*)((char*)in_ECX + 0x2d * 4);
    {
        uint32_t* puVar4 = in_ECX + 0x2e;
        uint32_t* puVar6 = (uint32_t*)(iVar3 + 0xb8);
        for (int i = 0x10; i != 0; i--) { *puVar6++ = *puVar4++; }
    }
    *(uint32_t*)(iVar3 + 0x90) = in_ECX[0x24]; *(uint32_t*)(iVar3 + 0x94) = in_ECX[0x25];
    *(uint32_t*)(iVar3 + 0x98) = in_ECX[0x26]; *(uint32_t*)(iVar3 + 0x104) = in_ECX[0x41];
    *(uint32_t*)(iVar3 + 0x108) = in_ECX[0x42]; *(uint32_t*)(iVar3 + 0x10c) = in_ECX[0x43];
    *(uint32_t*)(iVar3 + 0x110) = in_ECX[0x44]; *(uint32_t*)(iVar3 + 0x114) = in_ECX[0x45];
    *(uint32_t*)(iVar3 + 0x118) = in_ECX[0x46]; *(uint32_t*)(iVar3 + 0x11c) = in_ECX[0x47];
    *(uint32_t*)(iVar3 + 0x120) = in_ECX[0x48]; *(uint32_t*)(iVar3 + 0x124) = in_ECX[0x49];
    {
        uint32_t* puVar4 = in_ECX + 0x4a;
        uint32_t* puVar6 = (uint32_t*)(iVar3 + 0x128);
        for (int i = 7; i != 0; i--) { *puVar6++ = *puVar4++; }
    }
    *(uint32_t*)(iVar3 + 0x144) = in_ECX[0x51]; *(uint32_t*)(iVar3 + 0x148) = in_ECX[0x52];
    *(uint32_t*)(iVar3 + 0x14c) = in_ECX[0x53]; *(uint32_t*)(iVar3 + 0x150) = in_ECX[0x54];
    *(uint32_t*)(iVar3 + 0x1f0) = in_ECX[0x7c]; *(uint32_t*)(iVar3 + 0x18c) = in_ECX[99];
    *(uint32_t*)(iVar3 + 400) = in_ECX[100]; *(uint32_t*)(iVar3 + 0x194) = in_ECX[0x65];
    *(uint32_t*)(iVar3 + 0x198) = in_ECX[0x66]; *(uint32_t*)(iVar3 + 0x19c) = in_ECX[0x67];
    *(uint32_t*)(iVar3 + 0x1a0) = in_ECX[0x68]; *(uint32_t*)(iVar3 + 0x1a4) = in_ECX[0x69];
    *(uint32_t*)(iVar3 + 0x1a8) = in_ECX[0x6a]; *(uint32_t*)(iVar3 + 0x1ac) = in_ECX[0x6b];
    *(uint32_t*)(iVar3 + 0x1b0) = in_ECX[0x6c]; *(uint32_t*)(iVar3 + 0x1b4) = in_ECX[0x6d];
    *(uint32_t*)(iVar3 + 0x1b8) = in_ECX[0x6e]; *(uint32_t*)(iVar3 + 0x1bc) = in_ECX[0x6f];
    *(uint32_t*)(iVar3 + 0x1c0) = in_ECX[0x70]; *(uint32_t*)(iVar3 + 0x1c4) = in_ECX[0x71];
    *(uint32_t*)(iVar3 + 0x1c8) = in_ECX[0x72]; *(uint32_t*)(iVar3 + 0x1cc) = in_ECX[0x73];
    *(uint32_t*)(iVar3 + 0x1d0) = in_ECX[0x74]; *(uint32_t*)(iVar3 + 0x1d4) = in_ECX[0x75];
    *(uint32_t*)(iVar3 + 0x1d8) = in_ECX[0x76]; *(uint32_t*)(iVar3 + 0x1dc) = in_ECX[0x77];
    *(uint32_t*)(iVar3 + 0x1e0) = in_ECX[0x78]; *(uint32_t*)(iVar3 + 0x1e4) = in_ECX[0x79];
    *(uint32_t*)(iVar3 + 0x1e8) = in_ECX[0x7a];
    FUN_0057a3f0(in_ECX[0x59]);
    *(uint32_t*)(iVar3 + 0x16c) = in_ECX[0x5b];
    param_1 = 0;
    if (in_ECX[0x59] != 0) {
        do {
            uint32_t uVar7 = param_1;
            int32_t* piVar2 = *(int32_t**)((int32_t)in_ECX[0x57] + param_1 * 4);
            if (piVar2 == nullptr) { param_1 = 0; FUN_00581300(uVar7, &param_1); }
            else {
                piVar2[1]++;
                auto vt = *(uint32_t**)piVar2;
                uint32_t* puVar4 = (uint32_t*)((uint32_t(*)(uint32_t))vt[8 / 4])(param_2);
                if (puVar4) puVar4[1]++;
                uint32_t* puStack_4 = puVar4;
                FUN_00581300(param_1, &puStack_4);
                if (puVar4) { int32_t* pi = (int32_t*)(puVar4 + 1); *pi--; if (*pi == 0) { auto v = *(uint32_t**)puVar4; ((void(*)(int32_t))v[0])(1); } }
                int32_t* pi = piVar2 + 1; *pi--; if (*pi == 0) { auto v = *(uint32_t**)piVar2; ((void(*)(int32_t))v[0])(1); }
                uVar7 = param_1;
            }
            param_1 = uVar7 + 1;
        } while (param_1 < in_ECX[0x59]);
    }
    FUN_0057a3f0(in_ECX[0x5f]);
    *(uint32_t*)(iVar3 + 0x184) = in_ECX[0x61];
    param_1 = 0;
    if (in_ECX[0x5f] != 0) {
        do {
            uint32_t uVar7 = param_1;
            int32_t* piVar2 = *(int32_t**)((int32_t)in_ECX[0x5d] + param_1 * 4);
            if (piVar2 == nullptr) { param_1 = 0; FUN_00581300(uVar7, &param_1); }
            else {
                piVar2[1]++;
                auto vt = *(uint32_t**)piVar2;
                uint32_t* puVar4 = (uint32_t*)((uint32_t(*)(uint32_t))vt[8 / 4])(param_2);
                if (puVar4) puVar4[1]++;
                uint32_t* puStack_4 = puVar4;
                FUN_00581300(param_1, &puStack_4);
                if (puVar4) { int32_t* pi = (int32_t*)(puVar4 + 1); *pi--; if (*pi == 0) { auto v = *(uint32_t**)puVar4; ((void(*)(int32_t))v[0])(1); } }
                int32_t* pi = piVar2 + 1; *pi--; if (*pi == 0) { auto v = *(uint32_t**)piVar2; ((void(*)(int32_t))v[0])(1); }
                uVar7 = param_1;
            }
            param_1 = uVar7 + 1;
        } while (param_1 < in_ECX[0x5f]);
    }
    {
        uint32_t* puVar4 = *(uint32_t**)(iVar3 + 0x154);
        if (puVar4) { int32_t* pi = (int32_t*)(puVar4 + 1); *pi--; if (*pi == 0) { auto v = *(uint32_t**)puVar4; ((void(*)(int32_t))v[0])(1); } *(uint32_t*)(iVar3 + 0x154) = 0; }
    }
    {
        uint32_t* puVar4 = *(uint32_t**)(iVar3 + 0x188);
        if (puVar4) { int32_t* pi = (int32_t*)(puVar4 + 1); *pi--; if (*pi == 0) { auto v = *(uint32_t**)puVar4; ((void(*)(int32_t))v[0])(1); } *(uint32_t*)(iVar3 + 0x188) = 0; }
    }
}
