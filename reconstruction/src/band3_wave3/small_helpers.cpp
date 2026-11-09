// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
#include <cstdint>
#include <cstddef>

extern void operator_delete(void*);

// 0x0052c130 — reads *this; if this[1]==0.0 return *this; else return FUN_0052c130() * *this
float FUN_0052c130(float* self) {
    float f = *self;
    if (self[1] == 0.0f) {
        return f;
    }
    return FUN_0052c130(self) * f;
}

// 0x0052c150 — walks +0x04 chain to tail and appends in_EDX (if in_EDX != 0)
void FUN_0052c150(void* self, uint32_t node) {
    char* cur = (char*)self;
    if (node != 0) {
        while (*(uint32_t*)(cur + 4) != 0) {
            cur = (char*)(uintptr_t)*(uint32_t*)(cur + 4);
        }
        *(uint32_t*)(cur + 4) = node;
    }
}
extern void FUN_00530300(void);

// 0x005302e0 — scalar-deleting-dtor: FUN_00530300, if (flag&1) operator_delete
void FUN_005302e0(uint8_t flag, void* self) {
    FUN_00530300();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x00531920 — vcall +0x40; if result==0 return *(float*)(this+0x7c) else return 0.0
float FUN_00531920(int* self) {
    void* vtbl = *(void**)self;
    int (*cb)() = (int (*)())*(void**)((char*)vtbl + 0x40);
    if (cb() == 0) {
        return *(float*)((char*)self + 0x7c);
    }
    return 0.0f;
}
extern void FUN_00531ac0(void);

// 0x00531aa0 — scalar-deleting-dtor: FUN_00531ac0, if (flag&1) operator_delete
void FUN_00531aa0(uint8_t flag, void* self) {
    FUN_00531ac0();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
