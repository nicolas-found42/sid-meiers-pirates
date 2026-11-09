#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <windows.h>

// Extern helpers / globals observed in the listings.
extern uint32_t FUN_00533c78(size_t);
extern uint32_t thunk_FUN_00533c78(size_t);
extern uint32_t FUN_0051ffd0();
extern uint32_t FUN_004edfd0();
extern uint32_t FUN_005f0ddc(...);          // raw return bits; consumed as float/int/address
extern float FUN_004e2490(float);
extern long double FUN_00513cf0(float, float*);
extern float* FUN_004916d0(float*, float*);
extern void FUN_005200b0(void*);
extern void FUN_00520190(void*);
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_00533d10(uint32_t, uint32_t);
extern int* FUN_0054aad0();
extern uint32_t FUN_00539210(void*, int, void*, int);
extern void* FUN_00539cc0(void*, void*);
extern void* FUN_0053bb30(int);
extern char FUN_005108a0(uint32_t);
extern void FUN_004c3000();
extern void operator_delete__(void*);
extern void operator_delete(void*);

// Cross-batch entry points; the three trailing register artifacts
// (in_EAX / in_ECX / unaff_EDI, and the stack words of 0x513880) are
// inherited from the caller and are not materialised by the listings.
long double FUN_00513010(int param_1, float param_2, float param_3, float param_4,
                         int param_5, float* param_6,
                         float* in_EAX = nullptr, int in_ECX = 0, intptr_t unaff_EDI = 0);
int* FUN_00513880(int* param_1, uint32_t param_2, int param_3, int param_4,
                  int iStack_c = 0, int iStack_4 = 0, int unaff_retaddr = 0,
                  uint32_t* unaff_EDI = nullptr, int* piStack_8 = nullptr);

extern uint32_t DAT_008edcb8;   // overlaps smaller symbols at the same address
extern uint32_t DAT_008edcb0;
extern int32_t  DAT_008edcac;   // name buffer base ("FLandscape::CreateCell")
extern uint32_t DAT_008ca53c;
extern uint32_t DAT_008ea110;
extern uint32_t DAT_008edb88;
extern uint32_t DAT_008edb80;
extern uint32_t DAT_008edb78;
extern uint32_t DAT_008edb74;
extern uint32_t DAT_008eda50;
extern uint32_t DAT_00727560;
extern uint32_t DAT_007178c8;
extern uint32_t DAT_00727484;
extern uint32_t DAT_00717838;
extern uint32_t DAT_00717834;
extern uint32_t DAT_0071783c;
extern uint32_t DAT_0072745c;
extern uint32_t* DAT_008cad64;
extern uint32_t* DAT_008cad44;
extern uint32_t PTR_LAB_00711864;
extern uint32_t PTR_LAB_0071185c;
extern uint32_t PTR_FUN_00711994;

namespace {

// Observed shared-object protocol: a 32-bit reference count sits at obj+4;
// the release slot of the vtable at obj+0 is invoked with argument 1 when the
// count drops to zero.
inline void add_ref(void* obj) {
    ++*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(obj) + 4);
}

inline void release_ref(void* obj) {
    if (obj == nullptr) {
        return;
    }
    int32_t* rc = reinterpret_cast<int32_t*>(static_cast<uint8_t*>(obj) + 4);
    if (--*rc == 0) {
        typedef void (*ReleaseFn)(void*, int);
        ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(obj));
        fn(obj, 1);
    }
}

inline void* as_ptr(uint32_t v) {
    return reinterpret_cast<void*>(static_cast<uintptr_t>(v));
}

inline uint32_t as_u32(const void* p) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p));
}

}  // namespace

// 0x512b00 — observed shape
int* FUN_00512b00(void* self, int param_1, int param_2) {
    float fVar1, fVar3, fVar4, fVar5, fVar6;
    char cVar2;
    char* pcVar7;
    int iVar8;
    int iVar10;
    int* piVar9;
    uint8_t* base = static_cast<uint8_t*>(self);

    if ((DAT_008edcb8 & 1u) == 0) {
        DAT_008edcb8 |= 1u;
        pcVar7 = const_cast<char*>("FLandscape::CreateCell");
        do {
            cVar2 = *pcVar7;
            // Literal-relative byte store lands in the 0x8edcac name buffer.
            pcVar7[0x1dc2dc] = cVar2;
            pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        DAT_008edcb0 = 0xffffffffu;
        DAT_008edcac = 0;
    }
    if (DAT_008ca53c == 0) {
        iVar8 = static_cast<int>(FUN_00533c78(0x70));
        if (iVar8 == 0) {
            DAT_008ca53c = 0;
        } else {
            DAT_008ca53c = FUN_0051ffd0();
        }
    }
    FUN_005200b0(&DAT_008edb88);
    // **(undefined4 **)(self + 0xa8) resolved twice, then called.
    typedef int* (*CellFactoryFn)();
    CellFactoryFn cellFactory = reinterpret_cast<CellFactoryFn>(
        **reinterpret_cast<uint32_t**>(base + 0xa8));
    piVar9 = cellFactory();

    typedef int (*AttachFn)(uint32_t, uint32_t, uint32_t, uint32_t, void*);
    AttachFn attach = reinterpret_cast<AttachFn>(
        *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*piVar9) + 4));
    iVar8 = attach(*reinterpret_cast<uint32_t*>(base + 0x54),
                   *reinterpret_cast<uint32_t*>(base + 0x58),
                   *reinterpret_cast<uint32_t*>(base + 0x5c),
                   *reinterpret_cast<uint32_t*>(base + 0x60), &DAT_008ea110);
    if (iVar8 == 0) {
        iVar8 = static_cast<int>(FUN_004edfd0());
        iVar10 = *reinterpret_cast<int*>(base + 0x7c) + -1;
        fVar3 = static_cast<float>(iVar10);
        if (iVar10 < 0) {
            fVar3 = fVar3 + 4294967296.0f;
        }
        fVar4 = static_cast<float>(param_1);
        if (param_1 < 0) {
            fVar4 = fVar4 + 4294967296.0f;
        }
        iVar10 = *reinterpret_cast<int*>(base + 0x80) + -1;
        fVar5 = static_cast<float>(iVar10);
        if (iVar10 < 0) {
            fVar5 = fVar5 + 4294967296.0f;
        }
        fVar1 = *reinterpret_cast<float*>(base + 0x88);
        fVar6 = static_cast<float>(param_2);
        if (param_2 < 0) {
            fVar6 = fVar6 + 4294967296.0f;
        }
        *reinterpret_cast<float*>(static_cast<intptr_t>(iVar8) + 0x5c) =
            fVar4 * fVar3 * *reinterpret_cast<float*>(base + 0x84);
        *reinterpret_cast<float*>(static_cast<intptr_t>(iVar8) + 0x60) =
            -(fVar6 * fVar5 * fVar1);
        *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar8) + 100) = 0;
        if (*reinterpret_cast<int*>(base + 0x68) != 0) {
            typedef void (*Slot8Fn)(int);
            Slot8Fn slot8 = reinterpret_cast<Slot8Fn>(
                *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*piVar9) + 8));
            slot8(*reinterpret_cast<int*>(base + 0x68));
        }
        if (DAT_008ca53c != 0) {
            goto LAB_00512d52;
        }
        iVar8 = static_cast<int>(FUN_00533c78(0x70));
        if (iVar8 != 0) {
            DAT_008ca53c = FUN_0051ffd0();
            goto LAB_00512d52;
        }
    } else {
        iVar8 = static_cast<int>(FUN_004edfd0());
        iVar10 = *reinterpret_cast<int*>(base + 0x7c) + -1;
        fVar3 = static_cast<float>(iVar10);
        if (iVar10 < 0) {
            fVar3 = fVar3 + 4294967296.0f;
        }
        fVar4 = static_cast<float>(param_1);
        if (param_1 < 0) {
            fVar4 = fVar4 + 4294967296.0f;
        }
        iVar10 = *reinterpret_cast<int*>(base + 0x80) + -1;
        fVar5 = static_cast<float>(iVar10);
        if (iVar10 < 0) {
            fVar5 = fVar5 + 4294967296.0f;
        }
        fVar1 = *reinterpret_cast<float*>(base + 0x88);
        fVar6 = static_cast<float>(param_2);
        if (param_2 < 0) {
            fVar6 = fVar6 + 4294967296.0f;
        }
        *reinterpret_cast<float*>(static_cast<intptr_t>(iVar8) + 0x5c) =
            fVar4 * fVar3 * *reinterpret_cast<float*>(base + 0x84);
        *reinterpret_cast<float*>(static_cast<intptr_t>(iVar8) + 0x60) =
            -(fVar6 * fVar5 * fVar1);
        *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar8) + 100) = 0;
        if (DAT_008ca53c != 0) {
            goto LAB_00512d52;
        }
        iVar8 = static_cast<int>(FUN_00533c78(0x70));
        if (iVar8 != 0) {
            DAT_008ca53c = FUN_0051ffd0();
            goto LAB_00512d52;
        }
    }
    DAT_008ca53c = 0;
LAB_00512d52:
    FUN_00520190(&DAT_008edb88);
    return piVar9;
}

// 0x512d70 — observed shape
void FUN_00512d70(void* self, int param_1, int param_2) {
    char cVar1;
    char* pcVar4;
    intptr_t iVar5;
    int* piVar2;
    uint8_t bVar3;
    uint32_t* puVar6;
    uint32_t uVar7;
    uint8_t* base = static_cast<uint8_t*>(self);

    if ((DAT_008edb80 & 1u) == 0) {
        DAT_008edb80 |= 1u;
        pcVar4 = const_cast<char*>("FLandscape::AttachCell");
        do {
            cVar1 = *pcVar4;
            // Literal-relative byte store lands in the 0x8edb74 name buffer.
            pcVar4[0x1dc1bc] = cVar1;
            pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        DAT_008edb78 = 0xffffffffu;
        DAT_008edb74 = 0;
    }
    if (DAT_008ca53c == 0) {
        iVar5 = static_cast<intptr_t>(FUN_00533c78(0x70));
        if (iVar5 == 0) {
            DAT_008ca53c = 0;
        } else {
            DAT_008ca53c = FUN_0051ffd0();
        }
    }
    FUN_005200b0(&DAT_008eda50);

    int grid = *reinterpret_cast<int*>(base + 8);
    int rowBase = *reinterpret_cast<int*>(static_cast<intptr_t>(grid) + param_1 * 4);
    int cell = *reinterpret_cast<int*>(static_cast<intptr_t>(rowBase) + param_2 * 4);
    piVar2 = *reinterpret_cast<int**>(static_cast<intptr_t>(cell) + 8);

    uVar7 = 0;
    if (piVar2 != nullptr) {
        typedef void* (*IterFn)(void*);
        IterFn iter = reinterpret_cast<IterFn>(
            *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*piVar2) + 4));
        puVar6 = reinterpret_cast<uint32_t*>(iter(piVar2));
        for (; puVar6 != nullptr; puVar6 = reinterpret_cast<uint32_t*>(puVar6[1])) {
            if (puVar6 == &DAT_00727560) {
                bVar3 = 1;
                goto LAB_00512e10;
            }
        }
        bVar3 = 0;
LAB_00512e10:
        uVar7 = (0u - static_cast<uint32_t>(bVar3)) & as_u32(piVar2);
    }

    int owner = *reinterpret_cast<int*>(base + 4);
    uint32_t ownerVtbl = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(owner));
    typedef void (*Slot70Fn)(uint32_t, int);
    Slot70Fn slot70 = reinterpret_cast<Slot70Fn>(
        *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(ownerVtbl) + 0x70));
    slot70(uVar7, 1);

    FUN_00534130();
    FUN_00534350();
    FUN_00533d10(0, 1);
    if (DAT_008ca53c == 0) {
        iVar5 = static_cast<intptr_t>(FUN_00533c78(0x70));
        if (iVar5 == 0) {
            DAT_008ca53c = 0;
        } else {
            DAT_008ca53c = FUN_0051ffd0();
        }
    }
    FUN_00520190(&DAT_008eda50);
}

// 0x512e80 — observed shape
uint16_t FUN_00512e80(void* self, float param_1, float param_2, float* out_ESI, float* out_EDI) {
    uint8_t* base = static_cast<uint8_t*>(self);
    float fVar1, fVar2, fVar3, fVar4;
    uint32_t uVar5;
    int iVar6;

    iVar6 = *reinterpret_cast<int*>(base + 0x6c) + -1;
    fVar1 = static_cast<float>(iVar6);
    if (iVar6 < 0) {
        fVar1 = fVar1 + 4294967296.0f;
    }
    fVar2 = fVar1 * *reinterpret_cast<float*>(base + 0x84);

    iVar6 = *reinterpret_cast<int*>(base + 0x70) + -1;
    fVar3 = static_cast<float>(iVar6);
    if (iVar6 < 0) {
        fVar3 = fVar3 + 4294967296.0f;
    }
    fVar4 = fVar3 * *reinterpret_cast<float*>(base + 0x88);

    int origin = *reinterpret_cast<int*>(base + 4);
    param_1 = param_1 - *reinterpret_cast<float*>(static_cast<intptr_t>(origin) + 0x90);
    param_2 = param_2 - *reinterpret_cast<float*>(static_cast<intptr_t>(origin) + 0x94);

    if (0.0f <= param_1) {
        if (param_1 <= fVar2) {
            if (param_2 <= 0.0f) {
                if (-fVar4 <= param_2) {
                    uVar5 = FUN_005f0ddc(fVar4, fVar3, fVar2, fVar1);
                    *out_EDI = *reinterpret_cast<float*>(&uVar5);
                    uVar5 = FUN_005f0ddc();
                    *out_ESI = *reinterpret_cast<float*>(&uVar5);
                    return 1;
                }
            }
        }
    }
    *out_ESI = 0.0f;
    *out_EDI = 0.0f;
    return 0;
}

// 0x512f70 — observed shape
long double FUN_00512f70(void* self, uint32_t param_1) {
    uint8_t* base = static_cast<uint8_t*>(self);

    if (*reinterpret_cast<char*>(base + 0xa0) == '\0') {
        return 0.0L;
    }
    if (*reinterpret_cast<int*>(base + 4) == 0) {
        return static_cast<long double>(*reinterpret_cast<float*>(base + 0x8c)) * -256.0L;
    }
    return FUN_00513010(static_cast<int>(*reinterpret_cast<uint32_t*>(base + 0x70)),
                        *reinterpret_cast<float*>(base + 0x84),
                        *reinterpret_cast<float*>(base + 0x88),
                        *reinterpret_cast<float*>(base + 0x8c), 0,
                        reinterpret_cast<float*>(static_cast<intptr_t>(param_1)));
}

// 0x513010 — observed shape
long double FUN_00513010(int param_1, float param_2, float param_3, float param_4,
                         int param_5, float* param_6,
                         float* in_EAX, int in_ECX, intptr_t unaff_EDI) {
    long double fVar1 = 0.0L, fVar2 = 0.0L, fVar10 = 0.0L, fVar11 = 0.0L, fVar12 = 0.0L,
                fVar13 = 0.0L;
    // x87 stack values left behind by the preceding FUN_005f0ddc calls; the
    // listing exposes them only through extraout registers.
    long double extraout_ST0 = 0.0L;
    long double extraout_ST1 = 0.0L;
    long double extraout_ST1_00 = 0.0L;
    uint32_t uVar3 = 0, uVar4 = 0;
    int iVar5 = 0, iVar6 = 0;
    float* pfVar7 = nullptr;
    float fVar8 = 0.0f, fVar9 = 0.0f;
    double dVar14 = 0.0;
    double dIntPart = 0.0;
    float local_54 = 0.0f, local_50 = 0.0f, local_4c = 0.0f, local_48 = 0.0f, local_44 = 0.0f;
    float local_3c = 0.0f, local_38 = 0.0f, local_34 = 0.0f, local_28 = 0.0f, local_24 = 0.0f,
          local_20 = 0.0f;
    float local_1c[2] = {0.0f, 0.0f};
    float local_14 = 0.0f, local_10 = 0.0f, local_c = 0.0f, local_8 = 0.0f;

    local_24 = in_EAX[1];
    local_28 = *in_EAX;
    local_20 = in_EAX[2];
    fVar8 = static_cast<float>(param_1 + -1);
    if (param_1 + -1 < 0) {
        fVar8 = fVar8 + 4294967296.0f;
    }
    if (local_28 < 0.0f) {
LAB_00513529:
        return 0.0L;
    }
    local_50 = static_cast<float>(in_ECX + -1);
    fVar9 = static_cast<float>(static_cast<int>(local_50));
    if (static_cast<int>(local_50) < 0) {
        fVar9 = fVar9 + 4294967296.0f;
    }
    if (((fVar9 * param_2 < local_28) || (local_24 < -(fVar8 * param_3))) ||
        (0.0f < local_24)) {
        goto LAB_00513529;
    }
    fVar8 = local_28 / param_2;
    local_54 = -(local_24 / param_3);
    if (param_5 == 0) {
LAB_005130e5:
        uVar3 = FUN_005f0ddc();
        uVar4 = FUN_005f0ddc();
        fVar9 = local_54;
        if (((uVar3 ^ uVar4) & 1u) != 0) {
            goto LAB_00513216;
        }
        fVar10 = static_cast<long double>(FUN_00513cf0(local_54, &local_54));
        local_50 = static_cast<float>(fVar10);
        fVar10 = static_cast<long double>(FUN_00513cf0(fVar8, &local_54));
        if (1.0L < fVar10 + static_cast<long double>(local_50)) {
            fVar10 = static_cast<long double>(FUN_004e2490(fVar8));
            local_3c = static_cast<float>(fVar10 + 1.0L);
            fVar10 = static_cast<long double>(FUN_004e2490(fVar9));
            fVar11 = 1.5L + fVar10;
            fVar12 = static_cast<long double>(param_1);
            local_1c[0] = local_3c;
            if (param_1 < 0) {
                fVar12 = fVar12 + 4294967296.0L;
            }
            if ((std::isnan(fVar12) || std::isnan(fVar11)) ||
                (fVar12 < fVar11) == (fVar12 == fVar11)) {
                fVar11 = 1.0L;
            } else {
                fVar11 = -1.0L;
            }
            local_48 = static_cast<float>(fVar11 + fVar10);
            goto LAB_0051333b;
        }
        fVar10 = static_cast<long double>(FUN_004e2490(fVar8));
        local_3c = static_cast<float>(fVar10 + 1.0L);
        fVar10 = static_cast<long double>(FUN_004e2490(fVar9));
        fVar11 = fVar10 + 1.5L;
    } else {
        if (param_5 != 1) {
            if (param_5 != 2) {
                goto LAB_0051333b;
            }
            goto LAB_005130e5;
        }
LAB_00513216:
        // modf's integral parts are written through overlapping storage in the
        // listing and are overwritten before use; a scratch double carries them.
        dVar14 = std::modf(static_cast<double>(fVar8), &dIntPart);
        local_50 = static_cast<float>(dVar14);
        dVar14 = std::modf(static_cast<double>(local_54), &dIntPart);
        if (static_cast<double>(local_50) - dVar14 < 0.0) {
            dVar14 = std::floor(static_cast<double>(fVar8));
            local_3c = static_cast<float>(dVar14);
            dVar14 = std::floor(static_cast<double>(local_54));
            local_48 = static_cast<float>(dVar14);
            local_1c[0] = local_3c + 1.0f;
            fVar8 = local_48 + 1.5f;
            fVar9 = static_cast<float>(param_1);
            if (param_1 < 0) {
                fVar9 = fVar9 + 4294967296.0f;
            }
            if ((std::isnan(fVar9) || std::isnan(fVar8)) ||
                (fVar9 < fVar8) == (fVar9 == fVar8)) {
                local_48 = local_48 + 1.0f;
            } else {
                local_48 = local_48 + -1.0f;
            }
            goto LAB_0051333b;
        }
        dVar14 = std::floor(static_cast<double>(fVar8));
        local_3c = static_cast<float>(dVar14) + 1.0f;
        dVar14 = std::floor(static_cast<double>(local_54));
        fVar10 = static_cast<long double>(dVar14);
        fVar11 = fVar10 + 1.5L;
    }
    local_1c[0] = local_3c - 1.0f;
    fVar12 = static_cast<long double>(param_1);
    if (param_1 < 0) {
        fVar12 = fVar12 + 4294967296.0L;
    }
    if ((std::isnan(fVar12) || std::isnan(fVar11)) ||
        (fVar12 < fVar11) == (fVar12 == fVar11)) {
        local_48 = static_cast<float>(1.0L + fVar10);
    } else {
        local_48 = static_cast<float>(-1.0L + fVar10);
    }
LAB_0051333b:
    iVar5 = static_cast<int>(FUN_005f0ddc());
    iVar6 = static_cast<int>(FUN_005f0ddc());
    local_34 = static_cast<float>(
                   *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar6) +
                                               iVar5 * in_ECX + unaff_EDI)) *
               param_4;
    iVar5 = static_cast<int>(FUN_005f0ddc());
    iVar6 = static_cast<int>(FUN_005f0ddc());
    local_14 = static_cast<float>(
                   *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar6) +
                                               iVar5 * in_ECX + unaff_EDI)) *
               param_4;
    iVar5 = static_cast<int>(FUN_005f0ddc());
    fVar10 = extraout_ST1;
    iVar6 = static_cast<int>(FUN_005f0ddc());
    local_44 = static_cast<float>(
                   *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar6) +
                                               iVar5 * in_ECX + unaff_EDI)) *
               param_4;

    local_1c[0] = local_1c[0] * param_2;
    local_4c = static_cast<float>(extraout_ST0 * static_cast<long double>(param_2));
    local_48 = local_48 * param_3;
    local_24 = -local_24;
    local_3c = local_3c * param_2 - local_1c[0];
    local_38 = static_cast<float>(
        static_cast<float>(fVar10 * static_cast<long double>(param_3)) -
        extraout_ST1_00 * static_cast<long double>(param_3));
    local_34 = local_34 - local_14;
    local_10 = local_1c[0] - local_4c;
    local_c = static_cast<float>(extraout_ST1_00 * static_cast<long double>(param_3) -
                                 static_cast<long double>(local_48));
    local_8 = local_14 - local_44;

    pfVar7 = FUN_004916d0(local_1c, &local_10);
    local_38 = pfVar7[1];
    fVar8 = *pfVar7;
    fVar9 = pfVar7[2];
    fVar12 = static_cast<long double>(local_38);
    fVar1 = static_cast<long double>(fVar8);
    fVar2 = static_cast<long double>(fVar9);
    fVar13 = static_cast<long double>(fVar8);
    fVar10 = static_cast<long double>(local_38);
    fVar11 = static_cast<long double>(fVar9);

    if (param_6 != nullptr) {
        if (fVar9 < 0.0f) {
            fVar8 = -fVar8;
            local_38 = -local_38;
            fVar9 = -fVar9;
        }
        *param_6 = fVar8;
        param_6[1] = -local_38;
        param_6[2] = fVar9;
    }
    return ((static_cast<long double>(local_44) - static_cast<long double>(local_20)) * fVar2 +
            (static_cast<long double>(local_4c) - static_cast<long double>(local_28)) * fVar1 +
            (static_cast<long double>(local_48) - static_cast<long double>(local_24)) * fVar12) /
               ((fVar13 + fVar10) * 0.0L + fVar11) +
           static_cast<long double>(local_20);
}

// 0x513540 — observed shape
uint32_t FUN_00513540(void* self, float* in_EAX, uint32_t* param_1) {
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    union {
        double d;
        float f[2];
    } local_10;
    double local_18 = 0.0;
    uint32_t local_1c = 0;
    uint32_t local_8;
    int iVar6;
    int iVar5;
    float fVar1;
    float fVar2;
    uint16_t uVar4;
    uint32_t uVar3;
    double dVar7;

    local_10.d = 0.0;
    local_8 = *reinterpret_cast<uint32_t*>(in_EAX + 2);
    iVar6 = *reinterpret_cast<int*>(selfBytes + 4);
    uVar3 = 0;
    if (iVar6 != 0) {
        local_10.f[0] = in_EAX[0] - *reinterpret_cast<float*>(static_cast<intptr_t>(iVar6) + 0x90);
        iVar5 = *reinterpret_cast<int*>(selfBytes + 0x70) + -1;
        local_10.f[1] = in_EAX[1] - *reinterpret_cast<float*>(static_cast<intptr_t>(iVar6) + 0x94);
        fVar1 = static_cast<float>(iVar5);
        if (iVar5 < 0) {
            fVar1 = fVar1 + 4294967296.0f;
        }
        uVar4 = static_cast<uint16_t>(static_cast<uint32_t>(iVar6) >> 0x10);
        uVar3 = (static_cast<uint32_t>(uVar4) << 16) |
                (static_cast<uint32_t>(local_10.f[0] < 0.0f) << 8 |
                 static_cast<uint32_t>(std::isnan(local_10.f[0])) << 10 |
                 static_cast<uint32_t>(local_10.f[0] == 0.0f) << 0xe);
        if (local_10.f[0] >= 0.0f) {
            iVar6 = *reinterpret_cast<int*>(selfBytes + 0x6c) + -1;
            // CONCAT44(old high dword, iVar6) before modf overwrites the value.
            local_18 = static_cast<double>(static_cast<uint32_t>(iVar6));
            fVar2 = static_cast<float>(iVar6);
            if (iVar6 < 0) {
                fVar2 = fVar2 + 4294967296.0f;
            }
            fVar2 = fVar2 * *reinterpret_cast<float*>(selfBytes + 0x84);
            uVar3 = (static_cast<uint32_t>(uVar4) << 16) |
                    (static_cast<uint32_t>(fVar2 < local_10.f[0]) << 8 |
                     static_cast<uint32_t>(std::isnan(fVar2) || std::isnan(local_10.f[0])) << 10 |
                     static_cast<uint32_t>(fVar2 == local_10.f[0]) << 0xe);
            if (fVar2 >= local_10.f[0]) {
                fVar1 = -(fVar1 * *reinterpret_cast<float*>(selfBytes + 0x88));
                uVar3 = (static_cast<uint32_t>(uVar4) << 16) |
                        (static_cast<uint32_t>(fVar1 < local_10.f[1]) << 8 |
                         static_cast<uint32_t>(std::isnan(fVar1) || std::isnan(local_10.f[1]))
                             << 10 |
                         static_cast<uint32_t>(fVar1 == local_10.f[1]) << 0xe);
                if ((fVar1 < local_10.f[1] || fVar1 == local_10.f[1]) &&
                    (local_10.f[1] < 0.0f || local_10.f[1] == 0.0f)) {
                    dVar7 = std::modf(
                        static_cast<double>(local_10.f[0] / *reinterpret_cast<float*>(selfBytes + 0x84)),
                        &local_18);
                    if (0.0 <= dVar7) {
                        local_1c = static_cast<uint32_t>(0.5 < dVar7);
                        local_18 = static_cast<double>(local_1c) + local_18;
                    } else {
                        local_1c = static_cast<uint32_t>(dVar7 < -0.5);
                        local_18 = local_18 - static_cast<double>(local_1c);
                    }
                    iVar6 = static_cast<int>(FUN_005f0ddc());
                    dVar7 = std::modf(
                        -static_cast<double>(local_10.f[1] / *reinterpret_cast<float*>(selfBytes + 0x88)),
                        &local_10.d);
                    if (0.0 <= dVar7) {
                        local_1c = static_cast<uint32_t>(0.5 < dVar7);
                        local_10.d = static_cast<double>(local_1c) + local_10.d;
                    } else {
                        local_1c = static_cast<uint32_t>(dVar7 < -0.5);
                        local_10.d = local_10.d - static_cast<double>(local_1c);
                    }
                    iVar5 = static_cast<int>(FUN_005f0ddc());
                    uint32_t table = *reinterpret_cast<uint32_t*>(selfBytes + 0x60);
                    uVar3 = *reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(table) +
                        (iVar5 * *reinterpret_cast<int*>(selfBytes + 0x6c) + iVar6) * 4);
                    *param_1 = uVar3;
                    return (uVar3 & 0xffffff00u) | 1u;
                }
            }
        }
    }
    return uVar3;
}

// 0x513730 — observed shape
int* FUN_00513730(void* self, int* param_1, uint32_t* param_2, int param_3) {
    int32_t* esi = static_cast<int32_t*>(self);
    intptr_t iVar5;
    int iVar7;
    int iVar2;
    int* piVar6;
    int* piVar8;
    uint32_t* puVar3;
    uint32_t* puVar4;
    int32_t* piVar1;

    if (esi[2] == 0) {
        iVar5 = static_cast<intptr_t>(thunk_FUN_00533c78(
            *reinterpret_cast<int*>(static_cast<intptr_t>(*esi) + 0x74) * 4));
        esi[2] = static_cast<int32_t>(iVar5);
        iVar5 = 0;
        if (0 < *reinterpret_cast<int*>(static_cast<intptr_t>(*esi) + 0x74)) {
            do {
                iVar7 = *reinterpret_cast<int*>(static_cast<intptr_t>(*esi) + 0x78);
                piVar6 = reinterpret_cast<int*>(
                    static_cast<intptr_t>(thunk_FUN_00533c78(iVar7 * 4 + 4)));
                if (piVar6 == nullptr) {
                    piVar6 = nullptr;
                } else {
                    *piVar6 = iVar7;
                    piVar6 = piVar6 + 1;
                    if (-1 < iVar7 + -1) {
                        piVar8 = piVar6;
                        for (; iVar7 != 0; iVar7 = iVar7 + -1) {
                            *piVar8 = 0;
                            piVar8 = piVar8 + 1;
                        }
                    }
                }
                *reinterpret_cast<int**>(static_cast<intptr_t>(esi[2]) + iVar5 * 4) = piVar6;
                iVar7 = 0;
                if (0 < *reinterpret_cast<int*>(static_cast<intptr_t>(*esi) + 0x78)) {
                    do {
                        iVar2 = *reinterpret_cast<int*>(
                            static_cast<intptr_t>(esi[2]) + iVar5 * 4);
                        puVar3 = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(iVar2) +
                                                              iVar7 * 4);
                        if (puVar3 != nullptr) {
                            piVar6 = reinterpret_cast<int*>(
                                reinterpret_cast<uint8_t*>(puVar3) + 4);
                            *piVar6 = *piVar6 + -1;
                            if (*piVar6 == 0) {
                                typedef void (*ReleaseFn)(void*, int);
                                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
                                    *reinterpret_cast<void**>(puVar3));
                                fn(puVar3, 1);
                            }
                            *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar2) +
                                                          iVar7 * 4) = 0;
                        }
                        iVar7 = iVar7 + 1;
                    } while (iVar7 < *reinterpret_cast<int*>(static_cast<intptr_t>(*esi) + 0x78));
                }
                iVar5 = iVar5 + 1;
            } while (iVar5 < *reinterpret_cast<int*>(static_cast<intptr_t>(*esi) + 0x74));
        }
    }

    iVar5 = param_3;
    puVar3 = param_2;
    param_3 = param_3 * 4;
    if (*reinterpret_cast<int*>(static_cast<intptr_t>(param_3) +
                                *reinterpret_cast<int*>(static_cast<intptr_t>(esi[2]) +
                                                        reinterpret_cast<intptr_t>(param_2) * 4)) ==
        0) {
        piVar6 = FUN_00513880(esi, reinterpret_cast<uint32_t>(&param_2),
                              static_cast<int>(reinterpret_cast<intptr_t>(param_2)),
                              static_cast<int>(iVar5));
        piVar8 = reinterpret_cast<int*>(
            *reinterpret_cast<int*>(static_cast<intptr_t>(esi[2]) +
                                    reinterpret_cast<intptr_t>(puVar3) * 4) +
            param_3);
        puVar4 = *reinterpret_cast<uint32_t**>(piVar8);
        if (puVar4 != reinterpret_cast<uint32_t*>(*piVar6)) {
            if (puVar4 != nullptr) {
                piVar1 = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(puVar4) + 4);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    typedef void (*ReleaseFn)(void*, int);
                    ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
                        *reinterpret_cast<void**>(puVar4));
                    fn(puVar4, 1);
                }
            }
            iVar5 = *piVar6;
            *reinterpret_cast<int*>(piVar8) = static_cast<int>(iVar5);
            if (iVar5 != 0) {
                *reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) + 4) += 1;
            }
        }
        if ((param_2 != nullptr) && (iVar5 = param_2[1], param_2[1] = iVar5 - 1,
                                     iVar5 - 1 == 0)) {
            typedef void (*ReleaseFn)(void*, int);
            ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(param_2));
            fn(param_2, 1);
        }
    }
    iVar5 = *reinterpret_cast<int*>(static_cast<intptr_t>(param_3) +
                                    *reinterpret_cast<int*>(static_cast<intptr_t>(esi[2]) +
                                                            reinterpret_cast<intptr_t>(puVar3) * 4));
    *param_1 = static_cast<int>(iVar5);
    if (iVar5 != 0) {
        *reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) + 4) += 1;
    }
    return param_1;
}

// 0x513880 — observed shape
// The trailing stack words (iStack_c / iStack_4 / unaff_retaddr) and the
// unaff_EDI / piStack_8 slots are caller-provided; the listing shows only the
// four explicit arguments, so these remain explicit parameters.
int* FUN_00513880(int* param_1, uint32_t param_2, int param_3, int param_4,
                  int iStack_c, int iStack_4, int unaff_retaddr,
                  uint32_t* unaff_EDI, int* piStack_8) {
    int* piVar1;
    int iVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    int iVar5;
    int iVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    intptr_t local_74;
    intptr_t local_70;
    int local_68;
    int local_64[3];
    int* local_58;
    uint32_t local_54;
    uint32_t local_50;
    uint32_t local_4c;
    uint32_t local_48[9];
    uint32_t local_24[9];  // listing declares 6 but copies nine dwords
    uint8_t* p74;

    local_74 = 0;
    local_64[1] = 0;
    local_54 = 6;
    local_50 = 2;
    local_4c = 3;
    local_58 = FUN_0054aad0();
    iVar2 = *param_1;
    iVar5 = param_1[4];
    local_70 = static_cast<intptr_t>(*reinterpret_cast<int*>(static_cast<intptr_t>(iVar2) + 0x7c)) * iVar5;
    iVar6 = *reinterpret_cast<int*>(static_cast<intptr_t>(iVar2) + 0x80) * iVar5;
    local_64[0] = *reinterpret_cast<int*>(static_cast<intptr_t>(iVar2) + 0x6c) * iVar5;
    local_64[2] = *reinterpret_cast<int*>(static_cast<intptr_t>(iVar2) + 0x70) * iVar5;
    param_3 = (static_cast<int>(local_70) + -1) * iVar5 * param_3;
    param_4 = (iVar6 + -1) * iVar5 * param_4;

    iVar2 = static_cast<int>(FUN_00533c78(0x50));
    if (iVar2 != 0) {
        puVar3 = &DAT_007178c8;
        puVar7 = local_48;
        for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar7 = puVar7 + 1;
        }
        iVar2 = FUN_00539210(as_ptr(static_cast<uint32_t>(local_70)), iVar6, local_48, 1);
        if (iVar2 != 0) {
            *reinterpret_cast<int*>(static_cast<intptr_t>(iVar2) + 4) += 1;
            local_74 = iVar2;
        }
    }

    iVar2 = 0;
    local_64[2] = local_64[2] - param_4;
    param_4 = param_4 * local_64[0];
    local_68 = 0;
    while (true) {
        iVar5 = iVar6;
        if (local_64[2] <= iVar6) {
            iVar5 = local_64[2];
        }
        if (iVar5 <= local_68) {
            break;
        }
        puVar3 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(local_64[0] - param_3));
        if (static_cast<int>(local_70) < static_cast<int>(reinterpret_cast<intptr_t>(puVar3))) {
            puVar3 = reinterpret_cast<uint32_t*>(local_70);
        }
        puVar7 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(param_1[1] + param_4 + param_3));
        p74 = reinterpret_cast<uint8_t*>(local_74);
        int srcBlock = **reinterpret_cast<int**>(p74 + 0x40);
        puVar8 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(srcBlock) +
                                             *reinterpret_cast<int*>(p74 + 0x34) + iVar2);
        for (uVar4 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)) >> 2; uVar4 != 0;
             uVar4 = uVar4 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
        }
        for (uVar4 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)) & 3u; uVar4 != 0;
             uVar4 = uVar4 - 1) {
            *reinterpret_cast<uint8_t*>(puVar8) = *reinterpret_cast<uint8_t*>(puVar7);
            puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar7) + 1);
            puVar8 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar8) + 1);
        }
        local_68 = local_68 + 1;
        param_4 = param_4 + local_64[0];
        iVar2 = iVar2 + static_cast<int>(local_70);
    }

    puVar3 = reinterpret_cast<uint32_t*>(param_1[3]);
    p74 = reinterpret_cast<uint8_t*>(local_74);
    puVar7 = *reinterpret_cast<uint32_t**>(p74 + 0x30);
    if (puVar7 != puVar3) {
        if (puVar7 != nullptr) {
            piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(puVar7) + 4);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*ReleaseFn)(void*, int);
                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar7));
                fn(puVar7, 1);
            }
        }
        *reinterpret_cast<uint32_t**>(p74 + 0x30) = puVar3;
        if (puVar3 != nullptr) {
            add_ref(puVar3);
        }
    }

    puVar3 = &DAT_00727484;
    puVar7 = local_24;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
    }

    typedef void* (*CreateFn)(intptr_t, uint32_t*, uint32_t, uint32_t);
    CreateFn createFrom = reinterpret_cast<CreateFn>(
        *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*local_58) + 0x10));
    puVar3 = reinterpret_cast<uint32_t*>(createFrom(local_74, local_24, 0, 0));
    if (puVar3 != nullptr) {
        add_ref(puVar3);
        local_70 = reinterpret_cast<intptr_t>(puVar3);
    }

    local_64[2] = 0;
    local_64[1] = 0;
    local_64[0] = 2;
    puVar3 = reinterpret_cast<uint32_t*>(FUN_00539cc0(as_ptr(static_cast<uint32_t>(local_70)),
                                                      local_64));
    if (puVar3 != nullptr) {
        add_ref(puVar3);
    }

    iVar2 = *reinterpret_cast<int*>(static_cast<intptr_t>(iStack_c) + 8);
    iVar5 = unaff_retaddr * 4;
    puVar7 = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(iVar2) + iVar5);
    if (puVar7 != puVar3) {
        if (puVar7 != nullptr) {
            piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(puVar7) + 4);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*ReleaseFn)(void*, int);
                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar7));
                fn(puVar7, 1);
            }
        }
        *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(iVar2) + iVar5) = puVar3;
        if (puVar3 != nullptr) {
            add_ref(puVar3);
        }
    }
    iVar2 = *reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) +
                                    *reinterpret_cast<int*>(
                                        static_cast<intptr_t>(*reinterpret_cast<int*>(
                                            static_cast<intptr_t>(iStack_c) + 8)) +
                                        iStack_4 * 4));
    *piStack_8 = iVar2;
    if (iVar2 != 0) {
        *reinterpret_cast<int*>(static_cast<intptr_t>(iVar2) + 4) += 1;
    }
    if (puVar3 != nullptr) {
        piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(puVar3) + 4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*ReleaseFn)(void*, int);
            ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar3));
            fn(puVar3, 1);
        }
    }
    if (local_70 != 0) {
        puVar7 = reinterpret_cast<uint32_t*>(local_70);
        piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(puVar7) + 4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*ReleaseFn)(void*, int);
            ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar7));
            fn(puVar7, 1);
        }
    }
    if (unaff_EDI != nullptr) {
        piVar1 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(unaff_EDI) + 4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*ReleaseFn)(void*, int);
            ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
                *reinterpret_cast<void**>(unaff_EDI));
            fn(unaff_EDI, 1);
        }
    }
    return piStack_8;
}

// 0x513b00 — observed shape
void FUN_00513b00(void* self) {
    int32_t* edi = static_cast<int32_t*>(self);
    int iVar4;
    int iVar3;
    int iVar5;
    int iStack_4;
    uint32_t* puVar2;
    int32_t* piVar1;
    int obj = *edi;  // *unaff_EDI

    iVar4 = 0;
    if (0 < *reinterpret_cast<int*>(static_cast<intptr_t>(obj) + 0x74)) {
        do {
            iVar3 = 0;
            if (0 < *reinterpret_cast<int*>(static_cast<intptr_t>(obj) + 0x78)) {
                do {
                    if (edi[2] != 0) {
                        iVar5 = *reinterpret_cast<int*>(static_cast<intptr_t>(edi[2]) + iVar4 * 4);
                        puVar2 = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(iVar5) +
                                                              iVar3 * 4);
                        if (puVar2 != nullptr) {
                            piVar1 = reinterpret_cast<int32_t*>(
                                reinterpret_cast<uint8_t*>(puVar2) + 4);
                            *piVar1 = *piVar1 + -1;
                            if (*piVar1 == 0) {
                                typedef void (*ReleaseFn)(void*, int);
                                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
                                    *reinterpret_cast<void**>(puVar2));
                                fn(puVar2, 1);
                            }
                            *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar5) +
                                                          iVar3 * 4) = 0;
                        }
                    }
                    iVar3 = iVar3 + 1;
                } while (iVar3 < *reinterpret_cast<int*>(static_cast<intptr_t>(obj) + 0x78));
            }
            iVar4 = iVar4 + 1;
        } while (iVar4 < *reinterpret_cast<int*>(static_cast<intptr_t>(obj) + 0x74));
    }

    iVar4 = 0;
    if (edi[2] != 0) {
        if (0 < *reinterpret_cast<int*>(static_cast<intptr_t>(obj) + 0x74)) {
            do {
                iVar3 = *reinterpret_cast<int*>(static_cast<intptr_t>(edi[2]) + iVar4 * 4);
                if (iVar3 != 0) {
                    iStack_4 = *reinterpret_cast<int*>(static_cast<intptr_t>(iVar3) - 4);
                    iVar5 = iVar3 + iStack_4 * 4;
                    if (-1 < iStack_4 + -1) {
                        do {
                            puVar2 = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(iVar5) - 4);
                            iVar5 = iVar5 + -4;
                            if (puVar2 != nullptr) {
                                piVar1 = reinterpret_cast<int32_t*>(
                                    reinterpret_cast<uint8_t*>(puVar2) + 4);
                                *piVar1 = *piVar1 + -1;
                                if (*piVar1 == 0) {
                                    typedef void (*ReleaseFn)(void*, int);
                                    ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
                                        *reinterpret_cast<void**>(puVar2));
                                    fn(puVar2, 1);
                                }
                            }
                            iStack_4 = iStack_4 + -1;
                        } while (iStack_4 != 0);
                    }
                    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(iVar3) - 4));
                    *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(edi[2]) + iVar4 * 4) = 0;
                }
                iVar4 = iVar4 + 1;
            } while (iVar4 < *reinterpret_cast<int*>(static_cast<intptr_t>(obj) + 0x74));
        }
        if (edi[2] != 0) {
            operator_delete__(as_ptr(static_cast<uint32_t>(edi[2])));
            edi[2] = 0;
        }
    }
    if (edi[1] != 0) {
        operator_delete__(as_ptr(static_cast<uint32_t>(edi[1])));
        edi[1] = 0;
    }
}

// 0x513c00 — observed shape
void FUN_00513c00(int param_1, uint32_t param_2) {
    int* piVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    uint32_t* puVar7;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar1;
    int32_t* piVar1;

    piVar2 = FUN_0054aad0();
    typedef void* (*LookupFn)(uint32_t, int);
    LookupFn lookup = reinterpret_cast<LookupFn>(
        *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*piVar2) + 8));
    puVar3 = reinterpret_cast<uint32_t*>(lookup(param_2, 0));
    puVar7 = nullptr;
    if (puVar3 != nullptr) {
        add_ref(puVar3);
        puVar7 = puVar3;
    }

    puVar4 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(
        *reinterpret_cast<int*>(static_cast<intptr_t>(puVar7[0xf])) *
        *reinterpret_cast<int*>(static_cast<intptr_t>(puVar7[0xe]))));
    *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(param_1) + 4) = puVar4;

    iVar1 = *reinterpret_cast<int*>(static_cast<intptr_t>(puVar7[0x10]));
    uVar5 = static_cast<uint32_t>(
        *reinterpret_cast<int*>(static_cast<intptr_t>(puVar7[0x10]) + 4) - iVar1);
    puVar3 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(puVar7[0xd]) + iVar1);
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *reinterpret_cast<uint8_t*>(puVar4) = *reinterpret_cast<uint8_t*>(puVar3);
        puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar3) + 1);
        puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar4) + 1);
    }

    puVar3 = reinterpret_cast<uint32_t*>(puVar7[0xc]);
    puVar4 = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(param_1) + 0xc);
    if (puVar4 != puVar3) {
        if (puVar4 != nullptr) {
            piVar1 = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(puVar4) + 4);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*ReleaseFn)(void*, int);
                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar4));
                fn(puVar4, 1);
            }
        }
        *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(param_1) + 0xc) = puVar3;
        if (puVar3 != nullptr) {
            add_ref(puVar3);
        }
    }

    iVar1 = puVar7[1];
    puVar7[1] = static_cast<uint32_t>(iVar1 + -1);
    if (iVar1 + -1 == 0) {
        typedef void (*ReleaseFn)(void*, int);
        ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar7));
        fn(puVar7, 1);
    }
}

// 0x513ca0 — observed shape
void FUN_00513ca0(void* self_EAX, int ecx_index, int param_1) {
    uint8_t* base = static_cast<uint8_t*>(self_EAX);
    int32_t* piVar1;
    int32_t* piVar2;
    uint32_t* puVar3;

    if (*reinterpret_cast<int*>(base + 8) != 0) {
        int rowBase = *reinterpret_cast<int*>(base + 8);
        int row = *reinterpret_cast<int*>(static_cast<intptr_t>(rowBase) + ecx_index * 4);
        piVar2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(row) + param_1 * 4);
        puVar3 = *reinterpret_cast<uint32_t**>(piVar2);
        if (puVar3 != nullptr) {
            piVar1 = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(puVar3) + 4);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*ReleaseFn)(void*, int);
                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar3));
                fn(puVar3, 1);
            }
            *reinterpret_cast<uint32_t**>(piVar2) = nullptr;
        }
    }
}

// 0x513d20 — observed shape
void FUN_00513d20(void* self_EDX, uint32_t* out_ESI) {
    uint8_t* base = static_cast<uint8_t*>(self_EDX);
    int32_t* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar4;
    int iVar3;

    puVar2 = *reinterpret_cast<uint32_t**>(base + 0x50);
    puVar4 = nullptr;
    if (puVar2 != nullptr) {
        *reinterpret_cast<int*>(static_cast<intptr_t>(reinterpret_cast<intptr_t>(puVar2)) + 4) += 1;
        puVar4 = puVar2;
    }
    iVar3 = *reinterpret_cast<int*>(base + 0x50);
    *out_ESI = static_cast<uint32_t>(iVar3);
    if (iVar3 != 0) {
        *reinterpret_cast<int*>(static_cast<intptr_t>(iVar3) + 4) += 1;
    }
    if (puVar4 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(puVar4) + 4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*ReleaseFn)(void*, int);
            ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar4));
            fn(puVar4, 1);
        }
    }
}

// 0x513d50 — observed shape
void FUN_00513d50(void* self_EDI, uint32_t* param_1) {
    uint8_t* base = static_cast<uint8_t*>(self_EDI);
    int32_t* piVar1;
    uint32_t* puVar2;

    puVar2 = *reinterpret_cast<uint32_t**>(base + 0xc);
    if (puVar2 != param_1) {
        if (puVar2 != nullptr) {
            piVar1 = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(puVar2) + 4);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*ReleaseFn)(void*, int);
                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar2));
                fn(puVar2, 1);
            }
        }
        *reinterpret_cast<uint32_t**>(base + 0xc) = param_1;
        if (param_1 == nullptr) {
            return;
        }
        *reinterpret_cast<int*>(static_cast<intptr_t>(reinterpret_cast<intptr_t>(param_1)) + 4) += 1;
    }
    if (param_1 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(param_1) + 4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*ReleaseFn)(void*, int);
            ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(param_1));
            fn(param_1, 1);
        }
    }
}

// 0x513d90 — observed shape
int FUN_00513d90(void* self) {
    int32_t* esi = static_cast<int32_t*>(self);
    int iVar1;

    if (esi[1] == 0) {
        int obj = *esi;
        iVar1 = static_cast<int>(thunk_FUN_00533c78(static_cast<size_t>(
            esi[4] * esi[4] * *reinterpret_cast<int*>(static_cast<intptr_t>(obj) + 0x6c) *
            *reinterpret_cast<int*>(static_cast<intptr_t>(obj) + 0x70))));
        esi[1] = iVar1;
    }
    return esi[1];
}

// 0x513dc0 — observed shape
void FUN_00513dc0(void* self_ECX) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self_ECX);
    uint32_t uVar1;
    uint8_t bVar2;
    uint32_t uVar3;

    uVar1 = DAT_00717838;
    uVar3 = (2u << (static_cast<uint8_t>(DAT_0072745c) & 0x1f)) & DAT_00717834;
    bVar2 = static_cast<uint8_t>(DAT_0071783c);
    in_ECX[6] = 8;
    in_ECX[7] = uVar3 | ((1u << (bVar2 & 0x1f)) & uVar1);
    in_ECX[5] = 0;
    in_ECX[4] = 0;
    in_ECX[3] = 0;
    in_ECX[2] = 0;
    in_ECX[0] = 2;
    in_ECX[1] = 0;
    in_ECX[8] = 0;
}

// 0x513e20 — observed shape
void FUN_00513e20(const char* src_ESI, void* dst_EDI) {
    char cVar1;
    const char* pcVar2;
    intptr_t iVar3;
    char* p;

    pcVar2 = src_ESI;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (0x3fu < static_cast<uint32_t>(reinterpret_cast<intptr_t>(pcVar2) -
                                      reinterpret_cast<intptr_t>(src_ESI + 1))) {
        std::strncpy(reinterpret_cast<char*>(dst_EDI) + 0x14, src_ESI, 0x3f);
        *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(dst_EDI) + 0x53) = 0;
        return;
    }
    iVar3 = (reinterpret_cast<intptr_t>(dst_EDI) + 0x14) - reinterpret_cast<intptr_t>(src_ESI);
    p = const_cast<char*>(src_ESI);
    do {
        cVar1 = *p;
        p[iVar3] = cVar1;
        p = p + 1;
    } while (cVar1 != '\0');
}

// 0x513e60 — observed shape
void FUN_00513e60() {
    if (DAT_008cad64 == nullptr) {
        DAT_008cad64 = reinterpret_cast<uint32_t*>(as_ptr(FUN_00533c78(4)));
        if (DAT_008cad64 != nullptr) {
            *DAT_008cad64 = as_u32(&PTR_LAB_00711864);
            return;
        }
        DAT_008cad64 = nullptr;
    }
}

// 0x513ed0 — observed shape
void FUN_00513ed0() {
    if (DAT_008cad44 == nullptr) {
        DAT_008cad44 = reinterpret_cast<uint32_t*>(as_ptr(FUN_00533c78(4)));
        if (DAT_008cad44 != nullptr) {
            *DAT_008cad44 = as_u32(&PTR_LAB_0071185c);
            return;
        }
        DAT_008cad44 = nullptr;
    }
}

// 0x513f40 — observed shape
void FUN_00513f40(void* self_EDI) {
    int32_t* edi = static_cast<int32_t*>(self_EDI);
    int32_t* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    int iVar5;

    edi[1] = 0;
    puVar3 = reinterpret_cast<uint32_t*>(as_ptr(FUN_00533c78(0x18)));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        *puVar3 = as_u32(&PTR_FUN_00711994);
        puVar3[2] = 10;
        puVar3[5] = 10;
        puVar3[3] = 0;
        puVar3[4] = 0;
        uVar4 = thunk_FUN_00533c78(0x28);
        puVar3[1] = uVar4;
        *puVar3 = as_u32(&PTR_FUN_00711994);
    }
    *reinterpret_cast<uint32_t**>(edi) = puVar3;

    iVar5 = static_cast<int>(FUN_00533c78(0xec));
    if (iVar5 == 0) {
        puVar3 = nullptr;
    } else {
        puVar3 = reinterpret_cast<uint32_t*>(FUN_0053bb30(0));
    }
    puVar2 = reinterpret_cast<uint32_t*>(as_ptr(static_cast<uint32_t>(edi[1])));
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            piVar1 = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(puVar2) + 4);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (*ReleaseFn)(void*, int);
                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<void**>(puVar2));
                fn(puVar2, 1);
            }
        }
        edi[1] = static_cast<int32_t>(as_u32(puVar3));
        if (puVar3 != nullptr) {
            add_ref(puVar3);
        }
    }
}

// 0x513fe0 — observed shape
void FUN_00513fe0(int* param_1, uint32_t param_2) {
    int iVar5;
    int32_t* piVar2;
    uint32_t* puVar3;
    char cVar4;
    uint32_t uVar6;

    iVar5 = *param_1;
    uVar6 = 0;
    if (*reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) + 0x10) != 0) {
        do {
            int arrayBase = *reinterpret_cast<int*>(static_cast<intptr_t>(iVar5) + 4);
            piVar2 = *reinterpret_cast<int32_t**>(static_cast<intptr_t>(arrayBase) + uVar6 * 4);
            if ((piVar2 != nullptr) &&
                ((cVar4 = FUN_005108a0(param_2), cVar4 != '\0'))) {
                FUN_004c3000();
                puVar3 = *reinterpret_cast<uint32_t**>(piVar2);
                if (puVar3 != nullptr) {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(
                        reinterpret_cast<uint8_t*>(puVar3) + 4);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        typedef void (*ReleaseFn)(void*, int);
                        ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
                            *reinterpret_cast<void**>(puVar3));
                        fn(puVar3, 1);
                    }
                    *reinterpret_cast<uint32_t**>(piVar2) = nullptr;
                    if (reinterpret_cast<void*>(piVar2[9]) != nullptr) {
                        operator_delete(reinterpret_cast<void*>(piVar2[9]));
                        piVar2[9] = 0;
                    }
                }
            }
            iVar5 = *param_1;
            uVar6 = uVar6 + 1;
        } while (uVar6 < *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar5) + 0x10));
    }
}
