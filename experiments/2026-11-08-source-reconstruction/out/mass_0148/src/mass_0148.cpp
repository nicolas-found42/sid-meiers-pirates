// Reconstruction batch mass_0148 — Sid Meier's Pirates! (2004), PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* PTR_FUN_006c2a70;
extern void* PTR_FUN_00711770;
extern void* PTR_FUN_006c2ad0;
extern void* PTR_FUN_006c2b54;
extern void FUN_0055ab90();
extern uint32_t FUN_0055abd0(int param_1);
extern void FUN_0055abb0();
extern void FUN_0055ac40();
extern void FUN_0055ac70();
extern void FUN_0055aca0(int param_1);
extern uint32_t FUN_00538460(int param_1);
extern uint32_t FUN_00557a60(int param_1);
extern uint32_t FUN_005480d0(int param_1);
extern uint32_t FUN_00557b10(uint32_t addr);
extern int FUN_00557cb0(const char* name, uint32_t value);
extern int FUN_00557d40(const char* name, uint32_t value);
extern void FUN_005606f0(uint32_t index, int* value);
extern void FUN_006b34a0(int offset);
extern void FUN_00513ce0(int param_1);
extern uint32_t* FUN_00545600();
extern void FUN_00538400();
extern void FUN_004127b0(int addr, int size, uint32_t count, void* fill);
extern uint32_t DAT_00727cc8;
extern void* LAB_00556820;
extern void operator_delete(void* ptr);
extern void operator_delete__(void*);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void FUN_00556330(int, int);
extern void FUN_0054bc90();
extern void thunk_FUN_00538410(void*, uint32_t);
extern void FUN_0055ab40(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void* PTR_FUN_006c2a70;
extern void* PTR_FUN_00711770;
extern void* PTR_FUN_006c2ad0;
extern void* FUN_00533c78(uint32_t);

// 0x556430 — observed shape
void FUN_00556430(void* self_param) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_param);
    int* piVar3;
    uint32_t uVar1;
    int iVar2;
    if (in_ECX[3] == 0) {
        return;
    }
    {
        uint32_t vtable = *in_ECX;
        using Fn = void(*)();
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(vtable + 0x40));
        fn();
    }
    iVar2 = static_cast<int>(in_ECX[8]);
    in_ECX[0xc] = static_cast<uint32_t>(iVar2);
    if (iVar2 == 0) {
        piVar3 = nullptr;
    } else {
        in_ECX[0xc] = static_cast<uint32_t>(iVar2 + -1);
        piVar3 = *reinterpret_cast<int**>(in_ECX[10] + (iVar2 + -1) * 4);
    }
    uVar1 = *reinterpret_cast<uint32_t*>(in_ECX[3] + 0x188);
    if (piVar3 != nullptr) {
        do {
            {
                uint32_t vtable = *reinterpret_cast<uint32_t*>(piVar3);
                using Fn = void(*)(uint32_t);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(vtable + 0x70));
                fn(uVar1);
            }
            if (in_ECX[0xc] == 0) break;
            iVar2 = static_cast<int>(in_ECX[0xc]) + -1;
            in_ECX[0xc] = static_cast<uint32_t>(iVar2);
            piVar3 = *reinterpret_cast<int**>(in_ECX[10] + iVar2 * 4);
        } while (piVar3 != nullptr);
    }
    if (in_ECX[7] != 0) {
        do {
            piVar3 = reinterpret_cast<int*>(in_ECX[5]);
            iVar2 = *piVar3;
            in_ECX[5] = static_cast<uint32_t>(iVar2);
            if (iVar2 == 0) {
                in_ECX[6] = 0;
            } else {
                *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(iVar2) + 4) = 0;
            }
            {
                using Fn = void(*)(int*);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(in_ECX[4] + 8));
                fn(piVar3);
            }
            in_ECX[7] = in_ECX[7] + -1;
        } while (in_ECX[7] != 0);
    }
    FUN_0054bcd0();
}

// 0x5564d0 — observed shape
void FUN_005564d0(void* self_param) {
    unsigned char* base = static_cast<unsigned char*>(self_param);
    auto getI = [&](size_t off) -> int& { return *reinterpret_cast<int*>(base + off); };
    auto getU = [&](size_t off) -> uint32_t& { return *reinterpret_cast<uint32_t*>(base + off); };
    int iVar7 = getI(0x1c);
    getI(0x20) = iVar7;
    if (iVar7 != 0) {
        if (getI(0x24) < iVar7) {
            operator_delete__(*reinterpret_cast<void**>(base + 0x28));
            getI(0x24) = getI(0x20);
            uint32_t uVar6 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(static_cast<uint32_t>(getI(0x20) * 4)));
            getU(0x28) = uVar6;
            operator_delete__(*reinterpret_cast<void**>(base + 0x2c));
            uVar6 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(static_cast<uint32_t>(getI(0x24) << 2)));
            getU(0x2c) = uVar6;
        }
        int iVar5;
        iVar7 = getI(0xc);
        uint32_t* puVar8 = *reinterpret_cast<uint32_t**>(base + 0x14);
        float fVar2 = *reinterpret_cast<float*>(iVar7 + 0x104);
        float fVar3 = *reinterpret_cast<float*>(iVar7 + 0x108);
        float fVar4 = *reinterpret_cast<float*>(iVar7 + 0x10c);
        if (0 < getI(0x20)) {
            iVar7 = 0;
            do {
                uint32_t* puVar1 = puVar8 + 2;
                puVar8 = reinterpret_cast<uint32_t*>(*puVar8);
                *reinterpret_cast<uint32_t*>(getU(0x28) + iVar7 * 4) = *puVar1;
                iVar5 = static_cast<int>(*reinterpret_cast<uint32_t*>(getU(0x28) + iVar7 * 4));
                iVar7 = iVar7 + 1;
                *reinterpret_cast<float*>(getU(0x2c) + -4 + iVar7 * 4) =
                    fVar2 * *reinterpret_cast<float*>(iVar5 + 0x28) +
                    fVar4 * *reinterpret_cast<float*>(iVar5 + 0x30) + fVar3 * *reinterpret_cast<float*>(iVar5 + 0x2c);
            } while (iVar7 < getI(0x20));
        }
        FUN_00556330(0, getI(0x20) + -1);
    }
}

// 0x5565b0 — observed shape
void FUN_005565b0(void* self_param) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_param);
    FUN_0054bc90();
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c2a70);
    in_ECX[7] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[4] = reinterpret_cast<uint32_t>(&PTR_FUN_00711770);
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
}

// 0x5565e0 — observed shape
uint32_t* FUN_005565e0(uint32_t param_1) {
    uint32_t* puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x34));
    if (puVar1 == nullptr) {
        thunk_FUN_00538410(nullptr, param_1);
        return nullptr;
    }
    FUN_0054bc90();
    *puVar1 = reinterpret_cast<uint32_t>(&PTR_FUN_006c2a70);
    puVar1[7] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[4] = reinterpret_cast<uint32_t>(&PTR_FUN_00711770);
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    thunk_FUN_00538410(puVar1, param_1);
    return puVar1;
}

// 0x556650 — observed shape
void FUN_00556650(void* self_param, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_param);
    FUN_0055ab40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
    in_ECX[0x11] = param_9;
    in_ECX[0x12] = 0;
    *reinterpret_cast<uint16_t*>(in_ECX + 0x13) = 0;
    in_ECX[0x14] = 0;
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c2ad0);
    in_ECX[0x10] = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(in_ECX + 0xf)) * 3;
}

// 0x5566b0 — observed shape
void FUN_005566b0(void* self_param) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_param);
    FUN_0055ab90();
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    *reinterpret_cast<uint16_t*>(in_ECX + 0x13) = 0;
    in_ECX[0x14] = 0;
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c2ad0);
}

// 0x5566e0 — observed shape
void FUN_005566e0(void* self_param, uint16_t param_1, void* param_2) {
    unsigned char* base = static_cast<unsigned char*>(self_param);
    if (param_2 != *reinterpret_cast<void**>(base + 0x44)) {
        operator_delete__(*reinterpret_cast<void**>(base + 0x44));
    }
    *reinterpret_cast<uint16_t*>(base + 0x3c) = param_1;
    *reinterpret_cast<void**>(base + 0x44) = param_2;
    *reinterpret_cast<uint32_t*>(base + 0x40) = static_cast<uint32_t>(param_1) * 3;
}

// 0x5567d0 — observed shape
uint32_t FUN_005567d0(void* self_param, int param_1) {
    unsigned char* self = static_cast<unsigned char*>(self_param);
    unsigned char* other = reinterpret_cast<unsigned char*>(param_1);
    uint32_t uVar1 = FUN_0055abd0(param_1);
    if ((static_cast<char>(uVar1) == '\0') || (uVar1 = *reinterpret_cast<uint32_t*>(self + 0x40), uVar1 != *reinterpret_cast<uint32_t*>(param_1 + 0x40))) {
        return uVar1 & 0xffffff00;
    }
    int iVar2 = static_cast<int>(uVar1 * 2);
    bool bVar5 = true;
    char* pcVar3 = *reinterpret_cast<char**>(self + 0x44);
    char* pcVar4 = *reinterpret_cast<char**>(param_1 + 0x44);
    do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
    } while (bVar5);
    return static_cast<uint32_t>(bVar5);
}

// 0x556830 — observed shape
void FUN_00556830(void* self_param, uint8_t param_1) {
    FUN_005568a0();
    if ((param_1 & 1) != 0) {
        operator_delete(self_param);
    }
}

// 0x556850 — observed shape
void FUN_00556850(void* self_param) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_param);
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c2ad0);
    operator_delete__(reinterpret_cast<void*>(in_ECX[0x11]));
    void* pvVar1 = reinterpret_cast<void*>(in_ECX[0x14]);
    if (pvVar1 != nullptr) {
        FUN_005568a0();
        operator_delete(pvVar1);
    }
    operator_delete__(reinterpret_cast<void*>(in_ECX[0x12]));
    FUN_0055abb0();
}

// 0x5568a0 — observed shape
void FUN_005568a0(void* self_param) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_param);
    operator_delete__(reinterpret_cast<void*>(*in_ECX));
    void* pvVar1 = reinterpret_cast<void*>(in_ECX[4]);
    if (pvVar1 != nullptr) {
        FUN_005568a0(pvVar1);
        operator_delete(pvVar1);
    }
}

// 0x5568d0 — observed shape
void FUN_005568d0(void* self_param, uint8_t param_1) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_param);
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c2ad0);
    operator_delete__(reinterpret_cast<void*>(in_ECX[0x11]));
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(in_ECX[0x14]);
    if (puVar1 != nullptr) {
        operator_delete__(reinterpret_cast<void*>(*puVar1));
        if (puVar1[4] != 0) {
            FUN_00556830(puVar1, 1);
        }
        operator_delete(puVar1);
    }
    operator_delete__(reinterpret_cast<void*>(in_ECX[0x12]));
    FUN_0055abb0();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x556940 — observed shape
void FUN_00556940(void* self_param, uint32_t param_1) {
    unsigned char* base = static_cast<unsigned char*>(self_param);
    uint32_t uStack_18 = param_1;
    FUN_0055ac40();
    uStack_18 = 4;
    int* piVar1 = reinterpret_cast<int*>(base + 0x40);
    {
        using Fn = void(*)(int*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x15c) + 8));
        fn(piVar1);
    }
    if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0xa000111) {
        uStack_18 = 1;
    } else {
        char byteFlag = 0;
        using Fn = void(*)(void*, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x15c) + 8));
        fn(&byteFlag, 1);
        if (byteFlag == '\0') goto LAB_005569b0;
    }
    if (*piVar1 != 0) {
        uint32_t uVar3 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(static_cast<uint32_t>(*piVar1) * 2));
        *reinterpret_cast<uint32_t*>(base + 0x44) = uVar3;
        using Fn = void(*)(uint32_t, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x15c) + 8));
        fn(uVar3, *piVar1 << 1);
    }
LAB_005569b0:
    {
        using Fn = void(*)(void*, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x15c) + 8));
        fn(base + 0x4c, 2);
    }
    uint16_t uVar7 = *reinterpret_cast<uint16_t*>(base + 0x4c);
    if (uVar7 != 0) {
        int iVar4 = static_cast<int>(reinterpret_cast<uintptr_t>(thunk_FUN_00533c78(static_cast<uint32_t>(uVar7) * 8)));
        if (iVar4 == 0) {
            iVar4 = 0;
        } else {
            FUN_004127b0(iVar4, 8, static_cast<uint32_t>(uVar7), reinterpret_cast<void*>(&LAB_00556820));
        }
        *reinterpret_cast<int*>(base + 0x48) = iVar4;
        uint32_t* puVar5 = static_cast<uint32_t*>(FUN_00533c78(0x14));
        if (puVar5 == nullptr) {
            puVar5 = nullptr;
        } else {
            uint32_t uVar8 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(base + 0x4c));
            uint32_t uVar3 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(uVar8 * 2));
            *puVar5 = uVar3;
            puVar5[1] = uVar3;
            puVar5[2] = uVar8;
            puVar5[3] = uVar8;
            puVar5[4] = 0;
        }
        *reinterpret_cast<uint32_t**>(base + 0x50) = puVar5;
        uVar7 = 0;
        if (*reinterpret_cast<short*>(base + 0x4c) != 0) {
            do {
                iVar4 = 0;
                {
                    using Fn = void(*)(uint32_t*, int);
                    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x15c) + 8));
                    fn(&uStack_18, 2);
                }
                short sVar6 = 0;
                if (static_cast<uint16_t>(uStack_18) != 0) {
                    puVar5 = *reinterpret_cast<uint32_t**>(base + 0x50);
                    if (puVar5 != nullptr) {
                        do {
                            if ((uStack_18 & 0xffff) <= puVar5[3]) goto LAB_00556ada;
                            puVar5 = reinterpret_cast<uint32_t*>(puVar5[4]);
                        } while (puVar5 != nullptr);
                    }
                    puVar5 = static_cast<uint32_t*>(FUN_00533c78(0x14));
                    if (puVar5 == nullptr) {
                        puVar5 = nullptr;
                    } else {
                        iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(base + 0x50) + 8);
                        int iVar9 = iVar4 * 2;
                        uint32_t uVar3 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(static_cast<uint32_t>(iVar4 * 4)));
                        *puVar5 = uVar3;
                        puVar5[1] = uVar3;
                        puVar5[2] = static_cast<uint32_t>(iVar9);
                        puVar5[3] = static_cast<uint32_t>(iVar9);
                        puVar5[4] = 0;
                    }
                    puVar5[4] = *reinterpret_cast<uint32_t*>(base + 0x50);
                    *reinterpret_cast<uint32_t**>(base + 0x50) = puVar5;
LAB_00556ada:
                    iVar4 = static_cast<int>(puVar5[1]);
                    puVar5[3] = puVar5[3] - static_cast<uint32_t>(static_cast<uint16_t>(uStack_18));
                    puVar5[1] = static_cast<uint32_t>(iVar4) + (uStack_18 & 0xffff) * 2;
                    {
                        using Fn = void(*)(int, int);
                        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x15c) + 8));
                        fn(iVar4, static_cast<int>((uStack_18 & 0xffff) << 1));
                    }
                    sVar6 = static_cast<short>(static_cast<uint16_t>(uStack_18));
                }
                short* psVar2 = reinterpret_cast<short*>(*reinterpret_cast<int*>(base + 0x48) + static_cast<uint32_t>(uVar7) * 8);
                if (sVar6 == 0 || iVar4 == 0) {
                    *psVar2 = 0;
                    psVar2[2] = 0;
                    psVar2[3] = 0;
                } else {
                    *psVar2 = sVar6;
                    *reinterpret_cast<int*>(psVar2 + 2) = iVar4;
                }
                uVar7 = static_cast<uint16_t>(uVar7 + 1);
            } while (uVar7 < *reinterpret_cast<uint16_t*>(base + 0x4c));
        }
    }
}

// 0x556b50 — observed shape
void FUN_00556b50(void* self_param, int param_1) {
    unsigned char* base = static_cast<unsigned char*>(self_param);
    int iStack_18 = param_1;
    int iStack_4 = static_cast<int>(reinterpret_cast<uintptr_t>(base));
    FUN_0055ac70();
    iStack_18 = 4;
    int* piStack_1c = reinterpret_cast<int*>(base + 0x40);
    {
        using Fn = void(*)();
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x160) + 0xc));
        fn();
    }
    iStack_4 = (*reinterpret_cast<int*>(base + 0x44) != 0) ? 1 : (iStack_4 & ~0xff);
    {
        using Fn = void(*)(int*, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x160) + 0xc));
        fn(&iStack_4, 1);
    }
    if (static_cast<char>(iStack_4) != '\0') {
        using Fn = void(*)(uint32_t, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x160) + 0xc));
        fn(*reinterpret_cast<uint32_t*>(base + 0x44), *reinterpret_cast<int*>(base + 0x40) << 1);
    }
    {
        using Fn = void(*)(void*, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x160) + 0xc));
        fn(base + 0x4c, 2);
    }
    uint16_t uVar1 = 0;
    if (*reinterpret_cast<short*>(base + 0x4c) != 0) {
        do {
            int* entry = reinterpret_cast<int*>(static_cast<uint32_t>(static_cast<uint16_t>(static_cast<uint32_t>(uVar1) * 8 + *reinterpret_cast<int*>(base + 0x48))));
            {
                using Fn = void(*)(int**, int);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x160) + 0xc));
                fn(&entry, 2);
            }
            if (static_cast<short>(reinterpret_cast<uintptr_t>(entry)) != 0) {
                using Fn = void(*)(uint32_t, int);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t*>(*(uint32_t*)(param_1 + 0x160) + 0xc));
                fn(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(base + 0x48) + 4 + static_cast<uint32_t>(uVar1) * 8), static_cast<int>((static_cast<uint32_t>(reinterpret_cast<uintptr_t>(entry)) & 0xffff) << 1));
            }
            uVar1 = static_cast<uint16_t>(uVar1 + 1);
        } while (uVar1 < *reinterpret_cast<uint16_t*>(base + 0x4c));
    }
}

// 0x556c20 — observed shape
void FUN_00556c20(void* self_param, int param_1) {
    unsigned char* base = static_cast<unsigned char*>(self_param);
    int iVar2 = param_1;
    FUN_0055aca0(param_1);
    int param_1_local = FUN_00557b10(DAT_00727cc8);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &param_1_local);
    param_1_local = FUN_00557cb0("m_uiTriListLength", *reinterpret_cast<uint32_t*>(base + 0x40));
    uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &param_1_local);
    param_1_local = FUN_00557d40("m_pusTriList", *reinterpret_cast<uint32_t*>(base + 0x44));
    uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &param_1_local);
}

// 0x556ce0 — observed shape
void FUN_00556ce0(void* self_param) {
    unsigned char* base = static_cast<unsigned char*>(self_param);
    if (*reinterpret_cast<int*>(base + 0x48) != 0) {
        uint32_t uVar1 = 0;
        if (*reinterpret_cast<int*>(base + 0x44) != 0) {
            int iVar2 = 0;
            do {
                operator_delete(*reinterpret_cast<void**>(iVar2 + 0x44 + *reinterpret_cast<int*>(base + 0x48)));
                *reinterpret_cast<uint32_t*>(iVar2 + 0x44 + *reinterpret_cast<int*>(base + 0x48)) = 0;
                uVar1 = uVar1 + 1;
                iVar2 = iVar2 + 0x4c;
            } while (uVar1 < *reinterpret_cast<uint32_t*>(base + 0x44));
        }
    }
}

// 0x556d30 — observed shape
void FUN_00556d30(void* self_param) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_param);
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c2b54);
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[3]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
        in_ECX[3] = 0;
    }
    FUN_00556ce0(self_param);
    operator_delete__(reinterpret_cast<void*>(in_ECX[0x12]));
    puVar2 = reinterpret_cast<uint32_t*>(in_ECX[3]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
    }
    FUN_00538400();
}

// 0x556d90 — observed shape
void FUN_00556d90(void* self_param, int param_1) {
    unsigned char* base = static_cast<unsigned char*>(self_param);
    FUN_00513ce0(param_1);
    if (0x4000000 < *reinterpret_cast<uint32_t*>(param_1 + 0x1c)) {
        uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00545600());
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 0xc);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Fn = void(*)(int);
                    Fn fn = reinterpret_cast<Fn>(*puVar2);
                    fn(1);
                }
            }
            *reinterpret_cast<uint32_t**>(base + 0xc) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
}

// 0x556e10 — observed shape
uint32_t FUN_00556e10(void* self_param, int param_1) {
    unsigned char* base = static_cast<unsigned char*>(self_param);
    uint32_t uVar5 = FUN_00538460(param_1);
    if (((static_cast<char>(uVar5) == '\0') || (uVar5 = FUN_00557a60(param_1 + 0x10), static_cast<char>(uVar5) != '\0')) || (*reinterpret_cast<int*>(base + 0x44) != *reinterpret_cast<int*>(param_1 + 0x44)) || (*reinterpret_cast<int**>(base + 0xc) != nullptr && (uVar5 = reinterpret_cast<uint32_t>(reinterpret_cast<void*(*)()>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int**>(base + 0xc) + 0x1c))()), static_cast<char>(uVar5) == '\0'))) {
        return uVar5 & 0xffffff00;
    }
    uint32_t local_8 = 0;
    uVar5 = 0;
    if (*reinterpret_cast<int*>(base + 0x44) != 0) {
        int local_c = 0;
        do {
            int iVar10 = *reinterpret_cast<int*>(base + 0x48) + local_c;
            int iVar11 = *reinterpret_cast<int*>(param_1 + 0x48) + local_c;
            uVar5 = FUN_00557a60(iVar11);
            if (static_cast<char>(uVar5) != '\0' || (uVar5 = FUN_005480d0(iVar11 + 0x34), static_cast<char>(uVar5) == '\0')) {
LAB_00556f21:
                return uVar5 & 0xffffff00;
            }
            uint16_t uVar3 = *reinterpret_cast<uint16_t*>(iVar10 + 0x48);
            uVar5 = (static_cast<uint32_t>(static_cast<uint16_t>(uVar5 >> 0x10)) << 16) | uVar3;
            if (uVar3 != *reinterpret_cast<uint16_t*>(iVar11 + 0x48)) goto LAB_00556f21;
            uint32_t uVar9 = 0;
            if (uVar3 != 0) {
                iVar10 = *reinterpret_cast<int*>(iVar10 + 0x44);
                short* psVar7 = *reinterpret_cast<short**>(iVar11 + 0x44);
                float* pfVar8 = reinterpret_cast<float*>(iVar10 + 4);
                int delta = iVar10 - reinterpret_cast<int>(psVar7);
                do {
                    short sVar4 = *reinterpret_cast<short*>(delta + reinterpret_cast<int>(psVar7));
                    uint16_t hi = static_cast<uint16_t>(uVar5 >> 0x10);
                    uVar5 = (static_cast<uint32_t>(hi) << 16) | static_cast<uint16_t>(sVar4);
                    if (sVar4 != *psVar7) goto LAB_00556f21;
                    float fVar1 = *reinterpret_cast<float*>(psVar7 + 2);
                    float fVar2 = *pfVar8;
                    uint16_t cond = static_cast<uint16_t>((fVar2 < fVar1) ? 1 : 0) | static_cast<uint16_t>((NAN(fVar2) || NAN(fVar1)) ? 1 : 0) << 2 | static_cast<uint16_t>((fVar2 == fVar1) ? 1 : 0) << 6;
                    uVar5 = (static_cast<uint32_t>(hi) << 16) | cond;
                    if (fVar2 != fVar1) goto LAB_00556f21;
                    uVar9 = uVar9 + 1;
                    pfVar8 = pfVar8 + 2;
                    psVar7 = psVar7 + 4;
                } while (uVar9 < uVar3);
            }
            uVar5 = local_8 + 1;
            local_c = local_c + 0x4c;
            local_8 = uVar5;
        } while (uVar5 < *reinterpret_cast<uint32_t*>(base + 0x44));
    }
    return ((uVar5 & 0x00ffffff) << 8) | 1;
}

// 0x556f30 — observed shape
void FUN_00556f30(void* self_param, uint8_t param_1) {
    FUN_00556d30(self_param);
    if ((param_1 & 1) != 0) {
        operator_delete(self_param);
    }
}
