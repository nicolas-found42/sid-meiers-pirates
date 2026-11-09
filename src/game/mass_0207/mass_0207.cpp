#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef unsigned int uint;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern uint FUN_005bbd90(int param_1);
extern void FUN_005bbf20();
extern void FUN_00545cc0();
extern void FUN_005bbf80();
extern void FUN_005bbfe0(int param_1);
extern int FUN_00557b10(void* param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint param_1, int* param_2);
extern int FUN_00557d80(const char* param_1, void* param_2);
extern int FUN_00557cf0(const char* param_1, uint32_t param_2);
extern int FUN_00557b50(const char* param_1, undefined1 param_2);
extern uint8_t DAT_00728cc8;
extern uint8_t DAT_0070c39c;

// 0x5bc150 — observed shape
uint FUN_005bc150(void* self, int param_1)
{
    uint uVar3;
    uVar3 = FUN_005bbd90(param_1);
    if ((char)uVar3 == '\0') {
        return uVar3 & 0xffffff00U;
    }
    uVar3 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(self) + 0x1c);
    if (uVar3 == 0) {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x1c) != 0) {
            return uVar3 & 0xffffff00U;
        }
        uVar3 = 0;
    }
    else {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x1c) == 0) {
            return uVar3 & 0xffffff00U;
        }
        uVar3 = 0;
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x1c) != 0) {
            void* vt = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x1c);
            typedef uint (__cdecl* EqualFn)(int);
            EqualFn fn = *reinterpret_cast<EqualFn*>(reinterpret_cast<char*>(vt) + 0x1c);
            uVar3 = fn(*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x1c));
            if ((char)uVar3 == '\0') {
                return uVar3 & 0xffffff00U;
            }
        }
    }
    float fVar1 = *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x20);
    float fVar2 = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_1) + 0x20);
    unsigned short uVar4 = static_cast<unsigned short>(uVar3 >> 0x10);
    uint combined = (uint)uVar4 << 16;
    if (fVar2 < fVar1) combined |= 0x100U;
    if ((fVar2 != fVar2) || (fVar1 != fVar1)) combined |= 0x400U;
    if (fVar2 == fVar1) combined |= 0x4000U;
    uVar3 = combined;
    if (fVar2 == fVar1) {
        float gVar1 = *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x24);
        float gVar2 = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_1) + 0x24);
        uint combined2 = (uint)uVar4 << 16;
        if (gVar2 < gVar1) combined2 |= 0x100U;
        if ((gVar2 != gVar2) || (gVar1 != gVar1)) combined2 |= 0x400U;
        if (gVar2 == gVar1) combined2 |= 0x4000U;
        uVar3 = combined2;
        if ((gVar2 == gVar1) &&
            (*reinterpret_cast<char*>(reinterpret_cast<char*>(param_1) + 0x28) ==
             *reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x28))) {
            uVar3 = (uVar3 & 0xffffff00U) | (uint)(unsigned char)*reinterpret_cast<char*>(reinterpret_cast<char*>(param_1) + 0x28);
            float hVar1 = *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x2c);
            float hVar2 = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_1) + 0x2c);
            uint combined3 = (uint)uVar4 << 16;
            if (hVar2 < hVar1) combined3 |= 0x100U;
            if ((hVar2 != hVar2) || (hVar1 != hVar1)) combined3 |= 0x400U;
            if (hVar2 == hVar1) combined3 |= 0x4000U;
            uVar3 = combined3;
            if (hVar2 == hVar1) {
                return (uVar3 & 0xffffff00U) | 1U;
            }
        }
    }
    return uVar3 & 0xffffff00U;
}

// 0x5bc1f0 — observed shape
void FUN_005bc1f0(void* self, int param_1)
{
    int iStack_c = param_1;
    FUN_005bbf20();
    iStack_c = 0x5bc205;
    FUN_00545cc0();
    iStack_c = 4;
    void* vt = *reinterpret_cast<void**>(param_1 + 0x15c);
    typedef void (__cdecl* ReadFn)(void*, ...);
    ReadFn fn = *reinterpret_cast<ReadFn*>(reinterpret_cast<char*>(vt) + 8);
    fn(reinterpret_cast<char*>(self) + 0x20);
    fn(reinterpret_cast<char*>(self) + 0x24);
    fn(&iStack_c, 1);
    *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(self) + 0x28) = 1;
    fn(reinterpret_cast<char*>(self) + 0x2c, 4);
    float fVar1 = *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x2c);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x30) = fVar1 * fVar1;
    return;
}

// 0x5bc270 — observed shape
void FUN_005bc270(void* self, int* param_1)
{
    int iStack_c = reinterpret_cast<int>(param_1);
    (void)iStack_c;
    FUN_005bbf80();
    void* vt0 = *reinterpret_cast<void**>(param_1);
    typedef void (__cdecl* NoArgFn)();
    NoArgFn fn0 = *reinterpret_cast<NoArgFn*>(reinterpret_cast<char*>(vt0) + 0x2c);
    vt0 = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x1c);
    (void)vt0;
    fn0();
    void* vt = *reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x58));
    typedef void (__cdecl* ReadFn)(void*, ...);
    ReadFn fn = *reinterpret_cast<ReadFn*>(reinterpret_cast<char*>(vt) + 0xc);
    fn(reinterpret_cast<char*>(self) + 0x20);
    fn(reinterpret_cast<char*>(self) + 0x24, 4);
    int temp = 4;
    temp = (temp & 0xffffff00) | *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(self) + 0x28);
    fn(&temp, 1);
    fn(reinterpret_cast<char*>(self) + 0x2c, 4);
    return;
}

// 0x5bc2e0 — observed shape
void FUN_005bc2e0(void* self, int param_1)
{
    int iVar2 = param_1;
    FUN_005bbfe0(param_1);
    int localParam = FUN_00557b10(&DAT_00728cc8);
    uint uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    void* puVar3;
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x1c) == 0) {
        puVar3 = &DAT_0070c39c;
    }
    else {
        puVar3 = *reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x1c) + 0xc);
    }
    localParam = FUN_00557d80("Field Object", puVar3);
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    localParam = FUN_00557cf0("Magnitude", *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20));
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    localParam = FUN_00557cf0("Attenuation", *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x24));
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    localParam = FUN_00557b50("Use Max Distance", *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(self) + 0x28));
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    localParam = FUN_00557cf0("Max Distance", *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x2c));
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    return;
}

// 0x5bc460 — observed shape
int FUN_005bc460(void* self, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
{
    void* inner = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c);
    if (inner == nullptr) {
        return 0;
    }
    typedef int (__cdecl* InvokeFn)(undefined4, undefined4, undefined4, undefined4);
    InvokeFn fn = *reinterpret_cast<InvokeFn*>(reinterpret_cast<char*>(inner) + 0x34);
    int iVar1 = fn(param_1, param_2, param_3, param_4);
    if (iVar1 == 0) {
        return 0;
    }
    return iVar1;
}
extern void FUN_00538410(int param_1, undefined4 param_2);
extern void FUN_00513ce0(undefined4 param_1);
extern char FUN_005bd960(int param_1, int* param_2);
extern undefined4 FUN_00545600();

// 0x5bc490 — observed shape
void FUN_005bc490(void* self, undefined4 param_1, int* param_2, uint param_3)
{
    undefined4* puVar1 = reinterpret_cast<undefined4*>(param_2[8] + (param_3 & 0xffff) * 0xc);
    *puVar1 = *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x18);
    puVar1[1] = *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x1c);
    puVar1[2] = *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x20);
    if ((*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x10) != '\0') &&
        (*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x14) != nullptr)) {
        void* vt = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x14);
        typedef void (__cdecl* SpawnFn)(undefined4, undefined4, uint, undefined4);
        SpawnFn fn = *reinterpret_cast<SpawnFn*>(reinterpret_cast<char*>(vt) + 0x44);
        fn(param_1, *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x24), param_3,
           *reinterpret_cast<undefined4*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x28) + 0x14));
    }
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x11) != '\0') {
        void* vt = *reinterpret_cast<void**>(param_2);
        typedef void (__cdecl* NotifyFn)(uint);
        NotifyFn fn = *reinterpret_cast<NotifyFn*>(reinterpret_cast<char*>(vt) + 0x40);
        fn(param_3);
    }
    return;
}

// 0x5bc500 — observed shape
void FUN_005bc500(void* self, int param_1, undefined4 param_2)
{
    FUN_00538410(param_1, param_2);
    *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(param_1) + 0xc) =
        *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0xc);
    *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(param_1) + 0x10) =
        *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(self) + 0x10);
    *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(param_1) + 0x11) =
        *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(self) + 0x11);
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c) != nullptr) {
        void* vt = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c);
        typedef undefined4* (__cdecl* CloneFn)(undefined4);
        CloneFn fn = *reinterpret_cast<CloneFn*>(reinterpret_cast<char*>(vt) + 8);
        undefined4* puVar3 = fn(param_2);
        undefined4* puVar2 = *reinterpret_cast<undefined4**>(reinterpret_cast<char*>(param_1) + 0x2c);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    typedef void (__cdecl* ReleaseFn)(int);
                    ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(puVar2);
                    rel(1);
                }
            }
            *reinterpret_cast<undefined4**>(reinterpret_cast<char*>(param_1) + 0x2c) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
    return;
}

// 0x5bc560 — observed shape
void FUN_005bc560(void* self, int param_1)
{
    int iVar1 = param_1;
    FUN_00513ce0(param_1);
    FUN_005bd960(reinterpret_cast<int>(self), &param_1);
    int iVar2 = param_1;
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14) != 0) {
        char cVar3 = FUN_005bd960(*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14), &param_1);
        if (cVar3 == '\0') {
            *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(iVar2) + 0x14) =
                *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x14);
        }
        else {
            *reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) = param_1;
        }
    }
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x28) != 0) {
        char cVar3 = FUN_005bd960(*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x28), &param_1);
        if (cVar3 == '\0') {
            *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(iVar2) + 0x28) =
                *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x28);
        }
        else {
            *reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x28) = param_1;
        }
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c) != nullptr) {
        void* vt = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c);
        typedef void (__cdecl* CopyFn)(int);
        CopyFn fn = *reinterpret_cast<CopyFn*>(reinterpret_cast<char*>(vt) + 0x28);
        fn(iVar1);
    }
    return;
}

// 0x5bc5f0 — observed shape
void FUN_005bc5f0(void* self, undefined4 param_1)
{
    FUN_00513ce0(param_1);
    undefined4 uVar3 = FUN_00545600();
    *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x14) = uVar3;
    uVar3 = FUN_00545600();
    *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x28) = uVar3;
    undefined4* puVar4 = reinterpret_cast<undefined4*>(FUN_00545600());
    undefined4* puVar2 = *reinterpret_cast<undefined4**>(reinterpret_cast<char*>(self) + 0x2c);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (__cdecl* ReleaseFn)(int);
                ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(puVar2);
                rel(1);
            }
        }
        *reinterpret_cast<undefined4**>(reinterpret_cast<char*>(self) + 0x2c) = puVar4;
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    return;
}

// 0x5bc640 — observed shape
undefined1 FUN_005bc640(void* self, undefined4 param_1)
{
    extern char FUN_00538360(undefined4 p);
    char cVar1 = FUN_00538360(param_1);
    if (cVar1 == '\0') {
        return 0;
    }
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c) != nullptr) {
        void* vt = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c);
        typedef void (__cdecl* NotifyFn)(undefined4);
        NotifyFn fn = *reinterpret_cast<NotifyFn*>(reinterpret_cast<char*>(vt) + 0x14);
        fn(param_1);
    }
    return 1;
}
extern char FUN_00538460(int param_1);
extern void FUN_005383d0();
extern void FUN_00538630();
extern void FUN_00538430();
extern void FUN_005e4780();
extern void FUN_00538400();
extern void operator_delete(void* p);
extern void FUN_005386f0(int param_1);
extern void FUN_005af810();
extern void FUN_005afb50(undefined4 param_1);
extern void FUN_005afc10(int* param_1);
extern char FUN_005afcd0(int param_1);
extern int FUN_00557d40(const char* param_1, undefined4 param_2);
extern uint8_t DAT_00728cd0;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern void* PTR_FUN_006c6d2c;
extern void* PTR_FUN_006c6db0;

// 0x5bc670 — observed shape
undefined4 FUN_005bc670(void* self, int param_1)
{
    char cVar3 = FUN_00538460(param_1);
    if (cVar3 == '\0') {
        return 0;
    }
    if (*reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0xc) != *reinterpret_cast<float*>(reinterpret_cast<char*>(param_1) + 0xc)) {
        return 0;
    }
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x10) != *reinterpret_cast<char*>(reinterpret_cast<char*>(param_1) + 0x10)) {
        return 0;
    }
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0x11) != *reinterpret_cast<char*>(reinterpret_cast<char*>(param_1) + 0x11)) {
        return 0;
    }
    int iVar1 = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14);
    if (iVar1 == 0) {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x14) != 0) {
            return 0;
        }
    }
    else {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x14) == 0) {
            return 0;
        }
        void* vt14 = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x14);
        typedef char (__cdecl* EqualFn)(int);
        EqualFn eq = *reinterpret_cast<EqualFn*>(reinterpret_cast<char*>(vt14) + 0x1c);
        if ((cVar3 = eq(*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x14))) == '\0') {
            return 0;
        }
    }
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x28) == 0) {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x28) != 0) {
            return 0;
        }
    }
    else {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x28) == 0) {
            return 0;
        }
    }
    void* piVar2 = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c);
    if (piVar2 != nullptr) {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x2c) == 0) {
            return 0;
        }
        typedef char (__cdecl* EqualFn2)(int);
        EqualFn2 eq2 = *reinterpret_cast<EqualFn2*>(reinterpret_cast<char*>(piVar2) + 0x1c);
        cVar3 = eq2(*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x2c));
        if (cVar3 != '\0') {
            return 1;
        }
        return 0;
    }
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x2c) != 0) {
        return 0;
    }
    if (piVar2 == nullptr) {
        return 1;
    }
    return 0;
}

// 0x5bc740 — observed shape
void FUN_005bc740(void* self, undefined4 param_1, undefined1 param_2, undefined1 param_3, undefined4 param_4)
{
    undefined4* inECX = reinterpret_cast<undefined4*>(self);
    FUN_005383d0();
    inECX[3] = param_1;
    *reinterpret_cast<undefined1*>(inECX + 4) = param_2;
    inECX[5] = param_4;
    *inECX = reinterpret_cast<undefined4>(PTR_FUN_006c6d2c);
    *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(inECX) + 0x11) = param_3;
    inECX[6] = DAT_00727430;
    inECX[7] = DAT_00727434;
    undefined4 uVar1 = DAT_00727438;
    inECX[9] = 0;
    inECX[10] = 0;
    inECX[8] = uVar1;
    inECX[0xb] = 0;
    return;
}

// 0x5bc7b0 — observed shape
void FUN_005bc7b0(void* self, int param_1)
{
    FUN_00538630();
    void* vt = *reinterpret_cast<void**>(param_1 + 0x15c);
    typedef void (__cdecl* ReadFn)(void*, ...);
    ReadFn fn = *reinterpret_cast<ReadFn*>(reinterpret_cast<char*>(vt) + 8);
    fn(reinterpret_cast<char*>(self) + 0xc);
    undefined1 buf[4] = {0};
    fn(buf, 1);
    char cVar2 = (char)((*reinterpret_cast<uint*>(buf) >> 0x18));
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(self) + 0x10) = false;
    undefined1 buf2[4] = {0};
    fn(buf2, 1);
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(self) + 0x11) = (cVar2 != '\0');
    FUN_00545cc0();
    FUN_00545cc0();
    FUN_00545cc0();
    return;
}

// 0x5bc830 — observed shape
void FUN_005bc830(void* self, int* param_1)
{
    FUN_00538430();
    void* vt = *reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x58));
    typedef void (__cdecl* ReadFn)(void*, ...);
    ReadFn fn = *reinterpret_cast<ReadFn*>(reinterpret_cast<char*>(vt) + 0xc);
    fn(reinterpret_cast<char*>(self) + 0xc);
    int temp = 4;
    fn(reinterpret_cast<char*>(&temp) - 4, 1);
    temp = (temp & 0xffffff00) | *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(self) + 0x11);
    fn(&temp, 1);
    void* vt0 = *reinterpret_cast<void**>(param_1);
    typedef void (__cdecl* WriteFn)(undefined4);
    WriteFn wfn = *reinterpret_cast<WriteFn*>(reinterpret_cast<char*>(vt0) + 0x2c);
    wfn(*reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x14));
    wfn(*reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x28));
    wfn(*reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x2c));
    return;
}

// 0x5bc8b0 — observed shape
void FUN_005bc8b0(void* self, uint8_t param_1)
{
    FUN_005e4780();
    FUN_00538400();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}
// 0x5bc8e0 — observed shape
void FUN_005bc8e0(void* self, int param_1)
{
    int iVar2 = param_1;
    FUN_005386f0(param_1);
    int localParam = FUN_00557b10(&DAT_00728cd0);
    uint uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    localParam = FUN_00557cf0("Bounce", *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0xc));
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    localParam = FUN_00557b50("Spawn on Collide", *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(self) + 0x10));
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    localParam = FUN_00557b50("Die on Collide", *reinterpret_cast<undefined1*>(reinterpret_cast<char*>(self) + 0x11));
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    void* puVar3;
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14) == 0) {
        puVar3 = &DAT_0070c39c;
    }
    else {
        puVar3 = *reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14) + 0xc);
    }
    localParam = FUN_00557d80("Spawn Modifier", puVar3);
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    localParam = FUN_00557d40("Manager", *reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x28));
    uVar1 = *reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 0xc);
    if (*reinterpret_cast<uint*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(iVar2) + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &localParam);
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c) != nullptr) {
        void* vt = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c);
        typedef void (__cdecl* WriteFn)(int);
        WriteFn fn = *reinterpret_cast<WriteFn*>(reinterpret_cast<char*>(vt) + 0x20);
        fn(iVar2);
    }
    return;
}

// 0x5bca70 — observed shape
void FUN_005bca70(void* self)
{
    FUN_005af810();
    *reinterpret_cast<undefined4*>(self) = reinterpret_cast<undefined4>(PTR_FUN_006c6db0);
    reinterpret_cast<undefined4*>(self)[0x14] = 0;
    return;
}

// 0x5bcaa0 — observed shape
void FUN_005bcaa0(void* self, undefined4 param_1)
{
    (void)self;
    FUN_005afb50(param_1);
    FUN_00545cc0();
    return;
}

// 0x5bcae0 — observed shape
void FUN_005bcae0(void* self, int* param_1)
{
    FUN_005afc10(param_1);
    void* vt = *reinterpret_cast<void**>(param_1);
    typedef void (__cdecl* CopyFn)(undefined4);
    CopyFn fn = *reinterpret_cast<CopyFn*>(reinterpret_cast<char*>(vt) + 0x2c);
    fn(*reinterpret_cast<undefined4*>(reinterpret_cast<char*>(self) + 0x50));
    return;
}

// 0x5bcb00 — observed shape
undefined4 FUN_005bcb00(void* self, int param_1)
{
    char cVar2 = FUN_005afcd0(param_1);
    if (cVar2 == '\0') {
        return 0;
    }
    int iVar1 = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x50);
    if (iVar1 != 0) {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x50) == 0) {
            return 0;
        }
    }
    else {
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x50) != 0) {
            return 0;
        }
        if (iVar1 == 0) {
            return 1;
        }
    }
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x50) == 0) {
        return 1;
    }
    void* vt = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x50);
    typedef char (__cdecl* EqualFn)(int);
    EqualFn eq = *reinterpret_cast<EqualFn*>(reinterpret_cast<char*>(vt) + 0x1c);
    cVar2 = eq(*reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x50));
    if (cVar2 != '\0') {
        return 1;
    }
    return 0;
}
