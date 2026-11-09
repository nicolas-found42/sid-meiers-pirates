// Band4 wave3 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054c2e0 — observed purpose: thiscall vector-assign: operator_delete *(+0x14); if count/src null set +0x10/+0x14=0 else alloc count*4 via thunk_FUN_00533c78, unrolled 4-wide copy then tail. Corpus: analysis/pseudocode/functions/0x54c2e0.c
// 0x0054c420 — observed purpose: thiscall float-vector equality: +0x10 counts, +0x14 buffers, NaN/< /== flag merge, returns low byte 1 on equal else 0. Corpus: analysis/pseudocode/functions/0x54c420.c
// Observed: 54c2e0: *(in_ECX+0x10)=param_1; *(in_ECX+0x14)=thunk_FUN_00533c78(param_1*4); 4-wide until uVar2=iVar4*4 then scalar tail. 54c420: fVar1 vs fVar2 flags (fVar2<fVar1)<<8, NAN<<10, ==<<0xe; returns CONCAT31(...,1) on equal.
#include <stddef.h>
#include <stdint.h>
extern void operator_delete(void*);
extern void* __cdecl thunk_FUN_00533c78(uint32_t n);
struct Vec{ void* vt; uint32_t _4,_8,_c; uint32_t cnt; float* buf; };
// 0x0054c2e0
void __thiscall FUN_0054c2e0(Vec* self, uint32_t count, const float* src){
 operator_delete(self->buf);
 if(count==0||!src){ self->cnt=0; self->buf=nullptr; return; }
 self->cnt=count; float* dst=(float*)thunk_FUN_00533c78(count*4); self->buf=dst;
 uint32_t n=count; uint32_t i=0; uint32_t unroll=0;
 if(count>3){ uint32_t k=((count-4)>>2)+1; unroll=k*4;
  for(uint32_t j=0;j<k;++j){ const float* s=src+(j*4); float* d=dst+(j*4); d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; d[3]=s[3]; } }
 for(i=unroll;i<count;++i){ dst[i]=src[i]; }
 return; }
// 0x0054c420
uint32_t __thiscall FUN_0054c420(Vec* self, const Vec* other){
 if(!other) return 0; // in_EAX&0xffffff00 observed when param_1==0; result low byte 0 here (unverified widening)
 uint32_t cnt=other->cnt; if(self->cnt!=cnt) return 0;
 if(((self->buf==nullptr)!=(other->buf==nullptr))) return 0;
 if(!self->buf) return 1;
 for(uint32_t i=0;i<cnt;++i){ float a=other->buf[i], b=self->buf[i]; if(a!=b) return 0; if(!(a==a)||!(b==b)) return 0; }
 return 1; }
