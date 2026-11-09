// Band2 wave4 batch A — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// Built from analysis/pseudocode/functions/*.c; cl 13.10.3077 absent so nothing is byte-matched.
#include <windows.h>
#include <string.h>

namespace band2_wave4 {

extern int FUN_005f0ddc(void);
extern void FUN_0050c550(int);
extern void FUN_0050c5d0(void);
extern void FUN_005002f0(void);
extern void FUN_004eaae0(unsigned int, unsigned int);
extern void FUN_004f2620(void*, unsigned int, unsigned char*);
extern int DAT_008cade0;
extern int DAT_008cade4;
extern int DAT_008cade8;
extern int DAT_008ea08c;
extern int DAT_008cacd0;
extern int FUN_00533c78(int);

// 0x0050c6b0 — single forwarder leaf (no stack entry, RET plain)
// Observed: FUN_005f0ddc(); return.
inline void FUN_0050c6b0(void) {
    FUN_005f0ddc();
}

// 0x004f17f0 — vtable store then forwarder (register-top pointer plus 2 stack args)
// Observed: *unaff_ESI = &DAT_008cacd0; FUN_004f2620(unaff_ESI,param_1,&param_2);
// unaff_ESI is the ESI register input; its caller convention is unknown.
inline void FUN_004f17f0(void* pEsi, unsigned int param_1, unsigned char param_2) {
    *(unsigned int*)pEsi = (unsigned int)&DAT_008cacd0;
    FUN_004f2620(pEsi, param_1, &param_2);
}

// 0x00500920 — globals store then vtable dispatch (3 stack args, RET plain)
// Observed: DAT_008cade4 = param_2; DAT_008cade0 = param_1; DAT_008cade8 = param_3;
// (*(code **)(*DAT_008ea08c + 0x74))(&DAT_008cade0);
typedef void (__cdecl *VCall110)(void*);
inline void FUN_00500920(unsigned int param_1, unsigned int param_2, unsigned int param_3) {
    DAT_008cade4 = param_2;
    DAT_008cade0 = param_1;
    DAT_008cade8 = param_3;
    ((VCall110)(*(int*)(DAT_008ea08c) + 0x74))(&DAT_008cade0);
}

// 0x0050c6d0 — fetch then pass (no stack entry, RET plain)
// Observed: uVar1 = FUN_005f0ddc(); FUN_0050c550(uVar1);
inline void FUN_0050c6d0(void) {
    int uVar1 = FUN_005f0ddc();
    FUN_0050c550(uVar1);
}

// 0x0050c740 — fetch then pass (no stack entry, RET plain)
// Observed: uVar1 = FUN_005f0ddc(); FUN_0050c5d0(uVar1);
inline void FUN_0050c740(void) {
    int uVar1 = FUN_005f0ddc();
    FUN_0050c5d0(uVar1);
}

// 0x004dccd0 — call then zero byte field at +0x24c (1 stack arg, RET plain)
// Observed: FUN_005002f0(); *(param_1 + 0x24c) = 0;
inline void FUN_004dccd0(int param_1) {
    FUN_005002f0();
    *(unsigned char*)(param_1 + 0x24c) = 0;
}

// 0x004ea8b0 — indexed divisions then counter increment (register ECX plus 1 stack arg)
// Observed: FUN_004eaae0(*(param_1 + 0x24) / (*(in_ECX + 0x7c) - 1),
//                         *(param_1 + 0x28) / (*(in_ECX + 0x80) - 1));
//           *(in_ECX + 0xc4) = *(in_ECX + 0xc4) + 1;
// in_ECX is the ECX register input; its caller convention is unknown.
inline void FUN_004ea8b0(void* pEcx, int param_1) {
    FUN_004eaae0(*(unsigned int*)(param_1 + 0x24) / (*(int*)((unsigned char*)pEcx + 0x7c) - 1),
                 *(unsigned int*)(param_1 + 0x28) / (*(int*)((unsigned char*)pEcx + 0x80) - 1));
    *(int*)((unsigned char*)pEcx + 0xc4) = *(int*)((unsigned char*)pEcx + 0xc4) + 1;
}

// 0x004f1370 — CopyFileA wrapper returning negated result (register ECX plus 1 stack arg)
// Observed: BVar1 = CopyFileA(param_1,in_ECX,(uint)(in_DL == 0)); return BVar1 == 0;
// in_ECX/in_DL are register inputs; their caller convention is unknown.
inline bool FUN_004f1370(void* pEcx, unsigned char pDl, LPCSTR param_1) {
    BOOL BVar1 = CopyFileA(param_1, (LPCSTR)pEcx, (unsigned int)(pDl == '\0'));
    return BVar1 == 0;
}

// 0x004f4e60 — flag predicate (register ECX, no stack entry)
// Observed: if (*(in_ECX + 0x2c) == 0) return (uint)(*(in_ECX + 4) != 0);
//           return CONCAT31((int3)((uint)*(in_ECX + 0x2c) >> 8),1);
// CONCAT31 keeps the upper 3 bytes and forces the low byte to 1, i.e. (x & ~0xFF) | 1.
// in_ECX is the ECX register input; its caller convention is unknown.
inline unsigned int FUN_004f4e60(void* pEcx) {
    if (*(int*)((unsigned char*)pEcx + 0x2c) == 0) {
        return (unsigned int)(*(int*)((unsigned char*)pEcx + 4) != 0);
    }
    return (unsigned int)((*(int*)((unsigned char*)pEcx + 0x2c)) & ~0xFF) | 1;
}

// 0x004ff5f0 — scaled float accumulations (register EAX plus 1 stack arg)
// Observed: *(in_EAX + 0x5c) = *(in_EAX + 0x38) * param_1 + *(in_EAX + 0x5c);
//           *(in_EAX + 0x60) = *(in_EAX + 0x44) * param_1 + *(in_EAX + 0x60);
//           *(in_EAX + 100)  = *(in_EAX + 0x50) * param_1 + *(in_EAX + 100);
// in_EAX is the EAX register input; its caller convention is unknown.
// Note: pseudocode prints the third offset as decimal 100 (= 0x64).
inline void FUN_004ff5f0(void* pEax, float param_1) {
    *(float*)((unsigned char*)pEax + 0x5c) = *(float*)((unsigned char*)pEax + 0x38) * param_1 + *(float*)((unsigned char*)pEax + 0x5c);
    *(float*)((unsigned char*)pEax + 0x60) = *(float*)((unsigned char*)pEax + 0x44) * param_1 + *(float*)((unsigned char*)pEax + 0x60);
    *(float*)((unsigned char*)pEax + 0x64) = *(float*)((unsigned char*)pEax + 0x50) * param_1 + *(float*)((unsigned char*)pEax + 0x64);
}

} // namespace band2_wave4
