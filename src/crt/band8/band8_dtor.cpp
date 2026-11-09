// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
#include <stddef.h>
extern void* operator delete(void*);
extern void FUN_0067ca57(void*);
extern void FUN_006a0238(void*);

// 0x0067dee3 - deleting destructor: base then operator_delete if flag&1
void* __thiscall FUN_0067dee3(void* self, unsigned char flags) {
    FUN_0067ca57(self);
    if (flags & 1) operator delete(self);
    return self;
}

// 0x006830bf - ctor/dtor with vtable reset to 0x6f07e0 then base 0x6a0238
void* __thiscall FUN_006830bf(void* self, unsigned char flags) {
    *reinterpret_cast<void**>(self) = reinterpret_cast<void*>(0x6f07e0);
    FUN_006a0238(self);
    if (flags & 1) operator delete(self);
    return self;
}
