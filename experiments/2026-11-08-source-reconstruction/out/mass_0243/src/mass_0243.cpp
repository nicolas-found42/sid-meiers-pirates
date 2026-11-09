#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers/globals referenced by the observed listings.
extern char PTR_FUN_006c9950;
extern char PTR_FUN_006c99d8;
extern uint32_t ExceptionList;
extern char LAB_006b9880;
extern char LAB_006b989b;
extern uint32_t DAT_006c99c4[];
extern char DAT_006dd2a4[];
extern uint32_t DAT_007290c8;
extern uint32_t DAT_007291c8[];
extern uint32_t DAT_00729180[];
extern uint32_t DAT_0072915c[];

extern void FUN_005da790(void);
extern uint32_t FUN_005da280(uint32_t param_1);
extern void FUN_005c11d0(uint32_t param_7, int32_t flag);
extern void FUN_005c2c50(uint32_t param_2, uint32_t param_7, int32_t a, int32_t b, int32_t c);
extern void FUN_005c1290(uint32_t param_2, int param_3, uint32_t param_7);
extern int32_t FUN_005e49b0(void);
extern int32_t FUN_005e4760(void);
extern void thunk_FUN_005e6680(void* receiver, uint32_t param_1, uint32_t param_2, int param_3,
                              uint32_t param_4, uint32_t param_5, uint32_t param_6,
                              uint32_t param_7, uint32_t param_8, int32_t field_0x34);
extern void FUN_005da330(void* in_esi, void* retaddr, uint32_t param_1, uint32_t param_2,
                         uint32_t param_3, uint32_t param_4, uint32_t param_5);
extern void FUN_005e6e00(void* self);
extern void FUN_005e1ca0(void* self);
extern void FUN_005e2380(uint32_t field_14);
extern int32_t FUN_005e1b70(uint32_t field_08, uint32_t field_0c);
extern void FUN_005e7150(void* self);
extern void FUN_005d3e10(void* self);
extern void FUN_005d3090(uint32_t idx, uint32_t* local_14);
extern int32_t FUN_00533c78(uint32_t bytes);
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void FUN_005f7bc9(int32_t value, uint32_t out, void* stack_slot);

// 0x5e6e00 — observed shape: self vtable = PTR_FUN_006c9950; call FUN_005da790.
void FUN_005e6e00(void* self) {
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c9950;
    FUN_005da790();
}

// 0x5e6e10 — observed shape: early return if self[7] != 0; else FUN_005da280 gate,
// string-prefix compare vs ""; on mismatch call self vtable +0x4c, then tail check.
uint32_t FUN_005e6e10(void* self, uint32_t param_1) {
    int32_t* fields = reinterpret_cast<int32_t*>(self);
    uint32_t retval = static_cast<uint32_t>(fields[7]);
    if (static_cast<char>(fields[7]) != '\0') {
        return retval;
    }
    uint32_t result = FUN_005da280(param_1);
    if ((static_cast<char>(result) != '\0') && (reinterpret_cast<char*>(fields[2]) != (char*)0x0)) {
        int32_t remaining = 1;
        bool equal = true;
        char* cursor = reinterpret_cast<char*>(fields[2]);
        const char* empty = "";
        do {
            if (remaining == 0) break;
            remaining = remaining + -1;
            equal = (*cursor == *empty);
            cursor = cursor + 1;
            empty = empty + 1;
        } while (equal);
        if (!equal) {
            auto vtable = *reinterpret_cast<void**>(self);
            auto slot = reinterpret_cast<void**>(vtable);
            auto fn = reinterpret_cast<void(*)()>(slot[0x4c / 4]);
            fn();
            result = 0;
            if ((fields[0x19] != 0) && (remaining = fields[0x17], result = 0, remaining != 0)) {
                return static_cast<uint32_t>(retval);
            }
        }
    }
    return result & 0xffffff00u;
}

// 0x5e6ee0 — observed shape: branch on param_3; offsets +0x34/+0x18/+100; loop pattern
// FUN_005e49b0 / thunk_FUN_005e6680 / FUN_005e4760; always returns 0.
uint32_t FUN_005e6ee0(void* self, uint32_t param_1, uint32_t param_2, int param_3,
                      uint32_t param_4, uint32_t param_5, uint32_t param_6,
                      uint32_t param_7, uint32_t param_8) {
    char* base = reinterpret_cast<char*>(self);
    int32_t field_34 = *reinterpret_cast<int32_t*>(base + 0x34);
    void* vtable_18 = *reinterpret_cast<void**>(*reinterpret_cast<void**>(base + 0x18));
    if (param_3 == 0) {
        if (field_34 == 0) {
            auto fn = reinterpret_cast<void(*)(int)>(
                reinterpret_cast<void**>(vtable_18)[0x30 / 4]);
            fn(0);
            FUN_005c11d0(param_7, 1);
        }
    } else {
        if (field_34 == 0) {
            FUN_005c2c50(param_2, param_7, 0, 4, 0);
        }
        uint16_t value = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(param_3) + 0x24);
        auto fn = reinterpret_cast<void(*)(uint32_t)>(
            reinterpret_cast<void**>(vtable_18)[0x30 / 4]);
        fn(value);
        FUN_005c1290(param_2, param_3, param_7);
    }
    int32_t field_100 = *reinterpret_cast<int32_t*>(base + 100);
    (void)field_100;
    int32_t state = FUN_005e49b0();
    while (state != 0) {
        void* receiver = *reinterpret_cast<void**>(base + 100);
        thunk_FUN_005e6680(receiver, param_1, param_2, param_3, param_4, param_5, param_6,
                           param_7, param_8, *reinterpret_cast<int32_t*>(base + 0x34));
        state = FUN_005e4760();
    }
    return 0;
}

// 0x5e6f90 — observed shape: self+0x18 vtable calls +0x88/+0x90/+0x98/+0xa0 then
// FUN_005da330 with two untracked incoming registers first (in_ESI, retaddr).
void FUN_005e6f90(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5) {
    char* base = reinterpret_cast<char*>(self);
    void* vtable = *reinterpret_cast<void**>(*reinterpret_cast<void**>(base + 0x18));
    auto fn88 = reinterpret_cast<uint32_t(*)()>(
        reinterpret_cast<void**>(vtable)[0x88 / 4]);
    uint32_t v88 = fn88();
    auto fn90 = reinterpret_cast<void(*)(uint32_t)>(
        reinterpret_cast<void**>(vtable)[0x90 / 4]);
    fn90(v88);
    void* vtable2 = *reinterpret_cast<void**>(*reinterpret_cast<void**>(base + 0x18));
    auto fn98 = reinterpret_cast<uint32_t(*)()>(
        reinterpret_cast<void**>(vtable2)[0x98 / 4]);
    uint32_t v98 = fn98();
    auto fnA0 = reinterpret_cast<void(*)(uint32_t)>(
        reinterpret_cast<void**>(vtable2)[0xa0 / 4]);
    fnA0(v98);
    FUN_005da330(nullptr, nullptr, param_1, param_2, param_3, param_4, param_5);
}

// 0x5e7000 — observed shape: self+100 vtable +0x104(self+0x38, 3); self+0x34 = 0;
// if *(self+0x38) == 0 call +0x114; return *(self+0x38).
int32_t FUN_005e7000(void* self) {
    char* base = reinterpret_cast<char*>(self);
    int32_t* field_38 = reinterpret_cast<int32_t*>(base + 0x38);
    void* receiver = *reinterpret_cast<void**>(base + 100);
    auto fn104 = reinterpret_cast<void(*)(void*, int32_t*, int)>(
        reinterpret_cast<void**>(receiver)[0x104 / 4]);
    fn104(receiver, field_38, 3);
    *reinterpret_cast<int32_t*>(base + 0x34) = 0;
    if (*field_38 == 0) {
        auto fn114 = reinterpret_cast<void(*)(void*)>(
            reinterpret_cast<void**>(receiver)[0x114 / 4]);
        fn114(receiver);
    }
    return *field_38;
}

// 0x5e7050 — observed shape: self+0x34++; self+100 vtable +0x110; if remaining==0 call +0x114.
int32_t FUN_005e7050(void* self) {
    char* base = reinterpret_cast<char*>(self);
    int32_t new_34 = *reinterpret_cast<int32_t*>(base + 0x34) + 1;
    int32_t remaining = *reinterpret_cast<int32_t*>(base + 0x38) - new_34;
    *reinterpret_cast<int32_t*>(base + 0x34) = new_34;
    void* receiver = *reinterpret_cast<void**>(base + 100);
    auto fn110 = reinterpret_cast<void(*)(void*)>(
        reinterpret_cast<void**>(receiver)[0x110 / 4]);
    fn110(receiver);
    if (remaining == 0) {
        auto fn114 = reinterpret_cast<void(*)(void*)>(
            reinterpret_cast<void**>(receiver)[0x114 / 4]);
        fn114(receiver);
    }
    return remaining;
}

// 0x5e70a0 — observed shape: call FUN_005e6e00; if (param_1 & 1) operator_delete(self).
void FUN_005e70a0(void* self, uint8_t param_1) {
    FUN_005e6e00(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e7100 — observed shape: FUN_005e1ca0; release self+0x60 (+8), clear +0x60/+100/+0x5c;
// release refcounted self+0x24.
void FUN_005e7100(void* self) {
    char* base = reinterpret_cast<char*>(self);
    FUN_005e1ca0(self);
    int32_t* field_60 = *reinterpret_cast<int32_t**>(base + 0x60);
    if (field_60 != (int32_t*)0x0) {
        auto fn8 = reinterpret_cast<void(*)(int32_t*)>(
            reinterpret_cast<void**>(field_60)[8 / 4]);
        fn8(field_60);
        *reinterpret_cast<uint32_t*>(base + 0x60) = 0;
        if (*reinterpret_cast<int32_t*>(base + 100) != 0) {
            *reinterpret_cast<uint32_t*>(base + 100) = 0;
        }
    }
    *reinterpret_cast<uint32_t*>(base + 0x5c) = 0;
    uint32_t* field_24 = *reinterpret_cast<uint32_t**>(base + 0x24);
    if (field_24 != (uint32_t*)0x0) {
        int32_t* count = reinterpret_cast<int32_t*>(field_24 + 1);
        *count = *count + -1;
        if (*count == 0) {
            auto fn0 = reinterpret_cast<void(*)(int)>(
                reinterpret_cast<void**>(field_24)[0]);
            fn0(1);
        }
        *reinterpret_cast<uint32_t*>(base + 0x24) = 0;
    }
}

// 0x5e7150 — observed shape: if self+0x24 == 0, query self+0x60 (+0x14 count),
// allocate count<<4, iterate +0x38/+0x18 collect, sum via FUN_005f7bc9, second pass,
// operator_delete__.
void FUN_005e7150(void* self) {
    char* base = reinterpret_cast<char*>(self);
    uint32_t index = 0;
    if (*reinterpret_cast<int32_t*>(base + 0x24) == 0) {
        uint32_t count = 0;
        uint8_t local_c[12];
        auto fn14 = reinterpret_cast<void(*)(void*, uint32_t, uint8_t*)>(
            reinterpret_cast<void**>(*reinterpret_cast<void**>(base + 0x60))[0x14 / 4]);
        fn14(*reinterpret_cast<void**>(base + 0x60),
             *reinterpret_cast<uint32_t*>(base + 0x5c), local_c);
        count = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(local_c) + 0x14 - 0x0);
        void* buffer = reinterpret_cast<void*>(FUN_00533c78(count << 4));
        int32_t total = 0;
        if (count != 0) {
            int32_t* cursor = reinterpret_cast<int32_t*>(reinterpret_cast<char*>(buffer) + 8);
            do {
                void* iface = *reinterpret_cast<void**>(base + 0x60);
                auto fn38 = reinterpret_cast<uint32_t(*)(void*, uint32_t, uint32_t)>(
                    reinterpret_cast<void**>(iface)[0x38 / 4]);
                uint32_t value = fn38(iface, *reinterpret_cast<uint32_t*>(base + 0x5c), index);
                auto fn18 = reinterpret_cast<void(*)(void*, uint32_t, int32_t*)>(
                    reinterpret_cast<void**>(iface)[0x18 / 4]);
                fn18(iface, value, cursor + -2);
                if (*cursor != 0) {
                    uint32_t extra = 0;
                    FUN_005f7bc9(*cursor, 0, &extra);
                    total = total + static_cast<int32_t>(extra);
                }
                index = index + 1;
                cursor = cursor + 4;
            } while (index < count);
            if (total != 0) {
                uint32_t out = FUN_00533c78(total << 3);
                (void)out;
                index = 0;
                int32_t* second = reinterpret_cast<int32_t*>(reinterpret_cast<char*>(buffer) + 8);
                do {
                    if (*second != 0) {
                        FUN_005f7bc9(*second, out, local_c + -0x24 + 0x24);
                    }
                    index = index + 1;
                    second = second + 4;
                } while (index < count);
                operator_delete__(buffer);
            }
        }
    }
}

// 0x5e7380 — observed shape: replace self+0x24 ref with param_1 (release old,
// AddRef new).
void FUN_005e7380(void* self, uint32_t* param_1) {
    char* base = reinterpret_cast<char*>(self);
    uint32_t* old = *reinterpret_cast<uint32_t**>(base + 0x24);
    if (old != param_1) {
        if (old != (uint32_t*)0x0) {
            int32_t* count = reinterpret_cast<int32_t*>(old + 1);
            *count = *count + -1;
            if (*count == 0) {
                auto fn0 = reinterpret_cast<void(*)(int)>(
                    reinterpret_cast<void**>(old)[0]);
                fn0(1);
            }
        }
        *reinterpret_cast<uint32_t*>(base + 0x24) = reinterpret_cast<uint32_t>(param_1);
        if (param_1 != (uint32_t*)0x0) {
            param_1[1] = param_1[1] + 1;
        }
    }
}

// 0x5e73b0 — observed shape: self+100 vtable +0x108(self+0x34); if self+0x34==0 resolve
// param_2 from param_1+0x28 / ESI path, then +0xa4 or +0xb4; return 0.
uint32_t FUN_005e73b0(void* self, int32_t param_1, int32_t param_2) {
    char* base = reinterpret_cast<char*>(self);
    void* iface = *reinterpret_cast<void**>(base + 100);
    auto fn108 = reinterpret_cast<void(*)(void*, int32_t)>(
        reinterpret_cast<void**>(iface)[0x108 / 4]);
    fn108(iface, *reinterpret_cast<int32_t*>(base + 0x34));
    if (*reinterpret_cast<int32_t*>(base + 0x34) == 0) {
        if (param_2 == 0) {
            if (param_1 == 0) {
                int esi_placeholder = 0;
                // untracked ESI+0xbc path observed in listing
                param_2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(esi_placeholder + 0xbc) + 0x38);
            } else {
                param_2 = *reinterpret_cast<int32_t*>(param_1 + 0x28);
            }
        }
        if (*reinterpret_cast<int32_t*>(param_2 + 8) != 0) {
            auto fnA4 = reinterpret_cast<void(*)(int32_t)>(
                reinterpret_cast<void**>(*reinterpret_cast<void**>(base + 0x18))[0xa4 / 4]);
            fnA4(*reinterpret_cast<int32_t*>(param_2 + 8));
            return 0;
        }
        auto fnB4 = reinterpret_cast<void(*)(uint32_t, int)>(
            reinterpret_cast<void**>(*reinterpret_cast<void**>(base + 0x18))[0xb4 / 4]);
        fnB4(*reinterpret_cast<uint32_t*>(param_2 + 0xc), 0);
    }
    return 0;
}

// 0x5e74d0 — observed shape: resolve self+0x58+0x14 +0x4c; if null call FUN_005e2380;
// set self+0x60, call vtable(0) with DAT_006dd2a4, self+100; FUN_005e1b70 -> self+0x5c.
void FUN_005e74d0(void* self) {
    char* base = reinterpret_cast<char*>(self);
    int32_t helper = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(base + 0x58) + 0x14);
    uint32_t* field = *reinterpret_cast<uint32_t**>(helper + 0x4c);
    if (field == (uint32_t*)0x0) {
        FUN_005e2380(*reinterpret_cast<uint32_t*>(base + 0x14));
        field = *reinterpret_cast<uint32_t**>(helper + 0x4c);
        if (field == (uint32_t*)0x0) {
            return;
        }
    }
    *reinterpret_cast<uint32_t*>(base + 0x60) = reinterpret_cast<uint32_t>(field);
    auto fn0 = reinterpret_cast<void(*)(uint32_t*, void*, void*)>(
        reinterpret_cast<void**>(field)[0]);
    fn0(field, DAT_006dd2a4, base + 100);
    int32_t idx = FUN_005e1b70(*reinterpret_cast<uint32_t*>(base + 8),
                               *reinterpret_cast<uint32_t*>(base + 0xc));
    *reinterpret_cast<uint32_t*>(base + 0x5c) = *reinterpret_cast<uint32_t*>(idx + 0x10);
    FUN_005e7150(self);
}

// 0x5e7530 — observed shape: ExceptionList frame; FUN_005d3e10; *self = PTR_FUN_006c9950;
// self[0x16..0x19]=0; loop FUN_005d3090 while idx < self[0x12].
void FUN_005e7530(void* self) {
    uint32_t* fields = reinterpret_cast<uint32_t*>(self);
    // Exception frame setup observed in listing (ExceptionList / LAB_006b9880).
    (void)ExceptionList;
    FUN_005d3e10(self);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c9950;
    fields[0x16] = 0;
    fields[0x17] = 0;
    fields[0x18] = 0;
    fields[0x19] = 0;
    uint32_t count = fields[0x12];
    if (count != 0) {
        uint32_t local_14[2];
        local_14[0] = 0;
        uint32_t idx = 0;
        do {
            FUN_005d3090(idx, local_14);
            idx = idx + 1;
        } while (idx < count);
    }
}

// 0x5e7770 — observed shape: *self = PTR_FUN_006c99d8; call self[3] vtable +8;
// conditional operator_delete(self).
void FUN_005e7770(void* self, uint8_t param_1_unused) {
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c99d8;
    int32_t* field_3 = reinterpret_cast<int32_t*>(self)[3];
    auto fn8 = reinterpret_cast<void(*)(int32_t*)>(
        reinterpret_cast<void**>(field_3)[8 / 4]);
    fn8(field_3);
    if ((param_1_unused & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e77a0 — observed shape: 4-int compare param_2 vs DAT_006c99c4; if equal call
// *param_3 vtable +4, return 0 else 0x80004002.
uint32_t FUN_005e77a0(uint32_t param_1_unused, int32_t* param_2, uint32_t* param_3) {
    (void)param_1_unused;
    int32_t remaining = 4;
    bool equal = true;
    int32_t* cursor = param_2;
    uint32_t* expected = DAT_006c99c4;
    do {
        if (remaining == 0) break;
        remaining = remaining + -1;
        equal = (*cursor == static_cast<int32_t>(*expected));
        cursor = cursor + 1;
        expected = expected + 1;
    } while (equal);
    if (equal) {
        int32_t* iface = reinterpret_cast<int32_t*>(*param_3);
        auto fn4 = reinterpret_cast<void(*)(int32_t*)>(
            reinterpret_cast<void**>(iface)[4 / 4]);
        fn4(iface);
        return 0;
    }
    return 0x80004002u;
}

// 0x5e7840 — observed shape: self[2]=param_1; *self=PTR_FUN_006c99d8; self[1]=0;
// self[3]=param_2; call param_2 vtable +4.
void FUN_005e7840(void* self, uint32_t param_1, int32_t* param_2) {
    uint32_t* fields = reinterpret_cast<uint32_t*>(self);
    fields[2] = param_1;
    *reinterpret_cast<void**>(self) = &PTR_FUN_006c99d8;
    fields[1] = 0;
    fields[3] = reinterpret_cast<uint32_t>(param_2);
    auto fn4 = reinterpret_cast<void(*)(int32_t*)>(
        reinterpret_cast<void**>(param_2)[4 / 4]);
    fn4(param_2);
}

// 0x5e7870 — observed shape: cached DAT_007290c8; if zero and param_1 with +0x5cc/+0x60
// allocate 0x10, build via FUN_005e7840, cache result.
int32_t FUN_005e7870(int32_t param_1) {
    int32_t cached = static_cast<int32_t>(DAT_007290c8);
    if (cached == 0) {
        if ((param_1 != 0) && (cached = *reinterpret_cast<int32_t*>(param_1 + 0x5cc), cached != 0) &&
            (cached = *reinterpret_cast<int32_t*>(param_1 + 0x60), cached != 0)) {
            int32_t alloc = FUN_00533c78(0x10);
            if (alloc == 0) {
                DAT_007290c8 = 0;
                return 0;
            }
            cached = *reinterpret_cast<int32_t*>(param_1 + 0x5cc);
            int32_t second = *reinterpret_cast<int32_t*>(param_1 + 0x60);
            // Observed: DAT_007290c8 = FUN_005e7840(param_1+0x5cc value, param_1+0x60 value)
            DAT_007290c8 = alloc;
            FUN_005e7840(reinterpret_cast<void*>(alloc), cached, reinterpret_cast<int32_t*>(second));
            return static_cast<int32_t>(DAT_007290c8);
        }
        return 0;
    }
    return cached;
}

// 0x5e7a90 — observed shape: zero DAT_007291c8[0x17]; DAT_007291c8[0]=1; return ptr.
uint32_t* FUN_005e7a90(void) {
    uint32_t* ptr = DAT_007291c8;
    for (int32_t i = 0x17; i != 0; i = i + -1) {
        *ptr = 0;
        ptr = ptr + 1;
    }
    DAT_007291c8[0] = 1;
    return DAT_007291c8;
}

// 0x5e7ab0 — observed shape: zero DAT_00729180[0x12]; DAT_00729180[0]=2; return ptr.
uint32_t* FUN_005e7ab0(void) {
    uint32_t* ptr = DAT_00729180;
    for (int32_t i = 0x12; i != 0; i = i + -1) {
        *ptr = 0;
        ptr = ptr + 1;
    }
    DAT_00729180[0] = 2;
    return DAT_00729180;
}

// 0x5e7ad0 — observed shape: zero 7 dwords at DAT_00729160; DAT_0072915c[0]=3; return ptr.
uint32_t* FUN_005e7ad0(void) {
    uint32_t* base = DAT_0072915c;
    // Offsets: -0x5c..0x78 observed in listing; reproduce as zeroing 7 dwords after header.
    base[1] = 0;
    base[2] = 0;
    base[3] = 0;
    base[4] = 0;
    base[5] = 0;
    base[6] = 0;
    base[7] = 0;
    base[0] = 3;
    return DAT_0072915c;
}
