#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_0053c7c0(float);
extern void FUN_004bf940(uint32_t, void*);
extern void FUN_004bf8c0(uint32_t, void*);
extern void FUN_004c0480();
extern int FUN_00533db0(int);
extern int FUN_00533c78(int);
extern void* FUN_005428c0();
extern int FUN_004aac50(void**);
extern int FUN_004aad70(uint32_t);
extern void FUN_00534130();
extern void FUN_00491640();

// 0x4bcd30 — observed shape
void FUN_004bcd30(void* self, int param_1) {
    char* obj = static_cast<char*>(self);
    int inner;
    if (*reinterpret_cast<int*>(obj + 0xBC) != 0) {
        FUN_004bcd30(self, param_1);
    }
    inner = *reinterpret_cast<int*>(obj + 0x1C);
    FUN_0053c7c0((float)param_1 * 1.4629181e-09f);
    unsigned char local_24[36];
    FUN_004bf940(inner, local_24);
    FUN_004bf8c0(inner, local_24);
}

// 0x4bd600 — observed shape
void FUN_004bd600(void* self, uint32_t in_EAX) {
    char* obj = static_cast<char*>(self);
    // in_EAX is explicit selfAlias per listing; both receiver forms observed
    int inner = *reinterpret_cast<int*>(obj + 0x1C);
    if (*(int*)(inner + 0xC0) == 0) {
        FUN_004c0480();
        return;
    }
    FUN_004c0480();
}

// 0x4bd640 — observed shape
void FUN_004bd640(uint32_t param_1) {
    int iVar2 = FUN_00533db0(8);
    if (iVar2 == 0) {
        iVar2 = FUN_00533c78(0x48);
        uint32_t* puVar3;
        if (iVar2 == 0) {
            puVar3 = nullptr;
        } else {
            puVar3 = static_cast<uint32_t*>(FUN_005428c0());
        }
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
        uint32_t* local_4 = puVar3;
        FUN_004aac50(reinterpret_cast<void**>(&local_4));
        if (puVar3 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar3));
                f(1);
            }
        }
        FUN_00534130();
    }
    FUN_004aad70(param_1);
}

// 0x4bd700 — observed shape
void FUN_004bd700(void* self, uint param_2, uint32_t param_3, uint32_t param_4) {
    char* obj = static_cast<char*>(self);
    *reinterpret_cast<uint32_t*>(obj + 0x6C) = param_2;
    *reinterpret_cast<uint32_t*>(obj + 0x70) = param_3;
    *reinterpret_cast<uint32_t*>(obj + 0x74) = param_4;
    FUN_00491640();
    int outer = *reinterpret_cast<int*>(obj + 0x84);
    if (outer != 0) {
        uint idx = 0;
        if (*(int*)(outer + 0xC) != 0) {
            do {
                unsigned char* puVar1 = *reinterpret_cast<unsigned char**>(*(int*)(outer + 4) + idx * 4);
                if (puVar1 != nullptr) {
                    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(obj + 0x70);
                    uint32_t uVar3 = *reinterpret_cast<uint32_t*>(obj + 0x74);
                    *reinterpret_cast<uint32_t*>(puVar1 + 0x14) = *reinterpret_cast<uint32_t*>(obj + 0x6C);
                    *reinterpret_cast<uint32_t*>(puVar1 + 0x18) = uVar2;
                    *reinterpret_cast<uint32_t*>(puVar1 + 0x1C) = uVar3;
                    FUN_00491640();
                    *puVar1 = 1;
                }
                idx = idx + 1;
            } while (idx < *(uint*)(outer + 0xC));
        }
    }
}

// 0x4bd7a0 — observed shape
void FUN_004bd7a0(void* self, float param_1) {
    char* obj = static_cast<char*>(self);
    int iVar9 = *reinterpret_cast<int*>(obj + 0x84);
    if ((iVar9 != 0) && (*(int*)(iVar9 + 0xC) != 0)) {
        int iVar4 = **reinterpret_cast<int**>(iVar9 + 4);
        float fVar5 = *reinterpret_cast<float*>(iVar4 + 0x14);
        float fVar1 = *reinterpret_cast<float*>(obj + 0x6C);
        float fVar6 = *reinterpret_cast<float*>(iVar4 + 0x18);
        float fVar7 = *reinterpret_cast<float*>(iVar4 + 0x1C);
        float fVar2 = *reinterpret_cast<float*>(obj + 0x70);
        float fVar3 = *reinterpret_cast<float*>(obj + 0x74);
        uint uVar10 = 0;
        if (*(int*)(iVar9 + 0xC) != 0) {
            do {
                unsigned char* puVar8 = *reinterpret_cast<unsigned char**>(*(int*)(iVar9 + 4) + uVar10 * 4);
                if (puVar8 != nullptr) {
                    *reinterpret_cast<float*>(puVar8 + 0x14) = fVar5 - (fVar5 - fVar1) * param_1;
                    *reinterpret_cast<float*>(puVar8 + 0x18) = fVar6 - (fVar6 - fVar2) * param_1;
                    *reinterpret_cast<float*>(puVar8 + 0x1C) = fVar7 - (fVar7 - fVar3) * param_1;
                    FUN_00491640();
                    *puVar8 = 1;
                }
                iVar9 = *reinterpret_cast<int*>(obj + 0x84);
                uVar10 = uVar10 + 1;
            } while (uVar10 < *(uint*)(iVar9 + 0xC));
        }
    }
}

extern int FUN_00540540(const char*);
extern int FUN_00449390(void*, int);
extern uint32_t FUN_005dbd70(const char*);
extern void FUN_004b97c0(const char*, ...);
extern int _strnicmp(const char*, const char*, size_t);
extern int DAT_00727890;
extern int DAT_00727560;
extern int DAT_00727598;
extern int PTR_FUN_00711680;
extern void* FUN_00533c78(int);
extern void FUN_00491640();
extern void* FUN_0050d070(int*);
extern void FUN_004f5670();
extern void FUN_004f5720();
extern void FUN_005016d0(int*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern unsigned char DAT_007263b9;
extern unsigned char DAT_007263bc;
extern int DAT_008c97d0;
extern void FUN_004c30a0();
extern void FUN_0050d2f0();
extern void operator_delete(void*);
extern void FUN_004bdc40();
extern void* FUN_0050ee00(const char*);

// 0x4bd880 — observed shape
void FUN_004bd880(int* param_1) {
    char* _Str1;
    int iVar1 = FUN_00540540("UserPropBuffer");
    if (iVar1 != 0) {
        iVar1 = FUN_00449390(&DAT_00727890, iVar1);
        _Str1 = *reinterpret_cast<char**>(iVar1 + 0x10);
        iVar1 = param_1[3];
        uint32_t uVar2 = FUN_005dbd70(_Str1);
        FUN_004b97c0("%s / %s / %s", iVar1, uVar2);
        iVar1 = _strnicmp(_Str1, "CastShadow", 10);
        if (iVar1 == 0) {
            FUN_004bd940(param_1);
        }
    }
    if (param_1 != nullptr) {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<void*(**)(void)>(*reinterpret_cast<uint32_t*>((*param_1) + 4))());
        if (puVar3 != nullptr) {
            while (puVar3 != reinterpret_cast<uint32_t*>(&DAT_00727560)) {
                puVar3 = reinterpret_cast<uint32_t*>(puVar3[1]);
                if (puVar3 == nullptr) {
                    return;
                }
            }
            uint uVar4 = 0;
            if (param_1[0x30] != 0) {
                if (param_1[0x30] != 0) {
                    do {
                        iVar1 = *reinterpret_cast<int*>(param_1[0x2E] + uVar4 * 4);
                        if (iVar1 != 0) {
                            FUN_004bd880(reinterpret_cast<int*>(iVar1));
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < static_cast<uint>(param_1[0x30]));
                }
            }
        }
    }
}

// 0x4bd940 — observed shape
void FUN_004bd940(int* param_1) {
    char* in_ECX;
    // Receiver preserved as self alias; in_ECX used in observed listing
    if (param_1 != nullptr) {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<void*(**)(void)>(*reinterpret_cast<uint32_t*>((*param_1) + 4))());
        while (puVar3 != nullptr) {
            if (puVar3 == reinterpret_cast<uint32_t*>(&DAT_00727598)) {
                if (*(int*)(reinterpret_cast<int>(in_ECX) + 0x84) == 0) {
                    puVar3 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x18));
                    if (puVar3 == nullptr) {
                        puVar3 = nullptr;
                    } else {
                        *puVar3 = PTR_FUN_00711680;
                        puVar3[2] = 0;
                        puVar3[5] = 1;
                        puVar3[3] = 0;
                        puVar3[4] = 0;
                        puVar3[1] = 0;
                    }
                    *reinterpret_cast<uint32_t**>(reinterpret_cast<int>(in_ECX) + 0x84) = puVar3;
                }
                int iVar4 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x68)));
                unsigned char* puVar5;
                if (iVar4 == 0) {
                    puVar5 = nullptr;
                } else {
                    puVar5 = static_cast<unsigned char*>(FUN_0050d070(param_1));
                }
                uint32_t uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<int>(in_ECX) + 0x70);
                uint32_t uVar2 = *reinterpret_cast<uint32_t*>(reinterpret_cast<int>(in_ECX) + 0x74);
                *reinterpret_cast<uint32_t*>(puVar5 + 0x14) = *reinterpret_cast<uint32_t*>(reinterpret_cast<int>(in_ECX) + 0x6C);
                *reinterpret_cast<uint32_t*>(puVar5 + 0x18) = uVar1;
                *reinterpret_cast<uint32_t*>(puVar5 + 0x1C) = uVar2;
                FUN_00491640();
                *puVar5 = 1;
                *reinterpret_cast<uint32_t*>(puVar5 + 4) = 0x3f000000;
                if (*(uint*)(*(int*)(reinterpret_cast<int>(in_ECX) + 0x84) + 8) <= *(uint*)(*(int*)(reinterpret_cast<int>(in_ECX) + 0x84) + 0xC)) {
                    FUN_004f5670();
                }
                FUN_004f5720();
                FUN_005016d0(param_1, 0x4000, 0xffffffff, 0x33, 0, 0, 0);
                return;
            }
            puVar3 = reinterpret_cast<uint32_t*>(puVar3[1]);
        }
        puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<void*(**)(void)>(*reinterpret_cast<uint32_t*>((*param_1) + 4))());
        if (puVar3 != nullptr) {
            while (puVar3 != reinterpret_cast<uint32_t*>(&DAT_00727560)) {
                puVar3 = reinterpret_cast<uint32_t*>(puVar3[1]);
                if (puVar3 == nullptr) {
                    return;
                }
            }
            uint uVar6 = 0;
            if (param_1[0x30] != 0) {
                if (param_1[0x30] != 0) {
                    do {
                        int iVar4 = *reinterpret_cast<int*>(param_1[0x2E] + uVar6 * 4);
                        if (iVar4 != 0) {
                            FUN_004bd940(reinterpret_cast<int*>(iVar4));
                        }
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < static_cast<uint>(param_1[0x30]));
                }
            }
        }
    }
}

// 0x4bdaa0 — observed shape
void FUN_004bdaa0(int param_1) {
    uint uVar1;
    if ((((DAT_007263b9 != '\0') && (((unsigned char)DAT_007263bc & 0x20) != 0)) &&
         (*(int*)(param_1 + 0x84) != 0)) &&
        ((*(int*)(param_1 + 0x90) == 0 && (uVar1 = 0, *(int*)(*(int*)(param_1 + 0x84) + 0xC) != 0)))) {
        do {
            if (*(uint*)(*(int*)(DAT_008c97d0 + 0x20) + 8) <= *(uint*)(*(int*)(DAT_008c97d0 + 0x20) + 0xC)) {
                FUN_004f5670();
            }
            FUN_004f5720();
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint*)(*(int*)(param_1 + 0x84) + 0xC));
    }
}

// 0x4bdb30 — observed shape
uint32_t FUN_004bdb30(void* self, int in_EDX) {
    int iVar2 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x84);
    if (iVar2 != 0) {
        uint uVar7 = 0;
        if (*(uint*)(iVar2 + 0xC) != 0) {
            uint32_t* puVar6 = *reinterpret_cast<uint32_t**>(iVar2 + 4);
            do {
                void* pvVar3 = reinterpret_cast<void*>(*puVar6);
                if (*(int*)((int)reinterpret_cast<intptr_t>(pvVar3) + 8) == in_EDX) {
                    FUN_004c30a0();
                    iVar2 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x84);
                    if (uVar7 < *(uint*)(iVar2 + 0xC)) {
                        uint iVar1 = *(uint*)(iVar2 + 0xC) - 1;
                        int iVar4 = *(int*)(iVar2 + 4);
                        *(uint*)(iVar2 + 0xC) = iVar1;
                        int iVar5 = *(int*)(iVar4 + uVar7 * 4);
                        *(uint32_t*)(iVar4 + uVar7 * 4) = *(uint32_t*)(iVar4 + iVar1 * 4);
                        *(uint32_t*)(*(int*)(iVar2 + 4) + *(int*)(iVar2 + 0xC) * 4) = 0;
                        if (iVar5 != 0) {
                            *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) + -1;
                        }
                    }
                    FUN_0050d2f0();
                    operator_delete(pvVar3);
                    return 1;
                }
                uVar7 = uVar7 + 1;
                puVar6 = puVar6 + 1;
            } while (uVar7 < *(uint*)(iVar2 + 0xC));
        }
    }
    return 0;
}

// 0x4bdbc0 — observed shape
void FUN_004bdbc0(int param_1) {
    int* in_EAX;
    if (*(int*)(param_1 + 0x68) != 0) {
        FUN_004bdc40();
    }
    int iVar1 = reinterpret_cast<int(*)(const char*)>(*reinterpret_cast<uint32_t*>((*in_EAX) + 0x40))("fx_dummy_trail_top");
    int iVar2 = reinterpret_cast<int(*)(const char*)>(*reinterpret_cast<uint32_t*>((*in_EAX) + 0x40))("fx_dummy_trail_bottom");
    if ((iVar1 != 0) && (iVar2 != 0)) {
        iVar1 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x60)));
        if (iVar1 != 0) {
            uint32_t uVar3 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(FUN_0050ee00("fx_sword_trail.dds")));
            *(uint32_t*)(param_1 + 0x68) = uVar3;
            return;
        }
        *(uint32_t*)(param_1 + 0x68) = 0;
    }
}

extern void FUN_004c3000();
extern void FUN_0050f1e0();
extern DWORD GetCurrentThreadId();
extern uint32_t FUN_004baae0(uint32_t);
extern uint32_t FUN_004be3f0(int, char*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern uint32_t FUN_004be0c0(char*);
extern uint32_t FUN_004bdfc0();
extern uint32_t FUN_004bde20(char*);
extern uint32_t FUN_004baca0();
extern uint32_t* FUN_00533c78(int);
extern uint32_t FUN_004bdca0(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int DAT_00727444;
extern int PTR_FUN_006fd14c;
extern void FUN_004b1260(uint32_t);
extern void* FUN_00508e20(int, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int DAT_008c9ddc;
extern void* FUN_0053bb30(uint32_t);
extern void FUN_00533d10(uint32_t, uint32_t);
extern void FUN_00534350();
extern void FUN_00534130();
extern void FUN_0050a350();
extern void* FUN_00500600();
extern uint32_t FUN_004c0570(uint32_t);
extern void FUN_005006e0(uint32_t);
extern void* FUN_004c3150();
extern int DAT_008cabfc;
extern int PTR_FUN_0070d030;
extern char LAB_004bdf20;

// 0x4bdc40 — observed shape
uint32_t FUN_004bdc40(void* self, int in_ECX) {
    int iVar1 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x68);
    if (((iVar1 == 0) || (in_ECX == 0)) ||
        ((*(int*)(iVar1 + 0x1C) != in_ECX && (*(int*)(iVar1 + 0x20) != in_ECX)))) {
        return 0;
    }
    if ((*(char*)(iVar1 + 0x18) != '\0') && (*(char*)(iVar1 + 0x18) != '\0')) {
        *(unsigned char*)(iVar1 + 0x18) = 0;
    }
    FUN_004c3000();
    void* pvVar2 = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x68);
    if (pvVar2 != nullptr) {
        FUN_0050f1e0();
        operator_delete(pvVar2);
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x68) = 0;
    }
    return 1;
}

// 0x4bdca0 — observed shape
uint FUN_004bdca0(char* in_EAX, int in_ECX, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t in_EBX, uint32_t param_7, uint32_t param_8, uint32_t param_9, uint32_t param_10) {
    GetCurrentThreadId();
    FUN_004baae0(static_cast<uint32_t>(reinterpret_cast<intptr_t>(in_EAX)));
    *reinterpret_cast<uint*>(in_ECX + 0x20) = in_EBX & 0xfffffffe;
    uint uVar2;
    if (in_EAX == nullptr) {
        uVar2 = FUN_004be3f0(in_ECX, in_EAX, param_2, param_3, param_4, param_5, param_6, in_EBX, param_7, param_8, param_9, param_10);
    } else {
        char* pcVar1 = in_EAX;
        char* pcVar3;
        do {
            pcVar3 = pcVar1;
            pcVar1 = pcVar3 + 1;
        } while (*pcVar3 != '\0');
        uVar2 = *(uint*)(pcVar3 + -4) & 0xdfdfdfff;
        if ((int)uVar2 < 0x4d464b2f) {
            if (uVar2 == 0x4d464b2e) {
                *(uint*)(in_ECX + 0x20) = in_EBX;
                uVar2 = FUN_004be0c0(in_EAX);
                goto LAB_004bdd78;
            }
            if ((uVar2 == 0) || (uVar2 == 0x4147542e)) {
                uVar2 = FUN_004be3f0(in_ECX, in_EAX, param_2, param_3, param_4, param_5, param_6, in_EBX, param_7, param_8, param_9, param_10);
                goto LAB_004bdd78;
            }
            if (uVar2 == 0x46494e2e) {
                *(uint*)(in_ECX + 0x20) = in_EBX;
                uVar2 = FUN_004bdfc0();
                goto LAB_004bdd78;
            }
        } else if ((uVar2 == 0x5344442e) || (uVar2 == 0x5843502e)) {
            uVar2 = FUN_004be3f0(in_ECX, in_EAX, param_2, param_3, param_4, param_5, param_6, in_EBX, param_7, param_8, param_9, param_10);
            goto LAB_004bdd78;
        }
        uVar2 = FUN_004bde20(in_EAX);
    }
LAB_004bdd78:
    if ((*(unsigned char*)(in_ECX + 0x20) & 1) == 0) {
        uVar2 = FUN_004baca0();
    }
    return uVar2 & 0xffffff00;
}

// 0x4bdd90 — observed shape
uint32_t FUN_004bdd90(int param_1) {
    uint32_t* puVar4 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    if (puVar4 == nullptr) {
        puVar4 = nullptr;
    } else {
        uint32_t uVar2 = *(uint32_t*)(param_1 + 0x18);
        puVar4[1] = 0;
        *puVar4 = PTR_FUN_006fd14c;
        puVar4[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar4[0x19] = 0;
        puVar4[0x2f] = 0;
        FUN_004bdca0(uVar2, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(param_1 + 0xBC);
    if (puVar3 != puVar4) {
        if (puVar3 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar3));
                f(1);
            }
        }
        *reinterpret_cast<uint32_t**>(param_1 + 0xBC) = puVar4;
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    return 1;
}

// 0x4bde20 — observed shape
uint32_t FUN_004bde20(char* in_EAX_unused, uint32_t param_1, void* self) {
    uint32_t local_10 = 0, local_c = 0, local_8 = 0, local_4 = 0;
    FUN_004b1260(static_cast<uint32_t>(reinterpret_cast<intptr_t>(in_EAX_unused)));
    void* pvVar4 = FUN_00508e20(DAT_008c9ddc, 0, 0, 0, param_1, 0xc, local_10, local_c, local_8, local_4);
    uint32_t uVar2 = *(uint32_t*)((int)reinterpret_cast<intptr_t>(pvVar4) + 0x34);
    int iVar5 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0xec)));
    uint32_t* puVar6;
    if (iVar5 == 0) {
        puVar6 = nullptr;
    } else {
        puVar6 = static_cast<uint32_t*>(FUN_0053bb30(0));
    }
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x1C);
    if (puVar3 != puVar6) {
        if (puVar3 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar3));
                f(1);
            }
        }
        *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x1C) = puVar6;
        if (puVar6 != nullptr) {
            puVar6[1] = puVar6[1] + 1;
        }
    }
    auto f = reinterpret_cast<void(__cdecl*)(uint32_t, uint32_t)>(*reinterpret_cast<uint32_t*>(*(int*)(*(int*)(static_cast<char*>(self) + 0x1C) + 0x70)));
    f(uVar2, 1);
    FUN_00533d10(0, 1);
    FUN_00534350();
    FUN_00534130();
    FUN_0050a350();
    operator_delete(pvVar4);
    return 1;
}

// 0x4bdfc0 — observed shape
uint32_t FUN_004bdfc0(void* self) {
    char* obj = static_cast<char*>(self);
    if ((*(unsigned char*)(reinterpret_cast<int>(obj) + 0x20) & 1) == 0) {
        uint32_t* puVar4 = static_cast<uint32_t*>(FUN_00500600());
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<int>(obj) + 0x1C);
        if (puVar2 != puVar4) {
            if (puVar2 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar2));
                    f(1);
                }
            }
            *reinterpret_cast<uint32_t**>(reinterpret_cast<int>(obj) + 0x1C) = puVar4;
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
        if (*(float*)(reinterpret_cast<int>(obj) + 0x2C) == 0.0f) {
            uint32_t tmp = FUN_004c0570(*(uint32_t*)(reinterpret_cast<int>(obj) + 0x1C));
            *reinterpret_cast<float*>(reinterpret_cast<int>(obj) + 0x2C) = static_cast<float>(tmp);
        }
        return 1;
    }
    uint32_t* puVar2 = static_cast<uint32_t*>(FUN_00533c78(0x14));
    if (puVar2 == nullptr) {
        puVar2 = nullptr;
    } else {
        puVar2[2] = 0;
        *puVar2 = PTR_FUN_0070d030;
        puVar2[4] = 0;
        InterlockedIncrement(&DAT_008cabfc);
    }
    *reinterpret_cast<uint32_t**>(reinterpret_cast<int>(obj) + 0x50) = puVar2;
    *reinterpret_cast<char**>(*(int*)(reinterpret_cast<int>(obj) + 0x50) + 4) = &LAB_004bdf20;
    int iVar3 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0xc)));
    uint32_t* puVar2b;
    if (iVar3 == 0) {
        puVar2b = nullptr;
    } else {
        puVar2b = static_cast<uint32_t*>(FUN_004c3150());
    }
    iVar3 = *(int*)(reinterpret_cast<int>(obj) + 0x50);
    uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(iVar3 + 8);
    if (puVar4 != puVar2b) {
        if (puVar4 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar4));
                f(1);
            }
        }
        *reinterpret_cast<uint32_t**>(iVar3 + 8) = puVar2b;
        if (puVar2b != nullptr) {
            puVar2b[1] = puVar2b[1] + 1;
        }
    }
    *(uint32_t*)(*(int*)(reinterpret_cast<int>(obj) + 0x50) + 0xC) = 0;
    *(int*)(*(int*)(reinterpret_cast<int>(obj) + 0x50) + 0x10) = reinterpret_cast<int>(obj);
    FUN_005006e0(*(uint32_t*)(reinterpret_cast<int>(obj) + 0x50));
    return 1;
}

extern void* FUN_005716a0(int);
extern void FUN_00572020(int, uint32_t, int);
extern uint32_t FUN_004be140();
extern void FUN_00571600(void*, void**);
extern void FUN_004bf420();
extern uint32_t FUN_004c2380();
extern char FUN_00506550(void*);
extern int FUN_00571a60(uint32_t, int*);
extern int FUN_00571aa0(uint32_t, void*, void*);
extern void FUN_00571140(void**, uint32_t, uint32_t);
extern uint32_t FUN_004b9f20(void*, uint32_t);
extern void FUN_004c2510(uint32_t, uint32_t);
extern int FUN_004cddf0(char*, uint32_t, uint32_t, int*, void**);
extern void* FUN_00533c78(int);
extern void* FUN_005428c0();
extern int FUN_004aac50(void**);
extern void* FUN_005426d0();
extern void FUN_005606f0(uint32_t, void**);
extern void FUN_004aacc0(uint32_t);
extern void FUN_00540c50();
extern void* FUN_0053bb30(uint32_t);
extern void FUN_00533d10(uint32_t, uint32_t);
extern void FUN_00534350();
extern void* FUN_005473e0(int, void*, int, void*, void*, int, int, int, int, void*, void*);
extern int PTR_FUN_0070bf10;
extern int PTR_FUN_0070bf4c;
extern int DAT_00727854;
extern int FUN_004bb4b0(int);
extern void FUN_004bb840(int, int);
extern void FUN_00548120(int, void*);
extern int DAT_008e8fdc;
extern int DAT_008c9df4;
extern char PTR_DAT_007082c4;

// 0x4be0c0 — observed shape
uint32_t FUN_004be0c0(void* self, uint32_t param_1) {
    int iVar3 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x3c)));
    uint32_t* puVar4;
    if (iVar3 == 0) {
        puVar4 = nullptr;
    } else {
        puVar4 = static_cast<uint32_t*>(FUN_005716a0(1));
    }
    int in_EAX = reinterpret_cast<int>(self);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(in_EAX + 100);
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar2));
                f(1);
            }
        }
        *reinterpret_cast<uint32_t**>(in_EAX + 100) = puVar4;
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    FUN_00572020(0, param_1, 0);
    FUN_004bdfc0();
    if (((*(uint*)(in_EAX + 0x20) & 0x10000) != 0) && ((*(uint*)(in_EAX + 0x20) & 1) == 0)) {
        FUN_004be140();
    }
    return 1;
}

// 0x4be140 — observed shape
void FUN_004be140(uint param_1, uint32_t param_2) {
    // Ghidra WARNING blocks removed unreachable code; observed structure preserved
    if ((*(int*)(param_1 + 0x1C) != 0) && (*(int*)(param_1 + 100) != 0)) {
        int iVar7 = *(int*)(param_1 + 100);
        int local_8[2];
        local_8[0] = iVar7;
        FUN_004b97c0("ModelPath = %s", *(uint32_t*)(iVar7 + 8));
        FUN_004b97c0("ModelRoot = %s", *(uint32_t*)(iVar7 + 0xC));
        const char* pcVar4 = "true";
        if (*(char*)(iVar7 + 0x30) == '\0') {
            pcVar4 = "false";
        }
        FUN_004b97c0("DefaultPaths = %s", pcVar4);
        FUN_004b97c0("DefaultKFPath = %s", *(uint32_t*)(iVar7 + 0x38));
        FUN_004b97c0("DefaultNIFPath = %s", *(uint32_t*)(iVar7 + 0x34));
        uint32_t local_20 = 0;
        void* pvStack_10 = nullptr;
        // FUN_00571600 fills local_20 / pvStack_10 area in original
        // Signature approximated from observed call
        extern void FUN_00571600_expanded(void*, uint32_t*);
        (void)pvStack_10;
        if (*(int*)(param_1 + 0xA4) == 0) {
            int iVar5 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x10)));
            uint32_t uVar6;
            if (iVar5 == 0) {
                uVar6 = 0;
            } else {
                FUN_004bf420();
                uVar6 = FUN_004c2380();
            }
            *(uint32_t*)(param_1 + 0xA4) = uVar6;
        }
        int iVar7b = reinterpret_cast<int(*)(uint32_t)>(*reinterpret_cast<uint32_t*>(*(int*)(*(int*)(param_1 + 0x1C) + 0x40)))(*(uint32_t*)(iVar7 + 0xC));
        *(int*)(param_1 + 0x60) = iVar7b;
        if (iVar7b != 0) {
            uint uVar8 = 0;
            // loop over count observed as uStack_28 == param_1 when param_1 != 0
            if (param_1 != 0) {
                do {
                    uint32_t uVar6 = local_20; // placeholder for varargs array element
                    (void)uVar6;
                    // The original iterates over an array pointed to by pvStack_10/local_20
                    // using FUN_00506550 etc. Preserve the call sequence as observed:
                    unsigned char uStack00000000 = 0;
                    char cVar3 = FUN_00506550(&uStack00000000);
                    // Further body (FUN_00571a60 etc.) is elided in the abbreviated listing
                    // but retained in structure via the available ranges 89-104:
                    (void)cVar3;
                    uVar8 = uVar8 + 1;
                } while (uVar8 < param_1);
            }
            operator_delete(pvStack_10);
        }
    }
}


// 0x4be9c0 — observed shape
void FUN_004be9c0(int in_ECX, int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, int param_11, int param_12, int param_13, int param_14, int param_15, int param_16, int param_17, int param_18, int param_19, int param_20, uint32_t param_21, uint32_t param_22, uint32_t param_23, uint32_t param_24) {
    int iVar5 = FUN_004bb4b0(1);
    if (iVar5 != in_ECX) {
        FUN_004be9c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23, param_24);
        return;
    }
    FUN_004bb840(in_ECX, 100);
    uint32_t uVar6;
    if (*(int*)(*(int*)(in_ECX + 0x1C) + 0xC0) == 0) {
        uVar6 = 0;
    } else {
        uVar6 = **(uint32_t**)(*(int*)(in_ECX + 0x1C) + 0xB8);
    }
    int iVar7 = FUN_00449390(&DAT_00727854, uVar6);
    int iVar5b = *(int*)(iVar7 + 0xBC);
    uint32_t* puVar2 = *(uint32_t**)(iVar5b + 0x28);
    float* pfVar3 = *(float**)(iVar5b + 0x20);
    float* pfVar4 = *(float**)(iVar5b + 0x2C);
    extern uint32_t* FUN_004b1260_2(uint32_t);
    uint32_t* puVar8 = nullptr; (void)puVar8;
    // four matrix copies (16 floats total) from param_21..24 via FUN_004b1260
    pfVar3[3] = (float)param_1;
    pfVar3[4] = (float)param_2;
    pfVar3[5] = (float)param_3;
    *pfVar3 = (float)param_4;
    pfVar3[1] = (float)param_5;
    pfVar3[2] = (float)param_6;
    pfVar3[6] = (float)param_7;
    pfVar3[7] = (float)param_8;
    pfVar3[8] = (float)param_9;
    pfVar3[9] = (float)param_10;
    pfVar3[10] = (float)param_11;
    pfVar3[0x0B] = (float)param_12;
    pfVar4[2] = (float)param_13 * 0.001f;
    pfVar4[3] = 1.0f - (float)param_14 * 0.001f;
    *pfVar4 = (float)param_15 * 0.001f;
    pfVar4[1] = 1.0f - (float)param_16 * 0.001f;
    pfVar4[4] = (float)param_17 * 0.001f;
    pfVar4[5] = 1.0f - (float)param_18 * 0.001f;
    pfVar4[6] = (float)param_19 * 0.001f;
    pfVar4[7] = 1.0f - (float)param_20 * 0.001f;
    FUN_00548120(4, pfVar3);
    iVar5b = *(int*)(iVar7 + 0xBC);
    extern int local_buf[4];
    // local_10..local_4 stored to iVar5+0x10..0x1c
    unsigned char* pbVar1 = reinterpret_cast<unsigned char*>(*(int*)(iVar7 + 0xBC) + 0x32);
    *pbVar1 = *pbVar1 | 0xD;
    *(uint*)(in_ECX + 0x20) = *(uint*)(in_ECX + 0x20) | 0x2000;
    *(unsigned char*)(in_ECX + 0x24) = 1;
}

// 0x4bed70 — observed shape
void FUN_004bed70(int param_1, int param_2) {
    *(uint*)(param_1 + 0x20) = *(uint*)(param_1 + 0x20) | 0x1000;
    *(int*)(param_1 + 0x5C) = param_2;
    if ((*(int*)(param_1 + 0x50) == 0) || (GetCurrentThreadId() != (DWORD)DAT_008e8fdc)) {
        char local_20[32];
        sprintf(local_20, "set%02d", param_2);
        uint local_24 = 0;
        if (*(int*)(*(int*)(param_1 + 0x88) + 0xC) != 0) {
            do {
                int iVar1 = *(int*)(*(int*)(*(int*)(param_1 + 0x88) + 4) + local_24 * 4);
                if (iVar1 != 0) {
                    unsigned char uVar5 = 1;
                    if (param_2 != 0) {
                        uint32_t uVar3 = FUN_00540540("UserPropBuffer");
                        int iVar4 = FUN_00449390(&DAT_00727890, uVar3);
                        char* _Str1;
                        if ((iVar4 == 0) || ((_Str1 = strstr(*(char**)(iVar4 + 0x10), &PTR_DAT_007082c4), _Str1 == nullptr)) {
                            if (*(int*)(iVar1 + 0x24) != 0) {
                                uVar3 = FUN_00540540("UserPropBuffer");
                                iVar4 = FUN_00449390(&DAT_00727890, uVar3);
                                if ((iVar4 != 0) && ((_Str1 = strstr(*(char**)(iVar4 + 0x10), &PTR_DAT_007082c4), _Str1 != nullptr)) {
                                    uVar5 = 0;
                                    for (; _Str1 != nullptr; _Str1 = strstr(_Str1 + 1, local_20)) {
                                        int iVar4b = strncmp(_Str1, local_20, 5);
                                        if (iVar4b == 0) { uVar5 = 1; break; }
                                    }
                                }
                            }
                        } else {
                            uVar5 = 0;
                            for (; _Str1 != nullptr; _Str1 = strstr(_Str1 + 1, local_20)) {
                                int iVar4b = strncmp(_Str1, local_20, 5);
                                if (iVar4b == 0) { uVar5 = 1; break; }
                            }
                        }
                    }
                    *(unsigned char*)(iVar1 + 0xB4) = uVar5;
                }
                local_24 = local_24 + 1;
            } while (local_24 < *(uint*)(*(int*)(param_1 + 0x88) + 0xC));
        }
        DAT_008c9df4 = 1;
    }
}

// ---------------------------------------------------------------------------
// 0x004be3f0
// ---------------------------------------------------------------------------
extern const void* PTR_DAT_0070d370;
extern void* thunk_FUN_00533c78(size_t);

// 0x004be3f0 — observed shape
uint32_t FUN_004be3f0(int param_1, char* param_2, uint32_t param_3, uint32_t param_4, float param_5,
                      uint32_t* param_6, uint32_t param_7, unsigned char param_8, int param_9, int param_10,
                      uint32_t* param_11, uint32_t* param_12) {
    int* piVar1;
    float fVar2;
    char* pcVar3;
    char* pcVar4;
    int iVar5;
    uint32_t* puVar6;
    float* pfVar7;
    float* pfVar8;
    uint16_t* puVar9;
    uint32_t uVar10;
    uint32_t* puVar11;
    int iVar12;
    uint16_t* puVar13;
    int local_1c;
    uint32_t* local_18;
    float local_14;
    float local_10 = 0.0f;
    uint32_t local_c = 0;
    float local_8 = 0.0f;
    uint32_t local_4 = 0;

    local_1c = 0;
    local_18 = nullptr;
    if (param_2 != nullptr) {
        pcVar3 = param_2;
        do {
            pcVar4 = pcVar3;
            pcVar3 = pcVar4 + 1;
        } while (*pcVar4 != '\0');
        iVar5 = _stricmp(pcVar4 + -3, (char*)&PTR_DAT_0070d370);
        if (iVar5 == 0) {
            local_1c = (int)param_5;
            local_18 = param_6;
        }
    }
    iVar5 = FUN_004cddf0(param_2, param_3, param_4, &local_1c, reinterpret_cast<void**>(&local_18));
    if ((((param_9 == 0 && param_10 == 0) && param_11 == nullptr) &&
         param_12 == nullptr) && (param_2 != nullptr)) {
        param_11 = reinterpret_cast<uint32_t*>(local_1c);
        param_12 = local_18;
        param_5 = (float)local_1c;
        param_6 = local_18;
    }
    else {
    }
    *(float*)(param_1 + 0x34) = param_5;
    *(uint32_t**)(param_1 + 0x38) = param_6;
    puVar6 = (uint32_t*)thunk_FUN_00533c78(0x40);
    if (puVar6 == nullptr) {
        puVar6 = nullptr;
    }
    else {
        puVar11 = puVar6 + 2;
        iVar12 = 4;
        do {
            puVar11[-2] = 0;
            puVar11[-1] = 0;
            *puVar11 = 0;
            puVar11[1] = 0;
            puVar11 = puVar11 + 4;
            iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
    }
    pfVar7 = (float*)thunk_FUN_00533c78(0x30);
    pfVar8 = (float*)thunk_FUN_00533c78(0x20);
    FUN_004b1260(param_7);
    *(float*)&puVar6[0] = local_10;
    puVar6[1] = local_c;
    *(float*)&puVar6[2] = local_8;
    puVar6[3] = local_4;
    *(float*)&puVar6[4] = local_10;
    puVar6[5] = local_c;
    *(float*)&puVar6[6] = local_8;
    puVar6[7] = local_4;
    *(float*)&puVar6[8] = local_10;
    puVar6[9] = local_c;
    *(float*)&puVar6[10] = local_8;
    puVar6[0xb] = local_4;
    *(float*)&puVar6[0xc] = local_10;
    puVar6[0xd] = local_c;
    *(float*)&puVar6[0xe] = local_8;
    puVar6[0xf] = local_4;
    if ((param_8 & 1) != 0) {
        *(float*)&puVar6[3] = *(float*)&puVar6[3] * 0.5f;
    }
    if ((param_8 & 2) != 0) {
        *(float*)&puVar6[7] = *(float*)&puVar6[7] * 0.5f;
    }
    if ((param_8 & 4) != 0) {
        *(float*)&puVar6[0xb] = *(float*)&puVar6[0xb] * 0.5f;
    }
    if ((param_8 & 8) != 0) {
        *(float*)&puVar6[0xf] = *(float*)&puVar6[0xf] * 0.5f;
    }
    if ((param_8 & 0x10) != 0) {
        puVar6[3] = 0;
    }
    if ((param_8 & 0x20) != 0) {
        puVar6[7] = 0;
    }
    if ((param_8 & 0x40) != 0) {
        puVar6[0xb] = 0;
    }
    if ((char)param_8 < '\0') {
        puVar6[0xf] = 0;
    }
    local_10 = (float)*(int*)(param_1 + 0x34) * 0.5f;
    local_8 = (float)*(int*)(param_1 + 0x38) * 0.5f;
    *pfVar7 = -local_10;
    pfVar7[1] = 0.0f;
    pfVar7[2] = -local_8;
    pfVar7[3] = local_10;
    pfVar7[4] = 0.0f;
    pfVar7[5] = -local_8;
    pfVar7[6] = -local_10;
    pfVar7[7] = 0.0f;
    pfVar7[8] = local_8;
    pfVar7[9] = local_10;
    local_c = 0;
    pfVar7[10] = 0.0f;
    pfVar7[0xb] = local_8;
    iVar12 = 1;
    param_5 = 1.4013e-45f;
    if (1 < local_1c) {
        do {
            iVar12 = iVar12 * 2;
        } while (iVar12 < local_1c);
        param_5 = (float)iVar12;
    }
    iVar12 = 1;
    param_5 = (float)param_9 / (float)(int)param_5;
    param_6 = (uint32_t*)0x1;
    if (1 < (int)(intptr_t)local_18) {
        do {
            iVar12 = iVar12 * 2;
        } while (iVar12 < (int)(intptr_t)local_18);
        param_6 = (uint32_t*)iVar12;
    }
    iVar12 = 1;
    local_14 = (float)param_10 / (float)(int)(intptr_t)param_6;
    param_6 = (uint32_t*)0x1;
    if (1 < local_1c) {
        do {
            iVar12 = iVar12 * 2;
        } while (iVar12 < local_1c);
        param_6 = (uint32_t*)iVar12;
    }
    iVar12 = 1;
    float f_param_11 = (float)(int)(intptr_t)param_11 / (float)(int)(intptr_t)param_6;
    *(float*)&param_11 = f_param_11;
    param_6 = (uint32_t*)0x1;
    if (1 < (int)(intptr_t)local_18) {
        do {
            iVar12 = iVar12 * 2;
        } while (iVar12 < (int)(intptr_t)local_18);
        param_6 = (uint32_t*)iVar12;
    }
    fVar2 = (float)(int)(intptr_t)param_12 / (float)(int)(intptr_t)param_6;
    if (param_2 == nullptr) {
        param_5 = 0.0f;
        param_11 = (uint32_t*)0x3f800000;
        local_14 = 0.0f;
        fVar2 = 1.0f;
    }
    *pfVar8 = param_5;
    pfVar8[1] = fVar2;
    pfVar8[2] = *(float*)&param_11;
    pfVar8[3] = fVar2;
    pfVar8[4] = param_5;
    pfVar8[5] = local_14;
    local_18 = param_11;
    pfVar8[6] = *(float*)&param_11;
    pfVar8[7] = local_14;
    puVar9 = (uint16_t*)FUN_00533c78(2);
    puVar13 = nullptr;
    if (puVar9 != nullptr) {
        *puVar9 = 4;
        puVar13 = puVar9;
    }
    puVar9 = (uint16_t*)thunk_FUN_00533c78(8);
    *puVar9 = 0;
    puVar9[1] = 1;
    puVar9[2] = 2;
    puVar9[3] = 3;
    iVar12 = (int)(intptr_t)FUN_00533c78(0xcc);
    if (iVar12 == 0) {
        uVar10 = 0;
    }
    else {
        uVar10 = (uint32_t)(intptr_t)FUN_005473e0(4, pfVar7, 0, puVar6, pfVar8, 1, 0, 2, 1, puVar13, puVar9);
    }
    if (iVar5 != 0) {
        iVar12 = (int)(intptr_t)FUN_00533c78(0x48);
        if (iVar12 == 0) {
            puVar6 = nullptr;
        }
        else {
            puVar6 = (uint32_t*)FUN_005428c0();
        }
        FUN_004aad70(iVar5);
        puVar11 = *(uint32_t**)(intptr_t)puVar6[0xb];
        if (puVar11 == nullptr) {
            iVar5 = (int)(intptr_t)FUN_00533c78(0x1c);
            if (iVar5 == 0) {
                puVar11 = nullptr;
            }
            else {
                puVar11 = (uint32_t*)FUN_005426d0();
            }
            param_11 = puVar11;
            FUN_005606f0(0, (void**)&param_11);
        }
        puVar11[3] = 1;
        FUN_004aacc0(0);
        puVar6[1] = puVar6[1] + 1;
        param_11 = puVar6;
        FUN_004aac50((void**)&param_11);
        piVar1 = (int*)(puVar6 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar6));
            f(1);
        }
    }
    puVar6 = (uint32_t*)FUN_00533c78(0x2c);
    if (puVar6 == nullptr) {
        puVar6 = nullptr;
    }
    else {
        FUN_00540c50();
        *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_0070bf10;
        *(uint16_t*)(puVar6 + 8) = 0;
        puVar6[9] = 0;
        puVar6[10] = 1;
    }
    puVar6[10] = 0;
    puVar6[9] = 1;
    puVar6[1] = puVar6[1] + 1;
    param_11 = puVar6;
    FUN_004aac50((void**)&param_11);
    piVar1 = (int*)(puVar6 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
        auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar6));
        f(1);
    }
    puVar6 = (uint32_t*)FUN_00533c78(0x24);
    if (puVar6 == nullptr) {
        puVar6 = nullptr;
    }
    else {
        FUN_00540c50();
        *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_0070bf4c;
        *(uint16_t*)(puVar6 + 8) = 0xec;
        *(unsigned char*)((intptr_t)puVar6 + 0x22) = 0;
    }
    *(unsigned char*)((intptr_t)puVar6 + 0x22) = 0;
    *(uint16_t*)(puVar6 + 8) = *(uint16_t*)(puVar6 + 8) & 0xd6ed | 0x16ed;
    puVar6[1] = puVar6[1] + 1;
    param_11 = puVar6;
    FUN_004aac50((void**)&param_11);
    piVar1 = (int*)(puVar6 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
        auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar6));
        f(1);
    }
    iVar5 = (int)(intptr_t)FUN_00533c78(0xec);
    if (iVar5 == 0) {
        puVar6 = nullptr;
    }
    else {
        puVar6 = (uint32_t*)FUN_0053bb30(0);
    }
    puVar11 = *(uint32_t**)(param_1 + 0x1c);
    if (puVar11 != puVar6) {
        if (puVar11 != nullptr) {
            piVar1 = (int*)(puVar11 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                auto f = reinterpret_cast<void(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(puVar11));
                f(1);
            }
        }
        *(uint32_t**)(param_1 + 0x1c) = puVar6;
        if (puVar6 != nullptr) {
            puVar6[1] = puVar6[1] + 1;
        }
    }
    auto f2 = reinterpret_cast<void(__cdecl*)(uint32_t, uint32_t)>(*reinterpret_cast<uint32_t*>(*(int*)(*(int*)(param_1 + 0x1c) + 0x70)));
    f2(uVar10, 1);
    FUN_00533d10(0, 1);
    FUN_00534350();
    FUN_00534130();
    return 1;
}
