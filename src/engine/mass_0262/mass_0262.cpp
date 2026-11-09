#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

extern void* operator_new(std::size_t) noexcept;
extern void operator_delete(void*) noexcept;
extern int FUN_005f909b(void*, unsigned int);
extern float FUN_005f90bc(float);
extern float FUN_005f90ec(void*, unsigned int);
extern float FUN_005f90ec(int, int);
extern int FUN_005f8bed(void);
extern int ftol(void);
extern void* FUN_00533c78(unsigned int);
extern char* _strdup(const char*);
extern int FUN_005f5ff4(int);
extern int FUN_005f907a(int);
extern void* setlocale(int, const char*);
extern void free(void*);

// 0x5fafd5 — observed shape: _StringCopyWorkerA@12: HRESULT string copy with E_INVALIDARG 0x80070057 when count==0, E_INSUFFICIENT_BUFFER 0x8007007a when truncated, NUL-terminates destination.
uint32_t FUN_005fafd5(char* param_1, int param_2, char* param_3) {
    uint32_t uVar1 = 0;
    if (param_2 == 0) {
        uVar1 = 0x80070057;
    } else {
        do {
            if (*param_3 == '\0') break;
            *param_1 = *param_3;
            param_1 = param_1 + 1;
            param_3 = param_3 + 1;
            param_2 = param_2 + -1;
        } while (param_2 != 0);
        if (param_2 == 0) {
            param_1 = param_1 + -1;
            uVar1 = 0x8007007a;
        }
        *param_1 = '\0';
    }
    return uVar1;
}

// 0x5fb012 — observed shape: validates magic word 0x4d42 ("MB") and box length at +1, minimum size 0xe; delegates payload at +7 to FUN_005f90ec; else E_FAIL 0x80004005.
uint32_t FUN_005fb012(short* param_1, uint32_t param_2) {
    uint32_t uVar1;
    if (((param_2 < 0xe) || (*param_1 != 0x4d42)) || (param_2 < *(uint32_t*)(param_1 + 1))) {
        uVar1 = 0x80004005;
    } else {
        uVar1 = (uint32_t)FUN_005f90ec(param_1 + 7, param_2 - 0xe);
    }
    return uVar1;
}

// 0x5fb046 — observed shape: _StringCchCopyA_12 wrapper: size < 0x80000000 forwards to _StringCopyWorkerA, else E_INVALIDARG.
uint32_t FUN_005fb046(uint32_t param_1, uint32_t param_2) {
    uint32_t uVar1;
    if (param_2 < 0x80000000) {
        uVar1 = FUN_005fafd5(reinterpret_cast<char*>(param_1), (int)param_2, nullptr);
        return uVar1;
    }
    return 0x80070057;
}

// 0x5fb063 — observed shape: parses "PF\n"/"Pf\n" header selecting grayscale (local_c==0) vs RGB; sscanf "%u %u%s" dims and "%f%s" gamma; allocates w*h*16 via FUN_00533c78; fills 4 floats per pixel (x,y,z,1.0) with gamma exponent FUN_005f90bc when gamma>=0 else direct; HRESULT success 0, failure 0x80004005 / 0x8007000e.
uint32_t FUN_005fb063(void* self, char* param_1, uint32_t param_2) {
    float fVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    int iVar4;
    char* pcVar5;
    float* pfVar6;
    float* pfVar7;
    char* pcVar8;
    float* pfVar9;
    bool bVar10;
    double fVar11;
    char local_218[256];
    char local_118[256];
    float local_18;
    int local_14;
    int local_10;
    int local_c;
    float* local_8;

    iVar4 = 3;
    if (param_2 < 4) {
        return 0x80004005;
    }
    bVar10 = true;
    pcVar5 = const_cast<char*>("PF\n");
    pcVar8 = param_1;
    do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar10 = *pcVar5 == *pcVar8;
        pcVar5 = pcVar5 + 1;
        pcVar8 = pcVar8 + 1;
    } while (bVar10);
    if (bVar10) {
        local_c = 0;
    } else {
        iVar4 = 3;
        bVar10 = true;
        pcVar5 = const_cast<char*>("Pf\n");
        pcVar8 = param_1;
        do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar10 = *pcVar5 == *pcVar8;
            pcVar5 = pcVar5 + 1;
            pcVar8 = pcVar8 + 1;
        } while (bVar10);
        if (!bVar10) {
            return 0x80004005;
        }
        local_c = 1;
    }
    param_2 = param_2 - 3;
    uVar3 = 0x100;
    if (param_2 < 0x101) {
        uVar3 = param_2;
    }
    iVar4 = FUN_005f909b(param_1 + 3, uVar3);
    if (iVar4 != 0) {
        FUN_005fb046((uint32_t)local_118, (uint32_t)iVar4 + 1);
        iVar2 = sscanf(local_118, "%u %u%s", &local_10, &local_14, local_218);
        if (iVar2 == 2) {
            param_1 = param_1 + iVar4 + 4;
            param_2 = param_2 + (-1 - iVar4);
            if (param_2 != 0) {
                uVar3 = 0x100;
                if (param_2 < 0x101) {
                    uVar3 = param_2;
                }
                local_8 = reinterpret_cast<float*>(FUN_005f909b(param_1, uVar3));
                if (local_8 != (float*)0x0) {
                    FUN_005fb046((uint32_t)local_118, (uint32_t)(intptr_t)local_8 + 1);
                    iVar4 = sscanf(local_118, "%f%s", &local_18, local_218);
                    if ((iVar4 == 1) &&
                        ((((uint32_t)(local_c == 0) * 2 + 1) * (uint32_t)local_10 * (uint32_t)local_14 * 4) <=
                         (param_2 - (uint32_t)(intptr_t)local_8) - 1)) {
                        in_ECX[0xd] = 0;
                        in_ECX[0xc] = (uint32_t)local_10 * 0x10;
                        in_ECX[3] = (uint32_t)local_10;
                        *in_ECX = 0x74;
                        in_ECX[4] = (uint32_t)local_14;
                        in_ECX[5] = 1;
                        in_ECX[0xe] = 1;
                        iVar4 = (int)(intptr_t)FUN_00533c78((uint32_t)local_10 * 0x10 * (uint32_t)local_14);
                        in_ECX[1] = (uint32_t)iVar4;
                        if (iVar4 == 0) {
                            return 0x8007000e;
                        }
                        pfVar9 = reinterpret_cast<float*>(param_1 + (int)(intptr_t)local_8 + 1);
                        iVar4 = local_14;
                        while ((iVar4 = iVar4 + -1) >= 0) {
                            pfVar6 = reinterpret_cast<float*>((intptr_t)iVar4 * (intptr_t)local_10 * 0x10 + in_ECX[1]);
                            local_8 = pfVar6 + local_10 * 4;
                            if (local_c == 0) {
                                if (local_18 < 0.0f) {
                                    for (; pfVar6 != local_8; pfVar6 = pfVar6 + 4) {
                                        *pfVar6 = *pfVar9;
                                        pfVar6[1] = pfVar9[1];
                                        fVar1 = pfVar9[2];
                                        pfVar6[3] = 1.0f;
                                        pfVar6[2] = fVar1;
                                        pfVar9 = pfVar9 + 3;
                                    }
                                } else if (pfVar6 != local_8) {
                                    do {
                                        fVar11 = (double)FUN_005f90bc(*pfVar9);
                                        *pfVar6 = (float)fVar11;
                                        fVar11 = (double)FUN_005f90bc(pfVar9[1]);
                                        pfVar6[1] = (float)fVar11;
                                        fVar11 = (double)FUN_005f90bc(pfVar9[2]);
                                        pfVar6[2] = (float)fVar11;
                                        pfVar7 = pfVar6 + 4;
                                        pfVar9 = pfVar9 + 3;
                                        pfVar6[3] = 1.0f;
                                        pfVar6 = pfVar7;
                                    } while (pfVar7 != local_8);
                                }
                            } else if (local_18 < 0.0f) {
                                for (; pfVar6 != local_8; pfVar6 = pfVar6 + 4) {
                                    fVar1 = *pfVar9;
                                    pfVar9 = pfVar9 + 1;
                                    pfVar6[2] = fVar1;
                                    pfVar6[1] = fVar1;
                                    *pfVar6 = fVar1;
                                    pfVar6[3] = 1.0f;
                                }
                            } else if (pfVar6 != local_8) {
                                do {
                                    fVar11 = (double)FUN_005f90bc(*pfVar9);
                                    pfVar6[2] = (float)fVar11;
                                    pfVar9 = pfVar9 + 1;
                                    pfVar6[1] = (float)fVar11;
                                    *pfVar6 = (float)fVar11;
                                    pfVar7 = pfVar6 + 4;
                                    pfVar6[3] = 1.0f;
                                    pfVar6 = pfVar7;
                                } while (pfVar7 != local_8);
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    }
    return 0x80004005;
}

// 0x5fb308 — observed shape: Radiance "#?RADIANCE" header parse: FORMAT= (32-bit_rle_rgbe / 32-bit_rle_xyze), EXPOSURE= multiply, "-Y h +X w" resolution, RLE scanline decode (old/new run packets), RGBE->float via ldexp(value+0.5, exp-0x88)/exposure, w-alpha 1.0; HRESULT success 0, failure 0x80004005 / 0x8007000e.
uint32_t FUN_005fb308(void* self, float* param_1_data, float* param_2_len) {
    char cVar1;
    float fVar2;
    float fVar3;
    float fVar4 = 0;
    float fVar5 = 0;
    float fVar6 = 0;
    uint32_t uVar7 = 0;
    uint32_t uVar8 = 0;
    char* pcVar9;
    uint32_t* puVar10;
    char* pcVar11;
    float* pfVar12;
    uint32_t uVar13 = 0;
    uint32_t uVar14 = 0;
    uint8_t bVar16 = 0;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    int iVar15 = 0;
    int iVar17 = 0;
    float* pfVar18;
    uint32_t uVar19 = 0;
    short* psVar20;
    bool bVar21 = false;
    bool bVar22 = false;
    double dVar23 = 0;
    char local_164[256];
    char local_64[32];
    int local_44 = 0;
    uint32_t local_40 = 0;
    float local_3c = 0;
    int local_38 = 0;
    int local_34 = 0;
    int local_30 = 0;
    float local_2c = 1.0f;
    float* local_24 = nullptr;
    uint32_t local_20 = 0;
    uint32_t local_1c[2] = {0, 0};
    uint32_t local_14 = 0;
    bool local_d = false;
    float* local_c = param_1_data;
    uint32_t local_8;
    float* param_1 = param_1_data;
    float* param_2 = param_2_len;

    (void)fVar4; (void)fVar5; (void)fVar6;
    local_8 = (uint32_t)(intptr_t)param_2;
    if ((intptr_t)param_2 < 0xb) {
        return 0x80004005;
    }
    iVar15 = 5;
    bVar21 = true;
    psVar20 = reinterpret_cast<short*>(const_cast<char*>("#?RADIANCE"));
    do {
        if (iVar15 == 0) break;
        iVar15 = iVar15 + -1;
        bVar21 = *(short*)param_1 == *psVar20;
        param_1 = reinterpret_cast<float*>((intptr_t)param_1 + 2);
        psVar20 = psVar20 + 1;
    } while (bVar21);
    if (!bVar21) {
        return 0x80004005;
    }
    bVar21 = false;
    local_2c = 1.0f;
    if ((intptr_t)param_2 < 1) {
        return 0x80004005;
    }
    do {
        pfVar12 = local_c;
        if (*(char*)local_c == '\n') {
            local_c = reinterpret_cast<float*>((intptr_t)local_c + 1);
            local_8 = local_8 - 1;
            break;
        }
        pcVar11 = const_cast<char*>("FORMAT=");
        do {
            pcVar9 = pcVar11;
            pcVar11 = pcVar9 + 1;
        } while (*pcVar9 != '\0');
        if ((int)(intptr_t)(pcVar9 + -0x6dd5b8) < (int)local_8) {
            pcVar11 = const_cast<char*>("FORMAT=");
            do {
                pcVar9 = pcVar11;
                pcVar11 = pcVar9 + 1;
            } while (*pcVar9 != '\0');
            pcVar9 = pcVar9 + -0x6dd5b8;
            bVar22 = true;
            pfVar18 = local_c;
            pcVar11 = const_cast<char*>("FORMAT=");
            do {
                if (pcVar9 == (char*)0x0) break;
                pcVar9 = pcVar9 + -1;
                bVar22 = (char)*(short*)pfVar18 == *pcVar11;
                pfVar18 = reinterpret_cast<float*>((intptr_t)pfVar18 + 1);
                pcVar11 = pcVar11 + 1;
            } while (bVar22);
            if (!bVar22) goto LAB_005fb432;
            pcVar11 = const_cast<char*>("FORMAT=");
            do {
                pcVar9 = pcVar11;
                pcVar11 = pcVar9 + 1;
            } while (*pcVar9 != '\0');
            local_c = reinterpret_cast<float*>((intptr_t)local_c + (int)(intptr_t)(pcVar9 + -0x6dd5b8));
            pcVar11 = const_cast<char*>("FORMAT=");
            do {
                pcVar9 = pcVar11;
                pcVar11 = pcVar9 + 1;
            } while (*pcVar9 != '\0');
            local_8 = local_8 - (int)(intptr_t)(pcVar9 + -0x6dd5b8);
            for (; (*(char*)local_c == ' ' || (*(char*)local_c == '\t')); local_c = reinterpret_cast<float*>((intptr_t)local_c + 1)) {
                local_8 = local_8 + -1;
                if (local_8 == 0) {
                    return 0x80004005;
                }
            }
            std::strncpy(local_64 + 0x10, "32-bit_rle_rgbe", 0x10);
            std::strncpy(local_64, "32-bit_rle_xyze", 0x10);
            if ((int)local_8 < 0x10) {
                return 0x80004005;
            }
            iVar15 = 0xf;
            bVar21 = true;
            pfVar12 = local_c;
            pcVar11 = local_64 + 0x10;
            do {
                if (iVar15 == 0) break;
                iVar15 = iVar15 + -1;
                bVar21 = *(char*)pfVar12 == *pcVar11;
                pfVar12 = reinterpret_cast<float*>((intptr_t)pfVar12 + 1);
                pcVar11 = pcVar11 + 1;
            } while (bVar21);
            if (!bVar21) {
                iVar15 = 0xf;
                bVar21 = true;
                pfVar12 = local_c;
                pcVar11 = local_64;
                do {
                    if (iVar15 == 0) break;
                    iVar15 = iVar15 + -1;
                    bVar21 = *(char*)pfVar12 == *pcVar11;
                    pfVar12 = reinterpret_cast<float*>((intptr_t)pfVar12 + 1);
                    pcVar11 = pcVar11 + 1;
                } while (bVar21);
                if (!bVar21) {
                    return 0x80004005;
                }
            }
            local_c = reinterpret_cast<float*>((intptr_t)local_c + 0x10);
            local_8 = local_8 - 0x10;
            bVar21 = true;
        } else {
LAB_005fb432:
            pcVar11 = const_cast<char*>("EXPOSURE=");
            do {
                pcVar9 = pcVar11;
                pcVar11 = pcVar9 + 1;
            } while (*pcVar9 != '\0');
            if ((int)(intptr_t)(pcVar9 + -0x6dd58c) < (int)local_8) {
                pcVar11 = const_cast<char*>("EXPOSURE=");
                do {
                    pcVar9 = pcVar11;
                    pcVar11 = pcVar9 + 1;
                } while (*pcVar9 != '\0');
                pcVar9 = pcVar9 + -0x6dd58c;
                bVar22 = true;
                pfVar18 = local_c;
                pcVar11 = const_cast<char*>("EXPOSURE=");
                do {
                    if (pcVar9 == (char*)0x0) break;
                    pcVar9 = pcVar9 + -1;
                    bVar22 = (char)*(short*)pfVar18 == *pcVar11;
                    pfVar18 = reinterpret_cast<float*>((intptr_t)pfVar18 + 1);
                    pcVar11 = pcVar11 + 1;
                } while (bVar22);
                if (bVar22) {
                    pcVar11 = const_cast<char*>("EXPOSURE=");
                    do {
                        pcVar9 = pcVar11;
                        pcVar11 = pcVar9 + 1;
                    } while (*pcVar9 != '\0');
                    local_c = reinterpret_cast<float*>((intptr_t)local_c + (int)(intptr_t)(pcVar9 + -0x6dd58c));
                    pcVar11 = const_cast<char*>("EXPOSURE=");
                    do {
                        pcVar9 = pcVar11;
                        pcVar11 = pcVar9 + 1;
                    } while (*pcVar9 != '\0');
                    local_8 = local_8 - (int)(intptr_t)(pcVar9 + -0x6dd58c);
                    for (; (pfVar12 = local_c, *(char*)local_c == ' ' || (*(char*)local_c == '\t')); local_c = reinterpret_cast<float*>((intptr_t)local_c + 1)) {
                        local_8 = local_8 + -1;
                        if (local_8 == 0) {
                            return 0x80004005;
                        }
                    }
                    iVar15 = FUN_005f909b();
                    if (iVar15 == 0) {
                        return 0x80004005;
                    }
                    FUN_005fb046((uint32_t)local_164, (uint32_t)iVar15 + 1);
                    iVar17 = sscanf(local_164, "%f%s", &local_3c, local_64);
                    if (iVar17 != 1) {
                        return 0x80004005;
                    }
                    local_c = reinterpret_cast<float*>((intptr_t)pfVar12 + iVar15 + 1);
                    local_8 = local_8 + (-1 - iVar15);
                    local_2c = local_3c * local_2c;
                    goto LAB_005fb539;
                }
            }
            iVar15 = FUN_005f909b();
            local_c = reinterpret_cast<float*>((intptr_t)pfVar12 + iVar15 + 1);
            local_8 = local_8 + (-1 - iVar15);
        }
LAB_005fb539:
    } while (0 < (int)local_8);
    bVar22 = false;
    if (!bVar21) {
        return 0x80004005;
    }
    local_14 = FUN_005f909b();
    if (local_14 < 3) {
        return 0x80004005;
    }
    FUN_005fb046((uint32_t)local_164, (uint32_t)local_14 + 1);
    if (local_164[1] == 'Y') {
        bVar21 = true;
        puVar10 = &local_20;
        if (local_164[0] == '-') {
            bVar22 = false;
        } else {
            if (local_164[0] != '+') {
                return 0x80004005;
            }
            bVar22 = true;
        }
    } else {
        if (local_164[1] != 'X') {
            return 0x80004005;
        }
        bVar21 = false;
        puVar10 = local_1c;
        if (local_164[0] == '-') {
            local_d = false;
        } else {
            if (local_164[0] != '+') {
                return 0x80004005;
            }
            local_d = true;
        }
    }
    iVar15 = sscanf(&local_164[2], "%u", puVar10);
    if (iVar15 != 1) {
        return 0x80004005;
    }
    pcVar11 = &local_164[2];
    if (local_164[2] == '\0') {
        return 0x80004005;
    }
    do {
        if ((local_164[2] == '-') || (local_164[2] == '+')) break;
        pcVar11 = pcVar11 + 1;
    } while (*pcVar11 != '\0');
    cVar1 = *pcVar11;
    if (cVar1 == '\0') {
        return 0x80004005;
    }
    if (bVar21) {
        local_d = cVar1 == '+';
        puVar10 = local_1c;
    } else {
        bVar22 = cVar1 == '+';
        puVar10 = &local_20;
    }
    cVar1 = pcVar11[1];
    if (cVar1 == '\0') {
        return 0x80004005;
    }
    if ((cVar1 != 'Y') && (cVar1 != 'X')) {
        return 0x80004005;
    }
    iVar15 = sscanf(pcVar11 + 2, "%u", puVar10);
    if (iVar15 != 1) {
        return 0x80004005;
    }
    in_ECX[0xd] = 0;
    local_c = reinterpret_cast<float*>((intptr_t)local_c + local_14 + 1);
    local_8 = local_8 + (-1 - local_14);
    in_ECX[3] = local_1c[0];
    *in_ECX = 0x74;
    in_ECX[0xc] = local_1c[0] * 0x10;
    in_ECX[4] = local_20;
    in_ECX[5] = 1;
    if (local_1c[0] * local_20 == 0) {
        return 0x80004005;
    }
    in_ECX[0xe] = 1;
    pfVar12 = reinterpret_cast<float*>(FUN_00533c78(local_1c[0] * 0x10 * local_20));
    in_ECX[1] = (uint32_t)(intptr_t)pfVar12;
    if (pfVar12 == (float*)0x0) {
        return 0x8007000e;
    }
    if (bVar21) {
        uVar13 = in_ECX[0xc];
        uVar7 = local_20;
        uVar8 = local_1c[0];
        if (local_d == false) {
            uVar19 = 0xfffffffc;
            if (bVar22) {
                iVar15 = uVar13 * local_20 + -0x10;
                goto LAB_005fb73a;
            }
            iVar15 = uVar13 - 0x10;
        } else {
            uVar19 = 4;
            if (!bVar22) {
                uVar13 = uVar13 >> 2;
                goto LAB_005fb78a;
            }
            iVar15 = (local_20 - 1) * uVar13;
LAB_005fb73a:
            uVar13 = -uVar13;
        }
        pfVar12 = reinterpret_cast<float*>(iVar15 + (intptr_t)pfVar12);
        uVar13 = uVar13 >> 2;
        goto LAB_005fb78c;
    }
    uVar19 = in_ECX[0xc];
    uVar7 = local_1c[0];
    uVar8 = local_20;
    if (local_d == false) {
        if (bVar22) {
            iVar15 = uVar19 * local_20 + -0x10;
            uVar13 = 0xfffffffc;
            goto LAB_005fb765;
        }
        iVar15 = uVar19 - 0x10;
        uVar13 = 0xfffffffc;
    } else {
        uVar13 = 4;
        if (!bVar22) {
            uVar19 = uVar19 >> 2;
LAB_005fb78a:
            goto LAB_005fb78c;
        }
        iVar15 = (local_20 - 1) * uVar19;
LAB_005fb765:
        uVar19 = -uVar19;
    }
    pfVar12 = reinterpret_cast<float*>(iVar15 + (intptr_t)pfVar12);
    uVar19 = uVar19 >> 2;
LAB_005fb78c:
    local_34 = 0;
    param_2 = local_c;
    if (0 < (int)uVar7) {
        local_44 = uVar13 * 4;
        local_24 = pfVar12;
        do {
            if ((int)local_8 < 4) {
LAB_005fba78:
                operator_delete(reinterpret_cast<void*>(in_ECX[1]));
                in_ECX[1] = 0;
                return 0x80004005;
            }
            fVar2 = *param_2;
            param_2 = param_2 + 1;
            local_8 = local_8 + -4;
            param_1 = reinterpret_cast<float*>((intptr_t)param_1 + 0);
            // byte extraction of R,G,B,E from fVar2 bits
            uint32_t fbytes = *reinterpret_cast<uint32_t*>(&fVar2);
            uint8_t b0 = (uint8_t)(fbytes & 0xff);
            uint8_t b1 = (uint8_t)((fbytes >> 8) & 0xff);
            uint8_t b2 = (uint8_t)((fbytes >> 16) & 0xff);
            uint8_t b3 = (uint8_t)((fbytes >> 24) & 0xff);
            (void)bVar16;
            if ((b0 == 0x02) || ((b1 == 2 && (b2 < 0x80)))) {
                if (((uint32_t)b2) != uVar8 && ((uint32_t)((b3 << 8) | b2) != uVar8)) {
                    if ((((uint32_t)b3 << 8) | b2) != uVar8) goto LAB_005fba78;
                }
                local_30 = 0;
                local_c = local_24;
                do {
                    iVar15 = 0;
                    param_1 = local_c;
                    if (0 < (int)uVar8) {
                        do {
                            if ((int)local_8 < 2) goto LAB_005fba78;
                            bVar16 = *(uint8_t*)param_2;
                            if (bVar16 < 0x81) {
                                uVar14 = (uint32_t)bVar16;
                                if (((int)local_8 < (int)(uVar14 + 1)) || ((iVar15 = iVar15 + (int)uVar14, local_38 = iVar15, (int)uVar8 < iVar15))) goto LAB_005fba78;
                                if (bVar16 != 0) {
                                    pfVar12 = param_2;
                                    local_14 = uVar14;
                                    do {
                                        pfVar12 = reinterpret_cast<float*>((intptr_t)pfVar12 + 1);
                                        local_40 = (uint32_t)*(uint8_t*)pfVar12;
                                        pfVar18 = param_1 + uVar19;
                                        local_14 = local_14 - 1;
                                        *param_1 = (float)local_40;
                                        param_1 = pfVar18;
                                    } while (local_14 != 0);
                                    local_14 = 0;
                                }
                                local_8 = local_8 + (-1 - uVar14);
                                param_2 = reinterpret_cast<float*>((intptr_t)param_2 + uVar14 + 1);
                            } else {
                                uVar14 = bVar16 & 0x7f;
                                iVar15 = iVar15 + uVar14;
                                if ((int)uVar8 < iVar15) goto LAB_005fba78;
                                local_14 = (uint32_t)*(uint8_t*)((intptr_t)param_2 + 1);
                                if ((bVar16 & 0x7f) != 0) {
                                    do {
                                        pfVar12 = param_1 + uVar19;
                                        *param_1 = (float)local_14;
                                        uVar14 = uVar14 - 1;
                                        param_1 = pfVar12;
                                    } while (uVar14 != 0);
                                }
                                param_2 = reinterpret_cast<float*>((intptr_t)param_2 + 2);
                                local_8 = local_8 + -2;
                            }
                        } while (iVar15 < (int)uVar8);
                    }
                    local_30 = local_30 + 1;
                    local_c = local_c + 1;
                } while (local_30 < 4);
            } else {
                local_c = (float*)0x0;
                iVar15 = 1;
                fVar2 = (float)(fbytes & 0xff);
                local_14 = (uint32_t)b2;
                fVar4 = (float)b1;
                fVar5 = (float)local_14;
                fVar6 = (float)b3;
                pfVar12 = local_24;
                if (1 < (int)uVar8) {
                    do {
                        if ((int)local_8 < 4) goto LAB_005fba78;
                        fVar3 = *param_2;
                        param_2 = param_2 + 1;
                        local_8 = local_8 + -4;
                        uint32_t fbytes2 = *reinterpret_cast<uint32_t*>(&fVar3);
                        uint8_t nb1 = (uint8_t)((fbytes2 >> 8) & 0xff);
                        uint8_t nb2 = (uint8_t)((fbytes2 >> 16) & 0xff);
                        uint8_t nb3 = (uint8_t)((fbytes2 >> 24) & 0xff);
                        uint8_t nb0 = (uint8_t)(fbytes2 & 0xff);
                        if (((nb0 == 0x01) && (nb1 == 1)) && (nb2 == 1)) {
                            iVar17 = (uint32_t)nb3 << ((uint8_t)(local_c ? 0 : 0) & 0x1f);
                            iVar15 = iVar15 + iVar17;
                            if ((int)uVar8 < iVar15) goto LAB_005fba78;
                            if (0 < iVar17) {
                                do {
                                    *pfVar12 = fVar2;
                                    pfVar12[1] = fVar4;
                                    pfVar12[2] = fVar5;
                                    pfVar12[3] = fVar6;
                                    pfVar12 = pfVar12 + uVar19;
                                    iVar17 = iVar17 + -1;
                                } while (iVar17 != 0);
                            }
                            local_c = local_c + 2;
                        } else {
                            local_c = (float*)0x0;
                            fVar2 = (float)(fbytes2 & 0xff);
                            local_14 = (uint32_t)nb2;
                            *pfVar12 = fVar2;
                            fVar4 = (float)nb1;
                            pfVar12[1] = fVar4;
                            fVar5 = (float)local_14;
                            iVar15 = iVar15 + 1;
                            pfVar12[2] = fVar5;
                            fVar6 = (float)nb3;
                            pfVar12[3] = fVar6;
                            pfVar12 = pfVar12 + uVar19;
                        }
                    } while (iVar15 < (int)uVar8);
                }
            }
            local_34 = local_34 + 1;
            local_24 = local_24 + uVar13;
        } while (local_34 < (int)uVar7);
    }
    uVar13 = 0;
    if (local_1c[0] * local_20 != 0) {
        fVar2 = 1.0f / local_2c;
        pfVar12 = reinterpret_cast<float*>(in_ECX[1] + 8);
        do {
            iVar15 = ftol() + -0x88;
            dVar23 = std::ldexp((double)(pfVar12[-2] + 0.5f), iVar15);
            pfVar12[-2] = (float)dVar23 * fVar2;
            dVar23 = std::ldexp((double)(pfVar12[-1] + 0.5f), iVar15);
            pfVar12[-1] = (float)dVar23 * fVar2;
            dVar23 = std::ldexp((double)(*pfVar12 + 0.5f), iVar15);
            uVar13 = uVar13 + 1;
            *pfVar12 = (float)dVar23 * fVar2;
            pfVar12[1] = 1.0f;
            pfVar12 = pfVar12 + 4;
        } while (uVar13 < local_1c[0] * local_20);
    }
    return 0;
}

// 0x5fba91 — observed shape: tries 9 format loaders by locale-order table (0,5,4,1,3,8,7,2,6); sets LC_NUMERIC to "C" during parse; on failure frees in_ECX[1]/[2] and resets header fields 0xe-0x14; on success fills param_3[0..6] (w, h, pitch flag, channel count via 0x13 chain, FUN_005f5ff4, locale type, ptr) and backfills 0x13/0x14 children (fields 8,9,6,7,10,0xb); returns 0x8876086c / 0x88760b59 / 0.
uint32_t FUN_005fba91(void* self, int param_1, int param_2, uint32_t* param_3, int param_4) {
    char* pcVar1;
    uint32_t uVar2;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    int iVar3;
    uint32_t* puVar4;
    char* pcVar5;
    uint32_t* puVar6;
    bool bVar7;
    char* local_30[10];
    uint32_t local_8;

    if ((param_1 == 0) || (param_2 == 0)) {
        return 0x8876086c;
    }
    if ((param_3 == (uint32_t*)0x0) && (param_4 == 0)) {
        return 0;
    }
    local_30[0] = (char*)0x0;
    local_30[1] = (char*)0x5;
    local_30[2] = (char*)0x4;
    local_30[3] = (char*)0x1;
    local_30[4] = (char*)0x3;
    local_30[5] = (char*)0x8;
    local_30[6] = (char*)0x7;
    local_30[7] = (char*)0x2;
    local_30[8] = (char*)0x6;
    pcVar1 = setlocale(4, (char*)0x0);
    local_30[9] = _strdup(pcVar1);
    if (local_30[9] != (char*)0x0) {
        iVar3 = 2;
        bVar7 = true;
        pcVar1 = local_30[9];
        pcVar5 = const_cast<char*>("C");
        do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar1 == *pcVar5;
            pcVar1 = pcVar1 + 1;
            pcVar5 = pcVar5 + 1;
        } while (bVar7);
        if (bVar7) goto LAB_005fbb34;
    }
    setlocale(4, "C");
LAB_005fbb34:
    local_8 = 0;
    iVar3 = param_2;
    do {
        in_ECX[0x10] = (uint32_t)param_4;
        pcVar1 = local_30[local_8];
        in_ECX[0x11] = 3;
        in_ECX[0x12] = (uint32_t)(intptr_t)pcVar1;
        switch ((uintptr_t)pcVar1) {
        case (uintptr_t)0:
            iVar3 = FUN_005fb012(reinterpret_cast<short*>(param_1), (uint32_t)param_2);
            break;
        case (uintptr_t)1:
            iVar3 = FUN_005fb012(reinterpret_cast<short*>(param_1), (uint32_t)param_2);
            break;
        case (uintptr_t)2:
            iVar3 = FUN_005fb012(reinterpret_cast<short*>(param_1), (uint32_t)param_2);
            break;
        case (uintptr_t)3:
            iVar3 = FUN_005fb012(reinterpret_cast<short*>(param_1), (uint32_t)param_2);
            break;
        case (uintptr_t)4:
            iVar3 = FUN_005fb012(reinterpret_cast<short*>(param_1), (uint32_t)param_2);
            break;
        case (uintptr_t)5:
            iVar3 = FUN_005fb012(reinterpret_cast<short*>(param_1), (uint32_t)param_2);
            break;
        case (uintptr_t)6:
            iVar3 = (int)FUN_005f90ec(param_1, param_2);
            break;
        case (uintptr_t)7:
            iVar3 = FUN_005fb308(self, reinterpret_cast<float*>(param_1), reinterpret_cast<float*>(param_2));
            break;
        case (uintptr_t)8:
            iVar3 = FUN_005fb063(self, reinterpret_cast<char*>(param_1), (uint32_t)param_2);
            break;
        default:
            iVar3 = FUN_005fb012(reinterpret_cast<short*>(param_1), (uint32_t)param_2);
            break;
        }
        if (-1 < iVar3) break;
        if ((reinterpret_cast<void*>(in_ECX[1]) != (void*)0x0) && (in_ECX[0xe] != 0)) {
            operator_delete(reinterpret_cast<void*>(in_ECX[1]));
        }
        if ((reinterpret_cast<void*>(in_ECX[2]) != (void*)0x0) && (in_ECX[0xf] != 0)) {
            operator_delete(reinterpret_cast<void*>(in_ECX[2]));
        }
        if (in_ECX[0x13] != 0) {
            FUN_005f907a(1);
        }
        if (in_ECX[0x14] != 0) {
            FUN_005f907a(1);
        }
        local_8 = local_8 + 1;
        in_ECX[1] = 0;
        in_ECX[2] = 0;
        in_ECX[0xe] = 0;
        in_ECX[0xf] = 0;
        in_ECX[0x13] = 0;
        in_ECX[0x14] = 0;
    } while (local_8 < 9);
    if (local_30[9] != (char*)0x0) {
        iVar3 = 2;
        bVar7 = true;
        pcVar1 = local_30[9];
        pcVar5 = const_cast<char*>("C");
        do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar1 == *pcVar5;
            pcVar1 = pcVar1 + 1;
            pcVar5 = pcVar5 + 1;
        } while (bVar7);
        if (!bVar7) {
            setlocale(4, local_30[9]);
        }
        free(local_30[9]);
    }
    if (local_8 == 9) {
        return 0x88760b59;
    }
    puVar4 = in_ECX;
    if (param_3 != (uint32_t*)0x0) {
        puVar6 = param_3;
        for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
        }
        *param_3 = in_ECX[3];
        param_3[1] = in_ECX[4];
        param_3[2] = in_ECX[5];
        param_3[3] = 1;
        uVar2 = (uint32_t)FUN_005f5ff4((int)*in_ECX);
        param_3[4] = uVar2;
        param_3[5] = in_ECX[0x11];
        param_3[6] = in_ECX[0x12];
        for (puVar6 = in_ECX; puVar6[0x13] != 0; puVar6 = reinterpret_cast<uint32_t*>(puVar6[0x13])) {
            param_3[3] = param_3[3] + 1;
        }
    }
    do {
        for (; in_ECX != (uint32_t*)0x0; in_ECX = reinterpret_cast<uint32_t*>(in_ECX[0x13])) {
            in_ECX[8] = in_ECX[3];
            in_ECX[9] = in_ECX[4];
            in_ECX[6] = 0;
            in_ECX[7] = 0;
            in_ECX[10] = 0;
            in_ECX[0xb] = in_ECX[5];
        }
        in_ECX = reinterpret_cast<uint32_t*>(puVar4[0x14]);
        puVar4 = in_ECX;
    } while (in_ECX != (uint32_t*)0x0);
    return 0;
}

// 0x5fbd43 — observed shape: clears fields [1] then [0] to 0; void.
void FUN_005fbd43(void* self) {
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    in_ECX[1] = 0;
    *in_ECX = 0;
}

// 0x5fbd4d — observed shape: releases two COM-style slot pointers ([1] then [0]) via vtable call (1) when non-null; void.
void FUN_005fbd4d(void* self) {
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    if ((uint32_t*)in_ECX[1] != (uint32_t*)0x0) {
        uint32_t* obj = reinterpret_cast<uint32_t*>(in_ECX[1]);
        uint32_t* vtbl = reinterpret_cast<uint32_t*>(*obj);
        void (*fn)(uint32_t) = reinterpret_cast<void(*)(uint32_t)>(vtbl[0]);
        fn(1);
    }
    if ((uint32_t*)*in_ECX != (uint32_t*)0x0) {
        uint32_t* obj = reinterpret_cast<uint32_t*>(*in_ECX);
        uint32_t* vtbl = reinterpret_cast<uint32_t*>(*obj);
        void (*fn)(uint32_t) = reinterpret_cast<void(*)(uint32_t)>(vtbl[0]);
        fn(1);
    }
}

// 0x5fbd6d — observed shape: floor wrapper: returns (float10)floor((double)param_1); double->extended.
double FUN_005fbd6d(float param_1) {
    double dVar1 = std::floor((double)param_1);
    return dVar1;
}

// 0x5fbd85 — observed shape: clears three dwords [0],[1],[2] to 0; void.
void FUN_005fbd85(void* self) {
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    *in_ECX = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
}

// ---------------------------------------------------------------------------
// Declarations for the definitions appended below (same translation unit).
// ---------------------------------------------------------------------------
extern double FUN_005fbd6d(float);
extern uint32_t FUN_005fc059(void*);
extern uint32_t FUN_005fc1b1(uint32_t*, uint32_t, int32_t, uint32_t, int32_t, int32_t);
extern void FUN_005fc2db(void*);
extern uint32_t FUN_005fc2fd(uint32_t*, uint32_t, uint32_t*, uint32_t, int32_t, int32_t);
extern uint32_t FUN_005fc3e9(uint64_t*, uint64_t*, uint32_t, int32_t, int32_t, int32_t);
extern void FUN_005fc503(void);
extern void FUN_005fc53d(void);
extern void FUN_005fc56e(void*);
extern uint32_t FUN_005fc590(void*);

extern void* PTR_FUN_00719294;   // downscale/dither kernel slot A (FUN_005fc1b1 or FUN_005fc3e9)
extern void* PTR_FUN_00719298;   // downscale/dither kernel slot B (FUN_005fc2fd or FUN_005fc3e9)
extern uint8_t DAT_00800080;     // 0x00800080 bias word used by the 2x2 average

// 0x5fbd9b — observed shape: builds a per-scanline coverage table for a param_1-step
// ramp: allocates 0x10 + (0xc + n*0x10) bytes through FUN_00533c78, one span record
// (pixel index, accumulated coverage) per scanline band, 2 subsamples per axis,
// coverage = clipped trapezoid width * (0.5/step) - sample offset, second subsample
// mirrored by 1-x; param_3==0 additionally clamps samples to [0,param_2] and
// replaces the trapezoid weight with 0/1 edges. Returns the table (header dword =
// total byte size) or null.
int* FUN_005fbd9b(uint32_t param_1, int32_t param_2, int32_t param_3) {
    int* piVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    int iVar9;
    int* piVar10;
    int iVar11;
    int iVar12;
    int iVar13;
    int iVar14;
    uint32_t uVar15;
    int32_t local_28;
    float local_24;
    uint32_t local_1c;
    float local_18;
    uint32_t local_10;
    float local_c;
    float local_8;

    uVar15 = 0;
    if ((param_1 != 0) && (param_2 != 0)) {
        fVar2 = (float)param_2;
        if (param_2 < 0) {
            fVar2 = fVar2 + 4.2949673e+09f;
        }
        fVar3 = (float)(int32_t)param_1;
        if ((int32_t)param_1 < 0) {
            fVar3 = fVar3 + 4.2949673e+09f;
        }
        fVar4 = fVar2 / fVar3;
        iVar14 = 0x10;
        if (param_1 != 0) {
            do {
                iVar9 = ftol();
                uVar15 = uVar15 + 1;
                iVar14 = iVar14 + 0xc + iVar9 * 0x10;
            } while (uVar15 < param_1);
        }
        piVar10 = reinterpret_cast<int*>(FUN_00533c78((unsigned int)iVar14));
        if (piVar10 != reinterpret_cast<int*>(0x0)) {
            iVar9 = 0;
            local_1c = 0;
            iVar14 = 4;
            iVar13 = iVar14;
            if (param_1 != 0) {
                do {
                    local_8 = 0.0f;
                    local_10 = 0;
                    fVar5 = (float)(int32_t)local_1c;
                    iVar14 = iVar13 + 4;
                    if ((int32_t)local_1c < 0) {
                        fVar5 = fVar5 + 4.2949673e+09f;
                    }
                    do {
                        fVar6 = (float)(int32_t)local_10;
                        if ((int32_t)local_10 < 0) {
                            fVar6 = fVar6 + 4.2949673e+09f;
                        }
                        fVar6 = (fVar6 + fVar5) - 0.5f;
                        local_24 = fVar6 * fVar4;
                        local_c = fVar4 + local_24;
                        if (param_3 == 0) {
                            if (local_24 < 0.0f) {
                                local_24 = 0.0f;
                            }
                            if (fVar2 < local_c) {
                                local_c = fVar2;
                            }
                        }
                        FUN_005fbd6d(local_24);
                        iVar11 = ftol();
                        fVar7 = (float)iVar11;
                        if (fVar7 < local_c) {
                            local_28 = iVar11 - param_2;
                            do {
                                local_18 = fVar7 + 1.0f;
                                if (iVar11 < 0) {
                                    iVar12 = iVar11 + param_2;
                                } else {
                                    iVar12 = local_28;
                                    if (iVar11 < param_2) {
                                        iVar12 = iVar11;
                                    }
                                }
                                if (iVar12 != iVar9) {
                                    if (1e-05f < local_8) {
                                        piVar1 = reinterpret_cast<int*>(
                                            static_cast<intptr_t>(iVar14) +
                                            reinterpret_cast<intptr_t>(piVar10));
                                        *piVar1 = iVar9;
                                        iVar14 = iVar14 + 8;
                                        piVar1[1] = (int32_t)local_8;
                                    }
                                    local_8 = 0.0f;
                                    iVar9 = iVar12;
                                }
                                if (fVar7 < local_24) {
                                    fVar7 = local_24;
                                }
                                if (local_c < local_18) {
                                    local_18 = local_c;
                                }
                                if (param_3 == 0) {
                                    if (0.0f <= fVar6) {
                                        if (fVar6 + 1.0f < fVar3) goto LAB_005fbfc1;
                                        fVar8 = 0.0f;
                                    } else {
                                        fVar8 = 1.0f;
                                    }
                                } else {
LAB_005fbfc1:
                                    fVar8 = (local_18 + fVar7) * (0.5f / fVar4) - fVar6;
                                }
                                if (local_10 != 0) {
                                    fVar8 = 1.0f - fVar8;
                                }
                                iVar11 = iVar11 + 1;
                                local_28 = local_28 + 1;
                                local_8 = (local_18 - fVar7) * fVar8 + local_8;
                                fVar7 = (float)iVar11;
                            } while (fVar7 < local_c);
                        }
                        local_10 = local_10 + 1;
                    } while (local_10 < 2);
                    if (1e-05f < local_8) {
                        piVar1 = reinterpret_cast<int*>(
                            static_cast<intptr_t>(iVar14) + reinterpret_cast<intptr_t>(piVar10));
                        iVar14 = iVar14 + 8;
                        *piVar1 = iVar9;
                        piVar1[1] = (int32_t)local_8;
                    }
                    local_1c = local_1c + 1;
                    *reinterpret_cast<int*>(
                        static_cast<intptr_t>(iVar13) + reinterpret_cast<intptr_t>(piVar10)) =
                        iVar14 - iVar13;
                    iVar13 = iVar14;
                } while (local_1c < param_1);
            }
            *piVar10 = iVar14;
            return piVar10;
        }
    }
    return reinterpret_cast<int*>(0x0);
}

// 0x5fc059 — observed shape: 2x2 downscale of one surface into another through a
// straight 32-bit copy: rejects when either surface's 0x3c/0x40/0x44/0x48 dword OR
// has low 2 bits set; reads the FourCC at +4 of the source (DXT1 -> 8, DXT2..DXT5 ->
// 0x10, anything else fails), computes source/destination base addresses from
// (x>>2)*row + plane*0x4c + (y>>2)*elem + base, then copies height(+0x70) rows of
// width(+0x6c) elements of uVar5 bytes with the dword loop plus byte tail.
uint32_t FUN_005fc059(void* self) {
    int32_t iVar1;
    uint32_t uVar2;
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    uint32_t uVar3;
    int32_t iVar4;
    uint32_t uVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    uint32_t* puVar9;
    uint32_t* local_14;
    uint32_t local_10;
    uint32_t* local_c;
    uint32_t local_8;

    iVar4 = *in_ECX;
    if (((*reinterpret_cast<uint32_t*>(iVar4 + 0x48) |
          *reinterpret_cast<uint32_t*>(iVar4 + 0x44) |
          *reinterpret_cast<uint32_t*>(iVar4 + 0x3c) |
          *reinterpret_cast<uint32_t*>(iVar4 + 0x40)) & 3) != 0) {
        return 0x80004005;
    }
    iVar1 = in_ECX[1];
    if (((*reinterpret_cast<uint32_t*>(iVar1 + 0x48) |
          *reinterpret_cast<uint32_t*>(iVar1 + 0x44) |
          *reinterpret_cast<uint32_t*>(iVar1 + 0x40) |
          *reinterpret_cast<uint32_t*>(iVar1 + 0x3c)) & 3) == 0) {
        iVar1 = *reinterpret_cast<int32_t*>(in_ECX[1] + 4);
        if (iVar1 == 0x31545844) {
            local_8 = 8;
        } else {
            if (((iVar1 != 0x32545844) && (iVar1 != 0x33545844)) &&
                ((iVar1 != 0x34545844) && (iVar1 != 0x35545844))) goto LAB_005fc09e;
            local_8 = 0x10;
        }
        iVar1 = in_ECX[1];
        uVar5 = (*reinterpret_cast<uint32_t*>(iVar1 + 0x68) >> 2) * local_8;
        local_10 = 0;
        puVar6 = reinterpret_cast<uint32_t*>(
            (*reinterpret_cast<uint32_t*>(iVar1 + 0x40) >> 2) *
                *reinterpret_cast<int32_t*>(iVar1 + 0x60) +
            *reinterpret_cast<int32_t*>(iVar1 + 0x64) *
                *reinterpret_cast<int32_t*>(iVar1 + 0x4c) +
            (*reinterpret_cast<uint32_t*>(iVar1 + 0x3c) >> 2) * local_8 +
            *reinterpret_cast<int32_t*>(iVar1 + 0x20));
        local_c = reinterpret_cast<uint32_t*>(
            (*reinterpret_cast<uint32_t*>(iVar4 + 0x40) >> 2) *
                *reinterpret_cast<int32_t*>(iVar4 + 0x60) +
            *reinterpret_cast<int32_t*>(iVar4 + 0x64) *
                *reinterpret_cast<int32_t*>(iVar4 + 0x4c) +
            (*reinterpret_cast<uint32_t*>(iVar4 + 0x3c) >> 2) * local_8 +
            *reinterpret_cast<int32_t*>(iVar4 + 0x20));
        if (*reinterpret_cast<int32_t*>(in_ECX[1] + 0x70) != 0) {
            uVar3 = *reinterpret_cast<uint32_t*>(in_ECX[1] + 0x6c);
            do {
                local_8 = 0;
                puVar8 = local_c;
                local_14 = puVar6;
                if (uVar3 != 0) {
                    do {
                        local_8 = local_8 + 4;
                        puVar7 = puVar8;
                        puVar9 = local_14;
                        for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                            *puVar9 = *puVar7;
                            puVar7 = puVar7 + 1;
                            puVar9 = puVar9 + 1;
                        }
                        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                            *reinterpret_cast<uint8_t*>(puVar9) =
                                *reinterpret_cast<uint8_t*>(puVar7);
                            puVar7 = reinterpret_cast<uint32_t*>(
                                reinterpret_cast<intptr_t>(puVar7) + 1);
                            puVar9 = reinterpret_cast<uint32_t*>(
                                reinterpret_cast<intptr_t>(puVar9) + 1);
                        }
                        local_14 = reinterpret_cast<uint32_t*>(
                            reinterpret_cast<intptr_t>(local_14) +
                            *reinterpret_cast<int32_t*>(in_ECX[1] + 0x60));
                        puVar8 = reinterpret_cast<uint32_t*>(
                            reinterpret_cast<intptr_t>(puVar8) +
                            *reinterpret_cast<int32_t*>(*in_ECX + 0x60));
                        uVar3 = *reinterpret_cast<uint32_t*>(in_ECX[1] + 0x6c);
                    } while (local_8 < uVar3);
                }
                local_c = reinterpret_cast<uint32_t*>(
                    reinterpret_cast<intptr_t>(local_c) +
                    *reinterpret_cast<int32_t*>(*in_ECX + 0x64));
                puVar6 = reinterpret_cast<uint32_t*>(
                    reinterpret_cast<intptr_t>(puVar6) +
                    *reinterpret_cast<int32_t*>(in_ECX[1] + 0x64));
                local_10 = local_10 + 1;
            } while (local_10 < *reinterpret_cast<uint32_t*>(in_ECX[1] + 0x70));
        }
        uVar2 = 0;
    } else {
LAB_005fc09e:
        uVar2 = 0x80004005;
    }
    return uVar2;
}

// 0x5fc1b1 — observed shape: 2x2 box downscale using 32-bit packed averaging: each
// destination pixel sums the four source pixels (left/right on two rows) with
// per-field rounding (+0x20002 / -0x7fff80 for the 0xff00ff fields, +0x40 /
// +0x800080 for the 0x3fc03fc0 fields) then shifts right by 2; advances the source
// by 2 rows (param_5*2) and the destination by param_6 bytes per band.
uint32_t FUN_005fc1b1(uint32_t* param_1, uint32_t param_2, int32_t param_3, uint32_t param_4,
                      int32_t param_5, int32_t param_6) {
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    int32_t local_14;
    uint32_t* local_10;
    uint32_t* local_8;

    uVar5 = param_4 * param_5 + param_2;
    if (param_2 < uVar5) {
        param_4 = param_2 + (uint32_t)param_3 * 4;
        do {
            local_8 = param_1;
            if (param_2 < param_4) {
                local_10 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(param_2) + 4);
                local_14 = (int32_t)(((param_4 - param_2) - 1) >> 3) + 1;
                do {
                    uVar1 = *reinterpret_cast<uint32_t*>(
                        reinterpret_cast<intptr_t>(local_10) + param_5);
                    uVar2 = *reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(param_5) - 4 +
                        reinterpret_cast<intptr_t>(local_10));
                    uVar3 = *local_10;
                    uVar4 = local_10[-1];
                    *local_8 =
                        (((((uVar4 >> 2 & 0xffc03fc0) + (uVar2 >> 2 & 0xffc03fc0) +
                            (uVar1 >> 2 & 0xffc03fc0) + (uint32_t)-0x7fff80 +
                            (uVar3 >> 2 & 0xffc03fc0)) ^
                           (((uVar4 & 0xff00ff) + (uVar2 & 0xff00ff) + (uVar1 & 0xff00ff) +
                             0x20002 + (uVar3 & 0xff00ff)) >> 2)) & 0xff00ff) ^
                         (uint32_t)(reinterpret_cast<uintptr_t>(&DAT_00800080) +
                                    (uVar3 >> 2 & 0x3fc03fc0) +
                                    (uVar4 >> 2 & 0x3fc03fc0) +
                                    (uVar2 >> 2 & 0x3fc03fc0) +
                                    (uVar1 >> 2 & 0x3fc03fc0));
                    local_10 = local_10 + 2;
                    local_14 = local_14 + -1;
                    local_8 = local_8 + 1;
                } while (local_14 != 0);
            }
            param_1 = reinterpret_cast<uint32_t*>(
                reinterpret_cast<intptr_t>(param_1) + param_6);
            param_4 = param_4 + param_5 * 2;
            param_2 = param_2 + param_5 * 2;
        } while (param_2 < uVar5);
    }
    return 0;
}

// 0x5fc2db — observed shape: dispatches the current downscale kernel slot
// (PTR_FUN_00719294) over both surface base pointers with widths/heights/strides
// taken from the two surface headers (+0x68, +0x6c, +0x60).
void FUN_005fc2db(void* self) {
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    int32_t iVar1;

    iVar1 = *in_ECX;
    reinterpret_cast<void (*)(void*, void*, uint32_t, uint32_t, int32_t, int32_t)>(
        PTR_FUN_00719294)(*reinterpret_cast<void**>(in_ECX[1] + 0x20),
                          *reinterpret_cast<void**>(iVar1 + 0x20),
                          *reinterpret_cast<uint32_t*>(iVar1 + 0x68),
                          *reinterpret_cast<uint32_t*>(iVar1 + 0x6c),
                          *reinterpret_cast<int32_t*>(iVar1 + 0x60),
                          *reinterpret_cast<uint32_t*>(in_ECX[1] + 0x60));
}

// 0x5fc2fd — observed shape: 2x2 box downscale for non-vectorised widths: sums the
// red/blue fields (0xff00ff) with +0x20002 and the green/alpha fields (0xff00) with
// +0x200, masks with 0x3fc03fc / 0x3fc00, ors and shifts right by 2; source steps
// two rows (param_5*2) per band, destination advances param_6 bytes.
uint32_t FUN_005fc2fd(uint32_t* param_1, uint32_t param_2, uint32_t* param_3, uint32_t param_4,
                      int32_t param_5, int32_t param_6) {
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t* puVar6;
    int32_t local_10;

    uVar5 = param_4 * param_5 + param_2;
    if (param_2 < uVar5) {
        param_4 = param_2 + static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_3)) * 4;
        do {
            param_3 = param_1;
            if (param_2 < param_4) {
                local_10 = (int32_t)(((param_4 - param_2) - 1) >> 3) + 1;
                puVar6 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(param_2) + 4);
                do {
                    puVar2 = reinterpret_cast<uint32_t*>(
                        reinterpret_cast<intptr_t>(puVar6) + param_5);
                    uVar3 = *puVar6;
                    uVar4 = *reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(param_5) - 4 +
                        reinterpret_cast<intptr_t>(puVar6));
                    puVar1 = puVar6 + -1;
                    puVar6 = puVar6 + 2;
                    local_10 = local_10 + -1;
                    *param_3 =
                        ((((*puVar1 & 0xff00ff) + (uVar4 & 0xff00ff) + (*puVar2 & 0xff00ff) +
                           0x20002 + (uVar3 & 0xff00ff)) & 0x3fc03fc) |
                         (((*puVar1 & 0xff00) + (uVar4 & 0xff00) + (*puVar2 & 0xff00) + 0x200 +
                           (uVar3 & 0xff00)) & 0x3fc00)) >> 2;
                    param_3 = param_3 + 1;
                } while (local_10 != 0);
            }
            param_1 = reinterpret_cast<uint32_t*>(
                reinterpret_cast<intptr_t>(param_1) + param_6);
            param_4 = param_4 + param_5 * 2;
            param_2 = param_2 + param_5 * 2;
        } while (param_2 < uVar5);
    }
    return 0;
}

// 0x5fc3e9 — observed shape: vectorised 2x2 box downscale. When the width is a
// multiple of 4 it walks two 64-bit words per row pair: each 16-bit lane holds
// byte(k)+byte(k+4) of both rows' words plus 2, shifted right by 2 (psraw), and each
// of the eight result bytes saturates to 0..255 by channel. Otherwise it tail-calls
// FUN_005fc1b1.
uint32_t FUN_005fc3e9(uint64_t* param_1, uint64_t* param_2, uint32_t param_3, int32_t param_4,
                      int32_t param_5, int32_t param_6) {
    uint32_t uVar12;

    if ((param_3 & 3) == 0) {
        uint64_t* puVar13 = reinterpret_cast<uint64_t*>(
            static_cast<intptr_t>(param_4) * param_5 +
            reinterpret_cast<intptr_t>(param_2));
        for (; reinterpret_cast<intptr_t>(param_2) < reinterpret_cast<intptr_t>(puVar13);
             param_2 = reinterpret_cast<uint64_t*>(
                 reinterpret_cast<intptr_t>(param_2) + param_5 * 2)) {
            uint64_t* puVar14 = reinterpret_cast<uint64_t*>(
                reinterpret_cast<intptr_t>(param_2) + param_5);
            uint64_t* puVar15 = param_2;
            uint64_t* puVar11 = param_1;
            while (reinterpret_cast<intptr_t>(puVar15) <
                   reinterpret_cast<intptr_t>(param_2) + static_cast<intptr_t>(param_3) * 4) {
                uint64_t uVar16 = *puVar15;
                uint64_t uVar17 = *puVar14;
                uint64_t uVar1 = puVar15[1];
                uint64_t uVar2 = puVar14[1];
                uint64_t packed = 0;
                puVar15 = puVar15 + 2;
                puVar14 = puVar14 + 2;
                for (int32_t k = 0; k < 4; k = k + 1) {
                    int32_t sFirst = static_cast<int32_t>((uVar16 >> (8 * k)) & 0xff) +
                                     static_cast<int32_t>((uVar16 >> (8 * (k + 4))) & 0xff) +
                                     static_cast<int32_t>((uVar17 >> (8 * k)) & 0xff) +
                                     static_cast<int32_t>((uVar17 >> (8 * (k + 4))) & 0xff) + 2;
                    int32_t sSecond = static_cast<int32_t>((uVar1 >> (8 * k)) & 0xff) +
                                      static_cast<int32_t>((uVar1 >> (8 * (k + 4))) & 0xff) +
                                      static_cast<int32_t>((uVar2 >> (8 * k)) & 0xff) +
                                      static_cast<int32_t>((uVar2 >> (8 * (k + 4))) & 0xff) + 2;
                    sFirst = sFirst >> 2;
                    sSecond = sSecond >> 2;
                    uint32_t bFirst = static_cast<uint32_t>(
                        (0 < sFirst) * (sFirst < 0x100) *
                            static_cast<int32_t>(static_cast<int8_t>(sFirst)) -
                        (0xff < sFirst));
                    uint32_t bSecond = static_cast<uint32_t>(
                        (0 < sSecond) * (sSecond < 0x100) *
                            static_cast<int32_t>(static_cast<int8_t>(sSecond)) -
                        (0xff < sSecond));
                    packed = packed | (static_cast<uint64_t>(bFirst & 0xff) << (8 * k));
                    packed = packed | (static_cast<uint64_t>(bSecond & 0xff) << (8 * (k + 4)));
                }
                *puVar11 = packed;
                puVar11 = puVar11 + 1;
            }
            param_1 = reinterpret_cast<uint64_t*>(
                reinterpret_cast<intptr_t>(param_1) + param_6);
        }
        uVar12 = 0;
    } else {
        uVar12 = FUN_005fc1b1(reinterpret_cast<uint32_t*>(param_1),
                              static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_2)),
                              param_3, param_4, param_5, param_6);
    }
    return uVar12;
}

// 0x5fc503 — observed shape: selects the downscale kernels from FUN_005f8bed; when it
// returns 0 the scalar pair FUN_005fc1b1/FUN_005fc2fd is installed, otherwise both
// slots take the vectorised FUN_005fc3e9; then tail-calls the freshly installed slot.
void FUN_005fc503(void) {
    int32_t iVar1;

    iVar1 = FUN_005f8bed();
    if (iVar1 == 0) {
        PTR_FUN_00719294 = reinterpret_cast<void*>(FUN_005fc1b1);
        PTR_FUN_00719298 = reinterpret_cast<void*>(FUN_005fc2fd);
    } else {
        PTR_FUN_00719294 = reinterpret_cast<void*>(FUN_005fc3e9);
        PTR_FUN_00719298 = reinterpret_cast<void*>(FUN_005fc3e9);
    }
    /* indirect jump with the caller's registers: no explicit arguments */
    reinterpret_cast<void (*)(void)>(PTR_FUN_00719294)();
}

// 0x5fc53d — observed shape: same kernel selection as 0x5fc503 but the pending call
// target is kept in a local: slot A and the local both take FUN_005fc1b1/FUN_005fc2fd
// when FUN_005f8bed returns 0, otherwise both take FUN_005fc3e9; slot B receives the
// local and that target is tail-called.
void FUN_005fc53d(void) {
    int32_t iVar1;
    void (*UNRECOVERED_JUMPTABLE)(void);

    iVar1 = FUN_005f8bed();
    if (iVar1 == 0) {
        PTR_FUN_00719294 = reinterpret_cast<void*>(FUN_005fc1b1);
        UNRECOVERED_JUMPTABLE = reinterpret_cast<void (*)(void)>(FUN_005fc2fd);
    } else {
        UNRECOVERED_JUMPTABLE = reinterpret_cast<void (*)(void)>(FUN_005fc3e9);
        PTR_FUN_00719294 = reinterpret_cast<void*>(FUN_005fc3e9);
    }
    PTR_FUN_00719298 = reinterpret_cast<void*>(UNRECOVERED_JUMPTABLE);
    UNRECOVERED_JUMPTABLE();
}

// 0x5fc56e — observed shape: dispatches the second downscale kernel slot
// (PTR_FUN_00719298) over both surface base pointers with the same header fields
// (+0x20, +0x68, +0x6c, +0x60) as 0x5fc2db.
void FUN_005fc56e(void* self) {
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    int32_t iVar1;

    iVar1 = *in_ECX;
    reinterpret_cast<void (*)(void*, void*, uint32_t, uint32_t, int32_t, int32_t)>(
        PTR_FUN_00719298)(*reinterpret_cast<void**>(in_ECX[1] + 0x20),
                          *reinterpret_cast<void**>(iVar1 + 0x20),
                          *reinterpret_cast<uint32_t*>(iVar1 + 0x68),
                          *reinterpret_cast<uint32_t*>(iVar1 + 0x6c),
                          *reinterpret_cast<int32_t*>(iVar1 + 0x60),
                          *reinterpret_cast<uint32_t*>(in_ECX[1] + 0x60));
}

// 0x5fc590 — observed shape: 2x2 box downscale for 16-bit (RGB565) pixels: each
// destination word averages the four source words, red/blue fields (0xf81f) with
// +0x1002, green fields (0x07e0) with +0x40, shifting right by 2; reads the row pair
// (row + stride) and advances the destination by the second surface stride.
uint32_t FUN_005fc590(void* self) {
    uint16_t uVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    int32_t iVar4;
    uint16_t* puVar5;
    int32_t iVar6;
    uint16_t* puVar7;
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    uint32_t uVar8;
    uint16_t* puVar9;
    uint16_t* puVar10;
    uint16_t* puVar11;
    uint16_t* puVar12;

    iVar4 = *in_ECX;
    puVar9 = *reinterpret_cast<uint16_t**>(in_ECX[1] + 0x20);
    puVar5 = *reinterpret_cast<uint16_t**>(iVar4 + 0x20);
    puVar11 = reinterpret_cast<uint16_t*>(
        *reinterpret_cast<int32_t*>(iVar4 + 0x6c) *
            *reinterpret_cast<int32_t*>(iVar4 + 0x60) +
        reinterpret_cast<intptr_t>(puVar5));
    for (; puVar5 < puVar11;
         puVar5 = puVar5 + *reinterpret_cast<int32_t*>(iVar4 + 0x60)) {
        iVar6 = *reinterpret_cast<int32_t*>(iVar4 + 0x68);
        puVar12 = reinterpret_cast<uint16_t*>(
            *reinterpret_cast<int32_t*>(iVar4 + 0x60) +
            reinterpret_cast<intptr_t>(puVar5));
        puVar7 = puVar9;
        for (puVar10 = puVar5; puVar10 < puVar5 + iVar6; puVar10 = puVar10 + 2) {
            uVar8 = (uint32_t)*puVar12;
            uVar1 = puVar12[1];
            uVar2 = puVar10[1];
            uVar3 = *puVar10;
            *puVar7 = (uint16_t)(
                ((uint16_t)(((uint32_t)(uVar1 & 0xf81f) + (uint32_t)(uVar3 & 0xf81f) +
                             (uVar8 & 0xfffff81f) + 0x1002 + (uint32_t)(uVar2 & 0xf81f)) ^
                            ((uint32_t)(uVar1 & 0xffff07e0) + (uint32_t)(uVar3 & 0xffff07e0) +
                             (uVar8 & 0xffff07e0) + 0x40 + (uint32_t)(uVar2 & 0xffff07e0))) >>
                 2) &
                    0x7e0) ^
                (uint16_t)(((uVar1 & 0xf81f) + (uVar3 & 0xf81f) + (uVar8 & 0xf81f) + 0x1002 +
                            (uVar2 & 0xf81f)) >>
                           2);
            puVar12 = puVar12 + 2;
            puVar7 = puVar7 + 1;
        }
        puVar9 = reinterpret_cast<uint16_t*>(
            reinterpret_cast<intptr_t>(puVar9) +
            *reinterpret_cast<int32_t*>(in_ECX[1] + 0x60));
        iVar4 = *in_ECX;
    }
    return 0;
}
