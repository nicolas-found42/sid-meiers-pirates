#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <windows.h>

extern void* PTR_LAB_006c5198;
extern void FUN_00593960();
extern void* thunk_FUN_00533c78(int size);
extern void FUN_006b34a0(uint32_t v);
extern void FUN_005606f0(uint32_t a, void** b);
extern void* FUN_0058edf0(int* param_1);
extern void FUN_0058f6e0(uint32_t a, uint32_t b);
extern void FUN_004c2d90(int v);
extern int FUN_00591630(uint16_t a, uint32_t b);
extern void FUN_0058f000(int v);
extern uint8_t FUN_0059ef20(uint32_t a, int b, int c);

// 0x594df0 — observed shape
void FUN_00594df0(void* self, int param_1)
{
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    int* src = reinterpret_cast<int*>(param_1);
    *in_ECX = reinterpret_cast<uint32_t>(PTR_LAB_006c5198);
    in_ECX[1] = static_cast<uint32_t>(src[1]);
    in_ECX[2] = static_cast<uint32_t>(src[2]);
    in_ECX[3] = static_cast<uint32_t>(src[3]);
    in_ECX[4] = static_cast<uint32_t>(src[4]);
    in_ECX[5] = static_cast<uint32_t>(src[5]);
    in_ECX[6] = static_cast<uint32_t>(src[6]);
    in_ECX[7] = static_cast<uint32_t>(src[7]);
    in_ECX[0xe] = static_cast<uint32_t>(src[0xe]);
    FUN_00593960();
}

// 0x594ee0 — observed shape
void FUN_00594ee0(char* param_1, int param_2)
{
    char* pcVar3 = param_1;
    char* pcVar4 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    char* buf = reinterpret_cast<char*>(thunk_FUN_00533c78(static_cast<int>(pcVar4 + (0xe - static_cast<int>(reinterpret_cast<intptr_t>(param_1) + 1))) - reinterpret_cast<intptr_t>(buf)));
    // NOTE: pseudocode uses pcVar4+(0xe-(param_1+1)) as size; keep shape:
    // buf size = (pcVar4 + (0xe - (param_1+1))) - param_1 variant — using direct calc:
    buf = nullptr;
    // Recompute properly to match listing:
    // (preserved below via clean calc)
    // The listing: param_1 = (char*)thunk_FUN_00533c78(pcVar4 + (0xe - (int)(param_1 + 1)))
    buf = reinterpret_cast<char*>(thunk_FUN_00533c78(reinterpret_cast<intptr_t>(pcVar4) + (0xe - (reinterpret_cast<intptr_t>(param_1) + 1))));
    sprintf(buf, "%s = CAPSULE_BV", pcVar3);
    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(param_2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(param_2 + 8) <= uVar2) {
        FUN_006b34a0(*reinterpret_cast<uint32_t*>(param_2 + 0x14) + uVar2);
    }
    FUN_005606f0(uVar2, reinterpret_cast<void**>(&buf));
}

// 0x594fa0 — observed shape
void FUN_00594fa0(void* self, uint32_t* param_1)
{
    int* in_ECX = reinterpret_cast<int*>(self);
    in_ECX[0] = 0;
    in_ECX[1] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0]);
    if (puVar2 != param_1) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Fn = void(__cdecl*)(int);
                Fn fn = reinterpret_cast<Fn>(*puVar2);
                fn(1);
            }
        }
        in_ECX[0] = reinterpret_cast<int>(param_1);
        if (param_1 != nullptr) {
            param_1[1] = param_1[1] + 1;
        }
    }
    puVar2 = reinterpret_cast<uint32_t*>(in_ECX[1]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
        in_ECX[1] = 0;
    }
}

// 0x595000 — observed shape
void FUN_00595000(int* param_1, uint32_t param_2)
{
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(param_1[0x2c]);
    if (puVar4 != nullptr) {
        int iVar3 = static_cast<int>(puVar4[1]);
        puVar4[1] = static_cast<uint32_t>(iVar3 + 1);
        puVar4[1] = static_cast<uint32_t>(iVar3);
        if (iVar3 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar4);
            fn(1);
        }
    }
    extern uint8_t DAT_00727560[];
    extern uint8_t DAT_00727c3c[];
    using ListFn = uint32_t* (__cdecl*)();
    ListFn listNext = reinterpret_cast<ListFn>(*param_1 + 4);
    uint32_t* puVar2 = listNext();
    while (true) {
        if (puVar2 == nullptr) {
check2:
            puVar4 = listNext();
            if (puVar4 != nullptr) {
                while (puVar4 != reinterpret_cast<uint32_t*>(DAT_00727560)) {
                    puVar4 = reinterpret_cast<uint32_t*>(puVar4[1]);
                    if (puVar4 == nullptr) {
                        return;
                    }
                }
                uint32_t uVar1 = static_cast<uint32_t>(param_1[0x30]);
                uint32_t uVar5 = 0;
                if (uVar1 != 0) {
                    do {
                        if ((uVar5 < static_cast<uint32_t>(param_1[0x30])) &&
                            (static_cast<int>(*reinterpret_cast<int*>(param_1[0x2e] + uVar5 * 4)) != 0)) {
                            int iVar3 = *reinterpret_cast<int*>(param_1[0x2e] + uVar5 * 4);
                            FUN_00595000(reinterpret_cast<int*>(iVar3), param_2);
                        }
                        uVar5 = uVar5 + 1;
                    } while (uVar5 < uVar1);
                }
            }
            return;
        }
        if (puVar2 == reinterpret_cast<uint32_t*>(DAT_00727c3c)) {
            if (puVar4 == nullptr) {
                int iVar3 = reinterpret_cast<int>(thunk_FUN_00533c78(0x54));
                if (iVar3 == 0) {
                    iVar3 = 0;
                } else {
                    iVar3 = reinterpret_cast<int>(FUN_0058edf0(param_1));
                }
                *reinterpret_cast<uint32_t*>(iVar3 + 0x28) = 3;
                *reinterpret_cast<uint32_t*>(iVar3 + 0x2c) = param_2;
                FUN_0058f6e0(*reinterpret_cast<uint32_t*>(iVar3 + 0xc), param_2);
                FUN_004c2d90(iVar3);
            }
            goto check2;
        }
        puVar2 = reinterpret_cast<uint32_t*>(puVar2[1]);
    }
}

// 0x5950e0 — observed shape
uint8_t FUN_005950e0(uint32_t param_1, int param_2, int param_3, uint32_t param_4)
{
    switch (param_4) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 8: case 9:
        break;
    case 10:
        return 0;
    default:
        return 1;
    }
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(param_2 + 0xb0);
    int iVar4 = 0;
    if (puVar1 != nullptr) {
        int iVar3 = static_cast<int>(puVar1[1]);
        puVar1[1] = static_cast<uint32_t>(iVar3 + 1);
        puVar1[1] = static_cast<uint32_t>(iVar3);
        if (iVar3 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar1);
            fn(1);
        }
    }
    int iVar3 = static_cast<int>(puVar1[0xb]);
    if ((iVar3 == 1) || (iVar3 == 0)) {
        if (puVar1[0xc] == 0) {
            int bc = *reinterpret_cast<int*>(param_2 + 0xbc);
            iVar3 = FUN_00591630(*reinterpret_cast<uint16_t*>(bc + 0xc), *reinterpret_cast<uint32_t*>(bc + 0x20));
            if (iVar3 == 0) goto LAB_00595174;
            FUN_0058f000(iVar3);
        }
        iVar4 = 1;
    } else if ((iVar3 == 2) && (puVar1[0xc] != 0)) {
        iVar4 = 1;
    }
LAB_00595174:
    puVar1 = *reinterpret_cast<uint32_t**>(param_3 + 0xb0);
    if (puVar1 != nullptr) {
        iVar3 = static_cast<int>(puVar1[1]);
        puVar1[1] = static_cast<uint32_t>(iVar3 + 1);
        puVar1[1] = static_cast<uint32_t>(iVar3);
        if (iVar3 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar1);
            fn(1);
        }
    }
    iVar3 = static_cast<int>(puVar1[0xb]);
    if ((iVar3 == 1) || (iVar3 == 0)) {
        if (puVar1[0xc] == 0) {
            int bc = *reinterpret_cast<int*>(param_3 + 0xbc);
            iVar3 = FUN_00591630(*reinterpret_cast<uint16_t*>(bc + 0xc), *reinterpret_cast<uint32_t*>(bc + 0x20));
            if (iVar3 == 0) goto LAB_005951de;
            FUN_0058f000(iVar3);
        }
        iVar4 = iVar4 + 1;
    } else if ((iVar3 == 2) && (puVar1[0xc] != 0)) {
        iVar4 = iVar4 + 1;
    }
LAB_005951de:
    if (iVar4 == 2) {
        return FUN_0059ef20(param_1, param_2, param_3);
    }
    return 1;
}

extern int FUN_00596070(uint32_t a, uint32_t b, void* c, uint32_t d);
extern int FUN_0058ec00(uint32_t a, uint32_t b);
extern void FUN_0058f270();
extern void FUN_0058f310();
extern void FUN_0058f760(uint32_t v);
extern uint8_t FUN_0058ef70(uint32_t a, void* b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
extern uint8_t FUN_0059f180(uint32_t a, int b, int c, uint32_t d);
extern void FUN_0059f030(uint32_t a, int b, int c, uint32_t d);

// 0x595220 — observed shape
uint32_t FUN_00595220(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4)
{
    extern uint8_t DAT_00727560[];
    extern uint8_t DAT_00727d58[];
    using ListFn = uint32_t* (__cdecl*)();
    int* piVar1 = *reinterpret_cast<int**>(param_2 + 0xc);
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(piVar1[0x2c]);
    int iVar4 = 0;
    if (puVar3 == nullptr) {
        ListFn listNext = reinterpret_cast<ListFn>(*piVar1 + 4);
        for (puVar3 = listNext(); puVar3 != nullptr; puVar3 = reinterpret_cast<uint32_t*>(puVar3[1])) {
            if (puVar3 == reinterpret_cast<uint32_t*>(DAT_00727560)) {
                param_2 = static_cast<uint32_t>(piVar1[0x30]);
                puVar3 = listNext();
                goto joined_r0x005952b3;
            }
        }
    } else {
        iVar4 = static_cast<int>(puVar3[1]);
        puVar3[1] = static_cast<uint32_t>(iVar4 + 1);
        puVar3[1] = static_cast<uint32_t>(iVar4);
        if (iVar4 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar3);
            fn(1);
        }
    }
    piVar1 = *reinterpret_cast<int**>(param_3 + 0xc);
    puVar3 = reinterpret_cast<uint32_t*>(piVar1[0x2c]);
    if (puVar3 == nullptr) {
        ListFn listNext = reinterpret_cast<ListFn>(*piVar1 + 4);
        puVar3 = listNext();
        if (puVar3 != nullptr) {
            while (puVar3 != reinterpret_cast<uint32_t*>(DAT_00727560)) {
                puVar3 = reinterpret_cast<uint32_t*>(puVar3[1]);
                if (puVar3 == nullptr) {
                    return 0;
                }
            }
            uint32_t uVar5 = static_cast<uint32_t>(piVar1[0x30]);
            uint32_t uVar6 = 0;
            if (uVar5 != 0) {
                do {
                    if ((uVar6 < static_cast<uint32_t>(piVar1[0x30])) &&
                        (*reinterpret_cast<int*>(piVar1[0x2e] + uVar6 * 4) != 0)) {
                        uint8_t auStack_18[4] = {0};
                        uint32_t uStack_14 = 2;
                        uint32_t uStack_10 = *reinterpret_cast<uint32_t*>(param_3 + 8);
                        uint32_t uStack_8 = *reinterpret_cast<uint32_t*>(param_3 + 0x10);
                        uint32_t uStack_4 = *reinterpret_cast<uint32_t*>(param_3 + 0x14);
                        int iVar4r = FUN_00596070(param_1, static_cast<uint32_t>(param_2), auStack_18, param_4);
                        if (iVar4r == 1) {
                            return 1;
                        }
                    }
                    uVar6 = uVar6 + 1;
                } while (uVar6 < uVar5);
            }
        }
    } else {
        iVar4 = static_cast<int>(puVar3[1]);
        puVar3[1] = static_cast<uint32_t>(iVar4 + 1);
        puVar3[1] = static_cast<uint32_t>(iVar4);
        if (iVar4 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar3);
            fn(1);
            return 0;
        }
    }
    return 0;
joined_r0x005952b3:
    if (puVar3 == nullptr) {
LAB_005952d0:
        uint32_t uVar5 = 0;
        if (param_2 == 0) {
            return 0;
        }
        do {
            if ((uVar5 < static_cast<uint32_t>(piVar1[0x30])) &&
                (*reinterpret_cast<int*>(piVar1[0x2e] + uVar5 * 4) != 0)) {
                uint8_t auStack_18[4] = {0};
                uint32_t uStack_14 = 2;
                uint32_t uStack_10 = *reinterpret_cast<uint32_t*>(iVar4 + 8);
                uint32_t uStack_8 = *reinterpret_cast<uint32_t*>(iVar4 + 0x10);
                uint32_t uStack_4 = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
                int iVar2 = FUN_00596070(param_1, reinterpret_cast<uint32_t>(auStack_18), static_cast<uint32_t>(param_3), param_4);
                if (iVar2 == 1) {
                    return 1;
                }
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < param_2);
        return 0;
    }
    if (puVar3 == reinterpret_cast<uint32_t*>(DAT_00727d58)) {
        param_2 = static_cast<uint32_t>(piVar1[0x3c] + 1);
        goto LAB_005952d0;
    }
    puVar3 = reinterpret_cast<uint32_t*>(puVar3[1]);
    goto joined_r0x005952b3;
}

// 0x595410 — observed shape
uint32_t FUN_00595410(uint32_t param_1, int param_2, int param_3, uint8_t* param_4)
{
    uint8_t cVar3 = FUN_0059ef20(param_1, param_2, param_3);
    if (cVar3 != '\0') {
        *param_4 = 1;
        uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(param_2 + 0xb0);
        if (puVar1 != nullptr) {
            int iVar4 = static_cast<int>(puVar1[1]);
            puVar1[1] = static_cast<uint32_t>(iVar4 + 1);
            puVar1[1] = static_cast<uint32_t>(iVar4);
            if (iVar4 == 0) {
                using Fn = void(__cdecl*)(int);
                Fn fn = reinterpret_cast<Fn>(*puVar1);
                fn(1);
            }
        }
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(param_3 + 0xb0);
        if (puVar2 != nullptr) {
            int iVar4 = static_cast<int>(puVar2[1]);
            puVar2[1] = static_cast<uint32_t>(iVar4 + 1);
            puVar2[1] = static_cast<uint32_t>(iVar4);
            if (iVar4 == 0) {
                using Fn = void(__cdecl*)(int);
                Fn fn = reinterpret_cast<Fn>(*puVar2);
                fn(1);
            }
        }
        int iVar4 = FUN_0058ec00(puVar1[10], puVar2[10]);
        if (iVar4 == 1) {
            return 1;
        }
    }
    return 0;
}

// 0x5954a0 — observed shape
void FUN_005954a0(uint32_t param_1, int param_2, int param_3, int param_4, int param_5)
{
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(param_2 + 0xb0);
    if (puVar1 != nullptr) {
        int iVar2 = static_cast<int>(puVar1[1]);
        puVar1[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar1[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar1);
            fn(1);
        }
    }
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(param_3 + 0xb0);
    if (puVar3 != nullptr) {
        int iVar2 = static_cast<int>(puVar3[1]);
        puVar3[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar3[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar3);
            fn(1);
        }
    }
    if (puVar1[0x11] == 0) {
        FUN_0058f270();
    }
    if (puVar3[0x11] == 0) {
        FUN_0058f270();
    }
    FUN_0058f310();
    FUN_0058f310();
    FUN_0058f760(*reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_4) + 0x14));
    FUN_0058f760(*reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_5) + 0x14));
    FUN_0058ef70(param_1, puVar3, *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_4) + 0xc), *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_5) + 0xc), *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_4) + 0x10), *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_5) + 0x10));
}

// 0x595560 — observed shape
uint8_t FUN_00595560(uint32_t param_1, int param_2, int param_3, int param_4, int param_5, uint32_t param_6)
{
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(param_2 + 0xb0);
    if (puVar1 != nullptr) {
        int iVar2 = static_cast<int>(puVar1[1]);
        puVar1[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar1[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar1);
            fn(1);
        }
    }
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(param_3 + 0xb0);
    if (puVar3 != nullptr) {
        int iVar2 = static_cast<int>(puVar3[1]);
        puVar3[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar3[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar3);
            fn(1);
        }
    }
    if ((puVar1[0x11] == 0) || (puVar3[0x11] == 0)) {
        return FUN_0059f180(param_1, param_2, param_3, param_6);
    }
    FUN_0058f310();
    FUN_0058f310();
    FUN_0058f760(*reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_4) + 0x14));
    FUN_0058f760(*reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_5) + 0x14));
    return FUN_0058ef70(param_1, puVar3, *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_4) + 0xc), *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_5) + 0xc), *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_4) + 0x10), *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_5) + 0x10));
}

// 0x595630 — observed shape
void FUN_00595630(uint32_t param_1, int param_2, int param_3, uint32_t param_4)
{
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(param_2 + 0xb0);
    if (puVar1 != nullptr) {
        int iVar2 = static_cast<int>(puVar1[1]);
        puVar1[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar1[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar1);
            fn(1);
        }
    }
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(param_3 + 0xb0);
    if (puVar3 != nullptr) {
        int iVar2 = static_cast<int>(puVar3[1]);
        puVar3[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar3[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar3);
            fn(1);
        }
    }
    if (puVar1[0x11] == 0) {
        FUN_0058f270();
    }
    if (puVar3[0x11] == 0) {
        FUN_0058f270();
    }
    FUN_0058f310();
    FUN_0058f310();
    FUN_0059f030(param_1, param_2, param_3, param_4);
}


extern uint32_t FUN_0058f440(uint32_t a, uint32_t b);
extern uint32_t FUN_00594f80(uint32_t a, int b, int c, uint8_t* d);
extern int FUN_00533c78(uint32_t size);
extern void FUN_00571ce0(void* p);
extern void* FUN_0053cac0(void* out, void* in, int m);
extern void* FUN_0053ca60(void* out, void* in);
extern uint8_t FUN_0059ebe0(float* a, float* b, int c, int d, int e, uint32_t f, float* g, uint32_t* h, float* i, float* j);
extern void FUN_00491640();
extern void FUN_00510d70(void* out, float v);
extern void FUN_00510df0(void* out, void* in);
extern uint32_t FUN_00596270(uint32_t a, char* b, int c, uint8_t* d);
extern uint8_t FUN_00594f50(uint32_t a, uint8_t b);
extern uint32_t FUN_0059eb00(int* a, uint32_t b, uint32_t c);
extern uint32_t FUN_004879c0(void* a, void* b);
extern uint32_t FUN_00596520(uint32_t a, uint32_t b, int* c, int d);
extern uint32_t FUN_00596590(uint32_t a, uint32_t b, int* c, int* d);
extern uint32_t DAT_00727c4c;
extern uint32_t DAT_00727c50;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t DAT_0071779c;
extern uint32_t DAT_007177a0;
extern uint32_t DAT_007177a4;
extern uint32_t DAT_007177a8;
extern uint8_t DAT_00727c3c[];

// 0x5956d0 — observed shape
uint32_t FUN_005956d0(uint32_t param_1, int param_2, int param_3, uint8_t* param_4)
{
    uint32_t uVar5 = *reinterpret_cast<uint32_t*>(param_2 + 0xc);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(param_3 + 0xc);
    uint32_t uVar3 = FUN_0058f440(uVar5, uVar1);
    int iVar4 = FUN_005950e0(param_1, static_cast<int>(uVar5), static_cast<int>(uVar1), uVar3);
    if (iVar4 != 0) {
        switch (uVar3) {
        case 0:
        case 1: {
            using CharFn = uint8_t(__cdecl*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
            uint8_t cVar2 = reinterpret_cast<CharFn>(FUN_005954a0)(
                param_1, uVar5, uVar1,
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_2)),
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_3)));
            if (cVar2 != 0) {
                *param_4 = 1;
            }
            return 1;
        }
        case 2:
            return FUN_00595560(param_1, static_cast<int>(uVar5), static_cast<int>(uVar1),
                                param_2, param_3,
                                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_4)));
        case 3:
        case 6:
        case 8:
        case 9:
            return FUN_00595410(param_1, static_cast<int>(uVar5), static_cast<int>(uVar1), param_4);
        case 4:
            return FUN_00595630(param_1, static_cast<int>(uVar5), static_cast<int>(uVar1),
                                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_4)));
        case 5:
            return FUN_00594f80(param_1, static_cast<int>(uVar5), static_cast<int>(uVar1), param_4);
        case 7:
            return FUN_00595410(param_1, static_cast<int>(uVar5), static_cast<int>(uVar1), param_4);
        default:
            break;
        }
    }
    return 0;
}

// 0x595810 — observed shape
uint8_t FUN_00595810(float* param_1, uint32_t param_2, int* param_3, int param_4)
{
    float local_8c;
    float local_88;
    float local_84;
    float local_198;
    uint8_t local_bc[8];
    float local_c8[3];
    float local_80[3];
    uint8_t local_18d;
    int local_17c;
    uint16_t auStack_194[3];
    uint32_t uStack_184;
    uint32_t uStack_180;
    uint32_t uStack_110;
    uint32_t uStack_100;
    float fStack_188;
    float fStack_12c[3];
    float fStack_178[3];
    float fStack_18c;
    uint8_t auStack_58[16];
    uint8_t auStack_48[16];
    uint8_t auStack_38[16];
    uint8_t auStack_28[12];
    uint8_t auStack_1c[12];
    uint8_t auStack_10[16];
    float uStack_74[4];

    if (param_3[2] == 0) {
        int iVar5 = FUN_00533c78(0x44);
        if (iVar5 == 0) {
            local_17c = 0;
        }
        else {
            using AllocFn = void*(__cdecl*)(int);
            local_17c = static_cast<int>(reinterpret_cast<intptr_t>(
                reinterpret_cast<AllocFn>(FUN_00594fa0)(param_4)));
        }
        param_3[0xc] = local_17c;
        void* released = reinterpret_cast<void*>(static_cast<intptr_t>(local_17c));
        FUN_00571ce0(&released);
        return 1;
    }
    local_8c = *param_1 - *reinterpret_cast<float*>(param_4 + 0x90);
    local_88 = param_1[1] - *reinterpret_cast<float*>(param_4 + 0x94);
    local_84 = param_1[2] - *reinterpret_cast<float*>(param_4 + 0x98);
    local_198 = 1.0f / *reinterpret_cast<float*>(param_4 + 0x9c);
    float* pfVar6 = reinterpret_cast<float*>(FUN_0053cac0(local_bc, &local_8c, param_4 + 0x6c));
    local_80[2] = local_198 * pfVar6[2];
    local_80[1] = local_198 * pfVar6[1];
    local_80[0] = local_198 * pfVar6[0];
    pfVar6 = reinterpret_cast<float*>(FUN_0053cac0(local_bc,
        reinterpret_cast<void*>(static_cast<uintptr_t>(param_2)), param_4 + 0x6c));
    local_c8[2] = local_198 * pfVar6[2];
    local_18d = 0;
    local_c8[1] = local_198 * pfVar6[1];
    local_c8[0] = local_198 * pfVar6[0];
    int obj = *reinterpret_cast<int*>(param_4 + 0xbc);
    uint32_t vtable = *reinterpret_cast<uint32_t*>(obj);
    {
        using CountFn = int(__cdecl*)();
        CountFn countFn = reinterpret_cast<CountFn>(*reinterpret_cast<uint32_t*>(vtable + 0x44));
        uStack_110 = static_cast<uint32_t>(countFn());
    }
    local_17c = 0;
    if (static_cast<uint16_t>(uStack_110) != 0) {
        using ItemFn = void(__cdecl*)(int, uint16_t*, uint32_t*, uint32_t*);
        ItemFn itemFn = reinterpret_cast<ItemFn>(*reinterpret_cast<uint32_t*>(vtable + 0x48));
        do {
            itemFn(local_17c, auStack_194, &uStack_184, &uStack_180);
            int iVar5 = *reinterpret_cast<int*>(obj + 0x20);
            uint32_t uStack_120 = static_cast<uint8_t>(param_3[4]);
            uint8_t cVar4 = FUN_0059ebe0(
                local_80, local_c8,
                iVar5 + static_cast<uint32_t>(auStack_194[0]) * 0xc,
                iVar5 + (uStack_184 & 0xffff) * 0xc,
                iVar5 + (uStack_180 & 0xffff) * 0xc,
                uStack_120, fStack_12c, &uStack_100, &local_198, &fStack_188);
            if (cVar4 != 0) {
                local_18d = 1;
                int iVar7 = FUN_00533c78(0x44);
                void* obj2 = nullptr;
                if (iVar7 != 0) {
                    using AllocFn = void*(__cdecl*)(int);
                    obj2 = reinterpret_cast<AllocFn>(FUN_00594fa0)(param_4);
                }
                uintptr_t fVar8 = reinterpret_cast<uintptr_t>(obj2);
                if (param_3[3] == 1) {
                    pfVar6 = reinterpret_cast<float*>(FUN_0053ca60(auStack_28, fStack_12c));
                    float fVar3 = *reinterpret_cast<float*>(param_4 + 0x9c);
                    float fStack_94 = fVar3 * pfVar6[1];
                    float fStack_90 = fVar3 * pfVar6[2];
                    fStack_12c[0] = fVar3 * pfVar6[0] + *reinterpret_cast<float*>(param_4 + 0x90);
                    fStack_12c[1] = fStack_94 + *reinterpret_cast<float*>(param_4 + 0x94);
                    fStack_12c[2] = fStack_90 + *reinterpret_cast<float*>(param_4 + 0x98);
                }
                *reinterpret_cast<float*>(fVar8 + 8) = fStack_12c[0];
                *reinterpret_cast<float*>(fVar8 + 0xc) = fStack_12c[1];
                *reinterpret_cast<float*>(fVar8 + 0x10) = fStack_12c[2];
                *reinterpret_cast<uint32_t*>(fVar8 + 0x14) = uStack_100;
                *reinterpret_cast<uint16_t*>(fVar8 + 0x18) = static_cast<uint16_t>(local_17c);
                *reinterpret_cast<uint16_t*>(fVar8 + 0x1a) = auStack_194[0];
                *reinterpret_cast<int16_t*>(fVar8 + 0x1c) = static_cast<int16_t>(uStack_184);
                *reinterpret_cast<int16_t*>(fVar8 + 0x1e) = static_cast<int16_t>(uStack_180);
                fStack_18c = 1.0f - (local_198 + fStack_188);
                if (static_cast<uint8_t>(param_3[0xd]) == 0) {
                    *reinterpret_cast<uint32_t*>(fVar8 + 0x20) = DAT_00727c4c;
                    *reinterpret_cast<uint32_t*>(fVar8 + 0x24) = DAT_00727c50;
                }
                else {
                    int iVar7b = *reinterpret_cast<int*>(obj + 0x2c);
                    if (iVar7b == 0) {
                        *reinterpret_cast<uint32_t*>(fVar8 + 0x20) = DAT_00727c4c;
                        *reinterpret_cast<uint32_t*>(fVar8 + 0x24) = DAT_00727c50;
                    }
                    else {
                        float fStack_16c = *reinterpret_cast<float*>(iVar7b + (uStack_180 & 0xffff) * 8) * fStack_188;
                        float fStack_168 = *reinterpret_cast<float*>(iVar7b + 4 + (uStack_180 & 0xffff) * 8) * fStack_188;
                        float fStack_14c = *reinterpret_cast<float*>(iVar7b + (uStack_184 & 0xffff) * 8) * local_198;
                        float fStack_148 = *reinterpret_cast<float*>(iVar7b + 4 + (uStack_184 & 0xffff) * 8) * local_198;
                        float fStack_154 = *reinterpret_cast<float*>(iVar7b + static_cast<uint32_t>(auStack_194[0]) * 8) * fStack_18c;
                        float fStack_150 = *reinterpret_cast<float*>(iVar7b + 4 + static_cast<uint32_t>(auStack_194[0]) * 8) * fStack_18c;
                        float fStack_164 = fStack_14c + fStack_154;
                        float fStack_160 = fStack_148 + fStack_150;
                        float fStack_15c = fStack_16c + fStack_164;
                        *reinterpret_cast<float*>(fVar8 + 0x20) = fStack_15c;
                        float fStack_158 = fStack_168 + fStack_160;
                        *reinterpret_cast<float*>(fVar8 + 0x24) = fStack_158;
                    }
                }
                if (*reinterpret_cast<int8_t*>(reinterpret_cast<char*>(param_3) + 0x35) == 0) {
                    *reinterpret_cast<uint32_t*>(fVar8 + 0x28) = DAT_00727430;
                    *reinterpret_cast<uint32_t*>(fVar8 + 0x2c) = DAT_00727434;
                    *reinterpret_cast<uint32_t*>(fVar8 + 0x30) = DAT_00727438;
                }
                else {
                    int iVar7c = *reinterpret_cast<int*>(obj + 0x24);
                    if ((*reinterpret_cast<int8_t*>(reinterpret_cast<char*>(param_3) + 0x36) == 0) ||
                        (iVar7c == 0)) {
                        float* pfVar6b = reinterpret_cast<float*>(iVar5 + static_cast<uint32_t>(auStack_194[0]) * 0xc);
                        float* pfVar1 = reinterpret_cast<float*>(iVar5 + (uStack_184 & 0xffff) * 0xc);
                        float fStack_138 = pfVar1[0] - pfVar6b[0];
                        float fStack_134 = pfVar1[1] - pfVar6b[1];
                        float fStack_130 = pfVar1[2] - pfVar6b[2];
                        pfVar1 = reinterpret_cast<float*>(iVar5 + (uStack_180 & 0xffff) * 0xc);
                        float fStack_144 = pfVar1[0] - pfVar6b[0];
                        float fStack_140 = pfVar1[1] - pfVar6b[1];
                        float fStack_13c = pfVar1[2] - pfVar6b[2];
                        fStack_178[0] = fStack_13c * fStack_134 - fStack_130 * fStack_140;
                        fStack_178[1] = fStack_130 * fStack_144 - fStack_13c * fStack_138;
                        fStack_178[2] = fStack_140 * fStack_138 - fStack_134 * fStack_144;
                    }
                    else {
                        float* pfVar6b = reinterpret_cast<float*>(iVar7c + (uStack_180 & 0xffff) * 0xc);
                        float fStack_b4 = fStack_188 * pfVar6b[2];
                        float* pfVar1 = reinterpret_cast<float*>(iVar7c + (uStack_184 & 0xffff) * 0xc);
                        float fStack_5c = local_198 * pfVar1[2];
                        float* pfVar2 = reinterpret_cast<float*>(iVar7c + static_cast<uint32_t>(auStack_194[0]) * 0xc);
                        float fStack_ac = fStack_18c * pfVar2[1];
                        float fStack_a8 = fStack_18c * pfVar2[2];
                        float fStack_a4 = fStack_18c * pfVar2[0] + local_198 * pfVar1[0];
                        float fStack_9c = fStack_a8 + fStack_5c;
                        fStack_178[0] = fStack_a4 + fStack_188 * pfVar6b[0];
                        fStack_178[1] = fStack_ac + local_198 * pfVar1[1] + fStack_188 * pfVar6b[1];
                        fStack_178[2] = fStack_9c + fStack_b4;
                    }
                    FUN_00491640();
                    if (param_3[3] == 1) {
                        pfVar6 = reinterpret_cast<float*>(FUN_0053ca60(auStack_1c, fStack_178));
                        fStack_178[0] = pfVar6[0];
                        fStack_178[1] = pfVar6[1];
                        fStack_178[2] = pfVar6[2];
                    }
                    *reinterpret_cast<float*>(fVar8 + 0x28) = fStack_178[0];
                    *reinterpret_cast<float*>(fVar8 + 0x2c) = fStack_178[1];
                    *reinterpret_cast<float*>(fVar8 + 0x30) = fStack_178[2];
                }
                uint32_t uVar9;
                if ((*reinterpret_cast<int8_t*>(reinterpret_cast<char*>(param_3) + 0x37) == 0) ||
                    (*reinterpret_cast<int*>(obj + 0x28) == 0)) {
                    *reinterpret_cast<uint32_t*>(fVar8 + 0x34) = DAT_0071779c;
                    *reinterpret_cast<uint32_t*>(fVar8 + 0x38) = DAT_007177a0;
                    *reinterpret_cast<uint32_t*>(fVar8 + 0x3c) = DAT_007177a4;
                    uVar9 = DAT_007177a8;
                }
                else {
                    FUN_00510d70(auStack_58, fStack_188);
                    FUN_00510d70(auStack_38, local_198);
                    FUN_00510d70(auStack_48, fStack_18c);
                    FUN_00510df0(auStack_10, auStack_38);
                    FUN_00510df0(uStack_74, auStack_58);
                    *reinterpret_cast<float*>(fVar8 + 0x34) = uStack_74[0];
                    *reinterpret_cast<float*>(fVar8 + 0x38) = uStack_74[1];
                    *reinterpret_cast<float*>(fVar8 + 0x3c) = uStack_74[2];
                    uVar9 = *reinterpret_cast<uint32_t*>(&uStack_74[3]);
                }
                *reinterpret_cast<uint32_t*>(fVar8 + 0x40) = uVar9;
                param_3[0xc] = static_cast<int>(fVar8);
                void* released = reinterpret_cast<void*>(fVar8);
                FUN_00571ce0(&released);
                if ((param_3[0] == 1) && (param_3[1] == 1)) {
                    return 1;
                }
            }
            local_17c = local_17c + 1;
        } while (static_cast<uint16_t>(local_17c) < static_cast<uint16_t>(uStack_110));
    }
    return local_18d;
}

// 0x596070 — observed shape
void FUN_00596070_recon(uint32_t param_1, int param_2, int param_3, uint8_t* param_4)
{
    int iVar4 = *reinterpret_cast<int*>(param_2 + 0xc);
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(iVar4 + 0xb0);
    int iVar5 = *reinterpret_cast<int*>(param_3 + 0xc);
    if (puVar1 != nullptr) {
        int iVar2 = static_cast<int>(puVar1[1]);
        puVar1[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar1[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar1);
            fn(1);
        }
    }
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(iVar5 + 0xb0);
    if (puVar3 != nullptr) {
        int iVar2 = static_cast<int>(puVar3[1]);
        puVar3[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar3[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar3);
            fn(1);
        }
    }
    if ((puVar1 == nullptr) || (puVar3 == nullptr)) {
        FUN_00595220(param_1, static_cast<uint32_t>(param_2), param_3,
                     static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_4)));
        return;
    }
    int iVar6 = static_cast<int>(puVar1[0xb]);
    int iVar7 = static_cast<int>(puVar3[0xb]);
    *param_4 = 0;
    if ((iVar6 != 3) && (iVar7 != 3)) {
        uint32_t uVar1 = FUN_005956d0(param_1, param_2, param_3, param_4);
        if (uVar1 == 1) {
            return;
        }
    }
    FUN_00596270(param_1, reinterpret_cast<char*>(static_cast<intptr_t>(param_2)), param_3, param_4);
}

// 0x596130 — observed shape
uint32_t FUN_00596130(int param_1, uint32_t param_2, int param_3, uint32_t param_4, uint32_t param_5)
{
    struct ItemCtx {
        uint8_t flag;
        uint8_t pad[3];
        uint32_t kind;
        uint32_t field8;
        int object;
        uint32_t field10;
        uint32_t field14;
    };
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0xc0);
    uint32_t uVar3 = 0;
    if (uVar1 != 0) {
        do {
            int local_c;
            if ((uVar3 < *reinterpret_cast<uint32_t*>(param_1 + 0xc0)) &&
                (local_c = *reinterpret_cast<int*>(
                     *reinterpret_cast<int*>(param_1 + 0xb8) + uVar3 * 4), local_c != 0)) {
                ItemCtx local_18;
                local_18.field8 = *reinterpret_cast<uint32_t*>(param_3 + 8);
                local_18.field10 = *reinterpret_cast<uint32_t*>(param_3 + 0x10);
                local_18.field14 = *reinterpret_cast<uint32_t*>(param_3 + 0x14);
                local_18.flag = 0;
                local_18.kind = 2;
                local_18.object = local_c;
                int iVar2 = FUN_00596070(param_2, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&local_18)),
                                         reinterpret_cast<void*>(static_cast<uintptr_t>(param_4)), param_5);
                if (iVar2 == 1) {
                    return 1;
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar1);
    }
    return 0;
}

// 0x5961d0 — observed shape
uint32_t FUN_005961d0(int param_1, uint32_t param_2, uint32_t param_3, int param_4, uint32_t param_5)
{
    struct ItemCtx {
        uint8_t flag;
        uint8_t pad[3];
        uint32_t kind;
        uint32_t field8;
        int object;
        uint32_t field10;
        uint32_t field14;
    };
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0xc0);
    uint32_t uVar3 = 0;
    if (uVar1 != 0) {
        do {
            int local_c;
            if ((uVar3 < *reinterpret_cast<uint32_t*>(param_1 + 0xc0)) &&
                (local_c = *reinterpret_cast<int*>(
                     *reinterpret_cast<int*>(param_1 + 0xb8) + uVar3 * 4), local_c != 0)) {
                ItemCtx local_18;
                local_18.field8 = *reinterpret_cast<uint32_t*>(param_4 + 8);
                local_18.field10 = *reinterpret_cast<uint32_t*>(param_4 + 0x10);
                local_18.field14 = *reinterpret_cast<uint32_t*>(param_4 + 0x14);
                local_18.flag = 0;
                local_18.kind = 2;
                local_18.object = local_c;
                int iVar2 = FUN_00596070(param_2, param_3,
                                         reinterpret_cast<void*>(&local_18), param_5);
                if (iVar2 == 1) {
                    return 1;
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar1);
    }
    return 0;
}

// 0x596270 — observed shape
uint32_t FUN_00596270(uint32_t param_1, char* param_2, int param_3, uint8_t* param_4)
{
    extern uint8_t DAT_00727560[];
    using ListFn = uint32_t*(__cdecl*)();

    if (*param_2 != 0) {
        int iVar5 = *reinterpret_cast<int*>(param_2 + 0xc);
        uint32_t* puVar6 = *reinterpret_cast<uint32_t**>(iVar5 + 0xb0);
        if (puVar6 != nullptr) {
            int iVar2 = static_cast<int>(puVar6[1]);
            puVar6[1] = static_cast<uint32_t>(iVar2 + 1);
            puVar6[1] = static_cast<uint32_t>(iVar2);
            if (iVar2 == 0) {
                using Fn = void(__cdecl*)(int);
                Fn fn = reinterpret_cast<Fn>(*puVar6);
                fn(1);
            }
            if (puVar6[0xb] == 3) {
                if (puVar6[10] != 2) {
                    return 0;
                }
            }
            else {
                uint8_t cVar3 = FUN_00594f50(puVar6[10], *param_4);
                if (cVar3 == 0) {
                    return 0;
                }
            }
        }
        return FUN_005961d0(iVar5, param_1,
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_2)),
                            param_3, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_4)));
    }
    int iVar5 = *reinterpret_cast<int*>(param_2 + 0xc);
    uint32_t* puVar6 = *reinterpret_cast<uint32_t**>(iVar5 + 0xb0);
    if (puVar6 != nullptr) {
        int iVar2 = static_cast<int>(puVar6[1]);
        puVar6[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar6[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar6);
            fn(1);
        }
        if ((puVar6[10] == 0) || (puVar6[10] == 1)) {
            uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar5 + 0xc0);
            uint32_t uVar8 = 0;
            if (uVar1 == 0) {
                return 0;
            }
            do {
                int iStack_c;
                if ((uVar8 < *reinterpret_cast<uint32_t*>(iVar5 + 0xc0)) &&
                    (iStack_c = *reinterpret_cast<int*>(
                         *reinterpret_cast<int*>(iVar5 + 0xb8) + uVar8 * 4), iStack_c != 0)) {
                    uint8_t auStack_18[4];
                    uint32_t uStack_14;
                    uint32_t uStack_10;
                    uint32_t uStack_8;
                    uint32_t uStack_4;
                    uStack_10 = *reinterpret_cast<uint32_t*>(param_2 + 8);
                    uStack_8 = *reinterpret_cast<uint32_t*>(param_2 + 0x10);
                    uStack_4 = *reinterpret_cast<uint32_t*>(param_2 + 0x14);
                    auStack_18[0] = 0;
                    uStack_14 = 2;
                    int iVar4 = FUN_00596070(
                        param_1, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(auStack_18)),
                        reinterpret_cast<void*>(static_cast<uintptr_t>(param_3)),
                        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_4)));
                    if (iVar4 == 1) {
                        return 1;
                    }
                }
                uVar8 = uVar8 + 1;
            } while (uVar8 < uVar1);
            return 0;
        }
    }
    *param_2 = 1;
    int iVar4 = static_cast<int>(FUN_00596270(param_1, param_2, param_3, param_4));
    *param_2 = 0;
    if (iVar4 == 1) {
        return 1;
    }
    int* piVar2 = *reinterpret_cast<int**>(param_2 + 0xc);
    if (piVar2 == nullptr) {
        return 0;
    }
    int vtable = *piVar2;
    ListFn listNext = reinterpret_cast<ListFn>(*reinterpret_cast<uint32_t*>(vtable + 4));
    puVar6 = listNext();
    if (puVar6 == nullptr) {
        return 0;
    }
    while (puVar6 != reinterpret_cast<uint32_t*>(DAT_00727560)) {
        puVar6 = reinterpret_cast<uint32_t*>(puVar6[1]);
        if (puVar6 == nullptr) {
            return 0;
        }
    }
    puVar6 = reinterpret_cast<uint32_t*>(piVar2[0x2c]);
    if (puVar6 != nullptr) {
        int iVar2 = static_cast<int>(puVar6[1]);
        puVar6[1] = static_cast<uint32_t>(iVar2 + 1);
        puVar6[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar6);
            fn(1);
        }
        if (puVar6[0xb] == 3) {
            if (puVar6[10] != 2) {
                return 0;
            }
        }
        else {
            uint8_t cVar3 = FUN_00594f50(puVar6[10], *param_4);
            if (cVar3 == 0) {
                return 0;
            }
        }
    }
    return FUN_00596130(static_cast<int>(reinterpret_cast<intptr_t>(piVar2)), param_1,
                        static_cast<int>(reinterpret_cast<intptr_t>(param_2)), param_3,
                        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_4)));
}

// 0x596480 — observed shape
uint32_t FUN_00596480(uint32_t param_1, uint32_t param_2, int param_3, int* param_4,
                      uint32_t in_EAX = 0)
{
    extern uint8_t DAT_00727560[];
    using ListFn = uint32_t*(__cdecl*)();

    uint32_t uVar3 = (in_EAX >> 8) & 0xffffff;
    if (param_4 == nullptr) {
        return uVar3 << 8;
    }
    if ((*reinterpret_cast<int8_t*>(param_3 + 0x11) != 0) &&
        ((*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(param_4) + 0x20) & 1) != 0)) {
        return uVar3 << 8;
    }
    uint32_t uVar1 = FUN_0059eb00(param_4, param_1, param_2);
    if (static_cast<uint8_t>(uVar1) != 0) {
        int vtable = *param_4;
        ListFn listNext = reinterpret_cast<ListFn>(*reinterpret_cast<uint32_t*>(vtable + 4));
        for (uint32_t* puVar2 = listNext(); puVar2 != nullptr;
             puVar2 = reinterpret_cast<uint32_t*>(puVar2[1])) {
            if (puVar2 == reinterpret_cast<uint32_t*>(DAT_00727560)) {
                return FUN_00596590(param_1, param_2, param_3, param_4);
            }
        }
        uVar1 = FUN_004879c0(DAT_00727c3c, param_4);
        if (static_cast<uint8_t>(uVar1) != 0) {
            return FUN_00595810(reinterpret_cast<float*>(static_cast<uintptr_t>(param_1)), param_2,
                                reinterpret_cast<int*>(static_cast<intptr_t>(param_3)),
                                static_cast<int>(reinterpret_cast<intptr_t>(param_4)));
        }
    }
    return uVar1 & 0xffffff00;
}

// 0x596520 — observed shape
uint8_t FUN_00596520(uint32_t param_1, uint32_t param_2, int* param_3, int param_4)
{
    int iVar1 = *reinterpret_cast<int*>(param_4 + 0xf0);
    uint8_t uVar3 = 0;
    if (iVar1 >= 0) {
        if ((param_3[0] == 1) && (param_3[1] == 1) && (param_3[10] != 0)) {
            return 1;
        }
        if ((iVar1 < *reinterpret_cast<int*>(param_4 + 0xc0)) &&
            (iVar1 = *reinterpret_cast<int*>(
                 *reinterpret_cast<int*>(param_4 + 0xb8) + iVar1 * 4), iVar1 != 0)) {
            uint8_t cVar2 = FUN_00596480(param_1, param_2,
                                         static_cast<int>(reinterpret_cast<intptr_t>(param_3)),
                                         reinterpret_cast<int*>(iVar1));
            if (cVar2 != 0) {
                uVar3 = 1;
            }
        }
    }
    return uVar3;
}

// 0x596590 — observed shape
uint32_t FUN_00596590(uint32_t param_1, uint32_t param_2, int* param_3, int* param_4)
{
    extern uint8_t DAT_00727d58[];
    using ListFn = uint32_t*(__cdecl*)();

    int* piVar2 = param_4;
    int* piVar1 = param_3;
    if ((param_3[2] == 0) && (*param_3 == 1)) {
        int iVar4 = FUN_00533c78(0x44);
        if (iVar4 == 0) {
            param_3 = nullptr;
        }
        else {
            using AllocFn = void*(__cdecl*)(int);
            param_3 = reinterpret_cast<int*>(reinterpret_cast<AllocFn>(FUN_00594fa0)(
                static_cast<int>(reinterpret_cast<intptr_t>(param_4))));
        }
        piVar1[0xc] = static_cast<int>(reinterpret_cast<intptr_t>(param_3));
        void* released = reinterpret_cast<void*>(param_3);
        FUN_00571ce0(&released);
        return 1;
    }
    if (param_4 != nullptr) {
        int vtable = *param_4;
        ListFn listNext = reinterpret_cast<ListFn>(*reinterpret_cast<uint32_t*>(vtable + 4));
        for (uint32_t* puVar5 = listNext(); puVar5 != nullptr;
             puVar5 = reinterpret_cast<uint32_t*>(puVar5[1])) {
            if (puVar5 == reinterpret_cast<uint32_t*>(DAT_00727d58)) {
                return FUN_00596520(param_1, param_2, piVar1,
                                    static_cast<int>(reinterpret_cast<intptr_t>(piVar2)));
            }
        }
    }
    uint32_t uVar6 = static_cast<uint32_t>(piVar2[0x30]);
    uint32_t uVar7 = 0;
    uint32_t flag = 0;
    if (uVar6 != 0) {
        do {
            if ((*piVar1 == 1) && (piVar1[1] == 1) && (piVar1[10] != 0)) {
                return 1;
            }
            int iVar4;
            if ((uVar7 < uVar6) &&
                (iVar4 = *reinterpret_cast<int*>(piVar2[0x2e] + uVar7 * 4), iVar4 != 0) &&
                (FUN_00596480(param_1, param_2,
                              static_cast<int>(reinterpret_cast<intptr_t>(piVar1)),
                              reinterpret_cast<int*>(iVar4)) != 0)) {
                flag = 1;
            }
            uVar6 = static_cast<uint32_t>(piVar2[0x30]);
            uVar7 = uVar7 + 1;
        } while (uVar7 < uVar6);
    }
    return flag & 0xff;
}

// 0x596690 — observed shape
uint32_t FUN_00596690(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t in_ECX = 0)
{
    uint32_t uStack_4 = in_ECX;
    FUN_00596070(param_1, param_2,
                 reinterpret_cast<void*>(static_cast<uintptr_t>(param_3)),
                 static_cast<uint32_t>(reinterpret_cast<uintptr_t>(
                     reinterpret_cast<uint8_t*>(&uStack_4) + 3)));
    return uStack_4 >> 0x18;
}
