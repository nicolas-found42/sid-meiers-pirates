// UNVERIFIED: no cl 13.10.3077 on this host. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 6 wave 4 batch 2: byte setter + owned-string setters + slot getters (ECX-as-self).

#include <stddef.h>

extern void operator_delete__(void* p);
extern void* FUN_00533c78(unsigned int size);

// 0x005dbf00 — shader-wrapper byte setter: stores param_1 (byte) at self+0x24.
extern "C" void __thiscall Band6Wave4_SetByte_5dbf00(void* self_, unsigned char value) {
    unsigned char* base = (unsigned char*)self_;
    *(base + 0x24) = value;
}

// 0x005dbfa0 — shader-wrapper getter: returns word at self+0x2c.
extern "C" int __thiscall Band6Wave4_Get_5dbfa0(void* self_) {
    const unsigned char* base = (const unsigned char*)self_;
    return *reinterpret_cast<const int*>(base + 0x2c);
}

// 0x005dc010 — shader-wrapper getter: returns word at self+0x30.
extern "C" int __thiscall Band6Wave4_Get_5dc010(void* self_) {
    const unsigned char* base = (const unsigned char*)self_;
    return *reinterpret_cast<const int*>(base + 0x30);
}

// 0x005dc070 — shader-wrapper getter: returns word at self+0x34.
extern "C" int __thiscall Band6Wave4_Get_5dc070(void* self_) {
    const unsigned char* base = (const unsigned char*)self_;
    return *reinterpret_cast<const int*>(base + 0x34);
}

// 0x005dc0e0 — shader-wrapper getter: returns word at self+0x38.
extern "C" int __thiscall Band6Wave4_Get_5dc0e0(void* self_) {
    const unsigned char* base = (const unsigned char*)self_;
    return *reinterpret_cast<const int*>(base + 0x38);
}
