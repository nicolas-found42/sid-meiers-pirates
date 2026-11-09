// Reconstruction batch mass_0284 — Sid Meier's Pirates! (2004), PE32 i386
// Address range 0x629436..0x62a56f. Pseudocode corpus Ghidra 12.2.
// Receiver registers in_ECX/in_ESI/in_EDI are explicit leading parameters.
// Globals DAT_* and helpers FUN_* are extern; field offsets preserved.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// 32-bit guest address arithmetic: the corpus converts int fields to addresses.
static inline uintptr_t addr32(int32_t value) {
    return static_cast<uintptr_t>(static_cast<uint32_t>(value));
}

// Ghidra SBORROW4(a,b): signed borrow/overflow flag of (a - b) over 32-bit ints.
#define SBORROW4(a, b) \
  ((((((int32_t)(a) ^ (int32_t)(b)) & ((int32_t)(a) ^ ((int32_t)(a) - (int32_t)(b)))) & 0x80000000) != 0)

// ---- Globals (extern, as used by listed corpus) ----
extern int32_t DAT_006f5200[4];
extern int32_t DAT_006dd2c4[4];

// ---- Helpers (extern) ----
extern void* FUN_00533c78(uint32_t size);
extern void FUN_0062947f(void* self);   // in_ECX constructor, returns self in EAX
extern void FUN_0062952f(void* self);   // in_ECX constructor, returns self in EAX
extern void FUN_00629ca0(int32_t param_1, int32_t param_2, int32_t param_3);
extern void FUN_00629dca(int32_t param_1, int32_t param_2, int32_t param_3);
extern void FUN_0062e426(void* self);   // in_ECX destructor
extern void operator_delete(void* p);
extern "C" int _stricmp(const char* a, const char* b);

typedef void(__thiscall* PFN_THISCALL_VOID)(void*);
typedef int(__thiscall* PFN_THISCALL_INT_PARAM)(void*, uint32_t);

// ---------------------------------------------------------------------------

// 0x629436 — observed shape
// Four-dword interface match against DAT_006f5200 / DAT_006dd2c4; on match
// store the interface and call vtable slot +4 (AddRef-style).
uint32_t FUN_00629436(int32_t* param_1, int32_t* param_2, uint32_t* param_3) {
    int32_t iVar1;
    int32_t* piVar2;
    int32_t* piVar3;
    bool bVar4;

    *param_3 = 0;
    iVar1 = 4;
    bVar4 = true;
    piVar2 = param_2;
    piVar3 = DAT_006f5200;
    do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *piVar2 == *piVar3;
        piVar2 = piVar2 + 1;
        piVar3 = piVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
        iVar1 = 4;
        bVar4 = true;
        piVar2 = DAT_006dd2c4;
        do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar4 = *param_2 == *piVar2;
            param_2 = param_2 + 1;
            piVar2 = piVar2 + 1;
        } while (bVar4);
        if (!bVar4) {
            return 0x80004002;
        }
    }
    *param_3 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_1));
    reinterpret_cast<PFN_THISCALL_VOID>(
        *reinterpret_cast<uint32_t*>(addr32(*param_1 + 4)))(param_1);
    return 0;
}

// 0x629497 — observed shape
// Allocate 0x10 and construct in place; call vtable +0x18 with the tag, release
// via vtable +0x14 on failure. 0x8876086C / 0x8007000E on failure.
int32_t FUN_00629497(uint32_t param_1, uint32_t* param_2) {
    int32_t iVar1;
    int32_t* piVar2;

    if (param_2 == nullptr) {
        iVar1 = -0x7789f794;   // 0x8876086C
    } else {
        void* pNew = FUN_00533c78(0x10);
        iVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(pNew));
        if (pNew == nullptr) {
            piVar2 = nullptr;
        } else {
            FUN_0062947f(pNew);
            piVar2 = static_cast<int32_t*>(pNew);
        }
        if (piVar2 == nullptr) {
            iVar1 = -0x7ff8fff2;   // 0x8007000E
        } else {
            iVar1 = reinterpret_cast<PFN_THISCALL_INT_PARAM>(
                *reinterpret_cast<uint32_t*>(addr32(*piVar2 + 0x18)))(piVar2, param_1);
            if (iVar1 < 0) {
                reinterpret_cast<void(__thiscall*)(void*, int32_t)>(
                    *reinterpret_cast<uint32_t*>(addr32(*piVar2 + 0x14)))(piVar2, 1);
            } else {
                *param_2 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar2));
                iVar1 = 0;
            }
        }
    }
    return iVar1;
}

// 0x629504 — observed shape (in_ECX = self)
// Free owned buffer at +8 and unlink from the circular list at +0xc/+0x10.
void FUN_00629504(void* self) {
    uint8_t* base = static_cast<uint8_t*>(self);

    if (*reinterpret_cast<uint32_t*>(base + 8) != 0) {
        operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(
            *reinterpret_cast<uint32_t*>(base + 8))));
        *reinterpret_cast<uint32_t*>(base + 8) = 0;
    }
    *reinterpret_cast<uint32_t*>(
        addr32(*reinterpret_cast<int32_t*>(base + 0x10) + 0xc)) =
        *reinterpret_cast<uint32_t*>(base + 0xc);
    *reinterpret_cast<uint32_t*>(
        addr32(*reinterpret_cast<int32_t*>(base + 0xc) + 0x10)) =
        *reinterpret_cast<uint32_t*>(base + 0x10);
}

// 0x629545 — observed shape
// Match two structured tags (5 dwords), compare the trailing C strings
// byte-wise and then case-insensitively; recurse over the +5 child list.
int32_t FUN_00629545(int32_t param_1, int32_t* param_2, int32_t param_3, int32_t* param_4,
                     uint32_t* param_5) {
    uint8_t bVar1;
    int32_t* piVar2;
    int32_t* piVar3;
    uint32_t uVar4;
    int32_t* piVar5;
    int32_t iVar6;
    uint8_t* pbVar7;
    int32_t* _Str2;
    uint32_t uVar8;
    bool bVar9;
    uint8_t* local_c;

    piVar5 = param_4;
    piVar2 = reinterpret_cast<int32_t*>(*param_2);
    piVar3 = reinterpret_cast<int32_t*>(*param_4);
    if (((piVar2[1] == piVar3[1]) && (*piVar2 == *piVar3)) && (piVar2[4] == piVar3[4])) {
        if (*reinterpret_cast<int32_t*>(addr32(piVar2[2] + param_1)) == 0) {
            local_c = nullptr;
        } else {
            local_c = reinterpret_cast<uint8_t*>(addr32(piVar2[2] + param_1)) + 4;
        }
        if (*reinterpret_cast<int32_t*>(addr32(piVar3[2] + param_3)) == 0) {
            pbVar7 = nullptr;
        } else {
            pbVar7 = reinterpret_cast<uint8_t*>(addr32(piVar3[2] + param_3)) + 4;
        }
        _Str2 = nullptr;
        if (*reinterpret_cast<int32_t*>(addr32(piVar2[3] + param_1)) == 0) {
            param_4 = nullptr;
        } else {
            param_4 = reinterpret_cast<int32_t*>(addr32(piVar2[3] + param_1)) + 1;
        }
        if (*reinterpret_cast<int32_t*>(addr32(piVar3[3] + param_3)) != 0) {
            _Str2 = reinterpret_cast<int32_t*>(addr32(piVar3[3] + param_3)) + 1;
        }
        if (local_c != nullptr) {
            if (pbVar7 == nullptr) {
                return -0x7fffbffb;
            }
            for (;;) {
                bVar1 = *local_c;
                bVar9 = bVar1 < *pbVar7;
                if (bVar1 != *pbVar7) {
                    pbVar7 = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(
                        (1 - static_cast<uint32_t>(bVar9)) -
                        static_cast<uint32_t>(bVar9 != 0)));
                    break;
                }
                if (bVar1 == 0) {
                    pbVar7 = nullptr;
                    break;
                }
                bVar1 = local_c[1];
                bVar9 = bVar1 < pbVar7[1];
                if (bVar1 != pbVar7[1]) {
                    pbVar7 = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(
                        (1 - static_cast<uint32_t>(bVar9)) -
                        static_cast<uint32_t>(bVar9 != 0)));
                    break;
                }
                local_c = local_c + 2;
                pbVar7 = pbVar7 + 2;
                if (bVar1 == 0) {
                    pbVar7 = nullptr;
                    break;
                }
            }
        }
        if (pbVar7 == nullptr) {
            if (param_4 != nullptr) {
                if (_Str2 == nullptr) {
                    return -0x7fffbffb;
                }
                _Str2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(
                    _stricmp(reinterpret_cast<const char*>(param_4),
                             reinterpret_cast<const char*>(_Str2))));
            }
            if (_Str2 == nullptr) {
                piVar2 = reinterpret_cast<int32_t*>(*param_2);
                iVar6 = piVar2[1];
                if (-1 < iVar6) {
                    if (iVar6 < 4) {
                        if ((piVar2[5] == *reinterpret_cast<int32_t*>(
                                                addr32(*piVar5 + 0x14))) &&
                            (piVar2[6] == *reinterpret_cast<int32_t*>(
                                                addr32(*piVar5 + 0x18)))) {
                            *param_2 = static_cast<int32_t>(
                                reinterpret_cast<intptr_t>(piVar2 + 7));
                            *piVar5 = *piVar5 + 0x1c;
                            return 0;
                        }
                    } else {
                        if (iVar6 == 4) {
                            iVar6 = *piVar2;
                            if ((4 < iVar6) &&
                                ((iVar6 < 10 || ((0xe < iVar6 && (iVar6 < 0x11)))))) {
                                *param_5 = 1;
                            }
                            *param_2 = *param_2 + 0x14;
                            *piVar5 = *piVar5 + 0x14;
                            return 0;
                        }
                        if ((iVar6 == 5) &&
                            (uVar4 = static_cast<uint32_t>(piVar2[5]),
                             uVar4 == *reinterpret_cast<uint32_t*>(
                                           addr32(*piVar5 + 0x14)))) {
                            *param_2 = static_cast<int32_t>(
                                reinterpret_cast<intptr_t>(piVar2 + 6));
                            *piVar5 = *piVar5 + 0x18;
                            uVar8 = 0;
                            if (uVar4 == 0) {
                                return 0;
                            }
                            do {
                                iVar6 = FUN_00629545(param_1, param_2, param_3, piVar5, param_5);
                                if (iVar6 < 0) {
                                    return iVar6;
                                }
                                uVar8 = uVar8 + 1;
                            } while (uVar8 < uVar4);
                            return iVar6;
                        }
                    }
                }
            }
        }
    }
    return -0x7fffbffb;
}

// 0x6296e0 — observed shape
// Wrapper: zero the out flag then forward to FUN_00629545. The caller consumes
// EAX (0x62a1a7), so the status returned by the forward call is preserved.
int32_t FUN_006296e0(uint32_t param_1, int32_t param_2, uint32_t param_3, int32_t param_4,
                     uint32_t* param_5) {
    *param_5 = 0;
    return FUN_00629545(param_1, reinterpret_cast<int32_t*>(&param_2),
                        static_cast<int32_t>(param_3),
                        reinterpret_cast<int32_t*>(&param_4), param_5);
}

// 0x629703 — observed shape
// Compute required buffer size for a token and advance the cursor; type 4/5
// have 0x14/0x18-byte records, type 5 recurses per child with stride 5.
int32_t FUN_00629703(int32_t param_1, int32_t* param_2, int32_t* param_3, int32_t* param_4,
                     int32_t* param_5) {
    int32_t* piVar7;
    int32_t* piVar6;
    int32_t* piVar5;
    int32_t* piVar8;
    int32_t iVar10;
    int32_t local_c;
    int32_t local_10;
    int32_t local_8;
    uint32_t local_14;
    int32_t local_18;
    const char* s1;
    const char* s2;
    uint32_t n1;
    uint32_t n2;
    int32_t iVar9;

    piVar7 = param_5;
    piVar6 = param_4;
    piVar5 = param_3;
    piVar8 = reinterpret_cast<int32_t*>(*param_2);
    iVar10 = piVar8[1];
    local_c = piVar8[4];
    local_10 = *piVar8;
    local_8 = 0;
    if (local_c == 0) {
        local_c = 1;
    }
    if (*reinterpret_cast<int32_t*>(addr32(piVar8[2] + param_1)) == 0) {
        s1 = nullptr;
    } else {
        s1 = reinterpret_cast<const char*>(addr32(piVar8[2] + param_1)) + 4;
    }
    if (*reinterpret_cast<int32_t*>(addr32(piVar8[3] + param_1)) == 0) {
        piVar8 = nullptr;
    } else {
        piVar8 = reinterpret_cast<int32_t*>(addr32(piVar8[3] + param_1)) + 1;
    }
    n1 = 0;
    {
        const char* p = s1;
        do {
            n1 = n1 + 1;
        } while (*p++ != '\0');
    }
    n2 = 0;
    if (piVar8 != nullptr) {
        const char* p = reinterpret_cast<const char*>(piVar8);
        do {
            n2 = n2 + 1;
        } while (*p++ != '\0');
    }
    *param_5 = static_cast<int32_t>(
        (((n1 >> 2) + static_cast<uint32_t>((n1 & 3) != 0) +
          ((n2 >> 2) + static_cast<uint32_t>((n2 & 3) != 0))) * 4 + 8));
    *param_4 = 0;
    *param_3 = 0;
    if (iVar10 < 0) {
        return -0x7fffbffb;
    }
    if (iVar10 < 2) {
        local_c = local_c << 2;
    } else {
        if (3 < iVar10) {
            if (iVar10 != 4) {
                if (iVar10 != 5) {
                    return -0x7fffbffb;
                }
                local_14 = *reinterpret_cast<uint32_t*>(addr32(*param_2 + 0x14));
                param_5 = nullptr;
                *param_2 = *param_2 + 0x18;
                *param_3 = 0x18;
                if (local_14 != 0) {
                    local_18 = 5;
                    do {
                        local_8 = FUN_00629703(param_1, param_2, param_3,
                                               reinterpret_cast<int32_t*>(&param_4), &local_18);
                        if (local_8 < 0) {
                            return local_8;
                        }
                        *piVar6 = *piVar6 + static_cast<int32_t>(
                            reinterpret_cast<intptr_t>(param_4));
                        *piVar5 = *piVar5 + static_cast<int32_t>(
                            reinterpret_cast<intptr_t>(param_3));
                        *piVar7 = *piVar7 + local_18;
                        param_5 = reinterpret_cast<int32_t*>(
                            reinterpret_cast<intptr_t>(param_5) + 1);
                    } while (reinterpret_cast<uintptr_t>(param_5) <
                             static_cast<uintptr_t>(local_14));
                }
                *piVar6 = *piVar6 * local_c;
                return local_8;
            }
            iVar10 = 0x14;
            *param_3 = 0x14;
            if (local_10 < 4) {
                return -0x7fffbffb;
            }
            if (9 < local_10) {
                if (local_10 < 0xf) {
                    return -0x7fffbffb;
                }
                if (0x10 < local_10) {
                    return -0x7fffbffb;
                }
            }
            *param_4 = local_c << 2;
            goto LAB_0062989c;
        }
        local_c = local_c << 4;
    }
    iVar10 = 0x1c;
    *param_4 = local_c;
    *param_3 = 0x1c;
    if (((local_10 != 1) && (local_10 != 2)) && (local_10 != 3)) {
        return -0x7fffbffb;
    }
    *param_4 = *param_4 << 2;
LAB_0062989c:
    *param_2 = *param_2 + iVar10;
    return 0;
}

// 0x6298b9 — observed shape
// Serialize one token into the scratch buffer: header fields, two counted
// strings (count dword + padded bytes), then type-specific payload copies.
int32_t FUN_006298b9(int32_t param_1, int32_t* param_2, int32_t* param_3, int32_t param_4,
                     int32_t* param_5, int32_t* param_6, int32_t* param_7, int32_t* param_8) {
    char* pcVar1;
    int32_t iVar2;
    bool bVar3;
    int32_t iVar4;
    int32_t* piVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int32_t iVar8;
    uint32_t* puVar9;
    int32_t* piVar10;
    uint32_t* puVar11;
    int32_t* local_10;
    int32_t* local_c;
    int32_t local_8;
    uint32_t n1;
    uint32_t n2;

    piVar5 = param_5;
    *reinterpret_cast<uint32_t*>(addr32(*param_6 + 4)) =
        *reinterpret_cast<uint32_t*>(addr32(*param_2 + 4));
    *reinterpret_cast<uint32_t*>(addr32(*param_6)) =
        *reinterpret_cast<uint32_t*>(addr32(*param_2));
    *reinterpret_cast<uint32_t*>(addr32(*param_6 + 0x10)) =
        *reinterpret_cast<uint32_t*>(addr32(*param_2 + 0x10));
    *reinterpret_cast<int32_t*>(addr32(*param_6 + 8)) = *param_5;
    piVar10 = reinterpret_cast<int32_t*>(*param_2);
    iVar8 = piVar10[1];
    iVar2 = *piVar10;
    local_8 = 0;
    bVar3 = false;
    param_5 = reinterpret_cast<int32_t*>(1);
    if (piVar10[4] != 0) {
        param_5 = reinterpret_cast<int32_t*>(piVar10[4]);
    }
    if (*reinterpret_cast<int32_t*>(addr32(piVar10[2] + param_1)) == 0) {
        local_c = nullptr;
    } else {
        local_c = reinterpret_cast<int32_t*>(addr32(piVar10[2] + param_1)) + 1;
    }
    if (*reinterpret_cast<int32_t*>(addr32(piVar10[3] + param_1)) == 0) {
        local_10 = nullptr;
    } else {
        local_10 = reinterpret_cast<int32_t*>(addr32(piVar10[3] + param_1)) + 1;
    }
    n1 = 0;
    {
        const char* p = reinterpret_cast<const char*>(local_c);
        do {
            n1 = n1 + 1;
        } while (*p++ != '\0');
    }
    // Count dword at param_4 + *piVar5 (corpus stores the count in a pointer slot).
    *reinterpret_cast<uint32_t*>(addr32(param_4 + *piVar5)) = n1;
    *piVar5 = *piVar5 + 4;
    pcVar1 = reinterpret_cast<char*>(addr32(param_4 + *piVar5));
    piVar10 = reinterpret_cast<int32_t*>(pcVar1);
    for (uVar6 = n1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *piVar10 = *local_c;
        local_c = local_c + 1;
        piVar10 = piVar10 + 1;
    }
    for (uVar6 = n1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *reinterpret_cast<char*>(piVar10) = static_cast<char>(*local_c);
        local_c = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_c) + 1);
        piVar10 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(piVar10) + 1);
    }
    *piVar5 = *piVar5 + static_cast<int32_t>(
        ((static_cast<uint32_t>((n1 & 3) != 0) + (n1 >> 2)) * 4));
    *reinterpret_cast<int32_t*>(addr32(*param_6 + 0xc)) = *piVar5;

    if (local_10 == nullptr) {
        *reinterpret_cast<uint32_t*>(addr32(param_4 + *piVar5)) = 0;
        *piVar5 = *piVar5 + 4;
    } else {
        n2 = 0;
        {
            const char* p = reinterpret_cast<const char*>(local_10);
            do {
                n2 = n2 + 1;
            } while (*p++ != '\0');
        }
        *reinterpret_cast<uint32_t*>(addr32(param_4 + *piVar5)) = n2;
        *piVar5 = *piVar5 + 4;
        piVar10 = reinterpret_cast<int32_t*>(addr32(param_4 + *piVar5));
        for (uVar6 = n2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *piVar10 = *local_10;
            local_10 = local_10 + 1;
            piVar10 = piVar10 + 1;
        }
        for (uVar6 = n2 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *reinterpret_cast<char*>(piVar10) = static_cast<char>(*local_10);
            local_10 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_10) + 1);
            piVar10 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(piVar10) + 1);
        }
        *piVar5 = *piVar5 + static_cast<int32_t>(
            ((static_cast<uint32_t>((n2 & 3) != 0) + (n2 >> 2)) * 4));
    }

    if (-1 < iVar8) {
        if (1 < iVar8) {
            if (3 < iVar8) {
                if (iVar8 != 4) {
                    if (iVar8 != 5) {
                        return -0x7fffbffb;
                    }
                    *reinterpret_cast<uint32_t*>(addr32(*param_6 + 0x14)) =
                        *reinterpret_cast<uint32_t*>(addr32(*param_2 + 0x14));
                    uVar6 = *reinterpret_cast<uint32_t*>(addr32(*param_2 + 0x14));
                    *param_2 = *param_2 + 0x18;
                    *param_6 = *param_6 + 0x18;
                    iVar8 = *piVar5;
                    iVar2 = *param_2;
                    iVar4 = *param_6;
                    do {
                        if (param_5 == nullptr) {
                            return local_8;
                        }
                        local_10 = nullptr;
                        *param_2 = iVar2;
                        *param_6 = iVar4;
                        *piVar5 = iVar8;
                        if (uVar6 != 0) {
                            do {
                                local_8 = FUN_006298b9(param_1, param_2, param_3, param_4,
                                                       piVar5, param_6, param_7, param_8);
                                if (local_8 < 0) {
                                    return local_8;
                                }
                                local_10 = reinterpret_cast<int32_t*>(
                                    reinterpret_cast<intptr_t>(local_10) + 1);
                            } while (reinterpret_cast<uintptr_t>(local_10) <
                                     static_cast<uintptr_t>(uVar6));
                        }
                        param_5 = reinterpret_cast<int32_t*>(
                            reinterpret_cast<intptr_t>(param_5) - 1);
                    } while (true);
                }
                if (iVar2 < 4) {
                    return -0x7fffbffb;
                }
                if (9 < iVar2) {
                    if (iVar2 < 0xf) {
                        return -0x7fffbffb;
                    }
                    if (0x10 < iVar2) {
                        return -0x7fffbffb;
                    }
                }
                if (param_5 != nullptr) {
                    param_4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_5));
                    do {
                        *reinterpret_cast<uint32_t*>(addr32(*param_7)) =
                            *reinterpret_cast<uint32_t*>(addr32(*param_8));
                        *param_8 = *param_8 + 1;
                        *param_3 = *param_3 + 4;
                        *param_7 = *param_7 + 4;
                        param_4 = param_4 + -1;
                    } while (param_4 != 0);
                }
                *param_2 = *param_2 + 0x14;
                *param_6 = *param_6 + 0x14;
                return 0;
            }
            bVar3 = true;
        }
        *reinterpret_cast<uint32_t*>(addr32(*param_6 + 0x14)) =
            *reinterpret_cast<uint32_t*>(addr32(*param_2 + 0x14));
        *reinterpret_cast<uint32_t*>(addr32(*param_6 + 0x18)) =
            *reinterpret_cast<uint32_t*>(addr32(*param_2 + 0x18));
        if (bVar3) {
            uVar6 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_5)) << 4;
        } else {
            uVar6 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_5)) << 2;
        }
        if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
            puVar9 = reinterpret_cast<uint32_t*>(*param_3);
            puVar11 = reinterpret_cast<uint32_t*>(*param_7);
            for (uVar7 = uVar6 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar11 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar11 = puVar11 + 1;
            }
            *param_3 = *param_3 + static_cast<int32_t>(uVar6 * 4);
            *param_7 = *param_7 + static_cast<int32_t>(uVar6 * 4);
            *param_2 = *param_2 + 0x1c;
            *param_6 = *param_6 + 0x1c;
            return 0;
        }
    }
    return -0x7fffbffb;
}

// 0x629b6b — observed shape
// Thin wrapper: place the scratch offset at base+len1+len2+tail, zero the out
// count and serialize at the running offset.
void FUN_00629b6b(uint32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4,
                  int32_t param_5, int32_t param_6, int32_t param_7, int32_t* param_8) {
    int32_t iVar1;
    int32_t* puVar2;

    puVar2 = param_8;
    iVar1 = param_4;
    param_4 = param_5 + param_4 + param_6;
    *param_8 = 0;
    param_8 = reinterpret_cast<int32_t*>(addr32(param_4 + param_7));
    FUN_006298b9(param_1, reinterpret_cast<int32_t*>(&param_2),
                 reinterpret_cast<int32_t*>(&param_3), iVar1, &param_5, &param_4,
                 reinterpret_cast<int32_t*>(&param_8), puVar2);
}

// 0x629bb0 — observed shape
// Skip one token: advance the data cursor by the token size and the token
// cursor by 0x1c/0x14; type 5 recurses per child.
int32_t FUN_00629bb0(int32_t* param_1, int32_t* param_2, int32_t* param_3) {
    int32_t* piVar1;
    int32_t iVar2;
    int32_t iVar3;
    uint32_t uVar4;
    int32_t* piVar5;
    uint32_t local_c;
    int32_t local_8;

    piVar5 = param_1;
    local_8 = 0;
    piVar1 = reinterpret_cast<int32_t*>(*param_1);
    iVar2 = *piVar1;
    iVar3 = piVar1[1];
    param_1 = reinterpret_cast<int32_t*>(1);
    if (piVar1[4] != 0) {
        param_1 = reinterpret_cast<int32_t*>(piVar1[4]);
    }
    if (-1 < iVar3) {
        if (iVar3 < 4) {
            if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
                *param_2 = *param_2 + piVar1[6] * piVar1[5] *
                    static_cast<int32_t>(reinterpret_cast<intptr_t>(param_1)) * 4;
                *piVar5 = *piVar5 + 0x1c;
                return 0;
            }
        } else if (iVar3 == 4) {
            if ((3 < iVar2) && ((iVar2 < 10 || ((0xe < iVar2 && (iVar2 < 0x11)))))) {
                for (; param_1 != nullptr;
                     param_1 = reinterpret_cast<int32_t*>(
                         reinterpret_cast<intptr_t>(param_1) - 1)) {
                    *reinterpret_cast<uint32_t*>(addr32(*param_3)) =
                        *reinterpret_cast<uint32_t*>(addr32(*param_2));
                    *param_3 = *param_3 + 4;
                    *param_2 = *param_2 + 4;
                }
                *piVar5 = *piVar5 + 0x14;
                return 0;
            }
        } else if (iVar3 == 5) {
            uVar4 = static_cast<uint32_t>(piVar1[5]);
            *piVar5 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1 + 6));
            do {
                if (param_1 == nullptr) {
                    return local_8;
                }
                local_c = 0;
                *piVar5 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1 + 6));
                if (uVar4 != 0) {
                    do {
                        local_8 = FUN_00629bb0(piVar5, param_2, param_3);
                        if (local_8 < 0) {
                            return local_8;
                        }
                        local_c = local_c + 1;
                    } while (local_c < uVar4);
                }
                param_1 = reinterpret_cast<int32_t*>(
                    reinterpret_cast<intptr_t>(param_1) - 1);
            } while (true);
        }
    }
    return -0x7fffbffb;
}

// 0x629cba — observed shape
// Copy/skip one token between two cursors; format switch decides 4-byte
// element copies vs. cursor-only advance; type 5 recurses per child.
int32_t FUN_00629cba(int32_t* param_1, int32_t* param_2, int32_t* param_3) {
    int32_t* piVar1;
    int32_t* piVar2;
    int32_t iVar3;
    int32_t iVar4;
    uint32_t uVar5;
    int32_t iVar6;
    uint32_t* puVar7;
    int32_t iVar8;
    uint32_t* puVar9;

    piVar2 = param_1;
    piVar1 = reinterpret_cast<int32_t*>(*param_1);
    iVar6 = piVar1[1];
    iVar4 = *piVar1;
    iVar8 = piVar1[4];
    iVar3 = 0;
    if (iVar8 == 0) {
        iVar8 = 1;
    }
    if (-1 < iVar6) {
        if (iVar6 < 4) {
            uVar5 = static_cast<uint32_t>(piVar1[6] * piVar1[5] * iVar8);
            if (((iVar4 == 1) || (iVar4 == 2)) || (iVar4 == 3)) {
                iVar6 = static_cast<int32_t>(uVar5 * 4);
                puVar7 = reinterpret_cast<uint32_t*>(*param_3);
                puVar9 = reinterpret_cast<uint32_t*>(*param_2);
                for (uVar5 = uVar5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar9 = *puVar7;
                    puVar7 = puVar7 + 1;
                    puVar9 = puVar9 + 1;
                }
                *param_2 = *param_2 + iVar6;
                *param_3 = *param_3 + iVar6;
                *param_1 = *param_1 + 0x1c;
                return 0;
            }
        } else if (iVar6 == 4) {
            switch (iVar4) {
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 0xf:
            case 0x10:
                *param_2 = *param_2 + iVar8 * 4;
                *param_3 = *param_3 + iVar8 * 4;
                [[fallthrough]];
            case 10:
            case 0xb:
            case 0xc:
            case 0xd:
            case 0xe:
            case 0x11:
            case 0x12:
                *param_1 = *param_1 + 0x14;
                return 0;
            }
        } else if (iVar6 == 5) {
            uVar5 = static_cast<uint32_t>(piVar1[5]);
            *param_1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1 + 6));
            do {
                if (iVar8 == 0) {
                    return iVar3;
                }
                param_1 = nullptr;
                *piVar2 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1 + 6));
                if (uVar5 != 0) {
                    do {
                        iVar3 = FUN_00629cba(piVar2, param_2, param_3);
                        if (iVar3 < 0) {
                            return iVar3;
                        }
                        param_1 = reinterpret_cast<int32_t*>(
                            reinterpret_cast<intptr_t>(param_1) + 1);
                    } while (reinterpret_cast<uintptr_t>(param_1) <
                             static_cast<uintptr_t>(uVar5));
                }
                iVar8 = iVar8 + -1;
            } while (true);
        }
    }
    return -0x7fffbffb;
}

// 0x629de4 — observed shape
// Copy node-indexed records from the source table to the destination table,
// AddRef/Release on the contained interfaces and merge flag bit 1.
int32_t FUN_00629de4(int32_t* param_1, int32_t* param_2, int32_t* param_3, int32_t* param_4) {
    int32_t* piVar1;
    int32_t iVar2;
    uint32_t uVar3;
    int32_t iVar4;
    bool bVar5;
    bool bVar6;
    uint32_t local_c;
    int32_t local_8;
    int32_t idx;
    int32_t* obj;

    piVar1 = reinterpret_cast<int32_t*>(*param_1);
    local_8 = 0;
    iVar4 = piVar1[1];
    iVar2 = *piVar1;
    local_c = static_cast<uint32_t>(piVar1[4]);
    if (local_c == 0) {
        local_c = 1;
    }
    if (-1 < iVar4) {
        if (iVar4 < 4) {
            if (((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 3)) {
                *param_2 = *param_2 + piVar1[6] * piVar1[5] *
                    static_cast<int32_t>(local_c) * 4;
                *param_1 = *param_1 + 0x1c;
                return 0;
            }
            return -0x7fffbffb;
        }
        if (iVar4 != 4) {
            if (iVar4 != 5) {
                return -0x7fffbffb;
            }
            uVar3 = static_cast<uint32_t>(piVar1[5]);
            *param_1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1 + 6));
            iVar4 = static_cast<int32_t>(local_c);
            do {
                if (iVar4 == 0) {
                    return local_8;
                }
                local_c = 0;
                *param_1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1 + 6));
                if (uVar3 != 0) {
                    do {
                        local_8 = FUN_00629de4(param_1, param_2, param_3, param_4);
                        if (local_8 < 0) {
                            return local_8;
                        }
                        local_c = local_c + 1;
                    } while (local_c < uVar3);
                }
                iVar4 = iVar4 + -1;
            } while (true);
        }
        if (iVar2 < 0x10) {
            if (iVar2 == 0xf) {
                if (local_c != 0) {
                    do {
                        idx = *reinterpret_cast<int32_t*>(addr32(*param_2)) * 4 + param_4[2];
                        iVar4 = *reinterpret_cast<int32_t*>(addr32(*param_4 + 0x18)) +
                            *reinterpret_cast<int32_t*>(addr32(idx)) * 0x18;
                        idx = *reinterpret_cast<int32_t*>(addr32(*param_2)) * 4 + param_3[2];
                        iVar2 = *reinterpret_cast<int32_t*>(addr32(*param_3 + 0x18)) +
                            *reinterpret_cast<int32_t*>(addr32(idx)) * 0x18;
                        obj = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4))));
                        if (obj != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*obj + 4)))(obj);
                        }
                        obj = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 8))));
                        if (obj != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*obj + 4)))(obj);
                        }
                        piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4))));
                        if (piVar1 != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*piVar1 + 8)))(piVar1);
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4)) = 0;
                        }
                        piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 8))));
                        if (piVar1 != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*piVar1 + 8)))(piVar1);
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 8)) = 0;
                        }
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4));
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 8)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 8));
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 0x14)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 0x14)) ^
                            ((((*reinterpret_cast<int32_t*>(
                                   addr32(iVar2 + 0x14)) << 0x1e) >> 0x1e) ^
                              *reinterpret_cast<uint32_t*>(addr32(iVar4 + 0x14))) & 2);
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 0xc)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 0xc));
                        *param_2 = *param_2 + 4;
                        local_c = local_c + -1;
                    } while (local_c != 0);
                }
                goto LAB_0062a0fb;
            }
            if (iVar2 == 4) {
                if (local_c != 0) {
                    do {
                        idx = *reinterpret_cast<int32_t*>(addr32(*param_2)) * 4 + param_4[2];
                        iVar4 = *reinterpret_cast<int32_t*>(addr32(*param_4 + 0x18)) +
                            *reinterpret_cast<int32_t*>(addr32(idx)) * 0x18;
                        idx = *reinterpret_cast<int32_t*>(addr32(*param_2)) * 4 + param_3[2];
                        iVar2 = *reinterpret_cast<int32_t*>(addr32(*param_3 + 0x18)) +
                            *reinterpret_cast<int32_t*>(addr32(idx)) * 0x18;
                        obj = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4))));
                        if (obj != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*obj + 4)))(obj);
                        }
                        piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4))));
                        if (piVar1 != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*piVar1 + 8)))(piVar1);
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4)) = 0;
                        }
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4));
                        *param_2 = *param_2 + 4;
                        local_c = local_c + -1;
                    } while (local_c != 0);
                }
                goto LAB_0062a0fb;
            }
            if (iVar2 < 5) {
                return -0x7fffbffb;
            }
            if (iVar2 < 10) {
                if (local_c != 0) {
                    do {
                        idx = *reinterpret_cast<int32_t*>(addr32(*param_2)) * 4 + param_4[2];
                        iVar4 = *reinterpret_cast<int32_t*>(addr32(*param_4 + 0x18)) +
                            *reinterpret_cast<int32_t*>(addr32(idx)) * 0x18;
                        idx = *reinterpret_cast<int32_t*>(addr32(*param_2)) * 4 + param_3[2];
                        iVar2 = *reinterpret_cast<int32_t*>(addr32(*param_3 + 0x18)) +
                            *reinterpret_cast<int32_t*>(addr32(idx)) * 0x18;
                        obj = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4))));
                        if (obj != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*obj + 4)))(obj);
                        }
                        piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4))));
                        if (piVar1 != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*piVar1 + 8)))(piVar1);
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4)) = 0;
                        }
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4));
                        *param_2 = *param_2 + 4;
                        local_c = local_c + -1;
                    } while (local_c != 0);
                }
                goto LAB_0062a0fb;
            }
            bVar6 = SBORROW4(iVar2, 0xe);
            iVar4 = iVar2 + -0xe;
            bVar5 = iVar2 == 0xe;
        } else {
            if (iVar2 == 0x10) {
                if (local_c != 0) {
                    do {
                        idx = *reinterpret_cast<int32_t*>(addr32(*param_2)) * 4 + param_4[2];
                        iVar4 = *reinterpret_cast<int32_t*>(addr32(*param_4 + 0x18)) +
                            *reinterpret_cast<int32_t*>(addr32(idx)) * 0x18;
                        idx = *reinterpret_cast<int32_t*>(addr32(*param_2)) * 4 + param_3[2];
                        iVar2 = *reinterpret_cast<int32_t*>(addr32(*param_3 + 0x18)) +
                            *reinterpret_cast<int32_t*>(addr32(idx)) * 0x18;
                        obj = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4))));
                        if (obj != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*obj + 4)))(obj);
                        }
                        obj = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 8))));
                        if (obj != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*obj + 4)))(obj);
                        }
                        piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4))));
                        if (piVar1 != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*piVar1 + 8)))(piVar1);
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4)) = 0;
                        }
                        piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 8))));
                        if (piVar1 != nullptr) {
                            reinterpret_cast<PFN_THISCALL_VOID>(
                                *reinterpret_cast<uint32_t*>(addr32(*piVar1 + 8)))(piVar1);
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 8)) = 0;
                        }
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 4)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4));
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 8)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 8));
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 0x14)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar4 + 0x14)) ^
                            ((((*reinterpret_cast<int32_t*>(
                                   addr32(iVar2 + 0x14)) << 0x1e) >> 0x1e) ^
                              *reinterpret_cast<uint32_t*>(addr32(iVar4 + 0x14))) & 2);
                        *reinterpret_cast<uint32_t*>(addr32(iVar4 + 0xc)) =
                            *reinterpret_cast<uint32_t*>(addr32(iVar2 + 0xc));
                        *param_2 = *param_2 + 4;
                        local_c = local_c + -1;
                    } while (local_c != 0);
                }
                goto LAB_0062a0fb;
            }
            if (iVar2 < 0x11) {
                return -0x7fffbffb;
            }
            bVar6 = SBORROW4(iVar2, 0x12);
            iVar4 = iVar2 + -0x12;
            bVar5 = iVar2 == 0x12;
        }
        if (bVar5 || bVar6 != (iVar4 < 0)) {
LAB_0062a0fb:
            *param_1 = *param_1 + 0x14;
            return 0;
        }
    }
    return -0x7fffbffb;
}

// 0x62a12a — observed shape
// Guarded forward to FUN_00629de4: no-op when target equals source or source
// token pointer is null.
uint32_t FUN_0062a12a(int32_t param_1, int32_t param_2, int32_t* param_3, int32_t* param_4) {
    uint32_t uVar1;

    if ((param_3 == param_4) || (*param_3 == 0)) {
        uVar1 = 0;
    } else {
        uVar1 = static_cast<uint32_t>(FUN_00629de4(
            reinterpret_cast<int32_t*>(&param_1), reinterpret_cast<int32_t*>(&param_2),
            param_4, param_3));
    }
    return uVar1;
}

// 0x62a155 — observed shape (in_ECX = self)
// Rebase stored line offsets of every node onto the current buffer base.
uint32_t FUN_0062a155(void* self) {
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t iVar1;
    int32_t iVar2;
    int32_t* p;

    for (iVar1 = *reinterpret_cast<int32_t*>(base + 0x1c); iVar1 != 0;
         iVar1 = *reinterpret_cast<int32_t*>(addr32(iVar1) + 0x20)) {
        for (iVar2 = *reinterpret_cast<int32_t*>(addr32(iVar1) + 0x1c);
             iVar2 != iVar1 + 0xc;
             iVar2 = *reinterpret_cast<int32_t*>(addr32(iVar2) + 0x10)) {
            p = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<uint32_t*>(addr32(iVar2 + 4))));
            *p = p[0xc] + *reinterpret_cast<int32_t*>(base + 0x10);
        }
    }
    return 0;
}

// 0x62a186 — observed shape (in_ECX = self)
// Scalar deleting destructor: base cleanup then conditional free.
void FUN_0062a186(void* self, uint8_t param_1) {
    FUN_00629504(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x62a1a7 — observed shape (in_ECX = self)
// Append token `param_1` described by `param_2` to the growing scratch buffer
// owned by self; grow the buffer by powers of two (min 0x10000), build the
// 0x24-byte node with an 0x14-byte child entry, and link it into the lists.
int32_t FUN_0062a1a7(void* self, int32_t param_1, int32_t* param_2) {
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t* piVar1;
    uint8_t* puVar2;
    int32_t iVar3;
    int32_t* piVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    int32_t local_20;
    int32_t local_1c;
    int32_t local_18;
    int32_t local_14;
    int32_t local_10;
    int32_t local_c;
    int32_t local_8;

    piVar1 = param_2;
    local_20 = 0;
    local_1c = 0;
    local_10 = 0;
    local_14 = 0;
    local_c = param_2[0xb] + *reinterpret_cast<int32_t*>(addr32(param_1) + 0x20);
    local_18 = param_2[0xc] + *reinterpret_cast<int32_t*>(addr32(param_1) + 0x20);
    for (piVar4 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
             *reinterpret_cast<uint32_t*>(base + 0x1c)));
         piVar4 != nullptr;
         piVar4 = reinterpret_cast<int32_t*>(piVar4[8])) {
        iVar3 = FUN_006296e0(
            *reinterpret_cast<uint32_t*>(addr32(param_1) + 0x20), local_c,
            *reinterpret_cast<uint32_t*>(base + 0x10),
            *piVar4 + *reinterpret_cast<int32_t*>(base + 0x10),
            reinterpret_cast<uint32_t*>(&local_14));
        if (-1 < iVar3) {
            if (((local_14 != 0) &&
                 (*reinterpret_cast<int32_t*>(addr32(piVar4[7])) != 0)) &&
                (*reinterpret_cast<int32_t*>(addr32(param_1) + 0xc) !=
                 *reinterpret_cast<int32_t*>(
                     addr32(*reinterpret_cast<int32_t*>(addr32(piVar4[7])) + 0xc)))) {
                return -0x7fffbffb;
            }
            if ((piVar4 + 3 == reinterpret_cast<int32_t*>(piVar4[7])) &&
                (local_8 = FUN_00629dca(
                     local_c, piVar4[1] + *reinterpret_cast<int32_t*>(base + 0x10),
                     local_18),
                 local_8 < 0)) {
                return local_8;
            }
            goto LAB_0062a38f;
        }
    }
    local_8 = local_c;
    local_8 = FUN_00629703(
        *reinterpret_cast<uint32_t*>(addr32(param_1) + 0x20), &local_8, &local_14,
        &local_1c, &local_10);
    if (local_8 < 0) {
        return local_8;
    }
    puVar2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
        static_cast<intptr_t>(local_1c) + local_10 +
        *reinterpret_cast<int32_t*>(base + 0x14) + local_14));
    if (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
            *reinterpret_cast<int32_t*>(base + 0x18))) < puVar2) {
        uVar6 = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0x18)) * 2;
        uVar5 = 0x10000;
        if (0xffff < uVar6) {
            uVar5 = uVar6;
        }
        *reinterpret_cast<uint32_t*>(base + 0x18) = uVar5;
        local_1c = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(uVar5)));
        if (local_1c == 0) {
            return -0x7ff8fff2;
        }
        uVar6 = *reinterpret_cast<uint32_t*>(base + 0x14);
        if (uVar6 != 0) {
            puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<uint32_t*>(base + 0x10)));
            puVar8 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(local_1c)));
            for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar8 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar8 = puVar8 + 1;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *reinterpret_cast<uint8_t*>(puVar8) =
                    *reinterpret_cast<uint8_t*>(puVar7);
                puVar7 = reinterpret_cast<uint32_t*>(
                    reinterpret_cast<intptr_t>(puVar7) + 1);
                puVar8 = reinterpret_cast<uint32_t*>(
                    reinterpret_cast<intptr_t>(puVar8) + 1);
            }
        }
        uVar5 = *reinterpret_cast<uint32_t*>(base + 0x18) -
            *reinterpret_cast<uint32_t*>(base + 0x14);
        puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
            *reinterpret_cast<int32_t*>(base + 0x14) +
            static_cast<intptr_t>(local_1c)));
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *reinterpret_cast<uint8_t*>(puVar7) = 0;
            puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar7) + 1);
        }
        if (*reinterpret_cast<uint32_t*>(base + 0x10) != 0) {
            operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(
                *reinterpret_cast<uint32_t*>(base + 0x10))));
            *reinterpret_cast<uint32_t*>(base + 0x10) = 0;
        }
        *reinterpret_cast<uint32_t*>(base + 0x10) =
            static_cast<uint32_t>(static_cast<intptr_t>(local_1c));
        FUN_0062a155(self);
    }
    local_8 = FUN_00629b6b(
        *reinterpret_cast<uint32_t*>(addr32(param_1) + 0x20), local_c, local_18,
        *reinterpret_cast<int32_t*>(base + 0x10),
        *reinterpret_cast<int32_t*>(base + 0x14), local_10, local_14, &local_20);
    if (local_8 < 0) {
        return local_8;
    }
    {
        void* pNew = FUN_00533c78(0x24);
        iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(pNew));
        if (pNew == nullptr) {
            piVar4 = nullptr;
        } else {
            FUN_0062952f(pNew);
            piVar4 = static_cast<int32_t*>(pNew);
        }
    }
    if (piVar4 == nullptr) {
        return -0x7ff8fff2;
    }
    *piVar4 = *reinterpret_cast<int32_t*>(base + 0x14) + local_10;
    piVar4[1] = *reinterpret_cast<int32_t*>(base + 0x14) + local_14 + local_10;
    piVar4[2] = local_20;
    piVar4[8] = *reinterpret_cast<int32_t*>(base + 0x1c);
    *reinterpret_cast<uint32_t*>(base + 0x1c) =
        static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar4));
    *reinterpret_cast<uint32_t*>(base + 0x14) =
        static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar2));
LAB_0062a38f:
    param_2 = static_cast<int32_t*>(FUN_00533c78(0x14));
    if (param_2 == nullptr) {
        param_2 = nullptr;
    } else {
        param_2[2] = 0;
        *param_2 = 0;
        param_2[4] = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_2));
        param_2[3] = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_2));
    }
    if (param_2 == nullptr) {
        return -0x7ff8fff2;
    }
    if (piVar4[2] != 0) {
        void* pTable = FUN_00533c78(static_cast<uint32_t>(piVar4[2]) << 2);
        param_2[2] = static_cast<int32_t>(reinterpret_cast<intptr_t>(pTable));
        if (pTable == nullptr) {
            local_8 = -0x7ff8fff2;
            goto LAB_0062a452;
        }
        local_8 = FUN_00629ca0(local_c, local_18,
                               static_cast<int32_t>(reinterpret_cast<intptr_t>(pTable)));
        if (local_8 < 0) goto LAB_0062a452;
    }
    *param_2 = param_1;
    param_2[1] = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1));
    *reinterpret_cast<uint32_t*>(addr32(piVar4[7] + 0xc)) =
        static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_2));
    param_2[3] = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar4 + 3));
    param_2[4] = piVar4[7];
    piVar4[7] = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_2));
    piVar1[0x10] = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_2));
    piVar1[0xb] = *piVar4;
    piVar1[0xc] = piVar4[1];
    param_2 = nullptr;
    piVar1[1] = *reinterpret_cast<int32_t*>(base + 0x10) + *piVar4;
    *piVar1 = *reinterpret_cast<int32_t*>(base + 0x10) + piVar4[1];
    local_8 = static_cast<int32_t>(FUN_0062a12a(
        piVar1[0xb] + *reinterpret_cast<int32_t*>(base + 0x10),
        piVar1[0xc] + *reinterpret_cast<int32_t*>(base + 0x10),
        reinterpret_cast<int32_t*>(addr32(piVar1[0x10])),
        reinterpret_cast<int32_t*>(addr32(piVar4[6]))));
LAB_0062a452:
    if (param_2 == nullptr) {
        return local_8;
    }
    FUN_0062a186(param_2, 1);
    return local_8;
}

// 0x62a495 — observed shape (in_ECX = self)
// Scalar deleting destructor: base destructor then conditional free.
void FUN_0062a495(void* self, uint8_t param_1) {
    FUN_0062e426(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x62a4b6 — observed shape (in_ECX = self)
// Recursively clear the list threaded through +8, freeing each head node.
// The corpus shows FUN_0062a4b6() without arguments; the receiver register is
// unchanged across the recursive call, so the same self is used.
void FUN_0062a4b6(void* self) {
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t iVar1 = *reinterpret_cast<int32_t*>(base + 8);

    while (iVar1 != 0) {
        void* pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(
            *reinterpret_cast<uint32_t*>(base + 8)));
        *reinterpret_cast<uint32_t*>(base + 8) =
            *reinterpret_cast<uint32_t*>(
                static_cast<uint8_t*>(pvVar2) + 8);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pvVar2) + 8) = 0;
        FUN_0062a4b6(self);
        operator_delete(pvVar2);
        iVar1 = *reinterpret_cast<int32_t*>(base + 8);
    }
}

// 0x62a4e6 — observed shape (in_ECX = self)
// Scalar deleting destructor for the +8 list owner.
void FUN_0062a4e6(void* self, uint8_t param_1) {
    FUN_0062a4b6(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x62a507 — observed shape (in_ECX = self)
// Initialize self[0..9] from ten arguments; clear self[10].
void FUN_0062a507(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7,
                  uint32_t param_8, uint32_t param_9, uint32_t param_10) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self);

    *in_ECX = param_1;
    in_ECX[10] = 0;
    in_ECX[1] = param_2;
    in_ECX[2] = param_3;
    in_ECX[3] = param_4;
    in_ECX[4] = param_5;
    in_ECX[5] = param_6;
    in_ECX[6] = param_7;
    in_ECX[7] = param_8;
    in_ECX[8] = param_9;
    in_ECX[9] = param_10;
}

// 0x62a551 — observed shape (in_ECX = self)
// Recursively clear the list threaded through +0x28, freeing each head node.
// Receiver register retained across the recursive call, as in 0x62a4b6.
void FUN_0062a551(void* self) {
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t iVar1 = *reinterpret_cast<int32_t*>(base + 0x28);

    while (iVar1 != 0) {
        void* pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(
            *reinterpret_cast<uint32_t*>(base + 0x28)));
        *reinterpret_cast<uint32_t*>(base + 0x28) =
            *reinterpret_cast<uint32_t*>(
                static_cast<uint8_t*>(pvVar2) + 0x28);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pvVar2) + 0x28) = 0;
        FUN_0062a551(self);
        operator_delete(pvVar2);
        iVar1 = *reinterpret_cast<int32_t*>(base + 0x28);
    }
}
