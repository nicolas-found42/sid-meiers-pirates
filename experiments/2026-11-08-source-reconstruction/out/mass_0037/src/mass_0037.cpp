// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// Batch mass_0037 (retry) — addresses 0x004b0ea0 .. 0x004b20f0.
// No byte-match claim: MSVC 13.10.3077 absent on this host. Status: unverified.
// Corpus labels are kept verbatim: DAT_*/PTR_*/FUN_* are not original names.
// Register receivers (EAX/ECX/EDX/ESI/EDI/EBX) become explicit leading
// parameters; no `this` is used anywhere.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers (corpus labels; arity exactly as observed in the listing).
// Calls whose receiver arrives in a register that Ghidra did not render as an
// argument are reproduced with the observed arity, not with invented args.
// ---------------------------------------------------------------------------
extern "C" int strcmp(const char* a, const char* b);
extern "C" int _stricmp(const char* a, const char* b);
extern "C" void* memmove(void* dst, const void* src, size_t n);

void    FUN_004e6420();
void    operator_delete__(void* p);
void    operator_delete(void* p);
int32_t FUN_00533c78(int32_t size);
int32_t FUN_00503ca0();
void    FUN_00503ef0();
void    FUN_00503fb0(int32_t obj);
void    FUN_00504070(int32_t obj);
void    FUN_00504160();
void    FUN_00508190();
int32_t FUN_00508120();
void    FUN_00508670(int32_t obj, const char* name);
void    FUN_00534130();
void    FUN_00533d10(int32_t a, int32_t b);
void    FUN_00505920();
void    FUN_00506520();
void    FUN_00506040(int32_t a, float b, float c, float d, float e);
void    FUN_00505fc0(float a, float b, float c, float d);
void    FUN_00506e60(int32_t a, int32_t b, float c, float d, float e, float f, int32_t g);
void    FUN_005606f0(int32_t mode, void** slot);
void    FUN_00412f90();
void    FUN_004f3350();
void    FUN_00412df0();
void    FUN_004b2170();
void    FUN_004d2170(const char* name);
void    FUN_004985e0();
void    FUN_004a14b0();
void    FUN_004888e0(int32_t a, int32_t b, int32_t c, float d);

// ---------------------------------------------------------------------------
// Referenced globals (corpus labels; sizes inferred from the observed accesses).
// ---------------------------------------------------------------------------
extern char      DAT_008cacd0[];   // global string buffer (0x004b1130)
extern int32_t   DAT_008caccc;     // current buffer length (0x004b1130)
extern char      DAT_008cacc8[];   // static empty-string sentinel (0x004b12e0)
extern void*     DAT_008cac40;     // owned block (0x004b1ec0)
extern uint8_t   DAT_008cac27;
extern uint32_t  _DAT_0085a164;
extern int32_t   DAT_00726a84;     // live-object counter
extern int32_t   DAT_007263bc;
extern uint32_t  DAT_007268f4[];   // counter-indexed table
extern void*     DAT_00727b28;     // manager object whose vtable[1] is called
extern const char* DAT_008e8fc4[5];          // 0x8e8fc4..0x8e8fd4 (byte span 0x14)
extern void*     DAT_008c9568[3];            // 0x8c9568/0x8c956c/0x8c9570
extern const char* PTR_s_capt_kidd_30pt_fnt_007261f4[]; // font-name table
extern uint8_t   PTR_FUN_0070c0e4; // vtables observed as stored pointers
extern uint8_t   PTR_FUN_0070c100;
extern uint8_t   PTR_FUN_0070c11c;
extern uint8_t   PTR_FUN_0070c4d8;
extern uint8_t   PTR_FUN_007116a0;

// ---------------------------------------------------------------------------
// Observed layouts (offsets are corpus-verbatim; unobserved slots are marked).
// ---------------------------------------------------------------------------
struct StrTable {           // 0x004b0ea0
    void*    unk0;          // +0x00 (not touched by the listing)
    char**   items;         // +0x04
    uint32_t count;         // +0x08
};

struct VtObj {              // 0x004b0f60 / 0x004b0ff0
    void* vtable;           // +0x00
    void* unk4;             // +0x04 (not touched by these listings)
    void* field8;           // +0x08  freed by operator_delete__
};

struct BucketTable {        // 0x004b1050
    void*    vtable;        // +0x00
    uint32_t count;         // +0x04
    void***  buckets;       // +0x08  array of node lists
    uint8_t  flag;          // +0x10
};

// Forward declaration for the intra-batch call from 0x004b17f0.
void FUN_004b1990(void* self, int32_t index);

// ---------------------------------------------------------------------------
// 0x4b0ea0 — observed shape
// Linear search from EAX=index over a string table, comparing against the
// string held by EDX (pointer to the caller's char*). Returns the matching
// index, or 0xffffffff when the scan runs out. The inline byte compare is the
// provider's unsigned strcmp.
// ---------------------------------------------------------------------------
uint32_t FUN_004b0ea0(StrTable* self, uint32_t index, const char** name)
{
    if (index < self->count) {
        char** cur = self->items + index;
        do {
            if (strcmp(*cur, *name) == 0) {
                return index;
            }
            index = index + 1;
            cur = cur + 1;
        } while (index < self->count);
    }
    return 0xffffffffu;
}

// ---------------------------------------------------------------------------
// 0x4b0f10 — observed shape
// EAX and ECX each point at a char*; the two strings are compared bytewise.
// Result is a non-zero flag (the listing returns `sign != 0`).
// ---------------------------------------------------------------------------
int32_t FUN_004b0f10(const char** lhs_eax, const char** rhs_ecx)
{
    return strcmp(*rhs_ecx, *lhs_eax) != 0;
}

// ---------------------------------------------------------------------------
// 0x4b0f60 — observed shape
// ECX = object. Vtable reset, base subobject destroyed via FUN_004e6420,
// +0x08 block released, then flag bit 0 releases the object itself.
// ---------------------------------------------------------------------------
void FUN_004b0f60(VtObj* self, uint8_t flag)
{
    self->vtable = &PTR_FUN_0070c0e4;
    FUN_004e6420();
    operator_delete__(self->field8);
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x4b0fa0 — observed shape
// Same compare as 0x4b0f10 but returns the equality flag (1 when equal).
// ---------------------------------------------------------------------------
int32_t FUN_004b0fa0(const char** lhs_eax, const char** rhs_ecx)
{
    return strcmp(*rhs_ecx, *lhs_eax) == 0;
}

// ---------------------------------------------------------------------------
// 0x4b0ff0 — observed shape
// Two-level destructor: vtable 0x0070c11c, base destroy, vtable 0x0070c0e4,
// base destroy, then +0x08 block release and the flag-bit-0 self delete.
// ---------------------------------------------------------------------------
void FUN_004b0ff0(VtObj* self, uint8_t flag)
{
    self->vtable = &PTR_FUN_0070c11c;
    FUN_004e6420();
    self->vtable = &PTR_FUN_0070c0e4;
    FUN_004e6420();
    operator_delete__(self->field8);
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x4b1050 — observed shape
// Bucket-table teardown: walks every bucket list releasing each node payload
// (node[1]), then runs the two base destructors and frees the bucket array.
// ---------------------------------------------------------------------------
void FUN_004b1050(BucketTable* self)
{
    self->vtable = &PTR_FUN_0070c100;
    if (self->flag != 0 && self->count != 0) {
        uint32_t i = 0;
        do {
            void** node = self->buckets[i];
            while (node != nullptr) {
                void** next = (void**)*node;
                operator_delete__(node[1]);
                node = next;
            }
            i = i + 1;
        } while (i < self->count);
    }
    self->vtable = &PTR_FUN_0070c11c;
    FUN_004e6420();
    self->vtable = &PTR_FUN_0070c0e4;
    FUN_004e6420();
    operator_delete__(self->buckets);
}

// ---------------------------------------------------------------------------
// 0x4b10d0 — observed shape
// Owned critical section: ECX is the CRITICAL_SECTION. Release only when the
// recorded owner is the current thread; the last release leaves the section.
// (Ghidra renders the owner/count pair as the next CRITICAL_SECTION's
// DebugInfo/LockCount fields, i.e. +0x18/+0x1c.)
// ---------------------------------------------------------------------------
void FUN_004b10d0(LPCRITICAL_SECTION self)
{
    PRTL_CRITICAL_SECTION_DEBUG owner =
        (PRTL_CRITICAL_SECTION_DEBUG)(uintptr_t)GetCurrentThreadId();
    if (self[1].DebugInfo == owner) {
        LONG* count = &self[1].LockCount;
        *count = *count + -1;
        if (*count == 0) {
            self[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0;
            LeaveCriticalSection(self);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x4b1100 — observed shape
// Acquire side of the same owned critical section. A non-owner enters the
// section first and records itself; the recursion count always increments.
// ---------------------------------------------------------------------------
void FUN_004b1100(LPCRITICAL_SECTION self)
{
    PRTL_CRITICAL_SECTION_DEBUG owner =
        (PRTL_CRITICAL_SECTION_DEBUG)(uintptr_t)GetCurrentThreadId();
    if (self[1].DebugInfo != owner) {
        EnterCriticalSection(self);
        owner = (PRTL_CRITICAL_SECTION_DEBUG)(uintptr_t)GetCurrentThreadId();
        self[1].DebugInfo = owner;
    }
    self[1].LockCount = self[1].LockCount + 1;
}

// ---------------------------------------------------------------------------
// 0x4b1130 — observed shape
// String-buffer append. EAX points at the caller's string pointer (length
// stored in the provider's [-4] prefix), ECX/param_1/param_2 as listed:
// the first source replaces the buffer, the second is appended, then the
// buffer is re-terminated and FUN_00412df0 runs. Returns param_1.
// ---------------------------------------------------------------------------
uint32_t FUN_004b1130(const char** src_eax, uint32_t param_1, void** param_2)
{
    const char* src = *src_eax;
    size_t len = *(const size_t*)(src - 4);
    if (((int32_t)len >= 0) && (src != nullptr) && (src != DAT_008cacd0)) {
        if (len == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(DAT_008cacd0, src, len);
            DAT_008cacd0[DAT_008caccc] = 0;
        }
    }
    int32_t savedLen = DAT_008caccc;
    const void* src2 = *param_2;
    size_t len2 = *(const size_t*)((const char*)src2 - 4);
    if (((int32_t)len2 > 0) && (DAT_008caccc >= 0) && (src2 != nullptr)) {
        if (DAT_008caccc < (int32_t)(len2 + DAT_008caccc)) {
            FUN_004f3350();
            DAT_008cacd0[DAT_008caccc] = 0;
        }
        memmove(DAT_008cacd0 + savedLen, src2, len2);
    }
    FUN_00412df0();
    return param_1;
}

// ---------------------------------------------------------------------------
// 0x4b1200 — observed shape
// One-slot setter. ESI holds the object base; +0x2c points at a slot whose
// current pointer lives one more indirection down. When the argument differs,
// the old object is released (vtable[0] with flag 1) and FUN_005606f0 is given
// the parameter slot address. No self reference is taken when unchanged.
// ---------------------------------------------------------------------------
void FUN_004b1200(void* self, void* value)
{
    void* slotAddr = *(void**)((uint8_t*)self + 0x2c);
    void** current = (void**)*(void**)slotAddr;
    if (value != (void*)current) {
        if (current != nullptr) {
            void** vt = *(void***)current;
            ((void (__thiscall*)(void*, int))vt[0])(current, 1);
        }
        FUN_005606f0(0, &value);
    }
}

// ---------------------------------------------------------------------------
// 0x4b1230 — observed shape
// Bounds-checked dword getter over the vector reached through self+0x44
// (item array at vector+0x04, element count at vector+0x0c). Out-of-range or
// absent vector yields 0.
// ---------------------------------------------------------------------------
uint32_t FUN_004b1230(void* self, uint32_t index)
{
    int32_t vec = *(int32_t*)((uint8_t*)self + 0x44);
    if ((vec == 0) || (*(uint32_t*)(vec + 0xc) <= index)) {
        return 0;
    }
    return *(uint32_t*)(*(int32_t*)(vec + 4) + (int32_t)index * 4);
}

// ---------------------------------------------------------------------------
// 0x4b1260 — observed shape
// ARGB byte unpack into four floats in the order B, G, R, A with the
// provider's 1/255 constant (0x3b808081 -> 0.003921569f).
// ---------------------------------------------------------------------------
void FUN_004b1260(float* out_eax, uint32_t argb)
{
    out_eax[2] = (float)(argb & 0xff) * 0.003921569f;
    out_eax[1] = (float)((argb >> 8) & 0xff) * 0.003921569f;
    out_eax[0] = (float)((argb >> 0x10) & 0xff) * 0.003921569f;
    out_eax[3] = (float)(argb >> 0x18) * 0.003921569f;
}

// ---------------------------------------------------------------------------
// 0x4b12e0 — observed shape
// Case-insensitive lookup of the string against the five-entry table at
// 0x008e8fc4. In both paths the string header at name-8 is released unless it
// is the static sentinel 0x008cacc8. Returns 1 on a table hit, else 0.
// ---------------------------------------------------------------------------
uint32_t FUN_004b12e0(char* name)
{
    const char** entry = DAT_008e8fc4;
    do {
        if (_stricmp(name, *entry) == 0) {
            char* base = name - 8;
            if ((base != nullptr) && (base != DAT_008cacc8)) {
                operator_delete__(base);
            }
            return 1;
        }
        entry = entry + 1;
    } while (entry < DAT_008e8fc4 + 5);

    char* base = name - 8;
    if ((base != nullptr) && (base != DAT_008cacc8)) {
        operator_delete__(base);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x4b1740 — observed shape
// Object initialiser (EBX = object base). Clears 0x2b dwords at +0x18, the
// three +0xf4/+0xf8/+0xfc words and the selected index (+0x08 = -1), builds
// the +0x14 small object and the +0x10 manager, publishes them into the three
// globals at 0x008c9568, links the small object into the manager (+0x3e dword
// slot) with a temporary reference, then clears 0x2b bytes at +0xc4.
// ---------------------------------------------------------------------------
void FUN_004b1740(void* self)
{
    uint8_t* base = (uint8_t*)self;
    uint32_t* p = (uint32_t*)(base + 0x18);
    for (int32_t n = 0x2b; n != 0; n = n - 1) {
        *p = 0;
        p = p + 1;
    }
    *(uint32_t*)(base + 0xf8) = 0;
    *(uint32_t*)(base + 0xfc) = 0;
    *(uint32_t*)(base + 0xf4) = 0;
    *(uint32_t*)(base + 0x08) = 0xffffffffu;

    uint32_t* small = (uint32_t*)FUN_00533c78(4);
    if (small == nullptr) {
        small = nullptr;
    } else {
        *small = (uint32_t)(uintptr_t)&PTR_FUN_0070c4d8;
    }
    *(uint32_t**)(base + 0x14) = small;

    int32_t block = FUN_00533c78(0x50);
    // The 0x50-byte block is the receiver of the manager constructor; the
    // listing shows the call without explicit arguments.
    uint32_t manager = (block == 0) ? 0u : (uint32_t)FUN_00503ca0();
    *(uint32_t*)(base + 0x10) = manager;

    DAT_008c9568[0] = nullptr;
    DAT_008c9568[1] = nullptr;
    DAT_008c9568[2] = nullptr;

    uint32_t* sub = *(uint32_t**)(*(int32_t*)(base + 0x10) + 4);
    if (sub != nullptr) {
        sub[1] = sub[1] + 1;
    }
    sub[0x3e] = *(uint32_t*)(base + 0x14);
    sub[1] = sub[1] + -1;
    if (sub[1] == 0) {
        void** vt = *(void***)sub;
        ((void (__thiscall*)(void*, int))vt[0])(sub, 1);
    }

    uint32_t* q = (uint32_t*)(base + 0xc4);
    for (int32_t n = 10; n != 0; n = n - 1) {
        *q = 0;
        q = q + 1;
    }
    *(uint16_t*)q = 0;
    *(uint8_t*)((uint8_t*)q + 2) = 0;
}

// ---------------------------------------------------------------------------
// 0x4b17f0 — observed shape
// Slot install for index ECX over the object base in EDX (slots at base+0x18).
// Indices 0xf..0x26 rescale param_3/param_4 before constructing a 0x294-byte
// renderable whose vtable is 0x007116a0 and whose +0xa4 dword is 1. The new
// object is reference-counted into the slot, the activate helper 0x4b1990
// runs, and the selected index additionally triggers the 0x505920/0x506520
// pair and the 0x506040(1,...)/0x505fc0(1,...) state.
// ---------------------------------------------------------------------------
void* FUN_004b17f0(int32_t index, int32_t* self, int32_t param_1, int32_t param_2,
                   int32_t param_3, int32_t param_4, int32_t param_5)
{
    if ((0xe < index) && (index < 0x27)) {
        param_3 = (param_3 << 10) / 0x280;
        param_4 = (param_4 * 0x300) / 0x1e0;
    }

    uint32_t* obj = (uint32_t*)FUN_00533c78(0x294);
    if (obj == nullptr) {
        obj = nullptr;
    } else {
        FUN_00506e60(param_1, param_2, (float)param_3, (float)param_4, (float)param_5,
                     1.0f /* 0x3f800000 */, 0);
        *obj = (uint32_t)(uintptr_t)&PTR_FUN_007116a0;
        *(uint8_t*)((uint8_t*)obj + 0x290) = 1;  // puVar3 + 0xa4 dwords
    }

    uint32_t* old = (uint32_t*)self[index + 6];
    if (old != obj) {
        if (old != nullptr) {
            old[1] = old[1] + -1;
            if (old[1] == 0) {
                void** vt = *(void***)old;
                ((void (__thiscall*)(void*, int))vt[0])(old, 1);
            }
        }
        self[index + 6] = (int32_t)obj;
        if (obj != nullptr) {
            obj[1] = obj[1] + 1;
        }
    }

    FUN_004b1990(self, index);

    if (index == *self) {
        FUN_00505920();
        FUN_00506520();
        FUN_00506040(1, 0.2f /* 0x3e4ccccd */, 0.0f, 0.0f, 1.0f /* 0x3f800000 */);
        FUN_00505fc0(1.0f /* 0x3f800000 */, 0.0f, 0.0f, 1.0f /* 0x3f800000 */);
        return obj;
    }
    FUN_00506040(0, 1.0f /* 0x3f800000 */, 0.0f, 0.0f, 1.0f /* 0x3f800000 */);
    return obj;
}

// ---------------------------------------------------------------------------
// 0x4b1940 — observed shape
// Slot teardown for index EDI over the object base in ESI (slots at +0x18,
// per-slot activation bytes at +0xc4). An active slot is deactivated through
// FUN_00504160 (clearing the selected index when it matches), then the slot
// object is released and the slot zeroed.
// ---------------------------------------------------------------------------
void FUN_004b1940(void* self, int32_t index)
{
    uint8_t* base = (uint8_t*)self;
    if ((*(int32_t*)(base + 0x18 + index * 4) != 0) &&
        (*(uint8_t*)(base + 0xc4 + index) != 0)) {
        if (*(int32_t*)(base + 0x08) == index) {
            *(uint32_t*)(base + 0x08) = 0xffffffffu;
        }
        FUN_00504160();
        *(uint8_t*)(base + 0xc4 + index) = 0;
    }
    uint32_t* obj = *(uint32_t**)(base + 0x18 + index * 4);
    if (obj != nullptr) {
        obj[1] = obj[1] + -1;
        if (obj[1] == 0) {
            void** vt = *(void***)obj;
            ((void (__thiscall*)(void*, int))vt[0])(obj, 1);
        }
        *(uint32_t*)(base + 0x18 + index * 4) = 0;
    }
}

// ---------------------------------------------------------------------------
// 0x4b1990 — observed shape
// Slot activation for index param_1 over the object base in EBX. When the slot
// holds an object that is not yet active: FUN_00503fb0 prepares it, the
// manager's vtable slot at +0x70 receives (slotObject, 1), the two helpers run
// and the +0xc4 activation byte is set.
// ---------------------------------------------------------------------------
void FUN_004b1990(void* self, int32_t index)
{
    uint8_t* base = (uint8_t*)self;
    int32_t obj = *(int32_t*)(base + 0x18 + index * 4);
    if ((obj != 0) && (*(uint8_t*)(base + 0xc4 + index) == 0)) {
        int32_t manager = *(int32_t*)(base + 0x10);
        FUN_00503fb0(obj);
        void* receiver = *(void**)(manager + 4);
        void** vt = *(void***)receiver;
        ((void (__thiscall*)(void*, int, int))*(void**)((uint8_t*)vt + 0x70))
            (receiver, obj, 1);
        FUN_00534130();
        FUN_00533d10(0, 1);
        *(uint8_t*)(base + 0xc4 + index) = 1;
    }
}

// ---------------------------------------------------------------------------
// 0x4b1ec0 — observed shape
// Full subsystem shutdown, gated on the +0x0c byte. Clears the gate, runs the
// two pre-shutdown helpers, walks all 0x2b slots: active slots are detached
// through FUN_00504070 plus the manager's vtable +0x74 entry (whose first
// argument is the parameter slot itself), then every slot object is released.
// Finally the +0xf8 link is released, the 0x008cac40 block is freed, the two
// optional subsystem teardowns run, the +0x0d-gated flag bit is cleared, the
// counter is decremented with the 0x007268f4 table reload, *self becomes -1
// and FUN_004888e0(0x2e,-1,-1,-1.0f) is issued.
// ---------------------------------------------------------------------------
void FUN_004b1ec0(void* self)
{
    uint8_t* base = (uint8_t*)self;
    if (*(uint8_t*)(base + 0x0c) != 0) {
        *(uint8_t*)(base + 0x0c) = 0;
        FUN_004b2170();
        FUN_004d2170("Config.ini");

        int32_t index = 0;
        uint32_t* slot = (uint32_t*)(base + 0x18);
        do {
            if ((*slot != 0) && (*(uint8_t*)(index + 0xc4 + (intptr_t)base) != 0)) {
                if (*(int32_t*)(base + 0x08) == index) {
                    *(uint32_t*)(base + 0x08) = 0xffffffffu;
                }
                int32_t obj = (int32_t)*slot;
                if (obj != 0) {
                    FUN_00504070(obj);
                    void* receiver = *(void**)(obj + 0x24);
                    void** vt = *(void***)receiver;
                    ((void (__thiscall*)(void*, void**, int))
                        *(void**)((uint8_t*)vt + 0x74))(receiver, &self, obj);
                    if (self != nullptr) {
                        uint32_t* ref = (uint32_t*)self;
                        int32_t n = (int32_t)ref[1];
                        ref[1] = (uint32_t)(n - 1);
                        if (n - 1 == 0) {
                            void** vt2 = *(void***)ref;
                            ((void (__thiscall*)(void*, int))vt2[0])(ref, 1);
                        }
                    }
                }
                *(uint8_t*)(index + 0xc4 + (intptr_t)base) = 0;
            }
            uint32_t* obj = (uint32_t*)*slot;
            if (obj != nullptr) {
                obj[1] = obj[1] + -1;
                if (obj[1] == 0) {
                    void** vt = *(void***)obj;
                    ((void (__thiscall*)(void*, int))vt[0])(obj, 1);
                }
                *slot = 0;
            }
            index = index + 1;
            slot = slot + 1;
        } while (index < 0x2b);

        uint32_t* tail = *(uint32_t**)(base + 0x3e * 4);
        if (tail != nullptr) {
            tail[1] = tail[1] + -1;
            if (tail[1] == 0) {
                void** vt = *(void***)tail;
                ((void (__thiscall*)(void*, int))vt[0])(tail, 1);
            }
            *(uint32_t*)(base + 0x3e * 4) = 0;
        }

        if (DAT_008cac40 != nullptr) {
            operator_delete(DAT_008cac40);
            DAT_008cac40 = nullptr;
        }
        if (DAT_008cac27 == 0) {
            FUN_004985e0();
            FUN_004a14b0();
        }
        if (*(uint8_t*)(base + 0x0d) != 0) {
            _DAT_0085a164 = _DAT_0085a164 & 0xfffffffb;
        }
        DAT_00726a84 = DAT_00726a84 + -1;
        DAT_007263bc = (int32_t)DAT_007268f4[DAT_00726a84];
        *(uint32_t*)base = 0xffffffffu;
        FUN_004888e0(0x2e, -1, -1, -1.0f /* 0xbf800000 */);
    }
}

// ---------------------------------------------------------------------------
// 0x4b2040 — observed shape
// Object destructor (EBX = object base): frees the +0x10 manager and its
// release hook, releases the +0x14 object, clears the three global slots at
// 0x008c9568, then walks the +0xfc, +0xf8 and all 0x2b slot objects from
// +0xc0 down to +0x18, dropping one reference each.
// ---------------------------------------------------------------------------
void FUN_004b2040(void* self)
{
    uint8_t* base = (uint8_t*)self;

    void* manager = *(void**)(base + 0x10);
    if (manager != nullptr) {
        FUN_00503ef0();
        operator_delete(manager);
        *(void**)(base + 0x10) = nullptr;
    }

    void* aux = *(void**)(base + 0x14);
    if (aux != nullptr) {
        void** vt = *(void***)aux;
        ((void (__thiscall*)(void*, int))vt[0])(aux, 1);
        *(void**)(base + 0x14) = nullptr;
    }

    void** global = DAT_008c9568;
    do {
        void* block = *global;
        if (block != nullptr) {
            FUN_00508190();
            operator_delete(block);
            *global = nullptr;
        }
        global = global + 1;
    } while (global < DAT_008c9568 + 3);

    uint32_t* tail = *(uint32_t**)(base + 0xfc);
    if (tail != nullptr) {
        tail[1] = tail[1] + -1;
        if (tail[1] == 0) {
            void** vt = *(void***)tail;
            ((void (__thiscall*)(void*, int))vt[0])(tail, 1);
        }
    }
    tail = *(uint32_t**)(base + 0xf8);
    if (tail != nullptr) {
        tail[1] = tail[1] + -1;
        if (tail[1] == 0) {
            void** vt = *(void***)tail;
            ((void (__thiscall*)(void*, int))vt[0])(tail, 1);
        }
    }

    uint8_t* slot = base + 0xc4;
    for (int32_t n = 0x2b; n != 0; n = n - 1) {
        slot = slot - 4;
        uint32_t* obj = *(uint32_t**)slot;
        if (obj != nullptr) {
            obj[1] = obj[1] + -1;
            if (obj[1] == 0) {
                void** vt = *(void***)obj;
                ((void (__thiscall*)(void*, int))vt[0])(obj, 1);
            }
        }
    }
}

// ---------------------------------------------------------------------------
// 0x4b20f0 — observed shape
// Per-index font rebuild (EBX = index): frees the global slot at
// 0x008c9568[index], allocates a 0x68-byte object (FUN_00508120 construction),
// stores it, loads the observed font name through FUN_00508670, then asks the
// 0x00727b28 manager's vtable[1] for (2,0) and stores the result at +0x64.
// ---------------------------------------------------------------------------
void FUN_004b20f0(int32_t index)
{
    void** slot = &DAT_008c9568[index];
    void* old = *slot;
    if (old != nullptr) {
        FUN_00508190();
        operator_delete(old);
        *slot = nullptr;
    }

    int32_t obj = FUN_00533c78(0x68);
    if (obj == 0) {
        obj = 0;
    } else {
        obj = FUN_00508120();
    }
    *slot = (void*)(intptr_t)obj;

    FUN_00508670(obj, PTR_s_capt_kidd_30pt_fnt_007261f4[index]);

    int32_t font = (int32_t)(intptr_t)*slot;
    void* manager = DAT_00727b28;
    void** vt = *(void***)manager;
    uint32_t handle =
        ((uint32_t (__thiscall*)(void*, int, int))*(void**)((uint8_t*)vt + 4))
            (manager, 2, 0);
    *(uint32_t*)(font + 100) = handle;
}
