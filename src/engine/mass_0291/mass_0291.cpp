#include <cstdint>
#include <cstddef>
#include <cstdarg>
#include <windows.h>
#include <cstdio>

extern void FUN_0060fcd3(int context, void* param2, void* param3, void* global, char* text);
extern void FUN_0060fd9a(int context, void* param2, void* param3, void* global, char* text);
extern int FUN_0060d19b(int size);
extern int FUN_0065af58(void* param1, int param2, int p3, int p4, void* p5);
// Callers in the corpus invoke these reporters with no explicit arguments.
void FUN_00632325(int param_1 = 0, void* param_2 = nullptr, void* param_3 = nullptr,
                  char* param_4 = const_cast<char*>(""), ...);
void FUN_0063237b(int param_1 = 0, void* param_2 = nullptr, void* param_3 = nullptr,
                  char* param_4 = const_cast<char*>(""), ...);
void FUN_006323c8(int param_1 = 0, void* param_2 = nullptr, void* param_3 = nullptr,
                  char* param_4 = const_cast<char*>(""), ...);
extern unsigned char DAT_006c7974;

// Reflects the observed signed-overflow pair (SBORROW4(a, b) vs (a - b < 0)).
static inline bool recon_sb_overflow(int a, int b) {
    int d = a - b;
    return ((a ^ b) & (a ^ d)) < 0;
}

// 0x632325 — observed shape
void FUN_00632325(int param_1, void* param_2, void* param_3, char* param_4, ...) {
    char local_104[255];
    unsigned char local_5;
    va_list ap;
    va_start(ap, param_4);
    _vsnprintf(local_104, 0x100, param_4, ap);
    va_end(ap);
    local_5 = 0;
    (void)local_5;
    int base = *reinterpret_cast<int*>(param_1 + 4);
    FUN_0060fcd3(base + 0x18, param_2, param_3, &DAT_006c7974, local_104);
    *reinterpret_cast<uint32_t*>(param_1 + 0x40) = 1;
}

// 0x63237b — observed shape
void FUN_0063237b(int param_1, void* param_2, void* param_3, char* param_4, ...) {
    char local_104[255];
    unsigned char local_5;
    va_list ap;
    va_start(ap, param_4);
    _vsnprintf(local_104, 0x100, param_4, ap);
    va_end(ap);
    local_5 = 0;
    (void)local_5;
    int base = *reinterpret_cast<int*>(param_1 + 4);
    FUN_0060fd9a(base + 0x18, param_2, param_3, &DAT_006c7974, local_104);
}

// 0x6323c8 — observed shape
void FUN_006323c8(int param_1, void* param_2, void* param_3, char* param_4, ...) {
    char local_104[255];
    unsigned char local_5;
    va_list ap;
    va_start(ap, param_4);
    _vsnprintf(local_104, 0x100, param_4, ap);
    va_end(ap);
    local_5 = 0;
    (void)local_5;
    int base = *reinterpret_cast<int*>(param_1 + 4);
    FUN_0060fcd3(base + 0x18, param_2, param_3, &DAT_006c7974, local_104);
    *reinterpret_cast<uint32_t*>(param_1 + 0x40) = 1;
    *reinterpret_cast<uint32_t*>(param_1 + 0x44) = 1;
}

// 0x632420 — observed shape
int FUN_00632420(void* self, int param_1) {
    int selfInt = reinterpret_cast<int>(self);
    if (param_1 == 0) {
        if (*reinterpret_cast<int*>(selfInt + 0x40) == 0) {
            FUN_006323c8();
        }
        *reinterpret_cast<uint32_t*>(selfInt + 0x40) = 1;
        *reinterpret_cast<uint32_t*>(selfInt + 0x44) = 1;
    }
    return param_1;
}

// 0x632455 — observed shape
uint32_t FUN_00632455(void* self, uint32_t param_1, int param_2) {
    int selfInt = reinterpret_cast<int>(self);
    if ((*reinterpret_cast<int*>(selfInt + 0x10) != 0) && (param_2 == 0)) {
        int field10 = *reinterpret_cast<int*>(selfInt + 0x10);
        param_2 = *reinterpret_cast<int*>(field10 + 0x14);
    }
    int iVar1 = FUN_0060d19b(0x24);
    int alloc;
    if (iVar1 == 0) {
        alloc = 0;
    } else {
        void* field10 = reinterpret_cast<void*>(*reinterpret_cast<int*>(selfInt + 0x10));
        alloc = FUN_0065af58(reinterpret_cast<void*>(param_1), param_2, 0, 0, field10);
    }
    uint32_t result;
    if (alloc == 0) {
        FUN_006323c8();
        result = 0x8007000e;
    } else {
        *reinterpret_cast<int*>(selfInt + 0x10) = alloc;
        result = 0;
    }
    return result;
}

extern int FUN_0065acec(void* name, int p2, int p3, int p4);
extern int FUN_0065ac49(uint32_t param2, int p2, const char* name);

// 0x6324b9 — observed shape
uint32_t FUN_006324b9(int param_1, uint32_t param_2) {
    int iVar6 = *reinterpret_cast<int*>(param_2 + 0x14);
    int* piVar10 = reinterpret_cast<int*>(param_1 + 0x1c);
    if (*piVar10 != 0) {
        do {
            int iVar5 = *piVar10;
            unsigned char* pbVar7 = *reinterpret_cast<unsigned char**>(iVar6 + 0x18);
            unsigned char* pbVar3 = *reinterpret_cast<unsigned char**>(iVar5 + 0x10);
            int iVar4;
            for (;;) {
                unsigned char bVar1 = *pbVar7;
                bool bVar11 = bVar1 < *pbVar3;
                if (bVar1 != *pbVar3) {
                    iVar4 = (1 - (uint32_t)bVar11) - (uint32_t)(bVar11 != 0);
                    break;
                }
                if (bVar1 == 0) { iVar4 = 0; break; }
                bVar1 = pbVar7[1];
                bVar11 = bVar1 < pbVar3[1];
                if (bVar1 != pbVar3[1]) {
                    iVar4 = (1 - (uint32_t)bVar11) - (uint32_t)(bVar11 != 0);
                    break;
                }
                pbVar7 = pbVar7 + 2;
                pbVar3 = pbVar3 + 2;
                if (bVar1 == 0) { iVar4 = 0; break; }
            }
            if (iVar4 < 0) {
                piVar10 = reinterpret_cast<int*>(iVar5 + 8);
            } else {
                if (iVar4 < 1) break;
                piVar10 = reinterpret_cast<int*>(iVar5 + 0xc);
            }
        } while (*piVar10 != 0);
        if (*piVar10 != 0) goto LAB_00632549;
    }
    {
        int iVar5 = FUN_0060d19b(0x18);
        if (iVar5 == 0) {
            iVar6 = 0;
        } else {
            iVar6 = FUN_0065acec(*reinterpret_cast<void**>(iVar6 + 0x18), 0, 0, 0);
        }
        *piVar10 = iVar6;
        if (iVar6 == 0) {
            return 0x8007000e;
        }
    }
LAB_00632549:
    iVar6 = FUN_0060d19b(0x14);
    {
        uint32_t uVar9 = 0;
        if (iVar6 == 0) {
            iVar6 = 0;
        } else {
            iVar6 = FUN_0065ac49(param_2, *reinterpret_cast<int*>(*piVar10 + 0x14), "Stmts");
        }
        *reinterpret_cast<int*>(*piVar10 + 0x14) = iVar6;
        if (iVar6 == 0) {
            return 0x8007000e;
        }
        if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(*piVar10 + 0x14) + 0xc) == 0) {
            iVar6 = *piVar10;
            int* piVar8 = piVar10;
            while (iVar6 != 0) {
                for (;;) {
                    iVar6 = *piVar8;
                    if (iVar6 == 0) break;
                    int iVar5b = *reinterpret_cast<int*>(iVar6 + 8);
                    if (iVar5b == 0) break;
                    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(iVar5b + 0xc);
                    *reinterpret_cast<int*>(iVar5b + 0xc) = iVar6;
                    *reinterpret_cast<uint32_t*>(iVar6 + 8) = uVar2;
                    *piVar8 = iVar5b;
                }
                piVar8 = reinterpret_cast<int*>(iVar6 + 0xc);
                uVar9 = uVar9 + 1;
                iVar6 = *piVar8;
            }
            while (uVar9 = uVar9 >> 1, uVar9 != 0) {
                if (uVar9 != 0) {
                    piVar8 = piVar10;
                    uint32_t localCount = uVar9;
                    do {
                        iVar6 = *piVar8;
                        if (iVar6 != 0) {
                            int iVar5b = *reinterpret_cast<int*>(iVar6 + 0xc);
                            if (iVar5b != 0) {
                                uint32_t uVar2 = *reinterpret_cast<uint32_t*>(iVar5b + 8);
                                *reinterpret_cast<int*>(iVar5b + 8) = iVar6;
                                *reinterpret_cast<uint32_t*>(iVar6 + 0xc) = uVar2;
                                *piVar8 = iVar5b;
                            }
                        }
                        piVar8 = reinterpret_cast<int*>(*piVar8 + 0xc);
                        localCount = localCount - 1;
                    } while (localCount != 0);
                }
            }
        }
    }
    return 0;
}

// 0x6325ec — observed shape
uint32_t FUN_006325ec(int param_1, int param_2) {
    int iVar5 = *reinterpret_cast<int*>(param_2 + 0x1c);
    if (iVar5 != 0) {
        do {
            unsigned char* pbVar2 = *reinterpret_cast<unsigned char**>(iVar5 + 0x10);
            unsigned char* pbVar4 = *reinterpret_cast<unsigned char**>(param_1 + 8);
            int iVar3;
            for (;;) {
                unsigned char bVar1 = *pbVar4;
                bool bVar6 = bVar1 < *pbVar2;
                if (bVar1 != *pbVar2) {
                    iVar3 = (1 - (uint32_t)bVar6) - (uint32_t)(bVar6 != 0);
                    break;
                }
                if (bVar1 == 0) { iVar3 = 0; break; }
                bVar1 = pbVar4[1];
                bVar6 = bVar1 < pbVar2[1];
                if (bVar1 != pbVar2[1]) {
                    iVar3 = (1 - (uint32_t)bVar6) - (uint32_t)(bVar6 != 0);
                    break;
                }
                pbVar4 = pbVar4 + 2;
                pbVar2 = pbVar2 + 2;
                if (bVar1 == 0) { iVar3 = 0; break; }
            }
            if (iVar3 == 0) {
                return *reinterpret_cast<uint32_t*>(iVar5 + 0x14);
            }
            if (iVar3 < 0) {
                iVar5 = *reinterpret_cast<int*>(iVar5 + 8);
            } else {
                iVar5 = *reinterpret_cast<int*>(iVar5 + 0xc);
            }
        } while (iVar5 != 0);
    }
    return 0;
}

// 0x632650 — observed shape
uint32_t FUN_00632650(int param_1, int param_2) {
    bool bVar1;
    bool bVar2;
    bool bVar3;

    if (param_1 == param_2) {
        return 0;
    }
    switch (param_1) {
    case 1:
    case 5:
        if (param_2 < 1) {
            return 1;
        }
        bVar3 = recon_sb_overflow(param_2, 8);
        bVar2 = param_2 + -8 < 0;
        bVar1 = param_2 == 8;
        break;
    case 2:
    case 6:
        if (param_2 < 1) {
            return 1;
        }
        if (param_2 < 3) {
            return 0;
        }
        if (param_2 < 5) {
            return 1;
        }
        bVar3 = recon_sb_overflow(param_2, 6);
        bVar2 = param_2 + -6 < 0;
        bVar1 = param_2 == 6;
        break;
    case 3:
    case 7:
        if (param_2 == 1) {
            return 0;
        }
        if (param_2 == 3) {
            return 0;
        }
        param_2 = param_2 + -5;
        goto LAB_00632698;
    case 4:
    case 8:
        if (param_2 == 1) {
            return 0;
        }
        if (param_2 < 4) {
            return 1;
        }
        if (param_2 < 6) {
            return 0;
        }
        bVar1 = param_2 == 8;
        goto LAB_006326d3;
    case 9:
        if (param_2 < 9) {
            return 1;
        }
        bVar3 = recon_sb_overflow(param_2, 0xc);
        bVar2 = param_2 + -0xc < 0;
        bVar1 = param_2 == 0xc;
        break;
    case 10:
        if (param_2 < 9) {
            return 1;
        }
        bVar3 = recon_sb_overflow(param_2, 10);
        bVar2 = param_2 + -10 < 0;
        bVar1 = param_2 == 10;
        break;
    case 0xb:
        param_2 = param_2 + -9;
LAB_00632698:
        if (param_2 == 0) {
            return 0;
        }
        bVar1 = param_2 == 2;
        goto LAB_006326d3;
    case 0xc:
        if (param_2 == 9) {
            return 0;
        }
        bVar1 = param_2 == 0xc;
LAB_006326d3:
        if (bVar1) {
            return 0;
        }
        /* fallthrough */
    default:
        goto LAB_00632678;
    }
    if (bVar1 || bVar3 != bVar2) {
        return 0;
    }
LAB_00632678:
    return 1;
}

// 0x632729 — observed shape
uint32_t FUN_00632729(int param_1, int param_2) {
    if (param_1 == 0) {
        return 0;
    }
    int iVar1 = *reinterpret_cast<int*>(param_1 + 4);
    if (iVar1 == 1) {
        do {
            if (*reinterpret_cast<int*>(param_1 + 4) != 1) break;
            FUN_00632729(*reinterpret_cast<int*>(param_1 + 8), param_2);
            param_1 = *reinterpret_cast<int*>(param_1 + 0xc);
        } while (param_1 != 0);
        if (param_1 == 0) {
            return 0;
        }
    } else if (iVar1 == 6) {
        param_1 = *reinterpret_cast<int*>(param_1 + 0x18);
    } else if (iVar1 == 8) {
        param_1 = *reinterpret_cast<int*>(param_1 + 0x10);
    } else {
        if (iVar1 == 9) {
            if (param_2 == 0) {
                *reinterpret_cast<unsigned char*>(param_1 + 0x21) =
                    *reinterpret_cast<unsigned char*>(param_1 + 0x21) & 0xfd;
                return 0;
            }
            *reinterpret_cast<unsigned char*>(param_1 + 0x21) =
                *reinterpret_cast<unsigned char*>(param_1 + 0x21) | 2;
            return 0;
        }
        if (iVar1 != 0xb) {
            FUN_006323c8();
            return 0;
        }
        param_1 = *reinterpret_cast<int*>(param_1 + 0x20);
    }
    FUN_00632729(param_1, param_2);
    return 0;
}

extern void FUN_006321f5(void* self, const char* message);

// 0x6327be — observed shape
uint32_t FUN_006327be(void* self, int param_1, int param_2) {
    int selfInt = reinterpret_cast<int>(self);
    if ((*reinterpret_cast<uint32_t*>(param_1 + 0x10) &
         *reinterpret_cast<uint32_t*>(param_2 + 0x10)) != 0) {
        FUN_00632325();
    }
    if ((*reinterpret_cast<int*>(param_1 + 0x14) != 0) &&
        (*reinterpret_cast<int*>(param_2 + 0x14) != 0)) {
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int*>(param_2 + 0x14) + 0x10);
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(selfInt + 0x20);
        for (int iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar3 = puVar3 + 1;
        }
        FUN_006321f5(self, "syntax error");
    }
    *reinterpret_cast<uint32_t*>(param_1 + 0x10) =
        *reinterpret_cast<uint32_t*>(param_1 + 0x10) |
        *reinterpret_cast<uint32_t*>(param_2 + 0x10);
    if ((*reinterpret_cast<int*>(param_1 + 0x14) == 0) &&
        (*reinterpret_cast<int*>(param_2 + 0x14) != 0)) {
        int iVar1 = FUN_0065abf1(*reinterpret_cast<int*>(param_2 + 0x14));
        *reinterpret_cast<int*>(param_1 + 0x14) = iVar1;
        if (iVar1 == 0) {
            return 0x8007000e;
        }
    }
    return 0;
}

extern int FUN_0065abf1(int node);

// 0x63284b — observed shape
uint32_t FUN_0063284b(int param_1) {
    int iVar1;
    for (;;) {
        for (;;) {
            for (;;) {
                for (;;) {
                    if (param_1 == 0) {
                        return 0;
                    }
                    iVar1 = *reinterpret_cast<int*>(param_1 + 4);
                    if (iVar1 != 1) break;
                    iVar1 = FUN_0063284b(*reinterpret_cast<int*>(param_1 + 8));
                    if (iVar1 != 0) {
                        return 1;
                    }
                    param_1 = *reinterpret_cast<int*>(param_1 + 0xc);
                }
                if (iVar1 != 6) break;
                param_1 = *reinterpret_cast<int*>(param_1 + 0x18);
            }
            if (iVar1 != 8) break;
            param_1 = *reinterpret_cast<int*>(param_1 + 0x10);
        }
        if (iVar1 == 9) {
            return *reinterpret_cast<uint32_t*>(param_1 + 0x20) & 0x200;
        }
        if (iVar1 != 0xb) break;
        param_1 = *reinterpret_cast<int*>(param_1 + 0x20);
    }
    FUN_006323c8();
    return 0;
}

// 0x6328be — observed shape
bool FUN_006328be(int param_1) {
    bool bVar1;
    if ((param_1 == 0) || (*reinterpret_cast<int*>(param_1 + 4) != 9)) {
        bVar1 = false;
    } else {
        bVar1 = *reinterpret_cast<int*>(param_1 + 0x10) == 0;
    }
    return bVar1;
}

// 0x6328e2 — observed shape
uint32_t FUN_006328e2(int param_1) {
    int iVar1;
    for (;;) {
        for (;;) {
            for (;;) {
                for (;;) {
                    if (param_1 == 0) {
                        return 1;
                    }
                    iVar1 = *reinterpret_cast<int*>(param_1 + 4);
                    if (iVar1 != 1) break;
                    iVar1 = FUN_006328e2(*reinterpret_cast<int*>(param_1 + 8));
                    if (iVar1 == 0) {
                        return 0;
                    }
                    param_1 = *reinterpret_cast<int*>(param_1 + 0xc);
                }
                if (iVar1 != 6) break;
                param_1 = *reinterpret_cast<int*>(param_1 + 0x18);
            }
            if (iVar1 != 8) break;
            param_1 = *reinterpret_cast<int*>(param_1 + 0x10);
        }
        if (iVar1 == 9) break;
        if (iVar1 != 0xb) {
            FUN_006323c8();
            return 0;
        }
        param_1 = *reinterpret_cast<int*>(param_1 + 0x20);
    }
    if (*reinterpret_cast<int*>(param_1 + 0x10) < 0) {
        return 0;
    }
    if (*reinterpret_cast<int*>(param_1 + 0x10) < 3) {
        return 1;
    }
    return 0;
}

// 0x632959 — observed shape
int FUN_00632959(int param_1) {
    int iVar2 = 0;
    if (param_1 == 0) {
        return 0;
    }
    do {
        if (*reinterpret_cast<int*>(param_1 + 4) != 1) break;
        int iVar1 = FUN_00632959(*reinterpret_cast<int*>(param_1 + 8));
        param_1 = *reinterpret_cast<int*>(param_1 + 0xc);
        iVar2 = iVar2 + iVar1;
    } while (param_1 != 0);
    if (param_1 == 0) {
        return iVar2;
    }
    {
        int iVar1 = *reinterpret_cast<int*>(param_1 + 4);
        uint32_t uVar3;
        if (iVar1 == 6) {
            uVar3 = *reinterpret_cast<uint32_t*>(param_1 + 0x18);
        } else {
            if (iVar1 == 8) {
                iVar1 = FUN_00632959(*reinterpret_cast<int*>(param_1 + 0x10));
                iVar1 = iVar1 * *reinterpret_cast<int*>(param_1 + 0x14);
                goto LAB_006329de;
            }
            if (iVar1 == 9) {
                iVar1 = *reinterpret_cast<int*>(param_1 + 0x1c) *
                        *reinterpret_cast<int*>(param_1 + 0x18);
                goto LAB_006329de;
            }
            if (iVar1 != 0xb) {
                FUN_006323c8();
                return 0;
            }
            uVar3 = *reinterpret_cast<uint32_t*>(param_1 + 0x20);
        }
        iVar1 = FUN_00632959(uVar3);
LAB_006329de:
        return iVar1 + iVar2;
    }
}

// 0x6329e7 — observed shape
bool FUN_006329e7(int param_1, int param_2) {
    for (;;) {
        if (param_1 == 0) {
            return param_2 == 0;
        }
        int iVar1 = *reinterpret_cast<int*>(param_1 + 4);
        if (iVar1 != 1) break;
        if (param_2 == 0) {
            return false;
        }
        if (*reinterpret_cast<int*>(param_2 + 4) != 1) break;
        iVar1 = FUN_006329e7(*reinterpret_cast<int*>(param_1 + 8),
                             *reinterpret_cast<int*>(param_2 + 8));
        if (iVar1 == 0) {
            return false;
        }
        param_1 = *reinterpret_cast<int*>(param_1 + 0xc);
        param_2 = *reinterpret_cast<int*>(param_2 + 0xc);
    }
    if ((param_2 != 0) && (iVar1 == *reinterpret_cast<int*>(param_2 + 4))) {
        if (iVar1 == 6) {
            param_2 = *reinterpret_cast<int*>(param_2 + 0x18);
            param_1 = *reinterpret_cast<int*>(param_1 + 0x18);
            continue;
        }
        if (iVar1 == 8) {
            if (*reinterpret_cast<int*>(param_1 + 0x14) ==
                *reinterpret_cast<int*>(param_2 + 0x14)) {
                param_2 = *reinterpret_cast<int*>(param_2 + 0x10);
                param_1 = *reinterpret_cast<int*>(param_1 + 0x10);
                continue;
            }
        } else {
            if (iVar1 == 9) {
                if (*reinterpret_cast<int*>(param_1 + 0x10) !=
                    *reinterpret_cast<int*>(param_2 + 0x10)) {
                    return false;
                }
                if (*reinterpret_cast<int*>(param_1 + 0x14) !=
                    *reinterpret_cast<int*>(param_2 + 0x14)) {
                    return false;
                }
                if (*reinterpret_cast<int*>(param_1 + 0x18) !=
                    *reinterpret_cast<int*>(param_2 + 0x18)) {
                    return false;
                }
                if (*reinterpret_cast<int*>(param_1 + 0x1c) ==
                    *reinterpret_cast<int*>(param_2 + 0x1c)) {
                    return true;
                }
                return false;
            }
            if (iVar1 == 0xb) {
                param_2 = *reinterpret_cast<int*>(param_2 + 0x20);
                param_1 = *reinterpret_cast<int*>(param_1 + 0x20);
                continue;
            }
        }
    }
    return false;
}

extern uint32_t DAT_006e9340[];

// 0x632a99 — observed shape (listing declares void; recursive caller consumes the length)
int FUN_00632a99(char* param_1, uint32_t param_2, int param_3) {
    char local_108[255];
    unsigned char local_9 = 0;
    char* local_8 = local_108;
    const char* pcVar5 = "";
    const char* pcVar3 = "";
    const char* _Format = "%s%s";
    int iVar4;

    if (param_3 == 0) {
        local_8 = const_cast<char*>("void");
        goto LAB_00632cbb;
    }
    iVar4 = *reinterpret_cast<int*>(param_3 + 4);
    if (iVar4 == 1) {
        iVar4 = FUN_0063284b(param_3);
        pcVar5 = "const ";
        if (iVar4 == 0) {
            pcVar5 = "";
        }
        _snprintf(local_108, 0xff, "%sstruct{%u}", pcVar5,
                  static_cast<uint32_t>(FUN_00632959(param_3)));
        goto LAB_00632cbb;
    }
    if (iVar4 == 8) {
        int iVar2 = param_3;
        while (*reinterpret_cast<int*>(iVar2 + 4) == 8) {
            iVar2 = *reinterpret_cast<int*>(iVar2 + 0x10);
        }
        iVar4 = FUN_00632a99(local_108, 0xff, iVar2);
        for (; *reinterpret_cast<int*>(param_3 + 4) == 8;
             param_3 = *reinterpret_cast<int*>(param_3 + 0x10)) {
            _snprintf(local_108 + iVar4, 0xff - iVar4, "[%u]",
                      *reinterpret_cast<uint32_t*>(param_3 + 0x14));
            char* pcVar4 = local_108 + iVar4;
            local_9 = 0;
            char cVar1;
            do {
                cVar1 = *pcVar4;
                pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            iVar4 = static_cast<int>(pcVar4 - (local_108 + 1));
        }
        goto LAB_00632cbb;
    }
    if (iVar4 != 9) {
        local_8 = const_cast<char*>("unknown");
        goto LAB_00632cbb;
    }
    pcVar5 = "const ";
    if ((*reinterpret_cast<unsigned char*>(param_3 + 0x21) & 2) == 0) {
        pcVar5 = "";
    }
    switch (*reinterpret_cast<int*>(param_3 + 0x14)) {
    case 0: pcVar3 = "bool"; break;
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
        pcVar3 = "int"; break;
    case 9: case 0xb: pcVar3 = "float"; break;
    case 10: pcVar3 = "half"; break;
    case 0xc: pcVar3 = "double"; break;
    case 0xd: pcVar3 = "NULL"; break;
    case 0xe: pcVar3 = "string"; break;
    case 0xf: pcVar3 = "texture"; break;
    case 0x10: pcVar3 = "texture1D"; break;
    case 0x11: pcVar3 = "texture2D"; break;
    case 0x12: pcVar3 = "texture3D"; break;
    case 0x13: pcVar3 = "textureCUBE"; break;
    case 0x14: pcVar3 = "sampler"; break;
    case 0x15: pcVar3 = "sampler1D"; break;
    case 0x16: pcVar3 = "sampler2D"; break;
    case 0x17: pcVar3 = "sampler3D"; break;
    case 0x18: pcVar3 = "samplerCUBE"; break;
    case 0x19: pcVar3 = "pixelshader"; break;
    case 0x1a: pcVar3 = "vertexshader"; break;
    case 0x1b: pcVar3 = "pixelfragment"; break;
    case 0x1c: pcVar3 = "vertexfragment"; break;
    case 0x1d: pcVar3 = "stateblock"; break;
    default: pcVar3 = "unknown"; break;
    }
    if (*reinterpret_cast<int*>(param_3 + 0x10) == 1) {
        _snprintf(local_108, 0xff, "%s%s%u", pcVar5, pcVar3,
                  *reinterpret_cast<uint32_t*>(param_3 + 0x1c));
        goto LAB_00632cbb;
    }
    if (*reinterpret_cast<int*>(param_3 + 0x10) == 2) {
        _snprintf(local_108, 0xff, "%s%s%ux%u", pcVar5, pcVar3,
                  *reinterpret_cast<uint32_t*>(param_3 + 0x18),
                  *reinterpret_cast<uint32_t*>(param_3 + 0x1c));
        goto LAB_00632cbb;
    }
    _snprintf(local_108, 0xff, _Format, pcVar5, pcVar3);
LAB_00632cbb:
    {
        char* pcVar4 = local_8;
        char cVar1;
        uint32_t uVar6;
        do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        uVar6 = static_cast<uint32_t>(pcVar4 - (local_8 + 1));
        if (param_2 < uVar6) {
            uVar6 = param_2;
        }
        char* pcVar5Out = param_1;
        char* src = local_8;
        uint32_t uVar7;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *reinterpret_cast<uint32_t*>(pcVar5Out) = *reinterpret_cast<uint32_t*>(src);
            src = src + 4;
            pcVar5Out = pcVar5Out + 4;
        }
        for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar5Out = *src;
            src = src + 1;
            pcVar5Out = pcVar5Out + 1;
        }
        param_1[uVar6] = '\0';
        return static_cast<int>(uVar6);
    }
}

// 0x632d6c — observed shape
uint32_t FUN_00632d6c(int param_1, uint32_t param_2, int param_3) {
    if (param_1 != 0) {
        do {
            int iVar1 = *reinterpret_cast<int*>(param_1 + 4);
            if (iVar1 == 1) {
                uint32_t uVar2 = static_cast<uint32_t>(FUN_00632959(*reinterpret_cast<int*>(param_1 + 8)));
                if (param_2 < uVar2) {
                    param_1 = *reinterpret_cast<int*>(param_1 + 8);
                } else {
                    param_1 = *reinterpret_cast<int*>(param_1 + 0xc);
                    param_2 = param_2 - uVar2;
                }
            } else if (iVar1 == 6) {
                param_1 = *reinterpret_cast<int*>(param_1 + 0x18);
            } else if (iVar1 == 8) {
                param_1 = *reinterpret_cast<int*>(param_1 + 0x10);
                uint32_t uVar2 = static_cast<uint32_t>(FUN_00632959(param_1));
                if (uVar2 == 0) {
                    return 0x80004005;
                }
                param_2 = param_2 % uVar2;
            } else {
                if (iVar1 == 9) {
                    int iVar1b = *reinterpret_cast<int*>(param_1 + 0x10);
                    if (((iVar1b == 0) || (iVar1b == 1)) || (iVar1b == 2)) {
                        *reinterpret_cast<uint32_t*>(param_3 + 0x10) = 0;
                    } else if (iVar1b == 3) {
                        *reinterpret_cast<uint32_t*>(param_3 + 0x10) = 3;
                    }
                    *reinterpret_cast<uint32_t*>(param_3 + 0x14) =
                        *reinterpret_cast<uint32_t*>(param_1 + 0x14);
                    *reinterpret_cast<uint32_t*>(param_3 + 0x18) = 1;
                    *reinterpret_cast<uint32_t*>(param_3 + 0x1c) = 1;
                    *reinterpret_cast<uint32_t*>(param_3 + 0x20) =
                        *reinterpret_cast<uint32_t*>(param_1 + 0x20) & 0x200;
                    return 0;
                }
                if (iVar1 != 0xb) {
                    FUN_006323c8();
                    return 0;
                }
                param_1 = *reinterpret_cast<int*>(param_1 + 0x20);
            }
        } while (param_1 != 0);
    }
    return 0x80004005;
}

// 0x632e37 — observed shape
uint32_t FUN_00632e37(int param_1, int param_2, int* param_3) {
    uint32_t uVar4;
    if ((((param_1 == 0) || (*reinterpret_cast<int*>(param_1 + 4) != 9)) || (param_2 == 0)) ||
        (*reinterpret_cast<int*>(param_2 + 4) != 9)) {
LAB_00632fd5:
        uVar4 = 0x80004005;
    } else {
        int iVar1 = *reinterpret_cast<int*>(param_1 + 0x14);
        int iVar2 = *reinterpret_cast<int*>(param_2 + 0x14);
        if (iVar1 == iVar2) {
            *param_3 = iVar1;
        } else {
            uint32_t uVar7 = DAT_006e9340[iVar2 * 2];
            if (DAT_006e9340[iVar2 * 2] < DAT_006e9340[iVar1 * 2]) {
                uVar7 = DAT_006e9340[iVar1 * 2];
            }
            uint32_t uVar3 = DAT_006e9340[iVar1 * 2 + 1] & DAT_006e9340[iVar2 * 2 + 1];
            int iVar6 = 1;
            if ((uVar3 & 1) == 0) {
                if ((uVar3 & 4) == 0) {
                    if ((uVar3 & 2) == 0) {
                        if ((uVar3 & 8) == 0) {
                            if ((uVar3 & 0x10) != 0) {
                                uint32_t uVar7b = 0;
                                do {
                                    int iVar5;
                                    if (uVar7b == 0) {
                                        iVar6 = iVar1;
                                        iVar5 = iVar2;
                                    } else {
                                        iVar6 = iVar2;
                                        iVar5 = iVar1;
                                    }
                                    if (iVar5 == 0xd) {
LAB_00632fe1:
                                        *param_3 = iVar6;
                                        goto LAB_00632fe6;
                                    }
                                    if (iVar5 == 0xf) {
                                        if (0xe < iVar6) {
                                            bool bVar9 = recon_sb_overflow(iVar6, 0x13);
                                            int iVar5b = iVar6 + -0x13;
                                            bool bVar8 = iVar6 == 0x13;
                                            if (bVar8 || bVar9 != (iVar5b < 0)) {
                                                goto LAB_00632fe1;
                                            }
                                        }
                                    } else if ((iVar5 == 0x14) && (0x13 < iVar6)) {
                                        bool bVar9 = recon_sb_overflow(iVar6, 0x18);
                                        int iVar5b = iVar6 + -0x18;
                                        bool bVar8 = iVar6 == 0x18;
                                        if (bVar8 || bVar9 != (iVar5b < 0)) {
                                            goto LAB_00632fe1;
                                        }
                                    }
                                    uVar7b = uVar7b + 1;
                                } while (uVar7b < 2);
                            }
                            goto LAB_00632fd5;
                        }
                        if (uVar7 == 0) {
                            *param_3 = 9;
                        } else if ((uVar7 == 8) || (uVar7 == 0x10)) {
                            *param_3 = 10;
                        } else if (uVar7 == 0x20) {
                            *param_3 = 0xb;
                        } else if (uVar7 == 0x40) {
                            *param_3 = 0xc;
                        }
                    } else if (uVar7 == 0) {
LAB_00632ed6:
                        *param_3 = iVar6;
                    } else if (uVar7 == 8) {
                        *param_3 = 2;
                    } else if (uVar7 == 0x10) {
                        *param_3 = 3;
                    } else if ((uVar7 == 0x20) || (uVar7 == 0x40)) {
                        *param_3 = 4;
                    }
                } else if (uVar7 == 0) {
                    *param_3 = 5;
                } else {
                    iVar6 = 8;
                    if (uVar7 == 8) {
                        *param_3 = 6;
                    } else if (uVar7 == 0x10) {
                        *param_3 = 7;
                    } else if ((uVar7 == 0x20) || (uVar7 == 0x40)) {
                        goto LAB_00632ed6;
                    }
                }
            } else {
                *param_3 = 0;
            }
        }
LAB_00632fe6:
        uVar4 = 0;
    }
    return uVar4;
}

// 0x632fea — observed shape
uint32_t FUN_00632fea(void* self, uint32_t param_1) {
    int selfInt = reinterpret_cast<int>(self);
    int iVar2 = *reinterpret_cast<int*>(selfInt + 0x10);
    for (;;) {
        if (iVar2 == 0) {
            return param_1;
        }
        int iVar1 = *reinterpret_cast<int*>(iVar2 + 0x10);
        if (((iVar1 == 2) || (iVar1 == 3)) || (iVar1 == 4)) break;
        iVar2 = *reinterpret_cast<int*>(iVar2 + 0x20);
    }
    FUN_00632325();
    return 0;
}

// 0x63302f — observed shape
int FUN_0063302f(int param_1, uint32_t* param_2) {
    int iVar3 = 0;
    uint32_t uVar4 = 0;
    if (param_1 == 0) {
        return 0;
    }
    int iVar1 = *reinterpret_cast<int*>(param_1 + 4);
    if (iVar1 == 1) {
        do {
            if (*reinterpret_cast<int*>(param_1 + 4) != 1) break;
            iVar1 = FUN_0063302f(*reinterpret_cast<int*>(param_1 + 8), param_2 + iVar3 * 4);
            param_1 = *reinterpret_cast<int*>(param_1 + 0xc);
            iVar3 = iVar3 + iVar1;
        } while (param_1 != 0);
        if (param_1 == 0) {
            return iVar3;
        }
        iVar1 = FUN_0063302f(param_1, param_2 + iVar3 * 4);
        return iVar3 + iVar1;
    }
    if (iVar1 == 6) {
        uVar4 = *reinterpret_cast<uint32_t*>(param_1 + 0x18);
LAB_00633077:
        iVar3 = FUN_0063302f(uVar4, param_2);
        return iVar3;
    }
    if (iVar1 == 8) {
        uint32_t uVar2 = 0;
        if (*reinterpret_cast<int*>(param_1 + 0x14) == 0) {
            return 0;
        }
        do {
            iVar1 = FUN_0063302f(*reinterpret_cast<int*>(param_1 + 0x10), param_2 + iVar3 * 4);
            iVar3 = iVar3 + iVar1;
            uVar2 = uVar2 + 1;
        } while (uVar2 < *reinterpret_cast<uint32_t*>(param_1 + 0x14));
        return iVar3;
    }
    if (iVar1 != 9) {
        if (iVar1 != 0xb) {
            return 0;
        }
        uVar4 = *reinterpret_cast<uint32_t*>(param_1 + 0x20);
        goto LAB_00633077;
    }
    iVar3 = *reinterpret_cast<int*>(param_1 + 0x1c) * *reinterpret_cast<int*>(param_1 + 0x18);
    {
        uVar4 = 3;
        switch (*reinterpret_cast<int*>(param_1 + 0x14)) {
        case 0:
            uVar4 = 0;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            uVar4 = 1;
            break;
        case 5:
        case 6:
        case 7:
        case 8:
            uVar4 = 2;
            goto LAB_006330b4;
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
            uVar4 = 5;
            break;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x1d:
            uVar4 = 4;
LAB_006330b4:
            break;
        }
        if (iVar3 != 0) {
            int iVar1b = iVar3;
            do {
                *param_2 = uVar4;
                param_2 = param_2 + 4;
                iVar1b = iVar1b + -1;
            } while (iVar1b != 0);
        }
        return iVar3;
    }
}
