// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054c720 — observed purpose: copy 9 dwords DAT_00727484 -> DAT_00717a00. Corpus: analysis/pseudocode/functions/0x54c720.c
// 0x0054c750 — observed purpose: release7-entry table DAT_007279c8[7] (0x1c bytes), zero each. Corpus: analysis/pseudocode/functions/0x54c750.c
// 0x0054c780 — observed purpose: copy 9 dwords param_1 -> DAT_00717a00 then release/zero DAT_007279c8[7]. Corpus: analysis/pseudocode/functions/0x54c780.c
// Observed: 54c720/54c780: for(iVar1=9;iVar1!=0;--iVar1) copy; 54c750/54c780: do{release at (+uVar3) step 4 while uVar3<0x1c; *(...)=0}.
#include <stdint.h>
extern uint32_t g_src_727484[9];
extern uint32_t g_dst_717a00[9];
extern void* g_table_7279c8[7];
static void ReleaseRef(void* p){ if(!p) return; uint32_t* rc=(uint32_t*)p+1; *rc-=1; if(*rc==0){ typedef void(__cdecl*V)(void*,int); V v=*(V*)p; v(p,1);} }
// 0x0054c720
void __cdecl FUN_0054c720(void){ for(int i=0;i<9;++i) g_dst_717a00[i]=g_src_727484[i]; }
// 0x0054c750
void __cdecl FUN_0054c750(void){ for(int i=0;i<7;++i){ void* p=g_table_7279c8[i]; if(p){ ReleaseRef(p); g_table_7279c8[i]=nullptr; } } }
// 0x0054c780
void __cdecl FUN_0054c780(const uint32_t* src){ for(int i=0;i<9;++i) g_dst_717a00[i]=src[i]; FUN_0054c750(); }
