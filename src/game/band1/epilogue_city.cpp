// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only). Status: unverified.
// No byte-match claim: cl 13.10.3077 absent on this host. Original names NOT invented.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern char DAT_008cacd0[];
extern void* DAT_008ea000;
extern char DAT_006f5ffc[], DAT_006f5fe4[], DAT_006f5fbc[], DAT_006f5fc4[];
extern char DAT_00725fe3[], DAT_007091b0[];
extern int32_t DAT_00727444; // corpus label; observed counter
extern char DAT_00007f02[];
extern HCURSOR DAT_008cacd8;
extern char DAT_00869b48[];
extern int32_t DAT_0086c330, DAT_0085a26c, DAT_0085a268, DAT_0085a158;
extern int32_t DAT_008dbd08[], DAT_008dbd0c[], DAT_008dbd10[];
extern int32_t DAT_0085a984[], DAT_0085a98c[], DAT_00861b88[], DAT_008cb100[], DAT_008cb178[];
extern char DAT_0076ef10[];
extern int32_t DAT_0085a140, DAT_0085a164;
extern int32_t DAT_0085bf74[], DAT_0085c0b8[], DAT_00862008[];
extern int32_t DAT_00869a88, DAT_00869a8a, DAT_00869a8c, DAT_00869a8e, DAT_00869b14, DAT_00869b1c;
extern int32_t DAT_008e8fb0, DAT_008e8fb4, DAT_008e8fb8, DAT_008e8fbc, DAT_008c9df4;
extern void* DAT_00727520;
extern int32_t DAT_00860b70[], DAT_00860b74[], DAT_00860b75[], DAT_00860b76[], DAT_00860b7c[], DAT_00860b80[];
extern int32_t DAT_0085bf80[];
extern uint8_t DAT_0087cb[0];
extern char DAT_007267c8[]; extern int32_t DAT_007267cc, DAT_007267d0;
extern int32_t DAT_008142f8[], DAT_008142fa[], DAT_008142fc[], DAT_00814350[], DAT_00814328[], DAT_0081432c[], DAT_00814338[];
extern int32_t DAT_0085a974[], DAT_0085a648, DAT_0085a758;
extern char DAT_00723b14[], DAT_00723b18[];

void FUN_004f6090(const char*, ...); void FUN_004f60b0(const char*, ...); void FUN_004f2600(const char*, ...);
void FUN_004879f0(int, int); void FUN_004048a0(); int FUN_00428950(); void FUN_00412f10(); void FUN_00412ec0(); void FUN_00412f90();
void* FUN_00533c78(size_t); void FUN_004bdca0(void*, ...); void* FUN_004baaa0(...); void FUN_004bf760(...);
void FUN_004ae5b0(const char*); void FUN_00533d10(int, int); void FUN_00412840(double, double);
void FUN_00449390(void*, int); void FUN_004aad70(int); int FUN_004bf530(void*); int FUN_004bf5e0(void*); void FUN_004aade0(int);
void FUN_004c1000(const char*); void FUN_00535670(void*); void FUN_00535920(void*);
void FUN_004baa30(void*, ...); void FUN_004afd20(); void FUN_00482200(void*);
void FUN_004a12f0(const char*); void FUN_004f8b80(const char*, ...);
void FUN_00413080(); int FUN_00415290(int); int FUN_0044d140(int, int, int); int FUN_00449490(int, int, int, int);
void FUN_004bf30(); int FUN_004192f0(); void FUN_0043a970(int, int, int, int); void FUN_00449530();
void FUN_004b06c0(void*, int, int, int, int, int, int, int); void FUN_0042e730(); void FUN_004b6070(); void FUN_004b6f60();
void FUN_004b24a0(void*, int); int FUN_004b2760(int); void FUN_004889c0(void*, ...); void FUN_004bba60(void*, ...);
void FUN_004af080(int, int, int, int, int, int, int, int, int, int); int FUN_0042c6f0();
void FUN_004f6090b(const char*, ...);
extern char DAT_0086be80[], DAT_0086c010[], DAT_0086c1a0[], DAT_0086bcf0[], DAT_0086bb60[];
extern int32_t DAT_008dc30c;

// ===== 0x00456dd0 (retirement/epilogue text builder) =====
// Observed: ~23 retirement strings, "\n\n" paragraph separators written at buffer end,
// rank selection from DAT_00869a88..8e, wealth tier from DAT_00869b14, Montalban line on
// flag 0x80000 in DAT_0085a164, rescueds count DAT_00869b1c, notoriety DAT_00862008.
void FUN_00456dd0_recon(void)
{
    FUN_004048a0();
    FUN_004f6090("You retire at the age of @NUM in @HEALTH health. ");
    FUN_004f60b0("You take up residence in the city of @CITYNAME with the profession of @QUAYLE. ");
    int wife = -1; // corpus: DAT_00872bd0 vs stack param; selection logic elided (see corpus).
    (void)wife;
    FUN_004f60b0("Your promotion to @NATIONALITY @RANK gains you little respect. ");
    int acres = 0;
    for (int i = 0; i < 4; ++i) acres += DAT_0085c0b8[i * 0x25];
    if (DAT_00869b14 < 5000)
        FUN_004f60b0("Your accumulated wealth of @NUM gold pieces and @NUM acres of land provide you just the bare necessities in a small room near the docks. ", DAT_00869b14, acres * 0x32);
    else if (DAT_00869b14 < 10000)
        FUN_004f60b0("Your accumulated wealth of @NUM gold pieces and @NUM acres of land provide you some modest luxuries and a pleasant house near the edge of town. ", DAT_00869b14, acres * 0x32);
    else
        FUN_004f60b0("Your accumulated wealth of @NUM gold pieces and @NUM acres of land provide you an extravagant lifestyle in a mansion near the town center. ", DAT_00869b14, acres * 0x32);
    if (DAT_0085a164 & 0x80000)
        FUN_004f60b0("Vanquishing the evil Marquis de la Montalban remains the highlight of your career. ");
    else
        FUN_004f60b0("Sadly, the evil Marquis de la Montalban remains at large - a threat to good people everywhere. ");
    if (DAT_00869b1c == 0)
        FUN_004f60b0("Unfortunately, you were unable to rescue any members of your family. This omission haunts you throughout your remaining years. ");
    else if (DAT_00869b1c == 4)
        FUN_004f60b0("Happily, you were able to rescue all of your missing family members. Joyous family gatherings highlight your remaining years. ");
    else
        FUN_004f60b0("You were able to rescue @NUM of your missing family members. Joy is tempered with sadness as you live out your remaining years. ", (int)DAT_00869b1c);
}

// ===== 0x00443a0c0 (land-battle unit help text) =====
// Observed: dedup bitmask DAT_008ca978, guard on DAT_0085a158/DAT_008ca97c, 10 unit strings.
void FUN_0043a0c0_recon(int unit, char force)
{
    extern uint32_t DAT_008ca978; extern int32_t DAT_008ca97c;
    if (!force) {
        if (DAT_008ca978 & (1u << (unit & 0x1f))) return;
        if (DAT_0085a158) return;
        if (DAT_008ca97c) return;
    }
    DAT_008ca978 |= (1u << (unit & 0x1f));
    const char* msg = nullptr;
    switch (unit) {
    case 0: msg = "PIRATES: armed with cutlass and pistol. Fearsome at close quarters, vulnerable to cavalry and muskets in the open.\n"; break;
    case 1: msg = "BUCCANEERS: armed with hunting muskets. Deadly at long range, vulnerable to close quarter attack.\n"; break;
    case 2: FUN_004f6090("@NATIONALITY INFANTRY: armed with crude military muskets. Effective in large numbers.\n"); goto done;
    case 3: FUN_004f6090("@NATIONALITY CAVALRY: Devastating against exposed infantry. Ineffective in woods.\n"); goto done;
    case 4: msg = "ARTILLERY: Long range firepower. Vulnerable to close attack.\n"; break;
    case 5: msg = "Indian ARCHERS: Fast moving but with limited firepower.\n"; break;
    case 7: msg = "Indian SCOUTS: Fast moving, effective at close range.\n"; break;
    case 8: FUN_004f6090("@NATIONALITY GUARDS: Somewhat more effective than regular infantry.\n"); goto done;
    case 9: msg = "Ship's OFFICERS: armed with cutlass and pistol. Skilled at close quarters combat, vulnerable to cavalry and muskets in the open.\n"; break;
    case 0xf: msg = "Your goal is to defeat the enemy and reach the city gates.\n"; break;
    default: goto done;
    }
    if (msg) FUN_004f6090(msg);
done:
    FUN_004879f0(0x28, 0);
}

// ===== 0x004108a0 (town scene loader, gamebryo) =====
// Observed: picks menu/settlement/townback textures by biome byte, refcounted scene
// swap at DAT_008cadec, Camera01 + FUN_00533d10/00412840.
void FUN_004108a0_recon(int city)
{
    if (DAT_008cadec) return;
    int biome = DAT_00860b74[city * 0x20]; if (biome < 0) biome = 0; if (biome > 4) biome = 4;
    FUN_004f2600("tm_%c_menu.nif", DAT_006f5ffc[biome]);
    void* scene = FUN_00533c78(0xc0);
    if (scene) { FUN_004bdca0(DAT_008ea000, 0, 0, 0, 0, -1, 0, 0, 0, 0); DAT_00727444++; }
    DAT_008cadec = scene;
    if (biome != 4) {
        if (DAT_00860b80[city * 8] == 7) FUN_004f2600("Tm_%c_settlement.dds", DAT_006f5fe4[biome]);
        else FUN_004f2600("Tm_%c_townback_%s.dds", DAT_006f5fe4[biome], DAT_006f5fbc);
        void* tex = FUN_004baaa0(0, "transparent.tga", DAT_008cacd0);
        FUN_004bf760(tex);
    }
    FUN_004ae5b0("Camera01"); FUN_00533d10(0, 1); FUN_00412840(1.0, 100000.0);
    DAT_008ca904 = 1;
}
extern int32_t DAT_008ca904;

// ===== 0x00444830 (city description) =====
// Observed: short vs long description gated on flags 0x101/0x20/0x20000/0x40000,
// population, garrison, shipwright upgrade, governor's daughter line.
void FUN_00444830_recon(int city)
{
    if (((DAT_00860b70[city * 8] & 0x101) == 0) && ((DAT_0085a164 & 0x20) == 0)) {
        FUN_004f6090("@CITYNAME is @ANATIONALITY city. ");
        if ((DAT_00860b70[city * 8] & 0x20000) == 0) FUN_004f60b0("@UNIQUES", city);
    } else {
        FUN_004f6090("@CITYNAME is a @ECONOMY @NATIONALITY @CITYTYPE.");
        FUN_004f60b0(" The town has a population of @NUM @URBAN.");
        if (DAT_00860b76[city * 8] == 0) FUN_004f60b0(" There are no soldiers guarding the town. ");
        else FUN_004f60b0(" The town garrison consists of @NUM soldiers. ");
        if ((DAT_00860b70[city * 8] & 0x20000) == 0) FUN_004f60b0("@UNIQUES", city);
        FUN_004f60b0(" The shipwright can supply @UPGRADE. ");
    }
    if (DAT_00860b70[city * 8] & 0x40000) FUN_004f60b0("The governor's daughter is @BEAUTY. ");
}
