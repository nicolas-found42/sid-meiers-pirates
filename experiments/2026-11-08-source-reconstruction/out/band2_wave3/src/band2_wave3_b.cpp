// Band2 wave3 batch B — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// cl 13.10.3077 absent; nothing byte-matched.
#include <windows.h>
#include <string.h>
#include <math.h>

namespace band2_wave3 {

extern unsigned char FUN_004f4ed0(void);
extern void FUN_005002f0(void);
extern int FUN_005f0ddc(void);
extern void FUN_0050c550(int);
extern int FUN_0050b150(int*);
extern int* DAT_00727c30;
extern int* DAT_00727b28;
extern int DAT_008ea08c;
extern int DAT_008cade0;
extern int DAT_008cade4;
extern int DAT_008cade8;
extern int DAT_008cad0c;
extern int DAT_00727b28_dummy;
extern void operator_delete(void*);

// 0x004e2490 — float floor wrapper (1 stack arg, RET plain)
// Observed: d = floor((double)param_1); return (float)d.
inline float FUN_004e2490(float param_1) {
    double d = floor((double)param_1);
    return (float)d;
}

// 0x004fca80 — inverted boolean predicate (no stack entry, RET plain)
// Observed: return FUN_004f4ed0() == 0.
inline bool FUN_004fca80(void) {
    return FUN_004f4ed0() == 0;
}

// 0x004ffe50 — lazy one-time init (no stack entry, RET plain)
// Observed: if (DAT_008cad0c == 0) DAT_008cad0c = FUN_00533c78(1).
extern int FUN_00533c78(int);
inline void FUN_004ffe50(void) {
    if (DAT_008cad0c == 0) {
        DAT_008cad0c = FUN_00533c78(1);
    }
}

// 0x005002d0 — singleton field getter (no stack entry, RET plain)
// Observed: if (DAT_008ea08c == 0) return 0;
// return *(DAT_00727c30 + 0x60).
inline unsigned FUN_005002d0(void) {
    if (DAT_008ea08c == 0) return 0;
    return *(unsigned*)(DAT_00727c30 + 0x60);
}

// 0x00508340 — vtable-indirect dispatch (no stack entry, RET plain)
// Observed: uRam00000064 = (**(code**)(*DAT_00727b28 + 4))(2).
typedef void (__stdcall *Thunk)(int);
inline void FUN_00508340(void) {
    void* vtable = (void*)(*(int*)(DAT_00727b28) + 4);
    ((Thunk)vtable)(2);
}

// 0x00506a80 — clear field then delete (1 stack arg, RET plain)
// Observed: *(param_1 + 8) = 0; operator_delete(param_1).
inline void FUN_00506a80(void* param_1) {
    *(unsigned*)((char*)param_1 + 8) = 0;
    operator_delete(param_1);
}

// 0x0050b070 — short equality predicate (2 stack args, RET plain)
// Observed: return param_1 == param_2 (32-bit compare of short args).
inline bool FUN_0050b070(short param_1, short param_2) {
    return param_1 == param_2;
}

// 0x0050b1a0 — zero-init then pass-out (no stack entry, RET plain)
// Observed: local = 0; FUN_0050b150(&local); return local.
inline int FUN_0050b1a0(void) {
    int local_4 = 0;
    FUN_0050b150(&local_4);
    return local_4;
}

// 0x0050c650 — increment wrapper (no stack entry, RET plain)
// Observed: FUN_0050c550(FUN_005f0ddc() + 1).
inline void FUN_0050c650(void) {
    FUN_0050c550(FUN_005f0ddc() + 1);
}

// 0x0050c680 — decrement wrapper (no stack entry, RET plain)
// Observed: FUN_0050c550(FUN_005f0ddc() + -1).
inline void FUN_0050c680(void) {
    FUN_0050c550(FUN_005f0ddc() + -1);
}

} // namespace band2_wave3
