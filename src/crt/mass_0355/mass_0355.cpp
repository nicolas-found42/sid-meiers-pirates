// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent; no PASS.
// Sources: analysis/pseudocode/functions/*.c (Ghidra 12.2), addresses 0x6be930-0x6bec70.
#include <cstdint>
#include <cstddef>

// Observed object shape at every refcount site in this batch:
//   +0x00  vtable pointer; vtable[0] is the scalar deleting destructor
//   +0x04  reference count
struct RefCounted {
    void** vtable;     // +0x00
    int32_t refcount;  // +0x04
};

// Virtual destructor signature observed as (**(code **)*obj)(1):
// the object arrives in a register receiver, the sole stack argument is 1.
typedef void (__thiscall* ScalarDeletingDtor)(void* self, int32_t flags);

extern void __cdecl operator_delete__(void* p);
extern void __cdecl FUN_004baf50(void);

extern RefCounted* DAT_008dc958;
extern RefCounted* DAT_008dc96c;
extern RefCounted* DAT_008dc970;
extern RefCounted* DAT_008dc974;
extern RefCounted* DAT_008dc978;
extern RefCounted* DAT_008dc97c;
extern RefCounted* DAT_008e64dc;
extern RefCounted* DAT_008e66cc;
extern RefCounted* DAT_008e66ec;

extern int32_t DAT_00727444;
extern int32_t DAT_008de1e4;

// Table bases for the downward refcount-sweep loops below.
extern uintptr_t DAT_008e6690;
extern uintptr_t DAT_008e6660;
extern uintptr_t DAT_008e66a4;
extern uintptr_t DAT_008e66b4;
extern uintptr_t DAT_008e66c0;

extern uint8_t PTR_FUN_006fd14c;
extern uint8_t PTR_LAB_006fd148;

extern uint32_t* PTR_DAT_00726808;
extern uint32_t* PTR_DAT_0072680c;
extern uint8_t* DAT_008e66f0;

extern uint8_t DAT_008cacc8;
extern uint8_t DAT_008cacd0;

extern uintptr_t DAT_00726810;
extern uint32_t DAT_00726820;
extern uint8_t PTR_LAB_00708c68;

// 0x006be930 — observed shape
void FUN_006be930(void) {
    RefCounted* obj = DAT_008dc958;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006be950 — observed shape
void FUN_006be950(void) {
    RefCounted* obj = DAT_008dc96c;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006be970 — observed shape
void FUN_006be970(void) {
    RefCounted* obj = DAT_008dc970;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006be990 — observed shape
void FUN_006be990(void) {
    RefCounted* obj = DAT_008dc974;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006be9b0 — observed shape
void FUN_006be9b0(void) {
    RefCounted* obj = DAT_008dc978;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006be9d0 — observed shape
void FUN_006be9d0(void) {
    RefCounted* obj = DAT_008dc97c;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006be9f0 — observed shape: 0x20-element table walk, three refcounted
// slots released per iteration, vtable swapped and cursor stepped by -0x30 dwords.
void FUN_006be9f0(void) {
    int32_t remaining = 0x20;
    uintptr_t* slot = reinterpret_cast<uintptr_t*>(&DAT_008de1e4);
    do {
        slot[-0x49] = reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c);
        FUN_004baf50();

        RefCounted* obj = reinterpret_cast<RefCounted*>(slot[-0x1a]);
        if (obj != nullptr) {
            int32_t refs = obj->refcount;
            obj->refcount = refs - 1;
            if (refs - 1 == 0) {
                reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
            }
        }

        obj = reinterpret_cast<RefCounted*>(slot[-0x30]);
        if (obj != nullptr) {
            int32_t refs = obj->refcount;
            obj->refcount = refs - 1;
            if (refs - 1 == 0) {
                reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
            }
        }

        obj = reinterpret_cast<RefCounted*>(slot[-0x42]);
        if (obj != nullptr) {
            int32_t refs = obj->refcount;
            obj->refcount = refs - 1;
            if (refs - 1 == 0) {
                reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
            }
        }

        DAT_00727444 = DAT_00727444 - 1;
        remaining = remaining - 1;
        slot[-0x49] = reinterpret_cast<uintptr_t>(&PTR_LAB_006fd148);
        slot = slot - 0x30;
    } while (remaining != 0);
}

// 0x006bea70 — observed shape: dispose the block 8 dwords below the stored
// pointer unless it is the shared sentinel, then repoint to the empty sentinel.
void FUN_006bea70(void) {
    uint32_t* block = PTR_DAT_00726808 - 8;
    if (block != nullptr &&
        block != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator_delete__(block);
    }
    PTR_DAT_00726808 = reinterpret_cast<uint32_t*>(&DAT_008cacd0);
}

// 0x006beaa0 — observed shape: same dispose-and-reset pattern as 0x006bea70,
// applied to the second stored pointer.
void FUN_006beaa0(void) {
    uint32_t* block = PTR_DAT_0072680c - 8;
    if (block != nullptr &&
        block != reinterpret_cast<uint32_t*>(&DAT_008cacc8)) {
        operator_delete__(block);
    }
    PTR_DAT_0072680c = reinterpret_cast<uint32_t*>(&DAT_008cacd0);
}

// 0x006bead0 — observed shape
void FUN_006bead0(void) {
    RefCounted* obj = DAT_008e64dc;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006beaf0 — observed shape
void FUN_006beaf0(void) {
    RefCounted* obj = reinterpret_cast<RefCounted*>(DAT_008e6690);
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006beb10 — observed shape: 0xc entries walked downward from the table base,
// releasing each refcounted pointer.
void FUN_006beb10(void) {
    uintptr_t* cursor = &DAT_008e6690;
    int32_t remaining = 0xc;
    do {
        RefCounted* obj = reinterpret_cast<RefCounted*>(cursor[-1]);
        cursor = cursor - 1;
        if (obj != nullptr) {
            int32_t refs = obj->refcount;
            obj->refcount = refs - 1;
            if (refs - 1 == 0) {
                reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
            }
        }
        remaining = remaining - 1;
    } while (remaining != 0);
}

// 0x006beb40 — observed shape: same sweep with 0x60 entries.
void FUN_006beb40(void) {
    uintptr_t* cursor = &DAT_008e6660;
    int32_t remaining = 0x60;
    do {
        RefCounted* obj = reinterpret_cast<RefCounted*>(cursor[-1]);
        cursor = cursor - 1;
        if (obj != nullptr) {
            int32_t refs = obj->refcount;
            obj->refcount = refs - 1;
            if (refs - 1 == 0) {
                reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
            }
        }
        remaining = remaining - 1;
    } while (remaining != 0);
}

// 0x006beb70 — observed shape: same sweep with 4 entries.
void FUN_006beb70(void) {
    uintptr_t* cursor = &DAT_008e66a4;
    int32_t remaining = 4;
    do {
        RefCounted* obj = reinterpret_cast<RefCounted*>(cursor[-1]);
        cursor = cursor - 1;
        if (obj != nullptr) {
            int32_t refs = obj->refcount;
            obj->refcount = refs - 1;
            if (refs - 1 == 0) {
                reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
            }
        }
        remaining = remaining - 1;
    } while (remaining != 0);
}

// 0x006beba0 — observed shape: same sweep with 4 entries from a second base.
void FUN_006beba0(void) {
    uintptr_t* cursor = &DAT_008e66b4;
    int32_t remaining = 4;
    do {
        RefCounted* obj = reinterpret_cast<RefCounted*>(cursor[-1]);
        cursor = cursor - 1;
        if (obj != nullptr) {
            int32_t refs = obj->refcount;
            obj->refcount = refs - 1;
            if (refs - 1 == 0) {
                reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
            }
        }
        remaining = remaining - 1;
    } while (remaining != 0);
}

// 0x006bebd0 — observed shape: same sweep with 3 entries.
void FUN_006bebd0(void) {
    uintptr_t* cursor = &DAT_008e66c0;
    int32_t remaining = 3;
    do {
        RefCounted* obj = reinterpret_cast<RefCounted*>(cursor[-1]);
        cursor = cursor - 1;
        if (obj != nullptr) {
            int32_t refs = obj->refcount;
            obj->refcount = refs - 1;
            if (refs - 1 == 0) {
                reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
            }
        }
        remaining = remaining - 1;
    } while (remaining != 0);
}

// 0x006bec00 — observed shape
void FUN_006bec00(void) {
    RefCounted* obj = DAT_008e66cc;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006bec30 — observed shape: install a vtable pointer and clear the
// adjacent field at +0x10.
void FUN_006bec30(void) {
    DAT_00726810 = reinterpret_cast<uintptr_t>(&PTR_LAB_00708c68);
    DAT_00726820 = 0;
}

// 0x006bec50 — observed shape
void FUN_006bec50(void) {
    RefCounted* obj = DAT_008e66ec;
    if (obj != nullptr) {
        int32_t refs = obj->refcount;
        obj->refcount = refs - 1;
        if (refs - 1 == 0) {
            reinterpret_cast<ScalarDeletingDtor>(obj->vtable[0])(obj, 1);
        }
    }
}

// 0x006bec70 — observed shape: dispose the block 8 bytes below the stored
// pointer unless it is the shared sentinel, then repoint to the empty sentinel.
void FUN_006bec70(void) {
    uint8_t* block = DAT_008e66f0 - 8;
    if (block != nullptr && block != &DAT_008cacc8) {
        operator_delete__(block);
    }
    DAT_008e66f0 = &DAT_008cacd0;
}
