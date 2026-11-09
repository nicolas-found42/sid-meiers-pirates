// UNVERIFIED decompiler-derived reconstruction — no build, compiler or test run.
// Sources: analysis/pseudocode/functions/0x65abf1.c .. 0x65b1a8.c (Ghidra 12.2).
#include <cstdint>
#include <cstddef>

// Allocator used by every constructor below.  The provider shows the fresh
// object arriving in EDX; modelled here as an ordinary pointer return.  The
// argument is the tag later stored at 0x04.
extern void* __cdecl FUN_0065ab96(int32_t tag);

// Runtime type test.  Low 32 bits: non-zero when the value has the expected
// type; high 32 bits: the canonical object pointer (see 0x65aef2, 0x65b1a8).
extern uint64_t __cdecl FUN_0065abb5(uintptr_t value);

// Deep equality of two payload values (word or pointer); non-zero when equal.
extern int32_t __cdecl FUN_0065abd0(uintptr_t a, uintptr_t b);

extern void* PTR_FUN_006edfdc;
extern void* PTR_FUN_006edfe8;
extern void* PTR_FUN_006edff4;
extern void* PTR_FUN_006ee000;
extern void* PTR_FUN_006ee00c;
extern void* PTR_FUN_006ee018;
extern void* PTR_FUN_006ee024;
extern void* PTR_FUN_006ee030;

// Common prefix observed across these nodes: vtable at 0x00, tag at 0x04 and
// payload words from 0x08 up to 0x2c.
struct Node {
    void*    vtable;  // 0x00
    int32_t  tag;     // 0x04
    uint32_t w08;     // 0x08
    uint32_t w0c;     // 0x0c
    uint32_t w10;     // 0x10
    uint32_t w14;     // 0x14
    uint32_t w18;     // 0x18
    uint32_t w1c;     // 0x1c
    uint32_t w20;     // 0x20
    uint32_t w24;     // 0x24
    uint32_t w28;     // 0x28
    uint32_t w2c;     // 0x2c
};

// Tagged value compared by 0x65ad6e: type at 0x00, payload at 0x08 held either
// as a word, as a double, or as a wide-character string pointer.
struct VariantValue {
    uint32_t type;  // 0x00
    uint32_t w04;   // 0x04
    union {
        uint32_t        w08;
        double          dbl08;
        const uint16_t* str08;
    };
};

// 0x65abf1 — observed shape: null-checked virtual call through vtable slot 1.
uint32_t FUN_0065abf1(Node* self) {
    uint32_t result;
    if (self == nullptr) {
        result = 0;
    } else {
        typedef uint32_t(__cdecl* Slot1)();
        void** vtbl = reinterpret_cast<void**>(self->vtable);
        result = reinterpret_cast<Slot1>(vtbl[1])();
    }
    return result;
}

// 0x65ac0a — observed shape: append through the 0x0c next-links, walking to the
// tail and storing the new link there; returns the original head (or the value
// itself when the head is null).
uint32_t FUN_0065ac0a(uint32_t head, uint32_t value) {
    uint32_t result = value;
    if (head != 0) {
        uint32_t* link = &head;  // head slot modelled as a local by the provider
        do {
            link = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*link) + 0xc);
        } while (*link != 0);
        *link = value;
        result = head;
    }
    return result;
}

// 0x65ac49 — observed shape: tag 1 allocation, three payload words stored at
// 0x08/0x0c/0x10, vtable 0x006edfdc.
Node* FUN_0065ac49(uint32_t a, uint32_t b, uint32_t c) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(1));
    self->w08 = a;
    self->w0c = b;
    self->w10 = c;
    self->vtable = &PTR_FUN_006edfdc;
    return self;
}

// 0x65ac75 — observed shape: type test, then walk self's 0x0c chain comparing
// each node: tag 1 nodes compare their 0x08 payload and advance the other side
// in lockstep, any other tag is handed to the deep comparison 0x65abd0.
uint32_t FUN_0065ac75(void* self_, void* other_) {
    Node* self = static_cast<Node*>(self_);
    Node* other = static_cast<Node*>(other_);
    uint32_t result = 0;
    if ((int32_t)FUN_0065abb5(reinterpret_cast<uintptr_t>(other_)) != 0) {
        for (Node* node = self; node != nullptr;
             node = reinterpret_cast<Node*>(static_cast<uintptr_t>(node->w0c))) {
            if (node->tag != 1) {
                if (FUN_0065abd0(reinterpret_cast<uintptr_t>(node),
                                 reinterpret_cast<uintptr_t>(other)) == 0) {
                    return 0;
                }
                break;
            }
            if (other == nullptr) {
                return 0;
            }
            if (other->tag != 1) {
                return 0;
            }
            if (FUN_0065abd0(static_cast<uintptr_t>(node->w08),
                             static_cast<uintptr_t>(other->w08)) == 0) {
                return 0;
            }
            other = reinterpret_cast<Node*>(static_cast<uintptr_t>(other->w0c));
        }
        result = 1;
    }
    return result;
}

// 0x65acec — observed shape: tag 2 allocation, payload word at 0x10 first, then
// 0x08 and 0x0c, then 0x14; vtable 0x006edfe8.
Node* FUN_0065acec(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(2));
    self->w10 = a;
    self->w08 = b;
    self->w0c = c;
    self->w14 = d;
    self->vtable = &PTR_FUN_006edfe8;
    return self;
}

// Wide-character compare loop that the listing inlines at each of the three
// string sites of 0x65ad6e: -1/1 at the first difference, 0 when equal.
static int32_t cmp_wide_utf16(const uint16_t* a, const uint16_t* b) {
    for (;;) {
        uint16_t ca = *a;
        uint16_t cb = *b;
        if (ca != cb) {
            return (ca < cb) ? -1 : 1;
        }
        if (ca == 0) {
            return 0;
        }
        uint16_t ca2 = a[1];
        uint16_t cb2 = b[1];
        if (ca2 != cb2) {
            return (ca2 < cb2) ? -1 : 1;
        }
        a += 2;
        b += 2;
        if (ca2 == 0) {
            return 0;
        }
    }
}

// 0x65ad1e — observed shape: type test, word equality at 0x10 and 0x14, then
// deep comparison of the 0x08 and 0x0c payloads.  Receiver in ECX.
bool FUN_0065ad1e(void* self_, const Node* other) {
    const Node* self = static_cast<const Node*>(self_);
    if ((int32_t)FUN_0065abb5(reinterpret_cast<uintptr_t>(other)) == 0) {
        return false;
    }
    if (self->w10 != other->w10) {
        return false;
    }
    if (self->w14 != other->w14) {
        return false;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w08),
                     static_cast<uintptr_t>(other->w08)) == 0) {
        return false;
    }
    return FUN_0065abd0(static_cast<uintptr_t>(self->w0c),
                        static_cast<uintptr_t>(other->w0c)) != 0;
}

// 0x65ad6e — observed shape: deep value comparison of two VariantValue
// receivers arriving in registers (ECX = left, EAX = right).  Types must match
// exactly; then doubles (types 5..8) compare by value, wide strings (types 1, 9,
// 10) by character stream, and all remaining types by the word at 0x08.
// Returns 1 when the values are equal, 0 otherwise.
uint32_t FUN_0065ad6e(void* self_, void* other_) {
    const VariantValue* lhs = static_cast<const VariantValue*>(self_);   // in_ECX
    const VariantValue* rhs = static_cast<const VariantValue*>(other_);  // in_EAX
    uint32_t type = lhs->type;
    if (type != rhs->type) {
        return 0;
    }
    int32_t order = 0;
    if (type < 9) {
        if (type > 4) {
            if (lhs->dbl08 == rhs->dbl08) {
                return 1;
            }
            return 0;
        }
        if (type != 0) {
            if (type == 1) {
                order = cmp_wide_utf16(lhs->str08, rhs->str08);
                return (order == 0) ? 1 : 0;  // LAB_0065adc6 -> LAB_0065ae37
            }
            if (type < 2) {
                return 1;  // unreachable branch kept from the listing
            }
            if (type > 4) {
                return 1;  // unreachable branch kept from the listing
            }
        }
        return (lhs->w08 == rhs->w08) ? 1 : 0;  // LAB_0065ad98
    }
    if (type == 9) {
        order = cmp_wide_utf16(lhs->str08, rhs->str08);
    } else {
        if (type != 10) {
            return 1;
        }
        order = cmp_wide_utf16(lhs->str08, rhs->str08);
    }
    return (order == 0) ? 1 : 0;  // LAB_0065adc6 -> LAB_0065ae37
}

// 0x65ae50 — observed shape: tag 3 allocation, vtable 0x006edff4 written first,
// then eight payload words copied to 0x10..0x2c.
Node* FUN_0065ae50(const uint32_t* src) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(3));
    self->vtable = &PTR_FUN_006edff4;
    uint32_t* dst = reinterpret_cast<uint32_t*>(
        reinterpret_cast<uint8_t*>(self) + 0x10);
    for (int32_t i = 8; i != 0; i = i + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
    }
    return self;
}

// 0x65ae79 — observed shape: type test on the argument, then defer to the deep
// value comparison 0x65ad6e with the receiver as left operand.
bool FUN_0065ae79(void* self, void* param_1) {
    bool equal = false;
    if ((int32_t)FUN_0065abb5(reinterpret_cast<uintptr_t>(param_1)) != 0) {
        equal = FUN_0065ad6e(self, param_1) != 0;
    }
    return equal;
}

// 0x65aec0 — observed shape: tag 4 allocation, payload words at 0x10, 0x14,
// 0x18 and 0x1c; vtable 0x006ee000.
Node* FUN_0065aec0(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(4));
    self->w10 = a;
    self->w14 = b;
    self->w18 = c;
    self->w1c = d;
    self->vtable = &PTR_FUN_006ee000;
    return self;
}

// 0x65aef2 — observed shape: type test whose high word yields the canonical
// object, word equality at 0x10/0x14/0x18, then deep comparison at 0x1c.
bool FUN_0065aef2(void* self_, void* other_) {
    const Node* self = static_cast<const Node*>(self_);
    uint64_t cast = FUN_0065abb5(reinterpret_cast<uintptr_t>(other_));
    const Node* canonical =
        reinterpret_cast<const Node*>(static_cast<uintptr_t>(cast >> 32));
    if ((int32_t)cast == 0) {
        return false;
    }
    if (self->w10 != canonical->w10) {
        return false;
    }
    if (self->w14 != canonical->w14) {
        return false;
    }
    if (self->w18 != canonical->w18) {
        return false;
    }
    return FUN_0065abd0(static_cast<uintptr_t>(self->w1c),
                        static_cast<uintptr_t>(canonical->w1c)) != 0;
}

// 0x65af58 — observed shape: tag 5 allocation, payload words at 0x10, 0x14,
// 0x18, 0x1c and 0x20; vtable 0x006ee00c.
Node* FUN_0065af58(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(5));
    self->w10 = a;
    self->w14 = b;
    self->w18 = c;
    self->w1c = d;
    self->w20 = e;
    self->vtable = &PTR_FUN_006ee00c;
    return self;
}

// 0x65af90 — observed shape: type test, word equality at 0x10 and 0x14, then
// deep comparison of the 0x18, 0x1c and 0x20 payloads in that order.
uint32_t FUN_0065af90(void* self_, const Node* other) {
    const Node* self = static_cast<const Node*>(self_);
    if ((int32_t)FUN_0065abb5(reinterpret_cast<uintptr_t>(other)) == 0) {
        return 0;
    }
    if (self->w10 != other->w10) {
        return 0;
    }
    if (self->w14 != other->w14) {
        return 0;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w18),
                     static_cast<uintptr_t>(other->w18)) == 0) {
        return 0;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w1c),
                     static_cast<uintptr_t>(other->w1c)) == 0) {
        return 0;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w20),
                     static_cast<uintptr_t>(other->w20)) == 0) {
        return 0;
    }
    return 1;
}

// 0x65b01d — observed shape: tag 6 allocation, payload words at 0x10..0x1c,
// then 0x24 = -1, 0x20 = 0, 0x28 = 0, 0x2c = 0; vtable 0x006ee018.
Node* FUN_0065b01d(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(6));
    self->w10 = a;
    self->w14 = b;
    self->w18 = c;
    self->w1c = d;
    self->w24 = 0xffffffff;
    self->w20 = 0;
    self->w28 = 0;
    self->w2c = 0;
    self->vtable = &PTR_FUN_006ee018;
    return self;
}

// 0x65b05e — observed shape: type test, word equality at 0x10, 0x20, 0x24, 0x28
// and 0x2c, then deep comparison of the 0x14, 0x18 and 0x1c payloads.
uint32_t FUN_0065b05e(void* self_, const Node* other) {
    const Node* self = static_cast<const Node*>(self_);
    if ((int32_t)FUN_0065abb5(reinterpret_cast<uintptr_t>(other)) == 0) {
        return 0;
    }
    if (self->w10 != other->w10) {
        return 0;
    }
    if (self->w20 != other->w20) {
        return 0;
    }
    if (self->w24 != other->w24) {
        return 0;
    }
    if (self->w28 != other->w28) {
        return 0;
    }
    if (self->w2c != other->w2c) {
        return 0;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w14),
                     static_cast<uintptr_t>(other->w14)) == 0) {
        return 0;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w18),
                     static_cast<uintptr_t>(other->w18)) == 0) {
        return 0;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w1c),
                     static_cast<uintptr_t>(other->w1c)) == 0) {
        return 0;
    }
    return 1;
}

// 0x65b0f3 — observed shape: tag 7 allocation, payload words at 0x10, 0x14 and
// 0x18; vtable 0x006ee024.
Node* FUN_0065b0f3(uint32_t a, uint32_t b, uint32_t c) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(7));
    self->w10 = a;
    self->w14 = b;
    self->w18 = c;
    self->vtable = &PTR_FUN_006ee024;
    return self;
}

// 0x65b11f — observed shape: type test, word equality at 0x10, then deep
// comparison of the 0x14 and 0x18 payloads.
uint32_t FUN_0065b11f(void* self_, const Node* other) {
    const Node* self = static_cast<const Node*>(self_);
    if ((int32_t)FUN_0065abb5(reinterpret_cast<uintptr_t>(other)) == 0) {
        return 0;
    }
    if (self->w10 != other->w10) {
        return 0;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w14),
                     static_cast<uintptr_t>(other->w14)) == 0) {
        return 0;
    }
    if (FUN_0065abd0(static_cast<uintptr_t>(self->w18),
                     static_cast<uintptr_t>(other->w18)) == 0) {
        return 0;
    }
    return 1;
}

// 0x65b168 — observed shape: tag 8 allocation with both payload words 0x08 and
// 0x0c cleared; vtable 0x006ee030.
Node* FUN_0065b168(void) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(8));
    self->w08 = 0;
    self->w0c = 0;
    self->vtable = &PTR_FUN_006ee030;
    return self;
}

// 0x65b182 — observed shape: tag 8 allocation with the two payload words at
// 0x08 and 0x0c taken from the arguments; same vtable 0x006ee030.
Node* FUN_0065b182(uint32_t a, uint32_t b) {
    Node* self = reinterpret_cast<Node*>(FUN_0065ab96(8));
    self->w08 = a;
    self->w0c = b;
    self->vtable = &PTR_FUN_006ee030;
    return self;
}

// 0x65b1a8 — observed shape: type test whose high word yields the canonical
// object, word equality at 0x14 first, then deep comparison at 0x10.
bool FUN_0065b1a8(void* self_, void* other_) {
    const Node* self = static_cast<const Node*>(self_);
    uint64_t cast = FUN_0065abb5(reinterpret_cast<uintptr_t>(other_));
    const Node* canonical =
        reinterpret_cast<const Node*>(static_cast<uintptr_t>(cast >> 32));
    if ((int32_t)cast == 0) {
        return false;
    }
    if (self->w14 != canonical->w14) {
        return false;
    }
    return FUN_0065abd0(static_cast<uintptr_t>(self->w10),
                        static_cast<uintptr_t>(canonical->w10)) != 0;
}
