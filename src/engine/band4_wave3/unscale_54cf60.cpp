// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054cf60 — observed purpose: 3-byte->4-byte unscale loop overwriting uint32 dst: three masked/shifted channel terms OR'd with desc[0..3]. Corpus: analysis/pseudocode/functions/0x54cf60.c
// Observed: *puVar4=(bVar3>>(param_5[5]))<<(param_5[4])&*param_5 | (*pbVar1>>0x15)<<(0x11)&param_5[1] | (*pbVar2>>0x16)<<(0x12)&param_5[2] | (0xff>>0x17)<<(0x13)&param_5[3].
#include <stdint.h>
// 0x0054cf60
void __cdecl FUN_0054cf60(int cols,int rows,uint32_t* dst,const uint8_t* src,const uint8_t* desc){
 if(rows==0) return; const uint8_t* s=src; uint32_t* d=dst;
 for(int r=0;r<rows;++r){ if(cols==0) continue; uint32_t* dd=d; for(int c=0;c<cols;++c){ uint8_t b0=s[0],b1=s[1],b2=s[2]; s+=3;
  uint32_t a=(b0>>(desc[5]&0x1f))<<(desc[4]&0x1f); uint32_t b=(b1>>(desc[0x15]&0x1f))<<(desc[0x11]&0x1f); uint32_t cc=(b2>>(desc[0x16]&0x1f))<<(desc[0x12]&0x1f); uint32_t dd2=((0xffU>>(desc[0x17]&0x1f))<<(desc[0x13]&0x1f));
  *dd=(a& ((uint32_t*)desc)[0]) | (b& ((uint32_t*)desc)[1]) | (cc& ((uint32_t*)desc)[2]) | (dd2& ((uint32_t*)desc)[3]); dd++; } d=dd; } }
