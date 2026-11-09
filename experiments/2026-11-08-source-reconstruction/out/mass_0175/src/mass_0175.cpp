#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers and globals referenced by the assigned corpus
extern void operator_delete(void* ptr);
extern void* PTR_FUN_006c4350;
extern void* PTR_FUN_006c4348;
extern void* PTR_FUN_006c4344;
extern void* PTR_FUN_006c43cc;
extern void FUN_00575a00(void* self);
extern void FUN_00552d20(void* self);
extern void FUN_00538400(void* self);
extern void FUN_00538430(void* self);
extern void FUN_00538460(void* self, int param_1);
extern void FUN_00535150(int param_1);
extern uint32_t DAT_007284e8[];
extern uint32_t DAT_00728564_fn();
extern void* (*DAT_00728564)(uint32_t);
extern uint32_t DAT_00728650[];
extern void FUN_00576640(int param_1, int param_2, int* param_3, int* param_4, float param_5, uint32_t param_6);
extern void FUN_00576320(int param_1, uint32_t param_2, int param_3, uint32_t param_4, float param_5, float param_6, int* param_7, int* param_8);

// 0x575b10 — observed shape
void FUN_00575b10(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4350;
    FUN_00575a00(self);
    operator_delete((void*)(uintptr_t)in_ECX[0x1f]);
    in_ECX[0x19] = (uint32_t)(uintptr_t)&PTR_FUN_006c4348;
    operator_delete((void*)(uintptr_t)in_ECX[0x1a]);
    in_ECX[0x13] = (uint32_t)(uintptr_t)&PTR_FUN_006c4344;
    operator_delete((void*)(uintptr_t)in_ECX[0x14]);
    FUN_00552d20(self);
}

// 0x575bb0 — observed shape
void FUN_00575bb0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    uint8_t* base = (uint8_t*)self;
    int32_t idx;
    if (*(int32_t*)(base + 0xc) != 0) {
        idx = *(int32_t*)(base + 8);
        ((void(*)(int32_t))DAT_007284e8[idx])(*(int32_t*)(base + 0xc));
    }
    *(uint32_t*)(base + 0xc) = param_1;
    *(uint32_t*)(base + 4) = param_2;
    *(uint32_t*)(base + 8) = param_3;
    *(uint32_t*)(base + 0x10) = 0;
}

// 0x575bf0 — observed shape
void FUN_00575bf0(void* self, uint32_t param_1, uint32_t param_2) {
    uint8_t* base = (uint8_t*)self;
    uint32_t uVar1 = 0;
    if (*(int32_t*)(base + 0xc) != 0) {
        int32_t local_4 = 0;
        do {
            int32_t iVar2 = *(int32_t*)(base + 0x14) + local_4;
            int32_t local_8 = *(int32_t*)(iVar2 + 4);
            uint32_t* puStack_c;
            uint32_t uVar3;
            if (local_8 == 0) {
                uVar3 = 1;
                local_8 = 1;
                puStack_c = (uint32_t*)DAT_00728564(1);
                *puStack_c = 0;
                puStack_c[2] = 0;
            } else {
                puStack_c = *(uint32_t**)(iVar2 + 0xc);
                uVar3 = *(uint32_t*)(iVar2 + 8);
            }
            FUN_00576640(0, (int)uVar3, (int*)puStack_c, &local_8, *(float*)&param_1, param_2);
            *(uint32_t**)(iVar2 + 0xc) = puStack_c;
            *(int32_t*)(iVar2 + 4) = local_8;
            *(uint32_t*)(iVar2 + 8) = uVar3;
            *(uint32_t*)(iVar2 + 0x10) = 0;
            uVar1 = uVar1 + 1;
            local_4 = local_4 + 0x14;
        } while (uVar1 < *(uint32_t*)(base + 0xc));
    }
}

// 0x575cb0 — observed shape
void FUN_00575cb0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    int32_t iVar1 = (int32_t)in_ECX[5];
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c43cc;
    if (iVar1 != 0) {
        int32_t iVar2 = *(int32_t*)(iVar1 + -4);
        if (-1 < iVar2 + -1) {
            int32_t iVar3 = iVar1 + iVar2 * 0x14;
            do {
                operator_delete(*(void**)(iVar3 + -0x14));
                if (*(int32_t*)(iVar3 + -8) != 0) {
                    int32_t idx = *(int32_t*)(iVar3 + -0xc);
                    ((void(*)(int32_t))DAT_007284e8[idx])(*(int32_t*)(iVar3 + -8));
                }
                iVar2 = iVar2 + -1;
                iVar3 = iVar3 + -0x14;
            } while (iVar2 != 0);
        }
        operator_delete((void*)(iVar1 + -4));
    }
    FUN_00538400(self);
}

// 0x575ed0 — observed shape
void FUN_00575ed0(void* self, int param_1) {
    uint8_t* base = (uint8_t*)self;
    int32_t iStack_24 = param_1;
    uint32_t uVar1;
    uint32_t uVar2 = 0;
    (void)iStack_24;
    FUN_00538430(self);
    ((void(*)())(**(int32_t**)(param_1 + 0x160) + 0xc))();
    ((void(*)())(**(int32_t**)(param_1 + 0x160) + 0xc))();
    uint8_t auStack_c[12];
    auStack_c[0] = *(uint8_t*)(base + 0x18);
    ((void(*)(uint8_t*, int))(**(int32_t**)(param_1 + 0x160) + 0xc))(auStack_c, 1);
    if (*(int32_t*)(base + 0xc) != 0) {
        int32_t iVar3 = 0;
        do {
            int32_t* piStack_28 = *(int32_t**)(*(int32_t*)(base + 0x14) + 4 + iVar3);
            int32_t iStack_24_inner = *(int32_t*)(*(int32_t*)(base + 0x14) + iVar3 + 8);
            ((void(*)(int32_t**, int))(**(int32_t**)(param_1 + 0x160) + 0xc))(&piStack_28, 4);
            uVar1 = 0;
            uint32_t uStack_2c = 0;
            ((void(*)(uint32_t*, int))(**(int32_t**)(param_1 + 0x160) + 0xc))(&uStack_2c, 4);
            if (piStack_28 != (int32_t*)0) {
                ((void(*)(int, uint32_t, int32_t*))DAT_00728650[iStack_24_inner])(param_1, *(uint32_t*)(*(int32_t*)(base + 0x14) + 0xc + iVar3), piStack_28);
            }
            if (*(int32_t*)(base + 0x10) != 0) {
                do {
                    FUN_00535150(param_1);
                    uVar1 = uVar1 + 1;
                } while (uVar1 < *(uint32_t*)(base + 0x10));
            }
            uVar2 = uVar2 + 1;
            iVar3 = iVar3 + 0x14;
        } while (uVar2 < *(uint32_t*)(base + 0xc));
    }
}

extern uint32_t DAT_007286c8[];
extern void FUN_00569960(void* self);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void FUN_005818f0(void* self);
extern void FUN_00582030(void* self);
extern void FUN_00545cc0(void* self);
extern void FUN_00581fd0(uint32_t param_1);
extern void FUN_00581920(uint32_t param_2, uint32_t param_1, uint32_t param_3);
extern void* FUN_00533c78(uint32_t size);

// 0x575ff0 — observed shape
uint32_t FUN_00575ff0(void* self, int param_1) {
    uint8_t* selfBase = (uint8_t*)self;
    uint8_t* paramBase = (uint8_t*)(uintptr_t)param_1;
    uint32_t uVar9;
    FUN_00538460(self, param_1);
    // Pseudocode shape: verify counts, then iterate elements.
    // Preserve observed early-exit checks.
    uVar9 = *(uint32_t*)(selfBase + 0xc);
    if (uVar9 == 0) return 1;
    uint32_t local_28 = 0;
    uint32_t iVar15 = 0;
    uint32_t count = *(uint32_t*)(selfBase + 0xc);
    for (uint32_t iter = 0; iter < count; ++iter) {
        uint32_t elemCount = *(uint32_t*)(*(uint32_t*)(selfBase + 0x14) + 4 + iVar15);
        if (elemCount != *(uint32_t*)(*(uint32_t*)(paramBase + 0x14) + 4 + iVar15)) return 0;
        if (*(int32_t*)(iVar15 + 8 + *(int32_t*)(selfBase + 0x14)) != *(int32_t*)(*(int32_t*)(paramBase + 0x14) + iVar15 + 8)) return 0;
        void* cmpFn = (void*)DAT_007286c8[*(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar15 + 8)];
        (void)cmpFn;
        // Inner float triple compare loop preserved in structure below
        uint32_t subCount = *(uint32_t*)(selfBase + 0x10);
        for (uint32_t k = 0; k < subCount; ++k) {
            float* a = (float*)(k * 12 + *(int32_t*)(*(int32_t*)(paramBase + 0x14) + iVar15));
            float* b = (float*)(k * 12 + *(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar15));
            if (b[0] != a[0] || b[1] != a[1] || b[2] != a[2]) return 0;
        }
        local_28++;
        iVar15 += 0x14;
        if (local_28 >= *(uint32_t*)(selfBase + 0xc)) break;
    }
    return 1;
}

// 0x5761b0 — observed shape
void FUN_005761b0(void* self, uint8_t param_1) {
    FUN_00575cb0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x576290 — observed shape
uint32_t FUN_00576290(float* param_1, float* param_2) {
    if (*param_1 == *param_2) {
        return 1;
    }
    return 0;
}

// 0x5762b0 — observed shape
uint32_t FUN_005762b0(float param_1, int param_2, uint32_t param_3, uint32_t* param_4) {
    int32_t iVar1;
    uint32_t uVar2;
    *param_4 = 0;
    if (param_3 == 0) {
        return 1;
    }
    do {
        iVar1 = (uint32_t)*(uint8_t*)(param_2 + 4) * *param_4;
        if (param_1 <= *(float*)(iVar1 + param_2)) {
            if (param_1 < *(float*)(iVar1 + param_2)) {
                return 1;
            }
            return 0;
        }
        uVar2 = *param_4 + 1;
        *param_4 = uVar2;
    } while (uVar2 < param_3);
    return 1;
}

// 0x576320 — observed shape
void FUN_00576320(int param_1, uint32_t param_2, int param_3, uint32_t param_4, float param_5, float param_6, int32_t* param_7, int32_t* param_8) {
    uint32_t uVar8;
    if (param_2 == 4) {
        uint32_t local_c[3];
        uint32_t local_24[4];
        uint32_t local_14 = 0, local_10 = 0;
        uVar8 = 0;
        do {
            uint32_t uVar5 = uVar8 & 0xff;
            uint32_t uVar1 = *(uint32_t*)(param_3 + 0x24 + uVar5 * 4);
            uint32_t uVar2 = *(uint32_t*)(param_3 + 0x18 + uVar5 * 4);
            uint32_t uVar3 = *(uint32_t*)(param_3 + 0x34 + uVar5 * 4);
            local_c[uVar8] = uVar1;
            FUN_00576320(0, uVar1, (int)uVar3, uVar2, param_5, param_6, (int32_t*)(local_c + (uVar8 - 3)), (int32_t*)(local_24 + uVar8));
            uVar8 = uVar8 + 1;
        } while (uVar8 < 3);
        uint32_t* puVar6 = (uint32_t*)thunk_FUN_00533c78(0x50);
        uint32_t* puVar9;
        if (puVar6 == (uint32_t*)0) {
            puVar9 = (uint32_t*)0;
        } else {
            puVar9 = puVar6 + 1;
            *puVar6 = 1;
            *(uint8_t*)(puVar6 + 2) = 8;
            // CRect::CRect((CRect*)(puVar6 + 3),0,0,0,0);
            *(uint8_t*)(puVar6 + 2) = 0x4c;
            puVar6[7] = 0; puVar6[8] = 0; puVar6[9] = 0;
            puVar6[0xd] = 0; puVar6[0xe] = 0; puVar6[0xf] = 0; puVar6[0x10] = 0;
            puVar6[10] = 0; puVar6[0xb] = 0; puVar6[0xc] = 0;
            puVar6[0x11] = 0; puVar6[0x12] = 0; puVar6[0x13] = 0;
        }
        *param_7 = (int32_t)(uintptr_t)puVar9;
        *param_8 = 1;
        int32_t iVar10 = *param_7;
        FUN_00569960((void*)(uintptr_t)iVar10);
        *(uint32_t*)(iVar10 + 0x18) = local_24[0];
        *(uint32_t*)(iVar10 + 0x34) = local_24[3];
        *(uint32_t*)(iVar10 + 0x24) = local_c[0];
        *(uint32_t*)(iVar10 + 0x1c) = local_24[1];
        *(uint32_t*)(iVar10 + 0x38) = local_14;
        *(uint32_t*)(iVar10 + 0x30) = 0;
        *(uint32_t*)(iVar10 + 0x20) = local_24[2];
        *(uint32_t*)(iVar10 + 0x40) = 0;
        *(uint32_t*)(iVar10 + 0x44) = 0;
        *(uint32_t*)(iVar10 + 0x48) = 0;
        *(uint32_t*)(iVar10 + 0x28) = local_c[1];
        *(uint32_t*)(iVar10 + 0x3c) = local_10;
        *(uint32_t*)(iVar10 + 0x2c) = local_c[2];
        *(uint32_t*)(iVar10 + 0x30) = *(uint32_t*)(param_3 + 0x30);
        return;
    }
    uVar8 = 0;
    *param_8 = 0;
    if (3 < (int32_t)param_4) {
        int32_t iVar10 = 2;
        do {
            int32_t iVar7 = *(uint8_t*)(param_3 + 4) * uVar8;
            if (param_5 <= *(float*)(iVar7 + param_3)) {
                if (param_6 < *(float*)(iVar7 + param_3)) goto LAB;
                *param_8 = *param_8 + 1;
            }
            iVar7 = (iVar10 + -1) * (uint32_t)*(uint8_t*)(param_3 + 4);
            if (param_5 <= *(float*)(iVar7 + param_3)) {
                if (param_6 < *(float*)(iVar7 + param_3)) goto LAB;
                *param_8 = *param_8 + 1;
            }
            iVar7 = (uint32_t)*(uint8_t*)(param_3 + 4) * iVar10;
            if (param_5 <= *(float*)(iVar7 + param_3)) {
                if (param_6 < *(float*)(iVar7 + param_3)) goto LAB;
                *param_8 = *param_8 + 1;
            }
            iVar7 = (iVar10 + 1) * (uint32_t)*(uint8_t*)(param_3 + 4);
            if (param_5 <= *(float*)(iVar7 + param_3)) {
                if (param_6 < *(float*)(iVar7 + param_3)) goto LAB;
                *param_8 = *param_8 + 1;
            }
            uVar8 = uVar8 + 4;
            iVar10 = iVar10 + 4;
        } while (uVar8 < param_4 - 3);
    }
    for (; uVar8 < param_4; uVar8 = uVar8 + 1) {
        int32_t iVar10 = *(uint8_t*)(param_3 + 4) * uVar8;
        if (param_5 <= *(float*)(iVar10 + param_3)) {
            if (param_6 < *(float*)(iVar10 + param_3)) break;
            *param_8 = *param_8 + 1;
        }
    }
LAB:
    if (*param_8 == 0) {
        *param_7 = 0;
    } else {
        int32_t iVar7 = (param_2 + param_1 * 5) * 4;
        extern uint32_t DAT_00728560[];
        extern uint32_t DAT_007285d8[];
        int32_t iVar10 = ((int32_t(*)(int32_t))DAT_00728560[iVar7])(*param_8);
        *param_7 = iVar10;
        void* pcVar4 = (void*)DAT_007285d8[iVar7];
        (void)pcVar4;
        param_2 = 0;
        *param_8 = 0;
        if (param_4 != 0) {
            do {
                iVar10 = *(uint8_t*)(param_3 + 4) * param_2;
                float* pfVar12 = (float*)(iVar10 + param_3);
                if (param_5 <= *(float*)(iVar10 + param_3)) {
                    if (param_6 < *pfVar12) {
                        return;
                    }
                    float* pfVar11 = (float*)((uint32_t)*(uint8_t*)(*param_7 + 4) * *param_8 + *param_7);
                    ((void(*)(float*, float*))pcVar4)(pfVar11, pfVar12);
                    *pfVar11 = *pfVar12 - param_5;
                    *param_8 = *param_8 + 1;
                }
                param_2 = param_2 + 1;
            } while (param_2 < param_4);
            return;
        }
    }
}

extern uint32_t DAT_00728470[];
extern void* PTR_FUN_006c4428;
extern void FUN_005383d0(void);
extern uint32_t DAT_0071778c;
extern uint32_t DAT_00717790;
extern uint32_t DAT_00717794;
extern uint32_t DAT_00717798;
extern void FUN_00552c80(void* self);
extern void FUN_00568540(void* self, uint32_t param_1);
extern uint32_t FUN_00577100(uint32_t* param_1, uint32_t* local_14);
extern void FUN_0056e040(uint32_t* out, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t* e);
extern void FUN_005664e0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

// 0x576640 — observed shape
void FUN_00576640(int param_1, int param_2, int32_t* param_3, int32_t* param_4, float param_5, uint32_t param_6) {
    if (param_2 != 4) {
        void* pcVar3 = (void*)DAT_00728470[(param_2 + param_1 * 5)];
        if ((*param_4 != 1) || (*(float*)*param_3 != param_5)) {
            ((void(*)(float, int32_t*, int32_t*))pcVar3)(param_5, param_3, param_4);
            ((void(*)(uint32_t, int32_t*, int32_t*))pcVar3)(param_6, param_3, param_4);
        }
        return;
    }
    int32_t iVar1 = *param_3;
    uint32_t uVar6 = 0;
    do {
        uint32_t uVar7 = uVar6 & 0xff;
        int32_t param_2_local = *(int32_t*)(iVar1 + 0x18 + uVar7 * 4);
        uint32_t local_4 = *(uint32_t*)(iVar1 + 0x34 + uVar7 * 4);
        uint32_t uVar2 = *(uint32_t*)(iVar1 + 0x24 + uVar7 * 4);
        if (param_2_local != 0) {
            FUN_00576640(0, (int)uVar2, (int32_t*)&local_4, &param_2_local, param_5, param_6);
        }
        uVar6 = uVar6 + 1;
        *(uint32_t*)(iVar1 + 0x34 + uVar7 * 4) = local_4;
        *(int32_t*)(iVar1 + 0x18 + uVar7 * 4) = param_2_local;
        *(uint32_t*)(iVar1 + 0x24 + uVar7 * 4) = uVar2;
        *(uint32_t*)(iVar1 + 0x40 + uVar7 * 4) = 0;
    } while (uVar6 < 3);
}

// 0x576700 — observed shape
void FUN_00576700(int param_1) {
    ((void(*)())(**(int32_t**)(param_1 + 0x15c) + 8))();
}

// 0x576720 — observed shape
void FUN_00576720(int param_1, uint32_t param_2) {
    ((void(*)(uint32_t, int))(**(int32_t**)(param_1 + 0x160) + 0xc))(param_2, 4);
}

// 0x576740 — observed shape
void FUN_00576740(uint32_t param_1) {
    FUN_00581fd0(param_1);
    FUN_00545cc0((void*)(uintptr_t)param_1);
}

// 0x576770 — observed shape
void FUN_00576770(void* self, uint8_t param_1) {
    FUN_005818f0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x576870 — observed shape
void FUN_00576870(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    uint8_t* base = (uint8_t*)self;
    if (*(int32_t*)(base + 0x50) == 0) {
        uint32_t* puVar5 = (uint32_t*)FUN_00533c78(0x18);
        if (puVar5 == (uint32_t*)0) {
            puVar5 = (uint32_t*)0;
        } else {
            FUN_005383d0();
            *puVar5 = (uint32_t)(uintptr_t)&PTR_FUN_006c4428;
            puVar5[3] = 0;
            puVar5[4] = 0;
            puVar5[5] = 0;
        }
        uint32_t* puVar2 = *(uint32_t**)(base + 0x50);
        if (puVar2 != puVar5) {
            if (puVar2 != (uint32_t*)0) {
                int32_t* piVar1 = (int32_t*)(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    ((void(*)(int))(**(uint32_t**)puVar2))(1);
                }
            }
            *(uint32_t**)(base + 0x50) = puVar5;
            if (puVar5 != (uint32_t*)0) {
                puVar5[1] = puVar5[1] + 1;
            }
        }
    }
    FUN_00581920(param_2, param_1, param_3);
    int32_t iVar3 = *(int32_t*)(base + 0x50);
    *(uint32_t*)(base + 0x18) = 0x7f7fffff;
    *(uint32_t*)(base + 0x4c) = 0;
    *(uint32_t*)(base + 0x1c) = 0xff7fffff;
    if (iVar3 != 0) {
        int32_t iVar4 = *(int32_t*)(iVar3 + 0xc);
        uint32_t* puVar5 = *(uint32_t**)(iVar3 + 0x10);
        if (iVar4 != 0) {
            *(uint32_t*)(base + 0x18) = *puVar5;
            *(uint32_t*)(base + 0x1c) = *(uint32_t*)((uint32_t)*(uint8_t*)(puVar5 + 1) * (iVar4 + -1) + (int32_t)(uintptr_t)puVar5);
        }
    }
}

// 0x5769a0 — observed shape
void FUN_005769a0(void* self, uint8_t param_1) {
    FUN_00582030(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5769c0 — observed shape
void FUN_005769c0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00552c80(self);
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x13] = 0;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c4460;
    in_ECX[0x14] = 0;
    in_ECX[0x15] = DAT_0071778c;
    in_ECX[0x16] = DAT_00717790;
    in_ECX[0x17] = DAT_00717794;
    in_ECX[0x18] = DAT_00717798;
}

// 0x576a10 — observed shape
void FUN_00576a10(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c4460;
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)in_ECX[0x14];
    if (puVar2 != (uint32_t*)0) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            ((void(*)(int))(**(uint32_t**)puVar2))(1);
        }
        in_ECX[0x14] = 0;
    }
    puVar2 = (uint32_t*)(uintptr_t)in_ECX[0x14];
    if (puVar2 != (uint32_t*)0) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            ((void(*)(int))(**(uint32_t**)puVar2))(1);
        }
    }
    FUN_00582030(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x576a70 — observed shape
void FUN_00576a70(void* self, uint32_t param_1) {
    uint8_t* base = (uint8_t*)self;
    if ((*(int32_t*)(base + 0x34) != 0) && (*(int32_t*)(base + 0x48) != 0)) {
        char cVar1 = (char)FUN_00568540(self, param_1);
        if (cVar1 == '\0') {
            uint32_t local_14 = 0;
            uint32_t uVar2 = FUN_00577100(&param_1, &local_14);
            uint32_t local_10 = 0, local_c = 0, local_8 = 0, local_4 = 0;
            FUN_0056e040(&local_10, *(uint32_t*)(base + 0x2c), uVar2, local_14, param_1, (uint32_t*)(base + 0x4c));
            FUN_005664e0(local_10, local_c, local_8, local_4);
        }
    }
}
