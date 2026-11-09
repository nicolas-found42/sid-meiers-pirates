// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
#include <cstdint>
#include <cstddef>

extern void operator_delete(void*);
extern void FUN_00533db0(int);
extern void FUN_00534040(void);
extern void FUN_00535600(void);

// 0x00533f30 — if (FUN_00533db0(3)==0) return; else vcall +0xe8 (jumptable unrecovered)
void FUN_00533f30(int* self) {
    FUN_00533db0(3);
    void* vtbl = *(void**)self;
    void (*cb)() = (void (*)())*(void**)((char*)vtbl + 0xe8);
    cb();
}

// 0x00534a70 — scalar-deleting-dtor: FUN_00534040, if (flag&1) operator_delete
void FUN_00534a70(uint8_t flag, void* self) {
    FUN_00534040();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x00535900 — scalar-deleting-dtor: FUN_00535600, if (flag&1) operator_delete
void FUN_00535900(uint8_t flag, void* self) {
    FUN_00535600();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
extern void FUN_00537870(void);

// 0x00537910 — scalar-deleting-dtor: FUN_00537870, if (flag&1) operator_delete
void FUN_00537910(uint8_t flag, void* self) {
    FUN_00537870();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
extern void FUN_005378c0(void);

// 0x00537930 — scalar-deleting-dtor: FUN_005378c0, if (flag&1) operator_delete
void FUN_00537930(uint8_t flag, void* self) {
    FUN_005378c0();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
extern void FUN_005e1490(void);

// 0x00538370 — *this = PTR_FUN_006c0980; FUN_005e1490(); operator_delete(this[2])
void FUN_00538370(uint32_t* self) {
    self[0] = (uint32_t)0x006c0980;
    FUN_005e1490();
    operator_delete((void*)(uintptr_t)self[2]);
}
