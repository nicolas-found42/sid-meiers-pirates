#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cctype>
#include <windows.h>

extern void* FUN_00533c78(std::size_t size);
extern void* thunk_FUN_00533c78(std::size_t size);
extern void FUN_005c9200(void);
extern void FUN_00545310(const char* text, std::uint32_t value);
extern void FUN_005383d0(void);
extern void FUN_00538400(void);
extern void FUN_005606f0(std::uint32_t index, void** slot);
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void* DAT_00728dec;
extern void* PTR_FUN_006c7734;
extern void* PTR_FUN_006c7860;
extern void* PTR_FUN_006c7880;
extern void* PTR_FUN_006c787c;

// 0x5c9200 — observed shape: alloc 0x14, re-vtable, alloc 0x94 cleared by [1] count, flag
void FUN_005c9200(void)
{
    std::uint32_t* puVar1 = static_cast<std::uint32_t*>(FUN_00533c78(0x14));
    if (puVar1 == nullptr) {
        DAT_00728dec = nullptr;
        return;
    }
    puVar1[0] = reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c7734);
    puVar1[1] = 0x25;
    puVar1[3] = 0;
    std::uint32_t* puVar2 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(0x94));
    puVar1[2] = reinterpret_cast<std::uintptr_t>(puVar2);
    for (std::uint32_t uVar3 = puVar1[1] & 0x3fffffff; uVar3 != 0; --uVar3) {
        *puVar2 = 0;
        ++puVar2;
    }
    for (int iVar4 = 0; iVar4 != 0; --iVar4) {
        *reinterpret_cast<std::uint8_t*>(puVar2) = 0;
        puVar2 = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(puVar2) + 1);
    }
    *reinterpret_cast<std::uint8_t*>(puVar1 + 4) = 1;
    puVar1[0] = reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c7860);
    DAT_00728dec = puVar1;
}

// 0x5c9280 — observed shape: null/dot rejection, lowercase copy up to 256, registry dispatch returns 1
std::uint32_t FUN_005c9280(char* param_1, std::uint32_t param_2)
{
    if (param_1 != nullptr) {
        char* pcVar2 = std::strchr(param_1, '.');
        if (pcVar2 == nullptr) {
            char local_100[256];
            std::uint32_t uVar4 = 0;
            std::int32_t iVar1 = -static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(param_1));
            do {
                int iVar3 = std::tolower(static_cast<unsigned char>(*param_1));
                param_1[static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(local_100) + iVar1 & 0xffffffffu) - static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(param_1))] = static_cast<char>(iVar3);
                // Preserve observed write target: local_100 offset derived from original param_1
                local_100[uVar4] = static_cast<char>(iVar3);
                if (*param_1 == '\0') break;
                uVar4 = uVar4 + 1;
                param_1 = param_1 + 1;
            } while (uVar4 < 0x100);
            if (DAT_00728dec == nullptr) {
                FUN_005c9200();
            }
            FUN_00545310(local_100, param_2);
            return 1;
        }
    }
    return 0;
}

// 0x5c9560 — observed shape: receiver in_ECX, bounds check at +0x24, index table at +0x1c
std::uint32_t FUN_005c9560(std::uint32_t param_1, void* self, std::uint32_t* param_2)
{
    *param_2 = 0;
    if (param_1 < *reinterpret_cast<std::uint32_t*>(static_cast<char*>(self) + 0x24)) {
        std::uint32_t* puVar1 = *reinterpret_cast<std::uint32_t**>(*reinterpret_cast<std::int32_t*>(static_cast<char*>(self) + 0x1c) + param_1 * 4);
        if (puVar1 != nullptr) {
            *param_2 = *puVar1;
            return puVar1[1];
        }
    }
    return 0;
}

// 0x5c9590 — observed shape: receiver in_ECX, base ctor chain, vtable reset, array pointer clear
void FUN_005c9590(void* self)
{
    std::uintptr_t* in_ECX = static_cast<std::uintptr_t*>(self);
    FUN_005383d0();
    in_ECX[0] = reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c7880);
    in_ECX[6] = reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c787c);
    in_ECX[8] = 0;
    in_ECX[0xb] = 1;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[7] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    if (in_ECX[9] != 0) {
        std::uint32_t uVar1 = 0;
        do {
            *reinterpret_cast<std::uint32_t*>(in_ECX[7] + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[9]);
    }
    in_ECX[9] = 0;
    in_ECX[10] = 0;
}

// 0x5c95f0 — observed shape: receiver in_ECX, per-element nested delete + slot reset, table delete
void FUN_005c95f0(void* self)
{
    std::uintptr_t* in_ECX = static_cast<std::uintptr_t*>(self);
    void* pvVar1;
    std::uintptr_t local_4 = reinterpret_cast<std::uintptr_t>(in_ECX);
    in_ECX[0] = reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c7880);
    local_4 = reinterpret_cast<std::uintptr_t>(in_ECX);
    if (in_ECX[5] != 0) {
        std::uint32_t uVar2 = 0;
        if (in_ECX[9] != 0) {
            if (in_ECX[9] != 0) {
                do {
                    pvVar1 = *reinterpret_cast<void**>(in_ECX[7] + uVar2 * 4);
                    if (pvVar1 != nullptr) {
                        operator_delete__(*reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(pvVar1) + 4));
                        operator_delete(pvVar1);
                        local_4 = 0;
                        FUN_005606f0(uVar2, reinterpret_cast<void**>(&local_4));
                    }
                    uVar2 = uVar2 + 1;
                } while (uVar2 < in_ECX[9]);
            }
        }
        operator_delete__(reinterpret_cast<void*>(in_ECX[5]));
    }
    in_ECX[6] = reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c787c);
    operator_delete__(reinterpret_cast<void*>(in_ECX[7]));
    FUN_00538400();
}

// 0x5c9680 — observed shape: alloc 0x30 + construct via 0x5c9590, element alloc 0x18*count, dtor fallback
std::uint32_t* FUN_005c9680(std::int32_t param_1)
{
    std::int32_t iVar1 = static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(FUN_00533c78(0x30)));
    if (iVar1 == 0) {
        return nullptr;
    }
    std::uint32_t* puVar2 = static_cast<std::uint32_t*>(FUN_005c9590());
    if (puVar2 != nullptr) {
        puVar2[4] = static_cast<std::uint32_t>(param_1);
        iVar1 = static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(thunk_FUN_00533c78(param_1 * 0x18)));
        if (iVar1 == 0) {
            iVar1 = 0;
        }
        else {
            FUN_004127b0(reinterpret_cast<void*>(iVar1), 0x18, param_1, &LAB_005c9510);
        }
        puVar2[5] = static_cast<std::uint32_t>(iVar1);
        if (iVar1 == 0) {
            reinterpret_cast<void (__cdecl *)(int)>(*reinterpret_cast<void**>(puVar2))(1);
            return nullptr;
        }
    }
    return puVar2;
}

// 0x5c96f0 — observed shape: receiver in_ECX, slot fetch/create, grow, dword+tail copy, commit
std::uint32_t FUN_005c96f0(std::uint32_t* param_1, std::uint32_t* param_2, std::uint32_t param_3, void* self)
{
    std::uint32_t uVar4 = param_3;
    std::uint32_t* puVar1 = param_1;
    std::uint32_t* puVar2 = nullptr;
    if (param_1 < *reinterpret_cast<std::uint32_t**>(static_cast<char*>(self) + 0x24)) {
        puVar2 = *reinterpret_cast<std::uint32_t**>(*reinterpret_cast<std::int32_t*>(static_cast<char*>(self) + 0x1c) + static_cast<std::int32_t>(param_1) * 4);
        param_1 = puVar2;
        if (puVar2 != nullptr) {
            if (*puVar2 != param_3) {
                operator_delete__(reinterpret_cast<void*>(puVar2[1]));
                puVar2[1] = 0;
            }
            goto LAB_005c9754;
        }
    }
    puVar2 = static_cast<std::uint32_t*>(FUN_00533c78(8));
    if (puVar2 == nullptr) {
        return 0;
    }
    *puVar2 = 0;
    puVar2[1] = 0;
    param_1 = puVar2;
LAB_005c9754:
    if (puVar2[1] == 0) {
        *puVar2 = uVar4;
        std::uint32_t uVar3 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(thunk_FUN_00533c78(uVar4)));
        puVar2[1] = uVar3;
    }
    std::uint32_t* puVar5 = param_2;
    std::uint32_t* puVar6 = reinterpret_cast<std::uint32_t*>(puVar2[1]);
    for (std::uint32_t uVar3 = uVar4 >> 2; uVar3 != 0; --uVar3) {
        *puVar6 = *puVar5;
        ++puVar5;
        ++puVar6;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; --uVar4) {
        *reinterpret_cast<std::uint8_t*>(puVar6) = *reinterpret_cast<std::uint8_t*>(puVar5);
        puVar5 = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(puVar5) + 1);
        puVar6 = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(puVar6) + 1);
    }
    if (*reinterpret_cast<std::uint32_t**>(static_cast<char*>(self) + 0x20) <= puVar1) {
        FUN_006b34a0(*reinterpret_cast<std::int32_t*>(static_cast<char*>(self) + 0x2c) + static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(puVar1)));
    }
    FUN_005606f0(reinterpret_cast<std::uint32_t>(puVar1), reinterpret_cast<void**>(&param_1));
    return 1;
}

// 0x5c97b0 — observed shape: receiver in_ECX, dtor chain if flag bit set
void FUN_005c97b0(std::uint8_t param_1, void* self)
{
    FUN_005c95f0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5c97d0 — observed shape: null-checked vcall at +0x60, fixed shutdown call sequence
std::uint32_t FUN_005c97d0(void)
{
    std::int32_t* piVar1 = static_cast<std::int32_t*>(FUN_005bd940());
    if (piVar1 != nullptr) {
        FUN_00547780();
        reinterpret_cast<void (__cdecl *)(int)>(*reinterpret_cast<void**>(*reinterpret_cast<std::uintptr_t>(piVar1) + 0x60))(0);
    }
    FUN_005bec30(0);
    FUN_005ca7f0(0);
    FUN_005d7d60(0);
    FUN_005c86f0();
    FUN_005c8710(0);
    FUN_005d7d10(0);
    FUN_005c9f20(0);
    return 0;
}

// 0x5c9820 — observed shape: receiver in_ECX, base ctor chain, fields zero, vtable set
void FUN_005c9820(void* self)
{
    std::uintptr_t* in_ECX = static_cast<std::uintptr_t*>(self);
    FUN_00547620();
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    *reinterpret_cast<std::uint8_t*>(in_ECX + 7) = 0;
    *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(in_ECX) + 0x1d) = 0;
    in_ECX[0] = reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c78d8);
}

extern void FUN_005bec30(std::uint32_t param_1);
extern void FUN_005ca7f0(std::uint32_t param_1);
extern void FUN_005d7d60(void* param_1);
extern void FUN_005c8710(std::uint32_t param_1);
extern void FUN_005d7d10(std::uint32_t param_1);
extern void FUN_005c9f20(std::uint32_t param_1);
extern void* FUN_005bd940(void);
extern void FUN_00497420(const char* text);
extern void* FUN_005c9110(void);
extern void* DAT_00728de4;
extern void FUN_00547650(void);
extern void* PTR_FUN_006c78d8;
extern "C" void _splitpath(const char* path, char* drive, char* dir, char* fname, char* ext);
extern "C" int sprintf(char* buffer, const char* format, ...);

// 0x5c9890 — observed shape: receiver in_ECX, param stored at +0x14, null path releases +0x10 and
// clears +0x18, non-null path rebinds +0x10 from param+0x60 with release/addref and copies +0x5cc to +0x18
void FUN_005c9890(std::uint32_t param_1, void* self)
{
    char* base = static_cast<char*>(self);
    *reinterpret_cast<std::uint32_t*>(base + 0x14) = param_1;
    if (param_1 == 0) {
        std::uintptr_t* piVar1 = *reinterpret_cast<std::uintptr_t**>(base + 0x10);
        *reinterpret_cast<std::uint32_t*>(base + 0x18) = 0;
        if (piVar1 != nullptr) {
            reinterpret_cast<void (__cdecl*)(std::uintptr_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(piVar1) + 8))(piVar1);
        }
        *reinterpret_cast<std::uintptr_t*>(base + 0x10) = 0;
        return;
    }
    std::uintptr_t* piVar1 = *reinterpret_cast<std::uintptr_t**>(param_1 + 0x60);
    std::uintptr_t* piVar2 = *reinterpret_cast<std::uintptr_t**>(base + 0x10);
    if (piVar2 != nullptr) {
        reinterpret_cast<void (__cdecl*)(std::uintptr_t*)>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(piVar2) + 8))(piVar2);
    }
    *reinterpret_cast<std::uintptr_t*>(base + 0x10) = reinterpret_cast<std::uintptr_t>(piVar1);
    if (piVar1 != nullptr) {
        reinterpret_cast<void (__cdecl*)(std::uintptr_t*)>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(piVar1) + 4))(piVar1);
    }
    *reinterpret_cast<std::uint32_t*>(base + 0x18) =
        *reinterpret_cast<std::uint32_t*>(
            *reinterpret_cast<std::uint32_t*>(base + 0x14) + 0x5cc);
}

// 0x5c98f0 — observed shape: field +0x5cc fetched first, fixed init/shutdown call chain, vcall +0x10c,
// optional global notify through vcall +0x60, lazy shader program factory with duplicate error text
std::uint32_t FUN_005c98f0(std::uint32_t param_1)
{
    std::uintptr_t* piVar1 = *reinterpret_cast<std::uintptr_t**>(param_1 + 0x5cc);
    FUN_005bec30(param_1);
    FUN_005ca7f0(param_1);
    FUN_005d7d60(piVar1);
    FUN_005c8710(param_1);
    FUN_005d7d10(param_1);
    FUN_005c9f20(param_1);
    reinterpret_cast<void (__cdecl*)(void)>(
        *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(piVar1) + 0x10c))();
    piVar1 = static_cast<std::uintptr_t*>(FUN_005bd940());
    if (piVar1 != nullptr) {
        reinterpret_cast<void (__cdecl*)(std::uint32_t)>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(piVar1) + 0x60))(param_1);
    }
    if (DAT_00728de4 == nullptr) {
        void* iVar2 = FUN_00533c78(0x10);
        if (iVar2 == nullptr) {
            DAT_00728de4 = nullptr;
            FUN_00497420("Failed to create shader program factory!");
            return 0;
        }
        DAT_00728de4 = FUN_005c9110();
        if (DAT_00728de4 == nullptr) {
            FUN_00497420("Failed to create shader program factory!");
        }
    }
    return 0;
}

// 0x5c99a0 — observed shape: receiver in_ECX, vtable reset to PTR_FUN_006c78d8, slots 5/6 cleared,
// slot 4 reference released and cleared, fixed base teardown call
void FUN_005c99a0(void* self)
{
    std::uintptr_t* in_ECX = static_cast<std::uintptr_t*>(self);
    std::uintptr_t* piVar1 = reinterpret_cast<std::uintptr_t*>(in_ECX[4]);
    in_ECX[0] = reinterpret_cast<std::uintptr_t>(&PTR_FUN_006c78d8);
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    if (piVar1 != nullptr) {
        reinterpret_cast<void (__cdecl*)(std::uintptr_t*)>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(piVar1) + 8))(piVar1);
    }
    in_ECX[4] = 0;
    FUN_00547650();
}

// 0x5c99e0 — observed shape: receiver in_ECX, forward to 0x5c9890 then set byte +0x1c
void FUN_005c99e0(std::uint32_t param_1, void* self)
{
    FUN_005c9890(param_1, self);
    *reinterpret_cast<std::uint8_t*>(static_cast<char*>(self) + 0x1c) = 1;
}

// 0x5c9ab0 — observed shape: probe of the filename buffer precedes the splitpath call in the listing,
// capacity guard, then filename formatted into the destination
std::uint32_t FUN_005c9ab0(char* param_1, char* param_2, char* param_3)
{
    char local_308[4];
    char local_304[256];
    char local_204[256];
    char local_104[260];

    char* pcVar2 = local_304;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    // Observed bound expression: net length of local_304 measured against param_3 as an address.
    if (param_3 < pcVar2 + (1 - static_cast<std::ptrdiff_t>(reinterpret_cast<std::uintptr_t>(local_304 + 1)))) {
        return 0;
    }
    _splitpath(param_1, local_308, local_104, local_304, local_204);
    sprintf(param_2, "%s", local_304);
    return 1;
}

// 0x5c9b30 — observed shape: splitpath with the extension in the last buffer, bounded copy of that field
std::uint32_t FUN_005c9b30(char* param_1, char* param_2, std::size_t param_3)
{
    char local_308[4];
    char local_304[256];
    char local_204[256];
    char local_104[260];

    _splitpath(param_1, local_308, local_104, local_204, local_304);
    std::strncpy(param_2, local_304, param_3);
    return 1;
}

// 0x5c9b90 — observed shape: null or empty input clears the slot, length comparison decides in-place
// copy versus release plus thunk_FUN_00533c78 allocation, then trailing byte copy
void FUN_005c9b90(std::uint32_t* param_1, char* param_2)
{
    if (param_2 == nullptr) {
LAB_005c9c1e:
        operator_delete__(reinterpret_cast<void*>(*param_1));
        *param_1 = 0;
        return;
    }
    // Single-byte comparison against the empty literal: empty input behaves like null.
    if (*param_2 == '\0') {
        goto LAB_005c9c1e;
    }
    char* pcVar4 = reinterpret_cast<char*>(*param_1);
    char cVar1;
    if (pcVar4 != nullptr) {
        char* pcVar2 = pcVar4;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        char* pcVar3 = param_2;
        do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (static_cast<std::uint32_t>(pcVar3 - (param_2 + 1)) <
            static_cast<std::uint32_t>(pcVar2 - (pcVar4 + 1))) {
            goto LAB_005c9c0a;
        }
        operator_delete__(pcVar4);
        *param_1 = 0;
    }
    pcVar4 = param_2;
    do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    *param_1 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
        thunk_FUN_00533c78(static_cast<std::size_t>(pcVar4 - (param_2 + 1)) + 1)));
LAB_005c9c0a:
    pcVar4 = reinterpret_cast<char*>(*param_1);
    do {
        cVar1 = *param_2;
        param_2 = param_2 + 1;
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
}

// 0x5c9c40 — observed shape: vtable+0xc read of a 4-byte size into the size argument slot, then an
// optional vtable+0xc read of the pre-read size into the destination (unaff_retaddr, recovered as param_2)
std::uint32_t FUN_005c9c40(std::uint32_t* param_1, std::uint32_t param_2, std::int32_t param_3)
{
    void* vtable = *reinterpret_cast<void**>(param_1);
    std::int32_t iVar1 = param_3;
    std::int32_t iVar2 = reinterpret_cast<std::int32_t (__cdecl*)(void*, std::int32_t)>(
        *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(vtable) + 0xc))(
        reinterpret_cast<void*>(&param_3), 4);
    if (iVar2 != 4) {
        return 0;
    }
    if (iVar1 == 0) {
        return 1;
    }
    iVar2 = reinterpret_cast<std::int32_t (__cdecl*)(void*, std::int32_t)>(
        *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(vtable) + 0xc))(
        reinterpret_cast<void*>(param_2), iVar1);
    if (iVar2 == iVar1) {
        return 1;
    }
    return 0;
}

// 0x5c9c80 — observed shape: vtable+8 read of a 4-byte size into the argument slot, null size yields a
// null destination slot, otherwise thunk_FUN_00533c78 allocation followed by a vtable+8 read of that size
std::uint32_t FUN_005c9c80(std::uint32_t* param_1, std::uint32_t* param_2)
{
    std::uint32_t* piVar1 = param_1;
    // The listing reads the size straight into the argument slot; a dedicated 4-byte slot models it.
    std::uint32_t sizeSlot = 0;
    std::uint32_t* puVar5 = &sizeSlot;
    std::int32_t iVar2 = reinterpret_cast<std::int32_t (__cdecl*)(void*, std::int32_t)>(
        *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(*piVar1) + 8))(
        reinterpret_cast<void*>(puVar5), 4);
    if (iVar2 != 4) {
        return 0;
    }
    // unaff_ESI: the size value just written into that slot by the read.
    std::uint32_t unaff_ESI = sizeSlot;
    if (unaff_ESI == 0) {
        *param_2 = 0;
    }
    else {
        std::uintptr_t uVar3 = reinterpret_cast<std::uintptr_t>(
            thunk_FUN_00533c78(unaff_ESI));
        *param_2 = static_cast<std::uint32_t>(uVar3);
        std::uint32_t* puVar4 = reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<std::uintptr_t (__cdecl*)(void*, std::int32_t)>(
                *reinterpret_cast<void**>(reinterpret_cast<std::uintptr_t>(*piVar1) + 8))(
                reinterpret_cast<void*>(uVar3), static_cast<std::int32_t>(unaff_ESI)));
        if (reinterpret_cast<void*>(puVar4) != reinterpret_cast<void*>(puVar5)) {
            return 0;
        }
    }
    return 1;
}

// 0x5c9cd0 — observed shape: receiver in_ECX, capacity at +0x10 with buffer at +0x14, grow releases the
// buffer, lazy thunk_FUN_00533c78 allocation, dword plus tail-byte copy from a non-null source
void FUN_005c9cd0(std::uint32_t param_1, void* param_2, void* self)
{
    char* base = static_cast<char*>(self);
    if (*reinterpret_cast<std::uint32_t*>(base + 0x10) < param_1) {
        operator_delete__(*reinterpret_cast<void**>(base + 0x14));
        *reinterpret_cast<std::uint32_t*>(base + 0x14) = 0;
        *reinterpret_cast<std::uint32_t*>(base + 0x10) = param_1;
    }
    if (*reinterpret_cast<std::uint32_t*>(base + 0x14) == 0) {
        *reinterpret_cast<std::uintptr_t*>(base + 0x14) = reinterpret_cast<std::uintptr_t>(
            thunk_FUN_00533c78(*reinterpret_cast<std::uint32_t*>(base + 0x10)));
    }
    if (param_2 != nullptr) {
        std::uint32_t* puVar3 = *reinterpret_cast<std::uint32_t**>(base + 0x14);
        std::uint32_t* source = static_cast<std::uint32_t*>(param_2);
        std::uint32_t uVar2;
        for (uVar2 = param_1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar3 = *source;
            source = source + 1;
            puVar3 = puVar3 + 1;
        }
        for (uVar2 = param_1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *reinterpret_cast<std::uint8_t*>(puVar3) = *reinterpret_cast<std::uint8_t*>(source);
            source = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(source) + 1);
            puVar3 = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(puVar3) + 1);
        }
    }
}
