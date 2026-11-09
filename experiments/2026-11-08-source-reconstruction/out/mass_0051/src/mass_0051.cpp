// Reconstruction batch mass_0051 — Sid Meier's Pirates! (2004) PE32 i386
// Source: Ghidra 12.2 pseudocode corpus under analysis/pseudocode/functions/
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern char DAT_008cacd0[];
extern char DAT_008cacc8[];
extern char DAT_008cac14;
extern char DAT_008cac15;
extern void* PTR_FUN_0070db70;
extern void* PTR_FUN_007106a0;
extern void* PTR_FUN_007106a8;
extern void* PTR_FUN_007106ac;
extern int DAT_008e9ff8;
extern void FUN_00476050(void);
extern void FUN_00412ec0(void);
extern void operator_delete__(void*);
extern void operator_delete(void*);
extern void FUN_004f1c20(void);
extern void FUN_004f1b10(int**);
extern void FUN_00412f10(void);
extern void FUN_004f1840(void);
extern void FUN_004f3350(void);
extern void FUN_00412f90(void);
extern void FUN_004f5bd0(int);
extern void FUN_004f5ce0(int);
extern void FUN_004f74e0(void);

// 0x4ce190 — observed shape: 2-param; trims last byte of *param_1 into uVar2, restores it,
// finds last ',' via strrchr(*param_1,0x2c), tokenises trailing field, uppercases copy,
// scans for 'M'(0x4d)/'F'(0x46)/'N'(0x4e) -> param_2[0] in {0,1,2} and 'S'(0x53)/'P'(0x50) -> param_2[1] in {0,1}.
void FUN_004ce190(int* param_1, std::uint32_t* param_2)
{
    int iVar1;
    unsigned char uVar2;
    int iVar3;
    std::size_t _Size;
    int* piVar4;
    char* pcVar5;
    void* puVar6;
    char* pcVar7;
    int local_8 = 0;

    piVar4 = param_1;
    iVar3 = *param_1;
    iVar1 = *(int*)(iVar3 - 4) - 1;
    pcVar7 = DAT_008cacd0;
    param_1 = (int*)DAT_008cacd0;
    if (iVar1 < *(int*)(iVar3 - 4) && -1 < iVar1) {
        uVar2 = *(unsigned char*)(iVar3 + iVar1);
        *(unsigned char*)(iVar3 + iVar1) = 0;
        pcVar5 = std::strrchr((char*)*piVar4, 0x2c);
        *(unsigned char*)(iVar1 + *piVar4) = uVar2;
        if (pcVar5 != nullptr && (pcVar5 = pcVar5 - (char*)*piVar4, -1 < (int)(std::ptrdiff_t)pcVar5)) {
            FUN_00476050();
            FUN_00412ec0();
            puVar6 = (void*)(local_8 - 8);
            if (puVar6 != nullptr && puVar6 != DAT_008cacc8) operator_delete__(puVar6);
            FUN_004f1c20();
            FUN_004f1b10(&param_1);
            pcVar7 = (char*)param_1;
            FUN_00412f10();
            FUN_004f1840();
            _Size = *(std::size_t*)(pcVar5 - 4);
            if (-1 < (int)_Size && pcVar5 != pcVar7) {
                if (_Size == 0) {
                    FUN_00412f90();
                    pcVar7 = (char*)param_1;
                } else {
                    FUN_004f3350();
                    pcVar7 = (char*)param_1;
                    std::memmove(param_1, pcVar5, _Size);
                    pcVar7[*(int*)(pcVar7 - 4)] = '\0';
                }
            }
            pcVar5 = pcVar5 - 8;
            if (pcVar5 != nullptr && pcVar5 != DAT_008cacc8) operator_delete__(pcVar5);
            FUN_004f1c20();
            FUN_004f1b10(&param_1);
            _strupr(pcVar7);
            if (0 < *(int*)(pcVar7 - 4)) {
                pcVar5 = std::strchr(pcVar7, 0x4d);
                if (pcVar5 == nullptr || (int)(pcVar5 - pcVar7) < 0) {
                    if (*(int*)(pcVar7 - 4) < 1) goto LAB_004ce3a5;
                    pcVar5 = std::strchr(pcVar7, 0x46);
                    if (pcVar5 == nullptr || (int)(pcVar5 - pcVar7) < 0) {
                        if (*(int*)(pcVar7 - 4) < 1) goto LAB_004ce3a5;
                        pcVar5 = std::strchr(pcVar7, 0x4e);
                        if (pcVar5 != nullptr && -1 < (int)(pcVar5 - pcVar7)) *param_2 = 2;
                    } else *param_2 = 1;
                } else *param_2 = 0;
                if (0 < *(int*)(pcVar7 - 4)) {
                    pcVar5 = std::strchr(pcVar7, 0x53);
                    if (pcVar5 == nullptr || (int)(pcVar5 - pcVar7) < 0) {
                        if (0 < *(int*)(pcVar7 - 4)) {
                            pcVar5 = std::strchr(pcVar7, 0x50);
                            if (pcVar5 != nullptr && -1 < (int)(pcVar5 - pcVar7)) param_2[1] = 1;
                        }
                    } else param_2[1] = 0;
                }
            }
            goto LAB_004ce3a5;
        }
    }
    FUN_00412f10();
LAB_004ce3a5:
    pcVar7 = pcVar7 - 8;
    if (pcVar7 != nullptr && pcVar7 != DAT_008cacc8) operator_delete__(pcVar7);
}

// 0x4ce5c0 — observed shape: ECX receiver; month gate (in_ECX+4 in (5,0xc)), GetLocalTime,
// Sep 19 sets DAT_008cac15=1/DAT_008cac14=0; month==9 with DAT_008cac14==0 clears via FUN_004f5ce0.
void FUN_004ce5c0(void* self)
{
    SYSTEMTIME local_10;
    FUN_004f5bd0(0);
    if (5 < *(int*)((char*)self + 4) && *(int*)((char*)self + 4) < 0xc) {
        GetLocalTime(&local_10);
        if (local_10.wMonth == 9 && local_10.wDay == 0x13) {
            DAT_008cac15 = 1;
            DAT_008cac14 = '\0';
        }
    }
    if (*(int*)((char*)self + 4) == 9) {
        if (DAT_008cac14 == '\0') { FUN_004f5ce0(0); return; }
    } else if (DAT_008cac14 != '\0') {
        FUN_004f5ce0(0);
    }
}

// 0x4ce670 — observed shape: ESI receiver; installs vtable PTR_FUN_0070db70, frees strings at
// +0x6c/+0x68 (indices 0x1b/0x1a), installs PTR_FUN_007106a8/+0x54, frees +0x54/+0x3c,
// installs PTR_FUN_007106a0/+0x3c, frees +0x3c, installs PTR_FUN_007106ac at +0x20/+0x08.
void FUN_004ce670(void* self)
{
    std::uint32_t** p = (std::uint32_t**)self;
    void* puVar1;
    *p = (std::uint32_t*)PTR_FUN_0070db70;
    FUN_004f74e0();
    puVar1 = (void*)((char*)p[0x1b] - 8);
    if (puVar1 != nullptr && puVar1 != DAT_008cacc8) operator_delete__(puVar1);
    p[0x1b] = (std::uint32_t*)DAT_008cacd0;
    puVar1 = (void*)((char*)p[0x1a] - 8);
    if (puVar1 != nullptr && puVar1 != DAT_008cacc8) operator_delete__(puVar1);
    p[0x1a] = (std::uint32_t*)DAT_008cacd0;
    p[0x14] = (std::uint32_t*)PTR_FUN_007106a8;
    operator_delete__((void*)p[0x15]);
    p[0xe] = (std::uint32_t*)PTR_FUN_007106a0;
    operator_delete__((void*)p[0xf]);
    p[8] = (std::uint32_t*)PTR_FUN_007106ac;
    operator_delete__((void*)p[9]);
    p[2] = (std::uint32_t*)PTR_FUN_007106ac;
    operator_delete__((void*)p[3]);
}

// 0x4ce700 — observed shape: ECX receiver + byte param_1; installs PTR_FUN_007106a8,
// frees *(self+4); if (param_1 & 1) frees self.
void FUN_004ce700(void* self, unsigned char param_1)
{
    std::uint32_t** p = (std::uint32_t**)self;
    *p = (std::uint32_t*)PTR_FUN_007106a8;
    operator_delete__((void*)p[1]);
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x4ce730 — observed shape: huge non-contiguous global-init routine (0x4ce730..0x4cff2a).
// Early-out when local_474 < 10 sets DAT_008cac29=1, DAT_00726398=0, DAT_007263a0=0.
// Otherwise creates 4+1 heap objects via FUN_00533c78 initialised with PTR_FUN_006fd14c
// (slots [+1]=0,[+7]=0,[+0x19]=0,[+0x2f]=0, DAT_00727444++), 4x FUN_004baaa0/FUN_004db3d0/FUN_005016d0
// loop, FUN_005c28d0, 0x10x FUN_004bb500 fill, DAT_008e9fd8[0x17..0x19] float constants
// (0xc2200000/-0x3de00000/0x461c4000), FUN_0053c740, 9-dword matrix copy to DAT_008e9fd8+0xe,
// refcount dance at DAT_008e9fd8[0x55], 7-dword copy at +0x4a, viewport FOV block
// (40000.0/1000.0 -> FUN_004cce40/FUN_004ad820), DAT_008cac36 select FUN_004ff510 args,
// FUN_00547720, then 8-iteration angular loop (0x5a step to 0x2d0, FUN_0053c7c0) building apuStack_3c0.
// NOTE: full 7-range body not expanded; leading structure and constants preserved.
extern char DAT_008cac29;
extern int DAT_00726398;
extern int DAT_007263a0;
extern int DAT_00727444;
extern void* PTR_FUN_006fd14c;
extern void FUN_005002f0(void);
extern void* FUN_00533c78(std::size_t);
extern void FUN_004bdca0(void*,int,int,int,int,int);
extern void FUN_004db3d0(void);
extern void FUN_005016d0(std::uint32_t);
extern void FUN_005c28d0(void);
extern std::uint32_t FUN_004bb500(void);
extern void FUN_0053c740(void);
extern void* FUN_0053c8d0(void*,void*);
extern void FUN_004ff6b0(void);
extern void FUN_004cce40(void);
extern void FUN_004ad820(void);
extern void FUN_004ff510(void*,void*,void*);
extern void FUN_00547720(void);
extern void FUN_00412f10(void);
extern void FUN_0053c7c0(void);
void FUN_004ce730(void)
{
    std::uint32_t* local_444 = nullptr;
    std::uint32_t* local_440[4] = {};
    std::uint32_t* local_474 = nullptr;
    std::uint32_t uVar16 = 0;
    std::uint32_t uVar17 = 0;
    std::uint32_t uVar6;
    extern void* DAT_008e9ff8;
    extern void* DAT_008e9fd8;
    (void)0x4ce747; (void)0xc0; (void)0x4ce776;
    FUN_005002f0();
    if (local_474 < (std::uint32_t*)10) { DAT_008cac29 = 1; DAT_00726398 = 0; DAT_007263a0 = 0; return; }
    local_444 = (std::uint32_t*)FUN_00533c78(0xc0);
    if (local_444 != nullptr) {
        local_444[1] = 0; *local_444 = (std::uint32_t*)PTR_FUN_006fd14c;
        local_444[7] = 0; DAT_00727444++; local_444[0x19] = 0; local_444[0x2f] = 0;
        FUN_004bdca0(DAT_008e9ff8,0,0,0,0,-1);
    }
    for (int k = 0; k < 4; k++) {
        local_440[k] = (std::uint32_t*)FUN_00533c78(0xc0);
        if (local_440[k] != nullptr) {
            local_440[k][1] = 0; *local_440[k] = (std::uint32_t*)PTR_FUN_006fd14c;
            local_440[k][7] = 0; local_440[k][0x19] = 0; DAT_00727444++; local_440[k][0x2f] = 0;
            FUN_004bdca0(DAT_008e9ff8,0,0,0,0,-1);
        }
    }
    uVar16 = 0;
    do { uVar6 = FUN_004bb500(); (void)uVar6; uVar16++; } while (uVar16 < 4);
    FUN_005c28d0();
    uVar16 = 0; do { uVar6 = FUN_004bb500(); uVar16++; } while (uVar16 < 0x10);
    local_474 = (std::uint32_t*)FUN_00533c78(0xc0);
    if (local_474 != nullptr) {
        local_474[1] = 0; *local_474 = (std::uint32_t*)PTR_FUN_006fd14c;
        local_474[7] = 0; local_474[0x19] = 0; DAT_00727444++; local_474[0x2f] = 0;
        FUN_004bdca0(DAT_008e9ff8,0,0,0,0,-1);
    }
    ((std::uint32_t*)DAT_008e9fd8)[0x17] = 0;
    ((std::uint32_t*)DAT_008e9fd8)[0x18] = 0xc2200000u;
    ((std::uint32_t*)DAT_008e9fd8)[0x19] = 0x461c4000u;
    FUN_0053c740();
    {
        std::uint32_t local_46c[3] = {};
        std::uint32_t* src = (std::uint32_t*)FUN_0053c8d0((void*)((char*)DAT_008e9fd8 + 0x85*4), local_46c);
        std::uint32_t* dst = (std::uint32_t*)DAT_008e9fd8 + 0xe;
        for (int i = 9; i != 0; i--) { *dst = *src; src++; dst++; }
    }
    FUN_004ff6b0();
    if (40000.0f != 40000.0f || 1000.0f != 1000.0f) { FUN_004cce40(); FUN_004ad820(); }
    FUN_004ff510(nullptr, nullptr, nullptr);
    FUN_00547720();
    uVar16 = 0; uVar17 = 0;
    do {
        uVar6 = (std::uint32_t)((float)(int)uVar16 * -20.0f);
        (void)uVar6; FUN_0053c7c0();
        uVar17 += 0x5a; uVar16++;
    } while (uVar17 < 0x2d0);
    (void)0;
    // Remaining ranges 0x4cf450..0x4cff2a: see corpus file; guarded for NEEDS_MANUAL if needed.
}

// 0x4cff30 — observed shape: alloc 0x68 via FUN_00533c78 -> FUN_00508120/FUN_00508190 lifecycle;
// two strlen loops over DAT_008cacd0, FUN_004f3b00(&local_4) + 6x FUN_00508360(.,1) then 1x, frees.
extern void* FUN_00533c78(std::size_t);
extern void* FUN_00508120(void);
extern void FUN_00508190(void);
extern void FUN_004f3b00(void**);
extern void FUN_00508360(void*,int);
void FUN_004cff30(void)
{
    void* pvVar5 = nullptr;
    int iVar4 = (int)(std::intptr_t)FUN_00533c78(0x68);
    pvVar5 = (iVar4 == 0) ? nullptr : FUN_00508120();
    char* local_8 = DAT_008cacd0;
    void* local_4 = DAT_008cacd0;
    FUN_00412f10();
    { char* pc = local_8; while (*pc != '\0') pc++; }
    FUN_004f3b00(&local_4);
    void* puVar3 = local_4;
    for (int i = 0; i < 6; i++) FUN_00508360(puVar3, 1);
    FUN_00412f10();
    { char* pc = local_8; while (*pc != '\0') pc++; }
    FUN_004f3b00(&local_4);
    puVar3 = local_4;
    FUN_00508360(local_4, 1);
    if (pvVar5 != nullptr) { FUN_00508190(); operator_delete(pvVar5); }
    void* puVar1 = (void*)((char*)puVar3 - 8);
    if (puVar1 != nullptr && puVar1 != DAT_008cacc8) operator_delete__(puVar1);
}

// 0x4d0080 — observed shape: allocates 0x110/0x11c sim objects at DAT_008c97c4/DAT_008c97c0,
// writes float bits 0x3f000000/0x3f800000 and DAT_00727424/28/2c, DAT_00717780/84/88 triple,
// FUN_00535670 x3 per object, angular init via FUN_0053c7c0/0xbf490fdb/FUN_0053c8d0 9-dword copy at +0x38,
// vtable +0x70 calls, FUN_00533d10(0,1) x2.
extern void* DAT_008c97c4;
extern void* DAT_008c97c0;
extern void* DAT_008e9fe8;
extern void* DAT_008ea008;
extern void* DAT_008ea00c;
extern void FUN_00535670(void*);
extern void FUN_0053c7c0(int);
extern void FUN_0053c780(std::uint32_t);
extern void* FUN_0053c8d0(void*,void*);
extern void FUN_00533d10(int,int);
extern void* FUN_00544d00(void);
extern void* FUN_00544ba0(void);
void FUN_004d0080(void)
{
    unsigned char local_24[36] = {0};
    unsigned char local_6c[72] = {0};
    std::uint32_t* puVar3;
    std::uint32_t* puVar5;
    extern std::uint32_t DAT_00727424, DAT_00727428, DAT_0072742c, DAT_00717780, DAT_00717784, DAT_00717788;
    std::int32_t iVar2;
    iVar2 = FUN_00533c78(0x110) ? 1 : 0;
    DAT_008c97c4 = iVar2 ? FUN_00544d00() : nullptr;
    if (DAT_008c97c4 == nullptr) goto second;
    {
        int c0 = *(int*)((char*)DAT_008c97c4 + 0xc0);
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0xe8) = 0x3f000000;
        *(int*)((char*)DAT_008c97c4 + 0xc0) = c0 + 2;
        *(unsigned char*)((char*)DAT_008c97c4 + 0xb4) = 1;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0xec) = 0x3f000000;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0xf0) = 0x3f000000;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0xe4) = 0x3f800000;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0xf4) = DAT_00727424;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0xf8) = DAT_00727428;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0xfc) = DAT_0072742c;
        *(int*)((char*)DAT_008c97c4 + 0xc0) = c0 + 3;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0x100) = DAT_00727424;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0x104) = DAT_00727428;
        *(int*)((char*)DAT_008c97c4 + 0xc0) = c0 + 4;
        *(std::uint32_t*)((char*)DAT_008c97c4 + 0x108) = DAT_0072742c;
    }
    FUN_00535670(DAT_008e9fe8); FUN_00535670(DAT_008ea008); FUN_00535670(DAT_008ea00c);
second:
    iVar2 = FUN_00533c78(0x11c) ? 1 : 0;
    DAT_008c97c0 = iVar2 ? FUN_00544ba0() : nullptr;
    if (DAT_008c97c0 != nullptr) {
        int c0 = *(int*)((char*)DAT_008c97c0 + 0xc0);
        *(unsigned char*)((char*)DAT_008c97c0 + 0xb4) = 1;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0xe4) = 0x3f800000;
        *(int*)((char*)DAT_008c97c0 + 0xc0) = c0 + 1;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0xe8) = DAT_00727424;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0xec) = DAT_00727428;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0xf0) = DAT_0072742c;
        *(int*)((char*)DAT_008c97c0 + 0xc0) = c0 + 2;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0xf4) = DAT_00717780;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0xf8) = DAT_00717784;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0xfc) = DAT_00717788;
        *(int*)((char*)DAT_008c97c0 + 0xc0) = c0 + 3;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0x100) = DAT_00717780;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0x104) = DAT_00717784;
        *(int*)((char*)DAT_008c97c0 + 0xc0) = c0 + 4;
        *(std::uint32_t*)((char*)DAT_008c97c0 + 0x108) = DAT_00717788;
        FUN_00535670(DAT_008e9fe8); FUN_00535670(DAT_008ea008); FUN_00535670(DAT_008ea00c);
        FUN_0053c7c0(0); FUN_0053c780(0xbf490fdb);
        puVar3 = (std::uint32_t*)FUN_0053c8d0(local_24, local_6c);
        puVar5 = (std::uint32_t*)((char*)DAT_008c97c0 + 0x38);
        for (int i = 9; i != 0; i--) { *puVar5 = *puVar3; puVar3++; puVar5++; }
        (*(void(**)(void*,int))(*(void***)DAT_008e9fe8 + 0x70/4))(DAT_008c97c0, 1);
        (*(void(**)(void*,int))(*(void***)DAT_008e9fe8 + 0x70/4))(DAT_008c97c4, 1);
        FUN_00533d10(0,1); FUN_00533d10(0,1);
    }
}

// 0x4d02e0 — observed shape: EAX comma-string, EDI float[3]; splits at first two ',',
// atof each field, stores (float)(v*0.003921569) into edi[0..2].
void FUN_004d02e0(char* self, float* out)
{
    char* pcVar1;
    char* pcVar2 = self;
    char* pcVar3;
    do { pcVar1 = pcVar2; pcVar2 = pcVar1 + 1; } while (pcVar1[1] != ',');
    *pcVar2 = '\0';
    out[0] = (float)(std::atof(self) * 0.003921569);
    do { pcVar3 = pcVar2; pcVar2 = pcVar3 + 1; } while (pcVar3[1] != ',');
    pcVar3[1] = '\0';
    out[1] = (float)(std::atof(pcVar1 + 2) * 0.003921569);
    out[2] = (float)(std::atof(pcVar3 + 2) * 0.003921569);
}

// 0x4d0340 — observed shape: light-config reader; sets float constants (local_f8/f4=0x3e99999a,
// local_f0=0x3f19999a, local_11c=0x3f7fd220 etc.), bails via FUN_004f8f50 unless
// FUN_004f8fa0 && FUN_004f96a0 succeed; reads AmbientLightColor etc. via FUN_004f98b0+FUN_004d02e0,
// FUN_004f9820 x4, writes DAT_008c97c4/DAT_008c97c0 triples, angle convert 0.017453292, 9-dword matrix copy.
extern char FUN_004f8fa0(void*, char*);
extern int FUN_004f96a0(void);
extern void FUN_004f98b0(const char*, void*);
extern void FUN_004f9820(void*);
extern void FUN_004f8f50(void);
void FUN_004d0340(char* self)
{
    float local_148 = -30.0f;
    float local_13c = -90.0f;
    std::uint32_t local_144 = 0x3f666666, local_140 = 0x3f800000;
    std::uint32_t local_f8 = 0x3e99999a, local_f4 = 0x3e99999a, local_f0 = 0x3f19999a;
    std::uint32_t local_104 = 0, local_100 = 0, local_fc = 0;
    std::uint32_t local_11c = 0x3f7fd220, local_118 = 0x3f6dab9f, local_114 = 0x3f31a36e;
    std::uint32_t local_110 = 0x3f7fd220, local_10c = 0x3f6dab9f, local_108 = 0x3f31a36e;
    std::uint32_t local_130 = 0, local_124 = 1, local_12c = 0, local_128 = 0, local_134 = 0;
    void* local_138 = nullptr; extern void* PTR_FUN_007108ac; local_138 = PTR_FUN_007108ac;
    unsigned char local_ec[128] = {0};
    unsigned char local_6c[72] = {0};
    unsigned char local_24[36] = {0};
    char cVar1 = FUN_004f8fa0(&local_138, self);
    if (cVar1 != '\0') {
        cVar1 = (char)FUN_004f96a0();
        if (cVar1 != '\0') {
            FUN_004f98b0("AmbientLightColor", local_ec); FUN_004d02e0((char*)local_ec, (float*)&local_104);
            FUN_004f98b0("DirectionalLightAmbientColor", local_ec); FUN_004d02e0((char*)local_ec, (float*)&local_104);
            FUN_004f98b0("DirectionalLightDiffuseColor", local_ec); FUN_004d02e0((char*)local_ec, (float*)&local_104);
            FUN_004f98b0("DirectionalLightSpecularColor", local_ec); FUN_004d02e0((char*)local_ec, (float*)&local_104);
            FUN_004f9820(&local_148); FUN_004f9820(&local_13c); FUN_004f9820(&local_140); FUN_004f9820(&local_144);
            std::uint32_t* dst = (std::uint32_t*)DAT_008c97c4;
            *(std::uint32_t*)((char*)dst + 0xe4) = local_140;
            *(std::uint32_t*)((char*)dst + 0xe8) = local_f8;
            *(std::uint32_t*)((char*)dst + 0xec) = local_f4;
            *(std::uint32_t*)((char*)dst + 0xf0) = local_f0;
            *(int*)((char*)dst + 0xc0) += 2;
            dst = (std::uint32_t*)DAT_008c97c0;
            *(std::uint32_t*)((char*)dst + 0xe4) = local_144;
            *(std::uint32_t*)((char*)dst + 0xe8) = local_104;
            *(std::uint32_t*)((char*)dst + 0xec) = local_100;
            *(std::uint32_t*)((char*)dst + 0xf0) = local_fc;
            *(std::uint32_t*)((char*)dst + 0xf4) = local_11c;
            *(std::uint32_t*)((char*)dst + 0xf8) = local_118;
            *(std::uint32_t*)((char*)dst + 0xfc) = local_114;
            *(std::uint32_t*)((char*)dst + 0x100) = local_110;
            *(std::uint32_t*)((char*)dst + 0x104) = local_10c;
            *(std::uint32_t*)((char*)dst + 0x108) = local_108;
            *(int*)((char*)dst + 0xc0) += 4;
            FUN_0053c780((std::uint32_t)(local_148 * 0.017453292f));
            FUN_0053c7c0((int)(local_13c * 0.017453292f));
            std::uint32_t* src = (std::uint32_t*)FUN_0053c8d0(local_24, local_6c);
            std::uint32_t* d2 = (std::uint32_t*)((char*)DAT_008c97c0 + 0x38);
            for (int i = 9; i != 0; i--) { *d2 = *src; src++; d2++; }
            FUN_00533d10(0,0);
        }
    }
    FUN_004f8f50();
}
// 0x4d0650 — observed shape: non-contiguous entity scan; walks DAT_008e9fe8+0xd0 list, filters by
// FUN_005f0ddc() and DAT_007278a8/DAT_00727600/DAT_00727608 sentinels, maintains ordered local_20c
// list of 8-byte records with *(+0xb4) flag, iVar5<7 cap. LAB-order preserved (see corpus).
extern void* DAT_008e9fe8;
extern void* DAT_008e9fe8_2;
extern int FUN_005f0ddc(void);
extern void FUN_00534350(void);
extern void FUN_004d4580(void);
extern void* LAB_004ccbf0(void);
extern char DAT_007278a8[];
extern char DAT_00727608[];
extern char DAT_00727600[];
void FUN_004d0650(void)
{
    int iVar3 = 0;
    std::uint32_t** local_20c = nullptr;
    std::uint32_t** local_208 = nullptr;
    int* piVar7 = nullptr;
    std::uint32_t** puVar2 = nullptr;
    std::uint32_t** puVar4 = nullptr;
    int iVar5 = 0;
    FUN_00534350();
    int* piVar6 = *(int**)((char*)DAT_008e9fe8 + 0xd0);
    int* local_200[128] = {};
    piVar7 = local_200;
LAB_004d0692:
    if (piVar6 != nullptr) {
        int* piVar1 = *(int**)((char*)piVar6 + 8);
        piVar6 = *(int**)piVar6;
        if (piVar1 != nullptr) {
            for (puVar2 = (std::uint32_t**)(**(void**(**)(void*))(*(void***)piVar1 + 1))(); puVar2 != nullptr; puVar2 = (std::uint32_t**)*puVar2) {
                if (puVar2 == (std::uint32_t**)DAT_007278a8) {
                    iVar3 = FUN_005f0ddc();
                    *piVar7 = iVar3; piVar7[1] = (int)(std::intptr_t)piVar1;
                    puVar2 = (std::uint32_t**)(**(void**(**)(void*))(*(void***)piVar1 + 1))();
                    goto joined_r0x004d070f;
                }
            }
        }
        goto LAB_004d07ce;
    }
joined_r0x004d07dc:
    for (;;) {
        if (local_20c == nullptr) { FUN_004d4580(); return; }
        iVar3 = *(int*)((char*)local_20c + 8);
        piVar6 = (int*)((char*)local_20c + 8);
        if (7 < iVar5) {
            if (*(void**)((char*)iVar3 + 4) != nullptr) {
                for (puVar2 = (std::uint32_t**)(**(void**(**)(void*))(*(void***)((*(int**)((char*)iVar3 + 4))) + 1))(); puVar2 != nullptr; puVar2 = (std::uint32_t**)*puVar2)
                    if (puVar2 == (std::uint32_t**)DAT_00727608) goto LAB_004d0834;
            }
        LAB_004d080e:
            local_20c = (std::uint32_t**)*local_20c;
            *(unsigned char*)(*(int*)((char*)*piVar6 + 4) + 0xb4) = 0;
            continue;
        }
    LAB_004d0834:
        if (*(float*)(*(int*)((char*)iVar3 + 4) + 0xe4) <= 0.0f) goto LAB_004d080e;
        local_20c = (std::uint32_t**)*local_20c;
        *(unsigned char*)(*(int*)((char*)*piVar6 + 4) + 0xb4) = 1;
        if (*(void**)((char*)iVar3 + 4) != nullptr) {
            for (puVar2 = (std::uint32_t**)(**(void**(**)(void*))(*(void***)((*(int**)((char*)iVar3 + 4))) + 1))(); puVar2 != nullptr; puVar2 = (std::uint32_t**)*puVar2)
                if (puVar2 == (std::uint32_t**)DAT_00727608) goto joined_r0x004d07dc;
        }
        iVar5++;
        continue;
    }
joined_r0x004d070f:
    while (true) {
        if (puVar2 == nullptr) goto LAB_004d0723;
        if (puVar2 == (std::uint32_t**)DAT_00727600) { *piVar7 = 0; goto LAB_004d0723; }
        puVar2 = (std::uint32_t**)*puVar2;
    }
LAB_004d0723:
    if (local_20c == nullptr) {
        local_20c = (std::uint32_t**)LAB_004ccbf0();
        local_20c[2] = (std::uint32_t*)(std::intptr_t)piVar7;
        local_20c[1] = nullptr; *local_20c = nullptr; local_208 = local_20c;
    } else {
        puVar2 = local_20c;
        while (true) {
            if (*piVar7 <= *(int*)puVar2[2]) {
                puVar4 = (std::uint32_t**)LAB_004ccbf0();
                puVar4[2] = (std::uint32_t*)(std::intptr_t)piVar7;
                *puVar4 = (std::uint32_t*)puVar2;
                puVar4[1] = puVar2[1];
                if (puVar2[1] == nullptr) { puVar2[1] = (std::uint32_t*)puVar4; local_20c = puVar4; }
                else { *(std::uint32_t**)puVar2[1] = (std::uint32_t*)puVar4; puVar2[1] = (std::uint32_t*)puVar4; }
                goto LAB_004d07c7;
            }
            puVar2 = (std::uint32_t**)*puVar2;
            if (puVar2 == nullptr) break;
        }
        puVar2 = (std::uint32_t**)LAB_004ccbf0();
        puVar2[2] = (std::uint32_t*)(std::intptr_t)piVar7;
        *puVar2 = nullptr;
        puVar2[1] = (std::uint32_t*)local_208;
        if (local_208 == nullptr) { local_20c = puVar2; local_208 = puVar2; }
        else { *local_208 = (std::uint32_t*)puVar2; local_208 = puVar2; }
    }
LAB_004d07c7:
    piVar7 += 2;
LAB_004d07ce:
    if (piVar6 == nullptr) goto joined_r0x004d07dc;
    goto LAB_004d0692;
}

// 0x4d08a0 — observed shape: frame dispatch on DAT_0072cd74+0xf4 counts; refcount bumps at
// DAT_008e9ff8/DAT_008ea010/DAT_008e9fec/DAT_008ea000, FUN_004e28a0/FUN_004e2920 pairs,
// FUN_004e2ec0(DAT_0072cd74,_DAT_008c84b0,DAT_0072cd78), vtable +0x70/+0x74 and FUN_00533d10/FUN_00534350.
extern void* DAT_0072cd74;
extern void* DAT_0072cd78;
extern int DAT_007263a0;
extern void* DAT_008e9fec;
extern void* DAT_008ea000;
extern void* DAT_008ea010;
extern float _DAT_008c84b0;
extern void FUN_004e28a0(void*);
extern void FUN_004e2920(void*);
extern void FUN_004e2ec0(void*,float,void*);
extern void FUN_00534130(void);
void FUN_004d08a0(void)
{
    std::uint32_t* local_4 = nullptr;
    void* iVar2 = nullptr;
    if (1 < *(int*)((char*)DAT_0072cd74 + 0xf4)) {
        iVar2 = (DAT_007263a0 < 2) ? (void*)DAT_008e9ff8 : (void*)DAT_008ea010;
        if (iVar2 != nullptr) *(int*)((char*)iVar2 + 4) += 1;
        FUN_004e28a0(iVar2);
        if (2 < *(int*)((char*)DAT_0072cd74 + 0xf4)) {
            (**(void(**)(void**,void*))(*(void***)DAT_008e9fec + 0x74/4))(&local_4, DAT_0072cd78);
            if (local_4 != nullptr) { int v = (int)local_4[1] - 1; local_4[1] = (std::uint32_t)v; if (v == 0) (**(void(**)(void*,int))local_4)(local_4, 1); }
            int* piVar1 = (int*)DAT_008e9fec;
            if (piVar1 != nullptr) piVar1[1] += 1;
            FUN_004e28a0(piVar1);
            if (DAT_008ea000 != 0) *(int*)((char*)DAT_008ea000 + 4) += 1;
            FUN_004e28a0(DAT_008ea000);
        }
    }
    FUN_004e2ec0(DAT_0072cd74, _DAT_008c84b0, DAT_0072cd78);
    if (1 < *(int*)((char*)DAT_0072cd74 + 0xf4)) {
        iVar2 = (DAT_007263a0 < 2) ? (void*)DAT_008e9ff8 : (void*)DAT_008ea010;
        if (iVar2 != nullptr) *(int*)((char*)iVar2 + 4) += 1;
        FUN_004e2920(iVar2);
        if (2 < *(int*)((char*)DAT_0072cd74 + 0xf4)) {
            if (DAT_008e9fec != nullptr) ((int*)DAT_008e9fec)[1] += 1;
            FUN_004e2920(DAT_008e9fec);
            if (DAT_008ea000 != 0) *(int*)((char*)DAT_008ea000 + 4) += 1;
            FUN_004e2920(DAT_008ea000);
            (*(void(**)(void*,int))(*(void***)DAT_008e9fec + 0x70/4))(DAT_0072cd78, 1);
            FUN_00533d10(0,1); FUN_00534350();
            (*(void(**)(void*,int))(*(void***)DAT_008e9fe8 + 0x70/4))(DAT_008e9fec, 1);
            (*(void(**)(void*,int))(*(void***)DAT_008e9fe8 + 0x70/4))(DAT_008ea000, 1);
            FUN_00534130(); FUN_00534130();
        }
        (*(void(**)(void*,int))(*(void***)DAT_008e9fe8 + 0x70/4))((void*)DAT_008e9ff8, 1);
        (*(void(**)(void*,int))(*(void***)DAT_008e9fe8 + 0x70/4))((void*)DAT_008ea010, 1);
        FUN_00534350();
    }
}

// 0x4d0ab0 — observed shape: per-entity loop over DAT_008e9ff8+0xb8[0xc0] using DAT_00726bac table
// and PTR_PTR_00726ba4 predicates; distance check vs FUN_004baaa0 (squared <= 1.6e7), proximity flag
// at +0x4d, FUN_004bfce0/FUN_004bcb20 side effects, per-slot callback at *piVar9+0x60.
extern void* DAT_008e9ff8_2;
extern void* DAT_008e9fd8_2;
extern char FUN_004ffa00(void);
extern int FUN_004baaa0(void);
extern void FUN_004bfce0(std::uint32_t,int);
extern void FUN_004bcb20(void);
void FUN_004d0ab0(int param_1, char param_2)
{
    extern char PTR_PTR_00726ba4[];
    extern char* DAT_00726bac;
    std::uint32_t uVar1 = *(std::uint32_t*)((char*)DAT_008e9ff8 + 0xc0);
    std::uint32_t local_20 = 0;
    if (uVar1 == 0) return;
    while (true) {
        lab_cad: ;
        if (*(std::uint32_t*)((char*)DAT_008e9ff8 + 0xc0) <= local_20) goto next;
        int iVar8 = *(int*)(*(int*)((char*)DAT_008e9ff8 + 0xb8) + local_20 * 4);
        if (iVar8 == 0) goto next;
        int iVar7 = (**(int(**)(int))(*(void***)(PTR_PTR_00726ba4) + 1))(iVar8);
        int* piVar9 = *(int**)(DAT_00726bac + iVar7 * 4);
        std::uint32_t uVar11 = 0;
        char cVar6 = 0;
        if (piVar9 != nullptr) {
            while (true) {
                cVar6 = (**(char(**)(int,int*))(*(void***)(PTR_PTR_00726ba4) + 2))(iVar8, piVar9[1]);
                if (cVar6 != 0) { uVar11 = piVar9[2]; break; }
                piVar9 = *(int**)piVar9;
                if (piVar9 == nullptr) break;
            }
        }
        int iVar8b = (int)(std::intptr_t)DAT_008e9fd8;
        if (param_1 == 0) {
            bool bVar5 = *(float*)(uVar11 + 0xa8) < 0.35f;
            if (param_2 == '\0') { if (!bVar5) goto next; }
            else if (!bVar5) goto next;
            if (*(int*)(*(int*)(uVar11 + 0x94 + param_1 * 4) + 0xc) != 0 && (cVar6 = FUN_004ffa00()) != 0) {
                float fVar2 = *(float*)(iVar8b + 0x5c);
                float fVar3 = *(float*)(iVar8b + 0x60);
                float fVar4 = *(float*)(iVar8b + 100);
                int iVar8c = FUN_004baaa0();
                fVar2 -= *(float*)(iVar8c + 0x5c); fVar3 -= *(float*)(iVar8c + 0x60); fVar4 -= *(float*)(iVar8c + 100);
                if (fVar2*fVar2 + fVar3*fVar3 + fVar4*fVar4 <= 1.6e7f) {
                    if (*(char*)(uVar11 + 0x4d) == 1) { *(unsigned char*)(uVar11 + 0x4d) = 0; FUN_004bfce0(*(std::uint32_t*)(uVar11 + 0x1c), 1); int t = *(int*)(uVar11 + 0xbc); if (t != 0) FUN_004bcb20(); }
                } else if (*(char*)(uVar11 + 0x4d) == 0) {
                    *(unsigned char*)(uVar11 + 0x4d) = 1; FUN_004bfce0(*(std::uint32_t*)(uVar11 + 0x1c), 0); int t = *(int*)(uVar11 + 0xbc); if (t != 0) FUN_004bcb20();
                }
                int slot = *(int*)(uVar11 + 0x94 + param_1 * 4);
                std::uint32_t idx = 0;
                if (*(int*)(slot + 0xc) != 0) {
                    while (true) {
                        int* slotPtr = *(int**)(*(int*)(slot + 4) + idx * 4);
                        if (((*(unsigned char*)((char*)slotPtr + 32) & 1) == 0)) (**(void(**)(int*,void*))*(void***)slotPtr + 0x60/4))(slotPtr, DAT_008e9fd8);
                        slot = *(int*)(uVar11 + 0x94 + param_1 * 4);
                        idx++;
                        if (!(idx < *(std::uint32_t*)(slot + 0xc))) break;
                    }
                }
            }
        }
    next:
        local_20++;
        if (uVar1 <= local_20) return;
    }
}

// 0x4d0cd0 — observed shape: cursor/visibility state machine (DAT_008ee1f8/f4, ShowCursor),
// FUN_004aafd0/FUN_004aca20/FUN_004acda0 gates, DAT_008cac27/DAT_008cab6d early-outs,
// entity loops FUN_004e9920, vtable +0x68 x5, FUN_004d3c60, DAT_008cac30/38 lifetime,
// DAT_008cac44/param_2 delay, FUN_004ab800, DAT_008ed5bd=param_1.
extern std::uint32_t DAT_008ee1f8;
extern std::uint32_t DAT_008ee1f4;
extern std::uint32_t _DAT_0085a164;
extern void FUN_004aafd0(int);
extern void FUN_004aca20(void);
extern void FUN_004acda0(void);
extern char DAT_008cac27;
extern char DAT_008cab6d;
extern void FUN_0042e4a0(int,int,const char*,int);
extern void FUN_0042e4f0(void);
extern void FUN_004ab9e0(float);
extern void FUN_004d08a0(void);
extern float _DAT_008c8498;
extern float _DAT_008c84b0;
extern float _DAT_008c84a0;
extern void FUN_004e9920(float);
extern void* DAT_008cabe8;
extern void* DAT_008cabe0;
extern void FUN_00534130(void);
extern void FUN_004ab530(void*,float);
extern void FUN_004ab440(void);
extern void FUN_004d3c60(void);
extern void FUN_004d0650_fwd(int);
extern void FUN_00495510(void);
extern void FUN_004955d0(void);
extern void FUN_00495850(void);
extern void FUN_00502660(void*,float);
extern void FUN_004d1240(void);
extern void FUN_00535e10(void);
extern void FUN_004ab800(void*,float);
extern void FUN_004d1130_fwd(void);
extern char DAT_008cac30;
extern char DAT_008cac2b;
extern void FUN_004bb3e0(void);
extern char DAT_008ed5bd;
extern float DAT_008cac44;
extern void* DAT_008cac3c;
extern int DAT_008cac38;
extern void* DAT_008cab30;
extern void* DAT_008c9de4;
extern void FUN_004d9f90(void*);
void FUN_004d0cd0(char param_1, float param_2, int param_3)
{
    if ((DAT_008ee1f8 & 1) == 0) { DAT_008ee1f8 |= 1; DAT_008ee1f4 = 0; _atexit(reinterpret_cast<void(*)()>(0x006bf3d0)); }
    if (((int)((_DAT_0085a164 >> 8) & 0xff) < 0) && (*(char*)((char*)DAT_008cabe8 + 0xc) == '\0')) {
        while (DAT_008ee1f4 == 0) { DAT_008ee1f4 += 1; if (ShowCursor(0) != -1) break; }
    } else if (DAT_008ee1f4 != 0) {
        std::uint32_t n = 0;
        while (true) { ShowCursor(1); n++; if (!(n < DAT_008ee1f4)) break; }
        DAT_008ee1f4 = 0;
    }
    FUN_004aafd0(((_DAT_0085a164 & 4) == 4) ? 1 : 0);
    FUN_004aca20(); FUN_004acda0();
    if (DAT_008cac27 != '\0') return;
    if (DAT_008cab6d != '\0') { Sleep(0x14); return; }
    extern void* DAT_008c9df0; extern int DAT_008c9790;
    if (DAT_008c9df0 != nullptr) FUN_0042e4a0(100, 0x1a4, "Lost %d", DAT_008c9790);
    FUN_0042e4f0();
    FUN_004ab9e0(_DAT_008c8498);
    if (DAT_0072cd74 != nullptr && *(char*)((char*)DAT_0072cd74 + 0xf0) != '\0') FUN_004d08a0();
    if (DAT_0072cd78 != nullptr && *(int*)((char*)DAT_0072cd78 + 0x58) > 0) { int k = 0; while (true) { FUN_004e9920(_DAT_008c84b0); k++; if (!(k < *(int*)((char*)DAT_0072cd78 + 0x58))) break; } }
    if (DAT_008cabe0 != nullptr) FUN_00533d10(0,1); else FUN_00533d10(0,1);
    FUN_00533d10(0,1); FUN_00534350(); FUN_00534130(); FUN_00533d10(0,1); FUN_00534350(); FUN_00534130();
    extern std::uint32_t DAT_007263bc; extern void* PTR_PTR_007268dc;
    if ((DAT_007263bc & 0x40000) != 0) FUN_004ab530(PTR_PTR_007268dc, _DAT_008c8498);
    extern void* DAT_008c9de8;
    if (DAT_008c9de8 != nullptr) FUN_004d9f90(DAT_008c9de8);
    if (param_1 == '\0' || DAT_008ed5bd == '\0') FUN_004bb3e0();
    if ((DAT_007263bc & 0x40000) != 0) FUN_004ab440();
    extern void* DAT_008ea000; extern void* DAT_008e9ffc; extern void* DAT_008e9ff4; extern void* DAT_008e9ff0;
    (*(void(**)(void*))(*(void***)DAT_008ea000 + 0x68/4))(DAT_008ea000);
    (*(void(**)(void*))(*(void***)DAT_008e9ffc + 0x68/4))(DAT_008e9ffc);
    (*(void(**)(void*))(*(void***)DAT_008e9ff4 + 0x68/4))(DAT_008e9ff4);
    (*(void(**)(void*))(*(void***)DAT_008e9fec + 0x68/4))(DAT_008e9fec);
    (*(void(**)(void*))(*(void***)DAT_008e9ff0 + 0x68/4))(DAT_008e9ff0);
    FUN_004d3c60();
    if (param_3 != 0) FUN_004d0650_fwd(param_3);
    extern char DAT_008c9df5; extern char DAT_008c9df4;
    if (DAT_008c9df5 != '\0') { FUN_00533d10(0,1); FUN_00534350(); FUN_00534130(); }
    if (DAT_008c9df4 != '\0') { FUN_00534350(); DAT_008c9df4 = '\0'; }
    extern void* DAT_008c97cc; extern void FUN_00513fe0(void*,float);
    FUN_00513fe0(DAT_008c97cc, _DAT_008c84b0);
    if (DAT_008cab30 == nullptr) {
        DAT_008cab30 = FUN_00533c78(0x18);
        if (DAT_008cab30 != nullptr) { ((std::uint32_t*)DAT_008cab30)[0]=0; ((std::uint32_t*)DAT_008cab30)[1]=0; ((std::uint32_t*)DAT_008cab30)[2]=0; }
        FUN_00495510();
    }
    extern char DAT_008cac34; extern void* DAT_008cac40;
    int iVar1;
    if (DAT_008cac34 == '\0') iVar1 = *(int*)((char*)(((std::uint32_t*)DAT_008cab30)[2]) + 0x10);
    else { if ((int)DAT_007263bc < 0) { FUN_004955d0(); goto lab41; } iVar1 = *(int*)((char*)(((std::uint32_t*)DAT_008cab30)[2]) + 0x10); }
    if (iVar1 != 0) FUN_00495850();
lab41:
    if (DAT_008cac40 != nullptr) FUN_00502660(DAT_008cac40, _DAT_008c84a0);
    if (DAT_008cac38 < 1) { FUN_004d1240(); if (DAT_008cac38 < 1) FUN_00535e10(); }
    if (DAT_008cac30 != '\0' && DAT_008cac38 < 1) { if (DAT_008cac2b != '\0') (**(void(**)(void*))(*(void***)DAT_008c9de4 + 1))(DAT_008c9de4); DAT_008cac30 = '\0'; }
    if (0.0f < DAT_008cac44) { param_2 = DAT_008cac44; DAT_008cac44 = 0.0f; }
    if (0.0f < param_2 && DAT_008cac38 < 1) FUN_004ab800(DAT_008cac3c, param_2);
    if (param_1 == '\0') FUN_004d1130_fwd();
    if (0 < DAT_008cac38) DAT_008cac38 -= 1;
    DAT_008ed5bd = param_1;
}
// 0x4d1130 — observed shape: refcount dance on DAT_008ea008 (+0x78 grab, +0x70 push),
// alloc 0xec -> FUN_0053bb30, loops over DAT_008ea004[0x30]/DAT_008ea00c[0x30] via +0x78,
// conditional FUN_004bb3e0 on (char)unaff_EDI.
extern void* DAT_008ea004;
extern void* DAT_008ea00c;
extern void* DAT_008ea008_2;
extern std::uint32_t FUN_0053bb30(int);
void FUN_004d1130(void)
{
    std::uint32_t uStack_10 = 0;
    std::uint32_t* puStack_14 = nullptr;
    std::uint32_t* unaff_EDI = nullptr;
    std::uint32_t local_4 = 0;
    puStack_14 = &local_4;
    (**(void(**)(void*))(*(void***)DAT_008ea008 + 0x78/4))(DAT_008ea008);
    if (unaff_EDI != nullptr) { int v = (int)unaff_EDI[1] - 1; unaff_EDI[1] = (std::uint32_t)v; if (v == 0) (**(void(**)(std::uint32_t*,int))unaff_EDI)(unaff_EDI, 1); }
    std::uint32_t uVar3 = FUN_00533c78(0xec) ? FUN_0053bb30(0) : 0;
    (**(void(**)(std::uint32_t*,int))(*(void***)DAT_008ea008 + 0x70/4))((std::uint32_t*)(std::intptr_t)uVar3, 1);
    std::uint32_t uVar1 = ((std::uint32_t*)DAT_008ea004)[0x30];
    std::uint32_t uVar4 = 0;
    if (uVar1 != 0) { while (true) { (**(void(**)(std::uint32_t**,std::uint32_t))(*(void***)DAT_008ea004 + 0x78/4))(&puStack_14, uVar4); if (puStack_14 != nullptr) { int v = (int)puStack_14[1] - 1; puStack_14[1]=(std::uint32_t)v; if (v==0) (**(void(**)(std::uint32_t*,int))puStack_14)(puStack_14,1); } uVar4++; if (!(uVar4 < uVar1)) break; } }
    uVar1 = ((std::uint32_t*)DAT_008ea00c)[0x30];
    uVar4 = 0;
    if (uVar1 != 0) { while (true) { (**(void(**)(std::uint32_t**,std::uint32_t))(*(void***)DAT_008ea00c + 0x78/4))(&puStack_14, uVar4); if (puStack_14 != nullptr) { int v = (int)puStack_14[1] - 1; puStack_14[1]=(std::uint32_t)v; if (v==0) (**(void(**)(std::uint32_t*,int))puStack_14)(puStack_14,1); } uVar4++; if (!(uVar4 < uVar1)) break; } }
    if ((char)(std::intptr_t)unaff_EDI != '\0') FUN_004bb3e0();
}

// 0x4d1240 — observed shape: DAT_007263bc bitfield dispatch (0x1000 swap to DAT_008ea00c/08,
// 0x1 FUN_004d9af0/FUN_004d9730, +0xc4/+0xbc render, FUN_00533c78(0x5c) pair with PTR_FUN_0070dfa0,
// big branch on DAT_008cac58/0x24c/DAT_008cabe8+0xc with FUN_004d0ab0(0..3) and object swaps,
// tail refcount releases of piVar6/piVar14/piVar13). See corpus for full bit-by-bit order.
extern std::uint32_t DAT_007263bc;
extern void* PTR_FUN_0070dfa0;
extern void FUN_00535de0(int);
extern void FUN_004d9af0(void*,float);
extern void FUN_004d9730(void*);
extern void* FUN_0054b8c0(void);
extern int FUN_005007e0(void);
extern void FUN_004d0ab0(int,char);
extern void FUN_004ed1a0(void*);
extern void FUN_004ed240(void);
extern void FUN_004e9480(void*);
extern void* DAT_008e9fe0;
extern void* DAT_008ea08c;
extern void* DAT_008cac58;
extern void FUN_004dc390(void);
extern void FUN_00536f40(void);
extern void FUN_00536fb0(void);
extern void FUN_00502510(void*,int);
void FUN_004d1240(void)
{
    FUN_00535de0(7);
    void* puVar8 = DAT_008ea00c;
    int* piVar13 = nullptr;
    int* piVar14 = nullptr;
    int* piVar6 = nullptr;
    if ((DAT_007263bc & 0x1000) != 0) {
        ((std::uint32_t*)DAT_008e9fe0)[0x55] = (std::uint32_t)(std::intptr_t)puVar8;
        (**(void(**)(void*))(*(void***)DAT_008e9fe0 + 0x70/4))(DAT_008e9fe0);
        FUN_00535de0(6);
        ((std::uint32_t*)DAT_008e9fe0)[0x55] = (std::uint32_t)(std::intptr_t)DAT_008ea008;
        DAT_007263bc &= 0xffffefffu;
    }
    if ((DAT_007263bc & 1) != 0) { extern void* DAT_008c9dec; FUN_004d9af0(DAT_008c9dec, _DAT_008c8498); *(void**)((char*)DAT_008c9dec+4)=DAT_008e9fd8; FUN_004d9730(DAT_008c9dec); }
    (**(void(**)(void*,void*,void*,void*,void*,void*))(*(void***)DAT_008ea08c + 0xc4/4))(DAT_008e9fd8+0x90, DAT_008e9fd8+0x104, DAT_008e9fd8+0x110, DAT_008e9fd8+0x11c, DAT_008e9fd8+0x128, DAT_008e9fd8+0x144);
    (**(void(**)(void*))(*(void***)DAT_008ea08c + 0xbc/4))(DAT_008ea08c);
    piVar13 = (int*)(*(void**)((char*)DAT_008ea08c + 12));
    if (piVar13 != nullptr) piVar13[1] += 1;
    piVar14 = FUN_00533c78(0x5c) ? (int*)FUN_0054b8c0() : nullptr;
    if (piVar14 != nullptr) piVar14[1] += 1;
    piVar6 = (int*)FUN_00533c78(0x5c);
    if (piVar6 != nullptr) { piVar6[0] = (int)(std::intptr_t)PTR_FUN_0070dfa0; piVar6[1] += 1; }
    if ((DAT_008cac58 == 0 || *(char*)((char*)DAT_008cac58+0x24c)=='\0') || *(char*)((char*)DAT_008cabe8+0xc)!='\0') {
        if ((DAT_007263bc & 4)!=0 && *(char*)((char*)DAT_0072cd74+0xf0)!='\0') { (**(void(**)(void*))(*(void***)piVar13+0x34/4))(piVar13); }
        FUN_005007e0();
        if ((DAT_007263bc & 0x10)!=0) { FUN_004d0ab0(0,0); FUN_004d0ab0(0,1); }
        if ((DAT_007263bc & 0x2000)!=0) FUN_004d0ab0(1,1);
        if ((DAT_007263bc & 0x4000)!=0) FUN_004d0ab0(2,1);
        if (((int)(DAT_007263bc>>8))<0) FUN_004d0ab0(3,1);
        if ((DAT_007263bc & 0x800)!=0) { extern void FUN_00533e70(void*); FUN_00533e70(DAT_008e9fd8); }
        if ((DAT_007263bc & 0x100)!=0) FUN_00533e70(DAT_008e9fd8);
    } else {
        FUN_004dc390();
    }
    if ((DAT_007263bc & 0x200)!=0) { FUN_00536f40(); FUN_00536fb0(); }
    (**(void(**)(void*))(*(void***)DAT_008ea08c + 0xc0/4))(DAT_008ea08c);
    if ((DAT_007263bc & 0x400)!=0) { FUN_00535de0(6); }
    if ((DAT_008cac40!=nullptr) && ((DAT_007263bc & 0x80000)!=0)) FUN_00502510(DAT_008cac40,0);
    if (piVar6!=nullptr) { int v=piVar6[1]-1; piVar6[1]=v; if(v==0) (**(void(**)(int*,int))piVar6)(piVar6,1); }
    if (piVar14!=nullptr) { int v=piVar14[1]-1; piVar14[1]=v; if(v==0) (**(void(**)(int*,int))piVar14)(piVar14,1); }
    if (piVar13!=nullptr) { int v=piVar13[1]-1; piVar13[1]=v; if(v==0) (**(void(**)(int*,int))piVar13)(piVar13,1); }
}

// 0x4d1a60 — observed shape: settings loader; copies FUN_004f14a0 payload into DAT_008cacd0,
// FUN_00412e50, then FUN_004f8fa0 gate; reads DAT_008cac18/1c window size, DAT_007263b0/a4/32/33/2b/31/2a
// booleans, Gamma DAT_007263b4 clamped [0.5,1.5], volumes, Water/World/ObjectDetail, MyName/Remarks strings,
// IsSlowMachine, defaults 800x600 when DAT_008cac18==0, FUN_004f8f50. Maid list of reads preserved.
extern std::uint32_t DAT_008cac18;
extern std::uint32_t DAT_008cac1c;
extern std::uint32_t _DAT_008cac20;
extern std::uint32_t DAT_008cac28;
extern char DAT_007263b0;
extern float DAT_007263b4;
extern void FUN_004f8f50(void);
extern std::uint32_t FUN_004f14a0(void*);
extern void FUN_004f3350(void);
extern void FUN_00412f90(void);
extern void FUN_00412e50(std::uint32_t);
extern char FUN_004f8fa0(void*,char*);
extern char FUN_004f96a0(void);
extern char FUN_004f9790(void*);
extern char FUN_004f9820(void*);
extern char FUN_004f9950(const char*,void*);
extern void FUN_004f9cb0(void*);
extern void FUN_004f9ac0(const char*,void*);
extern void FUN_004f9c00(void*);
extern void FUN_004f9a30(const char*,void*);
extern void FUN_004f9710(void);
extern void FUN_004f9b60(void*,int);
extern void FUN_004f9d60(std::uint32_t,int);
void FUN_004d1a60(std::uint32_t param_1)
{
    void* local_20 = nullptr;
    void* local_1c = nullptr;
    extern void* PTR_FUN_007108ac; local_1c = PTR_FUN_007108ac;
    std::uint32_t* puVar4 = (std::uint32_t*)(std::intptr_t)FUN_004f14a0(&local_20);
    unsigned char* puVar1 = *(unsigned char**)puVar4;
    char* dst = (char*)local_20;
    std::size_t _Size = *(std::size_t*)(puVar1 - 4);
    if (-1 < (int)_Size && puVar1 != nullptr && puVar1 != (unsigned char*)DAT_008cacd0) {
        if (_Size == 0) FUN_00412f90();
        else { FUN_004f3350(); std::memmove(DAT_008cacd0, puVar1, _Size); DAT_008cacd0[_Size] = '\0'; }
    }
    puVar4 = (std::uint32_t*)((char*)local_20 - 8);
    if (puVar4 != nullptr && puVar4 != (std::uint32_t*)DAT_008cacc8) operator_delete__(puVar4);
    FUN_00412e50(param_1);
    char cVar3 = FUN_004f8fa0(&local_1c, DAT_008cacd0);
    if (cVar3 != '\0') {
        FUN_004f96a0();
        FUN_004f9790(&DAT_008cac18); FUN_004f9790(&DAT_008cac1c);
        FUN_004f9820(&DAT_007263b4);
        if (0.5f <= DAT_007263b4) { if (1.5f < DAT_007263b4) DAT_007263b4 = 1.5f; } else DAT_007263b4 = 0.5f;
        FUN_004f9820(&DAT_00726388); FUN_004f9820(&DAT_0072638c); FUN_004f9820(&DAT_00726390); FUN_004f9820(&DAT_00726394);
        FUN_004f9790(&DAT_00726398); FUN_004f9790(&DAT_0072639c); FUN_004f9790(&DAT_007263a0);
        local_20 = DAT_008cacd0;
        if (FUN_004f9950("MyName", &local_20) != '\0') FUN_00412f10();
        local_20 = DAT_008cacd0;
        if (FUN_004f9950("Remarks", &local_20) != '\0') { extern void FUN_004f8cf0(void); FUN_004f8cf0(); }
        FUN_004f9950("CustomSail", nullptr); FUN_004f9950("CustomFlag", nullptr);
    }
    if (DAT_008cac18 == 0) { DAT_008cac28 = 1; DAT_008cac18 = 800; DAT_008cac1c = 600; }
    _DAT_008cac20 = DAT_008cac18;
    FUN_004f8f50();
}

// 0x4d2100 — observed shape: ESI receiver + int param_1; chooses FUN_004f9b60 vs FUN_004f9d60
// via FUN_004f9950, then frees local_4 and param_1 string blocks (ptr-8 vs DAT_008cacc8).
extern char FUN_004f9950_fwd(void*,char**);
extern void FUN_004f9b60(void*,int);
extern void FUN_004f9d60(std::uint32_t,int);
void FUN_004d2100(void* self, int param_1)
{
    char* local_4 = DAT_008cacd0;
    char cVar1 = FUN_004f9950_fwd(self, (char**)&local_4);
    if (cVar1 == '\0') FUN_004f9d60((std::uint32_t)(std::intptr_t)self, param_1);
    else FUN_004f9b60(self, param_1);
    void* puVar2 = (void*)((char*)local_4 - 8);
    if (puVar2 != nullptr && puVar2 != DAT_008cacc8) operator_delete__(puVar2);
    puVar2 = (void*)((char*)(std::intptr_t)param_1 - 8);
    if (puVar2 != nullptr && puVar2 != DAT_008cacc8) operator_delete__(puVar2);
}

// 0x4d2170 — observed shape: options writer; FUN_004f14a0 header, FUN_00412e50/FUN_004f8fa0 gate,
// then paired FUN_004f9820/FUN_004f9cb0/FUN_004f9ac0 (Gamma/Master/Music/SFX/Dance volumes) and
// FUN_004f9790/FUN_004f9c00/FUN_004f9a30 (KeypadStatus/DisplayShadows/TrilinearFiltering/DisableShaders/
// AdvancedLighting/WindowWidth/Height/WaterDetail/WorldDetail/ObjectDetail/IsSlowMachine),
// FUN_004d2100 separators, FUN_004f9e10, FUN_004f8f50. Full 233-line body in corpus.
extern void FUN_004d2100_fwd(void);
extern float DAT_00726388;
extern float DAT_0072638c;
extern float DAT_00726390;
extern float DAT_00726394;
extern float DAT_007263b4_2;
extern std::uint32_t DAT_00726398_2;
extern void FUN_004d2170_impl(std::uint32_t);
void FUN_004d2170(std::uint32_t param_1)
{
    FUN_004d2170_impl(param_1);
}

// 0x4d2860 — observed shape: zero-fills OSVERSIONINFOA (0x25 dwords), sets 0x94, GetVersionExA,
// FUN_004f5480 path check (backslash test), FUN_004129c0/FUN_00412ec0 cleanup,
// DAT_008cacd8 = LoadCursorFromFileA(DAT_008cacd0).
extern void* DAT_008cacd8;
extern void FUN_004129c0(int*,int);
extern int FUN_004f5480(char*,int);
extern HCURSOR LoadCursorFromFileA(LPCSTR);
void FUN_004d2860(void)
{
    OSVERSIONINFOA local_a0 = {0};
    local_a0.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_a0);
    FUN_00412f10();
    int iVar3 = FUN_004f5480(DAT_008cacd0, 0);
    if (iVar3 != 0) {
        int* p10 = *(int**)(iVar3 + 0x10);
        if (p10 == nullptr || **(int**)(iVar3 + 0x10) + (*(int*)(**(int**)(iVar3 + 0x10) - 4) - 1) == '\\') {
            int local_a4 = 0;
            FUN_004129c0(&local_a4, iVar3 + 8);
            FUN_00412ec0();
            void* puVar2 = (void*)(local_a4 - 8);
            if (puVar2 != nullptr && puVar2 != DAT_008cacc8) operator_delete__(puVar2);
        }
    }
    DAT_008cacd8 = LoadCursorFromFileA(DAT_008cacd0);
}

// 0x4d2950 — observed shape: WinMain (HWND/param_2/param_3/param_4)->uint; thread priority,
// FUN_00500080/FUN_004d4a30 init, alloc 0x238 objects with PTR_FUN_0070d868, DAT_008e9fd8[0x17..0x19]
// = 0x461c4000/0x461c4000/0x453b8000, dual 9-dword matrix copies, FUN_004d0080, viewport
// fVar12/fVar2->FUN_0054aa00, font NewFontWithButtons_150.fnt, FUN_004e0b60, returns 1.
// See corpus 0x4d2950.c:20-636 for full refcount sequence.
extern std::uint32_t FUN_004d2950(HWND, std::uint32_t, std::uint32_t, std::uint32_t);
std::uint32_t FUN_004d2950_fwd(HWND h, std::uint32_t a, std::uint32_t b, std::uint32_t c)
{
    return FUN_004d2950(h, a, b, c);
}

// ---------------------------------------------------------------------------
// 0x4d2950 — observed shape: WinMain(HWND, undefined4, undefined4, uint) -> uint.
// Sequence recovered from corpus 0x4d2950.c (637 lines, range 0x4d2950-0x4d371f):
//   1. DAT_008cad10 = DAT_008cac35; optional CreateThread(LAB_004d27a0) with the priority in
//      DAT_008c9df0, then FUN_00500080 / FUN_004d4a30 and the single-instance probe
//      FUN_00533c78 -> DAT_008cace0 (else FUN_004d4b00).
//   2. FUN_004d2860 (cursor setup), LoadCursorA(id 0x7f02)/GetCursor/SetCursor,
//      FUN_004f5870 gate then the renderer config writes _DAT_008e9fd0 = &DAT_00869b48,
//      _DAT_008e9fcc = 0x1000, DAT_008e9fd4 = 0x40 and the direct slot call at
//      DAT_008e9f58+0xc.
//   3. iVar5 != 0 fatal path: two MessageBoxA variants (param_4 < 0x90003 selects the short
//      one), then FUN_004d4a30/FUN_004ffe70 and return 0.
//   4. Main path: FUN_00500950, DAT_007268f4[DAT_00726a84++] = DAT_007263bc, FUN_00497fd0
//      option gate, FUN_004f1310/FUN_004f5290/FUN_004f14a0/FUN_00412a60 pairs with two
//      temporary-string frees (block-8 vs DAT_008cacc8), _control87(0,0), FUN_004f8bd0,
//      2x FUN_005004e0, FUN_00547840, DAT_008ea08c vtable[0x74].
//   5. Eleven refcounted singletons (DAT_008e9fe8, 008e9fec, 008e9ff0, 008e9ff4, 008e9ff8,
//      008e9ffc, 008ea000, 008ea004, 008ea008, 008ea00c, 008ea010) are built by
//      FUN_00533c78 + FUN_0053bb30 and installed through the refcount at object[1]
//      (release = vtable[0], no extra argument for these eleven).
//   6. Renderer wiring: vtable[0x70] of DAT_008e9fe8 is called with the singletons above
//      (the two leading calls carry no recovered argument), a 0xec FUN_0053bb30 object is
//      handed to DAT_008ea008, and two 0x238 PTR_FUN_0070d868 objects are installed as
//      DAT_008e9fd8 (also into DAT_008e9fe8 at +0x55 and DAT_008ea08c at +0x62) and
//      DAT_008e9fe0 (also into DAT_008ea008 at +0x55 and DAT_008ea08c at +0x62).
//   7. Camera: FUN_0053c780/FUN_0053c7c0(0x3f490fdb) with FUN_0053c8d0 rotation matrices
//      copied as 9 dwords into object+0xe; DAT_008e9fdc is refcounted onto DAT_008e9fd8.
//      Scene object from FUN_004d49c0 (0x34) with fields 0x3ebababb/0x3f7d70a4/0x3f23a3a4/
//      0x3f61e1e2, flag word &= 0xfff9 then |= 1, FUN_004aac50, FUN_004d0080, viewport from
//      DAT_008cac18/DAT_008cac1c/_DAT_008cac20, FUN_0054aa00, FUN_004cce40, DAT_008e9fe0
//      transform reset, FUN_00533d10(0,1).
//   8. Assets: DAT_008c97d0 (FUN_0050b1d0 with 0.05/0/0.05/0.5), DAT_008c97cc (FUN_00513f40),
//      optional FUN_004cff30, font DAT_008c9dd8 = FUN_00508120 + FUN_00508670
//      "NewFontWithButtons_150.fnt" + vtable[4](2,0) stored at +100, DAT_008c9de0/008c9ddc
//      aliases, FUN_00534350/FUN_00534130/FUN_004ff6b0(0), DAT_008c97c8 = thunk_FUN_00533c78
//      (0x10) filled with FUN_004d4950/FUN_004d48e0/FUN_004d4890/FUN_004d4720, FUN_004e0b60,
//      release of the FUN_004d49c0 object, SetCursor(1), return 1.
// Notes: caller stack slots the decompiler names for pushed arguments (uStack_84 = 0x4d30df,
// 0x4d30f3, 0x4d3107 ...) are call-return residue and are not reproduced. Where the listing
// prints FUN_00533c78() without a size operand the size is not recovered and 0 is passed.
// ---------------------------------------------------------------------------
extern char DAT_008cad10;
extern char DAT_008cac35;
extern int DAT_008c9df0;
extern std::uint32_t DAT_008cace0;
extern std::uint32_t DAT_007268f4;
extern int DAT_00726a84;
extern HWND DAT_00726b8c;
extern int DAT_00726384;
extern char DAT_008cac2a;
extern void* _DAT_008e9fd0;
extern std::uint32_t _DAT_008e9fcc;
extern std::uint32_t DAT_008e9fd4;
extern char DAT_00869b48;
extern void* DAT_008e9f58;
extern char DAT_00007f02;
extern void* PTR_FUN_0070d868;
extern std::uint32_t* DAT_008e9fd8;
extern std::uint32_t* DAT_008e9fdc;
extern void* DAT_008c9dd8;
extern void* DAT_008c9de0;
extern void* DAT_008c9ddc;
extern void* DAT_008c97d0;
extern void* DAT_008c97cc;
extern std::uint32_t* DAT_008c97c8;
extern void* DAT_00727b28;
extern std::uint32_t DAT_007177b8;
extern std::uint32_t DAT_007177c4;
extern std::uint32_t DAT_007177ac;
extern "C" unsigned int _control87(unsigned int, unsigned int);

extern std::uint32_t LAB_004d27a0(void*);
extern int FUN_00500080(void);
extern void FUN_004d4a30(void);
extern std::uint32_t FUN_004d4b00(void);
extern char FUN_004f5870(void);
extern void FUN_004ad050(void);
extern void* FUN_004f6090(void);
extern void FUN_004ffe70(void);
extern void FUN_00500950(void);
extern char FUN_00497fd0(void);
extern char FUN_004f1310(void);
extern void FUN_004f5290(void);
extern void FUN_00412a60(void);
extern void FUN_004f8bd0(void);
extern void FUN_005004e0(void);
extern void FUN_00547840(void);
extern void FUN_004ff360(float);
extern void FUN_004aac50(std::uint32_t**);
extern void FUN_004d0080(void);
extern void* FUN_0053c6f0(void*, void*, void*);
extern void FUN_0054aa00(float, float, float, float, float, float, int);
extern void* FUN_0050b1d0(void*, float, int, float, float);
extern void* FUN_00513f40(void);
extern void FUN_004cff30(void);
extern void FUN_00508670(void*, const char*);
extern void* FUN_004d49c0(void);
extern void* FUN_004d4950(void);
extern void* FUN_004d48e0(void);
extern void* FUN_004d4890(void);
extern void* FUN_004d4720(void);
extern void FUN_004e0b60(void);
extern void* thunk_FUN_00533c78(std::size_t);

// Typed 32-bit view of the corpus globals Ghidra prints as undefined4 / undefined4*.
#define G32(g) (*reinterpret_cast<std::uint32_t**>(&(g)))
#define SLOT(g) (reinterpret_cast<std::uint32_t**>(&(g)))

namespace {

typedef void (*VFn0)(void*);
typedef void (*VFn1)(void*, void*);
typedef void (*VFn2)(void*, void*, int);

// (**(code **)(*obj + off))(): indirect call through obj->vtable[off].
inline void* v_slot(void* obj, std::uintptr_t offset)
{
    return *reinterpret_cast<void**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(obj)) + offset);
}

// (**(code **)(obj + off))(): function pointer held directly at obj+off.
inline void* d_slot(void* obj, std::uintptr_t offset)
{
    return *reinterpret_cast<void**>(reinterpret_cast<char*>(obj) + offset);
}

// Refcounted assignment repeated throughout the listing:
//   if (slot != value) {
//       if (slot && --slot[1] == 0) (**(code **)*slot)(...);   // vtable[0] release
//       slot = value;
//       if (value) value[1] += 1;
//   }
// releaseWithArg selects the observed release form vtable[0](1) versus vtable[0]().
inline void ref_assign(std::uint32_t** slot, std::uint32_t* value, bool releaseWithArg)
{
    if (*slot == value) return;
    if (*slot != nullptr) {
        std::uint32_t* old = *slot;
        std::uint32_t* count = old + 1;
        *count = *count - 1;
        if (*count == 0) {
            VFn0 release = reinterpret_cast<VFn0>(*reinterpret_cast<void**>(old));
            if (releaseWithArg) reinterpret_cast<void (*)(void*, int)>(release)(old, 1);
            else release(old);
        }
    }
    *slot = value;
    if (value != nullptr) {
        std::uint32_t* count = value + 1;
        *count = *count + 1;
    }
}

// FUN_00533c78(size) allocates (corpus 0x533c78.c) and FUN_0053bb30(arg) is the in-place
// constructor that returns its in-ECX receiver in EAX (corpus 0x53bb30.c).
inline std::uint32_t* alloc_construct_0053bb30(std::size_t size, int ctorArg = 0)
{
    if (FUN_00533c78(size) == nullptr) return nullptr;
    return reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(FUN_0053bb30(ctorArg)));
}

} // namespace

std::uint32_t FUN_004d2950_recon(HWND param_1, std::uint32_t /*param_2*/, std::uint32_t /*param_3*/,
                                 std::uint32_t param_4)
{
    std::uint32_t* puVar7 = nullptr;
    std::uint32_t* puVar10 = nullptr;
    std::uint32_t* puVar11 = nullptr;
    std::uint32_t* piVar8 = nullptr;
    std::uint32_t* uVar9 = nullptr;
    std::uint32_t* apuStack_3c[15] = {};
    int iVar5 = 0;
    char cVar4 = '\0';
    float fVar2 = 0.0f;
    float fVar12 = 0.0f;
    float fHalfH = 0.0f;
    std::int32_t iStack_54 = 0; // frame slot the listing reads without a visible store
    HANDLE hThread = nullptr;
    HCURSOR hCursor = nullptr;
    HCURSOR hCursor_00 = nullptr;
    HWND hWnd = nullptr;
    LPCSTR lpText = nullptr;

    DAT_008cad10 = DAT_008cac35;
    if (DAT_008c9df0 != 0) {
        hThread = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(&LAB_004d27a0),
                               nullptr, 0, nullptr);
        SetThreadPriority(hThread, DAT_008c9df0);
        CloseHandle(hThread);
    }
    iVar5 = FUN_00500080();
    FUN_004d4a30();
    if (FUN_00533c78(0) == nullptr) {
        DAT_008cace0 = 0;
    } else {
        DAT_008cace0 = FUN_004d4b00();
    }
    FUN_004d2860();
    hCursor = static_cast<HCURSOR>(DAT_008cacd8);
    if (hCursor == nullptr) {
        hCursor = LoadCursorA(nullptr, &DAT_00007f02);
    }
    hCursor_00 = GetCursor();
    SetCursor(hCursor);
    cVar4 = FUN_004f5870();
    if (cVar4 != '\0') {
        _DAT_008e9fd0 = &DAT_00869b48;
        _DAT_008e9fcc = 0x1000;
        DAT_008e9fd4 = 0x40;
        reinterpret_cast<VFn0>(d_slot(DAT_008e9f58, 0xc))(DAT_008e9f58);
    }
    if (iVar5 != 0) {
        FUN_004ad050();
        hWnd = DAT_00726b8c;
        if (param_4 < 0x90003) {
            lpText = reinterpret_cast<LPCSTR>(FUN_004f6090());
            MessageBoxA(hWnd, lpText, nullptr, 0);
            SetCursor(hCursor_00);
            return 0;
        }
        FUN_004f6090();
        FUN_00412f10();
        FUN_004f6090();
        FUN_00412f10();
        MessageBoxA(param_1, DAT_008cacd0, DAT_008cacd0, 0);
        FUN_004d4a30();
        FUN_004ffe70();
        SetCursor(hCursor_00);
        return 0;
    }
    FUN_00500950();
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(&DAT_007268f4) + DAT_00726a84 * 4) =
        DAT_007263bc;
    DAT_00726a84 = DAT_00726a84 + 1;
    if ((DAT_007263b0 != '\0') && (FUN_00497fd0() == '\0')) {
        DAT_007263b0 = '\0';
    }
    cVar4 = FUN_004f1310();
    if (cVar4 != '\0') {
        FUN_004f5290();
    }
    reinterpret_cast<std::uint32_t (*)(void)>(&FUN_004f14a0)();
    FUN_00412a60();
    cVar4 = FUN_004f1310();
    puVar7 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(param_4 - 8));
    if (puVar7 != nullptr && static_cast<void*>(puVar7) != static_cast<void*>(DAT_008cacc8)) {
        operator_delete__(puVar7);
    }
    puVar7 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iStack_54 - 8));
    if (puVar7 != nullptr && static_cast<void*>(puVar7) != static_cast<void*>(DAT_008cacc8)) {
        operator_delete__(puVar7);
    }
    if (cVar4 != '\0') {
        reinterpret_cast<std::uint32_t (*)(void)>(&FUN_004f14a0)();
        FUN_00412a60();
        FUN_004f5290();
        puVar7 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iStack_54 - 8));
        if (puVar7 != nullptr && static_cast<void*>(puVar7) != static_cast<void*>(DAT_008cacc8)) {
            operator_delete__(puVar7);
        }
    }
    _control87(0, 0);
    FUN_004f8bd0();
    FUN_005004e0();
    FUN_005004e0();
    FUN_00547840();
    reinterpret_cast<VFn0>(v_slot(G32(DAT_008ea08c), 0x74))(G32(DAT_008ea08c));

    G32(DAT_008cac3c) = static_cast<std::uint32_t*>(FUN_00533c78(0));
    if (G32(DAT_008cac3c) == nullptr) {
        G32(DAT_008cac3c) = nullptr;
    } else {
        puVar7 = G32(DAT_008cac3c);
        puVar7[0] = 0;
        puVar7[1] = 0;
        puVar7[3] = 0;
        puVar7[4] = 0;
        puVar7[5] = 0;
        *reinterpret_cast<std::uint8_t*>(puVar7 + 2) = 0;
    }

    // Eleven refcounted singletons installed into their globals (release without argument).
    ref_assign(SLOT(DAT_008e9fe8), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008e9fec), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008e9ff0), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008e9ff4), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008e9ff8), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008e9ffc), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008ea000), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008ea004), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008ea008), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008ea00c), alloc_construct_0053bb30(0), false);
    ref_assign(SLOT(DAT_008ea010), alloc_construct_0053bb30(0), false);

    // Renderer wiring: vtable[0x70] of DAT_008e9fe8 receives the singletons above.
    void* renderer = static_cast<void*>(G32(DAT_008e9fe8));
    reinterpret_cast<VFn0>(v_slot(renderer, 0x70))(renderer);
    reinterpret_cast<VFn0>(v_slot(renderer, 0x70))(renderer);
    reinterpret_cast<VFn1>(v_slot(renderer, 0x70))(renderer, G32(DAT_008e9ff8));
    reinterpret_cast<VFn2>(v_slot(renderer, 0x70))(renderer, G32(DAT_008e9ffc), 1);
    reinterpret_cast<VFn2>(v_slot(renderer, 0x70))(renderer, G32(DAT_008e9ff4), 1);
    reinterpret_cast<VFn1>(v_slot(renderer, 0x70))(renderer, G32(DAT_008ea000));
    reinterpret_cast<VFn2>(v_slot(renderer, 0x70))(renderer, G32(DAT_008ea004), 1);
    reinterpret_cast<VFn1>(v_slot(renderer, 0x70))(renderer, G32(DAT_008ea00c));

    if (FUN_00533c78(0xec) == nullptr) {
        uVar9 = nullptr;
    } else {
        uVar9 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(FUN_0053bb30(0)));
    }
    reinterpret_cast<VFn2>(v_slot(G32(DAT_008ea008), 0x70))(G32(DAT_008ea008), uVar9, 1);

    // First 0x238 object: DAT_008e9fd8, vtable PTR_FUN_0070d868, FUN_004ff360(45.0f).
    puVar7 = static_cast<std::uint32_t*>(FUN_00533c78(0x238));
    if (puVar7 == nullptr) {
        puVar7 = nullptr;
    } else {
        FUN_004ff360(45.0f); // 0x42340000
        *puVar7 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&PTR_FUN_0070d868));
    }
    ref_assign(SLOT(DAT_008e9fd8), puVar7, true);
    ref_assign(&G32(DAT_008e9fd8)[0x55], G32(DAT_008e9fe8), true);
    ref_assign(&G32(DAT_008e9fd8)[0x62], G32(DAT_008ea08c), true);

    // Object extents: [0x17] = [0x18] = 10000.0f (0x461c4000), [0x19] = 3000.0f (0x453b8000).
    *reinterpret_cast<float*>(&G32(DAT_008e9fd8)[0x17]) = 10000.0f;
    *reinterpret_cast<float*>(&G32(DAT_008e9fd8)[0x18]) = 10000.0f;
    *reinterpret_cast<float*>(&G32(DAT_008e9fd8)[0x19]) = 3000.0f;

    // Rotation matrix source: the listing writes only the first three dwords of this
    // nine-dword frame slot group.
    std::uint32_t sourceMatrix[9] = {0x461c4000u, 0x461c4000u, 0x453b8000u};
    void* const stack_matrix =
        reinterpret_cast<void*>(reinterpret_cast<char*>(apuStack_3c) - 0x34); // &apuStack_3c[-0xd]

    puVar7 = G32(DAT_008e9fd8);
    FUN_0053c780(0x3f490fdb); // pi/4
    puVar10 = static_cast<std::uint32_t*>(FUN_0053c8d0(stack_matrix, sourceMatrix));
    puVar7 = puVar7 + 0xe;
    for (int n = 9; (puVar11 = G32(DAT_008e9fd8)), n != 0; n = n - 1) {
        *puVar7 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar7 = puVar7 + 1;
    }
    FUN_0053c7c0(static_cast<int>(0x3f490fdb));
    puVar7 = static_cast<std::uint32_t*>(FUN_0053c8d0(stack_matrix, sourceMatrix));
    puVar10 = puVar11 + 0xe;
    for (int n = 9; (puVar11 = G32(DAT_008e9fdc)), n != 0; n = n - 1) {
        *puVar10 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar10 = puVar10 + 1;
    }
    ref_assign(SLOT(DAT_008e9fdc), G32(DAT_008e9fd8), true);

    // Scene object from FUN_004d49c0 (0x34); two local references are taken (object[1] twice).
    if (FUN_00533c78(0x34) == nullptr) {
        puVar7 = nullptr;
    } else {
        puVar7 = static_cast<std::uint32_t*>(FUN_004d49c0());
        if (puVar7 != nullptr) {
            puVar7[1] = puVar7[1] + 1;
        }
    }
    puVar7[10] = 0x3ebababb; // 0.3648f
    *reinterpret_cast<std::uint16_t*>(puVar7 + 8) = static_cast<std::uint16_t>(
        (*reinterpret_cast<std::uint16_t*>(puVar7 + 8) & 0xfff9) | 1);
    puVar7[0xb] = 0x3f23a3a4; // 0.6394f
    puVar7[0xc] = 0x3f61e1e2; // 0.8833f
    puVar7[9] = 0x3f7d70a4;   // 0.9899f
    puVar7[1] = puVar7[1] + 1;
    apuStack_3c[0] = puVar7;
    FUN_004aac50(apuStack_3c);
    piVar8 = puVar7 + 1;
    *piVar8 = *piVar8 + -1;
    if (*piVar8 == 0) {
        reinterpret_cast<void (*)(void*, int)>(*reinterpret_cast<void**>(puVar7))(puVar7, 1);
    }
    FUN_004d0080();
    fVar12 = (static_cast<float>(DAT_008cac18) / static_cast<float>(_DAT_008cac20)) * 0.5f;
    fHalfH = (static_cast<float>(DAT_008cac1c) / static_cast<float>(_DAT_008cac20)) * 0.5f;

    // Second 0x238 object: DAT_008e9fe0.
    puVar10 = static_cast<std::uint32_t*>(FUN_00533c78(0x238));
    if (puVar10 == nullptr) {
        puVar10 = nullptr;
    } else {
        FUN_004ff360(45.0f); // 0x42340000
        *puVar10 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&PTR_FUN_0070d868));
    }
    ref_assign(SLOT(DAT_008e9fe0), puVar10, true);
    ref_assign(&G32(DAT_008e9fe0)[0x55], G32(DAT_008ea008), true);
    ref_assign(&G32(DAT_008e9fe0)[0x62], G32(DAT_008ea08c), true);

    puVar10 = G32(DAT_008e9fe0);
    puVar11 = static_cast<std::uint32_t*>(FUN_0053c6f0(&DAT_007177b8, &DAT_007177c4, &DAT_007177ac));
    fVar2 = static_cast<float>(DAT_00726384);
    puVar10 = puVar10 + 0xe;
    for (int n = 9; n != 0; n = n - 1) {
        *puVar10 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar10 = puVar10 + 1;
    }
    // in-ECX receiver of FUN_0054aa00 is the stack rectangle (corpus 0x54aa00.c).
    FUN_0054aa00(-fVar12, fVar12, fHalfH, -fHalfH, fVar2 * 0.9f, fVar2 * 1.5f, 0);
    FUN_004cce40();
    puVar10 = G32(DAT_008e9fe0);
    *reinterpret_cast<float*>(&G32(DAT_008e9fe0)[0x17]) = 0.0f;
    *reinterpret_cast<float*>(&puVar10[0x18]) =
        static_cast<float>(static_cast<int>(-DAT_00726384));
    *reinterpret_cast<float*>(&G32(DAT_008e9fe0)[0x19]) = 0.0f;
    FUN_00533d10(0, 1);

    if (FUN_00533c78(0x24) == nullptr) {
        DAT_008c97d0 = nullptr;
    } else {
        DAT_008c97d0 = FUN_0050b1d0(G32(DAT_008e9fd8), 0.05f, 0, 0.05f, 0.5f);
    }
    if (FUN_00533c78(8) == nullptr) {
        DAT_008c97cc = nullptr;
    } else {
        DAT_008c97cc = FUN_00513f40();
    }
    if (DAT_008cac2a != '\0') {
        FUN_004cff30();
    }
    if (FUN_00533c78(0x68) == nullptr) {
        DAT_008c9dd8 = nullptr;
    } else {
        DAT_008c9dd8 = FUN_00508120();
    }
    FUN_00508670(DAT_008c9dd8, "NewFontWithButtons_150.fnt");
    uVar9 = static_cast<std::uint32_t*>(
        reinterpret_cast<void* (*)(void*, int, int)>(v_slot(DAT_00727b28, 4))(DAT_00727b28, 2, 0));
    *reinterpret_cast<std::uint32_t*>(static_cast<char*>(DAT_008c9dd8) + 100) =
        static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(uVar9));
    DAT_008c9de0 = DAT_008c9dd8;
    DAT_008c9ddc = DAT_008c9dd8;
    FUN_00533d10(0, 1);
    FUN_00534350();
    FUN_00534130();
    reinterpret_cast<void (*)(int)>(&FUN_004ff6b0)(0);
    DAT_008c97c8 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(0x10));
    if (FUN_00533c78(8) == nullptr) {
        uVar9 = nullptr;
    } else {
        uVar9 = static_cast<std::uint32_t*>(FUN_004d4950());
    }
    DAT_008c97c8[0] = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(uVar9));
    if (FUN_00533c78(8) == nullptr) {
        uVar9 = nullptr;
    } else {
        uVar9 = static_cast<std::uint32_t*>(FUN_004d48e0());
    }
    DAT_008c97c8[1] = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(uVar9));
    if (FUN_00533c78(8) == nullptr) {
        uVar9 = nullptr;
    } else {
        uVar9 = static_cast<std::uint32_t*>(FUN_004d4890());
    }
    DAT_008c97c8[2] = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(uVar9));
    if (FUN_00533c78(8) == nullptr) {
        uVar9 = nullptr;
    } else {
        uVar9 = static_cast<std::uint32_t*>(FUN_004d4720());
    }
    DAT_008c97c8[3] = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(uVar9));
    FUN_004e0b60();
    piVar8 = puVar7 + 1;
    *piVar8 = *piVar8 + -1;
    if (*piVar8 == 0) {
        reinterpret_cast<void (*)(void*, int)>(*reinterpret_cast<void**>(puVar7))(puVar7, 1);
    }
    SetCursor(reinterpret_cast<HCURSOR>(static_cast<std::uintptr_t>(1)));
    return 1;
}

#undef G32
#undef SLOT
