// Reconstruction batch mass_0160 — Sid Meier's Pirates! (2004) PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
// Ghidra 12.2 pseudocode corpus translations. Names follow FUN_<addr>.

#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdio>

// Referenced helpers / globals (extern declarations; not defined here)
extern void FUN_00564aa0(uint32_t);
extern void FUN_00567520();
extern void* FUN_00533c78(size_t);
extern void thunk_FUN_00538630(int32_t);
extern void FUN_00535110(int32_t);
extern void thunk_FUN_00538430(int32_t);
extern void FUN_00535150(int32_t);
extern int32_t FUN_00557b10(...);
extern void FUN_006b34a0(...);
extern void FUN_005606f0(uint32_t, void*);
extern int32_t FUN_00535230();
extern void* thunk_FUN_00533c78();
extern void* DAT_00727430;
extern void* DAT_00727434;
extern void* DAT_00727438;
extern void* PTR_FUN_006c3620;
extern void* PTR_FUN_006c3698;

// 0x564d30 — observed shape
void FUN_00564d30(uint8_t* self, void* param_1) {
    // *param_1[0xc..0x20] = *self[0xc..0x20]
    auto* dst = static_cast<uint8_t*>(param_1);
    auto* src = static_cast<uint8_t*>(static_cast<void*>(self));
    for (size_t off = 0xc; off <= 0x20; off += 4) {
        *reinterpret_cast<uint32_t*>(dst + off) = *reinterpret_cast<uint32_t*>(src + off);
    }
    FUN_00564aa0(*reinterpret_cast<uint32_t*>(src + 0x24));
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(src + 0x28);
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(dst + 0x28);
    for (int32_t iVar1 = static_cast<int32_t>((*reinterpret_cast<uint32_t*>(src + 0x24) & 0xfffffffu) << 2); iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    for (int32_t iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *reinterpret_cast<uint8_t*>(puVar3) = *reinterpret_cast<uint8_t*>(puVar2);
        puVar2 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar2) + 1);
        puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar3) + 1);
    }
}

// 0x564df0 — observed shape
uint32_t* FUN_00564df0(void* self) {
    uint32_t* puVar2 = static_cast<uint32_t*>(FUN_00533c78(0x2c));
    uint32_t* puVar4 = nullptr;
    if (puVar2 != nullptr) {
        FUN_00567520();
        puVar2[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c3620);
        puVar2[3] = reinterpret_cast<uint32_t>(DAT_00727430);
        puVar2[4] = reinterpret_cast<uint32_t>(DAT_00727434);
        uint32_t uVar1 = reinterpret_cast<uint32_t>(DAT_00727438);
        puVar2[9] = 0;
        puVar2[10] = 0;
        puVar2[5] = uVar1;
        puVar4 = puVar2;
    }
    puVar4[3] = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0xc);
    puVar4[4] = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x10);
    puVar4[5] = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x14);
    FUN_00564aa0(*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x24));
    uint32_t* puVar2b = *reinterpret_cast<uint32_t**>(static_cast<uint8_t*>(self) + 0x28);
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(puVar4[10]);
    for (int32_t iVar3 = static_cast<int32_t>((*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x24) & 0xfffffffu) << 2); iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2b;
        puVar2b = puVar2b + 1;
        puVar5 = puVar5 + 1;
    }
    for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar5) = *reinterpret_cast<uint8_t*>(puVar2b);
        puVar2b = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar2b) + 1);
        puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar5) + 1);
    }
    return puVar4;
}

// 0x564f00 — observed shape
void FUN_00564f00(void* self, int32_t param_1) {
    int32_t iVar1 = param_1;
    thunk_FUN_00538630(param_1);
    FUN_00535110(iVar1);
    void* vtbl = *reinterpret_cast<void**>(iVar1 + 0x15c);
    auto fn1 = reinterpret_cast<void(__cdecl*)(void*, uint32_t)>(*reinterpret_cast<void**>(vtbl) + 8);
    fn1(&param_1, 4);
    FUN_00564aa0(0); // unaff_EBX observed as value
    uint32_t uVar2 = 0;
    uint32_t unaff_EBX = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x24); // count from self+0x24 per corpus
    // Preserve observed do-while over unaff_EBX entries, stride 0x10 over self+0x28
    if (unaff_EBX != 0) {
        int32_t iVar3 = 0;
        do {
            int32_t base = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(self) + 0x28);
            fn1(reinterpret_cast<void*>(base + iVar3), 4);
            fn1(reinterpret_cast<void*>(base + 4 + iVar3), 4);
            uVar2 = uVar2 + 1;
            iVar3 = iVar3 + 0x10;
        } while (uVar2 < unaff_EBX);
    }
}

// 0x564f80 — observed shape
void FUN_00564f80(void* self, int32_t param_1) {
    thunk_FUN_00538430(param_1);
    FUN_00535150(param_1);
    void* vtbl = *reinterpret_cast<void**>(param_1 + 0x160);
    auto fn1 = reinterpret_cast<void(__cdecl*)(void*, uint32_t)>(*reinterpret_cast<void**>(vtbl) + 0xc);
    fn1(static_cast<uint8_t*>(self) + 0x24, 4);
    uint32_t uVar1 = 0;
    if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(self) + 0x24) != 0) {
        int32_t iVar2 = 0;
        do {
            int32_t base = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(self) + 0x28);
            fn1(reinterpret_cast<void*>(base + iVar2), 4);
            fn1(reinterpret_cast<void*>(base + 4 + iVar2), 4);
            uVar1 = uVar1 + 1;
            iVar2 = iVar2 + 0x10;
        } while (uVar1 < *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x24));
    }
}

// 0x564ff0 — observed shape
void FUN_00564ff0(void* self, int32_t param_1) {
    uint32_t uVar1;
    char* _Dest;
    int32_t iVar2;
    int32_t local_c = reinterpret_cast<int32_t>(self);
    int32_t local_10 = FUN_00557b10();
    uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0xc);
    if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar1) {
        FUN_006b34a0();
    }
    FUN_005606f0(uVar1, &local_10);
    local_10 = FUN_00535230();
    uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0xc);
    if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar1) {
        FUN_006b34a0();
    }
    FUN_005606f0(uVar1, &local_10);
    local_10 = FUN_00535230();
    uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0xc);
    if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar1) {
        FUN_006b34a0();
    }
    FUN_005606f0(uVar1, &local_10);
    uint32_t local_14 = 0;
    if (*reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x24) == 0) {
        return;
    }
    int32_t local_10b = 0;
    do {
        _Dest = static_cast<char*>(thunk_FUN_00533c78());
        int32_t base = *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x28);
        sprintf(_Dest, "range[%d] = %g   %g", local_14,
                static_cast<double>(*reinterpret_cast<float*>(base + local_10b)),
                static_cast<double>(*reinterpret_cast<float*>(base + 4 + local_10b)));
        uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0xc);
        if ((uVar1 < *reinterpret_cast<uint32_t*>(param_1 + 8)) || (FUN_006b34a0(), uVar1 < *reinterpret_cast<uint32_t*>(param_1 + 8))) {
            if (uVar1 < *reinterpret_cast<uint32_t*>(param_1 + 0xc)) {
                if (_Dest == nullptr) {
                    if (*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(param_1 + 4) + uVar1 * 4) != 0) {
                        iVar2 = *reinterpret_cast<int32_t*>(param_1 + 0x10) + -1;
                        goto LAB_0056514b;
                    }
                }
                else if (*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(param_1 + 4) + uVar1 * 4) == 0) {
                    iVar2 = *reinterpret_cast<int32_t*>(param_1 + 0x10) + 1;
                LAB_0056514b:
                    *reinterpret_cast<int32_t*>(param_1 + 0x10) = iVar2;
                }
            }
            else {
                *reinterpret_cast<uint32_t*>(param_1 + 0xc) = uVar1 + 1;
                if (_Dest != nullptr) {
                    iVar2 = *reinterpret_cast<int32_t*>(param_1 + 0x10) + 1;
                    goto LAB_0056514b;
                }
            }
            *reinterpret_cast<char**>(*reinterpret_cast<int32_t*>(param_1 + 4) + uVar1 * 4) = _Dest;
        }
        local_14 = local_14 + 1;
        local_10b = local_10b + 0x10;
        if (*reinterpret_cast<uint32_t*>(local_c + 0x24) <= local_14) {
            return;
        }
        self = reinterpret_cast<void*>(local_c);
    } while (true);
}
extern void FUN_00559510(uint32_t);
extern void FUN_00545cc0();
extern void thunk_FUN_00513ce0(uint32_t);
extern void* FUN_00545600();
extern void FUN_005591e0(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void* FUN_0053bb30(int32_t);
extern void FUN_005592d0();
extern void FUN_00559020();

// 0x565180 — observed shape
void FUN_00565180(void* self, uint32_t param_1) {
    FUN_00559510(param_1);
    FUN_00545cc0();
}

// 0x5651e0 — observed shape
void FUN_005651e0(void* self, uint32_t* param_1) {
    uint16_t uVar2 = static_cast<uint16_t>(reinterpret_cast<uintptr_t>(param_1));
    uint32_t* puVar3 = param_1;
    auto* self_u8 = static_cast<uint8_t*>(self);
    if (uVar2 < *reinterpret_cast<uint16_t*>(self_u8 + 0x44)) {
        do {
            void* vtbl = *reinterpret_cast<void**>(*reinterpret_cast<int32_t*>(self_u8 + 0x50));
            auto fn = reinterpret_cast<void(__cdecl*)(void*, uint32_t)>(*reinterpret_cast<void**>(vtbl) + 0x78);
            fn(&param_1, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)) & 0xffffu);
            if (param_1 != nullptr) {
                int32_t iVar1 = static_cast<int32_t>(param_1[1]);
                param_1[1] = static_cast<uint32_t>(iVar1 + -1);
                if (iVar1 + -1 == 0) {
                    auto dtor = reinterpret_cast<void(__cdecl*)(uint32_t*)>(*param_1);
                    dtor(param_1);
                }
            }
            puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar3) + 1);
        } while (static_cast<uint16_t>(reinterpret_cast<uintptr_t>(puVar3)) < *reinterpret_cast<uint16_t*>(self_u8 + 0x44));
    }
    if (*reinterpret_cast<uint16_t*>(self_u8 + 0xc) < uVar2) {
        *reinterpret_cast<uint16_t*>(self_u8 + 0x44) = *reinterpret_cast<uint16_t*>(self_u8 + 0xc);
        return;
    }
    *reinterpret_cast<uint16_t*>(self_u8 + 0x44) = uVar2;
}

// 0x565250 — observed shape
void FUN_00565250(void* self, uint32_t param_1) {
    thunk_FUN_00513ce0(param_1);
    uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00545600());
    auto* self_u8 = static_cast<uint8_t*>(self);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(self_u8 + 0x50);
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto dtor = reinterpret_cast<void(__cdecl*)(uint32_t*)>(*puVar2);
                dtor(puVar2);
            }
        }
        *reinterpret_cast<uint32_t**>(self_u8 + 0x50) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x565310 — observed shape
void FUN_00565310(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5) {
    FUN_005591e0(param_1, param_2, param_3, param_4, param_5);
    auto* self_u32 = reinterpret_cast<uint32_t*>(self);
    self_u32[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c3698);
    self_u32[0x14] = 0;
    int32_t iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0xec)));
    uint32_t* puVar4;
    if (iVar3 == 0) {
        puVar4 = nullptr;
    } else {
        puVar4 = static_cast<uint32_t*>(FUN_0053bb30(0));
    }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self_u32[0x14]);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto dtor = reinterpret_cast<void(__cdecl*)(uint32_t*)>(*puVar2);
                dtor(puVar2);
            }
        }
        self_u32[0x14] = reinterpret_cast<uint32_t>(puVar4);
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0x15) = 0;
}

// 0x5653a0 — observed shape
void FUN_005653a0(void* self) {
    FUN_005592d0();
    auto* self_u32 = reinterpret_cast<uint32_t*>(self);
    self_u32[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c3698);
    self_u32[0x14] = 0;
    int32_t iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0xec)));
    uint32_t* puVar4;
    if (iVar3 == 0) {
        puVar4 = nullptr;
    } else {
        puVar4 = static_cast<uint32_t*>(FUN_0053bb30(0));
    }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self_u32[0x14]);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto dtor = reinterpret_cast<void(__cdecl*)(uint32_t*)>(*puVar2);
                dtor(puVar2);
            }
        }
        self_u32[0x14] = reinterpret_cast<uint32_t>(puVar4);
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0x15) = 0;
}
extern void FUN_00520da0(void*);
extern void FUN_005598b0(int32_t);
extern void* DAT_00727d98;
extern void* DAT_00727558;
extern void FUN_0053e940(uint32_t, uint32_t, uint8_t*);
extern void FUN_004db0a0();
extern void FUN_005609e0(uint32_t);
extern int32_t* DAT_00717a80;

// 0x5654c0 — observed shape
void FUN_005654c0(void* self) {
    auto* self_u8 = static_cast<uint8_t*>(self);
    int32_t iVar3 = 0;
    uint32_t uVar4 = 0;
    if (*reinterpret_cast<int16_t*>(self_u8 + 0x44) != 0) {
        do {
            uint32_t limit = *reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self_u8 + 0x50)) + 0xc0);
            if (uVar4 < limit) {
                int32_t base_b8 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self_u8 + 0x50) + 0xb8);
                int32_t iVar1 = *reinterpret_cast<int32_t*>(base_b8 + uVar4 * 4);
                if (iVar1 != 0) {
                    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(self_u8 + 0x20) + iVar3);
                    *reinterpret_cast<uint32_t*>(iVar1 + 0x5c) = puVar2[0];
                    *reinterpret_cast<uint32_t*>(iVar1 + 0x60) = puVar2[1];
                    *reinterpret_cast<uint32_t*>(iVar1 + 100) = puVar2[2];
                    if (*reinterpret_cast<int32_t*>(self_u8 + 0x4c) != 0) {
                        FUN_00520da0(reinterpret_cast<void*>(iVar1 + 0x38));
                    }
                    float f48 = *reinterpret_cast<float*>(*reinterpret_cast<int32_t*>(self_u8 + 0x48) + uVar4 * 4);
                    float f40 = *reinterpret_cast<float*>(*reinterpret_cast<int32_t*>(self_u8 + 0x40) + uVar4 * 4);
                    *reinterpret_cast<float*>(iVar1 + 0x68) = (f48 * f40) >= 0.0f ? (f48 * f40) : -(f48 * f40);
                }
            }
            uVar4 = uVar4 + 1;
            iVar3 = iVar3 + 0xc;
        } while (uVar4 < static_cast<uint16_t>(*reinterpret_cast<int16_t*>(self_u8 + 0x44)));
    }
}

// 0x565580 — observed shape
void FUN_00565580(void* self, uint8_t param_1) {
    auto* self_u32 = reinterpret_cast<uint32_t*>(self);
    self_u32[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c3698);
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self_u32[0x14]);
    if (puVar2 != nullptr) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            auto dtor = reinterpret_cast<void(__cdecl*)(uint32_t*)>(*puVar2);
            dtor(puVar2);
        }
        self_u32[0x14] = 0;
    }
    puVar2 = reinterpret_cast<uint32_t*>(self_u32[0x14]);
    if (puVar2 != nullptr) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            auto dtor = reinterpret_cast<void(__cdecl*)(uint32_t*)>(*puVar2);
            dtor(puVar2);
        }
    }
    FUN_00559020();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5655e0 — observed shape
void FUN_005655e0(int32_t param_1) {
    int32_t iVar2 = param_1;
    FUN_005598b0(param_1);
    int32_t param_1b = FUN_00557b10(DAT_00727d98);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1b);
}

// 0x565790 — observed shape
void FUN_00565790(void* self, uint32_t param_1, uint32_t param_2, uint8_t* param_3) {
    FUN_0053e940(param_1, 1, param_3);
    int32_t* piVar2 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0xbc) + 0x50);
    auto fn = reinterpret_cast<void(__cdecl*)(uint32_t, uint32_t, uint8_t*)>(*reinterpret_cast<void**>(*piVar2 + 0x44));
    fn(param_1, 1, param_3);
    *param_3 = 0;
    uint8_t* pbVar1 = reinterpret_cast<uint8_t*>(piVar2 + 8);
    *pbVar1 = static_cast<uint8_t>(*pbVar1 & 0xef);
}

// 0x565870 — observed shape
void FUN_00565870(int32_t param_1) {
    int32_t iVar2 = param_1;
    FUN_0053a8f0(param_1);
    int32_t param_1b = FUN_00557b10(DAT_00727558);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1b);
}

extern void FUN_0053a8f0(int32_t);
extern void thunk_FUN_0053bf20(int32_t);
extern void* FUN_00564950();
extern void FUN_00561060();
extern void FUN_00535110();

// 0x5658c0 — observed shape
void FUN_005658c0(void* self) {
    FUN_004db0a0();
    auto* self_u8 = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<int32_t**>(self_u8 + 0x118) != nullptr) {
        auto fn = reinterpret_cast<void(__cdecl*)()>(*reinterpret_cast<void**>(*reinterpret_cast<int32_t*>(self_u8 + 0x118) + 0x38));
        fn();
    }
}

// 0x5658e0 — observed shape
void FUN_005658e0(void* self, uint32_t param_1) {
    auto* self_u8 = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<char*>(self_u8 + 0x11c) != '\0' && *reinterpret_cast<int32_t**>(self_u8 + 0x118) != nullptr) {
        auto fn34 = reinterpret_cast<uint32_t(__cdecl*)(uint32_t)>(*reinterpret_cast<void**>(*reinterpret_cast<int32_t*>(self_u8 + 0x118) + 0x34));
        uint32_t uVar2 = fn34(param_1);
        *reinterpret_cast<uint32_t*>(self_u8 + 0xf0) = uVar2;
        if (-1 < *DAT_00717a80) {
            auto fn40 = reinterpret_cast<uint32_t(__cdecl*)(int32_t)>(*reinterpret_cast<void**>(*reinterpret_cast<int32_t*>(self_u8 + 0x118) + 0x40));
            uVar2 = fn40(*DAT_00717a80);
            *reinterpret_cast<uint32_t*>(self_u8 + 0xf0) = uVar2;
        }
        if (0 <= *reinterpret_cast<int32_t*>(self_u8 + 0xf0)) {
            do {
                int32_t iVar1 = *reinterpret_cast<int32_t*>(self_u8 + 0xf0);
                if (iVar1 < *reinterpret_cast<int32_t*>(self_u8 + 0xc0) && *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self_u8 + 0xb8) + iVar1 * 4) != 0) break;
                *reinterpret_cast<int32_t*>(self_u8 + 0xf0) = iVar1 + -1;
            } while (0 <= *reinterpret_cast<int32_t*>(self_u8 + 0xf0));
        }
    }
    FUN_005609e0(param_1);
}

// 0x565970 — observed shape
void FUN_00565970(void* self) {
    auto* self_u8 = static_cast<uint8_t*>(self);
    int32_t iVar2 = 0;
    if (0 < *reinterpret_cast<int32_t*>(self_u8 + 0xc0)) {
        do {
            int32_t* piVar1 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(self_u8 + 0xb8) + iVar2 * 4);
            if (piVar1 != nullptr && *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self_u8 + 0x100) + iVar2 * 4) != *reinterpret_cast<int32_t*>(self_u8 + 0xf8)) {
                FUN_005606f0(static_cast<uint32_t>(iVar2), self_u8 + 0xf8);
                auto fn48 = reinterpret_cast<void(__cdecl*)(uint32_t, uint8_t)>(*reinterpret_cast<void**>(*piVar1 + 0x48));
                fn48(*reinterpret_cast<uint32_t*>(self_u8 + 0xf4), *reinterpret_cast<uint8_t*>(self_u8 + 0x114));
            }
            iVar2 = iVar2 + 1;
        } while (iVar2 < *reinterpret_cast<int32_t*>(self_u8 + 0xc0));
    }
}

// 0x5659e0 — observed shape
void FUN_005659e0(void* self, int32_t param_1) {
    thunk_FUN_0053bf20(param_1);
    if (0xa00010bu < *reinterpret_cast<uint32_t*>(param_1 + 0x1c)) {
        uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00545600());
        auto* self_u8 = static_cast<uint8_t*>(self);
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(self_u8 + 0x118);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    auto dtor = reinterpret_cast<void(__cdecl*)(uint32_t*)>(*puVar2);
                    dtor(puVar2);
                }
            }
            *reinterpret_cast<uint32_t**>(self_u8 + 0x118) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
}

// 0x565af0 — observed shape
void FUN_00565af0(void* self, int32_t param_1) {
    int32_t iVar3 = param_1;
    // Stack marker constants observed in Ghidra output (0x565b05, 0x2c, 0x565b28, 4)
    // preserved conceptually; only control flow is reproduced.
    FUN_00561060();
    if (0xa00010bu < *reinterpret_cast<uint32_t*>(iVar3 + 0x1c)) {
        FUN_00545cc0();
        return;
    }
    int32_t iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78()));
    uint32_t* puVar5;
    if (iVar4 == 0) {
        puVar5 = nullptr;
    } else {
        puVar5 = static_cast<uint32_t*>(FUN_00564950());
    }
    int32_t local_c;
    int32_t local_8;
    uint32_t local_4;
    uint32_t uVar6;
    // FUN_00535110() populates local_c/local_8/local_4 in the original (via stack);
    // reproduced as zeroed locals since the callee's stack outputs are not in the
    // decompiled parameter list.
    FUN_00535110();
    puVar5[3] = static_cast<uint32_t>(local_c);
    puVar5[4] = static_cast<uint32_t>(local_8);
    puVar5[5] = local_4;
    // vtbl call at iVar3+0x15c offset 8 with &param_1, 4
    {
        void* vtbl = *reinterpret_cast<void**>(iVar3 + 0x15c);
        auto fn = reinterpret_cast<void(__cdecl*)(void*)>(*reinterpret_cast<void**>(vtbl) + 8);
        fn(&param_1);
    }
    if (local_4 != 0) {
        FUN_00564aa0(local_4);
        uVar6 = 0;
        if (local_4 != 0) {
            iVar4 = 0;
            do {
                uint32_t unaff_EBX = 0;
                uint32_t unaff_EBP = 0;
                uint8_t auStack_1e[6];
                int32_t iStack_30;
                int32_t iStack_18;
                void* vtbl = *reinterpret_cast<void**>(iVar3 + 0x15c);
                auto fn = reinterpret_cast<void(__cdecl*)(void*, uint32_t)>(*reinterpret_cast<void**>(vtbl) + 8);
                fn(auStack_1e + -6 + 6, 4);
                fn(&iStack_30, 4);
                if (puVar5[9] <= uVar6) {
                    FUN_00564aa0(uVar6 + 1);
                }
                *reinterpret_cast<uint32_t*>(puVar5[10] + iVar4) = unaff_EBX;
                uVar6 = uVar6 + 1;
                *reinterpret_cast<uint32_t*>(puVar5[10] + 4 + iVar4) = unaff_EBP;
                iVar4 = iVar4 + 0x10;
                self = reinterpret_cast<void*>(iStack_18);
            } while (uVar6 < local_4);
        }
    }
    auto* self_u8 = static_cast<uint8_t*>(self);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(self_u8 + 0x118);
    if (puVar2 != puVar5) {
        if (puVar2 != nullptr) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto dtor = reinterpret_cast<void(__cdecl*)(uint32_t*)>(*puVar2);
                dtor(puVar2);
            }
        }
        *reinterpret_cast<uint32_t**>(self_u8 + 0x118) = puVar5;
        puVar5[1] = puVar5[1] + 1;
    }
}
