// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054c7c0 — observed purpose: alloc 0x50, FUN_00539210(8,8,param_3,1), pack 8x FUN_005f0ddc channels by masks/shifts DAT_00717860-7c into local_8[2], byte-tile copy 8x8 via *(param_3+0x40)+*(param_3+0x34) stride bVar9>>3. Corpus: analysis/pseudocode/functions/0x54c7c0.c
// Observed: iVar2=FUN_00533c78(0x50); param_3=FUN_00539210(8,8,param_3,1); masks DAT_00717860/64/68/6c, shifts DAT_00717870/74/78/7c; 8 FUN_005f0ddc calls; nested 8x8 tile loop with bVar9=*(iVar1+0x18).
#include <stdint.h>
extern void* __cdecl FUN_00533c78(int n);
extern void* __cdecl FUN_00539210(int a,int b,void* c,int d);
extern uint32_t __cdecl FUN_005f0ddc(void);
extern uint32_t g_m1,g_m2,g_m3,g_m4; extern uint32_t g_s1,g_s2,g_s3,g_s4;
// 0x0054c7c0
void* __cdecl FUN_0054c7c0(void* out1, void* out2, void* src){
 void* obj=FUN_00533c78(0x50); if(!obj) return nullptr;
 void* composed=FUN_00539210(8,8,src,1);
 uint32_t words[2];
 uint32_t r[2];
 for(int k=0;k<2;++k){ uint32_t c0=FUN_005f0ddc(),c1=FUN_005f0ddc(),c2=FUN_005f0ddc(),c3=FUN_005f0ddc(); r[k]=(c0&g_m1)|(c1&g_m2)|(c2&g_m3)|(c3&g_m4); }
 words[0]=r[0]; words[1]=r[1];
 uint32_t* dst=(uint32_t*)((uint8_t*)composed+0x40)+ *(uint32_t*)((uint8_t*)composed+0x34)/4;
 uint8_t stride=(uint8_t)(*(uint8_t*)((uint8_t*)src+0x18)>>3);
 for(int y=0;y<8;++y) for(int x=0;x<8;++x){ *dst=words[(x+y)&1]; dst++; }
 return composed; }
