// Reconstruction batch mass_0172 — Sid Meier's Pirates! (2004), PE32 i386.
// Ghidra 12.2 pseudocode candidates. Register receivers become explicit
// void* self parameters. Field offsets, constants, call order, return
// shapes and conditional structure follow the supplied listings.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers (only those used by the assigned listings)
// ---------------------------------------------------------------------------
extern char FUN_005bd960(int32_t id, int32_t* out);
extern void FUN_0055f300(int32_t size);
extern void FUN_006b34a0(int32_t ptr);
extern void FUN_005606f0(uint32_t index, int32_t* value);
extern void* FUN_00533c78(uint32_t size);
extern void FUN_00571850();
extern void FUN_00545310(int32_t id, void* obj);
extern uint32_t FUN_005711b0(int32_t a, int32_t b);
extern void FUN_005e1490();
extern uint32_t FUN_00571760(void* self, uint32_t a, uint32_t b, uint32_t c);
extern void FUN_00552d20();
extern char FUN_00568540(uint32_t param);
extern void FUN_0053f150(void* buf, float value, uint32_t entry, uint32_t count);
extern long double FUN_0056a5f0(uint32_t param, uint32_t a, uint32_t b, int32_t c, int32_t d);
extern void FUN_00552aa0(int32_t* obj, uint32_t param);
extern void FUN_00552f70(int32_t obj);
extern void FUN_00545cc0();
extern void FUN_00553060(int32_t obj);
extern void* FUN_00545600();
extern void FUN_005530e0(int32_t* obj);

void operator delete(void* ptr) noexcept;
void operator delete[](void* ptr) noexcept;

// vtable image pointers installed by the listed functions
extern void* PTR_FUN_006c3ee4;
extern void* PTR_FUN_006c3ee8;
extern void* PTR_FUN_006c3f3c;
extern void* PTR_FUN_006c3f90;
extern void* PTR_FUN_006c3f74;
extern void* PTR_FUN_006c3f20;
extern void* PTR_FUN_006c3f58;
extern void* PTR_FUN_006c3f04;
extern void* PTR_FUN_006c41f8;
extern void* PTR_LAB_006fd148;

// Globals written/read by the listed functions
extern int32_t DAT_00727444;
extern uint16_t DAT_00727c5c;
extern char DAT_007283d4;

// ---------------------------------------------------------------------------
// Self-referential helpers defined in this batch (declared first so call
// order inside the file is free)
// ---------------------------------------------------------------------------
extern uint32_t FUN_00571ce0(void* self, int32_t* param_1);
extern void FUN_00571ed0(void* self);
extern void FUN_005732f0(void* self);

// 0x5719c0 — observed shape
int32_t FUN_005719c0(int32_t param_1, uint32_t param_2, uint32_t param_3) {
    int32_t* piVar1;
    int32_t iVar2;
    char cVar3;
    int32_t iVar4;

    cVar3 = FUN_005bd960(param_1, &param_1);
    iVar2 = param_1;
    if (cVar3 == '\0' || param_1 == 0) {
        return 9;
    }
    iVar4 = *reinterpret_cast<int32_t*>(param_1 + 0xc);
    piVar1 = reinterpret_cast<int32_t*>(param_1 + 8);
    if (*reinterpret_cast<int32_t*>(param_1 + 0x10) == iVar4) {
        if (iVar4 == 0) {
            iVar4 = 1;
        } else {
            iVar4 = iVar4 * 2;
        }
        FUN_0055f300(iVar4);
    }
    *reinterpret_cast<uint32_t*>(*piVar1 + *reinterpret_cast<int32_t*>(iVar2 + 0x10) * 4) = param_2;
    *reinterpret_cast<int32_t*>(iVar2 + 0x10) = *reinterpret_cast<int32_t*>(iVar2 + 0x10) + 1;
    iVar4 = *reinterpret_cast<int32_t*>(iVar2 + 0x18);
    if (*reinterpret_cast<int32_t*>(iVar2 + 0x1c) == iVar4) {
        if (iVar4 == 0) {
            iVar4 = 1;
        } else {
            iVar4 = iVar4 * 2;
        }
        FUN_0055f300(iVar4);
    }
    *reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + *reinterpret_cast<int32_t*>(iVar2 + 0x1c) * 4) = param_3;
    *reinterpret_cast<int32_t*>(iVar2 + 0x1c) = *reinterpret_cast<int32_t*>(iVar2 + 0x1c) + 1;
    return 0;
}

// 0x571b40 — observed shape
int32_t FUN_00571b40(int32_t param_1, uint32_t param_2, uint32_t* param_3) {
    char cVar1;

    cVar1 = FUN_005bd960(param_1, &param_1);
    if (cVar1 == '\0' || param_1 == 0) {
        return 2;
    }
    cVar1 = FUN_005bd960(static_cast<int32_t>(param_2), &param_1);
    if (cVar1 == '\0' || param_1 == 0) {
        return 3;
    }
    *param_3 = *reinterpret_cast<uint32_t*>(param_1 + 0xc);
    return 0;
}

// 0x571ba0 — observed shape
int32_t FUN_00571ba0(int32_t param_1, uint32_t param_2, uint32_t* param_3) {
    char cVar1;

    cVar1 = FUN_005bd960(param_1, &param_1);
    if (cVar1 == '\0' || param_1 == 0) {
        return 2;
    }
    cVar1 = FUN_005bd960(static_cast<int32_t>(param_2), &param_1);
    if (cVar1 == '\0' || param_1 == 0) {
        return 3;
    }
    *param_3 = *reinterpret_cast<uint32_t*>(param_1 + 0x1c);
    return 0;
}

// 0x571c00 — observed shape
int32_t FUN_00571c00(int32_t param_1, uint32_t param_2, uint32_t param_3,
                     uint32_t* param_4, uint32_t* param_5) {
    uint32_t* puVar1;
    char cVar2;

    cVar2 = FUN_005bd960(param_1, &param_1);
    if (cVar2 == '\0' || param_1 == 0) {
        return 2;
    }
    cVar2 = FUN_005bd960(static_cast<int32_t>(param_2), &param_1);
    if (cVar2 == '\0' || param_1 == 0) {
        return 3;
    }
    if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < param_3) {
        return 6;
    }
    puVar1 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int32_t*>(param_1 + 0x14) + param_3 * 4);
    *param_4 = puVar1[0];
    *param_5 = puVar1[1];
    return 0;
}

// 0x571c80 — observed shape
int32_t FUN_00571c80(int32_t param_1, uint32_t param_2, uint8_t* param_3) {
    char cVar1;

    cVar1 = FUN_005bd960(param_1, &param_1);
    if (cVar1 == '\0' || param_1 == 0) {
        return 2;
    }
    cVar1 = FUN_005bd960(static_cast<int32_t>(param_2), &param_1);
    if (cVar1 == '\0' || param_1 == 0) {
        *param_3 = 0;
        return 0;
    }
    *param_3 = 1;
    return 0;
}
// 0x571ce0 — observed shape
uint32_t FUN_00571ce0(void* self, int32_t* param_1) {
    uint32_t uVar1;
    uint32_t uVar2;
    int32_t* piVar3;
    int32_t base = reinterpret_cast<int32_t>(self);

    if (*param_1 == 0) {
        return 0xffffffffu;
    }
    uVar1 = *reinterpret_cast<uint32_t*>(base + 0xc);
    uVar2 = 0;
    if (uVar1 != 0) {
        piVar3 = *reinterpret_cast<int32_t**>(base + 4);
        do {
            if (*piVar3 == 0) {
                (*reinterpret_cast<int32_t**>(base + 4))[uVar2] = *param_1;
                *reinterpret_cast<int32_t*>(base + 0x10) = *reinterpret_cast<int32_t*>(base + 0x10) + 1;
                return uVar2;
            }
            uVar2 = uVar2 + 1;
            piVar3 = piVar3 + 1;
        } while (uVar2 < *reinterpret_cast<uint32_t*>(base + 0xc));
    }
    if (*reinterpret_cast<uint32_t*>(base + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(base + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, param_1);
    return uVar1;
}

// 0x571d50 — observed shape
int32_t FUN_00571d50(int32_t param_1, int32_t param_2, uint8_t param_3, int32_t param_4) {
    int32_t iVar1;
    int32_t iVar2;
    char cVar3;
    int32_t* piVar4;

    iVar1 = param_1;
    cVar3 = FUN_005bd960(param_1, &param_1);
    if (cVar3 == '\0' || param_1 == 0) {
        return 2;
    }
    piVar4 = reinterpret_cast<int32_t*>(FUN_00533c78(0x34));
    iVar2 = param_2;
    if (piVar4 == nullptr) {
        piVar4 = nullptr;
    } else {
        piVar4[0] = iVar1;
        piVar4[1] = param_2;
        *reinterpret_cast<uint8_t*>(piVar4 + 2) = param_3;
        piVar4[3] = param_4;
        piVar4[4] = static_cast<int32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c3ee4));
        piVar4[6] = 0;
        piVar4[9] = 1;
        piVar4[7] = 0;
        piVar4[8] = 0;
        piVar4[5] = 0;
        piVar4[10] = 0;
        piVar4[0xb] = 0;
        piVar4[0xc] = 0;
    }
    cVar3 = FUN_005bd960(param_2, reinterpret_cast<int32_t*>(&param_3));
    if (cVar3 != '\0' && param_3 != 0) {
        FUN_00571850();
        ::operator delete(reinterpret_cast<void*>(static_cast<intptr_t>(param_3)));
    }
    FUN_00545310(iVar2, piVar4);
    return 0;
}

// 0x571e10 — observed shape
int32_t FUN_00571e10(int32_t param_1, uint32_t param_2, int32_t param_3, int32_t param_4) {
    int32_t iVar1;
    int32_t iVar2;
    char cVar3;
    int32_t iVar4;

    cVar3 = FUN_005bd960(param_1, &param_1);
    if (cVar3 == '\0' || param_1 == 0) {
        return 2;
    }
    cVar3 = FUN_005bd960(static_cast<int32_t>(param_2), &param_1);
    iVar2 = param_4;
    iVar1 = param_3;
    if (cVar3 == '\0' || param_1 == 0) {
        return 3;
    }
    if (param_3 == 0 && param_4 == 0) {
        return 5;
    }
    iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(8)));
    if (iVar4 == 0) {
        param_1 = 0;
        FUN_00571ce0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar1)), &param_1);
        return 0;
    }
    param_1 = static_cast<int32_t>(FUN_005711b0(iVar1, iVar2));
    FUN_00571ce0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar1)), &param_1);
    return 0;
}

// 0x571ed0 — observed shape
void FUN_00571ed0(void* self) {
    int32_t* piVar1;
    void* pvVar2;
    uint32_t uVar3;
    int32_t iVar4;
    uint32_t* puVar5;
    int32_t* piVar6;
    int32_t* piVar7;
    int32_t base = reinterpret_cast<int32_t>(self);

    ::operator delete[](*reinterpret_cast<void**>(base + 4));
    ::operator delete[](*reinterpret_cast<void**>(base + 8));
    piVar1 = reinterpret_cast<int32_t*>(base + 0x10);
    uVar3 = 0;
    if (*reinterpret_cast<uint32_t*>(base + 0x14) != 0) {
        piVar6 = *reinterpret_cast<int32_t**>(base + 0x18);
        do {
            if (*piVar6 != 0) {
                piVar6 = (*reinterpret_cast<int32_t**>(base + 0x18))[uVar3];
                goto joined_r0x00571f13;
            }
            uVar3 = uVar3 + 1;
            piVar6 = piVar6 + 1;
        } while (uVar3 < *reinterpret_cast<uint32_t*>(base + 0x14));
    }
    piVar6 = nullptr;
joined_r0x00571f13:
    for (;;) {
        if (piVar6 == nullptr) {
            *piVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c3f3c));
            FUN_005e1490();
            *piVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c3ee8));
            FUN_005e1490();
            ::operator delete[](*reinterpret_cast<void**>(base + 0x18));
            return;
        }
        piVar7 = reinterpret_cast<int32_t*>(piVar6[0]);
        pvVar2 = reinterpret_cast<void*>(static_cast<intptr_t>(piVar6[2]));
        if (piVar7 == nullptr) {
            using Fn = int32_t(*)(int32_t);
            iVar4 = (*reinterpret_cast<Fn*>(*piVar1 + 4))(piVar6[1]);
            uVar3 = static_cast<uint32_t>(iVar4) + 1;
            if (uVar3 < *reinterpret_cast<uint32_t*>(base + 0x14)) {
                puVar5 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(base + 0x18) + uVar3 * 4);
                do {
                    piVar7 = reinterpret_cast<int32_t*>(puVar5[0]);
                    if (piVar7 != nullptr) {
                        goto LAB_00571f50;
                    }
                    uVar3 = uVar3 + 1;
                    puVar5 = puVar5 + 1;
                } while (uVar3 < *reinterpret_cast<uint32_t*>(base + 0x14));
            }
            piVar7 = nullptr;
        }
LAB_00571f50:
        piVar6 = piVar7;
        if (pvVar2 != nullptr) {
            FUN_00571850();
            ::operator delete(pvVar2);
        }
    }
}

// 0x571fa0 — observed shape
int32_t FUN_00571fa0(void* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    void* pvVar1;
    void* pvVar2;
    char cVar3;
    int32_t iVar4;
    uint32_t uVar5;

    iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x20)));
    pvVar1 = param_1;
    if (iVar4 == 0) {
        uVar5 = 0;
    } else {
        uVar5 = FUN_00571760(param_1, param_2, param_3, param_4);
    }
    cVar3 = FUN_005bd960(static_cast<int32_t>(reinterpret_cast<intptr_t>(pvVar1)),
                         reinterpret_cast<int32_t*>(&param_1));
    pvVar2 = param_1;
    if (cVar3 != '\0' && param_1 != nullptr) {
        FUN_00571ed0(pvVar2);
        ::operator delete(pvVar2);
    }
    FUN_00545310(static_cast<int32_t>(reinterpret_cast<intptr_t>(pvVar1)),
                 reinterpret_cast<void*>(static_cast<intptr_t>(uVar5)));
    return 0;
}
// 0x5732f0 — observed shape
void FUN_005732f0(void* self) {
    int32_t* piVar1;
    void* pvVar2;
    uint32_t uVar3;
    int32_t iVar4;
    uint32_t* puVar5;
    int32_t* piVar6;
    int32_t* piVar7;
    int32_t* piVar8;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);

    in_ECX[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c3f90));
    ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[2])));
    ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[3])));
    ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[0xd])));
    ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[0xe])));
    piVar1 = reinterpret_cast<int32_t*>(in_ECX + 4);
    uVar3 = 0;
    if (in_ECX[5] != 0) {
        piVar6 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(in_ECX[6]));
        do {
            if (*piVar6 != 0) {
                piVar6 = reinterpret_cast<int32_t**>(static_cast<intptr_t>(in_ECX[6]))[uVar3];
                goto joined_r0x00573353;
            }
            uVar3 = uVar3 + 1;
            piVar6 = piVar6 + 1;
        } while (uVar3 < in_ECX[5]);
    }
    piVar6 = nullptr;
joined_r0x00573353:
    while (piVar6 != nullptr) {
        piVar7 = reinterpret_cast<int32_t*>(piVar6[0]);
        pvVar2 = reinterpret_cast<void*>(static_cast<intptr_t>(piVar6[2]));
        if (piVar7 == nullptr) {
            using Fn = int32_t(*)(int32_t);
            iVar4 = (*reinterpret_cast<Fn*>(*piVar1 + 4))(piVar6[1]);
            uVar3 = static_cast<uint32_t>(iVar4) + 1;
            if (uVar3 < in_ECX[5]) {
                puVar5 = reinterpret_cast<uint32_t*>(in_ECX[6] + uVar3 * 4);
                do {
                    piVar7 = reinterpret_cast<int32_t*>(puVar5[0]);
                    if (piVar7 != nullptr) {
                        goto LAB_00573391;
                    }
                    uVar3 = uVar3 + 1;
                    puVar5 = puVar5 + 1;
                } while (uVar3 < in_ECX[5]);
            }
            piVar7 = nullptr;
        }
LAB_00573391:
        piVar6 = piVar7;
        if (pvVar2 != nullptr) {
            FUN_00571ed0(pvVar2);
            ::operator delete(pvVar2);
        }
    }
    piVar6 = reinterpret_cast<int32_t*>(in_ECX + 8);
    uVar3 = 0;
    if (in_ECX[9] != 0) {
        piVar7 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(in_ECX[10]));
        do {
            if (*piVar7 != 0) {
                piVar7 = reinterpret_cast<int32_t**>(static_cast<intptr_t>(in_ECX[10]))[uVar3];
                goto joined_r0x005733d3;
            }
            uVar3 = uVar3 + 1;
            piVar7 = piVar7 + 1;
        } while (uVar3 < in_ECX[9]);
    }
    piVar7 = nullptr;
joined_r0x005733d3:
    for (;;) {
        if (piVar7 == nullptr) {
            *piVar6 = static_cast<int32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c3f74));
            FUN_005e1490();
            *piVar6 = static_cast<int32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c3f20));
            FUN_005e1490();
            ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[10])));
            *piVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c3f58));
            FUN_005e1490();
            *piVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c3f04));
            FUN_005e1490();
            ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[6])));
            in_ECX[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_LAB_006fd148));
            DAT_00727444 = DAT_00727444 + -1;
            return;
        }
        piVar8 = reinterpret_cast<int32_t*>(piVar7[0]);
        pvVar2 = reinterpret_cast<void*>(static_cast<intptr_t>(piVar7[2]));
        if (piVar8 == nullptr) {
            using Fn = int32_t(*)(int32_t);
            iVar4 = (*reinterpret_cast<Fn*>(*piVar6 + 4))(piVar7[1]);
            uVar3 = static_cast<uint32_t>(iVar4) + 1;
            if (uVar3 < in_ECX[9]) {
                puVar5 = reinterpret_cast<uint32_t*>(in_ECX[10] + uVar3 * 4);
                do {
                    piVar8 = reinterpret_cast<int32_t*>(puVar5[0]);
                    if (piVar8 != nullptr) {
                        goto LAB_00573410;
                    }
                    uVar3 = uVar3 + 1;
                    puVar5 = puVar5 + 1;
                } while (uVar3 < in_ECX[9]);
            }
            piVar8 = nullptr;
        }
LAB_00573410:
        piVar7 = piVar8;
        if (pvVar2 != nullptr) {
            ::operator delete[](*reinterpret_cast<void**>(static_cast<intptr_t>(pvVar2) + 4));
            ::operator delete[](*reinterpret_cast<void**>(static_cast<intptr_t>(pvVar2) + 0x14));
            ::operator delete[](*reinterpret_cast<void**>(static_cast<intptr_t>(pvVar2) + 8));
            ::operator delete(pvVar2);
        }
    }
}

// 0x5734b0 — observed shape
void FUN_005734b0(void* self, uint8_t param_1) {
    FUN_005732f0(self);
    if ((param_1 & 1) != 0) {
        ::operator delete(self);
    }
}

// 0x5734e0 — observed shape
void FUN_005734e0(void* self) {
    int32_t* piVar1;
    uint32_t* puVar2;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);

    in_ECX[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c41f8));
    puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(in_ECX[0x12]));
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(*)(int32_t);
            (*reinterpret_cast<Fn*>(puVar2[0]))(1);
        }
        in_ECX[0x12] = 0;
    }
    puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(in_ECX[0x12]));
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(*)(int32_t);
            (*reinterpret_cast<Fn*>(puVar2[0]))(1);
        }
    }
    FUN_00552d20();
}

// 0x573560 — observed shape
void FUN_00573560(void* self) {
    float fVar1;
    int32_t iVar2;
    float* pfVar3;
    uint32_t uVar4;
    int32_t base;
    uint32_t uVar5;
    int32_t iVar6;
    int32_t iVar7;
    int32_t iVar8;

    base = reinterpret_cast<int32_t>(self);
    iVar6 = *reinterpret_cast<int32_t*>(base + 0x48);
    if (iVar6 == 0) {
        uVar5 = 0;
    } else {
        uVar5 = *reinterpret_cast<uint32_t*>(iVar6 + 0xc);
    }
    *reinterpret_cast<uint32_t*>(base + 0x18) = 0x7f7fffff;
    uVar4 = 0;
    *reinterpret_cast<uint32_t*>(base + 0x1c) = 0xff7fffff;
    if (3 < static_cast<int32_t>(uVar5)) {
        iVar8 = 0;
        iVar7 = static_cast<int32_t>((uVar5 - 4 >> 2) + 1);
        uVar4 = static_cast<uint32_t>(iVar7 * 4);
        do {
            iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar6 + 0x14) + 4 + iVar8);
            if (iVar2 != 0) {
                pfVar3 = *reinterpret_cast<float**>(*reinterpret_cast<int32_t*>(iVar6 + 0x14) + iVar8 + 0xc);
                fVar1 = *reinterpret_cast<float*>(static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<int32_t>(pfVar3) + 4)) * static_cast<uint32_t>(iVar2 + -1) + reinterpret_cast<int32_t>(pfVar3));
                if (*pfVar3 < *reinterpret_cast<float*>(base + 0x18)) {
                    *reinterpret_cast<float*>(base + 0x18) = *pfVar3;
                }
                if (*reinterpret_cast<float*>(base + 0x1c) < fVar1) {
                    *reinterpret_cast<float*>(base + 0x1c) = fVar1;
                }
            }
            iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar6 + 0x14) + 0x18 + iVar8);
            if (iVar2 != 0) {
                pfVar3 = *reinterpret_cast<float**>(*reinterpret_cast<int32_t*>(iVar6 + 0x14) + iVar8 + 0x20);
                fVar1 = *reinterpret_cast<float*>(static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<int32_t>(pfVar3) + 4)) * static_cast<uint32_t>(iVar2 + -1) + reinterpret_cast<int32_t>(pfVar3));
                if (*pfVar3 < *reinterpret_cast<float*>(base + 0x18)) {
                    *reinterpret_cast<float*>(base + 0x18) = *pfVar3;
                }
                if (*reinterpret_cast<float*>(base + 0x1c) < fVar1) {
                    *reinterpret_cast<float*>(base + 0x1c) = fVar1;
                }
            }
            iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar6 + 0x14) + 0x2c + iVar8);
            if (iVar2 != 0) {
                pfVar3 = *reinterpret_cast<float**>(*reinterpret_cast<int32_t*>(iVar6 + 0x14) + iVar8 + 0x34);
                fVar1 = *reinterpret_cast<float*>(static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<int32_t>(pfVar3) + 4)) * static_cast<uint32_t>(iVar2 + -1) + reinterpret_cast<int32_t>(pfVar3));
                if (*pfVar3 < *reinterpret_cast<float*>(base + 0x18)) {
                    *reinterpret_cast<float*>(base + 0x18) = *pfVar3;
                }
                if (*reinterpret_cast<float*>(base + 0x1c) < fVar1) {
                    *reinterpret_cast<float*>(base + 0x1c) = fVar1;
                }
            }
            iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar6 + 0x14) + 0x40 + iVar8);
            if (iVar2 != 0) {
                pfVar3 = *reinterpret_cast<float**>(*reinterpret_cast<int32_t*>(iVar6 + 0x14) + iVar8 + 0x48);
                fVar1 = *reinterpret_cast<float*>(static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<int32_t>(pfVar3) + 4)) * static_cast<uint32_t>(iVar2 + -1) + reinterpret_cast<int32_t>(pfVar3));
                if (*pfVar3 < *reinterpret_cast<float*>(base + 0x18)) {
                    *reinterpret_cast<float*>(base + 0x18) = *pfVar3;
                }
                if (*reinterpret_cast<float*>(base + 0x1c) < fVar1) {
                    *reinterpret_cast<float*>(base + 0x1c) = fVar1;
                }
            }
            iVar8 = iVar8 + 0x50;
            iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
    }
    if (uVar4 < uVar5) {
        iVar7 = static_cast<int32_t>(uVar4 * 0x14);
        iVar6 = static_cast<int32_t>(uVar5 - uVar4);
        do {
            iVar8 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(base + 0x48) + 0x14);
            iVar2 = *reinterpret_cast<int32_t*>(iVar8 + 4 + iVar7);
            if (iVar2 != 0) {
                pfVar3 = *reinterpret_cast<float**>(iVar8 + iVar7 + 0xc);
                fVar1 = *reinterpret_cast<float*>(reinterpret_cast<int32_t>(pfVar3) + static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<int32_t>(pfVar3) + 4)) * static_cast<uint32_t>(iVar2 + -1));
                if (*pfVar3 < *reinterpret_cast<float*>(base + 0x18)) {
                    *reinterpret_cast<float*>(base + 0x18) = *pfVar3;
                }
                if (*reinterpret_cast<float*>(base + 0x1c) < fVar1) {
                    *reinterpret_cast<float*>(base + 0x1c) = fVar1;
                }
            }
            iVar7 = iVar7 + 0x14;
            iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
    }
}

// 0x573750 — observed shape
void FUN_00573750(void* self, uint32_t param_1) {
    char cVar1;
    int32_t base = reinterpret_cast<int32_t>(self);

    if (*reinterpret_cast<int32_t*>(base + 0x48) != 0) {
        cVar1 = FUN_00568540(param_1);
        if (cVar1 == '\0' || *reinterpret_cast<char*>(base + 0x4e) != '\0') {
            *reinterpret_cast<uint8_t*>(base + 0x4c) = 1;
        }
    }
}

// 0x573780 — observed shape
void FUN_00573780(void* self, uint32_t param_1) {
    uint32_t uVar1;
    int32_t iVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    int32_t iVar5;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    uint32_t uVar6;
    int32_t iVar7;
    uint32_t* puVar8;
    long double fVar9;
    float fStack_10;

    {
        using Fn = uint32_t* (*)();
        puVar3 = (*reinterpret_cast<Fn*>(in_ECX[0] + 0x68))();
    }
    uVar1 = *reinterpret_cast<uint32_t*>(in_ECX[0x12] + 0xc);
    uVar4 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(*reinterpret_cast<int32_t*>(in_ECX[0xd] + 0xbc) + 0xc));
    if (*reinterpret_cast<char*>(reinterpret_cast<int32_t>(in_ECX) + 0x4d) == '\0') {
        puVar8 = puVar3;
        for (uVar6 = uVar4 * 0xc >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
        }
        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *reinterpret_cast<uint8_t*>(puVar8) = 0;
            puVar8 = reinterpret_cast<uint32_t*>(reinterpret_cast<int32_t>(puVar8) + 1);
        }
    }
    uVar6 = 0;
    if (uVar1 != 0) {
        do {
            if (uVar6 == 0 && *reinterpret_cast<char*>(in_ECX[0x12] + 0x18) != '\0') {
                if (*reinterpret_cast<char*>(reinterpret_cast<int32_t>(in_ECX) + 0x4d) == '\0') {
                    fStack_10 = 1.0f;
                    goto LAB_00573844;
                }
            } else {
                iVar7 = static_cast<int32_t>(in_ECX[0x12]);
                iVar5 = static_cast<int32_t>(uVar6 * 0x14);
                iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar7 + 0x14) + 4 + iVar5);
                if (iVar2 != 0) {
                    fVar9 = FUN_0056a5f0(param_1,
                                         *reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(iVar7 + 0x14) + iVar5 + 0xc),
                                         *reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(iVar7 + 0x14) + 8 + iVar5),
                                         iVar2,
                                         *reinterpret_cast<int32_t*>(iVar7 + 0x14) + 0x10 + iVar5);
                    fStack_10 = static_cast<float>(fVar9);
                    if (fStack_10 != 0.0f) {
                        goto LAB_00573844;
                    }
                }
            }
            uVar6 = uVar6 + 1;
            continue;
LAB_00573844:
            FUN_0053f150(puVar3, fStack_10,
                         *reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(in_ECX[0x12] + 0x14) + uVar6 * 0x14),
                         uVar4);
            uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
    }
}

// 0x573880 — observed shape
void FUN_00573880(int32_t* param_1, uint32_t param_2, void* self) {
    int32_t* piVar1;
    uint32_t* puVar2;
    int32_t iVar3;
    uint32_t* puVar4;
    int32_t base = reinterpret_cast<int32_t>(self);

    FUN_00552aa0(param_1, param_2);
    *reinterpret_cast<uint16_t*>(reinterpret_cast<int32_t>(param_1) + 0x44) = *reinterpret_cast<uint16_t*>(base + 0x44);
    puVar2 = *reinterpret_cast<uint32_t**>(base + 0x48);
    if (puVar2 != nullptr) {
        iVar3 = param_1[0xd];
        puVar4 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(param_1[0x12]));
        if (puVar4 != puVar2) {
            if (puVar4 != nullptr) {
                piVar1 = reinterpret_cast<int32_t*>(puVar4 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Fn = void(*)(int32_t);
                    (*reinterpret_cast<Fn*>(puVar4[0]))(1);
                }
            }
            param_1[0x12] = static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar2));
            if (puVar2 != nullptr) {
                puVar2[1] = puVar2[1] + 1;
            }
        }
        if (iVar3 != 0) {
            using Fn = void(*)();
            (*reinterpret_cast<Fn*>(param_1[0] + 0x6c))();
        }
    }
    if (DAT_007283d4 != '\0') {
        *reinterpret_cast<uint8_t*>(base + 0x4e) = 1;
        *reinterpret_cast<uint8_t*>(reinterpret_cast<int32_t>(param_1) + 0x4e) = 1;
    }
}

// 0x5738f0 — observed shape
void FUN_005738f0(void* self, int32_t param_1) {
    uint16_t uVar1;
    int32_t iVar2;
    int32_t base = reinterpret_cast<int32_t>(self);
    int32_t unaff_SI = 0;

    iVar2 = param_1;
    FUN_00552f70(param_1);
    uVar1 = DAT_00727c5c;
    if (*reinterpret_cast<uint32_t*>(iVar2 + 0x1c) < 0xa000102u) {
        *reinterpret_cast<uint16_t*>(base + 0x44) = DAT_00727c5c;
        *reinterpret_cast<uint16_t*>(base + 0x44) = static_cast<uint16_t>(uVar1 >> 5 & 0x3f);
    } else {
        using Fn = void(*)(int32_t, int32_t);
        (*reinterpret_cast<Fn*>(*reinterpret_cast<int32_t*>(iVar2 + 0x15c) + 8))(base + 0x44, 2);
    }
    FUN_00545cc0();
    if (0x4000001u < *reinterpret_cast<uint32_t*>(iVar2 + 0x1c)) {
        using Fn = void(*)(int32_t*, int32_t);
        (*reinterpret_cast<Fn*>(*reinterpret_cast<int32_t*>(iVar2 + 0x15c) + 8))(&param_1, 1);
        *reinterpret_cast<bool*>(base + 0x4e) = unaff_SI != '\0';
    }
}

// 0x573970 — observed shape
void FUN_00573970(void* self, int32_t param_1) {
    int32_t* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);

    FUN_00553060(param_1);
    if (in_ECX[0xd] == 0) {
        puVar3 = reinterpret_cast<uint32_t*>(FUN_00545600());
        puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(in_ECX[0x12]));
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Fn = void(*)(int32_t);
                    (*reinterpret_cast<Fn*>(puVar2[0]))(1);
                }
            }
            in_ECX[0x12] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar3));
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    } else {
        puVar3 = reinterpret_cast<uint32_t*>(FUN_00545600());
        puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(in_ECX[0x12]));
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Fn = void(*)(int32_t);
                    (*reinterpret_cast<Fn*>(puVar2[0]))(1);
                }
            }
            in_ECX[0x12] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar3));
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
        {
            using Fn = void(*)();
            (*reinterpret_cast<Fn*>(in_ECX[0] + 0x6c))();
        }
        *reinterpret_cast<uint8_t*>(reinterpret_cast<int32_t>(in_ECX) + 0x4f) = 1;
    }
    if (in_ECX[0x12] != 0 && *reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0x401000du) {
        using Fn = void(*)(uint32_t, uint32_t);
        (*reinterpret_cast<Fn*>(in_ECX[0] + 0x54))(in_ECX[6], in_ECX[7]);
    }
}

// 0x573a10 — observed shape
void FUN_00573a10(int32_t* param_1, void* self) {
    int32_t base = reinterpret_cast<int32_t>(self);
    uint8_t auStackY_9c[128];

    FUN_005530e0(param_1);
    {
        using Fn = void(*)(int32_t, int32_t);
        (*reinterpret_cast<Fn*>(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(base + 0x44, 2);
    }
    {
        using Fn = void(*)(uint32_t);
        (*reinterpret_cast<Fn*>(param_1[0] + 0x2c))(*reinterpret_cast<uint32_t*>(base + 0x48));
    }
    {
        using Fn = void(*)(uint8_t*, int32_t);
        (*reinterpret_cast<Fn*>(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(auStackY_9c + 0x94, 1);
    }
}
