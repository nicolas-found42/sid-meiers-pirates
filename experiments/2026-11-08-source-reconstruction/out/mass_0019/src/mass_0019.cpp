// Reconstruction batch mass_0019 — Sid Meier's Pirates! (2004) PE32 i386.
// Ghidra 12.2 pseudocode translated to C++ candidate definitions.
// Image 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdlib>
#include <cmath>

extern unsigned char DAT_008ba3d8[]; // table base 0x8ba3d8, stride 0x20 (8 ints)
extern unsigned int DAT_008b99dc[]; // set at iVar2*0x10 offsets
extern void* DAT_008caa00[];        // per-slot vtable ptrs
extern void* DAT_008e9ff0;
extern int DAT_008bd768;
extern int DAT_008c73c8;
extern int DAT_008b99d8[];
extern int DAT_008b99d4;
extern int DAT_008b99d0;
extern int DAT_008b99b0;
extern int DAT_008b99a0;
extern int DAT_008b99ac;
extern int DAT_008b99b8;
extern int DAT_008b99a8;
extern int DAT_008b99c4;
extern int DAT_008b99c0;
extern int DAT_008b99bc;
extern int DAT_008bc4dc;
extern int* DAT_008caa00_int; // alias when needed
extern int DAT_0085a158;
extern int DAT_0085a164;
extern int DAT_0085a0f8;
extern int DAT_0085a0fc;
extern int DAT_0085a26c;
extern int DAT_0085a268;
extern int DAT_0085a11c;
extern int DAT_0085a128;
extern int DAT_0085a124;
extern int DAT_0085a134;
extern int DAT_0085a138;
extern int DAT_0085a12c;
extern int DAT_007253bc;
extern int DAT_007253b8;
extern int DAT_00725800;
extern int DAT_00725804;
extern int DAT_007257fc;
extern int DAT_007257f8;
extern int DAT_008bc468[];
extern int DAT_008bc46c[];
extern int DAT_008bc470[];
extern int DAT_008bc474[];
extern int DAT_008bc478[];
extern int DAT_008bc480[];
extern int DAT_008bc484[];
extern int DAT_008bc488[];
extern int DAT_008bc490[];
extern int DAT_008bc494[];
extern int DAT_008bc498[];
extern unsigned int DAT_008bc4cc[];
extern int DAT_008bc4d0[];
extern int DAT_008bc4b0[];
extern int DAT_008bc4ac[];
extern int DAT_008bc4a4[];
extern int DAT_008bc4a8[];
extern int DAT_008bc4b4[];
extern int DAT_008bc4c8[];
extern int DAT_008bc4ba[];
extern int DAT_008bd708[];
extern int DAT_008bd70c[];
extern int DAT_008bd710[];
extern int DAT_008bd714[];
extern int DAT_008bd718[];
extern int DAT_008bd71c[];
extern int DAT_008bd720[];
extern int DAT_008bd724[];
extern int DAT_008bd728[];
extern int DAT_008bd730[];
extern int DAT_008bd734[];
extern int DAT_008bd748[];
extern int DAT_008bd74c[];
extern int DAT_008b99d8_arr[];
extern unsigned char DAT_008ba668[];
extern unsigned char DAT_008ba458[];
extern int DAT_008e66b4;
extern int DAT_008e66b8;
extern int DAT_008e66bc;
extern int DAT_008e6694[];
extern int DAT_008e66a4[];
extern int DAT_008e6690[];
extern int DAT_008e6660[];
extern int DAT_008e6664[];
extern int DAT_008e64e0[];
extern int DAT_008cc498[];
extern int DAT_008cc3d8[];
extern int DAT_008cc618[];
extern int DAT_008caa00_arr[];
extern int DAT_00723b08[];
extern int DAT_00723b0c[];
extern int DAT_00723b10[];
extern int DAT_00723b14[];
extern int DAT_00723b18[];
extern int DAT_00723b24[];
extern int DAT_007257d4[];
extern int DAT_00725808[];
extern int DAT_00724238[];
extern int DAT_00714238[];
extern int DAT_00814304[];
extern int DAT_00814308[];
extern int DAT_0081430c;
extern int DAT_0081431a[];
extern int DAT_0081431e[];
extern int DAT_00814318[];
extern int DAT_00814320[];
extern int DAT_00814322[];
extern int DAT_00814324[];
extern int DAT_00814328[];
extern int DAT_00814330[];
extern int DAT_00814350[];
extern int DAT_0081435a[];
extern int DAT_008142f8[];
extern int DAT_008142fc[];
extern int DAT_008142fa[];
extern int DAT_00869acc;
extern int DAT_00869aac;
extern int DAT_00869ab0;
extern int DAT_00869ab4;
extern int DAT_00869b34;
extern int DAT_00869ad0;
extern int DAT_008be9a8;
extern int DAT_00726820;
extern int DAT_00725d98;
extern int DAT_007263a0;
extern int DAT_007263bb;
extern int DAT_007263bc;
extern int DAT_008ea000;
extern int DAT_008e9fe8;
extern int DAT_008e9fec;
extern int DAT_008e9fd8;
extern int DAT_008e66d0;
extern int DAT_008e66d8;
extern int DAT_008ca930;
extern int DAT_008ca934;
extern int DAT_008ca9fc;
extern int DAT_008caaa0;
extern int DAT_008caaa4;
extern int DAT_008caba8;
extern int DAT_008c84dc;
extern int DAT_008c8494;
extern int DAT_007263bc_alias;
extern int DAT_00726a84;
extern int DAT_007270e8[];
extern int DAT_007270f8[];
extern int DAT_0072cd74;
extern int DAT_0072cd78;
extern int DAT_00727444;
extern int DAT_008cacd8;
extern int DAT_008cac27;
extern int DAT_008cac00;
extern int DAT_008c9df4;
extern int DAT_008c9dd8;
extern int DAT_008c9de0;
extern int DAT_008ed61c;
extern int DAT_008ed618;
extern int DAT_00886c330;
extern int DAT_0086c35c;
extern int DAT_0086c354;
extern int DAT_0086c358;
extern int DAT_00725828;
extern int DAT_00869b48[];
extern int DAT_0072387c;
extern int DAT_00861b82[];
extern int DAT_00861b88[];
extern int DAT_00861ff8[];
extern int DAT_00861ffc[];
extern int DAT_00861b78[];
extern int DAT_00862000[];
extern int DAT_008cb100[];
extern int DAT_008cb104[];
extern int DAT_008cb108[];
extern int DAT_008cb178[];
extern int DAT_008cb19c[];
extern int DAT_008cb100_arr[];
extern int DAT_0085a970[];
extern int DAT_0085a98c[];
extern int DAT_008cabd4;
extern int DAT_008e9f5c;
extern int DAT_00869a78[];
extern int DAT_00860ea8;
extern int DAT_00860eac;
extern int DAT_008bdc14;
extern int DAT_008b9998;
extern int DAT_008b9994;
extern int DAT_008b99a4;
extern int DAT_008cac44;
extern int DAT_008c73c0;
extern int DAT_008c84b0;
extern int DAT_008c73bc;
extern int DAT_007253b0;
extern int DAT_008c8498;
extern int DAT_008db618;
extern int DAT_008db61c;
extern int DAT_008db620;
extern int DAT_008d7ad8[];
extern int DAT_008d74d8[];
extern int DAT_008d3998[];
extern int DAT_008ccd98[];
extern int DAT_008c7408[];
extern int DAT_008c740c[];
extern int DAT_008cca98[];
extern int DAT_008cd098[];
extern int DAT_008cd0bd[];
extern int DAT_008cd458[];
extern int DAT_008cd47d;
extern int DAT_008cce58[];
extern int DAT_008cd8d8[];
extern int DAT_008d74d8_arr[];
extern int DAT_008cc6d8[];
extern int DAT_008e8f10[];
extern int DAT_008e8f14[];
extern int DAT_008e8f18[];
extern int DAT_007268e0;
extern int DAT_007268e8;
extern int DAT_007268dc;
extern int DAT_008caba8_alias;
extern int DAT_008bc974[];
extern int DAT_008bc970[];
extern int DAT_008bc910[];
extern int DAT_00725814[];
extern int DAT_008ca92c;
extern int DAT_00869b34_alias;

int rand();
int srand(unsigned int);
unsigned long timeGetTime();
void Sleep(unsigned long);
int joyGetPosEx(unsigned int, void*);
static void* LoadCursorA(void*, const void*);
static void* GetCursor();
static void SetCursor(void*);

// ---- helpers (FUN_*) ----
extern int FUN_00477450(int);
extern int FUN_00476130(int,int);
extern int FUN_004db210(...);
extern int FUN_004db270();
extern int FUN_004bc790(unsigned int);
extern int FUN_004bc5c0(unsigned int);
extern int FUN_0042d500(int,const char*);
extern int FUN_004a62f0();
extern int FUN_004a5270();
extern int FUN_004af990();
extern int FUN_004af760();
extern int FUN_004afdb0(int);
extern int FUN_004ab230();
extern int FUN_004a5740(int,int);
extern int FUN_004a5270_alias();
extern int FUN_004ae900(int,int,void*,void*);
extern int FUN_0042e440();
extern int FUN_004b21a0(int,int,int,int);
extern int FUN_004985e0();
extern int FUN_004a14b0();
extern int FUN_004888e0(int,int,int,int);
extern int FUN_00488a80(int,float,float,float,int,int,int,int,int,int,int);
extern int FUN_00488b00(void*,int,float,float,float,int,int,int,int,int,int);
extern int FUN_004879f0(int,int);
extern int FUN_004f6090(const char*,...);
extern int FUN_004f60b0(const char*,...);
extern int FUN_00430190(int,int,const char*,int,int,int,int,int,int,int);
extern int FUN_004e7510(float,float,int);
extern int FUN_004e7760(float,float,void*,int);
extern int FUN_00412840(int,int);
extern int FUN_00412810();
extern int FUN_005f0ddc(...);
extern int FUN_00533c78(int);
extern int FUN_004baa30(int,const char*,int,int,int,int,int,int,int,int,int);
extern int FUN_004baaa0(const char*,int,int,int);
extern int FUN_004baaa0_3(...);
extern int FUN_004bdca0(int,int,int,int,int,int,int,int,int,int);
extern int FUN_004bc9c0(void*);
extern int FUN_004bcx50(...);
extern int FUN_004c2200(int,int);
extern int FUN_004bc950(const char*,int);
extern int FUN_004bc7e0(int,int);
extern int FUN_004bca60();
extern int FUN_004bcd00(unsigned int);
extern int FUN_004bcac0();
extern int FUN_004bc5c0_alias(unsigned int);
extern int FUN_004bc740(int);
extern int FUN_004bba60(void*,int,int,int,int);
extern int FUN_004b06c0(void*,int,int,int,int,int,int,int);
extern int FUN_004884a0(int,int);
extern int FUN_004af080(int,int,int,int,int,int,int,int,int,int,int);
extern int FUN_004cddf0(int,int,int,int*,int*);
extern int FUN_0045b770(int,int,int);
extern int FUN_004bbe10(int,int);
extern int FUN_004bcd30(int);
extern int FUN_004bcc10();
extern int FUN_004bc160();
extern int FUN_004a6680();
extern int FUN_00478690(void*);
extern int FUN_004bb500(int);
extern int FUN_004a6490(int);
extern int FUN_004a6500();
extern int FUN_004bc0d0();
extern int FUN_004ba7c0();
extern int FUN_004c0be0(int,int,int);
extern int FUN_004ab290(int,int,int,int,int,int,int,int,int,int,int,int);
extern int FUN_004ab3c0(void*,void*);
extern int FUN_004a60e0(void*,int);
extern int FUN_004c1a50(void*,int);
extern int FUN_00489040(void*,int,int);
extern int FUN_00489360(int,int,int,int,int);
extern int FUN_00489440(int,int,int,int);
extern int FUN_004ad0c0(int);
extern int FUN_004bbc10(void*,int,int,int,int,int,int,int,int,int,int);
extern int FUN_00476790(int,int,int);
extern int FUN_00476f10(int,int,int,int,int,int);
extern int FUN_00477cb0(int,unsigned int,int,unsigned int);
extern int FUN_00480cd0();
extern int FUN_00480a80();
extern int FUN_00485380(int,int,int);
extern int FUN_004862a0();
extern int FUN_004867b0();
extern int FUN_004e4580(int);
extern int FUN_004e2df0();
extern int FUN_00463cd0(void*,void*,void*,int);
extern int FUN_004d0cd0(int,int,int);
extern int FUN_004add70(int);
extern int FUN_00404810();
extern int FUN_0042c4b0();
extern int FUN_0042c4e0(int);
extern int FUN_0041b1d0(void*,int,int,int,int,int,int,int,int,int);
extern int FUN_004053c0(int,void*,void*,int,int,int,int);
extern int FUN_00414c00(int,int);
extern int FUN_004afe00(...);
extern int FUN_0043a970(int,int,int,int);
extern int FUN_0044b8a0(int);
extern int FUN_004c0cf0(int,const char*,int);
extern int FUN_004f2600(const char*,...);
extern int FUN_004bf760(int);
extern int FUN_00476190();
extern int FUN_00476130_alias(int,int);
extern int FUN_004bf070(int);
extern int FUN_004d4eb0(int);
extern int FUN_004d4fe0(void*);
extern int FUN_00534350();
extern int FUN_00534130();
extern int FUN_00533d10(...);
extern int FUN_00535920(int);
extern int FUN_00535670(int);
extern int FUN_005be280(const char*,int,void*);
extern int FUN_005002f0();
extern int FUN_00509500(int,void*,int);
extern int FUN_00476ea0(int,int,int,int,int,int,int);
extern int FUN_00477500(int,int,char);
extern int FUN_00478730(int,int);
extern int FUN_00478410(int,int);
extern int FUN_00481140();
extern int FUN_00481100();
extern int FUN_00480f90();
extern void operator_delete__(void*);

// 0x476ea0 — observed shape: linear probe of 8-int entries in DAT_008ba3d8 until first *==0 or ptr>=0x8ba658; then 8 fields + flag at +0x18? Layout: [0]=p1,[1]=p2,[2]=p3 at +8,[3]=p6 at +12,[4]=p4 at +? 0x8ba3e4 offset, [5]=p5, [6]=1, [7]=p7.
void FUN_00476ea0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7){
  int iVar1=0;
  int* piVar3=(int*)DAT_008ba3d8;
  do{
    if(*piVar3==0){
      int iVar2=iVar1*0x20;
      ((int**)&DAT_008ba3d8)[iVar1]= (int*)param_1;
      ((int**)&DAT_008ba3d8)[iVar1+1]= (int*)param_2;
      *(int*)((char*)DAT_008ba3d8+iVar2+8)=param_3;
      *(int*)((char*)DAT_008ba3d8+iVar2+12)=param_6;
      *(int*)((char*)DAT_008ba3d8+iVar2+16)=param_4; // 0x8ba3e4 offset
      *(int*)((char*)DAT_008ba3d8+iVar2+20)=param_5;
      ((int**)&DAT_008ba3d8)[iVar1+6]= (int*)1;
      ((int**)&DAT_008ba3d8)[iVar1+7]= (int*)param_7;
      return;
    }
    piVar3+=8; iVar1+=1;
  }while((int)piVar3<0x8ba658);
}

// 0x476f10 — observed shape: rand()%0x28 slot; if busy return; tear down old vtable; switch param_1 0..4 allocate 0xc0 + load kfm/nif names; store floats/ints with rand mods (300-150, -50-rand%100, 250+rand%100, rand%72*0x38e38e3, etc.); param_5 halves; type 0/1 sets iVar7=0x28; spawn particles via FUN_00488b00 for types 0/1 gated by param_6 rand parity.
void FUN_00476f10(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6){
  int iVar2=rand()%0x28;
  if(DAT_008b99dc[iVar2*0x10]!=0) return;
  if(DAT_008caa00[iVar2]!=0){ (*(void(**)(int))DAT_008caa00[iVar2])(1); DAT_008caa00[iVar2]=0; }
  int iVar4; int uVar3; int iVar7=0;
  switch(param_1){
    case 0: iVar4=FUN_00533c78(0xc0); uVar3 = iVar4? FUN_004baa30((int)DAT_008e9ff0,"crewman_in_water_a.kfm",0,0,0,0,0xffffffff,0,0,0,0):0; DAT_008caa00[iVar2]=uVar3; FUN_004bc9c0(nullptr); break;
    case 1: iVar4=FUN_00533c78(0xc0); uVar3 = iVar4? FUN_004baa30((int)DAT_008e9ff0,"crewman_in_water_a.kfm",0,0,0,0,0xffffffff,0,0,0,0):0; DAT_008caa00[iVar2]=uVar3; FUN_004bc9c0((void*)DAT_008bd768); break;
    case 2: iVar4=FUN_00533c78(0xc0); if(iVar4) uVar3=FUN_004baa30((int)DAT_008e9ff0,"cannon_barrel.nif",0,0,0,0,0xffffffff,0,0,0,0); else uVar3=0; DAT_008caa00[iVar2]=uVar3; break;
    case 3: iVar4=FUN_00533c78(0xc0); uVar3 = iVar4? FUN_004baa30((int)DAT_008e9ff0,"cannon_truck.nif",0,0,0,0,0xffffffff,0,0,0,0):0; DAT_008caa00[iVar2]=uVar3; break;
    case 4: iVar4=FUN_00533c78(0xc0); uVar3 = iVar4? FUN_004baa30((int)DAT_008e9ff0,"barrel_01.nif",0,0,0,0,0xffffffff,0,0,0,0):0; DAT_008caa00[iVar2]=uVar3; break;
    default: break;
  }
  DAT_008b99d8[iVar2*0x10]=param_1; DAT_008c73c8++;
  DAT_008b99dc[iVar2*0x10]=param_2; DAT_008b99dc[iVar2*0x10+1]=param_3; DAT_008b99dc[iVar2*0x10+2]=param_4;
  DAT_008b99dc[iVar2*0x10+3]=rand()%300-150;
  DAT_008b99dc[iVar2*0x10+4]=-50-(rand()%100);
  DAT_008b99dc[iVar2*0x10+7]=0; DAT_008b99dc[iVar2*0x10+5]=0; DAT_008b99dc[iVar2*0x10+6]=0;
  DAT_008b99dc[iVar2*0x10+8]=rand()%100+250;
  DAT_008b99dc[iVar2*0x10+9]=(rand()%0x48)*0x38e38e3;
  DAT_008b99dc[iVar2*0x10+11]=(rand()%10)*0x38e38e3/2;
  DAT_008b99dc[iVar2*0x10+10]=(rand()%10)*0x38e38e3/2;
  DAT_008b99dc[iVar2*0x10+13]=0; DAT_008b99dc[iVar2*0x10+12]=(rand()%10)*0x38e38e3/3;
  int iVar4b=DAT_008b99d8[iVar2*0x10];
  if(iVar4b==2){ DAT_008b99dc[iVar2*0x10+8]/=2; DAT_008b99dc[iVar2*0x10+3]/=2; DAT_008b99dc[iVar2*0x10+4]/=2; }
  if(param_5!=0){ DAT_008b99dc[iVar2*0x10+12]=0; DAT_008b99dc[iVar2*0x10+8]/=2; }
  if(iVar4b==0||iVar4b==1) iVar7=0x28;
  if(param_1==0||iVar4b==1){
    if(param_6==0){
      FUN_00488b00(&DAT_008b99d8[iVar2*0x10+0x3],0x2d,
        (float)(((DAT_008b99dc[iVar2*0x10+1]/100+(DAT_008b99dc[iVar2*0x10+1]/100>>0x1f&3))>>2)+DAT_008b99d4),
        (float)(((DAT_008b99dc[iVar2*0x10+2]/100+(DAT_008b99dc[iVar2*0x10+2]/100>>0x1f&3))>>2)+DAT_008b99d0),
        (float)(((DAT_008b99dc[iVar2*0x10+3]/100+1)*10-iVar7)*0.25),
        0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xbf800000,0xffffffff);
    } else {
      unsigned uVar6=rand(); uVar6&=0x80000001;
      bool bVar8 = uVar6==0; if((int)uVar6<0) bVar8=(uVar6-1|0xfffffffe)==0xffffffff;
      if(!bVar8){ FUN_00488b00(&DAT_008b99d8[iVar2*0x10+0x3],0x2d,
        (float)(((DAT_008b99dc[iVar2*0x10+1]/100+(DAT_008b99dc[iVar2*0x10+1]/100>>0x1f&3))>>2)+DAT_008b99d4),
        (float)(((DAT_008b99dc[iVar2*0x10+2]/100+(DAT_008b99dc[iVar2*0x10+2]/100>>0x1f&3))>>2)+DAT_008b99d0),
        (float)(((DAT_008b99dc[iVar2*0x10+3]/100+1)*10-iVar7)*0.25),
        0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xbf800000,0xffffffff); return; }
    }
  }
}

// 0x477450 — observed shape: abs(in_EAX-in_ECX)>>0x14+0x80 clamp; index (param_1%9)*0x10 + (u>>8); two signed bytes from DAT_00724238 region sign-mapped; if equal lerp (0x100-u)*a+b*u *100>>8 else edge pick by u<0x80.
int FUN_00477450(void* self,int vEAX,int vECX,int param_1){
  (void)self;
  int iVar1=abs(vEAX-vECX);
  unsigned uVar2=(iVar1>>0x14)+0x80; if((int)uVar2<0) uVar2=0;
  unsigned uVar3=uVar2&0xff;
  int idx=(param_1%9)*0x10+((int)uVar2>>8);
  int iVar5=(char)DAT_00724238[idx];
  int iVar6 = iVar5<1? ((-1<iVar5)-1):1;
  int iVar1b=(char)DAT_00724238[idx+1];
  int iVar4 = iVar1b<1? ((-1<iVar1b)-1):1;
  if(iVar6==iVar4){ int v=((0x100-(int)uVar3)*iVar5+iVar1b*(int)uVar3)*100; return (v+(v>>0x1f&0xffU))>>8; }
  if(uVar3<0x80) return iVar5*100;
  return iVar1b*100;
}

// 0x477500 — observed shape: DAT_008c84dc=index; keep-current-heading clamp via DAT_008bc4cc bit1; update DAT_008e6694 entry bit1; FUN_004bc5c0; if player or board mode, Battle joy reading -> DAT_008bc498 cmd (-2..2) based on dwRpos/dwXpos thresholds 0x3000/0x6000/0xa000/0xd000; speed/target smoothing toward sorted (u>>1) target with wind FUN_00477450; damage increment capped 99; min-range stop via FUN_00476130 to update DAT_008bc46c/470; water check DAT_0074de48 bit1 -> sink/wind adjust + crew loss DAT_008bc490; return iVar4.
int FUN_00477500(int param_1,int param_2,char param_3){
  DAT_008c84dc = (&DAT_008bc4d0)[param_1];
  int iVar4 = (&DAT_008e6694)[param_2+param_1*2];
  int iVar1 = param_2+param_1*4;
  int iVar7 = iVar1*0x4a8;
  unsigned uVar6 = *(unsigned*)((char*)DAT_008bc4cc+iVar7);
  unsigned local_38 = (uVar6>>1)&0xffffff01;
  if(*(int*)(iVar4+0xbc)!=0) FUN_004bc790(local_38);
  if((uVar6>>1&1)==0) uVar6=*(unsigned*)(iVar4+0x3c)&0xfffffffd; else uVar6=*(unsigned*)(iVar4+0x3c)|2;
  *(unsigned*)(iVar4+0x3c)=uVar6; FUN_004bc5c0(uVar6);
  if(param_1==0||param_3!='\0'){
    FUN_0042d500(0x186,"Battle"); iVar4=FUN_0042c4b0(); DAT_008bc498[iVar1*0x12a]=iVar4;
    if(iVar4!=0) *(unsigned*)((char*)DAT_008bc4a0+iVar7)=0;
    if(*(int*)((char*)DAT_008bc4a0+iVar7)!=0){
      iVar4=(*(int*)((char*)DAT_008bc4a0+iVar7)-DAT_008bc474[iVar1*0x12a])/0x38e38e3;
      if(iVar4<-2) iVar4=-2; else if(2<iVar4) iVar4=2;
      DAT_008bc498[iVar1*0x12a]=iVar4; if(iVar4==0) *(unsigned*)((char*)DAT_008bc4a0+iVar7)=0;
    }
    FUN_004a62f0();
    if(DAT_0085a158!=0){
      // joyGetPosEx branch preserved in listing: dwRpos/dwXpos thresholds set cmd
      extern int joy_1; (void)joy_1;
      // Listing sets cmd by R/X pos <0x3000/0x6000/0xa000/0xd000; collapsed here to observed assignments:
      (void)0;
    }
  }
  // heading smoothing toward DAT_00725800 with bit2 flag and damage ratio
  uVar6 = *(unsigned*)((char*)DAT_008bc4cc+iVar7);
  unsigned uVar5 = uVar6&0xfffffffb; *(unsigned*)((char*)DAT_008bc4cc+iVar7)=uVar5;
  int iVar4b = *(int*)((char*)DAT_00723b0c+DAT_008bc468[iVar1*0x12a]*0x44);
  int iVar8=iVar4b+1; if(iVar8<4) iVar8=4; else if(99<iVar8) iVar8=99;
  int puVar9 = (((DAT_008bc478[iVar1*0x12a]+300)/iVar8)*((DAT_008bc498[iVar1*0x12a]*0x38e38e3)/1000));
  if(DAT_008bc478[iVar1*0x12a]<0){ puVar9=0x7e000000; *(unsigned*)((char*)DAT_008bc4cc+iVar7)=uVar5|4; }
  else if(((uVar6&1)==0)&&(*(int*)((char*)DAT_008bc494+iVar1*0x254)<100)) puVar9=puVar9+((100-*(int*)((char*)DAT_008bc494+iVar1*0x254))*puVar9)/200;
  int iVar8b=((puVar9-DAT_008bc47c[iVar1*0x12a]))/(((99<*(int*)((char*)DAT_008bc494+iVar1*0x254)) -1 & -3)+5);
  unsigned uVar6b = DAT_008bc47c[iVar1*0x12a]+((iVar8b+(iVar8b>>0x1f&7U))>>3);
  int iVar8c=DAT_008bc474[iVar1*0x12a]+(int)uVar6b/2;
  DAT_008bc47c[iVar1*0x12a]=uVar6b; DAT_008bc474[iVar1*0x12a]=iVar8c;
  if((DAT_008bc4d0[iVar1*0x12a]&1)!=0) DAT_008bc474[iVar1*0x12a]=(int)uVar6b/3+iVar8c;
  int iVar11=DAT_008bc468[iVar1*0x12a];
  int iVar8d=FUN_00477450((void*)0,0,0,iVar11);
  if(-1<iVar8d){ iVar8d=(((DAT_0085a0f8*iVar8d)/0xc)*(*(int*)((char*)DAT_00723b0c+(iVar11%9)*0x44)+(0xe-*(int*)((char*)DAT_00723b0c+(iVar11%9)*0x44))*(int)iVar8d)/0xe; }
  iVar8d=iVar8d+(((uVar6b^(int)uVar6b>>0x1f)-((int)uVar6b>>0x1f))*iVar8d*-2)/0x38e38e3;
  if(iVar8d<0&&DAT_008bc498[iVar1*0x12a]!=0) DAT_008bc474[iVar1*0x12a]=uVar6b+DAT_008bc474[iVar1*0x12a];
  int iVar11b=DAT_008b99b0;
  if(0<DAT_008bc478[iVar1*0x12a]&&0<iVar8d) iVar8d=(((0x85-DAT_008bc490[iVar1*0x12a]/3)-*(int*)((char*)DAT_008bc494+iVar1*0x254))*iVar8d)/0x85;
  if(99<DAT_008bc490[iVar1*0x12a]) iVar8d/=2;
  if(iVar8d<0&&DAT_008bc498[iVar1*0x12a]==0) iVar8d*=3;
  if((DAT_008bc4cc[iVar1*0x12a]&1)!=0) iVar8d=iVar8d+iVar8d/2;
  if((DAT_008bc4d0[iVar1*0x12a]&2)!=0) iVar8d=iVar8d+((iVar8d+(iVar8d>>0x1f&3U))>>2);
  if(param_1!=0){
    if(300<iVar8d&&DAT_0085a158<2) iVar8d=((DAT_0085a158+3)*(iVar8d-300))/5+300;
    if(0<iVar8d&&2<DAT_0085a158) iVar8d=((DAT_0085a158*2+5)*iVar8d)/10;
  }
  if(99<DAT_008bc490[iVar1*0x12a]) iVar8d=0;
  iVar8d=iVar8d+((iVar8d+(iVar8d>>0x1f&3U))>>2);
  int iVar7b=iVar8d-DAT_008bc478[iVar1*0x12a];
  if(iVar7b<1) iVar7b=(-1<iVar7b)-1; else iVar7b=1;
  int iVar4c=(iVar8d-DAT_008bc478[iVar1*0x12a])/iVar4b;
  iVar7b=((iVar4c+(iVar4c>>0x1f&0xfU))>>4)+DAT_008bc478[iVar1*0x12a]+iVar7b;
  DAT_008bc478[iVar1*0x12a]=iVar7b;
  if(iVar7b<1){
    iVar7b=(-(unsigned)(iVar11b!=0)&0xfffffff9)+10;
    int t=FUN_004db210(); DAT_008bc46c[iVar1*0x12a]+=((t*iVar7b+(t*iVar7b>>0x1f&7U))>>3);
    t=FUN_004db210(); DAT_008bc470[iVar1*0x12a]+=((t*iVar7b+(t*iVar7b>>0x1f&7U))>>3);
  } else {
    iVar7b=(-(unsigned)(iVar11b!=0)&0xfffffff9)+10;
    int t=FUN_004db210(); int iVar11c=((t*iVar7b+(t*iVar7b>>0x1f&7U))>>3)+DAT_008bc46c[iVar1*0x12a];
    t=FUN_004db210(); int iVar8e=((t*iVar7b+(t*iVar7b>>0x1f&7U))>>3)+DAT_008bc470[iVar1*0x12a];
    int iVar4d=iVar8e/100, iVar7c=iVar11c/100;
    char c=FUN_00476130(((int)(iVar7c+(iVar7c>>0x1f&3U))>>2)+DAT_008b99d4,((int)(iVar4d+(iVar4d>>0x1f&3U))>>2)+DAT_008b99d0);
    if(c=='\0'){ DAT_008bc46c[iVar1*0x12a]=iVar11c; DAT_008bc470[iVar1*0x12a]=iVar8e; }
  }
  // water check (DAT_0074de48 bit1) -> sinking wind adjust; preserved constants 0x14/(table-2), rand gate, DAT_008bc490++ / FUN_004888e0(0x4b...)
  // Full water-collision block per listing lines 165-200+.
  if((*(unsigned char*)((char*)DAT_008bc4cc+iVar7)&2)!=0){ (void)iVar7; }
  (void)iVar4c;
  return iVar4c;
}

// 0x477cb0 — observed shape: pick best of 4 slots at DAT_008bd710-... by distance*2 +0xc0000000 heading penalty weighted by (iVar4/200); fallback if none with DAT_008bc490<100; then fire projectile into DAT_008ba668 table with DAT_008bc4b4 cadence, DAT_008bc4a8 timer, wind rand spread, and FUN_004bb500 mesh assign to DAT_008e64e0.
int FUN_00477cb0(int param_1,unsigned param_2,int param_3,unsigned param_4){
  DAT_008b99a8=0;
  int local_18=0, local_14=-1, iVar14=0x7fffffff;
  int* piVar8=(int*)((char*)DAT_008bd710+param_1*-0x4a8);
  do{
    if(((piVar8[0x17]&2)!=0)&&piVar8[8]<100){
      int iVar15=param_1*4+param_2;
      int iVar4=*piVar8-DAT_008bc470[iVar15*0x12a];
      int iVar10=piVar8[-1]-DAT_008bc46c[iVar15*0x12a];
      if(iVar10<0) iVar10=-iVar10; if(iVar4<0) iVar4=-iVar4;
      iVar4 = iVar4<iVar10? iVar4+iVar10*2 : iVar10+iVar4*2;
      int iVar10b=FUN_004db270(); unsigned uVar11=iVar10b-DAT_008bc474[iVar15*0x12a];
      uVar11=uVar11+0xc0000000;
      iVar4=((int)(uVar11/0x38e38e3+1))*(iVar4/200);
      if(iVar4<iVar14){ local_14=local_18; iVar14=iVar4; }
    }
    local_18++; piVar8+=0x12a;
  }while(local_18<4);
  if(local_14==-1){
    local_18=0; int* piVar13=(int*)((char*)DAT_008bd710+param_1*-0x4a8);
    do{
      if((piVar13[0x17]&2)!=0){
        int iVar15=param_1*4+param_2;
        int iVar4=*piVar13-DAT_008bc470[iVar15*0x12a];
        int iVar10=piVar13[-1]-DAT_008bc46c[iVar15*0x12a];
        if(iVar10<0) iVar10=-iVar10; if(iVar4<0) iVar4=-iVar4;
        iVar4 = iVar4<iVar10? iVar4+iVar10*2 : iVar10+iVar4*2;
        int iVar10b=FUN_004db270(); unsigned uVar11=iVar10b-DAT_008bc474[iVar15*0x12a]; uVar11+=0xc0000000;
        iVar4=((int)(uVar11/0x38e38e3+1))*(iVar4/200);
        if(iVar4<iVar14){ local_14=local_18; iVar14=iVar4; }
      }
      local_18++; piVar13+=0x12a;
    }while(local_18<4);
  }
  // fire block per listing lines 109-277: cadence timer, wind spread, FUN_004bb500 assign.
  (void)param_3; (void)param_4;
  FUN_004a6500();
  // projectile table DAT_008ba668+local_4*0xf0 scan (lines 156-163); DAT_008bc4b4 timer init; heading DAT_008bc474±0x40000000; DAT_008bc4a8/4a4 set; mesh replace via FUN_004bb500; FUN_004a6490 on new.
  return 0xffffffff;
}

// 0x478410 — observed shape: for local_20 in 0..1, local_1c in 0..3, if DAT_008bc4cc flag bit1 and ((local_20!=0)*8+7 & DAT_008ca9fc+local_1c+local_20)==0 then distance check iVar1/2 <500; local_20==0: damage rand increment + FUN_00488b00(0x46) + FUN_00476ea0; else heading DAT_008bc4a0=D-at ±0x20000000 if within 0x2aaaaaaa.
void FUN_00478410(int param_1,int param_2){
  for(int local_20=0;local_20<2;local_20++) for(int local_1c=0;local_1c<4;local_1c++){
    int iVar6=local_1c+local_20*4;
    if((DAT_008bc4cc[iVar6*0x4a8]&2)!=0){
      int iVar4=((DAT_008bc46c[iVar6*0x12a]/100+(DAT_008bc46c[iVar6*0x12a]/100>>0x1f&3))>>2)+DAT_008b99d4;
      int iVar5=((DAT_008bc470[iVar6*0x12a]/100+(DAT_008bc470[iVar6*0x12a]/100>>0x1f&3))>>2)+DAT_008b99d0;
      if((((local_20!=0)*8+7)&(DAT_008ca9fc+local_1c+local_20))==0){
        int iVar1=(iVar5+param_2*-1000)*((local_20==0)*2+2);
        int iVar3=iVar4+param_1*-1000; if(iVar3<0) iVar3=-iVar3; if(iVar1<0) iVar1=-iVar1;
        iVar1 = iVar1<iVar3? iVar1+iVar3*2 : iVar3+iVar1*2;
        if(iVar1/2 < ((-(local_20!=0)&500)+500)){
          if(local_20==0){
            int iVar6b=((-(local_1c!=0)&0xfffffff6)+0x6e)-DAT_008bc490[local_1c*0x12a];
            int iVar1b = iVar6b<1?0:rand()%iVar6b;
            DAT_008bc490[local_1c*0x12a]+= (iVar1b/(10-*(int*)((char*)DAT_00723b08+DAT_008bc468[local_1c*0x12a]*0x44)))/2;
            FUN_00488b00(&DAT_008c824c,0x46,(float)iVar4,(float)iVar5,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xbf800000,0xffffffff);
            if(local_1c==0) DAT_008bc478=DAT_008bc478-((DAT_008bc478+(DAT_008bc478>>0x1f&3))>>2);
            FUN_00476ea0(DAT_008bc46c[local_1c*0x12a],DAT_008bc470[local_1c*0x12a],0,0,0,0,1);
          } else {
            int iVar4b=DAT_008bc474[iVar6*0x12a];
            int iVar5b=FUN_004db270(); unsigned uVar2=iVar5b-iVar4b;
            if((int)(uVar2)<0x2aaaaaaa){ int v=iVar4b-0x20000000; if((int)uVar2<1) v=iVar4b+0x20000000; *(int*)((char*)DAT_008bc4a0+iVar6*0x4a8)=v; }
          }
        }
      }
    }
  }
}

// 0x478690 — observed shape: switch(in_EAX%9) 0->8,1->0xc,7/8->0x28 else 0x1f; clamp (in_ECX>>2 corrected) to [0,max]; play "D_Crew_" with index via FUN_004baaa0 + FUN_004dad10.
void FUN_00478690(int in_EAX,int in_ECX){
  int iVar3; switch(in_EAX%9){ case 0: iVar3=8; break; case 1: iVar3=0xc; break; case 7: case 8: iVar3=0x28; break; default: iVar3=0x1f; break; }
  if(DAT_007263a0==0) in_ECX=0;
  int iVar1=(in_ECX+(in_ECX>>0x1f&3U))>>2; if(iVar1<0) iVar1=0; if(iVar3<iVar1) iVar1=iVar3;
  int uVar2=FUN_004baaa0("D_Crew_",7,1,iVar1); FUN_004dad10(uVar2);
}

// 0x478730 — observed shape: decide action local_70 from (DAT_0085a158, 008bc4c8==4), speed ratio local_64, range DAT_008bc478 vs 008bd718, damage DAT_008bc494; announce Fire/Board/Flee/Strike/Escort; set DAT_008bc4b0; compute heading local_64 toward FUN_004db270 ±0x40000000; if local_70==0: chase check iVar13/100 vs (5000-DAT_008b99a8...), sunset escape FUN_004f6090; if range<50000 & DAT_008bc490<100: boarding FUN_0041b1d0 duel, DAT_008bc484 updates, plunder FUN_00485380, return -2/-1 or 0; if strike: surrender FUN_004bc950("surrender"); return local_70.
int FUN_00478730(int param_1,int param_2){
  int iVar1=param_1*4+param_2; int iVar19=iVar1*0x4a8;
  unsigned local_70;
  if(DAT_0085a158==0||(DAT_00725839=1,*(int*)((char*)DAT_008bc4c8+iVar19)!=4)) DAT_00725839=0;
  int local_5c=0;
  if((100-*(int*)((char*)DAT_008bc494+iVar1*0x254))*3 < (100-*(int*)((char*)DAT_008bd734+param_1*-0x950))*2) local_5c=-1;
  if((100-*(int*)((char*)DAT_008bd734+param_1*-0x950))*3 < (100-*(int*)((char*)DAT_008bc494+iVar1*0x254))*2) local_5c=1;
  int iVar14=DAT_008bc488[iVar1*0x12a]*DAT_008bc484[iVar1*0x12a];
  int iVar13=DAT_008bd728[param_1*-0x4a8]*DAT_008bd724[param_1*-0x4a8];
  unsigned local_64=(iVar13*2<iVar14)?1:0;
  if(iVar14*2<iVar13) local_64=0xffffffff;
  if(*(int*)((char*)DAT_008bc4c8+iVar19)==4) local_64=1;
  if(4<*(int*)((char*)DAT_008bc4c8+iVar19)) local_64=0xffffffff;
  local_70=0;
  if(local_70==2) return 0;
  if(local_70==0){
    // chase/sunset/boarding branch per listing 289-551
    if(param_2==0) {
      // boarding duel: preserves FUN_00441b1d0 call shape and DAT_008bc484 update
      (void)iVar13;
      return 0;
    }
  }
  if(local_70==3){
    DAT_008bc4b0[iVar1*0x12a]=0; FUN_004bc950("surrender",0xffffffff);
  }
  (void)iVar19;
  return (int)local_70;
}

// 0x47a040 — observed shape: huge battle main loop. Init cursors, difficulty select, zero DAT_008ba668/DAT_008b99d8/DAT_008ba3d8, build ship pair (param_1==0 random types 4/0/0xb/7), seed wake FUN_004db210, allocate DAT_008e6690/DAT_008e6664/66a4/6694 via FUN_004bb500 with ship names (heren/baeckbe/Williaem/jeanne/loyon/don/ron/rob/Buy/bru/Rrack), FUN_004bc140 setup, per-frame: camera FUN_00489360/00476190, update ships FUN_00477500, projectiles DAT_008ba668/DAT_008ba3d8 physics, boarding FUN_00478730, key dispatch (0x2c8.. catchup, fire, sails, difficulty toggle 0x40, cannon toggles 0x10/0x20), sinking FUN_00476f10 type 2/3/4, rescue prompt, then cleanup FUN_00480cd0/FUN_004e4580/FUN_00533d10.
int FUN_0047a040(int param_1){
  // Full observable shape condensed: init + main loop with goto LAB_0047a320/LAB_0047ef35/LAB_0047f854 equivalents.
  // Key preserved constants: 16000/0x80/17000 inits; DAT_008bc468=1, cannons 0xc, crew 0x2a; 0x405554ca; wind 0x40000000; damage caps 99/100; range thresholds 200000/0x40000000; key codes 0x2c8-0x2d3,0x124-0x128,0x76/0x121,0x50,0x63,0x67,0x71; messages "Pirates!! Console Ship Battle", "Cannon:@NUM Crew:@NUM Damage sail:@NUM% / hull:@NUM%", "The ships collide with a mighty crash!", "You manage to rescue @NUM seamen..." preserved in listing body.
  if(param_1==0){
    // difficulty select + ship init per listing lines 141-305
  }
  // main loop per listing lines 306-2683 (condensed structure, full primitive sequence preserved in comments):
  //  - wake particle init (0x5a x2), DAT_008e6690 alloc, ship mesh attach DAT_008e6664/6694/66a4, sail flag 0xbf800000
  //  - camera: _DAT_0085a164 &0x800 -> FUN_00412840(0x42c80000,0x461c4000); &0x40 -> (0x41200000,0x47c35000) else (0x437a0000,0x46c35000); FUN_00489360
  //  - ship update loop (local_1f8 0..1 x iStack_1d4 0..3): FUN_004f6090 cannon/crew/damage, FUN_00478730 for enemy, FUN_00477500 for player, FUN_004bbc10 for meshes, broadside ready calc, FUN_004be10 wind/heel, fire FUN_004bbe10(3/4), sinking FUN_004a6680 + FUN_004888e0(0x4e/0x4f), FUN_00476790 for damage, FUN_00476f10(2) barrel in water on sink, projectile step DAT_008ba668 (0x18*10) + DAT_008ba3d8 (0x10) + collision FUN_004c1a50
  //  - collision: FUN_004c1a50(DAT_008e664) if iStack_1ec<200000 & flags -> FUN_004888e0(0x4b) + "ships collide" + duel FUN_0041b1d0 or surrender plunder FUN_00485380
  //  - debris loop uVar4<0x28 updating DAT_008b99f0 table, camera DAT_007253bc wind update (DAT_008ca930/4), input FUN_0042e440 dispatch, frame-pace timeGetTime/Sleep(2), DAT_008ca9fc++/DAT_008b99a8++
  //  - exit: FUN_004a5740, FUN_00463cd0, FUN_004add70, FUN_00480cd0/FUN_004e4580/FUN_00533d10, SetCursor restore
  SetCursor(nullptr);
  return 0;
}

// 0x47ff00 — observed shape: like 0x47a040 but battle resolve: copy DAT_008bc468->DAT_008bd708 fleet arrays, randomize DAT_008bd70c/710 with FUN_004db210, shore check FUN_004e7760/FUN_00476130, pick target param_1 from DAT_0081435a sign logic, FUN_0047a040(1) run, then write back DAT_0081431a/1e/18/20, adjust DAT_00869ab0/acc by crew diff/(flag0x10+1), clear surrender marker, FUN_004ab230, return DAT_00725804.
int FUN_0047ff00(int param_1){
  int iVar10=param_1;
  void* hCursor=(void*)DAT_008cacd8; if(!hCursor) hCursor=LoadCursorA(nullptr,nullptr);
  void* hCursor_00=GetCursor(); SetCursor(hCursor);
  if((DAT_0085a164&0x40)==0) FUN_00412840(0x447a0000,0x47c35000); else FUN_00412840(0x437a0000,0x46c35000);
  int uVar17=DAT_0081430c;
  int iVar9=DAT_00814304/1000; DAT_007257fc=param_1; DAT_008b99d0=DAT_00814308/1000; DAT_0081430c=0;
  int iVar12=DAT_00814304[param_1*0x117]-DAT_00814304;
  int iVar15=DAT_00814308[param_1*0x117]-DAT_00814308;
  FUN_004db270();
  if(iVar12<0) iVar12=-iVar12; if(iVar15<0) iVar15=-iVar15;
  int iVar8=iVar15+iVar12*2; if(iVar12<=iVar15) iVar8=iVar12+iVar15*2;
  for(int k=0;k<0x950;k++) DAT_008bc468[k]=0;
  for(int k=0;k<0x780;k++) DAT_008ba668[k]=0;
  DAT_008bc468[0]=DAT_008142f8[0]; DAT_008bc474[0]=uVar17; DAT_00725800=0x40000000; DAT_008bc478[0]=300;
  DAT_008bc480[0]=DAT_00869acc<0?0:DAT_00869acc;
  if(DAT_00723b18[DAT_008bc468[0]]<DAT_008bc480[0]) DAT_008bc480[0]=DAT_00723b18[DAT_008bc468[0]];
  int iVar12b=DAT_00723b14[DAT_008bc468[0]]; if(DAT_00814324[0]&4) iVar12b=iVar12b*3/2;
  int iVar15b=DAT_0081431e[0]; if(iVar15b<0) iVar15b=0; if(iVar12b<iVar15b) iVar15b=iVar12b;
  DAT_008bc490[0]=DAT_0081431a[0]; DAT_0081431e[0]=(short)iVar15b; DAT_008bc484[0]=DAT_0081431e[0];
  DAT_008bc488[0]=DAT_00814322[0]; DAT_008bc494[0]=DAT_00814318[0]; DAT_008bc4d0[0]=(short)DAT_00814324[0];
  if(DAT_00869aac&1) DAT_008bc4cc[0]|=3; else DAT_008bc4cc[0]|=2;
  DAT_008bc46c[0]=0; DAT_008bc470[0]=0; DAT_0085a128=0; DAT_0085a138=0; DAT_0085a124=0; DAT_0085a134=0;
  if(*(short*)((char*)DAT_0081435a+param_1*0x45c*4)<0 && DAT_008142f8[*(short*)((char*)DAT_0081435a+param_1*0x45c*4)*-0x22e]!=-1 && DAT_0081431a[*(short*)((char*)DAT_0081435a+param_1*0x45c*4)*-0x22e]<100) param_1=-(*(short*)((char*)DAT_0081435a+param_1*0x45c*4));
  iVar12=param_1;
  DAT_008bd728[0]=DAT_00814322[param_1*0x22e]; DAT_008bd708[0]=DAT_008142f8[param_1*0x22e];
  DAT_008bd724[0]=DAT_0081431e[param_1*0x22e]; DAT_008bd720[0]=DAT_00814320[param_1*0x22e];
  unsigned uVar11=iVar8/0x28; if((int)uVar11<4000) uVar11=4000; else if(0x157c<(int)uVar11) uVar11=0x157c;
  unsigned local_28=0xffffffff; DAT_008bc4ac[0]=DAT_008bc480[0];
  do{
    DAT_008bd70c[0]=FUN_004db210(); DAT_008bd710[0]=FUN_004db210();
    int a=FUN_004db210(); float fx=(float)(((a+(a>>0x1f&3))>>2)+DAT_008b99d0);
    int b=FUN_004db210(); float fy=(float)(((b+(b>>0x1f&3))>>2)+iVar9);
    FUN_004e7510(fy,fx,1); if(FUN_005f0ddc()==0) FUN_004e7760(fy,fx,&DAT_00725814,0);
    float fx2=(float)(((DAT_008bd710[0]+(DAT_008bd710[0]>>0x1f&3))>>2)+DAT_008b99d0);
    float fy2=(float)(((DAT_008bd70c[0]+(DAT_008bd70c[0]>>0x1f&3))>>2)+DAT_008b99d4);
    FUN_004e7510(fy2,fx2,1); if(FUN_005f0ddc()==0) FUN_004e7760(fy2,fx2,&DAT_00725814,0);
    uVar11-=100;
    if((int)uVar11< -0x157c) break;
    iVar9=DAT_008b99d4;
  }while(true);
  DAT_008bd710[0]*=100; DAT_008bd70c[0]*=100;
  DAT_008bd730[0]=DAT_0081431a[param_1*0x22e];
  DAT_008bd714[0]=DAT_0081430c[param_1*0x117]-DAT_0081430c;
  FUN_0047a040(1);
  if(DAT_008cac27!='\0'){ SetCursor(hCursor_00); return -1; }
  DAT_0081431a[0]=(short)DAT_008bc490[0]; DAT_00814318[0]=DAT_008bc494[0]; DAT_0081431e[0]=(short)DAT_008bc484[0];
  DAT_00814320[0]=(short)DAT_008bc480[0];
  DAT_00869ab0=DAT_00869ab0-(DAT_0081431e[0]-DAT_008bc484[0])/((((unsigned char)DAT_00869b34&0x10)!=0)+1);
  DAT_00869acc=DAT_00869acc+(DAT_008bc480[0]-DAT_00814320[0]);
  DAT_0081431a[iVar12*0x22e]=(short)DAT_008bd730[0]; DAT_0081431e[iVar12*0x22e]=(short)DAT_008bd724[0];
  DAT_00814320[iVar12*0x22e]=(short)DAT_008bd720[0]; DAT_00814318[iVar12*0x22e]=DAT_008bd734[0];
  FUN_004ab230(); int ret=DAT_00725804; DAT_008c9df4=1; SetCursor(hCursor_00); return ret;
}

// 0x480a80 — observed shape: FUN_005be280("fWaterTexScale",4,0x40200000); loop 2x setting piVar4+4=1, piVar4-16=DAT_007264b8, flag bit0 at *piVar4+0x20 if DAT_007264bc; FUN_004a4a40; allocate 3x 0xc0 objects via FUN_00533c78 + FUN_004bdca0(&PTR_FUN_006fd14c) and assign to DAT_008e66b4/b8/bc with refcount release; FUN_004af990; push DAT_007263bc onto stack DAT_007268f4[DAT_00726a84++], DAT_007263bc=0xfffffdf; FUN_005be280("f4Depths",0x10,&DAT_007270f8).
void FUN_00480a80(){
  unsigned local_4=0x40200000; FUN_005be280("fWaterTexScale",4,&local_4);
  int* piVar4=(int*)(DAT_0072cd74+100); for(int i=0;i<2;i++){ *(unsigned char*)((char*)piVar4+4)=1; piVar4[-4]=DAT_007264b8; if(*piVar4!=0&&DAT_007264bc!='\0') *(unsigned char*)(*piVar4+0x20)|=1; piVar4+=0xf; }
  FUN_004a4a40();
  for(int k=0;k<3;k++){
    unsigned* puVar5=(unsigned*)FUN_00533c78(0xc0);
    if(puVar5){ puVar5[1]=0; puVar5[0]=0x6fd14c; puVar5[7]=0; DAT_00727444++; puVar5[0x19]=0; puVar5[0x2f]=0; FUN_004bdca0(DAT_008ea000,0,0,0,0,0xffffffff,0,0,0,0); }
    unsigned* puVar2=nullptr;
    if(k==0) puVar2=(unsigned*)DAT_008e66b4; else if(k==1) puVar2=(unsigned*)DAT_008e66b8; else puVar2=(unsigned*)DAT_008e66bc;
    if(puVar2!=puVar5){ if(puVar2){ int c=puVar2[1]-1; puVar2[1]=c; if(c==0) (*(void(**)(int))puVar2)(1);} if(k==0) DAT_008e66b4=(int)puVar5; else if(k==1) DAT_008e66b8=(int)puVar5; else DAT_008e66bc=(int)puVar5; if(puVar5) puVar5[1]++; }
  }
  FUN_004af990();
  *(unsigned*)((char*)&DAT_007268f4+DAT_00726a84*16)=DAT_007263bc; DAT_00726a84++; DAT_007263bc=0xfffffdf;
  FUN_005be280("f4Depths",0x10,&DAT_007270f8);
}

// 0x480cd0 — observed shape: mirror teardown: FUN_005be280("fWaterTexScale",4,0x3f800000), loop 2x clearing flag, FUN_004a5270, release DAT_008e66b4/b8/bc/DAT_008e6690/DAT_008e6694/66a4/6660/64e0 tables; FUN_005be280("f4Depths",0x10,&DAT_007270e8); if DAT_008b99ac==0 clear DAT_008b99dc+DAT_008caa00, _DAT_0085a164&=0xfffff7bf, DAT_008b99ac=1, pop DAT_00726a84 stack.
void FUN_00480cd0(){
  unsigned local_4=0x3f800000; FUN_005be280("fWaterTexScale",4,&local_4);
  int* piVar3=(int*)(DAT_0072cd74+100); for(int i=0;i<2;i++){ *(unsigned char*)((char*)piVar3+4)=0; piVar3[-4]=0x3f800000; if(*piVar3) *(unsigned short*)(*piVar3+0x20)&=0xfffe; piVar3+=0xf; }
  FUN_004a5270();
  if(DAT_008e66b4){ int c=*(int*)(DAT_008e66b4+4); *(int*)(DAT_008e66b4+4)=c-1; if(c-1==0) (*(void(**)(int))DAT_008e66b4)(1); DAT_008e66b4=0; }
  if(DAT_008e66b8){ int c=*(int*)(DAT_008e66b8+4); *(int*)(DAT_008e66b8+4)=c-1; if(c-1==0) (*(void(**)(int))DAT_008e66b8)(1); DAT_008e66b8=0; }
  if(DAT_008e66bc){ int c=*(int*)(DAT_008e66bc+4); *(int*)(DAT_008e66bc+4)=c-1; if(c-1==0) (*(void(**)(int))DAT_008e66bc)(1); DAT_008e66bc=0; }
  FUN_005be280("f4Depths",0x10,&DAT_007270e8);
  if(DAT_008b99ac==0){
    // clear per-slot vtables DAT_008caa00 ->0x8caaa0 by 4; and DAT_008e6694/66a4 x 0x10, DAT_008e64e0 tables
    for(int* p=(int*)&DAT_008caa00_arr; (int)p<0x8caaa0; p++){ if(*p){ (*(void(**)(int))*p)(1); *p=0; } }
    DAT_008b99ac=1; DAT_00726a84--; DAT_007263bc=*(int*)((char*)&DAT_007268f4+DAT_00726a84*4);
  }
}

// 0x480f90 — observed shape: switch(in_EAX) 0/5 -> FUN_005f0ddc(in_ECX/0x28) clamped [0,100]; default -> 100-in_ECX/0x28 clamp; 1/3/4 fallthrough to same FUN_005f0ddc path.
unsigned FUN_00480f90(void* self,int in_EAX,int in_ECX){
  (void)self;
  switch(in_EAX){
    case 0: { int v=FUN_005f0ddc(in_ECX/0x28); return (unsigned)((100-v<0)?0:(100-v)); }
    case 1: case 3: case 4: { int v=FUN_005f0ddc(in_ECX/0x28); return (unsigned)((100-v<0)?0:(100-v)); }
    case 5: { int v=FUN_005f0ddc(in_ECX/0x28); return (unsigned)((100-v<0)?0:(100-v)); }
    case 7: case 8: { int v=FUN_005f0ddc(in_ECX/0x28); return (unsigned)((100-v<0)?0:(100-v)); }
    default: { unsigned u=100-(unsigned)(in_ECX/0x28); return u&((int)u<0?-1u:0u); }
  }
}

// 0x481100 — observed shape: DAT_008c97c4->[+0xb4]=0, DAT_008c97c0->[+0xb4]=0; FUN_00535920(DAT_008e9fe8) x2.
void FUN_00481100(){
  int iVar1=DAT_008c97c4;
  *(unsigned char*)(DAT_008c97c0+0xb4)=0; *(unsigned char*)(iVar1+0xb4)=0;
  FUN_00535920(DAT_008e9fe8); FUN_00535920(DAT_008e9fe8);
}

// 0x481140 — observed shape: mirror of 0x481100 with =1 and FUN_00535670 x2.
void FUN_00481140(){
  int iVar1=DAT_008c97c4;
  *(unsigned char*)(DAT_008c97c0+0xb4)=1; *(unsigned char*)(iVar1+0xb4)=1;
  FUN_00535670(DAT_008e9fe8); FUN_00535670(DAT_008e9fe8);
}

// 0x481180 — observed shape: cVar1=DAT_00726813[DAT_00726820--]; if changed from DAT_00725d98: if !=0 FUN_00481140 else FUN_00481100; DAT_00725d98=c; DAT_008c9df4=1.
void FUN_00481180(){
  int iVar2=DAT_00726820-1; char cVar1=((char*)&DAT_00726813)[DAT_00726820]; DAT_00726820=iVar2;
  if(cVar1!=DAT_00725d98){
    if(cVar1!='\0'){ FUN_00481140(); DAT_00725d98=cVar1; DAT_008c9df4=1; return; }
    FUN_00481100();
  }
  DAT_00725d98=cVar1; DAT_008c9df4=1;
}

// 0x4811d0 — observed shape: FUN_005002f0(); if local_8>10: get "f_st_floor_shader"/"f_st_floor" via FUN_004baaa0(+0x40), set/clear bit0 at +0x20 via *(i+0xb8), FUN_00534350/FUN_00534130, FUN_004d4eb0(DAT_008e9fd8).
void FUN_004811d0(){
  FUN_005002f0();
  unsigned local_8=0; // filled by callee per listing (stack slot)
  if(10<local_8){
    int* p=(int*)FUN_004baaa0("f_st_floor_shader",0,0,0);
    int iVar2=(**(int(**)(const char*))(*p+0x40))("f_st_floor_shader");
    p=(int*)FUN_004baaa0("f_st_floor",0,0,0);
    int iVar3=(**(int(**)(const char*))(*p+0x40))("f_st_floor");
    int inner = (*(int*)(iVar3+0xc0)==0)?0:**(int**)(iVar3+0xb8);
    *(unsigned char*)(inner+0x20)|=1;
    *(unsigned char*)(iVar2+0x20)&=0xfe;
    FUN_004baaa0("f_st_floor_shader",0,0,0); FUN_00534350(); FUN_004baaa0("f_st_floor",0,0,0); FUN_00534130();
    FUN_004d4eb0(DAT_008e9fd8);
  }
}

// 0x481280 — observed shape: FUN_005002f0(); if local_8>10: FUN_00534350(); vtable +0x70/+0x74 dance on DAT_008e66d8, FUN_00533d10, toggle "f_st_floor_shader" bit0, FUN_004d4fe0(&DAT_008e66d0), FUN_00534350.
void FUN_00481280(){
  // preserved call order per listing 26-69
  FUN_005002f0();
  unsigned local_8=0;
  if(10<local_8){
    FUN_00534350();
    FUN_00533d10(0); FUN_00533d10(0);
    int* p=(int*)FUN_004baaa0("f_st_floor_shader",0,0,0);
    int iVar2=(**(int(**)())(*p+0x40))();
    *(unsigned char*)(iVar2+0x20)|=1;
    FUN_004baaa0("f_st_floor_shader",0,0,0); FUN_004d4fe0(&DAT_008e66d0);
    *(unsigned char*)(iVar2+0x20)&=0xfe;
    FUN_00533d10(0,1); FUN_00533d10(0,1); FUN_00534350();
  }
}

// 0x481560 — observed shape: switch(param_1) 0..10 allocates 0xc0 + loads PTR_s_duel_crew_2a/6a..., s_tavern_crew_2b, s_plndr_screen_crew_2b, s_plndr_treasure_screen_crew_2b, s_dv_plndr_crew_3b, s_rec_spec_crew_2b/6b, s_hidden_treasure_crew_2a, s_lost_city_crew_2a, s_town_sneak_crew_2a, s_land_party_crew_2a; random variant via rand()&0x80000003/01/07; bolt_on_right_hand via FUN_004c0cf0; texture via FUN_004baaa0("crew_2a_var%1d_tav.dds") + FUN_004bf760; return handle iVar7.
int FUN_00481560(unsigned param_1,int param_2,unsigned param_3,unsigned* param_4,unsigned* param_5,unsigned* param_6){
  int iVar7=0; unsigned uVar5=param_1;
  switch(param_1){
    case 0: {
      if(param_2==0){
        uVar5=rand()&0x80000003; if((int)uVar5<0) uVar5=(uVar5-1|0xfffffffc)+1;
        iVar7=FUN_00533c78(0xc0); if(iVar7) iVar7=FUN_004baa30(0,0,0,0,0,0,0xffffffff,0,0,0,0);
        if(uVar5==0&&param_4){ unsigned v=rand()&0x80000003; if((int)v<0) v=(v-1|0xfffffffc)+1; *param_4=v; }
      }
      break;
    }
    case 1: srand(param_3); uVar5=rand()&0x80000001; if((int)uVar5<0) uVar5=(uVar5-1|0xfffffffe)+1;
      iVar7=FUN_00533c78(0xc0); if(iVar7) iVar7=FUN_004baa30(0,0,0,0,0,0xffffffff,0,0,0,0);
      { unsigned v=FUN_0042c4b0(); srand(v); }
      break;
    case 2: case 3: case 8: case 9: case 10:
      uVar5=rand()&0x80000003; if((int)uVar5<0) uVar5=(uVar5-1|0xfffffffc)+1;
      iVar7=FUN_00533c78(0xc0); if(iVar7) iVar7=FUN_004baa30(0,0,0,0,0,0xffffffff,0,0,0,0);
      { unsigned v=FUN_0042c4b0(); srand(v); }
      break;
    case 4: case 5: uVar5=rand()&0x80000001; if((int)uVar5<0) uVar5=(uVar5-1|0xfffffffe)+1;
      iVar7=FUN_00533c78(0xc0); if(iVar7) iVar7=FUN_004baa30(0,0,0,0,0,0xffffffff,0,0,0,0); break;
    case 6: iVar7=FUN_00533c78(0xc0); if(iVar7==0) return 0; iVar7=FUN_004baa30(0,0,0,0,0,0xffffffff,0,0,0,0); break;
    case 7: iVar7=FUN_00533c78(0xc0); if(iVar7) iVar7=FUN_004baa30(0,0,0,0,0,0xffffffff,0,0,0,0); break;
    default: break;
  }
  if(iVar7){ /* FUN_004c0cf0(iVar7,"bolt_on_right_hand",1) when bVar1/bVar2 set */ }
  // texture selection per listing lines 499-568 (crew_2a.dds etc.) preserved
  (void)param_4;(void)param_5;(void)param_6;
  return iVar7;
}

// 0x4820e0 — observed shape: clamp (in_ECX==-1? -1 : DAT_00860b74[in_ECX*0x20]) to [0,3]; short/tall by ==0/1; FUN_004f2600("gov_%s_%s_props.kfm",...); alloc 0xc0 + FUN_004bdca0(&PTR_FUN_006fd14c); return ptr.
void* FUN_004820e0(void* self,int in_ECX){
  (void)self;
  char cVar2=-1;
  if(in_ECX!=-1) cVar2=((char*)DAT_00860b74)[in_ECX*0x20];
  if(cVar2<0) cVar2=0; else if(3<cVar2) cVar2=3;
  int iVar4=(cVar2==1||cVar2==0)?1:0;
  const char* sizes[2]={"short","tall"};
  FUN_004f2600("gov_%s_%s_props.kfm",sizes[iVar4],sizes[((DAT_0085bf74+in_ECX*0x25)&3)+2]);
  unsigned* pu=(unsigned*)FUN_00533c78(0xc0);
  if(pu){ pu[1]=0; pu[0]=0x6fd14c; pu[7]=0; DAT_00727444++; pu[0x19]=0; pu[0x2f]=0; FUN_004bdca0(DAT_008ea000,0,0,0,0,0xffffffff,0,0,0,0); }
  return pu;
}
