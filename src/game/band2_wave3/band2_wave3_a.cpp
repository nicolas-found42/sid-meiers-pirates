// Band2 wave3 batch A — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// Built from analysis/pseudocode/functions/*.c; cl 13.10.3077 absent so nothing is byte-matched.
#include <windows.h>
#include <string.h>

namespace band2_wave3 {

extern void FUN_004fcd60(void);
extern void FUN_004985e0(void);
extern void FUN_004a14b0(void);
extern void FUN_005be280(const char*, int, void*);
extern int FUN_00533c78(int);
extern void* FUN_00502460(void);
extern int gInit_8cad0c;
extern int* gTable_727b28;
extern void FUN_004f60d0(void*, int);
extern int FUN_004f4ed0(void);

// 0x004d3f50 — two-call init pair (no stack entry, RET plain)
// Observed: FUN_004985e0(); FUN_004a14b0(); in that order.
inline void FUN_004d3f50(void) {
    FUN_004985e0();
    FUN_004a14b0();
}

// 0x004d3f90 — two-call init pair (no stack entry, RET plain)
// Observed: FUN_004985e0(); FUN_004a14b0(); in that order.
// Body identical to 0x004d3f50; both addresses retained for manifest linkage.
inline void FUN_004d3f90(void) {
    FUN_004985e0();
    FUN_004a14b0();
}

// 0x004e4530 — water texture scale setter (1 stack arg, RET plain)
// Observed: FUN_005be280("fWaterTexScale", 4, &param_1).
inline void FUN_004e4530(unsigned char param_1) {
    FUN_005be280("fWaterTexScale", 4, &param_1);
}

// 0x004f17b0 — single forwarder leaf (no stack entry, RET plain)
// Observed: FUN_004fcd60(); return.
inline void FUN_004f17b0(void) {
    FUN_004fcd60();
}

// 0x004f2600 — three-arg forwarder with register arg (in_EDX plus 2 stack args)
// Observed: FUN_004f2620(in_EDX, param_1, &param_2); EDX comes from the caller,
// not the stack. Caller convention for EDX is unknown.
extern void FUN_004f2620(void*, void*, void*);
inline void FUN_004f2600(void* pEdx, void* param_1, unsigned char param_2) {
    FUN_004f2620(pEdx, param_1, &param_2);
}

// 0x004f3540 — three-arg forwarder with register arg (in_EDX plus 2 stack args)
// Observed: FUN_004f3560(in_EDX, param_1, &param_2); EDX comes from the caller,
// not the stack. Caller convention for EDX is unknown.
extern void FUN_004f3560(void*, void*, void*);
inline void FUN_004f3540(void* pEdx, void* param_1, unsigned char param_2) {
    FUN_004f3560(pEdx, param_1, &param_2);
}

// 0x004f6090 — FUN_004f60d0 selector passing 0 (2 stack args, RET plain)
// Observed: FUN_004f60d0(&param_2, 0); param_1 is unused in the body.
inline void FUN_004f6090(void* param_1, unsigned char param_2) {
    (void)param_1;
    FUN_004f60d0(&param_2, 0);
}

// 0x004f60b0 — FUN_004f60d0 selector passing 1 (2 stack args, RET plain)
// Observed: FUN_004f60d0(&param_2, 1); param_1 is unused in the body.
inline void FUN_004f60b0(void* param_1, unsigned char param_2) {
    (void)param_1;
    FUN_004f60d0(&param_2, 1);
}

// 0x004f8b40 — varargs debug-string formatter (2 stack args, RET plain)
// Observed: char buf[1024]; _vsnprintf(buf, 0x3fc, param_1, &param_2);
// OutputDebugStringA(buf).
inline void FUN_004f8b40(const char* param_1, const void* param_2) {
    char local_400[1024];
    _vsnprintf(local_400, 0x3fc, param_1, (const char*)param_2);
    OutputDebugStringA(local_400);
}

// 0x004f8b80 — varargs formatter via indirect call (2 stack args, RET plain)
// Observed: char buf[1024]; _vsnprintf(buf, 0x3fc, param_1, &param_2);
// (*(code*)PTR_FUN_007264d4)(buf, 0).
typedef void (__cdecl *DebugFn)(const char*, int);
extern void* PTR_FUN_007264d4;
inline void FUN_004f8b80(const char* param_1, const void* param_2) {
    char local_400[1024];
    _vsnprintf(local_400, 0x3fc, param_1, (const char*)param_2);
    ((DebugFn)PTR_FUN_007264d4)(local_400, 0);
}

} // namespace band2_wave3
