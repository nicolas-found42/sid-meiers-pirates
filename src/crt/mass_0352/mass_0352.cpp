// Reconstruction batch mass_0352
// Sid Meier's Pirates! (2004), PE32 i386.
// Candidate C++ translation of the Ghidra 12.2 listings for the assigned
// addresses only.  Register receivers are explicit `self` parameters.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// FUN_006b921c stores the active SEH chain; winnt.h only names this field for
// some toolchains, so provide the same access expression when it is missing.
#ifndef ExceptionList
#define ExceptionList (NtCurrentTeb()->ExceptionList)
#endif

// ---------------------------------------------------------------------------
// Listing helpers
// ---------------------------------------------------------------------------

// The listings index the matrix/vector globals as `&DAT_xxxxxxxx + offset`
// with byte offsets (Ghidra exposes those bases as byte addresses), so the
// globals below are declared as byte arrays and accessed through these views.
static inline float& f_at(uint8_t* base, int32_t off)
{
    return *reinterpret_cast<float*>(base + off);
}

static inline uint32_t& u_at(uint8_t* base, int32_t off)
{
    return *reinterpret_cast<uint32_t*>(base + off);
}

// `(**(code **)(*self + 0x28))(a, b, 0)` -- virtual call through vtable slot 0x28.
typedef uint32_t (*Pfn_slot28)(void* self, void* a, void* b, uint32_t c);

static uint32_t CallSlot28(void* self, void* a, void* b, uint32_t c)
{
    uint8_t* vtable = (uint8_t*)(uintptr_t)*(uint32_t*)self;
    return ((Pfn_slot28)(uintptr_t)*(uint32_t*)(vtable + 0x28))(self, a, b, c);
}

// `(**(code **)(*self + 0x24))(id)` -- virtual element lookup, returns int*.
typedef int* (*Pfn_slot24)(void* self, uint32_t id);

static int* CallSlot24(void* self, uint32_t id)
{
    uint8_t* vtable = (uint8_t*)(uintptr_t)*(uint32_t*)self;
    return ((Pfn_slot24)(uintptr_t)*(uint32_t*)(vtable + 0x24))(self, id);
}

// ---------------------------------------------------------------------------
// Referenced helpers and globals
// ---------------------------------------------------------------------------
extern "C" int _stricmp(const char* string1, const char* string2);

extern void operator_delete(void* param_1);
extern void operator_delete__(void* param_1);

extern char FUN_006b5200(uint32_t param_1, char* param_2, uint32_t param_3,
                         uint32_t param_4);
extern uint8_t FUN_006b75b0(uint32_t param_1, uint32_t* param_2, uint32_t param_3);
extern uint32_t FUN_006b7630(char* param_1);
extern uint32_t FUN_006b7670(uint32_t param_1);

extern void FUN_005df1a0(uint32_t param_1);
extern void FUN_0056f540(void);
extern int FUN_005dfaf0(uint32_t param_1);
extern void FUN_005dffd0(void);
extern int FUN_00540540(void* param_1);
extern void FUN_005477c0(uint32_t param_1, uint32_t param_2, const char* param_3);
extern void FUN_0054a7e0(void);
extern void FUN_004f0dc0(void);
extern void FUN_005e0120(void);

extern char FUN_005de180(void);
extern char FUN_005de1b0(void);
extern char FUN_005de940(void);
extern char FUN_005de970(void);
extern char FUN_005de9a0(void);
extern char FUN_005de9d0(void);
extern char FUN_005dea00(void);

extern int* FUN_005df860(int param_1, int param_2);

extern void thunk_FUN_005f1ec2(float* param_1, float* param_2, float* param_3);
extern void thunk_FUN_005f2148(float* param_1, float* param_2, float* param_3);
extern void thunk_FUN_005f2399(float* param_1, float* param_2);
extern void thunk_FUN_005f266e(float* param_1, uint32_t param_2, float* param_3);

extern uint8_t PTR_LAB_006fd148;
extern uint8_t PTR_FUN_006c93b0;
extern uint8_t PTR_FUN_006c93ac;
extern uint8_t PTR_FUN_006f5418;
extern uint8_t PTR_FUN_006f57c8;
extern uint8_t PTR_FUN_006f5864;

extern uint32_t DAT_00727444;
extern uint8_t DAT_00722688[];
extern uint8_t DAT_007187a8;
extern uint8_t DAT_007187b8;
extern char PTR_s_NDL_UpdateTime_007187c8[];

extern uint8_t DAT_00729098;
extern int DAT_00729060[256];
extern uint8_t DAT_00728f60[];
extern uint8_t DAT_00728fa0[];
extern uint8_t DAT_00728fe0[];
extern uint8_t DAT_00728ff0[];
extern uint8_t DAT_00729000[];
extern uint8_t DAT_00729040[];

extern float DAT_007278e0;
extern float DAT_007278e4;
extern float DAT_007278ec;
extern float DAT_007278f0;
extern float DAT_007278f4;
extern float DAT_007278f8;

extern uint8_t* PTR_PTR_00726610;
extern uint8_t* PTR_DAT_0072662c;
extern uint8_t DAT_008cacc8;
extern uint8_t DAT_008cacd0;

// ---------------------------------------------------------------------------
// 0x6b7510
// ---------------------------------------------------------------------------
// 0x6b7510 — observed shape
void FUN_006b7510(void* self, uint32_t param_1)
{
    uint32_t* p = (uint32_t*)self;

    p[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    p[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    p[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c93b0;
    p[2] = 2;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[4] = 0;
    p[3] = (uint32_t)(uintptr_t)&PTR_FUN_006c93ac;
    p[8] = 1;
    p[10] = 0;
    p[0xb] = 0;
    p[0xc] = 0;
    p[0xd] = 0;
    p[0xe] = 0;
    *(uint8_t*)(p + 9) = 1;
    FUN_005df1a0(param_1);
    FUN_0056f540();
    return;
}

// ---------------------------------------------------------------------------
// 0x6b7590
// ---------------------------------------------------------------------------
// 0x6b7590 — observed shape
void FUN_006b7590(void* self, uint32_t param_1)
{
    FUN_006b7510(self, param_1);
    *(uint32_t*)self = (uint32_t)(uintptr_t)&PTR_FUN_006f5418;
    return;
}

// ---------------------------------------------------------------------------
// 0x6b75b0
// ---------------------------------------------------------------------------
// 0x6b75b0 — observed shape
uint8_t FUN_006b75b0(uint32_t param_1, uint32_t* param_2, uint32_t param_3)
{
    char local_104[260];
    uint8_t* puVar4;
    uint32_t uVar3;
    int iVar2;
    char cVar1;

    cVar1 = FUN_006b5200(param_1, local_104, 0x104, param_3);
    if (cVar1 == '\0') {
        return 0;
    }
    puVar4 = DAT_00722688;
    uVar3 = 0;
    do {
        iVar2 = _stricmp(local_104, *(char**)(puVar4 + 4));
        if (iVar2 == 0) {
            *param_2 = *(uint32_t*)puVar4;
            return 1;
        }
        uVar3 = uVar3 + 8;
        puVar4 = puVar4 + 8;
    } while (uVar3 < 0x68);
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b7630
// ---------------------------------------------------------------------------
// 0x6b7630 — observed shape
uint32_t FUN_006b7630(char* param_1)
{
    uint8_t* puVar2;
    uint32_t uVar3;
    int iVar1;

    puVar2 = DAT_00722688;
    uVar3 = 0;
    do {
        iVar1 = _stricmp(param_1, *(char**)(puVar2 + 4));
        if (iVar1 == 0) {
            return *(uint32_t*)puVar2;
        }
        uVar3 = uVar3 + 8;
        puVar2 = puVar2 + 8;
    } while (uVar3 < 0x68);
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b7670
// ---------------------------------------------------------------------------
// 0x6b7670 — observed shape
uint32_t FUN_006b7670(uint32_t param_1)
{
    int32_t local_8 = 0;
    uint8_t local_4[4];
    char cVar1;

    cVar1 = (char)FUN_006b75b0(param_1, (uint32_t*)&local_8,
                               (uint32_t)(uintptr_t)local_4);
    if (cVar1 != '\0') {
        switch (local_8) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
            return 7;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b76d0
// ---------------------------------------------------------------------------
// 0x6b76d0 — observed shape
uint32_t FUN_006b76d0(int* param_1, uint32_t param_2)
{
    int32_t iVar1;

    iVar1 = FUN_005dfaf0(param_2);
    if (iVar1 == 0) {
        return 1;
    }
    CallSlot28(param_1, (void*)(uintptr_t)param_2, (void*)(uintptr_t)iVar1, 0);
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b7700
// ---------------------------------------------------------------------------
// 0x6b7700 — observed shape
void FUN_006b7700(void* self, uint8_t param_1)
{
    *(uint32_t*)self = (uint32_t)(uintptr_t)&PTR_FUN_006f57c8;
    FUN_005dffd0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6b7730
// ---------------------------------------------------------------------------
// 0x6b7730 — observed shape
uint32_t FUN_006b7730(int param_1)
{
    int32_t iVar1;

    iVar1 = (int32_t)FUN_006b7630(*(char**)(param_1 + 8));
    if (iVar1 == 0) {
        return 0x80000040;
    }
    *(int32_t*)(param_1 + 0xc) = iVar1;
    if (iVar1 == 1) {
        *(uint32_t*)(param_1 + 0x24) = 0x10;
        *(uint32_t*)(param_1 + 0x28) = 0x10;
        *(uint8_t*)(param_1 + 0x30) = 0;
        *(uint32_t*)(param_1 + 0x2c) = (uint32_t)(uintptr_t)&DAT_007187a8;
        return 0;
    }
    if (iVar1 == 2) {
        *(uint32_t*)(param_1 + 0x24) = 0x10;
        *(uint32_t*)(param_1 + 0x28) = 0x10;
        *(uint8_t*)(param_1 + 0x30) = 0;
        *(uint32_t*)(param_1 + 0x2c) = (uint32_t)(uintptr_t)&DAT_007187b8;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b7790
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: local_8 (int*) and local_4 are the 15th/16th elements of the
// 16-float block that starts at local_40; the case-9 paths use those same
// stack slots as a virtual-call receiver and first argument.  The listing
// leaves them unwritten on those paths, so they are zero-initialized here to
// keep the candidate well formed and their observed uses are preserved.
// 0x6b7790 — observed shape
uint32_t FUN_006b7790(int* param_1, uint32_t param_2, int param_3, uint32_t param_4,
                      char param_5, char param_6)
{
    float local_40[4];
    float local_30;
    float local_2c;
    float local_28;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    int* local_8 = nullptr;
    float local_4 = 0.0f;
    int iVar1;
    float* pfVar2;
    float* pfVar3;

    if (param_3 != 7) {
        if (param_3 == 9) {
            switch (param_4) {
            case 3:
            case 4:
                local_40[0] = f_at(DAT_00728f60, 0x00) * f_at(DAT_00728ff0, 0x00);
                local_40[1] = f_at(DAT_00728f60, 0x04) * f_at(DAT_00728ff0, 0x00);
                local_40[2] = f_at(DAT_00728f60, 0x08) * f_at(DAT_00728ff0, 0x00);
                local_40[3] = f_at(DAT_00728f60, 0x0c) * f_at(DAT_00728ff0, 0x00);
                local_30 = f_at(DAT_00728f60, 0x10) * f_at(DAT_00728ff0, 0x00);
                local_2c = f_at(DAT_00728f60, 0x14) * f_at(DAT_00728ff0, 0x00);
                local_28 = f_at(DAT_00728f60, 0x18) * f_at(DAT_00728ff0, 0x00);
                local_24 = f_at(DAT_00728f60, 0x1c) * f_at(DAT_00728ff0, 0x00);
                local_20 = f_at(DAT_00728f60, 0x20) * f_at(DAT_00728ff0, 0x00);
                local_1c = f_at(DAT_00728f60, 0x24) * f_at(DAT_00728ff0, 0x00);
                local_18 = f_at(DAT_00728f60, 0x28) * f_at(DAT_00728ff0, 0x00);
                local_14 = f_at(DAT_00728f60, 0x2c) * f_at(DAT_00728ff0, 0x00);
                local_10 = f_at(DAT_00728f60, 0x30) * f_at(DAT_00728ff0, 0x00);
                local_c = f_at(DAT_00728f60, 0x34) * f_at(DAT_00728ff0, 0x00);
                local_8 = (int*)(uintptr_t)(f_at(DAT_00728f60, 0x38) *
                                            f_at(DAT_00728ff0, 0x00));
                local_4 = f_at(DAT_00728f60, 0x3c) * f_at(DAT_00728ff0, 0x00);
                pfVar2 = local_40;
                pfVar3 = (float*)DAT_00729000;
                for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
                    *pfVar3 = *pfVar2;
                    pfVar2 = pfVar2 + 1;
                    pfVar3 = pfVar3 + 1;
                }
                if (param_5 != '\0') {
                    thunk_FUN_005f266e((float*)DAT_00729000, 0,
                                       (float*)DAT_00729000);
                }
                if (param_6 != '\0') {
                    thunk_FUN_005f2399((float*)DAT_00729000,
                                       (float*)DAT_00729000);
                }
                CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729000, 0);
                return 0;
            default:
                return 1;
            case 7:
            case 10:
                thunk_FUN_005f1ec2((float*)DAT_00729040, (float*)DAT_00728ff0,
                                   (float*)DAT_00728f60);
                break;
            case 9:
                thunk_FUN_005f2148((float*)DAT_00729000, (float*)DAT_00728f60,
                                   (float*)DAT_00728fa0);
                if ((char)param_2 != '\0') {
                    thunk_FUN_005f266e((float*)DAT_00729000, 0,
                                       (float*)DAT_00729000);
                }
                thunk_FUN_005f2399((float*)DAT_00729000,
                                   (float*)DAT_00729000);
                CallSlot28(local_8, (void*)(uintptr_t)local_4, DAT_00729000, 0);
                return 0;
            }
            goto LAB_006b7a9a;
        }
        if (param_3 != 10) {
            return 1;
        }
    }
    switch (param_4) {
    case 3:
    case 4:
        f_at(DAT_00729040, 0x00) = f_at(DAT_00728fe0, 0x00) * f_at(DAT_00728ff0, 0x00);
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x04) * f_at(DAT_00728ff0, 0x00);
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x08) * f_at(DAT_00728ff0, 0x00);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x0c) * f_at(DAT_00728ff0, 0x00);
        CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729040, 0);
        return 0;
    default:
        return 1;
    case 7:
    case 10:
        f_at(DAT_00729040, 0x00) = f_at(DAT_00728fe0, 0x00) * f_at(DAT_00728ff0, 0x00);
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728ff0, 0x04) * f_at(DAT_00728fe0, 0x04);
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728ff0, 0x08) * f_at(DAT_00728fe0, 0x08);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728ff0, 0x0c) * f_at(DAT_00728fe0, 0x0c);
        break;
    case 9:
        thunk_FUN_005f1ec2((float*)DAT_00729040, (float*)DAT_00728fe0,
                           (float*)DAT_00728fa0);
        CallSlot28(local_8, (void*)(uintptr_t)local_4, DAT_00729040, 0);
        return 0;
    }
LAB_006b7a9a:
    CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729040, 0);
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b7b00
// ---------------------------------------------------------------------------
// 0x6b7b00 — observed shape
uint32_t FUN_006b7b00(int* param_1, uint32_t param_2, int param_3, int param_4,
                      char param_5, char param_6)
{
    float fVar1;
    int iVar2;
    float* pfVar3;
    float* pfVar4;
    float local_40[4];
    float local_30;
    float local_2c;
    float local_28;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;

    if (param_3 != 7) {
        if (param_3 == 9) {
            if (param_4 < 3) {
                return 1;
            }
            if (4 < param_4) {
                return 1;
            }
            fVar1 = 1.0 / f_at(DAT_00728ff0, 0x00);
            local_40[0] = f_at(DAT_00728f60, 0x00) * fVar1;
            local_40[1] = f_at(DAT_00728f60, 0x04) * fVar1;
            local_40[2] = f_at(DAT_00728f60, 0x08) * fVar1;
            local_40[3] = f_at(DAT_00728f60, 0x0c) * fVar1;
            local_30 = f_at(DAT_00728f60, 0x10) * fVar1;
            local_2c = f_at(DAT_00728f60, 0x14) * fVar1;
            local_28 = f_at(DAT_00728f60, 0x18) * fVar1;
            local_24 = f_at(DAT_00728f60, 0x1c) * fVar1;
            local_20 = f_at(DAT_00728f60, 0x20) * fVar1;
            local_1c = f_at(DAT_00728f60, 0x24) * fVar1;
            local_18 = f_at(DAT_00728f60, 0x28) * fVar1;
            local_14 = f_at(DAT_00728f60, 0x2c) * fVar1;
            local_10 = f_at(DAT_00728f60, 0x30) * fVar1;
            local_c = f_at(DAT_00728f60, 0x34) * fVar1;
            local_8 = f_at(DAT_00728f60, 0x38) * fVar1;
            local_4 = f_at(DAT_00728f60, 0x3c) * fVar1;
            pfVar3 = local_40;
            pfVar4 = (float*)DAT_00729000;
            for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
                *pfVar4 = *pfVar3;
                pfVar3 = pfVar3 + 1;
                pfVar4 = pfVar4 + 1;
            }
            if (param_5 != '\0') {
                thunk_FUN_005f266e((float*)DAT_00729000, 0, (float*)DAT_00729000);
            }
            if (param_6 != '\0') {
                thunk_FUN_005f2399((float*)DAT_00729000, (float*)DAT_00729000);
            }
            CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729000, 0);
            return 0;
        }
        if (param_3 != 10) {
            return 1;
        }
    }
    switch (param_4) {
    case 3:
    case 4:
        f_at(DAT_00729040, 0x0c) = 1.0 / f_at(DAT_00728ff0, 0x00);
        f_at(DAT_00729040, 0x00) = f_at(DAT_00728fe0, 0x00) * f_at(DAT_00729040, 0x0c);
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x04) * f_at(DAT_00729040, 0x0c);
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x08) * f_at(DAT_00729040, 0x0c);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x0c) * f_at(DAT_00729040, 0x0c);
        break;
    default:
        return 1;
    case 7:
    case 10:
        f_at(DAT_00729040, 0x00) = f_at(DAT_00728fe0, 0x00) / f_at(DAT_00728ff0, 0x00);
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x04) / f_at(DAT_00728ff0, 0x04);
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x08) / f_at(DAT_00728ff0, 0x08);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x0c) / f_at(DAT_00728ff0, 0x0c);
    }
    CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729040, 0);
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b7d50
// ---------------------------------------------------------------------------
// 0x6b7d50 — observed shape
// The listing declares four parameters; call sites in FUN_006b8f00 pass two
// further stack arguments that the body ignores, hence the trailing ellipsis.
uint32_t FUN_006b7d50(int* param_1, uint32_t param_2, uint32_t param_3,
                      uint32_t param_4, ...)
{
    switch (param_3) {
    case 3:
    case 4:
        break;
    default:
        return 1;
    case 7:
    case 10:
        switch (param_4) {
        case 3:
        case 4:
            f_at(DAT_00729040, 0x0c) = f_at(DAT_00728ff0, 0x00);
            f_at(DAT_00729040, 0x04) = f_at(DAT_00728ff0, 0x00);
            f_at(DAT_00729040, 0x08) = f_at(DAT_00728ff0, 0x00);
            break;
        default:
            return 1;
        case 7:
        case 10:
            f_at(DAT_00729040, 0x0c) = f_at(DAT_00728ff0, 0x0c);
            f_at(DAT_00729040, 0x04) = f_at(DAT_00728ff0, 0x04);
            f_at(DAT_00729040, 0x08) = f_at(DAT_00728ff0, 0x08);
        }
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x08) + f_at(DAT_00729040, 0x08);
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x04) + f_at(DAT_00729040, 0x04);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x0c) + f_at(DAT_00729040, 0x0c);
        f_at(DAT_00729040, 0x00) = f_at(DAT_00728fe0, 0x00) + f_at(DAT_00728ff0, 0x00);
        CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729040, 0);
        return 0;
    }
    switch (param_4) {
    case 3:
    case 4:
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x04);
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x08);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x0c);
        break;
    default:
        return 1;
    case 7:
    case 10:
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x00);
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x00);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x00);
    }
    f_at(DAT_00729040, 0x0c) = f_at(DAT_00728ff0, 0x0c) + f_at(DAT_00729040, 0x0c);
    f_at(DAT_00729040, 0x08) = f_at(DAT_00728ff0, 0x08) + f_at(DAT_00729040, 0x08);
    f_at(DAT_00729040, 0x04) = f_at(DAT_00728ff0, 0x04) + f_at(DAT_00729040, 0x04);
    f_at(DAT_00729040, 0x00) = f_at(DAT_00728fe0, 0x00) + f_at(DAT_00728ff0, 0x00);
    CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729040, 0);
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b7f70
// ---------------------------------------------------------------------------
// 0x6b7f70 — observed shape
// Same call-site shape as FUN_006b7d50: two additional ignored stack arguments.
uint32_t FUN_006b7f70(int* param_1, uint32_t param_2, uint32_t param_3,
                      uint32_t param_4, ...)
{
    switch (param_3) {
    case 3:
    case 4:
        break;
    default:
        return 1;
    case 7:
    case 10:
        switch (param_4) {
        case 3:
        case 4:
            f_at(DAT_00729040, 0x0c) = f_at(DAT_00728ff0, 0x00);
            f_at(DAT_00729040, 0x04) = f_at(DAT_00728ff0, 0x00);
            f_at(DAT_00729040, 0x08) = f_at(DAT_00728ff0, 0x00);
            break;
        default:
            return 1;
        case 7:
        case 10:
            f_at(DAT_00729040, 0x0c) = f_at(DAT_00728ff0, 0x0c);
            f_at(DAT_00729040, 0x04) = f_at(DAT_00728ff0, 0x04);
            f_at(DAT_00729040, 0x08) = f_at(DAT_00728ff0, 0x08);
        }
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x08) - f_at(DAT_00729040, 0x08);
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x04) - f_at(DAT_00729040, 0x04);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x0c) - f_at(DAT_00729040, 0x0c);
        f_at(DAT_00729040, 0x00) = f_at(DAT_00728fe0, 0x00) - f_at(DAT_00728ff0, 0x00);
        CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729040, 0);
        return 0;
    }
    switch (param_4) {
    case 3:
    case 4:
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x04);
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x08);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x0c);
        break;
    default:
        return 1;
    case 7:
    case 10:
        f_at(DAT_00729040, 0x04) = f_at(DAT_00728fe0, 0x00);
        f_at(DAT_00729040, 0x08) = f_at(DAT_00728fe0, 0x00);
        f_at(DAT_00729040, 0x0c) = f_at(DAT_00728fe0, 0x00);
    }
    f_at(DAT_00729040, 0x0c) = f_at(DAT_00729040, 0x0c) - f_at(DAT_00728ff0, 0x0c);
    f_at(DAT_00729040, 0x08) = f_at(DAT_00729040, 0x08) - f_at(DAT_00728ff0, 0x08);
    f_at(DAT_00729040, 0x04) = f_at(DAT_00729040, 0x04) - f_at(DAT_00728ff0, 0x04);
    f_at(DAT_00729040, 0x00) = f_at(DAT_00728fe0, 0x00) - f_at(DAT_00728ff0, 0x00);
    CallSlot28(param_1, (void*)(uintptr_t)param_2, DAT_00729040, 0);
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b8190
// ---------------------------------------------------------------------------
// 0x6b8190 — observed shape
// param_3 is the listing's in_stack_0000001c (a context pointer).
uint32_t FUN_006b8190(int* param_1, int param_2, int param_3)
{
    uint32_t uVar1;
    int iVar2;
    double fVar3;
    double fVar4;
    float fStack_10;
    float fStack_c;
    float fStack_8;
    float fStack_4;

    uVar1 = *(uint32_t*)(param_2 + 0xc);
    switch (uVar1) {
    case 1:
    case 2:
        CallSlot28(param_1, (void*)(uintptr_t)param_2, nullptr, 0);
        return 0;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        iVar2 = FUN_00540540((void*)PTR_s_NDL_UpdateTime_007187c8);
        if (iVar2 == 0) {
            return 0x80000010;
        }
        fStack_10 = *(float*)(iVar2 + 0x10);
        fVar3 = (double)fStack_10;
        switch (uVar1) {
        case 4:
            fVar3 = std::sin(fVar3);
            fStack_10 = (float)fVar3;
            fStack_c = (float)fVar3;
            fStack_8 = (float)fVar3;
            fStack_4 = (float)fVar3;
            break;
        case 5:
            fVar3 = std::cos(fVar3);
            fStack_10 = (float)fVar3;
            fStack_c = (float)fVar3;
            fStack_8 = (float)fVar3;
            fStack_4 = (float)fVar3;
            break;
        case 6:
            fVar3 = std::tan(fVar3);
            /* fall through */
        case 3:
            fStack_10 = (float)fVar3;
            fStack_c = (float)fVar3;
            fStack_8 = (float)fVar3;
            fStack_4 = (float)fVar3;
            break;
        case 7:
            fVar4 = std::sin(fVar3);
            fStack_c = (float)fVar4;
            fVar4 = std::cos(fVar3);
            fStack_8 = (float)fVar4;
            fVar3 = std::tan(fVar3);
            fStack_4 = (float)fVar3;
            break;
        default:
            return 0x80000010;
        }
        break;
    case 8:
        iVar2 = *(int*)(param_3 + 0x14);
        if (iVar2 == 0) {
            return 0;
        }
        fStack_10 = *(float*)(iVar2 + 0x30);
        fStack_c = *(float*)(iVar2 + 0x34);
        fStack_8 = *(float*)(iVar2 + 0x38);
        fStack_4 = *(float*)(iVar2 + 0x58);
        break;
    case 9:
        iVar2 = *(int*)(param_3 + 0x14);
        if (iVar2 == 0) {
            return 0;
        }
        fStack_10 = *(float*)(iVar2 + 0x24);
        fStack_c = *(float*)(iVar2 + 0x28);
        fStack_8 = *(float*)(iVar2 + 0x2c);
        fStack_4 = *(float*)(iVar2 + 0x58);
        break;
    case 10:
        iVar2 = *(int*)(param_3 + 0x14);
        if (iVar2 == 0) {
            return 0;
        }
        fStack_10 = *(float*)(iVar2 + 0x3c);
        fStack_c = *(float*)(iVar2 + 0x40);
        fStack_8 = *(float*)(iVar2 + 0x44);
        fStack_4 = *(float*)(iVar2 + 0x58);
        break;
    case 0xb:
        iVar2 = *(int*)(param_3 + 0x14);
        if (iVar2 == 0) {
            return 0;
        }
        fStack_10 = *(float*)(iVar2 + 0x48);
        fStack_c = *(float*)(iVar2 + 0x4c);
        fStack_8 = *(float*)(iVar2 + 0x50);
        fStack_4 = *(float*)(iVar2 + 0x58);
        break;
    case 0xc:
        if (*(int*)(param_3 + 0x14) == 0) {
            return 0;
        }
        fStack_4 = *(float*)(*(int*)(param_3 + 0x14) + 0x54);
        fStack_c = fStack_4;
        fStack_8 = fStack_4;
        fStack_10 = fStack_4;
        break;
    default:
        goto LAB_006b830f;
    }
    CallSlot28(param_1, (void*)(uintptr_t)param_2, &fStack_10, 0);
LAB_006b830f:
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b86f0
// ---------------------------------------------------------------------------
// 0x6b86f0 — observed shape
// The listing declares five parameters; FUN_006b8f00 passes two further stack
// arguments that the body ignores, hence the trailing ellipsis.
uint32_t FUN_006b86f0(int param_1, int param_2, uint32_t param_3, uint32_t param_4,
                      int param_5, ...)
{
    uint32_t uVar1;
    int iVar2;
    double fVar3;
    double fVar4;

    uVar1 = *(uint32_t*)(param_2 + 0xc);
    switch (uVar1) {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        iVar2 = FUN_00540540((void*)PTR_s_NDL_UpdateTime_007187c8);
        if (iVar2 == 0) {
            return 0x80000010;
        }
        fVar3 = (double)*(float*)(iVar2 + 0x10);
        switch (uVar1) {
        case 3:
            break;
        case 4:
            fVar3 = std::sin(fVar3);
            break;
        case 5:
            fVar3 = std::cos(fVar3);
            break;
        case 6:
            fVar3 = std::tan(fVar3);
            break;
        case 7:
            param_1 = param_1 * 0x10;
            f_at(DAT_00728fe0, param_1 + 0x00) = *(float*)(iVar2 + 0x10);
            fVar4 = std::sin(fVar3);
            f_at(DAT_00728fe0, param_1 + 0x04) = (float)fVar4;
            fVar4 = std::cos(fVar3);
            f_at(DAT_00728fe0, param_1 + 0x08) = (float)fVar4;
            fVar3 = std::tan(fVar3);
            f_at(DAT_00728fe0, param_1 + 0x0c) = (float)fVar3;
            return 7;
        default:
            return 0;
        }
        param_1 = param_1 * 0x10;
        f_at(DAT_00728fe0, param_1 + 0x00) = (float)fVar3;
        f_at(DAT_00728fe0, param_1 + 0x04) = (float)fVar3;
        f_at(DAT_00728fe0, param_1 + 0x08) = (float)fVar3;
        f_at(DAT_00728fe0, param_1 + 0x0c) = (float)fVar3;
        return 7;
    case 8:
        iVar2 = *(int*)(param_5 + 0x14);
        if (iVar2 != 0) {
            param_1 = param_1 * 0x10;
            u_at(DAT_00728fe0, param_1 + 0x00) = *(uint32_t*)(iVar2 + 0x30);
            u_at(DAT_00728fe0, param_1 + 0x04) = *(uint32_t*)(iVar2 + 0x34);
            u_at(DAT_00728fe0, param_1 + 0x08) = *(uint32_t*)(iVar2 + 0x38);
            u_at(DAT_00728fe0, param_1 + 0x0c) = *(uint32_t*)(iVar2 + 0x58);
            return 10;
        }
        break;
    case 9:
        iVar2 = *(int*)(param_5 + 0x14);
        if (iVar2 != 0) {
            param_1 = param_1 * 0x10;
            u_at(DAT_00728fe0, param_1 + 0x00) = *(uint32_t*)(iVar2 + 0x24);
            u_at(DAT_00728fe0, param_1 + 0x04) = *(uint32_t*)(iVar2 + 0x28);
            u_at(DAT_00728fe0, param_1 + 0x08) = *(uint32_t*)(iVar2 + 0x2c);
            u_at(DAT_00728fe0, param_1 + 0x0c) = *(uint32_t*)(iVar2 + 0x58);
            return 10;
        }
        break;
    case 10:
        iVar2 = *(int*)(param_5 + 0x14);
        if (iVar2 != 0) {
            param_1 = param_1 * 0x10;
            u_at(DAT_00728fe0, param_1 + 0x00) = *(uint32_t*)(iVar2 + 0x3c);
            u_at(DAT_00728fe0, param_1 + 0x04) = *(uint32_t*)(iVar2 + 0x40);
            u_at(DAT_00728fe0, param_1 + 0x08) = *(uint32_t*)(iVar2 + 0x44);
            u_at(DAT_00728fe0, param_1 + 0x0c) = *(uint32_t*)(iVar2 + 0x58);
            return 10;
        }
        break;
    case 0xb:
        iVar2 = *(int*)(param_5 + 0x14);
        if (iVar2 != 0) {
            param_1 = param_1 * 0x10;
            u_at(DAT_00728fe0, param_1 + 0x00) = *(uint32_t*)(iVar2 + 0x48);
            u_at(DAT_00728fe0, param_1 + 0x04) = *(uint32_t*)(iVar2 + 0x4c);
            u_at(DAT_00728fe0, param_1 + 0x08) = *(uint32_t*)(iVar2 + 0x50);
            u_at(DAT_00728fe0, param_1 + 0x0c) = *(uint32_t*)(iVar2 + 0x58);
            return 10;
        }
        break;
    case 0xc:
        iVar2 = *(int*)(param_5 + 0x14);
        if (iVar2 != 0) {
            param_1 = param_1 * 0x10;
            u_at(DAT_00728fe0, param_1 + 0x00) = *(uint32_t*)(iVar2 + 0x54);
            u_at(DAT_00728fe0, param_1 + 0x04) = *(uint32_t*)(iVar2 + 0x54);
            u_at(DAT_00728fe0, param_1 + 0x08) = *(uint32_t*)(iVar2 + 0x54);
            u_at(DAT_00728fe0, param_1 + 0x0c) = *(uint32_t*)(iVar2 + 0x54);
            return 10;
        }
        break;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b8940
// ---------------------------------------------------------------------------
// 0x6b8940 — observed shape
// Call sites in FUN_006b8f00 pass one further stack argument that the body
// ignores, hence the trailing ellipsis.
uint32_t FUN_006b8940(int param_1, int param_2, ...)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    char cVar3;
    uint32_t uVar4;

    puVar1 = *(uint32_t**)(param_2 + 0x2c);
    uVar2 = *(uint32_t*)(param_2 + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    uVar4 = 3;
    if (DAT_00729060[uVar2 & 0xff] != 3) {
        uVar2 = *(uint32_t*)(param_2 + 0x10);
        if (DAT_00729098 == '\0') {
            FUN_005e0120();
        }
        uVar4 = 4;
        if (DAT_00729060[uVar2 & 0xff] != 4) {
            uVar2 = *(uint32_t*)(param_2 + 0x10);
            if (DAT_00729098 == '\0') {
                FUN_005e0120();
            }
            if (DAT_00729060[uVar2 & 0xff] == 5) {
                u_at(DAT_00728fe0, param_1 * 0x10 + 0x00) = *puVar1;
                u_at(DAT_00728fe0, param_1 * 0x10 + 0x04) = puVar1[1];
                return 5;
            }
            cVar3 = FUN_005de9a0();
            if (cVar3 != '\0') {
                param_1 = param_1 * 0x10;
                u_at(DAT_00728fe0, param_1 + 0x00) = *puVar1;
                u_at(DAT_00728fe0, param_1 + 0x04) = puVar1[1];
                u_at(DAT_00728fe0, param_1 + 0x08) = puVar1[2];
                return 6;
            }
            cVar3 = FUN_005de9d0();
            if (cVar3 != '\0') {
                param_1 = param_1 * 0x10;
                u_at(DAT_00728fe0, param_1 + 0x00) = *puVar1;
                u_at(DAT_00728fe0, param_1 + 0x04) = puVar1[1];
                u_at(DAT_00728fe0, param_1 + 0x08) = puVar1[2];
                u_at(DAT_00728fe0, param_1 + 0x0c) = puVar1[3];
                return 7;
            }
            cVar3 = FUN_005de180();
            if (cVar3 != '\0') {
                param_1 = param_1 * 0x40;
                u_at(DAT_00728f60, param_1 + 0x00) = *puVar1;
                u_at(DAT_00728f60, param_1 + 0x04) = puVar1[1];
                uVar4 = puVar1[2];
                u_at(DAT_00728f60, param_1 + 0x0c) = 0;
                u_at(DAT_00728f60, param_1 + 0x08) = uVar4;
                u_at(DAT_00728f60, param_1 + 0x10) = puVar1[3];
                u_at(DAT_00728f60, param_1 + 0x14) = puVar1[4];
                uVar4 = puVar1[5];
                u_at(DAT_00728f60, param_1 + 0x1c) = 0;
                u_at(DAT_00728f60, param_1 + 0x18) = uVar4;
                u_at(DAT_00728f60, param_1 + 0x20) = puVar1[6];
                u_at(DAT_00728f60, param_1 + 0x24) = puVar1[7];
                uVar4 = puVar1[8];
                u_at(DAT_00728f60, param_1 + 0x2c) = 0;
                u_at(DAT_00728f60, param_1 + 0x30) = 0;
                u_at(DAT_00728f60, param_1 + 0x34) = 0;
                u_at(DAT_00728f60, param_1 + 0x38) = 0;
                u_at(DAT_00728f60, param_1 + 0x28) = uVar4;
                u_at(DAT_00728f60, param_1 + 0x3c) = 0x3f800000;
                return 8;
            }
            cVar3 = FUN_005de1b0();
            if (cVar3 != '\0') {
                param_1 = param_1 * 0x40;
                u_at(DAT_00728f60, param_1 + 0x00) = *puVar1;
                u_at(DAT_00728f60, param_1 + 0x04) = puVar1[1];
                u_at(DAT_00728f60, param_1 + 0x08) = puVar1[2];
                u_at(DAT_00728f60, param_1 + 0x0c) = puVar1[3];
                u_at(DAT_00728f60, param_1 + 0x10) = puVar1[4];
                u_at(DAT_00728f60, param_1 + 0x14) = puVar1[5];
                u_at(DAT_00728f60, param_1 + 0x18) = puVar1[6];
                u_at(DAT_00728f60, param_1 + 0x1c) = puVar1[7];
                u_at(DAT_00728f60, param_1 + 0x20) = puVar1[8];
                u_at(DAT_00728f60, param_1 + 0x24) = puVar1[9];
                u_at(DAT_00728f60, param_1 + 0x28) = puVar1[10];
                u_at(DAT_00728f60, param_1 + 0x2c) = puVar1[0xb];
                u_at(DAT_00728f60, param_1 + 0x30) = puVar1[0xc];
                u_at(DAT_00728f60, param_1 + 0x34) = puVar1[0xd];
                u_at(DAT_00728f60, param_1 + 0x38) = puVar1[0xe];
                u_at(DAT_00728f60, param_1 + 0x3c) = puVar1[0xf];
                return 9;
            }
            cVar3 = FUN_005dea00();
            if (cVar3 == '\0') {
                return 0;
            }
            param_1 = param_1 * 0x10;
            u_at(DAT_00728fe0, param_1 + 0x00) = *puVar1;
            u_at(DAT_00728fe0, param_1 + 0x04) = puVar1[1];
            u_at(DAT_00728fe0, param_1 + 0x08) = puVar1[2];
            u_at(DAT_00728fe0, param_1 + 0x0c) = puVar1[3];
            return 10;
        }
    }
    u_at(DAT_00728fe0, param_1 * 0x10 + 0x00) = *puVar1;
    return uVar4;
}

// ---------------------------------------------------------------------------
// 0x6b8c10
// ---------------------------------------------------------------------------
// 0x6b8c10 — observed shape
// Call sites in FUN_006b8f00 pass five further stack arguments that the body
// ignores, hence the trailing ellipsis.
uint32_t FUN_006b8c10(int param_1, int param_2, uint32_t param_3, ...)
{
    uint32_t uVar1;
    float fVar2;
    char cVar3;
    int iVar4;
    int* piVar5;

    if (param_3 == 0) {
        return 1;
    }
    iVar4 = FUN_00540540((void*)(uintptr_t)*(uint32_t*)(param_2 + 8));
    if (iVar4 == 0) {
        return 0x80000010;
    }
    piVar5 = FUN_005df860(param_2, iVar4);
    uVar1 = *(uint32_t*)(param_2 + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    if (DAT_00729060[uVar1 & 0xff] == 3) {
        fVar2 = (float)*piVar5;
        if (*piVar5 < 0) {
            fVar2 = fVar2 + 4.2949673e+09f;
        }
        f_at(DAT_00728fe0, param_1 * 0x10 + 0x00) = fVar2;
        return 3;
    }
    cVar3 = FUN_005de940();
    if (cVar3 != '\0') {
        u_at(DAT_00728fe0, param_1 * 0x10 + 0x00) = (uint32_t)*piVar5;
        return 4;
    }
    cVar3 = FUN_005de970();
    if (cVar3 != '\0') {
        u_at(DAT_00728fe0, param_1 * 0x10 + 0x00) = (uint32_t)*piVar5;
        u_at(DAT_00728fe0, param_1 * 0x10 + 0x04) = (uint32_t)piVar5[1];
        return 5;
    }
    cVar3 = FUN_005de9a0();
    if (cVar3 != '\0') {
        param_1 = param_1 * 0x10;
        u_at(DAT_00728fe0, param_1 + 0x00) = (uint32_t)*piVar5;
        u_at(DAT_00728fe0, param_1 + 0x04) = (uint32_t)piVar5[1];
        u_at(DAT_00728fe0, param_1 + 0x08) = (uint32_t)piVar5[2];
        return 6;
    }
    cVar3 = FUN_005de9d0();
    if (cVar3 != '\0') {
        param_1 = param_1 * 0x10;
        u_at(DAT_00728fe0, param_1 + 0x00) = (uint32_t)*piVar5;
        u_at(DAT_00728fe0, param_1 + 0x04) = (uint32_t)piVar5[1];
        u_at(DAT_00728fe0, param_1 + 0x08) = (uint32_t)piVar5[2];
        u_at(DAT_00728fe0, param_1 + 0x0c) = (uint32_t)piVar5[3];
        return 7;
    }
    cVar3 = FUN_005de180();
    if (cVar3 != '\0') {
        param_1 = param_1 * 0x40;
        u_at(DAT_00728f60, param_1 + 0x00) = (uint32_t)*piVar5;
        u_at(DAT_00728f60, param_1 + 0x04) = (uint32_t)piVar5[1];
        iVar4 = piVar5[2];
        u_at(DAT_00728f60, param_1 + 0x0c) = 0;
        u_at(DAT_00728f60, param_1 + 0x08) = (uint32_t)iVar4;
        u_at(DAT_00728f60, param_1 + 0x10) = (uint32_t)piVar5[3];
        u_at(DAT_00728f60, param_1 + 0x14) = (uint32_t)piVar5[4];
        iVar4 = piVar5[5];
        u_at(DAT_00728f60, param_1 + 0x1c) = 0;
        u_at(DAT_00728f60, param_1 + 0x18) = (uint32_t)iVar4;
        u_at(DAT_00728f60, param_1 + 0x20) = (uint32_t)piVar5[6];
        u_at(DAT_00728f60, param_1 + 0x24) = (uint32_t)piVar5[7];
        iVar4 = piVar5[8];
        u_at(DAT_00728f60, param_1 + 0x2c) = 0;
        u_at(DAT_00728f60, param_1 + 0x30) = 0;
        u_at(DAT_00728f60, param_1 + 0x34) = 0;
        u_at(DAT_00728f60, param_1 + 0x38) = 0;
        u_at(DAT_00728f60, param_1 + 0x28) = (uint32_t)iVar4;
        u_at(DAT_00728f60, param_1 + 0x3c) = 0x3f800000;
        return 8;
    }
    cVar3 = FUN_005de1b0();
    if (cVar3 != '\0') {
        param_1 = param_1 * 0x40;
        u_at(DAT_00728f60, param_1 + 0x00) = (uint32_t)*piVar5;
        u_at(DAT_00728f60, param_1 + 0x04) = (uint32_t)piVar5[1];
        u_at(DAT_00728f60, param_1 + 0x08) = (uint32_t)piVar5[2];
        u_at(DAT_00728f60, param_1 + 0x0c) = (uint32_t)piVar5[3];
        u_at(DAT_00728f60, param_1 + 0x10) = (uint32_t)piVar5[4];
        u_at(DAT_00728f60, param_1 + 0x14) = (uint32_t)piVar5[5];
        u_at(DAT_00728f60, param_1 + 0x18) = (uint32_t)piVar5[6];
        u_at(DAT_00728f60, param_1 + 0x1c) = (uint32_t)piVar5[7];
        u_at(DAT_00728f60, param_1 + 0x20) = (uint32_t)piVar5[8];
        u_at(DAT_00728f60, param_1 + 0x24) = (uint32_t)piVar5[9];
        u_at(DAT_00728f60, param_1 + 0x28) = (uint32_t)piVar5[10];
        u_at(DAT_00728f60, param_1 + 0x2c) = (uint32_t)piVar5[0xb];
        u_at(DAT_00728f60, param_1 + 0x30) = (uint32_t)piVar5[0xc];
        u_at(DAT_00728f60, param_1 + 0x34) = (uint32_t)piVar5[0xd];
        u_at(DAT_00728f60, param_1 + 0x38) = (uint32_t)piVar5[0xe];
        u_at(DAT_00728f60, param_1 + 0x3c) = (uint32_t)piVar5[0xf];
        return 9;
    }
    cVar3 = FUN_005dea00();
    if (cVar3 == '\0') {
        return 0;
    }
    param_1 = param_1 * 0x10;
    u_at(DAT_00728fe0, param_1 + 0x00) = (uint32_t)*piVar5;
    u_at(DAT_00728fe0, param_1 + 0x04) = (uint32_t)piVar5[1];
    u_at(DAT_00728fe0, param_1 + 0x08) = (uint32_t)piVar5[2];
    u_at(DAT_00728fe0, param_1 + 0x0c) = (uint32_t)piVar5[3];
    return 10;
}

// ---------------------------------------------------------------------------
// 0x6b8f00
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: uStack_c and the unaff_* values are stack/register remnants
// that Ghidra could not bind to formals; they are zero-initialized here so the
// candidate is well formed, and their observed uses are preserved.
// 0x6b8f00 — observed shape
uint32_t FUN_006b8f00(void* self, uint32_t param_1, int param_2, uint32_t param_3,
                      uint32_t param_4, uint32_t param_5, uint32_t param_6)
{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t unaff_EBX = 0;
    uint32_t unaff_EBP = 0;
    uint32_t unaff_retaddr = 0;
    char* pcVar6;
    int local_18;
    int local_14;
    uint32_t uStack_c = 0;

    uVar4 = *(uint32_t*)(param_2 + 0x14);
    uVar1 = uVar4 & 0xf0000000;
    iVar2 = (int)(uintptr_t)CallSlot24(self, uVar4 & 0xfff);
    iVar3 = (int)(uintptr_t)CallSlot24(self, (uVar4 >> 0xc) & 0xfff);
    if ((iVar2 == 0) || (iVar3 == 0)) {
        pcVar6 = "Invalid entries in OperatorConstant\n";
    }
    else {
        uVar4 = *(uint32_t*)(iVar2 + 0x10);
        if (DAT_00729098 == '\0') {
            FUN_005e0120();
        }
        local_18 = DAT_00729060[uVar4 & 0xff];
        uVar4 = *(uint32_t*)(iVar3 + 0x10);
        if (DAT_00729098 == '\0') {
            FUN_005e0120();
        }
        local_14 = DAT_00729060[uVar4 & 0xff];
        uVar4 = *(uint32_t*)(iVar2 + 0x10) & 0xf0000000;
        if (uVar4 == 0x20000000) {
            local_18 = (int)FUN_006b7670(*(uint32_t*)(iVar2 + 8));
            FUN_006b86f0(0, iVar2, param_1, param_2, param_3, param_4, param_5);
        }
        else if (uVar4 == 0x40000000) {
            FUN_006b8940(0, iVar2, param_6);
        }
        else if ((uVar4 == 0x30000000) || (uVar4 == 0x10000000)) {
            FUN_006b8c10(0, iVar2, param_1, param_2, param_3, param_4, param_5,
                         param_6);
        }
        uVar4 = *(uint32_t*)(iVar3 + 0x10) & 0xf0000000;
        if (uVar4 == 0x20000000) {
            local_14 = (int)FUN_006b7670(*(uint32_t*)(iVar3 + 8));
            FUN_006b86f0(1, iVar3, param_1, param_2, param_3, param_4, param_5);
        }
        else if (uVar4 == 0x30000000) {
            FUN_006b8c10(1, iVar3, param_1, param_2, param_3, param_4, param_5,
                         param_6);
        }
        else if ((uVar4 == 0x40000000) || (uVar4 == 0x10000000)) {
            FUN_006b8940(1, iVar3, param_6);
        }
        if ((local_18 != 0) && (local_14 != 0)) {
            if (0x30000000 < uStack_c) {
                if (uStack_c == 0x40000000) {
                    uVar5 = FUN_006b7f70((int*)(uintptr_t)uVar1, unaff_retaddr,
                                         (uint32_t)local_18, (uint32_t)local_14,
                                         unaff_EBX, unaff_EBP);
                    return uVar5;
                }
                return 1;
            }
            if (uStack_c == 0x30000000) {
                uVar5 = FUN_006b7d50((int*)(uintptr_t)uVar1, unaff_retaddr,
                                     (uint32_t)local_18, (uint32_t)local_14,
                                     unaff_EBX, unaff_EBP);
                return uVar5;
            }
            if (uStack_c == 0x10000000) {
                uVar5 = FUN_006b7790((int*)(uintptr_t)uVar1, unaff_retaddr,
                                     local_18, (uint32_t)local_14, (char)unaff_EBX,
                                     (char)unaff_EBP);
                return uVar5;
            }
            if (uStack_c == 0x20000000) {
                uVar5 = FUN_006b7b00((int*)(uintptr_t)uVar1, unaff_retaddr,
                                     local_18, (int)local_14, (char)unaff_EBX,
                                     (char)unaff_EBP);
                return uVar5;
            }
            return 1;
        }
        pcVar6 = "Invalid operands in OperatorConstant\n";
    }
    FUN_005477c0(1, 0, pcVar6);
    return 1;
}

// ---------------------------------------------------------------------------
// 0x6b921c
// ---------------------------------------------------------------------------
// 0x6b921c — observed shape
// SEH bookkeeping stub: publishes a 12-byte stack area as the exception list.
void FUN_006b921c(void)
{
    uint8_t auStack_c[12];

    ExceptionList = auStack_c;
    return;
}

// ---------------------------------------------------------------------------
// 0x6bc690
// ---------------------------------------------------------------------------
// 0x6bc690 — observed shape
void FUN_006bc690(void)
{
    DAT_007278e4 = 0;
    DAT_007278e0 = 0;
    DAT_007278ec = 1.0f;
    DAT_007278f4 = 0.5f;
    DAT_007278f0 = 1.0f;
    DAT_007278f8 = 0.5f;
    FUN_0054a7e0();
    return;
}

// ---------------------------------------------------------------------------
// 0x6bdd80
// ---------------------------------------------------------------------------
// 0x6bdd80 — observed shape
void FUN_006bdd80(void)
{
    uint32_t* puVar1;

    PTR_PTR_00726610 = (uint8_t*)&PTR_FUN_006f5864;
    FUN_004f0dc0();
    puVar1 = (uint32_t*)(PTR_DAT_0072662c - 8);
    if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)&DAT_008cacc8)) {
        operator_delete__(puVar1);
    }
    PTR_DAT_0072662c = &DAT_008cacd0;
    return;
}
