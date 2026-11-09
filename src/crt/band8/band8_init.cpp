// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
// Band 8 static-init tail fragments. NOTE: these are fragments of enclosing
// static-init TUs - do not match as standalone game units.
#include <stddef.h>
extern void FUN_005edba0(void*);
extern void FUN_005f0810(void*);
extern void* _DAT_00728ad4;
extern void* _DAT_00717cb8;

// 0x006bfc50: store vtable 0x6c4eb4 to slot 0x728ad4
void FUN_006bfc50(void) {
    _DAT_00728ad4 = reinterpret_cast<void*>(0x6c4eb4);
}

// 0x006bfc60: install vtable, call, install vtable
void FUN_006bfc60(void) {
    _DAT_00717cb8 = reinterpret_cast<void*>(0x711b1c);
    FUN_005edba0();
    _DAT_00717cb8 = reinterpret_cast<void*>(0x71199c);
}

// 0x006bfc80: tail stub - span 896 is end-of-text artifact, body 10 bytes
void FUN_006bfc80(void) {
    FUN_005f0810();
}
