// Reconstruction batch mass_0173 — Sid Meier's Pirates! (2004), PE32 i386.
// Ghidra 12.2 pseudocode candidates. Register receivers become explicit
// void* self parameters. Field offsets, constants, call order, return
// shapes and conditional structure follow the supplied listings.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers (only those used by the assigned listings)
// ---------------------------------------------------------------------------
extern void FUN_00552c80();
extern void FUN_00552d20();
extern void FUN_00552b70(int32_t param_1);
extern uint32_t FUN_00552b90(int32_t param_1);
extern uint32_t FUN_00552bc0(int32_t param_1);
extern void FUN_00573560(void* self);
extern void FUN_0056fbf0(int32_t param_1, int32_t param_2);
extern void FUN_0056e810(int32_t param_1);
extern void FUN_00570f30(int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4);
extern void FUN_00570a30(int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4);
extern void FUN_0056fce0();
extern void FUN_0056fd40(int32_t param_1, int32_t param_2, int32_t param_3);
extern void FUN_0056e8c0(int32_t param_1);
extern void FUN_005e1490();
extern void FUN_00570970(int32_t param_1);
extern void FUN_0053cca0();
extern void FUN_005aead0(void* param_1, void* param_2, void* param_3);
extern char FUN_005bd960(int32_t param_1, void* param_2);

// Release helpers referenced by the listings as operator_delete/operator_delete__.
void operator delete(void* ptr) noexcept;
void operator delete[](void* ptr) noexcept;

// vtable image pointers installed by the listed functions
extern void* PTR_FUN_006c41f8;
extern void* PTR_FUN_006c42b4;
extern void* PTR_FUN_006c4298;
extern void* PTR_FUN_006c427c;

// ---------------------------------------------------------------------------
// Self-referential helpers defined in this batch (declared first so call
// order inside the file is free)
// ---------------------------------------------------------------------------
extern void FUN_00573c00(void* self);

// 0x573a60 — observed shape
void FUN_00573a60(void* self, int32_t param_1) {
    int32_t base = reinterpret_cast<int32_t>(self);

    FUN_00552c80();
    *reinterpret_cast<void**>(base) = &PTR_FUN_006c41f8;
    *reinterpret_cast<int32_t*>(base + 0x48) = param_1;
    if (param_1 != 0) {
        *reinterpret_cast<int32_t*>(param_1 + 4) = *reinterpret_cast<int32_t*>(param_1 + 4) + 1;
    }
    *reinterpret_cast<uint16_t*>(base + 0x44) = 0;
    if (param_1 != 0) {
        FUN_00573560(self);
    }
    *reinterpret_cast<uint8_t*>(base + 0x4c) = 0;
    *reinterpret_cast<uint8_t*>(base + 0x4d) = 0;
    *reinterpret_cast<uint8_t*>(base + 0x4e) = 0;
    *reinterpret_cast<uint8_t*>(base + 0x4f) = 0;
    return;
}

// 0x573ab0 — observed shape
void FUN_00573ab0(void* self, uint8_t param_1) {
    int32_t* piVar1;
    uint32_t* puVar2;
    int32_t base = reinterpret_cast<int32_t>(self);

    *reinterpret_cast<void**>(base) = &PTR_FUN_006c41f8;
    puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(base + 0x48)));
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(*)(int32_t);
            (*reinterpret_cast<Fn*>(puVar2[0]))(1);
        }
        *reinterpret_cast<int32_t*>(base + 0x48) = 0;
    }
    puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(base + 0x48)));
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(*)(int32_t);
            (*reinterpret_cast<Fn*>(puVar2[0]))(1);
        }
    }
    FUN_00552d20();
    if ((param_1 & 1) != 0) {
        ::operator delete(self);
    }
    return;
}

// 0x573b10 — observed shape
void FUN_00573b10(int32_t param_1, int32_t param_2, int32_t param_3) {
    (void)param_1;
    FUN_0056fbf0(param_2, param_3);
    return;
}

// 0x573b30 — observed shape
uint8_t FUN_00573b30(void) {
    FUN_0056e810(1);
    return 1;
}

// 0x573b40 — observed shape
void FUN_00573b40(int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4,
                  int32_t param_5) {
    (void)param_1;
    FUN_00570f30(param_2, param_3, param_4, param_5);
    return;
}

// 0x573b60 — observed shape
void FUN_00573b60(int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4,
                  int32_t param_5) {
    (void)param_1;
    FUN_00570a30(param_2, param_3, param_4, param_5);
    return;
}

// 0x573b80 — observed shape
void FUN_00573b80(void) {
    FUN_0056fce0();
    return;
}

// 0x573b90 — observed shape
void FUN_00573b90(int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4) {
    (void)param_1;
    FUN_0056fd40(param_2, param_3, param_4);
    return;
}

// 0x573bb0 — observed shape
void FUN_00573bb0(int32_t param_1, int32_t param_2) {
    (void)param_1;
    FUN_0056e8c0(param_2);
    return;
}

// 0x573bd0 — observed shape
void FUN_00573bd0(void* self, uint32_t* param_1, uint32_t* param_2) {
    int32_t iVar1;
    uint32_t* puVar2;
    int32_t base = reinterpret_cast<int32_t>(self);

    puVar2 = reinterpret_cast<uint32_t*>(base + 0x74);
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_1 = *puVar2;
        puVar2 = puVar2 + 1;
        param_1 = param_1 + 1;
    }
    *param_2 = *reinterpret_cast<uint32_t*>(base + 0x98);
    param_2[1] = *reinterpret_cast<uint32_t*>(base + 0x9c);
    param_2[2] = *reinterpret_cast<uint32_t*>(base + 0xa0);
    return;
}

// 0x573c00 — observed shape
void FUN_00573c00(void* self) {
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    uint32_t uVar3;

    *in_ECX = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c42b4));
    uVar3 = 0;
    if ((*reinterpret_cast<char*>(in_ECX + 4) != '\0') && (in_ECX[1] != 0)) {
        do {
            puVar2 = reinterpret_cast<uint32_t*>(
                static_cast<intptr_t>(*reinterpret_cast<int32_t*>(in_ECX[2] + uVar3 * 4)));
            while (puVar2 != nullptr) {
                puVar1 = puVar2 + 1;
                puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*puVar2));
                ::operator delete[](*reinterpret_cast<void**>(puVar1));
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < in_ECX[1]);
    }
    *in_ECX = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c4298));
    FUN_005e1490();
    *in_ECX = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c427c));
    FUN_005e1490();
    ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[2])));
    return;
}

// 0x573c80 — observed shape
void FUN_00573c80(void* self, uint8_t param_1) {
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);

    *in_ECX = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c427c));
    FUN_005e1490();
    ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[2])));
    if ((param_1 & 1) != 0) {
        ::operator delete(in_ECX);
    }
    return;
}

// 0x573cc0 — observed shape
void FUN_00573cc0(void* self, uint8_t param_1) {
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);

    *in_ECX = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c4298));
    FUN_005e1490();
    *in_ECX = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_006c427c));
    FUN_005e1490();
    ::operator delete[](reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[2])));
    if ((param_1 & 1) != 0) {
        ::operator delete(in_ECX);
    }
    return;
}

// 0x573d00 — observed shape
void FUN_00573d00(void* self, uint8_t param_1) {
    FUN_00573c00(self);
    if ((param_1 & 1) != 0) {
        ::operator delete(self);
    }
    return;
}

// 0x573d20 — observed shape
void FUN_00573d20(void* self, int32_t param_1) {
    int32_t base = reinterpret_cast<int32_t>(self);
    uint32_t uVar1;

    uVar1 = 0;
    if (*reinterpret_cast<int32_t*>(base + 0x50) != 0) {
        do {
            if (*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(base + 0x48) + uVar1 * 4) != 0) {
                FUN_00570970(param_1);
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < *reinterpret_cast<uint32_t*>(base + 0x50));
    }
    return;
}

// 0x573d50 — observed shape
void FUN_00573d50(void* self) {
    int32_t base = reinterpret_cast<int32_t>(self);
    uint32_t uVar1;

    uVar1 = 0;
    if (*reinterpret_cast<int32_t*>(base + 0x50) != 0) {
        do {
            if (*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(base + 0x48) + uVar1 * 4) != 0) {
                FUN_0056e810(1);
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < *reinterpret_cast<uint32_t*>(base + 0x50));
    }
    return;
}

// 0x573d80 — observed shape
void FUN_00573d80(void* self, float* param_1, uint32_t* param_2) {
    float fVar1;
    float fVar2;
    int32_t iVar3;
    float* pfVar4;
    int32_t base = reinterpret_cast<int32_t>(self);

    pfVar4 = reinterpret_cast<float*>(base + 0x74);
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar4 = *param_1;
        param_1 = param_1 + 1;
        pfVar4 = pfVar4 + 1;
    }
    *reinterpret_cast<uint32_t*>(base + 0x98) = *param_2;
    *reinterpret_cast<uint32_t*>(base + 0x9c) = param_2[1];
    *reinterpret_cast<uint32_t*>(base + 0xa0) = param_2[2];
    fVar1 = *reinterpret_cast<float*>(base + 0x74);
    fVar2 = *reinterpret_cast<float*>(*reinterpret_cast<int32_t*>(base + 0x34) + 0x68);
    if ((0.01f < fabsf((*reinterpret_cast<float*>(base + 0x80) * *reinterpret_cast<float*>(base + 0x80) +
                        fVar1 * fVar1 +
                        *reinterpret_cast<float*>(base + 0x8c) * *reinterpret_cast<float*>(base + 0x8c)) - fVar2)) ||
        (0.01f < fabsf((*reinterpret_cast<float*>(base + 0x84) * *reinterpret_cast<float*>(base + 0x84) +
                        *reinterpret_cast<float*>(base + 0x78) * *reinterpret_cast<float*>(base + 0x78) +
                        *reinterpret_cast<float*>(base + 0x90) * *reinterpret_cast<float*>(base + 0x90)) - fVar2)) ||
        (0.01f < fabsf((*reinterpret_cast<float*>(base + 0x88) * *reinterpret_cast<float*>(base + 0x88) +
                        *reinterpret_cast<float*>(base + 0x7c) * *reinterpret_cast<float*>(base + 0x7c) +
                        *reinterpret_cast<float*>(base + 0x94) * *reinterpret_cast<float*>(base + 0x94)) - fVar2))) {
        FUN_0053cca0();
    }
    return;
}

// 0x573e80 — observed shape
void FUN_00573e80(void* self, int32_t param_1) {
    int32_t* piVar1;
    int32_t base = reinterpret_cast<int32_t>(self);
    uint32_t uVar2;

    FUN_00552b70(param_1);
    uVar2 = 0;
    if (*reinterpret_cast<int32_t*>(base + 0x50) != 0) {
        do {
            piVar1 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(base + 0x48) + uVar2 * 4);
            if (piVar1 != nullptr) {
                using Fn = void(*)(int32_t);
                (*reinterpret_cast<Fn*>(*piVar1 + 0x28))(param_1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *reinterpret_cast<uint32_t*>(base + 0x50));
    }
    return;
}

// 0x573ec0 — observed shape
uint32_t FUN_00573ec0(void* self, int32_t param_1) {
    int32_t* piVar1;
    uint32_t uVar2;
    int32_t base = reinterpret_cast<int32_t>(self);
    uint32_t uVar3;
    uint32_t uVar4;

    uVar2 = FUN_00552b90(param_1);
    if (static_cast<char>(uVar2) == '\0') {
        return uVar2;
    }
    uVar4 = 0;
    uVar3 = 0;
    if (*reinterpret_cast<int32_t*>(base + 0x50) != 0) {
        do {
            piVar1 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(base + 0x48) + uVar4 * 4);
            if (piVar1 != nullptr) {
                using Fn = void(*)(int32_t);
                (*reinterpret_cast<Fn*>(*piVar1 + 0x14))(param_1);
            }
            uVar3 = *reinterpret_cast<uint32_t*>(base + 0x50);
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar3);
    }
    return (uVar3 & 0xffffff00u) | 1u;
}

// 0x573f50 — observed shape
uint32_t FUN_00573f50(void* self, int32_t param_1) {
    int32_t* piVar1;
    int32_t* piVar4;
    int32_t iVar2;
    int32_t base = reinterpret_cast<int32_t>(self);
    uint32_t uVar3;
    uint32_t uVar5;
    int32_t local_c;
    uint8_t local_8[4];
    uint8_t local_4[4];

    iVar2 = param_1;
    uVar3 = FUN_00552bc0(param_1);
    if (static_cast<char>(uVar3) == '\0') {
        return uVar3 & 0xffffff00u;
    }
    uVar3 = *reinterpret_cast<uint32_t*>(base + 0x50);
    if (uVar3 != *reinterpret_cast<uint32_t*>(iVar2 + 0x50)) {
        return uVar3 & 0xffffff00u;
    }
    uVar3 = 0;
    if (*reinterpret_cast<uint32_t*>(base + 0x60) != 0) {
        piVar4 = *reinterpret_cast<int32_t**>(base + 100);
        do {
            if (*piVar4 != 0) {
                param_1 = (*reinterpret_cast<int32_t**>(base + 100))[uVar3];
                goto joined_r0x00573fa9;
            }
            uVar3 = uVar3 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar3 < *reinterpret_cast<uint32_t*>(base + 0x60));
    }
    param_1 = 0;
joined_r0x00573fa9:
    for (;;) {
        if (param_1 == 0) {
            uVar5 = 0;
            uVar3 = 0;
            param_1 = 0;
            if (*reinterpret_cast<int32_t*>(base + 0x50) == 0) {
                goto LAB_0057402b;
            }
            goto LAB_00573ff0;
        }
        FUN_005aead0(&param_1, &local_c, local_8);
        piVar4 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(FUN_005bd960(local_c, local_4)));
        if (static_cast<char>(reinterpret_cast<intptr_t>(piVar4)) == '\0') {
            goto LAB_0057400e;
        }
    }
LAB_0057400e:
    return static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar4)) & 0xffffff00u;
LAB_00573ff0:
    piVar1 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(base + 0x48) + uVar5 * 4);
    piVar4 = *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t*>(iVar2 + 0x48) + uVar5 * 4);
    if ((piVar1 == nullptr) || (piVar4 == nullptr)) {
        if (piVar1 != piVar4) {
            goto LAB_0057400e;
        }
    } else {
        using Fn = int32_t(*)(int32_t*);
        piVar4 = reinterpret_cast<int32_t*>(
            (*reinterpret_cast<Fn*>(*piVar1 + 0x1c))(piVar4));
        if (static_cast<char>(reinterpret_cast<intptr_t>(piVar4)) == '\0') {
            goto LAB_0057400e;
        }
    }
    uVar3 = *reinterpret_cast<uint32_t*>(base + 0x50);
    uVar5 = uVar5 + 1;
    if (uVar3 <= uVar5) {
        goto LAB_0057402b;
    }
    goto LAB_00573ff0;
LAB_0057402b:
    return (uVar3 & 0xffffff00u) | 1u;
}
