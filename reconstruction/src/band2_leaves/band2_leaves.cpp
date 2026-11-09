// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c.
// Small leaves selected from the band2 queue by span.
#include <cstddef>

extern "C" void FUN_004d4580(void* self);   // 0x004d4580
extern "C" void FUN_004b0650(void);         // 0x004b0650
extern "C" void operator_delete(void* p);

// 0x004cd150 — resets a buffer/count pair addressed through EAX.
// The provider exposes no stack argument; EAX holds a pointer-like object.
// The exact source-level entry (method vs. naked helper) is unknown.
void FUN_004cd150() {
    // Observed: if (*(int*)(*p - 4) != 0) { *p = 0; *(int*)(p - 4) = 0; }
    // and p[1] = -1. Kept as a comment because EAX cannot be named portably.
}

// 0x004d0880 — scalar-deleting destructor with a different body at 0x004d4580.
void __thiscall FUN_004d0880(void* self, unsigned char flags) {
    FUN_004d4580(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
}

// 0x004d4600 — clears field +8, then calls the observed helper with no args.
void __cdecl FUN_004d4600(char* self) {
    *reinterpret_cast<unsigned*>(self + 8) = 0;
    FUN_004b0650();
}

// 0x004d4bc0 — observed body is a single RET.
void FUN_004d4bc0() {}
