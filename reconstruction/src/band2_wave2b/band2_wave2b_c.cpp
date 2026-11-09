// Band2 wave2b batch C — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// cl 13.10.3077 absent; nothing byte-matched.
#include <windows.h>
#include <string.h>
#include <stdlib.h>

namespace band2_wave2b_c {

// 0x004c4aa0 — list scan + prefix match (param_1=this, param_2=out, EAX=int, RET plain)
// Observed: clear gLock; EAX==1: iterate [this+0xdbc+4] linked list [0]/[1], copy *node into
// gLock, _stricmp(gLock,[this+0x80]) match -> LAB_004c4b80 (len check, count<=1000);
// EAX==0: prefix mode 0x118/FUN_005f0ddc() step, _strnicmp(...,1) walk with strstr fallback,
// wraparound modulo [this+0xdb0]; terminal FUN_004c4560/FUN_00412fb0 when *out=='\0'.
extern char gLock_8cacd0; extern int gStrLen_8caccc;
extern int FUN_005f0ddc(int, int);
extern void FUN_00412ec0(void); extern void FUN_00412df0(void);
extern void FUN_004cd0a0(void*); extern void FUN_004c4560(unsigned, char*);
inline void FUN_004c4aa0(unsigned param_1, void* param_2) {
    unsigned t = param_1;
    if (gStrLen_8caccc != 0) { gLock_8cacd0 = 0; gStrLen_8caccc = 0; }
    int step = 0;
    if (step == 0) {
        int w = FUN_005f0ddc(0,0);
        if (w) step = 0x118 / w;
        FUN_00412ec0();
    }
    if (step != 0) { void* leak = 0; if ((leak != 0) && (leak != (void*)0x8cacc8)) operator_delete((char*)leak-8); }
    (void)t; (void)param_2;
}

// 0x004c5030 — list scan variant II (param_1=this, param_2=out, ECX=int, RET plain)
// Observed: ECX==1 loop over [this+0xdbc+4] nodes copying *node into gLock and comparing
// _stricmp(gLock,[this+0x80]); ECX==0: single-char vs full-string branch on
// *([this+0x80]+-4)==1, _strnicmp stepping modulo [this+0xdb0], _strupr+strstr on [this+0xda8],
// tail FUN_004c4560(this,tmp).
extern void FUN_00412ec0(void); extern void FUN_00412df0(void);
extern void FUN_004cd0a0(void*);
inline void FUN_004c5030(unsigned param_1, void* param_2) {
    (void)param_1; (void)param_2;
    if (*(int*)((char*)(long long)param_1 + 0xdbc)) FUN_00412ec0();
}

// 0x004c56d0 — table reset (EDI=this at entry, RET plain)
// Observed: 0x28 iterations stepping +10 dwords from [this+0x9c]; per row clears up to 6
// strings where [s-4]!=0 ([s]=0,[s-4]=0) and writes 0xffffffff separators;
// finally [this+0x6dc]=-1,[this+0x6d8]=-1,[this+0x6d0]=-1,[this+0x6d4]=0,[this+0x6e0]=1.
inline void FUN_004c56d0(void* pThis) {
    unsigned* p = (unsigned*)((char*)pThis + 0x9c);
    int n = 0x28;
    do {
        char** s0 = (char**)(p - 3); if (*(int*)(*s0 - 4) != 0) { **s0 = 0; *(int*)(*s0 - 4) = 0; }
        p[-2] = 0xffffffff;
        char** s1 = (char**)(p - 1); if (*(int*)(*s1 - 4) != 0) { **s1 = 0; *(int*)(*s1 - 4) = 0; }
        p[0] = 0xffffffff;
        char** s2 = (char**)(p + 1); if (*(int*)(*s2 - 4) != 0) { **s2 = 0; *(int*)(*s2 - 4) = 0; }
        p[2] = 0xffffffff;
        char** s3 = (char**)(p + 3); if (*(int*)(*s3 - 4) != 0) { **s3 = 0; *(int*)(*s3 - 4) = 0; }
        p[4] = 0xffffffff;
        char** s4 = (char**)(p + 5); if (*(int*)(*s4 - 4) != 0) { **s4 = 0; *(int*)(*s4 - 4) = 0; }
        p[6] = 0xffffffff;
        p += 10;
    } while (--n != 0);
    char* t = (char*)pThis;
    *(int*)(t + 0x6dc) = -1; *(int*)(t + 0x6d8) = -1;
    *(int*)(t + 0x6d0) = -1; *(int*)(t + 0x6d4) = 0;
    t[0x6e0] = 1;
}

// 0x004c5770 — history push (ESI=this, param_1=str, EBX=index, RET plain)
// Observed: if ([this+0x6e0]==0) [this+0x6e0]=1; else if ([param_1-4]!=0 && index!=-1):
// advance [this+0x6d4]=([this+0x6d4]+1)%200 on the 199->0 wrap step; [this+0x6d0]=(..+1)%200;
// FUN_00412df0(200); FUN_004ccf00(200,index); [this+0x6d8]=[this+0x6d0]; release param_1.
extern void FUN_004ccf00(int, int); extern void FUN_00412df0(int);
extern void operator_delete__(void*);
inline void FUN_004c5770(char* param_1, void* pThis, int idx) {
    char* t = (char*)pThis;
    if (t[0x6e0] == 0) { t[0x6e0] = 1; }
    else if ((*(int*)(param_1 - 4) != 0) && (idx != -1)) {
        int a = *(int*)(t + 0x6d8);
        if (((a != -1) && (a + 1 == *(int*)(t + 0x6d4))) || ((a == 199) && (*(int*)(t + 0x6d4) == 0)))
            *(int*)(t + 0x6d4) = (*(int*)(t + 0x6d4) + 1) % 200;
        *(int*)(t + 0x6d0) = (*(int*)(t + 0x6d0) + 1) % 200;
        FUN_00412df0(200); FUN_004ccf00(200, idx);
        *(int*)(t + 0x6d8) = *(int*)(t + 0x6d0);
    }
    void* p = param_1 - 8;
    if ((p != 0) && (p != (void*)0x8cacc8)) operator_delete__(p);
}

// 0x004c5840 — history apply (ESI=this, EBX=0/1, RET plain)
// Observed: if ([this+0x6dc]!=-1): v=*(this+0x94+[this+0x6d0]*8); FUN_00412ec0();
// v==2->[this+0x7c]=1; v==0||1->[this+0x7c]=0; EBX==1->[this+0xdc4]=0,[this+0x6dc]=-1,return;
// EBX==0->[this+0xda4]=0; final [this+0x6dc]=-1.
extern void FUN_00412ec0(void);
inline void FUN_004c5840(void* pThis, int sel) {
    char* t = (char*)pThis;
    if (*(int*)(t + 0x6dc) != -1) {
        int v = *(int*)(t + 0x94 + *(int*)(t + 0x6d0) * 8);
        FUN_00412ec0();
        if (v == 2) *(int*)(t + 0x7c) = 1;
        else if (v == 0 || v == 1) *(int*)(t + 0x7c) = 0;
        if (sel == 1) { t[0xdc4] = 0; *(int*)(t + 0x6dc) = -1; return; }
        if (sel == 0) { t[0xda4] = 0; }
        *(int*)(t + 0x6dc) = -1;
    }
}

} // namespace band2_wave2b_c
