#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <windows.h>

extern int32_t DAT_00727864;
extern int32_t DAT_00727444;
extern int32_t DAT_00727c30;
extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006c1aa8;
extern void* PTR_FUN_006c1b44;
extern void* PTR_FUN_006c1b98;
extern void* PTR_FUN_006c1bcc;

extern char* thunk_FUN_00533c78(size_t n);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);

// 0x5477c0 — observed shape
int32_t FUN_005477c0(int32_t param_1, int32_t param_2, char* param_3, char param_4) {
    char local_800[2048];
    if (DAT_00727864 != 0) {
        // vsprintf(local_800, param_3, &param_4);
        // edx: &param_4 is va_list passed as pointer
        vsprintf(local_800, param_3, reinterpret_cast<char*>(&param_4));
        auto vtable = reinterpret_cast<int32_t*>(*(int32_t*)DAT_00727864);
        // * (code**)(DAT + 0x10)  -> vtable[4]
        if (vtable[4] != 0) {
            using Fn = int32_t(*)(char*, int32_t, int32_t);
            Fn fn = reinterpret_cast<Fn>(vtable[4]); // vtable index 4 corresponds to +0x10 byte offset
            int32_t result = fn(local_800, param_1, param_2);
            return result;
        }
    }
    return 0;
}

// 0x547840 — observed shape
void FUN_00547840(int32_t param_1) {
    if (DAT_00727864 != 0) {
        auto vtable = reinterpret_cast<int32_t*>(*(int32_t*)DAT_00727864);
        // (** (code**) (*DAT + 0x5c))(param_1); offset 0x5c /4 = 23
        if (vtable[23] != 0) {
            using Fn = void(*)(int32_t);
            Fn fn = reinterpret_cast<Fn>(vtable[23]);
            fn(param_1);
        }
    }
}

// 0x547860 — observed shape
void FUN_00547860(void* self) {
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_LAB_006fd148);
    in_ECX[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1aa8);
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
}

// 0x547890 — observed shape
void FUN_00547890(void* self) {
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1aa8);
    if (DAT_00727864 != 0) {
        auto v1 = reinterpret_cast<int32_t*>(*(int32_t*)DAT_00727864);
        if (v1[8] != 0) { // +0x20 /4
            using Fn = void(*)();
            reinterpret_cast<Fn>(v1[8])();
        }
        if (DAT_00727864 != 0) {
            auto v2 = reinterpret_cast<int32_t*>(*(int32_t*)DAT_00727864);
            if (v2[12] != 0) { // +0x30 /4
                using Fn = void(*)();
                reinterpret_cast<Fn>(v2[12])();
            }
        }
    }
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_LAB_006fd148);
    DAT_00727444 = DAT_00727444 + -1;
}

// 0x5478d0 — observed shape
char FUN_005478d0(int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(DAT_00727864);
    if (piVar1 != nullptr) {
        if (piVar1[2] != 0) {
            int32_t local_4 = 0;
            using Fn = char(*)(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t*);
            Fn fn = reinterpret_cast<Fn>(piVar1[2]);
            char cVar2 = fn(param_1, DAT_00727c30, param_2, param_3, param_4, &local_4);
            if ((cVar2 != '\0') && (local_4 != 0)) {
                auto v = reinterpret_cast<int32_t*>(*piVar1);
                // +0x24 /4 = 9
                if (v[9] != 0) {
                    using Fn2 = void(*)(int32_t);
                    reinterpret_cast<Fn2>(v[9])(local_4);
                }
            }
            return cVar2;
        }
        FUN_005477c0(1, 0, const_cast<char*>("LoadAndRegisterShaderLibrary: No valid ClassCreate call\n"), 0);
    }
    return '\0';
}

// 0x547950 — observed shape
void FUN_00547950(void* self, uint8_t param_1) {
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1aa8);
    if (DAT_00727864 != 0) {
        auto v1 = reinterpret_cast<int32_t*>(*(int32_t*)DAT_00727864);
        if (v1[8] != 0) {
            using Fn = void(*)();
            reinterpret_cast<Fn>(v1[8])();
        }
        if (DAT_00727864 != 0) {
            auto v2 = reinterpret_cast<int32_t*>(*(int32_t*)DAT_00727864);
            if (v2[12] != 0) {
                using Fn = void(*)();
                reinterpret_cast<Fn>(v2[12])();
            }
        }
    }
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_LAB_006fd148);
    DAT_00727444 = DAT_00727444 + -1;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5479e0 — observed shape
void FUN_005479e0(void* self, int param_1, int32_t param_2);
// 0x5479e0 — observed shape
void FUN_005479e0(void* self, int param_1, int32_t param_2) {
    // Observed pseudocode uses int in_ECX internally; self is the ecx receiver.
    // Body operates on strings at param_1+0x10 and *self+0x10.
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    extern void FUN_00547db0(int, int32_t);
    FUN_00547db0(param_1, param_2);
    char* pcVar2 = *reinterpret_cast<char**>(reinterpret_cast<char*>(in_ECX) + 0x10);
    if (pcVar2 == nullptr) {
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(param_1) + 0x10) = 0;
        return;
    }
    char* pcVar3 = pcVar2 + 1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar3 = thunk_FUN_00533c78(static_cast<size_t>(pcVar2 + (1 - (int)(pcVar3))));
    *reinterpret_cast<char**>(reinterpret_cast<char*>(param_1) + 0x10) = pcVar3;
    pcVar2 = *reinterpret_cast<char**>(reinterpret_cast<char*>(in_ECX) + 0x10);
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        *pcVar3 = cVar1;
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
}

// 0x547bb0 — observed shape
void FUN_00547bb0(void* self, uint8_t param_1);
// 0x547bb0 — observed shape
void FUN_00547bb0(void* self, uint8_t param_1) {
    extern void FUN_00547d10(void*);
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1b44);
    operator_delete__(reinterpret_cast<void*>(in_ECX[4]));
    in_ECX[4] = 0;
    FUN_00547d10(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x547c80 — observed shape
void FUN_00547c80(void* self) {
    extern void FUN_005383d0(void*);
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    FUN_005383d0(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1b98);
    in_ECX[3] = 0;
}

// 0x547ca0 — observed shape
void* FUN_00547ca0(void* self, char* param_1) {
    extern void FUN_005383d0(void*);
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    FUN_005383d0(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1b98);
    if (param_1 != nullptr) {
        char* pcVar2 = param_1;
        char cVar1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        if (pcVar2 != param_1 + 1) {
            pcVar2 = param_1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            pcVar2 = thunk_FUN_00533c78(static_cast<size_t>(pcVar2 + (1 - (int)(param_1 + 1))));
            reinterpret_cast<int32_t*>(in_ECX)[3] = reinterpret_cast<int32_t>(pcVar2);
            do {
                cVar1 = *param_1;
                param_1 = param_1 + 1;
                *pcVar2 = cVar1;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
        }
    }
    return self;
}

// 0x547d10 — observed shape
void FUN_00547d10(void* self) {
    extern void FUN_00538400(void*);
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1b98);
    operator_delete__(reinterpret_cast<void*>(in_ECX[3]));
    in_ECX[3] = 0;
    FUN_00538400(self);
}

// 0x547d40 — observed shape
void FUN_00547d40(void* self, char* param_1) {
    char* pcVar2;
    char cVar1;
    char* base = reinterpret_cast<char*>(self);
    if (*reinterpret_cast<void**>(base + 0xc) != nullptr) {
        operator_delete__(*reinterpret_cast<void**>(base + 0xc));
        *reinterpret_cast<int32_t*>(base + 0xc) = 0;
    }
    if (param_1 != nullptr) {
        pcVar2 = param_1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        if (pcVar2 != param_1 + 1) {
            pcVar2 = param_1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            pcVar2 = thunk_FUN_00533c78(static_cast<size_t>(pcVar2 + (1 - (int)(param_1 + 1))));
            *reinterpret_cast<char**>(base + 0xc) = pcVar2;
            do {
                cVar1 = *param_1;
                param_1 = param_1 + 1;
                *pcVar2 = cVar1;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
        }
    }
}

// 0x547db0 — observed shape
void FUN_00547db0(void* self, int param_1, int32_t param_2) {
    extern void FUN_00538410(int, int32_t);
    extern void FUN_00547d40(void*, char*);
    FUN_00538410(param_1, param_2);
    char* v = *reinterpret_cast<char**>(reinterpret_cast<char*>(self) + 0xc);
    FUN_00547d40(self, v);
}

// 0x547e10 — observed shape
bool FUN_00547e10(int32_t param_1) {
    extern char FUN_00538360(int32_t);
    char cVar1 = FUN_00538360(param_1);
    return cVar1 != '\0';
}

// 0x547e30 — observed shape
void FUN_00547e30(void* self, int32_t param_1) {
    extern void FUN_00538430(int32_t);
    extern void FUN_00545950(int32_t);
    FUN_00538430(param_1);
    int32_t v = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0xc);
    FUN_00545950(v);
}

// 0x547e50 — observed shape
int32_t FUN_00547e50(void* self, int param_1) {
    extern int32_t FUN_00538460(int);
    int32_t uVar2 = FUN_00538460(param_1);
    if (static_cast<char>(uVar2) == '\0') {
        return uVar2;
    }
    auto pbVar5 = *reinterpret_cast<uint8_t**>(reinterpret_cast<char*>(param_1) + 0xc);
    auto pbVar3 = *reinterpret_cast<uint8_t**>(reinterpret_cast<char*>(self) + 0xc);
    bool bVar6;
    while (true) {
        uint8_t bVar1 = *pbVar3;
        if (bVar1 == *pbVar5) {
            if (bVar1 == 0) {
                return 1;
            }
            uint8_t b1 = pbVar3[1];
            bVar6 = (bVar1 == 0);
            (void)bVar6;
            // preserve original two-byte stride comparison
            uint8_t nextA = pbVar3[1];
            uint8_t nextB = pbVar5[1];
            if (nextA == nextB) {
                pbVar3 = pbVar3 + 2;
                pbVar5 = pbVar5 + 2;
                if (nextA == 0) {
                    return 1;
                }
                continue;
            }
            bVar6 = (nextA < nextB);
            break;
        }
        bVar6 = (bVar1 < *pbVar5);
        break;
    }
    int32_t iVar4 = (1 - (int32_t)(bVar6 ? 1 : 0)) - (int32_t)(bVar6 ? 1 : 0);
    // Original: CONCAT31((int3)((uint)iVar4 >> 8), iVar4 == 0)
    // i.e. low byte = (iVar4==0), remaining bytes = high 3 bytes of iVar4
    int32_t result = static_cast<int32_t>(((static_cast<uint32_t>(iVar4) >> 8) << 8) | (iVar4 == 0 ? 1 : 0));
    return result;
}

// 0x547ec0 — observed shape
void FUN_00547ec0(void* self, uint8_t param_1) {
    extern void FUN_00538400(void*);
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1b98);
    operator_delete__(reinterpret_cast<void*>(in_ECX[3]));
    in_ECX[3] = 0;
    FUN_00538400(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x547f00 — observed shape
void FUN_00547f00(void* self, int param_1) {
    extern int32_t FUN_00545600();
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_1) + 0x1c) < 0x500000bu) {
        int32_t uVar1 = FUN_00545600();
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0xc) = uVar1;
    }
}

// 0x547f20 — observed shape
void FUN_00547f20(void* self, int32_t param_1, int32_t param_2) {
    extern void FUN_005383d0(void*);
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    FUN_005383d0(self);
    in_ECX[5] = param_1;
    in_ECX[3] = 0;
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1bcc);
    in_ECX[4] = param_2;
}

// 0x547f60 — observed shape
void FUN_00547f60(void* self, uint8_t param_1) {
    extern void FUN_00547d10(void*);
    auto* in_ECX = reinterpret_cast<int32_t*>(self);
    in_ECX[0] = reinterpret_cast<int32_t>(&PTR_FUN_006c1bcc);
    operator_delete__(reinterpret_cast<void*>(in_ECX[4]));
    in_ECX[4] = 0;
    FUN_00547d10(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

