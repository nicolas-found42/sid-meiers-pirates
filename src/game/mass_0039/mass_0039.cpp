#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern std::size_t DAT_008caccc;
extern unsigned char DAT_008cacd0[];
extern void* PTR_FUN_007116a0;
extern std::uint32_t DAT_008cacf0;
extern std::uint32_t DAT_008cace8;
extern std::uint32_t DAT_008cacec;
extern std::uint32_t DAT_00727444;
extern unsigned char DAT_00728374[];
extern unsigned char DAT_00728b88[];
extern std::uint32_t DAT_007257f8;
extern std::uint32_t DAT_008ea000;
extern int DAT_007263a0;
extern void* PTR_FUN_0070d0a8;
extern void* PTR_FUN_0070d024;
extern void* PTR_FUN_0070d138;
extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006fd14c;
extern void* PTR_FUN_0070d0a8_vtable;

extern void FUN_004f3350(void);
extern void FUN_005071f0(void);
extern void FUN_00504070(int param_1);
extern void FUN_00503fb0(int param_1);
extern void FUN_00534130(void);
extern void FUN_00534350(void);
extern void FUN_00533d10(int param_1, int param_2);
extern std::uint32_t FUN_004f8e40(void* param_1);
extern void FUN_00506550(void* param_1);
extern void* FUN_00533c78(std::size_t param_1);
extern void* thunk_FUN_00533c78(std::size_t param_1);
extern void* FUN_004c3150(void);
extern void* FUN_004c2410(std::uint32_t param_1, int param_2);
extern void* FUN_004c3100(void);
extern void FUN_004ba750(void* param_1);
extern void FUN_004b9840(void);
extern void FUN_004b9a90(void);
extern int FUN_004ba8e0(void* param_1);
extern std::uint32_t FUN_004b97c0(std::uint32_t param_1, std::uint8_t param_2);
extern void FUN_004ba350(int param_1);
extern void FUN_004ba580(int param_1, float param_2);
extern void FUN_00568680(int param_1, int param_2);
extern void FUN_004b9c20(void);
extern void FUN_00488880(void);
extern void FUN_004ed8f0(char* param_1);
extern void FUN_004f4ed0(void);
extern void FUN_004c2510(void);
extern void FUN_004bdca0(std::uint32_t p1, std::uint32_t p2, std::uint32_t p3, std::uint32_t p4, std::uint32_t p5, std::uint32_t p6, std::uint32_t p7, std::uint32_t p8, std::uint32_t p9, std::uint32_t p10);
extern void FUN_00581300(std::uint32_t param_1, void* param_2);
extern void* FUN_004c26f0(void);
extern std::uint32_t FUN_005f0ddc(std::uint32_t a, std::uint32_t b, std::uint32_t c);
extern std::uint32_t FUN_004ab290(std::uint32_t a, void* b, int c, int d, int e, int f, int g, int h, int i, std::uint32_t j, std::uint32_t k, std::uint32_t l);
extern std::uint32_t FUN_004ab380(std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t d, std::uint32_t e, std::uint32_t f, std::uint32_t g, std::uint32_t h, std::uint32_t i, std::uint32_t j);
extern void* FUN_00449390(void* a, int b);
extern void FUN_0053d510(void* a, void* b, void* c);
extern void FUN_005516a0(void);
extern void FUN_005007e0(void);
extern void* FUN_00538680(void);
extern void FUN_004127b0(void* a, std::size_t b, std::uint32_t c, void* d);

// 0x4b9650 — observed shape
void FUN_004b9650(void* self) {
    char* base = static_cast<char*>(self);
    std::uint32_t local_4 = 0;
    if (*reinterpret_cast<int*>(base + 0xc) != 0) {
        std::size_t _Size = DAT_008caccc;
        do {
            int* piVar1 = reinterpret_cast<int*>(*reinterpret_cast<int*>(base + 4) + local_4 * 4);
            if ((-1 < static_cast<int>(_Size)) && (reinterpret_cast<unsigned char*>(*piVar1) != &DAT_008cacd0[0])) {
                if (_Size == 0) {
                    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(*piVar1) - 4) == 0) goto LAB_004b96bc;
                    *reinterpret_cast<unsigned char*>(*piVar1) = 0;
                    *reinterpret_cast<std::uint32_t*>(*piVar1 - 4) = 0;
                } else {
                    FUN_004f3350();
                    std::memmove(reinterpret_cast<void*>(*piVar1), &DAT_008cacd0[0], _Size);
                    *reinterpret_cast<unsigned char*>(*piVar1 + *reinterpret_cast<int*>(*piVar1 - 4)) = 0;
                }
                _Size = DAT_008caccc;
            }
LAB_004b96bc:
            local_4 = local_4 + 1;
        } while (local_4 < *reinterpret_cast<std::uint32_t*>(base + 0xc));
    }
    *reinterpret_cast<std::uint32_t*>(base + 0xc) = 0;
    *reinterpret_cast<std::uint32_t*>(base + 0x10) = 0;
}

// 0x4b96e0 — observed shape
void FUN_004b96e0(void* self, std::uint8_t param_1) {
    *static_cast<void**>(self) = PTR_FUN_007116a0;
    FUN_005071f0();
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x4b9720 — observed shape
void FUN_004b9720(void* self, int param_1) {
    char* base = static_cast<char*>(self);
    int* in_ECX = static_cast<int*>(self);
    if ((*reinterpret_cast<int*>(param_1 + 0x24) != 0) && (*reinterpret_cast<int*>(param_1 + 0xfc) != 0)) {
        FUN_00504070(param_1);
    }
    if (in_ECX[0x3f] != 0) {
        FUN_00503fb0(param_1);
    }
    void** vtable = *reinterpret_cast<void***>(self);
    auto fn = reinterpret_cast<void(*)(int, int)>(vtable[0x70 / 4]);
    fn(param_1, 1);
    FUN_00534130();
    FUN_00534350();
    FUN_00533d10(0, 1);
}

// 0x4b97c0 — observed shape
std::uint32_t FUN_004b97c0(void* self, std::uint32_t param_1, std::uint8_t param_2) {
    // param_1 is unused in the listing except as a stack slot; in_EAX is self.
    (void)param_1;
    if ((DAT_008cacf0 == 0) || ((self != nullptr && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
        return 0;
    }
    std::uint32_t uVar1 = FUN_004f8e40(&param_2);
    return uVar1;
}

// 0x4b9800 — observed shape
std::uint32_t* FUN_004b9800(void) {
    std::uint32_t* local_4 = nullptr;
    FUN_00506550(&local_4);
    std::uint32_t* puVar2 = local_4;
    if (local_4 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(local_4 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            void** vtable = *reinterpret_cast<void***>(local_4);
            auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
            fn(1);
        }
    }
    return puVar2;
}
// 0x4b9840 — observed shape
void FUN_004b9840(void* self) {
    char* base = static_cast<char*>(self);
    int in_EAX = reinterpret_cast<int>(self);
    std::uint32_t local_218 = 0;
    if (in_EAX != 0) {
        std::uint32_t local_210 = *reinterpret_cast<std::uint32_t*>(in_EAX + 0x10);
        int local_214 = *reinterpret_cast<int*>(in_EAX + 0x14);
        if (local_210 != 0) {
            do {
                unsigned char* pbVar9 = *reinterpret_cast<unsigned char**>(local_214 + 4 + local_218 * 8);
                float local_20c = *reinterpret_cast<float*>(local_214 + local_218 * 8);
                if (pbVar9 != nullptr) {
                    std::uint8_t bVar3 = *pbVar9;
                    while (bVar3 != 0) {
                        while (true) {
                            bVar3 = *pbVar9;
                            if (((static_cast<signed char>(bVar3) < -0x80) || (0xff < static_cast<signed char>(bVar3))) || (std::isspace(bVar3) == 0)) break;
                            pbVar9 = pbVar9 + 1;
                        }
                        bVar3 = *pbVar9;
                        if (bVar3 == 0) break;
                        std::uint8_t local_208[260] = {0};
                        std::uint8_t* pbVar8 = local_208;
                        do {
                            if ((bVar3 == 10) || (bVar3 == 0xd)) break;
                            *pbVar8 = bVar3;
                            bVar3 = pbVar9[1];
                            pbVar8 = pbVar8 + 1;
                            pbVar9 = pbVar9 + 1;
                        } while (bVar3 != 0);
                        *pbVar8 = 0;
                        int iVar5 = std::strnicmp(reinterpret_cast<char*>(local_208), "PlayEffect,", 0xb);
                        if (iVar5 == 0) {
                            char local_1fd[260] = {0};
                            std::strncpy(local_1fd, reinterpret_cast<char*>(local_208 + 0xb), sizeof(local_1fd) - 1);
                            char* pcVar6 = std::strchr(local_1fd, 0x2c);
                            if (pcVar6 != nullptr) *pcVar6 = '\0';
                            std::strlwr(local_1fd);
                            std::uint32_t* local_21c = nullptr;
                            char cVar4 = static_cast<char>(FUN_004b9800() != nullptr ? 1 : 0);
                            FUN_00506550(&local_21c);
                            if (cVar4 == 0) {
                                char local_108[260] = {0};
                                std::sprintf(local_108, "%s.NIF", local_1fd);
                                cVar4 = 0;
                                FUN_004f4ed0();
                                if (cVar4 == 0) {
                                    std::uint32_t* puVar10 = local_21c;
                                    (void)puVar10;
                                } else {
                                    std::uint32_t* puVar7 = static_cast<std::uint32_t*>(FUN_00533c78(0xc0));
                                    std::uint32_t uVar2 = DAT_008ea000;
                                    if (puVar7 == nullptr) {
                                        puVar7 = nullptr;
                                    } else {
                                        puVar7[1] = 0;
                                        *puVar7 = reinterpret_cast<std::uint32_t>(PTR_FUN_006fd14c);
                                        puVar7[7] = 0;
                                        puVar7[0x19] = 0;
                                        DAT_00727444 = DAT_00727444 + 1;
                                        puVar7[0x2f] = 0;
                                        FUN_004bdca0(uVar2, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                                    }
                                    std::uint32_t* puVar10 = local_21c;
                                    if (local_21c != puVar7) {
                                        if (local_21c != nullptr) {
                                            int* piVar1 = reinterpret_cast<int*>(local_21c + 1);
                                            *piVar1 = *piVar1 + -1;
                                            if (*piVar1 == 0) {
                                                void** vtable = *reinterpret_cast<void***>(local_21c);
                                                auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                                                fn(1);
                                            }
                                        }
                                        puVar10 = puVar7;
                                        if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
                                    }
                                    if (puVar10 != nullptr) puVar10[1] = puVar10[1] + 1;
                                    FUN_004c2510();
                                    FUN_004b97c0("%s.NIF", static_cast<std::uint8_t>(0));
                                    (void)local_108;
                                }
                            } else {
                                local_21c[1] = local_21c[1] + 1;
                                std::uint32_t* puVar10 = local_21c;
                                (void)puVar10;
                            }
                            std::uint32_t* puVar10 = nullptr;
                            if (puVar10 != nullptr) {
                                int* piVar1 = reinterpret_cast<int*>(puVar10 + 1);
                                *piVar1 = *piVar1 + -1;
                                if (*piVar1 == 0) {
                                    void** vtable = *reinterpret_cast<void***>(puVar10);
                                    auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                                    fn(1);
                                }
                            }
                        }
                        bVar3 = *pbVar9;
                    }
                }
                local_218 = local_218 + 1;
            } while (local_218 < local_210);
        }
    }
    (void)base;
}
// 0x4b9a90 — observed shape
void FUN_004b9a90(void* self) {
    int in_EAX = reinterpret_cast<int>(self);
    if (in_EAX != 0) {
        std::uint32_t local_110 = *reinterpret_cast<std::uint32_t*>(in_EAX + 0x10);
        int local_114 = *reinterpret_cast<int*>(in_EAX + 0x14);
        std::uint32_t local_118 = 0;
        if (local_110 != 0) {
            do {
                unsigned char* pbVar8 = *reinterpret_cast<unsigned char**>(local_114 + 4 + local_118 * 8);
                float local_10c = *reinterpret_cast<float*>(local_114 + local_118 * 8);
                if (pbVar8 != nullptr) {
                    std::uint8_t bVar3 = *pbVar8;
                    while (bVar3 != 0) {
                        while (true) {
                            bVar3 = *pbVar8;
                            if (((static_cast<signed char>(bVar3) < -0x80) || (0xff < static_cast<signed char>(bVar3))) || (std::isspace(bVar3) == 0)) break;
                            pbVar8 = pbVar8 + 1;
                        }
                        bVar3 = *pbVar8;
                        if (bVar3 == 0) break;
                        std::uint8_t local_108[260] = {0};
                        std::uint8_t* pbVar7 = local_108;
                        do {
                            if ((bVar3 == 10) || (bVar3 == 0xd)) break;
                            *pbVar7 = bVar3;
                            bVar3 = pbVar8[1];
                            pbVar7 = pbVar7 + 1;
                            pbVar8 = pbVar8 + 1;
                        } while (bVar3 != 0);
                        *pbVar7 = 0;
                        int iVar5 = std::strnicmp(reinterpret_cast<char*>(local_108), "PlayEffect,", 0xb);
                        if (iVar5 == 0) {
                            char local_fd[260] = {0};
                            std::strncpy(local_fd, reinterpret_cast<char*>(local_108 + 0xb), sizeof(local_fd) - 1);
                            char* pcVar6 = std::strchr(local_fd, 0x2c);
                            if (pcVar6 != nullptr) *pcVar6 = '\0';
                            std::strlwr(local_fd);
                            std::uint32_t* local_11c = nullptr;
                            FUN_00506550(&local_11c);
                            std::uint32_t* puVar2 = local_11c;
                            if (local_11c != nullptr && local_11c[1] == 2) {
                                FUN_004ed8f0(local_fd);
                                FUN_004b97c0("Removing fx", static_cast<std::uint8_t>(0));
                                (void)local_10c;
                            } else if (local_11c != nullptr) {
                                int* piVar1 = reinterpret_cast<int*>(local_11c + 1);
                                *piVar1 = *piVar1 + -1;
                                if (*piVar1 == 0) {
                                    void** vtable = *reinterpret_cast<void***>(local_11c);
                                    auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                                    fn(1);
                                }
                            }
                            if (puVar2 != nullptr) {
                                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                                *piVar1 = *piVar1 + -1;
                                if (*piVar1 == 0) {
                                    void** vtable = *reinterpret_cast<void***>(puVar2);
                                    auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                                    fn(1);
                                }
                            }
                        }
                        bVar3 = *pbVar8;
                    }
                }
                local_118 = local_118 + 1;
            } while (local_118 < local_110);
        }
    }
}

// 0x4b9c20 — observed shape
void FUN_004b9c20(void* self, int* param_1) {
    unsigned char* in_EAX = static_cast<unsigned char*>(self);
    unsigned char* pbVar3 = reinterpret_cast<unsigned char*>(std::strchr(reinterpret_cast<char*>(in_EAX), 0x2c));
    if (pbVar3 != nullptr) {
        std::strlwr(reinterpret_cast<char*>(in_EAX));
        *pbVar3 = 0;
        while (true) {
            std::uint8_t bVar1 = *in_EAX;
            if (((static_cast<signed char>(bVar1) < -0x80) || (0xff < static_cast<signed char>(bVar1))) || (std::isspace(bVar1) == 0)) break;
            in_EAX = in_EAX + 1;
        }
        unsigned char* local_18 = in_EAX;
        unsigned char* pbVar13 = pbVar3;
        unsigned char* pbVar3temp = pbVar3;
        do {
            pbVar13 = pbVar3temp;
            pbVar3temp = pbVar13 + 1;
            std::uint8_t bVar1 = *pbVar3temp;
            if (((static_cast<signed char>(bVar1) < -0x80) || (0xff < static_cast<signed char>(bVar1))) || (std::isspace(bVar1) == 0)) break;
        } while (true);
        unsigned char* pbVar5 = in_EAX;
        unsigned char* pbVar12 = pbVar5;
        do {
            pbVar12 = pbVar5;
            pbVar5 = pbVar12 + 1;
        } while (*pbVar12 != 0);
        while (true) {
            std::uint8_t bVar1 = pbVar12[-1];
            pbVar12 = pbVar12 + -1;
            if (((static_cast<signed char>(bVar1) < -0x80) || (0xff < static_cast<signed char>(bVar1))) || (std::isspace(bVar1) == 0)) break;
            *pbVar12 = 0;
        }
        if (in_EAX < pbVar12) {
            pbVar5 = pbVar3temp;
            do {
                std::uint8_t bVar1 = *pbVar5;
                pbVar5 = pbVar5 + 1;
                if (bVar1 == 0) break;
            } while (true);
            unsigned char* pbVar13b = pbVar3temp + (reinterpret_cast<int>(pbVar5) - reinterpret_cast<int>(pbVar13 + 2));
            while (true) {
                std::uint8_t bVar1 = pbVar13b[-1];
                pbVar13b = pbVar13b + -1;
                if (((static_cast<signed char>(bVar1) < -0x80) || (0xff < static_cast<signed char>(bVar1))) || (std::isspace(bVar1) == 0)) break;
                *pbVar13b = 0;
            }
            if ((pbVar3temp < pbVar13b) && (std::stricmp(reinterpret_cast<char*>(in_EAX), "fx_sword_hit_thrust") != 0) && (std::stricmp(reinterpret_cast<char*>(in_EAX), "fx_sword_hit_slash") != 0)) {
                std::uint32_t iVar4 = reinterpret_cast<std::uint32_t>(FUN_004b9800());
                if (iVar4 != 0 && *reinterpret_cast<int*>(iVar4 + 0x50) == 0) {
                    void** vtable = *reinterpret_cast<void***>(param_1);
                    auto fn = reinterpret_cast<int(*)(unsigned char*)>(vtable[0x40 / 4]);
                    int iVar6 = fn(pbVar3temp);
                    if (iVar6 != 0) {
                        unsigned char* pbVar3b = static_cast<unsigned char*>(FUN_00449390(nullptr, iVar6));
                        if (pbVar3b != nullptr) {
                            bool bVar2 = false;
                            local_18 = pbVar3b;
                            (void)bVar2;
                        }
                    }
                }
            }
        }
    }
}

// 0x4b9f20 — observed shape
void FUN_004b9f20(void* self, int param_1, std::uint32_t param_2) {
    std::uint32_t* unaff_ESI = static_cast<std::uint32_t*>(self);
    std::uint32_t local_4 = *reinterpret_cast<std::uint32_t*>(param_1 + 0x38);
    DAT_00727444 = DAT_00727444 + 1;
    std::uint32_t uVar2 = local_4;
    int iVar5 = reinterpret_cast<int>(FUN_00533c78(0xc));
    std::uint32_t* puVar6 = nullptr;
    if (iVar5 != 0) puVar6 = static_cast<std::uint32_t*>(FUN_004c3150());
    unaff_ESI[1] = 0;
    *unaff_ESI = reinterpret_cast<std::uint32_t>(PTR_FUN_0070d0a8);
    unaff_ESI[2] = 0;
    unaff_ESI[0xb] = 0;
    std::uint32_t* puVar3 = reinterpret_cast<std::uint32_t*>(unaff_ESI[2]);
    if (puVar3 != puVar6) {
        if (puVar3 != nullptr) {
            int* piVar11 = reinterpret_cast<int*>(puVar3 + 1);
            *piVar11 = *piVar11 + -1;
            if (*piVar11 == 0) {
                void** vtable = *reinterpret_cast<void***>(puVar3);
                auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                fn(1);
            }
        }
        unaff_ESI[2] = reinterpret_cast<std::uint32_t>(puVar6);
        if (puVar6 != nullptr) puVar6[1] = puVar6[1] + 1;
    }
    unaff_ESI[4] = 0xbf800000;
    unaff_ESI[8] = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(unaff_ESI) + 20) = 0;
    unaff_ESI[6] = param_2;
    unaff_ESI[3] = reinterpret_cast<std::uint32_t>(FUN_004c3100());
    std::uint32_t* puVar6b = *reinterpret_cast<std::uint32_t**>(param_1 + 0x10);
    std::uint32_t* puVar3b = reinterpret_cast<std::uint32_t*>(unaff_ESI[0xb]);
    if (puVar3b != puVar6b) {
        if (puVar3b != nullptr) {
            int* piVar11 = reinterpret_cast<int*>(puVar3b + 1);
            *piVar11 = *piVar11 + -1;
            if (*piVar11 == 0) {
                void** vtable = *reinterpret_cast<void***>(puVar3b);
                auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                fn(1);
            }
        }
        unaff_ESI[0xb] = reinterpret_cast<std::uint32_t>(puVar6b);
        if (puVar6b != nullptr) puVar6b[1] = puVar6b[1] + 1;
    }
    FUN_004ba750(self);
    std::uint32_t* obj = static_cast<std::uint32_t*>(FUN_00533c78(0x18));
    if (obj != nullptr) {
        *obj = reinterpret_cast<std::uint32_t>(PTR_FUN_0070d138);
        obj[2] = uVar2;
        obj[5] = 1;
        obj[3] = 0;
        obj[4] = 0;
        if (uVar2 == 0) obj[1] = 0;
        else {
            std::uint32_t* puVar7 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(uVar2 * 4 + 4));
            if (puVar7 != nullptr) {
                std::uint32_t* puVar10 = puVar7 + 1;
                *puVar7 = uVar2;
                FUN_004127b0(puVar10, 4, uVar2, nullptr);
            }
            obj[1] = reinterpret_cast<std::uint32_t>(puVar7 ? puVar7 + 1 : nullptr);
        }
    }
    unaff_ESI[9] = reinterpret_cast<std::uint32_t>(obj);
    int alloc2 = reinterpret_cast<int>(FUN_00533c78(0x18));
    std::uint32_t uVar8 = 0;
    if (alloc2 != 0) uVar8 = reinterpret_cast<std::uint32_t>(FUN_004c2410(uVar2, 1));
    unaff_ESI[10] = uVar8;
    param_2 = 0;
    if (uVar2 != 0) {
        do {
            int* piVar11 = nullptr;
            if (param_2 < *reinterpret_cast<std::uint32_t*>(param_1 + 0x38)) {
                piVar11 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(param_1 + 0x30) + param_2 * 4);
            }
            int alloc3 = reinterpret_cast<int>(FUN_00533c78(0xc));
            int* piVar9 = nullptr;
            if (alloc3 != 0) piVar9 = static_cast<int*>(FUN_004c3150());
            if (piVar11 != nullptr) piVar11[1] = piVar11[1] + 1;
            int* piStack_8 = piVar11;
            FUN_00581300(param_2, &piStack_8);
            if (piVar11 != nullptr) {
                int* piVar1 = piVar11 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    void** vtable = *reinterpret_cast<void***>(piVar11);
                    auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                    fn(1);
                }
            }
            if (piVar9 != nullptr) piVar9[1] = piVar9[1] + 1;
            piStack_8 = piVar9;
            FUN_004c26f0();
            if (piVar9 != nullptr) {
                int* piVar1 = piVar9 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    void** vtable = *reinterpret_cast<void***>(piVar9);
                    auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                    fn(1);
                }
            }
            if (piVar11 != nullptr) {
                unaff_ESI[7] = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(piVar11) + 12) >> 1) & 3;
            }
            param_2 = param_2 + 1;
        } while (param_2 < local_4);
    }
    FUN_004b9840(self);
}

// 0x4ba190 — observed shape
void FUN_004ba190(void* self, std::uint32_t* param_1) {
    std::uint32_t* unaff_ESI = static_cast<std::uint32_t*>(self);
    std::uint32_t uVar5 = 0;
    unaff_ESI[1] = 0;
    *unaff_ESI = reinterpret_cast<std::uint32_t>(PTR_FUN_0070d0a8);
    DAT_00727444 = DAT_00727444 + 1;
    unaff_ESI[2] = 0;
    unaff_ESI[0xb] = 0;
    std::uint32_t* puVar4 = reinterpret_cast<std::uint32_t*>(unaff_ESI[2]);
    int unaff_EBX = reinterpret_cast<int>(self);
    if (puVar4 != *reinterpret_cast<std::uint32_t**>(unaff_EBX + 8)) {
        if (puVar4 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                void** vtable = *reinterpret_cast<void***>(puVar4);
                auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                fn(1);
            }
        }
        int iVar2 = *reinterpret_cast<int*>(unaff_EBX + 8);
        unaff_ESI[2] = iVar2;
        if (iVar2 != 0) *reinterpret_cast<int*>(iVar2 + 4) = *reinterpret_cast<int*>(iVar2 + 4) + 1;
    }
    unaff_ESI[4] = 0xbf800000;
    unaff_ESI[8] = 0;
    unaff_ESI[6] = reinterpret_cast<std::uint32_t>(param_1);
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(unaff_ESI) + 20) = *reinterpret_cast<unsigned char*>(unaff_EBX + 0x14);
    unaff_ESI[3] = *reinterpret_cast<std::uint32_t*>(unaff_EBX + 0xc);
    std::uint32_t* puVar4b = reinterpret_cast<std::uint32_t*>(unaff_ESI[0xb]);
    if (puVar4b != *reinterpret_cast<std::uint32_t**>(unaff_EBX + 0x2c)) {
        if (puVar4b != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar4b + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                void** vtable = *reinterpret_cast<void***>(puVar4b);
                auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                fn(1);
            }
        }
        int iVar2 = *reinterpret_cast<int*>(unaff_EBX + 0x2c);
        unaff_ESI[0xb] = iVar2;
        if (iVar2 != 0) *reinterpret_cast<int*>(iVar2 + 4) = *reinterpret_cast<int*>(iVar2 + 4) + 1;
    }
    unaff_ESI[9] = *reinterpret_cast<std::uint32_t*>(unaff_EBX + 0x24);
    unaff_ESI[10] = *reinterpret_cast<std::uint32_t*>(unaff_EBX + 0x28);
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(unaff_ESI) + 20) != 0) {
        int iVar2 = reinterpret_cast<int>(FUN_00533c78(0x18));
        std::uint32_t uVar3 = 0;
        if (iVar2 != 0) uVar3 = reinterpret_cast<std::uint32_t>(FUN_004c2410(*reinterpret_cast<std::uint32_t*>(*reinterpret_cast<int*>(unaff_EBX + 0x28) + 0xc), 1));
        unaff_ESI[10] = uVar3;
        if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(unaff_EBX + 0x28) + 0xc) != 0) {
            do {
                std::uint32_t* puVar4c = static_cast<std::uint32_t*>(FUN_00538680());
                if (puVar4c != nullptr) puVar4c[1] = puVar4c[1] + 1;
                std::uint32_t* param_1c = puVar4c;
                FUN_00581300(uVar5, &param_1c);
                if (puVar4c != nullptr) {
                    int* piVar1 = reinterpret_cast<int*>(puVar4c + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        void** vtable = *reinterpret_cast<void***>(puVar4c);
                        auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
                        fn(1);
                    }
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<int*>(unaff_EBX + 0x28) + 0xc));
        }
    }
    FUN_004b9840(self);
}
// 0x4ba2c0 — observed shape
void FUN_004ba2c0(void* self) {
    std::uint32_t* unaff_ESI = static_cast<std::uint32_t*>(self);
    *unaff_ESI = reinterpret_cast<std::uint32_t>(PTR_FUN_0070d0a8);
    FUN_004b9a90(self);
    std::uint32_t* ref = reinterpret_cast<std::uint32_t*>(unaff_ESI[2]);
    if (ref != nullptr && *reinterpret_cast<int*>(reinterpret_cast<char*>(ref) + 4) == 1) {
        if (reinterpret_cast<std::uint32_t*>(unaff_ESI[9]) != nullptr) {
            void* obj = reinterpret_cast<void*>(unaff_ESI[9]);
            void** vtable = *reinterpret_cast<void***>(obj);
            auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
            fn(1);
        }
        if (reinterpret_cast<std::uint32_t*>(unaff_ESI[10]) != nullptr) {
            void* obj = reinterpret_cast<void*>(unaff_ESI[10]);
            void** vtable = *reinterpret_cast<void***>(obj);
            auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
            fn(1);
        }
    } else if (*reinterpret_cast<char*>(reinterpret_cast<char*>(unaff_ESI) + 20) != 0 && reinterpret_cast<std::uint32_t*>(unaff_ESI[10]) != nullptr) {
        void* obj = reinterpret_cast<void*>(unaff_ESI[10]);
        void** vtable = *reinterpret_cast<void***>(obj);
        auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
        fn(1);
    }
    if (reinterpret_cast<std::uint32_t*>(unaff_ESI[8]) != nullptr) {
        void* obj = reinterpret_cast<void*>(unaff_ESI[8]);
        void** vtable = *reinterpret_cast<void***>(obj);
        auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
        fn(1);
    }
    std::uint32_t* puVar2 = reinterpret_cast<std::uint32_t*>(unaff_ESI[0xb]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            void** vtable = *reinterpret_cast<void***>(puVar2);
            auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
            fn(1);
        }
    }
    puVar2 = reinterpret_cast<std::uint32_t*>(unaff_ESI[2]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            void** vtable = *reinterpret_cast<void***>(puVar2);
            auto fn = reinterpret_cast<void(*)(int)>(vtable[0]);
            fn(1);
        }
    }
    *unaff_ESI = reinterpret_cast<std::uint32_t>(PTR_LAB_006fd148);
    DAT_00727444 = DAT_00727444 + -1;
}

// 0x4ba350 — observed shape
void FUN_004ba350(int param_1) {
    std::uint32_t uVar1 = *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<int*>(param_1 + 0x24) + 0xc);
    std::uint32_t* puVar3 = static_cast<std::uint32_t*>(FUN_00533c78(0x18));
    if (puVar3 != nullptr) {
        *puVar3 = reinterpret_cast<std::uint32_t>(PTR_FUN_0070d024);
        puVar3[2] = uVar1;
        puVar3[5] = 1;
        puVar3[3] = 0;
        puVar3[4] = 0;
        if (uVar1 == 0) puVar3[1] = 0;
        else puVar3[1] = reinterpret_cast<std::uint32_t>(thunk_FUN_00533c78(uVar1 * 4));
    }
    *reinterpret_cast<std::uint32_t**>(param_1 + 0x20) = puVar3;
    std::uint32_t uVar7 = 0;
    if (uVar1 != 0) {
        do {
            std::uint32_t uVar4 = *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x24) + 4) + uVar7 * 4) + 8);
            int iVar5 = FUN_004ba8e0(reinterpret_cast<void*>(*reinterpret_cast<int*>(param_1 + 0x18)));
            if (iVar5 == 0) FUN_004b97c0("%s not found in %s", static_cast<std::uint8_t>(0));
            int iVar2 = *reinterpret_cast<int*>(param_1 + 0x20);
            if (iVar2 != 0 && uVar7 < *reinterpret_cast<std::uint32_t*>(iVar2 + 8)) {
                if (uVar7 < *reinterpret_cast<std::uint32_t*>(iVar2 + 0xc)) {
                    if (iVar5 == 0) {
                        if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + uVar7 * 4) != 0) {
                            *reinterpret_cast<int*>(iVar2 + 0x10) = *reinterpret_cast<int*>(iVar2 + 0x10) + -1;
                        }
                    } else if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + uVar7 * 4) == 0) {
                        *reinterpret_cast<int*>(iVar2 + 0x10) = *reinterpret_cast<int*>(iVar2 + 0x10) + 1;
                    }
                } else {
                    *reinterpret_cast<std::uint32_t*>(iVar2 + 0xc) = uVar7 + 1;
                    if (iVar5 != 0) *reinterpret_cast<int*>(iVar2 + 0x10) = *reinterpret_cast<int*>(iVar2 + 0x10) + 1;
                }
                *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + uVar7 * 4) = iVar5;
            }
            uVar7 = uVar7 + 1;
        } while (uVar7 < uVar1);
    }
}

// 0x4ba450 — observed shape
void FUN_004ba450(void* self, std::uint32_t param_1) {
    char* base = static_cast<char*>(self);
    if (*reinterpret_cast<int*>(base + 0x20) == 0) FUN_004ba350(reinterpret_cast<int>(base));
    int iVar2 = *reinterpret_cast<int*>(base + 0x28);
    std::uint32_t uVar4 = 0;
    if (*reinterpret_cast<int*>(iVar2 + 0xc) != 0) {
        do {
            int* piVar1 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(iVar2 + 4) + uVar4 * 4);
            iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(base + 0x20) + 4) + uVar4 * 4);
            if (piVar1 != nullptr && iVar2 != 0) {
                void** vtable = *reinterpret_cast<void***>(piVar1);
                auto getFn = reinterpret_cast<void*(*)()>(vtable[1]);
                std::uint32_t* puVar3 = static_cast<std::uint32_t*>(getFn());
                if (puVar3 == reinterpret_cast<std::uint32_t*>(&DAT_00728374[0])) FUN_00568680(0, 0);
                auto callFn = reinterpret_cast<void(*)(int)>(vtable[0x40 / 4]);
                callFn(iVar2);
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(piVar1) + 0x40) = 1;
                auto callFn3c = reinterpret_cast<void(*)(std::uint32_t)>(vtable[0x3c / 4]);
                callFn3c(0);
                callFn(iVar2);
            }
            iVar2 = *reinterpret_cast<int*>(base + 0x28);
            uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<std::uint32_t*>(iVar2 + 0xc));
    }
    (void)param_1;
}

// 0x4ba4f0 — observed shape
void FUN_004ba4f0(int param_1, std::uint32_t param_2) {
    if (*reinterpret_cast<int*>(param_1 + 0x20) == 0) FUN_004ba350(param_1);
    int iVar2 = *reinterpret_cast<int*>(param_1 + 0x28);
    std::uint32_t uVar4 = 0;
    if (*reinterpret_cast<int*>(iVar2 + 0xc) != 0) {
        do {
            int* piVar1 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(iVar2 + 4) + uVar4 * 4);
            iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x20) + 4) + uVar4 * 4);
            if (piVar1 != nullptr && iVar2 != 0) {
                void** vtable = *reinterpret_cast<void***>(piVar1);
                auto getFn = reinterpret_cast<void*(*)()>(vtable[1]);
                std::uint32_t* puVar3 = static_cast<std::uint32_t*>(getFn());
                if (puVar3 == reinterpret_cast<std::uint32_t*>(&DAT_00728374[0])) FUN_00568680(0, 0);
                auto callFn = reinterpret_cast<void(*)(int)>(vtable[0x40 / 4]);
                callFn(iVar2);
                auto callFn60 = reinterpret_cast<void(*)(int, std::uint32_t, int)>(vtable[0x60 / 4]);
                callFn60(param_1, param_2, 1);
                callFn(0);
            }
            iVar2 = *reinterpret_cast<int*>(param_1 + 0x28);
            uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<std::uint32_t*>(iVar2 + 0xc));
    }
}

// 0x4ba580 — observed shape
void FUN_004ba580(int param_1, float param_2) {
    int iVar2 = *reinterpret_cast<int*>(param_1 + 0x2c);
    if (iVar2 != 0) {
        if (param_2 < *reinterpret_cast<float*>(param_1 + 0x10)) {
            *reinterpret_cast<std::uint32_t*>(param_1 + 0x10) = 0xbf800000;
        }
        std::uint32_t uVar3 = *reinterpret_cast<std::uint32_t*>(iVar2 + 0x10);
        iVar2 = *reinterpret_cast<int*>(iVar2 + 0x14);
        std::uint32_t local_114 = 0;
        if (uVar3 != 0) {
            do {
                unsigned char* pbVar7 = *reinterpret_cast<unsigned char**>(iVar2 + 4 + local_114 * 8);
                float fVar1 = *reinterpret_cast<float*>(iVar2 + local_114 * 8);
                if (pbVar7 != nullptr && *reinterpret_cast<float*>(param_1 + 0x10) < fVar1 && fVar1 < param_2) {
                    std::uint8_t bVar4 = *pbVar7;
                    while (bVar4 != 0) {
                        while (true) {
                            bVar4 = *pbVar7;
                            if (((static_cast<signed char>(bVar4) < -0x80) || (0xff < static_cast<signed char>(bVar4))) || (std::isspace(bVar4) == 0)) break;
                            pbVar7 = pbVar7 + 1;
                        }
                        bVar4 = *pbVar7;
                        if (bVar4 == 0) break;
                        std::uint8_t local_108[260] = {0};
                        std::uint8_t* pbVar6 = local_108;
                        do {
                            if ((bVar4 == 10) || (bVar4 == 0xd)) break;
                            *pbVar6 = bVar4;
                            bVar4 = pbVar7[1];
                            pbVar6 = pbVar6 + 1;
                            pbVar7 = pbVar7 + 1;
                        } while (bVar4 != 0);
                        *pbVar6 = 0;
                        int iVar5 = std::stricmp(reinterpret_cast<char*>(local_108), "Start");
                        if (iVar5 != 0) {
                            iVar5 = std::strnicmp(reinterpret_cast<char*>(local_108), "PlaySound,", 10);
                            if (iVar5 == 0) FUN_00488880();
                            else {
                                iVar5 = std::strnicmp(reinterpret_cast<char*>(local_108), "PlayEffect,", 0xb);
                                if (iVar5 == 0) FUN_004b9c20(nullptr, nullptr);
                                else std::stricmp(reinterpret_cast<char*>(local_108), "End");
                            }
                        }
                        FUN_004b97c0("%s: %s", static_cast<std::uint8_t>(0));
                        bVar4 = *pbVar7;
                    }
                }
                local_114 = local_114 + 1;
            } while (local_114 < uVar3);
        }
        *reinterpret_cast<float*>(param_1 + 0x10) = param_2;
    }
}
// 0x4ba750 — observed shape
void FUN_004ba750(int param_1) {
    int iVar1 = *reinterpret_cast<int*>(param_1 + 0x2c);
    if (iVar1 != 0) {
        std::uint32_t uVar2 = *reinterpret_cast<std::uint32_t*>(iVar1 + 0x10);
        std::uint32_t uVar3 = 0;
        iVar1 = *reinterpret_cast<int*>(iVar1 + 0x14);
        if (uVar2 != 0) {
            do {
                if (uVar3 == 0) FUN_004b97c0("%s", static_cast<std::uint8_t>(0));
                FUN_004b97c0("%6.3f", static_cast<std::uint8_t>(0));
                uVar3 = uVar3 + 1;
            } while (uVar3 < uVar2);
        }
    }
}

// 0x4ba7c0 — observed shape
float FUN_004ba7c0(void* self, char* unaff_EDI) {
    int in_EAX = reinterpret_cast<int>(self);
    if (unaff_EDI == nullptr) {
        return *reinterpret_cast<float*>(in_EAX + 0xc);
    }
    int iVar3 = *reinterpret_cast<int*>(in_EAX + 0x2c);
    if (iVar3 == 0) return 0.0f;
    std::uint32_t uVar4 = *reinterpret_cast<std::uint32_t*>(iVar3 + 0x10);
    iVar3 = *reinterpret_cast<int*>(iVar3 + 0x14);
    std::uint32_t uVar9 = 0;
    if (uVar4 != 0) {
        do {
            float fVar1 = *reinterpret_cast<float*>(iVar3 + uVar9 * 8);
            unsigned char* pbVar10 = *reinterpret_cast<unsigned char**>(iVar3 + 4 + uVar9 * 8);
            std::uint8_t bVar5 = *pbVar10;
            while (bVar5 != 0) {
                while (true) {
                    bVar5 = *pbVar10;
                    if (((static_cast<signed char>(bVar5) < -0x80) || (0xff < static_cast<signed char>(bVar5))) || (std::isspace(bVar5) == 0)) break;
                    pbVar10 = pbVar10 + 1;
                }
                bVar5 = *pbVar10;
                if (bVar5 == 0) break;
                std::uint8_t local_100[256] = {0};
                std::uint8_t* pbVar8 = local_100;
                do {
                    if ((bVar5 == 10) || (bVar5 == 0xd)) break;
                    *pbVar8 = bVar5;
                    bVar5 = pbVar10[1];
                    pbVar8 = pbVar8 + 1;
                    pbVar10 = pbVar10 + 1;
                } while (bVar5 != 0);
                *pbVar8 = 0;
                std::size_t len = std::strlen(unaff_EDI);
                int iVar6 = std::strnicmp(reinterpret_cast<char*>(local_100), unaff_EDI, static_cast<int>(len));
                if (iVar6 == 0) return fVar1;
                bVar5 = *pbVar10;
            }
            uVar9 = uVar9 + 1;
        } while (uVar9 < uVar4);
    }
    return 0.0f;
}

// 0x4ba8e0 — observed shape
int* FUN_004ba8e0(int* param_1, char* in_EAX) {
    if (in_EAX == nullptr) return nullptr;
    char local_30c[256] = {0};
    std::strncpy(local_30c, in_EAX, sizeof(local_30c) - 1);
    bool bVar12 = false;
    char* pcVar4 = std::strchr(local_30c, 10);
    char local_208[256] = {0};
    unsigned char abStack_108[264] = {0};
    if (pcVar4 != nullptr) {
        std::strncpy(local_208, pcVar4 + 1, sizeof(local_208) - 1);
        *pcVar4 = '\0';
        char* pcVar8 = std::strchr(local_208, 10);
        if (pcVar8 != nullptr) {
            std::strncpy(reinterpret_cast<char*>(abStack_108), pcVar8 + 1, sizeof(abStack_108) - 1);
            *pcVar8 = '\0';
            bVar12 = true;
        }
    }
    void** vtable = *reinterpret_cast<void***>(param_1);
    auto lookup = reinterpret_cast<int*(*)(char*)>(vtable[0x40 / 4]);
    int* piVar5 = lookup(local_30c);
    if (piVar5 != nullptr && bVar12) {
        int iVar9 = 5;
        bool ok = true;
        const char* pcVar4b = "PROP";
        const char* pcVar8b = nullptr;
        char acStack_20c[4] = {'P','R','O','P'};
        pcVar8b = pcVar4b;
        const char* cur = acStack_20c;
        do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            ok = *cur == *pcVar8b;
            cur = cur + 1;
            pcVar8b = pcVar8b + 1;
        } while (ok);
        if (ok) {
            int* piVar11 = reinterpret_cast<int*>(piVar5[0x29]);
            if (piVar11 != nullptr) {
                do {
                    int* piVar3 = reinterpret_cast<int*>(piVar11[2]);
                    piVar11 = reinterpret_cast<int*>(*piVar11);
                    void** vt = *reinterpret_cast<void***>(piVar3);
                    auto get = reinterpret_cast<void*(*)()>(vt[1]);
                    std::uint32_t* puVar6 = static_cast<std::uint32_t*>(get());
                    const unsigned char* pbVar7 = reinterpret_cast<const unsigned char*>(*puVar6);
                    const unsigned char* pbVar10 = abStack_108;
                    int cmp = std::strcmp(reinterpret_cast<const char*>(pbVar7), reinterpret_cast<const char*>(pbVar10));
                    if (cmp == 0) return piVar3;
                    if (piVar11 == nullptr) return piVar5;
                } while (true);
            }
        }
    }
    return piVar5;
}

// 0x4baa30 — observed shape
void FUN_004baa30(void* self, std::uint32_t param_1, std::uint32_t param_2, std::uint32_t param_3, std::uint32_t param_4, std::uint32_t param_5, std::uint32_t param_6, std::uint32_t param_7, std::uint32_t param_8, std::uint32_t param_9, std::uint32_t param_10, std::uint32_t param_11) {
    std::uint32_t* unaff_ESI = static_cast<std::uint32_t*>(self);
    unaff_ESI[1] = 0;
    *unaff_ESI = reinterpret_cast<std::uint32_t>(PTR_FUN_006fd14c);
    unaff_ESI[7] = 0;
    unaff_ESI[0x19] = 0;
    unaff_ESI[0x2f] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    FUN_004bdca0(param_1, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}

// 0x4baaa0 — observed shape
std::uint32_t FUN_004baaa0(void* self) {
    int in_EAX = reinterpret_cast<int>(self);
    while (true) {
        while (*reinterpret_cast<int*>(in_EAX + 0x50) != 0) {
            FUN_005516a0();
            FUN_005007e0();
        }
        if ((*reinterpret_cast<int*>(in_EAX + 0xbc) == 0) || (1 < DAT_007263a0)) break;
        in_EAX = *reinterpret_cast<int*>(in_EAX + 0xbc);
    }
    return *reinterpret_cast<std::uint32_t*>(in_EAX + 0x1c);
}
