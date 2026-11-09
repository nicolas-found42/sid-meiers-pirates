#include <cstdint>
#include <cstddef>
#include <cctype>
#include <windows.h>

extern void FUN_004f3ee0();
extern void FUN_004f2600(void *param_1, int param_2);
extern void FUN_004f30d0(int param_1);
extern void operator_delete__(void *param_1);
extern void *thunk_FUN_00533c78(std::size_t count);
extern int FUN_004f3ee0_eax;
extern int DAT_00710530;
extern int DAT_008cacc8;

// 0x4f3130 — observed shape
void FUN_004f3130(void *self, int in_EAX, int in_ECX, int in_EDX) {
    int local_4 = 0;
    (void)self;
    if (((-1 < in_EAX) && (-1 < in_ECX)) && (in_EDX != 0)) {
        FUN_004f3ee0();
        FUN_004f2600(&DAT_00710530, local_4);
        FUN_004f30d0(0);
        void *puVar1 = (void *)((intptr_t)&local_4 - 8);
        if ((puVar1 != nullptr) && (puVar1 != &DAT_008cacc8)) {
            operator_delete__(puVar1);
        }
    }
}

// 0x4f31c0 — observed shape
int FUN_004f31c0(uint32_t *param_1, int param_2) {
    uint8_t *pbVar2;
    uint8_t *pbVar5;
    int iVar4 = 0;
    int iVar6 = 1;
    bool bVar7;
    if ((param_2 < 2) || (0x24 < param_2)) {
        return 0;
    }
    pbVar2 = (uint8_t *)(uintptr_t)*param_1;
    pbVar5 = pbVar2 + *(int *)(pbVar2 - 4) - 1;
    bVar7 = pbVar5 == pbVar2;
    if (pbVar2 <= pbVar5) {
        do {
            if (bVar7) {
                if (*pbVar5 == 0x2d) {
                    iVar4 = -iVar4;
                } else if (*pbVar5 != 0x2b) {
                    goto LAB_004f31ff;
                }
            } else {
            LAB_004f31ff:;
                uint8_t bVar1 = *pbVar5;
                int iVar3;
                if (((char)bVar1 < -0x80) || (0xff < (char)bVar1)) {
                LAB_004f322b:
                    bVar1 = *pbVar5;
                    if (((char)bVar1 < -0x80) || (0xff < (char)bVar1)) {
                        iVar3 = 0;
                    } else {
                        iVar3 = toupper((unsigned int)bVar1);
                    }
                    iVar3 = iVar3 - 0x37;
                } else {
                    iVar3 = isdigit((unsigned int)bVar1);
                    if (iVar3 == 0) goto LAB_004f322b;
                    iVar3 = (char)*pbVar5 - 0x30;
                }
                iVar4 = iVar4 + iVar3 * iVar6;
            }
            iVar6 = iVar6 * param_2;
            pbVar5 = pbVar5 - 1;
            bVar7 = pbVar5 == (uint8_t *)(uintptr_t)*param_1;
        } while ((uint8_t *)(uintptr_t)*param_1 <= pbVar5);
    }
    return iVar4;
}

// 0x4f3270 — observed shape
void FUN_004f3270(void *self, int *in_EDX) {
    int iVar1 = *in_EDX;
    int iVar2 = 0;
    (void)self;
    if (0 < *(int *)(iVar1 - 4)) {
        do {
            if (*(char *)(iVar1 + iVar2) == (char)0xff) {
                *(uint8_t *)(iVar1 + iVar2) = 1;
            } else {
                *(char *)(iVar1 + iVar2) = *(char *)(iVar1 + iVar2) + 1;
            }
            iVar1 = *in_EDX;
            iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar1 - 4));
    }
}

// 0x4f32b0 — observed shape
void FUN_004f32b0(void *self, int *in_EDX) {
    int iVar1 = *in_EDX;
    (void)self;
    if (0 < *(int *)(iVar1 - 4)) {
        int iVar2 = 0;
        do {
            if (*(char *)(iVar1 + iVar2) == (char)0x01) {
                *(uint8_t *)(iVar1 + iVar2) = 0xff;
            } else {
                *(char *)(iVar1 + iVar2) = *(char *)(iVar1 + iVar2) - 1;
            }
            iVar1 = *in_EDX;
            iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar1 - 4));
    }
}

// 0x4f32e0 — observed shape
void FUN_004f32e0(void *self, int in_EAX, int *in_ECX) {
    (void)self;
    if (0 < in_EAX) {
        uint32_t *puVar1 = (uint32_t *)(uintptr_t)*in_ECX;
        if (in_EAX != (int)puVar1[-2]) {
            int *piVar2 = (int *)thunk_FUN_00533c78(in_EAX + 9);
            *in_ECX = (int)(intptr_t)(piVar2 + 2);
            *piVar2 = in_EAX;
            *(uint32_t *)(*in_ECX - 4) = puVar1[-1];
            if ((int)puVar1[-1] < 1) {
                *(uint8_t *)(uintptr_t)*in_ECX = 0;
            } else {
                uint32_t uVar4 = puVar1[-1] + 1;
                uint32_t *puVar5 = puVar1;
                uint32_t *puVar6 = (uint32_t *)(uintptr_t)*in_ECX;
                for (uint32_t uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                    *puVar6 = *puVar5;
                    puVar5 = puVar5 + 1;
                    puVar6 = puVar6 + 1;
                }
                for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *(uint8_t *)puVar6 = *(uint8_t *)puVar5;
                    puVar5 = (uint32_t *)((intptr_t)puVar5 + 1);
                    puVar6 = (uint32_t *)((intptr_t)puVar6 + 1);
                }
            }
            if (puVar1 - 2 != (uint32_t *)&DAT_008cacc8) {
                operator_delete__(puVar1 - 2);
            }
        }
    }
}

extern void FUN_004f32e0(void *self, int in_EAX, int *in_ECX);
extern void FUN_004f3b00(uint32_t unaff_EDI);
extern void FUN_004f3b90(int in_ECX);
extern void FUN_004f3e30();

// 0x4f3350 — observed shape
void FUN_004f3350(void *self, int unaff_ESI, int *unaff_EDI) {
    (void)self;
    if (unaff_ESI == 0) {
        if (*(int *)((uint8_t *)(uintptr_t)*unaff_EDI - 4) != 0) {
            *(uint8_t *)(uintptr_t)*unaff_EDI = 0;
            *(uint32_t *)( (uintptr_t)*unaff_EDI - 4) = 0;
            return;
        }
    } else if (0 < unaff_ESI) {
        if (*(int *)((uintptr_t)*unaff_EDI - 8) < unaff_ESI) {
            FUN_004f32e0(self, unaff_ESI, unaff_EDI);
        }
        *(int *)((uintptr_t)*unaff_EDI - 4) = unaff_ESI;
    }
}

// 0x4f3390 — observed shape
void FUN_004f3390(void *self, char *in_EDX, uint32_t unaff_EDI) {
    (void)self;
    if (in_EDX == nullptr) {
        FUN_004f3b00(unaff_EDI);
        return;
    }
    char cVar1;
    do {
        cVar1 = *in_EDX;
        in_EDX = in_EDX + 1;
    } while (cVar1 != '\0');
    FUN_004f3b00(unaff_EDI);
}

// 0x4f33d0 — observed shape
void FUN_004f33d0(void *self, int in_EAX, int in_ECX, int *unaff_EDI) {
    (void)self;
    if (in_ECX < 0) {
        in_ECX = 0;
    }
    if (in_EAX < 0) {
        in_EAX = 0;
    }
    int iVar1 = *(int *)((uintptr_t)*unaff_EDI - 4);
    if (iVar1 < in_ECX + in_EAX) {
        in_EAX = iVar1 - in_ECX;
    }
    if (iVar1 < in_ECX) {
        in_EAX = 0;
    }
    if ((in_ECX == 0) && (in_EAX == iVar1)) {
        FUN_004f3e30();
        return;
    }
    FUN_004f3b90(in_ECX);
    FUN_004f3e30();
}

// 0x4f3450 — observed shape
void FUN_004f3450(void *self, wchar_t *param_1, int *in_EAX) {
    (void)self;
    if (((*(int *)((uintptr_t)*in_EAX - 4) != 0) && (param_1 != nullptr)) &&
        (swcslen(param_1), 0 < (int)swcslen(param_1))) {
        wchar_t *pwVar3 = (wchar_t *)(uintptr_t)*in_EAX;
        wchar_t *pwVar1 = pwVar3 + *(int *)((intptr_t)pwVar3 - 4) - 1;
        wchar_t *pwVar5 = nullptr;
        if (pwVar3 <= pwVar3 + *(int *)((intptr_t)pwVar3 - 4) - 1) {
            do {
                wchar_t *pwVar4 = pwVar1;
                pwVar3 = wcschr(param_1, *pwVar4);
                if (pwVar3 == nullptr) break;
                pwVar1 = pwVar4 - 1;
                pwVar5 = pwVar4;
            } while ((wchar_t *)(uintptr_t)*in_EAX <= pwVar4 - 1);
            if (pwVar5 != nullptr) {
                *pwVar5 = L'\0';
                *(int *)((uintptr_t)*in_EAX - 4) = (int)(((intptr_t)pwVar5 - (intptr_t)*in_EAX) >> 1);
            }
        }
    }
}

// 0x4f34c0 — observed shape
void FUN_004f34c0(void *self, int *unaff_EBX, wchar_t *unaff_EDI) {
    (void)self;
    if (((*(int *)((uintptr_t)*unaff_EBX - 4) != 0) && (unaff_EDI != nullptr)) &&
        (swcslen(unaff_EDI), 0 < (int)swcslen(unaff_EDI))) {
        wchar_t *_Src = (wchar_t *)(uintptr_t)*unaff_EBX;
        wchar_t _Ch = *_Src;
        while ((_Ch != L'\0' && (wcschr(unaff_EDI, _Ch) != nullptr))) {
            _Ch = _Src[1];
            _Src = _Src + 1;
        }
        wchar_t *pwVar2 = (wchar_t *)(uintptr_t)*unaff_EBX;
        if (_Src != pwVar2) {
            *(int *)((intptr_t)pwVar2 - 4) = *(int *)((intptr_t)pwVar2 - 4) - (int)(((intptr_t)_Src - (intptr_t)pwVar2) >> 1);
            memmove((void *)(uintptr_t)*unaff_EBX, _Src, *(int *)((uintptr_t)*unaff_EBX - 4) * 2 + 2);
        }
    }
}

extern void FUN_004f3d90();
extern void FUN_004f3bf0(void *self);
extern void FUN_004f3c60(void *self);
extern void FUN_004f3ca0(int param_1);
extern void FUN_004f3540(void *param_1, int param_2);
extern void FUN_004f3e10();
extern int DAT_0071055c;

// 0x4f3560 — observed shape (non-contiguous varargs scan; structural sketch)
// NEEDS_MANUAL: varargs format scanner with register-passed va_list; body elided regions summarized, not verbatim
void FUN_004f3560(int *param_1, wchar_t *param_2, wchar_t *param_3);

void FUN_004f3560(int *param_1, wchar_t *param_2, wchar_t *param_3) {
    wchar_t *_Format = param_3;
    bool bVar4 = false;
    int local_c = 0;
    wchar_t *local_10 = nullptr;
    wchar_t *pwVar11 = param_2;
    size_t sVar12 = 0;
    va_list unaff_EDI = nullptr;
    (void)unaff_EDI;
    if (*param_2 != L'\0') {
        do {
            if (*pwVar11 != L'%') {
                local_c = local_c + 1;
                goto LAB_004f38d4;
            }
            {
                wchar_t wVar5 = pwVar11[1];
                pwVar11 = pwVar11 + 1;
                if (wVar5 == L'%') {
                    local_c = local_c + 1;
                    goto LAB_004f38d4;
                }
                local_10 = nullptr;
                if (wVar5 == L'\0') {
                LAB_004f3609:
                    local_10 = (wchar_t *)(intptr_t)_wtoi(pwVar11);
                    wVar5 = *pwVar11;
                    while (wVar5 != L'\0') {
                        int iVar6 = iswdigit(wVar5);
                        if (iVar6 == 0) break;
                        wVar5 = pwVar11[1];
                        pwVar11 = pwVar11 + 1;
                    }
                } else {
                    do {
                        if (wVar5 == L'#') {
                            local_c = local_c + 2;
                        } else if (wVar5 == L'*') {
                            local_10 = *(wchar_t **)param_3;
                            param_3 = param_3 + 2;
                        } else if ((((wVar5 != L'-') && (wVar5 != L'+')) && (wVar5 != L'0')) && (wVar5 != L' '))
                            break;
                        wVar5 = pwVar11[1];
                        pwVar11 = pwVar11 + 1;
                    } while (wVar5 != L'\0');
                    if (local_10 == nullptr) goto LAB_004f3609;
                }
            }
            sVar12 = 0;
            if (*pwVar11 == L'.') {
                wchar_t *pwVar10 = pwVar11 + 1;
                if (*pwVar10 == L'*') {
                    sVar12 = *(size_t *)param_3;
                    param_3 = param_3 + 2;
                    pwVar11 = pwVar11 + 2;
                } else {
                    sVar12 = _wtoi(pwVar10);
                    wchar_t wVar5 = *pwVar10;
                    pwVar11 = pwVar10;
                    while ((wVar5 != L'\0' && iswdigit(wVar5) != 0)) {
                        wVar5 = pwVar11[1];
                        pwVar11 = pwVar11 + 1;
                    }
                }
            }
            {
                wchar_t *pwVar10 = param_3;
                uint32_t uVar14 = 0;
                size_t sVar7 = 0;
                int iVar6 = wcsncmp(pwVar11, L"I64", 3);
                if (iVar6 == 0) {
                    pwVar11 = pwVar11 + 3;
                    uVar14 = 0x40000;
                } else {
                    switch (*pwVar11) {
                    case L'F': case L'L': case L'N': break;
                    default: goto switchD_004f36c9_caseD_47;
                    case L'h': uVar14 = 0x10000; break;
                    case L'l': uVar14 = 0x20000;
                    }
                    pwVar11 = pwVar11 + 1;
                }
            switchD_004f36c9_caseD_47:;
                uint32_t uVar9 = (uint16_t)*pwVar11 | uVar14;
                (void)uVar9;
                param_3 = pwVar10 + 2;
                /* branches LAB_004f37cf/004f374f/004f3738 compute sVar7 from arg strings
                   and converge to LAB_004f379f / LAB_004f370e; condensed here. */
                bool bVar15 = false;
                if (uVar9 == 0x10063 || uVar9 == 0x43) {
                    sVar7 = 1; bVar4 = true;
                } else if (uVar9 == 0x20053 || uVar9 == 0x73) {
                    if (*(wchar_t **)param_3 == nullptr) sVar7 = 6;
                    else { sVar7 = swcslen(*(wchar_t **)param_3); if ((int)sVar7 > 0) { param_3 = param_3 + 2; if (sVar7 != 0) goto apply; } sVar7 = 1; }
                } else if (uVar9 == 0x10073) {
                    char *pcVar8 = *(char **)param_3;
                    if (pcVar8 == nullptr) sVar7 = 6;
                    else { char *pcVar1 = pcVar8 + 1; char cVar2; do { cVar2 = *pcVar8; pcVar8 = pcVar8 + 1; } while (cVar2 != '\0'); sVar7 = (size_t)((intptr_t)pcVar8 - (intptr_t)pcVar1); if ((int)sVar7 < 1) sVar7 = 1; }
                    bVar4 = true; param_3 = pwVar10 + 2;
                } else if (uVar9 == 0x20063 || uVar9 == 0x20073 || uVar9 == 0x20043 || uVar9 == 0x53 || uVar9 == 0x63 || uVar9 == 0x10053 || bVar15) {
                    sVar7 = 1;
                } else {
                    goto LAB_004f370e;
                }
            apply:
                if ((sVar12 != 0) && ((int)sVar12 <= (int)sVar7)) sVar7 = sVar12;
                if ((int)(intptr_t)local_10 < (int)sVar7) { local_c = local_c + (int)sVar7; goto LAB_004f38d4; }
                local_c = local_c + (int)(intptr_t)local_10;
                goto LAB_004f38d4;
            LAB_004f370e:
                switch (*pwVar11) {
                case L'E': case L'G': case L'e': case L'g':
                    param_3 = param_3 + 4; sVar7 = sVar12 + (int)(intptr_t)local_10;
                    if (0x7f < (int)sVar7) { local_c = local_c + (int)sVar7; break; }
                    local_c = local_c + 0x80; break;
                case L'X': case L'd': case L'i': case L'o': case L'u': case L'x':
                    if ((uVar14 & 0x40000) == 0) param_3 = param_3 + 2; else param_3 = param_3 + 4;
                    goto LAB_004f38af;
                case L'f':
                    param_3 = param_3 + 4; break;
                case L'n': param_3 = param_3 + 2;
                    default: local_c = local_c + (int)sVar7; break;
                case L'p':
                    param_3 = param_3 + 2;
                LAB_004f38af:
                    sVar7 = (int)(intptr_t)local_10 + sVar12;
                    if (0x1f < (int)sVar7) { local_c = local_c + (int)sVar7; break; }
                    local_c = local_c + 0x20;
                }
            }
        LAB_004f38d4:
            pwVar11 = pwVar11 + 1;
        } while (*pwVar11 != L'\0');
        if (bVar4) {
            FUN_004f3d90();
            uint16_t *puVar3 = (uint16_t *)(uintptr_t)*param_1;
            if (*(int *)((intptr_t)puVar3 - 8) < local_c) {
                int iVar6 = *(int *)((intptr_t)puVar3 - 4);
                if (local_c == 0) {
                    if (iVar6 != 0) { *puVar3 = 0; *(uint32_t *)((uintptr_t)*param_1 - 4) = 0; }
                } else if (0 < local_c) {
                    FUN_004f3bf0(param_1);
                    *(int *)((uintptr_t)*param_1 - 4) = local_c;
                }
                *(int *)((uintptr_t)*param_1 - 4) = iVar6;
            }
            vswprintf((wchar_t *)(uintptr_t)*param_1, swcslen(param_2), _Format, unaff_EDI);
            setlocale(0, (char *)local_10);
            if (local_10 != nullptr) operator_delete__(local_10);
            goto LAB_004f39d3;
        }
    }
    {
        uint16_t *puVar3 = (uint16_t *)(uintptr_t)*param_1;
        if (*(int *)((intptr_t)puVar3 - 8) < local_c) {
            int iVar6 = *(int *)((intptr_t)puVar3 - 4);
            if (local_c == 0) {
                if (iVar6 != 0) { *puVar3 = 0; *(uint32_t *)((uintptr_t)*param_1 - 4) = 0; }
            } else if (0 < local_c) {
                FUN_004f3bf0(param_1);
                *(int *)((uintptr_t)*param_1 - 4) = local_c;
            }
            *(int *)((uintptr_t)*param_1 - 4) = iVar6;
        }
        vswprintf((wchar_t *)(uintptr_t)*param_1, swcslen(param_2), _Format, unaff_EDI);
    LAB_004f39d3:
        wchar_t *pwVar11b = (wchar_t *)(uintptr_t)*param_1;
        sVar12 = swcslen(pwVar11b);
        *(size_t *)((intptr_t)pwVar11b - 4) = sVar12;
    }
}

// 0x4f3a80 — observed shape
int FUN_004f3a80(void *self, int unaff_ESI, int *unaff_EDI) {
    (void)self;
    uint16_t *puVar1 = (uint16_t *)(uintptr_t)*unaff_EDI;
    if (*(int *)((intptr_t)puVar1 - 8) < unaff_ESI) {
        int iVar2 = *(int *)((intptr_t)puVar1 - 4);
        if (unaff_ESI == 0) {
            if (iVar2 != 0) {
                *puVar1 = 0;
                *(uint32_t *)((uintptr_t)*unaff_EDI - 4) = 0;
                *(int *)((uintptr_t)*unaff_EDI - 4) = iVar2;
                return *unaff_EDI;
            }
        } else if (0 < unaff_ESI) {
            FUN_004f3bf0(self);
            *(int *)((uintptr_t)*unaff_EDI - 4) = unaff_ESI;
        }
        *(int *)((uintptr_t)*unaff_EDI - 4) = iVar2;
    }
    return *unaff_EDI;
}

// 0x4f3ad0 — observed shape
void FUN_004f3ad0(void *self, int in_EAX, int *in_ECX) {
    (void)self;
    if (in_EAX == -1) {
        wchar_t *_Str = (wchar_t *)(uintptr_t)*in_ECX;
        size_t sVar1 = swcslen(_Str);
        *(size_t *)((intptr_t)_Str - 4) = sVar1;
        return;
    }
    *(int *)((uintptr_t)*in_ECX - 4) = in_EAX;
    if (0 < in_EAX) {
        *(uint16_t *)((uintptr_t)*in_ECX + (size_t)in_EAX * 2) = 0;
    }
}

// 0x4f3b00 — observed shape
void FUN_004f3b00(void *self, int in_EAX, int in_ECX, int in_EDX) {
    int local_4 = 0;
    (void)self;
    if (((-1 < in_EAX) && (-1 < in_ECX)) && (in_EDX != 0)) {
        FUN_004f3ca0(in_EDX + in_ECX);
        FUN_004f3540(&DAT_0071055c, local_4);
        FUN_004f3b90(0);
        void *puVar1 = (void *)((intptr_t)&local_4 - 8);
        if ((puVar1 != nullptr) && (puVar1 != &DAT_008cacc8)) {
            operator_delete__(puVar1);
        }
    }
}

// 0x4f3b90 — observed shape
void FUN_004f3b90(void *self, int param_1, int in_EAX, int *in_ECX, int unaff_EBX) {
    (void)self;
    if ((((-1 < in_EAX) && (-1 < param_1)) && (unaff_EBX != 0)) && (unaff_EBX != *in_ECX)) {
        if (in_EAX != 0) {
            FUN_004f3c60(self);
            memmove((void *)(uintptr_t)*in_ECX, (void *)((intptr_t)unaff_EBX + (intptr_t)param_1 * 2), (size_t)in_EAX * 2);
            *(uint16_t *)((uintptr_t)*in_ECX + (size_t)*(int *)((uintptr_t)*in_ECX - 4) * 2) = 0;
            return;
        }
        FUN_004f3e10();
    }
}

extern void FUN_004f3350(void *self, int unaff_ESI, int *unaff_EDI);
extern void FUN_004f412f90();
extern int DAT_008cacd0;
extern int DAT_008caccc;
extern int DAT_008cacc8;

// 0x4f3bf0 — observed shape
void FUN_004f3bf0(void *self, int in_EAX, int *in_ECX) {
    (void)self;
    if (0 < in_EAX) {
        uint32_t *puVar5 = (uint32_t *)(uintptr_t)*in_ECX;
        int *piVar1 = (int *)(puVar5 - 2);
        if (in_EAX != *piVar1) {
            int *piVar2 = (int *)thunk_FUN_00533c78((size_t)in_EAX * 2 + 10);
            *in_ECX = (int)(intptr_t)(piVar2 + 2);
            *piVar2 = in_EAX;
            *(uint32_t *)((uintptr_t)*in_ECX - 4) = puVar5[-1];
            if ((int)puVar5[-1] < 1) {
                *(uint16_t *)(uintptr_t)*in_ECX = 0;
            } else {
                uint32_t uVar4 = puVar5[-1] * 2 + 2;
                uint32_t *puVar6 = (uint32_t *)(uintptr_t)*in_ECX;
                for (uint32_t uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                    *puVar6 = *puVar5;
                    puVar5 = puVar5 + 1;
                    puVar6 = puVar6 + 1;
                }
                for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *(uint8_t *)puVar6 = *(uint8_t *)puVar5;
                    puVar5 = (uint32_t *)((intptr_t)puVar5 + 1);
                    puVar6 = (uint32_t *)((intptr_t)puVar6 + 1);
                }
            }
            if (piVar1 != &DAT_008cacc8) {
                operator_delete__(piVar1);
            }
        }
    }
}

// 0x4f3c60 — observed shape
void FUN_004f3c60(void *self, int unaff_ESI, int *unaff_EDI) {
    (void)self;
    if (unaff_ESI == 0) {
        if (*(int *)((intptr_t)*(uint16_t **)(void *)unaff_EDI - 4) != 0) {
            *(uint16_t *)(uintptr_t)*unaff_EDI = 0;
            *(uint32_t *)((uintptr_t)*unaff_EDI - 4) = 0;
            return;
        }
    } else if (0 < unaff_ESI) {
        if (*(int *)((uintptr_t)*unaff_EDI - 8) < unaff_ESI) {
            FUN_004f3bf0(self, unaff_ESI, unaff_EDI);
        }
        *(int *)((uintptr_t)*unaff_EDI - 4) = unaff_ESI;
    }
}

// 0x4f3ca0 — observed shape
void FUN_004f3ca0(void *self, void *param_1, size_t in_EAX, int *in_ECX) {
    (void)self;
    *in_ECX = (int)(intptr_t)&DAT_008cacd0;
    if (in_EAX == 0) {
        if (DAT_008caccc != 0) {
            DAT_008cacd0 = 0;
            *(uint32_t *)((uintptr_t)*in_ECX - 4) = 0;
        }
    } else {
        if (0 < (int)in_EAX) {
            if (DAT_008cacc8 < (int)in_EAX) {
                FUN_004f32e0(self, (int)in_EAX, in_ECX);
            }
            *(size_t *)((uintptr_t)*in_ECX - 4) = in_EAX;
        }
        if ((int)in_EAX < 0) {
            return;
        }
    }
    if ((param_1 != nullptr) && (param_1 != (void *)(uintptr_t)*in_ECX)) {
        if (in_EAX != 0) {
            FUN_004f3350(self, (int)in_EAX, in_ECX);
            memmove((void *)(uintptr_t)*in_ECX, param_1, in_EAX);
            *(uint8_t *)((uintptr_t)*in_ECX + *(int *)((uintptr_t)*in_ECX - 4)) = 0;
            return;
        }
        FUN_004f412f90();
    }
}

// 0x4f3d30 — observed shape
void FUN_004f3d30(void *self, int16_t param_1, int *in_EAX) {
    (void)self;
    int iVar1 = *(int *)((uintptr_t)*in_EAX - 4);
    uint32_t uVar2 = (uint32_t)(param_1 != 0);
    if ((uVar2 != 0) && (-1 < iVar1)) {
        if (iVar1 < (int)(iVar1 + uVar2)) {
            FUN_004f3c60(self, (int)(iVar1 + uVar2), in_EAX);
            *(uint16_t *)((uintptr_t)*in_EAX + (size_t)*(int *)((uintptr_t)*in_EAX - 4) * 2) = 0;
        }
        memmove((void *)((uintptr_t)*in_EAX + (size_t)iVar1 * 2), &param_1, (size_t)uVar2 * 2);
    }
}

// 0x4f3d90 — observed shape
void FUN_004f3d90(void *self, char *param_1, int unaff_EBX, int *unaff_EDI) {
    (void)self;
    char *pcVar2 = setlocale(unaff_EBX, nullptr);
    if ((pcVar2 == nullptr) || (*pcVar2 == '\0')) {
        unaff_EDI[1] = 0;
    } else {
        char *pcVar3 = pcVar2;
        char cVar1;
        do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        pcVar3 = (char *)thunk_FUN_00533c78((size_t)((intptr_t)(pcVar3 + 1) - (intptr_t)(pcVar2 + 1)));
        unaff_EDI[1] = (int)(intptr_t)pcVar3;
        if (pcVar3 != nullptr) {
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
                *pcVar3 = cVar1;
                pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            *unaff_EDI = unaff_EBX;
            setlocale(unaff_EBX, param_1);
            return;
        }
    }
    *unaff_EDI = unaff_EBX;
    setlocale(unaff_EBX, param_1);
}
