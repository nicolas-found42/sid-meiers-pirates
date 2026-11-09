#include <cstdint>
#include <cstddef>
#include <windows.h>

// Reconstructed candidates for Sid Meier's Pirates! (2004) PE32 i386.
// Each definition corresponds to one pseudocode listing under
// analysis/pseudocode/functions/ as listed in TASK.md for mass_0046.

extern void operator_delete(void* p);
extern void FUN_004e6420_recon();
extern void* PTR_FUN_0070d0c8;
extern void* PTR_FUN_0070d0e4;
extern void* PTR_FUN_0070d0ac;
extern void* PTR_FUN_0070d13c;

// 0x4c28b0 — vftable reset to PTR_FUN_0070d0c8, call FUN_004e6420, delete word at +8, conditionally delete self
void FUN_004c28b0_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d0c8);
    FUN_004e6420_recon();
    operator_delete(reinterpret_cast<void*>((*pSelf)[2]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c28f0 — vftable reset to PTR_FUN_0070d0e4, call FUN_004e6420, reset to PTR_FUN_0070d0c8, call FUN_004e6420, delete word at +8, conditionally delete self
void FUN_004c28f0_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d0e4);
    FUN_004e6420_recon();
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d0c8);
    FUN_004e6420_recon();
    operator_delete(reinterpret_cast<void*>((*pSelf)[2]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c2950 — call FUN_004c26a0, conditionally delete self
extern void FUN_004c26a0_recon(void* self);
void FUN_004c2950_recon(void* self, uint8_t flag) {
    FUN_004c26a0_recon(self);
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c2980 — vftable reset to PTR_FUN_0070d13c, delete word at +4, conditionally delete self
void FUN_004c2980_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d13c);
    operator_delete(reinterpret_cast<void*>((*pSelf)[1]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c29b0 — vftable reset to PTR_FUN_0070d0ac, call FUN_004e6420, delete word at +8, conditionally delete self
void FUN_004c29b0_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d0ac);
    FUN_004e6420_recon();
    operator_delete(reinterpret_cast<void*>((*pSelf)[2]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
extern void* PTR_FUN_0070d04c;
extern void* PTR_FUN_0070d048;
extern void* PTR_FUN_00711680;
extern void* PTR_FUN_0070d028;
extern void* PTR_FUN_0070d024;

// 0x4c29f0 — vftable reset to PTR_FUN_0070d04c, call FUN_004e6420, delete word at +8, conditionally delete self
void FUN_004c29f0_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d04c);
    FUN_004e6420_recon();
    operator_delete(reinterpret_cast<void*>((*pSelf)[2]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c2a30 — vftable reset to PTR_FUN_0070d048, delete word at +4, conditionally delete self
void FUN_004c2a30_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d048);
    operator_delete(reinterpret_cast<void*>((*pSelf)[1]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c2a60 — vftable reset to PTR_FUN_00711680, delete word at +4, conditionally delete self
void FUN_004c2a60_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_00711680);
    operator_delete(reinterpret_cast<void*>((*pSelf)[1]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c2a90 — vftable reset to PTR_FUN_0070d028, delete word at +4, conditionally delete self
void FUN_004c2a90_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d028);
    operator_delete(reinterpret_cast<void*>((*pSelf)[1]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c2ac0 — vftable reset to PTR_FUN_0070d024, delete word at +4, conditionally delete self
void FUN_004c2ac0_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d024);
    operator_delete(reinterpret_cast<void*>((*pSelf)[1]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
extern void* PTR_FUN_0070d044;
extern void* PTR_FUN_0070d000;

// 0x4c2b10 — vftable reset to PTR_FUN_0070d044, reverse-iterate dword array at +4 with count at [-4], refcount-decrement entries at +4 (call deleting destructor with flag 1 when count reaches 0), free array block
void FUN_004c2b10_recon(void* self) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d044);
    int32_t data = static_cast<int32_t>(reinterpret_cast<uintptr_t>((*pSelf)[1]));
    if (data != 0) {
        int32_t count = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(data) - 4);
        int32_t cursor = data + count * 4;
        if (count - 1 > -1) {
            do {
                uint32_t* entry = *reinterpret_cast<uint32_t**>(static_cast<uintptr_t>(cursor) - 4);
                cursor += -4;
                if (entry != nullptr) {
                    int32_t* refCount = reinterpret_cast<int32_t*>(entry + 1);
                    *refCount += -1;
                    if (*refCount == 0) {
                        using DeletingDtorFn = void(__cdecl*)(uint8_t);
                        DeletingDtorFn dtor = reinterpret_cast<DeletingDtorFn>(*entry);
                        dtor(1);
                    }
                }
                count += -1;
            } while (count != 0);
        }
        operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(data) - 4));
    }
}

// 0x4c2b60 — vftable reset to PTR_FUN_0070d000, call FUN_004e6420, reset to PTR_FUN_0070d04c, call FUN_004e6420, delete word at +8, conditionally delete self
void FUN_004c2b60_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d000);
    FUN_004e6420_recon();
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d04c);
    FUN_004e6420_recon();
    operator_delete(reinterpret_cast<void*>((*pSelf)[2]));
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4c2ba0 — if flag at +0x1c is 0 and floats at +0xc/+0x10 equal param[0]/param[1]: clear flag (stay 0) else set flag to 1; then store param floats at +0xc/+0x10
void FUN_004c2ba0_recon(void* self, const float* param1) {
    uint8_t* base = static_cast<uint8_t*>(self);
    float* f0 = reinterpret_cast<float*>(base + 0xc);
    float* f1 = reinterpret_cast<float*>(base + 0x10);
    uint8_t* flag = base + 0x1c;
    if ((*flag == 0) && (*f0 == param1[0]) && (*f1 == param1[1])) {
        *flag = 0;
        *f0 = param1[0];
        *f1 = param1[1];
        return;
    }
    *flag = 1;
    *f0 = param1[0];
    *f1 = param1[1];
}

// 0x4c2c00 — compare this float pair (indices 0,1) to param pair; return 0 if both equal, else 1
uint32_t FUN_004c2c00_recon(const float* self, const float* param1) {
    if ((self[0] == param1[0]) && (self[1] == param1[1])) {
        return 0;
    }
    return 1;
}

// 0x4c2c40 — if flag at +0x1c is 0 and float at +8 equals param1: clear flag (stay 0) else set flag to 1; then store param1 at +8
void FUN_004c2c40_recon(void* self, float param1) {
    uint8_t* base = static_cast<uint8_t*>(self);
    float* f = reinterpret_cast<float*>(base + 8);
    uint8_t* flag = base + 0x1c;
    if ((*flag == 0) && (*f == param1)) {
        *flag = 0;
        *f = param1;
        return;
    }
    *flag = 1;
    *f = param1;
}
extern void* PTR_FUN_0070d038;
extern int32_t FUN_00533c78_recon(uint32_t size);
extern int32_t FUN_005426d0_recon();
extern void FUN_005606f0_recon(uint32_t flags, int32_t* localPtr);
extern int32_t FUN_005dbd70_recon();
extern void FUN_00542750_recon();

// 0x4c2c80 — if flag at +0x1c (byte index 7, float-wise) is 0 and floats at [0]/[1] equal param[0]/param[1]: clear flag (stay 0) else set flag to 1; then store param floats at [0]/[1]
void FUN_004c2c80_recon(float* self, const float* param1) {
    uint8_t* flag = reinterpret_cast<uint8_t*>(self) + 0x1c;
    if ((*flag == 0) && (self[0] == param1[0]) && (self[1] == param1[1])) {
        *flag = 0;
        self[0] = param1[0];
        self[1] = param1[1];
        return;
    }
    *flag = 1;
    self[0] = param1[0];
    self[1] = param1[1];
}

// 0x4c2cd0 — if flag at +0x1c is 0 and floats at +0x14/+0x18 equal in_EDX[0]/in_EDX[1]: clear flag (stay 0) else set flag to 1; then store in_EDX floats at +0x14/+0x18
void FUN_004c2cd0_recon(void* self, const float* param1) {
    uint8_t* base = static_cast<uint8_t*>(self);
    float* f0 = reinterpret_cast<float*>(base + 0x14);
    float* f1 = reinterpret_cast<float*>(base + 0x18);
    uint8_t* flag = base + 0x1c;
    if ((*flag == 0) && (*f0 == param1[0]) && (*f1 == param1[1])) {
        *flag = 0;
        *f0 = param1[0];
        *f1 = param1[1];
        return;
    }
    *flag = 1;
    *f0 = param1[0];
    *f1 = param1[1];
}

// 0x4c2d20 — if *(int**)(in_EDI+0x2c) != 0: store in_EBX at *(slot)+0x18; else allocate: FUN_00533c78(0x1c), if nonzero FUN_005426d0() else 0, FUN_005606f0(0,&local), store in_EBX at +0x18
void FUN_004c2d20_recon(void* self, int32_t inEBX, void* inEDI) {
    (void)self;
    uint8_t* edi = static_cast<uint8_t*>(inEDI);
    int32_t slot = *reinterpret_cast<int32_t*>(edi + 0x2c);
    if (slot != 0) {
        *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(slot) + 0x18) = inEBX;
        return;
    }
    int32_t allocated = FUN_00533c78_recon(0x1c);
    int32_t obj = 0;
    if (allocated != 0) {
        obj = FUN_005426d0_recon();
    }
    int32_t local4 = obj;
    FUN_005606f0_recon(0, &local4);
    *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(obj) + 0x18) = inEBX;
}

// 0x4c2d90 — refcounted-assign field at +0xb0 from param_1 (decrement old, delete via deleting-dtor call with flag 1 at zero count; increment new), then if field nonzero and FUN_005dbd70()!=self call vfunc at *(field)+0x34
void FUN_004c2d90_recon(void* self, uint32_t* param1) {
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t** field = reinterpret_cast<uint32_t**>(base + 0xb0);
    uint32_t* old = *field;
    if (old != param1) {
        if (old != nullptr) {
            int32_t* refCount = reinterpret_cast<int32_t*>(old + 1);
            *refCount += -1;
            if (*refCount == 0) {
                using DeletingDtorFn = void(__cdecl*)(uint8_t);
                DeletingDtorFn dtor = reinterpret_cast<DeletingDtorFn>(*old);
                dtor(1);
            }
        }
        *field = param1;
        if (param1 != nullptr) {
            param1[1] += 1;
        }
    }
    if (*field != nullptr && FUN_005dbd70_recon() != reinterpret_cast<int32_t>(self)) {
        uint32_t target = *reinterpret_cast<uint32_t*>(*field);
        using VFn = void(__cdecl*)();
        VFn fn = reinterpret_cast<VFn>(*reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(target) + 0x34));
        fn();
    }
}

// 0x4c2e10 — vftable reset to PTR_FUN_0070d038, call FUN_00542750, conditionally delete self
void FUN_004c2e10_recon(void* self, uint8_t flag) {
    uint32_t** pSelf = reinterpret_cast<uint32_t**>(self);
    *pSelf = reinterpret_cast<uint32_t*>(&PTR_FUN_0070d038);
    FUN_00542750_recon();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

