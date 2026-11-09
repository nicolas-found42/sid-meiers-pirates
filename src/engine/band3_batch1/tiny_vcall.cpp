// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
#include <cstdint>

extern int DAT_00727864;

// 0x00535e10 — virtual dispatch through *(this+0x188), slot +0x44, null-guarded
void __thiscall FUN_00535e10(void* self) {
    void* obj = *(void**)((char*)self + 0x188);
    if (obj == nullptr) {
        return;
    }
    (*(void(**)(void))(*(void**)obj + 0x44))();
    return;
}

// 0x00538360 — single indirect dispatch through *param_1, slot +0x20
void FUN_00538360(void* self) {
    (*(void(**)(void))(*(void**)self + 0x20))();
}

// 0x005459b0
int __thiscall FUN_005459b0(void* self) {
    return *(int*)((char*)self + 0x194);
}

// 0x005459c0 — dispatch through *(this+0x194), slot +8
void __thiscall FUN_005459c0(void* self) {
    (*(void(**)(void))(*(void**)(*(void**)((char*)self + 0x194)) + 8))();
}

// 0x00547780 — dispatch through DAT_00727864, slot +0x20
void FUN_00547780(void) {
    if (DAT_00727864 == 0) {
        return;
    }
    (*(void(**)(void))(*(void**)DAT_00727864 + 0x20))();
}

// 0x00547790 — dispatch through DAT_00727864, slot +0x30
void FUN_00547790(void) {
    if (DAT_00727864 == 0) {
        return;
    }
    (*(void(**)(void))(*(void**)DAT_00727864 + 0x30))();
}
