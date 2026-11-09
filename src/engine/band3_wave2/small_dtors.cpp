// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
#include <cstdint>

extern void operator_delete(void*);

// 0x0051c1e0 — scalar-deleting-dtor: FUN_0051c200, if (flag&1) operator_delete
extern void FUN_0051c200(void);
void FUN_0051c1e0(uint8_t flag, void* self) {
    FUN_0051c200();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x0051e4d0 — scalar-deleting-dtor: FUN_0051e4f0, if (flag&1) operator_delete
extern void FUN_0051e4f0(void);
void FUN_0051e4d0(uint8_t flag, void* self) {
    FUN_0051e4f0();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x0051f040 — scalar-deleting-dtor: FUN_0051eef0, if (flag&1) operator_delete
extern void FUN_0051eef0(void);
void FUN_0051f040(uint8_t flag, void* self) {
    FUN_0051eef0();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x0051f140 — scalar-deleting-dtor: FUN_0051f160, if (flag&1) operator_delete
extern void FUN_0051f160(void);
void FUN_0051f140(uint8_t flag, void* self) {
    FUN_0051f160();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x00520390 — scalar-deleting-dtor: FUN_005203b0, if (flag&1) operator_delete
extern void FUN_005203b0(void);
void FUN_00520390(uint8_t flag, void* self) {
    FUN_005203b0();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x00520e70 — scalar-deleting-dtor: FUN_00520e90, if (flag&1) operator_delete
extern void FUN_00520e90(void);
void FUN_00520e70(uint8_t flag, void* self) {
    FUN_00520e90();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x005235a0 — scalar-deleting-dtor: FUN_00523720, if (flag&1) operator_delete
extern void FUN_00523720(void);
void FUN_005235a0(uint8_t flag, void* self) {
    FUN_00523720();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x005271b0 — scalar-deleting-dtor: FUN_005271d0, if (flag&1) operator_delete
extern void FUN_005271d0(void);
void FUN_005271b0(uint8_t flag, void* self) {
    FUN_005271d0();
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x005289f0 — refcount decrement at +0x98 ptr; virtual call(1) at zero
void FUN_005289f0(void* self) {
    uint32_t** ptr = *(uint32_t***)((char*)self + 0x98);
    if (ptr != 0) {
        uint32_t* ref = ptr + 1;
        *ref = *ref - 1;
        if (*ref == 0) {
            using Func = void(__thiscall*)(void*, int);
            Func fn = *(Func*)ptr;
            fn(ptr, 1);
        }
    }
}

// 0x00529420 — returns 1 after storing FUN_0052b7e0() result via param_1
extern uint32_t FUN_0052b7e0(void);
uint32_t FUN_00529420(uint32_t* out) {
    *out = FUN_0052b7e0();
    return 1;
}

// 0x0052a800 — dword copy loop: copies count dwords, returns dst+count
uint32_t* FUN_0052a800(uint32_t* dst, const uint32_t* src, uint32_t count) {
    if (count != 0) {
        uint32_t* d = dst;
        uint32_t remaining = count;
        do {
            *d = *src;
            d = d + 1;
            src = src + 1;
            remaining = remaining - 1;
        } while (remaining != 0);
    }
    return dst + count;
}

// 0x0052a870 — forwards (param_2, param_3) to FUN_0052b030
extern void FUN_0052b030(uint32_t, uint32_t);
void FUN_0052a870(uint32_t /*ignored*/, uint32_t p2, uint32_t p3) {
    FUN_0052b030(p2, p3);
}
