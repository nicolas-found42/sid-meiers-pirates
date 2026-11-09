// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054ce20 — observed purpose: 3-byte->2-byte unscale loop: outer param_2 rows, inner param_1 cols; read 3 bytes, shift/mask per param_5 bytes/shifts, OR into *puVar8 ushort. Corpus: analysis/pseudocode/functions/0x54ce20.c
// Observed: bVar3=*param_6; pbVar1=+1; pbVar2=+2; param_6+=3; param_3=puVar8+1; three CONCAT22 stages with param_5[10]/[8],[0xb]/[9],[0x15]/[0x11]; final &param_5[2], &*param_5, &param_5[4], &param_5[6].
#include <stddef.h>
#include <stdint.h>
static inline uint32_t sh(uint32_t v,int s){ return (v>>(s&0x1f))<<(0); }
// 0x0054ce20
void __cdecl FUN_0054ce20(int cols, int rows, uint16_t* dst, uint16_t* unused, const uint8_t* desc, const uint8_t* src){
 if(rows==0) return;
 const uint8_t* s=src; uint16_t* d=dst;
 for(int r=0;r<rows;++r){ if(cols==0) continue; uint16_t* dd=d; for(int c=0;c<cols;++c){ uint8_t b0=s[0],b1=s[1],b2=s[2]; s+=3;
  uint32_t a=(b0>> (desc[10]&0x1f)) & 0xffff; a=(a<< (desc[8]&0x1f)) & desc[0];
  uint32_t b=(b2>> (desc[0xb]&0x1f)) & 0xffff; b=(b<< (desc[9]&0x1f)) & desc[4];
  uint32_t cc=(b1>> (desc[0x15]&0x1f)) & 0xffff; cc=(cc<< (desc[0x11]&0x1f)) & desc[2];
  uint32_t dd4=((0xffU>> (desc[0x17]&0x1f)) << (desc[0x13]&0x1f)) & desc[6];
  *dd=(uint16_t)(a|b|cc|dd4); dd++; } d=dd; } }
