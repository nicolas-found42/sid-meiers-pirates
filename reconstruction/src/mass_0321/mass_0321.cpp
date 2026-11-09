#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the translated listings.
// ---------------------------------------------------------------------------

extern void FUN_00661fbd(...); // receiver/calling convention unresolved
extern void FUN_00662568(...); // receiver/calling convention unresolved
extern void FUN_00615a4f(...); // receiver/calling convention unresolved
extern int FUN_0065e551(...); // receiver/calling convention unresolved
extern int FUN_0065cdca(...); // receiver/calling convention unresolved
extern int FUN_0065d00b(...); // receiver/calling convention unresolved
extern int FUN_0065e935(int* param_1, int* param_2, int param_3, int param_4);
extern void FUN_006626da(...); // receiver/calling convention unresolved
extern uint32_t FUN_0065d9d5(uint32_t param_1, int param_2, int param_3, double param_4);
extern "C" long double fsin(long double);
extern "C" long double fcos(long double);
extern "C" long double fpatan(long double, long double);
extern "C" long double _CIpow(void);
extern "C" long double _CIasin(void);
extern "C" long double _CIacos(void);
extern "C" int _finite(double);
extern uint32_t FUN_0065f0a1(uint32_t* param_1, uint32_t* param_2);
extern int FUN_0065cc1a(...); // receiver/calling convention unresolved
extern int FUN_0065cc50(...); // receiver/calling convention unresolved
extern int FUN_0065d0ff(int param_1, int param_2, int param_3, int param_4);
extern void FUN_006338c7(...); // receiver/calling convention unresolved
extern int FUN_0065e4f2(...); // receiver/calling convention unresolved
extern int FUN_006605b4(uint32_t param_1);
extern int FUN_0065ff49(uint32_t* param_1);
extern int FUN_0066040e(uint32_t* param_1);
extern int FUN_0065fb5b(uint32_t* param_1);
extern int FUN_0065da35(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern uint32_t* FUN_00533c78(...); // receiver/calling convention unresolved
extern void operator_delete(void* param_1);
extern void FUN_00614343(...); // receiver/calling convention unresolved
extern uint32_t FUN_0065cc6f(uint32_t param_1, uint32_t** param_2);
extern int FUN_00660699(uint32_t param_1, uint32_t* param_2, uint32_t param_3, uint32_t* param_4);
extern void FUN_00661d51(uint32_t param_1, void* param_2, uint32_t param_3, int param_4);
extern int FUN_0065d0b4(...); // receiver/calling convention unresolved
extern int FUN_0065ccdf(...); // receiver/calling convention unresolved
extern void FUN_0065d5bd(...); // receiver/calling convention unresolved
extern int FUN_00660e0e(uint32_t param_1, int* param_2, int* param_3);
extern int FUN_00662317();
extern int FUN_006a71d0(uint32_t param_1);
extern int FUN_0065cd09();
extern int FUN_0065deb4();
extern int FUN_006613f9(uint32_t param_1, uint32_t param_2);
extern int FUN_0066138f(uint32_t param_1, uint32_t* param_2, uint32_t param_3, uint32_t param_4);
extern uint32_t FUN_0066144c(uint32_t param_1, double* param_2, double* param_3);
extern int FUN_00661c8a(int* param_1, uint32_t param_2, uint32_t param_3);
extern int FUN_00661b07(int* param_1, uint32_t param_2, uint32_t param_3);
extern int FUN_669f61(void* self, uint32_t param_1, int param_2);
extern int FUN_00664f69(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3);
extern int FUN_0066569a(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3, int param_4);
extern int FUN_0065ea37(uint32_t* param_1, uint32_t param_2);
extern int FUN_0065d97c(void* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
extern void FUN_0066254f();
extern int FUN_00664c21();
extern int FUN_006840fd();
extern int FUN_00662bf9(int param_1, uint32_t param_2, uint32_t param_3);
extern int FUN_0065e58c();
extern int FUN_0065e79d();
extern int FUN_006634e9();
extern int FUN_00664b28();
extern int FUN_0065ccac();
extern void FUN_0065e1b9(void* param_1, int param_2, int* param_3, int param_4);
extern int FUN_0065e0f1();
extern int FUN_0065e16a();
extern int FUN_0065e132();
extern int FUN_0065cd3a();
extern int FUN_0065cd72();
extern uint8_t DAT_006c3b94;
extern uint32_t FUN_0066306d();


// 0x664b28 — observed shape
bool FUN_664b28(void* self)
{
    uint32_t uVar1;
    bool bVar2 = false;
    uint32_t uVar3;
    int iVar4;
    int iVar5;
    uint32_t* puVar6;

    FUN_00661fbd();
    uVar3 = 0;
    if (*(int*)((char*)self + 4) != 0) {
        do {
            iVar5 = *(int*)(*(int*)((char*)self + 0x10) + uVar3 * 4);
            if (((*(uint32_t*)(iVar5 + 4) & 0x400) != 0) &&
                (*(int*)(iVar5 + 0x28) == -1)) {
                *(uint32_t*)(iVar5 + 4) = *(uint32_t*)(iVar5 + 4) & 0xfffffbff;
                bVar2 = true;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)((char*)self + 4));
    }
    iVar5 = 0;
    uVar3 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar4 = *(int*)(*(int*)((char*)self + 0x14) + uVar3 * 4);
            uVar1 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                          *(int*)(iVar4 + 4) * 4) + 4);
            if (((uVar1 & 0x100) != 0) && ((uVar1 & 0x800) != 0)) {
                *(uint32_t*)(iVar4 + 0x54) = 1;
            }
            if ((*(int*)(iVar4 + 0x54) == -1) && (*(int*)(iVar4 + 0x48) == -1)) {
                *(uint32_t*)(iVar4 + 0x30) = 0xffffffff;
            }
            else {
                *(int*)(iVar4 + 0x30) = iVar5;
                iVar5 = iVar5 + 1;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)((char*)self + 8));
    }
    iVar4 = 0;
    if (iVar5 == *(int*)((char*)self + 8)) {
        bVar2 = !bVar2;
    }
    else {
        FUN_00662568();
        uVar3 = 0;
        if (*(int*)((char*)self + 8) != 0) {
            do {
                iVar5 = *(int*)(*(int*)((char*)self + 0x14) + uVar3 * 4);
                if ((*(int*)(iVar5 + 0x54) == -1) && (*(int*)(iVar5 + 0x48) == -1)) {
                    FUN_00615a4f(1);
                }
                else {
                    *(int*)(*(int*)((char*)self + 0x14) + iVar4 * 4) = iVar5;
                    iVar4 = iVar4 + 1;
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint32_t*)((char*)self + 8));
        }
        puVar6 = (uint32_t*)(*(int*)((char*)self + 0x14) + iVar4 * 4);
        for (uVar3 = *(int*)((char*)self + 8) - iVar4 & 0x3fffffff; uVar3 != 0;
             uVar3 = uVar3 - 1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
        }
        // Byte tail of the original clear loop; its count is always zero here.
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(uint8_t*)puVar6 = 0;
            puVar6 = (uint32_t*)((int)puVar6 + 1);
        }
        *(int*)((char*)self + 8) = iVar4;
        bVar2 = false;
    }
    return bVar2;
}

// 0x664c21 — observed shape
uint32_t FUN_664c21(void* self)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t* puVar6;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    FUN_00661fbd();
    uVar5 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x14) + uVar5 * 4);
            iVar3 = *(int*)(*(int*)((char*)self + 0x10) + puVar1[1] * 4);
            *puVar1 = *puVar1 & 0xffffffdf;
            uVar4 = *(uint32_t*)(iVar3 + 4);
            if (((uVar4 & 0x10) != 0) && ((uVar4 & 0x200) == 0)) {
                *puVar1 = *puVar1 | 0x20;
            }
            if ((*(uint8_t*)(iVar3 + 5) & 8) != 0) {
                *puVar1 = *puVar1 | 0x20;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint32_t*)((char*)self + 8));
    }
    local_c = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_c * 4);
            uVar5 = *puVar1 & 0xfff00000;
            if (uVar5 != 0) {
                if ((((uVar5 == 0x50100000) || (uVar5 == 0x11000000)) ||
                     (uVar5 == 0x11200000)) ||
                    ((*puVar1 & 0xf0000000) == 0x60000000)) {
                    uVar5 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                   *(int*)(puVar1[4] + uVar5 * 4) * 4);
                            *puVar2 = *puVar2 | 0x20;
                            uVar5 = uVar5 + 1;
                        } while (uVar5 < puVar1[3]);
                    }
                }
                else if (((uVar5 == 0x10f00000) || (uVar5 == 0x11100000)) ||
                         (uVar5 == 0x11400000)) {
                    uVar5 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                   *(int*)(puVar1[4] + uVar5 * 4) * 4);
                            *puVar2 = *puVar2 | 0x20;
                            uVar5 = uVar5 + 1;
                        } while (uVar5 < puVar1[3]);
                    }
                }
                else {
                    uVar5 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            iVar3 = *(int*)(*(int*)((char*)self + 0x14) +
                                            *(int*)(puVar1[4] + uVar5 * 4) * 4);
                            if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                          *(int*)(iVar3 + 4) * 4) + 5) & 0x10) != 0) &&
                                (iVar3 = FUN_0065e551(*(uint32_t*)(iVar3 + 0x14)), iVar3 != 0)) {
                                puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                       *(int*)(puVar1[4] + uVar5 * 4) * 4);
                                *puVar2 = *puVar2 | 0x20;
                            }
                            uVar5 = uVar5 + 1;
                        } while (uVar5 < puVar1[3]);
                    }
                    uVar5 = *puVar1 & 0xf0000000;
                    if ((uVar5 < 0x10000000) || (0x40000000 < uVar5)) {
                        local_10 = 0;
                        if (puVar1[1] != 0) {
                            puVar6 = (uint32_t*)puVar1[2];
                            do {
                                iVar3 = FUN_0065e551(*puVar6);
                                if (iVar3 != 0) {
                                    uVar5 = 0;
                                    if (puVar1[3] != 0) {
                                        do {
                                            puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                                   *(int*)(puVar1[4] + uVar5 * 4) * 4);
                                            *puVar2 = *puVar2 | 0x20;
                                            uVar5 = uVar5 + 1;
                                        } while (uVar5 < puVar1[3]);
                                    }
                                    break;
                                }
                                local_10 = local_10 + 1;
                                puVar6 = puVar6 + 1;
                            } while (local_10 < puVar1[1]);
                        }
                    }
                    else {
                        uVar4 = puVar1[1] / (*puVar1 & 0xfffff);
                        local_8 = 0;
                        uVar5 = puVar1[3];
                        if (uVar5 != 0) {
                            do {
                                local_10 = 0;
                                if (uVar4 != 0) {
                                    puVar6 = (uint32_t*)(puVar1[2] + local_8 * 4);
                                    do {
                                        iVar3 = FUN_0065e551(*puVar6);
                                        if (iVar3 != 0) {
                                            puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                                   *(int*)(local_8 * 4 + puVar1[4]) * 4);
                                            *puVar2 = *puVar2 | 0x20;
                                            break;
                                        }
                                        local_10 = local_10 + 1;
                                        puVar6 = puVar6 + uVar5;
                                    } while (local_10 < uVar4);
                                }
                                local_8 = local_8 + 1;
                                uVar5 = puVar1[3];
                            } while (local_8 < uVar5);
                        }
                    }
                }
            }
            local_c = local_c + 1;
        } while (local_c < *(uint32_t*)((char*)self + 0xc));
    }
    uVar5 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x14) + uVar5 * 4);
            if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) + puVar1[1] * 4) + 4) & 0x20) != 0) {
                *puVar1 = *puVar1 | 0x20;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint32_t*)((char*)self + 8));
    }
    return 0;
}

// 0x664e87 — observed shape
uint32_t FUN_664e87(void* self, int param_1, int param_2)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    iVar1 = param_1;
    if ((*(int*)(param_1 + 0x48) != -1) && (*(int*)(param_2 + 0x14) != -1)) {
        param_1 = 0;
        if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) + *(int*)(param_2 + 0x14) * 4) + 0x48) != -1) {
            param_1 = FUN_0065cdca();
        }
        iVar2 = FUN_0065d00b();
        if ((iVar2 != 0) && (param_1 == 0)) {
            *(uint32_t*)(iVar1 + 0x14) = 0xffffffff;
            *(uint32_t*)(iVar1 + 0x18) = 1;
            return 0;
        }
    }
    uVar3 = FUN_0065e935((int*)(iVar1 + 0x14), (int*)(iVar1 + 0x18),
                         *(uint32_t*)(param_2 + 0x14), *(uint32_t*)(param_2 + 0x18));
    return uVar3;
}

// 0x664f08 — observed shape
int FUN_664f08(void* self, uint32_t param_1, int param_2)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;

    puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x14) + param_1 * 4);
    puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x14) + param_2 * 4);
    puVar2[0xc] = param_1;
    iVar4 = FUN_664e87(self, (int)puVar1, (int)puVar2);
    if (-1 < iVar4) {
        uVar3 = *puVar2;
        uVar7 = *puVar1 & 0xe000000;
        uVar6 = *puVar1 & 0xf1ffffff;
        *puVar1 = uVar6;
        uVar5 = uVar3 & 0xe000000;
        if ((uVar3 & 0xe000000) < uVar7) {
            uVar5 = uVar7;
        }
        *puVar1 = uVar6 | uVar5;
        if (puVar1[0x18] == 0) {
            puVar1[0x18] = puVar2[0x18];
            puVar1[0x19] = puVar2[0x19];
        }
        iVar4 = 0;
    }
    return iVar4;
}

// 0x664f69 — observed shape
uint32_t FUN_664f69(void* self, uint32_t* param_1, uint32_t* param_2, int* param_3)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    int iVar3;
    float10 fVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t* puVar8;
    uint32_t* puVar9;
    uint32_t uVar10;
    uint32_t uVar12;
    uint32_t uVar13;
    uint32_t uVar14;
    float10 fVar15;
    double dVar16;
    int* local_10;
    int* local_8;

    iVar7 = *(int*)((char*)self + 0x14);
    uVar10 = *(uint32_t*)(*(int*)(iVar7 + (int)(intptr_t)param_3 * 4) + 0x30);
    puVar1 = *(uint32_t**)(iVar7 + (int)(intptr_t)param_2 * 4);
    puVar2 = *(uint32_t**)(iVar7 + uVar10 * 4);
    uVar14 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) + puVar1[1] * 4) + 4);
    if ((uVar14 & 1) == 0) {
        return 0;
    }
    if ((uVar14 & 0x1000) != 0) {
        return 0;
    }
    uVar14 = *puVar2;
    uVar6 = *puVar1;
    uVar12 = uVar6 & 0x40;
    uVar13 = *param_1 & 0xfff00000;
    if (uVar13 == 0x10000000) {
        *puVar1 = uVar6 | uVar14 & 0x1f;
        goto LAB_0066568e;
    }
    uVar5 = uVar14 & 0x40 | uVar6;
    *puVar1 = uVar5;
    if (((uVar6 & 0xe000000) == 0) &&
        ((((uVar13 == 0x10100000 || (uVar13 == 0x10300000)) || (uVar13 == 0x10400000)) ||
          ((uVar13 == 0x10d00000 || (uVar13 == 0x10e00000)))))) {
        *puVar1 = *puVar2 & 0xe000000 | uVar5;
    }
    uVar6 = 4;
    if (uVar13 == 0x10100000) {
        *puVar1 = *puVar1 | (uVar14 & 0x1f) >> 1 & 4 | (uVar14 & 4) << 1 | uVar14 & 0x13;
    }
    else {
        if (uVar13 == 0x10300000) {
            if (((uVar14 & 4) == 0) || ((uVar14 & 8) == 0)) {
                uVar6 = uVar14 & 0xc;
            }
        }
        else if (((uVar13 != 0x10400000) && (uVar13 != 0x10500000)) &&
                 (uVar13 != 0x10700000))
            goto LAB_0066508a;
        *puVar1 = *puVar1 | uVar6;
    }
LAB_0066508a:
    uVar6 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) + puVar2[1] * 4) + 4);
    if (((uVar6 & 0x100) == 0) || (puVar2[2] != 0xffffffff)) {
        if ((((uVar14 & 1) == 0) || (uVar13 != 0x10400000)) &&
            (((uVar14 & 2) == 0 || (uVar13 != 0x10400000)))) {
            if ((uVar14 & 8) != 0) {
                if (uVar13 == 0x10600000) {
                    if (uVar12 != 0) {
                        return 0;
                    }
                    if ((uVar14 & 4) == 0) {
                        FUN_006626da();
                        return 0;
                    }
                    return 0;
                }
                if (uVar13 == 0x10700000) {
                    if (uVar12 != 0) {
                        return 0;
                    }
                    FUN_006626da();
                    dVar16 = 0.0;
                    goto LAB_00665684;
                }
            }
            if (((uVar6 & 0x200) == 0) || ((uVar13 != 0x10d00000 && (uVar13 != 0x10e00000)))) {
                if (uVar12 != 0) {
                    return 0;
                }
                if ((uVar6 & 2) == 0) {
                    return 0;
                }
                if (((((uVar13 != 0x10100000) ||
                       (puVar8 = *(uint32_t**)(*(int*)((char*)self + 0x18) + puVar2[0x12] * 4),
                        (*puVar8 & 0xfff00000) != 0x10100000)) &&
                      ((uVar13 != 0x10300000 ||
                        (puVar8 = *(uint32_t**)(*(int*)((char*)self + 0x18) + puVar2[0x12] * 4),
                         (*puVar8 & 0xfff00000) != 0x10300000)))) &&
                     ((uVar13 != 0x10500000 ||
                       (puVar8 = *(uint32_t**)(*(int*)((char*)self + 0x18) + puVar2[0x12] * 4),
                        (*puVar8 & 0xfff00000) != 0x10600000)))) &&
                    ((uVar13 != 0x10600000 ||
                      (puVar8 = *(uint32_t**)(*(int*)((char*)self + 0x18) + puVar2[0x12] * 4),
                       (*puVar8 & 0xfff00000) != 0x10500000)))) {
LAB_0066546f:
                    if ((uVar13 == 0x10300000) &&
                        (puVar8 = *(uint32_t**)(*(int*)((char*)self + 0x18) + puVar2[0x12] * 4),
                         (*puVar8 & 0xfff00000) == 0x20500000)) {
                        uVar14 = 0;
                        if (puVar8[3] != 0) {
                            puVar9 = (uint32_t*)puVar8[4];
                            do {
                                if (*puVar9 == uVar10) break;
                                uVar14 = uVar14 + 1;
                                puVar9 = puVar9 + 1;
                            } while (uVar14 < puVar8[3]);
                        }
                        uVar6 = puVar8[3];
                        param_2 = (uint32_t*)0x0;
                        local_8 = (int*)(puVar8[2] + uVar14 * 4);
                        local_10 = (int*)(puVar8[2] + (uVar6 + uVar14) * 4);
                        do {
                            iVar7 = *local_8;
                            iVar3 = *(int*)(*(int*)((char*)self + 0x14) + iVar7 * 4);
                            if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                          *(int*)(iVar3 + 4) * 4) + 4) & 2) != 0) &&
                                (puVar8 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                        *(int*)(iVar3 + 0x48) * 4),
                                 (*puVar8 & 0xfff00000) == 0x10700000)) {
                                param_1 = (uint32_t*)0x0;
                                if (puVar8[3] != 0) {
                                    int* piVar11 = (int*)puVar8[4];
                                    do {
                                        if (*piVar11 == iVar7) break;
                                        param_1 = (uint32_t*)((int)(intptr_t)param_1 + 1);
                                        piVar11 = piVar11 + 1;
                                    } while (param_1 < puVar8[3]);
                                }
                                if (*(int*)(puVar8[2] + (int)(intptr_t)param_1 * 4) == *local_10) {
                                    puVar1[0xc] = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                     iVar7 * 4) + 0x30);
                                    return 0;
                                }
                            }
                            local_8 = local_8 + uVar6;
                            param_2 = (uint32_t*)((int)(intptr_t)param_2 + 1);
                            local_10 = local_10 + -uVar6;
                        } while (param_2 < 2);
                    }
                    if (uVar13 != 0x10500000) {
                        return 0;
                    }
                    puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x18) + puVar2[0x12] * 4);
                    if ((*puVar2 & 0xfff00000) != 0x20500000) {
                        return 0;
                    }
                    uVar14 = puVar2[3];
                    param_1 = (uint32_t*)0x0;
                    if (uVar14 != 0) {
                        param_2 = (uint32_t*)puVar2[4];
                        do {
                            if (*param_2 == uVar10) break;
                            param_1 = (uint32_t*)((int)(intptr_t)param_1 + 1);
                            param_2 = param_2 + 1;
                        } while (param_1 < uVar14);
                    }
                    param_2 = (uint32_t*)0x0;
                    iVar7 = *(int*)((char*)self + 0x14);
                    param_3 = (int*)(puVar2[2] + (int)(intptr_t)param_1 * 4);
                    do {
                        iVar3 = *(int*)(iVar7 + *param_3 * 4);
                        if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                      *(int*)(iVar3 + 4) * 4) + 4) & 2) != 0) &&
                            (puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                    *(int*)(iVar3 + 0x48) * 4),
                             (*puVar2 & 0xfff00000) == 0x10600000)) {
                            param_1 = (uint32_t*)0x0;
                            if (puVar2[3] != 0) {
                                int* piVar11 = (int*)puVar2[4];
                                do {
                                    if (*piVar11 == *param_3) break;
                                    param_1 = (uint32_t*)((int)(intptr_t)param_1 + 1);
                                    piVar11 = piVar11 + 1;
                                } while (param_1 < puVar2[3]);
                            }
                            iVar7 = *(int*)((char*)self + 0x14);
                            uVar10 = **(uint32_t**)(iVar7 +
                                                    *(int*)(puVar2[2] + (int)(intptr_t)param_1 * 4) * 4);
                            if (((uVar10 & 4) != 0) && ((uVar10 & 8) != 0)) goto LAB_00665679;
                        }
                        param_3 = param_3 + uVar14;
                        param_2 = (uint32_t*)((int)(intptr_t)param_2 + 1);
                        if (1 < param_2) {
                            return 0;
                        }
                    } while (true);
                }
                param_1 = (uint32_t*)0x0;
                if (puVar8[3] != 0) {
                    puVar9 = (uint32_t*)puVar8[4];
                    do {
                        if (*puVar9 == uVar10) break;
                        param_1 = (uint32_t*)((int)(intptr_t)param_1 + 1);
                        puVar9 = puVar9 + 1;
                    } while (param_1 < puVar8[3]);
                }
                if (puVar8[3] <= param_1) goto LAB_0066546f;
                uVar10 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                               *(int*)(puVar8[2] + (int)(intptr_t)param_1 * 4) * 4) + 0x30);
                goto LAB_0066568e;
            }
        }
LAB_00665679:
        dVar16 = 0.0;
    }
    else {
        if (uVar13 < 0x10800001) {
            if (uVar13 == 0x10800000) {
                fVar15 = (float10)fsin((float10)*(double*)(puVar2 + 8));
            }
            else if (uVar13 == 0x10100000) {
                fVar15 = -(float10)*(double*)(puVar2 + 8);
            }
            else if (uVar13 == 0x10300000) {
                if ((uVar12 == 0) && (*(double*)(puVar2 + 8) == 0.0)) {
LAB_006652c4:
                    fVar15 = (float10)0;
                }
                else {
                    fVar15 = (float10)1 / (float10)*(double*)(puVar2 + 8);
                }
            }
            else if (uVar13 == 0x10400000) {
                iVar7 = _finite(*(double*)(puVar2 + 8));
                if (iVar7 == 0) goto LAB_006652c4;
                dVar16 = floor(*(double*)(puVar2 + 8));
                fVar15 = (float10)*(double*)(puVar2 + 8) - (float10)dVar16;
            }
            else if (uVar13 == 0x10500000) {
                fVar15 = (float10)_CIpow();
            }
            else if (uVar13 == 0x10600000) {
                if ((uVar12 == 0) && (*(double*)(puVar2 + 8) == 0.0)) {
                    return 0;
                }
                if (*(double*)(puVar2 + 8) < 0.0) goto LAB_006652b5;
                fVar15 = (float10)log2((float10)*(double*)(puVar2 + 8));
                fVar4 = (float10)log2((float10)2.0);
                fVar15 = ((float10)0.6931471805599453 * fVar15) /
                         ((float10)0.6931471805599453 * fVar4);
            }
            else {
                if (uVar13 != 0x10700000) {
                    return 0;
                }
                if ((uVar12 == 0) && (*(double*)(puVar2 + 8) < 0.0)) {
LAB_006652b5:
                    FUN_006626da();
                    goto LAB_006652c4;
                }
                fVar15 = (float10)1.0 / SQRT((float10)*(double*)(puVar2 + 8));
            }
        }
        else if (uVar13 == 0x10900000) {
            fVar15 = (float10)fcos((float10)*(double*)(puVar2 + 8));
        }
        else if (uVar13 == 0x10a00000) {
            if ((uVar12 == 0) &&
                ((*(double*)(puVar2 + 8) < -1.0 || (1.0 < *(double*)(puVar2 + 8)))))
                goto LAB_006652b5;
            fVar15 = (float10)_CIasin();
        }
        else if (uVar13 == 0x10b00000) {
            if ((uVar12 == 0) &&
                ((*(double*)(puVar2 + 8) < -1.0 || (1.0 < *(double*)(puVar2 + 8)))))
                goto LAB_006652b5;
            fVar15 = (float10)_CIacos();
        }
        else {
            if (uVar13 != 0x10c00000) {
                if ((uVar13 != 0x10d00000) && (uVar13 != 0x10e00000)) {
                    return 0;
                }
                goto LAB_006652c4;
            }
            fVar15 = (float10)fpatan((float10)*(double*)(puVar2 + 8), (float10)1);
        }
        dVar16 = (double)fVar15;
    }
LAB_00665684:
    uVar10 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78), 0, 0, dVar16);
LAB_0066568e:
    puVar1[0xc] = uVar10;
    return 0;
}

// ---------------------------------------------------------------------------
// x87 / CRT helpers used by the translated listings below.
// ---------------------------------------------------------------------------
using float10 = long double;

// 0x66569a — observed shape
uint32_t FUN_66569a(void* self, uint32_t* param_1, int param_2, int param_3, uint32_t param_4)
{
    uint32_t** ppuVar1;
    bool bVar2;
    uint32_t uVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    int* piVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    int iVar9;
    int iVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    uint32_t* puVar13;
    uint32_t uVar14;
    uint32_t uVar15;
    bool bVar16;
    uint16_t uVar17;
    float10 fVar18;
    float10 fVar19;
    uint32_t uVar20;
    double dVar21;
    double uVar22;
    uint32_t local_50_hi = 0;
    union {
        uint32_t* p[5];
        uint32_t u[5];
    } local_48;
    uint32_t local_pair[2];
    uint32_t* local_34 = nullptr;
    uint32_t* local_30 = nullptr;
    uint32_t* local_2c;
    uint32_t local_28;
    int local_24;
    uint32_t* local_20;
    int local_1c;
    uint32_t* local_18;
    uint32_t* local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    local_2c = (uint32_t*)*param_1;
    iVar9 = *(int*)((char*)self + 0x14);
    puVar8 = (uint32_t*)(uintptr_t)*(int*)(iVar9 + param_3 * 4);
    puVar4 = (uint32_t*)(uintptr_t)*(int*)(iVar9 + (int)param_4 * 4);
    puVar13 = *(uint32_t**)(iVar9 + param_2 * 4);
    local_20 = *(uint32_t**)(iVar9 + (int)(intptr_t)puVar8 * 4);
    local_18 = *(uint32_t**)(iVar9 + (int)(intptr_t)puVar4 * 4);
    uVar11 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) + puVar13[1] * 4) + 4);
    if ((uVar11 & 1) == 0) {
        return 0;
    }
    if ((uVar11 & 0x1000) != 0) {
        return 0;
    }
    uVar11 = *local_20;
    uVar15 = *local_18;
    local_8 = uVar11 & 0x1f;
    local_c = uVar15 & 0x1f;
    uVar3 = *puVar13;
    local_28 = uVar3 & 0x40;
    if (((uVar3 & 0xe000000) == 0) &&
        (((((uVar14 = (uint32_t)(uintptr_t)local_2c & 0xfff00000, uVar14 == 0x20000000) ||
            (uVar14 == 0x20100000)) ||
           (uVar14 == 0x20400000)) ||
          ((uVar14 == 0x20700000 || (uVar14 == 0x20800000)))) ||
         (uVar14 == 0x20900000))) {
        uVar12 = uVar15 | uVar11;
        uVar14 = 0x8000000;
        if ((((uVar12 & 0x8000000) != 0) ||
             (uVar14 = 0x4000000, (uVar12 & 0x4000000) != 0)) ||
            (uVar14 = 0x2000000, (uVar12 & 0x2000000) != 0)) {
            *puVar13 = uVar3 | uVar14;
        }
    }
    if (((*local_18 | *local_20) & 0x40) != 0) {
        uVar3 = (uint32_t)(uintptr_t)local_2c & 0xfff00000;
        if (uVar3 < 0x20600001) {
            if ((((uVar3 == 0x20600000) || (uVar3 == 0x20000000)) || (uVar3 == 0x20100000)) ||
                ((uVar3 == 0x20400000 || (uVar3 == 0x20500000)))) goto LAB_006657d9;
        }
        else if ((uVar3 == 0x20700000) || ((uVar3 == 0x20800000 || (uVar3 == 0x20900000)))) {
LAB_006657d9:
            *puVar13 = *puVar13 | 0x40;
        }
    }
    local_10 = (uint32_t)(uintptr_t)local_2c & 0xfff00000;
    if (local_10 < 0x20400001) {
        if (local_10 == 0x20400000) {
            uVar3 = local_c & local_8 & 0xe;
        }
        else if (local_10 == 0x20000000) {
            uVar3 = (local_8 | 8) & local_c | uVar11 & 8;
        }
        else {
            if (local_10 != 0x20100000) {
                if ((local_10 == 0x20200000) || (local_10 == 0x20300000)) {
                    *puVar13 = *puVar13 | 0x17;
                }
                goto LAB_0066596c;
            }
            uVar3 = (local_8 | 4) & local_c | uVar11 & 4;
        }
LAB_0066586a:
        *puVar13 = *puVar13 | uVar3;
    }
    else if (local_10 == 0x20500000) {
        *puVar13 = *puVar13 | local_c & local_8 & 3;
        local_48.p[4] = (uint32_t*)(uintptr_t)(uVar11 & 4);
        if (((local_48.p[4] != (uint32_t*)0x0) && ((uVar15 & 4) != 0)) ||
            (((uVar11 & 8) != 0 && ((uVar15 & 8) != 0)))) {
            *puVar13 = *puVar13 | 4;
        }
        if (((local_48.p[4] != (uint32_t*)0x0) && ((uVar15 & 8) != 0)) ||
            (((uVar11 & 8) != 0 && ((uVar15 & 4) != 0)))) {
            *puVar13 = *puVar13 | 8;
        }
        if (local_20 == local_18) {
            *puVar13 = *puVar13 | 4;
        }
        else if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) + local_20[1] * 4) + 4) & 2) == 0) ||
                 (puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_20[0x12] * 4),
                  (*puVar5 & 0xfff00000) != 0x10100000)) {
            if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) + local_18[1] * 4) + 4) & 2) != 0) &&
                ((puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_18[0x12] * 4),
                  (*puVar5 & 0xfff00000) == 0x10100000 && (uVar3 = 0, puVar5[3] != 0)))) {
                puVar7 = (uint32_t*)puVar5[4];
                do {
                    if ((uint32_t*)(uintptr_t)*puVar7 == puVar4) break;
                    uVar3 = uVar3 + 1;
                    puVar7 = puVar7 + 1;
                } while (uVar3 < puVar5[3]);
                if (uVar3 < puVar5[3]) {
                    bVar16 = (uint32_t*)(uintptr_t)*(uint32_t*)(puVar5[2] + uVar3 * 4) == puVar8;
                    goto LAB_00665967;
                }
            }
        }
        else {
            uVar3 = 0;
            if (puVar5[3] != 0) {
                puVar7 = (uint32_t*)puVar5[4];
                do {
                    if ((uint32_t*)(uintptr_t)*puVar7 == puVar8) break;
                    uVar3 = uVar3 + 1;
                    puVar7 = puVar7 + 1;
                } while (uVar3 < puVar5[3]);
                if (uVar3 < puVar5[3]) {
                    bVar16 = (uint32_t*)(uintptr_t)*(uint32_t*)(puVar5[2] + uVar3 * 4) == puVar4;
LAB_00665967:
                    if (bVar16) {
                        *puVar13 = *puVar13 | 8;
                    }
                }
            }
        }
    }
    else if (((local_10 == 0x20700000) || (local_10 == 0x20800000)) ||
             (local_10 == 0x20900000)) {
        uVar3 = local_c & local_8;
        goto LAB_0066586a;
    }
LAB_0066596c:
    local_14 = puVar13;
    if (local_28 != 0) goto LAB_006659e8;
    if (((uVar11 & 4) != 0) && ((uVar15 & 8) != 0)) {
        if (local_10 == 0x20000000) goto LAB_006660ff;
        if (local_10 == 0x20100000) goto LAB_006659ba;
        if (local_10 == 0x20200000) {
            dVar21 = 0.0;
        }
        else {
            if (local_10 != 0x20300000) goto LAB_006659ca;
            dVar21 = 1.0;
        }
LAB_006659a7:
        puVar4 = (uint32_t*)(uintptr_t)FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78), 0, 0, dVar21);
LAB_006660ff:
        puVar13[0xc] = (uint32_t)(uintptr_t)puVar4;
        return 0;
    }
LAB_006659ca:
    if (((uVar11 & 8) != 0) && ((uVar15 & 4) != 0)) {
        if (local_10 != 0x20000000) {
            if (local_10 == 0x20100000) goto LAB_006660ff;
            goto LAB_006659e8;
        }
LAB_006659ba:
        puVar4 = puVar8;
        goto LAB_006660ff;
    }
LAB_006659e8:
    local_24 = *(int*)((char*)self + 0x10);
    local_48.p[4] = (uint32_t*)(uintptr_t)*(uint32_t*)(*(int*)(local_24 + local_20[1] * 4) + 4);
    uVar3 = (uint32_t)(uintptr_t)local_48.p[4] & 0x100;
    if ((((uVar3 != 0) && (local_20[2] == 0xffffffff)) &&
         ((*(uint32_t*)(*(int*)(local_24 + local_18[1] * 4) + 4) & 0x100) != 0)) &&
        (local_18[2] == 0xffffffff)) {
        fVar18 = (float10)*(double*)(local_20 + 8);
        dVar21 = *(double*)(local_18 + 8);
        if (local_10 == 0x20000000) {
            if ((float10)dVar21 <= fVar18) {
LAB_00665ac8:
                fVar18 = (float10)dVar21;
            }
        }
        else {
            if (local_10 != 0x20100000) {
                if (local_10 == 0x20200000) {
                    if (fVar18 < (float10)dVar21) goto LAB_00665ccb;
                }
                else {
                    if (local_10 != 0x20300000) {
                        if (local_10 == 0x20400000) {
                            fVar18 = fVar18 + (float10)dVar21;
                        }
                        else if (local_10 == 0x20500000) {
                            fVar18 = fVar18 * (float10)dVar21;
                        }
                        else {
                            if (local_10 != 0x20600000) {
                                return 0;
                            }
                            fVar18 = (float10)fpatan(fVar18, (float10)dVar21);
                        }
                        goto LAB_00665acd;
                    }
                    if ((float10)dVar21 <= fVar18) goto LAB_00665ccb;
                }
                goto LAB_00665b9f;
            }
            if (fVar18 < (float10)dVar21) goto LAB_00665ac8;
        }
        goto LAB_00665acd;
    }
    if ((local_28 == 0) &&
        (((uVar3 != 0 && (local_20[2] == 0xffffffff)) ||
          (((*(uint32_t*)(*(int*)(local_24 + local_18[1] * 4) + 4) & 0x100) != 0 &&
            (local_18[2] == 0xffffffff)))))) {
        if ((uVar3 == 0) || (local_20[2] != 0xffffffff)) {
            dVar21 = *(double*)(local_18 + 8);
            uVar11 = local_8;
            puVar5 = puVar8;
        }
        else {
            dVar21 = *(double*)(local_20 + 8);
            uVar11 = local_c;
            puVar5 = puVar4;
        }
        fVar18 = (float10)dVar21;
        if (local_10 == 0x20000000) {
            if (((float10)1.0 <= fVar18) && ((uVar11 & 1) != 0)) goto LAB_00665de7;
            fVar19 = (float10)0.0;
            if ((isnan(fVar18) || isnan(fVar19)) || fVar18 < fVar19 == (fVar18 == fVar19)) {
                return 0;
            }
            if ((uVar11 & 4) == 0) {
                return 0;
            }
        }
        else {
            if (local_10 != 0x20100000) {
                if (local_10 == 0x20200000) {
                    fVar19 = (float10)0.0;
                    if (puVar5 == puVar4) {
                        if ((fVar18 < fVar19) && ((uVar11 & 4) != 0)) goto LAB_00665ccb;
                        if (((fVar18 < (float10)0.0) || ((uVar11 & 8) == 0)) &&
                            ((fVar18 < (float10)1.0 || ((uVar11 & 1) == 0)))) {
                            fVar19 = (float10)0.0;
LAB_00665cfc:
                            if (fVar18 != fVar19) {
                                return 0;
                            }
                            uVar11 = uVar11 & 1;
                            goto LAB_00665d10;
                        }
                    }
                    else if (((isnan(fVar18) || isnan(fVar19)) ||
                              fVar18 < fVar19 == (fVar18 == fVar19)) ||
                             ((uVar11 & 4) == 0)) {
                        if ((fVar18 <= (float10)0.0) || ((uVar11 & 8) == 0)) {
                            uVar17 = (uint16_t)(fVar18 < (float10)1.0) << 8 |
                                     (uint16_t)(fVar18 == (float10)1.0) << 0xe;
LAB_00665d90:
                            if (uVar17 != 0) {
                                return 0;
                            }
                            if ((uVar11 & 1) == 0) {
                                return 0;
                            }
                        }
LAB_00665ccb:
                        fVar18 = (float10)1;
                        goto LAB_00665acd;
                    }
LAB_00665b9f:
                    fVar18 = (float10)0;
                    goto LAB_00665acd;
                }
                if (local_10 == 0x20300000) {
                    fVar19 = (float10)0.0;
                    if (puVar5 == puVar4) {
                        if ((fVar18 >= fVar19) || ((uVar11 & 4) == 0)) {
                            if ((fVar18 < (float10)0.0) || ((uVar11 & 8) == 0)) {
                                uVar17 = (uint16_t)(fVar18 < (float10)1.0) << 8;
                                goto LAB_00665d90;
                            }
                            goto LAB_00665ccb;
                        }
                    }
                    else {
                        if (((!isnan(fVar18) && !isnan(fVar19)) &&
                             fVar18 < fVar19 != (fVar18 == fVar19)) &&
                            ((uVar11 & 4) != 0)) goto LAB_00665ccb;
                        if (((fVar18 <= (float10)0.0) || ((uVar11 & 8) == 0)) &&
                            ((fVar18 <= (float10)1.0 || ((uVar11 & 1) == 0)))) {
                            fVar19 = (float10)1.0;
                            goto LAB_00665cfc;
                        }
                    }
                    goto LAB_00665b9f;
                }
                if (local_10 == 0x20400000) {
                    if (fVar18 != (float10)0.0) {
                        return 0;
                    }
                    goto LAB_00665de7;
                }
                if (local_10 != 0x20500000) {
                    if (local_10 != 0x20600000) {
                        return 0;
                    }
                    if (fVar18 != (float10)0.0) {
                        return 0;
                    }
                    if (puVar5 != puVar8) {
                        return 0;
                    }
                    goto LAB_00665b9f;
                }
                if (fVar18 == (float10)0.0) goto LAB_00665b9f;
                if (fVar18 == (float10)1.0) goto LAB_00665de7;
                if (fVar18 != (float10)0.5) {
                    return 0;
                }
                iVar9 = *(int*)((char*)self + 0x14);
                iVar10 = *(int*)(iVar9 + (int)(intptr_t)puVar5 * 4);
                if ((*(uint8_t*)(*(int*)(local_24 + *(int*)(iVar10 + 4) * 4) + 4) & 2) == 0) {
                    return 0;
                }
                puVar8 = *(uint32_t**)(*(int*)((char*)self + 0x18) + *(int*)(iVar10 + 0x48) * 4);
                if ((*puVar8 & 0xfff00000) != 0x20400000) {
                    return 0;
                }
                uVar11 = puVar8[3];
                uVar15 = 0;
                if (uVar11 != 0) {
                    puVar4 = (uint32_t*)puVar8[4];
                    do {
                        if ((uint32_t*)(uintptr_t)*puVar4 == puVar5) break;
                        uVar15 = uVar15 + 1;
                        puVar4 = puVar4 + 1;
                    } while (uVar15 < uVar11);
                }
                if (uVar11 <= uVar15) {
                    return 0;
                }
                uVar3 = puVar8[2];
                if (*(int*)(uVar3 + uVar15 * 4) != *(int*)(uVar3 + (uVar11 + uVar15) * 4)) {
                    return 0;
                }
                iVar10 = *(int*)(uVar15 * 4 + uVar3);
LAB_00665c5b:
                puVar4 = (uint32_t*)(uintptr_t)*(int*)(*(int*)(iVar9 + iVar10 * 4) + 0x30);
                goto LAB_00666608;
            }
            if ((fVar18 < (float10)1.0) || ((uVar11 & 1) == 0)) {
                fVar19 = (float10)0.0;
                if ((isnan(fVar18) || isnan(fVar19)) || fVar18 < fVar19 == (fVar18 == fVar19)) {
                    return 0;
                }
                uVar11 = uVar11 & 4;
LAB_00665d10:
                if (uVar11 == 0) {
                    return 0;
                }
LAB_00665de7:
                puVar13[0xc] = (uint32_t)(uintptr_t)puVar5;
                return 0;
            }
        }
LAB_00665acd:
        dVar21 = (double)fVar18;
        goto LAB_006659a7;
    }
    if (local_20 == local_18) {
        if ((local_10 != 0x20000000) && (local_10 != 0x20100000)) {
            if (local_10 == 0x20200000) {
                if (local_28 != 0) {
                    return 0;
                }
LAB_00665f0a:
                dVar21 = 0.0;
                goto LAB_006659a7;
            }
            if (local_10 == 0x20300000) {
                if (local_28 != 0) {
                    return 0;
                }
                dVar21 = 1.0;
                goto LAB_006659a7;
            }
            if ((local_10 != 0x20500000) || ((uVar11 & 1) == 0)) goto LAB_00665e59;
        }
        goto LAB_006659ba;
    }
LAB_00665e59:
    uVar11 = 0;
    if (local_28 != 0) {
        return 0;
    }
    uVar3 = 0;
    if (local_10 == 0x20400000) {
        if ((((*(uint8_t*)(*(int*)(local_24 + local_18[1] * 4) + 4) & 2) != 0) &&
             (puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_18[0x12] * 4),
              (*puVar5 & 0xfff00000) == 0x10100000)) && (puVar5[3] != 0)) {
            puVar7 = (uint32_t*)puVar5[4];
            do {
                if ((uint32_t*)(uintptr_t)*puVar7 == puVar4) break;
                uVar11 = uVar11 + 1;
                puVar7 = puVar7 + 1;
            } while (uVar11 < puVar5[3]);
            if ((uVar11 < puVar5[3]) &&
                (puVar8 == (uint32_t*)(uintptr_t)*(uint32_t*)(puVar5[2] + uVar11 * 4)))
                goto LAB_00665f0a;
        }
        if ((((uint32_t)(uintptr_t)local_48.p[4] & 2) != 0) &&
            ((puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_20[0x12] * 4),
              (*puVar5 & 0xfff00000) == 0x10100000 && (uVar11 = 0, puVar5[3] != 0)))) {
            puVar7 = (uint32_t*)puVar5[4];
            do {
                if ((uint32_t*)(uintptr_t)*puVar7 == puVar8) break;
                uVar11 = uVar11 + 1;
                puVar7 = puVar7 + 1;
            } while (uVar11 < puVar5[3]);
            if ((uVar11 < puVar5[3]) &&
                (puVar4 == (uint32_t*)(uintptr_t)*(uint32_t*)(puVar5[2] + uVar11 * 4)))
                goto LAB_00665f0a;
        }
        local_8 = 0;
        local_28 = 0;
        do {
            if ((local_8 & 4) == 0) {
                local_2c = puVar4;
                local_30 = puVar8;
            }
            else {
                local_2c = puVar8;
                local_30 = puVar4;
            }
            local_48.p[1] = (uint32_t*)(uintptr_t)(local_8 & 2);
            if (local_48.p[1] == (uint32_t*)0x0) {
LAB_00665fd1:
                iVar9 = *(int*)(*(int*)((char*)self + 0x14) + (int)(intptr_t)local_30 * 4);
                if (((*(uint8_t*)(*(int*)(local_24 + *(int*)(iVar9 + 4) * 4) + 4) & 2) != 0) &&
                    (puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                            *(int*)(iVar9 + 0x48) * 4),
                     (*puVar5 & 0xfff00000) == 0x20400000)) {
                    uVar11 = puVar5[3];
                    uVar3 = 0;
                    if (uVar11 != 0) {
                        puVar7 = (uint32_t*)puVar5[4];
                        do {
                            if (local_30 == (uint32_t*)(uintptr_t)*puVar7) {
                                uVar14 = puVar5[2];
                                if ((local_8 & 1) == 0) {
                                    iVar9 = *(int*)(uVar14 + (uVar3 + uVar11) * 4);
                                }
                                else {
                                    iVar9 = *(int*)(uVar14 + uVar3 * 4);
                                    uVar3 = uVar3 + uVar11;
                                }
                                local_48.p[4] = (uint32_t*)(uintptr_t)
                                    *(int*)(*(int*)((char*)self + 0x14) + iVar9 * 4);
                                local_50_hi = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                             *(int*)(uVar14 + uVar3 * 4) * 4) + 0x30);
                                break;
                            }
                            uVar3 = uVar3 + 1;
                            puVar7 = puVar7 + 1;
                        } while (uVar3 < uVar11);
                    }
                    if (local_48.p[1] == (uint32_t*)0x0) {
                        iVar9 = *(int*)(*(int*)((char*)self + 0x14) +
                                        (int)(intptr_t)local_48.p[4] * 4);
                        if (((*(uint8_t*)(*(int*)(local_24 + *(int*)(iVar9 + 4) * 4) + 4) & 2) == 0) ||
                            (puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                    *(int*)(iVar9 + 0x48) * 4),
                             (*puVar5 & 0xfff00000) != 0x10100000)) goto LAB_006660c2;
                        uVar11 = 0;
                        if (puVar5[3] != 0) {
                            puVar7 = (uint32_t*)puVar5[4];
                            do {
                                if (local_48.p[4] == (uint32_t*)(uintptr_t)*puVar7) {
                                    local_48.p[4] = (uint32_t*)(uintptr_t)
                                        *(int*)(*(int*)((char*)self + 0x14) +
                                                *(int*)(puVar5[2] + uVar11 * 4) * 4);
                                    break;
                                }
                                uVar11 = uVar11 + 1;
                                puVar7 = puVar7 + 1;
                            } while (uVar11 < puVar5[3]);
                        }
                    }
                    if (local_2c == local_48.p[4]) {
                        puVar4 = (uint32_t*)(uintptr_t)local_50_hi;
                        goto LAB_006660ff;
                    }
                }
            }
            else {
                iVar9 = *(int*)(*(int*)((char*)self + 0x14) + (int)(intptr_t)local_2c * 4);
                if (((*(uint8_t*)(*(int*)(local_24 + *(int*)(iVar9 + 4) * 4) + 4) & 2) != 0) &&
                    (puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                            *(int*)(iVar9 + 0x48) * 4),
                     (*puVar5 & 0xfff00000) == 0x10100000)) {
                    local_28 = 0;
                    if (puVar5[3] != 0) {
                        puVar7 = (uint32_t*)puVar5[4];
                        do {
                            if (local_2c == (uint32_t*)(uintptr_t)*puVar7) {
                                local_2c = (uint32_t*)(uintptr_t)
                                    *(int*)(*(int*)((char*)self + 0x14) +
                                            *(int*)(puVar5[2] + local_28 * 4) * 4);
                                break;
                            }
                            local_28 = local_28 + 1;
                            puVar7 = puVar7 + 1;
                            local_48.p[3] = puVar7;
                        } while (local_28 < puVar5[3]);
                    }
                    goto LAB_00665fd1;
                }
            }
LAB_006660c2:
            local_8 = local_8 + 1;
            uVar3 = local_28;
        } while (local_8 < 8);
    }
    local_28 = uVar3;
    if (local_10 == 0x20500000) {
        uVar11 = 0;
        local_48.p[0] = puVar8;
        local_48.p[1] = puVar4;
        local_pair[0] = 0;
        local_pair[1] = 0;
        local_48.p[3] = (uint32_t*)0x0;
        local_48.p[2] = (uint32_t*)0x0;
        do {
            iVar9 = (int)local_48.u[uVar11 / 4];
            while (iVar10 = *(int*)(*(int*)((char*)self + 0x14) + iVar9 * 4),
                   (*(uint8_t*)(*(int*)(local_24 + *(int*)(iVar10 + 4) * 4) + 4) & 2) != 0) {
                puVar13 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                        *(int*)(iVar10 + 0x48) * 4);
                uint32_t* pair;
                if ((*puVar13 & 0xfff00000) == 0x10100000) {
                    pair = local_pair;
                }
                else {
                    if ((*puVar13 & 0xfff00000) != 0x10300000) break;
                    pair = &local_48.u[2];
                }
                *(uint32_t*)((char*)pair + uVar11) =
                    (uint32_t)(*(uint32_t*)((char*)pair + uVar11) == 0);
                local_48.p[4] = (uint32_t*)(uintptr_t)puVar13[3];
                puVar5 = (uint32_t*)0x0;
                if (local_48.p[4] != (uint32_t*)0x0) {
                    piVar6 = (int*)puVar13[4];
                    do {
                        if (*piVar6 == iVar9) {
                            iVar9 = *(int*)(puVar13[2] + (int)(intptr_t)puVar5 * 4);
                            break;
                        }
                        puVar5 = (uint32_t*)((int)(intptr_t)puVar5 + 1);
                        piVar6 = piVar6 + 1;
                    } while (puVar5 < local_48.p[4]);
                }
                if (local_48.p[4] <= puVar5) {
                    return 0x80004005;
                }
            }
            local_48.u[uVar11 / 4] = (uint32_t)iVar9;
            uVar11 = uVar11 + 4;
        } while (uVar11 < 8);
        if ((local_48.p[0] != local_48.p[1]) || (local_48.p[2] == local_48.p[3]))
            goto LAB_006661cd;
        if (local_pair[0] == (uint32_t)(uintptr_t)local_30) {
            uVar22 = 1.0;
        }
        else {
            uVar22 = -1.0;
        }
        uVar20 = *(uint32_t*)((char*)self + 0x78);
    }
    else {
LAB_006661cd:
        if ((((local_10 == 0x20200000) &&
              (iVar9 = *(int*)(*(int*)((char*)self + 0x14) + (int)(intptr_t)puVar8 * 4),
               (*(uint8_t*)(*(int*)(local_24 + *(int*)(iVar9 + 4) * 4) + 4) & 2) != 0)) &&
             ((uVar15 & 1) != 0)) &&
            (puVar13 = *(uint32_t**)(*(int*)((char*)self + 0x18) + *(int*)(iVar9 + 0x48) * 4),
             (*puVar13 & 0xfff00000) == 0x10100000)) {
            uVar11 = 0;
            if (puVar13[3] != 0) {
                puVar5 = (uint32_t*)puVar13[4];
                do {
                    if ((uint32_t*)(uintptr_t)*puVar5 == puVar8) break;
                    uVar11 = uVar11 + 1;
                    puVar5 = puVar5 + 1;
                } while (uVar11 < puVar13[3]);
            }
            if ((uint32_t*)(uintptr_t)*(uint32_t*)(puVar13[2] + uVar11 * 4) == puVar4)
                goto LAB_00666608;
        }
        iVar9 = *(int*)(*(int*)((char*)self + 0x14) + (int)(intptr_t)puVar8 * 4);
        if ((*(uint8_t*)(*(int*)(local_24 + *(int*)(iVar9 + 4) * 4) + 4) & 2) == 0) {
            return 0;
        }
        if ((*(uint8_t*)(*(int*)(local_24 +
                                 *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                               (int)(intptr_t)puVar4 * 4) + 4) * 4) + 4) & 2) == 0) {
            return 0;
        }
        if (((local_10 == 0x20500000) || (local_10 == 0x20200000)) ||
            (local_10 == 0x20300000)) {
            puVar13 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                   *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                   (int)(intptr_t)puVar8 * 4) + 0x48) * 4);
            puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                  *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                  (int)(intptr_t)puVar4 * 4) + 0x48) * 4);
            if (((*puVar13 & 0xfff00000) == 0x10100000) &&
                ((*puVar5 & 0xfff00000) == 0x10100000)) {
                local_2c = (uint32_t*)0x0;
                if (param_1[3] != 0) {
                    piVar6 = (int*)param_1[4];
                    do {
                        if ((int)param_2 == *piVar6) break;
                        local_2c = (uint32_t*)((int)(intptr_t)local_2c + 1);
                        piVar6 = piVar6 + 1;
                    } while (local_2c < param_1[3]);
                }
                uVar11 = 0;
                if (puVar13[3] != 0) {
                    puVar7 = (uint32_t*)puVar13[4];
                    do {
                        if (puVar8 == (uint32_t*)(uintptr_t)*puVar7) break;
                        uVar11 = uVar11 + 1;
                        puVar7 = puVar7 + 1;
                    } while (uVar11 < puVar13[3]);
                }
                uVar15 = 0;
                if (puVar5[3] != 0) {
                    puVar8 = (uint32_t*)puVar5[4];
                    do {
                        if (puVar4 == (uint32_t*)(uintptr_t)*puVar8) break;
                        uVar15 = uVar15 + 1;
                        puVar8 = puVar8 + 1;
                    } while (uVar15 < puVar5[3]);
                }
                if (local_10 == 0x20500000) {
                    iVar9 = *(int*)(puVar13[2] + uVar11 * 4);
                    iVar10 = *(int*)(puVar5[2] + uVar15 * 4);
                }
                else {
                    iVar9 = *(int*)(puVar5[2] + uVar15 * 4);
                    iVar10 = *(int*)(puVar13[2] + uVar11 * 4);
                }
                *(uint32_t*)(param_1[2] + (int)(intptr_t)local_2c * 4) =
                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + iVar9 * 4) + 0x30);
                *(uint32_t*)(param_1[2] + (param_1[3] + (int)(intptr_t)local_2c) * 4) =
                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + iVar10 * 4) + 0x30);
                return 0;
            }
        }
        if (local_10 != 0x20500000) {
            return 0;
        }
        if (puVar8 == puVar4) {
            puVar13 = *(uint32_t**)(*(int*)((char*)self + 0x18) + *(int*)(iVar9 + 0x48) * 4);
            uVar11 = *puVar13 & 0xfff00000;
            if ((uVar11 == 0x10300000) || (uVar11 == 0x10700000)) {
                uVar15 = 0;
                if (puVar13[3] != 0) {
                    puVar5 = (uint32_t*)puVar13[4];
                    do {
                        if ((uint32_t*)(uintptr_t)*puVar5 == puVar8) break;
                        uVar15 = uVar15 + 1;
                        puVar5 = puVar5 + 1;
                    } while (uVar15 < puVar13[3]);
                }
                iVar9 = *(int*)(*(int*)((char*)self + 0x14) +
                                *(int*)(uVar15 * 4 + puVar13[2]) * 4);
                if (((*(uint8_t*)(*(int*)(local_24 + *(int*)(iVar9 + 4) * 4) + 4) & 2) != 0) &&
                    (*(int*)(iVar9 + 8) == -1)) {
                    puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                           *(int*)(iVar9 + 0x48) * 4);
                    uVar3 = *puVar5 & 0xfff00000;
                    if (((uVar3 == 0x10300000) || (uVar3 == 0x10700000)) && (uVar11 != uVar3)) {
                        param_4 = 0;
                        if (puVar5[3] != 0) {
                            uVar11 = puVar5[4];
                            do {
                                *(uint32_t*)(uVar11 + param_4 * 4) =
                                    *(uint32_t*)(uVar15 * 4 + puVar13[2]);
                                uVar11 = puVar5[4];
                                if (*(int*)(uVar11 + param_4 * 4) != 0) break;
                                param_4 = param_4 + 1;
                            } while (param_4 < puVar5[3]);
                        }
                        iVar10 = *(int*)(puVar5[2] + param_4 * 4);
                        iVar9 = *(int*)((char*)self + 0x14);
                        goto LAB_00665c5b;
                    }
                }
            }
        }
        local_50_hi = *local_20 & 1;
        local_1c = (int)(intptr_t)self;
        if (((*local_20 & 1) != 0) && (iVar9 = FUN_0065f0a1(puVar8, puVar4), iVar9 != 0)) {
            goto LAB_00666608;
        }
        local_48.p[3] = (uint32_t*)(uintptr_t)(*local_18 & 1);
        if ((local_48.p[3] != (uint32_t*)0x0) &&
            (iVar9 = FUN_0065f0a1(puVar4, puVar8), iVar9 != 0)) {
            local_14[0xc] = (uint32_t)(uintptr_t)puVar8;
            return 0;
        }
        bVar16 = false;
        bVar2 = false;
        local_2c = (uint32_t*)0x1;
        local_28 = 1;
        uVar11 = local_14[6];
        uVar15 = local_14[5];
        if (uVar15 == 0xffffffff) {
            return 0;
        }
        do {
            local_48.p[4] = (uint32_t*)(uintptr_t)(uVar15 * 4);
            iVar9 = *(int*)(*(int*)(local_1c + 0x18) +
                            *(int*)(*(int*)((int)(intptr_t)local_48.p[4] +
                                            *(int*)(local_1c + 0x14)) + 0x48) * 4);
            uVar3 = 0;
            if (*(uint32_t*)(iVar9 + 0xc) != 0) {
                puVar13 = *(uint32_t**)(iVar9 + 0x10);
                do {
                    if (*puVar13 == uVar15) break;
                    uVar3 = uVar3 + 1;
                    puVar13 = puVar13 + 1;
                } while (uVar3 < *(uint32_t*)(iVar9 + 0xc));
            }
            if (local_50_hi != 0) {
                local_48.p[1] = (uint32_t*)(uintptr_t)*(uint32_t*)(*(int*)(iVar9 + 8) + uVar3 * 4);
                uVar15 = (uint32_t)FUN_0065f0a1(puVar8, local_48.p[1]);
                if ((uVar11 & uVar15) != 0) {
                    bVar16 = true;
                }
                if ((uVar11 == 0) &&
                    (iVar10 = FUN_0065f0a1(local_48.p[1], puVar8), iVar10 != 0)) {
                    local_2c = (uint32_t*)0x0;
                    bVar16 = true;
                }
            }
            if (local_48.p[3] == (uint32_t*)0x0) {
                iVar9 = local_1c;
            }
            else {
                uVar20 = *(uint32_t*)(*(int*)(iVar9 + 8) + uVar3 * 4);
                uVar15 = (uint32_t)FUN_0065f0a1(puVar4, (uint32_t*)(uintptr_t)uVar20);
                iVar9 = local_1c;
                if ((uVar11 & uVar15) != 0) {
                    bVar2 = true;
                }
                if (uVar11 == 0) {
                    iVar10 = FUN_0065f0a1((uint32_t*)(uintptr_t)uVar20, puVar4);
                    if (iVar10 != 0) {
                        local_28 = 0;
                        bVar2 = true;
                    }
                }
            }
            iVar10 = *(int*)(*(int*)(iVar9 + 0x14) + (int)(intptr_t)local_48.p[4]);
            uVar11 = *(uint32_t*)(iVar10 + 0x18);
            uVar15 = *(uint32_t*)(iVar10 + 0x14);
        } while (uVar15 != 0xffffffff);
        if (bVar16) {
            if (!bVar2) {
LAB_006665c2:
                if (local_2c != (uint32_t*)0x0) goto LAB_006665c7;
                goto LAB_006665d1;
            }
            if (local_2c == (uint32_t*)0x0) goto LAB_006665d1;
            if (local_28 == 0) goto LAB_006665c2;
            uVar22 = 1.0;
        }
        else {
LAB_006665c7:
            if ((!bVar2) || (local_28 != 0)) {
                if ((bVar16) && (local_2c != (uint32_t*)0x0)) {
                    local_14[0xc] = (uint32_t)(uintptr_t)puVar4;
                    return 0;
                }
                if (!bVar2) {
                    return 0;
                }
                if (local_28 == 0) {
                    return 0;
                }
                puVar4 = puVar8;
                goto LAB_00666608;
            }
LAB_006665d1:
            uVar22 = 0.0;
        }
        uVar20 = *(uint32_t*)(iVar9 + 0x78);
    }
    puVar4 = (uint32_t*)(uintptr_t)FUN_0065d9d5(uVar20, 0, 0, uVar22);
LAB_00666608:
    local_14[0xc] = (uint32_t)(uintptr_t)puVar4;
    return 0;
}


// 0x666617 — observed shape
int FUN_666617(void* self, uint32_t* param_1, int param_2, uint32_t param_3, int param_4, int param_5)
{
    int* piVar1;
    int* piVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    int iVar5;
    uint32_t* puVar6;
    int* piVar7;
    uint32_t* puVar8;
    int iVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    int* piVar13;
    uint32_t local_a4[8];
    uint32_t* local_9c = &local_a4[2];
    int* local_94 = (int*)&local_a4[4];
    int local_30;
    int* local_2c;
    int local_28;
    int local_24;
    uint8_t* local_20;
    int* local_1c;
    int local_18;
    int local_14;
    uint32_t* local_10;
    int* local_c;
    uint32_t* local_8;

    iVar9 = *(int*)((char*)self + 0x14);
    piVar13 = *(int**)(*(int*)(iVar9 + param_3 * 4) + 0x30);
    piVar1 = *(int**)(*(int*)(iVar9 + (int)param_4 * 4) + 0x30);
    local_20 = *(uint8_t**)(iVar9 + (int)(intptr_t)piVar13 * 4);
    local_10 = *(uint32_t**)(iVar9 + (int)(intptr_t)piVar1 * 4);
    piVar2 = *(int**)(*(int*)(iVar9 + param_5 * 4) + 0x30);
    puVar3 = *(uint32_t**)(iVar9 + param_2 * 4);
    puVar8 = *(uint32_t**)(iVar9 + (int)(intptr_t)piVar2 * 4);
    uVar12 = *puVar3;
    uVar10 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) + puVar3[1] * 4) + 4);
    if ((uVar10 & 1) == 0) {
        return 0;
    }
    if ((uVar10 & 0x1000) != 0) {
        return 0;
    }
    if (((uVar12 & 0xe000000) != 0) || ((*param_1 & 0xfff00000) != 0x30000000))
        goto LAB_006666ed;
    uVar10 = *puVar8 | *local_10;
    if ((uVar10 & 0x8000000) == 0) {
        if ((uVar10 & 0x4000000) != 0) {
            uVar10 = uVar12 | 0x4000000;
            goto LAB_006666dd;
        }
        if ((uVar10 & 0x2000000) != 0) {
            uVar10 = uVar12 | 0x2000000;
            goto LAB_006666dd;
        }
    }
    else {
        uVar10 = uVar12 | 0x8000000;
LAB_006666dd:
        *puVar3 = uVar10;
    }
    *puVar3 = *puVar3 | *puVar8 & *local_10 & 0x1f;
LAB_006666ed:
    if ((((*puVar8 | *local_10) & 0x40) != 0) && ((*param_1 & 0xfff00000) == 0x30000000)) {
        *puVar3 = *puVar3 | 0x40;
    }
    if ((*param_1 & 0xfff00000) == 0x30000000) {
        *puVar3 = *puVar3 | *puVar8 & *local_10 & 0x1f;
        if ((piVar13 == piVar1) && ((*puVar8 & 4) != 0)) {
            *puVar3 = *puVar3 | 4;
        }
        if ((piVar13 == piVar2) && ((*local_10 & 8) != 0)) {
            *puVar3 = *puVar3 | 8;
        }
    }
    if ((*param_1 & 0xfff00000) != 0x30000000) {
        return 0;
    }
    piVar7 = piVar1;
    if (((uVar12 & 0x40) != 0) || ((*local_20 & 4) == 0)) {
        uVar10 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                  *(int*)(local_20 + 4) * 4) + 4);
        if (((uVar10 & 0x100) == 0) || (*(int*)(local_20 + 8) != -1)) {
            if (piVar1 != piVar2) {
                uVar11 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                          local_10[1] * 4) + 4) & 0x100;
                if ((((uVar11 == 0) || (local_10[2] != 0xffffffff)) ||
                     ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                        puVar8[1] * 4) + 5) & 1) == 0)) ||
                    ((puVar8[2] != 0xffffffff ||
                      (*(double*)(local_10 + 8) != *(double*)(puVar8 + 8))))) {
                    if ((uVar12 & 0x40) != 0) {
                        return 0;
                    }
                    if (((((*(int*)(local_20 + 8) == -1) && ((uVar10 & 2) != 0)) &&
                          ((puVar4 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                   *(int*)(local_20 + 0x48) * 4),
                            (*puVar4 & 0xfff00000) == 0x10100000 &&
                            (((uVar11 != 0 && (local_10[2] == 0xffffffff)) &&
                              (*(double*)(local_10 + 8) == 0.0)))))) &&
                         (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                 puVar8[1] * 4) + 5) & 1) != 0 &&
                           (puVar8[2] == 0xffffffff)))) &&
                        (*(double*)(puVar8 + 8) == 1.0)) {
                        uVar12 = 0;
                        if (puVar4[3] != 0) {
                            local_8 = (uint32_t*)puVar4[4];
                            do {
                                if ((int*)(uintptr_t)*local_8 == piVar13) break;
                                local_8 = local_8 + 1;
                                uVar12 = uVar12 + 1;
                            } while (uVar12 < puVar4[3]);
                        }
                        uVar12 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                   *(int*)(puVar4[2] + uVar12 * 4) * 4) + 0x30);
                        if ((**(uint8_t**)(*(int*)((char*)self + 0x14) + uVar12 * 4) & 1) != 0) {
                            puVar3[0xc] = uVar12;
                            return 0;
                        }
                    }
                    if (*(int*)(local_20 + 8) != -1) {
                        return 0;
                    }
                    local_24 = (int)(intptr_t)self;
                    if ((uVar10 & 2) != 0) {
                        puVar4 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                               *(int*)(local_20 + 0x48) * 4);
                        if (((((*puVar4 & 0xfff00000) == 0x20500000) && (uVar11 != 0)) &&
                             ((local_10[2] == 0xffffffff &&
                               (((*(double*)(local_10 + 8) == 0.0 &&
                                  ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                           puVar8[1] * 4) + 5) & 1) != 0)) &&
                                 (puVar8[2] == 0xffffffff)))))) &&
                            (*(double*)(puVar8 + 8) == 1.0)) {
                            local_8 = (uint32_t*)0x0;
                            if (puVar4[3] != 0) {
                                puVar6 = (uint32_t*)puVar4[4];
                                do {
                                    if ((int*)(uintptr_t)*puVar6 == piVar13) break;
                                    local_8 = (uint32_t*)((int)(intptr_t)local_8 + 1);
                                    puVar6 = puVar6 + 1;
                                } while (local_8 < puVar4[3]);
                            }
                            uVar12 = puVar4[3];
                            iVar9 = *(int*)((char*)self + 0x14);
                            local_c = (int*)0x0;
                            local_30 = uVar12 * 4;
                            local_1c = (int*)(puVar4[2] + (int)(intptr_t)local_8 * 4);
                            local_8 = (uint32_t*)(puVar4[2] +
                                                  (uVar12 + (int)(intptr_t)local_8) * 4);
                            do {
                                piVar7 = *(int**)(*(int*)(iVar9 + *local_1c * 4) + 0x30);
                                local_24 = *(int*)(iVar9 +
                                    *(int*)(*(int*)(iVar9 + *local_8 * 4) + 0x30) * 4);
                                if ((((**(uint8_t**)(iVar9 + (int)(intptr_t)piVar7 * 4) & 1) != 0) &&
                                     ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                         *(int*)(local_24 + 4) * 4) + 5) & 1) != 0)) &&
                                    ((*(int*)(local_24 + 8) == -1 &&
                                      (*(double*)(local_24 + 0x20) < 0.0))))
                                    goto LAB_00666ab0;
                                local_c = (int*)((int)(intptr_t)local_c + 1);
                                local_1c = local_1c + uVar12;
                                local_8 = local_8 + -uVar12;
                                local_2c = piVar7;
                            } while (local_c < 2);
                        }
                    }
                    if (*(int*)(local_20 + 8) != -1) {
                        return 0;
                    }
                    if ((uVar10 & 2) == 0) {
                        return 0;
                    }
                    puVar3 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                           *(int*)(local_20 + 0x48) * 4);
                    if ((*puVar3 & 0xfff00000) != 0x20400000) {
                        return 0;
                    }
                    local_14 = -1;
                    if (((uVar11 != 0) && (local_10[2] == 0xffffffff)) &&
                        (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                              puVar8[1] * 4) + 5) & 1) != 0 &&
                          (puVar8[2] == 0xffffffff)))) {
                        if ((*(double*)(local_10 + 8) == 0.0) &&
                            (*(double*)(puVar8 + 8) == 1.0)) {
                            local_14 = 0x20200001;
                        }
                        else if ((*(double*)(local_10 + 8) == 1.0) &&
                                 (*(double*)(puVar8 + 8) == 0.0)) {
                            local_14 = 0x20300001;
                        }
                    }
                    uVar12 = 0;
                    if (puVar3[3] != 0) {
                        puVar8 = (uint32_t*)puVar3[4];
                        do {
                            if ((int*)(uintptr_t)*puVar8 == piVar13) break;
                            uVar12 = uVar12 + 1;
                            puVar8 = puVar8 + 1;
                        } while (uVar12 < puVar3[3]);
                    }
                    uVar10 = puVar3[3];
                    param_3 = 0;
                    local_28 = uVar10 * 4;
                    local_1c = (int*)(puVar3[2] + uVar12 * 4);
                    local_8 = (uint32_t*)(puVar3[2] + (uVar10 + uVar12) * 4);
                    do {
                        iVar9 = *(int*)((char*)self + 0x14);
                        local_c = *(int**)(*(int*)(iVar9 + *local_1c * 4) + 0x30);
                        iVar5 = *(int*)(*(int*)(iVar9 + *local_8 * 4) + 0x30);
                        iVar9 = *(int*)(iVar9 + iVar5 * 4);
                        if (((*(int*)(iVar9 + 8) == -1) &&
                             ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                   *(int*)(iVar9 + 4) * 4) + 4) & 2) != 0)) &&
                            (puVar3 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                    *(int*)(iVar9 + 0x48) * 4),
                             (*puVar3 & 0xfff00000) == 0x10100000)) {
                            uVar12 = 0;
                            if (puVar3[3] != 0) {
                                piVar13 = (int*)puVar3[4];
                                do {
                                    if (*piVar13 == iVar5) break;
                                    uVar12 = uVar12 + 1;
                                    piVar13 = piVar13 + 1;
                                    local_2c = piVar13;
                                } while (uVar12 < puVar3[3]);
                            }
                            piVar13 = *(int**)(*(int*)(*(int*)((char*)self + 0x14) +
                                                       *(int*)(puVar3[2] + uVar12 * 4) * 4) + 0x30);
                            local_18 = local_14;
                            if (local_14 != -1) {
LAB_00666bf1:
                                FUN_0065cc1a();
                                iVar9 = FUN_0065d0ff(local_18, 2, 1, 0);
                                if ((-1 < iVar9) && (iVar9 = FUN_0065cc50(param_1), -1 < iVar9)) {
                                    *local_94 = param_2;
                                    *local_9c = (uint32_t)(uintptr_t)local_c;
                                    local_9c[1] = (uint32_t)(uintptr_t)piVar13;
                                    iVar9 = FUN_66569a(self, local_a4, param_2,
                                                       (int)(intptr_t)local_c,
                                                       (uint32_t)(uintptr_t)piVar13);
                                }
                                FUN_006338c7();
                                return iVar9;
                            }
                            if ((piVar1 == piVar13) && (piVar2 == local_c)) {
                                local_18 = 0x20000001;
                                goto LAB_00666bf1;
                            }
                            if ((piVar1 == local_c) && (piVar2 == piVar13)) {
                                local_18 = 0x20100001;
                                goto LAB_00666bf1;
                            }
                        }
                        local_1c = local_1c + uVar10;
                        param_3 = param_3 + 1;
                        local_8 = local_8 + -uVar10;
                        if (1 < (int)param_3) {
                            return 0;
                        }
                    } while (true);
                }
            }
        }
        else if (*(double*)(local_20 + 0x20) < 0.0) {
            piVar7 = piVar2;
        }
    }
LAB_00666ab0:
    puVar3[0xc] = (uint32_t)(uintptr_t)piVar7;
    return 0;
}

// 0x666c6a — observed shape
int FUN_666c6a(void* self)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    int iVar6;
    uint32_t uVar7;
    uint32_t* puVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int iVar11;
    int local_10;
    uint32_t local_8;

    FUN_00661fbd();
    uVar9 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar6 = *(int*)(*(int*)((char*)self + 0x14) + uVar9 * 4);
            iVar11 = *(int*)(*(int*)((char*)self + 0x10) + *(int*)(iVar6 + 4) * 4);
            *(uint32_t*)(iVar6 + 0x40) = 0;
            if ((*(uint8_t*)(iVar11 + 4) & 0x40) == 0) {
                *(uint32_t*)(iVar6 + 0xc) = 0xffffffff;
                *(uint32_t*)(iVar6 + 0x10) = 0xffffffff;
            }
            uVar9 = uVar9 + 1;
        } while (uVar9 < *(uint32_t*)((char*)self + 8));
    }
    uVar9 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x18) + uVar9 * 4) + 0x24) = 0;
            iVar6 = uVar9 * 4;
            uVar9 = uVar9 + 1;
            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x18) + iVar6) + 0x28) = 0;
        } while (uVar9 < *(uint32_t*)((char*)self + 0xc));
    }
    FUN_00661fbd();
    uVar9 = *(uint32_t*)((char*)self + 0xc);
    uVar5 = uVar9;
    while (true) {
        do {
            if (uVar5 == 0) {
                uVar5 = *(int*)((char*)self + 0xc) - uVar9 >> 1;
                local_8 = 0;
                if (uVar5 != 0) {
                    local_10 = uVar9 << 2;
                    do {
                        puVar8 = (uint32_t*)(local_10 + *(int*)((char*)self + 0x18));
                        uVar3 = *puVar8;
                        *puVar8 = *(uint32_t*)
                                   (*(int*)((char*)self + 0x18) + -4 +
                                    (*(int*)((char*)self + 0xc) - local_8) * 4);
                        iVar6 = *(int*)((char*)self + 0xc) - local_8;
                        local_8 = local_8 + 1;
                        *(uint32_t*)(*(int*)((char*)self + 0x18) + -4 + iVar6 * 4) = uVar3;
                        local_10 = local_10 + 4;
                    } while (local_8 < uVar5);
                }
                uVar5 = 0;
                if (uVar9 != 0) {
                    do {
                        iVar6 = uVar5 * 4;
                        uVar5 = uVar5 + 1;
                        **(uint32_t**)(*(int*)((char*)self + 0x18) + iVar6) = 0;
                    } while (uVar5 < uVar9);
                }
                iVar6 = FUN_0065e4f2();
                if (-1 < iVar6) {
                    uVar9 = 0;
                    if (*(int*)((char*)self + 4) != 0) {
                        do {
                            iVar6 = *(int*)(*(int*)((char*)self + 0x10) + uVar9 * 4);
                            if ((*(uint8_t*)(iVar6 + 4) & 0x40) == 0) {
                                *(uint32_t*)(iVar6 + 0x10) = 0;
                            }
                            uVar9 = uVar9 + 1;
                        } while (uVar9 < *(uint32_t*)((char*)self + 4));
                    }
                    local_8 = 0;
                    if (*(int*)((char*)self + 0xc) != 0) {
                        do {
                            iVar6 = *(int*)(*(int*)((char*)self + 0x18) + local_8 * 4);
                            if ((((*(uint16_t*)(iVar6 + 2) & 0xfff0) != 0) &&
                                 (*(int*)(iVar6 + 0xc) != 0)) &&
                                (iVar11 = *(int*)(*(int*)((char*)self + 0x10) +
                                                  *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                 **(int**)(iVar6 + 0x10) * 4) + 4) * 4),
                                 (*(uint8_t*)(iVar11 + 4) & 0x40) == 0)) {
                                uVar9 = 0;
                                if (*(int*)(iVar6 + 0xc) != 0) {
                                    do {
                                        iVar4 = *(int*)(*(int*)((char*)self + 0x14) +
                                            *(int*)(*(int*)(iVar6 + 0x10) + uVar9 * 4) * 4);
                                        uVar3 = *(uint32_t*)(iVar11 + 0x10);
                                        *(uint32_t*)(iVar4 + 0x10) = uVar9;
                                        uVar9 = uVar9 + 1;
                                        *(uint32_t*)(iVar4 + 0xc) = uVar3;
                                    } while (uVar9 < *(uint32_t*)(iVar6 + 0xc));
                                }
                                *(int*)(iVar11 + 0x10) = *(int*)(iVar11 + 0x10) + 1;
                            }
                            local_8 = local_8 + 1;
                        } while (local_8 < *(uint32_t*)((char*)self + 0xc));
                    }
                    iVar6 = 0;
                }
                return iVar6;
            }
            uVar5 = uVar5 - 1;
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + uVar5 * 4);
            uVar10 = *puVar1 & 0xfff00000;
        } while (uVar10 == 0);
        uVar2 = *(uint32_t*)((char*)self + 0xc);
        uVar7 = *puVar1 & 0xf0000000;
        if ((uVar7 < 0x10000000) || (0x40000000 < uVar7)) {
            if (uVar10 == 0x50000000) {
                iVar6 = FUN_0065ff49(puVar1);
            }
            else {
                iVar6 = FUN_0066040e(puVar1);
            }
        }
        else {
            iVar6 = FUN_0065fb5b(puVar1);
        }
        if (iVar6 < 0) break;
        uVar7 = *(uint32_t*)((char*)self + 0xc);
        for (uVar10 = uVar2; uVar10 < uVar7; uVar10 = uVar10 + 1) {
            iVar6 = FUN_006605b4(*(uint32_t*)(*(int*)((char*)self + 0x18) + uVar10 * 4));
            if (iVar6 < 0) {
                return iVar6;
            }
        }
        local_8 = uVar7 - uVar2 >> 1;
        if (local_8 != 0) {
            iVar11 = uVar2 << 2;
            iVar6 = uVar7 << 2;
            do {
                puVar8 = (uint32_t*)(iVar11 + *(int*)((char*)self + 0x18));
                uVar3 = *puVar8;
                *puVar8 = *(uint32_t*)(iVar6 + -4 + *(int*)((char*)self + 0x18));
                *(uint32_t*)(iVar6 + -4 + *(int*)((char*)self + 0x18)) = uVar3;
                iVar11 = iVar11 + 4;
                iVar6 = iVar6 + -4;
                local_8 = local_8 - 1;
            } while (local_8 != 0);
        }
    }
    return iVar6;
}

// 0x666ea3 — observed shape
uint32_t* FUN_666ea3(void* self)
{
    uint32_t* puVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t* puVar4;
    uint32_t uVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;
    int* piVar8;
    int* piVar9;
    uint32_t* puVar10;
    uint32_t uVar11;
    int iVar12;
    uint32_t* puVar13;
    bool bVar14;
    uint32_t auStack_c4[4];
    uint32_t auStack_b4[4];
    uint32_t auStack_a4[4];
    uint8_t local_94[16];
    uint32_t local_84[4];
    uint32_t local_74[12];
    uint32_t* local_44;
    uint32_t* local_40;
    int* local_3c;
    uint32_t* local_38;
    uint32_t* local_34;
    uint32_t* local_30;
    uint32_t local_2c;
    uint32_t* local_28;
    uint32_t* local_24;
    uint32_t local_20;
    uint32_t* local_1c;
    uint32_t* local_18;
    uint32_t* local_14;
    uint32_t* local_10;
    uint32_t* local_c;
    uint32_t* local_8;

    local_8 = (uint32_t*)0x0;
    FUN_00661fbd();
    local_28 = (uint32_t*)0x0;
    local_44 = (uint32_t*)0x0;
    if (*(int*)((char*)self + 8) != 0) {
        piVar8 = *(int**)((char*)self + 0x14);
        iVar12 = *(int*)((char*)self + 8);
        do {
            if ((*(int*)((char*)self + 0x88) == *(int*)(*piVar8 + 4)) &&
                (puVar7 = *(uint32_t**)(*piVar8 + 0xc), local_28 <= puVar7)) {
                local_28 = (uint32_t*)((int)(intptr_t)puVar7 + 1);
            }
            piVar8 = piVar8 + 1;
            iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
    }
    if (((*(uint8_t*)((char*)self + 0x6c) & 0x20) == 0) &&
        (local_1c = (uint32_t*)0x0, *(int*)((char*)self + 0xc) != 0)) {
        do {
            local_10 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                     (int)(intptr_t)local_1c * 4);
            if (*local_10 == 0x50000002) {
                iVar12 = FUN_0065da35(0x20500002, 0xffffffff, 0xffffffff);
                if (iVar12 == -1) goto LAB_0066847e;
                iVar2 = FUN_0065da35(0x20400001, 0xffffffff, 0xffffffff);
                puVar7 = local_10;
                if (iVar2 == -1) goto LAB_0066847e;
                uVar11 = *(uint32_t*)(*(int*)((char*)self + 0x18) + iVar12 * 4);
                local_8 = *(uint32_t**)(*(int*)((char*)self + 0x18) + iVar2 * 4);
                local_20 = uVar11;
                FUN_0065cc50();
                FUN_0065cc50();
                puVar13 = *(uint32_t**)(uVar11 + 8);
                puVar1 = (uint32_t*)(uintptr_t)puVar7[2];
                local_14 = (uint32_t*)0x0;
                *puVar13 = *puVar1;
                puVar13[1] = puVar1[1];
                puVar13[2] = puVar1[2];
                puVar13[3] = puVar1[3];
                *(uint32_t*)(uintptr_t)local_8[4] = *(uint32_t*)(uintptr_t)local_10[4];
                do {
                    uVar11 = local_20;
                    iVar12 = (int)(intptr_t)local_14 * 4;
                    uVar3 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88),
                                         (uint32_t)(intptr_t)local_28,
                                         (uint32_t)(intptr_t)local_14, 0);
                    *(uint32_t*)(iVar12 + local_8[2]) = uVar3;
                    *(uint32_t*)(iVar12 + *(int*)(uVar11 + 0x10)) =
                        *(uint32_t*)(iVar12 + local_8[2]);
                    if (*(int*)(iVar12 + *(int*)(uVar11 + 0x10)) == -1) goto LAB_0066847e;
                    local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                         *(int*)(iVar12 + *(int*)(local_20 + 0x10)) * 4) + 0x18) =
                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                             *(int*)(uintptr_t)local_10[4] * 4) + 0x18);
                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                         *(int*)(iVar12 + *(int*)(local_20 + 0x10)) * 4) + 0x14) =
                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                             *(int*)(uintptr_t)local_10[4] * 4) + 0x14);
                } while (local_14 < (uint32_t*)0x2);
                puVar7 = *(uint32_t**)((char*)self + 0xc);
                while (puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + -1), local_1c < puVar7) {
                    puVar13 = (uint32_t*)(*(int*)((char*)self + 0x18) +
                                          (int)(intptr_t)puVar7 * 4);
                    *puVar13 = puVar13[-1];
                }
                *(uint32_t*)(*(int*)((char*)self + 0x18) + (int)(intptr_t)local_1c * 4) = local_20;
                *(uint32_t**)(*(int*)((char*)self + 0x18) + 4 + (int)(intptr_t)local_1c * 4) = local_8;
                FUN_00614343();
                *(int*)((char*)self + 0xc) = *(int*)((char*)self + 0xc) + -1;
                local_28 = (uint32_t*)((int)(intptr_t)local_28 + 1);
                local_8 = (uint32_t*)0x1;
            }
            local_1c = (uint32_t*)((int)(intptr_t)local_1c + 1);
        } while (local_1c < *(uint32_t**)((char*)self + 0xc));
        if (local_8 != (uint32_t*)0x0) {
            FUN_00661fbd();
        }
    }
    if ((*(uint8_t*)((char*)self + 0x6c) & 1) != 0) {
        local_2c = *(uint32_t*)((char*)self + 0xc);
        local_20 = 0;
        if (*(uint32_t*)((char*)self + 0xc) != 0) {
            do {
                iVar12 = *(int*)(*(int*)((char*)self + 0x18) + local_20 * 4);
                if ((((*(uint16_t*)(iVar12 + 2) & 0xfff0) != 0) &&
                     (*(uint32_t*)(iVar12 + 0xc) != 0)) &&
                    ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                          *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                         **(int**)(iVar12 + 0x10) * 4) + 4) * 4) +
                                  4) & 0x20) != 0)) {
                    uVar11 = 0;
                    bVar14 = *(int*)(iVar12 + 4) == 0;
                    if (*(int*)(iVar12 + 4) != 0) {
                        local_18 = *(uint32_t**)(iVar12 + 8);
                        do {
                            if (uVar11 != *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                          *local_18 * 4) + 0x10))
                                break;
                            local_18 = local_18 + 1;
                            uVar11 = uVar11 + 1;
                        } while (uVar11 < *(uint32_t*)(iVar12 + 4));
                        bVar14 = uVar11 == *(uint32_t*)(iVar12 + 4);
                    }
                    if (!bVar14) {
                        iVar2 = FUN_0065da35(*(uint32_t*)(iVar12 + 0xc) & 0xfffff | 0x10000000,
                                             0xffffffff, 0xffffffff);
                        if (iVar2 == -1) goto LAB_0066847e;
                        local_18 = *(uint32_t**)(*(int*)((char*)self + 0x18) + iVar2 * 4);
                        FUN_0065cc50();
                        iVar2 = *(int*)(*(int*)((char*)self + 0x14) +
                                        **(int**)(iVar12 + 0x10) * 4);
                        local_14 = (uint32_t*)0x0;
                        local_30 = *(uint32_t**)(iVar2 + 0x18);
                        local_38 = *(uint32_t**)(iVar2 + 0x14);
                        if (*(int*)(iVar12 + 0xc) != 0) {
                            do {
                                iVar2 = (int)(intptr_t)local_14 * 4;
                                *(uint32_t*)(iVar2 + local_18[4]) =
                                    *(uint32_t*)(iVar2 + *(int*)(iVar12 + 0x10));
                                uVar3 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88),
                                                     (uint32_t)(intptr_t)local_28,
                                                     (uint32_t)(intptr_t)local_14, 0);
                                *(uint32_t*)(iVar2 + *(int*)(iVar12 + 0x10)) = uVar3;
                                *(uint32_t*)(iVar2 + local_18[2]) =
                                    *(uint32_t*)(iVar2 + *(int*)(iVar12 + 0x10));
                                if (*(int*)(iVar2 + local_18[2]) == -1) goto LAB_0066847e;
                                local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                                *(uint32_t**)(*(int*)(*(int*)((char*)self + 0x14) +
                                                      *(int*)(iVar2 + local_18[2]) * 4) + 0x18) =
                                    local_30;
                                *(uint32_t**)(*(int*)(*(int*)((char*)self + 0x14) +
                                                      *(int*)(iVar2 + local_18[2]) * 4) + 0x14) =
                                    local_38;
                                **(uint32_t**)(*(int*)((char*)self + 0x14) +
                                               *(int*)(iVar2 + local_18[2]) * 4) =
                                    **(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                   *(int*)(iVar2 + local_18[4]) * 4);
                            } while (local_14 < *(uint32_t**)(iVar12 + 0xc));
                        }
                        local_28 = (uint32_t*)((int)(intptr_t)local_28 + 1);
                        local_8 = (uint32_t*)0x1;
                    }
                }
                local_20 = local_20 + 1;
            } while (local_20 < local_2c);
        }
    }
    if (((*(int*)((char*)self + 0x4c) != 0) && ((*(uint8_t*)((char*)self + 0x70) & 0x20) == 0)) &&
        (local_1c = (uint32_t*)0x0, *(int*)((char*)self + 0xc) != 0)) {
        do {
            local_30 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                     (int)(intptr_t)local_1c * 4);
            if ((*local_30 & 0xf0000000) == 0x60000000) {
                local_18 = (uint32_t*)0x1;
                uVar11 = FUN_0065cc6f(1, &local_20);
                while (uVar11 != 0) {
                    uVar5 = 0;
                    if (uVar11 != 0) {
                        do {
                            if (*(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                      *(int*)(uintptr_t)local_20 * 4) + 0x10) != uVar5)
                                break;
                            uVar5 = uVar5 + 1;
                        } while (uVar5 < uVar11);
                    }
                    if (uVar5 != uVar11) {
                        iVar12 = *(int*)((char*)self + 0xc);
                        local_10 = (uint32_t*)(uintptr_t)
                            FUN_00660699((uint32_t)(intptr_t)local_1c, (uint32_t*)(uintptr_t)local_20,
                                         uVar11, (uint32_t*)(uintptr_t)&local_28);
                        if ((int)(intptr_t)local_10 < 0) goto LAB_00667b44;
                        if (*(int*)((char*)self + 0xc) != iVar12) {
                            local_1c = (uint32_t*)((int)(intptr_t)local_1c +
                                                   (*(int*)((char*)self + 0xc) - iVar12));
                            FUN_00661fbd();
                        }
                        local_8 = (uint32_t*)0x1;
                    }
                    local_18 = (uint32_t*)((int)(intptr_t)local_18 + 1);
                    uVar11 = FUN_0065cc6f((uint32_t)(intptr_t)local_18, &local_20);
                }
            }
            local_1c = (uint32_t*)((int)(intptr_t)local_1c + 1);
        } while (local_1c < *(uint32_t**)((char*)self + 0xc));
    }
    if ((*(int*)((char*)self + 0x4c) != 0) &&
        (local_10 = (uint32_t*)0x0, *(int*)((char*)self + 0xc) != 0)) {
        do {
            puVar7 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                   (int)(intptr_t)local_10 * 4);
            local_1c = puVar7;
            if ((*puVar7 & 0xfff00000) == 0x11000000) {
                if (puVar7[1] == 4) {
                    piVar8 = (int*)(uintptr_t)puVar7[2];
                    iVar12 = *(int*)((char*)self + 0x14);
                    if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                              *(int*)(*(int*)(iVar12 + *piVar8 * 4) + 4) * 4) +
                                      5) & 2) == 0) {
                        local_18 = (uint32_t*)0x0;
                        local_20 = 4;
                        do {
                            iVar2 = *piVar8;
                            piVar8 = piVar8 + 1;
                            local_18 = (uint32_t*)((uint32_t)(uintptr_t)local_18 |
                                                   1 << ((uint8_t)*(uint32_t*)
                                                         (*(int*)(iVar12 + iVar2 * 4) + 0x10) & 0x1f));
                            local_20 = local_20 - 1;
                        } while (local_20 != 0);
                        local_20 = 0;
                        if (local_18 == (uint32_t*)0xf) {
                            puVar4 = (uint32_t*)(uintptr_t)puVar7[2];
                            local_20 = 4;
                            do {
                                uVar5 = *puVar4;
                                puVar4 = puVar4 + 1;
                                uVar11 = local_20 - 1;
                                local_20 = uVar11;
                                local_74[*(int*)(*(int*)(iVar12 + uVar5 * 4) + 0x10) + 8] = uVar5;
                            } while (uVar11 != 0);
                            uVar11 = 0;
                            do {
                                *(uint32_t*)(uVar11 + puVar7[2]) =
                                    *(uint32_t*)((int)(intptr_t)local_74 + uVar11 + 0x20);
                                uVar11 = uVar11 + 4;
                            } while (uVar11 < 0x10);
                            goto LAB_0066754f;
                        }
                    }
                }
                puVar4 = (uint32_t*)(uintptr_t)
                    FUN_0065da35(0x10000004, 0xffffffff, 0xffffffff);
                local_30 = puVar4;
                iVar12 = FUN_0065da35(0x11000004, 0xffffffff, 0xffffffff);
                if ((puVar4 == (uint32_t*)0xffffffff) || (iVar12 == -1)) goto LAB_0066847e;
                iVar2 = *(int*)(*(int*)((char*)self + 0x18) + (int)(intptr_t)puVar4 * 4);
                local_c = *(uint32_t**)(*(int*)((char*)self + 0x18) + iVar12 * 4);
                FUN_0065cc50();
                FUN_0065cc50();
                local_8 = (uint32_t*)0x0;
                while (true) {
                    local_14 = local_8;
                    if ((uint32_t*)(uintptr_t)puVar7[1] <= local_8) {
                        local_14 = (uint32_t*)((int)(intptr_t)puVar7[1] + -1);
                    }
                    local_14 = (uint32_t*)((int)(intptr_t)local_14 * 4);
                    iVar12 = (int)(intptr_t)local_8 * 4;
                    *(uint32_t*)(iVar12 + *(int*)(iVar2 + 8)) =
                        *(uint32_t*)((int)(intptr_t)local_14 + local_1c[2]);
                    uVar3 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88),
                                         (uint32_t)(intptr_t)local_28,
                                         (uint32_t)(intptr_t)local_8, 0);
                    *(uint32_t*)(iVar12 + *(int*)(iVar2 + 0x10)) = uVar3;
                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                         *(int*)(iVar12 + *(int*)(iVar2 + 0x10)) * 4) + 0x14) =
                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                             *(int*)((int)(intptr_t)local_14 + local_1c[4]) * 4) +
                                     0x14);
                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                         *(int*)(iVar12 + *(int*)(iVar2 + 0x10)) * 4) + 0x18) =
                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                             *(int*)((int)(intptr_t)local_14 + local_1c[4]) * 4) +
                                     0x18);
                    if (*(int*)(iVar12 + *(int*)(iVar2 + 0x10)) == -1) goto LAB_0066847e;
                    *(uint32_t*)(iVar12 + local_c[2]) =
                        *(uint32_t*)(iVar12 + *(int*)(iVar2 + 0x10));
                    uVar3 = FUN_0065d9d5(*(int*)((char*)self + 0xa8),
                                         *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                             *(int*)((char*)self + 0xa8) * 4) + 8),
                                         (uint32_t)(intptr_t)local_8, 0);
                    *(uint32_t*)(iVar12 + local_c[4]) = uVar3;
                    local_8 = (uint32_t*)((int)(intptr_t)local_8 + 1);
                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                         *(int*)(iVar12 + local_c[4]) * 4) + 0x14) =
                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                             *(int*)((int)(intptr_t)local_14 + local_1c[4]) * 4) +
                                     0x14);
                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                         *(int*)(iVar12 + local_c[4]) * 4) + 0x18) =
                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                             *(int*)((int)(intptr_t)local_14 + local_1c[4]) * 4) +
                                     0x18);
                    if ((uint32_t*)0x3 < local_8) break;
                    puVar7 = local_1c;
                }
                piVar8 = (int*)(*(int*)(*(int*)((char*)self + 0x10) +
                                        *(int*)((char*)self + 0xa8) * 4) + 8);
                *piVar8 = *piVar8 + 1;
                for (puVar7 = local_30; local_10 < puVar7;
                     puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + -1)) {
                    puVar13 = (uint32_t*)(*(int*)((char*)self + 0x18) +
                                          (int)(intptr_t)puVar7 * 4);
                    *puVar13 = puVar13[-1];
                }
                *(int*)(*(int*)((char*)self + 0x18) + (int)(intptr_t)local_10 * 4) = iVar2;
                puVar7 = (uint32_t*)((int)(intptr_t)local_10 + 1);
                local_10 = puVar7;
                FUN_00614343();
                *(int*)((char*)self + 0xc) = *(int*)((char*)self + 0xc) + -1;
                local_28 = (uint32_t*)((int)(intptr_t)local_28 + 1);
                *(uint32_t**)(*(int*)((char*)self + 0x18) + (int)(intptr_t)puVar7 * 4) = local_c;
                local_8 = (uint32_t*)0x1;
            }
LAB_0066754f:
            local_10 = (uint32_t*)((int)(intptr_t)local_10 + 1);
        } while (local_10 < *(uint32_t**)((char*)self + 0xc));
    }
    if ((*(uint8_t*)((char*)self + 0x6c) & 6) != 0) {
        local_c = (uint32_t*)0x0;
        if (*(int*)((char*)self + 0xc) != 0) {
            do {
                puVar7 = *(uint32_t**)((int)(intptr_t)local_c * 4 +
                                       *(int*)((char*)self + 0x18));
                local_30 = puVar7;
                if (((*puVar7 & 0xfff00000) == 0x10000000) &&
                    (iVar12 = *(int*)((char*)self + 0x14),
                     (*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                          *(int*)(*(int*)(iVar12 +
                                                          *(int*)(uintptr_t)puVar7[4] * 4) + 4) *
                                          4) + 4) & 0x20) == 0)) {
                    local_14 = (uint32_t*)0x0;
                    if (puVar7[3] != 0) {
                        piVar8 = (int*)(uintptr_t)puVar7[2];
                        iVar2 = *piVar8;
                        do {
                            if (*(int*)(*(int*)(iVar12 + iVar2 * 4) + 0x48) !=
                                *(int*)(*(int*)(iVar12 + *piVar8 * 4) + 0x48)) break;
                            local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                            piVar8 = piVar8 + 1;
                        } while (local_14 < (uint32_t*)(uintptr_t)puVar7[3]);
                    }
                    if (local_14 != (uint32_t*)(uintptr_t)puVar7[3]) {
                        puVar4 = (uint32_t*)(uintptr_t)puVar7[1];
                        local_1c = (uint32_t*)0x0;
                        local_8 = (uint32_t*)0x0;
                        if (puVar4 != (uint32_t*)0x0) {
                            do {
                                puVar10 = (uint32_t*)(puVar7[2] +
                                                      (int)(intptr_t)local_8 * 4);
                                uVar11 = *puVar10;
                                if (uVar11 != 0xffffffff) {
                                    local_2c = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                    uVar11 * 4) + 0x48);
                                    uVar11 = 0;
                                    if (local_8 < puVar4) {
                                        local_20 = (int)(intptr_t)puVar4 -
                                                   (int)(intptr_t)local_8;
                                        local_18 = puVar10;
                                        do {
                                            if ((*local_18 != 0xffffffff) &&
                                                (local_2c ==
                                                 *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                     *local_18 * 4) + 0x48))) {
                                                uVar11 = uVar11 + 1;
                                            }
                                            local_18 = local_18 + 1;
                                            local_20 = local_20 - 1;
                                        } while (local_20 != 0);
                                    }
                                    iVar12 = FUN_0065da35(uVar11 & 0xfffff | 0x10000000,
                                                          0xffffffff, 0xffffffff);
                                    if (iVar12 == -1) goto LAB_0066847e;
                                    puVar4 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                           iVar12 * 4);
                                    local_24 = puVar4;
                                    FUN_0065cc50();
                                    local_1c = (uint32_t*)((int)(intptr_t)local_1c + 1);
                                    local_14 = local_8;
                                    if (local_8 < (uint32_t*)(uintptr_t)puVar7[1]) {
                                        local_20 = 0;
                                        do {
                                            iVar12 = (int)(intptr_t)local_14 * 4;
                                            if ((*(int*)(iVar12 + puVar7[2]) != -1) &&
                                                (local_2c ==
                                                 *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                     *(int*)(iVar12 + puVar7[2]) * 4) +
                                                              0x48))) {
                                                *(uint32_t*)(local_20 + puVar4[2]) =
                                                    *(uint32_t*)(iVar12 + puVar7[2]);
                                                *(uint32_t*)(local_20 + local_24[4]) =
                                                    *(uint32_t*)(iVar12 + puVar7[4]);
                                                *(uint32_t*)(iVar12 + puVar7[2]) = 0xffffffff;
                                                local_20 = local_20 + 4;
                                                puVar4 = local_24;
                                            }
                                            local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                                        } while (local_14 < (uint32_t*)(uintptr_t)puVar7[1]);
                                    }
                                }
                                local_8 = (uint32_t*)((int)(intptr_t)local_8 + 1);
                                puVar4 = (uint32_t*)(uintptr_t)puVar7[1];
                            } while (local_8 < puVar4);
                            if (local_1c != (uint32_t*)0x0) {
                                puVar4 = (uint32_t*)(*(int*)((char*)self + 0x18) +
                                                     (*(int*)((char*)self + 0xc) -
                                                      (int)(intptr_t)local_1c) * 4);
                                puVar10 = local_74 + 8;
                                for (puVar7 = local_1c; puVar7 != (uint32_t*)0x0;
                                     puVar7 = (uint32_t*)((int)(intptr_t)puVar7 - 1)) {
                                    *puVar10 = *puVar4;
                                    puVar4 = puVar4 + 1;
                                    puVar10 = puVar10 + 1;
                                }
                            }
                        }
                        puVar7 = local_1c;
                        puVar4 = (uint32_t*)((*(int*)((char*)self + 0xc) -
                                              (int)(intptr_t)local_1c) + -1);
                        if (local_c < puVar4) {
                            iVar12 = ((int)(intptr_t)puVar4 + (int)(intptr_t)local_1c) * 4;
                            do {
                                *(uint32_t*)(*(int*)((char*)self + 0x18) + -4 + iVar12) =
                                    *(uint32_t*)(*(int*)((char*)self + 0x18) +
                                                 (int)(intptr_t)puVar4 * 4);
                                puVar4 = (uint32_t*)((int)(intptr_t)puVar4 + -1);
                                iVar12 = iVar12 + -4;
                            } while (local_c < puVar4);
                        }
                        local_14 = (uint32_t*)0x0;
                        if (local_1c != (uint32_t*)0x0) {
                            iVar12 = (int)(intptr_t)local_c << 2;
                            do {
                                puVar4 = local_14 + 2;
                                local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                                *(uint32_t*)(iVar12 + *(int*)((char*)self + 0x18)) =
                                    local_74[(int)(intptr_t)puVar4];
                                iVar12 = iVar12 + 4;
                            } while (local_14 < local_1c);
                        }
                        FUN_00614343();
                        *(int*)((char*)self + 0xc) = *(int*)((char*)self + 0xc) + -1;
                        local_c = (uint32_t*)((int)(intptr_t)local_c + -1 +
                                             (int)(intptr_t)puVar7);
                        local_8 = (uint32_t*)0x1;
                    }
                }
                local_c = (uint32_t*)((int)(intptr_t)local_c + 1);
            } while (local_c < *(uint32_t**)((char*)self + 0xc));
        }
        local_1c = (uint32_t*)0x0;
        if (*(int*)((char*)self + 0xc) != 0) {
            do {
                puVar7 = *(uint32_t**)((int)(intptr_t)local_1c * 4 +
                                       *(int*)((char*)self + 0x18));
                local_30 = puVar7;
                if ((*puVar7 & 0xfff00000) == 0x10000000) {
                    iVar12 = *(int*)((char*)self + 0x14);
                    if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                             *(int*)(*(int*)(iVar12 +
                                                             *(int*)(uintptr_t)puVar7[4] * 4) + 4) *
                                             4) + 4) & 0x20) == 0) {
                        local_24 = (uint32_t*)0x0;
                        local_14 = (uint32_t*)0x0;
                        local_34 = (uint32_t*)0x0;
                        puVar4 = (uint32_t*)0x0;
                        if (puVar7[3] != 0) {
                            local_3c = (int*)(uintptr_t)puVar7[2];
                            local_c = (uint32_t*)0x0;
                            local_18 = (uint32_t*)((int)(intptr_t)puVar7[4] -
                                                   (int)(intptr_t)local_3c);
                            do {
                                if (*(int*)(*(int*)(iVar12 +
                                                    *(int*)((int)(intptr_t)local_18 +
                                                            (int)(intptr_t)local_3c) * 4) + 0x10) ==
                                    *(int*)(*(int*)(iVar12 + *local_3c * 4) + 0x10)) {
                                    local_34 = (uint32_t*)((int)(intptr_t)local_34 + 1);
                                }
                                local_10 = (uint32_t*)0x0;
                                if (local_c != (uint32_t*)0x0) {
                                    piVar9 = (int*)(uintptr_t)puVar7[2];
                                    piVar8 = (int*)((int)(intptr_t)local_c + (int)(intptr_t)piVar9);
                                    do {
                                        if (*(int*)(*(int*)(iVar12 + *piVar9 * 4) + 0x10) ==
                                            *(int*)(*(int*)(iVar12 + *piVar8 * 4) + 0x10)) {
                                            local_24 = (uint32_t*)((int)(intptr_t)local_24 + 1);
                                            break;
                                        }
                                        local_10 = (uint32_t*)((int)(intptr_t)local_10 + 1);
                                        piVar9 = piVar9 + 1;
                                    } while (local_10 < local_14);
                                }
                                local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                                puVar4 = (uint32_t*)(uintptr_t)puVar7[3];
                                local_c = local_c + 1;
                                local_3c = local_3c + 1;
                            } while (local_14 < puVar4);
                        }
                        if (((local_34 != puVar4) && ((uint32_t*)((int)(intptr_t)local_24 + 1) != puVar4)) &&
                            (((uint32_t*)0x1 < local_34 || (local_24 != (uint32_t*)0x0)))) {
                            local_c = (uint32_t*)0x0;
                            if ((uint32_t*)0x1 < local_34) {
                                iVar12 = FUN_0065da35((uint32_t)(uintptr_t)local_34 & 0xfffff |
                                                          0x10000000, 0xffffffff, 0xffffffff);
                                if (iVar12 == -1) goto LAB_0066847e;
                                local_20 = *(uint32_t*)(*(int*)((char*)self + 0x18) + iVar12 * 4);
                                FUN_0065cc50();
                                local_c = (uint32_t*)0x1;
                                local_14 = (uint32_t*)0x0;
                                if (puVar7[3] != 0) {
                                    local_2c = 0;
                                    do {
                                        iVar12 = (int)(intptr_t)local_14 * 4;
                                        if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                           *(int*)(iVar12 + puVar7[4]) * 4) + 0x10) ==
                                            *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                           *(int*)(iVar12 + puVar7[2]) * 4) + 0x10)) {
                                            *(int*)(local_2c + *(int*)(local_20 + 0x10)) =
                                                *(int*)(iVar12 + puVar7[4]);
                                            *(uint32_t*)(local_2c + *(int*)(local_20 + 8)) =
                                                *(uint32_t*)(iVar12 + puVar7[2]);
                                            *(uint32_t*)(iVar12 + puVar7[2]) = 0xffffffff;
                                            local_2c = local_2c + 4;
                                        }
                                        local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                                    } while (local_14 < (uint32_t*)(uintptr_t)puVar7[3]);
                                }
                            }
                            puVar4 = (uint32_t*)(uintptr_t)puVar7[1];
                            local_8 = (uint32_t*)0x0;
                            if (puVar4 != (uint32_t*)0x0) {
                                do {
                                    puVar10 = (uint32_t*)(puVar7[2] +
                                                          (int)(intptr_t)local_8 * 4);
                                    uVar11 = *puVar10;
                                    if (uVar11 != 0xffffffff) {
                                        local_2c = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                        uVar11 * 4) + 0x10);
                                        uVar11 = 0;
                                        if (local_8 < puVar4) {
                                            local_20 = (int)(intptr_t)puVar4 -
                                                       (int)(intptr_t)local_8;
                                            local_24 = puVar10;
                                            do {
                                                if ((*local_24 != 0xffffffff) &&
                                                    (local_2c ==
                                                     *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                         *local_24 * 4) + 0x10))) {
                                                    uVar11 = uVar11 + 1;
                                                }
                                                local_24 = local_24 + 1;
                                                local_20 = local_20 - 1;
                                            } while (local_20 != 0);
                                        }
                                        iVar12 = FUN_0065da35(uVar11 & 0xfffff | 0x10000000,
                                                              0xffffffff, 0xffffffff);
                                        if (iVar12 == -1) goto LAB_0066847e;
                                        puVar4 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                               iVar12 * 4);
                                        local_24 = puVar4;
                                        FUN_0065cc50();
                                        local_c = (uint32_t*)((int)(intptr_t)local_c + 1);
                                        local_14 = local_8;
                                        if (local_8 < (uint32_t*)(uintptr_t)puVar7[1]) {
                                            local_20 = 0;
                                            do {
                                                iVar12 = (int)(intptr_t)local_14 * 4;
                                                if ((*(int*)(iVar12 + puVar7[2]) != -1) &&
                                                    (local_2c ==
                                                     *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                         *(int*)(iVar12 + puVar7[2]) * 4) +
                                                                  0x10))) {
                                                    *(uint32_t*)(local_20 + puVar4[4]) =
                                                        *(uint32_t*)(iVar12 + puVar7[4]);
                                                    *(uint32_t*)(local_20 + local_24[2]) =
                                                        *(uint32_t*)(iVar12 + puVar7[2]);
                                                    *(uint32_t*)(iVar12 + puVar7[2]) = 0xffffffff;
                                                    local_20 = local_20 + 4;
                                                    puVar4 = local_24;
                                                }
                                                local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                                            } while (local_14 < (uint32_t*)(uintptr_t)puVar7[1]);
                                        }
                                    }
                                    local_8 = (uint32_t*)((int)(intptr_t)local_8 + 1);
                                    puVar4 = (uint32_t*)(uintptr_t)puVar7[1];
                                } while (local_8 < puVar4);
                            }
                            if (local_c != (uint32_t*)0x0) {
                                puVar4 = (uint32_t*)(*(int*)((char*)self + 0x18) +
                                                     (*(int*)((char*)self + 0xc) -
                                                      (int)(intptr_t)local_c) * 4);
                                puVar10 = local_74 + 8;
                                for (puVar7 = local_c; puVar7 != (uint32_t*)0x0;
                                     puVar7 = (uint32_t*)((int)(intptr_t)puVar7 - 1)) {
                                    *puVar10 = *puVar4;
                                    puVar4 = puVar4 + 1;
                                    puVar10 = puVar10 + 1;
                                }
                            }
                            puVar7 = (uint32_t*)((*(int*)((char*)self + 0xc) -
                                                  (int)(intptr_t)local_c) + -1);
                            if (local_1c < puVar7) {
                                iVar12 = ((int)(intptr_t)puVar7 + (int)(intptr_t)local_c) * 4;
                                do {
                                    *(uint32_t*)(*(int*)((char*)self + 0x18) + -4 + iVar12) =
                                        *(uint32_t*)(*(int*)((char*)self + 0x18) +
                                                     (int)(intptr_t)puVar7 * 4);
                                    puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + -1);
                                    iVar12 = iVar12 + -4;
                                } while (local_1c < puVar7);
                            }
                            puVar7 = (uint32_t*)0x0;
                            if (local_c != (uint32_t*)0x0) {
                                iVar12 = (int)(intptr_t)local_1c << 2;
                                do {
                                    *(uint32_t*)(iVar12 + *(int*)((char*)self + 0x18)) =
                                        local_74[(int)(intptr_t)(puVar7 + 2)];
                                    puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + 1);
                                    iVar12 = iVar12 + 4;
                                } while (puVar7 < local_c);
                            }
                            FUN_00614343();
                            *(int*)((char*)self + 0xc) = *(int*)((char*)self + 0xc) + -1;
                            local_1c = (uint32_t*)((int)(intptr_t)local_1c + -1 +
                                                   (int)(intptr_t)local_c);
                            local_8 = (uint32_t*)0x1;
                        }
                    }
                }
                local_1c = (uint32_t*)((int)(intptr_t)local_1c + 1);
            } while (local_1c < *(uint32_t**)((char*)self + 0xc));
        }
    }
    if (local_8 != (uint32_t*)0x0) {
        FUN_00661fbd();
    }
    puVar7 = local_28;
    local_44 = FUN_00533c78();
    if (local_44 == (uint32_t*)0x0) {
LAB_0066847e:
        local_10 = (uint32_t*)0x8007000e;
    }
    else {
        puVar13 = local_44;
        for (uVar11 = (uint32_t)(uintptr_t)puVar7 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
            *puVar13 = 0;
            puVar13 = puVar13 + 1;
        }
        uVar11 = 0;
        // Byte tail of the original clear loop; its count is always zero here.
        for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
            *(uint8_t*)puVar13 = 0;
            puVar13 = (uint32_t*)((int)(intptr_t)puVar13 + 1);
        }
        if (*(int*)((char*)self + 8) != 0) {
            do {
                iVar12 = *(int*)(*(int*)((char*)self + 0x14) + uVar11 * 4);
                *(uint32_t*)(iVar12 + 0x5c) = 0;
                if (*(int*)((char*)self + 0x88) == *(int*)(iVar12 + 4)) {
                    if (local_44[*(int*)(iVar12 + 0xc)] <= *(uint32_t*)(iVar12 + 0x10)) {
                        local_44[*(int*)(iVar12 + 0xc)] = *(uint32_t*)(iVar12 + 0x10) + 1;
                    }
                }
                uVar11 = uVar11 + 1;
            } while (uVar11 < *(uint32_t*)((char*)self + 8));
        }
        uVar11 = *(uint32_t*)((char*)self + 0xc);
        if (*(uint32_t*)((char*)self + 0xc) != 0) {
            do {
                local_20 = uVar11 - 1;
                puVar7 = *(uint32_t**)(*(int*)((char*)self + 0x18) + (uVar11 - 1) * 4);
                uVar11 = *puVar7;
                local_14 = puVar7;
                if ((uVar11 & 0xfff00000) != 0) {
                    local_10 = (uint32_t*)(uintptr_t)(uVar11 & 0xfffff);
                    local_2c = puVar7[1] / (uint32_t)(uintptr_t)local_10;
                    if (((puVar7[3] != 0) && (0xfffffff < (uVar11 & 0xf0000000))) &&
                        ((uVar11 & 0xf0000000) < 0x40000001)) {
                        FUN_00661d51(puVar7[4], local_94, (uint32_t)(uintptr_t)local_10, 1);
                        uVar11 = 0;
                        if (local_2c != 0) {
                            do {
                                FUN_00661d51(puVar7[2] + puVar7[3] * uVar11 * 4, local_94,
                                             (uint32_t)(uintptr_t)local_10, 0);
                                uVar11 = uVar11 + 1;
                            } while (uVar11 < local_2c);
                        }
                    }
                    local_74[4] = 0;
                    local_74[5] = 0;
                    local_74[6] = 0;
                    local_74[7] = 0;
                    if ((*puVar7 & 0xfff00000) == 0x10000000) {
                        iVar12 = *(int*)((char*)self + 0x14);
                        local_34 = *(uint32_t**)(iVar12 + *(int*)(uintptr_t)puVar7[4] * 4);
                        uVar11 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                       local_34[1] * 4) + 4);
                        if (((((uVar11 & 4) == 0) &&
                              (((*(uint8_t*)((char*)self + 0x6c) & 1) == 0 ||
                                ((uVar11 & 0x20) == 0)))) &&
                             (*(int*)((char*)self + 0x88) ==
                              *(int*)(*(int*)(iVar12 + *(int*)(uintptr_t)puVar7[2] * 4) + 4))) &&
                            (local_2c = 0, puVar7[1] != 0)) {
                            local_24 = (uint32_t*)((int)(intptr_t)puVar7[2] -
                                                   (int)(intptr_t)(local_74 + 4));
                            local_30 = (uint32_t*)(*(uint32_t*)((char*)self + 0xcc) & 4);
                            do {
                                iVar2 = *(int*)(iVar12 +
                                    *(int*)((int)(intptr_t)(local_74 + 4) +
                                            (int)(intptr_t)(local_24 + local_2c)) * 4);
                                local_18 = *(uint32_t**)(iVar2 + 0x48);
                                local_10 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                         (int)(intptr_t)local_18 * 4);
                                if (local_30 != (uint32_t*)0x0) {
                                    local_38 = (uint32_t*)(uintptr_t)local_34[0x18];
                                    if (((local_38 != (uint32_t*)0x0) &&
                                         (*(uint32_t**)(iVar2 + 0x60) != (uint32_t*)0x0)) &&
                                        (local_38 != *(uint32_t**)(iVar2 + 0x60))) break;
                                }
                                if ((local_34[6] != *(uint32_t*)(iVar2 + 0x18)) ||
                                    (local_34[5] != *(uint32_t*)(iVar2 + 0x14))) break;
                                local_8 = (uint32_t*)0x0;
                                if (local_10[3] != 0) {
                                    local_3c = (int*)(uintptr_t)local_10[4];
                                    do {
                                        iVar2 = *(int*)(iVar12 + *local_3c * 4);
                                        if ((local_20 != *(uint32_t*)(iVar2 + 0x54)) ||
                                            (local_20 != *(uint32_t*)(iVar2 + 0x58))) break;
                                        local_8 = (uint32_t*)((int)(intptr_t)local_8 + 1);
                                        local_3c = local_3c + 1;
                                    } while (local_8 < (uint32_t*)(uintptr_t)local_10[3]);
                                }
                                if (local_8 != (uint32_t*)(uintptr_t)local_10[3]) break;
                                local_8 = (uint32_t*)0x0;
                                if ((uint32_t*)(uintptr_t)local_10[3] != (uint32_t*)0x0) {
                                    piVar8 = (int*)(uintptr_t)local_10[4];
                                    do {
                                        iVar2 = *(int*)(*(int*)(iVar12 + *piVar8 * 4) + 0x14);
                                        if ((iVar2 != -1) &&
                                            (local_18 <= *(uint32_t**)(*(int*)(iVar12 + iVar2 * 4) +
                                                                       0x48))) break;
                                        local_8 = (uint32_t*)((int)(intptr_t)local_8 + 1);
                                        piVar8 = piVar8 + 1;
                                    } while (local_8 < (uint32_t*)(uintptr_t)local_10[3]);
                                }
                                if ((local_8 != (uint32_t*)(uintptr_t)local_10[3]) ||
                                    ((*local_10 & 0xfff00000) == 0x20700000))
                                    break;
                                local_74[local_2c + 4] = 1;
                                local_2c = local_2c + 1;
                                if (puVar7[1] <= local_2c) break;
                            } while (true);
                        }
                    }
                    if (((*puVar7 & 0xf0000000) < 0x10000000) ||
                        (0x40000000 < (*puVar7 & 0xf0000000))) {
                        uVar11 = 0;
                        do {
                            local_84[uVar11] = uVar11;
                            uVar11 = uVar11 + 1;
                        } while (uVar11 < 4);
                    }
                    else {
                        local_10 = (uint32_t*)0x0;
                        if (puVar7[3] != 0) {
                            uVar11 = puVar7[4];
                            iVar12 = *(int*)((char*)self + 0x14);
                            do {
                                iVar2 = (int)(intptr_t)local_10 * 4;
                                puVar4 = local_84 + (int)(intptr_t)local_10;
                                local_10 = (uint32_t*)((int)(intptr_t)local_10 + 1);
                                *puVar4 = *(uint32_t*)(*(int*)(iVar12 +
                                                               *(int*)(iVar2 + uVar11) * 4) + 0x10);
                            } while (local_10 < (uint32_t*)(uintptr_t)puVar7[3]);
                        }
                    }
                    local_2c = 0;
                    while (true) {
                        local_28 = (uint32_t*)(uintptr_t)FUN_0065cc6f(local_2c, &local_1c);
                        if (local_28 == (uint32_t*)0x0) break;
                        local_74[0] = 0;
                        local_74[1] = 0;
                        local_74[2] = 0;
                        local_c = (uint32_t*)0x0;
                        local_3c = (int*)0x0;
                        local_74[3] = 0;
                        local_10 = (uint32_t*)0x0;
                        if (local_28 == (uint32_t*)0x0) {
LAB_00667fd7:
                            if ((*local_14 & 0xfff00000) != 0x10000000) {
                                uVar11 = 0;
                                do {
                                    if ((uint32_t*)(uintptr_t)local_74[uVar11] == local_28) {
                                        local_c = (uint32_t*)0x1;
                                        break;
                                    }
                                    uVar11 = uVar11 + 1;
                                } while (uVar11 < 4);
                                if (local_c != (uint32_t*)0x0) goto LAB_00668041;
                            }
                            if ((local_3c !=
                                 (int*)(uintptr_t)local_44[*(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                  *local_1c * 4) + 0xc)]) &&
                                (uVar11 = 0, local_14[3] != 0)) {
                                do {
                                    if (local_74[uVar11 + 4] == 0) {
                                        local_c = (uint32_t*)0x1;
                                        break;
                                    }
                                    uVar11 = uVar11 + 1;
                                } while (uVar11 < local_14[3]);
                                if (local_c != (uint32_t*)0x0) goto LAB_00668041;
                            }
                            local_18 = (uint32_t*)0x0;
                            if (local_28 != (uint32_t*)0x0) {
                                do {
                                    puVar4 = local_14;
                                    puVar7 = local_18;
                                    iVar12 = (int)(intptr_t)local_18 * 4;
                                    if (local_74[(int)(intptr_t)(local_18 + 1)] == 0) {
                                        puVar13 = *(uint32_t**)
                                            (*(int*)((char*)self + 0x14) +
                                             local_1c[(int)(intptr_t)local_18] * 4);
                                        if (local_74[puVar13[4]] == 1) {
                                            local_74[(int)(intptr_t)(local_18 + 2)] =
                                                local_1c[(int)(intptr_t)local_18];
                                            puVar13[4] = local_84[(int)(intptr_t)puVar7];
                                        }
                                        else {
                                            uVar11 = FUN_0065d9d5(puVar13[1], puVar13[3],
                                                                  local_84[(int)(intptr_t)local_18], 0);
                                            local_74[(int)(intptr_t)(puVar7 + 2)] = uVar11;
                                            if (uVar11 == 0xffffffff) goto LAB_0066847e;
                                            iVar12 = uVar11 * 4;
                                            FUN_0065d5bd();
                                            **(uint32_t**)(iVar12 + *(int*)((char*)self + 0x14)) =
                                                *puVar13;
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                iVar12) + 0x18) = puVar13[6];
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                iVar12) + 0x14) = puVar13[5];
                                            local_44[puVar13[3]] = local_44[puVar13[3]] + 1;
                                            local_74[puVar13[4]] = local_74[puVar13[4]] - 1;
                                        }
                                    }
                                    else {
                                        uVar11 = local_14[4];
                                        uVar5 = *(uint32_t*)(uVar11 + iVar12);
                                        iVar2 = *(int*)((char*)self + 0x14);
                                        local_74[(int)(intptr_t)(local_18 + 2)] = uVar5;
                                        if (*(int*)(*(int*)(iVar2 + uVar5 * 4) + 0x60) == 0) {
                                            *(uint32_t*)(*(int*)(iVar2 +
                                                                *(uint32_t*)(uVar11 + iVar12) * 4) +
                                                         0x60) =
                                                *(uint32_t*)(*(int*)(iVar2 +
                                                                     *(int*)(iVar12 + puVar4[2]) * 4) +
                                                             0x60);
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                *(int*)(iVar12 + puVar4[4]) * 4) +
                                                         100) =
                                                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                     *(int*)(iVar12 + puVar4[2]) * 4) +
                                                             100);
                                        }
                                    }
                                    local_18 = (uint32_t*)((int)(intptr_t)local_18 + 1);
                                } while (local_18 < local_28);
                            }
                            local_38 = (uint32_t*)0x0;
                            if (local_28 != (uint32_t*)0x0) {
                                do {
                                    puVar7 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                           local_1c[(int)(intptr_t)local_38] * 4);
                                    local_30 = puVar7;
                                    if (puVar7[0x17] == 0) {
                                        local_c = (uint32_t*)0x0;
                                        for (puVar4 = local_38; puVar10 = local_c, puVar4 < local_28;
                                             puVar4 = (uint32_t*)((int)(intptr_t)puVar4 + 1)) {
                                            iVar12 = *(int*)(*(int*)((char*)self + 0x14) +
                                                             local_1c[(int)(intptr_t)puVar4] * 4);
                                            if (puVar7[0x12] == *(uint32_t*)(iVar12 + 0x48)) {
                                                local_c = (uint32_t*)((int)(intptr_t)local_c + 1);
                                                auStack_b4[(int)(intptr_t)puVar10] =
                                                    local_1c[(int)(intptr_t)puVar4];
                                                auStack_a4[(int)(intptr_t)puVar10] =
                                                    local_74[(int)(intptr_t)(puVar4 + 2)];
                                                *(uint32_t*)(iVar12 + 0x5c) = 1;
                                            }
                                        }
                                        puVar7 = *(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                               puVar7[0x12] * 4);
                                        uVar11 = *puVar7 & 0xf0000000;
                                        if ((uVar11 < 0x10000000) || (0x40000000 < uVar11)) {
                                            local_18 = (uint32_t*)0x0;
                                            if (puVar7[3] != 0) {
                                                do {
                                                    puVar4 = (uint32_t*)(puVar7[4] +
                                                                        (int)(intptr_t)local_18 * 4);
                                                    puVar10 = (uint32_t*)0x0;
                                                    do {
                                                        if (*puVar4 ==
                                                            local_1c[(int)(intptr_t)puVar10]) {
                                                            *puVar4 = local_74[(int)(intptr_t)(puVar10 + 2)];
                                                            break;
                                                        }
                                                        puVar10 = (uint32_t*)((int)(intptr_t)puVar10 + 1);
                                                    } while (puVar10 < local_28);
                                                    local_18 = (uint32_t*)((int)(intptr_t)local_18 + 1);
                                                } while (local_18 < (uint32_t*)(uintptr_t)puVar7[3]);
                                            }
                                        }
                                        else {
                                            puVar4 = (uint32_t*)0x0;
                                            local_34 = (uint32_t*)(puVar7[1] / (*puVar7 & 0xfffff));
                                            if (local_c != (uint32_t*)0x0) {
                                                puVar10 = (uint32_t*)(uintptr_t)puVar7[3];
                                                do {
                                                    local_18 = (uint32_t*)0x0;
                                                    if (puVar10 != (uint32_t*)0x0) {
                                                        puVar6 = (uint32_t*)(uintptr_t)puVar7[4];
                                                        do {
                                                            if (*puVar6 ==
                                                                auStack_b4[(int)(intptr_t)puVar4]) {
                                                                auStack_c4[(int)(intptr_t)puVar4] =
                                                                    (uint32_t)(uintptr_t)local_18;
                                                                break;
                                                            }
                                                            local_18 = (uint32_t*)((int)(intptr_t)local_18 + 1);
                                                            puVar10 = (uint32_t*)(uintptr_t)puVar7[3];
                                                            puVar6 = puVar6 + 1;
                                                        } while (local_18 < puVar10);
                                                    }
                                                    puVar4 = (uint32_t*)((int)(intptr_t)puVar4 + 1);
                                                } while (puVar4 < local_c);
                                            }
                                            iVar12 = FUN_0065d0b4();
                                            if (iVar12 == 0) {
                                                iVar12 = 0;
                                            }
                                            else {
                                                iVar12 = FUN_0065cc1a();
                                            }
                                            if (iVar12 == 0) goto LAB_0066847e;
                                            local_10 = (uint32_t*)(uintptr_t)
                                                FUN_0065d0ff((*puVar7 ^ (uint32_t)(uintptr_t)local_c) &
                                                                 0xfffff ^ *puVar7,
                                                             (int)(intptr_t)local_34 *
                                                                 (int)(intptr_t)local_c,
                                                             (int)(intptr_t)local_c, 0);
                                            if (((int)(intptr_t)local_10 < 0) ||
                                                (local_10 = (uint32_t*)(uintptr_t)FUN_0065cc50(),
                                                 (int)(intptr_t)local_10 < 0)) {
                                                FUN_00614343();
                                                goto LAB_00667b44;
                                            }
                                            local_10 = (uint32_t*)0x0;
                                            if (local_c != (uint32_t*)0x0) {
                                                do {
                                                    local_18 = (uint32_t*)0x0;
                                                    *(uint32_t*)((int)(intptr_t)local_10 * 4 +
                                                                 *(int*)(iVar12 + 0x10)) =
                                                        auStack_a4[(int)(intptr_t)local_10];
                                                    if (local_34 != (uint32_t*)0x0) {
                                                        local_40 = (uint32_t*)(uintptr_t)
                                                            auStack_c4[(int)(intptr_t)local_10];
                                                        local_24 = (uint32_t*)((int)(intptr_t)local_10 * 4);
                                                        do {
                                                            iVar2 = puVar7[3] *
                                                                    (int)(intptr_t)local_18;
                                                            local_18 = (uint32_t*)((int)(intptr_t)local_18 + 1);
                                                            *(uint32_t*)((int)(intptr_t)local_24 +
                                                                         *(int*)(iVar12 + 8)) =
                                                                *(uint32_t*)(puVar7[2] +
                                                                             (int)(intptr_t)(iVar2 +
                                                                                             (int)(intptr_t)local_40) *
                                                                                 4);
                                                            local_24 = local_24 + (int)(intptr_t)local_c;
                                                        } while (local_18 < local_34);
                                                    }
                                                    local_10 = (uint32_t*)((int)(intptr_t)local_10 + 1);
                                                } while (local_10 < local_c);
                                            }
                                            if (*(int*)(*(int*)((char*)self + 0x18) +
                                                        local_30[0x12] * 4) != 0) {
                                                FUN_00614343();
                                            }
                                            *(int*)(*(int*)((char*)self + 0x18) +
                                                    local_30[0x12] * 4) = iVar12;
                                        }
                                    }
                                    local_38 = (uint32_t*)((int)(intptr_t)local_38 + 1);
                                } while (local_38 < local_28);
                            }
                            puVar7 = (uint32_t*)0x0;
                            if (local_28 != (uint32_t*)0x0) {
                                do {
                                    local_1c[(int)(intptr_t)puVar7] =
                                        local_74[(int)(intptr_t)(puVar7 + 2)];
                                    puVar4 = local_1c + (int)(intptr_t)puVar7;
                                    puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + 1);
                                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                         *puVar4 * 4) + 0x5c) = 1;
                                } while (puVar7 < local_28);
                            }
                        }
                        else {
                            do {
                                puVar7 = local_10;
                                local_30 = local_1c + (int)(intptr_t)local_10;
                                iVar12 = *(int*)(*(int*)((char*)self + 0x14) +
                                                 local_1c[(int)(intptr_t)local_10] * 4);
                                if ((*(int*)((char*)self + 0x88) != *(int*)(iVar12 + 4)) ||
                                    (iVar2 = *(int*)(iVar12 + 0x48), iVar2 == -1)) break;
                                if (*(int*)(iVar12 + 0x5c) != 0) {
                                    local_c = (uint32_t*)0x1;
                                }
                                local_38 = *(uint32_t**)(iVar12 + 0x10);
                                local_40 = local_74 + (int)(intptr_t)*(uint32_t**)(iVar12 + 0x10);
                                if (local_74[(int)(intptr_t)*(uint32_t**)(iVar12 + 0x10)] == 0) {
                                    local_3c = (int*)((int)(intptr_t)local_3c + 1);
                                }
                                local_74[*(int*)(iVar12 + 0x10)] =
                                    local_74[*(int*)(iVar12 + 0x10)] + 1;
                                puVar4 = *(uint32_t**)(*(int*)((char*)self + 0x18) + iVar2 * 4);
                                uVar11 = *puVar4;
                                uVar5 = uVar11 & 0xfff00000;
                                if (((uVar5 == 0x20700000) || (uVar5 == 0x20800000)) ||
                                    (uVar5 == 0x20900000)) {
LAB_00667fac:
                                    local_c = (uint32_t*)0x1;
                                }
                                else if (((uVar11 & 0xf0000000) < 0x10000000) ||
                                         (0x40000000 < (uVar11 & 0xf0000000))) {
                                    if (((1 < puVar4[3]) && (local_10 != local_38)) ||
                                        (1 < *local_40))
                                        goto LAB_00667fac;
                                }
                                else {
                                    if ((*(int*)(iVar12 + 0x5c) != 0) &&
                                        (local_40 = (uint32_t*)(uintptr_t)
                                                        local_84[(int)(intptr_t)puVar7],
                                         local_40 != local_38)) {
                                        local_34 = (uint32_t*)0xffffffff;
                                        local_18 = (uint32_t*)0xffffffff;
                                        local_8 = (uint32_t*)0x0;
                                        if (puVar4[3] != 0) {
                                            local_24 = (uint32_t*)(uintptr_t)puVar4[4];
                                            do {
                                                if (*local_30 == *local_24) {
                                                    local_34 = local_8;
                                                }
                                                if (local_40 ==
                                                    *(uint32_t**)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                         *local_24 * 4) + 0x10)) {
                                                    local_18 = local_8;
                                                }
                                                local_8 = (uint32_t*)((int)(intptr_t)local_8 + 1);
                                                local_24 = local_24 + 1;
                                            } while (local_8 < (uint32_t*)(uintptr_t)puVar4[3]);
                                            if ((local_34 != (uint32_t*)0xffffffff) &&
                                                (local_18 != (uint32_t*)0xffffffff)) {
                                                local_38 = (uint32_t*)(puVar4[1] / (uVar11 & 0xfffff));
                                                local_8 = (uint32_t*)0x0;
                                                if (local_38 != (uint32_t*)0x0) {
                                                    local_24 = (uint32_t*)(puVar4[2] +
                                                                          (int)(intptr_t)local_34 * 4);
                                                    puVar7 = (uint32_t*)(puVar4[2] +
                                                                        (int)(intptr_t)local_18 * 4);
                                                    do {
                                                        if (*local_24 != *puVar7) break;
                                                        local_8 = (uint32_t*)((int)(intptr_t)local_8 + 1);
                                                        local_24 = local_24 + puVar4[3];
                                                        puVar7 = puVar7 + puVar4[3];
                                                        local_40 = puVar7;
                                                    } while (local_8 < local_38);
                                                }
                                                if (local_8 == local_38) {
                                                    *local_30 = *(uint32_t*)(puVar4[4] +
                                                                            (int)(intptr_t)local_18 * 4);
                                                }
                                            }
                                        }
                                    }
                                    iVar2 = FUN_0065ccdf();
                                    if ((iVar2 != 0) && (1 < local_74[*(int*)(iVar12 + 0x10)])) {
                                        local_c = (uint32_t*)0x1;
                                    }
                                }
                                local_10 = (uint32_t*)((int)(intptr_t)local_10 + 1);
                            } while (local_10 < local_28);
                            if (local_10 < local_28) {
                                local_c = (uint32_t*)0x1;
                            }
                            if (local_c == (uint32_t*)0x0) goto LAB_00667fd7;
LAB_00668041:
                            local_74[4] = 0;
                            local_74[5] = 0;
                            local_74[6] = 0;
                            local_74[7] = 0;
                        }
                        local_2c = local_2c + 1;
                    }
                    if ((*local_14 & 0xfff00000) == 0x10000000) {
                        uVar11 = 0;
                        local_2c = 0;
                        if (local_14[3] != 0) {
                            do {
                                if (local_74[local_2c + 4] == 0) {
                                    *(uint32_t*)(local_14[4] + uVar11 * 4) =
                                        *(uint32_t*)(local_14[4] + local_2c * 4);
                                    *(uint32_t*)(local_14[2] + uVar11 * 4) =
                                        *(uint32_t*)(local_14[2] + local_2c * 4);
                                    uVar11 = uVar11 + 1;
                                }
                                else {
                                    iVar12 = uVar11 * 4;
                                    local_40 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                             *(int*)(iVar12 + local_14[4]) * 4);
                                    if (local_40[0x18] == 0) {
                                        local_40[0x18] =
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                *(int*)(iVar12 + local_14[2]) * 4) +
                                                         0x60);
                                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                            *(int*)(iVar12 + local_14[4]) * 4) +
                                                     100) =
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                *(int*)(iVar12 + local_14[2]) * 4) +
                                                         100);
                                    }
                                }
                                local_2c = local_2c + 1;
                            } while (local_2c < local_14[3]);
                        }
                        *local_14 = -(uint32_t)(uVar11 != 0) & (uVar11 & 0xfffff | 0x10000000);
                        local_14[1] = uVar11;
                        local_14[3] = uVar11;
                    }
                }
                if (local_20 == 0) break;
                uVar11 = local_20;
            } while (true);
        }
        local_10 = (uint32_t*)0x0;
    }
LAB_00667b44:
    operator_delete(local_44);
    return local_10;
}

// 0x668498 — observed shape
bool FUN_668498(void* self, int param_1)
{
    uint32_t* puVar1;
    int iVar2;
    bool bVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int* piVar7;
    int* local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    bVar3 = false;
    local_8 = 0;
    iVar4 = *(int*)((char*)self + 8);
    if (iVar4 != 0) {
        piVar7 = *(int**)((char*)self + 0x14);
        do {
            if ((*(int*)((char*)self + 0x88) == *(int*)(*piVar7 + 4)) &&
                (uVar5 = *(uint32_t*)(*piVar7 + 0xc), local_8 <= uVar5)) {
                local_8 = uVar5 + 1;
            }
            piVar7 = piVar7 + 1;
            iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
    }
    FUN_00661fbd();
    local_18 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_18 * 4);
            if ((*puVar1 & 0xfff00000) != 0) {
                uVar5 = puVar1[1] / (*puVar1 & 0xfffff);
                puVar1[9] = 0;
                local_14 = 0;
                if (uVar5 != 0) {
                    do {
                        local_10 = FUN_0065cc6f(local_14, (uint32_t**)&local_1c);
                        iVar4 = *(int*)(*(int*)((char*)self + 0x14) + *local_1c * 4);
                        if (*(int*)((char*)self + 0x88) == *(int*)(iVar4 + 4)) {
                            local_c = 1;
                            if (1 < local_10) {
                                do {
                                    iVar2 = *(int*)(*(int*)((char*)self + 0x14) +
                                                   local_1c[local_c] * 4);
                                    if ((*(int*)((char*)self + 0x88) == *(int*)(iVar2 + 4)) &&
                                        (*(int*)(iVar2 + 0x48) != *(int*)(iVar4 + 0x48))) break;
                                    local_c = local_c + 1;
                                } while (local_c < local_10);
                            }
                            if ((local_c != local_10) && (uVar6 = 0, local_10 != 0)) {
                                do {
                                    iVar4 = *(int*)(*(int*)((char*)self + 0x14) +
                                                   local_1c[uVar6] * 4);
                                    if (*(int*)((char*)self + 0x88) == *(int*)(iVar4 + 4)) {
                                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x18) +
                                                             *(int*)(iVar4 + 0x48) * 4) + 0x24) = 1;
                                    }
                                    uVar6 = uVar6 + 1;
                                } while (uVar6 < local_10);
                            }
                        }
                        local_14 = local_14 + 1;
                    } while (local_14 < uVar5);
                }
            }
            local_18 = local_18 + 1;
        } while (local_18 < *(uint32_t*)((char*)self + 0xc));
    }
    local_14 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            iVar4 = *(int*)(*(int*)((char*)self + 0x18) + local_14 * 4);
            if (((*(uint16_t*)(iVar4 + 2) & 0xfff0) != 0) && (*(int*)(iVar4 + 0x24) == 0)) {
                local_1c = *(int**)(iVar4 + 0x10);
                iVar2 = *(int*)((char*)self + 0x14);
                if (*(int*)((char*)self + 0x88) ==
                    *(int*)(*(int*)(iVar2 + *local_1c * 4) + 4)) {
                    uVar5 = *(uint32_t*)(iVar4 + 0xc);
                    uVar6 = 0;
                    if (param_1 == 0) {
                        local_18 = 0;
                        if (uVar5 != 0) {
                            do {
                                if (*(int*)(*(int*)(iVar2 + *local_1c * 4) + 0x10) == 0) break;
                                local_18 = local_18 + 1;
                                local_1c = local_1c + 1;
                            } while (local_18 < uVar5);
                        }
                        if (uVar5 <= local_18) {
                            uVar6 = 0;
                            if (uVar5 != 0) {
                                do {
                                    iVar2 = uVar6 * 4;
                                    uVar6 = uVar6 + 1;
                                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                        *(int*)(*(int*)(iVar4 + 0x10) +
                                                                iVar2) * 4) + 0xc) = local_8;
                                } while (uVar6 < *(uint32_t*)(iVar4 + 0xc));
                            }
                            goto LAB_006686ba;
                        }
                    }
                    else {
                        if (uVar5 != 0) {
                            do {
                                if (uVar6 != *(uint32_t*)(*(int*)(iVar2 + *local_1c * 4) + 0x10))
                                    break;
                                local_1c = local_1c + 1;
                                uVar6 = uVar6 + 1;
                            } while (uVar6 < uVar5);
                        }
                        if (uVar6 != uVar5) {
                            uVar6 = 0;
                            if (uVar5 != 0) {
                                do {
                                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                        *(int*)(*(int*)(iVar4 + 0x10) +
                                                                uVar6 * 4) * 4) + 0xc) = local_8;
                                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                        *(int*)(*(int*)(iVar4 + 0x10) +
                                                                uVar6 * 4) * 4) + 0x10) = uVar6;
                                    uVar6 = uVar6 + 1;
                                } while (uVar6 < *(uint32_t*)(iVar4 + 0xc));
                            }
LAB_006686ba:
                            local_8 = local_8 + 1;
                            bVar3 = true;
                        }
                    }
                }
            }
            local_14 = local_14 + 1;
        } while (local_14 < *(uint32_t*)((char*)self + 0xc));
    }
    return !bVar3;
}

// 0x6686e2 — observed shape
int FUN_6686e2(void* self)
{
    uint32_t* puVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t* puVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    int local_20;
    int local_1c;
    uint32_t local_18;
    void* local_14;
    uint32_t local_10;
    uint32_t* local_c;
    void* local_8;

    local_14 = (void*)0x0;
    local_8 = (void*)0x0;
    local_c = (uint32_t*)0x0;
    iVar3 = FUN_0065e4f2();
    if ((iVar3 < 0) || (iVar3 = FUN_00662317(), iVar3 < 0)) goto LAB_006689fc;
    if ((*(uint32_t*)((char*)self + 0x6c) & 0xc000000) != 0) {
        uVar4 = 0;
        if (*(int*)((char*)self + 0xc) != 0) {
            do {
                iVar3 = uVar4 * 4;
                uVar4 = uVar4 + 1;
                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x18) + iVar3) + 0x2c) = 0;
            } while (uVar4 < *(uint32_t*)((char*)self + 0xc));
        }
        iVar3 = *(int*)((char*)self + 0xc);
        while (iVar3 != 0) {
            iVar3 = iVar3 + -1;
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + iVar3 * 4);
            uVar4 = *puVar1 & 0xfff00000;
            if (uVar4 != 0) {
                uVar6 = puVar1[0xb];
                if (((*puVar1 & 0xf0000000) == 0x60000000) || (uVar4 == 0x11000000)) {
                    puVar1[0xb] = uVar6 + 1;
                    uVar6 = uVar6 + 2;
                }
                uVar4 = 0;
                if (puVar1[5] != 0) {
                    do {
                        iVar2 = *(int*)(*(int*)((char*)self + 0x18) + *(int*)(puVar1[6] + uVar4 * 4) * 4);
                        if (*(uint32_t*)(iVar2 + 0x2c) < uVar6) {
                            *(uint32_t*)(iVar2 + 0x2c) = uVar6;
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < puVar1[5]);
                }
            }
        }
    }
    local_1c = 0;
    local_10 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_10 * 4);
            local_18 = *puVar1 & 0xfff00000;
            if (local_18 != 0) {
                uVar4 = *(uint32_t*)puVar1[4];
                local_20 = *(int*)(*(int*)((char*)self + 0x14) + uVar4 * 4);
                if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                           *(int*)(local_20 + 4) * 4) + 4) & 8) == 0) {
                    if (((local_18 == 0x20700000) || (local_18 == 0x20800000)) ||
                        (local_18 == 0x11500000)) {
                        iVar3 = *(int*)(*(int*)((char*)self + 0x14) + *(int*)puVar1[2] * 4);
                    }
                    else {
                        iVar3 = local_20;
                    }
                    uVar4 = *(uint32_t*)(iVar3 + 0x14);
                }
                puVar1[0xd] = uVar4;
                if (uVar4 != 0xffffffff) {
                    local_1c = 1;
                }
            }
            local_10 = local_10 + 1;
        } while (local_10 < *(uint32_t*)((char*)self + 0xc));
    }
    uVar4 = 0;
    if ((*(uint8_t*)((char*)self + 0xcc) & 4) != 0) {
        return 1;
    }
    iVar3 = *(int*)((char*)self + 0xc) << 2;
    if (local_1c == 0) {
        local_10 = 0;
        local_14 = (void*)FUN_00533c78(iVar3);
        if (((local_14 == (void*)0x0) ||
             (local_8 = (void*)FUN_00533c78(*(int*)((char*)self + 0xc) << 2), local_8 == (void*)0x0)) ||
            (local_c = (uint32_t*)FUN_00533c78(*(int*)((char*)self + 0xc) << 2),
             local_c == (uint32_t*)0x0))
            goto LAB_006689f7;
        uVar6 = 0;
        if (*(int*)((char*)self + 0xc) != 0) {
            do {
                iVar3 = *(int*)(*(int*)((char*)self + 0x18) + uVar6 * 4);
                *(uint32_t*)(iVar3 + 0x38) = 0xffffffff;
                *(uint32_t*)(iVar3 + 0x24) = 0;
                if (((*(uint16_t*)(iVar3 + 2) & 0xfff0) != 0) && (*(int*)(iVar3 + 0x1c) == 0)) {
                    *(uint32_t*)((int)(intptr_t)local_14 + local_10 * 4) = uVar6;
                    local_10 = local_10 + 1;
                }
                uVar6 = uVar6 + 1;
            } while (uVar6 < *(uint32_t*)((char*)self + 0xc));
        }
        local_20 = 0;
        if (local_10 != 0) {
            do {
                iVar3 = FUN_00660e0e(*(uint32_t*)((int)(intptr_t)local_14 + uVar4 * 4), (int*)local_8,
                                     &local_20);
                if (iVar3 < 0) goto LAB_006689fc;
                uVar4 = uVar4 + 1;
            } while (uVar4 < local_10);
        }
        uVar4 = 0;
        if (*(int*)((char*)self + 0xc) != 0) {
            puVar5 = local_c;
            do {
                *puVar5 = *(uint32_t*)(*(int*)((char*)self + 0x18) +
                                       *(int*)((int)(intptr_t)puVar5 +
                                               ((int)(intptr_t)local_8 - (int)(intptr_t)local_c)) * 4);
                uVar4 = uVar4 + 1;
                puVar5 = puVar5 + 1;
            } while (uVar4 < *(uint32_t*)((char*)self + 0xc));
        }
        puVar5 = local_c;
        puVar7 = *(uint32_t**)((char*)self + 0x18);
        for (uVar4 = *(uint32_t*)((char*)self + 0xc) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar7 = *(uint8_t*)puVar5;
            puVar5 = (uint32_t*)((int)(intptr_t)puVar5 + 1);
            puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + 1);
        }
    }
    else {
        local_8 = (void*)FUN_00533c78(iVar3);
        if ((local_8 == (void*)0x0) ||
            (local_c = (uint32_t*)FUN_00533c78(*(int*)((char*)self + 0xc) << 2),
             local_c == (uint32_t*)0x0)) {
LAB_006689f7:
            iVar3 = -0x7ff8fff2;
            goto LAB_006689fc;
        }
        iVar3 = FUN_00661fbd();
        if (iVar3 < 0) goto LAB_006689fc;
        uVar4 = 0;
        if (*(int*)((char*)self + 0xc) != 0) {
            do {
                *(uint32_t*)((int)(intptr_t)local_8 + uVar4 * 4) = uVar4;
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint32_t*)((char*)self + 0xc));
        }
        FUN_0065e1b9((void*)FUN_0065deb4, (int)(intptr_t)local_8, *(uint32_t*)((char*)self + 0xc),
                     (int)(intptr_t)self);
        uVar4 = 0;
        if (*(int*)((char*)self + 0xc) != 0) {
            puVar5 = local_c;
            do {
                *puVar5 = *(uint32_t*)(*(int*)((char*)self + 0x18) +
                                       *(int*)(((int)(intptr_t)local_8 - (int)(intptr_t)local_c) +
                                               (int)(intptr_t)puVar5) * 4);
                uVar4 = uVar4 + 1;
                puVar5 = puVar5 + 1;
            } while (uVar4 < *(uint32_t*)((char*)self + 0xc));
        }
        puVar5 = local_c;
        puVar7 = *(uint32_t**)((char*)self + 0x18);
        for (uVar4 = *(uint32_t*)((char*)self + 0xc) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar7 = *(uint8_t*)puVar5;
            puVar5 = (uint32_t*)((int)(intptr_t)puVar5 + 1);
            puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + 1);
        }
        iVar3 = FUN_00662317();
        if ((iVar3 < 0) || (iVar3 = FUN_006a71d0(1), iVar3 < 0)) goto LAB_006689fc;
    }
    iVar3 = 0;
LAB_006689fc:
    operator_delete(local_14);
    operator_delete(local_8);
    operator_delete(local_c);
    return iVar3;
}

// 0x668a1e — observed shape
uint32_t FUN_668a1e(void* self)
{
    int* piVar1;
    uint32_t* puVar2;
    uint32_t uVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    uint8_t local_34[16];
    int local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    int* local_14;
    int* local_10;
    uint32_t local_c;
    uint32_t local_8;

    FUN_00661fbd();
    local_c = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            puVar2 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_c * 4);
            uVar3 = *puVar2;
            local_8 = uVar3 & 0xfff00000;
            if (local_8 != 0) {
                uVar6 = uVar3 & 0xfffff;
                local_1c = puVar2[1] / uVar6;
                if (local_8 == 0x50000000) {
                    FUN_00661d51((int*)(puVar2[2] + uVar6 * 4), local_34, uVar6, 1);
                    FUN_00661d51((int*)puVar2[2], local_34, uVar6, 0);
                }
                else if ((0xfffffff < (uVar3 & 0xf0000000)) && ((uVar3 & 0xf0000000) < 0x40000001)) {
                    FUN_00661d51((int*)puVar2[4], local_34, uVar6, 1);
                    local_8 = 0;
                    if (local_1c != 0) {
                        do {
                            FUN_00661d51((int*)(puVar2[2] + puVar2[3] * local_8 * 4), local_34, uVar6, 0);
                            local_8 = local_8 + 1;
                        } while (local_8 < local_1c);
                    }
                }
                if (((*puVar2 & 0xf0000000) == 0x20000000) &&
                    (iVar5 = FUN_0065cd09(), iVar5 != 0)) {
                    iVar5 = *(int*)((char*)self + 0x14);
                    local_24 = *(int*)(iVar5 + *(int*)puVar2[2] * 4);
                    iVar4 = *(int*)(iVar5 + ((int*)puVar2[2])[uVar6] * 4);
                    local_18 = 0xffffffff;
                    local_8 = 0xffffffff;
                    if (uVar6 == 0) {
LAB_00668b8a:
                        local_20 = *(int*)(local_24 + 4) * 4;
                        iVar5 = *(int*)(iVar4 + 4) * 4;
                        if ((*(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) + iVar5) + 4) <=
                             *(uint32_t*)(*(int*)(local_20 + *(int*)((char*)self + 0x10)) + 4)) &&
                            ((*(int*)(*(int*)(*(int*)((char*)self + 0x10) + local_20) + 4) !=
                              *(int*)(*(int*)(*(int*)((char*)self + 0x10) + iVar5) + 4) ||
                             ((*(uint32_t*)(iVar4 + 4) <= *(uint32_t*)(local_24 + 4) &&
                              ((*(uint32_t*)(local_24 + 4) != *(uint32_t*)(iVar4 + 4) ||
                               (*(uint32_t*)(iVar4 + 0xc) <= *(uint32_t*)(local_24 + 0xc))))))))) {
LAB_00668be3:
                            local_8 = 0;
                            if (uVar6 != 0) {
                                local_24 = uVar6 << 2;
                                do {
                                    uVar3 = local_8 + 1;
                                    piVar1 = (int*)(puVar2[2] + local_8 * 4);
                                    local_20 = (uint32_t)*piVar1;
                                    *piVar1 = *(int*)(local_24 + puVar2[2]);
                                    *(uint32_t*)(local_24 + puVar2[2]) = local_20;
                                    local_24 = local_24 + 4;
                                    local_8 = uVar3;
                                } while (uVar3 < uVar6);
                            }
                        }
                    }
                    else {
                        local_10 = (int*)puVar2[2];
                        local_14 = local_10 + uVar6;
                        local_20 = uVar6;
                        do {
                            uVar3 = *(uint32_t*)(*(int*)(iVar5 + *local_10 * 4) + 0x48);
                            if (uVar3 < local_18) {
                                local_18 = uVar3;
                            }
                            uVar3 = *(uint32_t*)(*(int*)(iVar5 + *local_14 * 4) + 0x48);
                            if (uVar3 < local_8) {
                                local_8 = uVar3;
                            }
                            local_10 = local_10 + 1;
                            local_14 = local_14 + 1;
                            local_20 = local_20 - 1;
                        } while (local_20 != 0);
                        local_20 = 0;
                        if (local_8 <= local_18) {
                            if (local_18 == local_8) goto LAB_00668b8a;
                            goto LAB_00668be3;
                        }
                    }
                }
            }
            local_c = local_c + 1;
        } while (local_c < *(uint32_t*)((char*)self + 0xc));
    }
    return 0;
}



// ---------------------------------------------------------------------------
// Helpers for 0x668c36 (value-pair carriers overlaid as doubles).
// ---------------------------------------------------------------------------
union U64 {
    double d;
    uint64_t q;
    struct { uint32_t lo, hi; } p;
};


// 0x668c36 — observed shape
uint32_t FUN_668c36(void* self, uint32_t* param_1, uint32_t param_2, int param_3, int* param_4,
                    uint32_t* param_5, uint32_t param_6, uint32_t param_7)
{
    int* piVar1;
    double* pdVar2;
    double dVar3;
    int iVar4;
    uint32_t* puVar5;
    int iVar6;
    uint32_t* puVar7;
    int iVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int* piVar11;
    uint32_t uVar12;
    uint32_t* puVar13;
    bool bVar14;
    uint32_t local_d0[4];
    double local_c0[4];
    double adStack_a0[4];
    U64 local_80;
    U64 local_78;
    int local_70;
    uint32_t local_6c[4];
    uint32_t* local_5c;
    uint32_t* local_58;
    U64 local_54;
    U64 local_4c;
    uint32_t* local_44;
    uint32_t local_40[4];
    uint32_t local_30;
    uint32_t local_2c;
    uint32_t local_28;
    uint32_t local_24;
    int local_20;
    uint32_t* local_1c;
    uint32_t local_18;
    int* local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    if (param_2 == 0) {
        return 1;
    }
    if (4 < param_2) {
        return 0;
    }
    uVar12 = 1;
    if (1 < param_2) {
        do {
            iVar6 = FUN_006613f9(*param_1, param_1[uVar12]);
            if (iVar6 == 0) break;
            uVar12 = uVar12 + 1;
        } while (uVar12 < param_2);
    }
    if (uVar12 != param_2) {
        puVar13 = param_1;
        puVar7 = local_40;
        for (uVar12 = param_2 & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
            *puVar7 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar7 = puVar7 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(char*)puVar7 = (char)*puVar13;
            puVar13 = (uint32_t*)((int)(intptr_t)puVar13 + 1);
            puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + 1);
        }
        local_30 = param_2 << 2;
        puVar13 = local_6c;
        for (uVar12 = param_2 & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
            *puVar13 = 0;
            puVar13 = puVar13 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(uint8_t*)puVar13 = 0;
            puVar13 = (uint32_t*)((int)(intptr_t)puVar13 + 1);
        }
        if ((param_3 == 0) || (local_20 = 0, (*param_5 & 0xfff00000) == 0x11200000)) {
            local_20 = 1;
        }
        local_10 = 0;
        local_8 = 0;
        if (param_2 != 0) {
            puVar13 = local_40;
            local_1c = puVar13;
LAB_00668cf4:
            uVar12 = *puVar13;
            local_1c = puVar13;
LAB_00668cf6:
            local_24 = uVar12;
            iVar6 = FUN_0066138f(uVar12, param_5, param_6, param_7);
            if (iVar6 != 0) {
                local_54.d = 1.0;
                local_4c.d = 0.0;
                if (uVar12 != 0xffffffff) {
                    piVar11 = *(int**)((char*)self + 0x14);
                    do {
                        if (((*(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                   *(int*)(piVar11[uVar12] + 4) * 4) + 4) & 0x100) != 0) &&
                            (*(int*)(piVar11[uVar12] + 8) == -1)) {
                            if ((local_54.d == 1.0) && (local_4c.d == 0.0)) goto LAB_00668df8;
                            piVar1 = piVar11 + uVar12;
                            uVar12 = 0;
                            bVar14 = *(int*)((char*)self + 8) == 0;
                            dVar3 = local_54.d * *(double*)(*piVar1 + 0x20) + local_4c.d;
                            if (*(int*)((char*)self + 8) == 0) goto LAB_00668dd3;
                            local_14 = piVar11;
                            goto LAB_00668d9f;
                        }
                        uVar12 = FUN_0066144c(uVar12, &local_54.d, &local_4c.d);
                    } while (uVar12 != 0xffffffff);
                    puVar13 = local_1c;
                }
            }
            goto LAB_00668e1d;
        }
LAB_00668e4b:
        if (local_10 != param_2) {
            local_c = 0;
            if (param_2 != 0) {
LAB_00668e62:
                local_58 = local_6c + local_c;
                if (local_6c[local_c] == 0) {
                    uVar12 = local_40[local_c];
                    local_5c = local_40 + local_c;
                    iVar6 = *(int*)(*(int*)((char*)self + 0x14) + uVar12 * 4);
                    if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                              *(int*)(iVar6 + 4) * 4) + 5) & 1) == 0) ||
                        (*(int*)(iVar6 + 8) != -1)) {
                        local_18 = 0xffffffff;
                        local_1c = (uint32_t*)0x0;
                        local_24 = 0;
                        local_10 = uVar12;
                        do {
                            iVar6 = FUN_0066138f(local_10, param_5, param_6, param_7);
                            if (iVar6 != 0) {
                                local_4c.d = 1.0;
                                local_54.d = 0.0;
                                for (local_28 = local_10; local_28 != 0xffffffff;
                                     local_28 = FUN_0066144c(local_28, &local_4c.d, &local_54.d)) {
                                    local_14 = (int*)0x0;
                                    local_8 = 0;
                                    if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                       local_28 * 4) + 0x48) == -1) {
                                        local_8 = 0xffffffff;
                                    }
                                    local_2c = 0;
                                    do {
                                        if (local_6c[local_2c] == 0) {
                                            puVar13 = (uint32_t*)(uintptr_t)local_40[local_2c];
                                            local_44 = puVar13;
                                            do {
                                                iVar6 = FUN_0066138f((uint32_t)(uintptr_t)puVar13,
                                                                     param_5, param_6, param_7);
                                                puVar7 = puVar13;
                                                if (iVar6 != 0) {
                                                    for (; puVar7 != (uint32_t*)0xffffffff;
                                                         puVar7 = (uint32_t*)(uintptr_t)
                                                             FUN_0066144c((uint32_t)(uintptr_t)puVar7,
                                                                          0, 0)) {
                                                        iVar6 = FUN_006613f9(local_28,
                                                                            (uint32_t)(uintptr_t)puVar7);
                                                        if (iVar6 != 0) {
                                                            local_14 = (int*)((int)(intptr_t)local_14 + 1);
                                                            if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                                (int)(intptr_t)puVar7 * 4) +
                                                                        0x48) != -1) {
                                                                iVar6 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                                        (int)(intptr_t)puVar7 * 4) +
                                                                                0x48) - (int)param_6;
                                                                local_8 = local_8 + iVar6 * iVar6;
                                                            }
LAB_00668f7d:
                                                            if (puVar7 != (uint32_t*)0xffffffff)
                                                                goto LAB_00668f97;
                                                            break;
                                                        }
                                                        if (local_20 != 0) {
                                                            puVar7 = (uint32_t*)0xffffffff;
                                                            goto LAB_00668f7d;
                                                        }
                                                    }
                                                }
                                                puVar13 = *(uint32_t**)
                                                    (*(int*)(*(int*)((char*)self + 0x14) +
                                                             (int)(intptr_t)puVar13 * 4) + 0x34);
                                            } while (local_44 != puVar13);
                                        }
LAB_00668f97:
                                        local_2c = local_2c + 1;
                                    } while (local_2c < param_2);
                                    if ((local_1c < (uint32_t*)(uintptr_t)local_14) ||
                                        ((local_1c == (uint32_t*)(uintptr_t)local_14 &&
                                          (local_24 < local_8)))) {
                                        local_78.d = local_4c.d;
                                        local_1c = (uint32_t*)(uintptr_t)local_14;
                                        local_80.d = local_54.d;
                                        local_18 = local_28;
                                        local_24 = local_8;
                                    }
                                    if (local_20 != 0) break;
                                }
                            }
                            uVar12 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                            local_10 * 4) + 0x34);
                            if (*local_5c == uVar12) goto LAB_00669012;
                            local_10 = uVar12;
                        } while (true);
                    }
                }
                goto LAB_00669109;
            }
LAB_0066911a:
            uVar12 = 0;
            bVar14 = false;
            local_14 = (int*)0x0;
            local_1c = (uint32_t*)0x0;
            local_2c = 0;
            if (param_2 != 0) {
                do {
                    iVar6 = *(int*)(*(int*)((char*)self + 0x14) + local_40[uVar12] * 4);
                    iVar8 = FUN_006613f9(local_40[uVar12], local_40[0]);
                    if (iVar8 == 0) {
                        bVar14 = true;
                    }
                    if (local_c0[uVar12] != 1.0) {
                        local_14 = (int*)0x1;
                    }
                    if (adStack_a0[uVar12] != 0.0) {
                        local_1c = (uint32_t*)0x1;
                    }
                    if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                              *(int*)(iVar6 + 4) * 4) + 5) & 1) != 0) &&
                        (*(int*)(iVar6 + 8) == -1)) {
                        local_2c = 1;
                    }
                    uVar12 = uVar12 + 1;
                } while (uVar12 < param_2);
                if (((local_14 != (int*)0x0) || (local_1c != (uint32_t*)0x0)) || (bVar14)) {
                    if (local_20 == 0) {
                        param_7 = 0;
                        local_c = 0;
                        local_10 = (*(int*)((char*)self + 0x6c) << 0x1d) >> 0x1f;
                        param_6 = 0;
                        do {
                            iVar6 = *(int*)(*(int*)((char*)self + 0x14) + local_40[local_c] * 4);
                            uVar12 = 0;
                            if ((local_10 == 0) && ((*(uint8_t*)((char*)self + 0x6c) & 2) == 0)) {
                                iVar8 = *(int*)(iVar6 + 4);
                                if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                            iVar8 * 4) + 5) & 1) == 0) ||
                                    (*(int*)(iVar6 + 8) != -1)) {
                                    if (param_6 != 0) {
                                        do {
                                            iVar4 = *(int*)(*(int*)((char*)self + 0x14) +
                                                           local_40[uVar12] * 4);
                                            if (((*(double*)((char*)local_c0 + param_6) ==
                                                 local_c0[uVar12]) &&
                                                (*(double*)((char*)adStack_a0 + param_6) ==
                                                 adStack_a0[uVar12])) &&
                                               ((iVar8 == *(int*)(iVar4 + 4) &&
                                                 (((*(int*)(iVar6 + 8) == *(int*)(iVar4 + 8) &&
                                                   (*(int*)(iVar6 + 0xc) == *(int*)(iVar4 + 0xc))) &&
                                                  (*(int*)(iVar6 + 0x10) == *(int*)(iVar4 + 0x10)))))))
                                                break;
                                            uVar12 = uVar12 + 1;
                                        } while (uVar12 < local_c);
                                    }
                                }
                                else if (param_6 != 0) {
                                    do {
                                        iVar4 = *(int*)(*(int*)((char*)self + 0x14) +
                                                       local_40[uVar12] * 4);
                                        if (((iVar8 == *(int*)(iVar4 + 4)) &&
                                             (*(int*)(iVar4 + 8) == -1)) &&
                                            (*(double*)(iVar6 + 0x20) == *(double*)(iVar4 + 0x20)))
                                            break;
                                        uVar12 = uVar12 + 1;
                                    } while (uVar12 < local_c);
                                }
                            }
                            else {
                                uVar12 = local_c;
                            }
                            local_d0[local_c] = uVar12;
                            uVar10 = local_30;
                            if (local_c == uVar12) {
                                param_7 = param_7 + 1;
                            }
                            param_6 = param_6 + 8;
                            local_c = local_c + 1;
                        } while (local_c < param_2);
                        local_24 = 0xffffffff;
                        bVar14 = true;
                        local_8 = 0;
                        local_c = 0;
                        do {
                            if (local_c == local_d0[local_c]) {
                                iVar6 = *(int*)(*(int*)((char*)self + 0x14) +
                                               local_40[local_c] * 4);
                                if (*(int*)((char*)self + 0x88) == *(int*)(iVar6 + 4)) {
                                    local_18 = param_7;
                                    uVar12 = 0;
                                    do {
                                        if (((uVar12 == local_d0[uVar12]) &&
                                             (iVar8 = *(int*)(*(int*)((char*)self + 0x14) +
                                                             local_40[uVar12] * 4),
                                              *(int*)((char*)self + 0x88) == *(int*)(iVar8 + 4))) &&
                                            ((*(int*)(iVar6 + 0xc) == *(int*)(iVar8 + 0xc) &&
                                              ((local_c0[uVar12] == 1.0 &&
                                                (adStack_a0[uVar12] == 0.0)))))) {
                                            local_18 = local_18 - 1;
                                        }
                                        uVar12 = uVar12 + 1;
                                    } while (uVar12 < param_2);
                                    if ((*(int*)(param_3 + *(int*)(iVar6 + 0xc) * 4) + local_18 < 5) &&
                                        (local_18 < local_24)) {
                                        bVar14 = false;
                                        local_24 = local_18;
                                        local_8 = local_c;
                                    }
                                }
                            }
                            local_c = local_c + 1;
                        } while (local_c < param_2);
                        if ((((local_10 != 0) || ((*(uint8_t*)((char*)self + 0x6c) & 2) != 0)) &&
                             (0xfffffff < (*param_5 & 0xf0000000))) &&
                            ((*param_5 & 0xf0000000) < 0x40000001)) {
                            local_10 = 0;
                            do {
                                if (bVar14) break;
                                iVar6 = *(int*)((char*)self + 0x14);
                                iVar8 = *(int*)(iVar6 + local_40[local_10] * 4);
                                if ((((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                            *(int*)(iVar8 + 4) * 4) + 5) & 1) == 0) ||
                                     (*(int*)(iVar8 + 8) == -1)) &&
                                    (*(int*)(iVar8 + 0x10) !=
                                     *(int*)(*(int*)(iVar6 + *(int*)(local_10 * 4 + param_5[4]) * 4) +
                                             0x10))) {
                                    local_18 = 0;
                                    param_7 = 0;
                                    do {
                                        iVar4 = *(int*)(iVar6 + local_40[param_7] * 4);
                                        if (((*(int*)(iVar4 + 4) == *(int*)(iVar8 + 4)) &&
                                             (*(int*)(iVar4 + 0xc) == *(int*)(iVar8 + 0xc))) &&
                                            (*(int*)(iVar4 + 8) == *(int*)(iVar8 + 8))) {
                                            local_18 = local_18 + 1;
                                        }
                                        param_7 = param_7 + 1;
                                    } while (param_7 < param_2);
                                    if (1 < local_18) {
                                        bVar14 = true;
                                    }
                                }
                                local_10 = local_10 + 1;
                            } while (local_10 < param_2);
                        }
                        uVar12 = *param_5 & 0xfff00000;
                        if (((((uVar12 == 0x10000000) &&
                               ((*(uint8_t*)((char*)self + 0x6c) & 8) == 0)) &&
                              ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                        *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                       *(int*)param_5[4] * 4) + 4) * 4) +
                                        4) & 0x20) != 0)) ||
                             ((uVar12 == 0x11200000 || (uVar12 != 0x10000000)))) ||
                            ((local_14 != (int*)0x0 ||
                              ((local_1c != (uint32_t*)0x0 || (local_2c != 0)))))) {
                            local_70 = -1;
                            if (bVar14) {
                                iVar6 = *param_4;
                                *param_4 = iVar6 + 1;
                            }
                            else {
                                iVar6 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                      local_40[local_8] * 4) + 0xc);
                            }
                            iVar8 = *(int*)(*(int*)((char*)self + 0x14) +
                                           *(int*)param_5[4] * 4);
                            local_58 = (uint32_t*)*(uint32_t*)(iVar8 + 0x14);
                            local_5c = (uint32_t*)*(uint32_t*)(iVar8 + 0x18);
                            puVar13 = local_6c;
                            for (uVar12 = local_30 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                                *puVar13 = 0;
                                puVar13 = puVar13 + 1;
                            }
                            for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                                *(uint8_t*)puVar13 = 0;
                                puVar13 = (uint32_t*)((int)(intptr_t)puVar13 + 1);
                            }
                            local_1c = (uint32_t*)(uintptr_t)iVar6;
                            uVar12 = 0;
                            do {
                                if ((uVar12 != local_d0[uVar12]) ||
                                    ((((iVar8 = *(int*)(*(int*)((char*)self + 0x14) +
                                                    local_40[uVar12] * 4),
                                        *(int*)((char*)self + 0x88) == *(int*)(iVar8 + 4) &&
                                        (iVar6 == *(int*)(iVar8 + 0xc))) &&
                                       (local_c0[uVar12] == 1.0)) &&
                                      (adStack_a0[uVar12] == 0.0)))) {
                                    local_6c[uVar12] = 1;
                                }
                                uVar12 = uVar12 + 1;
                            } while (uVar12 < param_2);
                            if (!bVar14) {
                                local_c = 0;
                                do {
                                    if (local_6c[local_c] == 0) {
                                        uVar12 = local_40[local_c];
                                        iVar6 = *(int*)(*(int*)((char*)self + 0x14) + uVar12 * 4);
                                        if (*(int*)((char*)self + 0x88) == *(int*)(iVar6 + 4)) {
                                            local_14 = (int*)0x0;
                                            local_18 = 0;
                                            param_6 = 0;
                                            do {
                                                if (local_6c[param_6] == 0) {
                                                    local_14 = (int*)((int)(intptr_t)local_14 + 1);
                                                    iVar8 = FUN_006613f9(uVar12, local_40[param_6]);
                                                    if ((iVar8 != 0) &&
                                                        ((local_18 = local_18 + 1,
                                                          local_c0[param_6] != 1.0 ||
                                                          (adStack_a0[param_6] != 0.0)))) break;
                                                }
                                                param_6 = param_6 + 1;
                                            } while (param_6 < param_2);
                                            if (param_2 <= param_6) {
                                                iVar6 = *(int*)(iVar6 + 0xc);
                                                piVar11 = (int*)(param_3 + (int)(intptr_t)local_1c * 4);
                                                if ((*(int*)(param_3 + iVar6 * 4) - local_18) +
                                                        *piVar11 + (int)(intptr_t)local_14 < 5) {
                                                    uVar12 = 0;
                                                    do {
                                                        if (((local_6c[uVar12] == 0) &&
                                                             (iVar8 = *(int*)(*(int*)((char*)self + 0x14) +
                                                                             local_40[uVar12] * 4),
                                                              *(int*)((char*)self + 0x88) ==
                                                                  *(int*)(iVar8 + 4))) &&
                                                            (iVar6 == *(int*)(iVar8 + 0xc))) {
                                                            local_6c[uVar12] = 1;
                                                        }
                                                        uVar12 = uVar12 + 1;
                                                    } while (uVar12 < param_2);
                                                    uVar12 = 0;
                                                    if (*(int*)((char*)self + 8) != 0) {
                                                        do {
                                                            iVar8 = *(int*)(*(int*)((char*)self + 0x14) +
                                                                           uVar12 * 4);
                                                            if ((*(int*)((char*)self + 0x88) ==
                                                                 *(int*)(iVar8 + 4)) &&
                                                                (iVar6 == *(int*)(iVar8 + 0xc))) {
                                                                *(uint32_t**)(iVar8 + 0xc) = local_1c;
                                                                *(int*)(iVar8 + 0x10) =
                                                                    *(int*)(iVar8 + 0x10) + *piVar11;
                                                            }
                                                            uVar12 = uVar12 + 1;
                                                        } while (uVar12 < *(uint32_t*)((char*)self + 8));
                                                    }
                                                    piVar1 = (int*)(param_3 + iVar6 * 4);
                                                    *piVar11 = *piVar11 + *piVar1;
                                                    *piVar1 = 0;
                                                }
                                            }
                                        }
                                    }
                                    local_c = local_c + 1;
                                } while (local_c < param_2);
                            }
                            if ((*(uint8_t*)((char*)self + 0x6c) & 6) == 0) {
                                local_c = 0;
                                do {
                                    if (local_6c[local_c] == 0) {
                                        puVar13 = local_40 + local_c;
                                        uVar12 = *puVar13;
                                        iVar6 = *(int*)(*(int*)((char*)self + 0x14) + uVar12 * 4);
                                        if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                  *(int*)(iVar6 + 4) * 4) + 5) & 1) == 0) ||
                                            (*(int*)(iVar6 + 8) != -1)) {
                                            param_6 = 0;
                                            param_7 = 0;
                                            do {
                                                if ((local_6c[param_7] == 0) &&
                                                    (iVar6 = FUN_006613f9(uVar12,
                                                                          local_40[param_7]), iVar6 != 0)) {
                                                    param_6 = param_6 + 1;
                                                }
                                                param_7 = param_7 + 1;
                                            } while (param_7 < param_2);
                                            param_7 = 0;
                                            do {
                                                if (3 < param_6) break;
                                                if (local_6c[param_7] == 0) {
                                                    iVar6 = *(int*)(*(int*)((char*)self + 0x14) +
                                                                   local_40[param_7] * 4);
                                                    if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                              *(int*)(iVar6 + 4) * 4) +
                                                                      5) & 1) != 0) &&
                                                        (*(int*)(iVar6 + 8) == -1)) {
                                                        dVar3 = *(double*)(iVar6 + 0x20);
                                                        local_40[param_7] = *puVar13;
                                                        param_6 = param_6 + 1;
                                                        adStack_a0[param_7] =
                                                            dVar3 * local_c0[param_7] + adStack_a0[param_7];
                                                        local_c0[param_7] = 0.0;
                                                    }
                                                }
                                                param_7 = param_7 + 1;
                                            } while (param_7 < param_2);
                                        }
                                    }
                                    local_c = local_c + 1;
                                } while (local_c < param_2);
                            }
                            local_c = 0;
                            do {
                                uVar12 = 0;
                                if (local_6c[local_c] == 0) {
                                    uVar10 = local_40[local_c];
                                    local_80.p.hi = uVar10;
                                    param_7 = 0;
                                    local_28 = 0;
                                    local_18 = 1;
                                    local_20 = 0;
                                    local_30 = 1;
                                    do {
                                        if ((local_6c[uVar12] == 0) &&
                                            (iVar6 = FUN_006613f9(uVar10, local_40[uVar12]), iVar6 != 0)) {
                                            param_7 = param_7 + 1;
                                            pdVar2 = local_c0 + uVar12;
                                            if (*pdVar2 != 1.0) {
                                                local_28 = 1;
                                            }
                                            if (*pdVar2 != -1.0) {
                                                local_18 = 0;
                                            }
                                            if (adStack_a0[uVar12] != 0.0) {
                                                local_20 = 1;
                                            }
                                            if (*pdVar2 != 0.0) {
                                                local_30 = 0;
                                            }
                                        }
                                        uVar12 = uVar12 + 1;
                                    } while (uVar12 < param_2);
                                    if (local_30 != 0) {
                                        local_28 = 0;
                                        local_20 = 0;
                                    }
                                    if (local_28 == 0) {
LAB_006698f8:
                                        if (local_20 != 0) goto LAB_006698fd;
LAB_00669943:
                                        if ((local_28 == 0) && (local_20 == 0)) {
                                            local_24 = FUN_0065da35(param_7 & 0xfffff | 0x10000000,
                                                                    0xffffffff, 0xffffffff);
                                            if (local_24 == 0xffffffff) {
                                                return 0;
                                            }
                                            local_2c = *(uint32_t*)(*(int*)((char*)self + 0x18) +
                                                                    local_24 * 4);
                                            local_10 = local_24;
                                            local_8 = local_2c;
                                            FUN_0065cc50();
                                        }
                                    }
                                    else {
                                        if (local_18 == 0) {
                                            uVar12 = param_7 & 0xfffff | 0x20500000;
                                        }
                                        else {
                                            uVar12 = param_7 & 0xfffff | 0x10100000;
                                        }
                                        uVar12 = FUN_0065da35(uVar12, 0xffffffff, 0xffffffff);
                                        if (uVar12 == 0xffffffff) {
                                            return 0;
                                        }
                                        uVar10 = *(uint32_t*)(*(int*)((char*)self + 0x18) + uVar12 * 4);
                                        local_2c = uVar10;
                                        local_10 = uVar12;
                                        FUN_0065cc50();
                                        if (local_20 == 0) {
                                            local_24 = uVar12;
                                            local_8 = uVar10;
                                            goto LAB_006698f8;
                                        }
LAB_006698fd:
                                        uVar12 = FUN_0065da35(param_7 & 0xfffff | 0x20400000,
                                                              0xffffffff, 0xffffffff);
                                        if (uVar12 == 0xffffffff) {
                                            return 0;
                                        }
                                        uVar10 = *(uint32_t*)(*(int*)((char*)self + 0x18) + uVar12 * 4);
                                        local_24 = uVar12;
                                        local_8 = uVar10;
                                        FUN_0065cc50();
                                        if (local_28 == 0) {
                                            local_10 = uVar12;
                                            local_2c = uVar10;
                                            goto LAB_00669943;
                                        }
                                    }
                                    local_14 = (int*)(uintptr_t)(param_7 << 2);
                                    iVar6 = 0;
                                    param_6 = 0;
                                    local_4c.p.hi = (uint32_t)((int)(intptr_t)param_1 -
                                                               (int)(intptr_t)local_40);
                                    do {
                                        local_54.p.hi = (uint32_t)(intptr_t)(local_6c + param_6);
                                        if (local_6c[param_6] == 0) {
                                            local_44 = local_40 + param_6;
                                            uVar12 = *local_44;
                                            iVar8 = FUN_006613f9(local_80.p.hi, uVar12);
                                            if (iVar8 != 0) {
                                                if (local_30 != 0) {
                                                    uVar12 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78),
                                                                         0, 0, adStack_a0[param_6]);
                                                }
                                                uVar10 = local_2c;
                                                if (uVar12 == 0xffffffff) {
                                                    return 0;
                                                }
                                                iVar8 = *(int*)(*(int*)((char*)self + 0x14) +
                                                                uVar12 * 4);
                                                *(uint32_t*)(iVar6 + *(int*)(local_2c + 8)) = uVar12;
                                                local_78.p.hi = (uint32_t)iVar8;
                                                if (local_30 != 0) {
                                                    *(uint32_t*)(iVar8 + 0x34) = uVar12;
                                                }
                                                if (local_28 == 0) {
LAB_00669b05:
                                                    uVar12 = 0;
                                                    if (local_20 != 0) {
                                                        bVar14 = *(int*)((char*)self + 8) == 0;
                                                        if (*(int*)((char*)self + 8) != 0) {
                                                            piVar11 = *(int**)((char*)self + 0x14);
                                                            do {
                                                                iVar8 = *piVar11;
                                                                if (((*(int*)((char*)self + 0x78) ==
                                                                      *(int*)(iVar8 + 4)) &&
                                                                     (*(int*)(iVar8 + 8) == -1)) &&
                                                                    (*(double*)(iVar8 + 0x20) ==
                                                                     adStack_a0[param_6])) break;
                                                                uVar12 = uVar12 + 1;
                                                                piVar11 = piVar11 + 1;
                                                            } while (uVar12 < *(uint32_t*)((char*)self + 8));
                                                            bVar14 = uVar12 == *(uint32_t*)((char*)self + 8);
                                                        }
                                                        if (bVar14) {
                                                            uVar12 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78),
                                                                                  0, 0,
                                                                                  adStack_a0[param_6]);
                                                            if (uVar12 == 0xffffffff) {
                                                                return 0;
                                                            }
                                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                                uVar12 * 4) + 0x34) = uVar12;
                                                        }
                                                        *(uint32_t*)((int)(intptr_t)local_14 +
                                                                     *(int*)(local_8 + 8)) = uVar12;
                                                    }
                                                }
                                                else {
                                                    if (local_18 == 0) {
                                                        uVar9 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78),
                                                                             0, 0, local_c0[param_6]);
                                                        *(uint32_t*)((int)(intptr_t)local_14 +
                                                                     *(int*)(uVar10 + 8)) = uVar9;
                                                        if (*(int*)((int)(intptr_t)local_14 +
                                                                    *(int*)(uVar10 + 8)) == -1) {
                                                            return 0;
                                                        }
                                                    }
                                                    if (local_20 != 0) {
                                                        if (local_70 == -1) {
                                                            local_70 = *param_4;
                                                            *param_4 = local_70 + 1;
                                                        }
                                                        puVar13 = (uint32_t*)(param_3 + local_70 * 4);
                                                        uVar12 = *puVar13;
                                                        *puVar13 = uVar12 + 1;
                                                        iVar8 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88),
                                                                             local_70, uVar12, 0);
                                                        if (iVar8 == -1) {
                                                            return 0;
                                                        }
                                                        if (4 < *puVar13) {
                                                            FUN_006626da();
                                                        }
                                                        puVar13 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                                                iVar8 * 4);
                                                        puVar13[5] = (uint32_t)(uintptr_t)local_58;
                                                        puVar13[6] = (uint32_t)(uintptr_t)local_5c;
                                                        *puVar13 = local_78.p.hi & 0xe000000;
                                                        puVar13[0x12] = local_10;
                                                        *(int*)(iVar6 + *(int*)(local_8 + 8)) = iVar8;
                                                        *(int*)(iVar6 + *(int*)(local_2c + 0x10)) = iVar8;
                                                        goto LAB_00669b05;
                                                    }
                                                }
                                                puVar13 = (uint32_t*)(param_3 + (int)(intptr_t)local_1c * 4);
                                                uVar12 = *puVar13;
                                                *puVar13 = uVar12 + 1;
                                                iVar8 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88),
                                                                     (uint32_t)(intptr_t)local_1c,
                                                                     uVar12, 0);
                                                if (iVar8 == -1) {
                                                    return 0;
                                                }
                                                if (4 < *puVar13) {
                                                    FUN_006626da();
                                                }
                                                puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                                       iVar8 * 4);
                                                puVar5[5] = (uint32_t)(uintptr_t)local_58;
                                                puVar5[6] = (uint32_t)(uintptr_t)local_5c;
                                                piVar11 = (int*)(uintptr_t)
                                                    (local_4c.p.hi + (uint32_t)(intptr_t)local_44);
                                                *puVar5 = **(uint32_t**)
                                                    (*(int*)((char*)self + 0x14) + *piVar11 * 4);
                                                puVar5[0x12] = local_24;
                                                *(int*)(iVar6 + *(int*)(local_8 + 0x10)) = iVar8;
                                                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                    iVar8 * 4) + 0x34) =
                                                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                        *piVar11 * 4) + 0x34);
                                                *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                               *piVar11 * 4) + 0x34) = iVar8;
                                                *local_44 = *(uint32_t*)(iVar6 +
                                                                         *(int*)(local_8 + 0x10));
                                                iVar6 = iVar6 + 4;
                                                local_14 = (int*)((int)(intptr_t)local_14 + 4);
                                                *(uint32_t*)(uintptr_t)local_54.p.hi = 1;
                                            }
                                        }
                                        param_6 = param_6 + 1;
                                    } while (param_6 < param_2);
                                }
                                local_c = local_c + 1;
                                if (param_2 <= local_c) {
                                    iVar6 = (int)(intptr_t)local_d0 - (int)(intptr_t)param_1;
                                    uVar12 = param_2;
                                    do {
                                        *param_1 = local_40[*(int*)(iVar6 + (int)(intptr_t)param_1)];
                                        param_1 = param_1 + 1;
                                        uVar12 = uVar12 - 1;
                                    } while (uVar12 != 0);
                                    uVar12 = 0;
                                    do {
                                        if (local_6c[uVar12] == 0) {
                                            return 0;
                                        }
                                        uVar12 = uVar12 + 1;
                                    } while (uVar12 < param_2);
                                    return 1;
                                }
                            } while (true);
                        }
                        puVar13 = local_40;
                        for (uVar12 = local_30 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                            *param_1 = *puVar13;
                            puVar13 = puVar13 + 1;
                            param_1 = param_1 + 1;
                        }
                        for (local_30 = local_30 & 3; local_30 != 0; local_30 = local_30 - 1) {
                            *(char*)param_1 = (char)*puVar13;
                            puVar13 = (uint32_t*)((int)(intptr_t)puVar13 + 1);
                            param_1 = (uint32_t*)((int)(intptr_t)param_1 + 1);
                        }
                    }
                    return 0;
                }
            }
        }
        puVar13 = local_40;
        for (uVar12 = local_30 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
            *param_1 = *puVar13;
            puVar13 = puVar13 + 1;
            param_1 = param_1 + 1;
        }
        for (local_30 = local_30 & 3; local_30 != 0; local_30 = local_30 - 1) {
            *(char*)param_1 = (char)*puVar13;
            puVar13 = (uint32_t*)((int)(intptr_t)puVar13 + 1);
            param_1 = (uint32_t*)((int)(intptr_t)param_1 + 1);
        }
    }
    return 1;
    while (true) {
        local_14 = local_14 + 1;
        uVar12 = uVar12 + 1;
        if (*(uint32_t*)((char*)self + 8) <= uVar12) break;
LAB_00668d9f:
        iVar6 = *local_14;
        if ((((*(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                  *(int*)(iVar6 + 4) * 4) + 4) & 0x100) != 0) &&
             (*(int*)(iVar6 + 8) == -1)) && (dVar3 == *(double*)(iVar6 + 0x20))) break;
    }
    bVar14 = uVar12 == *(uint32_t*)((char*)self + 8);
LAB_00668dd3:
    if ((bVar14) &&
        (uVar12 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78), 0, 0, dVar3), uVar12 == 0xffffffff)) {
        return 0;
    }
LAB_00668df8:
    uVar10 = local_8;
    puVar13 = local_1c;
    local_10 = local_10 + 1;
    local_c0[local_8] = 1.0;
    adStack_a0[uVar10] = 0.0;
    *puVar13 = uVar12;
    if (uVar12 != 0xffffffff) goto LAB_00668e34;
LAB_00668e1d:
    uVar12 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + local_24 * 4) + 0x34);
    if (*puVar13 == uVar12) goto LAB_00668e34;
    goto LAB_00668cf6;
LAB_00668e34:
    local_8 = local_8 + 1;
    puVar13 = puVar13 + 1;
    local_1c = puVar13;
    if (param_2 <= local_8) goto LAB_00668e4b;
    goto LAB_00668cf4;
LAB_00669012:
    if (local_18 == 0xffffffff) {
        return 0;
    }
    *local_5c = local_18;
    uVar12 = local_c;
    local_8 = 0;
    local_c0[local_c] = local_78.d;
    adStack_a0[uVar12] = local_80.d;
    *local_58 = 1;
    do {
        local_44 = local_6c + local_8;
        if (local_6c[local_8] == 0) {
            puVar13 = local_40 + local_8;
            uVar12 = *puVar13;
            do {
                local_10 = uVar12;
                iVar6 = FUN_0066138f(uVar12, param_5, param_6, param_7);
                if (iVar6 != 0) {
                    local_54.d = 1.0;
                    local_4c.d = 0.0;
                    for (uVar12 = local_10; uVar12 != 0xffffffff;
                         uVar12 = FUN_0066144c(uVar12, &local_54.d, &local_4c.d)) {
                        iVar6 = FUN_006613f9(local_18, uVar12);
                        uVar10 = local_8;
                        if (iVar6 != 0) {
                            local_c0[local_8] = local_54.d;
                            *puVar13 = uVar12;
                            adStack_a0[uVar10] = local_4c.d;
                            *local_44 = 1;
LAB_006690e1:
                            if (uVar12 != 0xffffffff) goto LAB_006690fa;
                            break;
                        }
                        if (local_20 != 0) {
                            uVar12 = 0xffffffff;
                            goto LAB_006690e1;
                        }
                    }
                }
                uVar12 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + local_10 * 4) + 0x34);
            } while (*puVar13 != uVar12);
        }
LAB_006690fa:
        local_8 = local_8 + 1;
    } while (local_8 < param_2);
LAB_00669109:
    local_c = local_c + 1;
    if (param_2 <= local_c) goto LAB_0066911a;
    goto LAB_00668e62;
}

// ---------------------------------------------------------------------------
// Register-allocation / expression-tree passes.
// ---------------------------------------------------------------------------
extern int FUN_00661891(int* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                        uint32_t* param_5, uint32_t param_6);
extern int FUN_669c99(void* self, int* param_1, uint32_t param_2, uint32_t param_3, int param_4,
                      uint32_t param_5);
extern int FUN_00666617(uint32_t* param_1, uint32_t param_2, uint32_t* param_3, uint32_t* param_4,
                        int param_5);

// 0x669c99 — finds a spare physical register for one active value.
int FUN_669c99(void* self, int* param_1, uint32_t param_2, uint32_t param_3, int param_4,
               uint32_t param_5)
{
    uint32_t* puVar1;
    int iVar2;
    int* piVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int iVar8;
    int* piVar9;
    uint32_t* puVar10;
    int local_40;
    uint32_t uStack_3c;
    uint32_t uStack_38;
    uint32_t uStack_34;
    int local_30[4];
    int local_20;
    uint32_t local_1c;
    int local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    int local_8;

    piVar3 = param_1;
    iVar5 = *(int*)(*(int*)(*(int*)((int)(intptr_t)self + 0x14) + param_2 * 4) + 0x38);
    if (iVar5 != -1) {
        param_2 = (uint32_t)iVar5;
    }
    iVar5 = *(int*)(*(int*)((int)(intptr_t)self + 0x14) + param_2 * 4);
    local_18 = iVar5;
    if (((*param_1 == *(int*)(iVar5 + 4)) &&
         (iVar4 = *(int*)(iVar5 + 0xc) * 4, *(int*)(iVar4 + param_1[4]) == -1)) &&
        (((uint32_t)param_1[1] <= *(uint32_t*)(iVar4 + param_1[2]) ||
          ((uint32_t)param_1[1] <= *(uint32_t*)(iVar4 + param_1[3]))))) {
        local_10 = 0xffffffff;
        local_c = 0xffffffff;
        local_8 = (int)(intptr_t)self;
        if (param_5 == 0xffffffff) {
            param_5 = 0;
            if (param_1[0xb] != 0) {
                do {
                    uVar7 = *(uint32_t*)(piVar3[8] + param_5 * 4);
                    param_1 = (int*)0x0;
                    iVar5 = *(int*)(local_18 + 0xc) * 4;
                    local_1c = *(uint32_t*)(piVar3[0xf] + iVar5);
                    local_20 = piVar3[0x11] + *(int*)(piVar3[0x10] + iVar5) * 4;
                    local_14 = uVar7;
                    if (local_1c == 0) {
LAB_00669d7e:
                        if (param_4 != -1) {
                            param_1 = (int*)0x0;
                            iVar5 = *(int*)(*(int*)(*(int*)(local_8 + 0x14) + param_4 * 4) + 0xc) * 4;
                            uVar6 = *(uint32_t*)(iVar5 + piVar3[0xf]);
                            if (uVar6 != 0) {
                                do {
                                    if (uVar7 == *(uint32_t*)(piVar3[4] +
                                                             *(int*)(piVar3[0x11] +
                                                                     *(int*)(iVar5 + piVar3[0x10]) * 4 +
                                                                     (int)(intptr_t)param_1 * 4) * 4))
                                        break;
                                    param_1 = (int*)((int)(intptr_t)param_1 + 1);
                                } while (param_1 < (int*)(uintptr_t)uVar6);
                                if (param_1 < (int*)(uintptr_t)uVar6) goto LAB_00669df4;
                            }
                        }
                        uVar6 = FUN_00661891(piVar3, param_2, uVar7, param_3,
                                             (uint32_t*)&local_40, local_c);
                        if (uVar6 < local_c) {
                            local_30[0] = local_40;
                            local_30[1] = uStack_3c;
                            local_30[2] = uStack_38;
                            local_30[3] = uStack_34;
                            local_10 = uVar7;
                            local_c = uVar6;
                            if (uVar6 == 0) {
                                iVar5 = local_18;
                                break;
                            }
                        }
                    }
                    else {
                        do {
                            if (uVar7 == *(uint32_t*)(piVar3[4] +
                                                     *(int*)(local_20 + (int)(intptr_t)param_1 * 4) * 4))
                                break;
                            param_1 = (int*)((int)(intptr_t)param_1 + 1);
                        } while (param_1 < (int*)(uintptr_t)local_1c);
                        if (local_1c <= (uint32_t)(uintptr_t)param_1) goto LAB_00669d7e;
                    }
LAB_00669df4:
                    param_5 = param_5 + 1;
                    iVar5 = local_18;
                } while (param_5 < (uint32_t)piVar3[0xb]);
                goto LAB_00669e2c;
            }
        }
        else {
            local_10 = *(uint32_t*)(param_1[8] + param_5 * 4);
            local_c = FUN_00661891(param_1, param_2, local_10, param_3, (uint32_t*)local_30,
                                   0xffffffff);
LAB_00669e2c:
            if (local_c != 0xffffffff) {
                *(uint32_t*)(piVar3[4] + *(int*)(iVar5 + 0xc) * 4) = local_10;
                if (((*(uint8_t*)(local_8 + 0xcc) & 4) != 0) && (local_10 < (uint32_t)piVar3[9])) {
                    uVar7 = 0;
                    for (puVar10 = (uint32_t*)piVar3[8];
                         uVar7 = uVar7 + 1, *puVar10 != local_10;
                         puVar10 = puVar10 + 1) {
                    }
                    if (uVar7 < (uint32_t)piVar3[9]) {
                        do {
                            puVar1 = (uint32_t*)(piVar3[8] + uVar7 * 4);
                            uVar7 = uVar7 + 1;
                            puVar1[-1] = *puVar1;
                        } while (uVar7 < (uint32_t)piVar3[9]);
                    }
                    *(uint32_t*)(piVar3[8] - 4 + piVar3[9] * 4) = local_10;
                }
                param_2 = 0;
                do {
                    iVar8 = (param_2 + *(int*)(iVar5 + 0xc) * 4) * 4;
                    iVar4 = *(int*)(iVar8 + piVar3[6]);
                    if (iVar4 != -1) {
                        iVar2 = local_30[param_2];
                        *(int*)(iVar8 + piVar3[5]) = iVar2;
                        piVar9 = (int*)(piVar3[7] + (iVar2 + local_10 * 4) * 4);
                        if (*piVar9 != -1) {
                            do {
                                if (*(uint32_t*)(*(int*)(*(int*)(local_8 + 0x14) + *piVar9 * 4) + 0x58) <=
                                    *(uint32_t*)(*(int*)(*(int*)(local_8 + 0x14) + iVar4 * 4) + 0x58))
                                    break;
                                piVar9 = (int*)(*(int*)(*piVar9 * 4 + *(int*)(local_8 + 0x14)) + 0x30);
                            } while (*piVar9 != -1);
                        }
                        *(int*)(*(int*)(*(int*)(local_8 + 0x14) + iVar4 * 4) + 0x30) = *piVar9;
                        *piVar9 = iVar4;
                    }
                    param_2 = param_2 + 1;
                } while (param_2 < 4);
                goto LAB_00669f3c;
            }
        }
        if ((*(uint8_t*)((char*)piVar3 + 0x18) & 2) != 0) {
            FUN_006626da(local_8, *(uint32_t*)(piVar3[0x17] + 0x3c), 0xfa4,
                         "program too complex; there are more active values than registers");
        }
        iVar5 = -0x7fffbffb;
    }
    else {
LAB_00669f3c:
        if ((*(int*)(iVar5 + 8) == -1) ||
            (iVar5 = FUN_669c99(self, piVar3, *(uint32_t*)(iVar5 + 8), 0, -1, 0xffffffff),
             -1 < iVar5)) {
            iVar5 = 0;
        }
    }
    return iVar5;
}

// 0x669f61 — 观察到的形态
int FUN_669f61(void* self, uint32_t param_1, int param_2)
{
    int iVar1;

    iVar1 = *(int*)(*(int*)(*(int*)((int)(intptr_t)self + 0x14) + param_2 * 4) + 0x14);
    if ((iVar1 == -1) ||
        (iVar1 = FUN_669c99(self, (int*)(uintptr_t)param_1, (uint32_t)iVar1, 0, -1, 0xffffffff),
         -1 < iVar1)) {
        return 0;
    }
    return iVar1;
}

// 0x669f90 — observed shape
uint32_t FUN_669f90(void* self, int* param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t* puVar1;
    int iVar2;
    int* piVar3;
    uint32_t uVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    uint32_t uVar8;
    int* piVar9;
    uint32_t uVar10;
    uint32_t* puVar11;
    uint32_t local_24;
    int local_20;
    int local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_c;
    int* local_8;

    piVar3 = param_1;
    FUN_00661fbd();
    if (param_1 == (int*)0x0) {
        uVar4 = 0x80004005;
    }
    else {
        piVar9 = param_1;
        for (iVar6 = 0x19; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar9 = 0;
            piVar9 = piVar9 + 1;
        }
        param_1[0xb] = (int)param_3;
        *param_1 = (int)param_2;
        uVar10 = 0;
        param_1[0x18] = param_1[0x18] ^ ((*(int*)((char*)self + 0x6c) << 1) >> 0x1f ^ param_1[0x18]) & 1U;
        if (*(int*)((char*)self + 8) != 0) {
            do {
                iVar6 = *(int*)(*(int*)((char*)self + 0x14) + uVar10 * 4);
                if ((param_2 == *(int*)(iVar6 + 4)) && (*(int*)(iVar6 + 0x38) == -1)) {
                    if ((uint32_t)param_1[10] <= *(uint32_t*)(iVar6 + 0xc)) {
                        param_1[10] = *(int*)(iVar6 + 0xc) + 1;
                    }
                    *(int*)(iVar6 + 0x74) = param_1[0x12];
                    param_1[0x12] = param_1[0x12] + 1;
                }
                uVar10 = uVar10 + 1;
            } while (uVar10 < *(uint32_t*)((char*)self + 8));
        }
        iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 2);
        param_1[4] = iVar6;
        if (iVar6 != 0) {
            iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 4);
            param_1[5] = iVar6;
            if (iVar6 != 0) {
                iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 4);
                param_1[6] = iVar6;
                if (iVar6 != 0) {
                    iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 2);
                    param_1[2] = iVar6;
                    if (iVar6 != 0) {
                        iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 2);
                        param_1[3] = iVar6;
                        if (iVar6 != 0) {
                            iVar6 = (int)(intptr_t)FUN_00533c78(param_1[0xb] << 4);
                            param_1[7] = iVar6;
                            if (iVar6 != 0) {
                                iVar6 = (int)(intptr_t)FUN_00533c78(param_1[0xb] << 2);
                                param_1[8] = iVar6;
                                if (iVar6 != 0) {
                                    iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 4);
                                    param_1[0xc] = iVar6;
                                    if (iVar6 != 0) {
                                        iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 4);
                                        param_1[0xd] = iVar6;
                                        if (iVar6 != 0) {
                                            iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 2);
                                            param_1[0xf] = iVar6;
                                            if (iVar6 != 0) {
                                                iVar6 = (int)(intptr_t)FUN_00533c78(param_1[10] << 2);
                                                param_1[0x10] = iVar6;
                                                if (iVar6 != 0) {
                                                    iVar6 = (int)(intptr_t)FUN_00533c78(param_1[0x12] << 2);
                                                    param_1[0x13] = iVar6;
                                                    if (iVar6 != 0) {
                                                        iVar6 = (int)(intptr_t)FUN_00533c78(param_1[0x12] << 2);
                                                        param_1[0x14] = iVar6;
                                                        if (iVar6 != 0) {
                                                            local_c = 0;
                                                            do {
                                                                puVar11 = (uint32_t*)param_1[0xc];
                                                                for (iVar6 = (param_1[10] & 0xfffffffU) << 2;
                                                                     iVar6 != 0; iVar6 = iVar6 + -1) {
                                                                    *puVar11 = 0;
                                                                    puVar11 = puVar11 + 1;
                                                                }
                                                                for (iVar6 = 0; iVar6 != 0;
                                                                     iVar6 = iVar6 + -1) {
                                                                    *(uint8_t*)puVar11 = 0;
                                                                    puVar11 = (uint32_t*)((int)(intptr_t)puVar11 + 1);
                                                                }
                                                                local_20 = 0;
                                                                local_14 = 0;
                                                                if (*(int*)((char*)self + 0xc) != 0) {
                                                                    do {
                                                                        puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_14 * 4);
                                                                        iVar6 = FUN_0065cd3a();
                                                                        if ((iVar6 != 0) &&
                                                                            (param_2 ==
                                                                             *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                                             *(int*)puVar1[4] * 4) +
                                                                                     4))) {
                                                                            uVar10 = *puVar1 & 0xfffff;
                                                                            local_24 = puVar1[1] / uVar10;
                                                                            if (local_24 != 0) {
                                                                                local_1c = 0;
                                                                                do {
                                                                                    local_8 = (int*)(puVar1[2] + local_1c);
                                                                                    iVar6 = *local_8;
                                                                                    if ((iVar6 == -1) ||
                                                                                        (iVar5 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) + iVar6 * 4) + 0x38),
                                                                                         iVar5 == -1)) {
                                                                                        iVar5 = iVar6;
                                                                                    }
                                                                                    iVar7 = *(int*)((char*)self + 0x14);
                                                                                    if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                                                                  *(int*)(*(int*)(iVar7 + iVar5 * 4) + 4) * 4) +
                                                                                                     6) & 2) != 0) {
                                                                                        if ((iVar6 == -1) ||
                                                                                            (iVar5 = *(int*)(*(int*)(iVar7 + iVar6 * 4) + 0x38),
                                                                                             iVar5 == -1)) {
                                                                                            iVar5 = iVar6;
                                                                                        }
                                                                                        local_8 = *(int**)(*(int*)(*(int*)((char*)self + 0x18) +
                                                                                                                    *(int*)(*(int*)(iVar7 + iVar5 * 4) + 0x48) * 4) +
                                                                                                           8);
                                                                                    }
                                                                                    iVar6 = *local_8;
                                                                                    if ((iVar6 != -1) &&
                                                                                        (iVar5 = *(int*)(*(int*)(iVar7 + iVar6 * 4) + 0x38),
                                                                                         iVar5 != -1)) {
                                                                                        iVar6 = iVar5;
                                                                                    }
                                                                                    if (param_2 == *(int*)(*(int*)(iVar7 + iVar6 * 4) + 4)) {
                                                                                        local_18 = 0;
                                                                                        param_3 = 0;
                                                                                        if (uVar10 != 0) {
                                                                                            do {
                                                                                                iVar6 = local_8[param_3];
                                                                                                if ((iVar6 != -1) &&
                                                                                                    (iVar5 = *(int*)(*(int*)(iVar7 + iVar6 * 4) + 0x38), iVar5 != -1)) {
                                                                                                    iVar6 = iVar5;
                                                                                                }
                                                                                                uVar8 = 1 << ((uint8_t)*(uint32_t*)(*(int*)(iVar7 + iVar6 * 4) + 0x10) & 0x1f);
                                                                                                if ((local_18 & uVar8) != 0) break;
                                                                                                local_18 = local_18 | uVar8;
                                                                                                param_3 = param_3 + 1;
                                                                                            } while (param_3 < uVar10);
                                                                                            if (param_3 < uVar10) goto LAB_0066a349;
                                                                                        }
                                                                                        param_3 = 0;
                                                                                        if (uVar10 != 0) {
                                                                                            do {
                                                                                                iVar6 = *(int*)((char*)self + 0x14);
                                                                                                iVar5 = local_8[param_3];
                                                                                                iVar7 = *(int*)(iVar6 + *(int*)(param_3 * 4 + puVar1[4]) * 4);
                                                                                                if ((iVar5 != -1) &&
                                                                                                    (iVar2 = *(int*)(*(int*)(iVar6 + iVar5 * 4) + 0x38), iVar2 != -1)) {
                                                                                                    iVar5 = iVar2;
                                                                                                }
                                                                                                iVar5 = *(int*)(iVar6 + iVar5 * 4);
                                                                                                iVar6 = *(int*)(iVar7 + 0x10) + *(int*)(iVar7 + 0xc) * 4;
                                                                                                iVar5 = *(int*)(iVar5 + 0x10) + *(int*)(iVar5 + 0xc) * 4;
                                                                                                if ((iVar6 != iVar5) && (*(int*)(iVar7 + 0x3c) == 0)) {
                                                                                                    if (local_c == 1) {
                                                                                                        *(int*)(param_1[0xe] +
                                                                                                                (*(int*)(param_1[0xc] + iVar6 * 4) +
                                                                                                                 *(int*)(param_1[0xd] + iVar6 * 4)) * 4) = iVar5;
                                                                                                        *(int*)(param_1[0xe] +
                                                                                                                (*(int*)(param_1[0xc] + iVar5 * 4) +
                                                                                                                 *(int*)(param_1[0xd] + iVar5 * 4)) * 4) = iVar6;
                                                                                                    }
                                                                                                    piVar9 = (int*)(param_1[0xc] + iVar6 * 4);
                                                                                                    *piVar9 = *piVar9 + 1;
                                                                                                    piVar9 = (int*)(param_1[0xc] + iVar5 * 4);
                                                                                                    *piVar9 = *piVar9 + 1;
                                                                                                    local_20 = local_20 + 2;
                                                                                                }
                                                                                                param_3 = param_3 + 1;
                                                                                            } while (param_3 < uVar10);
                                                                                        }
                                                                                    }
LAB_0066a349:
                                                                                    local_1c = local_1c + uVar10 * 4;
                                                                                    local_24 = local_24 - 1;
                                                                                } while (local_24 != 0);
                                                                            }
                                                                        }
                                                                        local_14 = local_14 + 1;
                                                                    } while (local_14 < *(uint32_t*)((char*)self + 0xc));
                                                                }
                                                                if (local_c == 0) {
                                                                    iVar6 = 0;
                                                                    uVar10 = 0;
                                                                    if ((param_1[10] & 0x3fffffffU) != 0) {
                                                                        do {
                                                                            *(int*)(param_1[0xd] + uVar10 * 4) = iVar6;
                                                                            iVar6 = iVar6 + *(int*)(param_1[0xc] + uVar10 * 4);
                                                                            uVar10 = uVar10 + 1;
                                                                        } while (uVar10 < (uint32_t)(param_1[10] << 2));
                                                                    }
                                                                    iVar6 = (int)(intptr_t)FUN_00533c78(local_20 << 2);
                                                                    param_1[0xe] = iVar6;
                                                                    if (iVar6 == 0) goto LAB_0066a64f;
                                                                }
                                                                local_c = local_c + 1;
                                                            } while (local_c < 2);
                                                            param_1 = (int*)0x0;
                                                            do {
                                                                puVar11 = (uint32_t*)piVar3[0xf];
                                                                for (uVar10 = piVar3[10] & 0x3fffffffU; uVar10 != 0;
                                                                     uVar10 = uVar10 - 1) {
                                                                    *puVar11 = 0;
                                                                    puVar11 = puVar11 + 1;
                                                                }
                                                                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                                                                    *(uint8_t*)puVar11 = 0;
                                                                    puVar11 = (uint32_t*)((int)(intptr_t)puVar11 + 1);
                                                                }
                                                                local_1c = 0;
                                                                param_3 = 0;
                                                                if (*(int*)((char*)self + 0xc) != 0) {
                                                                    do {
                                                                        puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + param_3 * 4);
                                                                        iVar6 = FUN_0065cd72();
                                                                        if (((iVar6 != 0) || ((*(uint8_t*)((char*)self + 0x6f) & 0x80) != 0)) &&
                                                                            (iVar6 = *(int*)(*(int*)((char*)self + 0x14) +
                                                                                             *(int*)puVar1[4] * 4),
                                                                             param_2 == *(int*)(iVar6 + 4))) {
                                                                            uVar10 = *puVar1;
                                                                            local_18 = puVar1[1] / (uVar10 & 0xfffff);
                                                                            iVar6 = *(int*)(iVar6 + 0xc);
                                                                            if (local_18 != 0) {
                                                                                local_24 = 0;
                                                                                do {
                                                                                    iVar5 = *(int*)(local_24 + puVar1[2]);
                                                                                    if ((iVar5 != -1) &&
                                                                                        (iVar7 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) + iVar5 * 4) + 0x38),
                                                                                         iVar7 != -1)) {
                                                                                        iVar5 = iVar7;
                                                                                    }
                                                                                    iVar5 = *(int*)(*(int*)((char*)self + 0x14) + iVar5 * 4);
                                                                                    if ((param_2 == *(int*)(iVar5 + 4)) &&
                                                                                        (iVar6 != *(int*)(iVar5 + 0xc))) {
                                                                                        if (param_1 == (int*)0x1) {
                                                                                            *(uint32_t*)(piVar3[0x11] +
                                                                                                         (*(int*)(iVar6 * 4 + piVar3[0x10]) +
                                                                                                          *(int*)(piVar3[0xf] + iVar6 * 4)) * 4) =
                                                                                                *(uint32_t*)(iVar5 + 0xc);
                                                                                            iVar7 = *(int*)(iVar5 + 0xc) * 4;
                                                                                            *(int*)(piVar3[0x11] +
                                                                                                    (*(int*)(iVar7 + piVar3[0x10]) +
                                                                                                     *(int*)(piVar3[0xf] + iVar7)) * 4) = iVar6;
                                                                                        }
                                                                                        piVar9 = (int*)(piVar3[0xf] + iVar6 * 4);
                                                                                        *piVar9 = *piVar9 + 1;
                                                                                        piVar9 = (int*)(piVar3[0xf] + *(int*)(iVar5 + 0xc) * 4);
                                                                                        *piVar9 = *piVar9 + 1;
                                                                                        local_1c = local_1c + 2;
                                                                                    }
                                                                                    local_24 = local_24 + (uVar10 & 0xfffff) * 4;
                                                                                    local_18 = local_18 - 1;
                                                                                } while (local_18 != 0);
                                                                            }
                                                                        }
                                                                        param_3 = param_3 + 1;
                                                                    } while (param_3 < *(uint32_t*)((char*)self + 0xc));
                                                                }
                                                                uVar10 = 0;
                                                                if (param_1 == (int*)0x0) {
                                                                    iVar6 = 0;
                                                                    if (piVar3[10] != 0) {
                                                                        do {
                                                                            *(int*)(piVar3[0x10] + uVar10 * 4) = iVar6;
                                                                            iVar6 = iVar6 + *(int*)(piVar3[0xf] + uVar10 * 4);
                                                                            uVar10 = uVar10 + 1;
                                                                        } while (uVar10 < (uint32_t)piVar3[10]);
                                                                    }
                                                                    iVar6 = (int)(intptr_t)FUN_00533c78(local_1c << 2);
                                                                    piVar3[0x11] = iVar6;
                                                                    if (iVar6 == 0) goto LAB_0066a64f;
                                                                }
                                                                param_1 = (int*)((int)(intptr_t)param_1 + 1);
                                                            } while (param_1 < (int*)0x2);
                                                            param_2 = 0;
                                                            puVar11 = (uint32_t*)piVar3[0x13];
                                                            for (uVar10 = piVar3[0x12] & 0x3fffffffU; uVar10 != 0;
                                                                 uVar10 = uVar10 - 1) {
                                                                *puVar11 = 0;
                                                                puVar11 = puVar11 + 1;
                                                            }
                                                            for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                                                                *(uint8_t*)puVar11 = 0;
                                                                puVar11 = (uint32_t*)((int)(intptr_t)puVar11 + 1);
                                                            }
                                                            if (*(int*)((char*)self + 0xc) != 0) {
                                                                do {
                                                                    iVar6 = *(int*)(*(int*)((char*)self + 0x18) + param_2 * 4);
                                                                    if ((*(uint16_t*)(iVar6 + 2) & 0xfff0) != 0) {
                                                                        param_1 = (int*)0x0;
                                                                        if (*(int*)(iVar6 + 0xc) != 0) {
                                                                            do {
                                                                                FUN_00661c8a(piVar3,
                                                                                             *(uint32_t*)(*(int*)(iVar6 + 0x10) +
                                                                                                          (int)(intptr_t)param_1 * 4),
                                                                                             param_2);
                                                                                param_1 = (int*)((int)(intptr_t)param_1 + 1);
                                                                            } while (param_1 < (int*)(uintptr_t)*(uint32_t*)(iVar6 + 0xc));
                                                                        }
                                                                        param_1 = (int*)0x0;
                                                                        if (*(int*)(iVar6 + 4) != 0) {
                                                                            do {
                                                                                FUN_00661b07(piVar3,
                                                                                             *(uint32_t*)(*(int*)(iVar6 + 8) +
                                                                                                          (int)(intptr_t)param_1 * 4),
                                                                                             param_2);
                                                                                param_1 = (int*)((int)(intptr_t)param_1 + 1);
                                                                            } while (param_1 < (int*)(uintptr_t)*(uint32_t*)(iVar6 + 4));
                                                                        }
                                                                        iVar5 = FUN_0065ccac();
                                                                        if ((iVar5 != 0) &&
                                                                            (param_1 = (int*)0x0,
                                                                             *(int*)(iVar6 + 0xc) != 0)) {
                                                                            do {
                                                                                FUN_00661b07(piVar3,
                                                                                             *(uint32_t*)(*(int*)(iVar6 + 0x10) +
                                                                                                          (int)(intptr_t)param_1 * 4),
                                                                                             param_2);
                                                                                param_1 = (int*)((int)(intptr_t)param_1 + 1);
                                                                            } while (param_1 < (int*)(uintptr_t)*(uint32_t*)(iVar6 + 0xc));
                                                                        }
                                                                    }
                                                                    param_2 = param_2 + 1;
                                                                } while (param_2 < *(uint32_t*)((char*)self + 0xc));
                                                            }
                                                            uVar10 = 0;
                                                            iVar6 = 0;
                                                            if (piVar3[0x12] != 0) {
                                                                do {
                                                                    *(int*)(piVar3[0x14] + uVar10 * 4) = iVar6;
                                                                    iVar6 = iVar6 + *(int*)(piVar3[0x13] + uVar10 * 4);
                                                                    uVar10 = uVar10 + 1;
                                                                } while (uVar10 < (uint32_t)piVar3[0x12]);
                                                            }
                                                            iVar5 = (int)(intptr_t)FUN_00533c78(iVar6 << 2);
                                                            piVar3[0x15] = iVar5;
                                                            if (iVar5 != 0) {
                                                                iVar6 = (int)(intptr_t)FUN_00533c78(iVar6 * 0xc);
                                                                piVar3[0x16] = iVar6;
                                                                if (iVar6 != 0) {
                                                                    return 0;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
LAB_0066a64f:
        uVar4 = 0x8007000e;
    }
    return uVar4;
}

// 0x66a65b — observed shape
int FUN_66a65b(void* self, int* param_1, uint32_t param_2)
{
    uint32_t* puVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    int* piVar5;
    int* piVar6;
    int iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    int iVar10;
    int iVar11;
    uint32_t* puVar12;
    uint32_t local_18;
    int* local_14;
    int* local_10;
    int local_c;
    uint32_t local_8;

    piVar5 = param_1;
    *(int**)((int)(intptr_t)self + 0xbc) = param_1;
    param_1[0x18] = param_1[0x18] ^ ((int)param_2 * 2 ^ param_1[0x18]) & 2;
    FUN_00661fbd();
    uVar9 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar10 = *(int*)(*(int*)((char*)self + 0x14) + uVar9 * 4);
            if (((*param_1 == *(int*)(iVar10 + 4)) && (*(int*)(iVar10 + 0x38) == -1)) &&
                (*(uint32_t*)(iVar10 + 0x58) <= *(uint32_t*)(iVar10 + 0x48))) {
                *(uint32_t*)(iVar10 + 0x58) = *(uint32_t*)(iVar10 + 0x48) + 1;
            }
            uVar9 = uVar9 + 1;
        } while (uVar9 < *(uint32_t*)((char*)self + 8));
    }
    puVar12 = (uint32_t*)param_1[4];
    for (uVar9 = param_1[10] & 0x3fffffffU; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(uint8_t*)puVar12 = 0xff;
        puVar12 = (uint32_t*)((int)(intptr_t)puVar12 + 1);
    }
    puVar12 = (uint32_t*)param_1[5];
    for (iVar10 = (param_1[10] & 0xfffffffU) << 2; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(uint8_t*)puVar12 = 0xff;
        puVar12 = (uint32_t*)((int)(intptr_t)puVar12 + 1);
    }
    puVar12 = (uint32_t*)param_1[6];
    for (iVar10 = (param_1[10] & 0xfffffffU) << 2; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(uint8_t*)puVar12 = 0xff;
        puVar12 = (uint32_t*)((int)(intptr_t)puVar12 + 1);
    }
    uVar9 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar10 = *(int*)(*(int*)((char*)self + 0x14) + uVar9 * 4);
            *(uint32_t*)(iVar10 + 0x30) = 0xffffffff;
            if ((*param_1 == *(int*)(iVar10 + 4)) && (*(int*)(iVar10 + 0x38) == -1)) {
                *(uint32_t*)(param_1[6] + (*(int*)(iVar10 + 0x10) + *(int*)(iVar10 + 0xc) * 4) * 4) = uVar9;
            }
            uVar9 = uVar9 + 1;
        } while (uVar9 < *(uint32_t*)((char*)self + 8));
    }
    puVar12 = (uint32_t*)param_1[2];
    for (uVar9 = param_1[10] & 0x3fffffffU; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(uint8_t*)puVar12 = 0;
        puVar12 = (uint32_t*)((int)(intptr_t)puVar12 + 1);
    }
    uVar9 = 0;
    if (param_1[10] != 0) {
        param_1 = (int*)0x0;
        do {
            iVar11 = 0;
            piVar6 = (int*)(piVar5[6] + (int)(intptr_t)param_1);
            iVar10 = 4;
            do {
                if (*piVar6 != -1) {
                    iVar11 = iVar11 + 1;
                }
                piVar6 = piVar6 + 1;
                iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
            param_1 = (int*)((int)(intptr_t)param_1 + 0x10);
            *(int*)(piVar5[2] + uVar9 * 4) = iVar11;
            uVar9 = uVar9 + 1;
        } while (uVar9 < (uint32_t)piVar5[10]);
    }
    param_1 = (int*)0x0;
    puVar12 = (uint32_t*)piVar5[3];
    for (uVar9 = piVar5[10] & 0x3fffffffU; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(uint8_t*)puVar12 = 0;
        puVar12 = (uint32_t*)((int)(intptr_t)puVar12 + 1);
    }
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            iVar10 = *(int*)(*(int*)((char*)self + 0x18) + (int)(intptr_t)param_1 * 4);
            iVar11 = FUN_0065cd3a();
            if ((iVar11 != 0) &&
                (iVar11 = *(int*)(*(int*)((char*)self + 0x14) + **(int**)(iVar10 + 0x10) * 4),
                 *piVar5 == *(int*)(iVar11 + 4))) {
                local_10 = (int*)0x2;
                do {
                    local_8 = 0;
                    if (*(int*)(iVar10 + 4) != 0) {
                        do {
                            iVar7 = *(int*)(*(int*)(iVar10 + 8) + local_8 * 4);
                            if (iVar7 != -1) {
                                iVar2 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) + iVar7 * 4) + 0x38);
                                if (iVar2 != -1) {
                                    iVar7 = iVar2;
                                }
                            }
                            iVar7 = *(int*)(*(int*)((char*)self + 0x14) + iVar7 * 4);
                            if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                       *(int*)(iVar7 + 4) * 4) + 6) & 2) != 0) {
                                iVar7 = *(int*)(*(int*)((char*)self + 0x14) +
                                                **(int**)(*(int*)(*(int*)((char*)self + 0x18) +
                                                                 *(int*)(iVar7 + 0x48) * 4) + 8) * 4);
                            }
                            if (*piVar5 == *(int*)(iVar7 + 4)) {
                                puVar1 = (uint32_t*)(piVar5[3] + *(int*)(iVar7 + 0xc) * 4);
                                uVar9 = *(uint32_t*)(piVar5[2] + *(int*)(iVar11 + 0xc) * 4);
                                if (*puVar1 < uVar9) {
                                    *puVar1 = uVar9;
                                }
                                puVar1 = (uint32_t*)(piVar5[3] + *(int*)(iVar11 + 0xc) * 4);
                                uVar9 = *(uint32_t*)(piVar5[2] + *(int*)(iVar7 + 0xc) * 4);
                                if (*puVar1 < uVar9) {
                                    *puVar1 = uVar9;
                                }
                            }
                            local_8 = local_8 + *(uint32_t*)(iVar10 + 0xc);
                        } while (local_8 < *(uint32_t*)(iVar10 + 4));
                    }
                    local_10 = (int*)((int)(intptr_t)local_10 + -1);
                } while (local_10 != (int*)0x0);
            }
            param_1 = (int*)((int)(intptr_t)param_1 + 1);
        } while (param_1 < (int*)(uintptr_t)*(uint32_t*)((char*)self + 0xc));
    }
    param_1 = (int*)0x0;
    puVar12 = (uint32_t*)piVar5[0x13];
    for (uVar9 = piVar5[0x12] & 0x3fffffffU; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(uint8_t*)puVar12 = 0;
        puVar12 = (uint32_t*)((int)(intptr_t)puVar12 + 1);
    }
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            iVar10 = *(int*)(*(int*)((char*)self + 0x18) + (int)(intptr_t)param_1 * 4);
            if ((*(uint16_t*)(iVar10 + 2) & 0xfff0) != 0) {
                param_2 = 0;
                if (*(int*)(iVar10 + 0xc) != 0) {
                    do {
                        FUN_00661c8a(piVar5, *(uint32_t*)(*(int*)(iVar10 + 0x10) + param_2 * 4), param_1);
                        param_2 = param_2 + 1;
                    } while (param_2 < *(uint32_t*)(iVar10 + 0xc));
                }
                param_2 = 0;
                if (*(int*)(iVar10 + 4) != 0) {
                    do {
                        FUN_00661b07(piVar5, *(uint32_t*)(*(int*)(iVar10 + 8) + param_2 * 4), param_1);
                        param_2 = param_2 + 1;
                    } while (param_2 < *(uint32_t*)(iVar10 + 4));
                }
                iVar11 = FUN_0065ccac();
                if ((iVar11 != 0) && (param_2 = 0, *(int*)(iVar10 + 0xc) != 0)) {
                    do {
                        FUN_00661b07(piVar5, *(uint32_t*)(*(int*)(iVar10 + 0x10) + param_2 * 4), param_1);
                        param_2 = param_2 + 1;
                    } while (param_2 < *(uint32_t*)(iVar10 + 0xc));
                }
            }
            param_1 = (int*)((int)(intptr_t)param_1 + 1);
        } while (param_1 < (int*)(uintptr_t)*(uint32_t*)((char*)self + 0xc));
    }
    local_8 = 0;
    if (piVar5[0x12] != 0) {
        do {
            iVar10 = piVar5[0x15] + *(int*)(piVar5[0x14] + local_8 * 4) * 4;
            uVar9 = *(uint32_t*)(piVar5[0x13] + local_8 * 4);
            if (1 < uVar9) {
                FUN_0065e1b9(FUN_0065e16a, iVar10, uVar9, (int)(intptr_t)self);
                param_1 = (int*)0x1;
                local_10 = (int*)0x1;
                if (1 < uVar9) {
                    do {
                        uVar3 = *(uint32_t*)(iVar10 + (int)(intptr_t)local_10 * 4);
                        iVar11 = FUN_0065e0f1();
                        if (iVar11 != 0) {
                            *(uint32_t*)(iVar10 + (int)(intptr_t)param_1 * 4) = uVar3;
                            param_1 = (int*)((int)(intptr_t)param_1 + 1);
                        }
                        local_10 = (int*)((int)(intptr_t)local_10 + 1);
                    } while (local_10 < (int*)(uintptr_t)uVar9);
                }
                *(int**)(piVar5[0x13] + local_8 * 4) = param_1;
                FUN_0065e1b9(FUN_0065e132, iVar10, param_1, (int)(intptr_t)self);
            }
            local_8 = local_8 + 1;
        } while (local_8 < (uint32_t)piVar5[0x12]);
    }
    puVar12 = (uint32_t*)piVar5[7];
    for (iVar10 = (piVar5[0xb] & 0xfffffffU) << 2; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar12 = 0xffffffff;
        puVar12 = puVar12 + 1;
    }
    for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(uint8_t*)puVar12 = 0xff;
        puVar12 = (uint32_t*)((int)(intptr_t)puVar12 + 1);
    }
    uVar9 = 0;
    if (piVar5[0xb] != 0) {
        do {
            *(uint32_t*)(piVar5[8] + uVar9 * 4) = uVar9;
            uVar9 = uVar9 + 1;
        } while (uVar9 < (uint32_t)piVar5[0xb]);
    }
    piVar5[1] = 0;
    piVar5[9] = (int)((uint32_t)piVar5[0xb] >> 1);
    iVar10 = *(int*)((char*)self + 0xc);
    do {
        do {
            if (iVar10 == 0) {
                local_c = 4;
                do {
                    piVar5[1] = local_c;
                    iVar10 = *(int*)((char*)self + 0xc);
                    while (iVar10 != 0) {
                        iVar10 = iVar10 + -1;
                        puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + iVar10 * 4);
                        piVar5[0x17] = (int)(intptr_t)puVar1;
                        if ((*puVar1 & 0xfff00000) != 0) {
                            param_1 = (int*)0x0;
                            if (puVar1[3] != 0) {
                                do {
                                    iVar11 = FUN_669f61(self, *(uint32_t*)(puVar1[4] + (int)(intptr_t)param_1 * 4),
                                                        (int)(intptr_t)piVar5);
                                    if (iVar11 < 0) {
                                        return iVar11;
                                    }
                                    param_1 = (int*)((int)(intptr_t)param_1 + 1);
                                } while (param_1 < (int*)(uintptr_t)puVar1[3]);
                            }
                            uVar9 = *puVar1;
                            uVar8 = puVar1[1] / (uVar9 & 0xfffff);
                            param_2 = 0;
                            if (puVar1[1] != 0) {
                                do {
                                    param_1 = (int*)0x0;
                                    if (((*(uint8_t*)((char*)self + 0x70) & 1) != 0) && (uVar8 != 0)) {
                                        local_14 = (int*)puVar1[2];
                                        local_18 = uVar8;
                                        do {
                                            iVar11 = *local_14;
                                            if (iVar11 != -1) {
                                                iVar7 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) + iVar11 * 4) +
                                                               0x38);
                                                if (iVar7 != -1) {
                                                    iVar11 = iVar7;
                                                }
                                            }
                                            iVar11 = *(int*)(*(int*)((char*)self + 0x14) + iVar11 * 4);
                                            if ((*piVar5 == *(int*)(iVar11 + 4)) &&
                                                (uVar4 = *(uint32_t*)(piVar5[4] + *(int*)(iVar11 + 0xc) * 4),
                                                 uVar4 != 0xffffffff)) {
                                                if ((uVar4 & 1) == 0) {
                                                    param_1 = (int*)((int)(intptr_t)param_1 + 1);
                                                }
                                                else {
                                                    param_1 = (int*)((int)(intptr_t)param_1 + -1);
                                                }
                                            }
                                            local_14 = local_14 + (uVar9 & 0xfffff);
                                            local_18 = local_18 - 1;
                                        } while (local_18 != 0);
                                    }
                                    iVar11 = *(int*)(puVar1[2] + param_2 * 4);
                                    if (iVar11 != -1) {
                                        iVar7 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) + iVar11 * 4) + 0x38);
                                        if (iVar7 != -1) {
                                            iVar11 = iVar7;
                                        }
                                    }
                                    iVar11 = FUN_669c99(self, piVar5, (uint32_t)iVar11,
                                                        (uint32_t)(uintptr_t)param_1, -1, 0xffffffff);
                                    if (iVar11 < 0) {
                                        return iVar11;
                                    }
                                    param_2 = param_2 + 1;
                                } while (param_2 < puVar1[1]);
                            }
                        }
                    }
                    local_c = local_c + -1;
                    if (local_c == 0) {
                        if (((*(uint8_t*)((char*)piVar5 + 0x18) & 2) != 0) &&
                            (param_1 = (int*)0x0, *(int*)((char*)self + 8) != 0)) {
                            do {
                                iVar10 = *(int*)(*(int*)((char*)self + 0x14) + (int)(intptr_t)param_1 * 4);
                                if (*piVar5 == *(int*)(iVar10 + 4)) {
                                    iVar11 = *(int*)(iVar10 + 0xc) * 4;
                                    *(uint32_t*)(iVar10 + 0x10) =
                                        *(uint32_t*)(piVar5[5] +
                                                     (*(int*)(iVar10 + 0x10) + iVar11) * 4);
                                    *(uint32_t*)(iVar10 + 0xc) = *(uint32_t*)(iVar11 + piVar5[4]);
                                }
                                param_1 = (int*)((int)(intptr_t)param_1 + 1);
                            } while (param_1 < (int*)(uintptr_t)*(uint32_t*)((char*)self + 8));
                        }
                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) + *piVar5 * 4) + 8) = 0xffffffff;
                        return 0;
                    }
                } while (true);
            }
            iVar10 = iVar10 + -1;
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + iVar10 * 4);
        } while (((*puVar1 & 0xfff00000) != 0x20900000) ||
                 (param_1 = (int*)0x0, puVar1[3] == 0));
        do {
            piVar5[0x17] = (int)(intptr_t)puVar1;
            iVar11 = *(int*)(puVar1[2] + (int)(intptr_t)param_1 * 4);
            if (iVar11 != -1) {
                iVar7 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) + iVar11 * 4) + 0x38);
                if (iVar7 != -1) {
                    iVar11 = iVar7;
                }
            }
            iVar11 = FUN_669c99(self, piVar5, (uint32_t)iVar11, 0, -1, 0xffffffff);
            if (iVar11 < 0) {
                return iVar11;
            }
            iVar11 = *(int*)(puVar1[2] + (puVar1[3] + (int)(intptr_t)param_1) * 4);
            iVar7 = *(int*)(*(int*)((char*)self + 0x18) +
                            *(int*)(*(int*)(*(int*)((char*)self + 0x14) + iVar11 * 4) + 0x48) * 4);
            param_2 = 0;
            if (*(uint32_t*)(iVar7 + 0xc) != 0) {
                local_10 = *(int**)(iVar7 + 0x10);
                do {
                    if (*local_10 == iVar11) break;
                    param_2 = param_2 + 1;
                    local_10 = local_10 + 1;
                } while (param_2 < *(uint32_t*)(iVar7 + 0xc));
            }
            piVar5[0x17] = iVar7;
            iVar11 = FUN_669c99(self, piVar5, *(uint32_t*)(puVar1[4] + (int)(intptr_t)param_1 * 4), 0,
                                *(int*)(param_2 * 4 + *(int*)(iVar7 + 8)), 0xffffffff);
            if (iVar11 < 0) {
                return iVar11;
            }
            iVar11 = FUN_669c99(self, piVar5, *(uint32_t*)(param_2 * 4 + *(int*)(iVar7 + 8)), 0,
                                *(int*)(puVar1[4] + (int)(intptr_t)param_1 * 4), 0xffffffff);
            if (iVar11 < 0) {
                return iVar11;
            }
            param_1 = (int*)((int)(intptr_t)param_1 + 1);
        } while (param_1 < (int*)(uintptr_t)puVar1[3]);
    } while (true);
}


// 0x66ad0e — observed shape
int FUN_66ad0e(void* self)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t uVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;
    int iVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int iVar11;
    int* piVar12;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    int local_14;
    int local_10;
    int local_c;
    uint32_t local_8;

    if (((*(uint32_t*)((char*)self + 0xcc) & 0x100) == 0) && ((*(uint32_t*)((char*)self + 0xcc) & 4) == 0)) {
        iVar5 = FUN_00664c21();
        if (-1 < iVar5) {
            iVar5 = (int)(intptr_t)FUN_00533c78();
            if (iVar5 == 0) {
                iVar5 = 0;
            }
            else {
                iVar5 = FUN_006840fd();
            }
            *(int*)((char*)self + 0xe0) = iVar5;
            if (iVar5 == 0) {
LAB_0066b208:
                iVar5 = -0x7ff8fff2;
            }
            else {
                iVar5 = FUN_00662bf9((int)(intptr_t)self, 0x46580201,
                                     *(uint32_t*)((char*)self + 0xcc) | 0x100);
                if (((-1 < iVar5) && (iVar5 = FUN_0065e58c(), -1 < iVar5)) &&
                    (iVar5 = FUN_0065e79d(), -1 < iVar5)) {
                    uVar6 = 0;
                    if (*(int*)((char*)self + 8) != 0) {
                        do {
                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + uVar6 * 4) + 0x30) = 0xffffffff;
                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + uVar6 * 4) + 0x44) = 0xffffffff;
                            uVar6 = uVar6 + 1;
                        } while (uVar6 < *(uint32_t*)((char*)self + 8));
                    }
                    local_10 = -1;
                    local_c = 0;
                    local_18 = 0;
                    if (*(int*)((char*)self + 0xc) != 0) {
                        do {
                            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_18 * 4);
                            if ((*puVar1 & 0xfff00000) != 0) {
                                uVar6 = puVar1[1];
                                uVar10 = *puVar1 & 0xfffff;
                                local_24 = 0;
                                if (uVar6 / uVar10 != 0) {
                                    local_14 = 0;
                                    do {
                                        local_8 = 0;
                                        if (uVar10 != 0) {
                                            piVar12 = (int*)(puVar1[2] + local_14);
                                            local_20 = uVar10;
                                            do {
                                                if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                           *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                                           *piVar12 * 4) +
                                                                                   4) * 4) + 4) & 2) != 0) &&
                                                    (iVar5 = FUN_0065e551(), iVar5 == 0)) {
                                                    local_8 = local_8 + 1;
                                                }
                                                piVar12 = piVar12 + 1;
                                                local_20 = local_20 - 1;
                                            } while (local_20 != 0);
                                            if (local_8 != 0) {
                                                if (((local_10 == -1) &&
                                                     (local_10 = FUN_0065d97c(&DAT_006c3b94, 0x80251, 0xffffffff, 4),
                                                      local_10 == -1)) ||
                                                    (iVar5 = FUN_0065da35(local_8 & 0xfffff | 0x10000000, local_8,
                                                                          local_8),
                                                     iVar5 == -1))
                                                    goto LAB_0066b208;
                                                puVar2 = *(uint32_t**)(*(int*)(*(int*)((char*)self + 0xe0) + 0x18) +
                                                                       iVar5 * 4);
                                                FUN_0065cc50();
                                                local_8 = 0;
                                                local_1c = 0;
                                                iVar5 = local_14;
                                                do {
                                                    uVar3 = puVar1[2];
                                                    iVar4 = *(int*)(uVar3 + iVar5);
                                                    iVar11 = iVar4 * 4;
                                                    iVar8 = *(int*)(iVar11 + *(int*)((char*)self + 0x14));
                                                    if ((((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                                *(int*)(iVar8 + 4) * 4) + 4) & 2) != 0) &&
                                                         (iVar7 = FUN_0065e551(), iVar7 == 0)) &&
                                                        ((*(int*)(iVar8 + 0x48) == -1 ||
                                                          ((**(uint32_t**)(*(int*)((char*)self + 0x18) +
                                                                           *(int*)(iVar8 + 0x48) * 4) &
                                                            0xfff00000) != 0x10100000)))) {
                                                        if (*(int*)(iVar8 + 0x30) == -1) {
                                                            iVar8 = FUN_0065d9d5(*(uint32_t*)(*(int*)((char*)self + 0xe0) + 0x84),
                                                                                 local_c, local_8, 0.0);
                                                            if (iVar8 == -1) goto LAB_0066b208;
                                                            *(int*)(local_8 * 4 + puVar2[4]) = iVar8;
                                                            *(int*)(local_8 * 4 + puVar2[2]) = iVar4;
                                                            uVar9 = FUN_0065d9d5(local_10, local_c, local_8, 0.0);
                                                            *(uint32_t*)(iVar5 + puVar1[2]) = uVar9;
                                                            if (*(int*)(iVar5 + puVar1[2]) == -1) goto LAB_0066b208;
                                                            iVar4 = *(int*)(*(int*)((char*)self + 0x14) +
                                                                            *(int*)(iVar5 + puVar1[2]) * 4);
                                                            FUN_0065d5bd();
                                                            *(uint32_t*)(iVar4 + 0x60) = 0;
                                                            *(uint32_t*)(iVar4 + 100) = 0;
                                                            local_8 = local_8 + 1;
                                                            *(int*)(iVar4 + 0x44) = iVar8;
                                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + iVar11) + 0x30) =
                                                                *(uint32_t*)(iVar5 + puVar1[2]);
                                                        }
                                                        else {
                                                            *(int*)(uVar3 + iVar5) = *(int*)(iVar8 + 0x30);
                                                        }
                                                    }
                                                    local_1c = local_1c + 1;
                                                    iVar5 = iVar5 + 4;
                                                } while (local_1c < uVar10);
                                                local_c = local_c + 1;
                                                *puVar2 = -(uint32_t)(local_8 != 0) & (local_8 & 0xfffff | 0x10000000);
                                                puVar2[3] = local_8;
                                                puVar2[1] = local_8;
                                            }
                                        }
                                        local_24 = local_24 + 1;
                                        local_14 = local_14 + uVar10 * 4;
                                    } while (local_24 < uVar6 / uVar10);
                                }
                            }
                            local_18 = local_18 + 1;
                        } while (local_18 < *(uint32_t*)((char*)self + 0xc));
                    }
                    local_18 = 0;
                    if (*(int*)((char*)self + 8) != 0) {
                        do {
                            iVar5 = *(int*)(*(int*)((char*)self + 0x14) + local_18 * 4);
                            if (((*(int*)(iVar5 + 8) != -1) &&
                                 (iVar4 = *(int*)(*(int*)((char*)self + 0x14) + *(int*)(iVar5 + 8) * 4),
                                  (*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                             *(int*)(iVar4 + 4) * 4) + 4) & 2) != 0)) &&
                                (iVar8 = FUN_0065e551(), iVar8 == 0)) {
                                if (*(int*)(iVar4 + 0x30) == -1) {
                                    if (((local_10 == -1) &&
                                         (local_10 = FUN_0065d97c(&DAT_006c3b94, 0x80251, 0xffffffff, 4),
                                          local_10 == -1)) ||
                                        (iVar8 = FUN_0065da35(0x10000001, 1, 1), iVar8 == -1))
                                        goto LAB_0066b208;
                                    iVar8 = *(int*)(*(int*)(*(int*)((char*)self + 0xe0) + 0x18) + iVar8 * 4);
                                    FUN_0065cc50();
                                    **(uint32_t**)(iVar8 + 8) = *(uint32_t*)(iVar5 + 8);
                                    uVar9 = FUN_0065d9d5(*(uint32_t*)(*(int*)((char*)self + 0xe0) + 0x84),
                                                         local_c, 0, 0.0);
                                    **(uint32_t**)(iVar8 + 0x10) = uVar9;
                                    if (**(int**)(iVar8 + 0x10) == -1) goto LAB_0066b208;
                                    iVar11 = FUN_0065d9d5(local_10, local_c, 0, 0.0);
                                    *(int*)(iVar4 + 0x30) = iVar11;
                                    if (iVar11 == -1) goto LAB_0066b208;
                                    iVar11 = *(int*)(*(int*)((char*)self + 0x14) + iVar11 * 4);
                                    FUN_0065d5bd();
                                    uVar9 = **(uint32_t**)(iVar8 + 0x10);
                                    *(uint32_t*)(iVar11 + 0x60) = 0;
                                    *(uint32_t*)(iVar11 + 100) = 0;
                                    local_c = local_c + 1;
                                    *(uint32_t*)(iVar11 + 0x44) = uVar9;
                                }
                                *(uint32_t*)(iVar5 + 8) = *(uint32_t*)(iVar4 + 0x30);
                            }
                            local_18 = local_18 + 1;
                        } while (local_18 < *(uint32_t*)((char*)self + 8));
                    }
                    iVar5 = FUN_006634e9();
                    if ((iVar5 == 0) || (-1 < iVar5)) {
                        iVar5 = FUN_0065e4f2();
                        if ((iVar5 == 0) || (-1 < iVar5)) {
                            FUN_00661fbd();
                            iVar5 = FUN_006634e9();
                            if ((iVar5 == 0) || (-1 < iVar5)) {
                                iVar5 = FUN_0065e4f2();
                                if ((iVar5 == 0) || (-1 < iVar5)) {
                                    iVar5 = FUN_00664b28();
                                    if ((iVar5 == 0) || (-1 < iVar5)) {
                                        iVar5 = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        iVar5 = 1;
    }
    return iVar5;
}

// 0x66b20f — observed shape
uint32_t FUN_66b20f(void* self)
{
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    uVar3 = 0;
    if (*(int*)((char*)self + 0xe0) == 0) {
        return 1;
    }
    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar1 = *(int*)(*(int*)((char*)self + 0x14) + uVar3 * 4);
            if (*(int*)(iVar1 + 0x44) != -1) {
                *(uint32_t*)(*(int*)(*(int*)(*(int*)((char*)self + 0xe0) + 0x14) +
                                      *(int*)(iVar1 + 0x44) * 4) + 0xc) =
                    *(uint32_t*)(iVar1 + 0xc);
                *(uint32_t*)(*(int*)(*(int*)(*(int*)((char*)self + 0xe0) + 0x14) +
                                      *(int*)(iVar1 + 0x44) * 4) + 0x44) = uVar3;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)((char*)self + 8));
    }
    uVar2 = FUN_0066306d();
    return uVar2;
}


// 0x66b26a — observed shape
int FUN_66b26a(void* self)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    int iVar4;
    uint32_t* puVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    int iVar10;
    uint32_t uVar11;
    int* piVar12;
    uint32_t uVar13;
    uint32_t uVar14;
    int local_4c[4];
    uint32_t* local_3c;
    uint32_t* local_38;
    int local_34;
    uint32_t local_30;
    uint32_t* local_2c;
    uint32_t* local_28;
    int local_24;
    uint32_t* local_20;
    uint32_t local_1c;
    uint32_t local_18;
    int local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    local_8 = 0;
    FUN_0066254f();
    FUN_00661fbd();
    local_24 = -1;
    local_14 = -1;
    local_1c = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_1c * 4);
            uVar14 = *puVar1;
            uVar13 = uVar14 & 0xfff00000;
            if (uVar13 != 0) {
                local_10 = *(uint32_t*)((char*)self + 8);
                if (uVar13 == 0x11000000) {
                    uVar14 = 0;
                    if (puVar1[1] != 0) {
                        piVar12 = (int*)puVar1[2];
                        do {
                            if ((**(uint8_t**)(*(int*)((char*)self + 0x14) +
                                               *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                              *piVar12 * 4) + 0x30) * 4) & 4) == 0)
                                break;
                            uVar14 = uVar14 + 1;
                            piVar12 = piVar12 + 1;
                        } while (uVar14 < puVar1[1]);
                    }
                    if (uVar14 != puVar1[1]) goto LAB_0066bd3c;
LAB_0066bd2b:
                    uVar14 = 0;
                    puVar1[1] = 0;
                    puVar1[3] = 0;
LAB_0066bd33:
                    local_8 = 1;
LAB_0066bd3a:
                    *puVar1 = uVar14;
                }
                else {
                    uVar9 = uVar14 & 0xf0000000;
                    if (uVar9 == 0x10000000) {
                        local_c = 0;
                        local_10 = 0;
                        if (puVar1[3] != 0) {
                            do {
                                puVar5 = *(uint32_t**)(local_10 * 4 + puVar1[4]);
                                iVar7 = *(int*)((char*)self + 0x14);
                                local_2c = *(uint32_t**)(*(int*)(iVar7 +
                                                                 *(int*)(local_10 * 4 + puVar1[2]) * 4) +
                                                         0x30);
                                if (((*puVar1 & 0xfff00000) == 0x10000000) ||
                                    ((*puVar1 & 0xfff00000) == 0x10100000)) {
                                    puVar2 = *(uint32_t**)(iVar7 + (int)(intptr_t)puVar5 * 4);
                                    puVar3 = *(uint32_t**)(iVar7 + (int)(intptr_t)local_2c * 4);
                                    uVar14 = *puVar2;
                                    uVar9 = *puVar3 | uVar14;
                                    uVar6 = uVar9 & 0xe000000;
                                    uVar13 = 0x2000000;
                                    if (((uVar9 & 0x2000000) != 0) ||
                                        ((uVar13 = 0x4000000, (uVar9 & 0x4000000) != 0 ||
                                          (uVar13 = 0x8000000, (uVar9 & 0x8000000) != 0)))) {
                                        uVar6 = uVar13;
                                    }
                                    if (uVar6 != (uVar14 & 0xe000000)) {
                                        *puVar2 = uVar14 & 0xf1ffffff | uVar6;
                                        local_8 = 1;
                                    }
                                    local_30 = *puVar3;
                                    if (((uVar6 != (local_30 & 0xe000000)) &&
                                         ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                    puVar3[1] * 4) + 4) & 2) != 0)) &&
                                        (puVar3[0x17] == 1)) {
                                        *puVar3 = local_30 & 0xf1ffffff | uVar6;
                                        local_8 = 1;
                                    }
                                }
                                local_28 = puVar5;
                                iVar7 = FUN_00664f69(puVar1, puVar5, local_2c);
                                if (iVar7 < 0) {
                                    return iVar7;
                                }
                                iVar7 = *(int*)((char*)self + 0x14);
                                piVar12 = (int*)(iVar7 + (int)(intptr_t)puVar5 * 4);
                                puVar2 = *(uint32_t**)(*piVar12 + 0x30);
                                if (puVar2 == puVar5) {
                                    local_c = local_c + 1;
                                }
                                else if (*(int*)(*(int*)(iVar7 + (int)(intptr_t)puVar2 * 4) + 0x30) == -1) {
                                    iVar10 = *(int*)(*piVar12 + 0x30);
                                    *(int*)(*(int*)(iVar7 + iVar10 * 4) + 0x30) = iVar10;
                                }
                                local_10 = local_10 + 1;
                            } while (local_10 < puVar1[3]);
                        }
                        if (local_c == puVar1[3]) goto LAB_0066bd3c;
                        local_c = 0;
                        local_8 = 0;
                        if (puVar1[3] == 0) {
LAB_0066b4d0:
                            uVar14 = 0;
                        }
                        else {
                            do {
                                iVar7 = *(int*)(puVar1[4] + local_8 * 4);
                                iVar10 = *(int*)((char*)self + 0x14);
                                if (*(int*)(*(int*)(iVar10 + iVar7 * 4) + 0x30) == iVar7) {
                                    iVar10 = local_c * 4;
                                    local_c = local_c + 1;
                                    *(int*)(iVar10 + puVar1[4]) = iVar7;
                                    *(uint32_t*)(iVar10 + puVar1[2]) = *(uint32_t*)(puVar1[2] + local_8 * 4);
                                }
                                else {
                                    iVar7 = *(int*)(iVar10 + iVar7 * 4);
                                    iVar10 = *(int*)(iVar10 + *(int*)(iVar7 + 0x30) * 4);
                                    if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                *(int*)(iVar10 + 4) * 4) + 4) & 2) != 0) &&
                                        (*(int*)(iVar10 + 0x60) == 0)) {
                                        *(uint32_t*)(iVar10 + 0x60) = *(uint32_t*)(iVar7 + 0x60);
                                        *(uint32_t*)(iVar10 + 100) =
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                 *(int*)(puVar1[4] + local_8 * 4) * 4) +
                                                         100);
                                    }
                                }
                                local_8 = local_8 + 1;
                            } while (local_8 < puVar1[3]);
                            if (local_c == 0) goto LAB_0066b4d0;
                            uVar14 = (*puVar1 ^ local_c) & 0xfffff ^ *puVar1;
                        }
                        puVar1[1] = local_c;
                        puVar1[3] = local_c;
                        goto LAB_0066bd33;
                    }
                    if (uVar9 != 0x20000000) {
                        if (uVar9 == 0x30000000) {
                            local_18 = 0;
                            local_c = 0;
                            if (puVar1[3] != 0) {
                                do {
                                    uVar14 = *(uint32_t*)(puVar1[4] + local_c * 4);
                                    uVar13 = puVar1[2];
                                    iVar7 = *(int*)((char*)self + 0x14);
                                    local_3c = *(uint32_t**)(*(int*)(iVar7 +
                                                                     *(int*)(uVar13 + local_c * 4) * 4) +
                                                             0x30);
                                    local_28 = *(uint32_t**)(*(int*)(iVar7 +
                                                                     *(int*)(uVar13 +
                                                                             (local_c + puVar1[3]) * 4) * 4) +
                                                             0x30);
                                    local_34 = *(int*)(*(int*)(iVar7 + *(int*)(uVar13 +
                                                                               (local_c + puVar1[3] * 2) * 4) * 4) +
                                                       0x30);
                                    if ((*puVar1 & 0xfff00000) == 0x30000000) {
                                        local_2c = *(uint32_t**)(iVar7 + (int)(intptr_t)local_28 * 4);
                                        local_20 = *(uint32_t**)(iVar7 + local_34 * 4);
                                        uVar13 = *local_2c;
                                        uVar6 = *local_20 | uVar13;
                                        uVar11 = uVar6 & 0xe000000;
                                        uVar9 = 0x8000000;
                                        if ((((uVar6 & 0x8000000) != 0) ||
                                             (uVar9 = 0x4000000, (uVar6 & 0x4000000) != 0)) ||
                                            (uVar9 = 0x2000000, (uVar6 & 0x2000000) != 0)) {
                                            uVar11 = uVar9;
                                        }
                                        uVar11 = uVar11 | **(uint32_t**)(iVar7 + uVar14 * 4) & 0xe000000;
                                        uVar9 = 0x2000000;
                                        if ((((uVar11 & 0x2000000) != 0) ||
                                             (uVar9 = 0x4000000, (uVar11 & 0x4000000) != 0)) ||
                                            (uVar9 = 0x8000000, (uVar11 & 0x8000000) != 0)) {
                                            uVar11 = uVar9;
                                        }
                                        if (((uVar11 != (uVar13 & 0xe000000)) &&
                                             ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                        local_2c[1] * 4) + 4) & 2) != 0)) &&
                                            (local_2c[0x17] == 1)) {
                                            *local_2c = uVar13 & 0xf1ffffff | uVar11;
                                            local_8 = 1;
                                        }
                                        local_38 = (uint32_t*)*local_20;
                                        if (((uVar11 != ((uint32_t)local_38 & 0xe000000)) &&
                                             ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                        local_20[1] * 4) + 4) & 2) != 0)) &&
                                            (local_20[0x17] == 1)) {
                                            *local_20 = (uint32_t)local_38 & 0xf1ffffff | uVar11;
                                            local_8 = 1;
                                        }
                                    }
                                    local_30 = uVar14;
                                    iVar7 = FUN_00666617(puVar1, uVar14, local_3c, local_28, local_34);
                                    if (iVar7 < 0) {
                                        return iVar7;
                                    }
                                    iVar7 = *(int*)((char*)self + 0x14);
                                    piVar12 = (int*)(iVar7 + uVar14 * 4);
                                    uVar13 = *(uint32_t*)(*piVar12 + 0x30);
                                    if (uVar13 == uVar14) {
                                        local_18 = local_18 + 1;
                                    }
                                    else if (*(int*)(*(int*)(iVar7 + uVar13 * 4) + 0x30) == -1) {
                                        iVar10 = *(int*)(*piVar12 + 0x30);
                                        *(int*)(*(int*)(iVar7 + iVar10 * 4) + 0x30) = iVar10;
                                    }
                                    local_c = local_c + 1;
                                } while (local_c < puVar1[3]);
                            }
                            uVar14 = puVar1[3];
                            if (local_18 != uVar14) {
                                if (local_18 == 0) {
                                    local_20 = (uint32_t*)0x1;
                                    if (1 < uVar14) {
                                        piVar12 = (int*)puVar1[4];
                                        iVar7 = *(int*)((char*)self + 0x14);
                                        iVar10 = *piVar12;
                                        do {
                                            piVar12 = piVar12 + 1;
                                            if (*(int*)(*(int*)(iVar7 +
                                                                *(int*)(*(int*)(iVar7 + iVar10 * 4) + 0x30) *
                                                                4) + 4) !=
                                                *(int*)(*(int*)(iVar7 +
                                                                *(int*)(*(int*)(iVar7 + *piVar12 * 4) + 0x30) *
                                                                4) + 4)) {
                                                uVar14 = puVar1[3];
                                                if (uVar14 != 0) goto LAB_0066ba07;
                                                break;
                                            }
                                            local_20 = (uint32_t*)((int)(intptr_t)local_20 + 1);
                                        } while (local_20 < (uint32_t*)puVar1[3]);
                                    }
                                    local_10 = 0;
                                    if (puVar1[3] != 0) {
                                        do {
                                            iVar7 = *(int*)(*(int*)((char*)self + 0x14) +
                                                           *(int*)(puVar1[4] + local_10 * 4) * 4);
                                            iVar10 = *(int*)(*(int*)((char*)self + 0x14) + *(int*)(iVar7 + 0x30) * 4);
                                            if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                        *(int*)(iVar10 + 4) * 4) + 4) & 2) != 0) &&
                                                (*(int*)(iVar10 + 0x60) == 0)) {
                                                *(uint32_t*)(iVar10 + 0x60) = *(uint32_t*)(iVar7 + 0x60);
                                                *(uint32_t*)(iVar10 + 100) =
                                                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                         *(int*)(puVar1[4] + local_10 * 4) * 4) +
                                                                 100);
                                            }
                                            local_10 = local_10 + 1;
                                        } while (local_10 < puVar1[3]);
                                    }
                                    goto LAB_0066bd2b;
                                }
LAB_0066ba07:
                                local_18 = 0;
                                if (uVar14 != 0) {
                                    do {
                                        uVar14 = *(uint32_t*)(puVar1[4] + local_18 * 4);
                                        local_3c = *(uint32_t**)(*(int*)((char*)self + 0x14) + uVar14 * 4);
                                        if (local_3c[0xc] != uVar14) {
                                            uVar13 = **(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                                    local_3c[0xc] * 4) & 0xf1ffffff |
                                                     *local_3c;
                                            if (*local_3c != uVar13) {
                                                *local_3c = uVar13;
                                                local_8 = 1;
                                            }
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + uVar14 * 4) + 0x30) =
                                                uVar14;
                                        }
                                        local_18 = local_18 + 1;
                                    } while (local_18 < puVar1[3]);
                                }
                                uVar14 = local_10;
                                uVar13 = local_10;
                                if (local_10 < *(uint32_t*)((char*)self + 8)) {
                                    do {
                                        if (*(int*)(*(int*)((char*)self + 0x14) + uVar13 * 4) != 0) {
                                            FUN_00615a4f();
                                            uVar14 = local_10;
                                        }
                                        uVar13 = uVar13 + 1;
                                    } while (uVar13 < *(uint32_t*)((char*)self + 8));
                                }
                                goto LAB_0066ba7f;
                            }
                            goto LAB_0066bd3c;
                        }
                        if (uVar13 != 0x50000000) {
                            if (uVar14 == 0x50100004) {
                                iVar7 = *(int*)((char*)self + 0x14);
                                local_4c[2] = -1;
                                local_4c[1] = -1;
                                local_4c[3] = 1;
                                local_4c[0] = 1;
                                piVar12 = (int*)puVar1[2];
                                iVar10 = *(int*)(iVar7 + *piVar12 * 4);
                                local_18 = *(uint32_t*)(iVar7 + piVar12[3] * 4);
                                local_20 = *(uint32_t**)(iVar7 + piVar12[1] * 4);
                                iVar4 = *(int*)((char*)self + 0x10);
                                if (((*(uint8_t*)(*(int*)(iVar4 + *(int*)(iVar10 + 4) * 4) + 5) & 1) == 0) ||
                                    (*(int*)(iVar10 + 8) != -1)) {
                                    if (*(int*)(*(int*)(iVar7 +
                                                         *(int*)(puVar1[4] + 4) * 4) + 0x5c) == 0) {
                                        local_4c[1] = 0;
                                    }
LAB_0066bc0c:
                                    if (*(int*)(*(int*)(iVar7 +
                                                         *(int*)(puVar1[4] + 8) * 4) + 0x5c) == 0) {
                                        local_4c[2] = 0;
                                    }
                                    if ((local_4c[1] == -1) || (local_4c[2] == -1)) goto LAB_0066bd3c;
                                }
                                else if (*(double*)(iVar10 + 0x20) <= 0.0) {
                                    local_4c[1] = 0;
LAB_0066bbf3:
                                    local_4c[2] = 0;
                                }
                                else {
                                    local_4c[1] = 2;
                                    if (((*(uint8_t*)(*(int*)(iVar4 + local_20[1] * 4) + 5) & 1) == 0) ||
                                        (local_20[2] != 0xffffffff)) goto LAB_0066bc0c;
                                    if (*(double*)(local_20 + 8) <= 0.0) goto LAB_0066bbf3;
                                    if (((*(uint8_t*)(*(int*)(iVar4 + *(int*)(local_18 + 4) * 4) + 5) & 1) ==
                                         0) ||
                                        (*(int*)(local_18 + 8) != -1)) goto LAB_0066bc0c;
                                    if (*(double*)(local_18 + 0x20) == 0.0) {
                                        local_4c[2] = 1;
                                    }
                                    else {
                                        if (*(double*)(local_18 + 0x20) != 1.0) goto LAB_0066bc0c;
                                        local_4c[2] = 3;
                                    }
                                }
                                uVar14 = 0;
                                do {
                                    iVar7 = *(int*)((int)(intptr_t)local_4c + uVar14);
                                    if (iVar7 == 0) {
                                        if (local_14 == -1) {
                                            local_14 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78), 0, 0, 0.0);
                                            *(int*)(*(int*)(*(int*)((char*)self + 0x14) + local_14 * 4) + 0x30) =
                                                local_14;
                                        }
                                        iVar7 = *(int*)(*(int*)((char*)self + 0x14) +
                                                        *(int*)(uVar14 + puVar1[4]) * 4);
                                        iVar10 = local_14;
LAB_0066bcd7:
                                        *(int*)(iVar7 + 0x30) = iVar10;
                                    }
                                    else {
                                        if (iVar7 == 1) {
                                            if (local_24 == -1) {
                                                local_24 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78), 0, 0,
                                                                        (double)0x3ff0000000000000ULL);
                                                *(int*)(*(int*)(*(int*)((char*)self + 0x14) + local_24 * 4) +
                                                        0x30) = local_24;
                                            }
                                            iVar7 = *(int*)(*(int*)((char*)self + 0x14) +
                                                            *(int*)(uVar14 + puVar1[4]) * 4);
                                            iVar10 = local_24;
                                            goto LAB_0066bcd7;
                                        }
                                        if (iVar7 == 2) {
                                            uVar8 = *(uint32_t*)puVar1[2];
LAB_0066bc51:
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                 *(int*)(uVar14 + puVar1[4]) * 4) + 0x30) =
                                                uVar8;
                                        }
                                        else if (iVar7 == 3) {
                                            uVar8 = *(uint32_t*)(puVar1[2] + 4);
                                            goto LAB_0066bc51;
                                        }
                                    }
                                    local_3c = *(uint32_t**)(*(int*)((char*)self + 0x14) +
                                                             *(int*)(uVar14 + puVar1[4]) * 4);
                                    iVar7 = *(int*)(*(int*)((char*)self + 0x14) + local_3c[0xc] * 4);
                                    if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                *(int*)(iVar7 + 4) * 4) + 4) & 2) != 0) &&
                                        (*(int*)(iVar7 + 0x60) == 0)) {
                                        *(uint32_t*)(iVar7 + 0x60) = local_3c[0x18];
                                        *(uint32_t*)(iVar7 + 100) =
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                 *(int*)(uVar14 + puVar1[4]) * 4) +
                                                         100);
                                    }
                                    uVar14 = uVar14 + 4;
                                } while (uVar14 < 0x10);
                                goto LAB_0066bd2b;
                            }
                            goto LAB_0066bd3c;
                        }
                        iVar7 = FUN_0065ea37(puVar1, 1);
                        if (iVar7 < 0) {
                            return iVar7;
                        }
                        if (iVar7 != 1) {
                            local_8 = 1;
                        }
                        iVar7 = *(int*)puVar1[4];
                        iVar10 = *(int*)((char*)self + 0x14);
                        if (*(int*)(*(int*)(iVar10 + iVar7 * 4) + 0x30) == iVar7) goto LAB_0066bd3c;
                        iVar7 = *(int*)(iVar10 + iVar7 * 4);
                        iVar10 = *(int*)(iVar10 + *(int*)(iVar7 + 0x30) * 4);
                        if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                    *(int*)(iVar10 + 4) * 4) + 4) & 2) != 0) &&
                            (*(int*)(iVar10 + 0x60) == 0)) {
                            *(uint32_t*)(iVar10 + 0x60) = *(uint32_t*)(iVar7 + 0x60);
                            *(uint32_t*)(iVar10 + 100) =
                                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                     *(int*)puVar1[4] * 4) + 100);
                        }
                        uVar14 = 0;
                        puVar1[1] = 0;
                        puVar1[3] = 0;
                        goto LAB_0066bd3a;
                    }
                    local_18 = 0;
                    local_c = 0;
                    if (puVar1[3] != 0) {
                        do {
                            puVar5 = *(uint32_t**)(local_c * 4 + puVar1[4]);
                            iVar7 = *(int*)((char*)self + 0x14);
                            local_2c = *(uint32_t**)(*(int*)(iVar7 +
                                                             *(int*)(local_c * 4 + puVar1[2]) * 4) + 0x30);
                            local_34 = *(int*)(*(int*)(iVar7 +
                                                       *(int*)(puVar1[2] + (puVar1[3] + local_c) * 4) * 4) +
                                               0x30);
                            if (((*puVar1 & 0xfff00000) == 0x20000000) ||
                                ((*puVar1 & 0xfff00000) == 0x20100000)) {
                                local_28 = *(uint32_t**)(iVar7 + (int)(intptr_t)local_2c * 4);
                                local_20 = *(uint32_t**)(iVar7 + local_34 * 4);
                                uVar14 = *local_28;
                                uVar9 = *local_20 | uVar14;
                                uVar6 = uVar9 & 0xe000000;
                                uVar13 = 0x8000000;
                                if (((uVar9 & 0x8000000) != 0) ||
                                    ((uVar13 = 0x4000000, (uVar9 & 0x4000000) != 0 ||
                                      (uVar13 = 0x2000000, (uVar9 & 0x2000000) != 0)))) {
                                    uVar6 = uVar13;
                                }
                                uVar6 = uVar6 | **(uint32_t**)(iVar7 + (int)(intptr_t)puVar5 * 4) & 0xe000000;
                                uVar13 = 0x2000000;
                                if ((((uVar6 & 0x2000000) != 0) ||
                                     (uVar13 = 0x4000000, (uVar6 & 0x4000000) != 0)) ||
                                    (uVar13 = 0x8000000, (uVar6 & 0x8000000) != 0)) {
                                    uVar6 = uVar13;
                                }
                                if (((uVar6 != (uVar14 & 0xe000000)) &&
                                     ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                local_28[1] * 4) + 4) & 2) != 0)) &&
                                    (local_28[0x17] == 1)) {
                                    *local_28 = uVar14 & 0xf1ffffff | uVar6;
                                    local_8 = 1;
                                }
                                local_30 = *local_20;
                                if (((uVar6 != (local_30 & 0xe000000)) &&
                                     ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                local_20[1] * 4) + 4) & 2) != 0)) &&
                                    (local_20[0x17] == 1)) {
                                    *local_20 = local_30 & 0xf1ffffff | uVar6;
                                    local_8 = 1;
                                }
                            }
                            local_38 = puVar5;
                            iVar7 = FUN_0066569a(puVar1, puVar5, local_2c, local_34);
                            if (iVar7 < 0) {
                                return iVar7;
                            }
                            iVar7 = *(int*)((char*)self + 0x14);
                            piVar12 = (int*)(iVar7 + (int)(intptr_t)puVar5 * 4);
                            puVar2 = *(uint32_t**)(*piVar12 + 0x30);
                            if (puVar2 == puVar5) {
                                local_18 = local_18 + 1;
                            }
                            else if (*(int*)(*(int*)(iVar7 + (int)(intptr_t)puVar2 * 4) + 0x30) == -1) {
                                iVar10 = *(int*)(*piVar12 + 0x30);
                                *(int*)(*(int*)(iVar7 + iVar10 * 4) + 0x30) = iVar10;
                            }
                            local_c = local_c + 1;
                        } while (local_c < puVar1[3]);
                    }
                    uVar14 = puVar1[3];
                    if (local_18 != uVar14) {
                        if (local_18 == 0) {
                            local_20 = (uint32_t*)0x1;
                            if (1 < uVar14) {
                                piVar12 = (int*)puVar1[4];
                                iVar7 = *(int*)((char*)self + 0x14);
                                iVar10 = *piVar12;
                                do {
                                    piVar12 = piVar12 + 1;
                                    if (*(int*)(*(int*)(iVar7 +
                                                        *(int*)(*(int*)(iVar7 + iVar10 * 4) + 0x30) * 4) + 4) !=
                                        *(int*)(*(int*)(iVar7 +
                                                        *(int*)(*(int*)(iVar7 + *piVar12 * 4) + 0x30) * 4) + 4)) {
                                        uVar14 = puVar1[3];
                                        if (uVar14 != 0) goto LAB_0066b72e;
                                        break;
                                    }
                                    local_20 = (uint32_t*)((int)(intptr_t)local_20 + 1);
                                } while (local_20 < (uint32_t*)puVar1[3]);
                            }
                            local_c = 0;
                            if (puVar1[3] != 0) {
                                do {
                                    iVar7 = *(int*)(*(int*)((char*)self + 0x14) +
                                                    *(int*)(puVar1[4] + local_c * 4) * 4);
                                    iVar10 = *(int*)(*(int*)((char*)self + 0x14) + *(int*)(iVar7 + 0x30) * 4);
                                    if (((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                                *(int*)(iVar10 + 4) * 4) + 4) & 2) != 0) &&
                                        (*(int*)(iVar10 + 0x60) == 0)) {
                                        *(uint32_t*)(iVar10 + 0x60) = *(uint32_t*)(iVar7 + 0x60);
                                        *(uint32_t*)(iVar10 + 100) =
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                 *(int*)(puVar1[4] + local_c * 4) * 4) +
                                                         100);
                                    }
                                    local_c = local_c + 1;
                                } while (local_c < puVar1[3]);
                            }
                            goto LAB_0066bd2b;
                        }
LAB_0066b72e:
                        local_18 = 0;
                        if (uVar14 != 0) {
                            do {
                                uVar14 = *(uint32_t*)(puVar1[4] + local_18 * 4);
                                local_38 = *(uint32_t**)(*(int*)((char*)self + 0x14) + uVar14 * 4);
                                if (local_38[0xc] != uVar14) {
                                    uVar13 = **(uint32_t**)(*(int*)((char*)self + 0x14) + local_38[0xc] * 4) &
                                            0xf1ffffff | *local_38;
                                    if (*local_38 != uVar13) {
                                        *local_38 = uVar13;
                                        local_8 = 1;
                                    }
                                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + uVar14 * 4) + 0x30) = uVar14;
                                }
                                local_18 = local_18 + 1;
                            } while (local_18 < puVar1[3]);
                        }
                        uVar14 = local_10;
                        if (local_10 < *(uint32_t*)((char*)self + 8)) {
                            do {
                                if (*(int*)(*(int*)((char*)self + 0x14) + uVar14 * 4) != 0) {
                                    FUN_00615a4f();
                                }
                                uVar14 = uVar14 + 1;
                            } while (uVar14 < *(uint32_t*)((char*)self + 8));
                        }
                        uVar14 = local_10;
LAB_0066ba7f:
                        *(uint32_t*)((char*)self + 8) = uVar14;
                    }
                }
LAB_0066bd3c:
                if (puVar1[3] != 0) {
                    local_18 = 0;
                    piVar12 = (int*)puVar1[4];
                    do {
                        puVar5 = *(uint32_t**)(*(int*)((char*)self + 0x14) + *piVar12 * 4);
                        local_30 = *puVar5;
                        if (((((local_30 & 0x40) != 0) ||
                              ((*(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                         puVar5[1] * 4) + 4) & 0x11028) != 0)) ||
                             ((local_30 & 4) == 0)) || ((local_30 & 8) == 0))
                            break;
                        local_18 = local_18 + 1;
                        piVar12 = piVar12 + 1;
                    } while (local_18 < puVar1[3]);
                    if (local_18 == puVar1[3]) {
                        if (local_14 == -1) {
                            local_14 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78), 0, 0, 0.0);
                            *(int*)(*(int*)(*(int*)((char*)self + 0x14) + local_14 * 4) + 0x30) = local_14;
                        }
                        uVar14 = 0;
                        if (puVar1[3] != 0) {
                            do {
                                iVar7 = uVar14 * 4;
                                uVar14 = uVar14 + 1;
                                *(int*)(*(int*)(*(int*)((char*)self + 0x14) + *(int*)(puVar1[4] + iVar7) * 4) +
                                        0x30) = local_14;
                            } while (uVar14 < puVar1[3]);
                        }
                        *puVar1 = 0;
                        puVar1[1] = 0;
                        puVar1[3] = 0;
                        local_8 = 1;
                    }
                }
            }
            local_1c = local_1c + 1;
        } while (local_1c < *(uint32_t*)((char*)self + 0xc));
        if (local_8 != 0) {
            FUN_00662568();
            return 0;
        }
    }
    return 1;
}
