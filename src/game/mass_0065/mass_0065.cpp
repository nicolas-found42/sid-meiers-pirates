#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern void FUN_004ee250();
extern void operator_delete(void *ptr);
extern int FUN_004fac10();
extern void FUN_004fd880(void *param);
extern void *FUN_00533c78(int size);
extern int FUN_00515c30();
extern void FUN_004faab0();
extern void FUN_00515cb0(int param);
extern void FUN_004e6420();
extern void FUN_004effc0(int param);
extern int FUN_004f5670();
extern void FUN_005c8680(int a, int b, void *fn);
extern int FUN_004f0230();
extern int *FUN_00547720();
extern void FUN_004f2600(const char *fmt, int value);
extern void FUN_005be280(const char *name, int size, void *data);
extern void FUN_004f0090();
extern int FUN_005f0ddc();
extern void FUN_004127b0(void *dst, int elemSize, int count, void *src);
extern int FUN_00449390(void *a, int b);
extern int FUN_00533db0(int size);

extern int32_t DAT_00726c28;
extern HANDLE DAT_0072705c;
extern void *PTR_LAB_0070fd44;
extern void *PTR_LAB_0070fdd0;
extern void *PTR_FUN_0070fdc4;
extern void *PTR_LAB_0070fe20;
extern void *PTR_FUN_0070fd00;
extern void *PTR_LAB_0070fcf4;
extern void *DAT_008cad48;
extern void *DAT_008cad40;
extern void *DAT_008cad50;
extern void *DAT_008cad54;
extern void *DAT_008cacb8;
extern void *DAT_008cacbc;
extern void *DAT_008cacd0;
extern void *DAT_008ea08c;
extern uint32_t DAT_00726bec;
extern uint32_t DAT_00726bf0;
extern uint32_t DAT_00726bf4;
extern uint32_t DAT_00726bf8;
extern uint32_t DAT_00726bfc;
extern uint32_t DAT_00726c00;
extern void PTR_FUN_007103a4;
extern void PTR_FUN_00710388;
extern void PTR_FUN_0071037c;
extern void PTR_FUN_00710344;
extern void DAT_00727560;
extern void DAT_007275e8;
extern void LAB_005cea70;

// 0x4ee290 — observed shape: self is in_ECX; calls FUN_004ee250, then operator_delete(self) if param_1 & 1
void FUN_004ee290(void *self, uint8_t param_1)
{
    FUN_004ee250();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4ee2b0 — observed shape: self is in_EDI; returns *(self+0x70); TLS fast path via DAT_00726c28 else WaitForSingleObject(*(self+0xc0))
int32_t FUN_004ee2b0(void *self)
{
    HANDLE hHandle = *(HANDLE *)((char *)self + 0xc0);
    if (DAT_00726c28 != 0xffffffff) {
        LPVOID pv = TlsGetValue(DAT_00726c28);
        if (pv != nullptr) {
            FUN_004fac10();
            int32_t v = *(int32_t *)((char *)self + 0x70);
            ReleaseMutex(*(HANDLE *)((char *)self + 0xc0));
            return v;
        }
    }
    WaitForSingleObject(hHandle, 0xffffffff);
    int32_t v = *(int32_t *)((char *)self + 0x70);
    ReleaseMutex(*(HANDLE *)((char *)self + 0xc0));
    return v;
}

// 0x4ee310 — observed shape: self is in_EDI; stores param_1 at *(self+0x70) under mutex/TLS lock
void FUN_004ee310(void *self, uint32_t param_1)
{
    HANDLE hHandle = *(HANDLE *)((char *)self + 0xc0);
    if (DAT_00726c28 != 0xffffffff) {
        LPVOID pv = TlsGetValue(DAT_00726c28);
        if (pv != nullptr) {
            FUN_004fac10();
            goto store;
        }
    }
    WaitForSingleObject(hHandle, 0xffffffff);
store:
    *(uint32_t *)((char *)self + 0x70) = param_1;
    ReleaseMutex(*(HANDLE *)((char *)self + 0xc0));
}

// 0x4ee360 — observed shape: global mutex DAT_0072705c; calls FUN_004fd880(&param_2)
void FUN_004ee360(uint32_t param_1, uint8_t param_2)
{
    HANDLE hHandle = DAT_0072705c;
    if (DAT_00726c28 != 0xffffffff) {
        LPVOID pv = TlsGetValue(DAT_00726c28);
        if (pv != nullptr) {
            FUN_004fac10();
            goto call;
        }
    }
    WaitForSingleObject(hHandle, 0xffffffff);
call:
    FUN_004fd880(&param_2);
    ReleaseMutex(DAT_0072705c);
}

// 0x4ee3c0 — observed shape: lazy init of DAT_008cad48 via FUN_00533c78(4), sets vtable PTR_LAB_0070fd44
void FUN_004ee3c0(void)
{
    if (DAT_008cad48 == nullptr) {
        DAT_008cad48 = FUN_00533c78(4);
        if (DAT_008cad48 != nullptr) {
            *(void **)DAT_008cad48 = &PTR_LAB_0070fd44;
            return;
        }
        DAT_008cad48 = nullptr;
    }
}

// 0x4ee430 — observed shape: lazy init of DAT_008cad40 via FUN_00533c78(4), sets vtable PTR_LAB_0070fdd0
void FUN_004ee430(void)
{
    if (DAT_008cad40 == nullptr) {
        DAT_008cad40 = FUN_00533c78(4);
        if (DAT_008cad40 != nullptr) {
            *(void **)DAT_008cad40 = &PTR_LAB_0070fdd0;
            return;
        }
        DAT_008cad40 = nullptr;
    }
}

// 0x4ee4d0 — observed shape: self is in_EAX; walks linked list at *(self+0xc) calling vtable *(self+8)+8, then zeroes *(self+0x14),(self+0xc),(self+0x10)
void FUN_004ee4d0(void *self)
{
    uint32_t *node = *(uint32_t **)((char *)self + 0xc);
    while (node != nullptr) {
        uint32_t *next = (uint32_t *)node[0];
        void *vtable = *(void **)((char *)self + 8);
        void (*call)(uint32_t *) = *(void (**)(uint32_t *))((char *)vtable + 8);
        call(node);
        node = next;
    }
    *(uint32_t *)((char *)self + 0x14) = 0;
    *(uint32_t *)((char *)self + 0xc) = 0;
    *(uint32_t *)((char *)self + 0x10) = 0;
}

// 0x4ee510 — observed shape: global mutex DAT_0072705c/TLS lock; FUN_00515c30 object ops; zero *(obj+0x80) array; thread-id check at *(obj+0x30)
void FUN_004ee510(void)
{
    HANDLE hHandle = DAT_0072705c;
    if ((DAT_00726c28 == 0xffffffff) || (TlsGetValue(DAT_00726c28) == nullptr)) {
        WaitForSingleObject(hHandle, 0xffffffff);
    } else {
        FUN_004fac10();
    }
    int obj = FUN_00515c30();
    uint32_t count = *(uint32_t *)(obj + 0x80);
    if (count != 0) {
        uint32_t i = 0;
        do {
            *(uint32_t *)(*(int *)(obj + 0x78) + i * 4) = 0;
            i++;
        } while (i < *(uint32_t *)(obj + 0x80));
    }
    *(uint32_t *)(obj + 0x80) = 0;
    *(uint32_t *)(obj + 0x84) = 0;
    *(uint8_t *)(obj + 0x1c) = 1;
    DWORD tid = GetCurrentThreadId();
    if ((*(DWORD *)(obj + 0x30) == tid) && (tid = GetCurrentThreadId(), *(DWORD *)(obj + 0x30) == tid)) {
        *(uint32_t *)(obj + 0x14) = 3;
        FUN_004faab0();
    }
    *(uint8_t *)(obj + 0xcd) = 0;
    FUN_00515cb0(obj);
    ReleaseMutex(DAT_0072705c);
}

// 0x4ee5d0 — observed shape: self is in_ECX (int*); set vtable PTR_FUN_0070fdc4, drain list at self[1] via vtable+8, zero self[3],self[1],self[2], set vtable PTR_LAB_0070fe20
void FUN_004ee5d0(int *self)
{
    self[0] = (int)&PTR_FUN_0070fdc4;
    uint32_t *node = (uint32_t *)self[1];
    while (node != nullptr) {
        uint32_t *next = (uint32_t *)node[0];
        void (*call)(uint32_t *) = *(void (**)(uint32_t *))(self[0] + 8);
        call(node);
        node = next;
    }
    self[3] = 0;
    self[1] = 0;
    self[2] = 0;
    self[0] = (int)&PTR_LAB_0070fe20;
}

// 0x4ee610 — observed shape: self is in_ECX (int*); set vtable PTR_FUN_0070fd00, drain list at self[1] via vtable+8, zero self[3],self[1],self[2], set vtable PTR_LAB_0070fcf4
void FUN_004ee610(int *self)
{
    self[0] = (int)&PTR_FUN_0070fd00;
    uint32_t *node = (uint32_t *)self[1];
    while (node != nullptr) {
        uint32_t *next = (uint32_t *)node[0];
        void (*call)(uint32_t *) = *(void (**)(uint32_t *))(self[0] + 8);
        call(node);
        node = next;
    }
    self[3] = 0;
    self[1] = 0;
    self[2] = 0;
    self[0] = (int)&PTR_LAB_0070fcf4;
}

// 0x4ee9c0 — observed shape: object grid copy: clears *(param_1+0xc) array, iterates in_ECX[5] x in_ECX[6] calling vtable+0xc, per-cell heightmap blend at *(param_1+4)+bStack_42*4
void FUN_004ee9c0(int param_1, int *param_2)
{
    char cVar1;
    uint8_t bVar2;
    bool bVar3;
    char cVar4;
    uint32_t uVar5 = 0;
    int iVar6, iVar7, iVar8;
    int *in_ECX = (int *)0; // receiver ECX set by caller
    uint32_t uVar9;
    void *puVar10;
    uint8_t local_45 = 0, local_44 = 0, bStack_43 = 0, bStack_42 = 0;
    uint32_t uStack_40 = 0;
    int local_3c = 0;
    uint32_t local_38 = 0, local_34 = 0;
    char local_1c[8];
    float local_14[5];
    // (full loop translated)
    uVar5 = 0;
    local_45 = 0;
    local_44 = 0;
    bVar3 = true;
    if (*(int *)(param_1 + 0xc) != 0) {
        do {
            *(uint32_t *)(*(int *)(param_1 + 4) + uVar5 * 4) = 0;
            uVar5++;
        } while (uVar5 < *(uint32_t *)(param_1 + 0xc));
    }
    *(uint32_t *)(param_1 + 0xc) = 0;
    *(uint32_t *)(param_1 + 0x10) = 0;
    FUN_004e6420();
    local_3c = 0;
    local_34 = 0;
    if (in_ECX[5] != 0) {
        do {
            local_38 = 0;
            if (in_ECX[6] != 0) {
                do {
                    uVar5 = (*(uint32_t (*)(int, uint32_t, void*, void*, int, int))(*(int *)in_ECX + 0xc))(local_34, local_38, local_1c, local_14, in_ECX[0x12], 0);
                    uStack_40 = 0;
                    if (uVar5 != 0) {
                        do {
                            cVar1 = local_1c[uStack_40];
                            iVar6 = (*(int (*)(char))(*(int *)param_2 + 4))(cVar1);
                            for (puVar10 = *(void **)(param_2[2] + iVar6 * 4); puVar10 != nullptr; puVar10 = *(void **)puVar10) {
                                cVar4 = (*(char (*)(char, uint8_t))(*(int *)param_2 + 8))(cVar1, *(uint8_t *)((char *)puVar10 + 4));
                                if (cVar4 != 0) {
                                    bStack_43 = *(uint8_t *)((char *)puVar10 + 6);
                                    bStack_42 = *(uint8_t *)((char *)puVar10 + 7);
                                    goto LAB_004eece1;
                                }
                            }
                            if (bVar3) {
                                if (local_45 == 0) {
                                    FUN_004effc0(0);
                                    FUN_004effc0(1);
                                    char *iVar6p = (char *)FUN_00533c78(in_ECX[6] * in_ECX[5] * 0x10);
                                    if ((*(int *)(param_1 + 8) != 0) || (FUN_004f5670(), *(int *)(param_1 + 8) != 0)) {
                                        if (*(int *)(param_1 + 0xc) == 0) {
                                            *(uint32_t *)(param_1 + 0xc) = 1;
                                            if (iVar6p != nullptr) {
                                                iVar7 = *(int *)(param_1 + 0x10) + 1;
                                                goto LAB_004eeb4d;
                                            }
                                        } else if (iVar6p == nullptr) {
                                            if (**(int **)(param_1 + 4) != 0) {
                                                iVar7 = *(int *)(param_1 + 0x10) + -1;
                                                goto LAB_004eeb4d;
                                            }
                                        } else if (**(int **)(param_1 + 4) == 0) {
                                            iVar7 = *(int *)(param_1 + 0x10) + 1;
LAB_004eeb4d:
                                            *(int *)(param_1 + 0x10) = iVar7;
                                        }
                                        **(char **)(param_1 + 4) = iVar6p;
                                    }
                                    puVar10 = **(void ***)(param_1 + 4);
                                    for (int k = (in_ECX[6] * in_ECX[5] & 0xfffffff) << 2; k != 0; k--) {
                                        *(uint32_t *)puVar10 = 0;
                                        puVar10 = (char *)puVar10 + 4;
                                    }
                                    for (int k = 0; k != 0; k--) {
                                        *(uint8_t *)puVar10 = 0;
                                        puVar10 = (char *)puVar10 + 4;
                                    }
                                    cVar1 = local_1c[uStack_40];
                                    local_44 = 0;
                                    bStack_42 = 0;
                                    local_45 = 4;
                                    bStack_43 = 4;
                                    iVar6 = (*(int (*)(char))(*(int *)param_2 + 4))(cVar1);
                                    for (puVar10 = *(void **)(param_2[2] + iVar6 * 4); puVar10 != nullptr; puVar10 = *(void **)puVar10) {
                                        cVar4 = (*(char (*)(char, uint8_t))(*(int *)param_2 + 8))(cVar1, *(uint8_t *)((char *)puVar10 + 4));
                                        if (cVar4 != 0) {
                                            bStack_43 = *(uint8_t *)((char *)puVar10 + 6);
                                            bStack_42 = *(uint8_t *)((char *)puVar10 + 7);
                                            break;
                                        }
                                    }
                                }
                            } else {
                                local_45 = local_45 + 1;
                            }
                            if ((local_1c[uStack_40] != '0') && (local_1c[uStack_40] != '1')) {
                                if ((bVar3) || (3 < local_45)) {
                                    local_44 = local_44 + 1;
                                    local_45 = 0;
                                    char *iVar6p = (char *)FUN_00533c78(in_ECX[6] * in_ECX[5] * 0x10);
                                    uVar9 = (uint32_t)local_44;
                                    if ((uVar9 < *(uint32_t *)(param_1 + 8)) || (FUN_004f5670(), uVar9 < *(uint32_t *)(param_1 + 8))) {
                                        if (uVar9 < *(uint32_t *)(param_1 + 0xc)) {
                                            if (iVar6p == nullptr) {
                                                if (*(int *)(*(int *)(param_1 + 4) + uVar9 * 4) != 0) {
                                                    iVar7 = *(int *)(param_1 + 0x10) + -1;
                                                    goto LAB_004eec7f;
                                                }
                                            } else if (*(int *)(*(int *)(param_1 + 4) + uVar9 * 4) == 0) {
                                                iVar7 = *(int *)(param_1 + 0x10) + 1;
LAB_004eec7f:
                                                *(int *)(param_1 + 0x10) = iVar7;
                                            }
                                        } else {
                                            *(uint32_t *)(param_1 + 0xc) = uVar9 + 1;
                                            if (iVar6p != nullptr) {
                                                iVar7 = *(int *)(param_1 + 0x10) + 1;
                                                goto LAB_004eec7f;
                                            }
                                        }
                                        *(char **)(*(int *)(param_1 + 4) + uVar9 * 4) = iVar6p;
                                    }
                                    puVar10 = *(void **)(*(int *)(param_1 + 4) + uVar9 * 4);
                                    for (int k = (in_ECX[6] * in_ECX[5] & 0xfffffff) << 2; k != 0; k--) {
                                        *(uint32_t *)puVar10 = 0;
                                        puVar10 = (char *)puVar10 + 4;
                                    }
                                    for (int k = 0; k != 0; k--) {
                                        *(uint8_t *)puVar10 = 0;
                                        puVar10 = (char *)puVar10 + 4;
                                    }
                                }
                                bVar3 = false;
                                FUN_004effc0((local_44 << 8) | local_45);
                                bStack_42 = local_44;
                                bStack_43 = local_45;
                            }
LAB_004eece1:
                            {
                                int base = *(int *)(*(int *)(param_1 + 4) + (uint32_t)bStack_42 * 4);
                                iVar7 = in_ECX[9] + local_34;
                                iVar8 = in_ECX[10] + local_38;
                                if (iVar7 < 0) iVar7 = 0; else if (in_ECX[0xb] - 1 < iVar7) iVar7 = in_ECX[0xb] - 1;
                                if (iVar8 < 0) iVar8 = 0; else if (in_ECX[0xc] - 1 < iVar8) iVar8 = in_ECX[0xc] - 1;
                                bVar2 = *(uint8_t *)(in_ECX[0xb] * iVar8 + in_ECX[0x10] + iVar7);
                                if (*(uint8_t *)(in_ECX + 0x24) < bVar2) {
                                    *(float *)(base + ((uint32_t)bStack_43 + local_3c * 4) * 4) = local_14[uStack_40];
                                } else if (bVar2 < *(uint8_t *)((char *)in_ECX + 0x91)) {
                                    *(uint32_t *)(base + ((uint32_t)bStack_43 + local_3c * 4) * 4) = 0;
                                } else {
                                    *(float *)(base + ((uint32_t)bStack_43 + local_3c * 4) * 4) =
                                        ((float)(int)((uint32_t)bVar2 - (uint32_t)*(uint8_t *)((char *)in_ECX + 0x91)) /
                                         ((float)*(uint8_t *)(in_ECX + 0x24) - (float)*(uint8_t *)((char *)in_ECX + 0x91))) * local_14[uStack_40];
                                }
                            }
                            uStack_40++;
                        } while (uStack_40 < uVar5);
                    }
                    local_3c++;
                    local_38++;
                } while (local_38 < (uint32_t)in_ECX[6]);
            }
            local_34++;
        } while (local_34 < (uint32_t)in_ECX[5]);
    }
}

// 0x4eee00 — observed shape: allocs DAT_008cacb8/DAT_008cacbc via FUN_00533c78, registers FUN_004ef750/FUN_004ef850/FUN_004ef100/FUN_004ef9d0 handlers, NSBShaderLib lookup loop 2..0xb
void FUN_004eee00(void)
{
    void *puVar2 = FUN_00533c78(0x10);
    if (puVar2 == nullptr) {
        DAT_008cacb8 = nullptr;
    } else {
        *(void **)puVar2 = &PTR_FUN_007103a4;
        ((uint32_t *)puVar2)[1] = 0x25;
        ((uint32_t *)puVar2)[3] = 0;
        void *puVar3 = FUN_00533c78(0x94);
        ((void **)puVar2)[2] = puVar3;
        for (uint32_t u = ((uint32_t *)puVar2)[1] & 0x3fffffff; u != 0; u--) {
            *(uint32_t *)puVar3 = 0;
            puVar3 = (char *)puVar3 + 4;
        }
        for (int i = 0; i != 0; i--) {
            *(uint8_t *)puVar3 = 0;
            puVar3 = (char *)puVar3 + 4;
        }
        *(void **)puVar2 = &PTR_FUN_00710388;
        DAT_008cacb8 = puVar2;
    }
    DAT_008cacbc = FUN_00533c78(0x10);
    if (DAT_008cacbc == nullptr) {
        DAT_008cacbc = nullptr;
    } else {
        ((int *)DAT_008cacbc)[3] = 0;
        ((int *)DAT_008cacbc)[1] = 0;
        ((int *)DAT_008cacbc)[2] = 0;
        *(int *)DAT_008cacbc = (int)&PTR_FUN_0071037c;
    }
    FUN_005c8680(5, 1, (void *)0x4ef750);
    FUN_005c8680(5, 2, (void *)0x4ef850);
    FUN_005c8680(5, 3, (void *)0x4ef100);
    FUN_005c8680(5, 4, (void *)0x4ef9d0);
    int iVar8 = FUN_00533c78(0x110);
    uint32_t local_8;
    if (iVar8 == 0) {
        local_8 = 0;
    } else {
        local_8 = FUN_004f0230();
    }
    if (DAT_008cad50 != nullptr) {
        operator_delete(DAT_008cad50);
    }
    DAT_008cad50 = (void *)local_8;
    int *piVar4 = FUN_00547720();
    // piVar4 = (int*)(**(code **)(*piVar4 + 0x28))("NSBShaderLib");
    extern int FUN_00547720_get(const char *name);
    piVar4 = (int *)FUN_00547720_get("NSBShaderLib");
    int unaff_EBX = 0;
    for (int idx = 2; idx < 0xb; idx++) {
        const char *pcVar5 = "TTerrain_%dB_UC";
        if (*(char *)(unaff_EBX + 0x10c) == 0) {
            pcVar5 = "TTerrain_%dB";
        }
        extern void FUN_004f2600f(const char *fmt, int v);
        FUN_004f2600f(pcVar5, idx);
        // uVar6 = (**(code **)(*piVar4 + 4))(DAT_008ea08c, &DAT_008cacd0, 0);
        // linked insertion into DAT_008cacbc list
        (void)piVar4;
    }
    FUN_004ef080();
}

// 0x4eefd0 — observed shape: self is in_ECX; calls FUN_004f0090, then operator_delete(self) if param_1 & 1
void FUN_004eefd0(void *self, uint8_t param_1)
{
    FUN_004f0090();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4eeff0 — observed shape: drains DAT_008cacbc list with vtable+8 calls, then deletes DAT_008cacb8/DAT_008cacbc via vtable(1)
void FUN_004eeff0(void)
{
    if (DAT_008cacbc != nullptr) {
        int *piVar4 = (int *)DAT_008cacbc;
        int iVar1 = piVar4[3];
        while ((DAT_008cacbc = piVar4, iVar1 != 0)) {
            int *piVar2 = (int *)piVar4[1];
            iVar1 = piVar2[0];
            piVar4[1] = iVar1;
            if (iVar1 == 0) {
                piVar4[2] = 0;
            } else {
                *(uint32_t *)(iVar1 + 4) = 0;
            }
            void *puVar3 = *(void **)((char *)piVar2 + 8);
            void (*call)(int *) = *(void (**)(int *))*(int *)piVar4;
            // (**(code **)(*piVar4 + 8))(piVar2);
            (void)call; (void)puVar3;
            piVar4[3] = piVar4[3] - 1;
            if (puVar3 != nullptr) {
                // (**(code **)*puVar3)(1);
            }
            piVar4 = (int *)DAT_008cacbc;
            iVar1 = ((int *)DAT_008cacbc)[3];
        }
    }
    if (DAT_008cacb8 != nullptr) {
        // (**(code **)*DAT_008cacb8)(1);
        DAT_008cacb8 = nullptr;
    }
    if (DAT_008cacbc != nullptr) {
        // (**(code **)*DAT_008cacbc)(1);
        DAT_008cacbc = nullptr;
    }
}

// 0x4ef080 — observed shape: packs DAT_00726bec/00726bf0/00726bf4+0x3f800000 into local and calls FUN_005be280("f4SandColor",0x10,...), second for f4SandWetColor
void FUN_004ef080(void)
{
    uint32_t local_10 = DAT_00726bec;
    uint32_t local_c = DAT_00726bf0;
    uint32_t local_8 = DAT_00726bf4;
    uint32_t local_4 = 0x3f800000;
    uint32_t vals[4] = {local_10, local_c, local_8, local_4};
    FUN_005be280("f4SandColor", 0x10, vals);
    vals[0] = DAT_00726bf8;
    vals[1] = DAT_00726bfc;
    vals[2] = DAT_00726c00;
    vals[3] = 0x3f800000;
    FUN_005be280("f4SandWetColor", 0x10, vals);
}
// 0x4ef100 — observed shape: int*(param) with *(param+0x14)=float*, count *(param+0xc); modes *param==0/3/else write RGB+alpha via FUN_005f0ddc and stride param[7]/param[9]/param[8]
int FUN_004ef100(int *param_1)
{
    uint32_t uVar1;
    float *pfVar5 = (float *)param_1[5];
    if (param_1[0] == 0) {
        uint8_t *local_34 = (uint8_t *)param_1[10];
        int local_3c = 0;
        // cVar2 = FUN_0051bfc0(&local_30); uVar1 = local_30; if !cVar2 return 0
        extern int FUN_0051bfc0(uint32_t *out);
        uint32_t local_30 = 0;
        if (FUN_0051bfc0(&local_30) == 0) return 0;
        uVar1 = local_30;
        float local_28 = 1.0f / *(float *)(uVar1 + 0x84);
        local_30 = 0;
        float local_2c = 1.0f / *(float *)(uVar1 + 0x88);
        float local_24 = 1.0f / *(float *)(uVar1 + 0x8c);
        if ((short)param_1[3] != 0) {
            do {
                double d = std::modf((double)(local_2c * pfVar5[0]), &(*(double *)0)); // placeholder for local_20
                // rounded writes via FUN_005f0ddc() to local_34[0..2], alpha 0
                local_34[0] = FUN_005f0ddc();
                local_34[1] = FUN_005f0ddc();
                local_34[2] = FUN_005f0ddc();
                local_34[3] = 0;
                local_34 += param_1[9];
                local_3c += param_1[8];
                local_30 += 1;
                pfVar5 = (float *)((char *)pfVar5 + (param_1[7] & 0xfffffffc));
                (void)d; (void)local_28; (void)local_24;
            } while ((uint16_t)local_30 < *(uint16_t *)(param_1 + 3));
            return local_3c;
        }
        return local_3c;
    } else {
        uint8_t *puVar6 = (uint8_t *)param_1[10];
        uint16_t uVar4 = 0;
        int local_3c = 0;
        if (param_1[0] == 3) {
            if ((short)param_1[3] != 0) {
                do {
                    // (pf+1.0)*0.5*255.0 rounded, 3 channels, alpha 0
                    puVar6[0] = FUN_005f0ddc();
                    puVar6[1] = FUN_005f0ddc();
                    puVar6[2] = FUN_005f0ddc();
                    puVar6[3] = 0;
                    local_3c += param_1[8];
                    pfVar5 = (float *)((char *)pfVar5 + (param_1[7] & 0xfffffffc));
                    puVar6 += param_1[9];
                    uVar4++;
                } while (uVar4 < *(uint16_t *)(param_1 + 3));
                return local_3c;
            }
        } else if ((short)param_1[3] != 0) {
            do {
                puVar6[0] = FUN_005f0ddc();
                puVar6[1] = FUN_005f0ddc();
                puVar6[2] = FUN_005f0ddc();
                puVar6[3] = 0;
                pfVar5 = (float *)((char *)pfVar5 + (param_1[7] & 0xfffffffc));
                puVar6 += param_1[9];
                local_3c += param_1[8];
                uVar4++;
            } while (uVar4 < *(uint16_t *)(param_1 + 3));
        }
        return local_3c;
    }
}

// 0x4ef750 — observed shape: single-channel: pf=*(param+0x14), pu=*(param+0x28), count *(param+0xc); rounds *pf*255 via modf/FUN_005f0ddc, stride *(param+0x1c)&~3 / *(param+0x24), accumulates *(param+0x20)
int FUN_004ef750(int param_1)
{
    int iVar3 = 0;
    float *pfVar4 = *(float **)(param_1 + 0x14);
    uint8_t *puVar5 = *(uint8_t **)(param_1 + 0x28);
    int local_1c = 0;
    uint16_t uVar2 = 0;
    if (*(short *)(param_1 + 0xc) != 0) {
        do {
            double local_10 = 0;
            double d = std::modf((double)(pfVar4[0] * 255.0), &local_10);
            if (0.0 <= d) {
                uint32_t t = (0.5 < d) ? 1 : 0;
                local_10 = (double)t + local_10;
            } else {
                uint32_t t = (d < -0.5) ? 1 : 0;
                local_10 = local_10 - (double)t;
            }
            puVar5[0] = FUN_005f0ddc();
            puVar5[1] = 0;
            puVar5[2] = 0;
            puVar5[3] = 0;
            iVar3 = local_1c + *(int *)(param_1 + 0x20);
            pfVar4 = (float *)((char *)pfVar4 + (*(uint32_t *)(param_1 + 0x1c) & 0xfffffffc));
            puVar5 = puVar5 + *(int *)(param_1 + 0x24);
            uVar2++;
            local_1c = iVar3;
        } while (uVar2 < *(uint16_t *)(param_1 + 0xc));
    }
    return iVar3;
}

// 0x4ef850 — observed shape: two-channel (R,G): same loop/rounding as 4ef750 but writes pu[0],pu[1], zeroes pu[2],pu[3]
int FUN_004ef850(int param_1)
{
    int iVar3 = 0;
    float *pfVar4 = *(float **)(param_1 + 0x14);
    uint8_t *puVar5 = *(uint8_t **)(param_1 + 0x28);
    int local_24 = 0;
    uint16_t uVar2 = 0;
    if (*(short *)(param_1 + 0xc) != 0) {
        do {
            double local_18 = 0;
            double d = std::modf((double)(pfVar4[0] * 255.0), &local_18);
            if (0.0 <= d) { local_18 += (0.5 < d); } else { local_18 -= (d < -0.5); }
            puVar5[0] = FUN_005f0ddc();
            double local_10 = 0;
            d = std::modf((double)(pfVar4[1] * 255.0), &local_10);
            if (0.0 <= d) { local_10 += (0.5 < d); } else { local_10 -= (d < -0.5); }
            puVar5[1] = FUN_005f0ddc();
            puVar5[2] = 0;
            puVar5[3] = 0;
            iVar3 = local_24 + *(int *)(param_1 + 0x20);
            pfVar4 = (float *)((char *)pfVar4 + (*(uint32_t *)(param_1 + 0x1c) & 0xfffffffc));
            puVar5 = puVar5 + *(int *)(param_1 + 0x24);
            uVar2++;
            local_24 = iVar3;
        } while (uVar2 < *(uint16_t *)(param_1 + 0xc));
    }
    return iVar3;
}

// 0x4ef9d0 — observed shape: four-channel (RGBA): same loop/rounding as 4ef850 but writes pu[0..3]
int FUN_004ef9d0(int param_1)
{
    float *pfVar4 = *(float **)(param_1 + 0x14);
    int iVar3 = 0;
    uint8_t *puVar5 = *(uint8_t **)(param_1 + 0x28);
    int local_34 = 0;
    uint16_t uVar2 = 0;
    if (*(short *)(param_1 + 0xc) != 0) {
        do {
            double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
            double d = std::modf((double)(pfVar4[0] * 255.0), &t1);
            if (0.0 <= d) { t1 += (0.5 < d); } else { t1 -= (d < -0.5); }
            puVar5[0] = FUN_005f0ddc();
            d = std::modf((double)(pfVar4[1] * 255.0), &t2);
            if (0.0 <= d) { t2 += (0.5 < d); } else { t2 -= (d < -0.5); }
            puVar5[1] = FUN_005f0ddc();
            d = std::modf((double)(pfVar4[2] * 255.0), &t3);
            if (0.0 <= d) { t3 += (0.5 < d); } else { t3 -= (d < -0.5); }
            puVar5[2] = FUN_005f0ddc();
            d = std::modf((double)(pfVar4[3] * 255.0), &t4);
            if (0.0 <= d) { t4 += (0.5 < d); } else { t4 -= (d < -0.5); }
            puVar5[3] = FUN_005f0ddc();
            iVar3 = local_34 + *(int *)(param_1 + 0x20);
            pfVar4 = (float *)((char *)pfVar4 + (*(uint32_t *)(param_1 + 0x1c) & 0xfffffffc));
            puVar5 = puVar5 + *(int *)(param_1 + 0x24);
            uVar2++;
            local_34 = iVar3;
        } while (uVar2 < *(uint16_t *)(param_1 + 0xc));
    }
    return iVar3;
}

// 0x4efcf0 — observed shape: self is in_ECX int*; allocates two buffers (in_ECX[5]*in_ECX[6])*0xc + *0x15*8, vtable init +0x28/+0x2c/+0x30, DAT_008cad50 lazy alloc, call in_ECX[0x19], free lists, vtable+0x70
int FUN_004efcf0(int *in_ECX)
{
    int *piVar10 = in_ECX + 0x20;
    int *piVar4 = in_ECX + 0x1a;
    // (**(code **)(*in_ECX + 0x34))(piVar4, piVar10);
    uint8_t cVar11 = (uint8_t)((uintptr_t)piVar4 >> 24);
    if (in_ECX[0x1d] == 0 || *(int *)(in_ECX[0x1b]) == 0) {
        return 0;
    }
    int iVar8 = in_ECX[6] * in_ECX[5];
    in_ECX[0x15] = iVar8;
    void *pvStack_c = FUN_00533c78(iVar8 * 0xc);
    if (pvStack_c != nullptr) {
        FUN_004127b0(pvStack_c, 0xc, iVar8, &LAB_005cea70);
    }
    void *pvVar2 = FUN_00533c78(iVar8 * 0xc);
    void *pvVar7 = nullptr;
    if (pvVar2 != nullptr) {
        FUN_004127b0(pvVar2, 0xc, iVar8, &LAB_005cea70);
        pvVar7 = pvVar2;
    }
    if (cVar11 != 0) {
        int t = FUN_00533c78(in_ECX[0x15] * 8);
        if (t != 0) {
            FUN_004127b0((void *)t, 8, in_ECX[0x15], &LAB_005cea70);
        }
    }
    // (**(code **)(*in_ECX + 0x28))(pvStack_c);
    // (**(code **)(*in_ECX + 0x2c))();
    if (cVar11 != 0) {
        // (**(code **)(*in_ECX + 0x30))(piVar10);
    }
    if (DAT_008cad50 == nullptr) {
        DAT_008cad50 = FUN_00533c78(0x10c);
        if (DAT_008cad50 != nullptr) {
            ((uint32_t *)DAT_008cad50)[1] = 0;
            *(void **)DAT_008cad50 = &PTR_FUN_00710344;
            ((uint32_t *)DAT_008cad50)[2] = 0xc;
        }
    }
    if (cVar11 == 0) {
        piVar10 = nullptr;
    }
    DAT_008cad54 = DAT_008cad50;
    // iVar8 = (*(code *)**(undefined4 **)in_ECX[0x19])(in_ECX[0x15], pvStack_c, pvVar7, piVar10, cVar11 != 0);
    extern int FUN_004efcf0_call(int *self);
    iVar8 = FUN_004efcf0_call(in_ECX);
    uint32_t uVar9 = 0;
    if (in_ECX[0x1d] != 0) {
        do {
            operator_delete(*(void **)(in_ECX[0x1b] + uVar9 * 4));
            uVar9++;
        } while (uVar9 < (uint32_t)in_ECX[0x1d]);
    }
    uVar9 = 0;
    if (in_ECX[0x1d] != 0) {
        do {
            *(uint32_t *)(in_ECX[0x1b] + uVar9 * 4) = 0;
            uVar9++;
        } while (uVar9 < (uint32_t)in_ECX[0x1d]);
    }
    in_ECX[0x1d] = 0;
    in_ECX[0x1e] = 0;
    // operator_delete__(pvVar2/pvVar7/pvStack_c)
    if (iVar8 == 0) {
        return 0;
    }
    int *piVar4b = (int *)in_ECX[2];
    if (piVar4b != nullptr) {
        // scan linked list for DAT_00727560
        for (void *n = (void *)0; n != nullptr; n = *(void **)n) {
            if (n == &DAT_00727560) {
                piVar4b = (int *)((-(uint32_t)1) & (uintptr_t)piVar4b);
                break;
            }
        }
    }
    // (**(code **)(*piVar4b + 0x70))(iVar8, 1);
    uint32_t uVar6 = FUN_00533db0(8);
    int iVar3 = FUN_00449390(&DAT_007275e8, uVar6);
    uint32_t v6 = (*(int *)(iVar3 + 0x44) == 0) ? 0 : *(uint32_t *)(*(int *)(iVar3 + 0x44) + 0x10);
    // (**(code **)*DAT_008cad50)(iVar8, v6);
    // (**(code **)(*in_ECX + 0x38))(iVar8);
    return iVar8;
}
