#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void* p);
extern void* FUN_00533c78(uint32_t size);

extern FARPROC DAT_00729a5c;
extern FARPROC DAT_00729a58;
extern int DAT_00718a64;
extern int DAT_00729a60;

// 0x5f8e43 — observed shape
uint32_t FUN_005f8e43(LPBYTE param_1, LPCSTR param_2, LPBYTE param_3, DWORD param_4) {
    LSTATUS LVar1;
    HKEY local_8;
    local_8 = (HKEY)0x0;
    LVar1 = RegOpenKeyA((HKEY)0x80000002, "Software\\Microsoft\\Direct3D", &local_8);
    if (LVar1 == 0) {
        LVar1 = RegQueryValueExA(local_8, param_2, (LPDWORD)0x0, (LPDWORD)&param_3, param_3, &param_4);
        RegCloseKey(local_8);
        if ((LVar1 == 0) && (param_3 == param_1)) {
            return 1;
        }
    }
    return 0;
}

// 0x5f8ea2 — observed shape
void FUN_005f8ea2(uint32_t param_1) {
    HMODULE pHVar1;
    int iVar2;
    if ((DAT_00729a5c == (FARPROC)0x0) && (DAT_00729a58 == (FARPROC)0x0)) {
        pHVar1 = GetModuleHandleA("d3d9.dll");
        if ((pHVar1 != (HMODULE)0x0) && (pHVar1 = LoadLibraryA("d3d9.dll"), pHVar1 != (HMODULE)0x0)) {
            DAT_00729a5c = GetProcAddress(pHVar1, "DebugSetMute");
        }
        pHVar1 = GetModuleHandleA("d3d9d.dll");
        if ((pHVar1 != (HMODULE)0x0) && (pHVar1 = LoadLibraryA("d3d9d.dll"), pHVar1 != (HMODULE)0x0)) {
            DAT_00729a58 = GetProcAddress(pHVar1, "DebugSetMute");
        }
    }
    if (DAT_00718a64 == -1) {
        iVar2 = (int)FUN_005f8e43((LPBYTE)4, "D3DXDoNotMute", (LPBYTE)&DAT_00718a64, 4);
        if (iVar2 == 0) {
            DAT_00718a64 = 0;
        }
        if (DAT_00718a64 == 0) goto LAB_005f8f55;
        DAT_00718a64 = 1;
    }
    if (DAT_00718a64 != 0) {
        return;
    }
LAB_005f8f55:
    if (DAT_00729a5c != (FARPROC)0x0) {
        ((void(*)(uint32_t))DAT_00729a5c)(param_1);
    }
    if (DAT_00729a58 != (FARPROC)0x0) {
        ((void(*)(uint32_t))DAT_00729a58)(param_1);
    }
    return;
}

// 0x5f8f77 — observed shape
void FUN_005f8f77(void) {
    bool bVar1;
    void* pvVar2;
    void* pvVar3;
    if (DAT_00729a60 == 0) {
        DAT_00729a60 = 1;
        bVar1 = false;
        pvVar2 = (void*)FUN_00533c78(0);
        pvVar3 = (void*)FUN_00533c78(0);
        if (((pvVar2 == (void*)0x0) || (pvVar3 == (void*)0x0)) || (pvVar2 == pvVar3)) {
            bVar1 = true;
        }
        if (pvVar2 != (void*)0x0) {
            operator_delete(pvVar2);
        }
        if ((pvVar3 != (void*)0x0) && (pvVar3 != pvVar2)) {
            operator_delete(pvVar3);
        }
        operator_delete((void*)0x0);
        if (bVar1) {
            OutputDebugStringA("D3DX: (WARN) Overloaded ::new and ::delete operators do not conform to C++ standards:\r\n");
            OutputDebugStringA("D3DX: (WARN) An allocation of zero bytes should return a unique non-null pointer to at\r\n");
            OutputDebugStringA("D3DX: (WARN) least zero bytes. Deletion of a null pointer should quietly do nothing.\r\n");
            OutputDebugStringA("D3DX: (WARN) D3DX relies upon this behavior.\r\n");
        }
    }
    return;
}

// 0x5f9006 — observed shape
void FUN_005f9006(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x14] = 0;
    return;
}

// 0x5f901f — observed shape
void FUN_005f901f(void* self) {
    void* pvVar1;
    int in_ECX = (int)self;
    if ((*(void**)(in_ECX + 4) != (void*)0x0) && (*(int*)(in_ECX + 0x38) != 0)) {
        operator_delete(*(void**)(in_ECX + 4));
    }
    if ((*(void**)(in_ECX + 8) != (void*)0x0) && (*(int*)(in_ECX + 0x3c) != 0)) {
        operator_delete(*(void**)(in_ECX + 8));
    }
    pvVar1 = *(void**)(in_ECX + 0x4c);
    if (pvVar1 != (void*)0x0) {
        FUN_005f901f(pvVar1);
        operator_delete(pvVar1);
    }
    pvVar1 = *(void**)(in_ECX + 0x50);
    if (pvVar1 != (void*)0x0) {
        FUN_005f901f(pvVar1);
        operator_delete(pvVar1);
    }
    return;
}

// 0x5f907a — observed shape
void FUN_005f907a(uint8_t param_1, void* self) {
    void* in_ECX = self;
    FUN_005f901f(in_ECX);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x5f909b — observed shape
uint32_t FUN_005f909b(int param_1, uint32_t param_2) {
    uint32_t uVar1;
    uVar1 = 0;
    if (param_2 != 0) {
        do {
            if (*(char*)(uVar1 + param_1) == '\n') {
                return uVar1;
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < param_2);
    }
    return 0;
}

// 0x5f90bc — observed shape
long double FUN_005f90bc(uint32_t param_1) {
    return (long double)(float)(((param_1 & 0xff00) + param_1 * 0x10000) * 0x100 + (param_1 >> 0x10 & 0xff) * 0x100 + (param_1 >> 0x18));
}

// 0x5f90ec — observed shape
// NEEDS_MANUAL: large BMP/DIB decoder; full branch structure preserved in reconstructed form below with observed offsets and constants where source elides in reads.
uint32_t FUN_005f90ec(uint32_t* param_1, uint8_t* param_2, void* self) {
    uint32_t uVar17;
    uint32_t uVar6;
    uint16_t uVar3;
    int iVar7;
    uint8_t bVar10;
    int* in_ECX = (int*)self;
    uint8_t* pbVar11;
    uint8_t* pbVar12;
    uint8_t* pbVar14;
    uint8_t* local_1c;
    uint8_t* local_18;
    uint32_t* puVar13;
    uint32_t local_20;
    uint32_t local_30;
    uint32_t local_2c;
    uint8_t* local_24;
    uint32_t local_34;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_28;
    uint32_t local_88;
    int local_84;
    int local_80;
    int local_8;
    int local_c;
    uint32_t* local_38;

    if ((uint32_t)param_2 < 4) {
        return 0x80004005;
    }
    uVar17 = *param_1;
    local_38 = param_1;
    if ((uint32_t)param_2 < uVar17) {
        return 0x80004005;
    }
    if (uVar17 == 0xc) {
        local_84 = (int)(int16_t)param_1[1];
        local_80 = (int)*(int16_t*)((int)param_1 + 6);
        local_88 = 0xc;
        local_38 = &local_88;
        puVar13 = &local_88;
    } else {
        puVar13 = param_1;
        if (uVar17 < 0x28) {
            return 0x80004005;
        }
    }
    local_20 = puVar13[1];
    local_30 = puVar13[2];
    if ((int)local_30 < 1) {
        local_30 = -local_30;
    }
    uVar17 = *puVar13;
    uVar3 = *(uint16_t*)((int)puVar13 + 0xe);
    uVar6 = puVar13[8];
    local_c = (uVar17 != 0xc) + 3;
    if ((uVar3 < 9) && (uVar6 == 0)) {
        uVar6 = 1 << ((uint8_t)uVar3 & 0x1f);
    }
    local_24 = (uint8_t*)(local_c * uVar6 + uVar17);
    if ((uint32_t)param_2 < (uint32_t)local_24) {
        return 0x80004005;
    }
    if ((int16_t)puVar13[3] != 1) {
        return 0x80004005;
    }
    if (puVar13[4] < 3) {
        local_2c = (uint32_t)uVar3;
        if (((local_2c == 1) || (local_2c == 4)) || (local_2c == 8)) {
            local_8 = 0x29;
            goto LAB_005f9557;
        }
        if (local_2c == 0x10) goto LAB_005f9469;
        if (local_2c == 0x18) goto LAB_005f93dd;
        if (local_2c != 0x20) {
            return 0x80004005;
        }
    } else {
        if (puVar13[4] != 3) {
            return 0x80004005;
        }
        if (uVar17 < 0x34) {
            return 0x80004005;
        }
        local_14 = puVar13[0xb];
        local_34 = puVar13[0xc];
        local_10 = puVar13[10];
        local_28 = (uVar17 < 0x38) ? 0 : puVar13[0xd];
        local_2c = (uint32_t)*(uint16_t*)((int)puVar13 + 0xe);
        local_8 = 0x74;
        if (local_2c == 0x10) {
            if (local_34 == 0xff) {
                if (((local_14 == 0xff) && (local_10 == 0xff)) && (local_28 == 0xff00)) {
                    local_8 = 0x33;
                }
                goto LAB_005f9557;
            }
            if (local_34 != 0x1f) {
                if (local_34 == 0xf) {
                    if ((local_14 == 0xf0) && (local_10 == 0xf00)) {
                        if (local_28 == 0xf000) {
                            local_8 = 0x1a;
                        } else if (local_28 == 0) {
                            local_8 = 0x1e;
                        }
                    }
                } else if (local_34 == 3) {
                    if (((local_14 == 0x1c) && (local_10 == 0xe0)) && (local_28 == 0xff00)) {
                        local_8 = 0x1d;
                    }
                } else if (((local_34 == 0xffff) && (local_14 == 0xffff)) && ((local_10 == 0xffff && (local_28 == 0)))) {
                    local_8 = 0x51;
                }
                goto LAB_005f9557;
            }
            if (local_14 == 0x7e0) {
                if ((local_10 == 0xf800) && (local_28 == 0)) {
                    local_8 = 0x17;
                }
                goto LAB_005f9557;
            }
            if ((local_14 != 0x3e0) || (local_10 != 0x7c00)) goto LAB_005f9557;
            if (local_28 != 0) {
                if (local_28 == 0x8000) {
                    local_8 = 0x19;
                }
                goto LAB_005f9557;
            }
LAB_005f9469:
            local_8 = 0x18;
            goto LAB_005f9557;
        }
        if (local_2c == 0x18) {
            if ((((local_34 != 0xff) || (local_14 != 0xff00)) || (local_10 != 0xff0000)) || (local_28 != 0)) goto LAB_005f9557;
LAB_005f93dd:
            local_8 = 0x14;
            goto LAB_005f9557;
        }
        if (local_2c != 0x20) {
            return 0x80004005;
        }
        if (local_34 != 0xff) {
            if (local_34 == 0x3ff00000) {
                if (((local_14 == 0xffc00) && (local_10 == 0x3ff)) && (local_28 == 0xc0000000)) {
                    local_8 = 0x1f;
                }
            } else if (local_34 == 0xff0000) {
                if ((local_14 == 0xff00) && (local_10 == 0xff)) {
                    if (local_28 == 0xff000000) {
                        local_8 = 0x20;
                    } else if (local_28 == 0) {
                        local_8 = 0x21;
                    }
                }
            } else if (local_34 == 0) {
                if (((local_14 == 0xffff0000) && (local_10 == 0xffff)) && (local_28 == 0)) {
                    local_8 = 0x22;
                }
            } else if (local_34 == 0x3ff) {
                if (((local_14 == 0xffc00) && (local_10 == 0x3ff00000)) && (local_28 == 0xc0000000)) {
                    local_8 = 0x23;
                }
            } else if (((local_34 == 0xff00) && (local_14 == 0xff0000)) && ((local_10 == 0xff000000 && (local_28 == 0)))) {
                local_8 = 0x16;
                local_24 = (uint8_t*)((int)local_24 + 1);
            }
            goto LAB_005f9557;
        }
        if ((local_14 != 0xff00) || (local_10 != 0xff0000)) goto LAB_005f9557;
        if (local_28 != 0) {
            if (local_28 == 0xff000000) {
                local_8 = 0x15;
            }
            goto LAB_005f9557;
        }
    }
    local_8 = 0x16;
LAB_005f9557:
    local_38 = puVar13;
    if ((in_ECX[0x10] != 0) && (local_8 == 0x29)) {
        uVar17 = puVar13[8];
        if (uVar17 == 0) {
            uVar17 = 1 << ((uint8_t)local_2c & 0x1f);
        }
        in_ECX[0xf] = 1;
        iVar7 = (int)FUN_00533c78(0x400);
        in_ECX[2] = iVar7;
        if (iVar7 == 0) {
            return 0x8007000e;
        }
    }
    return 0;
}

// 0x5f9c20 — observed shape
void FUN_005f9c20(int* param_1) {
    (*(void(**)(int*))(*(int*)param_1 + 8))(param_1);
    longjmp((int*)(*(int*)param_1 + 0x84), 1);
}

// 0x5f9c42 — observed shape
void FUN_005f9c42(int* param_1) {
    uint8_t local_cc[200];
    (*(void(**)(int*, uint8_t*))(*(int*)param_1 + 0xc))(param_1, local_cc);
    return;
}

// 0x5f9c61 — observed shape
uint32_t FUN_005f9c61(int param_1) {
    uint32_t* puVar1;
    puVar1 = *(uint32_t**)(param_1 + 0x18);
    puVar1[0] = puVar1[7];
    puVar1[1] = puVar1[8];
    return 1;
}

// 0x5f9c7e — observed shape
void FUN_005f9c7e(int param_1, int param_2) {
    int* piVar1;
    piVar1 = *(int**)(param_1 + 0x18);
    piVar1[0] = piVar1[0] + param_2;
    piVar1[1] = piVar1[1] - param_2;
    return;
}

// 0x5f9c95 — observed shape
// NEEDS_MANUAL: complex setjmp/image-load path; preserved core shape with observed constants.
uint32_t FUN_005f9c95(int param_1, int param_2) {
    uint32_t uVar5;
    uint32_t local_1e4;
    int local_168;
    int* local_c;
    uint32_t local_174;
    uint32_t local_170;
    uint32_t local_158;
    uint32_t* local_8;
    int iVar3;
    uint8_t local_224[64];
    uint32_t* local_1e0;
    uint32_t* local_1cc;
    uVar5 = 0;
    if ((param_1 == 0) || (param_2 == 0)) {
        return 0x80004005;
    }
    local_1e4 = 0;
    local_1cc = 0;
    local_c = 0;
    local_8 = 0;
    local_1e0 = 0;
    iVar3 = setjmp3(local_224, 0);
    if (iVar3 == 0) {
        local_1e4 = 0;
    } else {
        uVar5 = 0x80004005;
    }
    return uVar5;
}

// 0x5f9f0f — observed shape
// NEEDS_MANUAL: large JPEG/DIB header parser; header validation and format-id selection preserved.
uint32_t FUN_005f9f0f(uint32_t* param_1, uint32_t param_2, void* self) {
    int* in_ECX = (int*)self;
    uint32_t uVar8;
    uint32_t uVar13;
    uint32_t uVar9;
    uint8_t bVar3;
    uint8_t bVar7;
    int local_18;
    int local_10;
    uint32_t uVar10;
    if (param_2 < 0x12) {
        return 0x80004005;
    }
    if ((*(uint8_t*)((int)param_1 + 1) & 0xfe) != 0) {
        return 0x80004005;
    }
    bVar3 = *(uint8_t*)((int)param_1 + 2);
    if ((bVar3 & 0xf4) != 0) {
        return 0x80004005;
    }
    if (*(int16_t*)((int)param_1 + 0xc) == 0) {
        return 0x80004005;
    }
    if (*(int16_t*)((int)param_1 + 0xe) == 0) {
        return 0x80004005;
    }
    uVar8 = (uint32_t)*(uint8_t*)((int)param_1 + 7);
    local_18 = 0;
    if (*(uint8_t*)((int)param_1 + 1) != 0) {
        if (uVar8 == 0xf) {
            local_18 = 0x18;
        } else if (uVar8 == 0x10) {
            local_18 = 0x19;
        } else if (uVar8 == 0x18) {
            local_18 = 0x14;
        } else {
            if (uVar8 != 0x20) {
                return 0x80004005;
            }
            local_18 = 0x15;
        }
    }
    uVar13 = (uint32_t)*(uint8_t*)((int)param_1 + 0x10);
    uVar9 = (uVar13 + 7) >> 3;
    bVar7 = bVar3 & 3;
    if (bVar7 == 1) {
        if (*(uint8_t*)((int)param_1 + 1) == 0) {
            return 0x80004005;
        }
        if (*(uint8_t*)((int)param_1 + 0x10) != 8) {
            return 0x80004005;
        }
        local_10 = 0x29;
    } else if (bVar7 == 2) {
        if (uVar13 == 0xf) {
            local_10 = 0x18;
        } else if (uVar13 == 0x10) {
            local_10 = 0x19;
        } else if (uVar13 == 0x18) {
            local_10 = 0x14;
        } else {
            if (uVar13 != 0x20) {
                return 0x80004005;
            }
            local_10 = 0x15;
        }
    } else {
        if (bVar7 != 3) {
            return 0x80004005;
        }
        if (*(uint8_t*)((int)param_1 + 0x10) != 8) {
            return 0x80004005;
        }
        local_10 = 0x32;
    }
    (void)uVar9;
    (void)local_18;
    (void)local_10;
    (void)uVar10;
    (void)in_ECX;
    return 0;
}

// 0x5fa439 — observed shape
// NEEDS_MANUAL: P3/P6 PPM parser loop elided in reads; header checks preserved.
uint32_t FUN_005fa439(uint32_t* param_1, uint32_t param_2, void* self) {
    bool bVar2;
    uint8_t* pbVar6;
    (void)self;
    if (param_2 < 2) {
        return 0x80004005;
    }
    if (*(char*)param_1 == 'P') {
        if (*(char*)((int)param_1 + 1) == '3') {
            bVar2 = true;
        } else {
            if (*(char*)((int)param_1 + 1) != '6') {
                return 0x80004005;
            }
            bVar2 = false;
        }
        pbVar6 = (uint8_t*)((int)param_1 + 2);
        (void)pbVar6;
        (void)bVar2;
    }
    return 0x80004005;
}

// 0x5fa6c1 — observed shape
void FUN_005fa6c1(int param_1, uint32_t* param_2, uint32_t param_3) {
    int* piVar1;
    uint32_t uVar2;
    uint32_t* puVar3;
    piVar1 = *(int**)(param_1 + 0x54);
    if ((uint32_t)piVar1[1] < param_3) {
        FUN_006565dd(param_1, "read error");
    }
    puVar3 = (uint32_t*)*piVar1;
    for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *param_2 = *puVar3;
        puVar3 = puVar3 + 1;
        param_2 = param_2 + 1;
    }
    for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(uint8_t*)param_2 = *(uint8_t*)puVar3;
        puVar3 = (uint32_t*)((int)puVar3 + 1);
        param_2 = (uint32_t*)((int)param_2 + 1);
    }
    piVar1[0] = piVar1[0] + param_3;
    piVar1[1] = piVar1[1] - param_3;
    return;
}

// 0x5fa704 — observed shape
void FUN_005fa704(int* param_1) {
    longjmp(param_1, 1);
}

// 0x5fa714 — observed shape
// NEEDS_MANUAL: large zlib/PNG inflation driver with setjmp; entry and cleanup shape preserved.
uint32_t FUN_005fa714(uint32_t param_1, uint32_t param_2) {
    int local_8;
    int local_c;
    void* local_20;
    int iVar3;
    uint32_t uVar6;
    uint8_t auStack_158[256];
    (void)auStack_158;
    (void)param_1;
    (void)param_2;
    local_8 = 0;
    local_c = 0;
    local_20 = (void*)0x0;
    iVar3 = FUN_00656662();
    if (iVar3 != 0) {
        return 0x80004005;
    }
    local_8 = FUN_00656940("1.0.5", 0, FUN_005fa704, FUN_006338c7);
    if ((local_8 == 0) || (local_c = FUN_00656784(), local_c == 0)) {
        uVar6 = 0x80004005;
        goto LAB_005fac3b;
    }
    iVar3 = setjmp3(local_8);
    if (iVar3 == 0) {
        uVar6 = 0;
    } else {
        uVar6 = 0x80004005;
    }
LAB_005fac3b:
    if (local_8 != 0) {
        FUN_006570b2();
    }
    if (local_20 != (void*)0x0) {
        operator_delete(local_20);
    }
    return uVar6;
}

// 0x5fac67 — observed shape
// NEEDS_MANUAL: DSD/RIFF chunk table walk elided in reads; header validation and dispatch shape preserved.
uint32_t FUN_005fac67(int* param_1, int* param_2, void* self) {
    int* in_ECX = (int*)self;
    int iVar1;
    int iVar3;
    uint32_t uVar7;
    uint32_t local_1c;
    uint32_t local_24;
    int* local_20;
    if (((param_2 < 4) || (param_1[0] != 0x20534444)) || ((int)(uint32_t)param_2 - 4U < 0x7c)) {
        return 0x80004005;
    }
    in_ECX[3] = param_1[4];
    in_ECX[4] = param_1[3];
    if ((*(uint8_t*)((int)param_1 + 10) & 0x80) == 0) {
        iVar1 = 1;
    } else {
        iVar1 = param_1[6];
    }
    in_ECX[5] = iVar1;
    if (iVar1 == 0) {
        in_ECX[5] = 1;
    }
    if ((param_1[0x1c] & 0xfc00U) == 0xfc00) {
        local_1c = 6;
    }
    local_24 = param_1[7];
    if (local_24 == 0) {
        local_24 = 1;
    }
    uVar7 = param_1[0x14];
    if ((uVar7 & 4) != 0) {
        uVar7 = 4;
    }
    local_20 = (int*)(uVar7 & 0xc4040);
    (void)local_20;
    iVar3 = 0;
    (void)iVar3;
    (void)local_1c;
    (void)local_24;
    return 0;
}
