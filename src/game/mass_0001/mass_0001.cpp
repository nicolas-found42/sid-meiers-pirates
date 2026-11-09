// Mass reconstruction batch mass_0001 — unverified decompiler-derived candidate.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// No compiler/test run. Correlated externally via observed pseudocode shapes.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cwchar>
#include <cstdlib>
#include <windows.h>

typedef unsigned char byte;
typedef uint16_t ushort;

// ---- extern globals (scalar words; address-of gives adjacent array base) ----
extern int32_t DAT_0085a158;
extern uint32_t DAT_00869ab4;
extern uint32_t DAT_00869b1a;
extern uint32_t _DAT_00869a76;
extern int32_t DAT_00869ab0;
extern int32_t DAT_00869acc;
extern int32_t DAT_00869ab8;
extern int32_t DAT_00869ac8;
extern int32_t DAT_00869ac4;
extern int32_t DAT_00869ac0;
extern int32_t DAT_00869abc;
extern uint32_t DAT_0081431a;
extern uint32_t DAT_00814318;
extern uint32_t DAT_008142f8;
extern uint32_t DAT_00814350;
extern uint32_t _DAT_00814324;
extern uint32_t DAT_0081431e;
extern uint32_t DAT_00814320;
extern uint32_t DAT_00814322;
extern int32_t DAT_00869ad0;
extern int32_t DAT_00869b30;
extern uint32_t _DAT_00869b20;
extern uint32_t _DAT_00869b24;
extern uint32_t _DAT_00869b28;
extern uint32_t _DAT_00869b2c;
extern int32_t DAT_00814754;
extern int32_t DAT_00869a78;
extern int32_t DAT_00869a7a;
extern int32_t DAT_00869a7c;
extern int32_t DAT_00869a7e;
extern int32_t DAT_00869a80;
extern uint32_t _DAT_0085a164;
extern int32_t DAT_0072c770;
extern int32_t DAT_0072c774;
extern int32_t DAT_0085a154;
extern int32_t DAT_0085a150;
extern int32_t DAT_0085a100;
extern int32_t DAT_008ca92c;
extern int32_t DAT_008caccc;
extern int32_t DAT_00869b27;
extern uint32_t DAT_00869b34;
extern int32_t DAT_00869b29;
extern int32_t DAT_0085a140;
extern int32_t DAT_007253b4;
extern int32_t DAT_00869b18;
extern uint32_t _DAT_00862008;
extern int32_t DAT_00862004;
extern int32_t DAT_00862006;
extern int32_t DAT_00814304;
extern int32_t DAT_00814308;
extern int32_t DAT_0081430c;
extern int32_t DAT_00814760;
extern int32_t DAT_00814764;
extern int32_t DAT_00814768;
extern int32_t DAT_0081617c;
extern int32_t DAT_007267c8;
extern int32_t DAT_007267cc;
extern uint32_t _DAT_008c97de;
extern uint32_t DAT_008ca938;
extern uint32_t _DAT_008ca938;
extern uint32_t _DAT_008ca93c;
extern uint32_t _DAT_008ca940;
extern uint32_t _DAT_008ca944;
extern uint32_t _DAT_008ca948;
extern uint32_t _DAT_008ca94c;
extern uint32_t _DAT_008ca950;
extern uint32_t _DAT_00862000;
extern uint32_t _DAT_00862004;
extern uint32_t _DAT_00862008;
extern uint32_t _DAT_0086200a;
extern uint32_t _DAT_0086200c;
extern uint32_t _DAT_00862010;
extern int32_t DAT_00861ff8;
extern int32_t DAT_00861ffc;
extern uint32_t DAT_00869a89;
extern uint32_t DAT_00869a8b;
extern uint32_t DAT_00869a8d;
extern uint32_t DAT_00869a8f;
extern uint32_t DAT_00869a91;
extern uint32_t DAT_00869a93;
extern uint32_t DAT_00869a95;
extern uint32_t DAT_00869a97;

// ---- extern arrays / buffers (address base; *reinterpret_cast reads scalar) ----
extern unsigned char DAT_0085a970[];
extern unsigned char DAT_0085a8b0[];
extern unsigned char DAT_00861b78[];
extern unsigned char DAT_00723b18[];
extern unsigned char DAT_00860b70[];
extern unsigned char DAT_0085bf7c[];
extern char DAT_008cacd0[];
extern unsigned char DAT_008cacc8[];
extern unsigned char DAT_00869a70[];
extern unsigned char DAT_00860b68[];
extern unsigned char DAT_0085bf70[];
extern unsigned char DAT_00862d10[];
extern unsigned char DAT_00859ef8[];
extern unsigned char DAT_0085a168[];
extern unsigned char DAT_007d2168[];
extern unsigned char DAT_0076ef10[];
extern unsigned char DAT_0085a270[];
extern unsigned char DAT_0074de48[];
extern unsigned char DAT_00862110[];
extern unsigned char DAT_00722a08[];
extern unsigned char DAT_00722a0c[];
extern unsigned char DAT_0085a160[];
extern unsigned char DAT_0085b170[];
extern unsigned char DAT_007b10a0[];
extern unsigned char DAT_0085a790[];
extern unsigned char DAT_008c84b8[];
extern unsigned char DAT_0072c6b8[];
extern unsigned char DAT_0072c6e0[];
extern unsigned char DAT_00869aa8[];
extern unsigned char DAT_008db620[];
extern unsigned char DAT_00869b48[];
extern unsigned char DAT_006fb6d8[];
extern unsigned char DAT_00723b1c[];
extern unsigned char DAT_00723b14[];
extern unsigned char DAT_006fb738[];
extern unsigned char DAT_00710530[];
extern unsigned char DAT_008d8918[];
extern unsigned char DAT_008db678[];
extern unsigned char DAT_008cae00[];
extern unsigned char DAT_008cae0c[];
extern unsigned char DAT_008cae18[];
extern unsigned char DAT_008cae24[];
extern unsigned char DAT_008cb100[];
extern unsigned char DAT_008cb178[];
extern unsigned char DAT_008cb19c[];
extern unsigned char DAT_0085bf84[];
extern unsigned char DAT_0085bff6[];
extern unsigned char DAT_0085b178[];
extern unsigned char DAT_00860b75[];
extern unsigned char DAT_007252f0[];
extern unsigned char DAT_00725350[];
extern unsigned char DAT_00862020[];
extern unsigned char DAT_00814326[];
extern unsigned char DAT_00814330[];
extern unsigned char DAT_00814328[];
extern unsigned char DAT_008c97d8[];
extern unsigned char DAT_008c99d8[];
extern void* DAT_008c99e4;
extern unsigned char DAT_007253b0[];
extern unsigned char DAT_007253b4[];
extern unsigned char DAT_0085a17c[];
extern unsigned char DAT_0085a208[];
extern void* PTR_FUN_006f5814[];
extern char* PTR_DAT_007267d0;
extern unsigned char PTR_LAB_006f580c[];
extern unsigned char DAT_008cace0[];
extern unsigned char DAT_008cacec[];
extern unsigned char DAT_008c84b0[];

// ---- extern helpers ----
extern int FUN_0044d2e0(int a, int b);
extern int FUN_004f11a0(void* p, int n);
extern int FUN_004f10f0(void* p, int n);
extern void FUN_004f32e0(void);
extern void FUN_004f3350(void);
extern void operator_delete__(void* p);
extern void* FUN_004f14a0(void* p);
extern void FUN_00412f90(void);
extern void FUN_00412e50(uint32_t a);
extern byte FUN_004f1310(void);
extern int FUN_004f0e40(void* p, int a, int b, int flags);
extern void FUN_004f0dc0(void);
extern void FUN_004f4b20(const void* name, int a, int b, int flags);
extern void FUN_004f4de0(void);
extern uint32_t FUN_004ce080(void* p);
extern void FUN_004129c0(void* a, uint32_t b, void* c, void* d);
extern void* FUN_00412a60(void* a, void* b);
extern void FUN_004f8110(void* p);
extern uint32_t FUN_004f1220(int a, int b);
extern void FUN_004f8250(void* p);
extern void FUN_004f85e0(void* a, void* b);
extern void FUN_004f3ee0(void);
extern void FUN_004f2600(void* a, void* b);
extern void FUN_004f84d0(void* p);
extern void FUN_004f1c20(void);
extern void FUN_004f1b10(void* p);
extern void FUN_004ce190(void* a, void* b);
extern void FUN_00412b40(void);
extern byte FUN_004f83a0(void);
extern void FUN_00412f10(void);
extern void FUN_004f6090(const char* s);
extern void FUN_00413080(void);
extern void FUN_004aaf70(uint64_t v);
extern int FUN_004131d0(int a);
extern void FUN_00428a30(int a);
extern void FUN_00415290(int a);
extern int FUN_004888e0(int a, int b, int c, uint32_t d);
extern void FUN_004e1470(void);
extern void FUN_00400f00(void); // rand-exref slot target
extern int rand(void);
extern code* rand_exref;

// 0x00401000 — observed shape
void FUN_00401000(int param_1, char in_AL) {
    // Ghidra pseudocode elided mid ranges; preserved init/reset shape:
    // when in_AL!=0: iterate DAT_0085a970..0x85b170 (+8), clear 0x200 dwords at 0085a970,
    // 0x30 at 0085a8b0, optional 0x120 zero at 00861b78 when param_1==0.
    // Then seal global defaults (1000-masked by DAT_0085a158), param-selected block,
    // half negative 00869a78..00869a80, stride-clear 0086..., clear flag bit 0x200.
    if (in_AL != '\0') {
        int iVar6 = 0;
        int* piVar4 = (int*)DAT_0085a970;
        do {
            if (0 < *piVar4) FUN_0044d2e0(iVar6, 99);
            piVar4 = piVar4 + 8;
            iVar6 = iVar6 + 1;
        } while ((intptr_t)piVar4 < 0x85b170);
        uint32_t* puVar7 = (uint32_t*)DAT_0085a970;
        for (int i = 0x200; i != 0; i = i - 1) { *puVar7 = 0xffffffffu; puVar7 = puVar7 + 1; }
        puVar7 = (uint32_t*)DAT_0085a8b0;
        for (int i = 0x30; i != 0; i = i - 1) { *puVar7 = 0xffffffffu; puVar7 = puVar7 + 1; }
        if (param_1 == 0) {
            puVar7 = (uint32_t*)DAT_00861b78;
            for (int i = 0x120; i != 0; i = i - 1) { *puVar7 = 0; puVar7 = puVar7 + 1; }
        }
    }
    DAT_00869ab4 = (uint32_t)((-(uint32_t)(DAT_0085a158 != 0) & 0xfffffc7cu) + 1000u);
    DAT_00869b1a = 0;
    _DAT_00869a76 = 0;
    DAT_00869ab0 = 0x28;
    DAT_00869acc = 8;
    DAT_00869ab8 = 0x14;
    DAT_00869ac8 = 0;
    DAT_00869ac4 = 0;
    DAT_00869ac0 = 0;
    DAT_00869abc = 0;
    DAT_0081431a = 0;
    DAT_00814318 = 0;
    if (param_1 == 0) {
        _DAT_00869b20 = 0; _DAT_00869b24 = 0; _DAT_00869b28 = 0; _DAT_00869b2c = 0;
        DAT_00869b30 = 0;
        DAT_008142f8 = 1;
        *(uint32_t*)(DAT_00814350 + 0) = 0x408; // DAT_00814350 = 0x408 observed
        _DAT_00814324 = 0x30;
        DAT_0081431e = 0x28;
        DAT_00814320 = 8;
        DAT_00814322 = 4;
        DAT_00869ad0 = 1;
    } else {
        DAT_00869acc = (int32_t)*(uint32_t*)(DAT_00723b18 + (uint32_t)DAT_008142f8 * 0x44);
        if (param_1 == 1) goto LAB_00401111;
    }
    DAT_0081431a = 0;
    DAT_00814318 = 0;
    {
        ushort* puVar2 = (ushort*)((unsigned char*)&DAT_00814754);
        do {
            *puVar2 = 0xffff;
            puVar2 = puVar2 + 0x22e;
        } while ((intptr_t)puVar2 < 0x8165d8);
    }
LAB_00401111:
    if (param_1 == -1) DAT_00869ad0 = 1;
    if (DAT_00869a78 < 0) DAT_00869a78 = DAT_00869a78 / 2;
    if (DAT_00869a7a < 0) DAT_00869a7a = DAT_00869a7a / 2;
    if (DAT_00869a7c < 0) DAT_00869a7c = DAT_00869a7c / 2;
    if (DAT_00869a7e < 0) DAT_00869a7e = DAT_00869a7e / 2;
    if (DAT_00869a80 < 0) DAT_00869a80 = DAT_00869a80 / 2;
    {
        uint32_t* puVar5 = (uint32_t*)DAT_00860b70;
        short* psVar3 = (short*)DAT_0085bf7c;
        do {
            uint32_t uVar1 = *puVar5;
            psVar3[1] = 0;
            *psVar3 = (short)(*psVar3 / 2);
            *puVar5 = uVar1 & 0xfff7ffffu;
            psVar3 = psVar3 + 0x4a;
            puVar5 = puVar5 + 8;
        } while ((intptr_t)psVar3 < 0x85d8ec);
    }
    _DAT_0085a164 = _DAT_0085a164 & 0xfffffdffu;
}

// 0x00401260 — observed shape
byte FUN_00401260(void* self, int in_EAX) {
    // self = in_ECX receiver (+8 stride records), in_EAX = count.
    // DAT_0072c770 selects FUN_004f11a0 (==0) vs FUN_004f10f0 (!=0) reader.
    // Wide-string scratch at DAT_008cacd0, guarded operator_delete__ on exit.
    char* pcVar7 = DAT_008cacd0;
    char* local_c = DAT_008cacd0;
    byte bVar6 = 1;
    int local_8 = in_EAX;
    int local_4 = 0;
    if (DAT_0072c770 == 0) {
        if (0 < in_EAX) {
            int* piVar8 = (int*)((char*)self + 8);
            do {
                int local_18 = *(int*)(*piVar8 + -4);
                int iVar3 = FUN_004f11a0(&local_18, 4);
                bVar6 = (byte)(bVar6 & (iVar3 == 4));
                if (local_18 != 0) {
                    iVar3 = FUN_004f11a0((void*)*piVar8, local_18);
                    bVar6 = (byte)(bVar6 & (iVar3 == local_18));
                }
                int local_14 = piVar8[-2];
                iVar3 = FUN_004f11a0(&local_14, 4);
                int local_10 = piVar8[-1];
                int iVar5 = FUN_004f11a0(&local_10, 4);
                bVar6 = (byte)(bVar6 & (iVar3 == 4) & (iVar5 == 4));
                piVar8 = piVar8 + 3;
                in_EAX = in_EAX - 1;
            } while (in_EAX != 0);
        }
    } else if (0 < in_EAX) {
        int* piVar8 = (int*)((char*)self + 8);
        local_8 = in_EAX;
        do {
            int local_18 = 0;
            int iVar3 = FUN_004f10f0(&local_18, 4);
            bVar6 = (byte)(bVar6 & (iVar3 == 4));
            if (local_18 == 0) {
                if (*(int*)(pcVar7 + -4) != 0) {
                    *pcVar7 = '\0';
                    pcVar7[-4] = '\0'; pcVar7[-3] = '\0'; pcVar7[-2] = '\0'; pcVar7[-1] = '\0';
                }
            } else {
                local_4 = local_18;
                if (*(int*)(pcVar7 + -8) < local_18) {
                    uint32_t uVar2 = *(uint32_t*)(pcVar7 + -4);
                    if (0 < local_18) {
                        FUN_004f32e0();
                        *(int*)(local_c + -4) = local_4;
                        pcVar7 = local_c;
                    }
                    *(uint32_t*)(pcVar7 + -4) = uVar2;
                }
                iVar3 = FUN_004f10f0(pcVar7, local_18);
                bVar6 = (byte)(bVar6 & (iVar3 == local_18));
                if (local_18 == -1) {
                    char* pcVar4 = pcVar7;
                    char cVar1;
                    do { cVar1 = *pcVar4; pcVar4 = pcVar4 + 1; } while (cVar1 != '\0');
                    *(int*)(pcVar7 + -4) = (int)((intptr_t)pcVar4 - (intptr_t)(pcVar7 + 1));
                } else {
                    *(int*)(pcVar7 + -4) = local_18;
                    if (0 < local_18) pcVar7[local_18] = '\0';
                }
            }
            {
                char* pcVar4 = pcVar7;
                char cVar1;
                do { cVar1 = *pcVar4; pcVar4 = pcVar4 + 1; } while (cVar1 != '\0');
                size_t _Size = (size_t)((intptr_t)pcVar4 - (intptr_t)(pcVar7 + 1));
                if (((int)_Size > -1) && ((char*)*piVar8 != pcVar7)) {
                    if (_Size == 0) {
                        if (*(int*)(*piVar8 + -4) != 0) {
                            *(char*)*piVar8 = '\0';
                            *(uint32_t*)(*(intptr_t*)piVar8 + -4) = 0;
                        }
                    } else {
                        FUN_004f3350();
                        memmove((void*)*piVar8, pcVar7, _Size);
                        *(uint8_t*)(*(intptr_t*)piVar8 + *(int*)(*(intptr_t*)piVar8 + -4)) = 0;
                    }
                }
            }
            int local_14 = 0;
            iVar3 = FUN_004f10f0(&local_14, 4);
            piVar8[-2] = local_14;
            int local_10 = 0;
            int iVar5 = FUN_004f10f0(&local_10, 4);
            piVar8[-1] = local_10;
            bVar6 = (byte)(bVar6 & (iVar3 == 4) & (iVar5 == 4));
            piVar8 = piVar8 + 3;
            local_8 = local_8 - 1;
        } while (local_8 != 0);
        local_8 = 0;
    }
    pcVar7 = pcVar7 + -8;
    if ((pcVar7 != (char*)0x0) && (pcVar7 != (char*)DAT_008cacc8)) {
        operator_delete__(pcVar7);
    }
    return bVar6;
}

// 0x004014a0 — observed shape
byte FUN_004014a0(int in_EAX) {
    // Reads contiguous save header blocks via 11a0/10f0 selected by DAT_0072c770,
    // then calls 401260 twice; in_EAX==2 selects 0072c6b8/0xb8 vs 00869a70/0xd8 and
    // 0x1c00 vs 28000 sizes; final AND of all success codes returned.
    uint64_t local_c = *(uint64_t*)DAT_008c84b0;
    if (in_EAX < 1) DAT_0072c770 = (int)(((in_EAX > -1) ? 1 : 0) - 1);
    else DAT_0072c770 = 1;
    int iVar3 = DAT_0072c770 == 0 ? FUN_004f11a0(&DAT_0085a158, 4) : FUN_004f10f0(&DAT_0085a158, 4);
    int iVar4 = DAT_0072c770 == 0 ? FUN_004f11a0(&DAT_0072c774, 4) : FUN_004f10f0(&DAT_0072c774, 4);
    byte bVar1 = FUN_00401260((void*)0, 0);
    int iVar5 = DAT_0072c770 == 0 ? FUN_004f11a0(&DAT_0085a154, 4) : FUN_004f10f0(&DAT_0085a154, 4);
    int iVar6 = DAT_0072c770 == 0 ? FUN_004f11a0(&DAT_0085a150, 4) : FUN_004f10f0(&DAT_0085a150, 4);
    int iVar7 = DAT_0072c770 == 0 ? FUN_004f11a0(&_DAT_0085a164, 4) : FUN_004f10f0(&_DAT_0085a164, 4);
    bool bVar38;
    int iVar8;
    if (in_EAX == 2) {
        iVar8 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0072c6b8, 0xb8) : FUN_004f10f0(DAT_0072c6b8, 0xb8);
        bVar38 = (iVar8 == 0xb8);
    } else {
        iVar8 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00869a70, 0xd8) : FUN_004f10f0(DAT_00869a70, 0xd8);
        bVar38 = (iVar8 == 0xd8);
    }
    iVar8 = DAT_0072c770 == 0 ? FUN_004f11a0(&DAT_008142f8, 0x45c00) : FUN_004f10f0(&DAT_008142f8, 0x45c00);
    // (remaining blocks elided in this note but executed in order below)
    int iVar9 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00860b68, 0x1000) : FUN_004f10f0(DAT_00860b68, 0x1000);
    int iVar10 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0085bf70, 0x4a00) : FUN_004f10f0(DAT_0085bf70, 0x4a00);
    bool bVar39;
    int iVar11;
    if (in_EAX == 2) {
        iVar11 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00862d10, 0x1c00) : FUN_004f10f0(DAT_00862d10, 0x1c00);
        bVar39 = (iVar11 == 0x1c00);
    } else {
        iVar11 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00862d10, 28000) : FUN_004f10f0(DAT_00862d10, 28000);
        bVar39 = (iVar11 == 28000);
    }
    iVar11 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00859ef8, 0x200) : FUN_004f10f0(DAT_00859ef8, 0x200);
    int iVar12 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0085a168, 0x100) : FUN_004f10f0(DAT_0085a168, 0x100);
    int iVar13 = DAT_0072c770 == 0 ? FUN_004f11a0(&DAT_0085a150, 4) : FUN_004f10f0(&DAT_0085a150, 4);
    int iVar14 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0085a970, 0x800) : FUN_004f10f0(DAT_0085a970, 0x800);
    int iVar15 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0085a8b0, 0xc0) : FUN_004f10f0(DAT_0085a8b0, 0xc0);
    int iVar16 = DAT_0072c770 == 0 ? FUN_004f11a0(&DAT_0085a100, 4) : FUN_004f10f0(&DAT_0085a100, 4);
    int iVar17 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_007d2168, 0x4218c) : FUN_004f10f0(DAT_007d2168, 0x4218c);
    int iVar18 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0076ef10, 0x210c6) : FUN_004f10f0(DAT_0076ef10, 0x210c6);
    int iVar19 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0085a270, 0x520) : FUN_004f10f0(DAT_0085a270, 0x520);
    int iVar20 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0074de48, 0x210c6) : FUN_004f10f0(DAT_0074de48, 0x210c6);
    int iVar21 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00862110, 0xc00) : FUN_004f10f0(DAT_00862110, 0xc00);
    int iVar22 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00722a08, 4) : FUN_004f10f0(DAT_00722a08, 4);
    int iVar23 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00722a0c, 4) : FUN_004f10f0(DAT_00722a0c, 4);
    int iVar24 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00861ff8, 0x118) : FUN_004f10f0(DAT_00861ff8, 0x118);
    int iVar25 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_00861b78, 0x480) : FUN_004f10f0(DAT_00861b78, 0x480);
    int iVar26 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_007253b0, 4) : FUN_004f10f0(DAT_007253b0, 4);
    int iVar27 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0085a160, 4) : FUN_004f10f0(DAT_0085a160, 4);
    int iVar28 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_007253b4, 4) : FUN_004f10f0(DAT_007253b4, 4);
    int iVar29 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0085b170, 0x800) : FUN_004f10f0(DAT_0085b170, 0x800);
    int iVar30 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_007b10a0, 0x210c6) : FUN_004f10f0(DAT_007b10a0, 0x210c6);
    int iVar31 = DAT_0072c770 == 0 ? FUN_004f11a0(DAT_0085a790, 0x120) : FUN_004f10f0(DAT_0085a790, 0x120);
    int iVar32 = DAT_0072c770 == 0 ? FUN_004f11a0(&local_c, 8) : FUN_004f10f0(&local_c, 8);
    int iVar33;
    if (DAT_0072c770 == 0) {
        iVar33 = FUN_004f11a0(DAT_008c84b8, 4);
    } else {
        FUN_004aaf70(local_c);
        iVar33 = FUN_004f10f0(DAT_008c84b8, 4);
    }
    byte bVar2 = FUN_00401260((void*)0, 0);
    int iVar34 = DAT_0072c770 == 0 ? FUN_004f11a0(&DAT_008ca92c, 4) : FUN_004f10f0(&DAT_008ca92c, 4);
    if (DAT_008ca92c == -1) DAT_008ca92c = 0;
    if (in_EAX == 2) {
        uint32_t* puVar36 = (uint32_t*)DAT_0072c6b8;
        uint32_t* puVar37 = (uint32_t*)DAT_00869a70;
        for (int i = 0x2e; i != 0; i = i - 1) { *puVar37 = *puVar36; puVar36 = puVar36 + 1; puVar37 = puVar37 + 1; }
        puVar36 = (uint32_t*)DAT_0072c6e0;
        puVar37 = (uint32_t*)DAT_00869aa8;
        for (int i = 0x24; i != 0; i = i - 1) { *puVar37 = *puVar36; puVar36 = puVar36 + 1; puVar37 = puVar37 + 1; }
        DAT_00869a89 = 0; DAT_00869a8b = 0; DAT_00869a8d = 0; DAT_00869a8f = 0;
        DAT_00869a91 = 0; DAT_00869a93 = 0; DAT_00869a95 = 0; DAT_00869a97 = 0;
    }
    return (byte)((iVar3 == 4) & bVar1 & (iVar4 == 4) & (iVar5 == 4) & (iVar6 == 4) & (iVar7 == 4) & bVar38 &
        (iVar8 == 0x45c00) & (iVar9 == 0x1000) & (iVar10 == 0x4a00) & bVar39 & (iVar11 == 0x200) &
        (iVar12 == 0x100) & (iVar13 == 4) & (iVar14 == 0x800) & (iVar15 == 0xc0) & (iVar16 == 4) &
        (iVar17 == 0x4218c) & (iVar18 == 0x210c6) & (iVar19 == 0x520) & (iVar20 == 0x210c6) &
        (iVar21 == 0xc00) & (iVar22 == 4) & (iVar23 == 4) & (iVar24 == 0x118) & (iVar25 == 0x480) &
        (iVar26 == 4) & (iVar27 == 4) & (iVar28 == 4) & (iVar29 == 0x800) & (iVar30 == 0x210c6) &
        (iVar31 == 0x120) & (iVar32 == 8) & bVar2 & (iVar33 == 4) & (iVar34 == 4));
}

// 0x004025b0 — observed shape
void FUN_004025b0(int param_1, void* in_EAX, int unaff_EBX) {
    // Writes slot then 0x2c-stride items via 11a0/10f0; EBX count drives loops,
    // trailing FUN_00401260() per item.
    uint32_t local_4 = 0;
    if (DAT_0072c770 == 0) FUN_004f11a0(&local_4, 4);
    else FUN_004f10f0(&local_4, 4);
    if (DAT_0072c770 == 0) FUN_004f11a0(in_EAX, 4);
    else FUN_004f10f0(in_EAX, 4);
    if (0 < unaff_EBX) {
        int iVar1 = unaff_EBX;
        do {
            if (DAT_0072c770 == 0) FUN_004f11a0((void*)(intptr_t)param_1, 0x2c);
            else FUN_004f10f0((void*)(intptr_t)param_1, 0x2c);
            param_1 = param_1 + 0x2c;
            iVar1 = iVar1 - 1;
        } while (iVar1 != 0);
        if (0 < unaff_EBX) {
            do {
                FUN_00401260((void*)0, 0);
                unaff_EBX = unaff_EBX - 1;
            } while (unaff_EBX != 0);
        }
    }
}

// 0x00402650 — observed shape
uint32_t FUN_00402650(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    // Copies wide-string from FUN_004f14a0 result into DAT_008cacd0, frees scratch,
    // calls 412e50, checks FUN_004f1310, then FUN_004f0e40(...,1,...); on success
    // sets DAT_0072c770=1 and calls FUN_004025b0 + FUN_004f0dc0; returns 0/1.
    int local_4 = 0;
    uint32_t* puVar2 = (uint32_t*)FUN_004f14a0(&local_4);
    unsigned char* _Src = (unsigned char*)(uintptr_t)*puVar2;
    size_t _Size = *(size_t*)(_Src + -4);
    if (((int)_Size > -1) && (_Src != (unsigned char*)0x0) && (_Src != DAT_008cacd0)) {
        if (_Size == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(DAT_008cacd0, _Src, _Size);
            DAT_008cacd0[DAT_008caccc] = 0;
        }
    }
    puVar2 = (uint32_t*)(local_4 + -8);
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) {
        operator_delete__(puVar2);
    }
    FUN_00412e50(param_1);
    (void)param_2;
    byte cVar1 = FUN_004f1310();
    if (cVar1 != '\0') {
        int iVar3 = FUN_004f0e40(DAT_008cacd0, 1, 0, 0x8000);
        if (iVar3 != 0) return 0;
        DAT_0072c770 = 1;
        FUN_004025b0((int)param_3, (void*)(intptr_t)param_4, 0);
        FUN_004f0dc0();
    }
    return 1;
}

// 0x00402770 — observed shape
uint32_t FUN_00402770(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    // Same wide-string copy as 402650, then FUN_004f0e40(...,2,...);
    // success stores result (0) into DAT_0072c770, calls 4025b0/4f0dc0, returns 1 else 0.
    int local_4 = 0;
    uint32_t* puVar1 = (uint32_t*)FUN_004f14a0(&local_4);
    unsigned char* _Src = (unsigned char*)(uintptr_t)*puVar1;
    size_t _Size = *(size_t*)(_Src + -4);
    if (((int)_Size > -1) && (_Src != (unsigned char*)0x0) && (_Src != DAT_008cacd0)) {
        if (_Size == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(DAT_008cacd0, _Src, _Size);
            DAT_008cacd0[DAT_008caccc] = 0;
        }
    }
    puVar1 = (uint32_t*)(local_4 + -8);
    if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)DAT_008cacc8)) {
        operator_delete__(puVar1);
    }
    FUN_00412e50(param_1);
    (void)param_2;
    int iVar2 = FUN_004f0e40(DAT_008cacd0, 2, 0, 0x8000);
    if (iVar2 == 0) {
        DAT_0072c770 = iVar2;
        FUN_004025b0((int)param_3, (void*)(intptr_t)param_4, 0);
        FUN_004f0dc0();
        return 1;
    }
    return 0;
}

// 0x00402880 — observed shape
void FUN_00402880(void) {
    // Fixed "cityloc.dta" load sequence.
    FUN_004f4b20("cityloc.dta", 1, 0, 0x8000);
    FUN_004f10f0(DAT_0085b170, 0x800);
    FUN_004f4de0();
    FUN_004f0dc0();
}

// 0x00402950 — observed shape
void FUN_00402950(void) {
    // Wide-text file parse (cityloc-like): build path via 4ce080/4129c0/412a60,
    // copy into scratch, open via 4f4b20, branch on 4f8110, then loop with
    // 4f85e0/4f3ee0/4f2600 string joins, 4f1c20/4f1b10 tokens, 4ce190 dispatch
    // into DAT_008dbd08 stride-3 table skipping '#' and ';' comments.
    // Vtable-ish calls: local_44[7](0,1), (local_4c+0x10)(), (local_4c+0x1c)(0,1), (local_54+8)().
    wchar_t* pwVar1 = nullptr;
    unsigned char* _Src = nullptr;
    uint32_t uVar2;
    uint32_t* puVar3 = nullptr;
    int iVar4;
    size_t sVar7 = 0;
    unsigned char* unaff_EBX = DAT_008cacd0;
    wchar_t* pwVar8 = nullptr;
    wchar_t* unaff_EBP = nullptr;
    wchar_t* pwVar9 = (wchar_t*)DAT_008cacd0;
    uint32_t** ppuVar10 = nullptr;
    void* puVar11 = DAT_006fb738;
    uint32_t local_54 = (uint32_t)(uintptr_t)DAT_008cacd0;
    uint32_t* local_50 = (uint32_t*)DAT_008cacd0;
    unsigned char* local_4c = DAT_008cacd0;
    int local_48 = 0;
    void** local_44 = (void**)PTR_FUN_006f5814;
    uint32_t local_40 = 0, local_3c = 0, local_38 = 0, local_34 = 0, local_30 = 0, local_2c = 0;
    unsigned char* local_28 = DAT_008cacd0;
    int local_24 = 0;
    int local_1c = 0;
    unsigned char* local_18 = nullptr;
    unsigned char* local_14 = nullptr;
    unsigned char* local_10 = DAT_008cacd0;
    unsigned char* local_c = DAT_008cacd0;
    uint32_t local_8 = 0, local_4 = 0;
    // observed* initial local* temporaries (4129c0/412a60 results use stack slots)
    (void)local_40; (void)local_3c; (void)local_38; (void)local_34; (void)local_30; (void)local_2c;
    (void)local_28; (void)local_8; (void)pwVar1; (void)pwVar8; (void)ppuVar10;
    uVar2 = FUN_004ce080(&local_48);
    // NOTE: pseudocode passes stack addresses; preserve call order:
    FUN_004129c0(&local_4c, uVar2, &local_50, puVar11);
    puVar3 = (uint32_t*)FUN_00412a60(&local_50, puVar11);
    _Src = (unsigned char*)(uintptr_t)*puVar3;
    sVar7 = *(size_t*)(_Src + -4);
    pwVar9 = (wchar_t*)DAT_008cacd0;
    if (((int)sVar7 > -1) && (_Src != (unsigned char*)0x0) && (_Src != DAT_008cacd0)) {
        if (sVar7 == 0) {
            FUN_00412f90();
            pwVar9 = (wchar_t*)(uintptr_t)local_54;
        } else {
            FUN_004f3350();
            pwVar9 = (wchar_t*)(uintptr_t)local_54;
            memmove((void*)(uintptr_t)local_54, _Src, sVar7);
            *(char*)((intptr_t)pwVar9 + *(int*)(pwVar9 + -2)) = '\0';
        }
    }
    local_50 = local_50 + -2;
    if ((local_50 != (uint32_t*)0x0) && (local_50 != (uint32_t*)DAT_008cacc8)) operator_delete__(local_50);
    puVar3 = (uint32_t*)(local_4c + -8);
    local_50 = (uint32_t*)DAT_008cacd0;
    if ((puVar3 != (uint32_t*)0x0) && (puVar3 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar3);
    puVar3 = (uint32_t*)(local_48 + -8);
    local_4c = DAT_008cacd0;
    if ((puVar3 != (uint32_t*)0x0) && (puVar3 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar3);
    iVar4 = FUN_004f4b20(pwVar9, 1, 0, 0);
    if (iVar4 == 0) {
        FUN_004f8110(&local_44);
        if (local_18 == (unsigned char*)0x0) local_4 = FUN_004f1220(0, 1);
        else local_4 = *(uint32_t*)(local_18 + 0x14);
        if (local_24 == 1) FUN_004f8250(&local_44);
    }
    // vtable dispatch loop conditions observed: uVar5=u[7](0,1) vs u6=(local_4c+0x10)()
    using FnU = uint32_t(*)(uint32_t, int);
    using Fn0 = uint32_t(*)();
    uint32_t uVar5 = ((FnU)(local_44[7]))(0, 1);
    uint32_t uVar6 = ((Fn0)(*(void**)((char*)local_4c + 0x10)))();
    if (uVar5 < uVar6) {
        local_50 = (uint32_t*)DAT_008dbd08;
        do {
            if (local_1c == 1) {
                local_54 = (uint32_t)(uintptr_t)DAT_008cacd0;
                FUN_004f85e0(&local_4c, &local_54);
                pwVar1 = (wchar_t*)(uintptr_t)local_54;
                if ((wchar_t*)(uintptr_t)local_54 != (wchar_t*)0x0) {
                    sVar7 = wcslen((wchar_t*)(uintptr_t)local_54);
                    if ((int)sVar7 > -1) {
                        FUN_004f3ee0();
                        local_54 = (uint32_t)(uintptr_t)DAT_008cacd0;
                        FUN_004f2600(DAT_00710530, unaff_EBX);
                        pwVar8 = (wchar_t*)(uintptr_t)local_54;
                        sVar7 = *(size_t*)(pwVar8 + -2);
                        if (((int)sVar7 > -1) && ((wchar_t*)(uintptr_t)local_54 != pwVar9)) {
                            if (sVar7 == 0) {
                                FUN_00412f90();
                                pwVar9 = unaff_EBP;
                            } else {
                                FUN_004f3350();
                                memmove(unaff_EBP, pwVar8, sVar7);
                                *(char*)((intptr_t)unaff_EBP + *(int*)(unaff_EBP + -2)) = '\0';
                                pwVar9 = unaff_EBP;
                            }
                        }
                        pwVar8 = pwVar8 + -4;
                        if ((pwVar8 != (wchar_t*)0x0) && (pwVar8 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar8);
                        puVar3 = (uint32_t*)(unaff_EBX + -8);
                        if ((puVar3 != (uint32_t*)0x0) && (puVar3 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar3);
                        unaff_EBX = DAT_008cacd0;
                    }
                }
                pwVar1 = pwVar1 + -4;
                if ((pwVar1 != (wchar_t*)0x0) && (pwVar1 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar1);
            } else {
                FUN_004f84d0((void*)(intptr_t)(0 + -0x5c));
                pwVar9 = unaff_EBP;
            }
            FUN_004f1c20();
            FUN_004f1b10((void*)(intptr_t)(0 + -0x5c));
            puVar3 = local_50;
            if ((*(int*)(pwVar9 + -2) != 0) && ((char)*pwVar9 != '#') && ((char)*pwVar9 != ';')) {
                FUN_004ce190((void*)(intptr_t)(0 + -0x5c), local_50);
                local_50 = puVar3 + 3;
            }
            uVar5 = ((FnU)(*(void**)((char*)local_4c + 0x1c)))(0, 1);
            uVar6 = ((Fn0)(*(void**)((char*)(uintptr_t)local_54 + 8)))();
        } while (uVar5 < uVar6);
    }
    puVar3 = (uint32_t*)(local_18 + -8);
    if ((puVar3 != (uint32_t*)0x0) && (puVar3 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar3);
    puVar3 = (uint32_t*)(local_14 + -8);
    local_18 = DAT_008cacd0;
    if ((puVar3 != (uint32_t*)0x0) && (puVar3 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar3);
    local_14 = DAT_008cacd0;
    FUN_004f4de0();
    FUN_00412b40();
    pwVar9 = pwVar9 + -4;
    if ((pwVar9 != (wchar_t*)0x0) && (pwVar9 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar9);
}

// 0x00402cd0 — observed shape
void FUN_00402cd0(void) {
    // Same wide-text parse as 402950 but comment-strip loop handles '#' groups
    // (local_58 counter, /3 entries) and writes into DAT_008d8918 + stride pattern.
    // Loop bound (int)local_54 < 0xd; 4f1c20/4f1b10 per line; 4ce190 on data lines.
    unsigned char* _Src = nullptr;
    uint32_t uVar1;
    uint32_t* puVar2 = nullptr;
    wchar_t* pwVar3 = nullptr;
    int iVar4;
    size_t sVar5 = 0;
    wchar_t* pwVar6 = nullptr;
    wchar_t* pwVar7 = (wchar_t*)DAT_008cacd0;
    wchar_t* pwVar8 = nullptr;
    // Wait declared below used: pwVar6/pwVar7
    (void)pwVar8;
    unsigned char** ppuVar8 = nullptr;
    void* puVar9 = DAT_006fb738;
    wchar_t* local_5c = (wchar_t*)DAT_008cacd0;
    int local_58 = -1;
    unsigned char* local_54 = nullptr;
    unsigned char* local_50 = DAT_008cacd0;
    int local_4c = 0;
    wchar_t* local_48 = nullptr;
    void** local_44 = (void**)PTR_FUN_006f5814;
    uint32_t local_40 = 0, local_3c = 0, local_38 = 0, local_34 = 0, local_30 = 0, local_2c = 0;
    unsigned char* local_28 = DAT_008cacd0;
    int local_24 = 0;
    uint32_t local_1c = 0;
    int local_18 = 0;
    int local_14 = 0;
    unsigned char* local_10 = DAT_008cacd0;
    unsigned char* local_c = DAT_008cacd0;
    uint32_t local_8 = 0, local_4 = 0;
    (void)local_40; (void)local_3c; (void)local_38; (void)local_34; (void)local_30; (void)local_2c;
    (void)local_28; (void)local_1c; (void)ppuVar8;
    uVar1 = FUN_004ce080(&local_48);
    // stack temporaries: local_54, local_50 used as 4129c0/412a60 slots
    unsigned char* tmp54 = DAT_008cacd0;
    FUN_004129c0(&tmp54, uVar1, &local_50, puVar9);
    puVar2 = (uint32_t*)FUN_00412a60(&local_50, puVar9);
    _Src = (unsigned char*)(uintptr_t)*puVar2;
    sVar5 = *(size_t*)(_Src + -4);
    pwVar7 = (wchar_t*)DAT_008cacd0;
    if (((int)sVar5 > -1) && (_Src != (unsigned char*)0x0) && (_Src != DAT_008cacd0)) {
        if (sVar5 == 0) {
            FUN_00412f90();
            pwVar7 = local_5c;
        } else {
            FUN_004f3350();
            pwVar7 = local_5c;
            memmove(local_5c, _Src, sVar5);
            *(char*)((intptr_t)pwVar7 + *(int*)(pwVar7 + -2)) = '\0';
        }
    }
    puVar2 = (uint32_t*)(local_50 + -8);
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
    puVar2 = (uint32_t*)(tmp54 + -8);
    local_50 = DAT_008cacd0;
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
    pwVar3 = (wchar_t*)((unsigned char*)local_48 + -4);
    local_54 = DAT_008cacd0;
    if ((pwVar3 != (wchar_t*)0x0) && (pwVar3 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar3);
    iVar4 = FUN_004f4b20(pwVar7, 1, 0, 0);
    if (iVar4 == 0) {
        FUN_004f8110(&local_44);
        if (local_18 == 0) local_4 = FUN_004f1220(0, 1);
        else local_4 = *(uint32_t*)(local_18 + 0x14);
        if (local_24 == 1) FUN_004f8250(&local_44);
    }
    local_54 = (unsigned char*)0x0;
    do {
        if (local_14 == 1) {
            local_48 = (wchar_t*)DAT_008cacd0;
            FUN_004f85e0(&local_44, &local_48);
            pwVar3 = local_48;
            if ((local_48 != (wchar_t*)0x0) && ((sVar5 = wcslen(local_48)), (int)sVar5 > -1)) {
                FUN_004f3ee0();
                local_48 = (wchar_t*)DAT_008cacd0;
                FUN_004f2600(DAT_00710530, local_50);
                pwVar6 = local_48;
                sVar5 = *(size_t*)(local_48 + -2);
                if (((int)sVar5 > -1) && (local_48 != pwVar7)) {
                    if (sVar5 == 0) {
                        FUN_00412f90();
                        pwVar7 = local_5c;
                    } else {
                        FUN_004f3350();
                        pwVar7 = local_5c;
                        memmove(local_5c, pwVar6, sVar5);
                        *(char*)((intptr_t)pwVar7 + *(int*)(pwVar7 + -2)) = '\0';
                    }
                }
                pwVar6 = pwVar6 + -4;
                if ((pwVar6 != (wchar_t*)0x0) && (pwVar6 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar6);
                puVar2 = (uint32_t*)(local_50 + -8);
                if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
                local_50 = DAT_008cacd0;
            }
            pwVar3 = pwVar3 + -4;
            if ((pwVar3 != (wchar_t*)0x0) && (pwVar3 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar3);
        } else {
            FUN_004f84d0(&local_5c);
            pwVar7 = local_5c;
        }
        FUN_004f1c20();
        FUN_004f1b10(&local_5c);
        iVar4 = local_4c;
        if ((*(int*)(pwVar7 + -2) != 0) && ((char)*pwVar7 != ';')) {
            if ((char)*pwVar7 == '#') {
                local_58 = local_58 + 1;
                if (2 < local_58) {
                    local_54 = local_54 + 3;
                    local_58 = 0;
                }
                local_4c = 0;
            } else {
                FUN_004ce190(&local_5c, DAT_008d8918 + ((int)(local_54 + local_58) * 0x40 + local_4c) * 3);
                local_4c = iVar4 + 1;
            }
        }
    } while ((intptr_t)local_54 < 0xd);
    puVar2 = (uint32_t*)(local_10 + -8);
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
    puVar2 = (uint32_t*)(local_c + -8);
    local_10 = DAT_008cacd0;
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
    local_c = DAT_008cacd0;
    FUN_004f4de0();
    pwVar7 = pwVar7 + -4;
    if ((pwVar7 != (wchar_t*)0x0) && (pwVar7 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar7);
    FUN_00412b40();
}

// 0x00403050 — observed shape
void FUN_00403050(void) {
    // Applies "Revenge" string from DAT_00869b48 to every DAT_008db620+3 table row
    // up to 0x8db680; empty-string rows zero the target, else FUN_004f3350+memmove.
    FUN_004f6090("Revenge");
    int* piVar4 = (int*)DAT_008db620;
    do {
        char* pcVar2 = (char*)DAT_00869b48;
        char* pcVar3;
        do {
            pcVar3 = pcVar2;
            pcVar2 = pcVar3 + 1;
        } while (*pcVar3 != '\0');
        pcVar3 = pcVar3 + -0x869b48; // length (int)
        // length as offset from DAT_00869b48 base
        size_t len = (size_t)(intptr_t)(pcVar3);
        if (((int)len > -1)) {
            unsigned char* puVar1 = (unsigned char*)(uintptr_t)*piVar4;
            if (puVar1 != DAT_00869b48) {
                if (len == 0) {
                    if (*(int*)(puVar1 + -4) != 0) {
                        *puVar1 = 0;
                        *(uint32_t*)(*piVar4 + -4) = 0;
                    }
                } else {
                    FUN_004f3350();
                    memmove((void*)(uintptr_t)*piVar4, DAT_00869b48, len);
                    *(unsigned char*)(*piVar4 + *(int*)(*piVar4 + -4)) = 0;
                }
            }
        }
        piVar4 = piVar4 + 3;
    } while ((intptr_t)piVar4 < 0x8db680);
}

// 0x004030e0 — observed shape
void FUN_004030e0(void) {
    // Same envelope as 402cd0; per-line dispatch into DAT_008db678 with
    // local_54 seeded 0xffffffec, '#': +=0x14; bound (int)local_54 < 0x79;
    // teardown zeroes _DAT_008ca938.._DAT_008ca950.
    unsigned char* _Src = nullptr;
    uint32_t uVar1;
    uint32_t* puVar2 = nullptr;
    wchar_t* pwVar3 = nullptr;
    int iVar4;
    size_t sVar5 = 0;
    wchar_t* pwVar6 = nullptr;
    wchar_t* pwVar7 = (wchar_t*)DAT_008cacd0;
    unsigned char** ppuVar8 = nullptr;
    void* puVar9 = DAT_006fb738;
    wchar_t* local_58 = (wchar_t*)DAT_008cacd0;
    unsigned char* local_54 = nullptr;
    unsigned char* local_50 = DAT_008cacd0;
    int local_4c = 0;
    wchar_t* local_48 = nullptr;
    void** local_44 = (void**)PTR_FUN_006f5814;
    uint32_t local_40 = 0, local_3c = 0, local_38 = 0, local_34 = 0, local_30 = 0, local_2c = 0;
    unsigned char* local_28 = DAT_008cacd0;
    int local_24 = 0;
    uint32_t local_1c = 0;
    int local_18 = 0;
    int local_14 = 0;
    unsigned char* local_10 = DAT_008cacd0;
    unsigned char* local_c = DAT_008cacd0;
    uint32_t local_8 = 0, local_4 = 0;
    (void)local_40; (void)local_3c; (void)local_38; (void)local_34; (void)local_30; (void)local_2c;
    (void)local_28; (void)local_1c; (void)ppuVar8; (void)ppuVar8;
    uVar1 = FUN_004ce080(&local_48);
    unsigned char* tmp54 = DAT_008cacd0;
    FUN_004129c0(&tmp54, uVar1, &local_50, puVar9);
    puVar2 = (uint32_t*)FUN_00412a60(&local_50, puVar9);
    _Src = (unsigned char*)(uintptr_t)*puVar2;
    sVar5 = *(size_t*)(_Src + -4);
    pwVar7 = (wchar_t*)DAT_008cacd0;
    if (((int)sVar5 > -1) && (_Src != (unsigned char*)0x0) && (_Src != DAT_008cacd0)) {
        if (sVar5 == 0) {
            FUN_00412f90();
            pwVar7 = local_58;
        } else {
            FUN_004f3350();
            pwVar7 = local_58;
            memmove(local_58, _Src, sVar5);
            *(char*)((intptr_t)pwVar7 + *(int*)(pwVar7 + -2)) = '\0';
        }
    }
    puVar2 = (uint32_t*)(local_50 + -8);
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
    puVar2 = (uint32_t*)(tmp54 + -8);
    local_50 = DAT_008cacd0;
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
    pwVar3 = (wchar_t*)((unsigned char*)local_48 + -4);
    local_54 = DAT_008cacd0;
    if ((pwVar3 != (wchar_t*)0x0) && (pwVar3 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar3);
    iVar4 = FUN_004f4b20(pwVar7, 1, 0, 0);
    if (iVar4 == 0) {
        FUN_004f8110(&local_44);
        if (local_18 == 0) local_4 = FUN_004f1220(0, 1);
        else local_4 = *(uint32_t*)(local_18 + 0x14);
        if (local_24 == 1) FUN_004f8250(&local_44);
    }
    local_54 = (unsigned char*)(uintptr_t)0xffffffec;
    do {
        if (local_14 == 1) {
            local_48 = (wchar_t*)DAT_008cacd0;
            FUN_004f85e0(&local_44, &local_48);
            pwVar3 = local_48;
            if ((local_48 != (wchar_t*)0x0) && ((sVar5 = wcslen(local_48)), (int)sVar5 > -1)) {
                FUN_004f3ee0();
                local_48 = (wchar_t*)DAT_008cacd0;
                FUN_004f2600(DAT_00710530, local_50);
                pwVar6 = local_48;
                sVar5 = *(size_t*)(local_48 + -2);
                if (((int)sVar5 > -1) && (local_48 != pwVar7)) {
                    if (sVar5 == 0) {
                        FUN_00412f90();
                        pwVar7 = local_58;
                    } else {
                        FUN_004f3350();
                        pwVar7 = local_58;
                        memmove(local_58, pwVar6, sVar5);
                        *(char*)((intptr_t)pwVar7 + *(int*)(pwVar7 + -2)) = '\0';
                    }
                }
                pwVar6 = pwVar6 + -4;
                if ((pwVar6 != (wchar_t*)0x0) && (pwVar6 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar6);
                puVar2 = (uint32_t*)(local_50 + -8);
                if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
                local_50 = DAT_008cacd0;
            }
            pwVar3 = pwVar3 + -4;
            if ((pwVar3 != (wchar_t*)0x0) && (pwVar3 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar3);
        } else {
            FUN_004f84d0(&local_58);
            pwVar7 = local_58;
        }
        FUN_004f1c20();
        FUN_004f1b10(&local_58);
        iVar4 = local_4c;
        if ((*(int*)(pwVar7 + -2) != 0) && ((char)*pwVar7 != ';')) {
            if ((char)*pwVar7 == '#') {
                local_54 = local_54 + 0x14;
                local_4c = 0;
            } else {
                FUN_004ce190(&local_58, DAT_008db678 + (int)(local_54 + local_4c) * 3);
                local_4c = iVar4 + 1;
            }
        }
    } while ((intptr_t)local_54 < 0x79);
    puVar2 = (uint32_t*)(local_10 + -8);
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
    puVar2 = (uint32_t*)(local_c + -8);
    local_10 = DAT_008cacd0;
    if ((puVar2 != (uint32_t*)0x0) && (puVar2 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar2);
    local_c = DAT_008cacd0;
    FUN_004f4de0();
    _DAT_008ca938 = 0;
    _DAT_008ca93c = 0;
    _DAT_008ca940 = 0;
    pwVar7 = pwVar7 + -4;
    _DAT_008ca944 = 0;
    _DAT_008ca948 = 0;
    _DAT_008ca94c = 0;
    _DAT_008ca950 = 0;
    if ((pwVar7 != (wchar_t*)0x0) && (pwVar7 != (wchar_t*)DAT_008cacc8)) operator_delete__(pwVar7);
    FUN_00412b40();
}

// 0x00403470 — observed shape
void FUN_00403470(void) {
    // Multi-section table parser: 4ce080/4129c0/412a60 prelude, 4f4b20 open,
    // then 6 sequential section loops (008cb100/008cae00/008cae0c/008cae18/008cae24/
    // 008cb178/008cb19c) each doing 4f84d0/4f1c20/4f1b10 + 412f10 on data lines
    // with ';'/'#' skips and running vtable comparisons (DAT_008cace0/ec, +0x10/+0x1c).
    // Teardown: operator_delete, 4f4de0, delete scratch, 412b40.
    // Pseudocode uses register-resident iteration pointers (unaff_EBP/EDI,
    // pcVar12/pcVar10/pcVar9/pcVar8/pcVar6); preserved here as locals.
    uint32_t local_54 = (uint32_t)(uintptr_t)DAT_008cacd0;
    int local_50 = 0, local_4c = 0, local_48 = 0, local_24 = 0;
    FUN_004ce080();
    FUN_004129c0();
    uint32_t* puVar1 = (uint32_t*)FUN_00412a60();
    unsigned char* _Src = (unsigned char*)(uintptr_t)*puVar1;
    size_t sVar5 = *(size_t*)(_Src + -4);
    if (((int)sVar5 > -1) && (_Src != (unsigned char*)0x0) && (_Src != DAT_008cacd0)) {
        if (sVar5 == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(DAT_008cacd0, _Src, sVar5);
            DAT_008cacd0[DAT_008caccc] = 0;
        }
    }
    puVar1 = (uint32_t*)(local_4c + -8);
    if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar1);
    puVar1 = (uint32_t*)(local_50 + -8);
    if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar1);
    puVar1 = (uint32_t*)(local_48 + -8);
    if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar1);
    int iVar2 = FUN_004f4b20();
    if (iVar2 == 0) {
        FUN_004f8110();
        FUN_004f1220();
        if (local_24 == 1) FUN_004f8250();
    }
    char* pcVar12 = nullptr;
    uint32_t uVar3 = FUN_004f83a0();
    uint32_t uVar4 = ((uint32_t(*)())DAT_008cace0)();
    char* pcVar7 = DAT_008cacd0;
    char* unaff_EBP = DAT_008cacd0;
    char* unaff_EDI = DAT_008cacd0;
    char* pcVar10 = nullptr;
    if (uVar3 < uVar4) {
        local_54 = (uint32_t)(uintptr_t)DAT_008cb100;
        do {
            if (0x8cb177 < (intptr_t)local_54) break;
            FUN_004f84d0(unaff_EBP);
            FUN_004f1c20();
            FUN_004f1b10(unaff_EBP);
            if ((*(int*)(unaff_EBP + -4) != 0) && (*unaff_EBP != ';') && (*unaff_EBP != '#')) {
                local_54 = local_54 + 3;
                FUN_00412f10();
            }
            uVar3 = ((uint32_t(*)())DAT_008cacec)();
            // ((code*)local_54[4])() — vtable at +16
            uVar4 = ((uint32_t(*)())(*(void**)(local_54 + 16)))();
            pcVar7 = unaff_EBP;
        } while (uVar3 < uVar4);
    }
    pcVar10 = nullptr;
    uVar3 = ((uint32_t(*)())DAT_008cacec)();
    uVar4 = ((uint32_t(*)())(*(void**)(local_54 + 16)))();
    if (uVar3 < uVar4) {
        uint32_t* puVar1b = (uint32_t*)DAT_008cae00;
        do {
            if (0x8cb0ff < (intptr_t)puVar1b) break;
            if (local_24 == 1) {
                FUN_004f85e0();
                sVar5 = wcslen((wchar_t*)DAT_008cacd0);
                if ((int)sVar5 > -1) {
                    FUN_004f3ee0();
                    FUN_004f2600();
                    iVar2 = DAT_008caccc;
                    if ((iVar2 > -1) && (pcVar7 != DAT_008cacd0)) {
                        if (DAT_008caccc == 0) {
                            FUN_00412f90();
                            pcVar7 = unaff_EDI;
                        } else {
                            FUN_004f3350();
                            memmove(unaff_EDI, DAT_008cacd0, (size_t)iVar2);
                            unaff_EDI[*(int*)(unaff_EDI + -4)] = '\0';
                            pcVar7 = unaff_EDI;
                        }
                    }
                    char* pcVar6 = unaff_EBP + -8;
                    if ((pcVar6 != (char*)0x0) && (pcVar6 != (char*)DAT_008cacc8)) operator_delete__(pcVar6);
                    unaff_EBP = DAT_008cacd0;
                }
            } else {
                FUN_004f84d0(unaff_EDI);
                pcVar7 = unaff_EDI;
            }
            FUN_004f1c20();
            FUN_004f1b10(pcVar7);
            if ((*(int*)(pcVar7 + -4) != 0) && (*pcVar7 != ';') && (*pcVar7 != '#')) {
                puVar1b = puVar1b + 0xc;
                FUN_00412f10();
            }
            uVar3 = ((uint32_t(*)())(*(void**)(local_54 + 28)))();
            uVar4 = ((uint32_t(*)())(*(void**)((char*)unaff_EBP + 0x10)))();
        } while (uVar3 < uVar4);
    }
    {
        char* pcVar6 = nullptr;
        uVar3 = ((uint32_t(*)())(*(void**)(local_54 + 28)))();
        uVar4 = ((uint32_t(*)())(*(void**)((char*)unaff_EBP + 0x10)))();
        if (uVar3 < uVar4) {
            uint32_t* puVar1b = (uint32_t*)DAT_008cae0c;
            do {
                if (0x8cb10b < (intptr_t)puVar1b) break;
                pcVar7 = pcVar12;
                FUN_004f84d0(pcVar7);
                pcVar12 = pcVar7;
                FUN_004f1c20();
                FUN_004f1b10(pcVar7);
                if ((*(int*)(pcVar7 + -4) != 0) && (*pcVar7 != ';') && (*pcVar7 != '#')) {
                    puVar1b = puVar1b + 0xc;
                    FUN_00412f10();
                }
                uVar3 = ((uint32_t(*)())(*(void**)((char*)unaff_EBP + 0x1c)))();
                uVar4 = ((uint32_t(*)())(*(void**)((char*)unaff_EDI + 0x10)))();
            } while (uVar3 < uVar4);
        }
        char* pcVar9 = nullptr;
        uVar3 = ((uint32_t(*)())(*(void**)((char*)unaff_EBP + 0x1c)))();
        uVar4 = ((uint32_t(*)())(*(void**)((char*)unaff_EDI + 0x10)))();
        if (uVar3 < uVar4) {
            void* puVar11 = DAT_008cae18;
            do {
                if (0x8cb117 < (intptr_t)puVar11) break;
                pcVar7 = pcVar10;
                FUN_004f84d0(pcVar7);
                pcVar10 = pcVar7;
                FUN_004f1c20();
                FUN_004f1b10(pcVar7);
                if ((*(int*)(pcVar7 + -4) != 0) && (*pcVar7 != ';') && (*pcVar7 != '#')) {
                    puVar11 = (unsigned char*)puVar11 + 0x30;
                    FUN_00412f10();
                }
                uVar3 = ((uint32_t(*)())(*(void**)((char*)unaff_EDI + 0x1c)))();
                uVar4 = ((uint32_t(*)())(*(void**)((char*)pcVar12 + 0x10)))();
            } while (uVar3 < uVar4);
        }
        char* pcVar8 = nullptr;
        uVar3 = ((uint32_t(*)())(*(void**)((char*)unaff_EDI + 0x1c)))();
        uVar4 = ((uint32_t(*)())(*(void**)((char*)pcVar12 + 0x10)))();
        if (uVar3 < uVar4) {
            void* puVar11 = DAT_008cae24;
            unsigned char auStackY_128[128] = {};
            do {
                if (0x8cb123 < (intptr_t)puVar11) break;
                pcVar7 = pcVar6;
                FUN_004f84d0(auStackY_128 + 0xac);
                pcVar6 = pcVar7;
                FUN_004f1c20();
                FUN_004f1b10(auStackY_128 + 0xac);
                if ((*(int*)(pcVar7 + -4) != 0) && (*pcVar7 != ';') && (*pcVar7 != '#')) {
                    puVar11 = (unsigned char*)puVar11 + 0x30;
                    FUN_00412f10();
                }
                uVar3 = ((uint32_t(*)(uint32_t,int))(*(void**)((char*)pcVar12 + 0x1c)))(0, 1);
                uVar4 = ((uint32_t(*)())(*(void**)((char*)pcVar10 + 0x10)))();
            } while (uVar3 < uVar4);
        }
        uVar3 = ((uint32_t(*)(uint32_t,int))(*(void**)((char*)pcVar12 + 0x1c)))(0, 1);
        uVar4 = ((uint32_t(*)())(*(void**)((char*)pcVar10 + 0x10)))();
        if (uVar3 < uVar4) {
            uint32_t* puVar1b = (uint32_t*)DAT_008cb178;
            unsigned char auStackY_128[128] = {};
            do {
                if (0x8cb19b < (intptr_t)puVar1b) break;
                pcVar7 = pcVar9;
                FUN_004f84d0(auStackY_128 + 0xa4);
                pcVar9 = pcVar7;
                FUN_004f1c20();
                FUN_004f1b10(auStackY_128 + 0xa4);
                if ((*(int*)(pcVar7 + -4) != 0) && (*pcVar7 != ';') && (*pcVar7 != '#')) {
                    puVar1b = puVar1b + 3;
                    FUN_00412f10();
                }
                uVar3 = ((uint32_t(*)(uint32_t,int))(*(void**)((char*)pcVar10 + 0x1c)))(0, 1);
                uVar4 = ((uint32_t(*)())(*(void**)((char*)pcVar6 + 0x10)))();
            } while (uVar3 < uVar4);
        }
        uVar3 = ((uint32_t(*)(uint32_t,int))(*(void**)((char*)pcVar10 + 0x1c)))(0, 1);
        uVar4 = ((uint32_t(*)())(*(void**)((char*)pcVar6 + 0x10)))();
        if (uVar3 < uVar4) {
            uint32_t* puVar1b = (uint32_t*)DAT_008cb19c;
            unsigned char auStackY_128[128] = {};
            do {
                if (0x8cb1d7 < (intptr_t)puVar1b) break;
                pcVar7 = pcVar8;
                FUN_004f84d0(auStackY_128 + 0x9c);
                pcVar8 = pcVar7;
                FUN_004f1c20();
                FUN_004f1b10(auStackY_128 + 0x9c);
                if ((*(int*)(pcVar7 + -4) != 0) && (*pcVar7 != ';') && (*pcVar7 != '#')) {
                    puVar1b = puVar1b + 3;
                    FUN_00412f10();
                }
                uVar3 = ((uint32_t(*)(uint32_t,int))(*(void**)((char*)pcVar6 + 0x1c)))(0, 1);
                uVar4 = ((uint32_t(*)())(*(void**)((char*)pcVar9 + 0x10)))();
            } while (uVar3 < uVar4);
        }
        (void)pcVar6;
    }
    puVar1 = (uint32_t*)(local_48 + -8);
    if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar1);
    operator_delete__(PTR_LAB_006f580c);
    FUN_004f4de0();
    pcVar7 = pcVar7 + -8;
    if ((pcVar7 != (char*)0x0) && (pcVar7 != (char*)DAT_008cacc8)) operator_delete__(pcVar7);
    FUN_00412b40();
}

// 0x00404220 — observed shape
void FUN_00404220(void) {
    // World/session reset and re-init: zero header words, clear 0085a168 (0x40),
    // distinct rand()%4 pairs marked 0xffffffff/1, cross-mark 0085a208/0085a17c,
    // clear 0085bf70 (0x1280)/00859ef8 (0x80)/008142f8 (0x11700) to 0xffff stride 0x22e,
    // then call loaders 402cd0/402950/403470/403050, fill 0085bf84 rand()%3,
    // per-record random walk (FUN_004131d0 branch by 0x85b438), 428a30(1),
    // ship-type table init 2..10, clear 0085a270/00869a70, FUN_00401000(0),
    // DAT_00869b18=10, and 00415290 ship spawn pass clearing bit (rand()%8).
    DAT_0085a150 = 0;
    DAT_0085a154 = 0;
    DAT_0085a100 = 0;
    {
        uint32_t* puVar16 = (uint32_t*)DAT_0085a168;
        for (int i = 0x40; i != 0; i = i - 1) { *puVar16 = 0; puVar16 = puVar16 + 1; }
    }
    uint32_t uVar7, uVar8;
    do {
        uVar7 = (uint32_t)rand() & 0x80000003u;
        if ((int32_t)uVar7 < 0) uVar7 = (uVar7 - 1u | 0xfffffffc) + 1u;
        uVar8 = (uint32_t)rand() & 0x80000003u;
        if ((int32_t)uVar8 < 0) uVar8 = (uVar8 - 1u | 0xfffffffc) + 1u;
    } while (uVar7 == uVar8);
    if (DAT_0085a158 != 0) {
        ((uint32_t*)DAT_0085a168)[uVar7 + uVar8 * 8] = 0xffffffffu;
        ((uint32_t*)DAT_0085a168)[uVar8 + uVar7 * 8] = 0xffffffffu;
    }
    {
        uint32_t* puVar16 = (uint32_t*)DAT_0085a17c;
        uint32_t* puVar19 = (uint32_t*)DAT_0085a208;
        do {
            do {
                // rand_exref invoked via code* in pseudocode
                uVar7 = (uint32_t)rand() & 0x80000001u;
                if ((int32_t)uVar7 < 0) uVar7 = (uVar7 - 1u | 0xfffffffe) + 1u;
                int iVar13 = (int)(-(uint32_t)(uVar7 != 0) & 0xfffffffd) + 4;
                if (iVar13 < 1) uVar7 = 0;
                else {
                    int iVar9 = rand();
                    uVar7 = (uint32_t)(iVar9 % iVar13);
                }
                uVar8 = (uint32_t)rand() & 0x80000003u;
                if ((int32_t)uVar8 < 0) uVar8 = (uVar8 - 1u | 0xfffffffc) + 1u;
            } while (uVar7 == uVar8);
            int iVar13 = (int)uVar8 + (int)uVar7 * 8;
            if (((uint32_t*)DAT_0085a168)[iVar13] != 1) {
                ((uint32_t*)DAT_0085a168)[uVar7 + uVar8 * 8] = 1;
                ((uint32_t*)DAT_0085a168)[iVar13] = 1;
            }
            puVar19[-8] = 1;
            *puVar19 = 1;
            puVar16[-1] = 1;
            *puVar16 = 1;
            puVar19 = puVar19 + 1;
            puVar16 = puVar16 + 8;
        } while ((intptr_t)puVar19 < 0x85a218);
    }
    {
        uint32_t* puVar16 = (uint32_t*)DAT_0085bf70;
        for (int i = 0x1280; i != 0; i = i - 1) { *puVar16 = 0; puVar16 = puVar16 + 1; }
    }
    {
        uint32_t* puVar16 = (uint32_t*)DAT_00859ef8;
        for (int i = 0x80; i != 0; i = i - 1) { *puVar16 = 0; puVar16 = puVar16 + 1; }
    }
    {
        uint32_t* puVar16 = (uint32_t*)&DAT_008142f8;
        for (int i = 0x11700; i != 0; i = i - 1) { *puVar16 = 0; puVar16 = puVar16 + 1; }
    }
    {
        ushort* puVar10 = (ushort*)&DAT_008142f8;
        do {
            *puVar10 = 0xffff;
            puVar10 = puVar10 + 0x22e;
        } while ((intptr_t)puVar10 < 0x859ef8);
    }
    FUN_00402cd0();
    FUN_00402950();
    FUN_00403470();
    FUN_00403050();
    {
        uint32_t* puVar16 = (uint32_t*)DAT_0085bf84;
        uint32_t* puVar19 = nullptr;
        do {
            int iVar13 = rand();
            *puVar16 = 0xffffffffu;
            puVar16[1] = 0xffffffffu;
            puVar19 = puVar16 + 0x25;
            puVar16[-4] = (uint32_t)(iVar13 % 3);
            puVar16 = puVar19;
        } while ((intptr_t)puVar19 < 0x85d8f4);
    }
    {
        int local_8 = 0;
        ushort* puVar17 = (ushort*)DAT_0085bff6;
        int* local_4 = (int*)DAT_0085b178;
        unsigned char* pbVar18 = DAT_00860b75;
        while (true) {
            ushort* puVar20 = puVar17 + -0x19;
            for (int i = 0xc; i != 0; i = i - 1) {
                puVar20[0] = 0xffff; puVar20[1] = 0xffff; puVar20 = puVar20 + 2;
            }
            *puVar20 = 0xffff;
            if (*pbVar18 < 5) *pbVar18 = 5;
            byte bVar2 = *pbVar18;
            char cVar14;
            if (bVar2 == 0) cVar14 = '\0';
            else {
                int iVar13 = ((int(*)())rand_exref)();
                cVar14 = (char)(iVar13 % (int)(uint32_t)bVar2);
            }
            *pbVar18 = (char)((*pbVar18 + 1) / 2) + cVar14;
            int iVar13 = *(int*)(pbVar18 + 7);
            if (99 < iVar13) iVar13 = 200 - iVar13;
            int iVar9;
            if (iVar13 * 2 < 1) iVar9 = 0;
            else {
                iVar9 = rand();
                iVar9 = iVar9 % (iVar13 * 2);
            }
            iVar13 = *(int*)(pbVar18 + 7) + (iVar9 - iVar13);
            *(int*)(pbVar18 + 7) = iVar13;
            iVar13 = iVar13 / 5 + (uint32_t)*pbVar18;
            if (iVar13 < 1) cVar14 = '\0';
            else {
                iVar9 = rand();
                cVar14 = (char)(iVar9 % iVar13);
            }
            pbVar18[1] = (unsigned char)(cVar14 + 1);
            ushort uVar5;
            if ((pbVar18[-1] == 0) || (pbVar18[-1] == 3)) uVar5 = (ushort)*(uint32_t*)(pbVar18 + 7);
            else uVar5 = (ushort)(*(int*)(pbVar18 + 7) / 2);
            puVar17[-0x3b] = uVar5;
            if ((intptr_t)local_4 < 0x85b438) {
                uVar5 = (ushort)(((int)(*(unsigned char*)((char*)local_4 + 3) + 0x10)) >> 5) & 7;
            } else {
                uVar5 = (ushort)FUN_004131d0(local_8);
                *local_4 = (short)uVar5 * 0x20000000 + -0x10000000;
            }
            int iVar13b = *(int*)(pbVar18 + -0xd);
            *puVar17 = uVar5;
            unsigned char* pbVar1 = pbVar18 + -9;
            local_4 = local_4 + 4;
            local_8 = local_8 + 1;
            puVar17 = puVar17 + 0x4a;
            pbVar18 = pbVar18 + 0x20;
            // (&DAT_007b10a0)[*(int*)pbVar1 + ((&DAT_007252f0)[(short)uVar5] + iVar13b)*0x125 + (&DAT_00725350)[(short)uVar5]] = 0;
            {
                int base = *(int*)(DAT_007252f0 + (uint32_t)(ushort)uVar5 * sizeof(uint32_t)) + iVar13b;
                int add = *(int*)(DAT_00725350 + (uint32_t)(ushort)uVar5 * sizeof(uint32_t));
                int idx = *(int*)pbVar1 + base * 0x125 + add;
                DAT_007b10a0[idx] = 0;
            }
            if (0x85b977 < (intptr_t)local_4) break;
        }
    }
    FUN_00428a30(1);
    DAT_00861ff8 = 0;
    DAT_00861ffc = 0;
    _DAT_00862000 = 0;
    _DAT_00862004 = 0;
    _DAT_00862008 = 0;
    _DAT_0086200c = 0;
    _DAT_00862010 = 0;
    {
        uint32_t* puVar10 = (uint32_t*)DAT_00862020;
        int iVar9 = 32000;
        int iVar13 = 2;
        do {
            *(uint32_t*)(puVar10 + -4) = 0;
            int iVar11 = rand();
            *(int*)(puVar10 + -6) = (int)((28000 / (long long)iVar13) + (iVar11 % 100) + iVar9) * 2;
            int iVar11b = iVar13 + 1;
            puVar10[3] = (uint16_t)(0x32 / (long long)iVar13);
            puVar10[4] = (uint16_t)(6 / (long long)iVar13);
            puVar10[5] = (uint16_t)(0x1e / (long long)iVar11b);
            puVar10[6] = (uint16_t)(0xc / (long long)iVar11b);
            puVar10[2] = (uint16_t)iVar13 + -1;
            puVar10[7] = (uint16_t)(0x1e / (long long)(iVar13 + 2));
            switch (iVar13) {
            case 2: *puVar10 = 0xf; break;
            case 3: *puVar10 = 6; break;
            case 4: *puVar10 = 0x14; break;
            case 5: *puVar10 = 0xb; break;
            case 6: case 7: *puVar10 = 2; break;
            case 8: *puVar10 = 0x13; break;
            case 9: case 10: *puVar10 = 10;
            }
            iVar9 = iVar9 + -4000;
            puVar10 = puVar10 + 0xe;
            // bVar4 = iVar13 < 10;
            iVar13 = iVar11b;
        } while (iVar13 < 10);
    }
    {
        uint32_t* puVar16 = (uint32_t*)DAT_0085a270;
        for (int i = 0x148; i != 0; i = i - 1) { *puVar16 = 0; puVar16 = puVar16 + 1; }
    }
    {
        uint32_t* puVar16 = (uint32_t*)DAT_00869a70;
        for (int i = 0x36; i != 0; i = i - 1) { *puVar16 = 0; puVar16 = puVar16 + 1; }
    }
    FUN_00401000(0, 0);
    DAT_00869b18 = 10;
    _DAT_00862008 = (_DAT_0086200a << 16) | 10; // CONCAT22(_DAT_0086200a,10)
    for (int iVar13 = 1; iVar13 < 10; iVar13 = iVar13 + 1) {
        if (((int*)DAT_00861ff8)[iVar13 * 7] != 0) {
            short sVar6 = (short)FUN_00415290((int)*(short*)(DAT_00862004 + iVar13 * 0x1c));
            int iVar9 = (int)sVar6;
            int iVar11 = iVar9 * 0x45c;
            *(short*)(DAT_00862006 + iVar13 * 0x1c) = sVar6;
            *(short*)(DAT_00814326 + iVar11) = (short)iVar13;
            if (iVar13 == 1) *(ushort*)(DAT_00814326 + iVar11) = 0x1c;
            else if (iVar13 == 3) *(ushort*)(DAT_00814326 + iVar11) = 1;
            else if (iVar13 == 5) *(ushort*)(DAT_00814326 + iVar11) = 0x1e;
            int iVar12 = rand();
            int iVar3 = ((int*)DAT_00861ff8)[iVar13 * 7];
            ((short*)DAT_00814330)[iVar9 * 0x22e] = (short)iVar13;
            uint32_t uVar7 = ((uint32_t*)DAT_00814350)[iVar9 * 0x117];
            *(short*)(DAT_00814328 + iVar11) = (short)(iVar12 % 100) + (short)(iVar3 / 10);
            ((uint32_t*)DAT_00814350)[iVar9 * 0x117] = uVar7 | 0x4400u;
            if (iVar13 > -1) {
                int iVar9b = iVar13 + 1;
                do {
                    uint32_t uVar7b = (uint32_t)rand() & 0x80000007u;
                    if ((int32_t)uVar7b < 0) uVar7b = (uVar7b - 1u | 0xfffffff8u) + 1u;
                    *(ushort*)(DAT_00814324 + iVar11) = (ushort)(*(ushort*)(DAT_00814324 + iVar11) & ~(ushort)(1u << ((uint32_t)(uint8_t)uVar7b & 0x1fu)));
                    iVar9b = iVar9b - 1;
                } while (iVar9b != 0);
            }
        }
    }
}

// 0x00404780 — observed shape
int FUN_00404780(int param_1) {
    // Month length lookup: leap-year test on DAT_0085a140+DAT_007253b4
    // (div-by-4 mask 0x80000003, /100, /400 rule), Feb (index 1) +1 in leap,
    // returns 1 + ((param_1%6000)*len)/6000.
    uint32_t uVar1 = (uint32_t)DAT_0085a140 + (uint32_t)DAT_007253b4;
    uint32_t uVar2 = uVar1 & 0x80000003u;
    bool bVar5 = (uVar2 == 0);
    if ((int32_t)uVar2 < 0) {
        bVar5 = ((uVar2 - 1u | 0xfffffffc) == 0xffffffffu);
    }
    if (bVar5 && (((int32_t)uVar1 % 100 != 0 || ((int32_t)uVar1 % 400 == 0)))) {
        bVar5 = true;
    } else {
        bVar5 = false;
    }
    int iVar3 = (param_1 / 6000) % 0xc;
    int iVar4 = *(int*)(DAT_006fb6d8 + iVar3 * 4);
    if (bVar5 && (iVar3 == 1)) iVar4 = iVar4 + 1;
    return ((param_1 % 6000) * iVar4) / 6000 + 1;
}

// 0x00404810 — observed shape
int FUN_00404810(void) {
    // Smooth value: i=(_DAT_00869a76-4+DAT_0085a158)^2 >>2 -4*DAT_00869b27,
    // clamp [1,999], then (DAT_00869ab4+500)/(mask+0x14+DAT_00869ab0)/i,
    // clamp [0,4].
    int iVar1 = (int)_DAT_00869a76 + -4 + DAT_0085a158;
    iVar1 = iVar1 * iVar1;
    iVar1 = (int)((int64_t)(iVar1 + (iVar1 >> 0x1f & 3)) >> 2) + DAT_00869b27 * -4;
    // Ghidra form: ((i + (i>>31&3))>>2); reproduce directly:
    // (kept above as 64-bit shift equivalent for signed divide-by-4 rounding)
    if (iVar1 < 1) iVar1 = 1;
    else if (999 < iVar1) iVar1 = 999;
    int denom = (int)((-(uint32_t)((DAT_00869b34 & 0x80) != 0) & 0xffffffedu) + 0x14u + (uint32_t)DAT_00869ab0);
    iVar1 = ((DAT_00869ab4 + 500) / denom) / iVar1;
    if (iVar1 < 0) return 0;
    if (4 < iVar1) iVar1 = 4;
    return iVar1;
}

// 0x004048a0 — observed shape
int FUN_004048a0(void) {
    // i=(DAT_0085a140*2)/(2*(DAT_008ca92c==3)+6+DAT_00869b29), clamp [0,7],
    // i2=i/((DAT_008ca92c==3)+2), clamp [0,2], store i2 at DAT_00869a70 byte +3.
    int iVar1 = (DAT_0085a140 * 2) / (int)((uint32_t)(DAT_008ca92c == 3) * 2 + 6 + (uint32_t)DAT_00869b29);
    if (iVar1 < 0) iVar1 = 0;
    else if (7 < iVar1) iVar1 = 7;
    int iVar2 = iVar1 / (int)((uint32_t)(DAT_008ca92c == 3) + 2);
    if (iVar2 < 0) {
        DAT_00869a70[3] = 0;
        return iVar1;
    }
    if (2 < iVar2) iVar2 = 2;
    DAT_00869a70[3] = (unsigned char)iVar2;
    return iVar1;
}

// 0x00404910 — observed shape
int FUN_00404910(char param_1) {
    // Sums DAT_00723b1c[idx*0x44] over six occupied slots (DAT_008142f8,
    // DAT_00814754, DAT_00814bb0, DAT_0081500c, DAT_00815468, DAT_008158c4,
    // DAT_00815d20, DAT_0081617c), tracking last in iVar2, then subtracts
    // 00869ab8..00869acc sum and (if param_1==0) iVar2.
    int iVar1 = 0;
    int iVar2 = 0;
    if (*(int*)&DAT_008142f8 != -1) {
        iVar1 = *(int*)(DAT_00723b1c + (*(int*)&DAT_008142f8) * 0x44);
        iVar2 = *(int*)(DAT_00723b1c + (*(int*)&DAT_008142f8) * 0x44);
    }
    // helper macro for remaining slots:
    auto add_slot = [&](int slot) {
        if (slot != -1) {
            iVar1 = iVar1 + *(int*)(DAT_00723b1c + (uint32_t)slot * 0x44);
            iVar2 = *(int*)(DAT_00723b1c + (uint32_t)slot * 0x44);
        }
    };
    add_slot(*(int*)(DAT_00814754));
    add_slot(*(int*)(DAT_00814bb0));
    add_slot(*(int*)(DAT_0081500c));
    add_slot(*(int*)(DAT_00815468));
    add_slot(*(int*)(DAT_008158c4));
    add_slot(*(int*)(DAT_00815d20));
    add_slot(*(int*)(DAT_0081617c));
    iVar1 = iVar1 - (DAT_00869ab8 + DAT_00869abc + DAT_00869ac0 + DAT_00869ac4 + DAT_00869ac8 + DAT_00869acc);
    if (param_1 == '\0') iVar1 = iVar1 - iVar2;
    return iVar1;
}

// 0x00404a80 — observed shape
int FUN_00404a80(char param_1) {
    // Sums DAT_00723b14[idx*0x44] over stride-0x8b8 slots (four sub-slots per
    // record at +0x22e/+0x45c/+0x68a), +50% (iVar3/2) when byte &4 set;
    // if param_1==0 subtract last iVar3.
    int iVar2 = 0;
    short* psVar1 = (short*)&DAT_008142f8;
    int iVar3 = 0;
    do {
        if (*psVar1 != -1) {
            iVar3 = *(int*)(DAT_00723b14 + *psVar1 * 0x44);
            iVar2 = iVar2 + iVar3;
            if ((*(unsigned char*)((unsigned char*)psVar1 + 0x16 * sizeof(short)) & 4) != 0) iVar2 = iVar2 + iVar3 / 2;
        }
        if (psVar1[0x22e] != -1) {
            iVar3 = *(int*)(DAT_00723b14 + psVar1[0x22e] * 0x44);
            iVar2 = iVar2 + iVar3;
            if ((*(unsigned char*)((unsigned char*)psVar1 + 0x244 * sizeof(short)) & 4) != 0) iVar2 = iVar2 + iVar3 / 2;
        }
        if (psVar1[0x45c] != -1) {
            iVar3 = *(int*)(DAT_00723b14 + psVar1[0x45c] * 0x44);
            iVar2 = iVar2 + iVar3;
            if ((*(unsigned char*)((unsigned char*)psVar1 + 0x472 * sizeof(short)) & 4) != 0) iVar2 = iVar2 + iVar3 / 2;
        }
        if (psVar1[0x68a] != -1) {
            iVar3 = *(int*)(DAT_00723b14 + psVar1[0x68a] * 0x44);
            iVar2 = iVar2 + iVar3;
            if ((*(unsigned char*)((unsigned char*)psVar1 + 0x6a0 * sizeof(short)) & 4) != 0) iVar2 = iVar2 + iVar3 / 2;
        }
        psVar1 = psVar1 + 0x8b8;
    } while ((intptr_t)psVar1 < 0x8165d8);
    if (param_1 == '\0') iVar2 = iVar2 - iVar3;
    return iVar2;
}

// 0x00404b70 — observed shape
uint32_t FUN_00404b70(int in_EAX) {
    // Finds first empty DAT_008142f8 slot (== -1); copies 0x117-dword template
    // from in_EAX-indexed row, sets 0x408 holder, copies name from PTR_DAT_007267d0
    // into DAT_008db620 row, stores DAT_007267c8/cc, returns 1; else FUN_004888e0(5,...) 0.
    int iVar9 = 0;
    short* psVar6 = (short*)&DAT_008142f8;
    do {
        if (*psVar6 == -1) {
            int iVar8 = iVar9 * 0x45c;
            DAT_00869ad0 = DAT_00869ad0 + 1;
            uint32_t* puVar10 = (uint32_t*)((unsigned char*)&DAT_008142f8 + (uint32_t)in_EAX * 0x22e * sizeof(short));
            uint32_t* puVar11 = (uint32_t*)((unsigned char*)&DAT_008142f8 + (uint32_t)iVar9 * 0x22e * sizeof(short));
            for (int iVar7 = 0x117; iVar7 != 0; iVar7 = iVar7 - 1) {
                *puVar11 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar11 = puVar11 + 1;
            }
            ((uint32_t*)DAT_00814350)[iVar9 * 0x117] = 0x408;
            *(ushort*)(DAT_008142fa + iVar8) = 0;
            ((uint32_t*)DAT_0081430c)[iVar9 * 0x117] = (uint32_t)DAT_0081430c;
            *(ushort*)(DAT_0081435a + iVar8) = 0;
            *(ushort*)(DAT_00814358 + iVar8) = 0;
            ((uint32_t*)DAT_00814322)[iVar9 * 0x22e] = 3;
            FUN_00413080();
            char* _Src = PTR_DAT_007267d0;
            int* piVar1 = (int*)(DAT_008db620 + iVar9 * 3 * sizeof(uint32_t));
            if (PTR_DAT_007267d0 != (char*)0x0) {
                char* pcVar5 = PTR_DAT_007267d0;
                char cVar2;
                do { cVar2 = *pcVar5; pcVar5 = pcVar5 + 1; } while (cVar2 != '\0');
                size_t _Size = (size_t)((intptr_t)pcVar5 - (intptr_t)(PTR_DAT_007267d0 + 1));
                if (((int)_Size > -1)) {
                    unsigned char* puVar3 = (unsigned char*)(uintptr_t)*piVar1;
                    if (PTR_DAT_007267d0 != (char*)puVar3) {
                        if (_Size == 0) {
                            if (*(int*)(puVar3 + -4) != 0) {
                                *puVar3 = 0;
                                *(uint32_t*)(*piVar1 + -4) = 0;
                            }
                        } else {
                            FUN_004f3350();
                            memmove((void*)(uintptr_t)*piVar1, _Src, _Size);
                            *(unsigned char*)(*piVar1 + *(int*)(*piVar1 + -4)) = 0;
                        }
                    }
                }
            }
            uint32_t uVar4 = (uint32_t)DAT_007267c8;
            ((uint32_t*)DAT_008db61c)[iVar9 * 3] = (uint32_t)DAT_007267cc;
            ((uint32_t*)DAT_008db618)[iVar9 * 3] = uVar4;
            return 1;
        }
        psVar6 = psVar6 + 0x22e;
        iVar9 = iVar9 + 1;
    } while ((intptr_t)psVar6 < 0x8165d8);
    FUN_004888e0(5, 0xffffffff, 0xffffffff, 0xbf800000u);
    return 0;
}

// 0x00404ca0 — observed shape
void FUN_00404ca0(int in_EAX) {
    // Swaps 00814304/08/0c with 00814760/64/68 when in_EAX==0 && 00869ad0>1;
    // if in_EAX<7 shifts the 008142f8/in_EAX*0x22e slot rows upward (0x117 copy),
    // frees DAT_008c99d8/in_EAX, copies next name from DAT_008db620 row,
    // bumps DAT_008c97d8/in_EAX, decrements 00869ad0, sets DAT_0081617c=0xffff.
    uint32_t uVar5 = (uint32_t)DAT_0081430c;
    uint32_t uVar4 = (uint32_t)DAT_00814308;
    uint32_t uVar3 = (uint32_t)DAT_00814304;
    if ((in_EAX == 0) && (1 < DAT_00869ad0)) {
        DAT_00814304 = (int32_t)DAT_00814760;
        DAT_00814760 = (int32_t)uVar3;
        DAT_00814308 = (int32_t)DAT_00814764;
        DAT_00814764 = (int32_t)uVar4;
        DAT_0081430c = (int32_t)DAT_00814768;
        DAT_00814768 = (int32_t)uVar5;
    }
    if (in_EAX < 7) {
        short* local_8 = (short*)(DAT_008c97d8 + in_EAX * sizeof(short));
        char* local_c = (char*)(DAT_008c99d8 + in_EAX * sizeof(void*));
        int* piVar8 = (int*)(DAT_008db620 + (uint32_t)in_EAX * 3 * sizeof(uint32_t));
        uint32_t* puVar10 = (uint32_t*)((unsigned char*)&DAT_008142f8 + (uint32_t)in_EAX * 0x22e * sizeof(short));
        while (true) {
            uint32_t* puVar9 = puVar10 + 0x117;
            uint32_t* puVar11 = puVar10;
            for (int iVar7 = 0x117; iVar7 != 0; iVar7 = iVar7 - 1) {
                *puVar11 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar11 = puVar11 + 1;
            }
            void* pvVar2 = *(void**)local_c;
            if (pvVar2 != (void*)0x0) {
                FUN_004e1470();
                operator_delete__(pvVar2);
                *(void**)local_c = 0;
            }
            char* _Src = (char*)(uintptr_t)piVar8[3];
            *local_8 = (short)(*local_8 + 1);
            if (_Src != (char*)0x0) {
                char* pcVar6 = _Src;
                char cVar1;
                do { cVar1 = *pcVar6; pcVar6 = pcVar6 + 1; } while (cVar1 != '\0');
                size_t _Size = (size_t)((intptr_t)pcVar6 - (intptr_t)(_Src + 1));
                if ((int)_Size > -1) {
                    char* pcVar6b = (char*)(uintptr_t)*piVar8;
                    if (_Src != pcVar6b) {
                        if (_Size == 0) {
                            if (*(int*)(pcVar6b + -4) != 0) {
                                *pcVar6b = '\0';
                                *(uint32_t*)(*piVar8 + -4) = 0;
                            }
                        } else {
                            FUN_004f3350();
                            memmove((void*)(uintptr_t)*piVar8, _Src, _Size);
                            *(unsigned char*)(*piVar8 + *(int*)(*piVar8 + -4)) = 0;
                        }
                    }
                }
            }
            piVar8[-2] = piVar8[1];
            piVar8[-1] = piVar8[2];
            local_c = local_c + 1;
            local_8 = local_8 + 1;
            piVar8 = piVar8 + 3;
            if ((intptr_t)piVar8 > 0x8db673) break;
            puVar10 = puVar10 + 0x117;
        }
    }
    void* pvVar2 = DAT_008c99e4;
    if (DAT_008c99e4 != (void*)0x0) {
        FUN_004e1470();
        operator_delete__(pvVar2);
        DAT_008c99e4 = (void*)0x0;
    }
    _DAT_008c97de = _DAT_008c97de + 1;
    DAT_00869ad0 = DAT_00869ad0 + -1;
    DAT_0081617c = 0xffff;
}
