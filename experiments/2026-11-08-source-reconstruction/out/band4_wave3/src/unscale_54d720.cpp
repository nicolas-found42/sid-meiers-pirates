// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054d720 — observed purpose: 3-byte+pad stride-4 ->2-byte unscale loop with CONCAT22 through in_EDX/unaff_EBX/unaff_EBP, (short) store per pixel. Corpus: analysis/pseudocode/functions/0x54d720.c
// Observed: param_6+=4 (3 used bytes +1 pad); masks *param_5, param_5[2], param_5[6]; shifts via desc bytes 10/8, 0x15/0x11, 0x17/0x13.
#include <stdint.h>
// 0x0054d720
void __cdecl FUN_0054d720(int cols,int rows,short* dst,const uint8_t* src,const uint8_t* desc){
 if(rows==0) return; const uint8_t* s=src; short* d=dst;
 for(int r=0;r<rows;++r){ if(cols==0) continue; short* dd=d; for(int c=0;c<cols;++c){ uint8_t b0=s[0],b1=s[1],b2=s[2]; s+=4;
  uint32_t a=((b0>>(desc[10]&0x1f))<<(desc[8]&0x1f))&desc[0];
  uint32_t b=((b1>>(desc[0x15]&0x1f))<<(desc[0x11]&0x1f))&desc[2];
  uint32_t cc=((b2>>(desc[0x17]&0x1f))<<(desc[0x13]&0x1f))&desc[6];
  *dd=(short)(a|b|cc); dd++; } d=dd; } }
