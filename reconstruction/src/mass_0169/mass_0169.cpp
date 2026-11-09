#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// Helpers referenced by the listings below.
// ---------------------------------------------------------------------------
extern void FUN_00576720(void* a, void* b);
extern void FUN_005351e0(void* a);
extern void FUN_0056e040(float* param_1, float param_2, float* param_3, int param_4,
                         float param_5, int* param_6);
extern char FUN_00576290(void* a, int b);
extern void FUN_0059aac0(int a);
extern void* thunk_FUN_00533c78(int size);
extern void FUN_0056a8b0(void* a, int b);
extern void operator_delete__(void* p);
extern uint32_t FUN_00538360(uint32_t a);
extern void* FUN_0053c9e0(void* dst, float value);
extern void FUN_00573d80(void* a, void* b);
extern void FUN_005606f0(uint32_t idx, void** p);
extern void FUN_0056e940(void* self, int* param_1);
extern void FUN_0056a050(void* dst, float t, int curve, int dim, int interp, float* out);
extern uint32_t FUN_00555c50(void* a, void* b);
extern void FUN_00555bc0(void* a, uint32_t b);
extern void FUN_00520da0(void* a);
extern void* FUN_0053ca60(void* a, void* b);
extern void FUN_00540e40(int* a);
extern void FUN_00573bd0(void* a, void* b);
extern void FUN_00574040(void* a, void* b);
extern void FUN_0053cc20(void* a);
extern void FUN_0053c8d0(void* a, void* b);
extern int FUN_00449390(void* a, int b);
extern int FUN_00552ec0(int a);
extern void FUN_005802d0(uint32_t a, uint32_t b, int c, uint32_t d);
extern void FUN_0056e790(void* self);
extern void FUN_0056e810(void* self, char param_1);
extern void FUN_0056eed0(void* self, uint32_t param_1);
extern void FUN_004aaef0(void);
extern void FUN_00497420(void);
extern void FUN_0056e300(void* param_1, int param_2);
extern void FUN_0056e4c0(void* param_1, int param_2, int param_3);
extern int* FUN_0056e410(int param_1);

// Data / function-table globals.
extern float DAT_007283b8;
extern float DAT_007283bc;
extern float DAT_007283c0;
extern float DAT_007283c4;
extern char DAT_007283b6;
extern char DAT_007283c8;
extern uint32_t _DAT_007288e4;
extern uint32_t _DAT_007287f4;
extern uint32_t _DAT_0072877c;
extern uint32_t _DAT_00728434;
extern uint32_t _DAT_007284ac;
extern uint32_t _DAT_007288ac;
extern uint32_t _DAT_007287bc;
extern uint32_t _DAT_00728744;
extern void* _DAT_0072895c;
extern void* _DAT_0072868c;
extern void* _DAT_00728614;
extern void* _DAT_0072859c;
extern void* _DAT_00728524;
extern void* _DAT_0072886c;
extern void* _DAT_00728704;
extern void* _DAT_00728924;
extern void* _DAT_00728654;
extern void* _DAT_007285dc;
extern void* _DAT_007284ec;
extern void* _DAT_00728834;
extern void* _DAT_007286cc;
extern void* _DAT_007283fc;
extern void* _DAT_00728474;
extern void* DAT_00728564;
extern uint8_t LAB_0056e010;
extern uint8_t LAB_0056e450;
extern uint8_t LAB_0056e3c0;
extern uint8_t LAB_0056b110;
extern uint8_t LAB_0056e3e0;
extern uint8_t LAB_0056e4f0;
extern uint8_t DAT_0056e3b0;
extern uint32_t DAT_00728a3c;
extern uint32_t DAT_00727560;
extern uint32_t DAT_007179b0[9];
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint8_t DAT_007273fc;

// The listings carry several raw integer "addresses"; this recovers a pointer.
static inline char* at(intptr_t addr) { return (char*)addr; }

// ---------------------------------------------------------------------------
// 0x56dff0
// ---------------------------------------------------------------------------
// 0x56dff0 — observed shape
void FUN_0056dff0(void* param_1, void* param_2)
{
    FUN_00576720(param_1, param_2);
    FUN_005351e0(param_1);
}

// ---------------------------------------------------------------------------
// 0x56e040
// ---------------------------------------------------------------------------
// 0x56e040 — observed shape
void FUN_0056e040(float* param_1, float param_2, float* param_3, int param_4,
                  float param_5, int* param_6)
{
    uint32_t uVar1;
    float fVar2;
    float fVar3 = 0.0f;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;
    float local_10;
    float local_c;
    float local_8;
    float local_4;

    // Element stride is the byte stored at param_3 + 4; elements live at
    // param_3 + index * stride.
    auto elem = [param_3](uint32_t idx) -> float* {
        uint32_t stride = *(uint8_t*)((char*)param_3 + 4);
        return (float*)((char*)param_3 + idx * stride);
    };

    iVar5 = (int)param_5;
    if (param_5 == 1.4013e-45f) { // listing compares the raw float word against 1
        *param_1 = param_3[2];
        param_1[1] = param_3[3];
        param_1[2] = param_3[4];
        param_1[3] = param_3[5];
        return;
    }
    uVar1 = (uint32_t)((int)param_5 - 1);
    param_5 = *elem((uint32_t)*param_6);
    if (param_2 < param_5) {
        *param_6 = 0;
        param_5 = *param_3;
    }
    uVar6 = (uint32_t)*param_6 + 1;
    if (3 < (int)((uVar1 - uVar6) + 1)) {
        iVar7 = *param_6 + 3;
        do {
            fVar2 = *elem(uVar6);
            fVar3 = fVar2;
            if ((!std::isnan(param_2) && !std::isnan(fVar2)) &&
                ((param_2 < fVar2) != (param_2 == fVar2)))
                goto LAB_0056e1ad;
            iVar4 = *param_6;
            *param_6 = iVar4 + 1;
            param_5 = *elem((uint32_t)(iVar7 - 1));
            if ((!std::isnan(param_2) && !std::isnan(param_5)) &&
                ((param_2 < param_5) != (param_2 == param_5))) {
                uVar6 = uVar6 + 1;
                fVar3 = param_5;
                param_5 = fVar2;
                goto LAB_0056e1ad;
            }
            *param_6 = iVar4 + 2;
            fVar2 = *elem((uint32_t)iVar7);
            if ((!std::isnan(param_2) && !std::isnan(fVar2)) &&
                ((param_2 < fVar2) != (param_2 == fVar2))) {
                uVar6 = uVar6 + 2;
                fVar3 = fVar2;
                goto LAB_0056e1ad;
            }
            *param_6 = iVar4 + 3;
            param_5 = *elem((uint32_t)(iVar7 + 1));
            if ((!std::isnan(param_2) && !std::isnan(param_5)) &&
                ((param_2 < param_5) != (param_2 == param_5))) {
                uVar6 = uVar6 + 3;
                fVar3 = param_5;
                param_5 = fVar2;
                goto LAB_0056e1ad;
            }
            *param_6 = iVar4 + 4;
            uVar6 = uVar6 + 4;
            iVar7 = iVar7 + 4;
        } while (uVar6 <= (uint32_t)iVar5 - 4U);
    }
    for (;;) {
        fVar3 = param_5;
        if (!(uVar6 <= uVar1)) break;
        fVar3 = *elem(uVar6);
        if (!((std::isnan(param_2) || std::isnan(fVar3)) ||
              ((param_2 < fVar3) == (param_2 == fVar3))))
            break;
        uVar6 = uVar6 + 1;
        *param_6 = *param_6 + 1;
        param_5 = fVar3;
    }
LAB_0056e1ad:
    local_10 = 0.0f;
    local_c = 0.0f;
    local_8 = 0.0f;
    local_4 = 0.0f;
    {
        // Listing: (**(code **)(&DAT_0072886c + param_4 * 4))(...)
        typedef void (*InterpFn)(float t, float* a, float* b, float* out);
        InterpFn fn = *(InterpFn*)((char*)&_DAT_0072886c + param_4 * 4);
        fn((param_2 - param_5) / (fVar3 - param_5),
           elem((uint32_t)*param_6),
           elem(uVar6),
           &local_10);
    }
    *param_1 = local_10;
    param_1[1] = local_c;
    param_1[2] = local_8;
    param_1[3] = local_4;
}

// ---------------------------------------------------------------------------
// 0x56e240
// ---------------------------------------------------------------------------
// 0x56e240 — observed shape
float* FUN_0056e240(float* param_1, float param_2, float* param_3, uint32_t param_4, int param_5)
{
    int iVar1;

    iVar1 = param_5;
    if (param_5 == 0) {
        param_1[0] = DAT_007283b8;
        param_1[1] = DAT_007283bc;
        param_1[2] = DAT_007283c0;
        param_1[3] = DAT_007283c4;
        return param_1;
    }
    if (*param_3 <= param_2) {
        if (param_2 <= *(float*)((char*)param_3 +
                                 (param_5 - 1) * (uint32_t)*(uint8_t*)((char*)param_3 + 4))) {
            param_5 = 0; // reused as the interpolation index output
            FUN_0056e040(param_1, param_2, param_3, (int)param_4, (float)iVar1, &param_5);
            return param_1;
        }
        param_3 = (float*)((char*)param_3 + 8 +
                           (param_5 - 1) * (uint32_t)*(uint8_t*)((char*)param_3 + 4));
    } else {
        param_3 = param_3 + 2;
    }
    param_1[0] = param_3[0];
    param_1[1] = param_3[1];
    param_1[2] = param_3[2];
    param_1[3] = param_3[3];
    return param_1;
}

// ---------------------------------------------------------------------------
// 0x56e300
// ---------------------------------------------------------------------------
// 0x56e300 — observed shape
void FUN_0056e300(void* param_1, int param_2)
{
    char cVar1;

    cVar1 = FUN_00576290(param_1, param_2);
    if (cVar1 == '\0') {
        return;
    }
    FUN_0059aac0(param_2 + 8);
}

// ---------------------------------------------------------------------------
// 0x56e330
// ---------------------------------------------------------------------------
// 0x56e330 — observed shape
uint32_t FUN_0056e330(void)
{
    if (DAT_007283b6 == '\0') {
        _DAT_007288e4 = 0;
        _DAT_007287f4 = 0;
        _DAT_0072877c = 0;
        _DAT_00728434 = 0;
        _DAT_007284ac = 0;
        DAT_007283b6 = 1;
        _DAT_0072895c = (void*)&FUN_004aaef0;
        _DAT_0072868c = (void*)&FUN_00497420;
        _DAT_00728614 = (void*)&FUN_00497420;
        _DAT_0072859c = (void*)&FUN_004aaef0;
        _DAT_00728524 = (void*)&FUN_00497420;
        _DAT_0072886c = (void*)&LAB_0056e010; // listing: &LAB_0056e010
        _DAT_00728704 = (void*)&FUN_0056e300;
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x56e410
// ---------------------------------------------------------------------------
// 0x56e410 — observed shape
int* FUN_0056e410(int param_1)
{
    int* piVar1;
    int* piVar2;

    piVar1 = (int*)thunk_FUN_00533c78(param_1 * 0xc + 4);
    if (piVar1 == (int*)0x0) {
        piVar2 = (int*)0x0;
    } else {
        *piVar1 = param_1;
        piVar2 = piVar1 + 1;
        if (-1 < param_1 + -1) {
            piVar1 = piVar1 + 2;
            do {
                *(uint8_t*)piVar1 = 0xc;
                piVar1 = piVar1 + 3;
                param_1 = param_1 + -1;
            } while (param_1 != 0);
            return piVar2;
        }
    }
    return piVar2;
}

// ---------------------------------------------------------------------------
// 0x56e4c0
// ---------------------------------------------------------------------------
// 0x56e4c0 — observed shape
void FUN_0056e4c0(void* param_1, int param_2, int param_3)
{
    if (param_3 != 0) {
        do {
            FUN_0056a8b0(param_1, param_2);
            param_2 = param_2 + 0xc;
            param_3 = param_3 + -1;
        } while (param_3 != 0);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x56e610
// ---------------------------------------------------------------------------
// 0x56e610 — observed shape
uint32_t FUN_0056e610(void)
{
    if (DAT_007283c8 == '\0') {
        _DAT_007288ac = 0;
        _DAT_007287bc = 0;
        _DAT_00728744 = 0;
        DAT_007283c8 = 1;
        _DAT_00728924 = (void*)&LAB_0056e450;
        _DAT_00728654 = (void*)&FUN_0056e4c0;
        _DAT_007285dc = (void*)&LAB_0056e3c0;
        DAT_00728564 = (void*)&FUN_0056e410;
        _DAT_007284ec = (void*)&LAB_0056b110;
        _DAT_00728834 = (void*)&LAB_0056e3e0;
        _DAT_007286cc = (void*)&DAT_0056e3b0;
        _DAT_007283fc = (void*)&FUN_00497420;
        _DAT_00728474 = (void*)&LAB_0056e4f0;
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x56e6a0
// ---------------------------------------------------------------------------
// 0x56e6a0 — observed shape
void FUN_0056e6a0(void* self, char* param_1)
{
    char cVar1;
    char* pcVar2;
    uint8_t* s = (uint8_t*)self;

    operator_delete__(*(void**)(s + 0xa8));
    *(uint32_t*)(s + 0xa8) = 0;
    if (param_1 != (char*)0x0) {
        pcVar2 = param_1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = (char*)thunk_FUN_00533c78((int)(pcVar2 - param_1));
        *(char**)(s + 0xa8) = pcVar2;
        do {
            cVar1 = *param_1;
            param_1 = param_1 + 1;
            *pcVar2 = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x56e700
// ---------------------------------------------------------------------------
// 0x56e700 — observed shape
void FUN_0056e700(void* self)
{
    void* pvVar1;
    uint32_t uVar2;
    uint8_t* s = (uint8_t*)self;

    uVar2 = 0;
    if (*(int*)(s + 0x20) != 0) {
        do {
            operator_delete__(*(void**)(*(int*)(s + 0x18) + uVar2 * 4));
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(s + 0x20));
    }
    uVar2 = 0;
    if (*(int*)(s + 0x20) != 0) {
        do {
            *(uint32_t*)(*(int*)(s + 0x18) + uVar2 * 4) = 0;
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(s + 0x20));
    }
    *(uint32_t*)(s + 0x20) = 0;
    *(uint32_t*)(s + 0x24) = 0;
    if (*(int*)(s + 0x1c) != 0) {
        pvVar1 = *(void**)(s + 0x18);
        *(uint32_t*)(s + 0x1c) = 0;
        *(uint32_t*)(s + 0x18) = 0;
        operator_delete__(pvVar1);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x56e790
// ---------------------------------------------------------------------------
// 0x56e790 — observed shape
void FUN_0056e790(void* self)
{
    int* piVar1;
    uint32_t uVar2;
    uint8_t* s = (uint8_t*)self;

    uVar2 = 0;
    if (*(int*)(s + 0x38) != 0) {
        do {
            piVar1 = *(int**)(*(int*)(s + 0x30) + uVar2 * 4);
            if (piVar1 != (int*)0x0) {
                (*(void (**)(int))(*(int*)piVar1 + 0x40))(0);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(s + 0x38));
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x56e7c0
// ---------------------------------------------------------------------------
// 0x56e7c0 — observed shape
uint32_t FUN_0056e7c0(void* self, uint32_t param_1)
{
    int* piVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint8_t* s = (uint8_t*)self;

    uVar2 = FUN_00538360(param_1);
    if ((char)uVar2 == '\0') {
        return uVar2;
    }
    if (*(int**)(s + 0x10) != (int*)0x0) {
        (*(void (**)(uint32_t))(**(int**)(s + 0x10) + 0x14))(param_1);
    }
    uVar3 = 0;
    if (*(int*)(s + 0x38) != 0) {
        uVar4 = 0;
        do {
            piVar1 = *(int**)(*(int*)(s + 0x30) + uVar4 * 4);
            if (piVar1 != (int*)0x0) {
                (*(void (**)(uint32_t))(*(int*)piVar1 + 0x14))(param_1);
            }
            uVar3 = *(uint32_t*)(s + 0x38);
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar3);
    }
    // CONCAT31((int3)(uVar3 >> 8), 1)
    return (uVar3 & 0xffffff00u) | 1;
}

// ---------------------------------------------------------------------------
// 0x56e810
// ---------------------------------------------------------------------------
// 0x56e810 — observed shape
void FUN_0056e810(void* self, char param_1)
{
    int iVar1;
    uint32_t local_30;
    uint32_t local_2c;
    uint32_t local_28;
    uint8_t local_24[36];
    uint8_t* s = (uint8_t*)self;

    if (*(int*)(s + 0x60) != 0) {
        if ((*(char*)(s + 0x98) != '\0') && (param_1 != '\0')) {
            iVar1 = *(int*)(s + 0xac);
            local_30 = *(uint32_t*)(at(iVar1) + 0x5c);
            local_2c = *(uint32_t*)(at(iVar1) + 0x60);
            local_28 = *(uint32_t*)(at(iVar1) + 100);
            FUN_0053c9e0(local_24, *(float*)(at(iVar1) + 0x68));
            FUN_00573d80(local_24, &local_30);
        }
        if (*(float*)(*(int*)(*(int*)(s + 0x30) + *(int*)(s + 0x9c) * 4) + 0x24) !=
            -3.4028235e+38f) {
            iVar1 = *(int*)(*(int*)(s + 0x30) + *(int*)(s + 0x9c) * 4);
            *(float*)(s + 100) =
                (*(float*)(at(iVar1) + 0x28) / *(float*)(at(iVar1) + 0x10) -
                 *(float*)(at(iVar1) + 0x24)) +
                *(float*)(s + 100);
        }
        *(uint32_t*)(s + 0x60) = 0;
        FUN_0056e790(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x56e8c0
// ---------------------------------------------------------------------------
// 0x56e8c0 — observed shape
uint32_t FUN_0056e8c0(void* self, uint32_t param_1)
{
    int iVar1;
    // The listing tests in_EAX before assigning it on short-circuit paths; the
    // register value is undefined there, modelled here as 0.
    uint32_t in_EAX = 0;
    uint8_t* s = (uint8_t*)self;

    if ((((*(int*)(s + 0x60) == 3) && (param_1 != 0)) &&
         (in_EAX = *(uint32_t*)(s + 0x90), in_EAX == param_1)) &&
        (*(int*)(at(in_EAX) + 0x60) == 4)) {
        FUN_0056e810(self, 0);
        FUN_0056e810(self, 1);
        iVar1 = *(int*)(s + 0x90);
        *(uint32_t*)(s + 0x68) = 0xff7fffff;
        *(uint32_t*)(s + 0x6c) = 0xff7fffff;
        *(uint32_t*)(at(iVar1) + 0x90) = 0;
        *(uint32_t*)(s + 0x90) = 0;
        // CONCAT31((int3)((uint)iVar1 >> 8), 1)
        return ((uint32_t)iVar1 & 0xffffff00u) | 1;
    }
    return in_EAX & 0xffffff00u;
}

// ---------------------------------------------------------------------------
// 0x56e940
// ---------------------------------------------------------------------------
// 0x56e940 — observed shape
void FUN_0056e940(void* self, int* param_1)
{
    char cVar1;
    int* piVar2;
    int* piVar3;
    uint8_t bVar4;
    char* pcVar5;
    uint32_t* puVar6;
    int iVar7;
    uint32_t uVar8;
    int iVar9;
    uint32_t uVar10;
    uint32_t* local_10c;
    char* local_108;
    char acStack_104[260];
    uint8_t* s = (uint8_t*)self;

    local_108 = (char*)param_1[3];
    uVar8 = 0;
    if (*(int*)(s + 0x50) != 0) {
        do {
            piVar2 = *(int**)(*(int*)(s + 0x48) + uVar8 * 4);
            if ((piVar2 != (int*)0x0) && (param_1 == piVar2)) {
                pcVar5 = local_108;
                do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                local_10c = (uint32_t*)thunk_FUN_00533c78((int)(pcVar5 - local_108));
                pcVar5 = local_108;
                do {
                    cVar1 = *pcVar5;
                    ((char*)local_10c)[(int)(pcVar5 - local_108)] = cVar1;
                    pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                FUN_005606f0(uVar8, (void**)&local_10c);
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint32_t*)(s + 0x50));
    }
    puVar6 = (uint32_t*)param_1[0x29];
    if (puVar6 != (uint32_t*)0x0) {
        do {
            piVar2 = (int*)puVar6[2];
            local_10c = (uint32_t*)*puVar6;
            if ((piVar2 != (int*)0x0) && (uVar8 = 0, *(int*)(s + 0x50) != 0)) {
                do {
                    piVar3 = *(int**)(*(int*)(s + 0x48) + uVar8 * 4);
                    if ((piVar3 != (int*)0x0) && (piVar2 == piVar3)) {
                        puVar6 = (uint32_t*)(*(uint32_t (**)(void))(*(int*)piVar2 + 4))();
                        sprintf(acStack_104, "%s\nPROP\n%s", local_108, at(*puVar6));
                        pcVar5 = acStack_104;
                        do {
                            cVar1 = *pcVar5;
                            pcVar5 = pcVar5 + 1;
                        } while (cVar1 != '\0');
                        iVar7 = (int)(intptr_t)thunk_FUN_00533c78((int)(pcVar5 - acStack_104));
                        pcVar5 = acStack_104;
                        iVar9 = iVar7 - (int)(intptr_t)pcVar5;
                        do {
                            cVar1 = *pcVar5;
                            pcVar5[iVar9] = cVar1;
                            pcVar5 = pcVar5 + 1;
                        } while (cVar1 != '\0');
                        if (uVar8 < *(uint32_t*)(s + 0x1c)) {
                            if (uVar8 < *(uint32_t*)(s + 0x20)) {
                                if (iVar7 == 0) {
                                    if (*(int*)(*(int*)(s + 0x18) + uVar8 * 4) != 0) {
                                        iVar9 = *(int*)(s + 0x24) + -1;
                                        goto LAB_0056ea94;
                                    }
                                } else if (*(int*)(*(int*)(s + 0x18) + uVar8 * 4) == 0) {
                                    iVar9 = *(int*)(s + 0x24) + 1;
LAB_0056ea94:
                                    *(int*)(s + 0x24) = iVar9;
                                }
                            } else {
                                *(uint32_t*)(s + 0x20) = uVar8 + 1;
                                if (iVar7 != 0) {
                                    iVar9 = *(int*)(s + 0x24) + 1;
                                    goto LAB_0056ea94;
                                }
                            }
                            *(int*)(*(int*)(s + 0x18) + uVar8 * 4) = iVar7;
                        }
                    }
                    uVar8 = uVar8 + 1;
                } while (uVar8 < *(uint32_t*)(s + 0x50));
            }
            if (local_10c == (uint32_t*)0x0) break;
            puVar6 = local_10c;
        } while (true);
    }
    puVar6 = (uint32_t*)(*(uint32_t (**)(void))(*(int*)param_1 + 4))();
    do {
        if (puVar6 == (uint32_t*)0x0) {
            bVar4 = 0;
LAB_0056ead8:
            uVar8 = (-(uint32_t)bVar4) & (uint32_t)(intptr_t)param_1;
            if (uVar8 != 0) {
                uVar10 = 0;
                if (*(int*)(at(uVar8) + 0xc0) != 0) {
                    if (*(int*)(at(uVar8) + 0xc0) == 0) goto LAB_0056eb07;
                    do {
                        iVar7 = *(int*)(*(int*)(at(uVar8) + 0xb8) + uVar10 * 4);
                        if (iVar7 != 0) {
                            FUN_0056e940(self, (int*)iVar7);
                        }
LAB_0056eb07:
                        uVar10 = uVar10 + 1;
                    } while (uVar10 < *(uint32_t*)(at(uVar8) + 0xc0));
                }
            }
            return;
        }
        if (puVar6 == &DAT_00727560) {
            bVar4 = 1;
            goto LAB_0056ead8;
        }
        puVar6 = (uint32_t*)puVar6[1];
    } while (true);
}

// ---------------------------------------------------------------------------
// 0x56eb30
// ---------------------------------------------------------------------------
// 0x56eb30 — observed shape
void FUN_0056eb30(void* self)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    int iVar5;
    int iVar6;
    uint32_t* puVar7;
    uint32_t uVar8;
    float* pfVar9;
    int iVar10;
    uint32_t uVar11;
    uint32_t* puVar12;
    int* piVar13;
    float fStack_98;
    float fStack_94;
    float fStack_90;
    int* local_8c;
    uint8_t auStack_88[16];
    uint8_t auStack_78[16];
    uint8_t auStack_68[16];
    uint8_t auStack_58[16];
    uint8_t auStack_48[36];
    uint8_t auStack_24[36];
    uint8_t* s = (uint8_t*)self;

    uVar11 = 0;
    if (*(int*)(s + 0x50) != 0) {
        do {
            piVar13 = *(int**)(*(int*)(s + 0x30) + uVar11 * 4);
            if ((*(int*)(*(int*)(s + 0x48) + uVar11 * 4) == *(int*)(s + 0xac)) &&
                (piVar13 != (int*)0x0)) {
                local_8c = piVar13;
                for (puVar7 = (uint32_t*)(*(uint32_t (**)(void))(*(int*)piVar13 + 4))();
                     puVar7 != (uint32_t*)0x0; puVar7 = (uint32_t*)puVar7[1]) {
                    if (puVar7 == &DAT_00728a3c) {
                        iVar10 = piVar13[0x14];
                        if (iVar10 == 0) {
LAB_0056ebe7:
                            fStack_90 = 1.0f;
                        } else {
                            iVar5 = *(int*)(at(iVar10) + 0x28);
                            if (*(int*)(at(iVar10) + 0x24) == 0) goto LAB_0056ebe7;
                            fStack_90 = *(float*)(at(iVar5) + 8 +
                                                  (uint32_t)*(uint8_t*)(at(iVar5) + 4) *
                                                      (*(int*)(at(iVar10) + 0x24) - 1)) /
                                        *(float*)(at(iVar5) + 8);
                        }
                        if (iVar10 == 0) goto LAB_0056edad;
                        iVar5 = *(int*)(at(iVar10) + 0x10);
                        iVar6 = *(int*)(at(iVar10) + 0xc);
                        if (*(int*)(at(iVar10) + 0x14) == 4) {
                            fStack_98 = 3.4028235e+38f;
                            fStack_94 = -3.4028235e+38f;
                            if (*(int*)(at(iVar5) + 0x18) != 0) {
                                pfVar9 = *(float**)(at(iVar5) + 0x34);
                                if (*pfVar9 < 3.4028235e+38f) {
                                    fStack_98 = *pfVar9;
                                }
                                fVar1 = *(float*)((char*)pfVar9 +
                                                  (uint32_t)*(uint8_t*)((char*)pfVar9 + 4) *
                                                      (*(int*)(at(iVar5) + 0x18) - 1));
                                if (-3.4028235e+38f < fVar1) {
                                    fStack_94 = fVar1;
                                }
                            }
                            if (*(int*)(at(iVar5) + 0x1c) != 0) {
                                pfVar9 = *(float**)(at(iVar5) + 0x38);
                                if (*pfVar9 < fStack_98) {
                                    fStack_98 = *pfVar9;
                                }
                                fVar1 = *(float*)((char*)pfVar9 +
                                                  (uint32_t)*(uint8_t*)((char*)pfVar9 + 4) *
                                                      (*(int*)(at(iVar5) + 0x1c) - 1));
                                if (fStack_94 < fVar1) {
                                    fStack_94 = fVar1;
                                }
                            }
                            if (*(int*)(at(iVar5) + 0x20) != 0) {
                                pfVar9 = *(float**)(at(iVar5) + 0x3c);
                                if (*pfVar9 < fStack_98) {
                                    fStack_98 = *pfVar9;
                                }
                                fVar1 = *(float*)((char*)pfVar9 +
                                                  (uint32_t)*(uint8_t*)((char*)pfVar9 + 4) *
                                                      (*(int*)(at(iVar5) + 0x20) - 1));
                                if (fStack_94 < fVar1) {
                                    fStack_94 = fVar1;
                                }
                            }
                            FUN_0056a050(auStack_68, fStack_98, iVar5, 4, iVar6, &fStack_98);
                            FUN_0056a050(auStack_88, fStack_94, iVar5, 4, iVar6, &fStack_98);
                            uVar8 = FUN_00555c50(auStack_58, auStack_68);
                            FUN_00555bc0(auStack_78, uVar8);
                            FUN_00520da0(auStack_48);
                        } else {
                            if (iVar6 == 0) goto LAB_0056edad;
                            uVar8 = FUN_00555c50(auStack_58, at(iVar5 + 8));
                            FUN_00555bc0(auStack_78, uVar8);
                            FUN_00520da0(auStack_48);
                        }
                        puVar7 = (uint32_t*)FUN_0053c9e0(auStack_24, fStack_90);
                        puVar12 = (uint32_t*)(s + 0xb0);
                        for (iVar10 = 9; (piVar13 = local_8c), iVar10 != 0; iVar10 = iVar10 + -1) {
                            *puVar12 = *puVar7;
                            puVar7 = puVar7 + 1;
                            puVar12 = puVar12 + 1;
                        }
LAB_0056edad:
                        iVar10 = piVar13[0x14];
                        if (iVar10 != 0) {
                            iVar5 = *(int*)(at(iVar10) + 0x1c);
                            if (*(int*)(at(iVar10) + 0x18) != 0) {
                                iVar10 = (uint32_t)*(uint8_t*)(at(iVar5) + 4) *
                                             (*(int*)(at(iVar10) + 0x18) - 1) +
                                         iVar5;
                                pfVar9 = (float*)FUN_0053ca60(auStack_68, at(iVar5 + 8));
                                fVar1 = *(float*)(at(iVar10) + 0xc);
                                fVar2 = pfVar9[1];
                                fVar3 = *(float*)(at(iVar10) + 0x10);
                                fVar4 = pfVar9[2];
                                *(float*)(s + 0xd4) = *(float*)(at(iVar10) + 8) - *pfVar9;
                                *(float*)(s + 0xd8) = fVar1 - fVar2;
                                *(float*)(s + 0xdc) = fVar3 - fVar4;
                            }
                        }
                        return;
                    }
                }
            }
            uVar11 = uVar11 + 1;
        } while (uVar11 < *(uint32_t*)(s + 0x50));
    }
    puVar7 = DAT_007179b0;
    puVar12 = (uint32_t*)(s + 0xb0);
    for (iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar12 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar12 = puVar12 + 1;
    }
    *(uint32_t*)(s + 0xd4) = DAT_00727430;
    *(uint32_t*)(s + 0xd8) = DAT_00727434;
    *(uint32_t*)(s + 0xdc) = DAT_00727438;
    return;
}

// ---------------------------------------------------------------------------
// 0x56ee20
// ---------------------------------------------------------------------------
// 0x56ee20 — observed shape
void FUN_0056ee20(void* self, int param_1)
{
    int* piVar1;
    int* piVar2;
    int iVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    int* piVar6;
    uint32_t uVar7;
    uint8_t* s = (uint8_t*)self;

    uVar7 = 0;
    if (*(int*)(s + 0x38) != 0) {
        do {
            piVar2 = *(int**)(*(int*)(s + 0x30) + uVar7 * 4);
            iVar3 = *(int*)(*(int*)(s + 0x48) + uVar7 * 4);
            if ((piVar2 != (int*)0x0) && (iVar3 != 0)) {
                (*(void (**)(int))(*(int*)piVar2 + 0x40))(iVar3);
                (*(void (**)(void))(*(int*)piVar2 + 0x38))();
                piVar2[0xf] = param_1;
                if (piVar2[0xd] == *(int*)(at(*(int*)(s + 0x5c)) + 0x34)) {
                    FUN_00540e40(piVar2);
                    puVar4 = *(uint32_t**)(at(*(int*)(s + 0x5c)) + 0x38);
                    puVar5 = (uint32_t*)piVar2[0xe];
                    if (puVar5 != puVar4) {
                        if (puVar5 != (uint32_t*)0x0) {
                            piVar6 = (int*)(puVar5 + 1);
                            *piVar6 = *piVar6 + -1;
                            if (*piVar6 == 0) {
                                (*(void (**)(int))(*(uint32_t*)puVar5))(1);
                            }
                        }
                        piVar2[0xe] = (int)(intptr_t)puVar4;
                        if (puVar4 != (uint32_t*)0x0) {
                            puVar4[1] = puVar4[1] + 1;
                        }
                    }
                    iVar3 = *(int*)(s + 0x5c);
                    piVar6 = *(int**)(at(iVar3) + 0x38);
                    if (piVar6 != piVar2) {
                        if (piVar6 != (int*)0x0) {
                            piVar1 = piVar6 + 1;
                            *piVar1 = *piVar1 + -1;
                            if (*piVar1 == 0) {
                                (*(void (**)(int))(*(int*)piVar6))(1);
                            }
                        }
                        *(int**)(at(iVar3) + 0x38) = piVar2;
                        piVar2[1] = piVar2[1] + 1;
                    }
                }
            }
            uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint32_t*)(s + 0x38));
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x56eed0
// ---------------------------------------------------------------------------
// 0x56eed0 — observed shape
void FUN_0056eed0(void* self, uint32_t param_1)
{
    float fVar1;
    float* pfVar3;
    int iVar4;
    uint32_t* puVar5;
    uint32_t* puVar6;
    long double fVar7;
    uint8_t* puVar8;
    float fVar9;
    uint8_t auStack_b6[10];
    float fStack_ac;
    float fStack_a8;
    float fStack_a4;
    uint8_t auStack_a0[12];
    uint8_t auStack_94[36];
    uint8_t auStack_70[36];
    uint32_t auStack_4c[9];
    uint8_t auStack_28[40];
    uint8_t* s = (uint8_t*)self;

    {
        int* obj = *(int**)(*(int*)(s + 0x30) + *(int*)(s + 0x9c) * 4);
        float (*fn)(void*, uint32_t) = *(float (**)(void*, uint32_t))(*(int*)obj + 0x4c);
        fVar7 = (long double)fn(obj, param_1);
    }
    if (*(char*)(s + 0xa0) == '\0') {
        if ((float)fVar7 < *(float*)(s + 0xa4)) {
            FUN_00574040(s + 0xb0, s + 0xd4);
        }
    } else {
        puVar8 = auStack_70;
        fVar9 = 1.0f / *(float*)(at(*(int*)(s + 0xac)) + 0x68);
        FUN_0053cc20(auStack_28);
        FUN_0053c9e0(puVar8, fVar9);
        {
            void* uVar2 = FUN_0053ca60(auStack_a0, auStack_b6 - 6);
            FUN_00574040(auStack_70, uVar2);
        }
        *(uint8_t*)(s + 0xa0) = 0;
    }
    *(float*)(s + 0xa4) = (float)fVar7;
    FUN_00573bd0(auStack_94, &fStack_ac);
    FUN_0053c8d0(auStack_4c, at(*(int*)(s + 0xac) + 0x38));
    pfVar3 = (float*)FUN_0053ca60(auStack_a0, at(*(int*)(s + 0xac) + 0x5c));
    fVar9 = pfVar3[1];
    fVar1 = pfVar3[2];
    iVar4 = *(int*)(s + 0xac);
    *(float*)(at(iVar4 + 0x5c)) = fStack_ac + *pfVar3;
    *(float*)(at(iVar4 + 0x60)) = fStack_a8 + fVar9;
    *(float*)(at(iVar4 + 100)) = fStack_a4 + fVar1;
    puVar5 = auStack_4c;
    puVar6 = (uint32_t*)(at(*(int*)(s + 0xac) + 0x38));
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x56f060
// ---------------------------------------------------------------------------
// 0x56f060 — observed shape
void FUN_0056f060(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    int* piVar1;
    int* piVar2;
    int iVar3;
    uint32_t local_4;
    uint8_t* s = (uint8_t*)self;

    local_4 = 0;
    if (*(int*)(s + 0x38) != 0) {
        do {
            piVar1 = *(int**)(*(int*)(s + 0x30) + local_4 * 4);
            piVar2 = *(int**)(*(int*)(at(*(int*)(s + 0x90)) + 0x30) + local_4 * 4);
            if ((((((piVar1 != (int*)0x0) && (piVar2 != (int*)0x0)) &&
                   ((*(uint8_t*)(piVar1 + 3) >> 5 & 1) != 0)) &&
                  ((iVar3 = FUN_00449390(&DAT_007273fc, piVar1[0xd]), iVar3 == 0) ||
                   ((*(uint8_t*)(at(iVar3) + 0x20) >> 1 & 1) != 0))) &&
                 (((*(uint8_t*)(piVar2 + 3) >> 5 & 1) != 0) &&
                  ((iVar3 = FUN_00449390(&DAT_007273fc, piVar2[0xd]), iVar3 == 0) ||
                   ((*(uint8_t*)(at(iVar3) + 0x20) >> 1 & 1) != 0)))) &&
                ((iVar3 = FUN_00552ec0(piVar1[0xd]), piVar1[0xf] == iVar3) &&
                 (piVar2[0xf] == iVar3))) {
                if ((*(char*)(s + 0x98) != '\0') && (local_4 == *(uint32_t*)(s + 0x9c))) {
                    FUN_00573d80(s + 0xe0, s + 0x104);
                }
                *(uint8_t*)(piVar1 + 3) = *(uint8_t*)(piVar1 + 3) | 8;
                *(uint8_t*)(piVar1 + 0x10) = 1;
                (*(void (**)(uint32_t))(*(int*)piVar1 + 0x3c))(param_1);
                *(uint8_t*)(piVar1 + 3) = *(uint8_t*)(piVar1 + 3) & 0xf7;
                *(uint8_t*)(piVar2 + 3) = *(uint8_t*)(piVar2 + 3) | 8;
                if ((*(char*)(s + 0x98) == '\0') || (local_4 != *(uint32_t*)(s + 0x9c))) {
                    (*(void (**)(uint32_t, uint32_t, int))(*(int*)piVar2 + 0x60))(param_2, param_3,
                                                                                  1);
                } else {
                    FUN_0056eed0(self, param_1);
                    FUN_00573bd0(s + 0xe0, s + 0x104);
                    FUN_00573d80(at(*(int*)(s + 0x90) + 0xe0),
                                 at(*(int*)(s + 0x90) + 0x104));
                    FUN_005802d0(param_2, param_3, 1, *(uint32_t*)(s + 0x90));
                    FUN_00573bd0(at(*(int*)(s + 0x90) + 0xe0),
                                 at(*(int*)(s + 0x90) + 0x104));
                }
                *(uint8_t*)(piVar2 + 3) = *(uint8_t*)(piVar2 + 3) & 0xf7;
            }
            local_4 = local_4 + 1;
        } while (local_4 < *(uint32_t*)(s + 0x38));
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x56f230
// ---------------------------------------------------------------------------
// 0x56f230 — observed shape
long double FUN_0056f230(float* param_1, uint32_t param_2)
{
    uint8_t bVar1;
    int* piVar2;
    uint32_t uVar3;
    int iVar4;
    uint8_t* pbVar5;
    float* pfVar6;
    float* pfVar7;
    float* pfVar8;
    uint8_t* pbVar9;
    bool bVar10;
    bool bVar11;
    bool bVar12;
    long double fVar13 = 0.0;
    long double fVar14 = 0.0;
    long double fVar15 = 0.0;
    long double fVar16;
    float fVar17;
    float* pfVar18;
    uint32_t uStack_14;
    float* pfStack_10;
    float* pfStack_c;
    // iStack_8 in the listing keeps the original argument after the working
    // pointer is nulled; modelled as obj.
    float* obj = param_1;
    float* wPtr;

    piVar2 = *(int**)(*(int*)((char*)obj + 0x30) + *(int*)((char*)obj + 0x9c) * 4);
    {
        float (*fn)(void*, uint32_t) = *(float (**)(void*, uint32_t))(*(int*)piVar2 + 0x4c);
        fVar13 = (long double)fn(piVar2, param_2);
    }
    fVar17 = (float)fVar13;
    uStack_14 = *(uint32_t*)(*(int*)((char*)obj + 0x10) + 0x10);
    pfVar8 = *(float**)(*(int*)((char*)obj + 0x10) + 0x14);
    pfVar6 = (float*)0x0;
    pfVar7 = (float*)0x0;
    wPtr = (float*)0x0;
    pfVar18 = (float*)0x0;
    if (uStack_14 != 0) {
        do {
            if ((char*)pfVar8[1] != (char*)0x0) {
                iVar4 = strncmp((char*)pfVar8[1], "morph:", 6);
                if (iVar4 == 0) {
                    if (pfVar6 == (float*)0x0) {
                        pfVar6 = pfVar8;
                    }
                    pfVar7 = pfVar8;
                    if (fVar17 <= *pfVar8) {
                        if (pfVar18 == (float*)0x0) {
                            pfVar18 = pfVar8;
                        }
                    } else {
                        wPtr = pfVar8;
                    }
                }
            }
            pfVar8 = pfVar8 + 2;
            uStack_14 = uStack_14 + -1;
        } while (uStack_14 != 0);
        if (pfVar18 != (float*)0x0) {
            if (wPtr == (float*)0x0) {
                fVar13 = ((long double)*(float*)(piVar2 + 6) -
                          (long double)*(float*)(piVar2 + 7)) +
                         (long double)*pfVar7;
                wPtr = pfVar7;
            } else {
                fVar13 = (long double)*wPtr;
            }
            fVar14 = (long double)fVar17 - fVar13;
            fVar15 = (long double)*pfVar18;
            pfVar6 = pfVar18;
            goto LAB_0056f30c;
        }
    }
    fVar13 = (long double)*wPtr;
    fVar14 = (long double)fVar17 - fVar13;
    fVar15 = ((long double)*(float*)(piVar2 + 7) - (long double)*(float*)(piVar2 + 6)) +
             (long double)*pfVar6;
LAB_0056f30c:
    uVar3 = *(uint32_t*)(*(int*)((char*)obj + 0x10) + 0x10);
    pfVar8 = *(float**)(*(int*)((char*)obj + 0x10) + 0x14);
    bVar11 = wPtr == (float*)0x0;
    bVar12 = pfVar6 == (float*)0x0;
    pfStack_c = (float*)0x0;
    pfStack_10 = (float*)0x0;
    uStack_14 = 0;
    if (uVar3 != 0) {
        do {
            if (bVar11) {
                if (bVar12) break;
LAB_0056f3aa:
                pbVar9 = (uint8_t*)pfVar6[1];
                pbVar5 = (uint8_t*)pfVar8[1];
                do {
                    bVar1 = *pbVar5;
                    bVar10 = bVar1 < *pbVar9;
                    if (bVar1 != *pbVar9) {
LAB_0056f3d8:
                        iVar4 = (1 - (uint32_t)bVar10) - (uint32_t)(bVar10 != 0);
                        goto LAB_0056f3dd;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar5[1];
                    bVar10 = bVar1 < pbVar9[1];
                    if (bVar1 != pbVar9[1]) goto LAB_0056f3d8;
                    pbVar5 = pbVar5 + 2;
                    pbVar9 = pbVar9 + 2;
                } while (bVar1 != 0);
                iVar4 = 0;
LAB_0056f3dd:
                if (iVar4 == 0) {
                    bVar12 = true;
                    pfStack_10 = pfVar8;
                }
            } else {
                pbVar9 = (uint8_t*)wPtr[1];
                pbVar5 = (uint8_t*)pfVar8[1];
                do {
                    bVar1 = *pbVar5;
                    bVar10 = bVar1 < *pbVar9;
                    if (bVar1 != *pbVar9) {
LAB_0056f394:
                        iVar4 = (1 - (uint32_t)bVar10) - (uint32_t)(bVar10 != 0);
                        goto LAB_0056f399;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar5[1];
                    bVar10 = bVar1 < pbVar9[1];
                    if (bVar1 != pbVar9[1]) goto LAB_0056f394;
                    pbVar5 = pbVar5 + 2;
                    pbVar9 = pbVar9 + 2;
                } while (bVar1 != 0);
                iVar4 = 0;
LAB_0056f399:
                if (iVar4 == 0) {
                    bVar11 = true;
                    pfStack_c = pfVar8;
                }
                if (!bVar12) goto LAB_0056f3aa;
            }
            uStack_14 = uStack_14 + 1;
            pfVar8 = pfVar8 + 2;
        } while (uStack_14 < uVar3);
    }
    fVar16 = (long double)0.0;
    fVar17 = 0.0f;
    if (pfStack_10 != (float*)0x0) {
        fVar16 = (long double)*pfStack_10;
    }
    if (pfStack_c != (float*)0x0) {
        fVar17 = *pfStack_c;
    }
    if (fVar16 < (long double)fVar17) {
        iVar4 = *(int*)(*(int*)((char*)obj + 0x30) + *(int*)((char*)obj + 0x9c) * 4);
        fVar16 = ((long double)*(float*)(at(iVar4 + 0x1c)) -
                  (long double)*(float*)(at(iVar4 + 0x18))) +
                 fVar16;
    }
    return (fVar16 - (long double)fVar17) * (fVar14 / (fVar15 - fVar13)) +
           (long double)fVar17;
}
