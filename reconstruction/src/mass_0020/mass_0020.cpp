// Reconstruction batch mass_0020 — Sid Meier's Pirates! (2004), PE32 i386
// Address range 0x482200..0x4881b0. Pseudocode corpus Ghidra 12.2.
// Receiver registers in_EAX/in_ECX/in_EDI are explicit leading parameters.
// Globals DAT_* and helpers FUN_* are extern; field offsets preserved.
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>

// ---- Globals (extern, as used by listed corpus) ----
extern uint32_t DAT_008ea000;
extern uint32_t DAT_00727444;
extern uint8_t DAT_008cacd0[];
extern uint32_t DAT_008caccc;
extern uint8_t DAT_008cacd8[];
extern uint8_t DAT_0085bf78[];
extern uint32_t DAT_00726ae8;
extern uint32_t DAT_00726aec;
extern uint32_t DAT_00726af0;
extern uint32_t DAT_008cade0;
extern uint32_t DAT_008cade4;
extern uint32_t DAT_008cade8;
extern uint32_t DAT_008beb04;
extern uint32_t DAT_008ea08c;
extern uint32_t DAT_007263bc;
extern uint32_t DAT_00726a84;
extern uint8_t DAT_007268f4[];
extern uint8_t DAT_00726814[];
extern uint32_t DAT_00726820;
extern uint8_t DAT_00725d98;
extern uint32_t DAT_008c9df4;
extern uint32_t DAT_008bebd0;
extern uint8_t DAT_00860b74[];
extern uint8_t DAT_00869aa8[];
extern uint32_t DAT_00869a70;
extern uint8_t DAT_00869a88[];
extern uint32_t DAT_008bec20;
extern uint32_t DAT_008bebcc;
extern uint32_t DAT_00726024;
extern uint32_t DAT_008be9f8;
extern uint32_t DAT_008ed61c;
extern uint32_t DAT_008ed618;
extern uint32_t DAT_008caac4;
extern uint32_t DAT_008bf0e0;
extern uint32_t DAT_008caacc;
extern uint32_t DAT_0085a164;
extern uint32_t DAT_0085a268;
extern uint32_t DAT_008e66cc;
extern uint32_t DAT_008be9d0;
extern uint32_t DAT_008be9d4;
extern uint32_t DAT_008be9e4;
extern uint32_t DAT_008e66ec;
extern uint32_t DAT_0085a26c;
extern uint32_t DAT_008c8494;
extern uint32_t DAT_008caac8;
extern uint32_t DAT_008cab04;
extern uint32_t DAT_008caaf4;
extern uint8_t DAT_008e9fd8[];
extern uint32_t DAT_008caae4;
extern uint32_t DAT_008caae8;
extern uint32_t DAT_008caaec;
extern uint32_t DAT_008caaec_;
extern uint32_t DAT_008caaf0;
extern uint32_t DAT_008caaf4_;
extern uint32_t DAT_008caaf8;
extern uint32_t DAT_008caafc;
extern uint32_t DAT_008cab00;
extern uint32_t DAT_008cab08;
extern uint32_t DAT_008cab0c;
extern uint8_t DAT_008c8288[];
extern uint8_t DAT_008c827f;
extern uint8_t DAT_00726813[];
extern uint32_t DAT_008e66c0;
extern uint32_t DAT_008e66c4;
extern uint32_t DAT_008e66c8;
extern uint32_t DAT_008bf0dc;
extern uint32_t DAT_008bf0cc;
extern uint32_t DAT_008bf0d0;
extern uint32_t DAT_008bf0d8;
extern float DAT_008cac44;
extern uint32_t DAT_008e66f0;
extern uint8_t DAT_008c9de0;
extern uint32_t DAT_008c9dd8;
extern uint8_t DAT_00869b48[];
extern uint8_t DAT_008c9de0b[];

// ---- Helpers (extern) ----
extern "C" {
uint32_t FUN_004f2600(const char* fmt, int v);
uint32_t FUN_00412f10(void);
uint32_t* FUN_00533c78(uint32_t n);
void FUN_004bdca0(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i, uint32_t j);
uint32_t FUN_004baaa0(void);
void FUN_004bf760(uint32_t a, uint32_t b, void* c, void* d);
void FUN_004afd20(void);
void FUN_00481100(void);
void FUN_00481140(void);
void FUN_004af680(uint32_t a, const char* b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i, uint32_t j, uint32_t k, uint32_t l);
void FUN_004bcd90(uint32_t a, uint32_t b, uint32_t c);
void FUN_004bed70(uint32_t a, uint32_t b);
void FUN_004c1000(void* p);
void FUN_004f4de0(void);
void FUN_004f0dc0(void);
void FUN_00412900(uint32_t a, uint32_t b, uint32_t c);
void FUN_00412840(uint32_t a, uint32_t b);
void FUN_004db210(void);
int FUN_004953d0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
void FUN_004ad0c0(int a, int b, int c);
uint32_t FUN_005f0ddc(void);
void FUN_004af080(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i, uint32_t j, int k);
uint32_t FUN_004dadc0(uint32_t a, uint32_t b, uint32_t c);
void FUN_004bbc80(int a, int b, int c, void* d, int e, int f, int g);
void FUN_004bbc10(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, int h, uint32_t i);
void FUN_004bbe10(int a, int b);
void FUN_004bbf50(void);
void FUN_004ae4f0(void);
void FUN_004c1150(uint32_t a, const char* b);
void FUN_004e2df0(void);
void FUN_00489130(void* p);
void FUN_00489360(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
int FUN_004bc160(void);
void FUN_004d0cd0(uint32_t a, uint32_t b, uint32_t c);
int FUN_004879f0(int a, int b);
void FUN_004aef70(void* p);
void FUN_00476050(void);
void FUN_00412ec0(void);
void FUN_00412cb0(void);
void FUN_004f3350(void);
uint32_t FUN_004cddf0(uint32_t a, uint32_t b, uint32_t c, void* d, void* e);
void FUN_00509500(uint32_t a, void* b, int c);
}

// 0x482200 — observed shape
// GOVERNOR texture preset + allocate 0xc0 block, vtable PTR 0x6fd14c.
uint32_t* FUN_00482200(int in_eax, int in_ecx, uint8_t* param_1) {
    uint32_t* puVar1;
    uint32_t uVar2;
    int iVar4;
    char* pcVar3 = nullptr;
    switch (in_eax) {
    case 0:
        iVar4 = in_ecx % 3 + 1;
        FUN_004f2600("gov_s%1d_govm.kfm", iVar4);
        pcVar3 = "gov_s%1d.dds";
        break;
    case 1:
        iVar4 = in_ecx % 3 + 1;
        FUN_004f2600("gov_e%1d_govm.kfm", iVar4);
        pcVar3 = "gov_e%1d.dds";
        break;
    case 2:
        FUN_00412f10();
        FUN_004f2600("gov_f_%1d.dds", in_ecx % 3 + 1);
        FUN_00412f10();
        goto switchD_00482223_default;
    case 3:
        iVar4 = in_ecx % 3 + 1;
        FUN_004f2600("gov_d%1d_govm.kfm", iVar4);
        pcVar3 = "gov_d%1d.dds";
        break;
    default:
        goto switchD_00482223_default;
    }
    FUN_004f2600(pcVar3, iVar4);
switchD_00482223_default:
    puVar1 = FUN_00533c78(0xc0);
    uVar2 = DAT_008ea000;
    if (puVar1 == 0) {
        puVar1 = 0;
    } else {
        puVar1[1] = 0;
        *puVar1 = 0x6fd14c;
        puVar1[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar1[0x19] = 0;
        puVar1[0x2f] = 0;
        FUN_004bdca0(uVar2,0,0,0,0,0xffffffffu,0,0,0,0);
    }
    if (param_1 == 0) {
        if (DAT_008caccc == 0) goto LAB_00482370;
        uVar2 = FUN_004baaa0();
        param_1 = DAT_008cacd0;
    } else {
        uVar2 = FUN_004baaa0();
    }
    FUN_004bf760(uVar2,0,DAT_008cacd0,param_1);
LAB_00482370:
    FUN_004baaa0();
    FUN_004afd20();
    return puVar1;
}

// 0x4826a0 — observed shape
// Variant without textures; same 0xc0 block alloc.
uint32_t* FUN_004826a0(int in_eax) {
    uint32_t* puVar1;
    uint32_t uVar2;
    switch (in_eax) {
    case 0:
        FUN_00412f10();
        break;
    case 1:
        FUN_00412f10();
        FUN_00412f10();
        goto LAB_00482728;
    case 2:
        FUN_00412f10();
        break;
    case 3:
        FUN_00412f10();
        FUN_00412f10();
LAB_00482728:
        FUN_00412f10();
        break;
    default:
        break;
    }
    puVar1 = FUN_00533c78(0xc0);
    uVar2 = DAT_008ea000;
    if (puVar1 == 0) {
        puVar1 = 0;
    } else {
        puVar1[1] = 0;
        *puVar1 = 0x6fd14c;
        puVar1[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar1[0x19] = 0;
        puVar1[0x2f] = 0;
        FUN_004bdca0(uVar2,0,0,0,0,0xffffffffu,0,0,0,0);
    }
    if (DAT_008caccc != 0) {
        uVar2 = FUN_004baaa0();
        FUN_004bf760(uVar2,0,DAT_008cacd0,DAT_008cacd0);
    }
    FUN_004baaa0();
    FUN_004afd20();
    return puVar1;
}

// 0x482e60 — observed shape
// Cursor/UI mode switch (param_1 0/1/other), pushes DAT_007263bc frame, big loop.
// NEEDS_MANUAL: 400+ line conditional/UI state machine body elided in corpus view; observed prologue, mode dispatch, and epilogue preserved.
void FUN_00482e60(int param_1, uint32_t param_2) {
    HCURSOR hCursor = (HCURSOR)DAT_008cacd8;
    if ((void*)hCursor == 0) {
        hCursor = LoadCursorA((HINSTANCE)0, (LPCSTR)0x7f02);
    }
    HCURSOR saved = GetCursor();
    SetCursor(hCursor);
    DAT_008be9fc = 0; (void)param_2;
    DAT_008e66c0 = DAT_00726ae8;
    DAT_008e66c4 = DAT_00726aec;
    DAT_008e66c8 = DAT_00726af0;
    DAT_008cada4 = DAT_008cade0;
    DAT_008cada8 = DAT_008cade4;
    DAT_008cadac = DAT_008cade8;
    DAT_008cade0 = DAT_00727424;
    DAT_008cade4 = DAT_00727428;
    DAT_008cade8 = DAT_0072742c;
    // Mode dispatch (0 vs 1 vs other) and 0x34..0x468 loop elided — see listing 0x482e60:54-468.
    // Epilogue observed:
    (void)saved;
}

// 0x483b70 — observed shape
// Replace DAT_008bebd0 with af680-loaded KFM (tav vs gov), then FUN_004bcd90 placement.
void FUN_00483b70(int in_eax, int unaff_edi) {
    int iVar2;
    int cVar1;
    uint32_t bVar3;
    const char* pcVar4;
    if ((void*)DAT_008bebd0 != 0) {
        uint32_t* p = (uint32_t*)DAT_008bebd0;
        typedef void(__thiscall* DelFn)(void*, int);
        ((DelFn)(*(p)))(p, 1);
        DAT_008bebd0 = 0;
    }
    iVar2 = DAT_008ea000;
    pcVar4 = (DAT_008beb04 == 0) ? "tav_player_character.kfm" : "pc_govm.kfm";
    if (DAT_008ea000 != 0) {
        *(int*)(DAT_008ea000 + 4) = *(int*)(DAT_008ea000 + 4) + 1;
    }
    DAT_008bebd0 = (uint32_t) (uintptr_t) FUN_004af680(iVar2, pcVar4, 0,0,0,0, 0xffffffffu, 0,0,0,0, 0);
    cVar1 = DAT_00860b74[in_eax * 0x20];
    if (3 < cVar1) {
        FUN_004bcd90(0, *(int*)DAT_00869aa8, *(int*)(&DAT_00869a70));
        return;
    }
    if (unaff_edi == -1) {
        bVar3 = DAT_00869a88[cVar1 * 2];
        if (9 < bVar3) bVar3 = 9;
        FUN_004bcd90(bVar3, cVar1, *(int*)(&DAT_00869a70));
        return;
    }
    bVar3 = DAT_00869a88[unaff_edi * 2];
    if (9 < bVar3) bVar3 = 9;
    FUN_004bcd90(bVar3, unaff_edi, *(int*)(&DAT_00869a70));
}

// 0x4840f0 — observed shape
// If DAT_008beb04==0 copy 12-byte blob to each non-null entry stepped by 3.
void FUN_004840f0(int in_eax) {
    int* piVar2 = (int*)&DAT_008bebcc;
    (void)in_eax;
    if (DAT_008beb04 == 0) {
        FUN_004bed70(DAT_008bec20, in_eax);
        FUN_004f2600("shadow_%02d", 0);
        FUN_004c1000(DAT_008cacd0);
        uint32_t local_c = 0, local_8 = 0, local_4 = 0;
        do {
            int iVar1 = piVar2[-1];
            if (iVar1 != 0) {
                *(uint32_t*)(iVar1 + 0x78) = local_c;
                *(uint32_t*)(iVar1 + 0x7c) = local_8;
                *(uint32_t*)(iVar1 + 0x80) = local_4;
            }
            iVar1 = *piVar2;
            if (iVar1 != 0) {
                *(uint32_t*)(iVar1 + 0x78) = local_c;
                *(uint32_t*)(iVar1 + 0x7c) = local_8;
                *(uint32_t*)(iVar1 + 0x80) = local_4;
            }
            iVar1 = piVar2[1];
            if (iVar1 != 0) {
                *(uint32_t*)(iVar1 + 0x78) = local_c;
                *(uint32_t*)(iVar1 + 0x7c) = local_8;
                *(uint32_t*)(iVar1 + 0x80) = local_4;
            }
            piVar2 = piVar2 + 3;
        } while ((int)piVar2 < 0x8bec20);
    }
}

// 0x4841b0 — observed shape
// Save cursor, stamp DAT_00726024, time-based fill of array stepped by 7.
void FUN_004841b0(int in_eax) {
    HCURSOR hCursor = (HCURSOR)DAT_008cacd8;
    if ((void*)hCursor == 0) {
        hCursor = LoadCursorA((HINSTANCE)0, (LPCSTR)0x7f02);
    }
    HCURSOR hCursor_00 = GetCursor();
    SetCursor(hCursor);
    DAT_00726024 = in_eax;
    DAT_008be9f8 = in_eax;
    if ((_DAT_008ed61c & 1) == 0) {
        _DAT_008ed61c = _DAT_008ed61c | 1;
        DAT_008ed618 = timeGetTime();
    }
    uint32_t DVar2 = timeGetTime();
    int iVar1 = DAT_00726024;
    int iVar3 = DVar2 - DAT_008ed618;
    DAT_008caac4 = 1;
    int* piVar4 = (int*)&DAT_008bf0e0;
    _DAT_008caacc = iVar3;
    do {
        piVar4[-2] = iVar1;
        *piVar4 = iVar3;
        piVar4 = piVar4 + 7;
    } while ((int)piVar4 < 0x8bf32c);
    FUN_004f4de0();
    FUN_004f0dc0();
    SetCursor(hCursor_00);
}

// 0x4842f0 — observed shape
// Multiple non-contiguous ranges 0x4842f0..0x484b95; audio/sfx + state loop.
// NEEDS_MANUAL: body elided in corpus view; observed prologue (DAT_0085a164 bit 0x100000, FUN_00412900) preserved.
void FUN_004842f0(void) {
    if ((_DAT_0085a164 & 0x100000) != 0) {
        int iVar8 = DAT_0085a268 / 3;
        FUN_00412900(0, (DAT_0085a268 - (uint32_t)iVar8) + -0x51, 100);
    }
    // Middle conditional state machine 0x4842f0:62-317 elided in view — see listing.
}

// 0x484bd0 — observed shape
// Two ranges; timing/interp loop and tail clamp. Observed prologue/tail preserved.
void FUN_00484bd0(void) {
    int iVar12 = 0;
    (void)iVar12;
    // Prologue if/else on DAT_008beb04, FUN_00412840, main 0..0x54 loop elided — see listing 0x484bd0:44-234.
    if (DAT_008cac44 < 0.0) DAT_008cac44 = 0.0;
    uint32_t uVar18 = FUN_005f0ddc();
    iVar12 = 6 - DAT_008bf0dc;
    FUN_004db210();
    int iVar5 = DAT_008bf0cc - FUN_004db210();
    int iVar6 = DAT_008bf0d0 - FUN_004db210();
    int local_5c = 1;
    int iVar7 = DAT_008bf0d8;
    (void)uVar18; (void)iVar5; (void)iVar6; (void)local_5c; (void)iVar7; (void)iVar12;
    // Tail spin: do { DVar10=timeGetTime() } while ((DVar10-DAT_008ed618)-DAT_008caac8 < 0x1e)
    // Epilogue:
    DAT_008caac8 = timeGetTime() - DAT_008ed618;
}

// 0x485380 — observed shape
// NEEDS_MANUAL: large non-contiguous (0x485380..0x48622c + 0x486230..0x48625b) body not in view; signature preserved.
void FUN_00485380(int param_1, int param_2, uint8_t* param_3) {
    (void)param_1; (void)param_2; (void)param_3;
    // Body is 557 lines in corpus; requires full listing read to reconstruct.
}

// 0x4862a0 — observed shape
// Counter DAT_008be9e4++, branch on DAT_008be9d4 (8 vs else), af080/ddadc0/bbc80 calls.
void FUN_004862a0(void) {
    uint32_t iVar4 = DAT_008be9d0;
    DAT_008be9e4 = DAT_008be9e4 + 1;
    if (DAT_008be9d4 != 0xc && DAT_008be9d4 != 0xd) {
        FUN_004af080(DAT_008e66ec,0,0,0x400,0x300,0,0,DAT_0085a26c,DAT_0085a268,0xffffffffu,0x200);
    }
    DAT_007263bc = DAT_007263bc | 0x1000;
    uint32_t uVar3 = FUN_004dadc0(0,0,0);
    FUN_004bbc80(0,0,0,(void*)(uintptr_t)uVar3,100,0xffffffff,0);
    FUN_004dadc0(0,0,0);
    FUN_004bbc80(0,0,0,nullptr,100,0,DAT_008c8494 - DAT_008caac8);
    uVar3 = FUN_004dadc0(0,0,0);
    FUN_004bbc80(0,0,0,(void*)(uintptr_t)uVar3,100,0,DAT_008c8494 - DAT_008caac8);
    FUN_004dadc0(0,0,0);
    FUN_004bbc80(0,0,0,nullptr,100,0,DAT_008c8494 - DAT_008caac8);
    (void)iVar4;
    // Middle branches on DAT_008be9d4==8/0xc/0xd and DAT_008cab04 tail elided — see listing 0x4862a0:109-152.
}

// 0x4867b0 — observed shape
// Teardown: pop DAT_007263bc frame, release DAT_008e66ec + DAT_008caae4..DAT_008cab08, restore frame.
void FUN_004867b0(void) {
    uint32_t* puVar2;
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = *(uint32_t*)(&DAT_007268f4 + DAT_00726a84 * 4);
    FUN_004ae4f0();
    if ((void*)DAT_008cab08 != 0) {
        FUN_004c1150(DAT_008caae4, "fx_candle");
    }
    puVar2 = (uint32_t*)DAT_008e66ec;
    if ((void*)DAT_008e66ec != 0) {
        int iVar3 = (int)puVar2[1];
        puVar2[1] = iVar3 + -1;
        if (iVar3 + -1 == 0) {
            typedef void(__thiscall* DelFn)(void*, int);
            ((DelFn)(*(puVar2)))(puVar2, 1);
        }
        DAT_008e66ec = 0;
    }
    if ((void*)DAT_008caae4 != 0) { uint32_t* p=(uint32_t*)DAT_008caae4; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caae4=0; }
    if ((void*)DAT_008caae8 != 0) { uint32_t* p=(uint32_t*)DAT_008caae8; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caae8=0; }
    if ((void*)DAT_008caaec != 0) { uint32_t* p=(uint32_t*)DAT_008caaec; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caaec=0; }
    if ((void*)DAT_008caaf0 != 0) { uint32_t* p=(uint32_t*)DAT_008caaf0; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caaf0=0; }
    if ((void*)DAT_008caaf4 != 0) { uint32_t* p=(uint32_t*)DAT_008caaf4; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caaf4=0; }
    if ((void*)DAT_008caaf8 != 0) { uint32_t* p=(uint32_t*)DAT_008caaf8; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caaf8=0; }
    if ((void*)DAT_008caafc != 0) { uint32_t* p=(uint32_t*)DAT_008caafc; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caafc=0; }
    if ((void*)DAT_008cab00 != 0) { uint32_t* p=(uint32_t*)DAT_008cab00; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008cab00=0; }
    if ((void*)DAT_008cab04 != 0) { uint32_t* p=(uint32_t*)DAT_008cab04; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008cab04=0; }
    if ((void*)DAT_008cab08 != 0) { uint32_t* p=(uint32_t*)DAT_008cab08; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008cab08=0; }
    DAT_00726ae8 = DAT_008e66c0;
    uint32_t iVar3 = DAT_00726820 + -1;
    DAT_00726aec = DAT_008e66c4;
    uint8_t cVar1 = (&DAT_00726813)[DAT_00726820];
    DAT_00726af0 = DAT_008e66c8;
    DAT_00726820 = iVar3;
    if (cVar1 != DAT_00725d98) {
        if (cVar1 == '\0') FUN_00481100();
        else FUN_00481140();
    }
    DAT_008c9df4 = 1;
    DAT_00725d98 = cVar1;
    FUN_004e2df0();
    if (DAT_008be9d4 == 0xd && DAT_008c827f != '\0') {
        FUN_00489130(DAT_008c8288);
        DAT_008c827f = '\0';
    }
}

// 0x486990 — observed shape
// NEEDS_MANUAL: ~293-line body elided in corpus view; signature (uint, u8*) preserved.
void FUN_00486990(uint32_t param_1, uint8_t* param_2) {
    (void)param_1; (void)param_2;
}

// 0x487200 — observed shape
// af080 + flag 0x1000; AL/ECX register inputs select bbc10 vs bbc80 path.
void FUN_00487200(char in_al, uint32_t in_ecx) {
    FUN_004af080(DAT_008e66ec,0,0,0x400,0x300,0,0,DAT_0085a26c,DAT_0085a268,0xffffffffu,0x200);
    DAT_007263bc = DAT_007263bc | 0x1000;
    if (DAT_008be9cc != '\0' && DAT_008be9cf == '\0' && DAT_008be9ce == '\0') {
        uint32_t uVar8 = 0;
        uint32_t uVar7 = 0x5c;
        uint32_t uVar6;
        int iVar1;
        if (in_al == '\0') {
            FUN_004bbc10(DAT_008caae4,0x1c2,0x5c,0,0,0,0,0xffffffffu,0);
            iVar1 = DAT_008be9c8;
            if (DAT_008be9c8 == 0) iVar1 = DAT_008be9d8;
            FUN_004bbc10(DAT_008caae8,0x1c2,0x50,0,0xf8e38e39u,0,0,iVar1,in_ecx);
            uVar8 = 0xf8e38e39u;
            uVar7 = 0x50;
            uVar6 = DAT_008caaec;
            iVar1 = DAT_008be9c8;
        } else {
            uVar6 = DAT_008caae4;
            iVar1 = -1;
            in_ecx = 0;
        }
        FUN_004bbc10(uVar6,0x1c2,uVar7,0,uVar8,0,0,iVar1,in_ecx);
        FUN_00412840(0x41c80000u,0x44268000u);
        FUN_00489360(0x1ae,0x55,200,0,0x20000000u);
        return;
    }
    uint32_t uVar7 = FUN_004dadc0(0,0,0);
    if (in_al == '\0') {
        FUN_004bbc80(0x19a,0xa2,0,nullptr,100,0xffffffff,0);
        int iVar1 = DAT_008be9c8;
        if (DAT_008be9c8 == 0) iVar1 = DAT_008be9d8;
        FUN_004bbc10(DAT_008caae8,0x19a,0x96,0,0,0,0,iVar1,in_ecx);
        FUN_004bbc10(DAT_008caaec,0x19a,0x96,0,0,0,0,DAT_008be9c8,in_ecx);
    } else {
        FUN_004bbc80(0x19a,0xa2,0,(void*)(uintptr_t)uVar7,100,0xffffffff,0);
    }
    FUN_00412840(0x41c80000u,0x44268000u);
    int iVar2 = FUN_004db210();
    uint32_t uVar5 = (uint32_t)-iVar2;
    int iVar1 = 1;
    int iVar3 = (int)uVar5;
    int iVar4 = (iVar3 ^ (iVar3 >> 0x1f)) - (iVar3 >> 0x1f);
    while (32000 < iVar4) {
        uVar5 = (int)uVar5 / 2;
        iVar1 = iVar1 * 2;
        iVar3 = (int)uVar5;
        iVar4 = (iVar3 ^ (iVar3 >> 0x1f)) - (iVar3 >> 0x1f);
    }
    iVar2 = FUN_004953d0(0,0,0,0);
    int iVar3b = FUN_004db210();
    int iVar4b = FUN_004953d0(0xe0000000u,0x71c71c7u,0,0x20000000u);
    FUN_004ad0c0(0x1ae - iVar2 * iVar1, 0x14 - iVar3b, iVar4b + 0x55);
}

// 0x4874e0 — observed shape
// Mode param_1 (-2→-1); rescales by flags; calls 487200 twice with d0cd0 between.
// NEEDS_MANUAL: mid body 0x4874e0:25-143 elided; prologue/epilogue preserved.
void FUN_004874e0(int param_1) {
    DAT_00722734 = 0xfffffffe;
    if (param_1 == -2) param_1 = -1;
    FUN_00487200(0,0);
    DAT_008cac44 = DAT_008cab0c;
    DAT_008cab0c = 0.0;
    FUN_004d0cd0(0,0,0);
    FUN_00487200(0,0);
}

// 0x487850 — observed shape
// If DAT_008be9cf/ce set render+reset; pop frame; release 008e66ec/ae4/ae8/aec; restore.
void FUN_00487850(void) {
    if (DAT_008be9cf != '\0' || DAT_008be9ce != '\0') {
        FUN_00487200(0,0);
        DAT_008cac44 = *(float*)(uint32_t[]){0x3f800000};
        FUN_004d0cd0(0,0,0);
    }
    uint32_t* puVar2 = (uint32_t*)DAT_008e66ec;
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = *(uint32_t*)(&DAT_007268f4 + DAT_00726a84 * 4);
    if ((void*)DAT_008e66ec != 0) {
        int iVar3 = (int)puVar2[1];
        puVar2[1] = iVar3 + -1;
        if (iVar3 + -1 == 0) {
            typedef void(__thiscall* D)(void*, int);
            ((D)(*(puVar2)))(puVar2, 1);
        }
        DAT_008e66ec = 0;
    }
    if ((void*)DAT_008caae4 != 0) { uint32_t* p=(uint32_t*)DAT_008caae4; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caae4=0; }
    if ((void*)DAT_008caae8 != 0) { uint32_t* p=(uint32_t*)DAT_008caae8; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caae8=0; }
    if ((void*)DAT_008caaec != 0) { uint32_t* p=(uint32_t*)DAT_008caaec; typedef void(__thiscall* D)(void*,int); ((D)(*(p)))(p,1); DAT_008caaec=0; }
    DAT_00726af0 = DAT_008e66c8;
    uint32_t iVar3 = DAT_00726820 + -1;
    uint8_t cVar1 = (&DAT_00726813)[DAT_00726820];
    DAT_00726ae8 = DAT_008e66c0;
    DAT_00726aec = DAT_008e66c4;
    DAT_00726820 = iVar3;
    if (cVar1 != DAT_00725d98) {
        if (cVar1 == '\0') FUN_00481100();
        else FUN_00481140();
    }
    DAT_00725d98 = cVar1;
    DAT_008c9df4 = 1;
    DAT_008be9cf = 0;
    DAT_008be9ce = 0;
    DAT_008be9cd = 0;
    DAT_008be9cc = 0;
}

// 0x4879c0 — observed shape
// Walk linked list via vtable+4; return 1 if param_1 found.
uint32_t FUN_004879c0(int param_1, int* param_2) {
    if (param_2 == 0) return 0;
    typedef int(__thiscall* HeadFn)(void*);
    int iVar1 = ((HeadFn)(*(uint32_t*)param_2 + 4))((void*)param_2);
    for (; iVar1 != 0; iVar1 = *(int*)(iVar1 + 4)) {
        if (iVar1 == param_1) return 1;
    }
    return 0;
}

// 0x487ce0 — observed shape
// FUN_004879f0-gated string scan (strchr 10); std::string cleanup via operator_delete, SCRATCH at 0x869b48.
uint8_t FUN_00487ce0(int in_eax) {
    uint8_t local_c[4];
    char* local_8 = nullptr;
    local_c[0] = 0;
    int iVar2 = FUN_004879f0(0,0);
    if (iVar2 < 1) return 0;
    FUN_00412cb0();
    // String ops incl. two guarded branches elided — see listing 0x487ce0:34-88.
    // Epilogue cleanup:
    char* p = local_8;
    if (p != 0 && p != (char*)&DAT_008cacc8) {
        // operator_delete__(p)
    }
    return 0;
}

// 0x487e90 — observed shape
// Save 0x1000 to stack, verify FUN_004879f0>=4, retry loop with 00509500.
int FUN_00487e90(int in_ecx) {
    uint8_t local_1000[4092 + 4];
    (void)in_ecx;
    std::memcpy(local_1000, DAT_00869b48, 0x1000);
    int iVar1 = FUN_004879f0(0,0);
    if (iVar1 < 4) return iVar1;
    DAT_008c9de0 = DAT_008c9dd8;
    FUN_00509500(DAT_008c9dd8, DAT_00869b48, 0);
    int iVar2 = DAT_0085a26c * 7;
    int iVar3 = FUN_005f0ddc();
    while ((iVar3 < (iVar2 + (iVar2 >> 0x1f & 7)) >> 3) && (3 < iVar1)) {
        std::memcpy(DAT_00869b48, local_1000, 0x1000);
        in_ecx = in_ecx + 2;
        iVar1 = FUN_004879f0(in_ecx, 0);
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500(DAT_008c9dd8, DAT_00869b48, 0);
        iVar3 = FUN_005f0ddc();
    }
    return iVar1;
}

// 0x487fd0 — observed shape
// Tokeniser check via FUN_00487ce0; timing gates via FUN_005f0ddc; two cleanup branches.
// NEEDS_MANUAL: mid branches 0x487fd0:39-101 elided; signature and gates preserved.
uint8_t FUN_00487fd0(int param_1, int param_2) {
    uint8_t uVar3 = FUN_00487ce0(0);
    FUN_004aef70(DAT_00869b48);
    int iVar4 = FUN_005f0ddc();
    if (iVar4 <= param_1) return uVar3;
    FUN_00412cb0();
    FUN_004aef70(DAT_00709e64);
    iVar4 = FUN_005f0ddc();
    (void)param_2;
    return 1;
}

// 0x4881b0 — observed shape
// 9-tile atlas blit setup: clamp ECX/EAX to 0x20, align 0xfffffff0, cddf0+af080 per tile.
void FUN_004881b0(int param_1, int param_2, int in_eax, int in_ecx) {
    int iVar1 = param_1;
    if (in_ecx < 0x20) in_ecx = 0x20;
    if (in_eax < 0x20) in_eax = 0x20;
    param_2 = param_2 + 0x10;
    int iVar3 = param_1 + 0x10;
    int iVar4 = (in_ecx + 0xfU & 0xfffffff0u) - 0x20;
    int iVar5 = (in_eax + 0xfU & 0xfffffff0u) - 0x20;
    int local_10 = 0x10;
    int local_c = 0x10;
    int local_8 = 0x10;
    int local_4 = 0;
    (void)local_4;
    uint32_t uVar2 = FUN_004cddf0(DAT_008e66f0,0,0,&local_10,&local_c);
    int w = local_10, h = local_c;
    FUN_004af080(uVar2,0,0,w,h,iVar1,local_c - 0x10,0x10,0x10,0xffffffffu,0);
    local_10 = 0x10; local_c = 0x10;
    uVar2 = FUN_004cddf0(DAT_008e66f0,0x10,0,&local_10,&local_c);
    FUN_004af080(uVar2,0x10,0,local_10,local_c,iVar3,local_c - 0x10,iVar4,0x10,0xffffffffu,0);
    local_10 = 0x1f; local_c = 0x10;
    uVar2 = FUN_004cddf0(DAT_008e66f0,0x20,0,&local_10,&local_c);
    int local_4b = iVar4 + iVar3;
    FUN_004af080(uVar2,0x20,0,local_10,local_c,local_4b,local_c - 0x10,0x1f,0x10,0xffffffffu,0);
    local_10 = 0x10; local_c = 0x10;
    uVar2 = FUN_004cddf0(DAT_008e66f0,0,0x10,&local_c,&local_10);
    FUN_004af080(uVar2,0,0x10,local_c,local_10,local_8,param_2,0x10,iVar5,0xffffffffu,0);
    local_10 = 0x10; local_c = 0x10;
    uVar2 = FUN_004cddf0(DAT_008e66f0,0x10,0x10,&local_c,&local_10);
    FUN_004af080(uVar2,0x10,0x10,local_c,local_10,iVar3,param_2,iVar4,iVar5,0xffffffffu,0);
    local_10 = 0x1f; local_c = 0x10;
    uVar2 = FUN_004cddf0(DAT_008e66f0,0x20,0x10,&local_c,&local_10);
    FUN_004af080(uVar2,0x20,0x10,local_c,local_10,local_4b,param_2,0x1f,iVar5,0xffffffffu,0);
    local_10 = 0x10; local_c = 0x10;
    int pw = 0x10, ph = 0x1f;
    uVar2 = FUN_004cddf0(DAT_008e66f0,0,0x20,&local_c,&pw);
    int iVar5b = iVar5 + param_2;
    FUN_004af080(uVar2,0,0x20,local_c,pw,local_8,iVar5b,0x10,0x1f,0xffffffffu,0);
    ph = 0x1f; pw = 0x10;
    uVar2 = FUN_004cddf0(DAT_008e66f0,0x10,0x20,&pw,&ph);
    FUN_004af080(uVar2,0x10,0x20,pw,ph,iVar3,iVar5b,iVar4,0x1f,0xffffffffu,0);
    ph = 0x1f; pw = 0x1f;
    uVar2 = FUN_004cddf0(DAT_008e66f0,0x20,0x20,&pw,&ph);
    FUN_004af080(uVar2,0x20,0x20,pw,ph,local_4b,iVar5b,0x1f,0x1f,0xffffffffu,0);
}
