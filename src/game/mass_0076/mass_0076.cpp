#include <cstdint>
#include <cstddef>
#include <windows.h>

// Externs for vtables/globals referenced by listings
extern void* PTR_FUN_007109b4;
extern void* PTR_FUN_006f5814;
extern void* PTR_FUN_006f583c;
extern void* PTR_FUN_006f5864;
extern unsigned char DAT_008cacd0;
extern unsigned char DAT_008cacc8;
extern unsigned char DAT_008caccc;
extern unsigned char DAT_008cacf8;
extern unsigned char DAT_0070c164;
extern unsigned char DAT_00710a2c;
extern unsigned char DAT_007149ac;
extern void* PTR_FUN_007109d0;
extern void* PTR_FUN_007109ec;
extern void* PTR_FUN_007109b0;
extern void* PTR_FUN_00710a14;
extern void* PTR_LAB_00710a08;

unsigned char* DAT_008cacd0_ptr = &DAT_008cacd0;
unsigned char* DAT_008cacc8_ptr = &DAT_008cacc8;

// Helpers
extern void operator_delete__(void* ptr);
extern int FUN_004f4b20(int param_2, int a, int b, int c);
extern void FUN_00412b40();
extern void FUN_004f8110(void* p);
extern void* FUN_004f1220(int a, int b);
extern void FUN_004f8250(void* p);
extern void FUN_00412cb0();
extern char FUN_004f8900();
extern void FUN_004fb190(int param_1);
extern void FUN_00412f10();
extern void FUN_004f8a90();
extern void FUN_00475ff0(unsigned char c);
extern void FUN_00412970();
extern void FUN_00412ec0();
extern int FUN_004fb1f0(int a, int b, void* self);
extern int FUN_004f10f0(void* p, int sz);
extern int FUN_004fe190(void* p);
extern int FUN_004f4ea0(size_t* p, size_t sz);
extern void FUN_004f4de0();
extern void FUN_004f0dc0();
extern void* thunk_FUN_00533c78(size_t sz);
extern void FUN_004fbfd0();
extern void FUN_004e6420();
extern void* FUN_00517f90();
extern void FUN_00412e50(void* p);
extern void FUN_004f20a0();
extern void FUN_004fbf80(int* p);
extern void FUN_00412df0();
extern void FUN_004fbf10();
extern int FUN_004fdf40(void* a, void* b, int c);
extern void FUN_004fe030();
extern void FUN_004fbec0();
extern void* FUN_004fbe90(void* a, const char* b, void* c);
extern void FUN_004f1d50();
extern void* FUN_00412a60(void* a, const char* b);
extern void FUN_00412fb0();
extern char FUN_004fbd10(void* p, char flag);
extern void FUN_00476050();
extern void FUN_004f30d0(int a);
extern void FUN_004f1840();
extern void FUN_0051bfc0(char** p);
extern void FUN_00524e90(void* p);
extern char FUN_004b0fa0();
extern void FUN_004fe2d0(void* a, void* b, void* c);
extern void FUN_004fc070();

// 0x4fae60 — destructor body, iterates rows at self[2..3], deletes string cells
void FUN_004fae60(void* self) {
    uint32_t** s = (uint32_t**)self;
    int local_4 = 0;
    s[0] = (uint32_t*)&PTR_FUN_007109b4;
    if (0 < (int)s[3]) {
        do {
            int iVar2 = *(int*)(s[2] + local_4);
            if (iVar2 != 0) {
                int iVar5 = *(int*)(iVar2 + -4);
                uint32_t* puVar4 = (uint32_t*)(iVar2 + iVar5 * 4);
                if (-1 < iVar5 + -1) {
                    do {
                        uint32_t* piVar1 = puVar4 + -1;
                        puVar4 = puVar4 + -1;
                        uint32_t* puVar3 = (uint32_t*)(*piVar1 + -8);
                        if (puVar3 != (uint32_t*)0x0 && puVar3 != (uint32_t*)&DAT_008cacc8) {
                            operator_delete__((void*)puVar3);
                        }
                        iVar5 = iVar5 + -1;
                        *puVar4 = (uint32_t)&DAT_008cacd0;
                    } while (iVar5 != 0);
                }
                operator_delete__((void*)(iVar2 + -4));
            }
            local_4 = local_4 + 1;
        } while (local_4 < (int)s[3]);
    }
    operator_delete__((void*)s[2]);
}

// 0x4faef0 — CSV/text reader with comma, newline, quote handling
uint32_t FUN_004faef0(uint32_t param_1, uint32_t param_2) {
    unsigned char local_28 = 0;
    unsigned char local_10 = 0;
    unsigned char local_c = 0;
    uint32_t local_40 = 0, local_3c = 0, local_38 = 0, local_34 = 0, local_30 = 0, local_2c = 0;
    uint32_t local_1c = 0;
    int local_18 = 0;
    void* local_44 = &PTR_FUN_006f5814;
    uint32_t local_14 = 0, local_8 = 0, local_4 = 0;
    int local_4c = 0;
    int pcStack_54 = 0;
    int iVar3 = FUN_004f4b20(param_2, 1, 0, 0);
    if (iVar3 != 0) {
        FUN_00412b40();
        return 0;
    }
    FUN_004f8110(&local_44);
    if (local_18 == 0) {
        local_4 = (uint32_t)FUN_004f1220(0, 1);
    } else {
        local_4 = *(uint32_t*)(local_18 + 0x14);
    }
    int local_24 = 0;
    if (local_24 == 1) {
        FUN_004f8250(&local_44);
    }
    FUN_00412cb0();
    unsigned int uVar4 = (*(unsigned int(*)())(() ->) { return 0; })();
    (void)uVar4; (void)local_4c; (void)pcStack_54; (void)local_28; (void)local_10; (void)local_c;
    (void)local_40; (void)local_3c; (void)local_38; (void)local_34; (void)local_30; (void)local_2c;
    (void)local_1c; (void)local_14; (void)local_8;
    // Identifiers from listing loop depend on stream virtuals; body gated by uVar4 < uVar5
    unsigned int uVar5 = 0;
    if (uVar4 < uVar5) {
        do {
            char cVar1 = FUN_004f8900();
            if (cVar1 != '\0') {
                char cSym = cVar1;
                if (cSym == ',') {
                    FUN_004fb190((int)local_4);
                    FUN_00412f10();
                } else if (cSym == '\n' || cSym == '\r') {
                    char cVar2 = FUN_004f8900();
                    if (cVar2 != '\0') {
                        if (cSym != '\n' && cSym != '\r') FUN_004f8a90();
                        FUN_004fb190((int)local_4);
                        FUN_00412f10();
                    }
                } else if (cSym == '\"') {
                    do {
                        cVar1 = FUN_004f8900();
                        if (cVar1 == '\0') break;
                        char cIn = cVar1;
                        if (cIn == '\"') {
                            cVar1 = FUN_004f8900();
                            if (cVar1 == '\0') break;
                            if (cVar1 == '\"') {
                                FUN_00475ff0(0x22);
                            } else {
                                FUN_004f8a90();
                            }
                        } else {
                            FUN_00475ff0((unsigned char)cIn);
                        }
                    } while (cVar1 != '\"');
                } else {
                    FUN_00475ff0((unsigned char)cSym);
                }
            }
            uVar4 = 0;
            uVar5 = 0;
        } while (uVar4 < uVar5);
    }
    FUN_00412970();
    FUN_00412b40();
    return 1;
}

// 0x4fb190 — set cell, bounds-checked on self[0xc],self[0x10]
uint32_t FUN_004fb190(int param_1) {
    // Ghidra marks unaff_ESI/unaff_EDI — observed as by-register indices
    int unaff_ESI = 0;
    int unaff_EDI = 0;
    if ((unaff_ESI < 0 || *(int*)(param_1 + 0xc) <= unaff_ESI) || (unaff_EDI < 0 || *(int*)(param_1 + 0x10) <= unaff_EDI)) {
        return 0;
    }
    FUN_00412cb0();
    FUN_00412ec0();
    uint32_t* puVar1 = (uint32_t*)(param_1 + -8);
    if (puVar1 != (uint32_t*)0x0 && puVar1 != (uint32_t*)&DAT_008cacc8) {
        operator_delete__((void*)puVar1);
    }
    return 1;
}

// 0x4fb1f0 — bounds-checked 2D grid fetch: self+8 rows, self[0xc],self[0x10] extents
uint32_t FUN_004fb1f0(int in_EAX, int in_ECX, int in_EDX) {
    void* self = (void*)(intptr_t)in_EDX;
    (void)self;
    if ((in_EAX < 0 || *(int*)(in_EDX + 0xc) <= in_EAX) || (in_ECX < 0 || *(int*)(in_EDX + 0x10) <= in_ECX)) {
        return 0;
    }
    return *(uint32_t*)(*(int*)(*(int*)(in_EDX + 8) + in_EAX * 4) + in_ECX * 4);
}

// 0x4fb210 — file-load dependent
uint32_t FUN_004fb210(size_t* param_1, int param_2) {
    size_t* psVar3 = param_1;
    size_t* psVar1 = param_1 + 1;
    int iVar4;
    void* local_30 = &PTR_FUN_006f583c;
    int local_4 = 0;
    int local_34 = 0;
    void* local_14 = &DAT_008cacd0;
    void* param_1_ret;
    if ((void*)*psVar1 != (void*)0x0) {
        operator_delete__((void*)*psVar1);
        psVar3[1] = 0;
    }
    *psVar3 = 0;
    iVar4 = FUN_004f4b20(param_2, 1, 0, 0x8000);
    if (iVar4 == 0) {
        if (local_4 == 0) {
            iVar4 = FUN_004f10f0(&param_2, 4);
        } else {
            iVar4 = FUN_004fe190(&param_2);
        }
        if ((iVar4 == 4) && (param_2 == 0x20455543)) {
            if (local_4 == 0) {
                iVar4 = FUN_004f10f0(&local_34, 4);
            } else {
                iVar4 = FUN_004fe190(&local_34);
            }
            bool bVar7 = (iVar4 == 4);
            if (bVar7 && local_34 == 1) {
                iVar4 = FUN_004f4ea0(psVar3, 4);
                bVar7 = (iVar4 == 4);
                if (bVar7 && *psVar3 != 0) {
                    size_t sVar5 = (size_t)thunk_FUN_00533c78(*psVar3 * 0x18);
                    size_t sVar2 = *psVar3;
                    psVar3[1] = sVar5;
                    iVar4 = FUN_004f4ea0((size_t*)sVar5, sVar2 * 0x18);
                    bVar7 = (iVar4 == (int)(sVar2 * 0x18));
                }
            }
            FUN_004f4de0();
            if (bVar7) {
                param_1_ret = (void*)0x0;
                // qsort with comparator LAB_004fb620
                if ((void*)psVar3[1] != (void*)0x0) {
                    goto cleanup;
                }
                goto cleanup;
            }
            param_1_ret = (void*)0x2;
        } else {
            param_1_ret = (void*)0x2;
        }
    } else {
        param_1_ret = (void*)0x1;
        if ((void*)psVar3[1] != (void*)0x0) {
            operator_delete__((void*)psVar3[1]);
            psVar3[1] = 0;
        }
        *psVar3 = 0;
        goto cleanup;
    }
    if ((void*)psVar3[1] != (void*)0x0) {
        operator_delete__((void*)psVar3[1]);
        psVar3[1] = 0;
    }
    *psVar3 = 0;
cleanup:
    local_30 = &PTR_FUN_006f583c;
    FUN_004f4de0();
    local_30 = &PTR_FUN_006f5864;
    FUN_004f0dc0();
    {
        uint32_t* puVar6 = (uint32_t*)((unsigned char*)local_14 + -8);
        if (puVar6 != (uint32_t*)0x0 && puVar6 != (uint32_t*)&DAT_008cacc8) operator_delete__((void*)puVar6);
    }
    return (uint32_t)param_1_ret;
}

// ---------------------------------------------------------------------------
// Retry pass: reconstructions for 0x4fb400 .. 0x4fc0ae.
// Additional declarations used only by these listings.
// ---------------------------------------------------------------------------
extern void operator_delete(void* ptr);
extern int FUN_00533c78(size_t sz);
extern "C" void qsort(void* base, size_t num, size_t width,
                      int (__cdecl* compare)(const void*, const void*));
extern "C" char* strrchr(const char* str, int ch);
extern "C" char* _strlwr(char* str);
extern "C" int _strnicmp(const char* a, const char* b, size_t n);
extern "C" int LAB_004fb620(const void* a, const void* b);
struct ThrowInfo;
extern "C" void _CxxThrowException(void* pExceptionObject, ThrowInfo* pThrowInfo);

// 0x4fb400 — observed shape: RIFF/WAVE cue-table loader over mmio; fills
// self[0] = cue count, self[1] = cue array (0x18 bytes per entry), scales each
// entry's dword at +0x14 by 1000 / sample rate read from the fmt chunk.
int FUN_004fb400(void* self, LPSTR param_1) {
    uint32_t* s = (uint32_t*)self;
    HMMIO hmmio;
    MMRESULT MVar1;
    LONG LVar2;
    uint32_t uVar3;
    int iVar4;
    int iVar5;
    MMRESULT local_38;
    MMRESULT local_34;
    MMRESULT local_30;
    MMRESULT local_2c;
    MMCKINFO local_28;
    MMCKINFO local_14;

    if ((void*)s[1] != (void*)0x0) {
        operator_delete__((void*)s[1]);
        s[1] = 0;
    }
    *s = 0;
    hmmio = mmioOpenA(param_1, (LPMMIOINFO)0x0, 0);
    if (hmmio == (HMMIO)0x0) {
        iVar5 = 1;
        goto LAB_004fb5d0;
    }
    local_14.cksize = 0;
    local_14.fccType = 0;
    local_14.dwDataOffset = 0;
    local_14.dwFlags = 0;
    local_14.ckid = 0x46464952;
    local_14.fccType = mmioStringToFOURCCA("WAVE", 0);
    MVar1 = mmioDescend(hmmio, &local_14, (MMCKINFO*)0x0, 0x20);
    iVar5 = 0;
    if (MVar1 != 0) {
        iVar5 = 2;
    } else {
        // MVar1 is 0 on this path, so the chunk header starts cleared
        local_28.ckid = MVar1;
        local_28.cksize = MVar1;
        local_28.fccType = MVar1;
        local_28.dwDataOffset = MVar1;
        local_28.dwFlags = MVar1;
        local_28.ckid = mmioStringToFOURCCA("fmt ", 0);
        MVar1 = mmioDescend(hmmio, &local_28, &local_14, 0x10);
        if (MVar1 != 0) {
            iVar5 = 2;
        } else {
            local_38 = MVar1;
            local_34 = MVar1;
            local_30 = MVar1;
            local_2c = MVar1;
            LVar2 = mmioRead(hmmio, (HPSTR)&local_38, 0x10);
            if (LVar2 == -1 || local_34 == 0) {
                iVar5 = 2;
            } else {
                mmioSeek(hmmio, 0, 0);
                mmioDescend(hmmio, &local_14, (MMCKINFO*)0x0, 0x20);
                local_28.ckid = 0;
                local_28.cksize = 0;
                local_28.fccType = 0;
                local_28.dwDataOffset = 0;
                local_28.dwFlags = 0;
                local_28.ckid = mmioStringToFOURCCA("cue ", 0);
                MVar1 = mmioDescend(hmmio, &local_28, &local_14, 0x10);
                if (MVar1 != 0) {
                    iVar5 = 2;
                } else {
                    LVar2 = mmioRead(hmmio, (HPSTR)s, 4);
                    if (LVar2 == -1) {
                        iVar5 = 2;
                    } else {
                        uVar3 = (uint32_t)(uintptr_t)thunk_FUN_00533c78((size_t)(*s * 0x18));
                        iVar4 = 0;
                        s[1] = uVar3;
                        uint32_t i = 0;
                        do {
                            if (*s <= i) break;
                            LVar2 = mmioRead(hmmio, (HPSTR)(s[1] + iVar4), 0x18);
                            if (LVar2 == -1) {
                                iVar5 = 2;
                            } else {
                                *(uint32_t*)(iVar4 + s[1] + 4) =
                                    (uint32_t)(*(int32_t*)(iVar4 + s[1] + 0x14) * 1000) / (uint32_t)local_34;
                            }
                            i = i + 1;
                            iVar4 = iVar4 + 0x18;
                        } while (iVar5 == 0);
                    }
                }
            }
        }
    }
    mmioClose(hmmio, 0);
    if (iVar5 == 0) {
        qsort((void*)(uintptr_t)s[1], *s, 0x18,
              (int (__cdecl*)(const void*, const void*))&LAB_004fb620);
        return 0;
    }
LAB_004fb5d0:
    if ((void*)s[1] != (void*)0x0) {
        operator_delete__((void*)s[1]);
        s[1] = 0;
    }
    *s = 0;
    return iVar5;
}

// 0x4fb640 — observed shape: two-stage container initialisation; self[0] vtable
// slots are stamped twice (derived vtable PTR_FUN_007109ec, then PTR_FUN_007109ec
// base fields) and self[1] slots are zero-filled.
void FUN_004fb640(void* self, int in_EAX) {
    uint32_t* s = (uint32_t*)self;
    uint32_t* puVar1;

    s[1] = (uint32_t)in_EAX;
    s[0] = (uint32_t)(uintptr_t)&PTR_FUN_007109d0;
    s[3] = 0;
    puVar1 = (uint32_t*)thunk_FUN_00533c78((size_t)(in_EAX << 2));
    s[2] = (uint32_t)(uintptr_t)puVar1;
    for (uint32_t uVar2 = s[1] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    // The listing emits a second zero-fill loop whose counter starts at 0, so it
    // never executes; no bytes are written by it.
    s[0] = (uint32_t)(uintptr_t)&PTR_FUN_007109ec;
    s[7] = 0;
    s[5] = 0;
    s[6] = 0;
    s[4] = (uint32_t)(uintptr_t)&PTR_FUN_00710a14;
}

// 0x4fb6a0 — observed shape: table teardown. Walks the bucket array
// (param_1[2], param_1[1] buckets), frees each node's payload at node[2] after
// re-hashing node[1] to find the successor, then drains the node pool at
// param_1[5] through the vtable at param_1[4].
void FUN_004fb6a0(int* param_1, char param_2) {
    void* pvVar1;
    uint32_t uVar3;
    int iVar4;
    int* piVar5;
    uint32_t* puVar6;
    int* piVar7;

    if (param_2 != '\0') {
        uVar3 = 0;
        if (param_1[1] != 0) {
            piVar5 = (int*)param_1[2];
            do {
                if (*piVar5 != 0) {
                    piVar5 = ((int*)param_1[2])[uVar3];  // listed as a re-read of the slot
                    goto joined_r0x004fb6d3;
                }
                uVar3 = uVar3 + 1;
                piVar5 = piVar5 + 1;
            } while (uVar3 < (uint32_t)param_1[1]);
        }
        piVar5 = (int*)0x0;
    joined_r0x004fb6d3:
        while (piVar5 != (int*)0x0) {
            piVar7 = (int*)*piVar5;
            pvVar1 = (void*)piVar5[2];
            if (piVar7 == (int*)0x0) {
                typedef int (__cdecl* HashFn)(int);
                uint32_t vt = (uint32_t)*param_1;
                iVar4 = ((HashFn)(*(void**)(vt + 4)))(piVar5[1]);
                uVar3 = (uint32_t)(iVar4 + 1);
                if (uVar3 < (uint32_t)param_1[1]) {
                    puVar6 = (uint32_t*)(param_1[2] + (int)uVar3 * 4);
                    do {
                        piVar7 = (int*)*puVar6;
                        if (piVar7 != (int*)0x0) goto LAB_004fb711;
                        uVar3 = uVar3 + 1;
                        puVar6 = puVar6 + 1;
                    } while (uVar3 < (uint32_t)param_1[1]);
                }
                piVar7 = (int*)0x0;
            }
        LAB_004fb711:
            piVar5 = piVar7;
            if (pvVar1 != (void*)0x0) {
                FUN_004fbfd0();
                operator_delete(pvVar1);
            }
        }
    }
    FUN_004e6420();
    if (param_2 != '\0') {
        iVar4 = param_1[5];
        // The listing never reassigns iVar4 here; FUN_00517f90 supplies the next
        // node from the container behind param_1[5] through its implicit receiver.
        while (iVar4 != 0) {
            piVar5 = (int*)FUN_00517f90();
            if (piVar5 != (int*)0x0) {
                uint32_t* pobj = (uint32_t*)(*piVar5 - 8);
                if ((pobj != (uint32_t*)0x0) && (pobj != (uint32_t*)&DAT_008cacc8)) {
                    operator_delete__(pobj);
                }
                *piVar5 = (int)(intptr_t)&DAT_008cacd0;
                operator_delete(piVar5);
            }
        }
    }
    puVar6 = (uint32_t*)(uintptr_t)param_1[5];
    while (puVar6 != (uint32_t*)0x0) {
        uint32_t* puVar2 = (uint32_t*)*puVar6;
        (*(void (__cdecl*)(uint32_t*))(param_1[4] + 8))(puVar6);
        puVar6 = puVar2;
    }
    param_1[7] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
}

// 0x4fb7c0 — observed shape: normalises the shared scratch string in
// DAT_008cacd0 to backslashes, strips the last path component (or the leading
// ".\\"), lowercases it and returns a copy built with FUN_0051bfc0.
char* FUN_004fb7c0(void) {
    char cVar1;
    uint32_t* puVar2;
    char* pcVar3;
    char* pcVar4;
    int iVar5;
    char* local_c;
    uint8_t* local_8;
    uint8_t* local_4;

    local_c = (char*)&DAT_008cacd0;
    local_8 = (uint8_t*)0x0;
    local_4 = (uint8_t*)0x0;
    FUN_00412f10();
    pcVar4 = local_c;
    iVar5 = *(int*)(local_c + -4);
    for (pcVar3 = local_c; pcVar3 < local_c + iVar5; pcVar3 = pcVar3 + 1) {
        if (*pcVar3 == '/') {
            *pcVar3 = '\\';
        }
    }
    if (DAT_008cacf8 == '\0') {
        iVar5 = *(int*)(local_c + -4) + -1;
        if ((*(int*)(local_c + -4) <= iVar5) || (iVar5 < 0)) goto LAB_004fb8f6;
        cVar1 = local_c[iVar5];
        local_c[iVar5] = '\0';
        pcVar3 = strrchr(local_c, 0x5c);
        pcVar4[iVar5] = cVar1;
        if ((pcVar3 == (char*)0x0) || ((int)((intptr_t)pcVar3 - (intptr_t)pcVar4) < 0)) {
            goto LAB_004fb8f6;
        }
        FUN_004f1840();
        FUN_00412ec0();
        local_4 = local_8;  // register-returned buffer of the preceding builder call
    } else {
        if ((*local_c != '.') || (local_c[1] != '\\')) goto LAB_004fb8f6;
        local_8 = (uint8_t*)&DAT_008cacd0;
        FUN_004f30d0(2);
        FUN_00412df0();
        puVar2 = (uint32_t*)(local_8 + -8);
        if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)&DAT_008cacc8)) {
            operator_delete__(puVar2);
        }
        FUN_00412ec0();
    }
    puVar2 = (uint32_t*)(local_4 + -8);
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)&DAT_008cacc8)) {
        operator_delete__(puVar2);
    }
    pcVar4 = local_c;
LAB_004fb8f6:
    _strlwr(pcVar4);
    iVar5 = *(int*)(pcVar4 + -4);
    if (iVar5 != 0) {
        do {
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);  // dead countdown emitted by the decompiler
    }
    local_c = (char*)0x0;
    FUN_0051bfc0(&local_c);
    pcVar4 = pcVar4 + -8;
    if ((pcVar4 != (char*)0x0) && (pcVar4 != (char*)&DAT_008cacc8)) {
        operator_delete__(pcVar4);
    }
    return local_c;
}

// 0x4fb970 — observed shape: recursive directory walk. Converts the scratch
// pattern buffer to backslashes, enumerates entries with FindFirstFileA, packs
// every regular file into a container node through FUN_004fbe90/FUN_004fbd10,
// and recurses into each subdirectory (skipping "." and "..").
int FUN_004fb970(const char* param_1, uint32_t param_2, const char* param_3, void* self) {
    char cVar2;
    char* pcVar3;
    int iVar4;
    int* puVar5;
    HANDLE hFindFile;
    CHAR* pCVar6;
    uint32_t* puVar7;
    uint32_t uVar8;
    BOOL BVar9;
    char* pcVar10;
    CHAR* pCVar11;
    bool bVar12;
    int local_194;
    uint8_t local_17c[4];
    uint8_t local_178[56];
    _WIN32_FIND_DATAA local_140;

    bool bVar1 = false;
    local_194 = 0;
    if ((param_1 == (char*)0x0) || (*param_1 == '\0')) {
        return 0;
    }
    FUN_00412f10();
    pcVar3 = (char*)&DAT_008cacd0 + DAT_008caccc;
    for (pcVar10 = (char*)&DAT_008cacd0; pcVar10 < pcVar3; pcVar10 = pcVar10 + 1) {
        if (*pcVar10 == '/') {
            *pcVar10 = '\\';
        }
    }
    if (*(char*)((intptr_t)&DAT_008caccc + DAT_008caccc + 3) != '\\') {
        FUN_00412e50(&DAT_0070c164);
    }
    if ((param_3 != (char*)0x0) && (*param_3 != '\0')) {
        FUN_00412f10();
        FUN_004f20a0();
    }
    iVar4 = FUN_00533c78(4);
    if (iVar4 == 0) {
        puVar5 = (int*)0x0;
    } else {
        // FUN_00412df0 is declared void; the listing uses its returned buffer
        puVar5 = (int*)(uintptr_t)((void* (*)())FUN_00412df0)();
    }
    FUN_004fbf80(puVar5);
    FUN_00412e50(&DAT_00710a2c);
    hFindFile = FindFirstFileA((LPCSTR)&DAT_008cacd0, &local_140);
    if (hFindFile == (HANDLE)0xffffffff) {
        return 0;
    }
    do {
        if (((uint8_t)local_140.dwFileAttributes & 6) == 0) {
            if (((uint8_t)local_140.dwFileAttributes & 0x10) == 0) {
                if ((char)param_2 != '\0') {
                    pCVar11 = local_140.cFileName;
                    do {
                        pCVar6 = pCVar11;
                        pCVar11 = pCVar6 + 1;
                    } while (*pCVar6 != '\0');
                    iVar4 = _strnicmp(pCVar6 + -4, ".FPK", 4);
                    if (iVar4 == 0) {
                        FUN_004fbf10();
                        iVar4 = FUN_004fdf40(local_178, self, 0);
                        local_194 = local_194 + iVar4;
                        FUN_004fe030();
                        FUN_004fbec0();
                    }
                }
                if (DAT_008cacf8 == '\0') {
                    iVar4 = FUN_00533c78(0x28);
                    if (iVar4 == 0) {
                        uVar8 = 0;
                    } else {
                        uVar8 = (uint32_t)(uintptr_t)FUN_004fbe90(puVar5, local_140.cFileName, 0);
                    }
                } else {
                    if ((DAT_008caccc != 0) &&
                        (iVar4 = _strnicmp((char*)(uintptr_t)*puVar5, (char*)&DAT_008cacd0,
                                           DAT_008caccc), iVar4 == 0)) {
                        FUN_004f1d50();
                    }
                    iVar4 = FUN_00533c78(0x28);
                    if (iVar4 == 0) {
                        uVar8 = 0;
                    } else {
                        bVar1 = true;
                        puVar7 = (uint32_t*)FUN_00412a60(local_17c, local_140.cFileName);
                        uVar8 = (uint32_t)(uintptr_t)FUN_004fbe90(
                            0, (const char*)(uintptr_t)*puVar7, (void*)&DAT_008cacd0);
                    }
                    if (bVar1) {
                        bVar1 = false;
                        FUN_00412fb0();
                    }
                }
                cVar2 = FUN_004fbd10((void*)(uintptr_t)uVar8, 0);
                if (cVar2 != '\0') {
                    local_194 = local_194 + 1;
                }
            } else {
                // subdirectory: literal "." / ".." comparisons emitted by the listing
                iVar4 = 2;
                bVar12 = true;
                pCVar11 = local_140.cFileName;
                pcVar10 = (char*)".";
                do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar12 = *pCVar11 == *pcVar10;
                    pCVar11 = pCVar11 + 1;
                    pcVar10 = pcVar10 + 1;
                } while (bVar12);
                if (!bVar12) {
                    iVar4 = 3;
                    bVar12 = true;
                    pCVar11 = local_140.cFileName;
                    pcVar10 = (char*)"..";
                    do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar12 = *pCVar11 == *pcVar10;
                        pCVar11 = pCVar11 + 1;
                        pcVar10 = pcVar10 + 1;
                    } while (bVar12);
                    if (!bVar12) {
                        FUN_00476050();
                        FUN_00412ec0();
                        FUN_00412fb0();
                        FUN_00412e50(local_140.cFileName);
                        iVar4 = FUN_004fb970((char*)&DAT_008cacd0, param_2,
                                             (char*)&DAT_008cacd0, self);
                        local_194 = local_194 + iVar4;
                    }
                }
            }
        }
        BVar9 = FindNextFileA(hFindFile, &local_140);
        if (BVar9 == 0) {
            FindClose(hFindFile);
            return local_194;
        }
    } while (true);
}

// 0x4fbd10 — observed shape: accepts or rejects a built file record.
// self+0x14 holds a list whose nodes compare on node[2]; a second record is
// taken from the built path, kept only when newer (CompareFileTime == 1),
// and the loser is destroyed.
int FUN_004fbd10_recon(void* self, FILETIME* param_1, char param_2) {
    uint8_t* s = (uint8_t*)self;
    DWORD DVar1;
    uint32_t* puVar2;
    FILETIME* lpFileTime2;
    uint32_t* puVar3;
    char cVar4;
    LONG LVar5;
    FILETIME* lpFileTime1 = param_1;

    if (param_1[3].dwLowDateTime == 0) {
        FUN_004fbfd0();
        operator_delete(lpFileTime1);
        return 0;
    }
    if ((param_2 != '\0') && (DVar1 = param_1[2].dwLowDateTime, DVar1 != 0)) {
        puVar3 = *(uint32_t**)(s + 0x14);
        for (;;) {
            puVar2 = puVar3;
            if (puVar2 == (uint32_t*)0x0) {
                FUN_004fbf80((int*)(uintptr_t)DVar1);
                break;
            }
            puVar3 = (uint32_t*)*puVar2;
            if (DVar1 == puVar2[2]) break;
        }
    }
    cVar4 = FUN_0051bfc0((char**)&param_1);
    lpFileTime2 = param_1;
    if (cVar4 == '\0') {
        FUN_00524e90(lpFileTime1);
        return 1;
    }
    cVar4 = FUN_004b0fa0();
    if ((cVar4 != '\0') &&
        ((param_2 != '\0') ||
         (LVar5 = CompareFileTime(lpFileTime1, lpFileTime2), LVar5 == 1))) {
        FUN_00524e90(lpFileTime1);
        lpFileTime1 = lpFileTime2;
    }
    if (lpFileTime1 != (FILETIME*)0x0) {
        FUN_004fbfd0();
        operator_delete(lpFileTime1);
    }
    return 0;
}

// 0x4fbe10 — observed shape: scalar deleting destructor for PTR_FUN_007109d0;
// resets the vtable, destroys the base, frees self[2], then optionally self.
void FUN_004fbe10(void* self, uint8_t param_1) {
    uint32_t* s = (uint32_t*)self;

    s[0] = (uint32_t)(uintptr_t)&PTR_FUN_007109d0;
    FUN_004e6420();
    operator_delete__((void*)(uintptr_t)s[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(s);
    }
}

// 0x4fbe50 — observed shape: deleting destructor chaining PTR_FUN_007109ec over
// PTR_FUN_007109d0; both bases are torn down before self[2] is freed.
void FUN_004fbe50(void* self, uint8_t param_1) {
    uint32_t* s = (uint32_t*)self;

    s[0] = (uint32_t)(uintptr_t)&PTR_FUN_007109ec;
    FUN_004e6420();
    s[0] = (uint32_t)(uintptr_t)&PTR_FUN_007109d0;
    FUN_004e6420();
    operator_delete__((void*)(uintptr_t)s[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(s);
    }
}

// 0x4fbe90 — observed shape: constructor body. Clears the two owned strings at
// self+8 and self+0xc, zeroes the field at self+0x24 and forwards the live
// ECX/EDX register inputs plus param_3 to FUN_004fe2d0. The listing's stack
// param_1/param_2 are never read, so they are not carried into this candidate.
void FUN_004fbe90_recon(void* self, void* in_ECX, void* in_EDX, void* param_3) {
    uint8_t* s = (uint8_t*)self;

    *(void**)(s + 8) = (void*)&DAT_008cacd0;
    *(void**)(s + 0xc) = (void*)&DAT_008cacd0;
    *(uint32_t*)(s + 0x24) = 0;
    FUN_004fe2d0(in_EDX, in_ECX, param_3);
}

// 0x4fbec0 — observed shape: releases the file-container base: resets the
// vtable at self[0], closes the mutex/handle at self[0xc], destroys the base
// object, frees the owned string at self[7] and resets it to the empty sentinel.
void FUN_004fbec0_recon(void* self) {
    uint32_t* s = (uint32_t*)self;
    uint32_t* puVar1;

    FUN_004fe030();
    s[0xb] = (uint32_t)(uintptr_t)&PTR_FUN_007109b0;
    CloseHandle((HANDLE)(uintptr_t)s[0xc]);
    s[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f5864;
    FUN_004f0dc0();
    puVar1 = (uint32_t*)(s[7] + -8);
    if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)&DAT_008cacc8)) {
        operator_delete__(puVar1);
    }
    s[7] = (uint32_t)(uintptr_t)&DAT_008cacd0;
}

// 0x4fbf10 — observed shape: constructs the file-container base. Installs
// PTR_FUN_006f5864 / PTR_FUN_007109b0, clears slots 1..6 and 0xc, creates the
// owning mutex and throws (0xffffffff, DAT_007149ac) when creation fails;
// finally sets self[10] = 0 and self[0xd] = 2.
void FUN_004fbf10_recon(void* self) {
    uint32_t* s = (uint32_t*)self;
    HANDLE pvVar1;
    uint32_t local_4;

    s[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f5864;
    s[7] = (uint32_t)(uintptr_t)&DAT_008cacd0;
    s[1] = 0;
    s[2] = 0;
    s[3] = 0;
    s[4] = 0;
    s[5] = 0;
    s[6] = 0;
    s[0xb] = (uint32_t)(uintptr_t)&PTR_FUN_007109b0;
    s[0xc] = 0;
    pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
    s[0xc] = (uint32_t)(uintptr_t)pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
        local_4 = 0xffffffff;
        _CxxThrowException(&local_4, (ThrowInfo*)&DAT_007149ac);
    }
    s[10] = 0;
    s[0xd] = 2;
}

// 0x4fbf80 — observed shape: appends one node to the intrusive list at
// self+0x14..0x18. The node comes from the allocator hooked at
// *(*(self+0x10)+4); node[2] = param_1, node[1] = old tail, node[0] = 0.
void FUN_004fbf80_recon(void* self, void* param_1) {
    uint8_t* s = (uint8_t*)self;
    typedef uint32_t* (*AllocFn)();
    uint32_t* puVar1;

    AllocFn fn = (AllocFn)(*(void**)(*(uint8_t**)(s + 0x10) + 4));
    puVar1 = fn();
    puVar1[2] = (uint32_t)(uintptr_t)param_1;
    puVar1[0] = 0;
    puVar1[1] = *(uint32_t*)(s + 0x18);
    if (*(void**)(s + 0x18) == (void*)0x0) {
        *(uint32_t**)(s + 0x14) = puVar1;
        *(uint32_t**)(s + 0x18) = puVar1;
        *(int*)(s + 0x1c) = *(int*)(s + 0x1c) + 1;
        return;
    }
    **(uint32_t**)(s + 0x18) = (uint32_t)(uintptr_t)puVar1;
    *(uint32_t**)(s + 0x18) = puVar1;
    *(int*)(s + 0x1c) = *(int*)(s + 0x1c) + 1;
}

// 0x4fbfd0 — observed shape: clears the three owned strings of the container.
// The string at self+0x10 is released only when its last character is not a
// backslash (i.e. it is not a directory prefix); self+0xc and self+8 are
// released unconditionally and reset to DAT_008cacd0.
void FUN_004fbfd0_recon(void* self) {
    uint8_t* s = (uint8_t*)self;
    uint32_t* puVar3;
    uint32_t** piVar1 = *(uint32_t***)(s + 0x10);

    if (piVar1 != (uint32_t**)0x0) {
        uint32_t iVar2 = *piVar1;
        int32_t len = *(int32_t*)(iVar2 - 4);
        if (*(char*)(len - 1 + iVar2) != '\\') {
            puVar3 = (uint32_t*)(iVar2 - 8);
            if ((puVar3 != (uint32_t*)0x0) && (puVar3 != (uint32_t*)&DAT_008cacc8)) {
                operator_delete__(puVar3);
            }
            *piVar1 = (uint32_t)(uintptr_t)&DAT_008cacd0;
            operator_delete(piVar1);
            *(uint32_t*)(s + 0x10) = 0;
        }
    }
    puVar3 = (uint32_t*)(*(uint32_t*)(s + 0xc) + -8);
    if ((puVar3 != (uint32_t*)0x0) && (puVar3 != (uint32_t*)&DAT_008cacc8)) {
        operator_delete__(puVar3);
    }
    *(void**)(s + 0xc) = (void*)&DAT_008cacd0;
    puVar3 = (uint32_t*)(*(uint32_t*)(s + 8) + -8);
    if ((puVar3 != (uint32_t*)0x0) && (puVar3 != (uint32_t*)&DAT_008cacc8)) {
        operator_delete__(puVar3);
    }
    *(void**)(s + 8) = (void*)&DAT_008cacd0;
}

// 0x4fc050 — observed shape: deleting destructor wrapper for FUN_004fc070;
// forwards to the real teardown and frees self when the low bit of param_1 is set.
void FUN_004fc050(void* self, uint8_t param_1) {
    FUN_004fc070_recon(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4fc070 — observed shape: tears down the intrusive list at self+4 by
// calling the vtable slot +8 on every node, clears count/head/tail, then
// stamps the base vtable PTR_LAB_00710a08.
void FUN_004fc070_recon(void* self) {
    uint32_t* s = (uint32_t*)self;
    uint32_t* puVar1;
    uint32_t* puVar2;

    s[0] = (uint32_t)(uintptr_t)&PTR_FUN_00710a14;
    puVar2 = (uint32_t*)s[1];
    while (puVar2 != (uint32_t*)0x0) {
        puVar1 = (uint32_t*)*puVar2;
        (*(void (__cdecl*)(uint32_t*))(s[0] + 8))(puVar2);
        puVar2 = puVar1;
    }
    s[3] = 0;
    s[1] = 0;
    s[2] = 0;
    s[0] = (uint32_t)(uintptr_t)&PTR_LAB_00710a08;
}
