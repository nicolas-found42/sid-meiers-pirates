#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <windows.h>

extern void FUN_004c9b00_recon(void);
extern void FUN_004c9bc0_recon(void);
extern void FUN_004ca670_recon(void*);
extern void FUN_004c9c20_recon(int);
extern void FUN_004ccab0_recon(void);
extern void FUN_004c5770_recon(int);
extern void FUN_004c8580_recon(void);
extern void FUN_004cb470_recon(int);
extern void FUN_004cad00_recon(int, uint32_t);
extern void FUN_004c8a10_recon(void);
extern void FUN_004cd100_recon(int);
extern void operator_delete(void*);
extern void operator_delete__(void*);
extern int FUN_00412df0_recon(int);
extern int FUN_004aef70_recon(int);
extern int FUN_004aefd0_recon(int);
extern float FUN_00509500_recon(void*, const void*, int);
extern int FUN_005f0ddc_recon();
extern void FUN_004f3350_recon();
extern void FUN_00412f90_recon();
extern void FUN_004d0cd0_recon(int,int,int);
extern int FUN_0042e1d0_recon(const char*);
extern void FUN_0051bfc0_recon(void*);
extern int FUN_004b2760_recon(int);
extern void* FUN_00533c78_recon(size_t);
extern void FUN_004f32e0_recon();
extern int FUN_004b24a0_recon(int,int);
extern void FUN_004f6090_recon(const char*);
extern int FUN_004b06c0_recon(...);
extern void FUN_004889c0_recon(...);
extern uint32_t FUN_0042c6f0_recon();
extern int FUN_004cc0c0_recon(int*,int,int);
extern int _stricmp(const char*,const char*);
extern int _strnicmp(const char*,const char*,size_t);
extern void FUN_004cc8f0_recon(void);
extern int FUN_004cc9d0_recon();
extern int FUN_004cc990_recon();
extern int FUN_004cca20_recon();
extern void FUN_00412f90b();
extern void FUN_00489300_recon();
extern void FUN_004cd0a0_recon(void);
extern void FUN_0040c490_placeholder();

// Globals used by listings
extern uint32_t DAT_008dc310; extern uint32_t DAT_008dc30c; extern int DAT_008cabe8;
extern int DAT_008cac27; extern int DAT_0086bb5c; extern char DAT_006f588c[];
extern int DAT_008cac18; extern int DAT_008cac1c; extern int DAT_008c9de0; extern int DAT_008c9dd8; extern int DAT_008c9568;
extern int DAT_00726380; extern int DAT_0085a11c; extern int DAT_0086c330;
extern int DAT_008cacd0; extern int DAT_008caccc; extern int DAT_008cacc8; extern int DAT_0086c1a0[]; extern int DAT_0086c010[];
extern int DAT_0086be80[]; extern int DAT_0086bb60[]; extern int DAT_0086bcf0[]; extern char DAT_006fbe48[];
extern int DAT_0072637c; extern char PTR_FUN_0070d8e0; extern int DAT_008c8278;

#define IOFF(base,off,ty) *(ty*)((char*)(base)+(off))

// 0x4c9a10 — observed shape: init call, poll byte at +0xda4, loop calls FUN_004cb470, stores dwords at +0x88/+0x8c, Sleep(10) when DAT_008cabe8==0, break on DAT_008cac27
void FUN_004c9a10_recon(void* self) {
    char cVar1; int iVar2; uint32_t uVar3; uint32_t local_108; char local_104[260];
    FUN_004c9b00_recon();
    cVar1 = IOFF(self,0xda4,char);
    while (cVar1 != '\0') {
        FUN_004cb470_recon((int)(intptr_t)self);
        uVar3 = DAT_008dc310;
        iVar2 = DAT_008cabe8;
        IOFF(self,0x88,uint32_t) = DAT_008dc30c;
        IOFF(self,0x8c,uint32_t) = uVar3;
        if (IOFF((void*)(intptr_t)iVar2,0xc,char) == '\0') {
            FUN_004d0cd0_recon(0,0,0);
            local_108 = (uint32_t)FUN_0042e1d0_recon(&DAT_006f588c[0]);
            uVar3 = local_108;
            if (DAT_0086bb5c != 0) {
                sprintf(local_104, "%s_%03X", &DAT_006f588c[0], local_108);
                FUN_0051bfc0_recon(&local_108);
                uVar3 = local_108;
            }
        } else {
            uVar3 = (uint32_t)FUN_004b2760_recon(0);
        }
        FUN_004cad00_recon((int)(intptr_t)self, uVar3);
        if (DAT_008cabe8 == 0) Sleep(10);
        if (DAT_008cac27 != '\0') break;
        cVar1 = IOFF(self,0xda4,char);
    }
    FUN_004c9bc0_recon();
}

// 0x4c9b00 — observed shape: *in_EAX=1; DAT_008c9de0=DAT_008c9dd8; sets +0x6e4=0, computes +0xde8 float, calls FUN_004ca670/+0x80 handling, FUN_004c9c20, FUN_004ccab0
void FUN_004c9b00_recon(void* self) {
    uint8_t* e = (uint8_t*)self;
    float fVar1, fVar2, fVar3; int iVar4;
    *e = 1;
    iVar4 = DAT_008cac18 * 0x43;
    DAT_008c9de0 = DAT_008c9dd8;
    fVar1 = *(float*)(DAT_008c9dd8 + 4);
    fVar3 = (float)DAT_00726380;
    DAT_0085a11c = 0x43;
    DAT_0086c330 = 0;
    fVar2 = (float)DAT_008cac1c;
    IOFF(self,0x6e4,uint32_t) = 0;
    IOFF(self,0xde8,float) = ((fVar3 * fVar1) / fVar2 + 2.0f) * (float)((int)(iVar4 + (iVar4 >> 0x1f & 0x3ffU)) >> 10) * 0.01f;
    FUN_004ca670_recon(self);
    iVar4 = IOFF(self,0x80,int);
    if (*(int*)(iVar4 + -4) == 1) { FUN_00412df0_recon(iVar4); }
    else { FUN_00412df0_recon(iVar4); }
    FUN_004c5770_recon(iVar4);
    FUN_004c9c20_recon((int)(intptr_t)self);
    FUN_004c8580_recon();
    FUN_004ccab0_recon();
}

// 0x4c9bc0 — observed shape: calls FUN_004c8a10; clears +0x6e4; if (+0xdc0)!=0, FUN_004cd100(1) when [1], operator_delete__(ptr-8) except DAT_008cacc8, sets *ptr=DAT_008cacd0, operator_delete, clears +0xdc0, DAT_0086c330=0
void FUN_004c9bc0_recon(void* self) {
    int* piVar1; uint32_t* puVar2; int unaff_EBX;
    FUN_004c8a10_recon();
    (void)unaff_EBX;
    piVar1 = IOFF(self,0xdc0,int*);
    IOFF(self,0x6e4,uint32_t) = 0;
    if (piVar1 != nullptr) {
        if (piVar1[1] != 0) { FUN_004cd100_recon(1); piVar1[1] = 0; }
        puVar2 = (uint32_t*)(*piVar1 + -8);
        if (puVar2 != nullptr && puVar2 != (uint32_t*)&DAT_008cacc8) operator_delete__(puVar2);
        *piVar1 = (int)(intptr_t)&DAT_008cacd0;
        operator_delete(piVar1);
        IOFF(self,0xdc0,uint32_t) = 0;
    }
    DAT_0086c330 = 0;
}

// 0x4c9c20 — observed shape: two-phase table fill using DAT_0085a11c=100, substr windows at +0xda8, FUN_00509500, writes index iVar9 into DAT_0086c1a0/c010/be80/bb60/bcf0, appends to +0x6e4 array; then 4-row loop over +0xdc0 list with 0x118/row counts
void FUN_004c9c20_recon(int param_1) {
    int* piVar1; short sVar2; uint8_t* puVar3; size_t _Size; short sVar4, sVar5, sVar6;
    int iVar7, iVar8, iVar9; size_t sVar10; uint32_t* local_20; int local_1c, local_18, local_10; short local_c;
    DAT_0085a11c = 100;
    FUN_004aef70_recon(IOFF((void*)(intptr_t)param_1,0xdac,int));
    iVar7 = *(int*)(*(int*)(param_1 + 0xda8) + -4);
    DAT_0085a11c = 100;
    FUN_004aefd0_recon(0);
    IOFF((void*)(intptr_t)param_1,0x6e4,uint32_t) = 5;
    local_10 = 0;
    if (0 < iVar7) {
        local_c = (short)(FUN_005f0ddc_recon() + 0x3c);
        do {
            sVar10 = 1; iVar9 = local_10; if (local_10 < 0) iVar9 = 0;
            puVar3 = IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*) - 4;
            _Size = *(size_t*)(puVar3 + 4 - 4 + 4); // *(size_t*)(puVar3+...) simplified: size at puVar3-4 handled below
            _Size = *(size_t*)(IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*) - 4);
            if ((int)_Size < iVar9 + 1) sVar10 = _Size - iVar9;
            if ((int)_Size < iVar9) sVar10 = 0;
            if ((iVar9 == 0) && (sVar10 == _Size)) {
                if ((-1 < (int)_Size) && (IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*) != nullptr) && (IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*) != (uint8_t*)&DAT_008cacd0)) {
                    if (_Size == 0) FUN_00412f90_recon();
                    else { FUN_004f3350_recon(); memmove((void*)&DAT_008cacd0, IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*), _Size); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
                }
            } else if ((-1 < (int)sVar10) && (IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*) != nullptr && IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*) != (uint8_t*)&DAT_008cacd0)) {
                if (sVar10 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                else { FUN_004f3350_recon(); memmove((void*)&DAT_008cacd0, IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*) + iVar9, sVar10); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
            }
            DAT_0085a11c = 100; DAT_008c9de0 = DAT_008c9568; if (DAT_008c9568 == 0) DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500_recon((void*)(intptr_t)DAT_008c9de0, &DAT_008cacd0, 0);
            sVar4 = (short)FUN_005f0ddc_recon(); sVar6 = (short)DAT_0086c330; iVar9 = (int)DAT_0086c330;
            (&DAT_0086c1a0)[iVar9] = *(uint16_t*)(param_1 + 0x6e4); (&DAT_0086c010)[iVar9] = sVar4; (&DAT_0086be80)[iVar9] = 0x3c;
            sVar5 = (short)FUN_005f0ddc_recon(); (&DAT_0086bb60)[iVar9] = local_c;
            DAT_0085a11c = 100; (&DAT_0086bcf0)[iVar9] = sVar5 + sVar4; DAT_0086c330 = sVar6 + 1;
            DAT_008c9de0 = DAT_008c9568; if (DAT_008c9568 == 0) DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500_recon((void*)(intptr_t)DAT_008c9de0, &DAT_006fbe48[0], 0);
            iVar8 = DAT_008caccc; iVar9 = IOFF((void*)(intptr_t)param_1,0x6e4,int);
            piVar1 = (int*)(param_1 + 0x6e8 + iVar9 * 8);
            if ((-1 < DAT_008caccc) && (*piVar1 != (int)(intptr_t)&DAT_008cacd0)) {
                if (DAT_008caccc == 0) { if (*(int*)(*piVar1 + -4) != 0) { *(uint8_t*)(*piVar1) = 0; *(uint32_t*)(*piVar1 + -4) = 0; } }
                else { FUN_004f3350_recon(); memmove((void*)*piVar1, &DAT_008cacd0, iVar8); *(uint8_t*)(*piVar1 + *(int*)(*piVar1 + -4)) = 0; }
            }
            piVar1[1] = iVar9; IOFF((void*)(intptr_t)param_1,0x6e4,int) = IOFF((void*)(intptr_t)param_1,0x6e4,int) + 1;
            local_10 = local_10 + 1;
        } while (local_10 < iVar7);
    }
    local_20 = *(uint32_t**)(*(int*)(param_1 + 0xdc0) + 4);
    local_18 = 0;
    do {
        if (local_20 == nullptr) return;
        sVar6 = (short)((int)(DAT_0072637c + -0x54 + (DAT_0072637c + -0x54 >> 0x1f & 3U)) >> 2) * (short)local_18 + 0x2a;
        local_1c = 0;
        iVar7 = FUN_005f0ddc_recon();
        if (0 < (int)(0x118 / (long long)iVar7)) {
            do {
                iVar7 = DAT_008c9dd8; if (local_20 == nullptr) break;
                DAT_0085a11c = 0x43; DAT_008c9de0 = DAT_008c9dd8;
                sVar4 = (short)FUN_005f0ddc_recon();
                puVar3 = (uint8_t*)*local_20; sVar10 = *(size_t*)(puVar3 + -4);
                sVar5 = (short)(sVar4 * (short)local_1c + 100);
                if ((-1 < (int)sVar10) && (puVar3 != nullptr) && (puVar3 != (uint8_t*)&DAT_008cacd0)) {
                    if (sVar10 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                    else { if (0 < (int)sVar10) { if (DAT_008cacc8 < (int)sVar10) FUN_004f32e0_recon(); DAT_008caccc = (int)sVar10; } memmove((void*)&DAT_008cacd0, puVar3, sVar10); iVar7 = DAT_008c9dd8; ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
                }
                DAT_0085a11c = 0x43; DAT_008c9de0 = iVar7;
                FUN_00509500_recon((void*)(intptr_t)iVar7, &DAT_008cacd0, 0);
                local_10 = (short)FUN_005f0ddc_recon();
                if (DAT_008caccc == 1) local_10 = 0x10;
                iVar8 = FUN_005f0ddc_recon(); iVar9 = DAT_008caccc;
                iVar7 = IOFF((void*)(intptr_t)param_1,0xdb0,int);
                piVar1 = (int*)(param_1 + 0x6e8 + IOFF((void*)(intptr_t)param_1,0x6e4,int) * 8);
                if ((-1 < DAT_008caccc) && (*piVar1 != (int)(intptr_t)&DAT_008cacd0)) {
                    if (DAT_008caccc == 0) { if (*(int*)(*piVar1 + -4) != 0) { *(uint8_t*)(*piVar1) = 0; *(uint32_t*)(*piVar1 + -4) = 0; } }
                    else { if (0 < DAT_008caccc) { if (*(int*)(*piVar1 + -8) < DAT_008caccc) FUN_004f32e0_recon(); *(int*)(*piVar1 + -4) = iVar9; } memmove((void*)*piVar1, &DAT_008cacd0, iVar9); *(uint8_t*)(*piVar1 + *(int*)(*piVar1 + -4)) = 0; }
                }
                piVar1[1] = (int)(0x118 / (long long)iVar8) * local_18 + local_1c + 5 + iVar7;
                iVar9 = (int)DAT_0086c330; iVar7 = FUN_005f0ddc_recon(); sVar2 = *(short*)(param_1 + 0xdb0);
                (&DAT_0086be80)[iVar9] = sVar5;
                (&DAT_0086c1a0)[iVar9] = (short)(0x118 / (long long)iVar7) * (short)local_18 + (short)local_1c + sVar2 + 5;
                (&DAT_0086c010)[iVar9] = sVar6; (&DAT_0086bcf0)[iVar9] = sVar6 + (short)local_10;
                DAT_0086c330 = DAT_0086c330 + 1; (&DAT_0086bb60)[iVar9] = sVar5 + sVar4;
                IOFF((void*)(intptr_t)param_1,0x6e4,int) = IOFF((void*)(intptr_t)param_1,0x6e4,int) + 1;
                local_20 = (uint32_t*)local_20[1]; local_1c = local_1c + 1;
                iVar7 = FUN_005f0ddc_recon();
            } while (local_1c < (int)(0x118 / (long long)iVar7));
        }
        local_18 = local_18 + 1;
        if (3 < local_18) return;
    } while(true);
}

// 0x4ca490 — observed shape: allocates +0xdbc list node (12 bytes), zeroes +0xdb4, walks *(+0x74)+4 list, copies %-filtered strings to DAT_008cacd0, inserts sorted via _stricmp into +0xdbc list
void FUN_004ca490_recon(int param_1) {
    uint32_t* puVar1; char* _Src; size_t sVar2; uint8_t* _Src00; uint8_t* puVar3; uint32_t* puVar4; int* piVar5; int iVar6;
    puVar4 = (uint32_t*)FUN_00533c78_recon(0xc);
    if (puVar4 == nullptr) puVar4 = nullptr;
    else { *puVar4 = (uint32_t)(intptr_t)&DAT_008cacd0; puVar4[1] = 0; puVar4[2] = 0; }
    *(uint32_t**)(param_1 + 0xdbc) = puVar4;
    *(uint32_t*)(param_1 + 0xdb4) = 0;
    puVar1 = *(uint32_t**)(*(int*)(param_1 + 0x74) + 4);
    do {
        if (puVar1 == nullptr) return;
        _Src = (char*)(intptr_t)*puVar1;
        if (*_Src != '%') {
            sVar2 = *(size_t*)(_Src + -4);
            if ((-1 < (int)sVar2) && (_Src != nullptr) && (_Src != (char*)&DAT_008cacd0)) {
                if (sVar2 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                else { FUN_004f3350_recon(); memmove((void*)&DAT_008cacd0, _Src, sVar2); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
            }
            if ((0 < DAT_008caccc) && (*(char*)((int)(intptr_t)&DAT_008caccc + DAT_008caccc + 3) != '%')) {
                piVar5 = (int*)FUN_00533c78_recon(0xc);
                if (piVar5 == nullptr) piVar5 = nullptr;
                else { *piVar5 = (int)(intptr_t)&DAT_008cacd0; piVar5[1] = 0; piVar5[2] = 0; }
                _Src00 = (uint8_t*)(intptr_t)*puVar1; sVar2 = *(size_t*)(_Src00 + -4);
                if ((-1 < (int)sVar2) && (_Src00 != nullptr) && (puVar3 = (uint8_t*)(intptr_t)*piVar5, _Src00 != puVar3)) {
                    if (sVar2 == 0) { if (*(int*)(puVar3 + -4) != 0) { *puVar3 = 0; *(uint32_t*)(*piVar5 + -4) = 0; } }
                    else { FUN_004f3350_recon(); memmove((void*)*piVar5, _Src00, sVar2); *(uint8_t*)(*piVar5 + *(int*)(*piVar5 + -4)) = 0; }
                }
                if (puVar4[1] != 0) {
                    do { iVar6 = _stricmp((char*)(intptr_t)*piVar5, *(char**)(intptr_t)puVar4[1]); if (iVar6 < 1) break; puVar4 = (uint32_t*)(intptr_t)puVar4[1]; } while (puVar4[1] != 0);
                }
                piVar5[1] = (int)(intptr_t)puVar4[1]; piVar5[2] = (int)(intptr_t)puVar4; puVar4[1] = (uint32_t)(intptr_t)piVar5;
                if (piVar5[1] != 0) *(int**)(piVar5[1] + 8) = piVar5;
                puVar4 = *(uint32_t**)(param_1 + 0xdbc);
                *(int*)(param_1 + 0xdb4) = *(int*)(param_1 + 0xdb4) + 1;
            }
        }
        puVar1 = (uint32_t*)(intptr_t)puVar1[1];
    } while(true);
}
// 0x4ca670 — observed shape: copies *(+0x80) string to local+0x1c, allocates +0xdc0 node, iterates 0x118-row lists at +0xdbc, sorted insertion via _strnicmp/_stricmp with FUN_004c4560 fallback, truncates via strstr at +0xda8
void FUN_004ca670_recon(void* self) {
    int param_1 = (int)(intptr_t)self;
    uint8_t* puVar1; size_t _Size; int iVar2; int* piVar3; uint32_t* puVar4; char* pcVar5; uint32_t _Size00; size_t sVar6; char* pcVar7; char* pcVar8; int* piVar9; bool bVar10;
    char local_20[4]; char* local_1c; char* local_18; char* local_14; uint32_t* local_10; uint8_t* local_c; uint8_t* local_8; int local_4;
    puVar1 = IOFF(self,0x80,uint8_t*);
    sVar6 = *(size_t*)(puVar1 + -4);
    local_1c = (char*)&DAT_008cacd0; local_18 = (char*)&DAT_008cacd0;
    if ((-1 < (int)sVar6) && (puVar1 != nullptr) && (puVar1 != (uint8_t*)&DAT_008cacd0)) {
        if (sVar6 == 0) FUN_00412f90_recon();
        else { FUN_004f3350_recon(); pcVar5 = local_1c; memmove(local_1c, puVar1, sVar6); pcVar5[*(int*)(pcVar5 + -4)] = '\0'; }
    }
    local_10 = (uint32_t*)FUN_00533c78_recon(0xc);
    if (local_10 == nullptr) local_10 = nullptr;
    else { *local_10 = (uint32_t)(intptr_t)&DAT_008cacd0; local_10[1] = 0; local_10[2] = 0; }
    *(uint32_t**)(param_1 + 0xdc0) = local_10;
    local_14 = *(char**)(*(int*)(param_1 + 0xdbc) + 4);
    iVar2 = FUN_005f0ddc_recon();
    *(uint32_t*)(param_1 + 0xdb8) = 0;
    local_4 = (int)(0x118 / (long long)iVar2) * 4;
    if (0 < local_4) {
        do {
            pcVar5 = local_14;
            piVar3 = (int*)FUN_00533c78_recon(0xc); pcVar8 = local_1c; piVar9 = nullptr;
            if (piVar3 != nullptr) { piVar3[1] = 0; piVar3[2] = 0; *piVar3 = (int)(intptr_t)&DAT_008cacd0; piVar9 = piVar3; }
            sVar6 = *(size_t*)(local_1c + -4);
            if ((-1 < (int)sVar6) && (pcVar7 = (char*)(intptr_t)*piVar9, local_1c != pcVar7)) {
                if (sVar6 == 0) { if (*(int*)(pcVar7 + -4) != 0) { *pcVar7 = '\0'; *(uint32_t*)(*piVar9 + -4) = 0; } }
                else { FUN_004f3350_recon(); memmove((void*)*piVar9, pcVar8, sVar6); *(uint8_t*)(*piVar9 + *(int*)(*piVar9 + -4)) = 0; }
            }
            local_10[1] = (uint32_t)(intptr_t)piVar9; piVar9[2] = (int)(intptr_t)local_10; local_10 = (uint32_t*)(intptr_t)local_10[1];
            *(int*)(param_1 + 0xdb8) = *(int*)(param_1 + 0xdb8) + 1;
            local_20[0] = *pcVar8; bVar10 = local_20[0] != '\0'; pcVar7 = local_18;
            if (local_20 != local_18) {
                if (bVar10 == 0) { if (*(int*)(local_18 + -4) != 0) { *local_18 = '\0'; *(int*)((char*)local_18 - 4) = 0; } }
                else { FUN_004f3350_recon(); pcVar7 = local_18; memmove(local_18, local_20, (uint32_t)bVar10); pcVar7[*(int*)(pcVar7 + -4)] = '\0'; }
            }
            local_8 = nullptr;
            if (0 < *(int*)(param_1 + 0xdb4)) {
                do {
                    if (pcVar5 == nullptr) { pcVar5 = *(char**)(*(int*)(param_1 + 0xdbc) + 4); local_14 = pcVar5; }
                    iVar2 = *(int*)(pcVar8 + -4); bVar10 = iVar2 == 1;
                    if (bVar10) {
                        iVar2 = _strnicmp(*(char**)pcVar5, pcVar8, 1);
                        if (iVar2 != 0) { iVar2 = *(int*)(pcVar8 + -4); bVar10 = iVar2 == 1; goto LAB_004ca85e; }
LAB_004ca890:
                        piVar3 = (int*)FUN_00533c78_recon(0xc); piVar9 = nullptr;
                        if (piVar3 != nullptr) { piVar3[1] = 0; piVar3[2] = 0; *piVar3 = (int)(intptr_t)&DAT_008cacd0; piVar9 = piVar3; }
                        uint8_t* puVar11 = (uint8_t*)&DAT_008cacd0; puVar1 = *(uint8_t**)local_14; sVar6 = *(size_t*)(puVar1 + -4);
                        if ((-1 < (int)sVar6) && (puVar1 != nullptr) && (puVar1 != (uint8_t*)&DAT_008cacd0)) {
                            if (sVar6 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                            else { if (0 < (int)sVar6) { if (DAT_008cacc8 < (int)sVar6) FUN_004f32e0_recon(); *(size_t*)(puVar11 + -4) = sVar6; } memmove(puVar11, puVar1, sVar6); puVar11[*(int*)(puVar11 + -4)] = 0; }
                        }
                        puVar4 = (uint32_t*)FUN_00533c78_recon(0xc);
                        puVar1 = (uint8_t*)(intptr_t)*puVar4; sVar6 = *(size_t*)(puVar1 + -4);
                        if ((-1 < (int)sVar6) && (puVar1 != nullptr) && (puVar11 = (uint8_t*)(intptr_t)*piVar9, puVar1 != puVar11)) {
                            if (sVar6 == 0) { if (*(int*)(puVar11 + -4) != 0) { *puVar11 = 0; *(uint32_t*)(*piVar9 + -4) = 0; } }
                            else { if (0 < (int)sVar6) { if (*(int*)(puVar11 + -8) < (int)sVar6) FUN_004f32e0_recon(); *(size_t*)(*piVar9 + -4) = sVar6; } memmove((void*)*piVar9, puVar1, sVar6); *(uint8_t*)(*piVar9 + *(int*)(*piVar9 + -4)) = 0; }
                        }
                        if (local_c != nullptr && local_c != (uint8_t*)&DAT_008cacc8) operator_delete__((int*)local_c - 2);
                        local_10[1] = (uint32_t)(intptr_t)piVar9; piVar9[2] = (int)(intptr_t)local_10; local_10 = (uint32_t*)(intptr_t)local_10[1];
                        *(int*)(param_1 + 0xdb8) = *(int*)(param_1 + 0xdb8) + 1;
                        local_c = (uint8_t*)&DAT_008cacd0; pcVar5 = local_14; pcVar8 = local_1c; pcVar7 = local_18;
                    } else {
LAB_004ca85e:
                        if (!bVar10 && 0 < iVar2) { iVar2 = _strnicmp(*(char**)pcVar5, pcVar7, 1); if (iVar2 == 0) { iVar2 = _stricmp(*(char**)pcVar5, pcVar8); if (0 < iVar2) goto LAB_004ca890; } }
                    }
                    pcVar5 = *(char**)(pcVar5 + 4); local_8 = local_8 + 1; local_14 = pcVar5;
                } while ((int)(intptr_t)local_8 < *(int*)(param_1 + 0xdb4));
            }
            if (*(int*)(param_1 + 0xdb8) < local_4) {
                local_20[0] = *pcVar8; _Size00 = (uint32_t)(local_20[0] != '\0');
                if (local_20 != pcVar7) {
                    if (_Size00 == 0) { if (*(int*)(pcVar7 + -4) != 0) { *pcVar7 = '\0'; *(int*)((char*)pcVar7 - 4) = 0; } }
                    else { if (*(int*)(pcVar7 + -8) < (int)_Size00) { FUN_004f32e0_recon(); pcVar7 = local_18; } *(uint32_t*)(pcVar7 + -4) = _Size00; memmove(pcVar7, local_20, _Size00); pcVar7[*(int*)(pcVar7 + -4)] = '\0'; }
                }
                if ((0 < *(int*)(*(char**)(param_1 + 0xda8) + -4)) && (pcVar5 = strstr(*(char**)(param_1 + 0xda8), pcVar7), pcVar5 != nullptr) && (iVar2 = (int)(intptr_t)pcVar5 - *(int*)(param_1 + 0xda8), iVar2 != -1)) {
                    iVar2 = (iVar2 + 1) % *(int*)(param_1 + 0xdb0);
                    sVar6 = 1; if (iVar2 < 0) iVar2 = 0;
                    local_8 = *(uint8_t**)(param_1 + 0xda8); _Size = *(size_t*)(local_8 + -4);
                    if ((int)_Size < iVar2 + 1) sVar6 = _Size - iVar2;
                    if ((int)_Size < iVar2) sVar6 = 0;
                    if ((iVar2 == 0) && (sVar6 == _Size)) {
                        pcVar8 = (char*)&DAT_008cacd0; local_14 = (char*)&DAT_008cacd0;
                        if ((-1 < (int)_Size) && (local_8 != nullptr && local_8 != (uint8_t*)&DAT_008cacd0)) {
                            if (_Size == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                            else { FUN_004f3350_recon(); pcVar8 = local_14; memmove(local_14, local_8, _Size); pcVar8[*(int*)(pcVar8 + -4)] = '\0'; }
                        }
                    } else {
                        pcVar5 = (char*)&DAT_008cacd0; local_14 = (char*)&DAT_008cacd0;
                        if ((-1 < (int)sVar6) && (-1 < iVar2) && (local_8 != nullptr) && (local_8 != (uint8_t*)&DAT_008cacd0)) {
                            if (sVar6 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                            else { FUN_004f3350_recon(); pcVar5 = local_14; memmove(local_14, local_8 + iVar2, sVar6); pcVar5[*(int*)(pcVar5 + -4)] = 0; }
                        }
                        sVar6 = *(size_t*)(pcVar5 + -4); pcVar8 = (char*)&DAT_008cacd0; local_14 = (char*)&DAT_008cacd0;
                        if ((-1 < (int)sVar6) && (pcVar5 != (char*)&DAT_008cacd0)) {
                            if (sVar6 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                            else { FUN_004f3350_recon(); pcVar8 = local_14; memmove(local_14, pcVar5, sVar6); pcVar8[*(int*)(pcVar8 + -4)] = '\0'; }
                        }
                        piVar9 = (int*)(pcVar5 + -8);
                        if (piVar9 != nullptr && piVar9 != (int*)&DAT_008cacc8) operator_delete__(piVar9);
                    }
                    sVar6 = *(size_t*)(pcVar8 + -4); pcVar5 = local_1c;
                    if ((-1 < (int)sVar6) && (pcVar8 != local_1c)) {
                        if (sVar6 == 0) { if (*(int*)(local_1c + -4) != 0) { *local_1c = '\0'; *(int*)((char*)local_1c - 4) = 0; } }
                        else { if (0 < (int)sVar6) { if (*(int*)(local_1c + -8) < (int)sVar6) FUN_004f32e0_recon(); *(size_t*)(local_1c + -4) = sVar6; } pcVar5 = local_1c; memmove(local_1c, pcVar8, sVar6); pcVar5[*(int*)(pcVar5 + -4)] = '\0'; }
                    }
                    piVar9 = (int*)(pcVar8 + -8);
                    if (piVar9 != nullptr && piVar9 != (int*)&DAT_008cacc8) { operator_delete__(piVar9); pcVar5 = local_1c; }
                    if (*(int*)(pcVar5 + -4) == 0) break;
                }
            }
            local_14 = *(char**)(*(int*)(param_1 + 0xdbc) + 4);
        } while (*(int*)(param_1 + 0xdb8) < local_4);
    }
    piVar9 = (int*)(local_18 + -8);
    if (piVar9 != nullptr && piVar9 != (int*)&DAT_008cacc8) operator_delete__(piVar9);
    piVar9 = (int*)(local_1c + -8);
    if (piVar9 != nullptr && piVar9 != (int*)&DAT_008cacc8) operator_delete__(piVar9);
}
// 0x4cad00 — observed shape: uint return, param_1 dword array (0x36c count, 0x36a table, 0x1b9 limit, key dispatch table), alpha/toupper match loop, then key code switch (0x127/0x124/0xd/0x10c/0x121/0x125/0x126/0x128/0x200-0x204, 0x1/0x1b) with GetAsyncKeyState(0x10) branches
extern int FUN_004cc3c0_recon(void);
extern int FUN_004cc4d0_recon(void);
extern int FUN_004cc5e0_recon(void);
extern int FUN_004cc760_recon(void);
extern void FUN_004c4980_recon(void);
extern void FUN_004c4860_recon(void);
extern void FUN_004c5960_recon(void);
extern void FUN_004c5910_recon(void);
extern void FUN_004a2380_recon(void);
extern void FUN_0042e730_recon(void);
extern void FUN_004c5840_recon(void);
extern void FUN_00412ec0_recon(void);
extern void FUN_004cd150_recon(void);
extern void FUN_004888e0_recon(int,int,int,uint32_t);
extern char FUN_004c5c50_recon(void*,int);
uint32_t FUN_004cad00_recon(int param_1, uint32_t param_2) {
    uint32_t* puVar4 = (uint32_t*)(intptr_t)param_1;
    uint32_t local_c = 0; int iVar7; uint32_t uVar8; int local_8;
    int16_t SVar6; char cVar5;
    if (0 < (int)puVar4[0x36c]) {
        do {
            if (param_2 == local_c + 0x205) {
LAB_004cad8b:
                uVar8 = (uint32_t)(*(char*)(local_c + puVar4[0x36a]) != '\0');
                char tmpc = *(char*)(local_c + puVar4[0x36a]);
                if (uVar8 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                else { FUN_004f3350_recon(); memmove((void*)&DAT_008cacd0, &tmpc, uVar8); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
                iVar7 = _stricmp((char*)&DAT_008cacd0, (char*)(intptr_t)puVar4[0x20]);
                if (iVar7 != 0) {
                    if ((DAT_008caccc < 0) || ((uint8_t*)(intptr_t)puVar4[0x20] == (uint8_t*)&DAT_008cacd0)) goto LAB_004cb022;
                    if (DAT_008caccc != 0) goto LAB_004cae55_label;
                    FUN_00412f90_recon(); goto LAB_004cb022;
                }
            } else if ((param_2 >= (uint32_t)-0x81) && ((int)param_2 < 0x100) && isalpha(param_2 & 0xff)) {
                if ((char)param_2 < -0x80 || (char)param_2 > 0) {}
                iVar7 = toupper(param_2 & 0xff);
                if (*(char*)(puVar4[0x36a] + local_c) == iVar7) goto LAB_004cad8b;
            }
            local_c = local_c + 1;
        } while ((int)local_c < (int)puVar4[0x36c]);
    }
    local_8 = puVar4[0x36c] + 5; uVar8 = param_2;
    if (local_8 < (int)puVar4[0x1b9]) {
        uint32_t key = puVar4[0x36c] + 0x205;
        uint32_t* p1 = puVar4 + local_8 * 2 + 0x1ba;
        do {
            if (uVar8 == key) {
                uint8_t* puVar2 = (uint8_t*)(intptr_t)*p1;
                if (*(int*)(puVar2 + -4) != 1) {
                    uint32_t* pp = (uint32_t*)(intptr_t)puVar4[local_8*2+0x1ba]; int* piVar1 = puVar4+0x20; int _Sz = pp[-1];
                    if ((-1 < _Sz) && (pp != nullptr) && (pp != (uint32_t*)(intptr_t)*piVar1)) {
                        if (_Sz != 0) { FUN_004f3350_recon(); memmove((void*)*piVar1, pp, _Sz); *(uint8_t*)(*piVar1 + *(int*)(*piVar1 + -4)) = 0; puVar4[0x1f]=1; *(uint8_t*)(puVar4+0x369)=0; goto LAB_004cb19b; }
                        if (*(int*)(pp-1)!=0) { *(uint8_t*)pp=0; *(uint32_t*)(*piVar1-4)=0; }
                    }
                    puVar4[0x1f]=1; *(uint8_t*)(puVar4+0x369)=0; goto LAB_004cb19b;
                }
                if ((puVar2 != nullptr) && (puVar2 != (uint8_t*)&DAT_008cacd0)) {
                    if (DAT_008cacc8 < 1) FUN_004f32e0_recon();
                    DAT_008caccc = 1; memmove((void*)&DAT_008cacd0, puVar2, 1); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0;
                }
                iVar7 = _stricmp((char*)&DAT_008cacd0, (char*)(intptr_t)puVar4[0x20]);
                if (iVar7 != 0) {
                    if ((-1 < DAT_008caccc) && ((puVar2=(uint8_t*)(intptr_t)puVar4[0x20], puVar2 != (uint8_t*)&DAT_008cacd0))) {
                        if (DAT_008caccc == 0) { if (*(int*)(puVar2-4)!=0){*puVar2=0;*(uint32_t*)(puVar4[0x20]-4)=0;} }
                        else { LAB_004cae55_label: iVar7 = DAT_008caccc; FUN_004f3350_recon(); memmove((void*)(intptr_t)puVar4[0x20], &DAT_008cacd0, iVar7); iVar7 = puVar4[0x20]; *(uint8_t*)(iVar7+*(int*)(iVar7-4))=0; }
                    }
LAB_004cb022:
                    puVar4[0x1f]=0; *(uint8_t*)(puVar4+0x369)=0; FUN_004888e0_recon(0x2d,-1,-1,0xbf800000); return param_2;
                }
                uVar8 = param_2;
            }
            local_8 = local_8+1; p1 = p1+2; key = key+1;
        } while (local_8 < (int)puVar4[0x1b9]);
    }
    if ((int)uVar8 < 0x128) {
        if (uVar8 == 0x127) { FUN_004cc3c0_recon(); FUN_004a2380_recon(); goto LAB_004cb2e4; }
        if ((int)uVar8 < 0x125) {
            if (uVar8 == 0x124) { SVar6 = GetAsyncKeyState(0x10); if (SVar6==0) FUN_004c4980_recon(); else FUN_004c5960_recon(); goto LAB_004cb2e4; }
            if ((uVar8 == 0xd) || (uVar8 == 0x10c)) {
                if (puVar4[0x34b] != -1) {
                    iVar7 = *(int*)((char*)(intptr_t)puVar4[0x34a] + -4);
                    if (iVar7 == 1) {
                        iVar7 = _stricmp((char*)(intptr_t)puVar4[0x34a], (char*)(intptr_t)puVar4[0x20]);
                        if (iVar7 != 0) { *(uint8_t*)(puVar4+0x369)=0; FUN_00412ec0_recon(); puVar4[0x1f]=0; goto LAB_004cb19b; }
                    } else {
                        FUN_00412df0_recon(iVar7); cVar5 = FUN_004c5c50_recon(puVar4,iVar7);
                        if (cVar5 != '\0') { *(uint8_t*)(puVar4+0x369)=0; FUN_00412ec0_recon(); puVar4[0x1f]=1; FUN_004cd150_recon(); goto LAB_004cb19b; }
                    }
                    goto LAB_004cb2d6;
                }
            } else if (uVar8 == 0x121) { SVar6 = GetAsyncKeyState(0x10); if (SVar6==0) FUN_004c4860_recon(); else FUN_004c5910_recon(); goto LAB_004cb2e4; }
        } else {
            if (uVar8 == 0x125) { FUN_004cc4d0_recon(); FUN_0042e730_recon(); goto LAB_004cb2e4; }
            if (uVar8 == 0x126) { FUN_004cc5e0_recon(); FUN_0042e730_recon(); goto LAB_004cb2e4; }
        }
    } else {
        switch(uVar8) {
        case 0x128: FUN_004cc760_recon(); FUN_0042e730_recon(); break;
        case 0x200: FUN_004c5960_recon(); break;
        case 0x201: FUN_004c5910_recon(); break;
        case 0x202: FUN_004cd0a0_recon(); puVar4[0x1f]=0; *(uint8_t*)(puVar4+0x369)=0; FUN_004888e0_recon(0x2d,-1,-1,0xbf800000); break;
        case 0x203: FUN_004c4980_recon(); break;
        case 0x204: FUN_004c4860_recon(); break;
        default: goto LAB_004cb2da;
        }
LAB_004cb2d6:
        uVar8 = param_2;
    }
LAB_004cb2da:
    if ((uVar8 == 1) || (uVar8 == 0x1b)) { *(uint8_t*)puVar4=0; *(uint8_t*)(puVar4+0x369)=0; FUN_0042e730_recon(); return param_2; }
LAB_004cb2e4:
    FUN_004c5840_recon();
    if (((puVar4[0x22]==DAT_008dc30c) && (puVar4[0x23]==DAT_008dc310)) || (FUN_0042c6f0_recon()==puVar4[0x34b])) return param_2;
    if (*(int*)((uint8_t*)(intptr_t)puVar4[0x34a]+-4)!=0) { *(uint8_t*)(intptr_t)puVar4[0x34a]=0; *(uint32_t*)(puVar4[0x34a]-4)=0; }
    puVar4[0x34b] = 0xffffffff; return param_2;
LAB_004cb19b:
    FUN_004888e0_recon(0x2d,-1,-1,0xbf800000); return param_2;
}
// 0x4cb470 — observed shape: Pirate-O-Pedia render, two loops over +0xda8 substrings and +0xdc0 list (0x118 rows x 4), textHighlightBar.dds draw, DAT_0085a11c size fields, FUN_004b06c0 text calls with 0x43/100 sizes
extern void FUN_004c4640_recon(void);
extern void FUN_005096b0_recon(void);
extern void* FUN_004cddf0_recon(const char*,int,int,void*,void*);
extern void FUN_004af080_recon(void*,int,int,void*,void*,int,int,int,uint32_t,uint32_t,int);
void FUN_004cb470_recon(int param_1) {
    size_t _Size; float* pfVar1; int iVar2, iVar3, iVar4, iVar5; uint32_t uVar4, uVar5; int extraout_ECX; int iVar6; uint8_t* puVar7; uint8_t* _Dst; int* piVar8; size_t sVar9; bool bVar10; float10 fVar11; float fVar12;
    char local_36; uint8_t* local_2c; float local_28; float local_24; int local_20, local_1c; uint8_t* local_18; float* local_14; uint8_t* local_10; float local_c; int local_8, local_4;
    local_18 = (uint8_t*)&DAT_008cacd0;
    local_24 = (float)FUN_0042c6f0_recon();
    FUN_004b24a0_recon(DAT_008cabe8,1);
    if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; }
    FUN_004f6090_recon("Pirate-O-Pedia");
    DAT_0085a11c = 100;
    FUN_004b06c0_recon(&DAT_00869b48,0x140,0xc,100,-1,4,-1,0);
    DAT_0085a11c = 100;
    fVar11 = (float10)FUN_004aef70_recon(IOFF((void*)(intptr_t)param_1,0xdac,int));
    iVar6 = *(int*)(*(int*)(param_1 + 0xda8) + -4);
    DAT_0085a11c = 100;
    local_28 = (float)((float10)320.0 - fVar11 * (float10)0.5);
    local_20 = iVar6; FUN_004aefd0_recon(0); local_1c = 0;
    if (0 < iVar6) {
        local_14 = (float*)(param_1 + 0x714);
        do {
            sVar9 = 1; iVar6 = local_1c; if (local_1c < 0) iVar6 = 0;
            local_2c = IOFF((void*)(intptr_t)param_1,0xda8,uint8_t*);
            _Size = *(size_t*)(local_2c + -4);
            if ((int)_Size < iVar6 + 1) sVar9 = _Size - iVar6;
            if ((int)_Size < iVar6) sVar9 = 0;
            if ((iVar6 == 0) && (sVar9 == _Size)) {
                if ((-1 < (int)_Size) && (local_2c != nullptr) && (local_2c != (uint8_t*)&DAT_008cacd0)) {
                    if (_Size == 0) FUN_00412f90_recon();
                    else { FUN_004f3350_recon(); memmove((void*)&DAT_008cacd0, local_2c, _Size); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
                }
            } else {
                puVar7 = (uint8_t*)&DAT_008cacd0; local_10 = (uint8_t*)&DAT_008cacd0;
                if ((-1 < (int)sVar9) && (-1 < iVar6 && (local_2c != nullptr) && (local_2c != (uint8_t*)&DAT_008cacd0))) {
                    if (sVar9 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                    else { FUN_004f3350_recon(); puVar7 = local_10; memmove(local_10, local_2c + iVar6, sVar9); puVar7[*(int*)(puVar7 + -4)] = 0; }
                }
                sVar9 = *(size_t*)(puVar7 + -4);
                if ((-1 < (int)sVar9) && (puVar7 != (uint8_t*)&DAT_008cacd0)) {
                    if (sVar9 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                    else { FUN_004f3350_recon(); memmove((void*)&DAT_008cacd0, puVar7, sVar9); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
                }
                piVar8 = (int*)(puVar7 + -8);
                if (piVar8 != nullptr && piVar8 != (int*)&DAT_008cacc8) operator_delete__(piVar8);
            }
            local_10 = (uint8_t*)((int)(DAT_008cac18 * 100 + (DAT_008cac18 * 100 >> 0x1f & 0x3ffU)) >> 10);
            DAT_0085a11c = 100; DAT_008c9de0 = DAT_008c9568; if (DAT_008c9568 == 0) DAT_008c9de0 = DAT_008c9dd8;
            fVar11 = (float10)FUN_00509500_recon((void*)(intptr_t)DAT_008c9de0, &DAT_008cacd0, 0);
            pfVar1 = local_14; fVar12 = local_24;
            local_c = (float)((((float10)DAT_0072637c * fVar11) / (float10)DAT_008cac18) * (float10)(int)(intptr_t)local_10 * (float10)0.01 + (float10)local_28);
            if ((local_24 == *local_14) && (_stricmp(*(char**)(param_1 + 0x80), (char*)&DAT_008cacd0) != 0) && (*(int*)(param_1 + 0x88) != DAT_008dc30c || *(int*)(param_1 + 0x8c) != DAT_008dc310) && (fVar12 != *(float*)(param_1 + 0xd2c))) {
                fVar12 = *pfVar1; FUN_00412df0_recon(extraout_ECX); FUN_004ccf00_recon(); FUN_004889c0_recon(&DAT_008c8278,0x36,-1,-1,-1,0xbf800000,-1);
            }
            if ((*(float*)(param_1 + 0xd2c) == *pfVar1) && (_strnicmp(*(char**)(param_1 + 0xd28), *(char**)(param_1 + 0x80), 1) != 0)) {
                DAT_0085a11c = 0x8c; iVar6 = FUN_005f0ddc_recon() + -4;
            } else {
                iVar6 = _stricmp(*(char**)(param_1 + 0x80), (char*)&DAT_008cacd0); DAT_0085a11c = 100;
                uVar4 = (iVar6 == 0) ? 0xffff4040 : 0xffffffff;
                iVar6 = FUN_005f0ddc_recon();
            }
            FUN_004b06c0_recon(&DAT_008cacd0, iVar6);
            local_10 = (uint8_t*)((int)(DAT_008cac18 * 100 + (DAT_008cac18 * 100 >> 0x1f & 0x3ffU)) >> 10);
            DAT_0085a11c = 100; DAT_008c9de0 = DAT_008c9568; if (DAT_008c9568 == 0) DAT_008c9de0 = DAT_008c9dd8;
            fVar11 = (float10)FUN_00509500_recon((void*)(intptr_t)DAT_008c9de0, &DAT_006fbe48[0], 0);
            local_1c = local_1c + 1; local_14 = pfVar1 + 2;
            local_28 = (float)((((float10)DAT_0072637c * fVar11) / (float10)DAT_008cac18) * (float10)(int)(intptr_t)local_10 * (float10)0.01 + (float10)local_c);
        } while (local_1c < local_20);
    }
    local_20 = *(int*)(*(int*)(param_1 + 0xdc0) + 4);
    if (*(int*)(param_1 + 0xdb8) == 0) { FUN_004f6090_recon("~ No Entries ~"); FUN_004b06c0_recon(&DAT_00869b48,0x2a,100,DAT_0085a11c,-1,4,-1,0); }
    local_28 = 0.0f;
    do {
        if (local_20 == 0) break;
        local_10 = (uint8_t*)((((int)(DAT_0072637c + -0x54 + (DAT_0072637c + -0x54 >> 0x1f & 3U)) >> 2) * (int)local_28 + 0x2a);
        local_1c = 0; iVar6 = (int)(0x118 / (long long)FUN_005f0ddc_recon());
        if (0 < iVar6) {
            do {
                if (local_20 == 0) break;
                local_c = (float)((int)(DAT_008cac18 * 0x43 + (DAT_008cac18 * 0x43 >> 0x1f & 0x3ffU)) >> 10);
                _Dst = (uint8_t*)&DAT_008cacd0; local_2c = (uint8_t*)&DAT_008cacd0; local_14 = (float*)0xffffffff; local_36 = '\0';
                DAT_0085a11c = 0x43; DAT_008c9de0 = DAT_008c9dd8;
                iVar2 = 100 - FUN_005f0ddc_recon() * local_1c;
                puVar7 = *(uint8_t**)(param_1 + 0x710 + (iVar6 * (int)local_28 + *(int*)(param_1 + 0xdb0) + local_1c) * 8);
                sVar9 = *(size_t*)(puVar7 + -4); local_8 = iVar2;
                if ((-1 < (int)sVar9) && (puVar7 != nullptr) && (puVar7 != (uint8_t*)&DAT_008cacd0)) {
                    if (sVar9 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                    else { if (0 < (int)sVar9) { if (DAT_008cacc8 < (int)sVar9) { FUN_004f32e0_recon(); _Dst = local_2c; } *(size_t*)(_Dst + -4) = sVar9; } memmove(_Dst, puVar7, sVar9); _Dst[*(int*)(_Dst + -4)] = 0; }
                }
                sVar9 = *(size_t*)(_Dst + -4);
                if ((-1 < (int)sVar9) && (_Dst != (uint8_t*)&DAT_008cacd0)) {
                    if (sVar9 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                    else { if (0 < (int)sVar9) { if (DAT_008cacc8 < (int)sVar9) FUN_004f32e0_recon(); DAT_008caccc = (int)sVar9; } memmove((void*)&DAT_008cacd0, _Dst, sVar9); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
                }
                iVar6 = FUN_005f0ddc_recon();
                local_c = *(float*)(param_1 + 0x714 + ((int)(0x118 / (long long)iVar6) * (int)local_28 + *(int*)(param_1 + 0xdb0) + local_1c) * 8);
                bVar10 = *(int*)(_Dst + -4) == 1;
                if (!bVar10) { local_36 = (char)FUN_004cc0c0_recon((int*)local_2c, (((int)(DAT_0072637c + -0x54 + (DAT_0072637c + -0x54 >> 0x1f & 3U)) >> 2) + -8), 0x43); _Dst = local_2c; }
                local_2c = (uint8_t*)((int)(DAT_008cac18 * 0x43 + (DAT_008cac18 * 0x43 >> 0x1f & 0x3ffU)) >> 10);
                DAT_0085a11c = 0x43; DAT_008c9de0 = DAT_008c9dd8;
                FUN_00509500_recon((void*)(intptr_t)DAT_008c9dd8, _Dst, 0);
                iVar6 = FUN_005f0ddc_recon(); local_4 = iVar6;
                if ((local_24 == local_c) && (1 < *(int*)(*(char**)(param_1 + 0x80) + -4) || _stricmp(*(char**)(param_1 + 0x80), (char*)&DAT_008cacd0) != 0) && (*(int*)(param_1 + 0x88) != DAT_008dc30c || *(int*)(param_1 + 0x8c) != DAT_008dc310) && (local_24 != *(float*)(param_1 + 0xd2c))) {
                    local_2c = (uint8_t*)&DAT_008cacd0; piVar8 = (int*)(param_1 + 0xd28);
                    if ((-1 < DAT_008caccc) && (puVar7 = (uint8_t*)(intptr_t)*piVar8, puVar7 != (uint8_t*)&DAT_008cacd0)) {
                        if (DAT_008caccc == 0) { if (*(int*)(puVar7-4)!=0){*puVar7=0;*(uint32_t*)(*piVar8-4)=0;} }
                        else { FUN_004f3350_recon(); memmove((void*)*piVar8, &DAT_008cacd0, DAT_008caccc); *(uint8_t*)(*piVar8 + *(int*)(*piVar8 + -4)) = 0; }
                    }
                    *(float*)(param_1 + 0xd2c) = local_24;
                    FUN_004889c0_recon(&DAT_008c8278,0x36,-1,-1,-1,0xbf800000,-1);
                    iVar2 = local_8; iVar6 = local_4;
                }
                if (*(float*)(param_1 + 0xd2c) == local_c) {
                    local_4 = (int)(DAT_008cac18 * 0x43 + (DAT_008cac18 * 0x43 >> 0x1f & 0x3ffU)) >> 10;
                    DAT_0085a11c = 0x43; DAT_008c9de0 = DAT_008c9dd8; FUN_005096b0_recon();
                    uVar4 = (uint32_t)FUN_005f0ddc_recon();
                    if (bVar10) iVar6 = iVar6 << 2;
                    local_c = 8.96831e-44f; local_14 = (float*)0xff;
                    uVar5 = (uint32_t)(intptr_t)FUN_004cddf0_recon("textHighlightBar.dds",0,0,&local_14,&local_c);
                    FUN_004af080_recon((void*)(intptr_t)uVar5,0,0,local_14,&local_c,(int)(intptr_t)local_10 + -1,iVar2 + -1,iVar6,uVar4,0xff1d5d90,0);
                    iVar6 = DAT_008caccc; local_14 = (float*)0xffffcc00;
                    if ((local_36 != '\0') && (-1 < DAT_008caccc) && (local_18 != (uint8_t*)&DAT_008cacd0)) {
                        if (DAT_008caccc == 0) { if (*(int*)(local_18-4)!=0){*local_18=0;*(uint32_t*)(local_18-4)=0;} }
                        else { if (0 < DAT_008caccc) { if (*(int*)(local_18-8) < DAT_008caccc) FUN_004f32e0_recon(); *(int*)(local_18-4) = iVar6; } puVar7 = local_18; memmove(local_18, &DAT_008cacd0, iVar6); puVar7[*(int*)(puVar7 + -4)] = 0; }
                    }
                }
                puVar7 = local_10;
                if (bVar10) {
                    DAT_0085a11c = 0x43; FUN_004b06c0_recon(_Dst,(int)(intptr_t)local_10 + 1,iVar2 + 1,0x43,0xffc0c0c0,1,-1,0);
                    DAT_0085a11c = 0x43; FUN_004b06c0_recon(_Dst,puVar7,iVar2,0x43,local_14,1,-1,0);
                } else { DAT_0085a11c = 0x43; FUN_004b06c0_recon(_Dst,local_10,iVar2,0x43,local_14,1,-1,0); }
                local_20 = *(int*)(local_20 + 4);
                piVar8 = (int*)(_Dst + -8);
                if (piVar8 != nullptr && piVar8 != (int*)&DAT_008cacc8) operator_delete__(piVar8);
                iVar2 = local_1c + 1; local_1c = iVar2; iVar6 = (int)(0x118 / (long long)FUN_005f0ddc_recon());
            } while (iVar2 < iVar6);
        }
        local_28 = (float)((int)local_28 + 1);
    } while ((int)local_28 < 4);
    puVar7 = local_18; iVar2 = DAT_008dc310; iVar6 = DAT_008dc30c;
    if (*(int*)(local_18 + -4) != 0) {
        local_4 = (int)(DAT_008cac18 * 0x43 + (DAT_008cac18 * 0x43 >> 0x1f & 0x3ffU)) >> 10;
        DAT_0085a11c = 0x43; DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500_recon((void*)(intptr_t)DAT_008c9dd8, local_18, 0);
        local_4 = FUN_005f0ddc_recon(); iVar3 = FUN_005f0ddc_recon();
        if (iVar6 - iVar3 < 0x2a) iVar6 = iVar3 + 0x2a; else if (0x256 < iVar3 + iVar6) iVar6 = 0x256 - iVar3;
        DAT_0085a11c = 0x43; FUN_004b06c0_recon(puVar7,iVar6 + 1,iVar2 + -0x13,0x43,0xff000000,4,-1,0);
        DAT_0085a11c = 0x43; FUN_004b06c0_recon(puVar7,iVar6,iVar2 + -0x14,0x43,0xffff0000,4,-1,0);
    }
    FUN_004c4640_recon();
    piVar8 = (int*)(puVar7 + -8);
    if (piVar8 != nullptr && piVar8 != (int*)&DAT_008cacc8) operator_delete__(piVar8);
}
// 0x004cc0c0 — observed shape: uint return, DAT_0085a11c=param_3, two FUN_00509500 sizing calls with DAT_008c9dd8, truncates *param_1 to sVar6=sVar2-1 clamped, loop while param_2 < iVar4+iVar3 with iVar3=-iVar3, FUN_00489300 then return 1
extern void FUN_00412f10_recon(void);
extern void FUN_00489300_recon(void);
uint32_t FUN_004cc0c0_recon(int* param_1, int param_2, int param_3) {
    uint8_t* puVar1; size_t sVar2, sVar6; int iVar3, iVar4; uint32_t* puVar5; uint8_t* local_10;
    DAT_0085a11c = param_3;
    DAT_008c9de0 = DAT_008c9dd8;
    FUN_00509500_recon((void*)(intptr_t)DAT_008c9dd8, (void*)(intptr_t)*param_1, 0);
    iVar3 = FUN_005f0ddc_recon();
    FUN_00412f10_recon();
    local_10 = (uint8_t*)((int)(DAT_008cac18 * param_3 + (DAT_008cac18 * param_3 >> 0x1f & 0x3ffU)) >> 10);
    DAT_0085a11c = param_3;
    DAT_008c9de0 = DAT_008c9dd8;
    FUN_00509500_recon((void*)(intptr_t)DAT_008c9dd8, (void*)&DAT_008cacd0, 0);
    iVar4 = FUN_005f0ddc_recon();
    if (iVar3 <= param_2) return 0;
    for (; param_2 < iVar4 + iVar3; iVar3 = -iVar3) {
        puVar1 = (uint8_t*)(intptr_t)*param_1;
        sVar2 = *(size_t*)(puVar1 + -4);
        sVar6 = sVar2 - 1;
        if ((int)sVar6 < 0) sVar6 = 0;
        if ((int)sVar2 < (int)sVar6) sVar6 = sVar2;
        if ((int)sVar2 < 0) sVar6 = 0;
        if (sVar6 == sVar2) { FUN_00412df0_recon(0); }
        else {
            if ((-1 < (int)sVar6) && (puVar1 != nullptr) && (puVar1 != (uint8_t*)&DAT_008cacd0)) {
                if (sVar6 == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
                else { FUN_004f3350_recon(); memmove((void*)&DAT_008cacd0, puVar1, sVar6); ((uint8_t*)&DAT_008cacd0)[DAT_008caccc] = 0; }
            }
            local_10 = (uint8_t*)&DAT_008cacd0;
        }
        sVar6 = *(size_t*)(local_10 + -4);
        if ((-1 < (int)sVar6) && (puVar1 = (uint8_t*)(intptr_t)*param_1, local_10 != puVar1)) {
            if (sVar6 == 0) { if (*(int*)(puVar1 + -4) != 0) { *puVar1 = 0; *(uint32_t*)(*param_1 + -4) = 0; } }
            else { FUN_004f3350_recon(); memmove((void*)*param_1, local_10, sVar6); *(uint8_t*)(*param_1 + *(int*)(*param_1 + -4)) = 0; }
        }
        puVar5 = (uint32_t*)(local_10 + -8);
        if (puVar5 != nullptr && puVar5 != (uint32_t*)&DAT_008cacc8) operator_delete__(puVar5);
        DAT_0085a11c = param_3;
        local_10 = (uint8_t*)&DAT_008cacd0;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500_recon((void*)(intptr_t)DAT_008c9dd8, (void*)(intptr_t)*param_1, 0);
        iVar3 = FUN_005f0ddc_recon();
    }
    FUN_00489300_recon();
    return 1;
}

// 0x004cc3c0 — observed shape: in_EAX self, loop on +0xd2c (-1 exits via FUN_004cc8f0), scans +0x714 stride-2 array for match with iVar5 from 5, +0x6e4 count guard, <5 breaks; index = 0x6ec+iVar2*8 or ((0x118/div)*iVar5+iVar4+5+iVar2)*8, FUN_00412df0/FUN_004ccf00 then _stricmp(+0xd28,+0x80)
extern void FUN_004ccf00_recon(void);
void FUN_004cc3c0_recon(void* self) {
    int deref = (int)(intptr_t)self;
    int* piVar1; int iVar2, iVar3, iVar4, iVar5;
    iVar4 = IOFF(self,0xd2c,int);
    while (true) {
        if (iVar4 == -1) { FUN_004cc8f0_recon(); return; }
        iVar5 = 5;
        if (IOFF(self,0x6e4,int) < 6) return;
        piVar1 = (int*)((char*)self + 0x714);
        while (*piVar1 != iVar4) {
            iVar5 = iVar5 + 1; piVar1 = piVar1 + 2;
            if (IOFF(self,0x6e4,int) <= iVar5) return;
        }
        if (iVar5 < 5) break;
        iVar4 = IOFF(self,0xdb0,int);
        if (iVar5 < iVar4 + 5) {
            iVar2 = 5;
            if (iVar5 != iVar4 + 4) iVar2 = iVar5 + 1;
            iVar3 = IOFF((void*)(intptr_t)(deref + 0x6ec + iVar2 * 8),0,int);
            iVar4 = iVar3;
        } else {
            iVar5 = FUN_004cc9d0_recon();
            iVar2 = FUN_004cc990_recon();
            if (iVar5 == 3) iVar5 = 0; else iVar5 = iVar5 + 1;
            iVar3 = FUN_005f0ddc_recon();
            iVar4 = IOFF((void*)(intptr_t)(deref + 0x6ec + ((int)(0x118 / (long long)iVar3) * iVar5 + iVar4 + 5 + iVar2) * 8),0,int);
        }
        FUN_00412df0_recon(iVar3);
        FUN_004ccf00_recon();
        iVar4 = _stricmp(*(char**)((char*)self + 0xd28), *(char**)((char*)self + 0x80));
        if (iVar4 != 0) return;
        iVar4 = IOFF(self,0xd2c,int);
    }
    (void)deref;
}

// 0x004cc4d0 — observed shape: same +0xd2c/+0x714 scan as 0x4cc3c0; <5 breaks; index = 0x6ec+iVar4*8 with iVar4 = base+4 or iVar5-1, else ((0x118/div)*iVar5+iVar4+5+iVar2)*8 where iVar5 wraps 0->3/-1; FUN_00412df0/FUN_004ccf00, _stricmp guard
void FUN_004cc4d0_recon(void* self) {
    int deref = (int)(intptr_t)self;
    int* piVar1; int iVar2, iVar3, iVar4, iVar5;
    iVar4 = IOFF(self,0xd2c,int);
    while (true) {
        if (iVar4 == -1) { FUN_004cc8f0_recon(); return; }
        iVar5 = 5;
        if (IOFF(self,0x6e4,int) < 6) return;
        piVar1 = (int*)((char*)self + 0x714);
        while (*piVar1 != iVar4) {
            iVar5 = iVar5 + 1; piVar1 = piVar1 + 2;
            if (IOFF(self,0x6e4,int) <= iVar5) return;
        }
        if (iVar5 < 5) break;
        iVar4 = IOFF(self,0xdb0,int);
        if (iVar5 < iVar4 + 5) {
            iVar4 = iVar4 + 4;
            if (iVar5 != 5) iVar4 = iVar5 + -1;
            iVar3 = IOFF((void*)(intptr_t)(deref + 0x6ec + iVar4 * 8),0,int);
            iVar4 = iVar3;
        } else {
            iVar5 = FUN_004cc9d0_recon();
            iVar2 = FUN_004cc990_recon();
            if (iVar5 == 0) iVar5 = 3; else iVar5 = iVar5 + -1;
            iVar3 = FUN_005f0ddc_recon();
            iVar4 = IOFF((void*)(intptr_t)(deref + 0x6ec + ((int)(0x118 / (long long)iVar3) * iVar5 + iVar4 + 5 + iVar2) * 8),0,int);
        }
        FUN_00412df0_recon(iVar3);
        FUN_004ccf00_recon();
        iVar4 = _stricmp(*(char**)((char*)self + 0xd28), *(char**)((char*)self + 0x80));
        if (iVar4 != 0) return;
        iVar4 = IOFF(self,0xd2c,int);
    }
    (void)deref;
}

// 0x004cc5e0 — observed shape: do-while on +0xd2c; near branch uses FUN_004cca20 with index (iVar5+1)*(0x118/div)+4+iVar4; far branch FUN_004cc9d0/FUN_004cc990, goto shared LAB when iVar3!=0 else FUN_004cca70 then _stricmp dispatch to FUN_004cc4d0/FUN_004cc3c0
extern int FUN_004cca70_recon(void*,int);
void FUN_004cc5e0_recon(void* self) {
    int deref = (int)(intptr_t)self;
    int* piVar1; int iVar2, iVar3, iVar4, iVar5; uint32_t uVar6, uVar7; int extraout_ECX = 0;
    iVar4 = IOFF(self,0xd2c,int);
    do {
        if (iVar4 == -1) { FUN_004cc8f0_recon(); return; }
        iVar5 = 5;
        if (IOFF(self,0x6e4,int) < 6) return;
        piVar1 = (int*)((char*)self + 0x714);
        while (*piVar1 != iVar4) {
            iVar5 = iVar5 + 1; piVar1 = piVar1 + 2;
            if (IOFF(self,0x6e4,int) <= iVar5) return;
        }
        if (iVar5 < 5) return;
        iVar4 = IOFF(self,0xdb0,int);
        if (iVar5 < iVar4 + 5) {
            iVar5 = FUN_004cca20_recon();
            iVar2 = FUN_005f0ddc_recon();
            iVar4 = (iVar5 + 1) * (int)(0x118 / (long long)iVar2) + 4 + iVar4;
LAB_004cc709:
            uVar7 = IOFF((void*)(intptr_t)(deref + 0x6ec + iVar4 * 8),0,uint32_t);
            FUN_00412df0_recon(iVar2);
            FUN_004ccf00_recon();
        } else {
            iVar5 = FUN_004cc9d0_recon();
            iVar3 = FUN_004cc990_recon();
            if (iVar3 != 0) {
                iVar2 = FUN_005f0ddc_recon();
                iVar4 = (int)(0x118 / (long long)iVar2) * iVar5 + iVar4 + 4 + iVar3;
                goto LAB_004cc709;
            }
            iVar4 = FUN_004cca70_recon(self, iVar5);
            uVar7 = IOFF((void*)(intptr_t)(deref + 0x6ec + iVar4 * 8),0,uint32_t);
            uVar6 = (uint32_t)extraout_ECX;
            FUN_00412df0_recon(extraout_ECX);
            FUN_004ccf00_recon();
            (void)uVar6;
            iVar5 = _stricmp(*(char**)((char*)self + 0xd28), *(char**)((char*)self + 0x80));
            if (iVar5 == 0) {
                if (iVar4 == IOFF(self,0xdb0,int) + 4) FUN_004cc4d0_recon(self);
                else FUN_004cc3c0_recon(self);
            }
        }
        iVar4 = _stricmp(*(char**)((char*)self + 0xd28), *(char**)((char*)self + 0x80));
        if (iVar4 != 0) return;
        iVar4 = IOFF(self,0xd2c,int);
    } while (true);
    (void)deref;
}
// 0x004cc760 — observed shape: near branch index = iVar2*(0x118/div)+5+iVar4; far branch compares iVar2 vs iVar3-1, goto LAB_004cc89b or FUN_004cca70 path with _stricmp dispatch to FUN_004cc4d0/FUN_004cc3c0; tail _stricmp(+0xd28,+0x80) loop
void FUN_004cc760_recon(void* self) {
    int deref = (int)(intptr_t)self;
    int* piVar1; int iVar2, iVar3, iVar4, iVar5; uint32_t uVar6, uVar7; int extraout_ECX = 0;
    iVar4 = IOFF(self,0xd2c,int);
    do {
        if (iVar4 == -1) { FUN_004cc8f0_recon(); return; }
        iVar5 = 5;
        if (IOFF(self,0x6e4,int) < 6) return;
        piVar1 = (int*)((char*)self + 0x714);
        while (*piVar1 != iVar4) {
            iVar5 = iVar5 + 1; piVar1 = piVar1 + 2;
            if (IOFF(self,0x6e4,int) <= iVar5) return;
        }
        if (iVar5 < 5) return;
        iVar4 = IOFF(self,0xdb0,int);
        if (iVar5 < iVar4 + 5) {
            iVar2 = FUN_004cca20_recon();
            iVar5 = FUN_005f0ddc_recon();
            iVar4 = IOFF((void*)(intptr_t)(deref + 0x6ec + (iVar2 * (int)(0x118 / (long long)iVar5) + 5 + iVar4) * 8),0,int);
LAB_004cc89b:
            FUN_00412df0_recon(iVar5);
            FUN_004ccf00_recon();
        } else {
            iVar5 = FUN_004cc9d0_recon();
            iVar2 = FUN_004cc990_recon();
            iVar3 = FUN_005f0ddc_recon();
            iVar3 = (int)(0x118 / (long long)iVar3);
            if (iVar2 != iVar3 + -1) {
                iVar5 = IOFF((void*)(intptr_t)(deref + 0x6ec + (iVar3 * iVar5 + iVar4 + 6 + iVar2) * 8),0,int);
                iVar4 = iVar5;
                goto LAB_004cc89b;
            }
            iVar4 = FUN_004cca70_recon(self, iVar5);
            uVar7 = IOFF((void*)(intptr_t)(deref + 0x6ec + iVar4 * 8),0,uint32_t);
            uVar6 = (uint32_t)extraout_ECX;
            FUN_00412df0_recon(extraout_ECX);
            FUN_004ccf00_recon();
            (void)uVar6; (void)uVar7;
            iVar5 = _stricmp(*(char**)((char*)self + 0xd28), *(char**)((char*)self + 0x80));
            if (iVar5 == 0) {
                if (iVar4 == IOFF(self,0xdb0,int) + 4) FUN_004cc4d0_recon(self);
                else FUN_004cc3c0_recon(self);
            }
        }
        iVar4 = _stricmp(*(char**)((char*)self + 0xd28), *(char**)((char*)self + 0x80));
        if (iVar4 != 0) return;
        iVar4 = IOFF(self,0xd2c,int);
    } while (true);
    (void)deref;
}

// 0x004cc8f0 — observed shape: FUN_004cd0a0(**(+0xda8)); _stricmp(+0x80,&DAT_008cacd0): equal -> (extraout_ECX,+0x71c) else (+0x714,+0x714); FUN_00412df0/FUN_004ccf00; FUN_004889c0(&DAT_008c8278,0x36,-1,-1,-1,0xbf800000,-1)
extern void FUN_004cd0a0_recon(void);
extern void FUN_004889c0_recon(void*,int,int,int,int,int,int);
void FUN_004cc8f0_recon(void* self) {
    int iVar1; int extraout_ECX = 0; uint32_t uVar2, uVar3;
    FUN_004cd0a0_recon();
    iVar1 = _stricmp(*(char**)((char*)self + 0x80), (char*)&DAT_008cacd0);
    if (iVar1 == 0) { uVar2 = (uint32_t)extraout_ECX; uVar3 = IOFF(self,0x71c,uint32_t); }
    else { uVar2 = IOFF(self,0x714,uint32_t); uVar3 = uVar2; }
    FUN_00412df0_recon((int)uVar2);
    FUN_004ccf00_recon();
    (void)uVar3;
    FUN_004889c0_recon(&DAT_008c8278, 0x36, -1, -1, -1, 0xbf800000, -1);
}

// 0x004cc990 — observed shape: returns (unaff_EDI - FUN_004cc9d0()*(0x118/FUN_005f0ddc())) - *(unaff_ESI+0xdb0) + -5
int FUN_004cc990_recon(void* self, int edi_val) {
    int iVar1 = FUN_004cc9d0_recon();
    int iVar2 = FUN_005f0ddc_recon();
    return ((edi_val - iVar1 * (int)(0x118 / (long long)iVar2)) - IOFF(self,0xdb0,int)) + -5;
}

// 0x004cc9d0 — observed shape: iVar1=(in_EAX - *(in_ECX+0xdb0))+ -5; loop while iVar1<iVar5||iVar2<=iVar1 advancing iVar5/iVar2 by (0x118/div), return 0 if iVar4>3 else iVar4
int FUN_004cc9d0_recon(int eax_val, void* self) {
    int iVar1 = (eax_val - IOFF(self,0xdb0,int)) + -5;
    int iVar4 = 0, iVar5 = 0;
    int iVar3 = (int)(0x118 / (long long)FUN_005f0ddc_recon());
    int iVar2 = iVar3;
    while ((iVar1 < iVar5 || (iVar2 <= iVar1))) {
        iVar4 = iVar4 + 1; iVar5 = iVar5 + iVar3; iVar2 = iVar2 + iVar3;
        if (3 < iVar4) return 0;
    }
    return iVar4;
}

// 0x004cca20 — observed shape: if (in_ECX<5 || *(in_EAX+0xdb0)+5<=in_ECX) return 0 else return FUN_005f0ddc()
uint32_t FUN_004cca20_recon(void* self, int ecx_val) {
    if (ecx_val < 5 || IOFF(self,0xdb0,int) + 5 <= ecx_val) return 0;
    return (uint32_t)FUN_005f0ddc_recon();
}

// 0x004ccab0 — observed shape: if (+0xd2c!=-1): scan +0x714 stride-2 for match with iVar1 from 5 until ==+0xd2c else iVar1=-1; FUN_00412df0/FUN_004ccf00(*( +0x6ec+iVar1*8 ))
void FUN_004ccab0_recon(void* self) {
    int iVar1; int* piVar2; uint32_t uVar3, uVar4;
    if (IOFF(self,0xd2c,int) != -1) {
        iVar1 = 5;
        if (5 < IOFF(self,0x6e4,int)) {
            piVar2 = (int*)((char*)self + 0x714);
            do {
                if (*piVar2 == IOFF(self,0xd2c,int)) goto LAB_004ccae0;
                iVar1 = iVar1 + 1; piVar2 = piVar2 + 2;
            } while (iVar1 < IOFF(self,0x6e4,int));
        }
        iVar1 = -1;
LAB_004ccae0:
        uVar3 = IOFF((void*)(intptr_t)((int)(intptr_t)self + 0x6ec + iVar1 * 8),0,uint32_t);
        uVar4 = uVar3;
        FUN_00412df0_recon((int)uVar3);
        FUN_004ccf00_recon();
        (void)uVar4;
    }
}

// 0x004ccb10 — observed shape: *unaff_EBX=*in_EAX; [1]=in_EAX[1]; _Src=in_EAX[2]; if (_Size>=0 && _Src!=0 && _Src!=*piVar1): if (_Size!=0){FUN_004f3350(); memmove; NUL-terminate} else FUN_00412f90()
extern void FUN_004f3350_recon(void);
void FUN_004ccb10_recon(void* dst, void* src) {
    uint32_t* unaff_EBX = (uint32_t*)dst;
    uint32_t* in_EAX = (uint32_t*)src;
    int* piVar1; void* _Src; size_t _Size;
    *unaff_EBX = *in_EAX;
    unaff_EBX[1] = in_EAX[1];
    _Src = (void*)(intptr_t)in_EAX[2];
    _Size = *(size_t*)((int)(intptr_t)_Src + -4);
    piVar1 = (int*)((char*)unaff_EBX + 8);
    if ((-1 < (int)_Size) && (_Src != nullptr) && (_Src != (void*)(intptr_t)*piVar1)) {
        if (_Size != 0) {
            FUN_004f3350_recon();
            memmove((void*)(intptr_t)*piVar1, _Src, _Size);
            *(uint8_t*)(*piVar1 + *(int*)(*piVar1 + -4)) = 0;
            return;
        }
        FUN_00412f90_recon();
    }
}

// 0x004ccb70 — observed shape: *in_ECX=&PTR_FUN_0070d8e0; FUN_004e6420(); operator_delete__(in_ECX[2]); if (param_1&1) operator_delete(in_ECX)
extern void FUN_004e6420_recon(void);
void FUN_004ccb70_recon(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_0070d8e0;
    FUN_004e6420_recon();
    operator_delete__((void*)(intptr_t)in_ECX[2]);
    if ((param_1 & 1) != 0) operator_delete(in_ECX);
}
