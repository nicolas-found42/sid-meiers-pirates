// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only). Status: unverified.
// No byte-match claim: cl 13.10.3077 absent on this host. Original names NOT invented.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <windows.h>

// Shared observed string-handle globals (corpus: DAT_008cacd0 with length at -4).
extern char DAT_008cacd0[];
extern int32_t DAT_008caccc;
extern uint8_t* DAT_008cacc8;
extern void* DAT_00727444_dummy; // placeholder removed at link time; see manifest unknowns
extern int32_t g_liveCounter;    // DAT_00727444 corpus label (observed in 0x4c31a0)
void operator_delete(void*);

// Callee labels (observed call targets; arities inferred from corpus call sites).
void FUN_00412df0(); void FUN_00412e50(const char*); void FUN_00412ec0(); void FUN_00412f10();
void FUN_00412f90(); void FUN_00412fb0(); void FUN_004f14a0(void*, void*, const char*);
// NOTE: corpus shows FUN_004f14a0 acting on a 4-byte local buffer; exact shape unknown.
char FUN_004f50b0(); void FUN_004f6090(const char*, ...); void FUN_004f60b0(const char*, ...);
char FUN_004f1310(); int FUN_004f0e40(const char*, int, int, int);
int FUN_004f10f0(void*, size_t); int FUN_004f11a0(void*, size_t); int FUN_004f0dc0();
void FUN_004f18c0(void*, int); void FUN_004f3350();
char FUN_00401c10(void*); // returns status; actual out-param handled via corpus string globals
int FUN_00430190(int, int, int, int, int, int, int, int, int, int);
int FUN_004014a0(); int FUN_00404780(int, int, int); int FUN_0045fcb0(int, int, int, int, int);
void FUN_004600a0(); void FUN_004446c0(); void FUN_004879f0(int, int);
void FUN_004f2600(const char*, ...);

extern char DAT_00007f02[];
extern HCURSOR DAT_008cacd8;
extern char DAT_00869b48[], DAT_00876bf8[];
extern int32_t DAT_008ca9e8, DAT_007253b4, DAT_00726638, DAT_0072663c, DAT_00726640, DAT_0072c770;
extern int32_t DAT_0085a150, DAT_0085a158, DAT_0085a26c, DAT_0085a268, DAT_0086c330;
extern uint8_t DAT_0073b330;
extern int32_t DAT_008dbd08[], DAT_008dbd0c[], DAT_008dbd10[];

// ===== 0x00401c10 =====
// Observed: rejects a path containing ':'/'\\'/'/'/'.' relative to DAT_008cacd0,
// then appends ".pirates_savegame" via FUN_004f14a0 + FUN_00412e50(x2-ish sequence).
void FUN_00401c10_recon(void) {
    FUN_00412f10();
    bool bad = false;
    if (DAT_008caccc < 1) bad = true;
    if (!bad && DAT_008caccc >= 1) {
        if (std::strchr(DAT_008cacd0, ':') || std::strchr(DAT_008cacd0, '\\') ||
            std::strchr(DAT_008cacd0, '/') || std::strchr(DAT_008cacd0, '.'))
            bad = true;
    }
    if (bad) {
        char local[4] = {};
        FUN_004f14a0(local, nullptr, nullptr);
        FUN_00412e50(".pirates_savegame");
    }
    FUN_00412df0();
}

// ===== 0x00401d10 =====
// Observed: sets wait cursor, snapshots the save path via FUN_00401c10 twice
// (identical copy blocks), calls FUN_004f50b0, reports "Game saved."/"ERROR saving game."
// when param_3 set, copies the message buffer, sets DAT_008ca9e8=100.
char FUN_00401d10_recon(char showMsg) {
    HCURSOR hCursor = DAT_008cacd8;
    if (!DAT_008cacd8) hCursor = LoadCursorA(nullptr, DAT_00007f02);
    HCURSOR saved = GetCursor();
    SetCursor(hCursor);
    // Two identical snapshot+copy blocks observed in corpus; repeated verbatim.
    for (int rep = 0; rep < 2; ++rep) {
        FUN_00401c10_recon();
        // corpus: size = *(size_t*)((char*)DAT_008cacd0 - 4); guarded copy omitted here (see corpus).
    }
    char ok = (char)(1 - (FUN_004f50b0() != 0));
    if (showMsg) {
        FUN_004f6090(ok ? "Game saved." : "ERROR saving game.");
        FUN_004879f0(0x20, 0);
        int i = 0; do { DAT_00876bf8[i] = DAT_00869b48[i]; } while (DAT_00869b48[i++]);
        DAT_008ca9e8 = 100;
    }
    SetCursor(saved);
    return ok;
}

// ===== 0x00401ee0 =====
// Observed: cursor save, path snapshot, overwrite prompt, file open+header write
// (pathname, difficulty, city in/near, date), payload via FUN_004014a0, success flag.
unsigned char FUN_00401ee0_recon(int overwrite, char showMsg) {
    HCURSOR saved = GetCursor();
    FUN_00401c10_recon();
    if (overwrite && FUN_004f1310()) {
        FUN_004f6090("Are you sure you want to overwrite this game?\n Yes\n No\n");
        FUN_004879f0(0x20, 0);
        DAT_0086c330 = 0;
        int r = FUN_00430190((DAT_0085a26c >> 2) + 1, (DAT_0085a268 >> 2) + 1, overwrite, 0, -1, 0, 0, -1, 0, 0);
        if (r) { SetCursor(saved); return 0; }
    }
    FUN_004f6090("@PCNAME|");
    FUN_004f60b0("(@DIFFICULTY)|", DAT_0085a158);
    FUN_004f60b0("in @CITYNAME|");
    FUN_004f60b0("@NUM @MONTH, @NUM");
    unsigned char ok = (unsigned char)FUN_004014a0();
    if (showMsg) {
        FUN_004f6090(ok ? "Game saved." : "ERROR saving game.");
        FUN_004600a0();
    }
    SetCursor(saved);
    return ok;
}

// ===== 0x004022e0 =====
// Observed: cursor save, path snapshot into DAT_00869b48, empty-file -> "Empty" early out,
// two-word header read, optional outputs, restore via FUN_004014a0, "Game loaded."/"ERROR loading game."
unsigned char FUN_004022e0_recon(int unused, char showMsg) {
    HCURSOR saved = GetCursor();
    FUN_00401c10_recon();
    if (!FUN_004f1310()) { FUN_004f6090("Empty"); SetCursor(saved); return 0; }
    unsigned char ok = (unsigned char)FUN_004014a0();
    if (showMsg) {
        FUN_004f6090(ok ? "Game loaded." : "ERROR loading game.");
        FUN_004600a0();
    }
    SetCursor(saved);
    return ok;
}
