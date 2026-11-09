// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054c1c0 — observed purpose: thiscall 0x40-byte ctor: FUN_00540c50, vtable 0x6c0a50, slots 6/2/3/0 at +0x20..+0x2c, FUN_00539760, vtable 0x6c215c. Corpus: analysis/pseudocode/functions/0x54c1c0.c
// 0x0054c210 — observed purpose: factory: pow2 checks on param_1/param_2, null checks, alloc 0x40, ctor FUN_0054c1c0, fill +0x38/+0x3c/+0x20..+0x28, validate vcall (*param_3+0x104), free on fail. Corpus: analysis/pseudocode/functions/0x54c210.c
// Observed: 54c1c0: in_ECX[8]=6; [9]=2; [10]=3; [0xb]=0; 54c210: ((param_1-1 &param_1)!=0) guard; puVar3[0xe]=param_1; [0xf]=param_2; [8..10]=param_4[0..2]; (**(code**)(*param_3+0x104))(puVar3); on '\0' (**(code**)*puVar3)(1); return 0.
#include <stdint.h>
extern void* __cdecl FUN_00533c78(int n);
extern void __cdecl FUN_00540c50(void*);
extern void __cdecl FUN_00539760(void*);
extern void* g_vt_6c0a50; extern void* g_vt_6c215c;
struct Obj54c1c0{ void* vt; uint32_t _4,_8,_c,_10,_14,_18,_1c; uint32_t s8,s9,sa,sb; };
// 0x0054c1c0
void __thiscall FUN_0054c1c0(Obj54c1c0* self){ FUN_00540c50(self); self->vt=&g_vt_6c0a50; self->s8=6; self->s9=2; self->sa=3; self->sb=0; FUN_00539760(self); self->vt=&g_vt_6c215c; }
// 0x0054c210
uint32_t* __cdecl FUN_0054c210(uint32_t p1, uint32_t p2, void* p3, uint32_t* p4){
 if(!p4||!p3||!p1||((p1-1)&p1)||!p2||((p2-1)&p2)) return nullptr;
 uint32_t* o=(uint32_t*)FUN_00533c78(0x40); if(!o) return nullptr;
 FUN_0054c1c0((Obj54c1c0*)o); o[0xe]=p1; o[0xf]=p2; o[8]=p4[0]; o[9]=p4[1]; o[10]=p4[2];
 typedef char(__cdecl*Val)(uint32_t*,void*); void** vt=*(void***)p3; Val vf=(Val)vt[0x104/4];
 if(vf(o,p3)==0){ typedef void(__cdecl*V)(void*,int); V v=*(V*)o; v(o,1); return nullptr; } return o; }
