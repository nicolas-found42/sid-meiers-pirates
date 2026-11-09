#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern void __ArrayUnwind(void *a, uint32_t b, int c, void *(*d)(void *));
extern void FUN_005f0d74();
extern void* _controlfp(uint32_t a, uint32_t b);
extern DWORD GetSystemTimeAsFileTime(void *a);
extern DWORD GetCurrentProcessId();
extern DWORD GetCurrentThreadId();
extern DWORD GetTickCount();
extern int QueryPerformanceCounter(void *a);
extern void FUN_005f8d40(int a);

extern uint32_t DAT_007187f8;
extern uint32_t DAT_0071397c;
extern uint32_t DAT_00713984;
extern void (*_DAT_007188f0)();
extern void (*_DAT_007188f4)();
extern void (*_DAT_007188c4)();
extern void (*PTR_FUN_00718850)(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t);
extern void (*PTR_FUN_007188c8)(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t);
extern void (*PTR_FUN_007188cc)(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t);
// 0x5f0d12 — observed shape
void FUN_005f0d12(int *ebp_frame) {
    if (ebp_frame[-7] == 0) {
        void *arg1 = *(void **)(reinterpret_cast<char *>(ebp_frame) + 8);
        uint32_t arg2 = *(uint32_t *)(reinterpret_cast<char *>(ebp_frame) + 0xc);
        int arg3 = *(int *)(reinterpret_cast<char *>(ebp_frame) + 0x10);
        void *(*arg4)(void *) = *(void *(*)(void *) *)(reinterpret_cast<char *>(ebp_frame) + 0x14);
        __ArrayUnwind(arg1, arg2, arg3, arg4);
    }
}
// 0x5f0d2a — observed shape
void FUN_005f0d2a(void *param_1, uint32_t param_2, int param_3, void (*param_4)(void *), void (*param_5)(void *)) {
    void *unaff_EDI = param_1;
    (void)param_2; (void)param_5;
    for (int local_20 = 0; local_20 < param_3; local_20 = local_20 + 1) {
        (*param_4)(unaff_EDI);
    }
    FUN_005f0d74();
}
// 0x5f0d74 — observed shape
void FUN_005f0d74(int *ebp_frame) {
    if (ebp_frame[-8] == 0) {
        void *arg1 = *(void **)(reinterpret_cast<char *>(ebp_frame) + 8);
        uint32_t arg2 = *(uint32_t *)(reinterpret_cast<char *>(ebp_frame) + 0xc);
        int arg3 = *(int *)(reinterpret_cast<char *>(ebp_frame) + -0x1c);
        void *(*arg4)(void *) = *(void *(*)(void *) *)(reinterpret_cast<char *>(ebp_frame) + 0x18);
        __ArrayUnwind(arg1, arg2, arg3, arg4);
    }
}
// 0x5f0d90 — observed shape
void FUN_005f0d90(uint32_t in_EAX, void *retaddr) {
    char stack[1];
    if (in_EAX < 0x1000) {
        uint32_t *p = reinterpret_cast<uint32_t *>(reinterpret_cast<uintptr_t>(&stack) - in_EAX);
        *p = reinterpret_cast<uint32_t>(retaddr);
        return;
    }
    uint8_t *puVar1 = reinterpret_cast<uint8_t *>(&stack);
    uint32_t remaining = in_EAX;
    do {
        puVar1 = puVar1 - 0x1000;
        remaining = remaining - 0x1000;
    } while (0xfff < remaining);
    uint32_t *p2 = reinterpret_cast<uint32_t *>(reinterpret_cast<uintptr_t>(puVar1) - (4 + remaining + 0));
    // Ghidra: *(undefined4 *)(puVar1 + (-4 - in_EAX)) with remaining
    // simplified: address = puVar1 -4 - remaining; here kept equivalent via puVar1 base
    p2 = reinterpret_cast<uint32_t *>(puVar1 - 4 - remaining);
    *p2 = reinterpret_cast<uint32_t>(retaddr);
}
// 0x5f0ddc — observed shape
uint64_t FUN_005f0ddc(long double in_ST0) {
    uint64_t uVar1 = static_cast<uint64_t>(std::llround(in_ST0));
    uint32_t local_20 = static_cast<uint32_t>(uVar1);
    float fStack_1c = static_cast<float>(uVar1 >> 0x20);
    float fVar3 = static_cast<float>(in_ST0);
    if ((local_20 != 0) || (fVar3 = fStack_1c, (uVar1 & 0x7fffffff00000000ULL) != 0)) {
        if ((int32_t)fVar3 < 0) {
            uVar1 = uVar1 + (0x80000000u < static_cast<uint32_t>(-(float)(in_ST0 - (long double)(int64_t)uVar1)));
        } else {
            uint32_t uVar2 = static_cast<uint32_t>(0x80000000u < static_cast<uint32_t>((float)(in_ST0 - (long double)(int64_t)uVar1)));
            uVar1 = (static_cast<uint64_t>(static_cast<int32_t>(fStack_1c) - (local_20 < uVar2)) << 32) | (local_20 - uVar2);
        }
    }
    return uVar1;
}
// 0x5f0e88 — observed shape
void FUN_005f0e88() {
    uint32_t *local_20;
    for (local_20 = &DAT_0071397c; local_20 < &DAT_0071397c; local_20 = local_20 + 1) {
        if (reinterpret_cast<void (*)()>(*local_20) != nullptr) {
            reinterpret_cast<void (*)()>(*local_20)();
        }
    }
}
// 0x5f0ecc — observed shape
void FUN_005f0ecc() {
    uint32_t *local_20;
    for (local_20 = &DAT_00713984; local_20 < &DAT_00713984; local_20 = local_20 + 1) {
        if (reinterpret_cast<void (*)()>(*local_20) != nullptr) {
            reinterpret_cast<void (*)()>(*local_20)();
        }
    }
}
// 0x5f0f16 — observed shape
void FUN_005f0f16() {
    _controlfp(0x10000, 0x30000);
}
// 0x5f0f2b — observed shape
void FUN_005f0f2b() {
    if ((DAT_007187f8 == 0) || (DAT_007187f8 == 0xbb40e64e)) {
        _FILETIME local_c;
        GetSystemTimeAsFileTime(&local_c);
        DWORD DVar1 = GetCurrentProcessId();
        DWORD DVar2 = GetCurrentThreadId();
        DWORD DVar3 = GetTickCount();
        LARGE_INTEGER local_14;
        QueryPerformanceCounter(&local_14);
        DAT_007187f8 = local_c.dwHighDateTime ^ local_c.dwLowDateTime ^ DVar1 ^ DVar2 ^ DVar3 ^ local_14.s.HighPart ^ local_14.s.LowPart;
        if (DAT_007187f8 == 0) {
            DAT_007187f8 = 0xbb40e64e;
        }
    }
}
// 0x5f0fa4 — observed shape
uint32_t FUN_005f0fa4(float param_1, float param_2) {
    param_1 = param_1 - param_2;
    if ((std::isnan(param_1) || -1.1920929e-07f < param_1 == (param_1 == -1.1920929e-07f)) || (std::isnan(param_1) || param_1 < 1.1920929e-07f == (param_1 == 1.1920929e-07f))) {
        return 0;
    } else {
        return 1;
    }
}
// 0x5f0fd8 — observed shape
void FUN_005f0fd8() {
    FUN_005f8d40(1);
    _DAT_007188f0();
}
// 0x5f0ff1 — observed shape
void FUN_005f0ff1(int param_1, int param_2, uint32_t param_3) {
    uint32_t uVar4 = 0;
    if (param_3 != 0) {
        do {
            uint32_t uVar1 = *reinterpret_cast<uint32_t *>(param_2 + uVar4 * 4);
            uint32_t uVar2 = uVar1 & 0x7fffffff;
            uint16_t uVar3 = static_cast<uint16_t>((uVar1 >> 0x10) & 0x8000);
            if (uVar2 < 0x47fff000) {
                if (uVar2 < 0x38800000) {
                    int iVar5 = 0x71 - static_cast<int>(uVar2 >> 0x17);
                    if (iVar5 < 0x20) {
                        uVar2 = ((uVar1 & 0x7fffff | 0x800000) >> (static_cast<unsigned char>(iVar5) & 0x1f));
                    } else {
                        uVar2 = 0;
                    }
                    uVar2 = (uVar2 >> 0xd & 1) + 0xfff + uVar2;
                } else {
                    uVar2 = (uVar2 >> 0xd & 1) + 0xc8000fff + uVar2;
                }
                uVar3 = static_cast<uint16_t>((uVar2 >> 0xd) | uVar3);
            } else {
                uVar3 = static_cast<uint16_t>(uVar3 | 0x7fff);
            }
            *reinterpret_cast<uint16_t *>(param_1 + uVar4 * 2) = uVar3;
            uVar4 = uVar4 + 1;
        } while (uVar4 < param_3);
    }
}
// 0x5f1093 — observed shape
void FUN_005f1093() {
    FUN_005f8d40(1);
    _DAT_007188f4();
}
// 0x5f10ac — observed shape
int FUN_005f10ac(int param_1, int param_2, uint32_t param_3) {
    uint32_t uVar4 = 0;
    if (param_3 != 0) {
        do {
            uint16_t uVar1 = *reinterpret_cast<uint16_t *>(param_2 + uVar4 * 2);
            uint32_t uVar2 = static_cast<uint32_t>(uVar1);
            if ((uVar1 & 0x7c00) == 0) {
                if ((uVar1 & 0x3ff) == 0) {
                    uVar2 = (uVar2 & 0xffff8000) << 0x10;
                } else {
                    int iVar5 = -0xe;
                    uint32_t uVar3;
                    for (uVar3 = uVar2 & 0x3ff; (uVar3 & 0x400) == 0; uVar3 = uVar3 << 1) {
                        iVar5 = iVar5 + -1;
                    }
                    uVar2 = (((uVar2 & 0xffff8080) << 3 | uVar3) & 0xfffffbff) << 0xd | static_cast<uint32_t>(iVar5 + 0x7f) * 0x800000;
                }
            } else {
                uVar2 = ((uVar2 & 0xffff8000) << 3 | uVar2 & 0x3ff) << 0xd | ((static_cast<uint32_t>(uVar1 >> 10 & 0x1f) + 0x70) * 0x800000);
            }
            *reinterpret_cast<uint32_t *>(param_1 + uVar4 * 4) = uVar2;
            uVar4 = uVar4 + 1;
        } while (uVar4 < param_3);
    }
    return param_1;
}
// 0x5f1153 — observed shape
void FUN_005f1153() {
    FUN_005f8d40(1);
    _DAT_007188c4();
}
// 0x5f1166 — observed shape
void FUN_005f1166(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) {
    FUN_005f8d40(1);
    PTR_FUN_00718850(param_1, param_2, param_3, param_4, param_5, param_6);
}
// 0x5f1192 — observed shape
void FUN_005f1192(float *param_1, float *param_2, float *param_3, float *param_4, float *param_5, float param_6) {
    float fVar1 = param_6 * param_6;
    float fVar2 = param_6 * fVar1;
    float fVar4 = ((fVar2 + fVar2) - fVar1 * 3.0f) + 1.0f;
    param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
    float fVar3 = fVar1 * 3.0f - (fVar2 + fVar2);
    *param_1 = (fVar2 - fVar1) * *param_5 + fVar3 * *param_4 + param_6 * *param_3 + fVar4 * *param_2;
    param_1[1] = fVar4 * param_2[1] + param_6 * param_3[1] + fVar3 * param_4[1] + (fVar2 - fVar1) * param_5[1];
}
// 0x5f1222 — observed shape
void FUN_005f1222(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) {
    FUN_005f8d40(1);
    PTR_FUN_007188c8(param_1, param_2, param_3, param_4, param_5, param_6);
}
// 0x5f12ff — observed shape
void FUN_005f12ff(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) {
    FUN_005f8d40(1);
    PTR_FUN_007188cc(param_1, param_2, param_3, param_4, param_5, param_6);
}
// 0x5f1330 — observed shape
void FUN_005f1330(float *param_1, float *param_2, float *param_3, float *param_4, float param_5, float param_6) {
    *param_1 = (*param_4 - *param_2) * param_6 + (*param_3 - *param_2) * param_5 + *param_2;
    param_1[1] = (param_4[1] - param_2[1]) * param_6 + (param_3[1] - param_2[1]) * param_5 + param_2[1];
}
