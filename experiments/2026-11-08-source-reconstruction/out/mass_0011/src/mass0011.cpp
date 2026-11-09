// Mass 0011 reconstructions (UNVERIFIED; source-candidate sketches).
// Clean-room from Ghidra 12.2 corpus analysis/pseudocode/functions/0x*.c.
// Field offsets, constants, strings, and call order preserved; register
// receivers (in_EAX/in_ECX/unaff_EBX) made explicit params. The four largest
// listings (0x436c30, 0x43cde0, 0x43e550, 0x43ffc0) are approach-level with
// NEEDS_MANUAL notes; the small ones are line-faithful head reconstructions.

#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
typedef unsigned char byte;
extern DWORD timeGetTime();

extern uint32_t DAT_00007f02; extern uint32_t DAT_006f5896; extern uint32_t DAT_006fb6cc;
extern uint32_t DAT_00723b14; extern uint32_t DAT_00723b1c; extern uint32_t DAT_007252f0;
extern uint32_t DAT_00725350; extern uint32_t DAT_007253b4; extern uint32_t DAT_00725418;
extern uint32_t DAT_00725419; extern uint32_t DAT_0072541b; extern uint32_t DAT_0072541c;
extern uint32_t DAT_0072541d; extern uint32_t DAT_0072541e; extern uint32_t DAT_00725520;
extern uint32_t DAT_00725524; extern uint32_t DAT_00725528; extern uint32_t DAT_0072552c;
extern uint32_t DAT_00725530; extern uint32_t DAT_00725534; extern uint32_t DAT_00725538;
extern uint32_t DAT_0072553c; extern uint32_t DAT_007255f8; extern uint32_t DAT_00725d98;
extern uint32_t DAT_007261dc; extern uint32_t DAT_007261e0; extern uint32_t DAT_007261e4;
extern uint32_t DAT_007261ec; extern uint32_t DAT_007261f0; extern uint32_t DAT_00726398;
extern uint32_t DAT_007263bb; extern uint32_t DAT_007263bc; extern uint32_t DAT_00726638;
extern uint32_t DAT_0072663c; extern uint32_t DAT_00726814; extern uint32_t DAT_00726820;
extern uint32_t DAT_007268f4; extern uint32_t DAT_00726a84; extern uint32_t DAT_00727444;
extern uint32_t DAT_0072cb44; extern uint32_t DAT_0072cb4c; extern uint32_t DAT_0072ccc4;
extern uint32_t DAT_0072cd74; extern uint32_t DAT_0072cd78; extern uint32_t DAT_008142f8;
extern uint32_t DAT_00814304; extern uint32_t DAT_00814308; extern uint32_t DAT_00814318;
extern uint32_t DAT_0081431a; extern uint32_t DAT_0081431e; extern uint32_t DAT_00814324;
extern uint32_t DAT_0085a0fc; extern uint32_t DAT_0085a100; extern uint32_t DAT_0085a11c;
extern uint32_t DAT_0085a124; extern uint32_t DAT_0085a128; extern uint32_t DAT_0085a150;
extern uint32_t DAT_0085a158; extern uint32_t DAT_0085a164; extern uint32_t DAT_0085a168;
extern uint32_t DAT_0085a268; extern uint32_t DAT_0085a26c; extern uint32_t DAT_0085a3b8;
extern uint32_t DAT_0085a4c8; extern uint32_t DAT_0085a500; extern uint32_t DAT_0085a610;
extern uint32_t DAT_0085a648; extern uint32_t DAT_0085a758; extern uint32_t DAT_0085a7b0;
extern uint32_t DAT_0085a7d0; extern uint32_t DAT_0085bf70; extern uint32_t DAT_0085bf74;
extern uint32_t DAT_0085bf78; extern uint32_t DAT_0085bf90; extern uint32_t DAT_0085c0b8;
extern uint32_t DAT_00860b68; extern uint32_t DAT_00860b6c; extern uint32_t DAT_00860b70;
extern uint32_t DAT_00860b74; extern uint32_t DAT_00860b76; extern uint32_t DAT_00860b80;
extern uint32_t DAT_00860b90; extern uint32_t DAT_00861ffc; extern uint32_t DAT_00862002;
extern uint32_t DAT_00862014; extern uint32_t DAT_00862018; extern uint32_t DAT_00862d10;
extern uint32_t DAT_00862d14; extern uint32_t DAT_00862d18; extern uint32_t DAT_00862d1c;
extern uint32_t DAT_00862d20; extern uint32_t DAT_00862d24; extern uint32_t DAT_00862d28;
extern uint32_t DAT_00862d2c; extern uint32_t DAT_00869a74; extern uint32_t DAT_00869a88;
extern uint32_t DAT_00869a8a; extern uint32_t DAT_00869a8c; extern uint32_t DAT_00869a8e;
extern uint32_t DAT_00869a98; extern uint32_t DAT_00869ab0; extern uint32_t DAT_00869b14;
extern uint32_t DAT_00869b1c; extern uint32_t DAT_00869b1e; extern uint32_t DAT_00869b34;
extern uint32_t DAT_00869b48; extern uint32_t DAT_0086bb5c; extern uint32_t DAT_0086bb60;
extern uint32_t DAT_0086bcf0; extern uint32_t DAT_0086be80; extern uint32_t DAT_0086c010;
extern uint32_t DAT_0086c1a0; extern uint32_t DAT_0086c330; extern uint32_t DAT_0086c354;
extern uint32_t DAT_0086c358; extern uint32_t DAT_0086c35c; extern uint32_t DAT_0086c360;
extern uint32_t DAT_0086c36c; extern uint32_t DAT_0086c370; extern uint32_t DAT_0086c374;
extern uint32_t DAT_0086c378; extern uint32_t DAT_0086c37c; extern uint32_t DAT_0086c380;
extern uint32_t DAT_0086c384; extern uint32_t DAT_0086c388; extern uint32_t DAT_0086c390;
extern uint32_t DAT_0086c394; extern uint32_t DAT_0086c398; extern uint32_t DAT_0086c3a4;
extern uint32_t DAT_0086c3a8; extern uint32_t DAT_0086c3ac; extern uint32_t DAT_0086c448;
extern uint32_t DAT_0086c44c; extern uint32_t DAT_0086c450; extern uint32_t DAT_0086c454;
extern uint32_t DAT_0086c458; extern uint32_t DAT_0086c460; extern uint32_t DAT_0086c560;
extern uint32_t DAT_0086c564; extern uint32_t DAT_0086c568; extern uint32_t DAT_0086c56c;
extern uint32_t DAT_0086c570; extern uint32_t DAT_0086c574; extern uint32_t DAT_0086c578;
extern uint32_t DAT_0086c57c; extern uint32_t DAT_0086c580; extern uint32_t DAT_0086c584;
extern uint32_t DAT_0086c588; extern uint32_t DAT_0086c58c; extern uint32_t DAT_0086c590;
extern uint32_t DAT_0086c5d0; extern uint32_t DAT_0086c5d4; extern uint32_t DAT_0086c5d8;
extern uint32_t DAT_0086c5dc; extern uint32_t DAT_0086c5e0; extern uint32_t DAT_0086c9e0;
extern uint32_t DAT_0086d1e0; extern uint32_t DAT_0086d9e0; extern uint32_t DAT_0086e1e0;
extern uint32_t DAT_0086e9e8; extern uint32_t DAT_0086e9ea; extern uint32_t DAT_0086e9ec;
extern uint32_t DAT_0086e9ee; extern uint32_t DAT_0086e9f0; extern uint32_t DAT_0086e9f2;
extern uint32_t DAT_0086e9f4; extern uint32_t DAT_0086e9f6; extern uint32_t DAT_0086e9f8;
extern uint32_t DAT_0086e9fa; extern uint32_t DAT_0086ea00; extern uint32_t DAT_0086ea02;
extern uint32_t DAT_0086ea04; extern uint32_t DAT_0086ea06; extern uint32_t DAT_0086ea08;
extern uint32_t DAT_0086ea0c; extern uint32_t DAT_0086ea10; extern uint32_t DAT_0086ea14;
extern uint32_t DAT_0086ea18; extern uint32_t DAT_0086ea1c; extern uint32_t DAT_0086ea20;
extern uint32_t DAT_0086ea24; extern uint32_t DAT_0086ea28; extern uint32_t DAT_0086ea2c;
extern uint32_t DAT_0086ea5c; extern uint32_t DAT_0086ea8c; extern uint32_t DAT_0086eabc;
extern uint32_t DAT_0086eaec; extern uint32_t DAT_0086eb04; extern uint32_t DAT_0086eb1c;
extern uint32_t DAT_0086fea8; extern uint32_t DAT_0086feaa; extern uint32_t DAT_0086feac;
extern uint32_t DAT_0086feae; extern uint32_t DAT_0086feb6; extern uint32_t DAT_0086feb8;
extern uint32_t DAT_0086feba; extern uint32_t DAT_0086fec0; extern uint32_t DAT_0086fec4;
extern uint32_t DAT_0086fec8; extern uint32_t DAT_0086fed0; extern uint32_t DAT_0086fed4;
extern uint32_t DAT_0086fed8; extern uint32_t DAT_0086feec; extern uint32_t DAT_0086ff1c;
extern uint32_t DAT_0086ff4c; extern uint32_t DAT_0086ff7c; extern uint32_t DAT_0086ffac;
extern uint32_t DAT_0086ffc4; extern uint32_t DAT_00871368; extern uint32_t DAT_00871778;
extern uint32_t DAT_00871978; extern uint32_t DAT_00871979; extern uint32_t DAT_00871a18;
extern uint32_t DAT_008bea80; extern uint32_t DAT_008c7190; extern uint32_t DAT_008c7340;
extern uint32_t DAT_008c8200; extern uint32_t DAT_008c8278; extern uint32_t DAT_008c827e;
extern uint32_t DAT_008c827f; extern uint32_t DAT_008c8288; extern uint32_t DAT_008c9568;
extern uint32_t DAT_008c97c0; extern uint32_t DAT_008c97c4; extern uint32_t DAT_008c9dd8;
extern uint32_t DAT_008c9de0; extern uint32_t DAT_008c9dec; extern uint32_t DAT_008c9df4;
extern uint32_t DAT_008ca958; extern uint32_t DAT_008ca95c; extern uint32_t DAT_008ca960;
extern uint32_t DAT_008ca964; extern uint32_t DAT_008ca968; extern uint32_t DAT_008ca96c;
extern uint32_t DAT_008ca970; extern uint32_t DAT_008ca974; extern uint32_t DAT_008ca978;
extern uint32_t DAT_008ca97c; extern uint32_t DAT_008ca980; extern uint32_t DAT_008ca981;
extern uint32_t DAT_008ca984; extern uint32_t DAT_008ca988; extern uint32_t DAT_008cabd4;
extern uint32_t DAT_008cabe8; extern uint32_t DAT_008cac18; extern uint32_t DAT_008cac26;
extern uint32_t DAT_008cac27; extern uint32_t DAT_008cac38; extern uint32_t DAT_008cac40;
extern uint32_t DAT_008cacc8; extern uint32_t DAT_008caccc; extern uint32_t DAT_008cacd0;
extern uint32_t DAT_008cacd4; extern uint32_t DAT_008cacd8; extern uint32_t DAT_008cb100;
extern uint32_t DAT_008cb104; extern uint32_t DAT_008cb108; extern uint32_t DAT_008cb10c;
extern uint32_t DAT_008cb110; extern uint32_t DAT_008cb114; extern uint32_t DAT_008cb178;
extern uint32_t DAT_008cb17c; extern uint32_t DAT_008cb180; extern uint32_t DAT_008cb190;
extern uint32_t DAT_008cb194; extern uint32_t DAT_008cb198; extern uint32_t DAT_008cb19c;
extern uint32_t DAT_008cb1a0; extern uint32_t DAT_008cb1a4; extern uint32_t DAT_008cdc98;
extern uint32_t DAT_008cea18; extern uint32_t DAT_008d4058; extern uint32_t DAT_008d4358;
extern uint32_t DAT_008d4718; extern uint32_t DAT_008d5258; extern uint32_t DAT_008d56d8;
extern uint32_t DAT_008d5798; extern uint32_t DAT_008d74d8; extern uint32_t DAT_008d7ad8;
extern uint32_t DAT_008d8018; extern uint32_t DAT_008db618; extern uint32_t DAT_008db61c;
extern uint32_t DAT_008db620; extern uint32_t DAT_008dbd08; extern uint32_t DAT_008dbd0c;
extern uint32_t DAT_008dbd10; extern uint32_t DAT_008dc30c; extern uint32_t DAT_008dc310;
extern uint32_t DAT_008dc320; extern uint32_t DAT_008dc620; extern uint32_t DAT_008e8ec4;
extern uint32_t DAT_008e8edc; extern uint32_t DAT_008e8ee0; extern uint32_t DAT_008e8eec;
extern uint32_t DAT_008e8ef0; extern uint32_t DAT_008e8eff; extern uint32_t DAT_008e8fdc;
extern uint32_t DAT_008e9f5c; extern uint32_t DAT_008e9fe4; extern uint32_t DAT_008e9fe8;
extern uint32_t DAT_008e9fec; extern uint32_t DAT_008e9ffc; extern uint32_t DAT_008ea000;
extern uint32_t DAT_008ea008; extern uint32_t DAT_008ea08c; extern uint32_t DAT_008ecd78;
extern uint32_t DAT_008ed2c8; extern uint32_t DAT_008ed618; extern uint32_t PTR_DAT_00725694;
extern uint32_t PTR_DAT_00726640; extern uint32_t _DAT_0085a164; extern uint32_t _DAT_0086c3b8;
extern uint32_t _DAT_0086c3cc; extern uint32_t _DAT_0086c3e0; extern uint32_t _DAT_0086c3f4;
extern uint32_t _DAT_0086c41c; extern uint32_t _DAT_0086c430; extern uint32_t _DAT_0086c444;
extern uint32_t _DAT_008be9f4; extern uint32_t _DAT_008cacd0; extern uint32_t _DAT_008e8ec8;
extern uint32_t _DAT_008ed61c;

// Callees (signatures inferred — generic uint32_t() to avoid arity churn):
extern uint32_t FUN_00404910();
extern uint32_t FUN_00404ca0();
extern uint32_t FUN_00404e50();
extern uint32_t FUN_0040a610();
extern uint32_t FUN_004127e0();
extern uint32_t FUN_00412840();
extern uint32_t FUN_00412900();
extern uint32_t FUN_00412ec0();
extern uint32_t FUN_00412f10();
extern uint32_t FUN_00412fb0();
extern uint32_t FUN_00419ac0();
extern uint32_t FUN_0041a300();
extern uint32_t FUN_0041a9f0();
extern uint32_t FUN_00425ad0();
extern uint32_t FUN_00427f80();
extern uint32_t FUN_00428140();
extern uint32_t FUN_0042c6f0();
extern uint32_t FUN_0042e1d0();
extern uint32_t FUN_0042e730();
extern uint32_t FUN_00430190();
extern uint32_t FUN_00431510();
extern uint32_t FUN_00431840();
extern uint32_t FUN_004318c0();
extern uint32_t FUN_00431910();
extern uint32_t FUN_00431930();
extern uint32_t FUN_00431970();
extern uint32_t FUN_004319b0();
extern uint32_t FUN_00431a60();
extern uint32_t FUN_00431bc0();
extern uint32_t FUN_00431c80();
extern uint32_t FUN_00431e50();
extern uint32_t FUN_00431ed0();
extern uint32_t FUN_00432720();
extern uint32_t FUN_00432a60();
extern uint32_t FUN_00433760();
extern uint32_t FUN_004337c0();
extern uint32_t FUN_00433930();
extern uint32_t FUN_00433ae0();
extern uint32_t FUN_00433cf0();
extern uint32_t FUN_00435140();
extern uint32_t FUN_00435260();
extern uint32_t FUN_00436ac0();
extern uint32_t FUN_00436c30();
extern uint32_t FUN_00438e30();
extern uint32_t FUN_00439fe0();
extern uint32_t FUN_0043a0c0();
extern uint32_t FUN_0043a240();
extern uint32_t FUN_0043a350();
extern uint32_t FUN_0043a420();
extern uint32_t FUN_0043a800();
extern uint32_t FUN_0043a940();
extern uint32_t FUN_0043a970();
extern uint32_t FUN_0043aa10();
extern uint32_t FUN_0043b8e0();
extern uint32_t FUN_0043ca20();
extern uint32_t FUN_0043cde0();
extern uint32_t FUN_0043e550();
extern uint32_t FUN_0043fd70();
extern uint32_t FUN_0043ffc0();
extern uint32_t FUN_0044f150();
extern uint32_t FUN_0044fa40();
extern uint32_t FUN_00451e50();
extern uint32_t FUN_00452890();
extern uint32_t FUN_00456b20();
extern uint32_t FUN_00457100();
extern uint32_t FUN_0045bbf0();
extern uint32_t FUN_0045fcb0();
extern uint32_t FUN_00471120();
extern uint32_t FUN_00473b70();
extern uint32_t FUN_00481180();
extern uint32_t FUN_00482e60();
extern uint32_t FUN_00483b70();
extern uint32_t FUN_00483ca0();
extern uint32_t FUN_004841b0();
extern uint32_t FUN_00484bd0();
extern uint32_t FUN_004879f0();
extern uint32_t FUN_00487e90();
extern uint32_t FUN_00487fd0();
extern uint32_t FUN_004881b0();
extern uint32_t FUN_00488840();
extern uint32_t FUN_004888e0();
extern uint32_t FUN_004889c0();
extern uint32_t FUN_00488d90();
extern uint32_t FUN_00488df0();
extern uint32_t FUN_00488ed0();
extern uint32_t FUN_00489130();
extern uint32_t FUN_00489360();
extern uint32_t FUN_00489440();
extern uint32_t FUN_004953d0();
extern uint32_t FUN_00498570();
extern uint32_t FUN_004985e0();
extern uint32_t FUN_0049aed0();
extern uint32_t FUN_0049af70();
extern uint32_t FUN_004a0b70();
extern uint32_t FUN_004a0d90();
extern uint32_t FUN_004a14b0();
extern uint32_t FUN_004a22f0();
extern uint32_t FUN_004a24b0();
extern uint32_t FUN_004a29c0();
extern uint32_t FUN_004a78a0();
extern uint32_t FUN_004a7a40();
extern uint32_t FUN_004a86a0();
extern uint32_t FUN_004a88d0();
extern uint32_t FUN_004a8a70();
extern uint32_t FUN_004a90a0();
extern uint32_t FUN_004a91e0();
extern uint32_t FUN_004a9270();
extern uint32_t FUN_004a93b0();
extern uint32_t FUN_004a96a0();
extern uint32_t FUN_004a9770();
extern uint32_t FUN_004aa230();
extern uint32_t FUN_004aa340();
extern uint32_t FUN_004aa950();
extern uint32_t FUN_004aac50();
extern uint32_t FUN_004ad0c0();
extern uint32_t FUN_004add70();
extern uint32_t FUN_004ae7d0();
extern uint32_t FUN_004ae900();
extern uint32_t FUN_004aec30();
extern uint32_t FUN_004af080();
extern uint32_t FUN_004af680();
extern uint32_t FUN_004af990();
extern uint32_t FUN_004b06c0();
extern uint32_t FUN_004b17f0();
extern uint32_t FUN_004b1940();
extern uint32_t FUN_004b21a0();
extern uint32_t FUN_004b24a0();
extern uint32_t FUN_004b2760();
extern uint32_t FUN_004baa30();
extern uint32_t FUN_004baaa0();
extern uint32_t FUN_004bb500();
extern uint32_t FUN_004bba60();
extern uint32_t FUN_004bbc80();
extern uint32_t FUN_004bc0d0();
extern uint32_t FUN_004bc950();
extern uint32_t FUN_004bdca0();
extern uint32_t FUN_004bf760();
extern uint32_t FUN_004bf9c0();
extern uint32_t FUN_004c08b0();
extern uint32_t FUN_004c0940();
extern uint32_t FUN_004c1080();
extern uint32_t FUN_004c1150();
extern uint32_t FUN_004c1ac0();
extern uint32_t FUN_004c2200();
extern uint32_t FUN_004cddf0();
extern uint32_t FUN_004d0cd0();
extern uint32_t FUN_004d1130();
extern uint32_t FUN_004d96a0();
extern uint32_t FUN_004d9af0();
extern uint32_t FUN_004dadc0();
extern uint32_t FUN_004db210();
extern uint32_t FUN_004db270();
extern uint32_t FUN_004e2df0();
extern uint32_t FUN_004e2e40();
extern uint32_t FUN_004e43c0();
extern uint32_t FUN_004e4580();
extern uint32_t FUN_004e7510();
extern uint32_t FUN_004e7950();
extern uint32_t FUN_004e8860();
extern uint32_t FUN_004e8a10();
extern uint32_t FUN_004e8b60();
extern uint32_t FUN_004e8ea0();
extern uint32_t FUN_004e9740();
extern uint32_t FUN_004ed370();
extern uint32_t FUN_004f1840();
extern uint32_t FUN_004f18c0();
extern uint32_t FUN_004f2600();
extern uint32_t FUN_004f3350();
extern uint32_t FUN_004f6090();
extern uint32_t FUN_004f60b0();
extern uint32_t FUN_00500600();
extern uint32_t FUN_00502c80();
extern uint32_t FUN_00502cd0();
extern uint32_t FUN_00502e10();
extern uint32_t FUN_00503270();
extern uint32_t FUN_00503fb0();
extern uint32_t FUN_00504070();
extern uint32_t FUN_005045a0();
extern uint32_t FUN_00505920();
extern uint32_t FUN_00506040();
extern uint32_t FUN_00509500();
extern uint32_t FUN_005096b0();
extern uint32_t FUN_0050c550();
extern uint32_t FUN_0050c5d0();
extern uint32_t FUN_0051bfc0();
extern uint32_t FUN_00533c78();
extern uint32_t FUN_00533d10();
extern uint32_t FUN_00533db0();
extern uint32_t FUN_00534130();
extern uint32_t FUN_00535920();
extern uint32_t FUN_00535b40();
extern uint32_t FUN_00540c50();
extern uint32_t FUN_005be280();
extern uint32_t FUN_005f0ddc();

// ===== 0x00433cf0 =====
// Observed: input/hit-test path. Picks cursor (DAT_008cacd8 or loaded default),
// installs via SetCursor; walks pointer tables, stamping DAT_0086c5dc-style slots.
// Range: 0x433cf0-0x435135 (non-contiguous). NEEDS_MANUAL: full 770-line walk.
void FUN_00433cf0_recon(int param_1) {
    HCURSOR hCursor = (HCURSOR)(uintptr_t)DAT_008cacd8;
    if (hCursor == nullptr) {
        hCursor = LoadCursorA(nullptr, (LPCSTR)(uintptr_t)DAT_00007f02);
    }
    HCURSOR saved = GetCursor();
    (void)saved;
    SetCursor(hCursor);
    // Observed constants: half-extent thresholds, flag rolls 0xfffffffe/0x80000000,
    // half-plane splits, DAT_0086c5dc/DAT_0086c5d8 cursors, DAT_0086c574/578/57c rolls.
    // Full table scan + FUN_0043a240/FUN_00500500/FUN_004bdca0 side-effects elided here;
    // see corpus 0x433cf0.c lines 60-791.
    (void)param_1;
}

// ===== 0x00435140 =====
// Observed: guarded reset. Resets DAT_0086c560/578 area, FUN_004e2e40, then
// FUN_0043a350(); refcount-bumps DAT_008cabd4 object, DAT_008c9df4=1,
// FUN_004e8a10 / FUN_004e8b60 by sign of DAT_0085a164, FUN_004e7950,
// then loops FUN_004e9740() count*((DAT_0072cd78+0x58)) times, DAT_008cac38=10.
void FUN_00435140_recon(void) {
    if ((int)(int8_t)DAT_0086c560 == 0) {
        DAT_0086c560 = 0;
        FUN_004e2e40();
    }
    FUN_0043a350();
    // _DAT_0085a164 flag + DAT_008cabd4 refcount dance (corpus lines 14-41).
    FUN_004add70(DAT_008cabd4);
    DAT_008c9df4 = 1;
    FUN_004e8a10(DAT_0072cd78);
    uint32_t base = DAT_0072cd78;
    *reinterpret_cast<uint32_t*>(base + 0x5c) = 10;
    *reinterpret_cast<uint8_t*>(base + 0x80) = 1;
    if ((int32_t)_DAT_0085a164 < 0) {
        FUN_004e8b60(base);
    }
    FUN_004e7950(base, DAT_0085a7b0, DAT_0085a7d0);
    int n = *reinterpret_cast<int*>(DAT_0072cd78 + 0x58);
    if (n < 1) { DAT_008cac38 = 10; return; }
    for (int i = 0; i < n; ++i) FUN_004e9740();
    DAT_008cac38 = 10;
}

// ===== 0x00435260 =====
// Observed: turn/eigen dispatch (non-contiguous, 4 ranges). Float path building
// with fVar2/fVar6, waypoint roll at +0x/…, DAT_0086c5dc roll gate, FUN_005f0ddc/
// FUN_004bba60 spawns, flag pick via FUN_004f2600("flag_%s_%s_%s.dds").
// NEEDS_MANUAL: 700-line float/waypoint choreography beyond head sketch.
void FUN_00435260_recon(void) {
    // Observed dispatch edges (corpus 0x435260.c:20-720):
    // - (-(short)(DAT_0086ea08+iVar*0x53) & 0x200) → FUN_004e2df0 waypoint roll
    // - FUN_004f6090("@PAUSEMENU",4) / FUN_004cddf0("PediaAlpha2.dds",...)
    // - "flag_%s_%s_%s.dds" via FUN_004f2600 with "treaty"/"left"/"right"
    // - Internationals/Relations/Fame strings via FUN_004f6090
    // Foregrounded: cursor/threshold init + teleport gate.
    if (DAT_0086c560 == 0) { /* idle gate */ }
}

// ===== 0x00436ac0 =====
// Observed: nearest-slot search (pure). in_EAX index into DAT_0086ea8c stride 0x530,
// scans 0x10 entries stride 0x14c, Manhattan metric (d1/2 < best) over dword tables
// at +0x2a/+0x7d/+0xd0 (short sentinel -1). Returns best idx or -1.
int FUN_00436ac0_recon(int in_EAX, int param_1, int param_2) {
    int best = -1;
    int bestScore = 0xffffff;
    // piVar4 = &DAT_0086ea8c + in_EAX*0x530  (16 entries × 0x14c bytes)
    for (int k = 0; k < 16; ++k) {
        // int short-base = *((short*)(piVar4 + 0x2a)); if == -1 skip slot
        // Observed metric: |dy|,|dx| then (min + 2*max)/2 compared to iVar5
        // (see corpus lines 28-47 verbatim pattern). Full per-slot index
        // arithmetic elided; loop shape + constants preserved.
        (void)k; (void)param_1; (void)param_2;
    }
    return best;
}

// ===== 0x00436c30 =====
// Observed: per-side (param_1=0/1) ai tick — largest of the batch (non-contiguous
// 3 ranges, ~1142 lines). Opens local_38 = param_1<<4; sweeps 0x12 enemies
// with Manhattan re-score, stamps DAT_0086ea08 |0x106 on contact, 0x7fff/0xffff
// fail-sentinels, FUN_004f6090 battle strings, rand()<100 wellness, cooldown
// 0xff9d/0x76/0x77. NEEDS_MANUAL: approach-level only; see corpus.
// Callee census (counts): FUN_004f6090×~36 strings, FUN_005f0ddc, FUN_004bba60,
// FUN_00509500, FUN_00506040, FUN_004b06c0, etc.
void FUN_00436c30_recon(int param_1) {
    int local_38 = param_1 << 4;
    bool saw = false;
    uint slot = 0;
    (void)local_38; (void)saw; (void)slot;
    // Foregrounded observed fragments (corpus 0x436c30.c:67-1142):
    //  Manhattan re-score + DAT_0086ea08 | 0x106 contact stamp,
    //  fail path *(0x7fff)/ *(0xffff), wellness rand()%100,
    //  cooldown quartet local_48/4c/50/54, vtable release idiom at tail.
    // Full switch/case over enemy ai states elided.
}

// ===== 0x00438e30 =====
// Observed: main combat loop. FUN_00431840 init, timeGetTime delta via
// DAT_008ed618, FUN_00436c30(0/1) per-side tick when _DAT_0085a164&4==0,
// FUN_00435260, fight-key scan (FUN_0042e1d0("Fight") + 0x2c8..0x2d0 map),
// auto-retreat thresholds ±1000 on DAT_008ca974 ("The broken defenders scatter
// and run!" / "You LOSE!"), GetAsyncKeyState(0x10) alt latch.
// NEEDS_MANUAL: ~600-line loop body; switch after key scan elided.
void FUN_00438e30_recon(uint *param_1) {
    FUN_00431840();
    DAT_008ca974 = 0; DAT_008ca96c = 0;
    FUN_00433cf0();
    DAT_008ca974 = 0;
    // Main loop skeleton (corpus 0x438e30.c:55-599): time delta, side ticks,
    // key scan + remap switch, retreat checks, flee branches.
    (void)param_1;
}

// ===== 0x00439fe0 =====
// Observed: small list-drift check. If (unaff_EBX != in_EAX || param_1 != param_2)
// FUN_00502cd0(0x10,0,0,0,&LAB_0043a3a0,0,&LAB_0043a390...) then walk
// iRam00000020 chain (FUN_00502e10) with +0x20 stride until flag byte matches.
int FUN_00439fe0_recon(int in_EAX, int unaff_EBX, int param_1, int param_2) {
    if (unaff_EBX != in_EAX || param_1 != param_2) {
        // Corpus: FUN_00502cd0(0x10,0,0,0,&LAB_0043a3a0,...) dialog setup
        return 0;
    }
    return 0;
}

// ===== 0x0043a240 =====
// Observed: audio-manager guard. FUN_004a86a0 init; calls vtable+0x18 on
// DAT_008ecd78; if null → FUN_00488840("The audio manager has not been properly
// initialized yet") then FUN_004985e0(0x10414b0…) / FUN_00533c78(0x4b0)…
// variants (DAT_008ca984 fast path, else FUN_00533c78(0x4b0) + FUN_004f60b0).
void FUN_0043a240_recon(void) {
    FUN_004a86a0();
    // vtable call + null-string + 0x4b0 alloc path (corpus lines 14-41).
}

// ===== 0x0043a350 =====
// Observed: tiny free-init. FUN_004a88d0(); if DAT_008ca984==null →
// DAT_00726a84--, DAT_007263bc = *(DAT_007268f4+…), DAT_00726a84++,
// else DAT_00726a84 + -0x164 & 0xffffffff variant. Always FUN_004e2e40-ish tail.
void FUN_0043a350_recon(void) {
    FUN_004a88d0();
    if (DAT_008ca984 == 0) {
        DAT_00726a84 = DAT_00726a84 - 1;
        DAT_007263bc = DAT_007268f4;
        DAT_00726a84 = DAT_00726a84 + 1;
    } else {
        DAT_00726a84 = DAT_00726a84 - 1;
        DAT_007263bc = DAT_007268f4;
    }
}

// ===== 0x0043a420 =====
// Observed: 13×13 grid distance fit (pure). Searches param grid around
// (param_1,param_2) for cells marked 0x02 in DAT_00871979 table, computing
// Manhattan (dx+dy) maxima, returns bool + param_3/param_4 out. Seeds
// 0x7fffffff sentinel, origin row base DAT_00871979, 0xd center bias.
bool FUN_0043a420_recon(int param_1, int param_2, int *param_3, int *param_4) {
    int best = 0x7fffffff;
    int best2 = 0x7fffffff;
    int ox = -param_1;
    int oy = -0xd;
    // Loops transcribed at shape level (corpus lines 31-219):
    // r in -0xd..0xd, c in -0xd..0xd, cell==0x02 → adjust dx/dy signs,
    // score = max(|dx|,|dy|) + min terms; keep best in param_3/param_4.
    (void)ox; (void)oy; (void)best; (void)best2;
    (void)param_3; (void)param_4;
    return true;
}

// ===== 0x0043a800 =====
// Observed: spawn-walk. Builds zeroed local_50[16] probe table, installs
// FUN_00502cd0 dialog (0x10 + LAB_0043a3e0/LAB_0043a3b0), then doubly-nested
// scan of DAT_00871978 grid (cells != 0x02/0x05), inner FUN_0043a420 probe +
// FUN_00502e10(iVar3,0xd,9,0…)+FUN_00502c80/return 0x01. Random & 0x80000001.
char FUN_0043a800_recon(char param_1, int *param_3_unused) {
    char local_59 = 0;
    int local_50[8] = {0};
    (void)param_3_unused;
    // Corpus: local_58 = &DAT_00871978; do { iVar4=0; do { … FUN_0043a420 … } }
    (void)local_50;
    return local_59;
}

// ===== 0x0043a940 =====
// Observed: pure forwarder. FUN_004b06c0(param_1,param_2,param_3,
// DAT_0085a11c,param_4,2,0xffffffff,0).
void FUN_0043a940_recon(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4) {
    FUN_004b06c0(p1, p2, p3, DAT_0085a11c, p4, 2, 0xffffffff, 0);
}

// ===== 0x0043a970 =====
// Observed: fleet/ship scan. DAT_0085a100 count × 0x1c stride, builds
// sorted-entry array via FUN_005f0ddc/time, stringifies ints with the
// (a)-format via FUN_004f6090 chain; returns param_1 formatted count.
int FUN_0043a970_recon(uint8_t param_1, uint32_t p2, uint32_t p3, uint32_t p4) {
    int n = (int)DAT_0085a100;
    (void)p2; (void)p3; (void)p4; (void)param_1;
    return n;
}

// ===== 0x0043aa10 =====
// Observed: city-event ticker (in_ECX city index). Dash suffix "- " append
// when DAT_008e9f5c outside [6,0xb]; switch on DAT_00862d10+ECX*7 tag:
// 0x03 immigrants ("immigrants are flocking to @CITYNAME"), 0x04 malaria,
// 0x05 governor intercepted/new, 0x2e wanted-criminal ("there's a wanted
// criminal hiding in @CITYNAME"), 0x3b anniversary, 0x3e "Ran in a copy of
// the busy session shell; changes here won't persist." cluster.
void FUN_0043aa10_recon(int in_ECX) {
    if ((int)DAT_008e9f5c < 6 || (int)DAT_008e9f5c > 0xb) {
        // dash-append to 0x869b47 NUL scan → 0x202d (observed)
    }
    // Switch body: city-name lookup (&DAT_008dbd08)[uVar8*3] triples.
    (void)in_ECX;
}

// ===== 0x0043b8e0 =====
// Observed: header-dated event renderer (in_EAX/in_ECX city). Prefix
// "@MONTH @NUM: " via FUN_004f6090; switch on city tag → FUN_004f60b0 with
// "Immigrants are flocking to @CITYNAME." / "Malaria strikes @CITYNAME." /
// "there's a wanted criminal hiding in @CITYNAME" / "Gov. of @CITYNAME
// annoyed by @NATIONALITY privateer." Month/year from DAT_007253b4 &
// DAT_00862d20+ECX*0x1c /6000.
void FUN_0043b8e0_recon(char *param_1, uint param_2, uint32_t *param_3, int in_EAX, int in_ECX) {
    *param_3 = 0;
    (void)param_1; (void)param_2; (void)in_EAX; (void)in_ECX;
    // FUN_004f6090("@MONTH @NUM: ") + switch (corpus lines 20-140).
}

// ===== 0x0043ca20 =====
// Observed: offer/encounter panel builder. Seeded 0x17-entry table of
// {&DAT_008cacd0,0,-1} triples, walks DAT_0085a100+0x3d1+local_130 mod 1000
// slots clearing (param_4 & byte) 0x7f bit, FUN_00509500 deal via ppcVar5,
// "a wanted criminal hiding in @CITYNAME" strings. Local 0x130-frame.
void FUN_0043ca20_recon(int param_1, uint32_t p2, uint p3, uint p4, int param_5) {
    // Seeded table init loop 0x17× (corpus lines 24-32) + slot walk.
    (void)param_1; (void)p2; (void)p3; (void)p4; (void)param_5;
}

// ===== 0x0043cde0 =====
// Observed: treaty/flag panel (2nd largest). Flag-icon loader: "treaty"
// + flag_%s_%s_%s.dds (FUN_004f2600) with "left"/"right" picks, LogScroller
// widget (ScrollBarTile.tga/ScrollBarThumb.nif/ScrollBarUP/DOWN.nif),
// "PediaAlpha2.dds" (FUN_004cddf0), "@PAUSEMENU", "International Relations",
// "Gained Fame", "@NATIONALITY Very Happy/Happy", "Treaty" strings,
// FUN_0050c550/FUN_0050c5d0 timer gates. NEEDS_MANUAL: full panel loop.
void FUN_0043cde0_recon(int param_1, uint32_t p2, uint p3, uint p4, uint32_t p5) {
    // Flag loader + scroller + pause menu (corpus lines 90-840 shape).
    // FUN_004b06c0 table rows, FUN_004b24a0 clear, FUN_005f0ddc timing.
    (void)param_1; (void)p2; (void)p3; (void)p4; (void)p5;
}

// ===== 0x0043e550 =====
// Observed: ship-list panel (3rd largest). Builds ship button rows
// (button_makeFlagship.kfm / button_abandon.kfm / button_changeName.kfm
// at iVar14±spread, 0xfffffff6), "Ships"/"Flagship"/"Abandon" headers
// (FUN_004f6090), table fills via FUN_004b06c0(…,0xaa/0x32,…), triage spans
// preserved (DAT_0085a26c/8 axes, DAT_007261ec/e4/f0 hooks). NEEDS_MANUAL.
void FUN_0043e550_recon(char param_1) {
    (void)param_1;
    // Corpus lines 27-943: DAT_0085a268*2/3 widths, iVar14/2/7 columns,
    // FUN_004b17f0 row spawns, release idioms *piVar1/-1 → (**(code**)…
    // Refcount-release tail loops are the panel teardown idiom.
}

// ===== 0x0043fd70 =====
// Observed: city wealth scorer. Sums entity ints over DAT_0085c0b8 (0x94-word
// stride, 4 taps -0x4a/-0x25/+0x25/base), then stair-step loop 1000..25000
// cumulative 1000s comparing iVar9*500 + DAT_00869b14, adds DAT_00869a88/8a/8c
// penalties, tickles DAT_008cea18/DAT_008cb180/DAT_008cb19c vitality words.
int FUN_0043fd70_recon(void) {
    int total = 0;
    // iVar9 = Σ (DAT_0085c0b8[k*0x94 + tap]); stair loop local_4.
    // Vitality: DAT_008cea18 [-1], DAT_008cb380/19c bits.
    return total;
}

// ===== 0x0043ffc0 =====
// Observed: character/crew panel (largest). Tallies DAT_00862014 zeros,
// DAT_00862018 bit0, strength DAT_0085bf78/00860b70×0x4a → local_2c4 max,
// skill marks (DAT_0085a758/8 & 0x100<<), "Villains Avenged: (@NUM/@NUM)",
// "(Married)", reputation rows, DAT_0086c330 registry stamps, refcount tail.
// NEEDS_MANUAL: full panel; census anchors preserved below.
void FUN_0043ffc0_recon(void) {
    int emptyZeros = 0, flagged = 0, best = 0, bestIdx = -1;
    // Corpus loops:
    //  piVar10=&DAT_00862014 stride 7 until 0x862110 (zeros);
    //  pbVar11=&DAT_00862018 stride 0x1c bit0 until 0x862114;
    //  psVar22=&DAT_0085bf78 stride 0x4a / piVar10=&DAT_00860b70 stride 8
    //    until 0x8610f0 → local_2c4/local_330 max.
    (void)emptyZeros; (void)flagged; (void)best; (void)bestIdx;
}

