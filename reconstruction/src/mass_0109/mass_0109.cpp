#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint32_t FUN_0052b5d0();
extern uint32_t FUN_00527000(const char* text);
extern uint32_t FUN_0052fee0();
extern uint32_t thunk_FUN_00533c78(uint32_t value);
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);

// 0x529680 — observed shape
// Stores the result of FUN_0052b5d0() into *param_1 and returns 1.
uint32_t FUN_00529680(uint32_t* param_1)
{
    *param_1 = FUN_0052b5d0();
    return 1;
}

// 0x529800 — observed shape
// Checks audio-manager init via (self[0] + 0x18) vtable slot; on failure reports
// and masks the return. Otherwise clamps param_1 into self[0x169] (byte offset
// 0x169*4 = 0x5a4) and returns a value whose low byte is 1.
uint32_t FUN_00529800(void* self, float param_1)
{
    int32_t* s = static_cast<int32_t*>(self);
    int32_t vtbl = *s;
    uint32_t avail = (*reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(vtbl + 0x18)))();
    if (static_cast<int8_t>(avail) == 0) {
        return FUN_00527000("The audio manager has not been properly initialized yet") & 0xffffff00u;
    }
    uint32_t upper = (avail >> 16) & 0xffffu;
    if (param_1 < 0.0f) {
        s[0x169] = 0;
    } else if (param_1 < 1.0f || param_1 == 1.0f) {
        if (param_1 < 1.0f) {
            s[0x169] = static_cast<int32_t>(param_1);
        } else {
            s[0x169] = static_cast<int32_t>(param_1);
        }
    } else {
        s[0x169] = 0x3f800000;
    }
    return (upper << 8) | 1u;
}

// 0x5298c0 — observed shape
// Checks audio-manager init via (self[0] + 0x18) vtable slot; on failure reports
// and returns 0. Otherwise calls FUN_0052fee0 and walks two dword ranges
// self[0x161..0x162) and self[0x165..0x166), invoking each element's vtable
// +0x2c slot, then returns 1.
uint32_t FUN_005298c0(void* self)
{
    int32_t* s = static_cast<int32_t*>(self);
    int32_t vtbl = *s;
    int32_t avail = (*reinterpret_cast<int32_t(*)(void)>(*reinterpret_cast<void**>(vtbl + 0x18)))();
    if (avail == 0) {
        FUN_00527000("The audio manager has not been properly initialized yet");
        return 0;
    }
    FUN_0052fee0();
    uint32_t* p1 = reinterpret_cast<uint32_t*>(s[0x161]);
    uint32_t* end1 = reinterpret_cast<uint32_t*>(s[0x162]);
    while (p1 != end1) {
        int32_t elem = static_cast<int32_t>(*p1);
        (*reinterpret_cast<void(*)()>(*reinterpret_cast<void**>(elem + 0x2c)))();
        ++p1;
    }
    uint32_t* p2 = reinterpret_cast<uint32_t*>(s[0x165]);
    uint32_t* end2 = reinterpret_cast<uint32_t*>(s[0x166]);
    while (p2 != end2) {
        int32_t elem = static_cast<int32_t>(*p2);
        (*reinterpret_cast<void(*)()>(*reinterpret_cast<void**>(elem + 0x2c)))();
        ++p2;
    }
    return 1;
}

// 0x529b00 — observed shape
// Adds in_EAX+0x10 to a 64-bit counter at unaff_ESI+0x290 (low) / +0x294 (high)
// with carry, then aligns the total via thunk_FUN_00533c78 and writes a padding
// marker byte at the aligned end.
void FUN_00529b00(void* self, uint32_t in_eax)
{
    uint8_t* esi = static_cast<uint8_t*>(self);
    uint32_t add = in_eax + 0x10;
    uint32_t total_lo = *reinterpret_cast<uint32_t*>(esi + 0x290);
    uint64_t total = (static_cast<uint64_t>(*reinterpret_cast<uint32_t*>(esi + 0x294)) << 32) |
                     static_cast<uint64_t>(total_lo);
    total += add;
    *reinterpret_cast<uint32_t*>(esi + 0x290) = static_cast<uint32_t>(total & 0xffffffffULL);
    *reinterpret_cast<uint32_t*>(esi + 0x294) = static_cast<uint32_t>(total >> 32);
    uint32_t aligned = thunk_FUN_00533c78(add);
    if ((aligned & 0xf) == 0) {
        *reinterpret_cast<uint8_t*>(aligned + 0xf) = 0x10;
        return;
    }
    *reinterpret_cast<int8_t*>((aligned & 0xfffffff0u) + 0xf) =
        static_cast<int8_t>((aligned & 0xffu) + 0x10u) - static_cast<int8_t>(aligned & 0xffu);
    return;
}

// 0x529b50 — observed shape
// Destructor-style cleanup of nine singly-linked pointer chains at
// self+0x74c, +0x750, +0x754 (unconditional), +0x758, +0x75c, +0x760 (only when
// param_1 == 0), and +0x764, +0x768, +0x76c (unconditional). Each chain is
// freed element-by-element with operator_delete then the head with operator_delete__.
void FUN_00529b50(void* self, char param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    const int offsets[] = { 0x74c, 0x750, 0x754 };
    for (int off : offsets) {
        void* head = *reinterpret_cast<void**>(base + off);
        void* node = *reinterpret_cast<void**>(head);
        if (node != nullptr) {
            int idx = 0;
            do {
                operator_delete(node);
                node = *reinterpret_cast<void**>(idx + 4 + *reinterpret_cast<int32_t*>(base + off));
                idx += 4;
            } while (node != nullptr);
        }
        operator_delete__(head);
    }
    if (param_1 == 0) {
        const int cond_offsets[] = { 0x758, 0x75c, 0x760 };
        for (int off : cond_offsets) {
            void* head = *reinterpret_cast<void**>(base + off);
            void* node = *reinterpret_cast<void**>(head);
            if (node != nullptr) {
                int idx = 0;
                do {
                    operator_delete(node);
                    node = *reinterpret_cast<void**>(idx + 4 + *reinterpret_cast<int32_t*>(base + off));
                    idx += 4;
                } while (node != nullptr);
            }
            operator_delete__(head);
        }
    }
    const int tail_offsets[] = { 0x764, 0x768, 0x76c };
    for (int off : tail_offsets) {
        void* head = *reinterpret_cast<void**>(base + off);
        void* node = *reinterpret_cast<void**>(head);
        if (node != nullptr) {
            int idx = 0;
            do {
                operator_delete(node);
                node = *reinterpret_cast<void**>(idx + 4 + *reinterpret_cast<int32_t*>(base + off));
                idx += 4;
            } while (node != nullptr);
        }
        operator_delete__(head);
    }
}

extern int _stricmp(const char* lhs, const char* rhs);
extern int FUN_00529ec0(void* self, const char* text);
extern int FUN_00529f10(void* self, const char* text);
extern int FUN_00529f60(void* self, const char* text);
extern int FUN_00529fb0(void* self, const char* text);
extern int FUN_0052a000(void* self, const char* text);
extern int FUN_0052a060(void* self, const char* text);
extern void FUN_0052a890(uint32_t begin, uint32_t end, uint32_t count);
extern void FUN_0052a980(uint32_t begin, uint32_t end, uint32_t count);
extern char FUN_00531940();
extern char FUN_005337b0();

// 0x529d60 — observed shape
// Dispatches on the selector passed in EAX: 0/1/2 delegate to the name lookups
// for self+0x74c/+0x750/+0x754, 3/4/5 scan the char* tables at
// self+0x758/+0x75c/+0x760 case-insensitively and return the match index,
// 6/7/8 delegate further, and any other value returns -1.
int FUN_00529d60(void* self, uint32_t selector, const char* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    switch (selector) {
    case 0:
        return FUN_00529f60(self, param_1);
    case 1:
        return FUN_00529ec0(self, param_1);
    case 2:
        return FUN_00529f10(self, param_1);
    case 3: {
        char** list = *reinterpret_cast<char***>(base + 0x758);
        int index = 0;
        if (*list != nullptr) {
            do {
                if (_stricmp(param_1, list[index]) == 0) {
                    return index;
                }
                ++index;
            } while (list[index] != nullptr);
        }
        break;
    }
    case 4: {
        char** list = *reinterpret_cast<char***>(base + 0x75c);
        int index = 0;
        if (*list != nullptr) {
            do {
                if (_stricmp(param_1, list[index]) == 0) {
                    return index;
                }
                ++index;
            } while (list[index] != nullptr);
            return 0;
        }
        break;
    }
    case 5: {
        char** list = *reinterpret_cast<char***>(base + 0x760);
        int index = 0;
        if (*list != nullptr) {
            do {
                if (_stricmp(param_1, list[index]) == 0) {
                    return index;
                }
                ++index;
            } while (list[index] != nullptr);
            return 0;
        }
        break;
    }
    case 6:
        return FUN_00529fb0(self, param_1);
    case 7:
        return FUN_0052a000(self, param_1);
    case 8:
        return FUN_0052a060(self, param_1);
    default:
        return -1;
    }
    return 0;
}

// 0x529ec0 — observed shape
// Case-insensitive lookup of param_1 in the char* table at self+0x750; returns
// the matching index or 0 when the table ends (null terminator) first.
int FUN_00529ec0(void* self, const char* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    char** list = *reinterpret_cast<char***>(base + 0x750);
    int index = 0;
    while (true) {
        if (list[index] == nullptr) {
            return 0;
        }
        if (_stricmp(param_1, list[index]) == 0) {
            break;
        }
        list = *reinterpret_cast<char***>(base + 0x750);
        ++index;
    }
    return index;
}

// 0x529f10 — observed shape
// Same lookup as 0x529ec0 but over the char* table at self+0x754.
int FUN_00529f10(void* self, const char* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    char** list = *reinterpret_cast<char***>(base + 0x754);
    int index = 0;
    while (true) {
        if (list[index] == nullptr) {
            return 0;
        }
        if (_stricmp(param_1, list[index]) == 0) {
            break;
        }
        list = *reinterpret_cast<char***>(base + 0x754);
        ++index;
    }
    return index;
}

// 0x529f60 — observed shape
// Same lookup as 0x529ec0 but over the char* table at self+0x74c.
int FUN_00529f60(void* self, const char* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    char** list = *reinterpret_cast<char***>(base + 0x74c);
    int index = 0;
    while (true) {
        if (list[index] == nullptr) {
            return 0;
        }
        if (_stricmp(param_1, list[index]) == 0) {
            break;
        }
        list = *reinterpret_cast<char***>(base + 0x74c);
        ++index;
    }
    return index;
}

// 0x529fb0 — observed shape
// Same lookup as 0x529ec0 but over the char* table at self+0x764.
int FUN_00529fb0(void* self, const char* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    char** list = *reinterpret_cast<char***>(base + 0x764);
    int index = 0;
    while (true) {
        if (list[index] == nullptr) {
            return 0;
        }
        if (_stricmp(param_1, list[index]) == 0) {
            break;
        }
        list = *reinterpret_cast<char***>(base + 0x764);
        ++index;
    }
    return index;
}

// 0x52a000 — observed shape
// Rejects an empty param_1 up front, then performs the case-insensitive lookup
// over the char* table at self+0x768; returns the index or 0.
int FUN_0052a000(void* self, const char* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    if (_stricmp(param_1, "") == 0) {
        return 0;
    }
    char** list = *reinterpret_cast<char***>(base + 0x768);
    if (*list == nullptr) {
        return 0;
    }
    int index = 0;
    do {
        if (_stricmp(param_1, list[index]) == 0) {
            return index;
        }
        list = *reinterpret_cast<char***>(base + 0x768);
        ++index;
    } while (list[index] != nullptr);
    return 0;
}

// 0x52a060 — observed shape
// Same lookup as 0x52a000 but over the char* table at self+0x76c; a miss
// returns -1 instead of 0.
int FUN_0052a060(void* self, const char* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    if (_stricmp(param_1, "") == 0) {
        return 0;
    }
    char** list = *reinterpret_cast<char***>(base + 0x76c);
    if (*list == nullptr) {
        return 0;
    }
    int index = 0;
    do {
        if (_stricmp(param_1, list[index]) == 0) {
            return index;
        }
        list = *reinterpret_cast<char***>(base + 0x76c);
        ++index;
    } while (list[index] != nullptr);
    return -1;
}

// 0x52a140 — observed shape
// Calls FUN_0052a890 over the dword vector [self+0x584, self+0x588), then, when
// the vector is non-empty and EAX is non-zero, asks FUN_00531940 for a veto:
// a set result returns 0 before dispatching the first element's vtable +0xc.
// Otherwise returns 1.
uint32_t FUN_0052a140(void* self, uint32_t in_eax)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t begin = *reinterpret_cast<uint32_t*>(base + 0x584);
    uint32_t end = *reinterpret_cast<uint32_t*>(base + 0x588);
    FUN_0052a890(begin, end, (end - begin) >> 2);
    uint32_t* first = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(begin));
    if (first != nullptr && ((end - begin) >> 2) != 0 && in_eax != 0) {
        void* obj = reinterpret_cast<void*>(static_cast<uintptr_t>(*first));
        void** vtbl = *reinterpret_cast<void***>(obj);
        if (FUN_00531940() != 0) {
            return 0;
        }
        (*reinterpret_cast<void(*)()>(vtbl[0xc / 4]))();
    }
    return 1;
}

// 0x52a1b0 — observed shape
// Mirror of 0x52a140 for the vector [self+0x594, self+0x598) with FUN_0052a980;
// FUN_005337b0 returning zero permits the first element's vtable +0xc call and
// the function then returns 1, otherwise it returns 0. Empty vector or zero EAX
// short-circuits to 1.
uint32_t FUN_0052a1b0(void* self, uint32_t in_eax)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t begin = *reinterpret_cast<uint32_t*>(base + 0x594);
    uint32_t end = *reinterpret_cast<uint32_t*>(base + 0x598);
    FUN_0052a980(begin, end, (end - begin) >> 2);
    if (begin == 0 || ((end - begin) >> 2) == 0 || in_eax == 0) {
        return 1;
    }
    void* obj = *reinterpret_cast<void**>(static_cast<uintptr_t>(begin));
    void** vtbl = *reinterpret_cast<void***>(obj);
    if (FUN_005337b0() == 0) {
        (*reinterpret_cast<void(*)()>(vtbl[0xc / 4]))();
        return 1;
    }
    return 0;
}

// 0x52a220 — observed shape
// Destroys the vector [self+0x584, self+0x588): each iteration re-reads the
// head pointer and invokes the first element's leading vtable slot, so the
// callee is expected to pop the element. Frees the backing store with
// operator_delete and zeroes self+0x584/+0x588/+0x58c.
void FUN_0052a220(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* p = *reinterpret_cast<uint32_t**>(base + 0x584);
    uint32_t* end = *reinterpret_cast<uint32_t**>(base + 0x588);
    if (p != end) {
        do {
            void* obj = reinterpret_cast<void*>(static_cast<uintptr_t>(*p));
            void** vtbl = *reinterpret_cast<void***>(obj);
            (*reinterpret_cast<void(*)()>(vtbl[0]))();
            p = *reinterpret_cast<uint32_t**>(base + 0x584);
        } while (p != *reinterpret_cast<uint32_t**>(base + 0x588));
    }
    if (*reinterpret_cast<void**>(base + 0x584) != nullptr) {
        operator_delete(*reinterpret_cast<void**>(base + 0x584));
    }
    *reinterpret_cast<uint32_t*>(base + 0x584) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x588) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x58c) = 0;
}

// 0x52a280 — observed shape
// Same destruction idiom as 0x52a220 for the vector [self+0x594, self+0x598),
// zeroing self+0x594/+0x598/+0x59c.
void FUN_0052a280(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* p = *reinterpret_cast<uint32_t**>(base + 0x594);
    uint32_t* end = *reinterpret_cast<uint32_t**>(base + 0x598);
    if (p != end) {
        do {
            void* obj = reinterpret_cast<void*>(static_cast<uintptr_t>(*p));
            void** vtbl = *reinterpret_cast<void***>(obj);
            (*reinterpret_cast<void(*)()>(vtbl[0]))();
            p = *reinterpret_cast<uint32_t**>(base + 0x594);
        } while (p != *reinterpret_cast<uint32_t**>(base + 0x598));
    }
    if (*reinterpret_cast<void**>(base + 0x594) != nullptr) {
        operator_delete(*reinterpret_cast<void**>(base + 0x594));
    }
    *reinterpret_cast<uint32_t*>(base + 0x594) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x598) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x59c) = 0;
}

// 0x52a2e0 — observed shape
// Same destruction idiom for the vector [self+0x560, self+0x564), but each
// element is released through vtable slot +0x4; zeroes self+0x560/+0x564/+0x568.
void FUN_0052a2e0(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* p = *reinterpret_cast<uint32_t**>(base + 0x560);
    uint32_t* end = *reinterpret_cast<uint32_t**>(base + 0x564);
    if (p != end) {
        do {
            void* obj = reinterpret_cast<void*>(static_cast<uintptr_t>(*p));
            void** vtbl = *reinterpret_cast<void***>(obj);
            (*reinterpret_cast<void(*)()>(vtbl[1]))();
            p = *reinterpret_cast<uint32_t**>(base + 0x560);
        } while (p != *reinterpret_cast<uint32_t**>(base + 0x564));
    }
    if (*reinterpret_cast<void**>(base + 0x560) != nullptr) {
        operator_delete(*reinterpret_cast<void**>(base + 0x560));
    }
    *reinterpret_cast<uint32_t*>(base + 0x560) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x564) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x568) = 0;
}

// 0x52a340 — observed shape
// Wakes the elements of [param_1[0x161], param_1[0x162)) then of
// [param_1[0x165], param_1[0x166)). Each element is polled through vtable +0x30:
// state 2 calls vtable +0x5c with 1, state 1 clears field 0xe (second loop 0x22),
// any other non-zero state feeds this->vtable +0x14(0) through the element's
// +0x34 and hands the result to +0x60.
void FUN_0052a340(int* param_1)
{
    int32_t* it = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1[0x161]));
    int32_t* end = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1[0x162]));
    if (it != end) {
        do {
            void* obj = reinterpret_cast<void*>(static_cast<uintptr_t>(*it));
            void** vtbl = *reinterpret_cast<void***>(obj);
            int32_t state = (*reinterpret_cast<int32_t(*)()>(vtbl[0x30 / 4]))();
            if (state == 2) {
                (*reinterpret_cast<void(*)(int)>(vtbl[0x5c / 4]))(1);
            } else {
                state = (*reinterpret_cast<int32_t(*)()>(vtbl[0x30 / 4]))();
                if (state == 1) {
                    reinterpret_cast<int32_t*>(obj)[0xe] = 0;
                } else {
                    state = (*reinterpret_cast<int32_t(*)()>(vtbl[0x30 / 4]))();
                    if (state != 0) {
                        void** self_vtbl = *reinterpret_cast<void***>(param_1);
                        float value = (*reinterpret_cast<float(*)(int)>(self_vtbl[0x14 / 4]))(0);
                        float scaled = (*reinterpret_cast<float(*)(float)>(vtbl[0x34 / 4]))(value);
                        (*reinterpret_cast<void(*)(float)>(vtbl[0x60 / 4]))(scaled);
                    }
                }
            }
            ++it;
        } while (it != reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1[0x162])));
    }
    it = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1[0x165]));
    end = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1[0x166]));
    if (it != end) {
        do {
            void* obj = reinterpret_cast<void*>(static_cast<uintptr_t>(*it));
            void** vtbl = *reinterpret_cast<void***>(obj);
            int32_t state = (*reinterpret_cast<int32_t(*)()>(vtbl[0x30 / 4]))();
            if (state == 2) {
                (*reinterpret_cast<void(*)(int)>(vtbl[0x5c / 4]))(1);
            } else {
                state = (*reinterpret_cast<int32_t(*)()>(vtbl[0x30 / 4]))();
                if (state == 1) {
                    reinterpret_cast<int32_t*>(obj)[0x22] = 0;
                } else {
                    state = (*reinterpret_cast<int32_t(*)()>(vtbl[0x30 / 4]))();
                    if (state != 0) {
                        void** self_vtbl = *reinterpret_cast<void***>(param_1);
                        float value = (*reinterpret_cast<float(*)(int)>(self_vtbl[0x14 / 4]))(0);
                        float scaled = (*reinterpret_cast<float(*)(float)>(vtbl[0x34 / 4]))(value);
                        (*reinterpret_cast<void(*)(float)>(vtbl[0x60 / 4]))(scaled);
                    }
                }
            }
            ++it;
        } while (it != reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1[0x166])));
    }
}

// 0x52a460 — observed shape
// Forwards param_1 to the vtable +0x18 slot of every element of
// [self+0x584, self+0x588).
void FUN_0052a460(void* self, uint32_t param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* p = *reinterpret_cast<uint32_t**>(base + 0x584);
    uint32_t* end = *reinterpret_cast<uint32_t**>(base + 0x588);
    while (p != end) {
        void* obj = reinterpret_cast<void*>(static_cast<uintptr_t>(*p));
        void** vtbl = *reinterpret_cast<void***>(obj);
        (*reinterpret_cast<void(*)(uint32_t)>(vtbl[0x18 / 4]))(param_1);
        ++p;
    }
}

// 0x52a490 — observed shape
// Same forward as 0x52a460 for the vector [self+0x594, self+0x598).
void FUN_0052a490(void* self, uint32_t param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* p = *reinterpret_cast<uint32_t**>(base + 0x594);
    uint32_t* end = *reinterpret_cast<uint32_t**>(base + 0x598);
    while (p != end) {
        void* obj = reinterpret_cast<void*>(static_cast<uintptr_t>(*p));
        void** vtbl = *reinterpret_cast<void***>(obj);
        (*reinterpret_cast<void(*)(uint32_t)>(vtbl[0x18 / 4]))(param_1);
        ++p;
    }
}
