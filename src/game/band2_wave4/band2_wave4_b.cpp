// Band2 wave4 batch B — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// Built from analysis/pseudocode/functions/*.c; cl 13.10.3077 absent so nothing is byte-matched.
#include <windows.h>
#include <string.h>
#include <math.h>

namespace band2_wave4 {

extern int FUN_005f0ddc(void);
extern void FUN_00507c90(int);
extern void FUN_004cd2a0(void);
extern void FUN_004d4be0(void);
extern void FUN_004d4cb0(void);
extern void FUN_004985e0(void);
extern void FUN_004a14b0(void);
extern void FUN_005bf9b0(void*, int);
extern void FUN_005bf9e0(int, int, int, int);
extern void operator_delete(void*);
extern int DAT_007263ba;
extern unsigned char DAT_008cac25;
extern unsigned int DAT_0085a164;

// 0x00500bc0 — double vtable dispatch (register ECX plus 1 stack arg)
// Observed: (**(code **)(*in_ECX + 0x28))(param_1);
//           (**(code **)(*(int *)in_ECX[0x58] + 0xc))(&uStack00000000,4);
// in_ECX is the ECX register input; its caller convention is unknown.
typedef void (__cdecl *VCall28)(unsigned int);
typedef void (__cdecl *VCallC)(const void*, int);
inline void FUN_00500bc0(void* pEcx, unsigned int param_1) {
    ((VCall28)(*(int*)pEcx + 0x28))(param_1);
    ((VCallC)(*(int*)(*(int*)((unsigned char*)pEcx + 0x58)) + 0xc))(&param_1, 4);
}

// 0x00507250 — store two values and negated float (register ECX plus 3 stack args)
// Observed: *(in_ECX + 0x5c) = param_1; *(in_ECX + 0x60) = param_3;
//           *(in_ECX + 100) = -param_2;
// in_ECX is the ECX register input; its caller convention is unknown.
// Note: pseudocode prints the third offset as decimal 100 (= 0x64).
inline void FUN_00507250(void* pEcx, unsigned int param_1, float param_2, unsigned int param_3) {
    *(unsigned int*)((unsigned char*)pEcx + 0x5c) = param_1;
    *(unsigned int*)((unsigned char*)pEcx + 0x60) = param_3;
    *(float*)((unsigned char*)pEcx + 0x64) = -param_2;
}

// 0x0050c4a0 — call then vtable dispatch at +0x15c (1 stack arg)
// Observed: iVar1 = param_1; FUN_00507c90(param_1);
//           (**(code **)(**(int **)(iVar1 + 0x15c) + 8))(&param_1,4);
typedef void (__cdecl *VCall8)(const void*, int);
inline void FUN_0050c4a0(int param_1) {
    FUN_00507c90(param_1);
    ((VCall8)(*(int*)(*(int*)(param_1 + 0x15c)) + 8))(&param_1, 4);
}

// 0x00513cf0 — modf split (2 stack args)
// Observed: dVar1 = modf((double)param_1,&local_c); *param_2 = (float)local_c;
//           return (float10)dVar1;
inline float FUN_00513cf0(float param_1, float* param_2) {
    double dVar1 = modf((double)param_1, &param_2[0]);
    return (float)dVar1;
}

// 0x004cca70 — range check then offset (2 stack args)
// Observed: if ((param_2 < 0) || (3 < param_2)) return 5;
//           iVar1 = FUN_005f0ddc(); return iVar1 + 5;
inline int FUN_004cca70(unsigned int param_1, int param_2) {
    (void)param_1;
    if ((param_2 < 0) || (3 < param_2)) {
        return 5;
    }
    int iVar1 = FUN_005f0ddc();
    return iVar1 + 5;
}

// 0x004ccc30 — cleanup then conditional delete (register ECX plus 1 stack arg)
// Observed: FUN_004cd2a0(); if ((param_1 & 1) != 0) operator_delete(in_ECX);
// in_ECX is the ECX register input; its caller convention is unknown.
inline void FUN_004ccc30(void* pEcx, unsigned char param_1) {
    FUN_004cd2a0();
    if ((param_1 & 1) != 0) {
        operator_delete(pEcx);
    }
}

// 0x004d05f0 — alloc helper then flag store (register BL, no stack entry)
// Observed: FUN_005bf9b0(local_c,2); FUN_005bf9e0(2,2,2,-(unaff_BL != 0) & 2);
//           DAT_007263ba = unaff_BL;
// unaff_BL is the BL register input; its caller convention is unknown.
inline void FUN_004d05f0(char pBl) {
    unsigned char local_c[12];
    FUN_005bf9b0(local_c, 2);
    FUN_005bf9e0(2, 2, 2, -(pBl != '\0') & 2);
    DAT_007263ba = pBl;
}

// 0x004d3ef0 — two-call init then flag update (no stack entry)
// Observed: FUN_004985e0(); FUN_004a14b0();
//           DAT_008cac25 = (byte)(_DAT_0085a164 >> 2) & 1; _DAT_0085a164 = _DAT_0085a164 | 4;
inline void FUN_004d3ef0(void) {
    FUN_004985e0();
    FUN_004a14b0();
    DAT_008cac25 = (unsigned char)((DAT_0085a164 >> 2) & 1);
    DAT_0085a164 = DAT_0085a164 | 4;
}

// 0x004d45c0 — cleanup then conditional delete (register ECX plus 1 stack arg)
// Observed: FUN_004d4be0(); if ((param_1 & 1) != 0) operator_delete(in_ECX);
// in_ECX is the ECX register input; its caller convention is unknown.
inline void FUN_004d45c0(void* pEcx, unsigned char param_1) {
    FUN_004d4be0();
    if ((param_1 & 1) != 0) {
        operator_delete(pEcx);
    }
}

// 0x004d4d80 — cleanup then conditional delete (register ECX plus 1 stack arg)
// Observed: FUN_004d4cb0(); if ((param_1 & 1) != 0) operator_delete(in_ECX);
// in_ECX is the ECX register input; its caller convention is unknown.
inline void FUN_004d4d80(void* pEcx, unsigned char param_1) {
    FUN_004d4cb0();
    if ((param_1 & 1) != 0) {
        operator_delete(pEcx);
    }
}

} // namespace band2_wave4
