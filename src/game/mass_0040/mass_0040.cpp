#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern declarations for helpers and globals referenced by the listings.
extern DWORD timeGetTime();
extern void* FUN_00533c78(uint32_t size);
extern void operator_delete(void* p);
extern uint32_t DAT_008ed61c;
extern uint32_t DAT_008ed618;
extern uint32_t DAT_00726ae8;
extern uint32_t DAT_00726aec;
extern uint32_t DAT_00726af0;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern void* PTR_FUN_0070d13c;
extern void* PTR_FUN_0070d028;
extern void* PTR_FUN_006fd14c;
extern void* PTR_LAB_006fd148;
extern HANDLE DAT_00726b0c;
extern uint32_t DAT_00726c28;
extern uint32_t DAT_00726acc;
extern uint32_t DAT_00726ac8;
extern uint32_t DAT_00726ad0;
extern uint32_t* DAT_00726ac4;
extern void FUN_004fac10();
extern void FUN_004f5670();
extern void FUN_004bd880(int a);
extern void FUN_004bdbc0(void* a);
extern void FUN_004bf320(void* a);
extern void FUN_004bf130(void* a);
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_004afae0(void* a);
extern void FUN_004c0940();
extern void FUN_004c0a40(int a);
extern void FUN_004bc450(int a);
extern void FUN_004b0a90(int a, int b);
extern void FUN_004bc7e0(int a, int b);
extern void FUN_004beee0();
extern void FUN_004bed70(void* self, void* a);
extern DWORD DAT_00727444;
extern void FUN_005516a0();
extern void FUN_00500b50();
extern void FUN_004bb980();
extern void FUN_004ab3c0(void* a, void* b);
extern void FUN_004bef50();
extern void FUN_0050d2f0();
extern void FUN_004c3000();
extern void FUN_0050f1e0();
extern void FUN_004baf50();
extern void FUN_00497c0(const char* fmt, uint32_t v);

// 0x4baae0 — observed shape: self init (+0x08 sig 0x46495245), time delta at +0x0c, defaults, refcount releases at +0x1c/+0x64/+0xbc, 4 small objects at +0x94 and one at +0x88 when param_1 != 0.
void FUN_004baae0(void* self, int param_1) {
  uint8_t* s = static_cast<uint8_t*>(self);
  auto w32 = [&](size_t off, uint32_t v){ *reinterpret_cast<uint32_t*>(s+off)=v; };
  auto r32 = [&](size_t off)->uint32_t{ return *reinterpret_cast<uint32_t*>(s+off); };
  auto rptr = [&](size_t off)->uint32_t*{ return *reinterpret_cast<uint32_t**>(s+off); };
  auto release = [&](uint32_t* p){
    int* pi = reinterpret_cast<int*>(p)+1;
    *pi = *pi - 1;
    if (*pi == 0) {
      using F = void(*)(int);
      auto v = *reinterpret_cast<void**>(p);
      auto f = *reinterpret_cast<F*>(v);
      f(1);
    }
  };
  uint32_t uVar2 = DAT_008ed61c & 1;
  w32(8, 0x46495245u);
  if (uVar2 == 0) { DAT_008ed61c |= 1; DAT_008ed618 = timeGetTime(); }
  DWORD DVar3 = timeGetTime();
  w32(0xc, DVar3 - DAT_008ed618);
  w32(0x10,0); w32(0x14,0); w32(0x50,0); w32(0x20,0);
  *(uint8_t*)(s+0x24)=0; *(uint8_t*)(s+0x25)=0;
  w32(0x28,0); w32(0x2c,0); w32(0x30,0xfffffffeu);
  w32(0x44,0); w32(0x40,0xffffffffu); *(uint8_t*)(s+0x4c)=1;
  w32(0x3c,0); w32(0x48,100);
  *reinterpret_cast<int*>(s+0x18)=param_1;
  if (auto p = rptr(0x1c)) { release(p); w32(0x1c,0); }
  w32(0x84,0);
  w32(0x6c,DAT_00726ae8); w32(0x70,DAT_00726aec); w32(0x74,DAT_00726af0);
  w32(0x60,0); w32(0xa4,0); w32(0x68,0); *(uint8_t*)(s+0x4d)=0; w32(0x5c,0);
  if (auto p = rptr(100)) { release(p); w32(100,0); }
  w32(0x34,0); w32(0x38,0); w32(0x58,0); w32(0x54,0);
  w32(0x78,DAT_00727430); w32(0x7c,DAT_00727434); w32(0x80,DAT_00727438);
  w32(0x90,0); w32(0xa8,0x3f800000u); *(uint8_t*)(s+0xac)=0;
  w32(0xb0,0); w32(0xb4,0); w32(0xb8,0xffffffffu); w32(0x8c,0);
  if (auto p = rptr(0xbc)) { release(p); w32(0xbc,0); }
  if (param_1 != 0) {
    uint32_t* pu = static_cast<uint32_t*>(FUN_00533c78(0x18));
    if (pu) { pu[0]=(uint32_t)(uintptr_t)&PTR_FUN_0070d13c; pu[2]=0; pu[5]=1; pu[3]=0; pu[4]=0; pu[1]=0; }
    *reinterpret_cast<uint32_t**>(s+0x88)=pu;
    uint32_t** cur = reinterpret_cast<uint32_t**>(s+0x94);
    int iVar6=4;
    do {
      uint32_t* v = static_cast<uint32_t*>(FUN_00533c78(0x18));
      if (v) { v[0]=(uint32_t)(uintptr_t)&PTR_FUN_0070d028; v[2]=0; v[5]=1; v[3]=0; v[4]=0; v[1]=0; }
      *cur=v; cur++; iVar6--;
    } while(iVar6!=0);
  }
}

// 0x4baca0 — observed shape: EDI receiver, mutex/TLS wait, slot array DAT_00726ac4 indexed by DAT_00726acc, then teardown calls and signature 0x41584953 at +8.
void FUN_004baca0(void* self) {
  uint8_t* edi = static_cast<uint8_t*>(self);
  HANDLE hHandle = DAT_00726b0c;
  if ((DAT_00726c28 == 0xffffffffu) || (TlsGetValue(DAT_00726c28) == nullptr)) {
    WaitForSingleObject(hHandle, 0xffffffffu);
  } else { FUN_004fac10(); }
  uint32_t uVar1 = DAT_00726acc;
  if (DAT_00726acc < DAT_00726ac8) {
    DAT_00726acc = uVar1 + 1;
    if (edi != nullptr) DAT_00726ad0 += 1;
  } else {
    FUN_004f5670();
    if (DAT_00726ac8 <= uVar1) goto LAB_004bad4e;
    if (DAT_00726acc <= uVar1) { DAT_00726acc = uVar1 + 1; if (edi) DAT_00726ad0+=1; }
    else if (edi == nullptr) {
      if (*(int*)(DAT_00726ac4 + uVar1*4) != 0) DAT_00726ad0 -= 1;
    } else if (*(int*)(DAT_00726ac4 + uVar1*4) == 0) DAT_00726ad0 += 1;
  }
  *(int*)(DAT_00726ac4 + uVar1*4) = (int)(uintptr_t)edi;
LAB_004bad4e:
  if (*reinterpret_cast<int*>(edi+0x1c) != 0) {
    int inner = *reinterpret_cast<int*>(edi+0x1c);
    FUN_004bd880(inner); FUN_004bdbc0(edi); FUN_004bf320((void*)(intptr_t)inner);
    FUN_004bf130((void*)(intptr_t)inner); FUN_00534130(); FUN_00534350(); FUN_004afae0((void*)(intptr_t)inner);
    auto cb = *reinterpret_cast<void(**)()>(edi+0x54);
    if (cb) cb();
  }
  ReleaseMutex(DAT_00726b0c);
  *reinterpret_cast<uint32_t*>(edi+8)=0x41584953u;
}

// 0x4badc0 — observed shape: EAX receiver, early-out if +0x1c==0, mutex wait, flag dispatch on +0x20 masks 0x4000/2/4/8/0x40000/0x10..0x400/0x800/0x1000.
void FUN_004badc0(void* self) {
  uint8_t* eax = static_cast<uint8_t*>(self);
  HANDLE hHandle = DAT_00726b0c;
  if (*reinterpret_cast<int*>(eax+0x1c)==0) return;
  if ((DAT_00726c28 == 0xffffffffu) || (TlsGetValue(DAT_00726c28)==nullptr)) {
    WaitForSingleObject(hHandle,0xffffffffu);
  } else FUN_004fac10();
  uint32_t flags = *reinterpret_cast<uint32_t*>(eax+0x20);
  if ((flags & 0x4000)!=0) FUN_004c0940();
  if ((*(uint8_t*)(eax+0x20) & 2)!=0) FUN_004c0a40(0);
  uint32_t uVar3;
  if ((flags & 4)==0) { if ((flags & 8)==0) goto LAB_004bae36; uVar3=0; } else uVar3=1;
  FUN_004bc450((int)uVar3);
LAB_004bae36:
  if (((flags & 0x40000)!=0) && (*reinterpret_cast<int*>(eax+0x1c)!=0)) FUN_004b0a90(*reinterpret_cast<int*>(eax+0x1c),1);
  uint32_t uVar1 = *reinterpret_cast<uint32_t*>(eax+0x20);
  if ((((((uVar1&0x10)!=0)||((uVar1&0x20)!=0))||((uVar1&0x40)!=0))||(((int8_t)uVar1<0||((uVar1&0x100)!=0)))||(((uVar1&0x200)!=0||((uVar1&0x400)!=0)))) FUN_004bc7e0(0,0);
  if (((uVar1&0x800)!=0)&&(*reinterpret_cast<int*>(eax+0x58)!=0)) FUN_004beee0();
  if ((uVar1&0x1000)!=0) FUN_004bed70(eax,(void*)(intptr_t)*reinterpret_cast<int*>(eax+0x5c));
  ReleaseMutex(DAT_00726b0c);
}

// 0x4baef0 — observed shape: ECX receiver ctor/dtor swap vtable to PTR_FUN_006fd14c, call FUN_004baf50, release refs at +0xbc/+0x64/+0x1c, restore vtable, decrement DAT_00727444.
void FUN_004baef0(void* self) {
  uint32_t* ecx = static_cast<uint32_t*>(self);
  ecx[0]=(uint32_t)(uintptr_t)&PTR_FUN_006fd14c;
  FUN_004baf50();
  auto rel = [&](uint32_t* p){ if(!p)return; int* pi=(int*)p+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)(p[0]))(1);} };
  rel(reinterpret_cast<uint32_t*>(ecx[0x2f]));
  rel(reinterpret_cast<uint32_t*>(ecx[0x19]));
  rel(reinterpret_cast<uint32_t*>(ecx[7]));
  ecx[0]=(uint32_t)(uintptr_t)&PTR_LAB_006fd148;
  DAT_00727444 -= 1;
}

// 0x4baf50 — observed shape: EAX receiver destroy; guards on +8 signature 0x46495245/0x41584953, unlink +0x50 list, mutex section tearing down arrays at +0x94/+0x88/+0x8c, slot removal, ReleaseMutex, then re-init via FUN_004baae0(0).
void FUN_004baf50(void* self) {
  uint8_t* eax = static_cast<uint8_t*>(self);
  if ((*reinterpret_cast<int*>(eax+8)==(int)0x46495245)||(*reinterpret_cast<int*>(eax+8)==(int)0x41584953)) {
    if (*reinterpret_cast<int*>(eax+0x50)!=0) {
      FUN_005516a0(); FUN_00500b50();
      if (*reinterpret_cast<int*>(eax+0x50)!=0) {
        int* piVar9 = *reinterpret_cast<int**>(eax+0x50);
        if (*reinterpret_cast<int*>(piVar9[0]+0x10)==(int)(uintptr_t)eax) *reinterpret_cast<uint32_t*>(piVar9[0]+0x10)=0;
        *reinterpret_cast<uint32_t*>(eax+0x50)=0;
        if (piVar9==nullptr) return;
        using F=void(*)(int); (*(F*)(piVar9[0]+4))(1);
        return;
      }
    }
    HANDLE hHandle = DAT_00726b0c;
    if (*reinterpret_cast<int*>(eax+8)==(int)0x41584953) {
      if ((DAT_00726c28==0xffffffffu)||(TlsGetValue(DAT_00726c28)==nullptr)) WaitForSingleObject(hHandle,0xffffffffu); else FUN_004fac10();
      FUN_004bb980();
      // Traverse DAT_007268e0 list (omitted detail preserved as no-op linkage)
      if (*reinterpret_cast<int*>(eax+0x58)!=0) FUN_004bef50();
      int* piVar9 = reinterpret_cast<int*>(eax+0x94); int iVar10=4; int* piVar8=piVar9;
      do { int v=*piVar8; if(v){ if(*reinterpret_cast<int*>(v+0xc)!=0){ uint32_t u=0; do{ *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(v+4)+u*4)=0; u++; }while(u<*reinterpret_cast<uint32_t*>(v+0xc)); } *reinterpret_cast<uint32_t*>(v+0xc)=0; *reinterpret_cast<uint32_t*>(v+0x10)=0; } piVar8++; iVar10--; } while(iVar10!=0);
      if (*reinterpret_cast<uint32_t**>(eax+0x88)) { using F=void(*)(int); (*(F*)(**reinterpret_cast<uint32_t**>(eax+0x88))))(1); *reinterpret_cast<uint32_t*>(eax+0x88)=0; }
      if (*reinterpret_cast<uint32_t**>(eax+0x8c)) { using F=void(*)(int); (*(F*)(**reinterpret_cast<uint32_t**>(eax+0x8c))))(1); *reinterpret_cast<uint32_t*>(eax+0x8c)=0; }
      iVar10=4; do { if(*reinterpret_cast<uint32_t**>(piVar9)) { using F=void(*)(int); (*(F*)(**piVar9))(1); *piVar9=0; } piVar9++; iVar10--; } while(iVar10!=0);
      if (auto p=*reinterpret_cast<uint32_t**>(eax+0x1c)) { int* pi=(int*)p+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)p[0])(1);} *reinterpret_cast<uint32_t*>(eax+0x1c)=0; }
      if (auto p=*reinterpret_cast<uint32_t**>(eax+100)) { int* pi=(int*)p+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)p[0])(1);} *reinterpret_cast<uint32_t*>(eax+100)=0; }
      if (*reinterpret_cast<uint32_t**>(eax+0xa4)) { using F=void(*)(int); (*(F*)(**reinterpret_cast<uint32_t**>(eax+0xa4))))(1); }
      if (*reinterpret_cast<int*>(eax+0x84)!=0) {
        int i10=*reinterpret_cast<int*>(*reinterpret_cast<int*>(eax+0x84)+0xc);
        while(i10!=0){ void* pv=nullptr; int base=*reinterpret_cast<int*>(eax+0x84); if(*reinterpret_cast<int*>(base+0xc)!=0){ int n=*reinterpret_cast<int*>(base+0xc)-1; *reinterpret_cast<int*>(base+0xc)=n; pv=(void*)(intptr_t)*reinterpret_cast<int*>(*reinterpret_cast<int*>(base+4)+n*4); *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(base+4)+n*4)=0; if(pv) *reinterpret_cast<int*>(base+0x10)-=1; } if(pv){ FUN_0050d2f0(); operator_delete(pv); } i10=*reinterpret_cast<int*>(*reinterpret_cast<int*>(eax+0x84)+0xc); }
        if (*reinterpret_cast<uint32_t**>(eax+0x84)) { using F=void(*)(int); (*(F*)(**reinterpret_cast<uint32_t**>(eax+0x84))))(1); }
      }
      if (*reinterpret_cast<int*>(eax+0x68)!=0) { FUN_004c3000(); void* pv=(void*)(intptr_t)*reinterpret_cast<int*>(eax+0x68); if(pv){ FUN_0050f1e0(); operator_delete(pv); *reinterpret_cast<uint32_t*>(eax+0x68)=0; } }
      uint32_t u=0;
      if (DAT_00726acc!=0) { do { if (DAT_00726ac4[u]==(uintptr_t)eax) { if (u<DAT_00726acc){ DAT_00726acc-=1; int v=DAT_00726ac4[u]; DAT_00726ac4[u]=DAT_00726ac4[DAT_00726acc]; DAT_00726ac4[DAT_00726acc]=0; if(v) DAT_00726ad0-=1; } break; } u++; } while(u<DAT_00726acc); }
      ReleaseMutex(DAT_00726b0c);
      if (auto p=*reinterpret_cast<uint32_t**>(eax+0xbc)) { int* pi=(int*)p+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)p[0])(1);} *reinterpret_cast<uint32_t*>(eax+0xbc)=0; }
      if ((*reinterpret_cast<int*>(eax+0x14)==0) && *reinterpret_cast<uint32_t**>(eax+0x10)) { uint32_t* cur=*reinterpret_cast<uint32_t**>(eax+0x10); do { uint32_t* next=(uint32_t*)cur[4]; using F=void(*)(int); (*(F*)cur[0])(1); cur=next; } while(cur); }
      if (*reinterpret_cast<int*>(eax+0x10)!=0) *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(eax+0x10)+0x14)=*reinterpret_cast<uint32_t*>(eax+0x14);
      if (*reinterpret_cast<int*>(eax+0x14)!=0) *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(eax+0x14)+0x10)=*reinterpret_cast<uint32_t*>(eax+0x10);
      FUN_004baae0(eax,0);
    }
  }
}

// 0x4bb2d0 — observed shape: logs max attach size, drains DAT_00726acc slot queue destroying entries, then walks DAT_008ca4c8 linked list invoking +8 callbacks.
extern uint32_t DAT_008cabf8;
extern uint32_t DAT_008e8fe0;
extern void* DAT_008ee20c;
extern void* DAT_008ca4c8;
extern void FUN_004b97c0(const char* fmt, uint32_t v);
extern uint32_t DAT_008cac00;
void FUN_004bb2d0() {
  uint32_t* cur = reinterpret_cast<uint32_t*>(DAT_008e8fe0);
  FUN_005516a0();
  FUN_004b97c0("Object3d max attach size = %d", DAT_008cabf8);
  while (DAT_00726acc != 0) {
    uint32_t* p = reinterpret_cast<uint32_t*>(DAT_00726ac4[0]);
    if (p[1]==0) {
      if (reinterpret_cast<uintptr_t>(p) < reinterpret_cast<uintptr_t>(&DAT_008ee20c)+1) FUN_004baf50();
      else { using F=void(*)(int); (*(F*)p[0])(1); }
    } else {
      DAT_00726acc -= 1;
      uint32_t u = DAT_00726ac4[0];
      DAT_00726ac4[0]=DAT_00726ac4[DAT_00726acc]; DAT_00726ac4[DAT_00726acc]=0;
      if (u) DAT_00726ad0 -= 1;
    }
  }
  if (cur) { int c=reinterpret_cast<int*>(cur)[1]; reinterpret_cast<int*>(cur)[1]=c-1; if(c-1==0){ using F=void(*)(int); (*(F*)cur[0])(1);} DAT_008e8fe0=0; }
  uint32_t* pi = reinterpret_cast<uint32_t*>(DAT_008ca4c8);
  int count = reinterpret_cast<int*>(pi)[3];
  while (count!=0) {
    int* node = reinterpret_cast<int*>(pi[1]);
    pi[1]=node[0]; if(node[0]==0) ((int*)pi)[2]=0; else *reinterpret_cast<uint32_t*>(node[0]+4)=0;
    int holder = node[2];
    using F=void(*)(int*); ((F*)(*reinterpret_cast<int*>(pi)+8))(node);
    reinterpret_cast<int*>(pi)[3] -= 1;
    uint32_t* q = *reinterpret_cast<uint32_t**>(holder+0x10);
    if (reinterpret_cast<uintptr_t>(q) < reinterpret_cast<uintptr_t>(&DAT_008ee20c)+1) FUN_004baf50();
    else if(q){ using G=void(*)(int); (*(G*)q[0])(1); }
    pi = reinterpret_cast<uint32_t*>(DAT_008ca4c8); count = reinterpret_cast<int*>(pi)[3];
  }
  DAT_008ca4c8 = reinterpret_cast<uint32_t>(pi);
}

// 0x4bb3e0 — observed shape: scans DAT_00726ae0 bucket array, walks node list calling +9(flag)/+0x14 releases, clears DAT_008cac00 at end.
extern uint32_t DAT_00726adc;
extern uint32_t* DAT_00726ae0;
extern void* PTR_PTR_00726ad8;
void FUN_004bb3e0() {
  uint32_t idx=0; int* node=nullptr;
  if (DAT_00726adc) { do { node=reinterpret_cast<int*>(DAT_00726ae0[idx]); if(node) break; idx++; } while(idx<DAT_00726adc); }
  if (!node) { DAT_008cac00=0; return; }
  while(true) {
    uint32_t* obj = reinterpret_cast<uint32_t*>(node[1]);
    node = reinterpret_cast<int*>(node[0]);
    if (!node) {
      using F=uint32_t(*)(uint32_t*); idx = (*(F*)((uint8_t*)PTR_PTR_00726ad8+4))(obj);
      do { idx++; if (idx>=DAT_00726adc){ node=nullptr; break; } node=reinterpret_cast<int*>(DAT_00726ae0[idx]); } while(!node);
    }
    if (reinterpret_cast<uint8_t*>(obj)[36]==0) {
      FUN_004bb980();
      if (obj[5]!=0) {
        using F=void(*)(int); (*(F*)obj[0])(1);
        if (!node){ DAT_008cac00=0; return; }
        if (node[1]==0) node=reinterpret_cast<int*>(node[0]);
      }
    } else { reinterpret_cast<uint8_t*>(obj)[36]=0; }
    if (!node){ DAT_008cac00=0; return; }
  }
}

// 0x4bb4b0 — observed shape: ECX receiver list-insertion; if self null or +0x10 null, allocate via FUN_004bb500 and link +0x10/+0x14.
extern uint32_t* FUN_004bb500(int param_1);
void FUN_004bb4b0(void* self, int param_1) {
  uint8_t* ecx = static_cast<uint8_t*>(self);
  if (!ecx) { uint32_t* n=FUN_004bb500(param_1); *reinterpret_cast<uint32_t*>((uint8_t*)param_1+0x10)=(uint32_t)(uintptr_t)n; *reinterpret_cast<uint32_t*>((uint8_t*)n+0x14)=(uint32_t)param_1; return; }
  while (*reinterpret_cast<uint8_t*>(ecx+0x24)!=0) {
    ecx = *reinterpret_cast<uint8_t**>(ecx+0x10);
    if (!*reinterpret_cast<uint8_t**>(ecx+0x10)) { uint32_t* n=FUN_004bb500(param_1); *reinterpret_cast<uint32_t*>(ecx+0x10)=(uint32_t)(uintptr_t)n; *reinterpret_cast<uint32_t*>((uint8_t*)n+0x14)=(uint32_t)(uintptr_t)ecx; return; }
  }
}

// 0x4bb500 — observed shape: factory allocating 0xc0 bytes, init vtable, copy fields from ECX source (+0x34..+0xbc), conditional physics/material setup, register via FUN_004baca0.
extern void FUN_004baaa0();
extern void FUN_004baae0(void* self, int v);
extern uint32_t* FUN_00538680();
extern void FUN_004c0680(uint32_t v);
extern uint32_t* FUN_004ba190(uint32_t v);
extern void FUN_004c2510(uint32_t a, uint32_t* b);
extern uint32_t* FUN_00510e60();
extern void FUN_00510ed0();
extern void FUN_00491640();
extern void FUN_0053b680(uint32_t v);
extern void FUN_004bf420();
extern uint32_t FUN_004c2380();
extern int FUN_005065b0();
extern void FUN_005065e0(int* p);
void* FUN_004bb500(void* self_src, uint32_t param_1) {
  uint8_t* src = static_cast<uint8_t*>(self_src);
  uint32_t* pu = static_cast<uint32_t*>(FUN_00533c78(0xc0));
  if (!pu) return nullptr;
  pu[1]=0; pu[0]=(uint32_t)(uintptr_t)&PTR_FUN_006fd14c; pu[7]=0; DAT_00727444++; pu[0x19]=0; pu[0x2f]=0;
  FUN_004baaa0(); FUN_004baae0(pu, *reinterpret_cast<int*>(src+0x18));
  uint32_t* puVar4 = FUN_00538680(); uint32_t* old = reinterpret_cast<uint32_t*>(pu[7]);
  if (old != puVar4) { if(old){ int* pi=(int*)old+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)old[0])(1);} } pu[7]=(uint32_t)(uintptr_t)puVar4; if(puVar4) puVar4[1]++; }
  if (((int8_t)param_1!=0)||((*reinterpret_cast<uint32_t*>(src+0x20)&0x20000)!=0)) FUN_004c0680(pu[7]);
  if (*reinterpret_cast<int*>(src+0x60)!=0 && *reinterpret_cast<int*>(src+0xa4)!=0) {
    uint32_t got = (*(uint32_t(*)(uint32_t))(*reinterpret_cast<uint32_t*>(pu[7])+0x40))(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(src+0x60)+0xc));
    pu[0x18]=got;
    int a=FUN_00533c78(0x10) ? 1:0; uint32_t u5=0; if(a){ FUN_004bf420(); u5=FUN_004c2380(); } pu[0x29]=u5;
    int st=FUN_005065b0(); while(st!=0){ FUN_005065e0(&st); int t=FUN_00533c78(0x30)?1:0; uint32_t* q=nullptr; if(t){ q=FUN_004ba190(pu[0x18]); if(q) q[1]++; } if(q) q[1]++; FUN_004c2510(0,q); if(q){ int* pi=(int*)q+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)q[0])(1);} } }
  }
  if (*reinterpret_cast<int*>(src+0x90)!=0) {
    int t=FUN_00533c78(0x24)?1:0; uint32_t u5=0; if(t) u5=(uint32_t)(uintptr_t)FUN_00510e60(); pu[0x24]=u5; FUN_00510ed0();
    uint32_t v70=*reinterpret_cast<uint32_t*>(src+0x70), v74=*reinterpret_cast<uint32_t*>(src+0x74); uint32_t* obj=reinterpret_cast<uint32_t*>(pu[0x24]);
    if(obj){ *reinterpret_cast<uint32_t*>((uint8_t*)obj+0x14)=*reinterpret_cast<uint32_t*>(src+0x6c); *reinterpret_cast<uint32_t*>((uint8_t*)obj+0x18)=v70; *reinterpret_cast<uint32_t*>((uint8_t*)obj+0x1c)=v74; }
    FUN_00491640();
    uint32_t* host=reinterpret_cast<uint32_t*>(pu[7]); uint32_t* slot=reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(pu[0x24])+0x154); uint32_t* cur=*slot;
    if(cur!=host){ if(cur){ int* pi=(int*)cur+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)cur[0])(1);} } *slot=(uint32_t)(uintptr_t)host; if(host) host[1]++; }
    uint32_t v20=*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(src+0x90)+0x20);
    FUN_0053b680(*reinterpret_cast<uint32_t*>(pu[0x24]+2)); FUN_00534350(); *reinterpret_cast<uint32_t*>(pu[0x24]+8)=v20;
  }
  pu[0xd]=*reinterpret_cast<uint32_t*>(src+0x34); pu[0xe]=*reinterpret_cast<uint32_t*>(src+0x38);
  *(uint8_t*)((uint8_t*)pu+0x25)=*(uint8_t*)(src+0x25); pu[0xb]=*reinterpret_cast<uint32_t*>(src+0x2c);
  uint32_t* o19=reinterpret_cast<uint32_t*>(pu[0x19]); uint32_t* n19=*reinterpret_cast<uint32_t**>(src+100);
  if(o19!=n19){ if(o19){ int* pi=(int*)o19+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)o19[0])(1);} } pu[0x19]=(uint32_t)(uintptr_t)n19; if(n19) n19[1]++; }
  pu[0x1b]=*reinterpret_cast<uint32_t*>(src+0x6c); pu[0x1c]=*reinterpret_cast<uint32_t*>(src+0x70); pu[0x1d]=*reinterpret_cast<uint32_t*>(src+0x74);
  pu[0x1e]=*reinterpret_cast<uint32_t*>(src+0x78); pu[0x1f]=*reinterpret_cast<uint32_t*>(src+0x7c); pu[0x20]=*reinterpret_cast<uint32_t*>(src+0x80);
  *(uint8_t*)((uint8_t*)pu+0x4d)=0;
  if (*reinterpret_cast<int*>(src+0xbc)==0) { uint32_t* o=reinterpret_cast<uint32_t*>(pu[0x2f]); if(o){ int* pi=(int*)o+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)o[0])(1);} pu[0x2f]=0; } }
  else { uint32_t* n=FUN_004bb500(src,param_1); uint32_t* o=reinterpret_cast<uint32_t*>(pu[0x2f]); if(o!=n){ if(o){ int* pi=(int*)o+1; *pi=*pi-1; if(*pi==0){ using F=void(*)(int); (*(F*)o[0])(1);} } pu[0x2f]=(uint32_t)(uintptr_t)n; if(n) n[1]++; } }
  pu[8] = pu[8] | (*reinterpret_cast<uint32_t*>(src+0x20) & 0x28000);
  FUN_004baca0(pu);
  return pu;
}

// 0x4bb840 — observed shape: scaled float param, optional callback via +0x8c, FUN_0051bfc0 gate, timing latch DAT_008ed61c/18, max tracker DAT_008cabf8, vtbl +0x70 dispatch.
extern uint32_t DAT_008ea010;
extern uint32_t DAT_008e9fe8;
extern uint32_t DAT_008e9ff8;
extern uint32_t DAT_00726ae4;
extern void FUN_004fd880(void* p);
extern char FUN_0051bfc0(void* p);
extern void FUN_004c0740(uint32_t a, uint32_t b, float c);
extern void FUN_00524e90(uint32_t v);
int FUN_004bb840(void* self, int param_2) {
  uint8_t* s=static_cast<uint8_t*>(self); float f=(float)param_2;
  if(((s[0x3c]&2)!=0)&&(*reinterpret_cast<int*>(s+0x8c)!=0)&&(*reinterpret_cast<int*>(s+0x18)!=(int)DAT_008ea010)){ int v=*reinterpret_cast<int*>(s+0x8c); FUN_004fd880(&v); }
  char c=FUN_0051bfc0(&param_2);
  if(c!=0){ if(s[0x25]!=0){ FUN_004c0740(*reinterpret_cast<uint32_t*>(s+0x1c),DAT_008e9fe8,f*0.01f); FUN_00534350(); } return 0; }
  if((DAT_008ed61c&1)==0){ DAT_008ed61c|=1; DAT_008ed618=timeGetTime(); }
  DWORD d=timeGetTime(); FUN_00524e90(d-DAT_008ed618);
  if((int)DAT_008cabf8<(int)DAT_00726ae4) DAT_008cabf8=DAT_00726ae4;
  { int* host=*reinterpret_cast<int**>(s+0x18); using F=void(*)(uint32_t,int); (*(F*)(host[0]+0x70))(*reinterpret_cast<uint32_t*>(s+0x1c),1); }
  if(*reinterpret_cast<int*>(s+0x18)==(int)DAT_008e9ff8) FUN_00524e90((uint32_t)(uintptr_t)s);
  if(s[0x25]!=0) FUN_004c0740(*reinterpret_cast<uint32_t*>(s+0x1c),DAT_008e9fe8,0);
  FUN_00534350(); FUN_00534130(); return 1;
}

// 0x4bb980 — observed shape: EDI receiver query via FUN_004ed8f0, vtbl+0x74 on +0x1c ref, conditional FUN_004959b0, FUN_004c0740 when +0x25 set, returns CONCAT31(...,1).
extern void FUN_004959b0();
extern uint32_t FUN_004ed8f0(void* a);
extern int FUN_004959b0_ret();
uint32_t FUN_004bb980(void* self) {
  uint8_t* edi=static_cast<uint8_t*>(self);
  uint32_t u=FUN_004ed8f0(edi);
  if((int8_t)u==0) return u;
  uint32_t* inner=*reinterpret_cast<uint32_t**>(edi+0x1c);
  uint8_t local[4]={};
  { using F=void(*)(void*); (*(F*)(*reinterpret_cast<uint32_t*>(inner[9])+0x74))(local); }
  if(inner){ int c=(int)inner[1]; inner[1]=c-1; if(c-1==0){ using F=void(*)(int); (*(F*)inner[0])(1);} }
  if(*reinterpret_cast<int*>(edi+0x8c)!=0) FUN_004959b0();
  uint32_t v=*reinterpret_cast<uint32_t*>(edi+0x18);
  if(v==DAT_008e9ff8) v=FUN_004ed8f0((void*)(intptr_t)*reinterpret_cast<int*>(edi+0x1c));
  uint32_t u3 = v>>8;
  if(edi[0x25]!=0){ FUN_004c0740(*reinterpret_cast<uint32_t*>(edi+0x1c),0,1.0f); FUN_00534350(); }
  edi[0x25]=0;
  return (u3 & 0xffffff00u) | 1u;
}

// 0x4bba20 — observed shape: sign from DAT_008cac04 selects 100.0/-100.0, unsigned-bias DAT_008cac00, increment, divide.
extern int32_t DAT_008cac00;
extern uint8_t DAT_008cac04;
double FUN_004bba20() {
  double f1 = DAT_008cac04==0 ? 100.0 : -100.0;
  double f2 = (double)(uint32_t)DAT_008cac00;
  if (DAT_008cac00<0) f2 += 4294967296.0;
  DAT_008cac00 += 1;
  return f2/f1;
}

// 0x4bba60 — observed shape: walks +0xbc chain via FUN_004bb4b0, places object via FUN_004bb840/FUN_004bba20/FUN_0042c0a0, copies 9 dwords to +0x38, sets 0x2000 flag.
extern uint32_t DAT_007263a0;
extern uint32_t DAT_0072637c;
extern uint32_t DAT_00726380;
extern void* DAT_007179b0;
extern void FUN_0042c0a0(float a, float b, float c);
extern void FUN_0053c780(double v);
extern int FUN_004baaa0();
extern int FUN_004bb4b0(void* self, int v);
extern int FUN_004bb840(void* self, int v);
int FUN_004bba60(int param_1, int param_2, int param_3, float param_4, float param_5) {
  if(param_1!=0){
    int cur=param_1;
    do{
      if(FUN_004baaa0()==0) return 0;
      int b=*reinterpret_cast<int*>((uint8_t*)cur+0xbc);
      if((b==0||DAT_007263a0>1)&&(FUN_004bb4b0(nullptr,0)==cur)){
        FUN_004bb840((void*)(intptr_t)cur,100);
        float f=(float)FUN_004bba20();
        *reinterpret_cast<float*>(*reinterpret_cast<int*>((uint8_t*)cur+0x1c)+0x68)= (param_4>=0?param_4:-param_4)*0.01f;
        FUN_0042c0a0((float)param_2-(float)(DAT_0072637c/2), -f, -((float)param_3-(float)(DAT_00726380/2)));
        uint32_t* src;
        uint32_t local[9];
        if(param_5==0.0f) src=reinterpret_cast<uint32_t*>(&DAT_007179b0);
        else { FUN_0053c780(-param_5*0.017453292); src=local; /* single-value buffer preserved */ }
        uint32_t* dst=reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>((uint8_t*)cur+0x1c)+0x38);
        for(int i=0;i<9;i++){ dst[i]=src[i]; }
        *reinterpret_cast<uint32_t*>((uint8_t*)cur+0x20) |= 0x2000;
        *reinterpret_cast<uint32_t*>((uint8_t*)cur+0x28)=0;
        *(uint8_t*)((uint8_t*)cur+0x24)=1;
        return cur;
      }
      cur=b;
    }while(cur!=0);
  }
  return 0;
}

// 0x4bbb80 — observed shape: scales ints by 1.4629181e-09 via FUN_004dadc0 then forwards to FUN_004bbc80 with centered coords.
extern void FUN_004dadc0(float a, float b, float c);
extern int FUN_004bbc80(int a,int b,int c,uint32_t* d,int e,int f,int g);
void FUN_004bbb80(uint32_t p1,int p2,int p3,int p4,uint32_t p5,uint32_t p6,uint32_t p7) {
  uint32_t local[9]={};
  FUN_004dadc0((float)p2*1.4629181e-09f,(float)p3*1.4629181e-09f,(float)p4*1.4629181e-09f);
  FUN_004bbc80(p3-(int)(DAT_0072637c/2), 0, -(p4-(int)(DAT_00726380/2)), local, (int)p5,(int)p6,(int)p7);
}

// 0x4bbc10 — observed shape: same scaling wrapper, passes raw param_2..4 through to FUN_004bbc80.
void FUN_004bbc10(uint32_t p1,uint32_t p2,uint32_t p3,uint32_t p4,int p5,int p6,int p7,uint32_t p8,uint32_t p9) {
  uint32_t local[9]={};
  FUN_004dadc0((float)p5*1.4629181e-09f,(float)p6*1.4629181e-09f,(float)p7*1.4629181e-09f);
  FUN_004bbc80((int)p2,(int)p3,(int)p4,local,(int)p8,(int)p9,0);
}

// 0x4bbc80 — observed shape: chain-walk placement; recursion guard via +0xbc/DAT_007263a0, FUN_004bb4b0 match, FUN_004bb840/FUN_004bdaa0, conditional transform update, tail to FUN_004bbe10.
extern void FUN_004bdaa0(int v);
extern char FUN_00428470(void* p);
extern char FUN_0053c450(void* p);
extern int FUN_004bbe10(int a,int b);
int FUN_004bbc80(int param_1,int param_2,int param_3,uint32_t* param_4,int param_5,int param_6,int param_7) {
  // ECX receiver is implicit; use a static thread-local stand-in via explicit param packing is not possible without inventing ABI, so preserve traversal via FUN_004baaa0/RTTI-free self from listing is represented by iterating from FUN_004bb4b0.
  int self = 0;
  while(true){
    int cur = self;
    if(cur==0||FUN_004baaa0()==0) return 0;
    int chain = *reinterpret_cast<int*>((uint8_t*)cur+0xbc);
    if(chain!=0){
      if(DAT_007263a0<2) continue;
      uint32_t saved=*reinterpret_cast<uint32_t*>((uint8_t*)chain+0x18);
      *reinterpret_cast<uint32_t*>((uint8_t*)chain+0x18)=DAT_008ea010;
      FUN_004bbc80(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>((uint8_t*)cur+0xbc)+0x18)=saved;
    }
    if(FUN_004bb4b0(nullptr,0)!=cur) continue;
    FUN_004bb840((void*)(intptr_t)cur,param_5);
    FUN_004bdaa0(cur);
    float lc=(float)param_1, l8=(float)param_2, l4=(float)param_3;
    bool need = (*reinterpret_cast<int*>((uint8_t*)cur+0x30)!=param_6)||(*reinterpret_cast<float*>((uint8_t*)cur+0x28)!=(float)param_7*0.001f)||(*reinterpret_cast<float*>(*reinterpret_cast<int*>((uint8_t*)cur+0x1c)+0x68)!=(float)param_5*0.01f);
    char c2 = FUN_00428470(&lc);
    if(need || c2!=0 || FUN_0053c450(param_4)==0){
      *reinterpret_cast<float*>(*reinterpret_cast<int*>((uint8_t*)cur+0x1c)+0x68)= ((float)param_5>=0?(float)param_5:-(float)param_5)*0.01f;
      uint32_t* dst=reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>((uint8_t*)cur+0x1c)+0x38);
      for(int i=0;i<9;i++) dst[i]=param_4[i];
      int inner=*reinterpret_cast<int*>((uint8_t*)cur+0x1c);
      *reinterpret_cast<float*>(inner+0x5c)=lc; *reinterpret_cast<float*>(inner+0x60)=l8; *reinterpret_cast<float*>(inner+100)=l4;
      *reinterpret_cast<float*>((uint8_t*)cur+0x28)=(float)param_7*0.001f;
      *reinterpret_cast<int*>((uint8_t*)cur+0x30)=param_6;
      *reinterpret_cast<uint32_t*>((uint8_t*)cur+0x20)|=0x2000;
    }
    *(uint8_t*)((uint8_t*)cur+0x24)=1;
    if(param_6<0) return cur;
    return FUN_004bbe10(param_6,param_7);
  }
}

// 0x4bbe10 — observed shape: ECX receiver recursion while +0xbc && DAT_007263a0<2, fetch via FUN_004bc0d0, fmod guard, FUN_004ba450, set 0x2000 flag.
extern int FUN_004bc0d0();
extern void FUN_004ba450(float v);
extern double _CIfmod();
void FUN_004bbe10(void* self, uint32_t param_1, float param_2) {
  uint8_t* ecx=static_cast<uint8_t*>(self);
  if(*reinterpret_cast<int*>(ecx+0xbc)!=0 && DAT_007263a0<2) FUN_004bbe10(*reinterpret_cast<void**>(ecx+0xbc), param_1, param_2);
  int v=FUN_004bc0d0();
  if(v!=0){
    param_2 = (float)(int)param_2 * 0.001f;
    if(*reinterpret_cast<float*>(v+0xc)!=0.0f) param_2=(float)_CIfmod();
    FUN_004ba450(param_2);
    *reinterpret_cast<uint32_t*>(ecx+0x20)|=0x2000;
  }
}

// 0x4bbea0 — observed shape: scale param_1 by 0.001, fmod guard on FUN_004bc0d0 result +0xc, FUN_004ba4f0 with param_2*0.01.
extern void FUN_004ba4f0(int a,float b,float c);
void FUN_004bbea0(float param_1, int param_2) {
  int v=FUN_004bc0d0();
  if(v!=0){
    param_1=(float)(int)param_1*0.001f;
    if(*reinterpret_cast<float*>(v+0xc)!=0.0f) param_1=(float)_CIfmod();
    FUN_004ba4f0(v,param_1,(float)param_2*0.01f);
  }
}

// 0x4bbf10 — observed shape: EDI array at +4 count +0xc, per-element vtbl+0x48 call with (param_1,1).
void FUN_004bbf10(void* self, uint32_t param_1) {
  uint8_t* edi=static_cast<uint8_t*>(self);
  if(edi && *reinterpret_cast<int*>(edi+0xc)!=0){
    uint32_t n=*reinterpret_cast<uint32_t*>(edi+0xc);
    for(uint32_t i=0;i<n;i++){
      int e=*reinterpret_cast<int*>(*reinterpret_cast<int*>(edi+4)+i*4);
      if(e){ int v=*reinterpret_cast<int*>(e+8); using F=void(*)(uint32_t,int); (*(F*)(v+0x48))(param_1,1); }
    }
  }
}

// 0x4bbf50 — observed shape: EAX receiver; walk +0xbc chain, fmod +0x2c→+0x28, 0x2000-flag dispatch on +0x1c vtbl +0x48/+0x4c plus FUN_004bbf10, joint positioning via FUN_004bd700, update +0x90 block.
extern void FUN_004bd7a0(uint32_t v);
extern void FUN_004bd700(void* a,float b,float c,float d);
extern void FUN_00491640();
extern void FUN_00511610();
void FUN_004bbf50(void* self) {
  uint8_t* eax=static_cast<uint8_t*>(self);
  int cur=*reinterpret_cast<int*>(eax+0xbc);
  while(cur!=0 && DAT_007263a0<2){ eax+=0xbc; cur=*reinterpret_cast<int*>(eax+0xbc); }
  // restore base pointer traversal note: eax now points at tail; re-read offsets relative to tail node
  if(*reinterpret_cast<float*>(eax+0x2c)>0.0f) *reinterpret_cast<float*>(eax+0x28)=(float)_CIfmod();
  if((*reinterpret_cast<uint32_t*>(eax+0x20)&0x2000)!=0){
    if(((int8_t)(*reinterpret_cast<uint32_t*>(eax+0x20)>>8))<0){ int h=*reinterpret_cast<int**>(eax+0x1c); using F=void(*)(); (*(F*)(h[0]+0x48))(); }
    else { int h=*reinterpret_cast<int**>(eax+0x1c); using F=void(*)(uint32_t,int); (*(F*)(h[0]+0x4c))(*reinterpret_cast<uint32_t*>(eax+0x28),1); FUN_004bbf10(eax,*reinterpret_cast<uint32_t*>(eax+0x28)); }
    *reinterpret_cast<uint32_t*>(eax+0x20)&=0xffffdfffu;
  }
  if(FUN_00428470(&DAT_00727430)==0) FUN_004bd7a0(0x3e19999au);
  else {
    int h=*reinterpret_cast<int**>(eax+0x1c); using F=int(*)(const char*); int j=(*(F*)(h[0]+0x40))("Bip01 Pelvis");
    int joint = j? j : h;
    FUN_004bd700(eax, *reinterpret_cast<float*>(joint+0x90)-*reinterpret_cast<float*>(eax+0x78), *reinterpret_cast<float*>(joint+0x94)-*reinterpret_cast<float*>(eax+0x7c), *reinterpret_cast<float*>(joint+0x98)-*reinterpret_cast<float*>(eax+0x80));
  }
  int blk=*reinterpret_cast<int*>(eax+0x90);
  if(blk!=0){
    *reinterpret_cast<uint32_t*>(blk+0x14)=*reinterpret_cast<uint32_t*>(eax+0x6c);
    *reinterpret_cast<uint32_t*>(blk+0x18)=*reinterpret_cast<uint32_t*>(eax+0x70);
    *reinterpret_cast<uint32_t*>(blk+0x1c)=*reinterpret_cast<uint32_t*>(eax+0x74);
    FUN_00491640(); FUN_00511610();
  }
}
