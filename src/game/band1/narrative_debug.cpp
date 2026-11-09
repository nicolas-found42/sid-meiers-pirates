// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only). Status: unverified.
// No byte-match claim: cl 13.10.3077 absent on this host. Original names NOT invented.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern char DAT_008cacd0[];
extern int32_t DAT_008caccc;
extern char DAT_00869b48[];
extern uint8_t DAT_0086bb50, DAT_0086bb51, DAT_0086bb52, DAT_0086bb53, DAT_0086bb54;
extern int32_t DAT_008ca4e0, DAT_008cab68, DAT_008cab64, DAT_008cabec, DAT_008cabf0, DAT_0085a11c, DAT_0085a26c, DAT_0085a268;
extern double DAT_008c8290[];
extern char DAT_008c9e00[];
extern void* DAT_008ea000;
extern char DAT_006f5fe4[], DAT_006f5ffc[], DAT_006f5fc4[], DAT_006f5fbc[];
extern int32_t DAT_00860b70[], DAT_00860b74[], DAT_00860b75[], DAT_00860b76[], DAT_00860b7c[], DAT_00860b80[];
extern int32_t DAT_00722738, DAT_008ca904;
extern void* DAT_008cadec;
extern int32_t DAT_0085a164, DAT_0085bf74[], DAT_0085bf80[];
extern int32_t DAT_008dbd08[], DAT_008dbd0c[], DAT_008dbd10[];
extern int32_t DAT_0085a984[], DAT_0085a98c[], DAT_00861b88[], DAT_00861b78[], DAT_00861b7c[], DAT_00862008[];
extern int32_t DAT_0085a974[], DAT_00869b1c, DAT_00869b1e, DAT_0085a384;
extern char DAT_0076ef10[];
extern int32_t DAT_0085a140, DAT_005c0b8_[(0x85da28-0x85c0b8)/4];
extern int32_t DAT_0085c0b8[];
extern int32_t DAT_00869a88, DAT_00869a8a, DAT_00869a8c, DAT_00869a8e, DAT_00869b14, DAT_00869a88s;
extern int32_t DAT_008e8fb0, DAT_008e8fb4, DAT_008e8fb8, DAT_008e8fbc;
extern void* DAT_00727520;
extern int32_t DAT_008c9df4;

void FUN_00412f10(); void FUN_00412ec0(); void FUN_00412f90();
void FUN_004f6090(const char*, ...); void FUN_004f60b0(const char*, ...); void FUN_004f2600(const char*, ...);
void FUN_004879f0(int, int); void FUN_004048a0(); void FUN_00428950(); void FUN_004f1b10(void*);
int FUN_0045fc70();
void FUN_0042e4a0(int, int, const char*, ...);
void FUN_005459b0(int, void*, void*); void FUN_004ffbc0(int, uint64_t);
void* FUN_00533c78(size_t); void FUN_004bdca0(void*, ...); void* FUN_004baaa0(...); void FUN_004bf760(...);
void FUN_004ae5b0(const char*); void FUN_00533d10(int, int); void FUN_00412840(double, double);
void FUN_00449390(void*, int); void FUN_004aad70(int); int FUN_004bf530(void*); int FUN_004bf5e0(void*);
void FUN_004aade0(int); void FUN_004c1000(const char*); void FUN_00535670(void*); void FUN_00535920(void*);
void FUN_004baa30(void*, ...); void FUN_004afd20(); void FUN_00482200(void*);
void FUN_004a12f0(const char*); void FUN_004f8b80(const char*, ...);
void FUN_00413080(); int FUN_00415290(int); int FUN_0044d140(int, int, int); int FUN_00449490(int, int, int, int);
void FUN_004bf30(); int FUN_004192f0(); void FUN_0043a970(int, int, int, int); void FUN_00449530();
int FUN_004f1b10b(); // alias guard: real symbol above

// ===== 0x0042e4f0 =====
// Observed: four debug overlays gated by DAT_0086bb51/52/53/50/54; strings "Fps %5.1f",
// "Tex used = %d : %5.1f Mb", "2D = %d    3D = %d    Streams = %d", memory dump lines.
void FUN_0042e4f0_recon(void)
{
    if (DAT_0086bb51) FUN_0042e4a0(0xb4, 0x1e, DAT_008c9e00);
    if (DAT_0086bb52) {
        double fps = 1.0;
        if (DAT_008cab68 >= 2) {
            int n = DAT_008cab68 < 0xb ? DAT_008cab68 - 1 : 10;
            int cur = DAT_008cab64 - 1; if (cur < 0) cur += 0x40;
            int prev = cur - n; if (prev < 0) prev += 0x40;
            fps = (double)n / (DAT_008c8290[cur] - DAT_008c8290[prev]);
        }
        FUN_0042e4a0(200, 0x1c2, "Fps %5.1f", fps);
    }
    if (DAT_0086bb53) {
        int texCount = 0; float texMb = 0;
        if (DAT_008ca4e0) { FUN_005459b0(0, nullptr, nullptr); FUN_004ffbc0(0, 0); }
        FUN_0042e4a0(0x15e, 0x1c2, "Tex used = %d : %5.1f Mb", texCount, (double)(texMb * 9.536743e-07f));
    }
    if (DAT_0086bb50) FUN_0042e4a0(100, 0x1c2, "2D = %d    3D = %d    Streams = %d", 0, 0, 0);
    if (DAT_0086bb54) {
        if (DAT_0086bb52) FUN_0042e4a0(300, 0x1c2, "Mem %dMb", 0);
        else {
            FUN_0042e4a0(0, 100, "free:   %dKb / %d", 0, 0);
            FUN_0042e4a0(0, 0x78, "normal: %dMb / %d", 0, 0);
            FUN_0042e4a0(0, 0x8c, "crt:    %dKb / %d", 0, 0);
            FUN_0042e4a0(0, 0xa0, "max:    %dMb", 0);
            FUN_0042e4a0(0, 0xb4, "all:    %dMb", 0);
        }
    }
}

// ===== 0x0044ce60 =====
// Observed: switch on fleet record type -> 22 literal strings; quest case resolves
// "Evil Spaniard!" / "@EVILNAME" / "@TOP10" / "Mr. @CHAR. @NPCNAME".
void FUN_0044ce60_recon(int index)
{
    switch (DAT_0085a984[index]) {
    case 1: FUN_004f60b0("Delivering ultimatum"); return;
    case 2: FUN_004f60b0("Delivering peace treaty"); return;
    case 3: FUN_004f60b0("Transporting immigrants"); return;
    case 4: FUN_004f60b0("Delivering vital medicines"); return;
    case 5: FUN_004f60b0("Transporting new governor"); return;
    case 6: FUN_004f60b0("Pirate raiders"); return;
    case 7: FUN_004f60b0("Invasion force"); return;
    case 8: FUN_004f60b0("Transporting sugar plants"); return;
    case 9: FUN_004f60b0("Indian war canoe"); return;
    case 10: FUN_004f60b0("Transporting troops"); return;
    case 0xb: FUN_004f60b0("Proposing amnesty"); return;
    case 0xc: FUN_004f60b0("Treasure ship"); return;
    case 0xd: FUN_004f60b0("Military payroll"); return;
    case 0xe: FUN_004f60b0("Grain transport"); return;
    case 0xf: FUN_004f60b0("New Warship"); return;
    case 0x14: FUN_004f60b0("Transporting holy relic"); return;
    case 0x15: FUN_004f60b0("Bombard Indian village"); return;
    case 0x28: case 0x29: case 0x2a: break;
    default: FUN_004f60b0("quest"); return;
    }
    if (DAT_0085a98c[index] < 1) { FUN_004f60b0("Evil Spaniard!"); return; }
    int evil = DAT_00861b88[DAT_0085a98c[index]];
    if (evil > 0x27) { FUN_004f60b0("@EVILNAME", 0, 0, 0); return; }
    if (evil < 0x1e) { FUN_004f60b0("@TOP10", 0, 0, 0); return; }
    FUN_004f60b0("Mr. @CHAR. @NPCNAME", 'A' + (index % 0x1a), 0, 0, 0);
}

// ===== 0x004920a0 =====
// Observed: grid lookup + treasure/relative/rock descriptions; ~22 strings incl.
// "@TREASURE @ROCK", "Lost @RELATIVE!", "Inca Temple", "Geyser", "Arch rock".
int FUN_004920a0_recon(int mode)
{
    DAT_00869b48[0] = 0;
    int kind = DAT_0076ef10[0]; // index registers unknown; switch on observed byte
    if (kind == 0x10) { FUN_004f6090("@TREASURE @ROCK", 0, 0); return 0; }
    if (kind == 0x11) {
        if (mode == 1) { FUN_004f6090("Lost @RELATIVE!", (int)DAT_00869b1c); }
        else if (mode == 2) { FUN_004f6090("Lost City of the @LOSTCITY!", (int)DAT_00869b1e); }
        else if (mode == 3) { FUN_004f6090("Montalban's Hideout"); }
        else { FUN_004f6090("@TOP10's Treasure!"); }
        return 6;
    }
    if (kind == 0x13) { FUN_004f6090("Inca Temple"); return 8; }
    if (kind == 0x16) { FUN_004f6090("Geyser"); return 1; }
    if (kind == 0x1a) { FUN_004f6090("Stone Head"); return 0x19; }
    if (kind == 0x1b) { FUN_004f6090("Indian Totem"); return 9; }
    if (kind == 0x0c) { FUN_0045fc70(); FUN_004f6090("@CITYNAME"); return 0x18; }
    return 2;
}

// ===== 0x0044a3b0 =====
// Observed: 6-case switch -> "@ORDINAL ranked pirate", "Evil Spaniard", "Wanted Criminal",
// "Has information regarding your lost @RELATIVE", kidnapping texts.
void FUN_0044a3b0_recon(int index)
{
    switch (DAT_00861b78[index * 0x12]) {
    case 6: FUN_004f60b0("@ORDINAL ranked pirate", DAT_00862008[DAT_00861b88[index * 9] * 0xe]); return;
    case 0x1e: FUN_004f60b0("Wanted Criminal"); return;
    case 0x28: FUN_004f60b0("Has information regarding your lost @RELATIVE", (int)DAT_00869b1c); return;
    case 0x2a: FUN_004f60b0("Evil villain who wronged your family"); return;
    case 0x29: FUN_004f60b0("Kidnapped the Governor of @CITYNAME's Daughter"); return;
    default: FUN_004f60b0("Evil Spaniard"); return;
    }
}

// ===== 0x004a13c0 =====
// Observed: zeroes two dwords at +10000, prints audio-queue stats block (6 format strings).
void FUN_004a13c0_recon(void* stats)
{
    int32_t* p = (int32_t*)stats;
    p[10000 / 4] = 0; p[0x2714 / 4] = 0;
    FUN_004a12f0("Audio Queue statistics");
    FUN_004f8b80("\tmax queue size: %d\n", 0);
    FUN_004f8b80("\tmax queue delay: %dms\n", 0);
    FUN_004f8b80("\tmax thread delay: %dms\n", 0);
    FUN_004f8b80("\ttotal thread delay: %dms\n", 0);
}
