// Reconstruction batch mass_0167 — Sid Meier's Pirates! (2004) PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* thunk_FUN_00533c78(unsigned int size);
extern void FUN_005692c0(int param_1);
extern void FUN_005692e0(int param_1, int param_2);
extern void FUN_0056be80(int param_1, int param_2);
extern uint32_t FUN_0056e300(int param_1, int param_2);
extern char FUN_0059aac0(int param_1);
extern unsigned char DAT_007283b0;
extern void* _DAT_00728940;
extern void* _DAT_00728670;
extern void* _DAT_007285f8;
extern void* _DAT_00728580;
extern void* _DAT_00728508;
extern void FUN_0056bee0(int param_1, int param_2);
extern void FUN_0056bf80(int param_1, int param_2, int param_3);

// 0x56bee0 — observed shape
int* FUN_0056bee0(int param_1, int param_2) {
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(static_cast<unsigned int>(param_2 * 0x50 + 4)));
    int* piVar3;
    if (piVar1 == nullptr) {
        piVar3 = nullptr;
    } else {
        *piVar1 = param_2;
        piVar3 = piVar1 + 1;
        if (-1 < param_2 + -1) {
            piVar1 = piVar1 + 2;
            int iVar2 = param_2;
            do {
                *reinterpret_cast<unsigned char*>(piVar1) = 0x50;
                piVar1 = piVar1 + 0x14;
                iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
        }
    }
    if (param_2 != 0) {
        piVar1 = piVar3 + 6;
        do {
            FUN_005692c0(param_1);
            auto vtable = *reinterpret_cast<int**>(param_1 + 0x15c);
            auto fn = *reinterpret_cast<void(__cdecl**)(int*,int)>(reinterpret_cast<char*>(vtable) + 8);
            fn(piVar1 + -1, 4);
            fn(piVar1, 4);
            fn(piVar1 + 1, 4);
            piVar1 = piVar1 + 0x14;
            param_2 = param_2 + -1;
        } while (param_2 != 0);
    }
    return piVar3;
}

// 0x56bf80 — observed shape
void FUN_0056bf80(int param_1, int param_2, int param_3) {
    if (param_3 != 0) {
        param_2 = param_2 + 0x18;
        do {
            FUN_005692e0(param_1, param_2 + -0x18);
            auto vtable = *reinterpret_cast<int**>(param_1 + 0x160);
            auto fn = *reinterpret_cast<void(__cdecl**)(int*,int)>(reinterpret_cast<char*>(vtable) + 0xc);
            fn(reinterpret_cast<int*>(param_2 + -4), 4);
            fn(reinterpret_cast<int*>(param_2), 4);
            fn(reinterpret_cast<int*>(param_2 + 4), 4);
            param_2 = param_2 + 0x50;
            param_3 = param_3 + -1;
        } while (param_3 != 0);
    }
}

// 0x56bfe0 — observed shape
uint32_t FUN_0056bfe0(void) {
    if (DAT_007283b0 == '\0') {
        DAT_007283b0 = 1;
        _DAT_00728940 = reinterpret_cast<void*>(FUN_0056bee0);
        _DAT_00728670 = reinterpret_cast<void*>(FUN_0056bf80);
        _DAT_007285f8 = reinterpret_cast<void*>(0x56b450);
        _DAT_00728580 = reinterpret_cast<void*>(0x56b5a0);
        _DAT_00728508 = reinterpret_cast<void*>(0x56b110);
        FUN_0056be80(1, 3);
        return 1;
    }
    return 0;
}

// 0x56c130 — observed shape
uint32_t FUN_0056c130(int param_1, int param_2) {
    uint32_t uVar2 = FUN_0056e300(param_1, param_2);
    if (static_cast<char>(uVar2) == '\0') {
        return uVar2;
    }
    if ((*reinterpret_cast<float*>(param_1 + 0x18) == *reinterpret_cast<float*>(param_2 + 0x18)) &&
        (*reinterpret_cast<float*>(param_1 + 0x1c) == *reinterpret_cast<float*>(param_2 + 0x1c)) &&
        (*reinterpret_cast<float*>(param_1 + 0x20) == *reinterpret_cast<float*>(param_2 + 0x20))) {
        char cVar1 = FUN_0059aac0(param_2 + 0x24);
        if (cVar1 != '\0') {
            cVar1 = FUN_0059aac0(param_2 + 0x34);
            if (cVar1 != '\0') {
                return 1;
            }
        }
    }
    return 0;
}

// 0x56c1b0 — observed shape
int* FUN_0056c1b0(int param_1) {
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(static_cast<unsigned int>(param_1 * 0x44 + 4)));
    if (piVar1 == nullptr) {
        return nullptr;
    }
    *piVar1 = param_1;
    if (-1 < param_1 + -1) {
        int* piVar2 = piVar1 + 2;
        do {
            *reinterpret_cast<unsigned char*>(piVar2) = 8;
            *reinterpret_cast<unsigned char*>(*(reinterpret_cast<void**>(piVar2 + 1))) = 0;
            *reinterpret_cast<unsigned char*>(piVar2) = 0x44;
            piVar2 = piVar2 + 0x11;
            param_1 = param_1 + -1;
        } while (param_1 != 0);
    }
    return piVar1 + 1;
}

extern uint32_t FUN_00555c50(void* out, float* a, unsigned char* b, float* c);
extern uint32_t FUN_00555bc0(void* a, void* b);
extern uint32_t FUN_00555cf0(void* out, uint32_t v);
extern uint32_t FUN_0055eae0(void* out, float v, void* a);
extern void FUN_00555b30(void* a, uint32_t b);
extern uint32_t FUN_00555b60(void* a, void* b);
extern uint32_t FUN_0055ebf0(void* out, uint32_t v);
extern void FUN_0056a340(int param_1, unsigned int param_2);
extern char FUN_005762b0(int param_1, int* a, unsigned int b, unsigned int* out);
extern void FUN_004127b0(void* dst, unsigned int size, unsigned int count, void* init);
extern void FUN_0056a280(void* out, int param_1, int* a, int b, unsigned int c);
extern void operator_delete__(void* p);
extern void FUN_0056a010(int param_1);
extern void FUN_0056a030(int param_1, int param_2);

// 0x56c210 — observed shape
void FUN_0056c210(float* param_1, float* param_2, float* self) {
    unsigned char local_80[16]; unsigned char local_70[16]; unsigned char local_60[16]; unsigned char local_50[16];
    unsigned char local_40[16]; unsigned char local_30[16]; unsigned char local_20[16]; unsigned char local_10[16];
    float* pfVar9 = self + 2;
    unsigned char* puVar10 = local_70;
    float* pfVar11 = pfVar9;
    FUN_00555c50(local_80, param_1 + 2, puVar10, pfVar9);
    uint32_t uVar8 = FUN_00555bc0(puVar10, pfVar11);
    FUN_00555cf0(local_50, uVar8);
    pfVar11 = param_2 + 2;
    puVar10 = local_80;
    FUN_00555c50(local_70, pfVar9, puVar10, pfVar11);
    uVar8 = FUN_00555bc0(puVar10, pfVar11);
    FUN_00555cf0(local_60, uVar8);
    float fVar5 = 1.0f / (param_2[0] - param_1[0]);
    float fVar6 = 1.0f - self[6];
    float fVar1 = self[7];
    float fVar2 = self[7];
    float fVar3 = self[8];
    float fVar4 = self[8];
    float fVar7 = (self[0] - param_1[0]) * fVar5;
    uVar8 = FUN_0055eae0(local_80, fVar7 * (fVar4 + 1.0f) * (fVar2 + 1.0f) * fVar6, local_50);
    puVar10 = local_20;
    FUN_0055eae0(local_70, fVar7 * (1.0f - fVar3) * (1.0f - fVar1) * fVar6, local_60, puVar10, uVar8);
    FUN_00555b30(puVar10, uVar8);
    uVar8 = FUN_00555b60(local_80, local_60);
    uVar8 = FUN_0055eae0(local_70, 0x3f000000, uVar8);
    uVar8 = FUN_0055ebf0(local_30, uVar8);
    pfVar9 = reinterpret_cast<float*>(static_cast<uintptr_t>(FUN_00555bc0(local_40, reinterpret_cast<void*>(uVar8))));
    self[9] = pfVar9[0]; self[10] = pfVar9[1]; self[11] = pfVar9[2]; self[12] = pfVar9[3];
    fVar5 = (param_2[0] - self[0]) * fVar5;
    uVar8 = FUN_0055eae0(local_40, fVar5 * (fVar4 + 1.0f) * (1.0f - fVar1) * fVar6, local_50);
    puVar10 = local_10;
    FUN_0055eae0(local_30, fVar5 * (1.0f - fVar3) * (fVar2 + 1.0f) * fVar6, local_60, puVar10, uVar8);
    FUN_00555b30(puVar10, uVar8);
    uVar8 = FUN_00555b60(local_40, local_10);
    uVar8 = FUN_0055eae0(local_30, 0x3f000000, uVar8);
    uVar8 = FUN_0055ebf0(local_80, uVar8);
    pfVar9 = reinterpret_cast<float*>(static_cast<uintptr_t>(FUN_00555bc0(local_70, reinterpret_cast<void*>(uVar8))));
    self[13] = pfVar9[0]; self[14] = pfVar9[1]; self[15] = pfVar9[2]; self[16] = pfVar9[3];
}

// 0x56c470 — observed shape
void FUN_0056c470(int param_1, unsigned int param_2) {
    if (1 < param_2) {
        FUN_0056a340(param_1, param_2);
        FUN_0056c210(reinterpret_cast<float*>(param_1), reinterpret_cast<float*>(param_1 + 0x44), nullptr);
        if (1 < param_2 - 1) {
            unsigned int iVar2 = param_2 - 2;
            int iVar1 = param_1;
            do {
                FUN_0056c210(reinterpret_cast<float*>(iVar1), reinterpret_cast<float*>(iVar1 + 0x88), nullptr);
                iVar2 = iVar2 - 1;
                iVar1 = iVar1 + 0x44;
            } while (iVar2 != 0);
        }
        FUN_0056c210(reinterpret_cast<float*>((param_2 - 2) * 0x44 + param_1), reinterpret_cast<float*>((param_2 - 1) * 0x44 + param_1), nullptr);
    }
}

// 0x56c4e0 — observed shape
uint32_t FUN_0056c4e0(int param_1, uint32_t* param_2, unsigned int* param_3) {
    int* piVar5 = reinterpret_cast<int*>(*param_2);
    int* local_14 = piVar5;
    unsigned int local_18 = 0;
    char cVar1 = FUN_005762b0(param_1, piVar5, *param_3, &local_18);
    if (cVar1 == '\0') return 0;
    int iVar6 = *param_3 + 1;
    int* piVar2 = static_cast<int*>(thunk_FUN_00533c78(static_cast<unsigned int>(iVar6 * 0x44 + 4)));
    int* piVar4;
    if (piVar2 == nullptr) piVar4 = nullptr;
    else { piVar4 = piVar2 + 1; *piVar2 = iVar6; FUN_004127b0(piVar4, 0x44, static_cast<unsigned int>(iVar6), reinterpret_cast<void*>(0x56c110)); }
    piVar2 = piVar4;
    for (unsigned int uVar3 = local_18 * 0x44 >> 2; uVar3 != 0; uVar3--) { *piVar2 = *piVar5; piVar5++; piVar2++; }
    for (iVar6 = 0; iVar6 != 0; iVar6--) { *reinterpret_cast<char*>(piVar2) = static_cast<char>(*reinterpret_cast<char*>(piVar5)); piVar5 = reinterpret_cast<int*>(reinterpret_cast<char*>(piVar5) + 1); piVar2 = reinterpret_cast<int*>(reinterpret_cast<char*>(piVar2) + 1); }
    if (local_18 < *param_3) {
        piVar5 = local_14 + local_18 * 0x11;
        piVar2 = piVar4 + local_18 * 0x11 + 0x11;
        for (unsigned int uVar3 = (*param_3 - local_18) * 0x44 >> 2; uVar3 != 0; uVar3--) { *piVar2 = *piVar5; piVar5++; piVar2++; }
        for (iVar6 = 0; iVar6 != 0; iVar6--) { *reinterpret_cast<char*>(piVar2) = static_cast<char>(*reinterpret_cast<char*>(piVar5)); piVar5 = reinterpret_cast<int*>(reinterpret_cast<char*>(piVar5) + 1); piVar2 = reinterpret_cast<int*>(reinterpret_cast<char*>(piVar2) + 1); }
    }
    int local_10; int local_c; int local_8; int local_4;
    FUN_0056a280(&local_10, param_1, local_14, 3, *param_3);
    piVar5 = piVar4 + local_18 * 0x11;
    piVar5[0] = param_1; piVar5[2] = local_10; piVar5[3] = local_c; piVar5[4] = local_8; piVar5[5] = local_4;
    piVar5[6] = 0; piVar5[7] = 0; piVar5[8] = 0;
    *param_3 = *param_3 + 1;
    if (local_14 != nullptr) operator_delete__(local_14 + -1);
    *param_2 = reinterpret_cast<uint32_t>(piVar4);
    FUN_0056c470(reinterpret_cast<int>(piVar4), *param_3);
    return 1;
}

// 0x56c620 — observed shape
int* FUN_0056c620(int param_1, int param_2) {
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(static_cast<unsigned int>(param_2 * 0x44 + 4)));
    int* piVar2;
    if (piVar1 == nullptr) piVar2 = nullptr;
    else {
        *piVar1 = param_2; piVar2 = piVar1 + 1;
        if (-1 < param_2 + -1) {
            piVar1 = piVar1 + 2; int iVar3 = param_2;
            do { *reinterpret_cast<unsigned char*>(piVar1) = 8; *reinterpret_cast<unsigned char*>(piVar1) = 0x44; piVar1 = piVar1 + 0x11; iVar3--; } while (iVar3 != 0);
        }
    }
    if (param_2 != 0) {
        piVar1 = piVar2 + 7;
        do {
            FUN_0056a010(param_1);
            auto vtable = *reinterpret_cast<int**>(param_1 + 0x15c);
            auto fn = *reinterpret_cast<void(__cdecl**)(int*,int)>(reinterpret_cast<char*>(vtable) + 8);
            fn(piVar1 + -1, 4); fn(piVar1, 4); fn(piVar1 + 1, 4);
            piVar1 = piVar1 + 0x11; param_2--;
        } while (param_2 != 0);
    }
    return piVar2;
}

// 0x56c6d0 — observed shape
void FUN_0056c6d0(int param_1, int param_2, int param_3) {
    if (param_3 != 0) {
        param_2 = param_2 + 0x1c;
        do {
            FUN_0056a030(param_1, param_2 + -0x1c);
            auto vtable = *reinterpret_cast<int**>(param_1 + 0x160);
            auto fn = *reinterpret_cast<void(__cdecl**)(int*,int)>(reinterpret_cast<char*>(vtable) + 0xc);
            fn(reinterpret_cast<int*>(param_2 + -4), 4);
            fn(reinterpret_cast<int*>(param_2), 4);
            fn(reinterpret_cast<int*>(param_2 + 4), 4);
            param_2 = param_2 + 0x44; param_3--;
        } while (param_3 != 0);
    }
}

extern unsigned char DAT_007283b1;
extern void* _DAT_007288dc;
extern void* _DAT_007287ec;
extern void* _DAT_00728774;
extern void* _DAT_00728954;
extern void* _DAT_00728684;
extern void* _DAT_0072860c;
extern void* _DAT_00728594;
extern void* _DAT_0072851c;
extern void* _DAT_00728864;
extern void* _DAT_007286fc;
extern void* _DAT_0072842c;
extern void* _DAT_007284a4;

// 0x56c730 — observed shape
uint32_t FUN_0056c730(void) {
    if (DAT_007283b1 == '\0') {
        _DAT_007288dc = nullptr; _DAT_007287ec = nullptr; _DAT_00728774 = nullptr;
        DAT_007283b1 = 1;
        _DAT_00728954 = reinterpret_cast<void*>(0x56c620);
        _DAT_00728684 = reinterpret_cast<void*>(0x56c6d0);
        _DAT_0072860c = reinterpret_cast<void*>(0x56c040);
        _DAT_00728594 = reinterpret_cast<void*>(0x56c1b0);
        _DAT_0072851c = reinterpret_cast<void*>(0x56b110);
        _DAT_00728864 = reinterpret_cast<void*>(0x56c0c0);
        _DAT_007286fc = reinterpret_cast<void*>(0x56c130);
        _DAT_0072842c = reinterpret_cast<void*>(0x56c470);
        _DAT_007284a4 = reinterpret_cast<void*>(0x56c4e0);
        return 1;
    }
    return 0;
}

// 0x56c800 — observed shape
int* FUN_0056c800(int param_1) {
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(static_cast<unsigned int>(param_1 * 0x18 + 4)));
    if (piVar1 == nullptr) return nullptr;
    *piVar1 = param_1;
    if (-1 < param_1 + -1) {
        int* piVar2 = piVar1 + 2;
        do { *reinterpret_cast<unsigned char*>(piVar2) = 8; *reinterpret_cast<unsigned char*>(piVar2) = 0x18; piVar2 = piVar2 + 6; param_1--; } while (param_1 != 0);
    }
    return piVar1 + 1;
}

// 0x56c8a0 — observed shape
int* FUN_0056c8a0(uint32_t param_1, int param_2) {
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(static_cast<unsigned int>(param_2 * 0x18 + 4)));
    int* piVar3;
    if (piVar1 == nullptr) piVar3 = nullptr;
    else {
        *piVar1 = param_2; piVar3 = piVar1 + 1;
        if (-1 < param_2 + -1) {
            piVar1 = piVar1 + 2; int iVar2 = param_2;
            do { *reinterpret_cast<unsigned char*>(piVar1) = 8; *reinterpret_cast<unsigned char*>(piVar1) = 0x18; piVar1 = piVar1 + 6; iVar2--; } while (iVar2 != 0);
        }
    }
    for (; param_2 != 0; param_2--) FUN_0056a010(static_cast<int>(param_1));
    return piVar3;
}

// 0x56c920 — observed shape
void FUN_0056c920(uint32_t param_1, int param_2, int param_3) {
    if (param_3 != 0) {
        do { FUN_0056a030(static_cast<int>(param_1), param_2); param_2 += 0x18; param_3--; } while (param_3 != 0);
    }
}

// 0x56c950 — observed shape
uint32_t FUN_0056c950(int param_1, uint32_t* param_2, unsigned int* param_3) {
    int* piVar5 = reinterpret_cast<int*>(*param_2);
    int* local_14 = piVar5;
    unsigned int local_18 = 0;
    char cVar1 = FUN_005762b0(param_1, piVar5, *param_3, &local_18);
    if (cVar1 == '\0') return 0;
    int iVar6 = *param_3 + 1;
    int* piVar2 = static_cast<int*>(thunk_FUN_00533c78(static_cast<unsigned int>(iVar6 * 0x18 + 4)));
    int* piVar4;
    if (piVar2 == nullptr) piVar4 = nullptr;
    else { piVar4 = piVar2 + 1; *piVar2 = iVar6; FUN_004127b0(piVar4, 0x18, static_cast<unsigned int>(iVar6), reinterpret_cast<void*>(0x56c7d0)); }
    piVar2 = piVar4;
    for (unsigned int uVar3 = local_18 * 0x18 >> 2; uVar3 != 0; uVar3--) { *piVar2 = *piVar5; piVar5++; piVar2++; }
    for (iVar6 = 0; iVar6 != 0; iVar6--) { *reinterpret_cast<char*>(piVar2) = static_cast<char>(*reinterpret_cast<char*>(piVar5)); piVar5 = reinterpret_cast<int*>(reinterpret_cast<char*>(piVar5) + 1); piVar2 = reinterpret_cast<int*>(reinterpret_cast<char*>(piVar2) + 1); }
    if (local_18 < *param_3) {
        piVar5 = local_14 + local_18 * 6;
        piVar2 = piVar4 + local_18 * 6 + 6;
        for (unsigned int uVar3 = (*param_3 - local_18) * 0x18 >> 2; uVar3 != 0; uVar3--) { *piVar2 = *piVar5; piVar5++; piVar2++; }
        for (iVar6 = 0; iVar6 != 0; iVar6--) { *reinterpret_cast<char*>(piVar2) = static_cast<char>(*reinterpret_cast<char*>(piVar5)); piVar5 = reinterpret_cast<int*>(reinterpret_cast<char*>(piVar5) + 1); piVar2 = reinterpret_cast<int*>(reinterpret_cast<char*>(piVar2) + 1); }
    }
    int local_10; int local_c; int local_8; int local_4;
    FUN_0056a280(&local_10, param_1, local_14, 1, *param_3);
    piVar4[local_18 * 6] = param_1;
    piVar4[local_18 * 6 + 2] = local_10; piVar4[local_18 * 6 + 3] = local_c;
    piVar4[local_18 * 6 + 4] = local_8; piVar4[local_18 * 6 + 5] = local_4;
    *param_3 = *param_3 + 1;
    if (local_14 != nullptr) operator_delete__(local_14 + -1);
    *param_2 = reinterpret_cast<uint32_t>(piVar4);
    FUN_0056a340(reinterpret_cast<int>(piVar4), *param_3);
    return 1;
}

extern unsigned char DAT_007283b2;
extern void* _DAT_007288d4;
extern void* _DAT_007287e4;
extern void* _DAT_0072876c;
extern void* _DAT_0072894c;
extern void* _DAT_0072867c;
extern void* _DAT_00728604;
extern void* _DAT_0072858c;
extern void* _DAT_00728514;
extern void* _DAT_0072885c;
extern void* _DAT_007286f4;
extern void* _DAT_00728424;
extern void* _DAT_0072849c;
extern uint32_t FUN_00555d80(void* out, int a, int b, int c);

// 0x56ca90 — observed shape
uint32_t FUN_0056ca90(void) {
    if (DAT_007283b2 == '\0') {
        _DAT_007288d4 = nullptr; _DAT_007287e4 = nullptr; _DAT_0072876c = nullptr;
        DAT_007283b2 = 1;
        _DAT_0072894c = reinterpret_cast<void*>(0x56c8a0);
        _DAT_0072867c = reinterpret_cast<void*>(0x56c920);
        _DAT_00728604 = reinterpret_cast<void*>(0x56ace0);
        _DAT_0072858c = reinterpret_cast<void*>(0x56c800);
        _DAT_00728514 = reinterpret_cast<void*>(0x56b110);
        _DAT_0072885c = reinterpret_cast<void*>(0x56c860);
        _DAT_007286f4 = reinterpret_cast<void*>(0x56c7f0);
        _DAT_00728424 = reinterpret_cast<void*>(0x56c7c0);
        _DAT_0072849c = reinterpret_cast<void*>(0x56c950);
        return 1;
    }
    return 0;
}

// 0x56cbc0 — observed shape
void FUN_0056cbc0(int param_1, unsigned int param_2) {
    unsigned char local_10[16];
    if (1 < param_2) {
        FUN_0056a340(param_1, param_2);
        uint32_t* puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00555d80(local_10, param_1 + 8, param_1 + 8, param_1 + 0x30)));
        *reinterpret_cast<uint32_t*>(param_1 + 0x18) = puVar1[0];
        *reinterpret_cast<uint32_t*>(param_1 + 0x1c) = puVar1[1];
        *reinterpret_cast<uint32_t*>(param_1 + 0x20) = puVar1[2];
        *reinterpret_cast<uint32_t*>(param_1 + 0x24) = puVar1[3];
        if (1 < param_2 - 1) {
            unsigned int local_14 = param_2 - 2;
            int iVar2 = param_1 + 0x30;
            do {
                puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00555d80(local_10, iVar2 + -0x28, iVar2, iVar2 + 0x28)));
                *reinterpret_cast<uint32_t*>(iVar2 + 0x10) = puVar1[0];
                *reinterpret_cast<uint32_t*>(iVar2 + 0x14) = puVar1[1];
                *reinterpret_cast<uint32_t*>(iVar2 + 0x18) = puVar1[2];
                local_14--;
                *reinterpret_cast<uint32_t*>(iVar2 + 0x1c) = puVar1[3];
                iVar2 += 0x28;
            } while (local_14 != 0);
        }
        int iVar2 = param_1 + static_cast<int>((param_2 - 1) * 0x28);
        puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00555d80(local_10, param_1 + -0x48 + static_cast<int>(param_2 * 0x28), iVar2 + 8, iVar2 + 8)));
        *reinterpret_cast<uint32_t*>(iVar2 + 0x18) = puVar1[0];
        *reinterpret_cast<uint32_t*>(iVar2 + 0x1c) = puVar1[1];
        *reinterpret_cast<uint32_t*>(iVar2 + 0x20) = puVar1[2];
        *reinterpret_cast<uint32_t*>(iVar2 + 0x24) = puVar1[3];
    }
}

// 0x56ccb0 — observed shape
void FUN_0056ccb0(uint32_t param_1, int param_2) {
    char cVar1 = static_cast<char>(FUN_0056e300(static_cast<int>(param_1), param_2));
    if (cVar1 == '\0') return;
    FUN_0059aac0(param_2 + 0x18);
}

// 0x56cce0 — observed shape
void FUN_0056cce0(uint32_t param_1, int param_2, int param_3) {
    if (param_3 != 0) {
        do { FUN_0056a030(static_cast<int>(param_1), param_2); param_2 += 0x28; param_3--; } while (param_3 != 0);
    }
}

// 0x56cd30 — observed shape
int* FUN_0056cd30(int param_1) {
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(static_cast<unsigned int>(param_1 * 0x28 + 4)));
    if (piVar1 == nullptr) return nullptr;
    *piVar1 = param_1;
    if (-1 < param_1 + -1) {
        int* piVar2 = piVar1 + 2;
        do { *reinterpret_cast<unsigned char*>(piVar2) = 8; *reinterpret_cast<unsigned char*>(piVar2) = 0x28; piVar2 = piVar2 + 10; param_1--; } while (param_1 != 0);
    }
    return piVar1 + 1;
}
