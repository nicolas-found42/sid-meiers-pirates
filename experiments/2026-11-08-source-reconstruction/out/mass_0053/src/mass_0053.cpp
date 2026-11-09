#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_004fb640();
extern void* thunk_FUN_00533c78(uint32_t size);
extern void FUN_004fc0b0(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_004e6420();
extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern void FUN_004d4cb0();
extern void FUN_004d5270(uint32_t param);
extern void* FUN_00533c78(uint32_t size);
extern void* FUN_0053bb30(uint32_t param);
extern void FUN_004d4f10();
extern void FUN_004ff360(uint32_t param);
extern void FUN_00412840(uint32_t param_1, uint32_t param_2);
extern void FUN_004ff6b0(uint32_t param);
extern void FUN_004d4e60();

extern void* PTR_FUN_0070c0e4;
extern void* PTR_FUN_0070c100;
extern void* PTR_FUN_0070defc;
extern void* PTR_FUN_0070df18;
extern void* PTR_FUN_0070dee0;
extern void* PTR_FUN_0070de80;
extern void* PTR_FUN_0070df44;
extern void* PTR_FUN_0070d868;
extern uint32_t DAT_008cacd4;
extern uint32_t DAT_008cacc8;
extern uint32_t DAT_008cacd0;
extern void* DAT_008ea08c;

// 0x4d4b00 — observed shape
void FUN_004d4b00(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5) {
    int* in_EAX = nullptr;
    FUN_004fb640();
    *reinterpret_cast<void**>(reinterpret_cast<char*>(in_EAX) + 0x20) = &PTR_FUN_0070c0e4;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(in_EAX) + 0x24) = 0x25;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(in_EAX) + 0x2c) = 0;
    uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
    *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(in_EAX) + 0x28) = puVar1;
    for (uint32_t uVar2 = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(in_EAX) + 0x24) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(puVar1) + 1);
    }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_EAX) + 0x30) = 1;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(in_EAX) + 0x20) = &PTR_FUN_0070c100;
    FUN_004fc0b0(param_1, param_4, param_5);
}

// 0x4d4b80 — observed shape
void FUN_004d4b80(uint32_t* self, uint32_t* param_1) {
    // self replaces in_ECX receiver
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(pSelf) + 0xc);
    if (puVar2 != param_1) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using VoidCall = void(*)(int);
                VoidCall* vtbl = *reinterpret_cast<VoidCall**>(puVar2);
                vtbl[0](1);
            }
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(pSelf) + 0xc) = param_1;
        if (param_1 != nullptr) {
            param_1[1] = param_1[1] + 1;
        }
    }
}

// 0x4d4be0 — observed shape
void FUN_004d4be0(uint32_t* self) {
    // self replaces in_ECX receiver
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_0070defc);
    if ((*reinterpret_cast<char*>(self + 4) != '\0') && (self[1] != 0)) {
        uint32_t uVar3 = 0;
        do {
            uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(self[2] + uVar3 * 4);
            while (puVar2 != nullptr) {
                uint32_t* puVar1 = puVar2 + 1;
                puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
                operator_delete__(reinterpret_cast<void*>(*puVar1));
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < self[1]);
    }
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_0070df18);
    FUN_004e6420();
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_0070dee0);
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(self[2]));
}

// 0x4d4c60 — observed shape
void FUN_004d4c60(uint8_t param_1, uint32_t* self) {
    // self replaces in_ECX receiver
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_0070de80);
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 5) == '\0') {
        *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 5) = 1;
        DestroyWindow(reinterpret_cast<HWND>(self[0x15]));
        PostQuitMessage(0);
    }
    DAT_008cacd4 = 0;
    FUN_004d4cb0();
    if ((param_1 & 1) != 0) {
        operator_delete(reinterpret_cast<void*>(self));
    }
}

// 0x4d4cb0 — observed shape
void FUN_004d4cb0(uint32_t* self) {
    // self replaces in_ECX receiver
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_0070df44);
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 5) == '\0') {
        *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 5) = 1;
        DestroyWindow(reinterpret_cast<HWND>(self[0x15]));
        PostQuitMessage(0);
    }
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(self[0x12] + -8);
    DAT_008cacd4 = 0;
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    self[0x12] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
    puVar1 = reinterpret_cast<uint32_t*>(self[0x11] + -8);
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    self[0x11] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
    puVar1 = reinterpret_cast<uint32_t*>(self[0xe] + -8);
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    self[0xe] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
    if (reinterpret_cast<HANDLE>(self[0xd]) != nullptr) {
        CloseHandle(reinterpret_cast<HANDLE>(self[0xd]));
    }
    if (self[4] != 0) {
        SystemParametersInfoA(0x37, 0x1c, reinterpret_cast<LPVOID>(self + 4), 2);
    }
    if (self[0xb] != 0) {
        SystemParametersInfoA(0x3b, 8, reinterpret_cast<LPVOID>(self + 0xb), 2);
    }
}

// 0x4d4da0 — observed shape
void FUN_004d4da0(int* self) {
    // self replaces unaff_ESI receiver
    self[0] = 0;
    self[2] = 0;
    self[4] = 0;
    self[5] = 0;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self[0]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
        self[0] = 0;
    }
    self[3] = 0;
    puVar2 = reinterpret_cast<uint32_t*>(self[4]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
        self[4] = 0;
    }
    puVar2 = reinterpret_cast<uint32_t*>(self[2]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
        self[2] = 0;
    }
    self[1] = 0;
    self[6] = 0;
}

// 0x4d4e00 — observed shape
void FUN_004d4e00(int* self) {
    // self replaces in_EAX receiver
    FUN_004d4e60(self);
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self[5]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
    }
    puVar2 = reinterpret_cast<uint32_t*>(self[4]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
    }
    puVar2 = reinterpret_cast<uint32_t*>(self[2]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
    }
    puVar2 = reinterpret_cast<uint32_t*>(self[0]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
    }
}

// 0x4d4e60 — observed shape
void FUN_004d4e60(int* self) {
    // self replaces unaff_ESI receiver
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self[0]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
        self[0] = 0;
    }
    puVar2 = reinterpret_cast<uint32_t*>(self[4]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
        self[4] = 0;
    }
    puVar2 = reinterpret_cast<uint32_t*>(self[2]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
        self[2] = 0;
    }
}

// 0x4d4eb0 — observed shape
void FUN_004d4eb0(uint32_t* self, uint32_t param_1, uint32_t in_EAX) {
    // self replaces in_ECX receiver
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 4) = in_EAX;
    FUN_004d5270(in_EAX);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0xc) = param_1;
    uint32_t iVar3 = reinterpret_cast<uint32_t>(FUN_00533c78(0xec));
    uint32_t* puVar4 = nullptr;
    if (iVar3 == 0) {
        puVar4 = nullptr;
    } else {
        puVar4 = static_cast<uint32_t*>(FUN_0053bb30(0));
    }
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 8);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using VoidCall = void(*)(int);
                (*reinterpret_cast<VoidCall*>(puVar2))(1);
            }
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 8) = puVar4;
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    FUN_004d4f10(self);
}

// 0x4d4f10 — observed shape
void FUN_004d4f10(int* self) {
    // self replaces in_EAX receiver
    uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x238));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_004ff360(0x42340000);
        *puVar3 = reinterpret_cast<uint32_t>(&PTR_FUN_0070d868);
    }
    uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x10);
    if (puVar5 != puVar3) {
        if (puVar5 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar5 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using VoidCall = void(*)(int);
                (*reinterpret_cast<VoidCall*>(puVar5))(1);
            }
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x10) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    puVar5 = static_cast<uint32_t*>(DAT_008ea08c);
    int iVar4 = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x10);
    puVar3 = *reinterpret_cast<uint32_t**>(iVar4 + 0x188);
    if (puVar3 != static_cast<uint32_t*>(DAT_008ea08c)) {
        if (puVar3 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using VoidCall = void(*)(int);
                (*reinterpret_cast<VoidCall*>(puVar3))(1);
            }
        }
        *reinterpret_cast<uint32_t**>(iVar4 + 0x188) = puVar5;
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    iVar4 = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0xc);
    int iVar2 = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x10);
    *reinterpret_cast<uint32_t*>(iVar2 + 0x5c) = *reinterpret_cast<uint32_t*>(iVar4 + 0x5c);
    *reinterpret_cast<uint32_t*>(iVar2 + 0x60) = *reinterpret_cast<uint32_t*>(iVar4 + 0x60);
    *reinterpret_cast<uint32_t*>(iVar2 + 100) = *reinterpret_cast<uint32_t*>(iVar4 + 100);
    uint32_t* puVar3b = reinterpret_cast<uint32_t*>(iVar4 + 0x38);
    uint32_t* puVar5b = reinterpret_cast<uint32_t*>(iVar2 + 0x38);
    for (int i = 9; i != 0; i = i + -1) {
        *puVar5b = *puVar3b;
        puVar3b = puVar3b + 1;
        puVar5b = puVar5b + 1;
    }
    FUN_00412840(0x41200000, 0x47c35000);
    FUN_004ff6b0(0);
}

// 0x4d4fe0 — observed shape
void FUN_004d4fe0(uint32_t* param_1, uint32_t in_EAX) {
    int* piVar1;
    int iVar2;
    int iVar3;
    uint32_t* puVar4;
    uint32_t* puVar6;
    uint32_t uVar9;
    uint8_t auStack_66[2];
    float afStack_64[5];
    uint8_t auStack_50[76];
    float fStack_4;

    param_1[6] = in_EAX;
    {
        using Fn = void(*)(uint32_t);
        Fn fn = *reinterpret_cast<Fn*>(*static_cast<uint32_t**>(DAT_008ea08c) + 0x40);
        fn(param_1[0]);
    }
    afStack_64[0] = 0.0f;
    {
        using Fn = void (*)(void*);
        Fn fn = *reinterpret_cast<Fn*>(*static_cast<uint32_t**>(DAT_008ea08c) + 0x74);
        fn(auStack_66 + -6);
    }
    FUN_00535de0(5);
    iVar2 = DAT_008e9fd8;
    iVar3 = static_cast<int>(param_1[4]);
    param_1[3] = DAT_008e9fd8;
    *reinterpret_cast<uint32_t*>(iVar3 + 0x5c) = *reinterpret_cast<uint32_t*>(iVar2 + 0x90);
    *reinterpret_cast<uint32_t*>(iVar3 + 0x60) = *reinterpret_cast<uint32_t*>(iVar2 + 0x94);
    *reinterpret_cast<uint32_t*>(iVar3 + 100) = *reinterpret_cast<uint32_t*>(iVar2 + 0x98);
    puVar4 = reinterpret_cast<uint32_t*>(param_1[3] + 0x6c);
    puVar6 = reinterpret_cast<uint32_t*>(param_1[4] + 0x38);
    for (int i = 9; i != 0; i = i + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
    }
    float* pfVar5 = reinterpret_cast<float*>(param_1[3] + 0x128);
    float* pfVar7 = afStack_64;
    for (int i = 7; i != 0; i = i + -1) {
        *pfVar7 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        pfVar7 = pfVar7 + 1;
    }
    float d = (afStack_64[1] - afStack_64[0]) * (afStack_64[1] - afStack_64[0]) +
              (afStack_64[2] - afStack_64[3]) * (afStack_64[2] - afStack_64[3]);
    float fVar8 = static_cast<float>(atan2(sqrt(d * 0.5f), 1.0f));
    fStack_4 = (fVar8 + fVar8) * 57.29577951308232f;
    if (DAT_008cac36 == '\0') {
        uVar9 = 0x3faaaaab;
    } else {
        uVar9 = 0x3fe38e39;
    }
    FUN_004ff510(*reinterpret_cast<uint32_t*>(&fStack_4), uVar9);
    FUN_004ff6b0(0);
    FUN_004d5330(reinterpret_cast<int>(param_1));
    iVar3 = static_cast<int>(param_1[4]);
    puVar4 = reinterpret_cast<uint32_t*>(param_1[2]);
    puVar6 = *reinterpret_cast<uint32_t**>(iVar3 + 0x154);
    if (puVar6 != puVar4) {
        if (puVar6 != nullptr) {
            piVar1 = reinterpret_cast<int*>(puVar6 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using VoidCall = void(*)(int);
                (*reinterpret_cast<VoidCall*>(puVar6))(1);
            }
        }
        *reinterpret_cast<uint32_t**>(iVar3 + 0x154) = puVar4;
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    {
        using Fn = void(*)();
        Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<int*>(param_1[4]) + 0x70);
        fn();
    }
    FUN_00535e10();
    iVar3 = static_cast<int>(param_1[4]);
    puVar4 = *reinterpret_cast<uint32_t**>(iVar3 + 0x154);
    if (puVar4 != nullptr) {
        piVar1 = reinterpret_cast<int*>(puVar4 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar4))(1);
        }
        *reinterpret_cast<uint32_t*>(iVar3 + 0x154) = 0;
    }
    {
        using Fn = void(*)(int);
        Fn fn = *reinterpret_cast<Fn*>(*static_cast<uint32_t**>(DAT_008ea08c) + 0x40);
        fn(0);
    }
    {
        using Fn = void (*)(void*);
        Fn fn = *reinterpret_cast<Fn*>(*static_cast<uint32_t**>(DAT_008ea08c) + 0x74);
        fn(auStack_66 + -0xe);
    }
    FUN_004d5330(reinterpret_cast<int>(param_1));
    FUN_00547720();
    FUN_004d5590(auStack_50);
    FUN_005be280("mtxReflect", 0x40, auStack_50);
}

// 0x4d51c0 — observed shape
void FUN_004d51c0(uint32_t* self) {
    // self replaces unaff_EDI receiver
    uint32_t local_8 = 2;
    uint32_t local_4 = 0;
    uint32_t local_c = 1;
    uint32_t* puVar2 = static_cast<uint32_t*>(FUN_0054c210(0x200, 0x200, DAT_008ea08c, reinterpret_cast<uint32_t*>(&local_c)));
    if (puVar2 == nullptr) {
        int* piVar3;
        if (DAT_008ea08c == nullptr) {
            piVar3 = nullptr;
        } else {
            piVar3 = *reinterpret_cast<int**>(reinterpret_cast<char*>(DAT_00727c30) + 0x60);
        }
        {
            using Fn = void(*)(int*);
            Fn fn = *reinterpret_cast<Fn*>(*piVar3 + 0x14);
            fn(piVar3);
        }
        uint32_t* puVar4 = static_cast<uint32_t*>(FUN_0054c210(0x200, 0x200, DAT_008ea08c, reinterpret_cast<uint32_t*>(&local_c)));
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
            puVar2 = puVar4;
        }
    } else {
        puVar2[1] = puVar2[1] + 1;
    }
    *self = reinterpret_cast<uint32_t>(puVar2);
    if (puVar2 != nullptr) {
        int iVar1 = static_cast<int>(puVar2[1]);
        puVar2[1] = static_cast<uint32_t>(iVar1 + 1);
        puVar2[1] = static_cast<uint32_t>(iVar1);
        if (iVar1 == 0) {
            using VoidCall = void(*)(int);
            (*reinterpret_cast<VoidCall*>(puVar2))(1);
        }
    }
}

// 0x4d5270 — observed shape
void FUN_004d5270(uint32_t* self, uint32_t* param_1) {
    // self replaces unaff_EBX receiver
    FUN_00533db0(8);
    int* piVar3 = reinterpret_cast<int*>(FUN_004d51c0(self));
    uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(self);
    if (puVar4 != reinterpret_cast<uint32_t*>(piVar3)) {
        if (puVar4 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using VoidCall = void(*)(int);
                (*reinterpret_cast<VoidCall*>(puVar4))(1);
            }
        }
        int iVar2 = *piVar3;
        *self = static_cast<uint32_t>(iVar2);
        if (iVar2 != 0) {
            *reinterpret_cast<int*>(iVar2 + 4) = *reinterpret_cast<int*>(iVar2 + 4) + 1;
        }
    }
    if ((param_1 != nullptr) && (param_1[1] - 1 == 0)) {
        param_1[1] = param_1[1] + -1;
        using VoidCall = void(*)(int);
        (*reinterpret_cast<VoidCall*>(param_1))(1);
    } else if (param_1 != nullptr) {
        param_1[1] = param_1[1] + -1;
    }
    puVar4 = static_cast<uint32_t*>(FUN_00533c78(0x20));
    if (puVar4 == nullptr) {
        puVar4 = nullptr;
    } else {
        FUN_00542700(*self, 0, 3, 1, 0);
        *puVar4 = reinterpret_cast<uint32_t>(&PTR_FUN_0070d038);
        puVar4[7] = 0;
    }
    FUN_00542cb0(0, puVar4);
    FUN_00547730(param_1, "TDanceReflections_11", 0);
}

// 0x4d5330 — observed shape
void FUN_004d5330(int param_1) {
    int* piVar1;
    int* piVar2;
    uint32_t* puVar3;
    uint8_t bVar4;
    uint32_t* puVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t* puVar8;
    uint32_t* puVar9;
    uint32_t uVar10;
    uint32_t uStack_30;
    uint32_t local_28;
    uint32_t auStack_24[8];
    float fStack_4;

    (void)fStack_4;
    iVar7 = *reinterpret_cast<int*>(param_1 + 8);
    local_28 = 0;
    if (*reinterpret_cast<int*>(iVar7 + 0xc0) != 0) {
        uVar10 = 0;
        if (*reinterpret_cast<int*>(iVar7 + 0xc0) == 0) goto LAB_004d544c;
        do {
            piVar2 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(iVar7 + 0xb8) + local_28 * 4);
            uVar10 = local_28;
            if (piVar2 != nullptr) {
                piVar2[1] = piVar2[1] + 1;
                {
                    using Fn = uint32_t*(*)();
                    Fn fn = *reinterpret_cast<Fn*>(*piVar2 + 4);
                    puVar5 = fn();
                }
                for (; puVar5 != nullptr; puVar5 = reinterpret_cast<uint32_t*>(puVar5[1])) {
                    if (puVar5 == reinterpret_cast<uint32_t*>(&DAT_00727560)) {
                        bVar4 = 1;
                        goto LAB_004d5394;
                    }
                }
                bVar4 = 0;
LAB_004d5394:
                puVar5 = reinterpret_cast<uint32_t*>(-static_cast<uint32_t>(bVar4) & reinterpret_cast<uint32_t>(piVar2));
                if (puVar5 != nullptr) {
                    puVar5[1] = puVar5[1] + 1;
                    uStack_30 = 0;
                    if (puVar5[0x30] != 0) {
                        uVar6 = 0;
                        if (puVar5[0x30] == 0) goto LAB_004d541e;
                        do {
                            puVar3 = *reinterpret_cast<uint32_t**>(puVar5[0x2e] + uStack_30 * 4);
                            uVar6 = uStack_30;
                            if (puVar3 != nullptr) {
                                puVar3[1] = puVar3[1] + 1;
                                puVar8 = puVar3 + 0xe;
                                puVar9 = auStack_24;
                                for (int i = 9; i != 0; i = i + -1) {
                                    *puVar9 = *puVar8;
                                    puVar8 = puVar8 + 1;
                                    puVar9 = puVar9 + 1;
                                }
                                fStack_4 = fStack_4 * -1.0f;
                                puVar8 = auStack_24;
                                puVar9 = puVar3 + 0xe;
                                for (int i = 9; i != 0; i = i + -1) {
                                    *puVar9 = *puVar8;
                                    puVar8 = puVar8 + 1;
                                    puVar9 = puVar9 + 1;
                                }
                                FUN_00533d10(0, 0);
                                FUN_004d5480(reinterpret_cast<int*>(puVar3));
                                piVar1 = reinterpret_cast<int*>(puVar3 + 1);
                                *piVar1 = *piVar1 + -1;
                                if (*piVar1 == 0) {
                                    using VoidCall = void(*)(int);
                                    (*reinterpret_cast<VoidCall*>(puVar3))(1);
                                }
                            }
LAB_004d541e:
                            uStack_30 = uVar6 + 1;
                        } while (uStack_30 < puVar5[0x30]);
                    }
                    piVar1 = reinterpret_cast<int*>(puVar5 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        using VoidCall = void(*)(int);
                        (*reinterpret_cast<VoidCall*>(puVar5))(1);
                    }
                }
                piVar1 = piVar2 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using VoidCall = void(*)(int);
                    (*reinterpret_cast<VoidCall*>(piVar2))(1);
                }
            }
LAB_004d544c:
            iVar7 = *reinterpret_cast<int*>(param_1 + 8);
            local_28 = uVar10 + 1;
        } while (local_28 < *reinterpret_cast<uint32_t*>(iVar7 + 0xc0));
    }
}

// 0x4d5480 — observed shape
void FUN_004d5480(int* param_1) {
    int* piVar1;
    uint8_t bVar2;
    int* piVar3;
    int iVar4;
    uint32_t* puVar5;
    int* piVar6;
    uint32_t uVar8;

    piVar3 = param_1;
    iVar4 = FUN_00533db0(7);
    if (piVar3 != nullptr) {
        {
            using Fn = uint32_t*(*)();
            Fn fn = *reinterpret_cast<Fn*>(*piVar3 + 4);
            puVar5 = fn();
        }
        for (; puVar5 != nullptr; puVar5 = reinterpret_cast<uint32_t*>(puVar5[1])) {
            if (puVar5 == reinterpret_cast<uint32_t*>(&DAT_00727598)) {
                if (iVar4 == 0) {
                    iVar4 = FUN_00533c78(0x40);
                    if (iVar4 == 0) {
                        piVar6 = nullptr;
                    } else {
                        piVar6 = static_cast<int*>(FUN_004d57d0());
                    }
                    reinterpret_cast<int*>(reinterpret_cast<char*>(piVar6) + 0x3c)[0] = 2;
                    piVar6[1] = piVar6[1] + 1;
                    {
                        int* tmp = piVar6;
                        FUN_004aac50(reinterpret_cast<int**>(&tmp));
                    }
                    piVar1 = piVar6 + 1;
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        using VoidCall = void(*)(int);
                        (*reinterpret_cast<VoidCall*>(piVar6))(1);
                    }
                    FUN_00534130();
                } else if (*reinterpret_cast<int*>(iVar4 + 0x3c) != 3) {
                    *reinterpret_cast<uint32_t*>(iVar4 + 0x3c) = static_cast<uint32_t>((*reinterpret_cast<int*>(iVar4 + 0x3c) == 1) + 1);
                }
                break;
            }
        }
        {
            using Fn = uint32_t*(*)();
            Fn fn = *reinterpret_cast<Fn*>(*piVar3 + 4);
            puVar5 = fn();
        }
        for (; puVar5 != nullptr; puVar5 = reinterpret_cast<uint32_t*>(puVar5[1])) {
            if (puVar5 == reinterpret_cast<uint32_t*>(&DAT_00727560)) {
                bVar2 = 1;
                goto LAB_004d5540;
            }
        }
        bVar2 = 0;
LAB_004d5540:
        {
            uint32_t uVar7 = -static_cast<uint32_t>(bVar2) & reinterpret_cast<uint32_t>(piVar3);
            if (uVar7 != 0) {
                uVar8 = 0;
                if (*reinterpret_cast<int*>(uVar7 + 0xc0) != 0) {
                    if (*reinterpret_cast<int*>(uVar7 + 0xc0) == 0) goto LAB_004d556f;
                    do {
                        iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(uVar7 + 0xb8) + uVar8 * 4);
                        if (iVar4 != 0) {
                            FUN_004d5480(reinterpret_cast<int*>(iVar4));
                        }
LAB_004d556f:
                        uVar8 = uVar8 + 1;
                    } while (uVar8 < *reinterpret_cast<uint32_t*>(uVar7 + 0xc0));
                }
            }
        }
    }
}

// 0x4d5590 — observed shape
void FUN_004d5590(int* unaff_EBX) {
    int iVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint32_t* puStack_2b4;
    uint32_t* puStack_2b0;
    uint32_t* puStack_2ac;
    float* pfStack_2a8;
    uint32_t local_268[7];
    uint32_t local_24c;
    uint32_t local_248;
    uint32_t local_244;
    uint32_t local_240;
    uint32_t local_23c;
    uint32_t local_21c;
    uint32_t local_218;
    uint32_t local_214;
    uint32_t local_20c;
    uint32_t local_208;
    uint32_t local_204;
    uint32_t local_1fc;
    uint32_t local_1f8;
    uint32_t local_1f4;
    uint32_t auStack_1e8[3];
    float local_1dc[5];
    float local_1c8;
    float local_1a4;
    uint32_t local_19c[4];
    float local_18c;
    uint8_t local_180[40];
    uint32_t auStack_158[19];
    uint32_t auStack_10c[10];
    uint32_t auStack_e4[3];
    uint8_t auStack_d8[64];
    uint32_t auStack_98[3];
    uint8_t auStack_8c[40];
    uint32_t auStack_64[17];
    uint32_t uStack_20;

    (void)uStack_20;
    (void)local_24c; (void)local_248; (void)local_244; (void)local_240; (void)local_23c;
    pfStack_2a8 = nullptr;
    puStack_2ac = reinterpret_cast<uint32_t*>(0x4d55a6);
    FUN_0054a9f0();
    puStack_2ac = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(unaff_EBX) + 0x10);
    pfStack_2a8 = local_1dc;
    local_268[0] = 0x3f000000;
    local_268[1] = 0;
    local_268[2] = 0x3f800000;
    puStack_2b0 = reinterpret_cast<uint32_t*>(0x4d5637);
    FUN_004ff9a0();
    puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(unaff_EBX) + 0x10) + 0x128);
    puVar3 = local_19c;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    local_18c = 1.0f / local_18c;
    pfStack_2a8 = reinterpret_cast<float*>(local_180);
    local_1dc[0] = local_1dc[0] * local_18c;
    local_1c8 = local_1c8 * local_18c;
    local_1a4 = local_18c * local_1a4;
    puStack_2ac = reinterpret_cast<uint32_t*>(0x4d5696);
    FUN_004ff930();
    pfStack_2a8 = nullptr;
    puStack_2ac = nullptr;
    puStack_2b0 = nullptr;
    puStack_2b4 = &local_21c;
    puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(unaff_EBX) + 0x18) + 0x38);
    puVar3 = local_268 + 3;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    thunk_FUN_005f2abc();
    local_21c = local_268[3];
    local_218 = local_268[4];
    local_214 = local_268[5];
    local_20c = local_268[6];
    local_208 = local_24c;
    local_204 = local_248;
    local_1fc = local_244;
    pfStack_2a8 = reinterpret_cast<float*>(local_180);
    local_1f8 = local_240;
    puStack_2ac = &local_21c;
    local_1f4 = local_23c;
    puStack_2b0 = local_268 + 3;
    puStack_2b4 = reinterpret_cast<uint32_t*>(0x4d5737);
    thunk_FUN_005f2148();
    puVar2 = local_268;
    puVar3 = auStack_10c;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    puStack_2b4 = auStack_1e8;
    thunk_FUN_005f2148(auStack_8c, auStack_10c);
    puVar2 = auStack_98;
    puVar3 = auStack_158;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    thunk_FUN_005f2148(auStack_d8, auStack_158, &puStack_2b4);
    puVar2 = auStack_e4;
    puVar3 = auStack_64;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    thunk_FUN_005f2399(uStack_20, auStack_64);
}

// 0x4d57d0 — observed shape
void FUN_004d57d0(uint32_t* self) {
    // self replaces in_ECX receiver
    FUN_00540c50();
    *reinterpret_cast<uint8_t*>(self + 8) = 0;
    self[10] = 0;
    self[0xc] = 0;
    self[0xd] = 0;
    self[0xf] = 0;
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_0070e93c);
    self[9] = 4;
    self[0xb] = 0xffffffff;
    self[0xe] = 3;
}

// 0x4d5810 — observed shape
void FUN_004d5810(uint8_t param_1, uint32_t* self) {
    // self replaces in_ECX receiver
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_0070e93c);
    FUN_00540c90();
    if ((param_1 & 1) != 0) {
        operator_delete(reinterpret_cast<void*>(self));
    }
}

// 0x4d5860 — observed shape
void FUN_004d5860(uint32_t* unaff_ESI) {
    *unaff_ESI = reinterpret_cast<uint32_t>(&PTR_LAB_00710bfc);
    unaff_ESI[1] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
    FUN_00412cb0();
    FUN_005022c0(0);
    *reinterpret_cast<uint8_t*>(unaff_ESI + 2) = 0;
    *unaff_ESI = reinterpret_cast<uint32_t>(&PTR_LAB_0070e99c);
    FUN_00412cb0();
    FUN_005022c0(0);
    *reinterpret_cast<uint8_t*>(unaff_ESI + 3) = 0;
}

// 0x4d58b0 — observed shape
uint32_t FUN_004d58b0(int* self, uint32_t in_EAX) {
    // self replaces in_ECX receiver
    int iVar1 = static_cast<int>(in_EAX) | (static_cast<uint32_t>(*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0xc)) << 24);
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(self) + 0xc) != '\0') {
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(&DAT_007268f4) + DAT_00726a84 * 4) = DAT_007263bc;
        DAT_00726a84 = DAT_00726a84 + 1;
        DAT_007263bc = DAT_007263bc & 0xfffffbff;
        FUN_004d1240();
        iVar1 = static_cast<int>(DAT_00726a84) + -1;
        DAT_007263bc = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(&DAT_007268f4) + iVar1 * 4);
        DAT_00726a84 = static_cast<uint32_t>(iVar1);
        *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0xc) = 0;
    }
    return static_cast<uint32_t>(iVar1) | 0x01000000;
}

extern int DAT_008e9fd8;
extern char DAT_008cac36;
extern uint32_t DAT_00727560;
extern uint32_t DAT_00727598;
extern uint32_t DAT_00726a84;
extern uint32_t DAT_007263bc;
extern uint32_t DAT_007268f4;
extern void* DAT_00727c30;
extern void* PTR_FUN_0070d038;
extern void* PTR_FUN_0070e93c;
extern void* PTR_LAB_00710bfc;
extern void* PTR_LAB_0070e99c;
extern void FUN_00535de0(int param);
extern void FUN_00535e10();
extern void FUN_00542700(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5);
extern void FUN_00542cb0(uint32_t param_1, void* param_2);
extern void FUN_00547730(void* param_1, const char* param_2, uint32_t param_3);
extern void FUN_004ff9a0();
extern void FUN_004ff930();
extern void FUN_0054a9f0();
extern void thunk_FUN_005f2abc();
extern void thunk_FUN_005f2148();
extern void FUN_004ff510(uint32_t param_1, uint32_t param_2);
extern void FUN_00547720();
extern void FUN_005be280(const char* param_1, uint32_t param_2, void* param_3);
extern void FUN_004d5330(int param_1);
extern void FUN_004d5590(void* param_1);
extern void* FUN_0054c210(uint32_t param_1, uint32_t param_2, void* param_3, uint32_t* param_4);
extern void FUN_00533db0(uint32_t param);
extern void FUN_00533d10(uint32_t param_1, uint32_t param_2);
extern void FUN_004d5480(int* param_1);
extern void* FUN_004d57d0();
extern void FUN_004aac50(int** param_1);
extern void FUN_00534130();
extern void FUN_00540c50();
extern void FUN_00540c90();
extern void FUN_004d4cb0();
extern void FUN_004d4f10(int* self);
extern void FUN_004d4e60(int* self);
extern void FUN_00412cb0();
extern void FUN_005022c0(uint32_t param);
extern void FUN_004d1240();
