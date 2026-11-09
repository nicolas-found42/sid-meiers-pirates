#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00574540(int param_1, int param_2, int param_3);
extern void FUN_004e6420(void);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);

// 0x506440 — observed shape
uint32_t FUN_506440(void* self, int32_t in_EDX) {
    // self = in_EAX receiver; puVar2 list at +0x38 then +0x48
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<intptr_t>(self) + 0x38);
    int32_t* piVar1;
    while (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 2);
        puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
        if (*reinterpret_cast<int32_t*>(*reinterpret_cast<intptr_t*>(piVar1) + 0x24) == in_EDX) {
            return *reinterpret_cast<uint32_t*>(*reinterpret_cast<intptr_t*>(piVar1) + 4);
        }
    }
    puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<intptr_t>(self) + 0x48);
    do {
        if (puVar2 == nullptr) {
            return 0xffffffffu;
        }
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 2);
        puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
    } while (*reinterpret_cast<int32_t*>(*reinterpret_cast<intptr_t*>(*reinterpret_cast<intptr_t*>(piVar1) + 4) + 0x24) != in_EDX);
    return *reinterpret_cast<uint32_t*>(*reinterpret_cast<intptr_t*>(*reinterpret_cast<intptr_t*>(piVar1) + 4) + 4);
}

// 0x506490 — observed shape
void FUN_506490(int32_t param_1) {
    int32_t* piVar1;
    uint32_t uVar2;
    int32_t iVar3;
    uint32_t* puVar4;
    int32_t* piVar5;
    int32_t* piVar6;

    uVar2 = 0;
    if (*reinterpret_cast<uint32_t*>(param_1 + 0x60) != 0) {
        piVar5 = *reinterpret_cast<int32_t**>(param_1 + 100);
        do {
            if (*piVar5 != 0) {
                piVar5 = reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t**>(param_1 + 100))[uVar2];
                goto joined_r0x005064c3;
            }
            uVar2 = uVar2 + 1;
            piVar5 = piVar5 + 1;
        } while (uVar2 < *reinterpret_cast<uint32_t*>(param_1 + 0x60));
    }
    piVar5 = nullptr;
joined_r0x005064c3:
    do {
        if (piVar5 == nullptr) {
            return;
        }
        piVar6 = reinterpret_cast<int32_t*>(*piVar5);
        piVar1 = reinterpret_cast<int32_t*>(piVar5[2]);
        if (piVar6 == nullptr) {
            using Func = int32_t(__cdecl*)(int32_t);
            int32_t vtable = *reinterpret_cast<int32_t*>(param_1 + 0x5c);
            Func fn = *reinterpret_cast<Func*>(vtable + 4);
            iVar3 = fn(piVar5[1]);
            uVar2 = (uint32_t)(iVar3 + 1);
            if (uVar2 < *reinterpret_cast<uint32_t*>(param_1 + 0x60)) {
                puVar4 = reinterpret_cast<uint32_t*>(*reinterpret_cast<intptr_t*>(param_1 + 100) + uVar2 * 4);
                do {
                    piVar6 = reinterpret_cast<int32_t*>(*puVar4);
                    if (piVar6 != nullptr) goto LAB_00506500;
                    uVar2 = uVar2 + 1;
                    puVar4 = puVar4 + 1;
                } while (uVar2 < *reinterpret_cast<uint32_t*>(param_1 + 0x60));
            }
            piVar6 = nullptr;
        }
LAB_00506500:
        piVar5 = piVar6;
        if (*piVar1 != 0) {
            FUN_00574540(*piVar1, 0, 1);
        }
    } while (true);
}

// 0x506520 — observed shape
void FUN_506520(void* self) {
    // self = unaff_EDI receiver (dword array)
    uint32_t* unaff_EDI = reinterpret_cast<uint32_t*>(self);
    uint32_t* puVar1;
    uint32_t* puVar2;

    puVar2 = reinterpret_cast<uint32_t*>(unaff_EDI[1]);
    while (puVar2 != nullptr) {
        puVar1 = reinterpret_cast<uint32_t*>(*puVar2);
        using Func = void(__cdecl*)(uint32_t*);
        int32_t vtable = *reinterpret_cast<int32_t*>(unaff_EDI);
        Func fn = *reinterpret_cast<Func*>(vtable + 8);
        fn(puVar2);
        puVar2 = puVar1;
    }
    unaff_EDI[3] = 0;
    unaff_EDI[1] = 0;
    unaff_EDI[2] = 0;
    return;
}

// 0x506550 — observed shape
uint32_t FUN_506550(void* self, int32_t* param_1) {
    // self = unaff_EDI receiver
    uint32_t* unaff_EDI = reinterpret_cast<uint32_t*>(self);
    int32_t iVar5;
    uint32_t* puVar2;
    uint32_t* puVar3;
    int32_t* piVar1;
    char cVar4;

    {
        using Func = int32_t(__cdecl*)();
        int32_t vtable = *reinterpret_cast<int32_t*>(unaff_EDI);
        Func fn = *reinterpret_cast<Func*>(vtable + 4);
        iVar5 = fn();
    }
    puVar2 = *reinterpret_cast<uint32_t**>(unaff_EDI[2] + iVar5 * 4);
    while (true) {
        if (puVar2 == nullptr) {
            return 0;
        }
        {
            using Func = char(__cdecl*)();
            int32_t vtable = *reinterpret_cast<int32_t*>(unaff_EDI);
            Func fn = *reinterpret_cast<Func*>(vtable + 8);
            cVar4 = fn();
        }
        if (cVar4 != '\0') break;
        puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
    }
    puVar3 = reinterpret_cast<uint32_t*>(*param_1);
    if (puVar3 != reinterpret_cast<uint32_t*>(puVar2[2])) {
        if (puVar3 != nullptr) {
            piVar1 = reinterpret_cast<int32_t*>(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Func = void(__cdecl*)(int32_t);
                int32_t vtable = *reinterpret_cast<int32_t*>(puVar3);
                Func fn = *reinterpret_cast<Func*>(vtable);
                fn(1);
            }
        }
        iVar5 = (int32_t)puVar2[2];
        *param_1 = iVar5;
        if (iVar5 != 0) {
            *reinterpret_cast<int32_t*>(iVar5 + 4) = *reinterpret_cast<int32_t*>(iVar5 + 4) + 1;
        }
    }
    return 1;
}

// 0x5065b0 — observed shape
int32_t FUN_5065b0(void* self) {
    // self = in_ECX receiver
    uint32_t uVar1;
    int32_t* piVar2;

    uVar1 = 0;
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4) != 0) {
        piVar2 = *reinterpret_cast<int32_t**>(reinterpret_cast<intptr_t>(self) + 8);
        do {
            if (*piVar2 != 0) {
                return (*reinterpret_cast<int32_t**>(reinterpret_cast<intptr_t>(self) + 8))[uVar1];
            }
            uVar1 = uVar1 + 1;
            piVar2 = piVar2 + 1;
        } while (uVar1 < *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(self) + 4));
    }
    return 0;
}

extern void* PTR_FUN_0071128c;
extern void* PTR_FUN_00711290;
extern void* PTR_FUN_00711254;
extern void* PTR_FUN_00711270;
extern void* PTR_FUN_007112ac;
extern void* PTR_FUN_007112c8;
extern void* PTR_FUN_007112e4;
extern void* PTR_FUN_00711300;
extern void* PTR_FUN_00711334;

// 0x5065e0 — observed shape
void FUN_5065e0(int32_t** param_1, void* self, void* in_EBX, void* in_EDI) {
    // self = in_ECX receiver; in_EBX/in_EDI extra register params
    int32_t* ecx = reinterpret_cast<int32_t*>(self);
    int32_t* edi = reinterpret_cast<int32_t*>(in_EDI);
    int32_t* ebx = reinterpret_cast<int32_t*>(in_EBX);
    int32_t* piVar1;
    int32_t* piVar5;
    int32_t* puVar2;
    int32_t iVar3;
    uint32_t uVar4;

    piVar5 = *param_1;
    ecx[0] = piVar5[1];
    puVar2 = reinterpret_cast<int32_t*>(edi[0]);
    if (puVar2 != reinterpret_cast<int32_t*>(piVar5[2])) {
        if (puVar2 != nullptr) {
            piVar1 = puVar2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using DeletingDtor = void(__cdecl*)(int32_t);
                DeletingDtor fn = *reinterpret_cast<DeletingDtor*>(*reinterpret_cast<int32_t*>(puVar2));
                fn(1);
            }
        }
        iVar3 = piVar5[2];
        edi[0] = iVar3;
        if (iVar3 != 0) {
            *reinterpret_cast<int32_t*>(iVar3 + 4) = *reinterpret_cast<int32_t*>(iVar3 + 4) + 1;
        }
    }
    if (piVar5[0] != 0) {
        *param_1 = reinterpret_cast<int32_t*>(piVar5[0]);
        return;
    }
    {
        using NextIndex = int32_t(__cdecl*)(int32_t);
        NextIndex fn = *reinterpret_cast<NextIndex*>(*reinterpret_cast<int32_t*>(ebx) + 4);
        iVar3 = fn(piVar5[1]);
    }
    uVar4 = static_cast<uint32_t>(iVar3 + 1);
    if (uVar4 < static_cast<uint32_t>(ebx[1])) {
        piVar5 = reinterpret_cast<int32_t*>(ebx[2] + static_cast<int32_t>(uVar4) * 4);
        do {
            if (piVar5[0] != 0) {
                *param_1 = reinterpret_cast<int32_t*>(piVar5[0]);
                return;
            }
            uVar4 = uVar4 + 1;
            piVar5 = piVar5 + 1;
        } while (uVar4 < static_cast<uint32_t>(ebx[1]));
    }
    *param_1 = nullptr;
    return;
}

// 0x506660 — observed shape
void FUN_506660(void* param_1) {
    int32_t* piVar1;
    uint32_t* puVar2;

    puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<intptr_t>(param_1) + 8);
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DeletingDtor = void(__cdecl*)(int32_t);
            DeletingDtor fn = *reinterpret_cast<DeletingDtor*>(static_cast<intptr_t>(*puVar2));
            fn(1);
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<intptr_t>(param_1) + 8) = nullptr;
    }
    if (param_1 != nullptr) {
        puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<intptr_t>(param_1) + 8);
        if (puVar2 != nullptr) {
            piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using DeletingDtor = void(__cdecl*)(int32_t);
                DeletingDtor fn = *reinterpret_cast<DeletingDtor*>(static_cast<intptr_t>(*puVar2));
                fn(1);
            }
        }
        operator_delete(param_1);
    }
    return;
}

// 0x5066b0 — observed shape
void FUN_5066b0(void* self) {
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);
    uint32_t uVar3;

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_007112e4));
    if (*reinterpret_cast<char*>(ecx + 4) != '\0') {
        uVar3 = 0;
        if (ecx[1] != 0) {
            do {
                puVar2 = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(ecx[2]) + uVar3 * 4);
                while (puVar2 != nullptr) {
                    puVar1 = puVar2 + 1;
                    puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*puVar2));
                    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(*puVar1)));
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < ecx[1]);
        }
    }
    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711300));
    FUN_004e6420();
    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_007112c8));
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2])));
    return;
}

// 0x506730 — observed shape
void FUN_506730(void* self, int32_t in_EAX, uint8_t param_1) {
    // self = unaff_ESI receiver; in_EAX element count
    uint32_t* esi = reinterpret_cast<uint32_t*>(self);
    uint32_t* puVar1;
    uint32_t uVar2;
    int32_t iVar3;

    esi[1] = static_cast<uint32_t>(in_EAX);
    esi[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_007112c8));
    esi[3] = 0;
    puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(static_cast<uint32_t>(in_EAX) << 2));
    esi[2] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar1));
    for (uVar2 = esi[1] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar1) + 1);
    }
    *reinterpret_cast<uint8_t*>(esi + 4) = param_1;
    esi[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_007112e4));
    return;
}

// 0x506780 — observed shape
void FUN_506780(void* self) {
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);
    uint32_t uVar3;

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711290));
    if (*reinterpret_cast<char*>(ecx + 4) != '\0') {
        uVar3 = 0;
        if (ecx[1] != 0) {
            do {
                puVar2 = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(ecx[2]) + uVar3 * 4);
                while (puVar2 != nullptr) {
                    puVar1 = puVar2 + 1;
                    puVar2 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*puVar2));
                    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(*puVar1)));
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < ecx[1]);
        }
    }
    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_007112ac));
    FUN_004e6420();
    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711334));
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2])));
    return;
}

// 0x506800 — observed shape
void FUN_506800(void* self, int32_t in_EAX, uint8_t param_1) {
    // self = unaff_ESI receiver; in_EAX element count
    uint32_t* esi = reinterpret_cast<uint32_t*>(self);
    uint32_t* puVar1;
    uint32_t uVar2;
    int32_t iVar3;

    esi[1] = static_cast<uint32_t>(in_EAX);
    esi[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711334));
    esi[3] = 0;
    puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(static_cast<uint32_t>(in_EAX) << 2));
    esi[2] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar1));
    for (uVar2 = esi[1] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar1) + 1);
    }
    *reinterpret_cast<uint8_t*>(esi + 4) = param_1;
    esi[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711290));
    return;
}

// 0x506850 — observed shape
void FUN_506850(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_007112c8));
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2])));
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
    return;
}

// 0x506890 — observed shape
void FUN_506890(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711300));
    FUN_004e6420();
    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_007112c8));
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2])));
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
    return;
}

// 0x5068d0 — observed shape
void FUN_5068d0(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    FUN_5066b0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x5068f0 — observed shape
void FUN_5068f0(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711334));
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2])));
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
    return;
}

// 0x506930 — observed shape
void FUN_506930(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_007112ac));
    FUN_004e6420();
    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711334));
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2])));
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
    return;
}

// 0x506970 — observed shape
void FUN_506970(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    FUN_506780(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x506990 — observed shape
void FUN_506990(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_0071128c));
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[1])));
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
    return;
}

// 0x5069c0 — observed shape
void FUN_5069c0(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711254));
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2])));
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
    return;
}

// 0x506a40 — observed shape
void FUN_506a40(void* self, uint8_t param_1) {
    // self = in_ECX receiver; deleting destructor with free flag
    uint32_t* ecx = reinterpret_cast<uint32_t*>(self);

    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711270));
    FUN_004e6420();
    ecx[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(&PTR_FUN_00711254));
    FUN_004e6420();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[2])));
    if ((param_1 & 1) != 0) {
        operator_delete(ecx);
    }
    return;
}
