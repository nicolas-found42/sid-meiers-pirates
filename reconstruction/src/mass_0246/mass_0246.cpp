#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* ExceptionList;
extern void* PTR_FUN_006c9ba0;
extern void* PTR_LAB_006c9b24;
extern void* LAB_006b9a08;
extern void* LAB_006b9a2b;
extern void* DAT_00727868;
extern uint32_t DAT_0072788c;
extern DWORD DAT_00727888;
extern LPCRITICAL_SECTION DAT_00727870;

extern void FUN_005edba0(void);
extern uint8_t FUN_006b5090(uint32_t param_1, uint32_t* param_2);
extern void* FUN_00533c78(uint32_t size);
extern void* FUN_005ec3c0(void);
extern uint8_t FUN_005ec2a0(uint32_t param_1);
extern void* FUN_005ece60(void* param_1);
extern void FUN_00545310(void* param_1, void* param_2);
extern void FUN_004b0b20(void);
extern void FUN_005c9a50(const char* fmt, void* arg);
extern void FUN_005e4780(void);
extern void operator_delete(void* ptr);

typedef void (*FUN_void_void_ptr)(void*);

// 0x5e8f40 — observed shape
void FUN_5e8f40(void* self) {
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    (void)savedExceptionList;
    uint32_t* self_dwords = reinterpret_cast<uint32_t*>(self);
    self_dwords[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9ba0);
    FUN_005edba0();
    self_dwords[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006c9b24);
    ExceptionList = savedExceptionList;
}

// 0x5e8f90 — observed shape
void FUN_5e8f90(int param_1, uint32_t* param_2) {
    const uint8_t* src = reinterpret_cast<const uint8_t*>(param_1);
    param_2[0] = *reinterpret_cast<const uint32_t*>(src + 0x61c);
    param_2[3] = *reinterpret_cast<const uint32_t*>(src + 0x628);
    param_2[6] = *reinterpret_cast<const uint32_t*>(src + 0x634);
    param_2[1] = *reinterpret_cast<const uint32_t*>(src + 0x620);
    param_2[4] = *reinterpret_cast<const uint32_t*>(src + 0x62c);
    param_2[7] = *reinterpret_cast<const uint32_t*>(src + 0x638);
    param_2[2] = *reinterpret_cast<const uint32_t*>(src + 0x624);
    param_2[5] = *reinterpret_cast<const uint32_t*>(src + 0x630);
    param_2[8] = *reinterpret_cast<const uint32_t*>(src + 0x63c);
    param_2[9] = *reinterpret_cast<const uint32_t*>(src + 0x640);
    if (param_2[0] < param_2[2]) {
        param_2[2] = param_2[0];
    }
    if (param_2[3] < param_2[5]) {
        param_2[5] = param_2[3];
    }
    if (param_2[6] < param_2[8]) {
        param_2[8] = param_2[6];
    }
}

// 0x5e9020 — observed shape
uint8_t FUN_5e9020(uint32_t param_1) {
    uint32_t uVar1 = param_1;
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    uint8_t cVar2 = FUN_006b5090(param_1, &param_1);
    if (cVar2 == 0) {
        ExceptionList = savedExceptionList;
        return 0;
    }
    uint32_t uVar6 = 0;
    if (param_1 != 0) {
        do {
            int iVar3 = reinterpret_cast<int>(FUN_00533c78(0x1c));
            void* uVar5 = nullptr;
            if (iVar3 != 0) {
                uVar5 = FUN_005ec3c0();
            }
            cVar2 = FUN_005ec2a0(uVar1);
            if (cVar2 == 0) {
                ExceptionList = savedExceptionList;
                return 0;
            }
            void* uVar4 = FUN_005ece60(uVar5);
            FUN_00545310(uVar4, uVar5);
            uVar6 = uVar6 + 1;
        } while (uVar6 < param_1);
    }
    ExceptionList = savedExceptionList;
    return 1;
}

// 0x5e90f0 — observed shape
// NEEDS_MANUAL: large SEH-managed vector resize with refcounted element releases; structure preserved but exception scopes simplified.
void FUN_5e90f0(void* self, uint32_t param_1) {
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    auto getU32 = [&](uint32_t off) -> uint32_t { return *reinterpret_cast<uint32_t*>(base + off); };
    auto setU32 = [&](uint32_t off, uint32_t v) { *reinterpret_cast<uint32_t*>(base + off) = v; };
    void* savedExceptionList = ExceptionList;
    if (param_1 != getU32(8)) {
        ExceptionList = nullptr;
        if (param_1 < getU32(0xc)) {
            uint32_t uVar9 = param_1;
            do {
                int* piVar2 = reinterpret_cast<int*>(*(int*)(base + 4) + uVar9 * 4);
                if (*piVar2 != 0) {
                    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(*piVar2);
                    if (puVar4 != nullptr) {
                        int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            (**(code**)(*puVar4))(1);
                        }
                        *piVar2 = 0;
                    }
                    setU32(0x10, getU32(0x10) + (uint32_t)-1);
                }
                uVar9 = uVar9 + 1;
            } while (uVar9 < getU32(0xc));
            setU32(0xc, param_1);
        }
        void* pvVar5 = *reinterpret_cast<void**>(base + 4);
        setU32(8, param_1);
        if (param_1 == 0) {
            setU32(4, 0);
        } else {
            uint32_t* puVar8 = reinterpret_cast<uint32_t*>(FUN_00533c78(param_1 * 4 + 4));
            uint32_t* puVar10 = nullptr;
            if (puVar8 != nullptr) {
                puVar10 = puVar8 + 1;
                *puVar8 = param_1;
                // _eh_vector_constructor_iterator_(puVar10,4,param_1,LAB_004c2970,FUN_005e4780);
            }
            uint32_t uVar9 = 0;
            setU32(4, reinterpret_cast<uint32_t>(puVar10));
            if (getU32(0xc) != 0) {
                do {
                    int iVar6 = *(int*)(base + 4);
                    int iVar3 = (int)(uVar9 * 4);
                    uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(iVar6 + iVar3);
                    if (puVar4 != *reinterpret_cast<uint32_t**>((int)pvVar5 + uVar9 * 4)) {
                        if (puVar4 != nullptr) {
                            int* piVar2 = reinterpret_cast<int*>(puVar4 + 1);
                            *piVar2 = *piVar2 + -1;
                            if (*piVar2 == 0) {
                                (**(code**)(*puVar4))(1);
                            }
                        }
                        int iVar7 = *(int*)((int)pvVar5 + iVar3);
                        *(int*)(iVar6 + iVar3) = iVar7;
                        if (iVar7 != 0) {
                            *(int*)(iVar7 + 4) = *(int*)(iVar7 + 4) + 1;
                        }
                    }
                    uVar9 = uVar9 + 1;
                } while (uVar9 < getU32(0xc));
            }
            uVar9 = getU32(0xc);
            if (uVar9 < getU32(8)) {
                do {
                    int iVar3 = *(int*)(base + 4);
                    uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(iVar3 + uVar9 * 4);
                    if (puVar4 != nullptr) {
                        int* piVar2 = reinterpret_cast<int*>(puVar4 + 1);
                        *piVar2 = *piVar2 + -1;
                        if (*piVar2 == 0) {
                            (**(code**)(*puVar4))(1);
                        }
                        *(uint32_t*)(iVar3 + uVar9 * 4) = 0;
                    }
                    uVar9 = uVar9 + 1;
                } while (uVar9 < getU32(8));
            }
        }
        if (pvVar5 != nullptr) {
            // _eh_vector_destructor_iterator_(pvVar5,4,*(int*)((int)pvVar5 + -4),FUN_005e4780);
            // operator_delete__((void*)((int)pvVar5 + -4));
        }
    }
    ExceptionList = savedExceptionList;
}

// 0x5e92a0 — observed shape
uint32_t* FUN_5e92a0(void) {
    DWORD DVar1 = GetCurrentThreadId();
    if (DAT_00727888 != DVar1) {
        EnterCriticalSection(&DAT_00727870);
        DAT_00727888 = GetCurrentThreadId();
    }
    DAT_0072788c = DAT_0072788c + 1;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(DAT_00727868);
    if (DAT_00727868 == nullptr) {
        FUN_004b0b20();
        puVar2 = reinterpret_cast<uint32_t*>(DAT_00727868);
    }
    DAT_00727868 = reinterpret_cast<void*>(*puVar2);
    puVar2[2] = 0;
    puVar2[0] = 0;
    puVar2[1] = 0;
    DVar1 = GetCurrentThreadId();
    if ((DAT_00727888 == DVar1) && (DAT_0072788c = DAT_0072788c + (uint32_t)-1, DAT_0072788c == 0)) {
        DAT_00727888 = 0;
        LeaveCriticalSection(&DAT_00727870);
    }
    return puVar2;
}

extern void* PTR_FUN_006c9b9c;
extern void* PTR_FUN_006c9b20;
extern void* PTR_LAB_006fd148;
extern int32_t DAT_00727444;
extern void FUN_005e1490(void);
extern void FUN_005ec630(void);
extern void FUN_005ec210(void);
extern void FUN_005e8bf0(void);
extern void FUN_005ecfc0(void);
extern void* FUN_006b3830(void);
extern void* FUN_006b3c00(void);
extern int FUN_005ed050(void);
extern int FUN_005e5b30(void);
extern void FUN_00531830(uint32_t param_1);
extern void FUN_005ec420(void);
extern uint32_t FUN_005dbe30(void);
extern uint32_t FUN_005eceb0(void);
extern uint32_t FUN_005ece60(void);
extern uint32_t FUN_005d5fd0(void);
extern uint32_t FUN_005dbd60(void);
extern uint32_t FUN_005dbd70(void);
extern void* FUN_006b38d0(void);
extern void FUN_006b3790(uint32_t index, int* obj);
extern void FUN_006b38a0(int* obj);
extern void FUN_005e9330(void);
extern void FUN_005e8f40(void);
extern void FUN_005e90f0(void* self, uint32_t param_1);
extern void FUN_00581300(uint32_t param_1, uint32_t** param_2);
extern uint8_t FUN_005ec910(uint32_t param_1);
extern int FUN_005ec590(void);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t param_1, int* param_2);

// 0x5e9330 — observed shape
// NEEDS_MANUAL: non-contiguous SEH destructor with goto-merged loops over shader tables; structure preserved.
void FUN_5e9330(void* self) {
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    auto getU32 = [&](uint32_t off) -> uint32_t { return *reinterpret_cast<uint32_t*>(base + off); };
    auto setU32 = [&](uint32_t off, uint32_t v) { *reinterpret_cast<uint32_t*>(base + off) = v; };
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    setU32(0, reinterpret_cast<uint32_t>(&PTR_FUN_006c9b9c));
    FUN_005c9a50("Killing NSBShader %s\n", reinterpret_cast<void*>(*(uint32_t*)(base + 8)));
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(getU32(0x28 * 4));
    if (puVar4 != nullptr) {
        int* piVar5 = reinterpret_cast<int*>(puVar4 + 1);
        *piVar5 = *piVar5 + -1;
        if (*piVar5 == 0) {
            (**(code**)(*puVar4))(1);
        }
        setU32(0x28 * 4, 0);
    }
    operator_delete(reinterpret_cast<void*>(getU32(8)));
    operator_delete(reinterpret_cast<void*>(getU32(12)));
    uint32_t uVar2 = 0;
    int* piVar5 = nullptr;
    if (getU32(0x1e * 4) != 0) {
        piVar5 = reinterpret_cast<int*>(getU32(0x1f * 4));
        do {
            if (*piVar5 != 0) {
                piVar5 = reinterpret_cast<int*>((reinterpret_cast<int**>(getU32(0x1f * 4)))[uVar2]);
                goto joined_loop;
            }
            uVar2 = uVar2 + 1;
            piVar5 = piVar5 + 1;
        } while (uVar2 < getU32(0x1e * 4));
    }
    piVar5 = nullptr;
joined_loop:
    do {
        if (piVar5 == nullptr) {
            FUN_005e1490();
            uVar2 = 0;
            if (getU32(0x25 * 4) != 0) {
                do {
                    void* pvVar1 = *reinterpret_cast<void**>(getU32(0x23 * 4) + uVar2 * 4);
                    if (pvVar1 != nullptr) {
                        FUN_005ec630();
                        operator_delete(pvVar1);
                        if (uVar2 < getU32(0x24 * 4)) {
                            if (uVar2 < getU32(0x25 * 4)) {
                                if (*(int*)(getU32(0x23 * 4) + uVar2 * 4) != 0) {
                                    setU32(0x26 * 4, getU32(0x26 * 4) + (uint32_t)-1);
                                }
                            } else {
                                setU32(0x25 * 4, uVar2 + 1);
                            }
                            *(uint32_t*)(getU32(0x23 * 4) + uVar2 * 4) = 0;
                        }
                    }
                    uVar2 = uVar2 + 1;
                } while (uVar2 < getU32(0x25 * 4));
            }
            uVar2 = 0;
            if (getU32(0x25 * 4) != 0) {
                do {
                    *(uint32_t*)(getU32(0x23 * 4) + uVar2 * 4) = 0;
                    uVar2 = uVar2 + 1;
                } while (uVar2 < getU32(0x25 * 4));
            }
            setU32(0x25 * 4, 0);
            setU32(0x26 * 4, 0);
            puVar4 = reinterpret_cast<uint32_t*>(getU32(0x28 * 4));
            if (puVar4 != nullptr) {
                piVar5 = reinterpret_cast<int*>(puVar4 + 1);
                *piVar5 = *piVar5 + -1;
                if (*piVar5 == 0) {
                    (**(code**)(*puVar4))(1);
                }
            }
            setU32(0x22 * 4, reinterpret_cast<uint32_t>(&PTR_FUN_006c9b20));
            operator_delete(reinterpret_cast<void*>(getU32(0x23 * 4)));
            FUN_005e8bf0();
            FUN_005ecfc0();
            FUN_005ecfc0();
            puVar4 = reinterpret_cast<uint32_t*>(getU32(0x12 * 4));
            if (puVar4 != nullptr) {
                piVar5 = reinterpret_cast<int*>(puVar4 + 1);
                *piVar5 = *piVar5 + -1;
                if (*piVar5 == 0) {
                    (**(code**)(*puVar4))(1);
                }
            }
            setU32(0, reinterpret_cast<uint32_t>(&PTR_LAB_006fd148));
            DAT_00727444 = DAT_00727444 + -1;
            ExceptionList = savedExceptionList;
            return;
        }
        int* piVar6 = reinterpret_cast<int*>(*piVar5);
        void* pvVar1 = reinterpret_cast<void*>(piVar5[2]);
        if (piVar6 == nullptr) {
            int iVar3 = (**(code**)(getU32(0x1d * 4) + 4))(piVar5[1]);
            uVar2 = (uint32_t)(iVar3 + 1);
            if (uVar2 < getU32(0x1e * 4)) {
                uint32_t* puVar4b = reinterpret_cast<uint32_t*>(getU32(0x1f * 4) + uVar2 * 4);
                do {
                    piVar6 = reinterpret_cast<int*>(*puVar4b);
                    if (piVar6 != nullptr) goto LAB_005e9410;
                    uVar2 = uVar2 + 1;
                    puVar4b = puVar4b + 1;
                } while (uVar2 < getU32(0x1e * 4));
            }
            piVar6 = nullptr;
        }
    LAB_005e9410:
        piVar5 = piVar6;
        if (pvVar1 != nullptr) {
            FUN_005ec210();
            operator_delete(pvVar1);
        }
    } while (true);
}

// 0x5e9570 — observed shape
// NEEDS_MANUAL: non-contiguous SEH initialization with many virtual calls and enumeration loops.
int FUN_5e9570(void* self) {
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    auto getU32 = [&](uint32_t off) -> uint32_t { return *reinterpret_cast<uint32_t*>(base + off); };
    auto setU32 = [&](uint32_t off, uint32_t v) { *reinterpret_cast<uint32_t*>(base + off) = v; };
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    int iVar2 = (int)getU32(0xa0);
    if (iVar2 == 0) {
        iVar2 = (int)FUN_00533c78(100);
        uint32_t* puVar3 = nullptr;
        if (iVar2 == 0) {
            puVar3 = nullptr;
        } else {
            puVar3 = reinterpret_cast<uint32_t*>(FUN_006b3830());
        }
        uint32_t* puVar1 = reinterpret_cast<uint32_t*>(getU32(0xa0));
        if (puVar1 != puVar3) {
            if (puVar1 != nullptr) {
                int* piVar5 = reinterpret_cast<int*>(puVar1 + 1);
                *piVar5 = *piVar5 + -1;
                if (*piVar5 == 0) {
                    (**(code**)(*puVar1))(1);
                }
            }
            setU32(0xa0, reinterpret_cast<uint32_t>(puVar3));
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
        (**(code**)(**(int**)(base + 0xa0) + 0xc))(getU32(8));
        (**(code**)(**(int**)(base + 0xa0) + 0x10))(getU32(0xc));
        (**(code**)(**(int**)(base + 0xa0) + 0x44))(getU32(0x2c));
        (**(code**)(**(int**)(base + 0xa0) + 0x44))(getU32(0x30));
        (**(code**)(**(int**)(base + 0xa0) + 0x48))(getU32(0x34));
        (**(code**)(**(int**)(base + 0xa0) + 0x48))(getU32(0x38));
        (**(code**)(**(int**)(base + 0xa0) + 0x4c))(getU32(0x3c));
        (**(code**)(**(int**)(base + 0xa0) + 0x4c))(getU32(0x40));
        (**(code**)(**(int**)(base + 0xa0) + 0x50))(getU32(0x44));
        iVar2 = FUN_005ed050();
        while (iVar2 != 0) {
            int iVar4 = (int)FUN_00533c78(0xdc);
            int* piVar5 = nullptr;
            if (iVar4 == 0) {
                piVar5 = nullptr;
            } else {
                piVar5 = reinterpret_cast<int*>(FUN_006b3c00());
            }
            (**(code**)(*piVar5 + 0x1c))(iVar2);
            FUN_006b38a0(piVar5);
            iVar2 = FUN_005e5b30();
        }
        FUN_00531830(getU32(0x98));
        uint32_t local_10 = 0;
        if (*(int*)(base + 0x94) != 0) {
            do {
                uint32_t* puVar3b = *reinterpret_cast<uint32_t**>(*(int*)(base + 0x8c) + local_10 * 4);
                if (puVar3b != nullptr) {
                    FUN_005ec420();
                    if (local_10 == 0) {
                        int iVar2b = **(int**)(base + 0xa0);
                        uint32_t uVar6 = FUN_005dbe30();
                        (**(code**)(iVar2b + 100))(uVar6);
                        iVar2b = **(int**)(base + 0xa0);
                        uVar6 = FUN_005eceb0();
                        (**(code**)(iVar2b + 0x68))(uVar6);
                    }
                    int iVar2c = (int)FUN_00533c78(0x34);
                    int* piVar5 = nullptr;
                    if (iVar2c == 0) {
                        piVar5 = nullptr;
                    } else {
                        piVar5 = reinterpret_cast<int*>(FUN_006b38d0());
                    }
                    (**(code**)(*piVar5 + 0xc))(*puVar3b);
                    (**(code**)(*piVar5 + 0x10))(puVar3b[1]);
                    int iVar2d = *piVar5;
                    uint32_t uVar6 = FUN_005ece60();
                    (**(code**)(iVar2d + 0x44))(uVar6);
                    iVar2d = *piVar5;
                    uVar6 = FUN_005d5fd0();
                    (**(code**)(iVar2d + 0x48))(uVar6);
                    iVar2d = *piVar5;
                    uVar6 = FUN_005dbd60();
                    (**(code**)(iVar2d + 0x4c))(uVar6);
                    iVar2d = *piVar5;
                    uVar6 = FUN_005dbd70();
                    (**(code**)(iVar2d + 0x50))(uVar6);
                    iVar2d = *piVar5;
                    uVar6 = FUN_005dbe30();
                    (**(code**)(iVar2d + 100))(uVar6);
                    iVar2d = *piVar5;
                    uVar6 = FUN_005eceb0();
                    (**(code**)(iVar2d + 0x68))(uVar6);
                    FUN_006b3790(local_10, piVar5);
                }
                local_10 = local_10 + 1;
            } while (local_10 < *(uint32_t*)(base + 0x94));
        }
        iVar2 = (int)getU32(0xa0);
    }
    ExceptionList = savedExceptionList;
    return iVar2;
}

// 0x5e9840 — observed shape
void FUN_5e9840(void* self, uint8_t param_1) {
    FUN_5e8f40(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e9860 — observed shape
uint8_t FUN_5e9860(void* self, uint32_t param_1) {
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    auto getU32 = [&](uint32_t off) -> uint32_t { return *reinterpret_cast<uint32_t*>(base + off); };
    auto setU32 = [&](uint32_t off, uint32_t v) { *reinterpret_cast<uint32_t*>(base + off) = v; };
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    uint32_t local_14 = 0;
    uint8_t cVar1 = FUN_006b5090(param_1, &local_14);
    if (cVar1 == 0) {
        ExceptionList = savedExceptionList;
        return 0;
    }
    uint32_t uVar4 = 0;
    if (local_14 != 0) {
        do {
            int local_10 = (int)FUN_00533c78(0x40);
            if (local_10 == 0) {
                local_10 = 0;
            } else {
                local_10 = FUN_005ec590();
            }
            cVar1 = FUN_005ec910(param_1);
            if (cVar1 == 0) {
                ExceptionList = savedExceptionList;
                return 0;
            }
            int iVar2 = FUN_005ec420();
            if (iVar2 != 0) {
                uint32_t uVar3 = FUN_005ece60();
                if (uVar3 < getU32(0x2c)) {
                    setU32(0x2c, uVar3);
                }
                if (getU32(0x30) < uVar3) {
                    setU32(0x30, uVar3);
                }
                uVar3 = FUN_005d5fd0();
                if (uVar3 < getU32(0x34)) {
                    setU32(0x34, uVar3);
                }
                if (getU32(0x38) < uVar3) {
                    setU32(0x38, uVar3);
                }
                uVar3 = FUN_005dbd60();
                if (uVar3 < getU32(0x3c)) {
                    setU32(0x3c, uVar3);
                }
                if (getU32(0x40) < uVar3) {
                    setU32(0x40, uVar3);
                }
                uVar3 = FUN_005dbd70();
                setU32(0x44, getU32(0x44) | uVar3);
            }
            if (getU32(0x90) <= uVar4) {
                FUN_006b34a0((int)getU32(0x9c) + (int)uVar4);
            }
            FUN_005606f0(uVar4, &local_10);
            uVar4 = uVar4 + 1;
        } while (uVar4 < local_14);
    }
    ExceptionList = savedExceptionList;
    return 1;
}

// 0x5e99c0 — observed shape
void FUN_5e99c0(void* self, uint32_t param_1, uint32_t* param_2) {
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    auto getU32 = [&](uint32_t off) -> uint32_t { return *reinterpret_cast<uint32_t*>(base + off); };
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    uint32_t* puVar2 = param_2;
    if (puVar2 != nullptr) {
        puVar2[1] = puVar2[1] + 1;
    }
    if (getU32(0x78) <= param_1) {
        FUN_5e90f0(reinterpret_cast<void*>(getU32(0x84) + param_1 * 4), param_1);
    }
    FUN_00581300(param_1, &param_2);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (**(code**)(*puVar2))(1);
        }
    }
    ExceptionList = savedExceptionList;
}

// 0x5e9a50 — observed shape
void FUN_5e9a50(void* self, uint8_t param_1) {
    FUN_5e9330(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

extern uint32_t DAT_007187cc;
extern void* PTR_FUN_006c9b30;
extern void* PTR_FUN_006c9be4;
extern void* PTR_LAB_006c9e68;
extern void* PTR_FUN_006c9e74;
extern uint8_t FUN_006b5020(uint32_t param_1, void* param_2);
extern void* FUN_005edf90(void);
extern void FUN_0051ac30(void* param_1);
extern uint8_t FUN_005ed070(uint32_t param_1);
extern int FUN_005e8a70(int param_1, uint32_t* param_2);
extern void* FUN_0057eca0(void);
extern void FUN_005c8c10(void* param_1);
extern void FUN_005477c0(int param_1, int param_2, const char* fmt, uint32_t arg);
extern void FUN_005e8d70(void);
extern void FUN_005ed170(void);
extern void* thunk_FUN_004fcaa0(uint32_t param_1, uint32_t param_2, uint32_t param_3);

// 0x5e9a70 — observed shape
bool FUN_5e9a70(void* self, uint32_t param_1) {
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t iVar3 = param_1;
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    uint32_t local_14 = 0;
    uint8_t cVar4 = FUN_006b5090(iVar3, &local_14);
    if ((cVar4 == 0) || (local_14 != 0x62736e)) {
        ExceptionList = savedExceptionList;
        return false;
    }
    cVar4 = FUN_006b5090(iVar3, &DAT_007187cc);
    if (cVar4 == 0) {
        ExceptionList = savedExceptionList;
        return false;
    }
    if (DAT_007187cc < 0x10007) {
        cVar4 = FUN_006b5020(iVar3, base + 8);
        if (cVar4 != 0) {
            cVar4 = FUN_006b5020(iVar3, base + 0xc);
            if (cVar4 != 0) {
                if (0x10005 < DAT_007187cc) {
                    cVar4 = FUN_006b5090(iVar3, &local_14);
                    if (cVar4 == 0) {
                        ExceptionList = savedExceptionList;
                        return false;
                    }
                    if (local_14 == 0) {
                        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 0x48);
                        if (puVar2 != nullptr) {
                            int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                            *piVar1 = *piVar1 + -1;
                            if (*piVar1 == 0) {
                                (**(code**)(*puVar2))(1);
                            }
                            *reinterpret_cast<uint32_t*>(base + 0x48) = 0;
                        }
                    } else {
                        int local_10 = static_cast<int>(
                            reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
                        void* uVar5 = (local_10 == 0) ? nullptr : FUN_005edf90();
                        FUN_0051ac30(uVar5);
                        cVar4 = (**(code**)(**(int**)(base + 0x48) + 8))(iVar3);
                        if (cVar4 == 0) {
                            ExceptionList = savedExceptionList;
                            return false;
                        }
                    }
                }
                cVar4 = FUN_005ed070(iVar3);
                if (cVar4 != 0) {
                    cVar4 = FUN_005ed070(iVar3);
                    if (cVar4 != 0) {
                        cVar4 = FUN_005e9020(iVar3);
                        if (cVar4 != 0) {
                            cVar4 = FUN_005e9860(self, iVar3);
                            ExceptionList = savedExceptionList;
                            return cVar4 != 0;
                        }
                    }
                }
            }
        }
    }
    ExceptionList = savedExceptionList;
    return false;
}

// 0x5e9bf0 — observed shape
int FUN_5e9bf0(void* self, uint32_t param_1) {
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    uint32_t bounds[10];
    int iVar8 = 0;
    bool bVar2 = false;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    FUN_5e8f90(static_cast<int>(param_1), bounds);
    void* local_40 = nullptr;
    void* local_3c = nullptr;
    FUN_005edba0();
    uVar5 = *reinterpret_cast<uint32_t*>(base + 0x94);
    uVar7 = 0;
    if (uVar5 != 0) {
        do {
            iVar8 = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(base + 0x8c) + uVar7 * 4);
            void* puVar4 = local_40;
            if (iVar8 != 0) {
                int iVar3 = FUN_005e8a70(iVar8, bounds);
                if (iVar3 != 0) {
                    do {
                        if (puVar4 == nullptr) {
                            puVar4 = FUN_0057eca0();
                            reinterpret_cast<uint32_t*>(puVar4)[2] =
                                static_cast<uint32_t>(iVar8);
                            *reinterpret_cast<uint32_t*>(puVar4) = 0;
                            reinterpret_cast<uint32_t*>(puVar4)[1] =
                                static_cast<uint32_t>(
                                    reinterpret_cast<uintptr_t>(local_3c));
                            if (local_3c == nullptr) {
                                local_40 = puVar4;
                            } else {
                                *reinterpret_cast<uint32_t*>(local_3c) =
                                    static_cast<uint32_t>(
                                        reinterpret_cast<uintptr_t>(puVar4));
                            }
                            local_3c = puVar4;
                            break;
                        }
                        int* piVar1 = reinterpret_cast<int*>(puVar4) + 2;
                        puVar4 = reinterpret_cast<void*>(
                            *reinterpret_cast<uint32_t*>(puVar4));
                    } while (*piVar1 != iVar8);
                }
            }
            uVar7 = uVar7 + 1;
        } while (uVar7 < uVar5);
    }
    void* puVar4 = local_40;
    if (local_40 == nullptr) {
joined_r0x005e9d74:
        while (local_40 != nullptr) {
            puVar4 = reinterpret_cast<void*>(
                *reinterpret_cast<uint32_t*>(local_40));
            FUN_005c8c10(local_40);
            local_40 = puVar4;
        }
        if (bVar2) {
            ExceptionList = savedExceptionList;
            return iVar8;
        }
        FUN_005477c0(1, 0, "* ERROR: Unable to find usable implementation for %s\n",
                     *reinterpret_cast<uint32_t*>(base + 8));
        ExceptionList = savedExceptionList;
        return 0;
    }
    do {
        iVar8 = reinterpret_cast<uint32_t*>(puVar4)[2];
        puVar4 = reinterpret_cast<void*>(*reinterpret_cast<uint32_t*>(puVar4));
        if (iVar8 != 0) {
            FUN_005ec420();
            uVar5 = FUN_005ece60();
            if (uVar5 == 0) {
                uVar5 = 0xffff0000;
            }
            uVar7 = FUN_005d5fd0();
            if (uVar7 == 0) {
                uVar7 = 0xfffe0000;
            }
            uVar6 = FUN_005dbd60();
            if (uVar6 == 0) {
                uVar6 = 0xfffe0000;
            }
            if ((uVar5 <= bounds[2]) && (bounds[1] <= uVar5) &&
                (uVar7 <= bounds[5]) && (bounds[4] <= uVar7) &&
                (uVar6 <= bounds[8]) && (bounds[7] <= uVar6)) {
                bVar2 = true;
                goto joined_r0x005e9d74;
            }
        }
        if (puVar4 == nullptr) goto joined_r0x005e9d74;
    } while (true);
}

// 0x5e9e20 — observed shape
void FUN_5e9e20(void* self, uint8_t param_1) {
    FUN_005e8d70();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e9e40 — observed shape
void FUN_5e9e40(void* self) {
    uint32_t* obj = reinterpret_cast<uint32_t*>(self);
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_LAB_006fd148));
    obj[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c9b9c));
    obj[2] = 0;
    obj[3] = 0;
    obj[4] = 0;
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = 0;
    obj[8] = 0;
    obj[9] = 0;
    obj[10] = 0;
    obj[0xb] = 0xffffffff;
    obj[0xc] = 0;
    obj[0xd] = 0xffffffff;
    obj[0xe] = 0;
    obj[0xf] = 0xffffffff;
    obj[0x10] = 0;
    obj[0x11] = 0;
    obj[0x12] = 0;
    FUN_005ed170();
    FUN_005ed170();
    obj[0x1d] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c9b30));
    obj[0x1e] = 0x25;
    obj[0x20] = 0;
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x94));
    obj[0x1f] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    for (uint32_t uVar2 = obj[0x1e] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(obj) + 0x84) = 1;
    obj[0x1d] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c9be4));
    obj[0x22] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c9b20));
    obj[0x24] = 0;
    obj[0x27] = 1;
    obj[0x25] = 0;
    obj[0x26] = 0;
    obj[0x23] = 0;
    obj[0x28] = 0;
    FUN_005e1490();
    uint32_t uVar2 = 0;
    if (obj[0x25] != 0) {
        do {
            *reinterpret_cast<uint32_t*>(obj[0x23] + uVar2 * 4) = 0;
            uVar2 = uVar2 + 1;
        } while (uVar2 < obj[0x25]);
    }
    obj[0x25] = 0;
    obj[0x26] = 0;
    ExceptionList = savedExceptionList;
}

// 0x5ea280 — observed shape
uint8_t FUN_5ea280(void* self, uint32_t param_1) {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(
        thunk_FUN_004fcaa0(param_1, 0, 0x8000));
    if (puVar2 == nullptr) {
        return 0;
    }
    uint8_t uVar1 = FUN_5e9a70(
        self, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar2)));
    (**(code**)(*puVar2))(1);
    return uVar1;
}

// 0x5ea2f0 — observed shape
void FUN_5ea2f0(void* self) {
    uint32_t* obj = reinterpret_cast<uint32_t*>(self);
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_LAB_006c9e68));
}

// 0x5ea300 — observed shape
void FUN_5ea300(void* self) {
    uint32_t* obj = reinterpret_cast<uint32_t*>(self);
    void* savedExceptionList = ExceptionList;
    ExceptionList = nullptr;
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c9e74));
    FUN_005edba0();
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_LAB_006c9e68));
    ExceptionList = savedExceptionList;
}

// 0x5ea370 — observed shape
void FUN_5ea370(void* self, uint8_t param_1) {
    FUN_5ea300(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5ea390 — observed shape
int FUN_5ea390(void* self) {
    int* obj = reinterpret_cast<int*>(self);
    int* piVar1 = reinterpret_cast<int*>(obj[2]);
    int iVar2 = 0;
    obj[0] = static_cast<int>(reinterpret_cast<intptr_t>(piVar1));
    if (piVar1 != nullptr) {
        obj[0] = *piVar1;
        iVar2 = piVar1[2];
    }
    return iVar2;
}
