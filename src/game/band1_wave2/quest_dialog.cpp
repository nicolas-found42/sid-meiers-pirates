// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// No byte-match claim: cl 13.10.3077 absent on this host. Status: unverified.
// Quest / dialog / difficulty subsystem. DAT_*/FUN_* are corpus labels.
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

extern int32_t DAT_0085a158; // difficulty / career tier
extern int32_t DAT_00869ab4, DAT_00869ab0, DAT_00869584_dummy;
extern int32_t DAT_00869ab8, DAT_00869b14, DAT_0085a150, DAT_0085a140;
extern int32_t DAT_0085a26c, DAT_0085a268, DAT_0085a164;
extern uint8_t DAT_00869b48, DAT_00869b20, DAT_00869b21, DAT_00869a70_3;
extern uint8_t DAT_00860b70[];
extern uint8_t DAT_00860b74[];
extern int32_t DAT_00860b68[], DAT_00860b6c[];
extern int32_t DAT_0085bf84[];
extern int32_t DAT_0072ccc4, DAT_007253b4;
extern uint8_t DAT_008cac27, DAT_008c827f, DAT_008c827e, DAT_008c81f0;
extern char DAT_006f5896[];
extern int32_t DAT_008c827d;
extern char DAT_00726638[], DAT_0072663c[];
extern void* PTR_DAT_00726640;
extern int32_t DAT_00722734;
extern int32_t DAT_008dbd08[], DAT_008dbd0c[], DAT_008dbd10[];
extern int32_t DAT_0072c650;

void FUN_004f6090(const char*, ...);
void FUN_004f60b0(const char*, ...);
void FUN_004f2600(const char*, ...);
void FUN_00430190(int,int,const char*,int,int,...);
int FUN_00486990(int,int);
int FUN_004879f0(int,int);
void FUN_004881b0(int,int);
void FUN_004b06c0(const void*,int,int,int,int,int,int,int);
void FUN_004867b0();
void FUN_004862a0();
int FUN_004048a0();
void FUN_00485380(int,int,int);
void FUN_0046b790(int);
void FUN_00460480();
void FUN_004888e0(int,int,int,int);
void FUN_00401000(int);
void FUN_0045bbf0(int);
void FUN_00403470();
void FUN_004add70(int);
int FUN_00451110();
int FUN_0048c160();
void FUN_00450cf0();
void* FUN_004baaa0(...);
void FUN_004bf760(void*,int,const char*,const void*);
int FUN_004a2080(int,int,int);
void FUN_004a21c0();
void FUN_00487850();
void FUN_00489130(const void*);
int FUN_00444e10(int,int);
int FUN_0044ea50(int,int);
int FUN_0044eb10(int,int,int,int);
void FUN_0045fcb0(int,int,int,int,int);
void FUN_004890c0(const void*);
void FUN_0044c700(int);
int rand();

// ===== 0x0046e080 =====
// Observed: difficulty help - register CL selects name-entry prompt, EAX 0..0xe selects era text; on completion sets DAT_0085a11c=0x4b, calls FUN_004879f0(0x1a,0), FUN_005096b0, FUN_005f0ddc timed layout, FUN_004881b0, FUN_004b06c0(&DAT_00869b48,...).
void FUN_0046e080_recon(int difficulty, int showNamePrompt)
{
    const char* text = nullptr;
    if (showNamePrompt != 0) {
        text = "Type your name and press ENTER to continue.";
    } else {
        switch (difficulty) {
        case 0: text = "The best choice for the new player. Includes numerous play suggestions and milder opponents."; break;
        case 1: text = "Try Journeyman once you've gotten your sea legs. Opponents are tougher and swordfights more decisive."; break;
        case 2: text = "Adventurer is for the experienced pirate. Sea battles are more dangerous and villains more treacherous."; break;
        case 3: text = "Only the bold will attempt the Rogue level. Skilled opponents will constantly challenge your command of the seas."; break;
        case 0xc: FUN_004f6090("Opportunities abound and success awaits. "); FUN_004f60b0("Spain is almost always at war with somebody, and not uncommonly with everybody! "); FUN_004f60b0("Since Spanish military power is a joke, the opportunities for plunder are legion. "); FUN_004f60b0("After a rich cruise against the hapless Spanish, no voyage is complete without a wild party at Tortuga, Barbados, or Curacao!"); goto layout;
        case 0xd: FUN_004f6090("This era is sometimes called the \"Golden Age of Buccaneering.\" "); FUN_004f60b0("There's plenty of warfare to legalize your actions, and a plethora of rich Spanish and non-Spanish ports to either raid or use as bases, as you prefer. "); goto layout;
        case 0xe: FUN_004f6090("Prospects in this era appear as good as the 1660s and 1670s. "); FUN_004f60b0("However pirate-hunting warships appear more frequently, while the non-Spanish ports are larger and better fortified. "); goto layout;
        default: DAT_0085a158 = 0; return;
        }
    }
    if (text) FUN_004f6090(text);
layout:
    if (DAT_00869b48 != 0) {
        DAT_0085a11c = 0x4b;
        FUN_004879f0(0x1a, 0);
        // FUN_005096b0(); FUN_005f0ddc(); timing-derived offsets are inferred
    }
}

// ===== 0x004102a0 =====
// Observed: retirement / loot-division flow. local_c = {5,10,0x14,0x1e,0x32}; iVar4 = local_c[DAT_0085a158]*DAT_00869ab4/100; health tiers via FUN_004048a0; three difficulty-continue branches comparing DAT_0085a158<4 and DAT_00869ab4>9999; month loop DAT_0085a150+=6000 with FUN_00460480/FUN_004888e0(0x39,...) and "@MONTH @NUM"; clamps DAT_00869ab4 to [100,99999].
int FUN_004102a0_recon(void)
{
    short local_c[5] = {5, 10, 0x14, 0x1e, 0x32};
    int share = (local_c[DAT_0085a158] * DAT_00869ab4) / 100;
    int health = FUN_004048a0();
    const char* msg = (health < 3)
        ? "Your health is @HEALTH and as the months pass you quickly become bored with life on land. "
        : "Though your health is @HEALTH, still as the months pass you quickly become bored with life on land. ";
    FUN_004f6090(msg, health);
    FUN_004f60b0("And so your flagship is refit and a bold crew assembled as you prepare to set sail for further adventures!\n");
    bool revert = false;
    if (DAT_0085a158 < 4 && 9999 < DAT_00869ab4) {
        FUN_004f60b0(" Continue as @DIFFICULTY captain.\n", DAT_0085a158);
        FUN_004f60b0(" Advance to @DIFFICULTY captain.\n", DAT_0085a158 + 1);
        FUN_004f60b0(" Retire from pirating.\n");
    } else if (DAT_0085a158 < 1 || 9999 < DAT_00869ab4) {
        FUN_004f60b0(" Continue as @DIFFICULTY captain.\n", DAT_0085a158);
        FUN_004f60b0(" Retire from pirating.\n");
        revert = true;
    } else {
        FUN_004f60b0(" Continue as @DIFFICULTY captain.\n", DAT_0085a158);
        FUN_004f60b0(" Revert to @DIFFICULTY captain.\n", DAT_0085a158 - 1);
        FUN_004f60b0(" Retire from pirating.\n");
    }
    if (health == 7) FUN_004f6090("Time and the ravages of the sea have taken their toll on your health. ");
    FUN_004879f0(0x1e, 0);
    int choice = FUN_00430190((DAT_0085a26c >> 4), (DAT_0085a268 >> 4), DAT_006f5896, 0, 0xffffffff, (int)FUN_004862a0);
    (void)revert; (void)choice; (void)share;
    FUN_004867b0();
    return 1;
}

// ===== 0x00419370 =====
// Observed: setup wizard. If DAT_008cac27==0 calls FUN_00403470. Stage/difficulty/nationality selectors via FUN_00430190 with "mutiny.pcx"; FUN_004add70(0x4b0/0x78a/0x8fc) for noon/sunset/night; random iVar5 = (rand()&0x80000003)+0x30; bad-guy tables mapping to DAT_0085a158=2/4 and local_4c codes 0x1e..0x2a.
void FUN_00419370_recon(void)
{
    if (DAT_008cac27 == 0) FUN_00403470();
    int r = (rand() & 0x80000003);
    if ((int)r < 0) r = (r - 1 | 0xfffffffc) + 1;
    int stage = r + 0x30;
    FUN_004f6090("Select Stage...\n Ship Deck 1\n Ship Deck 2\n Ship Deck 3\n Garden/Fountain\n Garden/Pool\n Tavern\n Ramparts\n");
    FUN_004f6090("Select Difficulty...\n Easy (Tutorial)\n Moderate\n Difficult\n Very Difficult\n Impossible\n");
    (void)stage;
    FUN_004f6090("Select Stage Time...\n Noon\n Sunset (1 pistol)\n Night (2 pistols)\n");
    FUN_004f6090("Select Nationality...\n Spanish\n English\n French\n Dutch\n Pirate\n");
    DAT_0072ccc4 = 1;
}

// ===== 0x004517b0 =====
// Observed: prison escape. Early return if DAT_008cac27!=0. Cursor save/restore pattern; strings "@PROP1/@PROP2" bribe, "Quietly avoiding the town guards..."; timed loops rand()%3+3 and rand()%6+6 with DAT_0085a150+=6000, FUN_00460480/FUN_004888e0(0x39,...), "@MONTH @NUM"; FUN_00451110/FUN_0048c160/FUN_00450cf0 escape check sets DAT_008c81f0=1; "Player_head_%s_rags.dds" + "player_head_yng.dds".
void FUN_004517b0_recon(int cityIndex)
{
    if (DAT_008cac27 != 0) return;
    FUN_004f6090("A greedy guard offers to let you escape in exchange for a bribe of @NUM gold pieces.\n I'll pay.\n I'll stay.\n");
    FUN_004f6090("Quietly avoiding the town guards, you attempt to sneak out of town!\n");
    FUN_004879f0(0x20, 0);
    FUN_00451110();
    if (FUN_0048c160() != 0) { DAT_008c81f0 = 1; return; }
    FUN_00450cf0();
    FUN_004f6090("The months pass slowly in @CITYNAME prison. ", DAT_008dbd08[cityIndex*3], DAT_008dbd0c[cityIndex*3], DAT_008dbd10[cityIndex*3]);
    FUN_004f60b0("Late one night you manage to pry loose the bars of your prison window. ");
    (void)cityIndex;
}

// ===== 0x0040b340 =====
// Observed: mission-caravan request. FUN_00486990(param_1,0); DAT_008c827f=0,DAT_008c827e=0; flag 0x10000 in DAT_00860b70[param_1*8]; strings "A ship carrying refugees from Europe...", " I will deliver them to @CITYNAME.", " I will escort them to @CITYNAME."; scans 4 nearby cities via FUN_0045fcb0 with Manhattan-distance calc (abs+2*abs)/2 threshold 0x9a and bit 2 test; choice via FUN_00430190 then FUN_0044eb10/FUN_0044ea50 and DAT_0085bf84[param_1*0x25].
void FUN_0040b340_recon(int cityId)
{
    FUN_00486990(cityId, 0);
    DAT_008c827f = 0; DAT_008c827e = 0;
    FUN_004f6090("A ship carrying refugees from Europe has arrived at our mission. ");
    FUN_004f60b0("These hard-working immigrants seek a home in the New World, can you help them?\n");
    FUN_004f60b0(" I will deliver them to @CITYNAME.\n");
    FUN_004f60b0(" I will escort them to @CITYNAME.\n");
    FUN_004f60b0(" Their problems do not concern me.\n");
    FUN_004879f0(0x30, 0);
}

// ===== 0x0040a670 =====
// Observed: pirate-recruitment dialog. DAT_008c827f=0; loop over 4 candidate cities; strings "My men have gambled away their last golden doubloons...", "Which city is most weakly defended?", " @CITYNAME has very few soldiers.", " @CITYNAME needs plundering."; same 0x9a proximity scan; dispatch via FUN_004a2080(0xffffffff,...)/FUN_004a21c0 and FUN_0044eb10(...,0,4,9).
void FUN_0040a670_recon(int cityId)
{
    DAT_008c827f = 0; DAT_008c827e = 0;
    FUN_004f6090("My men have gambled away their last golden doubloons. It is time to take to the seas to plunder and pillage! ");
    FUN_004f60b0("Which city is most weakly defended?\n");
    FUN_004f60b0(" @CITYNAME has very few soldiers.\n");
    FUN_004f60b0(" @CITYNAME needs plundering.\n");
    FUN_004f60b0(" The time is not right, captain.\n");
    FUN_004879f0(0x30, 0);
    (void)cityId;
}

// ===== 0x0040ae10 =====
// Observed: governor-agriculture quest. FUN_00486990(param_1,0); FUN_004890c0(&DAT_008c7340); guard DAT_0085bf84[param_1*0x25]==0 and 0x10000 flag; strings "'I have been appointed as the new governor of @CITYNAME...", "Our farmers have developed a disease-resistant variety of sugar cane...", " @CITYNAME could use these plants." / " @CITYNAME could benefit from your discovery."; distance scan over 4 cities, FUN_0044ea50/FUN_0044eb10(...,9,...) then DAT_0085bf84[param_1*0x25]=result, "We will send them at once, @PCNAME."
void FUN_0040ae10_recon(int cityId)
{
    FUN_00486990(cityId, 0);
    FUN_004890c0(&DAT_008c827f); // corpus DAT_008c7340 table handle; inferred
    FUN_004f6090("'I have been appointed as the new governor of @CITYNAME. ");
    FUN_004f60b0("I have big plans for economic growth. ");
    FUN_004f60b0("Our farmers have developed a disease-resistant variety of sugar cane, which we gladly share with our fellow colonists.\n");
    FUN_004f60b0(" @CITYNAME could use these plants.\n");
    FUN_004f60b0(" @CITYNAME could benefit from your discovery.\n");
    FUN_004f6090("We will send them at once, @PCNAME.\n", DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
    (void)cityId;
}

// ===== 0x0040ba80 =====
// Observed: native war-canoe dialog. FUN_00486990(param_1,0); DAT_00722734=0x33; strings "Our warriors grow tired of the presence of the European colonists...", "Which city is weak and ripe for destruction?", " @CITYNAME is corrupt and weak.", " @CITYNAME is weak and corrupt."; 4-city scan, FUN_00487850/FUN_00489130(&DAT_008c8288) cleanup, FUN_0044eb10(param_1,target,0,4,9); "We will crush the weaklings, @PCNAME." / "'Your face looks very familiar...'"
void FUN_0040ba80_recon(int cityId)
{
    FUN_00486990(cityId, 0);
    DAT_00722734 = 0x33;
    DAT_008c827f = 0; DAT_008c827e = 0;
    FUN_004f6090("Our warriors grow tired of the presence of the European colonists. Our war canoe is prepared.");
    FUN_004f60b0("Which city is weak and ripe for destruction?\n");
    FUN_004f60b0(" @CITYNAME is corrupt and weak.\n");
    FUN_004f60b0(" @CITYNAME is weak and corrupt.\n");
    FUN_004f60b0(" The time is not yet right, chief.\n");
    FUN_004f6090("We will crush the weaklings, @PCNAME.\n", DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
    FUN_00487850();
    (void)cityId;
}
