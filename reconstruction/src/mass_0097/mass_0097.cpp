#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005193c0(void* self);
extern void FUN_004e6420(void* self);
extern void operator_delete(void* p);

// 0x518540 — observed shape
void FUN_00518540(void* self, byte param_1) {
    FUN_005193c0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x518580 — observed shape
void FUN_00518580(int* self) {
    // *self = (int)&PTR_FUN_00711a70; vtable set
    // iterate linked list at self[1]
    void* node = *(void**)&self[1];
    while (node != nullptr) {
        void* next = *(void**)node;
        // call virtual at (*self + 8)
        // (**(code **)(*in_ECX + 8))(puVar2);
        // Represent as function pointer call through vtable
        void* vtable = *(void**)self;
        using Fn = void (*)(void*);
        Fn fn = *(Fn*)((char*)vtable + 8);
        fn(node);
        node = next;
    }
    self[3] = 0;
    self[1] = 0;
    self[2] = 0;
    // *self = (int)&PTR_LAB_00711a58; vtable set
}

// 0x5185e0 — observed shape
void FUN_005185e0(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711ac8;
    FUN_004e6420(self);
    operator_delete((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x518620 — observed shape
void FUN_00518620(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711b00;
    FUN_004e6420(self);
    // *self = &PTR_FUN_00711ac8;
    FUN_004e6420(self);
    operator_delete((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x518660 — observed shape
void FUN_00518660(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711a10;
    FUN_004e6420(self);
    operator_delete((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
// 0x5186a0 — observed shape
void FUN_005186a0(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711a30;
    FUN_004e6420(self);
    // *self = &PTR_FUN_00711a10;
    FUN_004e6420(self);
    operator_delete((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5186e0 — observed shape
void FUN_005186e0(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711a2c;
    operator_delete((void*)self[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x518750 — observed shape
void FUN_00518750(int* self) {
    // *self = (int)&PTR_FUN_007119ec;
    void* node = *(void**)&self[1];
    while (node != nullptr) {
        void* next = *(void**)node;
        void* vtable = *(void**)self;
        using Fn = void (*)(void*);
        Fn fn = *(Fn*)((char*)vtable + 8);
        fn(node);
        node = next;
    }
    self[3] = 0;
    self[1] = 0;
    self[2] = 0;
    // *self = (int)&PTR_LAB_007119a8;
}

// 0x5187d0 — observed shape
void FUN_005187d0(int* self) {
    // *self = (int)&PTR_FUN_00711aa0;
    void* node = *(void**)&self[1];
    while (node != nullptr) {
        void* next = *(void**)node;
        void* vtable = *(void**)self;
        using Fn = void (*)(void*);
        Fn fn = *(Fn*)((char*)vtable + 8);
        fn(node);
        node = next;
    }
    self[3] = 0;
    self[1] = 0;
    self[2] = 0;
    // *self = (int)&PTR_LAB_00711a7c;
}

// 0x518810 — observed shape
void FUN_00518810(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711998;
    operator_delete((void*)self[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
// 0x518880 — observed shape
void FUN_00518880(int* self) {
    // *self = (int)&PTR_FUN_00711a64;
    void* node = *(void**)&self[1];
    while (node != nullptr) {
        void* next = *(void**)node;
        void* vtable = *(void**)self;
        using Fn = void (*)(void*);
        Fn fn = *(Fn*)((char*)vtable + 8);
        fn(node);
        node = next;
    }
    self[3] = 0;
    self[1] = 0;
    self[2] = 0;
    // *self = (int)&PTR_LAB_00711a4c;
}

// 0x5188c0 — observed shape
void FUN_005188c0(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711aac;
    FUN_004e6420(self);
    operator_delete((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x518900 — observed shape
void FUN_00518900(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711ae4;
    FUN_004e6420(self);
    // *self = &PTR_FUN_00711aac;
    FUN_004e6420(self);
    operator_delete((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x518960 — observed shape
void FUN_00518960(undefined4* self, undefined4 ecx_val, undefined4 edx_val, int eax_val, undefined4 param_1, undefined4 param_2) {
    // *self = &PTR_FUN_00711fbc; unaff_ESI = self
    self[2] = 0;
    self[0x14] = 7;
    self[5] = ecx_val;
    self[6] = edx_val;
    self[0x10] = 0;
    self[0x11] = 0;
    self[0x12] = 0;
    self[1] = eax_val;
    self[9] = param_1;
    self[10] = param_2;
    self[3] = *(undefined4*)(eax_val + 0xc);
    self[4] = *(undefined4*)(eax_val + 0x10);
    self[0xb] = *(undefined4*)(eax_val + 0x6c);
    self[0xc] = *(undefined4*)(eax_val + 0x70);
    self[0xd] = *(undefined4*)(eax_val + 0x84);
    self[0xe] = *(undefined4*)(eax_val + 0x88);
    self[0xf] = *(undefined4*)(eax_val + 0x8c);
    self[7] = *(undefined4*)(eax_val + 0x7c);
    self[8] = *(undefined4*)(eax_val + 0x80);
    int iVar3 = FUN_00533c78(0xf4);
    undefined4* puVar4 = (iVar3 == 0) ? nullptr : (undefined4*)FUN_00518e30();
    undefined4* puVar2 = (undefined4*)self[2];
    if (puVar2 != puVar4) {
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Fn = void (*)(undefined4*, int);
                Fn fn = *(Fn*)*puVar2;
                fn(puVar2, 1);
            }
        }
        self[2] = (int)puVar4;
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    *(undefined4*)((char*)self[2] + 0xec) = 1;
    self[0x14] = self[9] * self[10];
}

// 0x518a40 — observed shape
uint FUN_00518a40(int* self, int param_1, char* param_2, char* param_3, undefined4* param_4, int param_5, char param_6) {
    int iVar9 = param_5 + ((*(int*)((char*)self + 0x28) + (int)param_2) * *(int*)((char*)self + 0x2c) + *(int*)((char*)self + 0x24) + param_1) * 4;
    uint local_4 = 0;
    float local_8 = 0.0f;
    char* src = nullptr;
    char cVar5 = FUN_0051bfc0(&src);
    undefined4* puVar4 = param_4;
    char* pcVar3 = param_3;
    if (cVar5 != '\0') {
        param_3[0] = src[0];
        param_3[1] = src[1];
        param_3[2] = src[2];
        param_3[3] = src[3];
        param_3[4] = src[4];
    }
    param_4[0] = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    param_4[3] = 0;
    param_4[4] = 0;
    if (*param_3 != '\0') {
        do {
            if (4 < local_4) break;
            float f = (float)FUN_0051a8d0(iVar9);
            puVar4[local_4] = (float)f;
            int iVar1 = (int)local_4 + 1;
            local_4 = local_4 + 1;
            local_8 = f + local_8;
            if (pcVar3[iVar1] == '\0') break;
        } while (true);
    }
    if (param_6 != '\0') {
        uint uVar7 = 0;
        if (3 < (int)local_4) {
            float fVar2 = 1.0f / local_8;
            int iVar9b = ((int)local_4 - 4 >> 2) + 1;
            uVar7 = iVar9b * 4;
            float* pfVar6 = (float*)(puVar4 + 2);
            do {
                iVar9b = iVar9b + -1;
                pfVar6[-2] = fVar2 * pfVar6[-2];
                pfVar6[-1] = fVar2 * pfVar6[-1];
                *pfVar6 = fVar2 * *pfVar6;
                pfVar6[1] = fVar2 * pfVar6[1];
                pfVar6 = pfVar6 + 4;
            } while (iVar9b != 0);
        }
        if (uVar7 < local_4) {
            do {
                uint uVar8 = uVar7 + 1;
                puVar4[uVar7] = (1.0f / local_8) * (float)puVar4[uVar7];
                uVar7 = uVar8;
            } while (uVar8 < local_4);
        }
    }
    return local_4;
}
// 0x518c20 — observed shape
int FUN_00518c20(int* self) {
    int iVar4 = *(int*)((char*)self + 8);
    int iVar5 = 0;
    uint uVar6 = 0;
    if (*(int*)(iVar4 + 0xc0) != 0) {
        do {
            int* piVar1 = *(int**)(*(int*)(iVar4 + 0xb8) + uVar6 * 4);
            if (piVar1 != nullptr) {
                using GetFn = undefined4* (*)(void*);
                GetFn getFn = *(GetFn*)((char*)*(void**)piVar1 + 4);
                for (undefined4* puVar2 = getFn(piVar1); puVar2 != nullptr; puVar2 = (undefined4*)puVar2[1]) {
                    if (puVar2 == &DAT_00727598) {
                        int iVar3 = FUN_00533db0(8);
                        int iVar4b = 0;
                        if (*(int*)(iVar3 + 0x44) != 0) {
                            iVar4b = *(int*)(*(int*)(iVar3 + 0x44) + 0x10);
                        }
                        iVar5 = iVar5 + iVar4b;
                        break;
                    }
                }
            }
            iVar4 = *(int*)((char*)self + 8);
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint*)(iVar4 + 0xc0));
    }
    return iVar5;
}

// 0x518c90 — observed shape
uint FUN_00518c90(int* self, int edx_val, int param_1) {
    int iVar1 = self[9] + edx_val;
    int p1 = self[10] + param_1;
    if (iVar1 < 0) {
        iVar1 = 0;
    } else if (self[0xb] + -1 < iVar1) {
        iVar1 = self[0xb] + -1;
    }
    if (p1 < 0) {
        p1 = 0;
    } else if (self[0xc] + -1 < p1) {
        p1 = self[0xc] + -1;
    }
    if (self[0x11] == 0) {
        undefined1 local_8[8];
        using Fn = void (*)(int*, int, int, undefined1*, int);
        Fn fn = *(Fn*)((char*)*(void**)self + 0x10);
        fn(self, iVar1, p1, local_8, self[0x12]);
        return (uint)local_8[0];
    }
    return (uint)*(byte*)(self[0xb] * p1 + self[0x11] + iVar1);
}

// 0x518d30 — observed shape
void FUN_00518d30(void) {
    if (DAT_008cad3c != nullptr) {
        uint uVar2 = 0;
        int* piVar5 = DAT_008cad3c;
        int* piVar6 = nullptr;
        if (DAT_008cad3c[1] != 0) {
            piVar6 = (int*)DAT_008cad3c[2];
            do {
                if (*piVar6 != 0) {
                    piVar6 = (int*)((int*)DAT_008cad3c[2])[uVar2];
                    goto joined;
                }
                uVar2 = uVar2 + 1;
                piVar6 = piVar6 + 1;
            } while (uVar2 < (uint)DAT_008cad3c[1]);
        }
        piVar6 = nullptr;
joined:
        while (piVar6 != nullptr) {
            int* piVar7 = (int*)*piVar6;
            undefined4* puVar1 = (undefined4*)piVar6[2];
            if (piVar7 == nullptr) {
                using GetFn = int (*)(int*, int);
                GetFn getFn = *(GetFn*)((char*)*(void**)piVar5 + 4);
                int iVar3 = getFn(piVar5, piVar6[1]);
                uVar2 = iVar3 + 1;
                if (uVar2 < (uint)piVar5[1]) {
                    undefined4* puVar4 = (undefined4*)(piVar5[2] + uVar2 * 4);
                    do {
                        piVar7 = (int*)*puVar4;
                        if (piVar7 != nullptr) break;
                        uVar2 = uVar2 + 1;
                        puVar4 = puVar4 + 1;
                    } while (uVar2 < (uint)piVar5[1]);
                    if (uVar2 >= (uint)piVar5[1]) piVar7 = nullptr;
                } else {
                    piVar7 = nullptr;
                }
                piVar5 = DAT_008cad3c;
            }
            piVar6 = piVar7;
            if (puVar1 != nullptr) {
                using DelFn = void (*)(undefined4*, int);
                DelFn delFn = *(DelFn*)*puVar1;
                delFn(puVar1, 1);
                piVar5 = DAT_008cad3c;
            }
        }
        FUN_004e6420(DAT_008cad3c);
        if (DAT_008cad3c != nullptr) {
            using DelFn = void (*)(int*, int);
            DelFn delFn = *(DelFn*)*DAT_008cad3c;
            delFn(DAT_008cad3c, 1);
            DAT_008cad3c = nullptr;
        }
    }
    FUN_005254f0();
    if (DAT_008cad50 != nullptr) {
        operator_delete(DAT_008cad50);
        DAT_008cad50 = nullptr;
    }
    undefined4* puVar1b = DAT_008ea524;
    if (DAT_008ea524 != nullptr) {
        int iVar3b = DAT_008ea524[1];
        DAT_008ea524[1] = iVar3b + -1;
        if (iVar3b + -1 == 0) {
            using DelFn = void (*)(undefined4*, int);
            DelFn delFn = *(DelFn*)*puVar1b;
            delFn(puVar1b, 1);
        }
        DAT_008ea524 = nullptr;
    }
    DAT_008cad54 = 0;
}

// 0x518e30 — observed shape
void FUN_00518e30(undefined4* self) {
    FUN_0053bb30(0);
    // *self = &PTR_FUN_00711f38;
    self[0x3c] = 0;
    self[0x3b] = 0;
    undefined4* puVar2 = (undefined4*)self[0x3c];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DelFn = void (*)(undefined4*, int);
            DelFn delFn = *(DelFn*)*puVar2;
            delFn(puVar2, 1);
        }
        self[0x3c] = 0;
    }
}

// 0x518e80 — observed shape
void FUN_00518e80(undefined4* self, byte param_1) {
    // *self = &PTR_FUN_00711f38;
    undefined4* puVar2 = (undefined4*)self[0x3c];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DelFn = void (*)(undefined4*, int);
            DelFn delFn = *(DelFn*)*puVar2;
            delFn(puVar2, 1);
        }
    }
    FUN_0053c1d0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
