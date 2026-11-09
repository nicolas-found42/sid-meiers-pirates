// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
#include <cstdint>

extern void DAT_00533b60(void);
extern int DAT_00727444;
extern int DAT_007275a0;
extern int DAT_00727864;
extern int DAT_0072792c;
extern char PTR_LAB_006fd148[];
extern char PTR_LAB_006c1e00[];

// atexit wrapper used by 0x533b70 (corpus spells _atexit on a func ptr)
using _func_4879 = void (*)();
extern void _atexit(_func_4879);
extern int FUN_00535290(void);

// 0x00533b70
int __cdecl FUN_00533b70(void) {
    _atexit((_func_4879 *)&DAT_00533b60);
    return 0;
}

// 0x00538400
void __thiscall FUN_00538400(void* self) {
    *(void**)self = (void*)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
    return;
}

// 0x0053ee10
void FUN_0053ee10(void) {
    DAT_007275a0 = FUN_00535290();
    return;
}

// 0x00547720
int FUN_00547720(void) {
    return DAT_00727864;
}

// 0x0054aad0
int FUN_0054aad0(void) {
    return DAT_0072792c;
}

// 0x00549b80
void __thiscall FUN_00549b80(void* self) {
    *(void**)self = (void*)&PTR_LAB_006c1e00;
    FUN_00538400();
    return;
}
