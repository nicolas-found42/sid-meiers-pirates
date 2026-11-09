// Reconstruction batch mass_0026 — Sid Meier's Pirates! (2004), PE32 i386.
// Each function preserves observed offsets, constants, call order, and control flow
// from the Ghidra 12.2 pseudocode corpus.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ── Globals ────────────────────────────────────────────────────────────────
extern void* DAT_008ecd78;          // audio manager interface (vtable at +0x18)
extern void* DAT_008ed4a8;          // word/property table base (stride 0x58)
extern void* DAT_008ed4a4;          // bounds check global (compared against index)
extern void* DAT_008cacd0;          // file/time database handle
extern void* DAT_0070ab90;          // filename 1
extern void* DAT_0070ab88;          // filename 2
extern void* DAT_008ed4a0;          // audio asset table base (stride 0x40)

// ── Helpers ────────────────────────────────────────────────────────────────
extern void FUN_004985e0();         // error path
extern void FUN_004a14b0();         // error/SAFETY path
extern void FUN_00412f10();         // refcount / lock helper
extern void FUN_00412fb0();         // unlock helper
extern void operator_delete__(void*);
extern void* FUN_005285f0(void*, int, void*, uint32_t, uint32_t, uint32_t, float, uint32_t, float, float, float);
extern void* FUN_00528a10(uint32_t, uint32_t, uint32_t, uint32_t, float, uint32_t, float, float, void*);
extern void* FUN_00528e70(uint32_t, float, float, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void* FUN_00528ee0(uint32_t, float, float, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_00527000(const char*);
extern void FUN_0052f700(uint32_t, float, float, int, int, int, int, uint32_t, uint32_t, int, int);
extern void FUN_0052fbb0(int, uint32_t);
extern void FUN_0052fd80(float);
extern void FUN_0052c4a0(float);
extern void FUN_0052c350();
extern void FUN_0052c4d0(float);
extern int  FUN_0052c980(void*, void*);
extern void* FUN_004f5480(void*, int);
extern void FUN_004fb400(void*);
extern int  FUN_004fb210(int*, void*);

// Internal self-type: functions with an in_ECX / unaff_ESI receiver point at a
// vtable-holder whose *self is a vtable. Modelled as int* (address of pointer).
// For functions where the receiver types differ, use void* and cast inline.

// 0x49f860 — observed shape
void FUN_0049f860(void* self, uint32_t param_1, uint32_t param_2, char param_3) {
    int* pSelf = static_cast<int*>(self);
    int in_ECX;
    // Receiver captured via asm: ECX carries index guard (-1 = none),
    // ES1 points to vtable-holder.
    char cVar1 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
    if (cVar1 != '\0') {
        if (param_3 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
        int* unaff_ESI = static_cast<int*>(self);
        if (unaff_ESI != nullptr && *unaff_ESI != 0) {
            if (in_ECX != -1) {
                int iVar2 = (**(code**)(*unaff_ESI + 0xcc))();
                if (iVar2 == 0) return;
                int* piVar3 = (int*)(**(code**)(*unaff_ESI + 0xcc))();
                if (in_ECX != *piVar3) return;
            }
            (**(code**)(*unaff_ESI + 0x98))(2);
            (**(code**)(*unaff_ESI + 0x78))(param_1);
            (**(code**)(*unaff_ESI + 0x68))();
        }
    }
    (void)param_2;
}

// 0x49f930 — observed shape
// Self = param_1 (int, object with flag @+0x274f). param_3 = refcounted handle.
// param_10 = out pointer. param_13 = cleanup flag. param_11 = gain.
void FUN_0049f930(int param_1, uint32_t param_2, uint32_t* param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, float param_7, int param_8, int param_9,
                  uint32_t** param_10, float param_11, float param_12, char param_13)
{
    float uVar1 = param_12;
    uint32_t in_EDX;
    if (*reinterpret_cast<char*>(param_1 + 0x274f) == '\0') {
        if (param_13 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            if (param_3 == nullptr) return;
            uint32_t* piVar2 = param_3 + 1;
            *piVar2 = *piVar2 + (-1);
            if (*piVar2 == 0) {
                (**(code**)*param_3)(1);
                return;
            }
            return;
        }
    } else if (param_13 != '\0') {
        if (param_3 == nullptr) return;
        uint32_t* piVar2 = param_3 + 1;
        *piVar2 = *piVar2 + (-1);
        if (*piVar2 == 0) {
            (**(code**)*param_3)(1);
            return;
        }
        return;
    }
    float _param_13;
    if (param_7 == -NAN) { param_12 = -1.0f; }
    else { param_12 = (float)(int)param_7 * 0.01f; }
    if (param_9 == -1) { _param_13 = -1.0f; }
    else { _param_13 = (float)param_9; }
    float _param_7;
    if (param_8 == -1) { _param_7 = -1.0f; }
    else { _param_7 = (float)param_8; }
    if (param_3 != nullptr) {
        param_3[1] = param_3[1] + 1;
    }
    int* piVar2 = static_cast<int*>(FUN_005285f0(&DAT_008ecd78, 0, param_3, param_4, param_5, param_6, param_12, in_EDX, _param_7, _param_13, uVar1));
    if (piVar2 != nullptr && param_10 != nullptr && (*param_10 = piVar2, 0.0f < param_11)) {
        (**(code**)(*piVar2 + 0x3c))(param_11, 0xbf800000, 0, 0xbf800000);
    }
    if (param_3 != nullptr) {
        uint32_t* piVar2b = param_3 + 1;
        *piVar2b = *piVar2b + (-1);
        if (*piVar2b == 0) {
            (**(code**)*param_3)(1);
        }
    }
    (void)param_2;
}

// 0x49fb80 — observed shape
// param_1/params: object with flag @+0x274f. param_2 = id (0..0xf3). param_3 = refcounted handle.
void FUN_0049fb80(int param_1, int param_2, uint32_t* param_3) {
    int* in_ECX;
    char in_stack_00000034;
    if (*reinterpret_cast<char*>(param_1 + 0x274f) == '\0') {
        if (in_stack_00000034 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            if (param_3 == nullptr) return;
            uint32_t* piVar1 = param_3 + 1;
            *piVar1 = *piVar1 + (-1);
            if (*piVar1 == 0) {
                (**(code**)*param_3)();
                return;
            }
            return;
        }
    } else if (in_stack_00000034 != '\0') {
        goto LAB_0049fbae;
    }
    if ((param_2 < 0) || (0xf3 < param_2)) {
LAB_0049fbae:
        if (param_3 != nullptr) {
            uint32_t* piVar1 = param_3 + 1;
            *piVar1 = *piVar1 + (-1);
            if (*piVar1 == 0) {
                (**(code**)*param_3)();
            }
        }
        return;
    }
    int iVar2 = *reinterpret_cast<int*>(reinterpret_cast<char*>(DAT_008ed4a8) + param_2 * 0x58 + 4);
    bool bVar3;
    if (in_ECX != nullptr && *in_ECX != 0) {
        int iVar5 = (**(code**)(*in_ECX + 0x7c))();
        bVar3 = true;
        if (iVar5 == iVar2) goto LAB_0049fce6;
    }
    bVar3 = false;
LAB_0049fce6:
    if ((in_ECX == nullptr) || (*in_ECX == 0) ||
        ((**(code**)(*in_ECX + 0x40))() == '\0') || (!bVar3)) {
        if (param_3 != nullptr) {
            param_3[1] = param_3[1] + 1;
        }
        FUN_0049f930(param_1, param_2, param_3, 0, 0, 0, 0.0f, -1, -1, nullptr, 0.0f, 0.0f, 0);
    }
    if (param_3 == nullptr) return;
    uint32_t* piVar1 = param_3 + 1;
    *piVar1 = *piVar1 + (-1);
    if (*piVar1 == 0) {
        (**(code**)*param_3)();
        return;
    }
    return;
}

// 0x49fda0 — observed shape
void FUN_0049fda0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, int param_6, int param_7, int param_8, uint32_t* param_9,
                  uint32_t param_10, char param_11)
{
    uint32_t in_EDX;
    uint32_t* pOut = reinterpret_cast<uint32_t*>(&in_EDX);
    if (*reinterpret_cast<char*>(param_1 + 0x274f) == '\0') {
        if (param_11 != '\0') {
            FUN_00412f10();
            FUN_004985e0();
            FUN_004a14b0();
            if (param_9 == nullptr) return;
            uint32_t* piVar1 = param_9 + 1;
            *piVar1 = *piVar1 + (-1);
            if (*piVar1 == 0) {
                (**(code**)*param_9)(1);
                return;
            }
            return;
        }
    } else if (param_11 != '\0') {
        if (param_9 == nullptr) return;
        uint32_t* piVar1 = param_9 + 1;
        *piVar1 = *piVar1 + (-1);
        if (*piVar1 == 0) {
            (**(code**)*param_9)(1);
            return;
        }
        return;
    }
    if (param_9 != nullptr) {
        param_9[1] = param_9[1] + 1;
    }
    uint32_t uVar2 = reinterpret_cast<uint32_t>(FUN_00528a10(param_2, param_3, param_4, param_5,
        (float)param_6 * 0.01f, 0, (float)param_7, (float)param_8, param_9));
    if (pOut != nullptr) {
        *pOut = uVar2;
    }
    if (param_9 != nullptr) {
        uint32_t* piVar1 = param_9 + 1;
        *piVar1 = *piVar1 + (-1);
        if (*piVar1 == 0) {
            (**(code**)*param_9)(1);
        }
    }
    (void)param_10;
}

// 0x49ff70 — observed shape
void FUN_0049ff70(void* self, uint32_t param_1, float param_2) {
    int* unaff_ESI = static_cast<int*>(self);
    int in_ECX;
    char in_AL;
    (void)param_1;
    if (in_AL != '\0') {
        FUN_004985e0();
        FUN_004a14b0();
        return;
    }
    if (unaff_ESI == nullptr) return;
    if (*unaff_ESI == 0) return;
    if (in_ECX != -1) {
        int iVar1 = (**(code**)(*unaff_ESI + 0xf0))();
        if (iVar1 == 0) return;
        int* piVar2 = (int*)(**(code**)(*unaff_ESI + 0xf0))();
        if (in_ECX != *piVar2) return;
    }
    if (NAN(param_2) || param_2 < 0.0f == (param_2 == 0.0f)) {
        (**(code**)(*unaff_ESI + 0x38))(param_2, 0xbf800000, 0, 0xbf800000);
        *unaff_ESI = 0;
        return;
    }
    (**(code**)(*unaff_ESI + 0x5c))(1);
    *unaff_ESI = 0;
    return;
}

// 0x4a0040 — observed shape
void FUN_004a0040(void* self, uint32_t param_1, uint32_t param_2, char param_3) {
    int* unaff_ESI = static_cast<int*>(self);
    int in_EAX;
    (void)param_1;
    char cVar1 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
    if (cVar1 != '\0') {
        if (param_3 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
        if (unaff_ESI != nullptr && *unaff_ESI != 0) {
            if (in_EAX != -1) {
                int iVar2 = (**(code**)(*unaff_ESI + 0xf0))();
                if (iVar2 == 0) return;
                int* piVar3 = (int*)(**(code**)(*unaff_ESI + 0xf0))();
                if (in_EAX != *piVar3) return;
            }
            (**(code**)(*unaff_ESI + 0x38))(param_2, 0xbf800000, 0, 0xbf800000);
        }
    }
}

// 0x4a0100 — observed shape
void FUN_004a0100(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, char param_5) {
    int* unaff_ESI = static_cast<int*>(self);
    int in_EAX;
    (void)param_1;
    char cVar1 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
    if (cVar1 != '\0') {
        if (param_5 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
        if (unaff_ESI != nullptr && *unaff_ESI != 0) {
            if (in_EAX != -1) {
                int iVar2 = (**(code**)(*unaff_ESI + 0xf0))();
                if (iVar2 == 0) {
LAB_004a01b4:
                    *unaff_ESI = 0;
                    return;
                }
                int* piVar3 = (int*)(**(code**)(*unaff_ESI + 0xf0))();
                if (in_EAX != *piVar3) goto LAB_004a01b4;
            }
            (**(code**)(*unaff_ESI + 0xc0))(&param_2);
        }
    }
    (void)param_3;
    (void)param_4;
}

// 0x4a01e0 — observed shape
void FUN_004a01e0(void* self, uint32_t param_1, uint32_t param_2, char param_3) {
    int* unaff_ESI = static_cast<int*>(self);
    int in_EAX;
    (void)param_1;
    char cVar1 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
    if (cVar1 != '\0') {
        if (param_3 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
        if (unaff_ESI != nullptr && *unaff_ESI != 0) {
            if (in_EAX != -1) {
                int iVar2 = (**(code**)(*unaff_ESI + 0xf0))();
                if (iVar2 == 0) return;
                int* piVar3 = (int*)(**(code**)(*unaff_ESI + 0xf0))();
                if (in_EAX != *piVar3) return;
            }
            (**(code**)(*unaff_ESI + 0x60))(param_2, 0);
        }
    }
}

// 0x4a02a0 — observed shape
void FUN_004a02a0(void* self, uint32_t param_1, char param_2) {
    int* unaff_ESI = static_cast<int*>(self);
    int in_ECX;
    (void)param_1;
    char cVar1 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
    if (cVar1 != '\0') {
        if (param_2 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
        if (unaff_ESI != nullptr && *unaff_ESI != 0) {
            if (in_ECX != -1) {
                int iVar2 = (**(code**)(*unaff_ESI + 0xf0))();
                if (iVar2 == 0) return;
                int* piVar3 = (int*)(**(code**)(*unaff_ESI + 0xf0))();
                if (in_ECX != *piVar3) return;
            }
            (**(code**)(*unaff_ESI + 0x98))(2);
            (**(code**)(*unaff_ESI + 0x68))();
        }
    }
}

// 0x4a0360 — observed shape
void FUN_004a0360(void* self, uint32_t param_1, uint32_t param_2, char param_3) {
    int* unaff_ESI = static_cast<int*>(self);
    int in_ECX;
    (void)param_1;
    (void)param_2;
    char cVar1 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
    if (cVar1 != '\0') {
        if (param_3 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
        if (unaff_ESI != nullptr && *unaff_ESI != 0) {
            if (in_ECX != -1) {
                int iVar2 = (**(code**)(*unaff_ESI + 0xf0))();
                if (iVar2 == 0) return;
                int* piVar3 = (int*)(**(code**)(*unaff_ESI + 0xf0))();
                if (in_ECX != *piVar3) return;
            }
            (**(code**)(*unaff_ESI + 0x98))(2);
            (**(code**)(*unaff_ESI + 0x78))(param_1);
            (**(code**)(*unaff_ESI + 0x68))();
        }
    }
}

// 0x4a0430 — observed shape
void FUN_004a0430(void* self, uint32_t param_1, float param_2) {
    int* in_EAX = static_cast<int*>(self);
    char in_CL;
    (void)param_1;
    if (in_CL != '\0') {
        FUN_004985e0();
        FUN_004a14b0();
        return;
    }
    if (in_EAX != nullptr && *in_EAX != 0 && *reinterpret_cast<char*>(*in_EAX + 0x32) != '\0') {
        if (0.0f < param_2) {
            FUN_0052c4a0(param_2);
            return;
        }
        FUN_0052c350();
    }
}

// 0x4a04d0 — observed shape
void FUN_004a04d0(void* self, uint32_t param_1, float param_2) {
    int* in_EAX = static_cast<int*>(self);
    char in_DL;
    (void)param_1;
    if (in_DL != '\0') {
        FUN_004985e0();
        FUN_004a14b0();
        return;
    }
    if (param_2 == -NAN) {
        param_2 = -1.0f;
    } else {
        param_2 = (float)(int)param_2 * 0.01f;
    }
    if (in_EAX != nullptr && *in_EAX != 0) {
        FUN_0052c4d0(param_2);
    }
}

// 0x4a0560 — observed shape
void FUN_004a0560(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, float param_5,
                  int param_6, uint32_t param_7, char param_8)
{
    uint32_t in_EAX;
    uint32_t in_ECX;
    uint32_t in_EDX;
    if (*reinterpret_cast<char*>(param_1 + 0x274f) == '\0') {
        if (param_8 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
    } else if (param_8 != '\0') {
        return;
    }
    float _param_8;
    if (param_5 == -NAN) {
        param_5 = -1.0f;
    } else {
        param_5 = (float)(int)param_5 * 0.01f;
    }
    if (param_6 == -1) {
        _param_8 = -1.0f;
    } else {
        _param_8 = ((float)param_6 + 100.0f) * 0.005f;
    }
    FUN_00528e70(param_2, param_5, _param_8, param_7, in_EDX, param_3, param_4, in_ECX, in_EAX);
    *reinterpret_cast<uint8_t*>(param_1 + 0x274e) = 1;
}

// 0x4a06c0 — observed shape
void FUN_004a06c0(int unaff_ESI, uint32_t param_1, uint32_t param_2, float param_3) {
    char in_AL;
    uint32_t in_EDX;
    if (*reinterpret_cast<char*>(unaff_ESI + 0x274f) == '\0' || in_AL == '\0') {
        *reinterpret_cast<uint32_t*>(unaff_ESI + 0x2750) = 0xffffffffu;
        if (in_AL != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
        if (param_3 == -NAN) {
            param_3 = -1.0f;
        } else {
            param_3 = (float)(int)param_3 * 0.01f;
        }
        char cVar1 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
        if (cVar1 == '\0') {
            FUN_00527000("The audio manager has not been properly initialized yet");
            return;
        }
        FUN_0052f700(param_1, param_3, 0x3f000000, 0, 0, 0, 0, in_EDX, param_2, 1, 1);
    }
    (void)unaff_ESI;
}

// 0x4a07c0 — observed shape
void FUN_004a07c0(int unaff_ESI, uint32_t param_1, uint32_t param_2, float param_3) {
    char in_AL;
    uint32_t in_EDX;
    if (*reinterpret_cast<char*>(unaff_ESI + 0x274f) == '\0') {
        if (in_AL != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
    } else if (in_AL != '\0') {
        return;
    }
    if (param_3 == -NAN) {
        param_3 = -1.0f;
    } else {
        param_3 = (float)(int)param_3 * 0.01f;
    }
    char cVar1 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
    if (cVar1 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        return;
    }
    FUN_0052f700(param_1, param_3, 0x3f000000, 0, 0, 0, 0, in_EDX, param_2, 1, 0);
}

// 0x4a08b0 — observed shape
void FUN_004a08b0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, float param_5,
                  int param_6, uint32_t param_7, char param_8)
{
    uint32_t in_EAX;
    uint32_t in_ECX;
    uint32_t in_EDX;
    if (*reinterpret_cast<char*>(param_1 + 0x274f) == '\0') {
        if (param_8 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
    } else if (param_8 != '\0') {
        return;
    }
    float _param_8;
    if (param_5 == -NAN) {
        param_5 = -1.0f;
    } else {
        param_5 = (float)(int)param_5 * 0.01f;
    }
    if (param_6 == -1) {
        _param_8 = -1.0f;
    } else {
        _param_8 = ((float)param_6 + 100.0f) * 0.005f;
    }
    FUN_00528ee0(param_2, param_5, _param_8, param_7, in_EDX, param_3, param_4, in_ECX, in_EAX);
}

// 0x4a0a10 — observed shape
void FUN_004a0a10(uint32_t param_1, uint32_t param_2) {
    int in_EAX;
    char in_CL;
    (void)param_1;
    if (in_CL != '\0') {
        FUN_004985e0();
        FUN_004a14b0();
        return;
    }
    int iVar1 = *reinterpret_cast<int*>(reinterpret_cast<char*>(DAT_008ed4a0) + in_EAX * 0x40 + 4);
    if (iVar1 != -1) {
        char cVar2 = (**(code**)(*reinterpret_cast<int*>(DAT_008ecd78) + 0x18))();
        if (cVar2 == '\0') {
            FUN_00527000("The audio manager has not been properly initialized yet");
            return;
        }
        FUN_0052fbb0(iVar1, param_2);
    }
}

// 0x4a0ac0 — observed shape
void FUN_004a0ac0(void* self, uint32_t param_1, int param_2) {
    int* unaff_ESI = static_cast<int*>(self);
    int in_ECX;
    char in_AL;
    (void)param_1;
    if (in_AL != '\0') {
        FUN_004985e0();
        FUN_004a14b0();
        return;
    }
    if (unaff_ESI != nullptr && *unaff_ESI != 0) {
        int iVar1 = (**(code**)(*unaff_ESI + 0xcc))();
        if (iVar1 != 0) {
            iVar1 = (**(code**)(*unaff_ESI + 0xcc))();
            if (iVar1 != 0) {
                int* piVar2 = (int*)(**(code**)(*unaff_ESI + 0xcc))();
                if (*piVar2 != in_ECX) {
                    return;
                }
            }
            FUN_0052fd80((float)param_2 * 0.01f);
        }
    }
}

// 0x4a0b70 — observed shape
// NEEDS_MANUAL: receiver in in_EAX (index/slot) is a scratch register value;
// preserved as explicit int parameter to keep the switch shape exact.
int FUN_004a0b70(int in_EAX) {
    switch (in_EAX) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 3;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9: return in_EAX + 1;
    case 10: return 0xb;
    case 0xb: return 0xc;
    case 0xc: return 0xd;
    case 0xd: return 0x15;
    case 0xe: return 0x18;
    case 0xf: return 0x1b;
    default: return -1;
    }
}

// 0x4a0c00 — observed shape
uint32_t FUN_004a0c00(void* self, int in_EAX) {
    int in_ECX = reinterpret_cast<int>(self);
    if (in_EAX < 0 || reinterpret_cast<int>(DAT_008ed4a4) < in_EAX) {
        return 0;
    }
    int* piVar3 = reinterpret_cast<int*>(in_ECX + 0x2754);
    if (*reinterpret_cast<void**>(in_ECX + 0x2758) != nullptr) {
        operator_delete__(*reinterpret_cast<void**>(in_ECX + 0x2758));
        *reinterpret_cast<uint32_t*>(in_ECX + 0x2758) = 0;
    }
    *piVar3 = 0;
    FUN_00412f10();
    FUN_0052c980(&DAT_008cacd0, &DAT_0070ab90);
    FUN_00412f10();
    FUN_0052c980(&DAT_008cacd0, &DAT_0070ab88);
    FUN_00412f10();
    FILETIME* lpFileTime1 = static_cast<FILETIME*>(FUN_004f5480(&DAT_008cacd0, 0));
    FILETIME* lpFileTime2 = static_cast<FILETIME*>(FUN_004f5480(&DAT_008cacd0, 0));
    if (lpFileTime1 == nullptr ||
        (CompareFileTime(lpFileTime1, lpFileTime2) < 0)) {
        FUN_004fb400(&DAT_008cacd0);
    }
    if (*piVar3 == 0 && FUN_004fb210(piVar3, &DAT_008cacd0) != 0) {
        FUN_00412fb0();
        FUN_00412fb0();
        FUN_00412fb0();
        return 0;
    }
    return 1;
}
