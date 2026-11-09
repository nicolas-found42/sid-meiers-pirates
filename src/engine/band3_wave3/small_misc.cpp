// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
#include <cstdint>
#include <cstddef>
extern void FUN_00545310(uint32_t, uint32_t);

// 0x00538410 — forwards (self,param_1) to FUN_00545310
void FUN_00538410(uint32_t self, uint32_t param_1) {
    FUN_00545310(self, param_1);
}

// 0x00538f20 — returns 1 if (*this >= 4 && *this <= 6), else 0
uint32_t FUN_00538f20(int* self) {
    if ((*self < 4) || (6 < *self)) {
        return 0;
    }
    return 1;
}

// 0x00538f40 — returns 0 if this+0x1c==p+0x1c && this+0x20==p+0x20, else 1
uint32_t FUN_00538f40(void* self, void* p) {
    if ((*(int*)((char*)self + 0x1c) == *(int*)((char*)p + 0x1c)) &&
        (*(int*)((char*)self + 0x20) == *(int*)((char*)p + 0x20))) {
        return 0;
    }
    return 1;
}

// 0x00539980 — decref object at this+0x40 (slot 1 decremented; if reaches 0, vcall(1)); clears +0x40
void FUN_00539980(void* self) {
    uint32_t* obj = *(uint32_t**)((char*)self + 0x40);
    if (obj != (uint32_t*)0) {
        int* count = (int*)(obj + 1);
        *count = *count - 1;
        if (*count == 0) {
            void (*cb)(int) = (void (*)(int))*(void**)obj;
            cb(1);
        }
        *(uint32_t*)((char*)self + 0x40) = 0;
    }
}
