#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cmath>
#include <windows.h>

// Forward prototypes (defined below in this file)
extern int FUN_00449490(uint16_t param_1, uint16_t param_2, uint16_t param_3, uint32_t param_4);
extern void FUN_00449530(int self);
extern uint32_t FUN_004495a0(int param_1, int self);
extern uint32_t FUN_004497d0(int param_1);
extern void* FUN_0044a4e0(int self);
extern int FUN_0044a670(int param_1, int param_2, int param_3, int self, int in_EDX);
extern void FUN_0044a710(int param_1);
extern void FUN_0044bf30(int self);
extern int FUN_0044c700(int param_1, int in_EAX, int self);
extern int FUN_0044d140(uint32_t param_1, uint32_t param_2, uint32_t param_3, int self);
extern int FUN_0044d1d0(int param_1, int param_2, int self);
extern void FUN_0044d2e0(int param_1, int param_2);
extern void FUN_0044ea50(int param_1);
extern void FUN_0044ea90(int param_1, int in_EAX, int self);
extern int FUN_0044eb10(int param_1, int param_2, int param_3, int param_4, int param_5);
extern void FUN_0044f150(void* param_1, void* param_2, int self);
extern void FUN_00450110(int param_1);
extern void FUN_00451110(void);
extern void FUN_00451270(void);
extern void FUN_00451e50(int param_1, uint32_t param_2, char param_3);

// Extern helpers referenced from other modules (not in this batch)
extern int FUN_00412810(void);
extern void FUN_00412f10(void);
extern void FUN_00413080(void);
extern int FUN_004135d0(void);
extern void* FUN_00533c78(size_t n);
extern void FUN_004bdca0(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern int FUN_005f0ddc();
extern int FUN_004bb500(int f);
extern void FUN_004baaa0();
extern void FUN_004beee0();
extern void FUN_004bcd00(int v);
extern void FUN_004bcac0();
extern void FUN_004bca60();
extern void FUN_004bc740(int v);
extern uint32_t FUN_0045a120(uint32_t v);
extern void FUN_004bc7e0(uint32_t a, uint32_t b);
extern void FUN_004c2810(uint32_t a, int b);
extern void FUN_004bc950(void* p, int a);
extern void FUN_00481140();
extern void FUN_004cddf0(const char* s, int a, int b, int* c, int* d);
extern void FUN_004af080(uint32_t a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern void FUN_004bbb80(void* o, int a, int b, int c, int d, int e, int f);
extern void FUN_004f6090(const char* fmt, ...);
extern void FUN_004f60b0(const char* fmt, ...);
extern void FUN_0044a3b0();
extern void FUN_004879f0(int a, int b);
extern void FUN_004b06c0(void* p, int a, int b, int c, int d, int e, int f, int g);
extern void FUN_004e0390(int v);
extern void FUN_004bbe10(int a, int b);
extern void FUN_004bba60(void* a, int b, uint32_t c, uint32_t d, uint32_t e);
extern int FUN_0042c6f0();
extern void FUN_004889c0(void* p, int a, int b, int c, int d, float e, int f);
extern void FUN_004d0cd0(int a, int b, int c);
extern int FUN_0042e1d0(int v);
extern void FUN_0045fee0(int a, int b, int c, int d, int e);
extern int FUN_0045fcb0(int a, int b, int c, int d, int e);
extern int FUN_0045b5d0();
extern uint32_t FUN_004db150();
extern int FUN_004db210();
extern int FUN_004f2600(const char* fmt, ...);
extern void FUN_004f6090_var(const char* fmt);
extern void FUN_0043a970(int a, int b, int c, int d);
extern void FUN_004051c0();
extern void FUN_00428570(int v);
extern int FUN_00412950();
extern void FUN_00487e90();
extern void FUN_00414c00(int a, int b);
extern void FUN_00448840(const char* s, int v);
extern void FUN_004888e0(int a, int b, int c, float d);
extern void FUN_004600a0();
extern void FUN_004bef50();
extern void FUN_004ae4f0();
extern void FUN_00481180();
extern void FUN_00488e50(int a, float b);
extern void FUN_00489130(void* p);
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern uint32_t FUN_004dadc0(int a, int b, int c);
extern void FUN_004bbc80(int a, int b, int c, uint32_t d, int e, int f, int g);
extern void FUN_004bbf50();
extern void FUN_004afee0();
extern void FUN_004bc0d0();
extern void FUN_004a2080(int a, int b, int c);
extern void FUN_00488ed0(uint32_t v);
extern void FUN_00481100();
extern void* FUN_004afe30();
extern void* FUN_004af680(int a, const char* b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
extern void FUN_004bcd90(int a, int b, int c);
extern void* FUN_00482ca0(int v);
extern void FUN_004ae5b0(const char* s);
extern void FUN_00412840(uint32_t a, uint32_t b);
extern void FUN_004c1080(void* o, const char* s, int a, int b);
extern void FUN_004aff70(void* p);
extern void FUN_004c1150(void* o, const char* s);
extern void FUN_004ff590(float a, float b);
extern void FUN_004ad820();
extern void FUN_004c0870(int v);
extern void FUN_004bc5c0(int v);
extern void FUN_004bbc10(void* o, int a, int b, int c, int d, int e, int f, int g, int h);
extern void FUN_004bcd30(uint32_t v);
extern void FUN_004c2200(int a, int b);
extern void FUN_0045a7c0();
extern void FUN_0042fee0(int a, int b);
extern void FUN_0046b790(int v);
extern void FUN_00460480();
extern void FUN_00401000(int v);
extern void FUN_00453810(void** a, void* b);
extern void FUN_004add70(int v);
extern void FUN_004c1000(const char* s);
extern void FUN_00533d10(int a, int b);
extern int FUN_0041b1d0(void* a, int b, int c, int d, int e, int f, int g, int h, int i, void** j);
extern void FUN_004757c0();
extern void FUN_00475760(int v);
extern void FUN_004a3db0(int v);
extern void FUN_004a3f10();
extern void FUN_0040a610();
extern void FUN_00404ca0();
extern void FUN_0045bbf0(int v);
extern void FUN_00493440(int a, int b, int c, int d, int e);
extern void FUN_00430190(int a, int b, void* c, int d, int e, int f, int g, int h, int i, int j);
extern void FUN_0044c4a0(int v);
extern void FUN_00488840_var(const char* s, int v);
extern void FUN_005be280(const char* s, int a, void* p);
extern void FUN_00535920(void* p);
extern void FUN_00535670(void* p);

// 0x449490 — observed shape
int FUN_00449490(uint16_t param_1, uint16_t param_2, uint16_t param_3, uint32_t param_4)
{
    extern uint16_t DAT_00861b9c[];
    extern uint32_t DAT_00861b78[];
    extern uint16_t DAT_00861b7c[];
    extern uint16_t DAT_00861b80[];
    extern uint32_t DAT_00861b84[];
    extern uint16_t DAT_00861b88[];
    extern uint32_t DAT_00861b8c[];
    extern uint32_t DAT_00861b90[];
    extern uint32_t DAT_00861b94[];
    extern uint32_t DAT_00861b98[];
    extern uint32_t DAT_0085a150;
    uint32_t uVar1;
    int iVar2;
    uint16_t* psVar3;
    int iVar4;
    iVar2 = 1;
    psVar3 = &DAT_00861b9c;
    do {
        if (*psVar3 < 1) {
            iVar4 = iVar2 * 0x24;
            DAT_00861b78[iVar2 * 0x12] = 0xffffffff;
            DAT_00861b7c[iVar2 * 9] = 0xffffffff;
            DAT_00861b80[iVar2 * 0x12] = 0xffffffff;
            DAT_00861b84[iVar2 * 9] = 0xffffffff;
            DAT_00861b88[iVar2 * 9] = 0xffffffff;
            DAT_00861b8c[iVar2 * 9] = 0xffffffff;
            DAT_00861b90[iVar2 * 9] = 0xffffffff;
            DAT_00861b94[iVar2 * 9] = 0xffffffff;
            DAT_00861b98[iVar2 * 9] = 0xffffffff;
            DAT_00861b78[iVar2 * 0x12] = param_1;
            *reinterpret_cast<uint16_t*>(&DAT_00861b78[0] + iVar4) = param_2;
            *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(&DAT_00861b7c[0]) + iVar4 + 2) = param_3;
            DAT_00861b88[iVar2 * 9] = (uint16_t)param_4;
            uVar1 = DAT_0085a150;
            DAT_00861b80[iVar2 * 0x12] = 1;
            DAT_00861b8c[iVar2 * 9] = uVar1;
            return iVar2;
        }
        psVar3 = psVar3 + 0x12;
        iVar2 = iVar2 + 1;
    } while (reinterpret_cast<intptr_t>(psVar3) < 0x861ff8);
    return 0;
}

// 0x449530 — observed shape
void FUN_00449530(int self)
{
    extern uint8_t DAT_00861b7a[];
    extern uint32_t DAT_00861b8c[];
    extern uint16_t DAT_00861b80[];
    extern uint16_t DAT_00861b98[];
    extern uint16_t DAT_00861b9a[];
    extern uint32_t DAT_00861b90[];
    extern uint32_t DAT_00861b94[];
    extern uint16_t DAT_00814336[];
    extern uint16_t DAT_00814338[];
    extern uint32_t DAT_00814308[];
    extern uint32_t DAT_00814304[];
    extern uint32_t DAT_0085a150;
    uint16_t uVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    iVar3 = self * 0x24;
    if (0 < *reinterpret_cast<int16_t*>(DAT_00861b7a + iVar3)) {
        iVar4 = *reinterpret_cast<int16_t*>(DAT_00861b7a + iVar3);
        DAT_00861b8c[self * 9] = DAT_0085a150;
        if (0 < iVar4) {
            uVar1 = DAT_00814336[iVar4 * 0x22e];
            *reinterpret_cast<uint8_t*>(&DAT_00861b80[self * 0x12]) = *reinterpret_cast<uint8_t*>(&DAT_00861b80[self * 0x12]) | 0x40;
            DAT_00861b98[iVar4 * 0x22e] = uVar1;
            DAT_00861b9a[iVar4 * 0x22e] = DAT_00814338[iVar4 * 0x22e];
            uVar2 = DAT_00814308[iVar4 * 0x117];
            DAT_00861b90[self * 9] = DAT_00814304[iVar4 * 0x117];
            DAT_00861b94[self * 9] = uVar2;
        }
    }
    return;
}

// 0x4495a0 — observed shape
uint32_t FUN_004495a0(int param_1, int self)
{
    extern uint16_t DAT_00861ba4[];
    extern int32_t DAT_0085a97c[];
    extern int32_t DAT_0085a974[];
    extern int32_t DAT_00814308[];
    extern int32_t DAT_00814304[];
    int16_t sVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    uint32_t local_8;
    uint16_t* local_c;
    uint32_t local_10;
    local_8 = 0xffffffff;
    iVar4 = 0xffff;
    local_10 = 1;
    local_c = &DAT_00861ba4[0];
    do {
        if ((local_c[-4] != 0) && (-1 < *local_c) && (((uint8_t)*local_c & 0x7f) != 0x7f)) {
            iVar2 = local_c[-3];
            if (iVar2 == -1) {
                sVar1 = local_c[-1];
                if ((sVar1 == -1) || ((DAT_0085a97c[sVar1 * 8] == -1 && (DAT_0085a974[sVar1 * 8] == -1)))) {
                    goto LAB_00449781;
                }
                iVar3 = FUN_00412810();
            } else {
                iVar3 = DAT_00814308[iVar2 * 0x117] / 1000000 - self;
                iVar2 = DAT_00814304[iVar2 * 0x117] / 1000000 - param_1;
                if (iVar2 < 0) iVar2 = -iVar2;
                if (iVar3 < 0) iVar3 = -iVar3;
                if (iVar3 < iVar2) iVar3 = iVar3 + iVar2 * 2;
                else iVar3 = iVar2 + iVar3 * 2;
                iVar3 = iVar3 / 2;
            }
            if (iVar3 < iVar4) {
                local_8 = local_10;
                iVar4 = iVar3;
            }
        }
LAB_00449781:
        local_c = local_c + 0x12;
        local_10 = local_10 + 1;
        if (0x861fff < reinterpret_cast<intptr_t>(local_c)) {
            if (local_8 == 0xffffffff) return 0;
            {
                extern uint32_t FUN_004497d0(int);
                int iVar4b = FUN_004497d0((int)local_8);
                return (uint32_t)(-(int)(iVar4b != 0)) & local_8;
            }
        }
    } while (true);
}

// 0x4497d0 — observed shape
uint32_t FUN_004497d0(int param_1)
{
    extern uint16_t DAT_00861b80[];
    extern uint8_t DAT_00869b48;
    extern uint8_t DAT_0044a362[];
    extern void* PTR_LAB_0044a348[];
    int iVar1;
    uint32_t uVar2;
    uint8_t bVar3;
    int iVar4;
    iVar4 = 0;
    while (true) {
        iVar1 = std::rand();
        bVar3 = (uint8_t)(iVar1 % 7);
        if (((int)(int16_t)DAT_00861b80[param_1 * 0x12] & (1 << (bVar3 & 0x1f))) == 0) break;
        iVar4 = iVar4 + 1;
        if (99 < iVar4) return 0;
    }
    if (99 < iVar4) return 0;
    iVar4 = 1 << (bVar3 & 0x1f);
    DAT_00869b48 = 0;
    if ((uint32_t)(iVar4 - 2) < 0x3f) {
        // Ghidra warning: Could not emulate address calculation at 0x0044983d; Treating indirect jump as call
        void* target = PTR_LAB_0044a348[DAT_0044a362[iVar4]];
        // indirect call through jump table (non_contiguous range 0x44a320-0x44a346)
        uVar2 = reinterpret_cast<uint32_t(*)()>(target)();
        return uVar2;
    }
    DAT_00861b80[param_1 * 0x12] = (uint16_t)(DAT_00861b80[param_1 * 0x12] | (uint16_t)(1 << (bVar3 & 0x1f)));
    return 0;
}

// 0x44a4e0 — observed shape
void* FUN_0044a4e0(int self)
{
    extern int32_t DAT_008ea008;
    extern int32_t DAT_00727444;
    extern void* PTR_FUN_006fd14c;
    extern uint32_t FUN_00412f10(void);
    extern void* FUN_00533c78(size_t n);
    extern void FUN_004bdca0(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
    uint32_t uVar1;
    uint32_t* puVar2;
    switch (self) {
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
    case 8: break;
    case 9: break;
    default:
        goto switchD_0044a4fd_caseD_a;
    case 0x1e: break;
    case 0x1f: break;
    case 0x20: break;
    case 0x21: break;
    case 0x22: break;
    case 0x28: break;
    case 0x29: break;
    case 0x2a: break;
    }
    FUN_00412f10();
switchD_0044a4fd_caseD_a:
    puVar2 = (uint32_t*)FUN_00533c78(0xc0);
    uVar1 = DAT_008ea008;
    if (puVar2 == (uint32_t*)0x0) {
        puVar2 = (uint32_t*)0x0;
    } else {
        puVar2[1] = 0;
        *puVar2 = (uint32_t)(intptr_t)&PTR_FUN_006fd14c;
        puVar2[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar2[0x19] = 0;
        puVar2[0x2f] = 0;
        FUN_004bdca0((int)uVar1, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    return puVar2;
}

// 0x44a670 — observed shape
int FUN_0044a670(int param_1, int param_2, int param_3, int self, int in_EDX)
{
    extern int FUN_005f0ddc();
    int iVar1;
    double dVar2;
    int local_8[2];
    local_8[0] = self - in_EDX;
    dVar2 = std::modf(((double)local_8[0] / (double)param_1) * (double)param_2, (double*)local_8);
    if (dVar2 < 0.0) {
        iVar1 = FUN_005f0ddc();
        return iVar1 + param_3;
    }
    iVar1 = FUN_005f0ddc();
    return iVar1 + param_3;
}
// 0x44a710 — observed shape
// NEEDS_MANUAL: large UI display routine (596 lines) with nested switch on city names and pirate info display; full reconstruction appended below is structurally faithful but uses simplified pointer arithmetic for some overlays
void FUN_0044a710(int param_1)
{
    extern int32_t DAT_00861b7a[];
    extern int32_t DAT_00861b88[];
    extern uint16_t DAT_008142f8[];
    extern uint16_t DAT_00814324[];
    extern int32_t DAT_0085a164;
    extern uint8_t DAT_00725d98;
    extern uint8_t DAT_00869b48[];
    extern int32_t DAT_007263bc;
    extern int32_t DAT_00726820;
    extern int32_t DAT_00726a84;
    extern uint8_t DAT_00726814[];
    extern uint8_t DAT_008cac27;
    extern uint32_t DAT_007268f4[];
    extern int32_t DAT_008c9df4;
    extern int32_t DAT_0085a268;
    extern int32_t DAT_0085a26c;
    extern int32_t DAT_0086c330;
    extern int32_t DAT_0086c1a0[];
    extern int32_t DAT_0086c010[];
    extern int32_t DAT_0086be80[];
    extern int32_t DAT_0086bcf0[];
    extern int32_t DAT_0086bb60[];
    extern int32_t DAT_00861b80[];
    extern int32_t DAT_00861b7c[];
    extern int32_t DAT_00861b82[];
    extern int32_t DAT_00861b98[];
    extern int32_t DAT_00861b9a[];
    extern int32_t DAT_00861b8c[];
    extern int32_t DAT_0085a150;
    extern int32_t DAT_008dbd08[];
    extern int32_t DAT_008cb100[];
    extern int32_t DAT_008cb178[];
    extern int32_t DAT_008cb19c[];
    extern int32_t DAT_008cb1a0[];
    extern int32_t DAT_008cb1a4[];
    extern int32_t DAT_008c8494;
    extern int32_t DAT_008dc30c;
    extern int32_t DAT_008dc310;
    extern uint8_t DAT_008c97c0[];
    extern int32_t DAT_008c97c4;
    extern uint8_t DAT_008e9fe8[];
    extern int32_t DAT_00869b47;
    extern int32_t DAT_008d74d8[];
    extern int32_t DAT_007267c8;
    extern int32_t DAT_007267cc;
    extern void* PTR_DAT_007267d0;
    extern int32_t DAT_008ea008;
    extern int32_t DAT_00727444;
    extern void* PTR_FUN_006fd14c;
    extern uint8_t DAT_007270cc[];
    extern uint8_t DAT_007270bc[];
    extern int32_t DAT_0086c35c;
    extern int32_t DAT_0086c360;
    extern char DAT_00701e48;
    bool bVar5;
    uint32_t uVar6;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar16;
    int iVar14;
    int iVar15;
    int iVar18;
    int local_10;
    int local_34;
    int local_2c;
    int local_28;
    int local_14;
    int local_8;
    uint32_t local_c;
    uint32_t local_30;
    uint32_t* local_3c;
    uint32_t* local_24;
    uint32_t* local_20;
    uint32_t* local_1c;
    uint32_t* local_18;
    uint8_t cVar3;
    char* pcVar22;
    uint32_t* puVar7;
    uint32_t* puVar8;
    uint16_t* puVar20;
    local_10 = param_1 * 0x24;
    iVar14 = (int16_t)*(int16_t*)(DAT_00861b7a + local_10);
    local_34 = -1;
    local_2c = -1;
    uVar6 = (uint32_t)DAT_0085a164 >> 2;
    DAT_0085a164 = (int32_t)(DAT_0085a164 & 0xfffffffb);
    local_3c = nullptr;
    local_24 = nullptr;
    local_20 = nullptr;
    local_1c = nullptr;
    local_18 = nullptr;
    bVar5 = false;
    local_30 = 0;
    FUN_005be280("f4Depths", 0x10, DAT_007270cc);
    puVar7 = (uint32_t*)FUN_0044a4e0(0);
    if (puVar7 != nullptr) {
        puVar7[1] = puVar7[1] + 1;
        local_3c = puVar7;
    }
    for (int rep = 0; rep < 3; ++rep) {
        puVar7 = (uint32_t*)FUN_00533c78(0xc0);
        uVar9 = DAT_008ea008;
        if (puVar7 != nullptr) {
            puVar7[1] = 0;
            *puVar7 = (uint32_t)(intptr_t)&PTR_FUN_006fd14c;
            puVar7[7] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            puVar7[0x19] = 0;
            puVar7[0x2f] = 0;
            FUN_004bdca0((int)uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            puVar7[1] = puVar7[1] + 1;
            if (rep == 0) local_24 = puVar7;
            else if (rep == 1) local_20 = puVar7;
            else local_18 = puVar7;
        }
    }
    DAT_007268f4[DAT_00726a84] = (uint32_t)DAT_007263bc;
    DAT_00726a84++;
    DAT_007263bc = 0x500;
    if ((0 < iVar14) && (DAT_008142f8[iVar14 * 0x22e] != 0xffff)) {
        puVar8 = (uint32_t*)FUN_004bb500(0);
        puVar7 = nullptr;
        if (puVar8 != nullptr) {
            puVar8[1] = puVar8[1] + 1;
            puVar7 = puVar8;
            local_1c = puVar8;
        }
        puVar7[6] = DAT_008ea008;
        *(uint32_t*)(puVar7[0x2f] + 0x18) = DAT_008ea008;
        FUN_004baaa0();
        FUN_004beee0();
        if (puVar7[0x2f] != 0) FUN_004bcd00(1);
        *(uint8_t*)(puVar7 + 0x13) = 1;
        FUN_004bcac0();
        FUN_004bca60();
        FUN_004bc740(DAT_00814324[iVar14 * 0x45c] & 1);
        uVar16 = (uint32_t)(iVar14 < 8);
        uVar9 = FUN_0045a120(uVar16);
        FUN_004bc7e0(uVar9, uVar16);
        uVar9 = FUN_004baaa0();
        local_14 = (int)(local_14 & 0xffffff00u) | 0x80;
        FUN_004c2810(uVar9, local_14);
        iVar18 = DAT_00861b88[param_1 * 9];
        *(uint32_t*)(DAT_00869b48) &= 0xffffff00u;
        if (iVar18 < 1 || 9 < iVar18) {
            if (iVar18 < 0x28 || 0x2a < iVar18) goto switchD_0044aa16_default;
            DAT_00869b48[0]='u'; DAT_00869b48[1]='r'; DAT_00869b48[2]='e'; DAT_00869b48[3]='v';
            DAT_00869b48[4]='i'; DAT_00869b48[5]='l'; DAT_00869b48[6]='l';
            *reinterpret_cast<char**>(DAT_00869b48 + 8) = nullptr; // &DAT_006e6961
        } else {
            switch (iVar18) {
            case 1: { // henry morgan
                const char* s="henry morgan";
                for(int i=0;s[i];++i) DAT_00869b48[i]=s[i];
                break; }
            case 2: { const char* s="blackbeard"; for(int i=0;s[i];++i)DAT_00869b48[i]=s[i]; break; }
            case 3: { const char* s="william kidd"; for(int i=0;s[i];++i)DAT_00869b48[i]=s[i]; break; }
            case 4: { const char* s="jean lafitte"; for(int i=0;s[i];++i)DAT_00869b48[i]=s[i]; break; }
            case 5: { const char* s="steed bonnet"; for(int i=0;s[i];++i)DAT_00869b48[i]=s[i]; break; }
            case 6: { const char* s="ol livn lo"; for(int i=0;s[i];++i)DAT_00869b48[i]=s[i]; break; }
            case 7: { const char* s="roc bras"; for(int i=0;s[i];++i)DAT_00869b48[i]=s[i]; break; }
            case 8: { const char* s="bartholomew"; for(int i=0;s[i];++i)DAT_00869b48[i]=s[i]; break; }
            case 9: { const char* s="jack rackham"; for(int i=0;s[i];++i)DAT_00869b48[i]=s[i]; break; }
            default: goto switchD_0044aa16_default;
            }
        }
        if (DAT_00869b48[0] != 0) FUN_004bc950(DAT_00869b48, 0xffffffff);
    }
switchD_0044aa16_default:
    cVar3 = DAT_00725d98;
    DAT_00726814[DAT_00726820] = DAT_00725d98;
    DAT_00726820++;
    if (cVar3 != 1) FUN_00481140();
    DAT_00725d98 = 1;
    DAT_008c9df4 = 1;
    if (iVar14 != -1) FUN_00413080();
    // Main display loop: repeatedly render pirate info until exit key or error
    while (true) {
        DAT_0086c330 = 0;
        local_28 = 0x300;
        local_14 = 0x400;
        uVar9 = (uint32_t)(intptr_t)0;
        FUN_004cddf0("pirateInfoBG.dds", 0, 0, &local_14, &local_28);
        FUN_004af080(uVar9, 0, 0, local_14, local_28, 0, 0, DAT_0085a26c, DAT_0085a268, 0xffffffff, 0x200);
        DAT_007263bc |= 0x1000;
        FUN_004bbb80(local_3c, 0x71c71c7, 0, 0, 0x118, 0, DAT_008c8494);
        {
            int iVar15_ = DAT_0086c330;
            DAT_0086c1a0[iVar15_] = 3;
            DAT_0086c010[iVar15_] = (int16_t)(DAT_0085a26c/8 - 0x14);
            DAT_0086be80[iVar15_] = (int16_t)(DAT_0085a268/2 - DAT_0085a26c/3 - 0x30);
            DAT_0086bcf0[iVar15_] = (int16_t)(DAT_0085a268/4 - 0x20 + (DAT_0085a26c/8 - 0x14));
            DAT_0086bb60[iVar15_] = (int16_t)(DAT_0085a268/2 - DAT_0085a26c/3 - 0x30 + DAT_0085a268/3);
            DAT_0086c330++;
        }
        iVar18 = DAT_00861b88[param_1 * 9];
        if (iVar18 < 0x28) {
            if (iVar18 < 0x1e) {
                FUN_004f6090("@TOP10", DAT_008cb100[iVar18*3], DAT_008cb100[iVar18*3+1], DAT_008cb100[iVar18*3+2]);
            } else {
                int idx = iVar18*3 - 0x5a;
                FUN_004f6090("Mr. @CHAR. @NPCNAME", (char)((*(int16_t*)(DAT_00861b7c + local_10 + 2) % 0x1a) + 'A'),
                    DAT_008cb19c[idx], DAT_008cb1a0[idx], DAT_008cb1a4[idx]);
            }
        } else {
            int idx = iVar18*3 - 0x78;
            FUN_004f6090("@EVILNAME", DAT_008cb178[idx], DAT_008cb178[idx+1], DAT_008cb178[idx+2]);
        }
        FUN_004b06c0(DAT_00869b48, 0x1e, DAT_0085a268/2 - 0x28, 99, 0xffffffff, 1, 0xffffffff, 0);
        *(uint32_t*)(DAT_00869b48) &= 0xffffff00u;
        FUN_0044a3b0();
        // append flags-based info (home port, dueling skill, last seen)
        {
            uint8_t b = (uint8_t)DAT_00861b80[param_1 * 0x12];
            if ((b & 8) != 0 && *(int16_t*)(DAT_00861b7c + local_10) != -1) {
                int iVar15_ = *(int16_t*)(DAT_00861b7c + local_10);
                FUN_004f60b0("Home port: @CITYNAME", DAT_008dbd08[iVar15_*3], DAT_008dbd08[iVar15_*3+1], DAT_008dbd08[iVar15_*3+2]);
                local_34 = *(int16_t*)(DAT_00861b7c + local_10);
            }
            if (((uint8_t)DAT_00861b80[param_1 * 0x12] & 0x10) != 0 && *(int16_t*)(DAT_00861b82 + local_10) != -1) {
                FUN_004f60b0("Special dueling skill: @DUELINGSKILL", *(int16_t*)(DAT_00861b82 + local_10));
            }
            if ((((uint8_t)DAT_00861b80[param_1 * 0x12]) & 0x40) != 0) {
                int16_t sVar4 = *(int16_t*)(DAT_00861b9a + local_10);
                if (sVar4 != -1) {
                    int16_t sVar17 = *(int16_t*)(DAT_00861b98 + local_10);
                    int32_t iVar15_ = DAT_00861b8c[param_1 * 9];
                    if (sVar17 == sVar4) {
                        if (DAT_0085a150 - 12000 < iVar15_) {
                            FUN_004f60b0("Last seen in @CITYNAME.", DAT_008dbd08[sVar4*3], DAT_008dbd08[sVar4*3+1], DAT_008dbd08[sVar4*3+2]);
                        } else {
                            FUN_004f60b0("Last seen in @CITYNAME, @NUM months ago.", DAT_008dbd08[sVar4*3], DAT_008dbd08[sVar4*3+1], DAT_008dbd08[sVar4*3+2], (DAT_0085a150 - iVar15_)/6000);
                        }
                    } else if (DAT_0085a150 - 12000 < iVar15_) {
                        FUN_004f60b0("Last seen traveling from @CITYNAME to @CITYNAME.", DAT_008dbd08[sVar17*3], DAT_008dbd08[sVar17*3+1], DAT_008dbd08[sVar17*3+2], DAT_008dbd08[sVar4*3], DAT_008dbd08[sVar4*3+1], DAT_008dbd08[sVar4*3+2]);
                    } else {
                        FUN_004f60b0("Last seen traveling from @CITYNAME to @CITYNAME, @NUM months ago.", DAT_008dbd08[sVar17*3], DAT_008dbd08[sVar17*3+1], DAT_008dbd08[sVar17*3+2], DAT_008dbd08[sVar4*3], DAT_008dbd08[sVar4*3+1], DAT_008dbd08[sVar4*3+2], (DAT_0085a150 - iVar15_)/6000);
                    }
                    local_34 = *(int16_t*)(DAT_00861b9a + local_10);
                }
            }
        }
        FUN_004879f0(0x34, 0);
        FUN_004b06c0(DAT_00869b48, 0x1e, DAT_0085a268/2 - 8, 0x37, 0xffffffff, 1, 0xffffffff, 0);
        if (0 < iVar14 && DAT_008142f8[iVar14 * 0x22e] != 0xffff &&
            ((uint8_t)DAT_00861b80[param_1 * 0x12] & 2) != 0) {
            FUN_004e0390(DAT_008142f8[iVar14 * 0x22e]);
            FUN_004bbb80(local_1c, local_8 - 0x15555555, (int32_t)0xf8e38e39, 0, (int)local_c, 0xffffffff, 0);
            FUN_004bbe10(0, DAT_008c8494);
            FUN_004f6090("Sails on the @SHIPTYPE: '@SHIPNAME'", DAT_008142f8[iVar14 * 0x22e], DAT_007267c8, DAT_007267cc, PTR_DAT_007267d0);
            FUN_004b06c0(DAT_00869b48, 0x1e, (DAT_0085a268*7)/8 - 0x78, 99, 0xffffffff, 1, 0xffffffff, 0);
            if (((uint8_t)DAT_00861b80[param_1 * 0x12] & 4) != 0) {
                for (int iu = 0, iu2 = 0; iu < 20; ++iu, ++iu2) {
                    if ((DAT_00814324[iVar14 * 0x45c] & (1 << (iu & 0x1f))) != 0) {
                        FUN_004f6090("@UPGRADE", iu);
                        FUN_004b06c0(DAT_00869b48, (DAT_0085a26c/4)+0x14, (DAT_0085a268*7)/8 - 0x58 + iu2, 0x33, 0xffffffff, 1, 0xffffffff, 0);
                        iu2 += 0x10;
                    }
                }
            }
        }
        // random hover text positions
        {
            int iVar18b = FUN_0044a670(0x1ce, 0x118, 0x108, 0, 0);
            int iVar11b = FUN_0044a670(0x125, 0xde, 0x2d, 0, 0);
            if ((DAT_008c8494 % 1000 < 500) && local_24) FUN_004bba60(local_24, 0, (uint32_t)0x42200000, (uint32_t)0x42200000, 0);
            int iVar15b = DAT_0086c330;
            DAT_0086be80[iVar15b] = (int16_t)iVar11b;
            DAT_0086bb60[iVar15b] = (int16_t)(iVar11b + 10);
            DAT_0086c1a0[iVar15b] = 1;
            DAT_0086c010[iVar15b] = (int16_t)iVar18b;
            DAT_0086c330++;
            DAT_0086bcf0[iVar15b] = (int16_t)(iVar18b + 10);
            int iVar15c = FUN_0044a670(0x70cb0, 0x118, 0x108, 0, 0);
            int iVar11c = FUN_0044a670(0x125, 0xde, 0x2d, 0, 0);
            if (local_20) FUN_004bba60(local_20, 0, (uint32_t)0x42200000, (uint32_t)0x42200000, 0);
            int iVar12b = DAT_0086c330;
            DAT_0086be80[iVar12b] = (int16_t)(iVar11c - 9);
            DAT_0086bb60[iVar12b] = (int16_t)(iVar11c + 9);
            DAT_0086c010[iVar12b] = (int16_t)(iVar15c - 9);
            DAT_0086bcf0[iVar12b] = (int16_t)(iVar15c + 9);
            DAT_0086c1a0[iVar12b] = 0;
            DAT_0086c330++;
            FUN_004bbb80(local_18, 0, 0, 0, 0x3c, (int)local_30, DAT_008c8494);
            int iVar13b = DAT_0086c330;
            DAT_0086c010[iVar13b] = (int16_t)(DAT_0085a26c - 0x2b);
            DAT_0086be80[iVar13b] = (int16_t)(DAT_0085a268 - 0x23);
            DAT_0086c330++;
            DAT_0086bcf0[iVar13b] = (int16_t)(DAT_0085a26c - 5);
            DAT_0086c1a0[iVar13b] = 2;
            DAT_0086bb60[iVar13b] = (int16_t)(DAT_0085a268 - 7);
            bool bVar21 = DAT_008dc30c != -1;
            int iVar12c = DAT_008dc310;
            if (bVar21 || iVar12c != -1) {
                int iVar12d = FUN_0042c6f0();
                if (local_2c != iVar12d) {
                    if (local_2c == 2) local_30 = 0;
                    else if (iVar12d == 2) local_30 = 7;
                    if (local_2c == -1) FUN_004889c0(DAT_00869b48, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, -1.0f, 0xffffffff);
                }
                local_2c = iVar12d;
            }
            if (local_2c == 0) { FUN_004f6090("You are here."); FUN_004b06c0(DAT_00869b48, iVar15c+3, iVar11c-10, 0x33, (int32_t)0xffc00000, 4, 0xffffffff, 0); }
            else if (local_2c == 1) { FUN_004f6090("@CITYNAME", DAT_008dbd08[local_34*3], DAT_008dbd08[local_34*3+1], DAT_008dbd08[local_34*3+2]); FUN_004b06c0(DAT_00869b48, iVar18b, iVar11b-0xf, 0x33, (int32_t)0xffc00000, 4, 0xffffffff, 0); }
            else if (local_2c == 2) { FUN_004f6090(&DAT_00701e48); FUN_004b06c0(DAT_00869b48, DAT_0085a26c-0x1a, DAT_0085a268-0x2e, 0x44, 0xffffffff, 4, 0xffffffff, 0); }
        }
        FUN_004d0cd0(0, 0, 0);
        Sleep(5);
        iVar18 = FUN_0042e1d0(0);
        if (iVar18 == 0x1b || iVar18 == 0x202) {
            FUN_004889c0(DAT_00869b48, 0x35, 0xffffffff, 0xffffffff, 0xffffffff, -1.0f, 0xffffffff);
            bVar5 = true;
        }
        if (DAT_008cac27 != 0 || bVar5) {
            // release local refs
            if (local_3c) { uint32_t* p = local_3c + 1; *p--; if (*p == 0) reinterpret_cast<void(*)()>(*local_3c)(1); local_3c = nullptr; }
            if (local_24) { uint32_t* p = local_24 + 1; if (--*p == 0) reinterpret_cast<void(*)()>(*local_24)(1); }
            if (local_20) { uint32_t* p = local_20 + 1; if (--*p == 0) reinterpret_cast<void(*)()>(*local_20)(1); }
            if (local_1c) { uint32_t* p = local_1c + 1; if (--*p == 0) reinterpret_cast<void(*)()>(*local_1c)(1); }
            FUN_005be280("f4Depths", 0x10, DAT_007270bc);
            int iVar14b = DAT_008c97c4;
            if ((uVar6 & 1) != 0) DAT_0085a164 |= 4;
            DAT_00726a84--;
            DAT_007263bc = DAT_007268f4[DAT_00726a84];
            int iVar18b = DAT_00726820 - 1;
            uint8_t cVar = DAT_00726814[DAT_00726820];
            DAT_00726820 = iVar18b;
            if (cVar != DAT_00725d98) {
                if (cVar == 0) { DAT_008c97c0[0xb4]=0; *(uint8_t*)(DAT_008c97c0 + 0xb4)=0; *(uint8_t*)(reinterpret_cast<uint8_t*>(iVar14b)+0xb4)=0; FUN_00535920(DAT_008e9fe8); FUN_00535920(DAT_008e9fe8); }
                else { *(uint8_t*)(DAT_008c97c0 + 0xb4)=1; *(uint8_t*)(reinterpret_cast<uint8_t*>(iVar14b)+0xb4)=1; FUN_00535670(DAT_008e9fe8); FUN_00535670(DAT_008e9fe8); }
            }
            DAT_008c9df4 = 1;
            DAT_00725d98 = cVar;
            do { } while (FUN_0042e1d0(0) != 0);
            DAT_0086c35c = 0; DAT_0086c360 = 0;
            if (local_18) { uint32_t* p=local_18+1; if (--*p==0) reinterpret_cast<void(*)()>(*local_18)(1); }
            if (local_3c) { uint32_t* p=local_3c+1; if (--*p==0) reinterpret_cast<void(*)()>(*local_3c)(1); }
            return;
        }
    }
}

// 0x44bf30 — observed shape
void FUN_0044bf30(int self)
{
    extern uint16_t DAT_0081432a[];
    extern uint16_t DAT_0081432c[];
    extern uint16_t DAT_00814320[];
    extern uint16_t DAT_008142f8[];
    extern int32_t DAT_00723b1c[];
    int16_t sVar1, sVar2, sVar3;
    int iVar4, iVar5, iVar6;
    if (self != -1) {
        iVar5 = self * 0x45c;
        sVar1 = *(int16_t*)((uint8_t*)DAT_0081432a + iVar5 * sizeof(uint16_t));
        sVar2 = DAT_00814320[self * 0x22e];
        iVar4 = DAT_00723b1c[(int16_t)DAT_008142f8[self * 0x22e] * 0x11];
        sVar3 = *(int16_t*)((uint8_t*)DAT_0081432c + iVar5 * sizeof(uint16_t));
        iVar6 = (int)sVar1 + (int)sVar3 + (int)sVar2;
        while (iVar4 < iVar6) {
            if (sVar3 == 0) {
                if (sVar1 == 0) {
                    if (sVar2 == 0) return;
                    DAT_00814320[self * 0x22e] = (int16_t)(sVar2 - 1);
                } else {
                    *(int16_t*)((uint8_t*)DAT_0081432a + iVar5 * sizeof(uint16_t)) = (int16_t)(sVar1 - 1);
                }
            } else {
                *(int16_t*)((uint8_t*)DAT_0081432c + iVar5 * sizeof(uint16_t)) = (int16_t)(sVar3 - 1);
            }
            sVar3 = *(int16_t*)((uint8_t*)DAT_0081432c + iVar5 * sizeof(uint16_t));
            sVar1 = *(int16_t*)((uint8_t*)DAT_0081432a + iVar5 * sizeof(uint16_t));
            sVar2 = DAT_00814320[self * 0x22e];
            iVar6 = (int)sVar1 + (int)sVar3 + (int)sVar2;
        }
    }
    return;
}
// 0x44c700 — observed shape
int FUN_0044c700(int param_1, int in_EAX, int self)
{
    extern int32_t DAT_0085a8bc[];
    extern int32_t DAT_00860b6c[];
    extern int32_t DAT_00860b68[];
    extern int16_t DAT_0085a8b2[];
    extern int32_t DAT_0085a8b0[];
    extern int16_t DAT_0085a8b4[];
    extern int32_t DAT_00814350[];
    extern uint8_t DAT_00860b74[];
    extern int32_t DAT_008dbd08[];
    extern int32_t DAT_0085a974[];
    extern int32_t DAT_0085a97c[];
    extern int16_t DAT_008142fc[];
    extern int32_t DAT_007267c8;
    extern int32_t DAT_007267cc;
    extern void* PTR_DAT_007267d0;
    uint8_t cVar1;
    uint8_t bVar2;
    int16_t sVar3;
    int iVar4, iVar5, iVar7, iVar12;
    int32_t* psVar6;
    char* pcVar8 = nullptr;
    uint32_t uVar9=0, uVar10=0, uVar11=0;
    int in_ECX = self;
    iVar12 = 0;
    psVar6 = DAT_0085a8bc;
    iVar7 = 3;
    do {
        for (int k = 0; k < 5; ++k) {
            int idx = k*6;
            if ((0 < psVar6[idx]) && (param_1 == -1 || psVar6[idx] == param_1)) {
                iVar5 = DAT_00860b6c[in_EAX*8] - DAT_00860b6c[psVar6[idx+1]*8];
                iVar4 = DAT_00860b68[in_EAX*8] - DAT_00860b68[psVar6[idx+1]*8];
                if (iVar4 < 0) iVar4 = -iVar4;
                if (iVar5 < 0) iVar5 = -iVar5;
                if (iVar5 < iVar4) iVar5 = iVar5 + iVar4*2; else iVar5 = iVar4 + iVar5*2;
                if (iVar5/2 < in_ECX) { iVar12 = iVar7 + k - 2; in_ECX = iVar5/2; }
            }
        }
        iVar5 = iVar7 + 3;
        psVar6 = psVar6 + 0x1e;
        iVar7 = iVar7 + 5;
    } while (iVar5 < 0x10);
    if (iVar12 == 0) return 0;
    iVar7 = DAT_0085a8b2[iVar12*6];
    switch (DAT_0085a8b0[iVar12*6]) {
    case 3:
        if (DAT_0085a8b4[iVar12*6] == -1) {
            bVar2 = DAT_00860b74[iVar7*0x20];
            iVar5 = (int)FUN_0045fee0(DAT_00860b68[iVar7*8], DAT_00860b6c[iVar7*8], 1 << (bVar2 & 0x1f), 7, 0x80008000);
            if (iVar5 == -1) iVar5 = 0x2e;
            iVar5 = FUN_0044eb10(iVar5, iVar7, (int)((-(uint32_t)(bVar2 != 0) & 0xfffffffd) + 8), 0xffffffff, 3);
            cVar1 = DAT_00860b74[iVar7*0x20];
            DAT_0085a974[iVar5*8] = iVar7;
            sVar3 = DAT_0085a97c[iVar5*0x20];
            DAT_0085a8b4[iVar12*6] = sVar3;
            DAT_008142fc[(uint32_t)sVar3*0x117] = (int16_t)cVar1;
        }
        FUN_00413080();
        FUN_004f60b0("'I've heard that a large group of immigrants from @NATION is traveling to @CITYNAME aboard the ship '@SHIPNAME'.\n", (int)(char)DAT_00860b74[iVar7*0x20], DAT_008dbd08[iVar7*3], DAT_008dbd08[iVar7*3+1], DAT_008dbd08[iVar7*3+2], DAT_007267c8, DAT_007267cc, PTR_DAT_007267d0);
        goto switchD_0044c95d_default;
    case 4:
        uVar9 = DAT_008dbd08[iVar7*3]; uVar10 = DAT_008dbd08[iVar7*3+1]; uVar11 = DAT_008dbd08[iVar7*3+2];
        iVar7 = (char)DAT_00860b74[iVar7*0x20];
        pcVar8 = "'I've heard that some people in the @NATIONALITY city of @CITYNAME have come down with a mysterious illness. I understand the indians are quite familiar with these local diseases.\n";
        break;
    case 5:
        if (DAT_0085a8b4[iVar12*6] == -1) {
            iVar5 = (int)FUN_0045fee0(DAT_00860b68[iVar7*8], DAT_00860b6c[iVar7*8], 1 << (DAT_00860b74[iVar7*0x20] & 0x1f), 7, 0x80008000);
            if (iVar5 == -1) iVar5 = 0x2e;
            iVar5 = FUN_0044eb10(iVar5, iVar7, 1, 0xffffffff, 5);
            cVar1 = DAT_00860b74[iVar7*0x20];
            DAT_0085a974[iVar5*8] = iVar7;
            sVar3 = DAT_0085a97c[iVar5*0x20];
            DAT_0085a8b4[iVar12*6] = sVar3;
            DAT_008142fc[(uint32_t)sVar3*0x117] = (int16_t)cVar1;
        }
        uVar9 = DAT_008dbd08[iVar7*3]; uVar10 = DAT_008dbd08[iVar7*3+1]; uVar11 = DAT_008dbd08[iVar7*3+2];
        iVar7 = (char)DAT_00860b74[iVar7*0x20];
        pcVar8 = "'I've heard they're expecting a new governor in @NATIONALITY city of @CITYNAME. He's the mayor of one of the local settlements I believe.\n";
        break;
    case 6:
        uVar9 = DAT_008dbd08[iVar7*3]; uVar10 = DAT_008dbd08[iVar7*3+1]; uVar11 = DAT_008dbd08[iVar7*3+2];
        iVar7 = (char)DAT_00860b74[iVar7*0x20];
        pcVar8 = "'I've heard the @NATIONALITY city of @CITYNAME is bracing for a pirate attack.\n";
        break;
    case 7:
        uVar9 = DAT_008dbd08[iVar7*3]; uVar10 = DAT_008dbd08[iVar7*3+1]; uVar11 = DAT_008dbd08[iVar7*3+2];
        iVar7 = DAT_0085a8b4[iVar12*6];
        pcVar8 = "'I've heard the @NATIONALITY plan to capture the city of @CITYNAME.\n";
        break;
    case 8:
        uVar9 = DAT_008dbd08[iVar7*3]; uVar10 = DAT_008dbd08[iVar7*3+1]; uVar11 = DAT_008dbd08[iVar7*3+2];
        iVar7 = (char)DAT_00860b74[iVar7*0x20];
        pcVar8 = "'I've heard that the sugar crop in the @NATIONALITY city of @CITYNAME is especially healthy.\n";
        break;
    case 9:
        uVar9 = DAT_008dbd08[iVar7*3]; uVar10 = DAT_008dbd08[iVar7*3+1]; uVar11 = DAT_008dbd08[iVar7*3+2];
        iVar7 = (char)DAT_00860b74[iVar7*0x20];
        pcVar8 = "'I've heard the @NATIONALITY city of @CITYNAME is fearing an indian attack.\n";
        break;
    case 10:
        if (DAT_0085a8b4[iVar12*6] == -1) {
            bVar2 = DAT_00860b74[iVar7*0x20];
            iVar5 = (int)FUN_0045fee0(DAT_00860b68[iVar7*8], DAT_00860b6c[iVar7*8], 1 << (bVar2 & 0x1f), 7, 0x80008000);
            if (iVar5 == -1) iVar5 = 0x2e;
            iVar5 = FUN_0044eb10(iVar5, iVar7, 7 - (uint32_t)(bVar2 != 0), 0xffffffff, 10);
            cVar1 = DAT_00860b74[iVar7*0x20];
            DAT_0085a974[iVar5*8] = iVar7;
            sVar3 = DAT_0085a97c[iVar5*0x20];
            DAT_0085a8b4[iVar12*6] = sVar3;
            DAT_008142fc[(uint32_t)sVar3*0x117] = (int16_t)cVar1;
        }
        FUN_00413080();
        FUN_004f60b0("'I've heard that a fresh battalion of soldiers from @NATION is headed for @CITYNAME aboard the ship '@SHIPNAME'.\n", (int)(char)DAT_00860b74[iVar7*0x20], DAT_008dbd08[iVar7*3], DAT_008dbd08[iVar7*3+1], DAT_008dbd08[iVar7*3+2], DAT_007267c8, DAT_007267cc, PTR_DAT_007267d0);
        goto switchD_0044c95d_default;
    case 0xb:
        if (DAT_0085a8b4[iVar12*6] == -1) {
            iVar5 = (int)FUN_0045fee0(DAT_00860b68[iVar7*8], DAT_00860b6c[iVar7*8], 0xffffffff, 6, 0x80008000);
            if (iVar5 == -1) iVar5 = 0x2e;
            iVar5 = FUN_0044eb10(iVar5, iVar7, 9, 0xffffffff, 0xb);
            cVar1 = DAT_00860b74[iVar7*0x20];
            DAT_0085a974[iVar5*8] = iVar7;
            sVar3 = DAT_0085a97c[iVar5*0x20];
            DAT_0085a8b4[iVar12*6] = sVar3;
            DAT_008142fc[(uint32_t)sVar3*0x117] = (int16_t)cVar1;
        }
        FUN_00413080();
        FUN_004f60b0("'I've heard that a Jesuit Priest is traveling to @CITYNAME aboard the ship '@SHIPNAME' to persuade the governor to declare amnesty for pirates.\n", DAT_008dbd08[iVar7*3], DAT_008dbd08[iVar7*3+1], DAT_008dbd08[iVar7*3+2], DAT_007267c8, DAT_007267cc, PTR_DAT_007267d0);
    default:
        goto switchD_0044c95d_default;
    }
    FUN_004f60b0(pcVar8, iVar7, uVar9, uVar10, uVar11);
switchD_0044c95d_default:
    sVar3 = DAT_0085a8b4[iVar12*6];
    if (0 < sVar3) DAT_00814350[(uint32_t)sVar3*0x117] |= 0x20000;
    return iVar12;
}

// 0x44d140 — observed shape
int FUN_0044d140(uint32_t param_1, uint32_t param_2, uint32_t param_3, int self)
{
    extern int32_t DAT_0085a990[];
    extern int32_t DAT_0085a970[];
    extern int32_t DAT_0085a974[];
    extern int32_t DAT_0085a978[];
    extern int32_t DAT_0085a97c[];
    extern int32_t DAT_0085a980[];
    extern int32_t DAT_0085a984[];
    extern int32_t DAT_0085a988[];
    extern int32_t DAT_0085a98c[];
    extern int32_t DAT_0085a150;
    extern int16_t DAT_008142fc[];
    int iVar1;
    int32_t* piVar2;
    int iVar3;
    iVar1 = 1;
    piVar2 = DAT_0085a990;
    do {
        if (*piVar2 == -1) {
            iVar3 = iVar1 * 0x20;
            DAT_0085a970[iVar1*8] = 0;
            DAT_0085a974[iVar1*8] = 0;
            *(uint32_t*)((uint8_t*)DAT_0085a978 + iVar3) = 0;
            DAT_0085a97c[iVar3/4] = 0;
            *(uint32_t*)(DAT_0085a980 + iVar3/4) = 0;
            *(uint32_t*)((uint8_t*)DAT_0085a984 + iVar3) = 0;
            *(uint32_t*)((uint8_t*)DAT_0085a988 + iVar3) = 0;
            *(uint32_t*)((uint8_t*)DAT_0085a98c + iVar3) = 0;
            DAT_0085a970[iVar1*8] = (int32_t)param_1;
            DAT_0085a974[iVar1*8] = (int32_t)param_2;
            *(uint32_t*)(DAT_0085a980 + iVar3/4) = (uint32_t)DAT_0085a150;
            *(int32_t*)((uint8_t*)DAT_0085a97c + iVar3) = self;
            *(uint32_t*)((uint8_t*)DAT_0085a984 + iVar3) = param_3;
            if (self < 1) return iVar1;
            *(int16_t*)((uint8_t*)DAT_008142fc + self*0x45c + 2) = (int16_t)iVar1;
            return iVar1;
        }
        piVar2 = piVar2 + 8;
        iVar1++;
    } while (reinterpret_cast<intptr_t>(piVar2) < 0x85b170);
    return -1;
}

// 0x44d1d0 — observed shape
int FUN_0044d1d0(int param_1, int param_2, int self)
{
    extern int32_t DAT_0085a9a4[];
    extern int32_t DAT_00860b6c[];
    extern int32_t DAT_00860b68[];
    extern int32_t DAT_00814308[];
    extern int32_t DAT_00814304[];
    int iVar1, iVar2, iVar3, iVar4, iVar5;
    int32_t* piVar6;
    int local_4;
    local_4 = -1;
    iVar5 = 462000000;
    iVar4 = 1;
    piVar6 = DAT_0085a9a4;
    do {
        if ((piVar6[-5] == param_1) && (param_2 == -1 || *piVar6 == param_2)) {
            if (self == -1) return iVar4;
            iVar2 = piVar6[-2];
            if (iVar2 == -1) {
                iVar3 = DAT_00860b6c[self*8] - DAT_00860b6c[piVar6[-4]*8];
                iVar2 = DAT_00860b68[self*8] - DAT_00860b68[piVar6[-4]*8];
                if (iVar2 < 0) iVar2 = -iVar2;
                if (iVar3 < 0) iVar3 = -iVar3;
                iVar1 = iVar3 + iVar2*2;
                if (iVar2 <= iVar3) iVar1 = iVar2 + iVar3*2;
                iVar3 = (iVar1/2)*1000000;
            } else {
                iVar3 = DAT_00860b6c[self*8]*1000000 - DAT_00814308[iVar2*0x117];
                iVar2 = DAT_00860b68[self*8]*1000000 - DAT_00814304[iVar2*0x117];
                if (iVar2 < 0) iVar2 = -iVar2;
                if (iVar3 < 0) iVar3 = -iVar3;
                if (iVar3 < iVar2) iVar3 = iVar3 + iVar2*2; else iVar3 = iVar2 + iVar3*2;
                iVar3 = iVar3/2;
            }
            if (iVar3 < iVar5) { iVar5 = iVar3; local_4 = iVar4; }
        }
        piVar6 = piVar6 + 8;
        iVar4++;
    } while (reinterpret_cast<intptr_t>(piVar6) < 0x85b184);
    return local_4;
}

// 0x44ea50 — observed shape
void FUN_0044ea50(int param_1)
{
    extern uint8_t DAT_0085a168[];
    int iVar1, iVar2, iVar3;
    iVar3 = 0;
    do {
        iVar3++;
        iVar1 = (9 < iVar3) + 4;
        if (iVar1 == 0) iVar2 = 0;
        else { iVar2 = std::rand(); iVar2 = iVar2 % iVar1; }
    } while (DAT_0085a168[iVar2 + param_1*8] != 1);
    return;
}

// 0x44ea90 — observed shape
void FUN_0044ea90(int param_1, int in_EAX, int self)
{
    extern char DAT_007b10a0[];
    extern int32_t DAT_00814308[];
    extern int32_t DAT_00814304[];
    char cVar1;
    int iVar2;
    int in_ECX = self;
    cVar1 = DAT_007b10a0[in_EAX + in_ECX*0x125];
    while ('\x04' < cVar1) {
        iVar2 = std::rand();
        in_ECX = in_ECX - 1 + iVar2 % 3;
        iVar2 = std::rand();
        in_EAX = in_EAX - 1 + iVar2 % 3;
        cVar1 = DAT_007b10a0[in_EAX + in_ECX*0x125];
    }
    DAT_00814308[param_1*0x117] = in_EAX * 1000000;
    DAT_00814304[param_1*0x117] = in_ECX * 1000000;
    return;
}
// 0x44d2e0 — observed shape
// NEEDS_MANUAL: very large dispatch switch (cases 1-11, 13, 20-21, 40-42) handling all ship arrival outcomes; structurally complete but lengthy
void FUN_0044d2e0(int param_1, int param_2)
{
    extern int32_t DAT_0085a974[];
    extern int32_t DAT_0085a97c[];
    extern int16_t DAT_00814338[];
    extern uint8_t DAT_00860b74[];
    extern int32_t DAT_00814350[];
    extern uint8_t DAT_00869b48[];
    extern int32_t DAT_0085a984[];
    extern int16_t DAT_008142fc[];
    extern int32_t DAT_00862d10[];
    extern uint8_t DAT_0085a168[];
    extern int32_t DAT_00869a78[];
    extern int32_t DAT_008dbd08[];
    extern int32_t DAT_007267c8;
    extern int32_t DAT_007267cc;
    extern void* PTR_DAT_007267d0;
    extern int16_t DAT_00814336[];
    extern int32_t DAT_00860b75[];
    extern int32_t DAT_00860b70[];
    extern int32_t DAT_00860b7c[];
    extern int32_t DAT_0085bf94[];
    extern int32_t DAT_0085bf7c[];
    extern int32_t DAT_0085a158;
    extern int32_t DAT_0085a100;
    extern int32_t DAT_00862cf6[];
    extern int32_t DAT_00862cf5[];
    extern int32_t DAT_0085a1a8[];
    extern int32_t DAT_0085a188[];
    extern int32_t DAT_0085a1c8[];
    extern int32_t DAT_00869a7a;
    extern int32_t DAT_00869a7c;
    extern int32_t DAT_00869a7e;
    extern int32_t DAT_00860b76_ovl[];
    extern int32_t DAT_0085bf7e[];
    extern int32_t DAT_0085bf78[];
    extern int32_t DAT_00860b80[];
    extern int32_t DAT_0085bfac[];
    extern uint8_t DAT_00869a88[];
    extern int32_t DAT_00869b1c;
    extern int32_t DAT_00869ad0;
    extern int32_t DAT_00726638;
    extern int32_t DAT_0072663c;
    extern void* PTR_DAT_00726640;
    extern int32_t DAT_0072387c;
    extern int32_t DAT_0081431e[];
    extern int32_t DAT_00869ab0;
    extern uint8_t DAT_00869b34;
    extern int32_t DAT_00869a74;
    extern int16_t DAT_00861b7a[];
    extern int16_t DAT_00861b82[];
    extern int32_t DAT_00861b88[];
    extern int32_t DAT_00861b7c[];
    extern int32_t DAT_008cb100[];
    extern int32_t DAT_008cb178[];
    extern int32_t DAT_008cb19c[];
    extern int32_t DAT_008cb1a0[];
    extern int32_t DAT_008cb1a4[];
    extern int32_t DAT_008cacd0;
    extern int32_t DAT_0085a98c[];
    extern int32_t DAT_0085bf84[];
    extern int32_t DAT_00814330[];
    extern int32_t DAT_0085a164;
    extern int32_t DAT_0085a170[];
    uint8_t bVar2;
    int iVar7;
    int iVar8;
    int iVar9;
    int iVar12;
    int iVar16;
    uint32_t uVar14;
    int local_d8;
    if (param_1 < 1) return;
    iVar7 = param_1 * 0x20;
    local_d8 = DAT_0085a974[param_1*8];
    if (local_d8 == -1) local_d8 = 0;
    iVar12 = DAT_0085a97c[iVar7/4];
    if (iVar12 == -1) goto LAB_0044e920;
    iVar16 = iVar12 * 0x45c;
    iVar8 = DAT_00814338[iVar16/4];
    iVar9 = iVar8 * 0x20;
    bVar2 = DAT_00860b74[iVar9];
    uVar14 = (uint32_t)(char)bVar2;
    if ((DAT_00814350[iVar12*0x117] & 0x800000) != 0 || param_2 == 99) goto LAB_0044e920;
    DAT_00869b48[0] = 0;
    switch (DAT_0085a984[iVar7/4]) {
    case 1: {
        int16_t sVar5 = DAT_008142fc[iVar12*0x117];
        uint32_t uVar17 = (uint32_t)sVar5;
        if (uVar17 != uVar14) {
            if (param_2 == 1) {
                int iVar12b = FUN_0043a970(0x10, (int)(uVar14 << 4 | uVar17), 1, 0);
                *(uint8_t*)((uint8_t*)DAT_00862d10 + iVar12b*0x1c + 1) |= (uint8_t)(1 << ((uint8_t)sVar5 & 0x1f));
                DAT_0085a168[uVar17 + uVar14*8] = 1;
                DAT_0085a168[uVar14 + uVar17*8] = 1;
                FUN_004f6090("Delivery of the @NATIONALITY king's ultimatum has triggered war between @NATION and @NATION.\n", uVar17, uVar14, uVar17);
                DAT_00869a78[uVar17]++;
            } else {
                FUN_004f6090("The @NATIONALITY king's ultimatum sinks beneath the waves, @NATION and @NATION remain at peace.\n", uVar17, uVar14, uVar17);
                DAT_00869a78[uVar17]--;
            }
        }
        break;
    }
    case 2: {
        int16_t sVar5 = DAT_008142fc[iVar12*0x117];
        uint32_t uVar17 = (uint32_t)sVar5;
        if (uVar17 != uVar14) {
            if (param_2 != 1) {
                FUN_004f6090("The @NATIONALITY king's peace proposal has been lost at sea, along with any chance of peace between @NATION and @NATION.\n", uVar17, uVar14, uVar17);
                DAT_00869a78[uVar17]--;
            } else {
                int iVar12b = FUN_0043a970(0x12, (int)(uVar14 << 4 | uVar17), 1, 0);
                uint8_t* pb = (uint8_t*)((uint8_t*)DAT_00862d10 + iVar12b*0x1c + 1);
                *pb |= (uint8_t)(1 << (bVar2 & 0x1f)) | (uint8_t)(1 << ((uint8_t)sVar5 & 0x1f));
                DAT_0085a168[uVar17 + uVar14*8] = 0;
                DAT_0085a168[uVar14 + uVar17*8] = 0;
                FUN_004f6090("The @NATIONALITY king's peace proposal has been accepted, @NATION and @NATION are at peace.\n", uVar17, uVar14, uVar17);
                DAT_00869a78[uVar17]++; DAT_00869a78[uVar14]++;
            }
        }
        break;
    }
    case 3: {
        int iVar16b = DAT_00814338[iVar16/4];
        if (param_2 == 1) {
            FUN_004f6090("The ship bearing @NATIONALITY immigrants has arrived in @CITYNAME.\n", (int)(char)DAT_00860b74[iVar16b*0x20], DAT_008dbd08[iVar16b*3], DAT_008dbd08[iVar16b*3+1], DAT_008dbd08[iVar16b*3+2]);
            DAT_00860b75[iVar9] += 10;
            FUN_0043a970(3, iVar8, 0, 0);
            FUN_004051c0();
        } else {
            FUN_004f6090("The ship bearing @NATIONALITY immigrants bound for @CITYNAME has mysteriously disappeared.\n", (int)(char)DAT_00860b74[iVar16b*0x20], DAT_008dbd08[iVar16b*3], DAT_008dbd08[iVar16b*3+1], DAT_008dbd08[iVar16b*3+2]);
            int16_t sVar5 = DAT_00814336[iVar12*0x22e];
            DAT_00860b75[iVar9] -= (uint8_t)DAT_00860b75[iVar9] / 5;
            DAT_00860b70[(int)sVar5*8] |= 0x10000;
        }
        break;
    }
    case 4: {
        int iVar12b = DAT_00814338[iVar16/4];
        if (param_2 == 1) {
            FUN_004f6090("The indian medicine man works his magic with the mysterious illness in @CITYNAME. The dreaded plague has been averted.\n", DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            DAT_00860b75[iVar12b*0x20] += 4;
        } else {
            FUN_004f6090("The indian medicine man has been lost and soon the plague runs unchecked in @CITYNAME. Many citizens succumb to this dreaded disease.\n", DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            FUN_0043a970(4, iVar12b, 0, 0);
            DAT_00860b75[iVar12b*0x20] -= (uint8_t)DAT_00860b75[iVar12b*0x20] / 3;
        }
        break;
    }
    case 5: {
        int iVar12b = DAT_00814338[iVar16/4];
        if (param_2 == 1) {
            FUN_004f6090("The new governor has arrived in @CITYNAME. The economy flourishes.\n", DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            DAT_00860b7c[iVar12b*8] = (200 - DAT_00860b7c[iVar12b*8])/2 + DAT_00860b7c[iVar12b*8];
            DAT_0085bf94[iVar12b*0x25] += 1000;
            FUN_0043a970(5, iVar12b, 0, 0);
            FUN_004051c0();
            DAT_0085bf7c[iVar12b*0x4a]++;
        } else {
            FUN_004f6090("The new governor fails to arrive in @CITYNAME. Corruption runs rampant.\n", DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            DAT_00860b7c[iVar12b*8] /= 2;
            if (param_2 == 0 || param_2 == 3) {
                int16_t sVar5 = DAT_00814338[iVar16/4];
                FUN_0043a970(5, (int)sVar5, 0xffffffff, 0);
                int iVar9b = DAT_0085a158;
                int iVar12c = DAT_0085a100;
                uint8_t bv = DAT_00860b74[(int)sVar5*0x20];
                int iVar15 = (char)bv;
                if (DAT_0085a158 != 0) {
                    DAT_00869a78[iVar15]--;
                    if (0 < DAT_00869a78[iVar15]) DAT_00869a78[iVar15]--;
                    DAT_00862cf6[iVar12c*0x1c] |= (1 << (bv & 0x1f));
                }
                int iVar6 = DAT_0085a168[iVar15];
                if (iVar6 == 1) { DAT_00869a78[0]++; DAT_00862cf5[iVar12c*0x1c] |= 1; }
                if (iVar6 == -1 && iVar9b != 0) { DAT_00869a78[0]--; DAT_00862cf6[iVar12c*0x1c] |= 1; }
                iVar6 = DAT_0085a188[iVar15*4];
                if (iVar6 == 1) { DAT_00869a7a++; DAT_00862cf5[iVar12c*0x1c] |= 2; }
                if (iVar6 == -1 && iVar9b != 0) { DAT_00869a7a--; DAT_00862cf6[iVar12c*0x1c] |= 2; }
                iVar6 = DAT_0085a1a8[iVar15*4];
                if (iVar6 == 1) { DAT_00869a7c++; DAT_00862cf5[iVar12c*0x1c] |= 4; }
                if (iVar6 == -1 && iVar9b != 0) { DAT_00869a7c--; DAT_00862cf6[iVar12c*0x1c] |= 4; }
                iVar15 = DAT_0085a1c8[iVar15*4];
                if (iVar15 == 1) { DAT_00869a7e++; DAT_00862cf5[iVar12c*0x1c] |= 8; }
                if (iVar15 == -1 && iVar9b != 0) { DAT_00869a7e--; DAT_00862cf6[iVar12c*0x1c] |= 8; }
                DAT_0085bf7c[iVar12b*0x4a]--;
            }
        }
        break;
    }
    case 6: {
        if (param_2 == 1) {
            int iVar12b = FUN_00412950();
            if (iVar12b < 6) {
                FUN_004f6090("Pirates attack the city of @CITYNAME! Mountains of gold and jewels plundered.\n", DAT_008dbd08[iVar8*3], DAT_008dbd08[iVar8*3+1], DAT_008dbd08[iVar8*3+2]);
                DAT_00860b7c[iVar8*8] -= DAT_00860b7c[iVar8*8]/2;
            } else {
                FUN_004f6090("Pirate attack on the city of @CITYNAME defeated by local militia.\n", DAT_008dbd08[iVar8*3], DAT_008dbd08[iVar8*3+1], DAT_008dbd08[iVar8*3+2]);
                DAT_00860b76_ovl[iVar9] -= (char)DAT_00860b76_ovl[iVar9]/2;
            }
            DAT_0085bf7e[iVar8*0x4a] += 50;
            FUN_0043a970(6, iVar8, 0, 0);
        } else if (param_2 == 0 || param_2 == 3) FUN_004051c0();
        break;
    }
    case 7: {
        if (param_2 == 1) {
            if ((char)DAT_00860b76_ovl[iVar9]*2 < (int)(char)DAT_00860b76_ovl[(int16_t)DAT_00814336[iVar12*0x22e]*0x20] && (int16_t)DAT_0085bf78[iVar8*0x4a] < 5) {
                FUN_004f6090("@NATIONALITY fleet captures the city of @CITYNAME!\n", (int)DAT_008142fc[iVar12*0x117], DAT_008dbd08[iVar8*3], DAT_008dbd08[iVar8*3+1], DAT_008dbd08[iVar8*3+2]);
                char cVar3 = (char)DAT_008142fc[iVar12*0x117];
                DAT_00860b74[iVar9] = cVar3;
                if (iVar8 < 0x2c) DAT_00860b80[iVar8*8] = (int)cVar3;
                if ((int16_t)DAT_0085bf7c[iVar8*0x4a] < 0) DAT_0085bf7c[iVar8*0x4a] = 0;
                FUN_0043a970(7, (int)DAT_008142fc[iVar12*0x117], iVar8, 0);
                DAT_00860b70[iVar8*8] = (DAT_00860b70[iVar8*8] & 0xfff7ffff) | 0x20000;
                DAT_0085bf78[iVar8*0x4a] = 0;
            } else {
                FUN_004f6090("@NATIONALITY attack on @CITYNAME defeated!\n", (int)DAT_008142fc[iVar12*0x117], DAT_008dbd08[iVar8*3], DAT_008dbd08[iVar8*3+1], DAT_008dbd08[iVar8*3+2]);
            }
            DAT_0085bf7e[iVar8*0x4a] += 25;
        }
        break;
    }
    case 8: {
        if (param_2 != 1) {
            FUN_004f6090("The valuable seedlings have been lost. The people of @CITYNAME are very disappointed.\n", DAT_008dbd08[local_d8*3], DAT_008dbd08[local_d8*3+1], DAT_008dbd08[local_d8*3+2]);
            DAT_00860b70[(int16_t)DAT_00814336[iVar12*0x22e]*8] = (DAT_00860b70[(int16_t)DAT_00814336[iVar12*0x22e]*8] & 0xfffffbff) | 0x10000;
        } else {
            int iVar12b = DAT_00814338[iVar16/4];
            FUN_004f6090("The hardy seedlings from @CITYNAME have arrived safely in @CITYNAME. Agriculture flourishes.\n", DAT_008dbd08[local_d8*3], DAT_008dbd08[local_d8*3+1], DAT_008dbd08[local_d8*3+2], DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            FUN_0043a970(8, iVar8, 0, 0);
            FUN_004051c0();
            int iVar9b = DAT_00814338[iVar16/4];
            int iVar12c = DAT_00860b7c[iVar9b*8];
            DAT_0085bfac[iVar9b*0x25] += 50;
            DAT_00860b7c[iVar9b*8] = (200 - iVar12c)/2 + iVar12c;
        }
        break;
    }
    case 9: {
        if (param_2 == 1) {
            int iVar12b = FUN_00412950();
            if (iVar12b < 6) {
                FUN_004f6090("Indians attack the city of @CITYNAME! Colonists flee for their lives.\n", DAT_008dbd08[iVar8*3], DAT_008dbd08[iVar8*3+1], DAT_008dbd08[iVar8*3+2]);
                DAT_00860b75[iVar9] -= ((uint8_t)DAT_00860b75[iVar9] >> 1);
            } else {
                FUN_004f6090("Indian raid on the city of @CITYNAME defeated by local militia.\n", DAT_008dbd08[iVar8*3], DAT_008dbd08[iVar8*3+1], DAT_008dbd08[iVar8*3+2]);
                DAT_00860b76_ovl[iVar9] -= (char)DAT_00860b76_ovl[iVar9]/2;
            }
            DAT_0085bf7e[iVar8*0x4a] += 20;
            FUN_0043a970(9, iVar8, 0, 0);
        } else if (param_2 == 0 || param_2 == 3) {
            FUN_004051c0();
            DAT_00860b70[(int16_t)DAT_00814336[iVar12*0x22e]*8] &= 0xfffffbff;
        }
        break;
    }
    case 10: {
        int iVar12b = DAT_00814338[iVar16/4];
        if (param_2 == 1) {
            FUN_004f6090("The ship bearing @NATIONALITY troops has arrived in @CITYNAME.\n", (int)(char)DAT_00860b74[iVar12b*0x20], DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            DAT_00860b76_ovl[iVar9] += 10;
            FUN_0043a970(10, iVar8, 0, 0);
        } else {
            FUN_004f6090("The ship bearing @NATIONALITY troops bound for @CITYNAME has mysteriously disappeared.\n", (int)(char)DAT_00860b74[iVar12b*0x20], DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
        }
        break;
    }
    case 0xb: {
        int iVar12b = DAT_00814338[iVar16/4];
        if (param_2 == 1) {
            FUN_004f6090("The priest proposing @NATIONALITY pirate amnesty has arrived in @CITYNAME.\n", (int)(char)DAT_00860b74[iVar12b*0x20], DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            int iVar12c = 0;
            if (DAT_00869a88[uVar14*2] != 0) {
                iVar12c = (uint8_t)DAT_00869a88[uVar14*2] + 1;
                iVar12c = (uint32_t)(iVar12c*iVar12c)/2 + (int16_t)*(int16_t*)&DAT_00869a88[uVar14*2];
            }
            if (DAT_00869a78[uVar14] < iVar12c) DAT_00869a78[uVar14] = (int16_t)iVar12c;
            FUN_0043a970(0x14, (int)uVar14, 0, 0);
            DAT_0085bf7e[iVar8*0x4a] = 0;
            DAT_0085bf7c[iVar8*0x4a] = 1;
        } else {
            FUN_004f6090("The priest proposing @NATIONALITY pirate amnesty has mysteriously disappeared.\n", (int)(char)DAT_00860b74[iVar12b*0x20], DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            DAT_00869a78[uVar14]--;
        }
        break;
    }
    case 0xd: {
        int iVar12b = DAT_00814338[iVar16/4];
        if (param_2 == 1) {
            FUN_004f6090("The ship bearing the military payroll has arrived in @CITYNAME.\n", DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            DAT_00860b76_ovl[iVar9] += 5;
        } else {
            FUN_004f6090("The ship bearing the military payroll bound for @CITYNAME has mysteriously disappeared.\n", DAT_008dbd08[iVar12b*3], DAT_008dbd08[iVar12b*3+1], DAT_008dbd08[iVar12b*3+2]);
            int cVar3 = (char)DAT_00860b76_ovl[iVar9];
            DAT_00860b76_ovl[iVar9] = (char)(cVar3 - (int)((int)cVar3 + 3)/4);
        }
        break;
    }
    case 0x14: {
        if (param_2 == 1) {
            int iVar9b = DAT_00814338[iVar16/4];
            FUN_004f6090("The holy relic from the @CITYNAME mission has arrived safely in @CITYNAME. Your good deed will not go unrewarded.\n", DAT_008dbd08[local_d8*3], DAT_008dbd08[local_d8*3+1], DAT_008dbd08[local_d8*3+2], DAT_008dbd08[iVar9b*3], DAT_008dbd08[iVar9b*3+1], DAT_008dbd08[iVar9b*3+2]);
            DAT_00860b70[iVar9b*8] |= 0x400;
            DAT_00860b70[(int16_t)DAT_00814336[iVar12*0x22e]*8] |= 0x400;
        } else {
            FUN_004f6090("The holy relic from the @CITYNAME mission was lost at sea. Your negligence will not go unpunished.\n", DAT_008dbd08[local_d8*3], DAT_008dbd08[local_d8*3+1], DAT_008dbd08[local_d8*3+2]);
            DAT_00860b70[(int16_t)DAT_00814336[iVar12*0x22e]*8] = (DAT_00860b70[(int16_t)DAT_00814336[iVar12*0x22e]*8] & 0xfffffbff) | 0x10000;
        }
        break;
    }
    case 0x15: {
        if (param_2 == 0 || param_2 == 3) {
            FUN_004f6090("The Indians of @CITYNAME have been saved from attack. Your good deed will not go unrewarded.\n", DAT_008dbd08[local_d8*3], DAT_008dbd08[local_d8*3+1], DAT_008dbd08[local_d8*3+2]);
            DAT_00860b70[local_d8*8] |= 0x400;
        }
        if (param_2 == 1 && DAT_008142fc[iVar12*0x117] < 4) {
            FUN_004f6090("The @NATIONALITY have destroyed the village of @CITYNAME and founded a settlement in its place.", (int)DAT_008142fc[iVar12*0x117], DAT_008dbd08[local_d8*3], DAT_008dbd08[local_d8*3+1], DAT_008dbd08[local_d8*3+2]);
            uint8_t uVar4 = (uint8_t)DAT_008142fc[iVar12*0x117];
            int iVar12b = local_d8*0x20;
            DAT_00860b80[local_d8*8] = 7;
            DAT_00860b74[iVar12b] = uVar4;
            DAT_00860b7c[local_d8*8] = 100;
            uint32_t uVar14b = (uint32_t)std::rand() & 0x80000007;
            if ((int32_t)uVar14b < 0) uVar14b = (uVar14b - 1 | 0xfffffff8) + 1;
            DAT_00860b75[iVar12b] = (char)uVar14b + 2;
            int iVar9b = std::rand();
            *(int32_t*)((uint8_t*)DAT_00860b78 + iVar12b) = iVar9b % 0x14;
        }
        break;
    }
    case 0x28: case 0x29: case 0x2a: {
        if (param_2 == 3) {
            int iVar9b = DAT_0085a98c[iVar7/4];
            int local_d0 = -1;
            if (iVar9b < 1) {
                FUN_004f6090("Spaniard!");
                FUN_004f6090("The evil Spaniard! emerges from hiding below decks. ");
            } else {
                int iVar16b = DAT_00861b88[iVar9b*9];
                if (iVar16b < 0x28) {
                    if (iVar16b < 0x1e) FUN_004f6090("@TOP10", DAT_008cb100[iVar16b*3], DAT_008cb100[iVar16b*3+1], DAT_008cb100[iVar16b*3+2]);
                    else { int idx = iVar16b*3 - 0x5a; FUN_004f6090("Mr. @CHAR @NPCNAME", (char)(((int)*(int16_t*)((uint8_t*)DAT_00861b7c + iVar9b*0x24 + 2) % 0x1a) + 'A'), DAT_008cb19c[idx], DAT_008cb1a0[idx], DAT_008cb1a4[idx]); }
                } else {
                    int idx = iVar16b*3 - 0x78;
                    FUN_004f6090("@EVILNAME", DAT_008cb178[idx], DAT_008cb178[idx+1], DAT_008cb178[idx+2]);
                }
                if (0 < *(int16_t*)((uint8_t*)DAT_00861b7a + iVar9b*0x24)) {
                    local_d0 = DAT_0081431e[(uint32_t)*(int16_t*)((uint8_t*)DAT_00861b7a + iVar9b*0x24)*0x22e];
                }
                DAT_0072387c = *(int16_t*)((uint8_t*)DAT_00861b82 + iVar9b*0x24);
            }
            FUN_004f60b0("'You have found me at last Mr. @PCNAME, but you will regret crossing swords with me! En Garde!'\n", DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
            FUN_00487e90(); FUN_00412f10();
            FUN_004f6090("'Captain, toss this pathetic creature overboard. ");
            FUN_004f60b0("Perhaps he will think twice before challenging a master swordsman such as myself!'\n");
            if (1 < DAT_00869ad0) {
                extern int32_t DAT_00814754;
                FUN_004f60b0("\nLuckily, a nearby @SHIPTYPE from your fleet is able to haul you from the water. ", DAT_00814754);
                FUN_004f60b0("Chastened but undaunted you continue your adventures.\n");
            }
            FUN_00487e90(); FUN_00412f10();
            int iVar9c = DAT_0085a984[iVar7/4];
            if (iVar9c == 0x28) {
                FUN_004f6090("'You are a master swordsman, sir. I will reveal to you the truth that you seek. ");
                FUN_004f60b0("Your @RELATIVE is held captive in a remote location. ", DAT_00869b1c);
                FUN_004f60b0("This map should help you in your quest to restore your family.\n");
            } else if (iVar9c == 0x29) {
                FUN_004f6090("'You are a master swordsman, sir. ");
                FUN_004f60b0("The governor's daughter is held hostage in the forecastle.'");
            } else if (iVar9c == 0x2a) {
                FUN_004f6090("The evil Marquis falls over the railing and disappears. ");
                FUN_004f60b0("Among the papers in his cabin is a fragment of a map showing the location of his secret hideout, deep in indian territory.\n");
            }
            FUN_00487e90(); FUN_00412f10();
            FUN_004757c0();
            int iVar9d = (local_d0 == -1) ? -1 : DAT_0081431e[0];
            int32_t local_94[4] = {0};
            void* local_c8 = nullptr;
            int32_t* piVar13 = FUN_0041b1d0(local_94, iVar9d, 4, local_d0, 5, 0, DAT_00861b88[DAT_0085a98c[iVar7/4]*9], iVar12, 0, &local_c8);
            if (local_d0 != -1) {
                int iVar12d = DAT_0081431e[0];
                DAT_0081431e[0] = (int16_t)piVar13[1];
                DAT_00869ab0 -= (iVar12d - piVar13[1]) / ((DAT_00869b34 & 0x10) != 0 ? 2 : 1);
            }
            if (*piVar13 != 1) {
                DAT_00869a74--;
                if (DAT_00869ad0 < 2) {
                    FUN_004f6090("You manage to swim to a deserted island. Many months pass before you are rescued by a passing ship.\n");
                    FUN_004f60b0("The men elect you as captain.\n");
                    FUN_00487e90();
                    FUN_00475760(0); FUN_004a3db0(1); FUN_00450110(0xffffffff);
                    DAT_0085a164 |= 0x2000;
                    FUN_004a3f10(); FUN_0040a610();
                    return;
                }
                FUN_00404ca0();
                DAT_00869a74--;
                FUN_0045bbf0(1);
                DAT_0085a164 |= 0x2000;
                FUN_00475760(0); FUN_0040a610();
                return;
            }
            if (DAT_0085a984[iVar7/4] == 0x28) { FUN_00475760(0); FUN_00493440(1, DAT_0081b13e[0], DAT_00860b68[iVar8*8], 0, 0); FUN_00493440(1, 0, 0, 1, 1); }
            if (DAT_0085a984[iVar7/4] == 0x29) {
                int iVar12d = DAT_0085a974[param_1*8];
                FUN_004f6090("The governor's daughter is held hostage in the forecastle. ");
                FUN_004f6090("'Oh dear @RANK @PCNAME, I dreamt every night that you would come to rescue me! ", DAT_00869a88[(char)DAT_00860b74[iVar12d*0x20]*2], DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
                FUN_004f60b0("Let us return to my father in @CITYNAME and speak of our future together.\n", DAT_008dbd08[iVar12d*3], DAT_008dbd08[iVar12d*3+1], DAT_008dbd08[iVar12d*3+2]);
                FUN_00487e90();
                FUN_00451e50(4, (uint32_t)iVar12d, 0);
                DAT_0085bf78[DAT_0085a974[param_1*8]*0x4a]++;
                FUN_00475760(0);
            }
            if (DAT_0085a984[iVar7/4] == 0x2a) { FUN_00475760(0); FUN_00493440(3, DAT_00860b68[iVar8*8], DAT_00860b6c[iVar8*8], 1, 1); }
            FUN_0043a970(0x27, DAT_0085a984[iVar7/4], 0, 0);
            DAT_00869b48[0] = 0;
            FUN_0040a610();
        }
        break;
    }
    default:
        break;
    }
    if (iVar8 != -1) FUN_00428570(iVar8);
    if (DAT_00869b48[0] != 0 && FUN_00412810() < 0x1c) {
        FUN_004888e0(0x2a, 0xffffffff, 0xffffffff, -1.0f);
        FUN_004600a0();
    }
LAB_0044e920:
    if (local_d8 != -1) {
        if (DAT_0085bf84[local_d8*0x25] == param_1) DAT_0085bf84[local_d8*0x25] = 0;
        if (DAT_0085bf84[local_d8*0x25+1] == param_1) DAT_0085bf84[local_d8*0x25+1] = 0;
    }
    {
        int32_t* piVar13 = DAT_0085bf84;
        do {
            if (piVar13[2] == param_1) piVar13[2] = -1;
            if (*piVar13 == param_1) *piVar13 = -1;
            piVar13 += 0x25;
        } while (reinterpret_cast<intptr_t>(piVar13) < 0x85d8f4);
    }
    iVar12 = DAT_0085a97c[iVar7/4];
    if (iVar12 != -1) {
        if (*(int16_t*)((uint8_t*)DAT_008142fc + iVar12*0x45c + 2) == param_1) *(uint16_t*)((uint8_t*)DAT_008142fc + iVar12*0x45c + 2) = 0;
        if (param_2 == 99) FUN_00414c00(iVar12, 99);
    }
    if (0 < DAT_0085a98c[iVar7/4]) DAT_00861b78[DAT_0085a98c[iVar7/4]*0x12] = 0;
    DAT_0085a970[param_1*8] = 0xffffffff;
    return;
}

// 0x44eb10 — observed shape
// NEEDS_MANUAL: large ship-spawn routine (220+ lines); structure preserved, some nested math compressed
int FUN_0044eb10(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    extern int32_t DAT_00723b10[];
    extern int32_t DAT_00723b14[];
    extern int32_t DAT_00723b18[];
    extern int32_t DAT_00723b1c[];
    extern int32_t DAT_00723b08[];
    extern int16_t DAT_008142f8[];
    extern int16_t DAT_00814324[];
    extern int16_t DAT_00814322[];
    extern int16_t DAT_00814320[];
    extern int16_t DAT_0081431e[];
    extern int16_t DAT_00814326[];
    extern int16_t DAT_00814328[];
    extern int16_t DAT_0081432a[];
    extern int16_t DAT_00814338[];
    extern int16_t DAT_00814336[];
    extern int16_t DAT_00814334[];
    extern int16_t DAT_00814330[];
    extern int16_t DAT_00814340[];
    extern int16_t DAT_0081433c[];
    extern int16_t DAT_0081430c[];
    extern int16_t DAT_00814350[];
    extern int16_t DAT_00814354[];
    extern int16_t DAT_00814300[];
    extern int16_t DAT_008142fc[];
    extern int16_t DAT_008142fa[];
    extern uint8_t DAT_00860b74[];
    extern int32_t DAT_00860b7c[];
    extern int32_t DAT_00860b6c[];
    extern int32_t DAT_00860b68[];
    extern int16_t DAT_00861b78[];
    extern int32_t DAT_0085a150;
    extern int32_t DAT_0085a158;
    int16_t sVar4;
    int iVar7 = FUN_004135d0();
    if (iVar7 == -1) return -1;
    sVar4 = (int16_t)FUN_0044d140(10, (uint32_t)param_1, (uint32_t)param_5, 0);
    int iVar17 = iVar7 * 0x45c;
    *(int16_t*)((uint8_t*)DAT_008142fc + iVar17 + 2) = sVar4;
    uint8_t cVar14 = DAT_00860b74[param_1*0x20];
    *(uint16_t*)((uint8_t*)DAT_00814338 + iVar17) = (uint16_t)param_2;
    *(int16_t*)((uint8_t*)DAT_008142fc + iVar7*0x117*2) = (int16_t)cVar14;
    int iVar8 = std::rand();
    DAT_008142f8[iVar7*0x22e] = (int16_t)param_3;
    int iVar9 = (int16_t)param_3 * 0x44;
    int iVar10 = DAT_00723b10[iVar9/4];
    iVar9 = DAT_00723b14[iVar9/4];
    *(int16_t*)((uint8_t*)DAT_00814354 + iVar17) = (int16_t)(iVar8 % 0x32) + 1;
    DAT_00814322[iVar7*0x22e] = (int16_t)((iVar10 != 0) + 2);
    int16_t sVar15;
    if (iVar9/2 < 1) sVar15 = 0;
    else { int t = std::rand(); sVar15 = (int16_t)(t % (iVar9/2)); }
    iVar10 = DAT_00723b18[(int16_t)DAT_008142f8[iVar7*0x22e]*0x11];
    DAT_0081431e[iVar7*0x22e] = (int16_t)(DAT_00723b14[(int16_t)DAT_008142f8[iVar7*0x22e]*0x11]/3) + sVar15;
    if (iVar10/3 < 1) cVar14 = 0;
    else { int t = std::rand(); cVar14 = (char)(t % (iVar10/3)); }
    iVar8 = (int16_t)DAT_008142f8[iVar7*0x22e] * 0x44;
    uint16_t uVar5 = (uint16_t)(((char)(DAT_00723b18[iVar8/4]/3) + cVar14 + 1) & 0xfe);
    DAT_00814320[iVar7*0x22e] = (int16_t)uVar5;
    iVar10 = DAT_00723b08[iVar8/4];
    iVar9 = DAT_00860b7c[param_1*8];
    *(int16_t*)((uint8_t*)DAT_0081432a + iVar17) = (int16_t)((DAT_00723b1c[iVar8/4] - (int)(int16_t)uVar5)/2);
    *(int16_t*)((uint8_t*)DAT_00814328 + iVar17) = (int16_t)((iVar10*iVar9)/5*5);
    if (DAT_00860b74[param_1*0x20] == 4) {
        int t = std::rand();
        *(int16_t*)((uint8_t*)DAT_00814328 + iVar17) += (int16_t)(t % 1000);
    }
    *(uint16_t*)((uint8_t*)DAT_00814326 + iVar17) = 0xffff;
    FUN_00413080();
    iVar10 = 0;
    if (0 < DAT_00814322[iVar7*0x22e]) {
        do {
            uint32_t uVar11 = (uint32_t)std::rand() & 0x80000007;
            if ((int32_t)uVar11 < 0) uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
            *(int16_t*)((uint8_t*)DAT_00814324 + iVar17) += (int16_t)(1 << ((uint8_t)uVar11 & 0x1f));
            iVar10++;
        } while (iVar10 < DAT_00814322[iVar7*0x22e]);
    }
    uint32_t uVar11 = (uint32_t)FUN_004db150();
    if (param_5 == 9) {
        int16_t sVar15b = DAT_008142f8[iVar7*0x22e];
        *(uint16_t*)((uint8_t*)DAT_00814324 + iVar17) &= 0xf;
        uint16_t uVar6 = *(uint16_t*)((uint8_t*)DAT_00723b14 + sVar15b*0x44);
        *(int16_t*)((uint8_t*)DAT_00814354 + iVar17) += 0x3c;
        DAT_0081431e[iVar7*0x22e] = (int16_t)uVar6;
        DAT_00814320[iVar7*0x22e] = 4;
        int iVar10b = 0;
        do {
            int iVar9c = FUN_004135d0();
            if (iVar9c != -1) {
                int16_t* puVar16 = (int16_t*)((uint8_t*)DAT_008142f8 + iVar7*0x22e*2);
                int16_t* puVar18 = (int16_t*)((uint8_t*)DAT_008142f8 + iVar9c*0x22e*2);
                for (int iVar8b = 0x117; iVar8b != 0; iVar8b--) { *puVar18++ = *puVar16++; }
                uint32_t uVar13 = (uint32_t)*(uint32_t*)((uint8_t*)DAT_00814350 + iVar9c*0x117*2);
                *(int16_t*)((uint8_t*)DAT_00814354 + iVar9c*0x45c) += (int16_t)iVar10b * -0x1e + -0x1e;
                *(uint32_t*)((uint8_t*)DAT_00814350 + iVar9c*0x117*2) = uVar13 | 0x800000;
                *(uint16_t*)((uint8_t*)DAT_008142fc + iVar9c*0x45c + 2) = 0;
            }
            iVar10b++;
        } while (iVar10b < 2);
    } else if (param_5 == 6 || param_5 == 7) {
        DAT_0081431e[iVar7*0x22e] = (int16_t)*(uint16_t*)((uint8_t*)DAT_00723b14 + (int16_t)DAT_008142f8[iVar7*0x22e]*0x44);
        DAT_00814322[iVar7*0x22e] = 3;
    } else if (param_5 == 10) {
        DAT_0081431e[iVar7*0x22e] = (int16_t)*(uint16_t*)((uint8_t*)DAT_00723b14 + (int16_t)DAT_008142f8[iVar7*0x22e]*0x44);
    }
    if (param_4 != -1 && param_5 != 2 && DAT_0085a158/2 > -1) {
        int local_14 = 0;
        int iVar10bit = 1 << ((uint8_t)param_4 & 0x1f);
        do {
            int32_t uVar2 = DAT_00860b6c[param_2*8];
            int32_t uVar3 = DAT_00860b68[param_2*8];
            int iVar9d = FUN_0045fee0(uVar3, uVar2, iVar10bit, 0xffffffff, 0x80008000);
            if (iVar9d != -1 && (iVar8 = FUN_004135d0()) != -1) {
                int iVar17b = iVar8*0x45c;
                int uVar6 = FUN_0045fcb0(uVar3, uVar2, iVar10bit, 9999, 0xc0008000);
                DAT_00814336[iVar8*0x22e] = (int16_t)uVar6;
                *(uint16_t*)((uint8_t*)DAT_00814300 + iVar17b) = (uint16_t)iVar7;
                *(uint32_t*)((uint8_t*)DAT_00814340 + iVar17b) = (uint32_t)DAT_0085a150;
                *(int16_t*)((uint8_t*)DAT_00814338 + iVar17b) = (int16_t)iVar9d;
                *(int16_t*)((uint8_t*)DAT_008142fc + iVar8*0x117*2) = (int16_t)param_4;
                *(uint16_t*)((uint8_t*)DAT_008142fa + iVar17b) = 2;
                switch (param_3 % 9) {
                case 0: DAT_008142f8[iVar8*0x22e] = 10; break;
                default: DAT_008142f8[iVar8*0x22e] = 0xb; break;
                case 2: case 8: DAT_008142f8[iVar8*0x22e] = (int16_t)(7 - (param_4 != 0)); break;
                case 6: case 7: DAT_008142f8[iVar8*0x22e] = (int16_t)((param_4 != 0)*8 + 0x10);
                }
                int iVar9e = DAT_00723b14[(int16_t)DAT_008142f8[iVar8*0x22e]*0x11];
                DAT_00814322[iVar8*0x22e] = 3;
                int16_t sVar15c;
                if (iVar9e/2 < 1) sVar15c = 0; else { int t=std::rand(); sVar15c=(int16_t)(t%(iVar9e/2)); }
                DAT_0081431e[iVar8*0x22e] = (int16_t)(DAT_00723b14[(int16_t)DAT_008142f8[iVar8*0x22e]*0x11]/3) + sVar15c;
                int iVar9f = DAT_00723b18[(int16_t)DAT_008142f8[iVar8*0x22e]*0x11];
                uint8_t cVar14b;
                if (iVar9f/2 < 1) cVar14b = 0; else { int t=std::rand(); cVar14b=(char)(t%(iVar9f/2)); }
                uint16_t uVar5b = (uint16_t)(((char)(DAT_00723b18[(int16_t)DAT_008142f8[iVar8*0x22e]*0x11]/3) + cVar14b + 1) & 0xfe);
                DAT_00814320[iVar8*0x22e] = (int16_t)uVar5b;
                *(int16_t*)((uint8_t*)DAT_0081432a + iVar17b) = (int16_t)((DAT_00723b1c[(int16_t)DAT_008142f8[iVar8*0x22e]*0x11] - (int)(int16_t)uVar5b)/2);
                int iVar9g = DAT_00860b7c[(int16_t)DAT_00814336[iVar8*0x22e]*8];
                int16_t sVar15d;
                if (iVar9g*10 < 1) sVar15d = 0; else { int t=std::rand(); sVar15d=(int16_t)(t%(iVar9g*10)); }
                int iVar9h = 0;
                int16_t sVar1 = DAT_00814322[iVar8*0x22e];
                *(int16_t*)((uint8_t*)DAT_00814328 + iVar17b) = (int16_t)(sVar15d + 100);
                if (0 < sVar1) {
                    do {
                        uint32_t uVar13 = (uint32_t)std::rand() & 0x80000007;
                        if ((int32_t)uVar13 < 0) uVar13 = (uVar13 - 1 | 0xfffffff8) + 1;
                        *(int16_t*)((uint8_t*)DAT_00814324 + iVar17b) += (int16_t)(1 << ((uint8_t)uVar13 & 0x1f));
                        iVar9h++;
                    } while (iVar9h < DAT_00814322[iVar8*0x22e]);
                }
                FUN_0044ea90(iVar8, 0, 0);
                uint32_t iVar9i = (uint32_t)(((uVar11 ^ 4) << 0x1d));
                DAT_0081433c[iVar8*0x117] = (int16_t)iVar9i;
                DAT_0081430c[iVar8*0x117] = (int16_t)iVar9i;
                int uVar6b = FUN_0045b5d0();
                DAT_00814336[iVar8*0x22e] = (int16_t)uVar6b;
                *(uint16_t*)((uint8_t*)DAT_00814326 + iVar17b) = 0xffff;
                FUN_00413080();
            }
            local_14++;
        } while (local_14 <= DAT_0085a158/2);
    }
    return (int)sVar4;
}
// 0x44f150 — observed shape
// NEEDS_MANUAL: large full-screen UI with camera setup, message loop and refcount cleanup (325 lines)
void FUN_0044f150(void* param_1, void* param_2, int self)
{
    extern uint8_t DAT_008cac27;
    extern uint8_t DAT_00725d98;
    extern int32_t DAT_007263bc;
    extern int32_t DAT_00726820;
    extern int32_t DAT_00726a84;
    extern uint8_t DAT_00726814[];
    extern uint32_t DAT_007268f4[];
    extern int32_t DAT_008c9df4;
    extern int32_t DAT_0085a164;
    extern int32_t DAT_008c7328;
    extern HCURSOR DAT_008cacd8;
    extern int32_t DAT_008c827f;
    extern int32_t DAT_008c827d;
    extern int32_t DAT_008c8288;
    extern int32_t DAT_0086c35c;
    extern int32_t DAT_008ea000;
    extern int32_t DAT_008e9fec;
    extern int32_t DAT_00727444;
    extern void* PTR_FUN_006fd14c;
    extern int32_t DAT_008e9fd8;
    extern int32_t DAT_0085a11c;
    extern uint8_t DAT_00869b48[];
    extern int32_t DAT_008c97c4;
    extern uint8_t DAT_008c97c0[];
    extern uint8_t DAT_008e9fe8[];
    extern float fStack_c4, fStack_c8, fStack_e0, fStack_e4;
    extern int32_t DAT_00860b74[];
    extern uint8_t DAT_00869a88[];
    extern uint8_t DAT_00869aa8[];
    extern uint8_t DAT_00869a70[];
    bool bVar3 = false;
    if (DAT_008cac27 == 0) {
        FUN_00488ed0(0x40000000);
        FUN_004a2080(0xffffffff, 0xffffffff, 0xffffffff);
        DAT_008c7328 = 1;
        HCURSOR hCursor = DAT_008cacd8;
        if (!hCursor) hCursor = LoadCursorA(nullptr, (LPCSTR)0x7f02);
        HCURSOR hCursor_00 = GetCursor();
        SetCursor(hCursor);
        uint8_t cVar2 = DAT_00725d98;
        DAT_00726814[DAT_00726820] = DAT_00725d98;
        DAT_00726820++;
        if (cVar2 != 0) FUN_00481100();
        DAT_007268f4[DAT_00726a84] = (uint32_t)DAT_007263bc;
        DAT_00726a84++;
        uint32_t uVar4 = (uint32_t)DAT_0085a164 >> 2;
        DAT_0085a164 &= 0xfffffffb;
        DAT_00725d98 = 0;
        DAT_008c9df4 = 1;
        DAT_007263bc = 0xff7ffff;
        uint32_t* puVar5 = (uint32_t*)FUN_004afe30();
        if (puVar5) puVar5[1]++;
        int iVar13 = DAT_008ea000;
        if (!param_1 || !param_2) {
            bVar3 = true;
            if (DAT_008ea000) *(int*)((uint8_t*)(intptr_t)DAT_008ea000 + 4) += 1;
            param_1 = FUN_004af680(iVar13, "pc_govm.kfm", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0, 0);
            uint32_t uVar12;
            if ((char)DAT_00860b74[self*0x20] < 4) {
                iVar13 = (char)DAT_00860b74[self*0x20];
                uVar12 = DAT_00869a88[iVar13*2];
                if ((int)uVar12 < 0) uVar12 = 0; else if (9 < (int)uVar12) uVar12 = 9;
            } else { iVar13 = DAT_00869aa8[0]; uVar12 = 0; }
            FUN_004bcd90((int)uVar12, iVar13, *(int*)DAT_00869a70._3_1_ ? 0 : 0);
            param_2 = FUN_00482ca0(0);
        }
        // create 4 background objects
        uint32_t* objs[4]; uint32_t* puVar6 = nullptr;
        for (int oi = 0; oi < 4; ++oi) {
            uint32_t* o = (uint32_t*)FUN_00533c78(0xc0);
            int32_t tov = (oi == 0) ? DAT_008e9fec : DAT_008ea000;
            if (o) {
                o[1]=0; *o=(uint32_t)(intptr_t)&PTR_FUN_006fd14c; o[7]=0; o[0x19]=0;
                DAT_00727444++; o[0x2f]=0;
                FUN_004bdca0(tov,0,0,0,0,0xffffffff,0,0,0,0);
                o[1]++;
            }
            objs[oi]=o;
        }
        puVar6 = objs[0];
        uint32_t local_f4[7], local_d8_[7];
        {
            uint32_t* src = (uint32_t*)((uint8_t*)(intptr_t)DAT_008e9fd8 + 0x128);
            for (int i=0;i<7;++i) local_f4[i]=src[i];
        }
        uint32_t* puVar7 = (uint32_t*)FUN_00533c78(0xc0);
        int32_t tov2 = DAT_008e9fec;
        if (puVar7) { puVar7[1]=0; *puVar7=(uint32_t)(intptr_t)&PTR_FUN_006fd14c; puVar7[7]=0; puVar7[0x19]=0; DAT_00727444++; puVar7[0x2f]=0; FUN_004bdca0(tov2,0,0,0,0,0xffffffff,0,0,0,0); }
        if (!puVar7) FUN_004ae4f0(); else { puVar7[1]++; FUN_004ae5b0("Camera All"); }
        FUN_00412840(0x3c23d70a, 0x47c35000);
        FUN_004baaa0();
        FUN_004c1080(puVar6, "fx_fountain_splashes", 100, 0xffffffff);
        FUN_004beee0();
        int local_128 = 0;
        if (DAT_00869b48[0] != 0) { local_128 = FUN_005f0ddc(); local_128 = 4000 - local_128; }
        FUN_004a21c0();
        int iVar13b = 0xbb9;
        do {
            int iVar14 = 0;
            if (iVar13b != -1) FUN_004bc0d0();
            int iVar8 = FUN_005f0ddc();
            int iVar9 = FUN_005f0ddc();
            if (iVar8 >= -1) {
                do {
                    int iVar10 = FUN_0042e1d0(0);
                    if (iVar10==0x1b||iVar10==0x20||iVar10==0xd||DAT_0086c35c!=0||DAT_008cac27!=0) {
                        if (DAT_008c827f) { FUN_00489130((void*)(intptr_t)&DAT_008c8288); DAT_008c827f=0; }
                        DAT_008c7328=0; DAT_008c827d=1; iVar13b=0xbbe; break;
                    }
                    uint32_t uVar11;
                    uVar11 = FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar11,100,0,iVar14);
                    uVar11 = FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar11,100,iVar13b,iVar14);
                    uVar11 = FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar11,100,iVar13b,iVar14);
                    uVar11 = FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar11,100,iVar13b,iVar14);
                    uVar11 = FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar11,100,0,0);
                    FUN_004bbe10(iVar13b, iVar14);
                    FUN_004bbf50();
                    *(uint8_t*)(puVar7+9)=0;
                    FUN_004afee0();
                    if (local_128!=0 && FUN_005f0ddc()>=local_128) { DAT_0085a11c=100; FUN_004aff70(DAT_00869b48); }
                    FUN_004d0cd0(0,0,0); Sleep(5);
                    int iVar14b = FUN_005f0ddc(); iVar14b = -iVar14b - iVar9;
                    iVar14 = iVar14b;
                } while (iVar14 <= iVar8);
            }
            iVar13b++;
        } while (iVar13b < 0xbbe);
        if (bVar3) {
            if (param_1) reinterpret_cast<void(*)()>(*(void**)param_1)(1);
            if (param_2) reinterpret_cast<void(*)()>(*(void**)param_2)(1);
        }
        FUN_004bef50();
        FUN_004c1150(puVar6, "fx_fountain_splashes");
        FUN_004ae4f0();
        {
            uint32_t* src = (uint32_t*)((uint8_t*)(intptr_t)DAT_008e9fd8 + 0x128);
            for (int i=0;i<7;++i) local_d8_[i]=src[i];
            if (local_d8_[3]!=local_f4[3] || local_d8_[2]!=local_f4[2]) { FUN_004ff590((float)local_f4[0], (float)local_f4[1]); FUN_004ad820(); }
        }
        for (int oi=1; oi<4; ++oi) {
            if (objs[oi]) { uint32_t* p=objs[oi]+1; if (--*p==0) reinterpret_cast<void(*)()>(*objs[oi])(1); }
        }
        if (puVar6) { uint32_t* p=puVar6+1; if (--*p==0) reinterpret_cast<void(*)()>(*puVar6)(1); }
        if (puVar7) { uint32_t* p=puVar7+1; if (--*p==0) reinterpret_cast<void(*)()>(*puVar7)(1); }
        int iVar13c = DAT_008c97c4;
        if ((uVar4 & 1) != 0) DAT_0085a164 |= 4;
        DAT_00726a84--;
        DAT_007263bc = DAT_007268f4[DAT_00726a84];
        int iVar14c = DAT_00726820 - 1;
        uint8_t cVar = DAT_00726814[DAT_00726820];
        DAT_00726820 = iVar14c;
        if (cVar != DAT_00725d98) {
            if (cVar==0) { *(uint8_t*)(DAT_008c97c0+0xb4)=0; *(uint8_t*)(reinterpret_cast<uint8_t*>(iVar13c)+0xb4)=0; FUN_00535920(DAT_008e9fe8); FUN_00535920(DAT_008e9fe8); }
            else { *(uint8_t*)(DAT_008c97c0+0xb4)=1; *(uint8_t*)(reinterpret_cast<uint8_t*>(iVar13c)+0xb4)=1; FUN_00535670(DAT_008e9fe8); FUN_00535670(DAT_008e9fe8); }
        }
        DAT_008c9df4=1; DAT_00725d98=cVar;
        for (int oi=1; oi<4; ++oi) if (objs[oi]) { uint32_t* p=objs[oi]+1; if (--*p==0) reinterpret_cast<void(*)()>(*objs[oi])(1); }
        if (puVar5) { uint32_t* p=puVar5+1; if (--*p==0) reinterpret_cast<void(*)()>(*puVar5)(1); }
        SetCursor(hCursor_00);
    }
    return;
}

// 0x450110 — observed shape
// NEEDS_MANUAL: large island-rescue cutscene (390 lines); structure preserved, exact float math simplified
void FUN_00450110(int param_1)
{
    extern uint8_t DAT_008cac27;
    extern HCURSOR DAT_008cacd8;
    extern uint8_t DAT_00869b30;
    extern int32_t DAT_008e9ff0;
    extern int32_t DAT_008e9ffc;
    extern int32_t DAT_00727444;
    extern void* PTR_FUN_006fd14c;
    extern int32_t DAT_008cabd4;
    extern int32_t DAT_007263bc;
    extern int32_t DAT_00726820;
    extern int32_t DAT_00726a84;
    extern uint32_t DAT_007268f4[];
    extern int32_t DAT_008e9fd8;
    extern uint8_t DAT_00869b48[];
    extern int32_t DAT_008c8494;
    extern int32_t DAT_008c8498;
    extern float _DAT_008c8498;
    extern int16_t DAT_008142f8[];
    extern int16_t DAT_00814324[];
    extern int16_t DAT_00814350[];
    extern int16_t DAT_00814330[];
    extern int16_t DAT_0081430c[];
    extern int32_t DAT_0085a150;
    extern int32_t DAT_0085a140;
    extern int32_t DAT_007253b4;
    extern int32_t DAT_0085a26c;
    extern int32_t DAT_0085a268;
    extern int32_t DAT_0086c35c;
    extern int32_t DAT_008caccc;
    extern uint8_t DAT_008cacd0[];
    extern int32_t DAT_0085a164;
    extern int32_t DAT_00814304;
    extern int32_t DAT_00814308;
    extern int32_t DAT_008c97c4;
    extern uint8_t DAT_008c97c0[];
    extern uint8_t DAT_008e9fe8[];
    extern uint8_t DAT_008e8eff;
    extern void* DAT_008ecd78;
    extern uint8_t DAT_00869b30v;
    HCURSOR local_134;
    uint32_t* local_158;
    uint32_t* local_164;
    uint32_t* local_144;
    uint32_t* local_170 = nullptr;
    uint32_t* puVar3;
    int local_140, local_148, local_154, local_13c, local_160;
    int local_150;
    float local_174;
    uint32_t* local_14c = nullptr;
    if (DAT_008cac27) return;
    HCURSOR hCursor = DAT_008cacd8;
    if (!hCursor) hCursor = LoadCursorA(nullptr, (LPCSTR)0x7f02);
    local_134 = GetCursor();
    SetCursor(hCursor);
    if (DAT_00869b30) {
        FUN_004f6090("You are marooned on a deserted island. ");
        if (DAT_00869b30 == 1) FUN_004f60b0("With the help of your handy @PROP1, you quickly signal a passing vessel and are rescued!\n", 0x10);
        if (DAT_00869b30 == 2) FUN_004f60b0("With the help of your handy @PROP2, you quickly signal a passing vessel and are rescued!\n", 0x10);
        FUN_00487e90();
    }
    local_158 = (uint32_t*)FUN_00533c78(0xc0);
    if (local_158) { local_158[1]=0; *local_158=(uint32_t)(intptr_t)&PTR_FUN_006fd14c; local_158[7]=0; local_158[0x19]=0; local_158[0x2f]=0; DAT_00727444++; FUN_004bdca0(DAT_008e9ff0,0,0,0,0,0xffffffff,0,0,0,0); local_158[1]++; }
    if (DAT_008e9ffc) *(int*)((uint8_t*)(intptr_t)DAT_008e9ffc+4)++;
    puVar3 = (uint32_t*)FUN_004af680(DAT_008e9ffc, "maroon_pc.kfm", 0,0,0,0,0xffffffff,1,0,0,0,0);
    if (puVar3) puVar3[1]++;
    local_164 = (uint32_t*)FUN_00533c78(0xc0);
    if (local_164) { local_164[1]=0; *local_164=(uint32_t)(intptr_t)&PTR_FUN_006fd14c; local_164[7]=0; DAT_00727444++; local_164[0x19]=0; local_164[0x2f]=0; FUN_004bdca0(DAT_008e9ffc,0,0,0,0,0xffffffff,0,0,0,0); local_164[1]++; }
    local_144 = (uint32_t*)FUN_004afe30();
    if (local_144) local_144[1]++;
    if (local_158 && local_158[0x2f]) FUN_004c0870(1);
    if (local_158) local_158[8] |= 0x8000;
    if (puVar3 && puVar3[0x2f]) { FUN_004c0870(1); }
    if (puVar3) puVar3[8] |= 0x8000;
    local_148 = FUN_005f0ddc();
    local_160 = 0;
    local_150 = DAT_008cabd4;
    FUN_004add70(800);
    DAT_007268f4[DAT_00726a84] = (uint32_t)DAT_007263bc;
    DAT_00726a84++;
    DAT_007263bc &= 0xfffffff5;
    if (!local_164) FUN_004ae4f0(); else FUN_004ae5b0("Camera All");
    FUN_004bc0d0();
    local_140 = FUN_005f0ddc();
    FUN_00412840(0x3dcccccd, 0x47c35000);
    if (DAT_008e9fd8) *(int*)((uint8_t*)(intptr_t)DAT_008e9fd8+4)++;
    FUN_00453810((void**)&local_14c, (void*)(intptr_t)DAT_008e9fd8);
    local_154 = 0;
    if (DAT_00869b48[0]) { local_154=FUN_005f0ddc(); local_154=4000-local_154; FUN_00412f10(); }
    FUN_004baaa0();
    FUN_00533d10(0,1);
    FUN_004c1000("shadow_01");
    if (local_158) { local_158[0x1e]=0; local_158[0x1f]=0; local_158[0x20]=0; }
    if (puVar3) { puVar3[0x1e]=0; puVar3[0x1f]=0; puVar3[0x20]=0; }
    local_13c = FUN_005f0ddc(); local_13c = 5000 - local_13c;
    if (param_1 != -1) {
        uint32_t* puVar4 = (uint32_t*)FUN_004bb500(0);
        if (puVar4) { puVar4[1]++; local_170=puVar4; }
        FUN_004bca60();
        if (local_170) {
            int uVar10 = (DAT_008142f8[param_1*0x22e] % 9 != 0);
            if (local_170[0x2f]) FUN_004bcd00(uVar10);
            *(uint8_t*)(local_170+0x13)= (uint8_t)uVar10;
            FUN_004bcac0();
            uint32_t uVar9 = (uint32_t)(param_1 < 8);
            uint32_t uVar13 = FUN_0045a120(uVar9);
            FUN_004bc7e0(uVar13, uVar9);
            if ((DAT_00814324[param_1*0x45c] & 1) != 0) {
                if (local_170[0x2f]) FUN_004bc740(1);
                if ((local_170[0xf] & 1) == 0) { uint32_t v=local_170[0xf]|1; local_170[0xf]=v; FUN_004bc5c0((int)v); }
            }
            if ((uint16_t)*(uint16_t*)((uint8_t*)DAT_00814350 + param_1*0x117*2) & 0x4000) {
                switch (DAT_00814330[param_1*0x22e]) { case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: break; default: break; }
                FUN_00412f10();
            }
            if ((uint16_t)*(uint16_t*)((uint8_t*)DAT_00814350 + param_1*0x117*2) & 0x2000) FUN_00412f10();
        }
        if (DAT_008caccc) FUN_004bc950(DAT_008cacd0, 0xffffffff);
        local_150 = DAT_0081430c[param_1*0x117];
        local_174 = 5265.0f;
    }
    do {
        char cVar2 = (char)(*(char(*)())(*(void**)(DAT_008ecd78) + 0x18))();
        if (!cVar2) FUN_00488840("The audio manager has not been properly initialized yet", 0);
        else if (!DAT_008e8eff) { FUN_004985e0(); FUN_004a14b0(); }
        int iVar5 = FUN_005f0ddc(); iVar5 = -iVar5 - local_148;
        local_148 += iVar5; local_160 += iVar5;
        uint32_t uVar13 = FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,0xffffffff,0);
        if (local_160 < local_140) {
            uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,0xffffffff,0); FUN_004bbe10(1,local_160); FUN_004bbf50();
            if (local_164) *(uint8_t*)(local_164+9)=0;
            uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,1,local_160);
        } else {
            uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,0xffffffff,0); FUN_004bbe10(2,local_160-local_140); FUN_004bbf50();
            if (local_164) *(uint8_t*)(local_164+9)=0;
            uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,2,local_160);
        }
        if (param_1 != -1 && local_170 && local_174 < 41265.0f) {
            local_174 = _DAT_008c8498*100.0f + local_174;
            DAT_0081430c[param_1*0x117] = (int16_t)0xe391;
            FUN_005f0ddc(); FUN_004db210(); FUN_004db210(); FUN_004db210();
            FUN_004bbc10(local_170,0,0,0,0,0,0,0,0);
            FUN_004bbe10(0,1000); FUN_004bbe10(9,DAT_008c8494>>1); FUN_004bbe10(0xb,DAT_008c8494/3);
            FUN_004bcd30(0x40000000);
            if (31265.0f <= local_174) {
                int iVar5b=FUN_005f0ddc(); if (iVar5b<0)iVar5b=0; else if (iVar5b>100)iVar5b=100; FUN_004c2200(iVar5b,1);
            }
            FUN_0045a7c0();
        }
        FUN_004afee0();
        if (local_154 && FUN_005f0ddc()>=local_154) { DAT_0085a11c=0; FUN_004aff70(DAT_008cacd0); }
        if (FUN_005f0ddc()>=local_13c) FUN_0042fee0(DAT_0085a26c-0x30,0xffffffff);
        FUN_004d0cd0(0,0,0); Sleep(5);
        int iVar5c = FUN_0042e1d0(0);
        if (iVar5c==0x1b||iVar5c==0x20||iVar5c==0xd||(DAT_0086c35c==0&&DAT_008cac27==0)) break;
    } while (true);
    if (param_1 != -1) DAT_0081430c[param_1*0x117] = (int16_t)local_150;
    FUN_0043a970(0x31,0xffffffff,0,0);
    FUN_0046b790(0x5dc);
    DAT_0085a164 |= 0x400;
    for (int i=0; i < (std::rand()%6+6)/((int)DAT_00869b30+1); ++i) {
        DAT_0085a150 += 6000;
        FUN_00460480();
        FUN_004f6090("@MONTH @NUM\n", (DAT_0085a150/6000)%0xc, DAT_0085a140+DAT_007253b4);
    }
    DAT_0085a164 &= 0xfffffbff;
    FUN_004888e0(0x39,0xffffffff,0xffffffff,-1.0f);
    uint32_t uVar15 = (uint32_t)DAT_00814308; uint32_t uVar13b=(uint32_t)DAT_00814304;
    FUN_00401000(0);
    if (local_14c) local_14c[1]++;
    FUN_00453810((void**)&local_14c, local_14c);
    if (local_14c) { uint32_t* p=local_14c+1; if (--*p==0) reinterpret_cast<void(*)()>(*local_14c)(1); }
    FUN_004ae4f0();
    DAT_00726a84--; DAT_007263bc=DAT_007268f4[DAT_00726a84];
    FUN_004add70(local_150);
    DAT_00814304=(int32_t)uVar13b; DAT_00814308=(int32_t)uVar15;
    FUN_00488e50(0x3e,1.0f);
    if (local_170) { uint32_t* p=local_170+1; if (--*p==0) reinterpret_cast<void(*)()>(*local_170)(1); }
    if (local_164) { uint32_t* p=local_164+1; if (--*p==0) reinterpret_cast<void(*)()>(*local_164)(1); }
    if (puVar3) { uint32_t* p=puVar3+1; if (--*p==0) reinterpret_cast<void(*)()>(*puVar3)(1); }
    if (local_158) { uint32_t* p=local_158+1; if (--*p==0) reinterpret_cast<void(*)()>(*local_158)(1); }
    SetCursor(local_134);
    return;
}

// 0x451110 — observed shape
void FUN_00451110(void)
{
    extern uint8_t DAT_008ca998;
    extern uint8_t DAT_008cad8c;
    extern uint8_t DAT_008cad90;
    extern uint8_t DAT_008cad94;
    extern uint8_t DAT_008cade0[];
    extern uint8_t DAT_008cade4[];
    extern uint8_t DAT_008cade8[];
    extern int32_t DAT_00726a84;
    extern int32_t DAT_007263bc;
    extern uint32_t DAT_007268f4[];
    extern int32_t DAT_008ca99c;
    extern uint32_t* DAT_008dc958;
    extern uint32_t* DAT_008dc95c;
    extern uint32_t* DAT_008dc960;
    extern uint32_t* DAT_008dc964;
    extern uint32_t* DAT_008dc968;
    extern int32_t DAT_008ea08c;
    extern uint8_t DAT_008c8288[];
    if (DAT_008ca998) {
        DAT_008ca998 = 0;
        FUN_004bef50();
        DAT_00726a84--;
        DAT_007263bc = (int32_t)DAT_007268f4[DAT_00726a84];
        DAT_008cade0[0]=DAT_008cad8c; DAT_008cade4[0]=DAT_008cad90; DAT_008cade8[0]=DAT_008cad94;
        reinterpret_cast<void(*)()>(*(void**)(DAT_008ea08c + 0x74))(DAT_008cade0);
        FUN_004ae4f0();
        DAT_008ca99c = 0;
        uint32_t** slots[5] = { &DAT_008dc958, &DAT_008dc95c, &DAT_008dc960, &DAT_008dc964, &DAT_008dc968 };
        for (int si=0; si<5; ++si) {
            uint32_t* pu = *slots[si];
            if (pu) {
                int c = (int)pu[1];
                pu[1] = c - 1;
                if (c-1==0) reinterpret_cast<void(*)()>(*pu)(1);
                *slots[si]=nullptr;
            }
        }
        FUN_00481180();
        FUN_00488e50(0x3e, 1.0f);
        FUN_00489130(DAT_008c8288);
    }
    return;
}

// 0x451270 — observed shape
void FUN_00451270(void)
{
    extern int32_t DAT_008ca99c;
    extern int32_t DAT_008dc95c;
    extern int32_t DAT_008ecd78;
    extern uint8_t DAT_008e8eff;
    extern int32_t DAT_0086c35c;
    extern uint8_t DAT_008cac27;
    extern char DAT_008c8288[];
    int iVar6 = 0;
    FUN_004bc0d0();
    int iVar2 = FUN_005f0ddc();
    int iVar3 = FUN_005f0ddc();
    if (0 < iVar2) {
        do {
            char cVar1 = (char)(*(char(*)())((uint8_t*)(intptr_t)DAT_008ecd78 + 0x18))();
            if (!cVar1) FUN_00488840("The audio manager has not been properly initialized yet", 0);
            else if (!DAT_008e8eff) { FUN_004985e0(); FUN_004a14b0(); }
            int iVar4 = FUN_0042e1d0(0);
            if (iVar4==0x1b||iVar4==0x20||iVar4==0xd) return;
            if (DAT_0086c35c) return;
            if (DAT_008cac27) return;
            uint32_t uVar5;
            uVar5=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar5,100,0,iVar6);
            uVar5=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar5,100,0,DAT_008ca99c);
            int iVar4b=DAT_008dc95c;
            uVar5=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar5,100,0xffffffff,0);
            FUN_004bbe10(0,iVar6); FUN_004bbf50();
            *(uint8_t*)(iVar4b+0x24)=0;
            FUN_004afee0();
            FUN_004d0cd0(0,0,0); Sleep(5);
            int iVar4c=FUN_005f0ddc(); iVar4c=-iVar4c-iVar3;
            DAT_008ca99c += (iVar4c - iVar6);
            iVar6 = iVar4c;
            iVar4 = iVar4c;
        } while (iVar4 < iVar2);
    }
    return;
}

// 0x451e50 — observed shape
// NEEDS_MANUAL: large rescue cutscene (380 lines) with model loading and story branch
void FUN_00451e50(int param_1, uint32_t param_2, char param_3)
{
    extern uint8_t DAT_00725d98;
    extern int32_t DAT_00726820;
    extern uint8_t DAT_00726814[];
    extern int32_t DAT_00726a84;
    extern int32_t DAT_007263bc;
    extern uint32_t DAT_007268f4[];
    extern int32_t DAT_008c9df4;
    extern int32_t DAT_008ea000;
    extern int32_t DAT_008e9ff0;
    extern int32_t DAT_008e9ffc;
    extern int32_t DAT_00727444;
    extern void* PTR_FUN_006fd14c;
    extern uint8_t DAT_00869b48[];
    extern int32_t DAT_00869b1c;
    extern int32_t DAT_0085a164;
    extern int32_t DAT_0085bf74[];
    extern int32_t DAT_00873000;
    extern uint8_t DAT_008cacd0[];
    extern int32_t DAT_0086c35c;
    extern uint8_t DAT_008cac27;
    extern int32_t DAT_008c827f;
    extern int32_t DAT_008c8288[];
    extern int32_t DAT_008c97c4;
    extern uint8_t DAT_008c97c0[];
    extern uint8_t DAT_008e9fe8[];
    extern int32_t DAT_0085a26c;
    extern int32_t DAT_0085a268;
    extern int32_t DAT_0085a3b8;
    extern int32_t DAT_0085a3f8;
    extern int32_t DAT_00869b1e;
    extern int32_t DAT_0085a9a4[];
    extern void* DAT_006fb55c;
    extern int32_t DAT_0085a170[];
    HCURSOR local_bc;
    uint32_t* puVar5;
    bool bVar3 = (param_1==1||param_1==3);
    FUN_00488ed0(0x3f800000);
    FUN_004a2080(0xffffffff,0xffffffff,0xffffffff);
    HCURSOR hCursor = DAT_008cacd8;
    if (!hCursor) hCursor = LoadCursorA(nullptr, (LPCSTR)0x7f02);
    local_bc = GetCursor(); SetCursor(hCursor);
    puVar5 = (uint32_t*)FUN_004afe30();
    if (puVar5) puVar5[1]++;
    uint8_t cVar1 = DAT_00725d98;
    DAT_00726814[DAT_00726820]=DAT_00725d98; DAT_00726820++;
    if (cVar1) FUN_00481100();
    DAT_00725d98=0; DAT_008c9df4=1;
    auto make_obj = [&](int32_t tov)->uint32_t* {
        uint32_t* o=(uint32_t*)FUN_00533c78(0xc0);
        if (o) { o[1]=0; *o=(uint32_t)(intptr_t)&PTR_FUN_006fd14c; o[7]=0; o[0x19]=0; DAT_00727444++; o[0x2f]=0; FUN_004bdca0(tov,0,0,0,0,0xffffffff,0,0,0,0); o[1]++; }
        return o;
    };
    uint32_t* local_d8 = make_obj(DAT_008e9ff0);
    uint32_t* local_dc = make_obj(DAT_008e9ff0);
    uint32_t* local_e4=nullptr, *local_e0=nullptr;
    uint32_t* puVar10=nullptr;
    {
        uint32_t* puVar6 = make_obj(DAT_008e9ffc);
        puVar10 = puVar6;
    }
    if (param_1 < 4) {
        if (DAT_008e9ffc) *(int*)((uint8_t*)(intptr_t)DAT_008e9ffc+4)++;
        const char* names[4] = { "pc_lost_rel_bro.kfm", "pc_lost_rel_sis.kfm", nullptr, nullptr };
        const char* name = (param_1>=0&&param_1<4&&names[param_1])?names[param_1]:"pc_lost_rel_sis.kfm";
        uint32_t* puVar6 = (uint32_t*)FUN_004af680(DAT_008e9ffc, name, 0,0,0,0,0xffffffff,1,0,0,0,0);
        if (puVar6) { puVar6[1]++; local_e4=puVar6; }
        local_e0 = make_obj(DAT_008e9ffc);
    } else {
        const char* desc[3] = { "plain", "attractive", "beautiful" };
        FUN_004f2600("pc_lost_daughter_%s_%d.kfm", desc[DAT_0085bf74[param_2*0x25]&3], (param_2&1)+1);
        if (DAT_008e9ffc) *(int*)((uint8_t*)(intptr_t)DAT_008e9ffc+4)++;
        uint32_t* puVar6 = (uint32_t*)FUN_004af680(DAT_008e9ffc, (const char*)DAT_008cacd0, 0,0,0,0,0xffffffff,1,0,0,0,0);
        if (puVar6) { puVar6[1]++; local_e4=puVar6; }
        uint32_t* o2 = (uint32_t*)FUN_00482ca0(3);
        if (o2) { o2[1]++; local_e0=o2; }
    }
    auto set_flag = [](uint32_t* o){ if (o) { if (o[0x2f]) FUN_004c0870(1); o[8]|=0x8000; } };
    set_flag(local_d8); set_flag(local_dc); set_flag(local_e4); set_flag(local_e0);
    int local_e8=0;
    if (DAT_00869b48[0]) { local_e8=FUN_005f0ddc(); local_e8=4000-local_e8; }
    DAT_007268f4[DAT_00726a84]=(uint32_t)DAT_007263bc; DAT_00726a84++; DAT_007263bc=0xff7fff1;
    if (!puVar10) FUN_004ae4f0(); else FUN_004ae5b0("Camera All");
    FUN_00412840(0x3dcccccd,0x47c35000);
    FUN_004baaa0(); FUN_004beee0(); FUN_004beee0(); FUN_004beee0(); FUN_004baaa0();
    FUN_00533d10(0,1); FUN_004c1000("shadow_01");
    char* local_cc[3] = { nullptr, nullptr, nullptr };
    if (local_d8) { local_d8[0x1e]=(uint32_t)(intptr_t)local_cc[0]; local_d8[0x1f]=(uint32_t)(intptr_t)local_cc[1]; local_d8[0x20]=(uint32_t)(intptr_t)local_cc[2]; }
    if (local_dc) { local_dc[0x1e]=(uint32_t)(intptr_t)local_cc[0]; local_dc[0x1f]=(uint32_t)(intptr_t)local_cc[1]; local_dc[0x20]=(uint32_t)(intptr_t)local_cc[2]; }
    if (local_e0) { local_e0[0x1e]=(uint32_t)(intptr_t)local_cc[0]; local_e0[0x1f]=(uint32_t)(intptr_t)local_cc[1]; local_e0[0x20]=(uint32_t)(intptr_t)local_cc[2]; }
    if (local_e4) { local_e4[0x1e]=(uint32_t)(intptr_t)local_cc[0]; local_e4[0x1f]=(uint32_t)(intptr_t)local_cc[1]; local_e4[0x20]=(uint32_t)(intptr_t)local_cc[2]; }
    FUN_004a21c0();
    int iVar12=1;
    do {
        int iVar11=0;
        if (iVar12!=-1) FUN_004bc0d0();
        int iVar7=FUN_005f0ddc();
        int local_c0=FUN_005f0ddc();
        if (0<iVar7) {
            do {
                int iVar8=FUN_0042e1d0(0);
                if (iVar8==0x1b||iVar8==0x20||iVar8==0xd||DAT_0086c35c||DAT_008cac27) {
                    if (DAT_008c827f) { FUN_00489130((void*)DAT_008c8288); DAT_008c827f=0; }
                    iVar12=7; break;
                }
                uint32_t uVar13; uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,0,iVar11);
                uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,iVar12,iVar11);
                uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,iVar12,iVar11);
                uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,iVar12,iVar11);
                uVar13=FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0,uVar13,100,0xffffffff,0);
                FUN_004bbe10(iVar12,iVar11); FUN_004bbf50();
                if (puVar10) *(uint8_t*)(puVar10+9)=0;
                FUN_004afee0();
                if (local_e8 && FUN_005f0ddc()>=local_e8) FUN_004aff70(DAT_00869b48);
                FUN_004d0cd0(0,0,0); Sleep(5);
                int iVar11b=FUN_005f0ddc(); iVar11b=-iVar11b-local_c0; iVar11=iVar11b;
            } while (iVar11<iVar7);
        }
        iVar12++;
    } while (iVar12<7);
    if (param_3) {
        const char* line = (DAT_00869b1c & 1)==0 ? "'I have an amazing story to tell you.' she says. " : "'I have an amazing story to tell you.' he says. ";
        FUN_004f60b0(line);
        bool bVar3b=false;
        int pi = 1;
        int32_t* p9 = DAT_0085a9a4;
        do {
            if ((p9[-5]==0x28)&&(*p9==0x2a)) { if (pi>0) goto LAB_0045264d; break; }
            p9+=8; pi++;
        } while ((intptr_t)p9 < 0x85b184);
        if ((_DAT_0085a164 & 0x80000)==0) { FUN_0044c4a0(1); FUN_00487e90(); }
        else {
LAB_0045264d:
            if (DAT_00869b1e < 4) {
                FUN_004f60b0("'While held captive I managed to obtain this piece of a map to the legendary lost city of the @LOSTCITY! ", (int)DAT_00869b1e);
                FUN_004f60b0("I will trust this map to you for safekeeping.\n");
                FUN_00487e90(); bVar3b=true;
            } else FUN_004f60b0("'Well, maybe some other time.\n");
        }
        pi=1; p9=DAT_0085a9a4;
        do {
            if ((p9[-5]==0x28)&&(*p9==0x28)) { if (pi>0) FUN_0044d2e0(pi,99); break; }
            p9+=8; pi++;
        } while ((intptr_t)p9 < 0x85b184);
        FUN_00430190((DAT_0085a26c+(DAT_0085a26c>>0x1f&0xfU))>>4, (DAT_0085a268+(DAT_0085a268>>0x1f&7U))>>3, DAT_006fb55c, 0, 0xffffffff, 0, 0, 0xffffffff, 0, 0);
        uint16_t uVar4 = (uint16_t)DAT_00869b1c;
        FUN_0043a970(0x2d, (int)(short)uVar4, 0, 0);
        DAT_00869b1c = (int32_t)uVar4 + 1;
        if (bVar3b) FUN_00493440(2, DAT_0085a3b8, DAT_0085a3f8, 1, 0);
        (void)bVar3;
    }
    FUN_004bef50(); FUN_004bef50(); FUN_004bef50();
    int iVar12b=DAT_008c97c4;
    int iVar11b=DAT_00726820-1;
    uint8_t cVar1b=DAT_00726814[DAT_00726820];
    DAT_00726820=iVar11b;
    if (cVar1b!=DAT_00725d98) {
        if (!cVar1b) { *(uint8_t*)(DAT_008c97c0+0xb4)=0; *(uint8_t*)(reinterpret_cast<uint8_t*>(iVar12b)+0xb4)=0; FUN_00535920(DAT_008e9fe8); FUN_00535920(DAT_008e9fe8); }
        else { *(uint8_t*)(DAT_008c97c0+0xb4)=1; *(uint8_t*)(reinterpret_cast<uint8_t*>(iVar12b)+0xb4)=1; FUN_00535670(DAT_008e9fe8); FUN_00535670(DAT_008e9fe8); }
    }
    DAT_008c9df4=1; DAT_00725d98=cVar1b;
    FUN_004ae4f0();
    DAT_00726a84--; DAT_007263bc=DAT_007268f4[DAT_00726a84];
    auto release = [](uint32_t* o){ if (o) { uint32_t* p=o+1; if (--*p==0) reinterpret_cast<void(*)()>(*o)(1); } };
    release(puVar10); release(local_e0); release(local_e4); release(local_dc); release(local_d8); release(puVar5);
    SetCursor(local_bc);
    return;
}
