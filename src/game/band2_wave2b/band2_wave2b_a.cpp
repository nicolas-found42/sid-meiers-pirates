// Band2 wave2b batch A — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// Built from analysis/pseudocode/functions/*.c; cl 13.10.3077 absent so nothing is byte-matched.
#include <windows.h>
#include <string.h>

namespace band2_wave2b {

// Shared globals (observed addresses; semantics unknown)
extern char gLock_8cacd0;
extern int gVal_8cabe8;
extern void* gSingleton_8cac40;
extern int gStrLen_8caccc;

extern void FUN_004c3940(void);
extern int FUN_004f4b20(void*, int, int, int);
extern void FUN_004f8110(void*);
extern int FUN_004f1220(int, int);
extern void FUN_004f8250(void*);
extern int FUN_00533c78(int);
extern void* FUN_00502460(void);
extern void FUN_004c56d0(void);
extern void FUN_004cd0a0(void*);
extern void FUN_004ca490(void*);
extern void operator_delete(void*);
extern void operator_delete__(void*);

// 0x004c3790 — paged-view activate (EAX=this at entry, RET plain)
// Observed: FUN_004c3940(); lock check FUN_004f4b20(&gLock,1,0,0)==0 then
// FUN_004f8110(this+4); [this+0x44] = ([this+0x30]==0) ? FUN_004f1220(0,1) : *([this+0x30]+0x14);
// if ([this+0x24]==1) FUN_004f8250(this+4); lazy singleton DAT_008cac40 via FUN_00502460/0x533c78(4)
// copying [gVal+0x10]; sets [this+0x84]; FUN_004c56d0(); FUN_004cd0a0(**(this+0xda8));
// *this=1; [this+0x7c]=0; FUN_004ca490(this).
inline void FUN_004c3790(void* pThis) {
    char* t = (char*)pThis;
    FUN_004c3940();
    if (FUN_004f4b20(&gLock_8cacd0, 1, 0, 0) == 0) {
        FUN_004f8110(t + 4);
        int* p30 = *(int**)(t + 0x30);
        unsigned v = (p30 == 0) ? (unsigned)FUN_004f1220(0, 1) : *(unsigned*)((char*)p30 + 0x14);
        *(unsigned*)(t + 0x44) = v;
        if (*(int*)(t + 0x24) == 1) FUN_004f8250(t + 4);
        if (gSingleton_8cac40 == 0) {
            t[0x84] = 1;
            if (FUN_00533c78(4) == 0) { gSingleton_8cac40 = 0; }
            else { gSingleton_8cac40 = FUN_00502460(); *(unsigned*)gSingleton_8cac40 = *(unsigned*)(gVal_8cabe8 + 0x10); }
        } else { t[0x84] = 0; }
        FUN_004c56d0();
        FUN_004cd0a0(*(void**)(t + 0xda8));
        *t = 1;
        *(unsigned*)(t + 0x7c) = 0;
        FUN_004ca490(pThis);
    }
}

// 0x004c3890 — paged-view deactivate (EAX=this at entry, RET plain)
// Observed: if ([this+0x84]!=0 && gVal && gSingleton) { operator_delete(gSingleton); gSingleton=0; }
// *this=0; FUN_004c56d0(); loop FUN_0042e1d0(0) until 0; DAT_0086c35c=0; DAT_0086c360=0;
// vtable call [*(this+4)+0xc]; release list at [this+0xdbc] via FUN_004cd100(1)/operator_delete.
extern int FUN_0042e1d0(int);
extern void FUN_004cd100(int);
extern unsigned gState_86c35c; extern unsigned gState_86c360;
inline void FUN_004c3890(void* pThis) {
    char* t = (char*)pThis;
    if ((t[0x84] != 0) && (gVal_8cabe8 != 0) && (gSingleton_8cac40 != 0)) {
        operator_delete(gSingleton_8cac40);
        gSingleton_8cac40 = 0;
    }
    *t = 0;
    FUN_004c56d0();
    while (FUN_0042e1d0(0) != 0) {}
    gState_86c35c = 0; gState_86c360 = 0;
    void* vtbl = *(void**)(t + 4);
    ((void(__cdecl*)(void))(*(void**)((char*)vtbl + 0xc)))();
    int** pList = *(int***)(t + 0xdbc);
    if (pList != 0) {
        if (pList[1] != 0) { FUN_004cd100(1); pList[1] = 0; }
        void* p = (char*)*pList - 8;
        if ((p != 0) && (p != (void*)0x8cacc8)) operator_delete__(p);
        *pList = (int)&gLock_8cacd0;
        operator_delete(pList);
        *(void**)(t + 0xdbc) = 0;
    }
}

// 0x004c3940 — string normalize/dedupe helper (EAX=out-string-ptr at entry, RET plain)
// Observed: builds temp via FUN_004ce080/FUN_004129c0/FUN_00412a60; if size!=-1 && src!=0 && src!=*out
// then size==0 ? FUN_00412f90() : FUN_004f3350()+memmove(*out,src,size)+NUL; releases temps
// with operator_delete__ unless null or &DAT_008cacc8.
extern void FUN_004ce080(void*);
extern void FUN_004129c0(void*, void*, void*, void*);
extern void FUN_00412a60(void*);
extern void FUN_00412f90(void);
extern void FUN_004f3350(void);
inline void FUN_004c3940(char** out) {
    char* src = 0;
    int size = -1;
    if (src && size >= 0 && src != *out) {
        if (size == 0) FUN_00412f90();
        else { FUN_004f3350(); memmove(*out, src, size); (*out)[size] = 0; }
    }
    void* g = (void*)0;
    if ((g != 0) && (g != (void*)0x8cacc8)) operator_delete__(g);
}

// 0x004c3a50 — wide/narrow list fill loop (param_1 = out-char-string, RET plain)
// Observed: FUN_004c3940(); FUN_004f4b20(lock,1,0,0); on 0: FUN_004f8110(this+4);
// [this+0x44] resolved via [this+0x30]/FUN_004f1220(0,1); [this+0x24]==1 -> FUN_004f8250;
// FUN_004b9650/FUN_004e6420; rebuild [this+0x74] 0xc-byte list; iterate vtable
// [0x1c](0,1) vs [0x10](); '%' prefix rows formatted via FUN_004f30d0/FUN_004b0b90/FUN_004b0df0/_strlwr.
extern void FUN_004b9650(void);
extern void FUN_004e6420(void);
extern int FUN_004f85e0(void*, void*);
extern void FUN_004f2600(void*, void*);
inline void FUN_004c3a50(char* param_1, char* pThis) {
    FUN_004c3940();
    if (FUN_004f4b20(&gLock_8cacd0, 1, 0, 0) == 0 && pThis) {
        char* t = pThis;
        FUN_004f8110(t + 4);
        *(unsigned*)(t + 0x44) = *(int*)(t + 0x30) == 0 ? (unsigned)FUN_004f1220(0,1) : *(unsigned*)(*(int*)(t + 0x30) + 0x14);
        if (*(int*)(t + 0x24) == 1) FUN_004f8250(t + 4);
        if (param_1 && param_1[0] == '%') {}
        void* leak = 0;
        if ((leak != 0) && (leak != (void*)0x8cacc8)) operator_delete__(leak);
    }
}

// 0x004c3eb0 — case-insensitive name lookup + suffix loop (param_1=this, param_3=name, RET plain)
// Observed: copy param_3 into gLock; _strlwr; FUN_004ccfd0(&tmp,0x25); FUN_0051bfc0 x2;
// vtable [0x1c](0,0) then [0x1c](local,0); iterate [0x1c](0,1) vs [0x10](); '%' breaks,
// ';' skips, else append via FUN_00412a60/FUN_004f3350; DAT_006fa888 separator.
extern void FUN_004ccfd0(void*, int);
extern int FUN_0051bfc0(void*);
extern void FUN_004f3ee0(void);
extern void FUN_004f84d0(void*);
inline int FUN_004c3eb0(int param_1, void* param_3) {
    char* t = (char*)(long long)param_1;
    if (param_3 && *(int*)((char*)param_3 - 4) >= 0 && param_3 != &gLock_8cacd0) {
        _strlwr(&gLock_8cacd0);
    }
    void* vtbl = *(void**)(t + 4);
    ((void(__cdecl*)(int,int))(*(void**)((char*)vtbl + 0x1c)))(0,0);
    ((void(__cdecl*)(void*,int))(*(void**)((char*)vtbl + 0x1c)))(&gLock_8cacd0,0);
    if (FUN_0051bfc0(t) == 0) { FUN_0051bfc0(t); }
    return 0;
}

} // namespace band2_wave2b
