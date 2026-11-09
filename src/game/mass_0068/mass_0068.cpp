// Reconstruction batch mass_0068
// Sid Meier's Pirates! (2004), PE32 i386
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cctype>
#include <windows.h>

extern int isspace(int);

// 0x4f1b70 — observed shape
void FUN_004f1b70(void** self, char in_DL)
{
    // Receiver convention: EDI carries int* pointing at the string pointer slot (length at -4).
    // Trims trailing in_DL characters, then NUL-terminates and updates prefix length.
    char* pcVar1 = (char*)*self;
    if (*(int*)(pcVar1 + -4) != 0) {
        char* pcVar2 = pcVar1 + *(int*)(pcVar1 + -4) + -1;
        char* pcVar4 = (char*)0x0;
        if (pcVar1 <= pcVar1 + *(int*)(pcVar1 + -4) + -1) {
            do {
                char* pcVar3 = pcVar2;
                if (*pcVar3 != in_DL) break;
                pcVar2 = pcVar3 + -1;
                pcVar4 = pcVar3;
            } while (pcVar1 <= pcVar3 + -1);
            if (pcVar4 != (char*)0x0) {
                *pcVar4 = '\0';
                *(int*)(*self + -4) = (int)pcVar4 - (int)*self;
            }
        }
    }
}

// 0x4f1ba0 — observed shape
void FUN_004f1ba0(int** param_1, char* param_2, char* unaff_EBX = nullptr)
{
    char* pcVar3 = (char*)*param_1;
    if ((*(int*)(pcVar3 + -4) != 0) && (param_2 != (char*)0x0)) {
        char* pcVar2 = param_2;
        char cVar1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        if ((0 < (int)pcVar2 - (int)(param_2 + 1)) && (pcVar3 <= pcVar3 + *(int*)(pcVar3 + -4) + -1)) {
            pcVar3 = pcVar3 + *(int*)(pcVar3 + -4) + -1;
            pcVar2 = (char*)0x0;
            do {
                char* pcVar4 = pcVar3;
                pcVar3 = strchr(param_2, (int)*pcVar4);
                if (pcVar3 == (char*)0x0) break;
                pcVar3 = pcVar4 + -1;
                pcVar2 = pcVar4;
            } while ((char*)*param_1 <= pcVar4 + -1);
            if (pcVar2 != (char*)0x0) {
                *pcVar2 = '\0';
                *(int*)(*param_1 + -4) = (int)pcVar2 - (int)*param_1;
            }
        }
    }
}

// 0x4f1c20 — observed shape
void FUN_004f1c20(void** self)
{
    // Receiver via EBX: left-trim isspace bytes, memmove the remainder, adjust prefix length.
    unsigned char* _Src = (unsigned char*)*self;
    if (*(int*)(_Src + -4) != 0) {
        while (true) {
            unsigned char bVar1 = *_Src;
            if ((((char)bVar1 < -0x80) || (0xff < (char)bVar1)) ||
                (isspace((uint)bVar1) == 0)) break;
            _Src = _Src + 1;
        }
        unsigned char* pbVar2 = (unsigned char*)*self;
        if (_Src != pbVar2) {
            *(unsigned char**)(pbVar2 + -4) = pbVar2 + (*(int*)(pbVar2 + -4) - (int)_Src);
            memmove((void*)*self, _Src, *(int*)((int)*self + -4) + 1);
        }
    }
}

// 0x4f1c80 — observed shape
void FUN_004f1c80(void** self, char in_DL)
{
    // Receiver via ESI: strips leading in_DL bytes, memmoves remainder, adjusts prefix length.
    char* pcVar3 = (char*)*self;
    if (*(int*)(pcVar3 + -4) != 0) {
        char cVar2 = *pcVar3;
        char* _Src = pcVar3;
        while (in_DL == cVar2) {
            char* pcVar1 = _Src + 1;
            _Src = _Src + 1;
            cVar2 = *pcVar1;
        }
        if (_Src != pcVar3) {
            *(char**)(pcVar3 + -4) = pcVar3 + (*(int*)(pcVar3 + -4) - (int)_Src);
            memmove((void*)*self, _Src, *(int*)((int)*self + -4) + 1);
        }
    }
}

// 0x4f1cc0 — observed shape
void FUN_004f1cc0(void** param_1, char* unaff_EBX)
{
    // Strips leading characters contained in unaff_EBX set; adjusts prefix length and memmoves.
    char* _Src = (char*)*param_1;
    if ((*(int*)(_Src + -4) != 0) && (unaff_EBX != (char*)0x0)) {
        char* pcVar2 = unaff_EBX;
        char cVar1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        if (0 < (int)pcVar2 - (int)(unaff_EBX + 1)) {
            cVar1 = *_Src;
            while ((cVar1 != '\0' && (pcVar2 = strchr(unaff_EBX, (int)cVar1), pcVar2 != (char*)0x0))) {
                cVar1 = _Src[1];
                _Src = _Src + 1;
            }
            pcVar2 = (char*)*param_1;
            if (_Src != pcVar2) {
                *(char**)(pcVar2 + -4) = pcVar2 + (*(int*)(pcVar2 + -4) - (int)_Src);
                memmove((void*)*param_1, _Src, *(int*)((int)*param_1 + -4) + 1);
            }
        }
    }
}
// 0x4f1d50 — observed shape
uint32_t FUN_004f1d50(int in_ECX, int in_EAX, void** self)
{
    if (in_ECX < 0) in_ECX = 0;
    auto* puVar1 = (uint8_t*)*self;
    int iVar2 = *(int*)(puVar1 + -4);
    int iVar3 = iVar2 - in_ECX;
    if (iVar3 < in_EAX) in_EAX = iVar3;
    if ((in_ECX == 0) && (in_EAX == iVar2)) {
        if (iVar2 != 0) {
            *puVar1 = 0;
            *(uint32_t*)(*self + -4) = 0;
            return *(uint32_t*)(*self + -4);
        }
    } else if ((0 < in_EAX) && (in_ECX < iVar2)) {
        memmove(puVar1 + in_ECX, puVar1 + in_ECX + in_EAX, (iVar3 - in_EAX) + 1);
        *(int*)(*self + -4) = *(int*)(*self + -4) - in_EAX;
    }
    return *(uint32_t*)(*self + -4);
}

// 0x4f1dc0 — observed shape
extern uint32_t FUN_004f1d50(int, int, void**);
uint32_t FUN_004f1dc0(char* param_1, void** self)
{
    if ((param_1 != (char*)0x0) && (*param_1 != '\0') && (0 < *(int*)((char*)*self + -4))) {
        char* pcVar2 = strstr((char*)*self, param_1);
        if (pcVar2 != (char*)0x0) {
            int iVar3 = (int)pcVar2 - (int)self;
            while (iVar3 != -1) {
                char* pcVar2b = param_1;
                char cVar1;
                do { cVar1 = *pcVar2b; pcVar2b = pcVar2b + 1; } while (cVar1 != '\0');
                int len = (int)pcVar2b - (int)(param_1 + 1);
                FUN_004f1d50(iVar3, len, self);
                if ((*(int*)((char*)*self + -4) < 1) ||
                    (pcVar2 = strstr((char*)*self, param_1), pcVar2 == (char*)0x0)) break;
                iVar3 = (int)pcVar2 - (int)self;
            }
        }
    }
    return *(uint32_t*)(*self + -4);
}

// 0x4f1e40 — observed shape
extern void FUN_004f32e0(void*, int);
uint32_t FUN_004f1e40(uint8_t param_1, int in_EAX, void** self)
{
    if (in_EAX < 0) in_EAX = 0;
    else if (*(int*)(*self + -4) < in_EAX) in_EAX = *(int*)(*self + -4);
    auto* puVar2 = (uint8_t*)*self;
    int iVar1 = *(int*)(puVar2 + -4) + 1;
    if (iVar1 == 0) {
        if (*(int*)(puVar2 + -4) != 0) { *puVar2 = 0; *(uint32_t*)(*self + -4) = 0; }
    } else if (0 < iVar1) {
        if (*(int*)(puVar2 + -8) < iVar1) FUN_004f32e0(*self, iVar1);
        *(int*)(*self + -4) = iVar1;
    }
    void* _Src = (void*)(*self + in_EAX);
    memmove((void*)((int)_Src + 1), _Src, *(int*)(*self + -4) - in_EAX);
    *(uint8_t*)(in_EAX + (int)self) = param_1;
    return *(uint32_t*)(*self + -4);
}

// 0x4f1ec0 — observed shape
extern void FUN_004f32e0(void*, int);
uint32_t FUN_004f1ec0(int param_1, char* param_2, void** self)
{
    if (param_1 < 0) param_1 = 0;
    else if (*(int*)(*self + -4) < param_1) param_1 = *(int*)(*self + -4);
    if (param_2 == (char*)0x0) return *(uint32_t*)(*self + -4);
    char* pcVar4 = param_2;
    char cVar2;
    do { cVar2 = *pcVar4; pcVar4 = pcVar4 + 1; } while (cVar2 != '\0');
    size_t _Size = (size_t)((int)pcVar4 - (int)(param_2 + 1));
    auto* puVar3 = (uint8_t*)*self;
    if ((int)_Size < 1) return *(uint32_t*)(puVar3 + -4);
    int iVar1 = *(int*)(puVar3 + -4) + (int)_Size;
    if (iVar1 == 0) {
        if (*(int*)(puVar3 + -4) != 0) { *puVar3 = 0; *(uint32_t*)(*self + -4) = 0; }
    } else if (0 < iVar1) {
        if (*(int*)(puVar3 + -8) < iVar1) FUN_004f32e0(*self, iVar1);
        *(int*)(*self + -4) = iVar1;
    }
    iVar1 = (int)self;
    memmove((void*)(iVar1 + _Size + param_1), (void*)(iVar1 + param_1),
            ((*(int*)(iVar1 + -4) - (int)_Size) - param_1) + 1);
    memmove((void*)(*self + param_1), param_2, _Size);
    return *(uint32_t*)(*self + -4);
}

// 0x4f1f80 — observed shape
int FUN_004f1f80(char param_1, void** self)
{
    int iVar6 = (int)self;
    int iVar3 = *(int*)(iVar6 + -4);
    int iVar1 = iVar3 + -1;
    if ((iVar1 < iVar3) && (-1 < iVar1)) {
        uint8_t uVar2 = *(uint8_t*)(iVar6 + iVar1);
        *(uint8_t*)(iVar6 + iVar1) = 0;
        char* pcVar5 = strrchr((char*)*self, (int)param_1);
        *(uint8_t*)(iVar1 + (int)self) = uVar2;
        if (pcVar5 != (char*)0x0) {
            auto* puVar9 = (uint8_t*)*self;
            iVar6 = (int)pcVar5 - (int)puVar9;
            iVar1 = iVar6;
            if (-1 < iVar6) {
                while (true) {
                    int iVar10 = iVar1;
                    iVar1 = iVar10 + -1;
                    if (-1 < iVar1) {
                        if (puVar9[iVar1] == (uint8_t)param_1) continue;
                    }
                    int iVar7 = (iVar6 - iVar1) + -1;
                    iVar6 = iVar10;
                    if (iVar10 < 0) iVar6 = 0;
                    int iVar4 = *(int*)(puVar9 + -4);
                    int iVar8 = iVar4 - iVar6;
                    if (iVar8 < iVar7) iVar7 = iVar8;
                    if ((iVar6 == 0) && (iVar7 == iVar4)) {
                        if (iVar4 != 0) { *puVar9 = 0; *(uint32_t*)(*self + -4) = 0; }
                    } else if ((0 < iVar7) && (iVar6 < iVar4)) {
                        memmove(puVar9 + iVar6, puVar9 + iVar6 + iVar7, (iVar8 - iVar7) + 1);
                        *(int*)(*self + -4) = *(int*)(*self + -4) - iVar7;
                    }
                    if (iVar1 < 1) break;
                    iVar10 = iVar10 + -2;
                    if (iVar10 == -1) iVar10 = *(int*)(*self + -4) + -1;
                    iVar1 = (int)self;
                    if ((*(int*)(iVar1 + -4) <= iVar10) || (iVar10 < 0)) break;
                    uVar2 = *(uint8_t*)(iVar1 + iVar10);
                    *(uint8_t*)(iVar1 + iVar10) = 0;
                    pcVar5 = strrchr((char*)*self, (int)param_1);
                    *(uint8_t*)(iVar10 + (int)self) = uVar2;
                    if (pcVar5 == (char*)0x0) break;
                    puVar9 = (uint8_t*)*self;
                    iVar6 = (int)pcVar5 - (int)puVar9;
                    iVar1 = iVar6;
                    if (iVar6 < 0) break;
                }
            }
        }
    }
    return iVar3 - *(int*)(*self + -4);
}
// 0x4f20a0 — observed shape
int FUN_004f20a0(char unaff_BL, char in_AL, void** self)
{
    int iVar3 = 0;
    if (unaff_BL != in_AL) {
        char* pcVar1 = (char*)*self;
        char* pcVar2 = pcVar1 + *(int*)(pcVar1 + -4);
        for (; pcVar1 < pcVar2; pcVar1 = pcVar1 + 1) {
            if (*pcVar1 == unaff_BL) { *pcVar1 = in_AL; iVar3 = iVar3 + 1; }
        }
    }
    return iVar3;
}

// 0x4f20d0 — observed shape
extern void FUN_004f32e0(void*, int);
int FUN_004f20d0(int* param_1, char* param_2, char* param_3)
{
    char cVar1;
    char* pcVar5;
    int iVar6; size_t local_10; int local_c = 0;
    if (param_2 == (char*)0x0) iVar6 = 0;
    else { pcVar5 = param_2; do { cVar1 = *pcVar5; pcVar5++; } while (cVar1 != '\0'); iVar6 = (int)pcVar5 - (int)(param_2 + 1); }
    if (param_3 == (char*)0x0) local_10 = 0;
    else { pcVar5 = param_3; do { cVar1 = *pcVar5; pcVar5++; } while (cVar1 != '\0'); local_10 = (size_t)((int)pcVar5 - (int)(param_3 + 1)); }
    if (iVar6 < 1) return 0;
    pcVar5 = (char*)*param_1;
    char* pcVar3 = pcVar5 + *(int*)(pcVar5 + -4);
    if (pcVar3 <= pcVar5) return 0;
    do {
        char* pcVar4 = strstr(pcVar5, param_2);
        while (pcVar4 != (char*)0x0) { pcVar5 = pcVar4 + iVar6; local_c++; pcVar4 = strstr(pcVar5, param_2); }
        do { cVar1 = *pcVar5; pcVar5++; } while (cVar1 != '\0');
    } while (pcVar5 < pcVar3);
    if (local_c < 1) return local_c;
    auto* puVar2 = (uint8_t*)*param_1;
    int local_8 = *(int*)(puVar2 + -4);
    int iVar7 = (int)(local_10 - iVar6) * local_c + local_8;
    if (iVar7 == 0) { if (local_8 != 0) { *puVar2 = 0; *(uint32_t*)(*param_1 + -4) = 0; } }
    else if (0 < iVar7) { if (*(int*)(puVar2 + -8) < iVar7) FUN_004f32e0(*param_1, iVar7); *(int*)(*param_1 + -4) = iVar7; }
    pcVar5 = (char*)*param_1;
    pcVar3 = pcVar5 + local_8;
    if (pcVar5 < pcVar3) {
        do {
            char* pcVar4 = strstr(pcVar5, param_2);
            while (pcVar4 != (char*)0x0) {
                size_t _Size = (size_t)(((*param_1 - (int)pcVar4) - iVar6) + local_8);
                pcVar5 = pcVar4 + local_10;
                memmove(pcVar5, pcVar4 + iVar6, _Size);
                memmove(pcVar4, param_3, local_10);
                local_8 = local_8 + (int)(local_10 - iVar6);
                pcVar5[_Size] = '\0';
                pcVar4 = strstr(pcVar5, param_2);
            }
            do { cVar1 = *pcVar5; pcVar5++; } while (cVar1 != '\0');
        } while (pcVar5 < pcVar3);
    }
    return local_c;
}

// 0x4f22c0 — observed shape
extern int FUN_004f1f80(char, void**);
extern int FUN_004f24f0(int*);
extern void FUN_004ccf60(void);
int FUN_004f22c0(int* param_1, int param_2)
{
    char* pcVar3 = (char*)*param_1;
    char* pcVar6 = pcVar3 + *(int*)(pcVar3 + -4);
    for (; pcVar3 < pcVar6; pcVar3++) if (*pcVar3 == '\t') *pcVar3 = ' ';
    FUN_004ccf60();
    FUN_004f1f80(0x20, (void**)param_1);
    if (0 < param_2) {
        int iVar4 = *param_1;
        int iVar10 = *(int*)(iVar4 + -4);
        int local_4 = 0;
        if (0 < iVar10) {
            do {
                if ((local_4 < iVar10) && (-1 < local_4) &&
                    (pcVar3 = strchr((char*)(iVar4 + local_4), 10), pcVar3 != (char*)0x0) &&
                    (iVar4 = (int)pcVar3 - *param_1, -1 < iVar4 && (iVar4 < local_4 + param_2))) {
                    local_4 = iVar4 + 1;
                } else {
                    int iVar7 = *param_1;
                    iVar10 = local_4 + param_2;
                    iVar4 = iVar10;
                    if (*(int*)(iVar7 + -4) <= iVar10) iVar4 = *(int*)(iVar7 + -4) + -1;
                    if (iVar4 < iVar10) { local_4 = iVar4 + 1; }
                    else {
                        bool bVar2 = true;
                        int iVar5 = -1;
                        do {
                            iVar10 = iVar4;
                            if (iVar4 == -1) iVar10 = *(int*)(iVar7 + -4) + -1;
                            if ((iVar10 < *(int*)(iVar7 + -4)) && (-1 < iVar10)) {
                                uint8_t uVar1 = *(uint8_t*)(iVar7 + iVar10);
                                *(uint8_t*)(iVar7 + iVar10) = 0;
                                pcVar3 = strrchr((char*)*param_1, 0x20);
                                *(uint8_t*)(iVar10 + *param_1) = uVar1;
                                if (pcVar3 == (char*)0x0) goto NEXT;
                                iVar10 = *param_1;
                                iVar5 = (int)pcVar3 - iVar10;
                                if (iVar5 < 0) goto NEXT;
                                if (iVar5 <= local_4) { if (!bVar2) { bVar2 = true; iVar4++; } goto NEXT; }
                                uint8_t bVar8 = (iVar5 + 1 < *(int*)(iVar10 + -4)) ? *(uint8_t*)(iVar10 + 1 + iVar5) : 0;
                                uint8_t bVar9 = (iVar5 + 2 < *(int*)(iVar10 + -4)) ? *(uint8_t*)(iVar10 + 2 + iVar5) : 0;
                                if (((((char)bVar8 < -0x80) || (0xff < (char)bVar8)) || (ispunct((uint)bVar8) == 0)) ||
                                     ((bVar9 != 0 && ((((char)bVar9 < -0x80 || (0xff < (char)bVar9)) || (isspace((uint)bVar9) == 0)))))) {
                                    *(uint8_t*)(iVar5 + *param_1) = 10;
                                } else {
                                    if (!bVar2) { bVar2 = true; iVar4++; goto NEXT; }
                                    bVar2 = false; iVar4--;
                                }
                            } else {
NEXT:
                                iVar4++;
                                if ((iVar4 < *(int*)(*param_1 + -4)) && (-1 < iVar4) &&
                                    (pcVar3 = strpbrk((char*)(*param_1 + iVar4), " \n"), pcVar3 != (char*)0x0))
                                    iVar5 = (int)pcVar3 - *param_1; else iVar5 = -1;
                                iVar4 = iVar5;
                                if (iVar5 < 0) goto DONE;
                            }
                            iVar7 = *param_1;
                        } while (*(char*)(iVar7 + iVar5) != '\n');
DONE:
                        local_4 = (iVar5 < 0) ? *(int*)(*param_1 + -4) : iVar5 + 1;
                    }
                }
                iVar4 = *param_1;
                iVar10 = *(int*)(iVar4 + -4);
            } while (local_4 < iVar10);
        }
    }
    if (*(int*)(*param_1 + -4) == 0) return 0;
    return FUN_004f24f0(param_1) + 1;
}

// 0x4f24f0 — observed shape
int FUN_004f24f0(int* param_1, int in_EAX, char unaff_BL)
{
    int iVar2 = 0;
    while (true) {
        if ((*(int*)(*param_1 + -4) <= in_EAX) || (in_EAX < 0)) return iVar2;
        char* pcVar1 = strchr((char*)(*param_1 + in_EAX), (int)unaff_BL);
        if (pcVar1 == (char*)0x0) return iVar2;
        if ((int)pcVar1 - *param_1 < 0) break;
        iVar2++;
        in_EAX = ((int)pcVar1 - *param_1) + 1;
        if (in_EAX < 0) return iVar2;
    }
    return iVar2;
}

// 0x4f2530 — observed shape
extern int isalnum(int);
int FUN_004f2530(int* param_1, char* param_2, int in_ECX)
{
    int iVar3;
    if (param_2 == (char*)0x0) iVar3 = 0;
    else {
        char* pcVar2 = param_2; char cVar1;
        do { cVar1 = *pcVar2; pcVar2++; } while (cVar1 != '\0');
        iVar3 = (int)pcVar2 - (int)(param_2 + 1);
    }
    while (true) {
        if ((*(int*)(*param_1 + -4) <= in_ECX) || (in_ECX < 0)) return -1;
        char* pcVar2 = strstr((char*)(*param_1 + in_ECX), param_2);
        if (pcVar2 == (char*)0x0) return -1;
        int iVar5 = *param_1;
        int iVar4 = (int)pcVar2 - iVar5;
        if (iVar4 < 0) return iVar4;
        uint8_t bVar7 = (iVar4 + iVar3 < *(int*)(iVar5 + -4)) ? *(uint8_t*)(iVar5 + iVar4 + iVar3) : 0;
        uint8_t bVar6 = (iVar4 + -1 < 0) ? 0 : *(uint8_t*)(iVar5 + -1 + iVar4);
        if ((((char)bVar6 < -0x80) || (0xff < (char)bVar6)) || (isalnum((uint)bVar6) == 0)) {
            if ((char)bVar7 < -0x80) return iVar4;
            if (0xff < (char)bVar7) return iVar4;
            if (isalnum((uint)bVar7) == 0) return iVar4;
        }
        in_ECX = iVar4 + 1;
    }
}
// 0x4f2620 — observed shape
// NEEDS_MANUAL: lengthy vsprintf-format scanner; observed structure preserved below
extern void FUN_004f32e0(void*, int);
extern int isdigit(int);
extern int atoi(const char*);
extern int sprintf(char*, const char*, ...);
extern int vsprintf(char*, const char*, va_list);
extern size_t wcslen(const wchar_t*);
void FUN_004f2620(int* param_1, uint8_t* param_2, size_t* param_3)
{
    size_t* _Args = param_3;
    uint8_t bVar5 = *param_2;
    char* local_c = (char*)0x0;
    uint8_t* _Str = param_2;
    while (true) {
        if (bVar5 == 0) {
            auto* puVar3 = (uint8_t*)*param_1;
            if (*(int*)(puVar3 + -8) < (int)local_c) {
                int iVar6 = *(int*)(puVar3 + -4);
                if (local_c == (char*)0x0) {
                    if (iVar6 != 0) { *puVar3 = 0; *(uint32_t*)(*param_1 + -4) = 0; }
                } else if (0 < (int)local_c) { FUN_004f32e0(*param_1, (int)local_c); *(char**)(*param_1 + -4) = local_c; }
                *(int*)(*param_1 + -4) = iVar6;
            }
            vsprintf((char*)*param_1, (char*)param_2, (va_list)_Args);
            char* pcVar8 = (char*)*param_1; char* pcVar9 = pcVar8; char cVar2;
            do { cVar2 = *pcVar9; pcVar9++; } while (cVar2 != '\0');
            *(int*)(pcVar8 + -4) = (int)pcVar9 - (int)(pcVar8 + 1);
            return;
        }
        if (*_Str == 0x25) {
            bVar5 = _Str[1]; _Str++;
            if (bVar5 != 0x25) {
                size_t local_8 = 0;
                if (bVar5 == 0) goto PARSE_INT;
                do {
                    if (bVar5 == 0x23) local_c += 2;
                    else if (bVar5 == 0x2a) { local_8 = *param_3; param_3++; }
                    else if (((bVar5 != 0x2d) && (bVar5 != 0x2b)) && (bVar5 != 0x30) && (bVar5 != 0x20)) break;
                    bVar5 = _Str[1]; _Str++;
                } while (bVar5 != 0);
                if (local_8 == 0) {
PARSE_INT:
                    local_8 = atoi((char*)_Str);
                    bVar5 = *_Str;
                    while (bVar5 != 0) {
                        if (((char)bVar5 < -0x80) || (0xff < (char)bVar5)) break;
                        if (isdigit((uint)bVar5) == 0) break;
                        bVar5 = _Str[1]; _Str++;
                    }
                }
                size_t sVar11 = 0;
                if (*_Str == 0x2e) {
                    uint8_t* _Str_00 = _Str + 1;
                    if (_Str[1] == 0x2a) { sVar11 = *param_3; param_3++; _Str += 2; }
                    else {
                        sVar11 = atoi((char*)_Str_00);
                        bVar5 = *_Str_00; _Str = _Str_00;
                        while ((bVar5 != 0 && (-0x81 < (char)bVar5)) && ((char)bVar5 < 0x100 && isdigit((uint)bVar5) != 0)) {
                            bVar5 = _Str[1]; _Str++;
                        }
                    }
                }
                size_t* psVar4 = param_3;
                uint uVar13 = 0;
                if (strncmp((char*)_Str, "I64", 3) == 0) { _Str += 3; uVar13 = 0x40000; }
                else {
                    switch (*_Str) {
                        case 0x46: case 0x4c: case 0x4e: break;
                        default: goto CONV;
                        case 0x68: uVar13 = 0x10000; break;
                        case 0x6c: uVar13 = 0x20000; break;
                    }
                    _Str++;
                }
CONV:
                uint uVar10 = (int)(char)*_Str | uVar13;
                size_t sVar7 = 0;
                if ((int)uVar10 < 0x10064) {
                    if (uVar10 != 0x10063) {
                        if ((int)uVar10 < 0x74) {
                            if (uVar10 == 0x73) goto STR_S;
                            if (uVar10 != 0x43) {
                                if (uVar10 != 0x53) { if (uVar10 == 99) goto ONE; goto OTHER; }
                                goto WIDE_S;
                            }
                        } else if (uVar10 != 0x10043) {
                            if (uVar10 != 0x10053) goto OTHER;
STR_S:
                            char* pcVar8 = (char*)*param_3;
                            if (pcVar8 == (char*)0x0) sVar7 = 6;
                            else {
                                char* pcVar9 = pcVar8 + 1; char c;
                                do { c = *pcVar8; pcVar8++; } while (c != '\0');
                                sVar7 = (size_t)((int)pcVar8 - (int)pcVar9);
                                if (0 < (int)sVar7) goto ADV;
                                sVar7 = 1;
                            }
                            goto WID;
                        }
                    }
ONE: sVar7 = 1;
WID:
                    param_3 = psVar4 + 1;
                    if ((sVar11 != 0) && ((int)sVar11 <= (int)sVar7)) sVar7 = sVar11;
                    if ((int)local_8 < (int)sVar7) goto ADD;
                    local_c += local_8;
                } else {
                    if ((int)uVar10 < 0x20054) {
                        if (uVar10 != 0x20053) {
                            if (uVar10 == 0x10073) goto STR_S;
                            if (uVar10 == 0x20043) goto ONE;
                            goto OTHER;
                        }
WIDE_S:
                        if ((wchar_t*)*param_3 == (wchar_t*)0x0) sVar7 = 6;
                        else {
                            sVar7 = wcslen((wchar_t*)*param_3);
                            if ((int)sVar7 < 1) sVar7 = 1;
                            else { ADV: param_3++; if (sVar7 == 0) goto OTHER; }
                        }
                        goto WID;
                    }
                    if (uVar10 == 0x20063) goto ONE;
                    if (uVar10 == 0x20073) goto WIDE_S;
OTHER:
                    switch (*_Str) {
                        case 0x45: case 0x47: case 0x65: case 0x67:
                            param_3 += 2; sVar7 = local_8 + sVar11;
                            if (0x7f < (int)sVar7) goto ADD;
                            local_c += 0x80; break;
                        case 0x58: case 100: case 0x69: case 0x6f: case 0x75: case 0x78:
                            param_3 += ((uVar13 & 0x40000) == 0) ? 1 : 2;
                            sVar7 = sVar11 + local_8;
                            if (0x1f < (int)sVar7) goto ADD;
                            local_c += 0x20; break;
                        case 0x66: {
                            char stack[32]; char* pc = stack; uint64_t u = *(uint64_t*)param_3; param_3 += 2;
                            sprintf(stack, "%*.*f", (int)local_8, (int)sVar11 + 6, u);
                            char c; do { c = *pc; pc++; } while (c != '\0');
                            local_c = pc + ((int)local_c - (int)(stack + 1)); break;
                        }
                        case 0x6e: param_3++;
                        default:
ADD: local_c += sVar7; break;
                        case 0x70:
                            param_3++; sVar7 = sVar11 + local_8;
                            if (0x1f < (int)sVar7) goto ADD;
                            local_c += 0x20;
                    }
                }
                goto NEXTCH;
            }
        }
        local_c++;
NEXTCH:
        bVar5 = _Str[1]; _Str++;
    }
}

// 0x4f2aa0 — observed shape
// NEEDS_MANUAL: large backslash-escape decoder over two string buffers with many cases; preserved below
extern uint8_t DAT_008cacd0[];
extern int DAT_008caccc;
extern int DAT_008cacc8;
extern int* FUN_004f1840(void);
extern void FUN_004f3350(void*, int);
extern void FUN_004f31c0(void**, int);
extern void FUN_00489300(void);
extern void FUN_00412f90(void);
extern void operator_delete__(void*);
void FUN_004f2aa0(int* param_1)
{
    uint8_t* local_10 = DAT_008cacd0;
    uint8_t* local_18 = DAT_008cacd0;
    uint8_t* local_c = DAT_008cacd0;
    if ((0 < *(int*)((char*)*param_1 + -4)) && ((strchr((char*)*param_1, 0x5c) != (char*)0x0))) {
        int local_14 = (int)strchr((char*)*param_1, 0x5c) - *param_1;
        if (local_14 != -1) {
            int* piVar8 = &DAT_008caccc;
            while (true) {
                int iVar9 = local_14;
                int* piVar4 = FUN_004f1840();
                void* local_4 = (void*)*piVar4;
                size_t sVar2 = *(size_t*)((int)local_4 + -4);
                int local_8 = *piVar8;
                if ((0 < (int)sVar2) && (-1 < local_8) && (local_4 != (void*)0x0)) {
                    if (local_8 < local_8 + (int)sVar2) { FUN_004f3350(local_18, (int)sVar2); piVar8 = (int*)(local_18 + -4); local_18[*(int*)(local_18 + -4)] = 0; iVar9 = local_14; }
                    memmove(local_18 + local_8, local_4, sVar2);
                }
                void* puVar5 = (void*)(local_c + -8);
                if ((puVar5 != (void*)0x0) && (puVar5 != &DAT_008cacc8)) operator_delete__(puVar5);
                int iVar10 = iVar9 + 1;
                local_c = DAT_008cacd0; local_14 = iVar10;
                if (*(int*)(*param_1 + -4) <= iVar10) goto ENDCHK;
                if (*(int*)(local_10 + -4) != 0) { *local_10 = 0; *(uint32_t*)(local_10 + -4) = 0; }
                int iVar6 = *param_1;
                char local_1c[4]; char local_1d = 0;
                switch ((uint8_t)*(iVar6 + iVar10)) {
                    case 0x22: local_1c[0] = '"'; break;
                    case 0x27: local_1c[0] = '\''; break;
                    case 0x3f: local_1c[0] = '?'; break;
                    case 0x5c: local_1c[0] = '\\'; break;
                    case 0x61: local_1c[0] = '\a'; break;
                    case 0x62: local_1c[0] = '\b'; break;
                    case 0x66: local_1c[0] = '\f'; break;
                    case 0x6e: local_1c[0] = '\n'; break;
                    case 0x72: local_1c[0] = '\r'; break;
                    case 0x74: local_1c[0] = '\t'; break;
                    case 0x76: local_1c[0] = '\v'; break;
                    case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37:
                        if (iVar10 < *(int*)(iVar6 + -4)) {
                            do {
                                char c = *(char*)(iVar6 + local_14); iVar10 = local_14;
                                if ((c < '0') || ('7' < c)) break;
                                uint u = (uint)(c != '\0'); void* l4 = *(void**)(local_10 + -4); local_1c[0] = c;
                                if ((u != 0) && (-1 < (int)l4)) {
                                    if ((int)l4 < (int)((int)l4 + u)) { FUN_004f3350(local_10, 1); local_10[*(int*)(local_10 + -4)] = 0; }
                                    iVar10 = local_14; memmove((uint8_t*)((int)l4 + (int)local_10), local_1c, u);
                                }
                                iVar6 = *param_1; iVar10++; local_14 = iVar10;
                            } while (iVar10 < *(int*)(iVar6 + -4));
                        }
                        goto OCTTAIL;
                    case 0x78:
                        iVar10 = iVar9 + 2; local_1d = '\x01'; local_14 = iVar10;
                        if (iVar10 < *(int*)(iVar6 + -4)) {
                            do {
                                char c = *(char*)(iVar6 + local_14);
                                if (((c < '0') || ('9' < c)) && ((c < 'A' || ('F' < c)) && (iVar10 = local_14, c < 'a' || ('f' < c)))) break;
                                uint u = (uint)(c != '\0'); void* l4 = *(void**)(local_10 + -4); iVar10 = local_14; local_1c[0] = c;
                                if ((u != 0) && (-1 < (int)l4)) {
                                    if ((int)l4 < (int)((int)l4 + u)) { FUN_004f3350(local_10, 1); local_10[*(int*)(local_10 + -4)] = 0; }
                                    iVar10 = local_14; memmove((uint8_t*)((int)l4 + (int)local_10), local_1c, u);
                                }
                                iVar6 = *param_1; iVar10++; local_14 = iVar10;
                            } while (iVar10 < *(int*)(iVar6 + -4));
                        }
                        goto OCTTAIL;
                    default: {
                        local_1c[0] = '\\';
                        int t = *piVar8;
                        if (-1 < t) {
                            if (t < t + 1) { FUN_004f3350(local_18, 1); piVar8 = (int*)(local_18 + -4); local_18[*(int*)(local_18 + -4)] = 0; }
                            iVar10 = local_14; memmove(local_18 + t, local_1c, 1);
                        }
                        local_1c[0] = *(char*)(iVar10 + *param_1);
                        uint u = (uint)(local_1c[0] != '\0'); void* l4 = (void*)*piVar8;
                        if ((u == 0) || ((int)l4 < 0)) goto OCTTAIL;
                        if ((int)l4 < (int)(u + (int)l4)) { FUN_004f3350(local_18, (int)u); piVar8 = (int*)(local_18 + -4); local_18[*(int*)(local_18 + -4)] = 0; iVar10 = local_14; }
                        memmove((uint8_t*)((int)l4 + (int)local_18), local_1c, u);
                        goto OCTTAIL;
                    }
                }
                {
                    int t = *piVar8;
                    if (-1 < t) {
                        if (t < t + 1) { FUN_004f3350(local_18, 1); piVar8 = (int*)(local_18 + -4); local_18[*(int*)(local_18 + -4)] = 0; }
                        memmove(local_18 + t, local_1c, 1);
                    }
                }
OCTTAIL:
                if (*(int*)(local_10 + -4) == 0) iVar10++;
                else {
                    local_1c[0] = (char)(int)FUN_004f31c0((void**)&local_10, (local_1d != '\0') * '\b' + '\b');
                    uint u = (uint)(local_1c[0] != '\0'); void* l4 = (void*)*piVar8;
                    if ((u != 0) && (-1 < (int)l4)) {
                        if ((int)l4 < (int)(u + (int)l4)) { FUN_004f3350(local_18, (int)u); piVar8 = (int*)(local_18 + -4); local_18[*(int*)(local_18 + -4)] = 0; iVar10 = local_14; }
                        memmove((uint8_t*)((int)l4 + (int)local_18), local_1c, u);
                    }
                }
ENDCHK:
                if (!((iVar10 < *(int*)(*param_1 + -4)) && (-1 < iVar10) &&
                      (strchr((char*)(*param_1 + iVar10), 0x5c) != (char*)0x0) &&
                      (local_14 = (int)strchr((char*)(*param_1 + iVar10), 0x5c) - *param_1, local_14 != -1))) break;
            }
        }
    }
    FUN_004f1840(); FUN_00489300();
    void* puVar5 = (void*)(local_c + -8);
    if ((puVar5 != (void*)0x0) && (puVar5 != &DAT_008cacc8)) operator_delete__(puVar5);
    uint8_t* puVar7 = local_18;
    size_t sVar2 = *(size_t*)(local_18 + -4);
    if ((-1 < (int)sVar2) && (local_18 != (uint8_t*)*param_1)) {
        if (sVar2 == 0) FUN_00412f90();
        else { FUN_004f3350((void*)*param_1, (int)sVar2); memmove((void*)*param_1, puVar7, sVar2); *(uint8_t*)(*param_1 + *(int*)(*param_1 + -4)) = 0; }
    }
    puVar5 = (void*)(puVar7 + -8);
    if ((puVar5 != (void*)0x0) && (puVar5 != &DAT_008cacc8)) operator_delete__(puVar5);
    puVar5 = (void*)(local_10 + -8);
    if ((puVar5 != (void*)0x0) && (puVar5 != &DAT_008cacc8)) operator_delete__(puVar5);
}

// 0x4f3050 — observed shape
extern void FUN_004f32e0(void*, int);
int FUN_004f3050(int unaff_ESI, void** self)
{
    auto* puVar1 = (uint8_t*)*self;
    if (*(int*)(puVar1 + -8) < unaff_ESI) {
        int iVar2 = *(int*)(puVar1 + -4);
        if (unaff_ESI == 0) {
            if (iVar2 != 0) { *puVar1 = 0; *(uint32_t*)(*self + -4) = 0; *(int*)(*self + -4) = iVar2; return (int)self; }
        } else if (0 < unaff_ESI) { FUN_004f32e0(*self, unaff_ESI); *(int*)(*self + -4) = unaff_ESI; }
        *(int*)(*self + -4) = iVar2;
    }
    return (int)self;
}

// 0x4f30a0 — observed shape
void FUN_004f30a0(int in_EAX, void** self)
{
    char* pcVar2 = (char*)*self;
    if (in_EAX == -1) {
        char* pcVar3 = pcVar2; char c;
        do { c = *pcVar3; pcVar3++; } while (c != '\0');
        *(int*)(pcVar2 + -4) = (int)pcVar3 - (int)(pcVar2 + 1);
        return;
    }
    *(int*)(pcVar2 + -4) = in_EAX;
    if (0 < in_EAX) *(uint8_t*)(in_EAX + (int)self) = 0;
}

// 0x4f30d0 — observed shape
extern void FUN_004f3350(void*, int);
extern void FUN_00412f90(void);
void FUN_004f30d0(int param_1, void* in_EAX, size_t in_ECX, int** self)
{
    if (((-1 < (int)in_ECX) && (-1 < param_1)) && (in_EAX != 0) && (in_EAX != *self)) {
        if (in_ECX != 0) {
            FUN_004f3350(*self, (int)in_ECX);
            memmove((void*)*self, (void*)((int)in_EAX + param_1), in_ECX);
            *(uint8_t*)(*self + *(int*)(*self + -4)) = 0;
            return;
        }
        FUN_00412f90();
    }
}
