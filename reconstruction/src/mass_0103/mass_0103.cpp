#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers / globals referenced by the listings below.
extern void FUN_0052a720_recon();
extern void FUN_0052c640_recon();
extern void* DAT_008ca53c;
extern void* PTR_LAB_007129fc;
extern void* PTR_FUN_00712a2c;
extern void* PTR_LAB_00712a20;
extern void* PTR_FUN_00712a14;
extern void* PTR_FUN_007129f8;
extern uint32_t DAT_00727444;
extern uint32_t DAT_0071778c;
extern uint32_t DAT_00717790;
extern uint32_t DAT_00717794;
extern uint32_t DAT_00717798;

// 0x51ffd0 — observed shape
// Receiver in ESI; initializes fields at +0x19..+0x54, constructs std::string at +0x54,
// calls helper twice, then sets floats 0xbf800000(-1.0), 0x42200000(40.0), 0x7f7fffff, 0xff7fffff.
void FUN_0051ffd0(void* self) {
    char* s = (char*)self;
    *(uint32_t*)(s + 0x38) = 0;
    *(uint32_t*)(s + 0x3c) = 0;
    *(uint32_t*)(s + 0x40) = 0;
    *(uint32_t*)(s + 0x48) = 0;
    *(uint32_t*)(s + 0x4c) = 0;
    *(uint32_t*)(s + 0x50) = 0;
    // std::string default-construction at +0x54 (opaque, modeled as helper-free construction omitted => use extern if available)
    FUN_0052a720_recon();
    FUN_0052a720_recon();
    if (*(char*)(s + 0x19) != '\0') {
        *(char*)(s + 0x19) = 0;
    }
    *(uint8_t*)(s + 0x21) = 0;
    *(uint8_t*)(s + 0x20) = 0;
    *(uint32_t*)(s + 0x28) = 0;
    *(uint32_t*)(s + 0x1c) = 0xbf800000;
    *(uint32_t*)(s + 0x24) = 0x42200000;
    *(uint32_t*)(s + 0x2c) = 0x7f7fffff;
    *(uint32_t*)(s + 0x30) = 0xff7fffff;
}

// 0x520050 — observed shape
// Tears down singleton DAT_008ca53c: destroys string at +0x54, frees buffers at +0x48 and +0x38, frees object.
void FUN_00520050(void) {
    void* pvVar1 = DAT_008ca53c;
    if (DAT_008ca53c != nullptr) {
        // string destruction at +0x54 omitted (no extern modeled)
        if (*(void**)((char*)pvVar1 + 0x48) != nullptr) {
            operator delete(*(void**)((char*)pvVar1 + 0x48));
        }
        *(uint32_t*)((char*)pvVar1 + 0x48) = 0;
        *(uint32_t*)((char*)pvVar1 + 0x4c) = 0;
        *(uint32_t*)((char*)pvVar1 + 0x50) = 0;
        if (*(void**)((char*)pvVar1 + 0x38) != nullptr) {
            operator delete(*(void**)((char*)pvVar1 + 0x38));
        }
        *(uint32_t*)((char*)pvVar1 + 0x38) = 0;
        *(uint32_t*)((char*)pvVar1 + 0x3c) = 0;
        *(uint32_t*)((char*)pvVar1 + 0x40) = 0;
        operator delete(pvVar1);
    }
}

// 0x5200b0 — observed shape
// Receiver in EAX, param_1 is timed record; if flags at +0x19/+0x21 set, initialize/increment counters and timestamp via timeGetTime.
void FUN_005200b0(int param_1) {
    float fVar1;
    DWORD DVar2;
    // self (in_EAX) flags checked via param_1's companion object is not available; EAX receiver preserved via globals? -- listing reads in_EAX+0x19/0x21 but no self param in signature. Model as extern self forwarded below.
    extern void* g_self_5200b0;
    if ((*(char*)((char*)g_self_5200b0 + 0x19) != '\0') && (*(char*)((char*)g_self_5200b0 + 0x21) == '\0')) {
        if (*(char*)(param_1 + 0x124) == '\0') {
            *(uint32_t*)(param_1 + 0x104) = 1;
            *(uint32_t*)(param_1 + 0x100) = 1;
            *(uint64_t*)(param_1 + 0x110) = 0;
            DVar2 = timeGetTime();
            fVar1 = (float)(int)DVar2;
            if ((int)DVar2 < 0) {
                fVar1 = fVar1 + 4.2949673e+09f;
            }
            *(double*)(param_1 + 0x108) = (double)fVar1;
            *(uint64_t*)(param_1 + 0x118) = 0;
            *(uint32_t*)(param_1 + 0x120) = 0;
            *(uint8_t*)(param_1 + 0x124) = 1;
            FUN_0052c640_recon();
        } else {
            *(int*)(param_1 + 0x104) = *(int*)(param_1 + 0x104) + 1;
            *(int*)(param_1 + 0x100) = *(int*)(param_1 + 0x100) + 1;
            if (*(int*)(param_1 + 0x104) == 1) {
                DVar2 = timeGetTime();
                fVar1 = (float)(int)DVar2;
                if ((int)DVar2 < 0) {
                    fVar1 = fVar1 + 4.2949673e+09f;
                }
                *(double*)(param_1 + 0x108) = (double)fVar1;
                return;
            }
        }
    }
}

// 0x520190 — observed shape
// Receiver in EDI; decrements counter at param+0x104, scans array at self+0x38 for earliest start time, accumulates duration at +0x118/+0x110.
void FUN_00520190(int param_1) {
    extern void* g_self_520190;
    int iVar1;
    float fVar2;
    DWORD DVar3;
    uint32_t uVar4;
    int iVar5;
    uint32_t uVar6;
    int local_10 = 0;
    if (((*(char*)((char*)g_self_520190 + 0x19) != '\0') && (*(char*)((char*)g_self_520190 + 0x21) == '\0')) &&
        (*(char*)(param_1 + 0x124) != '\0')) {
        uVar6 = 0xffffffff;
        DVar3 = timeGetTime();
        fVar2 = (float)(int)DVar3;
        if ((int)DVar3 < 0) {
            fVar2 = fVar2 + 4.2949673e+09f;
        }
        *(int*)(param_1 + 0x104) = *(int*)(param_1 + 0x104) + -1;
        if (*(int*)(param_1 + 0x128) == -1) {
            iVar5 = 0;
            for (uVar4 = 0;
                 (*(int*)((char*)g_self_520190 + 0x38) != 0 &&
                  (iVar1 = *(int*)((char*)g_self_520190 + 0x38),
                  uVar4 < (uint32_t)((*(int*)((char*)g_self_520190 + 0x3c) - iVar1) >> 2))); uVar4 = uVar4 + 1) {
                if ((0 < *(int*)(*(int*)(iVar5 + iVar1) + 0x104)) &&
                    ((local_10 = local_10 + 1, (int)uVar6 < 0 ||
                     (*(double*)(*(int*)(iVar1 + uVar6 * 4) + 0x108) <=
                      *(double*)(*(int*)(iVar5 + iVar1) + 0x108))))) {
                    uVar6 = uVar4;
                }
                iVar5 = iVar5 + 4;
            }
            *(uint32_t*)(param_1 + 0x128) = uVar6;
            *(int*)(param_1 + 0x120) = local_10;
            if (-1 < (int)uVar6) {
                iVar5 = *(int*)(*(int*)((char*)g_self_520190 + 0x38) + uVar6 * 4);
                *(double*)(iVar5 + 0x118) =
                    (double)((fVar2 - (float)*(double*)(param_1 + 0x108)) +
                             (float)*(double*)(iVar5 + 0x118));
            }
        }
        *(double*)(param_1 + 0x110) =
            (double)((fVar2 - (float)*(double*)(param_1 + 0x108)) +
                     (float)*(double*)(param_1 + 0x110));
    }
}

// 0x5202b0 — observed shape
// Vtable/instance initializer on ESI; sets slots 0..0x1f, decrements refcount at [0x11], copies globals DAT_0071778c..98 into slots 0xd..0x10.
void FUN_005202b0(void) {
    extern void* g_self_5202b0;
    int* piVar1;
    uint32_t* puVar2;
    uint32_t uVar4;
    uint32_t uVar3;
    uint32_t uVar5;
    uint32_t* unaff_ESI = (uint32_t*)g_self_5202b0;
    unaff_ESI[1] = 0;
    unaff_ESI[2] = (uint32_t)PTR_LAB_007129fc;
    unaff_ESI[7] = 0;
    unaff_ESI[8] = 0;
    unaff_ESI[9] = 0;
    unaff_ESI[3] = 0;
    unaff_ESI[4] = 0x10;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[0] = (uint32_t)PTR_FUN_00712a2c;
    unaff_ESI[2] = (uint32_t)PTR_LAB_00712a20;
    unaff_ESI[0xd] = 0;
    unaff_ESI[0xe] = 0;
    unaff_ESI[0xf] = 0;
    unaff_ESI[0x10] = 0;
    unaff_ESI[0x11] = 0;
    unaff_ESI[0x18] = 0;
    unaff_ESI[0x16] = 0;
    unaff_ESI[0x17] = 0;
    unaff_ESI[0x15] = (uint32_t)PTR_FUN_00712a14;
    DAT_00727444 = DAT_00727444 + 1;
    unaff_ESI[0x19] = (uint32_t)PTR_FUN_007129f8;
    unaff_ESI[0x1b] = 0;
    unaff_ESI[0x1e] = 1;
    unaff_ESI[0x1c] = 0;
    unaff_ESI[0x1d] = 0;
    unaff_ESI[0x1a] = 0;
    puVar2 = (uint32_t*)unaff_ESI[0x11];
    if (puVar2 != nullptr) {
        piVar1 = (int*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (__cdecl *deleter_fn)(int);
            (*(deleter_fn)puVar2[0])(1);
        }
        unaff_ESI[0x11] = 0;
    }
    uVar4 = DAT_00717794;
    uVar3 = DAT_00717790;
    unaff_ESI[0xd] = DAT_0071778c;
    uVar5 = DAT_00717798;
    unaff_ESI[0xe] = uVar3;
    unaff_ESI[0xf] = uVar4;
    unaff_ESI[0xb] = 0;
    *(uint8_t*)((char*)unaff_ESI + 0xc) = 0;
    unaff_ESI[0x14] = 0;
    *(uint8_t*)((char*)unaff_ESI + 0x31) = 0;
    *(uint8_t*)((char*)unaff_ESI + 0x32) = 0;
    unaff_ESI[0x13] = 0;
    unaff_ESI[0x1f] = 0;
    unaff_ESI[10] = 0xffffffff;
    unaff_ESI[0x10] = uVar5;
}

// ---------------------------------------------------------------------------
// Additional externs referenced only by the appended reconstructions.
extern void* FUN_00533c78(int size);
extern void* thunk_FUN_00533c78(int size);
extern void* FUN_00538680(void);
extern void FUN_00533d10(uint32_t obj, int flag);
extern void FUN_00534130(void);
extern void FUN_00534350(void);
extern uint32_t FUN_0051dd80(void* a, void* b);
extern void* FUN_0051e290(void);
extern void FUN_0051e5e0(void* p);
extern void* FUN_00533db0(int n);
extern void FUN_004fd880(void* p);
extern void FUN_00540c50(void* p);
extern void FUN_004aac50(void* p);
extern void FUN_00534a90(void* p, int n);
extern void FUN_00506040(uint32_t a, float b, int c, int d, float e);
extern void FUN_00506e60(int a, int b, int c, int d, int e, float f, int g);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);

extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_0070bf4c;
extern void* PTR_LAB_00712a08;
extern void* PTR_FUN_00712a14;
extern void* PTR_FUN_00712a58;
extern void* DAT_00727430;
extern void* DAT_00727434;
extern void* DAT_00727438;
extern void* DAT_00727560;
extern void* DAT_00727598;
extern void* DAT_007278a8;
extern void* DAT_008cacd0;

typedef void (__cdecl *PIRATES_DTOR)(int);

// 0x5206a0 — observed shape
// Receiver in ECX: walks the child list of param_1 (vtable+4), matches the node
// tag DAT_007278a8, links a new node into self+0x54/0x58/0x5c/0x60, then
// recursively descends into param_1's child array at +0x2e..+0x30.
void FUN_005206a0(void* self, int* param_1) {
    uint32_t* u = (uint32_t*)self;
    uint32_t* piVar1;
    int iVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    uint32_t uVar5;

    if (param_1 == nullptr) {
        return;
    }
    puVar3 = (uint32_t*)(*(void*(__cdecl**)(void))(*param_1 + 4))();
    if (puVar3 == nullptr) {
        return;
    }
    while (puVar3 != (uint32_t*)&DAT_00727560) {
        puVar3 = (uint32_t*)puVar3[1];
        if (puVar3 == nullptr) {
            return;
        }
    }
    puVar3 = (uint32_t*)param_1[0x34];
    while (puVar3 != nullptr) {
        piVar1 = (uint32_t*)puVar3[2];
        puVar3 = (uint32_t*)*puVar3;
        if (piVar1 != nullptr) {
            puVar4 = (uint32_t*)(*(void*(__cdecl**)(void))(*piVar1 + 4))();
            for (; puVar4 != nullptr; puVar4 = (uint32_t*)puVar4[1]) {
                if (puVar4 == (uint32_t*)&DAT_007278a8) {
                    puVar4 = (uint32_t*)(*(void*(__cdecl**)(void))(*(uint32_t*)((char*)self + 0x54) + 4))();
                    puVar4[2] = (uint32_t)piVar1;
                    *puVar4 = 0;
                    puVar4[1] = *(uint32_t*)((char*)self + 0x5c);
                    if (*(uint32_t*)((char*)self + 0x5c) == 0) {
                        *(uint32_t*)((char*)self + 0x58) = (uint32_t)puVar4;
                    } else {
                        **(uint32_t**)((char*)self + 0x5c) = (uint32_t)puVar4;
                    }
                    *(uint32_t*)((char*)self + 0x5c) = (uint32_t)puVar4;
                    *(int*)((char*)self + 0x60) = *(int*)((char*)self + 0x60) + 1;
                    break;
                }
            }
        }
    }
    uVar5 = 0;
    if (param_1[0x30] != 0) {
        do {
            iVar2 = *(int*)(param_1[0x2e] + uVar5 * 4);
            if (iVar2 != 0) {
                FUN_005206a0(self, (int*)iVar2);
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < (uint32_t)param_1[0x30]);
    }
}

// 0x5208f0 — observed shape
// Receiver in EAX: releases the object at +0x44 through its vtable slot +0x74,
// then releases the refcounted pair at +0x50 and destroys the member at +0x48.
void FUN_005208f0(void* self) {
    int* piVar1;
    uint32_t* piVar2;
    int iVar3;
    uint32_t* puVar4;
    uint32_t* local_4 = nullptr;

    piVar2 = *(uint32_t**)(*(int*)((char*)self + 0x44) + 0x24);
    if (piVar2 != nullptr) {
        (*(void(__cdecl**)(uint32_t**, uint32_t))(*piVar2 + 0x74))(&local_4, *(uint32_t*)((char*)self + 0x44));
        if ((local_4 != nullptr) &&
            (iVar3 = (int)local_4[1], local_4[1] = (uint32_t)(iVar3 + -1), iVar3 - 1 == 0)) {
            ((PIRATES_DTOR)*local_4)(1);
        }
    }
    puVar4 = *(uint32_t**)((char*)self + 0x44);
    if (puVar4 != nullptr) {
        piVar1 = (int*)puVar4 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            ((PIRATES_DTOR)*puVar4)(1);
        }
        *(uint32_t*)((char*)self + 0x44) = 0;
    }
    piVar2 = *(uint32_t**)((char*)self + 0x50);
    if (piVar2 != nullptr) {
        puVar4 = (uint32_t*)*piVar2;
        if (puVar4 != nullptr) {
            piVar1 = (int*)puVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((PIRATES_DTOR)*puVar4)(1);
            }
            *piVar2 = 0;
        }
        puVar4 = (uint32_t*)piVar2[1];
        if (puVar4 != nullptr) {
            piVar1 = (int*)puVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((PIRATES_DTOR)*puVar4)(1);
            }
        }
        puVar4 = (uint32_t*)*piVar2;
        if (puVar4 != nullptr) {
            piVar1 = (int*)puVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((PIRATES_DTOR)*puVar4)(1);
            }
        }
        operator_delete(piVar2);
        *(uint32_t*)((char*)self + 0x50) = 0;
    }
    FUN_0051e5e0((char*)self + 0x48);
}

// 0x520bd0 — observed shape
// Receiver in ESI: allocates self+0x74 records of 0x28 bytes at +0x7c, clears
// each 10-dword record, then copies pos/color/scale/duration fields from the
// entry pointers stored at self+0x68.
void FUN_00520bd0(void* self) {
    int iVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t* puVar4;

    iVar3 = *(int*)((char*)self + 0x74);
    iVar1 = (int)(intptr_t)thunk_FUN_00533c78(iVar3 * 0x28);
    uVar2 = 0;
    if (iVar1 == 0) {
        iVar1 = 0;
    } else if (-1 < iVar3 + -1) {
        puVar4 = (uint32_t*)(iVar1 + 0x14);
        do {
            puVar4[-5] = 0;
            puVar4[-4] = 0;
            puVar4[-3] = 0;
            puVar4[-2] = 0;
            puVar4[-1] = 0;
            *puVar4 = 0;
            puVar4[1] = 0;
            puVar4[2] = 0;
            puVar4[3] = 0;
            puVar4 = puVar4 + 10;
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
    }
    *(int*)((char*)self + 0x7c) = iVar1;
    if (*(int*)((char*)self + 0x74) != 0) {
        iVar3 = 0;
        do {
            iVar1 = *(int*)(*(int*)((char*)self + 0x68) + uVar2 * 4);
            puVar4 = (uint32_t*)(*(int*)((char*)self + 0x7c) + iVar3);
            *puVar4 = *(uint32_t*)(iVar1 + 0x24);
            puVar4[1] = *(uint32_t*)(iVar1 + 0x28);
            puVar4[2] = *(uint32_t*)(iVar1 + 0x2c);
            iVar1 = *(int*)(*(int*)((char*)self + 0x68) + uVar2 * 4);
            puVar4 = (uint32_t*)(*(int*)((char*)self + 0x7c) + 0xc + iVar3);
            *puVar4 = *(uint32_t*)(iVar1 + 0x30);
            puVar4[1] = *(uint32_t*)(iVar1 + 0x34);
            puVar4[2] = *(uint32_t*)(iVar1 + 0x38);
            iVar1 = *(int*)(*(int*)((char*)self + 0x68) + uVar2 * 4);
            puVar4 = (uint32_t*)(*(int*)((char*)self + 0x7c) + 0x18 + iVar3);
            *puVar4 = *(uint32_t*)(iVar1 + 0x48);
            puVar4[1] = *(uint32_t*)(iVar1 + 0x4c);
            puVar4[2] = *(uint32_t*)(iVar1 + 0x50);
            *(uint32_t*)(*(int*)((char*)self + 0x7c) + 0x24 + iVar3) =
                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x68) + uVar2 * 4) + 0x58);
            uVar2 = uVar2 + 1;
            iVar3 = iVar3 + 0x28;
        } while (uVar2 < *(uint32_t*)((char*)self + 0x74));
    }
}

// 0x5209b0 — observed shape
// Receiver in EAX: stores the scale factor at each child's +0x58 and bumps its
// +0x5c counter; at scale >= 1.0 releases the object at +0x4c, otherwise lazily
// creates it (0x24 bytes, vtable PTR_FUN_0070bf4c, flags 0xec).
uint32_t FUN_005209b0(void* self, float param_1) {
    uint32_t* u = (uint32_t*)self;
    int* piVar1;
    uint8_t* pbVar2;
    int iVar3;
    uint32_t* puVar4;
    uint32_t uVar5;

    if (*(int*)((char*)self + 0x7c) == 0) {
        FUN_00520bd0(self);
    }
    uVar5 = 0;
    if (*(int*)((char*)self + 0x74) != 0) {
        do {
            iVar3 = *(int*)(*(int*)((char*)self + 0x68) + uVar5 * 4);
            *(float*)(iVar3 + 0x58) = param_1;
            *(int*)(iVar3 + 0x5c) = *(int*)(iVar3 + 0x5c) + 1;
            uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint32_t*)((char*)self + 0x74));
    }
    if (1.0f <= param_1) {
        if (*(int*)((char*)self + 0x4c) != 0) {
            // Helper receives an out-parameter slot; the listing reuses the
            // parameter variable for that smart-pointer temporary.
            void* temp = nullptr;
            FUN_00534a90(&temp, 0);
            if ((temp != nullptr) &&
                (iVar3 = ((int*)temp)[1], ((int*)temp)[1] = iVar3 + -1, iVar3 - 1 == 0)) {
                ((PIRATES_DTOR)*(uint32_t*)temp)(1);
            }
            *(uint32_t*)((char*)self + 0x4c) = 0;
            FUN_00534130();
        }
        return 0;
    }
    if (*(int*)((char*)self + 0x4c) == 0) {
        puVar4 = (uint32_t*)FUN_00533c78(0x24);
        if (puVar4 == nullptr) {
            puVar4 = nullptr;
        } else {
            FUN_00540c50(puVar4);
            *puVar4 = (uint32_t)&PTR_FUN_0070bf4c;
            *(uint16_t*)((char*)puVar4 + 0x20) = 0xec;
            *(uint8_t*)((char*)puVar4 + 0x22) = 0;
        }
        *(uint32_t*)((char*)self + 0x4c) = (uint32_t)puVar4;
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
        {
            uint32_t* temp = puVar4;
            FUN_004aac50(&temp);
        }
        if (puVar4 != nullptr) {
            piVar1 = (int*)puVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((PIRATES_DTOR)*puVar4)(1);
            }
        }
        FUN_00534130();
    }
    pbVar2 = (uint8_t*)(*(int*)((char*)self + 0x4c) + 0x20);
    *pbVar2 = *pbVar2 | 1;
    *(uint16_t*)(*(int*)((char*)self + 0x4c) + 0x20) =
        *(uint16_t*)(*(int*)((char*)self + 0x4c) + 0x20) & 0xffed | 0xc;
    *(uint16_t*)(*(int*)((char*)self + 0x4c) + 0x20) =
        *(uint16_t*)(*(int*)((char*)self + 0x4c) + 0x20) & 0xfeff | 0xe0;
    return 0;
}

// 0x520b00 — observed shape
// Receiver in ECX: if param_1 carries the DAT_00727598 tag, resolves behavior 3
// and registers it unless already present in self+0x68; then walks the
// DAT_00727560 child list and recurses into the child array.
void FUN_00520b00(void* self, int* param_1) {
    bool bVar1;
    int* piVar2;
    uint32_t* puVar3;
    int iVar4;
    uint32_t uVar5;

    piVar2 = param_1;
    if (param_1 == nullptr) {
        return;
    }
    puVar3 = (uint32_t*)(*(void*(__cdecl**)(void))(*param_1 + 4))();
    if (puVar3 == nullptr) {
        goto LAB_00520b6e;
    }
LAB_00520b20:
    if (puVar3 != (uint32_t*)&DAT_00727598) {
        goto code_r0x00520b27;
    }
    param_1 = (int*)FUN_00533db0(3);
    if (param_1 != nullptr) {
        iVar4 = *(int*)((char*)self + 0x74);
        bVar1 = false;
        if (iVar4 != 0) {
            puVar3 = *(uint32_t**)((char*)self + 0x68);
            do {
                if ((int*)*puVar3 == param_1) {
                    bVar1 = true;
                }
                puVar3 = puVar3 + 1;
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            if (bVar1) {
                goto LAB_00520b6e;
            }
        }
        FUN_004fd880(&param_1);
    }
LAB_00520b6e:
    puVar3 = (uint32_t*)(*(void*(__cdecl**)(void))(*piVar2 + 4))();
    if (puVar3 != nullptr) {
        while (puVar3 != (uint32_t*)&DAT_00727560) {
            puVar3 = (uint32_t*)puVar3[1];
            if (puVar3 == nullptr) {
                return;
            }
        }
        uVar5 = 0;
        if (piVar2[0x30] != 0) {
            do {
                iVar4 = *(int*)(piVar2[0x2e] + uVar5 * 4);
                if (iVar4 != 0) {
                    FUN_00520b00(self, (int*)iVar4);
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < (uint32_t)piVar2[0x30]);
        }
    }
    return;
code_r0x00520b27:
    puVar3 = (uint32_t*)puVar3[1];
    if (puVar3 == nullptr) {
        goto LAB_00520b6e;
    }
    goto LAB_00520b20;
}

// 0x520cf0 — observed shape
// Receiver in ECX: resets vtable to PTR_FUN_007129f8, deletes the owned buffer
// at +4 via the array-delete helper, and conditionally frees the object.
void FUN_00520cf0(void* self, uint8_t param_1) {
    uint32_t* u = (uint32_t*)self;

    *u = (uint32_t)&PTR_FUN_007129f8;
    operator_delete__((void*)u[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(u);
    }
}

// 0x520d40 — observed shape
// Receiver in ECX (3 floats): writes self[0..2] * param_2 into param_1[0..2].
void FUN_00520d40(void* self, float* param_1, float param_2) {
    float* f = (float*)self;
    float fVar1 = f[1];
    float fVar2 = f[2];

    *param_1 = *f * param_2;
    param_1[1] = fVar1 * param_2;
    param_1[2] = fVar2 * param_2;
}

// 0x520da0 — observed shape
// Receiver in ECX (quaternion): expands to a 3x3 rotation matrix in param_1.
void FUN_00520da0(void* self, float* param_1) {
    float* q = (float*)self;
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float fVar11;

    fVar8 = q[1] + q[1];
    fVar10 = q[2] + q[2];
    fVar11 = q[3] + q[3];
    fVar9 = fVar8 * *q;
    fVar1 = *q;
    fVar2 = *q;
    fVar8 = fVar8 * q[1];
    fVar3 = q[1];
    fVar4 = q[1];
    fVar5 = q[2];
    fVar6 = q[2];
    fVar7 = q[3];
    *param_1 = 1.0f - (fVar11 * fVar7 + fVar10 * fVar5);
    param_1[3] = fVar10 * fVar3 + fVar11 * fVar2;
    param_1[6] = fVar11 * fVar4 - fVar10 * fVar1;
    param_1[1] = fVar10 * fVar3 - fVar11 * fVar2;
    param_1[4] = 1.0f - (fVar11 * fVar7 + fVar8);
    param_1[7] = fVar9 + fVar11 * fVar6;
    param_1[2] = fVar11 * fVar4 + fVar10 * fVar1;
    param_1[5] = fVar11 * fVar6 - fVar9;
    param_1[8] = 1.0f - (fVar10 * fVar5 + fVar8);
}

// 0x520e90 — observed shape
// Receiver in ECX: sets vtable PTR_FUN_00712a14, calls slot +8 for every node of
// the linked list at +4, clears the three bookkeeping fields, then swaps the
// vtable to PTR_LAB_00712a08.
void FUN_00520e90(void* self) {
    uint32_t* u = (uint32_t*)self;
    uint32_t* puVar1;
    uint32_t* puVar2;

    *u = (uint32_t)&PTR_FUN_00712a14;
    puVar2 = (uint32_t*)u[1];
    while (puVar2 != nullptr) {
        puVar1 = (uint32_t*)*puVar2;
        (*(void(__cdecl**)(uint32_t*))((uint32_t)*u + 8))(puVar2);
        puVar2 = puVar1;
    }
    u[3] = 0;
    u[1] = 0;
    u[2] = 0;
    *u = (uint32_t)&PTR_LAB_00712a08;
}

// 0x520fa0 — observed shape
// Receiver in EAX (header bytes) and ESI (FILE*): emits the 0x14-byte record
// header field by field; returns 0xd when the final 1-byte write fails.
uint8_t FUN_00520fa0(void* data, FILE* f) {
    size_t sVar1;

    fwrite(data, 1, 1, f);
    fwrite((void*)((char*)data + 1), 1, 1, f);
    fwrite((void*)((char*)data + 2), 1, 1, f);
    fwrite((void*)((char*)data + 4), 2, 1, f);
    fwrite((void*)((char*)data + 6), 2, 1, f);
    fwrite((void*)((char*)data + 8), 1, 1, f);
    fwrite((void*)((char*)data + 10), 2, 1, f);
    fwrite((void*)((char*)data + 0xc), 2, 1, f);
    fwrite((void*)((char*)data + 0xe), 2, 1, f);
    fwrite((void*)((char*)data + 0x10), 2, 1, f);
    fwrite((void*)((char*)data + 0x12), 1, 1, f);
    sVar1 = fwrite((void*)((char*)data + 0x13), 1, 1, f);
    return (uint8_t)(-(int)(sVar1 != 1) & 0xd);
}

// 0x520ef0 — observed shape
// Filename in EAX, element counts in ECX/EBX: opens the file for writing,
// serializes the register-passed header via FUN_00520fa0, writes one block of
// (ecx_count * param_3 * ebx_count) >> 3 units, and reports 0xd on failure.
uint32_t FUN_00520ef0(char* filename, void* header, void* param_2, int param_3,
                      int ecx_count, int ebx_count) {
    FILE* _File;
    int iVar1;
    size_t sVar2;

    _File = fopen(filename, "wb");
    iVar1 = (int)FUN_00520fa0(header, _File);
    if (iVar1 == 0) {
        sVar2 = fwrite(param_2, (uint32_t)(ecx_count * param_3 * ebx_count) >> 3, 1, _File);
        if (sVar2 == 1) {
            fclose(_File);
            return 0;
        }
    }
    fclose(_File);
    return 0xd;
}

// 0x521040 — observed shape
// EBX mode and EDI receiver: mode 1 clears +0x290 on every node of the +0x2a0
// list and restores its +0x294 parameter; mode 0 early-outs when already 0.
// Then, if the receiver's mode differs, store it and re-parameterize the slot
// at 0x290 + mode*4.
void FUN_00521040(void* self, int param_1) {
    uint32_t* puVar1;
    int iVar2;

    if (param_1 == 0) {
        if (*(int*)((char*)self + 0x290) != 0) {
            return;
        }
    } else if (param_1 == 1) {
        puVar1 = *(uint32_t**)((char*)self + 0x2a0);
        while (puVar1 != nullptr) {
            iVar2 = (int)puVar1[2];
            puVar1 = (uint32_t*)*puVar1;
            if (*(int*)(iVar2 + 0x290) != 0) {
                *(uint32_t*)(iVar2 + 0x290) = 0;
                FUN_00506040(*(uint32_t*)(iVar2 + 0x294), 1.0f, 0, 0, 1.0f);
            }
        }
    }
    if (*(int*)((char*)self + 0x290) != param_1) {
        *(int*)((char*)self + 0x290) = param_1;
        FUN_00506040(*(uint32_t*)((char*)self + 0x290 + param_1 * 4), 1.0f, 0, 0, 1.0f);
    }
}

// 0x5212a0 — observed shape
// Receiver in ESI: initializes the base at 0xffffffff with unit alpha, installs
// vtable PTR_FUN_00712a58, clears the +0x294..+0x2a0 block and points +0x2cc at
// DAT_008cacd0.
void FUN_005212a0(void* self) {
    uint32_t* u = (uint32_t*)self;

    FUN_00506e60(0xffffffff, 0, 0, 0, 0, 1.0f, 0);
    *u = (uint32_t)&PTR_FUN_00712a58;
    u[0xa5] = 0;
    u[0xa6] = 0;
    u[0xa7] = 0;
    u[0xa8] = 0;
    u[0xb3] = (uint32_t)&DAT_008cacd0;
}

// 0x5203b0 — observed shape
// Receiver in ESI: full destructor. Rebinds vtables, releases each of the three
// refcounted children of the container at +0x50, deletes it, frees the buffer at
// +0x7c, tears down the +0x48 member, releases the child at +0x44, destroys the
// list at +0x11, resets the trailing vtables and decrements DAT_00727444.
void FUN_005203b0(void* self) {
    uint32_t* u = (uint32_t*)self;
    uint32_t* piVar1;
    int* piVar2;
    uint32_t* puVar3;

    piVar2 = (int*)u[0x14];
    u[0] = (uint32_t)&PTR_FUN_00712a2c;
    u[2] = (uint32_t)&PTR_LAB_00712a20;
    if (piVar2 != nullptr) {
        puVar3 = (uint32_t*)*piVar2;
        if (puVar3 != nullptr) {
            piVar1 = puVar3 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                ((PIRATES_DTOR)*puVar3)(1);
            }
            *piVar2 = 0;
        }
        puVar3 = (uint32_t*)piVar2[1];
        if (puVar3 != nullptr) {
            piVar1 = puVar3 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                ((PIRATES_DTOR)*puVar3)(1);
            }
        }
        puVar3 = (uint32_t*)*piVar2;
        if (puVar3 != nullptr) {
            piVar1 = puVar3 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                ((PIRATES_DTOR)*puVar3)(1);
            }
        }
        operator_delete(piVar2);
        u[0x14] = 0;
    }
    if ((void*)u[0x1f] != nullptr) {
        operator_delete((void*)u[0x1f]);
        u[0x1f] = 0;
    }
    FUN_005208f0(self);
    puVar3 = (uint32_t*)u[0x11];
    if (puVar3 != nullptr) {
        piVar2 = (int*)puVar3 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) {
            ((PIRATES_DTOR)*puVar3)(1);
        }
        u[0x11] = 0;
    }
    u[0x19] = (uint32_t)&PTR_FUN_007129f8;
    operator_delete__((void*)u[0x1a]);
    // The listing does not make the ECX receiver explicit; it is the base
    // object being torn down (the following lines restore its vtable slot).
    FUN_00520e90(self);
    puVar3 = (uint32_t*)u[0x11];
    if (puVar3 != nullptr) {
        piVar2 = (int*)puVar3 + 1;
        *piVar2 = *piVar2 - 1;
        if (*piVar2 == 0) {
            ((PIRATES_DTOR)*puVar3)(1);
        }
    }
    u[2] = (uint32_t)&PTR_LAB_007129fc;
    u[0] = (uint32_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 - 1;
}

// 0x520490 — observed shape
// Receiver in ECX: clears the pending-entry array at +0x68, snapshots the
// current child at +0x44 (mode/flags/timing fields), resets the scale via
// FUN_005209b0(1.0), swaps in the shared child from FUN_00538680, restores or
// resets the timing fields, refreshes the renderer, then optionally creates the
// secondary object at +0x50 and applies it to the child.
uint32_t FUN_00520490(void* self, int param_1, char param_2) {
    uint32_t* u = (uint32_t*)self;
    int* piVar1;
    uint8_t* pbVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    uint32_t* puVar5;
    int iVar6;
    uint32_t uVar7;
    int* piVar8;
    uint8_t local_d;
    uint32_t local_c;
    uint32_t local_8;
    uint32_t local_4;

    piVar8 = nullptr;
    uVar4 = 0;
    local_d = 0;
    if (*(int*)((char*)self + 0x70) != 0) {
        do {
            *(uint32_t*)(*(int*)((char*)self + 0x68) + uVar4 * 4) = 0;
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint32_t*)((char*)self + 0x70));
    }
    *(uint32_t*)((char*)self + 0x70) = 0;
    *(uint32_t*)((char*)self + 0x74) = 0;
    iVar6 = *(int*)((char*)self + 0x44);
    if (iVar6 != 0) {
        piVar8 = *(int**)(iVar6 + 0x24);
        local_c = *(uint32_t*)(iVar6 + 0x5c);
        local_d = *(uint8_t*)(iVar6 + 0x20) & 1;
        local_8 = *(uint32_t*)(iVar6 + 0x60);
        local_4 = *(uint32_t*)(iVar6 + 100);
        FUN_005209b0(self, 1.0f);
        if (*(void**)((char*)self + 0x7c) != nullptr) {
            operator_delete(*(void**)((char*)self + 0x7c));
            *(uint32_t*)((char*)self + 0x7c) = 0;
        }
        FUN_005208f0(self);
    }
    puVar5 = (uint32_t*)FUN_00538680();
    puVar3 = *(uint32_t**)((char*)self + 0x44);
    if (puVar3 != puVar5) {
        if (puVar3 != nullptr) {
            piVar1 = (int*)puVar3 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                ((PIRATES_DTOR)*puVar3)(1);
            }
        }
        *(uint32_t**)((char*)self + 0x44) = puVar5;
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    *(int*)((char*)self + 0x48) = param_1;
    if (piVar8 == nullptr) {
        iVar6 = *(int*)((char*)self + 0x44);
        *(uint32_t*)(iVar6 + 0x5c) = (uint32_t)DAT_00727430;
        *(uint32_t*)(iVar6 + 0x60) = (uint32_t)DAT_00727434;
        *(uint32_t*)(iVar6 + 100) = (uint32_t)DAT_00727438;
    } else {
        iVar6 = *(int*)((char*)self + 0x44);
        *(uint32_t*)(iVar6 + 0x5c) = local_c;
        *(uint32_t*)(iVar6 + 0x60) = local_8;
        *(uint32_t*)(iVar6 + 100) = local_4;
        (*(void(__cdecl**)(uint32_t, int))(*piVar8 + 0x70))(*(uint32_t*)((char*)self + 0x44), 1);
    }
    FUN_00533d10(*(uint32_t*)((char*)self + 0x2c), 1);
    FUN_00534130();
    FUN_00534350();
    pbVar2 = (uint8_t*)(*(int*)((char*)self + 0x44) + 0x20);
    *pbVar2 = *pbVar2 | 2;
    if (*(char*)(param_1 + 0x40) != 0) {
        *(uint8_t*)((char*)self + 0x31) = 1;
    }
    if (local_d != 0) {
        pbVar2 = (uint8_t*)(*(int*)((char*)self + 0x44) + 0x20);
        *pbVar2 = *pbVar2 | 1;
    }
    FUN_005206a0(self, *(int**)((char*)self + 0x44));
    FUN_00520b00(self, *(int**)((char*)self + 0x44));
    if (param_2 == 0) {
        return 0;
    }
    iVar6 = (int)(intptr_t)FUN_00533c78(8);
    if (iVar6 == 0) {
        piVar8 = nullptr;
    } else {
        if (*(int*)(param_1 + 0x3c) == 0) {
            iVar6 = (int)(intptr_t)FUN_00533c78(8);
            if (iVar6 != 0) {
                uVar7 = FUN_0051dd80((void*)iVar6, (void*)(param_1 + 0x14));
                *(uint32_t*)(param_1 + 0x3c) = uVar7;
                piVar8 = (int*)FUN_0051e290();
                goto LAB_0052063d;
            }
            *(uint32_t*)(param_1 + 0x3c) = 0;
        }
        piVar8 = (int*)FUN_0051e290();
    }
LAB_0052063d:
    *(uint32_t*)((char*)self + 0x50) = (uint32_t)piVar8;
    *(uint8_t*)(*piVar8 + 0x20) = *(uint8_t*)(*piVar8 + 0x20) | 1;
    (*(void(__cdecl**)(uint32_t, int))(**(int**)((char*)self + 0x44) + 0x70))(
        *(uint32_t*)((char*)self + 0x50), 0);
    return 0;
}
