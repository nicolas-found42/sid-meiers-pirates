// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054d020 — observed purpose: 4-byte->2-byte unscale loop, single inner for over cols with CONCAT22 accumulation across in_EDX/unaff_EBX registers, final (short) store. Corpus: analysis/pseudocode/functions/0x54d020.c
// Observed: bVar4=*param_6; pbVar1=+1; pbVar2=+2; pbVar3=+3; +4 stride; three CONCAT22 stages using param_5 bytes 0x15/0x11,10/8,0x17/0x13,0xb/9; masks param_5[4],*param_5,2,6.
#include <stdint.h>
// 0x0054d020
void __cdecl FUN_0054d020(int cols,int rows,short* dst,const uint8_t* src,const uint8_t* desc){
 if(rows==0) return; const uint8_t* s=src; short* d=dst;
 for(int r=0;r<rows;++r){ for(int c=0;c<cols;++c){ uint8_t b0=s[0],b1=s[1],b2=s[2],b3=s[3]; s+=4;
  uint32_t a=((b0>>(desc[10]&0x1f))<<(desc[8]&0x1f))&desc[0];
  uint32_t b=((b1>>(desc[0x15]&0x1f))<<(desc[0x11]&0x1f))&desc[2];
  uint32_t cc=((b3>>(desc[0x17]&0x1f))<<(desc[0x13]&0x1f))&desc[6];
  uint32_t dd=((b2>>(desc[0xb]&0x1f))<<(desc[9]&0x1f))&desc[4];
  *d=(short)(a|b|cc|dd); d++; } } }
