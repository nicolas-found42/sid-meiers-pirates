// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// Batch mass_0313 (addresses 0x65b1db..0x65b7b8). No byte-match claim.
// Status: unverified. Globals/callees keep their corpus labels; types inferred.
// Register receivers in_ECX/in_EDX appear as an explicit `self` parameter.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- Observed corpus labels ----
extern uint8_t PTR_FUN_006ee03c[];  // vtable label written into self[0]
extern uint8_t PTR_FUN_006ee048[];  // vtable label written into self[0]
extern uint8_t PTR_FUN_006ee054[];  // vtable label written into self[0]
extern uint8_t PTR_FUN_006ee060[];  // vtable label written into self[0]
extern uint8_t PTR_FUN_006ee06c[];  // vtable label written into self[0]
extern uint8_t PTR_FUN_006ee078[];  // vtable label written into self[0]
extern uint8_t PTR_FUN_006ee084[];  // vtable label written into self[0]

// ---- Observed helpers (signatures inferred from call sites) ----
// Base-object initializer: writes vtable, class id at +4, clears +8/+0xc.
extern void     FUN_0065ab96(void* self, uint32_t class_id);  // receiver (ECX)
// Class-id guard: true when other != null and other->class_id == self->class_id.
extern bool     FUN_0065abb5(void* self, void* other);        // receiver (ECX)
// Virtual equality dispatch: null lhs -> (rhs == null), else lhs->vtable[0](rhs).
extern uint32_t FUN_0065abd0(void* lhs, void* rhs);
// Virtual release/replace: null -> 0, else lhs->vtable[1]().
extern uint32_t FUN_0065abf1(void* obj);
// Tagged-value equality; provider drops both operands (register passthrough).
extern uint32_t FUN_0065ad6e();                               // receiver (ECX), arg (EAX)

// 0x65b1db — observed shape
// NEEDS_MANUAL: the receiver reaches the body only as extraout_EDX (a register
// leftover of FUN_0065ab96); it is expressed here as the explicit `self`.
// Constructor: base id 9, class id 9, variant payload dwords 6..8 cleared, then
// the class vtable is installed.
uint32_t* FUN_0065b1db(void* self)
{
    uint32_t* obj = (uint32_t*)self;

    FUN_0065ab96(self, 9);
    obj[4] = 0;
    obj[6] = 0;
    obj[7] = 0;
    obj[8] = 0;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee03c;
    obj[5] = 9;
    return obj;
}

// 0x65b202 — observed shape
// NEEDS_MANUAL: same extraout_EDX receiver situation as 0x65b1db.
// Constructor: base id 9, five payload fields set verbatim, vtable last.
uint32_t* FUN_0065b202(void* self, uint32_t param_1, uint32_t param_2,
                       uint32_t param_3, uint32_t param_4, uint32_t param_5)
{
    uint32_t* obj = (uint32_t*)self;

    FUN_0065ab96(self, 9);
    obj[4] = param_1;
    obj[5] = param_2;
    obj[6] = param_3;
    obj[7] = param_4;
    obj[8] = param_5;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee03c;
    return obj;
}

// 0x65b23a — observed shape
// NEEDS_MANUAL: the high half of FUN_0065abb5's result is a leftover EDX that
// aliases the argument, so the compared operand is modeled as `other`.
// Equality: class-id guard, then five payload dwords (0x10..0x20) must match.
uint32_t FUN_0065b23a(void* self, void* other)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* rhs = (uint32_t*)other;
    int32_t   iVar1;

    iVar1 = (int32_t)FUN_0065abb5(self, other);
    if ((iVar1 == 0) ||
        (obj[4] != rhs[4]) ||
        (obj[5] != rhs[5]) ||
        ((obj[6] != rhs[6]) || (obj[7] != rhs[7])) ||
        (obj[8] != rhs[8])) {
        return 0;
    }
    return 1;
}

// 0x65b27f — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 10, payload dwords 4..0xf cleared, vtable installed.
uint32_t* FUN_0065b27f(void* self)
{
    uint32_t* obj = (uint32_t*)self;

    FUN_0065ab96(self, 10);
    obj[4] = 0;
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = 0;
    obj[8] = 0;
    obj[9] = 0;
    obj[10] = 0;
    obj[0xb] = 0;
    obj[0xc] = 0;
    obj[0xd] = 0;
    obj[0xe] = 0;
    obj[0xf] = 0;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee048;
    return obj;
}

// 0x65b2b7 — observed shape
// Equality: class-id guard, dword compares 0x10/0x14/0x18/0x38/0x3c, then the
// seven smart-payload fields 0x1c..0x34 via the virtual equality helper.
uint32_t FUN_0065b2b7(void* self, void* other)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* rhs = (uint32_t*)other;
    int32_t   iVar1;

    iVar1 = (int32_t)FUN_0065abb5(self, other);
    if ((iVar1 == 0) ||
        (obj[4] != rhs[4]) ||
        (obj[5] != rhs[5]) ||
        ((obj[6] != rhs[6]) || (obj[0xe] != rhs[0xe])) ||
        ((obj[0xf] != rhs[0xf]) ||
         ((iVar1 = (int32_t)FUN_0065abd0((void*)obj[7], (void*)rhs[7]),
           iVar1 == 0) ||
          (iVar1 = (int32_t)FUN_0065abd0((void*)obj[8], (void*)rhs[8]),
           iVar1 == 0)))) {
        return 0;
    }
    iVar1 = (int32_t)FUN_0065abd0((void*)obj[9], (void*)rhs[9]);
    if ((iVar1 == 0) ||
        (((iVar1 = (int32_t)FUN_0065abd0((void*)obj[10], (void*)rhs[10]),
           iVar1 == 0) ||
          (iVar1 = (int32_t)FUN_0065abd0((void*)obj[0xb], (void*)rhs[0xb]),
           iVar1 == 0)) ||
         (iVar1 = (int32_t)FUN_0065abd0((void*)obj[0xc], (void*)rhs[0xc]),
          iVar1 == 0)) ||
        (iVar1 = (int32_t)FUN_0065abd0((void*)obj[0xd], (void*)rhs[0xd]),
         iVar1 == 0)) {
        return 0;
    }
    return 1;
}

// 0x65b377 — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0xb, payload dwords 4..0xf cleared, vtable installed.
uint32_t* FUN_0065b377(void* self)
{
    uint32_t* obj = (uint32_t*)self;

    FUN_0065ab96(self, 0xb);
    obj[4] = 0;
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = 0;
    obj[8] = 0;
    obj[9] = 0;
    obj[10] = 0;
    obj[0xb] = 0;
    obj[0xc] = 0;
    obj[0xd] = 0;
    obj[0xe] = 0;
    obj[0xf] = 0;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee054;
    return obj;
}

// 0x65b3af — observed shape
// Equality: class-id guard, dword compares 0x10/0x14/0x18/0x1c/0x34, virtual
// equality for 0x20..0x30, then a byte-wise compare of (count<<2) bytes at the
// pointer stored in 0x38 when the count at 0x34 is nonzero.
uint32_t FUN_0065b3af(void* self, void* other)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* rhs = (uint32_t*)other;
    int32_t   iVar1;
    int32_t   remaining;
    char*     pcVar2;
    char*     pcVar3;
    bool      bVar4;

    iVar1 = (int32_t)FUN_0065abb5(self, other);
    if ((((((iVar1 == 0) || (obj[4] != rhs[4])) ||
           (obj[5] != rhs[5])) ||
          ((obj[6] != rhs[6]) || (obj[7] != rhs[7]))) ||
         ((obj[0xd] != rhs[0xd]) ||
          ((iVar1 = (int32_t)FUN_0065abd0((void*)obj[8], (void*)rhs[8]),
            iVar1 == 0) ||
           (iVar1 = (int32_t)FUN_0065abd0((void*)obj[9], (void*)rhs[9]),
            iVar1 == 0)))) ||
        ((iVar1 = (int32_t)FUN_0065abd0((void*)obj[10], (void*)rhs[10]),
          iVar1 == 0) ||
         ((iVar1 = (int32_t)FUN_0065abd0((void*)obj[0xb], (void*)rhs[0xb]),
           iVar1 == 0) ||
          (iVar1 = (int32_t)FUN_0065abd0((void*)obj[0xc], (void*)rhs[0xc]),
           iVar1 == 0)))) {
        return 0;
    }
    if (obj[0xd] != 0) {
        remaining = (int32_t)(obj[0xd] << 2);
        bVar4     = true;
        pcVar2    = (char*)obj[0xe];
        pcVar3    = (char*)rhs[0xe];
        do {
            if (remaining == 0) break;
            remaining = remaining - 1;
            bVar4 = *pcVar2 == *pcVar3;
            pcVar2 = pcVar2 + 1;
            pcVar3 = pcVar3 + 1;
        } while (bVar4);
        if (!bVar4) {
            return 0;
        }
    }
    return 1;
}

// 0x65b469 — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0xc, payload dwords 4..8 cleared, vtable installed.
uint32_t* FUN_0065b469(void* self)
{
    uint32_t* obj = (uint32_t*)self;

    FUN_0065ab96(self, 0xc);
    obj[4] = 0;
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = 0;
    obj[8] = 0;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee060;
    return obj;
}

// 0x65b48c — observed shape
// Equality: class-id guard, dword compare 0x10, then virtual equality for the
// four payload fields 0x14..0x20.
uint32_t FUN_0065b48c(void* self, void* other)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* rhs = (uint32_t*)other;
    int32_t   iVar1;

    iVar1 = (int32_t)FUN_0065abb5(self, other);
    if ((((iVar1 == 0) || (obj[4] != rhs[4])) ||
         (iVar1 = (int32_t)FUN_0065abd0((void*)obj[5], (void*)rhs[5]),
          iVar1 == 0)) ||
        (((iVar1 = (int32_t)FUN_0065abd0((void*)obj[6], (void*)rhs[6]),
           iVar1 == 0) ||
          (iVar1 = (int32_t)FUN_0065abd0((void*)obj[7], (void*)rhs[7]),
           iVar1 == 0)) ||
         (iVar1 = (int32_t)FUN_0065abd0((void*)obj[8], (void*)rhs[8]),
          iVar1 == 0))) {
        return 0;
    }
    return 1;
}

// 0x65b4f3 — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0xd, payload dwords 4..9 cleared, vtable installed,
// mode word 0xa set to 1, then eight dwords at 0xc.. are zero-filled.
uint32_t* FUN_0065b4f3(void* self)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* puVar2;
    int32_t   iVar1;

    FUN_0065ab96(self, 0xd);
    obj[4] = 0;
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = 0;
    obj[8] = 0;
    obj[9] = 0;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee06c;
    obj[10] = 1;
    puVar2 = obj + 0xc;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    return obj;
}

// 0x65b52c — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0xd, five scalar fields 4..0xa set (5/6 cleared first),
// vtable installed, then eight dwords at 0xc.. copied from param_6.
uint32_t* FUN_0065b52c(void* self, uint32_t param_1, uint32_t param_2,
                       uint32_t param_3, uint32_t param_4, uint32_t param_5,
                       uint32_t* param_6)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* puVar2;
    int32_t   iVar1;

    FUN_0065ab96(self, 0xd);
    obj[5] = 0;
    obj[6] = 0;
    obj[4] = param_1;
    obj[7] = param_2;
    obj[8] = param_3;
    obj[9] = param_4;
    obj[10] = param_5;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee06c;
    puVar2 = obj + 0xc;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_6;
        param_6 = param_6 + 1;
        puVar2 = puVar2 + 1;
    }
    return obj;
}

// 0x65b57b — observed shape
// Equality: class-id guard, dword compares 0x14/0x18/0x1c/0x28, the
// FUN_0065ad6e tagged-value check (provider drops its operand registers),
// then virtual equality for 0x10/0x20/0x24.
// NEEDS_MANUAL: FUN_0065ad6e is called with no visible arguments because the
// provider lost its ECX/EAX operand pair; the call is preserved as-is.
uint32_t FUN_0065b57b(void* self, void* other)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* rhs = (uint32_t*)other;
    int32_t   iVar1;

    iVar1 = (int32_t)FUN_0065abb5(self, other);
    if ((((((iVar1 == 0) || (obj[5] != rhs[5])) ||
           (obj[6] != rhs[6])) ||
          ((obj[7] != rhs[7]) || (obj[10] != rhs[10]))) ||
         ((iVar1 = (int32_t)FUN_0065ad6e(), iVar1 == 0) ||
          ((iVar1 = (int32_t)FUN_0065abd0((void*)obj[4], (void*)rhs[4]),
            iVar1 == 0) ||
           (iVar1 = (int32_t)FUN_0065abd0((void*)obj[8], (void*)rhs[8]),
            iVar1 == 0)))) ||
        (iVar1 = (int32_t)FUN_0065abd0((void*)obj[9], (void*)rhs[9]),
         iVar1 == 0)) {
        return 0;
    }
    return 1;
}

// 0x65b5fa — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0xe, vtable installed, scalar fields 4..7 cleared,
// eight dwords at 8.. zeroed, then the kind word at 4 is forced to 3.
uint32_t* FUN_0065b5fa(void* self)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* puVar2;
    int32_t   iVar1;

    FUN_0065ab96(self, 0xe);
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee078;
    obj[4] = 0;
    obj[5] = 0;
    obj[6] = 0;
    obj[7] = 0;
    puVar2 = obj + 8;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    obj[4] = 3;
    return obj;
}

// 0x65b62d — observed shape
// Constructor: base id 0xe, vtable installed, four words copied from the
// value object at param_1, eight dwords at 8.. copied from param_2, and when
// the kind word equals 4 the owned payload at 6 is replaced by its virtual
// release result.
void FUN_0065b62d(void* self, int32_t* param_1, uint32_t* param_2)
{
    uint32_t* obj = (uint32_t*)self;
    int32_t   iVar1;
    uint32_t  uVar2;
    uint32_t* puVar4;
    int32_t   iVar3;

    FUN_0065ab96(self, 0xe);
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee078;
    obj[4] = (uint32_t)param_1[0];
    obj[5] = (uint32_t)param_1[1];
    obj[6] = (uint32_t)param_1[2];
    obj[7] = (uint32_t)param_1[3];
    iVar1  = (int32_t)obj[4];
    puVar4 = obj + 8;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *param_2;
        param_2 = param_2 + 1;
        puVar4 = puVar4 + 1;
    }
    if ((iVar1 == 4) && (obj[6] != 0)) {
        uVar2 = FUN_0065abf1((void*)obj[6]);
        obj[6] = uVar2;
    }
    return;
}

// 0x65b679 — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0xe, scalar fields 4 and 6 set, vtable installed, then
// eight dwords at 8.. copied from param_3.
uint32_t* FUN_0065b679(void* self, uint32_t param_1, uint32_t param_2,
                       uint32_t* param_3)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* puVar2;
    int32_t   iVar1;

    FUN_0065ab96(self, 0xe);
    obj[4] = param_1;
    obj[6] = param_2;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee078;
    puVar2 = obj + 8;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_3;
        param_3 = param_3 + 1;
        puVar2 = puVar2 + 1;
    }
    return obj;
}

// 0x65b6ae — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0xe, an eight-byte pair stored at dword index 6, field
// 4 set, vtable installed, then eight dwords at 8.. copied from param_3.
uint32_t* FUN_0065b6ae(void* self, uint32_t param_1, uint64_t param_2,
                       uint32_t* param_3)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* puVar2;
    int32_t   iVar1;

    FUN_0065ab96(self, 0xe);
    *(uint64_t*)(obj + 6) = param_2;
    obj[4] = param_1;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee078;
    puVar2 = obj + 8;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_3;
        param_3 = param_3 + 1;
        puVar2 = puVar2 + 1;
    }
    return obj;
}

// 0x65b6e3 — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0xe, scalar fields 4/6/7 set, vtable installed, then
// eight dwords at 8.. copied from param_4.
uint32_t* FUN_0065b6e3(void* self, uint32_t param_1, uint32_t param_2,
                       uint32_t param_3, uint32_t* param_4)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* puVar2;
    int32_t   iVar1;

    FUN_0065ab96(self, 0xe);
    obj[4] = param_1;
    obj[6] = param_2;
    obj[7] = param_3;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee078;
    puVar2 = obj + 8;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_4;
        param_4 = param_4 + 1;
        puVar2 = puVar2 + 1;
    }
    return obj;
}

// 0x65b71e — observed shape
// NEEDS_MANUAL: the receiver itself is absent from the listing; the high half
// of FUN_0065abb5's result is a leftover EDX equal to the argument, so the
// block compare uses the true receiver `self` here.
// Equality: class-id guard, four-dword compare at 0x10; when those differ and
// the tag word at 0x10 is 4, the owned payload at 0x18 is compared virtually.
uint32_t FUN_0065b71e(void* self, void* other)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* rhs = (uint32_t*)other;
    uint32_t* piVar4;
    uint32_t* piVar5;
    int32_t   iVar1;
    int32_t   iVar2;
    int32_t   iVar3;
    bool      bVar6;

    iVar1 = (int32_t)FUN_0065abb5(self, other);
    if (iVar1 != 0) {
        piVar4 = rhs + 4;
        iVar1  = (int32_t)*piVar4;
        if (iVar1 == (int32_t)obj[4]) {
            iVar3  = 4;
            bVar6  = true;
            piVar5 = obj + 4;
            do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar6 = *piVar4 == *piVar5;
                piVar4 = piVar4 + 1;
                piVar5 = piVar5 + 1;
            } while (bVar6);
            if ((bVar6) ||
                ((iVar1 == 4 &&
                  (iVar2 = (int32_t)FUN_0065abd0((void*)obj[6], (void*)rhs[6]),
                   iVar2 != 0)))) {
                return 1;
            }
        }
    }
    return 0;
}

// 0x65b78c — observed shape
// NEEDS_MANUAL: extraout_EDX receiver, as in 0x65b1db.
// Constructor: base id 0x10, three scalar fields set, vtable installed.
uint32_t* FUN_0065b78c(void* self, uint32_t param_1, uint32_t param_2,
                       uint32_t param_3)
{
    uint32_t* obj = (uint32_t*)self;

    FUN_0065ab96(self, 0x10);
    obj[4] = param_1;
    obj[5] = param_2;
    obj[6] = param_3;
    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee084;
    return obj;
}

// 0x65b7b8 — observed shape
// Equality: class-id guard, then virtual equality for the three payload fields
// 0x10/0x14/0x18.
uint32_t FUN_0065b7b8(void* self, void* other)
{
    uint32_t* obj = (uint32_t*)self;
    uint32_t* rhs = (uint32_t*)other;
    int32_t   iVar1;

    iVar1 = (int32_t)FUN_0065abb5(self, other);
    if ((((iVar1 == 0) ||
          (iVar1 = (int32_t)FUN_0065abd0((void*)obj[4], (void*)rhs[4]),
           iVar1 == 0)) ||
         (iVar1 = (int32_t)FUN_0065abd0((void*)obj[5], (void*)rhs[5]),
          iVar1 == 0)) ||
        (iVar1 = (int32_t)FUN_0065abd0((void*)obj[6], (void*)rhs[6]),
         iVar1 == 0)) {
        return 0;
    }
    return 1;
}
