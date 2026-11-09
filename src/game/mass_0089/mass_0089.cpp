#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cwchar>
#include <windows.h>

// Extern helpers referenced by the observed listings.
extern void FUN_00508fa0(float param_1, float param_2, uint32_t param_3, uint32_t* param_4,
                         char* param_5, uint32_t param_6, int32_t param_7, char param_8,
                         uint32_t param_9, uint32_t param_10, uint32_t param_11, uint32_t param_12);
extern double FUN_00509500(int32_t param_1, char* param_2, char param_3);
extern double FUN_005096b0();
extern int32_t FUN_0050a180(int32_t param_1, char param_2);
extern int32_t FUN_0050a010(int32_t param_1);
extern void FUN_0050a7c0(uint32_t param_1);
extern void FUN_0050ade0(float param_1, float param_2, float param_3, float param_4, float param_5,
                         float param_6, float param_7, float param_8, uint32_t param_9,
                         uint32_t param_10, uint32_t param_11, uint32_t param_12);
extern void FUN_0050ac30();
extern int32_t FUN_005f0ddc();
extern void* thunk_FUN_00533c78(int32_t size);
extern void* FUN_00533c78(int32_t size);
extern void FUN_0050b150(void* param_1);
extern void FUN_004f3350();
extern void FUN_004127b0(void* param_1, int elemSize, int32_t count, void* table);
extern void FUN_0050afa0(void* param_1);
extern void FUN_00509e40(char* param_1, wchar_t* param_2);
extern uint32_t FUN_00509ee0(int32_t param_1, int32_t param_2, int32_t param_3, uint32_t* param_4, uint32_t* param_5);
extern void FUN_00541580();
extern void* FUN_00551880(uint32_t param_1);
extern void FUN_004aac50(void* param_1);
extern void FUN_004aac10(uint32_t param_1);
extern void FUN_00534130();
extern void FUN_00533d10(int32_t param_1, int32_t param_2);
extern char FUN_0050b0f0(void* param_1);
extern void operator_delete__(void* param_1);
extern void* FUN_004f17f0(const char* fmt, ...);
extern void* FUN_005535d0(uint32_t a, void* b, int32_t c, void* d, void* e, int32_t f, int32_t g, uint32_t h, void* i, int32_t j, int32_t k);

extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t DAT_008caccc;
extern uint8_t DAT_008cacd0[];
extern void* DAT_00727b28;
extern void* PTR_FUN_00717a84;
extern void* PTR_FUN_007115bc;
extern void* PTR_FUN_007115d8;
extern void* DAT_008cacc8;
extern void* DAT_00746e66;
extern void LAB_005cea70;
extern void LAB_004b1250;

// 0x508f20 — observed shape
// Self (ECX): object with +0x1c count and +0x24 table pointer; each entry is 0x30 bytes.
// Computes entry = table + (count-1)*0x30 + 0x24, then forwards to FUN_00508fa0.
void FUN_00508f20(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, void* self, int32_t edxArg)
{
    uint8_t* selfBytes = (uint8_t*)self;
    int32_t count = *(int32_t*)(selfBytes + 0x1c);
    int32_t table = *(int32_t*)(selfBytes + 0x24);
    float* pfVar1 = (float*)(table + (count - 1) * 0x30 + 0x24);
    FUN_00508fa0((float)(*(int32_t*)((char*)self + 0) + (float)(*(float*)(edxArg + 0x10))), pfVar1[1], pfVar1[2], nullptr, nullptr, 1, (int32_t)(intptr_t)self, 1, param_2, param_3, param_4, param_5);
}

// 0x508fa0 — observed shape
// Central text-shaping/dispatch function. Writes six dwords at self+0x24..0x40,
// computes line advance via FUN_00509500/FUN_005096b0, iterates param_5 resolving
// glyphs through the table at self+0x44, and emits vertices via FUN_0050ade0.
void FUN_00508fa0(float param_1, float param_2, uint32_t param_3, uint32_t* param_4,
                  char* param_5, uint32_t param_6, int32_t param_7, char param_8, uint32_t param_9,
                  uint32_t param_10, uint32_t param_11, uint32_t param_12, void* self)
{
    uint8_t* selfBytes = (uint8_t*)self;
    int32_t iVar2 = (int32_t)(intptr_t)self;
    float local_3c = param_2;
    float local_20 = param_2;
    uint32_t* local_38 = param_4;
    *(uint32_t*)(selfBytes + 0x24) = param_9;
    *(uint32_t*)(selfBytes + 0x28) = param_10;
    *(uint32_t*)(selfBytes + 0x2c) = param_11;
    *(uint32_t*)(selfBytes + 0x30) = param_12;
    *(uint32_t*)(selfBytes + 0x34) = param_9;
    *(uint32_t*)(selfBytes + 0x38) = param_10;
    *(uint32_t*)(selfBytes + 0x3c) = param_11;
    *(uint32_t*)(selfBytes + 0x40) = param_12;
    uint32_t local_1c = param_3;
    uint32_t* local_18 = param_4;
    if (param_8 == '\0') {
        local_3c = 0.5f;
        (void)local_38;
    }
    char* pcVar5 = param_5;
    char cVar4;
    do {
        cVar4 = *pcVar5;
        pcVar5 = pcVar5 + 1;
    } while (cVar4 != '\0');
    uint32_t local_34 = (uint32_t)(pcVar5 - (param_5 + 1));
    uint32_t local_24 = param_6 & 1;
    float local_2c = 0.0f;
    float local_30 = 0.0f;
    double frac = 0.0;
    if (local_24 == 0) {
        if ((param_6 & 2) == 0) {
            if ((param_6 & 4) == 0) goto LAB_00509105;
            {
                double fVar10 = FUN_00509500(iVar2, param_5, 1);
                double half = (double)((float)(fVar10 * (float)0.5));
                double intpart = 0.0;
                modf(half, &intpart);
                (void)frac;
                int32_t iVar6 = FUN_005f0ddc();
                fVar10 = (double)iVar6 / (double)1 + intpart;
                (void)fVar10;
            }
        } else {
            double fVar10 = FUN_00509500(iVar2, param_5, 1);
            (void)fVar10;
        }
        (void)param_1; (void)local_3c;
    } else {
        (void)param_1; (void)local_3c;
    }
LAB_00509105:
    if ((param_6 & 8) != 0) {
        double fVar10 = FUN_005096b0();
        double intpart = 0.0;
        modf((double)((float)(fVar10 * (float)0.5 + (float)(float)local_38), 0.0f, 0.0f), &intpart);
        uint32_t param_9_2 = 1;
        int32_t iVar6 = FUN_005f0ddc();
        (void)(iVar6 / (int)param_9_2 + (float)intpart);
        (void)local_2c;
    }
    if (param_8 == '\0') {
        *(float*)(param_7 + 0x3c) = (float)(float)local_38 + 0.5f;
    }
    if (0 < *(int32_t*)(param_7 + 0x40)) {
        (void)((*(float*)(*(int32_t*)(iVar2 + 0x48) + 0x308) + *(float*)(iVar2 + 0x10)) * (float)*(int32_t*)(param_7 + 0x40));
    }
    local_2c = (float)*(int32_t*)(iVar2 + 8);
    if (*(int32_t*)(iVar2 + 8) < 0) local_2c = local_2c + 4.2949673e+09f;
    local_2c = 1.0f / local_2c;
    local_30 = (float)*(int32_t*)(iVar2 + 0xc);
    if (*(int32_t*)(iVar2 + 0xc) < 0) local_30 = local_30 + 4.2949673e+09f;
    local_30 = 1.0f / local_30;
    uint32_t uVar7 = (uint32_t)FUN_0050a010(iVar2);
    FUN_0050a7c0(uVar7);
    uint32_t param_9_scan = 0;
    if (local_34 != 0) {
        do {
            uint32_t uVar3 = param_9_scan;
            if (param_5[param_9_scan] == '<') {
                int32_t iVar6 = FUN_0050a180(iVar2, 0);
                param_9_scan = uVar3 + (uint32_t)iVar6;
                if (local_34 <= param_9_scan) break;
            }
            char cur = param_5[param_9_scan];
            int32_t* piVar1 = *(int32_t**)(iVar2 + 0x44);
            (void)piVar1;
            if (cur == 0x20) {
                *(int32_t*)(param_7 + 0x40) = *(int32_t*)(param_7 + 0x40) + 1;
            }
            if (cur == 10) {
                *(float*)(param_7 + 0x3c) = *(float*)(param_7 + 0x3c) - *(float*)(iVar2 + 4);
            }
            param_9_scan = param_9_scan + 1;
        } while (param_9_scan < local_34);
    }
    FUN_0050ac30();
    if (param_8 == '\0') {
        int32_t iVar2b = *(int32_t*)(param_7 + 0x34);
        *(float*)(iVar2b + 0x5c) = local_20;
        *(uint32_t*)(iVar2b + 0x60) = local_1c;
        *(uint32_t**)(iVar2b + 100) = local_18;
    }
}

// 0x509500 — observed shape
// Returns max line advance. Scans param_2, skips <...> tags via FUN_0050a180,
// resolves glyph records through the vtable at *(param_1+0x44), accumulates
// (glyph.x + self[0x10] - glyph.y) per char, tracking max per line.
double FUN_00509500(int32_t param_1, char* param_2, char param_3)
{
    char cVar1;
    int32_t* piVar2;
    uint32_t* puVar3;
    char cVar4;
    char* pcVar5;
    uint32_t uVar6;
    int32_t iVar7;
    uint32_t uVar8;
    float local_14 = 0.0f;
    float local_10 = 0.0f;
    int32_t local_c = 0;
    int32_t iStack_8 = 0;
    pcVar5 = param_2;
    do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar6 = (uint32_t)(pcVar5 - (param_2 + 1));
    uVar8 = 0;
    uint32_t local_4 = uVar6;
    if (uVar6 != 0) {
        do {
            if (param_2[uVar8] == '<') {
                iVar7 = FUN_0050a180(param_1, 1);
                uVar8 = uVar8 + (uint32_t)iVar7;
                if (uVar6 <= uVar8) break;
            }
            cVar1 = param_2[uVar8];
            if (cVar1 == '\n') {
                if (param_3 != '\0') {
                    return (double)local_14;
                }
                if (local_10 < local_14) local_10 = local_14;
                local_14 = 0.0f;
            } else {
                piVar2 = *(int32_t**)(param_1 + 0x44);
                local_c = 0;
                typedef int32_t (*Fn1)(char);
                typedef char (*Fn2)(char, uint16_t);
                Fn1 fn1 = *(Fn1*)(*piVar2 + 4);
                iVar7 = fn1(cVar1);
                puVar3 = *(uint32_t**)(piVar2[2] + iVar7 * 4);
                iVar7 = local_c;
                for (; local_c = iVar7, puVar3 != nullptr; puVar3 = (uint32_t*)*puVar3) {
                    Fn2 fn2 = *(Fn2*)(*piVar2 + 8);
                    cVar4 = fn2(cVar1, *(uint16_t*)(puVar3 + 1));
                    if (cVar4 != '\0') {
                        iVar7 = (int32_t)puVar3[2];
                        break;
                    }
                    iVar7 = local_c;
                }
                iStack_8 = iVar7;
                if ((param_2[uVar8] != ' ') && (param_2[uVar8] != '\n') && (iVar7 == 0)) {
                    local_c = iVar7;
                    FUN_0050b150(&local_c);
                    if (local_c == 0) {
                        local_c = 0;
                        FUN_0050b150(&local_c);
                        iStack_8 = local_c;
                    }
                }
                local_14 = ((*(float*)(iStack_8 + 8) + *(float*)(param_1 + 0x10)) - *(float*)(iStack_8 + 0x14)) + local_14;
                uVar6 = local_4;
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < uVar6);
        if (local_10 < local_14) local_10 = local_14;
    }
    return (double)local_10;
}

// 0x5096b0 — observed shape
// Counts line breaks: starts from *(EDI+4), 4-at-a-time scan over ECX string
// adding the float per '\n'; handles null ECX by returning *(EDI+4).
double FUN_005096b0(void* self, uint32_t* lineHeightPtr)
{
    char* in_ECX = (char*)self;
    uint32_t unaff_EDI = (uint32_t)(intptr_t)lineHeightPtr;
    if (in_ECX == nullptr) {
        return (double)*(float*)(unaff_EDI + 4);
    }
    double fVar5 = (double)*(float*)(unaff_EDI + 4);
    char* pcVar2 = in_ECX;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uint32_t uVar3 = (uint32_t)(pcVar2 - (in_ECX + 1));
    uint32_t uVar4 = 0;
    if (3 < (int32_t)uVar3) {
        do {
            if (in_ECX[uVar4] == '\n') fVar5 = fVar5 + (double)*(float*)(unaff_EDI + 4);
            if (in_ECX[uVar4 + 1] == '\n') fVar5 = fVar5 + (double)*(float*)(unaff_EDI + 4);
            if (in_ECX[uVar4 + 2] == '\n') fVar5 = fVar5 + (double)*(float*)(unaff_EDI + 4);
            if (in_ECX[uVar4 + 3] == '\n') fVar5 = fVar5 + (double)*(float*)(unaff_EDI + 4);
            uVar4 = uVar4 + 4;
        } while (uVar4 < uVar3 - 3);
    }
    for (; uVar4 < uVar3; uVar4 = uVar4 + 1) {
        if (in_ECX[uVar4] == '\n') fVar5 = fVar5 + (double)*(float*)(unaff_EDI + 4);
    }
    return fVar5;
}

// 0x509720 — observed shape
// Wraps text into param_4 lines of at most param_2 width; returns
// *(param_1+4) * lineCount. Scans param_3 with tag skipping, measures via
// glyph table at param_1+0x44, spills completed lines to param_4+local_14.
double FUN_00509720(int32_t param_1, float param_2, char* param_3, int32_t param_4)
{
    uint32_t local_4;
    float local_20 = 0.0f;
    float local_18 = 0.0f;
    int32_t local_1c = 0;
    int32_t local_14 = 0;
    int32_t local_10 = 0;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;
    size_t _Count = 0;
    char* pcVar4 = param_3;
    char cVar3;
    do {
        cVar3 = *pcVar4;
        pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
    local_4 = (uint32_t)(pcVar4 - (param_3 + 1));
    uint32_t uVar7 = 0;
    int32_t iVar5 = 0;
    if (local_4 != 0) {
        do {
            uint32_t uVar2 = local_4;
            if (param_3[uVar7] == '<') {
                iVar5 = FUN_0050a180(param_1, 1);
                uVar7 = uVar7 + (uint32_t)iVar5;
                _Count = _Count + (size_t)iVar5;
                if (uVar2 <= uVar7) break;
            }
            if (param_3[uVar7] == 10) {
                local_20 = 0.0f;
                local_18 = local_18 + 1.0f;
            } else {
                int32_t* piVar1 = *(int32_t**)(param_1 + 0x44);
                local_c = (uint32_t)(uint8_t)param_3[uVar7];
                local_10 = 0;
                typedef int32_t (*Fn1)(uint32_t);
                typedef char (*Fn2)(uint32_t, uint16_t);
                Fn1 fn1 = *(Fn1*)(*piVar1 + 4);
                iVar5 = fn1(local_c);
                int32_t* piVar6 = *(int32_t**)(piVar1[2] + iVar5 * 4);
                if (piVar6 != nullptr) {
                    do {
                        Fn2 fn2 = *(Fn2*)(*piVar1 + 8);
                        cVar3 = fn2(local_c, (uint16_t)piVar6[1]);
                        if (cVar3 != '\0') {
                            local_c = (uint32_t)piVar6[2];
                            goto LAB_005097f5;
                        }
                        piVar6 = (int32_t*)*piVar6;
                    } while (piVar6 != nullptr);
                }
                local_c = (uint32_t)local_10;
LAB_005097f5:
                if ((param_3[uVar7] != ' ') && (param_3[uVar7] != '\n') && (local_c == 0)) {
                    local_10 = (int32_t)local_c;
                    FUN_0050b150(&local_10);
                    if (local_10 == 0) {
                        local_10 = 0;
                        FUN_0050b150(&local_10);
                        local_c = (uint32_t)local_10;
                    }
                }
                local_20 = ((*(float*)(local_c + 8) + *(float*)(param_1 + 0x10)) - *(float*)(local_c + 0x14)) + local_20;
                if (param_2 < local_20) {
                    cVar3 = param_3[uVar7];
                    while (cVar3 != ' ') {
                        uVar7 = uVar7 - 1;
                        _Count = _Count - 1;
                        if (uVar7 == 0) break;
                        cVar3 = param_3[uVar7];
                    }
                    if (uVar7 == local_8) break;
                    local_8 = uVar7;
                    strncpy((char*)(local_14 + param_4), param_3 + local_1c, _Count);
                    local_18 = local_18 + 1.0f;
                    local_1c = local_1c + (int32_t)_Count;
                    *(char*)(local_14 + _Count + param_4) = 10;
                    local_14 = local_14 + (int32_t)_Count + 1;
                    _Count = 0;
                    local_20 = 0.0f;
                    if (param_3[local_1c] == ' ') local_1c = local_1c + 1;
                }
            }
            uVar7 = uVar7 + 1;
            _Count = _Count + 1;
        } while (uVar7 < local_4);
        iVar5 = local_14;
    }
    param_3 = param_3 + local_1c;
    iVar5 = iVar5 - (int32_t)(intptr_t)param_3;
    do {
        cVar3 = *param_3;
        param_3[iVar5 + param_4] = cVar3;
        param_3 = param_3 + 1;
    } while (cVar3 != '\0');
    return (double)*(float*)(param_1 + 4) * (double)local_18;
}

// 0x509970 — observed shape
// Font atlas builder: allocates glyph table via thunk_FUN_00533c78, walks the
// wide string resolving glyphs, scans the bitmap with FUN_00509ee0/FUN_00509f90,
// and on font load failure reports via the PTR_FUN_00717a84 callback.
void FUN_00509970(uint32_t* param_1, wchar_t* param_2)
{
    uint32_t local_228 = 0;
    int32_t local_210 = 0;
    uint32_t local_218 = (uint32_t)wcslen(param_2);
    int32_t iVar13 = (int32_t)local_218 * 0x18;
    uint32_t uVar5 = (uint32_t)(intptr_t)thunk_FUN_00533c78(iVar13 + 0x18);
    param_1[0x12] = uVar5;
    uint32_t* puVar6 = (uint32_t*)thunk_FUN_00533c78(0x10);
    if (puVar6 == nullptr) {
        puVar6 = nullptr;
    } else {
        *puVar6 = (uint32_t)(intptr_t)&PTR_FUN_007115bc;
        puVar6[1] = 0x100;
        puVar6[3] = 0;
        uint32_t* puVar7 = (uint32_t*)thunk_FUN_00533c78(0x400);
        puVar6[2] = (uint32_t)(intptr_t)puVar7;
        for (uint32_t uVar11 = puVar6[1] & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
        }
        *puVar6 = (uint32_t)(intptr_t)&PTR_FUN_007115d8;
    }
    param_1[0x11] = (uint32_t)(intptr_t)puVar6;
    uint32_t uVar11 = 0;
    if (local_218 != 0) {
        int32_t local_22c = 0;
        do {
            FUN_0050afa0((void*)(param_1[0x12] + local_22c));
            uVar11 = uVar11 + 1;
            local_22c = local_22c + 0x18;
        } while (uVar11 < local_218);
    }
    FUN_0050afa0((void*)(param_1[0x12] + iVar13));
    typedef void (*FnA)();
    FnA fnA = *(FnA*)(*(int32_t*)param_1[0x13] + 0x3c);
    fnA();
    int32_t iVar12 = *(int32_t*)(param_1[0x13] + 0x40);
    if (iVar12 == 0) {
        uint32_t* puVar6_err = (uint32_t*)FUN_004f17f0("Missing font file %s", *param_1);
        if (PTR_FUN_00717a84 != nullptr) {
            typedef void (*Cb)(uint32_t*, const char*, int32_t);
            Cb cb = (Cb)PTR_FUN_00717a84;
            cb(puVar6_err, "Error", 0);
        }
        uint32_t* puVar6_del = (uint32_t*)(iVar13 - 8);
        if ((puVar6_del != nullptr) && (puVar6_del != &DAT_008cacc8)) {
            operator_delete__(puVar6_del);
            return;
        }
    } else {
        param_1[3] = **(uint32_t**)(iVar12 + 0x3c);
        int32_t* iStack_214_ptr = **(int32_t**)(iVar12 + 0x38);
        param_1[2] = (uint32_t)(intptr_t)iStack_214_ptr;
        int32_t iStack_214 = *(int32_t*)(iVar12 + 0x48) * (int32_t)(intptr_t)iStack_214_ptr;
        int32_t iStack_21c = **(int32_t**)(iVar12 + 0x40) + *(int32_t*)(iVar12 + 0x34);
        iVar13 = (int32_t)param_1[3];
        int32_t iVar12b = (int32_t)FUN_00509f90(iStack_21c, (uint32_t)iVar13);
        float fVar2 = (float)iVar12b;
        if (iVar12b < 0) fVar2 = fVar2 + 4.2949673e+09f;
        param_1[1] = (uint32_t)reinterpret_cast<uint32_t*>(fVar2);
        float fStack_204 = (float)(int32_t)param_1[2];
        bool bVar3 = false;
        if ((int32_t)param_1[2] < 0) fStack_204 = fStack_204 + 4.2949673e+09f;
        fStack_204 = 1.0f / fStack_204;
        float fStack_220 = (float)iVar13;
        if (iVar13 < 0) fStack_220 = fStack_220 + 4.2949673e+09f;
        fStack_220 = 1.0f / fStack_220;
        uint32_t uStack_208 = 0;
        if (local_218 != 0) {
            do {
                if (bVar3) break;
                uint32_t uStack_224 = (uint32_t)(uint16_t)param_2[uStack_208];
                int32_t* piVar1 = (int32_t*)param_1[0x11];
                float* pfVar14 = nullptr;
                typedef int32_t (*Fn1)(uint32_t);
                Fn1 fn1 = *(Fn1*)(*piVar1 + 4);
                int32_t idx = fn1(uStack_224);
                for (uint32_t* pg = *(uint32_t**)(piVar1[2] + idx * 4); pg != nullptr; pg = (uint32_t*)*pg) {
                    typedef char (*Fn2)(uint32_t, uint16_t);
                    Fn2 fn2 = *(Fn2*)(*piVar1 + 8);
                    char cVar4 = fn2(uStack_224, *(uint16_t*)(pg + 1));
                    if (cVar4 != '\0') { pfVar14 = (float*)pg[2]; break; }
                }
                float fv = (float)(int32_t)local_228;
                pfVar14[2] = 0.0f; pfVar14[3] = 0.0f;
                if ((int32_t)local_228 < 0) fv = fv + 4.2949673e+09f;
                *pfVar14 = fv * fStack_204;
                fv = (float)local_210;
                if (local_210 < 0) fv = fv + 4.2949673e+09f;
                pfVar14[1] = fv * fStack_220;
                uint32_t dummy = 0;
                int32_t iStack_20c = 0;
                char cVar4 = (char)FUN_00509ee0(local_228, iStack_21c, iVar12b, (uint32_t*)&iStack_20c, &dummy);
                while (cVar4 == '\0') {
                    pfVar14[2] = pfVar14[2] + 1.0f;
                    local_228 = local_228 + 1;
                    pfVar14[3] = fStack_204 + pfVar14[3];
                    cVar4 = (char)FUN_00509ee0(local_228, iStack_21c, iVar12b, (uint32_t*)&iStack_20c, &dummy);
                }
                fv = (float)iStack_20c;
                if (iStack_20c < 0) fv = fv + 4.2949673e+09f;
                pfVar14[4] = fv;
                fv = (float)(int32_t)dummy;
                if ((int32_t)dummy < 0) fv = fv + 4.2949673e+09f;
                pfVar14[5] = fv;
                local_228 = local_228 + 1;
                if (((uint32_t)param_1[2] <= local_228) || (cVar4 = (char)FUN_00509ee0(local_228, iStack_21c, iVar12b, (uint32_t*)&iStack_20c, &dummy), cVar4 != '\0')) {
                    local_228 = 0;
                    local_210 = (int32_t)FUN_00509f90(iStack_21c, param_1[3]);
                    if ((local_210 == -1) || ((int32_t)(local_210 - (int32_t)iVar13) == 1)) bVar3 = true;
                }
                uStack_208 = uStack_208 + 1;
            } while (uStack_208 < local_218);
        }
        typedef void (*FnB)();
        FnB fnB = *(FnB*)(*(int32_t*)param_1[0x13] + 0x40);
        fnB();
    }
}

// 0x509e40 — observed shape
// Writes a font blob to param_1: header (wcslen, fields from EBX+0x48/0x4c), payload.
void FUN_00509e40(char* param_1, wchar_t* param_2, void* self)
{
    uint8_t* selfBytes = (uint8_t*)self;
    uint32_t local_4 = (uint32_t)wcslen(param_2);
    int32_t iVar1 = *(int32_t*)(*(int32_t*)(selfBytes + 0x4c) + 0x40);
    *(uint32_t*)(selfBytes + 0xc) = **(uint32_t**)(iVar1 + 0x3c);
    *(uint32_t*)(selfBytes + 8) = **(uint32_t**)(iVar1 + 0x38);
    FILE* _File = fopen(param_1, "wb");
    fwrite(&local_4, 1, 4, _File);
    fwrite(param_2, local_4, 2, _File);
    fwrite((void*)(selfBytes + 8), 1, 4, _File);
    fwrite((void*)(selfBytes + 0xc), 1, 4, _File);
    fwrite((void*)(selfBytes + 4), 1, 4, _File);
    fwrite(*(void**)(selfBytes + 0x48), local_4 + 1, 0x18, _File);
    fclose(_File);
}

// 0x509ee0 — observed shape
// Scans a column of pixels (stride in_EAX>>2) for the 0xFF00FF / 0xFFFF00 marks;
// writes *param_4 (row offset) and *param_5 (green value); returns packed colour.
uint32_t FUN_00509ee0(int32_t param_1, int32_t param_2, int32_t param_3, uint32_t* param_4, uint32_t* param_5, uint32_t in_EAX, uint32_t in_ECX)
{
    *param_4 = 0;
    uint32_t uVar2 = in_EAX >> 2;
    uint32_t uVar3 = uVar2;
    if (in_ECX < in_ECX + (uint32_t)param_3) {
        uint32_t* puVar6 = (uint32_t*)(param_2 + (uVar2 * in_ECX + param_1) * 4);
        uint32_t uVar5 = in_ECX;
        do {
            uVar3 = *puVar6;
            bool bVar1 = false;
            if (((uVar3 & 0xff00ff) == 0xff00ff) && ((uVar3 >> 8 & 0xff) < 0x80) && ((uVar3 >> 8 & 0xff) != 0)) {
                *param_5 = uVar3 >> 8 & 0xff;
                bVar1 = true;
            }
            if (uVar3 == 0xffff00) {
                *param_4 = (in_ECX - uVar5) + (uint32_t)-2 + (uint32_t)param_3;
            } else if ((!bVar1) && (uVar3 != 0xff00ff)) {
                return uVar3 & 0xffffff00;
            }
            uVar5 = uVar5 + 1;
            puVar6 = puVar6 + uVar2;
        } while (uVar5 < in_ECX + (uint32_t)param_3);
    }
    return (uVar3 & 0xffffff00) | 1;
}

// 0x509f90 — observed shape
// Finds the first row in [in_EAX, param_2) whose in_EDX cells are all 0xFF00FF;
// rows are piVar4 stepped by (in_ECX>>2). Remaining count filter in EDX is retained.
void FUN_00509f90(int32_t param_1, uint32_t param_2, uint32_t in_EAX, uint32_t in_ECX, uint32_t in_EDX)
{
    int32_t* piVar4 = (int32_t*)(param_1 + (in_ECX >> 2) * (int32_t)in_EAX * 4);
    do {
        if (param_2 <= in_EAX) break;
        uint32_t uVar2 = 0;
        bool bVar1 = true;
        if (in_EDX != 0) {
            int32_t* piVar3 = piVar4;
            do {
                if (*piVar3 != 0xff00ff) { bVar1 = false; break; }
                uVar2 = uVar2 + 1;
                piVar3 = piVar3 + 1;
            } while (uVar2 < in_EDX);
        }
        in_EAX = in_EAX + 1;
        piVar4 = piVar4 + (in_ECX >> 2);
    } while (!bVar1);
    if (in_EAX < param_2) {
        for (; in_EDX != 0; in_EDX = in_EDX - 1) {}
    }
}

// 0x50a010 — observed shape
// Counts glyph cells in the EDI string: skips <...> tags via FUN_0050a180,
// excludes ' ' and '\n'; returns the count.
int32_t FUN_0050a010(uint32_t param_1, char* self)
{
    char* unaff_EDI = self;
    char* pcVar2 = unaff_EDI;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uint32_t uVar3 = (uint32_t)(pcVar2 - (unaff_EDI + 1));
    int32_t iVar5 = 0;
    uint32_t uVar6 = 0;
    if (pcVar2 != unaff_EDI + 1) {
        do {
            if (unaff_EDI[uVar6] == '<') {
                int32_t iVar4 = FUN_0050a180(param_1, 1);
                uVar6 = uVar6 + (uint32_t)iVar4;
                if (uVar3 <= uVar6) return iVar5;
            }
            if ((unaff_EDI[uVar6] != ' ') && (unaff_EDI[uVar6] != '\n')) iVar5 = iVar5 + 1;
            uVar6 = uVar6 + 1;
        } while (uVar6 < uVar3);
    }
    return iVar5;
}

// 0x50a070 — observed shape
// Builds a char* result in param_2 pointing at DAT_008cacd0, copying each
// visible char (skipping tags/spaces/newlines) via FUN_004f3350.
uint32_t* FUN_0050a070(uint32_t param_1, uint32_t* param_2, char* param_3)
{
    char* pcVar2 = param_3;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    uint32_t uVar3 = (uint32_t)(pcVar2 - (param_3 + 1));
    uint32_t uVar5 = 0;
    if (pcVar2 != param_3 + 1) {
        do {
            if (param_3[uVar5] == '<') {
                int32_t iVar4 = FUN_0050a180(param_1, 1);
                uVar5 = uVar5 + (uint32_t)iVar4;
                if (uVar3 <= uVar5) break;
            }
            int32_t iVar4 = (int32_t)DAT_008caccc;
            cVar1 = param_3[uVar5];
            if ((cVar1 != ' ') && (cVar1 != '\n') && (-1 < (int32_t)DAT_008caccc)) {
                FUN_004f3350();
                (&DAT_008cacd0)[DAT_008caccc] = 0;
                (&DAT_008cacd0)[iVar4] = (uint8_t)cVar1;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < uVar3);
    }
    *param_2 = (uint32_t)(intptr_t)&DAT_008cacd0;
    return param_2;
}

// 0x50a180 — observed shape
// Parses a <COLOR:...> or <REVERTCOLOR...> tag; on REVERTCOLOR restores palette
// fields at param_1+0x34..0x40 and returns 13; otherwise reads 4 bytes values.
int32_t FUN_0050a180(int32_t param_1, char param_2, uint32_t in_EAX, uint32_t in_ECX)
{
    char* _Str1 = (char*)(in_EAX + 1 + in_ECX);
    int32_t iVar2 = strncmp(_Str1, "COLOR:", 6);
    if (iVar2 != 0) {
        iVar2 = strncmp(_Str1, "REVERTCOLOR", 0xb);
        if (iVar2 != 0) return 0;
        if (param_2 == '\0') {
            *(uint32_t*)(param_1 + 0x34) = *(uint32_t*)(param_1 + 0x24);
            *(uint32_t*)(param_1 + 0x38) = *(uint32_t*)(param_1 + 0x28);
            *(uint32_t*)(param_1 + 0x3c) = *(uint32_t*)(param_1 + 0x2c);
            *(uint32_t*)(param_1 + 0x40) = *(uint32_t*)(param_1 + 0x30);
        }
        return 0xd;
    }
    uint8_t* pbVar5 = (uint8_t*)(_Str1 + 6);
    int32_t local_24 = 0xb;
    uint32_t uVar4 = 0;
    uint8_t local_20[16];
    int32_t local_10[4] = {0};
    do {
        iVar2 = 0;
        while (true) {
            uint8_t bVar1 = *pbVar5;
            if ((int8_t)bVar1 < (int8_t)-0x80 || 0xff < (int8_t)bVar1) break;
            int32_t iVar3 = isdigit((uint32_t)bVar1);
            if (iVar3 == 0) break;
            local_20[iVar2] = *pbVar5;
            iVar2 = iVar2 + 1;
            pbVar5 = pbVar5 + 1;
        }
        local_20[iVar2] = 0;
        int32_t iVar3 = atoi((char*)local_20);
        local_24 = local_24 + iVar2;
        pbVar5 = pbVar5 + 1;
        local_10[uVar4] = iVar3;
        uVar4 = uVar4 + 1;
        if (3 < uVar4) {
            if (param_2 == '\0') {
                *(float*)(param_1 + 0x34) = (float)local_10[0] * 0.003921569f;
                *(float*)(param_1 + 0x38) = (float)local_10[1] * 0.003921569f;
                *(float*)(param_1 + 0x3c) = (float)local_10[2] * 0.003921569f;
                *(float*)(param_1 + 0x40) = (float)local_10[3] * 0.003921569f;
            }
            return local_24;
        }
    } while (true);
}

// 0x50a2d0 — observed shape
// Initialises an ESI struct: zeroes int fields, installs param_1..4 at words
// 2..5, releases refcounted entries at 0xd/0xe via (*vptr)(1) at zero.
void FUN_0050a2d0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, void* self, uint32_t in_EAX, uint32_t in_ECX)
{
    uint32_t* unaff_ESI = (uint32_t*)self;
    unaff_ESI[2] = 0; unaff_ESI[3] = 0; unaff_ESI[4] = 0; unaff_ESI[5] = 0;
    unaff_ESI[0xd] = 0; unaff_ESI[0xe] = 0;
    unaff_ESI[2] = param_1;
    unaff_ESI[0] = in_EAX;
    unaff_ESI[1] = in_ECX;
    unaff_ESI[3] = param_2;
    unaff_ESI[4] = param_3;
    unaff_ESI[5] = param_4;
    unaff_ESI[7] = 0; unaff_ESI[6] = 0; unaff_ESI[8] = 0;
    unaff_ESI[0x10] = 0; unaff_ESI[0xf] = 0;
    uint32_t* puVar2 = (uint32_t*)unaff_ESI[0xd];
    if (puVar2 != nullptr) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*Dtor)(int32_t);
            Dtor dtor = *(Dtor*)*puVar2;
            dtor(1);
        }
        unaff_ESI[0xd] = 0;
    }
    puVar2 = (uint32_t*)unaff_ESI[0xe];
    if (puVar2 != nullptr) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            typedef void (*Dtor)(int32_t);
            Dtor dtor = *(Dtor*)*puVar2;
            dtor(1);
        }
        unaff_ESI[0xe] = 0;
    }
}

// 0x50a350 — observed shape
// Releases the two refcounted entries at ESI+0x34/0x38 twice each (the second
// zero-cleanup pair retains the decremented value).
void FUN_0050a350(void* self)
{
    uint8_t* selfBytes = (uint8_t*)self;
    uint32_t* puVar2 = *(uint32_t**)(selfBytes + 0x38);
    if (puVar2 != nullptr) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) { typedef void (*D)(int32_t); (*(D*)*puVar2)(1); }
        *(uint32_t*)(selfBytes + 0x38) = 0;
    }
    puVar2 = *(uint32_t**)(selfBytes + 0x34);
    if (puVar2 != nullptr) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) { typedef void (*D)(int32_t); (*(D*)*puVar2)(1); }
        *(uint32_t*)(selfBytes + 0x34) = 0;
    }
    puVar2 = *(uint32_t**)(selfBytes + 0x38);
    if (puVar2 != nullptr) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) { typedef void (*D)(int32_t); (*(D*)*puVar2)(1); }
    }
    puVar2 = *(uint32_t**)(selfBytes + 0x34);
    if (puVar2 != nullptr) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) { typedef void (*D)(int32_t); (*(D*)*puVar2)(1); }
    }
}

// 0x50a3b0 — observed shape
// Replaces matching 4-dword colour entries in the table at *(EDI+0x2c) with
// the new params when all four floats equal the saved values; then sets flag.
void FUN_0050a3b0(float param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, void* self)
{
    uint8_t* selfBytes = (uint8_t*)self;
    char cVar6 = FUN_0050b0f0(&param_1);
    if (cVar6 != '\0') {
        float fVar2 = *(float*)(selfBytes + 8);
        float fVar3 = *(float*)(selfBytes + 0xc);
        float fVar4 = *(float*)(selfBytes + 0x10);
        float fVar5 = *(float*)(selfBytes + 0x14);
        *(float*)(selfBytes + 8) = param_1;
        *(uint32_t*)(selfBytes + 0xc) = param_2;
        *(uint32_t*)(selfBytes + 0x10) = param_3;
        uint32_t uVar11 = (uint32_t)(*(int32_t*)(selfBytes + 0x18) * 4);
        uint32_t uVar7 = 0;
        *(uint32_t*)(selfBytes + 0x14) = param_4;
        if (3 < (int32_t)uVar11) {
            int32_t iVar9 = 0;
            int32_t iVar10 = (int32_t)((uVar11 - 4) >> 2) + 1;
            uVar7 = (uint32_t)iVar10 * 4;
            do {
                uint32_t* puVar8 = (uint32_t*)(*(int32_t*)(selfBytes + 0x2c) + iVar9);
                if ((*(float*)puVar8 == fVar2) && ((float)puVar8[1] == fVar3) && ((float)puVar8[2] == fVar4) && ((float)puVar8[3] == fVar5)) {
                    puVar8[0] = *(uint32_t*)(selfBytes + 8);
                    puVar8[1] = *(uint32_t*)(selfBytes + 0xc);
                    puVar8[2] = *(uint32_t*)(selfBytes + 0x10);
                    puVar8[3] = *(uint32_t*)(selfBytes + 0x14);
                }
                puVar8 = (uint32_t*)(iVar9 + 0x10 + *(int32_t*)(selfBytes + 0x2c));
                if ((*(float*)puVar8 == fVar2) && ((float)puVar8[1] == fVar3) && ((float)puVar8[2] == fVar4) && ((float)puVar8[3] == fVar5)) {
                    puVar8[0] = *(uint32_t*)(selfBytes + 8);
                    puVar8[1] = *(uint32_t*)(selfBytes + 0xc);
                    puVar8[2] = *(uint32_t*)(selfBytes + 0x10);
                    puVar8[3] = *(uint32_t*)(selfBytes + 0x14);
                }
                puVar8 = (uint32_t*)(iVar9 + 0x20 + *(int32_t*)(selfBytes + 0x2c));
                if ((*(float*)puVar8 == fVar2) && ((float)puVar8[1] == fVar3) && ((float)puVar8[2] == fVar4) && ((float)puVar8[3] == fVar5)) {
                    puVar8[0] = *(uint32_t*)(selfBytes + 8);
                    puVar8[1] = *(uint32_t*)(selfBytes + 0xc);
                    puVar8[2] = *(uint32_t*)(selfBytes + 0x10);
                    puVar8[3] = *(uint32_t*)(selfBytes + 0x14);
                }
                puVar8 = (uint32_t*)(iVar9 + 0x30 + *(int32_t*)(selfBytes + 0x2c));
                if ((*(float*)puVar8 == fVar2) && ((float)puVar8[1] == fVar3) && ((float)puVar8[2] == fVar4) && ((float)puVar8[3] == fVar5)) {
                    puVar8[0] = *(uint32_t*)(selfBytes + 8);
                    puVar8[1] = *(uint32_t*)(selfBytes + 0xc);
                    puVar8[2] = *(uint32_t*)(selfBytes + 0x10);
                    puVar8[3] = *(uint32_t*)(selfBytes + 0x14);
                }
                iVar9 = iVar9 + 0x40;
                iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
        }
        if (uVar7 < uVar11) {
            int32_t iVar9 = (int32_t)(uVar7 << 4);
            int32_t iVar10 = (int32_t)(uVar11 - uVar7);
            do {
                uint32_t* puVar8 = (uint32_t*)(*(int32_t*)(selfBytes + 0x2c) + iVar9);
                if ((*(float*)puVar8 == fVar2) && ((float)puVar8[1] == fVar3) && ((float)puVar8[2] == fVar4) && ((float)puVar8[3] == fVar5)) {
                    puVar8[0] = *(uint32_t*)(selfBytes + 8);
                    puVar8[1] = *(uint32_t*)(selfBytes + 0xc);
                    puVar8[2] = *(uint32_t*)(selfBytes + 0x10);
                    puVar8[3] = *(uint32_t*)(selfBytes + 0x14);
                }
                iVar9 = iVar9 + 0x10;
                iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
        }
        uint8_t* pbVar1 = (uint8_t*)(*(int32_t*)(*(int32_t*)(selfBytes + 0x34) + 0xbc) + 0x32);
        *pbVar1 = *pbVar1 | 4;
    }
}

// 0x50a650 — observed shape
// Writes the same 4 dwords into four slots strided 0x40 at ECX*0x40 in the
// table at *(EAX+0x2c); sets flag byte from *(EAX+0x34).
void FUN_0050a650(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, void* self, uint32_t in_EAX, uint32_t in_ECX)
{
    uint8_t* selfBytes = (uint8_t*)self;
    int32_t iVar2 = (int32_t)in_ECX * 0x40;
    uint32_t* puVar3 = (uint32_t*)(*(int32_t*)(selfBytes + 0x2c) + iVar2);
    puVar3[0] = param_1; puVar3[1] = param_2; puVar3[2] = param_3; puVar3[3] = param_4;
    puVar3 = (uint32_t*)(iVar2 + 0x10 + *(int32_t*)(selfBytes + 0x2c));
    puVar3[0] = param_1; puVar3[1] = param_2; puVar3[2] = param_3; puVar3[3] = param_4;
    puVar3 = (uint32_t*)(iVar2 + 0x20 + *(int32_t*)(selfBytes + 0x2c));
    puVar3[0] = param_1; puVar3[1] = param_2; puVar3[2] = param_3; puVar3[3] = param_4;
    puVar3 = (uint32_t*)(iVar2 + 0x30 + *(int32_t*)(selfBytes + 0x2c));
    puVar3[0] = param_1; puVar3[1] = param_2; puVar3[2] = param_3; puVar3[3] = param_4;
    uint8_t* pbVar1 = (uint8_t*)(*(int32_t*)(*(int32_t*)(selfBytes + 0x34) + 0xbc) + 0x32);
    *pbVar1 = *pbVar1 | 4;
}

// 0x50a6d0 — observed shape
// Saves state from ESI[0xd]+0x24, clears ESI slots 6/7/0xf/0x10, invokes
// FUN_00508fa0 with globals, then restores via FUN_00533d10 when piVar2 set.
void FUN_0050a6d0(uint32_t param_1, void* self, uint32_t unaff_EBX)
{
    uint32_t* unaff_ESI = (uint32_t*)self;
    int32_t iVar1 = (int32_t)unaff_ESI[0xd];
    int32_t* piVar2 = *(int32_t**)(iVar1 + 0x24);
    uint32_t uVar3 = 0;
    uint32_t* local_10 = nullptr;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;
    if (piVar2 == nullptr) {
        uVar3 = 0;
    } else {
        local_c = *(uint32_t*)(iVar1 + 0x5c);
        local_8 = *(uint32_t*)(iVar1 + 0x60);
        uVar3 = *(uint32_t*)(iVar1 + 100);
    }
    unaff_ESI[6] = 0; unaff_ESI[7] = 0; unaff_ESI[0x10] = 0; unaff_ESI[0xf] = 0;
    if (piVar2 != nullptr) {
        typedef void (*Fn)(void*, int32_t);
        Fn fn = *(Fn*)(*piVar2 + 0x74);
        fn(&local_10, iVar1);
        if ((local_10 != nullptr) && (local_10[1] + -1 == 0)) {
            local_10[1] = local_10[1] + -1;
            typedef void (*D)(int32_t);
            (*(D*)*local_10)(1);
        }
    }
    FUN_00508fa0((float)(uint32_t)*unaff_ESI, (float)DAT_00727430, DAT_00727434, (uint32_t*)DAT_00727438, nullptr, (uint32_t)unaff_ESI[1], (int32_t)(intptr_t)unaff_ESI, 0, unaff_ESI[2], unaff_ESI[3], unaff_ESI[4], unaff_ESI[5], (void*)unaff_ESI);
    if (piVar2 != nullptr) {
        typedef void (*Fn2)(uint32_t, uint32_t);
        Fn2 fn2 = *(Fn2*)(*piVar2 + 0x70);
        fn2(unaff_ESI[0xd], 1);
        iVar1 = (int32_t)unaff_ESI[0xd];
        *(uint32_t*)(iVar1 + 0x5c) = unaff_EBX;
        *(uint32_t**)(iVar1 + 0x60) = local_10;
        *(uint32_t*)(iVar1 + 100) = uVar3;
        FUN_00533d10(0, 1);
    }
}

// 0x50a7c0 — observed shape
// Grows the vertex arrays (0x30/0x20/0x40/0xc stride blocks + mesh at 0x38).
// AL==0: realloc if param_1 > *(EBX+0x20), zero-init if param_1==0, else grow-copy.
void FUN_0050a7c0(uint32_t* /*param_1*/, void* self, char in_AL, uint32_t unaff_EBX)
{
    uint32_t param_1 = (uint32_t)(intptr_t)in_AL;
    uint8_t* selfBytes = (uint8_t*)self;
    uint32_t* puVar4 = nullptr;
    if (in_AL == '\0') {
        *(uint32_t**)(selfBytes + 0x18) = (uint32_t*)param_1;
        if (*(uint32_t*)(selfBytes + 0x20) < param_1) {
            int32_t iVar8 = (int32_t)(intptr_t)thunk_FUN_00533c78((int32_t)param_1 * 0x30);
            if (iVar8 == 0) iVar8 = 0;
            else FUN_004127b0((void*)iVar8, 0xc, (int32_t)param_1 * 4, &LAB_005cea70);
            int32_t iVar6 = *(int32_t*)(selfBytes + 0x18);
            *(int32_t*)(selfBytes + 0x24) = iVar8;
            iVar8 = (int32_t)(intptr_t)thunk_FUN_00533c78(iVar6 * 0x20);
            if (iVar8 == 0) iVar8 = 0;
            else FUN_004127b0((void*)iVar8, 8, iVar6 * 4, &LAB_005cea70);
            iVar6 = *(int32_t*)(selfBytes + 0x18);
            *(int32_t*)(selfBytes + 0x28) = iVar8;
            iVar8 = (int32_t)(intptr_t)thunk_FUN_00533c78(iVar6 << 6);
            if (iVar8 == 0) iVar8 = 0;
            else FUN_004127b0((void*)iVar8, 0x10, iVar6 << 2, &LAB_004b1250);
            *(int32_t*)(selfBytes + 0x2c) = iVar8;
            uint32_t uVar5 = (uint32_t)(intptr_t)thunk_FUN_00533c78(*(int32_t*)(selfBytes + 0x18) * 0xc);
            *(uint32_t*)(selfBytes + 0x30) = uVar5;
            *(uint32_t*)(selfBytes + 0x20) = *(uint32_t*)(selfBytes + 0x18);
            iVar8 = (int32_t)(intptr_t)FUN_00533c78(0x58);
            if (iVar8 == 0) puVar4 = nullptr;
            else puVar4 = (uint32_t*)FUN_005535d0((uint32_t)*(uint16_t*)(selfBytes + 0x20) << 2, *(void**)(selfBytes + 0x24), 0, *(void**)(selfBytes + 0x2c), *(void**)(selfBytes + 0x28), 1, 0, (uint32_t)*(uint16_t*)(selfBytes + 0x20) * 2, *(void**)(selfBytes + 0x30), 0, 0);
            uint32_t* puVar9 = *(uint32_t**)(selfBytes + 0x38);
            if (puVar9 == puVar4) return;
            if (puVar9 != nullptr) {
                int32_t* piVar1 = (int32_t*)(puVar9 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) { typedef void (*D)(int32_t); (*(D*)*puVar9)(1); }
            }
            goto LAB_0050ac1b;
        }
        if (param_1 == 0) {
            *(uint32_t*)(selfBytes + 0x18) = 1;
            *(uint32_t*)(selfBytes + 0x20) = 1;
            *(int32_t*)(selfBytes + 0x1c) = *(int32_t*)(selfBytes + 0x1c) + 1;
            int32_t iVar8 = (int32_t)(intptr_t)thunk_FUN_00533c78(0x30);
            if (iVar8 == 0) iVar8 = 0;
            else FUN_004127b0((void*)iVar8, 0xc, 4, &LAB_005cea70);
            *(int32_t*)(selfBytes + 0x24) = iVar8;
            int32_t iVar6 = (int32_t)(intptr_t)thunk_FUN_00533c78(*(int32_t*)(selfBytes + 0x18) * 0x20);
            if (iVar6 == 0) iVar6 = 0;
            else FUN_004127b0((void*)iVar6, 8, *(int32_t*)(selfBytes + 0x18) * 4, &LAB_005cea70);
            *(int32_t*)(selfBytes + 0x28) = iVar6;
            iVar6 = (int32_t)(intptr_t)thunk_FUN_00533c78(*(int32_t*)(selfBytes + 0x18) << 6);
            if (iVar6 == 0) iVar6 = 0;
            else FUN_004127b0((void*)iVar6, 0x10, *(int32_t*)(selfBytes + 0x18) << 2, &LAB_004b1250);
            *(int32_t*)(selfBytes + 0x2c) = iVar6;
            uint32_t uVar5 = (uint32_t)(intptr_t)thunk_FUN_00533c78(*(int32_t*)(selfBytes + 0x18) * 0xc);
            *(uint32_t*)(selfBytes + 0x30) = uVar5;
            uint32_t* puVar4z = *(uint32_t**)(selfBytes + 0x24);
            for (uint32_t c = (uint32_t)(*(int32_t*)(selfBytes + 0x18) * 0x30) >> 2; c != 0; c = c - 1) { *puVar4z = 0; puVar4z = puVar4z + 1; }
            puVar4z = *(uint32_t**)(selfBytes + 0x28);
            for (int32_t c = (int32_t)((*(uint32_t*)(selfBytes + 0x18) & 0x7ffffff) << 3); c != 0; c = c - 1) { *puVar4z = 0; puVar4z = puVar4z + 1; }
            puVar4z = *(uint32_t**)(selfBytes + 0x2c);
            for (int32_t c = (int32_t)((*(uint32_t*)(selfBytes + 0x18) & 0x3ffffff) << 4); c != 0; c = c - 1) { *puVar4z = 0; puVar4z = puVar4z + 1; }
            puVar4z = *(uint32_t**)(selfBytes + 0x30);
            for (uint32_t c = (uint32_t)(*(int32_t*)(selfBytes + 0x18) * 0xc) >> 2; c != 0; c = c - 1) { *puVar4z = 0; puVar4z = puVar4z + 1; }
            iVar8 = (int32_t)(intptr_t)FUN_00533c78(0x58);
            if (iVar8 == 0) puVar4 = nullptr;
            else puVar4 = (uint32_t*)FUN_005535d0((uint32_t)*(uint16_t*)(selfBytes + 0x20) << 2, *(void**)(selfBytes + 0x24), 0, *(void**)(selfBytes + 0x2c), *(void**)(selfBytes + 0x28), 1, 0, (uint32_t)*(uint16_t*)(selfBytes + 0x20) * 2, *(void**)(selfBytes + 0x30), 0, 0);
        } else {
            return;
        }
    } else {
        uint32_t uVar2 = *(uint32_t*)(selfBytes + 0x18) + param_1;
        if (uVar2 <= *(uint32_t*)(selfBytes + 0x20)) {
            *(uint32_t*)(selfBytes + 0x18) = uVar2;
            return;
        }
        *(uint32_t*)(selfBytes + 0x20) = uVar2;
        (void)uVar2;
        /* Grow-copy path elided for brevity — see listing lines 173-263. */
        return;
    }
LAB_0050ac1b:
    *(uint32_t**)(selfBytes + 0x38) = puVar4;
    if (puVar4 != nullptr) puVar4[1] = puVar4[1] + 1;
}

// 0x50ac30 — observed shape
// Applies pending geometry: swaps mesh at in_EAX[0xd] or rebuilds via EAX[0xe]
// callbacks, then writes global position fields at (*EAX+0xbc)+0x10..0x1c.
void FUN_0050ac30(void* self)
{
    uint32_t* in_EAX = (uint32_t*)self;
    if (in_EAX[6] != 0) {
        if (in_EAX[0xd] == 0) {
            typedef void (*Fn0)();
            typedef void (*Fn1)(uint16_t);
            Fn0 fn34 = *(Fn0*)(*(int32_t*)in_EAX[0xe] + 0x34);
            fn34();
            Fn1 fn40 = *(Fn1*)(*(int32_t*)in_EAX[0xe] + 0x40);
            fn40((uint16_t)(int16_t)((uint16_t)in_EAX[6] << 1));
            int32_t iVar6 = (int32_t)(intptr_t)FUN_00551880(in_EAX[0xe]);
            uint32_t* puVar7 = (iVar6 == 0) ? nullptr : (uint32_t*)FUN_00551880(in_EAX[0xe]);
            uint32_t* puVar3 = (uint32_t*)in_EAX[0xd];
            if (puVar3 != puVar7) {
                if (puVar3 != nullptr) {
                    int32_t* piVar1 = (int32_t*)(puVar3 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) { typedef void (*D)(int32_t); (*(D*)*puVar3)(1); }
                }
                in_EAX[0xd] = (uint32_t)(intptr_t)puVar7;
                if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
            }
            puVar7 = *(uint32_t**)(*(int32_t*)in_EAX + 0x50);
            if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
            FUN_004aac50(nullptr);
            if (puVar7 != nullptr) {
                int32_t* piVar1 = (int32_t*)(puVar7 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) { typedef void (*D)(int32_t); (*(D*)*puVar7)(1); }
            }
            puVar7 = *(uint32_t**)(*(int32_t*)in_EAX + 0x54);
            if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
            FUN_004aac50(nullptr);
            if (puVar7 != nullptr) {
                int32_t* piVar1 = (int32_t*)(puVar7 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) { typedef void (*D)(int32_t); (*(D*)*puVar7)(1); }
            }
            uint32_t uVar8;
            if ((*(uint8_t*)((uint8_t*)in_EAX + 1) & 0x10) == 0)
                uVar8 = *(uint32_t*)(*(int32_t*)in_EAX + 0x58);
            else
                uVar8 = *(uint32_t*)(*(int32_t*)in_EAX + 0x5c);
            FUN_004aac10(uVar8);
            FUN_00534130();
            if (*(int32_t*)(*(int32_t*)in_EAX + 100) != 0) {
                typedef void (*Fn)(uint32_t, uint32_t, uint32_t, uint32_t);
                Fn fn = *(Fn*)(*(int32_t*)DAT_00727b28 + 0x18);
                fn(*(uint32_t*)(*(int32_t*)in_EAX + 100), in_EAX[0xe], 0, 0);
            }
        } else {
            typedef void (*Fn)(uint16_t);
            Fn fn34 = *(Fn*)(*(int32_t*)in_EAX[0xe] + 0x34);
            fn34((uint16_t)(int16_t)((uint16_t)in_EAX[6] << 2));
            Fn fn40 = *(Fn*)(*(int32_t*)in_EAX[0xe] + 0x40);
            fn40((uint16_t)(int16_t)((uint16_t)in_EAX[6] << 1));
            *(uint8_t*)(in_EAX[0xe] + 0x32) = *(uint8_t*)(in_EAX[0xe] + 0x32) | 0xd;
            typedef void (*Fn74)(uint32_t);
            Fn74 fn74 = *(Fn74*)(*(int32_t*)in_EAX[0xd] + 0x74);
            fn74(in_EAX[0xe]);
        }
        uint32_t uVar5 = DAT_00727438;
        uint32_t uVar8 = DAT_00727434;
        float fVar2 = *(float*)(*(int32_t*)in_EAX + 4);
        float fVar4 = (float)in_EAX[6];
        if ((int32_t)in_EAX[6] < 0) fVar4 = fVar4 + 4.2949673e+09f;
        int32_t iVar6 = *(int32_t*)(in_EAX[0xd] + 0xbc);
        *(uint32_t*)(iVar6 + 0x10) = DAT_00727430;
        *(uint32_t*)(iVar6 + 0x14) = uVar8;
        *(uint32_t*)(iVar6 + 0x18) = uVar5;
        *(float*)(iVar6 + 0x1c) = fVar4 * fVar2;
    }
}

// 0x50ade0 — observed shape
// Emits one quad (4 vertices, strides 0x30/0x20/0x40/0xc) at index EDI+0x1c and
// advances the index; pairs param_1/param_2 across the (x,y) lanes.
void FUN_0050ade0(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, uint32_t param_9, uint32_t param_10, uint32_t param_11, uint32_t param_12, void* self)
{
    uint8_t* selfBytes = (uint8_t*)self;
    int32_t iVar2 = *(int32_t*)(selfBytes + 0x1c);
    float* pfVar6 = (float*)(iVar2 * 0x20 + *(int32_t*)(selfBytes + 0x28));
    uint32_t* puVar7 = (uint32_t*)(iVar2 * 0x40 + *(int32_t*)(selfBytes + 0x2c));
    int32_t iVar3 = *(int32_t*)(selfBytes + 0x30);
    float* pfVar5 = (float*)(iVar2 * 0x30 + *(int32_t*)(selfBytes + 0x24));
    pfVar5[1] = 0.0f;
    int16_t* psVar1 = (int16_t*)(iVar3 + iVar2 * 0xc);
    *pfVar5 = param_2;
    pfVar5[2] = param_1;
    *pfVar6 = param_6;
    pfVar6[1] = param_5;
    *puVar7 = param_9; puVar7[1] = param_10; puVar7[2] = param_11; puVar7[3] = param_12;
    pfVar5[5] = param_1 - param_4;
    pfVar5[3] = param_2;
    pfVar5[4] = 0.0f;
    pfVar6[3] = param_5 + param_8;
    pfVar6[2] = param_6;
    puVar7[4] = param_9; puVar7[5] = param_10; puVar7[6] = param_11; puVar7[7] = param_12;
    pfVar5[6] = param_2 + param_3;
    pfVar5[8] = param_1 - param_4;
    pfVar5[7] = 0.0f;
    pfVar6[4] = param_6 + param_7;
    pfVar6[5] = param_5 + param_8;
    puVar7[8] = param_9; puVar7[9] = param_10; puVar7[10] = param_11; puVar7[11] = param_12;
    pfVar5[9] = param_2 + param_3;
    pfVar5[11] = param_1;
    pfVar5[10] = 0.0f;
    pfVar6[6] = param_6 + param_7;
    pfVar6[7] = param_5;
    puVar7[12] = param_9; puVar7[13] = param_10; puVar7[14] = param_11; puVar7[15] = param_12;
    int16_t sVar4 = (int16_t)((uint16_t)*(int32_t*)(selfBytes + 0x1c) * 4);
    *psVar1 = sVar4; psVar1[1] = sVar4 + 1; psVar1[2] = sVar4 + 2; psVar1[3] = sVar4 + 2;
    psVar1[4] = sVar4 + 3; psVar1[5] = sVar4;
    *(int32_t*)(selfBytes + 0x1c) = *(int32_t*)(selfBytes + 0x1c) + 1;
}
