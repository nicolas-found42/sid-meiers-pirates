#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern void operator_delete__(void* ptr);
extern void FUN_005de540(void* self);
extern void FUN_005c9050(void* self);
extern void FUN_005de0e0(void* self);
extern void FUN_005de090(void* self);
extern void FUN_005e0120();
extern bool FUN_005de180(void* self);
extern bool FUN_005de1b0(void* self);
extern bool FUN_005de150(void* self);
extern bool FUN_005de120(void* self);
extern void* thunk_FUN_00533c78(std::size_t size);

extern void* PTR_FUN_006c8ed8;
extern void* PTR_FUN_006c8f30;
extern void* PTR_FUN_006c8f88;
extern void* PTR_FUN_006c9e8c;
extern void* PTR_LAB_006fd148;
extern char DAT_00729098;
extern int DAT_00729060[];
extern int DAT_00727444;

// 0x5de5a0 — observed shape
void FUN_005de5a0(void* self, unsigned char param_1)
{
    FUN_005de540(self);
    if ((param_1 & 1) != 0) {
        ::operator delete(self);
    }
}

// 0x5de5c0 — observed shape
void FUN_005de5c0(void* self)
{
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c) != 0) {
        void* obj = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x1c);
        void* vtable = *reinterpret_cast<void**>(obj);
        auto fn = *reinterpret_cast<void(**)(void*)>(static_cast<char*>(vtable) + 0x120);
        fn(obj);
    }
}

// 0x5de5f0 — observed shape
void FUN_005de5f0(void* self)
{
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c8ed8;
    FUN_005c9050(self);
    if (reinterpret_cast<uint32_t*>(self)[0xb] != 0) {
        void* obj = reinterpret_cast<void*>(reinterpret_cast<uint32_t*>(self)[7]);
        void* vtable = *reinterpret_cast<void**>(obj);
        auto fn = *reinterpret_cast<void(**)(void*)>(static_cast<char*>(vtable) + 0x120);
        fn(obj);
    }
    FUN_005de540(self);
}

// 0x5de8d0 — observed shape
void FUN_005de8d0(void* self)
{
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c8f30;
    operator_delete__(reinterpret_cast<void**>(self)[10]);
    operator_delete__(reinterpret_cast<void**>(self)[0xb]);
    int* piVar1 = static_cast<int*>(reinterpret_cast<void**>(self)[0xc]);
    if (piVar1 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar1);
        auto fn = *reinterpret_cast<void(**)(int*)>(static_cast<char*>(vtable) + 8);
        fn(piVar1);
        reinterpret_cast<void**>(self)[0xc] = nullptr;
    }
    FUN_005de0e0(self);
}

// 0x5de910 — observed shape
void FUN_005de910(void* self)
{
    int* piVar1 = *reinterpret_cast<int**>(static_cast<char*>(self) + 0x30);
    if (piVar1 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar1);
        auto fn = *reinterpret_cast<void(**)(int*)>(static_cast<char*>(vtable) + 8);
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x30) = 0;
    }
    FUN_005de090(self);
}
// 0x5de940 — observed shape
bool FUN_005de940(void* self)
{
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return DAT_00729060[uVar1 & 0xff] == 4;
}

// 0x5de970 — observed shape
bool FUN_005de970(void* self)
{
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return DAT_00729060[uVar1 & 0xff] == 5;
}

// 0x5de9a0 — observed shape
bool FUN_005de9a0(void* self)
{
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return DAT_00729060[uVar1 & 0xff] == 6;
}

// 0x5de9d0 — observed shape
bool FUN_005de9d0(void* self)
{
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return DAT_00729060[uVar1 & 0xff] == 7;
}

// 0x5dea00 — observed shape
bool FUN_005dea00(void* self)
{
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return DAT_00729060[uVar1 & 0xff] == 10;
}
// 0x5dea30 — observed shape
bool FUN_005dea30(void* self, int param_1, uint32_t* param_2)
{
    if ((*reinterpret_cast<int*>(static_cast<char*>(self) + 0x30) == 0) ||
        (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) == 0)) {
        return false;
    }
    if (param_2 == nullptr) {
        param_2 = *reinterpret_cast<uint32_t**>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x2c);
    }
    int iVar2 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x20);
    if (iVar2 == 0) {
        iVar2 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 8);
    }
    void* container = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x30);
    void* cVtable = *reinterpret_cast<void**>(container);
    auto fn24 = *reinterpret_cast<int(**)(void*, int, int)>(static_cast<char*>(cVtable) + 0x24);
    iVar2 = fn24(container, 0, iVar2);
    int iVar3 = 0;
    if (iVar2 != 0) {
        if (FUN_005de180(self)) {
            auto fn54 = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t*)>(static_cast<char*>(cVtable) + 0x54);
            iVar3 = fn54(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, param_2);
        } else if (!FUN_005de1b0(self)) {
            if (!FUN_005de970(self)) {
                if (!FUN_005de9a0(self)) {
                    if (!FUN_005de9d0(self)) {
                        if (!FUN_005dea00(self)) {
                            if (FUN_005de940(self)) {
                                auto fn44 = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t)>(static_cast<char*>(cVtable) + 0x44);
                                iVar2 = fn44(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, *param_2);
                                return -1 < iVar2;
                            }
                            if (FUN_005de150(self)) {
                                auto fn3c = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t)>(static_cast<char*>(cVtable) + 0x3c);
                                iVar2 = fn3c(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, *param_2);
                                return -1 < iVar2;
                            }
                            if (!FUN_005de120(self)) return false;
                            auto fn34 = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t)>(static_cast<char*>(cVtable) + 0x34);
                            iVar2 = fn34(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, *param_2);
                            return -1 < iVar2;
                        }
                    }
                }
                auto fn4c = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t*)>(static_cast<char*>(cVtable) + 0x4c);
                iVar2 = fn4c(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, param_2);
                return -1 < iVar2;
            }
            auto fn4c = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t*)>(static_cast<char*>(cVtable) + 0x4c);
            iVar2 = fn4c(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, param_2);
            return -1 < iVar2;
        } else {
            auto fn4c = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t*)>(static_cast<char*>(cVtable) + 0x4c);
            iVar2 = fn4c(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, param_2);
            return -1 < iVar2;
        }
    }
    return -1 < iVar3;
}

// 0x5debb0 — observed shape
bool FUN_005debb0(void* self, int param_1, int param_2, uint32_t count, int ebx_mult, int ebp_base)
{
    if ((*reinterpret_cast<int*>(static_cast<char*>(self) + 0x30) == 0) ||
        (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) == 0)) {
        return false;
    }
    uint32_t uVar5 = *reinterpret_cast<uint32_t*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    if (DAT_00729060[uVar5 & 0xff] != 8) {
        if (!FUN_005de1b0(self)) return false;
    }
    if (param_2 == 0) {
        param_2 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x2c);
    }
    int iVar3 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x20);
    if (iVar3 == 0) {
        iVar3 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 8);
    }
    void* container = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x30);
    void* cVtable = *reinterpret_cast<void**>(container);
    auto fn24 = *reinterpret_cast<int(**)(void*, int, int)>(static_cast<char*>(cVtable) + 0x24);
    iVar3 = fn24(container, 0, iVar3);
    if (iVar3 != 0) {
        if (param_2 == 0) {
            auto fn58 = *reinterpret_cast<int(**)(void*, uint32_t, int, int, uint32_t)>(static_cast<char*>(cVtable) + 0x58);
            iVar3 = fn58(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar3, 0, count);
            return -1 < iVar3;
        }
        uVar5 = 0;
        if (count != 0) {
            do {
                uint16_t uVar1 = *reinterpret_cast<uint16_t*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_2))) + uVar5 * 2);
                auto fn28 = *reinterpret_cast<void(**)(void*, int, uint32_t)>(static_cast<char*>(cVtable) + 0x28);
                fn28(container, iVar3, uVar5);
                auto fn54 = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t)>(static_cast<char*>(cVtable) + 0x54);
                int iVar4 = fn54(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar3, (uint32_t)uVar1 * (uint32_t)ebx_mult * 0x10 + (uint32_t)ebp_base);
                if (iVar4 < 0) return false;
                uVar5 = uVar5 + 1;
            } while (uVar5 < count);
        }
    }
    return true;
}

// 0x5decc0 — observed shape
void FUN_005decc0(void* self)
{
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c8f88;
    operator_delete__(reinterpret_cast<void**>(self)[0xd]);
    operator_delete__(reinterpret_cast<void**>(self)[0xe]);
    int* piVar1 = static_cast<int*>(reinterpret_cast<void**>(self)[0xf]);
    if (piVar1 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar1);
        auto fn = *reinterpret_cast<void(**)(int*)>(static_cast<char*>(vtable) + 8);
        fn(piVar1);
        reinterpret_cast<void**>(self)[0xf] = nullptr;
    }
    FUN_005de5f0(self);
}

// 0x5ded00 — observed shape
void FUN_005ded00(void* self)
{
    int* piVar1 = *reinterpret_cast<int**>(static_cast<char*>(self) + 0x3c);
    if (piVar1 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar1);
        auto fn = *reinterpret_cast<void(**)(int*)>(static_cast<char*>(vtable) + 8);
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x3c) = 0;
    }
    FUN_005de5c0(self);
}

// 0x5ded30 — observed shape
bool FUN_005ded30(void* self, int param_1, uint32_t* param_2)
{
    if ((*reinterpret_cast<int*>(static_cast<char*>(self) + 0x3c) == 0) ||
        (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) == 0)) {
        return false;
    }
    if (param_2 == nullptr) {
        param_2 = *reinterpret_cast<uint32_t**>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x2c);
    }
    int iVar2 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x20);
    if (iVar2 == 0) {
        iVar2 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 8);
    }
    void* container = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x3c);
    void* cVtable = *reinterpret_cast<void**>(container);
    auto fn24 = *reinterpret_cast<int(**)(void*, int, int)>(static_cast<char*>(cVtable) + 0x24);
    iVar2 = fn24(container, 0, iVar2);
    int iVar3 = 0;
    if (iVar2 != 0) {
        if (FUN_005de180(self)) {
            auto fn54 = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t*)>(static_cast<char*>(cVtable) + 0x54);
            iVar3 = fn54(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, param_2);
        } else if (!FUN_005de1b0(self)) {
            if (!FUN_005de970(self)) {
                if (!FUN_005de9a0(self)) {
                    if (!FUN_005de9d0(self)) {
                        if (!FUN_005dea00(self)) {
                            if (FUN_005de940(self)) {
                                auto fn44 = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t)>(static_cast<char*>(cVtable) + 0x44);
                                iVar2 = fn44(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, *param_2);
                                return -1 < iVar2;
                            }
                            if (FUN_005de150(self)) {
                                auto fn3c = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t)>(static_cast<char*>(cVtable) + 0x3c);
                                iVar2 = fn3c(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, *param_2);
                                return -1 < iVar2;
                            }
                            if (!FUN_005de120(self)) return false;
                            auto fn34 = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t)>(static_cast<char*>(cVtable) + 0x34);
                            iVar2 = fn34(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, *param_2);
                            return -1 < iVar2;
                        }
                    }
                }
                auto fn4c = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t*)>(static_cast<char*>(cVtable) + 0x4c);
                iVar2 = fn4c(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, param_2);
                return -1 < iVar2;
            }
            auto fn4c = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t*)>(static_cast<char*>(cVtable) + 0x4c);
            iVar2 = fn4c(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, param_2);
            return -1 < iVar2;
        } else {
            auto fn4c = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t*)>(static_cast<char*>(cVtable) + 0x4c);
            iVar2 = fn4c(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar2, param_2);
            return -1 < iVar2;
        }
    }
    return -1 < iVar3;
}
// 0x5deeb0 — observed shape
bool FUN_005deeb0(void* self, int param_1, int param_2, uint32_t count, int ebx_mult, int ebp_base)
{
    if ((*reinterpret_cast<int*>(static_cast<char*>(self) + 0x3c) == 0) ||
        (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) == 0)) {
        return false;
    }
    uint32_t uVar5 = *reinterpret_cast<uint32_t*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    if (DAT_00729060[uVar5 & 0xff] != 8) {
        if (!FUN_005de1b0(self)) return false;
    }
    if (param_2 == 0) {
        param_2 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x2c);
    }
    int iVar3 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 0x20);
    if (iVar3 == 0) {
        iVar3 = *reinterpret_cast<int*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_1))) + 8);
    }
    void* container = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x3c);
    void* cVtable = *reinterpret_cast<void**>(container);
    auto fn24 = *reinterpret_cast<int(**)(void*, int, int)>(static_cast<char*>(cVtable) + 0x24);
    iVar3 = fn24(container, 0, iVar3);
    if (iVar3 != 0) {
        if (param_2 == 0) {
            auto fn58 = *reinterpret_cast<int(**)(void*, uint32_t, int, int, uint32_t)>(static_cast<char*>(cVtable) + 0x58);
            iVar3 = fn58(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar3, 0, count);
            return -1 < iVar3;
        }
        uVar5 = 0;
        if (count != 0) {
            do {
                uint16_t uVar1 = *reinterpret_cast<uint16_t*>(static_cast<char*>(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(param_2))) + uVar5 * 2);
                auto fn28 = *reinterpret_cast<void(**)(void*, int, uint32_t)>(static_cast<char*>(cVtable) + 0x28);
                fn28(container, iVar3, uVar5);
                auto fn54 = *reinterpret_cast<int(**)(void*, uint32_t, int, uint32_t)>(static_cast<char*>(cVtable) + 0x54);
                int iVar4 = fn54(container, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18), iVar3, (uint32_t)uVar1 * (uint32_t)ebx_mult * 0x10 + (uint32_t)ebp_base);
                if (iVar4 < 0) return false;
                uVar5 = uVar5 + 1;
            } while (uVar5 < count);
        }
    }
    return true;
}

// 0x5defc0 — observed shape
void FUN_005defc0(void* self)
{
    *reinterpret_cast<void**>(self) = &PTR_LAB_006fd148;
    reinterpret_cast<uint32_t*>(self)[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c9e8c;
    reinterpret_cast<uint32_t*>(self)[2] = 0;
    reinterpret_cast<uint32_t*>(self)[4] = 0;
    reinterpret_cast<uint32_t*>(self)[5] = 0;
    reinterpret_cast<uint32_t*>(self)[6] = 0;
    reinterpret_cast<uint32_t*>(self)[7] = 0;
    reinterpret_cast<uint32_t*>(self)[8] = 0;
    reinterpret_cast<uint32_t*>(self)[9] = 0;
    reinterpret_cast<uint32_t*>(self)[10] = 0;
    reinterpret_cast<uint32_t*>(self)[0xb] = 0;
    *reinterpret_cast<uint8_t*>(static_cast<char*>(self) + 0xc * 4) = 0;
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
}

// 0x5df010 — observed shape
void FUN_005df010(void* self, char* param_1)
{
    if (param_1 != nullptr) {
        int iVar5 = 1;
        bool bVar7 = true;
        char* pcVar2 = param_1;
        const char* pcVar6 = "";
        do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar7 = *pcVar2 == *pcVar6;
            pcVar2 = pcVar2 + 1;
            pcVar6 = pcVar6 + 1;
        } while (bVar7);
        if (!bVar7) {
            pcVar2 = param_1;
            char cVar1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            char* pcVar6b = *reinterpret_cast<char**>(static_cast<char*>(self) + 8);
            if (pcVar6b != nullptr) {
                char* pcVar3 = pcVar6b;
                do {
                    cVar1 = *pcVar3;
                    pcVar3 = pcVar3 + 1;
                } while (cVar1 != '\0');
                if (pcVar3 + -(int)(pcVar6b + 1) < pcVar2 + (1 - (int)(param_1 + 1))) {
                    operator_delete__(pcVar6b);
                    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 8) = 0;
                }
            }
            if (*reinterpret_cast<int*>(static_cast<char*>(self) + 8) == 0) {
                uint32_t uVar4 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(pcVar2 + (1 - (int)(param_1 + 1))));
                *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 8) = uVar4;
            }
            pcVar2 = *reinterpret_cast<char**>(static_cast<char*>(self) + 8);
            do {
                cVar1 = *param_1;
                param_1 = param_1 + 1;
                *pcVar2 = cVar1;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            return;
        }
    }
    operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 8));
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 8) = 0;
}

// 0x5df0b0 — observed shape
void FUN_005df0b0(void* self, char* param_1)
{
    if ((param_1 == nullptr) || (*param_1 == '\0')) {
        operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x20));
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x20) = 0;
        return;
    }
    char* pcVar3 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    char* pcVar2 = *reinterpret_cast<char**>(static_cast<char*>(self) + 0x20);
    if (pcVar2 != nullptr) {
        char* pcVar4 = pcVar2;
        do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        if (pcVar4 + -(int)(pcVar2 + 1) < pcVar3 + (1 - (int)(param_1 + 1))) {
            operator_delete__(pcVar2);
            *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x20) = 0;
        }
    }
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x20) == 0) {
        uint32_t uVar5 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(pcVar3 + (1 - (int)(param_1 + 1))));
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x20) = uVar5;
    }
    pcVar3 = *reinterpret_cast<char**>(static_cast<char*>(self) + 0x20);
    do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar3 = cVar1;
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
}

// 0x5df140 — observed shape
void FUN_005df140(void* self, uint32_t param_1, uint32_t param_2, uint32_t* param_3, char param_4)
{
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x28) = param_2;
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x24) = param_1;
    if (param_4 == '\0') {
        *reinterpret_cast<uint8_t*>(static_cast<char*>(self) + 0x30) = 0;
        *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x2c) = param_3;
        return;
    }
    *reinterpret_cast<uint8_t*>(static_cast<char*>(self) + 0x30) = 1;
    operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x2c));
    uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(param_1));
    *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x2c) = puVar1;
    for (uint32_t uVar2 = param_1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = *param_3;
        param_3 = param_3 + 1;
        puVar1 = puVar1 + 1;
    }
    for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
        *reinterpret_cast<uint8_t*>(puVar1) = *reinterpret_cast<uint8_t*>(param_3);
        param_3 = reinterpret_cast<uint32_t*>(reinterpret_cast<std::uintptr_t>(param_3) + 1);
        puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<std::uintptr_t>(puVar1) + 1);
    }
}
