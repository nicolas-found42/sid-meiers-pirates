#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005ccdd0(uint32_t param_1, uint32_t param_2);
extern void FUN_005cce50(void);
extern void FUN_005ce8a0(int param_1, int param_2, int param_3);
extern int FUN_005d8450(int param_1);
extern void FUN_00497420(const char* fmt, ...);
extern int FUN_0054aad0(void);
extern void* PTR_FUN_006c7fb8;

// 0x5ce9c0 — observed shape
bool FUN_005ce9c0(void* self, uint32_t* param_1)
{
    bool bVar3 = false;
    if (param_1 != nullptr) {
        bVar3 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(self) + 0x58) != static_cast<int32_t>(param_1[5]);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x58) = param_1[5];
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(static_cast<uint8_t*>(self) + 0x54);
        if (puVar2 != param_1) {
            if (puVar2 != param_1) {
                if (puVar2 != nullptr) {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        using Fn = void(__cdecl*)(int);
                        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
                        fn(1);
                    }
                }
                *reinterpret_cast<uint32_t**>(static_cast<uint8_t*>(self) + 0x54) = param_1;
                param_1[1] = param_1[1] + 1;
            }
            bVar3 = true;
        }
    }
    return bVar3;
}

// 0x5cea10 — observed shape
void FUN_005cea10(void* self, uint32_t param_1, uint32_t param_2)
{
    FUN_005ccdd0(param_1, param_2);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c7fb8;
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    in_ECX[0x15] = 0;
    in_ECX[0x18] = 0;
    in_ECX[0x19] = 0;
    in_ECX[0x16] = 0;
    *reinterpret_cast<uint8_t*>(in_ECX + 0x13) = 0;
    in_ECX[0x14] = 0;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x15]);
    if (puVar2 != nullptr) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
            fn(1);
        }
        in_ECX[0x15] = 0;
    }
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x17] = 0;
}

// 0x5cea90 — observed shape
void FUN_005cea90(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    int32_t* piVar1 = reinterpret_cast<int32_t*>(in_ECX[0x18]);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c7fb8;
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        in_ECX[0x18] = 0;
    }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x15]);
    if (puVar2 != nullptr) {
        int32_t* piVar1b = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1b = *piVar1b + -1;
        if (*piVar1b == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
            fn(1);
        }
    }
    FUN_005cce50();
}

// 0x5cead0 — observed shape
void FUN_005cead0(void* self, int param_1)
{
    int iVar1 = param_1;
    int iVar2 = *reinterpret_cast<int*>(param_1 + 0x44);
    *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x48) = iVar2;
    uint32_t uVar4 = 0;
    int unaff_ESI = 0;
    if (iVar2 != *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x5c)) {
        int* obj = *reinterpret_cast<int**>(static_cast<uint8_t*>(self) + 0x60);
        void** vtbl = *reinterpret_cast<void***>(obj);
        using Fn = int(__cdecl*)(int*, uint32_t, int*);
        Fn fn = reinterpret_cast<Fn>(reinterpret_cast<uint8_t*>(vtbl) + 0x48);
        while ((iVar2 = fn(obj, uVar4, &param_1), -1 < iVar2)) {
            FUN_005ce8a0(iVar1, *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x5c) + static_cast<int>(uVar4), unaff_ESI);
            using Fn2 = void(__cdecl*)(int);
            Fn2 fn2 = reinterpret_cast<Fn2>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(unaff_ESI)) + 8));
            fn2(unaff_ESI);
            uVar4 = uVar4 + 1;
            if ((uint32_t)(*reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x48) - *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x5c)) <= uVar4) {
                return;
            }
        }
        uint32_t uVar3 = static_cast<uint32_t>(FUN_005d8450(iVar2));
        FUN_00497420("NiDX9SourceTextureData::CopyDataToSurface> Failed GetSurfaceLevel (%d)- %s", uVar4, reinterpret_cast<const char*>(uVar3));
        using Fn3 = void(__cdecl*)(int*);
        Fn3 fn3 = reinterpret_cast<Fn3>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(obj)) + 8));
        fn3(obj);
    }
}

// 0x5ceb60 — observed shape
void FUN_005ceb60(void* self)
{
    int iVar1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 4) + 0x40);
    if (iVar1 != 0) {
        uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(iVar1 + 0x30);
        bool bVar5 = false;
        if (puVar4 != nullptr) {
            bVar5 = *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x58) != static_cast<int>(puVar4[5]);
            *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x58) = puVar4[5];
            uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(static_cast<uint8_t*>(self) + 0x54);
            if (puVar2 != puVar4) {
                if (puVar2 != puVar4) {
                    if (puVar2 != nullptr) {
                        int32_t* piVar3 = reinterpret_cast<int32_t*>(puVar2 + 1);
                        *piVar3 = *piVar3 + -1;
                        if (*piVar3 == 0) {
                            using Fn = void(__cdecl*)(int);
                            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
                            fn(1);
                        }
                    }
                    *reinterpret_cast<uint32_t**>(static_cast<uint8_t*>(self) + 0x54) = puVar4;
                    puVar4[1] = puVar4[1] + 1;
                }
                bVar5 = true;
            }
        }
        if ((*reinterpret_cast<int*>(iVar1 + 0x4c) != *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 100)) || bVar5) {
            int32_t* piVar3 = reinterpret_cast<int32_t*>(FUN_0054aad0());
            using Fn = uint32_t*(__cdecl*)(int, void*, int, uint8_t);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar3)) + 0x10));
            puVar4 = fn(iVar1, static_cast<uint8_t*>(self) + 0xc, iVar1, *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(self) + 0x4c));
            *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 100) = *reinterpret_cast<uint32_t*>(iVar1 + 0x4c);
            if (*reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 4) != 0) {
                FUN_005cead0(self, static_cast<int>(reinterpret_cast<intptr_t>(puVar4)));
            }
            if (puVar4 != nullptr) {
                int32_t iVar1b = static_cast<int32_t>(puVar4[1]);
                puVar4[1] = static_cast<uint32_t>(iVar1b + 1);
                puVar4[1] = static_cast<uint32_t>(iVar1b);
                if (iVar1b == 0) {
                    using Fn2 = void(__cdecl*)(int);
                    Fn2 fn2 = reinterpret_cast<Fn2>(*reinterpret_cast<void**>(puVar4));
                    fn2(1);
                }
            }
        }
    }
}

extern uint32_t FUN_005d1960(void* param_1, uint32_t param_2);
extern uint32_t FUN_00533c78(size_t size);
extern uint32_t FUN_0054c9c0(uint32_t param_1, uint32_t param_2);
extern void* FUN_005cce60(void* param_1, void* param_2, void* param_3);
extern void FUN_005ce800(uint32_t* param_1);
extern char DAT_0072799c;
extern void* DAT_00727d70;

// 0x5cec10 — observed shape
int FUN_005cec10(int32_t* param_1, int32_t param_2)
{
    int32_t* piVar8 = param_1;
    int32_t iVar5 = 0;
    if (param_1 != nullptr) {
        uint32_t* puVar4 = nullptr;
        {
            using Fn = uint32_t*(__cdecl*)(int32_t*);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 4));
            puVar4 = fn(param_1);
        }
        for (; puVar4 != nullptr;) {
            if (puVar4 == reinterpret_cast<uint32_t*>(&DAT_00727d70)) {
                return static_cast<int>(FUN_005d1960(param_1, static_cast<uint32_t>(param_2)));
            }
            puVar4 = reinterpret_cast<uint32_t*>(puVar4[1]);
        }
    }
    iVar5 = static_cast<int32_t>(FUN_00533c78(0x68));
    if (iVar5 == 0) {
        iVar5 = 0;
    } else {
        FUN_005cea10(param_1, static_cast<uint32_t>(param_2));
    }
    int32_t iVar7 = param_1[0x10];
    if (iVar7 == 0) {
        iVar7 = param_1[0xf];
        int32_t* piVar6 = reinterpret_cast<int32_t*>(FUN_0054aad0());
        using Fn = int32_t(__cdecl*)(int32_t, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar6)) + 8));
        iVar7 = fn(iVar7, 0);
    }
    if (iVar7 == 0) {
        iVar7 = static_cast<int32_t>(FUN_0054c9c0(0x80000005, 1));
    } else {
        *reinterpret_cast<int*>(iVar7 + 4) = *reinterpret_cast<int*>(iVar7 + 4) + 1;
        uint32_t uVar1 = **reinterpret_cast<uint32_t**>(iVar7 + 0x38);
        if ((((uVar1 == 0) || ((uVar1 - 1u & uVar1) != 0)) || (uVar1 = **reinterpret_cast<uint32_t**>(iVar7 + 0x3c), uVar1 == 0)) || ((uVar1 - 1u & uVar1) != 0)) {
            iVar7 = static_cast<int32_t>(FUN_0054c9c0(0x80000006, 1));
        } else {
            void* r = FUN_005cce60(reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(iVar7))) + 0xc, param_1 + 8, reinterpret_cast<uint8_t*>(reinterpret_cast<void*>(static_cast<intptr_t>(param_2))) + 0x468);
            if (r == nullptr) {
                iVar7 = static_cast<int32_t>(FUN_0054c9c0(0x80000004, 1));
            }
        }
    }
    *reinterpret_cast<uint32_t*>(iVar5 + 100) = *reinterpret_cast<uint32_t*>(iVar7 + 0x4c);
    *reinterpret_cast<int*>(iVar5 + 0x34) = param_1[10];
    uint32_t* puVar4b = reinterpret_cast<uint32_t*>(param_1);
    uint32_t* puVar10 = reinterpret_cast<uint32_t*>(iVar5 + 0xc);
    for (int iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar10 = *puVar4b;
        puVar4b = puVar4b + 1;
        puVar10 = puVar10 + 1;
    }
    *reinterpret_cast<uint32_t*>(iVar5 + 0x40) = **reinterpret_cast<uint32_t**>(iVar7 + 0x38);
    *reinterpret_cast<uint32_t*>(iVar5 + 0x44) = **reinterpret_cast<uint32_t**>(iVar7 + 0x3c);
    uint8_t uVar3 = 0;
    if ((piVar8[9] == 1) || ((piVar8[9] == 2 && DAT_0072799c != '\0'))) {
        uVar3 = 1;
    } else {
        uVar3 = 0;
    }
    *reinterpret_cast<uint8_t*>(iVar5 + 0x4c) = uVar3;
    piVar8 = reinterpret_cast<int32_t*>(FUN_0054aad0());
    uint32_t* puVar10b = nullptr;
    {
        using Fn = uint32_t*(__cdecl*)(int, void*, int, uint8_t);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar8)) + 0x10));
        puVar10b = fn(iVar7, param_1, iVar7, *reinterpret_cast<uint8_t*>(iVar5 + 0x4c));
    }
    if ((*reinterpret_cast<int*>(iVar5 + 0x60) != 0) || (FUN_005ce800(puVar10b), *reinterpret_cast<int*>(iVar5 + 0x60) != 0)) {
        FUN_005cead0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar5)), static_cast<int>(reinterpret_cast<intptr_t>(puVar10b)));
    }
    uint32_t* puVar10c = *reinterpret_cast<uint32_t**>(iVar7 + 0x30);
    if (puVar10c != nullptr) {
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(iVar5 + 0x54);
        *reinterpret_cast<uint32_t*>(iVar5 + 0x58) = puVar10c[5];
        if ((puVar2 != puVar10c) && (puVar2 != puVar10c)) {
            if (puVar2 != nullptr) {
                int32_t* piVar8b = reinterpret_cast<int32_t*>(puVar2 + 1);
                *piVar8b = *piVar8b + -1;
                if (*piVar8b == 0) {
                    using Fn = void(__cdecl*)(int);
                    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
                    fn(1);
                }
            }
            *reinterpret_cast<uint32_t**>(iVar5 + 0x54) = puVar10c;
            puVar10c[1] = puVar10c[1] + 1;
        }
    }
    *reinterpret_cast<uint32_t*>(iVar5 + 0x50) = *reinterpret_cast<uint32_t*>(puVar10b[0x10] + puVar10b[0x11] * 4);
    puVar10b[1] = puVar10b[1] + 1;
    *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar5 + 4) + 0x2c) = iVar5;
    int32_t* piVar8c = reinterpret_cast<int32_t*>(puVar10b + 1);
    *piVar8c = *piVar8c + -1;
    if (*piVar8c == 0) {
        using Fn = void(__cdecl*)(int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar10b));
        fn(1);
    }
    return iVar5;
}

extern void FUN_005387b0(int param_1, int param_2);
extern void FUN_005389d0(int param_1, int param_2, int param_3, int param_4, int param_5);
extern void FUN_00538830(void);
extern void FUN_00538b80(int param_1, int param_2, int param_3, int param_4);

// 0x5ceeb0 — observed shape
void FUN_005ceeb0(void* self, int param_1)
{
    *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x28) = param_1;
    *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x24) = 0;
    uint32_t uVar1 = 0;
    if (param_1 < 0x2a) {
        if (param_1 == 0x29) {
            FUN_005387b0(0, 8);
            return;
        }
        switch (param_1) {
        case 0x14:
        case 0x16:
            uVar1 = 0;
            goto LAB_005ceee4;
        case 0x17:
            FUN_005389d0(0xf800, 0x7e0, 0x1f, 0, 0x10);
            return;
        case 0x18:
            FUN_005389d0(0x7c00, 0x3e0, 0x1f, 0, 0x10);
            return;
        case 0x19:
            FUN_005389d0(0x7c00, 0x3e0, 0x1f, 0x8000, 0x10);
            return;
        case 0x1a:
            FUN_005389d0(0xf00, 0xf0, 0xf, 0xf000, 0x10);
            return;
        }
    } else if (param_1 < 0x31545845) {
        if (param_1 == 0x31545844) {
            FUN_00538830();
            return;
        }
        if (param_1 == 0x3c) {
            FUN_00538b80(0xff, 0xff00, 0, 0x10);
            return;
        }
        if (param_1 == 0x3d) {
            FUN_00538b80(0x1f, 0x3e0, 0xfc00, 0x10);
            return;
        }
        if (param_1 == 0x3e) {
            FUN_00538b80(0xff, 0xff00, 0xff0000, 0x20);
            return;
        }
    } else {
        if (param_1 == 0x33545844) {
            FUN_00538830();
            return;
        }
        if (param_1 == 0x35545844) {
            FUN_00538830();
            return;
        }
    }
    uVar1 = 0xff000000;
LAB_005ceee4:
    FUN_005389d0(0xff0000, 0xff00, 0xff, static_cast<int>(uVar1), 0x20);
}

extern int32_t DAT_00728e8c;
extern int32_t DAT_00728e90;

// 0x5cf090 — observed shape
bool FUN_005cf090(void* self, int32_t* param_1)
{
    int iVar1 = *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0xc);
    if (iVar1 == 0) {
        return false;
    }
    int iVar2 = 0;
    if (iVar1 != DAT_00728e8c) {
        using Fn = int(__cdecl*)(int32_t*, int, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 0x94));
        iVar2 = fn(param_1, 0, iVar1);
        DAT_00728e8c = *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0xc);
        if (iVar2 < 0) {
            return false;
        }
    }
    if (*reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x10) != DAT_00728e90) {
        using Fn = int(__cdecl*)(int32_t*, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 0x9c));
        iVar2 = fn(param_1, *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x10));
        DAT_00728e90 = *reinterpret_cast<int*>(static_cast<uint8_t*>(self) + 0x10);
    }
    return -1 < iVar2;
}

// 0x5cf100 — observed shape
void FUN_005cf100(void* self)
{
    int32_t* piVar1 = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0x10);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x10) = 0;
    }
    piVar1 = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0xc);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0xc) = 0;
    }
    operator delete(*reinterpret_cast<void**>(static_cast<uint8_t*>(self) + 0x14));
    *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x14) = 0;
}

extern void* PTR_FUN_006c8040;
extern void* PTR_FUN_006c8034;

// 0x5cf140 — observed shape
void FUN_005cf140(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    int32_t* piVar1 = reinterpret_cast<int32_t*>(in_ECX[6]);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c8040;
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        in_ECX[6] = 0;
    }
    piVar1 = reinterpret_cast<int32_t*>(in_ECX[4]);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c8034;
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        in_ECX[4] = 0;
    }
    piVar1 = reinterpret_cast<int32_t*>(in_ECX[3]);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        in_ECX[3] = 0;
    }
    operator delete(reinterpret_cast<void*>(in_ECX[5]));
    in_ECX[5] = 0;
}

// 0x5cf1a0 — observed shape
void FUN_005cf1a0(void* self, uint8_t param_1)
{
    FUN_005cf140(self);
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x5cf1c0 — observed shape
void FUN_005cf1c0(void* self)
{
    int32_t* piVar1 = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0x18);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x18) = 0;
    }
    piVar1 = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0x10);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x10) = 0;
    }
    piVar1 = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0xc);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0xc) = 0;
    }
    operator delete(*reinterpret_cast<void**>(static_cast<uint8_t*>(self) + 0x14));
    *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x14) = 0;
}

extern void* PTR_FUN_006c804c;

// 0x5cf210 — observed shape
void FUN_005cf210(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    int32_t* piVar1 = reinterpret_cast<int32_t*>(in_ECX[0x14]);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c804c;
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        in_ECX[0x14] = 0;
    }
    piVar1 = reinterpret_cast<int32_t*>(in_ECX[4]);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c8034;
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        in_ECX[4] = 0;
    }
    piVar1 = reinterpret_cast<int32_t*>(in_ECX[3]);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        in_ECX[3] = 0;
    }
    operator delete(reinterpret_cast<void*>(in_ECX[5]));
    in_ECX[5] = 0;
}

// 0x5cf270 — observed shape
void FUN_005cf270(void* self)
{
    int32_t* piVar1 = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0x50);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x50) = 0;
    }
    piVar1 = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0x10);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x10) = 0;
    }
    piVar1 = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0xc);
    if (piVar1 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 8));
        fn(piVar1);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0xc) = 0;
    }
    operator delete(*reinterpret_cast<void**>(static_cast<uint8_t*>(self) + 0x14));
    *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x14) = 0;
}

extern void FUN_00513dc0(void);
extern uint32_t FUN_005cb9d0(int param_1);

// 0x5cf2c0 — observed shape
uint32_t* FUN_005cf2c0(int32_t* param_1)
{
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x1c));
    if (puVar2 == nullptr) {
        puVar2 = nullptr;
    } else {
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        *reinterpret_cast<void**>(puVar2) = &PTR_FUN_006c8040;
        puVar2[6] = 0;
    }
    puVar2[6] = reinterpret_cast<uint32_t>(reinterpret_cast<intptr_t>(param_1));
    {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 4));
        fn(param_1);
    }
    uint8_t auStack_1e[6] = {};
    int iVar3 = 0;
    {
        using Fn = int(__cdecl*)(int32_t*, int, uint32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 0x48));
        iVar3 = fn(param_1, 0, puVar2 + 3);
    }
    if (iVar3 < 0) {
        uint32_t uVar4 = FUN_005d8450(iVar3);
        FUN_00497420("NiDX9Renderer::CreateRenderedTextureRendererData> FAILED- GetSurfaceLevel - %s", reinterpret_cast<const char*>(uVar4));
    } else {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2[3]);
        {
            using Fn = int(__cdecl*)(int32_t*, void*);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 0x30));
            iVar3 = fn(piVar1, auStack_1e + -0x12);
        }
        if (-1 < iVar3) {
            uint32_t uStack_18 = 0;
            uint32_t uStack_14 = 0;
            uint32_t uStack_8 = 0;
            int32_t* piStack_4 = nullptr;
            iVar3 = static_cast<int>(FUN_00533c78(0x2c));
            if (iVar3 == 0) {
                iVar3 = 0;
            } else {
                FUN_00513dc0();
                FUN_005ceeb0(puVar2, 0);
            }
            puVar2[5] = static_cast<uint32_t>(iVar3);
            puVar2[1] = uStack_18;
            puVar2[2] = uStack_14;
            uint32_t uVar4b = FUN_005cb9d0(0);
            FUN_00497420("NiDX9Renderer::Recreate> Using %s backbuffer format\n", reinterpret_cast<const char*>(uVar4b));
            if (piStack_4 != nullptr) {
                using Fn = void(__cdecl*)(int32_t*, uint32_t, uint32_t, uint32_t, int, int, int, uint32_t*, int);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piStack_4)) + 0x74));
                fn(piStack_4, uStack_18, uStack_14, uStack_8, 0, 0, 1, puVar2 + 4, 0);
            }
            return puVar2;
        }
    }
    {
        using Fn = void(__cdecl*)(int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
        fn(1);
    }
    return nullptr;
}

// 0x5cf3d0 — observed shape
uint32_t* FUN_005cf3d0(int32_t* param_1)
{
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x1c));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        *reinterpret_cast<void**>(puVar3) = &PTR_FUN_006c8040;
        puVar3[6] = 0;
    }
    puVar3[6] = reinterpret_cast<uint32_t>(reinterpret_cast<intptr_t>(param_1));
    {
        using Fn = void(__cdecl*)();
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 4));
        fn();
    }
    uint32_t* puVar1 = puVar3 + 3;
    int iVar4 = 0;
    {
        using Fn = int(__cdecl*)(int32_t*, int32_t*, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(reinterpret_cast<int32_t*>(puVar3[6]))) + 0x48));
        iVar4 = fn(reinterpret_cast<int32_t*>(puVar3[6]), param_1, 0);
    }
    uint32_t uStack_1c = 0;
    uint32_t uStack_18 = 0;
    int iStack_8 = 0;
    int32_t* piStack_4 = reinterpret_cast<int32_t*>(FUN_0054aad0());
    if (iVar4 < 0) {
        uint32_t uVar5 = FUN_005d8450(iVar4);
        FUN_00497420("NiDX9Renderer::CreateRenderedTextureRendererData> FAILED- GetSurfaceLevel - %s", reinterpret_cast<const char*>(uVar5));
        *puVar1 = 0;
    } else {
        {
            using Fn = int(__cdecl*)(int32_t*, void*);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(reinterpret_cast<int32_t*>(*puVar1))) + 0x30));
            iVar4 = fn(reinterpret_cast<int32_t*>(*puVar1), &uStack_1c);
        }
        if (-1 < iVar4) {
            puVar3[1] = uStack_1c;
            puVar3[2] = uStack_18;
            iVar4 = static_cast<int>(FUN_00533c78(0x2c));
            if (iVar4 == 0) {
                iVar4 = 0;
            } else {
                FUN_00513dc0();
                FUN_005ceeb0(puVar3, 0);
            }
            puVar3[5] = static_cast<uint32_t>(iVar4);
            if (iStack_8 == 0) {
                using Fn = void(__cdecl*)(int32_t*, uint32_t, uint32_t, int, int, int, int, uint32_t*, int);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piStack_4)) + 0x74));
                fn(piStack_4, puVar3[1], puVar3[2], 0x50, 0, 0, 1, puVar3 + 4, 0);
                return puVar3;
            }
            int32_t* piVar2 = *reinterpret_cast<int32_t**>(iStack_8 + 0x10);
            if (piVar2 == nullptr) {
                using Fn = void(__cdecl*)(int32_t*, uint32_t, uint32_t, int, int, int, int, uint32_t*, int);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piStack_4)) + 0x74));
                fn(piStack_4, puVar3[1], puVar3[2], 0x50, 0, 0, 1, puVar3 + 4, 0);
                return puVar3;
            }
            puVar3[4] = reinterpret_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar2));
            {
                using Fn = void(__cdecl*)(int32_t*);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar2)) + 4));
                fn(piVar2);
            }
            return puVar3;
        }
    }
    {
        using Fn = void(__cdecl*)(int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar3));
        fn(1);
    }
    return nullptr;
}

// 0x5cf4f0 — observed shape
void FUN_005cf4f0(void* self, uint8_t param_1)
{
    FUN_005cf210(self);
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x5cf510 — observed shape
uint32_t* FUN_005cf510(int32_t* param_1, uint32_t* param_2)
{
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x54));
    if (puVar2 == nullptr) {
        puVar2 = nullptr;
    } else {
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        *reinterpret_cast<void**>(puVar2) = &PTR_FUN_006c804c;
        puVar2[0x14] = 0;
    }
    uint32_t* puVar5 = puVar2 + 6;
    for (int iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = *param_2;
        param_2 = param_2 + 1;
        puVar5 = puVar5 + 1;
    }
    puVar2[0x14] = reinterpret_cast<uint32_t>(reinterpret_cast<intptr_t>(param_1));
    {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 4));
        fn(param_1);
    }
    uint8_t auStack_1e[6] = {};
    uint32_t uStack_18 = 0;
    uint32_t uStack_14 = 0;
    int iVar4b = 0;
    {
        using Fn = int(__cdecl*)(int32_t*, int, uint32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 0x98));
        iVar4b = fn(param_1, 0, puVar2 + 3);
    }
    if (-1 < iVar4b) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2[3]);
        {
            using Fn = int(__cdecl*)(int32_t*, void*);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar1)) + 0x30));
            iVar4b = fn(piVar1, auStack_1e + -0x12);
        }
        if (-1 < iVar4b) {
            puVar2[1] = uStack_18;
            puVar2[2] = uStack_14;
            iVar4b = static_cast<int>(FUN_00533c78(0x2c));
            if (iVar4b == 0) {
                iVar4b = 0;
            } else {
                FUN_00513dc0();
                FUN_005ceeb0(puVar2, 0);
            }
            puVar2[5] = static_cast<uint32_t>(iVar4b);
            uint32_t uVar3 = FUN_005cb9d0(0);
            FUN_00497420("NiDX9Renderer::Create> Using %s backbuffer format\n", reinterpret_cast<const char*>(uVar3));
            {
                using Fn = void(__cdecl*)(int32_t*, uint32_t*);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 0xa0));
                fn(param_1, puVar2 + 4);
            }
            uVar3 = FUN_005cb9d0(static_cast<int>(puVar2[0x10]));
            FUN_00497420("NiDX9Renderer::Create> Using %s depth/stencil format\n", reinterpret_cast<const char*>(uVar3));
            return puVar2;
        }
    }
    {
        using Fn = void(__cdecl*)(int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(puVar2));
        fn(1);
    }
    return nullptr;
}

// 0x5cf620 — observed shape
uint32_t FUN_005cf620(void* self, int32_t* param_1)
{
    int32_t* in_ECX = static_cast<int32_t*>(self);
    int32_t* piVar4 = in_ECX + 3;
    if (in_ECX[3] != 0) {
        using Fn = void(__cdecl*)();
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(in_ECX)) + 0xc));
        fn();
    }
    DAT_00728e8c = 0;
    DAT_00728e90 = 0;
    int32_t* piVar3 = reinterpret_cast<int32_t*>(in_ECX[0x14]);
    if (piVar3 != nullptr) {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar3)) + 8));
        fn(piVar3);
        in_ECX[0x14] = 0;
    }
    in_ECX[0x14] = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_1));
    {
        using Fn = void(__cdecl*)(int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 4));
        fn(param_1);
    }
    int32_t* piVar4b = piVar4;
    uint32_t uStack_20 = 0;
    int32_t iStack_1c = 0;
    int iVar1 = 0;
    {
        using Fn = int(__cdecl*)(int32_t*, int, int32_t*);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(reinterpret_cast<int32_t*>(in_ECX[0x14]))) + 0x98));
        iVar1 = fn(reinterpret_cast<int32_t*>(in_ECX[0x14]), 0, piVar4);
    }
    if (-1 < iVar1) {
        {
            using Fn = int(__cdecl*)(int32_t*, intptr_t);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(piVar4)) + 0x30));
            iVar1 = fn(reinterpret_cast<int32_t*>(*piVar4), static_cast<intptr_t>(reinterpret_cast<void*>(piVar4)) + -0x30);
        }
        if (-1 < iVar1) {
            in_ECX[1] = static_cast<int32_t>(uStack_20);
            in_ECX[2] = iStack_1c;
            iVar1 = static_cast<int>(FUN_00533c78(0x2c));
            if (iVar1 == 0) {
                iVar1 = 0;
            } else {
                int32_t* piVar3b = piVar3;
                FUN_00513dc0();
                FUN_005ceeb0(piVar3b, static_cast<int>(reinterpret_cast<intptr_t>(piVar4b)));
                piVar3 = piVar4b;
            }
            in_ECX[5] = iVar1;
            uint32_t uVar2 = FUN_005cb9d0(static_cast<int>(reinterpret_cast<intptr_t>(piVar3)));
            FUN_00497420("NiDX9Renderer::Recreate> Using %s backbuffer format\n", reinterpret_cast<const char*>(uVar2));
            {
                using Fn = void(__cdecl*)(int32_t*, int32_t*);
                Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(param_1)) + 0xa0));
                fn(param_1, in_ECX + 4);
            }
            if (in_ECX[4] != 0) {
                uVar2 = FUN_005cb9d0(in_ECX[0x10]);
                FUN_00497420("NiDX9Renderer::Recreate> Using %s depth/stencil format\n", reinterpret_cast<const char*>(uVar2));
            }
            return 1;
        }
        {
            using Fn = void(__cdecl*)(int32_t*);
            Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(reinterpret_cast<int32_t*>(*piVar4))) + 8));
            fn(reinterpret_cast<int32_t*>(*piVar4));
        }
        *piVar4 = 0;
    }
    return 0;
}

// 0x5cf730 — observed shape
void FUN_005cf730(void* self)
{
    int32_t* obj = *reinterpret_cast<int32_t**>(static_cast<uint8_t*>(self) + 0x2c);
    {
        using Fn = void(__cdecl*)(int, int, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(obj)) + 0x70));
        fn(0x8b, 0, 0);
    }
    {
        using Fn = void(__cdecl*)(int, int, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(obj)) + 0x70));
        fn(0x89, 0, 0);
    }
    *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x38) = 0;
    *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(self) + 0x3c) = 0;
    *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x40) = 0;
    {
        using Fn = void(__cdecl*)(int, int, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(obj)) + 0x70));
        fn(0x94, 0, 0);
    }
    {
        using Fn = void(__cdecl*)(int, int, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(obj)) + 0x70));
        fn(0x93, 0, 0);
    }
    {
        using Fn = void(__cdecl*)(int, int, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(*reinterpret_cast<void**>(obj)) + 0x70));
        fn(0x91, 0, 0);
    }
    *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x30) = 0;
    *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(self) + 0x34) = 0;
}
