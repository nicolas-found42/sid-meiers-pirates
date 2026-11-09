// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
#include <cstdint>
#include <cstdlib>

extern void FUN_004aba90(void);
extern void CSimpleArray_RemoveAll_533b80(void* self);
extern void operator_delete(void*);

// 0x00533b9d — calls FUN_004aba90 then zeroes this+0x30/0x34/0x38
void FUN_00533b9d(void* self) {
    FUN_004aba90();
    *(uint32_t*)((char*)self + 0x30) = 0;
    *(uint32_t*)((char*)self + 0x34) = 0;
    *(uint32_t*)((char*)self + 0x38) = 0;
}

// 0x00533b80 — ATL CSimpleArray RemoveAll: free buffer, zero +0x00/+0x04/+0x08
void __thiscall FUN_00533b80(void* self) {
    if (*(void**)self != (void*)0) {
        ::free(*(void**)self);
        *(void**)self = (void*)0;
    }
    *(uint32_t*)((char*)self + 0x04) = 0;
    *(uint32_t*)((char*)self + 0x08) = 0;
}

// 0x005185c0 — scalar-deleting-dtor: FUN_00518580, if (flag&1) operator_delete
extern void FUN_00518580(void);
void FUN_005185c0(uint8_t flag, void* self) {
    FUN_00518580();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x00518730 — scalar-deleting-dtor: FUN_00518750, if (flag&1) operator_delete
extern void FUN_00518750(void);
void FUN_00518730(uint8_t flag, void* self) {
    FUN_00518750();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x005187b0 — scalar-deleting-dtor: FUN_005187d0, if (flag&1) operator_delete
extern void FUN_005187d0(void);
void FUN_005187b0(uint8_t flag, void* self) {
    FUN_005187d0();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x00518860 — scalar-deleting-dtor: FUN_00518880, if (flag&1) operator_delete
extern void FUN_00518880(void);
void FUN_00518860(uint8_t flag, void* self) {
    FUN_00518880();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x00518940 — scalar-deleting-dtor: FUN_00515680, if (flag&1) operator_delete
extern void FUN_00515680(void);
void FUN_00518940(uint8_t flag, void* self) {
    FUN_00515680();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x0051a6e0 — scalar-deleting-dtor: FUN_0051a540, if (flag&1) operator_delete
extern void FUN_0051a540(void);
void FUN_0051a6e0(uint8_t flag, void* self) {
    FUN_0051a540();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
