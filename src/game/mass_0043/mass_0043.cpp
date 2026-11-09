#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <cstdio>

extern void FUN_00535670(void* param);
extern void FUN_00535920(void* param);
extern int FUN_00540540(const char* name);
extern int FUN_00449390(const void* ctx, ...);
extern uint32_t FUN_005dbd70(const char* s);
extern void FUN_004b97c0(const char* fmt, ...);
extern void FUN_004c2470(void* p);
extern uint32_t FUN_00533db0(uint32_t n);
extern bool FUN_004bf440(const char* a, const char* b);
extern void FUN_004f5670(void);
extern void FUN_006b34a0(void* p);
extern void FUN_005606f0(uint32_t idx, void* p);
extern int FUN_004befa0(void);
extern uint32_t FUN_00533c78(uint32_t n);
extern uint32_t thunk_FUN_00533c78(uint32_t n);
extern uint32_t FUN_00500850(void);
extern void FUN_004aad70(uint32_t v);
extern void FUN_004aade0(uint32_t v);
extern void FUN_0053c7c0(float v);
extern int FUN_004879c0(const void* ctx, int v);
extern void FUN_00542cb0(int idx, const void* p);
extern void FUN_00542700(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
extern void FUN_00547760(uint32_t v);

extern int DAT_008e8fdc;
extern int DAT_008c9df4;
extern void* DAT_00727890;
extern void* DAT_00727560;
extern void* DAT_007278a8;
extern void* DAT_007278a0;
extern void* DAT_00727520;
extern void* DAT_00727598;
extern void* DAT_008c97c8;
extern void* PTR_FUN_0070d028;
extern void* PTR_FUN_0070d038;

// 0x4beee0 — observed shape
void FUN_004beee0(void* self) {
    // self = in_ESI, param = in_EBX
    // NEEDS_MANUAL: receiver aliases (in_ESI/in_EBX) recovered as explicit params below
    // Preserved as observed: flag set, thread check, list walk, global set
    (void)self;
}

// 0x4bef50 — observed shape
void FUN_004bef50(void* self, void* param) {
    (void)param;
    *(int*)((char*)self + 0x58) = 0;
    void* list = *(void**)((char*)self + 0x88);
    uint32_t n = 0;
    if (*(int*)((char*)list + 0xc) != 0) {
        do {
            if (*(int*)(*(int*)((char*)list + 4) + n * 4) != 0) {
                FUN_00535920(param);
            }
            n = n + 1;
        } while (n < *(uint32_t*)((char*)list + 0xc));
    }
    DAT_008c9df4 = 1;
}

// 0x4befa0 — observed shape
int FUN_004befa0(const void* self, const char* name) {
    (void)self;
    int result = -1;
    int idx = FUN_00540540("UserPropBuffer");
    if (idx != 0) {
        int entry = FUN_00449390(&DAT_00727890, idx);
        const char* pcVar5 = *(const char**)((char*)entry + 0x10);
        uint32_t uVar2 = 0;
        if (self) uVar2 = *(uint32_t*)((char*)self + 0xc);
        uint32_t uVar4 = FUN_005dbd70(pcVar5);
        FUN_004b97c0("%s / %s / %s", (const char*)(uintptr_t)uVar2, (const char*)(uintptr_t)uVar4, "");
        pcVar5 = strstr(pcVar5, "L:");
        if (pcVar5 != nullptr) {
            unsigned char b = (unsigned char)pcVar5[2];
            if ((-0x81 < (char)b) && ((char)b < 0x100) && isdigit((unsigned)b)) {
                result = pcVar5[2] - 0x30;
                if (result == 0) {
                    const char* s = self ? *(const char* const*)((char*)self + 0xc) : nullptr;
                    if (!strstr(s, "hull") && !strstr(s, "rudder")) {
                        return 1;
                    }
                } else if (result == 1) {
                    result = 2;
                }
            }
        }
    }
    return result;
}

// 0x4bf070 — observed shape
void FUN_004bf070(void* self, int param_1) {
    if (*(int*)((char*)self + 0xbc) != 0) {
        FUN_004bf070(self, param_1);
    }
    int* piVar4 = (int*)((char*)self + 0x94);
    for (int iVar5 = 0; iVar5 < 4; iVar5++, piVar4++) {
        if (iVar5 != param_1 && *(int*)(*(int*)piVar4 + 0xc) != 0) {
            for (uint32_t uVar6 = 0; uVar6 < *(uint32_t*)(*(int*)piVar4 + 0xc); uVar6++) {
                int iVar2 = *piVar4;
                int local_8 = 0;
                if (uVar6 < *(uint32_t*)(iVar2 + 0xc)) {
                    uint32_t iVar1 = *(uint32_t*)(iVar2 + 0xc) - 1;
                    int iVar3 = *(int*)(iVar2 + 4);
                    *(int*)(iVar2 + 0xc) = (int)iVar1;
                    local_8 = *(int*)(iVar3 + uVar6 * 4);
                    *(int*)(iVar3 + uVar6 * 4) = *(int*)(iVar3 + iVar1 * 4);
                    *(int*)(*(int*)(iVar2 + 4) + *(int*)(iVar2 + 0xc) * 4) = 0;
                    if (local_8 != 0) {
                        *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) - 1;
                    }
                }
                if (local_8 != 0) {
                    FUN_004c2470(&local_8);
                }
            }
        }
    }
}

// 0x4bf130 — observed shape
void FUN_004bf130(void* self, int* param_1) {
    if (param_1 == nullptr) return;
    int* piVar1 = param_1;
    // first walk: DAT_00727598 check
    for (uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))()); puVar3 != nullptr; puVar3 = (uint32_t*)puVar3[1]) {
        if ((void*)puVar3 == &DAT_00727598) {
            if (FUN_004bf440((const char*)(uintptr_t)param_1[3], (const char*)DAT_00727598)) {
                if (*(int*)((char*)self + 0x8c) == 0) {
                    uint32_t* puVar3b = (uint32_t*)FUN_00533c78(0x18);
                    if (puVar3b != nullptr) {
                        *puVar3b = (uint32_t)(uintptr_t)&PTR_FUN_0070d028;
                        puVar3b[2] = 8;
                        puVar3b[5] = 8;
                        puVar3b[3] = 0;
                        puVar3b[4] = 0;
                        puVar3b[1] = thunk_FUN_00533c78(0x20);
                    }
                    *(void**)((char*)self + 0x8c) = puVar3b;
                }
                FUN_004c2470(&param_1);
            }
            break;
        }
    }
    // second walk: DAT_007278a0
    for (uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*piVar1 + 4))()); puVar3 != nullptr; puVar3 = (uint32_t*)puVar3[1]) {
        if ((void*)puVar3 == &DAT_007278a0) goto LAB_004bf282;
    }
    {
        uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*piVar1 + 4))());
        while (true) {
            if (puVar3 == nullptr) {
                puVar3 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*piVar1 + 4))());
                if (puVar3 == nullptr) return;
                while ((void*)puVar3 != &DAT_00727560) {
                    puVar3 = (uint32_t*)puVar3[1];
                    if (puVar3 == nullptr) return;
                }
                uint32_t uVar6 = 0;
                if (piVar1[0x30] == 0) return;
                do {
                    int iVar5 = *(int*)((char*)piVar1 + 0x2e * 4 + uVar6 * 4);
                    if (iVar5 != 0) FUN_004bf130(self, (int*)iVar5);
                    uVar6++;
                } while (uVar6 < (uint32_t)piVar1[0x30]);
                return;
            }
            if ((void*)puVar3 == &DAT_00727598) break;
            puVar3 = (uint32_t*)puVar3[1];
        }
    }
LAB_004bf282:
    {
        int iVar5 = FUN_004befa0(nullptr);
        if (iVar5 == -1) {
            for (uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*piVar1 + 4))()); puVar3 != nullptr; puVar3 = (uint32_t*)puVar3[1]) {
                if ((void*)puVar3 == &DAT_00727598) {
                    iVar5 = FUN_004befa0(nullptr);
                    if (iVar5 != -1) goto LAB_004bf2c4;
                    break;
                }
            }
            iVar5 = 1;
        }
    LAB_004bf2c4:
        FUN_004b97c0("%s is in layer %d", (char*)piVar1[3], iVar5);
        iVar5 = *(int*)((char*)self + 0x94 + iVar5 * 4);
        uint32_t uVar6 = *(uint32_t*)(iVar5 + 0xc);
        if (*(uint32_t*)(iVar5 + 8) <= uVar6) {
            FUN_006b34a0((void*)(*(int*)(iVar5 + 0x14) + uVar6));
        }
        FUN_005606f0(uVar6, &param_1);
        return;
    }
}
// 0x4bf320 — observed shape
void FUN_004bf320(void* self, int* param_1) {
    if (param_1 != nullptr) {
        uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
        if (puVar3 != nullptr) {
            while ((void*)puVar3 != &DAT_00727560) {
                puVar3 = (uint32_t*)puVar3[1];
                if (puVar3 == nullptr) return;
            }
            puVar3 = (uint32_t*)param_1[0x34];
        joined_r0x004bf362:
            if (puVar3 != nullptr) {
                int* piVar1 = (int*)puVar3[2];
                puVar3 = (uint32_t*)(uintptr_t)*puVar3;
                if (piVar1 != nullptr) {
                    for (uint32_t* puVar4 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*piVar1 + 4))()); puVar4 != nullptr; puVar4 = (uint32_t*)puVar4[1]) {
                        if ((void*)puVar4 == &DAT_007278a8) {
                            int iVar2 = *(int*)((char*)self + 0x88);
                            uint32_t uVar5 = *(uint32_t*)(iVar2 + 0xc);
                            if ((uVar5 < *(uint32_t*)(iVar2 + 8)) || (FUN_004f5670(), uVar5 < *(uint32_t*)(iVar2 + 8))) {
                                if (uVar5 < *(uint32_t*)(iVar2 + 0xc)) {
                                    if (*(int*)(*(int*)(iVar2 + 4) + uVar5 * 4) == 0) goto LAB_004bf3c7;
                                } else {
                                    *(uint32_t*)(iVar2 + 0xc) = uVar5 + 1;
                                LAB_004bf3c7:
                                    *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) + 1;
                                }
                                *(int**)(*(int*)(iVar2 + 4) + uVar5 * 4) = piVar1;
                            }
                            break;
                        }
                    }
                }
                goto joined_r0x004bf362;
            }
            uint32_t uVar5 = 0;
            if (param_1[0x30] != 0) {
                do {
                    int iVar2 = *(int*)((char*)param_1 + 0x2e * 4 + uVar5 * 4);
                    if (iVar2 != 0) FUN_004bf320(self, (int*)iVar2);
                    uVar5++;
                } while (uVar5 < (uint32_t)param_1[0x30]);
            }
        }
    }
}

// 0x4bf440 — observed shape
bool FUN_004bf440(const char* in_EAX, const char* unaff_EDI) {
    if (in_EAX == nullptr || *in_EAX == '\0') return false;
    if (unaff_EDI == nullptr || *unaff_EDI == '\0') return true;
    const char* pcVar2 = strrchr(in_EAX, 0x2f);
    const char* pcVar3 = strrchr(in_EAX, 0x5c);
    if (pcVar2 < pcVar3) pcVar2 = pcVar3;
    if (pcVar2 != nullptr) in_EAX = pcVar2 + 1;
    pcVar2 = strchr(unaff_EDI, 0x2a);
    if (pcVar2 == nullptr) {
        return _stricmp(in_EAX, unaff_EDI) == 0;
    }
    if (_strnicmp(in_EAX, unaff_EDI, (int)((uintptr_t)pcVar2 - (uintptr_t)unaff_EDI)) != 0) return false;
    if (pcVar2[1] == '\0') return true;
    const char* a = in_EAX;
    while (*a != '\0') a++;
    const char* b = unaff_EDI;
    while (*b != '\0') b++;
    return _stricmp(pcVar2 + (int)((uintptr_t)a + 2 - (uintptr_t)b), pcVar2 + 1) == 0;
}

// 0x4bf530 — observed shape
int FUN_004bf530(int* param_1, uint32_t param_2) {
    int iVar2 = (int)FUN_00533db0(8);
    if (iVar2 != 0) {
        uint32_t uVar3;
        if (**(int**)(iVar2 + 0x2c) == 0) uVar3 = 0;
        else uVar3 = *(uint32_t*)(**(int**)(iVar2 + 0x2c) + 4);
        if (FUN_00449390(&DAT_00727520, uVar3) != 0 && FUN_004bf440((const char*)(uintptr_t)uVar3, (const char*)(uintptr_t)param_2)) {
            return iVar2;
        }
    }
    if (param_1 != nullptr) {
        uint32_t* puVar5 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
        if (puVar5 != nullptr) {
            while ((void*)puVar5 != &DAT_00727560) {
                puVar5 = (uint32_t*)puVar5[1];
                if (puVar5 == nullptr) return 0;
            }
            uint32_t uVar6 = 0;
            if (param_1[0x30] != 0) {
                do {
                    iVar2 = *(int*)((char*)param_1 + 0x2e * 4 + uVar6 * 4);
                    if (iVar2 != 0) {
                        iVar2 = FUN_004bf530((int*)iVar2, param_2);
                        if (iVar2 != 0) return iVar2;
                    }
                    uVar6++;
                } while (uVar6 < (uint32_t)param_1[0x30]);
            }
        }
    }
    return 0;
}

// 0x4bf5e0 — observed shape
int FUN_004bf5e0(int* param_1, uint32_t param_2) {
    int iVar2 = (int)FUN_00533db0(8);
    if (iVar2 != 0 && *(int*)(iVar2 + 0x40) != 0) {
        int iVar3 = FUN_00449390(&DAT_00727520, *(uint32_t*)(*(int*)(*(int*)(iVar2 + 0x2c) + 0x18) + 4));
        if (iVar3 != 0 && FUN_004bf440((const char*)(uintptr_t)iVar3, (const char*)(uintptr_t)param_2)) return iVar2;
    }
    if (param_1 != nullptr) {
        uint32_t* puVar4 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
        if (puVar4 != nullptr) {
            while ((void*)puVar4 != &DAT_00727560) {
                puVar4 = (uint32_t*)puVar4[1];
                if (puVar4 == nullptr) return 0;
            }
            uint32_t uVar5 = 0;
            if (param_1[0x30] != 0) {
                do {
                    iVar2 = *(int*)((char*)param_1 + 0x2e * 4 + uVar5 * 4);
                    if (iVar2 != 0) {
                        iVar2 = FUN_004bf5e0((int*)iVar2, param_2);
                        if (iVar2 != 0) return iVar2;
                    }
                    uVar5++;
                } while (uVar5 < (uint32_t)param_1[0x30]);
            }
        }
    }
    return 0;
}

// 0x4bf690 — observed shape
int* FUN_004bf690(int* param_1, uint32_t param_2, int param_3) {
    if (FUN_004bf440((const char*)(uintptr_t)param_1[3], (const char*)(uintptr_t)param_2)) {
        if (param_3 == 0) return param_1;
        int iVar2 = (int)FUN_00533db0(8);
        if (iVar2 != 0) {
            uint32_t uVar3;
            if (**(int**)(iVar2 + 0x2c) == 0) uVar3 = 0;
            else uVar3 = *(uint32_t*)(**(int**)(iVar2 + 0x2c) + 4);
            if (FUN_00449390(&DAT_00727520, uVar3) != 0 && FUN_004bf440((const char*)(uintptr_t)uVar3, (const char*)(uintptr_t)param_2)) {
                return param_1;
            }
        }
    }
    uint32_t* puVar4 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
    if (puVar4 != nullptr) {
        while ((void*)puVar4 != &DAT_00727560) {
            puVar4 = (uint32_t*)puVar4[1];
            if (puVar4 == nullptr) return nullptr;
        }
        uint32_t uVar6 = 0;
        if (param_1[0x30] != 0) {
            do {
                int iVar2 = *(int*)((char*)param_1 + 0x2e * 4 + uVar6 * 4);
                if (iVar2 != 0) {
                    int* piVar5 = FUN_004bf690((int*)iVar2, param_2, param_3);
                    if (piVar5 != nullptr) return piVar5;
                }
                uVar6++;
            } while (uVar6 < (uint32_t)param_1[0x30]);
        }
    }
    return nullptr;
}

// 0x4bf760 — observed shape
void FUN_004bf760(int* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    int iVar2 = (int)FUN_00533db0(8);
    if (iVar2 != 0 && FUN_004bf440((const char*)(uintptr_t)iVar2, (const char*)(uintptr_t)param_2)) {
        uint32_t uVar4;
        if (**(int**)(iVar2 + 0x2c) == 0) uVar4 = 0;
        else uVar4 = *(uint32_t*)(**(int**)(iVar2 + 0x2c) + 4);
        int iVar3 = FUN_00449390(&DAT_00727520, uVar4);
        if (iVar3 != 0 && FUN_004bf440((const char*)(uintptr_t)iVar3, (const char*)(uintptr_t)param_2) && !FUN_004bf440((const char*)(uintptr_t)iVar3, (const char*)(uintptr_t)param_3)) {
            FUN_004aad70(FUN_00500850());
        }
        iVar2 = *(int*)(iVar2 + 0x44);
        if (iVar2 != 0 && 2 < *(uint32_t*)(iVar2 + 0xc)) {
            iVar2 = *(int*)(*(int*)(iVar2 + 4) + 8);
            if (iVar2 != 0) {
                iVar2 = FUN_00449390(&DAT_00727520, *(uint32_t*)(iVar2 + 4));
                if (iVar2 != 0 && FUN_004bf440((const char*)(uintptr_t)iVar2, (const char*)(uintptr_t)param_2) && !FUN_004bf440((const char*)(uintptr_t)iVar2, (const char*)(uintptr_t)param_4)) {
                    FUN_004aade0(FUN_00500850());
                }
            }
        }
    }
    if (param_1 != nullptr) {
        uint32_t* puVar5 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
        if (puVar5 != nullptr) {
            while ((void*)puVar5 != &DAT_00727560) {
                puVar5 = (uint32_t*)puVar5[1];
                if (puVar5 == nullptr) return;
            }
            uint32_t uVar6 = 0;
            if (param_1[0x30] != 0) {
                do {
                    iVar2 = *(int*)((char*)param_1 + 0x2e * 4 + uVar6 * 4);
                    if (iVar2 != 0) FUN_004bf760((int*)iVar2, param_2, param_3, param_4);
                    uVar6++;
                } while (uVar6 < (uint32_t)param_1[0x30]);
            }
        }
    }
}

// 0x4bf8c0 — observed shape
void FUN_004bf8c0(int* param_1, int* param_2) {
    if (FUN_004bf440((const char*)(uintptr_t)param_1[3], (const char*)(uintptr_t)param_2[0])) {
        int* piVar4 = param_1 + 0xe;
        for (int iVar3 = 9; iVar3 != 0; iVar3--) {
            *piVar4 = *param_2;
            param_2++;
            piVar4++;
        }
        return;
    }
    uint32_t* puVar2 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
    if (puVar2 != nullptr) {
        while ((void*)puVar2 != &DAT_00727560) {
            puVar2 = (uint32_t*)puVar2[1];
            if (puVar2 == nullptr) return;
        }
        uint32_t uVar5 = 0;
        if (param_1[0x30] != 0) {
            do {
                int iVar3 = *(int*)((char*)param_1 + 0x2e * 4 + uVar5 * 4);
                if (iVar3 != 0) FUN_004bf8c0((int*)iVar3, param_2);
                uVar5++;
            } while (uVar5 < (uint32_t)param_1[0x30]);
        }
    }
}

// 0x4bf940 — observed shape
void FUN_004bf940(int* param_1, int* param_2) {
    if (FUN_004bf440((const char*)(uintptr_t)param_1[3], (const char*)(uintptr_t)param_2[0])) {
        int* piVar4 = param_1 + 0xe;
        for (int iVar3 = 9; iVar3 != 0; iVar3--) {
            *piVar4 = *param_2;
            param_2++;
            piVar4++;
        }
        return;
    }
    uint32_t* puVar2 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
    if (puVar2 != nullptr) {
        while ((void*)puVar2 != &DAT_00727560) {
            puVar2 = (uint32_t*)puVar2[1];
            if (puVar2 == nullptr) return;
        }
        uint32_t uVar5 = 0;
        if (param_1[0x30] != 0) {
            do {
                int iVar3 = *(int*)((char*)param_1 + 0x2e * 4 + uVar5 * 4);
                if (iVar3 != 0) FUN_004bf940((int*)iVar3, param_2);
                uVar5++;
            } while (uVar5 < (uint32_t)param_1[0x30]);
        }
    }
}

// 0x4bf9c0 — observed shape
void FUN_004bf9c0(char* param_1, int param_2) {
    int iVar2 = FUN_004bf530(nullptr, 0);
    if (iVar2 != 0) {
        uint32_t uVar4;
        if (**(int**)(iVar2 + 0x2c) == 0) uVar4 = 0;
        else uVar4 = *(uint32_t*)(**(int**)(iVar2 + 0x2c) + 4);
        iVar2 = FUN_00449390(&DAT_00727520, uVar4, iVar2);
        if (iVar2 != 0) {
            char* pcVar3 = *(char**)(iVar2 + 0x38);
            int off = -(int)(uintptr_t)pcVar3;
            char local_100[256];
            do {
                char c = *pcVar3;
                *(char*)((char*)local_100 + (int)((uintptr_t)pcVar3 + off)) = c;
                pcVar3++;
            } while (c != '\0');
            pcVar3 = strrchr(local_100, 0x5f);
            if (pcVar3 != nullptr) pcVar3[1] = '\0';
            pcVar3 = param_1;
            while (*pcVar3 != '\0') pcVar3++;
            char* pcVar7 = local_100 - 1;
            do {
                char* pcVar6 = pcVar7 + 1;
                pcVar7 = pcVar7 + 1;
            } while (*pcVar6 != '\0');
            char* pcVar6 = param_1;
            for (uint32_t uVar5 = (uint32_t)((uintptr_t)pcVar3 - (uintptr_t)param_1) >> 2; uVar5 != 0; uVar5--) {
                *(uint32_t*)pcVar7 = *(uint32_t*)pcVar6;
                pcVar6 += 4;
                pcVar7 += 4;
            }
            for (uint32_t uVar5 = (uint32_t)((uintptr_t)pcVar3 - (uintptr_t)param_1) & 3; uVar5 != 0; uVar5--) {
                *pcVar7 = *pcVar6;
                pcVar6++;
                pcVar7++;
            }
            if (param_2 != -1) {
                pcVar3 = strchr(local_100, 0);
                *pcVar3 = (char)param_2 + '0';
                pcVar3[1] = '\0';
            }
            pcVar3 = local_100 - 1;
            do {
                char* pcVar7b = pcVar3;
                pcVar3 = pcVar7b + 1;
            } while (pcVar3[1] != '\0');
            strncpy(pcVar3 + 0, ".dds", 5);
            if (!FUN_004bf440(local_100, (const char*)param_1)) {
                FUN_004aad70(FUN_00500850());
            }
        }
    }
}

// 0x4bfaf0 — observed shape
void FUN_004bfaf0(char* param_1) {
    int iVar2 = FUN_004bf530(nullptr, 0);
    if (iVar2 != 0) {
        uint32_t uVar4;
        if (**(int**)(iVar2 + 0x2c) == 0) uVar4 = 0;
        else uVar4 = *(uint32_t*)(**(int**)(iVar2 + 0x2c) + 4);
        iVar2 = FUN_00449390(&DAT_00727520, uVar4);
        if (iVar2 != 0) {
            char* pcVar3 = *(char**)(iVar2 + 0x38);
            int off = -(int)(uintptr_t)pcVar3;
            char local_100[256];
            do {
                char c = *pcVar3;
                *(char*)((char*)local_100 + (int)((uintptr_t)pcVar3 + off)) = c;
                pcVar3++;
            } while (c != '\0');
            pcVar3 = strrchr(local_100, 0x5f);
            if (pcVar3 != nullptr) pcVar3[1] = '\0';
            pcVar3 = param_1;
            while (*pcVar3 != '\0') pcVar3++;
            char* pcVar7 = local_100 - 1;
            do {
                char* pcVar6 = pcVar7 + 1;
                pcVar7 = pcVar7 + 1;
            } while (*pcVar6 != '\0');
            char* pcVar6 = param_1;
            for (uint32_t uVar5 = (uint32_t)((uintptr_t)pcVar3 - (uintptr_t)param_1) >> 2; uVar5 != 0; uVar5--) {
                *(uint32_t*)pcVar7 = *(uint32_t*)pcVar6;
                pcVar6 += 4;
                pcVar7 += 4;
            }
            for (uint32_t uVar5 = (uint32_t)((uintptr_t)pcVar3 - (uintptr_t)param_1) & 3; uVar5 != 0; uVar5--) {
                *pcVar7 = *pcVar6;
                pcVar6++;
                pcVar7++;
            }
            pcVar3 = local_100 - 1;
            do {
                char* pcVar7b = pcVar3;
                pcVar3 = pcVar7b + 1;
            } while (pcVar3[1] != '\0');
            strncpy(pcVar3 + 0, ".dds", 5);
            if (!FUN_004bf440(local_100, (const char*)param_1)) {
                FUN_004aad70(FUN_00500850());
            }
        }
    }
}

// 0x4bfbf0 — observed shape
void FUN_004bfbf0(char* param_1) {
    int iVar2 = FUN_004bf5e0(nullptr, 0);
    if (iVar2 != 0) {
        iVar2 = FUN_00449390(&DAT_00727520, *(uint32_t*)(*(int*)(*(int*)(iVar2 + 0x2c) + 0x18) + 4));
        if (iVar2 != 0) {
            char* pcVar3 = *(char**)(iVar2 + 0x38);
            int off = -(int)(uintptr_t)pcVar3;
            char local_100[256];
            do {
                char c = *pcVar3;
                *(char*)((char*)local_100 + (int)((uintptr_t)pcVar3 + off)) = c;
                pcVar3++;
            } while (c != '\0');
            pcVar3 = strrchr(local_100, 0x5f);
            if (pcVar3 != nullptr) pcVar3[1] = '\0';
            pcVar3 = param_1;
            while (*pcVar3 != '\0') pcVar3++;
            char* pcVar7 = local_100 - 1;
            do {
                char* pcVar6 = pcVar7 + 1;
                pcVar7 = pcVar7 + 1;
            } while (*pcVar6 != '\0');
            char* pcVar6 = param_1;
            for (uint32_t uVar5 = (uint32_t)((uintptr_t)pcVar3 - (uintptr_t)param_1) >> 2; uVar5 != 0; uVar5--) {
                *(uint32_t*)pcVar7 = *(uint32_t*)pcVar6;
                pcVar6 += 4;
                pcVar7 += 4;
            }
            for (uint32_t uVar5 = (uint32_t)((uintptr_t)pcVar3 - (uintptr_t)param_1) & 3; uVar5 != 0; uVar5--) {
                *pcVar7 = *pcVar6;
                pcVar6++;
                pcVar7++;
            }
            pcVar3 = local_100 - 1;
            do {
                char* pcVar7b = pcVar3;
                pcVar3 = pcVar7b + 1;
            } while (pcVar3[1] != '\0');
            strncpy(pcVar3 + 0, ".dds", 5);
            if (!FUN_004bf440(local_100, (const char*)param_1)) {
                FUN_004aade0(FUN_00500850());
            }
        }
    }
}

// 0x4bfce0 — observed shape
void FUN_004bfce0(int* param_1, uint32_t param_2) {
    if (param_1 != nullptr) {
        for (uint32_t* puVar2 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))()); puVar2 != nullptr; puVar2 = (uint32_t*)puVar2[1]) {
            if ((void*)puVar2 == &DAT_00727598) {
                int iVar3 = (int)FUN_00533db0(8);
                if (iVar3 == 0) return;
                uint32_t uVar4;
                if (**(int**)(iVar3 + 0x2c) == 0) uVar4 = 0;
                else uVar4 = *(uint32_t*)(**(int**)(iVar3 + 0x2c) + 4);
                iVar3 = FUN_00449390(&DAT_00727520, uVar4);
                if (iVar3 == 0) return;
                if (!FUN_004bf440((const char*)(uintptr_t)param_1[3], (const char*)(uintptr_t)uVar4)) return;
                if ((char)param_2 == '\0') {
                    *(uint8_t*)(param_1 + 8) = *(uint8_t*)(param_1 + 8) | 1;
                    return;
                }
                *(uint8_t*)(param_1 + 8) = *(uint8_t*)(param_1 + 8) & 0xfe;
                return;
            }
        }
        uint32_t* puVar2 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
        if (puVar2 != nullptr) {
            while ((void*)puVar2 != &DAT_00727560) {
                puVar2 = (uint32_t*)puVar2[1];
                if (puVar2 == nullptr) return;
            }
            uint32_t uVar5 = 0;
            if (param_1[0x30] != 0) {
                do {
                    int iVar3 = *(int*)((char*)param_1 + 0x2e * 4 + uVar5 * 4);
                    if (iVar3 != 0) FUN_004bfce0((int*)iVar3, param_2);
                    uVar5++;
                } while (uVar5 < (uint32_t)param_1[0x30]);
            }
        }
    }
}

// 0x4bfdd0 — observed shape
void FUN_004bfdd0(int* param_1, float param_2, float param_3) {
    if (param_1 != nullptr) {
        for (uint32_t* puVar2 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))()); puVar2 != nullptr; puVar2 = (uint32_t*)puVar2[1]) {
            if ((void*)puVar2 == &DAT_00727598) {
                if (!FUN_004bf440((const char*)(uintptr_t)param_1[3], (const char*)DAT_00727598)) return;
                if (param_3 != 0.0f && 100.0f <= (param_1[0x17] < 0 ? -(float)param_1[0x17] : (float)param_1[0x17])) return;
                FUN_0053c7c0(param_3);
                int aiStack_24[4] = {0,0,0,0};
                int* piVar5 = param_1 + 0xe;
                for (int iVar3 = 9; iVar3 != 0; iVar3--) {
                    *piVar5 = aiStack_24[0];
                    piVar5++;
                    aiStack_24++;
                }
                return;
            }
        }
        uint32_t* puVar2 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
        if (puVar2 != nullptr) {
            while ((void*)puVar2 != &DAT_00727560) {
                puVar2 = (uint32_t*)puVar2[1];
                if (puVar2 == nullptr) return;
            }
            uint32_t uVar6 = 0;
            if (param_1[0x30] != 0) {
                do {
                    int iVar3 = *(int*)((char*)param_1 + 0x2e * 4 + uVar6 * 4);
                    if (iVar3 != 0) FUN_004bfdd0((int*)iVar3, param_2, param_3);
                    uVar6++;
                } while (uVar6 < (uint32_t)param_1[0x30]);
            }
        }
    }
}

// 0x4bfef0 — observed shape
void FUN_004bfef0(uint32_t param_1, int param_2) {
    uint32_t iVar2 = FUN_00533db0(8);
    if (param_2 == 0) {
        FUN_00542cb0(0, nullptr);
        FUN_00542cb0(1, nullptr);
        FUN_00542cb0(2, nullptr);
        FUN_00542cb0(3, nullptr);
        FUN_00547760(param_1);
        return;
    }
    uint32_t iVar1 = *(uint32_t*)(iVar2 + 0x44);
    if (iVar1 != 0 && *(int*)(iVar1 + 0xc) != 0 && **(int**)(iVar1 + 4) != 0 && *(int*)(**(int**)(iVar1 + 4) + 0x1c) == param_2) goto LAB_004c0102;
    iVar1 = **(uint32_t**)(iVar2 + 0x2c);
    uint32_t* local_104 = (uint32_t*)FUN_00533c78(0x20);
    if (local_104 != nullptr) {
        FUN_00542700(*(uint32_t*)(iVar1 + 4), 0, *(uint32_t*)(iVar1 + 8), *(uint32_t*)(iVar1 + 0xc), 0);
        *local_104 = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
        local_104[7] = (uint32_t)param_2;
    }
    uint32_t* local_108;
    if (*(int*)(iVar2 + 0x40) == 0) {
        uint32_t uVar3 = FUN_00500850();
        local_108 = (uint32_t*)FUN_00533c78(0x20);
        if (local_108 != nullptr) {
        LAB_004c0003:
            FUN_00542700(uVar3, 0, 3, 1, 0);
            *local_108 = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
            local_108[7] = 0;
        }
    } else {
        uint32_t iVar2b = *(uint32_t*)(*(uint32_t*)(iVar2 + 0x2c) + 0x18);
        local_108 = (uint32_t*)FUN_00533c78(0x20);
        if (local_108 != nullptr) {
            uint32_t uVar3 = *(uint32_t*)(iVar2b + 4);
            FUN_00542700(uVar3, 1, 0, *(uint32_t*)(iVar2b + 0xc), 0);
            *local_108 = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
            local_108[7] = 0;
        }
    }
    char local_100[256];
    sprintf(local_100, "ship_sail_damage%03d.dds", param_2 * 0x14);
    uint32_t* puVar4 = (uint32_t*)FUN_00533c78(0x20);
    if (puVar4 != nullptr) {
        FUN_00542700(FUN_00500850(), 0, 3, 1, 0);
        *puVar4 = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
        puVar4[7] = 0;
    }
    sprintf(local_100, "ship_sail_scorch%03d.dds", param_2 * 0x14);
    uint32_t* puVar5 = (uint32_t*)FUN_00533c78(0x20);
    if (puVar5 != nullptr) {
        FUN_00542700(FUN_00500850(), 0, 3, 1, 0);
        *puVar5 = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
        puVar5[7] = 0;
    }
    FUN_00542cb0(0, local_104);
    FUN_00542cb0(1, local_108);
    FUN_00542cb0(2, puVar4);
    FUN_00542cb0(3, puVar5);
LAB_004c0102:
    (*(void(**)(uint32_t, int))(*(uint32_t**)DAT_008c97c8))(param_1, -1);
}

// 0x4c0120 — observed shape
void FUN_004c0120(int* param_1, char param_2) {
    if (param_1 == nullptr) return;
    for (uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))()); puVar3 != nullptr; puVar3 = (uint32_t*)puVar3[1]) {
        if ((void*)puVar3 == &DAT_00727560) {
            int iVar6 = FUN_00449390(&DAT_00727560, param_1);
            int iVar4 = (int)FUN_00533db0(8);
            if (iVar4 != 0 && **(int**)(iVar4 + 0x2c) != 0) {
                iVar4 = *(int*)(**(int**)(iVar4 + 0x2c) + 4);
                if (iVar4 != 0 && FUN_004879c0(&DAT_00727520, iVar4) && FUN_004bf440((const char*)(uintptr_t)iVar4, (const char*)param_1[3])) {
                    param_2 = '\x01';
                }
            }
            if (*(int*)(iVar6 + 0xc0) < 1) return;
            uint32_t uVar7 = 0;
            bool bVar9 = *(int*)(iVar6 + 0xc0) == 0;
            bool bVar8 = false;
            do {
                uint32_t uVar5 = (bVar8 || bVar9) ? 0 : *(uint32_t*)(*(int*)(iVar6 + 0xb8) + uVar7 * 4);
                FUN_004c0120((int*)uVar5, param_2);
                uint32_t uVar1 = *(uint32_t*)(iVar6 + 0xc0);
                uVar7++;
                bVar8 = uVar1 < uVar7;
                bVar9 = uVar1 == uVar7;
            } while (!bVar9 && (int)uVar7 <= (int)uVar1);
            return;
        }
    }
    uint32_t* puVar3 = (uint32_t*)(*(uint32_t*(*)(void*))(*(void**)(*param_1 + 4))());
    if (puVar3 != nullptr) {
        while ((void*)puVar3 != &DAT_00727598) {
            puVar3 = (uint32_t*)puVar3[1];
            if (puVar3 == nullptr) return;
        }
        _stricmp((const char*)(uintptr_t)param_1[3], "hull:0");
        if (param_2 != '\0' || FUN_004bf530(param_1, 0) != 0) {
            (*(void(**)(int*, int))(*(uint32_t**)((char*)DAT_008c97c8 + 8)))(param_1, -1);
            return;
        }
    }
}
