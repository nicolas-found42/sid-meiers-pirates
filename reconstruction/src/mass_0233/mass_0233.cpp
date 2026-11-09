#include <cstdint>
#include <cstddef>

// Reconstruction of Sid Meier's Pirates! (2004) functions; see TASK.md.

extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006c9308;
extern void* PTR_FUN_006c8e98;
extern void* PTR_FUN_006c936c;
extern int DAT_00727444;
extern void* DAT_00728eac;
extern uint32_t DAT_00729060[];
extern char DAT_00729098;

extern void operator_delete(void* p) noexcept;
extern int FUN_005477c0(int a, int b, const char* fmt, int code);
extern void FUN_005c9080();
extern void FUN_005e0120();
extern void FUN_005ddf50();
extern void FUN_005de4a0(int param_1);
extern void FUN_005de540();

// 0x5ddb00 — bounded 4-byte-stride buffer write with optional old->backup shift
uint32_t FUN_005ddb00(void* self, uint32_t param_1, uint32_t* param_2, uint32_t param_3, char param_4)
{
    uint32_t end = param_1 + param_3;
    if (*(uint32_t*)((char*)self + 0x78) < end) {
        return 0;
    }
    if (param_4 != '\0') {
        uint32_t* src = (uint32_t*)(*(intptr_t*)((char*)self + 0x58) + param_1 * 4);
        uint32_t* dst = (uint32_t*)(*(intptr_t*)((char*)self + 0x5c) + param_1 * 4);
        for (uint32_t i = 0; i < (param_3 & 0x3fffffff); ++i) {
            dst[i] = src[i];
        }
    }
    uint32_t* dst = (uint32_t*)(*(intptr_t*)((char*)self + 0x58) + param_1 * 4);
    for (uint32_t i = 0; i < (param_3 & 0x3fffffff); ++i) {
        dst[i] = param_2[i];
    }
    if (param_1 < *(uint32_t*)((char*)self + 0x68)) {
        *(uint32_t*)((char*)self + 0x68) = param_1;
    }
    if (*(uint32_t*)((char*)self + 0x6c) < end) {
        *(uint32_t*)((char*)self + 0x6c) = end;
    }
    return 1;
}

// 0x5ddb90 — bounded 0x10-byte-stride record write with optional old->backup shift
uint32_t FUN_005ddb90(void* self, uint32_t param_1, uint32_t* param_2, uint32_t param_3, char param_4)
{
    uint32_t end = param_1 + param_3;
    if (*(uint32_t*)((char*)self + 0x28) < end) {
        return 0;
    }
    if (param_4 != '\0') {
        char* src = (char*)(*(intptr_t*)((char*)self + 0x08) + param_1 * 0x10);
        char* dst = (char*)(*(intptr_t*)((char*)self + 0x0c) + param_1 * 0x10);
        for (int32_t i = (int32_t)((param_3 & 0xfffffff) << 2); i != 0; --i) {
            *dst++ = *src++;
        }
    }
    char* dst = (char*)(*(intptr_t*)((char*)self + 0x08) + param_1 * 0x10);
    char* src = (char*)param_2;
    for (int32_t i = (int32_t)((param_3 & 0xfffffff) << 2); i != 0; --i) {
        *dst++ = *src++;
    }
    if (param_1 < *(uint32_t*)((char*)self + 0x18)) {
        *(uint32_t*)((char*)self + 0x18) = param_1;
    }
    if (*(uint32_t*)((char*)self + 0x1c) < end) {
        *(uint32_t*)((char*)self + 0x1c) = end;
    }
    return 1;
}

// 0x5ddc30 — bounded 0x10-byte-stride record write, third channel lane
uint32_t FUN_005ddc30(void* self, uint32_t param_1, uint32_t* param_2, uint32_t param_3, char param_4)
{
    uint32_t end = param_1 + param_3;
    if (*(uint32_t*)((char*)self + 0x50) < end) {
        return 0;
    }
    if (param_4 != '\0') {
        char* src = (char*)(*(intptr_t*)((char*)self + 0x30) + param_1 * 0x10);
        char* dst = (char*)(*(intptr_t*)((char*)self + 0x34) + param_1 * 0x10);
        for (int32_t i = (int32_t)((param_3 & 0xfffffff) << 2); i != 0; --i) {
            *dst++ = *src++;
        }
    }
    char* dst = (char*)(*(intptr_t*)((char*)self + 0x30) + param_1 * 0x10);
    char* src = (char*)param_2;
    for (int32_t i = (int32_t)((param_3 & 0xfffffff) << 2); i != 0; --i) {
        *dst++ = *src++;
    }
    if (param_1 < *(uint32_t*)((char*)self + 0x40)) {
        *(uint32_t*)((char*)self + 0x40) = param_1;
    }
    if (*(uint32_t*)((char*)self + 0x44) < end) {
        *(uint32_t*)((char*)self + 0x44) = end;
    }
    return 1;
}

// 0x5ddcd0 — bounded 4-byte-stride buffer write, second channel lane
uint32_t FUN_005ddcd0(void* self, uint32_t param_1, uint32_t* param_2, uint32_t param_3, char param_4)
{
    uint32_t end = param_1 + param_3;
    if (*(uint32_t*)((char*)self + 0x7c) < end) {
        return 0;
    }
    if (param_4 != '\0') {
        uint32_t* src = (uint32_t*)(*(intptr_t*)((char*)self + 0x60) + param_1 * 4);
        uint32_t* dst = (uint32_t*)(*(intptr_t*)((char*)self + 100) + param_1 * 4);
        for (uint32_t i = 0; i < (param_3 & 0x3fffffff); ++i) {
            dst[i] = src[i];
        }
    }
    uint32_t* dst = (uint32_t*)(*(intptr_t*)((char*)self + 0x60) + param_1 * 4);
    for (uint32_t i = 0; i < (param_3 & 0x3fffffff); ++i) {
        dst[i] = param_2[i];
    }
    if (param_1 < *(uint32_t*)((char*)self + 0x70)) {
        *(uint32_t*)((char*)self + 0x70) = param_1;
    }
    if (*(uint32_t*)((char*)self + 0x74) < end) {
        *(uint32_t*)((char*)self + 0x74) = end;
    }
    return 1;
}

// 0x5ddd60 — bounded 0x10-byte-stride record write, second lane
uint32_t FUN_005ddd60(void* self, uint32_t param_1, uint32_t* param_2, uint32_t param_3, char param_4)
{
    uint32_t end = param_1 + param_3;
    if (*(uint32_t*)((char*)self + 0x2c) < end) {
        return 0;
    }
    if (param_4 != '\0') {
        char* src = (char*)(*(intptr_t*)((char*)self + 0x10) + param_1 * 0x10);
        char* dst = (char*)(*(intptr_t*)((char*)self + 0x14) + param_1 * 0x10);
        for (int32_t i = (int32_t)((param_3 & 0xfffffff) << 2); i != 0; --i) {
            *dst++ = *src++;
        }
    }
    char* dst = (char*)(*(intptr_t*)((char*)self + 0x10) + param_1 * 0x10);
    char* src = (char*)param_2;
    for (int32_t i = (int32_t)((param_3 & 0xfffffff) << 2); i != 0; --i) {
        *dst++ = *src++;
    }
    if (param_1 < *(uint32_t*)((char*)self + 0x20)) {
        *(uint32_t*)((char*)self + 0x20) = param_1;
    }
    if (*(uint32_t*)((char*)self + 0x24) < end) {
        *(uint32_t*)((char*)self + 0x24) = end;
    }
    return 1;
}

// 0x5dde00 — bounded 0x10-byte-stride record write, fourth lane
uint32_t FUN_005dde00(void* self, uint32_t param_1, uint32_t* param_2, uint32_t param_3, char param_4)
{
    uint32_t end = param_1 + param_3;
    if (*(uint32_t*)((char*)self + 0x54) < end) {
        return 0;
    }
    if (param_4 != '\0') {
        char* src = (char*)(*(intptr_t*)((char*)self + 0x38) + param_1 * 0x10);
        char* dst = (char*)(*(intptr_t*)((char*)self + 0x3c) + param_1 * 0x10);
        for (int32_t i = (int32_t)((param_3 & 0xfffffff) << 2); i != 0; --i) {
            *dst++ = *src++;
        }
    }
    char* dst = (char*)(*(intptr_t*)((char*)self + 0x38) + param_1 * 0x10);
    char* src = (char*)param_2;
    for (int32_t i = (int32_t)((param_3 & 0xfffffff) << 2); i != 0; --i) {
        *dst++ = *src++;
    }
    if (param_1 < *(uint32_t*)((char*)self + 0x48)) {
        *(uint32_t*)((char*)self + 0x48) = param_1;
    }
    if (*(uint32_t*)((char*)self + 0x4c) < end) {
        *(uint32_t*)((char*)self + 0x4c) = end;
    }
    return 1;
}

// 0x5ddea0 — constructor: base init, refcount bump, zero fields, owner link, retain
void FUN_005ddea0(void* self, int param_1)
{
    uint32_t* fields = (uint32_t*)self;
    fields[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    fields[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    fields[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c9308;
    for (int i = 2; i <= 0x1f; ++i) fields[i] = 0;
    fields[0x21] = (uint32_t)param_1;
    if (param_1 != 0) {
        fields[0x20] = *(uint32_t*)((char*)(uintptr_t)param_1 + 0x60);
    }
    int* piVar1 = (int*)(uintptr_t)fields[0x20];
    if (piVar1 != nullptr) {
        using RetainFn = void(*)(int*);
        RetainFn fn = *(RetainFn*)((char*)(uintptr_t)piVar1[0] + 4);
        fn(piVar1);
    }
}

// 0x5ddf50 — destructor: free slot arenas, release owned interface, refcount drop
void FUN_005ddf50(void* self)
{
    uint32_t* fields = (uint32_t*)self;
    fields[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c9308;
    operator_delete((void*)(uintptr_t)fields[2]);
    operator_delete((void*)(uintptr_t)fields[3]);
    operator_delete((void*)(uintptr_t)fields[4]);
    operator_delete((void*)(uintptr_t)fields[5]);
    operator_delete((void*)(uintptr_t)fields[0xc]);
    operator_delete((void*)(uintptr_t)fields[0xd]);
    operator_delete((void*)(uintptr_t)fields[0xe]);
    operator_delete((void*)(uintptr_t)fields[0xf]);
    operator_delete((void*)(uintptr_t)fields[0x16]);
    operator_delete((void*)(uintptr_t)fields[0x17]);
    operator_delete((void*)(uintptr_t)fields[0x18]);
    operator_delete((void*)(uintptr_t)fields[0x19]);
    int* piVar1 = (int*)(uintptr_t)fields[0x20];
    if (piVar1 != nullptr) {
        using ReleaseFn = void(*)(int*);
        ReleaseFn fn = *(ReleaseFn*)((char*)(uintptr_t)piVar1[0] + 8);
        fn(piVar1);
        fields[0x20] = 0;
    }
    fields[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
}

// 0x5ddff0 — deleting-destructor wrapper honoring the low-bit flag
void FUN_005ddff0(void* self, uint8_t flags)
{
    FUN_005ddf50(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5de010 — vertex-shader crate: invoke device slot +0x16c, log on failure
uint32_t FUN_005de010(uint32_t param_1)
{
    uint32_t uVar2 = param_1;
    int result;
    {
        void* dev = DAT_00728eac;
        using CreateFn = int(*)(void*, uint32_t, uint32_t*);
        uint32_t out = 0;
        CreateFn fn = *(CreateFn*)((char*)(*(void**)dev) + 0x16c);
        result = fn(dev, param_1, &out);
        uVar2 = out;
    }
    if (result < 0) {
        FUN_005477c0(1, 0, "Failed to create vertex shader\nError 0x%08x\n", result);
        return 0;
    }
    return uVar2;
}

// 0x5de050 — pixel-shader crate: invoke device slot +0x1a8, log on failure
uint32_t FUN_005de050(uint32_t param_1)
{
    uint32_t uVar2 = param_1;
    int result;
    {
        void* dev = DAT_00728eac;
        using CreateFn = int(*)(void*, uint32_t, uint32_t*);
        uint32_t out = 0;
        CreateFn fn = *(CreateFn*)((char*)(*(void**)dev) + 0x1a8);
        result = fn(dev, param_1, &out);
        uVar2 = out;
    }
    if (result < 0) {
        FUN_005477c0(1, 0, "Failed to create pixel shader\nError 0x%08x\n", result);
        return 0;
    }
    return uVar2;
}

// 0x5de090 — guarded vtable release call when +0x24 slot is alive
void FUN_005de090(void* self)
{
    if (*(int*)((char*)self + 0x24) != 0) {
        void* obj = *(void**)((char*)self + 0x1c);
        using CallFn = void(*)();
        CallFn fn = *(CallFn*)((char*)(*(void**)obj) + 0x124);
        fn();
    }
}

// 0x5de0c0 — lazy-init resource table lookup masked to low byte
uint32_t FUN_005de0c0(uint32_t param_1)
{
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return *(uint32_t*)((char*)DAT_00729060 + (param_1 & 0xff) * 4);
}

// 0x5de0e0 — chained teardown: base release, guarded vtable call, final cleanup
void FUN_005de0e0(void* self)
{
    uint32_t* fields = (uint32_t*)self;
    fields[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c8e98;
    FUN_005c9080();
    if (fields[9] != 0) {
        void* obj = (void*)(uintptr_t)fields[7];
        using CallFn = void(*)();
        CallFn fn = *(CallFn*)((char*)(*(void**)obj) + 0x124);
        fn();
    }
    fields[9] = 0;
    FUN_005de540();
}

// 0x5de150 — device-state predicate: table entry equals 3 (self+0x10 key)
bool FUN_005de150(void* self)
{
    uint32_t key = *(uint32_t*)((char*)self + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return *(int32_t*)((char*)DAT_00729060 + (key & 0xff) * 4) == 3;
}

// 0x5de180 — device-state predicate: table entry equals 8 (self+0x10 key)
bool FUN_005de180(void* self)
{
    uint32_t key = *(uint32_t*)((char*)self + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return *(int32_t*)((char*)DAT_00729060 + (key & 0xff) * 4) == 8;
}

// 0x5de1b0 — device-state predicate: table entry equals 9 (self+0x10 key)
bool FUN_005de1b0(void* self)
{
    uint32_t key = *(uint32_t*)((char*)self + 0x10);
    if (DAT_00729098 == '\0') {
        FUN_005e0120();
    }
    return *(int32_t*)((char*)DAT_00729060 + (key & 0xff) * 4) == 9;
}

// 0x5de4a0 — owner rebind: release old interface, retain new, cache +0x5cc field
void FUN_005de4a0(void* self, int param_1)
{
    *(int*)((char*)self + 0x1c) = param_1;
    if (param_1 == 0) {
        int* old = *(int**)((char*)self + 0x18);
        *(uint32_t*)((char*)self + 0x20) = 0;
        if (old != nullptr) {
            using ReleaseFn = void(*)(int*);
            ReleaseFn fn = *(ReleaseFn*)((char*)(*(void**)old) + 8);
            fn(old);
        }
        *(uint32_t*)((char*)self + 0x18) = 0;
        return;
    }
    int* next = *(int**)((char*)(uintptr_t)param_1 + 0x60);
    int* old = *(int**)((char*)self + 0x18);
    if (old != nullptr) {
        using ReleaseFn = void(*)(int*);
        ReleaseFn fn = *(ReleaseFn*)((char*)(*(void**)old) + 8);
        fn(old);
    }
    *(int**)((char*)self + 0x18) = next;
    if (next != nullptr) {
        using RetainFn = void(*)(int*);
        RetainFn fn = *(RetainFn*)((char*)(*(void**)next) + 4);
        fn(next);
    }
    *(uint32_t*)((char*)self + 0x20) = *(uint32_t*)((char*)(uintptr_t)*(int*)((char*)self + 0x1c) + 0x5cc);
}

// 0x5de500 — constructor: base init, zero slots, derived vtable, owner bind
void FUN_005de500(void* self, int param_1)
{
    uint32_t* fields = (uint32_t*)self;
    fields[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    fields[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    for (int i = 2; i <= 8; ++i) fields[i] = 0;
    fields[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c936c;
    FUN_005de4a0(self, param_1);
}

// 0x5de540 — destructor: free slots, release cached interface, refcount drop
void FUN_005de540(void* self)
{
    uint32_t* fields = (uint32_t*)self;
    fields[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c936c;
    operator_delete((void*)(uintptr_t)fields[2]);
    operator_delete((void*)(uintptr_t)fields[3]);
    operator_delete((void*)(uintptr_t)fields[5]);
    int* owned = (int*)(uintptr_t)fields[6];
    fields[7] = 0;
    fields[8] = 0;
    if (owned != nullptr) {
        using ReleaseFn = void(*)(int*);
        ReleaseFn fn = *(ReleaseFn*)((char*)(*(void**)owned) + 8);
        fn(owned);
    }
    fields[6] = 0;
    fields[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 - 1;
}
