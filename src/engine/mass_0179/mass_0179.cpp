#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>

extern void operator_delete(void* p) noexcept;
extern "C" char FUN_005e19a0(std::uint32_t, std::uint32_t**);
extern std::uint32_t* FUN_0053ba20(void* self, std::uint32_t index);
extern void FUN_005383d0();
extern void FUN_006b34a0(std::uint32_t);
extern void FUN_0057a3f0(std::uint32_t);
extern char* thunk_FUN_00533c78(std::size_t);
extern std::uint32_t DAT_007179b0;
extern std::uint32_t DAT_00727430;
extern std::uint32_t DAT_00727434;
extern std::uint32_t DAT_00727438;
extern void FUN_00538400();
extern void FUN_0057a5b0(void* self);
extern std::uint32_t PTR_FUN_006c4890;
extern std::uint32_t PTR_FUN_006c4894;
extern std::uint32_t PTR_FUN_007115f4;
extern std::uint32_t PTR_FUN_0070d028;
extern std::uint32_t PTR_FUN_006c4868;
extern std::uint32_t PTR_LAB_006c4840;

// 0x57a550 — observed shape
std::uint32_t* FUN_0057a550(std::uint32_t param_1) {
    std::uint32_t* local_4 = nullptr;
    char cVar3 = FUN_005e19a0(param_1, &local_4);
    std::uint32_t* puVar2 = local_4;
    if (cVar3 == '\0') {
        if (local_4 != nullptr) {
            std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(local_4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Fn = void(__cdecl*)(int);
                Fn vfn = reinterpret_cast<Fn>(*local_4);
                vfn(1);
            }
        }
        return nullptr;
    }
    if (local_4 != nullptr) {
        std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(local_4 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn vfn = reinterpret_cast<Fn>(*local_4);
            vfn(1);
        }
    }
    return puVar2;
}

// 0x57a5b0 — observed shape
void FUN_0057a5b0(void* self) {
    auto* dv = reinterpret_cast<std::uint32_t*>(self);
    dv[0] = PTR_FUN_006c4890;
    std::int32_t iVar2 = reinterpret_cast<std::int32_t*>(dv)[1];
    if (iVar2 != 0) {
        std::int32_t iVar4 = *reinterpret_cast<std::int32_t*>(iVar2 + -4);
        std::int32_t iVar5 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 + -1) {
            do {
                std::uint32_t* puVar3 = *reinterpret_cast<std::uint32_t**>(iVar5 + -4);
                iVar5 = iVar5 + -4;
                if (puVar3 != nullptr) {
                    std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(puVar3 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        using Fn = void(__cdecl*)(int);
                        Fn vfn = reinterpret_cast<Fn>(*puVar3);
                        vfn(1);
                    }
                }
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
        }
        operator_delete(reinterpret_cast<void*>(iVar2 + -4));
    }
}

// 0x57a600 — observed shape
void FUN_0057a600(void* self, std::uint8_t param_1) {
    FUN_0057a5b0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x57a620 — observed shape
void FUN_0057a620(void* self, char* param_1, std::uint32_t param_2, std::uint32_t param_3) {
    auto* in_ECX = reinterpret_cast<std::uint32_t*>(self);
    FUN_005383d0();
    in_ECX[0] = PTR_FUN_006c4894;
    in_ECX[6] = PTR_FUN_007115f4;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[7] = 0;
    in_ECX[0xb] = 1;
    in_ECX[0x11] = 1;
    in_ECX[0xc] = PTR_FUN_006c4890;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0x17] = 1;
    in_ECX[0x12] = PTR_FUN_0070d028;
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0;
    in_ECX[0x16] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x1b] = 0;
    in_ECX[0x19] = 0;
    in_ECX[0x1a] = 0;
    in_ECX[0x18] = PTR_FUN_006c4868;
    in_ECX[0x1c] = 0;
    if (param_1 == nullptr) {
        in_ECX[3] = 0;
    } else {
        char* pcVar3 = param_1;
        char cVar2;
        do {
            cVar2 = *pcVar3;
            pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        pcVar3 = thunk_FUN_00533c78(static_cast<std::size_t>(pcVar3 + (1 - static_cast<std::int32_t>(reinterpret_cast<std::intptr_t>(param_1 + 1))))));
        in_ECX[3] = reinterpret_cast<std::uint32_t>(pcVar3);
        do {
            cVar2 = *param_1;
            param_1 = param_1 + 1;
            *pcVar3 = cVar2;
            pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
    }
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    FUN_006b34a0(param_2);
    in_ECX[0xb] = param_3;
    FUN_0057a3f0(param_2);
    in_ECX[0x11] = param_3;
    FUN_006b34a0(param_2);
    in_ECX[0x17] = param_3;
    in_ECX[0x1e] = 0;
    in_ECX[0x22] = 0;
    in_ECX[0x1f] = 0;
    in_ECX[0x21] = 0;
    std::uint32_t* puVar5 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(in_ECX[0x1c]));
    if (puVar5 != nullptr) {
        std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(puVar5 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn vfn = reinterpret_cast<Fn>(*puVar5);
            vfn(1);
        }
        in_ECX[0x1c] = 0;
    }
    in_ECX[0x1d] = 0;
    *(reinterpret_cast<std::uint8_t*>(in_ECX) + 0x8c) = 0;
    *(reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uintptr_t>(self) + 0x8d)) = 0;
    *(reinterpret_cast<std::uint8_t*>(in_ECX + 0x25)) = 0;
    *(reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uintptr_t>(self) + 0x95)) = 0;
    in_ECX[0x24] = 0xff7fffff;
    auto* src = reinterpret_cast<std::uint32_t*>(&DAT_007179b0);
    std::uint32_t* puVar6 = in_ECX + 0x26;
    for (int iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *src;
        src = src + 1;
        puVar6 = puVar6 + 1;
    }
    in_ECX[0x2f] = DAT_00727430;
    in_ECX[0x30] = DAT_00727434;
    in_ECX[0x31] = DAT_00727438;
}

// 0x57a7b0 — observed shape
void FUN_0057a7b0(void* self) {
    auto* in_ECX = reinterpret_cast<std::uint32_t*>(self);
    in_ECX[0] = PTR_FUN_006c4894;
    std::uint32_t* local_4 = in_ECX;
    operator_delete(reinterpret_cast<void*>(static_cast<std::uintptr_t>(in_ECX[3])));
    operator_delete(reinterpret_cast<void*>(static_cast<std::uintptr_t>(in_ECX[4])));
    if (in_ECX[0xf] != 0) {
        std::uint32_t uVar7 = 0;
        do {
            std::int32_t* piVar5 = reinterpret_cast<std::int32_t*>(FUN_0053ba20(&local_4, uVar7));
            std::uint32_t* puVar2 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(*piVar5));
            if (puVar2 != nullptr) {
                std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Fn = void(__cdecl*)(int);
                    Fn vfn = reinterpret_cast<Fn>(*puVar2);
                    vfn(1);
                }
                *piVar5 = 0;
            }
            if ((local_4 != nullptr) && (local_4[1] = local_4[1] + -1, local_4[1] == 0)) {
                using Fn = void(__cdecl*)(int);
                Fn vfn = reinterpret_cast<Fn>(*local_4);
                vfn(1);
            }
            void* pvVar6 = nullptr;
            if (uVar7 < in_ECX[9]) {
                pvVar6 = *reinterpret_cast<void**>(static_cast<std::uintptr_t>(in_ECX[7]) + uVar7 * 4);
                *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(in_ECX[7]) + uVar7 * 4) = 0;
                if (pvVar6 != nullptr) {
                    in_ECX[10] = in_ECX[10] + -1;
                }
                if (uVar7 == in_ECX[9] - 1) {
                    in_ECX[9] = in_ECX[9] - 1;
                }
            }
            operator_delete(pvVar6);
            uVar7 = uVar7 + 1;
        } while (uVar7 < in_ECX[0xf]);
    }
    std::uint32_t* puVar2 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(in_ECX[0x1c]));
    if (puVar2 != nullptr) {
        std::int32_t* piVar5 = reinterpret_cast<std::int32_t*>(puVar2 + 1);
        *piVar5 = *piVar5 + -1;
        if (*piVar5 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn vfn = reinterpret_cast<Fn>(*puVar2);
            vfn(1);
        }
    }
    std::uint32_t* piVar5 = in_ECX + 0x18;
    *piVar5 = PTR_FUN_006c4868;
    std::uint32_t* node = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(in_ECX[0x19]));
    while (node != nullptr) {
        std::uint32_t* next = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(*node));
        using Fn = void(__cdecl*)(std::uint32_t*);
        Fn vfn = reinterpret_cast<Fn>(*piVar5 + 8);
        vfn(node);
        node = next;
    }
    in_ECX[0x1b] = 0;
    in_ECX[0x19] = 0;
    in_ECX[0x1a] = 0;
    *piVar5 = PTR_LAB_006c4840;
    in_ECX[0x12] = PTR_FUN_0070d028;
    operator_delete(reinterpret_cast<void*>(static_cast<std::uintptr_t>(in_ECX[0x13])));
    FUN_0057a5b0(self);
    in_ECX[6] = PTR_FUN_007115f4;
    operator_delete(reinterpret_cast<void*>(static_cast<std::uintptr_t>(in_ECX[7])));
    FUN_00538400();
}

extern char* FUN_00533c78(std::size_t);
extern void FUN_005606f0(std::uint32_t index, void* value);
extern void FUN_00581300(std::uint32_t index, void* value);
extern void FUN_0053c9e0(void* dst, std::uint32_t src);
extern void FUN_0057eb00(void* a, void* b);
extern void FUN_0057e9b0(void* a, void* b);
extern void FUN_005796f0();
extern void FUN_00579b80(float value);
extern long double FUN_00579740(std::int32_t self, float value);
extern void FUN_00579bd0(float a, float b, float c);
extern void FUN_005edba0();
extern void FUN_00545310(std::uint32_t value, std::int32_t flag);
extern void FUN_005e1490();
extern std::int32_t FUN_005e1570(std::int32_t object);
extern void operator_delete__(void* p) noexcept;
extern std::int32_t (*DAT_00000004)(std::int32_t);
extern void FUN_00579960(std::uint32_t param_1, std::uint32_t index);
extern void FUN_00538410(void* self, std::uint32_t param_2);
extern void FUN_00579100(std::int32_t object);
extern std::int32_t FUN_00449390(void* table, std::uint32_t id);
extern void FUN_00540a10(std::uint32_t index);
extern void FUN_00540a30();
extern char FUN_00568540(std::uint32_t param_1);
extern std::uint32_t FUN_005829f0(void* a, void* b);
extern long double FUN_0056a5f0(std::int32_t a, std::uint32_t b, std::uint32_t c,
                                std::uint32_t d, void* e);
extern void FUN_0053c7c0(float value);
extern void* FUN_0053c8d0(void* a, void* b);
extern void FUN_005531c0(std::int32_t param_1);
extern std::uint32_t FUN_00557b10(std::uint32_t param_1);
extern void FUN_005bbe20(std::int32_t param_1);
extern void FUN_00546930();
extern char FUN_00545060(std::uint32_t param_1);
extern void FUN_00546ad0();
extern void FUN_0057ee90(void* a, std::uint32_t b);
extern void FUN_00579fa0();
extern void FUN_00579e80(float value);
extern void FUN_005791d0(float value);
extern void FUN_0051ac30(std::int32_t value);
extern std::uint32_t DAT_007275d4;
extern char DAT_007179d4;
extern std::uint32_t DAT_007289d8;
extern std::uint32_t DAT_007289d0;
extern std::uint32_t DAT_00727890;
extern std::uint32_t DAT_00728a3c;
extern std::uint32_t DAT_007289f0;
extern std::uint32_t DAT_007289e8;
extern std::uint32_t DAT_007283cc;
extern std::uint32_t PTR_FUN_006c4874;

// 0x57a8f0 — observed shape
std::uint32_t FUN_0057a8f0(void* self, char* param_1, std::uint32_t* param_2) {
    auto* base = static_cast<std::uint8_t*>(self);
    char* const original = param_1;
    std::uint32_t index = *reinterpret_cast<std::uint32_t*>(base + 0x24);
    char* scan = param_1;
    char cVar2;
    do {
        cVar2 = *scan;
        scan = scan + 1;
    } while (cVar2 != '\0');
    char* text = thunk_FUN_00533c78(static_cast<std::size_t>(scan - original + 1));
    char* src = original;
    char* dst = text;
    do {
        cVar2 = *src;
        src = src + 1;
        *dst = cVar2;
        dst = dst + 1;
    } while (cVar2 != '\0');
    if (*reinterpret_cast<std::uint32_t*>(base + 0x20) <= index) {
        FUN_006b34a0(static_cast<std::int32_t>(*reinterpret_cast<std::int32_t*>(base + 0x2c)) +
                     static_cast<std::int32_t>(index));
    }
    char* nameSlot = text;
    FUN_005606f0(index, &nameSlot);
    std::uint32_t* puVar4 = param_2;
    char* objectSlot = reinterpret_cast<char*>(param_2);
    if (param_2 != nullptr) {
        param_2[1] = param_2[1] + 1;
    }
    if (*reinterpret_cast<std::uint32_t*>(base + 0x38) <= index) {
        FUN_0057a3f0(static_cast<std::int32_t>(*reinterpret_cast<std::int32_t*>(base + 0x44)) +
                     static_cast<std::int32_t>(index));
    }
    FUN_00581300(index, &objectSlot);
    if (puVar4 != nullptr) {
        std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(puVar4 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn vfn = reinterpret_cast<Fn>(*puVar4);
            vfn(1);
        }
    }
    return index;
}

// 0x57a9a0 — observed shape
std::uint32_t FUN_0057a9a0(void* self, char param_1) {
    auto* base = static_cast<std::uint8_t*>(self);
    std::uint32_t local_30;
    std::uint32_t local_2c;
    std::uint32_t local_28;
    std::uint32_t local_24[9];
    if (*reinterpret_cast<std::int32_t*>(base + 0x7c) == 0) {
        return 0;
    }
    if ((*reinterpret_cast<std::uint8_t*>(base + 0x8c) != 0) && (param_1 == '\0')) {
        std::int32_t iVar1 = *reinterpret_cast<std::int32_t*>(
            *reinterpret_cast<std::int32_t*>(base + 0x78) + 0x34);
        auto* owner = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar1));
        local_30 = *reinterpret_cast<std::uint32_t*>(owner + 0x5c);
        local_2c = *reinterpret_cast<std::uint32_t*>(owner + 0x60);
        local_28 = *reinterpret_cast<std::uint32_t*>(owner + 100);
        FUN_0053c9e0(local_24, *reinterpret_cast<std::uint32_t*>(owner + 0x68));
        FUN_0057eb00(local_24, &local_30);
    }
    std::int32_t elem = *reinterpret_cast<std::int32_t*>(
        *reinterpret_cast<std::int32_t*>(base + 0x34) +
        *reinterpret_cast<std::int32_t*>(base + 0x74) * 4);
    auto* item = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(elem));
    if (*reinterpret_cast<float*>(item + 0x24) != -3.4028235e+38f) {
        *reinterpret_cast<float*>(base + 0x88) =
            (*reinterpret_cast<float*>(item + 0x28) / *reinterpret_cast<float*>(item + 0x10) +
             *reinterpret_cast<float*>(base + 0x88)) -
            *reinterpret_cast<float*>(item + 0x24);
    }
    FUN_005796f0();
    return 1;
}

// 0x57aa50 — observed shape
void FUN_0057aa50(void* self, float param_1) {
    auto* base = static_cast<std::uint8_t*>(self);
    FUN_00579b80(param_1 + *reinterpret_cast<float*>(base + 0x88));
}

// 0x57aa70 — observed shape
void FUN_0057aa70(void* self, float param_1) {
    auto* base = static_cast<std::uint8_t*>(self);
    float fVar1 = *reinterpret_cast<float*>(base + 0x80);
    std::int32_t iVar2 = *reinterpret_cast<std::int32_t*>(base + 0x84);
    auto* blendSrc = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar2));
    float fVar3 = *reinterpret_cast<float*>(blendSrc + 0x80);
    if (param_1 < fVar1) {
        FUN_00579b80(param_1 + *reinterpret_cast<float*>(base + 0x88));
        std::int32_t iVar8 = *reinterpret_cast<std::int32_t*>(
            *reinterpret_cast<std::int32_t*>(base + 0x78) + 0x34);
        auto* owner = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar8));
        std::uint32_t uVar4 = *reinterpret_cast<std::uint32_t*>(owner + 0x5c);
        std::uint32_t uVar5 = *reinterpret_cast<std::uint32_t*>(owner + 0x60);
        std::uint32_t uVar6 = *reinterpret_cast<std::uint32_t*>(owner + 100);
        std::uint32_t local_24[9];
        FUN_0053c9e0(local_24, *reinterpret_cast<std::uint32_t*>(owner + 0x68));
        *reinterpret_cast<std::uint32_t*>(blendSrc + 0xec) = uVar4;
        std::uint32_t* puVar9 = local_24;
        std::uint32_t* puVar10 = reinterpret_cast<std::uint32_t*>(blendSrc + 200);
        for (std::int32_t n = 9; n != 0; n = n + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
        }
        *reinterpret_cast<std::uint32_t*>(blendSrc + 0xf0) = uVar5;
        *reinterpret_cast<std::uint32_t*>(blendSrc + 0xf4) = uVar6;
        return;
    }
    float fVar7 = param_1 + *reinterpret_cast<float*>(blendSrc + 0x88);
    if (fVar3 < param_1) {
        FUN_00579b80(fVar7);
        return;
    }
    long double fVar11 = FUN_00579740(iVar2, fVar7);
    std::int32_t elem = *reinterpret_cast<std::int32_t*>(
        *reinterpret_cast<std::int32_t*>(base + 0x34) +
        *reinterpret_cast<std::int32_t*>(base + 0x74) * 4);
    auto* item = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(elem));
    FUN_00579bd0(static_cast<float>(
                     (fVar11 - static_cast<long double>(*reinterpret_cast<float*>(item + 0x14))) /
                     static_cast<long double>(*reinterpret_cast<float*>(item + 0x10))),
                 fVar7, (param_1 - fVar1) / (fVar3 - fVar1));
}

// 0x57ab90 — observed shape
void FUN_0057ab90(void* self, float param_1, std::uint32_t param_2) {
    auto* base = static_cast<std::uint8_t*>(self);
    auto* blend = reinterpret_cast<std::uint8_t*>(
        static_cast<std::uintptr_t>(*reinterpret_cast<std::int32_t*>(base + 0x84)));
    FUN_00579bd0(param_1 + *reinterpret_cast<float*>(base + 0x88),
                 param_1 + *reinterpret_cast<float*>(blend + 0x88), static_cast<float>(param_2));
}

// 0x57abd0 — observed shape
void FUN_0057abd0(void* self, std::uint32_t param_1, std::int32_t param_2,
                  std::uint32_t param_3) {
    auto* base = static_cast<std::uint8_t*>(self);
    auto* other = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(param_2));
    std::uint32_t* puVar3;
    std::uint32_t* puVar4;
    std::uint32_t* puVar5;
    char cVar2;
    std::int32_t iVar6;
    std::int32_t iVar7;
    std::uint32_t uVar9;
    std::int32_t local_3c;
    std::uint32_t local_34;
    std::uint32_t local_30;
    std::int32_t* local_2c;
    std::int32_t local_24;
    std::int32_t local_1c;
    std::int32_t local_c;

    auto fillNode = [](std::uint32_t* node, std::int32_t target) {
        auto* t = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(target));
        node[2] = static_cast<std::uint32_t>(target);
        node[0xc] = *reinterpret_cast<std::uint32_t*>(t + 0x5c);
        node[0xd] = *reinterpret_cast<std::uint32_t*>(t + 0x60);
        node[0xe] = *reinterpret_cast<std::uint32_t*>(t + 100);
        auto* srcWords = reinterpret_cast<std::uint32_t*>(t + 0x38);
        std::uint32_t* dstWords = node + 3;
        for (std::int32_t n = 9; n != 0; n = n + -1) {
            *dstWords = *srcWords;
            srcWords = srcWords + 1;
            dstWords = dstWords + 1;
        }
        node[0xf] = *reinterpret_cast<std::uint32_t*>(t + 0x68);
    };
    auto appendNode = [](std::uint8_t* owner) -> std::uint32_t* {
        auto* allocObj = *reinterpret_cast<std::uint32_t**>(owner + 0x60);
        using AllocFn = void*(__cdecl*)(void*);
        AllocFn alloc = reinterpret_cast<AllocFn>(
            *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(allocObj) + 4));
        std::uint32_t* node = reinterpret_cast<std::uint32_t*>(alloc(allocObj));
        *node = 0;
        node[1] = *reinterpret_cast<std::uint32_t*>(owner + 0x68);
        auto* tail = reinterpret_cast<std::uint32_t*>(
            static_cast<std::uintptr_t>(*reinterpret_cast<std::uint32_t*>(owner + 0x68)));
        if (tail == nullptr) {
            *reinterpret_cast<std::uint32_t*>(owner + 100) =
                static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(node));
        } else {
            *tail = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(node));
        }
        *reinterpret_cast<std::uint32_t*>(owner + 0x68) =
            static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(node));
        *reinterpret_cast<std::int32_t*>(owner + 0x6c) =
            *reinterpret_cast<std::int32_t*>(owner + 0x6c) + 1;
        return node;
    };

    FUN_005edba0();
    FUN_005edba0();
    local_c = 0x25;
    puVar3 = reinterpret_cast<std::uint32_t*>(thunk_FUN_00533c78(0x94));
    puVar5 = puVar3;
    for (; local_c != 0; local_c = local_c + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
    }
    local_1c = 0x25;
    puVar4 = reinterpret_cast<std::uint32_t*>(thunk_FUN_00533c78(0x94));
    puVar5 = puVar4;
    for (; local_1c != 0; local_1c = local_1c + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
    }
    uVar9 = 0;
    if (*reinterpret_cast<std::int32_t*>(base + 0x3c) != 0) {
        do {
            std::int32_t elem = *reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(base + 0x34) + uVar9 * 4);
            FUN_00545310(*reinterpret_cast<std::uint32_t*>(
                             reinterpret_cast<std::uintptr_t>(elem) + 0x34), 1);
            uVar9 = uVar9 + 1;
        } while (uVar9 < *reinterpret_cast<std::uint32_t*>(base + 0x3c));
    }
    uVar9 = 0;
    if (*reinterpret_cast<std::int32_t*>(other + 0x3c) != 0) {
        do {
            std::int32_t elem = *reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(other + 0x34) + uVar9 * 4);
            FUN_00545310(*reinterpret_cast<std::uint32_t*>(
                             reinterpret_cast<std::uintptr_t>(elem) + 0x34), 1);
            uVar9 = uVar9 + 1;
        } while (uVar9 < *reinterpret_cast<std::uint32_t*>(other + 0x3c));
    }
    local_30 = 0;
    local_34 = 0;
    do {
        if ((*reinterpret_cast<std::uint32_t*>(base + 0x3c) <= local_30) &&
            (*reinterpret_cast<std::uint32_t*>(other + 0x3c) <= local_34)) {
            FUN_005e1490();
            FUN_005e1490();
            operator_delete__(puVar4);
            FUN_005e1490();
            FUN_005e1490();
            operator_delete__(puVar3);
            return;
        }
        iVar7 = 0;
        local_2c = nullptr;
        local_24 = 0;
        local_3c = 0;
        if (local_30 < *reinterpret_cast<std::uint32_t*>(base + 0x3c)) {
            local_24 = *reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(base + 0x34) + local_30 * 4);
            iVar7 = *reinterpret_cast<std::int32_t*>(
                reinterpret_cast<std::uintptr_t>(local_24) + 0x34);
        }
        if (local_34 < *reinterpret_cast<std::uint32_t*>(other + 0x3c)) {
            local_2c = *reinterpret_cast<std::int32_t**>(
                *reinterpret_cast<std::int32_t*>(other + 0x34) + local_34 * 4);
            local_3c = local_2c[0xd];
        }
        if (local_24 == 0) {
            if (local_2c != nullptr) {
                puVar5 = appendNode(base);
                fillNode(puVar5, local_3c);
            }
        } else if (local_2c == nullptr) {
            puVar5 = appendNode(other);
            fillNode(puVar5, iVar7);
        }
        if (((iVar7 != 0) && (local_3c != 0)) && (iVar7 != local_3c)) {
            iVar6 = FUN_005e1570(iVar7);
            local_2c = *reinterpret_cast<std::int32_t**>(
                static_cast<std::uintptr_t>(iVar6 * 4 + 0x25));
            if (local_2c != nullptr) {
LAB_0057ae84:
                {
                    using CmpFn = char(__cdecl*)(std::int32_t, std::int32_t);
                    CmpFn cmp = *reinterpret_cast<CmpFn*>(
                        static_cast<std::uintptr_t>(local_24) + 8);
                    cVar2 = cmp(iVar7, local_2c[1]);
                }
                if (cVar2 == '\0') break;
                puVar5 = appendNode(base);
                fillNode(puVar5, local_3c);
                goto LAB_0057b02e;
            }
LAB_0057ae24:
            iVar6 = DAT_00000004(local_3c);
            puVar5 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(
                (&PTR_FUN_006c4874)[iVar6]));
            while (puVar5 != nullptr) {
                using Cmp2Fn = char(__cdecl*)(std::int32_t, std::uint32_t);
                Cmp2Fn cmp = reinterpret_cast<Cmp2Fn>(puVar4[2]);
                cVar2 = cmp(local_3c, puVar5[1]);
                if (cVar2 != '\0') break;
                puVar5 = reinterpret_cast<std::uint32_t*>(
                    static_cast<std::uintptr_t>(*puVar5));
            }
            puVar5 = appendNode(other);
            fillNode(puVar5, iVar7);
            local_2c = nullptr;
        }
        if (local_24 != 0) {
            if ((*reinterpret_cast<std::uint8_t*>(base + 0x8c) != 0) &&
                (local_30 == *reinterpret_cast<std::uint32_t*>(base + 0x74))) {
                FUN_0057eb00(base + 200, base + 0xec);
            }
            FUN_00579960(param_1, local_30);
            puVar5 = appendNode(base);
            fillNode(puVar5, iVar7);
            if ((*reinterpret_cast<std::uint8_t*>(base + 0x8c) != 0) &&
                (local_30 == *reinterpret_cast<std::uint32_t*>(base + 0x74))) {
                FUN_0057e9b0(base + 200, base + 0xec);
            }
            local_30 = local_30 + 1;
        }
LAB_0057b02e:
        if (local_2c != nullptr) {
            if ((*reinterpret_cast<std::uint8_t*>(other + 0x8c) != 0) &&
                (local_34 == *reinterpret_cast<std::uint32_t*>(other + 0x74))) {
                FUN_0057eb00(other + 200, other + 0xec);
            }
            FUN_00579960(param_3, local_34);
            puVar5 = appendNode(other);
            fillNode(puVar5, local_3c);
            if ((*reinterpret_cast<std::uint8_t*>(other + 0x8c) != 0) &&
                (local_34 == *reinterpret_cast<std::uint32_t*>(other + 0x74))) {
                FUN_0057e9b0(other + 200, other + 0xec);
            }
            local_34 = local_34 + 1;
        }
    } while (true);
    local_2c = reinterpret_cast<std::int32_t*>(
        static_cast<std::uintptr_t>(*local_2c));
    if (local_2c == nullptr) goto LAB_0057ae24;
    goto LAB_0057ae84;
}

// 0x57b180 — observed shape
void FUN_0057b180(void* self, std::uint8_t* param_1, std::uint32_t param_2) {
    auto* base = static_cast<std::uint8_t*>(self);
    char cVar2;
    FUN_00538410(param_1, param_2);
    std::int32_t iVar6 = static_cast<std::int32_t>(DAT_007275d4);
    char* pcVar7 = *reinterpret_cast<char**>(base + 0xc);
    char* pcVar11 = pcVar7 + 1;
    char* pcVar9;
    if (DAT_007275d4 == 2) {
        do {
            cVar2 = *pcVar7;
            pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        std::int32_t iVar8 = static_cast<std::int32_t>(pcVar7 - pcVar11);
        pcVar9 = thunk_FUN_00533c78(static_cast<std::size_t>(iVar8 + 2));
        pcVar11 = *reinterpret_cast<char**>(base + 0xc);
        char* pcVar7b = pcVar9;
        do {
            cVar2 = *pcVar11;
            pcVar11 = pcVar11 + 1;
            *pcVar7b = cVar2;
            pcVar7b = pcVar7b + 1;
        } while (cVar2 != '\0');
        pcVar9[iVar8] = DAT_007179d4;
        pcVar9[iVar8 + 1] = '\0';
    } else {
        do {
            cVar2 = *pcVar7;
            pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        pcVar9 = thunk_FUN_00533c78(static_cast<std::size_t>(pcVar7 + (1 - pcVar11)));
        pcVar11 = *reinterpret_cast<char**>(base + 0xc);
        char* pcVar7b = pcVar9;
        do {
            cVar2 = *pcVar11;
            pcVar11 = pcVar11 + 1;
            *pcVar7b = cVar2;
            pcVar7b = pcVar7b + 1;
        } while (cVar2 != '\0');
    }
    *reinterpret_cast<char**>(param_1 + 0xc) = pcVar9;
    if (*reinterpret_cast<std::int32_t*>(base + 0x10) != 0) {
        FUN_00579100(*reinterpret_cast<std::int32_t*>(base + 0x10));
    }
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x14) =
        *reinterpret_cast<std::uint32_t*>(base + 0x14);
    std::uint32_t* puVar3 = *reinterpret_cast<std::uint32_t**>(param_1 + 0x70);
    std::uint32_t* puVar3new = *reinterpret_cast<std::uint32_t**>(base + 0x70);
    if (puVar3 != puVar3new) {
        if (puVar3 != nullptr) {
            std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Fn = void(__cdecl*)(int);
                Fn vfn = reinterpret_cast<Fn>(*puVar3);
                vfn(1);
            }
        }
        *reinterpret_cast<std::uint32_t**>(param_1 + 0x70) = puVar3new;
        if (puVar3new != nullptr) {
            puVar3new[1] = puVar3new[1] + 1;
        }
    }
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x74) =
        *reinterpret_cast<std::uint32_t*>(base + 0x74);
    DAT_007275d4 = 1;
    std::uint32_t uVar4 = *reinterpret_cast<std::uint32_t*>(base + 0x3c);
    std::uint32_t uVar12 = 0;
    if (uVar4 == 0) {
        DAT_007275d4 = static_cast<std::uint32_t>(iVar6);
        return;
    }
    do {
        std::uint32_t uVar5 = *reinterpret_cast<std::uint32_t*>(
            *reinterpret_cast<std::int32_t*>(base + 0x1c) + uVar12 * 4);
        std::int32_t* obj = *reinterpret_cast<std::int32_t**>(
            *reinterpret_cast<std::int32_t*>(base + 0x34) + uVar12 * 4);
        using Fn = std::uint32_t(__cdecl*)(void*, std::uint32_t);
        Fn vfn = *reinterpret_cast<Fn*>(static_cast<std::uintptr_t>(*obj) + 8);
        std::uint32_t uVar10 = vfn(obj, param_2);
        FUN_0057a8f0(reinterpret_cast<void*>(param_1),
                     reinterpret_cast<char*>(static_cast<std::uintptr_t>(uVar5)),
                     reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(uVar10)));
        uVar12 = uVar12 + 1;
    } while (uVar12 < uVar4);
    DAT_007275d4 = static_cast<std::uint32_t>(iVar6);
}

// 0x57b440 — observed shape
void FUN_0057b440(void* self, std::uint8_t param_1) {
    FUN_0057a7b0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x57b460 — observed shape
std::int32_t FUN_0057b460(std::int32_t param_1, std::uint32_t param_2, std::int32_t param_3) {
    auto* base = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(param_1));
    std::uint32_t* puVar2;
    std::uint32_t* puVar7;
    std::int32_t* piVar3;
    std::int32_t* piVar10;
    std::uint32_t uVar8;
    std::uint32_t uVar9;
    bool bVar4;
    if ((0x4010002 < *reinterpret_cast<std::uint32_t*>(base + 0x1c)) ||
        (*reinterpret_cast<std::uint32_t*>(base + 0x150) <= param_2)) {
        return 0;
    }
    std::int32_t iVar5 = FUN_00449390(
        &DAT_007289d8,
        *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::int32_t*>(base + 0x148) +
                                          param_2 * 4));
    if (iVar5 == 0) {
        return 0;
    }
    auto* model = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar5));
    if (param_3 == 0) {
        param_3 = *reinterpret_cast<std::int32_t*>(model + 0xc);
    }
    char* block = FUN_00533c78(0xf8);
    if (block == nullptr) {
        param_1 = 0;
    } else {
        FUN_0057a620(reinterpret_cast<void*>(block),
                     reinterpret_cast<char*>(static_cast<std::uintptr_t>(param_3)), 0xc, 0xc);
        param_1 = static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(block));
    }
    auto* out = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(param_1));
    *reinterpret_cast<std::uint32_t*>(out + 0x74) = 0;
    uVar9 = 0;
    if (*reinterpret_cast<std::int32_t*>(model + 0x18) != 0) {
        do {
            puVar7 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(FUN_00449390(
                &DAT_007289d0,
                *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::int32_t*>(model + 0x14) +
                                                  uVar9 * 4))));
            if (puVar7 != nullptr) {
                puVar2 = *reinterpret_cast<std::uint32_t**>(out + 0x70);
                if (puVar2 != puVar7) {
                    if (puVar2 != nullptr) {
                        piVar10 = reinterpret_cast<std::int32_t*>(puVar2 + 1);
                        *piVar10 = *piVar10 + -1;
                        if (*piVar10 == 0) {
                            using Fn = void(__cdecl*)(int);
                            Fn vfn = reinterpret_cast<Fn>(*puVar2);
                            vfn(1);
                        }
                    }
                    *reinterpret_cast<std::uint32_t**>(out + 0x70) = puVar7;
                    puVar7[1] = puVar7[1] + 1;
                }
                FUN_00540a10(uVar9);
                break;
            }
            uVar9 = uVar9 + 1;
        } while (uVar9 < *reinterpret_cast<std::uint32_t*>(model + 0x18));
    }
    piVar10 = *reinterpret_cast<std::int32_t**>(model + 0x10);
    if (piVar10 != nullptr) {
        piVar10[1] = piVar10[1] + 1;
    }
    std::uint32_t local_4 = 0;
    if (*reinterpret_cast<std::int32_t*>(model + 0x18) != 0) {
        do {
            piVar3 = *reinterpret_cast<std::int32_t**>(
                *reinterpret_cast<std::int32_t*>(model + 0x14) + local_4 * 4);
            if (piVar3 == nullptr) {
                uVar9 = 0;
            } else {
                bVar4 = false;
                {
                    using Fn = void*(__cdecl*)(void*);
                    Fn vfn = *reinterpret_cast<Fn*>(static_cast<std::uintptr_t>(*piVar3) + 4);
                    for (std::uint32_t* puVar7b = reinterpret_cast<std::uint32_t*>(vfn(piVar3));
                         puVar7b != nullptr;
                         puVar7b = reinterpret_cast<std::uint32_t*>(
                             static_cast<std::uintptr_t>(puVar7b[1]))) {
                        if (puVar7b == &DAT_00727890) {
                            bVar4 = true;
                            break;
                        }
                    }
                }
                uVar9 = (0u - static_cast<std::uint32_t>(bVar4)) &
                        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(piVar3));
            }
            if (piVar10 == nullptr) {
                uVar8 = 0;
            } else {
                bVar4 = false;
                {
                    using Fn = void*(__cdecl*)(void*);
                    Fn vfn = *reinterpret_cast<Fn*>(static_cast<std::uintptr_t>(*piVar10) + 4);
                    for (std::uint32_t* puVar7b = reinterpret_cast<std::uint32_t*>(vfn(piVar10));
                         puVar7b != nullptr;
                         puVar7b = reinterpret_cast<std::uint32_t*>(
                             static_cast<std::uintptr_t>(puVar7b[1]))) {
                        if (puVar7b == &DAT_00728a3c) {
                            bVar4 = true;
                            break;
                        }
                    }
                }
                uVar8 = (0u - static_cast<std::uint32_t>(bVar4)) &
                        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(piVar10));
            }
            FUN_0057a8f0(out,
                         *reinterpret_cast<char**>(static_cast<std::uintptr_t>(uVar9) + 0x10),
                         reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(uVar8)));
            std::int32_t* piVar3b = reinterpret_cast<std::int32_t*>(
                static_cast<std::uintptr_t>(piVar10[0xe]));
            if (piVar3b != nullptr) {
                piVar3b[1] = piVar3b[1] + 1;
            }
            std::uint32_t* puVar7b = reinterpret_cast<std::uint32_t*>(
                static_cast<std::uintptr_t>(piVar10[0xe]));
            if (puVar7b != nullptr) {
                std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(puVar7b + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Fn = void(__cdecl*)(int);
                    Fn vfn = reinterpret_cast<Fn>(*puVar7b);
                    vfn(1);
                }
                piVar10[0xe] = 0;
            }
            if (piVar10 == piVar3b) {
                if (piVar3b != nullptr) {
                    std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(piVar3b + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        using Fn = void(__cdecl*)(int);
                        Fn vfn = reinterpret_cast<Fn>(*piVar3b);
                        vfn(1);
                    }
                }
            } else {
                std::int32_t* piVar1 = reinterpret_cast<std::int32_t*>(piVar10 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Fn = void(__cdecl*)(int);
                    Fn vfn = reinterpret_cast<Fn>(*piVar10);
                    vfn(1);
                }
                piVar10 = piVar3b;
                if (piVar3b != nullptr) {
                    piVar3b[1] = piVar3b[1] + 1;
                    std::int32_t* piVar1b = reinterpret_cast<std::int32_t*>(piVar3b + 1);
                    *piVar1b = *piVar1b + -1;
                    if (*piVar1b == 0) {
                        using Fn = void(__cdecl*)(int);
                        Fn vfn = reinterpret_cast<Fn>(*piVar3b);
                        vfn(1);
                    }
                }
            }
            local_4 = local_4 + 1;
        } while (local_4 < *reinterpret_cast<std::uint32_t*>(model + 0x18));
    }
    FUN_00540a30();
    if (piVar10 != nullptr) {
        piVar3 = reinterpret_cast<std::int32_t*>(piVar10 + 1);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn vfn = reinterpret_cast<Fn>(*piVar10);
            vfn(1);
        }
    }
    return param_1;
}

// 0x57b660 — observed shape
std::int32_t FUN_0057b660(std::int32_t param_1) {
    auto* src = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(param_1));
    std::uint32_t uVar6 = 0;
    char* block = FUN_00533c78(0xf8);
    std::int32_t out;
    if (block == nullptr) {
        out = 0;
    } else {
        FUN_0057a620(
            reinterpret_cast<void*>(block),
            reinterpret_cast<char*>(
                static_cast<std::uintptr_t>(*reinterpret_cast<std::uint32_t*>(src + 0xc))),
            *reinterpret_cast<std::uint32_t*>(src + 0x38),
            *reinterpret_cast<std::uint32_t*>(src + 0x38));
        out = static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(block));
    }
    auto* dst = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(out));
    std::uint32_t uVar4 = *reinterpret_cast<std::uint32_t*>(src + 0x38);
    if (uVar4 != 0) {
        do {
            std::int32_t iVar3 = 0;
            std::int32_t* piVar7 = nullptr;
            if (uVar6 < *reinterpret_cast<std::uint32_t*>(src + 0x20)) {
                iVar3 = *reinterpret_cast<std::int32_t*>(
                    *reinterpret_cast<std::int32_t*>(src + 0x18) + uVar6 * 4);
            }
            if (uVar6 < uVar4) {
                piVar7 = *reinterpret_cast<std::int32_t**>(
                    *reinterpret_cast<std::int32_t*>(src + 0x30) + uVar6 * 4);
            }
            if ((iVar3 != 0) && (piVar7 != nullptr)) {
                using Fn = void*(__cdecl*)(void*);
                Fn vfn = *reinterpret_cast<Fn*>(static_cast<std::uintptr_t>(*piVar7) + 4);
                for (std::uint32_t* puVar5 = reinterpret_cast<std::uint32_t*>(vfn(piVar7));
                     puVar5 != nullptr;
                     puVar5 = reinterpret_cast<std::uint32_t*>(
                         static_cast<std::uintptr_t>(puVar5[1]))) {
                    if (puVar5 == &DAT_00728a3c) {
                        FUN_0057a8f0(
                            reinterpret_cast<void*>(static_cast<std::uintptr_t>(out)),
                            reinterpret_cast<char*>(static_cast<std::uintptr_t>(iVar3)),
                            reinterpret_cast<std::uint32_t*>(piVar7));
                        break;
                    }
                }
            }
            uVar4 = *reinterpret_cast<std::uint32_t*>(src + 0x38);
            uVar6 = uVar6 + 1;
        } while (uVar6 < uVar4);
    }
    std::uint32_t* puVar5 = *reinterpret_cast<std::uint32_t**>(src + 0x10);
    std::uint32_t* puVar1 = *reinterpret_cast<std::uint32_t**>(dst + 0x70);
    if (puVar1 != puVar5) {
        if (puVar1 != nullptr) {
            std::int32_t* piVar7b = reinterpret_cast<std::int32_t*>(puVar1 + 1);
            *piVar7b = *piVar7b + -1;
            if (*piVar7b == 0) {
                using Fn = void(__cdecl*)(int);
                Fn vfn = reinterpret_cast<Fn>(*puVar1);
                vfn(1);
            }
        }
        *reinterpret_cast<std::uint32_t**>(dst + 0x70) = puVar5;
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    return out;
}

// 0x57b730 — observed shape
void FUN_0057b730(void* self, float param_1) {
    auto* base = static_cast<std::uint8_t*>(self);
    std::int32_t iVar5 = *reinterpret_cast<std::int32_t*>(base + 0x84);
    std::uint32_t uVar6 = 0;
    float local_38 = param_1;
    if (iVar5 != 0) {
        local_38 = *reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(iVar5) + 0x80);
    }
    float fVar1 = *reinterpret_cast<float*>(base + 0x80);
    if (param_1 < local_38) {
        FUN_00579b80(param_1 + *reinterpret_cast<float*>(
                                    reinterpret_cast<std::uintptr_t>(iVar5) + 0x88));
        std::int32_t iVar8 = *reinterpret_cast<std::int32_t*>(
            *reinterpret_cast<std::int32_t*>(base + 0x78) + 0x34);
        auto* owner = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar8));
        std::uint32_t uVar2 = *reinterpret_cast<std::uint32_t*>(owner + 0x5c);
        std::uint32_t uVar3 = *reinterpret_cast<std::uint32_t*>(owner + 0x60);
        std::uint32_t uVar4 = *reinterpret_cast<std::uint32_t*>(owner + 100);
        std::uint32_t local_24[9];
        FUN_0053c9e0(local_24, *reinterpret_cast<std::uint32_t*>(owner + 0x68));
        *reinterpret_cast<std::uint32_t*>(base + 0xec) = uVar2;
        std::uint32_t* puVar7 = local_24;
        std::uint32_t* puVar8 = reinterpret_cast<std::uint32_t*>(base + 200);
        for (std::int32_t n = 9; n != 0; n = n + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
        }
        *reinterpret_cast<std::uint32_t*>(base + 0xf0) = uVar3;
        *reinterpret_cast<std::uint32_t*>(base + 0xf4) = uVar4;
        return;
    }
    if (fVar1 < param_1) {
        if (*reinterpret_cast<std::int32_t*>(base + 0x7c) == 2) {
            std::uint32_t* pTemp = FUN_0057a550(
                static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>("TempBlendSource")));
            *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(pTemp) + 0x7c) = 0;
            *reinterpret_cast<std::uint32_t*>(base + 0x7c) = 1;
        } else if (*reinterpret_cast<std::int32_t*>(base + 0x7c) == 3) {
            std::uint32_t* pTemp = FUN_0057a550(
                static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>("TempBlendSource")));
            *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(pTemp) + 0x7c) = 0;
            FUN_0057a9a0(self, 1);
            *reinterpret_cast<std::uint32_t*>(base + 0x7c) = 0;
            return;
        }
        FUN_00579b80(param_1 + *reinterpret_cast<float*>(base + 0x88));
        return;
    }
    if (*reinterpret_cast<std::uint8_t*>(base + 0x94) == 0) goto LAB_0057b95c;
    if (iVar5 == 0) {
        std::int32_t local_34;
        char* block = FUN_00533c78(0xf8);
        if (block == nullptr) {
            local_34 = 0;
        } else {
            FUN_0057a620(reinterpret_cast<void*>(block),
                         reinterpret_cast<char*>(
                             static_cast<std::uintptr_t>("TempBlendSource")), 0xc, 0xc);
            local_34 = static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(block));
        }
        if (*reinterpret_cast<std::int32_t*>(base + 0x3c) != 0) {
            do {
                std::int32_t iVar8 = *reinterpret_cast<std::int32_t*>(base + 0x34);
                if (*reinterpret_cast<std::uint32_t*>(
                        static_cast<std::uintptr_t>(local_34) + 0x38) <= uVar6) {
                    FUN_0057a3f0(*reinterpret_cast<std::int32_t*>(
                                     static_cast<std::uintptr_t>(local_34) + 0x44) +
                                 static_cast<std::int32_t>(uVar6));
                }
                FUN_00581300(uVar6, reinterpret_cast<void*>(
                                        static_cast<std::uintptr_t>(iVar8) + uVar6 * 4));
                uVar6 = uVar6 + 1;
            } while (uVar6 < *reinterpret_cast<std::uint32_t*>(base + 0x3c));
        }
        *reinterpret_cast<float*>(static_cast<std::uintptr_t>(local_34) + 0x80) = param_1;
        *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(local_34) + 0x7c) = 4;
        FUN_0057ee90(reinterpret_cast<void*>(static_cast<std::uintptr_t>(local_34)), 0);
        *reinterpret_cast<std::int32_t*>(base + 0x84) = local_34;
        FUN_00579fa0();
        float fVar9 = (*reinterpret_cast<std::int32_t*>(base + 0x7c) == 3)
                          ? fVar1
                          : fVar1 + *reinterpret_cast<float*>(base + 0x88);
        FUN_00579e80(fVar9);
    } else {
        auto* blend = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar5));
        float fVar9 = local_38 + *reinterpret_cast<float*>(blend + 0x88);
        if (*reinterpret_cast<std::uint8_t*>(base + 0x95) == 0) {
            FUN_00579e80(fVar9);
            fVar9 = fVar1 + *reinterpret_cast<float*>(base + 0x88);
            FUN_00579e80(fVar9);
        } else {
            FUN_0057abd0(self, fVar1 + *reinterpret_cast<float*>(base + 0x88), iVar5, fVar9);
            *reinterpret_cast<std::uint8_t*>(base + 0x95) = 0;
        }
    }
    *reinterpret_cast<std::uint8_t*>(base + 0x94) = 0;
LAB_0057b95c:
    FUN_005791d0((param_1 - local_38) / (fVar1 - local_38));
}

// 0x57b9e0 — observed shape
std::uint32_t* FUN_0057b9e0(std::uint32_t* param_1, void* param_2, std::uint32_t param_3,
                            std::int32_t param_4) {
    auto* model = static_cast<std::uint8_t*>(param_2);
    std::uint32_t* local_4 = nullptr;
    std::uint32_t* puVar1 = nullptr;
    if (*reinterpret_cast<std::uint32_t*>(model + 0x1c) < 0x4010003) {
        local_4 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(
            FUN_0057b460(static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(param_2)),
                         param_3, param_4)));
        if (local_4 == nullptr) goto LAB_0057bacd;
        local_4[1] = local_4[1] + 1;
    } else {
        if (*reinterpret_cast<std::uint32_t*>(model + 0x150) <= param_3) {
            *param_1 = 0;
            return param_1;
        }
        puVar1 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(FUN_00449390(
            &DAT_007289e8,
            *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::int32_t*>(model + 0x148) +
                                              param_3 * 4))));
        if (puVar1 != nullptr) {
            puVar1[1] = puVar1[1] + 1;
            goto LAB_0057ba62;
        }
        std::int32_t iVar2 = FUN_00449390(
            &DAT_007283cc,
            *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::int32_t*>(model + 0x148) +
                                              param_3 * 4));
        if (iVar2 == 0) goto LAB_0057bacd;
        std::int32_t uVar3 = FUN_0057b660(iVar2);
        FUN_0051ac30(uVar3);
    }
    puVar1 = local_4;
    if (local_4 != nullptr) {
LAB_0057ba62:
        if (param_4 != 0) {
            FUN_005bbe20(param_4);
        }
        *param_1 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
        if (puVar1 == nullptr) {
            return param_1;
        }
        std::int32_t iVar2 = static_cast<std::int32_t>(puVar1[1]);
        puVar1[1] = static_cast<std::uint32_t>(iVar2 + 1);
        puVar1[1] = static_cast<std::uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn vfn = reinterpret_cast<Fn>(*puVar1);
            vfn(1);
            return param_1;
        }
        return param_1;
    }
LAB_0057bacd:
    *param_1 = 0;
    return param_1;
}

// 0x57baf0 — observed shape
std::uint32_t* FUN_0057baf0(std::uint32_t* param_1, std::uint32_t param_2, std::uint32_t param_3,
                            std::uint32_t param_4) {
    std::uint8_t local_1b0[432];
    FUN_00546930();
    char cVar1 = FUN_00545060(param_2);
    if (cVar1 == '\0') {
        *param_1 = 0;
        FUN_00546ad0();
        return param_1;
    }
    FUN_0057b9e0(param_1, local_1b0, param_3, static_cast<std::int32_t>(param_4));
    FUN_00546ad0();
    return param_1;
}

// 0x57bb90 — observed shape
void FUN_0057bb90(void* self, std::uint32_t param_1) {
    auto* base = static_cast<std::uint8_t*>(self);
    std::uint32_t local_74;
    std::uint32_t local_70;
    std::uint32_t local_6c[9];
    std::uint32_t local_48[9];
    std::uint32_t local_24[9];
    if (*reinterpret_cast<std::int32_t*>(base + 0x34) == 0) {
        return;
    }
    char cVar1 = FUN_00568540(param_1);
    if (cVar1 != '\0') {
        return;
    }
    std::uint32_t uVar2 = FUN_005829f0(&local_74, &local_70);
    long double fVar6 = FUN_0056a5f0(*reinterpret_cast<std::int32_t*>(base + 0x2c), uVar2,
                                     local_70, local_74, base + 0x44);
    auto* target = reinterpret_cast<std::uint8_t*>(
        static_cast<std::uintptr_t>(*reinterpret_cast<std::int32_t*>(base + 0x34)));
    std::uint32_t* puVar3 = reinterpret_cast<std::uint32_t*>(target + 0x38);
    std::uint32_t* puVar5 = local_6c;
    for (std::int32_t iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
    }
    FUN_0053c7c0(static_cast<float>(-fVar6));
    puVar3 = reinterpret_cast<std::uint32_t*>(FUN_0053c8d0(local_24, local_48));
    puVar5 = local_6c;
    for (std::int32_t iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
    }
    puVar3 = local_6c;
    puVar5 = reinterpret_cast<std::uint32_t*>(target + 0x38);
    for (std::int32_t iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
    }
}

// 0x57bce0 — observed shape
void FUN_0057bce0(std::int32_t param_1) {
    auto* base = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(param_1));
    FUN_005531c0(param_1);
    std::uint32_t local = FUN_00557b10(DAT_007289f0);
    std::uint32_t uVar1 = *reinterpret_cast<std::uint32_t*>(base + 0xc);
    if (*reinterpret_cast<std::uint32_t*>(base + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<std::int32_t*>(base + 0x14) +
                     static_cast<std::int32_t>(uVar1));
    }
    FUN_005606f0(uVar1, &local);
}
