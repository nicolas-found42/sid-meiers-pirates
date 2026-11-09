// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054bc90 — observed purpose: thiscall ctor fragment: base init then vtable 0x711788, +0x0c zero. Corpus: analysis/pseudocode/functions/0x54bc90.c
// 0x0054bfc0 — observed purpose: alloc 0x34, init, vtable 0x70dea4, scale 1.0f at +0x24, swap global DAT_00727980 with addref/release. Corpus: analysis/pseudocode/functions/0x54bfc0.c
// 0x0054c050 — observed purpose: release global DAT_00727980, zero it. Corpus: analysis/pseudocode/functions/0x54c050.c
// Observed: 54bc90: FUN_005383d0(); *in_ECX=&PTR_FUN_00711788; in_ECX[3]=0; 54bfc0: FUN_00533c78(0x34); FUN_00540c50(); *puVar3=&PTR_FUN_0070dea4; puVar3[10..12]=DAT_00727424/28/2c; puVar3[9]=0x3f800000; *(undefined2*)(puVar3+8)=0; swap DAT_00727980 with release-at-0. 54c050: release DAT_00727980 then =0.
#include <stdint.h>
extern void* __cdecl FUN_00533c78(int nbytes);
extern void __cdecl FUN_005383d0(void*);
extern void __cdecl FUN_00540c50(void*);
extern void* g_vt_711788;
extern void* g_vt_70dea4;
extern void* g_slot_727980;
extern float g_f_727424; extern float g_f_727428; extern float g_f_72742c;
struct Obj54bc90{ void* vt; uint32_t w4,w8,wc; };
static void ReleaseRef(void* p){ if(!p) return; uint32_t* rc=(uint32_t*)p+1; *rc-=1; if(*rc==0){ typedef void(__cdecl*V)(void*,int); V v=*(V*)p; v(p,1);} }
static void AddRef(void* p){ if(p) ((uint32_t*)p)[1]+=1; }
// 0x0054bc90
void __thiscall FUN_0054bc90(Obj54bc90* self){ FUN_005383d0(self); self->vt=&g_vt_711788; self->wc=0; }
// 0x0054bfc0
void __cdecl FUN_0054bfc0(void){ uint32_t* o=(uint32_t*)FUN_00533c78(0x34); if(o){ FUN_00540c50(o); *(void**)o=&g_vt_70dea4; o[3]=0; o[9]=0x3f800000; o[10]=0; o[11]=0; o[12]=0; o[10]=*(uint32_t*)&g_f_727424; o[11]=*(uint32_t*)&g_f_727428; o[12]=*(uint32_t*)&g_f_72742c; } void* old=g_slot_727980; if(old!=o){ ReleaseRef(old); g_slot_727980=o; AddRef(o);} }
// 0x0054c050
void __cdecl FUN_0054c050(void){ void* old=g_slot_727980; if(old){ ReleaseRef(old); g_slot_727980=nullptr; } }
