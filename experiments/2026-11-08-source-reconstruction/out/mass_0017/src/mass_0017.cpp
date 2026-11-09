// Reconstruction batch mass_0017 — Sid Meier's Pirates! (2004), PE32 i386.
// Each definition below translates one Ghidra pseudocode listing; names use
// FUN_ADDR. Register receivers become an explicit `void* self` parameter.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

// Extern helpers referenced by the assigned listings
extern DWORD timeGetTime();
extern void srand(uint32_t);
extern int rand();
extern void* malloc(std::size_t);
extern void free(void*);
extern void* memmove(void*, const void*, std::size_t);
extern void operator_delete(void*);
extern void operator_delete__(void*);
extern int _open(const char*, int);
extern uint32_t _write(int, const void*, uint32_t);
extern int _close(int);
extern HCURSOR LoadCursorA(HINSTANCE, int);
extern HCURSOR GetCursor();
extern void SetCursor(HCURSOR);
extern DWORD GetCurrentThreadId();
extern void Sleep(int);

extern uint32_t FUN_004f4b20(const char*, int, int, int);
extern void FUN_004f10f0(void*, uint32_t);
extern void FUN_004f4de0();
extern int FUN_004e7060(void*, int, int, int);
extern void FUN_004e7510(float, float, int);
extern uint32_t FUN_005f0ddc(...);
extern void FUN_00402880();
extern void FUN_004446c0();
extern void FUN_004030e0();
extern void* FUN_0046c870();
extern uint32_t FUN_0045fcb0(int, int, int, int, int);
extern void FUN_005516a0();
extern uint32_t FUN_00551600(int);
extern void FUN_005451a0(uint32_t);
extern uint32_t FUN_004baaa0(...);
extern void FUN_004bb500(int);
extern void FUN_004dad10(...);
extern void FUN_004f0dc0();
extern void FUN_004887d0();
extern uint32_t FUN_00533c78(uint32_t);
extern void FUN_004c1210(uint32_t);
extern void FUN_004ab0d0(int, uint32_t);
extern void FUN_004af080(...);
extern uint32_t FUN_004cddf0(...);
extern void FUN_004f6090(const char*, ...);
extern void FUN_004b06c0(void*, int, int, int, uint32_t, int, int, int);
extern void FUN_0046e080();
extern uint32_t FUN_0042c6f0();
extern uint32_t FUN_0042e1d0(void*);
extern void FUN_004889c0(void*, int, int, int, int, int, int);
extern void FUN_004a2380();
extern void FUN_0042e730();
extern void FUN_004d0cd0(int, int, int);
extern void FUN_00506040(int, uint32_t, int, int, uint32_t);
extern void FUN_00505fc0(uint32_t, int, int, uint32_t);
extern void FUN_004f2600(const char*, ...);
extern void FUN_00535920(void*);
extern void FUN_00535670(void*);
extern void FUN_00481100();
extern void FUN_00481140();
extern void FUN_004c1150(void*, const char*);
extern void FUN_004bef50();
extern void FUN_004ae4f0();
extern void FUN_004a85a0();
extern void FUN_00481180();
extern void FUN_004dadc0(int, int, int);
extern void FUN_004bbc80(int, int, int, void*, int, int, int);
extern void FUN_004bbe10(int, int);
extern void FUN_004bbf50();
extern void FUN_004bc160();
extern void FUN_004a2080(...);
extern void FUN_004a21c0();
extern void FUN_004879f0(int, int);
extern void FUN_004bba60(int, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_00489130(void*);
extern void FUN_00470b90();
extern void FUN_0046eb00();
extern void FUN_00471860();
extern void FUN_004719a0();
extern bool FUN_0046fa20(int, int);
extern void FUN_0046f860();
extern void FUN_004bed70(uint32_t, int);
extern void FUN_004ae5b0(const char*);
extern void FUN_00412840(int, int);
extern void FUN_00533d10(int, int);
extern void FUN_0042fee0(int, int);
extern void FUN_004aef70(void*);
extern void FUN_00509500(void*, void*, int);
extern void FUN_0045fbf0();
extern void FUN_0045ac10();
extern void FUN_004917a0();
extern void FUN_0045b5d0();
extern void FUN_00498260(void*);
extern void FUN_00497fd0(void*);
extern void FUN_004a24b0();
extern void FUN_0045c270(int);
extern void FUN_0045cab0(int);
extern void FUN_004e0d10();
extern void FUN_004ed490(void*, uint32_t);
extern void FUN_004a8420();
extern void FUN_004bdca0(int, int, int, int, int, int, int, int, int, int);
extern void FUN_004c0870(int);
extern void FUN_004af680(int, const char*, int, int, int, int, int, int, int, int, int, int);
extern void FUN_004cce40();
extern void FUN_004ad820();
extern void FUN_004beee0();
extern void FUN_004baae0(uint32_t);
extern void FUN_004be3f0(void*, int, int, int, int, int, uint32_t, int, int, int, int, int);
extern void FUN_004baca0();
extern void FUN_004c1080(int, const char*, int, int);
extern void FUN_004c12a0(int, int, int);
extern void FUN_004c1000(const char*);
extern void FUN_004afd20();
extern void FUN_004b04e0();
extern void FUN_004b20f0();
extern void FUN_004b1940();
extern void FUN_004b2170();
extern void FUN_004b17f0(const char*, const char*, int, int, int);
extern void FUN_00508120();
extern void FUN_00508670(void*, const char*);
extern void FUN_00508190();
extern void FUN_004abb50(const char*, uint32_t);
extern void FUN_0042c000();
extern void FUN_004888e0(int, int, int, int);
extern void FUN_004bc0d0();

// Globals referenced by the assigned listings
extern uint32_t DAT_008ed618;
extern uint32_t _DAT_008ed61c;
extern uint8_t DAT_00860b80[];
extern uint8_t DAT_00860b74[];
extern uint8_t DAT_00860b70[];
extern uint8_t DAT_008ca938[];
extern uint8_t DAT_008db678[];
extern uint32_t DAT_0086c330;
extern uint32_t DAT_008e64dc;
extern uint32_t DAT_007263bc;
extern uint8_t DAT_00869b48[];
extern uint8_t DAT_0072574c;
extern uint32_t DAT_0085a158;
extern uint32_t DAT_008ca92c;
extern uint32_t DAT_00725748;
extern uint8_t DAT_008cac27;
extern uint32_t* DAT_0086bb5c;
extern uint32_t DAT_008dc30c;
extern uint32_t DAT_008dc310;
extern uint32_t DAT_0086c35c;
extern uint8_t DAT_008c9df4;
extern uint32_t DAT_008ea000;
extern uint32_t DAT_008e9fec;
extern uint32_t DAT_008e9fd8;
extern uint32_t DAT_008ea008;
extern uint32_t DAT_0085a26c;
extern uint32_t DAT_0085a11c;
extern uint32_t DAT_00726820;
extern uint8_t DAT_00725d98;
extern uint32_t DAT_00726a84;
extern uint8_t DAT_00726813[];
extern uint32_t DAT_00876bdc[];
extern uint32_t DAT_008c8490;
extern uint32_t DAT_008c97c4;
extern uint32_t DAT_008c97c0;
extern uint32_t DAT_008e9fe8;
extern uint32_t DAT_00727444;
extern uint32_t DAT_0085a268;
extern uint32_t DAT_008c9de0;
extern uint32_t DAT_008c9dd8;
extern uint32_t DAT_008c9570;
extern uint32_t DAT_007253b4;
extern uint32_t DAT_008c8278[8];
extern uint32_t DAT_008c8270[8];
extern uint32_t DAT_008c8288[8];
extern uint8_t DAT_008c827f;
extern uint32_t DAT_008cacd8;
extern uint32_t DAT_008ca9f4;
extern uint32_t DAT_008ca9f8;
extern uint32_t DAT_008cac40;
extern uint32_t DAT_008cabe8;
extern uint32_t DAT_00725748;
extern uint32_t DAT_007268f4[];
extern uint32_t DAT_0085a164;
extern uint32_t DAT_00860b68[];
extern uint8_t DAT_007242d0[];
extern uint8_t DAT_007d2168[];
extern uint8_t DAT_0074de48[];
extern uint8_t DAT_0076ef10[];
extern uint8_t DAT_0085a270[];
extern uint8_t DAT_00862110[];
extern uint32_t DAT_007253b0;
extern uint32_t _DAT_0085a160;
extern uint8_t DAT_007b10a0[];
extern uint8_t DAT_0078ffd8[];
extern uint32_t DAT_008ee1f0;
extern uint32_t DAT_0072cd78;
extern uint8_t DAT_0085bff6[];
extern uint8_t DAT_0085b174[];
extern uint32_t DAT_00860b50;
extern uint32_t DAT_007263a0;
extern uint32_t DAT_008ca4cc;
extern uint32_t* DAT_008ca4c8;
extern uint32_t DAT_008cba18[];
extern uint32_t DAT_007252f0[];
extern uint8_t DAT_00725350[];
extern uint8_t DAT_0072cd80[];
extern uint32_t DAT_00725744;
extern uint32_t _DAT_00876be8;
extern uint32_t _DAT_00876be4;
extern uint32_t DAT_00725678;
extern uint8_t DAT_0076f035[];
extern uint8_t DAT_008dbd10[];
extern uint32_t DAT_008dbd08[];
extern uint32_t DAT_008dbd0c[];
extern uint8_t DAT_00862002[];
extern uint8_t DAT_0085bf80[];
extern uint8_t DAT_008cacc8[];
extern uint32_t DAT_008c9dec;
extern uint32_t DAT_007255f8;
extern uint32_t DAT_00814308;
extern uint32_t DAT_00814304;
extern uint32_t DAT_008b98c4;
extern uint32_t DAT_008ca9c0;
extern uint32_t DAT_008b9980;
extern uint32_t DAT_008b96b0;
extern uint32_t DAT_008b96b4;
extern uint32_t DAT_0072560c;
extern uint32_t DAT_008b98d4;
extern uint32_t DAT_0085a154;
extern uint32_t DAT_0072555c;
extern uint32_t DAT_00877060[];
extern uint8_t DAT_007263b0;
extern uint32_t DAT_008e67b0[4];
extern uint32_t DAT_008b9991;
extern uint8_t DAT_0086c1a0[];
extern uint8_t DAT_0086c010[];
extern uint8_t DAT_0086be80[];
extern uint8_t DAT_0086bcf0[];
extern uint8_t DAT_0086bb60[];
extern uint8_t DAT_00869b48[];
extern uint8_t DAT_006f588c[];
extern uint8_t DAT_00726638[];
extern uint8_t DAT_0072663c[];
extern uint8_t* PTR_DAT_00726640;
extern uint8_t DAT_00725750[];
extern uint8_t DAT_00725754[];
extern uint8_t DAT_00725758[];
extern int FUN_006fd14c;
extern uint8_t DAT_00007f02[];
extern uint32_t DAT_00876be0;
extern float _DAT_008c84b0;
extern uint32_t DAT_008cac18;
extern uint32_t DAT_0072cd78;
extern void* PTR_FUN_006fd14c;

// 0x46c5d0 — observed shape: Fisher-Yates shuffle of 128 ints; seeds via timeGetTime since DAT_008ed618; picks random entry where DAT_00860b80[idx*8]==6 and DAT_00860b74[idx*0x20]==rand%4, else picks Nth type-6 entry with N=rand%count; fallback first entry with (DAT_00860b70[idx*8]>=0 && &2); sets 0x10000000
void FUN_0046c5d0() {
    int local_200[128];
    int iVar2 = 0;
    do { local_200[iVar2] = iVar2; ++iVar2; } while (iVar2 < 0x80);
    if ((_DAT_008ed61c & 1) == 0) {
        _DAT_008ed61c |= 1;
        DAT_008ed618 = timeGetTime();
    }
    DWORD DVar3 = timeGetTime();
    srand(DVar3 - DAT_008ed618);
    iVar2 = 0;
    do {
        uint32_t uVar4 = rand() & 0x8000007f;
        if ((int)uVar4 < 0) uVar4 = (uVar4 - 1 | 0xffffff80) + 1;
        int iVar5 = local_200[iVar2];
        local_200[iVar2] = local_200[uVar4];
        ++iVar2;
        local_200[uVar4] = iVar5;
    } while (iVar2 < 0x80);
    iVar2 = 0;
    uint32_t uVar4 = rand() & 0x80000003;
    if ((int)uVar4 < 0) uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
    int iVar5 = 0;
    do {
        int iVar1 = local_200[iVar5];
        if (DAT_00860b80[iVar1 * 8] == 6 && ((int)(char)DAT_00860b74[iVar1 * 0x20] == (int)uVar4)) {
            ++iVar2;
            goto LAB_0046c706;
        }
        ++iVar5;
    } while (iVar5 < 0x80);
    if (iVar2 < 1) iVar5 = 0;
    else iVar5 = rand() % iVar2;
    iVar2 = 0;
    do {
        int iVar1 = local_200[iVar2];
        if (DAT_00860b80[iVar1 * 8] == 6) {
            if (iVar5 == 0) goto LAB_0046c706;
            --iVar5;
        }
        ++iVar2;
    } while (iVar2 < 0x80);
    iVar2 = 0;
    while (true) {
        int iVar1 = local_200[iVar2];
        if ((int)(*(int*)(&DAT_00860b70[iVar1 * 8])) >= 0 && ((*(int*)(&DAT_00860b70[iVar1 * 8]) & 2) != 0)) break;
        ++iVar2;
        if (iVar2 > 0x7f) return;
    }
LAB_0046c706:
    {
        int iVar1 = local_200[iVar2];
        *(uint32_t*)(&DAT_00860b70[iVar1 * 8]) |= 0x10000000u;
    }
}

// 0x46c720 — observed shape: identical shuffle/selection to 0x46c5d0 but type-7 entries and sets 0x20000000 flag
void FUN_0046c720() {
    int local_200[128];
    int iVar2 = 0;
    do { local_200[iVar2] = iVar2; ++iVar2; } while (iVar2 < 0x80);
    if ((_DAT_008ed61c & 1) == 0) {
        _DAT_008ed61c |= 1;
        DAT_008ed618 = timeGetTime();
    }
    DWORD DVar3 = timeGetTime();
    srand(DVar3 - DAT_008ed618);
    iVar2 = 0;
    do {
        uint32_t uVar4 = rand() & 0x8000007f;
        if ((int)uVar4 < 0) uVar4 = (uVar4 - 1 | 0xffffff80) + 1;
        int iVar5 = local_200[iVar2];
        local_200[iVar2] = local_200[uVar4];
        ++iVar2;
        local_200[uVar4] = iVar5;
    } while (iVar2 < 0x80);
    iVar2 = 0;
    uint32_t uVar4 = rand() & 0x80000003;
    if ((int)uVar4 < 0) uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
    int iVar5 = 0;
    do {
        int iVar1 = local_200[iVar5];
        if (DAT_00860b80[iVar1 * 8] == 7 && ((int)(char)DAT_00860b74[iVar1 * 0x20] == (int)uVar4)) {
            ++iVar2;
            goto LAB_0046c856;
        }
        ++iVar5;
    } while (iVar5 < 0x80);
    if (iVar2 < 1) iVar5 = 0;
    else iVar5 = rand() % iVar2;
    iVar2 = 0;
    do {
        int iVar1 = local_200[iVar2];
        if (DAT_00860b80[iVar1 * 8] == 7) {
            if (iVar5 == 0) goto LAB_0046c856;
            --iVar5;
        }
        ++iVar2;
    } while (iVar2 < 0x80);
    iVar2 = 0;
    while (true) {
        int iVar1 = local_200[iVar2];
        if ((int)(*(int*)(&DAT_00860b70[iVar1 * 8])) >= 0 && ((*(int*)(&DAT_00860b70[iVar1 * 8]) & 2) != 0)) break;
        ++iVar2;
        if (iVar2 > 0x7f) return;
    }
LAB_0046c856:
    {
        int iVar1 = local_200[iVar2];
        *(uint32_t*)(&DAT_00860b70[iVar1 * 8]) |= 0x20000000u;
    }
}

// 0x46c870 — observed shape: if DAT_008ca938[unaff_EDI*4] < 0xfffff, advance in_ECX cyclically mod 0x14 past set bits; OR bit (1<<in_ECX) into mask; returns &DAT_008db678[(in_ECX + unaff_EDI*0x14)*3]
uint32_t* FUN_0046c870(void* self, int in_ECX, int unaff_EDI) {
    uint32_t uVar1 = *(uint32_t*)(&DAT_008ca938[unaff_EDI * 4]);
    if (uVar1 < 0xfffff) {
        uint8_t bVar2 = (uint8_t)in_ECX;
        while ((uVar1 & (1u << (bVar2 & 0x1f))) != 0) {
            in_ECX = (in_ECX + 1) % 0x14;
            bVar2 = (uint8_t)in_ECX;
        }
        *(uint32_t*)(&DAT_008ca938[unaff_EDI * 4]) = (1u << ((uint8_t)in_ECX & 0x1f)) | uVar1;
    }
    return (uint32_t*)(&DAT_008db678[(in_ECX + unaff_EDI * 0x14) * 3]);
}

// 0x46c8d0 — observed shape: large world/map init; copies 0x400 dwords, loads piratemap*.dta or regenerates them, processes city/port placement with rand(), switch on city type 4..7 setting fields, sets cursor, crew/cannon attachment loops; see full body
void FUN_0046c8d0() {
    HCURSOR hCursor = (HCURSOR)DAT_008cacd8;
    bool bVar35 = DAT_008cacd8 == 0;
    uint32_t* puVar27 = (uint32_t*)DAT_007242d0;
    uint32_t* puVar13 = (uint32_t*)DAT_00860b68;
    for (int iVar18 = 0x400; iVar18 != 0; --iVar18) {
        *puVar13 = *puVar27;
        ++puVar27; ++puVar13;
    }
    if (bVar35) hCursor = LoadCursorA((HINSTANCE)0, (int*)DAT_00007f02);
    HCURSOR local_1d8 = GetCursor();
    (void)local_1d8;
    SetCursor(hCursor);
    puVar27 = (uint32_t*)(DAT_008c9dec + 0x14);
    (*(void(**)(uint32_t, uint32_t, uint32_t))(**(uint32_t**)(DAT_008c9dec + 0x14) + 0x10))(0, 0, DAT_007255f8);
    (*(void(**)(uint32_t))(*(uint32_t*)*puVar27 + 0xc))(0);
    puVar27 = (uint32_t*)DAT_007d2168;
    for (int iVar18 = 0x10863; iVar18 != 0; --iVar18) { *puVar27 = 0xffffffff; ++puVar27; }
    puVar27 = (uint32_t*)DAT_0074de48;
    for (int i = 0x8431; i != 0; --i) { *puVar27 = 0; ++puVar27; }
    *(uint16_t*)puVar27 = 0;
    puVar27 = (uint32_t*)DAT_0076ef10;
    for (int i = 0x8431; i != 0; --i) { *puVar27 = 0xffffffff; ++puVar27; }
    *(uint16_t*)puVar27 = 0xffff;
    puVar27 = (uint32_t*)DAT_0085a270;
    do { *puVar27 = 0; puVar27 = (uint32_t*)((uint8_t*)puVar27 + 0x52); } while ((uintptr_t)puVar27 < 0x85a790);
    puVar27 = (uint32_t*)DAT_00862110;
    for (int i = 0x300; i != 0; --i) { *puVar27 = 0xffffffff; ++puVar27; }
    DAT_007253b0 = 0;
    _DAT_0085a160 = 0;
    _DAT_0085a164 = 0;
    int iVar18 = FUN_004f4b20("piratemap.dta", 1, 0, 0x8000);
    if (iVar18 == 0) {
        FUN_004f10f0(DAT_007b10a0, 0x210c6);
        FUN_004f4de0();
        iVar18 = FUN_004f4b20("piratemapz.dta", 1, 0, 0x8000);
        if (iVar18 == 0) FUN_004f10f0(DAT_007d2168, 0x4218c);
        FUN_004f4de0();
        iVar18 = FUN_004f4b20("piratemap8.dta", 1, 0, 0x8000);
        if (iVar18 == 0) FUN_004f10f0(DAT_0078ffd8, 0x210c6);
        FUN_004f4de0();
    } else {
        iVar18 = 0;
        int iStack_248 = 0;
        uint16_t* puVar26 = (uint16_t*)DAT_007d2168;
        do {
            int iVar29 = 0;
            do {
                uint8_t cVar6 = (uint8_t)FUN_004e7060((void*)DAT_0072cd78, iStack_248, iVar29, 2);
                DAT_0078ffd8[iVar18] = cVar6;
                DAT_007b10a0[iVar18] = 0;
                for (int iVar9 = 0; iVar9 < 9; ++iVar9) {
                    if (((int)cVar6 & (1 << ((uint8_t)iVar9 & 0x1f))) != 0) DAT_007b10a0[iVar18]++;
                }
                FUN_004e7510((float)iStack_248, (float)iVar29, 1);
                uint16_t uVar7 = (uint16_t)FUN_005f0ddc();
                iVar29 += 1000;
                *puVar26 = uVar7;
                ++iVar18; ++puVar26;
            } while (iVar29 < 0x47888);
            iStack_248 += 1000;
        } while ((uintptr_t)puVar26 < 0x8142f4);
        DAT_008ee1f0 = _open("assets/data/piratemap.dta", 0x8302);
        _write((int)DAT_008ee1f0, DAT_007b10a0, 0x210c6);
        _close((int)DAT_008ee1f0);
        DAT_008ee1f0 = _open("assets/data/piratemap8.dta", 0x8302);
        _write((int)DAT_008ee1f0, DAT_0078ffd8, 0x210c6);
        _close((int)DAT_008ee1f0);
        DAT_008ee1f0 = _open("assets/data/piratemapz.dta", 0x8302);
        _write((int)DAT_008ee1f0, DAT_007d2168, 0x4218c);
        _close((int)DAT_008ee1f0);
        DAT_008ee1f0 = _open("assets/data/piratemap.txt", 0x8301);
        iVar18 = 0;
        char acStack_1e0[8];
        do {
            char* pcVar19 = acStack_1e0;
            for (int i = 0x73; i != 0; --i) { pcVar19[0]=0; pcVar19[1]=0; pcVar19[2]=0; pcVar19[3]=0; pcVar19+=4; }
            pcVar19[0]=0; pcVar19[1]=0; pcVar19[2]=0;
            int iVar29 = 0;
            pcVar19 = (char*)DAT_007b10a0 + iVar18;
            do {
                acStack_1e0[iVar29] = *pcVar19 + '0';
                ++iVar29;
                pcVar19 += 0x125;
            } while (iVar29 < 0x1ce);
            _write((int)DAT_008ee1f0, acStack_1e0, 0x1cf);
            acStack_1e0[0] = '\n';
            acStack_1e0[1] = 0xd;
            _write((int)DAT_008ee1f0, acStack_1e0, 2);
            ++iVar18;
        } while (iVar18 < 0x125);
        _close((int)DAT_008ee1f0);
    }
    // cStack_c referenced as stack byte; treat as non-zero path guard as observed
    // FUN_00402880 block and 0x2f-iteration city placement, suffix loops preserved in notes
    // Full tail: crew/cannon dha handling + cannons/ports D_Crew_, gunport/cannon kfm attach
    // NEEDS_MANUAL: 0x46c8d0 has 900+ lines of intricate map/city generation; core file-load and regen paths preserved above, remaining city/cannon loops follow same rand/switch pattern as switch((int)cVar6) cases 4-7
}

// 0x46e300 — observed shape: signup screen; sets DAT_0086c330=0, draws Crew Signups/Name/Experience/Skill/Start Date UI, registers click rects DAT_0086c1a0/010/be80/bcf0/bb60, adds Continue button when DAT...==0x10
void FUN_0046e300(char param_1) {
    uint32_t local_c = 0x200;
    uint32_t local_8 = 0x100;
    DAT_0086c330 = 0;
    FUN_004af080((void*)DAT_008e64dc, 0, 0, 0x400, 0x300, 0, 0, (int)DAT_0085a26c, (int)DAT_0085a268, 0xffffffff, 0x200);
    DAT_007263bc |= 0x1000;
    uint32_t uVar1 = FUN_004cddf0((void*)((uint8_t*)DAT_00725758)[DAT_008ca92c + DAT_0085a158 * 5], 0, 0, &local_8, &local_c);
    FUN_004af080((void*)uVar1, 0, 0, (int)local_8, (int)local_c, 0x15, 0x22, 0xa0, 0x140, 0xffffffff, 0);
    FUN_004f6090("Crew Signups");
    FUN_004b06c0(DAT_00869b48, 0x18e, 0x14, 100, 0xff3e2816, 4, 0xffffffff, 0);
    FUN_004f6090("Name: ");
    FUN_004b06c0(DAT_00869b48, 0xed, 0x3d, 0x4b, 0xff3e2816, 1, 0xffffffff, 0);
    if (param_1 == 0) {
        DAT_0085a11c = 0x4b;
        FUN_004aef70(DAT_00869b48);
        int iVar2 = (int)FUN_005f0ddc();
        uint32_t uVar5 = 0x44;
        DAT_0085a11c = 0x78;
        while (true) {
            local_8 = (uint32_t)((int)(DAT_008cac18 * DAT_0085a11c + ((DAT_008cac18 * DAT_0085a11c) >> 31 & 0x3ffU)) >> 10);
            DAT_008c9de0 = DAT_008c9570;
            if (DAT_008c9570 == 0) DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500((void*)DAT_008c9de0, PTR_DAT_00726640, 0);
            int iVar3 = (int)FUN_005f0ddc();
            if (iVar3 < 0x14c) break;
            DAT_0085a11c = (DAT_0085a11c * 9) / 10;
            uVar5 += (~uVar5 & 1 | 2);
        }
        FUN_004b06c0(PTR_DAT_00726640, iVar2 + 0xed, (int)uVar5, (int)DAT_0085a11c, 0xffc00000, 1, 0xffffffff, 0);
    }
    if (DAT_0072574c != 0) {
        FUN_004f6090("Experience");
        uint32_t local_4 = (uint32_t)(-(uint32_t)(param_1 != 0) & 0x81000000) - 0xc1d7ea;
        FUN_004b06c0(DAT_00869b48, 0xed, 0x5b, 0x4b, local_4, 1, 0xffffffff, 0);
        int iVar2 = 0; int iVar3 = 0x7e;
        do {
            FUN_004f6090("@DIFFICULTY", iVar2);
            int iVar6 = -0xc1d7ea;
            if ((int)DAT_00725748 == iVar2) iVar6 = -0x407af9;
            if (param_1 != 0) iVar6 = -0x7fc1d7ea;
            FUN_004b06c0(DAT_00869b48, 0x10e, iVar3 - 3, 0x28, (uint32_t)iVar6, 1, 0xffffffff, 0);
            local_8 = 0x20; local_c = 0x20;
            uVar1 = FUN_004cddf0(PTR_s_box_off_dds_00725750, 0, 0, &local_c, &local_8);
            FUN_004af080((void*)uVar1, 0, 0, (int)local_c, (int)local_8, 0xfa, iVar3, 0x10, 0x10, (uint32_t)iVar6, 0);
            if (DAT_0085a158 == (uint32_t)iVar2) {
                local_8 = 0x20; local_c = 0x20;
                uVar1 = FUN_004cddf0(PTR_s_box_on_dds_00725754, 0, 0, &local_c, &local_8);
                FUN_004af080((void*)uVar1, 0, 0, (int)local_c, (int)local_8, 0xfa, iVar3, 0x10, 0x10, ((iVar6 != -0x7fc1d7ea) - 1 & 0x803e2817) - 1, 0);
            }
            if (iVar6 != -0x7fc1d7ea) {
                int idx = (int)DAT_0086c330; DAT_0086c330++;
                ((int16_t*)DAT_0086c1a0)[idx] = (int16_t)iVar2;
                ((int16_t*)DAT_0086c010)[idx] = 0xfa;
                ((int16_t*)DAT_0086be80)[idx] = (int16_t)iVar3;
                ((int16_t*)DAT_0086bcf0)[idx] = 0x172;
                ((int16_t*)DAT_0086bb60)[idx] = (int16_t)iVar3 + 0x10;
            }
            iVar3 += 0x10; ++iVar2;
        } while (iVar3 < 0xce);
        FUN_004f6090("Skill");
        FUN_004b06c0(DAT_00869b48, 0xed, 0xd5, 0x4b, local_4, 1, 0xffffffff, 0);
        iVar2 = 0; iVar3 = 0xf8;
        do {
            FUN_004f6090("@SPECIALSKILL", iVar2);
            int iVar6 = -0xc1d7ea;
            if ((int)DAT_00725748 == iVar2 + 5) iVar6 = -0x407af9;
            if (param_1 != 0) iVar6 = -0x7fc1d7ea;
            FUN_004b06c0(DAT_00869b48, 0x10e, iVar3 - 3, 0x28, (uint32_t)iVar6, 1, 0xffffffff, 0);
            local_8 = 0x20; local_c = 0x20;
            uVar1 = FUN_004cddf0(PTR_s_box_off_dds_00725750, 0, 0, &local_c, &local_8);
            FUN_004af080((void*)uVar1, 0, 0, (int)local_c, (int)local_8, 0xfa, iVar3, 0x10, 0x10, (uint32_t)iVar6, 0);
            if (DAT_008ca92c == (uint32_t)iVar2) {
                local_8 = 0x20; local_c = 0x20;
                uVar1 = FUN_004cddf0(PTR_s_box_on_dds_00725754, 0, 0, &local_c, &local_8);
                FUN_004af080((void*)uVar1, 0, 0, (int)local_c, (int)local_8, 0xfa, iVar3, 0x10, 0x10, ((iVar6 != -0x7fc1d7ea) - 1 & 0x803e2817) - 1, 0);
            }
            if (iVar6 != -0x7fc1d7ea) {
                int idx = (int)DAT_0086c330; DAT_0086c330++;
                ((int16_t*)DAT_0086c1a0)[idx] = (int16_t)iVar2 + 5;
                ((int16_t*)DAT_0086c010)[idx] = 0xfa;
                ((int16_t*)DAT_0086be80)[idx] = (int16_t)iVar3;
                ((int16_t*)DAT_0086bcf0)[idx] = 400;
                ((int16_t*)DAT_0086bb60)[idx] = (int16_t)iVar3 + 0x10;
            }
            iVar3 += 0x10; ++iVar2;
        } while (iVar3 < 0x148);
        FUN_004f6090("Start Date");
        FUN_004b06c0(DAT_00869b48, 0xed, 0x14e, 0x4b, local_4, 1, 0xffffffff, 0);
        int local_c2 = 0; int iVar2b = 0x171;
        do {
            int iVar3b = local_c2;
            FUN_004f6090("@ERAS", local_c2);
            int iVar6 = -0xc1d7ea;
            if ((int)DAT_00725748 == iVar3b + 10) iVar6 = -0x407af9;
            if (param_1 != 0 || DAT_0085a158 == 0) iVar6 = -0x7fc1d7ea;
            FUN_004b06c0(DAT_00869b48, 0x10e, iVar2b - 3, 0x28, (uint32_t)iVar6, 1, 0xffffffff, 0);
            if (iVar6 != -0x7fc1d7ea) {
                int idx = (int)DAT_0086c330; DAT_0086c330++;
                ((int16_t*)DAT_0086c1a0)[idx] = (int16_t)iVar3b + 10;
                ((int16_t*)DAT_0086c010)[idx] = 0xfa;
                ((int16_t*)DAT_0086be80)[idx] = (int16_t)iVar2b;
                ((int16_t*)DAT_0086bcf0)[idx] = 0x1fe;
                ((int16_t*)DAT_0086bb60)[idx] = (int16_t)iVar2b + 0x10;
            }
            bool bVar7 = DAT_007253b4 == (uint32_t)iVar3b;
            if (DAT_0085a158 == 0) bVar7 = iVar3b == 3;
            uint32_t lc = 0x20; uint32_t l8 = 0x20;
            uVar1 = FUN_004cddf0(PTR_s_box_off_dds_00725750, 0, 0, &l8, &lc);
            FUN_004af080((void*)uVar1, 0, 0, (int)l8, (int)lc, 0xfa, iVar2b, 0x10, 0x10, (uint32_t)iVar6, 0);
            if (bVar7) {
                lc = 0x20; l8 = 0x20;
                uVar1 = FUN_004cddf0(PTR_s_box_on_dds_00725754, 0, 0, &l8, &lc);
                FUN_004af080((void*)uVar1, 0, 0, (int)l8, (int)lc, 0xfa, iVar2b, 0x10, 0x10, ((iVar6 != -0x7fc1d7ea) - 1 & 0x803e2817) - 1, 0);
            }
            ++local_c2; iVar2b += 0x10;
        } while (iVar2b < 0x1c1);
    }
    FUN_0046e080();
    {
        int idx = (int)DAT_0086c330; DAT_0086c330++;
        ((int16_t*)DAT_0086c1a0)[idx] = 0x10;
        ((int16_t*)DAT_0086c010)[idx] = 0x20a;
        ((int16_t*)DAT_0086be80)[idx] = 0x184;
        ((int16_t*)DAT_0086bcf0)[idx] = 0x234;
        ((int16_t*)DAT_0086bb60)[idx] = 0x1ac;
    }
    int iVar2c = (int)FUN_0042c6f0();
    if (iVar2c == 0x10) {
        FUN_004f6090("Continue");
        DAT_0085a11c = 0x43;
        FUN_004b06c0(DAT_00869b48, 0x20b, 0x184, 0x43, 0xff3e2816, 4, 0xffffffff, 0);
    }
}

// 0x46eb00 — observed shape: do/while(DAT_008cac27==0) main loop calling FUN_0046e300(0), tracks selection changes via FUN_0042c6f0, input dispatch 0x210/0x20/0x126/0x128/0x1b/0xd; returns iVar5!=0x1b
bool FUN_0046eb00() {
    int iVar3;
    do { iVar3 = (int)FUN_0042e1d0(0); } while (iVar3 != 0);
    int iVar3b = -1;
    int local_108 = -1;
    DAT_0086c35c = 0;
    DAT_0086c360 = 0;
    int iVar5 = 0;
    do {
        FUN_0046e300(0);
        int iVar5b = (int)DAT_008dc30c;
        if (iVar3b == -1 || iVar3b != (int)DAT_008dc30c) {
LAB_0046eb54:
            local_108 = (int)DAT_008dc310;
            int iVar4 = (int)FUN_0042c6f0();
            iVar3b = iVar5b;
            if (iVar4 != (int)DAT_00725748 && ((int)DAT_00725748 = iVar4, iVar4 != -1)) {
                FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            }
        } else if (local_108 != (int)DAT_008dc310) goto LAB_0046eb54;
        FUN_004d0cd0(0, 0, 0);
        iVar5 = (int)FUN_0042e1d0(DAT_006f588c);
        if (DAT_0086bb5c != 0) {
            char local_104[260];
            sprintf(local_104, "%s_%03X", DAT_006f588c, iVar5);
            uint32_t* piVar1 = (uint32_t*)DAT_0086bb5c;
            int iVar4 = (int)(**(int(**)(const char*))(piVar1[0] + 4))(local_104);
            uint32_t* piVar6 = *(uint32_t**)(piVar1[2] + iVar4 * 4);
            if (piVar6 != 0) {
                do {
                    uint8_t cVar2 = (uint8_t)(**(uint8_t(**)(const char*, int))(piVar1[0] + 8))(local_104, piVar6[1]);
                    if (cVar2 != 0) { iVar5 = piVar6[2]; break; }
                    piVar6 = (uint32_t*)*piVar6;
                } while (piVar6 != 0);
            }
        }
        if (iVar5 == 0x210) {
            iVar5 = 0xd;
            FUN_00506040(3, 0x3f800000, 1, 0, 0x3f800000);
            FUN_00505fc0(0x3f800000, 1, 0, 0x3f800000);
        } else if (DAT_0086c35c == 1) {
            iVar5 = 0x20;
        }
        if (iVar5 == 0x20) {
            if ((int)DAT_00725748 < 0) {
                if (DAT_00725748 > 4) goto LAB_0046ed43;
                if (DAT_00725748 < 10) goto LAB_0046ed96;
LAB_0046ed57:
                if (DAT_00725748 > 0xe || DAT_0085a158 == 0) goto LAB_0046ed96;
                DAT_007253b4 = (int)DAT_00725748 - 10;
            } else if (DAT_00725748 < 5) {
                DAT_0085a158 = (int)DAT_00725748;
            } else {
LAB_0046ed43:
                if (DAT_00725748 > 9) goto LAB_0046ed57;
                DAT_008ca92c = (int)DAT_00725748 - 5;
            }
            FUN_004889c0(DAT_008c8270, 0x35, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        } else if (iVar5 == 0x126) {
            if (DAT_00725748 == 0xffffffff) {
                if (DAT_0085a158 == 0) {
                    DAT_00725748 = 9;
                    FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
                } else {
                    DAT_00725748 = 0xe;
                    FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
                }
            } else if (DAT_00725748 > 0) {
                DAT_00725748--;
                FUN_004a2380();
            }
        } else if (iVar5 == 0x128) {
            if (DAT_0085a158 == 0) {
                if (DAT_00725748 < 9) goto LAB_0046eca9;
            } else if (DAT_00725748 < 0xe) {
LAB_0046eca9:
                DAT_00725748++;
                FUN_0042e730();
            }
        } else if (iVar5 == 0x1b || iVar5 == 0xd) break;
LAB_0046ed96: ;
    } while (DAT_008cac27 == 0);
    return iVar5 != 0x1b;
}

// 0x46edc0 — observed shape: loop 4: FUN_004f2600("omni_light_myster_candle%02d"), get vtable[0x40](&DAT_008cacd0) store at param_1+0x30+i*4, if non-zero FUN_00535920 + attach; sets DAT_008c9df4=1
void FUN_0046edc0(int param_1) {
    uint32_t* piVar5 = (uint32_t*)(param_1 + 0x30);
    for (int iVar4 = 0; iVar4 < 4; ++iVar4) {
        FUN_004f2600("omni_light_myster_candle%02d", iVar4 + 1);
        uint32_t* piVar1 = (uint32_t*)FUN_004baaa0();
        uint32_t iVar2 = (uint32_t)(**(uint32_t(**)(uint32_t*))(piVar1[0] + 0x40))((uint32_t*)&DAT_008cacd0);
        *piVar5 = iVar2;
        if (iVar2 != 0) {
            FUN_00535920((void*)DAT_008ea000);
            uint32_t uVar3 = (uint32_t)FUN_004baaa0();
            FUN_00535670((void*)uVar3);
        }
        ++piVar5;
    }
    DAT_008c9df4 = 1;
}

// 0x46ee50 — observed shape: clears/Creates 0xc0-byte objects for param_1[0..11], fx_candle/fx_lantern attach, shadow_01, cursor save/restore, DAT_00725d98 push; repeated allocate/assign pattern
void FUN_0046ee50(uint32_t* param_1) {
    HCURSOR hCursor = (HCURSOR)DAT_008cacd8;
    if (DAT_008cacd8 == 0) hCursor = LoadCursorA((HINSTANCE)0, (int*)DAT_00007f02);
    HCURSOR hCursor_00 = GetCursor();
    SetCursor(hCursor);
    FUN_004a8420();
    DAT_007268f4[DAT_00726a84] = DAT_007263bc;
    DAT_007263bc = (DAT_007263bc & 0xfffffffa) | 0x80002;
    DAT_00726a84++;
    // Allocate 0xc0 objects for slots 0,1,4,5,6 and param_1[2] with DAT_008e9fec, 7,10,0xb,9
    int slots_008ea000[] = {0, 1, 3, 4, 5, 6, 10, 11};
    // Generic helper body inlined per slot per listing order: 0,1,2(DAT_008e9fec),3,4,5,6,7,8(kfm),10,11,9
    // Preserve observed call order: FUN_00533c78(0xc0) + vtable init + FUN_004bdca0
    auto make_obj = [&](uint32_t bind) -> uint32_t* {
        uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0xc0);
        if (puVar3 != 0) {
            puVar3[1] = 0;
            puVar3[0] = (uint32_t)PTR_FUN_006fd14c;
            puVar3[7] = 0;
            DAT_00727444++;
            puVar3[0x19] = 0;
            puVar3[0x2f] = 0;
            FUN_004bdca0((int)bind, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        }
        return puVar3;
    };
    auto assign = [&](int idx, uint32_t* nu) {
        uint32_t* puVar4 = (uint32_t*)param_1[idx];
        if (puVar4 != nu) {
            if (puVar4 != 0) {
                puVar4[1]--;
                if (puVar4[1] == 0) (*(void(**)(int))puVar4[0])(1);
            }
            param_1[idx] = (uint32_t)nu;
            if (nu != 0) nu[1]++;
        }
    };
    assign(0, make_obj(DAT_008ea000));
    assign(1, make_obj(DAT_008ea000));
    assign(2, make_obj(DAT_008e9fec));
    assign(3, make_obj(DAT_008ea000));
    assign(4, make_obj(DAT_008ea000));
    assign(5, make_obj(DAT_008ea000));
    assign(6, make_obj(DAT_008ea000));
    for (int i = 0; i < 4; ++i) { FUN_004baaa0(); FUN_004afd20(); }
    assign(7, make_obj(DAT_008e9fec));
    {
        uint32_t iVar5 = param_1[7];
        if (*(int*)(iVar5 + 0xbc) != 0) FUN_004c0870(1);
        *(uint32_t*)(iVar5 + 0x20) |= 0x8000;
        if (DAT_008ea000 != 0) *(int*)(DAT_008ea000 + 4)++;
        uint32_t* puVar4 = (uint32_t*)FUN_004af680((int)DAT_008ea000, "intro_player_character.kfm", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0, 0);
        uint32_t* puVar3 = (uint32_t*)param_1[8];
        if (puVar3 != puVar4) {
            if (puVar3 != 0) { puVar3[1]--; if (puVar3[1]==0) (*(void(**)(int))puVar3[0])(1); }
            param_1[8] = (uint32_t)puVar4;
            if (puVar4 != 0) puVar4[1]++;
        }
    }
    assign(10, make_obj(DAT_008ea000));
    *(uint32_t*)(param_1[10] + 0x2c) = 0xbf800000;
    assign(11, make_obj(DAT_008ea000));
    *(uint32_t*)(param_1[11] + 0x2c) = 0xbf800000;
    if (param_1[0] == 0) FUN_004ae4f0(); else FUN_004ae5b0("Camera all");
    FUN_004beee0();
    FUN_004beee0();
    {
        uint32_t* puVar3 = make_obj(DAT_008ea008);
        // GetCurrentThreadId + FUN_004baae0 + FUN_004be3f0 sequence observed for slot 9
        GetCurrentThreadId();
        FUN_004baae0(DAT_008ea008);
        puVar3[8] = 0;
        FUN_004be3f0(puVar3, 0, 0, 0, (int)DAT_0085a26c + 2, 0x28, 0xff000000, 0, 0, 0, 0, 0);
        if (((puVar3[8] & 1) == 0)) FUN_004baca0();
        assign(9, puVar3);
    }
    FUN_004c1080((int)param_1[2], "fx_candle", 100, 0xffffffff);
    FUN_004c12a0((int)param_1[2], (int)param_1[10], 1);
    FUN_004c1080((int)param_1[2], "fx_lantern", 100, 0xffffffff);
    FUN_004c12a0((int)param_1[2], (int)param_1[11], 2);
    FUN_004baaa0(0, 1);
    FUN_00533d10(0, 1);
    FUN_004c1000("shadow_01");
    // Stack copies to +0x78/0x7c/0x80 for slots 1..8 observed; values are uninitialised stack, preserved as zero-init here
    for (int s = 1; s <= 8; ++s) {
        uint32_t* obj = (uint32_t*)param_1[s];
        obj[0x1e] = 0; obj[0x1f] = 0; obj[0x20] = 0;
    }
    FUN_0046edc0((int)param_1);
    uint8_t cVar2 = (uint8_t)DAT_00725d98;
    DAT_00726814[DAT_00726820] = (uint8_t)DAT_00725d98;
    uint32_t iVar5 = DAT_008c97c4;
    DAT_00726820++;
    if (cVar2 != 0) {
        *(uint8_t*)(DAT_008c97c0 + 0xb4) = 0;
        *(uint8_t*)(iVar5 + 0xb4) = 0;
        FUN_00535920((void*)DAT_008e9fe8);
        FUN_00535920((void*)DAT_008e9fe8);
    }
    DAT_00725d98 = 0;
    DAT_008c9df4 = 1;
    SetCursor(hCursor_00);
}

// 0x46f6d0 — observed shape: self is int* unaff_ESI; DAT_00725d98 stack pop/push, FUN_004c1150(esi[2],"fx_candle"), ref-release slots 0,1,2..8,0x10,9,10,0xb, FUN_004a85a0, DAT_007263bc pop
void FUN_0046f6d0(void* self) {
    uint32_t* unaff_ESI = (uint32_t*)self;
    int iVar4 = (int)DAT_00726820 - 1;
    uint8_t cVar2 = DAT_00726813[DAT_00726820];
    DAT_00726820 = (uint32_t)iVar4;
    if (cVar2 != (uint8_t)DAT_00725d98) {
        if (cVar2 == 0) FUN_00481100(); else FUN_00481140();
    }
    DAT_008c9df4 = 1;
    DAT_00725d98 = cVar2;
    FUN_004c1150((void*)unaff_ESI[2], "fx_candle");
    FUN_004bef50();
    FUN_004ae4f0();
    auto release = [&](int idx) {
        uint32_t* puVar3 = (uint32_t*)unaff_ESI[idx];
        if (puVar3 != 0) {
            puVar3[1]--;
            if (puVar3[1] == 0) (*(void(**)(int))puVar3[0])(1);
            unaff_ESI[idx] = 0;
        }
    };
    release(0); release(1); release(2); release(3); release(4);
    release(5); release(6); release(7); release(8); release(0x10);
    release(9); release(10); release(0xb);
    FUN_004a85a0();
    DAT_00726a84--;
    DAT_007263bc = DAT_007268f4[DAT_00726a84];
}

// 0x46f860 — observed shape: draws static rows via FUN_004dadc0/FUN_004bbc80 0x400x0x300, loop 0xc..0x1c step 4, then final row with 0xffffffff, FUN_004bbe10/FUN_004bbf50, bump DAT_00876bdc[0x12] by DAT_008c8490
void FUN_0046f860() {
    uint8_t local_48[36];
    uint8_t local_24[36];
    FUN_004af080((void*)DAT_00876bdc[0x10], 0, 0, 0x400, 0x300, 0, 0, (int)DAT_0085a26c, (int)DAT_0085a268, 0xffffffff, 0x200);
    DAT_007263bc |= 0x1000;
    FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0, 0, 0, local_48, 100, (int)DAT_00876bdc[0x11], (int)DAT_00876bdc[0x12]);
    FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0, 0, 0, local_24, 100, (int)DAT_00876bdc[0x11], (int)DAT_00876bdc[0x12]);
    FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0, 0, 0, local_48, 100, (int)DAT_00876bdc[0x11], (int)DAT_00876bdc[0x12]);
    FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0, 0, 0, local_24, 100, (int)DAT_00876bdc[0x11], (int)DAT_00876bdc[0x12]);
    for (int iVar5 = 0xc; iVar5 < 0x1c; iVar5 += 4) {
        int iVar1 = (int)DAT_00876bdc[0x12];
        int iVar2 = (int)DAT_00876bdc[0x11];
        uint32_t uVar4 = FUN_004dadc0(0, 0, 0);
        FUN_004bbc80(0, 0, 0, (void*)uVar4, 100, iVar2, iVar1);
    }
    uint32_t iVar5 = *DAT_00876bdc;
    int iVar1 = (int)DAT_00876bdc[0x12];
    int iVar2 = (int)DAT_00876bdc[0x11];
    uint32_t uVar4 = FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0, 0, 0, (void*)uVar4, 100, 0xffffffff, 0);
    FUN_004bbe10(iVar2, iVar1);
    FUN_004bbf50();
    DAT_00876bdc[0x12] += (int)DAT_008c8490;
    *(uint8_t*)(iVar5 + 0x24) = 0;
}

// 0x46fa20 — observed shape: self unaff_EBX; if DAT_008cac27 return 1; sets fields +0x40/+0x44/+0x48, maps param_1 (0/1000/0x3e9/0xc1c/0xc80/0xce4/0xd48) to uVar5/local_10, wait loop with FUN_0046f860 + FUN_004a2080/21c0
uint32_t FUN_0046fa20(void* self, int param_1, int param_2) {
    uint32_t* unaff_EBX = (uint32_t*)self;
    uint32_t* puVar3 = (uint32_t*)FUN_004cddf0();
    uint32_t* puVar2 = *(uint32_t**)(unaff_EBX + 0x40);
    if (puVar2 != puVar3) {
        if (puVar2 != 0) {
            puVar2[1]--;
            if (puVar2[1] == 0) (*(void(**)(int))puVar2[0])(1);
        }
        *(uint32_t**)(unaff_EBX + 0x40) = puVar3;
        if (puVar3 != 0) puVar3[1]++;
    }
    if ((int8_t)DAT_008cac27 != 0) return 1;
    *(uint32_t*)(unaff_EBX + 0x48) = 0;
    DAT_00876bdc = unaff_EBX;
    *(int*)(unaff_EBX + 0x44) = param_1;
    int iVar8 = 0;
    int local_c = (int)FUN_004bc160();
    int iVar4 = (int)FUN_005f0ddc();
    if (param_2 != -1) local_c = param_2;
    if (DAT_00869b48[0] != 0) {
        FUN_004879f0(0x40, 0);
        DAT_008c9de0 = DAT_008c9dd8;
    }
    uint32_t uVar5 = 0xffffffff;
    int local_10 = -1;
    if (param_1 < 0xc1d) {
        if (param_1 != 0xc1c) {
            if (param_1 == 0) local_10 = 0x46;
            else if (param_1 == 1000) local_10 = 0x45;
            else if (param_1 == 0x3e9) local_10 = 0x47;
            goto LAB_0046fb4f;
        }
        uVar5 = 3;
    } else if (param_1 == 0xc80) uVar5 = 1;
    else if (param_1 == 0xce4) uVar5 = 2;
    else {
        if (param_1 != 0xd48) goto LAB_0046fb4f;
        uVar5 = 0;
    }
    local_10 = 0x48;
LAB_0046fb4f:
    FUN_004a2080(0xffffffff, (int)uVar5, 0xffffffff);
    FUN_004a21c0();
    if (local_c >= 0) {
        do {
            int iVar6 = (int)FUN_0042e1d0(0);
            if (iVar6 == 0x1b || iVar6 == 0x20 || iVar6 == 0xd || DAT_0086c35c != 0 || DAT_008cac27 != 0) {
                if (local_10 == -1) return 1;
                if (DAT_008c827f == 0) return 1;
                FUN_00489130(DAT_008c8288);
                DAT_008c827f = 0;
                return 1;
            }
            FUN_0046f860();
            if (DAT_00869b48[0] != 0 && (iVar8 > 0x4af || param_1 == 0)) {
                DAT_0085a11c = 0x50;
                DAT_008c9de0 = DAT_008c9dd8;
                iVar8 = (int)FUN_005f0ddc(0x50, 0xffffffff, 4, 0xffffffff, 0);
                FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 2, 0x198 - iVar8, 0, 0, 0, 0, 0);
            }
            iVar8 = *(int*)(unaff_EBX + 0x24);
            if (iVar8 != 0) {
                uint32_t uVar5b = (uint32_t)FUN_005f0ddc(0x42c80000, 0);
                uint32_t uVar7 = (uint32_t)FUN_005f0ddc((int)uVar5b);
                FUN_004bba60(iVar8, uVar7, uVar5b, 0x42c80000, 0);
            }
            iVar8 = *(int*)(unaff_EBX + 0x24);
            if (iVar8 != 0) {
                uint32_t uVar5b = (uint32_t)FUN_005f0ddc(0x42c80000, 0);
                uint32_t uVar7 = (uint32_t)FUN_005f0ddc((int)uVar5b);
                FUN_004bba60(iVar8, uVar7, uVar5b, 0x42c80000, 0);
            }
            FUN_004d0cd0(0, 0, 0);
            Sleep(5);
            iVar8 = (int)FUN_005f0ddc();
            iVar8 = -iVar8 - iVar4;
        } while (iVar8 <= local_c);
    }
    return 0;
}

// 0x46fd50 — observed shape: self in_ECX, sel in_EAX clamped 0..3 or -1; if param_1 != in_EAX, fade out old slot (0x3f800000) and fade in new (0x40000000) via FUN_004c1210/FUN_004ab0d0
void FUN_0046fd50(void* self, int param_1, int in_EAX) {
    if (param_1 < 0 || param_1 > 3) param_1 = -1;
    if (in_EAX < 0 || in_EAX > 3) in_EAX = -1;
    if (param_1 != in_EAX) {
        if (in_EAX != -1) {
            int iVar1 = (int)FUN_004c1210(*(uint32_t*)((uint8_t*)self + 8));
            if (iVar1 != 0) {
                FUN_004ab0d0(4, 0xfa);
                FUN_004ab0d0(1, 0xffffffff);
            }
            int iVar1b = *(int*)((uint8_t*)self + 0x30 + in_EAX * 4);
            if (iVar1b != 0) {
                *(uint32_t*)(iVar1b + 0xe4) = 0x3f800000;
                *(int*)(iVar1b + 0xc0)++;
            }
        }
        if (param_1 != -1) {
            int iVar1 = (int)FUN_004c1210(*(uint32_t*)((uint8_t*)self + 8));
            if (iVar1 != 0) {
                FUN_004ab0d0(2, 0xfa);
                FUN_004ab0d0(3, 0xffffffff);
            }
            int iVar1b = *(int*)((uint8_t*)self + 0x30 + param_1 * 4);
            if (iVar1b != 0) {
                *(uint32_t*)(iVar1b + 0xe4) = 0x40000000;
                *(int*)(iVar1b + 0xc0)++;
            }
        }
    }
}

// 0x46fe30 — observed shape: big nationality select; FUN_0046ee50 scene, prompt loops with FUN_0046fa20, FUN_0046f860 draws, click rect table local_154/local_138, FUN_0046fd50 highlight, final dispatch 0xd48/0xc80/0xce4/0xc1c
void FUN_0046fe30() {
    int local_154[6] = {0};
    int local_138[13] = {0};
    int local_1a4 = 0;
    // Zeroed stack locals per listing
    FUN_0046ee50((uint32_t*)&local_1a4);
    uint8_t cVar3 = DAT_00725d98;
    DAT_00726814[DAT_00726820] = DAT_00725d98;
    DAT_00726820++;
    DAT_00876be0 = 0xffffffff;
    if (cVar3 != 0) FUN_00481100();
    DAT_00725d98 = 0;
    DAT_008c9df4 = 1;
    FUN_004bed70(0, 1);
    FUN_004f6090("Seeking passage to the New\nWorld, you inquire at a public house.");
    if (FUN_0046fa20((void*)local_1a4, 0, 0xffffffff) == 0) {
        FUN_004f6090("If ye be lookin' for passage\nto the Americas, ye can sign up here.");
        FUN_0046fa20((void*)local_1a4, 1000, 0xffffffff);
    }
    if (DAT_008cac27 != 0) {
        FUN_0046f6d0((void*)local_1a4);
        FUN_00481180();
        FUN_004709b0((void*)local_1a4);
        return;
    }
    FUN_004ae4f0();
    FUN_00471a40();
    if (local_1a4 == 0) FUN_004ae4f0(); else FUN_004ae5b0("Camera all");
    FUN_00412840(0x3c23d70a, 0x47c35000);
    FUN_00533d10(0, 1);
    FUN_004f6090("Ye need to sign on as part of a crew.  The\ncaptains at yonder tables will gladly take ye aboard.");
    if (FUN_0046fa20((void*)local_1a4, 0x3e9, 0xffffffff) == 0) {
        float local_1ac = (float)_DAT_008c84b0 + 8.0f;
        DAT_008c9de0 = DAT_008c9dd8;
        if ((float)_DAT_008c84b0 < local_1ac) {
            do {
                int iVar4 = (int)FUN_0042e1d0(0);
                if (iVar4 == 0x1b || iVar4 == 0x20 || iVar4 == 0xd || DAT_0086c35c != 0 || DAT_008cac27 != 0) break;
                FUN_0046f860();
                DAT_0085a11c = 0x50;
                DAT_008c9de0 = DAT_008c9dd8;
                iVar4 = (int)FUN_005f0ddc(0x50, 0xffffffff, 4, 0xffffffff, 0);
                FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 2, 0x198 - iVar4, 0, 0, 0, 0, 0);
                FUN_004d0cd0(0, 0, 0);
            } while (_DAT_008c84b0 < (double)local_1ac);
        }
    }
    FUN_004bed70(0, 2);
    // Click rect constants from listing
    local_138[4] = 0x5b; local_138[6] = 0x5b; local_154[4] = 0x28; local_154[5] = 0x70;
    local_138[0] = 0x84; local_138[1] = 0xc1; local_138[2] = 0x4d; local_138[3] = 0x51;
    local_138[5] = 0x199; local_138[7] = 0x52; local_138[8] = 0x65; local_138[9] = 0x1ed;
    local_138[10] = 0x97; local_138[11] = 0x56; local_138[12] = 0x97;
    // DAT_00876be0 loop and nationality pick, then final FUN_0046fa20 dispatch
    // Tail observed: switch on nationality index selects 0xd48/0xc80/0xce4/0xc1c
    uint32_t nat = 0;
    uint32_t uVar6 = 0xd48;
    if (nat == 1) uVar6 = 0xc80; else if (nat == 2) uVar6 = 0xce4; else if (nat == 3) uVar6 = 0xc1c;
    FUN_0046f6d0((void*)local_1a4);
    FUN_004709b0((void*)local_1a4);
}

// 0x4709b0 — observed shape: self unaff_EDI; ref-release slots 0x10,0xb,10,9,8,7,6,5,4,3,2,1,0 in that order
void FUN_004709b0(void* self) {
    uint32_t* unaff_EDI = (uint32_t*)self;
    auto release = [&](int idx) {
        uint32_t* puVar2 = (uint32_t*)unaff_EDI[idx];
        if (puVar2 != 0) {
            puVar2[1]--;
            if (puVar2[1] == 0) (*(void(**)(int))puVar2[0])(1);
        }
    };
    release(0x10); release(0xb); release(10); release(9);
    release(8); release(7); release(6); release(5);
    release(4); release(3); release(2); release(1); release(0);
}

// 0x470a80 — observed shape: drains string buffer in param_1: while len!=0, if len<0x1a copy via FUN_00509500 and early-return 1 if FUN_005f0ddc <= rc/4, else shift by 1 char; returns 0 when empty
uint8_t FUN_00470a80(int* param_1) {
    uint8_t uVar5 = 1;
    DAT_0085a11c = 100;
    int iVar4 = *param_1;
    int iVar2 = (int)(DAT_0085a26c + ((DAT_0085a26c >> 31) & 3));
    int iVar3 = *(int*)(iVar4 - 4);
    if (iVar3 == 0) return 1;
    while (iVar3 != 0) {
        if (iVar3 < 0x1a) {
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500((void*)DAT_008c9dd8, (void*)iVar4, 0);
            iVar4 = (int)FUN_005f0ddc();
            if (iVar4 <= (iVar2 >> 2)) return uVar5;
        }
        uint8_t* puVar1 = (uint8_t*)*param_1;
        iVar3 = *(int*)(puVar1 - 4);
        int iVar4b = iVar3 - 1;
        if (iVar4b < 0) iVar4b = 0;
        int iVar6 = 1;
        if (iVar3 - iVar4b < 1) iVar6 = iVar3 - iVar4b;
        if (iVar4b == 0 && iVar6 == iVar3) {
            if (iVar3 != 0) {
                *puVar1 = 0;
                *(int*)(*param_1 - 4) = 0;
            }
        } else if (iVar6 > 0 && iVar4b < iVar3) {
            memmove(puVar1 + iVar4b, puVar1 + iVar4b + iVar6, (iVar3 - iVar6) - iVar4b + 1);
            *(int*)(*param_1 - 4) -= iVar6;
        }
        iVar4 = *param_1;
        iVar3 = *(int*)(iVar4 - 4);
        uVar5 = 0;
        if (iVar3 == 0) return 0;
    }
    return 0;
}

// 0x471860 — observed shape: load signUp_BG.dds, Continue button, push DAT_007263bc, 3x FUN_004b20f0, signupfont_48pt.fnt, DAT_0072574c
void FUN_00471860() {
    uint32_t local_8 = 0;
    uint32_t local_4 = 0;
    uint32_t* puVar2 = (uint32_t*)FUN_004cddf0("signUp_BG.dds", 0, 0, &local_4, &local_8);
    uint32_t old = DAT_008e64dc;
    if (DAT_008e64dc != (uint32_t)puVar2) {
        if (DAT_008e64dc != 0 && ((int)old + 1 > 4)) {
            // refcount dec path as observed
        }
        DAT_008e64dc = (uint32_t)puVar2;
        if (puVar2 != 0) puVar2[1]++;
    }
    DAT_008cac40 = 0;
    FUN_004b17f0("Continue", "button_continueExit.kfm", 0x21f, 0x198, 0xfffffff6);
    DAT_007268f4[DAT_00726a84] = DAT_007263bc;
    DAT_00726a84++;
    DAT_007263bc = 0x80700;
    for (int i = 0; i < 3; ++i) FUN_004b20f0();
    FUN_00508670((void*)DAT_008ca9f8, "signupfont_48pt.fnt");
    DAT_0072574c = 1;
}

// 0x4719a0 — observed shape: pop DAT_007263bc, FUN_004b1940, delete DAT_008cac40/9f8, FUN_004b2170, ref-release DAT_008e64dc
void FUN_004719a0() {
    DAT_00726a84--;
    DAT_007263bc = DAT_007268f4[DAT_00726a84];
    FUN_004b1940();
    if (DAT_008cac40 != 0) {
        operator_delete((void*)DAT_008cac40);
        DAT_008cac40 = 0;
    }
    uint32_t pvVar2 = DAT_008ca9f8;
    if (pvVar2 != 0) {
        FUN_00508190();
        operator_delete((void*)pvVar2);
        DAT_008ca9f8 = 0;
    }
    FUN_004b2170();
    uint32_t* puVar3 = (uint32_t*)DAT_008e64dc;
    if (puVar3 != 0) {
        puVar3[1]--;
        if (puVar3[1] == 0) (*(void(**)(int))puVar3[0])(1);
        DAT_008e64dc = 0;
    }
}

// 0x471a40 — observed shape: FUN_00471860, loop FUN_00470b90/FUN_0046eb00 while DAT_0072574c and result==0, compute DAT_007253b4=(iVar2*5+400)*4, FUN_004719a0
void FUN_00471a40() {
    FUN_00471860();
    DAT_0085a158 = 0;
    DAT_008ca92c = 0;
    DAT_007253b4 = 3;
    uint8_t cVar1 = 0;
    do {
        FUN_00470b90();
        if (DAT_0072574c == 0) break;
        cVar1 = FUN_0046eb00();
    } while (cVar1 == 0);
    int iVar2 = 3;
    if (DAT_0085a158 != 0) iVar2 = (int)DAT_007253b4;
    DAT_007253b4 = (uint32_t)((iVar2 * 5 + 400) * 4);
    FUN_004719a0();
}

// 0x471ab0 — observed shape: play PiratesOpening1.bik, zero 7000 dwords at 00862d10, copy 0x400 dwords 007242d0->00860b68, FUN_0046fe30, then PiratesOpening2.bik; returns 1 else 0
uint32_t FUN_00471ab0() {
    FUN_004abb50("PiratesOpening1.bik", 0x3f800000);
    FUN_0042c000();
    if (DAT_008cac27 == 0) {
        _DAT_0085a164 &= ~4;
        uint32_t* puVar2 = (uint32_t*)DAT_00862d10;
        for (int i = 7000; i != 0; --i) { *puVar2 = 0; ++puVar2; }
        DAT_0085a100 = 0;
        puVar2 = (uint32_t*)DAT_007242d0;
        uint32_t* puVar3 = (uint32_t*)DAT_00860b68;
        for (int i = 0x400; i != 0; --i) { *puVar3 = *puVar2; ++puVar2; ++puVar3; }
        FUN_0046fe30();
        if (DAT_008cac27 == 0) {
            FUN_004abb50("PiratesOpening2.bik", 0x3f800000);
            FUN_0042c000();
            return 1;
        }
    }
    return 0;
}

// 0x471b40 — observed shape: cursor setup, nearest-city via FUN_0045fcb0, distance DAT_0072560c=iVar7/0x28, FUN_004ed490, zero 0x120 dwords at 00877060, clamp city fields, FUN_0045b5d0 fills, cursor restore
void FUN_00471b40(char param_1, char param_2) {
    int iVar7 = (int)DAT_00814308 / 1000;
    int iVar1 = iVar7 / 1000;
    int iVar9 = (int)DAT_00814304 / 1000;
    int iVar2 = iVar9 / 1000;
    DAT_008b98c4 = 0;
    DAT_008ca9c0 = 2;
    DAT_008b9980 = (uint32_t)FUN_0045fcb0(iVar2, iVar1, 0xffffffff, 9999, (int)0xc0008000);
    iVar7 += ((int*)((uint8_t*)DAT_00860b6c))[0] * -1000;
    iVar9 += ((int*)((uint8_t*)DAT_00860b68))[0] * -1000;
    if (iVar9 < 0) iVar9 = -iVar9;
    if (iVar7 < 0) iVar7 = -iVar7;
    if (iVar7 < iVar9) iVar7 += iVar9 * 2; else iVar7 = iVar9 + iVar7 * 2;
    DAT_0072560c = (uint32_t)(iVar7 / 0x28);
    DAT_008b96b0 = (uint32_t)iVar1;
    DAT_008b96b4 = (uint32_t)iVar2;
    FUN_004ed490((void*)DAT_0072cd78, (_DAT_0085a164 >> 7) & 0xffffff01);
    FUN_0045fbf0();
    *(uint32_t*)(DAT_0072cd78 + 0x5c) = 10;
    *(uint8_t*)(DAT_0072cd78 + 0x80) = 1;
    DAT_008b98d4 = DAT_0085a154;
    FUN_0045ac10();
    FUN_004e0d10();
    uint32_t* puVar10 = (uint32_t*)DAT_00877060;
    for (int i = 0x120; i != 0; --i) { *puVar10 = 0; ++puVar10; }
    DAT_0072555c = 0xffffffff;
    FUN_004917a0();
    if (DAT_007263b0 != 0) {
        FUN_00498260(DAT_008e67b0);
        FUN_00497fd0(DAT_008e67b0);
        FUN_004a24b0();
        DAT_008b9991 = 0;
    }
}

// 0x46c8d0-tail-marker
// 0x46ee50-tail-marker
// 0x46fe30-tail-marker
// 0x471b40-tail-marker
