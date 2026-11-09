#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_004ed8f0(uint32_t param_1);
extern void FUN_00517f90();
extern void FUN_00533d10(float param_1, int param_2);
extern void FUN_00535de0(int param_1);
extern void FUN_00582f50();
extern void FUN_00583070(void* param_1, void* param_2, int param_3);
extern void FUN_005831c0();
extern bool FUN_00507fa0(int param_1, int param_2);
extern int* DAT_008ea08c;
extern void* DAT_008ea0a4;

// 0x504070 — observed shape
void FUN_00504070(int* param_1, void* self) {
    auto* self_ints = static_cast<int*>(self);
    auto* self_bytes = static_cast<uint8_t*>(self);
    using Func = void(*)();
    using Func2 = void*(*)();
    int* piVar3;
    uint32_t uVar4;
    (void)self_ints;
    if (param_1 == *reinterpret_cast<int**>(self_bytes + 0xc)) {
        *reinterpret_cast<uint32_t*>(self_bytes + 0xc) = 0;
    }
    if (param_1 == *reinterpret_cast<int**>(self_bytes + 8)) {
        *reinterpret_cast<uint32_t*>(self_bytes + 8) = 0;
    }
    uVar4 = 0;
    if (param_1 == *reinterpret_cast<int**>(self_bytes + 0x10)) {
        *reinterpret_cast<uint32_t*>(self_bytes + 0x10) = 0;
    }
    if (param_1 == *reinterpret_cast<int**>(self_bytes + 0x14)) {
        *reinterpret_cast<uint32_t*>(self_bytes + 0x14) = 0;
    }
    if (param_1 == *reinterpret_cast<int**>(self_bytes + 0x18)) {
        *reinterpret_cast<uint32_t*>(self_bytes + 0x18) = 0;
    }
    if (param_1[0x30] != 0) {
        do {
            piVar3 = *reinterpret_cast<int**>(param_1[0x2e] + uVar4 * 4);
            if (piVar3 != nullptr) {
                auto* vtbl = *reinterpret_cast<void**>(piVar3);
                auto fn4 = *reinterpret_cast<Func2*>(static_cast<uint8_t*>(vtbl) + 4);
                void* puVar2 = fn4();
                while (puVar2 != nullptr) {
                    if (puVar2 == &DAT_008ea0a4) {
                        FUN_00504070(piVar3, nullptr);
                        break;
                    }
                    puVar2 = *reinterpret_cast<void**>(static_cast<uint8_t*>(puVar2) + 4);
                }
            }
        } while (++uVar4 < static_cast<uint32_t>(param_1[0x30]));
    }
    FUN_004ed8f0(static_cast<uint32_t>(param_1[3]));
    param_1[0x3f] = 0;
    if (param_1[0x3e] != 0) {
        if (*reinterpret_cast<int**>(self_bytes + 0x24) != nullptr) {
            piVar3 = *reinterpret_cast<int**>(self_bytes + 0x24);
            do {
                int* piVar1 = reinterpret_cast<int*>(*piVar3);
                if (param_1[0x3e] == piVar3[2]) {
                    goto cleanup_check;
                }
                piVar3 = piVar1;
            } while (piVar1 != nullptr);
        }
        piVar3 = nullptr;
    cleanup_check:
        if (piVar3 != nullptr) {
            FUN_00517f90();
        }
    }
    {
        auto* vtbl = *reinterpret_cast<void**>(param_1);
        auto fn = *reinterpret_cast<Func*>(static_cast<uint8_t*>(vtbl) + 0xc4);
        fn();
    }
}

// 0x504160 — observed shape
void FUN_00504160(void* self) {
    if (self == nullptr) {
        return;
    }
    FUN_00504070(static_cast<int*>(self), nullptr);
    {
        auto* ints = static_cast<int*>(self);
        auto* obj = reinterpret_cast<int*>(ints[9]);
        auto* vtbl = *reinterpret_cast<void**>(obj);
        using Fn = void(*)(void*);
        auto fn = *reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0x74);
        uint8_t local_4[4] = {0};
        fn(local_4);
    }
    if (self != nullptr) {
        auto* ints = static_cast<int*>(self);
        int iVar1 = ints[1];
        ints[1] = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            auto* vtbl = *reinterpret_cast<void**>(ints);
            using Fn = void(*)(int);
            auto fn = *reinterpret_cast<Fn*>(vtbl);
            fn(1);
        }
    }
}

// 0x5041a0 — observed shape
void FUN_005041a0(void* self, void* self2) {
    auto* unaff_EDI = static_cast<int*>(self2);
    int in_EAX = static_cast<int>(reinterpret_cast<uintptr_t>(self));
    auto release_ref = [](int* p) {
        if (p != nullptr) {
            int* piVar1 = p + 1;
            if ((*piVar1 = *piVar1 + -1) == 0) {
                auto* vtbl = *reinterpret_cast<void**>(p);
                using Fn = void(*)(int);
                (*reinterpret_cast<Fn*>(vtbl))(1);
            }
        }
    };
    if (unaff_EDI != nullptr && *unaff_EDI != 0 && unaff_EDI[1] != 0) {
        if (in_EAX != 0) {
            FUN_00535de0(in_EAX);
        }
        if (unaff_EDI[0x11] != 0 && reinterpret_cast<int*>(unaff_EDI[0x12]) != nullptr) {
            auto* obj = reinterpret_cast<int*>(unaff_EDI[0x12]);
            auto* vtbl = *reinterpret_cast<void**>(obj);
            using Fn = void(*)();
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0x70))();
        }
        int iVar2 = *unaff_EDI;
        int* piVar3 = *reinterpret_cast<int**>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2))) + 0x188);
        {
            auto* vtbl = *reinterpret_cast<void**>(piVar3);
            using Fn = void(*)(int, int, int, int, int, int);
            auto fn = *reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xc4);
            fn(iVar2 + 0x90, iVar2 + 0x104, iVar2 + 0x110, iVar2 + 0x11c, iVar2 + 0x128, iVar2 + 0x144);
        }
        auto* puVar4 = reinterpret_cast<int*>(piVar3[3]);
        auto* puVar5 = reinterpret_cast<int*>(unaff_EDI[0x13]);
        if (puVar4 != puVar5) {
            release_ref(puVar4);
            piVar3[3] = static_cast<int>(reinterpret_cast<uintptr_t>(puVar5));
            if (puVar5 != nullptr) {
                puVar5[1] = puVar5[1] + 1;
            }
        }
        {
            auto* vtbl = *reinterpret_cast<void**>(piVar3);
            using Fn = void(*)();
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xbc))();
        }
        {
            auto* obj = reinterpret_cast<int*>(unaff_EDI[0x13]);
            auto* vtbl = *reinterpret_cast<void**>(obj);
            using Fn = void(*)(int);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0x34))(*unaff_EDI);
        }
        {
            auto* obj = reinterpret_cast<int*>(unaff_EDI[1]);
            auto* vtbl = *reinterpret_cast<void**>(obj);
            using Fn = void(*)(int);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0x84))(*unaff_EDI);
        }
        {
            auto* obj = reinterpret_cast<int*>(unaff_EDI[0x13]);
            auto* vtbl = *reinterpret_cast<void**>(obj);
            using Fn = void(*)();
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0x38))();
        }
        {
            auto* vtbl = *reinterpret_cast<void**>(piVar3);
            using Fn = void(*)();
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xc0))();
        }
        puVar5 = reinterpret_cast<int*>(piVar3[3]);
        if (puVar5 != puVar4) {
            release_ref(puVar5);
            piVar3[3] = static_cast<int>(reinterpret_cast<uintptr_t>(puVar4));
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
    }
}

// 0x5042a0 — observed shape
void FUN_005042a0(float param_1, void* self) {
    auto* self_bytes = static_cast<uint8_t*>(self);
    float fVar1 = param_1 + *reinterpret_cast<float*>(self_bytes + 0x40);
    *reinterpret_cast<float*>(self_bytes + 0x40) = fVar1;
    FUN_00533d10(fVar1, 1);
    if (*reinterpret_cast<int**>(self_bytes + 0x44) != nullptr) {
        auto* obj = *reinterpret_cast<int**>(self_bytes + 0x44);
        {
            auto* vtbl = *reinterpret_cast<void**>(obj);
            using Fn = void(*)(float);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xc))(param_1);
        }
        int iVar2 = *reinterpret_cast<int*>(self_bytes + 0x44);
        if (*reinterpret_cast<int*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2))) + 0x48) == 0) {
            fVar1 = 0.0f;
        } else {
            fVar1 = *reinterpret_cast<float*>(*reinterpret_cast<int*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2))) + 0x48) + 0x44);
        }
        if (fVar1 <= *reinterpret_cast<float*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2))) + 0x2c)) {
            *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2))) + 0x2c) = 0;
        }
    }
}

// 0x504310 — observed shape
int* FUN_00504310(int param_1, int param_2, void* self) {
    if (self == nullptr) {
        return nullptr;
    }
    FUN_00582f50();
    float fVar4 = static_cast<float>(param_1);
    int* piVar10 = nullptr;
    if (param_1 < 0) {
        fVar4 = fVar4 + 4.2949673e+09f;
    }
    int iVar7;
    {
        auto* vtbl = *reinterpret_cast<void**>(DAT_008ea08c);
        using Fn = int(*)();
        iVar7 = (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0x58))();
    }
    float fVar5 = static_cast<float>(param_2);
    if (param_2 < 0) {
        fVar5 = fVar5 + 4.2949673e+09f;
    }
    int iVar8;
    {
        auto* vtbl = *reinterpret_cast<void**>(DAT_008ea08c);
        using Fn = int(*)();
        iVar8 = (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0x5c))();
    }
    auto* in_EAX = static_cast<int*>(self);
    int iVar1 = *in_EAX;
    int* puVar2 = reinterpret_cast<int*>(in_EAX[1]);
    float fStack_50 = *reinterpret_cast<float*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar1))) + 0x90);
    float fStack_4c = *reinterpret_cast<float*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar1))) + 0x94);
    float fStack_48 = *reinterpret_cast<float*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar1))) + 0x98);
    int* puStack_24_local = nullptr;
    int iStack_1c = 0;
    uint32_t uStack_14 = 0;
    (void)puStack_24_local;
    (void)iStack_1c;
    (void)uStack_14;
    // Sentinel for puStack_24: use static thread-local stand-in via explicit arg modeling
    // Observed: swap puStack_24 with puVar2 refcount handling
    static int* stack_24_holder = nullptr;
    static int stack_1c_holder = 0;
    static uint32_t stack_14_holder = 0;
    if (stack_24_holder != puVar2) {
        if (stack_24_holder != nullptr &&
            (iVar1 = stack_24_holder[1], stack_24_holder[1] = iVar1 + -1, iVar1 + -1 == 0)) {
            auto* vtbl = *reinterpret_cast<void**>(stack_24_holder);
            using Fn = void(*)(int);
            (*reinterpret_cast<Fn*>(vtbl))(1);
        }
        stack_24_holder = puVar2;
        if (puVar2 != nullptr) {
            puVar2[1] = puVar2[1] + 1;
        }
    }
    float fStack_44 = (fVar4 / static_cast<float>(iVar7) - 0.5f) * 1024.0f - fStack_50;
    float fStack_40 = -fStack_4c;
    uint32_t uStack_30 = 1;
    uint8_t uStack_27 = 1;
    float fStack_3c = ((1.0f - fVar5 / static_cast<float>(iVar8)) - 0.5f) * 768.0f - fStack_48;
    (void)fStack_40; (void)uStack_30; (void)uStack_27; (void)fStack_3c;
    FUN_00583070(&fStack_50, &fStack_44, 0);
    uint32_t uVar11 = 0;
    if (stack_14_holder != 0) {
        do {
            int* piVar3 = *reinterpret_cast<int**>(stack_1c_holder + uVar11 * 4);
            piVar10 = reinterpret_cast<int*>(piVar3[1]);
            if (piVar10 != nullptr) goto check_sentinel;
            for (piVar10 = *reinterpret_cast<int**>(*reinterpret_cast<uint8_t*>(piVar3) + 0x24); piVar10 != nullptr; piVar10 = reinterpret_cast<int*>(piVar10[9])) {
            check_sentinel:
                {
                    auto* vtbl = *reinterpret_cast<void**>(piVar10);
                    using Fn2 = void*(*)();
                    auto fn = *reinterpret_cast<Fn2*>(static_cast<uint8_t*>(vtbl) + 4);
                    void* puVar9 = fn();
                    while (puVar9 != nullptr) {
                        if (puVar9 == &DAT_008ea0a4) {
                            bool cVar6 = FUN_00507fa0(param_1, param_2);
                            if (!cVar6 || static_cast<char>(piVar10[0x3c]) != '\0') goto next_entry;
                            goto done;
                        }
                        puVar9 = *reinterpret_cast<void**>(static_cast<uint8_t*>(puVar9) + 4);
                    }
                }
            }
        next_entry:
            piVar10 = nullptr;
            uVar11 = uVar11 + 1;
        } while (uVar11 < stack_14_holder);
    }
done:
    FUN_005831c0();
    return piVar10;
}

extern bool FUN_0051bfc0(void* param_1);
extern void FUN_005044d0(int param_1);
extern void FUN_00504530(uint32_t param_1);
extern void FUN_004e6420(void* self);
extern void* PTR_FUN_007111e8;
extern void* PTR_FUN_00711204;
extern void* PTR_FUN_00711220;

// 0x5044d0 — observed shape
void FUN_005044d0(int param_1, void* self) {
    auto* unaff_ESI = static_cast<int*>(self);
    int iVar2 = param_1;
    int param_1_copy = param_1;
    bool cVar3 = FUN_0051bfc0(&param_1_copy);
    if (!cVar3 || *(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(unaff_ESI)) + 0xf3) != '\0' ||
        (reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2))) + 8)) == unaff_ESI)) {
        return;
    }
    auto* piVar1 = *reinterpret_cast<int**>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2))) + 8);
    if (piVar1 != nullptr) {
        auto* vtbl = *reinterpret_cast<void**>(piVar1);
        using Fn = void(*)(int);
        (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xbc))(0);
    }
    *reinterpret_cast<int**>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2))) + 8) = unaff_ESI;
    param_1 = 1;
    (void)param_1;
    // WARNING: Could not recover jumptable at 0x0050451c. Treating indirect jump as call (offset 0xbc)
    {
        auto* vtbl = *reinterpret_cast<void**>(unaff_ESI);
        using Fn = void(*)();
        (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xbc))();
    }
}

// 0x504530 — observed shape
void FUN_00504530(uint32_t param_1, void* self, void* self2) {
    auto* unaff_ESI = static_cast<int*>(self);
    auto* unaff_EDI = static_cast<int*>(self2);
    auto esi_bytes = static_cast<uint8_t*>(static_cast<void*>(unaff_ESI));
    if (*reinterpret_cast<int*>(esi_bytes + 8) != 0 &&
        *(reinterpret_cast<char*>(*reinterpret_cast<int*>(esi_bytes + 8)) + 0xf3) != '\0') {
        *reinterpret_cast<uint32_t*>(esi_bytes + 8) = 0;
    }
    auto* piVar1 = *reinterpret_cast<int**>(esi_bytes + 8);
    if (unaff_EDI != piVar1 && (param_1 & 0x2000u) != 0) {
        if (piVar1 != nullptr) {
            auto* vtbl = *reinterpret_cast<void**>(piVar1);
            using Fn = void(*)(int);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xbc))(0);
        }
        if (unaff_EDI == nullptr || *(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(unaff_EDI)) + 0xf3) == '\0') {
            *reinterpret_cast<int**>(esi_bytes + 8) = unaff_EDI;
        }
        if (*reinterpret_cast<int**>(esi_bytes + 8) != nullptr) {
            // WARNING: Could not recover jumptable at 0x00504588. Treating indirect jump as call (offset 0xbc)
            auto* obj = *reinterpret_cast<int**>(esi_bytes + 8);
            auto* vtbl = *reinterpret_cast<void**>(obj);
            using Fn = void(*)();
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xbc))();
        }
    }
}

// 0x5045a0 — observed shape
uint32_t FUN_005045a0(int param_1, int param_2, int param_3, void* self, uint32_t unaff_EBX, uint32_t in_EAX) {
    if (param_1 == 0) {
        return in_EAX & 0xffffff00u;
    }
    bool bVar2 = false;
    auto* piVar3 = FUN_00504310(param_2, param_3, self);
    auto* base = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_1));
    auto* piVar1 = *reinterpret_cast<int**>(base + 0xc);
    if (piVar1 != nullptr && *(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(piVar1)) + 0xf2) != '\0') {
        piVar3 = piVar1;
    }
    piVar1 = *reinterpret_cast<int**>(base + 0xc);
    if (piVar3 != piVar1) {
        bVar2 = true;
        if (piVar1 != nullptr) {
            auto* vtbl = *reinterpret_cast<void**>(piVar1);
            using Fn = void(*)(int);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xb0))(0);
        }
        *reinterpret_cast<int**>(base + 0xc) = piVar3;
        if (piVar3 != nullptr) {
            auto* vtbl = *reinterpret_cast<void**>(piVar3);
            using Fn = void(*)(int);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xb0))(1);
        }
    }
    FUN_00504530(unaff_EBX, self);
    if ((unaff_EBX & 0x2000u) == 0) {
        if ((unaff_EBX & 0x80000u) == 0) {
            if ((unaff_EBX & 0x10000u) != 0) {
                *reinterpret_cast<int**>(base + 0x18) = piVar3;
            }
        } else {
            *reinterpret_cast<int**>(base + 0x14) = piVar3;
        }
    } else {
        *reinterpret_cast<int**>(base + 0x10) = piVar3;
    }
    if (*reinterpret_cast<int**>(base + 8) != nullptr && (unaff_EBX & 0xc00000u) != 0) {
        auto* obj = *reinterpret_cast<int**>(base + 8);
        auto* vtbl = *reinterpret_cast<void**>(obj);
        using Fn = void(*)(int, int);
        (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xac))(param_2, param_3);
        return (uint32_t)(piVar3 != nullptr);
    }
    if ((unaff_EBX & 0x4000u) == 0) {
        if ((unaff_EBX & 0x100000u) == 0) {
            if ((unaff_EBX & 0x20000u) == 0) {
                if (piVar3 != nullptr &&
                    ((unaff_EBX & 0x1000u) == 0 || bVar2 ||
                     *(reinterpret_cast<char*>(*reinterpret_cast<int*>(base + 0xc)) + 0xf2) != '\0')) {
                    auto* vtbl = *reinterpret_cast<void**>(piVar3);
                    using Fn = void(*)(int, int);
                    (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xac))(param_2, param_3);
                }
            } else if (*reinterpret_cast<int*>(base + 0x18) != 0) {
                FUN_005044d0(param_1, self);
                auto* obj = *reinterpret_cast<int**>(base + 0x18);
                auto* vtbl = *reinterpret_cast<void**>(obj);
                using Fn = void(*)(int, int);
                (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xac))(param_2, param_3);
                *reinterpret_cast<uint32_t*>(base + 0x18) = 0;
                return (uint32_t)(piVar3 != nullptr);
            }
        } else if (*reinterpret_cast<int*>(base + 0x14) != 0) {
            FUN_005044d0(param_1, self);
            auto* obj = *reinterpret_cast<int**>(base + 0x14);
            auto* vtbl = *reinterpret_cast<void**>(obj);
            using Fn = void(*)(int, int);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xac))(param_2, param_3);
            *reinterpret_cast<uint32_t*>(base + 0x14) = 0;
            return (uint32_t)(piVar3 != nullptr);
        }
    } else if (*reinterpret_cast<int*>(base + 0x10) != 0) {
        FUN_005044d0(param_1, self);
        auto* obj = *reinterpret_cast<int**>(base + 0x10);
        auto* vtbl = *reinterpret_cast<void**>(obj);
        using Fn = void(*)(int, int);
        (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 0xac))(param_2, param_3);
        *reinterpret_cast<uint32_t*>(base + 0x10) = 0;
        return (uint32_t)(piVar3 != nullptr);
    }
    return (uint32_t)(piVar3 != nullptr);
}

// 0x504770 — observed shape
void FUN_00504770(void* self) {
    auto* in_ECX = static_cast<int*>(self);
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_007111e8));
    if (*(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(in_ECX)) + 4) != '\0' && in_ECX[1] != 0) {
        uint32_t uVar3 = 0;
        do {
            auto* puVar2 = *reinterpret_cast<int**>(in_ECX[2] + uVar3 * 4);
            while (puVar2 != nullptr) {
                auto* puVar1 = puVar2 + 1;
                puVar2 = reinterpret_cast<int*>(*puVar2);
                operator delete(reinterpret_cast<void*>(*puVar1));
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < static_cast<uint32_t>(in_ECX[1]));
    }
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_00711220));
    FUN_004e6420(self);
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_00711204));
    FUN_004e6420(self);
    operator delete(reinterpret_cast<void*>(in_ECX[2]));
}

// 0x5047f0 — observed shape
void FUN_005047f0(uint8_t param_1, void* self) {
    auto* in_ECX = static_cast<int*>(self);
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_00711204));
    FUN_004e6420(self);
    operator delete(reinterpret_cast<void*>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator delete(in_ECX);
    }
}

extern void FUN_00504770(void* self);
extern void FUN_00504910(void* self);
extern void FUN_00504950(void* self);
extern void* PTR_FUN_007111d0;
extern void* PTR_LAB_007111b8;

// 0x504830 — observed shape
void FUN_00504830(uint8_t param_1, void* self) {
    auto* in_ECX = static_cast<int*>(self);
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_00711220));
    FUN_004e6420(self);
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_00711204));
    FUN_004e6420(self);
    operator delete(reinterpret_cast<void*>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator delete(in_ECX);
    }
}

// 0x504870 — observed shape
void FUN_00504870(uint8_t param_1, void* self) {
    FUN_00504770(self);
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x5048d0 — observed shape
void FUN_005048d0(uint8_t param_1, void* self) {
    FUN_00504910(self);
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x5048f0 — observed shape
void FUN_005048f0(uint8_t param_1, void* self) {
    FUN_00504950(self);
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x504910 — observed shape
void FUN_00504910(void* self) {
    auto* in_ECX = static_cast<int*>(self);
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_007111d0));
    auto* puVar2 = reinterpret_cast<int*>(in_ECX[1]);
    while (puVar2 != nullptr) {
        auto* puVar1 = reinterpret_cast<int*>(*puVar2);
        {
            auto* vtbl = *reinterpret_cast<void**>(in_ECX);
            using Fn = void(*)(int*);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 8))(puVar2);
        }
        puVar2 = puVar1;
    }
    in_ECX[3] = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_LAB_007111b8));
}

extern void FUN_00506bf0(void* self);
extern void FUN_00506bb0(void* self);
extern void FUN_00504e00(void* self);
extern void FUN_00524ad0(const char* format, uint32_t arg);
extern void* thunk_FUN_00533c78(uint32_t size);
extern int FUN_00506730(int param_1);
extern int FUN_00506800(int param_1);
extern int* DAT_008cad14;
extern int* DAT_008cad18;
extern int* DAT_008cad1c;
extern void* PTR_FUN_007111dc;
extern void* PTR_LAB_007111c4;
extern void* PTR_FUN_0071131c;
extern void* PTR_FUN_00711328;
extern void* PTR_FUN_00711254;
extern void* PTR_FUN_00711270;
extern void* PTR_FUN_0071128c;

// 0x504950 — observed shape
void FUN_00504950(void* self) {
    auto* in_ECX = static_cast<int*>(self);
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_007111dc));
    auto* puVar2 = reinterpret_cast<int*>(in_ECX[1]);
    while (puVar2 != nullptr) {
        auto* puVar1 = reinterpret_cast<int*>(*puVar2);
        {
            auto* vtbl = *reinterpret_cast<void**>(in_ECX);
            using Fn = void(*)(int*);
            (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 8))(puVar2);
        }
        puVar2 = puVar1;
    }
    in_ECX[3] = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    *in_ECX = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_LAB_007111c4));
}

// 0x504990 — observed shape
int FUN_00504990(void* self, int param_1) {
    auto* base = static_cast<uint8_t*>(self);
    auto* field = [&](int off) -> uint32_t& { return *reinterpret_cast<uint32_t*>(base + off); };
    field(0x10) = 0;
    field(0x20) = 0;
    field(0x18) = 0;
    field(0x1c) = 0;
    *reinterpret_cast<void**>(base + 0x14) = &PTR_FUN_0071131c;
    field(0x30) = 0;
    field(0x28) = 0;
    field(0x2c) = 0;
    *reinterpret_cast<void**>(base + 0x24) = &PTR_FUN_0071131c;
    field(0x40) = 0;
    field(0x38) = 0;
    field(0x3c) = 0;
    *reinterpret_cast<void**>(base + 0x34) = &PTR_FUN_0071131c;
    field(0x50) = 0;
    field(0x48) = 0;
    field(0x4c) = 0;
    *reinterpret_cast<void**>(base + 0x44) = &PTR_FUN_00711328;
    *reinterpret_cast<void**>(base + 0x5c) = &PTR_FUN_00711254;
    field(0x60) = 0x25;
    field(0x68) = 0;
    auto* puVar3 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
    *reinterpret_cast<uint32_t**>(base + 100) = puVar3;
    for (uint32_t uVar4 = field(0x60) & 0x3fffffffu; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
    }
    int iVar2;
    for (int iVar5 = 0; (iVar2 = DAT_008cad14 != nullptr ? *DAT_008cad14 : 0, iVar5 != 0); iVar5 = iVar5 + -1) {
        *reinterpret_cast<uint8_t*>(puVar3) = 0;
        puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar3) + 1);
    }
    (void)iVar2;
    *reinterpret_cast<void**>(base + 0x5c) = &PTR_FUN_00711270;
    *reinterpret_cast<void**>(base + 0x6c) = &PTR_FUN_0071128c;
    field(0x74) = 0;
    field(0x80) = 1;
    field(0x78) = 0;
    field(0x7c) = 0;
    field(0x70) = 0;
    if (DAT_008cad14 == nullptr) {
        if (thunk_FUN_00533c78(0x14) == nullptr) {
            DAT_008cad14 = nullptr;
        } else {
            DAT_008cad14 = reinterpret_cast<int*>(static_cast<uintptr_t>(FUN_00506730(1)));
        }
        if (thunk_FUN_00533c78(0x14) == nullptr) {
            DAT_008cad18 = nullptr;
        } else {
            DAT_008cad18 = reinterpret_cast<int*>(static_cast<uintptr_t>(FUN_00506800(1)));
        }
    }
    auto* puVar3b = *reinterpret_cast<int**>(base + 0x10);
    if (puVar3b != nullptr) {
        auto* piVar1 = puVar3b + 1;
        if ((*piVar1 = *piVar1 + -1) == 0) {
            auto* vtbl = *reinterpret_cast<void**>(puVar3b);
            using Fn = void(*)(int);
            (*reinterpret_cast<Fn*>(vtbl))(1);
        }
        field(0x10) = 0;
    }
    field(0x84) = 0;
    field(0x54) = 0;
    field(0x58) = 0;
    field(8) = 0;
    field(0xc) = 0;
    field(4) = 0;
    *reinterpret_cast<uint8_t*>(base + 0x89) = 0;
    return param_1;
}

// 0x504ad0 — observed shape
void FUN_00504ad0(uint8_t param_1, void* self) {
    FUN_00506bf0(self);
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x504af0 — observed shape
void FUN_00504af0(uint8_t param_1, void* self) {
    FUN_00506bb0(self);
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x504b10 — observed shape
void FUN_00504b10(int param_1, void* self) {
    auto* base = static_cast<uint8_t*>(self);
    if (DAT_008cad1c != nullptr && *(base + 0x89) != '\0') {
    joined:
        auto* piVar1 = DAT_008cad1c;
        auto* puVar2 = *reinterpret_cast<int**>(base + 0x38);
        if (puVar2 != nullptr) {
            uint32_t uVar3 = static_cast<uint32_t>(puVar2[2]);
            puVar2 = reinterpret_cast<int*>(*puVar2);
            int iVar7;
            {
                auto* inner = reinterpret_cast<int*>(piVar1[1]);
                auto* vtbl = *reinterpret_cast<void**>(inner);
                using Fn = int(*)(uint32_t);
                iVar7 = (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 4))(uVar3);
            }
            auto* puVar4 = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(static_cast<void*>(piVar1)) + 0x??0) + iVar7;
            (void)puVar4;
            // Observed loop: iterate bucket list matching uVar3; preserve structure via getter vtable +8
            auto* bucket = *reinterpret_cast<int**>(static_cast<uint8_t*>(reinterpret_cast<void*>(piVar1)) + 12 + iVar7 * 4);
            for (auto* cur = bucket; cur != nullptr; cur = reinterpret_cast<int*>(*cur)) {
                bool matched;
                {
                    auto* inner = reinterpret_cast<int*>(piVar1[1]);
                    auto* vtbl = *reinterpret_cast<void**>(inner);
                    using Fn = bool(*)(uint32_t, int);
                    matched = (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 8))(uVar3, cur[1]);
                }
                if (matched) {
                    uint32_t uVar5 = static_cast<uint32_t>(cur[2]);
                    FUN_004ed8f0(uVar3);
                    {
                        auto* vtbl = *reinterpret_cast<void**>(piVar1);
                        using Fn = void(*)(uint32_t);
                        (*reinterpret_cast<Fn*>(static_cast<uint8_t*>(vtbl) + 8))(uVar5);
                    }
                    goto joined;
                }
            }
            FUN_00524ad0("Attempt to invalidate cache for uncached animation (anim=0x%x)", uVar3);
            goto joined;
        }
    }
    FUN_00504e00(self);
    *reinterpret_cast<void**>(base + 0x6c) = &PTR_FUN_0071128c;
    operator delete(*reinterpret_cast<void**>(base + 0x70));
    *reinterpret_cast<void**>(base + 0x5c) = &PTR_FUN_00711270;
    FUN_004e6420(self);
    *reinterpret_cast<void**>(base + 0x5c) = &PTR_FUN_00711254;
    FUN_004e6420(self);
    operator delete(*reinterpret_cast<void**>(base + 100));
    FUN_00506bb0(self);
    FUN_00506bf0(self);
    FUN_00506bf0(self);
    FUN_00506bf0(self);
    auto* puVar2 = *reinterpret_cast<int**>(base + 0x10);
    if (puVar2 != nullptr) {
        auto* piVar1 = puVar2 + 1;
        if ((*piVar1 = *piVar1 + -1) == 0) {
            // WARNING: Could not recover jumptable at 0x00504c14
            auto* vtbl = *reinterpret_cast<void**>(puVar2);
            using Fn = void(*)();
            (*reinterpret_cast<Fn*>(vtbl))();
            return;
        }
    }
}
