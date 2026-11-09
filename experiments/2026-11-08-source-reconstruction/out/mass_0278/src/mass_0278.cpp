#include <cstdint>
#include <cstdarg>
#include <cstddef>
#include <windows.h>

extern int FUN_005f7fa4(void*, int, void*);
extern void FUN_006338c7();
extern void FUN_0065d63f(void*);
extern int FUN_0065d97c(void*, int, int, int);
extern int FUN_0065d9d5(void*, int, void*, void*);
extern void FUN_0060fcd3(int, int, int, void*, char*);
extern void FUN_0060fd9a(int, int, int, void*, char*);
extern int FUN_0061449c(int, int, int, int, int, int, void*, int, int*);
extern int FUN_006147e4(int, double*);
extern int FUN_00533c78(int);
extern void operator_delete(void*);
extern int FUN_00614343(int);
extern int FUN_0065da35(uint32_t, uint32_t, uint32_t);
extern int FUN_0065d412(int, int);
extern int FUN_0065cc6f(int, int);
extern int FUN_0065cea4();
extern int _finite(double);
extern int _stricmp(const char*, const char*);
extern int _vsnprintf(char*, size_t, const char*, va_list);
extern void* DAT_006c7974;
extern void* DAT_006e0430;

// 0x6154ae — observed shape
int FUN_006154ae(void* self, int param_1, uint32_t param_2) {
    uint32_t uVar3 = 0;
    if (param_2 != 0) {
        do {
            uint32_t uVar1 = *(uint32_t*)(param_1 + uVar3 * 4);
            int iVar2;
            if (uVar1 < *(uint32_t*)(*(int*)(*(int*)((char*)self + 8)) + 8)) {
                iVar2 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + uVar1 * 4);
            } else {
                iVar2 = 0;
            }
            if ((iVar2 == 0) || (*(int*)(iVar2 + 0x68) == 0)) {
                return 0;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < param_2);
    }
    return 1;
}

// 0x6154f3 — observed shape
bool FUN_006154f3(void* self, int* param_1, int* param_2, uint32_t param_3, uint32_t param_4) {
    bool bVar4;
    if (param_2 == (int*)0x2) {
        bVar4 = false;
        if (param_3 * param_4 != 0) {
            uint32_t local_c = 0;
            if (param_4 != 0) {
                int* piVar3 = param_1;
                do {
                    int iVar1 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + *piVar3 * 4);
                    int* param_2b = (int*)0x0;
                    if (param_3 != 0) {
                        int* local_8 = piVar3;
                        do {
                            int iVar2 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + *local_8 * 4);
                            if (*(int*)(iVar1 + 4) != *(int*)(iVar2 + 4)) goto LAB_00615679;
                            if ((*(uint8_t*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x10) + *(int*)(iVar1 + 4) * 4) + 4) & 0x40) == 0) {
                                bVar4 = *(int*)(iVar1 + 0x48) == *(int*)(iVar2 + 0x48);
                            } else {
                                if (((uint32_t)param_2b >> 2) + *(int*)(iVar1 + 0xc) != *(int*)(iVar2 + 0xc)) goto LAB_00615679;
                                bVar4 = ((uint32_t)param_2b & 3) + *(int*)(iVar1 + 0x10) == *(int*)(iVar2 + 0x10);
                            }
                            if (!bVar4) goto LAB_00615679;
                            param_2b = (int*)((int)param_2b + 1);
                            local_8 = local_8 + param_4;
                        } while ((int)param_2b < (int)param_3);
                    }
                    local_c = local_c + 1;
                    piVar3 = piVar3 + 1;
                } while (local_c < param_4);
            }
            local_c = 0;
            if (param_3 != 0) {
                int* piVar3 = param_1;
                do {
                    int iVar1 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + *piVar3 * 4);
                    int* param_1b = (int*)0x0;
                    if (param_4 != 0) {
                        int* param_2c = piVar3;
                        do {
                            int iVar2 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + *param_2c * 4);
                            if (*(int*)(iVar1 + 4) != *(int*)(iVar2 + 4)) {
                                return false;
                            }
                            if ((*(uint8_t*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x10) + *(int*)(iVar1 + 4) * 4) + 4) & 0x40) == 0) {
                                bVar4 = *(int*)(iVar1 + 0x48) == *(int*)(iVar2 + 0x48);
                            } else {
                                if (((uint32_t)param_1b >> 2) + *(int*)(iVar1 + 0xc) != *(int*)(iVar2 + 0xc)) {
                                    return false;
                                }
                                bVar4 = ((uint32_t)param_1b & 3) + *(int*)(iVar1 + 0x10) == *(int*)(iVar2 + 0x10);
                            }
                            if (!bVar4) {
                                return false;
                            }
                            param_1b = (int*)((int)param_1b + 1);
                            param_2c = param_2c + 1;
                        } while ((int)param_1b < (int)param_4);
                    }
                    local_c = local_c + 1;
                    piVar3 = piVar3 + param_4;
                } while (local_c < param_3);
            }
        LAB_00615679:
            bVar4 = true;
        }
    } else {
        bVar4 = param_3 == 1;
    }
    return bVar4;
}

// 0x615687 — observed shape
bool FUN_00615687(void* self, int* param_1, int* param_2, uint32_t param_3, uint32_t param_4) {
    bool bVar4;
    if (param_2 == (int*)0x2) {
        bVar4 = false;
        if (param_3 * param_4 != 0) {
            uint32_t local_c = 0;
            if (param_3 != 0) {
                int* piVar3 = param_1;
                do {
                    int iVar1 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + *piVar3 * 4);
                    int* param_2b = (int*)0x0;
                    if (param_4 != 0) {
                        int* local_8 = piVar3;
                        do {
                            int iVar2 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + *local_8 * 4);
                            if (*(int*)(iVar1 + 4) != *(int*)(iVar2 + 4)) goto LAB_0061580f;
                            if ((*(uint8_t*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x10) + *(int*)(iVar1 + 4) * 4) + 4) & 0x40) == 0) {
                                bVar4 = *(int*)(iVar1 + 0x48) == *(int*)(iVar2 + 0x48);
                            } else {
                                if (((uint32_t)param_2b >> 2) + *(int*)(iVar1 + 0xc) != *(int*)(iVar2 + 0xc)) goto LAB_0061580f;
                                bVar4 = ((uint32_t)param_2b & 3) + *(int*)(iVar1 + 0x10) == *(int*)(iVar2 + 0x10);
                            }
                            if (!bVar4) goto LAB_0061580f;
                            param_2b = (int*)((int)param_2b + 1);
                            local_8 = local_8 + 1;
                        } while ((int)param_2b < (int)param_4);
                    }
                    local_c = local_c + 1;
                    piVar3 = piVar3 + param_4;
                } while (local_c < param_3);
            }
            local_c = 0;
            if (param_4 != 0) {
                int* piVar3 = param_1;
                do {
                    int iVar1 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + *piVar3 * 4);
                    int* param_1b = (int*)0x0;
                    if (param_3 != 0) {
                        int* param_2c = piVar3;
                        do {
                            int iVar2 = *(int*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x14) + *param_2c * 4);
                            if (*(int*)(iVar1 + 4) != *(int*)(iVar2 + 4)) {
                                return false;
                            }
                            if ((*(uint8_t*)(*(int*)(*(int*)(*(int*)((char*)self + 8)) + 0x10) + *(int*)(iVar1 + 4) * 4) + 4) & 0x40) == 0) {
                                bVar4 = *(int*)(iVar1 + 0x48) == *(int*)(iVar2 + 0x48);
                            } else {
                                if (((uint32_t)param_1b >> 2) + *(int*)(iVar1 + 0xc) != *(int*)(iVar2 + 0xc)) {
                                    return false;
                                }
                                bVar4 = ((uint32_t)param_1b & 3) + *(int*)(iVar1 + 0x10) == *(int*)(iVar2 + 0x10);
                            }
                            if (!bVar4) {
                                return false;
                            }
                            param_1b = (int*)((int)param_1b + 1);
                            param_2c = param_2c + param_4;
                        } while ((int)param_1b < (int)param_3);
                    }
                    local_c = local_c + 1;
                    piVar3 = piVar3 + 1;
                } while (local_c < param_4);
            }
        LAB_0061580f:
            bVar4 = true;
        }
    } else {
        bVar4 = 1 < param_3;
    }
    return bVar4;
}

// 0x61581d — observed shape
int FUN_0061581d(void* self, uint8_t* param_1) {
    int local_10 = 0;
    uint32_t local_8 = 0xffffffff;
    int iVar2 = *(int*)((char*)self + 4);
    if ((iVar2 == 0) || (*(int*)(iVar2 + 4) != 4)) {
        local_10 = 0;
    } else {
        int local_c = *(int*)(iVar2 + 0x1c);
        for (; local_c != 0; local_c = *(int*)(local_c + 0xc)) {
            iVar2 = *(int*)(local_c + 8);
            if (iVar2 != 0) {
                if (*(int*)(iVar2 + 4) == 6) {
                    if (*(int*)(iVar2 + 0x10) == 2) {
                        uint8_t* pbVar3 = *(uint8_t**)(*(int*)(iVar2 + 0x14) + 0x18);
                        uint8_t* pbVar6 = param_1;
                        int iVar4;
                        do {
                            uint8_t bVar1 = *pbVar3;
                            bool bVar7 = bVar1 < *pbVar6;
                            if (bVar1 != *pbVar6) {
                            LAB_006158a2:
                                iVar4 = (1 - (uint32_t)bVar7) - (uint32_t)(bVar7 != 0);
                                goto LAB_006158a7;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = pbVar3[1];
                            bVar7 = bVar1 < pbVar6[1];
                            if (bVar1 != pbVar6[1]) goto LAB_006158a2;
                            pbVar3 = pbVar3 + 2;
                            pbVar6 = pbVar6 + 2;
                        } while (bVar1 != 0);
                        iVar4 = 0;
                    LAB_006158a7:
                        if (iVar4 == 0) {
                            iVar2 = *(int*)(iVar2 + 0x18);
                            if (*(int*)(iVar2 + 0x3c) != 0) {
                                if ((*(uint8_t*)(iVar2 + 0x18) & 2) == 0) {
                                    uint32_t uVar5 = 0;
                                    if (*(int*)(iVar2 + 0x1c) != 0) {
                                        uint8_t local_1c[4];
                                        uint32_t local_18 = 0;
                                        int iVar4b = FUN_005f7fa4(*(void**)(*(int*)(iVar2 + 0x1c) + 0x18), 0, local_1c);
                                        if (iVar4b < 0) {
                                            uVar5 = 0xffffffff;
                                        } else {
                                            uVar5 = local_18;
                                        }
                                    }
                                    if ((uVar5 & 0xffff0000) != 0) {
                                        if ((uVar5 & 0xffff0000) != (*(uint32_t*)((char*)self + 0x10) & 0xffff0000))
                                        goto LAB_00615914;
                                    }
                                    if ((uVar5 & 0xffff) != 0) {
                                        if ((uVar5 & 0xffff) != (*(uint32_t*)((char*)self + 0x10) & 0xffff)) goto LAB_00615914;
                                    }
                                    if (local_8 != 0xffffffff) {
                                        if (uVar5 <= local_8) goto LAB_00615914;
                                    }
                                    local_10 = iVar2;
                                    local_8 = uVar5;
                                }
                            }
                        }
                    }
                }
            }
        LAB_00615914:
        }
    }
    return local_10;
}

// 0x615933 — observed shape
int FUN_00615933(void* self, int param_1, void** param_2) {
    int local_14 = 0;
    uint32_t local_8 = 0xffffffff;
    void* local_10 = nullptr;
    int iVar1 = *(int*)((char*)self + 4);
    if ((iVar1 == 0) || (*(int*)(iVar1 + 4) != 4)) {
        local_14 = 0;
    } else {
        int local_c = *(int*)(iVar1 + 0x1c);
        for (; local_c != 0; local_c = *(int*)(local_c + 0xc)) {
            iVar1 = *(int*)(local_c + 8);
            if (iVar1 != 0) {
                if (*(int*)(iVar1 + 4) == 6) {
                    if (*(int*)(iVar1 + 0x10) == 2) {
                        if (param_1 != 0) {
                            int iVar2 = param_1;
                            do {
                                if (*(int*)(iVar1 + 0x24) == *(int*)(*(int*)(iVar2 + 8) + 0x18)) break;
                                iVar2 = *(int*)(iVar2 + 0xc);
                            } while (iVar2 != 0);
                            if (iVar2 != 0) {
                                iVar2 = *(int*)(iVar1 + 0x18);
                                if (*(int*)(iVar2 + 0x3c) != 0) {
                                    uint32_t uVar4 = 0;
                                    if (*(int*)(iVar2 + 0x1c) != 0) {
                                        uint8_t local_20[4];
                                        uint32_t local_1c = 0;
                                        int iVar3 = FUN_005f7fa4(*(void**)(*(int*)(iVar2 + 0x1c) + 0x18), 0, local_20);
                                        if (iVar3 < 0) {
                                            uVar4 = 0xffffffff;
                                        } else {
                                            uVar4 = local_1c;
                                        }
                                    }
                                    if ((uVar4 & 0xffff0000) != 0) {
                                        if ((uVar4 & 0xffff0000) != (*(uint32_t*)((char*)self + 0x10) & 0xffff0000))
                                        goto LAB_00615a24;
                                    }
                                    if ((uVar4 & 0xffff) != 0) {
                                        if ((uVar4 & 0xffff) != (*(uint32_t*)((char*)self + 0x10) & 0xffff)) goto LAB_00615a24;
                                    }
                                    if (local_8 != 0xffffffff) {
                                        if (uVar4 <= local_8) goto LAB_00615a24;
                                    }
                                    local_10 = *(void**)(*(int*)(iVar1 + 0x14) + 0x18);
                                    local_14 = iVar2;
                                    local_8 = uVar4;
                                }
                            }
                        }
                    }
                }
            }
        LAB_00615a24:
        }
        if (param_2 != nullptr) {
            *param_2 = local_10;
        }
    }
    return local_14;
}
// 0x615a4f — observed shape
void FUN_00615a4f(void* self, uint8_t param_1) {
    FUN_006338c7();
    if ((param_1 & 1) != 0) {
        FUN_0065d63f(self);
    }
}

// 0x615a6f — observed shape
uint32_t FUN_00615a6f(void* self) {
    int32_t* in_ECX = (int32_t*)self;
    uint64_t* puVar3 = *(uint64_t**)(*(intptr_t*)in_ECX + 0x3c);
    do {
        if (puVar3 == (uint64_t*)0x0) {
            return 0;
        }
        char* local_c = *(char**)((intptr_t)puVar3 + 4);
        uint64_t* puVar2 = (uint64_t*)0x0;
        uint64_t* local_8 = (uint64_t*)0x0;
        do {
            int32_t iVar1 = _stricmp(local_c, *(char**)((intptr_t)puVar3 + 4));
            if (iVar1 != 0) break;
            uint8_t local_18[4];
            uint32_t local_14 = 0;
            iVar1 = FUN_005f7fa4(*(void**)(intptr_t)puVar3, 0, local_18);
            if (-1 < iVar1) {
                if (in_ECX[4] == (int32_t)local_14) {
                    if (puVar2 == (uint64_t*)0x0) {
                        puVar2 = puVar3;
                    }
                } else if (((in_ECX[4] & 0xffff0000) == (int32_t)local_14) && (local_8 == (uint64_t*)0x0)) {
                    local_8 = puVar3;
                }
            }
            puVar3 = *(uint64_t**)(puVar3 + 5);
        } while (puVar3 != (uint64_t*)0x0);
        if ((puVar2 != (uint64_t*)0x0) || (puVar2 = local_8, local_8 != (uint64_t*)0x0)) {
            local_c = (char*)(intptr_t)FUN_0065d97c(*(void**)((intptr_t)puVar2 + 4), 0xb51, 1, 4);
            if (local_c == (char*)0xffffffff) {
                return 0x8007000e;
            }
            local_8 = (uint64_t*)0x0;
            do {
                puVar2 = puVar2 + 1;
                int32_t iVar1 = FUN_0065d9d5(local_c, 0, local_8, (void*)*puVar2);
                if (iVar1 == -1) {
                    return 0x8007000e;
                }
                local_8 = (uint64_t*)((intptr_t)local_8 + 1);
            } while ((intptr_t)local_8 < 4);
        }
    } while (true);
}

// 0x615b49 — observed shape
int FUN_00615b49(int param_1) {
    if (param_1 != 0) {
        int iVar1 = *(int*)(param_1 + 4);
        if (iVar1 == 6) {
            return *(int*)(param_1 + 0x14) + 0x10;
        }
        if (iVar1 != 0xb) {
            if (iVar1 == 0xc) {
                iVar1 = FUN_00615b49(*(int*)(param_1 + 0x14));
                if (iVar1 != 0) {
                    return iVar1;
                }
                iVar1 = FUN_00615b49(*(int*)(param_1 + 0x18));
                if (iVar1 != 0) {
                    return iVar1;
                }
                iVar1 = FUN_00615b49(*(int*)(param_1 + 0x1c));
                if (iVar1 != 0) {
                    return iVar1;
                }
                iVar1 = FUN_00615b49(*(int*)(param_1 + 0x20));
                if (iVar1 != 0) {
                    return iVar1;
                }
            } else if (iVar1 == 0xd) {
                return param_1 + 0x30;
            }
        }
    }
    return 0;
}

// 0x615bbb — observed shape
uint32_t FUN_00615bbb(int* param_1, uint32_t param_2, uint32_t param_3, char* param_4, char param_5) {
    param_1[0x13] = 1;
    char local_104[255];
    _vsnprintf(local_104, 0x100, param_4, (va_list)&param_5);
    char* pcVar3 = local_104;
    void* puVar2 = &DAT_006c7974;
    uint8_t local_5 = 0;
    (void)local_5;
    uint32_t uVar1 = FUN_00615b49((int)param_2);
    FUN_0060fcd3(*param_1 + 0x18, (int)uVar1, (int)param_3, puVar2, pcVar3);
    return 0;
}

// 0x615c1d — observed shape
// The listing receives a 64-bit value from FUN_00615b49 (EDX:EAX register pair); the
// low half is threaded to FUN_0060fd9a and the high half is the receiver.
uint32_t FUN_00615c1d(uint32_t param_1, uint32_t param_2, uint32_t param_3, char* param_4, char param_5) {
    char local_104[255];
    _vsnprintf(local_104, 0x100, param_4, (va_list)&param_5);
    char* pcVar3 = local_104;
    void* puVar2 = &DAT_006c7974;
    uint64_t uVar1 = (uint64_t)FUN_00615b49((int)param_2);
    FUN_0060fd9a(*(int*)((intptr_t)(uVar1 >> 0x20) + 0x18), (int)uVar1, (int)param_3, puVar2, pcVar3);
    return 0;
}

// 0x615c76 — observed shape
uint32_t FUN_00615c76(uint32_t param_1, uint32_t param_2, int param_3) {
    int iVar1 = *(int*)(*(int*)(param_3 + 8) + 0x14);
    int iVar2 = *(int*)(iVar1 + *(int*)(*(int*)(param_3 + 0x18) + param_1 * 4) * 4);
    int iVar1b = *(int*)(iVar1 + *(int*)(*(int*)(param_3 + 0x18) + param_2 * 4) * 4);
    uint32_t uVar3 = *(uint32_t*)(iVar2 + 0x6c);
    uint32_t uVar4 = *(uint32_t*)(iVar1b + 0x6c);
    if (uVar4 <= uVar3) {
        if (uVar4 < uVar3) {
            return 1;
        }
        uVar3 = *(uint32_t*)(iVar2 + 0x10);
        uVar4 = *(uint32_t*)(iVar1b + 0x10);
        if (uVar4 <= uVar3) {
            if (uVar4 < uVar3) {
                return 1;
            }
            if (param_2 <= param_1) {
                return (uint32_t)(param_2 < param_1);
            }
        }
    }
    return 0xffffffff;
}

// 0x615ccd — observed shape
void FUN_00615ccd(void* self) {
    char* in_ECX = (char*)self;
    if (*(void***)(in_ECX + 8) != (void**)0x0) {
        (**(void(***)(int))**(void***)(in_ECX + 8))(1);
    }
    operator_delete(*(void**)(in_ECX + 0x18));
    operator_delete(*(void**)(in_ECX + 0x88));
    operator_delete(*(void**)(in_ECX + 0x90));
    operator_delete(*(void**)(in_ECX + 0x98));
}

// 0x615d0d — observed shape
int FUN_00615d0d(void* self, int param_1, uint32_t* param_2) {
    char* in_ECX = (char*)self;
    uint32_t uVar3 = 0;
    if (param_1 == 0) {
        return 0;
    }
    int iVar1 = *(int*)(param_1 + 4);
    int iVar2 = 0;
    if (iVar1 != 1) {
        uint32_t uVar4;
        if (iVar1 == 6) {
            uVar4 = *(uint32_t*)(param_1 + 0x18);
        } else {
            if (iVar1 == 8) {
                if (*(int*)(param_1 + 0x14) == 0) {
                    return 0;
                }
                do {
                    iVar1 = FUN_00615d0d(in_ECX, *(uint32_t*)(param_1 + 0x10), param_2 + iVar2);
                    iVar2 = iVar2 + iVar1;
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *(uint32_t*)(param_1 + 0x14));
                return iVar2;
            }
            if (iVar1 == 9) {
                iVar1 = *(int*)(param_1 + 0x1c) * *(int*)(param_1 + 0x18);
                uVar3 = 0;
                switch (*(uint32_t*)(param_1 + 0x14)) {
                case 0:
                    uVar3 = 0x17;
                    break;
                case 1:
                case 5:
                    uVar3 = 2;
                    break;
                case 2:
                case 6:
                    uVar3 = 0x2000002;
                    break;
                case 3:
                case 7:
                    uVar3 = 0x4000002;
                    break;
                case 4:
                case 8:
                    uVar3 = 0x8000002;
                    break;
                case 10:
                    uVar3 = 0x2000000;
                    break;
                case 0xb:
                    uVar3 = 0x4000000;
                    break;
                case 0xc:
                    uVar3 = 0x8000000;
                }
                if ((*(uint8_t*)(in_ECX + 0x14) & 0x20) != 0) {
                    uVar3 = uVar3 & 0xf3ffffff | 0x2000000;
                }
                if (iVar1 != 0) {
                    for (iVar2 = iVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
                        *param_2 = uVar3;
                        param_2 = param_2 + 1;
                    }
                }
                return iVar1;
            }
            if (iVar1 != 0xb) {
                FUN_00615bbb((int*)nullptr, 0, 0, (char*)nullptr, 0);
                return 0;
            }
            uVar4 = *(uint32_t*)(param_1 + 0x20);
        }
        iVar1 = FUN_00615d0d(in_ECX, uVar4, param_2);
        return iVar1;
    }
    do {
        if (*(int*)(param_1 + 4) != 1) break;
        iVar1 = FUN_00615d0d(in_ECX, *(uint32_t*)(param_1 + 8), param_2 + iVar2);
        param_1 = *(int*)(param_1 + 0xc);
        iVar2 = iVar2 + iVar1;
    } while (param_1 != 0);
    if (param_1 == 0) {
        return iVar2;
    }
    iVar1 = FUN_00615d0d(in_ECX, param_1, param_2 + iVar2);
    return iVar2 + iVar1;
}

// 0x615e7a — observed shape
int FUN_00615e7a(void* self, int param_1, int param_2, int param_3, uint32_t param_4,
                int param_5, uint32_t param_6, uint32_t* param_7, int* param_8) {
    char* in_ECX = (char*)self;
    int iVar3 = param_2;
    int iVar2 = param_1;
    uint32_t uVar5 = 0;
    int local_8 = 0;
    uint32_t local_c = 0;
    if (param_7 == (uint32_t*)0x0) {
        param_7 = &local_c;
    }
    if (param_1 != 0) {
        int iVar4 = *(int*)(param_1 + 4);
        if (iVar4 == 1) {
            iVar4 = FUN_00615e7a(in_ECX, *(uint32_t*)(param_1 + 8), param_2, param_3, param_4,
                                 param_5, param_6, param_7, &param_2);
            if (iVar4 < 0) {
                return iVar4;
            }
            iVar2 = FUN_00615e7a(in_ECX, *(uint32_t*)(iVar2 + 0xc), iVar3 + param_2 * 4, param_3,
                                 param_4, param_5, param_6, param_7, &param_1);
            if (iVar2 < 0) {
                return iVar2;
            }
            local_8 = param_1 + param_2;
        } else {
            if (iVar4 == 6) {
                iVar2 = FUN_00615e7a(in_ECX, *(uint32_t*)(param_1 + 0x18), param_2, param_3, param_4,
                                     param_5, param_6, param_7, &local_8);
            } else {
                if (iVar4 == 8) {
                    if (param_5 == 0) {
                        iVar3 = param_1;
                        do {
                            if (*(int*)(iVar3 + 4) != 8) break;
                            iVar3 = *(int*)(iVar3 + 0x10);
                        } while (iVar3 != 0);
                        if (((iVar3 != 0) && (*(int*)(iVar3 + 4) == 9)) && (*(int*)(iVar3 + 0x10) == 3)) {
                            param_3 = FUN_0065d97c(&DAT_006e0430, 0x2d1, 0xffffffff, 4);
                            param_5 = 1;
                        }
                    }
                    if (*(int*)(iVar2 + 0x14) != 0) {
                        do {
                            iVar3 = FUN_00615e7a(in_ECX, *(uint32_t*)(iVar2 + 0x10), param_2 + local_8 * 4,
                                                 param_3, param_4, param_5, param_6, param_7, &param_1);
                            if (iVar3 < 0) {
                                return iVar3;
                            }
                            local_8 = local_8 + param_1;
                            uVar5 = uVar5 + 1;
                        } while (uVar5 < *(uint32_t*)(iVar2 + 0x14));
                    }
                    goto LAB_00616071;
                }
                if (iVar4 == 9) {
                    if (*(int*)(param_1 + 0x10) == 3) {
                        if (param_5 == 0) {
                            param_3 = FUN_0065d97c(&DAT_006e0430, 0x2d1, 0xffffffff, 4);
                        } else {
                            uint8_t* pbVar1 = (uint8_t*)(*(int*)(*(int*)(*(int*)(in_ECX + 8) + 0x10) + param_3 * 4) + 4);
                            *pbVar1 = *pbVar1 | 0x80;
                        }
                    }
                    iVar2 = FUN_0061449c(*(int*)(iVar2 + 0x10), *(int*)(iVar2 + 0x18),
                                         *(int*)(iVar2 + 0x1c), *(int*)(iVar2 + 0x20), param_2,
                                         param_3, param_7, param_6, &local_8);
                } else {
                    if (iVar4 != 0xb) {
                        FUN_00615bbb((int*)nullptr, 0, 0, (char*)nullptr, 0);
                        goto LAB_00616071;
                    }
                    iVar2 = FUN_00616a9f(*(int*)(param_1 + 0x20), param_2, param_3, param_4, param_5,
                                         param_6, param_7, *(char**)(param_1 + 0x2c),
                                         *(int*)(param_1 + 0x30), &local_8);
                }
            }
            if (iVar2 < 0) {
                return iVar2;
            }
        }
    }
LAB_00616071:
    if (param_8 != (int*)0x0) {
        *param_8 = local_8;
    }
    return 0;
}

extern int FUN_00614480(void*, uint32_t);
extern void* FUN_0065aaac(int, int);
extern int FUN_0065da8c(int);
extern void* FUN_00533c78();
extern int FUN_0065da35(uint32_t, uint32_t, uint32_t);

// 0x616086 — observed shape
int FUN_00616086(void* self, int param_1, double* param_2) {
    char* in_ECX = (char*)self;
    uint8_t* pbVar1 = *(uint8_t**)(*(int*)(*(int*)(in_ECX + 8) + 0x14) + param_1 * 4);
    double local_14;
    double local_c;
    if ((*pbVar1 & 0x80) == 0) {
        int iVar2 = FUN_006147e4(param_1, &local_14);
        if (iVar2 < 0) {
            return iVar2;
        }
        if (local_14 != local_c) {
            return -0x7fffbffb;
        }
        iVar2 = _finite(local_14);
        if (iVar2 == 0) {
            return -0x7fffbffb;
        }
        if (param_2 == (double*)0x0) {
            return 0;
        }
    } else {
        int iVar2 = _finite(*(double*)(pbVar1 + 0x20));
        if (iVar2 == 0) {
            return -0x7fffbffb;
        }
        if (param_2 == (double*)0x0) {
            return 0;
        }
        local_14 = *(double*)(pbVar1 + 0x20);
    }
    *param_2 = local_14;
    return 0;
}

// 0x616109 — observed shape
uint32_t FUN_00616109(int param_1) {
    while (true) {
        while (true) {
            if (param_1 == 0) {
                return 1;
            }
            int iVar1 = *(int*)(param_1 + 4);
            if (iVar1 != 1) break;
            iVar1 = FUN_00616109(*(int*)(param_1 + 8));
            if (iVar1 == 0) {
                return 0;
            }
            param_1 = *(int*)(param_1 + 0xc);
        }
        while (iVar1 == 6) {
            param_1 = *(int*)(param_1 + 0x18);
            if (param_1 == 0) return 1;
            iVar1 = *(int*)(param_1 + 4);
            if (iVar1 == 1) break;
        }
        if (iVar1 == 8) {
        LAB_00616148:
            param_1 = *(int*)(param_1 + 0x10);
            continue;
        }
        if (iVar1 == 9) {
            if ((*(int*)(param_1 + 0x10) < 0) || (2 < *(int*)(param_1 + 0x10))) {
                return 0;
            }
            return 1;
        }
        if (iVar1 == 0xb) {
            param_1 = *(int*)(param_1 + 0x20);
            continue;
        }
        if (iVar1 != 0xd) {
            FUN_00615bbb((int*)0x0, 0, 0, (char*)0x0, 0);
            return 0;
        }
        goto LAB_00616148;
    }
}

// 0x616184 — observed shape
uint32_t FUN_00616184(void* self, uint32_t param_1, uint32_t param_2, uint32_t* param_3) {
    char* in_ECX = (char*)self;
    int iVar1 = *(int*)(in_ECX + 8);
    uint32_t uVar2 = param_1;
    if (param_1 < *(uint32_t*)(iVar1 + 8)) {
        do {
            if (*(int*)(*(int*)(iVar1 + 0x14) + uVar2 * 4) != 0) {
                FUN_00615a4f(self, 1);
            }
            *(uint32_t*)(*(int*)(*(int*)(in_ECX + 8) + 0x14) + uVar2 * 4) = 0;
            iVar1 = *(int*)(in_ECX + 8);
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(iVar1 + 8));
    }
    *(uint32_t*)(*(int*)(in_ECX + 8) + 8) = param_1;
    iVar1 = *(int*)(in_ECX + 8);
    uVar2 = param_2;
    if (param_2 < *(uint32_t*)(iVar1 + 0xc)) {
        do {
            if (*(int*)(*(int*)(iVar1 + 0x18) + uVar2 * 4) != 0) {
                FUN_00614343(1);
            }
            *(uint32_t*)(*(int*)(*(int*)(in_ECX + 8) + 0x18) + uVar2 * 4) = 0;
            iVar1 = *(int*)(in_ECX + 8);
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(iVar1 + 0xc));
    }
    *(uint32_t*)(*(int*)(in_ECX + 8) + 0xc) = param_2;
    uint32_t* puVar3 = *(uint32_t**)(in_ECX + 0x18);
    for (uVar2 = *(uint32_t*)(*(int*)(in_ECX + 4) + 0x18) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = *param_3;
        param_3 = param_3 + 1;
        puVar3 = puVar3 + 1;
    }
    for (int iVar1b = 0; iVar1b != 0; iVar1b = iVar1b + -1) {
        *(uint8_t*)puVar3 = *(uint8_t*)param_3;
        param_3 = (uint32_t*)((intptr_t)param_3 + 1);
        puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
    }
    return 0;
}

// 0x616222 — observed shape
int FUN_00616222(void* self, uint32_t param_1, uint32_t param_2, int param_3, int* param_4,
                 uint32_t* param_5, uint32_t param_6) {
    char* in_ECX = (char*)self;
    uint32_t uVar1, uVar3, uVar4;
    uint32_t* puVar2;
    int iVar5;
    void* pvVar6;
    uint32_t* puVar7;
    int iVar8;
    uint32_t* puVar9;
    int* piVar10;
    bool bVar11;
    uint32_t uVar12;
    int local_24[2];
    void* local_1c;
    int local_18 = 0;
    int local_14 = 0;
    uint32_t local_10;
    void* local_c;
    uint32_t local_8;

    uVar4 = param_2;
    if (((param_2 & 0xfff00000) == 0x20500000) && ((param_6 & 4) != 0)) {
        uVar3 = param_2 & 0xfffff;
        param_2 = 0;
        if (uVar3 != 0) {
            local_8 = (int)(intptr_t)param_5 - (int)(intptr_t)param_4;
            piVar10 = param_4;
            do {
                if ((*piVar10 != *(int*)(local_8 + (intptr_t)piVar10)) ||
                   ((**(uint8_t**)(*(int*)(*(int*)(in_ECX + 8) + 0x14) + *piVar10 * 4) & 1) == 0)) break;
                param_2 = param_2 + 1;
                piVar10 = piVar10 + 1;
            } while (param_2 < uVar3);
        }
        if (param_2 == uVar3) {
            uVar4 = uVar3 | 0x10000000;
        }
    }
    if (uVar4 == 0x50000001) {
        uVar12 = 0x20500001;
    LAB_0061633b:
        iVar5 = FUN_00616222(in_ECX, uVar12, param_3, (int*)(intptr_t)param_4, param_5, param_6);
        if (iVar5 < 0) {
            return iVar5;
        }
        return 0;
    }
    if ((uVar4 == 0x50000002) && ((*(uint8_t*)(*(int*)(in_ECX + 8) + 0x6c) & 0x20) == 0)) {
        local_14 = -1;
        local_10 = 0xffffffff;
        iVar5 = FUN_00616222(in_ECX, 0x20500001, 0, (int*)&local_14, (uint32_t*)param_4, param_6 & 0x40);
        if (iVar5 < 0) {
            return iVar5;
        }
        iVar5 = FUN_00616222(in_ECX, 0x20500001, 0, (int*)&local_10, (uint32_t*)param_4 + 1,
                             param_6 & 0x40);
        if (iVar5 < 0) {
            return iVar5;
        }
        param_5 = &local_10;
        param_4 = &local_14;
        uVar12 = 0x20400001;
        goto LAB_0061633b;
    }
    if (((*(uint8_t*)(*(int*)(in_ECX + 8) + 0x6c) & 0x80) != 0) &&
       ((((local_10 = uVar4 & 0xfff00000, local_10 == 0x20000000 || (local_10 == 0x20100000)) ||
         (local_10 == 0x20200000)) || (local_10 == 0x20300000)))) {
        uVar4 = uVar4 & 0xfffff;
        local_c = (void*)(intptr_t)FUN_00533c78();
        if (local_c == (void*)0x0) {
            return -0x7ff8fff2;
        }
        uVar3 = 0;
        pvVar6 = local_c;
        do {
            local_24[uVar3] = (int)(intptr_t)pvVar6;
            uVar3 = uVar3 + 1;
            pvVar6 = (void*)((intptr_t)pvVar6 + uVar4 * 4);
        } while (uVar3 < 4);
        if (uVar4 != 0) {
            iVar5 = (int)(intptr_t)param_4 - (int)(intptr_t)local_1c;
            iVar8 = (int)(intptr_t)param_5 - (int)(intptr_t)local_1c;
            local_18 = local_18 - (int)(intptr_t)local_1c;
            local_8 = uVar4;
            do {
                if (local_10 == 0x20000000) {
                    *(void**)local_1c = *(void**)(iVar8 + (intptr_t)local_1c);
                    uVar12 = *(uint32_t*)(iVar5 + (intptr_t)local_1c);
                LAB_00616428:
                    *(uint32_t*)(local_18 + (intptr_t)local_1c) = uVar12;
                } else {
                    if (local_10 == 0x20100000) {
                        *(void**)local_1c = *(void**)(iVar5 + (intptr_t)local_1c);
                        uVar12 = *(uint32_t*)(iVar8 + (intptr_t)local_1c);
                        goto LAB_00616428;
                    }
                    if (local_10 == 0x20200000) {
                        *(void**)local_1c = *(void**)(in_ECX + 0x24);
                        uVar12 = *(uint32_t*)(in_ECX + 0x20);
                        goto LAB_00616428;
                    }
                    if (local_10 == 0x20300000) {
                        *(void**)local_1c = *(void**)(in_ECX + 0x20);
                        uVar12 = *(uint32_t*)(in_ECX + 0x24);
                        goto LAB_00616428;
                    }
                }
                local_1c = (void*)((intptr_t)local_1c + 1);
                local_8 = local_8 - 1;
            } while (local_8 != 0);
        }
        iVar5 = FUN_00614480((void*)(intptr_t)local_24[0], uVar4);
        if ((-1 < iVar5) && (iVar5 = FUN_00614480((void*)(intptr_t)local_24[1], uVar4), -1 < iVar5)) {
            iVar5 = FUN_00616222(in_ECX, uVar4 | 0x10100000, local_24[0], (int*)param_5, (uint32_t*)0,
                                 param_6 & 0x40);
            if ((-1 < iVar5) &&
               ((iVar5 = FUN_00616222(in_ECX, uVar4 | 0x20400000, local_24[1], (int*)param_4,
                                      (uint32_t*)(intptr_t)local_24[0], param_6 & 0x40), -1 < iVar5 &&
                (iVar5 = FUN_00616222(in_ECX, uVar4 | 0x30000000, param_3, (int*)local_24[1],
                                      (uint32_t*)((intptr_t)local_c + uVar4 * 8), param_6), -1 < iVar5)))) {
                iVar5 = 0;
            }
        }
        operator_delete(local_c);
        return iVar5;
    }
    local_c = in_ECX;
    local_8 = FUN_0065da35(uVar4, 0xffffffff, 0xffffffff);
    if (local_8 < *(uint32_t*)(*(int*)(in_ECX + 8) + 0xc)) {
        puVar9 = *(uint32_t**)(*(int*)(*(int*)(in_ECX + 8) + 0x18) + local_8 * 4);
    } else {
        puVar9 = (uint32_t*)0x0;
    }
    if (puVar9 == (uint32_t*)0x0) {
        return -0x7ff8fff2;
    }
    if ((puVar9[3] == 0) && (puVar9[1] == 0)) {
        *puVar9 = 0;
        return 0;
    }
    uVar4 = FUN_0065d412(0, 0);
    uVar3 = FUN_0065cc6f(0, 0);
    local_10 = uVar3 * 4;
    iVar5 = puVar9[1] - uVar3;
    piVar10 = (int*)puVar9[2];
    for (uVar3 = uVar3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *piVar10 = *param_4;
        param_4 = param_4 + 1;
        piVar10 = piVar10 + 1;
    }
    for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(char*)piVar10 = (char)*param_4;
        param_4 = (int*)((intptr_t)param_4 + 1);
        piVar10 = (int*)((intptr_t)piVar10 + 1);
    }
    puVar7 = (uint32_t*)(puVar9[2] + local_10);
    for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *param_5;
        param_5 = param_5 + 1;
        puVar7 = puVar7 + 1;
    }
    uVar3 = 0;
    if (puVar9[1] != 0) {
        do {
            uVar1 = *(uint32_t*)(puVar9[2] + uVar3 * 4);
            if (uVar1 < *(uint32_t*)(*(int*)((intptr_t)local_c + 8) + 8)) {
                iVar5 = *(int*)(*(int*)(*(int*)((intptr_t)local_c + 8) + 0x14) + uVar1 * 4);
            } else {
                iVar5 = 0;
            }
            if (iVar5 != 0) {
                *(int*)(iVar5 + 0x5c) = *(int*)(iVar5 + 0x5c) + 1;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < puVar9[1]);
    }
    param_5 = (uint32_t*)0x0;
    if (uVar4 != 0) {
        do {
            param_4 = (int*)0x0;
            if ((param_3 != 0) && (uVar3 = *(uint32_t*)(param_3 + (intptr_t)param_5 * 4), uVar3 != 0xffffffff)) {
                if (uVar3 < *(uint32_t*)(*(int*)((intptr_t)local_c + 8) + 8)) {
                    param_4 = *(int**)(*(int*)(*(int*)((intptr_t)local_c + 8) + 0x14) + uVar3 * 4);
                } else {
                    param_4 = (int*)0x0;
                }
                if (param_4 == (int*)0x0) {
                    FUN_00615bbb((int*)local_c, 0, 0, (char*)"internal error: result register invalid", 0);
                    return -0x7fffbffb;
                }
            }
            local_10 = FUN_0065d9d5(*(void**)(*(int*)((intptr_t)local_c + 8) + 0x88), 0, 0, 0);
            if (local_10 == 0xffffffff) {
                return -0x7ff8fff2;
            }
            if (local_10 < *(uint32_t*)(*(int*)((intptr_t)local_c + 8) + 8)) {
                puVar7 = *(uint32_t**)(*(int*)(*(int*)((intptr_t)local_c + 8) + 0x14) + local_10 * 4);
            } else {
                puVar7 = (uint32_t*)0x0;
            }
            if (puVar7 == (uint32_t*)0x0) {
                return -0x7ff8fff2;
            }
            *puVar7 = param_6;
            puVar7[0x12] = local_8;
            puVar7[4] = (uint32_t)(intptr_t)param_5;
            if ((param_6 & 0xe000000) == 0) {
                *puVar7 = *(uint32_t*)((intptr_t)local_c + 100) | param_6;
            }
            puVar7[5] = *(uint32_t*)((intptr_t)local_c + 0x30);
            puVar7[6] = *(uint32_t*)((intptr_t)local_c + 0x34);
            iVar5 = (int)(intptr_t)param_5 * 4;
            *(uint32_t*)(iVar5 + puVar9[4]) = local_10;
            if (param_3 != 0) {
                *(uint32_t*)(iVar5 + param_3) = local_10;
            }
            if (param_4 != (int*)0x0) {
                puVar7[0xc] = *(uint32_t*)((intptr_t)param_4 + 0x30);
                puVar7[0x18] = *(uint32_t*)((intptr_t)param_4 + 0x60);
                puVar7[0x19] = *(uint32_t*)((intptr_t)param_4 + 100);
            }
            if ((puVar7[0xc] != 0xffffffff) &&
               (*(uint32_t*)(*(int*)((intptr_t)local_c + 0x18) + puVar7[0xc] * 4) =
                    *(uint32_t*)(iVar5 + puVar9[4]), puVar7[0x18] == 0)) {
                FUN_00615bbb((int*)local_c, 0, 0, (char*)"internal error: argument missing context (A%u)", 0);
            }
            param_5 = (uint32_t*)((intptr_t)param_5 + 1);
        } while (param_5 < uVar4);
    }
    uVar3 = 0;
    if (uVar4 != 0) {
        do {
            FUN_006147e4(*(uint32_t*)(puVar9[4] + uVar3 * 4), 0);
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar4);
    }
    if (((*(uint8_t*)((intptr_t)local_c + 0x14) & 4) == 0) && (iVar5 = FUN_0065cea4(), iVar5 == 0)) {
        uVar3 = 0;
        bVar11 = uVar4 == 0;
        if (uVar4 != 0) {
            do {
                iVar5 = *(int*)(puVar9[4] + uVar3 * 4);
                if (((**(uint8_t**)(*(int*)(*(int*)((intptr_t)local_c + 8) + 0x14) + iVar5 * 4) & 0x40) != 0) ||
                   (iVar5 = FUN_00616086(local_c, iVar5, &local_14), iVar5 < 0)) break;
                uVar3 = uVar3 + 1;
            } while (uVar3 < uVar4);
            bVar11 = uVar3 == uVar4;
        }
        if (bVar11) {
            *puVar9 = uVar4 & 0xfffff | 0x10000000;
            uVar3 = 0;
            puVar9[1] = puVar9[3];
            if (uVar4 != 0) {
                do {
                    uVar12 = FUN_0065d9d5(*(void**)(*(int*)((intptr_t)local_c + 8) + 0x78), 0, 0,
                                          (void*)(uintptr_t)*(uint64_t*)
                                          (*(int*)(*(int*)(*(int*)((intptr_t)local_c + 8) + 0x14) +
                                                   *(int*)(puVar9[4] + uVar3 * 4) * 4) + 0x20));
                    *(uint32_t*)(puVar9[2] + uVar3 * 4) = uVar12;
                    if (*(int*)(puVar9[2] + uVar3 * 4) == -1) {
                        return -0x7ff8fff2;
                    }
                    uVar3 = uVar3 + 1;
                } while (uVar3 < uVar4);
            }
        }
    }
    uVar3 = *puVar9 & 0xfff00000;
    if (uVar3 < 0x20500001) {
        if (uVar3 != 0x20500000) {
            if (uVar3 == 0x10000000) {
                param_6 = 0;
                if (uVar4 != 0) {
                    do {
                        iVar5 = *(int*)(*(int*)((intptr_t)local_c + 8) + 0x14);
                        puVar7 = *(uint32_t**)(iVar5 + *(int*)((intptr_t)param_6 * 4 + puVar9[4]) * 4);
                        uVar3 = *(uint32_t*)((intptr_t)param_6 * 4 + puVar9[2]);
                        puVar2 = *(uint32_t**)(iVar5 + uVar3 * 4);
                        puVar7[0xd] = uVar3;
                        *puVar7 = *puVar7 | *puVar2;
                        *(uint64_t*)(puVar7 + 8) = *(uint64_t*)(puVar2 + 8);
                        *(uint64_t*)(puVar7 + 10) = *(uint64_t*)(puVar2 + 10);
                        param_6 = param_6 + 1;
                    } while (param_6 < uVar4);
                }
                goto LAB_00616a23;
            }
            if (uVar3 == 0x10100000) {
                param_6 = 0;
                if (uVar4 != 0) {
                    do {
                        iVar5 = *(int*)(*(int*)((intptr_t)local_c + 8) + 0x14);
                        puVar7 = *(uint32_t**)(iVar5 + *(int*)((intptr_t)param_6 * 4 + puVar9[4]) * 4);
                        *puVar7 = *puVar7 | **(uint32_t**)(iVar5 + *(int*)((intptr_t)param_6 * 4 + puVar9[2]) * 4) & 2;
                        param_6 = param_6 + 1;
                    } while (param_6 < uVar4);
                }
                goto LAB_00616a23;
            }
            if ((uVar3 != 0x20000000) && (uVar3 != 0x20100000)) {
                if ((uVar3 == 0x20400000) && (param_6 = 0, uVar4 != 0)) {
                    do {
                        iVar5 = *(int*)(*(int*)((intptr_t)local_c + 8) + 0x14);
                        puVar7 = *(uint32_t**)(iVar5 + *(int*)((intptr_t)param_6 * 4 + puVar9[4]) * 4);
                        *puVar7 = *puVar7 |
                                  **(uint32_t**)(iVar5 + *(int*)(puVar9[2] + (puVar9[3] + (intptr_t)param_6) * 4) * 4) &
                                  **(uint32_t**)(iVar5 + *(int*)((intptr_t)param_6 * 4 + puVar9[2]) * 4) & 2;
                        param_6 = param_6 + 1;
                    } while (param_6 < uVar4);
                }
                goto LAB_00616a23;
            }
        }
    } else if ((uVar3 != 0x20700000) && (uVar3 != 0x20800000)) {
        if (uVar3 == 0x30000000) {
            param_4 = (int*)0x0;
            if (uVar4 != 0) {
                do {
                    iVar5 = *(int*)(*(int*)((intptr_t)local_c + 8) + 0x14);
                    puVar7 = *(uint32_t**)(iVar5 + *(int*)(puVar9[4] + (intptr_t)param_4 * 4) * 4);
                    uVar3 = **(uint32_t**)(iVar5 + *(int*)(puVar9[2] + ((intptr_t)param_4 + puVar9[3] * 2) * 4) * 4) &
                            **(uint32_t**)(iVar5 + *(int*)(puVar9[2] + ((intptr_t)param_4 + puVar9[3]) * 4) * 4);
                    if ((uVar3 & 1) == 0) {
                        if ((uVar3 & 2) != 0) {
                            *puVar7 = *puVar7 | 2;
                        }
                    } else {
                        *puVar7 = *puVar7 | 0x17;
                    }
                    param_4 = (int*)((intptr_t)param_4 + 1);
                } while (param_4 < uVar4);
            }
        } else if (uVar3 == 0x50000000) {
            puVar7 = *(uint32_t**)(*(int*)(*(int*)((intptr_t)local_c + 8) + 0x14) + *(int*)puVar9[4] * 4);
            param_6 = 0;
            if (uVar4 != 0) {
                param_4 = (int*)puVar9[2];
                iVar5 = *(int*)(*(int*)((intptr_t)local_c + 8) + 0x14);
                piVar10 = param_4 + puVar9[3];
                do {
                    if ((**(uint32_t**)(iVar5 + *param_4 * 4) & **(uint32_t**)(iVar5 + *piVar10 * 4) & 2) == 0)
                        break;
                    param_6 = param_6 + 1;
                    param_4 = param_4 + 1;
                    piVar10 = piVar10 + 1;
                } while (param_6 < uVar4);
            }
            if (param_6 == uVar4) {
                *puVar7 = *puVar7 | 2;
            }
        }
        goto LAB_00616a23;
    }
    param_6 = 0;
    if (uVar4 != 0) {
        do {
            iVar5 = *(int*)(*(int*)((intptr_t)local_c + 8) + 0x14);
            puVar7 = *(uint32_t**)(iVar5 + *(int*)((intptr_t)param_6 * 4 + puVar9[4]) * 4);
            uVar3 = **(uint32_t**)(iVar5 + *(int*)(puVar9[2] + (puVar9[3] + (intptr_t)param_6) * 4) * 4) &
                    **(uint32_t**)(iVar5 + *(int*)((intptr_t)param_6 * 4 + puVar9[2]) * 4);
            if ((uVar3 & 1) == 0) {
                if ((uVar3 & 2) != 0) {
                    *puVar7 = *puVar7 | 2;
                }
            } else {
                *puVar7 = *puVar7 | 0x17;
            }
            param_6 = param_6 + 1;
        } while (param_6 < uVar4);
    }
LAB_00616a23:
    puVar9[0xf] = param_1;
    puVar9[0xe] = *(uint32_t*)((intptr_t)local_c + 0x38);
    return 0;
}

// 0x616a38 — observed shape
uint32_t FUN_00616a38(void* self, uint32_t param_1, int param_2, int param_3) {
    char* in_ECX = (char*)self;
    uint32_t* puVar2 = (uint32_t*)(intptr_t)FUN_00533c78(param_3 << 2);
    if (puVar2 == (uint32_t*)0x0) {
        return 0x8007000e;
    }
    FUN_00615d0d(in_ECX, param_1, puVar2);
    if (param_3 != 0) {
        uint32_t* puVar4 = puVar2;
        do {
            uint32_t* puVar1 = *(uint32_t**)(*(int*)(*(int*)(in_ECX + 8) + 0x14) +
                                            *(int*)((param_2 - (intptr_t)puVar2) + (intptr_t)puVar4) * 4);
            *puVar1 = *puVar1 | *puVar4;
            puVar4 = puVar4 + 1;
            param_3 = param_3 + -1;
        } while (param_3 != 0);
    }
    operator_delete(puVar2);
    return 0;
}

// 0x616a9f — observed shape
int FUN_00616a9f(void* self, int param_1, uint32_t param_2, uint32_t param_3, int param_4,
                 int param_5, uint32_t* param_6, char* param_7, int param_8, void* param_9,
                 uint32_t* param_10) {
    char* in_ECX = (char*)self;
    char cVar1;
    int iVar2;
    int iVar3;
    char* pcVar4;
    char* pcVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t uVar8;
    uint32_t* puVar9;
    uint32_t* puVar10;
    uint32_t* puVar11;
    uint8_t local_20[4];
    uint32_t local_1c = 0;
    uint32_t local_14 = 0;
    uint32_t local_10 = 0;

    if (param_1 != 0) {
        if ((param_3 == 0) && (param_7 != (char*)0x0)) {
            param_5 = (int)(intptr_t)param_7;
            param_6 = &local_14;
            param_3 = 1;
        }
        if (((param_4 == 0) && (param_8 != 0)) && (*(int*)(in_ECX + 0x84) == 0)) {
            do {
                char* local_c;
                pcVar5 = (char*)0x0;
                iVar2 = *(int*)(param_8 + 8);
                param_7 = (char*)0x0;
                local_c = (char*)0x0;
                if (*(int*)(iVar2 + 4) == 0x11) {
                    pcVar4 = *(char**)(*(int*)(iVar2 + 0x14) + 0x18);
                    if (*(int*)(iVar2 + 0x10) == 0) {
                        local_c = pcVar4;
                    } else {
                        iVar2 = FUN_005f7fa4(*(void**)(*(int*)(iVar2 + 0x10) + 0x18), 0, local_20);
                        if (-1 < iVar2) {
                            if (*(uint32_t*)(in_ECX + 0x10) == local_1c) {
                                param_7 = pcVar4;
                            } else if ((*(uint32_t*)(in_ECX + 0x10) & 0xffff0000) == local_1c) {
                                pcVar5 = pcVar4;
                            }
                        }
                    }
                }
                iVar2 = (int)(intptr_t)in_ECX;
                param_8 = *(int*)(param_8 + 0xc);
                puVar9 = (uint32_t*)0x0;
                if (param_7 == (char*)0x0) {
                    if (pcVar5 == (char*)0x0) {
                        param_7 = local_c;
                    } else {
                        param_7 = pcVar5;
                    }
                    if (param_7 != (char*)0x0) goto LAB_00616b9b;
                } else {
                LAB_00616b9b:
                    if (param_2 < *(uint32_t*)(*(int*)(in_ECX + 8) + 4)) {
                        iVar3 = *(int*)(*(int*)(*(int*)(in_ECX + 8) + 0x10) + param_2 * 4);
                    } else {
                        iVar3 = 0;
                    }
                    if (iVar3 == 0) {
                        return -0x7fffbffb;
                    }
                    param_2 = (uint32_t)FUN_0065da8c(iVar3);
                    if (param_2 < *(uint32_t*)(*(int*)(iVar2 + 8) + 4)) {
                        puVar9 = *(uint32_t**)(*(int*)(*(int*)(iVar2 + 8) + 0x10) + param_2 * 4);
                    }
                    if (puVar9 == (uint32_t*)0x0) {
                        return -0x7ff8fff2;
                    }
                    uVar6 = puVar9[1];
                    if ((uVar6 & 0x800) == 0) {
                        *puVar9 = (uint32_t)(intptr_t)param_7;
                        puVar9[1] = uVar6 | 0x840;
                        if (((uVar6 & 0x10) != 0) && (-1 < (char)(uVar6 | 0x840))) {
                            if (((uVar6 & 0x200) != 0) && ((*(uint32_t*)(*(int*)(in_ECX + 8) + 0x70) & 0x200) != 0)) {
                                puVar9[1] = uVar6 | 0xc40;
                            }
                            if (((puVar9[1] & 0x200) == 0) && ((*(uint8_t*)(*(int*)(in_ECX + 8) + 0x71) & 4) != 0)) {
                                puVar9[1] = puVar9[1] | 0x100400;
                            }
                        }
                    } else {
                        pcVar4 = (char*)(intptr_t)*puVar9;
                        pcVar5 = pcVar4 + 1;
                        do {
                            cVar1 = *pcVar4;
                            pcVar4 = pcVar4 + 1;
                        } while (cVar1 != '\0');
                        pcVar4 = pcVar4 + -(intptr_t)pcVar5;
                        pcVar5 = param_7;
                        do {
                            cVar1 = *pcVar5;
                            pcVar5 = pcVar5 + 1;
                        } while (cVar1 != '\0');
                        uVar6 = (int)(intptr_t)pcVar5 - (int)(intptr_t)(param_7 + 1);
                        local_c = pcVar4;
                        puVar7 = (uint32_t*)(intptr_t)FUN_0065aaac((int)(intptr_t)pcVar4 + (int)uVar6 + 3, 4);
                        if (puVar7 == (uint32_t*)0x0) {
                            return -0x7ff8fff2;
                        }
                        puVar10 = (uint32_t*)(intptr_t)*puVar9;
                        puVar11 = puVar7;
                        for (uVar8 = (uint32_t)(intptr_t)pcVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                            *puVar11 = *puVar10;
                            puVar10 = puVar10 + 1;
                            puVar11 = puVar11 + 1;
                        }
                        for (uVar8 = (uint32_t)(intptr_t)pcVar4 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                            *(uint8_t*)puVar11 = *(uint8_t*)puVar10;
                            puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
                            puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
                        }
                        pcVar5 = (char*)((intptr_t)puVar7 + (intptr_t)local_c);
                        *pcVar5 = ';';
                        pcVar5[1] = ' ';
                        pcVar5 = pcVar5 + 2;
                        for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                            *(uint32_t*)pcVar5 = *(uint32_t*)param_7;
                            param_7 = param_7 + 4;
                            pcVar5 = pcVar5 + 4;
                        }
                        for (uVar8 = uVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                            *pcVar5 = *param_7;
                            param_7 = param_7 + 1;
                            pcVar5 = pcVar5 + 1;
                        }
                        ((uint8_t*)((intptr_t)puVar7 + uVar6 + 2))[(intptr_t)local_c] = 0;
                        *puVar9 = (uint32_t)(intptr_t)puVar7;
                    }
                    param_4 = 1;
                }
            } while (param_8 != 0);
        }
        iVar2 = FUN_00615e7a(in_ECX, param_1, (int)param_2, (int)param_3, param_4, param_5, param_6,
                             (uint32_t*)param_7, (int*)&local_10);
        if (iVar2 < 0) {
            return iVar2;
        }
    }
    if (param_10 != (uint32_t*)0x0) {
        *param_10 = local_10;
    }
    return 0;
}
