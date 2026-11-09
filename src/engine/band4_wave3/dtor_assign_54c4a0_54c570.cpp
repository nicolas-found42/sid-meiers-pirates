// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054c4a0 — observed purpose: thiscall assign-ctor: FUN_00547c80, vtable 0x6c21ac, +0x14=0, FUN_0054c2e0(param_1,param_2). Corpus: analysis/pseudocode/functions/0x54c4a0.c
// 0x0054c570 — observed purpose: deleting dtor: vtable 0x6c21ac, operator_delete(+0x14) then =0, FUN_00547d10, if(param_1&1) operator_delete(this). Corpus: analysis/pseudocode/functions/0x54c570.c
// Observed: 54c4a0: in_ECX[5]=0; 54c570: *(void**)(in_ECX+0x14) delete via operator_delete__; in_ECX[5]=0.
#include <stddef.h>
#include <stdint.h>
extern void operator_delete(void*);
extern void __cdecl FUN_00547c80(void*);
extern void __cdecl FUN_00547d10(void*);
extern void __thiscall FUN_0054c2e0(void*,uint32_t,const float*);
extern void* g_vt_6c21ac;
struct Obj54c4a0{ void* vt; uint32_t _4,_8,_c,_10; float* buf; };
// 0x0054c4a0
void __thiscall FUN_0054c4a0(Obj54c4a0* self,uint32_t count,const float* src){ FUN_00547c80(self); self->vt=&g_vt_6c21ac; self->buf=nullptr; FUN_0054c2e0(self,count,src); }
// 0x0054c570
void __thiscall FUN_0054c570(Obj54c4a0* self,uint32_t flag){ self->vt=&g_vt_6c21ac; operator_delete(self->buf); self->buf=nullptr; FUN_00547d10(self); if((flag&1)!=0) operator_delete(self); }
