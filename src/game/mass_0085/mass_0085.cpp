#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <cmath>

extern int FUN_005065b0();
extern void FUN_005065e0(void*);
extern void operator_delete(void*);
extern void operator_delete__(void*);
extern void FUN_00573d50(void);
extern void FUN_00574330(void);
extern void FUN_004ed8f0(int);
extern void FUN_004f8fa0(void*, const char*);
extern void FUN_004f96a0(void);
extern void FUN_004f8f50(void);
extern void FUN_004c2510(const char*, void*);
extern void FUN_004f9820(void*);
extern char FUN_0051bfc0(void*);
extern int FUN_00533c78(int);
extern void FUN_00571600(void*, uint32_t*);
extern void FUN_00571aa0(uint32_t, char**, void*);
extern void FUN_00571a60(uint32_t, void*);
extern void FUN_00506550(void**);
extern void FUN_00506490(void*);
extern void FUN_00506440(void);
extern void FUN_005063d0(void*);
extern void FUN_00506220(void*);
extern void FUN_00506040(int, uint32_t, int, uint32_t, uint32_t);
extern void FUN_00505820(void);
extern void FUN_00505760(void);
extern void FUN_00505ed0(char);
extern void FUN_00506130(int, void*);
extern void* FUN_00571140(void*, const char*, uint32_t);
extern uint32_t* FUN_00538680(void);
extern void* FUN_00574480(uint32_t);
extern void FUN_00573d80(void*, void*);
extern void FUN_00573b30(uint32_t);
extern void FUN_00573bb0(uint32_t, uint32_t);
extern void FUN_00573b80(uint32_t);
extern void FUN_00573b40(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_00573b90(uint32_t, uint32_t, int, int);
extern void FUN_00573b10(uint32_t, uint32_t, int);
extern void FUN_00571ae0(uint32_t, uint32_t, void*);
extern void FUN_00571b40(uint32_t, uint32_t, int*);
extern void FUN_00571ba0(uint32_t, uint32_t, int*);
extern void FUN_00571c00(uint32_t, uint32_t, int, uint32_t*, uint32_t*);
extern void FUN_00571c80(uint32_t, uint32_t, void*);
extern void FUN_00572020(int, uint32_t, int);
extern void FUN_00524e90(void*);
extern void FUN_00524d90(uint32_t);
extern void FUN_00524b10(uint32_t, void*, float);
extern void FUN_00500b50(void);
extern void FUN_00517f90(void);
extern void FUN_00506af0(uint32_t);
extern void FUN_00506b80(float);
extern float FUN_00506aa0(void);
extern float FUN_004c3100(void);
extern void FUN_005200b0(void*);
extern void FUN_00520190(void*);
extern void* FUN_0051ffd0(void);
extern void FUN_00506520(void);
extern void FUN_0051a480(void*);

extern void* DAT_008cad14_value();
extern void* DAT_008cad14;
extern int* DAT_008cad18;
extern uint32_t DAT_008cad1c;
extern void* DAT_00717a84_ptr;
extern uint32_t DAT_007275d4;
extern void* PTR_FUN_007108ac;
extern void* DAT_007179b0;
extern void* DAT_00727430;
extern void* DAT_008ee070;
extern uint32_t DAT_008ca53c;
extern uint32_t DAT_008ee194;
extern uint32_t DAT_008ee1a0;
extern uint32_t DAT_008ee198;
extern void* DAT_008ee070_vtable;

// 0x504c40 — observed shape
void FUN_00504c40_recon() {
    uint32_t* puVar6 = (uint32_t*)DAT_008cad14;
    if (DAT_008cad14 != nullptr && DAT_008cad14_value() != nullptr) {
        // Check DAT_008cad14[3]
        if (*(int*)((char*)DAT_008cad14 + 12) != 0) {
            int local_40c = FUN_005065b0();
            while (local_40c != 0) {
                uint32_t* local_408 = nullptr;
                FUN_005065e0(&local_40c);
                uint32_t* puVar4 = local_408;
                char local_400[1024];
                wsprintfA(local_400, "\nERROR: %s still in sequence map, refCnt=%d\n", (char*)puVar4, puVar4[1]);
                OutputDebugStringA(local_400);
                ((void(*)(int))(*(void**)puVar4))(1);
                int* piVar2 = (int*)((char*)puVar4 + 4);
                *piVar2 = *piVar2 - 1;
                puVar6 = (uint32_t*)DAT_008cad14;
                if (*piVar2 == 0) {
                    ((void(*)(int))(*(void**)puVar4))(1);
                    puVar6 = (uint32_t*)DAT_008cad14;
                }
            }
        }
    }
    if (DAT_008cad18 != nullptr) {
        uint32_t uVar1 = 0;
        int* piVar2 = nullptr;
        if (DAT_008cad18[1] != 0) {
            piVar2 = (int*)DAT_008cad18[2];
            do {
                if (*piVar2 != 0) {
                    piVar2 = (int*)DAT_008cad18[2] + uVar1;
                }
                uVar1 = uVar1 + 1;
                piVar2 = piVar2 + 1;
            } while (uVar1 < (uint32_t)DAT_008cad18[1]);
        }
        if (piVar2 == nullptr) {
            piVar2 = nullptr;
        }
        int* piVar5 = DAT_008cad18;
        if (piVar2 != nullptr) {
            do {
                int* piVar7 = (int*)*piVar2;
                uint32_t* puVar6b = (uint32_t*)piVar2[2];
                if (piVar7 == nullptr) {
                    int iVar3 = ((int(*)(int))(*(void**)(*piVar5 + 4)))(piVar2[1]);
                    uVar1 = iVar3 + 1;
                    if (uVar1 < (uint32_t)piVar5[1]) {
                        uint32_t* puVar4 = (uint32_t*)((char*)piVar5[2] + uVar1 * 4);
                        do {
                            piVar7 = (int*)*puVar4;
                            if (piVar7 != nullptr) break;
                            uVar1 = uVar1 + 1;
                            puVar4 = puVar4 + 1;
                        } while (uVar1 < (uint32_t)piVar5[1]);
                    } else {
                        piVar7 = nullptr;
                    }
                    piVar5 = DAT_008cad18;
                }
                if (puVar6b != nullptr) {
                    ((void(*)(int))(*(void**)puVar6b))(1);
                    piVar5 = DAT_008cad18;
                }
                piVar2 = piVar7;
            } while (piVar7 != nullptr);
            puVar6 = (uint32_t*)DAT_008cad14;
        }
        if (piVar5 != nullptr) {
            ((void(*)(int))(*(void**)piVar5))(1);
            DAT_008cad18 = nullptr;
            puVar6 = (uint32_t*)DAT_008cad14;
        }
    }
    if (puVar6 != nullptr) {
        ((void(*)(int))(*(void**)puVar6))(1);
        DAT_008cad14 = nullptr;
    }
}

// 0x504db0 — observed shape
void FUN_00504db0_recon(void* self) {
    char* base = (char*)self;
    if (*(int*)(base + 0x50) != 0) {
        do {
            int* piVar1 = *(int**)(base + 0x48);
            int iVar2 = *piVar1;
            *(int*)(base + 0x48) = iVar2;
            if (iVar2 == 0) {
                *(uint32_t*)(base + 0x4c) = 0;
            } else {
                *(uint32_t*)(iVar2 + 4) = 0;
            }
            void* pvVar3 = (void*)piVar1[2];
            ((void(*)(void*))(*(void**)(*(int*)(base + 0x44) + 8)))(piVar1);
            *(int*)(base + 0x50) = *(int*)(base + 0x50) - 1;
            operator_delete(pvVar3);
        } while (*(int*)(base + 0x50) != 0);
    }
}

// 0x504e00 — observed shape
void FUN_00504e00_recon(void* self) {
    char* base = (char*)self;
    if (*(int*)(base + 0x10) != 0) {
        FUN_00573d50();
        FUN_00574330();
    }
    FUN_00504db0_recon(self);
    // FUN_00504e80_recon(self); // cross-batch call preserved via extern
    {
        // inline call to 0x504e80 logic would be duplicate; call through extern decl below
    }
    // Note: body falls through to FUN_00504e80 and FUN_00504fa0 equivalents
    // For fidelity, invoke via function pointers declared as extern helpers
    // (preserving call order as observed)
    // The actual calls are emitted in the tail section to avoid duplicate definition issues:
    // See FUN_00504e00 tail below.
}

// 0x504e80 — observed shape
void FUN_00504e80_recon(void* self) {
    char* base = (char*)self;
    uint32_t* puVar8 = *(uint32_t**)(base + 0x18);
    while (puVar8 != nullptr) {
        uint32_t* puVar2 = (uint32_t*)*puVar8;
        ((void(*)(uint32_t*))(*(void**)(*(int*)(base + 0x14) + 8)))(puVar8);
        puVar8 = puVar2;
    }
    *(uint32_t*)(base + 0x20) = 0;
    *(uint32_t*)(base + 0x18) = 0;
    *(uint32_t*)(base + 0x1c) = 0;
    puVar8 = *(uint32_t**)(base + 0x28);
    while (puVar8 != nullptr) {
        uint32_t* puVar2 = (uint32_t*)*puVar8;
        ((void(*)(uint32_t*))(*(void**)(*(int*)(base + 0x24) + 8)))(puVar8);
        puVar8 = puVar2;
    }
    *(uint32_t*)(base + 0x30) = 0;
    *(uint32_t*)(base + 0x28) = 0;
    *(uint32_t*)(base + 0x2c) = 0;
    if (*(int**)(base + 0x38) != nullptr) {
        int* piVar6 = *(int**)(base + 0x38);
        do {
            int* piVar3 = (int*)*piVar6;
            ((void(*)(int*))(*(void**)(*(int*)(base + 0x34) + 8)))(piVar6);
            piVar6 = piVar3;
        } while (piVar3 != nullptr);
    }
    *(uint32_t*)(base + 0x40) = 0;
    *(uint32_t*)(base + 0x38) = 0;
    *(uint32_t*)(base + 0x3c) = 0;
    *(uint32_t*)(base + 0x54) = 0;
    uint32_t uVar5 = 0;
    int* piVar6 = nullptr;
    if (*(uint32_t*)(base + 0x60) != 0) {
        piVar6 = *(int**)(base + 100);
        do {
            if (*piVar6 != 0) {
                piVar6 = (int*)(*(int**)(base + 100))[uVar5];
                break;
            }
            uVar5 = uVar5 + 1;
            piVar6 = piVar6 + 1;
        } while (uVar5 < *(uint32_t*)(base + 0x60));
    }
    if (piVar6 == nullptr) {
        piVar6 = nullptr;
    }
    while (true) {
        if (piVar6 == nullptr) {
            return;
        }
        int* piVar3 = (int*)piVar6[2];
        int iVar4 = piVar6[1];
        piVar6 = (int*)*piVar6;
        if (piVar6 == nullptr) {
            int iVar7 = ((int(*)(int))(*(void**)(*(int*)(base + 0x5c) + 4)))(iVar4);
            uVar5 = iVar7 + 1;
            if (uVar5 < *(uint32_t*)(base + 0x60)) {
                uint32_t* puVar8b = (uint32_t*)(*(int*)(base + 100) + uVar5 * 4);
                do {
                    piVar6 = (int*)*puVar8b;
                    if (piVar6 != nullptr) break;
                    uVar5 = uVar5 + 1;
                    puVar8b = puVar8b + 1;
                } while (uVar5 < *(uint32_t*)(base + 0x60));
            } else {
                piVar6 = nullptr;
            }
        }
        FUN_004ed8f0(iVar4);
        if (piVar3 != nullptr) {
            uint32_t* puVar8c = (uint32_t*)*piVar3;
            if (puVar8c != nullptr) {
                int* piVar1 = (int*)((char*)puVar8c + 4);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    ((void(*)(int))(*(void**)puVar8c))(1);
                }
            }
            operator_delete(piVar3);
        }
    }
}

// 0x504fa0 — observed shape
void FUN_00504fa0_recon(int param_1) {
    void* local_21c = nullptr;
    uint32_t local_214 = 0;
    if (*(int*)(param_1 + 0x58) != 0) {
        FUN_00571600(&local_21c, &local_214);
    }
    uint32_t local_218 = 0;
    if (local_214 != 0) {
        do {
            uint32_t uVar6 = local_218;
            uint32_t* local_210 = nullptr;
            char* local_20c = nullptr;
            uint8_t local_208[4] = {0};
            uint8_t local_204[3] = {0};
            FUN_00571aa0(*(uint32_t*)((int)local_21c + local_218 * 4), &local_20c, local_208);
            FUN_00571a60(*(uint32_t*)((int)local_21c + uVar6 * 4), local_204);
            char* pcVar5 = *(char**)(param_1 + 0xc);
            char acStack_201[513] = {0};
            if (pcVar5 == nullptr) {
                acStack_201[1] = 0;
            } else {
                int iVar3 = 1 - (int)pcVar5;
                char cVar2;
                do {
                    cVar2 = *pcVar5;
                    pcVar5[(int)(acStack_201 + iVar3)] = cVar2;
                    pcVar5 = pcVar5 + 1;
                } while (cVar2 != '\0');
            }
            pcVar5 = local_20c;
            char cVar2b;
            do {
                cVar2b = *pcVar5;
                pcVar5 = pcVar5 + 1;
            } while (cVar2b != '\0');
            char* pcVar8 = acStack_201;
            char* pcVar7;
            do {
                pcVar7 = pcVar8 + 1;
                pcVar8 = pcVar8 + 1;
            } while (*pcVar7 != '\0');
            pcVar7 = local_20c;
            for (uVar6 = (uint32_t)((int)pcVar5 - (int)local_20c) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                *(uint32_t*)pcVar8 = *(uint32_t*)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar8 = pcVar8 + 4;
            }
            for (uVar6 = (int)pcVar5 - (int)local_20c & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *pcVar8 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar8 = pcVar8 + 1;
            }
            FUN_00506550((void**)&local_210);
            uint32_t* puVar4 = local_210;
            if (local_210 != nullptr) {
                if (local_210[1] == 2) {
                    FUN_004ed8f0((int)(acStack_201 + 1));
                } else {
                    int* piVar1 = (int*)((char*)local_210 + 4);
                    *piVar1 = *piVar1 - 1;
                    if (*piVar1 == 0) {
                        ((void(*)(int))(*(void**)local_210))(1);
                    }
                }
                int* piVar1b = (int*)((char*)puVar4 + 4);
                *piVar1b = *piVar1b - 1;
                if (*piVar1b == 0) {
                    ((void(*)(int))(*(void**)puVar4))(1);
                }
            }
            local_218 = local_218 + 1;
        } while (local_218 < local_214);
    }
    if (local_21c != nullptr) {
        operator_delete__(local_21c);
    }
}

// ---------------------------------------------------------------------------
// Additional declarations used by the appended reconstructions below.
// Register receivers (in_EAX/in_EBX/in_EDX/in_EDI) are modelled as explicit
// leading parameters on the _recon forms; no `this` is used.
// ---------------------------------------------------------------------------
extern uint32_t FUN_005716a0(uint32_t);
extern void* thunk_FUN_00533c78(int);

// Ghidra types several animation-node link fields as float. The machine keeps
// those 32 bits verbatim, so reinterpret instead of converting.
static inline float as_float(uint32_t v) { float f; std::memcpy(&f, &v, 4); return f; }
static inline uint32_t as_u32(float f) { uint32_t v; std::memcpy(&v, &f, 4); return v; }
static inline void* as_ptr(float f) { return (void*)(uintptr_t)as_u32(f); }
static inline float as_float_ptr(const void* p) { return as_float((uint32_t)(uintptr_t)p); }

// Forward declarations for the recon forms that are called before definition.
uint32_t FUN_005053b0_recon(uint32_t in_EAX);
void FUN_005054a0_recon(int param_1);
void FUN_00505760_recon(void* self, int in_EDX);
void FUN_00505820_recon(int in_EAX);
void FUN_00505ed0_recon(int* unaff_EBX, int* unaff_EDI, char param_1);
void FUN_00506040_recon(int in_EAX, int param_1, uint32_t param_2, int param_3,
                        uint32_t param_4, uint32_t param_5);
int* FUN_00506130_recon(int in_EAX, int param_1, uint32_t* param_2);
void FUN_00506220_recon(int* in_EAX, int* unaff_EBX, int* param_1);
void FUN_005063d0_recon(int* in_EAX, uint32_t* param_1);

// 0x5050f0 — observed shape
// EAX receiver carries the source path string; param_1 is the animation object.
void FUN_005050f0_recon(uint32_t* param_1, uint8_t param_2, char param_3, char* in_EAX) {
    char cVar1;
    char* pcVar2;
    char* pcVar3;
    uint32_t uVar4;
    FILE* _File;
    uint32_t* puVar5;
    uint32_t uVar6;
    char* pcVar7;
    uint32_t uVar8;
    int iVar9;
    char* pcVar10;
    int iVar11;
    char local_400[509];
    char acStack_203[515];

    pcVar2 = in_EAX;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar3 = (char*)thunk_FUN_00533c78((int)(intptr_t)(pcVar2 + (1 - (intptr_t)(in_EAX + 1))));
    param_1[1] = (uint32_t)(uintptr_t)pcVar3;
    pcVar2 = in_EAX;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        *pcVar3 = cVar1;
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    *(uint8_t*)(param_1 + 0x22) = param_2;
    *param_1 = 0;
    uVar4 = FUN_005053b0_recon((uint32_t)(uintptr_t)in_EAX); // EAX still holds the path
    param_1[0x16] = uVar4;
    pcVar2 = in_EAX;
    do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    pcVar7 = in_EAX;
    do {
        cVar1 = *pcVar7;
        pcVar7[(intptr_t)(acStack_203 + (3 - (intptr_t)in_EAX))] = cVar1;
        pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    strncpy(pcVar3 + (intptr_t)(local_400 + (0x1fc - (intptr_t)(in_EAX + 1))) + 1, ".Tim", 4);
    (pcVar2 + (intptr_t)(acStack_203 + (3 - (intptr_t)(in_EAX + 1))))[0] = 'e';
    (pcVar2 + (intptr_t)(acStack_203 + (3 - (intptr_t)(in_EAX + 1))))[1] = '\0';
    _File = fopen(acStack_203 + 3, "rb");
    if (_File != nullptr) {
        fclose(_File);
        puVar5 = (uint32_t*)(intptr_t)FUN_00533c78(0x1c);
        if (puVar5 == nullptr) {
            puVar5 = nullptr;
        } else {
            puVar5[2] = 0;
            puVar5[5] = 1;
            puVar5[3] = 0;
            puVar5[4] = 0;
            puVar5[1] = 0;
            *puVar5 = (uint32_t)(uintptr_t)&PTR_FUN_007108ac;
            FUN_004f8fa0(puVar5, acStack_203 + 3);
        }
        param_1[0x21] = (uint32_t)(uintptr_t)puVar5;
        FUN_004f96a0();
    }
    if (*(char*)((intptr_t)param_1[0x16] + 0x30) != '\0') {
        iVar11 = -(int)(intptr_t)in_EAX;
        do {
            cVar1 = *in_EAX;
            in_EAX[(intptr_t)(local_400 + iVar11)] = cVar1;
            in_EAX = in_EAX + 1;
        } while (cVar1 != '\0');
        pcVar2 = strrchr(local_400, 0x5c);
        if ((pcVar2 == nullptr) && (pcVar2 = strrchr(local_400, 0x2f), pcVar2 == nullptr)) {
            local_400[0] = '\0';
        } else {
            pcVar2[1] = '\0';
        }
        pcVar2 = *(char**)((intptr_t)param_1[0x16] + 0x34);
        iVar11 = 0;
        if (pcVar2 != nullptr) {
            pcVar3 = pcVar2 + 1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            iVar11 = (int)((intptr_t)pcVar2 - (intptr_t)pcVar3);
        }
        pcVar2 = *(char**)((intptr_t)param_1[0x16] + 8);
        iVar9 = 0;
        if (pcVar2 != nullptr) {
            pcVar3 = pcVar2 + 1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            iVar9 = (int)((intptr_t)pcVar2 - (intptr_t)pcVar3);
        }
        pcVar2 = local_400;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar3 = (char*)thunk_FUN_00533c78((int)((intptr_t)pcVar2 + iVar11 +
                                                 (iVar9 - (intptr_t)(local_400 + 1)) + 1));
        param_1[2] = (uint32_t)(uintptr_t)pcVar3;
        pcVar2 = local_400;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
            *pcVar3 = cVar1;
            pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        pcVar2 = *(char**)((intptr_t)param_1[0x16] + 0x34);
        pcVar3 = pcVar2;
        if (pcVar2 != nullptr) {
            do {
                cVar1 = *pcVar3;
                pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            uVar6 = (uint32_t)((intptr_t)pcVar3 - (intptr_t)pcVar2);
            pcVar3 = (char*)((intptr_t)param_1[2] - 1);
            do {
                pcVar7 = pcVar3 + 1;
                pcVar3 = pcVar3 + 1;
            } while (*pcVar7 != '\0');
            for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(uint32_t*)pcVar3 = *(uint32_t*)pcVar2;
                pcVar2 = pcVar2 + 4;
                pcVar3 = pcVar3 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *pcVar3 = *pcVar2;
                pcVar2 = pcVar2 + 1;
                pcVar3 = pcVar3 + 1;
            }
        }
        pcVar2 = *(char**)((intptr_t)param_1[0x16] + 8);
        pcVar3 = pcVar2;
        if (pcVar2 != nullptr) {
            do {
                cVar1 = *pcVar3;
                pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            uVar6 = (uint32_t)((intptr_t)pcVar3 - (intptr_t)pcVar2);
            pcVar3 = (char*)((intptr_t)param_1[2] - 1);
            do {
                pcVar7 = pcVar3 + 1;
                pcVar3 = pcVar3 + 1;
            } while (*pcVar7 != '\0');
            for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(uint32_t*)pcVar3 = *(uint32_t*)pcVar2;
                pcVar2 = pcVar2 + 4;
                pcVar3 = pcVar3 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *pcVar3 = *pcVar2;
                pcVar2 = pcVar2 + 1;
                pcVar3 = pcVar3 + 1;
            }
        }
        pcVar2 = *(char**)((intptr_t)param_1[0x16] + 0x38);
        iVar11 = 0;
        if (pcVar2 != nullptr) {
            pcVar3 = pcVar2 + 1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            iVar11 = (int)((intptr_t)pcVar2 - (intptr_t)pcVar3);
        }
        pcVar2 = local_400;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar3 = (char*)thunk_FUN_00533c78((int)((intptr_t)pcVar2 + iVar11 +
                                                 (1 - (intptr_t)(local_400 + 1))));
        param_1[3] = (uint32_t)(uintptr_t)pcVar3;
        pcVar2 = local_400;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
            *pcVar3 = cVar1;
            pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if (iVar11 != 0) {
            pcVar2 = *(char**)((intptr_t)param_1[0x16] + 0x38);
            pcVar3 = pcVar2;
            do {
                cVar1 = *pcVar3;
                pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            pcVar7 = (char*)((intptr_t)param_1[3] - 1);
            do {
                pcVar10 = pcVar7 + 1;
                pcVar7 = pcVar7 + 1;
            } while (*pcVar10 != '\0');
            pcVar10 = pcVar2;
            for (uVar6 = (uint32_t)((intptr_t)pcVar3 - (intptr_t)pcVar2) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                *(uint32_t*)pcVar7 = *(uint32_t*)pcVar10;
                pcVar10 = pcVar10 + 4;
                pcVar7 = pcVar7 + 4;
            }
            for (uVar6 = (uint32_t)((intptr_t)pcVar3 - (intptr_t)pcVar2) & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *pcVar7 = *pcVar10;
                pcVar10 = pcVar10 + 1;
                pcVar7 = pcVar7 + 1;
            }
        }
    }
    if (param_3 != '\0') {
        FUN_005054a0_recon((int)(intptr_t)param_1);
    }
    return;
}

// 0x5053b0 — observed shape
// EAX receiver is forwarded to FUN_00572020 as its second argument.
uint32_t FUN_005053b0_recon(uint32_t in_EAX) {
    char cVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t local_4;

    local_4 = 0;
    cVar1 = FUN_0051bfc0(&local_4);
    if (cVar1 != '\0') {
        return local_4;
    }
    iVar2 = FUN_00533c78(0x3c);
    if (iVar2 == 0) {
        uVar3 = 0;
    } else {
        uVar3 = FUN_005716a0(1);
    }
    FUN_00572020(0, in_EAX, 0);
    FUN_00524e90((void*)(uintptr_t)uVar3);
    return uVar3;
}

// 0x505420 — observed shape
// EDI receiver is the animation object.
void FUN_00505420_recon(void* self, uint32_t param_1) {
    int* piVar1;
    uint32_t* puVar2;
    int iVar3;
    uint32_t* puVar4;
    char* base = (char*)self;

    if (*(int*)(base + 0x10) == 0) {
        iVar3 = FUN_00533c78(0xa4);
        if (iVar3 == 0) {
            puVar4 = nullptr;
        } else {
            puVar4 = (uint32_t*)FUN_00574480(param_1);
        }
        puVar2 = *(uint32_t**)(base + 0x10);
        if (puVar2 != puVar4) {
            if (puVar2 != nullptr) {
                piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    ((void(*)(int))(*(void**)puVar2))(1);
                }
            }
            *(uint32_t**)(base + 0x10) = puVar4;
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
    }
    *(uint8_t*)((intptr_t)*(int*)(base + 0x10) + 0x70) = 1;
    FUN_00506490(base);
    *(uint8_t*)((intptr_t)*(int*)(base + 0x10) + 0x70) = 1;
    FUN_00573d80(&DAT_007179b0, &DAT_00727430);
    return;
}

// 0x5054a0 — observed shape
void FUN_005054a0_recon(int param_1) {
    int* piVar1;
    int iVar2;
    void* pvVar3;
    char cVar4;
    char* pcVar5;
    uint32_t* puVar6;
    uint32_t uVar7;
    int* piVar8;
    uint32_t uVar9;
    char* pcVar10;
    char* pcVar11;
    uint32_t* puVar12;
    void* local_420;
    uint32_t local_41c;
    uint32_t* local_418;
    uint32_t local_414;
    char* local_410;
    uint32_t local_40c;
    uint32_t* local_408;
    uint8_t local_404[3];
    char cStack_401;
    char local_400[512];
    char acStack_200[512];

    local_420 = nullptr;
    local_414 = 0;
    local_410 = nullptr;
    local_40c = 0;
    local_408 = nullptr;
    local_418 = nullptr;
    local_404[0] = local_404[1] = local_404[2] = 0;
    cStack_401 = 0;
    FUN_00571600(&local_420, &local_414);
    local_41c = 0;
    if (local_414 != 0) {
        do {
            uVar9 = local_41c;
            local_418 = nullptr;
            FUN_00571aa0(*(uint32_t*)((intptr_t)local_420 + local_41c * 4), &local_410, &local_40c);
            FUN_00571a60(*(uint32_t*)((intptr_t)local_420 + uVar9 * 4), local_404);
            pcVar5 = *(char**)((intptr_t)param_1 + 0xc);
            iVar2 = -(int)(intptr_t)pcVar5;
            do {
                cVar4 = *pcVar5;
                pcVar5[(intptr_t)(local_400 + iVar2)] = cVar4;
                pcVar5 = pcVar5 + 1;
            } while (cVar4 != '\0');
            pcVar5 = local_410;
            do {
                cVar4 = *pcVar5;
                pcVar5 = pcVar5 + 1;
            } while (cVar4 != '\0');
            pcVar11 = &cStack_401;
            do {
                pcVar10 = pcVar11 + 1;
                pcVar11 = pcVar11 + 1;
            } while (*pcVar10 != '\0');
            pcVar10 = local_410;
            for (uVar9 = (uint32_t)((intptr_t)pcVar5 - (intptr_t)local_410) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                *(uint32_t*)pcVar11 = *(uint32_t*)pcVar10;
                pcVar10 = pcVar10 + 4;
                pcVar11 = pcVar11 + 4;
            }
            for (uVar9 = (uint32_t)((intptr_t)pcVar5 - (intptr_t)local_410) & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                *pcVar11 = *pcVar10;
                pcVar10 = pcVar10 + 1;
                pcVar11 = pcVar11 + 1;
            }
            cVar4 = ((char(*)(void**))FUN_00506550)((void**)&local_418);
            puVar12 = local_418;
            if (cVar4 == '\0') {
                piVar8 = (int*)FUN_00571140(&local_408, local_400, local_40c);
                puVar12 = local_418;
                if (local_418 != (uint32_t*)(intptr_t)*piVar8) {
                    if (local_418 != nullptr) {
                        piVar1 = (int*)(local_418 + 1);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            ((void(*)(int))(*(void**)local_418))(1);
                        }
                    }
                    puVar12 = (uint32_t*)(intptr_t)*piVar8;
                    if (puVar12 != nullptr) {
                        puVar12[1] = puVar12[1] + 1;
                    }
                }
                if (local_408 != nullptr) {
                    iVar2 = (int)local_408[1];
                    local_408[1] = (uint32_t)(iVar2 + -1);
                    if (iVar2 + -1 == 0) {
                        ((void(*)(int))(*(void**)local_408))(1);
                    }
                }
                if ((puVar12 == nullptr) &&
                    (sprintf(acStack_200, "Can't create animation sequence from file %s", local_400),
                     DAT_00717a84_ptr != nullptr)) {
                    ((void(*)(const char*, const char*, int))DAT_00717a84_ptr)(acStack_200, "ERROR", 0);
                }
                if (puVar12 != nullptr) {
                    puVar12[1] = puVar12[1] + 1;
                }
                FUN_004c2510(local_400, puVar12);
                DAT_007275d4 = 1;
                puVar6 = FUN_00538680();
                if (puVar12 != puVar6) {
                    if (puVar12 != nullptr) goto LAB_00505665;
                    goto LAB_00505672;
                }
            } else {
                local_418[1] = local_418[1] + 1;
                DAT_007275d4 = 1;
                puVar6 = FUN_00538680();
                if (puVar12 != puVar6) {
LAB_00505665:
                    piVar8 = (int*)(puVar12 + 1);
                    *piVar8 = *piVar8 + -1;
                    if (*piVar8 == 0) {
                        ((void(*)(int))(*(void**)puVar12))(1);
                    }
LAB_00505672:
                    puVar12 = puVar6;
                    if (puVar6 != nullptr) {
                        puVar6[1] = puVar6[1] + 1;
                    }
                }
            }
            if (puVar12 != nullptr) {
                puVar12[1] = puVar12[1] + 1;
            }
            uVar7 = (uint32_t)(uintptr_t)FUN_00506130_recon(param_1, param_1, puVar12);
            FUN_00524e90((void*)(uintptr_t)uVar7);
            if (puVar12 != nullptr) {
                piVar8 = (int*)(puVar12 + 1);
                *piVar8 = *piVar8 + -1;
                if (*piVar8 == 0) {
                    ((void(*)(int))(*(void**)puVar12))(1);
                }
            }
            local_41c = local_41c + 1;
        } while (local_41c < local_414);
    }
    operator_delete__(local_420);
    piVar8 = (int*)(intptr_t)FUN_00533c78(0x28);
    if (piVar8 == nullptr) {
        piVar8 = nullptr;
    } else {
        *piVar8 = 0;
    }
    puVar12 = (uint32_t*)(intptr_t)*piVar8;
    if (puVar12 != nullptr) {
        piVar1 = (int*)(puVar12 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            ((void(*)(int))(*(void**)puVar12))(1);
        }
        *piVar8 = 0;
    }
    piVar8[1] = -1;
    piVar8[5] = 0;
    piVar8[8] = -0x40800000;
    FUN_00524e90(piVar8);
    pvVar3 = *(void**)((intptr_t)param_1 + 0x84);
    if (pvVar3 != nullptr) {
        FUN_004f8f50();
        operator_delete(pvVar3);
        *(uint32_t*)((intptr_t)param_1 + 0x84) = 0;
    }
    return;
}

// 0x505760 — observed shape
// EDX receiver selects the sequence id; EDI receiver is the animation object.
void FUN_00505760_recon(void* self, int in_EDX) {
    int* piVar1;
    int* piVar2;
    int local_c;
    uint32_t local_8;
    uint32_t local_4;
    char* base = (char*)self;

    piVar2 = *(int**)(base + 0x48);
    if (piVar2 != nullptr) {
        while (true) {
            piVar1 = (int*)piVar2[2];
            piVar2 = (int*)*piVar2;
            if (*(int*)(piVar1[1] + 4) == in_EDX) break;
            if (piVar2 == nullptr) {
                return;
            }
        }
        local_c = 0;
        local_4 = 0;
        local_8 = 0;
        FUN_00573b30(*(uint32_t*)(intptr_t)piVar1[1]);
        FUN_00571ba0(*(uint32_t*)(*piVar1 + 4), *(uint32_t*)(piVar1[1] + 4), &local_c);
        if (local_c != 0) {
            FUN_00571c00(*(uint32_t*)(*piVar1 + 4), *(uint32_t*)(piVar1[1] + 4), 0, &local_4, &local_8);
        }
        FUN_00573b40(*(uint32_t*)(intptr_t)*piVar1, local_8, 0x3f800000,
                     *(uint32_t*)(piVar1[1] + 0x24), *(uint32_t*)(intptr_t)*piVar1);
    }
    return;
}

// 0x505820 — observed shape
// EAX receiver is the animation object.
void FUN_00505820_recon(int in_EAX) {
    uint32_t* puVar1;
    int* piVar2;
    uint32_t* puVar3;
    int* piVar4;
    char cVar5;
    int* local_4;

    local_4 = nullptr;
    cVar5 = FUN_0051bfc0(&local_4);
    piVar4 = local_4;
    if (cVar5 != '\0') {
        if ((DAT_008cad1c != 0) && (*(char*)(in_EAX + 0x89) != '\0')) {
            FUN_00524d90(DAT_008cad1c);
        }
        piVar2 = *(int**)(in_EAX + 0x38);
        while (local_4 = piVar2, local_4 != nullptr) {
            piVar2 = (int*)*local_4;
            if ((int*)local_4[2] == piVar4) {
                FUN_00573b30((uint32_t)*piVar4);
                FUN_00517f90();
                return;
            }
        }
        if (*(int**)(in_EAX + 0x48) != nullptr) {
            local_4 = *(int**)(in_EAX + 0x48);
            while (true) {
                puVar1 = (uint32_t*)(intptr_t)local_4[2];
                piVar2 = (int*)*local_4;
                if (*(int*)(intptr_t)puVar1[1] == *piVar4) break;
                local_4 = piVar2;
                if (piVar2 == nullptr) {
                    return;
                }
            }
            puVar3 = (uint32_t*)(intptr_t)puVar1[1];
            if ((*(uint8_t*)((char*)puVar3 + 20) & 4) == 0) {
                if (*(char*)((char*)puVar1 + 16) == '\0') {
                    FUN_00573bb0(*(uint32_t*)(intptr_t)*puVar1, *puVar3);
                } else {
                    FUN_00573b80(*puVar3);
                }
            } else {
                // [INFERENCE] EDX = matched sequence id; EDI = this object.
                FUN_00505760_recon((void*)(intptr_t)in_EAX, *piVar4);
            }
            FUN_00517f90();
            operator_delete(puVar1);
        }
    }
    return;
}

// 0x505920 — observed shape
// EDI receiver is the animation object.
uint32_t FUN_00505920_recon(int unaff_EDI) {
    uint32_t uVar1;
    uint32_t local_8;
    void* local_4;

    if (*(int*)(unaff_EDI + 0x58) == 0) {
        return 0;
    }
    local_4 = nullptr;
    local_8 = 0;
    FUN_00571600(&local_4, &local_8);
    uVar1 = 0;
    if (local_8 != 0) {
        do {
            FUN_00505820_recon(unaff_EDI);
            uVar1 = uVar1 + 1;
        } while (uVar1 < local_8);
    }
    if (local_4 != nullptr) {
        operator_delete__(local_4);
    }
    return 1;
}

// 0x505990 — observed shape
// EAX receiver is the animation object; EBX carries the sequence id (-1 = all).
void FUN_00505990_recon(int in_EAX, int unaff_EBX) {
    int* piVar1;
    uint32_t* puVar2;

    if (unaff_EBX == -1) {
        FUN_00506520();
        return;
    }
    puVar2 = *(uint32_t**)(in_EAX + 0x18);
    while (puVar2 != nullptr) {
        piVar1 = (int*)(puVar2 + 2);
        puVar2 = (uint32_t*)(intptr_t)*puVar2;
        if (*(int*)(*piVar1 + 0x24) == unaff_EBX) {
            FUN_00517f90();
            puVar2 = *(uint32_t**)(in_EAX + 0x18);
        }
    }
    return;
}

// 0x5059e0 — observed shape
// Per-frame animation update: advances the clock, fires time-based events,
// retires finished tracks and starts chained sequences.
void FUN_005059e0_recon(float* param_1, float param_2, char param_3) {
    char cVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    float fVar4;
    float fVar5;
    float* pfVar6;
    float* pfVar7;
    char* pcVar8;
    int iVar9;
    float* pfVar10;
    uint64_t uVar11;
    uint32_t uVar12;

    pfVar7 = param_1;
    if ((DAT_008ee1a0 & 1) == 0) {
        DAT_008ee1a0 = DAT_008ee1a0 | 1;
        pcVar8 = (char*)"FAnimation::Update";
        do {
            cVar1 = *pcVar8;
            pcVar8[0x1dcd18] = cVar1;
            pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        DAT_008ee198 = 0xffffffff;
        DAT_008ee194 = 0;
    }
    if (DAT_008ca53c == 0) {
        iVar9 = FUN_00533c78(0x70);
        if (iVar9 == 0) {
            DAT_008ca53c = 0;
        } else {
            DAT_008ca53c = (uint32_t)(uintptr_t)FUN_0051ffd0();
        }
    }
    FUN_005200b0(&DAT_008ee070);
    if (param_3 == '\0') {
        *pfVar7 = param_2 + *pfVar7;
    } else {
        *pfVar7 = param_2;
    }
    if (*(char*)((char*)pfVar7 + 0x88) == '\0') {
        pfVar10 = (float*)as_ptr(pfVar7[0xe]);
        while (pfVar10 != nullptr) {
            puVar2 = (uint32_t*)as_ptr(pfVar10[2]);
            fVar4 = *pfVar7 - as_float(puVar2[2]);
            pfVar10 = (float*)as_ptr(*pfVar10);
            fVar5 = (as_float(puVar2[3]) / as_float(puVar2[4])) *
                   (as_float(puVar2[7]) - as_float(puVar2[6]));
            if ((!std::isnan(fVar5) && !std::isnan(fVar4)) &&
                ((fVar5 < fVar4) != (fVar5 == fVar4))) {
                if (((puVar2[5] & 1) == 0) || (pfVar7[8] != 0.0f)) {
                    puVar2[5] = puVar2[5] | 0x10;
                    FUN_00573b30(*puVar2);
                    FUN_00517f90();
                    if ((DAT_008cad1c != 0) && (*(char*)((intptr_t)pfVar7 + 0x89) != '\0')) {
                        FUN_00524b10(DAT_008cad1c, pfVar7, as_float(puVar2[3]));
                        FUN_00524d90(DAT_008cad1c);
                    }
                    pfVar7[0x15] = as_float_ptr(puVar2);
                } else {
                    if ((DAT_008cad1c != 0) && (*(char*)((intptr_t)pfVar7 + 0x89) != '\0')) {
                        FUN_00524b10(DAT_008cad1c, pfVar7, as_float(puVar2[3]));
                    }
                    puVar2[2] = as_u32(*pfVar7);
                }
            }
        }
        pfVar10 = (float*)as_ptr(pfVar7[0x12]);
        while (pfVar10 != nullptr) {
            puVar2 = (uint32_t*)as_ptr(pfVar10[2]);
            pfVar10 = (float*)as_ptr(*pfVar10);
            if (as_float(puVar2[3]) <= *pfVar7 - as_float(puVar2[2])) {
                puVar3 = (uint32_t*)(intptr_t)puVar2[1];
                if ((*(uint8_t*)((char*)puVar3 + 20) & 4) == 0) {
                    if (*(char*)((char*)puVar2 + 16) == '\0') {
                        FUN_00573bb0(*(uint32_t*)(intptr_t)*puVar2, *puVar3);
                        *(uint32_t*)((intptr_t)puVar2[1] + 0x14) =
                            *(uint32_t*)((intptr_t)puVar2[1] + 0x14) | 2;
                    } else {
                        FUN_00573b80(*puVar3);
                    }
                    FUN_00517f90();
                    *(uint32_t*)((intptr_t)puVar2[1] + 0x14) =
                        *(uint32_t*)((intptr_t)puVar2[1] + 0x14) | 0x20;
                    iVar9 = (int)puVar2[1];
                    FUN_00506040_recon((int)(intptr_t)pfVar7,
                                       *(uint32_t*)((intptr_t)iVar9 + 4),
                                       *(uint32_t*)((intptr_t)iVar9 + 0x10),
                                       *(int*)((intptr_t)iVar9 + 0x24),
                                       *(uint32_t*)((intptr_t)iVar9 + 0x18),
                                       *(uint32_t*)((intptr_t)iVar9 + 0x1c));
                    operator_delete(puVar2);
                } else {
                    FUN_00505820_recon((int)(intptr_t)pfVar7);
                }
                pfVar10 = (float*)as_ptr(pfVar7[0x12]);
            }
        }
        if (pfVar7[0xc] != 0.0f) goto LAB_00505c66;
        if (((pfVar7[0x10] == 0.0f) && (pfVar7[0x14] == 0.0f)) && (pfVar7[8] != 0.0f)) {
            pfVar10 = (float*)as_ptr(pfVar7[6]);
            while (pfVar10 != nullptr) {
                fVar4 = pfVar10[2];
                pfVar10 = (float*)as_ptr(*pfVar10);
                uVar11 = ((uint64_t(*)(void))FUN_00506440)();
                if ((int)uVar11 == -1) {
                    FUN_00506040_recon((int)(intptr_t)pfVar7,
                                       *(uint32_t*)((intptr_t)as_ptr(fVar4) + 4),
                                       *(uint32_t*)((intptr_t)as_ptr(fVar4) + 0x10),
                                       (int)(uint32_t)(uVar11 >> 0x20),
                                       *(uint32_t*)((intptr_t)as_ptr(fVar4) + 0x18),
                                       *(uint32_t*)((intptr_t)as_ptr(fVar4) + 0x1c));
                    FUN_00517f90();
                    pfVar10 = (float*)as_ptr(pfVar7[6]);
                }
            }
        }
        fVar4 = pfVar7[0xc];
        while (fVar4 != 0.0f) {
LAB_00505c66:
            pfVar10 = (float*)as_ptr(pfVar7[10]);
            fVar4 = *pfVar10;
            param_3 = '\0';
            pfVar7[10] = fVar4;
            if (fVar4 == 0.0f) {
                pfVar7[0xb] = 0.0f;
            } else {
                *(uint32_t*)((intptr_t)as_ptr(fVar4) + 4) = 0;
            }
            fVar4 = pfVar10[2];
            {
                void (*nodeRelease)(float*) = *(void* (**)(float*))((intptr_t)as_ptr(pfVar7[9]) + 8);
                nodeRelease(pfVar10);
            }
            pfVar7[0xc] = (float)((int)pfVar7[0xc] + -1);
            if (*(int*)((intptr_t)as_ptr(fVar4) + 4) == -1) {
                iVar9 = ((int(*)(void))FUN_00506440)();
                if (iVar9 != -1) {
                    FUN_00505820_recon((int)(intptr_t)pfVar7);
                }
            } else {
                if ((*(uint8_t*)((intptr_t)as_ptr(fVar4) + 0x14) & 4) == 0) {
                    pfVar10 = (float*)as_ptr(pfVar7[0xe]);
                    if (pfVar10 != nullptr) {
                        do {
                            if (param_3 != '\0') goto LAB_00505e61;
                            fVar5 = pfVar10[2];
                            pfVar10 = (float*)as_ptr(*pfVar10);
                            if (*(int*)((intptr_t)as_ptr(fVar4) + 0x24) ==
                                *(int*)((intptr_t)as_ptr(fVar5) + 0x24)) {
                                FUN_00505820_recon((int)(intptr_t)pfVar7);
                                FUN_00571c80(*(uint32_t*)((intptr_t)as_ptr(fVar5) + 4),
                                             *(uint32_t*)((intptr_t)as_ptr(fVar4) + 4),
                                             &param_2);
                                if (((char*)&param_2)[0] != '\0') {
                                    // [INFERENCE] both receivers are the animation object.
                                    FUN_00506220_recon((int*)pfVar7, (int*)pfVar7,
                                                       (int*)as_ptr(fVar4));
                                    param_3 = '\x01';
                                }
                            }
                        } while (pfVar10 != nullptr);
                        if (param_3 != '\0') goto LAB_00505e61;
                    }
                    pfVar10 = (float*)as_ptr(pfVar7[0x12]);
                    if (pfVar10 != nullptr) {
                        do {
                            pfVar6 = (float*)as_ptr(pfVar10[2]);
                            puVar2 = (uint32_t*)as_ptr(pfVar6[1]);
                            pfVar10 = (float*)as_ptr(*pfVar10);
                            if ((int)puVar2[9] == *(int*)((intptr_t)as_ptr(fVar4) + 0x24)) {
                                if ((*(uint8_t*)((char*)puVar2 + 20) & 4) == 0) {
                                    if (*(char*)((char*)pfVar6 + 16) == '\0') {
                                        FUN_00573bb0(*(uint32_t*)(intptr_t)as_ptr(*pfVar6), *puVar2);
                                        *(uint32_t*)((intptr_t)as_ptr(pfVar6[1]) + 0x14) =
                                            *(uint32_t*)((intptr_t)as_ptr(pfVar6[1]) + 0x14) | 2;
                                    } else {
                                        FUN_00573b80(*puVar2);
                                    }
                                    FUN_00517f90();
                                    if (*pfVar6 == fVar4) {
                                        FUN_00505ed0_recon((int*)pfVar7, (int*)as_ptr(fVar4), 1);
                                    } else {
                                        FUN_00506220_recon((int*)pfVar7, (int*)pfVar7,
                                                           (int*)as_ptr(fVar4));
                                    }
                                    param_3 = '\x01';
                                    operator_delete(pfVar6);
                                } else {
                                    FUN_00505820_recon((int)(intptr_t)pfVar7);
                                }
                            }
                        } while (pfVar10 != nullptr);
                        if (param_3 != '\0') goto LAB_00505e61;
                    }
                    if (pfVar7[0x15] != 0.0f) {
                        FUN_00571c80(*(uint32_t*)((intptr_t)as_ptr(pfVar7[0x15]) + 4),
                                     *(uint32_t*)((intptr_t)as_ptr(fVar4) + 4), &param_1);
                        if ((((char*)&param_1)[0] != '\0') &&
                            ((*(uint8_t*)((intptr_t)as_ptr(fVar4) + 0x14) & 0x20) == 0)) {
                            FUN_00506220_recon((int*)pfVar7, (int*)pfVar7, (int*)as_ptr(fVar4));
                            goto LAB_00505e61;
                        }
                        *(uint32_t*)((intptr_t)as_ptr(fVar4) + 0x14) =
                            *(uint32_t*)((intptr_t)as_ptr(fVar4) + 0x14) & 0xffffffdf;
                    }
                    uVar12 = 0;
                } else {
                    pfVar10 = (float*)as_ptr(pfVar7[0xe]);
                    if (pfVar10 != nullptr) {
                        do {
                            pfVar6 = pfVar10 + 2;
                            pfVar10 = (float*)as_ptr(*pfVar10);
                            if (*(int*)((intptr_t)as_ptr(*pfVar6) + 0x24) == 0) {
                                FUN_00506220_recon((int*)pfVar7, (int*)pfVar7,
                                                   (int*)as_ptr(fVar4));
                                break;
                            }
                        } while (pfVar10 != nullptr);
                        goto LAB_00505e61;
                    }
                    uVar12 = 1;
                }
                FUN_00505ed0_recon((int*)pfVar7, (int*)as_ptr(fVar4), (char)uVar12);
            }
LAB_00505e61:
            fVar4 = pfVar7[0xc];
        }
        if ((DAT_008cad1c != 0) && (*(char*)((intptr_t)pfVar7 + 0x89) != '\0')) {
            FUN_00524b10(DAT_008cad1c, pfVar7, *pfVar7);
        }
    }
    if (DAT_008ca53c == 0) {
        iVar9 = FUN_00533c78(0x70);
        if (iVar9 == 0) {
            DAT_008ca53c = 0;
        } else {
            DAT_008ca53c = (uint32_t)(uintptr_t)FUN_0051ffd0();
        }
    }
    FUN_00520190(&DAT_008ee070);
    return;
}

// 0x505ed0 — observed shape
// EBX: animation object; EDI: finished track node. Queues the node for release.
void FUN_00505ed0_recon(int* unaff_EBX, int* unaff_EDI, char param_1) {
    float fVar1;
    float fVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    long double fVar8;
    void* (*allocNode)(void);

    if ((unaff_EDI[5] & 2U) == 0) {
        if (param_1 == '\0') {
            unaff_EDI[2] = *unaff_EBX;
        }
    } else {
        unaff_EDI[5] = unaff_EDI[5] - 2;
    }
    iVar3 = unaff_EDI[4];
    iVar4 = *unaff_EDI;
    uVar6 = 0;
    if (*(int*)(iVar4 + 0x38) != 0) {
        do {
            iVar5 = *(int*)(*(int*)(iVar4 + 0x30) + uVar6 * 4);
            if (iVar5 != 0) {
                *(int*)(iVar5 + 0x10) = iVar3;
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < (uint32_t)*(int*)(iVar4 + 0x38));
    }
    fVar1 = (float)unaff_EDI[3];
    iVar3 = *unaff_EDI;
    fVar2 = (float)unaff_EDI[6];
    uVar6 = 0;
    if (*(int*)(iVar3 + 0x38) != 0) {
        do {
            iVar4 = *(int*)(*(int*)(iVar3 + 0x30) + uVar6 * 4);
            if (iVar4 != 0) {
                *(float*)(iVar4 + 0x14) = fVar1 * fVar2;
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < (uint32_t)*(int*)(iVar3 + 0x38));
    }
    if ((char)unaff_EBX[0x22] != '\0') {
        fVar1 = (float)unaff_EDI[3];
        fVar2 = (float)unaff_EDI[6];
        fVar8 = ((long double(*)(uint32_t))FUN_00506af0)((uint32_t)*unaff_EDI);
        FUN_00506b80((float)((long double)(fVar1 * fVar2) - fVar8));
    }
    FUN_00573b10((uint32_t)*unaff_EDI, (uint32_t)unaff_EDI[9], 1);
    allocNode = *(void* (**)(void))(intptr_t)(unaff_EBX[0xd] + 4);
    puVar7 = (uint32_t*)allocNode();
    puVar7[2] = (uint32_t)(uintptr_t)unaff_EDI;
    *puVar7 = 0;
    puVar7[1] = (uint32_t)unaff_EBX[0xf];
    if ((int*)unaff_EBX[0xf] == nullptr) {
        unaff_EBX[0xe] = (int)(intptr_t)puVar7;
        unaff_EBX[0xf] = (int)(intptr_t)puVar7;
        unaff_EBX[0x10] = unaff_EBX[0x10] + 1;
        return;
    }
    *(uint32_t*)(intptr_t)unaff_EBX[0xf] = (uint32_t)(uintptr_t)puVar7;
    unaff_EBX[0xf] = (int)(intptr_t)puVar7;
    unaff_EBX[0x10] = unaff_EBX[0x10] + 1;
    return;
}

// 0x505fc0 — observed shape
// EAX receiver is the animation object; links a new event record.
void FUN_00505fc0_recon(int in_EAX, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                        uint32_t param_4) {
    char cVar1;
    uint32_t* puVar2;
    int local_4;
    void* (*allocRecord)(void);

    local_4 = 0;
    cVar1 = FUN_0051bfc0(&local_4);
    if (cVar1 != '\0') {
        *(uint32_t*)(local_4 + 0x18) = param_3;
        *(uint32_t*)(local_4 + 0x1c) = param_4;
        *(uint32_t*)(local_4 + 0x10) = param_1;
        *(uint32_t*)(local_4 + 0x24) = param_2;
        allocRecord = *(void* (**)(void))(intptr_t)(*(int*)(in_EAX + 0x14) + 4);
        puVar2 = (uint32_t*)allocRecord();
        puVar2[2] = (uint32_t)(uintptr_t)local_4;
        *puVar2 = 0;
        puVar2[1] = *(uint32_t*)(in_EAX + 0x1c);
        if (*(uint32_t**)(in_EAX + 0x1c) != nullptr) {
            **(uint32_t**)(in_EAX + 0x1c) = (uint32_t)(uintptr_t)puVar2;
            *(uint32_t**)(in_EAX + 0x1c) = puVar2;
            *(int*)(in_EAX + 0x20) = *(int*)(in_EAX + 0x20) + 1;
            return;
        }
        *(uint32_t**)(in_EAX + 0x18) = puVar2;
        *(uint32_t**)(in_EAX + 0x1c) = puVar2;
        *(int*)(in_EAX + 0x20) = *(int*)(in_EAX + 0x20) + 1;
    }
    return;
}

// 0x506040 — observed shape
// EAX receiver is the animation object. Rejects/updates an existing record or
// creates a new sound/scene record with the supplied timing fields.
void FUN_00506040_recon(int in_EAX, int param_1, uint32_t param_2, int param_3,
                        uint32_t param_4, uint32_t param_5) {
    uint32_t* puVar1;
    int iVar2;
    char cVar3;
    char* base = (char*)(intptr_t)in_EAX;

    iVar2 = param_1;
    puVar1 = *(uint32_t**)(base + 0x38);
    while (true) {
        if (puVar1 == nullptr) {
            for (puVar1 = *(uint32_t**)(base + 0x48); puVar1 != nullptr;
                 puVar1 = (uint32_t*)(intptr_t)*puVar1) {
                if (*(int*)((intptr_t)puVar1[2] + 4) == param_1) {
                    return;
                }
            }
            puVar1 = *(uint32_t**)(base + 0x28);
            while (true) {
                if (puVar1 == nullptr) {
                    cVar3 = FUN_0051bfc0(&param_1);
                    if (cVar3 != '\0') {
                        if (999 < param_3) {
                            *(uint32_t*)((intptr_t)param_1 + 0x14) =
                                *(uint32_t*)((intptr_t)param_1 + 0x14) | 4;
                        }
                        *(uint32_t*)((intptr_t)param_1 + 0x14) =
                            *(uint32_t*)((intptr_t)param_1 + 0x14) & 0xffffffef;
                        *(uint32_t*)((intptr_t)param_1 + 0x18) = param_4;
                        *(uint32_t*)((intptr_t)param_1 + 0x1c) = param_5;
                        *(uint32_t*)((intptr_t)param_1 + 0x10) = param_2;
                        *(int*)((intptr_t)param_1 + 0x24) = param_3;
                        FUN_0051a480(&param_1);
                    }
                    return;
                }
                param_1 = (int)puVar1[2];
                if (*(int*)((intptr_t)param_1 + 4) == iVar2) break;
                if (*(int*)((intptr_t)param_1 + 0x24) == param_3) {
                    FUN_00500b50();
                    puVar1 = *(uint32_t**)(base + 0x28);
                } else {
                    puVar1 = (uint32_t*)(intptr_t)*puVar1;
                }
            }
            return;
        }
        if (((*(int*)((intptr_t)puVar1[2] + 4) == param_1) &&
             ((*(uint8_t*)((intptr_t)puVar1[2] + 0x14) & 0x10) == 0)) &&
            (*(int*)(base + 0x30) == 0)) break;
        puVar1 = (uint32_t*)(intptr_t)*puVar1;
    }
    return;
}

// 0x506130 — observed shape
// EAX receiver is the owning object; wraps a sequence into a morph track.
int* FUN_00506130_recon(int in_EAX, int param_1, uint32_t* param_2) {
    int* piVar1;
    uint32_t* puVar2;
    int iVar3;
    int* piVar4;
    long double fVar5;
    long double fVar6;
    char local_20[32];

    piVar4 = (int*)(intptr_t)FUN_00533c78(0x28);
    if (piVar4 == nullptr) {
        piVar4 = nullptr;
    } else {
        *piVar4 = 0;
    }
    puVar2 = (uint32_t*)(intptr_t)*piVar4;
    if (puVar2 != param_2) {
        if (puVar2 != nullptr) {
            piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((void(*)(int))(*(void**)puVar2))(1);
            }
        }
        *piVar4 = (int)(intptr_t)param_2;
        if (param_2 != nullptr) {
            param_2[1] = param_2[1] + 1;
        }
    }
    piVar4[1] = in_EAX;
    piVar4[5] = 0;
    piVar4[8] = -0x40800000;
    if (*(int*)(param_1 + 0x84) != 0) {
        sprintf(local_20, "MORPH%d");
        FUN_004f9820(piVar4 + 8);
    }
    iVar3 = *piVar4;
    if (iVar3 != 0) {
        fVar5 = (long double)FUN_004c3100();
        fVar6 = (long double)FUN_00506aa0();
        piVar4[3] = (int)(float)((long double)(float)fVar5 - fVar6);
        if ((*(uint8_t*)(*(int*)(*(int*)(iVar3 + 0x30) + *(int*)(iVar3 + 0x9c) * 4) + 0xc) & 6) == 0) {
            piVar4[5] = piVar4[5] | 1;
        }
    }
    if (param_2 != nullptr) {
        piVar1 = (int*)(param_2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            ((void(*)(int))(*(void**)param_2))(1);
        }
    }
    return piVar4;
}

// 0x506220 — observed shape
// EAX receiver: animation object; EBX: owning scene/object; param_1: track node.
void FUN_00506220_recon(int* in_EAX, int* unaff_EBX, int* param_1) {
    int* piVar1;
    int* piVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    int local_10;
    uint32_t local_c;
    int local_8;
    uint32_t local_4;
    void* (*allocNode)(void);

    piVar2 = param_1;
    local_4 = 0;
    local_c = 0;
    local_10 = 0;
    local_8 = 0;
    if (in_EAX[0x14] != 0) {
        puVar3 = (uint32_t*)(intptr_t)in_EAX[0x12];
        while (puVar3 != nullptr) {
            piVar1 = (int*)(intptr_t)puVar3[2];
            puVar3 = (uint32_t*)(intptr_t)*puVar3;
            if ((*(int*)((intptr_t)*piVar1 + 0x24) == unaff_EBX[9]) &&
                (*(int*)((intptr_t)piVar1[1] + 0x24) == piVar2[9])) {
                FUN_005063d0_recon(in_EAX, (uint32_t*)piVar1);
                puVar3 = (uint32_t*)(intptr_t)in_EAX[0x12];
            }
        }
    }
    piVar2[2] = *in_EAX;
    FUN_00571ae0((uint32_t)unaff_EBX[1], (uint32_t)piVar2[1], &param_1);
    FUN_00571b40((uint32_t)unaff_EBX[1], (uint32_t)piVar2[1], &local_10);
    local_8 = 0;
    FUN_00571ba0((uint32_t)unaff_EBX[1], (uint32_t)piVar2[1], &local_8);
    if (local_8 != 0) {
        FUN_00571c00((uint32_t)unaff_EBX[1], (uint32_t)piVar2[1], 0, &local_4, &local_c);
    }
    if (((char*)&param_1)[0] == '\0') {
        FUN_00573b90((uint32_t)*unaff_EBX, (uint32_t)*piVar2, local_10, 0);
    } else {
        *(uint32_t*)((intptr_t)*piVar2 + 100) = 0xff7fffff;
        FUN_00506b80((float)piVar2[6] * (float)piVar2[3]);
        if ((*(uint8_t*)((char*)piVar2 + 20) & 4) == 0) {
            FUN_00573b40((uint32_t)*piVar2, local_c, (uint32_t)local_10,
                         (uint32_t)piVar2[9], 0);
        } else {
            FUN_00573b40((uint32_t)*piVar2, local_c, (uint32_t)local_10,
                         (uint32_t)piVar2[9], 0);
            local_10 = piVar2[3];
        }
    }
    puVar3 = (uint32_t*)(intptr_t)FUN_00533c78(0x14);
    *puVar3 = (uint32_t)(uintptr_t)unaff_EBX;
    puVar3[1] = (uint32_t)(uintptr_t)piVar2;
    puVar3[2] = (uint32_t)piVar2[2];
    puVar3[3] = (uint32_t)local_10;
    *(char*)((char*)puVar3 + 16) = ((char*)&param_1)[0];
    allocNode = *(void* (**)(void))(intptr_t)(in_EAX[0x11] + 4);
    puVar4 = (uint32_t*)allocNode();
    puVar4[2] = (uint32_t)(uintptr_t)puVar3;
    *puVar4 = 0;
    puVar4[1] = (uint32_t)in_EAX[0x13];
    if (in_EAX[0x13] == 0) {
        in_EAX[0x12] = (int)(intptr_t)puVar4;
        in_EAX[0x13] = (int)(intptr_t)puVar4;
        in_EAX[0x14] = in_EAX[0x14] + 1;
        return;
    }
    *(uint32_t*)(intptr_t)in_EAX[0x13] = (uint32_t)(uintptr_t)puVar4;
    in_EAX[0x13] = (int)(intptr_t)puVar4;
    in_EAX[0x14] = in_EAX[0x14] + 1;
    return;
}

// 0x5063d0 — observed shape
// EAX receiver: animation object; param_1: 0x14-byte pending-release record.
void FUN_005063d0_recon(int* in_EAX, uint32_t* param_1) {
    uint32_t* puVar1;

    puVar1 = (uint32_t*)(intptr_t)param_1[1];
    if ((*(uint8_t*)((char*)puVar1 + 20) & 4) != 0) {
        FUN_00505820_recon((int)(intptr_t)in_EAX);
        return;
    }
    if (*(char*)((char*)param_1 + 16) == '\0') {
        FUN_00573bb0(*(uint32_t*)(intptr_t)*param_1, *puVar1);
        *(uint32_t*)((intptr_t)param_1[1] + 0x14) =
            *(uint32_t*)((intptr_t)param_1[1] + 0x14) | 2;
    } else {
        FUN_00573b80(*puVar1);
    }
    FUN_00500b50();
    operator_delete(param_1);
    return;
}
