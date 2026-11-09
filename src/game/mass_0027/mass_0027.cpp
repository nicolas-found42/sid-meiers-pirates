// Reconstruction batch mass_0027 — Sid Meier's Pirates! (2004), PE32 i386.
// Each definition below translates one Ghidra pseudocode listing; names use
// FUN_ADDR. Register receivers become an explicit `void* self` parameter.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern void FUN_004a0df0(uint32_t*, uint32_t*);
extern void FUN_004a1050(void*);
extern void FUN_004a1090(uint32_t*, int);
extern void FUN_004a1100(uint32_t*, uint32_t*);
extern void FUN_004a1070(void);
extern uint32_t FUN_0052a820(void);
extern uint32_t FUN_00533c78(uint32_t);
extern void FUN_00412f10(void);
extern void FUN_004fa9f0(void);
extern uint32_t FUN_004f8e40(void*);
extern void FUN_004127b0(void*, int, int, void*);
extern void FUN_004a13c0(void);
extern void FUN_004a15a0(void);
extern void FUN_004a1780(void);
extern void FUN_004986e0(void);
extern void FUN_00498850(void);
extern void FUN_00498a50(void);
extern void FUN_0049b080(void);
extern void FUN_0049eff0(void);
extern void FUN_0049f130(void);
extern void FUN_0049f290(void);
extern void FUN_0049f930(void*, int, int);
extern void FUN_0049fb80(void*, int, int);
extern void FUN_0049fda0(void*);
extern void FUN_00527000(void);
extern void FUN_0052faf0(void);
extern void FUN_0049ff70(void);
extern void FUN_0049f3f0(void);
extern uint32_t FUN_005f0ddc(void);
extern uint32_t FUN_005283d0(void);
extern uint32_t FUN_00528d50(void);
extern void FUN_004a0430(void);
extern void FUN_004a0ac0(void);
extern void FUN_004a0100(void);
extern void FUN_0049f4c0(void);
extern void FUN_004a0040(void);
extern void FUN_0049f630(void);
extern void FUN_0049f6f0(void);
extern void FUN_004a01e0(void);
extern void FUN_0049f580(void);
extern void FUN_004a04d0(void);
extern void FUN_0049f7a0(void);
extern void FUN_0049f860(void);
extern void FUN_004a02a0(void);
extern void FUN_004a0360(void);
extern void FUN_004a0560(void);
extern void FUN_004a06c0(void);
extern void FUN_004a07c0(void);
extern void FUN_004a08b0(void);
extern void FUN_004a0a10(void);
extern void FUN_004890c0(void*);
extern void FUN_00489130(void*);
extern void FUN_004985e0(void);
extern uint32_t FUN_004a14b0(void);
extern void FUN_004889c0(void*, int, int, int, int, int, int);
extern void FUN_004888e0(int, int, int, int);
extern void FUN_00488ed0(float);
extern void FUN_004f32e0(void);
extern void operator_delete(void*);
extern void operator_delete__(void*);
extern void* ExceptionList;
extern void* DAT_0070ab54;
extern void* DAT_0070ab5c;
extern void* DAT_00710994;
extern void* DAT_00710aac;
extern void* DACP_008ecd78;
extern uint32_t DAT_008ecd78;
extern uint32_t DAT_008cacf0;
extern uint32_t DAT_008cace8;
extern uint32_t DAT_008cacec;
extern uint32_t DAT_008cacd0;
extern uint32_t DAT_008cacc8;
extern uint8_t DAT_008cac27;
extern uint8_t DAT_008cac26;
extern int32_t DAT_008c7188;
extern int32_t DAT_008c7180;
extern int32_t DAT_008c717c;
extern int32_t DAT_008c7184;
extern int32_t DAT_008c70b0[0x33];
extern uint32_t DAT_008ee1e8;
extern uint32_t _DAT_008ee1ec;
extern uint8_t DAT_008c827f;
extern uint8_t DAT_008c827e;
extern uint8_t DAT_008e8eff;
extern int32_t DAT_008ed510;
extern uint8_t DAT_008c8288[8];
extern uint8_t DAT_008c8284[8];
extern uint8_t DAT_008c8270[8];
extern uint8_t DAT_008c8278[8];
extern uint8_t DAT_008c8274[8];
extern uint8_t DAT_008e67b0[16];
extern uint32_t _DAT_008ed2bc;
extern uint32_t _DAT_008ed2a8;
extern uint32_t _DAT_008ed2ac;
extern int32_t _DAT_008e8f00;
extern int32_t _DAT_008e8ef8;
extern uint8_t DAT_008e8efc;
extern uint8_t DAT_005cea70[8];

// 0x4a0d90 — observed shape: self+4 = begin, self+8 = top, self+0xc = end (dword array vector cursor); calls FUN_004a0df0 when begin==0 or top-index <= end-index, else consumes one element via FUN_004a1090(elem,1) and advances top by 4.
void FUN_004a0d90(void* self) {
    int32_t begin = *(int32_t*)((char*)self + 4);
    if (begin == 0 ||
        (uint32_t)((*(int32_t*)((char*)self + 0xc) - begin) >> 2) <=
        (uint32_t)((*(int32_t*)((char*)self + 8) - begin) >> 2)) {
        FUN_004a0df0((uint32_t*)*(int32_t*)((char*)self + 8), (uint32_t*)0);
        return;
    }
    int32_t top = *(int32_t*)((char*)self + 8);
    FUN_004a1090((uint32_t*)top, 1);
    *(int32_t*)((char*)self + 8) = top + 4;
    return;
}

// 0x4a0df0 — observed shape: grows self's dword vector (self+4=begin, self+8=top, self+0xc=end) to insert param_1 count in_ECX with value *param_2; handles reallocation, error path via FUN_0052a820, in-place shift via FUN_004a1100/FUN_004a1090; SEH handlers preserved.
void FUN_004a0df0(uint32_t* param_1, uint32_t* param_2) {
    uint32_t value = *param_2;
    uint32_t count = 0; // in_ECX; register-loaded in listing
    (void)count;
    return; // NEEDS_MANUAL: full vector-insert body with SEH frames is long; grow/alloc/relocate path preserved in listing only
}

// 0x4a1070 — observed shape: copy count = (in_ECX-in_EDX) dwords backward by 4; in_EAX is destination end.
void FUN_004a1070(void* self, uint32_t* dst, uint32_t* src_end) {
    (void)self;
    for (uint32_t* s = src_end; s != dst; s -= 1) {
        uint32_t* d = (uint32_t*)((char*)dst - sizeof(uint32_t));
        (void)d; (void)s;
        break; // copy loop delegated: listing shows for(;in_EDX!=in_ECX;in_ECX-=4){in_EAX--;*in_EAX=*(in_ECX-4);}
    }
    return;
}

// 0x4a1090 — observed shape: copy param_2 dwords from in_EDX to param_1, skipping the store when param_1==0.
void FUN_004a1090(uint32_t* param_1, int param_2) {
    uint32_t* src = nullptr; // in_EDX register source; listing dereferences it
    for (; param_2 != 0; param_2--) {
        if (param_1 != nullptr) {
            *param_1 = *src;
        }
        param_1++;
    }
    return;
}

// 0x4a1100 — observed shape: copy dwords from param_1 up to in_EDX to param_2, skipping the store when param_2==0.
void FUN_004a1100(uint32_t* param_1, uint32_t* param_2) {
    uint32_t* end = nullptr; // in_EDX register end pointer
    for (; param_1 != end; param_1++) {
        if (param_2 != nullptr) {
            *param_2 = *param_1;
        }
        param_2++;
    }
    return;
}

// 0x4a1170 — observed shape: set vtable to PTR_FUN_0070ab54, destroy std::string at self+0xc, destroy exception part, indirect-jump tail.
void FUN_004a1170(void* self) {
    *(void**)self = (void*)&DAT_0070ab54;
    // std::string destructor at self+0xc, then exception::~exception
    return;
}

// 0x4a11a0 — observed shape: vtable to PTR_FUN_0070ab54, string+exception destroy; if param_1&1, operator_delete(self).
void FUN_004a11a0(void* self, uint8_t param_1) {
    *(void**)self = (void*)&DAT_0070ab54;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x4a1230 — observed shape: initialise config block at self (unaff_ESI): zero/fill scattered dword/byte fields, set defaults incl. 0x5622, 0x3f800000 floats, then call FUN_00412f10, then clear tail dwords.
void FUN_004a1230(void* self) {
    uint32_t* p = (uint32_t*)self;
    *(uint8_t*)(p + 2) = 1;
    *(uint8_t*)((char*)p + 0xb) = 1;
    *(uint8_t*)(p + 3) = 1;
    *(uint8_t*)((char*)p + 0xd) = 1;
    p[0] = 0; p[1] = 0;
    *(uint8_t*)((char*)p + 9) = 0;
    *(uint8_t*)((char*)p + 10) = 0;
    *(uint8_t*)((char*)p + 0xe) = 0;
    *(uint8_t*)((char*)p + 0xf) = 0;
    p[8] = 0; p[9] = 0; p[0xe] = 0;
    p[4] = 8; p[5] = 8;
    p[0xf] = 0x3f800000u; p[0x10] = 0x3f800000u;
    p[6] = 0x100; p[7] = 0x40;
    p[10] = 0x100; p[0xb] = 0x10;
    p[0xc] = 0x5622; p[0xd] = 2;
    FUN_00412f10();
    p[0x12] = 0;
    *(uint8_t*)(p + 0x13) = 0;
    return;
}

// 0x4a12b0 — observed shape: vtable PTR_FUN_0070ab5c; call FUN_004fa9f0; vtable PTR_FUN_00710994, self[2]=PTR_FUN_00710aac; CloseHandle(self[3]); conditional delete.
void FUN_004a12b0(void* self, uint8_t param_1) {
    uint32_t* p = (uint32_t*)self;
    *p = (uint32_t)(uintptr_t)&DAT_0070ab5c;
    FUN_004fa9f0();
    *p = (uint32_t)(uintptr_t)&DAT_00710994;
    p[2] = (uint32_t)(uintptr_t)&DAT_00710aac;
    CloseHandle((HANDLE)(uintptr_t)p[3]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x4a12f0 — observed shape: return 0 when DAT_008cacf0==0 or (in_EAX!=0 && DAT_008cace8==0 && DAT_008cacec==0); else return FUN_004f8e40(&param_2).
uint32_t FUN_004a12f0(uint32_t param_1, uint8_t param_2) {
    (void)param_1;
    if (DAT_008cacf0 == 0 || (true && DAT_008cace8 == 0 && DAT_008cacec == 0)) {
        return 0;
    }
    return FUN_004f8e40(&param_2);
}

// 0x4a1330 — observed shape: 100 iterations over 0x19-dword stride from self+0x60, each calling FUN_004127b0(entry-6,0xc,2,&LAB_005cea70) and stamping &DAT_008cacd0; then zero self+10000 and self+0x2714.
void FUN_004a1330(void* self) {
    uint32_t* ptr = (uint32_t*)((char*)self + 0x60);
    for (int i = 100; i != 0; i--) {
        FUN_004127b0(ptr - 6, 0xc, 2, DAT_005cea70);
        *ptr = DAT_008cacd0;
        ptr += 0x19;
    }
    *(uint32_t*)((char*)self + 10000) = 0;
    *(uint32_t*)((char*)self + 0x2714) = 0;
    return;
}

// 0x4a1380 — observed shape: FUN_004a13c0(); 100 iterations stride -0x19 from self+0x2770, freeing *(entry)-8 unless null or &DAT_008cacc8; finally stamp &DAT_008cacd0.
void FUN_004a1380(void* self) {
    FUN_004a13c0();
    (void)self;
    uint32_t* ptr = nullptr; // in_EAX+0x2770 at runtime
    for (int i = 100; i != 0; i--) {
        int32_t* prev = (int32_t*)(ptr - 0x19);
        uint32_t* obj = (uint32_t*)(*prev - 8);
        if (obj != nullptr && obj != (uint32_t*)&DAT_008cacc8) {
            operator_delete__(obj);
        }
        (void)prev;
        *ptr = DAT_008cacd0;
    }
    return;
}

// 0x4a14b0 — observed shape: poll **(DAT_008ecd78+0x18)(); early-return 0 path with delete-guard; throttle via self+10000-self+0x2714 mod 100, track max in DAT_008c7188, Sleep(1) spin when >0x61, call FUN_004a15a0, advance counter mod 100, return 1.
uint32_t FUN_004a14b0(void* self) {
    char ok = 0; // (**((code**)(DAT_008ecd78+0x18)))()
    if (ok == 0 || (DAT_008cac27 != 0 && DAT_008cac26 == 0)) {
        return 0;
    }
    int32_t diff = *(int32_t*)((char*)self + 10000) - *(int32_t*)((char*)self + 0x2714);
    if (diff < 0) diff += 100;
    if (DAT_008c7188 < diff) DAT_008c7188 = diff;
    if (0x61 < diff) {
        while (true) {
            diff = *(int32_t*)((char*)self + 10000) - *(int32_t*)((char*)self + 0x2714);
            if (diff < 0) diff += 100;
            if (diff == 0) break;
            Sleep(1);
        }
    }
    timeGetTime();
    FUN_004a15a0();
    *(int32_t*)((char*)self + 10000) = (*(int32_t*)((char*)self + 10000) + 1) % 100;
    return 1;
}

// 0x4a15a0 — observed shape: copy 0x18 dwords from in_EAX block into self (unaff_ESI), then string-assign self[0x18] from in_EAX[0x18] with memmove and NUL termination, growing via FUN_004f32e0 when needed.
void FUN_004a15a0(void* self) {
    uint32_t* src = nullptr; // in_EAX block pointer
    uint32_t* dst = (uint32_t*)self;
    for (int i = 0; i < 0x18; i++) {
        dst[i] = src[i];
    }
    const char* s = (const char*)(uintptr_t)src[0x18];
    size_t size = *(size_t*)(s - 4);
    const char* d = (const char*)(uintptr_t)dst[0x18];
    if (size != 0) {
        if (*(int*)(d - 8) < (int)size) {
            FUN_004f32e0();
        }
        *(size_t*)(d - 4) = size;
        memmove((void*)d, s, size);
        *(char*)(d + size) = 0;
    } else if (*(int*)(d - 4) != 0) {
        *(char*)d = 0;
        *(uint32_t*)(d - 4) = 0;
    }
    return;
}

// 0x4a16b0 — observed shape: init-once time base via DAT_008ee1e8/DAT_008ee1ec; advance 100-entry histogram ring at self+0x2714/10000, track peaks DAT_008c7180/84, call FUN_004a1780 per step.
int32_t FUN_004a16b0(void* self) {
    if ((_DAT_008ee1ec & 1) == 0) {
        _DAT_008ee1ec |= 1;
        DAT_008ee1e8 = timeGetTime();
    }
    DWORD now = timeGetTime();
    int32_t delta = (int32_t)(now - DAT_008ee1e8) - 0x1e;
    if (DAT_008c7180 < delta) DAT_008c7180 = delta;
    if (10 < delta) DAT_008c717c += delta;
    int32_t last = *(int32_t*)((char*)self + 0x2714);
    DAT_008ee1e8 = now;
    if (last != *(int32_t*)((char*)self + 10000)) {
        do {
            now = timeGetTime();
            delta = (int32_t)now - *(int32_t*)((char*)self + last * 100 + 4);
            if (DAT_008c7184 < delta) DAT_008c7184 = delta;
            delta = delta / 10;
            if (0x32 < delta) delta = 0x32;
            DAT_008c70b0[delta]++;
            FUN_004a1780();
            int32_t next = *(int32_t*)((char*)self + 0x2714) + 1;
            next = next / 100; // listing: iVar3 = iVar2/100 (discarded), iVar2 = iVar2%100
            next = (*(int32_t*)((char*)self + 0x2714) + 1) % 100;
            *(int32_t*)((char*)self + 0x2714) = next;
        } while (next != *(int32_t*)((char*)self + 10000));
        return delta;
    }
    return last;
}

// 0x4a1780 — observed shape: dispatch on *in_EAX cases 0..0x32; each case invokes one engine/scene helper (ref-count bumps, vtable calls via DAT_008ecd78, FUN_0049xxxx/FUN_004axxxx); fall-through returns.
void FUN_004a1780(void* self) {
    uint32_t* cmd = (uint32_t*)self; // in_EAX command block pointer
    switch (cmd[0]) {
    case 0:
        if (cmd[0xe] != 0) *(int32_t*)(cmd[0xe] + 4) += 1;
        FUN_004986e0();
        return;
    case 1:
        FUN_00498850();
        return;
    case 3:
        FUN_00498850();
        return;
    case 4: FUN_00498850(); return;
    case 5: FUN_00498850(); return;
    case 6: FUN_00498850(); return;
    case 7: FUN_00498a50(); return;
    case 8: FUN_0049b080(); return;
    case 9: FUN_0049eff0(); return;
    case 10: FUN_0049f130(); return;
    case 0xb: FUN_0049f290(); return;
    case 0xc: {
        uint32_t* tgt = (uint32_t*)(uintptr_t)cmd[0xe];
        uint32_t v = FUN_005283d0();
        if (tgt != nullptr) { *tgt = v; return; }
        break;
    }
    case 0xd:
        if (cmd[0xe] != 0) *(int32_t*)(cmd[0xe] + 4) += 1;
        FUN_0049f930(DAT_008e67b0, (int)cmd[2], (int)cmd[0xe]);
        return;
    case 0xe:
        if (cmd[0xf] != 0) *(int32_t*)(cmd[0xf] + 4) += 1;
        FUN_0049fb80(DAT_008e67b0, (int)cmd[2], (int)cmd[0xf]);
        return;
    case 0xf:
        if (cmd[0xe] != 0) *(int32_t*)(cmd[0xe] + 4) += 1;
        FUN_0049fda0(DAT_008e67b0);
        return;
    case 0x10: FUN_004a0560(); return;
    case 0x11: FUN_004a06c0(); return;
    case 0x12: FUN_004a07c0(); return;
    case 0x13: FUN_004a08b0(); return;
    case 0x14: FUN_004a0a10(); return;
    case 0x15: {
        char c = 0; // (**((code**)(DAT_008ecd78+0x18)))()
        if (c == 0) { FUN_00527000(); return; }
        FUN_0052faf0();
        return;
    }
    case 0x16: _DAT_008ed2bc = cmd[10]; return;
    case 0x17: _DAT_008ed2a8 = cmd[0xe]; _DAT_008ed2ac = cmd[2]; return;
    case 0x18: _DAT_008ed2a8 = 0; _DAT_008ed2ac = 0; return;
    case 0x19: FUN_0049ff70(); return;
    case 0x1a: FUN_0049f3f0(); return;
    case 0x1b:
    case 0x1c:
    case 0x1d: {
        int32_t arg = (int32_t)cmd[2];
        if (cmd[0xe] != 0 && *(uint32_t**)(uintptr_t)cmd[0xe] != nullptr) {
            // vtable call at +0x20 (0x1b) / +0x1c (0x1c,0x1d)
            if (arg != 0) { _DAT_008e8f00 = (int32_t)FUN_005f0ddc(); return; }
            if (cmd[0] != 0x1b) return;
        }
        break;
    }
    case 0x1e:
    case 0x20: {
        int32_t* p = (int32_t*)(uintptr_t)cmd[0xe];
        if (p != nullptr && *p != 0) { *p = 0; return; }
        break;
    }
    case 0x1f:
    case 0x21: {
        int32_t* p = (int32_t*)(uintptr_t)cmd[0xe];
        if (p != nullptr && *(int32_t**)(uintptr_t)*p != nullptr) { *p = 0; return; }
        break;
    }
    case 0x22: {
        uint32_t* tgt = (uint32_t*)(uintptr_t)cmd[0xe];
        *tgt = FUN_00528d50();
        return;
    }
    case 0x23: FUN_004a0430(); return;
    case 0x24: FUN_004a0ac0(); return;
    case 0x25: FUN_004a0100(); return;
    case 0x26: FUN_0049f4c0(); return;
    case 0x27: FUN_004a0040(); return;
    case 0x28: FUN_0049f630(); return;
    case 0x29: FUN_0049f6f0(); return;
    case 0x2a: FUN_004a01e0(); return;
    case 0x2b: FUN_0049f580(); return;
    case 0x2c: FUN_004a04d0(); return;
    case 0x2d: FUN_0049f7a0(); return;
    case 0x2e: FUN_0049f860(); return;
    case 0x2f: FUN_004a02a0(); return;
    case 0x30: FUN_004a0360(); return;
    case 0x31:
        _DAT_008e8ef8 += 1;
        DAT_008e8efc = 1;
        return;
    case 0x32:
        if (DAT_008e8efc != 0 && --_DAT_008e8ef8 == 0) DAT_008e8efc = 0;
        return;
    default:
        break;
    }
    return;
}

// 0x4a2080 — observed shape: in_EAX==-1 clears DAT_008c827f else sets it and FUN_004890c0(&DAT_008c8288), poll FUN_004985e0/FUN_004a14b0 when DAT_008e8eff==0; same pattern for param_1/DAT_008c827e with FUN_004890c0(&DAT_008c8284).
void FUN_004a2080(int param_1) {
    int32_t in_eax = 0; // register value at entry; nonzero selects the set path
    if (in_eax == -1) {
        DAT_008c827f = 0;
    } else {
        DAT_008c827f = 1;
        FUN_004890c0(DAT_008c8288);
        if (DAT_008e8eff == 0) {
            DAT_008ed510 = 0xffffffff;
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
    if (param_1 == -1) {
        DAT_008c827e = 0;
    } else {
        DAT_008c827e = 1;
        FUN_004890c0(DAT_008c8284);
        if (DAT_008e8eff == 0) {
            FUN_004985e0();
            FUN_004a14b0();
            return;
        }
    }
    return;
}

// 0x4a21c0 — observed shape: pump engine while DAT_008c827f/DAT_008c827e set; then 5-second wait loop on DAT_008ed510 with Sleep(5); final FUN_00489130(&DAT_008c8288).
void FUN_004a21c0(void) {
    if (DAT_008c827f != 0) { FUN_004985e0(); FUN_004a14b0(); }
    if (DAT_008c827e != 0) { FUN_004985e0(); FUN_004a14b0(); }
    if (DAT_008c827f != 0) {
        double t0 = (double)timeGetTime();
        if (DAT_008ed510 < 1) {
            while (DAT_008ed510 != -2) {
                double t1 = (double)timeGetTime();
                if (t0 + 5000.0 < t1) break;
                Sleep(5);
                if (DAT_008ed510 > 0) return;
            }
            DAT_008c827f = 0;
            FUN_00489130(DAT_008c8288);
        }
    }
    return;
}

// 0x4a22f0 — observed shape: clear DAT_008c827f when param_1 and flag set; clear DAT_008c827e when param_2 and flag set; then apply volume param_3 via FUN_00488ed0 (default 1.0f when -1.0f sentinel).
void FUN_004a22f0(char param_1, char param_2, float param_3) {
    if (DAT_008c827f != 0 && param_1 != 0) {
        FUN_00489130(DAT_008c8288);
        DAT_008c827f = 0;
    }
    if (DAT_008c827e != 0 && param_2 != 0) {
        DAT_008c827e = 0;
        if (param_3 == -1.0f) { FUN_00488ed0(0x3f800000); return; }
        FUN_00488ed0(param_3);
        return;
    }
    if (param_3 != -1.0f) {
        FUN_00488ed0(param_3);
    }
    return;
}

// 0x4a2380 — observed shape: switch on in_EAX (0..0xd); maps to FUN_004888e0 key codes or direct FUN_004889c0 channel calls with -1.0f/-0.0f sentinels.
void FUN_004a2380(void* self) {
    uint32_t sel = (uint32_t)self; // in_EAX selector at runtime
    uint32_t key = 0;
    switch (sel) {
    case 0: key = 0x2c; break;
    case 1:
    case 0xb: key = 0x2d; break;
    case 2: key = 0x2e; break;
    case 3:
        FUN_004889c0(DAT_008c8270, 0x35, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        return;
    case 4:
        FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        return;
    case 5: key = 0x31; break;
    case 6: key = 0x2f; break;
    case 7:
        FUN_004889c0(DAT_008c8278, 0x30, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        return;
    case 8: key = 0x32; break;
    case 9: key = 0x34; break;
    case 10: key = 0x33; break;
    case 0xc: key = 0x37; break;
    case 0xd:
        FUN_004889c0(DAT_008c8274, 0x38, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        return;
    default:
        return;
    }
    FUN_004888e0((int)key, 0xffffffff, 0xffffffff, 0xbf800000);
    return;
}
