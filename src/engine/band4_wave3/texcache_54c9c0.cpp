// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054c9c0 — observed purpose: indexed texture cache: bounds (-1<(int)param_1||6<(param_1&0x7fffffff)) return 0; if DAT_007279c8[param_1] return it; else build matrix locals with 0x3f800000 (1.0f) per case 0x80000001..06, FUN_0054c7c0(&local_20,&local_30,&DAT_00717a00), FUN_0051ac30, return cached. Corpus: analysis/pseudocode/functions/0x54c9c0.c
// Observed: switch cases fill local_20/local_1c/local_18/local_10/local_c/local_8/local_4/local_14/local_24/local_30..28; default path LAB_0054cbed sets 1.0f entries.
#include <stdint.h>
extern void* g_table_7279c8[7];
extern uint32_t g_tex_717a00[9];
extern void* __cdecl FUN_0054c7c0(void*,void*,void*);
extern void __cdecl FUN_0051ac30(void*);
// 0x0054c9c0
void* __cdecl FUN_0054c9c0(int32_t idx){
 if(idx<-1||(idx&0x7fffffff)>6) return nullptr;
 if(g_table_7279c8[idx]) return g_table_7279c8[idx];
 uint32_t L30=0,L2c=0,L28=0,L10=0x3f800000,Lc=0,L8=0;
 uint32_t sub1[2]={0,0}, sub2[2]={0,0};
 switch(0x80000000|idx){
  case 0x80000001: sub1[0]=0x3f800000; break;
  case 0x80000002: L10=0x3f800000; goto comp;
  case 0x80000003: sub1[1]=0x3f800000; break;
  case 0x80000004: sub1[0]=0; goto comp2;
  default: break;
 }
 comp2:
 comp:
 { uint32_t tmp[8]={0,0,0,L10,Lc,L8,0x3f800000,0x3f800000};
   void* v=FUN_0054c7c0(sub1,tmp,g_tex_717a00); FUN_0051ac30(v); }
 return g_table_7279c8[idx]; }
