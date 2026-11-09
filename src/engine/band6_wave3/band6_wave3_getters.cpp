// UNVERIFIED: no cl 13.10.3077 on this host. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 6 wave 3: small-span Gamebryo/NiD3D slot getters + constant stubs (ECX-as-self).

#include <stddef.h>

// 0x005dbe30 — shader-wrapper getter: returns word at self+0x14.
extern "C" int __thiscall Band6Wave3_Get_5dbe30(void* self_) {
    const unsigned char* base = (const unsigned char*)self_;
    return *reinterpret_cast<const unsigned*>(base + 0x14);
}

// 0x005ece60 — effect/helper getter: returns word at self+0x00.
extern "C" int __thiscall Band6Wave3_Get_5ece60(void* self_) {
    const unsigned char* base = (const unsigned char*)self_;
    return *reinterpret_cast<const unsigned*>(base + 0x00);
}

// 0x005ece70 — effect/helper byte getter: returns byte at self+0x10.
extern "C" unsigned char __thiscall Band6Wave3_Get_5ece70(void* self_) {
    const unsigned char* base = (const unsigned char*)self_;
    return *(base + 0x10);
}

// 0x005f0f28 — Ni math/D3D config stub: observed body returns constant 0.
extern "C" int __thiscall Band6Wave3_Stub_5f0f28(void* self_) {
    (void)self_;
    return 0;
}

// 0x005f6015 — Ni math/D3D config stub: observed body is void return, no stores.
extern "C" void __thiscall Band6Wave3_Stub_5f6015(void* self_) {
    (void)self_;
    return;
}
