#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete__(void*);
extern void operator_delete(void*);
extern void* thunk_FUN_00533c78(intptr_t);
extern char* DAT_00728e04;
extern void FUN_0055a2e0(uint32_t);
extern void FUN_0055a310(void);
extern void* PTR_FUN_006c799c;

// 0x5c9d30 — observed shape
void FUN_005c9d30(char* param_1) {
    char cVar1;
    char* pcVar2;
    int iVar3;
    char* pcVar4;
    bool bVar5;
    operator_delete__(DAT_00728e04);
    if (param_1 != (char*)0x0) {
        iVar3 = 1;
        bVar5 = true;
        pcVar2 = param_1;
        pcVar4 = "";
        do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar5 = *pcVar2 == *pcVar4;
            pcVar2 = pcVar2 + 1;
            pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (!bVar5) {
            pcVar2 = param_1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            pcVar2 = (char*)thunk_FUN_00533c78(pcVar2 + (1 - (int)(param_1 + 1)));
            DAT_00728e04 = pcVar2;
            do {
                cVar1 = *param_1;
                param_1 = param_1 + 1;
                *pcVar2 = cVar1;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
        }
    }
    return;
}

// 0x5c9d90 — observed shape
void FUN_005c9d90(void* self, uint32_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_0055a2e0(param_1);
    in_ECX[4] = 0;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c799c;
    in_ECX[5] = 0;
    return;
}

// 0x5c9dc0 — observed shape
void FUN_005c9dc0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    int32_t* piVar1;
    uint32_t* puVar2;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c799c;
    puVar2 = (uint32_t*)(uintptr_t)in_ECX[5];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(uint32_t))(*puVar2))(1);
        }
        in_ECX[5] = 0;
    }
    in_ECX[4] = 0;
    puVar2 = (uint32_t*)(uintptr_t)in_ECX[5];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(uint32_t))(*puVar2))(1);
        }
    }
    FUN_0055a310();
    return;
}

// 0x5c9ea0 — observed shape
void FUN_005c9ea0(void* self, uint8_t param_1) {
    void* in_ECX = self;
    FUN_005c9ec0(in_ECX);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x5c9ec0 — observed shape
void FUN_005c9ec0(void* self) {
    void* pvVar1;
    void** in_ECX = (void**)self;
    operator_delete__(*(void**)in_ECX);
    pvVar1 = in_ECX[2];
    if (pvVar1 != (void*)0x0) {
        FUN_005c9ec0(pvVar1);
        operator_delete(pvVar1);
    }
    return;
}

extern void* PTR_DAT_00728e18;
extern uint32_t* DAT_00728e1c;

// 0x5c9f20 — observed shape
void FUN_005c9f20(int param_1) {
    *(int*)PTR_DAT_00728e18 = param_1;
    if (param_1 == 0) {
        DAT_00728e1c = (uint32_t*)0;
        return;
    }
    DAT_00728e1c = (uint32_t*)(uintptr_t)(*(int*)(param_1 + 0x5cc));
    return;
}

// 0x5c9f50 — observed shape
uint32_t FUN_005c9f50(void* self) {
    uint32_t* puVar1;
    int in_ECX = (int)(uintptr_t)self;
    for (puVar1 = *(uint32_t**)(in_ECX + 8); puVar1 != (uint32_t*)0x0; puVar1 = (uint32_t*)(uintptr_t)puVar1[2]) {
        (*(void(**)(uint32_t, uint32_t, uint32_t))(*DAT_00728e1c + 0x70))(puVar1[0], puVar1[1], 0);
    }
    for (puVar1 = *(uint32_t**)(in_ECX + 0x10); puVar1 != (uint32_t*)0x0; puVar1 = (uint32_t*)(uintptr_t)puVar1[2]) {
        (*(void(**)(uint32_t, uint32_t, uint32_t))(*DAT_00728e1c + 0x70))(puVar1[0], puVar1[1], 1);
    }
    return 0;
}

// 0x5c9fb0 — observed shape
uint32_t FUN_005c9fb0(void* self) {
    uint32_t* puVar1;
    int in_ECX = (int)(uintptr_t)self;
    for (puVar1 = *(uint32_t**)(in_ECX + 0x10); puVar1 != (uint32_t*)0x0; puVar1 = (uint32_t*)(uintptr_t)puVar1[2]) {
        (*(void(**)(uint32_t))(*DAT_00728e1c + 0x68))(puVar1[0]);
    }
    return 0;
}

// 0x5c9fe0 — observed shape
void FUN_005c9fe0(void* self, int param_1) {
    int iVar1;
    int iVar2;
    int in_ECX = (int)(uintptr_t)self;
    iVar1 = *(int*)(param_1 + 8);
    iVar2 = *(int*)(param_1 + 0xc);
    if (iVar1 != 0) {
        *(int*)(iVar1 + 0xc) = iVar2;
    }
    if (iVar2 != 0) {
        *(int*)(iVar2 + 8) = iVar1;
    }
    if (param_1 == *(int*)(in_ECX + 8)) {
        *(int*)(in_ECX + 8) = iVar1;
    }
    *(int*)(in_ECX + 4) = *(int*)(in_ECX + 4) + -1;
    *(uint32_t*)(param_1 + 8) = 0;
    *(uint32_t*)(param_1 + 0xc) = 0;
    return;
}

// 0x5ca020 — observed shape
void FUN_005ca020(void* self, int param_1) {
    int iVar1;
    int iVar2;
    int in_ECX = (int)(uintptr_t)self;
    iVar1 = *(int*)(param_1 + 8);
    iVar2 = *(int*)(param_1 + 0xc);
    if (iVar1 != 0) {
        *(int*)(iVar1 + 0xc) = iVar2;
    }
    if (iVar2 != 0) {
        *(int*)(iVar2 + 8) = iVar1;
    }
    if (param_1 == *(int*)(in_ECX + 0x10)) {
        *(int*)(in_ECX + 0x10) = iVar1;
    }
    *(int*)(in_ECX + 0xc) = *(int*)(in_ECX + 0xc) + -1;
    *(uint32_t*)(param_1 + 8) = 0;
    *(uint32_t*)(param_1 + 0xc) = 0;
    return;
}

extern void* FUN_00533c78(int);
extern void FUN_004127b0(void*, int, int, void*);
extern void* LAB_005c9f00;
extern void* LAB_005c9ef0;
extern uint32_t* DAT_00728e20;
extern uint32_t* DAT_00728e24;

// 0x5ca060 — observed shape
int* FUN_005ca060(void* self, int param_1, uint8_t* param_2) {
    int* piVar1;
    int in_ECX = (int)(uintptr_t)self;
    for (piVar1 = *(int**)(in_ECX + 8); piVar1 != (int*)0x0; piVar1 = (int*)(uintptr_t)piVar1[2]) {
        if (*piVar1 == param_1) {
            *param_2 = 0;
            return piVar1;
        }
    }
    piVar1 = *(int**)(in_ECX + 0x10);
    while (true) {
        if (piVar1 == (int*)0x0) {
            return (int*)0x0;
        }
        if (*piVar1 == param_1) break;
        piVar1 = (int*)(uintptr_t)piVar1[2];
    }
    *param_2 = 1;
    return piVar1;
}

// 0x5ca0b0 — observed shape
void FUN_005ca0b0(void* self, int param_1) {
    int* piVar1;
    int* in_ECX = (int*)self;
    int* piVar2 = (int*)0x0;
    in_ECX[1] = param_1;
    in_ECX[2] = 0;
    if (param_1 != 0) {
        piVar1 = (int*)thunk_FUN_00533c78(param_1 * 0x14 + 4);
        if (piVar1 != (int*)0x0) {
            piVar2 = piVar1 + 1;
            *piVar1 = param_1;
            FUN_004127b0(piVar2, 0x14, param_1, &LAB_005c9f00);
        }
    }
    *in_ECX = (int)(uintptr_t)piVar2;
    return;
}

// 0x5ca100 — observed shape
void FUN_005ca100(void* self, int param_1) {
    int iVar1;
    int* in_ECX = (int*)self;
    in_ECX[1] = param_1;
    in_ECX[2] = 0;
    if (param_1 == 0) {
        *in_ECX = 0;
        return;
    }
    iVar1 = (int)(uintptr_t)thunk_FUN_00533c78(param_1 << 4);
    if (iVar1 == 0) {
        *in_ECX = 0;
        return;
    }
    FUN_004127b0((void*)(uintptr_t)iVar1, 0x10, param_1, &LAB_005c9ef0);
    *in_ECX = iVar1;
    return;
}

// 0x5ca160 — observed shape
void FUN_005ca160(void) {
    DAT_00728e20 = (uint32_t*)FUN_00533c78(0x18);
    if (DAT_00728e20 == (uint32_t*)0x0) {
        DAT_00728e20 = (uint32_t*)0x0;
    } else {
        DAT_00728e20[0] = 0;
        DAT_00728e20[1] = 0;
        DAT_00728e20[2] = 0;
        DAT_00728e20[3] = 8;
        DAT_00728e20[4] = 8;
        DAT_00728e20[5] = 0;
    }
    DAT_00728e24 = (uint32_t*)FUN_00533c78(0x18);
    if (DAT_00728e24 == (uint32_t*)0x0) {
        DAT_00728e24 = (uint32_t*)0x0;
        return;
    }
    DAT_00728e24[0] = 0;
    DAT_00728e24[1] = 0;
    DAT_00728e24[2] = 0;
    DAT_00728e24[5] = 0;
    DAT_00728e24[3] = 0x10;
    DAT_00728e24[4] = 0x10;
    return;
}

// 0x5ca1d0 — observed shape
uint32_t FUN_005ca1d0(void* self, uint32_t param_1, uint32_t* param_2, uint32_t param_3) {
    uint32_t uVar1;
    int iVar2;
    iVar2 = (int)(uintptr_t)FUN_005ca060(self, (int)param_1, (uint8_t*)(uintptr_t)param_3);
    if (iVar2 == 0) {
        return 0;
    }
    uVar1 = *(uint32_t*)(iVar2 + 4);
    *param_2 = uVar1;
    return ((uVar1 >> 8) & 0xffffff) | (1u << 24);
}

extern void FUN_0055f300(int);
extern void FUN_005ca6f0(void);

// 0x5ca200 — observed shape
void FUN_005ca200(void* self, uint32_t param_1) {
    int iVar1;
    int iVar2;
    int* in_ECX = (int*)self;
    uint32_t uVar3;
    int iVar4;
    int* local_4;
    iVar1 = (int)(uintptr_t)FUN_00533c78(0xc);
    iVar4 = 0;
    if (iVar1 == 0) {
        local_4 = (int*)0x0;
    } else {
        FUN_005ca0b0(in_ECX, (int)param_1);
        local_4 = (int*)(uintptr_t)(*(int*)in_ECX);
    }
    uVar3 = 0;
    if (param_1 != 0) {
        do {
            if (uVar3 < (uint32_t)local_4[1]) {
                iVar1 = *(int*)(uintptr_t)((int)(uintptr_t)local_4 + iVar4) + iVar4;
            } else {
                iVar1 = 0;
            }
            iVar2 = in_ECX[1];
            if (in_ECX[2] == iVar2) {
                if (iVar2 == 0) {
                    iVar2 = 1;
                } else {
                    iVar2 = iVar2 * 2;
                }
                FUN_0055f300(iVar2);
            }
            *(int*)(*(int*)in_ECX + in_ECX[2] * 4) = iVar1;
            in_ECX[2] = in_ECX[2] + 1;
            uVar3 = uVar3 + 1;
            iVar4 = iVar4 + 0x14;
        } while (uVar3 < param_1);
    }
    local_4[2] = in_ECX[5];
    in_ECX[5] = (int)(uintptr_t)local_4;
    return;
}

// 0x5ca2a0 — observed shape
void FUN_005ca2a0(void* self, uint32_t param_1) {
    int iVar1;
    int iVar2;
    int* in_ECX = (int*)self;
    uint32_t uVar3;
    int iVar4;
    int* local_4;
    iVar1 = (int)(uintptr_t)FUN_00533c78(0xc);
    iVar4 = 0;
    if (iVar1 == 0) {
        local_4 = (int*)0x0;
    } else {
        FUN_005ca100(in_ECX, (int)param_1);
        local_4 = (int*)(uintptr_t)(*(int*)in_ECX);
    }
    uVar3 = 0;
    if (param_1 != 0) {
        do {
            if (uVar3 < (uint32_t)local_4[1]) {
                iVar1 = *(int*)(uintptr_t)((int)(uintptr_t)local_4 + iVar4) + iVar4;
            } else {
                iVar1 = 0;
            }
            iVar2 = in_ECX[1];
            if (in_ECX[2] == iVar2) {
                if (iVar2 == 0) {
                    iVar2 = 1;
                } else {
                    iVar2 = iVar2 * 2;
                }
                FUN_0055f300(iVar2);
            }
            *(int*)(*(int*)in_ECX + in_ECX[2] * 4) = iVar1;
            in_ECX[2] = in_ECX[2] + 1;
            uVar3 = uVar3 + 1;
            iVar4 = iVar4 + 0x10;
        } while (uVar3 < param_1);
    }
    local_4[2] = in_ECX[5];
    in_ECX[5] = (int)(uintptr_t)local_4;
    return;
}

// 0x5ca340 — observed shape
void FUN_005ca340(void) {
    void* pvVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    puVar3 = DAT_00728e20;
    if (DAT_00728e20 != (uint32_t*)0x0) {
        pvVar1 = (void*)(uintptr_t)DAT_00728e20[5];
        DAT_00728e20[2] = 0;
        if (pvVar1 != (void*)0x0) {
            FUN_005ca6f0(pvVar1);
            operator_delete(pvVar1);
        }
        operator_delete__((void*)(uintptr_t)(*puVar3));
        operator_delete(puVar3);
    }
    puVar3 = DAT_00728e24;
    if (DAT_00728e24 != (uint32_t*)0x0) {
        puVar2 = (uint32_t*)(uintptr_t)DAT_00728e24[5];
        DAT_00728e24[2] = 0;
        if (puVar2 != (uint32_t*)0x0) {
            operator_delete__((void*)(uintptr_t)(*puVar2));
            if (puVar2[2] != 0) {
                FUN_005c9ea0(puVar2, 1);
            }
            operator_delete(puVar2);
        }
        operator_delete__((void*)(uintptr_t)(*puVar3));
        operator_delete(puVar3);
    }
    return;
}

// 0x5ca3d0 — observed shape
void FUN_005ca3d0(void* self) {
    uint32_t* puVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    int in_ECX = (int)(uintptr_t)self;
    int* piVar5;
    int* piVar6;
    int iVar7;
    iVar7 = *(int*)(in_ECX + 8);
    piVar5 = (int*)DAT_00728e24;
    if (iVar7 != 0) {
        do {
            iVar2 = *(int*)(iVar7 + 8);
            puVar1 = (uint32_t*)(piVar5 + 2);
            uVar3 = 0;
            if (piVar5[2] != 0) {
                piVar6 = (int*)(uintptr_t)(*piVar5);
                do {
                    if (*piVar6 == iVar7) {
                        if (uVar3 != 0xffffffff) goto LAB_005ca445;
                        break;
                    }
                    uVar3 = uVar3 + 1;
                    piVar6 = piVar6 + 1;
                } while (uVar3 < *puVar1);
            }
            iVar4 = piVar5[1];
            if (piVar5[2] == iVar4) {
                if (iVar4 == 0) {
                    iVar4 = 1;
                } else {
                    iVar4 = iVar4 * 2;
                }
                FUN_0055f300(iVar4);
            }
            *(int*)(*(int*)piVar5 + *puVar1 * 4) = iVar7;
            *puVar1 = *puVar1 + 1;
            piVar5 = (int*)DAT_00728e24;
        LAB_005ca445:
            iVar7 = iVar2;
        } while (iVar2 != 0);
    }
    iVar7 = *(int*)(in_ECX + 0x10);
    if (*(int*)(in_ECX + 0x10) == 0) {
        *(uint32_t*)(in_ECX + 8) = 0;
        *(uint32_t*)(in_ECX + 0x10) = 0;
        return;
    }
    do {
        iVar2 = *(int*)(iVar7 + 8);
        puVar1 = (uint32_t*)(piVar5 + 2);
        uVar3 = 0;
        if (piVar5[2] != 0) {
            piVar6 = (int*)(uintptr_t)(*piVar5);
            do {
                if (*piVar6 == iVar7) {
                    if (uVar3 != 0xffffffff) goto LAB_005ca4b0;
                    break;
                }
                uVar3 = uVar3 + 1;
                piVar6 = piVar6 + 1;
            } while (uVar3 < *puVar1);
        }
        iVar4 = piVar5[1];
        if (piVar5[2] == iVar4) {
            if (iVar4 == 0) {
                iVar4 = 1;
            } else {
                iVar4 = iVar4 * 2;
            }
            FUN_0055f300(iVar4);
        }
        *(int*)(*(int*)piVar5 + *puVar1 * 4) = iVar7;
        *puVar1 = *puVar1 + 1;
        piVar5 = (int*)DAT_00728e24;
    LAB_005ca4b0:
        iVar7 = iVar2;
        if (iVar2 == 0) {
            *(uint32_t*)(in_ECX + 8) = 0;
            *(uint32_t*)(in_ECX + 0x10) = 0;
            return;
        }
    } while (true);
}

// 0x5ca4e0 — observed shape
void FUN_005ca4e0(void* self, uint32_t param_1, uint32_t param_2, char param_3) {
    int* piVar1;
    int* piVar2;
    int* piVar3;
    uint32_t* puVar4;
    int iVar5;
    uint32_t in_ECX = (uint32_t)(uintptr_t)self;
    uint32_t uStack_4 = in_ECX & 0xffffff;
    int* piVar6;
    int iVar7;
    iVar5 = (int)(uintptr_t)FUN_005ca060(self, (int)param_1, (uint8_t*)((uintptr_t)&uStack_4 + 3));
    piVar3 = (int*)DAT_00728e24;
    if (iVar5 == 0) {
        piVar1 = (int*)DAT_00728e24 + 2;
        if (DAT_00728e24[2] == 0) {
            piVar2 = (int*)DAT_00728e24 + 3;
            FUN_005ca2a0(self, DAT_00728e24[3]);
            *piVar2 = *piVar2 << 1;
        }
        piVar3 = (int*)(uintptr_t)(*piVar3);
        puVar4 = (uint32_t*)(uintptr_t)(*piVar3);
        iVar5 = *piVar1 + -1;
        *piVar1 = iVar5;
        *piVar3 = piVar3[iVar5];
        puVar4[0] = param_1;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[1] = param_2;
        if (param_3 != '\0') {
            if (*(int*)(in_ECX + 0x10) != 0) {
                *(uint32_t**)(*(int*)(in_ECX + 0x10) + 0xc) = puVar4;
                puVar4[2] = *(uint32_t*)(in_ECX + 0x10);
            }
            puVar4[3] = 0;
            *(uint32_t**)(in_ECX + 0x10) = puVar4;
            *(int*)(in_ECX + 0xc) = *(int*)(in_ECX + 0xc) + 1;
            return;
        }
        if (*(int*)(in_ECX + 8) != 0) {
            *(uint32_t**)(*(int*)(in_ECX + 8) + 0xc) = puVar4;
            puVar4[2] = *(uint32_t*)(in_ECX + 8);
        }
        puVar4[3] = 0;
        *(uint32_t**)(in_ECX + 8) = puVar4;
        *(int*)(in_ECX + 4) = *(int*)(in_ECX + 4) + 1;
    } else {
        *(uint32_t*)(iVar5 + 4) = param_2;
        if (((uStack_4 >> 24) & 0xff) != (uint32_t)(uint8_t)param_3) {
            if (((uStack_4 >> 24) & 0xff) == 0) {
                FUN_005c9fe0(self, iVar5);
                if (*(int*)(in_ECX + 0x10) != 0) {
                    *(int*)(*(int*)(in_ECX + 0x10) + 0xc) = iVar5;
                    *(uint32_t*)(iVar5 + 8) = *(uint32_t*)(in_ECX + 0x10);
                }
                *(uint32_t*)(iVar5 + 0xc) = 0;
                *(int*)(in_ECX + 0x10) = iVar5;
                *(int*)(in_ECX + 0xc) = *(int*)(in_ECX + 0xc) + 1;
                return;
            }
            FUN_005ca020(self, iVar5);
            if (*(int*)(in_ECX + 8) != 0) {
                *(int*)(*(int*)(in_ECX + 8) + 0xc) = iVar5;
                *(uint32_t*)(iVar5 + 8) = *(uint32_t*)(in_ECX + 8);
            }
            *(uint32_t*)(iVar5 + 0xc) = 0;
            *(int*)(in_ECX + 8) = iVar5;
            *(int*)(in_ECX + 4) = *(int*)(in_ECX + 4) + 1;
            return;
        }
    }
    return;
}
