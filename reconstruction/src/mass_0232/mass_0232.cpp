#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005de0e0();
extern void FUN_005de5f0();
extern void operator_delete(void* p);
extern uint32_t FUN_005f0ddc();

typedef void (__thiscall *VFunc0)(void* self);

// 0x5da9c0 — observed shape
void FUN_005da9c0(void* self) {
    int* piSelf = reinterpret_cast<int*>(self);
    (void)piSelf;
    void* vtable = *reinterpret_cast<void**>(self);
    auto f1 = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 0x8c);
    reinterpret_cast<void (__cdecl*)()>(f1)();
    auto f2 = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 0x9c);
    reinterpret_cast<void (__cdecl*)()>(f2)();
}

// 0x5daa30 — observed shape
void FUN_005daa30(void* self, int param_1) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x2288) = param_1;
    if (param_1 == 0) {
        int* piVar1 = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x2284);
        if (piVar1 != nullptr) {
            void* vtable = *reinterpret_cast<void**>(piVar1);
            auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 8);
            reinterpret_cast<void (__cdecl*)(int*)>(f)(piVar1);
        }
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x2284) = 0;
        return;
    }
    int* piVar1 = *reinterpret_cast<int**>(param_1 + 0x60);
    int* piVar2 = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x2284);
    if (piVar2 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar2);
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 8);
        reinterpret_cast<void (__cdecl*)(int*)>(f)(piVar2);
    }
    *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x2284) = piVar1;
    if (piVar1 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar1);
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 4);
        reinterpret_cast<void (__cdecl*)(int*)>(f)(piVar1);
    }
}

// 0x5dab60 — observed shape
void FUN_005dab60(void* self, int param_1) {
    int* in_ECX = reinterpret_cast<int*>(self);
    if ((*(reinterpret_cast<uint8_t*>(param_1 + 0x20)) & 1) == 0) {
        int iVar1 = *in_ECX;
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
        reinterpret_cast<void (__cdecl*)(int, int, int)>(f)(0x1c, 0, 0);
        return;
    }
    uint32_t uVar8 = 0x1c;
    {
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
        reinterpret_cast<void (__cdecl*)(int, int, int)>(f)(0x1c, 1, 0);
    }
    float fVar7 = 1.0f / (static_cast<float>(in_ECX[0x21]) * *reinterpret_cast<float*>(param_1 + 0x24));
    {
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
        reinterpret_cast<void (__cdecl*)(int, float, int)>(f)(0x26, fVar7, 0);
    }
    {
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
        reinterpret_cast<void (__cdecl*)(int, uint32_t, int)>(f)(0x24, uVar8, 0);
    }
    uint32_t* puVar6 = reinterpret_cast<uint32_t*>(0x25);
    {
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
        reinterpret_cast<void (__cdecl*)(int, float, int)>(f)(0x25, fVar7, 0);
    }
    uint8_t bVar2 = static_cast<uint8_t>(*(reinterpret_cast<uint8_t*>(param_1 + 0x20)) >> 1);
    if ((bVar2 & 3) == 0) {
        if ((*(reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 2)) & 1) != 0) {
            auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
            reinterpret_cast<void (__cdecl*)(int, int, int)>(f)(0x23, 3, 0);
            auto f2 = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
            reinterpret_cast<void (__cdecl*)(int, int, int)>(f2)(0x8c, 0, 0);
        }
        uVar8 = 0x30;
    } else {
        if ((bVar2 & 3) == 1) {
            if ((*(reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 2)) & 1) != 0) {
                auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
                reinterpret_cast<void (__cdecl*)(int, int, int)>(f)(0x23, 0, 0);
                auto f2 = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
                reinterpret_cast<void (__cdecl*)(int, int, int)>(f2)(0x8c, 3, 0);
            }
            auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
            reinterpret_cast<void (__cdecl*)(int, int, int)>(f)(0x30, 1, 0);
            goto LAB_005dac6f;
        }
        uVar8 = 0x1c;
    }
    {
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
        reinterpret_cast<void (__cdecl*)(int, uint32_t, int)>(f)(static_cast<int>(uVar8), 0, 0);
    }
LAB_005dac6f:
    if (((*reinterpret_cast<float*>(param_1 + 0x28) == static_cast<float>(in_ECX[0x24])) &&
         (*reinterpret_cast<float*>(param_1 + 0x2c) == static_cast<float>(in_ECX[0x25]))) &&
        (*reinterpret_cast<float*>(param_1 + 0x30) == static_cast<float>(in_ECX[0x26]))) {
        return;
    }
    int iVar1 = *in_ECX;
    uint32_t uVar3 = FUN_005f0ddc();
    uint32_t uVar4 = FUN_005f0ddc();
    uint32_t uVar5 = FUN_005f0ddc();
    uint32_t packed = ((((uVar3 & 0xffu) | 0xffffff00u) << 8 | (uVar4 & 0xffu)) << 8 | (uVar5 & 0xffu));
    {
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x70);
        reinterpret_cast<void (__cdecl*)(int, uint32_t)>(f)(0x22, packed);
    }
    (void)iVar1;
    // puVar6 holds the immediate 0x25 in the decompiler; the following writes mirror the observed store shape via the pointer.
    *puVar6 = *reinterpret_cast<uint32_t*>(param_1 + 0x28);
    puVar6[1] = *reinterpret_cast<uint32_t*>(param_1 + 0x2c);
    puVar6[2] = *reinterpret_cast<uint32_t*>(param_1 + 0x30);
}

// 0x5dbe60 — observed shape
void FUN_005dbe60(void* self, uint8_t param_1) {
    FUN_005de0e0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5dbea0 — observed shape
void FUN_005dbea0(void* self, uint8_t param_1) {
    FUN_005de5f0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

extern void FUN_005de8d0();
extern void FUN_005decc0();
extern uint8_t FUN_00568540(uint32_t param_1);
extern void FUN_00552e30(int param_1);
extern int* FUN_00540540(void* p);
extern void FUN_0051ac30(int* p);
extern void* FUN_00533c78(uint32_t size);
extern void FUN_00547c80();
extern void FUN_00547d40(void* p);
extern void FUN_00540860(void* p);
extern void operator_delete__(void* p);
extern void* PTR_s_NDL_UpdateTime_007187c8;
extern void* PTR_FUN_006c3878;
extern void* PTR_FUN_006c8c28;
extern void* DAT_00727dc0;

// 0x5dbf10 — observed shape
void FUN_005dbf10(void* self, uint8_t param_1) {
    FUN_005de8d0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5dc050 — observed shape
void FUN_005dc050(void* self, uint8_t param_1) {
    FUN_005decc0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5dd580 — observed shape
void FUN_005dd580(void* self, uint32_t param_1) {
    if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x34) != 0) &&
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x44) != 0)) {
        char cVar1 = static_cast<char>(FUN_00568540(param_1));
        if (cVar1 == '\0') {
            *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x44) + 0x10) = param_1;
        }
    }
}

// 0x5dd670 — observed shape
void FUN_005dd670(void* self, int param_1) {
    FUN_00552e30(param_1);
    if (param_1 != 0) {
        int* piVar2 = reinterpret_cast<int*>(FUN_00540540(PTR_s_NDL_UpdateTime_007187c8));
        if (piVar2 != nullptr) {
            uint32_t* puVar3 = nullptr;
            {
                void* vtable = *reinterpret_cast<void**>(piVar2);
                auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 4);
                puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<void* (__cdecl*)()>(f)());
            }
            for (; puVar3 != nullptr; puVar3 = reinterpret_cast<uint32_t*>(puVar3[1])) {
                if (puVar3 == reinterpret_cast<uint32_t*>(&DAT_00727dc0)) {
                    FUN_0051ac30(piVar2);
                    return;
                }
            }
        }
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x14));
        if (puVar3 == nullptr) {
            puVar3 = nullptr;
        } else {
            FUN_00547c80();
            *reinterpret_cast<void**>(puVar3) = PTR_FUN_006c3878;
            puVar3[4] = 0;
        }
        uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x44);
        if (puVar1 != puVar3) {
            if (puVar1 != nullptr) {
                int* piVar2b = reinterpret_cast<int*>(puVar1 + 1);
                *piVar2b = *piVar2b + -1;
                if (*piVar2b == 0) {
                    auto f = *reinterpret_cast<void**>(*reinterpret_cast<void**>(puVar1));
                    reinterpret_cast<void (__cdecl*)(int)>(f)(1);
                }
            }
            *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(self) + 0x44) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
        FUN_00547d40(PTR_s_NDL_UpdateTime_007187c8);
        FUN_00540860(*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x44));
    }
}

// 0x5dd780 — observed shape
void FUN_005dd780(void* self) {
    *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x2c) = PTR_FUN_006c8c28;
    operator_delete__(*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x30));
}

extern int DAT_00728ee4;
extern int DAT_007187a0;
extern void* PTR_LAB_006c92d8;
extern void FUN_005606f0(int a, int* b);
extern void FUN_005dd840();
extern uint32_t FUN_00571ce0(void* p);

// 0x5dd7a0 — observed shape
int FUN_005dd7a0(void* self, int param_1) {
    int iVar3 = param_1;
    int* piVar6 = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x30);
    int iVar1 = piVar6[param_1];
    int iVar4 = 0;
    if (iVar1 != 0) {
        iVar4 = *reinterpret_cast<int*>(iVar1 + 0x14);
        if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x20) - iVar4 ==
             *reinterpret_cast<int*>(iVar1 + 0xc)) &&
            (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20) = 0, param_1 != 0)) {
            do {
                int iVar2 = *piVar6;
                if ((iVar2 != 0) &&
                    (static_cast<uint32_t>(*reinterpret_cast<int*>(iVar2 + 0x14) +
                                            *reinterpret_cast<int*>(iVar2 + 0xc)) >
                     *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20))) {
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20) =
                        *reinterpret_cast<int*>(iVar2 + 0x14) + *reinterpret_cast<int*>(iVar2 + 0xc);
                }
                piVar6 = piVar6 + 1;
                param_1 = param_1 + -1;
            } while (param_1 != 0);
        }
        *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x28) =
            *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x28) + iVar4;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x24) =
            *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0xc) -
            *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x20);
        param_1 = 0;
        FUN_005606f0(iVar3, &param_1);
        *reinterpret_cast<uint32_t*>(iVar1 + 0x1c) = 0;
        *reinterpret_cast<int*>(iVar1 + 0x18) = DAT_00728ee4;
        if (DAT_00728ee4 != 0) {
            *reinterpret_cast<int*>(DAT_00728ee4 + 0x1c) = iVar1;
        }
        DAT_00728ee4 = iVar1;
    }
    return iVar4;
}

// 0x5dd840 — observed shape
void FUN_005dd840_recon() {
    uint32_t* puVar1 = nullptr;
    uint32_t uVar2 = 0;
    if (DAT_007187a0 != 0) {
        do {
            puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x20));
            if (puVar1 == nullptr) {
                puVar1 = nullptr;
            } else {
                puVar1[0] = 0;
                puVar1[1] = 0;
                puVar1[2] = 0;
                puVar1[3] = 0;
                puVar1[5] = 0;
                puVar1[4] = 0;
                puVar1[6] = 0;
                puVar1[7] = 0;
            }
            if (DAT_00728ee4 != 0) {
                reinterpret_cast<uint32_t*>(DAT_00728ee4)[7] = reinterpret_cast<uint32_t>(puVar1);
            }
            puVar1[6] = DAT_00728ee4;
            puVar1[7] = 0;
            uVar2 = uVar2 + 1;
            DAT_00728ee4 = reinterpret_cast<int>(puVar1);
        } while (uVar2 < static_cast<uint32_t>(DAT_007187a0));
    }
}

// 0x5dd8b0 — observed shape
void FUN_005dd8b0_recon() {
    void* pvVar2 = reinterpret_cast<void*>(DAT_00728ee4);
    while (pvVar2 != nullptr) {
        void* pvVar1 = *reinterpret_cast<void**>(reinterpret_cast<char*>(pvVar2) + 0x18);
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(pvVar2) + 8) = 0;
        operator_delete(pvVar2);
        pvVar2 = pvVar1;
    }
    DAT_00728ee4 = 0;
}

// 0x5dd8e0 — observed shape
uint32_t* FUN_005dd8e0(void* self, uint32_t* param_1) {
    uint32_t uVar1 = reinterpret_cast<uint32_t>(param_1);
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x24) < uVar1) {
        return nullptr;
    }
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(DAT_00728ee4);
    if (DAT_00728ee4 == 0) {
        FUN_005dd840();
        puVar3 = reinterpret_cast<uint32_t*>(DAT_00728ee4);
    }
    DAT_00728ee4 = static_cast<int>(reinterpret_cast<uint32_t>(puVar3[6]));
    if (DAT_00728ee4 != 0) {
        *reinterpret_cast<uint32_t*>(DAT_00728ee4 + 0x1c) = 0;
    }
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[1] = reinterpret_cast<uint32_t>(self);
    puVar3[2] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 8);
    puVar3[3] = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20);
    puVar3[5] = uVar1;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x24) =
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x24) - uVar1;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x28) =
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x28) - uVar1;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20) =
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x20) + uVar1;
    param_1 = puVar3;
    uint32_t uVar2 = FUN_00571ce0(&param_1);
    *reinterpret_cast<uint32_t*>(puVar3) = uVar2;
    return puVar3;
}

// 0x5dd980 — observed shape
void FUN_005dd980(void* self) {
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006c92d8);
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
}

extern void FUN_005d0650();

// 0x5dd9a0 — observed shape
void FUN_005dd9a0(void* self) {
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006c92d8);
    int* piVar1 = reinterpret_cast<int*>(in_ECX[3]);
    if (piVar1 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar1);
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 8);
        reinterpret_cast<void (__cdecl*)(int*)>(f)(piVar1);
    }
}

// 0x5dd9c0 — observed shape
void FUN_005dd9c0(void* self, uint8_t param_1) {
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    int* piVar1 = reinterpret_cast<int*>(in_ECX[3]);
    in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006c92d8);
    if (piVar1 != nullptr) {
        void* vtable = *reinterpret_cast<void**>(piVar1);
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 8);
        reinterpret_cast<void (__cdecl*)(int*)>(f)(piVar1);
    }
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5dd9f0 — observed shape
void FUN_005dd9f0(void* self, int param_1) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 4) =
        *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 4) + 1;
    *reinterpret_cast<int*>(param_1 + 4) = reinterpret_cast<int>(self);
}

// 0x5dda00 — observed shape
void FUN_005dda00(void* self, int param_1) {
    int* in_ECX = reinterpret_cast<int*>(self);
    in_ECX[1] = in_ECX[1] + -1;
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0x14);
    uint32_t uVar2 = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 4) = 0;
    if (uVar1 != 0) {
        do {
            auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(in_ECX)) + 0x24);
            reinterpret_cast<void (__cdecl*)(int, uint32_t)>(f)(param_1, uVar2);
            uVar2 = uVar2 + 1;
        } while (uVar2 < uVar1);
    }
    FUN_005d0650();
}

// 0x5dda40 — observed shape
uint32_t FUN_005dda40(void* self, uint32_t param_1, int* param_2, uint32_t* param_3, char param_4) {
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 8) < param_1) {
        int* piVar1 = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x10);
        if (piVar1 != nullptr) {
            void* vtable = *reinterpret_cast<void**>(piVar1);
            auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 8);
            reinterpret_cast<void (__cdecl*)(int*)>(f)(piVar1);
        }
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x10) = 0;
        uint32_t uVar2 = param_1;
        if ((param_1 & 0xf) != 0) {
            uVar2 = (param_1 & 0xfffffff0u) + 0x20;
        }
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 8) = uVar2;
    }
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x10) == 0) {
        int* pObj = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0xc);
        void* vtable = *reinterpret_cast<void**>(pObj);
        auto f = *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 0x68);
        int iVar3 = reinterpret_cast<int (__cdecl*)(int*, uint32_t, int, uint32_t, int, uint32_t*, int)>(f)(
            pObj,
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 8),
            0x208,
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 4),
            0,
            reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x10),
            0);
        if (-1 < iVar3) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x14) = 0;
        }
    }
    if ((param_4 == '\0') &&
        (param_1 <= *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 8) -
                       *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14))) {
        *param_2 = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14) =
            *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x14) +
            static_cast<int>(param_1);
        *param_3 = 0x1000;
    } else {
        *param_2 = 0;
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x14) = param_1;
        *param_3 = 0x2000;
    }
    if (*param_2 == 0) {
        *param_3 = 0x2000;
    }
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x10);
}
