#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void FUN_0053c1d0(void* self);
extern void FUN_00547db0(void* self, int param_1, uint32_t param_2);
extern void FUN_00547d10(void* self);
extern void FUN_00547fa0(void* self, int param_1);
extern void* thunk_FUN_00533c78(uint32_t size);

extern void* PTR_FUN_006c3760;
extern void* PTR_FUN_006c3304;
extern void* PTR_FUN_006c37f4;
extern void* PTR_FUN_006c3838;

// 0x565cb0 — observed shape
void FUN_00565cb0(void* self, uint8_t param_1)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    *fields = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c3760));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(fields[0x46]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Func = void (*)(uint32_t);
            Func fn = reinterpret_cast<Func>(*puVar2);
            fn(1);
        }
    }
    fields[0x3f] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c3304));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[0x40])));
    FUN_0053c1d0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x565e30 — observed shape
void FUN_00565e30(void* self, int param_1, uint32_t param_2)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int in_ECX = param_1;
    FUN_00547db0(self, param_1, param_2);
    int count = *reinterpret_cast<int*>(in_ECX + 0x10);
    int* srcPtr = reinterpret_cast<int*>(in_ECX + 0x14);
    if ((*reinterpret_cast<int*>(in_ECX + 0x14) == 0) || (count == 0)) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x14) = 0;
        *reinterpret_cast<uint32_t*>(param_1 + 0x10) = 0;
    }
    else {
        *reinterpret_cast<int*>(param_1 + 0x10) = count;
        uint32_t alloc = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(thunk_FUN_00533c78((uint32_t)count << 2)));
        *reinterpret_cast<uint32_t*>(param_1 + 0x14) = alloc;
        uint32_t uVar2 = 0;
        if (count != 0) {
            do {
                *reinterpret_cast<uint32_t*>(alloc + uVar2 * 4) = *reinterpret_cast<uint32_t*>(*srcPtr + uVar2 * 4);
                uVar2 = uVar2 + 1;
            } while (uVar2 < (uint32_t)count);
        }
    }
    (void)selfBytes;
}

// 0x565fc0 — observed shape
void FUN_00565fc0(void* self, uint8_t param_1)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    *fields = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c37f4));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[5])));
    fields[5] = 0;
    FUN_00547d10(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x566000 — observed shape
void FUN_00566000(void* self, int param_1)
{
    int in_ECX = param_1;
    FUN_00547fa0(self, param_1);
    int* piVar1 = reinterpret_cast<int*>(in_ECX + 0x10);
    int vtable0 = *reinterpret_cast<int*>(param_1 + 0x15c);
    using Func = void (*)(int*, int);
    Func fn0 = reinterpret_cast<Func>(*reinterpret_cast<void**>(vtable0) + 8);
    fn0(piVar1, 4);
    if (*piVar1 == 0) {
        *reinterpret_cast<uint32_t*>(in_ECX + 0x14) = 0;
        return;
    }
    uint32_t uVar2 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(thunk_FUN_00533c78((uint32_t)(*piVar1) * 4)));
    *reinterpret_cast<uint32_t*>(in_ECX + 0x14) = uVar2;
    int vtable1 = *reinterpret_cast<int*>(param_1 + 0x15c);
    Func fn1 = reinterpret_cast<Func>(*reinterpret_cast<void**>(vtable1) + 8);
    fn1(reinterpret_cast<int*>(uVar2), (*piVar1) << 2);
}

// 0x566240 — observed shape
void FUN_00566240(void* self, uint8_t param_1)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    *fields = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c3838));
    FUN_00547d10(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

extern void* PTR_FUN_006c3878;
extern void* PTR_FUN_006c38b8;
extern uint32_t DAT_0071778c;
extern uint32_t DAT_00717790;
extern uint32_t DAT_00717794;
extern uint32_t DAT_00717798;
extern void FUN_00547c80(void* self);
extern void FUN_00547db0_3(void* self, int param_1);
extern void FUN_00535110(void* self, int param_1);
extern void FUN_00535190(void* self, int param_1);

// 0x5663c0 — observed shape
void FUN_005663c0(void* self, uint8_t param_1)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    *fields = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c3878));
    FUN_00547d10(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5664e0 — observed shape
void FUN_005664e0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    fields[0x10 >> 2] = param_1;
    fields[0x14 >> 2] = param_2;
    fields[0x18 >> 2] = param_3;
    fields[0x1c >> 2] = param_4;
}

// 0x566540 — observed shape
uint32_t* FUN_00566540(void* self, int param_1)
{
    int in_ECX = param_1;
    uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x20));
    if (puVar1 == nullptr) {
        puVar1 = nullptr;
    }
    else {
        FUN_00547c80(reinterpret_cast<void*>(puVar1));
        *puVar1 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c38b8));
        puVar1[4] = 0;
        puVar1[5] = 0;
        puVar1[6] = 0;
        puVar1[7] = 0;
        puVar1[4] = DAT_0071778c;
        puVar1[5] = DAT_00717790;
        puVar1[6] = DAT_00717794;
        puVar1[7] = DAT_00717798;
    }
    FUN_00547db0_3(reinterpret_cast<void*>(puVar1), param_1);
    puVar1[4] = *reinterpret_cast<uint32_t*>(in_ECX + 0x10);
    puVar1[5] = *reinterpret_cast<uint32_t*>(in_ECX + 0x14);
    puVar1[6] = *reinterpret_cast<uint32_t*>(in_ECX + 0x18);
    puVar1[7] = *reinterpret_cast<uint32_t*>(in_ECX + 0x1c);
    (void)self;
    return puVar1;
}

// 0x566630 — observed shape
void FUN_00566630(void* self, int param_1)
{
    FUN_00547fa0(self, param_1);
    if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0x500000e) {
        FUN_00535110(self, param_1);
        uint32_t* fields = static_cast<uint32_t*>(self);
        fields[0x10 >> 2] = 0;
        fields[0x14 >> 2] = 0;
        fields[0x18 >> 2] = 0;
        fields[0x1c >> 2] = 0x3f800000;
        return;
    }
    FUN_00535190(self, param_1);
}

// 0x5666a0 — observed shape
void FUN_005666a0(void* self, uint8_t param_1)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    *fields = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c38b8));
    FUN_00547d10(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

extern void FUN_004db0a0(void* self);
extern void FUN_005373f0(void* ptr);
extern void FUN_005366d0(void* self);
extern void FUN_00537c70(void* self, int param_1, uint32_t param_2);
extern void FUN_00533e70(void* self);
extern void FUN_00537950(void* self);
extern void* FUN_0053bb30(int param_1);
extern void FUN_00540c50(void* self);
extern void FUN_004aac50(void* self, uint32_t** ptr);
extern void FUN_00534130(void* self);
extern void FUN_00534350(void* self);
extern void FUN_005667f0(void* self);
extern void FUN_005366b0(void* self);
extern void* FUN_005565b0(void* self);
extern void FUN_00537af0(void* self);
extern void* PTR_FUN_006c38f8;
extern void* PTR_FUN_0070bed4;

// 0x5667f0 — observed shape
void FUN_005667f0(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    FUN_004db0a0(self);
    *reinterpret_cast<int*>(b + 0x11c) = *reinterpret_cast<int*>(b + 0x6c);
    *reinterpret_cast<int*>(b + 0x120) = *reinterpret_cast<int*>(b + 0x78);
    *reinterpret_cast<int*>(b + 0x124) = *reinterpret_cast<int*>(b + 0x84);
    *reinterpret_cast<int*>(b + 0x110) = *reinterpret_cast<int*>(b + 0x70);
    *reinterpret_cast<int*>(b + 0x114) = *reinterpret_cast<int*>(b + 0x7c);
    *reinterpret_cast<int*>(b + 0x118) = *reinterpret_cast<int*>(b + 0x88);
    *reinterpret_cast<int*>(b + 0x104) = *reinterpret_cast<int*>(b + 0x74);
    *reinterpret_cast<int*>(b + 0x108) = *reinterpret_cast<int*>(b + 0x80);
    *reinterpret_cast<int*>(b + 0x10c) = *reinterpret_cast<int*>(b + 0x8c);
    *reinterpret_cast<float*>(b + 0x110) = -(*reinterpret_cast<float*>(b + 0x110));
    *reinterpret_cast<float*>(b + 0x114) = -(*reinterpret_cast<float*>(b + 0x114));
    *reinterpret_cast<float*>(b + 0x118) = -(*reinterpret_cast<float*>(b + 0x118));
    FUN_005373f0(b + 0x128);
    FUN_005366d0(self);
}

// 0x5668e0 — observed shape
void FUN_005668e0(void* self, int param_1, uint32_t param_2)
{
    FUN_00537c70(self, param_1, param_2);
    uint8_t* b = reinterpret_cast<uint8_t*>(param_1);
    int* field154 = reinterpret_cast<int*>(b + 0x154);
    if (*field154 != 0) {
        using VFunc = uint32_t* (*)(uint32_t);
        void** vtable = reinterpret_cast<void**>(*field154);
        VFunc fn = reinterpret_cast<VFunc>(vtable[1]);
        uint32_t* puVar3 = fn(param_2);
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(param_1) + 0x154));
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Del = void (*)(uint32_t);
                    Del d = reinterpret_cast<Del>(*puVar2);
                    d(1);
                }
            }
            *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(param_1) + 0x154) = reinterpret_cast<uint32_t>(puVar3);
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
}

// 0x566950 — observed shape
void FUN_00566950(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(b + 0x188) + 0xc));
    if (puVar5 != nullptr) {
        puVar5[1] = puVar5[1] + 1;
    }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(b + 500));
    int iVar3 = *reinterpret_cast<int*>(b + 0x188);
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(iVar3 + 0xc));
    if (puVar4 != puVar2) {
        if (puVar4 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Del = void (*)(uint32_t);
                reinterpret_cast<Del>(*puVar4)(1);
            }
        }
        *reinterpret_cast<uint32_t*>(iVar3 + 0xc) = reinterpret_cast<uint32_t>(puVar2);
        if (puVar2 != nullptr) {
            puVar2[1] = puVar2[1] + 1;
        }
    }
    {
        uint32_t vtbl = *reinterpret_cast<uint32_t*>(b + 500);
        using VFunc = void (*)();
        reinterpret_cast<VFunc>(*reinterpret_cast<void**>(vtbl) + 0x34)();
    }
    if ((*reinterpret_cast<int*>(b + 0x154) != 0) && (*reinterpret_cast<float*>(*reinterpret_cast<int*>(b + 0x154) + 0x34) != 0.0f)) {
        uint32_t vtbl2 = *reinterpret_cast<uint32_t*>(b + 0x188);
        using VFunc2 = void (*)(uint8_t*, uint8_t*, uint8_t*, uint8_t*, uint8_t*, uint8_t*);
        reinterpret_cast<VFunc2>(*reinterpret_cast<void**>(vtbl2) + 0xc4)(b + 0x90, b + 0x104, b + 0x110, b + 0x11c, b + 0x128, b + 0x144);
        puVar5 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(b + 0x188) + 0xc));
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
        iVar3 = *reinterpret_cast<int*>(b + 0x188);
        puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(b + 500));
        puVar4 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(iVar3 + 0xc));
        if (puVar4 != puVar2) {
            if (puVar4 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Del = void (*)(uint32_t);
                    reinterpret_cast<Del>(*puVar4)(1);
                }
            }
            *reinterpret_cast<uint32_t*>(iVar3 + 0xc) = reinterpret_cast<uint32_t>(puVar2);
            if (puVar2 != nullptr) {
                puVar2[1] = puVar2[1] + 1;
            }
        }
        FUN_00533e70(self);
        uint32_t vtbl3 = *reinterpret_cast<uint32_t*>(b + 500);
        using VFunc3 = void (*)();
        reinterpret_cast<VFunc3>(*reinterpret_cast<void**>(vtbl3) + 0x38)();
        if (puVar5 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar5 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Del = void (*)(uint32_t);
                reinterpret_cast<Del>(*puVar5)(1);
            }
        }
        puVar5 = nullptr;
    }
    iVar3 = *reinterpret_cast<int*>(b + 0x188);
    puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(iVar3 + 0xc));
    if (puVar2 != puVar5) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Del = void (*)(uint32_t);
                reinterpret_cast<Del>(*puVar2)(1);
            }
        }
        *reinterpret_cast<uint32_t*>(iVar3 + 0xc) = reinterpret_cast<uint32_t>(puVar5);
        if (puVar5 == nullptr) {
            return;
        }
        puVar5[1] = puVar5[1] + 1;
    }
    if (puVar5 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar5 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Del = void (*)(uint32_t);
            reinterpret_cast<Del>(*puVar5)(1);
        }
    }
}

// 0x566ab0 — observed shape
void FUN_00566ab0(void* self)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    FUN_00537950(self);
    *fields = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c38f8));
    fields[0x7d] = 0;
    int iVar3 = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(0xec)));
    uint32_t* puVar4 = nullptr;
    if (iVar3 == 0) {
        puVar4 = nullptr;
    }
    else {
        puVar4 = static_cast<uint32_t*>(FUN_0053bb30(0));
    }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(fields[0x55]);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Del = void (*)(uint32_t);
                reinterpret_cast<Del>(*puVar2)(1);
            }
        }
        fields[0x55] = reinterpret_cast<uint32_t>(puVar4);
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    puVar4 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x28));
    if (puVar4 == nullptr) {
        puVar4 = nullptr;
    }
    else {
        FUN_00540c50(reinterpret_cast<void*>(puVar4));
        *puVar4 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_0070bed4));
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(puVar4) + 8 * 4) = 3;
        puVar4[9] = 3;
    }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(puVar4) + 8 * 4) = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(puVar4) + 8 * 4) & 0xfc;
    puVar4[1] = puVar4[1] + 1;
    uint32_t* puStack_10 = puVar4;
    FUN_004aac50(self, &puStack_10);
    int* piVar1b = reinterpret_cast<int*>(puVar4 + 1);
    *piVar1b = *piVar1b + -1;
    if (*piVar1b == 0) {
        using Del = void (*)(uint32_t);
        reinterpret_cast<Del>(*puVar4)(1);
    }
    iVar3 = static_cast<int>(fields[0x55]);
    *reinterpret_cast<uint32_t*>(iVar3 + 0x5c) = 0;
    *reinterpret_cast<uint32_t*>(iVar3 + 0x60) = 0;
    *reinterpret_cast<uint32_t*>(iVar3 + 100) = 0x3f800000;
    FUN_00534130(self);
    FUN_00534350(self);
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x50) = 1;
    FUN_005667f0(self);
    FUN_005366b0(self);
    iVar3 = static_cast<int>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(0x34)));
    if (iVar3 == 0) {
        puVar4 = nullptr;
    }
    else {
        puVar4 = static_cast<uint32_t*>(FUN_005565b0(self));
    }
    puVar2 = reinterpret_cast<uint32_t*>(fields[0x7d]);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Del = void (*)(uint32_t);
                reinterpret_cast<Del>(*puVar2)(1);
            }
        }
        fields[0x7d] = reinterpret_cast<uint32_t>(puVar4);
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
}

// 0x566c20 — observed shape
void FUN_00566c20(void* self, uint8_t param_1)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    *fields = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c38f8));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(fields[0x7d]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Del = void (*)(uint32_t);
            reinterpret_cast<Del>(*puVar2)(1);
        }
    }
    FUN_00537af0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

extern void FUN_00566950(void* self);
extern void FUN_00536f40(void* self);
extern void FUN_00536fb0(void* self);
extern void FUN_00538180(void* self, int param_1);
extern int FUN_00557b10(uint32_t param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(void* self, uint32_t param_1, int* param_2);
extern uint32_t DAT_00727dd0;
extern void FUN_0053ca60(void* self, float* out, int* src);
extern void FUN_00566df0(void* self);
extern void FUN_004db0a0_2(void* self);

// 0x566c60 — observed shape
void FUN_00566c60(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<int*>(b + 0x188) == 0) {
        return;
    }
    uint32_t vtbl = *reinterpret_cast<uint32_t*>(b + 0x188);
    using VFunc = void (*)();
    reinterpret_cast<VFunc>(*reinterpret_cast<void**>(vtbl) + 0xbc)();
    FUN_00566950(self);
    FUN_00536f40(self);
    FUN_00536fb0(self);
    uint32_t vtbl2 = *reinterpret_cast<uint32_t*>(b + 0x188);
    reinterpret_cast<VFunc>(*reinterpret_cast<void**>(vtbl2) + 0xc0)();
}

// 0x566d10 — observed shape
void FUN_00566d10(void* self, int param_1)
{
    int iVar2 = param_1;
    FUN_00538180(self, param_1);
    int local_param = FUN_00557b10(DAT_00727dd0);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(self, uVar1, &local_param);
}

// 0x566da0 — observed shape
uint32_t FUN_00566da0(float* self, float* param_1)
{
    float fVar1 = (param_1[0] * self[0] + param_1[1] * self[1] + param_1[2] * self[2]) - self[3];
    if (fVar1 < 0.0f) {
        return 2;
    }
    if (0.0f < fVar1) {
        return 1;
    }
    return 0;
}

// 0x566df0 — observed shape
void FUN_00566df0(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    float local_c = 0.0f;
    float local_8 = 0.0f;
    float local_4 = 0.0f;
    FUN_0053ca60(self, &local_c, reinterpret_cast<int*>(b + 0xec));
    *reinterpret_cast<float*>(b + 0xfc) = local_c;
    *reinterpret_cast<float*>(b + 0x100) = local_8;
    *reinterpret_cast<float*>(b + 0x104) = local_4;
    *reinterpret_cast<float*>(b + 0x108) = local_c * *reinterpret_cast<float*>(b + 0x90) + local_4 * *reinterpret_cast<float*>(b + 0x98) + local_8 * *reinterpret_cast<float*>(b + 0x94) + *reinterpret_cast<float*>(b + 0xf8) * *reinterpret_cast<float*>(b + 0x9c);
}

// 0x566e60 — observed shape
void FUN_00566e60(void* self)
{
    FUN_004db0a0_2(self);
    FUN_00566df0(self);
}
