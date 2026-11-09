#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern uint16_t FUN_005496b0(int param_1);
extern void FUN_004db0a0();
extern void FUN_00549610(int param_1);
extern void FUN_00549660(int param_1);
extern void FUN_00549730(int param_1);
extern int FUN_00557b10(intptr_t value);
extern void FUN_006b34a0(int value);
extern void FUN_005606f0(uint32_t index, intptr_t* value);
extern int FUN_00557cf0(const char* name, uint32_t value);
extern void FUN_00538630(uint32_t param_1);
extern void FUN_00545cc0();
extern void FUN_00513ce0(uint32_t param_1);
extern uint32_t FUN_00545600();
extern char FUN_00538360(uint32_t param_1);
extern void FUN_00538430(int* param_1);
extern uint32_t FUN_00538460(int param_1);
extern void FUN_004c2d90(void* self);
extern void FUN_005383d0();
extern void FUN_005386f0(int param_1);
extern int FUN_00557d40(const char* name, uint32_t value);
extern int FUN_00533c78(size_t size);
extern void FUN_0053e5d0(uint32_t value);
extern uint32_t FUN_0055a5f0(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7);
extern char FUN_005573d0(intptr_t value);
extern void FUN_0051ac30(int param_1);
extern void FUN_00534000(intptr_t value);
extern void FUN_00557530(uint32_t value);
extern void FUN_0053edc0(int param_1);
extern void FUN_0055ab40(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8);
extern void FUN_0055a250();
extern void FUN_0055abb0();
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern intptr_t DAT_007278b0;
extern intptr_t DAT_007278b8;
extern intptr_t DAT_007278c0;
extern intptr_t DAT_00727cd8;
extern int DAT_00727444;
extern void* PTR_LAB_006c1e00;
extern void* PTR_FUN_006c1e70;
extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006c0ba8;
extern void* PTR_FUN_006c1ef8;

// 0x5498a0 — observed shape
uint16_t FUN_005498a0(void* self, int param_1) {
    float fVar1;
    float fVar2;
    uint16_t uVar3 = FUN_005496b0(param_1);
    if (static_cast<char>(uVar3) != '\0') {
        fVar1 = *reinterpret_cast<const float*>(reinterpret_cast<const uint8_t*>(reinterpret_cast<const void*>(static_cast<intptr_t>(param_1))) + 0x110);
        fVar2 = *reinterpret_cast<const float*>(static_cast<const uint8_t*>(self) + 0x110);
        uVar3 = static_cast<uint16_t>(static_cast<uint16_t>(fVar2 < fVar1) << 8 | static_cast<uint16_t>(std::isnan(fVar2) || std::isnan(fVar1)) << 10 | static_cast<uint16_t>(fVar2 == fVar1) << 0xe);
        if (fVar2 == fVar1) {
            fVar1 = *reinterpret_cast<const float*>(reinterpret_cast<const uint8_t*>(reinterpret_cast<const void*>(static_cast<intptr_t>(param_1))) + 0x114);
            fVar2 = *reinterpret_cast<const float*>(static_cast<const uint8_t*>(self) + 0x114);
            uVar3 = static_cast<uint16_t>(static_cast<uint16_t>(fVar2 < fVar1) << 8 | static_cast<uint16_t>(std::isnan(fVar2) || std::isnan(fVar1)) << 10 | static_cast<uint16_t>(fVar2 == fVar1) << 0xe);
            if (fVar2 == fVar1) {
                fVar1 = *reinterpret_cast<const float*>(reinterpret_cast<const uint8_t*>(reinterpret_cast<const void*>(static_cast<intptr_t>(param_1))) + 0x118);
                fVar2 = *reinterpret_cast<const float*>(static_cast<const uint8_t*>(self) + 0x118);
                uVar3 = static_cast<uint16_t>(static_cast<uint16_t>(fVar2 < fVar1) << 8 | static_cast<uint16_t>(std::isnan(fVar2) || std::isnan(fVar1)) << 10 | static_cast<uint16_t>(fVar2 == fVar1) << 0xe);
                if (fVar2 == fVar1) {
                    return static_cast<uint16_t>(static_cast<uint16_t>(static_cast<uint8_t>(static_cast<char>(uVar3 >> 8))) << 8 | 1);
                }
            }
        }
    }
    return static_cast<uint16_t>(uVar3 & 0xff00);
}

// 0x549900 — observed shape
void FUN_00549900(void* self) {
    FUN_004db0a0();
    int32_t* slot = reinterpret_cast<int32_t*>(static_cast<uint8_t*>(self) + 0xc0);
    *slot = *slot + 1;
}

// 0x5499e0 — observed shape
void FUN_005499e0(void* self, int param_1) {
    FUN_00549610(param_1);
    int32_t** vtableHolder = *reinterpret_cast<int32_t***>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(param_1))) + 0x15c);
    // (**(code **)(**(int **)(param_1 + 0x15c) + 8))(in_ECX + 0x110, 4)
    using Fn = void (*)(void*, int);
    auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtableHolder) + 8));
    fn(static_cast<uint8_t*>(self) + 0x110, 4);
    fn(static_cast<uint8_t*>(self) + 0x114, 4);
    fn(static_cast<uint8_t*>(self) + 0x118, 4);
}

// 0x549a30 — observed shape
void FUN_00549a30(void* self, int param_1) {
    FUN_00549660(param_1);
    int32_t** vtableHolder = *reinterpret_cast<int32_t***>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(param_1))) + 0x160);
    using Fn = void (*)(void*, int);
    auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtableHolder) + 0xc));
    fn(static_cast<uint8_t*>(self) + 0x110, 4);
    fn(static_cast<uint8_t*>(self) + 0x114, 4);
    fn(static_cast<uint8_t*>(self) + 0x118, 4);
}

// 0x549a80 — observed shape
void FUN_00549a80(void* self, int param_1) {
    int paramSaved = param_1;
    FUN_00549730(param_1);
    int local = FUN_00557b10(static_cast<intptr_t>(DAT_007278b0));
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 0xc);
    if (*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, reinterpret_cast<intptr_t*>(&local));
    local = FUN_00557cf0("m_fAtten0", *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x110));
    uVar1 = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 0xc);
    if (*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, reinterpret_cast<intptr_t*>(&local));
    local = FUN_00557cf0("m_fAtten1", *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x114));
    uVar1 = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 0xc);
    if (*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(static_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, reinterpret_cast<intptr_t*>(&local));
    local = FUN_00557cf0("m_fAtten2", *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x118));
    uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 0xc);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(paramSaved))) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, reinterpret_cast<intptr_t*>(&local));
}

// 0x549ba0 — observed shape
void FUN_00549ba0(uint32_t param_1) {
    FUN_00538630(param_1);
    FUN_00545cc0();
}

// 0x549bc0 — observed shape
void FUN_00549bc0(void* self, uint32_t param_1) {
    uint32_t uVar1;
    FUN_00513ce0(param_1);
    uVar1 = FUN_00545600();
    *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0xc) = uVar1;
}

// 0x549be0 — observed shape
uint8_t FUN_00549be0(void* self, uint32_t param_1) {
    char cVar1;
    int32_t* slot;
    cVar1 = FUN_00538360(param_1);
    if (cVar1 == '\0') {
        return 0;
    }
    slot = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0xc);
    if (slot != nullptr) {
        using Fn = void (*)(void*, uint32_t);
        auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(slot) + 0x14));
        fn(slot, param_1);
    }
    return 1;
}

// 0x549c10 — observed shape
void FUN_00549c10(void* self, int* param_1) {
    FUN_00538430(param_1);
    using Fn = void (*)(void*, uint32_t);
    auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(param_1) + 0x2c));
    fn(param_1, *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0xc));
}

// 0x549c30 — observed shape
uint32_t FUN_00549c30(void* self, int param_1) {
    uint32_t uVar1;
    uVar1 = FUN_00538460(param_1);
    if (static_cast<char>(uVar1) != '\0') {
        uVar1 = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0xc);
        if (uVar1 != 0) {
            if (param_1 == 0) {
                return uVar1 & 0xffffff00u;
            }
            return (uVar1 & 0xffffff00u) | 1u;
        }
        if (param_1 == 0) {
            return (uVar1 & 0xffffff00u) | 1u;
        }
        return uVar1 & 0xffffff00u;
    }
    return uVar1 & 0xffffff00u;
}

// 0x549c80 — observed shape
void FUN_00549c80(void* self, int param_1) {
    uint32_t* piVar1;
    uint32_t* puVar2;
    uint32_t* ecx = static_cast<uint32_t*>(self);
    ecx[3] = static_cast<uint32_t>(param_1);
    if (param_1 != 0) {
        puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0xb0);
        if (puVar2 != nullptr) {
            puVar2[1] = puVar2[1] + 1;
        }
        if (puVar2 != nullptr) {
            piVar1 = puVar2 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                using Fn = void (*)(void*, int);
                auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
                fn(puVar2, 1);
            }
        }
        if (static_cast<void*>(puVar2) != self) {
            FUN_004c2d90(self);
        }
    }
}

// 0x549cd0 — observed shape
void FUN_00549cd0(void* self, int param_1) {
    uint32_t* piVar1;
    uint32_t* puVar2;
    uint32_t* ecx = static_cast<uint32_t*>(self);
    FUN_005383d0();
    *reinterpret_cast<void**>(ecx) = static_cast<void*>(&PTR_LAB_006c1e00);
    ecx[3] = static_cast<uint32_t>(param_1);
    if (param_1 != 0) {
        puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0xb0);
        if (puVar2 != nullptr) {
            puVar2[1] = puVar2[1] + 1;
        }
        if (puVar2 != nullptr) {
            piVar1 = puVar2 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                using Fn = void (*)(void*, int);
                auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
                fn(puVar2, 1);
            }
        }
        if (static_cast<void*>(puVar2) != self) {
            FUN_004c2d90(self);
        }
    }
}

// 0x549d20 — observed shape
void FUN_00549d20(void* self, int param_1) {
    uint32_t uVar1;
    int iVar2;
    int local;
    iVar2 = param_1;
    FUN_005386f0(param_1);
    local = FUN_00557b10(DAT_007278b8);
    uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0xc);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, reinterpret_cast<intptr_t*>(&local));
    using Fn = void (*)(void*, int);
    auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(self)) + 0x24));
    fn(self, iVar2);
}

// 0x549d80 — observed shape
void FUN_00549d80(void* self, int param_1) {
    uint32_t uVar1;
    int iVar2;
    int local;
    local = FUN_00557b10(DAT_007278b8);
    iVar2 = param_1;
    uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0xc);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, reinterpret_cast<intptr_t*>(&local));
    local = FUN_00557d40("m_pkSceneObject", *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0xc));
    uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0xc);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, reinterpret_cast<intptr_t*>(&local));
}

// 0x549e00 — observed shape
void FUN_00549e00(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7) {
    int iVar1;
    uint32_t uVar2;
    iVar1 = FUN_00533c78(0x40);
    if (iVar1 == 0) {
        FUN_0053e5d0(0);
        *reinterpret_cast<void**>(self) = static_cast<void*>(&PTR_FUN_006c1e70);
        return;
    }
    uVar2 = FUN_0055a5f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    FUN_0053e5d0(uVar2);
    *reinterpret_cast<void**>(self) = static_cast<void*>(&PTR_FUN_006c1e70);
}

// 0x549f30 — observed shape
void FUN_00549f30(void* self, int param_1) {
    uint32_t* piVar1;
    uint32_t* puVar2;
    char cVar3;
    uint32_t* puVar4;
    uint8_t* base = static_cast<uint8_t*>(self);
    puVar4 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(DAT_00727cd8));
    if (param_1 == 0) {
        puVar4 = *reinterpret_cast<uint32_t**>(base + 0xb8);
        if (puVar4 != nullptr) {
            piVar1 = puVar4 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                using Fn = void (*)(void*, int);
                auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar4));
                fn(puVar4, 1);
            }
            *reinterpret_cast<uint32_t*>(base + 0xb8) = 0;
            return;
        }
    }
    else {
        cVar3 = FUN_005573d0(DAT_00727cd8);
        if (cVar3 == '\0') {
            int* fields = reinterpret_cast<int*>(static_cast<intptr_t>(param_1));
            if ((fields[4] != 0) || (fields[5] != 0) || (fields[6] != 0) || (fields[7] != 0)) {
                uint32_t* obj = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(FUN_00533c78(0x20)));
                if (obj == nullptr) {
                    obj = nullptr;
                }
                else {
                    *reinterpret_cast<void**>(obj) = static_cast<void*>(&PTR_LAB_006fd148);
                    obj[1] = 0;
                    DAT_00727444 = DAT_00727444 + 1;
                    *reinterpret_cast<void**>(obj) = static_cast<void*>(&PTR_FUN_006c0ba8);
                    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(obj) + 8) = 0;
                    obj[3] = 0;
                    obj[4] = 0;
                    obj[5] = 0;
                    obj[6] = 0;
                    obj[7] = 0;
                }
                puVar2 = *reinterpret_cast<uint32_t**>(base + 0xb8);
                if (puVar2 != obj) {
                    if (puVar2 != nullptr) {
                        piVar1 = puVar2 + 1;
                        *piVar1 = *piVar1 - 1;
                        if (*piVar1 == 0) {
                            using Fn = void (*)(void*, int);
                            auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
                            fn(puVar2, 1);
                        }
                    }
                    *reinterpret_cast<uint32_t**>(base + 0xb8) = obj;
                    if (obj != nullptr) {
                        obj[1] = obj[1] + 1;
                    }
                }
                puVar4 = *reinterpret_cast<uint32_t**>(fields + 3);
                while (puVar4 != nullptr) {
                    uint32_t* node = puVar4 + 1;
                    puVar4 = reinterpret_cast<uint32_t*>(*puVar4);
                    FUN_00557530(*node);
                }
                FUN_00534000(*reinterpret_cast<uint32_t*>(base + 0xb8));
                return;
            }
            FUN_0051ac30(param_1);
            FUN_00534000(param_1);
        }
        else {
            puVar2 = *reinterpret_cast<uint32_t**>(base + 0xb8);
            if (puVar2 != puVar4) {
                if (puVar2 != nullptr) {
                    piVar1 = puVar2 + 1;
                    *piVar1 = *piVar1 - 1;
                    if (*piVar1 == 0) {
                        using Fn = void (*)(void*, int);
                        auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
                        fn(puVar2, 1);
                    }
                }
                *reinterpret_cast<uint32_t**>(base + 0xb8) = puVar4;
                if (puVar4 != nullptr) {
                    puVar4[1] = puVar4[1] + 1;
                    return;
                }
            }
        }
    }
}

// 0x54a070 — observed shape
void FUN_0054a070(int param_1) {
    uint32_t uVar1;
    int iVar2;
    int local;
    iVar2 = param_1;
    FUN_0053edc0(param_1);
    local = FUN_00557b10(DAT_007278c0);
    uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0xc);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, reinterpret_cast<intptr_t*>(&local));
}

// 0x54a0c0 — observed shape
void FUN_0054a0c0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint16_t param_9, uint32_t param_10, uint32_t param_11) {
    uint32_t* ecx = static_cast<uint32_t*>(self);
    FUN_0055ab40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
    ecx[0x11] = param_10;
    *reinterpret_cast<void**>(ecx) = static_cast<void*>(&PTR_FUN_006c1ef8);
    *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(ecx) + 0x40) = param_9;
    ecx[0x12] = param_11;
}

// 0x54a3d0 — observed shape
void FUN_0054a3d0(void* self) {
    int* piVar1;
    void* pvVar2;
    uint32_t* ecx = static_cast<uint32_t*>(self);
    pvVar2 = reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2]));
    *reinterpret_cast<void**>(ecx) = static_cast<void*>(&PTR_FUN_006c1ef8);
    if (pvVar2 == nullptr) {
        operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x11])));
        operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x12])));
    }
    else {
        piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(pvVar2) + 0xc);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            FUN_0055a250();
            operator_delete(pvVar2);
        }
        pvVar2 = reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2]));
        piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(pvVar2) + 0xc);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            FUN_0055a250();
            operator_delete(pvVar2);
            FUN_0055abb0();
            return;
        }
    }
    FUN_0055abb0();
}

// 0x54a440 — observed shape
void FUN_0054a440(void* self, uint16_t param_1, void* param_2, void* param_3) {
    int* piVar1;
    void* pvVar2;
    uint8_t* base = static_cast<uint8_t*>(self);
    pvVar2 = *reinterpret_cast<void**>(base + 8);
    if (pvVar2 == nullptr) {
        if (param_2 != *reinterpret_cast<void**>(base + 0x44)) {
            operator_delete__(*reinterpret_cast<void**>(base + 0x44));
        }
        if (param_3 != *reinterpret_cast<void**>(base + 0x48)) {
            operator_delete__(*reinterpret_cast<void**>(base + 0x48));
        }
    }
    else {
        if (param_2 != *reinterpret_cast<void**>(base + 0x44)) {
            piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(pvVar2) + 0xc);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                FUN_0055a250();
                operator_delete(pvVar2);
            }
        }
        if (param_3 != *reinterpret_cast<void**>(base + 0x48)) {
            pvVar2 = *reinterpret_cast<void**>(base + 8);
            piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(pvVar2) + 0xc);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                FUN_0055a250();
                operator_delete(pvVar2);
            }
        }
    }
    *reinterpret_cast<void**>(base + 0x44) = param_2;
    *reinterpret_cast<void**>(base + 0x48) = param_3;
    *reinterpret_cast<uint16_t*>(base + 0x40) = param_1;
}
