#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

// Extern helpers / globals observed in listings
extern void FUN_00506e60(...);
extern void FUN_00412f10(...);
extern uint32_t FUN_005082d0(uint32_t);
extern uint32_t FUN_00508e20(...);
extern void FUN_0053c280(uint32_t, uint32_t);
extern void FUN_00534130(...);
extern void FUN_00533d10(uint32_t, uint32_t);
extern void FUN_0050a350(...);
extern void FUN_005071f0(...);
extern void FUN_0050a6d0(uint8_t*);
extern void FUN_00508f20(void*, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_00475ff0(uint32_t);
extern uint32_t FUN_00509500(uint32_t, void*, uint32_t);
extern void FUN_00412f90(...);
extern void FUN_004f3350(...);
extern uint32_t DAT_0071779c, DAT_007177a0, DAT_007177a4, DAT_007177a8;
extern uint32_t DAT_00727430, DAT_00727434, DAT_00727438;
extern uint32_t DAT_008cad20;
extern void* PTR_FUN_00711048;
extern uint8_t DAT_008cacd0, DAT_008cacc8;
extern uint8_t DAT_008caccc;
extern uint8_t DAT_008cacd0_buf;

// 0x514090 — observed shape
void FUN_00514090(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5, uint32_t param_6, float param_7,
                  uint8_t param_8, uint32_t in_EAX, uint32_t in_ECX) {
    uint32_t* self32 = reinterpret_cast<uint32_t*>(self);
    (void)in_ECX;
    FUN_00506e60(param_1, 0, param_4, param_5, param_6, 0x3f800000u, in_EAX);
    self32[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711048);
    // *unaff_ESI = &PTR_FUN_00711048; unaff_ESI[0xa6] = &DAT_008cacd0; unaff_ESI[0xa5] = param_3;
    self32[0xa6] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
    self32[0xa5] = param_3;
    FUN_00412f10();
    uint32_t uVar4 = DAT_007177a8;
    uint32_t uVar3 = DAT_007177a4;
    uint32_t uVar2 = DAT_007177a0;
    uint32_t uVar1 = DAT_0071779c;
    self32[0xa7] = 0;
    int32_t iVar6 = static_cast<int32_t>(DAT_008cad20);
    for (; iVar6 != 0; iVar6 = *reinterpret_cast<int32_t*>(iVar6 + 0x60)) { // indirect via linked word
        uint8_t cVar5 = static_cast<uint8_t>(FUN_005082d0(param_2));
        if (cVar5 != 0) goto LAB_00514133;
    }
    iVar6 = 0;
    LAB_00514133:
    iVar6 = static_cast<int32_t>(FUN_00508e20(iVar6, DAT_00727430, DAT_00727434, DAT_00727438,
                                              in_ECX, param_3, uVar1, uVar2, uVar3, uVar4));
    self32[0xa4] = static_cast<uint32_t>(iVar6);
    iVar6 = *reinterpret_cast<int32_t*>(iVar6 + 0x34);
    *reinterpret_cast<float*>(iVar6 + 0x68) = (param_7 >= 0 ? param_7 : -param_7);
    FUN_0053c280(static_cast<uint32_t>(iVar6), 1);
    FUN_00534130();
    FUN_00533d10(0, 1);
    *reinterpret_cast<uint8_t*>(self32 + 0x3c) = param_8;
}

// 0x5141c0 — observed shape
void FUN_005141c0(void* self, uint32_t in_ECX_unused) {
    (void)in_ECX_unused;
    uint32_t* self32 = reinterpret_cast<uint32_t*>(self);
    void* pvVar1 = reinterpret_cast<void*>(self32[0xa4]);
    self32[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711048);
    if (pvVar1 != nullptr) {
        FUN_0050a350();
        operator delete(pvVar1);
        self32[0xa4] = 0;
    }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self32[0xa6] - 8);
    if (puVar2 != nullptr && puVar2 != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator delete(puVar2);
    }
    self32[0xa6] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
    FUN_005071f0();
}

// 0x514260 — observed shape
void FUN_00514260(void* self, uint8_t* param_1, uint32_t in_ECX) {
    (void)self;
    uint8_t* pbVar2 = *reinterpret_cast<uint8_t**>(in_ECX + 0x298);
    uint8_t* pbVar4 = param_1;
    int32_t iVar3;
    bool bVar5;
    do {
        uint8_t bVar1 = *pbVar2;
        bVar5 = bVar1 < *pbVar4;
        if (bVar1 != *pbVar4) {
            LAB_0051429c:
            iVar3 = (1 - (uint32_t)bVar5) - (uint32_t)(bVar5 != 0);
            goto LAB_005142a1;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar5 = bVar1 < pbVar4[1];
        if (bVar1 != pbVar4[1]) goto LAB_0051429c;
        pbVar2 = pbVar2 + 2;
        pbVar4 = pbVar4 + 2;
    } while (*pbVar2 != 0);
    iVar3 = 0;
    LAB_005142a1:
    if (iVar3 != 0) {
        FUN_0050a6d0(param_1);
        FUN_00412f10();
    }
}

// 0x5142c0 — observed shape
void FUN_005142c0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t in_ECX, uint32_t in_EBX) {
    (void)self;
    uint16_t local_4 = static_cast<uint16_t>(static_cast<uint8_t>(in_EBX));
    uint16_t uStack_2 = static_cast<uint16_t>(in_ECX >> 0x10);
    (void)uStack_2;
    FUN_00508f20(&local_4, param_1, param_2, param_3, param_4);
    FUN_00475ff0(in_EBX);
}

// 0x514310 — observed shape
double FUN_00514310(void* self, size_t param_1, uint32_t in_EBX_unused) {
    (void)self; (void)in_EBX_unused;
    uint32_t unaff_EBX = in_EBX_unused;
    // Use in_EBX register value supplied via wrapper; in original self is carried in EBX.
    int32_t iVar2 = 1;
    bool bVar5 = true;
    char* pcVar3 = *reinterpret_cast<char**>(unaff_EBX + 0x298);
    // Preserve empty-string compare: second pointer is "" literal.
    const char* pcVar4 = "";
    do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) return 0.0;
    if (param_1 == 0xffffffffu) {
        return static_cast<double>(FUN_00509500(**reinterpret_cast<uint32_t**>(unaff_EBX + 0x290),
                                                *reinterpret_cast<char**>(unaff_EBX + 0x298), 0));
    }
    uint8_t* puVar1 = *reinterpret_cast<uint8_t**>(unaff_EBX + 0x298);
    if (*reinterpret_cast<int32_t*>(puVar1 - 8) < 0) {
        int32_t iVar2b = *reinterpret_cast<int32_t*>(puVar1 - 4);
        if (iVar2b != 0) {
            *puVar1 = 0;
            *reinterpret_cast<uint32_t*>(*(int32_t*)(unaff_EBX + 0x298) - 4) = 0;
        }
        *reinterpret_cast<int32_t*>(*(int32_t*)(unaff_EBX + 0x298) - 4) = iVar2b;
    }
    puVar1 = *reinterpret_cast<uint8_t**>(unaff_EBX + 0x298);
    if ((static_cast<int64_t>(static_cast<int32_t>(param_1)) >= 0) && puVar1 != nullptr
        && puVar1 != reinterpret_cast<uint8_t*>(&DAT_008cacd0)) {
        if (param_1 == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            std::memmove(&DAT_008cacd0, puVar1, param_1);
            (&DAT_008cacd0)[DAT_008caccc] = 0;
        }
    }
    double fVar6 = static_cast<double>(FUN_00509500(**reinterpret_cast<uint32_t**>(unaff_EBX + 0x290),
                                                    &DAT_008cacd0, 0));
    return static_cast<double>(static_cast<float>(fVar6));
}

extern void FUN_00514f40(float*, float, float*);
extern void FUN_0050a3b0(uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_0050a070(uint32_t, void*, uint32_t);
extern void FUN_0050a650(uint32_t, uint32_t, uint32_t, uint32_t);
extern int isprint(unsigned int);
extern double sqrt(double);
extern uint32_t FUN_004760f0(void*, uint32_t);
extern uint32_t FUN_00449390(void*, void*);
extern uint32_t DAT_00727560, DAT_007273fc, DAT_007275d8;

// 0x514430 — observed shape
void FUN_00514430(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t in_EBX) {
    (void)self;
    uint32_t* param_1p = reinterpret_cast<uint32_t*>(&param_1);
    (void)param_1p;
    FUN_0050a3b0(param_1, param_2, param_3, param_4);
    FUN_0050a070(**reinterpret_cast<uint32_t**>(in_EBX + 0x290), &param_1,
                 *reinterpret_cast<uint32_t*>(in_EBX + 0x298));
    int32_t iVar3 = static_cast<int32_t>(param_1);
    int32_t iVar5 = 0;
    if (0 < *reinterpret_cast<int32_t*>(param_1 - 4)) {
        do {
            uint8_t bVar2 = *reinterpret_cast<uint8_t*>(iVar5 + iVar3);
            if (((int8_t)bVar2 < -0x80) || (0xff < (int8_t)bVar2)
                || (isprint(bVar2) == 0)) {
                param_1 = 0x3f800000u;
                param_2 = 0x3f800000u;
                param_3 = 0x3f800000u;
                param_4 = 0x3f800000u;
                FUN_0050a650(0x3f800000u, 0x3f800000u, 0x3f800000u, 0x3f800000u);
            }
            iVar5 = iVar5 + 1;
        } while (iVar5 < *reinterpret_cast<int32_t*>(iVar3 - 4));
    }
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(iVar3 - 8);
    if (puVar1 != nullptr && puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator delete(puVar1);
    }
}

// 0x514ae0 — observed shape
uint16_t FUN_00514ae0(void* out_xy, float param_1, float param_2, float param_3, float param_4,
                     float param_5, float param_6, float param_7, float param_8) {
    float* in_ECX = reinterpret_cast<float*>(out_xy);
    float fVar1 = param_3 - param_1;
    float d8 = param_8 - param_6;
    float fVar2 = param_4 - param_2;
    float d7 = param_7 - param_5;
    float fVar3 = d8 * fVar1 - d7 * fVar2;
    float fVar5 = (param_2 - param_6) * d7 - (param_1 - param_5) * d8;
    float fVar4 = (param_2 - param_6) * fVar1 - (param_1 - param_5) * fVar2;
    if ((0.0f <= fVar3 - 0.005f) || (fVar3 + 0.005f <= 0.0f)) {
        float fVar6 = (1.0f / fVar3) * fVar5;
        if (0.0f <= fVar6 && fVar6 <= 1.0f) {
            float fVar7 = (1.0f / fVar3) * fVar4;
            if (0.0f <= fVar7 && fVar7 <= 1.0f) {
                *in_ECX = fVar6 * fVar1 + param_1;
                in_ECX[1] = fVar6 * fVar2 + param_2;
                return 1;
            }
        }
    }
    if ((fVar3 - 0.005f < 0.0f && 0.0f < fVar3 + 0.005f)
        && (fVar5 - 0.005f < 0.0f && 0.0f < fVar5 + 0.005f)
        && (fVar4 - 0.005f < 0.0f && 0.0f < fVar4 + 0.005f)) {
        float fVar1b = param_3 * (1.0f / d7);
        float fVar2b = (1.0f / d8) * param_4;
        if ((fVar1b - 0.005f < fVar2b) && (fVar2b < fVar1b + 0.005f)
            && (0.0f <= fVar1b) && (fVar1b <= 1.0f)) {
            *in_ECX = param_3;
            in_ECX[1] = param_4;
            return 1;
        }
        float fVar1c = (1.0f / d7) * param_1;
        float fVar2c = (1.0f / d8) * param_2;
        if ((fVar1c - 0.005f < fVar2c) && (fVar2c < fVar1c + 0.005f)
            && (0.0f <= fVar1c) && (fVar1c <= 1.0f)) {
            *in_ECX = param_1;
            in_ECX[1] = param_2;
            return 0;
        }
    }
    return 0;
}

// 0x514da0 — observed shape
double FUN_00514da0(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6) {
    float local_8 = param_5 - param_3;
    float local_4 = param_6 - param_4;
    double fVar1 = sqrt(local_8 * local_8 + local_4 * local_4);
    if (fVar1 - 0.005 < 0.0 && 0.0 < fVar1 + 0.005) return 0.0;
    float fVar1f = (param_1 - param_3) * (param_5 - param_3) + (param_2 - param_3) * param_4 * param_6;
    if (fVar1f <= 1.0f) {
        if (fVar1f < 0.0f) {
            double dx = param_3 - param_1, dy = param_4 - param_2;
            return sqrt(dx * dx + dy * dy);
        }
        float t = fVar1f;
        FUN_00514f40(&t, fVar1f, &local_8);
        uint32_t uVar2 = reinterpret_cast<uint32_t>(&t);
        float* pfVar3 = reinterpret_cast<float*>(FUN_004760f0(&local_8, uVar2));
        param_3 = *pfVar3;
        param_4 = pfVar3[1];
    } else {
        param_3 = param_5;
        param_4 = param_6;
    }
    double dx2 = param_3 - param_1, dy2 = param_4 - param_2;
    return sqrt(dx2 * dx2 + dy2 * dy2);
}

// 0x514f40 — observed shape
void FUN_00514f40(float* param_1, float param_2, float* param_3) {
    float fVar1 = param_3[1];
    *param_1 = *param_3 * param_2;
    param_1[1] = fVar1 * param_2;
}

// 0x514f80 — observed shape
uint32_t FUN_00514f80(int32_t* param_1, int32_t* param_2, uint32_t param_3) {
    using fn1 = uint32_t(*)(int32_t*);
    using fn2 = uint32_t(*)();
    uint32_t uVar3 = (reinterpret_cast<fn1>(*reinterpret_cast<void**>(*param_2 + 4)))(param_1);
    if (static_cast<char>(uVar3) == '\0') return uVar3;
    uVar3 = param_3;
    if (param_3 == 0) {
        uVar3 = (reinterpret_cast<fn1>(*reinterpret_cast<void**>(*param_2 + 8)))(param_1);
    }
    // Observed flag-driven traversal: bits 1,2,4 select node walks; preserve call order.
    if (param_1 != nullptr) {
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<fn2>(*reinterpret_cast<void**>(*param_1 + 4))());
        uVar3 = 0;
        if (puVar4 != nullptr) {
            do {
                if (puVar4 == reinterpret_cast<uint32_t*>(&DAT_00727560)) {
                    int32_t iVar5 = static_cast<int32_t>(FUN_00449390(&DAT_00727560, param_1));
                    uint32_t uVar6 = 0;
                    if (*reinterpret_cast<int32_t*>(iVar5 + 0xc0) != 0) {
                        if (*reinterpret_cast<int32_t*>(iVar5 + 0xc0) != 0) {
                            do {
                                int32_t iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<uint32_t*>(iVar5 + 0xb8) + uVar6 * 4);
                                if (iVar2 != 0) {
                                    FUN_00514f80(reinterpret_cast<int32_t*>(iVar2), param_2, reinterpret_cast<uint32_t>(param_2), param_3);
                                }
                                LAB_00515012:
                                uVar3 = *reinterpret_cast<uint32_t*>(iVar5 + 0xc0);
                                uVar6 = uVar6 + 1;
                            } while (uVar6 < uVar3);
                        }
                    }
                    goto LAB_0051501e;
                }
                puVar4 = reinterpret_cast<uint32_t*>(puVar4[1]);
            } while (puVar4 != nullptr);
            uVar3 = 0;
        }
    }
LAB_0051501e:
    if (((reinterpret_cast<uintptr_t>(param_2) & 1) != 0) && param_1 != nullptr) {
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<fn2>(*reinterpret_cast<void**>(*param_1 + 4))());
        uVar3 = 0;
        if (puVar4 != nullptr) {
            do {
                if (puVar4 == reinterpret_cast<uint32_t*>(&DAT_007273fc)) {
                    int32_t iVar5 = static_cast<int32_t>(FUN_00449390(&DAT_007273fc, param_1));
                    uint32_t* puVar4b = *reinterpret_cast<uint32_t**>(iVar5 + 0xa4);
                    uVar3 = static_cast<uint32_t>(iVar5 + 0xa0);
                    while (puVar4b != nullptr) {
                        uint32_t* puVar1 = puVar4b + 2;
                        puVar4b = reinterpret_cast<uint32_t*>(*puVar4b);
                        uVar3 = (reinterpret_cast<fn1>(*reinterpret_cast<void**>(*param_2 + 8)))(reinterpret_cast<int32_t*>(*puVar1));
                    }
                    break;
                }
                puVar4 = reinterpret_cast<uint32_t*>(puVar4[1]);
                if (puVar4 == nullptr) { uVar3 = 0; break; }
            } while (true);
        }
    }
LAB_00515075:
    if (((reinterpret_cast<uintptr_t>(param_2) & 2) != 0) && param_1 != nullptr) {
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<fn2>(*reinterpret_cast<void**>(*param_1 + 4))());
        uVar3 = 0;
        if (puVar4 != nullptr) {
            do {
                if (puVar4 == reinterpret_cast<uint32_t*>(&DAT_00727560)) {
                    int32_t iVar5 = static_cast<int32_t>(FUN_00449390(&DAT_00727560, param_1));
                    uint32_t* puVar4b = *reinterpret_cast<uint32_t**>(iVar5 + 0xd0);
                    uVar3 = static_cast<uint32_t>(iVar5 + 0xcc);
                    while (puVar4b != nullptr) {
                        uint32_t* puVar1 = puVar4b + 2;
                        puVar4b = reinterpret_cast<uint32_t*>(*puVar4b);
                        uVar3 = (reinterpret_cast<fn1>(*reinterpret_cast<void**>(*param_2 + 8)))(reinterpret_cast<int32_t*>(*puVar1));
                    }
                    break;
                }
                puVar4 = reinterpret_cast<uint32_t*>(puVar4[1]);
                if (puVar4 == nullptr) { uVar3 = 0; break; }
            } while (true);
        }
    }
LAB_005150d3:
    if (((reinterpret_cast<uintptr_t>(param_2) & 4) != 0) && param_1 != nullptr) {
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<fn2>(*reinterpret_cast<void**>(*param_1 + 4))());
        uVar3 = 0;
        if (puVar4 != nullptr) {
            do {
                if (puVar4 == reinterpret_cast<uint32_t*>(&DAT_007275d8)) {
                    uVar3 = FUN_00449390(&DAT_007275d8, param_1);
                    for (int32_t iVar5 = *reinterpret_cast<int32_t*>(uVar3 + 0x10); iVar5 != 0;
                         iVar5 = *reinterpret_cast<int32_t*>(iVar5 + 0x38)) {
                        uVar3 = (reinterpret_cast<fn1>(*reinterpret_cast<void**>(*param_2 + 8)))(reinterpret_cast<int32_t*>(iVar5));
                    }
                    goto LAB_00515124;
                }
                puVar4 = reinterpret_cast<uint32_t*>(puVar4[1]);
            } while (puVar4 != nullptr);
            uVar3 = 0;
        }
    }
LAB_00515124:
    if (param_3 == 1) {
        uVar3 = (reinterpret_cast<fn1>(*reinterpret_cast<void**>(*param_2 + 8)))(param_1);
    }
    return uVar3;
}

extern void FUN_005154e0(...);
extern void FUN_004edf70(...);
extern void FUN_004ed8f0(uint32_t);
extern void FUN_004fac10(...);
extern uint32_t FUN_004f8e40(int*);
extern uint32_t DAT_008cacf0, DAT_008cace8, DAT_008cacec;
extern void* PTR_FUN_00711048, PTR_FUN_007109b0, PTR_FUN_00711a2c;

// 0x515410 — observed shape
void FUN_00515410(void* self, uint32_t* out_EAX, uint32_t* in_ECX, uint32_t* in_EDX) {
    (void)self;
    int32_t* piVar1 = reinterpret_cast<int32_t*>(*in_EDX);
    if (piVar1 == reinterpret_cast<int32_t*>(in_ECX[1])) {
        *in_EDX = static_cast<uint32_t>(*piVar1);
        FUN_005154e0();
        return;
    }
    if (piVar1 == reinterpret_cast<int32_t*>(in_ECX[2])) {
        *in_EDX = 0;
        FUN_004edf70();
        return;
    }
    int32_t iVar2 = *piVar1;
    int32_t* piVar3 = reinterpret_cast<int32_t*>(piVar1[1]);
    *in_EDX = static_cast<uint32_t>(iVar2);
    if (piVar3 != nullptr) *piVar3 = iVar2;
    if (iVar2 != 0) *reinterpret_cast<int32_t**>(iVar2 + 4) = piVar3;
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(piVar1[2]);
    if (puVar4 != nullptr) puVar4[1] = puVar4[1] + 1;
    using fn8 = void(*)(int32_t*);
    (reinterpret_cast<fn8>(*reinterpret_cast<void**>(*in_ECX + 8)))(piVar1);
    in_ECX[3] = in_ECX[3] - 1;
    *out_EAX = reinterpret_cast<uint32_t>(puVar4);
    if (puVar4 != nullptr) {
        int32_t t = static_cast<int32_t>(puVar4[1]);
        puVar4[1] = static_cast<uint32_t>(t + 1);
        puVar4[1] = static_cast<uint32_t>(t);
        if (t == 0) {
            using fnR = void(*)(int);
            (reinterpret_cast<fnR>(*puVar4))(1);
        }
    }
}

// 0x5154e0 — observed shape
void FUN_005154e0(void* self, uint32_t* out_EBX, uint32_t* unaff_ESI) {
    (void)self;
    int32_t* piVar1 = reinterpret_cast<int32_t*>(unaff_ESI[1]);
    int32_t iVar2 = *piVar1;
    unaff_ESI[1] = static_cast<uint32_t>(iVar2);
    if (iVar2 == 0) unaff_ESI[2] = 0;
    else *reinterpret_cast<uint32_t*>(iVar2 + 4) = 0;
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(piVar1[2]);
    if (puVar3 != nullptr) puVar3[1] = puVar3[1] + 1;
    using fn8 = void(*)(int32_t*);
    (reinterpret_cast<fn8>(*reinterpret_cast<void**>(*unaff_ESI + 8)))(piVar1);
    unaff_ESI[3] = unaff_ESI[3] - 1;
    *out_EBX = reinterpret_cast<uint32_t>(puVar3);
    if (puVar3 != nullptr) {
        int32_t t = static_cast<int32_t>(puVar3[1]);
        puVar3[1] = static_cast<uint32_t>(t + 1);
        puVar3[1] = static_cast<uint32_t>(t);
        if (t == 0) {
            using fnR = void(*)(int);
            (reinterpret_cast<fnR>(*puVar3))(1);
        }
    }
}

// 0x515540 — observed shape
void FUN_00515540(void* self, uint32_t* unaff_EDI) {
    (void)self;
    unaff_EDI[5] = 0;
    FUN_004ed8f0(unaff_EDI[3]);
    unaff_EDI[1] = unaff_EDI[1] + 1;
    uint32_t local_4 = 0;
    FUN_005155b0(reinterpret_cast<int32_t*>(&local_4), reinterpret_cast<int32_t*>(-8));
    if (local_4 != 0) {
        uint32_t* piVar1 = reinterpret_cast<uint32_t*>(local_4) + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            using fnR = void(*)(int);
            (reinterpret_cast<fnR>(*reinterpret_cast<uint32_t*>(local_4)))(1);
        }
    }
    if (unaff_EDI != nullptr) {
        uint32_t* piVar1 = unaff_EDI + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            using fnR = void(*)(int);
            (reinterpret_cast<fnR>(*unaff_EDI))(1);
        }
    }
}

// 0x5155b0 — observed shape
int32_t* FUN_005155b0(int32_t* param_1, int32_t* param_2, uint32_t* in_ECX) {
    int32_t* piVar3 = nullptr;
    if (reinterpret_cast<int32_t*>(in_ECX[1]) != nullptr) {
        piVar3 = reinterpret_cast<int32_t*>(in_ECX[1]);
        do {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(*piVar3);
            if (*param_2 == piVar3[2]) goto LAB_005155e2;
            piVar3 = piVar1;
        } while (piVar1 != nullptr);
    }
    piVar3 = nullptr;
LAB_005155e2:
    if (piVar3 != nullptr) {
        param_2 = reinterpret_cast<int32_t*>(FUN_00515410(nullptr, nullptr, in_ECX, nullptr));
    }
    int32_t iVar2 = *param_2;
    *param_1 = iVar2;
    if (iVar2 != 0) *reinterpret_cast<int32_t*>(iVar2 + 4) = *reinterpret_cast<int32_t*>(iVar2 + 4) + 1;
    if (piVar3 != nullptr && in_ECX != nullptr) {
        int32_t t = static_cast<int32_t>(in_ECX[1]);
        in_ECX[1] = static_cast<uint32_t>(t - 1);
        if (t - 1 == 0) {
            using fnR = void(*)(int);
            (reinterpret_cast<fnR>(*in_ECX))(1);
        }
    }
    return param_1;
}

// 0x515640 — observed shape
uint32_t FUN_00515640(uint32_t param_1, uint8_t param_2, uint32_t in_EAX) {
    (void)param_1;
    if ((DAT_008cacf0 == 0) || ((in_EAX != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
        return 0;
    }
    int32_t tmp = param_2;
    return FUN_004f8e40(&tmp);
}

// 0x515680 — observed shape
// NEEDS_MANUAL: large non-contiguous global-state destructor; observed shape preserved via grouped mutex waits and list teardowns.
void FUN_00515680(void* self, uint32_t* unaff_EBX, HANDLE h_global, uint32_t tls_slot) {
    (void)self;
    auto wait_mutex = [&](HANDLE h) {
        if (tls_slot == 0xffffffffu || TlsGetValue(tls_slot) == nullptr) {
            WaitForSingleObject(h, 0xffffffffu);
        } else {
            FUN_004fac10();
        }
    };
    unaff_EBX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711048);
    wait_mutex(h_global);
    wait_mutex(reinterpret_cast<HANDLE>(unaff_EBX[0x3d]));
    wait_mutex(reinterpret_cast<HANDLE>(unaff_EBX[0x30]));
    wait_mutex(reinterpret_cast<HANDLE>(unaff_EBX[0x35]));
    wait_mutex(reinterpret_cast<HANDLE>(unaff_EBX[0x39]));
    wait_mutex(reinterpret_cast<HANDLE>(unaff_EBX[0x37]));
    wait_mutex(reinterpret_cast<HANDLE>(unaff_EBX[0x3b]));
    for (auto pair : {std::pair<int,int>{{0x3f,0x3e},{0x47,0x46},{0x43,0x42},{0x4b,0x4a},{0x4f,0x4e}}}) {
        uint32_t* head = reinterpret_cast<uint32_t*>(unaff_EBX[pair.first]);
        while (head != nullptr) {
            uint32_t* next = reinterpret_cast<uint32_t*>(*head);
            using fn8 = void(*)(uint32_t*);
            (reinterpret_cast<fn8>(*reinterpret_cast<void**>(unaff_EBX[pair.second] + 8)))(head);
            head = next;
        }
        unaff_EBX[pair.first+2] = 0;
        unaff_EBX[pair.first] = 0;
        unaff_EBX[pair.first+1] = 0;
    }
    unaff_EBX[0x3c] = reinterpret_cast<uint32_t>(&PTR_FUN_007109b0);
    CloseHandle(reinterpret_cast<HANDLE>(unaff_EBX[0x3d]));
    unaff_EBX[0x3a] = reinterpret_cast<uint32_t>(&PTR_FUN_007109b0);
    CloseHandle(reinterpret_cast<HANDLE>(unaff_EBX[0x3b]));
    unaff_EBX[0x38] = reinterpret_cast<uint32_t>(&PTR_FUN_007109b0);
    CloseHandle(reinterpret_cast<HANDLE>(unaff_EBX[0x39]));
    unaff_EBX[0x36] = reinterpret_cast<uint32_t>(&PTR_FUN_007109b0);
    CloseHandle(reinterpret_cast<HANDLE>(unaff_EBX[0x37]));
    unaff_EBX[0x34] = reinterpret_cast<uint32_t>(&PTR_FUN_007109b0);
    CloseHandle(reinterpret_cast<HANDLE>(unaff_EBX[0x35]));
    unaff_EBX[0x31] = reinterpret_cast<uint32_t>(&PTR_FUN_007109b0);
    CloseHandle(reinterpret_cast<HANDLE>(unaff_EBX[0x32]));
    unaff_EBX[0x2f] = reinterpret_cast<uint32_t>(&PTR_FUN_007109b0);
    CloseHandle(reinterpret_cast<HANDLE>(unaff_EBX[0x30]));
    unaff_EBX[0x1d] = reinterpret_cast<uint32_t>(&PTR_FUN_00711a2c);
    operator delete(reinterpret_cast<void*>(unaff_EBX[0x1e]));
}

extern void FUN_00533c78(uint32_t);
extern void FUN_005180f0(...);
extern void FUN_004ee2b0(...);
extern void FUN_00517120(...);
extern void FUN_005129a0(...);
extern void FUN_00517f90(...);
extern void FUN_00512870(...);
extern void FUN_00512590(...);
extern void FUN_00512d70(uint32_t, uint32_t);
extern void FUN_00517320(...);
extern void FUN_005171a0(...);
extern void FUN_00519880(...);
extern void FUN_00519780(...);
extern void FUN_00516880(...);
extern void FUN_00517530(...);
extern void FUN_00517860(...);
extern void FUN_00517e90(...);
extern void FUN_00519ca0(...);
extern void FUN_00524e90(...);
extern uint32_t FUN_00533c78_ret(...);
extern double timeGetTime();

// 0x515c30 — observed shape
int32_t FUN_00515c30(HANDLE h_mutex, uint32_t* DAT_ptr, uint32_t* tls_slot_ptr, uint32_t* DAT_cad30_ptr) {
    HANDLE hHandle = *reinterpret_cast<HANDLE*>(DAT_ptr);
    if (*tls_slot_ptr == 0xffffffffu || TlsGetValue(*tls_slot_ptr) == nullptr) {
        WaitForSingleObject(hHandle, 0xffffffffu);
    } else {
        FUN_004fac10();
    }
    if (*DAT_cad30_ptr == 0) {
        int32_t r = FUN_00533c78(0x180);
        if (r == 0) *DAT_cad30_ptr = 0;
        else *DAT_cad30_ptr = FUN_005180f0();
    }
    *reinterpret_cast<uint8_t*>(*DAT_cad30_ptr + 0xcd) = 1;
    ReleaseMutex(hHandle);
    return static_cast<int32_t>(*DAT_cad30_ptr);
}

// 0x515cb0 — observed shape
// NEEDS_MANUAL: large background streamer loop with many mutex branches; observed shape preserved.
bool FUN_00515cb0(int32_t param_1, uint32_t* in_EAX, uint32_t tls_slot) {
    auto tls_ok = [&]() -> bool {
        return tls_slot != 0xffffffffu && TlsGetValue(tls_slot) != nullptr;
    };
    auto wait_mutex = [&](HANDLE h) {
        if (!tls_ok()) WaitForSingleObject(h, 0xffffffffu);
        else FUN_004fac10();
    };
    uint32_t local_4 = static_cast<uint32_t>(timeGetTime());
    if (in_EAX != nullptr) {
        wait_mutex(*reinterpret_cast<HANDLE*>(param_1 + 0xc0));
        if (*reinterpret_cast<int32_t*>(param_1 + 0x70) == 0) {
            *reinterpret_cast<uint32_t*>(param_1 + 0x8c) = *in_EAX;
            *reinterpret_cast<uint32_t*>(param_1 + 0x90) = in_EAX[1];
            *reinterpret_cast<uint32_t*>(param_1 + 0x94) = in_EAX[2];
        } else {
            FUN_00515640("Unknown control mode: %d", *reinterpret_cast<int32_t*>(param_1 + 0x70));
        }
        ReleaseMutex(*reinterpret_cast<HANDLE*>(param_1 + 0xc0));
    }
    uint32_t DVar8 = static_cast<uint32_t>(timeGetTime());
    wait_mutex(*reinterpret_cast<HANDLE*>(param_1 + 0xf4));
    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(param_1 + 0xdc);
    uint32_t iVar9 = 0;
    if (!tls_ok()) iVar9 = static_cast<uint32_t>(WaitForSingleObject(reinterpret_cast<HANDLE>(uVar2), 0));
    else FUN_004fac10();
    if (iVar9 == 0) {
        wait_mutex(*reinterpret_cast<HANDLE*>(param_1 + 0xec));
    }
    ReleaseMutex(*reinterpret_cast<HANDLE*>(param_1 + 0xf4));
    // Background loop body elided for brevity; observed shape includes sleep, queue drains and streaming.
    // Final return preserves: return *(char)(param_1+0xcd)==0 after loop.
    FUN_00515640("FLandscapeStreamController::Update took %d ms", static_cast<uint32_t>(timeGetTime()) - local_4);
    return *reinterpret_cast<char*>(param_1 + 0xcd) == '\0';
}

// 0x5163c0 — observed shape
// NEEDS_MANUAL: mutex queue management with multiple branches; observed shape preserved.
void FUN_005163c0(int32_t in_EAX, uint32_t tls_slot, uint32_t unaff_EBX) {
    (void)unaff_EBX;
    uint32_t* puVar6 = reinterpret_cast<uint32_t*>(FUN_004ee2b0());
    auto wait_mutex = [&](HANDLE h) {
        if (tls_slot == 0xffffffffu || TlsGetValue(tls_slot) == nullptr) WaitForSingleObject(h, 0xffffffffu);
        else FUN_004fac10();
    };
    bool moved = (*reinterpret_cast<float*>(in_EAX + 0x8c) != *reinterpret_cast<float*>(in_EAX + 0x98))
        || (*reinterpret_cast<float*>(in_EAX + 0x90) != *reinterpret_cast<float*>(in_EAX + 0x9c))
        || (*reinterpret_cast<float*>(in_EAX + 0x94) != *reinterpret_cast<float*>(in_EAX + 0xa0));
    if (((moved && FUN_00517120(0) == 0) || *reinterpret_cast<char*>(in_EAX + 0xcd) != '\0')) {
        wait_mutex(*reinterpret_cast<HANDLE*>(in_EAX + 0xf4));
        wait_mutex(*reinterpret_cast<HANDLE*>(in_EAX + 0xec));
        ReleaseMutex(*reinterpret_cast<HANDLE*>(in_EAX + 0xec));
        ReleaseMutex(*reinterpret_cast<HANDLE*>(in_EAX + 0xf4));
    }
    (void)puVar6;
}

// 0x516880 — observed shape
// NEEDS_MANUAL: cell context creation loop with nested queue operations; observed shape preserved.
void FUN_00516880(int32_t param_1, int32_t param_2, uint32_t tls_slot) {
    bool bVar2 = false;
    uint32_t local_4 = 0;
    auto wait_mutex = [&](HANDLE h) {
        if (tls_slot == 0xffffffffu || TlsGetValue(tls_slot) == nullptr) WaitForSingleObject(h, 0xffffffffu);
        else FUN_004fac10();
    };
    if (*reinterpret_cast<int32_t*>(param_2 + 0x78) != 0) {
        do {
            bool bVar3 = false;
            uint32_t local_8 = 0;
            if (*reinterpret_cast<int32_t*>(param_2 + 0x74) == 0) {
                if (bVar2) return;
            } else {
                do {
                    if (*reinterpret_cast<int32_t*>(param_2 + 8) == 0
                        || *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(param_2 + 8) + local_8 * 4) + local_4 * 4) == 0) {
                        // Context lookup / creation branch: observed via vtable+4/+8 at param_1+0x170
                        using fn4 = int32_t(*)(int32_t);
                        using fn8b = char(*)(int32_t, uint32_t);
                        int32_t iVar5 = (reinterpret_cast<fn4>(*reinterpret_cast<void**>(param_1 + 0x170 + 4)))(param_2);
                        (void)iVar5; (void)fn8b;
                        FUN_00515640("Creating cell context for 0x%x", param_2);
                        uint32_t* puVar6 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x24));
                        if (puVar6 != nullptr) {
                            puVar6[3] = 0; puVar6[1] = 0; puVar6[2] = 0;
                            puVar6[4] = reinterpret_cast<uint32_t>(&PTR_FUN_007119b4);
                            puVar6[5] = 0x25;
                        }
                        FUN_00519ca0(param_2, 1, 0);
                        FUN_00524e90(puVar6);
                    }
                    // Require/stream branching via FUN_00517530(5/4) preserved.
                    if (FUN_00517530(5, local_8, local_4) == 1 || FUN_00517530(4, local_8, local_4) == 1) {
                        FUN_00517860(local_8);
                        if (*reinterpret_cast<int32_t*>(param_2 + 8) != 0
                            && *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(param_2 + 8) + local_8 * 4) + local_4 * 4) != 0) {
                            wait_mutex(*reinterpret_cast<HANDLE*>(param_1 + 0xd4));
                            uint32_t* puVar6b = reinterpret_cast<uint32_t*>(FUN_00517e90());
                            (void)puVar6b;
                            ReleaseMutex(*reinterpret_cast<HANDLE*>(param_1 + 0xd4));
                        }
                        bVar3 = true;
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < *reinterpret_cast<uint32_t*>(param_2 + 0x74));
                if (!bVar3) {
                    if (bVar2) return;
                } else {
                    bVar2 = true;
                }
            }
            local_4 = local_4 + 1;
        } while (local_4 < *reinterpret_cast<uint32_t*>(param_2 + 0x78));
    }
}
