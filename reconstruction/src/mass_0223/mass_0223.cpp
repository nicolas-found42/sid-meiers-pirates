// Reconstruction batch mass_0223 — Sid Meier's Pirates! (2004)
// Each definition preserves observed offsets, constants, call order and conditionals.
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void*);
extern void FUN_00520d40(void* out, int value);
extern void FUN_005bfa50(int value);
extern void FUN_005edba0(void);
extern void FUN_005e1490(void);
extern void FUN_005cfa20(void* self);
extern void *PTR_FUN_006c81e4;
extern void *PTR_FUN_006c81d4;
extern void *PTR_LAB_006c81ac;
extern void *PTR_FUN_006c81b8;
extern void *PTR_FUN_006c8190;
extern void *PTR_LAB_006fd148;
extern int DAT_00727444;
extern float _DAT_00727c78;
extern int DAT_00728e94;

// 0x5cf870 — observed shape
uint32_t FUN_005cf870(void* self, uint32_t* param_1)
{
    uint32_t* s = static_cast<uint32_t*>(self);
    if (s[0x1a] == param_1[0x30]) {
        return 0;
    }
    s[0x1a] = param_1[0x30];
    uint32_t* puVar2 = s;
    for (int iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    using Fn0 = int (*)();
    Fn0 fn = *reinterpret_cast<Fn0*>(reinterpret_cast<uint8_t*>(*param_1) + 0x70);
    int iVar1 = fn();
    if (iVar1 == 1) {
        s[0] = 3;
        s[0x10] = param_1[0x44];
        s[0x11] = param_1[0x45];
        s[0x12] = param_1[0x46];
    } else {
        if (iVar1 == 2) {
            s[0] = 1;
            s[0xd] = param_1[0x24];
            s[0xe] = param_1[0x25];
            s[0xf] = param_1[0x26];
        } else {
            if (iVar1 != 3) goto LAB_005cf93a;
            s[0] = 2;
            s[0xd] = param_1[0x24];
            s[0xe] = param_1[0x25];
            s[0xf] = param_1[0x26];
            s[0x10] = param_1[0x47];
            s[0x11] = param_1[0x48];
            s[0x12] = param_1[0x49];
            s[0x18] = 0;
            s[0x19] = static_cast<uint32_t>(_DAT_00727c78 * static_cast<float>(param_1[0x4a]) * 0.011111111f);
            s[0x14] = param_1[0x4b];
        }
        s[0x15] = param_1[0x44];
        s[0x16] = param_1[0x45];
        s[0x17] = param_1[0x46];
        s[0x13] = DAT_00728e94;
    }
LAB_005cf93a:
    iVar1 = static_cast<int>(param_1[0x39]);
    uint32_t uStack_24 = 0, uStack_20 = 0, uStack_1c = 0;
    uint32_t uStack_18 = 0, uStack_14 = 0, uStack_10 = 0;
    uint32_t uStack_c = 0, uStack_8 = 0, uStack_4 = 0;
    // FUN_00520d40 fills 12-byte task/error-like slot (matches other callers).
    {
        struct Slot { uint32_t a,b,c; } a,b,c;
        FUN_00520d40(&a, iVar1); FUN_00520d40(&b, iVar1); FUN_00520d40(&c, iVar1);
        uStack_24 = a.a; uStack_20 = a.b; uStack_1c = a.c;
        uStack_18 = b.a; uStack_14 = b.b; uStack_10 = b.c;
        uStack_c = c.a; uStack_8 = c.b; uStack_4 = c.c;
    }
    s[0xb] = uStack_1c;
    s[9] = uStack_24;
    s[10] = uStack_20;
    s[3] = uStack_10;
    s[1] = uStack_18;
    s[2] = uStack_14;
    s[7] = uStack_4;
    s[5] = uStack_c;
    s[6] = uStack_8;
    return 1;
}

// 0x5cfa20 — observed shape
void FUN_005cfa20(void* self)
{
    uint32_t* s = static_cast<uint32_t*>(self);
    s[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c81e4);
    if (s[5] != 0) {
        do {
            uint32_t uVar3 = 0;
            uint32_t* piVar4 = nullptr;
            if (s[3] != 0) {
                piVar4 = reinterpret_cast<uint32_t*>(s[4]);
                do {
                    if (*piVar4 != 0) {
                        piVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*>(s[4])[uVar3]);
                        goto LAB_005cfa5e;
                    }
                    uVar3 = uVar3 + 1;
                    piVar4 = piVar4 + 1;
                } while (uVar3 < s[3]);
            }
            piVar4 = nullptr;
LAB_005cfa5e:
            {
                int iVar1 = static_cast<int>(piVar4[1]);
                void* pvVar2 = reinterpret_cast<void*>(piVar4[2]);
                if (*piVar4 == 0) {
                    using Fn = int (*)(int);
                    Fn fn = *reinterpret_cast<Fn*>(s[2] + 4);
                    int iVar5 = fn(iVar1);
                    uVar3 = static_cast<uint32_t>(iVar5 + 1);
                    if (uVar3 < s[3]) {
                        piVar4 = reinterpret_cast<uint32_t*>(s[4] + uVar3 * 4);
                        do {
                            if (*piVar4 != 0) break;
                            uVar3 = uVar3 + 1;
                            piVar4 = piVar4 + 1;
                        } while (uVar3 < s[3]);
                    }
                }
                FUN_005bfa50(iVar1);
                *reinterpret_cast<uint32_t*>(iVar1 + 0x10c) = 0;
                operator_delete(pvVar2);
            }
        } while (s[5] != 0);
    }
    if (s[9] != 0) {
        do {
            uint32_t* piVar4 = reinterpret_cast<uint32_t*>(s[7]);
            int iVar1 = static_cast<int>(*piVar4);
            s[7] = static_cast<uint32_t>(iVar1);
            if (iVar1 == 0) {
                s[8] = 0;
            } else {
                *reinterpret_cast<uint32_t*>(iVar1 + 4) = 0;
            }
            using Fn = void (*)(uint32_t*);
            Fn fn = *reinterpret_cast<Fn*>(s[6] + 8);
            fn(piVar4);
            s[9] = s[9] + -1;
        } while (s[9] != 0);
    }
    uint32_t* piVar4 = reinterpret_cast<uint32_t*>(s[10]);
    if (piVar4 != nullptr) {
        using Fn = void (*)(uint32_t*);
        Fn fn = *reinterpret_cast<Fn*>(*piVar4 + 8);
        fn(piVar4);
        s[10] = 0;
    }
    s[6] = reinterpret_cast<uint32_t>(PTR_FUN_006c81d4);
    FUN_005edba0();
    s[6] = reinterpret_cast<uint32_t>(PTR_LAB_006c81ac);
    s[2] = reinterpret_cast<uint32_t>(PTR_FUN_006c81b8);
    FUN_005e1490();
    s[2] = reinterpret_cast<uint32_t>(PTR_FUN_006c8190);
    FUN_005e1490();
    operator_delete(reinterpret_cast<void*>(s[4]));
    s[0] = reinterpret_cast<uint32_t>(PTR_LAB_006fd148);
    DAT_00727444 = DAT_00727444 + -1;
}

// 0x5cfb50 — observed shape
void FUN_005cfb50(void* self)
{
    int* s = static_cast<int*>(self);
    if (*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) != 0) {
        do {
            int* piVar1 = *reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x1c);
            int iVar2 = *piVar1;
            *reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x1c) = iVar2;
            if (iVar2 == 0) {
                *reinterpret_cast<uint32_t*>(reinterpret_cast<int8_t*>(s) + 0x20) = 0;
            } else {
                *reinterpret_cast<uint32_t*>(iVar2 + 4) = 0;
            }
            int iVar2b = piVar1[2];
            using Fn = void (*)(int*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x18) + 8);
            fn(piVar1);
            *reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) = *reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) + -1;
            using Fn2 = void (*)(int*, uint32_t, int);
            Fn2 fn2 = *reinterpret_cast<Fn2*>(**reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x28) + 0xd4);
            fn2(*reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x28), *reinterpret_cast<uint32_t*>(iVar2b + 0xb8), 0);
        } while (*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) != 0);
    }
    *reinterpret_cast<uint32_t*>(reinterpret_cast<int8_t*>(s) + 0x30) = 0;
}

// 0x5cfbb0 — observed shape
void FUN_005cfbb0(void* self, uint8_t param_1)
{
    FUN_005cfa20(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5cfbd0 — observed shape
extern int FUN_00533c78(int size);
extern int FUN_005cf870(void* self, uint32_t* param_1);
extern void FUN_00545310(void* a, int b);
extern int FUN_005f0ddc(int x);
extern int FUN_005f0ddc();
void FUN_005cfbd0(void* self, int param_1)
{
    int* s = static_cast<int*>(self);
    int iVar4 = 0;
    if (*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) != 0) {
        do {
            int* piVar1 = *reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x1c);
            iVar4 = *piVar1;
            *reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x1c) = iVar4;
            if (iVar4 == 0) {
                *reinterpret_cast<uint32_t*>(reinterpret_cast<int8_t*>(s) + 0x20) = 0;
            } else {
                *reinterpret_cast<uint32_t*>(iVar4 + 4) = 0;
            }
            iVar4 = piVar1[2];
            using Fn = void (*)(int*);
            Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x18) + 8);
            fn(piVar1);
            *reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) = *reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) + -1;
            using Fn2 = void (*)(int*, uint32_t, int);
            Fn2 fn2 = *reinterpret_cast<Fn2*>(**reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x28) + 0xd4);
            fn2(*reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x28), *reinterpret_cast<uint32_t*>(iVar4 + 0xb8), 0);
        } while (*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) != 0);
    }
    if ((*reinterpret_cast<char*>(reinterpret_cast<int8_t*>(s) + 0x3c) != '\0') && (param_1 != 0)) {
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(param_1 + 0xc);
        while (puVar2 != nullptr) {
            uint32_t* puVar5 = reinterpret_cast<uint32_t*>(*puVar2);
            int* piVar1 = reinterpret_cast<int*>(puVar2[1]);
            puVar2 = puVar5;
            if ((reinterpret_cast<uint8_t*>(piVar1)[0x2d * 4] != '\0') && (0.01f <= reinterpret_cast<float*>(piVar1)[0x39]) &&
                (((int (*)())(*reinterpret_cast<void**>(piVar1)[0x70 / 4]))() != 0)) {
                iVar4 = piVar1[0x43];
                if (iVar4 == 0) {
                    iVar4 = FUN_00533c78(0x70);
                    if (iVar4 == 0) {
                        iVar4 = 0;
                    } else {
                        *reinterpret_cast<uint32_t*>(iVar4 + 0x68) = 0;
                        *reinterpret_cast<int*>(iVar4 + 0x6c) = piVar1[0x2e];
                        FUN_005cf870(reinterpret_cast<void*>(0), reinterpret_cast<uint32_t*>(piVar1));
                    }
                    FUN_00545310(piVar1, iVar4);
                    piVar1[0x43] = iVar4;
LAB_005cfce7:
                    using Fn3 = void (*)(int*, uint32_t, int);
                    Fn3 fn3 = *reinterpret_cast<Fn3*>(**reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x28) + 0xcc);
                    fn3(*reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x28), *reinterpret_cast<uint32_t*>(iVar4 + 0x6c), iVar4);
                } else {
                    char cVar3 = static_cast<char>(FUN_005cf870(reinterpret_cast<void*>(0), reinterpret_cast<uint32_t*>(piVar1)));
                    if (cVar3 != '\0') goto LAB_005cfce7;
                }
                using Fn4 = void (*)(int*, uint32_t, int);
                Fn4 fn4 = *reinterpret_cast<Fn4*>(**reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x28) + 0xd4);
                fn4(*reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x28), *reinterpret_cast<uint32_t*>(iVar4 + 0x6c), 1);
                using Fn5 = uint32_t* (*)();
                Fn5 fn5 = *reinterpret_cast<Fn5*>(*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x18) + 4);
                uint32_t* puVar5b = fn5();
                puVar5b[2] = reinterpret_cast<uint32_t>(piVar1);
                puVar5b[1] = 0;
                *puVar5b = *reinterpret_cast<uint32_t*>(reinterpret_cast<int8_t*>(s) + 0x1c);
                if (*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x1c) == 0) {
                    *reinterpret_cast<uint32_t**>(reinterpret_cast<int8_t*>(s) + 0x20) = puVar5b;
                } else {
                    *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x1c) + 4) = puVar5b;
                }
                *reinterpret_cast<uint32_t**>(reinterpret_cast<int8_t*>(s) + 0x1c) = puVar5b;
                *reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) = *reinterpret_cast<int*>(reinterpret_cast<int8_t*>(s) + 0x24) + 1;
            }
        }
    }
    iVar4 = **reinterpret_cast<int**>(reinterpret_cast<int8_t*>(s) + 0x2c);
    uint32_t uVar6 = static_cast<uint32_t>(FUN_005f0ddc(0));
    uint32_t uVar7 = static_cast<uint32_t>(FUN_005f0ddc());
    uint32_t uVar8 = static_cast<uint32_t>(FUN_005f0ddc());
    using Fn6 = void (*)(int, uint32_t);
    Fn6 fn6 = *reinterpret_cast<Fn6*>(iVar4 + 0x70);
    fn6(0x8b, (((uVar6 & 0xff | 0xffffff00) << 8 | (uVar7 & 0xff)) << 8 | (uVar8 & 0xff)));
}

extern void* thunk_FUN_00533c78(int size);
extern void operator_delete__(void* ptr);
extern void FUN_005cf730(void* self);
extern char FUN_005bd960(int param_1, int* param_2);
extern void FUN_00535830(void* p);
extern void FUN_00535540(void* p);
extern void FUN_005510a0(void);
extern void FUN_005510b0(void);
extern void FUN_005d87d0(void);
extern int FUN_005d9130(uint32_t param_1);
extern int FUN_005d91d0(uint32_t param_1);
extern int FUN_005d9eb0(uint32_t param_1);
extern void FUN_0055f300(int capacity);
extern void FUN_00497420(const char* fmt, ...);
extern void *PTR_FUN_006c81f0;

// 0x5cfde0 — observed shape
void FUN_005cfde0(void* self, uint32_t param_1, int* param_2)
{
    uint32_t* s = static_cast<uint32_t*>(self);
    s[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_LAB_006fd148));
    s[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    s[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c81e4));
    s[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8190));
    s[3] = 0x25;
    s[5] = 0;
    uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
    s[4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    for (uint32_t uVar2 = s[3] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar1) + 1);
    }
    s[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c81b8));
    s[9] = 0;
    s[7] = 0;
    s[8] = 0;
    s[6] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c81d4));
    s[0xb] = param_1;
    s[10] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_2));
    {
        using Fn = void (*)(int*);
        Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<uint32_t*>(param_2) + 4);
        fn(param_2);
    }
    FUN_005cf730(self);
}

// 0x5cfe70 — observed shape
void FUN_005cfe70(void* self, uint32_t param_1, int param_2, int param_3, int unaff_EDI)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    int* obj = *reinterpret_cast<int**>(b + 0x2c);
    using Fn0 = void (*)();
    using Fn3 = void (*)(int, int, int);
    int iVar1 = *reinterpret_cast<int*>(param_2 + 0x20);
    *reinterpret_cast<int*>(b + 0x38) = iVar1;
    {
        int* pvObj = *reinterpret_cast<int**>(param_2 + 0x2c);
        int vBase = *pvObj;
        if ((vBase != 0) && (*reinterpret_cast<int*>(vBase + 4) != 0) && (iVar1 == 0)) {
            Fn0 fn = *reinterpret_cast<Fn0*>(*obj + 0x70);
            fn();
            return;
        }
    }
    iVar1 = *reinterpret_cast<int*>(param_3 + 0x24);
    if (*reinterpret_cast<int*>(param_3 + 0x28) == 0) {
        if ((iVar1 != 0) && ((iVar1 == 1) || (iVar1 != 2))) {
            Fn0 fn = *reinterpret_cast<Fn0*>(*obj + 0x70);
            fn();
            return;
        }
        *reinterpret_cast<uint8_t*>(b + 0x3c) = 0;
        if (*reinterpret_cast<int*>(b + 0x40) == 1) {
            Fn3 fn3 = *reinterpret_cast<Fn3*>(*obj + 0x70);
            fn3(0x94, 0, 0);
            fn3(0x93, 0, 0);
            fn3(0x91, 0, 0);
            *reinterpret_cast<uint32_t*>(b + 0x40) = 0;
        }
        goto LAB_005cffd4;
    }
    if (iVar1 != *reinterpret_cast<int*>(b + 0x40)) {
        Fn3 fn3 = *reinterpret_cast<Fn3*>(*obj + 0x70);
        if (iVar1 == 0) {
            fn3(0x94, 0, 0);
            fn3(0x93, 0, 0);
            fn3(0x91, 0, 0);
        } else if (iVar1 == 1) {
            fn3(0x94, 1, 0);
            fn3(0x93, 0, 0);
            fn3(0x91, 0, 0);
        } else if (iVar1 == 2) {
            fn3(0x94, 0, 0);
            fn3(0x93, 1, 0);
            fn3(0x91, 1, 0);
        }
        *reinterpret_cast<int*>(b + 0x40) = iVar1;
    }
    *reinterpret_cast<uint8_t*>(b + 0x3c) = 1;
LAB_005cffd4:
    {
        Fn3 fn3 = *reinterpret_cast<Fn3*>(*obj + 0x70);
        fn3(0x89, 1, 0);
    }
    if ((unaff_EDI != *reinterpret_cast<int*>(b + 0x30)) ||
        (*reinterpret_cast<uint8_t*>(b + 0x3c) != *reinterpret_cast<uint8_t*>(b + 0x34))) {
        FUN_005cfbd0(b, unaff_EDI);
        *reinterpret_cast<int*>(b + 0x30) = unaff_EDI;
        *reinterpret_cast<uint8_t*>(b + 0x34) = *reinterpret_cast<uint8_t*>(b + 0x3c);
    }
}

// 0x5d0030 — observed shape
void FUN_005d0030(void* self, int param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint8_t auStackY_a0[128];
    int iVar2 = param_1;
    void* pvVar1 = *reinterpret_cast<void**>(param_1 + 0x10c);
    if (pvVar1 != nullptr) {
        FUN_005bd960(param_1, &param_1);
        {
            int* obj = *reinterpret_cast<int**>(b + 0x28);
            using Fn = void (*)(int*, uint32_t, int);
            Fn fn = *reinterpret_cast<Fn*>(*obj + 0xd4);
            fn(obj, *reinterpret_cast<uint32_t*>(iVar2 + 0xb8), 0);
        }
        FUN_005bfa50(iVar2);
        FUN_00535830(auStackY_a0 + 0x98);
        *reinterpret_cast<uint32_t*>(iVar2 + 0x10c) = 0;
        operator_delete(pvVar1);
        return;
    }
    char cVar3 = FUN_005bd960(param_1, &param_1);
    if (cVar3 != '\0') {
        FUN_005bfa50(iVar2);
        param_1 = iVar2;
        FUN_00535830(&param_1);
        *reinterpret_cast<uint32_t*>(iVar2 + 0x10c) = 0;
    }
}

// 0x5d00e0 — observed shape
void FUN_005d00e0(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t uVar3 = 0;
    int* piVar4;
    if (*reinterpret_cast<uint32_t*>(b + 0xc) != 0) {
        int* arrayBase = *reinterpret_cast<int**>(b + 0x10);
        piVar4 = arrayBase;
        do {
            if (*piVar4 != 0) {
                piVar4 = reinterpret_cast<int*>(arrayBase[uVar3]);
                goto joined;
            }
            uVar3 = uVar3 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar3 < *reinterpret_cast<uint32_t*>(b + 0xc));
    }
    piVar4 = nullptr;
joined:
    while (true) {
        void* pvVar1;
        int iVar2;
        do {
            if (piVar4 == nullptr) {
                return;
            }
            pvVar1 = reinterpret_cast<void*>(piVar4[2]);
            iVar2 = piVar4[1];
            piVar4 = reinterpret_cast<int*>(*piVar4);
            if (piVar4 == nullptr) {
                using Fn = int (*)(int);
                Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<int*>(b + 8) + 4);
                int iVar5 = fn(iVar2);
                uVar3 = static_cast<uint32_t>(iVar5 + 1);
                if (uVar3 < *reinterpret_cast<uint32_t*>(b + 0xc)) {
                    uint32_t* puVar6 = reinterpret_cast<uint32_t*>(
                        *reinterpret_cast<int*>(b + 0x10) + uVar3 * 4);
                    do {
                        piVar4 = reinterpret_cast<int*>(*puVar6);
                        if (piVar4 != nullptr) goto LAB_005d0164;
                        uVar3 = uVar3 + 1;
                        puVar6 = puVar6 + 1;
                    } while (uVar3 < *reinterpret_cast<uint32_t*>(b + 0xc));
                }
                piVar4 = nullptr;
            }
LAB_005d0164:
            ;
        } while (pvVar1 == nullptr);
        {
            int* obj = *reinterpret_cast<int**>(b + 0x28);
            using Fn2 = void (*)(int*, uint32_t, int);
            Fn2 fn2 = *reinterpret_cast<Fn2*>(*obj + 0xd4);
            fn2(obj, *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(pvVar1) + 0x6c), 0);
        }
        FUN_005bfa50(iVar2);
        uint32_t* puVar6 = *reinterpret_cast<uint32_t**>(b + 0x1c);
        uint32_t* puStack_4;
        do {
            puStack_4 = puVar6;
            if (puStack_4 == nullptr) {
                puStack_4 = nullptr;
                break;
            }
            puVar6 = reinterpret_cast<uint32_t*>(*puStack_4);
        } while (iVar2 != static_cast<int>(puStack_4[2]));
        if (puStack_4 != nullptr) {
            FUN_00535540(&puStack_4);
        }
        *reinterpret_cast<uint32_t*>(iVar2 + 0x10c) = 0;
        operator_delete(pvVar1);
    }
}

// 0x5d0200 — observed shape
void FUN_005d0200(void* self)
{
    uint32_t* s = static_cast<uint32_t*>(self);
    uint32_t uVar1 = s[3];
    uint32_t uVar3 = 0;
    s[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c81f0));
    if (uVar1 != 0) {
        do {
            int* piVar2 = *reinterpret_cast<int**>(s[1] + uVar3 * 4);
            if (piVar2 != nullptr) {
                using Fn = void (*)(void*, int);
                Fn fn = *reinterpret_cast<Fn*>(*piVar2 + 0x2c);
                fn(piVar2, 1);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar1);
    }
    FUN_005d87d0();
    int* piVar2 = reinterpret_cast<int*>(s[4]);
    if (piVar2 != nullptr) {
        using Fn = void (*)(void*);
        Fn fn = *reinterpret_cast<Fn*>(*piVar2 + 8);
        fn(piVar2);
    }
    operator_delete__(reinterpret_cast<void*>(s[1]));
    FUN_005510b0();
}

// 0x5d0260 — observed shape
uint32_t* FUN_005d0260(int* param_1)
{
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x1c));
    if (puVar1 == nullptr) {
        puVar1 = nullptr;
    } else {
        FUN_005510a0();
        *puVar1 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c81f0));
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar1[4] = 0;
        puVar1[5] = 0;
        *reinterpret_cast<uint8_t*>(puVar1 + 6) = 0;
    }
    puVar1[4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
    {
        using Fn = void (*)(int*);
        Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<uint32_t*>(param_1) + 4);
        fn(param_1);
    }
    puVar1[5] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
    return puVar1;
}

// 0x5d03f0 — observed shape
char FUN_005d03f0(int param_1)
{
    int iVar4 = *reinterpret_cast<int*>(param_1 + 0xc);
    int iVar3 = *reinterpret_cast<int*>(param_1 + 0x10);
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(
        *reinterpret_cast<int*>(iVar3 + 0x28) + 4);
    char cVar2 = '\0';
    if (iVar4 != 0) {
        do {
            if (*reinterpret_cast<int*>(iVar3 + 0x28) != 0) {
                int* p = *reinterpret_cast<int**>(*reinterpret_cast<int*>(iVar3 + 0x28) + 4);
                using Fn = void (*)(int);
                Fn fn = *reinterpret_cast<Fn*>(*p + 0x18);
                fn(iVar3);
                cVar2 = '\x01';
            }
            iVar3 = iVar3 + 0x2c;
            iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if ((cVar2 != '\0') && (puVar1[1] == 0)) {
            using Fn0 = void (*)();
            Fn0 fn0 = *reinterpret_cast<Fn0*>(*puVar1);
            fn0();
        }
    }
    return cVar2;
}

// 0x5d0450 — observed shape
void FUN_005d0450(void* self, uint8_t param_1)
{
    FUN_005d0200(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5d0470 — observed shape
int FUN_005d0470(void* self, int param_1, uint32_t param_2)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    int iVar1;
    if (param_1 == 0) {
        iVar1 = FUN_005d9130(param_2);
    } else if (param_1 == 1) {
        iVar1 = FUN_005d91d0(param_2);
    } else {
        if (param_1 != 2) {
            return 0;
        }
        iVar1 = FUN_005d9eb0(param_2);
    }
    if (iVar1 != 0) {
        uint32_t uVar2 = 0;
        if (*reinterpret_cast<uint32_t*>(b + 0xc) != 0) {
            int* piVar4 = *reinterpret_cast<int**>(b + 4);
            do {
                if (*piVar4 == iVar1) {
                    if (-1 < static_cast<int>(uVar2)) {
                        return iVar1;
                    }
                    break;
                }
                uVar2 = uVar2 + 1;
                piVar4 = piVar4 + 1;
            } while (uVar2 < *reinterpret_cast<uint32_t*>(b + 0xc));
        }
        int iVar3 = *reinterpret_cast<int*>(b + 8);
        if (*reinterpret_cast<int*>(b + 0xc) == iVar3) {
            if (iVar3 == 0) {
                iVar3 = 1;
            } else {
                iVar3 = iVar3 * 2;
            }
            FUN_0055f300(iVar3);
        }
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(b + 4) +
                                *reinterpret_cast<int*>(b + 0xc) * 4) = iVar1;
        *reinterpret_cast<int*>(b + 0xc) = *reinterpret_cast<int*>(b + 0xc) + 1;
        int* piVar4 = *reinterpret_cast<int**>(b + 0x10);
        *reinterpret_cast<int**>(iVar1 + 0xc) = piVar4;
        using Fn = void (*)(int*);
        Fn fn = *reinterpret_cast<Fn*>(*piVar4 + 4);
        fn(piVar4);
    }
    return iVar1;
}

// 0x5d0510 — observed shape
uint32_t FUN_005d0510(void* self, int* param_1, int param_2, int param_3, uint32_t param_4)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    int iVar1 = 0;
    int iVar2;
    if ((param_3 == 0) || (*reinterpret_cast<char*>(b + 0x18) == '\0') ||
        (*reinterpret_cast<int*>(param_3 + 0xc) == 0) ||
        ((iVar1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_3 + 0xc) + 0xc)),
         (iVar1 == 0))) {
        if (*reinterpret_cast<int*>(param_2 + 0x38) != 0) {
            return 0;
        }
        using Fn = void (*)(int*, int, int, int, uint32_t);
        Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<uint32_t*>(param_1) + 0xc);
        fn(param_1, param_2, param_3, 0, param_4);
    } else {
        iVar2 = *reinterpret_cast<int*>(iVar1 + 0x10);
        if (*reinterpret_cast<int*>(iVar2 + 0x28) != 0) {
            return 0;
        }
        iVar1 = *reinterpret_cast<int*>(iVar1 + 0xc);
        if (iVar1 != 0) {
            do {
                using Fn = void (*)(int*, int, int, int, uint32_t);
                Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<uint32_t*>(param_1) + 0xc);
                fn(param_1, param_2, param_3, iVar2, param_4);
                iVar2 = iVar2 + 0x2c;
                iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
            return 1;
        }
    }
    return 1;
}

// 0x5d0610 — observed shape
void FUN_005d0610(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t uVar1 = 0;
    if ((*reinterpret_cast<int*>(b + 4) != 0) && (*reinterpret_cast<int*>(b + 0x14) != 0)) {
        do {
            int* obj = *reinterpret_cast<int**>(b + 4);
            using Fn = void (*)();
            Fn fn = *reinterpret_cast<Fn*>(*obj + 0x24);
            fn();
            uVar1 = uVar1 + 1;
        } while (uVar1 < *reinterpret_cast<uint32_t*>(b + 0x14));
    }
    operator_delete__(*reinterpret_cast<void**>(b + 0x1c));
    operator_delete__(*reinterpret_cast<void**>(b + 0x18));
}

// 0x5d0650 — observed shape
void FUN_005d0650(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    int* piVar1 = *reinterpret_cast<int**>(b + 0x28);
    *reinterpret_cast<uint32_t*>(b + 0x24) = 0;
    if (piVar1 != nullptr) {
        using Fn = void (*)(int*);
        Fn fn = *reinterpret_cast<Fn*>(*piVar1 + 8);
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(b + 0x28) = 0;
    }
}

// 0x5d0670 — observed shape
void FUN_005d0670(void* self, uint32_t param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    if (param_1 != *reinterpret_cast<uint32_t*>(b + 0x14)) {
        uint32_t* puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(static_cast<int>(param_1 * 4)));
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(static_cast<int>(param_1 * 4)));
        uint32_t uVar3 = *reinterpret_cast<uint32_t*>(b + 0x14);
        if (param_1 < uVar3) {
            uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(b + 0x1c);
            uint32_t* puVar6 = puVar1;
            for (uVar3 = param_1 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + 1;
            }
            for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *reinterpret_cast<uint8_t*>(puVar6) = *reinterpret_cast<uint8_t*>(puVar5);
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar5) + 1);
                puVar6 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar6) + 1);
            }
            puVar5 = *reinterpret_cast<uint32_t**>(b + 0x18);
            puVar6 = puVar2;
            for (uVar3 = param_1 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + 1;
            }
            for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *reinterpret_cast<uint8_t*>(puVar6) = *reinterpret_cast<uint8_t*>(puVar5);
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar5) + 1);
                puVar6 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar6) + 1);
            }
            if ((*reinterpret_cast<int*>(b + 4) != 0) &&
                (uVar3 = param_1, param_1 < *reinterpret_cast<uint32_t*>(b + 0x14))) {
                do {
                    int* obj = *reinterpret_cast<int**>(b + 4);
                    using Fn = void (*)();
                    Fn fn = *reinterpret_cast<Fn*>(*obj + 0x24);
                    fn();
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *reinterpret_cast<uint32_t*>(b + 0x14));
            }
        } else {
            uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(b + 0x1c);
            uint32_t* puVar6 = puVar1;
            for (; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + 1;
            }
            puVar5 = *reinterpret_cast<uint32_t**>(b + 0x18);
            puVar6 = puVar2;
            for (uVar3 = *reinterpret_cast<uint32_t*>(b + 0x14) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + 1;
            }
            for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *reinterpret_cast<uint8_t*>(puVar6) = *reinterpret_cast<uint8_t*>(puVar5);
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar5) + 1);
                puVar6 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar6) + 1);
            }
            puVar5 = puVar1 + *reinterpret_cast<int*>(b + 0x14);
            for (uVar3 = (param_1 - *reinterpret_cast<uint32_t*>(b + 0x14)) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar5 = 0;
                puVar5 = puVar5 + 1;
            }
            for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *reinterpret_cast<uint8_t*>(puVar5) = 0;
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar5) + 1);
            }
            puVar5 = puVar2 + *reinterpret_cast<int*>(b + 0x14);
            for (uVar3 = (param_1 - *reinterpret_cast<uint32_t*>(b + 0x14)) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar5 = 0;
                puVar5 = puVar5 + 1;
            }
            for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                *reinterpret_cast<uint8_t*>(puVar5) = 0;
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar5) + 1);
            }
        }
        operator_delete__(*reinterpret_cast<void**>(b + 0x1c));
        operator_delete__(*reinterpret_cast<void**>(b + 0x18));
        *reinterpret_cast<uint32_t**>(b + 0x1c) = puVar1;
        *reinterpret_cast<uint32_t**>(b + 0x18) = puVar2;
        *reinterpret_cast<uint32_t*>(b + 0x14) = param_1;
    }
}

// 0x5d0790 — observed shape
uint32_t FUN_005d0790(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(b + 0x14);
    if (uVar1 == 0) {
        return 0;
    }
    uint32_t uVar3 = 0;
    if (uVar1 != 0) {
        int* piVar2 = *reinterpret_cast<int**>(b + 0x1c);
        do {
            if ((*piVar2 == 0) || (*reinterpret_cast<int*>(*piVar2 + 8) == 0)) {
                return 0;
            }
            uVar3 = uVar3 + 1;
            piVar2 = piVar2 + 1;
        } while (uVar3 < uVar1);
    }
    return 1;
}

// 0x5d0850 — observed shape
int* FUN_005d0850(void* self, int param_1, int* param_2, int* param_3,
                  uint32_t* param_4, uint32_t* param_5, int param_6)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    int iVar3 = param_6;
    uint32_t* puVar7 = param_5;
    int* piVar6 = param_3;
    int* piVar1 = param_2;
    int local_14 = 0;
    uint32_t* local_10 = nullptr;
    int local_c = 0;
    uint32_t* local_8 = nullptr;
    uint32_t local_4 = 0;
    if ((*reinterpret_cast<int*>(b + 8) == 0) || (param_1 == 0)) {
        return nullptr;
    }
    uint32_t uVar5 = static_cast<uint32_t>(static_cast<int>(reinterpret_cast<intptr_t>(param_2)) * 2);
    if (param_3 != nullptr) {
        local_14 = 0;
        local_10 = nullptr;
        local_c = 0;
        local_8 = nullptr;
        local_4 = 0;
        using Fn = int (*)(int*, int*);
        Fn fn = *reinterpret_cast<Fn*>(*param_3 + 0x34);
        int iVar2 = fn(param_3, &local_14);
        if ((((-1 < iVar2) && (local_14 == 0x65)) &&
             (local_10 == reinterpret_cast<uint32_t*>(0x7))) &&
            (((local_c == iVar3 && (local_8 == puVar7)) && (uVar5 <= local_4)))) {
            goto LAB_005d092d;
        }
    }
    param_2 = nullptr;
    {
        int* devObj = *reinterpret_cast<int**>(b + 8);
        using Fn = int (*)(int*, uint32_t, int, int, uint32_t*, int**, int);
        Fn fn = *reinterpret_cast<Fn*>(*devObj + 0x6c);
        iVar3 = fn(devObj, uVar5, iVar3, 0x65, puVar7, &param_2, 0);
    }
    if (iVar3 < 0) {
        FUN_00497420("NiDX9IndexBufferManager::CreateIndexBuffer FAILED");
        param_2 = nullptr;
    }
    if (param_2 == nullptr) {
        FUN_00497420("NiDX9IndexBufferManager::PackBuffer> Failed to create index buffer\n");
        return nullptr;
    }
    *param_4 = uVar5;
    piVar6 = param_2;
LAB_005d092d:
    param_3 = nullptr;
    {
        using Fn = int (*)(int*, int, uint32_t, int**, int);
        Fn fn = *reinterpret_cast<Fn*>(*piVar6 + 0x2c);
        iVar3 = fn(piVar6, 0, uVar5, &param_3, 0);
    }
    if (iVar3 < 0) {
        FUN_00497420("NiDX9IndexBufferManager::PackBuffer> Failed to lock index buffer\n");
        {
            using Fn = void (*)(int*);
            Fn fn = *reinterpret_cast<Fn*>(*piVar6 + 0x30);
            fn(piVar6);
        }
        {
            using Fn = void (*)(int*);
            Fn fn = *reinterpret_cast<Fn*>(*piVar6 + 8);
            fn(piVar6);
        }
        return piVar6;
    }
    puVar7 = local_10;
    uint32_t* puVar8 = local_8;
    for (uint32_t uVar4 = (static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar1)) & 0x7fffffffu) >> 1;
         uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *reinterpret_cast<uint8_t*>(puVar8) = *reinterpret_cast<uint8_t*>(puVar7);
        puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar7) + 1);
        puVar8 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar8) + 1);
    }
    {
        using Fn = void (*)(int*);
        Fn fn = *reinterpret_cast<Fn*>(*piVar6 + 0x30);
        fn(piVar6);
    }
    return piVar6;
}
