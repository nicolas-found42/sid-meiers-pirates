#include <cstdint>
#include <cstddef>

// Extern helpers referenced by the assigned corpus listings.
extern void* ExceptionList;
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern uint32_t FUN_006b5090(uint32_t param_1, void* param_2);
extern uint32_t FUN_006b5020(uint32_t param_1, void* param_2);
extern void* FUN_00533c78(uint32_t size);
extern void FUN_005edba0(void);
extern char FUN_006b4f80(uint32_t param_1, uint32_t param_2);
extern char FUN_006b4fe0(uint32_t param_1, uint32_t param_2);
extern char FUN_005c9c40(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern char FUN_005c9c80(uint32_t param_1, void* param_2);
extern void* PTR_FUN_006c9e74;
extern void* PTR_LAB_006c9e68;
extern void* PTR_FUN_006c9e8c;
extern void* PTR_FUN_006c9e90;
extern void* PTR_FUN_006c9eb4;
extern void* PTR_LAB_006c9e80;
extern void* PTR_LAB_006fd148;
extern int DAT_00727444;
extern int DAT_007187cc;
extern char LAB_006b9ba3;
extern char LAB_006b9bbb;
extern char LAB_006b9bd8;
extern char LAB_006b9c44;

// 0x5ea3b0 — observed shape
// Self is passed in ECX; self[0] is a pointer to a node whose [0] is the
// next pointer and whose [2] is the value returned. When the node pointer
// is non-null, self[0] advances to *node and node[2] is returned.
uint32_t FUN_5ea3b0(void* self) {
    int* piVar1 = (int*)*(int**)self;
    uint32_t uVar2 = 0;
    if (piVar1 != (int*)0x0) {
        *(int**)self = (int*)*piVar1;
        uVar2 = (uint32_t)piVar1[2];
    }
    return uVar2;
}

// 0x5ea3c0 — observed shape
// Destructor-like cleanup: self[2] is the starting count/pointer; self[0] is
// the list head. Walks the list, freeing each payload via operator_delete__ /
// operator_delete. Then resets vtable slots self[1] to PTR_FUN_006c9e74 and
// finally PTR_LAB_006c9e68 after FUN_005edba0() calls.
void FUN_5ea3c0(void* self) {
    int iVar1;
    int* piVar2;
    void* pvVar3;
    void* local_c;
    void* puStack_8 = (void*)0x0;
    int local_4 = 0;
    puStack_8 = &LAB_006b9ba3;
    local_c = ExceptionList;
    ExceptionList = (void*)&local_c;
    iVar1 = ((int*)self)[2];
    *(int*)self = iVar1;
    while (iVar1 != 0) {
        piVar2 = (int*)*(int**)self;
        *(int**)self = (int*)*piVar2;
        pvVar3 = (void*)piVar2[2];
        if (pvVar3 != (void*)0x0) {
            operator_delete__(*(void**)((intptr_t)pvVar3 + 0xc));
            operator_delete(pvVar3);
        }
        iVar1 = *(int*)self;
    }
    FUN_005edba0();
    ((int*)self)[1] = (int)(intptr_t)&PTR_FUN_006c9e74;
    local_4 = 1;
    FUN_005edba0();
    ((int*)self)[1] = (int)(intptr_t)&PTR_LAB_006c9e68;
    ExceptionList = local_c;
    return;
}

// 0x5ea450 — observed shape
// Reads count via FUN_006b5090(param_1,&local_4). If count nonzero, loop
// allocating 16-byte nodes via FUN_00533c78, filling node[0..3] through
// FUN_006b5090 / FUN_006b5020, then a factory call through *(self+4) vtable,
// then appends to doubly-linked list at self+8/self+0xc and bumps self+0x10.
// Returns bool true in low byte on success, f&0xffffff00 on read failure.
uint32_t FUN_5ea450(void* self, uint32_t param_1) {
    uint32_t uVar2 = 0;
    uint32_t local_4 = (uint32_t)(intptr_t)self;
    // First call: in_ECX (self) is read for the count out-param.
    uVar2 = FUN_006b5090(param_1, &local_4);
    if ((char)uVar2 == '\0') {
        return uVar2;
    }
    uint32_t count = local_4;
    uint32_t index = 0;
    if (count != 0) {
        do {
            uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0x10);
            uint32_t* puVar4 = (uint32_t*)0x0;
            if (puVar3 != (uint32_t*)0x0) {
                puVar3[0] = 0;
                puVar3[3] = 0;
                puVar3[1] = 0xffffffff;
                puVar3[2] = 0xffffffff;
                puVar4 = puVar3;
            }
            uVar2 = FUN_006b5090(index, puVar4);
            if ((char)uVar2 == '\0') return uVar2 & 0xffffff00;
            uVar2 = FUN_006b5090(index, puVar4 + 1);
            if ((char)uVar2 == '\0') return uVar2 & 0xffffff00;
            uVar2 = FUN_006b5090(index, puVar4 + 2);
            if ((char)uVar2 == '\0') return uVar2 & 0xffffff00;
            uVar2 = FUN_006b5020(index, puVar4 + 3);
            if ((char)uVar2 == '\0') return uVar2 & 0xffffff00;
            uint32_t vtable = *(uint32_t*)((uint8_t*)self + 4);
            uint32_t* puVar = (uint32_t*)(**(uint32_t*(**)())(vtable + 4))();
            puVar[2] = (uint32_t)(intptr_t)puVar4;
            puVar[0] = 0;
            puVar[1] = *(uint32_t*)((uint8_t*)self + 0xc);
            if (*(uint32_t**)((uint8_t*)self + 0xc) == (uint32_t*)0x0) {
                *(uint32_t**)((uint8_t*)self + 8) = puVar;
            } else {
                **(uint32_t***)((uint8_t*)self + 0xc) = puVar;
            }
            *(uint32_t**)((uint8_t*)self + 0xc) = puVar;
            index = param_1 + 1;
            if (*(int*)((uint8_t*)self + 0x10) >= 0) {
                *(int*)((uint8_t*)self + 0x10) = *(int*)((uint8_t*)self + 0x10) + 1;
            }
            param_1 = index;
        } while (index < count);
    }
    return (uVar2 & 0xffffff00) | 1;
}

// 0x5ea550 — observed shape
// Constructor: zeroes self+0x10, self+8, self+0xc; sets *(self+4) vtable to
// PTR_FUN_006c9e74; calls FUN_005edba0().
void FUN_5ea550(void* self) {
    void* local_c;
    void* puStack_8 = (void*)0x0;
    int local_4 = 0;
    puStack_8 = &LAB_006b9bbb;
    local_c = ExceptionList;
    ExceptionList = (void*)&local_c;
    *(uint32_t*)((uint8_t*)self + 0x10) = 0;
    *(uint32_t*)((uint8_t*)self + 8) = 0;
    *(uint32_t*)((uint8_t*)self + 0xc) = 0;
    *(void**)((uint8_t*)self + 4) = (void*)&PTR_FUN_006c9e74;
    local_4 = 0;
    FUN_005edba0();
    ExceptionList = local_c;
    return;
}

// 0x5ea5a0 — observed shape
// Chain of FUN_006b4f80 / FUN_006b4fe0 on successive self offsets +8..+0x28,
// ending with FUN_005c9c40(param_1, self+0x2c, self+0x24). Returns true only
// if every check is nonzero.
bool FUN_5ea5a0(void* self, uint32_t param_1) {
    char cVar1;
    cVar1 = FUN_006b4f80(param_1, *(uint32_t*)((uint8_t*)self + 8));
    if (cVar1 != '\0') {
        cVar1 = FUN_006b4fe0(param_1, *(uint32_t*)((uint8_t*)self + 0x10));
        if (cVar1 != '\0') {
            cVar1 = FUN_006b4fe0(param_1, *(uint32_t*)((uint8_t*)self + 0x14));
            if (cVar1 != '\0') {
                cVar1 = FUN_006b4fe0(param_1, *(uint32_t*)((uint8_t*)self + 0x18));
                if (cVar1 != '\0') {
                    cVar1 = FUN_006b4fe0(param_1, *(uint32_t*)((uint8_t*)self + 0x1c));
                    if (cVar1 != '\0') {
                        cVar1 = FUN_006b4f80(param_1, *(uint32_t*)((uint8_t*)self + 0x20));
                        if (cVar1 != '\0') {
                            cVar1 = FUN_006b4fe0(param_1, *(uint32_t*)((uint8_t*)self + 0x24));
                            if (cVar1 != '\0') {
                                cVar1 = FUN_006b4fe0(param_1, *(uint32_t*)((uint8_t*)self + 0x28));
                                if (cVar1 != '\0') {
                                    cVar1 = FUN_005c9c40(param_1,
                                                         *(uint32_t*)((uint8_t*)self + 0x2c),
                                                         *(uint32_t*)((uint8_t*)self + 0x24));
                                    return cVar1 != '\0';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
// 0x5ea660 — observed shape
// Returns false if FUN_006b4fe0(param_1,self[2]) is zero; otherwise calls
// vtable[0x1c](param_1) and returns low byte as bool.
bool FUN_5ea660(void* self, uint32_t param_1) {
    char cVar1 = FUN_006b4fe0(param_1, ((int*)self)[2]);
    if (cVar1 == '\0') return false;
    cVar1 = (**(char(**)(uint32_t))(*(int*)self + 0x1c))(param_1);
    return cVar1 != '\0';
}

// 0x5ea690 — observed shape
// Returns false if FUN_006b5090(param_1,self+2) is zero; otherwise calls
// vtable[0x20](param_1) and returns low byte as bool.
bool FUN_5ea690(void* self, uint32_t param_1) {
    char cVar1 = (char)FUN_006b5090(param_1, (void*)((int*)self + 2));
    if (cVar1 == '\0') return false;
    cVar1 = (**(char(**)(uint32_t))(*(int*)self + 0x20))(param_1);
    return cVar1 != '\0';
}

// 0x5ea6c0 — observed shape
// Vtable setter: *self = &PTR_LAB_006c9e80.
void FUN_5ea6c0(void* self) {
    *(void**)self = (void*)&PTR_LAB_006c9e80;
    return;
}

// 0x5ea6f0 — observed shape
// Scalar deleting-destructor shape: calls FUN_5ea820() on self, then if the
// low bit of param_1 is set, frees self via operator_delete.
void FUN_5ea6f0(void* self, unsigned char param_1) {
    FUN_5ea820(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x5ea710 — observed shape
// Destructor with mass-delete slots: sets vtable to PTR_FUN_006c9e8c, frees
// self[2] and self[8] (index 8 = offset 0x20), conditionally frees self[0xb]
// if the byte at self+0x30 (index 0xc) is nonzero, restores vtable to
// PTR_LAB_006fd148, decrements DAT_00727444.
void FUN_5ea710(void* self) {
    int* in_ECX = (int*)self;
    *in_ECX = (int)(intptr_t)&PTR_FUN_006c9e8c;
    operator_delete__((void*)in_ECX[2]);
    operator_delete__((void*)in_ECX[8]);
    if (*(char*)((uint8_t*)self + 0x30) != '\0') {
        operator_delete__((void*)in_ECX[0xb]);
    }
    *in_ECX = (int)(intptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
    return;
}
// 0x5ea750 — observed shape
// Read chain: FUN_006b5020(self+8), FUN_006b5090(self+0x10..0x1c); then if
// DAT_007187cc != 0x10001 requires FUN_006b5020(self+0x20) nonzero; then
// FUN_006b5090(self+0x24), FUN_006b5090(self+0x28), FUN_005c9c80(self+0x2c).
// On full success sets byte at self+0x30 to 1 and returns 1 else 0.
uint32_t FUN_5ea750(void* self, uint32_t param_1) {
    char cVar1;
    cVar1 = (char)FUN_006b5020(param_1, (void*)((uint8_t*)self + 8));
    if ((cVar1 != '\0') &&
        ((cVar1 = (char)FUN_006b5090(param_1, (void*)((uint8_t*)self + 0x10)), cVar1 != '\0') &&
         (cVar1 = (char)FUN_006b5090(param_1, (void*)((uint8_t*)self + 0x14)), cVar1 != '\0') &&
         (cVar1 = (char)FUN_006b5090(param_1, (void*)((uint8_t*)self + 0x18)), cVar1 != '\0') &&
         (cVar1 = (char)FUN_006b5090(param_1, (void*)((uint8_t*)self + 0x1c)), cVar1 != '\0'))) {
        if ((DAT_007187cc != 0x10001) && (cVar1 = (char)FUN_006b5020(param_1, (void*)((uint8_t*)self + 0x20)), cVar1 == '\0')) {
            return 0;
        }
        cVar1 = (char)FUN_006b5090(param_1, (void*)((uint8_t*)self + 0x24));
        if (((cVar1 != '\0') && (cVar1 = (char)FUN_006b5090(param_1, (void*)((uint8_t*)self + 0x28)), cVar1 != '\0')) &&
            (cVar1 = FUN_005c9c80(param_1, (void*)((uint8_t*)self + 0x2c)), cVar1 != '\0')) {
            *(unsigned char*)((uint8_t*)self + 0x30) = 1;
            return 1;
        }
    }
    return 0;
}

// 0x5ea820 — observed shape
// Vtable bounce: *self = PTR_FUN_006c9eb4; FUN_005edba0(); *self = PTR_LAB_006c9e80.
void FUN_5ea820(void* self) {
    void* local_c;
    void* puStack_8 = (void*)0x0;
    int local_4 = 0;
    puStack_8 = &LAB_006b9bd8;
    local_c = ExceptionList;
    ExceptionList = (void*)&local_c;
    *(void**)self = (void*)&PTR_FUN_006c9eb4;
    local_4 = 0;
    FUN_005edba0();
    *(void**)self = (void*)&PTR_LAB_006c9e80;
    ExceptionList = local_c;
    return;
}

// 0x5ea870 — observed shape
// Destructor walking four sublists at self+0xc/0x14, self+0x20/0x28,
// self+0x34/0x3c, self+0x48/0x50. Each node with non-null [2] gets its
// vtable[0] called with arg 1. Between/after sweeps, vtable bounces
// through PTR_FUN_006c9eb4 / PTR_LAB_006c9e80 and FUN_005edba0() runs.
// Ends with *self = PTR_LAB_006fd148; DAT_00727444--.
void FUN_5ea870(void* self) {
    int* in_ECX = (int*)self;
    void* pvStack_c = (void*)0x0;
    void* puStack_8 = (void*)0x0;
    int local_4 = 0;
    pvStack_c = ExceptionList;
    puStack_8 = &LAB_006b9c44;
    ExceptionList = (void*)&pvStack_c;
    *(void**)self = (void*)&PTR_FUN_006c9e90;
    int iVar1 = in_ECX[5];
    local_4 = 4;
    in_ECX[3] = iVar1;
    while (iVar1 != 0) {
        uint32_t* puVar2 = (uint32_t*)in_ECX[3];
        in_ECX[3] = (int)puVar2[0];
        puVar2 = (uint32_t*)puVar2[2];
        if (puVar2 != (uint32_t*)0x0) {
            (**(void(**)(int))puVar2)(1);
        }
        iVar1 = in_ECX[3];
    }
    FUN_005edba0();
    iVar1 = in_ECX[10];
    in_ECX[8] = iVar1;
    while (iVar1 != 0) {
        uint32_t* puVar2 = (uint32_t*)in_ECX[8];
        in_ECX[8] = (int)puVar2[0];
        puVar2 = (uint32_t*)puVar2[2];
        if (puVar2 != (uint32_t*)0x0) {
            (**(void(**)(int))puVar2)(1);
        }
        iVar1 = in_ECX[8];
    }
    FUN_005edba0();
    iVar1 = in_ECX[0xf];
    in_ECX[0xd] = iVar1;
    while (iVar1 != 0) {
        uint32_t* puVar2 = (uint32_t*)in_ECX[0xd];
        in_ECX[0xd] = (int)puVar2[0];
        puVar2 = (uint32_t*)puVar2[2];
        if (puVar2 != (uint32_t*)0x0) {
            (**(void(**)(int))puVar2)(1);
        }
        iVar1 = in_ECX[0xd];
    }
    FUN_005edba0();
    iVar1 = in_ECX[0x14];
    in_ECX[0x12] = iVar1;
    while (iVar1 != 0) {
        uint32_t* puVar2 = (uint32_t*)in_ECX[0x12];
        in_ECX[0x12] = (int)puVar2[0];
        puVar2 = (uint32_t*)puVar2[2];
        if (puVar2 != (uint32_t*)0x0) {
            (**(void(**)(int))puVar2)(1);
        }
        iVar1 = in_ECX[0x12];
    }
    FUN_005edba0();
    in_ECX[0x13] = (int)(intptr_t)&PTR_FUN_006c9eb4;
    FUN_005edba0();
    in_ECX[0x13] = (int)(intptr_t)&PTR_LAB_006c9e80;
    in_ECX[0xe] = (int)(intptr_t)&PTR_FUN_006c9eb4;
    FUN_005edba0();
    in_ECX[0xe] = (int)(intptr_t)&PTR_LAB_006c9e80;
    in_ECX[9] = (int)(intptr_t)&PTR_FUN_006c9eb4;
    FUN_005edba0();
    in_ECX[9] = (int)(intptr_t)&PTR_LAB_006c9e80;
    in_ECX[4] = (int)(intptr_t)&PTR_FUN_006c9eb4;
    FUN_005edba0();
    in_ECX[4] = (int)(intptr_t)&PTR_LAB_006c9e80;
    *in_ECX = (int)(intptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
    ExceptionList = pvStack_c;
    return;
}

// 0x5eaa10 — observed shape
// List search: walks self+0x14 -> self+0xc chain; for each node, compares
// node[2]+8 string pointer against param_1 with strcmp semantics (2 bytes
// at a time). Returns matching node index (puVar3[2]) or 0 when exhausted.
int FUN_5eaa10(void* self, unsigned char* param_1) {
    int iVar2 = *(int*)((uint8_t*)self + 0x14);
    *(int*)((uint8_t*)self + 0xc) = iVar2;
    do {
        if (iVar2 == 0) return 0;
        uint32_t* puVar3 = *(uint32_t**)((uint8_t*)self + 0xc);
        *(uint32_t**)((uint8_t*)self + 0xc) = (uint32_t*)puVar3[0];
        iVar2 = (int)puVar3[2];
        if (iVar2 != 0) {
            unsigned char* pbVar4 = *(unsigned char**)(iVar2 + 8);
            unsigned char* pbVar6 = param_1;
            int iVar5;
            for (;;) {
                unsigned char bVar1 = *pbVar4;
                bool bVar7 = bVar1 < *pbVar6;
                if (bVar1 != *pbVar6) {
                    iVar5 = (1 - (unsigned)bVar7) - (unsigned)(bVar7 != 0);
                    break;
                }
                if (bVar1 == 0) { iVar5 = 0; break; }
                bVar1 = pbVar4[1];
                bVar7 = bVar1 < pbVar6[1];
                if (bVar1 != pbVar6[1]) {
                    iVar5 = (1 - (unsigned)bVar7) - (unsigned)(bVar7 != 0);
                    break;
                }
                pbVar4 = pbVar4 + 2;
                pbVar6 = pbVar6 + 2;
                if (bVar1 == 0) { iVar5 = 0; break; }
            }
            if (iVar5 == 0) return iVar2;
        }
        iVar2 = *(int*)((uint8_t*)self + 0xc);
    } while (true);
}

// 0x5eaa80 — observed shape
// Selector over three lists: param_1==1 -> self+0x20/self+0x28,
// param_1==2 -> self+0x34/self+0x?? (iVar3 = in_ECX+0x38), param_1==4 ->
// self+0x48/self+0x4c. Otherwise returns 0. Reads *(iVar3+4) into *piVar7
// and walks it with the same strcmp search returning matching node index.
int FUN_5eaa80(void* self, int param_1, unsigned char* param_2) {
    int* piVar7;
    int iVar3;
    if (param_1 == 1) {
        piVar7 = (int*)((uint8_t*)self + 0x20);
        iVar3 = (int)(intptr_t)self + 0x24;
    } else if (param_1 == 2) {
        piVar7 = (int*)((uint8_t*)self + 0x34);
        iVar3 = (int)(intptr_t)self + 0x38;
    } else {
        if (param_1 != 4) return 0;
        piVar7 = (int*)((uint8_t*)self + 0x48);
        iVar3 = (int)(intptr_t)self + 0x4c;
    }
    if ((piVar7 == (int*)0x0) || (iVar3 == 0)) return 0;
    iVar3 = *(int*)(iVar3 + 4);
    *piVar7 = iVar3;
    do {
        if (iVar3 == 0) return 0;
        int* piVar2 = (int*)*piVar7;
        *piVar7 = *piVar2;
        iVar3 = piVar2[2];
        if (iVar3 != 0) {
            unsigned char* pbVar4 = *(unsigned char**)(iVar3 + 8);
            unsigned char* pbVar6 = param_2;
            int iVar5;
            for (;;) {
                unsigned char bVar1 = *pbVar4;
                bool bVar8 = bVar1 < *pbVar6;
                if (bVar1 != *pbVar6) {
                    iVar5 = (1 - (unsigned)bVar8) - (unsigned)(bVar8 != 0);
                    break;
                }
                if (bVar1 == 0) { iVar5 = 0; break; }
                bVar1 = pbVar4[1];
                bVar8 = bVar1 < pbVar6[1];
                if (bVar1 != pbVar6[1]) {
                    iVar5 = (1 - (unsigned)bVar8) - (unsigned)(bVar8 != 0);
                    break;
                }
                pbVar4 = pbVar4 + 2;
                pbVar6 = pbVar6 + 2;
                if (bVar1 == 0) { iVar5 = 0; break; }
            }
            if (iVar5 == 0) return iVar3;
        }
        iVar3 = *piVar7;
    } while (true);
}

extern void FUN_005defc0(void* self);
extern void FUN_005df010(void* self, uint32_t param_1);
extern void FUN_005df0b0(void* self, uint32_t param_6);
extern void FUN_005df140(void* self, uint32_t param_7, uint32_t param_8, uint32_t param_9, uint32_t param_10);
extern uint32_t FUN_005dbe20(void);
extern uint32_t FUN_005de0c0(uint32_t uVar3);
extern void FUN_005be160(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern void FUN_00547720(void);
extern int FUN_005bdd30(uint32_t a);
extern void FUN_006b36a0(uint32_t a);
extern void FUN_006b3c30(void* a);
extern void FUN_006b3c50(void* a);
extern void FUN_006b3c70(void* a);
extern void FUN_006b3c90(void* a);
extern void FUN_006b3cb0(void* a);
extern char LAB_006b9c5b;

// 0x5eab20 — observed shape
// Factory: allocates 0x34 bytes via FUN_00533c78, default-constructs via
// FUN_005defc0, installs vtable PTR_FUN_006c9e8c, then assigns fields
// [4],[5],[7],[6] from params 2..5 and forwards params 6 and 7..10 to
// FUN_005df0b0 / FUN_005df140. Returns the object (or null).
uint32_t* FUN_5eab20(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                     uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8,
                     uint32_t param_9, uint32_t param_10) {
    uint32_t* puVar1;
    void* local_c;
    void* puStack_8 = (void*)0x0;
    int local_4 = -1;
    puStack_8 = &LAB_006b9c5b;
    local_c = ExceptionList;
    ExceptionList = (void*)&local_c;
    puVar1 = (uint32_t*)FUN_00533c78(0x34);
    local_4 = 0;
    if (puVar1 == (uint32_t*)0x0) {
        puVar1 = (uint32_t*)0x0;
    } else {
        FUN_005defc0(puVar1);
        *(void**)puVar1 = (void*)&PTR_FUN_006c9e8c;
    }
    local_4 = -1;
    if (puVar1 != (uint32_t*)0x0) {
        FUN_005df010(puVar1, param_1);
        puVar1[4] = param_2;
        puVar1[5] = param_3;
        puVar1[7] = param_5;
        puVar1[6] = param_4;
        FUN_005df0b0(puVar1, param_6);
        FUN_005df140(puVar1, param_7, param_8, param_9, param_10);
    }
    ExceptionList = local_c;
    return puVar1;
}

// 0x5eabe0 — observed shape
// Validates (param_1, param_3, param_4) non-null; dispatches on the top
// nibble of *(param_3+0x10): 0x4.... uses FUN_005de0c0 / FUN_005be160 /
// FUN_00547720 / FUN_005bdd30 path; anything other than 0x3.... uses the
// generic vtable[1] call with offsets 8,0x10,0x14,0x18,0x1c,0x20,0x24,
// 0x28,0x2c; 0x3.... decodes the value via FUN_005dbe20 and switches on the
// tag (1..5/b observed) filling a local buffer before the same vtable[1]
// call. Returns (call result == 0).
bool FUN_5eabe0(int param_1, uint32_t param_2, int param_3, int* param_4) {
    if (((param_1 == 0) || (param_3 == 0)) || (param_4 == (int*)0x0)) {
        return false;
    }
    uint32_t uVar3 = *(uint32_t*)(param_3 + 0x10);
    int iVar5;
    uint32_t uVar6;
    char local_85;
    char* local_8c;
    char* local_70;
    uint32_t local_80, local_7c, local_6c, local_64, local_60;
    if ((uVar3 & 0xf0000000) == 0x40000000) {
        uint32_t uVar4 = FUN_005de0c0(uVar3);
        FUN_005be160(*(uint32_t*)(param_3 + 8), uVar4,
                     *(uint32_t*)(param_3 + 0x24), *(uint32_t*)(param_3 + 0x2c));
        FUN_00547720();
        iVar5 = FUN_005bdd30(*(uint32_t*)(param_3 + 8));
        char* local_84 = *(char**)(param_3 + 0x18);
        iVar5 = (**(int(**)(uint32_t, uint32_t, int, char*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int))(*(int*)param_4 + 4))(
            *(uint32_t*)(param_3 + 8), *(uint32_t*)(param_3 + 0x10), 0, local_84,
            *(uint32_t*)(param_3 + 0x1c), *(uint32_t*)(param_3 + 0x20),
            *(uint32_t*)(param_3 + 0x24), *(uint32_t*)(param_3 + 0x24),
            *(uint32_t*)(iVar5 + 0x14), 0);
        return iVar5 == 0;
    }
    if ((uVar3 & 0xf0000000) != 0x30000000) {
        uint32_t local_70v = *(uint32_t*)(param_3 + 0x18);
        uint32_t local_6cv = *(uint32_t*)(param_3 + 8);
        iVar5 = (**(int(**)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int))(*(int*)param_4 + 4))(
            local_6cv, uVar3, *(uint32_t*)(param_3 + 0x14), local_70v,
            *(uint32_t*)(param_3 + 0x1c), *(uint32_t*)(param_3 + 0x20),
            *(uint32_t*)(param_3 + 0x24), *(uint32_t*)(param_3 + 0x28),
            *(uint32_t*)(param_3 + 0x2c), 0);
        return iVar5 == 0;
    }
    FUN_006b36a0(*(uint32_t*)(param_3 + 8));
    local_8c = (char*)&local_64;
    uVar6 = 4;
    uint32_t uVar4 = FUN_005dbe20();
    switch (uVar4) {
    case 1:
        FUN_006b3c30(&local_85);
        local_8c = &local_85;
        iVar5 = 1;
        uVar6 = 1;
        break;
    case 2:
    case 0xb:
        FUN_006b3c50(&local_70);
        local_8c = local_70;
        iVar5 = (local_70 != (char*)0x0 && *local_70 != '\0') ? 1 : 0;
        uVar6 = 1;
        break;
    case 3:
        FUN_006b3c70(&local_6c);
        local_8c = (char*)&local_6c;
        iVar5 = 4;
        uVar6 = 4;
        break;
    case 4:
        FUN_006b3c90(&local_64);
        iVar5 = 4;
        break;
    case 5:
        FUN_006b3cb0(&local_80);
        local_60 = local_7c;
        local_64 = local_80;
        iVar5 = 8;
        break;
    default:
        break;
    }
    uint32_t local_68 = *(uint32_t*)(param_3 + 0x18);
    uint32_t local_80v = *(uint32_t*)(param_3 + 8);
    iVar5 = (**(int(**)(uint32_t, uint32_t, int, uint32_t, uint32_t, uint32_t, int, uint32_t, char*, int))(*(int*)param_4 + 4))(
        local_80v, *(uint32_t*)(param_3 + 0x10), 0, local_68,
        *(uint32_t*)(param_3 + 0x1c), *(uint32_t*)(param_3 + 0x20), iVar5, uVar6,
        local_8c, 1);
    return iVar5 == 0;
}

// 0x5eafa0 — observed shape
// Same dispatcher as 0x5eabe0 but the generic branch passes offset 0x14 as
// the third argument and 0x18 as the fourth. Returns (call result == 0).
bool FUN_5eafa0(int param_1, uint32_t param_2, int param_3, int* param_4) {
    if (((param_1 == 0) || (param_3 == 0)) || (param_4 == (int*)0x0)) {
        return false;
    }
    uint32_t uVar3 = *(uint32_t*)(param_3 + 0x10);
    int iVar5;
    uint32_t uVar6;
    char local_89;
    char* local_90;
    char* local_74;
    uint32_t local_84, local_80, local_7c, local_6c, local_64, local_60;
    if ((uVar3 & 0xf0000000) == 0x40000000) {
        uint32_t uVar4 = FUN_005de0c0(uVar3);
        FUN_005be160(*(uint32_t*)(param_3 + 8), uVar4,
                     *(uint32_t*)(param_3 + 0x24), *(uint32_t*)(param_3 + 0x2c));
        FUN_00547720();
        iVar5 = FUN_005bdd30(*(uint32_t*)(param_3 + 8));
        iVar5 = (**(int(**)(uint32_t, uint32_t, int, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int))(*(int*)param_4 + 4))(
            *(uint32_t*)(param_3 + 8), *(uint32_t*)(param_3 + 0x10), 0,
            *(uint32_t*)(param_3 + 0x18), *(uint32_t*)(param_3 + 0x1c),
            *(uint32_t*)(param_3 + 0x20), *(uint32_t*)(param_3 + 0x24),
            *(uint32_t*)(param_3 + 0x24), *(uint32_t*)(iVar5 + 0x14), 0);
        return iVar5 == 0;
    }
    if ((uVar3 & 0xf0000000) != 0x30000000) {
        uint32_t local_70v = *(uint32_t*)(param_3 + 0x18);
        uint32_t local_6cv = *(uint32_t*)(param_3 + 0x14);
        uint32_t local_84v = *(uint32_t*)(param_3 + 8);
        iVar5 = (**(int(**)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int))(*(int*)param_4 + 4))(
            local_84v, *(uint32_t*)(param_3 + 0x10), local_6cv, local_70v,
            *(uint32_t*)(param_3 + 0x1c), *(uint32_t*)(param_3 + 0x20),
            *(uint32_t*)(param_3 + 0x24), *(uint32_t*)(param_3 + 0x28),
            *(uint32_t*)(param_3 + 0x2c), 0);
        return iVar5 == 0;
    }
    FUN_006b36a0(*(uint32_t*)(param_3 + 8));
    local_90 = (char*)&local_64;
    uVar6 = 4;
    uint32_t uVar4 = FUN_005dbe20();
    switch (uVar4) {
    case 1:
        FUN_006b3c30(&local_89);
        local_90 = &local_89;
        iVar5 = 1;
        uVar6 = 1;
        break;
    case 2:
    case 0xb:
        FUN_006b3c50(&local_74);
        local_90 = local_74;
        iVar5 = (local_74 != (char*)0x0 && *local_74 != '\0') ? 1 : 0;
        uVar6 = 1;
        break;
    case 3:
        FUN_006b3c70(&local_6c);
        local_90 = (char*)&local_6c;
        iVar5 = 4;
        uVar6 = 4;
        break;
    case 4:
        FUN_006b3c90(&local_64);
        iVar5 = 4;
        break;
    case 5:
        FUN_006b3cb0(&local_80);
        local_60 = local_7c;
        local_64 = local_80;
        iVar5 = 8;
        break;
    default:
        break;
    }
    uint32_t local_70 = *(uint32_t*)(param_3 + 0x18);
    uint32_t local_6c2 = *(uint32_t*)(param_3 + 0x14);
    local_84 = *(uint32_t*)(param_3 + 8);
    iVar5 = (**(int(**)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int, uint32_t, char*, int))(*(int*)param_4 + 4))(
        local_84, *(uint32_t*)(param_3 + 0x10), local_6c2, local_70,
        *(uint32_t*)(param_3 + 0x1c), *(uint32_t*)(param_3 + 0x20), iVar5, uVar6,
        local_90, 1);
    return iVar5 == 0;
}

// 0x5eb370 — observed shape
// Count check then four sequential list walks: expected counts from
// self+0x1c, self+0x30, self+0x44, self+0x58 with list heads at
// self+0x14/0xc, self+0x20/0x28, self+0x34/0x3c, self+0x48/0x50. Each
// element is validated via FUN_005ea5a0 and counted; the function returns
// true only when every count matches its expected value.
uint32_t FUN_5eb370(void* self, uint32_t param_1) {
    int in_ECX = (int)(intptr_t)self;
    int iVar3 = *(int*)(in_ECX + 0x1c);
    uint32_t uVar5 = (uint32_t)FUN_006b4fe0(param_1, (uint32_t)iVar3);
    if ((char)uVar5 == '\0') {
        return uVar5;
    }
    uint32_t* puVar6 = *(uint32_t**)(in_ECX + 0x14);
    int iVar8 = 0;
    int iVar7 = 0;
    *(uint32_t**)(in_ECX + 0xc) = puVar6;
    if (puVar6 != (uint32_t*)0x0) {
        *(uint32_t**)(in_ECX + 0xc) = (uint32_t*)puVar6[0];
        iVar7 = (int)puVar6[2];
    }
    while (iVar7 != 0) {
        if ((char)(uintptr_t)FUN_005ea5a0(self, param_1) == '\0') {
            return (uint32_t)(uintptr_t)puVar6 & 0xffffff00;
        }
        puVar6 = *(uint32_t**)(in_ECX + 0xc);
        iVar8 = iVar8 + 1;
        iVar7 = 0;
        if (puVar6 != (uint32_t*)0x0) {
            *(uint32_t**)(in_ECX + 0xc) = (uint32_t*)puVar6[0];
            iVar7 = (int)puVar6[2];
        }
    }
    if (iVar8 != iVar3) return 0;
    iVar3 = *(int*)(in_ECX + 0x30);
    if ((char)(uintptr_t)FUN_006b4fe0(param_1, (uint32_t)iVar3) == '\0') return 0;
    uint32_t* puVar1 = (uint32_t*)(in_ECX + 0x20);
    iVar8 = 0;
    iVar7 = 0;
    if ((puVar1 != (uint32_t*)0x0) && (in_ECX != -0x24)) {
        puVar6 = *(uint32_t**)(in_ECX + 0x28);
        *puVar1 = (uint32_t)(uintptr_t)puVar6;
        if (puVar6 != (uint32_t*)0x0) {
            *puVar1 = puVar6[0];
            iVar7 = (int)puVar6[2];
        }
        while (iVar7 != 0) {
            if ((char)(uintptr_t)FUN_005ea5a0(self, param_1) == '\0') return 0;
            iVar8 = iVar8 + 1;
            iVar7 = 0;
            puVar6 = (uint32_t*)*puVar1;
            if (puVar6 != (uint32_t*)0x0) {
                *puVar1 = puVar6[0];
                iVar7 = (int)puVar6[2];
            }
        }
    }
    if (iVar8 != iVar3) return 0;
    iVar3 = *(int*)(in_ECX + 0x44);
    if ((char)(uintptr_t)FUN_006b4fe0(param_1, (uint32_t)iVar3) == '\0') return 0;
    puVar1 = (uint32_t*)(in_ECX + 0x34);
    iVar8 = 0;
    iVar7 = 0;
    if ((puVar1 != (uint32_t*)0x0) && (in_ECX != -0x38)) {
        puVar6 = *(uint32_t**)(in_ECX + 0x3c);
        *puVar1 = (uint32_t)(uintptr_t)puVar6;
        if (puVar6 != (uint32_t*)0x0) {
            *puVar1 = puVar6[0];
            iVar7 = (int)puVar6[2];
        }
        while (iVar7 != 0) {
            if ((char)(uintptr_t)FUN_005ea5a0(self, param_1) == '\0') return 0;
            iVar8 = iVar8 + 1;
            iVar7 = 0;
            puVar6 = (uint32_t*)*puVar1;
            if (puVar6 != (uint32_t*)0x0) {
                *puVar1 = puVar6[0];
                iVar7 = (int)puVar6[2];
            }
        }
    }
    if (iVar8 != iVar3) return 0;
    iVar3 = *(int*)(in_ECX + 0x58);
    if ((char)(uintptr_t)FUN_006b4fe0(param_1, (uint32_t)iVar3) == '\0') return 0;
    int* piVar2 = (int*)(in_ECX + 0x48);
    iVar8 = 0;
    iVar7 = 0;
    if ((piVar2 != (int*)0x0) && (in_ECX != -0x4c)) {
        int* piVar4 = *(int**)(in_ECX + 0x50);
        *piVar2 = (int)(intptr_t)piVar4;
        if (piVar4 != (int*)0x0) {
            *piVar2 = *piVar4;
            iVar7 = piVar4[2];
        }
        while (iVar7 != 0) {
            if ((char)(uintptr_t)FUN_005ea5a0(self, param_1) == '\0') {
                return (uint32_t)(uintptr_t)FUN_005ea5a0(self, param_1) & 0xffffff00;
            }
            iVar8 = iVar8 + 1;
            iVar7 = 0;
            piVar4 = (int*)*piVar2;
            if (piVar4 != (int*)0x0) {
                *piVar2 = *piVar4;
                iVar7 = piVar4[2];
            }
        }
    }
    return (uint32_t)(((uint32_t)iVar3 & 0xffffff00) | (uint32_t)(iVar8 == iVar3));
}

// 0x5eb560 — observed shape
// Scalar deleting-destructor shape: calls FUN_5ea710(self), then frees self
// when the low bit of param_1 is set.
void FUN_5eb560(void* self, unsigned char param_1) {
    FUN_5ea710(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

