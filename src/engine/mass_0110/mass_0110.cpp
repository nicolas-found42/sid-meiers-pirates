#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_0052c400(int param_1);
extern uint32_t thunk_FUN_00533c78(uint32_t size);
extern void FUN_0052a820();
extern void FUN_0052a870(int self, int a, int b);
extern void operator_delete(void* ptr);
extern uint32_t DAT_008ed008;
extern uint32_t DAT_008ed00c;
extern void* ExceptionList;

// 0x52a4c0 — observed shape: self in EDI, param_1 index, param_2 mask; scans u32 array at self+0x550 up to self+0x554 entries, checks bits and self+0x548-relative mask-table at param_1*0x4c+0x44; returns 1 in low byte combined with high bits on match else param_2 & 0xffffff00 (0 when mask is 0)
uint32_t FUN_0052a4c0(void* self, int param_1, uint32_t param_2)
{
    uint32_t uVar1;
    int iVar2;
    uint32_t* puVar3;
    uint8_t* base = (uint8_t*)self;

    if (param_2 == 0) {
        return 0;
    }
    iVar2 = 0;
    uVar1 = param_2;
    if (0 < *(int*)(base + 0x554)) {
        puVar3 = *(uint32_t**)(base + 0x550);
        do {
            uVar1 = *puVar3;
            if (((param_2 & uVar1) != 0) &&
                ((*(uint32_t*)(param_1 * 0x4c + 0x44 + *(int*)(base + 0x548)) & uVar1) != 0)) {
                return (uVar1 & 0xffffff00u) | 1u;
            }
            iVar2 = iVar2 + 1;
            puVar3 = puVar3 + 1;
        } while (iVar2 < *(int*)(base + 0x554));
    }
    return uVar1 & 0xffffff00u;
}

// 0x52a520 — observed shape: self in EAX, param_1; iterates 5 strides of 0x4c starting at self+0x5ac, checks byte at +0x32, calls FUN_0052c400(param_1) when nonzero
void FUN_0052a520(void* self, int param_1)
{
    int iVar1 = (int)(intptr_t)self + 0x5ac;
    int iVar2 = 5;
    do {
        if (*(char*)(iVar1 + 0x32) != '\0') {
            FUN_0052c400(param_1);
        }
        iVar1 = iVar1 + 0x4c;
        iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
}

// 0x52a690 — observed shape: param_1 byte count; adds 0x10, allocates via thunk_FUN_00533c78, accumulates into DAT_008ed008/DAT_008ed00c with carry, writes 16-byte alignment size byte at aligned+0xf
void FUN_0052a690(int param_1)
{
    uint32_t uVar1;
    uint32_t uVar2;
    bool bVar3;

    uVar2 = (uint32_t)(param_1 + 0x10);
    uVar1 = thunk_FUN_00533c78(uVar2);
    bVar3 = (DAT_008ed008 + uVar2) < DAT_008ed008;
    DAT_008ed008 = DAT_008ed008 + uVar2;
    DAT_008ed00c = DAT_008ed00c + (uint32_t)bVar3;
    if ((uVar1 & 0xf) == 0) {
        *(uint8_t*)(uVar1 + 0xf) = 0x10;
        return;
    }
    *(char*)((uVar1 & 0xfffffff0u) + 0xf) = (char)((uVar1 & 0xfffffff0u) + 0x10 - uVar1);
}

// 0x52a720 — observed shape: self in ECX, count in EDX; vector-grow with ExceptionList guard; when count > 0x3fffffff calls FUN_0052a820; else ensures capacity (dwords at self+4/8/0xc), allocates via thunk_FUN_00533c78, fixes up via FUN_0052a870, frees old buffer with operator_delete
void FUN_0052a720(void* self, uint32_t count)
{
    void* pvVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    uint8_t* base = (uint8_t*)self;

    if (0x3fffffffu < count) {
        FUN_0052a820();
        return;
    }
    iVar4 = 0;
    if (*(int*)(base + 4) == 0) {
        uVar2 = 0;
    }
    else {
        uVar2 = (uint32_t)(*(int*)(base + 0xc) - *(int*)(base + 4)) >> 2;
    }
    if (uVar2 < count) {
        iVar3 = (int)thunk_FUN_00533c78(count * 4);
        FUN_0052a870(*(int*)(base), *(int*)(base + 4), *(int*)(base + 8));
        pvVar1 = *(void**)(base + 4);
        if (pvVar1 != (void*)0x0) {
            iVar4 = *(int*)(base + 8) - (int)(intptr_t)pvVar1 >> 2;
            operator_delete(pvVar1);
        }
        *(uint32_t*)(base + 0xc) = count * 4 + (uint32_t)iVar3;
        *(int*)(base + 8) = iVar3 + iVar4 * 4;
        *(int*)(base + 4) = iVar3;
    }
}

// 0x52a820 — observed shape: throws length_error "vector<T> too long" via _CxxThrowException; constructs std::string and std::exception then throws with ThrowInfo DAT_00714938
void FUN_0052a820()
{
    // Observed pseudocode constructs basic_string local_44 from "vector<T> too long",
    // an exception object local_28 with vtable PTR_FUN_0070ab54, and a copy local_1c,
    // then calls _CxxThrowException(local_28, &DAT_00714938). C++ type details are
    // provider-specific; the terminal throw is the observed behavior.
    // Terminal call: _CxxThrowException (MSVCR71.DLL) — never returns.
    extern void _CxxThrowException(void*, void*);
    extern int DAT_00714938;
    extern void* PTR_FUN_0070ab54;
    (void)PTR_FUN_0070ab54;
    _CxxThrowException(nullptr, &DAT_00714938);
}

// 0x52a890 — observed shape: recursive quicksort partition on u32 range [param_1,param_2) with depth/limit param_3 and comparator param_4; median-of-... pivot via FUN_0052aa70, heap fallback FUN_0052b160+FUN_0052ac60 when depth exhausted, small-range insertion sort FUN_0052acb0
void FUN_0052a890(int param_1, int param_2, int param_3, uint32_t param_4)
{
    extern void FUN_0052b160(int, int, uint32_t);
    extern void FUN_0052ac60(uint32_t*, int, uint32_t);
    extern void FUN_0052aa70(uint32_t*, uint32_t*, uint32_t*, uint32_t);
    extern void FUN_0052acb0(int, int, uint32_t);
    int iVar1;
    int local_8;
    int local_4;

    iVar1 = (param_2 - param_1) >> 2;
    if (0x20 < iVar1) {
        do {
            if (param_3 < 1) {
                if (0x20 < iVar1) {
                    if (4 < (int)((uint32_t)(param_2 - param_1) & 0xfffffffcU)) {
                        FUN_0052b160(param_1, param_2, param_4);
                    }
                    FUN_0052ac60((uint32_t*)param_1, param_2, param_4);
                    return;
                }
                break;
            }
            FUN_0052aa70((uint32_t*)&local_8, (uint32_t*)param_1, (uint32_t*)param_2, param_4);
            iVar1 = local_4;
            param_3 = param_3 / 2 + (param_3 / 2) / 2;
            if ((int)((uint32_t)(local_8 - param_1) & 0xfffffffcU) < (int)((uint32_t)(param_2 - local_4) & 0xfffffffcU)) {
                FUN_0052a890(param_1, local_8, param_3, param_4);
                param_1 = iVar1;
            }
            else {
                FUN_0052a890(local_4, param_2, param_3, param_4);
                param_2 = local_8;
            }
            iVar1 = (param_2 - param_1) >> 2;
        } while (0x20 < iVar1);
    }
    if (1 < iVar1) {
        FUN_0052acb0(param_1, param_2, param_4);
    }
}

// 0x52a980 — observed shape: same recursive quicksort structure as 0x52a890 but with the second comparator family: partition FUN_0052ad50, heap fallback FUN_0052b250+FUN_0052af40, insertion sort FUN_0052af90
void FUN_0052a980(int param_1, int param_2, int param_3, uint32_t param_4)
{
    extern void FUN_0052b250(int, int, uint32_t);
    extern void FUN_0052af40(uint32_t*, int, uint32_t);
    extern void FUN_0052ad50(uint32_t*, uint32_t*, uint32_t*, uint32_t);
    extern void FUN_0052af90(int, int);
    int iVar1;
    int local_8;
    int local_4;

    iVar1 = (param_2 - param_1) >> 2;
    if (0x20 < iVar1) {
        do {
            if (param_3 < 1) {
                if (0x20 < iVar1) {
                    if (4 < (int)((uint32_t)(param_2 - param_1) & 0xfffffffcU)) {
                        FUN_0052b250(param_1, param_2, param_4);
                    }
                    FUN_0052af40((uint32_t*)param_1, param_2, param_4);
                    return;
                }
                break;
            }
            FUN_0052ad50((uint32_t*)&local_8, (uint32_t*)param_1, (uint32_t*)param_2, param_4);
            iVar1 = local_4;
            param_3 = param_3 / 2 + (param_3 / 2) / 2;
            if ((int)((uint32_t)(local_8 - param_1) & 0xfffffffcU) < (int)((uint32_t)(param_2 - local_4) & 0xfffffffcU)) {
                FUN_0052a980(param_1, local_8, param_3, param_4);
                param_1 = iVar1;
            }
            else {
                FUN_0052a980(local_4, param_2, param_3, param_4);
                param_2 = local_8;
            }
            iVar1 = (param_2 - param_1) >> 2;
        } while (0x20 < iVar1);
    }
    if (1 < iVar1) {
        FUN_0052af90(param_1, param_2);
    }
}

// 0x52aa70 — observed shape: partition pivot (out param_1[0..1]) around median local_c with comparator FUN_00531940; calls ninther FUN_0052b0b0, scans inward, then swaps runs until [param_2,param_3) partitioned
void FUN_0052aa70(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3, uint32_t param_4)
{
    extern char FUN_00531940();
    extern void FUN_0052b0b0(int, int, int, uint32_t);
    uint32_t* puVar4;
    uint32_t uVar2;
    char cVar3;
    uint32_t* puVar5;
    uint32_t* local_c;
    uint32_t* local_8;
    uint32_t* local_4;

    local_c = param_2 + ((((int)(intptr_t)param_3 - (int)(intptr_t)param_2 >> 2) - ((int)(intptr_t)param_3 - (int)(intptr_t)param_2 >> 0x1f) >> 1));
    FUN_0052b0b0((int)(intptr_t)param_2, (int)(intptr_t)local_c, (int)(intptr_t)param_3 + -1, param_4);
    local_4 = local_c;
    while (((param_2 < local_4 && (cVar3 = FUN_00531940(), cVar3 == '\0')) &&
            (cVar3 = FUN_00531940(), cVar3 == '\0'))) {
        local_4 = local_4 + -1;
    }
    do {
        local_c = local_c + 1;
        if ((param_3 <= local_c) || (cVar3 = FUN_00531940(), cVar3 != '\0')) break;
        cVar3 = FUN_00531940();
    } while (cVar3 == '\0');
    puVar4 = local_4;
    puVar5 = local_c;
    local_8 = local_4;
    do {
        if (puVar5 < param_3) {
            do {
                cVar3 = FUN_00531940();
                if (cVar3 == '\0') {
                    cVar3 = FUN_00531940();
                    if (cVar3 != '\0') break;
                    uVar2 = *local_c;
                    *local_c = *puVar5;
                    *puVar5 = uVar2;
                    local_c = local_c + 1;
                }
                puVar5 = puVar5 + 1;
            } while (puVar5 < param_3);
            local_4 = local_8;
        }
        if (param_2 < local_4) {
            do {
                local_4 = local_4 + -1;
                cVar3 = FUN_00531940();
                if (cVar3 == '\0') {
                    cVar3 = FUN_00531940();
                    if (cVar3 != '\0') break;
                    uVar2 = puVar4[-1];
                    puVar4 = puVar4 + -1;
                    *puVar4 = *local_4;
                    *local_4 = uVar2;
                }
                local_8 = local_8 + -1;
            } while (param_2 < local_8);
            local_4 = local_8;
        }
        if (local_4 == param_2) {
            if (puVar5 == param_3) {
                *param_1 = (uint32_t)(intptr_t)puVar4;
                param_1[1] = (uint32_t)(intptr_t)local_c;
                return;
            }
            if (local_c != puVar5) {
                uVar2 = *puVar4;
                *puVar4 = *local_c;
                *local_c = uVar2;
            }
            local_c = local_c + 1;
            uVar2 = *puVar4;
            *puVar4 = *puVar5;
            puVar4 = puVar4 + 1;
            *puVar5 = uVar2;
            puVar5 = puVar5 + 1;
        }
        else {
            local_4 = local_4 + -1;
            local_8 = local_4;
            if (puVar5 == param_3) {
                puVar4 = puVar4 + -1;
                if (local_4 != puVar4) {
                    uVar2 = *local_4;
                    *local_4 = *puVar4;
                    *puVar4 = uVar2;
                }
                {
                    uint32_t* puVar1 = local_c + -1;
                    uVar2 = *puVar4;
                    local_c = local_c + -1;
                    *puVar4 = *puVar1;
                    *local_c = uVar2;
                }
            }
            else {
                uVar2 = *puVar5;
                *puVar5 = *local_4;
                puVar5 = puVar5 + 1;
                *local_4 = uVar2;
            }
        }
    } while (true);
}

// 0x52ac60 — observed shape: heap sort tail selection loop over [param_1,param_2); repeatedly moves last element to front via FUN_0052b2f0(param_1, 0, (size-4)>>2, saved, param_3)
void FUN_0052ac60(uint32_t* param_1, int param_2, uint32_t param_3)
{
    extern void FUN_0052b2f0(int, int, int, uint32_t, uint32_t);
    uint32_t uVar1;

    for (param_2 = param_2 - (int)(intptr_t)param_1; 1 < param_2 >> 2; param_2 = param_2 + -4) {
        uVar1 = *(uint32_t*)((int)(intptr_t)param_1 + param_2 + -4);
        *(uint32_t*)((int)(intptr_t)param_1 + param_2 + -4) = *param_1;
        FUN_0052b2f0((int)(intptr_t)param_1, 0, (param_2 + -4) >> 2, uVar1, param_3);
    }
}

// 0x52acb0 — observed shape: insertion sort over [param_1,param_2) with comparator FUN_00531940; shifts runs via FUN_0052b510(first, run_end, saved_hole)
void FUN_0052acb0(int param_1, int param_2)
{
    extern char FUN_00531940();
    extern void FUN_0052b510(int, int, int);
    int iVar1;
    int iVar2;
    char cVar3;
    int iVar4;

    iVar1 = param_1;
    if (param_1 != param_2) {
        while ((iVar2 = iVar1, iVar1 = iVar2 + 4, iVar1) != param_2) {
            cVar3 = FUN_00531940();
            if (cVar3 == '\0') {
                cVar3 = FUN_00531940();
                iVar4 = iVar1;
                if (cVar3 != '\0') {
                    do {
                        iVar4 = iVar4 + -4;
                        cVar3 = FUN_00531940();
                    } while (cVar3 != '\0');
                    if ((iVar4 != iVar1) && (iVar1 != iVar2 + 8)) {
                        FUN_0052b510(iVar4, iVar1, iVar2 + 8);
                    }
                }
            }
            else if ((param_1 != iVar1) && (iVar1 != iVar2 + 8)) {
                FUN_0052b510(param_1, iVar1, iVar2 + 8);
            }
        }
    }
}

// 0x52ad50 — observed shape: partition pivot (out param_1[0..1]) around median with comparator FUN_005337b0; calls ninther FUN_0052b1a0, scans inward, then swaps runs until [param_2,param_3) partitioned (mirror of 0x52aa70)
void FUN_0052ad50(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3, uint32_t param_4)
{
    extern char FUN_005337b0();
    extern void FUN_0052b1a0(int, int, int, uint32_t);
    uint32_t uVar2;
    char cVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    uint32_t* local_c;
    uint32_t* local_8;
    uint32_t* local_4;

    local_c = param_2 + ((((int)(intptr_t)param_3 - (int)(intptr_t)param_2 >> 2) - ((int)(intptr_t)param_3 - (int)(intptr_t)param_2 >> 0x1f) >> 1));
    FUN_0052b1a0((int)(intptr_t)param_2, (int)(intptr_t)local_c, (int)(intptr_t)param_3 + -1, param_4);
    local_4 = local_c;
    while (((param_2 < local_4 && (cVar3 = FUN_005337b0(), cVar3 == '\0')) &&
            (cVar3 = FUN_005337b0(), cVar3 == '\0'))) {
        local_4 = local_4 + -1;
    }
    do {
        local_c = local_c + 1;
        if ((param_3 <= local_c) || (cVar3 = FUN_005337b0(), cVar3 != '\0')) break;
        cVar3 = FUN_005337b0();
    } while (cVar3 == '\0');
    puVar4 = local_c;
    puVar5 = local_4;
    local_8 = local_4;
    do {
        if (puVar4 < param_3) {
            do {
                cVar3 = FUN_005337b0();
                if (cVar3 == '\0') {
                    cVar3 = FUN_005337b0();
                    if (cVar3 != '\0') break;
                    uVar2 = *local_c;
                    *local_c = *puVar4;
                    *puVar4 = uVar2;
                    local_c = local_c + 1;
                }
                puVar4 = puVar4 + 1;
            } while (puVar4 < param_3);
            local_4 = local_8;
        }
        if (param_2 < local_4) {
            do {
                local_4 = local_4 + -1;
                cVar3 = FUN_005337b0();
                if (cVar3 == '\0') {
                    cVar3 = FUN_005337b0();
                    if (cVar3 != '\0') break;
                    uVar2 = puVar5[-1];
                    puVar5 = puVar5 + -1;
                    *puVar5 = *local_4;
                    *local_4 = uVar2;
                }
                local_8 = local_8 + -1;
            } while (param_2 < local_8);
            local_4 = local_8;
        }
        if (local_4 == param_2) {
            if (puVar4 == param_3) {
                *param_1 = (uint32_t)(intptr_t)puVar5;
                param_1[1] = (uint32_t)(intptr_t)local_c;
                return;
            }
            if (local_c != puVar4) {
                uVar2 = *puVar5;
                *puVar5 = *local_c;
                *local_c = uVar2;
            }
            local_c = local_c + 1;
            uVar2 = *puVar5;
            *puVar5 = *puVar4;
            puVar5 = puVar5 + 1;
            *puVar4 = uVar2;
            puVar4 = puVar4 + 1;
        }
        else {
            local_4 = local_4 + -1;
            local_8 = local_4;
            if (puVar4 == param_3) {
                puVar5 = puVar5 + -1;
                if (local_4 != puVar5) {
                    uVar2 = *local_4;
                    *local_4 = *puVar5;
                    *puVar5 = uVar2;
                }
                {
                    uint32_t* puVar1 = local_c + -1;
                    uVar2 = *puVar5;
                    local_c = local_c + -1;
                    *puVar5 = *puVar1;
                    *local_c = uVar2;
                }
            }
            else {
                uVar2 = *puVar4;
                *puVar4 = *local_4;
                puVar4 = puVar4 + 1;
                *local_4 = uVar2;
            }
        }
    } while (true);
}

// 0x52af40 — observed shape: heap sort tail selection loop over [param_1,param_2); moves last to front via FUN_0052b3d0(param_1, 0, (size-4)>>2, saved, param_3)
void FUN_0052af40(uint32_t* param_1, int param_2, uint32_t param_3)
{
    extern void FUN_0052b3d0(int, int, int, uint32_t, uint32_t);
    uint32_t uVar1;

    for (param_2 = param_2 - (int)(intptr_t)param_1; 1 < param_2 >> 2; param_2 = param_2 + -4) {
        uVar1 = *(uint32_t*)((int)(intptr_t)param_1 + param_2 + -4);
        *(uint32_t*)((int)(intptr_t)param_1 + param_2 + -4) = *param_1;
        FUN_0052b3d0((int)(intptr_t)param_1, 0, (param_2 + -4) >> 2, uVar1, param_3);
    }
}

// 0x52af90 — observed shape: insertion sort over [param_1,param_2) with comparator FUN_005337b0; shifts runs via FUN_0052b510(first, run_end, saved_hole)
void FUN_0052af90(int param_1, int param_2)
{
    extern char FUN_005337b0();
    extern void FUN_0052b510(int, int, int);
    int iVar1;
    int iVar2;
    char cVar3;
    int iVar4;

    iVar1 = param_1;
    if (param_1 != param_2) {
        while ((iVar2 = iVar1, iVar1 = iVar2 + 4, iVar1) != param_2) {
            cVar3 = FUN_005337b0();
            if (cVar3 == '\0') {
                cVar3 = FUN_005337b0();
                iVar4 = iVar1;
                if (cVar3 != '\0') {
                    do {
                        iVar4 = iVar4 + -4;
                        cVar3 = FUN_005337b0();
                    } while (cVar3 != '\0');
                    if ((iVar4 != iVar1) && (iVar1 != iVar2 + 8)) {
                        FUN_0052b510(iVar4, iVar1, iVar2 + 8);
                    }
                }
            }
            else if ((param_1 != iVar1) && (iVar1 != iVar2 + 8)) {
                FUN_0052b510(param_1, iVar1, iVar2 + 8);
            }
        }
    }
}

// 0x52b030 — observed shape: copy u32 range [param_1,param_2) to param_3, advancing dest even when source is null-checked
void FUN_0052b030(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3)
{
    for (; param_1 != param_2; param_1 = param_1 + 1) {
        if (param_3 != (uint32_t*)0x0) {
            *param_3 = *param_1;
        }
        param_3 = param_3 + 1;
    }
}

// 0x52b0b0 — observed shape: ninther over u32 range [param_1,param_3] around median param_2; short range (<0x29 dwords) defers to FUN_0052b290, else four FUN_0052b290 calls on eighth-sized blocks
void FUN_0052b0b0(int param_1, int param_2, int param_3, uint32_t param_4)
{
    extern void FUN_0052b290(uint32_t*, uint32_t*, uint32_t*);
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = (param_3 - param_1) >> 2;
    if (iVar1 < 0x29) {
        FUN_0052b290((uint32_t*)param_1, (uint32_t*)param_2, (uint32_t*)param_3);
        return;
    }
    iVar1 = iVar1 + 1;
    iVar2 = (iVar1 + ((iVar1 >> 0x1f) & 7U)) >> 3;
    iVar1 = iVar2 * 4 + param_1;
    FUN_0052b290((uint32_t*)param_1, (uint32_t*)iVar1, (uint32_t*)(iVar2 * 8 + param_1));
    FUN_0052b290((uint32_t*)(param_2 + iVar2 * -4), (uint32_t*)param_2, (uint32_t*)(iVar2 * 4 + param_2));
    iVar3 = param_3 + iVar2 * -4;
    FUN_0052b290((uint32_t*)(param_3 + iVar2 * -8), (uint32_t*)iVar3, (uint32_t*)param_3);
    FUN_0052b290((uint32_t*)iVar1, (uint32_t*)param_2, (uint32_t*)iVar3);
}

// 0x52b160 — observed shape: heapify loop for iVar2 = count - sign-shift>>1 down to 1; calls FUN_0052b2f0(param_1, iVar2-1, count, *(param_1-4+iVar2*4), param_3)
void FUN_0052b160(int param_1, int param_2, uint32_t param_3)
{
    extern void FUN_0052b2f0(int, int, int, uint32_t, uint32_t);
    int iVar1;
    int iVar2;
    int iVar3;

    iVar3 = (param_2 - param_1) >> 2;
    iVar2 = iVar3 - ((param_2 - param_1 >> 0x1f) >> 1);
    while (0 < iVar2) {
        iVar1 = iVar2 * 4;
        iVar2 = iVar2 + -1;
        FUN_0052b2f0(param_1, iVar2, iVar3, *(uint32_t*)(param_1 + -4 + iVar1), param_3);
    }
}

// 0x52b1a0 — observed shape: ninther over u32 range [param_1,param_3] around median param_2; short range (<0x29 dwords) defers to FUN_0052b370, else four FUN_0052b370 calls on eighth-sized blocks
void FUN_0052b1a0(int param_1, int param_2, int param_3, uint32_t param_4)
{
    extern void FUN_0052b370(uint32_t*, uint32_t*, uint32_t*, uint32_t);
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = (param_3 - param_1) >> 2;
    if (iVar1 < 0x29) {
        FUN_0052b370((uint32_t*)param_1, (uint32_t*)param_2, (uint32_t*)param_3, param_4);
        return;
    }
    iVar1 = iVar1 + 1;
    iVar2 = (iVar1 + ((iVar1 >> 0x1f) & 7U)) >> 3;
    iVar1 = iVar2 * 4 + param_1;
    FUN_0052b370((uint32_t*)param_1, (uint32_t*)iVar1, (uint32_t*)(iVar2 * 8 + param_1), param_4);
    FUN_0052b370((uint32_t*)(param_2 + iVar2 * -4), (uint32_t*)param_2, (uint32_t*)(iVar2 * 4 + param_2), param_4);
    iVar3 = param_3 + iVar2 * -4;
    FUN_0052b370((uint32_t*)(param_3 + iVar2 * -8), (uint32_t*)iVar3, (uint32_t*)param_3, param_4);
    FUN_0052b370((uint32_t*)iVar1, (uint32_t*)param_2, (uint32_t*)iVar3, param_4);
}

// 0x52b250 — observed shape: heapify loop for iVar2 = count - sign-shift>>1 down to 1; calls FUN_0052b3d0(param_1, iVar2-1, count, *(param_1-4+iVar2*4), param_3)
void FUN_0052b250(int param_1, int param_2, uint32_t param_3)
{
    extern void FUN_0052b3d0(int, int, int, uint32_t, uint32_t);
    int iVar1;
    int iVar2;
    int iVar3;

    iVar3 = (param_2 - param_1) >> 2;
    iVar2 = iVar3 - ((param_2 - param_1 >> 0x1f) >> 1);
    while (0 < iVar2) {
        iVar1 = iVar2 * 4;
        iVar2 = iVar2 + -1;
        FUN_0052b3d0(param_1, iVar2, iVar3, *(uint32_t*)(param_1 + -4 + iVar1), param_3);
    }
}

// 0x52b290 — observed shape: 3-element sorting network over param_1/param_2/param_3 u32 pointers with comparator FUN_00531940; swaps param_1-param_2, then param_2-param_3, then param_1-param_2 when comparator true
void FUN_0052b290(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3)
{
    extern char FUN_00531940();
    uint32_t uVar1;
    char cVar2;

    cVar2 = FUN_00531940();
    if (cVar2 != '\0') {
        uVar1 = *param_2;
        *param_2 = *param_1;
        *param_1 = uVar1;
    }
    cVar2 = FUN_00531940();
    if (cVar2 != '\0') {
        uVar1 = *param_3;
        *param_3 = *param_2;
        *param_2 = uVar1;
    }
    cVar2 = FUN_00531940();
    if (cVar2 != '\0') {
        uVar1 = *param_2;
        *param_2 = *param_1;
        *param_1 = uVar1;
    }
}

// 0x52b2f0 — observed shape: sift-down over heap array param_1 with hole index param_2 and count param_3; picks child 2*i+2 or 2*i+1 via FUN_00531940 then calls FUN_0052b450(param_1, final, param_2, param_5)
void FUN_0052b2f0(int param_1, int param_2, int param_3, uint32_t param_4, uint32_t param_5)
{
    extern char FUN_00531940();
    extern void FUN_0052b450(int, int, int, uint32_t);
    char cVar1;
    int iVar2;
    int iVar3;

    iVar3 = param_2;
    while (true) {
        iVar2 = iVar3 * 2 + 2;
        if (param_3 <= iVar2) break;
        cVar1 = FUN_00531940();
        if (cVar1 != '\0') {
            iVar2 = iVar3 * 2 + 1;
        }
        *(uint32_t*)(param_1 + iVar3 * 4) = *(uint32_t*)(param_1 + iVar2 * 4);
        iVar3 = iVar2;
    }
    if (iVar2 == param_3) {
        *(uint32_t*)(param_1 + iVar3 * 4) = *(uint32_t*)(param_1 + -4 + param_3 * 4);
        iVar3 = param_3 + -1;
    }
    FUN_0052b450(param_1, iVar3, param_2, param_5);
}
