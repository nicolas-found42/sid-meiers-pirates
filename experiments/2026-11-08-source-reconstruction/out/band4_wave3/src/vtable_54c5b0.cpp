// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054c5b0 — observed purpose: thiscall: FUN_00547e30(param_1); two vcall +0x0c via *(param_1+0x160) with (+0x10,4) and (+0x14,+0x10<<2). Corpus: analysis/pseudocode/functions/0x54c5b0.c
// Observed: (**(code**)(**(int**)(param_1+0x160)+0xc))((int*)(in_ECX+0x10),4); (**(code**)(**(int**)(param_1+0x160)+0xc))(*(in_ECX+0x14),*(in_ECX+0x10)<<2).
#include <stdint.h>
extern void __cdecl FUN_00547e30(void*);
// 0x0054c5b0
void __thiscall FUN_0054c5b0(uint32_t* self, void* p1){
 FUN_00547e30(p1);
 typedef void(__cdecl*V)(uint32_t*,uint32_t);
 void** vt=*(void***)((uint8_t*)p1+0x160);
 V v=(V)vt[0x0c/4]; v(self+4/4,4); // self+0x10 approx: self is uint32_t* so +4 = +0x10 bytes
 uint32_t cnt=self[4]; void* buf=(void*)self[5];
 v(buf, cnt<<2); }
