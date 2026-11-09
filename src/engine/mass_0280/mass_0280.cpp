#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

extern void operator_delete(void* ptr);
extern int FUN_0065d9d5(uint32_t a, uint32_t b, uint32_t c, double d);
extern int FUN_00623505(int a, uint32_t* b, int c);
extern int FUN_00615bbb();
extern int FUN_00615bbb(void* a, int b, int c, const char* d);
extern void* FUN_00533c78(uint32_t n);
extern uint32_t FUN_00614480(void* a, uint32_t b);
extern uint32_t FUN_00616222(int a, uint32_t b, void* c, void* d, uint32_t e, uint32_t f);
extern int FUN_00618ec0(int a, void* b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);
extern int FUN_0065aa32(uint32_t a, uint32_t b);
extern int FUN_0065aa8a();
extern int FUN_005f7fa4(int a, uint32_t b, void* c);
extern int FUN_006840fd();
extern int FUN_0067099c(uint32_t a);
extern int FUN_00681814(uint32_t a);
extern int FUN_0067e9a7(uint32_t a);
extern int FUN_00672ecd();
extern int FUN_006321e1(uint32_t a, uint32_t b, void* c);
extern int FUN_0063d60d(uint32_t a, uint32_t b, void* c);
extern int FUN_006338c7();
extern int FUN_00615c1d();
extern int FUN_0065d5fa(void* a);
extern int FUN_0065d07f(void* a);
extern int FUN_006233ff();
extern int FUN_00615933(uint32_t a, void* b);
extern int FUN_0061581d(int a);
extern int FUN_0062294a(int a, int b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
extern int FUN_00615a6f();
extern int FUN_005f8091(uint32_t a, void* b);
extern int FUN_00616109(int a);
extern int FUN_006294f9(uint32_t a, uint32_t* b);
extern uint32_t DAT_006f5200[4];
extern uint32_t DAT_006dd2b4[4];

// 0x624bb6 — observed shape
int FUN_00624bb6(void* self, int param_1, uint32_t* param_2, uint32_t param_3) {
    double dVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t* puVar4 = param_2;
    uint32_t uVar5;
    int iVar6 = 0;
    if (param_1 == 0) {
        if (param_2 == nullptr) {
            return 0;
        }
        uVar5 = 0;
        if (param_3 == 0) {
            return 0;
        }
        do {
            int ctx = *(int*)((uint8_t*)self + 8);
            uVar2 = (uint32_t)FUN_0065d9d5(*(uint32_t*)(ctx + 0x88), 0, 0, 0.0);
            param_2[uVar5] = uVar2;
            if (uVar2 < *(uint32_t*)(ctx + 8)) {
                iVar3 = *(int*)(*(int*)(ctx + 0x14) + uVar2 * 4);
            } else {
                iVar3 = 0;
            }
            if (iVar3 != 0) {
                *(uint32_t*)(iVar3 + 0x30) = 0xffffffff;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < param_3);
        return 0;
    }
    iVar3 = *(int*)(param_1 + 4);
    if (iVar3 != 0xe) {
        if (iVar3 == 0xd) {
            iVar3 = FUN_00623505(param_1, param_2, 0);
            return iVar3;
        }
        if (iVar3 == 1) {
            while ((iVar3 = *(int*)(param_1 + 8), iVar3 != 0)) {
                if (*(int*)(iVar3 + 4) == 0xe) {
                    iVar6 = 1;
                    if (*(int*)(iVar3 + 0x10) == 6) {
                        iVar6 = *(int*)(iVar3 + 0x1c);
                    }
                    iVar3 = FUN_00624bb6(self, iVar3, param_2, (uint32_t)iVar6);
                } else {
                    if ((iVar3 == 0) || (*(int*)(iVar3 + 4) != 0xd)) break;
                    iVar6 = *(int*)(iVar3 + 0x18) * *(int*)(iVar3 + 0x14);
                    iVar3 = FUN_00623505(iVar3, param_2, 0);
                }
                if (iVar3 < 0) {
                    return iVar3;
                }
                if (param_2 != nullptr) {
                    param_2 = param_2 + iVar6;
                }
                param_1 = *(int*)(param_1 + 0xc);
                if (param_1 == 0) {
                    return 0;
                }
            }
        }
        FUN_00615bbb();
        return -0x7fffbffb;
    }
    if (param_2 == nullptr) {
        return 0;
    }
    iVar3 = *(int*)(param_1 + 0x10);
    if (iVar3 == 6) {
        uVar5 = 0;
        if (*(int*)(param_1 + 0x18) != -1) {
            if (param_3 == 0) {
                return 0;
            }
            do {
                param_2[uVar5] = *(uint32_t*)(*(int*)((uint8_t*)self + 0x18) + (*(int*)(param_1 + 0x18) + uVar5) * 4);
                uVar5 = uVar5 + 1;
            } while (uVar5 < param_3);
            return 0;
        }
        if (param_3 == 0) {
            return 0;
        }
        do {
            param_2[uVar5] = *(uint32_t*)(*(int*)((uint8_t*)self + 0x1c) + uVar5 * 4);
            uVar5 = uVar5 + 1;
        } while (uVar5 < param_3);
        return 0;
    }
    dVar1 = 0.0;
    uint32_t code = 0;
    if (iVar3 == 0) {
        if (*(int*)(param_1 + 0x18) == 0) {
            dVar1 = 0.0;
        } else {
            dVar1 = 1.0;
        }
        code = 0x17;
    } else {
        if (iVar3 == 1) {
            dVar1 = (double)*(int*)(param_1 + 0x18);
        } else {
            if (iVar3 != 2) {
                if (iVar3 == 3) {
                    dVar1 = *(double*)(param_1 + 0x18);
                }
                goto LAB_00624cd7;
            }
            dVar1 = (double)*(int*)(param_1 + 0x18);
            if (*(int*)(param_1 + 0x18) < 0) {
                dVar1 = dVar1 + 4294967296.0;
            }
        }
        code = 0x2;
    }
LAB_00624cd7:
    {
        int ctx = *(int*)((uint8_t*)self + 8);
        uVar5 = (uint32_t)FUN_0065d9d5(*(uint32_t*)(ctx + 0x78), 0, 0, dVar1);
    }
    *puVar4 = uVar5;
    {
        int ctx = *(int*)((uint8_t*)self + 8);
        if (uVar5 < *(uint32_t*)(ctx + 8)) {
            puVar4 = *(uint32_t**)(*(int*)(ctx + 0x14) + uVar5 * 4);
        } else {
            puVar4 = nullptr;
        }
    }
    if (puVar4 != nullptr) {
        *puVar4 = *puVar4 | code;
        puVar4[0xc] = 0xffffffff;
    }
    return 0;
}

// 0x624db7 — observed shape
uint32_t FUN_00624db7(void* self, int param_1) {
    uint32_t uVar1;
    int iVar2;
    void* pvVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t local_8 = 0;
    if (*(int*)(param_1 + 4) == 0xd) {
        uVar5 = (uint32_t)(*(int*)(param_1 + 0x18) * *(int*)(param_1 + 0x14));
        pvVar3 = FUN_00533c78(uVar5 * 4);
        if (pvVar3 == nullptr) {
            local_8 = (uint32_t)-0x7ff8fff2;
        } else {
            local_8 = FUN_00614480(pvVar3, uVar5);
            if (((-1 < (int)local_8) && (local_8 = (uint32_t)FUN_00623505(param_1, (uint32_t*)pvVar3, 0), -1 < (int)local_8)) &&
                (local_8 = FUN_00616222(param_1, (uVar5 & 0xfffff) | 0x10000000, pvVar3, pvVar3, 0, 0),
                 -1 < (int)local_8)) {
                local_8 = 0;
                if (uVar5 != 0) {
                    do {
                        uVar1 = *(uint32_t*)((int)(uintptr_t)pvVar3 + local_8 * 4);
                        int iVar3 = *(int*)((uint8_t*)self + 8);
                        if (uVar1 < *(uint32_t*)(iVar3 + 8)) {
                            iVar4 = *(int*)(*(int*)(iVar3 + 0x14) + uVar1 * 4);
                        } else {
                            iVar4 = 0;
                        }
                        if (iVar4 != 0) {
                            *(uint32_t*)(iVar4 + 4) = *(uint32_t*)(iVar3 + 0x84);
                        }
                        local_8 = local_8 + 1;
                    } while (local_8 < uVar5);
                }
                local_8 = (uint32_t)FUN_00618ec0(*(int*)(param_1 + 0x10), pvVar3,
                                          *(uint32_t*)(*(int*)((uint8_t*)self + 8) + 0x84), 1, 1, 0, 0);
            }
        }
        operator_delete(pvVar3);
        if (*(int*)((uint8_t*)self + 0x4c) != 0) {
            local_8 = (uint32_t)-0x7fffbffb;
        }
    } else {
        local_8 = 0;
    }
    return local_8;
}

// 0x624eb8 — observed shape
int FUN_00624eb8(uint32_t* self, uint32_t param_1, int param_2, int param_3, uint32_t param_4, int param_5,
                 uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9,
                 uint32_t* param_10, uint32_t* param_11) {
    uint32_t uVar1;
    uint32_t uVar2 = 0;
    uint32_t uVar3;
    char cVar4;
    int iVar5 = 0;
    bool bVar6 = false;
    uint32_t* puVar7 = nullptr;
    uint8_t local_38[24];
    uint8_t local_20[4];
    uint32_t local_1c = 0;
    uint32_t local_14 = 0;
    int local_10 = 0;
    int local_c = 0;
    int* local_8 = nullptr;
    FUN_0065aa32(0x100000, 0x10000);
    uVar3 = param_9;
    local_c = 0;
    local_10 = 0;
    if (((param_9 & 0xfffff800) == 0) &&
        (((cVar4 = (char)param_9, param_2 == 0 || ((param_9 & 0x18) == 0)) &&
         (param_10 != nullptr)))) {
        if ((void*)self[2] != nullptr) {
            void** vtbl = *(void***)self[2];
            ((void(__cdecl*)(void*, int))vtbl[0])((void*)self[2], 1);
        }
        operator_delete((void*)self[6]);
        self[0x12] = 0xffffffff;
        self[0] = param_1;
        self[1] = 0;
        self[2] = 0;
        self[6] = 0;
        self[7] = 0;
        self[0x13] = 0;
        self[0x14] = 0;
        self[0x15] = 0;
        self[0x16] = 0;
        self[0x17] = 0;
        self[0x18] = 0;
        self[0x19] = 0;
        self[3] = param_8;
        self[5] = uVar3;
        self[0xe] = 0;
        self[0xf] = 0;
        self[0x10] = 0;
        self[0x11] = 0;
        self[0x1a] = 0;
        self[0x1b] = 0;
        self[0x1c] = 0;
        self[0x1d] = 0;
        self[0x1e] = 0;
        self[0x1f] = 0;
        self[0x20] = 0;
        self[0x21] = param_7;
        if (param_5 != 0) {
            self[4] = 0x46580200;
            iVar5 = (int)(intptr_t)FUN_00533c78(0x1fc);
            if (iVar5 == 0) {
                uVar2 = 0;
            } else {
                uVar2 = (uint32_t)FUN_006840fd();
            }
            *(uint8_t*)((uintptr_t)self + 0x15) = (uint8_t)(*(uint8_t*)((uintptr_t)self + 0x15) | 1);
            goto LAB_006251aa;
        }
        if ((uVar3 & 0xc0) == 0) {
LAB_00625041:
            iVar5 = FUN_005f7fa4((int)self[3], 2, local_20);
            if (-1 < iVar5) {
                self[4] = local_1c;
                self[5] = uVar3;
                if (local_1c == 0xfffe0100) {
                    self[4] = 0xfffe0101;
                    local_c = 1;
                }
                if (self[4] == (uint32_t)-0xff00) {
                    self[4] = 0xffff0101;
                    local_10 = 1;
                }
                uVar1 = self[4];
                if (uVar1 < 0xfffe0400) {
                    if (uVar1 == 0xfffe03ff) {
LAB_0062518d:
                        iVar5 = (int)(intptr_t)FUN_00533c78(0x1f8);
                        if (iVar5 == 0) {
LAB_006251a8:
                            uVar2 = 0;
                        } else {
                            uVar2 = (uint32_t)FUN_0067099c(param_7);
                        }
                    } else if (uVar1 == 0x54580100) {
                        self[5] = uVar3 | 0x100;
                        iVar5 = (int)(intptr_t)FUN_00533c78(0x1fc);
                        if (iVar5 == 0) goto LAB_006251a8;
                        uVar2 = (uint32_t)FUN_006840fd();
                    } else {
                        if ((((uVar1 != 0xfffe0101) && (uVar1 != 0xfffe0200)) && (uVar1 != 0xfffe0202)) &&
                            (uVar1 != 0xfffe02ff)) {
                            bVar6 = (uVar1 == 0xfffe0300);
                            goto LAB_00625186;
                        }
                        iVar5 = (int)(intptr_t)FUN_00533c78(0x1f8);
                        if (iVar5 == 0) goto LAB_006251a8;
                        uVar2 = (uint32_t)FUN_00681814(param_7);
                    }
LAB_006251aa:
                    self[2] = uVar2;
                } else {
                    if (0xffff02ff < uVar1) {
                        if (uVar1 != 0xffff0300) {
                            bVar6 = (uVar1 == 0xffff03ff);
LAB_00625186:
                            if (!bVar6) goto LAB_00625188;
                        }
                        goto LAB_0062518d;
                    }
                    if (uVar1 == 0xffff02ff) {
LAB_00625141:
                        iVar5 = (int)(intptr_t)FUN_00533c78(0x22c);
                        if (iVar5 == 0) goto LAB_006251a8;
                        uVar2 = (uint32_t)FUN_0067e9a7(param_7);
                        goto LAB_006251aa;
                    }
                    if (0xffff0100 < uVar1) {
                        if (uVar1 < 0xffff0105) {
                            self[5] = uVar3 & 0xfffffffb;
                            iVar5 = (int)(intptr_t)FUN_00533c78(0x484);
                            if (iVar5 == 0) goto LAB_006251a8;
                            uVar2 = (uint32_t)FUN_00672ecd();
                            goto LAB_006251aa;
                        }
                        if ((uVar1 == 0xffff0200) || ((0xffff0201 < uVar1 && (uVar1 < 0xffff0204))))
                            goto LAB_00625141;
                    }
LAB_00625188:
                    self[2] = 0;
                }
                if (self[2] == 0) {
LAB_006251b2:
                    iVar5 = (int)-0x7ff8fff2;
                    goto LAB_00625396;
                }
                if (param_2 == 0) {
                    puVar7 = self + 1;
                    uVar3 = self[5] | 0x80000000;
                    uVar2 = self[0];
                    FUN_006321e1(uVar2, uVar3, puVar7);
                    iVar5 = FUN_0063d60d(uVar2, uVar3, puVar7);
                    FUN_006338c7();
                    if (-1 < iVar5) goto LAB_006251fe;
                } else {
                    self[1] = (uint32_t)param_2;
LAB_006251fe:
                    if (local_c != 0) {
                        FUN_00615c1d();
                    }
                    if (local_10 != 0) {
                        FUN_00615c1d();
                    }
                    if (self[0x22] == 0) {
                        self[0x23] = 0x1000;
                        iVar5 = (int)(intptr_t)FUN_00533c78(0x4000);
                        self[0x22] = (uint32_t)iVar5;
                        if (iVar5 == 0) goto LAB_006251b2;
                    }
                    FUN_0065d5fa(local_38);
                    FUN_0065d07f(local_38);
                    iVar5 = FUN_006233ff();
                    if (-1 < iVar5) {
                        if (param_5 == 0) {
                            if (param_3 == 0) {
                                iVar5 = FUN_00615933(param_4, &param_3);
                                if (iVar5 != 0) {
                                    uVar2 = 1;
                                    goto LAB_006252e9;
                                }
                                FUN_00615bbb();
                            } else {
                                iVar5 = FUN_0061581d(param_3);
                                if (iVar5 != 0) {
                                    uVar2 = 0;
LAB_006252e9:
                                    iVar5 = FUN_0062294a(param_3, iVar5, param_6, 0, 1, uVar2);
                                    goto LAB_006252fb;
                                }
                                FUN_00615bbb();
                            }
LAB_006252dc:
                            iVar5 = (int)-0x7fffbffb;
                        } else {
                            iVar5 = (int)FUN_00624db7((void*)self, param_5);
LAB_006252fb:
                            if (-1 < iVar5) {
                                if (self[0x13] != 0) goto LAB_006252dc;
                                iVar5 = FUN_00615a6f();
                                if (-1 < iVar5) {
                                    void** v2 = *(void***)self[2];
                                    iVar5 = ((int(__cdecl*)(void*, int**))v2[2])((void*)self[2], &local_8);
                                }
                                if (-1 < iVar5) {
                                    if (param_11 != nullptr) {
                                        puVar7 = &local_14;
                                        uVar2 = (uint32_t)((uint32_t(*)(int*, uint32_t*))*(void**)(*local_8 + 0xc))(local_8, puVar7);
                                        iVar5 = FUN_005f8091(uVar2, puVar7);
                                        if (iVar5 < 0) {
                                            if (local_8 != nullptr) {
                                                ((void(__cdecl*)(int*))*(void**)(*local_8 + 8))(local_8);
                                                local_8 = nullptr;
                                            }
                                            goto LAB_0062536b;
                                        }
                                    }
                                    if (param_10 != nullptr) {
                                        *param_10 = (uint32_t)(uintptr_t)local_8;
                                    }
                                    if (param_11 != nullptr) {
                                        *param_11 = local_14;
                                    }
                                    iVar5 = 0;
                                }
                            }
                        }
                    }
                }
LAB_0062536b:
                self[1] = 0;
                if ((void*)self[2] != nullptr) {
                    void** vtbl = *(void***)self[2];
                    ((void(__cdecl*)(void*, int))vtbl[0])((void*)self[2], 1);
                }
                self[2] = 0;
                operator_delete((void*)self[6]);
                self[6] = 0;
                FUN_0065d5fa(nullptr);
                FUN_0065d07f(nullptr);
                goto LAB_00625396;
            }
        } else {
            iVar5 = FUN_005f7fa4((int)param_8, 2, local_20);
            if (-1 < iVar5) {
                if ((local_1c & 0xffff0000) == 0xfffe0000) {
                    if ((uVar3 & 0x40) != 0) {
                        uVar3 = uVar3 | 5;
                        if ((local_1c & 0xff00) == 0x300) {
                            self[3] = (uint32_t)(uintptr_t)"vs_3_sw";
                        } else {
                            self[3] = (uint32_t)(uintptr_t)"vs_2_sw";
                        }
                    }
                } else if (((local_1c & 0xffff0000) == 0xffff0000) && (cVar4 < '\0')) {
                    uVar3 = uVar3 | 5;
                    if ((local_1c & 0xff00) == 0x300) {
                        self[3] = (uint32_t)(uintptr_t)"ps_3_sw";
                    } else {
                        self[3] = (uint32_t)(uintptr_t)"ps_2_sw";
                    }
                }
                goto LAB_00625041;
            }
        }
        FUN_00615bbb();
    }
    iVar5 = (int)-0x7789f794;
LAB_00625396:
    FUN_0065aa8a();
    return iVar5;
}

// 0x6253a7 — observed shape
uint32_t FUN_006253a7(void* self, uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4, uint32_t param_5,
                     uint32_t param_6, uint32_t* param_7, uint32_t* param_8) {
    uint32_t uVar1;
    if (param_7 != nullptr) {
        *param_7 = 0;
    }
    if (param_8 != nullptr) {
        *param_8 = 0;
    }
    if (param_3 == 0) {
        uVar1 = 0x8876086c;
    } else {
        uVar1 = (uint32_t)FUN_00624eb8((uint32_t*)self, param_1, (int)param_2, param_3, 0, 0, 0, param_4, param_5, param_6, param_7, param_8);
    }
    return uVar1;
}

// 0x6253ee — observed shape
void FUN_006253ee(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t* param_8,
                  uint32_t* param_9) {
    if (param_8 != nullptr) {
        *param_8 = 0;
    }
    if (param_9 != nullptr) {
        *param_9 = 0;
    }
    FUN_00624eb8((uint32_t*)self, param_1, (int)param_2, 0, param_3, 0, param_4, param_5, param_6, param_7 & 0xffffffe7, param_8, param_9);
    return;
}

// 0x62542f — observed shape
int FUN_0062542f(void* self, uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4, uint32_t param_5,
                 uint32_t* param_6, uint32_t* param_7) {
    char* pcVar1;
    char cVar2;
    int* piVar3;
    int iVar4;
    int iVar5;
    uint32_t* puVar6;
    char* pcVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t* puVar10;
LAB_00625443:
    if (param_6 != nullptr) {
        *param_6 = 0;
    }
    if (param_7 != nullptr) {
        *param_7 = 0;
    }
    param_5 = param_5 & 0xffffffe7;
    *(uint32_t*)self = param_1;
    iVar4 = FUN_00616109(param_3);
    if (iVar4 == 0) {
        if (*(int*)(param_3 + 4) == 0xd) {
            iVar4 = param_3;
            if ((uint32_t)(*(int*)(param_3 + 0x18) * *(int*)(param_3 + 0x14)) < 2) {
                do {
                    if (*(int*)(iVar4 + 0x1c) != 0) goto LAB_00625493;
                    while ((iVar4 = *(int*)(iVar4 + 0x20), *(int*)(iVar4 + 4) != 0xd)) {
LAB_00625493:
                        do {
                            if (*(int*)(iVar4 + 4) != 1) break;
                            iVar4 = *(int*)(iVar4 + 8);
                        } while (iVar4 != 0);
                        if ((*(int*)(iVar4 + 4) != 0xd) || (*(int*)(iVar4 + 0x1c) != 0)) {
                            if ((*(int*)(iVar4 + 4) == 0xd) && (*(int*)(iVar4 + 0x1c) == 0x1b)) {
                                iVar4 = FUN_006253ee(self, param_1, param_2,
                                                     *(uint32_t*)(*(int*)(iVar4 + 0x24) + 0x20),
                                                     *(uint32_t*)(*(int*)(iVar4 + 0x24) + 0x24), 0,
                                                     *(uint32_t*)(*(int*)(iVar4 + 0x20) + 0x18), param_5, param_6,
                                                     param_7);
                                return iVar4;
                            }
                            if (*(int*)(iVar4 + 4) == 0xe) {
                                if ((*(int*)(iVar4 + 0x10) == 4) && (*(int*)(*(int*)(iVar4 + 0x18) + 4) == 0xd)) {
                                    param_3 = *(int*)(iVar4 + 0x18);
                                    goto LAB_00625443;
                                }
                                if (*(int*)(iVar4 + 0x10) == 5) {
                                    if (param_6 != nullptr) {
                                        iVar5 = FUN_006294f9((uint32_t)*(int*)(iVar4 + 0x1c), param_6);
                                        if (iVar5 < 0) {
                                            return iVar5;
                                        }
                                        uVar9 = *(uint32_t*)(iVar4 + 0x1c);
                                        puVar10 = *(uint32_t**)(iVar4 + 0x18);
                                        {
                                            uint32_t objAddr = *param_6;
                                            void** vtbl = *(void***)(uintptr_t)objAddr;
                                            puVar6 = (uint32_t*)((uint32_t*(*)(void*))vtbl[3])((void*)(uintptr_t)objAddr);
                                        }
                                        for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                                            *puVar6 = *puVar10;
                                            puVar10 = puVar10 + 1;
                                            puVar6 = puVar6 + 1;
                                        }
                                        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                                            *(uint8_t*)puVar6 = *(uint8_t*)puVar10;
                                            puVar10 = (uint32_t*)((int)(uintptr_t)puVar10 + 1);
                                            puVar6 = (uint32_t*)((int)(uintptr_t)puVar6 + 1);
                                        }
                                    }
                                    if (param_7 != nullptr) {
                                        *param_7 = 0;
                                    }
                                    return 0;
                                }
                                if (((*(int*)(iVar4 + 0x10) == 6) && (*(int*)(iVar4 + 0x20) == 9)) &&
                                    (pcVar7 = *(char**)(iVar4 + 0x28), pcVar7 != nullptr)) {
                                    if (param_6 != nullptr) {
                                        pcVar1 = pcVar7 + 1;
                                        do {
                                            cVar2 = *pcVar7;
                                            pcVar7 = pcVar7 + 1;
                                        } while (cVar2 != '\0');
                                        iVar5 = FUN_006294f9((uint32_t)((int)(uintptr_t)pcVar7 + (1 - (int)(uintptr_t)pcVar1)), param_6);
                                        if (iVar5 < 0) {
                                            return iVar5;
                                        }
                                        piVar3 = (int*)*param_6;
                                        {
                                            void** vtbl = *(void***)piVar3;
                                            uVar9 = (uint32_t)((uint32_t(*)(void*))vtbl[4])(piVar3);
                                        }
                                        puVar10 = *(uint32_t**)(iVar4 + 0x28);
                                        {
                                            void** vtbl = *(void***)piVar3;
                                            puVar6 = (uint32_t*)((uint32_t*(*)(void*))vtbl[3])(piVar3);
                                        }
                                        for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                                            *puVar6 = *puVar10;
                                            puVar10 = puVar10 + 1;
                                            puVar6 = puVar6 + 1;
                                        }
                                        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                                            *(uint8_t*)puVar6 = *(uint8_t*)puVar10;
                                            puVar10 = (uint32_t*)((int)(uintptr_t)puVar10 + 1);
                                            puVar6 = (uint32_t*)((int)(uintptr_t)puVar6 + 1);
                                        }
                                    }
                                    if (param_7 == nullptr) {
                                        return 0;
                                    }
                                    *param_7 = 1;
                                    return 0;
                                }
                            }
                            pcVar7 = (char*)"non-trivial object expressions not yet implemented";
                            goto LAB_00625636;
                        }
                    }
                } while (true);
            }
            pcVar7 = (char*)"expressions returning objects in an array or struct not yet implemented";
LAB_00625636:
            FUN_00615bbb(self, param_3, 0xdac, pcVar7);
            iVar4 = (int)-0x7fffbfff;
        } else {
            FUN_00615bbb(self, param_3, 0, "internal error: expression expected");
            iVar4 = (int)-0x7fffbffb;
        }
    } else {
        if ((((param_3 != 0) && (*(int*)(param_3 + 4) == 0xd)) &&
             (iVar4 = *(int*)(param_3 + 0x10), iVar4 != 0)) && (*(int*)(iVar4 + 4) == 9)) {
            *(uint8_t*)(iVar4 + 0x21) = (uint8_t)(*(uint8_t*)(iVar4 + 0x21) & 0xf3);
        }
        iVar4 = FUN_00624eb8((uint32_t*)self, param_1, (int)param_2, 0, 0, param_3, 0, 0, param_4, param_5, param_6, param_7);
    }
    return iVar4;
}

// 0x62564d — observed shape
void FUN_0062564d(int param_1, int param_2, short* param_3, int param_4, int* param_5, int* param_6) {
    short* psVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    short* psVar4;
    int iVar5;
    uint32_t uVar6;
    int* piVar7;
    psVar4 = param_3;
    psVar1 = param_3 + 5;
    if (*psVar1 == 0) {
        if (*(short*)(param_2 + 4) == 0) {
            uVar6 = (uint32_t)(uint16_t)param_3[3];
            uVar2 = (uint16_t)param_3[2];
        } else {
            if (*param_3 == 3) {
                uVar3 = (uint16_t)param_3[2];
                uVar2 = (uint16_t)param_3[3];
            } else {
                uVar3 = (uint16_t)param_3[3];
                uVar2 = (uint16_t)param_3[2];
            }
            uVar6 = (uint32_t)((int)(uVar3 + 3) >> 2);
        }
        *param_5 = *param_5 + (int)(uVar6 * uVar2 * (uint32_t)param_4);
        *param_6 = *param_6 + (int)((uint32_t)(uint16_t)param_3[3] * (uint32_t)(uint16_t)param_3[2] * (uint32_t)param_4);
    } else {
        piVar7 = (int*)(param_3 + 6);
        param_3 = (short*)0x0;
        if (*psVar1 != 0) {
            piVar7 = (int*)(*piVar7 + *(int*)(param_1 + 8) + 4);
            do {
                if (*piVar7 != 0) {
                    iVar5 = *(int*)(param_1 + 8) + *piVar7;
                    FUN_0062564d(param_1, param_2, (short*)iVar5,
                                 (int)((uint32_t)*(uint16_t*)(iVar5 + 8) * (uint32_t)param_4), param_5, param_6);
                }
                param_3 = (short*)((int)(uintptr_t)param_3 + 1);
                piVar7 = piVar7 + 2;
            } while ((uint32_t)(uint16_t)psVar4[5] > (uint32_t)(uintptr_t)param_3);
        }
    }
    return;
}

// 0x625708 — observed shape
uint32_t FUN_00625708(const char* self, const char* peer, uint32_t param_1) {
    uint32_t uVar3 = 0;
    bool bVar4 = (param_1 == 0);
    if (param_1 != 0) {
        intptr_t iVar2 = (intptr_t)peer - (intptr_t)self;
        const char* p = self;
        do {
            if (p[iVar2] < *p) {
                return 0xffffffff;
            }
            if (*p < p[iVar2]) goto LAB_00625737;
            uVar3 = uVar3 + 1;
            p = p + 1;
        } while (uVar3 < param_1);
        bVar4 = (uVar3 == param_1);
    }
    if ((bVar4) && (*(char*)(uVar3 + (uintptr_t)peer) != '\0')) {
LAB_00625737:
        return 1;
    } else {
        return 0;
    }
}

// 0x625749 — observed shape
int FUN_00625749(void* self, uint32_t param_1, uint32_t* param_2, int param_3, uint32_t param_4, uint32_t param_5) {
    int* piVar1;
    int* piVar2;
    uint32_t* in_ECX = (uint32_t*)self;
    int iVar3;
    int extraout_EDX;
    uint32_t* puVar4 = param_2;
    uint32_t* puVar5 = in_ECX;
    *in_ECX = param_1;
    for (iVar3 = 5; puVar5 = puVar5 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
    }
    piVar1 = (int*)(in_ECX + 0xd);
    piVar2 = (int*)(in_ECX + 0xb);
    in_ECX[7] = param_4;
    in_ECX[8] = param_5;
    in_ECX[6] = (uint32_t)param_3;
    in_ECX[9] = 0;
    *piVar2 = 0;
    *piVar1 = 0;
    FUN_0062564d((int)(intptr_t)param_1, (int)(intptr_t)param_2, (short*)param_3, 1, piVar2, piVar1);
    extraout_EDX = (int)(intptr_t)self;
    *(uint32_t*)(extraout_EDX + 0x28) = (uint32_t)*(uint16_t*)(param_3 + 8) * (uint32_t)*piVar2;
    *(uint32_t*)(extraout_EDX + 0x30) = (uint32_t)*(uint16_t*)(param_3 + 8) * (uint32_t)*piVar1;
    *(uint32_t*)(extraout_EDX + 0x38) = 0;
    *(uint32_t*)(extraout_EDX + 0x3c) = 0;
    *(uint32_t*)(extraout_EDX + 0x40) = 0;
    return extraout_EDX;
}

// NEEDS_MANUAL: provider emits the recursive call as FUN_006257ba() with the parent's ECX;
// the child element is the only sensible receiver for the subtree free, so it is passed explicitly.
// 0x6257ba — observed shape
void FUN_006257ba(void* self) {
    void* pvVar1;
    uint32_t uVar2;
    int base18 = *(int*)((uint8_t*)self + 0x18);
    uVar2 = 0;
    if (*(int*)((uint8_t*)self + 0x38) != 0) {
        if (*(short*)(base18 + 10) != 0) {
            do {
                pvVar1 = *(void**)(*(int*)((uint8_t*)self + 0x38) + uVar2 * 4);
                if (pvVar1 != nullptr) {
                    FUN_006257ba(pvVar1);
                    operator_delete(pvVar1);
                }
                uVar2 = uVar2 + 1;
            } while (uVar2 < *(uint16_t*)(base18 + 10));
        }
        operator_delete(*(void**)((uint8_t*)self + 0x38));
    }
    uVar2 = 0;
    if (*(int*)((uint8_t*)self + 0x3c) != 0) {
        if (*(short*)(base18 + 8) != 0) {
            do {
                pvVar1 = *(void**)(*(int*)((uint8_t*)self + 0x3c) + uVar2 * 4);
                if (pvVar1 != nullptr) {
                    FUN_006257ba(pvVar1);
                    operator_delete(pvVar1);
                }
                uVar2 = uVar2 + 1;
            } while (uVar2 < *(uint16_t*)(base18 + 8));
        }
        operator_delete(*(void**)((uint8_t*)self + 0x3c));
    }
    operator_delete(*(void**)((uint8_t*)self + 0x40));
    return;
}

// 0x625848 — observed shape
uint32_t FUN_00625848(void* self, uint32_t param_1) {
    int iVar1;
    uint32_t iVar2 = param_1;
    uint32_t idx = 0;
    *(int*)((uint8_t*)self + 0x20) = (int)iVar2;
    int base18 = *(int*)((uint8_t*)self + 0x18);
    if (*(short*)(base18 + 10) != 0) {
        do {
            FUN_00625848(self, iVar2);
            iVar1 = *(int*)(*(int*)((uint8_t*)self + 0x38) + idx * 4);
            idx = idx + 1;
            uint32_t factor = (uint32_t)((-(uint32_t)(*(short*)(iVar1 + 8) != 0) & 3) + 1);
            iVar2 = iVar2 + factor * (uint32_t)*(uint16_t*)(*(int*)(iVar1 + 0x18) + 8) * (uint32_t)*(int*)(iVar1 + 0x2c) * 4;
        } while (idx < *(uint16_t*)(base18 + 10));
    }
    return 0;
}

// 0x6258b4 — observed shape
uint32_t FUN_006258b4(void* self, int* param_1) {
    int iVar1;
    int* in_ECX = (int*)self;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    if (in_ECX[1] == 0) {
        iVar1 = 0;
    } else {
        iVar1 = *(int*)(*in_ECX + 8) + in_ECX[1];
    }
    *param_1 = iVar1;
    param_1[1] = (int)*(uint16_t*)(in_ECX + 2);
    param_1[2] = (int)*(uint16_t*)((uintptr_t)in_ECX + 10);
    param_1[3] = (int)*(uint16_t*)(in_ECX + 3);
    param_1[4] = (int)*(uint16_t*)in_ECX[6];
    param_1[5] = (int)*(uint16_t*)(in_ECX[6] + 2);
    param_1[6] = (int)*(uint16_t*)(in_ECX[6] + 4);
    param_1[7] = (int)*(uint16_t*)(in_ECX[6] + 6);
    param_1[8] = (int)*(uint16_t*)(in_ECX[6] + 8);
    param_1[9] = (int)*(uint16_t*)(in_ECX[6] + 10);
    param_1[10] = param_1[8] * param_1[6] * param_1[7] * 4;
    if (in_ECX[5] == 0) {
        iVar1 = 0;
    } else {
        iVar1 = *(int*)(*in_ECX + 8) + in_ECX[5];
    }
    param_1[0xb] = iVar1;
    return 0;
}

// 0x625957 — observed shape
uint32_t FUN_00625957(void* self, uint32_t param_1) {
    uint32_t uVar1;
    int base18 = *(int*)((uint8_t*)self + 0x18);
    if (param_1 < *(uint16_t*)(base18 + 10)) {
        uVar1 = *(uint32_t*)(*(int*)((uint8_t*)self + 0x38) + param_1 * 4);
    } else {
        uVar1 = 0;
    }
    return uVar1;
}

// 0x625978 — observed shape
int FUN_00625978(void* self, uint32_t param_1, int param_2) {
    int iVar1;
    int* in_ECX = (int*)self;
    if ((in_ECX[5] == 0) ||
        (iVar1 = (*(int(*)(uint32_t, uint32_t, int, uint32_t, int16_t))in_ECX[7])
                     (param_1, (uint32_t)*(uint16_t*)((uintptr_t)in_ECX + 10) + (uint32_t)param_2,
                      *(int*)(*in_ECX + 8) + in_ECX[5] +
                      ((-(uint32_t)((int16_t)in_ECX[2] != 0) & 3) + 1) * (uint32_t)param_2 * 4,
                      (uint32_t)in_ECX[8], (int16_t)in_ECX[3]), -1 < iVar1)) {
        return 0;
    }
    return iVar1;
}

// 0x6259c4 — observed shape
uint32_t FUN_006259c4(int* param_1, int* param_2, uint32_t* param_3) {
    int iVar1;
    int* piVar2;
    int* piVar3;
    bool bVar4;
    *param_3 = 0;
    iVar1 = 4;
    bVar4 = true;
    piVar2 = param_2;
    piVar3 = (int*)DAT_006f5200;
    do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = (*piVar2 == *piVar3);
        piVar2 = piVar2 + 1;
        piVar3 = piVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
        iVar1 = 4;
        bVar4 = true;
        piVar2 = (int*)DAT_006dd2b4;
        do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar4 = (*param_2 == *piVar2);
            param_2 = param_2 + 1;
            piVar2 = piVar2 + 1;
        } while (bVar4);
        if (!bVar4) {
            return 0x80004002;
        }
    }
    *param_3 = (uint32_t)(uintptr_t)param_1;
    ((void(__cdecl*)(int*))*(void**)(*param_1 + 4))(param_1);
    return 0;
}

// 0x625a0d — observed shape
uint32_t FUN_00625a0d(int param_1, int* param_2) {
    uint32_t* puVar1;
    uint32_t uVar2;
    int iVar3;
    if (param_2 == nullptr) {
        uVar2 = 0x8876086c;
    } else if (((*(uint32_t*)(param_1 + 0xc) < 0x1c) || (puVar1 = *(uint32_t**)(param_1 + 8), *puVar1 < 0x1c))
               || (*(uint32_t*)(param_1 + 0xc) <= puVar1[1])) {
        uVar2 = 0x88760b59;
    } else {
        *param_2 = 0;
        param_2[1] = 0;
        param_2[2] = 0;
        if (puVar1[1] == 0) {
            iVar3 = 0;
        } else {
            iVar3 = *(int*)(param_1 + 8) + (int)puVar1[1];
        }
        *param_2 = iVar3;
        param_2[1] = (int)puVar1[2];
        param_2[2] = (int)puVar1[3];
        uVar2 = 0;
    }
    return uVar2;
}

// 0x625a6e — observed shape
int FUN_00625a6e(void* self, int param_1, uint32_t param_2) {
    int iVar1;
    uint32_t uVar2 = 0;
    if (*(int*)(param_1 + 0x18) != 0) {
        do {
            iVar1 = FUN_00625978(self, param_2, 0);
            if (iVar1 < 0) {
                return iVar1;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(param_1 + 0x18));
    }
    return 0;
}

// 0x625aa1 — observed shape
void FUN_00625aa1(int* param_1, uint32_t param_2, int param_3, uint32_t* param_4, int param_5) {
    int iVar1;
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        iVar1 = param_3 - (int)(uintptr_t)param_4;
        do {
            *param_4 = (uint32_t)(*(int*)(iVar1 + (int)(uintptr_t)param_4) != 0);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    ((void(__cdecl*)(int*, uint32_t, int, int))*(void**)(*param_1 + 0x1bc))(param_1, param_2, param_3, param_5);
    return;
}

// 0x625ae5 — observed shape
void FUN_00625ae5(int* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5) {
    ((void(__cdecl*)(int*, uint32_t, uint32_t, uint32_t))*(void**)(*param_1 + 0x1bc))(param_1, param_2, param_3, param_5);
    return;
}

// 0x625b03 — observed shape
void FUN_00625b03(int* param_1, uint32_t param_2, int param_3, int* param_4, int param_5) {
    int iVar1;
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        iVar1 = param_3 - (int)(uintptr_t)param_4;
        do {
            float f = *(float*)(iVar1 + (int)(uintptr_t)param_4);
            *param_4 = (int)roundf(f); // observed ROUND(f32) — ties away from zero
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    ((void(__cdecl*)(int*, uint32_t, int, int))*(void**)(*param_1 + 0x1bc))(param_1, param_2, param_3, param_5);
    return;
}
