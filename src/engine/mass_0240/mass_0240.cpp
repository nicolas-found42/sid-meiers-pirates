#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* ExceptionList;
void FUN_00533c78(uint32_t size);
void FUN_006b3830();
void FUN_00531830(uint32_t v);
int FUN_005ed050();
void FUN_006b3c00();
void FUN_006b38a0 void* a);
int FUN_005e5b30();
int FUN_005dc070();
int FUN_005dbfa0();
int FUN_005dc010();
void FUN_006b3790(uint32_t idx, void* p);
void FUN_005e4850(uint32_t p);
void FUN_005e3ec0(uint32_t p);
void _eh_vector_constructor_iterator_(void* p, size_t sz, uint32_t n, void* ctor, void* dtor);
void _eh_vector_destructor_iterator_(void* p, size_t sz, uint32_t n, void* dtor);
void operator_delete__(void* p);
void LAB_004c2970();
void FUN_005e4780();

// 0x5e3f20 — observed shape
void FUN_005e3f20(void* self)
{
    uint32_t uVar2 = 0;
    int32_t cnt = *(int32_t*)((uint8_t*)self + 0x30);
    if (cnt != 0) {
        do {
            int iVar1 = *(int*)(*(intptr_t*)((uint8_t*)self + 0x28) + uVar2 * 4);
            if (iVar1 != 0) {
                *(uint32_t*)(iVar1 + 0x10) = 0;
            }
            uVar2++;
        } while (uVar2 < (uint32_t)cnt);
    }
}

// 0x5e3f50 — observed shape
uint32_t FUN_005e3f50(void* self)
{
    void* local_c;
    uint32_t local_4 = 0xffffffff;
    if (*(int*)((uint8_t*)self + 0x40) != 0) {
        return *(uint32_t*)((uint8_t*)self + 0x40);
    }
    local_c = ExceptionList;
    ExceptionList = &local_c;
    void* pvVar2 = (void*)FUN_00533c78(100);
    local_4 = 0;
    uint32_t* puVar3;
    if (pvVar2 == nullptr) {
        puVar3 = nullptr;
    } else {
        puVar3 = (uint32_t*)FUN_006b3830();
    }
    uint32_t* puVar1 = *(uint32_t**)((uint8_t*)self + 0x40);
    local_4 = 0xffffffff;
    if (puVar1 != puVar3) {
        if (puVar1 != nullptr) {
            int32_t* piVar7 = (int32_t*)puVar1 + 1;
            *piVar7 = *piVar7 + -1;
            if (*piVar7 == 0) {
                (*(void(**)(uint32_t))(*puVar1))(1);
            }
        }
        *(uint32_t**)((uint8_t*)self + 0x40) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    (*(void(**)(uint32_t))(**(uint32_t**)((uint8_t*)self + 0x40) + 0xc))(*(uint32_t*)((uint8_t*)self + 8));
    if (**(int**)((uint8_t*)self + 0x28) != 0) {
        int iVar5 = **(int**)((uint8_t*)self + 0x40);
        uint32_t uVar4 = (**(uint32_t(**)())(**(int**)(**(int**)((uint8_t*)self + 0x28) + 0x34) + 8))();
        (**(void(**)(uint32_t))(iVar5 + 0x10))(uVar4);
    }
    FUN_00531830(*(uint32_t*)((uint8_t*)self + 0x34));
    int iVar5 = FUN_005ed050();
    while (iVar5 != 0) {
        int iVar6 = FUN_00533c78(0xdc);
        if (iVar6 == 0) {
            (void*)0;
        } else {
            (void*)FUN_006b3c00();
        }
        FUN_006b38a0((void*)0);
        iVar5 = FUN_005e5b30();
    }
    uint32_t uVar8 = 0;
    int32_t cnt = *(int32_t*)((uint8_t*)self + 0x30);
    if (cnt != 0) {
        do {
            if (*(int*)(*(intptr_t*)((uint8_t*)self + 0x28) + uVar8 * 4) != 0) {
                void* piVar7 = (void*)FUN_005dc070();
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uint32_t uVar4 = (**(uint32_t(**)())(*(uint32_t*)piVar7 + 0x1c))();
                (**(void(**)(uint32_t))(iVar5 + 0x44))(uVar4);
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uVar4 = (**(uint32_t(**)())(*(uint32_t*)piVar7 + 0x20))();
                (**(void(**)(uint32_t))(iVar5 + 0x44))(uVar4);
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uVar4 = (**(uint32_t(**)())(*(uint32_t*)piVar7 + 0x24))();
                (**(void(**)(uint32_t))(iVar5 + 0x48))(uVar4);
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uVar4 = (**(uint32_t(**)())(*(uint32_t*)piVar7 + 0x28))();
                (**(void(**)(uint32_t))(iVar5 + 0x48))(uVar4);
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uVar4 = (**(uint32_t(**)())(*(uint32_t*)piVar7 + 0x2c))();
                (**(void(**)(uint32_t))(iVar5 + 0x4c))(uVar4);
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uVar4 = (**(uint32_t(**)())(*(uint32_t*)piVar7 + 0x30))();
                (**(void(**)(uint32_t))(iVar5 + 0x4c))(uVar4);
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uVar4 = (**(uint32_t(**)())(*(uint32_t*)piVar7 + 0x34))();
                (**(void(**)(uint32_t))(iVar5 + 0x50))(uVar4);
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uVar4 = FUN_005dbfa0();
                (**(void(**)(uint32_t))(iVar5 + 100))(uVar4);
                iVar5 = **(int**)((uint8_t*)self + 0x40);
                uVar4 = FUN_005dc010();
                (**(void(**)(uint32_t))(iVar5 + 0x68))(uVar4);
                FUN_006b3790(uVar8, piVar7);
            }
            uVar8++;
        } while (uVar8 < (uint32_t)cnt);
    }
    ExceptionList = pvVar2;
    return *(uint32_t*)((uint8_t*)self + 0x40);
}

// 0x5e4180 — observed shape
void FUN_005e4180(void* self, uint32_t param_1, uint32_t param_2)
{
    if ((param_2 < *(uint32_t*)((uint8_t*)self + 0x30)) && (*(int*)(*(intptr_t*)((uint8_t*)self + 0x28) + param_2 * 4) != 0)) {
        FUN_005e4850(param_1);
        return;
    }
    FUN_005e3ec0(param_1);
}

// 0x5e41b0 — observed shape
void FUN_005e41b0(void* self)
{
    void* local_c = ExceptionList;
    ExceptionList = &local_c;
    uint32_t uVar4 = 0;
    if (*(int*)((uint8_t*)self + 0xc) != 0) {
        do {
            int iVar2 = *(int*)((uint8_t*)self + 4);
            uint32_t* puVar3 = *(uint32_t**)(iVar2 + uVar4 * 4);
            if (puVar3 != nullptr) {
                int32_t* piVar1 = (int32_t*)puVar3 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    (**(void(**)(uint32_t))(*puVar3))(1);
                }
                *(uint32_t*)(iVar2 + uVar4 * 4) = 0;
            }
            uVar4++;
        } while (uVar4 < *(uint32_t*)((uint8_t*)self + 0xc));
    }
    *(uint32_t*)((uint8_t*)self + 0xc) = 0;
    *(uint32_t*)((uint8_t*)self + 0x10) = 0;
    ExceptionList = local_c;
}

// 0x5e4230 — observed shape
void FUN_005e4230(void* self, uint32_t param_1)
{
    void* local_c = ExceptionList;
    uint32_t local_4 = 0xffffffff;
    if (param_1 != *(uint32_t*)((uint8_t*)self + 8)) {
        ExceptionList = &local_c;
        if (param_1 < *(uint32_t*)((uint8_t*)self + 0xc)) {
            uint32_t uVar9 = param_1;
            do {
                int32_t* piVar2 = (int32_t*)(*(intptr_t*)((uint8_t*)self + 4) + uVar9 * 4);
                if (*piVar2 != 0) {
                    uint32_t* puVar4 = (uint32_t*)*piVar2;
                    if (puVar4 != nullptr) {
                        int32_t* piVar1 = (int32_t*)puVar4 + 1;
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            (**(void(**)(uint32_t))(*puVar4))(1);
                        }
                        *piVar2 = 0;
                    }
                    *(int32_t*)((uint8_t*)self + 0x10) = *(int32_t*)((uint8_t*)self + 0x10) + -1;
                }
                uVar9++;
            } while (uVar9 < *(uint32_t*)((uint8_t*)self + 0xc));
            *(uint32_t*)((uint8_t*)self + 0xc) = param_1;
        }
        local_4 = 0xffffffff;
        void* pvVar5 = *(void**)((uint8_t*)self + 4);
        *(uint32_t*)((uint8_t*)self + 8) = param_1;
        if (param_1 == 0) {
            *(uint32_t*)((uint8_t*)self + 4) = 0;
        } else {
            uint32_t* puVar8 = (uint32_t*)FUN_00533c78(param_1 * 4 + 4);
            local_4 = 1;
            uint32_t* puVar10;
            if (puVar8 == nullptr) {
                puVar10 = nullptr;
            } else {
                puVar10 = puVar8 + 1;
                *puVar8 = param_1;
                _eh_vector_constructor_iterator_(puVar10, 4, param_1, (void*)LAB_004c2970, (void*)FUN_005e4780);
            }
            uint32_t uVar9 = 0;
            local_4 = 0xffffffff;
            *(uint32_t**)((uint8_t*)self + 4) = puVar10;
            if (*(int*)((uint8_t*)self + 0xc) != 0) {
                do {
                    int iVar6 = *(int*)((uint8_t*)self + 4);
                    int iVar3 = uVar9 * 4;
                    uint32_t* puVar4 = *(uint32_t**)(iVar6 + iVar3);
                    if (puVar4 != *(uint32_t**)((intptr_t)pvVar5 + uVar9 * 4)) {
                        if (puVar4 != nullptr) {
                            int32_t* piVar2 = (int32_t*)puVar4 + 1;
                            *piVar2 = *piVar2 + -1;
                            if (*piVar2 == 0) {
                                (**(void(**)(uint32_t))(*puVar4))(1);
                            }
                        }
                        int iVar7 = *(int*)((intptr_t)pvVar5 + iVar3);
                        *(int*)(iVar6 + iVar3) = iVar7;
                        if (iVar7 != 0) {
                            *(int*)(iVar7 + 4) = *(int*)(iVar7 + 4) + 1;
                        }
                    }
                    uVar9++;
                } while (uVar9 < *(uint32_t*)((uint8_t*)self + 0xc));
            }
            uVar9 = *(uint32_t*)((uint8_t*)self + 0xc);
            if (uVar9 < *(uint32_t*)((uint8_t*)self + 8)) {
                do {
                    int iVar3 = *(int*)((uint8_t*)self + 4);
                    uint32_t* puVar4 = *(uint32_t**)(iVar3 + uVar9 * 4);
                    local_4 = 2;
                    if (puVar4 != nullptr) {
                        int32_t* piVar2 = (int32_t*)puVar4 + 1;
                        *piVar2 = *piVar2 + -1;
                        if (*piVar2 == 0) {
                            (**(void(**)(uint32_t))(*puVar4))(1);
                        }
                        *(uint32_t*)(iVar3 + uVar9 * 4) = 0;
                    }
                    uVar9++;
                    local_4 = 0xffffffff;
                } while (uVar9 < *(uint32_t*)((uint8_t*)self + 8));
            }
        }
        if (pvVar5 != nullptr) {
            _eh_vector_destructor_iterator_(pvVar5, 4, *(int*)((intptr_t)pvVar5 + -4), (void*)FUN_005e4780);
            operator_delete__((void*)((intptr_t)pvVar5 + -4));
        }
    }
    ExceptionList = local_c;
}

// ---------------------------------------------------------------------------
// Additional extern declarations: helpers and globals referenced only by the
// definitions below. Names and addresses come from the assigned listings.
// ---------------------------------------------------------------------------
void operator_delete(void* p);
void FUN_005e44d0(void* self);
void FUN_005e47a0(void* self);
void FUN_00581300(uint32_t index, void* value);
void FUN_005c9b90(void* p, uint32_t v);
int* FUN_006b38d0();
uint32_t FUN_005e7870(uint32_t p);
int* FUN_005e7530();
void FUN_0051ac30(uint32_t p);
void FUN_0055a260(uint32_t v);
void FUN_00547610(uint32_t v);

extern uint32_t PTR_FUN_006c97c0;
extern uint32_t PTR_FUN_006c97c4;
extern uint32_t PTR_FUN_006c9814;
extern uint32_t PTR_FUN_006c9660;
extern uint32_t PTR_LAB_006fd148;
extern int32_t DAT_00727444;
extern uint32_t DAT_006dd2a4;

// 0x5e4410 — observed shape
// Install vtable PTR_FUN_006c97c0, destroy the element vector at +0x04, then
// conditional delete of the object itself when bit 0 of param_1 is set.
void FUN_005e4410(void* self, uint8_t param_1)
{
    uint32_t* d = (uint32_t*)self;
    void* pvVar1 = (void*)d[1];
    d[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c97c0;
    if (pvVar1 != nullptr) {
        _eh_vector_destructor_iterator_(pvVar1, 4, *(int32_t*)((uint8_t*)pvVar1 - 4), (void*)FUN_005e4780);
        operator_delete__((void*)((uint8_t*)pvVar1 - 4));
    }
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e4460 — observed shape
// Construct: install PTR_LAB_006fd148/PTR_FUN_006c97c4, bump DAT_00727444,
// zero fields 2..6 and 9..0x10, embed PTR_FUN_006c97c0 at +0x24, set
// +0x38 = 1 and zero +0x3c/+0x40.
void FUN_005e4460(void* self)
{
    uint32_t* d = (uint32_t*)self;
    d[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    d[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    d[2] = 0;
    d[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c97c4;
    d[0xb] = 0;
    d[0xc] = 0;
    d[0xd] = 0;
    d[10] = 0;
    d[9] = (uint32_t)(uintptr_t)&PTR_FUN_006c97c0;
    d[0xe] = 1;
    d[0xf] = 0;
    d[0x10] = 0;
}

// 0x5e4590 — observed shape
// Base destruction via FUN_005e44d0, conditional delete when bit 0 is set.
void FUN_005e4590(void* self, uint8_t param_1)
{
    FUN_005e44d0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e45b0 — observed shape
// Link the node param_1 into the list at +0x2c, growing the index vector first
// when the node index is out of range, then release the caller's reference.
void FUN_005e45b0(void* self, uint32_t* param_1)
{
    uint32_t* puVar3 = param_1;
    void* local_c = ExceptionList;
    ExceptionList = &local_c;
    if (param_1 != nullptr) {
        ExceptionList = &local_c;
        param_1[1] = param_1[1] + 1;
    }
    uint32_t uVar1 = param_1[3];
    if (*(uint32_t*)((uint8_t*)self + 0x2c) <= uVar1) {
        FUN_005e4230(self, *(int32_t*)((uint8_t*)self + 0x38) + uVar1);
    }
    FUN_00581300(uVar1, &param_1);
    int32_t iVar2 = (int32_t)puVar3[1];
    puVar3[1] = (uint32_t)(iVar2 - 1);
    if (iVar2 - 1 == 0) {
        (**(void(**)(uint32_t))(*puVar3))(1);
    }
    ExceptionList = local_c;
}

// 0x5e4640 — observed shape
// Copy the record at param_1 into the embedded channel object at +0x08,
// allocate the dispatch object at +0x34 and populate it through its vtable,
// then mirror scalar fields +0x0c/+0x31/+0x32.
void FUN_005e4640(void* self, uint32_t* param_1)
{
    void* pvStack_c = ExceptionList;
    ExceptionList = &pvStack_c;
    FUN_005c9b90((void*)((uint8_t*)self + 8), param_1[1]);
    int32_t iVar1 = FUN_00533c78(0x34);
    int* piVar2;
    if (iVar1 == 0) {
        piVar2 = nullptr;
    } else {
        piVar2 = FUN_006b38d0();
    }
    *(int**)((uint8_t*)self + 0x34) = piVar2;
    (**(void(**)(uint32_t))(*piVar2 + 0xc))(*param_1);
    (**(void(**)(uint32_t))(**(int**)((uint8_t*)self + 0x34) + 0x10))(param_1[2]);
    (**(void(**)(uint32_t))(**(int**)((uint8_t*)self + 0x34) + 0x44))(param_1[4]);
    (**(void(**)(uint32_t))(**(int**)((uint8_t*)self + 0x34) + 0x48))(param_1[5]);
    (**(void(**)(uint32_t))(**(int**)((uint8_t*)self + 0x34) + 0x4c))(param_1[6]);
    (**(void(**)(uint32_t))(**(int**)((uint8_t*)self + 0x34) + 0x58))(0);
    (**(void(**)(uint32_t))(**(int**)((uint8_t*)self + 0x34) + 0x5c))(1);
    (**(void(**)(void))(**(int**)((uint8_t*)self + 0x34) + 0x60))();
    (**(void(**)(uint32_t))(**(int**)((uint8_t*)self + 0x34) + 100))(param_1[7]);
    (**(void(**)(uint32_t))(**(int**)((uint8_t*)self + 0x34) + 0x68))(param_1[8]);
    *(uint32_t*)((uint8_t*)self + 0xc) = param_1[3];
    *(uint8_t*)((uint8_t*)self + 0x31) = *(uint8_t*)((uint8_t*)param_1 + 0x24);
    *(uint8_t*)((uint8_t*)self + 0x32) = *(uint8_t*)((uint8_t*)param_1 + 0x25);
    ExceptionList = nullptr;
}

// 0x5e4730 — observed shape
// Ask the dispatch object at +0x34 for its current value, pass it through the
// record's vtable slot 0x34, and store the result at +0x10.
void FUN_005e4730(void* self, int32_t* param_1)
{
    int32_t iVar1 = *param_1;
    uint32_t uVar2 = (**(uint32_t(**)())(**(int**)((uint8_t*)self + 0x34) + 4))();
    uVar2 = (**(uint32_t(**)(int32_t*, uint32_t))(iVar1 + 0x34))(param_1, uVar2);
    *(uint32_t*)((uint8_t*)self + 0x10) = uVar2;
}

// 0x5e4760 — observed shape
// Pop the head of the list at +0x2c, returning its payload (+0x08); 0 when
// the list is empty.
uint32_t FUN_005e4760(void* self)
{
    if (*(int32_t*)((uint8_t*)self + 0x2c) == 0) {
        return 0;
    }
    uint32_t* puVar1 = *(uint32_t**)((uint8_t*)self + 0x2c);
    *(uint32_t*)((uint8_t*)self + 0x2c) = *puVar1;
    return puVar1[2];
}

// 0x5e4780 — observed shape
// Element destructor: release the pointer stored in the slot the receiver
// points at. The earlier prototype in this file fixes the no-argument form,
// so the reconstructed body is named FUN_005e4780_recon.
void FUN_005e4780_recon(void** self)
{
    uint32_t* puVar2 = (uint32_t*)*self;
    if (puVar2 != nullptr) {
        int32_t* piVar1 = (int32_t*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (**(void(**)(uint32_t))(*puVar2))(1);
        }
    }
}

// 0x5e4850 — observed shape
// Lazily create the object at +0x18 from the selection at +0x10 and the
// provider at +0x14, configure it through its vtable, hand it to
// FUN_0051ac30 and publish the side channels. The earlier prototype in this
// file fixes a different shape for 0x5e4850, so this body is *_recon.
int32_t FUN_005e4850_recon(void* self, uint32_t param_1)
{
    void* local_c = ExceptionList;
    int32_t* piVar1 = (int32_t*)((uint8_t*)self + 0x18);
    if (*(int32_t*)((uint8_t*)self + 0x18) == 0) {
        if (*(int32_t*)((uint8_t*)self + 0x10) == 0) {
            return 0;
        }
        int32_t* piVar4;
        if (*(char*)((intptr_t)*(int32_t*)((uint8_t*)self + 0x14) + 0x50) == '\0') {
            piVar4 = nullptr;
        } else {
            piVar4 = *(int32_t**)((intptr_t)*(int32_t*)((uint8_t*)self + 0x14) + 0x4c);
        }
        ExceptionList = &local_c;
        int32_t iVar2 = (**(int32_t(**)(int32_t*, int32_t))(*piVar4 + 0xf8))(
            piVar4, *(int32_t*)((uint8_t*)self + 0x10));
        if (-1 < iVar2) {
            iVar2 = *piVar4;
            uint32_t uVar3 = FUN_005e7870(param_1);
            (**(void(**)(int32_t*, uint32_t))(iVar2 + 0x124))(piVar4, uVar3);
            int iStack_4 = FUN_00533c78(0x68);
            if (iStack_4 == 0) {
                uVar3 = 0;
            } else {
                uVar3 = (uint32_t)(uintptr_t)FUN_005e7530();
            }
            FUN_0051ac30(uVar3);
            *(int32_t*)((intptr_t)*piVar1 + 0x58) = (int32_t)(uintptr_t)self;
            uVar3 = (**(uint32_t(**)())(**(int**)((uint8_t*)self + 0x34) + 4))();
            FUN_0055a260(uVar3);
            FUN_00547610(*(uint32_t*)((uint8_t*)self + 0xc));
            *(uint8_t*)((intptr_t)*piVar1 + 0x20) = *(uint8_t*)((uint8_t*)self + 0x31);
            *(uint8_t*)((intptr_t)*piVar1 + 0x21) = *(uint8_t*)((uint8_t*)self + 0x32);
        }
    }
    ExceptionList = local_c;
    return *piVar1;
}

// 0x5e4950 — observed shape
// Allocate a list node through the factory at +0x1c, link it after the tail at
// +0x24, bump the count at +0x28 and flag categories 0x32..0x36 at +0x30.
void FUN_005e4950(void* self, uint32_t param_1)
{
    uint32_t* puVar2 = (uint32_t*)(**(uint32_t(**)(void))(
        *(int32_t*)((uint8_t*)self + 0x1c) + 4))();
    puVar2[2] = param_1;
    *puVar2 = 0;
    puVar2[1] = *(uint32_t*)((uint8_t*)self + 0x24);
    if (*(uint32_t**)((uint8_t*)self + 0x24) == nullptr) {
        *(uint32_t**)((uint8_t*)self + 0x20) = puVar2;
    } else {
        **(uint32_t**)((uint8_t*)self + 0x24) = (uint32_t)(uintptr_t)puVar2;
    }
    *(uint32_t**)((uint8_t*)self + 0x24) = puVar2;
    *(int32_t*)((uint8_t*)self + 0x28) = *(int32_t*)((uint8_t*)self + 0x28) + 1;
    int32_t iVar1 = *(int32_t*)((intptr_t)param_1 + 0xc);
    if (iVar1 == 0x32 || iVar1 == 0x33 || iVar1 == 0x34 ||
        iVar1 == 0x35 || iVar1 == 0x36) {
        *(uint8_t*)((uint8_t*)self + 0x30) = 1;
    }
}

// 0x5e49b0 — observed shape
// Rewind the cursor at +0x2c to the list head at +0x20 and advance it one
// node, returning the node payload; 0 when the list is empty.
uint32_t FUN_005e49b0(void* self)
{
    *(uint32_t*)((uint8_t*)self + 0x2c) = *(uint32_t*)((uint8_t*)self + 0x20);
    if (*(uint32_t*)((uint8_t*)self + 0x20) == 0) {
        return 0;
    }
    uint32_t* puVar1 = *(uint32_t**)((uint8_t*)self + 0x2c);
    *(uint32_t*)((uint8_t*)self + 0x2c) = *puVar1;
    return puVar1[2];
}

// 0x5e49d0 — observed shape
// Construct: install PTR_LAB_006fd148/PTR_FUN_006c9814, bump DAT_00727444,
// zero fields 2..6, 8..10 and 0xb, embed PTR_FUN_006c9660 at +0x1c, and zero
// the byte flags at +0x30/+0x31/+0x32.
void FUN_005e49d0(void* self)
{
    uint32_t* d = (uint32_t*)self;
    d[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    d[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    d[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c9814;
    d[2] = 0;
    d[3] = 0;
    d[4] = 0;
    d[5] = 0;
    d[6] = 0;
    d[10] = 0;
    d[8] = 0;
    d[9] = 0;
    d[7] = (uint32_t)(uintptr_t)&PTR_FUN_006c9660;
    d[0xb] = 0;
    *(uint8_t*)((uint8_t*)self + 0x30) = 0;
    *(uint8_t*)((uint8_t*)self + 0x31) = 0;
    *(uint8_t*)((uint8_t*)self + 0x32) = 0;
}

// 0x5e4a20 — observed shape
// Base destruction via FUN_005e47a0, conditional delete when bit 0 is set.
void FUN_005e4a20(void* self, uint8_t param_1)
{
    FUN_005e47a0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e4a40 — observed shape
// NEEDS_MANUAL: the listing stores through unaff_retaddr, a caller-supplied
// pointer visible only through the return-address slot; modeled as an explicit
// trailing parameter.
uint32_t FUN_005e4a40(int32_t* param_1, int32_t** unaff_retaddr)
{
    int32_t local_10[4];
    int32_t iVar1 = (**(int32_t(**)(int32_t*))(*param_1 + 0xc))(param_1);
    if (iVar1 < 0) {
        return 0;
    }
    *unaff_retaddr = local_10;
    *param_1 = local_10[0];
    return 1;
}

// 0x5e4a80 — observed shape
// Receiver arrives in ESI (unaff_ESI) and is modeled as the explicit self.
// NEEDS_MANUAL: the listing initializes piVar4 to null and then dispatches
// through its vtable slot 0x100; the real receiver is not recovered.
bool FUN_005e4a80(void* self, uint32_t* param_1)
{
    int32_t* selfv = (int32_t*)self;
    uint32_t* puVar5 = param_1;
    int32_t* piVar6 = (int32_t*)&DAT_006dd2a4;
    int32_t iVar1 = (**(int32_t(**)(uint32_t*, uint32_t*, void*))(*param_1))(
        param_1, (uint32_t*)&DAT_006dd2a4, (void*)&param_1);
    if (iVar1 < 0) {
        return true;
    }
    int32_t* piVar4 = nullptr;
    uint32_t uVar2 = (**(uint32_t(**)(int32_t*, uint32_t, void*))(*piVar6 + 0x24))(
        piVar6, 0, (void*)&param_1);
    uint32_t uVar3 = (**(uint32_t(**)(int32_t*, uint32_t*))(*selfv + 0x34))(selfv, puVar5);
    iVar1 = (**(int32_t(**)(int32_t*, uint32_t, uint32_t))(*piVar4 + 0x100))(
        piVar4, uVar2, uVar3);
    (**(void(**)(int32_t*))(*selfv + 8))(selfv);
    return iVar1 != 0;
}
