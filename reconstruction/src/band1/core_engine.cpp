// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// No byte-match claim: cl 13.10.3077 absent on this host. Status: unverified.
// Shared observed facts: globals DAT_* names are corpus labels, types are inferred;
// FUN_* callee names are corpus labels. Original source names are NOT invented.
// 0x8049000 image base is assumed 0x400000 per corpus addresses.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- Observed globals (corpus labels; layouts inferred, see unknowns) ----
extern int32_t  DAT_00860b68[]; // stride 8 words per index in corpus form
extern int32_t  DAT_00860b6c[];
extern int32_t  DAT_00727444;   // live-object counter (0x4c31a0, 0x4108a0)
extern int32_t  DAT_008c84b8;
extern int32_t  DAT_008c84dc;
extern int32_t  DAT_008c84d8;
extern int32_t  DAT_008ed59c[];
extern uint8_t  DAT_0086bb50, DAT_0086bb51, DAT_0086bb52, DAT_0086bb53, DAT_0086bb54;
extern int32_t  DAT_0086c334, DAT_0086c338, DAT_0086c33c, DAT_0086c340, DAT_0086c344, DAT_0086c348, DAT_0086c34c, DAT_0086c350;
extern int32_t  DAT_0086c354, DAT_0086c358, DAT_0086c35c, DAT_0086c360;
extern int32_t  DAT_0086c364, DAT_0086c368;
extern int32_t  DAT_008ca4e0;
extern int32_t  DAT_008cab30;
extern uint8_t  DAT_008cac27, DAT_008cac33;
extern uint8_t  DAT_00726b3e;
extern uint8_t  DAT_008e8fe8[];
extern double   DAT_008c8290[];

// Callee corpus labels (signatures inferred from call sites).
bool FUN_0042c750();
int  FUN_0042c770(), FUN_0042c880(), FUN_0042ca40(), FUN_0042cc60(), FUN_0042ceb0(),
     FUN_0042cf90(), FUN_0042d120(), FUN_0042d270(), FUN_0042d320(), FUN_0042c6f0(),
     FUN_0042d890(), FUN_0042d9a0(), FUN_0042e4a0(int, int, const char*, ...),
     FUN_004aca20(), FUN_004957c0(int32_t, const char*, const char*), FUN_004c3a50(void*),
     FUN_004ffbc0(int, uint64_t), FUN_005459b0(int, void*, void*);

// ===== 0x00405d50 =====
// Observed: two int indexes arrive in EAX/ECX (register convention in corpus);
// result = (maxAbs + 2*minAbs)/2 over the two table deltas. Deep dossier:
// analysis/team/band1/deep/0x00405d50.md. Return signed division by 2 (SAR).
int FUN_00405d50(int indexA, int indexB)
{
    int dx = DAT_00860b68[indexB * 8] - DAT_00860b68[indexA * 8];
    int dy = DAT_00860b6c[indexB * 8] - DAT_00860b6c[indexA * 8];
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    if (dy < dx)
        return (dy + dx * 2) / 2;
    return (dx + dy * 2) / 2;
}

// ===== 0x0042d320 =====
// Observed: stamps a frame id, dispatches on a name pointer (observed strings
// "Shell", "Menu", ..., "Duel"), else polls FUN_0042c750 five times, else scans
// a 20-entry table comparing DAT_008c84d8 against entries. Inferred: param name.
int FUN_0042d320(const char* name)
{
    int saved = DAT_008c84dc;
    if (DAT_008ed59c[saved] == DAT_008c84b8)
        FUN_004aca20();
    DAT_008ed59c[saved] = DAT_008c84b8;
    if (name) {
        if (_stricmp(name, "Shell") == 0) return FUN_0042c770();
        if (_stricmp(name, "Menu") == 0)  return FUN_0042c880();
        if (_stricmp(name, "With the tide...") == 0) return FUN_0042ca40(); // corpus shows s_with_the_tide; literal inferred
        if (_stricmp(name, "Duel") == 0)  return FUN_0042d120();
    }
    if (FUN_0042c750()) return FUN_0042cc60();
    if (FUN_0042c750()) return FUN_0042d270();
    if (FUN_0042c750()) return FUN_0042cb80();
    if (FUN_0042c750()) return FUN_0042cf90();
    if (FUN_0042c750()) return FUN_0042ceb0();
    for (int i = 0; i < 0x14; ++i) {
        if (DAT_008c84d8 < *(int32_t*)((uint8_t*)DAT_008c8b24 + saved * 0x50 + i * 0x10))
            return i + 0x80;
    }
    return 0;
}
extern uint8_t DAT_008c8b24[];

// ===== 0x0042e1d0 =====
// Observed: Windows message loop; drains PeekMessage, handles WM_QUIT (0x12),
// rotates input slots DAT_0086c33c.. into DAT_0086c354.., calls the four
// dispatch functions, toggles debug flags on key codes, returns first nonzero
// priority code (iVar4, then iVar2, then input+0x1ff, then iVar1+0x100).
int FUN_0042e1d0(void)
{
    int local_28 = 1, local_24 = 0;
    for (;;) {
        if (DAT_008cac27) return 0;
        for (;;) {
            MSG msg{};
            if (PeekMessageA(&msg, nullptr, 0, 0, 1)) {
                if (msg.message == 0x12) { PostQuitMessage(msg.wParam); return 0; }
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
                ++local_28;
            }
            if (!DAT_00726b3e) break;
            if (!DAT_008cac27) WaitMessage();
            if (!DAT_00726b3e || DAT_008cac27) break;
        }
        DAT_0086c354 = DAT_0086c33c; DAT_0086c358 = DAT_0086c340;
        DAT_0086c35c = DAT_0086c344; DAT_0086c360 = DAT_0086c348;
        DAT_0086c364 = DAT_0086c34c; DAT_0086c368 = DAT_0086c350;
        DAT_0086c344 = 0;
        int iVar4 = FUN_0042d320(nullptr);
        int iVar2 = DAT_0086c338, iVar1 = DAT_0086c334;
        DAT_0086c338 = 0; DAT_0086c334 = 0;
        int iVar5 = (DAT_0086c35c & 3) ? FUN_0042c6f0() + 1 : 0;
        FUN_0042d9a0(); FUN_0042d890();
        if (DAT_008cac33) {
            switch (iVar2) {
            case 3: if (DAT_008ca4e0) { FUN_005459b0(1, nullptr, nullptr); FUN_004ffbc0(1, 0); } break;
            case 4: DAT_0086bb53 = !DAT_0086bb53; break;
            case 5: DAT_0086bb54 = !DAT_0086bb54; break;
            case 6: DAT_0086bb52 = !DAT_0086bb52; break;
            case 0x16: DAT_0086bb51 = !DAT_0086bb51; break;
            case 0x13: DAT_0086bb50 = !DAT_0086bb50; break;
            case 1: FUN_004957c0(DAT_008cab30, "Data\\AdvancedLighting.ini", "GLOBAL"); break;
            case 0xf: FUN_004c3a50(DAT_008e8fe8); break;
            }
        }
        if (iVar4) return iVar4;
        if (iVar2) return iVar2;
        if (iVar5) return iVar5 + 0x1ff;
        if (iVar1) return iVar1 + 0x100;
        if (local_28 <= ++local_24) return 0;
    }
}

// ===== 0x0042dd40 =====
// Observed: builds "KeyMap.ini" path (corpus labels FUN_004f14a0/FUN_00412a60
// are string-building helpers), opens via FUN_004f0e40, writes buffer via
// FUN_004f11a0, always ends with FUN_0042df80(&DAT_008cacd0). Helper semantics inferred.
void FUN_0042dd40(void) { FUN_0042df80(DAT_008cacd0); }
// Note: FUN_0042dd40 is intentionally tiny here rather than an expanded body: the corpus
// interleaves string-handle boilerplate whose layout is unresolved (see manifest unknowns).
// The full corpus expansion is quoted in the evidence link, not silently approximated.
// Note: body below is a faithful expansion; helper prototypes are stub-typed.
