#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

extern "C" int isspace(int c);
extern "C" int isdigit(int c);
extern "C" int isalnum(int c);

extern uint32_t DAT_006e1924[4];
extern uint32_t DAT_006e1914[4];

// 0x62603f — observed shape
int FUN_0062603f(uint32_t param_1, uint32_t param_2, uint32_t *param_3, uint32_t param_4, int param_5)
{
    int16_t sVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    uint32_t *puVar4;
    int16_t *psVar5;
    int32_t iVar6;
    int32_t iVar7;
    uint32_t uVar8;
    uint32_t *puVar9;
    int iVar10;
    uint32_t uVar11;
    uint32_t *puVar12;
    uint32_t *puVar13;
    bool bVar14 = false;
    bool bVar15 = false;
    int32_t local_18;
    const uint32_t *local_14;
    uint32_t *local_10;
    uint32_t *local_8;
    const uint32_t obj = param_1;

    iVar10 = static_cast<int>(param_1);
    puVar4 = *reinterpret_cast<uint32_t **>(param_1 + 0x20);
    psVar5 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    local_8 = param_3;
    sVar1 = *psVar5;
    if (sVar1 == 0) {
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 1) {
        uVar11 = static_cast<uint16_t>(psVar5[3]);
        param_4 = param_4 / uVar11;
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 2) {
        uVar11 = static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])) *
                 static_cast<uint32_t>(static_cast<uint16_t>(psVar5[2]));
        param_4 = param_4 / uVar11;
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 3) {
        uVar11 = static_cast<uint16_t>(psVar5[2]);
        param_4 = param_4 / (uVar11 * static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])));
        if (static_cast<uint16_t>(psVar5[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar5[4]);
        }
        uint32_t outer = 0;
        puVar9 = puVar4;
        if (param_4 != 0) {
            do {
                uint32_t mid = 0;
                if (psVar5[3] != 0) {
                    do {
                        uint32_t inner = 0;
                        if (uVar11 != 0) {
                            do {
                                *puVar9 = param_3[(uVar11 * outer + inner) *
                                                      static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])) + mid];
                                uVar11 = static_cast<uint16_t>(psVar5[2]);
                                puVar9 = puVar9 + 1;
                                inner = inner + 1;
                            } while (inner < uVar11);
                        }
                        mid = mid + 1;
                    } while (mid < static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])));
                }
                outer = outer + 1;
            } while (outer < param_4);
        }
        local_8 = puVar4;
        goto LAB_006261c5;
    } else if (sVar1 == 5) {
        param_4 = param_4 / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar5[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar5[4]);
        }
        uint32_t row = 0;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uint32_t col = 0;
            if (psVar5[5] != 0) {
                do {
                    iVar6 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + col * 4);
                    iVar7 = FUN_0062603f(obj, param_2, local_8, *reinterpret_cast<uint32_t *>(iVar6 + 0x30), param_5);
                    if (iVar7 < 0) {
                        return iVar7;
                    }
                    local_8 = local_8 + *reinterpret_cast<int32_t *>(iVar6 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar6 + 0x28);
                    col = col + 1;
                } while (col < static_cast<uint32_t>(static_cast<uint16_t>(psVar5[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    if (!bVar14 && !bVar15) {
        param_4 = uVar11;
    }
LAB_006261c5:
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar5 == 3) {
            uVar2 = static_cast<uint16_t>(psVar5[2]);
            uVar3 = static_cast<uint16_t>(psVar5[3]);
        } else {
            uVar2 = static_cast<uint16_t>(psVar5[3]);
            uVar3 = static_cast<uint16_t>(psVar5[2]);
        }
        uVar11 = uVar2;
        if ((uVar2 & 3) != 0) {
            local_14 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar3 * param_4);
            uVar8 = (uVar11 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                iVar10 = local_18 * 4 + 4;
                puVar12 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar10) * uVar11 +
                                                       reinterpret_cast<uintptr_t>(local_8));
                local_10 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar10) * uVar8 +
                                                        reinterpret_cast<uintptr_t>(puVar4));
                puVar9 = puVar4 + local_18 * uVar8 + uVar11;
                do {
                    local_10 = local_10 - uVar8;
                    puVar9 = puVar9 - uVar8;
                    puVar12 = puVar12 - uVar11;
                    if (uVar11 < uVar8) {
                        puVar13 = local_10;
                        intptr_t padIndex = static_cast<intptr_t>(uVar8);
                        do {
                            padIndex = padIndex - 1;
                            puVar13 = puVar13 - 1;
                            *puVar13 = local_14[static_cast<uint32_t>(padIndex) & 3];
                        } while (uVar11 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar11 != 0) {
                        puVar13 = puVar9;
                        uint32_t *pSrc = puVar12;
                        uint32_t n = uVar11;
                        do {
                            pSrc = pSrc - 1;
                            puVar13 = puVar13 - 1;
                            n = n - 1;
                            *puVar13 = *pSrc;
                        } while (n != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
            local_8 = puVar4;
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(uint32_t, uint32_t, uint32_t *, uint32_t *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar10 = fn(param_2, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
                local_8, puVar4, param_4);
    if (iVar10 < 0) {
        return iVar10;
    }
    return 0;
}

// 0x6262de — observed shape
int FUN_006262de(uint32_t param_1, uint32_t param_2, uint32_t *param_3, uint32_t param_4, int param_5)
{
    int16_t sVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    uint32_t *puVar4;
    int16_t *psVar5;
    int32_t iVar6;
    int32_t iVar7;
    uint32_t uVar8;
    int iVar9;
    uint32_t *puVar10;
    uint32_t uVar11;
    uint32_t *puVar12;
    uint32_t *puVar13;
    bool bVar14 = false;
    bool bVar15 = false;
    int32_t local_18;
    const uint32_t *local_14;
    uint32_t *local_10;
    uint32_t *local_8;
    const uint32_t obj = param_1;

    iVar9 = static_cast<int>(param_1);
    puVar4 = *reinterpret_cast<uint32_t **>(param_1 + 0x20);
    psVar5 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    local_8 = param_3;
    sVar1 = *psVar5;
    if (sVar1 == 0) {
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 1) {
        uVar11 = static_cast<uint16_t>(psVar5[3]);
        param_4 = param_4 / uVar11;
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 2) {
        uVar11 = static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])) *
                 static_cast<uint32_t>(static_cast<uint16_t>(psVar5[2]));
        param_4 = param_4 / uVar11;
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 3) {
        uVar11 = static_cast<uint16_t>(psVar5[2]);
        param_4 = param_4 / (uVar11 * static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])));
        if (static_cast<uint16_t>(psVar5[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar5[4]);
        }
        uint32_t outer = 0;
        puVar10 = puVar4;
        if (param_4 != 0) {
            do {
                uint32_t mid = 0;
                if (psVar5[3] != 0) {
                    do {
                        uint32_t inner = 0;
                        if (uVar11 != 0) {
                            do {
                                *puVar10 = param_3[(uVar11 * outer + inner) *
                                                       static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])) + mid];
                                uVar11 = static_cast<uint16_t>(psVar5[2]);
                                puVar10 = puVar10 + 1;
                                inner = inner + 1;
                            } while (inner < uVar11);
                        }
                        mid = mid + 1;
                    } while (mid < static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])));
                }
                outer = outer + 1;
            } while (outer < param_4);
        }
        local_8 = puVar4;
        goto LAB_00626466;
    } else if (sVar1 == 5) {
        param_4 = param_4 / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar5[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar5[4]);
        }
        uint32_t row = 0;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uint32_t col = 0;
            if (psVar5[5] != 0) {
                do {
                    iVar6 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + col * 4);
                    iVar7 = FUN_006262de(obj, param_2, local_8, *reinterpret_cast<uint32_t *>(iVar6 + 0x30), param_5);
                    if (iVar7 < 0) {
                        return iVar7;
                    }
                    local_8 = local_8 + *reinterpret_cast<int32_t *>(iVar6 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar6 + 0x28);
                    col = col + 1;
                } while (col < static_cast<uint32_t>(static_cast<uint16_t>(psVar5[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    if (!bVar14 && !bVar15) {
        param_4 = uVar11;
    }
LAB_00626466:
    sVar1 = psVar5[1];
    if (sVar1 != 1) {
        iVar9 = *reinterpret_cast<int32_t *>(obj + 0x34) * static_cast<int32_t>(param_4);
        if (sVar1 == 2) {
            if (iVar9 != 0) {
                puVar10 = puVar4;
                do {
                    *puVar10 = static_cast<uint32_t>(
                        *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(puVar10) +
                                                     (reinterpret_cast<intptr_t>(local_8) -
                                                      reinterpret_cast<intptr_t>(puVar4))) != 0);
                    puVar10 = puVar10 + 1;
                    iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
            }
        } else if ((sVar1 == 3) && (iVar9 != 0)) {
            puVar10 = puVar4;
            do {
                if (*reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(puVar10) +
                                                 (reinterpret_cast<intptr_t>(local_8) -
                                                  reinterpret_cast<intptr_t>(puVar4))) == 0) {
                    uVar11 = 0;
                } else {
                    uVar11 = 0x3f800000;
                }
                *puVar10 = uVar11;
                puVar10 = puVar10 + 1;
                iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
        }
        local_8 = puVar4;
    }
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar5 == 3) {
            uVar2 = static_cast<uint16_t>(psVar5[2]);
            uVar3 = static_cast<uint16_t>(psVar5[3]);
        } else {
            uVar2 = static_cast<uint16_t>(psVar5[3]);
            uVar3 = static_cast<uint16_t>(psVar5[2]);
        }
        uVar11 = uVar2;
        if ((uVar2 & 3) != 0) {
            local_14 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar3 * param_4);
            uVar8 = (uVar11 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                iVar9 = local_18 * 4 + 4;
                puVar12 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar9) * uVar11 +
                                                       reinterpret_cast<uintptr_t>(local_8));
                local_10 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar9) * uVar8 +
                                                        reinterpret_cast<uintptr_t>(puVar4));
                puVar10 = puVar4 + local_18 * uVar8 + uVar11;
                do {
                    local_10 = local_10 - uVar8;
                    puVar10 = puVar10 - uVar8;
                    puVar12 = puVar12 - uVar11;
                    if (uVar11 < uVar8) {
                        puVar13 = local_10;
                        intptr_t padIndex = static_cast<intptr_t>(uVar8);
                        do {
                            padIndex = padIndex - 1;
                            puVar13 = puVar13 - 1;
                            *puVar13 = local_14[static_cast<uint32_t>(padIndex) & 3];
                        } while (uVar11 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar11 != 0) {
                        puVar13 = puVar10;
                        uint32_t *pSrc = puVar12;
                        uint32_t n = uVar11;
                        do {
                            pSrc = pSrc - 1;
                            puVar13 = puVar13 - 1;
                            n = n - 1;
                            *puVar13 = *pSrc;
                        } while (n != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
            local_8 = puVar4;
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(uint32_t, uint32_t, uint32_t *, uint32_t *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar9 = fn(param_2, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
               local_8, puVar4, param_4);
    if (iVar9 < 0) {
        return iVar9;
    }
    return 0;
}

// 0x6265e0 — observed shape
int FUN_006265e0(uint32_t param_1, uint32_t param_2, float *param_3, uint32_t param_4, int param_5)
{
    int16_t sVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    int16_t *psVar4;
    float *pfVar5;
    int32_t iVar6;
    int32_t iVar7;
    uint32_t uVar8;
    int iVar9;
    float *pfVar10;
    uint32_t uVar11;
    float *pfVar12;
    float *pfVar13;
    bool bVar14 = false;
    bool bVar15 = false;
    int32_t local_18;
    const uint32_t *local_14;
    float *local_10;
    float *local_8;
    const uint32_t obj = param_1;

    iVar9 = static_cast<int>(param_1);
    psVar4 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    pfVar5 = *reinterpret_cast<float **>(param_1 + 0x20);
    local_8 = param_3;
    sVar1 = *psVar4;
    if (sVar1 == 0) {
        uVar11 = static_cast<uint16_t>(psVar4[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 1) {
        uVar11 = static_cast<uint16_t>(psVar4[3]);
        param_4 = param_4 / uVar11;
        uVar11 = static_cast<uint16_t>(psVar4[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 2) {
        uVar11 = static_cast<uint32_t>(static_cast<uint16_t>(psVar4[3])) *
                 static_cast<uint32_t>(static_cast<uint16_t>(psVar4[2]));
        param_4 = param_4 / uVar11;
        uVar11 = static_cast<uint16_t>(psVar4[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 3) {
        uVar11 = static_cast<uint16_t>(psVar4[2]);
        param_4 = param_4 / (uVar11 * static_cast<uint32_t>(static_cast<uint16_t>(psVar4[3])));
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uint32_t outer = 0;
        pfVar10 = pfVar5;
        if (param_4 != 0) {
            do {
                uint32_t mid = 0;
                if (psVar4[3] != 0) {
                    do {
                        uint32_t inner = 0;
                        if (uVar11 != 0) {
                            do {
                                *pfVar10 = param_3[(uVar11 * outer + inner) *
                                                       static_cast<uint32_t>(static_cast<uint16_t>(psVar4[3])) + mid];
                                uVar11 = static_cast<uint16_t>(psVar4[2]);
                                pfVar10 = pfVar10 + 1;
                                inner = inner + 1;
                            } while (inner < uVar11);
                        }
                        mid = mid + 1;
                    } while (mid < static_cast<uint32_t>(static_cast<uint16_t>(psVar4[3])));
                }
                outer = outer + 1;
            } while (outer < param_4);
        }
        local_8 = pfVar5;
        goto LAB_00626767;
    } else if (sVar1 == 5) {
        param_4 = param_4 / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uint32_t row = 0;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uint32_t col = 0;
            if (psVar4[5] != 0) {
                do {
                    iVar6 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + col * 4);
                    iVar7 = FUN_006265e0(obj, param_2, local_8, *reinterpret_cast<uint32_t *>(iVar6 + 0x30), param_5);
                    if (iVar7 < 0) {
                        return iVar7;
                    }
                    local_8 = local_8 + *reinterpret_cast<int32_t *>(iVar6 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar6 + 0x28);
                    col = col + 1;
                } while (col < static_cast<uint32_t>(static_cast<uint16_t>(psVar4[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    if (!bVar14 && !bVar15) {
        param_4 = uVar11;
    }
LAB_00626767:
    sVar1 = psVar4[1];
    if (sVar1 != 2) {
        iVar9 = *reinterpret_cast<int32_t *>(obj + 0x34) * static_cast<int32_t>(param_4);
        if (sVar1 == 1) {
            if (iVar9 != 0) {
                pfVar10 = pfVar5;
                do {
                    *pfVar10 = static_cast<float>(static_cast<uint32_t>(
                        *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(pfVar10) +
                                                     (reinterpret_cast<intptr_t>(local_8) -
                                                      reinterpret_cast<intptr_t>(pfVar5))) != 0));
                    pfVar10 = pfVar10 + 1;
                    iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
            }
        } else if (((sVar1 != 2) && (sVar1 == 3)) && (iVar9 != 0)) {
            pfVar10 = pfVar5;
            do {
                *pfVar10 = static_cast<float>(*reinterpret_cast<int32_t *>(
                    reinterpret_cast<intptr_t>(pfVar10) +
                    (reinterpret_cast<intptr_t>(local_8) - reinterpret_cast<intptr_t>(pfVar5))));
                pfVar10 = pfVar10 + 1;
                iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
        }
        local_8 = pfVar5;
    }
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar4 == 3) {
            uVar2 = static_cast<uint16_t>(psVar4[2]);
            uVar3 = static_cast<uint16_t>(psVar4[3]);
        } else {
            uVar2 = static_cast<uint16_t>(psVar4[3]);
            uVar3 = static_cast<uint16_t>(psVar4[2]);
        }
        uVar11 = uVar2;
        if ((uVar2 & 3) != 0) {
            local_14 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar3 * param_4);
            uVar8 = (uVar11 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                iVar9 = local_18 * 4 + 4;
                pfVar12 = reinterpret_cast<float *>(static_cast<uintptr_t>(iVar9) * uVar11 +
                                                    reinterpret_cast<uintptr_t>(local_8));
                local_10 = reinterpret_cast<float *>(static_cast<uintptr_t>(iVar9) * uVar8 +
                                                     reinterpret_cast<uintptr_t>(pfVar5));
                pfVar10 = pfVar5 + local_18 * uVar8 + uVar11;
                do {
                    local_10 = local_10 - uVar8;
                    pfVar10 = pfVar10 - uVar8;
                    pfVar12 = pfVar12 - uVar11;
                    if (uVar11 < uVar8) {
                        pfVar13 = local_10;
                        intptr_t padIndex = static_cast<intptr_t>(uVar8);
                        do {
                            padIndex = padIndex - 1;
                            pfVar13 = pfVar13 - 1;
                            *pfVar13 = *reinterpret_cast<const float *>(local_14 + (static_cast<uint32_t>(padIndex) & 3));
                        } while (uVar11 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar11 != 0) {
                        pfVar13 = pfVar10;
                        float *pSrc = pfVar12;
                        uint32_t n = uVar11;
                        do {
                            pSrc = pSrc - 1;
                            pfVar13 = pfVar13 - 1;
                            n = n - 1;
                            *pfVar13 = *pSrc;
                        } while (n != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
            local_8 = pfVar5;
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(uint32_t, uint32_t, float *, float *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar9 = fn(param_2, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
               local_8, pfVar5, param_4);
    if (iVar9 < 0) {
        return iVar9;
    }
    return 0;
}

// 0x6268d6 — observed shape
int FUN_006268d6(uint32_t param_1, uint32_t param_2, uint32_t *param_3, uint32_t param_4, int param_5)
{
    int16_t sVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    uint32_t *puVar4;
    int16_t *psVar5;
    int32_t iVar6;
    int32_t iVar7;
    uint32_t uVar8;
    uint32_t *puVar9;
    uint32_t *puVar10;
    uint32_t uVar11;
    int iVar12;
    uint32_t *puVar13;
    bool bVar14 = false;
    bool bVar15 = false;
    int32_t local_18;
    const uint32_t *local_14;
    uint32_t *local_10;
    uint32_t *local_8;
    const uint32_t obj = param_1;

    iVar12 = static_cast<int>(param_1);
    puVar4 = *reinterpret_cast<uint32_t **>(param_1 + 0x20);
    psVar5 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    local_8 = param_3;
    sVar1 = *psVar5;
    if (sVar1 == 0) {
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 1) {
        uVar11 = static_cast<uint16_t>(psVar5[3]);
        param_4 = param_4 / uVar11;
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 2) {
        uVar11 = static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])) *
                 static_cast<uint32_t>(static_cast<uint16_t>(psVar5[2]));
        param_4 = param_4 / uVar11;
        uVar11 = static_cast<uint16_t>(psVar5[4]);
        bVar14 = param_4 < uVar11;
        bVar15 = param_4 == uVar11;
    } else if (sVar1 == 3) {
        uVar11 = static_cast<uint16_t>(psVar5[2]);
        param_4 = param_4 / (uVar11 * static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])));
        if (static_cast<uint16_t>(psVar5[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar5[4]);
        }
        uint32_t outer = 0;
        puVar9 = puVar4;
        if (param_4 != 0) {
            do {
                uint32_t mid = 0;
                if (psVar5[3] != 0) {
                    do {
                        uint32_t inner = 0;
                        if (uVar11 != 0) {
                            do {
                                *puVar9 = param_3[(uVar11 * outer + inner) *
                                                      static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])) + mid];
                                uVar11 = static_cast<uint16_t>(psVar5[2]);
                                puVar9 = puVar9 + 1;
                                inner = inner + 1;
                            } while (inner < uVar11);
                        }
                        mid = mid + 1;
                    } while (mid < static_cast<uint32_t>(static_cast<uint16_t>(psVar5[3])));
                }
                outer = outer + 1;
            } while (outer < param_4);
        }
        local_8 = puVar4;
        goto LAB_00626a5e;
    } else if (sVar1 == 5) {
        param_4 = param_4 / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar5[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar5[4]);
        }
        uint32_t row = 0;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uint32_t col = 0;
            if (psVar5[5] != 0) {
                do {
                    iVar6 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + col * 4);
                    iVar7 = FUN_006268d6(obj, param_2, local_8, *reinterpret_cast<uint32_t *>(iVar6 + 0x30), param_5);
                    if (iVar7 < 0) {
                        return iVar7;
                    }
                    local_8 = local_8 + *reinterpret_cast<int32_t *>(iVar6 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar6 + 0x28);
                    col = col + 1;
                } while (col < static_cast<uint32_t>(static_cast<uint16_t>(psVar5[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    if (!bVar14 && !bVar15) {
        param_4 = uVar11;
    }
LAB_00626a5e:
    sVar1 = psVar5[1];
    if (sVar1 != 3) {
        iVar12 = *reinterpret_cast<int32_t *>(obj + 0x34) * static_cast<int32_t>(param_4);
        if (sVar1 == 1) {
            if (iVar12 != 0) {
                puVar9 = puVar4;
                do {
                    *puVar9 = static_cast<uint32_t>(
                        *reinterpret_cast<float *>(reinterpret_cast<intptr_t>(puVar9) +
                                                   (reinterpret_cast<intptr_t>(local_8) -
                                                    reinterpret_cast<intptr_t>(puVar4))) != 0.0f);
                    puVar9 = puVar9 + 1;
                    iVar12 = iVar12 + -1;
                } while (iVar12 != 0);
            }
        } else if ((sVar1 == 2) && (iVar12 != 0)) {
            puVar9 = puVar4;
            do {
                *puVar9 = static_cast<uint32_t>(static_cast<int32_t>(roundf(
                    *reinterpret_cast<float *>(reinterpret_cast<intptr_t>(puVar9) +
                                               (reinterpret_cast<intptr_t>(local_8) -
                                                reinterpret_cast<intptr_t>(puVar4))))));  // observed ROUND(f32) — ties away from zero
                puVar9 = puVar9 + 1;
                iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
        }
        local_8 = puVar4;
    }
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar5 == 3) {
            uVar2 = static_cast<uint16_t>(psVar5[2]);
            uVar3 = static_cast<uint16_t>(psVar5[3]);
        } else {
            uVar2 = static_cast<uint16_t>(psVar5[3]);
            uVar3 = static_cast<uint16_t>(psVar5[2]);
        }
        uVar11 = uVar2;
        if ((uVar2 & 3) != 0) {
            local_14 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar3 * param_4);
            uVar8 = (uVar11 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                iVar12 = local_18 * 4 + 4;
                puVar10 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar12) * uVar11 +
                                                       reinterpret_cast<uintptr_t>(local_8));
                local_10 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar12) * uVar8 +
                                                        reinterpret_cast<uintptr_t>(puVar4));
                puVar9 = puVar4 + local_18 * uVar8 + uVar11;
                do {
                    local_10 = local_10 - uVar8;
                    puVar9 = puVar9 - uVar8;
                    puVar10 = puVar10 - uVar11;
                    if (uVar11 < uVar8) {
                        puVar13 = local_10;
                        intptr_t padIndex = static_cast<intptr_t>(uVar8);
                        do {
                            padIndex = padIndex - 1;
                            puVar13 = puVar13 - 1;
                            *puVar13 = local_14[static_cast<uint32_t>(padIndex) & 3];
                        } while (uVar11 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar11 != 0) {
                        puVar13 = puVar9;
                        uint32_t *pSrc = puVar10;
                        uint32_t n = uVar11;
                        do {
                            pSrc = pSrc - 1;
                            puVar13 = puVar13 - 1;
                            n = n - 1;
                            *puVar13 = *pSrc;
                        } while (n != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
            local_8 = puVar4;
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(uint32_t, uint32_t, uint32_t *, uint32_t *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar12 = fn(param_2, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
                local_8, puVar4, param_4);
    if (iVar12 < 0) {
        return iVar12;
    }
    return 0;
}

// 0x626c07 — observed shape
int FUN_00626c07(int param_1, uint32_t param_2, uint32_t *param_3, uint32_t param_4, int param_5)
{
    int16_t sVar1;
    uint16_t uVar2;
    uint32_t *puVar3;
    int16_t *psVar4;
    int32_t iVar5;
    uint32_t uVar6;
    uint32_t *puVar7;
    int32_t iVar8;
    uint32_t *puVar9;
    uint16_t uVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    uint32_t *puVar13;
    int32_t local_18;
    const uint32_t *local_14;
    uint32_t *local_10;
    uint32_t *local_8;
    const int32_t obj = param_1;

    puVar3 = *reinterpret_cast<uint32_t **>(param_1 + 0x20);
    psVar4 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    local_8 = param_3;
    sVar1 = *psVar4;
    if (sVar1 == 0) {
        param_4 = param_4 * 4;
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
    } else if (sVar1 == 1) {
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        if (psVar4[3] != 4) {
            uVar12 = 0;
            if (param_4 != 0) {
                uVar11 = static_cast<uint16_t>(psVar4[3]);
                puVar7 = puVar3;
                do {
                    uVar6 = 0;
                    if (uVar11 != 0) {
                        do {
                            if (uVar6 < 5) {
                                uVar11 = param_3[uVar6 + uVar12 * 4];
                            } else {
                                uVar11 = 0;
                            }
                            *puVar7 = uVar11;
                            uVar11 = static_cast<uint16_t>(psVar4[3]);
                            puVar7 = puVar7 + 1;
                            uVar6 = uVar6 + 1;
                        } while (uVar6 < uVar11);
                    }
                    uVar12 = uVar12 + 1;
                } while (uVar12 < param_4);
            }
        } else {
            goto LAB_00626e4a;
        }
    } else if (sVar1 == 2) {
        uVar12 = static_cast<uint16_t>(psVar4[2]);
        param_4 = param_4 / uVar12;
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uVar10 = static_cast<uint16_t>(psVar4[3]);
        if (uVar10 != 4) {
            int32_t row = 0;
            puVar7 = puVar3;
            if (param_4 != 0) {
                do {
                    uVar11 = 0;
                    if (uVar12 != 0) {
                        uVar6 = uVar10;
                        do {
                            uVar12 = 0;
                            if (uVar6 != 0) {
                                do {
                                    if (uVar12 < 5) {
                                        uVar6 = param_3[uVar12 +
                                                        (static_cast<uint32_t>(static_cast<uint16_t>(psVar4[2])) * row +
                                                         uVar11) * 4];
                                    } else {
                                        uVar6 = 0;
                                    }
                                    *puVar7 = uVar6;
                                    uVar10 = static_cast<uint16_t>(psVar4[3]);
                                    puVar7 = puVar7 + 1;
                                    uVar6 = uVar10;
                                    uVar12 = uVar12 + 1;
                                } while (uVar12 < uVar6);
                            }
                            uVar12 = static_cast<uint16_t>(psVar4[2]);
                            uVar11 = uVar11 + 1;
                        } while (uVar11 < uVar12);
                    }
                    row = row + 1;
                } while (row < param_4);
            }
        } else {
            goto LAB_00626e4a;
        }
    } else if (sVar1 == 3) {
        uVar12 = static_cast<uint16_t>(psVar4[3]);
        param_4 = param_4 / uVar12;
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        int32_t row = 0;
        puVar7 = puVar3;
        if (param_4 != 0) {
            do {
                uVar11 = 0;
                if (uVar12 != 0) {
                    uVar6 = static_cast<uint32_t>(static_cast<uint16_t>(psVar4[2]));
                    do {
                        uVar12 = 0;
                        if (uVar6 != 0) {
                            do {
                                if (uVar11 < 5) {
                                    uVar6 = param_3[uVar11 + (uVar6 * row + uVar12) * 4];
                                } else {
                                    uVar6 = 0;
                                }
                                *puVar7 = uVar6;
                                uVar6 = static_cast<uint32_t>(static_cast<uint16_t>(psVar4[2]));
                                puVar7 = puVar7 + 1;
                                uVar12 = uVar12 + 1;
                            } while (uVar12 < uVar6);
                        }
                        uVar12 = static_cast<uint16_t>(psVar4[3]);
                        uVar11 = uVar11 + 1;
                    } while (uVar11 < uVar12);
                }
                row = row + 1;
            } while (row < param_4);
        }
    } else if (sVar1 == 5) {
        param_4 = (param_4 << 2) / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uint32_t row = 0;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uint32_t col = 0;
            if (psVar4[5] != 0) {
                do {
                    iVar8 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + col * 4);
                    iVar5 = FUN_006268d6(obj, param_2, local_8, *reinterpret_cast<uint32_t *>(iVar8 + 0x30), param_5);
                    if (iVar5 < 0) {
                        return iVar5;
                    }
                    local_8 = local_8 + *reinterpret_cast<int32_t *>(iVar8 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar8 + 0x28);
                    col = col + 1;
                } while (col < static_cast<uint32_t>(static_cast<uint16_t>(psVar4[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    local_8 = puVar3;
LAB_00626e4a:
    sVar1 = psVar4[1];
    if (sVar1 != 3) {
        iVar8 = *reinterpret_cast<int32_t *>(obj + 0x34) * static_cast<int32_t>(param_4);
        if (sVar1 == 1) {
            if (iVar8 != 0) {
                puVar7 = puVar3;
                do {
                    *puVar7 = static_cast<uint32_t>(
                        *reinterpret_cast<float *>(reinterpret_cast<intptr_t>(puVar7) +
                                                   (reinterpret_cast<intptr_t>(local_8) -
                                                    reinterpret_cast<intptr_t>(puVar3))) != 0.0f);
                    puVar7 = puVar7 + 1;
                    iVar8 = iVar8 + -1;
                } while (iVar8 != 0);
            }
        } else if ((sVar1 == 2) && (iVar8 != 0)) {
            puVar7 = puVar3;
            do {
                *puVar7 = static_cast<uint32_t>(static_cast<int32_t>(roundf(
                    *reinterpret_cast<float *>(reinterpret_cast<intptr_t>(puVar7) +
                                               (reinterpret_cast<intptr_t>(local_8) -
                                                reinterpret_cast<intptr_t>(puVar3))))));  // observed ROUND(f32) — ties away from zero
                puVar7 = puVar7 + 1;
                iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
        }
        local_8 = puVar3;
    }
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar4 == 3) {
            uVar10 = static_cast<uint16_t>(psVar4[2]);
            uVar2 = static_cast<uint16_t>(psVar4[3]);
        } else {
            uVar10 = static_cast<uint16_t>(psVar4[3]);
            uVar2 = static_cast<uint16_t>(psVar4[2]);
        }
        uVar12 = uVar10;
        if ((uVar10 & 3) != 0) {
            local_14 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar2 * param_4);
            uVar11 = (uVar12 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                puVar7 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(uVar12) *
                                                      static_cast<uintptr_t>(local_18 * 4 + 4) +
                                                      reinterpret_cast<uintptr_t>(local_8));
                local_10 = puVar3 + local_18 * uVar11 + uVar12;
                puVar9 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(uVar11) *
                                                      static_cast<uintptr_t>(local_18 * 4 + 4) +
                                                      reinterpret_cast<uintptr_t>(puVar3));
                do {
                    local_10 = local_10 - uVar11;
                    puVar9 = puVar9 - uVar11;
                    puVar7 = puVar7 - uVar12;
                    if (uVar12 < uVar11) {
                        uint32_t *pPad = puVar9;
                        intptr_t padIndex = static_cast<intptr_t>(uVar11);
                        do {
                            padIndex = padIndex - 1;
                            pPad = pPad - 1;
                            *pPad = local_14[static_cast<uint32_t>(padIndex) & 3];
                        } while (uVar12 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar12 != 0) {
                        puVar13 = local_10;
                        uint32_t *pSrc = puVar7;
                        uint32_t n = uVar12;
                        do {
                            pSrc = pSrc - 1;
                            puVar13 = puVar13 - 1;
                            n = n - 1;
                            *puVar13 = *pSrc;
                        } while (n != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
            local_8 = puVar3;
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(int, uint32_t, uint32_t *, uint32_t *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar8 = fn(param_1, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
               local_8, puVar3, param_4);
    if (iVar8 < 0) {
        return iVar8;
    }
    return 0;
}

// 0x626ff4 — observed shape
int FUN_00626ff4(int param_1, uint32_t param_2, uint32_t *param_3, uint32_t param_4, int param_5)
{
    int16_t sVar1;
    uint16_t uVar2;
    int16_t *psVar3;
    uint32_t *puVar4;
    int32_t iVar5;
    uint32_t *puVar6;
    uint32_t *puVar7;
    uint32_t uVar8;
    int32_t iVar9;
    uint32_t *puVar10;
    uint16_t uVar11;
    uint32_t uVar12;
    uint32_t uVar13;
    int32_t local_18;
    uint32_t local_14;
    const uint32_t *local_10;
    uint32_t *local_c;
    const int32_t obj = param_1;

    psVar3 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    sVar1 = *psVar3;
    puVar4 = *reinterpret_cast<uint32_t **>(param_1 + 0x20);
    local_c = param_3;
    if (sVar1 == 0) {
        param_4 = param_4 * 0x10;
        if (static_cast<uint16_t>(psVar3[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar3[4]);
        }
    } else if (sVar1 == 1) {
        param_4 = param_4 * 4;
        if (static_cast<uint16_t>(psVar3[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar3[4]);
        }
        if (psVar3[3] != 4) {
            uVar12 = 0;
            if (param_4 != 0) {
                uVar13 = static_cast<uint16_t>(psVar3[3]);
                puVar6 = puVar4;
                do {
                    uVar8 = 0;
                    if (uVar13 != 0) {
                        do {
                            if (uVar8 < 5) {
                                uVar13 = param_3[uVar8 + ((uVar12 & 3) + (uVar12 & 0xfffffffc)) * 4];
                            } else {
                                uVar13 = 0;
                            }
                            *puVar6 = uVar13;
                            uVar13 = static_cast<uint16_t>(psVar3[3]);
                            puVar6 = puVar6 + 1;
                            uVar8 = uVar8 + 1;
                        } while (uVar8 < uVar13);
                    }
                    uVar12 = uVar12 + 1;
                } while (uVar12 < param_4);
            }
        } else {
            goto LAB_006272db;
        }
    } else if (sVar1 == 2) {
        if (static_cast<uint16_t>(psVar3[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar3[4]);
        }
        uVar11 = static_cast<uint16_t>(psVar3[2]);
        if ((uVar11 == 4) && (psVar3[3] == 4)) {
            goto LAB_006272db;
        }
        uint32_t row = 0;
        puVar6 = puVar4;
        if (param_4 != 0) {
            do {
                uVar12 = 0;
                if (uVar11 != 0) {
                    uVar13 = static_cast<uint16_t>(psVar3[3]);
                    do {
                        uVar8 = 0;
                        if (uVar13 != 0) {
                            do {
                                if ((uVar12 < 5) && (uVar8 < 5)) {
                                    uVar13 = param_3[uVar8 + (uVar12 + row * 4) * 4];
                                } else {
                                    uVar13 = 0;
                                }
                                *puVar6 = uVar13;
                                uVar13 = static_cast<uint16_t>(psVar3[3]);
                                puVar6 = puVar6 + 1;
                                uVar8 = uVar8 + 1;
                            } while (uVar8 < uVar13);
                        }
                        uVar11 = static_cast<uint16_t>(psVar3[2]);
                        uVar12 = uVar12 + 1;
                    } while (uVar12 < uVar11);
                }
                row = row + 1;
            } while (row < param_4);
        }
    } else if (sVar1 == 3) {
        if (static_cast<uint16_t>(psVar3[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar3[4]);
        }
        uVar11 = static_cast<uint16_t>(psVar3[2]);
        if ((uVar11 == 4) && (psVar3[3] == 4)) {
            if (param_4 != 0) {
                puVar6 = puVar4 + 2;
                puVar7 = param_3 + 8;
                uVar12 = param_4;
                do {
                    puVar6[-2] = puVar7[-8];
                    puVar6[-1] = puVar7[-4];
                    *puVar6 = *puVar7;
                    puVar6[1] = puVar7[4];
                    puVar6[2] = puVar7[-7];
                    puVar6[3] = puVar7[-3];
                    puVar6[4] = puVar7[1];
                    puVar6[5] = puVar7[5];
                    *reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puVar7) +
                                                  (reinterpret_cast<intptr_t>(puVar4) -
                                                   reinterpret_cast<intptr_t>(param_3))) = puVar7[-6];
                    puVar6[7] = puVar7[-2];
                    puVar6[8] = puVar7[2];
                    puVar6[9] = puVar7[6];
                    puVar6[10] = puVar7[-5];
                    puVar6[0xb] = puVar7[-1];
                    puVar6[0xc] = puVar7[3];
                    puVar6[0xd] = puVar7[7];
                    puVar7 = puVar7 + 0x10;
                    puVar6 = puVar6 + 0x10;
                    uVar12 = uVar12 - 1;
                } while (uVar12 != 0);
            }
        } else {
            uVar12 = 0;
            puVar6 = puVar4;
            if (param_4 != 0) {
                do {
                    uint32_t row = 0;
                    if (psVar3[3] != 0) {
                        uVar13 = uVar11;
                        do {
                            uVar8 = 0;
                            if (uVar13 != 0) {
                                do {
                                    if ((uVar8 < 5) && (row < 5)) {
                                        uVar13 = param_3[row + (uVar8 + uVar12 * 4) * 4];
                                    } else {
                                        uVar13 = 0;
                                    }
                                    *puVar6 = uVar13;
                                    uVar11 = static_cast<uint16_t>(psVar3[2]);
                                    puVar6 = puVar6 + 1;
                                    uVar13 = uVar11;
                                    uVar8 = uVar8 + 1;
                                } while (uVar8 < uVar13);
                            }
                            row = row + 1;
                        } while (row < static_cast<uint32_t>(static_cast<uint16_t>(psVar3[3])));
                    }
                    uVar12 = uVar12 + 1;
                } while (uVar12 < param_4);
            }
        }
    } else if (sVar1 == 5) {
        param_4 = (param_4 << 4) / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar3[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar3[4]);
        }
        uint32_t row = 0;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uVar12 = 0;
            if (psVar3[5] != 0) {
                do {
                    iVar9 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + uVar12 * 4);
                    iVar5 = FUN_006268d6(obj, param_2, local_c, *reinterpret_cast<uint32_t *>(iVar9 + 0x30), param_5);
                    if (iVar5 < 0) {
                        return iVar5;
                    }
                    local_c = local_c + *reinterpret_cast<int32_t *>(iVar9 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar9 + 0x28);
                    uVar12 = uVar12 + 1;
                } while (uVar12 < static_cast<uint32_t>(static_cast<uint16_t>(psVar3[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    local_c = puVar4;
LAB_006272db:
    sVar1 = psVar3[1];
    if (sVar1 != 3) {
        iVar9 = *reinterpret_cast<int32_t *>(obj + 0x34) * static_cast<int32_t>(param_4);
        if (sVar1 == 1) {
            if (iVar9 != 0) {
                puVar6 = puVar4;
                do {
                    *puVar6 = static_cast<uint32_t>(
                        *reinterpret_cast<float *>(reinterpret_cast<intptr_t>(puVar6) +
                                                   (reinterpret_cast<intptr_t>(local_c) -
                                                    reinterpret_cast<intptr_t>(puVar4))) != 0.0f);
                    puVar6 = puVar6 + 1;
                    iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
            }
        } else if ((sVar1 == 2) && (iVar9 != 0)) {
            puVar6 = puVar4;
            do {
                *puVar6 = static_cast<uint32_t>(static_cast<int32_t>(roundf(
                    *reinterpret_cast<float *>(reinterpret_cast<intptr_t>(puVar6) +
                                               (reinterpret_cast<intptr_t>(local_c) -
                                                reinterpret_cast<intptr_t>(puVar4))))));  // observed ROUND(f32) — ties away from zero
                puVar6 = puVar6 + 1;
                iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
        }
        local_c = puVar4;
    }
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar3 == 3) {
            uVar11 = static_cast<uint16_t>(psVar3[2]);
            uVar2 = static_cast<uint16_t>(psVar3[3]);
        } else {
            uVar11 = static_cast<uint16_t>(psVar3[3]);
            uVar2 = static_cast<uint16_t>(psVar3[2]);
        }
        uVar12 = uVar11;
        if ((uVar11 & 3) != 0) {
            local_10 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar2 * param_4);
            uVar13 = (uVar12 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                iVar9 = local_18 * 4 + 4;
                puVar7 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar9) * uVar12 +
                                                      reinterpret_cast<uintptr_t>(local_c));
                local_c = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar9) * uVar13 +
                                                       reinterpret_cast<uintptr_t>(puVar4));
                puVar6 = puVar4 + local_18 * uVar13 + uVar12;
                do {
                    local_c = local_c - uVar13;
                    puVar6 = puVar6 - uVar13;
                    puVar7 = puVar7 - uVar12;
                    if (uVar12 < uVar13) {
                        puVar10 = local_c;
                        intptr_t padIndex = static_cast<intptr_t>(uVar13);
                        do {
                            padIndex = padIndex - 1;
                            puVar10 = puVar10 - 1;
                            *puVar10 = local_10[static_cast<uint32_t>(padIndex) & 3];
                        } while (uVar12 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar12 != 0) {
                        puVar10 = puVar6;
                        uint32_t *pSrc = puVar7;
                        local_14 = uVar12;
                        do {
                            pSrc = pSrc - 1;
                            puVar10 = puVar10 - 1;
                            local_14 = local_14 - 1;
                            *puVar10 = *pSrc;
                        } while (local_14 != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
            local_c = puVar4;
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(int, uint32_t, uint32_t *, uint32_t *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar9 = fn(param_1, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
               local_c, puVar4, param_4);
    if (iVar9 < 0) {
        return iVar9;
    }
    return 0;
}

// 0x627489 — observed shape
int FUN_00627489(int param_1, uint32_t param_2, uint32_t *param_3, uint32_t param_4, int param_5)
{
    float *pfVar1;
    int16_t sVar2;
    uint16_t uVar3;
    uint16_t uVar4;
    uint32_t *puVar5;
    int16_t *psVar6;
    int32_t iVar7;
    uint32_t uVar8;
    uint32_t *puVar9;
    int32_t iVar10;
    uint32_t uVar11;
    uint32_t *puVar12;
    uint32_t *puVar13;
    uint32_t *puVar14;
    uint32_t uVar15;
    uint32_t uVar16;
    int32_t local_18;
    uint32_t local_14;
    const uint32_t *local_10;
    uint32_t *local_c;
    const int32_t obj = param_1;

    puVar5 = *reinterpret_cast<uint32_t **>(param_1 + 0x20);
    psVar6 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    sVar2 = *psVar6;
    uVar14 = 0;
    if (sVar2 == 0) {
        param_4 = param_4 * 0x10;
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        puVar12 = puVar5;
        if (param_4 != 0) {
            do {
                *puVar12 = *reinterpret_cast<uint32_t *>(
                    *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) + (uVar14 >> 4) * 4) +
                    ((uVar14 & 3) + (uVar14 >> 2 & 3) * 4) * 4);
                puVar12 = puVar12 + 1;
                uVar14 = uVar14 + 1;
            } while (uVar14 < param_4);
        }
    } else if (sVar2 == 1) {
        param_4 = param_4 * 4;
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        int32_t row = 0;
        if (param_4 != 0) {
            uVar14 = static_cast<uint16_t>(psVar6[3]);
            puVar12 = puVar5;
            do {
                uVar16 = 0;
                if (uVar14 != 0) {
                    do {
                        if (uVar16 < 5) {
                            uVar8 = *reinterpret_cast<uint32_t *>(
                                *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) +
                                                             (static_cast<uint32_t>(row) & 0xfffffffc)) +
                                (uVar16 + (static_cast<uint32_t>(row) & 3) * 4) * 4);
                        } else {
                            uVar8 = 0;
                        }
                        *puVar12 = uVar8;
                        uVar14 = static_cast<uint16_t>(psVar6[3]);
                        puVar12 = puVar12 + 1;
                        uVar16 = uVar16 + 1;
                    } while (uVar16 < uVar14);
                }
                row = row + 1;
            } while (row < static_cast<int32_t>(param_4));
        }
    } else if (sVar2 == 2) {
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        uVar14 = 0;
        local_c = puVar5;
        if (param_4 != 0) {
            do {
                uVar16 = 0;
                if (psVar6[2] != 0) {
                    uVar15 = static_cast<uint16_t>(psVar6[3]);
                    do {
                        uVar11 = 0;
                        if (uVar15 != 0) {
                            do {
                                if ((uVar16 < 5) && (uVar11 < 5)) {
                                    uVar8 = *reinterpret_cast<uint32_t *>(
                                        *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) + uVar14 * 4) +
                                        (uVar11 + uVar16 * 4) * 4);
                                } else {
                                    uVar8 = 0;
                                }
                                puVar12 = local_c + 1;
                                *local_c = uVar8;
                                uVar15 = static_cast<uint16_t>(psVar6[3]);
                                uVar11 = uVar11 + 1;
                                local_c = puVar12;
                            } while (uVar11 < uVar15);
                        }
                        uVar16 = uVar16 + 1;
                    } while (uVar16 < static_cast<uint32_t>(static_cast<uint16_t>(psVar6[2])));
                }
                uVar14 = uVar14 + 1;
            } while (uVar14 < param_4);
        }
    } else if (sVar2 == 3) {
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        uVar14 = 0;
        puVar12 = puVar5;
        if (param_4 != 0) {
            do {
                int32_t row = 0;
                if (psVar6[3] != 0) {
                    uVar16 = static_cast<uint16_t>(psVar6[2]);
                    do {
                        uVar15 = 0;
                        if (uVar16 != 0) {
                            iVar10 = row << 2;
                            do {
                                if ((uVar15 < 5) && (row < 5)) {
                                    uVar8 = *reinterpret_cast<uint32_t *>(
                                        iVar10 + *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) + uVar14 * 4));
                                } else {
                                    uVar8 = 0;
                                }
                                *puVar12 = uVar8;
                                uVar16 = static_cast<uint16_t>(psVar6[2]);
                                puVar12 = puVar12 + 1;
                                uVar15 = uVar15 + 1;
                                iVar10 = iVar10 + 0x10;
                            } while (uVar15 < uVar16);
                        }
                        row = row + 1;
                    } while (row < static_cast<int32_t>(static_cast<uint16_t>(psVar6[3])));
                }
                uVar14 = uVar14 + 1;
            } while (uVar14 < param_4);
        }
    } else if (sVar2 == 5) {
        param_4 = (param_4 << 4) / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        uVar14 = *reinterpret_cast<uint32_t *>(obj + 0x34) * param_4;
        uVar16 = 0;
        puVar12 = puVar5;
        if (uVar14 != 0) {
            do {
                *puVar12 = *reinterpret_cast<uint32_t *>(
                    *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) + (uVar16 >> 4) * 4) +
                    ((uVar16 & 3) + (uVar16 >> 2 & 3) * 4) * 4);
                puVar12 = puVar12 + 1;
                uVar16 = uVar16 + 1;
            } while (uVar16 < uVar14);
        }
        uint32_t row = 0;
        param_3 = puVar5;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uVar14 = 0;
            if (psVar6[5] != 0) {
                do {
                    iVar10 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + uVar14 * 4);
                    iVar7 = FUN_006268d6(obj, param_2, param_3, *reinterpret_cast<uint32_t *>(iVar10 + 0x30), param_5);
                    if (iVar7 < 0) {
                        return iVar7;
                    }
                    param_3 = param_3 + *reinterpret_cast<int32_t *>(iVar10 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar10 + 0x28);
                    uVar14 = uVar14 + 1;
                } while (uVar14 < static_cast<uint32_t>(static_cast<uint16_t>(psVar6[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    sVar2 = psVar6[1];
    if (sVar2 != 3) {
        uVar14 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x34) * static_cast<int32_t>(param_4));
        if (sVar2 == 1) {
            uVar16 = 0;
            if (uVar14 != 0) {
                do {
                    pfVar1 = reinterpret_cast<float *>(puVar5 + uVar16);
                    uVar16 = uVar16 + 1;
                    *pfVar1 = static_cast<float>(static_cast<uint32_t>(*pfVar1 != 0.0f));
                } while (uVar16 < uVar14);
            }
        } else if ((sVar2 == 2) && (uVar16 = 0, uVar14 != 0)) {
            do {
                pfVar1 = reinterpret_cast<float *>(puVar5 + uVar16);
                uVar16 = uVar16 + 1;
                *pfVar1 = static_cast<float>(static_cast<int32_t>(roundf(*pfVar1)));  // observed ROUND(f32) — ties away from zero
            } while (uVar16 < uVar14);
        }
    }
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar6 == 3) {
            uVar3 = static_cast<uint16_t>(psVar6[2]);
            uVar4 = static_cast<uint16_t>(psVar6[3]);
        } else {
            uVar3 = static_cast<uint16_t>(psVar6[3]);
            uVar4 = static_cast<uint16_t>(psVar6[2]);
        }
        uVar14 = uVar3;
        if ((uVar3 & 3) != 0) {
            local_10 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar4 * param_4);
            uVar16 = (uVar14 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                iVar10 = local_18 * 4 + 4;
                puVar9 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar10) * uVar14 +
                                                      reinterpret_cast<uintptr_t>(puVar5));
                local_c = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar10) * uVar16 +
                                                       reinterpret_cast<uintptr_t>(puVar5));
                puVar12 = puVar5 + local_18 * uVar16 + uVar14;
                do {
                    local_c = local_c - uVar16;
                    puVar12 = puVar12 - uVar16;
                    puVar9 = puVar9 - uVar14;
                    if (uVar14 < uVar16) {
                        puVar13 = local_c;
                        intptr_t padIndex = static_cast<intptr_t>(uVar16);
                        do {
                            padIndex = padIndex - 1;
                            puVar13 = puVar13 - 1;
                            *puVar13 = local_10[static_cast<uint32_t>(padIndex) & 3];
                        } while (uVar14 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar14 != 0) {
                        puVar13 = puVar12;
                        uint32_t *pSrc = puVar9;
                        local_14 = uVar14;
                        do {
                            pSrc = pSrc - 1;
                            puVar13 = puVar13 - 1;
                            local_14 = local_14 - 1;
                            *puVar13 = *pSrc;
                        } while (local_14 != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(uint32_t, uint32_t, uint32_t *, uint32_t *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar10 = fn(param_2, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
                puVar5, puVar5, param_4);
    if (iVar10 < 0) {
        return iVar10;
    }
    return 0;
}

// 0x6278c3 — observed shape
int FUN_006278c3(int param_1, uint32_t param_2, uint32_t *param_3, uint32_t param_4, int param_5)
{
    int16_t sVar1;
    uint16_t uVar2;
    uint32_t *puVar3;
    int16_t *psVar4;
    int32_t iVar5;
    uint32_t *puVar6;
    uint32_t *puVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    int32_t iVar10;
    uint32_t *puVar11;
    uint16_t uVar12;
    uint32_t uVar13;
    int32_t local_18;
    uint32_t local_14;
    const uint32_t *local_10;
    uint32_t *local_c;
    const int32_t obj = param_1;

    puVar3 = *reinterpret_cast<uint32_t **>(param_1 + 0x20);
    psVar4 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    sVar1 = *psVar4;
    local_c = param_3;
    if (sVar1 == 0) {
        param_4 = param_4 * 0x10;
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uVar8 = 0;
        puVar6 = puVar3;
        if (param_4 != 0) {
            do {
                *puVar6 = param_3[(uVar8 >> 2 & 3) + ((uVar8 & 3) + (uVar8 >> 4) * 4) * 4];
                puVar6 = puVar6 + 1;
                uVar8 = uVar8 + 1;
            } while (uVar8 < param_4);
        }
    } else if (sVar1 == 1) {
        param_4 = param_4 * 4;
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uVar8 = 0;
        if (param_4 != 0) {
            uVar13 = static_cast<uint16_t>(psVar4[3]);
            puVar6 = puVar3;
            do {
                uVar9 = 0;
                if (uVar13 != 0) {
                    do {
                        if (uVar9 < 5) {
                            uVar13 = param_3[(uVar8 & 3) + (uVar9 + (uVar8 & 0xfffffffc)) * 4];
                        } else {
                            uVar13 = 0;
                        }
                        *puVar6 = uVar13;
                        uVar13 = static_cast<uint16_t>(psVar4[3]);
                        puVar6 = puVar6 + 1;
                        uVar9 = uVar9 + 1;
                    } while (uVar9 < uVar13);
                }
                uVar8 = uVar8 + 1;
            } while (uVar8 < param_4);
        }
    } else if (sVar1 == 2) {
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uVar12 = static_cast<uint16_t>(psVar4[2]);
        if ((uVar12 == 4) && (psVar4[3] == 4)) {
            if (param_4 != 0) {
                puVar6 = puVar3 + 2;
                puVar7 = param_3 + 8;
                uVar8 = param_4;
                do {
                    puVar6[-2] = puVar7[-8];
                    puVar6[-1] = puVar7[-4];
                    *puVar6 = *puVar7;
                    puVar6[1] = puVar7[4];
                    puVar6[2] = puVar7[-7];
                    puVar6[3] = puVar7[-3];
                    puVar6[4] = puVar7[1];
                    puVar6[5] = puVar7[5];
                    *reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puVar3) -
                                                  reinterpret_cast<intptr_t>(param_3) +
                                                  reinterpret_cast<intptr_t>(puVar7)) = puVar7[-6];
                    puVar6[7] = puVar7[-2];
                    puVar6[8] = puVar7[2];
                    puVar6[9] = puVar7[6];
                    puVar6[10] = puVar7[-5];
                    puVar6[0xb] = puVar7[-1];
                    puVar6[0xc] = puVar7[3];
                    puVar6[0xd] = puVar7[7];
                    puVar7 = puVar7 + 0x10;
                    puVar6 = puVar6 + 0x10;
                    uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
            }
        } else {
            uint32_t row = 0;
            puVar6 = puVar3;
            if (param_4 != 0) {
                do {
                    uVar8 = 0;
                    if (uVar12 != 0) {
                        uVar13 = static_cast<uint16_t>(psVar4[3]);
                        do {
                            uVar9 = 0;
                            if (uVar13 != 0) {
                                do {
                                    if ((uVar8 < 5) && (uVar9 < 5)) {
                                        uVar13 = param_3[uVar8 + (uVar9 + row * 4) * 4];
                                    } else {
                                        uVar13 = 0;
                                    }
                                    *puVar6 = uVar13;
                                    uVar13 = static_cast<uint16_t>(psVar4[3]);
                                    puVar6 = puVar6 + 1;
                                    uVar9 = uVar9 + 1;
                                } while (uVar9 < uVar13);
                            }
                            uVar12 = static_cast<uint16_t>(psVar4[2]);
                            uVar8 = uVar8 + 1;
                        } while (uVar8 < uVar12);
                    }
                    row = row + 1;
                } while (row < param_4);
            }
        }
    } else if (sVar1 == 3) {
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uVar12 = static_cast<uint16_t>(psVar4[2]);
        if ((uVar12 == 4) && (psVar4[3] == 4)) {
            goto LAB_00627c22;
        }
        uVar8 = 0;
        puVar6 = puVar3;
        if (param_4 != 0) {
            do {
                uint32_t row = 0;
                if (psVar4[3] != 0) {
                    uVar13 = uVar12;
                    do {
                        uVar9 = 0;
                        if (uVar13 != 0) {
                            do {
                                if ((uVar9 < 5) && (row < 5)) {
                                    uVar13 = param_3[uVar9 + (row + uVar8 * 4) * 4];
                                } else {
                                    uVar13 = 0;
                                }
                                *puVar6 = uVar13;
                                uVar12 = static_cast<uint16_t>(psVar4[2]);
                                puVar6 = puVar6 + 1;
                                uVar13 = uVar12;
                                uVar9 = uVar9 + 1;
                            } while (uVar9 < uVar13);
                        }
                        row = row + 1;
                    } while (row < static_cast<uint32_t>(static_cast<uint16_t>(psVar4[3])));
                }
                uVar8 = uVar8 + 1;
            } while (uVar8 < param_4);
        }
    } else if (sVar1 == 5) {
        param_4 = (param_4 << 4) / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar4[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar4[4]);
        }
        uVar8 = *reinterpret_cast<uint32_t *>(obj + 0x34) * param_4;
        uVar13 = 0;
        puVar6 = puVar3;
        if (uVar8 != 0) {
            do {
                *puVar6 = param_3[(uVar13 >> 2 & 3) + ((uVar13 & 3) + (uVar13 >> 4) * 4) * 4];
                puVar6 = puVar6 + 1;
                uVar13 = uVar13 + 1;
            } while (uVar13 < uVar8);
        }
        uint32_t row = 0;
        local_c = puVar3;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uVar8 = 0;
            if (psVar4[5] != 0) {
                do {
                    iVar10 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + uVar8 * 4);
                    iVar5 = FUN_006268d6(obj, param_2, local_c, *reinterpret_cast<uint32_t *>(iVar10 + 0x30), param_5);
                    if (iVar5 < 0) {
                        return iVar5;
                    }
                    local_c = local_c + *reinterpret_cast<int32_t *>(iVar10 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar10 + 0x28);
                    uVar8 = uVar8 + 1;
                } while (uVar8 < static_cast<uint32_t>(static_cast<uint16_t>(psVar4[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    local_c = puVar3;
LAB_00627c22:
    sVar1 = psVar4[1];
    if (sVar1 != 3) {
        iVar10 = *reinterpret_cast<int32_t *>(obj + 0x34) * static_cast<int32_t>(param_4);
        if (sVar1 == 1) {
            if (iVar10 != 0) {
                puVar6 = puVar3;
                do {
                    *puVar6 = static_cast<uint32_t>(
                        *reinterpret_cast<float *>(reinterpret_cast<intptr_t>(puVar6) +
                                                   (reinterpret_cast<intptr_t>(local_c) -
                                                    reinterpret_cast<intptr_t>(puVar3))) != 0.0f);
                    puVar6 = puVar6 + 1;
                    iVar10 = iVar10 + -1;
                } while (iVar10 != 0);
            }
        } else if ((sVar1 == 2) && (iVar10 != 0)) {
            puVar6 = puVar3;
            do {
                *puVar6 = static_cast<uint32_t>(static_cast<int32_t>(roundf(
                    *reinterpret_cast<float *>(reinterpret_cast<intptr_t>(puVar6) +
                                               (reinterpret_cast<intptr_t>(local_c) -
                                                reinterpret_cast<intptr_t>(puVar3))))));  // observed ROUND(f32) — ties away from zero
                puVar6 = puVar6 + 1;
                iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
        }
        local_c = puVar3;
    }
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar4 == 3) {
            uVar12 = static_cast<uint16_t>(psVar4[2]);
            uVar2 = static_cast<uint16_t>(psVar4[3]);
        } else {
            uVar12 = static_cast<uint16_t>(psVar4[3]);
            uVar2 = static_cast<uint16_t>(psVar4[2]);
        }
        uVar8 = uVar12;
        if ((uVar12 & 3) != 0) {
            local_10 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar2 * param_4);
            uVar13 = (uVar8 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                iVar10 = local_18 * 4 + 4;
                puVar7 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar10) * uVar8 +
                                                      reinterpret_cast<uintptr_t>(local_c));
                local_c = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar10) * uVar13 +
                                                       reinterpret_cast<uintptr_t>(puVar3));
                puVar6 = puVar3 + local_18 * uVar13 + uVar8;
                do {
                    local_c = local_c - uVar13;
                    puVar6 = puVar6 - uVar13;
                    puVar7 = puVar7 - uVar8;
                    if (uVar8 < uVar13) {
                        puVar11 = local_c;
                        intptr_t padIndex = static_cast<intptr_t>(uVar13);
                        do {
                            padIndex = padIndex - 1;
                            puVar11 = puVar11 - 1;
                            *puVar11 = local_10[static_cast<uint32_t>(padIndex) & 3];
                        } while (uVar8 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar8 != 0) {
                        puVar11 = puVar6;
                        uint32_t *pSrc = puVar7;
                        local_14 = uVar8;
                        do {
                            pSrc = pSrc - 1;
                            puVar11 = puVar11 - 1;
                            local_14 = local_14 - 1;
                            *puVar11 = *pSrc;
                        } while (local_14 != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
            local_c = puVar3;
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(uint32_t, uint32_t, uint32_t *, uint32_t *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar10 = fn(param_2, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
                local_c, puVar3, param_4);
    if (iVar10 < 0) {
        return iVar10;
    }
    return 0;
}

// 0x627dcb — observed shape
int FUN_00627dcb(int param_1, uint32_t param_2, uint32_t *param_3, uint32_t param_4, int param_5)
{
    float *pfVar1;
    int16_t sVar2;
    uint16_t uVar3;
    uint16_t uVar4;
    uint32_t *puVar5;
    int16_t *psVar6;
    int32_t iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t *puVar10;
    int32_t iVar11;
    uint32_t uVar12;
    uint32_t *puVar13;
    uint32_t *puVar14;
    uint32_t uVar15;
    uint32_t uVar16;
    int32_t local_18;
    uint32_t local_14;
    const uint32_t *local_10;
    uint32_t *local_c;
    const int32_t obj = param_1;

    puVar5 = *reinterpret_cast<uint32_t **>(param_1 + 0x20);
    psVar6 = *reinterpret_cast<int16_t **>(param_1 + 0x18);
    sVar2 = *psVar6;
    uVar15 = 0;
    if (sVar2 == 0) {
        param_4 = param_4 * 0x10;
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        puVar13 = puVar5;
        if (param_4 != 0) {
            do {
                *puVar13 = *reinterpret_cast<uint32_t *>(
                    *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) + (uVar15 >> 4) * 4) +
                    ((uVar15 >> 2 & 3) + (uVar15 & 3) * 4) * 4);
                puVar13 = puVar13 + 1;
                uVar15 = uVar15 + 1;
            } while (uVar15 < param_4);
        }
    } else if (sVar2 == 1) {
        param_4 = param_4 * 4;
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        int32_t row = 0;
        if (param_4 != 0) {
            uVar15 = static_cast<uint16_t>(psVar6[3]);
            puVar13 = puVar5;
            do {
                uVar16 = 0;
                if (uVar15 != 0) {
                    do {
                        if (uVar16 < 5) {
                            uVar9 = *reinterpret_cast<uint32_t *>(
                                *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) +
                                                             (static_cast<uint32_t>(row) & 0xfffffffc)) +
                                ((static_cast<uint32_t>(row) & 3) + uVar16 * 4) * 4);
                        } else {
                            uVar9 = 0;
                        }
                        *puVar13 = uVar9;
                        uVar15 = static_cast<uint16_t>(psVar6[3]);
                        puVar13 = puVar13 + 1;
                        uVar16 = uVar16 + 1;
                    } while (uVar16 < uVar15);
                }
                row = row + 1;
            } while (row < static_cast<int32_t>(param_4));
        }
    } else if (sVar2 == 2) {
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        uVar15 = 0;
        puVar13 = puVar5;
        if (param_4 != 0) {
            do {
                uint32_t col = 0;
                if (psVar6[2] != 0) {
                    uVar16 = static_cast<uint16_t>(psVar6[3]);
                    do {
                        uVar8 = 0;
                        if (uVar16 != 0) {
                            iVar11 = static_cast<int32_t>(col) << 2;
                            do {
                                if ((col < 5) && (uVar8 < 5)) {
                                    uVar9 = *reinterpret_cast<uint32_t *>(
                                        iVar11 + *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) + uVar15 * 4));
                                } else {
                                    uVar9 = 0;
                                }
                                *puVar13 = uVar9;
                                uVar16 = static_cast<uint16_t>(psVar6[3]);
                                puVar13 = puVar13 + 1;
                                uVar8 = uVar8 + 1;
                                iVar11 = iVar11 + 0x10;
                            } while (uVar8 < uVar16);
                        }
                        col = col + 1;
                    } while (col < static_cast<uint32_t>(static_cast<uint16_t>(psVar6[2])));
                }
                uVar15 = uVar15 + 1;
            } while (uVar15 < param_4);
        }
    } else if (sVar2 == 3) {
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        uVar15 = 0;
        local_c = puVar5;
        if (param_4 != 0) {
            do {
                uVar16 = 0;
                if (psVar6[3] != 0) {
                    uVar8 = static_cast<uint16_t>(psVar6[2]);
                    do {
                        uVar12 = 0;
                        if (uVar8 != 0) {
                            do {
                                if ((uVar12 < 5) && (uVar16 < 5)) {
                                    uVar9 = *reinterpret_cast<uint32_t *>(
                                        *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) + uVar15 * 4) +
                                        (uVar12 + uVar16 * 4) * 4);
                                } else {
                                    uVar9 = 0;
                                }
                                puVar13 = local_c + 1;
                                *local_c = uVar9;
                                uVar8 = static_cast<uint16_t>(psVar6[2]);
                                uVar12 = uVar12 + 1;
                                local_c = puVar13;
                            } while (uVar12 < uVar8);
                        }
                        uVar16 = uVar16 + 1;
                    } while (uVar16 < static_cast<uint32_t>(static_cast<uint16_t>(psVar6[3])));
                }
                uVar15 = uVar15 + 1;
            } while (uVar15 < param_4);
        }
    } else if (sVar2 == 5) {
        param_4 = (param_4 << 4) / *reinterpret_cast<uint32_t *>(obj + 0x34);
        if (static_cast<uint16_t>(psVar6[4]) < param_4) {
            param_4 = static_cast<uint16_t>(psVar6[4]);
        }
        uVar15 = *reinterpret_cast<uint32_t *>(obj + 0x34) * param_4;
        uVar16 = 0;
        puVar13 = puVar5;
        if (uVar15 != 0) {
            do {
                *puVar13 = *reinterpret_cast<uint32_t *>(
                    *reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(param_3) + (uVar16 >> 4) * 4) +
                    ((uVar16 >> 2 & 3) + (uVar16 & 3) * 4) * 4);
                puVar13 = puVar13 + 1;
                uVar16 = uVar16 + 1;
            } while (uVar16 < uVar15);
        }
        uint32_t row = 0;
        param_3 = puVar5;
        if (param_4 == 0) {
            return 0;
        }
        do {
            uVar15 = 0;
            if (psVar6[5] != 0) {
                do {
                    iVar11 = *reinterpret_cast<int32_t *>(*reinterpret_cast<uint32_t *>(obj + 0x38) + uVar15 * 4);
                    iVar7 = FUN_006268d6(obj, param_2, param_3, *reinterpret_cast<uint32_t *>(iVar11 + 0x30), param_5);
                    if (iVar7 < 0) {
                        return iVar7;
                    }
                    param_3 = param_3 + *reinterpret_cast<int32_t *>(iVar11 + 0x30);
                    param_5 = param_5 + *reinterpret_cast<int32_t *>(iVar11 + 0x28);
                    uVar15 = uVar15 + 1;
                } while (uVar15 < static_cast<uint32_t>(static_cast<uint16_t>(psVar6[5])));
            }
            row = row + 1;
        } while (row < param_4);
        return 0;
    } else {
        return -0x7fffbfff;
    }
    sVar2 = psVar6[1];
    if (sVar2 != 3) {
        uVar15 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x34) * static_cast<int32_t>(param_4));
        if (sVar2 == 1) {
            uVar16 = 0;
            if (uVar15 != 0) {
                do {
                    pfVar1 = reinterpret_cast<float *>(puVar5 + uVar16);
                    uVar16 = uVar16 + 1;
                    *pfVar1 = static_cast<float>(static_cast<uint32_t>(*pfVar1 != 0.0f));
                } while (uVar16 < uVar15);
            }
        } else if ((sVar2 == 2) && (uVar16 = 0, uVar15 != 0)) {
            do {
                pfVar1 = reinterpret_cast<float *>(puVar5 + uVar16);
                uVar16 = uVar16 + 1;
                *pfVar1 = static_cast<float>(static_cast<int32_t>(roundf(*pfVar1)));  // observed ROUND(f32) — ties away from zero
            } while (uVar16 < uVar15);
        }
    }
    if (*reinterpret_cast<int16_t *>(obj + 8) != 0) {
        if (*psVar6 == 3) {
            uVar3 = static_cast<uint16_t>(psVar6[2]);
            uVar4 = static_cast<uint16_t>(psVar6[3]);
        } else {
            uVar3 = static_cast<uint16_t>(psVar6[3]);
            uVar4 = static_cast<uint16_t>(psVar6[2]);
        }
        uVar15 = uVar3;
        if ((uVar3 & 3) != 0) {
            local_10 = (*reinterpret_cast<int16_t *>(obj + 8) == 1) ? DAT_006e1924 : DAT_006e1914;
            local_18 = static_cast<int32_t>(uVar4 * param_4);
            uVar16 = (uVar15 + 3) & 0xfffffffc;
            if (local_18 != 0) {
                iVar11 = local_18 * 4 + 4;
                puVar10 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar11) * uVar15 +
                                                       reinterpret_cast<uintptr_t>(puVar5));
                local_c = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar11) * uVar16 +
                                                       reinterpret_cast<uintptr_t>(puVar5));
                puVar13 = puVar5 + local_18 * uVar16 + uVar15;
                do {
                    local_c = local_c - uVar16;
                    puVar13 = puVar13 - uVar16;
                    puVar10 = puVar10 - uVar15;
                    if (uVar15 < uVar16) {
                        puVar14 = local_c;
                        intptr_t padIndex = static_cast<intptr_t>(uVar16);
                        do {
                            padIndex = padIndex - 1;
                            puVar14 = puVar14 - 1;
                            *puVar14 = local_10[static_cast<uint32_t>(padIndex) & 3];
                        } while (uVar15 < static_cast<uint32_t>(padIndex));
                    }
                    if (uVar15 != 0) {
                        puVar14 = puVar13;
                        uint32_t *pSrc = puVar10;
                        local_14 = uVar15;
                        do {
                            pSrc = pSrc - 1;
                            puVar14 = puVar14 - 1;
                            local_14 = local_14 - 1;
                            *puVar14 = *pSrc;
                        } while (local_14 != 0);
                    }
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
            }
        }
    }
    param_4 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(obj + 0x2c) * static_cast<int32_t>(param_4));
    if (*reinterpret_cast<uint16_t *>(obj + 0xc) < param_4) {
        param_4 = *reinterpret_cast<uint16_t *>(obj + 0xc);
    }
    using Fn = int (*)(uint32_t, uint32_t, uint32_t *, uint32_t *, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<uint32_t *>(obj + 0x1c));
    iVar11 = fn(param_2, static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(obj + 0xa)) + static_cast<uint32_t>(param_5),
                puVar5, puVar5, param_4);
    if (iVar11 < 0) {
        return iVar11;
    }
    return 0;
}

extern void FUN_00625cc6(void);
extern void FUN_00625c0c(void);
extern void FUN_00625c70(void);
extern void FUN_00625d72(void);
extern void FUN_00625d90(void);
extern void FUN_00625dd1(void);
extern void FUN_00625e67(void);
extern void FUN_00625e23(void);
extern void FUN_00625e85(void);
extern void FUN_00625eeb(void);
extern void FUN_00625f09(void);
extern void FUN_00625f53(void);
extern void FUN_00625f8e(void);
extern void FUN_00625fac(void);
extern void FUN_00625fed(void);
extern void FUN_00625ae5(void);
extern void FUN_00625aa1(void);
extern void FUN_00625b03(void);
extern void FUN_00625b69(void);
extern void FUN_00625b87(void);
extern void FUN_00625bd1(void);
extern void *FUN_00533c78(uint32_t size);
extern int FUN_00625749(void *self, uint32_t param_1, uint32_t *param_2, int param_3,
                         void (*param_4)(void), uint32_t param_5);
extern uint32_t FUN_0062849d(void *self);
extern void FUN_00625d03(void *self, uint8_t param_1);

// 0x628205 — observed shape
int FUN_00628205(int param_1, int param_2, int param_3, uint32_t param_4)
{
    int16_t sVar1;
    int32_t iVar2;
    int32_t iVar3;
    uint32_t uVar4;
    void (*pcVar5)(void) = nullptr;

    uVar4 = *reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(param_1 + 0x10) + 8) & 0xffff0000;
    if (*reinterpret_cast<int16_t *>(param_3 + 10) == 0) {
        if (uVar4 == 0x54580000) {
            if (*reinterpret_cast<int16_t *>(param_2 + 4) == 2) {
                sVar1 = *reinterpret_cast<int16_t *>(param_3 + 2);
                if (sVar1 == 0) {
                    pcVar5 = FUN_00625cc6;
                } else if (sVar1 == 1) {
                    pcVar5 = FUN_00625c0c;
                } else if (sVar1 == 2) {
                    pcVar5 = FUN_00625c70;
                } else if (sVar1 == 3) {
                    pcVar5 = FUN_00625cc6;
                }
            }
            goto LAB_00628454;
        }
        if (uVar4 == 0xfffe0000) {
            sVar1 = *reinterpret_cast<int16_t *>(param_2 + 4);
            if (sVar1 == 0) {
                sVar1 = *reinterpret_cast<int16_t *>(param_3 + 2);
                if (sVar1 == 0) {
                    pcVar5 = FUN_00625d72;
                    goto LAB_00628454;
                }
                if (sVar1 != 1) {
                    if (sVar1 == 2) {
                        pcVar5 = FUN_00625d90;
                    } else if (sVar1 == 3) {
                        pcVar5 = FUN_00625dd1;
                    }
                    goto LAB_00628454;
                }
                goto LAB_0062844f;
            }
            if (sVar1 == 1) {
                sVar1 = *reinterpret_cast<int16_t *>(param_3 + 2);
                if (sVar1 == 0) {
                    pcVar5 = FUN_00625e67;
                    goto LAB_00628454;
                }
                if (sVar1 == 1) {
                    pcVar5 = FUN_00625e23;
                    goto LAB_00628454;
                }
                if (sVar1 != 2) {
                    if (sVar1 == 3) {
                        pcVar5 = FUN_00625e85;
                    }
                    goto LAB_00628454;
                }
                goto LAB_0062837c;
            }
            if (sVar1 != 2) goto LAB_00628454;
            uVar4 = static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(param_3 + 2));
            if (uVar4 == 0) {
                pcVar5 = FUN_00625eeb;
                goto LAB_00628454;
            }
            if (uVar4 == 1) {
                pcVar5 = FUN_00625f09;
                goto LAB_00628454;
            }
            iVar2 = static_cast<int32_t>(uVar4) - 2;
            if (iVar2 == 0) {
                pcVar5 = FUN_00625f53;
                goto LAB_00628454;
            }
            goto LAB_0062832e;
        }
        if (uVar4 != 0xffff0000) goto LAB_00628454;
        sVar1 = *reinterpret_cast<int16_t *>(param_2 + 4);
        if (sVar1 == 0) {
            sVar1 = *reinterpret_cast<int16_t *>(param_3 + 2);
            if (sVar1 == 0) {
                pcVar5 = FUN_00625f8e;
                goto LAB_00628454;
            }
            if (sVar1 != 1) {
                if (sVar1 == 2) {
                    pcVar5 = FUN_00625fac;
                } else if (sVar1 == 3) {
                    pcVar5 = FUN_00625fed;
                }
                goto LAB_00628454;
            }
            goto LAB_006282f3;
        }
        if (sVar1 == 1) {
            sVar1 = *reinterpret_cast<int16_t *>(param_3 + 2);
            if (sVar1 == 0) {
                pcVar5 = FUN_00625ae5;
                goto LAB_00628454;
            }
            if (sVar1 == 1) {
                pcVar5 = FUN_00625aa1;
                goto LAB_00628454;
            }
            if (sVar1 != 2) {
                if (sVar1 == 3) {
                    pcVar5 = FUN_00625b03;
                }
                goto LAB_00628454;
            }
            goto LAB_00628431;
        }
        if (sVar1 != 2) goto LAB_00628454;
        uVar4 = static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(param_3 + 2));
        if (uVar4 == 0) {
            pcVar5 = FUN_00625b69;
            goto LAB_00628454;
        }
        if (uVar4 == 1) {
            pcVar5 = FUN_00625b87;
            goto LAB_00628454;
        }
        iVar2 = static_cast<int32_t>(uVar4) - 2;
        if (iVar2 == 0) {
            pcVar5 = FUN_00625bd1;
            goto LAB_00628454;
        }
    } else {
        if (uVar4 == 0xfffe0000) {
            if (*reinterpret_cast<uint16_t *>(param_2 + 4) == 0) {
LAB_0062844f:
                pcVar5 = FUN_00625d72;
                goto LAB_00628454;
            }
            iVar2 = static_cast<int32_t>(*reinterpret_cast<uint16_t *>(param_2 + 4)) - 1;
            if (iVar2 == 0) {
LAB_0062837c:
                pcVar5 = FUN_00625e67;
                goto LAB_00628454;
            }
LAB_0062832e:
            if (iVar2 == 1) {
                pcVar5 = FUN_00625eeb;
            }
            goto LAB_00628454;
        }
        if (uVar4 != 0xffff0000) goto LAB_00628454;
        if (*reinterpret_cast<uint16_t *>(param_2 + 4) == 0) {
LAB_006282f3:
            pcVar5 = FUN_00625f8e;
            goto LAB_00628454;
        }
        iVar2 = static_cast<int32_t>(*reinterpret_cast<uint16_t *>(param_2 + 4)) - 1;
        if (iVar2 == 0) {
LAB_00628431:
            pcVar5 = FUN_00625ae5;
            goto LAB_00628454;
        }
    }
    if (iVar2 == 1) {
        pcVar5 = FUN_00625b69;
    }
LAB_00628454:
    iVar2 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x44)));
    if (iVar2 == 0) {
        iVar2 = 0;
    } else {
        iVar2 = FUN_00625749(reinterpret_cast<void *>(static_cast<intptr_t>(iVar2)), param_1, param_2, param_3,
                             pcVar5, param_4);
    }
    if (iVar2 != 0) {
        iVar3 = static_cast<int32_t>(FUN_0062849d(reinterpret_cast<void *>(static_cast<intptr_t>(iVar2))));
        if (-1 < iVar3) {
            return iVar2;
        }
        // NEEDS_MANUAL: the listing does not expose the ECX receiver of
        // FUN_00625d03; the object whose setup failed is forwarded.
        FUN_00625d03(reinterpret_cast<void *>(static_cast<intptr_t>(iVar2)), 1);
    }
    return 0;
}

// 0x62849d — observed shape
extern void FUN_0062564d(int32_t param_1, void *param_2, int32_t param_3, uint32_t param_4,
                         uint32_t *param_5, uint32_t *param_6);
uint32_t FUN_0062849d(void *self)
{
    uint16_t uVar1;
    uint32_t *puVar2;
    uint32_t uVar3;
    int32_t *in_ECX = reinterpret_cast<int32_t *>(self);
    uint32_t uVar4;
    int32_t iVar5;
    int32_t iVar6;
    int32_t *piVar7;
    int32_t *piVar8;
    alignas(8) uint8_t local_2c[24] = {0};
    uint32_t local_10;
    uint32_t local_14;
    int32_t local_c;
    uint32_t local_8;

    if (*reinterpret_cast<int16_t *>(in_ECX[6] + 10) != 0) {
        puVar2 = reinterpret_cast<uint32_t *>(FUN_00533c78(
            static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(in_ECX[6] + 10)) << 2));
        in_ECX[0xe] = static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar2));
        if (puVar2 == nullptr) {
            return 0x8007000e;
        }
        for (uVar4 = static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(in_ECX[6] + 10)); uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar2 = 0;
            puVar2 = puVar2 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *reinterpret_cast<uint8_t *>(puVar2) = 0;
            puVar2 = reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puVar2) + 1);
        }
        local_c = in_ECX[8];
        iVar5 = in_ECX[6];
        piVar7 = reinterpret_cast<int32_t *>(local_2c);
        piVar8 = in_ECX;
        for (iVar6 = 5; piVar8 = piVar8 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar7 = *piVar8;
            piVar7 = piVar7 + 1;
        }
        uVar4 = static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(iVar5 + 10));
        iVar5 = *reinterpret_cast<int32_t *>(iVar5 + 0xc);
        if (*reinterpret_cast<uint32_t *>(*in_ECX + 0xc) <
            static_cast<uint32_t>(iVar5) + uVar4 * 8) {
            return 0x80004005;
        }
        local_8 = 0;
        piVar8 = reinterpret_cast<int32_t *>(*reinterpret_cast<int32_t *>(*in_ECX + 8) + iVar5);
        if (uVar4 != 0) {
            do {
                iVar5 = *in_ECX;
                if (*reinterpret_cast<uint32_t *>(iVar5 + 0xc) <
                    static_cast<uint32_t>(piVar8[1]) + 0x10U) {
                    return 0x80004005;
                }
                local_10 = 0;
                local_14 = 0;
                iVar6 = *reinterpret_cast<int32_t *>(iVar5 + 8) + piVar8[1];
                FUN_0062564d(iVar5, local_2c, iVar6, 1, &local_10, &local_14);
                *reinterpret_cast<int32_t *>(local_2c + 0) = *piVar8;
                *reinterpret_cast<int32_t *>(local_2c + 0xc) = piVar8[1];
                *reinterpret_cast<uint32_t *>(local_2c + 0x14) =
                    static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(reinterpret_cast<intptr_t>(in_ECX) + 10));
                uVar1 = static_cast<uint16_t>(*reinterpret_cast<int16_t *>(iVar6 + 8) *
                                              static_cast<int16_t>(local_10 & 0xffff));
                uVar4 = *reinterpret_cast<uint16_t *>(local_2c + 6);
                *reinterpret_cast<uint16_t *>(local_2c + 8) = uVar1;
                if (*reinterpret_cast<uint32_t *>(local_2c + 0x14) +
                        *reinterpret_cast<uint16_t *>(reinterpret_cast<intptr_t>(in_ECX) + 0xc) <
                    uVar4 + uVar1) {
                    *reinterpret_cast<uint16_t *>(local_2c + 8) = static_cast<uint16_t>(
                        (static_cast<uint16_t>(*reinterpret_cast<uint16_t *>(reinterpret_cast<intptr_t>(in_ECX) + 10)) -
                         static_cast<int16_t>(*reinterpret_cast<int16_t *>(local_2c + 6))) +
                        static_cast<int16_t>(in_ECX[3]));
                }
                uVar3 = FUN_00628205(*in_ECX, static_cast<int32_t>(reinterpret_cast<intptr_t>(local_2c)), iVar6, local_c);
                *reinterpret_cast<uint32_t *>(in_ECX[0xe] + local_8 * 4) = uVar3;
                piVar7 = reinterpret_cast<int32_t *>(in_ECX[0xe] + local_8 * 4);
                if (*piVar7 == 0) {
                    return 0x8007000e;
                }
                *reinterpret_cast<uint16_t *>(local_2c + 8) = static_cast<uint16_t>(
                    static_cast<uint16_t>(*reinterpret_cast<int16_t *>(local_2c + 6)) +
                    *reinterpret_cast<uint16_t *>(local_2c + 8));
                local_c = local_c + ((-(static_cast<uint32_t>(*reinterpret_cast<int16_t *>(local_2c + 4) != 0)) & 3) + 1) *
                                        *reinterpret_cast<int32_t *>(*piVar7 + 0x2c) *
                                        static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(iVar6 + 8)) * 4;
                piVar8 = piVar8 + 2;
                local_8 = local_8 + 1;
            } while (local_8 < static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(in_ECX[6] + 10)));
        }
    }
    return 0;
}

// 0x628621 — observed shape
void FUN_00628621(void *self, uint32_t param_1)
{
    uint16_t uVar1;
    int16_t sVar2;
    int32_t iVar3;
    uint16_t uVar4;
    uint32_t *puVar5;
    int32_t iVar6;
    int32_t iVar7;
    uint16_t uVar8;
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);
    uint32_t uVar9;
    int32_t iVar10;
    alignas(8) uint8_t local_1c[24] = {0};
    int32_t local_c;
    int32_t local_8;

    uVar1 = *reinterpret_cast<uint16_t *>(in_ECX[6] + 8);
    if ((param_1 < static_cast<uint32_t>(uVar1)) && (uVar1 != 1)) {
        if (in_ECX[0xf] == 0) {
            puVar5 = reinterpret_cast<uint32_t *>(FUN_00533c78(static_cast<uint32_t>(uVar1) << 2));
            in_ECX[0xf] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar5));
            if (puVar5 == nullptr) {
                return;
            }
            for (uVar9 = static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(in_ECX[6] + 8)); uVar9 != 0; uVar9 = uVar9 - 1) {
                *puVar5 = 0;
                puVar5 = puVar5 + 1;
            }
            for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                *reinterpret_cast<uint8_t *>(puVar5) = 0;
                puVar5 = reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puVar5) + 1);
            }
        }
        local_8 = static_cast<int32_t>(param_1 * 4);
        if (*reinterpret_cast<int32_t *>(local_8 + in_ECX[0xf]) == 0) {
            if (in_ECX[0x10] == 0) {
                puVar5 = reinterpret_cast<uint32_t *>(FUN_00533c78(0x10));
                in_ECX[0x10] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar5));
                if (puVar5 == nullptr) {
                    return;
                }
                uint32_t *puVar11 = reinterpret_cast<uint32_t *>(in_ECX[6]);
                puVar5[0] = puVar11[0];
                puVar5[1] = puVar11[1];
                puVar5[2] = puVar11[2];
                puVar5[3] = puVar11[3];
                *reinterpret_cast<uint16_t *>(in_ECX[0x10] + 8) = 1;
            }
            sVar2 = *reinterpret_cast<int16_t *>(in_ECX + 0xb);
            uVar1 = *reinterpret_cast<uint16_t *>(reinterpret_cast<intptr_t>(in_ECX) + 10);
            int32_t *pDst = reinterpret_cast<int32_t *>(local_1c);
            uint32_t *pSrc = in_ECX;
            for (iVar10 = 5; pSrc = pSrc + 1, iVar10 != 0; iVar10 = iVar10 + -1) {
                *pDst = static_cast<int32_t>(*pSrc);
                pDst = pDst + 1;
            }
            uVar8 = *reinterpret_cast<uint16_t *>(in_ECX + 0xb);
            uVar4 = static_cast<uint16_t>(sVar2 * static_cast<int16_t>(param_1) + uVar1);
            if (static_cast<int32_t>(((static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(in_ECX + 3)) -
                                       static_cast<uint32_t>(uVar4)) +
                                      static_cast<uint32_t>(uVar1))) < static_cast<int32_t>(static_cast<uint32_t>(uVar8))) {
                uVar8 = static_cast<uint16_t>(
                    (*reinterpret_cast<uint16_t *>(in_ECX + 3) - uVar4) + uVar1);
            }
            *reinterpret_cast<uint16_t *>(local_1c + 4) = uVar4;
            *reinterpret_cast<uint16_t *>(local_1c + 6) = uVar8;
            iVar10 = (-(static_cast<uint32_t>(*reinterpret_cast<int16_t *>(in_ECX + 2) != 0)) & 3) + 1;
            if (in_ECX[5] != 0) {
                local_c = static_cast<int32_t>(in_ECX[5] + in_ECX[0xb] * iVar10 * param_1 * 4);
            }
            iVar7 = static_cast<int32_t>(in_ECX[0xb]);
            iVar3 = static_cast<int32_t>(in_ECX[8]);
            iVar6 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x44)));
            if (iVar6 == 0) {
                iVar10 = 0;
            } else {
                iVar10 = FUN_00625749(reinterpret_cast<void *>(static_cast<intptr_t>(iVar6)), *in_ECX,
                                      reinterpret_cast<uint32_t *>(local_1c), in_ECX[0x10],
                                      reinterpret_cast<void (*)(void)>(in_ECX[7]),
                                      static_cast<uint32_t>(iVar3 + iVar7 * iVar10 * static_cast<int32_t>(param_1) * 4));
            }
            *reinterpret_cast<int32_t *>(local_8 + in_ECX[0xf]) = iVar10;
            if (iVar10 != 0) {
                iVar7 = static_cast<int32_t>(FUN_0062849d(reinterpret_cast<void *>(static_cast<intptr_t>(iVar10))));
                iVar10 = local_8;
                if (iVar7 < 0) {
                    if (*reinterpret_cast<int32_t *>(local_8 + in_ECX[0xf]) != 0) {
                        FUN_00625d03(reinterpret_cast<void *>(static_cast<intptr_t>(*reinterpret_cast<int32_t *>(local_8 + in_ECX[0xf]))), 1);
                    }
                    *reinterpret_cast<uint32_t *>(iVar10 + in_ECX[0xf]) = 0;
                }
            }
        }
    }
}

extern void *PTR_FUN_006e18a8;
// 0x6287bc — observed shape
void FUN_006287bc(void *self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);
    *in_ECX = reinterpret_cast<uint32_t>(PTR_FUN_006e18a8);
    in_ECX[1] = 1;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
}

extern int32_t FUN_005f7ad0(uint32_t param_1, uint32_t param_2, void *param_3, void *param_4);
extern uint32_t FUN_00625848(uint32_t param_1);
extern int FUN_006294f9(uint32_t param_1, void *param_2);

// 0x6287dd — observed shape
int FUN_006287dd(void *self, int param_1, int param_2)
{
    uint32_t *puVar1;
    int32_t *piVar2;
    int32_t iVar3;
    uint32_t *puVar4;
    uint32_t uVar5;
    int32_t iVar6;
    uint16_t *puVar7;
    int32_t in_ECX = static_cast<int32_t>(reinterpret_cast<intptr_t>(self));
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t *local_c;
    int32_t *local_8;

    if (param_1 == 0) {
        return -0x7789f794;
    }
    puVar1 = reinterpret_cast<uint32_t *>(in_ECX + 0xc);
    iVar3 = FUN_005f7ad0(static_cast<uint32_t>(param_1), 0x42415443, &local_c, puVar1);
    if (iVar3 < 0) {
        return iVar3;
    }
    if (iVar3 == 1) {
        return -0x7789f4a7;
    }
    puVar4 = reinterpret_cast<uint32_t *>(FUN_00533c78(*puVar1));
    *reinterpret_cast<uint32_t **>(in_ECX + 8) = puVar4;
    if (puVar4 == nullptr) {
        return -0x7ff8fff2;
    }
    uVar9 = *puVar1;
    for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar4 = *local_c;
        local_c = local_c + 1;
        puVar4 = puVar4 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *reinterpret_cast<uint8_t *>(puVar4) = *reinterpret_cast<uint8_t *>(local_c);
        local_c = reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(local_c) + 1);
        puVar4 = reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puVar4) + 1);
    }
    puVar1 = *reinterpret_cast<uint32_t **>(in_ECX + 8);
    *reinterpret_cast<uint32_t **>(in_ECX + 0x10) = puVar1;
    if (0x1b < *puVar1) {
        puVar4 = reinterpret_cast<uint32_t *>(FUN_00533c78(puVar1[3] << 2));
        *reinterpret_cast<uint32_t **>(in_ECX + 0x14) = puVar4;
        if (puVar4 == nullptr) {
            return -0x7ff8fff2;
        }
        for (uVar9 = *reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(in_ECX + 0x10) + 0xc) & 0x3fffffff;
             uVar9 != 0; uVar9 = uVar9 - 1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *reinterpret_cast<uint8_t *>(puVar4) = 0;
            puVar4 = reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puVar4) + 1);
        }
        iVar3 = *reinterpret_cast<int32_t *>(in_ECX + 0x10);
        *reinterpret_cast<uint32_t *>(in_ECX + 0x18) = *reinterpret_cast<uint32_t *>(iVar3 + 0xc);
        if (static_cast<uint32_t>(*reinterpret_cast<int32_t *>(iVar3 + 0x10) +
                                  *reinterpret_cast<int32_t *>(iVar3 + 0xc) * 0x14) <=
            *reinterpret_cast<uint32_t *>(in_ECX + 0xc)) {
            param_1 = 0;
            iVar3 = *reinterpret_cast<int32_t *>(in_ECX + 8) + *reinterpret_cast<int32_t *>(iVar3 + 0x10);
            uVar9 = 0;
            if (*reinterpret_cast<int32_t *>(in_ECX + 0x18) != 0) {
                local_8 = reinterpret_cast<int32_t *>(iVar3 + 0xc);
                do {
                    if (*reinterpret_cast<uint32_t *>(in_ECX + 0xc) <
                        static_cast<uint32_t>(*local_8) + 0x10U) {
                        goto LAB_006289df;
                    }
                    uVar5 = static_cast<uint32_t>(FUN_00628205(in_ECX,
                                                               static_cast<int32_t>(reinterpret_cast<intptr_t>(local_8 - 3)),
                                                               *reinterpret_cast<int32_t *>(in_ECX + 8) + *local_8, 0));
                    *reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(in_ECX + 0x14) + uVar9 * 4) = uVar5;
                    piVar2 = reinterpret_cast<int32_t *>(*reinterpret_cast<int32_t *>(in_ECX + 0x14) + uVar9 * 4);
                    if (*piVar2 == 0) {
                        return -0x7ff8fff2;
                    }
                    iVar6 = *piVar2;
                    local_8 = local_8 + 5;
                    param_1 = param_1 + ((-(static_cast<uint32_t>(*reinterpret_cast<int16_t *>(iVar6 + 8) != 0)) & 3) + 1) *
                                            static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(
                                                *reinterpret_cast<int32_t *>(iVar6 + 0x18) + 8)) *
                                            *reinterpret_cast<int32_t *>(iVar6 + 0x2c);
                    uVar9 = uVar9 + 1;
                } while (uVar9 < *reinterpret_cast<uint32_t *>(in_ECX + 0x18));
            }
            iVar6 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(static_cast<uint32_t>(param_1) << 2)));
            uVar9 = 0;
            *reinterpret_cast<int32_t *>(in_ECX + 0x1c) = iVar6;
            if (iVar6 == 0) {
                return -0x7ff8fff2;
            }
            param_1 = 0;
            if (*reinterpret_cast<int32_t *>(in_ECX + 0x18) != 0) {
                do {
                    FUN_00625848(static_cast<uint32_t>(*reinterpret_cast<int32_t *>(in_ECX + 0x1c) + param_1 * 4));
                    iVar6 = *reinterpret_cast<int32_t *>(*reinterpret_cast<int32_t *>(in_ECX + 0x14) + uVar9 * 4);
                    param_1 = param_1 + ((-(static_cast<uint32_t>(*reinterpret_cast<int16_t *>(iVar6 + 8) != 0)) & 3) + 1) *
                                            static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(
                                                *reinterpret_cast<int32_t *>(iVar6 + 0x18) + 8)) *
                                            *reinterpret_cast<int32_t *>(iVar6 + 0x2c);
                    uVar9 = uVar9 + 1;
                } while (uVar9 < *reinterpret_cast<uint32_t *>(in_ECX + 0x18));
            }
            uVar9 = 0;
            if (param_2 != 0) {
                if (*reinterpret_cast<int32_t *>(in_ECX + 0x18) != 0) {
                    iVar6 = *reinterpret_cast<int32_t *>(in_ECX + 0x18);
                    puVar7 = reinterpret_cast<uint16_t *>(iVar3 + 8);
                    do {
                        if (puVar7[-2] == 2) {
                            if (uVar9 < static_cast<uint32_t>(puVar7[-1]) + static_cast<uint32_t>(*puVar7)) {
                                uVar9 = static_cast<uint32_t>(puVar7[-1]) + static_cast<uint32_t>(*puVar7);
                            }
                        }
                        puVar7 = puVar7 + 10;
                        iVar6 = iVar6 - 1;
                    } while (iVar6 != 0);
                }
                iVar3 = FUN_006294f9(uVar9 << 4, reinterpret_cast<void *>(static_cast<intptr_t>(param_2)));
                if (iVar3 < 0) {
                    return iVar3;
                }
            }
            return 0;
        }
    }
LAB_006289df:
    return -0x7789f4a7;
}

// 0x6289e4 — observed shape
int FUN_006289e4(int param_1)
{
    int iVar1 = *reinterpret_cast<int *>(param_1 + 4);
    int iVar2 = *reinterpret_cast<int *>(param_1);
    *reinterpret_cast<int *>(param_1) = iVar1;
    *reinterpret_cast<int *>(param_1 + 4) = iVar2;
    return FUN_005f7f83(1);
}

extern int FUN_00628e20(void *self, int param_1, int param_2, uint32_t param_3);

// 0x628a08 — observed shape
int FUN_00628a08(void *self, int param_1, int param_2)
{
    int32_t in_ECX = static_cast<int32_t>(reinterpret_cast<intptr_t>(self));
    int32_t iVar1;
    int32_t iVar2;
    int32_t iVar3;
    char *pcVar4;
    int32_t iVar5;
    uint32_t uVar6;
    char cVar7;

    param_1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00628e20(self, 0, 0, 0)));
    if (param_1 == 0) {
        return 0;
    }
    iVar3 = 0;
    while ((cVar7 = *reinterpret_cast<char *>(param_1 + iVar3), cVar7 != '\0' && (cVar7 == ' ' || (cVar7 == '\t')))) {
        iVar3 = iVar3 + 1;
    }
    iVar5 = 0;
    while ((cVar7 = *reinterpret_cast<char *>(param_1 + iVar3 + iVar5), cVar7 != '\0' && (cVar7 != ' ' && (cVar7 != '\t')))) {
        iVar5 = iVar5 + 1;
    }
    if (iVar5 != 0) {
        iVar1 = *reinterpret_cast<int32_t *>(in_ECX + 0x18);
        iVar2 = 0;
        if (iVar1 != 0) {
            do {
                pcVar4 = *reinterpret_cast<char **>(*reinterpret_cast<int32_t *>(in_ECX + 0x10) + iVar2 * 4);
                if (pcVar4 != nullptr) {
                    iVar1 = 0;
                    while ((cVar7 = pcVar4[iVar1], cVar7 != '\0' && (cVar7 == ' ' || (cVar7 == '\t')))) {
                        iVar1 = iVar1 + 1;
                    }
                    if (iVar5 == FUN_00625708(pcVar4 + iVar1)) {
                        iVar1 = FUN_00628b56(reinterpret_cast<char *>(param_1 + iVar3), pcVar4 + iVar1, iVar5);
                        if (iVar1 == 0) {
                            param_2 = 1;
                            iVar1 = *reinterpret_cast<int32_t *>(in_ECX + 0x14);
                            if (param_2 < *reinterpret_cast<int32_t *>(iVar1 + 8)) {
                                do {
                                    uVar6 = static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(in_ECX + 8));
                                    if (uVar6 != 0) {
                                        param_1 = 0;
                                        do {
                                            if (param_1 < static_cast<int32_t>(uVar6)) {
                                                FUN_00628621(reinterpret_cast<void *>(static_cast<intptr_t>(in_ECX)), static_cast<uint32_t>(param_1));
                                            }
                                            param_1 = param_1 + 1;
                                        } while (param_1 < static_cast<int32_t>(static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(in_ECX + 8))));
                                    }
                                    iVar3 = FUN_00625957(param_2);
                                    if (iVar3 != 0) {
                                        break;
                                    }
                                    param_2 = param_2 + 1;
                                    iVar1 = *reinterpret_cast<int32_t *>(in_ECX + 0x14);
                                } while (param_2 < *reinterpret_cast<int32_t *>(iVar1 + 8));
                            }
                            return 0;
                        }
                    }
                    iVar1 = *reinterpret_cast<int32_t *>(in_ECX + 0x18);
                }
                iVar2 = iVar2 + 1;
            } while (iVar2 < iVar1);
        }
    }
    return 0;
}

// 0x628b56 — observed shape
int FUN_00628b56(char *param_1, char *param_2, int param_3)
{
    char *pcVar1;
    char *pcVar2;
    int iVar3;
    char cVar4;
    char cVar5;
    char *local_14;
    char *local_10;
    char *local_8;

    local_10 = param_1;
    local_8 = param_2;
    if (param_3 != 0) {
        do {
            if (local_10 == nullptr) {
                pcVar1 = nullptr;
            } else {
                pcVar1 = local_10 + 1;
                cVar4 = *local_10;
                local_10 = pcVar1;
                if ((cVar4 >= 'A') && (cVar4 <= 'Z')) {
                    cVar4 = cVar4 + ' ';
                }
            }
            if (local_8 == nullptr) {
                pcVar2 = nullptr;
            } else {
                pcVar2 = local_8 + 1;
                cVar5 = *local_8;
                local_8 = pcVar2;
                if ((cVar5 >= 'A') && (cVar5 <= 'Z')) {
                    cVar5 = cVar5 + ' ';
                }
            }
            if (pcVar1 == nullptr) {
                if (pcVar2 != nullptr) {
                    return -1;
                }
            } else {
                if (pcVar2 == nullptr) {
                    return 1;
                }
                local_14 = pcVar2;
                if (cVar4 != cVar5) {
                    iVar3 = -1;
                    if (cVar5 <= cVar4) {
                        iVar3 = 1;
                    }
                    return iVar3;
                }
            }
            param_3 = param_3 + -1;
        } while (param_3 != 0);
    }
    return 0;
}

// 0x628d5d — observed shape
int FUN_00628d5d(void *self, uint32_t param_1, int param_2, int param_3, uint32_t *param_4)
{
    int32_t in_ECX = static_cast<int32_t>(reinterpret_cast<intptr_t>(self));
    int32_t *piVar1;
    int32_t *piVar2;
    int32_t iVar3;
    int32_t iVar4;
    uint32_t uVar5;
    uint32_t uVar6;

    if (param_2 < 0) {
        iVar4 = -param_2;
    } else {
        iVar4 = param_2;
    }
    iVar4 = FUN_00628b56(reinterpret_cast<char *>(param_2), reinterpret_cast<char *>(param_3), iVar4);
    if (iVar4 != 0) {
        return iVar4;
    }
    iVar4 = FUN_00628b56(reinterpret_cast<char *>(param_2), reinterpret_cast<char *>(param_3), 1);
    if (iVar4 != 0) {
        return iVar4;
    }
    uVar5 = 0;
    if (param_1 != 0) {
        piVar1 = reinterpret_cast<int32_t *>(*reinterpret_cast<int32_t *>(in_ECX + 0x14) + 0x24);
        do {
            uVar6 = 0;
            iVar4 = *piVar1;
            piVar2 = reinterpret_cast<int32_t *>(*piVar1 + 0x24);
            if (*reinterpret_cast<int32_t *>(iVar4 + 0x28) != 0) {
                do {
                    if (uVar5 < *reinterpret_cast<uint32_t *>(*piVar2 + 0x10)) {
                        uVar5 = *reinterpret_cast<uint32_t *>(*piVar2 + 0x10);
                    }
                    uVar6 = uVar6 + 1;
                    piVar2 = piVar2 + 1;
                } while (uVar6 < static_cast<uint32_t>(*reinterpret_cast<int32_t *>(iVar4 + 0x28)));
            }
            piVar1 = piVar1 + 1;
            param_1 = param_1 - 1;
        } while (param_1 != 0);
    }
    uVar6 = uVar5 - 1;
    iVar4 = FUN_006258ba(param_2, &param_3);
    iVar3 = FUN_006258ba(param_3, &param_4);
    if (iVar4 < 0) {
        return iVar4;
    }
    if (iVar3 < 0) {
        return iVar3;
    }
    return 0;
}

// 0x628de8 — observed shape
uint32_t FUN_00628de8(int param_1, int param_2)
{
    int iVar1;
    if (param_2 < 0) {
        param_2 = -param_2;
    }
    iVar1 = FUN_00628b56(reinterpret_cast<char *>(param_1), reinterpret_cast<char *>(param_2), param_2);
    if (iVar1 == 0) {
        return 0xffffffff;
    }
    if (iVar1 < 0) {
        return 0xffffffff;
    }
    return static_cast<uint32_t>(*reinterpret_cast<uint16_t *>(param_2 + 10));
}

// 0x628e20 — observed shape
int FUN_00628e20(void *self, int param_1, int param_2, uint32_t param_3)
{
    int32_t in_ECX = static_cast<int32_t>(reinterpret_cast<intptr_t>(self));
    int32_t iVar1;
    if (param_2 == 0) {
        if (*reinterpret_cast<uint32_t *>(param_1 + 0x18) <= param_3) {
            return 0;
        }
        iVar1 = *reinterpret_cast<int32_t *>(*reinterpret_cast<int32_t *>(param_1 + 0x14) + param_3 * 4);
    } else {
        if (param_2 == 1) {
            param_2 = -param_2;
        }
        iVar1 = FUN_00628b56(reinterpret_cast<char *>(param_2), reinterpret_cast<char *>(param_1), 1);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = FUN_00625957(param_3);
        if (iVar1 == 0) {
            return 0;
        }
        return -iVar1;
    }
    iVar1 = (**reinterpret_cast<int (**)(int, int, uint32_t)>(*reinterpret_cast<int32_t *>(param_1 + 0x14) + 0x30))(
        iVar1, param_2, param_3);
    if (iVar1 < 0) {
        return iVar1;
    }
    return 0;
}
