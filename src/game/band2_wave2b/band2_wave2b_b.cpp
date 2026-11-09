// Band2 wave2b batch B — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// cl 13.10.3077 absent; nothing byte-matched.
#include <windows.h>
#include <string.h>

namespace band2_wave2b_b {

// 0x004c42e0 — dual name-table lookup (param_1=this, param_2=out, param_3=name, RET plain)
// Observed: clear gLock if len!=0; scan [this+0x60]/[this+0x68] with _stricmp(param_3,entry) into gLock;
// FUN_004ccfd0(&tmp,0x25) copy into param_3; second scan restores gLock; *param_2=&gLock; release param_3.
extern char gLock_8cacd0; extern int gStrLen_8caccc;
extern void FUN_004ccfd0(void*, int);
inline void* FUN_004c42e0(int param_1, void** param_2, char* param_3) {
    char* t = (char*)(long long)param_1;
    if (gStrLen_8caccc != 0) { gLock_8cacd0 = 0; gStrLen_8caccc = 0; }
    unsigned n = *(unsigned*)(t + 0x68);
    for (unsigned i = 0; i < n; ++i) {
        if (_stricmp(param_3, *(char**)(*(size_t*)(t + 0x60) + i*4)) == 0) break;
    }
    FUN_004ccfd0(&param_3, 0x25);
    *param_2 = &gLock_8cacd0;
    return param_2;
}

// 0x004c4560 — name-table lookup into out-string (thiscall-ish, param_1=this, param_2=name, RET plain)
// Observed: loop i over [this+0x68] entries at [this+0x60]*4 calling _stricmp(entry,param_2);
// on match copy matched entry into *out (FUN_004f3350+memmove, FUN_00412f90 if empty);
// else clear out if gStrLen!=0; release param_2 via operator_delete__.
extern void FUN_004f3350(void); extern void FUN_00412f90(void);
extern void operator_delete__(void*);
inline void FUN_004c4560(unsigned param_1, char* param_2, char** out) {
    unsigned n = *(unsigned*)((char*)(long long)param_1 + 0x68);
    for (unsigned i = 0; i < n; ++i) {
        char** tbl = *(char***)(*(size_t*)((char*)(long long)param_1 + 0x60));
        if (_stricmp(tbl[i], param_2) == 0) {
            char* src = tbl[i]; size_t sz = *(size_t*)(src - 4);
            *out = &gLock_8cacd0;
            if (sz && src && src != *out) { FUN_004f3350(); memmove(*out, src, sz); (*out)[sz] = 0; }
            break;
        }
    }
    void* p = param_2 - 8;
    if ((p != 0) && (p != (void*)0x8cacc8)) operator_delete__(p);
}

// 0x004c4640 — nav-button dispatch (RET plain)
// Observed: i=FUN_00506440(); j=[gVal+8]; mapping (7||j==code) -> label+accent:
// 0x11 Home 0x140; 0xf Back 0x10e; 0x10 Forward 0x172; 0x12 Previous 0x46; 0x13 Next 0x23a;
// then FUN_004f6090(label); FUN_00412f10(); g_85a11c=0x37; g_8c9de0=g_8c9dd8;
// FUN_00509500(...); clamp accent by 0x2a/0x256; FUN_004b06c0(&g_869b48,...).
extern int FUN_00506440(void); extern int FUN_005f0ddc(void);
extern void FUN_004f6090(const char*); extern void FUN_00412f10(void);
extern void FUN_00509500(void*, void*, int);
extern void FUN_004b06c0(void*, int, int, int, int, int, int, int);
extern int gVal_8cabe8; extern int g_85a11c; extern void* g_8c9dd8; extern void* g_8c9de0;
extern char g_869b48; extern char gLock_8cacd0;
inline void FUN_004c4640(void) {
    int i = FUN_00506440();
    int j = *(int*)(gVal_8cabe8 + 8);
    const char* label = 0; int accent = 0;
    if ((i == 7) || (j == 0x11)) { accent = 0x140; FUN_005f0ddc(); label = "Home"; }
    else if ((i == 7) || (j == 0xf)) { accent = 0x10e; FUN_005f0ddc(); label = "Back"; }
    else if ((i == 7) || (j == 0x10)) { accent = 0x172; FUN_005f0ddc(); label = "Forward"; }
    else if ((i == 7) || (j == 0x12)) { accent = 0x46; FUN_005f0ddc(); label = "Previous"; }
    else if ((i == 7) || (j == 0x13)) { accent = 0x23a; FUN_005f0ddc(); label = "Next"; }
    else return;
    FUN_004f6090(label); FUN_00412f10();
    g_85a11c = 0x37; g_8c9de0 = g_8c9dd8;
    FUN_00509500(g_8c9dd8, &gLock_8cacd0, 0); FUN_005f0ddc();
    int w = FUN_005f0ddc();
    if (accent - w < 0x2a) accent = w + 0x2a;
    else if (0x256 < w + accent) accent = 0x256 - w;
    g_85a11c = 0x37;
    FUN_004b06c0(&g_869b48, accent, ((int)(0x26c/(int)w)/2)*w + 0x6c, 0x37, -1, 4, -1, 0);
}

// 0x004c4860 — selection flag setter A (EAX=0/1, ECX=this, RET plain)
// Observed: EAX==1 -> FUN_00412df0(); gate FUN_004c58c0(this)!=0; FUN_004c4aa0(this,&tmp);
// release tmp; if gStrLen!=0 { FUN_00412ec0(); [this+0xdc4]=0; [this+0x7c]=1; }
// EAX==0 -> FUN_004c4aa0 path with [this+0xda4]=0; [this+0x7c]=0; tail FUN_004888e0(0x2d,-1,-1,0xbf800000).
extern void FUN_00412df0(void); extern void FUN_00412ec0(void);
extern void FUN_004888e0(int,int,int,float);
extern int FUN_004c58c0(void*);
extern void FUN_004c4aa0(void*, void*);
inline void FUN_004c4860(int sel, void* pThis) {
    char* t = (char*)pThis;
    if (sel == 1) {
        FUN_00412df0();
        if (FUN_004c58c0(pThis) == 0) return;
        void* tmp = 0; FUN_004c4aa0(pThis, &tmp);
        void* p = (char*)tmp - 8;
        if ((p != 0) && (p != (void*)0x8cacc8)) operator_delete__(p);
    } else if (sel == 0) {
        void* tmp = 0; FUN_004c4aa0(pThis, &tmp);
        void* p = (char*)tmp - 8;
        if ((p != 0) && (p != (void*)0x8cacc8)) operator_delete__(p);
    }
    FUN_004888e0(0x2d, -1, -1, -1.0f);
}

// 0x004c4980 — selection flag setter B (EAX=0/1, ECX=this, RET plain; variant calling 0x4c5030)
// Observed: identical shape to 0x4c4860 except FUN_004c5030 substituted for FUN_004c4aa0 on both branches.
extern void FUN_004c5030(void*, void*);
inline void FUN_004c4980(int sel, void* pThis) {
    if (sel == 1) {
        FUN_00412df0();
        if (FUN_004c58c0(pThis) == 0) return;
        void* tmp = 0; FUN_004c5030(pThis, &tmp);
        void* p = (char*)tmp - 8;
        if ((p != 0) && (p != (void*)0x8cacc8)) operator_delete__(p);
    } else if (sel == 0) {
        void* tmp = 0; FUN_004c5030(pThis, &tmp);
        void* p = (char*)tmp - 8;
        if ((p != 0) && (p != (void*)0x8cacc8)) operator_delete__(p);
    }
    FUN_004888e0(0x2d, -1, -1, -1.0f);
}

} // namespace band2_wave2b_b
