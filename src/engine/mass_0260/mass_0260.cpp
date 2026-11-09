#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

static inline float bits_to_float(uint32_t bits)
{
    float f;
    std::memcpy(&f, &bits, sizeof(f));
    return f;
}

extern int FUN_0060b97b();
extern int FUN_0060b98d(uint32_t param_1, uint32_t param_2);
extern int FUN_005f7412(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10, uint32_t p11, uint32_t p12, uint32_t p13, uint32_t p14, uint32_t p15, uint32_t p16);
extern void FUN_0060bb0e();
extern void FUN_0060dc0d();
extern void FUN_0060dcfa();
extern int FUN_0060f067(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4);
extern int FUN_0060f0e5(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4);
extern void FUN_00610c00();
extern int FUN_00613e10(void* buf, uint32_t flag, uint32_t zero, void** out);
extern void FUN_0061324d();
extern int FUN_0060f796();
extern void FUN_0060f728(int p);
extern void FUN_006142c8();
extern int FUN_006253a7(void* buf, uint32_t zero1, uint32_t p3, uint32_t zero2, uint32_t p5, uint32_t flags, void** out1, void** out2);
extern void FUN_00615ccd();

// 0x5f7519 — observed shape
int FUN_005f7519(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9, uint32_t param_10, uint32_t param_11, uint32_t param_12, uint32_t param_13, uint32_t param_14, uint32_t param_15)
{
    int iVar1;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;

    FUN_0060b97b();
    iVar1 = FUN_0060b98d(param_2, 0);
    if (-1 < iVar1) {
        iVar1 = FUN_005f7412(param_1, local_c, local_8, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15);
    }
    FUN_0060bb0e();
    return iVar1;
}

// 0x5f7581 — observed shape
int FUN_005f7581(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint param_4, uint32_t* param_5, int param_6)
{
    int iVar1;
    int iVar2;
    uint8_t local_338[816];
    void* local_8 = nullptr;

    FUN_0060dc0d();
    if (param_5 != nullptr) {
        *param_5 = 0;
    }
    if ((param_4 & 0xfffffffc) == 0) {
        iVar2 = FUN_0060f067(param_1, 0, param_2, param_3);
        if (-1 < iVar2) {
            FUN_00610c00();
            iVar2 = FUN_00613e10(local_338, param_4, 0, &local_8);
            FUN_0061324d();
            if (-1 < iVar2) {
                iVar1 = FUN_0060f796();
                if (iVar1 == 0) {
                    if (param_5 != nullptr) {
                        *param_5 = reinterpret_cast<uintptr_t>(local_8);
                        local_8 = nullptr;
                    }
                }
                else {
                    iVar2 = static_cast<int>(0x88760b59);
                }
            }
        }
    }
    else {
        iVar2 = static_cast<int>(0x8876086c);
    }
    if (param_6 != 0) {
        FUN_0060f728(param_6);
    }
    if (local_8 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_8);
        using ReleaseFn = void(__cdecl*)(void*);
        ReleaseFn fn = reinterpret_cast<ReleaseFn*>(vtable)[2];
        fn(local_8);
        local_8 = nullptr;
    }
    FUN_0060dcfa();
    return iVar2;
}

// 0x5f7662 — observed shape
int FUN_005f7662(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint param_5, uint32_t* param_6, int param_7)
{
    int iVar1;
    int iVar2;
    uint8_t local_338[816];
    void* local_8 = nullptr;

    FUN_0060dc0d();
    if (param_6 != nullptr) {
        *param_6 = 0;
    }
    if ((param_5 & 0xfffffffc) == 0) {
        iVar2 = FUN_0060f0e5(param_1, param_2, param_3, param_4);
        if (-1 < iVar2) {
            FUN_00610c00();
            iVar2 = FUN_00613e10(local_338, param_5, 0, &local_8);
            FUN_0061324d();
            if (-1 < iVar2) {
                iVar1 = FUN_0060f796();
                if (iVar1 == 0) {
                    if (param_6 != nullptr) {
                        *param_6 = reinterpret_cast<uintptr_t>(local_8);
                        local_8 = nullptr;
                    }
                }
                else {
                    iVar2 = static_cast<int>(0x88760b59);
                }
            }
        }
    }
    else {
        iVar2 = static_cast<int>(0x8876086c);
    }
    if (param_7 != 0) {
        FUN_0060f728(param_7);
    }
    if (local_8 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_8);
        using ReleaseFn = void(__cdecl*)(void*);
        ReleaseFn fn = reinterpret_cast<ReleaseFn*>(vtable)[2];
        fn(local_8);
        local_8 = nullptr;
    }
    FUN_0060dcfa();
    return iVar2;
}

// 0x5f7745 — observed shape
int FUN_005f7745(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint param_6, uint32_t* param_7, int param_8, uint32_t* param_9)
{
    int iVar1;
    int iVar2;
    uint8_t local_374[872];
    void* local_c = nullptr;
    void* local_8 = nullptr;

    FUN_0060dc0d();
    if (param_7 != nullptr) {
        *param_7 = 0;
    }
    if (param_9 != nullptr) {
        *param_9 = 0;
    }
    if ((param_6 & 0xfffff9c0) == 0) {
        iVar1 = FUN_0060f067(param_1, 0, param_2, param_3);
        if (-1 < iVar1) {
            FUN_006142c8();
            iVar1 = FUN_006253a7(local_374, 0, param_4, 0, param_5, param_6 | 0x100, &local_8, &local_c);
            if (iVar1 < 0) {
                FUN_00615ccd();
            }
            else {
                FUN_00615ccd();
                iVar2 = FUN_0060f796();
                if (iVar2 == 0) {
                    if (param_7 != nullptr) {
                        *param_7 = reinterpret_cast<uintptr_t>(local_8);
                        local_8 = nullptr;
                    }
                    if (param_9 != nullptr) {
                        *param_9 = reinterpret_cast<uintptr_t>(local_c);
                        local_c = nullptr;
                    }
                }
                else {
                    iVar1 = static_cast<int>(0x88760b59);
                }
            }
        }
    }
    else {
        iVar1 = static_cast<int>(0x8876086c);
    }
    if (param_8 != 0) {
        FUN_0060f728(param_8);
    }
    if (local_c != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_c);
        using ReleaseFn = void(__cdecl*)(void*);
        ReleaseFn fn = reinterpret_cast<ReleaseFn*>(vtable)[2];
        fn(local_c);
        local_c = nullptr;
    }
    if (local_8 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_8);
        using ReleaseFn = void(__cdecl*)(void*);
        ReleaseFn fn = reinterpret_cast<ReleaseFn*>(vtable)[2];
        fn(local_8);
        local_8 = nullptr;
    }
    FUN_0060dcfa();
    return iVar1;
}

// 0x5f7876 — observed shape
int FUN_005f7876(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint param_7, uint32_t* param_8, int param_9, uint32_t* param_10)
{
    int iVar1;
    int iVar2;
    uint8_t local_374[872];
    void* local_c = nullptr;
    void* local_8 = nullptr;

    FUN_0060dc0d();
    if (param_8 != nullptr) {
        *param_8 = 0;
    }
    if (param_10 != nullptr) {
        *param_10 = 0;
    }
    if ((param_7 & 0xfffff9c0) == 0) {
        iVar1 = FUN_0060f0e5(param_1, param_2, param_3, param_4);
        if (-1 < iVar1) {
            FUN_006142c8();
            iVar1 = FUN_006253a7(local_374, 0, param_5, 0, param_6, param_7 | 0x100, &local_8, &local_c);
            if (iVar1 < 0) {
                FUN_00615ccd();
            }
            else {
                FUN_00615ccd();
                iVar2 = FUN_0060f796();
                if (iVar2 == 0) {
                    if (param_8 != nullptr) {
                        *param_8 = reinterpret_cast<uintptr_t>(local_8);
                        local_8 = nullptr;
                    }
                    if (param_10 != nullptr) {
                        *param_10 = reinterpret_cast<uintptr_t>(local_c);
                        local_c = nullptr;
                    }
                }
                else {
                    iVar1 = static_cast<int>(0x88760b59);
                }
            }
        }
    }
    else {
        iVar1 = static_cast<int>(0x8876086c);
    }
    if (param_9 != 0) {
        FUN_0060f728(param_9);
    }
    if (local_c != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_c);
        using ReleaseFn = void(__cdecl*)(void*);
        ReleaseFn fn = reinterpret_cast<ReleaseFn*>(vtable)[2];
        fn(local_c);
        local_c = nullptr;
    }
    if (local_8 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_8);
        using ReleaseFn = void(__cdecl*)(void*);
        ReleaseFn fn = reinterpret_cast<ReleaseFn*>(vtable)[2];
        fn(local_8);
        local_8 = nullptr;
    }
    FUN_0060dcfa();
    return iVar1;
}
extern void operator_delete(void* p) noexcept;
extern void FUN_00625d24();

// 0x5f7ad0 — observed shape
uint32_t FUN_005f7ad0(uint32_t* param_1, uint param_2, uint32_t* param_3, int* param_4)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    uint uVar3;
    uint32_t* puVar4;
    uint uVar5;

    if (param_3 != nullptr) {
        *param_3 = 0;
    }
    if (param_4 != nullptr) {
        *param_4 = 0;
    }
    if (param_1 == nullptr) {
        uVar2 = 0x8876086c;
    }
    else {
        uVar3 = *param_1 & 0xffff0000;
        puVar4 = param_1;
        if (((((uVar3 == 0x46580000) || (uVar3 == 0x54580000)) || (uVar3 == 0x7ffe0000)) ||
            ((uVar3 == 0x7fff0000 || (uVar3 == 0xfffe0000)))) || (uVar3 == 0xffff0000)) {
            for (;;) {
                for (;;) {
                    do {
                        puVar1 = puVar4;
                        puVar4 = puVar1 + 1;
                        uVar3 = *puVar4;
                    } while (static_cast<int>(uVar3) < 0);
                    uVar5 = uVar3 & 0xffff;
                    if (uVar5 == 0xffff) {
                        return 1;
                    }
                    if (uVar5 != 0xfffe) break;
                    uVar3 = (uVar3 >> 0x10) & 0x7fff;
                    if ((1 < uVar3) && (param_2 == puVar1[2])) {
                        if (param_3 != nullptr) {
                            *param_3 = reinterpret_cast<uintptr_t>(puVar1 + 3);
                        }
                        if (param_4 != nullptr) {
                            *param_4 = static_cast<int>(uVar3 * 4 - 4);
                        }
                        return 0;
                    }
                    puVar4 = puVar4 + uVar3;
                }
                if (0x1ff < (*param_1 & 0xffff)) {
                    uVar3 = (uVar3 >> 0x18) & 0xf;
                    puVar4 = puVar4 + uVar3;
                    continue;
                }
                if (uVar5 == 0x51) {
                    puVar4 = puVar1 + 6;
                }
            }
        }
        uVar2 = 0x88760b59;
    }
    return uVar2;
}

// 0x5f7bb7 — observed shape
uint32_t FUN_005f7bb7(uint32_t* param_1)
{
    uint32_t uVar1 = 0;
    if (param_1 != nullptr) {
        uVar1 = *param_1;
    }
    return uVar1;
}

// 0x5f7bc9 — observed shape
uint32_t FUN_005f7bc9(uint32_t* param_1, int param_2, int* param_3)
{
    uint32_t* puVar1;
    uint32_t* puVar5;
    uint32_t uVar4;
    uint32_t* puVar7;
    uint32_t uVar6;
    char local_1c[8] = {0};
    uint32_t local_14;
    int local_10 = 0;
    int local_c = 0;
    uint32_t local_8;

    puVar7 = param_1;
    if (param_1 == nullptr) {
        return 0x8876086c;
    }
    param_1 = nullptr;
    if (param_3 != nullptr) {
        *param_3 = 0;
    }
    local_14 = *puVar7;
    uVar4 = local_14 & 0xffff0000;
    if (uVar4 != 0x46580000) {
        if (uVar4 == 0xfffe0000) {
            uint8_t bVar3 = *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(puVar7) + 1);
            while (true) {
                do {
                    puVar5 = puVar7;
                    puVar7 = puVar5 + 1;
                } while (static_cast<int>(*puVar7) < 0);
                if (((*puVar7 & 0xffff) == 0x1f) && (((puVar5[3] >> 0x14) & 0x700 | (puVar5[3] & 0x1800)) == 0x100)) {
                    if (param_2 != 0) {
                        *reinterpret_cast<uint32_t*>(param_2 + reinterpret_cast<intptr_t>(param_1) * 8) = puVar5[2] & 0xffff;
                        *reinterpret_cast<uint32_t*>(param_2 + 4 + reinterpret_cast<intptr_t>(param_1) * 8) = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(puVar5) + 10) & 0x7fff;
                    }
                    param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_1) + 1);
                }
                uVar4 = *puVar7;
                uVar6 = uVar4 & 0xffff;
                if (uVar6 == 0xffff) break;
                if (uVar6 == 0xfffe) {
                    uVar4 = (uVar4 >> 0x10) & 0x7fff;
                    puVar7 = puVar7 + uVar4;
                }
                else {
                    if (bVar3 > 1) {
                        uVar4 = (uVar4 >> 0x18) & 0xf;
                        puVar7 = puVar7 + uVar4;
                    }
                    if (uVar6 == 0x51) {
                        puVar7 = puVar5 + 6;
                    }
                }
            }
        }
        else {
            if (uVar4 != 0xffff0000) {
                return 0x88760b59;
            }
            int8_t cVar2 = *reinterpret_cast<int8_t*>(reinterpret_cast<uintptr_t>(puVar7) + 1);
            if (cVar2 == 0x03) {
                while (true) {
                    puVar5 = puVar7 + 1;
                    if (((*puVar5 & 0xffff) == 0x1f) && ((((puVar7[3] >> 0x14) & 0x700) | (puVar7[3] & 0x1800)) == 0x100)) {
                        if (param_2 != 0) {
                            *reinterpret_cast<uint32_t*>(param_2 + reinterpret_cast<intptr_t>(param_1) * 8) = puVar7[2] & 0xffff;
                            *reinterpret_cast<uint32_t*>(param_2 + 4 + reinterpret_cast<intptr_t>(param_1) * 8) = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(puVar7) + 10) & 0x7fff;
                        }
                        param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_1) + 1);
                    }
                    uVar4 = *puVar5;
                    if ((uVar4 & 0xffff) == 0xffff) break;
                    if ((uVar4 & 0xffff) == 0xfffe) {
                        uVar4 = (uVar4 >> 0x10) & 0x7fff;
                    }
                    else {
                        uVar4 = (uVar4 >> 0x18) & 0xf;
                    }
                    puVar7 = puVar5 + uVar4;
                }
            }
            else if (cVar2 == 0x02) {
                for (;;) {
                    puVar5 = puVar7 + 1;
                    if ((*puVar5 & 0xffff) == 0x1f) {
                        uVar6 = puVar7[3] & 0x7ff;
                        uVar4 = puVar7[3] & 0xf0001800;
                        if (param_2 == 0) {
                            if (uVar4 == 0xa0000800) goto LAB_005f7d2d;
                        }
                        else if (uVar4 == 0xb0000000) {
                            *reinterpret_cast<uint32_t*>(param_2 + reinterpret_cast<intptr_t>(param_1) * 8) = 5;
                            *reinterpret_cast<uint32_t*>(param_2 + 4 + reinterpret_cast<intptr_t>(param_1) * 8) = uVar6;
                        }
                        else {
                            if (uVar4 != 0x90000000) {
                                if (uVar4 != 0xa0000800) {
                                    return 0x80004005;
                                }
                                goto LAB_005f7d2d;
                            }
                            if (uVar6 > 1) {
                                return 0x80004005;
                            }
                            *reinterpret_cast<uint32_t*>(param_2 + 4 + reinterpret_cast<intptr_t>(param_1) * 8) = 0;
                            *reinterpret_cast<uint32_t*>(param_2 + reinterpret_cast<intptr_t>(param_1) * 8) = 10;
                        }
                        param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_1) + 1);
                    }
LAB_005f7d2d:
                    uVar4 = *puVar5;
                    if ((uVar4 & 0xffff) == 0xffff) goto LAB_005f7ec7;
                    if ((uVar4 & 0xffff) == 0xfffe) {
                        uVar4 = (uVar4 >> 0x10) & 0x7fff;
                    }
                    else {
                        uVar4 = (uVar4 >> 0x18) & 0xf;
                    }
                    puVar7 = puVar5 + uVar4;
                }
            }
            if (cVar2 != 0x01) {
                return 0x80004005;
            }
            memset(local_1c, 0, sizeof(local_1c));
            local_c = 0;
            local_10 = 0;
            local_8 = (static_cast<int8_t>(local_14) == 0x04) ? 1 : 0;
            while (true) {
                while (true) {
                    puVar5 = puVar7;
                    puVar7 = puVar5 + 1;
                    uVar4 = *puVar7;
                    if (static_cast<int>(uVar4) >= 0) break;
                    if ((uVar4 & 0xf0001800) == 0x90000000) {
                        if ((uVar4 & 0x7ff) == 0) {
                            local_c = 1;
                        }
                        else if ((uVar4 & 0x7ff) == 1) {
                            local_10 = 1;
                        }
                    }
                    if ((local_8 != 0) && ((uVar4 & 0xf0001800) == 0xb0000000)) {
                        local_1c[uVar4 & 0x7ff] = 1;
                    }
                }
                uVar6 = uVar4 & 0xffff;
                if (uVar6 == 0xffff) break;
                if (uVar6 == 0xfffe) {
                    uVar4 = (uVar4 >> 0x10) & 0x7fff;
                    puVar7 = puVar7 + uVar4;
                }
                else {
                    if ((((local_8 == 0) && (0x3f < uVar6)) && ((uVar6 < 0x4b || ((0x4b < uVar6 && ((uVar6 < 0x4e || ((0x51 < uVar6 && (uVar6 < 0x58)))))))))) && (((puVar5[2] & 0xf0001800) == 0xb0000000))) {
                        local_1c[puVar5[2] & 0x7ff] = 1;
                    }
                    if (0x1ff < (local_14 & 0xffff)) {
                        uVar4 = (uVar4 >> 0x18) & 0xf;
                        puVar7 = puVar7 + uVar4;
                    }
                    if (uVar6 == 0x51) {
                        puVar7 = puVar5 + 6;
                    }
                }
            }
            uVar4 = 0;
            do {
                if (local_1c[uVar4] != 0) {
                    if (param_2 != 0) {
                        *reinterpret_cast<uint32_t*>(param_2 + reinterpret_cast<intptr_t>(param_1) * 8) = 5;
                        *reinterpret_cast<uint32_t*>(param_2 + 4 + reinterpret_cast<intptr_t>(param_1) * 8) = uVar4;
                    }
                    param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_1) + 1);
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < 6);
            if (local_c != 0) {
                if (param_2 != 0) {
                    puVar1 = reinterpret_cast<uint32_t*>(param_2 + reinterpret_cast<intptr_t>(param_1) * 8);
                    *puVar1 = 10;
                    puVar1[1] = 0;
                }
                param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_1) + 1);
            }
            if (local_10 != 0) {
                if (param_2 != 0) {
                    puVar1 = reinterpret_cast<uint32_t*>(param_2 + reinterpret_cast<intptr_t>(param_1) * 8);
                    *puVar1 = 10;
                    puVar1[1] = 1;
                }
                param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_1) + 1);
            }
LAB_005f7ec7:
            if (param_3 != nullptr) {
                *param_3 = reinterpret_cast<intptr_t>(param_1);
            }
        }
    }
    return 0;
}

// 0x5f7f83 — observed shape
// Scalar deleting destructor: register receiver in_ECX modelled as an explicit `self` parameter;
// the low bit of the flag selects the conditional delete.
void FUN_005f7f83(void* self, uint8_t param_1)
{
    FUN_00625d24();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5f7fa4 — observed shape
uint32_t FUN_005f7fa4(uint8_t* param_1, uint param_2, uint32_t* param_3)
{
    uint8_t bVar1;
    uint32_t uVar2;
    uint uVar3;
    int iVar4;
    uint uVar5;
    uint8_t* pbVar6;
    uint8_t* pbVar7;
    bool bVar8;
    uint local_8;
    extern uint8_t UNK_006dcf38;
    extern uint8_t DAT_006dcf40;

    uVar5 = 0;
    if (param_1 == nullptr) {
        uVar2 = 0x8876086c;
    }
    else {
        local_8 = 0x2c;
        do {
            uVar3 = (local_8 + uVar5) >> 1;
            pbVar6 = *reinterpret_cast<uint8_t**>(reinterpret_cast<uintptr_t>(&UNK_006dcf38) + uVar3 * 0xc);
            pbVar7 = param_1;
            do {
                bVar1 = *pbVar6;
                bVar8 = bVar1 < *pbVar7;
                if (bVar1 != *pbVar7) {
                    iVar4 = static_cast<int>(1 - static_cast<uint>(bVar8) - static_cast<uint>(bVar8 != 0));
                    goto LAB_005f7ff9;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar6[1];
                bVar8 = bVar1 < pbVar7[1];
                if (bVar1 != pbVar7[1]) {
                    iVar4 = static_cast<int>(1 - static_cast<uint>(bVar8) - static_cast<uint>(bVar8 != 0));
                    goto LAB_005f7ff9;
                }
                pbVar6 = pbVar6 + 2;
                pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_005f7ff9:
            if (iVar4 == 0) {
                uint iVar4idx = static_cast<uint>(uVar3 * 0xc);
                if ((*reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(&DAT_006dcf40) + iVar4idx) & param_2) == param_2) {
                    if (param_3 != nullptr) {
                        *reinterpret_cast<uint32_t*>(param_3) = *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(&UNK_006dcf38) + iVar4idx);
                        param_3[1] = *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(&UNK_006dcf3c) + iVar4idx);
                        param_3[2] = *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(&DAT_006dcf40) + iVar4idx);
                    }
                    return 0;
                }
                break;
            }
            if (iVar4 < 0) {
                uVar5 = uVar3 + 1;
            }
            else {
                local_8 = uVar3;
            }
        } while (uVar5 < local_8);
        uVar2 = 0x80004005;
    }
    return uVar2;
}
// 0x5f8091 — observed shape
int FUN_005f8091(uint32_t* param_1, int* param_2)
{
    int iVar1;
    int iVar2 = 0;
    if (param_2 != nullptr) {
        *param_2 = 0;
    }
    if ((param_1 == nullptr) || (param_2 == nullptr)) {
        return static_cast<int>(0x8876086c);
    }
    if (((*param_1 & 0xffff0000) == 0xfffe0000) || ((*param_1 & 0xffff0000) == 0xffff0000)) {
        extern int FUN_00533c78(uint32_t size);
        extern int FUN_006287bc();
        extern int FUN_006287dd(uint32_t* p1, uint32_t p2);
        iVar1 = FUN_00533c78(0x20);
        if (iVar1 != 0) {
            iVar2 = FUN_006287bc();
        }
        if (iVar2 == 0) {
            return static_cast<int>(0x8007000e);
        }
        iVar1 = FUN_006287dd(param_1, 0);
        if (iVar1 < 0) {
            FUN_005f7f83(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar2)), 1);
            return iVar1;
        }
    }
    *param_2 = iVar2;
    return 0;
}

// 0x5f8112 — observed shape
int FUN_005f8112(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t* param_5, uint32_t* param_6)
{
    extern int FUN_00533c78(uint32_t size);
    extern void* FUN_00630f1c();
    extern int FUN_0060f067(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4);
    extern int FUN_0063d60d(void* p1, uint32_t p2, int* p3);
    extern int FUN_0060f796();
    extern int FUN_00631caf(int v);
    extern void FUN_0060d2b8();
    extern void FUN_0060f728(uint32_t* p);

    int iVar1;
    int iVar2;
    int* piVar3 = nullptr;
    int local_8 = 0;
    if (param_5 != nullptr) {
        *param_5 = 0;
    }
    if (param_6 != nullptr) {
        *param_6 = 0;
    }
    if ((param_1 == 0) || (param_5 == nullptr)) {
        iVar1 = static_cast<int>(0x8876086c);
    }
    else {
        iVar1 = FUN_00533c78(0x360);
        if (iVar1 == 0) {
            piVar3 = nullptr;
        }
        else {
            piVar3 = reinterpret_cast<int*>(FUN_00630f1c());
        }
        if (piVar3 == nullptr) {
            iVar1 = static_cast<int>(0x8007000e);
            goto LAB_005f8207;
        }
        iVar1 = FUN_0060f067(param_1, 0, param_2, param_3);
        if (iVar1 >= 0) {
            iVar1 = FUN_0063d60d(reinterpret_cast<uint8_t*>(piVar3) + 16, param_4, &local_8);
            if (iVar1 >= 0) {
                iVar1 = FUN_0060f796();
                if (iVar1 == 0) {
                    iVar1 = FUN_00631caf(local_8);
                    if (iVar1 >= 0) {
                        local_8 = 0;
                        iVar2 = FUN_0060f796();
                        if (iVar2 != 0) goto LAB_005f81b1;
                        *param_5 = reinterpret_cast<uintptr_t>(piVar3);
                        {
                            void* vtable = *reinterpret_cast<void**>(piVar3);
                            using Fn = void(__cdecl*)(int*);
                            Fn fn = reinterpret_cast<Fn*>(vtable)[1];
                            fn(piVar3);
                        }
                    }
                }
                else {
LAB_005f81b1:
                    iVar1 = static_cast<int>(0x88760b59);
                }
            }
        }
    }
    if (piVar3 != nullptr) {
        FUN_0060d2b8();
        if (param_6 != nullptr) {
            FUN_0060f728(param_6);
        }
    }
LAB_005f8207:
    if (local_8 != 0) {
        local_8 = 0;
    }
    if (piVar3 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar3);
        using Fn = void(__cdecl*)(int*);
        Fn fn = reinterpret_cast<Fn*>(vtable)[2];
        fn(piVar3);
    }
    return iVar1;
}

// 0x5f8222 — observed shape
int FUN_005f8222(int param_1, uint param_2, uint32_t param_3, int* param_4, uint param_5, uint32_t param_6, uint32_t* param_7, int* param_8)
{
    extern void FUN_0060b97b();
    extern void FUN_0060bb0e();
    extern int FUN_0060b98d(uint32_t p1, uint32_t p2);
    extern int FUN_00533c78(uint32_t size);
    extern void* FUN_00647cf7();
    extern int FUN_005f8112(int p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t* p5, uint32_t* p6);
    extern int FUN_006294f9(uint32_t size, void** out);
    extern int FUN_006522f5(int p1, uint32_t p2, void* p3, uint32_t* p4);
    extern int FUN_0064dc3f();
    extern void FUN_0060bacb();

    int* piVar1;
    int iVar3;
    int iVar4;
    int* piVar5;
    uint uVar6;
    int* piVar7;
    int* local_24 = nullptr;
    uint local_20 = 0;
    int* local_1c = nullptr;
    int local_18 = 0;
    int* local_14 = nullptr;
    uint local_10 = 0;
    int* local_c = nullptr;
    int* local_8 = nullptr;

    FUN_0060b97b();
    piVar5 = param_4;
    if (param_7 != nullptr) {
        *param_7 = 0;
    }
    if (param_8 != nullptr) {
        *param_8 = 0;
    }
    if ((param_1 == 0) || (param_2 == 0)) {
        iVar3 = static_cast<int>(0x8876086c);
LAB_005f83f6:
        if (local_18 != 0) {
            piVar5 = param_4;
            goto LAB_005f83ff;
        }
    }
    else {
        if (param_4 == nullptr) {
            iVar3 = FUN_0060b98d(param_2, 0);
            if (iVar3 < 0) goto LAB_005f8425;
            local_10 = local_20;
            local_14 = local_24;
        }
        else {
            using Fn = int(__cdecl*)(int*, uint32_t, uint32_t, uint32_t, int**, uint*);
            void* vtable = *reinterpret_cast<void**>(param_4);
            Fn fn = reinterpret_cast<Fn*>(vtable)[0];
            iVar3 = fn(param_4, 0, param_2, 0, &local_14, &local_10);
            if (iVar3 < 0) goto LAB_005f8425;
        }
        local_18 = 1;
        iVar4 = FUN_00533c78(0x130);
        if (iVar4 == 0) {
            local_c = nullptr;
        }
        else {
            local_c = reinterpret_cast<int*>(FUN_00647cf7());
        }
        piVar7 = local_c;
        if (local_c == nullptr) {
            iVar3 = static_cast<int>(0x8007000e);
        }
        else if (local_10 < 4) {
            iVar3 = static_cast<int>(0x80004005);
        }
        else {
            if (*local_14 != -0x100f6ff) {
                if (piVar5 == nullptr) {
                    FUN_0060bacb();
                }
                else {
                    void* vtable = *reinterpret_cast<void**>(piVar5);
                    using Fn = void(__cdecl*)(int*, int*);
                    Fn fn = reinterpret_cast<Fn*>(vtable)[1];
                    fn(piVar5, local_14);
                }
                uVar6 = param_5;
                local_18 = 0;
                iVar3 = FUN_005f8112(param_2, param_3, reinterpret_cast<uintptr_t>(param_4), param_5, reinterpret_cast<uint32_t*>(&local_1c), reinterpret_cast<uint32_t*>(param_8));
                piVar5 = param_8;
                if (iVar3 >= 0) {
                    if ((param_8 != nullptr) && ((piVar1 = reinterpret_cast<int*>(*param_8)) != nullptr)) {
                        void* vtable = *reinterpret_cast<void**>(piVar1);
                        using Fn = void(__cdecl*)(int*);
                        Fn fn = reinterpret_cast<Fn*>(vtable)[2];
                        fn(piVar1);
                        *piVar5 = 0;
                    }
                    {
                        void* vtable = *reinterpret_cast<void**>(local_1c);
                        using Fn = int(__cdecl*)(int*, uint, int**, int*);
                        Fn fn = reinterpret_cast<Fn*>(vtable)[61];
                        iVar3 = fn(local_1c, uVar6 & 0xffffffe7, &local_8, piVar5);
                    }
                    if (iVar3 >= 0) goto LAB_005f83b5;
                }
                goto LAB_005f8416;
            }
            if (param_7 != nullptr) {
                iVar3 = FUN_006294f9(local_10, reinterpret_cast<void**>(&local_8));
                piVar7 = local_14;
                if (iVar3 < 0) goto LAB_005f83ff;
                param_2 = local_10;
                {
                    void* vtable = *reinterpret_cast<void**>(local_8);
                    using Fn = int*(__cdecl*)(int*);
                    Fn fn = reinterpret_cast<Fn*>(vtable)[3];
                    piVar5 = reinterpret_cast<int*>(fn(local_8));
                }
                for (uVar6 = param_2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *piVar5 = *piVar7;
                    piVar7 = piVar7 + 1;
                    piVar5 = piVar5 + 1;
                }
                for (uVar6 = param_2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *reinterpret_cast<char*>(piVar5) = static_cast<char>(*piVar7);
                    piVar7 = reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(piVar7) + 1);
                    piVar5 = reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(piVar5) + 1);
                }
                piVar7 = local_c;
LAB_005f83b5:
                if (param_7 != nullptr) {
                    uint32_t saved = param_2;
                    param_2 = 0;
                    iVar3 = FUN_006522f5(param_1, param_6, local_8, &param_2);
                    if (iVar3 >= 0) {
                        iVar3 = FUN_0064dc3f();
                    }
                    if (iVar3 >= 0) {
                        *param_7 = reinterpret_cast<uintptr_t>(piVar7);
                        void* vtable = *reinterpret_cast<void**>(piVar7);
                        using Fn = void(__cdecl*)(int*);
                        Fn fn = reinterpret_cast<Fn*>(vtable)[1];
                        fn(piVar7);
                    }
                    param_2 = saved;
                }
                goto LAB_005f83f6;
            }
        }
LAB_005f83ff:
        if (piVar5 == nullptr) {
            FUN_0060bacb();
        }
        else {
            void* vtable = *reinterpret_cast<void**>(piVar5);
            using Fn = void(__cdecl*)(int*, int*);
            Fn fn = reinterpret_cast<Fn*>(vtable)[1];
            fn(piVar5, local_14);
        }
    }
LAB_005f8416:
    if (local_1c != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_1c);
        using Fn = void(__cdecl*)(int*);
        Fn fn = reinterpret_cast<Fn*>(vtable)[2];
        fn(local_1c);
    }
LAB_005f8425:
    if (local_8 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_8);
        using Fn = void(__cdecl*)(int*);
        Fn fn = reinterpret_cast<Fn*>(vtable)[2];
        fn(local_8);
        local_8 = nullptr;
    }
    if (local_c != nullptr) {
        void* vtable = *reinterpret_cast<void**>(local_c);
        using Fn = void(__cdecl*)(int*);
        Fn fn = reinterpret_cast<Fn*>(vtable)[2];
        fn(local_c);
    }
    FUN_0060bb0e();
    return iVar3;
}

// 0x5f8453 — observed shape
void FUN_005f8453(int param_1, int param_2, uint32_t* param_3, uint32_t* param_4, uint param_5, uint param_6, float* param_7, int* param_8, char* param_9, float param_10, float* param_11)
{
    extern void thunk_FUN_005f186d(float* out, float a, int b);
    extern void thunk_FUN_005f1980(float* out, float a, int b);
    extern int ftol();

    float* pfVar4;
    int iVar5;
    int* piVar6;
    uint uVar7;
    uint uVar8;
    float* pfVar9;
    float fVar10;
    uint32_t* puVar11;
    uint32_t* puVar12;
    float local_33c[195];
    uint local_30 = static_cast<uint>(static_cast<int>(param_10) * 0xc);
    uint local_2c = (static_cast<int>(param_10) * 0xc != static_cast<int>(param_6)) ? 1 : 0;
    float local_28 = 0.0f;
    float local_24 = 0.0f;
    float local_20 = 0.0f;
    float local_1c = 0.0f;
    float local_18 = 0.0f;
    float local_14 = 0.0f;
    float local_10 = 0.0f;
    float* local_c = nullptr;
    float local_8 = 0.0f;

    if (param_2 == 0) {
        param_2 = param_1;
    }
    if (param_10 == 2.8026e-45f) {
        if ((param_9[0] == 0 && param_9[1] == 0x03)) {
            local_1c = param_7[0];
            local_8 = param_7[1];
            local_c = reinterpret_cast<float*>(param_8[1]);
            pfVar9 = reinterpret_cast<float*>(param_8[0]);
        }
        else {
            if ((param_9[1] != 0) || (param_9[0] != 0x03)) goto LAB_005f8642;
            local_1c = param_7[1];
            local_8 = param_7[0];
            pfVar9 = reinterpret_cast<float*>(param_8[1]);
            local_c = reinterpret_cast<float*>(param_8[0]);
        }
        if (local_1c != 0.0f) {
            if (param_5 == 0) {
                return;
            }
            float* iter = reinterpret_cast<float*>(param_5);
            do {
                if (local_2c != 0) {
                    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_4) + param_6);
                    puVar11 = param_3;
                    for (uVar7 = param_6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *param_4 = *puVar11;
                        puVar11 = puVar11 + 1;
                        param_4 = param_4 + 1;
                    }
                    param_3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_3) + param_6);
                    puVar12 = param_4;
                    for (uVar7 = param_6 & 3; param_4 = puVar2, uVar7 != 0; uVar7 = uVar7 - 1) {
                        *reinterpret_cast<uint8_t*>(puVar12) = *reinterpret_cast<uint8_t*>(puVar11);
                        puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar11) + 1);
                        puVar12 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar12) + 1);
                    }
                }
                pfVar9[0] = 0.0f;
                pfVar9[1] = 0.0f;
                pfVar9[2] = 0.0f;
                local_c[0] = 0.0f;
                local_c[1] = 0.0f;
                local_c[2] = 0.0f;
                if (param_11[0] >= 0.0f) {
                    do {
                        uVar7 = static_cast<uint>(ftol());
                        iVar5 = static_cast<int>((uVar7 >> 1) * 2);
                        fVar10 = static_cast<float>(iVar5);
                        if (iVar5 < 0) {
                            fVar10 = fVar10 + 4.2949673e+09f;
                        }
                        fVar10 = param_11[0] - fVar10;
                        iVar5 = static_cast<int>((uVar7 >> 1) * 0x40);
                        thunk_FUN_005f186d(&local_18, local_1c, param_1 + iVar5);
                        thunk_FUN_005f1980(&local_28, local_8, iVar5 + param_2);
                        local_18 = local_18 * fVar10;
                        param_11 = param_11 + 1;
                        local_14 = local_14 * fVar10;
                        local_10 = local_10 * fVar10;
                        local_28 = local_28 * fVar10;
                        local_24 = local_24 * fVar10;
                        local_20 = local_20 * fVar10;
                        pfVar9[0] = local_18 + pfVar9[0];
                        pfVar9[1] = local_14 + pfVar9[1];
                        pfVar9[2] = local_10 + pfVar9[2];
                        local_c[0] = local_28 + local_c[0];
                        local_c[1] = local_24 + local_c[1];
                        local_c[2] = local_20 + local_c[2];
                    } while (param_11[0] >= 0.0f);
                }
                local_1c = static_cast<float>(static_cast<int>(local_1c) + static_cast<int>(param_6));
                local_8 = static_cast<float>(static_cast<int>(local_8) + static_cast<int>(param_6));
                local_c = reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(local_c) + param_6);
                param_11 = param_11 + 1;
                pfVar9 = reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(pfVar9) + param_6);
                iter = reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(iter) - 1);
            } while (iter != nullptr);
            return;
        }
    }
LAB_005f8642:
    local_c = nullptr;
    if (param_5 != 0) {
        do {
            uVar7 = local_30;
            pfVar9 = local_33c;
            for (uVar8 = local_30 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *pfVar9 = 0.0f;
                pfVar9 = pfVar9 + 1;
            }
            for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *reinterpret_cast<uint8_t*>(pfVar9) = 0;
                pfVar9 = reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(pfVar9) + 1);
            }
            for (; param_11[0] >= 0.0f; param_11 = param_11 + 1) {
                uVar7 = static_cast<uint>(ftol());
                uVar7 = uVar7 >> 1;
                local_8 = static_cast<float>(static_cast<int>(uVar7 * 2));
                if (static_cast<int>(uVar7 * 2) < 0) {
                    local_8 = local_8 + 4.2949673e+09f;
                }
                local_8 = param_11[0] - local_8;
                fVar10 = 0.0f;
                if (param_10 != 0.0f) {
                    float* pf = local_33c + 2;
                    float idx = 0.0f;
                    do {
                        uint8_t bVar3 = static_cast<uint8_t>(param_9[static_cast<int>(idx)]);
                        if (bVar3 == 0) {
                            thunk_FUN_005f186d(&local_18, param_7[static_cast<int>(idx)], static_cast<int>(uVar7 * 0x40 + param_1));
                        }
                        else {
                            if (bVar3 == 3) {
                                iVar5 = static_cast<int>(uVar7 * 0x40 + param_2);
                            }
                            else {
                                if (bVar3 < 6) {
                                    return;
                                }
                                if (bVar3 > 7) {
                                    return;
                                }
                                iVar5 = static_cast<int>(uVar7 * 0x40 + param_1);
                            }
                            thunk_FUN_005f1980(&local_18, param_7[static_cast<int>(idx)], iVar5);
                        }
                        idx = static_cast<float>(static_cast<int>(idx) + 1);
                        local_18 = local_18 * local_8;
                        local_14 = local_14 * local_8;
                        local_10 = local_10 * local_8;
                        pf[-2] = local_18 + pf[-2];
                        pf[-1] = local_14 + pf[-1];
                        pf[0] = local_10 + pf[0];
                        pf = pf + 3;
                    } while (static_cast<uint>(idx) < static_cast<uint>(param_10));
                }
            }
            if (local_2c != 0) {
                uint32_t* puVar2 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_4) + param_6);
                puVar11 = param_3;
                for (uVar7 = param_6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *param_4 = *puVar11;
                    puVar11 = puVar11 + 1;
                    param_4 = param_4 + 1;
                }
                param_3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(param_3) + param_6);
                puVar12 = param_4;
                for (uVar7 = param_6 & 3; param_4 = puVar2, uVar7 != 0; uVar7 = uVar7 - 1) {
                    *reinterpret_cast<uint8_t*>(puVar12) = *reinterpret_cast<uint8_t*>(puVar11);
                    puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar11) + 1);
                    puVar12 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar12) + 1);
                }
            }
            if (param_10 != 0.0f) {
                pfVar9 = local_33c;
                float remain = param_10;
                piVar6 = param_8;
                do {
                    pfVar4 = reinterpret_cast<float*>(*piVar6);
                    *pfVar4 = *pfVar9;
                    pfVar4[1] = pfVar9[1];
                    pfVar4[2] = pfVar9[2];
                    *piVar6 = *piVar6 + static_cast<int>(param_6);
                    int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_7) - reinterpret_cast<intptr_t>(param_8) + reinterpret_cast<intptr_t>(piVar6));
                    *piVar1 = *piVar1 + static_cast<int>(param_6);
                    pfVar9 = pfVar9 + 3;
                    piVar6 = piVar6 + 1;
                    remain = static_cast<float>(static_cast<int>(remain) - 1);
                } while (remain != 0.0f);
            }
            param_11 = param_11 + 1;
            local_c = reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(local_c) + 1);
        } while (local_c < reinterpret_cast<float*>(param_5));
    }
}

// 0x5f87cd — observed shape
void FUN_005f87cd(float* param_1, float* param_2, float* param_3, float param_4, float* param_5)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;

    param_5[0] = param_1[0];
    param_5[1] = param_1[1];
    param_5[2] = param_1[2];
    param_5[0] = param_5[0] - param_2[0];
    param_5[1] = param_5[1] - param_2[1];
    fVar3 = param_5[2] - param_2[2];
    param_5[2] = fVar3;
    fVar4 = param_5[1] * param_3[1] + param_3[0] * param_5[0] + fVar3 * param_3[2];
    fVar1 = param_3[0];
    fVar2 = param_3[1];
    param_5[2] = fVar3 - fVar4 * param_3[2];
    fVar1 = (param_5[0] - fVar4 * fVar1) * param_4;
    param_5[0] = fVar1;
    fVar2 = (param_5[1] - fVar4 * fVar2) * param_4;
    param_5[1] = fVar2;
    param_5[2] = param_4 * param_5[2];
    param_5[0] = fVar1 + param_2[0];
    param_5[1] = fVar2 + param_2[1];
    param_5[2] = param_2[2] + param_5[2];
}

// 0x5f886c — observed shape
void FUN_005f886c(uint param_1, int param_2, uint param_3, float* param_4, float* param_5, float* param_6, float* param_7, uint param_8)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float* pfVar5;
    uint uVar6;
    int iVar7;
    float* pfVar8;

    // Bezier/barycentric scratch blocks addressed by the decompiler's stack slot names.
    float local_1cc[68];
    float local_bc[10];
    float local_7c, local_78, local_74;
    float local_34, local_30, local_2c;
    float local_10, local_c, local_8;
    float local_70, local_6c, local_68;
    float local_64, local_60, local_5c;
    float local_58, local_54, local_50;
    float local_40, local_3c, local_38;
    float local_28, local_24, local_20;
    float local_1c, local_18, local_14;
    float local_94, local_8c, local_84, local_80;
    float local_4c, local_48, local_44;

    local_7c = param_5[0];
    local_78 = param_5[1];
    local_74 = param_5[2];
    local_34 = param_6[0];
    local_30 = param_6[1];
    local_2c = param_6[2];
    local_10 = param_7[0];
    local_c = param_7[1];
    local_8 = param_7[2];
    FUN_005f87cd(&local_34, &local_7c, reinterpret_cast<float*>(param_1), bits_to_float(0x3eaaaaab), &local_70);
    FUN_005f87cd(&local_10, &local_7c, reinterpret_cast<float*>(param_1), bits_to_float(0x3eaaaaab), &local_64);
    FUN_005f87cd(&local_7c, &local_34, reinterpret_cast<float*>(param_1 + 0xc), bits_to_float(0x3eaaaaab), &local_58);
    FUN_005f87cd(&local_7c, &local_10, reinterpret_cast<float*>(param_1 + 0x18), bits_to_float(0x3eaaaaab), &local_40);
    FUN_005f87cd(&local_10, &local_34, reinterpret_cast<float*>(param_1 + 0xc), bits_to_float(0x3eaaaaab), &local_28);
    FUN_005f87cd(&local_34, &local_10, reinterpret_cast<float*>(param_1 + 0x18), bits_to_float(0x3eaaaaab), &local_1c);
    local_94 = local_10 + local_34 + local_7c;
    local_8c = local_8 + local_2c + local_74;
    param_1 = 0;
    local_84 = (local_c + local_30 + local_78) * 0.166666f;
    local_80 = local_8c * 0.166666f;
    local_4c = (local_1c + local_28 + local_40 + local_58 + local_64 + local_70) * 0.25f - local_94 * 0.166666f;
    local_48 = (local_18 + local_24 + local_3c + local_54 + local_60 + local_6c) * 0.25f - local_84;
    local_44 = (local_14 + local_20 + local_38 + local_50 + local_5c + local_68) * 0.25f - local_80;
    if (param_3 != 0) {
        do {
            fVar1 = *reinterpret_cast<float*>(param_1 * 8 + param_2);
            uVar6 = 0;
            fVar2 = *reinterpret_cast<float*>(param_1 * 8 + 4 + param_2);
            fVar4 = (1.0f - fVar1) - fVar2;
            local_bc[0] = fVar2 * fVar2 * fVar2;
            local_bc[1] = fVar4 * fVar2 * fVar2 * 3.0f;
            local_bc[2] = fVar2 * fVar2 * fVar1 * 3.0f;
            fVar3 = fVar4 * fVar4;
            local_bc[3] = fVar3 * fVar2 * 3.0f;
            local_bc[4] = fVar4 * fVar2 * fVar1 * 6.0f;
            local_bc[5] = fVar2 * fVar1 * fVar1 * 3.0f;
            local_bc[6] = fVar3 * fVar4;
            local_bc[7] = fVar3 * fVar1 * 3.0f;
            local_bc[8] = fVar4 * fVar1 * fVar1 * 3.0f;
            local_bc[9] = fVar1 * fVar1 * fVar1;
            local_1cc[0] = 0.0f;
            local_1cc[1] = 0.0f;
            local_1cc[2] = 0.0f;
            pfVar5 = &local_78;
            do {
                pfVar8 = local_bc + uVar6;
                uVar6 = uVar6 + 1;
                local_1cc[0] = pfVar5[-1] * *pfVar8 + local_1cc[0];
                local_1cc[1] = *pfVar8 * *pfVar5 + local_1cc[1];
                local_1cc[2] = pfVar5[1] * *pfVar8 + local_1cc[2];
                pfVar5 = pfVar5 + 3;
            } while (uVar6 < 10);
            if (param_8 > 3) {
                pfVar5 = param_6 + 3;
                iVar7 = static_cast<int>(param_8 - 3);
                do {
                    *reinterpret_cast<float*>(reinterpret_cast<intptr_t>(local_1cc) - reinterpret_cast<intptr_t>(param_6) + reinterpret_cast<intptr_t>(pfVar5)) =
                        fVar4 * *pfVar5 +
                        fVar2 * *reinterpret_cast<float*>(reinterpret_cast<intptr_t>(param_5) - reinterpret_cast<intptr_t>(param_6) + reinterpret_cast<intptr_t>(pfVar5)) +
                        fVar1 * *reinterpret_cast<float*>(reinterpret_cast<intptr_t>(param_7) - reinterpret_cast<intptr_t>(param_6) + reinterpret_cast<intptr_t>(pfVar5));
                    pfVar5 = pfVar5 + 1;
                    iVar7 = iVar7 - 1;
                } while (iVar7 != 0);
            }
            pfVar5 = local_1cc;
            pfVar8 = param_4;
            for (uVar6 = param_8 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                *pfVar8 = *pfVar5;
                pfVar5 = pfVar5 + 1;
                pfVar8 = pfVar8 + 1;
            }
            param_1 = param_1 + 1;
            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *reinterpret_cast<uint8_t*>(pfVar8) = *reinterpret_cast<uint8_t*>(pfVar5);
                pfVar5 = reinterpret_cast<float*>(reinterpret_cast<intptr_t>(pfVar5) + 1);
                pfVar8 = reinterpret_cast<float*>(reinterpret_cast<intptr_t>(pfVar8) + 1);
            }
            param_4 = param_4 + param_8;
        } while (param_1 < param_3);
    }
}

extern int cpuid_Version_info(int leaf);
extern int cpuid_basic_info(int leaf);

// 0x5f8bc5 — observed shape
// NEEDS_MANUAL: observed return packs EDX (register input, not a formal parameter) into the high
// half of the 64-bit result; the incoming EDX value is modelled as an explicit trailing argument.
uint64_t FUN_005f8bc5(uint32_t in_EDX)
{
    int iVar1;

    iVar1 = cpuid_Version_info(1);
    return (static_cast<uint64_t>(in_EDX) << 32) |
           static_cast<uint32_t>((*reinterpret_cast<uint32_t*>(iVar1 + 8) & 0x800000) != 0);
}

extern int32_t DAT_00718a5c;

// 0x5f8bed — observed shape
// NEEDS_MANUAL: local_18 aliases the WORD just past wProcessorArchitecture inside the
// GetSystemInfo output block; it is kept as a separate slot because the frame layout is flattened.
int FUN_005f8bed(void)
{
    LSTATUS LVar1;
    int iVar2;
    SYSTEM_INFO local_38;
    ushort local_18 = 0;
    int local_14 = 0;
    DWORD local_10[2] = {0, 0};
    HKEY local_8 = nullptr;

    LVar1 = RegOpenKeyA(reinterpret_cast<HKEY>(0x80000002), "Software\\Microsoft\\Direct3D", &local_8);
    if (LVar1 == 0) {
        local_10[1] = 4;
        LVar1 = RegQueryValueExA(local_8, "DisableMMX", nullptr, local_10, reinterpret_cast<LPBYTE>(&local_14), local_10 + 1);
        if (((LVar1 == 0) && (local_10[0] == 4)) && (local_14 != 0)) {
            RegCloseKey(local_8);
            DAT_00718a5c = 0;
            return 0;
        }
        RegCloseKey(local_8);
    }
    if (DAT_00718a5c < 0) {
        DAT_00718a5c = 0;
        GetSystemInfo(&local_38);
        if (((local_38.wProcessorArchitecture == 0) && (local_18 > 4))) {
            iVar2 = FUN_005f8bc5(0);
            if (iVar2 != 0) {
                DAT_00718a5c = 1;
            }
        }
    }
    return DAT_00718a5c;
}

// 0x5f8c9f — observed shape
// NEEDS_MANUAL: Ghidra exposes the frame through unaff_EBP; the EBP-relative slot writes are kept
// verbatim against a local byte frame.
void FUN_005f8c9f(void)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint8_t auStack_bc[128];
    uint8_t frame[0x40];
    uint8_t* const ebp = frame + 0x40;

    FUN_006b921c();
    *reinterpret_cast<uint8_t**>(ebp - 0x10) = auStack_bc + 0x80;
    *reinterpret_cast<uint32_t*>(ebp - 0x14) = 0;
    std::memcpy(ebp - 0x24, "Genu", 4);
    std::memcpy(ebp - 0x20, "ineI", 4);
    std::memcpy(ebp - 0x1c, "ntel", 4);
    *(ebp - 0x18) = '\0';
    *reinterpret_cast<uint32_t*>(ebp - 4) = 0;
    puVar1 = reinterpret_cast<uint32_t*>(cpuid_basic_info(0));
    uVar4 = puVar1[1];
    uVar3 = puVar1[2];
    uVar2 = puVar1[3];
    *reinterpret_cast<uint32_t*>(ebp - 0x2c) = puVar1[0];
    *reinterpret_cast<uint32_t*>(ebp - 0x38) = uVar4;
    *reinterpret_cast<uint32_t*>(ebp - 0x34) = uVar3;
    *reinterpret_cast<uint32_t*>(ebp - 0x30) = uVar2;
    FUN_005f8ce5();
}

extern void FUN_005f8ce5();
extern void* ExceptionList;   // NT_TIB.ExceptionList of the current TEB

// 0x5f8ce5 — observed shape
// NEEDS_MANUAL: non-contiguous body (0x5f8ce5-0x5f8cea, 0x5f8cf0-0x5f8d3f) and unaff_EBP frame;
// slot accesses and the TEB ExceptionList restore are preserved as observed.
uint32_t FUN_005f8ce5(void)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    uint8_t frame[0x40];
    uint8_t* const ebp = frame + 0x40;

    *reinterpret_cast<uint32_t*>(ebp - 4) = 0xffffffffu;
    if (*reinterpret_cast<int*>(ebp - 0x2c) == 0) {
        uVar2 = *reinterpret_cast<uint32_t*>(ebp - 0x14);
    }
    else {
        puVar1 = reinterpret_cast<uint32_t*>(cpuid_Version_info(1));
        uVar2 = puVar1[2];
        *reinterpret_cast<uint32_t*>(ebp - 0x2c) = puVar1[0];
        *reinterpret_cast<uint32_t*>(ebp - 0x28) = uVar2;
        if ((*reinterpret_cast<uint32_t*>(ebp - 0x28) & 0x2000000) != 0) {
            *reinterpret_cast<uint32_t*>(ebp - 0x14) = *reinterpret_cast<uint32_t*>(ebp - 0x14) | 4;
        }
        if ((*reinterpret_cast<uint32_t*>(ebp - 0x28) & 0x4000000) != 0) {
            *reinterpret_cast<uint32_t*>(ebp - 0x14) = *reinterpret_cast<uint32_t*>(ebp - 0x14) | 8;
        }
        uVar2 = *reinterpret_cast<uint32_t*>(ebp - 0x14);
    }
    ExceptionList = *reinterpret_cast<void**>(ebp - 0xc);
    return uVar2;
}

