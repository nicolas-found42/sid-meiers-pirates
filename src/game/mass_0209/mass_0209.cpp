#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <windows.h>

extern uint32_t FUN_00428470(const float* param);
extern void FUN_005477c0(uint32_t level, int category, const char* format, ...);
extern void FUN_00547790(void);
extern void FUN_00545310(void* param1, void* param2);
extern int FUN_00533c78(uint32_t size);
extern int FUN_005bdfa0(void* param1, void* param2, void* param3, void* param4);
extern void FUN_005bfa50(void* param1);
extern uint32_t FUN_005dbd60(void);
extern void FUN_005c9890(void* param);
extern void FUN_005c9b90(void* param1, void* param2);
extern void FUN_005c9cd0(void* param1, void* param2);
extern int FUN_005aead0(int* param1, void* param2, int** param3);
extern void FUN_005e1490(void);
extern void* operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void* DAT_00728cf4;
extern void* DAT_00727864;
extern uint32_t DAT_00727444;
extern void* PTR_FUN_006c713c;
extern void* PTR_FUN_006c7030;
extern void* PTR_FUN_006c6fdc;
extern void* PTR_FUN_006c7158;
extern void* PTR_FUN_006c704c;
extern void* PTR_FUN_006c6ff8;
extern void* PTR_FUN_006c7174;
extern void* PTR_FUN_006c7068;
extern void* PTR_FUN_006c7014;
extern void* PTR_FUN_006c7084;
extern void* PTR_LAB_006fd148;

// 0x5bd640 — float-vector equality with flag packing; receiver in_ECX, param float array, compares component-wise with NaN handling, calls FUN_00428470 at +3
uint32_t FUN_005bd640(float* param_1, float* in_ECX, uint32_t in_EAX)
{
    float fVar1 = *param_1;
    float fVar2 = *in_ECX;
    uint32_t uVar3 = CONCAT22((uint16_t)(in_EAX >> 16), (uint16_t)((fVar2 < fVar1) << 8 | (isnan(fVar2) || isnan(fVar1)) << 10 | (fVar2 == fVar1) << 14));
    if (fVar2 == fVar1) {
        fVar1 = param_1[1];
        fVar2 = in_ECX[1];
        uVar3 = CONCAT22((uint16_t)(uVar3 >> 16), (uint16_t)((fVar2 < fVar1) << 8 | (isnan(fVar2) || isnan(fVar1)) << 10 | (fVar2 == fVar1) << 14));
        if (fVar2 == fVar1) {
            fVar1 = param_1[2];
            fVar2 = in_ECX[2];
            uVar3 = CONCAT22((uint16_t)(uVar3 >> 16), (uint16_t)((fVar2 < fVar1) << 8 | (isnan(fVar2) || isnan(fVar1)) << 10 | (fVar2 == fVar1) << 14));
            if (fVar2 == fVar1) {
                uVar3 = FUN_00428470(param_1 + 3);
                if ((char)uVar3 == 0) {
                    fVar1 = param_1[6];
                    fVar2 = in_ECX[6];
                    uVar3 = CONCAT22((uint16_t)(uVar3 >> 16), (uint16_t)((fVar2 < fVar1) << 8 | (isnan(fVar2) || isnan(fVar1)) << 10 | (fVar2 == fVar1) << 14));
                    if (fVar2 == fVar1) {
                        fVar1 = param_1[7];
                        fVar2 = in_ECX[7];
                        uVar3 = CONCAT22((uint16_t)(uVar3 >> 16), (uint16_t)((fVar2 < fVar1) << 8 | (isnan(fVar2) || isnan(fVar1)) << 10 | (fVar2 == fVar1) << 14));
                        if (fVar2 == fVar1) {
                            fVar1 = param_1[8];
                            fVar2 = in_ECX[8];
                            uVar3 = CONCAT22((uint16_t)(uVar3 >> 16), (uint16_t)((fVar2 < fVar1) << 8 | (isnan(fVar2) || isnan(fVar1)) << 10 | (fVar2 == fVar1) << 14));
                            if ((fVar2 == fVar1) && (*(int16_t*)(in_ECX + 9) == *(int16_t*)(param_1 + 9)) && (*(int16_t*)((uintptr_t)in_ECX + 0x26) == *(int16_t*)((uintptr_t)param_1 + 0x26))) {
                                return CONCAT31((int32_t)(uVar3 >> 8), 1);
                            }
                        }
                    }
                }
            }
        }
    }
    return uVar3 & 0xFFFFFF00u;
}

// 0x5bd6e0 — setter for self[5] with listener notification; receiver in_ECX int*, int param
void FUN_005bd6e0(int param_1, int* in_ECX)
{
    if (in_ECX[5] != param_1) {
        in_ECX[5] = param_1;
        int* piVar1 = (int*)(**(int*(*)())(**(int**)(*in_ECX + 0x34)))();
        while (piVar1 != (int*)0x0) {
            (**(code**)(*piVar1 + 0x10))(param_1);
            piVar1 = (int*)(**(int*(*)())(**(int**)(*in_ECX + 0x38)))();
        }
    }
}

// 0x5bd720 — RetrieveShader with renderer check and shader name lookup; receiver in_ECX int*
int FUN_005bd720(char* param_1, uint32_t param_2, int* in_ECX)
{
    if (in_ECX[5] == 0) {
        OutputDebugStringA("Attempting to RetrieveShader w/out a valid renderer!\n");
        return 0;
    }
    if (param_1 != (char*)0x0) {
        int iVar2 = 1;
        bool bVar5 = true;
        char* pcVar3 = param_1;
        char* pcVar4 = "";
        do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar5 = *pcVar3 == *pcVar4;
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (!bVar5) {
            iVar2 = (**(code**)(*in_ECX + 0x18))(param_1, param_2);
            if (iVar2 == 0) {
                int* piVar1 = (int*)(**(int*(*)())(**(int**)(*in_ECX + 0x34)))();
                while (piVar1 != (int*)0x0) {
                    iVar2 = (**(code**)(*piVar1 + 4))(in_ECX[5], param_1, param_2);
                    if (iVar2 != 0) {
                        (**(code**)(*in_ECX + 0x14))(iVar2, param_2);
                        (**(code**)(*(int*)in_ECX[5] + 0x128))(iVar2);
                        FUN_005c9890((void*)(intptr_t)in_ECX[5]);
                        break;
                    }
                    piVar1 = (int*)(**(int*(*)())(**(int**)(*in_ECX + 0x38)))();
                }
            }
            if (((char)(intptr_t)param_1 != '\0') && (iVar2 == 0)) {
                FUN_005477c0(1, 0, "Failed to find shader %s, Implementation %d\n", param_1, param_2);
            }
            return iVar2;
        }
    }
    FUN_005477c0(1, 0, "Attempting to RetrieveShader w/out a valid name!\n");
    return 0;
}

// 0x5bd960 — hash-bucket lookup with comparator; receiver in_ECX int*, int* param_1
uint32_t FUN_005bd960(int* param_1, int* in_ECX)
{
    int iVar2 = (**(code**)(*in_ECX + 4))(param_1);
    int* piVar3 = *(int**)(in_ECX[2] + iVar2 * 4);
    if (piVar3 != (int*)0x0) {
        do {
            char cVar1 = (**(code**)(*in_ECX + 8))(param_1, piVar3[1]);
            if (cVar1 != '\0') {
                *param_1 = piVar3[2];
                return 1;
            }
            piVar3 = (int*)*piVar3;
        } while (piVar3 != (int*)0x0);
    }
    return 0;
}

// 0x5bd9b0 — destructor chain resetting vtables and deleting bucket contents; receiver in_ECX uint32_t*
void FUN_005bd9b0(uint32_t* in_ECX)
{
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c713c;
    if ((*(char*)(in_ECX + 4) != '\0') && (in_ECX[1] != 0)) {
        uint32_t uVar3 = 0;
        do {
            uint32_t* puVar2 = *(uint32_t**)(in_ECX[2] + uVar3 * 4);
            while (puVar2 != (uint32_t*)0x0) {
                uint32_t* puVar1 = puVar2 + 1;
                puVar2 = (uint32_t*)*puVar2;
                operator_delete__((void*)(uintptr_t)*puVar1);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < (uint32_t)in_ECX[1]);
    }
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7030;
    FUN_005e1490();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c6fdc;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
}
// 0x5bdb10 — scalar deleting destructor for 0x5bd9b0; receiver in_ECX void*, byte flag
void FUN_005bdb10(uint8_t param_1, void* in_ECX)
{
    FUN_005bd9b0((uint32_t*)in_ECX);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x5bdb30 — global pointer cleanup with secondary clear and virtual call
void FUN_005bdb30(void)
{
    if (DAT_00728cf4 != (uint32_t*)0x0) {
        FUN_00547790();
        if (DAT_00727864 == DAT_00728cf4) {
            DAT_00727864 = (uint32_t*)0x0;
        }
        if (DAT_00728cf4 != (uint32_t*)0x0) {
            (**(code**)*(void**)DAT_00728cf4)(1);
        }
        DAT_00728cf4 = (uint32_t*)0x0;
    }
}

// 0x5bdc80 — iterate bucket array and process entries with listener callbacks; receiver in_ECX int address
void FUN_005bdc80(uintptr_t in_ECX)
{
    if ((*(int*)(in_ECX + 0x14) != 0) && (*(int*)(in_ECX + 0x18) != 0)) {
        int iVar1 = *(int*)(in_ECX + 0x18);
        int* local_c = (int*)0x0;
        int local_8 = 0;
        if (*(uint32_t*)(iVar1 + 4) != 0) {
            int* piVar4 = *(int**)(iVar1 + 8);
            uint32_t uVar3 = 0;
            do {
                if (*piVar4 != 0) {
                    local_8 = (*(int**)(iVar1 + 8))[uVar3];
                    break;
                }
                uVar3 = uVar3 + 1;
                piVar4 = piVar4 + 1;
            } while (uVar3 < *(uint32_t*)(iVar1 + 4));
        }
        while (local_8 != 0) {
            int local_4_data[4] = {0};
            FUN_005aead0(&local_8, local_4_data, &local_c);
            int* piVar4 = local_c;
            if ((local_c != (int*)0x0) && (**(code**)(*local_c + 0xc))() == 0) {
                FUN_005c9890((void*)(uintptr_t)*(int*)(in_ECX + 0x14));
                (**(code**)(*piVar4 + 0x4c))();
                (**(code**)(**(int**)(in_ECX + 0x14) + 0x128))(piVar4);
            }
        }
    }
}

// 0x5bdd30 — wrapper calling FUN_005bd960 and masking param by result
uint32_t FUN_005bdd30(uint32_t param_1, int* in_ECX)
{
    char cVar1 = (char)FUN_005bd960((int*)&param_1, in_ECX);
    return -(uint32_t)(cVar1 != '\0') & param_1;
}

// 0x5bdd80 — destructor chain mirroring 0x5bd9b0 with different vtables; receiver in_ECX uint32_t*
void FUN_005bdd80(uint32_t* in_ECX)
{
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7158;
    if ((*(char*)(in_ECX + 4) != '\0') && (in_ECX[1] != 0)) {
        uint32_t uVar3 = 0;
        do {
            uint32_t* puVar2 = *(uint32_t**)(in_ECX[2] + uVar3 * 4);
            while (puVar2 != (uint32_t*)0x0) {
                uint32_t* puVar1 = puVar2 + 1;
                puVar2 = (uint32_t*)*puVar2;
                operator_delete__((void*)(uintptr_t)*puVar1);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < (uint32_t)in_ECX[1]);
    }
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c704c;
    FUN_005e1490();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c6ff8;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
}
// 0x5bde00 — destructor chain mirroring 0x5bd9b0 with different vtables; receiver in_ECX uint32_t*
void FUN_005bde00(uint32_t* in_ECX)
{
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7174;
    if ((*(char*)(in_ECX + 4) != '\0') && (in_ECX[1] != 0)) {
        uint32_t uVar3 = 0;
        do {
            uint32_t* puVar2 = *(uint32_t**)(in_ECX[2] + uVar3 * 4);
            while (puVar2 != (uint32_t*)0x0) {
                uint32_t* puVar1 = puVar2 + 1;
                puVar2 = (uint32_t*)*puVar2;
                operator_delete__((void*)(uintptr_t)*puVar1);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < (uint32_t)in_ECX[1]);
    }
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7068;
    FUN_005e1490();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7014;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
}

// 0x5bdf00 — scalar deleting destructor for 0x5bdd80; receiver in_ECX void*, byte flag
void FUN_005bdf00(uint8_t param_1, void* in_ECX)
{
    FUN_005bdd80((uint32_t*)in_ECX);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x5bdfa0 — constructor initializing fields and calling 0x5c9b90/0x5c9cd0; receiver in_ECX uint32_t*
void FUN_005bdfa0(uint32_t* in_ECX, void* param_1, void* param_2, void* param_3, void* param_4)
{
    *in_ECX = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    in_ECX[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7084;
    FUN_005c9b90(in_ECX + 2, param_1);
    in_ECX[3] = (uint32_t)(uintptr_t)param_2;
    FUN_005c9cd0(param_3, param_4);
}

// 0x5be000 — scalar deleting destructor for 0x5be020; receiver in_ECX void*, byte flag
void FUN_005be000(uint8_t param_1, void* in_ECX)
{
    FUN_005be020((uint32_t*)in_ECX);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x5be020 — destructor deleting two fields and decrementing global counter; receiver in_ECX uint32_t*
void FUN_005be020(uint32_t* in_ECX)
{
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7084;
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
    operator_delete__((void*)(uintptr_t)in_ECX[5]);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
}
// 0x5be060 — shader setup validating and linking shader to geometry object; receiver in_ECX int*, unaff_ESI geometry
uint32_t FUN_005be060(int* in_ECX, void* param_1, void* param_2, int param_3, uintptr_t unaff_ESI)
{
    int* piVar4 = (int*)(**(code**)(*in_ECX + 0x10))(param_2, param_3, 1);
    if (piVar4 == (int*)0x0) {
        FUN_005477c0(0x100, 0, "Cannot find shader %s, Implementation %d\n", param_2, param_3);
        return 0;
    }
    if (param_3 == -1) {
        (**(code**)(*piVar4 + 0x54))(1);
    }
    (**(code**)(*piVar4 + 0x10))(in_ECX[5]);
    char cVar3 = (char)(**(code**)(*piVar4 + 8))(unaff_ESI);
    if (cVar3 == '\0') {
        uint32_t uVar5 = FUN_005dbd60();
        FUN_005477c0(1, 0, "SetupGeometry on %s failed\n", (void*)(uintptr_t)uVar5);
    }
    int* piVar2 = *(int**)(unaff_ESI + 200);
    if (piVar2 != piVar4) {
        if (piVar2 != (int*)0x0) {
            int* piVar1 = piVar2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (**(code**)*piVar2)(1);
            }
        }
        *(int**)(unaff_ESI + 200) = piVar4;
        piVar4[1] = piVar4[1] + 1;
    }
    return 1;
}

// 0x5be110 — release geometry shader reference at +200 with refcounting
uint32_t FUN_005be110(int param_1)
{
    if (param_1 == 0) {
        return 0;
    }
    if (*(int*)(param_1 + 200) != 0) {
        FUN_005dbd60();
        uint32_t* puVar2 = *(uint32_t**)(param_1 + 200);
        if (puVar2 != (uint32_t*)0x0) {
            int* piVar1 = (int*)puVar2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (**(code**)*puVar2)(1);
            }
            *(uint32_t*)(param_1 + 200) = 0;
        }
    }
    return 1;
}

// 0x5be160 — lookup-or-create object with refcount bump and registry insertion
uint32_t FUN_005be160(uint32_t param_1, int param_2, uint32_t param_3, uint32_t param_4, int* in_ECX)
{
    uint32_t local_4;
    char cVar1 = (char)FUN_005bd960((int*)&param_1, in_ECX);
    if ((cVar1 == '\0') || (local_4 == 0)) {
        int iVar2 = FUN_00533c78(0x18);
        if (iVar2 != 0) {
            iVar2 = FUN_005bdfa0((void*)(uintptr_t)param_1, (void*)(uintptr_t)param_2, (void*)(uintptr_t)param_3, (void*)(uintptr_t)param_4);
            if (iVar2 != 0) {
                *(int*)(iVar2 + 4) = *(int*)(iVar2 + 4) + 1;
                FUN_00545310((void*)(uintptr_t)*(uint32_t*)(iVar2 + 8), (void*)(uintptr_t)iVar2);
                return 1;
            }
        }
    }
    else if (*(int*)(local_4 + 0xc) == param_2) {
        *(int*)(local_4 + 4) = *(int*)(local_4 + 4) + 1;
        return 1;
    }
    return 0;
}

// 0x5be1e0 — lookup with refcount decrement and virtual release when zero
uint32_t FUN_005be1e0(uint32_t param_1, int* in_ECX)
{
    uint32_t* local_4;
    char cVar2 = (char)FUN_005bd960((int*)&param_1, in_ECX);
    if ((cVar2 == '\0') || (local_4 == (uint32_t*)0x0)) {
        return 0;
    }
    if (local_4[1] == 1) {
        FUN_005bfa50((void*)(uintptr_t)param_1);
    }
    int* piVar1 = (int*)local_4 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
        (**(code**)*local_4)(1);
    }
    return 1;
}

// 0x5be240 — lookup returning object fields at +0x10/+0x14 via out-params
uint32_t FUN_005be240(uint32_t param_1, uint32_t* param_2, uint32_t* param_3, int* in_ECX)
{
    int local_4;
    char cVar1 = (char)FUN_005bd960((int*)&param_1, in_ECX);
    if ((cVar1 == '\0') || (local_4 == 0)) {
        return 0;
    }
    *param_2 = *(uint32_t*)(local_4 + 0x10);
    *param_3 = *(uint32_t*)(local_4 + 0x14);
    return 1;
}
