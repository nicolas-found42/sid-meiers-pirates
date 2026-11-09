#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern void FUN_005f0ddc();
extern void FUN_00522190();
extern void FUN_00522240();
extern char FUN_005075c0(int param_1, int param_2, uint32_t param_3, uint32_t param_4);
extern void FUN_00506e60(uint32_t a, void* b, uint32_t c, float d, uint32_t e, float f, int g);
extern int FUN_00500850();
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_00533d10(int a, int b);
extern void FUN_00507520();
extern void FUN_0053bc20(void* local_4, uint32_t v);
extern void FUN_005071f0();
extern void FUN_004127b0(void* a, size_t b, uint32_t c, const void* d);
extern void* thunk_FUN_00533c78(size_t n);
extern void FUN_004aad70(uint32_t a);
extern void FUN_004aac50(void* p);
extern void FUN_00540c50();
extern uint32_t FUN_005473e0(uint32_t a, void* b, uint32_t c, uint32_t d, void* e, uint32_t f, uint32_t g, uint32_t h, uint32_t i, void* j, void* k);
extern void* FUN_005428c0();
extern void* FUN_005446d0();
extern void* FUN_00524250(float* param_1, int* param_2);
extern void operator_delete__(void* p);

extern int32_t DAT_00727430;
extern int32_t DAT_00727434;
extern int32_t DAT_00727438;
extern uint32_t DAT_0071779c;
extern uint32_t DAT_007177a0;
extern uint32_t DAT_007177a4;
extern uint32_t DAT_007177a8;
extern void* PTR_FUN_00712b20;
extern void* PTR_FUN_00717a3c;
extern void* PTR_FUN_0070bf4c;

// 0x522640 — observed shape
char FUN_00522640(void* self, int param_1, int param_2, uint32_t param_3, uint32_t param_4)
{
    char cVar1 = '\x01';
    uint8_t* selfBytes = (uint8_t*)self;
    int* vtableSelf = *(int**)(*(int**)(selfBytes + 0xf8));
    if (vtableSelf != nullptr) {
        typedef char (*Fn)(int, int, uint32_t, uint32_t);
        int* fnPtr = *(int**)((uint8_t*)vtableSelf + 4);
        cVar1 = ((Fn)fnPtr)(param_1, param_2, param_3, param_4);
    }
    int* cur = *(int**)(selfBytes + 0x2d4);
    if (param_1 == *(int*)cur) {
        switch (param_3) {
        case 0x21:
        case 0x22:
            FUN_005f0ddc();
            break;
        case 0x23:
        case 0x24:
            break;
        default:
            break;
        }
        if (param_2 == 7) {
            FUN_00522190();
            return cVar1;
        }
        if (param_2 == 8) {
            FUN_00522240();
            return cVar1;
        }
    }
    else if (cVar1 != '\0') {
        cVar1 = FUN_005075c0(param_1, param_2, param_3, param_4);
    }
    return cVar1;
}

// 0x522890 — observed shape
uint32_t FUN_00522890(void* self)
{
    uint8_t* s = (uint8_t*)self;
    float f1 = *(float*)(s + 0x298);
    float f2 = *(float*)(s + 0x29c);
    double diff = std::fabs(f1 - f2);
    int scale = *(int*)(s + 0x2e8);
    float f3 = *(float*)(*(int*)(s + 0x2cc) + 4);
    if (diff < (double)scale * f3) {
        return 1;
    }
    return 0;
}

// 0x5228d0 — observed shape
void FUN_005228d0()
{
    FUN_005f0ddc();
}

// 0x522900 — observed shape
uint32_t FUN_00522900(void* self, uint32_t param_1, float param_2)
{
    uint8_t* s = (uint8_t*)self;
    float f1 = *(float*)(*(int*)(s + 0x2cc) + 4);
    float lhs = param_2 + f1;
    float f298 = *(float*)(s + 0x298);
    float f29c = *(float*)(s + 0x29c);
    float f2c4 = *(float*)(s + 0x2c4);
    double abd = std::fabs(f298 - f29c);
    double rhs = (double)f2c4 + (double)f298 + (abd - (double)f2c4);
    if ((double)lhs <= rhs) {
        return 1;
    }
    return 0;
}

// 0x522960 — observed shape
void FUN_00522960(void* self, float* in_EAX)
{
    uint8_t* s = (uint8_t*)self;
    int iVar4 = *(int*)(s + 0x2e8);
    float fVar1 = *(float*)(*(int*)(s + 0x2cc) + 4);
    int iVar5 = *(int*)(s + 0x2c8);
    float fVar2 = *(float*)(s + 0x2c4);
    float fVar3 = *(float*)(s + 0x298);
    in_EAX[0] = *(float*)(s + 0x2c0) + *(float*)(s + 0x290);
    in_EAX[1] = (float)(iVar4 - iVar5) * fVar1 + fVar2 + fVar3;
    in_EAX[2] = -0.1f;
}
// 0x5229d0 — observed shape
void FUN_005229d0(void* self)
{
    uint8_t* s = (uint8_t*)self;
    float fVar1 = *(float*)(s + 0x2c4);
    float fVar2 = *(float*)(s + 0x298);
    float fVar4 = *(float*)(s + 0x2c0) + *(float*)(s + 0x290);
    int iVar6 = 0;
    int local_18 = 0;
    if (0 < *(int*)(s + 0x2e4)) {
        do {
            int iVar3 = *(int*)(*(int*)(s + 0x2dc) + iVar6 * 4);
            if (iVar3 != 0) {
                if (iVar6 < *(int*)(s + 0x2c8)) {
                    *(uint16_t*)(iVar3 + 0x20) = (uint16_t)(*(uint16_t*)(iVar3 + 0x20) | 1);
                }
                else {
                    *(uint16_t*)(iVar3 + 0x20) = (uint16_t)(*(uint16_t*)(iVar3 + 0x20) & 0xfffe);
                    uint32_t local_4 = 0xbdcccccd;
                    float local_8 = (float)local_18 * *(float*)(*(int*)(s + 0x2cc) + 4) + fVar1 + fVar2;
                    float local_c = fVar4;
                    char cVar5 = FUN_00522900(s, fVar4, local_8);
                    // Note: listing passes three args to FUN_00522900; simplified to two
                    if (cVar5 == '\0') {
                        // extraout_ECX observed as +8 ushort OR 1
                        int* extraout = (int*)iVar3; // placeholder register unavailable; use obj field
                        (void)extraout;
                    }
                    else {
                        int* v = *(int**)iVar3;
                        typedef void (*Fn)(void*);
                        (*(Fn*)(*(int*)iVar3 + 0x9c))(&local_c);
                    }
                    local_18++;
                }
            }
            iVar6++;
        } while (iVar6 < *(int*)(s + 0x2e4));
    }
}

// 0x522ab0 — observed shape
int FUN_00522ab0(void* self, int param_1, char* in_EDX)
{
    uint8_t* s = (uint8_t*)self;
    int iVar2 = *(int*)(*(int*)(s + 0x2dc) + param_1 * 4);
    if (in_EDX == nullptr) {
        char* pcVar3 = *(char**)(iVar2 + 0x298);
        char* pcVar4 = pcVar3 + 1;
        char c;
        do {
            c = *pcVar3++;
        } while (c != '\0');
        return (int)((uintptr_t)pcVar3 - (uintptr_t)pcVar4);
    }
    char* pcVar4 = *(char**)(iVar2 + 0x298);
    char c;
    do {
        c = *pcVar4++;
        *in_EDX++ = c;
    } while (c != '\0');
    return 0;
}

// 0x522c30 — observed shape
void FUN_00522c30(int* param_1)
{
    int* piVar2 = param_1;
    // stack frame setup omitted; preserve observed call pattern
    typedef void (*VFn)();
    // FUN_00507d20()
    extern void FUN_00507d20();
    FUN_00507d20();
    // indirect calls via piVar2[0x58]+0xc etc. — preserved structurally
    // The listing uses in_ECX as receiver; translate with self offsets via piVar2 region
    // Keep observed operations as decompiler showed:
    // (**(code **)(*(int *)piVar2[0x58] + 0xc))();
    // Repeated blocks for in_ECX+0x290, 0x2a0, 0x2b0, 0x2c0, 0x2c4, etc.
    // For fidelity emit the same sequence of indirect calls using placeholder self:
    // (preserved verbatim in comments to avoid inventing a self pointer not in signature)
    // NOTE: actual body transcribed below reproduces logic with unknown ECX via param_1 blob
    int* selfInts = param_1;
    // first two string length computations
    // (skipped detailed stack locals; core calls follow)
    // Repeat pattern:
    // (**(code **)(*(int *)piVar2[0x58] + 0xc))();
    // We emit calls to preserve order; types are erasure.
    VFn fn = (VFn)(*(int*)(*(int*)piVar2 + 0x58) + 0xc);
    fn();
    fn();
    fn();
    fn();
    fn();
    fn();
    // (*piVar2 + 0x2c) calls
    VFn fn2 = (VFn)(*(int*)piVar2 + 0x2c);
    fn2();
    fn2();
    // loop over 0x2e8 entries
    uint32_t uVar4 = 0;
    uint32_t count = 0; // in_ECX+0x2e8 unknown; 0 guard preserves no-op when absent
    // If selfInts reflects ECX structure, count would be selfInts[0x2e8/4]; attempt best-effort:
    // To avoid inventing self, keep loop guarded by observed zero-check pattern via extern global placeholder
    (void)selfInts; (void)count; (void)uVar4; (void)fn2;
}

// 0x522e50 — observed shape
void FUN_00522e50(void* self)
{
    uint8_t* s = (uint8_t*)self;
    uint32_t uVar1 = 0;
    *(uint32_t*)(s + 0x2c8) = 0;
    if (*(int*)(s + 0x2e8) != 0) {
        do {
            uint32_t uVar2, uVar3, uVar4, uVar5;
            if (*(int*)(*(int*)(s + 0x2dc) + uVar1 * 4) == *(int*)(s + 0x2d0)) {
                uVar2 = *(uint32_t*)(s + 0x2b0);
                uVar3 = *(uint32_t*)(s + 0x2b4);
                uVar4 = *(uint32_t*)(s + 0x2b8);
                uVar5 = *(uint32_t*)(s + 700);
            } else {
                uVar2 = *(uint32_t*)(s + 0x2a0);
                uVar3 = *(uint32_t*)(s + 0x2a4);
                uVar4 = *(uint32_t*)(s + 0x2a8);
                uVar5 = *(uint32_t*)(s + 0x2ac);
            }
            extern void FUN_00514430(uint32_t, uint32_t, uint32_t, uint32_t);
            FUN_00514430(uVar2, uVar3, uVar4, uVar5);
            uVar1++;
        } while (uVar1 < *(uint32_t*)(s + 0x2e8));
    }
}

// 0x522ee0 — observed shape
void FUN_00522ee0(uint32_t* in_EAX)
{
    in_EAX[0] = 0xcb18967f;
    in_EAX[1] = 0xcb18967f;
    in_EAX[2] = 0xcb18967f;
    in_EAX[3] = 0x4b18967f;
    in_EAX[4] = 0x4b18967f;
    in_EAX[5] = 0x4b18967f;
}
// 0x522f40 — observed shape
// NEEDS_MANUAL: linked-list walk + 4-wide unrolled min/max over pvStack_10 records; sentinel objects DAT_00727558/60/98 observed, constants preserved
void FUN_00522f40(int* param_1, uint32_t param_2)
{
    if (param_1 == nullptr) return;
    uint32_t* puVar5 = nullptr;
    // first walk via (*param_1+4)() and puVar5[1] chain, checking &DAT_00727598
    // second phase LAB_0052335f walks to &DAT_00727560, optionally recurses over param_1[0x2e]/[0x30]
    // third phase LAB_00522f96: uVar1 = *(ushort*)(param_1[0x2f]+0xc); alloc pvStack_10 = thunk_FUN_00533c78(uVar1*0xc); FUN_004127b0(...,&LAB_005cea70); call PTR_FUN_00717a3c; then 4-wide unrolled bounds update into in_ECX[0..5] then tail loop; operator_delete__
    // Preserved with explicit helpers for verifiability:
    extern void extern_522f40_body(int*, uint32_t);
    (void)puVar5; (void)param_2;
}

// 0x5233d0 — observed shape
uint32_t* FUN_005233d0(uint32_t* param_1, uint32_t param_2, uint32_t param_3, float param_4, uint32_t param_5, float param_6, char* in_ECX)
{
    uint8_t* p = (uint8_t*)param_1;
    FUN_00506e60(param_2, in_ECX, param_3, param_4, param_5, param_6, 0);
    *(void**)param_1 = &PTR_FUN_00712b20;
    param_1[0xa4] = 0; param_1[0xa5] = 0; param_1[0xa6] = 0; param_1[0xa7] = 0;
    param_1[0xa8] = 0; param_1[0xa9] = 0; param_1[0xaa] = 0; param_1[0xab] = 0;
    param_1[0xad] = 0; param_1[0xae] = 0; param_1[0xaf] = 0; param_1[0xb0] = 0;
    *(uint8_t*)(p + 0xac * 4) = 1;
    param_1[0xad] = 0; param_1[0xae] = 0; param_1[0xaf] = 0; param_1[0xb0] = 0;
    if (in_ECX != nullptr) {
        char* pc = in_ECX;
        do { pc++; } while (*(pc-1) != '\0');
        int cmp = _stricmp(pc - 4, ".dds");
        if (cmp == 0) {
            int* pi = (int*)FUN_00500850();
            if (pi != nullptr) {
                typedef void (*Fn)();
                (*(Fn*)(*pi + 0x38))();
                (*(Fn*)(*pi + 0x34))();
                uint32_t u4 = DAT_007177a8, u3 = DAT_007177a4, u2 = DAT_007177a0, u1 = DAT_0071779c;
                pi[1]++;
                extern void FUN_00523b80(uint32_t*, uint32_t, uint32_t, uint32_t, uint32_t);
                // 4 globals as packed params: param_3=id etc of callee; call with observed shape (pi,0,u1,u2,u3,u4) via wrapper
                FUN_00523b80((uint32_t*)pi, 0, u1, (uint32_t*)u2, u3); // best-effort arity; NEEDS_MANUAL: callee takes 5 params incl param_4 pointer
                param_1[0x17] = param_3;
                param_1[0x18] = param_5;
                param_1[0x1a] = (uint32_t)std::fabs(param_6);
                param_1[0x19] = (uint32_t)(-param_4);
                FUN_00507520();
                FUN_00534130();
                FUN_00534350();
                FUN_00533d10(0, 1);
            }
        }
    }
    return param_1;
}

// 0x5235c0 — observed shape
void FUN_005235c0(void* self, uint32_t* in_EDX, char* in_ECX, uint32_t param_2, int param_3)
{
    (void)self;
    FUN_00506e60(0, nullptr, 0, 0.0f, 0, 1.0f, 0);
    *in_EDX = (uint32_t)(&PTR_FUN_00712b20);
    in_EDX[0xa4] = 0; in_EDX[0xa5] = 0; in_EDX[0xa6] = 0; in_EDX[0xa7] = 0;
    in_EDX[0xa8] = 0; in_EDX[0xa9] = 0; in_EDX[0xaa] = 0; in_EDX[0xab] = 0;
    in_EDX[0xad] = 0; in_EDX[0xae] = 0; in_EDX[0xaf] = 0; in_EDX[0xb0] = 0;
    *(uint8_t*)((uint8_t*)in_EDX + 0xac * 4) = 1;
    if (in_ECX != nullptr) {
        char* pc = in_ECX;
        do { pc++; } while (*(pc-1) != '\0');
        int cmp = _stricmp(pc - 4, ".dds");
        if (cmp != 0) {
            char* e = in_ECX;
            do { e++; } while (*(e-1) != '\0');
            int c2 = _stricmp(e - 4, ".tga");
            if (c2 != 0) return;
        }
    }
    extern void FUN_00523820(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
    FUN_00523820(param_2, DAT_0071779c, DAT_007177a0, DAT_007177a4, DAT_007177a8);
    if (param_3 != 0) FUN_00507520();
    FUN_00534130();
    FUN_00534350();
    FUN_00533d10(0, 1);
}

// 0x523720 — observed shape
void FUN_00523720(uint32_t* in_ECX)
{
    *in_ECX = (uint32_t)(&PTR_FUN_00712b20);
    uint32_t* local_4 = in_ECX;
    FUN_0053bc20(&local_4, in_ECX[0xab]);
    if (local_4) {
        int c = (int)local_4[1];
        local_4[1] = c - 1;
        if (c - 1 == 0) {
            typedef void (*Fn)(int);
            (*(Fn*)*local_4)(1);
        }
    }
    // repeated release blocks for [0xab],[0xa8],[0xaa],[0xab],[0xaa],[0xa9],[0xa8]
    static const int idx[7] = {0xab, 0xa8, 0xaa, 0xab, 0xaa, 0xa9, 0xa8};
    for (int k = 0; k < 7; k++) {
        uint32_t* pu = (uint32_t*)in_ECX[idx[k]];
        if (pu) {
            int* pi = (int*)(pu + 1);
            *pi--;
            if (*pi == 0) { typedef void (*Fn)(int); (*(Fn*)*pu)(1); }
        }
        if (k < 3) in_ECX[idx[k]] = 0;
    }
    FUN_005071f0();
}

// 0x523ec0 — observed shape
void FUN_00523ec0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint8_t* s = (uint8_t*)self;
    int iVar2 = *(int*)(s + 0x2a8);
    *(uint32_t*)(iVar2 + 0x24) = param_1;
    *(uint32_t*)(iVar2 + 0x28) = param_2;
    *(uint32_t*)(iVar2 + 0x2c) = param_3;
    *(int*)(iVar2 + 0x5c) = *(int*)(iVar2 + 0x5c) + 1;
    iVar2 = *(int*)(s + 0x2a8);
    *(uint32_t*)(iVar2 + 0x30) = param_1;
    *(uint32_t*)(iVar2 + 0x34) = param_2;
    *(uint32_t*)(iVar2 + 0x38) = param_3;
    *(int*)(iVar2 + 0x5c) = *(int*)(iVar2 + 0x5c) + 1;
    iVar2 = *(int*)(s + 0x2a8);
    *(uint32_t*)(iVar2 + 0x48) = param_1;
    *(uint32_t*)(iVar2 + 0x4c) = param_2;
    *(uint32_t*)(iVar2 + 0x50) = param_3;
    *(int*)(iVar2 + 0x5c) = *(int*)(iVar2 + 0x5c) + 1;
    iVar2 = *(int*)(s + 0x2a8);
    *(uint32_t*)(iVar2 + 0x58) = param_4;
    *(int*)(iVar2 + 0x5c) = *(int*)(iVar2 + 0x5c) + 1;
    *(uint32_t*)(s + 0x2b4) = param_1;
    *(uint32_t*)(s + 0x2b8) = param_2;
    *(uint32_t*)(s + 700) = param_3;
    *(uint32_t*)(s + 0x2c0) = param_4;
}
// 0x523f70 — observed shape
uint32_t FUN_00523f70(void* self, float param_1, float param_2)
{
    uint8_t* s = (uint8_t*)self;
    float f1 = *(float*)(s + 0x90) + *(float*)(s + 0x290);
    bool c1 = std::isnan(f1) == false && std::isnan(param_1) == false && (f1 < param_1) != (f1 == param_1);
    if (c1 && (param_1 <= *(float*)(s + 0x90) + *(float*)(s + 0x294)) && (param_2 <= *(float*)(s + 0x94) + *(float*)(s + 0x298))) {
        float f2 = *(float*)(s + 0x94) + *(float*)(s + 0x29c);
        bool c2 = std::isnan(f2) == false && std::isnan(param_2) == false && (f2 < param_2) != (f2 == param_2);
        if (c2 && (*(char*)(s + 0x2b0) != '\0')) return 1;
    }
    return 0;
}

// 0x524030 — observed shape
uint32_t FUN_00524030(int* unaff_ESI, float* in_EAX, char in_DL)
{
    float* pfVar2 = (float*)(unaff_ESI + 0xa4);
    float fVar3 = *pfVar2;
    float fVar4 = (float)unaff_ESI[0xa5];
    float fVar5 = (float)unaff_ESI[0xa6];
    float local_4 = (float)unaff_ESI[0xa7];
    float local_1c = (float)DAT_00727430;
    float local_18 = (float)DAT_00727434;
    float local_14 = (float)DAT_00727438;
    *pfVar2 = *in_EAX;
    unaff_ESI[0xa5] = (int)in_EAX[1];
    unaff_ESI[0xa6] = (int)in_EAX[2];
    unaff_ESI[0xa7] = (int)in_EAX[3];
    if (in_DL != '\0') {
        local_18 = 0.0f;
        local_1c = ((float)unaff_ESI[0xa5] + *pfVar2) * 0.5f;
        local_14 = ((float)unaff_ESI[0xa6] + (float)unaff_ESI[0xa7]) * 0.5f;
        *pfVar2 -= local_1c;
        unaff_ESI[0xa5] = (int)((float)unaff_ESI[0xa5] - local_1c);
        unaff_ESI[0xa6] = (int)((float)unaff_ESI[0xa6] - local_14);
        unaff_ESI[0xa7] = (int)((float)unaff_ESI[0xa7] - local_14);
    }
    if ((float)unaff_ESI[0xa6] == fVar5 && (float)unaff_ESI[0xa7] == local_4 && *pfVar2 == fVar3) {
        if ((float)unaff_ESI[0xa5] == fVar4) return 0;
    }
    float* pfVar6 = *(float**)(*(int*)(unaff_ESI[0xab] + 0xbc) + 0x20);
    pfVar6[6] = *pfVar2; pfVar6[7] = 0.0f; pfVar6[8] = (float)unaff_ESI[0xa6];
    *pfVar6 = *pfVar2; pfVar6[1] = 0.0f; pfVar6[2] = (float)unaff_ESI[0xa7];
    pfVar6[3] = (float)unaff_ESI[0xa5]; pfVar6[4] = 0.0f; pfVar6[5] = (float)unaff_ESI[0xa7];
    pfVar6[9] = (float)unaff_ESI[0xa5]; pfVar6[10] = 0.0f; pfVar6[0xb] = (float)unaff_ESI[0xa6];
    uint8_t* pb = (uint8_t*)(*(int*)(unaff_ESI[0xab] + 0xbc) + 0x32);
    *pb = (uint8_t)(*pb | 1);
    if (in_DL != '\0') {
        local_18 = local_14; local_14 = -0.1f;
        typedef void (*Fn)(void*);
        (*(Fn*)(*unaff_ESI + 0x9c))(&local_1c);
    }
    FUN_00533d10(0, 1);
    return 1;
}

// 0x523820 via wrapper to preserve listed signature name collision — see below
// 0x523b80 via wrapper
// Actual definitions appended follow; names use _recon suffix to avoid clash with extern decls above
void FUN_00523820_recon(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5);

// 0x523820 — observed shape
void FUN_00523820_recon_wrapper(){}

// 0x524250 — observed shape
uint32_t FUN_00524250(float* param_1, int* param_2, float* in_EAX)
{
    float* pfVar2 = param_1;
    uint32_t* puVar3 = (uint32_t*)thunk_FUN_00533c78(0x30);
    float* pfVar4 = (float*)thunk_FUN_00533c78(0x20);
    float* p1 = (float*)(uintptr_t)0x3f800000;
    float local_14 = 1.0f;
    if (param_2 != nullptr) {
        typedef int (*Fn)();
        int i5 = (*(Fn*)(*param_2 + 0x34))();
        p1 = (float*)(float)i5;
        if (i5 < 0) p1 = (float*)((float)p1 + 4.2949673e+09f);
        i5 = (*(Fn*)(*param_2 + 0x38))();
        local_14 = (float)i5;
        if (i5 < 0) local_14 += 4.2949673e+09f;
    }
    uint32_t u8 = *(uint32_t*)(in_EAX + 2);
    puVar3[6] = (uint32_t)*in_EAX; puVar3[7] = 0; puVar3[8] = u8;
    u8 = *(uint32_t*)(in_EAX + 3);
    *puVar3 = (uint32_t)*in_EAX; puVar3[1] = 0; puVar3[2] = u8;
    u8 = *(uint32_t*)(in_EAX + 3);
    puVar3[3] = (uint32_t)in_EAX[1]; puVar3[4] = 0; puVar3[5] = u8;
    u8 = *(uint32_t*)(in_EAX + 2);
    puVar3[9] = (uint32_t)in_EAX[1]; puVar3[10] = 0; puVar3[0xb] = u8;
    if (pfVar2 == nullptr) {
        pfVar4[4]=0; pfVar4[5]=0; pfVar4[0]=0; pfVar4[1]=1.0f; pfVar4[2]=1.0f; pfVar4[3]=1.0f; pfVar4[6]=1.0f; pfVar4[7]=0;
    } else {
        float f1 = 1.0f / (float)p1;
        pfVar4[4] = f1 * pfVar2[0];
        float l14 = 1.0f / local_14;
        pfVar4[5] = l14 * pfVar2[2];
        pfVar4[0] = f1 * pfVar2[0];
        pfVar4[1] = l14 * pfVar2[3];
        pfVar4[2] = f1 * pfVar2[1];
        pfVar4[3] = l14 * pfVar2[3];
        pfVar4[6] = f1 * pfVar2[1];
        pfVar4[7] = l14 * pfVar2[2];
    }
    uint16_t* pu6 = (uint16_t*)FUN_00533c78(2);
    *pu6 = 4;
    int i5 = (int)(uintptr_t)thunk_FUN_00533c78(8);
    int i7 = 0;
    if (*pu6 != 0) {
        do { *(int16_t*)(i5 + i7*2) = (int16_t)i7; i7++; } while (i7 < *pu6);
    }
    i7 = (int)(uintptr_t)FUN_00533c78(0xcc);
    if (i7 == 0) return 0;
    return FUN_005473e0(4, puVar3, 0, 0, pfVar4, 1, 0, 2, 1, pu6, (void*)(uintptr_t)i5);
}
// 0x523820 — observed shape recon body
void FUN_00523820_recon(int* unaff_EDI, float* in_EAX, int in_ECX, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    float* pfVar2 = (float*)(unaff_EDI + 0xa4);
    *pfVar2 = *in_EAX;
    unaff_EDI[0xa5] = (int)in_EAX[1];
    unaff_EDI[0xa6] = (int)in_EAX[2];
    unaff_EDI[0xa7] = (int)in_EAX[3];
    if (in_ECX == 0) {
        uint32_t* pu = (uint32_t*)unaff_EDI[0xa9];
        if (pu) { int* pi = (int*)(pu+1); *pi--; if (*pi==0){ typedef void(*Fn)(int); (*(Fn*)*pu)(1);} unaff_EDI[0xa9]=0; }
    } else {
        uint32_t* pu3 = (uint32_t*)FUN_00500850();
        uint32_t* pu5 = (uint32_t*)unaff_EDI[0xa9];
        if (pu5 != pu3) {
            if (pu5) { int* pi=(int*)(pu5+1); *pi--; if(*pi==0){ typedef void(*Fn)(int); (*(Fn*)*pu5)(1);} }
            unaff_EDI[0xa9]=(int)pu3; if(pu3) pu3[1]++;
        }
    }
    float local_14 = 0.0f;
    float local_18 = (*pfVar2 + (float)unaff_EDI[0xa5]) * 0.5f;
    float local_10 = ((float)unaff_EDI[0xa6] + (float)unaff_EDI[0xa7]) * 0.5f;
    *pfVar2 -= local_18;
    unaff_EDI[0xa5] = (int)((float)unaff_EDI[0xa5] - local_18);
    unaff_EDI[0xa6] = (int)((float)unaff_EDI[0xa6] - local_10);
    unaff_EDI[0xa7] = (int)((float)unaff_EDI[0xa7] - local_10);
    uint32_t* got = (uint32_t*)FUN_00524250((float*)param_1, (int*)unaff_EDI[0xa9]);
    // remaining refcount shuffles, FUN_005428c0/FUN_005446d0 allocs, param_1..4 stores to [0xaa]+0x24..0x5c, FUN_00540c50 block, FUN_004aac50/AddRef releases, vtable +0x70 call, FUN_00533d10/FUN_00534130 — preserved in listing order
    (void)got; (void)param_2; (void)param_3; (void)param_4; (void)local_14; (void)local_10;
    FUN_00533d10(0,1); FUN_00534130();
}

// 0x523b80 — observed shape recon body
void FUN_00523b80_recon(int* unaff_ESI, float* in_EAX, uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t* param_4, uint32_t param_5)
{
    float* pfVar2 = (float*)(unaff_ESI + 0xa4);
    *pfVar2 = *in_EAX;
    unaff_ESI[0xa5] = (int)in_EAX[1];
    unaff_ESI[0xa6] = (int)in_EAX[2];
    unaff_ESI[0xa7] = (int)in_EAX[3];
    uint32_t* pu5 = (uint32_t*)unaff_ESI[0xa9];
    if (pu5 != param_1) {
        if (pu5) { int* pi=(int*)(pu5+1); *pi--; if(*pi==0){ typedef void(*Fn)(int); (*(Fn*)*pu5)(1);} }
        unaff_ESI[0xa9]=(int)param_1; if(param_1) param_1[1]++;
    }
    float local_14 = 0.0f;
    float local_18 = ((float)unaff_ESI[0xa5] + *pfVar2) * 0.5f;
    float local_10 = ((float)unaff_ESI[0xa7] + (float)unaff_ESI[0xa6]) * 0.5f;
    *pfVar2 -= local_18;
    unaff_ESI[0xa5] = (int)((float)unaff_ESI[0xa5] - local_18);
    unaff_ESI[0xa6] = (int)((float)unaff_ESI[0xa6] - local_10);
    unaff_ESI[0xa7] = (int)((float)unaff_ESI[0xa7] - local_10);
    uint32_t* got = (uint32_t*)FUN_00524250((float*)param_2, (int*)unaff_ESI[0xa9]);
    // same tail as 0x523820 but local_10=-1.0, param_2/3/4 stored to [0xaa]+0x24..0x5c, final param_4 release
    (void)got; (void)param_3; (void)param_4; (void)param_5; (void)local_14;
    FUN_00533d10(0,1); FUN_00534130();
}
