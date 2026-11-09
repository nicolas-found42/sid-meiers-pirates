// Reconstruction batch mass_0074 — Sid Meier's Pirates! (2004), PE32 i386.
// Each definition corresponds to the Ghidra pseudocode corpus file at the
// address in its // 0xADDR comment. Receiver registers are explicit
// void* self parameters.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <windows.h>

extern uint32_t DAT_007264dc;
extern void* PTR_DAT_007264e0[];
extern uint32_t DAT_008cace8;
extern uint32_t DAT_008cacec;
extern uint32_t DAT_008cacf0;
extern void* PTR_FUN_007264d4;
extern void* PTR_FUN_007108ac;
extern void* PTR_FUN_007108b0;
extern void* PTR_FUN_006f5814;
extern char DAT_008cacd0[];
extern uint32_t DAT_008caccc;
extern uint32_t DAT_008cacc8;
extern char DAT_00710980[];
extern char DAT_007108c8[];
extern char DAT_0070e7ac[];

extern void FUN_004f8bd0(const char* fmt, ...);
extern void FUN_004f8b80(const char* fmt, ...);
extern void FUN_004f8cf0();
extern int  FUN_004f8e40_ver(char* self, const char* fmt, va_list ap);
extern uint32_t FUN_004f8e40(const char* fmt, ...);
extern void FUN_004fa610();
extern void operator_delete(void* pv);
extern void operator_delete__(void* pv);
extern void FUN_004f4ed0();
extern void FUN_00412f10();
extern void FUN_00476050();
extern void FUN_00412ec0();
extern void FUN_00412e50(const void* p);
extern void FUN_004fa570();
extern void FUN_004fa4d0();
extern void FUN_00412970();
extern void FUN_004f0dc0();
extern void FUN_004fa440(void* self);
extern int  FUN_004f4b20(void* self, int a, int b, int c);
extern void FUN_004f8110(void** p);
extern void FUN_004f8250(void** p);
extern void FUN_004f8460();
extern void FUN_004f32b0();
extern void FUN_004f11a0(void* p, int v);
extern void FUN_004f1220(int a, int b);
extern void FUN_004f85e0(int* p, wchar_t** pp);
extern void FUN_004f3ee0();
extern void FUN_004f2600(const void* p, ...);
extern void FUN_004f3350();
extern void FUN_004f84d0(void* p);
extern void FUN_004f1c20();
extern void FUN_004f1b10(void* p);
extern void FUN_004f1c80();
extern void FUN_004f1840();
extern void FUN_004f5720();
extern void FUN_004f5670();
extern void* FUN_00533c78(size_t n);
extern void* FUN_00533c78_();
extern uint32_t FUN_005f0ddc();
extern void FUN_00412b40();
extern void FUN_00412f90();
extern void FUN_004f4de0();
extern void FUN_004f3540(const void* p, const void* q);
extern void FUN_004f3ca0(const void* p);
extern void FUN_004f3270();
extern void FUN_004f87c0();

// 0x4f8dc0 — observed shape: scan remark-group list for EDI receiver, append if absent and count < 0x20, clear 0x8cace8/0x8cacec, log via 0x4f8bd0; returns receiver.
void* FUN_004f8dc0(void* self) {
    uint32_t uVar1 = 0;
    if (DAT_007264dc != 0) {
        do {
            if (PTR_DAT_007264e0[uVar1] == self) {
                if (uVar1 != 0) return nullptr;
                goto LAB_004f8e09;
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < DAT_007264dc);
    }
    if (DAT_007264dc < 0x20) {
        PTR_DAT_007264e0[DAT_007264dc] = self;
        DAT_007264dc = DAT_007264dc + 1;
    } else {
        FUN_004f8bd0("Remark Group List *** FULL ***");
    }
LAB_004f8e09:
    DAT_008cace8 = 0;
    DAT_008cacec = 0;
    GetCommandLineA();
    FUN_004f8cf0();
    FUN_004f8bd0("Adding remark group #%d - \"%s\"", uVar1);
    return self;
}

// 0x4f8e40 — observed shape: variadic remark-group emit; looks up EAX name in group list, checks verbosity flag & 3, formats "Name: msg\n" into 0x400 local, dispatches via function pointer at 0x7264d4; returns 0/1.
uint32_t FUN_004f8e40(void* self, const char* fmt, va_list ap) {
    char local_400[1020];
    uint32_t uVar2 = 0;
    const char* in_EAX = (const char*)self;
    int unaff_EBX = *(int*)((char*)self + 4); // low bits carry verbosity in listing; preserved as observed
    void* unaff_EDI = nullptr; // format args source in original
    if (DAT_007264dc != 0) {
        do {
            if (PTR_DAT_007264e0[uVar2] == self) goto LAB_004f8e73;
            uVar2 = uVar2 + 1;
        } while (uVar2 < DAT_007264dc);
    }
    FUN_004f8b80("Remark Group \"%s\" *** NOT FOUND ***\n");
LAB_004f8e73:
    uVar2 = (uint32_t)(uVar2 & 3);
    if ((int)uVar2 < unaff_EBX) return 0;
    if (unaff_EDI != nullptr) {
        strncpy(local_400, in_EAX, 0x40);
        char* pcVar3 = local_400;
        char cVar1;
        do { cVar1 = *pcVar3; pcVar3 = pcVar3 + 1; } while (cVar1 != '\0');
        int tail = (int)(pcVar3 - local_400) - 1;
        local_400[tail] = ':';
        local_400[tail + 1] = ' ';
        char* dst = local_400 + tail + 2;
        int n = _vsnprintf(dst, (size_t)((local_400 + sizeof(local_400)) - dst), (const char*)unaff_EDI, ap);
        if (n < 0) n = 0;
        dst[n] = '\n';
        dst[n + 1] = '\0';
        ((void(*)(char*))PTR_FUN_007264d4)(local_400);
    }
    return 1;
}

// 0x4f8f10 — observed shape: remark gate; returns 0 if 0x8cacf0==0 or (EAX non-null and both 0x8cace8/0x8cacec zero), else forwards to 0x4f8e40.
uint32_t FUN_004f8f10(void* self, const char* fmt, ...) {
    int in_EAX = (int)self;
    if ((DAT_008cacf0 == 0) || ((in_EAX != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
        return 0;
    }
    va_list ap;
    va_start(ap, fmt);
    uint32_t r = FUN_004f8e40_ver(self, fmt, ap);
    va_end(ap);
    return r;
}

// 0x4f8f50 — observed shape: container destructor; drains array at self[1] with count at self[3], decrements self[4] per freed element via 0x4fa610 + operator_delete, resets vtable to 0x7108ac.
void FUN_004f8f50(void* self) {
    uint32_t* unaff_EDI = (uint32_t*)self;
    int iVar2 = (int)unaff_EDI[3];
    while (iVar2 != 0) {
        if (unaff_EDI[3] != 0) {
            iVar2 = (int)unaff_EDI[3] - 1;
            unaff_EDI[3] = (uint32_t)iVar2;
            void* pvVar1 = *(void**)((char*)unaff_EDI[1] + iVar2 * 4);
            *(void**)((char*)unaff_EDI[1] + iVar2 * 4) = nullptr;
            if (pvVar1 != nullptr) {
                unaff_EDI[4] = unaff_EDI[4] - 1;
                FUN_004fa610();
                operator_delete(pvVar1);
            }
        }
        iVar2 = (int)unaff_EDI[3];
    }
    *unaff_EDI = (uint32_t)PTR_FUN_007108ac;
    operator_delete__((void*)unaff_EDI[1]);
}

// 0x4f8fa0 — observed shape: top-level parse entry; gated by FUN_004f4ed0, strips last char of DAT_008cacd0 string, finds '.' extension, runs FUN_004f9230 loop; returns low byte in stack slot.
uint8_t FUN_004f8fa0(void* self, int param_1) {
    uint8_t result = 0;
    char cVar2 = *((char*)&FUN_004f4ed0);
    (void)cVar2;
    FUN_00412f10();
    uint32_t len = DAT_008caccc;
    if ((int)(len - 1) < (int)len && (int)(len - 1) >= 0) {
        char ch = *(char*)((char*)&DAT_008caccc + len + 3);
        result = (uint8_t)ch;
        *(char*)((char*)&DAT_008caccc + len + 3) = 0;
        char* pcVar4 = strrchr(&DAT_008cacd0[0], 0x2e);
        *(char*)((char*)&DAT_008caccc + len + 3) = (char)ch;
        if (pcVar4 != nullptr && (int)(pcVar4 - &DAT_008cacd0[0]) >= 0) {
            FUN_00476050();
            FUN_00412ec0();
        }
    }
    FUN_00412e50(&DAT_00710980);
    FUN_004fa570();
    {
        uint8_t b = (uint8_t)FUN_004f9230(self, param_1);
        result = b;
    }
    return result;
}

extern char DAT_00710530[];
extern char DAT_0071055c[];
extern char DAT_00710808[];
extern char DAT_00710810[];
extern char DAT_007108c0[];

// 0x4f9230 — observed shape: record-stream reader; opens the store via 0x4f4b20 with mode 1, walks records through the reader vtable (slots +0x10/+0x1c), allocates 0x1c section records and 0x10 key/value records with 0x533c78, inserts them through 0x4f5720, returns the status byte written as CONCAT13(1,...).
uint8_t FUN_004f9230_recon(void* self, int param_1) {
    char* pcVar10 = DAT_008cacd0;
    char* local_5c = DAT_008cacd0;
    char* local_28 = DAT_008cacd0;
    uint32_t local_40 = 0;
    uint32_t local_3c = 0;
    uint32_t local_38 = 0;
    uint32_t local_34 = 0;
    uint32_t local_30 = 0;
    uint32_t local_2c = 0;
    int local_1c = 0;
    int local_18 = 0;
    void** local_44 = (void**)&PTR_FUN_006f5814;
    char* local_10 = DAT_008cacd0;
    char* local_c = DAT_008cacd0;
    uint32_t local_14 = 0;
    uint32_t local_8 = 0;
    intptr_t local_4 = 0;
    int local_24 = 0;
    int local_4c[2] = {0, 0};
    wchar_t* uStack_60 = nullptr;
    char* local_54 = DAT_008cacd0;
    char* local_50 = DAT_008cacd0;
    char* local_58 = DAT_008cacd0;
    char* unaff_EBX = pcVar10;
    uint8_t result = 0;

    uStack_60 = (wchar_t*)(uintptr_t)uStack_60;
    *(uint32_t*)((char*)(uintptr_t)param_1 + 0x18) = 0;
    int iVar2 = FUN_004f4b20(self, 1, 0, 0);
    if (iVar2 == 0) {
        FUN_004f8110(local_44);
        if (local_18 == 0) {
            local_4 = ((intptr_t(*)(int, int))FUN_004f1220)(0, 1);
        } else {
            local_4 = *(int*)(local_18 + 0x14);
        }
        if (local_24 == 1) {
            FUN_004f8250(local_44);
        }
        uint32_t uVar3 = ((uint32_t(*)(int, int))local_44[7])(0, 1);
        uint32_t uVar4 = ((uint32_t(*)(void))*(void**)(local_4c[0] + 0x10))();
        if (uVar3 < uVar4) {
            do {
                if (local_1c == 1) {
                    uStack_60 = (wchar_t*)DAT_008cacd0;
                    FUN_004f85e0(local_4c, &uStack_60);
                    wchar_t* pwVar11 = uStack_60;
                    if (uStack_60 != nullptr) {
                        int sVar5 = (int)wcslen(uStack_60);
                        if (sVar5 > -1) {
                            FUN_004f3ee0();
                            local_54 = DAT_008cacd0;
                            FUN_004f2600(DAT_00710530, local_5c);
                            char* pcVar9 = local_54;
                            int len = *(int*)(local_54 - 4);
                            if (len > -1 && local_54 != pcVar10) {
                                if (len == 0) {
                                    FUN_00412f90();
                                    pcVar10 = unaff_EBX;
                                } else {
                                    FUN_004f3350();
                                    pcVar10 = unaff_EBX;
                                    memmove(unaff_EBX, pcVar9, (size_t)len);
                                    unaff_EBX[*(int*)(unaff_EBX - 4)] = '\0';
                                    pwVar11 = uStack_60;
                                }
                                unaff_EBX = pcVar10;
                            }
                            char* pcVar9b = pcVar9 - 8;
                            if (pcVar9b != nullptr && pcVar9b != (char*)&DAT_008cacc8) {
                                operator_delete__(pcVar9b);
                            }
                            void* puVar6 = local_5c - 8;
                            if (puVar6 != nullptr && puVar6 != (void*)&DAT_008cacc8) {
                                operator_delete__(puVar6);
                            }
                            local_5c = DAT_008cacd0;
                        }
                        wchar_t* wp = pwVar11 - 4;
                        if (wp != nullptr && wp != (wchar_t*)&DAT_008cacc8) {
                            operator_delete__(wp);
                        }
                    }
                } else {
                    pcVar10 = unaff_EBX;
                    FUN_004f84d0((char*)local_4c - 24);
                    unaff_EBX = pcVar10;
                }
                FUN_004f1c20();
                FUN_004f1b10((char*)local_4c - 24);
                iVar2 = *(int*)(pcVar10 - 4);
                if (iVar2 != 0 && *pcVar10 != ';') {
                    if (*pcVar10 == '[' && pcVar10[iVar2 - 1] == ']') {
                        char* pcVar9 = (char*)FUN_00533c78(0x1c);
                        if (pcVar9 == nullptr) {
                            pcVar9 = nullptr;
                        } else {
                            *(char**)pcVar9 = DAT_008cacd0;
                            pcVar9[0xc] = '\0';
                            pcVar9[0xd] = '\0';
                            pcVar9[0xe] = '\0';
                            pcVar9[0xf] = '\0';
                            pcVar9[0x18] = '\x01';
                            pcVar9[0x19] = '\0';
                            pcVar9[0x1a] = '\0';
                            pcVar9[0x1b] = '\0';
                            pcVar9[0x10] = '\0';
                            pcVar9[0x11] = '\0';
                            pcVar9[0x12] = '\0';
                            pcVar9[0x13] = '\0';
                            pcVar9[0x14] = '\0';
                            pcVar9[0x15] = '\0';
                            pcVar9[0x16] = '\0';
                            pcVar9[0x17] = '\0';
                            pcVar9[8] = '\0';
                            pcVar9[9] = '\0';
                            pcVar9[10] = '\0';
                            pcVar9[0xb] = '\0';
                            *(void**)(pcVar9 + 4) = (void*)&PTR_FUN_007108b0;
                        }
                        local_54 = pcVar9;
                        FUN_004f1c80();
                        if (*(int*)(pcVar10 - 4) != 0) {
                            char* pcVar8 = nullptr;
                            char* pcVar1 = pcVar10 + *(int*)(pcVar10 - 4) - 1;
                            if (pcVar10 <= pcVar10 + *(int*)(pcVar10 - 4) - 1) {
                                do {
                                    char* pcVar7 = pcVar1;
                                    if (*pcVar7 != ']') break;
                                    pcVar1 = pcVar7 - 1;
                                    pcVar8 = pcVar7;
                                } while (pcVar10 <= pcVar7 - 1);
                                if (pcVar8 != nullptr) {
                                    *pcVar8 = '\0';
                                    *(int*)(pcVar10 - 4) = (int)(pcVar8 - pcVar10);
                                }
                            }
                        }
                        FUN_00412ec0();
                        intptr_t iVar3 = local_4;
                        if (*(uint32_t*)(local_4 + 8) <= *(uint32_t*)(local_4 + 0xc)) {
                            FUN_004f5670();
                        }
                        FUN_004f5720();
                        *(char**)(iVar3 + 0x18) = pcVar9;
                    } else if (*(int*)(local_4 + 0x18) != 0 && iVar2 > 0) {
                        char* pcVar9 = strchr(pcVar10, '=');
                        if (pcVar9 != nullptr) {
                            uStack_60 = (wchar_t*)(pcVar9 - pcVar10);
                            int off = (int)(pcVar9 - pcVar10);
                            if (off > 0 && off < *(int*)(pcVar10 - 4) - 1) {
                                pcVar9 = (char*)FUN_00533c78(0x10);
                                if (pcVar9 == nullptr) {
                                    pcVar9 = nullptr;
                                } else {
                                    *(char**)pcVar9 = DAT_008cacd0;
                                    *(char**)(pcVar9 + 4) = DAT_008cacd0;
                                }
                                local_54 = pcVar9;
                                FUN_00476050();
                                FUN_00412ec0();
                                void* puVar6 = local_50 - 8;
                                pcVar10 = unaff_EBX;
                                if (puVar6 != nullptr && puVar6 != (void*)&DAT_008cacc8) {
                                    operator_delete__(puVar6);
                                    pcVar10 = unaff_EBX;
                                }
                                local_50 = DAT_008cacd0;
                                FUN_004f1c20();
                                FUN_004f1b10(pcVar9);
                                FUN_004f1840();
                                char* pcVar1 = pcVar9 + 4;
                                FUN_00412ec0();
                                puVar6 = local_58 - 8;
                                if (puVar6 != nullptr && puVar6 != (void*)&DAT_008cacc8) {
                                    operator_delete__(puVar6);
                                }
                                local_58 = DAT_008cacd0;
                                FUN_004f1c20();
                                FUN_004f1b10(pcVar1);
                                iVar2 = atoi(*(char**)pcVar1);
                                *(int*)(pcVar9 + 8) = iVar2;
                                double dVar12 = atof(*(char**)pcVar1);
                                *(float*)(pcVar9 + 0xc) = (float)dVar12;
                                FUN_004fa440(&local_54);
                                unaff_EBX = pcVar10;
                            }
                        }
                    }
                }
                uVar3 = ((uint32_t(*)(int, int))*(void**)(local_4c[0] + 0x1c))(0, 1);
                uVar4 = ((uint32_t(*)(void))*(void**)(local_54 + 0x10))();
            } while (uVar3 < uVar4);
        }
        *(uint32_t*)(local_4 + 0x18) = 0;
        FUN_00412970();
        uStack_60 = (wchar_t*)(uintptr_t)1; // listing: CONCAT13(1,(uint3)uStack_60)
        result = 1;
    }
    FUN_00412b40();
    char* tail = pcVar10 - 8;
    if (tail != nullptr && tail != (char*)&DAT_008cacc8) {
        operator_delete__(tail);
    }
    return result;
}

// 0x4f96a0 — observed shape: search the group table at self+4/self+0xc by case-insensitive key, store the matching entry at self+0x18, log through 0x4f8f10; returns 1 on hit, 0 otherwise (and clears self+0x18).
uint32_t FUN_004f96a0_recon(void* self, const char* key) {
    int iVar2 = 0;
    if (0 < *(int*)((char*)self + 0xc)) {
        do {
            void** slots = *(void***)((char*)self + 4);
            char* entryKey = *(char**)slots[iVar2];
            int iVar1 = _stricmp(entryKey, key);
            if (iVar1 == 0) {
                *(uint32_t*)((char*)self + 0x18) = (uint32_t)slots[iVar2];
                FUN_004f8f10(self, "Group key set to: %s", key);
                return 1;
            }
            iVar2 = iVar2 + 1;
        } while (iVar2 < *(int*)((char*)self + 0xc));
    }
    FUN_004f8f10(self, "Group key not found: %s", key);
    *(uint32_t*)((char*)self + 0x18) = 0;
    return 0;
}

// 0x4f9710 — observed shape: ensure a group key exists; on a miss allocate a 0x1c entry (string pair + vtable 0x7108b0), insert it through the container at self+0x18; always returns 1.
uint32_t FUN_004f9710_recon(void* self, const char* key) {
    char cVar1 = (char)FUN_004f96a0_recon(self, key);
    if (cVar1 == '\0') {
        uint32_t* puVar2 = (uint32_t*)FUN_00533c78(0x1c);
        uint32_t* puVar3 = nullptr;
        if (puVar2 != nullptr) {
            puVar2[0] = (uint32_t)DAT_008cacd0;
            puVar2[3] = 0;
            puVar2[4] = 0;
            puVar2[5] = 0;
            puVar2[2] = 0;
            puVar2[6] = 1;
            puVar2[1] = (uint32_t)&PTR_FUN_007108b0;
            puVar3 = puVar2;
        }
        FUN_00412f10();
        if (*(uint32_t*)((char*)self + 8) <= *(uint32_t*)((char*)self + 0xc)) {
            FUN_004f5670();
        }
        FUN_004f5720();
        *(uint32_t**)((char*)self + 0x18) = puVar3;
    }
    return 1;
}

// 0x4f9790 — observed shape: integer key lookup in the selected group; writes entry+8 to *out, logs via 0x4f8f10; returns 1 on hit, 0 otherwise.
uint32_t FUN_004f9790_recon(void* self, const char* key, uint32_t* out) {
    uint32_t group = *(uint32_t*)((char*)self + 0x18);
    if (group == 0) {
        return 0;
    }
    int iVar2 = 0;
    if (0 < *(int*)(group + 0x10)) {
        do {
            void** slots = *(void***)(group + 8);
            char* entryKey = *(char**)slots[iVar2];
            int iVar1 = _stricmp(entryKey, key);
            if (iVar1 == 0) {
                uint32_t entry = *(uint32_t*)(*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 8) + iVar2 * 4);
                *out = *(uint32_t*)(entry + 8);
                FUN_004f8f10(self, "Key value found: %s (value = %d)", key, *out);
                return 1;
            }
            group = *(uint32_t*)((char*)self + 0x18);
            iVar2 = iVar2 + 1;
        } while (iVar2 < *(int*)(group + 0x10));
    }
    FUN_004f8f10(self, "Key value not found: %s", key);
    return 0;
}

// 0x4f9820 — observed shape: float key lookup in the selected group; writes entry+0xc to *out, logs via 0x4f8f10; returns 1 on hit, 0 otherwise.
uint32_t FUN_004f9820_recon(void* self, const char* key, float* out) {
    uint32_t group = *(uint32_t*)((char*)self + 0x18);
    if (group == 0) {
        return 0;
    }
    int iVar2 = 0;
    if (0 < *(int*)(group + 0x10)) {
        do {
            void** slots = *(void***)(group + 8);
            char* entryKey = *(char**)slots[iVar2];
            int iVar1 = _stricmp(entryKey, key);
            if (iVar1 == 0) {
                uint32_t entry = *(uint32_t*)(*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 8) + iVar2 * 4);
                *out = *(float*)(entry + 0xc);
                FUN_004f8f10(self, "Key value found: %s (value = %f)", key, *out);
                return 1;
            }
            group = *(uint32_t*)((char*)self + 0x18);
            iVar2 = iVar2 + 1;
        } while (iVar2 < *(int*)(group + 0x10));
    }
    FUN_004f8f10(self, "Key value not found: %s", key);
    return 0;
}

// 0x4f98b0 — observed shape: string key lookup in the selected group; copies entry+4 into the caller buffer with a byte loop, logs via 0x4f8f10; returns 1 on hit, 0 otherwise.
uint32_t FUN_004f98b0_recon(void* self, const char* key, char* out) {
    uint32_t group = *(uint32_t*)((char*)self + 0x18);
    if (group == 0) {
        return 0;
    }
    int iVar5 = 0;
    if (0 < *(int*)(group + 0x10)) {
        do {
            void** slots = *(void***)(group + 8);
            char* entryKey = *(char**)slots[iVar5];
            int iVar2 = _stricmp(entryKey, key);
            if (iVar2 == 0) {
                uint32_t entry = *(uint32_t*)(*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 8) + iVar5 * 4);
                char* src = *(char**)(entry + 4);
                char* dst = out;
                char cVar1;
                do {
                    cVar1 = *src;
                    src = src + 1;
                    *dst = cVar1;
                    dst = dst + 1;
                } while (cVar1 != '\0');
                FUN_004f8f10(self, "Key value found: %s (value = %s)", key, out);
                return 1;
            }
            group = *(uint32_t*)((char*)self + 0x18);
            iVar5 = iVar5 + 1;
        } while (iVar5 < *(int*)(group + 0x10));
    }
    FUN_004f8f10(self, "Key value not found: %s", key);
    return 0;
}

// 0x4f9950 — observed shape: string key lookup that moves the entry+4 string object into the caller-provided string object; logs via 0x4f8f10; returns 1 on hit, 0 otherwise.
uint32_t FUN_004f9950_recon(void* self, const char* key, char** out) {
    uint32_t group = *(uint32_t*)((char*)self + 0x18);
    if (group == 0) {
        return 0;
    }
    int iVar3 = 0;
    if (0 < *(int*)(group + 0x10)) {
        do {
            void** slots = *(void***)(group + 8);
            char* entryKey = *(char**)slots[iVar3];
            int iVar2 = _stricmp(entryKey, key);
            group = *(uint32_t*)((char*)self + 0x18);
            if (iVar2 == 0) {
                char* entry = *(char**)(*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 8) + iVar3 * 4);
                void* src = *(void**)((char*)entry + 4);
                int size = *(int*)((char*)src - 4);
                if (size > -1 && src != nullptr && src != (void*)*out) {
                    if (size == 0) {
                        FUN_00412f90();
                    } else {
                        FUN_004f3350();
                        memmove((void*)*out, src, (size_t)size);
                        *(*out + *(int*)(*out - 4)) = 0;
                    }
                }
                FUN_004f8f10(self, "Key value found: %s (value = %s)", key, *out);
                return 1;
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < *(int*)(group + 0x10));
    }
    FUN_004f8f10(self, "Key value not found: %s", key);
    return 0;
}

// 0x4f9a30 — observed shape: store an integer value into the matching entry (entry+8 int, entry+0xc float) and log the value via 0x4f2600; returns 1 on hit, 0 otherwise.
uint32_t FUN_004f9a30_recon(void* self, const char* key, int* value) {
    uint32_t group = *(uint32_t*)((char*)self + 0x18);
    if (group == 0) {
        return 0;
    }
    int iVar2 = 0;
    if (0 < *(int*)(group + 0x10)) {
        do {
            void** slots = *(void***)(group + 8);
            char* entryKey = *(char**)slots[iVar2];
            int iVar1 = _stricmp(entryKey, key);
            if (iVar1 == 0) {
                uint32_t entry = *(uint32_t*)(*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 8) + iVar2 * 4);
                *(int*)(entry + 8) = *value;
                *(float*)(entry + 0xc) = (float)*value;
                FUN_004f2600(DAT_0070e7ac, *value);
                return 1;
            }
            group = *(uint32_t*)((char*)self + 0x18);
            iVar2 = iVar2 + 1;
        } while (iVar2 < *(int*)(group + 0x10));
    }
    return 0;
}

// 0x4f9ac0 — observed shape: store a float value into the matching entry (entry+8 from 0x5f0ddc, entry+0xc float) and log the double via 0x4f2600; returns 1 on hit, 0 otherwise.
uint32_t FUN_004f9ac0_recon(void* self, const char* key, float* value) {
    uint32_t group = *(uint32_t*)((char*)self + 0x18);
    if (group == 0) {
        return 0;
    }
    int iVar3 = 0;
    if (0 < *(int*)(group + 0x10)) {
        do {
            void** slots = *(void***)(group + 8);
            char* entryKey = *(char**)slots[iVar3];
            int iVar1 = _stricmp(entryKey, key);
            if (iVar1 == 0) {
                uint32_t entry = *(uint32_t*)(*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 8) + iVar3 * 4);
                uint32_t uVar2 = FUN_005f0ddc();
                *(uint32_t*)(entry + 8) = uVar2;
                *(float*)(entry + 0xc) = *value;
                FUN_004f2600(DAT_007108c8, (double)*value);
                return 1;
            }
            group = *(uint32_t*)((char*)self + 0x18);
            iVar3 = iVar3 + 1;
        } while (iVar3 < *(int*)(group + 0x10));
    }
    return 0;
}

// 0x4f9b60 — observed shape: re-parse the matching entry's string value at entry+4 with atoi/atof and store entry+8/entry+0xc; returns 1 on hit, 0 otherwise.
uint32_t FUN_004f9b60_recon(void* self, const char* key) {
    uint32_t group = *(uint32_t*)((char*)self + 0x18);
    if (group == 0) {
        return 0;
    }
    int iVar3 = 0;
    if (0 < *(int*)(group + 0x10)) {
        do {
            void** slots = *(void***)(group + 8);
            char* entryKey = *(char**)slots[iVar3];
            int iVar1 = _stricmp(entryKey, key);
            if (iVar1 == 0) {
                FUN_00412f10();
                uint32_t base = *(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 8);
                int iVar2 = atoi(*(char**)(*(uint32_t*)(base + iVar3 * 4) + 4));
                *(int*)(*(uint32_t*)(base + iVar3 * 4) + 8) = iVar2;
                base = *(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 8);
                double dVar4 = atof(*(char**)(*(uint32_t*)(base + iVar3 * 4) + 4));
                *(float*)(*(uint32_t*)(base + iVar3 * 4) + 0xc) = (float)dVar4;
                return 1;
            }
            group = *(uint32_t*)((char*)self + 0x18);
            iVar3 = iVar3 + 1;
        } while (iVar3 < *(int*)(group + 0x10));
    }
    return 0;
}

// 0x4f9c00 — observed shape: set or insert an integer key; on a miss allocate a 0x10 string-pair record, format via 0x4f2600, store int/float at +8/+0xc, insert through the container; returns 1.
uint32_t FUN_004f9c00_recon(void* self, const char* key, int* param_1) {
    if (*(int*)((char*)self + 0x18) == 0) {
        return 0;
    }
    char cVar1 = (char)FUN_004f9a30_recon(self, key, param_1);
    if (cVar1 == '\0') {
        uint32_t* puVar2 = (uint32_t*)FUN_00533c78(0x10);
        if (puVar2 == nullptr) {
            puVar2 = nullptr;
        } else {
            puVar2[0] = (uint32_t)DAT_008cacd0;
            puVar2[1] = (uint32_t)DAT_008cacd0;
        }
        FUN_00412f10();
        FUN_004f2600(DAT_0070e7ac, *param_1);
        puVar2[2] = (uint32_t)*param_1;
        puVar2[3] = (float)*param_1;
        if (*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 0xc) <= *(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 0x10)) {
            FUN_004f5670();
        }
        FUN_004f5720();
    }
    return 1;
}

// 0x4f9cb0 — observed shape: set or insert a float key; on a miss allocate a 0x10 string-pair record, format via 0x4f2600, store 0x5f0ddc result and the float, insert through the container; returns 1.
uint32_t FUN_004f9cb0_recon(void* self, const char* key, float* param_1) {
    if (*(int*)((char*)self + 0x18) == 0) {
        return 0;
    }
    char cVar1 = (char)FUN_004f9ac0_recon(self, key, param_1);
    if (cVar1 == '\0') {
        uint32_t* puVar2 = (uint32_t*)FUN_00533c78(0x10);
        if (puVar2 == nullptr) {
            puVar2 = nullptr;
        } else {
            puVar2[0] = (uint32_t)DAT_008cacd0;
            puVar2[1] = (uint32_t)DAT_008cacd0;
        }
        FUN_00412f10();
        FUN_004f2600(DAT_007108c8, (double)*param_1);
        uint32_t uVar3 = FUN_005f0ddc();
        puVar2[2] = uVar3;
        puVar2[3] = *param_1;
        if (*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 0xc) <= *(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 0x10)) {
            FUN_004f5670();
        }
        FUN_004f5720();
    }
    return 1;
}

// 0x4f9d60 — observed shape: set or insert a string key; on a miss allocate a 0x10 string-pair record, re-parse its value text with atoi/atof into +8/+0xc, insert through the container; returns 1.
uint32_t FUN_004f9d60_recon(void* self, const char* key) {
    if (*(int*)((char*)self + 0x18) == 0) {
        return 0;
    }
    char cVar1 = (char)FUN_004f9b60_recon(self, key);
    if (cVar1 == '\0') {
        uint32_t* puVar2 = (uint32_t*)FUN_00533c78(0x10);
        if (puVar2 == nullptr) {
            puVar2 = nullptr;
        } else {
            puVar2[0] = (uint32_t)DAT_008cacd0;
            puVar2[1] = (uint32_t)DAT_008cacd0;
        }
        FUN_00412f10();
        FUN_00412f10();
        int iVar3 = atoi((char*)puVar2[1]);
        puVar2[2] = (uint32_t)iVar3;
        double dVar4 = atof((char*)puVar2[1]);
        puVar2[3] = (float)dVar4;
        if (*(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 0xc) <= *(uint32_t*)(*(uint32_t*)((char*)self + 0x18) + 0x10)) {
            FUN_004f5670();
        }
        FUN_004f5720();
    }
    return 1;
}

// 0x4f9e10 — observed shape: serialize the group table at param_1 through the writer object at local_44; optional extension stripping when the flag is set, "key = value" lines with 0x4f2600, offsets adjusted per record, returns 1 when the store opened.
uint8_t FUN_004f9e10_recon(void* self, void* param_1, char param_2) {
    uint8_t local_65 = 0;
    char* local_60 = DAT_008cacd0;
    int local_58 = 0;
    char* local_54 = DAT_008cacd0;
    int local_50 = 0;
    char* puStack_4c = DAT_008cacd0;
    intptr_t local_48 = 0;
    void** local_44 = (void**)&PTR_FUN_006f5814;
    uint32_t local_40 = 0;
    uint32_t local_3c = 0;
    uint32_t local_38 = 0;
    uint32_t local_34 = 0;
    uint32_t local_30 = 0;
    uint32_t local_2c = 0;
    char* local_28 = DAT_008cacd0;
    int local_24 = 0;
    uint32_t local_1c = 0;
    int local_18 = 0;
    int local_14 = 0;
    char* local_10 = DAT_008cacd0;
    char* local_c = DAT_008cacd0;
    uint32_t local_8 = 0;
    uint32_t local_4 = 0;

    if (self != nullptr) {
        FUN_00412f10();
        int iVar5 = (int)DAT_008caccc;
        if (param_2 != '\0') {
            if ((int)(DAT_008caccc - 1) < (int)DAT_008caccc && (int)(DAT_008caccc - 1) > -1) {
                uint8_t uVar1 = *(uint8_t*)((intptr_t)&DAT_008caccc + DAT_008caccc + 3);
                *(uint8_t*)((intptr_t)&DAT_008caccc + DAT_008caccc + 3) = 0;
                char* pcVar3 = strrchr(DAT_008cacd0, '.');
                *(uint8_t*)((intptr_t)&DAT_008caccc + iVar5 + 3) = uVar1;
                if (pcVar3 != nullptr && (int)(pcVar3 - DAT_008cacd0) > -1) {
                    FUN_00476050();
                    FUN_00412ec0();
                    void* piVar4 = (void*)(local_48 - 8);
                    if (piVar4 != nullptr && piVar4 != (void*)&DAT_008cacc8) {
                        operator_delete__(piVar4);
                    }
                }
            }
            FUN_00412e50(DAT_00710980);
        }
        iVar5 = FUN_004f4b20((void*)DAT_008cacd0, 2, 0, 0);
        if (iVar5 == 0) {
            local_14 = 0;
            if (local_18 == 0) {
                local_4 = (uint32_t)((int(*)(int, int))FUN_004f1220)(0, 1);
            } else {
                local_4 = *(uint32_t*)(local_18 + 0x14);
            }
            if (local_24 == 1) {
                FUN_004f8250(local_44);
            }
            local_58 = 0;
            if (0 < *(int*)((char*)param_1 + 0xc)) {
                do {
                    FUN_004f2600(DAT_007108c0, **(char***)(*(uint32_t*)((char*)param_1 + 4) + local_58 * 4));
                    if (param_2 != '\0') {
                        FUN_004f3270();
                    }
                    FUN_004f87c0();
                    uint32_t* piVar4 = (uint32_t*)(*(uint32_t*)((char*)param_1 + 4) + local_58 * 4);
                    local_50 = 0;
                    if (0 < *(int*)(*piVar4 + 0x10)) {
                        do {
                            local_60 = DAT_008cacd0;
                            char** puVar2 = *(char***)(*(uint32_t*)(*piVar4 + 8) + local_50 * 4);
                            FUN_004f2600("%s = %s", puVar2[0], puVar2[1]);
                            if (param_2 != '\0') {
                                for (int k = 0; k < (int)DAT_008caccc; ++k) {
                                    if (DAT_008cacd0[k] == (char)0xff) {
                                        DAT_008cacd0[k] = 1;
                                    } else {
                                        DAT_008cacd0[k] = (char)(DAT_008cacd0[k] + '\x01');
                                    }
                                }
                            }
                            if (local_14 == 1) {
                                char* pcVar3;
                                do {
                                    pcVar3 = local_60;
                                    local_60 = pcVar3 + 1;
                                } while (*pcVar3 != '\0');
                                if ((int)(pcVar3 - DAT_008cacd0) > -1) {
                                    FUN_004f3ca0(DAT_008cacd0);
                                    FUN_004f3540(DAT_0071055c, local_54);
                                    void* q = local_54 - 8;
                                    if (q != nullptr && q != (void*)&DAT_008cacc8) {
                                        operator_delete__(q);
                                    }
                                    local_54 = DAT_008cacd0;
                                    if (local_14 != 1) goto LAB_004fa195;
                                }
                                if ((int)DAT_008cacc8 < 0 && DAT_008caccc != 0) {
                                    *(uint32_t*)DAT_008cacd0 = 0;
                                }
                                ((void(*)(char*, uint32_t))local_44[9])(DAT_008cacd0, DAT_008caccc);
                                ((void(*)(void*, int))*(void**)(puStack_4c + 0x24))((void*)DAT_00710808, 2);
                            } else if (local_14 == 0) {
                                if ((int)DAT_008cacc8 < 0 && DAT_008caccc != 0) {
                                    *(uint32_t*)DAT_008cacd0 = *(uint32_t*)DAT_008cacd0 & 0xff00;
                                }
                                ((void(*)(char*, uint32_t))local_44[9])(DAT_008cacd0, DAT_008caccc);
                                ((void(*)(void*, int))*(void**)(puStack_4c + 0x24))((void*)DAT_00710810, 2);
                            }
LAB_004fa195:
                            piVar4 = (uint32_t*)(*(uint32_t*)((char*)param_1 + 4) + local_58 * 4);
                            local_50 = local_50 + 1;
                        } while (local_50 < *(int*)(*piVar4 + 0x10));
                    }
                    if (DAT_008caccc != 0) {
                        *(uint32_t*)DAT_008cacd0 = *(uint32_t*)DAT_008cacd0 & 0xff00;
                        DAT_008caccc = 0;
                    }
                    if (param_2 != '\0') {
                        for (int k = 0; k < (int)DAT_008caccc; ++k) {
                            if (DAT_008cacd0[k] == (char)0xff) {
                                DAT_008cacd0[k] = 1;
                            } else {
                                DAT_008cacd0[k] = (char)(DAT_008cacd0[k] + '\x01');
                            }
                        }
                    }
                    if (local_14 == 1) {
                        char* pcVar3 = DAT_008cacd0;
                        char* pcVar6;
                        do {
                            pcVar6 = pcVar3;
                            pcVar3 = pcVar6 + 1;
                        } while (*pcVar6 != '\0');
                        if ((int)(pcVar6 - DAT_008cacd0) > -1) {
                            FUN_004f3ca0(DAT_008cacd0);
                            FUN_004f3540(DAT_0071055c, puStack_4c);
                            void* q = puStack_4c - 8;
                            if (q != nullptr && q != (void*)&DAT_008cacc8) {
                                operator_delete__(q);
                            }
                            puStack_4c = DAT_008cacd0;
                            if (local_14 != 1) goto LAB_004fa385;
                        }
                        if ((int)DAT_008cacc8 < 0 && DAT_008caccc != 0) {
                            *(uint32_t*)DAT_008cacd0 = 0;
                        }
                        ((void(*)(char*, uint32_t))local_44[9])(DAT_008cacd0, DAT_008caccc);
                        ((void(*)(void*, int))*(void**)(puStack_4c + 0x24))((void*)DAT_00710808, 2);
                    } else if (local_14 == 0) {
                        if ((int)DAT_008cacc8 < 0 && DAT_008caccc != 0) {
                            *(uint32_t*)DAT_008cacd0 = *(uint32_t*)DAT_008cacd0 & 0xff00;
                        }
                        ((void(*)(char*, uint32_t))local_44[9])(DAT_008cacd0, DAT_008caccc);
                        ((void(*)(void*, int))*(void**)(puStack_4c + 0x24))((void*)DAT_00710810, 2);
                    }
LAB_004fa385:
                    local_58 = local_58 + 1;
                } while (local_58 < *(int*)((char*)param_1 + 0xc));
            }
            void* p1 = local_10 - 8;
            if (p1 != nullptr && p1 != (void*)&DAT_008cacc8) {
                operator_delete__(p1);
            }
            void* p2 = local_c - 8;
            local_10 = DAT_008cacd0;
            if (p2 != nullptr && p2 != (void*)&DAT_008cacc8) {
                operator_delete__(p2);
            }
            local_c = DAT_008cacd0;
            FUN_004f4de0();
            local_65 = 1;
        }
    }
    FUN_00412b40();
    return local_65;
}

// 0x4fa440 — observed shape: container count accessor; returns self+0xc after growth via 0x4f5670 when self+8 <= self+0xc, then 0x4f5720.
uint32_t FUN_004fa440_recon(void* self) {
    uint32_t uVar1 = *(uint32_t*)((char*)self + 0xc);
    if (*(uint32_t*)((char*)self + 8) <= uVar1) {
        FUN_004f5670();
    }
    FUN_004f5720();
    return uVar1;
}
