// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054cc80 — observed purpose: append value from DAT_007279a0: FUN_00541080(param_1); v=FUN_00557b10(DAT_007279a0); count=*(+0x0c); if(*( +8)<=count) FUN_006b34a0(*( +0x14)+count); FUN_005606f0(count,&v). Corpus: analysis/pseudocode/functions/0x54cc80.c
// Observed: iVar2=param_1 preserved across calls; FUN_005606f0(uVar1,&param_1) with count uVar1=*(iVar2+0xc).
#include <stdint.h>
extern void __cdecl FUN_00541080(void*);
extern uint32_t __cdecl FUN_00557b10(void*);
extern void __cdecl FUN_006b34a0(uint32_t);
extern void __cdecl FUN_005606f0(uint32_t,void*);
extern void* g_slot_7279a0;
// 0x0054cc80
void __cdecl FUN_0054cc80(uint32_t* arr){
 FUN_00541080(arr);
 uint32_t v=FUN_00557b10(g_slot_7279a0);
 uint32_t cnt=arr[3]; // +0x0c
 if(arr[2]<=cnt) FUN_006b34a0(arr[5]+cnt); // +0x14
 FUN_005606f0(cnt,&v); }
