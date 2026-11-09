#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cctype>
#include <windows.h>

extern void operator delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void FUN_005071f0();
extern int FUN_00412df0();
extern int FUN_00412cb0();
extern int FUN_00412ec0();
extern int FUN_004f1e40(int value);
extern int FUN_004f1d50();
extern int FUN_004f3350();
extern void FUN_005142c0(int a, int b, int c, int d);
extern void* PTR_FUN_00712a58;
extern char DAT_008cacc8[];
extern char DAT_008cacd0[];
extern int DAT_008caccc;
extern int DAT_0071779c;
extern int DAT_007177a0;
extern int DAT_007177a4;
extern int DAT_007177a8;
extern void FUN_00507570();
extern int FUN_00533c78(int size);
extern int FUN_00514090(int a, uint32_t b, int c, int d, int e, int f, int g, int h);
extern float FUN_00514310(int value);
extern void FUN_00514430(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern int FUN_0050b1a0(uint32_t value);
extern uint32_t FUN_005079e0(int a, uint32_t b);
extern void FUN_00507d20(void* ptr);
extern uint32_t FUN_00522960();
extern int FUN_00522900(int a, uint32_t b, uint32_t c);
extern uint32_t FUN_004fd880(int* ptr);
extern int FUN_005f0ddc();
extern void FUN_00503730();
extern void FUN_00504070(int value);
extern void FUN_005229d0();
extern int FUN_00503840();
extern void FUN_0050c5d0(int value);
extern void FUN_0050c550(int value);

void FUN_005213f0(void* self, uint32_t in_ECX, char in_AL);
void FUN_00521620(void* self);
void FUN_005217f0(void* self);
void FUN_00521840(void* self, int in_EAX);

// 0x5212f0 — observed shape
void FUN_005212f0(void* self, uint8_t param_1) {
    uint32_t** self32 = static_cast<uint32_t**>(self);
    uint32_t* puVar1;
    self32[0] = reinterpret_cast<uint32_t*>(&PTR_FUN_00712a58);
    puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(self32[0xb3]) - 8);
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    self32[0xb3] = reinterpret_cast<uint32_t*>(&DAT_008cacd0);
    FUN_005071f0();
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x521340 — observed shape
void FUN_00521340(void* self) {
    char* pcVar1;
    uint32_t* puVar2;
    char cVar3;
    int in_EAX = 0;
    char* pcVar4;
    int in_ECX = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x2cc);
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c0) == 0) {
        FUN_00521620(self);
    } else {
        pcVar4 = *reinterpret_cast<char**>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c0) + 0x298);
        pcVar1 = pcVar4 + 1;
        do {
            cVar3 = *pcVar4;
            pcVar4 = pcVar4 + 1;
        } while (cVar3 != '\0');
        if ((int)pcVar4 - (int)pcVar1 == *reinterpret_cast<int*>(static_cast<char*>(self) + 0x290)) {
            FUN_005213f0(self, *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x0), 0);
            return;
        }
        FUN_00412df0();
        FUN_004f1e40(in_EAX);
        FUN_00521620(self);
        FUN_00521840(self, in_EAX);
        puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX) - 8);
        if ((puVar2 != nullptr) && (puVar2 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
            return;
        }
    }
}

// 0x5213f0 — observed shape
void FUN_005213f0(void* self, uint32_t in_ECX, char in_AL) {
    int iVar1;
    int iVar2;
    ushort local_4;
    uint16_t uStack_2 = static_cast<uint16_t>(in_ECX >> 0x10);
    local_4 = static_cast<ushort>(in_AL);
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c0) == 0) {
        FUN_00521620(self);
    } else {
        FUN_005142c0(DAT_0071779c, DAT_007177a0, DAT_007177a4, DAT_007177a8);
        FUN_00521840(self, 0);
        iVar1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2cc) - 4);
        if (-1 < iVar1) {
            if (iVar1 < iVar1 + 1) {
                FUN_004f3350();
                iVar2 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x2cc);
                *reinterpret_cast<uint8_t*>(iVar2 + *reinterpret_cast<int*>(iVar2 - 4)) = 0;
            }
            std::memmove(reinterpret_cast<void*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2cc) + iVar1), &local_4, 1);
            return;
        }
    }
}

// 0x5214d0 — observed shape
void FUN_005214d0(void* self) {
    char* pcVar1;
    uint32_t* puVar2;
    char cVar3;
    int in_EAX = reinterpret_cast<int>(self);
    char* pcVar4;
    int in_ECX = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x2cc);
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c0) != 0) {
        pcVar4 = *reinterpret_cast<char**>(in_EAX + 0x2cc);
        pcVar1 = pcVar4 + 1;
        do {
            cVar3 = *pcVar4;
            pcVar4 = pcVar4 + 1;
        } while (cVar3 != '\0');
        if (0 < *reinterpret_cast<int*>(static_cast<char*>(self) + 0x290)) {
            if ((int)pcVar4 - (int)pcVar1 < 2) {
                FUN_005217f0(self);
            } else {
                FUN_00412cb0();
                FUN_004f1d50();
                FUN_00521620(self);
                FUN_00521840(self, 0);
                puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX) - 8);
                if ((puVar2 != nullptr) && (puVar2 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                    operator_delete__(puVar2);
                    return;
                }
            }
        }
    }
}

// 0x521570 — observed shape
void FUN_00521570(void* self) {
    char* pcVar1;
    char* pcVar2;
    uint32_t* puVar3;
    char cVar4;
    int in_EAX = reinterpret_cast<int>(self);
    char* pcVar5;
    int in_ECX = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x2cc);
    char* pcVar6;
    if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c0) != 0) {
        pcVar6 = *reinterpret_cast<char**>(*reinterpret_cast<int*>(in_EAX + 0x2c0) + 0x298);
        pcVar1 = pcVar6 + 1;
        pcVar5 = pcVar6;
        do {
            cVar4 = *pcVar5;
            pcVar5 = pcVar5 + 1;
        } while (cVar4 != '\0');
        pcVar2 = pcVar6 + 1;
        do {
            cVar4 = *pcVar6;
            pcVar6 = pcVar6 + 1;
        } while (cVar4 != '\0');
        if ((int)pcVar6 - (int)pcVar2 != *reinterpret_cast<int*>(static_cast<char*>(self) + 0x290)) {
            if ((int)pcVar5 - (int)pcVar1 < 2) {
                FUN_005217f0(self);
            } else {
                FUN_00412df0();
                FUN_004f1d50();
                FUN_00521620(self);
                FUN_00521840(self, 0);
                puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX) - 8);
                if ((puVar3 != nullptr) && (puVar3 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                    operator_delete__(puVar3);
                    return;
                }
            }
        }
    }
}

// 0x521620 — observed shape
void FUN_00521620(void* self) {
    uint8_t* pbVar1 = reinterpret_cast<uint8_t*>(static_cast<char*>(self) + 0x2c8);
    char cVar2;
    int iVar3 = reinterpret_cast<int>(self);
    char* in_EAX = reinterpret_cast<char*>(iVar3);
    uint32_t* puVar4;
    int* piVar5;
    char* pcVar6 = const_cast<char*>("");
    int iVar7 = 1;
    bool bVar8 = true;
    int local_10;
    float local_c;
    uint32_t local_8;
    float local_4;
    do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar8 = *in_EAX == *pcVar6;
        in_EAX = in_EAX + 1;
        pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (bVar8) {
        FUN_005217f0(self);
    } else {
        FUN_00412cb0();
        FUN_00412ec0();
        puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(local_10) - 8);
        if ((puVar4 != nullptr) && (puVar4 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
            operator_delete__(puVar4);
        }
        if (*reinterpret_cast<char*>(iVar3 + 0x2c8) == '\0') {
            FUN_00412ec0();
        } else {
            local_10 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar3 + 0x2cc) - 4);
            if (0 < local_10) {
                do {
                    iVar7 = DAT_008caccc;
                    if (-1 < DAT_008caccc) {
                        if (DAT_008caccc < DAT_008caccc + 1) {
                            FUN_004f3350();
                            (&DAT_008cacd0)[DAT_008caccc] = 0;
                        }
                        std::memmove(&DAT_008cacd0 + iVar7, &local_c, 1);
                    }
                    local_10 = local_10 + -1;
                } while (local_10 != 0);
            }
        }
        if (*reinterpret_cast<int**>(iVar3 + 0x2c0) == nullptr) {
            iVar7 = FUN_00533c78(0x2a0);
            if (iVar7 == 0) {
                piVar5 = nullptr;
            } else {
                piVar5 = reinterpret_cast<int*>(FUN_00514090(0, **reinterpret_cast<uint32_t**>(iVar3 + 700), 1, 0, 0, 0, 0x3f800000, 1));
            }
            local_8 = *reinterpret_cast<uint32_t*>(iVar3 + 0x2a8);
            local_c = *reinterpret_cast<float*>(iVar3 + 0x2a4) + 4.0f;
            *reinterpret_cast<int**>(iVar3 + 0x2c0) = piVar5;
            local_4 = *reinterpret_cast<float*>(iVar3 + 0x2ac) - 0.1f;
            (**(void (**)(float*))(*piVar5 + 0x9c))(&local_c);
            *reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(iVar3 + 0x2c0) + 0xf0) = 1;
            if (*reinterpret_cast<int*>(iVar3 + 0x2c0) != 0) {
                pcVar6 = *reinterpret_cast<char**>(*reinterpret_cast<int*>(iVar3 + 0x2c0) + 0x298);
                do {
                    cVar2 = *pcVar6;
                    pcVar6 = pcVar6 + 1;
                } while (cVar2 != '\0');
            }
            FUN_00521840(self, 0);
        } else {
            (**(void (**)(char*))(**reinterpret_cast<int**>(iVar3 + 0x2c0) + 200))(&DAT_008cacd0);
        }
    }
}

// 0x5217f0 — observed shape
void FUN_005217f0(void* self) {
    int in_EAX = reinterpret_cast<int>(self);
    if (*reinterpret_cast<int*>(in_EAX + 0x2c0) != 0) {
        FUN_00507570();
        *reinterpret_cast<uint32_t*>(in_EAX + 0x2c0) = 0;
        FUN_00521840(self, 0);
    }
    if (*reinterpret_cast<int*>(*reinterpret_cast<uint8_t**>(in_EAX + 0x2cc) - 4) != 0) {
        **reinterpret_cast<uint8_t**>(in_EAX + 0x2cc) = 0;
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(in_EAX + 0x2cc) - 4) = 0;
    }
}

// 0x521840 — observed shape
void FUN_00521840(void* self, int in_EAX) {
    char* pcVar1;
    char cVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    char* pcVar6;
    int iVar7;
    float fVar8;
    iVar3 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c0);
    if (iVar3 == 0) {
        iVar7 = 0;
    } else {
        pcVar6 = *reinterpret_cast<char**>(iVar3 + 0x298);
        pcVar1 = pcVar6 + 1;
        do {
            cVar2 = *pcVar6;
            pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        iVar7 = (int)pcVar6 - (int)pcVar1;
    }
    if (iVar7 < in_EAX) {
        if (iVar3 != 0) {
            pcVar6 = *reinterpret_cast<char**>(iVar3 + 0x298);
            pcVar1 = pcVar6 + 1;
            do {
                cVar2 = *pcVar6;
                pcVar6 = pcVar6 + 1;
            } while (cVar2 != '\0');
            in_EAX = (int)pcVar6 - (int)pcVar1;
            goto LAB_00521893;
        }
    } else if (-1 < in_EAX) goto LAB_00521893;
    in_EAX = 0;
LAB_00521893:
    iVar7 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c4);
    if (iVar7 != 0) {
        if ((iVar3 != 0) && (in_EAX != 0)) {
            fVar8 = FUN_00514310(in_EAX);
            uVar4 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x2b4);
            uVar5 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x2b8);
            iVar3 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c4);
            *reinterpret_cast<float*>(iVar3 + 0x5c) = fVar8 + *reinterpret_cast<float*>(static_cast<char*>(self) + 0x2a4) + 2.0f + *reinterpret_cast<float*>(static_cast<char*>(self) + 0x2b0);
            *reinterpret_cast<uint32_t*>(iVar3 + 0x60) = uVar4;
            *reinterpret_cast<uint32_t*>(iVar3 + 100) = uVar5;
            *reinterpret_cast<int*>(static_cast<char*>(self) + 0x290) = in_EAX;
            return;
        }
        uVar4 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x2b4);
        uVar5 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x2b8);
        *reinterpret_cast<float*>(iVar7 + 0x5c) = *reinterpret_cast<float*>(static_cast<char*>(self) + 0x2a4) + 2.0f + *reinterpret_cast<float*>(static_cast<char*>(self) + 0x2b0);
        *reinterpret_cast<uint32_t*>(iVar7 + 0x60) = uVar4;
        *reinterpret_cast<uint32_t*>(iVar7 + 100) = uVar5;
        *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x290) = 0;
    }
}

// 0x521960 — observed shape
uint8_t FUN_00521960(char in_AL) {
    if (in_AL == '-') return 0x5f;
    if (in_AL == '=') return 0x2b;
    if (in_AL == '[') return 0x7b;
    if (in_AL == ']') return 0x7d;
    if (in_AL == '\\') return 0x7c;
    if (in_AL == ';') return 0x3a;
    if (in_AL == '\'') return 0x22;
    if (in_AL == ',') return 0x3c;
    if (in_AL == '.') return 0x3e;
    if (in_AL == '/') return 0x3f;
    return (uint8_t)((in_AL != ' ') - 1U & 0x20);
}

// 0x5219c0 — observed shape
uint8_t FUN_005219c0(char in_AL) {
    if (in_AL == '1') return 0x21;
    if (in_AL == '2') return 0x40;
    if (in_AL == '3') return 0x23;
    if (in_AL == '4') return 0x24;
    if (in_AL == '5') return 0x25;
    if (in_AL == '6') return 0x5e;
    if (in_AL == '7') return 0x26;
    if (in_AL == '8') return 0x2a;
    if (in_AL == '9') return 0x28;
    return (uint8_t)((in_AL != '0') - 1U & 0x29);
}

// 0x521a10 — observed shape
bool FUN_00521a10(uint32_t in_EAX) {
    if ((static_cast<char>(in_EAX) == ' ') || (static_cast<char>(in_EAX) == '\n')) {
        return true;
    }
    int iVar1 = FUN_0050b1a0(in_EAX);
    return iVar1 != 0;
}

// 0x521a70 — observed shape
uint32_t FUN_00521a70(char param_1, uint32_t in_EAX) {
    uint32_t uVar2;
    int iVar1;
    int iVar3;
    uint8_t local_1;
    if (in_EAX == 0x92) {
        uVar2 = 0x3d;
        local_1 = 0x3d;
    } else {
        uVar2 = MapVirtualKeyA(in_EAX, 2);
        local_1 = static_cast<uint8_t>(uVar2);
    }
    iVar3 = static_cast<int>(static_cast<char>(uVar2));
    if ((-0x81 < iVar3) && (iVar3 < 0x100)) {
        iVar1 = std::isalnum(uVar2 & 0xff);
        if (iVar1 != 0) {
            if (((-0x81 < iVar3) && (iVar3 < 0x100)) && (iVar1 = std::isdigit(uVar2 & 0xff), iVar1 != 0)) {
                if (param_1 == '\0') {
                    return static_cast<uint32_t>(local_1);
                }
                uVar2 = FUN_005219c0(static_cast<char>(local_1));
                return uVar2;
            }
            if (param_1 != '\0') {
                return static_cast<uint32_t>(local_1);
            }
            if ((iVar3 < -0x80) || (0xff < iVar3)) {
                return 0;
            }
            return (uVar2 & 0xff) + 0x20;
        }
        uVar2 = static_cast<uint32_t>(local_1);
    }
    if (param_1 == '\0') {
        return uVar2;
    }
    uVar2 = FUN_00521960(static_cast<char>(local_1));
    return uVar2;
}

// 0x521b30 — observed shape
uint32_t FUN_00521b30(void* self, int param_1, uint32_t param_2) {
    char cVar1;
    char* pcVar2;
    uint32_t uVar3;
    if (param_1 == 8) {
        FUN_005214d0(self);
        return 1;
    }
    if (param_1 == 0x23) {
        if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c0) != 0) {
            pcVar2 = *reinterpret_cast<char**>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x2c0) + 0x298);
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            FUN_00521840(self, 0);
            return 1;
        }
    } else if (param_1 != 0x24) {
        if (param_1 == 0x2e) {
            FUN_00521570(self);
            return 1;
        }
        if (param_1 == 0x25) {
            FUN_00521840(self, 0);
            return 1;
        }
        if (param_1 == 0x27) {
            FUN_00521840(self, 0);
            return 1;
        }
        FUN_00521a70(static_cast<char>(param_2), static_cast<uint32_t>(param_1));
        cVar1 = static_cast<char>(FUN_00521a10(static_cast<uint32_t>(param_1)));
        if (cVar1 == '\0') {
            uVar3 = FUN_005079e0(param_1, param_2);
            return uVar3;
        }
        FUN_00521340(self);
        return 1;
    }
    FUN_00521840(self, 0);
    return 1;
}

// 0x521d10 — observed shape
void FUN_00521d10(void* self, int* param_1) {
    char cVar1;
    int* piVar2;
    char* pcVar3;
    char* pcVar4;
    uint8_t auStackY_c8[128];
    piVar2 = param_1;
    FUN_00507d20(param_1);
    int* param_1_bits = reinterpret_cast<int*>(static_cast<uintptr_t>(0x3f8147ae));
    (**(void (**)(int*, int))(*reinterpret_cast<int*>(static_cast<char*>(piVar2) + 0x160) + 0xc))(reinterpret_cast<int*>(&param_1_bits), 4);
    (**(void (**)(void*, int))(*reinterpret_cast<int*>(static_cast<char*>(piVar2) + 0x160) + 0xc))(static_cast<char*>(self) + 0x294, 0x10);
    pcVar3 = reinterpret_cast<char*>(**reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 700));
    do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    (**(void (**)(void*, int))(*reinterpret_cast<int*>(static_cast<char*>(piVar2) + 0x160) + 0xc))(auStackY_c8 + 0xbc, 4);
    pcVar3 = reinterpret_cast<char*>(**reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 700));
    pcVar4 = pcVar3;
    do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    (**(void (**)(char*, int))(*reinterpret_cast<int*>(static_cast<char*>(piVar2) + 0x160) + 0xc))(pcVar3, (int)pcVar4 - (int)(pcVar3 + 1));
    (**(void (**)(void*, int))(*reinterpret_cast<int*>(static_cast<char*>(piVar2) + 0x160) + 0xc))(static_cast<char*>(self) + 0x2a4, 0xc);
    (**(void (**)(void*, int))(*reinterpret_cast<int*>(static_cast<char*>(piVar2) + 0x160) + 0xc))(static_cast<char*>(self) + 0x2b0, 0xc);
    (**(void (**)(uint32_t))(*piVar2 + 0x2c))(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x2c0));
    (**(void (**)(uint32_t))(*piVar2 + 0x2c))(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x2c4));
}

// 0x521e70 — observed shape
uint32_t FUN_00521e70(int param_1, int param_2, int* param_3, int unaff_EDI, int unaff_EBX, ushort extraout_CX) {
    uint8_t* pbVar1;
    int iVar4;
    int* piVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t local_c;
    uint32_t uStack_8;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(param_3);
    iVar4 = FUN_00533c78(0x2a0);
    if (iVar4 == 0) {
        piVar5 = nullptr;
    } else {
        piVar5 = reinterpret_cast<int*>(FUN_00514090(0, **reinterpret_cast<uint32_t**>(unaff_EDI + 0x2cc), 1, 0, 0, 0, 0x3f800000, 1));
    }
    param_3 = piVar5;
    uVar6 = FUN_00522960();
    (**(void (**)(uint32_t))(*piVar5 + 0x9c))(uVar6);
    if (puVar2 == nullptr) {
        uVar6 = *reinterpret_cast<uint32_t*>(unaff_EDI + 0x2a0);
        uVar8 = *reinterpret_cast<uint32_t*>(unaff_EDI + 0x2a4);
        uVar9 = *reinterpret_cast<uint32_t*>(unaff_EDI + 0x2a8);
        uVar10 = *reinterpret_cast<uint32_t*>(unaff_EDI + 0x2ac);
    } else {
        uVar6 = puVar2[0];
        uVar8 = puVar2[1];
        uVar9 = puVar2[2];
        uVar10 = puVar2[3];
    }
    FUN_00514430(uVar6, uVar8, uVar9, uVar10);
    *reinterpret_cast<uint8_t*>(piVar5 + 0x3c) = 1;
    if (-1 < param_1) {
        piVar5[0x3b] = param_1;
    }
    char cVar3 = static_cast<char>(FUN_00522900(unaff_EBX, local_c, uStack_8));
    if (cVar3 == '\0') {
        *reinterpret_cast<ushort*>(piVar5 + 8) = static_cast<ushort>(*reinterpret_cast<ushort*>(piVar5 + 8) | extraout_CX);
    }
    uVar6 = FUN_004fd880(&param_2);
    if ((*reinterpret_cast<int*>(unaff_EDI + 0x2d4) != 0) &&
        (param_2 = *reinterpret_cast<int*>(unaff_EDI + 0x2e8),
         std::abs(*reinterpret_cast<float*>(unaff_EDI + 0x298) - *reinterpret_cast<float*>(unaff_EDI + 0x29c)) <
             static_cast<float>(param_2) * *reinterpret_cast<float*>(*reinterpret_cast<int*>(unaff_EDI + 0x2cc) + 4))) {
        pbVar1 = reinterpret_cast<uint8_t*>(*reinterpret_cast<int*>(unaff_EDI + 0x2d4) + 0x20);
        *pbVar1 = static_cast<uint8_t>(*pbVar1 & 0xfe);
        iVar4 = *reinterpret_cast<int*>(unaff_EDI + 0x2e8);
        iVar7 = FUN_005f0ddc();
        if (-1 < iVar4 - iVar7) {
            FUN_005f0ddc();
        }
        FUN_00503730();
    }
    return uVar6;
}
// 0x522010 — observed shape
void FUN_00522010(void* self) {
    ushort* puVar1;
    int iVar2;
    int in_EAX = reinterpret_cast<int>(self);
    uint32_t* puVar3;
    uint32_t uVar4 = 0;
    uint32_t* local_8;
    uint32_t* puStack_4;
    if (*reinterpret_cast<int*>(in_EAX + 0x2e4) != 0) {
        do {
            iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(in_EAX + 0x2dc) + uVar4 * 4);
            if ((iVar2 != 0) && (*reinterpret_cast<int**>(iVar2 + 0x24) != nullptr)) {
                if (*reinterpret_cast<int*>(iVar2 + 0xfc) == 0) {
                    (**(void (**)(uint32_t**, int))(**reinterpret_cast<int**>(iVar2 + 0x24) + 0x74))(&puStack_4, iVar2);
                    puVar3 = puStack_4;
                } else {
                    FUN_00504070(iVar2);
                    (**(void (**)(uint32_t**, int))(**reinterpret_cast<int**>(iVar2 + 0x24) + 0x74))(&local_8, iVar2);
                    puVar3 = local_8;
                }
                if ((puVar3 != nullptr) && (iVar2 = puVar3[1], puVar3[1] = iVar2 - 1, iVar2 - 1 == 0)) {
                    (**(void (**)(int))*puVar3)(1);
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<uint32_t*>(in_EAX + 0x2e4));
    }
    *reinterpret_cast<uint32_t*>(in_EAX + 0x2c8) = 0;
    uVar4 = 0;
    if (*reinterpret_cast<int*>(in_EAX + 0x2e4) != 0) {
        do {
            *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(in_EAX + 0x2dc) + uVar4 * 4) = 0;
            uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<uint32_t*>(in_EAX + 0x2e4));
    }
    *reinterpret_cast<uint32_t*>(in_EAX + 0x2e4) = 0;
    *reinterpret_cast<uint32_t*>(in_EAX + 0x2e8) = 0;
    *reinterpret_cast<uint32_t*>(in_EAX + 0x2d0) = 0;
    if (*reinterpret_cast<int*>(in_EAX + 0x2d4) != 0) {
        iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(in_EAX + 0x2d4) + 0x298);
        *reinterpret_cast<uint32_t*>(iVar2 + 0x294) = 1;
        *reinterpret_cast<uint32_t*>(iVar2 + 0x290) = 1;
        puVar1 = reinterpret_cast<ushort*>(*reinterpret_cast<int*>(in_EAX + 0x2d4) + 0x20);
        *puVar1 = static_cast<ushort>(*puVar1 | 1);
    }
}

// 0x522120 — observed shape
void FUN_00522120(void* self, int in_ECX) {
    int in_EAX = reinterpret_cast<int>(self);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(in_EAX + 0x2dc) + in_ECX * 4);
    if (*reinterpret_cast<int*>(in_EAX + 0x2d0) != 0) {
        FUN_00514430(*reinterpret_cast<uint32_t*>(in_EAX + 0x2a0), *reinterpret_cast<uint32_t*>(in_EAX + 0x2a4), *reinterpret_cast<uint32_t*>(in_EAX + 0x2a8), *reinterpret_cast<uint32_t*>(in_EAX + 0x2ac));
    }
    *reinterpret_cast<uint32_t*>(in_EAX + 0x2d0) = uVar1;
    FUN_00514430(*reinterpret_cast<uint32_t*>(in_EAX + 0x2b0), *reinterpret_cast<uint32_t*>(in_EAX + 0x2b4), *reinterpret_cast<uint32_t*>(in_EAX + 0x2b8), *reinterpret_cast<uint32_t*>(in_EAX + 700));
}

// 0x522190 — observed shape
void FUN_00522190(void* self, int in_EAX) {
    int iVar1;
    int in_ECX = reinterpret_cast<int>(self);
    int iVar2;
    int iVar3;
    if (std::abs(*reinterpret_cast<float*>(in_ECX + 0x298) - *reinterpret_cast<float*>(in_ECX + 0x29c)) <
        static_cast<float>(*reinterpret_cast<int*>(in_ECX + 0x2e8)) * *reinterpret_cast<float*>(*reinterpret_cast<int*>(in_ECX + 0x2cc) + 4)) {
        iVar3 = *reinterpret_cast<int*>(in_ECX + 0x2c8);
        if (iVar3 - in_EAX < 0) {
            *reinterpret_cast<uint32_t*>(in_ECX + 0x2c8) = 0;
        } else {
            *reinterpret_cast<int*>(in_ECX + 0x2c8) = iVar3 - in_EAX;
            iVar3 = in_EAX;
        }
        FUN_005229d0();
        iVar1 = *reinterpret_cast<int*>(in_ECX + 0x2d4);
        if ((iVar1 != 0) && (*reinterpret_cast<char*>(*reinterpret_cast<int*>(iVar1 + 0x298) + 0xf2) == '\0')) {
            iVar2 = FUN_00503840();
            if (*reinterpret_cast<char*>(iVar1 + 0x29c) != '\0') {
                FUN_0050c5d0(iVar2 - iVar3);
                return;
            }
            FUN_0050c550(iVar2 - iVar3);
        }
    }
}

// 0x522240 — observed shape
void FUN_00522240(void* self, int in_EAX) {
    int iVar1;
    int in_ECX = reinterpret_cast<int>(self);
    int iVar2;
    int iVar3;
    float extraout_ST1;
    iVar1 = *reinterpret_cast<int*>(in_ECX + 0x2cc);
    iVar3 = *reinterpret_cast<int*>(in_ECX + 0x2e8);
    iVar2 = FUN_005f0ddc();
    iVar2 = iVar3 - iVar2;
    if (std::abs(extraout_ST1) < static_cast<float>(iVar3) * *reinterpret_cast<float*>(iVar1 + 4)) {
        iVar1 = *reinterpret_cast<int*>(in_ECX + 0x2c8) + in_EAX;
        if (iVar2 < iVar1) {
            in_EAX = iVar2 - *reinterpret_cast<int*>(in_ECX + 0x2c8);
            *reinterpret_cast<int*>(in_ECX + 0x2c8) = iVar2;
        } else {
            *reinterpret_cast<int*>(in_ECX + 0x2c8) = iVar1;
        }
        FUN_005229d0();
        iVar1 = *reinterpret_cast<int*>(in_ECX + 0x2d4);
        if ((iVar1 != 0) && (*reinterpret_cast<char*>(*reinterpret_cast<int*>(iVar1 + 0x298) + 0xf2) == '\0')) {
            iVar3 = FUN_00503840();
            if (*reinterpret_cast<char*>(iVar1 + 0x29c) != '\0') {
                FUN_0050c5d0(iVar3 + in_EAX);
                return;
            }
            FUN_0050c550(iVar3 + in_EAX);
        }
    }
}

// 0x522570 — observed shape
bool FUN_00522570(void* self, int param_1) {
    if (param_1 == 0x28) {
        FUN_00522240(self, 0);
        return true;
    }
    if (param_1 == 0x26) {
        FUN_00522190(self, 0);
        return true;
    }
    if (param_1 == 0x22) {
        FUN_005f0ddc();
        FUN_00522240(self, 0);
        return true;
    }
    if (param_1 == 0x21) {
        FUN_005f0ddc();
        FUN_00522190(self, 0);
        return true;
    }
    if (param_1 == 0x23) {
        FUN_00522240(self, 0);
        return true;
    }
    if (param_1 == 0x24) {
        FUN_00522190(self, 0);
    }
    return param_1 == 0x24;
}
