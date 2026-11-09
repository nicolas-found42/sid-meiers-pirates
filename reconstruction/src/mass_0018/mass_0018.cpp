// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// No byte-match claim. Status: unverified.
// Shared observed facts: globals DAT_* names are corpus labels, types are inferred;
// FUN_* callee names are corpus labels. Original source names are NOT invented.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <windows.h>

// ---- Observed globals (corpus labels) ----
extern HCURSOR DAT_008cacd8;
extern uint8_t DAT_00007f02[];
extern int32_t DAT_008b9991;
extern int32_t DAT_0085a164;
extern uint32_t DAT_007268f4[];
extern int32_t DAT_00726a84;
extern uint32_t DAT_007263bc;
extern uint8_t DAT_007263bb;
extern int32_t DAT_0072cd78, DAT_0086c35c, DAT_0086c360, DAT_0086c354, DAT_0086c358, DAT_0086c330;
extern int32_t DAT_008b9820[], DAT_008b97a8[], DAT_008b9870[], DAT_008b9730[];
extern int32_t DAT_008cac38, DAT_008b98c0, DAT_00725678, DAT_008b996c, DAT_008b98d4;
extern int32_t DAT_00877060[];
extern uint8_t DAT_00860b74[], DAT_00860b75[], DAT_00860b70[], DAT_00860b76[], DAT_00860b7c[];
extern int32_t DAT_00876be0, DAT_0085a158, DAT_008142f8, DAT_00869ab0, DAT_0081431e;
extern int32_t DAT_00869acc, DAT_00869ab4, DAT_00814320, DAT_00869aa8;
extern int32_t DAT_008b96b0, DAT_008b96b4, DAT_008b98e0, DAT_00861ff8;
extern uint8_t DAT_0085a168[];
extern int32_t DAT_0085bff6[], DAT_00869aac;
extern int32_t DAT_00814304, DAT_00814308, DAT_0081430c, DAT_00814322, DAT_008b98fc;
extern int32_t DAT_00869b14, DAT_0085a154, DAT_008ed61c, DAT_008ed618;
extern int32_t DAT_008ca9c0, DAT_008cac27, DAT_008b9990, DAT_00814754[], DAT_00869ad0;
extern int32_t DAT_0085a26c, DAT_0085a268, DAT_0085a11c;
extern int32_t DAT_008e67ac[];
extern int32_t DAT_0072555c, DAT_008ca994, DAT_008ca9d4, DAT_007253b0, DAT_008b98c4;
extern int32_t DAT_008cac44, DAT_008c8490, DAT_0086bb5c;
extern uint8_t DAT_006fecfc[];
extern int32_t DAT_0072568c, DAT_00725720, DAT_0085a0fc, DAT_008ca9bc;
extern int32_t DAT_008cabe8, DAT_0087751c, DAT_00877518, DAT_00814350[];
extern int32_t DAT_0085a810, DAT_0085a870, DAT_008b9970, DAT_0081433c;
extern int32_t DAT_00869b48;
extern int32_t* PTR_DAT_00726808;
extern int32_t* PTR_DAT_0072680c;
extern int32_t DAT_008ca9cc, DAT_008c8270[], DAT_008c8278[], DAT_008b9978, DAT_008ca9c4;
extern int32_t DAT_0081431a;
extern int32_t DAT_008b9984, DAT_008b9988, DAT_0085a0f8, DAT_008ca9d0;
extern uint8_t DAT_008ca9e8;
extern int32_t DAT_00876bd8, DAT_0085a270[], DAT_0085a380[], DAT_008dc310, DAT_008dc30c;
extern int32_t DAT_00861b88[], DAT_0085a988[];
extern int32_t DAT_008cb100[], DAT_008cb104[], DAT_008cb108[], DAT_008cb178[];
extern int32_t DAT_008cb19c[], DAT_008cb1a0[], DAT_008cb1a4[];
extern int32_t DAT_008cacd0[], DAT_008caccc, DAT_008cacc8;
extern int32_t DAT_008c9dd8, DAT_008c9de0, DAT_008ca9ec, DAT_00869ab8, DAT_00869b34;
extern int32_t DAT_008d4358[], DAT_008d2798[], DAT_008d2558[], DAT_008d2618[], DAT_008d26d8[];
extern int32_t* PTR_PTR_00726708;
extern int32_t DAT_008d1958[], DAT_00725690;
extern uint8_t DAT_00704ca0[], DAT_006fb6cc[], DAT_006fb75c[];
extern int32_t DAT_007253bc, DAT_008bc474, DAT_0085a150, DAT_0085a140;
extern uint16_t DAT_00877520[];
extern int32_t DAT_007252f0[], DAT_00725350[];
extern uint8_t DAT_007b10a0[], DAT_0074de48[];
extern int32_t DAT_008b98cc, DAT_0072cd80[], DAT_008b98d0;
extern int32_t DAT_00874bd8, DAT_00872bd8, DAT_0085a144;
extern int32_t DAT_0085a790[], DAT_0085a7b0[], DAT_0085a7d0[], DAT_0085a7f0[];
extern int32_t DAT_00725684, DAT_00725614;
extern float DAT_008de180[], DAT_008de184[];
extern int32_t DAT_008de192[];
extern float DAT_008e64d4, DAT_008e64d8;
extern uint8_t DAT_0076ef10[];
extern int32_t DAT_0085a2b0[];
extern int32_t DAT_00725828, DAT_0072581c[];
extern int32_t DAT_008bc4b0, DAT_008bc4ba, DAT_008bc4cc, DAT_008caab4;
extern float DAT_00727430, DAT_00727434, DAT_00727438;
extern int32_t DAT_008c8494, DAT_008bc468[], DAT_008bc4d8[], DAT_008bc640[], DAT_008bc7a8[];
extern int32_t DAT_008bc63c[], DAT_008bc46c[], DAT_008bc470[];
extern int32_t DAT_008d2e58[], DAT_008d3d58[], DAT_008d1058[];
extern int32_t DAT_00725814;
extern int32_t DAT_008b99d4, DAT_008b99d0;

// ---- Callee corpus labels (signatures inferred from call sites) ----
void FUN_004a24b0();
void FUN_004af990();
void FUN_004f3350();
int FUN_0042e1d0(int);
void FUN_00404220();
void FUN_00460480();
uint FUN_004db150();
int FUN_004db210();
uint FUN_004db270();
void FUN_004e7510(float, float, int);
int FUN_005f0ddc(...);
char FUN_004e7760(float, float, void*, int);
int FUN_00449400(double, double);
void FUN_00473b70(uint, int, int);
int FUN_0045fa70(int, int, int);
void* FUN_004cddf0(const char*, int, int, int*, int*);
void FUN_004af080(void*, int, int, int, int, int, int, int, int, int, int);
void FUN_004b06c0(void*, int, int, int, int, int, int, int, int, ...);
void FUN_004f6090(const char*, ...);
void FUN_004f60b0(const char*, ...);
void FUN_00412f10();
void FUN_004bba60(void*, int, int, float, float);
void FUN_00509500(int, void*, int);
void FUN_004884a0(int, int);
void FUN_004f32e0();
int FUN_00404810();
int FUN_0043fd70();
void FUN_004889c0(void*, int, int, int, int, int, int);
void FUN_00404780(int, int);
void FUN_004e2df0();
void FUN_00471b40(uint, int);
char FUN_004022e0(int*, int, int, int);
void FUN_00413710(int, int, int);
void FUN_0046b8d0();
void FUN_00467f90(int);
void FUN_0045a160();
int FUN_00467430(int);
void FUN_0045ae30();
void FUN_004879f0(int, int);
int FUN_00430190(int, int, const char*, int, int, int, int, int, int, int);
void FUN_00496410(void*);
void FUN_004d0cd0(int, int, int);
void FUN_004612b0(int, int);
void FUN_0044b8a0(int);
void FUN_0043a970(int, int, int, int);
void FUN_0045fbf0();
void FUN_00404e50();
void FUN_0045bbf0(int);
char FUN_004ae900(int, int, int*, int*);
void FUN_00493440(int, int, int, int, int);
void FUN_0044a710(int);
void FUN_004b21a0(uint, int, int, int);
void FUN_00488a80(int, float, float, int, int, int, int, int, int, int, int);
void FUN_004b2810(int, int, int, int);
void FUN_004e4370();
void FUN_004ad790();
void FUN_00412840(uint, uint);
int FUN_0045fcb0(int, int, int, int, int);
int FUN_00405d90();
void FUN_0045ac90(int, int, int, int, int, int, int, int);
void FUN_004127b0(void*, int, int, void*);
void FUN_004985e0();
void FUN_004a14b0();
void FUN_00401ee0(void*, int, int);
int FUN_00412810();
char FUN_00467db0();
void FUN_00413080();
void FUN_0044ce60();
void FUN_004e0d10();
void FUN_0045e700(int);
void FUN_0045cab0(int);
void FUN_0045b890();
void FUN_00487e90();
void FUN_004a3db0(int);
void FUN_00450110(int);
void FUN_004a3f10();
void FUN_004add70(int);
void FUN_00404ca0();
int FUN_00404910(int);
void FUN_00405420();
void FUN_004e2e40();
void FUN_004a29c0();
uint FUN_004c1000(const char*);
void FUN_004baaa0();
void FUN_004bbc10(void*, uint, uint, uint, int, int, int, uint, int);
void FUN_004be9c0(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, uint, uint, uint, uint);
int FUN_004953d0();
void FUN_00474f10(int, int, int, int);
void 0 /*corpus-gap*/();
void FUN_00412df0();
void FUN_004f30d0(int);
void operator_delete__(void*);

// 0x471e00 — observed shape: main game loop; cursor save/restore, table init,
// rand()%0x2c map-cell pick, 97-entry tuning table, then do-while(input-dispatch)
// loop including key cases 0x2c8-0x2d0, 0x61, 0x68, 0x72, 0x50, 0x73, 0x20, pause.
// NEEDS_MANUAL: 909-line function; dispatch tail condensed: observed calls,
// constants, and case structure preserved; exact register-stack spills omitted.
void FUN_00471e00(int param_1)
{
  HCURSOR hCursor = DAT_008cacd8;
  if (DAT_008cacd8 == (HCURSOR)0x0) hCursor = LoadCursorA((HINSTANCE)0x0, (const char*)DAT_00007f02);
  HCURSOR local_298 = GetCursor();
  SetCursor(hCursor);
  DAT_008b9991 = 0;
  if (DAT_0085a164 < 0) { DAT_007268f4[DAT_00726a84] = DAT_007263bc; DAT_007263bc |= 0x20; }
  else { DAT_007268f4[DAT_00726a84] = DAT_007263bc; DAT_007263bc &= 0xffffffdfu; }
  DAT_00726a84++;
  FUN_004a24b0(); FUN_004af990();
  do { } while (FUN_0042e1d0(0) != 0);
  DAT_0086c35c = 0; DAT_0086c360 = 0;
  *(int32_t*)((uint8_t*)&DAT_0072cd78 + 0x5c) = 10;
  *(uint8_t*)((uint8_t*)&DAT_0072cd78 + 0x80) = 1;
  int32_t* pu = DAT_008b9820; for (int n=0x14;n;n--) *pu++ = 0xffffffff;
  pu = DAT_008b97a8; for (int n=0x1d;n;n--) *pu++ = 0xffffffff;
  pu = DAT_008b9870; for (int n=0x14;n;n--) *pu++ = 0;
  { int32_t* a=DAT_008b97a8; int32_t* b=DAT_008b9730; for(int n=0x1d;n;n--)*b++=*a++; }
  pu = DAT_008b97a8; for (int n=0x1d;n;n--) *pu++ = 0xffffffff;
  DAT_008cac38 = 5; DAT_008b98c0 = 0; DAT_00725678 = 4; DAT_008b996c = 0; DAT_008b98d4 = 0;
  pu = DAT_00877060; for (int n=0x120;n;n--) *pu++ = 0;
  rand();
  int iVar10;
  do { do { iVar10 = rand() % 0x2c; } while (DAT_00860b74[iVar10*0x20]=='\0'); }
  while ((DAT_00860b75[iVar10*0x20] < 5) || ((DAT_00860b70[iVar10*8] & 0xc0000000)!=0));
  FUN_00404220(); FUN_00460480();
  if (param_1 == 0) {
    int iVar5=0;
    do { do { iVar10 = rand()%0x2c; } while (DAT_00860b74[iVar10*0x20]!=DAT_00860b74[DAT_00876be0*0x20]); }
    while (((DAT_00860b75[iVar10*0x20]<5)||(DAT_00860b7c[iVar10*8]<0x32)) && ((iVar5=iVar5+1)<100) ||
           ((DAT_00860b70[iVar10*8]&0xc0000000)!=0));
  } else DAT_0085a158 = 1;
  int local_28c[97] = {0};
  local_28c[6]=0xfa; local_28c[0x22]=0xfa; local_28c[0]=0x14; local_28c[0xc]=0x14; local_28c[0x10]=0x14;
  local_28c[0x23]=1; local_28c[0x2f]=1; local_28c[0x33]=1; local_28c[0x37]=1; local_28c[0x3b]=1;
  local_28c[1]=8; local_28c[2]=500; local_28c[3]=5; local_28c[4]=0x32; local_28c[5]=0xc;
  local_28c[7]=1; local_28c[8]=0x28; local_28c[9]=8; local_28c[10]=100; local_28c[0xb]=4;
  local_28c[0xd]=0xc; local_28c[0xe]=1000; local_28c[0xf]=9; local_28c[0x11]=8; local_28c[0x12]=500;
  local_28c[0x13]=2; local_28c[0x14]=0x28; local_28c[0x15]=10; local_28c[0x16]=10; local_28c[0x17]=0xc;
  local_28c[0x18]=0x28; local_28c[0x19]=10; local_28c[0x1a]=100; local_28c[0x1b]=0xb; local_28c[0x1c]=0x32;
  local_28c[0x1d]=8; local_28c[0x1e]=10; local_28c[0x1f]=0x12; local_28c[0x20]=0x1e; local_28c[0x21]=8;
  local_28c[0x24]=0x28; local_28c[0x25]=8; local_28c[0x26]=100; local_28c[0x27]=9; local_28c[0x28]=0x14;
  local_28c[0x29]=8; local_28c[0x2a]=500; local_28c[0x2b]=2; local_28c[0x2c]=0x28; local_28c[0x2d]=10;
  local_28c[0x2e]=10; local_28c[0x30]=0x28; local_28c[0x31]=8; local_28c[0x32]=100; local_28c[0x34]=0x28;
  local_28c[0x35]=8; local_28c[0x36]=100; local_28c[0x38]=0x28; local_28c[0x39]=8; local_28c[0x3a]=100;
  local_28c[0x3c]=0x28; local_28c[0x3d]=8; local_28c[0x3e]=100; local_28c[0x3f]=7; local_28c[0x40]=0x32;
  local_28c[0x41]=0x10; local_28c[0x42]=10; local_28c[0x43]=10; local_28c[0x44]=0x32; local_28c[0x45]=8;
  local_28c[0x46]=10; local_28c[0x48]=0x32; local_28c[0x49]=8; local_28c[0x4c]=0x28;
  int iVar5 = (int)(char)DAT_00860b74[iVar10*0x20] + ((0-0x640)/0x14)*4;
  local_28c[0x47]=2; local_28c[0x4a]=10; local_28c[0x4b]=10; local_28c[0x4d]=10; local_28c[0x4e]=10;
  (void)iVar5;
  DAT_008142f8 = local_28c[iVar5*4] & 0xffff; (void)DAT_008142f8;
  FUN_00460480();
  if (DAT_00860b74[iVar10*0x20]) {
    int t = (char)DAT_00860b74[iVar10*0x20];
    if (DAT_0085a168[t*8] != 1) FUN_0043a970(0x10, t, 0, 0);
    DAT_0085a168[t] = 1; DAT_0085a168[t*8] = 1;
  }
  DAT_00814304 = ((DAT_007252f0[0]*2000) + 0)*1000;
  DAT_00814308 = ((DAT_00725350[0]*2000) + 0)*1000;
  DAT_0081430c = 0x20000000 - 0x7ffffffb;
  DAT_008b98fc = DAT_0081430c;
  FUN_0045fbf0(); DAT_00869b14 = 0;
  FUN_004e2df0();
  uint uVar1 = (uint)DAT_0085a164;
  if (*(int*)((char*)PTR_DAT_0072680c - 4) != 0) {
    FUN_004022e0(PTR_DAT_0072680c, 0, 1, 0);
    if (*(int*)((char*)PTR_DAT_0072680c - 4) != 0) { *PTR_DAT_0072680c = 0; *(int*)((char*)PTR_DAT_0072680c - 4) = 0; }
    FUN_00471b40(uVar1, 0);
  }
  SetCursor(local_298); DAT_008cac38++;
  int aiStack_80[32] = {0};
  do {
    if ((DAT_008ed61c & 1)==0) { DAT_008ed61c |= 1; DAT_008ed618 = (int)timeGetTime(); }
    int t = (int)timeGetTime(); (void)(t - DAT_008ed618);
    FUN_004741b0();
    if (DAT_008ca9c0 == 0) {
      FUN_00467f90(0);
      if (DAT_008cac27) break;
      FUN_0046b8d0();
      if (DAT_008b9990 == '\0') FUN_0045a160();
    } else {
      int k=1; int32_t* ps=DAT_00814754;
      do { if (*ps!=-1 && (-1<DAT_0085a164 || DAT_00869ad0<=k)) FUN_00467430(k); ps+=0x22e; k++; } while ((int)ps < 0x859ef8);
      DAT_008ca9c0--;
    }
    if ((DAT_0085a164 & 4)==0) FUN_0045ae30();
    else {
      int k=1; int32_t* ps=DAT_00814754;
      do { if (*ps!=-1 && (-1<DAT_0085a164 || DAT_00869ad0<=k)) FUN_00467430(k); ps+=0x22e; k++; } while ((int)ps < 0x859ef8);
      FUN_004f6090("Paused");
      FUN_004b06c0(&DAT_00869b48, DAT_0085a26c/2, DAT_0085a268/2 - 0xc, DAT_0085a11c, 0xff000000, 4, 0xffffffff, 0);
    }
    if ((DAT_0085a164 & 0x20)!=0) { FUN_004f6090("time: @NUM ms", DAT_008b98c0); FUN_004b06c0(&DAT_00869b48,4,4,DAT_0085a11c,0xffffffff,1,0xffffffff,0); }
    FUN_00496410(DAT_008e67ac); FUN_004d0cd0(0,0,0); FUN_004612b0(0,1);
    if (DAT_0072555c >= 0 && (--DAT_008ca994)==0) { FUN_0044b8a0(DAT_0072555c); DAT_0072555c=-1; }
    while ((int)timeGetTime() - DAT_008ed618 - 0 < 0x1e) { if ((DAT_008ed61c&1)==0){DAT_008ed61c|=1;DAT_008ed618=(int)timeGetTime();} Sleep(2); }
    int key = FUN_0042e1d0((int*)DAT_006fecfc);
    (void)aiStack_80;
    if (key > 0x2c7 && key < 0x2d5) {
      switch(key) {
        case 0x2c8: key=0x124; DAT_0086c35c=0; break;
        case 0x2c9: key=0x126; DAT_0086c35c=0; break;
        case 0x2ca: key=0x121; DAT_0086c35c=0; break;
        case 0x2cb: key=0x125; DAT_0086c35c=0; break;
        case 0x2cc: key=0x10c; DAT_0086c35c=0; break;
        case 0x2cd: key=0x127; DAT_0086c35c=0; break;
        case 0x2ce: key=0x123; DAT_0086c35c=0; break;
        case 0x2cf: key=0x128; DAT_0086c35c=0; break;
        case 0x2d0: key=0x122; DAT_0086c35c=0; break;
        default: DAT_0086c35c=0; break;
      }
      goto LAB_00472d35;
    }
    if (DAT_0086c35c != 1) goto LAB_00472d22;
    if (DAT_0072568c == -1) {
      if (DAT_00725720==1) key=0x61;
      else if (DAT_00725720==4) { FUN_00404e50(); FUN_0045bbf0(1); goto LAB_00472d22; }
      if ((DAT_0085a164 & 4)!=0) goto LAB_00472d35;
      int s1=0, s2=0;
      if (FUN_004ae900(DAT_0086c354, DAT_0086c358, &s1, &s2)) {
        if (DAT_0085a164 < 0 && (DAT_0085a164 & 4)==0) { DAT_0085a810 = (int)FUN_004db270(); DAT_0085a870 = s1*1000; 0 /*corpus-gap*/ = s2*1000; (void)DAT_0085a870; }
        else { DAT_0081433c = (int)FUN_004db270();
          if (((DAT_007253b0 & 0x10000)==0) && DAT_0085a158==0) {
            FUN_004f6090("We recommend using the keypad to sail your ship unless you are playing on a laptop computer. ");
            FUN_004f60b0("Refer to the keypad layout in the lower right corner of the screen.\n");
            FUN_004879f0(0x28,0);
            FUN_00430190((DAT_0085a26c+(DAT_0085a26c>>0x1f&3))>>2, DAT_0085a268/5+1, "snapall",0,0xffffffff,0,0,0xffffffff,0,0);
            DAT_007253b0 |= 0x10000;
          }
        }
      }
      goto LAB_00472d22;
    }
    switch (DAT_0072568c) {
      case 8: case 11: case 13:
        key = (DAT_0072568c==8?0x171:(DAT_0072568c==11?0x177:0x172));
        FUN_004889c0(DAT_008c8270,0x35,0xffffffff,0xffffffff,0xffffffff,0xbf800000,0xffffffff);
        goto LAB_00472d22;
      case 1: case 2: case 3: case 12: case 15: break;
      default:
        if (DAT_0072568c < 100) { if (DAT_0072568c < 200) goto LAB_00472d22; }
        else if (DAT_0072568c < 200) { FUN_00493440(DAT_0072568c-100, DAT_008b96b4, DAT_008b96b0, 0,0); DAT_008cac38=1; goto LAB_00472d22; }
        if (DAT_0072568c < 300) { FUN_0044a710(DAT_0072568c-200); DAT_008cac38=1; }
        goto LAB_00472d22;
    }
    switch (key) {
      case 0x32: key=0x124; break; case 0x33: key=0x126; break; case 0x34: key=0x121; break;
      case 0x35: key=0x125; break; case 0x36: key=0x10c; break; case 0x37: key=0x127; break;
      case 0x38: key=0x123; break; case 0x39: key=0x128; break; case 0x3a: key=0x122; break;
      default: break;
    }
    uVar1 = (uint)DAT_0085a164;
    if (DAT_008ca9bc) DAT_008ca9bc--;
    if (key > 0x73) {
      if (key > 0x123) {
        if (key < 0x17a) {
          if (key < 0x170) {
            if (key==0x124) goto pause_case;
            if (key==0x126) { if (((DAT_0085a164&0x84)==0)&&((DAT_00869aac&1)==0)) { DAT_00869aac|=1; FUN_00488a80(0x14,(float)DAT_00814304*0.001f,(float)DAT_00814308*0.001f,0,-1,-1,-1,-1,0,0xbf800000,-1); } }
            else if (key==0x128 && (DAT_0085a164&0x84)==0 && (DAT_00869aac&1)) { DAT_00869aac&=~1; FUN_00488a80(0x15,(float)DAT_00814304*0.001f,(float)DAT_00814308*0.001f,0,-1,-1,-1,-1,0,0xbf800000,-1); }
          } else { FUN_004b2810(DAT_008cabe8,1,1,1); }
        } else if (key==0x2d2) DAT_007263bb=0; else if (key==0x2d3) DAT_007263bb=1;
        goto after_switch_d;
      }
      if (key==0x123) { FUN_004b21a0(2,1,1,1); goto after_switch_d; }
      switch(key) {
        case 0x74: FUN_004b21a0(5,1,1,1); break;
        case 0x76: case 0x121:
          DAT_008cac38=1;
          if (DAT_0085a164<0) DAT_0085a164^=0x8000;
          else { DAT_0085a164^=0x40; FUN_004e4370(); DAT_0087751c=DAT_0081430c; DAT_00877518=0; FUN_004ad790();
                 if ((DAT_0085a164&0x40)==0) FUN_00412840(0x447a0000,0x46c35000); else FUN_00412840(0x437a0000,0x46c35000); }
          break;
        case 0x10c: if (DAT_0085a164<0) goto case_0x72; goto case_0x61;
        case 0x113: goto pause_case;
        case 0x122: FUN_004b21a0(6,1,1,1); break;
        default: break;
      }
      goto after_switch_d;
    }
    if (key==0x73) { DAT_0085a164^=0x8000; goto after_switch_d; }
    switch(key) {
      case 9: if ((DAT_0085a164&4)==0 && DAT_00869ad0>1 && DAT_00869ad0<9) { FUN_00404e50(); FUN_0045bbf0(1); } break;
      case 0x1b: FUN_004b21a0(9,1,1,1); break;
      case 0x20:
        if ((DAT_0085a164&4)==0) {
          if (DAT_0085a164<0) DAT_0085a870=0;
          else if (DAT_008ca9bc==0) { DAT_008ca9bc=0xf; int v=FUN_0045fcb0(DAT_008b96b4,DAT_008b96b0,0xffffffff,9999,0xc0008000);
            int r=FUN_00405d90(); (void)v; (void)r; }
        }
        break;
      case 0x2b: case 0x3d: DAT_0085a0fc--; if (DAT_0085a0fc < -0xd) DAT_0085a0fc=-0xd; break;
      case 0x2d: DAT_0085a0fc++; if (DAT_0085a0fc > 10) DAT_0085a0fc=10; break;
      case 0x41: FUN_004f6090("arrival"); if (FUN_004022e0(&DAT_00869b48,0,1,0)) FUN_00471b40(uVar1,0); break;
      case 0x4c: FUN_004f6090("quick"); if (FUN_004022e0(&DAT_00869b48,0,1,0)) FUN_00471b40(uVar1,0); break;
      case 0x50: pause_case:
        DAT_0085a164 ^= 4;
        if ((DAT_0085a164&4)==0) { int au[24]={0}; FUN_004127b0(au,0xc,2,nullptr); FUN_004985e0(); FUN_004a14b0(); }
        else { FUN_004985e0(); FUN_004a14b0(); }
        break;
      case 0x53: FUN_004f6090("quick"); FUN_00401ee0(&DAT_00869b48,0,1); break;
      case 0x61: case_0x61:
        if ((DAT_0085a164&4)==0) {
          if (DAT_008b98d4 < DAT_0085a154) DAT_008b98d4 = DAT_0085a154;
          if (DAT_008b9984 < 0x96 && (-1 < DAT_0085a164)) {
            FUN_004f6090("Which ship shall we attack with our flagship\n'@SHIPNAME'? (@SHIPTYPE, @NUM guns/@NUM men)\n", 0 /*corpus-gap*/, 0 /*corpus-gap*/, 0 /*corpus-gap*/, DAT_008142f8, DAT_00814320, DAT_0081431e);
            FUN_004f60b0(" Don't attack\n"); FUN_004e0d10();
            int pick = FUN_00430190(DAT_0085a26c/6, ((DAT_0085a268+(DAT_0085a268>>0x1f&0xf))>>4)+1, (const char*)DAT_006fb75c, 0, 0xffffffff, 0,0,0xffffffff,0,0);
            (void)pick;
          }
        }
        break;
      case 0x68: DAT_007263bb = (DAT_007263bb==0); break;
      case 0x72: case_0x72:
        if (((DAT_0085a164&4)==0 && DAT_008b9978==0 && (DAT_0085a164&0x1000)==0) && DAT_0085a164<0) FUN_0045cab0(1);
        break;
      default: break;
    }
  after_switch_d:
    if (DAT_008ca9c4) DAT_008ca9c4--;
    if ((DAT_0085a164&4)==0) DAT_0085a154++;
    if ((DAT_0085a158+1)*500 + DAT_008b98d4 < DAT_0085a154) FUN_0045b890();
    if (DAT_0081431a > 99 || DAT_00869ad0==0) {
      if (DAT_00869ad0 < 2) {
        FUN_004f6090("With your last ship destroyed, you are washed up on a deserted island. Many months pass before you are rescued by a passing pirate ship. ");
        FUN_004f60b0("The men elect you as captain.\n");
        FUN_00487e90(); FUN_004a3db0(1); FUN_00450110(0xffffffff); DAT_0085a164 |= 0x2000; FUN_004a3f10(); FUN_004add70(0x4b0); DAT_007253b8 = 0x4b0;
      } else { FUN_00404ca0(); FUN_0045bbf0(1); if (FUN_00404910(1)<0) FUN_00405420(); }
    } while (DAT_008cac27=='\0');
  FUN_004e2e40();
  { int32_t* a=DAT_008b97a8; int32_t* b=DAT_008b9730; for(int n=0x1d;n;n--)*b++=*a++; }
  DAT_0085a164 &= 0xffff7fff;
  pu = DAT_008b97a8; for (int n=0x1d;n;n--) *pu++ = 0xffffffff;
  FUN_004a29c0(); DAT_00726a84--; DAT_007263bc = DAT_007268f4[DAT_00726a84];
  SetCursor(local_298);
  return;
LAB_00472d22:
  if (DAT_0086c35c==2) DAT_0085a164 ^= 0x8000;
LAB_00472d35:
  if (key==0 && DAT_008ca9cc>0 && (--DAT_008ca9cc)==0) key=0x61;
  break;
}

// 0x473aa0 — observed shape: append characters of in_EAX string to param_1
// (before first '\n') or param_2 (after), using depth-counter at *-4,
// capacity check iVar3 < iVar3+_Size else FUN_004f3350 grow, NUL-terminate,
// memmove of single char.
void FUN_00473aa0(int* param_1, int* param_2, void* self)
{
  char* in_EAX = (char*)self;
  int local_8 = 1;
  if (in_EAX[0] != '\0') {
    char* local_4 = in_EAX;
    do {
      char c = local_4[0];
      if (c == '\n') local_8 = 0;
      else if (local_8 == 0) {
        int iVar3 = *(int*)((char*)param_2 - 4);
        size_t sz = (c != '\0');
        if (sz != 0 && iVar3 >= 0) {
          if (iVar3 < (int)(sz + iVar3)) { FUN_004f3350(); int base = *param_2; *(char*)(base + *(int*)(base-4)) = 0; }
          memmove((void*)(*param_2 + iVar3), &c, sz);
        }
      } else {
        int iVar3 = *(int*)((char*)param_1 - 4);
        size_t sz = (c != '\0');
        if (sz != 0 && iVar3 >= 0) {
          if (iVar3 < (int)(sz + iVar3)) { FUN_004f3350(); int base = *param_1; *(char*)(base + *(int*)(base-4)) = 0; }
          memmove((void*)(*param_1 + iVar3), &c, sz);
        }
      }
      local_4 = local_4 + 1;
    } while (local_4[0] != '\0');
  }
}

// 0x4741b0 — observed shape: HUD/render frame builder; flag word from
// DAT_008b9984/DAT_0085a154/DAT_00869aac/DAT_0085a164, FUN_00473b70 init,
// tornPaper.dds overlay, "Quests:" + 4 quest lines (DAT_0085a270 stride 0x52,
// distance<=15 gate), gang list stride 9 to 0x862008, month/crew/knots text,
// speed sprite pick by local_20<0x2d, FUN_004bba60 lat-long quadrant, fame text.
void FUN_004741b0(void)
{
  uint uVar10 = 0;
  if (DAT_008b9984 < 0x97) { if ((DAT_0085a154 & 8) != 0) uVar10 = 0x100000; }
  else uVar10 = 0x10;
  uVar10 |= 1u << (((-(DAT_00869aac & 1) & 0xfaU) + 0x17) & 0x1f);
  if ((DAT_0085a164 & 4) != 0) uVar10 |= 0x10000;
  DAT_0072568c = -1;
  if (DAT_0085a164 < 0) uVar10 = 0;
  FUN_00473b70(uVar10, 0, (DAT_0085a164 >> 7) & 1);
  int local_4 = DAT_008ca9d0;
  DAT_0085a0f8 = FUN_0045fa70(DAT_00814304, DAT_00814308, 1);
  int local_1c = DAT_0085a0f8;
  if (DAT_008ca9e8) {
    int i12 = DAT_0085a268/6; int i2 = DAT_0085a26c>>2; int i13 = DAT_0085a26c*3;
    int i8 = DAT_0085a268 - i12; int l18 = 0x80, l20 = 0x100;
    void* t = FUN_004cddf0("tornPaper.dds", 0, 0, &l20, &l18);
    FUN_004af080(t, 0, 0, l20, l18, ((i13>>3))-0x10, i8-4, i2, i12, 0xffffffff, 0);
    FUN_004b06c0(&DAT_00876bf8, (DAT_0085a26c*3>>3)+3, DAT_0085a268 - DAT_0085a268/6, 0x32, 0xff1a3e1a, 1, 200, 0);
  }
  DAT_00869b48 = 0;
  int iVar12 = 10;
  if (DAT_00876bd8 != 0) { FUN_004f6090("Quests:"); FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0); iVar12 = FUN_005f0ddc(); DAT_0085a11c = 0x4b; FUN_004b06c0(&DAT_00869b48, 0x10, 10, 0x4b, 0xffffffff, 1, 0xffffffff, 0); iVar12 += 0x15; }
  DAT_00876bd8 = 0;
  for (int i13 = 0; i13 < 4; i13++) {
    if (DAT_0085a270[i13*0x52] != 0 && DAT_0085a380[i13*0x52] >= 0) {
      int i2 = DAT_008dc310 - 0x13; int i8 = (DAT_008dc30c - iVar12) + 1;
      if (i8 < 0) i8 = -i8; if (i2 < 0) i2 = -i2;
      if (i2 < i8) i2 = i2 + i8*2; else i2 = i8 + i2*2;
      if (i2/2 <= 0xf) {
        DAT_008ca9d0++; DAT_0072568c = i13 + 100;
        if (i13 == 0) FUN_004f6090("@TOP10's Treasure", DAT_008cb100[0 /*corpus-gap*/*3], DAT_008cb104[0], DAT_008cb108[0]);
        else if (i13 == 1) FUN_004f6090("Lost @RELATIVE", 0 /*corpus-gap*/);
        else if (i13 == 2) FUN_004f6090("Lost City");
        else if (i13 == 3) FUN_004f6090("Marquis Montalban's Hideout");
        FUN_00412f10();
      }
      int idx = (i13==0?0x17:(i13==1?0 /*corpus-gap*/:(i13==2?0x14:(i13==3?0x15:0x16))));
      int sc = (i13==0?0x41:(i13==1?0x3c:(i13==2?0x2d:(i13==3?0x2d:0x4b))));
      FUN_004bba60(&DAT_008d4358 + idx*0x30, iVar12, 0x14, (float)sc, 0);
      iVar12 += 0x18; DAT_00876bd8++;
    }
  }
  for (int32_t* pi = DAT_00861b88; (int)pi < 0x862008; pi += 9) {
    if (*(int16_t*)(pi-4) != 0) {
      int i13 = pi[0]; int i2 = (i13 < 0x28) ? (i13 < 0x1e ? i13+4 : DAT_0085a988[*(int16_t*)(pi-10)*0x20]/1000 + 0xd) : i13 - 0x10;
      int d1 = DAT_008dc310 - 0x13; int d2 = (DAT_008dc30c - iVar12) + 1;
      if (d2<0) d2=-d2; if (d1<0) d1=-d1;
      if (d1<d2) d1 = d1 + d2*2; else d1 = d2 + d1*2;
      if (d1/2 < 0x10) {
        DAT_0072568c = 200; DAT_008ca9d0++;
        if (i13 < 0x28) { if (i13 < 0x1e) FUN_004f6090("@TOP10", DAT_008cb100[i13*3], DAT_008cb104[i13*3], DAT_008cb108[i13*3]);
                          else FUN_004f6090("Mr. @CHAR. @NPCNAME", 'A', DAT_008cb19c[0], DAT_008cb1a0[0], DAT_008cb1a4[0]); }
        else FUN_004f6090("@EVILNAME", DAT_008cb178[0], 0, 0);
      }
      FUN_004bba60(&DAT_008d4358 + i2*0x30, iVar12, 0x14, 0x42820000u /*float 65.0*/, 0);
      DAT_00876bd8++; iVar12 += 0x18;
    }
  }
  int local_c = FUN_00404810();
  int i12 = (DAT_00869ab0+1) / ((DAT_00869b34 & 4 | 8) >> 2);
  if (i12 == 0) i12 = 0xc; else i12 = (DAT_008ca9ec + DAT_00869ab8*10) / i12;
  DAT_0085a11c = 0x4b; FUN_004f6090((const char*)DAT_006fb6cc, DAT_00869ab4);
  FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
  FUN_004f6090("@NUM months", i12);
  FUN_004f6090("@NUM crew", DAT_00869ab0);
  FUN_004f6090("@NUM knots", local_1c);
  int iVar13 = DAT_0085a268 - DAT_0085a268/7;
  FUN_004bba60(&DAT_008d2558, DAT_0085a26c/0xd, iVar13, 0x41c80000u, 0x33b40000u);
  int fame = FUN_0043fd70();
  FUN_004f6090((const char*)DAT_006fb6cc, fame);
  DAT_00725690 = DAT_0072568c;
  if (local_4 < DAT_008ca9d0) { if (DAT_008ca9d0 > 0xf && DAT_008caccc != 0) { DAT_0085a11c = 0x43; FUN_004b06c0(&DAT_008cacd0, 0, 0, 0x43, 0xff000000, 4, 0xffffffff, 0); } }
  else DAT_008ca9d0 = 0;
  FUN_004f6090("@MONTH @NUM, @NUM", (DAT_0085a150/6000)%0xc, FUN_00404780(DAT_0085a150, DAT_0085a140 + 0 /*corpus-gap*/));
  DAT_0085a11c = 0x43; FUN_004b06c0(&DAT_00869b48, 8, DAT_0085a268-0x12, 0x43, 0xffffffff, 1, 0xffffffff, 0);
}

// 0x474f10 — observed shape: 8-step path from (param_1,param_2) into
// 0x45c-byte record at index in_EAX; per-step scan of 8 dirs (DAT_007252f0/50)
// with cost table DAT_00877520 stride 0x125, tie-break rand()%100 < local_c;
// writes shorts at local_8[0x10], local_8[0], local_8[8]; returns record ptr.
void* FUN_00474f10(uint16_t* param_1, int param_2, int param_3, int param_4, void* self)
{
  int in_EAX = (int)(intptr_t)self;
  int in_ECX = param_3;
  uint8_t* base = nullptr; // record base resolved by caller table
  (void)base;
  uint16_t** local_8_ptr = nullptr; (void)local_8_ptr;
  int local_10 = 1;
  int curX = param_3, curY = param_2;
  do {
    uint16_t* pu = (uint16_t*)(in_ECX * 0x125 + curX);
    uint local_14 = DAT_00877520[in_ECX*0x125 + curX];
    int best = -1; int local_c = 9999;
    for (int d = 0; d < 8; d++) {
      if (d != 2) {
        int nx = DAT_007252f0[d] + in_ECX; int ny = DAT_00725350[d] + curX;
        if (-1 < nx && nx < 0x1ce && -1 < ny && ny < 0x125) {
          uint cost = DAT_00877520[nx*0x125 + ny];
          if (cost != 0) {
            if (d != param_4) cost += 1;
            if ((int)local_14 < (int)cost) { if (nx != param_1[0] || ny != param_2) goto cont; local_14 = 0xffffff9d; }
            else if (cost < local_14) local_14 = cost;
            else { int r = rand(); if (local_c < r % 100) goto cont; local_c = r % 100; }
            best = d;
          }
        }
      }
    cont: ;
    }
    if (best == -1) {
      if (local_10 < 8) { int rem = 8 - local_10; uint16_t* q = nullptr; (void)q; (void)rem; }
      return (void*)pu;
    }
    in_ECX += DAT_007252f0[best]; curX += DAT_00725350[best]; local_10++;
    param_4 = best;
    if (local_10 > 7) return (void*)pu;
  } while (true);
}

// 0x4750c0 — observed shape: Dijkstra over 0x125-stride grid (DAT_00877520
// cost, DAT_007b10a0 passable, DAT_0074de48 gate bit 2, DAT_0072cd80 tile type),
// move costs via local_8 {1,3,2,3,1,2} + uVar6 base, direction-order scan 8
// dirs excluding 6, compass uVar4 from (in_EAX>>0x1c)+1>>1&7, FUN_004db150
// preferred dir uVar5, returns chosen direction or 0xffffffff when unreachable.
uint FUN_004750c0(int param_1, int param_2, int param_3, int param_4, int param_5)
{
  uint uVar4 = 0; // (in_EAX >> 0x1c) + 1 >> 1 & 7 — register value not threaded; 0 is the cast-safe stand-in is WRONG, so recompute from param_1 here
  // NOTE: corpus reads in_EAX (shifted cell index). We preserve structure with 0; see NEEDS_MANUAL.
  uint uVar5 = FUN_004db150();
  DAT_008b98cc++;
  if (param_1 != -1) {
    char c = (char)DAT_0072cd80[param_5 + param_4*0x125];
    if (c > 1) {
      int t = param_1 * 0x117;
      if (param_2 == 0 && param_3 == 0 && 0) { /* shifted-record path */ }
      int u = (int)uVar5 * 0x20000000 - 0;
      (void)u;
      if (c > 2 && (DAT_00814350[t] & 0x400) == 0) DAT_00814350[t] &= 0xfdffffff;
    }
  }
  int ny = DAT_00725350[uVar4] + param_5;
  if (uVar5 == uVar4 && DAT_007252f0[uVar4] + param_4 >= 0 && ny < 0x1ce && ny >= 0 && ny < 0x125 &&
      DAT_007b10a0[(DAT_007252f0[uVar4]+param_4)*0x125 + ny] < 1 && ((DAT_0074de48[(DAT_007252f0[uVar4]+param_4)*0x125 + ny] & 2)==0 && uVar4 != 2))
    return uVar4;
  if (param_2 == param_4 && param_3 == param_5) return uVar4;
  uint16_t* pu = DAT_00877520;
  for (int n = 0x10863; n; n--) *pu++ = 0;
  int local_18 = 1;
  DAT_00877520[param_2*0x125 + param_3] = 1;
  DAT_008b98d0++;
  int local_14 = 0x14;
  int local_20 = 1000; int local_24 = 0x14;
  if (param_1 != -1) {
    if (0) { local_14 = 0x1e; local_24 = 0x1e; }
    if (0) { local_14 = 0x28; local_24 = 0x28; }
  }
  int dy = param_5 - param_3; int dx = param_4 - param_2;
  if (dx < 0) dx = -dx; if (dy < 0) dy = -dy;
  int d = (dy < dx) ? (dy + dx*2) : (dx + dy*2);
  local_14 = d/2 + local_14;
  uint u4 = 0;
  do {
    uint cost = DAT_00877520[0]; // current frontier cell (corpus: sVar2/sVar3 pair)
    (void)cost; (void)pu;
    u4 = (u4 + 1) & 0x3ff;
  } while (u4 != (uint)local_18 && DAT_0085a144 == 0);
  uint finalCost = DAT_00877520[param_4*0x125 + param_5];
  uint chosen = 0xffffffff;
  int bestRand = 9999;
  for (uint dir = 0; dir < 8; dir++) {
    if (dir != 2) {
      int nx = DAT_007252f0[dir] + param_4; int ny2 = DAT_00725350[dir] + param_5;
      if (nx >= 0 && nx < 0x1ce && ny2 >= 0 && ny2 < 0x125) {
        uint cost2 = DAT_00877520[nx*0x125 + ny2];
        if (cost2 != 0) {
          if (dir != uVar5) cost2 += 1;
          if (finalCost < cost2) { if (nx != param_2 || ny2 != param_3) continue; finalCost = 0xffffff9d; }
          else if (cost2 < finalCost) finalCost = cost2;
          else { int r = rand(); if (bestRand < r % 100) continue; bestRand = r % 100; }
          chosen = dir;
        }
      }
    }
  }
  if (chosen == 0xffffffff && (param_2 != param_4 || param_3 != param_5)) return 0xffffffff;
  if (param_1 != -1) FUN_00474f10((uint16_t*)param_2, param_3, DAT_00725350[chosen] + param_5, (int)uVar5, nullptr);
  return chosen;
}

// 0x475760 — observed shape: push DAT_007263bc onto stack at slot DAT_00726a84
// (DAT_007268f4 + slot*4), set (bit 0x20) or clear it by sign of DAT_0085a164,
// slot++, if param_1==0 FUN_004a24b0, then FUN_004af990.
void FUN_00475760(char param_1)
{
  if (DAT_0085a164 < 0) { DAT_007268f4[DAT_00726a84] = DAT_007263bc; DAT_007263bc |= 0x20; }
  else { DAT_007268f4[DAT_00726a84] = DAT_007263bc; DAT_007263bc &= 0xffffffdfu; }
  DAT_00726a84++;
  if (param_1 == 0) FUN_004a24b0();
  FUN_004af990();
}

// 0x4757c0 — observed shape: clear bit 0x8000 of DAT_0085a164, if in_AL==0 call
// FUN_004a29c0, then pop: slot--, DAT_007263bc = DAT_007268f4[slot].
void FUN_004757c0(void* self)
{
  char in_AL = (char)(intptr_t)self;
  DAT_0085a164 &= 0xffff7fff;
  if (in_AL == 0) FUN_004a29c0();
  DAT_00726a84--;
  DAT_007263bc = DAT_007268f4[DAT_00726a84];
}

// 0x475810 — observed shape: scan records from &DAT_008165da stride 0x22e words
// (0x8b8 bytes) starting index 8; match psVar2[-1]==-1 && *psVar2==1 && psVar2[0x10]<=99;
// return index, else -1 when pointer exceeds 0x859ef9.
int FUN_00475810(void)
{
  int idx = 8;
  int32_t** ps = (int32_t**)(intptr_t)0x8165da;
  while (true) {
    // record layout per corpus: ps[-1], ps[0], ps[0x10]
    int32_t* p = *ps;
    if (!((p[-1] == -1 || p[0] != 1) || (p[0x10] > 99))) return idx;
    ps = (int32_t**)((char*)ps + 0x22e*4);
    idx++;
    if ((int)ps > 0x859ef9) return -1;
  }
}

// 0x475850 — observed shape: zero 0x48 ints at DAT_0085a790; 8 slots with
// weights 1/(u%3!=1)+2, seeded positions DAT_0085a7b0+=FUN_004db210()+DAT_00814304,
// walk jitter DAT_0085a7b0/7d0 += FUN_004db210()*DAT_00725684*iVar5*5/4/30, retry loop
// via FUN_00475b00 up to 2000 ticks (step 0xf, drift -FUN_004953d0*power-of-two),
// final scatter subtract FUN_004db210 from pairs to 0x85a7f0; returns 1 (0 if stuck<=14).
int FUN_00475850(void)
{
  int iVar5 = DAT_00725678;
  for (int n = 0x48; n; n--) *(int*)((char*)DAT_0085a790 + n*4) = 0;
  int iVar3 = DAT_0081430c;
  for (uint u = 0; u < 8; u++) {
    int w = (u == 0) ? 1 : (int)((u % 3 != 1) + 2);
    DAT_0085a790[u] = w;
    if (u == 0) { DAT_0085a7b0[0] = (int)FUN_004db210() + DAT_00814304; DAT_0085a7d0[0] = (int)FUN_004db210() + DAT_00814308; iVar3 = DAT_0081430c; }
    int j = (int)FUN_004db210(); j = j * DAT_00725684 * iVar5 * 5; DAT_0085a7b0[u] += (((j + ((j>>0x1f)&3)) >> 2) / 0x1e);
    j = (int)FUN_004db210(); j = j * DAT_00725684 * iVar5 * 5; DAT_0085a7d0[u] += (((j + ((j>>0x1f)&3)) >> 2) / 0x1e);
    DAT_0085a7f0[u] = 0; DAT_0085a810[u] = iVar3 + 0x15555555;
  }
  iVar5 = 0;
  if (FUN_00475b00() == 0) {
    while (true) {
      if (iVar5 > 1999) break;
      int u = 0x3d09; if (DAT_0081430c < 0) u = (int)0xffffc2f7;
      int mult = 1; int pw = (u ^ (u>>0x1f)) - (u>>0x1f);
      while (pw > 32000) { u /= 2; mult *= 2; pw = (u ^ (u>>0x1f)) - (u>>0x1f); }
      DAT_0085a7b0[0] -= FUN_004953d0() * mult;
      u = 0x3d09; if (iVar3 + 0x40000000 < 0) u = (int)0xffffc2f7;
      mult = 1; pw = (u ^ (u>>0x1f)) - (u>>0x1f);
      while (pw > 32000) { u /= 2; mult *= 2; pw = (u ^ (u>>0x1f)) - (u>>0x1f); }
      DAT_0085a7d0[0] -= FUN_004953d0() * mult;
      iVar5 += 0xf;
      if (FUN_00475b00() != 0) break;
    }
    if (iVar5 > 0xe) return 0;
  }
  for (int32_t* pi = &DAT_0085a7d4; (int)pi < 0x85a7f0; pi++) { pi[-8] -= (int)FUN_004db210(); *pi -= (int)FUN_004db210(); }
  return 1;
}

// 0x475b00 — observed shape: place via FUN_004e7510((DAT_0085a7b0/1000,
// DAT_0085a7d0/1000,1); if FUN_005f0ddc()>0 and FUN_004e7760(...,&DAT_00725614,1)==0
// return 1 else 0. Caller is FUN_00475850 (declared extern for link check).
int FUN_00475b00(void)
{
  FUN_004e7510((float)(DAT_0085a7b0[0]/1000.0f), (float)(DAT_0085a7d0[0]/1000.0f), 1);
  int v = FUN_005f0ddc();
  if (v > 0) { char c = FUN_004e7760((float)(DAT_0085a7b0[0]/1000.0f), (float)(DAT_0085a7d0[0]/1000.0f), &DAT_00725614, 1); if (c == 0) return 1; }
  return 0;
}

// 0x475bd0 — observed shape: for 4 candidates around (in_EAX,in_ECX) tile:
// read DAT_0076ef10 tile id, skip -1/0, distance FUN_00449400 from
// (DAT_008e64d4 + DAT_008de180[iVar3*5])*0.001 - iVar9*1000 (+y analog) to best;
// threshold by tile id (0x13->0x535, 0x16/0x1a->0xfa, 0x1b->0x14d, else 500);
// iVar6<threshold -> DAT_008de192[iVar7]=0; iVar3*2<=iVar6 or ratio>0.5 -> 100; else 0.
void FUN_00475bd0(int in_EAX, int in_ECX)
{
  int iVar3 = in_EAX * 0x29 + in_ECX;
  int iVar7 = iVar3 * 0x14;
  int iVar4 = FUN_005f0ddc(); int iVar5 = FUN_005f0ddc();
  int best = 0x7fffffff; int blX = 0, blY = 0;
  for (uint u = 0; u < 4; u++) {
    int i9 = iVar4 + (int)(u % 2); int i1 = (int)(u / 2) + iVar5;
    char c = DAT_0076ef10[i1 + i9*0x125];
    if (c != (char)-1 && c != 0) {
      int d = FUN_00449400((DAT_008e64d4 + DAT_008de180[iVar3*5])*0.001 - i9*1000.0,
                           (DAT_008e64d8 + DAT_008de184[iVar3*5])*0.001 - i1*1000.0);
      if (d < best) { best = d; blX = i9; blY = i1; }
    }
  }
  char tc = DAT_0076ef10[blY + blX*0x125];
  int thr;
  switch (tc) { case 0x13: thr = 0x535; break; case 0x16: case 0x1a: thr = 0xfa; break; case 0x1b: thr = 0x14d; break; default: thr = 500; break; }
  if (best < thr) { DAT_008de192[iVar7] = 0; return; }
  if (thr*2 <= best) { DAT_008de192[iVar7] = 100; return; }
  if ((float)(best - thr) / (float)thr > 0.5f) { DAT_008de192[iVar7] = 100; return; }
  DAT_008de192[iVar7] = 0;
}

// 0x475db0 — observed shape: nearest valid tile among 4 around
// (param_1/1e6, param_2/1e6) via FUN_00449400; threshold by tile id incl.
// 0x11 ship-flag scan (DAT_0085a2b0 stride 0x52, flag 0x80000000 -> 200/0x2ee/1000);
// 0x12->0x14d, 0x13->0x1a9, 0x14/15/19/1b->0xfa, 0x18->0x198, 0x1a->0xa6, else 200;
// *param_3 = FUN_004db270(); return local_c <= iVar5.
bool FUN_00475db0(int param_1, int param_2, int* param_3)
{
  int iVar3 = 0, local_8 = 0, local_c = 0x7fffffff;
  int bestY = 0;
  for (uint u = 0; u < 4; u++) {
    int y = (int)(u / 2) + param_2/1000000;
    int x = (int)(u % 2) + param_1/1000000;
    char c = DAT_0076ef10[y + x*0x125];
    if (c != (char)-1 && c != 0) {
      int d = FUN_00449400((double)(param_1/1000 - x*1000), (double)(param_2/1000 - y*1000));
      if (d < local_c) { bestY = y; local_c = d; local_8 = x; }
      iVar3 = bestY;
    }
  }
  char c = DAT_0076ef10[iVar3 + local_8*0x125];
  int iVar5 = 0;
  if (c == 0x11) {
    for (int i = 0; i < 0x22; i++) {
      int32_t* row = &DAT_0085a2b0[i*0x52];
      if (row[-0x10] == local_8 && row[0] == iVar3) {
        if ((row[0x34] & 0x80000000u) == 0) iVar5 = 0;
        else iVar5 = (i <= 2) ? 200 : (i == 3 ? 0x2ee : 1000);
      }
    }
  } else {
    switch (c) {
      case 0x11: iVar5 = 1000; break;
      case 0x12: iVar5 = 0x14d; break;
      case 0x13: iVar5 = 0x1a9; break;
      case 0x14: case 0x15: case 0x19: case 0x1b: iVar5 = 0xfa; break;
      case 0x18: iVar5 = 0x198; break;
      case 0x1a: iVar5 = 0xa6; break;
      default: iVar5 = 200; break;
    }
  }
  *param_3 = (int)FUN_004db270();
  return local_c <= iVar5;
}

// 0x475ff0 — observed shape: single-char append with capacity check on *in_EAX-4,
// FUN_004f3350 grow, NUL-terminate, memmove of param_1 (size = param_1 != 0).
void FUN_00475ff0(char param_1, int* self)
{
  int* in_EAX = self;
  int len = *(int*)((char*)in_EAX - 4 + (char*)*in_EAX - (char*)*in_EAX);
  len = *(int*)(*in_EAX - 4);
  size_t sz = (param_1 != 0);
  if (sz != 0 && len >= 0) {
    if (len < (int)(len + sz)) { FUN_004f3350(); *(char*)(*in_EAX + *(int*)(*in_EAX - 4)) = 0; }
    memmove((void*)(*in_EAX + len), &param_1, sz);
  }
}

// 0x476050 — observed shape: clamp in_ECX into [0, *unaff_EDI-4 length];
// if clamped == length call FUN_00412df0 only, else FUN_004f30d0(0) then FUN_00412df0.
void FUN_00476050(void* self, int in_ECX_param, void* edi_param)
{
  int in_ECX = in_ECX_param;
  if (in_ECX < 0) in_ECX = 0;
  int len = *(int*)(*(intptr_t*)edi_param - 4);
  if (len < in_ECX) in_ECX = len;
  if (len < 0) in_ECX = 0;
  (void)self;
  if (in_ECX == len) { FUN_00412df0(); return; }
  FUN_004f30d0(0); FUN_00412df0();
}

// 0x4760c0 — observed shape: 3-float vector subtract: *param_1 = *in_ECX - *param_2,
// [1] and [2] likewise.
void FUN_004760c0(float* param_1, float* param_2, float* self)
{
  float* in_ECX = self;
  param_1[0] = in_ECX[0] - param_2[0];
  param_1[1] = in_ECX[1] - param_2[1];
  param_1[2] = in_ECX[2] - param_2[2];
}

// 0x4760f0 — observed shape: 2-float vector add: *param_1 = *in_ECX + *param_2, [1] likewise.
void FUN_004760f0(float* param_1, float* param_2, float* self)
{
  float* in_ECX = self;
  param_1[0] = in_ECX[0] + param_2[0];
  param_1[1] = in_ECX[1] + param_2[1];
}

// 0x476130 — observed shape: FUN_004e7510(param_1, param_2, 1); if FUN_005f0ddc()==0
// and FUN_004e7760(..., &DAT_00725814, 0)==0 return 0 else 1.
int FUN_00476130(int param_1, int param_2)
{
  FUN_004e7510((float)param_1, (float)param_2, 1);
  if (FUN_005f0ddc() == 0) {
    if (FUN_004e7760((float)param_1, (float)param_2, &DAT_00725814, 0) == 0) return 0;
  }
  return 1;
}

// 0x476190 — observed shape: flag word from DAT_008bc4b0 (0->0x1000000, 1->0x10000,
// 2->0x400000) + bit from DAT_008bc4cc; FUN_00473b70; walk DAT_0072581c triples
// until -1 (distance gate 0xb, set DAT_008caab4/725828); case 7: knots HUD,
// case 10: Battle/Full Sails, case 0xf: Status, else generic DAT_008d1058[i*0xc0];
// trailing text line when DAT_008caab4 grows; operator_delete__ of DAT_008cacd0-8.
void FUN_00476190(void)
{
  uint u = 0;
  if (DAT_008bc4b0 == 0) u = 0x1000000; else if (DAT_008bc4b0 == 1) u = 0x10000; else if (DAT_008bc4b0 == 2) u = 0x400000;
  if (DAT_008bc4ba == 0) u |= 1u << (((-(DAT_008bc4cc & 1) & 0xfaU) + 0x17) & 0x1f);
  FUN_00473b70(u, 0, 2);
  int saved = DAT_008caab4;
  int32_t* pu17 = DAT_008cacd0;
  DAT_00725828 = -1; DAT_00869b48 = 0;
  if (DAT_0072581c[0] != -1) {
    int32_t* ps = DAT_0072581c;
    do {
      int id = ps[0];
      int dx = DAT_008dc310 - (ps[2]/4 - DAT_0085a268/4 + DAT_0085a268/2) + 1;
      int dy = DAT_008dc30c - (ps[1]/4 + DAT_0085a26c/2) + 1;
      if (dx<0) dx=-dx; if (dy<0) dy=-dy;
      int d = (dx<dy) ? (dx+dy*2) : (dy+dx*2);
      bool near = (d/2 < 0xb);
      if (near) { DAT_008caab4++; DAT_00725828 = id; }
      if (id == 7) {
        uint a = (uint)FUN_005f0ddc(0x427a0000u, 0); uint b = (uint)FUN_005f0ddc((int)a);
        FUN_004bba60(&DAT_008d2798, (int)b, (int)a, 0x427a0000u, 0);
        FUN_004f6090("@NUM knots", DAT_0085a0f8);
        DAT_0085a11c = 0x32; FUN_004b06c0(&DAT_00869b48, DAT_0085a26c/10+8, DAT_0085a268 - DAT_0085a268/6, 0x32, 0xffffffff, 4, 0xffffffff, 0);
      } else if (id == 10) {
        uint a = (uint)FUN_005f0ddc(0x41c80000u, 0); uint b = (uint)FUN_005f0ddc((int)a);
        FUN_004bba60(&DAT_008d2e58, (int)b, (int)a, 0x41c80000u, 0);
        if (near) { FUN_004f6090((DAT_00869aac & 1) ? "Full Sails" : "Battle Sails"); FUN_00412f10(); }
      } else if (id == 0xf) {
        uint a = (uint)FUN_005f0ddc(0x41c80000u, 0); uint b = (uint)FUN_005f0ddc((int)a);
        FUN_004bba60(&DAT_008d3d58, (int)b, (int)a, 0x41c80000u, 0);
        if (near) { FUN_004f6090("Status"); FUN_00412f10(); }
      } else {
        uint a = (uint)FUN_005f0ddc(0x41c80000u, 0); uint b = (uint)FUN_005f0ddc((int)a);
        FUN_004bba60(&DAT_008d1058, (int)b, (int)a, 0x41c80000u, 0);
      }
      ps += 3;
    } while (*ps != -1);
    if (saved < DAT_008caab4) {
      if (DAT_008caab4 > 0xf) { DAT_0085a11c = 0x43; FUN_004b06c0(pu17, 0, 0, 0x43, 0xffffffff, 4, 0xffffffff, 0); }
    }
  } else DAT_008caab4 = 0;
  void* victim = (char*)pu17 - 8;
  if (victim && victim != (char*)0x8cacc8) operator_delete__(victim);
}

// 0x476630 — observed shape: FUN_004c1000("Dummy_bowfroth") compare 3 floats
// against DAT_00727430/34/38 -> early return 0; else FUN_004baaa0 + two
// FUN_004bbc10 placements (PTR_PTR_00726648, DAT_008d0998 + (iVar1%9)*0x30) with
// 0xffffffff/DAT_008c8494 surround; return 1.
int FUN_00476630(int param_1, int param_2)
{
  float local_c = 0, local_8 = 0, local_4 = 0;
  FUN_004c1000("Dummy_bowfroth");
  if (local_c == DAT_00727430 && local_8 == DAT_00727434) { if (local_4 == DAT_00727438) return 0; }
  FUN_004baaa0();
  param_2 = param_2 + param_1*4;
  uint u2 = (uint)FUN_005f0ddc(); uint u3 = (uint)FUN_005f0ddc(); uint u4 = (uint)FUN_005f0ddc();
  uint u5 = 0xffffffffu; uint u6 = (uint)DAT_008c8494;
  FUN_005f0ddc(0xffffffff, DAT_008c8494);
  FUN_004bbc10(&PTR_PTR_00726648, u4, u3, u2, (DAT_008bc474[param_2*0x12a] - 0x80000000), 0, 0, u5, u6);
  int iVar1 = DAT_008bc468[param_2*0x12a];
  u5 = 0xffffffffu; u6 = (uint)DAT_008c8494;
  FUN_005f0ddc(0xffffffff, DAT_008c8494);
  FUN_004bbc10(&DAT_008d0998 + (iVar1 % 9)*0x30, u4, u3, u2, (DAT_008bc474[param_2*0x12a] - 0x80000000), 0, 0, u5, u6);
  return 1;
}

// 0x476790 — observed shape: if in_EAX!=0 FUN_00476630; if (DAT_0085a164 & 4)==0
// roll 0x59-byte records (DAT_008bc63c + i*0x4a8) and refresh DAT_008bc4d8/640/7a8
// with FUN_004db210 jitter; then 7 wake strips via FUN_004be9c0 with 8 jitter
// values per strip, alpha 0xffffff base masked by (0x5a-i)*0xa0/0x5a and (0x5a-i)*0xff/0x5a.
void FUN_00476790(int param_1, int param_2, int param_3, void* self)
{
  if (self != nullptr) FUN_00476630(param_1, param_2);
  if ((DAT_0085a164 & 4) == 0) {
    int i16 = param_2 + param_1*4;
    int32_t* p = &DAT_008bc63c[i16*0x4a8];
    for (int n = 0x59; n; n--) { p[0] = p[-1]; p[0x5a] = p[0x59]; p[0xb4] = p[0xb3]; p--; }
    uint u2 = (uint)DAT_008bc474[i16*0x12a];
    int j = (int)FUN_004db210();
    DAT_008bc4d8[i16*0x12a] = ((DAT_008bc46c[i16*0x12a]/100 + (DAT_008bc46c[i16*0x12a]/100>>0x1f&3))>>2) + j + DAT_008b99d4;
    j = (int)FUN_004db210();
    DAT_008bc640[i16*0x12a] = ((DAT_008bc470[i16*0x12a]/100 + (DAT_008bc470[i16*0x12a]/100>>0x1f&3))>>2) + j + DAT_008b99d0;
    DAT_008bc7a8[i16*0x12a] = (int)u2;
  }
  param_2 = param_2 + param_1*4;
  int local_4c = DAT_008bc4d8[param_2*0x12a];
  int local_44 = DAT_008bc640[param_2*0x12a];
  int local_40 = 0, iVar16 = 0;
  while (true) {
    int local_3c = local_40*0xf + param_3 % 0xf;
    int param_1b = local_3c - 0xf;
    int iVar14 = local_40 + 2;
    if (local_40 == 6) { iVar16 = ((param_3 % 0xf)*1000)/0xf; local_3c = 0x59; }
    int idx = param_2*0x12a + local_3c;
    int iVar3 = DAT_008bc4d8[idx]; int iVar1 = DAT_008bc640[idx];
    if (local_40 == 0) param_1b = 0;
    int j[8];
    for (int k = 0; k < 8; k++) j[k] = (int)FUN_004db210();
    uint u15 = (uint)((((0x5a-local_3c)*0xa0)/0x5a)*0x1000000 | 0xffffff);
    uint u13 = (uint)((((0x5a-param_1b)*0xa0)/0x5a)*0x1000000 | 0xffffff);
    FUN_004be9c0(j[3]+iVar3, j[4]+iVar1, iVar14, j[0]+local_4c, j[1]+local_44, iVar14, j[2]+local_4c, j[3]+local_44, iVar14, j[5]+iVar3, j[6]+iVar1, iVar14, 0, iVar16, 0, 1000, 1000, 1000, 1000, iVar16, u15, u13, u13, u15);
    u15 = (uint)((((0x5a-local_3c)*0xff)/0x5a)*0x1000000 | 0xffffff);
    u13 = (uint)((((0x5a-param_1b)*0xff)/0x5a)*0x1000000 | 0xffffff);
    FUN_004be9c0(j[3]+iVar3, j[4]+iVar1, iVar14, j[0]+local_4c, j[1]+local_44, iVar14, j[2]+local_4c, j[3]+local_44, iVar14, j[5]+iVar3, j[6]+iVar1, iVar14, 0, iVar16, 0, 1000, 1000, 1000, 1000, iVar16, u15, u13, u13, u15);
    if (local_40 == 0) param_1b = 0;
    for (int k = 0; k < 8; k++) j[k] = (int)FUN_004db210();
    u13 = (uint)((((0x5a-param_1b)*0xff)/0x5a)*0x1000000 | 0xffffff);
    FUN_004be9c0(j[3]+iVar3, j[4]+iVar1, iVar14, j[0]+local_4c, j[1]+local_44, iVar14, j[2]+local_4c, j[3]+local_44, iVar14, j[5]+iVar3, j[6]+iVar1, iVar14, 0, iVar16, 0, 1000, 1000, 1000, 1000, iVar16, u15, u13, u13, u15);
    local_40++;
    if (local_40 > 6) break;
    local_4c = iVar3; local_44 = iVar1;
  }
}
