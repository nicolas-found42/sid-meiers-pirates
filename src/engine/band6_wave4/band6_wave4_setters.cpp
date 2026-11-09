// UNVERIFIED: no cl 13.10.3077 on this host. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 6 wave 4: NiD3D shader-wrapper setters (ECX-as-self field stores). Small-span, strong evidence.

#include <stddef.h>

// 0x005dbe40 — shader-wrapper two-slot setter: stores param_1 at self+0x10, param_2 at self+0x14.
extern "C" void __thiscall Band6Wave4_Set_5dbe40(void* self_, int param_1, int param_2) {
    unsigned char* base = (unsigned char*)self_;
    *reinterpret_cast<int*>(base + 0x10) = param_1;
    *reinterpret_cast<int*>(base + 0x14) = param_2;
}

// 0x005dbe90 — shader-wrapper scalar setter: stores param_1 at self+0x24.
extern "C" void __thiscall Band6Wave4_Set_5dbe90(void* self_, int param_1) {
    unsigned char* base = (unsigned char*)self_;
    *reinterpret_cast<int*>(base + 0x24) = param_1;
}

// 0x005dbec0 — shader-wrapper scalar setter: stores param_1 at self+0x28.
extern "C" void __thiscall Band6Wave4_Set_5dbec0(void* self_, int param_1) {
    unsigned char* base = (unsigned char*)self_;
    *reinterpret_cast<int*>(base + 0x28) = param_1;
}

// 0x005dbed0 — shader-wrapper scalar setter: stores param_1 at self+0x2c.
extern "C" void __thiscall Band6Wave4_Set_5dbed0(void* self_, int param_1) {
    unsigned char* base = (unsigned char*)self_;
    *reinterpret_cast<int*>(base + 0x2c) = param_1;
}

// 0x005dbee0 — shader-wrapper scalar setter: stores param_1 at self+0x30.
extern "C" void __thiscall Band6Wave4_Set_5dbee0(void* self_, int param_1) {
    unsigned char* base = (unsigned char*)self_;
    *reinterpret_cast<int*>(base + 0x30) = param_1;
}
