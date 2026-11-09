// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only). Status: unverified.
// No byte-match claim: cl 13.10.3077 absent on this host. Original names NOT invented.
// Covers the quest-text trio (0x4c4a0/0x4c280/0x4bfe0), object destructor (0x4c31a0),
// refcount helper (0x4aac10), settings label switch (0x4b2f10) and mode switch (0x4b3270).
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <windows.h>

extern int32_t DAT_00727444;
extern int32_t DAT_008dbd08[], DAT_008dbd0c[], DAT_008dbd10[];
extern int32_t DAT_008142f8[], DAT_008142fa[], DAT_008142fc[], DAT_00814350[], DAT_00814328[], DAT_0081432c[], DAT_00814338[];
extern char DAT_00723b14[], DAT_00723b18[];
extern char DAT_007267c8[]; extern int32_t DAT_007267cc, DAT_007267d0;
extern int32_t DAT_0085a164, DAT_0085a648, DAT_0085a758, DAT_0085a974[];
extern char DAT_00726638[]; extern int32_t DAT_0072663c, DAT_00726640;
extern int32_t DAT_00869b1c;
extern int32_t DAT_00860b74[];
extern char DAT_008cacd0[]; extern int32_t DAT_0085a11c, DAT_0085a26c; extern int32_t DAT_008cabec, DAT_008cabf0;
extern int32_t DAT_008ea0b4;

void FUN_004f6090(const char*, ...); void FUN_004f60b0(const char*, ...); void FUN_004f2600(const char*, ...);
void FUN_00413080(); int FUN_00415290(int); int FUN_0044d140(int, int, int); int FUN_00449490(int, int, int, int);
void FUN_004bf30(); int FUN_004192f0(); void FUN_0043a970(int, int, int, int); void FUN_00449530();
void FUN_00449390(void*, int); int FUN_005f0ddc(); void FUN_004b06c0(void*, int, int, int, int, int, int, int);
void FUN_00412df0(); void FUN_00412f10(); void FUN_00487fd0(int, int);
struct RefObj { void* vtbl; int32_t ref; };
void FUN_004aac50(void*);

// ===== 0x004c31a0 =====
// Observed (deep dossier): swaps vtable, deletes member at +8, decrements counter,
// restores vtable, conditionally deletes this on flag bit 0.
void FUN_004c31a0_recon(void* self, uint8_t flag)
{
    int32_t* obj = (int32_t*)self;
    obj[0] = 0x70d02c;                       // observed vtable load
    void* member = (void*)(intptr_t)obj[2];
    ::operator delete(member);
    DAT_00727444 -= 1;
    obj[0] = 0x6fd148;                       // observed restore
    if (flag & 1) ::operator delete(self);
}

// ===== 0x004aac10 =====
// Observed: AddRef param, call FUN_004aac50(&param), Release with virtual call at zero.
void FUN_004aac10_recon(RefObj* p)
{
    RefObj* saved = p;
    if (p) p->ref++;
    FUN_004aac50(&p);
    if (saved && --saved->ref == 0) {
        auto fn = (void(__thiscall*)(RefObj*, int))*(void**)saved;
        fn(saved, 1);
    }
}

// ===== 0x0044c4a0 / 0x0044c280 / 0x0044bfe0 (quest text) =====
// Observed common shape: guard flags, scan quest table for existing type pair,
// else random city/alloc via FUN_00415290/0044d140/00449490, fill record, print
// two-sentence hint with "traveling to" vs "lurking/hiding in" branch.
static int questAlloc(int a, int b, int c, int d)
{
    int city = 0; // rand()%0x2c loop elided (see corpus LAB_* labels)
    int evil = FUN_00415290(a);
    int slot = FUN_0044d140(b, c, d);
    int id = FUN_00449490(b, evil, slot, d);
    (void)city;
    FUN_004bf30();
    return id;
}
int FUN_0044c4a0_recon(int possessive)
{
    if ((DAT_0085a164 & 0x80000) || (DAT_0085a648 && ((DAT_0085a758 & 0xf00) == 0))) return -1;
    int id = questAlloc(0x19, 0x28, -1, 0x2a);
    FUN_00413080();
    FUN_004f6090(possessive
        ? "The Evil Villain: Marquis Montalban, who wronged our family, sails the waters of the Spanish Main in his mighty galleon: '@SHIPNAME'. "
        : "The Evil Villain: Marquis Montalban, who wronged your family, sails the waters of the Spanish Main in his mighty galleon: '@SHIPNAME'. ");
    FUN_004f60b0("At last report he was traveling to @CITYNAME.\n");
    FUN_0043a970(0x44, 0, 0x2a, 0); FUN_00449530();
    return id;
}
int FUN_0044c280_recon(void)
{
    if (DAT_00869b1c > 3) return -1;
    int id = questAlloc(0x10, 0x28, -1, 0x28);
    FUN_004f6090("I believe you have @ARELATIVE who has been missing for many years. ");
    FUN_004f60b0("The Evil Spaniard: Baron Raymondo, has information which will be of great value to you. ");
    FUN_004f60b0("At the moment he is traveling to @CITYNAME on the fast galleon '@SHIPNAME'.\n");
    FUN_004f60b0(" I'll note that in my log.\n");
    return id;
}
int FUN_0044bfe0_recon(int city)
{
    int id = questAlloc(7, 0x28, city, 0x29);
    FUN_004f6090("'Oh @RANK @PCNAME, I am so glad you are here. ");
    FUN_004f60b0("My daughter has been kidnapped by the evil spaniard: Colonel Mendoza. ");
    FUN_004f60b0("He is said to be traveling to @CITYNAME on the fast galleon '@SHIPNAME'.\n");
    FUN_004f60b0(" That's a real shame.\n I'll get right on it.\n");
    return id;
}

// ===== 0x004b2f10 (settings label switch) =====
// Observed: index in AL selects one of 29 labels (Picture Gamma ... Dump Memory Stats,
// Enable Wireframe, Draw Safe Area); case 0x15 branches Main Menu vs Game.
void FUN_004b2f10_recon(int index, char inGame)
{
    const char* labels[] = {
        "Picture Gamma","Water Detail","Object Detail","World Detail","Change Video Resolution",
        "Enable Shadows","Enable Advanced Lighting","Enable Trilinear Filtering","Disable Shaders",
        "Exit Video Settings","Master Volume","Music Volume","Sound FX Volume","Dance Music Volume",
        "3D Sound Driver","Exit Audio Settings","Video Settings","Audio Settings",
        "Modify Your Ship's Sails And Flags","Abandon Game","Quit Game","Return to Main Menu/Return to Game",
        "Xbox Live Options","Enable FPS","Enable Texture Info","Dump Memory Stats","Enable Wireframe","Draw Safe Area"
    };
    if (index >= 0 && index < 29) FUN_004f6090(labels[index]);
    else if (index == 0x15) FUN_004f6090(inGame ? "Return to Game" : "Return to Main Menu");
}

// ===== 0x004b3270 (mode item apply) =====
// Observed: mode 4 -> "%d x %d" resolution label; mode 0xe -> "Not Supported"/"Default"
// with Miles Fast 2D driver check.
void FUN_004b3270_recon(int mode, int x, int y)
{
    if (mode == 4) {
        FUN_004f2600("%d x %d", x, y);
    } else if (mode == 0xe) {
        if (!DAT_008cabec) { FUN_004f6090("Not Supported"); DAT_0085a11c = 100; return; }
        FUN_00412df0(); FUN_004f6090("Default");
        DAT_0085a11c = 100;
    }
}
