#include <cstdint>
#include <cstddef>
#include <windows.h>
extern void operator_delete(void*);
extern void operator_delete__(void*);
extern void FUN_005d03f0(int param_1);
extern char FUN_005d0790(void);
extern char FUN_004879c0(void*, int*);
extern int FUN_005dc150(void);
extern uint32_t FUN_005d0670(uint32_t);
extern uint32_t FUN_005d0850(void*, uint32_t, uint32_t, uint32_t*, uint32_t, uint32_t);
extern uint32_t FUN_005d0650(void);
extern int FUN_005cd550(int*, int, uint32_t, uint32_t, uint32_t);
extern int FUN_005cdb30(int, uint32_t, uint16_t, uint32_t, uint32_t, int);
extern void FUN_005cd490(int, int, uint32_t*, uint32_t*, uint8_t*, uint8_t*, uint8_t*, int*, int**);
extern char FUN_005cd450(uint32_t*, uint32_t);
extern int FUN_005bfb50(uint32_t);
extern int FUN_005cde70(int, int, int, uint32_t, uint32_t, int);
extern char FUN_005bd960(uint32_t, void**);
extern void FUN_005bfa50(uint32_t);
extern void FUN_00545310(uint32_t, int);
extern void* DAT_00727cc8;
extern void* DAT_007278d4;

// 0x5c1510 — observed shape
void FUN_005c1510(void* self, int param_1) {
    char* obj = (char*)self;
    if ((param_1 != 0) && (*(int*)(param_1 + 0x10) != 0) && (*(int*)(*(int*)(param_1 + 0x10) + 0x28) != 0)) {
        int local_14 = *(int*)(param_1 + 0x10);
        if (*(int*)(param_1 + 0xc) != 0) {
            int local_4 = *(int*)(param_1 + 0xc);
            int local_c;
            int local_8;
            void* local_10;
            char cVar3;
            DWORD tid;
            do {
                int iVar6 = *(int*)(local_14 + 0x28);
                local_c = iVar6;
                if ((*(int*)(iVar6 + 0x14) != 0) && (*(int*)(*(int*)(iVar6 + 0x1c)) != 0)) {
                    tid = GetCurrentThreadId();
                    if (*(DWORD*)(obj + 0x30) != tid) {
                        EnterCriticalSection((LPCRITICAL_SECTION)(obj + 0x18));
                        tid = GetCurrentThreadId();
                        *(DWORD*)(obj + 0x30) = tid;
                    }
                    *(int*)(obj + 0x34) = *(int*)(obj + 0x34) + 1;
                    local_8 = 0;
                    if (*(int*)(iVar6 + 0x14) != 0) {
                        while (true) {
                            int iVar5;
                            uint32_t uVar11;
                            if (*(int*)(iVar6 + 0x14) == 0) { iVar5 = 0; }
                            else { iVar5 = *(int*)(*(int*)(iVar6 + 0x1c) + local_8 * 4); }
                            uVar11 = (uint32_t)local_8;
                            uint32_t uVar2 = *(uint32_t*)(iVar5 + 4);
                            local_10 = (void*)0x0;
                            cVar3 = FUN_005bd960(uVar2, &local_10);
                            if (cVar3 != '\0') {
                                if (local_10 != (void*)0x0) {
                                    void* pvVar8 = (void*)0x0;
                                    void* pvVar9 = local_10;
                                    do {
                                        if (*(int*)((int)pvVar9 + 8) == local_14) {
                                            void* pvVar10 = (void*)0x0;
                                            if (pvVar8 == (void*)0x0) {
                                                if (*(int*)((int)pvVar9 + 0x2c) == 0) { FUN_005bfa50(uVar2); }
                                                else { FUN_00545310(uVar2, *(int*)((int)pvVar9 + 0x2c)); pvVar10 = *(void**)((int)pvVar9 + 0x2c); }
                                            } else {
                                                *(uint32_t*)((int)pvVar8 + 0x2c) = *(uint32_t*)((int)pvVar9 + 0x2c);
                                                pvVar10 = *(void**)((int)pvVar9 + 0x2c);
                                            }
                                            *(uint32_t*)((int)pvVar9 + 0x2c) = 0;
                                            operator_delete(pvVar9);
                                            pvVar9 = pvVar8;
                                            uVar11 = (uint32_t)local_8;
                                        } else { pvVar10 = *(void**)((int)pvVar9 + 0x2c); }
                                        pvVar8 = pvVar9;
                                        pvVar9 = pvVar10;
                                    } while (pvVar10 != (void*)0x0);
                                }
                                iVar6 = local_c;
                            }
                            local_8 = (int)(uVar11 + 1);
                            if (!(local_8 < *(uint*)(iVar6 + 0x14))) break;
                        }
                    }
                    int tid2 = (int)GetCurrentThreadId();
                    if (*(int*)(obj + 0x30) == tid2) {
                        int* piVar1 = (int*)(obj + 0x34);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            *(uint32_t*)(obj + 0x30) = 0;
                            LeaveCriticalSection((LPCRITICAL_SECTION)(obj + 0x18));
                        }
                    }
                }
                local_14 = local_14 + 0x2c;
                local_4 = local_4 + -1;
            } while (local_4 != 0);
        }
        FUN_005d03f0(param_1);
    }
}

// 0x5c16c0 — observed shape
void FUN_005c16c0(int param_1) {
    operator_delete__(*(void**)(param_1 + 0x20));
    *(uint32_t*)(param_1 + 0x1c) = 0;
    *(uint32_t*)(param_1 + 0x24) = 4;
    *(uint32_t*)(param_1 + 0x20) = 0;
    operator_delete__(*(void**)(param_1 + 0x28));
    *(uint32_t*)(param_1 + 0x28) = 0;
}

// 0x5c1700 — observed shape
void FUN_005c1700(void* self) {
    int* in_ECX = (int*)self;
    int iVar1 = in_ECX[0x186];
    while (iVar1 != 0) {
        ((void(*)(uint32_t))(**(void***)(*(int*)in_ECX + 0x130)))(*(uint32_t*)(in_ECX[0x184] + 8));
        iVar1 = in_ECX[0x186];
    }
}

// 0x5c1730 — observed shape
uint32_t FUN_005c1730(uint32_t* param_1, int* param_2, int param_3, int* param_4, uint32_t param_5, uint32_t param_6) {
    int* piVar1 = param_2;
    if ((param_1 == (uint32_t*)0x0) || (param_2 == (int*)0x0)) { return 0; }
    char cVar2 = FUN_005d0790();
    if ((((char)param_6 == '\0') && (cVar2 != '\0')) && ((*(uint16_t*)((int)param_2 + 0x32) & 0xf000) == 0x4000)) { return 0x4001; }
    uint32_t uVar4;
    if (param_2[9] == 0) { uVar4 = *param_1 & 0xff7fffff; } else { uVar4 = *param_1 | 0x800000; }
    *param_1 = (uVar4 & 0xffffff) | ((*(uint8_t*)(param_2 + 0xc) & 0x3f) << 0x18);
    uVar4 = ((uint32_t(*)(void))(**(void***)(*param_2 + 0x38)))();
    param_2 = (int*)0x0;
    uint32_t uStack_18 = 0;
    uint32_t uStack_10 = 0;
    uint32_t uStack_c = 0;
    uint32_t uStack_14 = 0;
    for (uint32_t* puVar5 = (uint32_t*)(((uint32_t(*)(void))(**(void***)(*piVar1 + 4)))()); puVar5 != (uint32_t*)0x0; puVar5 = (uint32_t*)puVar5[1]) {
        if (puVar5 == (uint32_t*)DAT_00727cc8) {
            uStack_10 = ((uint32_t(*)(void))(**(void***)(*piVar1 + 0x44)))();
            param_2 = (int*)piVar1[0x11];
            uStack_18 = 0;
            uStack_c = 1;
            uStack_14 = (uStack_10 & 0xffff) * 3;
            goto LAB_005c1820;
        }
    }
    {
        char cVar3 = FUN_004879c0(DAT_007278d4, piVar1);
        if (cVar3 != '\0') {
            uStack_10 = ((uint32_t(*)(void))(**(void***)(*piVar1 + 0x44)))();
            param_2 = (int*)piVar1[0x12];
            uStack_18 = (uint32_t)piVar1[0x11];
            uStack_c = (uint32_t)*(uint16_t*)(piVar1 + 0x10);
            uStack_14 = (uStack_10 & 0xffff) + uStack_c * 2;
        }
    }
LAB_005c1820:
    uint32_t uStack_20;
    if (param_4 == (int*)0x0) { uStack_20 = 1; } else { uStack_20 = (uint32_t)param_4[9]; }
    uint32_t uVar10 = *(uint16_t*)((int)piVar1 + 0x32) & 0xfff;
    if ((param_3 != 0) && (*(int*)(param_3 + 0x18) != FUN_005dc150())) {
        uVar10 = uVar10 | 3;
        *(uint32_t*)(param_3 + 0x18) = (uint32_t)FUN_005dc150();
    }
    if (((*(uint16_t*)((int)piVar1 + 0x32) & 0xf000) == 0x8000) || ((char)param_6 != '\0')) { uVar10 = 0xfff; }
    if (cVar2 == '\0') {
        uint32_t uVar8 = 0;
        if (uStack_20 != 0) {
            do {
                ((void(*)(uint32_t*, uint32_t))(**(void***)(*(int*)param_1[1] + 0x24)))(param_1, uVar8);
                uVar8 = uVar8 + 1;
            } while (uVar8 < uStack_20);
        }
        FUN_005d0670(uStack_20);
        param_1[0xb] = 0;
    } else {
        if (uStack_20 != param_1[5]) { FUN_005d0670(uStack_20); }
    }
    uVar10 = 0xfff;
    param_1[0x11] = (uint32_t)param_2;
    param_1[0xe] = uStack_10 & 0xffff;
    param_1[4] = uVar4 & 0xffff;
    param_1[0x10] = uStack_18;
    param_1[0xf] = uStack_c & 0xffff;
    uint32_t loopParam6 = param_6;
    if (((uVar10 & 0xffef) != 0) && (loopParam6 = 0, uStack_20 != 0)) {
        do {
            uint32_t uVar7;
            if (loopParam6 < param_1[5]) { uVar7 = *(uint32_t*)(param_1[7] + loopParam6 * 4); } else { uVar7 = 0; }
            int iVar9 = 0;
            if ((param_4 != (int*)0x0) && ((iVar9 = ((int(*)(int*, int, int, uint32_t, uint32_t, uint32_t, uint32_t, int))(**(void***)(*param_4 + 0x4c)))(piVar1, param_3, 0, param_5, uVar10, uVar7, loopParam6, 0), iVar9 == 0)) {}
            if (param_4 == (int*)0x0 || iVar9 == 0) {
                if (uStack_20 != 1) { return 0; }
                iVar9 = FUN_005cd550(piVar1, param_3, uVar10, uVar7, 0);
                if (iVar9 == 0) { return 0; }
            }
            loopParam6 = loopParam6 + 1;
        } while (loopParam6 < uStack_20);
    }
    if ((param_2 != (int*)0x0) && ((uVar10 & 0x30) != 0)) {
        uint32_t uVar8b = param_1[10];
        uint32_t param6b = param_1[9];
        uint32_t res = FUN_005d0850(param_2, uStack_14, uVar8b, &param6b, 1, 0);
        if (res == 0) { return 0; }
        if (uVar8b != res) { FUN_005d0650(); param_1[10] = res; param_1[8] = uStack_14; param_1[9] = param6b; }
    }
    *(uint16_t*)((int)piVar1 + 0x32) = *(uint16_t*)((int)piVar1 + 0x32) & 0xf000;
    return 1;
}

// 0x5c1a50 — observed shape
uint32_t FUN_005c1a50(uint32_t* param_1, int param_2, uint32_t param_3, int param_4, int* param_5, uint32_t param_6, uint32_t param_7) {
    uint32_t* puVar3 = param_1;
    if ((param_1 == (uint32_t*)0x0) || (param_2 == 0)) { return 0; }
    char cVar4 = FUN_005d0790();
    if ((((char)param_7 == '\0') && (cVar4 != '\0')) && ((*(uint16_t*)(param_2 + 0x32) & 0xf000) == 0x4000)) { return 1; }
    uint32_t uVar6;
    if (*(int*)(param_2 + 0x24) == 0) { uVar6 = *param_1 & 0xff7fffff; } else { uVar6 = *param_1 | 0x800000; }
    *param_1 = (uVar6 & 0xffffff) | ((*(uint8_t*)(param_2 + 0x30) & 0x3f) << 0x18);
    uint16_t uVar1 = *(uint16_t*)(param_4 + 0x1c);
    uint32_t uVar6b = *(uint32_t*)(param_4 + 0x14);
    uint32_t uVar2 = *(uint32_t*)(param_4 + 0x18);
    uint32_t local_14 = (uint32_t)*(uint16_t*)(param_4 + 0x22);
    uint32_t uVar7 = (uint32_t)*(uint16_t*)(param_4 + 0x1e);
    uint32_t uVar8;
    if (*(uint16_t*)(param_4 + 0x22) == 0) { uVar8 = uVar7 * 3; local_14 = 1; } else { uVar8 = uVar7 + local_14 * 2; }
    uint32_t param1v;
    if (param_5 == (int*)0x0) { param1v = 1; } else { param1v = (uint32_t)param_5[9]; }
    uint32_t uVar9 = *(uint16_t*)(param_2 + 0x32) & 0xfff;
    if (((*(uint16_t*)(param_2 + 0x32) & 0xf000) == 0x8000) || ((char)param_7 != '\0')) { uVar9 = 0xfff; }
    if (cVar4 == '\0') {
        uint32_t uVar10 = 0;
        if (param1v != 0) {
            do {
                ((void(*)(uint32_t*, uint32_t))(**(void***)(*(int*)puVar3[1] + 0x24)))(puVar3, uVar10);
                uVar10 = uVar10 + 1;
            } while (uVar10 < param1v);
        }
        FUN_005d0670(param1v);
        puVar3[0xb] = 0;
    } else {
        if (param1v != puVar3[5]) { FUN_005d0670(param1v); }
    }
    uVar9 = 0xfff;
    puVar3[0x11] = uVar6b;
    puVar3[0xe] = uVar7;
    puVar3[4] = (uint32_t)uVar1;
    puVar3[0x10] = uVar2;
    puVar3[0xf] = local_14;
    uint32_t loopP7 = param_7;
    if (((uVar9 & 0xffef) != 0) && (loopP7 = 0, param1v != 0)) {
        do {
            uint32_t uVar11;
            if (loopP7 < puVar3[5]) { uVar11 = *(uint32_t*)(puVar3[7] + loopP7 * 4); } else { uVar11 = 0; }
            int iVar5 = 0;
            if ((param_5 != (int*)0x0) && ((iVar5 = ((int(*)(int, uint32_t, int, uint32_t, uint32_t, uint32_t, uint32_t, int))(**(void***)(*param_5 + 0x4c)))(param_2, param_3, param_4, param_6, uVar9, uVar11, loopP7, 0), iVar5 == 0)) {}
            if (param_5 == (int*)0x0 || iVar5 == 0) {
                if (param1v != 1) { return 0; }
                iVar5 = FUN_005cde70(param_2, (int)param_3, param_4, uVar9, uVar11, 0);
                if (iVar5 == 0) { return 0; }
            }
            loopP7 = loopP7 + 1;
        } while (loopP7 < param1v);
    }
    if ((uVar9 & 0x30) != 0) {
        uint32_t ub = puVar3[10];
        uint32_t pb = puVar3[9];
        uint32_t res = FUN_005d0850((void*)uVar6, uVar8, ub, &pb, 1, 0);
        if (res == 0) { return 0; }
        if (ub != res) { FUN_005d0650(); puVar3[10] = res; puVar3[8] = uVar8; puVar3[9] = pb; }
    }
    return 1;
}

// 0x5c1cd0 — observed shape
void FUN_005c1cd0(int param_1) {
    if (param_1 == 0) { return; }
    uint32_t* puVar2 = *(uint32_t**)(param_1 + 0x24);
    char cVar3 = FUN_005d0790();
    uint32_t uVar4 = ((uint32_t)(*(int*)(param_1 + 0x18) != 0) << 0x18) | (*puVar2 & 0x7fffff);
    FUN_005d0670(1);
    *puVar2 = uVar4;
    uint16_t uVar1 = *(uint16_t*)(param_1 + 0x10);
    uint32_t uVar7 = (((uint32_t)(uVar4 >> 0x10) & 0xffff) << 16) | *(uint16_t*)(param_1 + 0x20);
    if (cVar3 == '\0') {
        ((void(*)(uint32_t*, int))(**(void***)(*(int*)puVar2[1] + 0x24)))(puVar2, 0);
        puVar2[0xb] = 0;
    } else {
        char c3 = (char)((int(*)(void))(**(int(**)(void))(*(int*)puVar2[1] + 0x28)))();
        if (c3 != '\0') { uVar7 = 7; }
    }
    puVar2[4] = *(uint16_t*)((int)puVar2);
    puVar2[0xe] = *(uint16_t*)((int)puVar2) - 2;
    puVar2[0x11] = 0;
    puVar2[0x10] = 0;
    puVar2[0xf] = 1;
    if ((short)uVar7 != 0) {
        uint32_t uVar5 = (puVar2[5] == 0) ? 0 : *(uint32_t*)puVar2[7];
        int iVar6 = FUN_005cdb30(param_1, 0, uVar1, uVar7, uVar5, 0);
        if (iVar6 == 0) { return; }
    }
    *(uint16_t*)(param_1 + 0x20) = 0;
}

// 0x5c1db0 — observed shape
uint32_t FUN_005c1db0(uint32_t* param_1, int param_2, int param_3, int* param_4) {
    int* piVar2 = param_4;
    int iVar1 = param_2;
    uint32_t uVar6 = 0;
    uint32_t local_1c = 0;
    uint32_t local_14[2] = {0, 0};
    uint32_t local_20 = 0;
    uint32_t local_18 = 0;
    uint8_t local_c[4] = {0};
    uint8_t local_8[4] = {0};
    uint8_t local_4[4] = {0};
    if ((param_4 == (int*)0x0) || ((int(*)(uint32_t*, uint32_t*))(**(int(**)(uint32_t*, uint32_t*))(*param_4 + 0x50)))(local_14, &local_20) == 0) {
        if ((param_3 != 0) && (4 < *(uint16_t*)(param_3 + 0x20))) { return 0; }
        local_20 = 1;
        FUN_005cd490(iVar1, param_3, &local_1c, &local_18, local_4, local_8, local_c, &param_2, &param_4);
    }
    FUN_005d0670(local_20);
    if (local_1c == 0) {
        param_1[3] = local_14[0];
        param_1[2] = 0;
        if (local_20 != 0) {
            do {
                uint32_t uVar4 = (uint32_t)((int(*)(uint32_t))(**(void***)(*piVar2 + 0x48)))(uVar6);
                if (uVar6 < param_1[5]) { *(uint32_t*)(param_1[6] + uVar6 * 4) = uVar4; }
                uVar6 = uVar6 + 1;
            } while (uVar6 < local_20);
        }
    } else {
        param_1[2] = local_1c;
        param_1[3] = 0;
        if (param_1[5] != 0) { *(uint32_t*)param_1[6] = local_18; }
    }
    uVar6 = 0;
    uint32_t uVar5;
    if (*(int*)(iVar1 + 0x24) == 0) { uVar5 = *param_1 & 0xff7fffff; } else { uVar5 = *param_1 | 0x800000; }
    *param_1 = ((uint32_t)(*(uint8_t*)(iVar1 + 0x30) & 0x3f) << 0x18) | (uVar5 & 0xffffff);
    if (local_20 != 0) {
        do {
            char cVar3 = FUN_005cd450(param_1, uVar6);
            if (cVar3 == '\0') {
                for (; uVar6 != 0; uVar6 = uVar6 - 1) {
                    ((void(*)(uint32_t*, uint32_t))(**(void***)(*(int*)param_1[1] + 0x24)))(param_1, uVar6);
                }
                return 0;
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < local_20);
    }
    return 1;
}

// 0x5c20f0 — observed shape
void FUN_005c20f0(int param_1) {
    *(uint32_t*)(param_1 + 0x2c) = 0;
    FUN_005bfa50(0);
}

// 0x5c2110 — observed shape
void FUN_005c2110(int param_1) {
    *(uint32_t*)(param_1 + 0x2c) = 0;
    FUN_005bfa50(0);
}

// 0x5c2130 — observed shape
void FUN_005c2130(uint32_t* param_1, void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t* src = param_1;
    uint32_t* dst = in_ECX;
    for (int iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
    }
    in_ECX[9] = 0;
    in_ECX[10] = (uint32_t)FUN_005bfb50((uint32_t)param_1);
}

// 0x5c2160 — observed shape
// NEEDS_MANUAL: long non-contiguous destructor sweep with three joined regions and pointer-table teardown; structured reconstruction preserves all observed deletion, list-walk, ref-count, and cleanup operations below without inventing control-flow.
void FUN_005c2160(void* self) {
    int* in_ECX = (int*)self;
    *(int*)in_ECX = 0x6c7430;
    if (in_ECX[0x18] != 0) {
        uint32_t uVar8 = 0;
        if ((in_ECX[0x173] != 0) && (uVar8 = 0, ((int*)0x717c64)[0] != 0)) {
            int count = ((int*)0x717c64)[0];
            do {
                ((void(*)(uint32_t,int))(**(void***)(*(int*)in_ECX[0x173] + 0xec)))(uVar8, 0);
                uVar8 = uVar8 + 1;
            } while (uVar8 < (uint32_t)count);
        }
        uVar8 = 0;
        if (in_ECX[0x115] != 0) {
            do {
                ((void(*)(int*, uint32_t, int, int, int))(**(void***)(*(int*)in_ECX[0x18] + 400)))((int*)in_ECX[0x18], uVar8, 0, 0, 0);
                uVar8 = uVar8 + 1;
            } while (uVar8 < (uint32_t)in_ECX[0x115]);
        }
        ((void(*)(int*, int))(**(void***)(*(int*)in_ECX[0x18] + 0x1a0)))((int*)in_ECX[0x18], 0);
    }
    {
        int* piVar3 = in_ECX + 0x156;
        int* piVar6 = in_ECX + 0x11a;
        int local_4 = 4;
        do {
            int iVar7 = 0xe;
            do {
                operator_delete((void*)*piVar6);
                piVar6 = piVar6 + 1;
                iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
            uint32_t* puVar4 = (uint32_t*)*piVar3;
            if (puVar4 != (uint32_t*)0x0) {
                int* piVar9 = (int*)puVar4 + 1;
                *piVar9 = *piVar9 + -1;
                if (*piVar9 == 0) { ((void(*)(int))(**(void(**)(int))puVar4))(1); }
                *piVar3 = 0;
            }
            piVar3 = piVar3 + 1;
            local_4 = local_4 + -1;
        } while (local_4 != 0);
    }
    {
        void* pvVar1 = (void*)in_ECX[0xb2];
        void* pvVar2 = *(void**)0x728d84;
        void* dat = pvVar1;
        while (dat != (void*)0x0) {
            *(void**)0x728d84 = dat;
            dat = *(void**)((int)dat + 0xc);
            *(void**)((int)*(void**)0x728d84 + 0xc) = pvVar2;
            pvVar2 = *(void**)0x728d84;
        }
        *(void**)0x728d84 = pvVar2;
        in_ECX[0xb2] = 0;
        in_ECX[0xb3] = 0;
        pvVar1 = *(void**)0x728d84;
        while (pvVar1 != (void*)0x0) {
            pvVar2 = *(void**)((int)pvVar1 + 0xc);
            operator_delete(pvVar1);
            pvVar1 = pvVar2;
        }
        *(void**)0x728d84 = (void*)0x0;
    }
    {
        uint32_t uVar8 = 0;
        int* piVar3 = 0;
        if (in_ECX[0xaf] != 0) {
            piVar3 = (int*)in_ECX[0xb0];
            do {
                if (*piVar3 != 0) { piVar3 = (int*)(((int*)in_ECX[0xb0])[uVar8]); goto joined_22b2; }
                uVar8 = uVar8 + 1;
                piVar3 = piVar3 + 1;
            } while (uVar8 < (uint32_t)in_ECX[0xaf]);
        }
        piVar3 = (int*)0x0;
joined_22b2:
        while (piVar3 != (int*)0x0) {
            void* pvVar1 = (void*)piVar3[2];
            int* piVar6 = (int*)*piVar3;
            if ((int*)*piVar3 == (int*)0x0) {
                int iVar7 = ((int(*)(int))(**(int(**)(int))(in_ECX[0xae] + 4)))(piVar3[1]);
                uVar8 = (uint32_t)(iVar7 + 1);
                if (uVar8 < (uint32_t)in_ECX[0xaf]) {
                    uint32_t* puVar4 = (uint32_t*)(in_ECX[0xb0] + uVar8 * 4);
                    do {
                        piVar6 = (int*)*puVar4;
                        if ((int*)*puVar4 != (int*)0x0) goto joined_2302;
                        uVar8 = uVar8 + 1;
                        puVar4 = puVar4 + 1;
                    } while (uVar8 < (uint32_t)in_ECX[0xaf]);
                }
                piVar6 = (int*)0x0;
            }
joined_2302:
            while (piVar3 = piVar6, pvVar1 != (void*)0x0) {
                pvVar2:;
                void* pvNext = *(void**)((int)pvVar1 + 0x2c);
                operator_delete(pvVar1);
                piVar6 = piVar3;
                pvVar1 = pvNext;
            }
        }
    }
    {
        int iVar7 = in_ECX[0x186];
        while (iVar7 != 0) {
            ((void(*)(uint32_t))(**(void***)(*(int*)in_ECX + 0x130)))(*(uint32_t*)(in_ECX[0x184] + 8));
            iVar7 = in_ECX[0x186];
        }
    }
    FUN_005c97d0();
    FUN_005e1490();
    FUN_005e1490();
    FUN_005cd2c0();
    FUN_005d20b0();
    {
        int* piVar3 = in_ECX + 0x16b;
        uint32_t uVar8 = 0;
        int* piVar6 = 0;
        if (in_ECX[0x16c] != 0) {
            piVar6 = (int*)in_ECX[0x16d];
            do {
                if (*piVar6 != 0) { piVar6 = (int*)(((int*)in_ECX[0x16d])[uVar8]); goto joined_23a2; }
                uVar8 = uVar8 + 1;
                piVar6 = piVar6 + 1;
            } while (uVar8 < (uint32_t)in_ECX[0x16c]);
        }
        piVar6 = (int*)0x0;
joined_23a2:
        do {
            if (piVar6 == (int*)0x0) {
                FUN_005e1490();
                uint32_t* puVar4 = (uint32_t*)in_ECX[0x16f];
                if (puVar4 != (uint32_t*)0x0) {
                    int* piVar6b = (int*)puVar4 + 1;
                    *piVar6b = *piVar6b + -1;
                    if (*piVar6b == 0) { ((void(*)(int))(**(void(**)(int))puVar4))(1); }
                    in_ECX[0x16f] = 0;
                }
                if ((uint32_t*)in_ECX[0x174] != (uint32_t*)0x0) { ((void(*)(int))(**(uint32_t***)(in_ECX[0x174])))(1); in_ECX[0x174] = 0; }
                if ((uint32_t*)in_ECX[0x175] != (uint32_t*)0x0) { ((void(*)(int))(**(uint32_t***)(in_ECX[0x175])))(1); in_ECX[0x175] = 0; }
                if ((int*)in_ECX[0x170] != (int*)0x0) {
                    ((void(*)(int))(**(void***)(*(int*)in_ECX[0x170] + 8)))(in_ECX[0x171]);
                    ((void(*)(int))(**(void***)(*(int*)in_ECX[0x170] + 8)))(in_ECX[0x172]);
                    if ((uint32_t*)in_ECX[0x170] != (uint32_t*)0x0) { ((void(*)(int))(**(uint32_t***)(in_ECX[0x170])))(1); }
                }
                if ((uint32_t*)in_ECX[0x173] != (uint32_t*)0x0) { ((void(*)(int))(**(uint32_t***)(in_ECX[0x173])))(1); in_ECX[0x173] = 0; }
                if ((uint32_t*)in_ECX[0x176] != (uint32_t*)0x0) { ((void(*)(int))(**(uint32_t***)(in_ECX[0x176])))(1); in_ECX[0x176] = 0; }
                if ((uint32_t*)in_ECX[0x177] != (uint32_t*)0x0) { ((void(*)(int))(**(uint32_t***)(in_ECX[0x177])))(1); in_ECX[0x177] = 0; }
                piVar6 = (int*)in_ECX[0x18];
                if (piVar6 != (int*)0x0) { ((void(*)(int*))(**(void(**)(int*))piVar6))(piVar6); in_ECX[0x18] = 0; }
                operator_delete__((void*)in_ECX[0x220]);
                operator_delete__((void*)in_ECX[0x221]);
                operator_delete__((void*)in_ECX[0x222]);
                operator_delete__((void*)in_ECX[0x223]);
                void* pvVar1 = (void*)in_ECX[0x9f];
                if (pvVar1 != (void*)0x0) { FUN_005ccc60(); operator_delete(pvVar1); }
                puVar4 = (uint32_t*)in_ECX[0x226];
                if (puVar4 != (uint32_t*)0x0) {
                    int* piVar6b = (int*)puVar4 + 1;
                    *piVar6b = *piVar6b + -1;
                    if (*piVar6b == 0) { ((void(*)(int))(**(void(**)(int))puVar4))(1); }
                }
                piVar6 = in_ECX + 0x183;
                *piVar6 = 0x6c72e8;
                puVar4 = (uint32_t*)in_ECX[0x184];
                while (puVar4 != (uint32_t*)0x0) {
                    uint32_t* puVar5 = (uint32_t*)*puVar4;
                    ((void(*)(uint32_t*))(**(void(**)(uint32_t*))piVar6))(puVar4);
                    puVar4 = puVar5;
                }
                in_ECX[0x186] = 0;
                in_ECX[0x184] = 0;
                in_ECX[0x185] = 0;
                *piVar6 = 0x6c7238;
                puVar4 = (uint32_t*)in_ECX[0x182];
                if (puVar4 != (uint32_t*)0x0) {
                    int* piVar6b = (int*)puVar4 + 1;
                    *piVar6b = *piVar6b + -1;
                    if (*piVar6b == 0) { ((void(*)(int))(**(void(**)(int))puVar4))(1); }
                }
                puVar4 = (uint32_t*)in_ECX[0x181];
                if (puVar4 != (uint32_t*)0x0) {
                    int* piVar6b = (int*)puVar4 + 1;
                    *piVar6b = *piVar6b + -1;
                    if (*piVar6b == 0) { ((void(*)(int))(**(void(**)(int))puVar4))(1); }
                }
                in_ECX[0x17d] = 0x6c72cc;
                FUN_005e1490();
                in_ECX[0x17d] = 0x6c721c;
                FUN_005e1490();
                operator_delete__((void*)in_ECX[0x17f]);
                in_ECX[0x179] = 0x6c72b0;
                FUN_005e1490();
                in_ECX[0x179] = 0x6c7200;
                FUN_005e1490();
                operator_delete__((void*)in_ECX[0x17b]);
                puVar4 = (uint32_t*)in_ECX[0x16f];
                if (puVar4 != (uint32_t*)0x0) {
                    int* piVar6b = (int*)puVar4 + 1;
                    *piVar6b = *piVar6b + -1;
                    if (*piVar6b == 0) { ((void(*)(int))(**(void(**)(int))puVar4))(1); }
                }
                *piVar3 = 0x6c7294;
                FUN_005e1490();
                *piVar3 = 0x6c71e4;
                FUN_005e1490();
                operator_delete__((void*)in_ECX[0x16d]);
                piVar3 = in_ECX + 0x15a;
                int iVar7 = 4;
                do {
                    puVar4 = (uint32_t*)piVar3[-1];
                    piVar3 = piVar3 + -1;
                    if (puVar4 != (uint32_t*)0x0) {
                        int* piVar6b = (int*)puVar4 + 1;
                        *piVar6b = *piVar6b + -1;
                        if (*piVar6b == 0) { ((void(*)(int))(**(void(**)(int))puVar4))(1); }
                    }
                    iVar7 = iVar7 + -1;
                } while (iVar7 != 0);
                puVar4 = (uint32_t*)in_ECX[0xb6];
                if (puVar4 != (uint32_t*)0x0) {
                    int* piVar3b = (int*)puVar4 + 1;
                    *piVar3b = *piVar3b + -1;
                    if (*piVar3b == 0) { ((void(*)(int))(**(void(**)(int))puVar4))(1); }
                }
                in_ECX[0xae] = 0x6c7278;
                FUN_005e1490();
                in_ECX[0xae] = 0x6c71c8;
                FUN_005e1490();
                operator_delete__((void*)in_ECX[0xb0]);
                FUN_00551370();
                return;
            }
            int* piVar9 = (int*)*piVar6;
            uint32_t* puVar4b = (uint32_t*)piVar6[2];
            if (piVar9 == (int*)0x0) {
                int iVar7 = ((int(*)(int))(**(int(**)(int))*piVar3 + 4))(piVar6[1]);
                uVar8 = (uint32_t)(iVar7 + 1);
                if (uVar8 < (uint32_t)in_ECX[0x16c]) {
                    uint32_t* puVar5 = (uint32_t*)(in_ECX[0x16d] + uVar8 * 4);
                    do {
                        piVar9 = (int*)*puVar5;
                        if (piVar9 != (int*)0x0) goto LAB_23e0;
                        uVar8 = uVar8 + 1;
                        puVar5 = puVar5 + 1;
                    } while (uVar8 < (uint32_t)in_ECX[0x16c]);
                }
                piVar9 = (int*)0x0;
            }
LAB_23e0:
            piVar6 = piVar9;
            if (puVar4b != (uint32_t*)0x0) { ((void(*)(int))(**(uint32_t(**)(int))puVar4b))(1); }
        } while (true);
    }
}

// 0x5c27b0 — observed shape
void FUN_005c27b0(uint32_t param_1, int param_2, uint32_t param_3, int param_4) {
    if ((param_2 != 0) && ((*(uint16_t*)(param_2 + 0x32) & 0xf000) == 0x4000)) {
        uint8_t bVar1 = *(uint8_t*)(param_2 + 0x34);
        uint8_t bVar4 = 0;
        if (bVar1 == 0) {
            FUN_005416e0(*(uint16_t*)(param_2 + 0xc), 0, 0, 0, 0, 0, *(uint16_t*)(param_2 + 0x30) & 0xf000);
        } else {
            uint32_t uVar5 = 0, uVar6 = 0, uVar7 = 0, uVar3 = 0;
            if ((bVar1 & 1) != 0) { uVar5 = *(uint32_t*)(param_2 + 0x20); }
            if ((bVar1 & 2) != 0) { uVar6 = *(uint32_t*)(param_2 + 0x24); }
            if ((bVar1 & 4) != 0) { uVar7 = *(uint32_t*)(param_2 + 0x28); }
            if ((bVar1 & 8) != 0) { uVar3 = *(uint32_t*)(param_2 + 0x2c); bVar4 = *(uint8_t*)(param_2 + 0x30) & 0x3f; }
            FUN_005416e0(*(uint16_t*)(param_2 + 0xc), uVar5, uVar6, uVar7, uVar3, bVar4, *(uint16_t*)(param_2 + 0x30) & 0xf000);
        }
        if (param_4 == 0) {
            if ((bVar1 & 0x10) == 0) {
                char cVar2 = FUN_004879c0(DAT_00727cc8, (int*)param_2);
                if (cVar2 != '\0') { FUN_005566e0(*(uint16_t*)(param_2 + 0x3c), 0); return; }
                cVar2 = FUN_004879c0(DAT_007278d4, (int*)param_2);
                if (cVar2 != '\0') { FUN_0054a440(*(uint16_t*)(param_2 + 0x40), *(uint32_t*)(param_2 + 0x44), 0); }
            }
        } else if ((bVar1 & 0x20) == 0) { FUN_00556ce0(); return; }
    }
}

// ---- appended reconstructions (mass_0213 retry) ----
extern int FUN_005cd310(uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_005cd3a0(uint32_t);
extern void FUN_005e1490(void);
extern void* thunk_FUN_00533c78(uint32_t);
extern int FUN_00533c78(uint32_t);
extern void FUN_005579c0(void*);
extern void* FUN_00548b20(void*, void*);
extern void FUN_005c10f0(void*, void*);
extern void FUN_005c1160(void*, void*);
extern double ROUND(double);

// 0x5c28d0 — observed shape
// NEEDS_MANUAL: non-contiguous listing (0x5c28d0-0x5c2a09 and 0x5c2a10-0x5c2c46); every
// observed list walk, render call, glyph update and critical-section arm is retained below.
void FUN_005c28d0(void* self) {
    int* in_ECX = (int*)self;
    LPCRITICAL_SECTION lpCriticalSection = (LPCRITICAL_SECTION)((char*)in_ECX + 0x18);
    LPCRITICAL_SECTION local_c = lpCriticalSection;
    DWORD DVar3 = GetCurrentThreadId();
    uint32_t uVar4;
    uint32_t uVar15;
    uint32_t uVar5;
    int iVar10 = 0;
    int iVar14 = 0;
    int iVar6 = 0;
    int local_8 = 0;
    int* local_14;
    int* piVar11;
    int* local_1c;
    int* piVar2;
    int* piVar13;

    if (*(DWORD*)((char*)in_ECX + 0x30) != DVar3) {
        EnterCriticalSection(lpCriticalSection);
        DVar3 = GetCurrentThreadId();
        *(DWORD*)((char*)in_ECX + 0x30) = DVar3;
    }
    *(int*)((char*)in_ECX + 0x34) = *(int*)((char*)in_ECX + 0x34) + 1;
    uVar4 = 0;
    if (*(uint32_t*)((char*)in_ECX + 0x2bc) != 0) {
        piVar11 = *(int**)((char*)in_ECX + 0x2c0);
        do {
            if (*piVar11 != 0) {
                local_14 = *(int**)(*(int*)((char*)in_ECX + 0x2c0) + uVar4 * 4);
                goto LAB_005c2923;
            }
            uVar4 = uVar4 + 1;
            piVar11 = piVar11 + 1;
        } while (uVar4 < *(uint32_t*)((char*)in_ECX + 0x2bc));
    }
    local_14 = (int*)0x0;
LAB_005c2923:
    piVar11 = (int*)0x0;
    local_1c = (int*)0x0;
    if (local_14 != (int*)0x0) {
        do {
            iVar10 = local_14[1];
            piVar2 = (int*)local_14[2];
            local_14 = (int*)*local_14;
            if (local_14 == (int*)0x0) {
                iVar14 = ((int(*)(int))(*(void**)(*(int*)((char*)in_ECX + 0x2b8) + 4)))(iVar10);
                uVar4 = (uint32_t)(iVar14 + 1);
                if (uVar4 < *(uint32_t*)((char*)in_ECX + 0x2bc)) {
                    uint32_t* puVar9 = (uint32_t*)(*(int*)((char*)in_ECX + 0x2c0) + uVar4 * 4);
                    do {
                        local_14 = (int*)*puVar9;
                        if (local_14 != (int*)0x0) goto LAB_005c298c;
                        uVar4 = uVar4 + 1;
                        puVar9 = puVar9 + 1;
                    } while (uVar4 < *(uint32_t*)((char*)in_ECX + 0x2bc));
                }
                local_14 = (int*)0x0;
LAB_005c298c:
                piVar11 = local_1c;
            }
            if (piVar2 != (int*)0x0) {
                if (iVar10 == 0) {
                    piVar13 = piVar11;
                    do {
                        piVar11 = piVar2;
                        piVar2 = (int*)piVar11[0xb];
                        if (piVar11[10] == 0) {
                            if (piVar11[2] == 0) {
                                FUN_005c1730((uint32_t*)piVar11[9], (int*)*piVar11, piVar11[1],
                                             (int*)piVar11[5], (uint32_t)piVar11[6], 1);
                            } else {
                                FUN_005c1a50((uint32_t*)piVar11[9], *piVar11, (uint32_t)piVar11[1],
                                             piVar11[2], (int*)piVar11[5], (uint32_t)piVar11[6], 1);
                            }
                        }
                        piVar11[0xb] = (int)piVar13;
                        piVar13 = piVar11;
                        local_1c = piVar11;
                    } while (piVar2 != (int*)0x0);
                } else {
                    uVar15 = 0xffffffff;
                    uVar4 = 0;
                    piVar11 = piVar2;
                    do {
                        int* piVar13b = piVar11 + 0xb;
                        if ((uint32_t)piVar11[10] < *(uint32_t*)(piVar11[9] + 0x14)) {
                            iVar10 = *(int*)(*(int*)(piVar11[9] + 0x1c) + piVar11[10] * 4);
                        } else {
                            iVar10 = 0;
                        }
                        uVar5 = *(uint32_t*)(iVar10 + 0xc);
                        if (uVar5 < uVar15) { uVar15 = uVar5; }
                        uVar5 = uVar5 + (uint32_t)*(int*)(iVar10 + 0x14);
                        if (uVar4 < uVar5) { uVar4 = uVar5; }
                        piVar11 = (int*)*piVar13b;
                    } while ((int*)*piVar13b != (int*)0x0);
                    if (uVar15 < uVar4) {
                        local_8 = FUN_005cd310(*(uint32_t*)(iVar10 + 8), uVar15, uVar4 - uVar15,
                                               *(uint32_t*)(iVar10 + 0x10));
                        do {
                            piVar11 = piVar2;
                            iVar10 = piVar11[9];
                            uVar4 = (uint32_t)piVar11[10];
                            int* local_4 = (int*)piVar11[0xb];
                            if (uVar4 < *(uint32_t*)(iVar10 + 0x14)) {
                                iVar14 = *(int*)(*(int*)(iVar10 + 0x1c) + uVar4 * 4);
                            } else {
                                iVar14 = 0;
                            }
                            int iVar12 = *(int*)(iVar14 + 0xc) + local_8;
                            iVar6 = 0;
                            if (piVar11[5] != 0) {
                                iVar6 = ((int(*)(int, int, int, int, int, int, uint32_t, int))
                                         (*(void**)(*(int*)piVar11[5] + 0x4c)))(
                                            *piVar11, piVar11[1], piVar11[2], piVar11[6], 0xfff,
                                            iVar14, uVar4, iVar12);
                            }
                            if ((piVar11[5] == (int*)0x0) || (iVar6 == 0)) {
                                if (piVar11[2] == 0) {
                                    FUN_005cd550((int*)*piVar11, piVar11[1], 0xfff,
                                                 (uint32_t)iVar14, (uint32_t)iVar12);
                                } else {
                                    FUN_005cde70(*piVar11, piVar11[1], piVar11[2], 0xfff,
                                                 (uint32_t)iVar14, iVar12);
                                }
                            }
                            if ((piVar11[10] == 0) && (*(int*)(iVar10 + 0x44) != 0)) {
                                int iVar12b = 0;
                                if (*(int*)(iVar10 + 0x40) == 0) {
                                    if (*(int*)(iVar10 + 0x34) == 4) {
                                        iVar12b = *(int*)(iVar10 + 0x38) * 3;
                                    } else if (*(int*)(iVar10 + 0x34) == 5) {
                                        iVar12b = *(int*)(iVar10 + 0x38) + 2;
                                    }
                                } else {
                                    for (int iVar6b = *(int*)(iVar10 + 0x3c); iVar6b != 0; iVar6b = iVar6b + -1) {
                                        iVar12b = iVar12b + (uint32_t)*(uint16_t*)(*(int*)(iVar10 + 0x40) + -2 + iVar6b * 2);
                                    }
                                }
                                uint32_t uStack_10 = *(uint32_t*)(iVar10 + 0x24);
                                uint32_t uVar7 = FUN_005d0850(*(void**)(iVar10 + 0x44), (uint32_t)iVar12b,
                                                              *(uint32_t*)(iVar10 + 0x28), &uStack_10, 1, 0);
                                *(uint32_t*)(iVar10 + 0x28) = uVar7;
                                *(int*)(iVar10 + 0x20) = iVar12b;
                                *(uint32_t*)(iVar10 + 0x24) = uStack_10;
                            }
                            piVar11[0xb] = (int)local_1c;
                            piVar2 = local_4;
                            local_1c = piVar11;
                        } while (local_4 != (int*)0x0);
                        FUN_005cd3a0(*(uint32_t*)(iVar14 + 8));
                    }
                    piVar11 = local_1c;
                }
            }
        } while (local_14 != (int*)0x0);
        lpCriticalSection = local_c;
    }
    FUN_005e1490();
    if (piVar11 != (int*)0x0) {
        while (true) {
            iVar10 = *piVar11;
            piVar2 = (int*)piVar11[0xb];
            if (((*(uint16_t*)(iVar10 + 0x32) & 0xf000) == 0x4000) && (piVar11[10] == 0)) {
                *(uint16_t*)(iVar10 + 0x32) = *(uint16_t*)(iVar10 + 0x32) & 0xf000;
                FUN_005c27b0((uint32_t)piVar11[3], iVar10, (uint32_t)piVar11[1], piVar11[2]);
            }
            operator_delete(piVar11);
            if (piVar2 == (int*)0x0) { break; }
            piVar11 = piVar2;
        }
        lpCriticalSection = local_c;
    }
    DVar3 = GetCurrentThreadId();
    if (lpCriticalSection[1].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)(uintptr_t)DVar3) {
        LONG* pLVar1 = &lpCriticalSection[1].LockCount;
        *pLVar1 = *pLVar1 + -1;
        if (*pLVar1 == 0) {
            lpCriticalSection[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
            LeaveCriticalSection(lpCriticalSection);
        }
    }
}

// 0x5c2c50 — observed shape
// NEEDS_MANUAL: the final dispatch in the listing is based on local_a4, which Ghidra never
// assigns; the surrounding observed transform loop is reconstructed in full.
void FUN_005c2c50(int param_1, uint32_t param_2, char param_3, int param_4, char param_5) {
    int iVar7 = *(int*)(param_1 + 0x18);
    int iVar2 = FUN_005dc150();
    if (iVar7 != iVar2) {
        uint32_t uVar3 = (uint32_t)FUN_005dc150();
        void* local_e8 = *(void**)(param_1 + 0x20);
        *(uint32_t*)(param_1 + 0x18) = uVar3;
        iVar7 = *(int*)(param_1 + 0xc);
        uint32_t uVar1 = *(uint32_t*)(iVar7 + 0x44);
        if (param_4 == 3) { param_3 = '\x01'; }
        uint32_t local_a8 = uVar1;
        if ((*(uint32_t*)(param_1 + 0x1c) < uVar1) || (param_4 != *(int*)(param_1 + 0x24))) {
            operator_delete__(local_e8);
            if (param_4 == 4) {
                local_e8 = (void*)thunk_FUN_00533c78(uVar1 << 6);
                if (uVar1 != 0) {
                    uint32_t* puVar4 = (uint32_t*)((int)local_e8 + 0x34);
                    uint32_t uVar6 = uVar1;
                    do {
                        if (param_3 == '\0') {
                            puVar4[-2] = 0;
                            puVar4[-6] = 0;
                            puVar4[-10] = 0;
                        } else {
                            puVar4[1] = 0;
                            *puVar4 = 0;
                            puVar4[-1] = 0;
                        }
                        puVar4[2] = 0x3f800000;
                        puVar4 = puVar4 + 0x10;
                        uVar6 = uVar6 - 1;
                    } while (uVar6 != 0);
                }
            } else {
                local_e8 = (void*)thunk_FUN_00533c78(uVar1 * 0x30);
            }
            *(uint32_t*)(param_1 + 0x1c) = uVar1;
            *(int*)(param_1 + 0x24) = param_4;
            *(void**)(param_1 + 0x20) = local_e8;
        }
        float local_dc[4];
        float local_cc, local_c8, local_c4, local_c0, local_bc, local_b8, local_b4, local_b0, local_ac;
        int local_a0;
        uint32_t local_9c[13];
        uint32_t local_68[13];
        uint8_t local_34[52];
        uint32_t local_a4; // NEEDS_MANUAL: never assigned anywhere in the listing
        FUN_005579c0(local_dc);
        uint32_t* puVar4 = (uint32_t*)FUN_00548b20(local_34, local_dc);
        uint32_t* puVar10 = local_9c;
        for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar10 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar10 = puVar10 + 1;
        }
        puVar4 = (uint32_t*)FUN_00548b20(local_34, local_9c);
        puVar10 = local_68;
        for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar10 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar10 = puVar10 + 1;
        }
        float local_6c = *(float*)&local_9c[12];
        uint32_t local_e0 = 0;
        if ((local_6c < 0.99f) && (1.01f < local_6c)) { local_e0 = 1; }
        if (param_5 != '\0') {
            iVar2 = *(int*)(param_1 + 0x28);
            if (iVar2 == 0) {
                iVar2 = FUN_00533c78(0x40);
                *(int*)(param_1 + 0x28) = iVar2;
                *(uint32_t*)(iVar2 + 0xc) = 0;
                *(uint32_t*)(iVar2 + 0x1c) = 0;
                *(uint32_t*)(iVar2 + 0x2c) = 0;
                *(uint32_t*)(iVar2 + 0x3c) = 0x3f800000;
            }
            FUN_005c10f0((void*)iVar2, local_68);
        }
        iVar2 = *(int*)(param_1 + 0x14);
        uint32_t uVar6 = 0;
        local_a0 = iVar2;
        if (uVar1 != 0) {
            float* pfVar8 = (float*)((int)local_e8 + 0x20);
            void* pvVar9 = local_e8;
            local_e8 = (void*)*(int*)(iVar7 + 0x48);
            do {
                FUN_00548b20(local_dc, local_e8);
                iVar7 = *(int*)(iVar2 + uVar6 * 4);
                if ((*(float*)(iVar7 + 0x9c) < 0.99f) && (1.01f < *(float*)(iVar7 + 0x9c))) {
                    local_e0 = 1;
                }
                if (param_5 == '\0') {
                    float* pfVar5 = (float*)FUN_00548b20(local_34, local_dc);
                    float* pfVar11 = local_dc;
                    for (int iVar7b = 0xd; iVar7b != 0; iVar7b = iVar7b + -1) {
                        *pfVar11 = *pfVar5;
                        pfVar5 = pfVar5 + 1;
                        pfVar11 = pfVar11 + 1;
                    }
                    iVar2 = local_a0;
                }
                if (param_4 == 4) {
                    if (param_3 == '\0') {
                        FUN_005c10f0(pvVar9, local_dc);
                    } else {
                        FUN_005c1160(pvVar9, local_dc);
                    }
                } else {
                    pfVar8[-5] = local_b8;
                    pfVar8[-8] = local_dc[0] * local_ac;
                    pfVar8[-1] = local_b4;
                    pfVar8[3] = local_b0;
                    pfVar8[-4] = local_dc[3] * local_ac;
                    *pfVar8 = local_c4 * local_ac;
                    pfVar8[-7] = local_dc[1] * local_ac;
                    pfVar8[-3] = local_cc * local_ac;
                    pfVar8[1] = local_c0 * local_ac;
                    pfVar8[-6] = local_dc[2] * local_ac;
                    pfVar8[-2] = local_c8 * local_ac;
                    pfVar8[2] = local_bc * local_ac;
                }
                local_e8 = (void*)((int)local_e8 + 0x4c);
                uVar6 = uVar6 + 1;
                pvVar9 = (void*)((int)pvVar9 + 0x40);
                pfVar8 = pfVar8 + 0xc;
            } while (uVar6 < local_a8);
        }
        uint32_t obj5 = *(uint32_t*)(local_a4 + 0x5cc);
        uint32_t vt5 = *(uint32_t*)obj5;
        ((void(*)(uint32_t))(*(void**)(vt5 + 0x104)))(local_e0);
    }
}

// 0x5c3770 — observed shape
// NEEDS_MANUAL: non-contiguous listing (0x5c3770-0x5c3cdc, 0x5c3ce0-0x5c3dba); Ghidra
// dropped the pushed argument lists of several virtual calls, so those calls keep the
// observed call order; every copy loop, colour pack and field store is preserved.
extern int* FUN_005d0b50(void);

void FUN_005c3770(int param_1, void* self, void* in_EBX) {
    int* in_ECX = (int*)self;
    char* regEBX = (char*)in_EBX;
    uint32_t local_34[13];
    uint32_t local_44, local_40, local_3c, local_38;
    uint32_t uStack_54 = 0, uStack_50 = 0, uStack_4c = 0, uStack_48 = 0;
    uint32_t uStack_c0 = 0, uStack_c4 = 0, uStack_e4 = 0, uStack_bc = 0;
    float fStack_b4 = 0.0f;
    uint32_t* puStack_d4 = (uint32_t*)0x0;
    int* piVar2 = *(int**)(param_1 + 0xbc);
    uint32_t* puVar11 = (uint32_t*)(param_1 + 0x6c);
    uint32_t* puVar12 = local_34;
    int iVar7;
    for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
    }
    local_44 = *(uint32_t*)(param_1 + 0x28);
    local_40 = *(uint32_t*)(param_1 + 0x2c);
    local_3c = *(uint32_t*)(param_1 + 0x30);
    local_38 = *(uint32_t*)(param_1 + 0x34);
    if (*(char*)((char*)in_ECX + 0x44c) != '\0') {
        piVar2 = *(int**)(param_1 + 0xbc);
        short sVar4 = ((short(*)(int*))(*(void**)(*piVar2 + 0x38)))(piVar2);
        if (sVar4 != 0) {
            uint32_t vt5c0 = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x5c0);
            ((void(*)(void))(*(void**)(vt5c0 + 0x18)))();
            *(uint32_t*)((char*)in_ECX + 0x30c) = uStack_54;
            *(uint32_t*)((char*)in_ECX + 0x310) = uStack_50;
            *(uint32_t*)((char*)in_ECX + 0x314) = uStack_4c;
            *(uint32_t*)((char*)in_ECX + 0x318) = uStack_48;
            int iStack_94 = piVar2[0xf];
            puVar11 = (uint32_t*)piVar2[8];
            puVar12 = (uint32_t*)piVar2[0xb];
            float* pfVar10 = (float*)piVar2[10];
            float fVar5 = (float)(uint32_t)*(uint16_t*)((char*)piVar2 + 0xc);
            int* local_58 = (int*)FUN_005d0b50();
            if (local_58 != (int*)0x0) {
                uint32_t uVar13 = 2;
                int iVar7b = 0xc;
                if (puVar12 != (uint32_t*)0x0) {
                    uVar13 = 0x102;
                    iVar7b = 0x14;
                }
                if (pfVar10 != (float*)0x0) {
                    uVar13 = uVar13 | 0x40;
                    iVar7b = iVar7b + 4;
                }
                uint32_t fVar3 = *(uint32_t*)(regEBX + 0x38);
                ((void(*)(void))FUN_005d0670)();
                *(float*)(fVar3 + 0x10) = fVar5;
                *(uint32_t*)(fVar3 + 8) = uVar13;
                *(uint32_t*)(fVar3 + 0xc) = 0;
                if (*(int*)(fVar3 + 0x14) != 0) {
                    **(int**)(fVar3 + 0x18) = iVar7b;
                }
                ((char(*)(void))FUN_005cd450)();
                if (*(int*)(fVar3 + 0x14) == 0) {
                    iVar7b = 0;
                } else {
                    iVar7b = **(int**)(fVar3 + 0x1c);
                }
                iStack_94 = *(int*)(iVar7b + 8);
                if (iStack_94 != 0) {
                    uint32_t* puVar6 = ((uint32_t*(*)(void))FUN_005cd310)();
                    if (puVar12 == (uint32_t*)0x0) {
                        if (pfVar10 == (float*)0x0) {
                            if (puVar6 == (uint32_t*)0x0) { return; }
                            float fVar8 = 0.0f;
                            if (3 < (uint32_t)fVar5) {
                                int iVar9 = (((int)fVar5 - 4u) >> 2) + 1;
                                fVar8 = (float)(iVar9 * 4);
                                do {
                                    *puVar6 = *puVar11;
                                    puVar6[1] = puVar11[1];
                                    puVar6[2] = puVar11[2];
                                    puVar6[3] = puVar11[3];
                                    puVar6[4] = puVar11[4];
                                    puVar6[5] = puVar11[5];
                                    puVar6[6] = puVar11[6];
                                    puVar6[7] = puVar11[7];
                                    puVar6[8] = puVar11[8];
                                    puVar6[9] = puVar11[9];
                                    puVar6[10] = puVar11[10];
                                    puVar6[0xb] = puVar11[0xb];
                                    puVar11 = puVar11 + 0xc;
                                    puVar6 = puVar6 + 0xc;
                                    iVar9 = iVar9 + -1;
                                } while (iVar9 != 0);
                            }
                            if ((uint32_t)fVar8 < (uint32_t)fVar5) {
                                int iVar9 = (int)fVar5 - (int)fVar8;
                                do {
                                    *puVar6 = *puVar11;
                                    puVar6[1] = puVar11[1];
                                    puVar6[2] = puVar11[2];
                                    puVar11 = puVar11 + 3;
                                    puVar6 = puVar6 + 3;
                                    iVar9 = iVar9 + -1;
                                } while (iVar9 != 0);
                            }
                        } else {
                            if (puVar6 == (uint32_t*)0x0) { return; }
                            for (; fVar5 != 0.0f; fVar5 = (float)((int)fVar5 + -1)) {
                                *puVar6 = *puVar11;
                                puVar6[1] = puVar11[1];
                                puVar6[2] = puVar11[2];
                                uint32_t uStack_60 = (uint32_t)ROUND(pfVar10[3] * 255.0);
                                float fStack_5c = pfVar10[2] * 255.0f;
                                puVar6[3] = ((uStack_60 << 8 | (int)ROUND(*pfVar10 * 255.0)) << 8 |
                                             (int)ROUND(pfVar10[1] * 255.0)) << 8 |
                                            (int)ROUND(fStack_5c);
                                puVar6 = puVar6 + 4;
                                puVar11 = puVar11 + 3;
                                pfVar10 = pfVar10 + 4;
                            }
                        }
                    } else if (pfVar10 == (float*)0x0) {
                        if (puVar6 == (uint32_t*)0x0) { return; }
                        float fVar8 = 0.0f;
                        if (3 < (uint32_t)fVar5) {
                            int iVar9 = (((int)fVar5 - 4u) >> 2) + 1;
                            fVar8 = (float)(iVar9 * 4);
                            do {
                                *puVar6 = *puVar11;
                                puVar6[1] = puVar11[1];
                                puVar6[2] = puVar11[2];
                                puVar6[3] = *puVar12;
                                puVar6[4] = puVar12[1];
                                puVar6[5] = puVar11[3];
                                puVar6[6] = puVar11[4];
                                puVar6[7] = puVar11[5];
                                puVar6[8] = puVar12[2];
                                puVar6[9] = puVar12[3];
                                puVar6[10] = puVar11[6];
                                puVar6[0xb] = puVar11[7];
                                puVar6[0xc] = puVar11[8];
                                puVar6[0xd] = puVar12[4];
                                puVar6[0xe] = puVar12[5];
                                puVar6[0xf] = puVar11[9];
                                puVar6[0x10] = puVar11[10];
                                puVar6[0x11] = puVar11[0xb];
                                puVar6[0x12] = puVar12[6];
                                puVar6[0x13] = puVar12[7];
                                puVar11 = puVar11 + 0xc;
                                puVar12 = puVar12 + 8;
                                puVar6 = puVar6 + 0x14;
                                iVar9 = iVar9 + -1;
                            } while (iVar9 != 0);
                        }
                        if ((uint32_t)fVar8 < (uint32_t)fVar5) {
                            int iVar9 = (int)fVar5 - (int)fVar8;
                            do {
                                *puVar6 = *puVar11;
                                puVar6[1] = puVar11[1];
                                puVar6[2] = puVar11[2];
                                puVar6[3] = *puVar12;
                                puVar6[4] = puVar12[1];
                                puVar11 = puVar11 + 3;
                                puVar12 = puVar12 + 2;
                                puVar6 = puVar6 + 5;
                                iVar9 = iVar9 + -1;
                            } while (iVar9 != 0);
                        }
                    } else {
                        if (puVar6 == (uint32_t*)0x0) { return; }
                        for (; fVar5 != 0.0f; fVar5 = (float)((int)fVar5 + -1)) {
                            *puVar6 = *puVar11;
                            puVar6[1] = puVar11[1];
                            puVar6[2] = puVar11[2];
                            float* pfVar1 = pfVar10 + 3;
                            float fVar8 = *pfVar10;
                            uint32_t uStack_60 = (uint32_t)ROUND(pfVar10[1] * 255.0);
                            float fStack_5c = (float)(int)ROUND(pfVar10[2] * 255.0);
                            puVar11 = puVar11 + 3;
                            pfVar10 = pfVar10 + 4;
                            puVar6[3] = (((int)ROUND(*pfVar1 * 255.0) << 8 |
                                          (int)ROUND(fVar8 * 255.0)) << 8 | uStack_60) << 8 |
                                        (uint32_t)fStack_5c;
                            puVar6[4] = *puVar12;
                            puVar6[5] = puVar12[1];
                            puVar12 = puVar12 + 2;
                            puVar6 = puVar6 + 6;
                        }
                    }
                    FUN_005cd3a0(*(uint32_t*)(iVar7b + 8));
                    uint32_t vt898 = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x898);
                    uint32_t vt60 = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x60);
                    uint32_t obj5cc = *(uint32_t*)((char*)in_ECX + 0x5cc);
                    uint32_t sub227c = *(uint32_t*)(obj5cc + 0x227c);
                    uint32_t v227c = *(uint32_t*)sub227c;
                    int iVar7c = ((int(*)(void))(*(void**)(vt898 + 0x14)))();
                    if (iVar7c == 0) {
                        ((void(*)(void))(*(void**)(vt898 + 0x18)))();
                        iVar7c = ((int(*)(void))(*(void**)(vt898 + 0x30)))();
                        if (*(int*)(fVar3 + 0x14) == 0) {
                            uStack_c0 = 0;
                        } else {
                            uStack_c0 = **(uint32_t**)(fVar3 + 0x18);
                        }
                        ((void(*)(void))(*(void**)(vt60 + 400)))();
                        ((void(*)(void))(*(void**)(vt60 + 0x1a0)))();
                        while (iVar7c != 0) {
                            ((void(*)(int, int, uint32_t, uint32_t))(*(void**)(vt898 + 0x1c)))(
                                0, 0, fVar3, *(uint32_t*)((char*)in_ECX + 0x10));
                            ((void(*)(int, int, int, uint32_t, uint32_t, uint32_t, float*, uint32_t*))
                             (*(void**)(vt898 + 0x20)))(0, 0, 0, fVar3,
                                *(uint32_t*)((char*)in_ECX + 0x10),
                                *(uint32_t*)((char*)in_ECX + 0x14), &fStack_b4, &uStack_c4);
                            ((void(*)(int, int, int, uint32_t, uint32_t, uint32_t, uint32_t**, uint32_t*))
                             (*(void**)(vt898 + 0x24)))(0, 0, 0, fVar3,
                                *(uint32_t*)((char*)in_ECX + 0x10),
                                *(uint32_t*)((char*)in_ECX + 0x14), &puStack_d4, &uStack_e4);
                            ((void(*)(void))(*(void**)(v227c + 4)))();
                            ((void(*)(int*, int, uint32_t, int, uint32_t, int, uint32_t))
                             (*(void**)(vt60 + 0x148)))(*(int**)((char*)in_ECX + 0x60), 2,
                                *(uint32_t*)(fVar3 + 0x2c), 0, *(uint32_t*)(fVar3 + 0x10), 0,
                                uStack_bc >> 1);
                            iVar7c = ((int(*)(void))(*(void**)(vt898 + 0x34)))();
                        }
                        ((void(*)(int, int, uint32_t, uint32_t))(*(void**)(vt898 + 0x2c)))(
                            0, 0, fVar3, *(uint32_t*)((char*)in_ECX + 0x10));
                    }
                }
            }
        }
    }
}

// 0x5c3dc0 — observed shape
extern void FUN_005bf8c0(void);

void FUN_005c3dc0(void* self) {
    int* in_ECX = (int*)self;
    int* piVar5 = *(int**)((char*)in_ECX + 0x2c8);
    *(uint8_t*)((char*)in_ECX + 0x58) = 0;
    if (piVar5 != (int*)0x0) {
        int iVar7 = *piVar5;
        int iVar6 = *(int*)(iVar7 + 0xc0);
        int iVar4 = piVar5[2];
        if (*(int**)((char*)in_ECX + 0x2d8) != (int*)0x0) {
            uint32_t vt2d8 = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x2d8);
            uint32_t vt898 = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x898);
            uint32_t vt60 = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x60);
            uint32_t obj5cc = *(uint32_t*)((char*)in_ECX + 0x5cc);
            uint32_t vt5cc = *(uint32_t*)obj5cc;
            uint32_t sub227c = *(uint32_t*)(obj5cc + 0x227c);
            uint32_t v227c = *(uint32_t*)sub227c;
            int iVar9 = iVar7;
            int iVar3 = ((int(*)(int, int, int, uint32_t, uint32_t, int, int))
                         (*(void**)(vt2d8 + 0x14)))(iVar7, iVar6, iVar4,
                            *(uint32_t*)((char*)in_ECX + 0x2d0), *(uint32_t*)((char*)in_ECX + 0x2d4),
                            iVar7 + 0x6c, iVar7 + 0x28);
            if (iVar3 == 0) {
                ((void(*)(int, int, int, uint32_t, uint32_t, int, int))(*(void**)(vt2d8 + 0x18)))(
                    iVar7, iVar6, iVar4, *(uint32_t*)((char*)in_ECX + 0x2d0),
                    *(uint32_t*)((char*)in_ECX + 0x2d4), iVar7 + 0x6c, iVar7 + 0x28);
                iVar3 = ((int(*)(void))(*(void**)(vt2d8 + 0x30)))();
                if (iVar3 != 0) {
                    do {
                        piVar5 = *(int**)((char*)in_ECX + 0x2c8);
                        iVar7 = *piVar5;
                        int* piVar8 = *(int**)((char*)in_ECX + 0x2d4);
                        ((void(*)(int, uint32_t, int, uint32_t, int*, int, int))
                         (*(void**)(vt2d8 + 0x1c)))(iVar7, *(uint32_t*)(iVar7 + 0xc0), piVar5[2],
                            *(uint32_t*)((char*)in_ECX + 0x2d0), piVar8, iVar7 + 0x6c, iVar7 + 0x28);
                        iVar6 = iVar9;
                        while (true) {
                            iVar7 = *piVar5;
                            iVar4 = piVar5[2];
                            iVar9 = piVar5[1];
                            bool cond = (*(int**)((char*)in_ECX + 0x2d8) !=
                                         *(int**)((char*)in_ECX + 0x898)) || (iVar9 == 0);
                            if (!cond) {
                                piVar5 = piVar8;
                                cond = ((uint32_t)*(uint16_t*)(iVar9 + 0x20) <=
                                        *(uint32_t*)((char*)in_ECX + 0x450));
                            }
                            if (cond) {
                                iVar3 = iVar4;
                                ((void(*)(int, uint32_t, int, int, uint32_t, uint32_t, int, int))
                                 (*(void**)(vt2d8 + 0x20)))(iVar7, *(uint32_t*)(iVar7 + 0xc0), iVar9,
                                    iVar4, *(uint32_t*)((char*)in_ECX + 0x2d0),
                                    *(uint32_t*)((char*)in_ECX + 0x2d4), iVar7 + 0x6c, iVar7 + 0x28);
                                iVar4 = ((int(*)(int, int, int, uint32_t))
                                         (*(void**)(vt2d8 + 0x28)))(iVar7, iVar9, iVar4,
                                            *(uint32_t*)((char*)in_ECX + 0x2d0));
                                ((void(*)(int, int, int, int, uint32_t, uint32_t, int, int))
                                 (*(void**)(vt2d8 + 0x24)))(iVar7, iVar3, iVar9, iVar4,
                                    *(uint32_t*)((char*)in_ECX + 0x2d0),
                                    *(uint32_t*)((char*)in_ECX + 0x2d4), iVar7 + 0x6c, iVar7 + 0x28);
                                ((void(*)(void))(*(void**)(v227c + 4)))();
                                if (*(int*)(iVar4 + 0x28) == 0) {
                                    ((void(*)(int*, uint32_t, uint32_t, uint32_t))
                                     (*(void**)(vt60 + 0x144)))(*(int**)((char*)in_ECX + 0x60),
                                        *(uint32_t*)(iVar4 + 0x34), *(uint32_t*)(iVar4 + 0x2c),
                                        *(uint32_t*)(iVar4 + 0x38));
                                } else {
                                    iVar9 = 0;
                                    uint32_t uVar10 = 0;
                                    if (*(int*)(iVar4 + 0x3c) != 0) {
                                        do {
                                            if (*(int*)(iVar4 + 0x40) == 0) {
                                                iVar3 = *(int*)(iVar4 + 0x38);
                                            } else {
                                                iVar3 = *(uint16_t*)(*(int*)(iVar4 + 0x40) + uVar10 * 2) - 2;
                                            }
                                            ((void(*)(int*, uint32_t, uint32_t, int, uint32_t, int, int))
                                             (*(void**)(vt60 + 0x148)))(*(int**)((char*)in_ECX + 0x60),
                                                *(uint32_t*)(iVar4 + 0x34), *(uint32_t*)(iVar4 + 0x2c), 0,
                                                *(uint32_t*)(iVar4 + 0x10), iVar9, iVar3);
                                            iVar9 = iVar9 + 2 + iVar3;
                                            uVar10 = uVar10 + 1;
                                        } while (uVar10 < *(uint32_t*)(iVar4 + 0x3c));
                                    }
                                }
                                piVar5 = (int*)piVar8[3];
                            }
                            if (piVar5 == (int*)0x0) { break; }
                            piVar8 = piVar5;
                        }
                        iVar3 = ((int(*)(void))(*(void**)(vt2d8 + 0x34)))();
                        iVar9 = iVar6;
                    } while (iVar3 != 0);
                }
                for (piVar5 = *(int**)((char*)in_ECX + 0x2c8); piVar5 != (int*)0x0; piVar5 = (int*)piVar5[3]) {
                    uint16_t* puVar1 = (uint16_t*)(*(int*)(*piVar5 + 0xbc) + 0x32);
                    *puVar1 = *puVar1 & 0xf000;
                }
                ((void(*)(int, int, int, uint32_t, uint32_t, int, int))(*(void**)(vt2d8 + 0x2c)))(
                    iVar7, iVar6, iVar4, *(uint32_t*)((char*)in_ECX + 0x2d0),
                    *(uint32_t*)((char*)in_ECX + 0x2d4), iVar7 + 0x6c, iVar7 + 0x28);
                uint32_t* puVar2 = *(uint32_t**)((char*)in_ECX + 0x2d8);
                if (puVar2 != (uint32_t*)0x0) {
                    int* piVar5b = (int*)puVar2 + 1;
                    *piVar5b = *piVar5b + -1;
                    if (*piVar5b == 0) {
                        ((void(*)(int))(*(void**)(*puVar2)))(1);
                    }
                    *(uint32_t*)((char*)in_ECX + 0x2d8) = 0;
                }
                *(uint32_t*)((char*)in_ECX + 0x2d0) = 0;
                *(uint32_t*)((char*)in_ECX + 0x2d4) = 0;
                FUN_005bf8c0();
                ((void(*)(uint32_t))(*(void**)(vt5cc + 0x104)))(0);
            }
        }
    }
}

// 0x5c4080 — observed shape
extern int* DAT_00728d84;
extern uint8_t DAT_00728dfc;
extern void* FUN_00449390(void*, uint32_t);

void FUN_005c4080(int param_1, void* self, int in_ESI) {
    int* in_ECX = (int*)self;
    int* piVar6 = *(int**)(param_1 + 0xbc);
    int iVar8 = *(int*)(param_1 + 0xc0);
    int iVar9;
    short sVar3;
    uint32_t uVar5;
    if (in_ECX[0xb6] == 0) {
        uint32_t* puVar4 = (uint32_t*)FUN_00449390(&DAT_00728dfc, *(uint32_t*)(param_1 + 200));
        uint32_t* puVar2 = (uint32_t*)in_ECX[0xb6];
        if (puVar2 != puVar4) {
            if (puVar2 != (uint32_t*)0x0) {
                int* piVar7 = (int*)puVar2 + 1;
                *piVar7 = *piVar7 + -1;
                if (*piVar7 == 0) {
                    ((void(*)(int))(*(void**)(*puVar2)))(1);
                }
            }
            in_ECX[0xb6] = (int)puVar4;
            if (puVar4 != (uint32_t*)0x0) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
        if (in_ECX[0xb6] == 0) {
            iVar9 = in_ECX[0x226];
            if (iVar9 != 0) {
                in_ECX[0xb6] = iVar9;
                *(int*)(iVar9 + 4) = *(int*)(iVar9 + 4) + 1;
            }
        }
    }
    if ((char)in_ECX[0x113] != '\0') {
        sVar3 = ((short(*)(int*))(*(void**)(*piVar6 + 0x38)))(piVar6);
        if (sVar3 != 0) {
            if (((*(uint16_t*)((int)piVar6 + 0x32) & 0xf000) == 0x8000) ||
                ((iVar8 != 0) &&
                 ((uVar5 = ((uint32_t(*)(int*))(*(void**)(*in_ECX + 0x38)))(in_ECX) & 0x200) == 0))) {
                iVar9 = in_ECX[0x172];
            } else {
                iVar9 = in_ECX[0x171];
            }
            ((void(*)(int, int*, int, int))(*(void**)(*(int*)in_ECX[0x170] + 0x18)))(
                iVar9, piVar6, iVar8, 0);
            if ((iVar8 == 0) ||
                ((uVar5 = ((uint32_t(*)(int*))(*(void**)(*in_ECX + 0x38)))(in_ECX) & 0x200) == 0)) {
                uint32_t* piVar7 = (uint32_t*)DAT_00728d84;
                if (DAT_00728d84 == (int*)0x0) {
                    piVar7 = (uint32_t*)FUN_00533c78(0x10);
                } else {
                    int* piVar1 = DAT_00728d84 + 3;
                    DAT_00728d84 = (int*)DAT_00728d84[3];
                    *piVar1 = 0;
                }
                *piVar7 = (uint32_t)param_1;
                piVar7[1] = 0;
                piVar7[2] = (uint32_t)piVar6[0xe];
                piVar7[3] = 0;
                if (in_ECX[0xb3] != 0) {
                    *(uint32_t**)(in_ECX[0xb3] + 0xc) = piVar7;
                    in_ECX[0xb3] = (int)piVar7;
                    return;
                }
                in_ECX[0xb2] = (int)piVar7;
                in_ECX[0xb3] = (int)piVar7;
            } else {
                if (*(int*)(iVar8 + 0xc) == 0) {
                    iVar8 = 0;
                } else {
                    iVar8 = *(int*)(*(int*)(iVar8 + 0xc) + 0xc);
                }
                iVar9 = *(int*)(iVar8 + 0x10);
                iVar8 = *(int*)(iVar8 + 0xc);
                if (iVar8 != 0) {
                    do {
                        piVar6 = DAT_00728d84;
                        if (DAT_00728d84 == (int*)0x0) {
                            piVar6 = (int*)FUN_00533c78(0x10);
                        } else {
                            int* piVar7b = DAT_00728d84 + 3;
                            DAT_00728d84 = (int*)DAT_00728d84[3];
                            *piVar7b = 0;
                        }
                        *piVar6 = in_ESI;
                        piVar6[1] = iVar9;
                        piVar6[2] = *(int*)(iVar9 + 0x28);
                        piVar6[3] = 0;
                        if (in_ECX[0xb3] == 0) {
                            in_ECX[0xb2] = (int)piVar6;
                        } else {
                            *(int**)(in_ECX[0xb3] + 0xc) = piVar6;
                        }
                        iVar9 = iVar9 + 0x2c;
                        iVar8 = iVar8 + -1;
                        in_ECX[0xb3] = (int)piVar6;
                    } while (iVar8 != 0);
                    return;
                }
            }
        }
    }
}

// 0x5c4270 — observed shape
void FUN_005c4270(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, int param_6, void* self, uint32_t reg_EBP,
                  uint32_t reg_ESI, uint32_t reg_EDI) {
    int* in_ECX = (int*)self;
    int* piVar1;
    int iVar2, iVar3, iVar7, iVar8, iVar9;
    uint32_t uVar4, uVar5, uVar6;
    uint32_t vt60 = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x60);
    uint32_t vt5cc = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x5cc);
    if ((param_1 == 0) ||
        ((piVar1 = (int*)FUN_00449390(&DAT_00728dfc, *(uint32_t*)(param_1 + 200))) == (int*)0x0)) {
        piVar1 = *(int**)((char*)in_ECX + 0x898);
    }
    iVar8 = param_1;
    iVar9 = param_6;
    iVar2 = ((int(*)(int, uint32_t, int, uint32_t, uint32_t, uint32_t, uint32_t))
             (*(void**)(*piVar1 + 0x14)))(param_1, param_3, param_6,
                *(uint32_t*)((char*)in_ECX + 0x10), *(uint32_t*)((char*)in_ECX + 0x14),
                param_4, param_5);
    if (iVar2 == 0) {
        iVar2 = param_1;
        iVar7 = param_6;
        ((void(*)(int, uint32_t, int, uint32_t, uint32_t, uint32_t, uint32_t))
         (*(void**)(*piVar1 + 0x18)))(param_1, reg_EDI, param_6,
            *(uint32_t*)((char*)in_ECX + 0x10), *(uint32_t*)((char*)in_ECX + 0x14),
            reg_ESI, reg_EBP);
        iVar3 = ((int(*)(void))(*(void**)(*piVar1 + 0x30)))();
        while (iVar3 != 0) {
            ((void(*)(int, int, int, uint32_t, uint32_t, uint32_t, int))
             (*(void**)(*piVar1 + 0x1c)))(param_1, iVar8, param_6,
                *(uint32_t*)((char*)in_ECX + 0x10), *(uint32_t*)((char*)in_ECX + 0x14),
                param_3, iVar9);
            uVar6 = *(uint32_t*)((char*)in_ECX + 0x14);
            uVar5 = *(uint32_t*)((char*)in_ECX + 0x10);
            iVar3 = param_6;
            ((void(*)(int, int, int, int, uint32_t, uint32_t, uint32_t, uint32_t))
             (*(void**)(*piVar1 + 0x20)))(param_1, iVar2, 0, param_6, uVar5, uVar6, reg_EDI, iVar7);
            param_6 = ((int(*)(int, int, int, uint32_t))(*(void**)(*piVar1 + 0x28)))(
                param_1, 0, param_6, *(uint32_t*)((char*)in_ECX + 0x10));
            ((void(*)(int, int, int, int, uint32_t, uint32_t, uint32_t, uint32_t))
             (*(void**)(*piVar1 + 0x24)))(param_1, iVar3, 0, param_6,
                *(uint32_t*)((char*)in_ECX + 0x10), *(uint32_t*)((char*)in_ECX + 0x14), uVar5, uVar6);
            uint32_t obj5cc = *(uint32_t*)((char*)in_ECX + 0x5cc);
            uint32_t sub227c = *(uint32_t*)(obj5cc + 0x227c);
            uint32_t v227c = *(uint32_t*)sub227c;
            ((void(*)(void))(*(void**)(v227c + 4)))();
            if (*(int*)(param_6 + 0x28) == 0) {
                ((void(*)(int*, uint32_t, uint32_t, uint32_t))(*(void**)(vt60 + 0x144)))(
                    *(int**)((char*)in_ECX + 0x60), *(uint32_t*)(param_6 + 0x34),
                    *(uint32_t*)(param_6 + 0x2c), *(uint32_t*)(param_6 + 0x38));
            } else {
                uVar4 = 0;
                if (*(int*)(param_6 + 0x3c) != 0) {
                    do {
                        if (*(int*)(param_6 + 0x40) == 0) {
                            iVar3 = *(int*)(param_6 + 0x38);
                        } else {
                            iVar3 = *(uint16_t*)(*(int*)(param_6 + 0x40) + uVar4 * 2) - 2;
                        }
                        ((void(*)(int*, uint32_t, uint32_t, int, uint32_t, uint32_t, int))
                         (*(void**)(vt60 + 0x148)))(*(int**)((char*)in_ECX + 0x60),
                            *(uint32_t*)(param_6 + 0x34), *(uint32_t*)(param_6 + 0x2c), 0,
                            *(uint32_t*)(param_6 + 0x10), *(uint32_t*)(param_6 + 0x30), iVar3);
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)(param_6 + 0x3c));
                }
            }
            iVar3 = ((int(*)(void))(*(void**)(*piVar1 + 0x34)))();
        }
        ((void(*)(int, int, int, uint32_t, uint32_t, uint32_t, int))(*(void**)(*piVar1 + 0x2c)))(
            param_1, iVar8, param_6, *(uint32_t*)((char*)in_ECX + 0x10),
            *(uint32_t*)((char*)in_ECX + 0x14), param_3, iVar9);
        ((void(*)(uint32_t))(*(void**)(vt5cc + 0x104)))(0);
    }
}

// 0x5c4450 — observed shape
void FUN_005c4450(int param_1, uint32_t param_2, int param_3, uint32_t param_4, uint32_t* param_5,
                  void* self, uint32_t reg_EBP, uint32_t reg_EDI) {
    int* in_ECX = (int*)self;
    int local_1c;
    uint32_t uStack_18 = 0, uStack_10 = 0, uStack_c = 0;
    if (param_3 != 0) {
        if (*(int*)(param_3 + 0xc) == 0) {
            local_1c = 0;
        } else {
            local_1c = *(int*)(*(int*)(param_3 + 0xc) + 0xc);
        }
        int iVar3 = *(int*)(local_1c + 0x10);
        int* piVar2;
        if ((param_1 == 0) ||
            ((piVar2 = (int*)FUN_00449390(&DAT_00728dfc, *(uint32_t*)(param_1 + 200))) == (int*)0x0)) {
            piVar2 = *(int**)((char*)in_ECX + 0x898);
        }
        uint32_t* puVar4 = *(uint32_t**)(iVar3 + 0x28);
        uint32_t* puVar11 = puVar4;
        iVar3 = ((int(*)(int, int, uint32_t*, uint32_t, uint32_t, uint32_t, uint32_t*))
                 (*(void**)(*piVar2 + 0x14)))(param_1, param_3, puVar4,
                    *(uint32_t*)((char*)in_ECX + 0x10), *(uint32_t*)((char*)in_ECX + 0x14),
                    param_4, param_5);
        if (iVar3 == 0) {
            int iVar3b = *(int*)((char*)in_ECX + 0x14);
            uint32_t uVar14 = *(uint32_t*)((char*)in_ECX + 0x10);
            uint32_t* puVar6 = puVar4;
            ((void(*)(uint32_t, uint32_t, uint32_t*, uint32_t, int, uint32_t))
             (*(void**)(*piVar2 + 0x18)))(uStack_18, uStack_10, puVar4, uVar14, iVar3b, uStack_c);
            uint32_t uVar15 = *(uint32_t*)(iVar3b + 0xc);
            iVar3 = ((int(*)(void))(*(void**)(*piVar2 + 0x30)))();
            uint32_t* puVar7 = param_5;
            uint32_t vt60 = *(uint32_t*) *(uint32_t*)((char*)in_ECX + 0x60);
            uint32_t obj5cc = *(uint32_t*)((char*)in_ECX + 0x5cc);
            uint32_t vt5cc = *(uint32_t*)obj5cc;
            while (iVar3 != 0) {
                int iVar3c = *(int*)((char*)in_ECX + 0x14);
                uint32_t uVar9 = *(uint32_t*)((char*)in_ECX + 0x10);
                uint32_t* puVar8 = puVar4;
                uint32_t uVar16 = param_4;
                ((void(*)(uint32_t, uint32_t, uint32_t*, uint32_t, int, uint32_t, uint32_t*))
                 (*(void**)(*piVar2 + 0x1c)))(param_4, reg_EBP, puVar4, uVar9, iVar3c, reg_EDI, puVar7);
                *(uint32_t*)((char*)in_ECX + 0x30c) = *puVar7;
                *(uint32_t*)((char*)in_ECX + 0x310) = puVar7[1];
                *(uint32_t*)((char*)in_ECX + 0x314) = puVar7[2];
                *(uint32_t*)((char*)in_ECX + 0x318) = puVar7[3];
                uint32_t uVar12 = 0;
                uint32_t* puVar13 = puVar6;
                if (uStack_10 != 0) {
                    puVar7 = puVar11;
                    do {
                        if ((piVar2 != *(int**)((char*)in_ECX + 0x898)) ||
                            ((uint32_t)*(uint16_t*)(puVar6 + 8) <= *(uint32_t*)((char*)in_ECX + 0x450))) {
                            uint32_t uVar1 = puVar6[10];
                            puVar11 = puVar6;
                            ((void(*)(uint32_t, int, uint32_t*, uint32_t, uint32_t, int, uint32_t, uint32_t*))
                             (*(void**)(*piVar2 + 0x20)))(uStack_c, param_1, puVar6, uVar1,
                                *(uint32_t*)((char*)in_ECX + 0x10), *(uint32_t*)((char*)in_ECX + 0x14),
                                uVar15, puVar7);
                            puVar4 = (uint32_t*)((int(*)(int, uint32_t*, uint32_t, uint32_t))
                                                 (*(void**)(*piVar2 + 0x28)))(iVar3c, puVar6, uVar1,
                                                    *(uint32_t*)((char*)in_ECX + 0x10));
                            if (puVar4 == (uint32_t*)0x0) { return; }
                            ((void(*)(uint32_t, uint32_t*, uint32_t*, uint32_t*, uint32_t, int, uint32_t, int))
                             (*(void**)(*piVar2 + 0x24)))(param_4, puVar8, puVar6, puVar4,
                                *(uint32_t*)((char*)in_ECX + 0x10), *(uint32_t*)((char*)in_ECX + 0x14),
                                uVar9, iVar3c);
                            uint32_t sub227c = *(uint32_t*)(obj5cc + 0x227c);
                            uint32_t v227c = *(uint32_t*)sub227c;
                            ((void(*)(void))(*(void**)(v227c + 4)))();
                            iVar3 = 0;
                            uint32_t uVar10 = 0;
                            if (puVar4[0xf] != 0) {
                                do {
                                    puVar6 = puVar11;
                                    int iVar5;
                                    if (puVar4[0x10] == 0) {
                                        iVar5 = puVar4[0xe];
                                    } else {
                                        iVar5 = *(uint16_t*)(puVar4[0x10] + uVar10 * 2) - 2;
                                    }
                                    ((void(*)(int*, uint32_t, uint32_t, int, uint16_t, int, int))
                                     (*(void**)(vt60 + 0x148)))(*(int**)((char*)in_ECX + 0x60), uVar14,
                                        puVar4[0xb], 0, *(uint16_t*)(puVar6 + 7), iVar3, iVar5);
                                    iVar3 = iVar3 + 2 + iVar5;
                                    uVar10 = uVar10 + 1;
                                    puVar11 = puVar6;
                                } while (uVar10 < (uint32_t)puVar4[0xf]);
                            }
                        }
                        uVar12 = uVar12 + 1;
                        puVar6 = puVar6 + 0xb;
                    } while (uVar12 < uStack_10);
                    puVar11 = puVar7;
                }
                *(uint16_t*)((int)param_5 + 0x32) = *(uint16_t*)((int)param_5 + 0x32) & 0xf000;
                iVar3 = ((int(*)(void))(*(void**)(*piVar2 + 0x34)))();
                puVar6 = puVar13;
                param_4 = uVar16;
            }
            ((void(*)(uint32_t, uint32_t, uint32_t*, uint32_t, int, uint32_t, uint32_t*))
             (*(void**)(*piVar2 + 0x2c)))(param_4, reg_EBP, puVar4,
                *(uint32_t*)((char*)in_ECX + 0x10), *(uint32_t*)((char*)in_ECX + 0x14),
                reg_EDI, puVar7);
            ((void(*)(uint32_t))(*(void**)(vt5cc + 0x104)))(0);
        }
    }
}

// 0x5c4760 — observed shape
// NEEDS_MANUAL: non-contiguous listing (0x5c4760-0x5c495c, 0x5c4960-0x5c4c8e); the vertex
// loop, modulo wrap, UV/RGBA packing and dynamic buffer rebuilds are reconstructed in full.
extern void FUN_004127b0(int, int, uint32_t, void*);
extern void LAB_005cea70(void);
extern void LAB_004b1250(void);
extern int FUN_005cd8b0(int, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int, int);

void FUN_005c4760(int param_1, uint32_t param_2, void* self) {
    int* in_ECX = (int*)self;
    uint16_t uVar1 = *(uint16_t*)(param_1 + 0x14);
    int iVar3 = *(int*)(param_1 + 0x20);
    *(uint32_t*)(iVar3 + 0x3c) = 1;
    uint32_t uVar12 = (uint32_t)uVar1 * 4;
    uint32_t uVar22 = uVar12 & 0xffff;
    *(uint32_t*)(iVar3 + 0x38) = (uint32_t)uVar1 << 1;
    int iVar16 = 0;
    uint32_t uVar21 = (uVar22 * 3) / 2;
    uint8_t bVar7 = (uint8_t)((uint8_t)param_2 >> 3) & 1;
    *(uint32_t*)(iVar3 + 0x10) = uVar22;
    *(uint32_t*)(iVar3 + 0x44) = 0;
    *(uint32_t*)(iVar3 + 0x40) = 0;
    if (*(int*)(iVar3 + 0x14) != 0) {
        iVar16 = **(int**)(iVar3 + 0x1c);
    }
    if (bVar7 != 0) {
        uint16_t local_30 = (uint16_t)uVar12;
        if (*(uint16_t*)((char*)in_ECX + 0x890) < local_30) {
            operator_delete__(*(void**)((char*)in_ECX + 0x880));
            operator_delete__(*(void**)((char*)in_ECX + 0x884));
            operator_delete__(*(void**)((char*)in_ECX + 0x888));
            int iVar10 = (int)thunk_FUN_00533c78(uVar22 * 8);
            if (iVar10 == 0) {
                iVar10 = 0;
            } else {
                FUN_004127b0(iVar10, 8, uVar22, (void*)&LAB_005cea70);
            }
            *(int*)((char*)in_ECX + 0x880) = iVar10;
            iVar10 = (int)thunk_FUN_00533c78(uVar22 << 4);
            if (iVar10 == 0) {
                iVar10 = 0;
            } else {
                FUN_004127b0(iVar10, 0x10, uVar22, (void*)&LAB_004b1250);
            }
            *(int*)((char*)in_ECX + 0x884) = iVar10;
            iVar10 = (int)thunk_FUN_00533c78(uVar22 * 8);
            if (iVar10 == 0) {
                iVar10 = 0;
            } else {
                FUN_004127b0(iVar10, 8, uVar22, (void*)&LAB_005cea70);
            }
            *(int*)((char*)in_ECX + 0x888) = iVar10;
            *(uint16_t*)((char*)in_ECX + 0x890) = local_30;
        }
        if (iVar16 != 0) {
            uint32_t uVar20;
            if (*(int*)(iVar3 + 0x14) == 0) {
                uVar20 = 0;
            } else {
                uVar20 = **(uint32_t**)(iVar3 + 0x18);
            }
            if (*(uint32_t*)(iVar16 + 0x14) / uVar20 < uVar22) {
                param_2 = 0xf;
            }
        }
    }
    if ((param_2 & 0xffff | 0xfffffff7) != 0) {
        int local_3c = 0;
        if (uVar1 != 0) {
            int local_38 = 0;
            do {
                int qObj = *(int*)(uintptr_t)(*(int*)(param_1 + 0x18) + 0x2c);
                int iVar10 = *(int*)(uintptr_t)qObj;
                uint16_t* puVar23 = (uint16_t*)(*(int*)(param_1 + 0xc) + local_38);
                int* piVar17;
                if (iVar10 == 0) {
                    piVar17 = (int*)0x0;
                } else {
                    piVar17 = *(int**)(iVar10 + 4);
                }
                uint16_t uVar8 = ((uint16_t(*)(int*))(*(void**)(*piVar17 + 0x34)))(piVar17);
                qObj = *(int*)(uintptr_t)(*(int*)(param_1 + 0x18) + 0x2c);
                iVar10 = *(int*)(uintptr_t)qObj;
                if (iVar10 == 0) {
                    piVar17 = (int*)0x0;
                } else {
                    piVar17 = *(int**)(iVar10 + 4);
                }
                uint16_t uVar9 = ((uint16_t(*)(int*))(*(void**)(*piVar17 + 0x38)))(piVar17);
                iVar10 = *(int*)(*(int*)((char*)in_ECX + 0x5a4) + 4);
                uint16_t uVar13 = puVar23[1];
                uint32_t uVar20 = (uint32_t)uVar13;
                while ((short)uVar13 < 0) {
                    uVar20 = uVar20 + iVar10;
                    uVar13 = (uint16_t)uVar20;
                }
                short sVar15 = (short)uVar20;
                while (iVar10 <= sVar15) {
                    uVar20 = uVar20 - iVar10;
                    sVar15 = (short)uVar20;
                }
                iVar10 = *(int*)(*(int*)((char*)in_ECX + 0x5a4) + 8);
                uVar13 = *puVar23;
                uVar20 = (uint32_t)uVar13;
                while ((short)uVar13 < 0) {
                    uVar20 = uVar20 + iVar10;
                    uVar13 = (uint16_t)uVar20;
                }
                short sVar14 = (short)uVar20;
                while (iVar10 <= sVar14) {
                    uVar20 = uVar20 - iVar10;
                    sVar14 = (short)uVar20;
                }
                uVar13 = puVar23[2];
                uint16_t uVar2 = puVar23[3];
                uint16_t uVar19 = 0;
                uint32_t uStack_40 = (uint32_t)local_3c << 2;
                float fVar5 = (float)puVar23[5] * (1.0f / (float)uVar8);
                uint32_t uStack_20 = 0;
                float fVar6 = (float)puVar23[4] * (1.0f / (float)uVar9);
                do {
                    float fVar4;
                    if (uVar19 >> 1 == 0) {
                        fVar4 = (float)(int)sVar15 - 0.5f;
                    } else {
                        fVar4 = (float)uVar13 + ((float)(int)sVar15 - 0.5f);
                    }
                    uint32_t uVar18 = uStack_20 & 0x80000001;
                    uVar20 = uStack_40 & 0xffff;
                    *(float*)(*(int*)((char*)in_ECX + 0x880) + uVar20 * 8) = fVar4;
                    if ((int)uVar18 < 0) {
                        uVar18 = (uVar18 - 1 | 0xfffffffe) + 1;
                    }
                    if (uVar18 == 0) {
                        fVar4 = (float)(int)sVar14 - 0.5f;
                    } else {
                        fVar4 = (float)uVar2 + ((float)(int)sVar14 - 0.5f);
                    }
                    *(float*)(*(int*)((char*)in_ECX + 0x880) + 4 + uVar20 * 8) = fVar4;
                    uint32_t* puVar24 = (uint32_t*)(uVar20 * 0x10 + *(int*)((char*)in_ECX + 0x884));
                    *puVar24 = *(uint32_t*)(puVar23 + 6);
                    puVar24[1] = *(uint32_t*)(puVar23 + 8);
                    puVar24[2] = *(uint32_t*)(puVar23 + 10);
                    puVar24[3] = *(uint32_t*)(puVar23 + 0xc);
                    if (uVar19 >> 1 == 0) {
                        fVar4 = fVar5;
                    } else {
                        fVar4 = (float)uVar13 * (1.0f / (float)uVar8) + fVar5;
                    }
                    *(float*)(*(int*)((char*)in_ECX + 0x888) + uVar20 * 8) = fVar4;
                    if (uVar18 == 0) {
                        fVar4 = fVar6;
                    } else {
                        fVar4 = (float)uVar2 * (1.0f / (float)uVar9) + fVar6;
                    }
                    *(float*)(*(int*)((char*)in_ECX + 0x888) + 4 + uVar20 * 8) = fVar4;
                    uVar19 = uVar19 + 1;
                    uStack_40 = uStack_40 + 1;
                    uStack_20 = uStack_20 + 1;
                } while (uVar19 < 4);
                local_3c = local_3c + 1;
                local_38 = local_38 + 0x1c;
            } while ((uint16_t)local_3c < uVar1);
        }
        iVar16 = FUN_005cd8b0(iVar3, uVar12, *(uint32_t*)((char*)in_ECX + 0x880),
                              *(uint32_t*)((char*)in_ECX + 0x884), *(uint32_t*)((char*)in_ECX + 0x888),
                              param_2, iVar16, 0);
        if (iVar16 == 0) {
            return;
        }
    }
    if (bVar7 != 0) {
        if (*(uint32_t*)((char*)in_ECX + 0x894) < uVar21) {
            operator_delete__(*(void**)((char*)in_ECX + 0x88c));
            uint32_t uVar11 = (uint32_t)thunk_FUN_00533c78(uVar21 * 2);
            *(uint32_t*)((char*)in_ECX + 0x88c) = uVar11;
            uVar12 = 0;
            uint32_t uVar20 = 0;
            *(uint32_t*)((char*)in_ECX + 0x894) = uVar21;
            if (uVar22 != 0) {
                do {
                    short sVar15 = (short)uVar20;
                    *(int16_t*)(*(int*)((char*)in_ECX + 0x88c) + (uVar12 & 0xffff) * 2) = sVar15;
                    *(int16_t*)(*(int*)((char*)in_ECX + 0x88c) + (uVar12 + 1 & 0xffff) * 2) = sVar15 + 1;
                    *(int16_t*)(*(int*)((char*)in_ECX + 0x88c) + (uVar12 + 2 & 0xffff) * 2) = sVar15 + 2;
                    *(int16_t*)(*(int*)((char*)in_ECX + 0x88c) + (uVar12 + 3 & 0xffff) * 2) = sVar15 + 2;
                    *(int16_t*)(*(int*)((char*)in_ECX + 0x88c) + (uVar12 + 4 & 0xffff) * 2) = sVar15 + 1;
                    *(int16_t*)(*(int*)((char*)in_ECX + 0x88c) + (uVar12 + 5 & 0xffff) * 2) = sVar15 + 3;
                    uVar20 = uVar20 + 4;
                    uVar12 = uVar12 + 6;
                } while (uVar20 < uVar22);
            }
        }
        iVar16 = *(int*)(iVar3 + 0x28);
        param_2 = *(uint32_t*)(iVar3 + 0x24);
        int iVar10 = FUN_005d0850(*(void**)((char*)in_ECX + 0x88c), uVar21, (uint32_t)iVar16,
                                  &param_2, 1, 0);
        if (iVar16 != iVar10) {
            FUN_005d0650();
            *(int*)(iVar3 + 0x28) = iVar10;
            *(uint32_t*)(iVar3 + 0x20) = uVar21;
            *(uint32_t*)(iVar3 + 0x24) = param_2;
        }
    }
}

