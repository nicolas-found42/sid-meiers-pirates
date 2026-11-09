// Band4 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Bounds-checked slot/vector accessors on a small holder object
// (+0x0c single slot, +0x10 count, +0x14 base). Corpus:
// analysis/pseudocode/functions/0x54bcb0.c, 0x54bcd0.c, 0x54c3e0.c, 0x54c400.c
#include <stddef.h>

struct SlotHolder {
    void*      vptr_00;
    int        slot_0c;    // +0x0c
    unsigned   count_10;   // +0x10
    void**     data_14;    // +0x14

    bool  __thiscall FUN_0054bcb0(int value);
    void  __thiscall FUN_0054bcd0(void);
    bool  __thiscall FUN_0054c3e0(unsigned index, void* value);
    float __thiscall FUN_0054c400(unsigned index);
};

// 0x0054bcb0 — set-if-null; returns whether the write happened.
bool __thiscall SlotHolder::FUN_0054bcb0(int value)
{
    if (slot_0c == 0) {
        slot_0c = value;
        return true;
    }
    return false;
}

// 0x0054bcd0 — clear the slot.
void __thiscall SlotHolder::FUN_0054bcd0(void)
{
    slot_0c = 0;
}

// 0x0054c3e0 — bounds-checked store into data_14[index].
bool __thiscall SlotHolder::FUN_0054c3e0(unsigned index, void* value)
{
    if (index < count_10) {
        data_14[index] = value;
        return true;
    }
    return false;
}

// 0x0054c400 — bounds-checked load; 0.0f out of range. (Ghidra's float10
// return spelling is an x87 artifact; source is read as float.)
float __thiscall SlotHolder::FUN_0054c400(unsigned index)
{
    if (index < count_10) {
        return *(float*)&data_14[index];
    }
    return 0.0f;
}
