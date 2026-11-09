// Reconstruction batch mass_0155 — Sid Meier's Pirates! (2004), PE32 i386.
// Each definition mirrors the observed Ghidra 12.2 pseudocode shape:
// field offsets, constants, call order, and conditional structure.

#include <cstdint>
#include <cstddef>

// ---- shared externs referenced by the listings below -----------------------
void operator_delete(void* p);
void operator_delete__(void* p);
void* FUN_00533c78(unsigned int size);          // thunk_FUN_00533c78 (alloc)
extern uint32_t* DAT_00727d38;                  // global at 0x00727d38
extern uint32_t* DAT_00727d3c;                  // global at 0x00727d3c
void FUN_0055f2c0(void* self);
void FUN_0055f2a0(unsigned char param_1, void* self);

// 0x55f120 — observed shape: refcount decrement on global DAT_00727d38;
// at zero, invoke vtable[0](1); then clear the global pointer.
void FUN_0055f120(void)
{
    uint32_t* ptr = DAT_00727d38;
    if (DAT_00727d38 != nullptr) {
        int32_t count = static_cast<int32_t>(ptr[1]) - 1;
        ptr[1] = count;
        if (count == 0) {
            void** vtable = reinterpret_cast<void**>(*ptr);
            reinterpret_cast<void (*)(int)>(vtable[0])(1);
        }
        DAT_00727d38 = nullptr;
        (void)ptr;
    }
}

// 0x55f200 — observed shape: conditional field-block replace.
// self+0x04: uint16 id, self+0x06: int16 kind, self+0x08/0x0C/0x10: pointers.
// On id change, delete+null all three pointers and store the id; then each
// pointer (and the int16 at +0x06 with +0x10) is replaced only if changed,
// deleting the previous pointer first.
void FUN_0055f200(uint32_t param_1, void* param_2, void* param_3, void* param_4, int16_t param_5, void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint16_t* id_field = reinterpret_cast<uint16_t*>(base + 4);
    int16_t* kind_field = reinterpret_cast<int16_t*>(base + 6);
    void** ptr8 = reinterpret_cast<void**>(base + 8);
    void** ptrC = reinterpret_cast<void**>(base + 0xC);
    void** ptr10 = reinterpret_cast<void**>(base + 0x10);

    if (param_1 != *id_field) {
        operator_delete__(*ptr8);  *ptr8 = nullptr;
        operator_delete__(*ptrC);  *ptrC = nullptr;
        operator_delete__(*ptr10); *ptr10 = nullptr;
        *id_field = static_cast<uint16_t>(param_1);
    }
    if (*ptr8 != param_2) {
        operator_delete__(*ptr8);
        *ptr8 = param_2;
    }
    if (*ptrC != param_3) {
        operator_delete__(*ptrC);
        *ptrC = param_3;
    }
    if ((*ptr10 != param_4) || (*kind_field != param_5)) {
        operator_delete__(*ptr10);
        *ptr10 = param_4;
        *kind_field = param_5;
    }
}

// 0x55f2a0 — observed shape: tail destructor wrapper. Runs FUN_0055f2c0
// on self, then conditionally frees self when (param_1 & 1).
void FUN_0055f2a0(unsigned char param_1, void* self)
{
    FUN_0055f2c0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x55f2c0 — observed shape: recursive owning-node teardown.
// *self points at a counted block (int32 at -1, vtable at 0): if the count
// is 0, free the block; otherwise call vtable[0](3). Then if self[2] is the
// child node, recursively tear it down and free it.
// NEEDS_MANUAL: recursive call receiver is reported bare in the listing;
// reconstructed as a call operating on the child node before operator_delete.
void FUN_0055f2c0(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t** head = reinterpret_cast<int32_t**>(base);
    uint32_t* block = reinterpret_cast<uint32_t*>(*head);
    if (block != nullptr) {
        if (static_cast<int32_t>(block[-1]) == 0) {
            operator_delete__(block - 1);
        } else {
            void* vtable = *reinterpret_cast<void**>(block);
            reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(vtable))(3);
        }
    }
    void* child = reinterpret_cast<void*>(
        *reinterpret_cast<uint32_t*>(base + 8));
    if (child != nullptr) {
        FUN_0055f2c0(child);
        operator_delete(child);
    }
}

// 0x55f300 — observed shape: grow/replace an int32 vector.
// If param_1 != self[1] (capacity), allocate param_1*4 bytes (or null when
// zero), copy the existing self[2] entries from the old buffer, free the old
// buffer, then install the new buffer and store param_1 in self[1].
void FUN_0055f300(int32_t param_1, void* self)
{
    int32_t* vec = static_cast<int32_t*>(self);
    if (param_1 != vec[1]) {
        int32_t* fresh = nullptr;
        if (param_1 != 0) {
            fresh = static_cast<int32_t*>(FUN_00533c78(static_cast<unsigned int>(param_1 * 4)));
            uint32_t written = 0;
            if (vec[2] != 0) {
                do {
                    fresh[written] = (*reinterpret_cast<int32_t*>(vec))[written];
                    written = written + 1;
                } while (written < static_cast<uint32_t>(vec[2]));
            }
        }
        operator_delete__(reinterpret_cast<void*>(*vec));
        vec[0] = reinterpret_cast<int32_t>(fresh);
        vec[1] = param_1;
    }
}

// 0x55f360 — observed shape: scalar deleting destructor for a node with
// a vtable pointer. Resets the vtable to PTR_FUN_006c31e0, frees the
// owned buffer at self[1], and conditionally frees self.
extern void* PTR_FUN_006c31e0;
extern void FUN_004127b0(void* dst, unsigned int elem_size, int count, void* ctor);
extern void* LAT_0055f1e0;

// 0x55f360 — observed shape: scalar deleting destructor for a node with
// a vtable pointer. Resets the vtable to PTR_FUN_006c31e0, frees the
// owned buffer at self[1], and conditionally frees self.
void FUN_0055f360(unsigned char param_1, void* self)
{
    uint32_t* node = static_cast<uint32_t*>(self);
    node[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c31e0);
    operator_delete__(reinterpret_cast<void*>(node[1]));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x55f410 — observed shape: container teardown. Reads the child list at
// self[5], zeroes self[2], tears down the first element's counted block
// (free when count word is 0, else vtable[0](3)), destroys it via
// FUN_0055f2a0(1) when self[2] of the child is nonzero, frees the child,
// and finally frees the buffer at *self.
extern void FUN_0055f2a0(unsigned char, void*);

void FUN_0055f410(void* self)
{
    int32_t* node = static_cast<int32_t*>(self);
    int32_t* child = reinterpret_cast<int32_t*>(node[5]);
    node[2] = 0;
    if (child != nullptr) {
        uint32_t* block = *reinterpret_cast<uint32_t**>(child);
        if (block != nullptr) {
            if (static_cast<int32_t>(block[-1]) == 0) {
                operator_delete__(block - 1);
            } else {
                void* vtable = *reinterpret_cast<void**>(block);
                reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(vtable))(3);
            }
        }
        if (child[2] != 0) {
            FUN_0055f2a0(1, child);
        }
        operator_delete(child);
    }
    operator_delete__(reinterpret_cast<void*>(*node));
}

// 0x55f470 — observed shape: array-of-0x14 layout builder.
// Stores param_1 in self[1] and 0 in self[2]; when param_1 != 0 allocates
// param_1*0x14+4 bytes, stores param_1 in the first word, and runs
// FUN_004127b0 on the following elements (ctor at 0x55f1e0). The result
// pointer (header+1, or null) is stored at *self.
void FUN_0055f470(int32_t param_1, void* self)
{
    int32_t* node = static_cast<int32_t*>(self);
    int32_t* result = nullptr;
    node[1] = param_1;
    node[2] = 0;
    if (param_1 != 0) {
        int32_t* alloc = static_cast<int32_t*>(FUN_00533c78(static_cast<unsigned int>(param_1 * 0x14 + 4)));
        if (alloc != nullptr) {
            result = alloc + 1;
            *alloc = param_1;
            FUN_004127b0(result, 0x14, param_1, &LAT_0055f1e0);
        }
    }
    node[0] = reinterpret_cast<int32_t>(result);
}

// 0x55f560 — observed shape: singleton-style init. Allocates 0x18 bytes
// into DAT_00727d3c and initializes the six words to {0,0,0,8,8,0};
// on allocation failure DAT_00727d3c is null.
void FUN_0055f560(void)
{
    DAT_00727d3c = static_cast<uint32_t*>(FUN_00533c78(0x18));
    if (DAT_00727d3c == nullptr) {
        DAT_00727d3c = nullptr;
        return;
    }
    DAT_00727d3c[0] = 0;
    DAT_00727d3c[1] = 0;
    DAT_00727d3c[2] = 0;
    DAT_00727d3c[3] = 8;
    DAT_00727d3c[4] = 8;
    DAT_00727d3c[5] = 0;
}

// 0x55f5a0 — observed shape: serialization dispatch loop over the entries
// at self+0x60 (count = loop bound). Each round reads the entry, writes
// its uint16 at +4 through the writer at *(param_1+0x160)+0xC, and when
// nonzero writes the fields at +6/+8/+0x10 and repeats FUN_00551a80 /
// FUN_005351e0 calls before restoring the receiver from the stack slot.
// NEEDS_MANUAL: loop bound (ESI), high word (EDI) and inner count (EBP) are
// passed in registers in the listing; modelled as explicit parameters.
struct WriterVec;
void FUN_00556b50(void* self);
void FUN_00551a80(uint32_t param_1);
void FUN_005351e0(uint32_t param_1);

void FUN_0055f5a0(uint32_t param_1, void* self, uint32_t loop_count, uint32_t edi_value, uint32_t ebp_value)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint8_t* entry_base = *reinterpret_cast<uint8_t**>(base + 0x60);
    auto writer = *reinterpret_cast<void**>(*reinterpret_cast<uint32_t*>(param_1 + 0x160));
    auto write_fn = reinterpret_cast<void (*)(void*)>(*reinterpret_cast<void**>(static_cast<uint8_t*>(writer) + 0xC));
    auto write_fn2 = reinterpret_cast<void (*)(void*, int)>(*reinterpret_cast<void**>(static_cast<uint8_t*>(writer) + 0xC));
    (void)write_fn; (void)write_fn2;
    uint32_t out = param_1;
    // Preamble mirroring the listing's stack temporaries.
    FUN_00556b50(self);
    uint32_t slot_2c = 1;
    uint32_t slot_20 = static_cast<uint32_t>(base[0x54]);
    if (loop_count != 0) {
        uint32_t index = 0;
        do {
            uint32_t entry = *reinterpret_cast<uint32_t*>(entry_base + index * 4);
            if (entry == 0) {
                slot_2c = 0;
            } else {
                slot_2c = *reinterpret_cast<uint16_t*>(entry + 4);
            }
            if (static_cast<int16_t>(slot_2c) != 0) {
                slot_20 = *reinterpret_cast<uint32_t*>(entry + 0x10);
                uint32_t kind = *reinterpret_cast<uint16_t*>(entry + 6);
                uint32_t flag = (*reinterpret_cast<uint32_t*>(entry + 8) != 0) ? 1 : 0;
                (void)kind; (void)flag;
                if (static_cast<char>(slot_20) != '\0') {
                    uint32_t n = 0;
                    do {
                        FUN_00551a80(param_1);
                        n = n + 1;
                    } while (n < 4);
                }
                if ((static_cast<char>(edi_value >> 0x10) != '\0') && ((ebp_value & 0xFFFF) != 0)) {
                    uint32_t m = 0;
                    do {
                        FUN_005351e0(param_1);
                        m = m + 1;
                    } while (m < (ebp_value & 0xFFFF));
                }
                if ((static_cast<int16_t>(slot_20) != 0)) {
                    int32_t total = static_cast<int32_t>(kind & 0xFFFF) * static_cast<int32_t>(slot_2c & 0xFFFF);
                    while (total != 0) {
                        FUN_00551a80(param_1);
                        total = total - 1;
                    }
                }
                (void)out;
            }
            index = index + 1;
        } while (index < loop_count);
    }
}
// 0x55f750 — observed shape: two container equality predicates combined.
// Early-returns 0 when FUN_005567d0 reports no difference, or when the
// bytes/ints at +0x54/+0x6C/+0x68 differ. Otherwise walks the entry
// tables at +0x60: null/non-null mismatches and differing uint16 fields
// at +4/+6 cause a failure return; nested 8/16-byte payload comparisons
// via FUN_004c2c00 / FUN_0050b0f0 are checked per sub-element. On a full
// match, returns the index with low byte 1 (CONCAT31 with (uVar4>>8),1).
// NEEDS_MANUAL: the elided middle (lines 45-98) was reconstructed from a
// ranged re-read; FPU/concat helpers are modelled as plain integer ops.
uint32_t FUN_005567d0(int param_1);
uint32_t FUN_004c2c00(int addr);
uint32_t FUN_0050b0f0(int addr);

uint32_t FUN_0055f750(int param_1, void* self, uint32_t count)
{
    uint8_t* me = static_cast<uint8_t*>(self);
    uint8_t* other = reinterpret_cast<uint8_t*>(param_1);
    uint32_t cmp = FUN_005567d0(param_1);
    if ((static_cast<char>(cmp) == '\0') ||
        (cmp = (cmp & 0xFFFFFF00u) | other[0x54], other[0x54] != me[0x54]) ||
        (cmp = *reinterpret_cast<uint32_t*>(other + 0x6C), cmp != *reinterpret_cast<uint32_t*>(me + 0x6C)) ||
        (*reinterpret_cast<int32_t*>(other + 0x68) != *reinterpret_cast<int32_t*>(me + 0x68))) {
        return cmp & 0xFFFFFF00u;
    }
    uint32_t seen = 0;
    if (count == 0) {
        return (seen & 0xFFFFFF00u) | 1u;
    }
    int32_t* mine_table = *reinterpret_cast<int32_t**>(me + 0x60);
    int32_t table_delta = *reinterpret_cast<int32_t*>(other + 0x60) - reinterpret_cast<int32_t>(mine_table);
    for (;;) {
        uint32_t other_entry = *reinterpret_cast<uint32_t*>(table_delta + reinterpret_cast<int32_t>(mine_table));
        uint32_t my_entry = static_cast<uint32_t>(*mine_table);
        if (other_entry == 0) {
            if (my_entry != 0) {
                return other_entry & 0xFFFFFF00u;
            }
        } else {
            if (my_entry == 0) {
                return other_entry & 0xFFFFFF00u;
            }
            uint32_t rows = *reinterpret_cast<uint16_t*>(other_entry + 4);
            uint32_t cols = *reinterpret_cast<uint16_t*>(other_entry + 6);
            if ((rows != *reinterpret_cast<uint16_t*>(my_entry + 4)) ||
                (cols != *reinterpret_cast<uint16_t*>(my_entry + 6))) {
                return other_entry & 0xFFFFFF00u;
            }
            int32_t payload_a = *reinterpret_cast<int32_t*>(other_entry + 8);
            int32_t payload_b = *reinterpret_cast<int32_t*>(other_entry + 0xC);
            int32_t payload_c = *reinterpret_cast<int32_t*>(other_entry + 0x10);
            int32_t payload_d = *reinterpret_cast<int32_t*>(my_entry + 0x10);
            if (rows != 0) {
                int32_t delta_a = *reinterpret_cast<int32_t*>(my_entry + 8) - payload_a;
                int32_t delta_b = *reinterpret_cast<int32_t*>(my_entry + 0xC) - payload_b;
                int32_t cursor = payload_c;
                uint32_t r = 0;
                do {
                    uint32_t res = FUN_004c2c00(delta_a + payload_a);
                    if ((static_cast<char>(res) != '\0') ||
                        (res = FUN_0050b0f0(delta_b + payload_b), static_cast<char>(res) != '\0')) {
                        return other_entry & 0xFFFFFF00u;
                    }
                    uint32_t c = 0;
                    if (cols != 0) {
                        int32_t cell = cursor;
                        do {
                            uint32_t cell_res = FUN_004c2c00((payload_d - payload_c) + cell);
                            if (static_cast<char>(cell_res) != '\0') {
                                return other_entry & 0xFFFFFF00u;
                            }
                            c = c + 1;
                            cell = cell + 8;
                        } while (c < cols);
                    }
                    cursor = cursor + static_cast<int32_t>(cols * 8);
                    payload_a = payload_a + 8;
                    payload_b = payload_b + 0x10;
                    r = r + 1;
                } while (r < rows);
            }
        }
        seen = seen + 1;
        mine_table = mine_table + 1;
        if (count <= seen) {
            return (seen & 0xFFFFFF00u) | 1u;
        }
    }
}

// 0x55f930 — observed shape: builds a 0xC-node via FUN_0055f470(param_1),
// then fills the self vector (self[0]/[1]/[2]) with pointers stepping
// 0x14 through the new array, growing with FUN_0055f300 when full
// (1 when empty, else double). Links the node into self[5] at the end:
// local_4[2] takes the old self[5], self[5] takes local_4.
// NEEDS_MANUAL: the 0xC allocation result feeds local_4 through
// FUN_0055f470(p1); the vector-buffer pointer at *self is carried as int.
extern void FUN_0055f470(int32_t param_1, void* self);
extern void FUN_0055f300(int32_t param_1, void* self);

void FUN_0055f930(uint32_t param_1, void* self)
{
    int32_t* vec = static_cast<int32_t*>(self);
    int32_t* node = nullptr;
    if (FUN_00533c78(0xC) != nullptr) {
        node = static_cast<int32_t*>(FUN_00533c78(0xC));
        FUN_0055f470(static_cast<int32_t>(param_1), node);
    }
    uint32_t index = 0;
    int32_t offset = 0;
    if (param_1 != 0) {
        do {
            int32_t slot;
            if (index < static_cast<uint32_t>(node[1])) {
                slot = *node + offset;
            } else {
                slot = 0;
            }
            int32_t cap = vec[1];
            if (vec[2] == cap) {
                if (cap == 0) {
                    cap = 1;
                } else {
                    cap = cap * 2;
                }
                FUN_0055f300(cap, self);
            }
            *reinterpret_cast<int32_t*>(*vec + vec[2] * 4) = slot;
            vec[2] = vec[2] + 1;
            index = index + 1;
            offset = offset + 0x14;
        } while (index < param_1);
    }
    node[2] = vec[5];
    vec[5] = reinterpret_cast<int32_t>(node);
}

// 0x55f9d0 — observed shape: destroys the DAT_00727d3c object when it
// exists: FUN_0055f410 on it, then operator_delete of the saved pointer.
void FUN_0055f9d0(void)
{
    void* obj = DAT_00727d3c;
    if (DAT_00727d3c != nullptr) {
        FUN_0055f410(obj);
        operator_delete(obj);
    }
}

// 0x55fab0 — observed shape: clears the pointer table at self+0x60
// (count at +0x68, running balance at +0x6C, capacity word at +100).
// Entries inside the capacity that are nonzero decrement the balance at
// +0x6C, entries at/after capacity shorten the count at +0x68; every entry
// is zeroed, and nonzero entries are passed through FUN_0055f200(0,0,0,0,0)
// and FUN_005bf090 before being forgotten.
// NEEDS_MANUAL: loop bound at +0x68 evolves in the body; the grow-check at
// +100 is compared against the loop index exactly as listed.
extern void FUN_005bf090(void* p);
extern void FUN_0055f200(uint32_t, void*, void*, void*, int16_t, void*);

void FUN_0055fab0(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t index = 0;
    int32_t slot = reinterpret_cast<int32_t>(self);
    (void)slot;
    if (*reinterpret_cast<int32_t*>(base + 0x68) != 0) {
        do {
            uint32_t table_base = *reinterpret_cast<uint32_t*>(base + 0x60);
            int32_t entry = *reinterpret_cast<int32_t*>(table_base + index * 4);
            if (index < *reinterpret_cast<uint32_t*>(base + 100)) {
                if (index < *reinterpret_cast<uint32_t*>(base + 0x68)) {
                    if (*reinterpret_cast<int32_t*>(table_base + index * 4) != 0) {
                        *reinterpret_cast<int32_t*>(base + 0x6C) = *reinterpret_cast<int32_t*>(base + 0x6C) + -1;
                    }
                } else {
                    *reinterpret_cast<uint32_t*>(base + 0x68) = index + 1;
                }
                *reinterpret_cast<uint32_t*>(table_base + index * 4) = 0;
            }
            if (entry != 0) {
                FUN_0055f200(0, nullptr, nullptr, nullptr, 0, self);
                slot = entry;
                FUN_005bf090(&slot);
            }
            index = index + 1;
        } while (index < *reinterpret_cast<uint32_t*>(base + 0x68));
    }
}

// 0x55fb30 — observed shape: initalizes the self block at +0x54/+0x0C/+0x3C
// ranges from the writer reachable at param_1+0x15C, branching on the
// version word at param_1+0x1C (threshold 0xA00010F picks FUN_005418d0
// vs FUN_00556940). When the version is below the threshold, reads two
// more words at +0x3C, then a uint16 count at +0x40 whose buffer of
// count*2 bytes is allocated and filled through the writer; finally a word
// at the stack slot drives FUN_006b34a0 and a 2-byte-per-element read loop.
// NEEDS_MANUAL: several writer reads pass register-borne values (BX/SI)
// and stack offsets that the decompiler leaves implicit; each Ghidra
// warning block is unreachable, so only the fall-through path is kept.
extern void FUN_005418d0(void);
extern void FUN_00556940(void);
extern void FUN_006b34a0(uint32_t count);

void FUN_0055fb30(int param_1, void* self, uint32_t bx_value, uint32_t si_value, char stack_bool)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t version = *reinterpret_cast<uint32_t*>(param_1 + 0x1C);
    if (version < 0xA00010F) {
        FUN_005418d0();
    } else {
        FUN_00556940();
    }
    void** writer_vtable = *reinterpret_cast<void***>(*reinterpret_cast<int32_t*>(param_1 + 0x15C));
    auto writer = reinterpret_cast<void (*)(void*)>(writer_vtable[1]);

    *reinterpret_cast<bool*>(base + 0x54) = (stack_bool != '\0');
    if (version < 0xA00010F) {
        writer(base + 0x3C);
        *reinterpret_cast<uint16_t*>(base + 0x0C) = static_cast<uint16_t>(si_value);
        writer(base + 0x3C);
        if (version < 0xA00010F) {
            writer(base + 0x3C);
            *reinterpret_cast<uint32_t*>(base + 0x40) = bx_value;
            if (bx_value != 0) {
                void* buf = FUN_00533c78(bx_value * 2);
                *reinterpret_cast<void**>(base + 0x44) = buf;
                auto writer2 = reinterpret_cast<void (*)(void*, uint32_t)>(writer);
                writer2(buf, bx_value << 1);
            }
        }
    }
    uint32_t stack_word = 0;
    writer(&stack_word);
    if (stack_word != 0) {
        FUN_006b34a0(stack_word);
        stack_word = 0;
        uint32_t count = 0;
        do {
            writer(base + 0x3A);
            count = count + 1;
        } while (count < stack_word);
    }
}

// 0x55fe30 — observed shape: deleting destructor for a node with a
// vtable pointer and an embedded sub-object. Resets vtable to
// PTR_FUN_006c31e8, destroys the table via FUN_0055fab0, rewrites the
// sub-object vtable at +0x5C (in_ECX[0x17]) to PTR_FUN_006c31e0, frees
// the buffer at in_ECX[0x18], runs FUN_00556850, and conditionally frees
// self when (param_1 & 1).
extern void* PTR_FUN_006c31e8;
extern void FUN_00556850(void* self);

void FUN_0055fe30(unsigned char param_1, void* self)
{
    uint32_t* node = static_cast<uint32_t*>(self);
    node[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c31e8);
    FUN_0055fab0(self);
    node[0x17] = reinterpret_cast<uint32_t>(&PTR_FUN_006c31e0);
    operator_delete__(reinterpret_cast<void*>(node[0x18]));
    FUN_00556850(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x55ff10 — observed shape: scalar deleting destructor wrapping
// FUN_00547d10. Sets the vtable to PTR_FUN_006c325c, runs the base
// destructor, and conditionally frees self when (param_1 & 1).
extern void* PTR_FUN_006c325c;
extern void FUN_00547d10(void* self);

void FUN_0055ff10(unsigned char param_1, void* self)
{
    uint32_t* node = static_cast<uint32_t*>(self);
    node[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c325c);
    FUN_00547d10(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x55ff40 — observed shape: allocating copy constructor. Allocates 0x20
// bytes, initializes the vtable (PTR_FUN_006c325c) and zeroes words 4..7,
// calls FUN_00547c80, then FUN_00547db0(new, param_1), and copies the four
// words at receiver+0x10..0x1C into the new object's words 4..7.
// On allocation failure the null pointer flows through both calls and
// returns null.
extern void FUN_00547c80(void* self);
extern void FUN_00547db0(void* dst, uint32_t src);

uint32_t* FUN_0055ff40(uint32_t param_1, void* self)
{
    uint32_t* fresh = static_cast<uint32_t*>(FUN_00533c78(0x20));
    if (fresh == nullptr) {
        fresh = nullptr;
    } else {
        FUN_00547c80(fresh);
        fresh[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c325c);
        fresh[7] = 0;
        fresh[6] = 0;
        fresh[5] = 0;
        fresh[4] = 0;
    }
    FUN_00547db0(fresh, param_1);
    uint8_t* base = static_cast<uint8_t*>(self);
    // NOTE: in the listing in_ECX is the source receiver; the null path
    // still copies through the freed receiver slots as written.
    if (fresh != nullptr || true) {
        fresh[4] = *reinterpret_cast<uint32_t*>(base + 0x10);
        fresh[5] = *reinterpret_cast<uint32_t*>(base + 0x14);
        fresh[6] = *reinterpret_cast<uint32_t*>(base + 0x18);
        fresh[7] = *reinterpret_cast<uint32_t*>(base + 0x1C);
    }
    return fresh;
}

// 0x55ffb0 — observed shape: version-dispatched reader into self+0x10.
// Runs FUN_00547fa0, then when the version word at param_1+0x1C is below
// 0x500000E reads three words via FUN_00535110 into the locals and stores
// them at self+0x10/+0x14/+0x18 with +0x1C zeroed; otherwise reads four
// 4-byte values through the writer at *(param_1+0x15C)+8.
extern void FUN_00547fa0(int param_1);
extern int FUN_00535110(int param_1);

void FUN_0055ffb0(int param_1, void* self)
{
    FUN_00547fa0(param_1);
    uint8_t* base = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<uint32_t*>(param_1 + 0x1C) < 0x500000E) {
        int a = FUN_00535110(param_1);
        int b = FUN_00535110(param_1);
        int c = FUN_00535110(param_1);
        *reinterpret_cast<int*>(base + 0x10) = a;
        *reinterpret_cast<int*>(base + 0x14) = b;
        *reinterpret_cast<int*>(base + 0x18) = c;
        *reinterpret_cast<int*>(base + 0x1C) = 0;
        return;
    }
    void** writer_vtable = *reinterpret_cast<void***>(*reinterpret_cast<int32_t*>(param_1 + 0x15C));
    auto read4 = reinterpret_cast<void (*)(void*, int)>(writer_vtable[1]);
    read4(base + 0x10, 4);
    read4(base + 0x14, 4);
    read4(base + 0x18, 4);
    read4(base + 0x1C, 4);
}

// 0x560160 — observed shape: string-vector deep copy. Runs FUN_00547db0,
// then if either the table at receiver+0x14 or the count at receiver+0x10
// is zero, zeroes param_1+0x10/+0x14 and returns. Otherwise copies the
// count, clamps the index at +0x18 to 0xFFFFFFFF when negative or
// >= count, allocates count*4 bytes at param_1+0x14, and copies each
// counted string (null stays null) with FUN_00533c78 sized to the
// measured length.
extern void FUN_00547db0(int dst, uint32_t src);

void FUN_00560160(int param_1, uint32_t param_2, void* self)
{
    FUN_00547db0(param_1, param_2);
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t table = *reinterpret_cast<uint32_t*>(base + 0x14);
    uint32_t count = *reinterpret_cast<uint32_t*>(base + 0x10);
    if ((table == 0) || (count == 0)) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x14) = 0;
        *reinterpret_cast<uint32_t*>(param_1 + 0x10) = 0;
        return;
    }
    *reinterpret_cast<uint32_t*>(param_1 + 0x10) = count;
    int32_t index = *reinterpret_cast<int32_t*>(base + 0x18);
    if ((index < 0) || (static_cast<uint32_t>(count) <= static_cast<uint32_t>(index))) {
        *reinterpret_cast<uint32_t*>(param_1 + 0x18) = 0xFFFFFFFFu;
    } else {
        *reinterpret_cast<int32_t*>(param_1 + 0x18) = index;
    }
    void* fresh_table = FUN_00533c78(count << 2);
    *reinterpret_cast<void**>(param_1 + 0x14) = fresh_table;
    uint32_t i = 0;
    do {
        const char* src = *reinterpret_cast<const char* const*>(table + i * 4);
        if (src == nullptr) {
            *reinterpret_cast<uint32_t*>(static_cast<uint32_t>(fresh_table) + i * 4) = 0;
        } else {
            const char* start = src + 1;
            const char* cursor = src;
            do {
                char ch = *cursor;
                cursor = cursor + 1;
                if (ch == '\0') {
                    break;
                }
            } while (true);
            unsigned int len = static_cast<unsigned int>(cursor + (1 - static_cast<int>(start)));
            char* dup = static_cast<char*>(FUN_00533c78(len));
            *reinterpret_cast<char**>(static_cast<uint32_t>(fresh_table) + i * 4) = dup;
            const char* read = *reinterpret_cast<const char* const*>(table + i * 4);
            char* write = *reinterpret_cast<char**>(static_cast<uint32_t>(fresh_table) + i * 4);
            do {
                char ch = *read;
                read = read + 1;
                *write = ch;
                write = write + 1;
                if (ch == '\0') {
                    break;
                }
            } while (true);
        }
        i = i + 1;
    } while (i < count);
}
