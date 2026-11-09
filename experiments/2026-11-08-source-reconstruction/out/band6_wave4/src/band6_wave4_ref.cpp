// UNVERIFIED: no cl 13.10.3077 on this host. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 6 wave 4 batch 4: refcounted interface slots + vtable dtor (operator_delete declared, never defined).

#include <stddef.h>

extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void* FUN_00533c78(unsigned int size);
extern void __thiscall FUN_005ce790(void* self_);

// 0x005dc020 — iface-slot setter at self+0x30: Release old via vtable+8, AddRef new via vtable+4. Null-guarded.
extern "C" void __thiscall Band6Wave4_SetIface_5dc020(void* self_, void* next) {
    unsigned char* base = (unsigned char*)self_;
    void** slot = (void**)(base + 0x30);
    if (*slot != next) {
        if (*slot != (void*)0) {
            typedef void (__thiscall *VRel)(void*);
            void* old = *slot;
            ((VRel)(*(int**)old)[8 / 4])(old);
        }
        *slot = next;
        if (next != (void*)0) {
            typedef void (__thiscall *VAdd)(void*);
            ((VAdd)(*(int**)next)[4 / 4])(next);
        }
    }
}

// 0x005dc160 — iface-slot setter at self+0x3c: Release old via vtable+8, AddRef new via vtable+4. Null-guarded.
extern "C" void __thiscall Band6Wave4_SetIface_5dc160(void* self_, void* next) {
    unsigned char* base = (unsigned char*)self_;
    void** slot = (void**)(base + 0x3c);
    if (*slot != next) {
        if (*slot != (void*)0) {
            typedef void (__thiscall *VRel)(void*);
            void* old = *slot;
            ((VRel)(*(int**)old)[8 / 4])(old);
        }
        *slot = next;
        if (next != (void*)0) {
            typedef void (__thiscall *VAdd)(void*);
            ((VAdd)(*(int**)next)[4 / 4])(next);
        }
    }
}

// 0x005dd4e0 — dtor core: call FUN_005ce760, vtable init, zero self+0x44, refcount Release on self+0x44 slot.
extern "C" void __thiscall Band6Wave4_DtorCore_5dd4e0(void* self_) {
    extern void __thiscall FUN_005ce760(void* self_);
    int* self = (int*)self_;
    FUN_005ce760(self_);
    *self = (int)(long)&PTR_FUN_006c9270;
    self[0x11] = 0;
    int* held = (int*)self[0x11];
    if (held != (int*)0) {
        int* rc = held + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            typedef void (__thiscall *VRel)(int*, int);
            ((VRel)(*held))(held, 1);
        }
        self[0x11] = 0;
    }
}

// 0x005dd520 — deleting-dtor: vtable init, double Release, FUN_005ce790, conditional operator_delete on flag.
extern "C" void __thiscall Band6Wave4_DeletingDtor_5dd520(void* self_, unsigned char flag) {
    int* self = (int*)self_;
    *self = (int)(long)&PTR_FUN_006c9270;
    int* held = (int*)self[0x11];
    if (held != (int*)0) {
        int* rc = held + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            typedef void (__thiscall *VRel)(int*, int);
            ((VRel)(*held))(held, 1);
        }
        self[0x11] = 0;
    }
    held = (int*)self[0x11];
    if (held != (int*)0) {
        int* rc = held + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            typedef void (__thiscall *VRel)(int*, int);
            ((VRel)(*held))(held, 1);
        }
    }
    FUN_005ce790(self_);
    if ((flag & 1) != 0) {
        operator_delete(self_);
    }
}
