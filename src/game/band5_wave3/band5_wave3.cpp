// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent; no PASS.
// Sources: analysis/pseudocode/functions/*.c.
#include <cstdint>
#include <cstddef>

extern void __cdecl operator_delete(void* p);
extern void __cdecl FUN_005b6ee0(void* self);
extern void __cdecl FUN_005b46d0(void* self);
extern void __cdecl FUN_005bbf20(uint32_t value);
extern void __cdecl FUN_00545d20(void);

// 0x005b4100 — scalar-deleting wrapper: body 0x005b6ee0, conditional free.
void __thiscall FUN_005b4100(void* self, uint8_t flags) {
    FUN_005b6ee0(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
}

// 0x005b4170 — forwards the stack value, then calls 0x00545d20.
void __cdecl FUN_005b4170(uint32_t value) {
    FUN_005bbf20(value);
    FUN_00545d20();
}

// 0x005b4720 — scalar-deleting wrapper: body 0x005b46d0, conditional free.
void __thiscall FUN_005b4720(void* self, uint8_t flags) {
    FUN_005b46d0(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
}
