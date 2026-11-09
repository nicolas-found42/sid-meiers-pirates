// Band2 wave2b batch D — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// cl 13.10.3077 absent; nothing byte-matched.
#include <windows.h>
#include <string.h>

namespace band2_wave2b_d {

// 0x004c58c0 — trailing-'%' reject predicate (param_1=str, RET plain)
// Observed: if ([param_1-4]<1 || last char=='%') { release; return 0; } release; return 1.
extern void operator_delete__(void*);
inline int FUN_004c58c0(char* param_1) {
    int ok = 0;
    if ((*(int*)(param_1 - 4) < 1) || (param_1[*(int*)(param_1 - 4) - 1] == '%')) ok = 0;
    else ok = 1;
    void* p = param_1 - 8;
    if ((p != 0) && (p != (void*)0x8cacc8)) operator_delete__(p);
    return ok;
}

// 0x004c5910 — history next (ECX=this, RET plain)
// Observed: if ([this+0x6d0]!=[this+0x6d8]) { [this+0x6dc]=1; [this+0x6e0]=0;
// [this+0x6d0]=([this+0x6d0]+1)%200; FUN_004888e0(0x2d,-1,-1,0xbf800000); }
extern void FUN_004888e0(int,int,int,float);
inline void FUN_004c5910(void* pThis) {
    char* t = (char*)pThis;
    if (*(int*)(t + 0x6d0) != *(int*)(t + 0x6d8)) {
        *(int*)(t + 0x6dc) = 1; t[0x6e0] = 0;
        *(int*)(t + 0x6d0) = (*(int*)(t + 0x6d0) + 1) % 200;
        FUN_004888e0(0x2d, -1, -1, -1.0f);
    }
}

// 0x004c5960 — history prev (ECX=this, RET plain)
// Observed: if ([this+0x6d0]!=[this+0x6d4]) { [this+0x6dc]=0; [this+0x6e0]=0;
// [this+0x6d0]=([this+0x6d0]+199)%200; FUN_004888e0(0x2d,-1,-1,0xbf800000); }
inline void FUN_004c5960(void* pThis) {
    char* t = (char*)pThis;
    if (*(int*)(t + 0x6d0) != *(int*)(t + 0x6d4)) {
        *(int*)(t + 0x6dc) = 0; t[0x6e0] = 0;
        *(int*)(t + 0x6d0) = (*(int*)(t + 0x6d0) + 199) % 200;
        FUN_004888e0(0x2d, -1, -1, -1.0f);
    }
}

// 0x004c59b0 — idle-spin notify A (EAX=count, ESI=this, RET plain)
// Observed: if (count>0 && [this+0xd30]!=0): i=FUN_00503840(); loop FUN_00503780() count times;
// j=FUN_005f0ddc(); if (i!=j) FUN_004889c0(&DAT_008c8278,0x36,-1,-1,-1,0xbf800000,-1).
extern int FUN_00503840(void); extern void FUN_00503780(void);
extern int FUN_005f0ddc(void);
extern void FUN_004889c0(void*, int, int, int, int, float, int);
extern char DAT_008c8278;
inline void FUN_004c59b0(int count, void* pThis) {
    char* t = (char*)pThis;
    if ((count > 0) && (*(int*)(t + 0xd30) != 0)) {
        int i = FUN_00503840();
        while (count != 0) { FUN_00503780(); --count; }
        int j = FUN_005f0ddc();
        if (i != j) FUN_004889c0(&DAT_008c8278, 0x36, -1, -1, -1, -1.0f, -1);
    }
}

// 0x004c5a60 — idle-spin notify B (EAX=count, ESI=this, RET plain; calls FUN_005037e0)
// Observed: same shape as 0x4c59b0 except inner call FUN_005037e0.
extern void FUN_005037e0(void);
inline void FUN_004c5a60(int count, void* pThis) {
    char* t = (char*)pThis;
    if ((count > 0) && (*(int*)(t + 0xd30) != 0)) {
        int i = FUN_00503840();
        while (count != 0) { FUN_005037e0(); --count; }
        int j = FUN_005f0ddc();
        if (i != j) FUN_004889c0(&DAT_008c8278, 0x36, -1, -1, -1, -1.0f, -1);
    }
}

} // namespace band2_wave2b_d
