#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint32_t FUN_00505fc0(uint32_t, uint32_t, uint32_t, uint32_t);
extern int32_t FUN_00506440(void);

// 0x5075c0 — observed shape
void FUN_005075c0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    int32_t* base = static_cast<int32_t*>(self);
    (void)base;
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t child = *reinterpret_cast<int32_t*>(s + 0x124);
    if (*(char*)(s + 0xf1) == '\0') {
        if (child != 0 && ((*(uint8_t*)((uint8_t*)(uintptr_t)child + 0x20) & 1) == 0)) {
            *(uint16_t*)((uint8_t*)(uintptr_t)child + 0x20) = *(uint16_t*)((uint8_t*)(uintptr_t)child + 0x20) | 1;
        }
    } else if (child != 0 && ((*(uint8_t*)((uint8_t*)(uintptr_t)child + 0x20) & 1) != 0)) {
        *(uint8_t*)((uint8_t*)(uintptr_t)child + 0x20) = *(uint8_t*)((uint8_t*)(uintptr_t)child + 0x20) & 0xfe;
    }
    if (*(int32_t**)(s + 0xf8) != nullptr) {
        auto fn = *reinterpret_cast<int32_t(**)(uint32_t, uint32_t, uint32_t, uint32_t)>(*reinterpret_cast<int32_t*>(s + 0xf8) + 4);
        char c = (char)fn(param_1, param_2, param_3, param_4);
        if (c == '\0') return;
    }
    if (*(int32_t**)(s + 0x24) != nullptr) {
        auto fn = *reinterpret_cast<void(**)(uint32_t, uint32_t, uint32_t, uint32_t)>(*reinterpret_cast<int32_t*>(s + 0x24) + 0xb4);
        fn(param_1, param_2, param_3, param_4);
    }
}

// 0x507640 — observed shape
void FUN_00507640(void* self, char param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t iVar1;
    if (param_1 == '\0') {
        *(uint8_t*)(s + 0xf3) = 1;
        *(uint32_t*)(s + 0xf4) = 9;
        if (*(int32_t*)(s + 0x23c) == 0) return;
        iVar1 = *(int32_t*)(s + 0x264);
    } else {
        *(uint8_t*)(s + 0xf3) = 0;
        *(uint32_t*)(s + 0xf4) = 0;
        if (*(int32_t*)(s + 0x23c) == 0) return;
        iVar1 = *(int32_t*)(s + 0x240);
    }
    if (iVar1 != -1) {
        FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
    }
}

// 0x5076a0 — observed shape
void FUN_005076a0(void* self, char param_1)
{
    int32_t* in_ECX = static_cast<int32_t*>(self);
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t iVar1;
    if (param_1 == '\0') {
        *(uint8_t*)(s + 0xf1) = 0;
        if (in_ECX[0x8f] != 0) {
            iVar1 = FUN_00506440();
            if ((iVar1 == -1 || (iVar1 != in_ECX[0x93] && iVar1 != in_ECX[0x94])) &&
                (in_ECX[0x3d] = 8, in_ECX[0x98] != -1)) {
                FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
            }
        }
        auto fn = *reinterpret_cast<void(**)()>(*in_ECX + 0xb4);
        fn();
        return;
    }
    *(uint8_t*)(s + 0xf1) = 1;
    if (in_ECX[0x8f] != 0) {
        iVar1 = FUN_00506440();
        if ((iVar1 == -1 || (iVar1 != in_ECX[0x93] && iVar1 != in_ECX[0x94])) &&
            (in_ECX[0x3d] = 7, in_ECX[0x97] != -1)) {
            FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
        }
    }
    auto fn = *reinterpret_cast<void(**)()>(*in_ECX + 0xb4);
    fn();
}

// 0x5077f0 — observed shape
uint32_t FUN_005077f0(void* self, uint16_t param_1, uint32_t param_2, uint32_t param_3)
{
    int32_t* in_ECX = static_cast<int32_t*>(self);
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t iVar1;
    uint32_t uVar2 = ((uint32_t)(param_1 >> 8) << 8) | *(uint8_t*)(s + 0xf3);
    if (*(char*)(s + 0xf3) != '\0') {
        param_3 = param_3 & 0x1000;
    }
    if ((param_3 & 0x2000) == 0) {
        if ((param_3 & 2) != 0) {
            uVar2 = (uint32_t)in_ECX[0x8f];
            in_ECX[0x3d] = 5;
            if (uVar2 != 0 && in_ECX[0x95] != -1) {
                uVar2 = FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
            }
        }
    } else {
        iVar1 = in_ECX[0x8f];
        in_ECX[0x3d] = 3;
        if (iVar1 != 0 && in_ECX[0x93] != -1) {
            iVar1 = (int32_t)FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
        }
        uVar2 = ((uint32_t)iVar1 & 0xffffff00) | *(uint8_t*)(s + 0xf2);
        if (*(char*)(s + 0xf2) == '\0') {
            *(uint8_t*)(s + 0xf2) = 1;
        }
    }
    if ((param_3 & 0x4000) == 0) {
        if ((param_3 & 0x20000) != 0) {
            uVar2 = (uint32_t)in_ECX[0x8f];
            in_ECX[0x3d] = 6;
            if (uVar2 != 0 && in_ECX[0x96] != -1) {
                uVar2 = FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
            }
        }
    } else {
        uVar2 = (uVar2 & 0xffffff00) | *(uint8_t*)(s + 0xf2);
        if (*(char*)(s + 0xf2) != '\0') {
            uVar2 = (uint32_t)in_ECX[0x8f];
            in_ECX[0x3d] = 4;
            if (uVar2 != 0 && in_ECX[0x94] != -1) {
                uVar2 = FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
            }
            *(uint8_t*)(s + 0xf2) = 0;
        }
    }
    if (((param_3 & 0x4000) != 0) || ((param_3 & 0x120000) != 0)) {
        auto fn = *reinterpret_cast<uint32_t(**)()>(*in_ECX + 0xb4);
        uVar2 = fn();
    }
    if ((param_3 & 0x248000) == 0) {
        if ((param_3 & 0x1000) != 0) {
            auto fn = *reinterpret_cast<uint32_t(**)()>(*in_ECX + 0xb4);
            uVar2 = fn();
            return uVar2 & 0xffffff00;
        }
        if ((param_3 & 0x400000) != 0) {
            auto fn = *reinterpret_cast<uint32_t(**)()>(*in_ECX + 0xb4);
            uVar2 = fn();
            return uVar2 & 0xffffff00;
        }
        if ((param_3 & 0x800000) != 0) {
            auto fn = *reinterpret_cast<uint32_t(**)()>(*in_ECX + 0xb4);
            uVar2 = fn();
            return uVar2 & 0xffffff00;
        }
    } else {
        auto fn = *reinterpret_cast<uint32_t(**)()>(*in_ECX + 0xb4);
        uVar2 = fn();
    }
    (void)param_2;
    return uVar2 & 0xffffff00;
}

// 0x5079e0 — observed shape
uint32_t FUN_005079e0(void* self)
{
    int32_t* in_ECX = static_cast<int32_t*>(self);
    uint8_t* s = static_cast<uint8_t*>(self);
    uint32_t uVar1;
    if (*(char*)(s + 0xf3) == '\0') {
        auto fn = *reinterpret_cast<uint32_t(**)()>(*in_ECX + 0xb4);
        uVar1 = fn();
        return uVar1;
    }
    return (uint32_t)((char)in_ECX[0x3c] == '\0');
}
// 0x507a10 — observed shape
void FUN_00507a10(void* self, uint32_t param_1, uint32_t param_2)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t iVar1;
    int32_t iVar2;
    if ((*(uint8_t*)(s + 0x20) & 1) != 0) return;
    if (*(int32_t*)(s + 0x23c) != 0) {
        FUN_005059e0(*(int32_t*)(s + 0x23c), param_1, 1);
        iVar2 = *(int32_t*)(s + 0x23c);
        iVar1 = FUN_00506440();
        if (iVar1 == -1) {
            if (*(char*)(s + 0xf1) == '\0') {
                *(uint32_t*)(s + 0xf4) = 0;
                if (iVar2 == 0) goto LAB_00507aa6;
                iVar2 = *(int32_t*)(s + 0x240);
            } else {
                if (*(int32_t*)(s + 0xf4) == 7 || (*(uint32_t*)(s + 0xf4) = 7, iVar2 == 0)) goto LAB_00507aa6;
                iVar2 = *(int32_t*)(s + 0x25c);
            }
            if (iVar2 != -1) {
                FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
            }
        }
    }
LAB_00507aa6:
    FUN_0053ae40(param_1, param_2);
}

// 0x507ac0 — observed shape
void FUN_00507ac0(int32_t param_1, uint32_t param_2)
{
    extern uint32_t DAT_00727560;
    extern uint32_t DAT_007278a8;
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(param_1 + 0xd0);
    do {
        if (puVar3 == nullptr) {
            uint32_t uVar5 = 0;
            if (*(int32_t*)(param_1 + 0xc0) != 0) {
                if (*(int32_t*)(param_1 + 0xc0) == 0) goto LAB_00507b70;
                do {
                    int32_t* piVar1 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(param_1 + 0xb8) + uVar5 * 4);
                    if (piVar1 != nullptr) {
                        for (uint32_t* puVar2 = (uint32_t*)(**(uint32_t*(**)())(*piVar1 + 4))(); puVar2 != nullptr; puVar2 = (uint32_t*)puVar2[1]) {
                            if (puVar2 == &DAT_00727560) {
                                uint32_t uVar4;
                                if (uVar5 < *(uint32_t*)(param_1 + 0xc0)) {
                                    uVar4 = *(uint32_t*)(*reinterpret_cast<int32_t*>(param_1 + 0xb8) + uVar5 * 4);
                                } else {
                                    uVar4 = 0;
                                }
                                FUN_00507ac0((int32_t)uVar4, param_2);
                                break;
                            }
                        }
                    }
LAB_00507b70:
                    uVar5 = uVar5 + 1;
                } while (uVar5 < *(uint32_t*)(param_1 + 0xc0));
            }
            return;
        }
        uint32_t* piVar1 = puVar3 + 2;
        puVar3 = (uint32_t*)*puVar3;
        if ((int32_t*)*piVar1 != nullptr) {
            for (uint32_t* puVar2 = (uint32_t*)(**(uint32_t*(**)())(*(int32_t*)*piVar1 + 4))(); puVar2 != nullptr; puVar2 = (uint32_t*)puVar2[1]) {
                if (puVar2 == &DAT_007278a8) {
                    FUN_005353a0();
                    FUN_00535670(param_2);
                    break;
                }
            }
        }
    } while (true);
}

// 0x507b90 — observed shape
void FUN_00507b90(void* self)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t iVar1;
    GUID local_34;
    char local_24[36];
    CoCreateGuid(&local_34);
    sprintf(local_24, "%X%X%X%X", (unsigned)local_34.Data1, (unsigned)local_34.Data2, (unsigned)local_34.Data3, local_34.Data4);
    iVar1 = *(int32_t*)(s + 0xfc);
    if (iVar1 != 0) {
        FUN_00504070((int32_t)(intptr_t)self);
    }
    FUN_00540460(local_24);
    if (iVar1 != 0) {
        FUN_00503fb0((int32_t)(intptr_t)self);
    }
}

// 0x507c00 — observed shape
void FUN_00507c00(void* self, uint32_t param_1)
{
    uint32_t* unaff_ESI = static_cast<uint32_t*>(self);
    uint32_t local_18, local_14, local_10, local_c, local_8, local_4;
    FUN_00522ee0();
    FUN_00522f40(param_1, 1);
    *unaff_ESI = local_18;
    unaff_ESI[1] = local_10;
    unaff_ESI[2] = local_14;
    unaff_ESI[3] = local_c;
    unaff_ESI[4] = local_4;
    unaff_ESI[5] = local_8;
}

// 0x507c90 — observed shape
void FUN_00507c90(void* self, int32_t param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t iVar1 = param_1;
    FUN_0053a940(param_1);
    auto fn = *reinterpret_cast<void(**)(void*, uint32_t)>(*reinterpret_cast<int32_t*>(iVar1 + 0x15c) + 8);
    fn(reinterpret_cast<void*>(&param_1), 4);
    fn(s + 0xec, 4);
    fn(s + 0xf0, 1);
    fn(s + 0xf3, 1);
    fn(s + 0x240, 0x50);
    fn(s + 0x13c, 0x100);
}
// 0x507d20 — observed shape
void FUN_00507d20(void* self, int32_t param_1)
{
    char* pcVar1;
    char cVar2;
    int32_t iVar3;
    char* pcVar4;
    uint8_t* s = static_cast<uint8_t*>(self);
    iVar3 = param_1;
    FUN_0053b820(param_1);
    param_1 = 0x3f800000;
    auto fn = *reinterpret_cast<void(**)(void*, uint32_t)>(*reinterpret_cast<int32_t*>(iVar3 + 0x160) + 0xc);
    fn(reinterpret_cast<void*>(&param_1), 4);
    fn(s + 0xec, 4);
    fn(s + 0xf0, 1);
    fn(s + 0xf3, 1);
    fn(s + 0x240, 0x50);
    pcVar1 = reinterpret_cast<char*>(s + 0x13c);
    pcVar4 = pcVar1;
    do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    for (pcVar4 = pcVar4 + (-1 - (intptr_t)(s + 0x13d)); (0 < (int)(intptr_t)pcVar4 && (pcVar1[(int)(intptr_t)pcVar4] != '\\')); pcVar4 = pcVar4 + -1) {
    }
    if (pcVar4 != nullptr) {
        pcVar4 = pcVar4 + (intptr_t)s + 0x13d;
        int32_t iVar5 = (int32_t)((intptr_t)pcVar1 - (intptr_t)pcVar4);
        do {
            cVar2 = *pcVar4;
            pcVar4[iVar5] = cVar2;
            pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
    }
    fn(pcVar1, 0x100);
}

// 0x507e00 — observed shape
int32_t* FUN_00507e00(void* self, int32_t param_1)
{
    int32_t* in_ECX = static_cast<int32_t*>(self);
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t* piVar2;
    int32_t iVar3;
    uint32_t uVar4;
    uint8_t auStack_104[2];
    uint8_t auStack_102[258];
    FUN_00540ef0(param_1);
    piVar2 = (int32_t*)(uint32_t)*(uint8_t*)(s + 0x4f);
    if (*(uint8_t*)(s + 0x4f) != 0) {
        iVar3 = FUN_00533c78(0x8c);
        if (iVar3 == 0) {
            iVar3 = 0;
        } else {
            iVar3 = FUN_00504990(iVar3);
        }
        in_ECX[0x8f] = iVar3;
        piVar2 = *reinterpret_cast<int32_t**>(param_1 + 0x128);
        FUN_00567810(s + 0x4f);
        auto fn1 = *reinterpret_cast<void(**)()>(*piVar2 + 4);
        fn1();
        auto fn2 = *reinterpret_cast<char(**)(void*)>(*piVar2 + 8);
        char cVar1 = fn2(auStack_104);
        while (cVar1 != '\0') {
            cVar1 = FUN_004f4ed0();
            if (cVar1 != '\0') {
                FUN_005050f0(in_ECX[0x8f], 0, 1);
                uVar4 = (**(uint32_t(**)(uint32_t))(*in_ECX + 0x40))(*(uint32_t*)(*(int32_t*)(in_ECX[0x8f] + 0x58) + 0xc));
                FUN_00505420(uVar4);
                break;
            }
            cVar1 = fn2(auStack_104 + -4);
        }
        piVar2 = in_ECX + 0x90;
        iVar3 = 0x14;
        do {
            piVar2 = piVar2 + 1;
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
    }
    (void)auStack_102;
    return piVar2;
}

// 0x507ef0 — observed shape
void FUN_00507ef0(void* self, uint32_t param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    extern uint32_t DAT_008ecd60;
    extern uint32_t DAT_008ea0a4;
    extern uint32_t DAT_008ca4e4, DAT_008ca4ec, DAT_008ca4e8, DAT_008ca4f0;
    DAT_008ca4e4 = 0;
    DAT_008ca4ec = 0;
    DAT_008ca4e8 = 0;
    DAT_008ca4f0 = 0;
    if ((*(uint8_t*)(s + 0x20) & 1) == 0) {
        uint32_t uVar3 = 0;
        if (*(int32_t*)(s + 0xc0) != 0) {
            if (*(int32_t*)(s + 0xc0) == 0) goto LAB_00507f7a;
LAB_00507f27:;
            int32_t* piVar1 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(s + 0xb8) + uVar3 * 4);
            if (piVar1 != nullptr) {
                void* puVar2;
                for (puVar2 = (void*)(**(void*(**)())(*piVar1 + 4))(); puVar2 != nullptr; puVar2 = *reinterpret_cast<void**>((uint8_t*)puVar2 + 4)) {
                    if (puVar2 == &DAT_008ecd60) goto LAB_00507f8c;
                }
                for (puVar2 = (void*)(**(void*(**)())(*piVar1 + 4))(); puVar2 != nullptr; puVar2 = *reinterpret_cast<void**>((uint8_t*)puVar2 + 4)) {
                    if (puVar2 == &DAT_008ea0a4) goto LAB_00507f8c;
                }
                auto fn = *reinterpret_cast<void(**)(uint32_t)>(*piVar1 + 0x60);
                fn(param_1);
            }
            goto LAB_00507f7a;
        }
    }
    return;
LAB_00507f8c:;
    {
        int32_t* piVar1 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(s + 0xb8) + 0);
        (void)piVar1;
    }
    {
        uint32_t uVar3 = 0;
        int32_t* piVar1 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(s + 0xb8) + uVar3 * 4);
        auto fn = *reinterpret_cast<void(**)(uint32_t)>(*piVar1 + 0x84);
        fn(param_1);
LAB_00507f7a:;
        uVar3 = uVar3 + 1;
        if (*(uint32_t*)(s + 0xc0) <= uVar3) return;
        goto LAB_00507f27;
    }
}

// 0x507fa0 — observed shape
uint32_t FUN_00507fa0(void* self, float* pfSelf, int32_t param_1, int32_t param_2)
{
    extern uint32_t DAT_008ecd60;
    extern int32_t* DAT_008ea08c;
    int32_t* in_EAX = static_cast<int32_t*>(self);
    (void)pfSelf;
    float fVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7;
    int32_t iVar9;
    int32_t iVar11;
    if (in_EAX != nullptr) {
        int32_t* piVar12 = in_EAX;
        if (in_EAX == nullptr) goto LAB_00507fce;
        do {
            void* puVar8;
            for (puVar8 = (void*)(**(void*(**)())(*piVar12 + 4))(); puVar8 != nullptr; puVar8 = *reinterpret_cast<void**>((uint8_t*)puVar8 + 4)) {
                if (puVar8 == &DAT_008ecd60) {
                    fVar1 = (float)piVar12[0x4a];
                    fVar2 = (float)piVar12[0x4b];
                    fVar3 = (float)piVar12[0x4c];
                    fVar4 = (float)piVar12[0x4d];
                    if (in_EAX == (int32_t*)piVar12[0xad]) return 1;
                    if (in_EAX == (int32_t*)piVar12[0xac]) return 1;
                    if ((int32_t*)in_EAX[9] == (int32_t*)piVar12[0xad]) return 1;
                    if ((int32_t*)in_EAX[9] == (int32_t*)piVar12[0xac]) return 1;
                    if (fVar2 == 0.0f) return 1;
                    FUN_004ffe50();
                    iVar9 = (**(int32_t(**)())(*DAT_008ea08c + 0x58))();
                    float* pfVar10 = (float*)FUN_005074d0();
                    fVar5 = (float)(iVar9 / 2) + *pfVar10;
                    FUN_004ffe50();
                    iVar9 = (**(int32_t(**)())(*DAT_008ea08c + 0x5c))();
                    iVar11 = (int32_t)FUN_005074d0();
                    fVar6 = (float)(iVar9 / 2) + *(float*)(iVar11 + 4);
                    fVar7 = (float)param_1;
                    fVar1 = fVar1 + fVar5;
                    if ((fVar1 < fVar7 != (fVar1 == fVar7)) && (fVar7 <= fVar5 + fVar2)) {
                        fVar1 = (float)param_2;
                        fVar3 = fVar3 + fVar6;
                        if ((fVar3 < fVar1 != (fVar3 == fVar1)) && (fVar1 <= fVar4 + fVar6)) {
                            return 1;
                        }
                    }
                    return 0;
                }
            }
LAB_00507fce:;
            piVar12 = (int32_t*)piVar12[9];
        } while (piVar12 != nullptr);
    }
    return 1;
}

// 0x508120 — observed shape
void FUN_00508120(void* self)
{
    extern uint32_t* DAT_008cad20;
    extern uint32_t DAT_0071779c, DAT_007177a0, DAT_007177a4, DAT_007177a8;
    uint32_t* in_EAX = static_cast<uint32_t*>(self);
    in_EAX[5] = 0;
    in_EAX[6] = 0;
    in_EAX[7] = 0;
    in_EAX[8] = 0;
    in_EAX[9] = 0;
    in_EAX[10] = 0;
    in_EAX[0xb] = 0;
    in_EAX[0xc] = 0;
    in_EAX[0xd] = 0;
    in_EAX[0xe] = 0;
    in_EAX[0xf] = 0;
    in_EAX[0x10] = 0;
    in_EAX[0x13] = 0;
    in_EAX[0x14] = 0;
    in_EAX[0x15] = 0;
    in_EAX[0x16] = 0;
    in_EAX[0x17] = 0;
    in_EAX[0x18] = (uint32_t)(intptr_t)DAT_008cad20;
    DAT_008cad20 = in_EAX;
    *in_EAX = 0;
    in_EAX[5] = DAT_0071779c;
    in_EAX[6] = DAT_007177a0;
    in_EAX[7] = DAT_007177a4;
    in_EAX[8] = DAT_007177a8;
    in_EAX[0x19] = 0;
}
// 0x508190 — observed shape
void FUN_00508190(void* self)
{
    extern uint32_t* DAT_008cad20;
    uint32_t* unaff_ESI = static_cast<uint32_t*>(self);
    uint32_t* piVar2;
    uint32_t* puVar4;
    uint32_t* puVar1;
    int32_t iVar3;
    piVar2 = &DAT_008cad20;
    if (DAT_008cad20 != nullptr) {
        do {
            if ((uint32_t*)*piVar2 == unaff_ESI) break;
            piVar2 = (uint32_t*)*piVar2 + 0x18;
        } while (*piVar2 != nullptr);
        if (*piVar2 != nullptr) {
            *piVar2 = *(uint32_t*)((uint8_t*)*piVar2 + 0x60);
        }
    }
    puVar4 = (uint32_t*)unaff_ESI[0x13];
    if (puVar4 != nullptr) {
        piVar2 = puVar4 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar4)(1);
        unaff_ESI[0x13] = 0;
    }
    puVar4 = (uint32_t*)unaff_ESI[0x14];
    if (puVar4 != nullptr) {
        piVar2 = puVar4 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar4)(1);
        unaff_ESI[0x14] = 0;
    }
    puVar4 = (uint32_t*)unaff_ESI[0x15];
    if (puVar4 != nullptr) {
        piVar2 = puVar4 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar4)(1);
        unaff_ESI[0x15] = 0;
    }
    puVar4 = (uint32_t*)unaff_ESI[0x16];
    if (puVar4 != nullptr) {
        piVar2 = puVar4 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar4)(1);
        unaff_ESI[0x16] = 0;
    }
    puVar4 = (uint32_t*)unaff_ESI[0x17];
    if (puVar4 != nullptr) {
        piVar2 = puVar4 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar4)(1);
        unaff_ESI[0x17] = 0;
    }
    if ((void*)*unaff_ESI != nullptr) {
        operator_delete((void*)*unaff_ESI);
        *unaff_ESI = 0;
    }
    if (unaff_ESI[0x19] != 0) unaff_ESI[0x19] = 0;
    if ((void*)unaff_ESI[0x12] != nullptr) {
        operator_delete__((void*)unaff_ESI[0x12]);
        unaff_ESI[0x12] = 0;
    }
    if ((uint32_t*)unaff_ESI[0x11] != nullptr) {
        (*(void(**)(uint32_t))**(uint32_t**)unaff_ESI[0x11])(1);
        unaff_ESI[0x11] = 0;
    }
    puVar4 = unaff_ESI + 0x18;
    iVar3 = 2;
    do {
        puVar1 = (uint32_t*)puVar4[-1];
        puVar4 = puVar4 - 1;
        if (puVar1 != nullptr) {
            piVar2 = puVar1 + 1;
            *piVar2 = *piVar2 - 1;
            if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar1)(1);
        }
        iVar3 = iVar3 - 1;
    } while (iVar3 != 0);
    puVar4 = (uint32_t*)unaff_ESI[0x15];
    if (puVar4 != nullptr) {
        piVar2 = puVar4 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar4)(1);
    }
    puVar4 = (uint32_t*)unaff_ESI[0x14];
    if (puVar4 != nullptr) {
        piVar2 = puVar4 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar4)(1);
    }
    puVar4 = (uint32_t*)unaff_ESI[0x13];
    if (puVar4 != nullptr) {
        piVar2 = puVar4 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) (**(void(**)(uint32_t))*puVar4)(1);
    }
}

// 0x5082d0 — observed shape
bool FUN_005082d0(char* self, char* param_1)
{
    char* in_EAX = self;
    if (in_EAX == nullptr) return false;
    if (param_1 != nullptr) {
        int32_t iVar2 = _stricmp(in_EAX, param_1);
        if (iVar2 != 0) {
            char* pcVar3 = strrchr(in_EAX, 0x2f);
            char* pcVar4 = strrchr(in_EAX, 0x5c);
            if (pcVar4 < pcVar3) in_EAX = pcVar3 + 1;
            if (pcVar3 < pcVar4) in_EAX = pcVar4 + 1;
            pcVar3 = param_1;
            char cVar1;
            do {
                cVar1 = *pcVar3;
                pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            iVar2 = _strnicmp(in_EAX, param_1, (int)((intptr_t)pcVar3 - (intptr_t)(param_1 + 1)));
            return iVar2 == 0;
        }
    }
    return true;
}

// 0x508360 — observed shape
void FUN_00508360(void* self, uint32_t p1, uint32_t p2)
{
    extern uint32_t PTR_FUN_0070bf10, PTR_FUN_0070bf4c;
    int32_t* piVar1;
    char cVar2;
    char* in_EAX;
    uint32_t* puVar3;
    char* pcVar4;
    uint32_t* puVar5;
    uint32_t* unaff_ESI = static_cast<uint32_t*>(self);
    int32_t iVar6;
    int32_t aiStack_10[4];
    aiStack_10[1] = 2;
    aiStack_10[3] = 2;
    aiStack_10[2] = 1;
    puVar3 = (uint32_t*)FUN_00539c10();
    puVar5 = (uint32_t*)unaff_ESI[0x13];
    if (puVar5 != puVar3) {
        if (puVar5 != nullptr) {
            piVar1 = (int32_t*)puVar5 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar5)(1);
        }
        unaff_ESI[0x13] = (uint32_t)(intptr_t)puVar3;
        if (puVar3 != nullptr) puVar3[1] = puVar3[1] + 1;
    }
    pcVar4 = strrchr(in_EAX, 0x5c);
    if (pcVar4 == nullptr) {
        pcVar4 = strrchr(in_EAX, 0x2f);
        if (pcVar4 == nullptr) goto LAB_005083d9;
        iVar6 = 0x2f;
    } else {
        iVar6 = 0x5c;
    }
    pcVar4 = strrchr(in_EAX, iVar6);
    in_EAX = pcVar4 + 1;
LAB_005083d9:;
    pcVar4 = in_EAX;
    do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    pcVar4 = (char*)thunk_FUN_00533c78(pcVar4 + (1 - (intptr_t)(in_EAX + 1)));
    *unaff_ESI = (uint32_t)(intptr_t)pcVar4;
    do {
        cVar2 = *in_EAX;
        in_EAX = in_EAX + 1;
        *pcVar4 = cVar2;
        pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    iVar6 = FUN_00533c78(0x48);
    if (iVar6 == 0) {
        puVar5 = nullptr;
    } else {
        puVar5 = (uint32_t*)FUN_005428c0();
    }
    puVar3 = (uint32_t*)unaff_ESI[0x14];
    if (puVar3 != puVar5) {
        if (puVar3 != nullptr) {
            piVar1 = (int32_t*)puVar3 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar3)(1);
        }
        unaff_ESI[0x14] = (uint32_t)(intptr_t)puVar5;
        if (puVar5 != nullptr) puVar5[1] = puVar5[1] + 1;
    }
    FUN_004aad70(unaff_ESI[0x13]);
    iVar6 = **(int32_t**)(unaff_ESI[0x14] + 0x2c);
    if (iVar6 == 0) {
        iVar6 = FUN_00533c78(0x1c);
        if (iVar6 == 0) iVar6 = 0;
        else iVar6 = FUN_005426d0();
        aiStack_10[0] = iVar6;
        FUN_005606f0(0, aiStack_10);
    }
    *(uint32_t*)(iVar6 + 0xc) = 2;
    puVar5 = (uint32_t*)FUN_00533c78(0x2c);
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    } else {
        FUN_00540c50();
        *puVar5 = (uint32_t)(intptr_t)&PTR_FUN_0070bf10;
        *(uint16_t*)((uint8_t*)puVar5 + 0x20) = 0;
        puVar5[9] = 0;
        puVar5[10] = 1;
    }
    puVar3 = (uint32_t*)unaff_ESI[0x15];
    if (puVar3 != puVar5) {
        if (puVar3 != nullptr) {
            piVar1 = (int32_t*)puVar3 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar3)(1);
        }
        unaff_ESI[0x15] = (uint32_t)(intptr_t)puVar5;
        if (puVar5 != nullptr) puVar5[1] = puVar5[1] + 1;
    }
    *(uint32_t*)((uint8_t*)unaff_ESI[0x15] + 0x24) = 1;
    *(uint32_t*)((uint8_t*)unaff_ESI[0x15] + 0x28) = 0;
    puVar5 = (uint32_t*)FUN_00533c78(0x24);
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    } else {
        FUN_00540c50();
        *puVar5 = (uint32_t)(intptr_t)&PTR_FUN_0070bf4c;
        *(uint16_t*)((uint8_t*)puVar5 + 0x20) = 0xec;
        *(uint8_t*)((uint8_t*)puVar5 + 0x22) = 0;
    }
    puVar3 = (uint32_t*)unaff_ESI[0x16];
    if (puVar3 != puVar5) {
        if (puVar3 != nullptr) {
            piVar1 = (int32_t*)puVar3 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar3)(1);
        }
        unaff_ESI[0x16] = (uint32_t)(intptr_t)puVar5;
        if (puVar5 != nullptr) puVar5[1] = puVar5[1] + 1;
    }
    *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) | 1;
    *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) & 0xffed | 0xc;
    *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) & 0xfeff | 0xe0;
    *(uint8_t*)((uint8_t*)unaff_ESI[0x16] + 0x21) = *(uint8_t*)((uint8_t*)unaff_ESI[0x16] + 0x21) | 2;
    *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) & 0xf7ff | 0x1400;
    *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x16] + 0x20) & 0xdfff;
    *(uint8_t*)((uint8_t*)unaff_ESI[0x16] + 0x22) = 0;
    puVar5 = (uint32_t*)FUN_00533c78(0x24);
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    } else {
        FUN_00540c50();
        *puVar5 = (uint32_t)(intptr_t)&PTR_FUN_0070bf4c;
        *(uint16_t*)((uint8_t*)puVar5 + 0x20) = 0xec;
        *(uint8_t*)((uint8_t*)puVar5 + 0x22) = 0;
    }
    puVar3 = (uint32_t*)unaff_ESI[0x17];
    if (puVar3 != puVar5) {
        if (puVar3 != nullptr) {
            piVar1 = (int32_t*)puVar3 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar3)(1);
        }
        unaff_ESI[0x17] = (uint32_t)(intptr_t)puVar5;
        if (puVar5 != nullptr) puVar5[1] = puVar5[1] + 1;
    }
    *(uint8_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) = *(uint8_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) | 1;
    *(uint16_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) & 0xffed | 0xc;
    *(uint16_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) & 0xfe1f;
    *(uint8_t*)((uint8_t*)unaff_ESI[0x17] + 0x21) = *(uint8_t*)((uint8_t*)unaff_ESI[0x17] + 0x21) | 2;
    *(uint16_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) & 0xf7ff | 0x1400;
    *(uint16_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) = *(uint16_t*)((uint8_t*)unaff_ESI[0x17] + 0x20) & 0xdfff;
    *(uint8_t*)((uint8_t*)unaff_ESI[0x17] + 0x22) = 0;
    FUN_00509970(unaff_ESI, p1, p2);
    unaff_ESI[4] = 0x3f800000;
}

// 0x508670 — observed shape
void FUN_00508670(uint32_t* param_1, char* param_2)
{
    extern uint32_t PTR_FUN_006f583c, PTR_FUN_006f5864, PTR_FUN_007115bc, PTR_FUN_007115d8;
    extern uint32_t PTR_FUN_0070bf10, PTR_FUN_0070bf4c;
    extern uint32_t* DAT_00727044;
    extern uint32_t DAT_00727050;
    extern uint32_t DAT_00736464;
    extern uint32_t DAT_008cacd0;
    extern uint32_t DAT_008cacc8;
    extern int DAT_008cace4;
    int32_t* piVar1;
    char cVar2;
    char* pcVar3;
    char* pcVar4;
    void* pvVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    int32_t iVar9, iVar10, iVar11;
    uint32_t uVar12;
    uint32_t local_344;
    int32_t local_340;
    uint32_t* local_33c;
    uint32_t local_338, local_334, local_330, local_32c, local_328, local_324;
    uint32_t* local_320;
    uint32_t local_314;
    int32_t local_310;
    void* local_30c;
    uint32_t local_308[4];
    uint8_t local_304;
    uint8_t auStack_303[3];
    char local_300[256];
    char local_200[512];
    pcVar3 = strrchr(param_2, 0x5c);
    if (pcVar3 == nullptr && (pcVar3 = strrchr(param_2, 0x2f), pcVar3 == nullptr)) {
        pcVar3 = param_2;
        do { cVar2 = *pcVar3; pcVar3 = pcVar3 + 1; } while (cVar2 != '\0');
        pcVar4 = (char*)thunk_FUN_00533c78(pcVar3 + (1 - (intptr_t)(param_2 + 1)));
        *param_1 = (uint32_t)(intptr_t)pcVar4;
        pcVar3 = param_2;
        do { cVar2 = *pcVar3; pcVar3 = pcVar3 + 1; *pcVar4 = cVar2; pcVar4 = pcVar4 + 1; } while (cVar2 != '\0');
        pcVar3 = param_2;
        do { cVar2 = *pcVar3; pcVar3[(intptr_t)(local_200 - param_2)] = cVar2; pcVar3 = pcVar3 + 1; } while (cVar2 != '\0');
        uVar12 = 0;
        if (DAT_00727050 != 0) {
            do {
                sprintf(local_200, "%s%s", *(char**)(DAT_00727044 + uVar12 * 4), param_2);
                cVar2 = FUN_004f4ed0();
                if (cVar2 != '\0') break;
                uVar12 = uVar12 + 1;
            } while (uVar12 < DAT_00727050);
        }
    } else {
        pcVar3 = param_2;
        do { cVar2 = *pcVar3; pcVar3[(intptr_t)(local_200 - param_2)] = cVar2; pcVar3 = pcVar3 + 1; } while (cVar2 != '\0');
        pcVar3 = strrchr(param_2, 0x5c);
        if (pcVar3 == nullptr) {
            pcVar3 = strrchr(param_2, 0x2f);
            if (pcVar3 != nullptr) { iVar11 = 0x2f; goto LAB_00508778; }
        } else {
            iVar11 = 0x5c;
LAB_00508778:;
            param_2 = strrchr(param_2, iVar11);
            param_2 = param_2 + 1;
        }
        pcVar3 = param_2;
        do { cVar2 = *pcVar3; pcVar3 = pcVar3 + 1; } while (cVar2 != '\0');
        pcVar4 = (char*)thunk_FUN_00533c78(pcVar3 + (1 - (intptr_t)(param_2 + 1)));
        *param_1 = (uint32_t)(intptr_t)pcVar4;
        pcVar3 = param_2;
        do { cVar2 = *pcVar3; pcVar3 = pcVar3 + 1; *pcVar4 = cVar2; pcVar4 = pcVar4 + 1; } while (cVar2 != '\0');
    }
    local_320 = &DAT_008cacd0;
    local_338 = 0; local_334 = 0; local_330 = 0; local_32c = 0; local_328 = 0; local_324 = 0;
    local_33c = &PTR_FUN_006f583c;
    local_314 = 0;
    local_310 = 0;
    FUN_004f4b20(local_200, 1, 0, 0x8000);
    if (local_310 == 0) FUN_004f10f0(&local_344, 4);
    else FUN_004fe190(&local_344);
    pvVar5 = (void*)thunk_FUN_00533c78(local_344 * 2 + 2);
    local_30c = pvVar5;
    if (local_310 == 0) FUN_004f10f0(pvVar5, local_344 * 2);
    else FUN_004fe190(pvVar5);
    uVar6 = thunk_FUN_00533c78((local_344 * 3 + 3) * 8);
    param_1[0x12] = uVar6;
    *(uint16_t*)((uint8_t*)pvVar5 + local_344 * 2) = 0;
    if (local_310 == 0) FUN_004f10f0(local_308, 4); else FUN_004fe190(local_308);
    if (local_310 == 0) FUN_004f10f0(&local_304, 4); else FUN_004fe190(&local_304);
    if (local_310 == 0) FUN_004f10f0(param_1 + 1, 4); else FUN_004fe190(param_1 + 1);
    if (local_310 == 0) FUN_004f10f0(param_1[0x12], (local_344 * 3 + 3) * 8); else FUN_004fe190(param_1[0x12]);
    FUN_004f4de0();
    puVar7 = (uint32_t*)FUN_00533c78(0x10);
    if (puVar7 == nullptr) {
        puVar7 = nullptr;
    } else {
        *puVar7 = (uint32_t)(intptr_t)&PTR_FUN_007115bc;
        puVar7[1] = 0x100;
        puVar7[3] = 0;
        puVar8 = (uint32_t*)thunk_FUN_00533c78(0x400);
        puVar7[2] = (uint32_t)(intptr_t)puVar8;
        for (uVar12 = puVar7[1] & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) { *puVar8 = 0; puVar8 = puVar8 + 1; }
        for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) { *(uint8_t*)puVar8 = 0; puVar8 = (uint32_t*)((uint8_t*)puVar8 + 1); }
        *puVar7 = (uint32_t)(intptr_t)&PTR_FUN_007115d8;
    }
    uVar12 = 0;
    param_1[0x11] = (uint32_t)(intptr_t)puVar7;
    if (local_344 != 0) {
        local_340 = 0;
        do {
            FUN_0050afa0(param_1[0x12] + local_340);
            uVar12 = uVar12 + 1;
            local_340 = local_340 + 0x18;
        } while (uVar12 < local_344);
    }
    FUN_0050afa0(param_1[0x12] + local_344 * 0x18);
    iVar11 = -(int32_t)(intptr_t)param_2;
    do { cVar2 = *param_2; param_2[(intptr_t)(local_300 + iVar11)] = cVar2; param_2 = param_2 + 1; } while (cVar2 != '\0');
    pcVar3 = local_300;
    do { cVar2 = *pcVar3; pcVar3 = pcVar3 + 1; } while (cVar2 != '\0');
    local_344 = (int32_t)((intptr_t)pcVar3 - (intptr_t)(local_300 + 1));
    *(uint32_t**)(auStack_303 + local_344) = &DAT_00736464;
    cVar2 = FUN_004f4ed0();
    if (cVar2 == '\0') *(uint32_t*)(auStack_303 + local_344) = 0x616774;
    puVar8 = (uint32_t*)FUN_00500850();
    puVar7 = (uint32_t*)param_1[0x13];
    if (puVar7 != puVar8) {
        if (puVar7 != nullptr) {
            piVar1 = (int32_t*)puVar7 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar7)(1);
        }
        param_1[0x13] = (uint32_t)(intptr_t)puVar8;
        if (puVar8 != nullptr) puVar8[1] = puVar8[1] + 1;
    }
    uVar6 = (**(uint32_t(**)())(*(uint32_t*)param_1[0x13] + 0x38))();
    param_1[3] = uVar6;
    uVar6 = (**(uint32_t(**)())(*(uint32_t*)param_1[0x13] + 0x34))();
    param_1[2] = uVar6;
    iVar11 = FUN_00533c78(0x48);
    if (iVar11 == 0) puVar7 = nullptr; else puVar7 = (uint32_t*)FUN_005428c0();
    puVar8 = (uint32_t*)param_1[0x14];
    if (puVar8 != puVar7) {
        if (puVar8 != nullptr) {
            piVar1 = (int32_t*)puVar8 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar8)(1);
        }
        param_1[0x14] = (uint32_t)(intptr_t)puVar7;
        if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
    }
    iVar11 = (int32_t)param_1[0x14];
    iVar9 = **(int32_t**)(iVar11 + 0x2c);
    puVar7 = (uint32_t*)param_1[0x13];
    if (iVar9 == 0) {
        iVar9 = FUN_00533c78(0x1c);
        if (iVar9 == 0) iVar9 = 0; else iVar9 = FUN_005426d0();
        if (*(int32_t*)(iVar11 + 0x30) != 0) {
            if (*(int32_t*)(iVar11 + 0x34) == 0) {
                *(uint32_t*)(iVar11 + 0x34) = 1;
                if (iVar9 != 0) { iVar10 = *(int32_t*)(iVar11 + 0x38) + 1; goto LAB_00508b1f; }
            } else if (iVar9 == 0) {
                if (**(int32_t**)(iVar11 + 0x2c) != 0) { iVar10 = *(int32_t*)(iVar11 + 0x38) - 1; goto LAB_00508b1f; }
            } else if (**(int32_t**)(iVar11 + 0x2c) == 0) {
                iVar10 = *(int32_t*)(iVar11 + 0x38) + 1;
LAB_00508b1f:;
                *(int32_t*)(iVar11 + 0x38) = iVar10;
            }
            **(int32_t**)(iVar11 + 0x2c) = iVar9;
        }
    }
    puVar8 = *(uint32_t**)(iVar9 + 4);
    if (puVar8 != puVar7) {
        if (puVar8 != nullptr) {
            piVar1 = (int32_t*)puVar8 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar8)(1);
        }
        *(uint32_t**)(iVar9 + 4) = puVar7;
        if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
    }
    iVar11 = (int32_t)param_1[0x14];
    iVar9 = **(int32_t**)(iVar11 + 0x2c);
    if (iVar9 == 0) {
        iVar9 = FUN_00533c78(0x1c);
        if (iVar9 == 0) iVar9 = 0; else iVar9 = FUN_005426d0();
        if (*(int32_t*)(iVar11 + 0x30) != 0) {
            if (*(int32_t*)(iVar11 + 0x34) == 0) {
                *(uint32_t*)(iVar11 + 0x34) = 1;
                if (iVar9 != 0) {
                    *(int32_t*)(iVar11 + 0x38) = *(int32_t*)(iVar11 + 0x38) + 1;
                    **(int32_t**)(iVar11 + 0x2c) = iVar9;
                    goto LAB_00508bb5;
                }
            } else if (iVar9 == 0) {
                if (**(int32_t**)(iVar11 + 0x2c) != 0) *(int32_t*)(iVar11 + 0x38) = *(int32_t*)(iVar11 + 0x38) - 1;
            } else if (**(int32_t**)(iVar11 + 0x2c) == 0) {
                *(int32_t*)(iVar11 + 0x38) = *(int32_t*)(iVar11 + 0x38) + 1;
                **(int32_t**)(iVar11 + 0x2c) = iVar9;
                goto LAB_00508bb5;
            }
            **(int32_t**)(iVar11 + 0x2c) = iVar9;
        }
    }
LAB_00508bb5:;
    *(uint32_t*)(iVar9 + 0xc) = 2;
    puVar7 = (uint32_t*)FUN_00533c78(0x2c);
    if (puVar7 == nullptr) puVar7 = nullptr;
    else {
        FUN_00540c50();
        *puVar7 = (uint32_t)(intptr_t)&PTR_FUN_0070bf10;
        *(uint16_t*)((uint8_t*)puVar7 + 0x20) = 0;
        puVar7[9] = 0;
        puVar7[10] = 1;
    }
    puVar8 = (uint32_t*)param_1[0x15];
    if (puVar8 != puVar7) {
        if (puVar8 != nullptr) {
            piVar1 = (int32_t*)puVar8 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar8)(1);
        }
        param_1[0x15] = (uint32_t)(intptr_t)puVar7;
        if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
    }
    *(uint32_t*)((uint8_t*)param_1[0x15] + 0x24) = 1;
    *(uint32_t*)((uint8_t*)param_1[0x15] + 0x28) = 0;
    puVar7 = (uint32_t*)FUN_00533c78(0x24);
    if (puVar7 == nullptr) puVar7 = nullptr;
    else {
        FUN_00540c50();
        *puVar7 = (uint32_t)(intptr_t)&PTR_FUN_0070bf4c;
        *(uint16_t*)((uint8_t*)puVar7 + 0x20) = 0xec;
        *(uint8_t*)((uint8_t*)puVar7 + 0x22) = 0;
    }
    puVar8 = (uint32_t*)param_1[0x16];
    if (puVar8 != puVar7) {
        if (puVar8 != nullptr) {
            piVar1 = (int32_t*)puVar8 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar8)(1);
        }
        param_1[0x16] = (uint32_t)(intptr_t)puVar7;
        if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
    }
    *(uint8_t*)((uint8_t*)param_1[0x16] + 0x20) = *(uint8_t*)((uint8_t*)param_1[0x16] + 0x20) | 1;
    *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) & 0xffed | 0xc;
    *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) & 0xfeff | 0xe0;
    *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) | 0x200;
    *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) & 0xf7ff | 0x1400;
    *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x16] + 0x20) & 0xdfff;
    *(uint8_t*)((uint8_t*)param_1[0x16] + 0x22) = 0;
    puVar7 = (uint32_t*)FUN_00533c78(0x24);
    if (puVar7 == nullptr) puVar7 = nullptr;
    else {
        FUN_00540c50();
        *puVar7 = (uint32_t)(intptr_t)&PTR_FUN_0070bf4c;
        *(uint16_t*)((uint8_t*)puVar7 + 0x20) = 0xec;
        *(uint8_t*)((uint8_t*)puVar7 + 0x22) = 0;
    }
    puVar8 = (uint32_t*)param_1[0x17];
    if (puVar8 != puVar7) {
        if (puVar8 != nullptr) {
            piVar1 = (int32_t*)puVar8 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar8)(1);
        }
        param_1[0x17] = (uint32_t)(intptr_t)puVar7;
        if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
    }
    *(uint8_t*)((uint8_t*)param_1[0x17] + 0x20) = *(uint8_t*)((uint8_t*)param_1[0x17] + 0x20) | 1;
    *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) & 0xffed | 0xc;
    *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) & 0xfe1f;
    *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) | 0x200;
    *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) & 0xf7ff | 0x1400;
    *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) = *(uint16_t*)((uint8_t*)param_1[0x17] + 0x20) & 0xdfff;
    *(uint8_t*)((uint8_t*)param_1[0x17] + 0x22) = 0;
    if (local_30c != nullptr) operator_delete__(local_30c);
    param_1[4] = 0x3f800000;
    local_33c = &PTR_FUN_006f583c;
    cVar2 = FUN_004f4e60();
    if (cVar2 != '\0') {
        if (local_310 == 0) {
            FUN_004f0dc0();
        } else {
            *(uint32_t*)((uint8_t*)local_310 + 0x14) = 0;
            local_310 = 0;
            local_314 = 0;
            if (*(int32_t*)((uint8_t*)local_320 - 4) != 0) {
                *local_320 = 0;
                *(uint32_t*)((uint8_t*)local_320 - 4) = 0;
            }
        }
        InterlockedDecrement(&DAT_008cace4);
    }
    local_33c = &PTR_FUN_006f5864;
    FUN_004f0dc0();
    puVar7 = (uint32_t*)((uint8_t*)local_320 - 8);
    if (puVar7 != nullptr && puVar7 != &DAT_008cacc8) operator_delete__(puVar7);
}

// 0x508e20 — observed shape
uint32_t FUN_00508e20(void* self, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, float param_7, float param_8, float param_9, float param_10)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t iVar1;
    uint32_t uVar2;
    if (param_7 == -1.0f && param_8 == -1.0f && param_9 == -1.0f && param_10 == -1.0f) {
        param_7 = *(float*)(s + 0x14);
        param_8 = *(float*)(s + 0x18);
        param_9 = *(float*)(s + 0x1c);
        param_10 = *(float*)(s + 0x20);
    }
    iVar1 = FUN_00533c78(0x44);
    if (iVar1 == 0) uVar2 = 0;
    else uVar2 = FUN_0050a2d0(param_7, param_8, param_9, param_10);
    FUN_00508fa0((int32_t)(intptr_t)self, p2, p3, p4, p5, p6, uVar2, 0, param_7, param_8, param_9, param_10);
    return uVar2;
}
