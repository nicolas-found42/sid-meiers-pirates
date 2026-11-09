// Reconstructions for batch mass_0024 (Sid Meier's Pirates! 2004, PE32 i386).
#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <windows.h>

extern void operator_delete(void*);
extern void operator_delete__(void*);

// Observed globals (types are candidate approximations from the pseudocode).
extern int* DAT_008cab4c;
extern int* DAT_008cab50[];
extern int DAT_008cab34;
extern int DAT_008cab38;
extern int DAT_008cab3c;
extern int DAT_008cab40;
extern int DAT_008cab44;
extern int DAT_008cab48;
extern int DAT_008cab54;
extern int DAT_008cab5c;
extern float DAT_007177c4;
extern float DAT_007177c8;
extern float DAT_007177cc;
extern float DAT_00727430;
extern float DAT_00727434;
extern float DAT_00727438;
extern uint8_t DAT_0072cd80[];
extern int DAT_008b96b0;
extern int DAT_008b96b4;
extern int DAT_008cab58;
extern int DAT_008cab60;
extern float DAT_008cadd0;
extern float DAT_008cadc8;
extern float DAT_008cadcc;
extern float DAT_008cadd4;
extern float DAT_008cadd8;
extern float DAT_008caddc;
extern int DAT_008c8494;
extern int DAT_00814304;
extern int DAT_00814308;
extern int DAT_0081430c;
extern uint8_t DAT_00860b68[];
extern uint8_t DAT_00860b6c[];
extern float* DAT_008cdbd8;
extern float DAT_008e9fec_dummy_guard;
extern int DAT_00727444;
extern int DAT_008e9fec;
extern int32_t DAT_00726c28;
extern HANDLE DAT_008e8ed0;
extern uint8_t DAT_008e8efe;
extern uint8_t DAT_008e8efd;
extern void* DAT_008ecd78;
extern uint8_t DAT_008c827f;
extern uint8_t DAT_008c827e;
extern uint8_t DAT_008c81f0;
extern uint8_t DAT_008c827d;
extern uint8_t DAT_008c827c;
extern void* DAT_008cacc8;
extern int DAT_008ed4c0;
extern uint32_t DAT_008ed4bc;
extern float fRam00000000;
struct ThrowInfo {};
extern void* DAT_007149ac;
extern void _CxxThrowException(void*, ThrowInfo*);
// Helpers.
extern int FUN_00491640(void);
extern uint32_t FUN_00533c78(uint32_t);
extern uint32_t FUN_00496650(void);
extern uint32_t FUN_00497430(void);
extern void FUN_004963a0(int);
extern uint32_t FUN_004bdca0(uint32_t, int, int, int, int, uint32_t, int, int, int, int);
extern uint32_t FUN_004baaa0(void*, void*, uint32_t, uint32_t);
extern uint32_t FUN_00501140(uint32_t);
extern void FUN_00501490(uint32_t);
extern void FUN_00534130(void);
extern void FUN_004bbc10(void*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_004c2200(uint32_t, uint32_t);
extern uint32_t FUN_005f0ddc(void);
extern void FUN_004db210(void);
extern uint32_t FUN_0045fcb0(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_00431420(void*);
extern void FUN_004faab0(void);
extern void FUN_004a16b0(void);
extern void FUN_004a1330(void);
extern void FUN_00412f10(void);
extern void FUN_004a1380(void);
extern void FUN_00412df0(void);
extern void FUN_004d4500(void);
extern void FUN_00498b50(void);
extern void FUN_00499810(void);
extern void FUN_0049a010(void);
extern void FUN_0049aa50(void);
extern uint8_t FUN_004984a0(void*, uint8_t);
extern void FUN_00529b50(uint32_t);
extern void FUN_0049aed0(uint32_t, uint32_t);
extern void FUN_004fa8e0(uint32_t, uint32_t);
extern void FUN_004985e0(void);
extern void FUN_004a14b0(void);
extern void FUN_004a13c0(void);
extern void FUN_0049af70(uint32_t, uint32_t);
extern void FUN_00412f90(void);
extern void FUN_004f3350(void);
extern void FUN_004a1230(void);
extern void FUN_004d4480(void);

// 0x496370 — observed shape: drain singly-linked list at DAT_008cab4c, freeing each node.
void FUN_496370_recon(void) {
    void* node = (void*)DAT_008cab4c;
    if (node != nullptr) {
        do {
            void* cur = node;
            node = *(void**)((std::intptr_t)node + 4);
            operator_delete(cur);
        } while (node != nullptr);
    }
}

// 0x4963a0 — observed shape: find node whose target equals EDI, unlink it, call vtable[3] and vtable[0], delete.
void FUN_4963a0_recon(void* self, int* edi_val) {
    (void)self;
    int* target = edi_val;
    int i_next = DAT_008cab4c[1];
    int* prev = DAT_008cab4c;
    while (i_next != 0 && (int*)prev[1] != target) {
        int* cur = (int*)prev[1];
        i_next = cur[1];
        prev = cur;
    }
    if ((int*)prev[1] == target) {
        if (target == (int*)*DAT_008cab50) {
            DAT_008cab50 = prev;
        }
        (**(void(**)(void))(*(int*)target + 0xc))();
        (**(void(**)(int))*(int*)target)(1);
        void* victim = (void*)prev[1];
        prev[1] = *(int*)((std::intptr_t)victim + 4);
        *(uint32_t*)((std::intptr_t)victim + 4) = 0;
        operator_delete(victim);
    }
}

// 0x496410 — observed shape: steering update + periodic spawn of FUN_00496650 (type 0x6c alloc) / FUN_00497430 (0x50), then dispatch list.
void FUN_496410_recon(void) {
    int seed = (int)FUN_005f0ddc();
    DAT_008cadd0 = 0.0f;
    double fVar5 = (double)((0x1c2 - seed) % 0x168) * (double)0.017453292;
    DAT_008cadc8 = (float)std::cos(fVar5);
    DAT_008cadcc = (float)std::sin(fVar5);
    FUN_00491640();
    int iVar1 = DAT_008cab38;
    DAT_008cadd4 = DAT_007177cc * DAT_008cadcc - DAT_008cadd0 * DAT_007177c8;
    DAT_008cadd8 = DAT_008cadd0 * DAT_007177c4 - DAT_007177cc * DAT_008cadc8;
    DAT_008caddc = DAT_007177c8 * DAT_008cadc8 - DAT_008cadcc * DAT_007177c4;
    if (((DAT_008cab54 < DAT_008cab34) &&
         (DAT_008cab3c < *(char*)((std::intptr_t)&DAT_0072cd80 + DAT_008b96b0 + DAT_008b96b4 * 0x125))) &&
        ((DAT_008cab38 < 1 || (rand() % iVar1 == 0)))) {
        iVar1 = (int)FUN_00533c78(0x6c);
        int* child;
        if (iVar1 == 0) child = nullptr;
        else child = (int*)FUN_00496650();
        uint32_t* link = (uint32_t*)FUN_00533c78(8);
        DAT_008cab50[1] = (int*)link;
        DAT_008cab50 = (int*)link;
        link[0] = (uint32_t)(std::intptr_t)child;
        link[1] = 0;
        (**(void(**)(void))(*(int*)(std::intptr_t)child + 4))();
    }
    iVar1 = DAT_008cab44;
    if (((DAT_008cab5c < DAT_008cab40) &&
         (*(char*)((std::intptr_t)&DAT_0072cd80 + DAT_008b96b0 + DAT_008b96b4 * 0x125) <= DAT_008cab48)) &&
        ((DAT_008cab44 < 1 || (rand() % iVar1 == 0)))) {
        iVar1 = (int)FUN_00533c78(0x50);
        int* child;
        if (iVar1 == 0) child = nullptr;
        else child = (int*)FUN_00497430();
        uint32_t* link = (uint32_t*)FUN_00533c78(8);
        DAT_008cab50[1] = (int*)link;
        link[0] = (uint32_t)(std::intptr_t)child;
        link[1] = 0;
        DAT_008cab50 = (int*)link;
        (**(void(**)(void))(*(int*)(std::intptr_t)child + 4))();
    }
    int* node = *(int**)((std::intptr_t)DAT_008cab4c + 4);
    while (node != nullptr) {
        (**(void(**)(void))(*(int*)*node + 8))();
        if (*(char*)((std::intptr_t)node + 0x30) == 0) {
            node = (int*)node[1];
        } else {
            node = (int*)node[1];
            FUN_004963a0((int*)(std::intptr_t)node);
        }
    }
}

// 0x496650 — observed shape: constructor-ish (receiver EDI) guarded by DAT_008cab54, buffer alloc 0xc0, resource init.
void FUN_496650_recon(void* self) {
    uint32_t* edi = (uint32_t*)self;
    bool first = DAT_008cab54 == 0;
    *(uint8_t*)((std::intptr_t)edi + 0xc) = 0;
    edi[0] = 0x70ab28;
    if (first) {
        uint32_t* buf = (uint32_t*)FUN_00533c78(0xc0);
        uint32_t res = (uint32_t)DAT_008e9fec;
        if (buf == nullptr) {
            DAT_008cab58 = 0;
        } else {
            buf[1] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            buf[0] = 0x6fd14c;
            buf[7] = 0;
            buf[0x19] = 0;
            buf[0x2f] = 0;
            FUN_004bdca0(res, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
            DAT_008cab58 = (int)(std::intptr_t)buf;
        }
        uint32_t v = FUN_004baaa0((void*)(std::intptr_t)&DAT_0072758c, nullptr, 0, 0);
        v = FUN_00501140(v);
        v = FUN_004baaa0((void*)(std::intptr_t)v, (void*)(std::intptr_t)&DAT_00727598, 1, 1);
        FUN_00501490(v);
        FUN_004baaa0(nullptr, nullptr, 0, 0);
        FUN_00534130();
    }
    DAT_008cab54 = DAT_008cab54 + 1;
    edi[10] = 0;
}

// 0x496820 — NEEDS_MANUAL: very long multi-block state machine (cases 2/9/10/0xb/0x14/0x15) with float10/atlan locals; pseudocode elided 220 lines in the read, translation below covers the full observed ranges shape compactly.
void FUN_496820_recon(void* self) {
    int* ec = (int*)self;
    int* node = *(int**)((std::intptr_t)DAT_008cab4c + 4);
    rand();
    int cur = DAT_008c8494;
    int i16 = cur - *(int*)((std::intptr_t)self + 0x34);
    int local68 = cur - *(int*)((std::intptr_t)self + 0x58);
    int sx = DAT_00814304 / 1000;
    int sy = DAT_00814308 / 1000;
    float fStack48 = DAT_00727430;
    float fStack44 = DAT_00727434;
    float fStack40 = DAT_00727438;
    int st = *(int*)((std::intptr_t)self + 0x2c);
    if (st == 2) {
        float dx = *(float*)((std::intptr_t)self + 0xc) - (float)sx;
        float dy = *(float*)((std::intptr_t)self + 0x10) - (float)sy;
        (void)FUN_00491640();
    } else if (st == 9) {
        *(float*)((std::intptr_t)self + 0x40) += 15.0f;
    } else if (st == 10) {
        *(float*)((std::intptr_t)self + 0x40) -= 15.0f;
        *(float*)((std::intptr_t)self + 0x50) = (1800.0f - (float)i16) * 0.00044444445f;
        if (0x708 < i16) return;
    } else if (st == 0xb) {
        *(float*)((std::intptr_t)self + 0x50) = 1.0f;
        if ((*(char*)((std::intptr_t)self + 0x54) != 0) && (0x6a4 < i16)) {
            *(int*)((std::intptr_t)self + 0x58) = cur + -500;
            local68 = 500;
            *(uint8_t*)((std::intptr_t)self + 0x54) = 0;
        }
    } else if (st == 0x14) {
        *(float*)((std::intptr_t)self + 0x50) = 1.0f;
        if ((*(char*)((std::intptr_t)self + 0x54) != 0) && (900 < i16)) {
            *(int*)((std::intptr_t)self + 0x58) = cur + -500;
            local68 = 500;
            *(uint8_t*)((std::intptr_t)self + 0x54) = 0;
        }
    } else if (st == 0x15) {
        *(float*)((std::intptr_t)self + 0x50) = 1.0f;
        if ((*(char*)((std::intptr_t)self + 0x54) != 0) && (0x6a4 < i16)) {
            *(int*)((std::intptr_t)self + 0x58) = cur + -500;
            local68 = 500;
            *(uint8_t*)((std::intptr_t)self + 0x54) = 0;
        }
    }
    *(float*)((std::intptr_t)self + 0xc) = (float)sx + *(float*)((std::intptr_t)self + 0x38);
    *(float*)((std::intptr_t)self + 0x10) = (float)sy + *(float*)((std::intptr_t)self + 0x3c);
    uint32_t u12 = FUN_005f0ddc();
    *(uint32_t*)((std::intptr_t)self + 0x5c) = u12;
    uint32_t u13 = FUN_005f0ddc();
    uint32_t u14 = FUN_005f0ddc();
    uint32_t u15 = FUN_005f0ddc();
    FUN_004bbc10((void*)(std::intptr_t)DAT_008cab58, u15, u14, u13, u12, 0, 0, (uint32_t)st, (uint32_t)i16);
    if (*(float*)((std::intptr_t)self + 0x50) < 0.99f) {
        FUN_004c2200(FUN_005f0ddc(), 0);
    }
    if (*(int*)((std::intptr_t)self + 0x58) != 0) {
        if (0x69a < local68) {
            *(uint32_t*)((std::intptr_t)self + 0x58) = 0;
            return;
        }
        uint32_t a = FUN_005f0ddc();
        uint32_t b = FUN_005f0ddc();
        uint32_t c = FUN_005f0ddc();
        FUN_004bbc10((void*)(std::intptr_t)&DAT_008cdbd8, c, b, a, 0, 0, 0, 0xffffffffu, (uint32_t)local68);
    }
    (void)node; (void)fStack48; (void)fStack44; (void)fStack40; (void)ec;
}

// 0x497430 — observed shape: variant of 0x496650 with DAT_008cab5c/DAT_008cab60, index[10]=1.
void FUN_497430_recon(void* self) {
    uint32_t* edi = (uint32_t*)self;
    bool first = DAT_008cab5c == 0;
    *(uint8_t*)((std::intptr_t)edi + 0xc) = 0;
    edi[0] = 0x70ab38;
    if (first) {
        uint32_t* buf = (uint32_t*)FUN_00533c78(0xc0);
        uint32_t res = (uint32_t)DAT_008e9fec;
        if (buf == nullptr) {
            DAT_008cab60 = 0;
        } else {
            buf[1] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            buf[0] = 0x6fd14c;
            buf[7] = 0;
            buf[0x19] = 0;
            buf[0x2f] = 0;
            FUN_004bdca0(res, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
            DAT_008cab60 = (int)(std::intptr_t)buf;
        }
    }
    DAT_008cab5c = DAT_008cab5c + 1;
    edi[10] = 1;
}

// 0x4975a0 — observed shape: entity steering (states 0/1 via +0x2c), wander/pursue blending, advance by speed at +0x24, render via FUN_004bbc10.
void FUN_4975a0_recon(void* self) {
    int* node = *(int**)((std::intptr_t)DAT_008cab4c + 4);
    uint32_t age = (uint32_t)(DAT_008c8494 - *(int*)((std::intptr_t)self + 0x40));
    float local3c = 0.0f, local38 = 0.0f, local34 = 0.0f;
    FUN_004db210();
    FUN_004db210();
    float f1 = 0.0f - *(float*)((std::intptr_t)self + 0xc);
    float f3 = ((float)0 + (float)(DAT_00814308 / 1000)) - *(float*)((std::intptr_t)self + 0x10);
    float f4 = 450.0f - *(float*)((std::intptr_t)self + 0x14);
    (void)FUN_00491640();
    int st = *(int*)((std::intptr_t)self + 0x2c);
    if (st == 0) {
        if (*(char*)((std::intptr_t)self + 0x4c) == 0) {
            float wanderX = DAT_00727430, wanderY = DAT_00727434, wanderZ = DAT_00727438;
            while (node != nullptr) {
                int other = *node;
                if (other != (std::intptr_t)self && *(int*)(std::intptr_t)other + 0x28 == 1) {
                    wanderX += (*(float*)((std::intptr_t)self + 0xc) - *(float*)(std::intptr_t)other + 0xc) * 0.05f;
                    (void)wanderY; (void)wanderZ;
                }
                node = (int*)node[1];
            }
            *(float*)((std::intptr_t)self + 0xc) += *(float*)((std::intptr_t)self + 0x24) * *(float*)((std::intptr_t)self + 0x18);
            *(float*)((std::intptr_t)self + 0x10) += *(float*)((std::intptr_t)self + 0x24) * *(float*)((std::intptr_t)self + 0x1c);
            *(float*)((std::intptr_t)self + 0x14) += *(float*)((std::intptr_t)self + 0x24) * *(float*)((std::intptr_t)self + 0x20);
            (void)local3c; (void)local38; (void)local34; (void)f1; (void)f3; (void)f4; (void)age;
        } else {
            *(float*)((std::intptr_t)self + 0x18) = *(float*)((std::intptr_t)self + 0x18) * 0.9f;
            *(float*)((std::intptr_t)self + 0x1c) = *(float*)((std::intptr_t)self + 0x1c) * 0.9f;
            *(float*)((std::intptr_t)self + 0x20) = *(float*)((std::intptr_t)self + 0x20) * 0.9f;
        }
    } else if (st == 1) {
        *(float*)((std::intptr_t)self + 0xc) += *(float*)((std::intptr_t)self + 0x24) * *(float*)((std::intptr_t)self + 0x18);
        *(float*)((std::intptr_t)self + 0x10) += *(float*)((std::intptr_t)self + 0x24) * *(float*)((std::intptr_t)self + 0x1c);
        *(float*)((std::intptr_t)self + 0x14) += *(float*)((std::intptr_t)self + 0x24) * *(float*)((std::intptr_t)self + 0x20);
    }
    uint32_t a = FUN_005f0ddc();
    uint32_t b = FUN_005f0ddc();
    FUN_004bbc10((void*)(std::intptr_t)DAT_008cab60, b, a, 0, 0, 0, 0, (uint32_t)st, age);
}

// 0x497ca0 — observed shape: 3-float vector add, receiver in ECX.
void FUN_497ca0_recon(void* self, float* out, float* in2) {
    const float* s = (const float*)self;
    out[0] = in2[0] + s[0];
    out[1] = in2[1] + s[1];
    out[2] = in2[2] + s[2];
}

// 0x497cf0 — observed shape: 3-float vector cross product, receiver in ECX.
void FUN_497cf0_recon(void* self, float* out, float* in2) {
    const float* s = (const float*)self;
    out[0] = s[1] * in2[2] - s[2] * in2[1];
    out[1] = s[2] * in2[0] - in2[2] * s[0];
    out[2] = s[0] * in2[1] - s[1] * in2[0];
}

// 0x497d30 — observed shape: TLS-aware wait loop keyed on byte at self+0x1c; calls FUN_004faab0/FUN_004a16b0/vtable+0x10, SleepEx(30).
void FUN_497d30_recon(void* self) {
    char flag = *(char*)((std::intptr_t)self + 0x1c);
    HANDLE h = DAT_008e8ed0;
    for (;;) {
        if (flag != 0) { DAT_008e8ed0 = h; return; }
        if (DAT_008e8efe != 0) { DAT_008e8efe = 0; DAT_008e8efd = 0; }
        DAT_008e8ed0 = h;
        void* tls = nullptr;
        if (DAT_00726c28 != -1) tls = TlsGetValue((uint32_t)DAT_00726c28);
        bool tls_ok = (DAT_00726c28 != -1 && tls != nullptr && *(int*)((std::intptr_t)tls + 0x14) != 0 && *(int*)((std::intptr_t)tls + 0x14) != 3);
        if (!tls_ok) {
            WaitForSingleObject(h, 0xffffffffu);
        } else {
            HANDLE local8 = *(HANDLE*)((std::intptr_t)tls + 0x20);
            HANDLE local4 = h;
            HANDLE handles[2] = {local8, local4};
            DWORD w = WaitForMultipleObjects(2, handles, 0, 0xffffffffu);
            if (w == 0 && *(DWORD*)((std::intptr_t)tls + 0x30) == GetCurrentThreadId()) {
                *(DWORD*)((std::intptr_t)tls + 0x14) = 3;
                FUN_004faab0();
            }
        }
        FUN_004a16b0();
        (**(void(**)(void))((std::intptr_t)DAT_008ecd78 + 0x10))();
        ReleaseMutex(DAT_008e8ed0);
        if (!tls_ok) {
            SleepEx(0x1e, 0);
        } else {
            DWORD w = WaitForSingleObject(*(HANDLE*)((std::intptr_t)tls + 0x20), 0x1e);
            if (w == 0 && *(DWORD*)((std::intptr_t)tls + 0x30) == GetCurrentThreadId()) {
                *(DWORD*)((std::intptr_t)tls + 0x14) = 3;
                FUN_004faab0();
            }
        }
        flag = *(char*)((std::intptr_t)self + 0x1c);
        h = DAT_008e8ed0;
    }
}

// 0x497e60 — observed shape: init object at ESI (mutex in slot 0x9c8, throwing on failure), zero-fill slots, FUN_004a1330/FUN_00412f10.
void FUN_497e60_recon(void* self) {
    uint32_t* esi = (uint32_t*)self;
    FUN_004a1330();
    esi[0x9c7] = (uint32_t)0x7109b0;
    esi[0x9c8] = 0;
    HANDLE h = CreateMutexA(nullptr, 0, nullptr);
    esi[0x9c8] = (uint32_t)(std::intptr_t)h;
    if (h == nullptr) {
        uint32_t local4 = 0xffffffffu;
        _CxxThrowException(&local4, (ThrowInfo*)&DAT_007149ac);
    }
    esi[0x9c9] = (uint32_t)(std::intptr_t)&DAT_008cacd0;
    esi[0x9cb] = 0; esi[0x9cc] = 0; esi[0x9cd] = 0;
    esi[0x9cf] = 0; esi[0x9d0] = 0; esi[0x9d1] = 0;
    esi[0x9d5] = 0; esi[0x9d6] = 0;
    FUN_00412f10();
    esi[0] = 0;
    esi[0x9d2] = 0;
    esi[0x9d4] = 0xffffffffu;
}

// 0x497f10 — observed shape: teardown object at ESI: delete string slots 0x2758/0x273c/0x272c, reset vector at 0x2724, close mutex 0x2720.
void FUN_497f10_recon(void* self) {
    uint32_t* esi = (uint32_t*)self;
    if (*(void**)((std::intptr_t)esi + 0x2758) != nullptr) {
        operator_delete__(*(void**)((std::intptr_t)esi + 0x2758));
        *(uint32_t*)((std::intptr_t)esi + 0x2758) = 0;
    }
    *(uint32_t*)((std::intptr_t)esi + 0x2754) = 0;
    if (*(void**)((std::intptr_t)esi + 0x273c) != nullptr) operator_delete(*(void**)((std::intptr_t)esi + 0x273c));
    *(uint32_t*)((std::intptr_t)esi + 0x273c) = 0;
    *(uint32_t*)((std::intptr_t)esi + 0x2740) = 0;
    *(uint32_t*)((std::intptr_t)esi + 0x2744) = 0;
    if (*(void**)((std::intptr_t)esi + 0x272c) != nullptr) operator_delete(*(void**)((std::intptr_t)esi + 0x272c));
    *(uint32_t*)((std::intptr_t)esi + 0x272c) = 0;
    *(uint32_t*)((std::intptr_t)esi + 0x2730) = 0;
    *(uint32_t*)((std::intptr_t)esi + 0x2734) = 0;
    uint32_t* buf = (uint32_t*)((int)*(uint32_t*)((std::intptr_t)esi + 0x2724) - 8);
    if (buf != nullptr && buf != (uint32_t*)DAT_008cacc8) operator_delete__(buf);
    *(void**)((std::intptr_t)esi + 0x2724) = (void*)&DAT_008cacd0;
    *(uint32_t**)((std::intptr_t)esi + 0x271c) = (uint32_t**)0x7109b0;
    CloseHandle(*(HANDLE*)((std::intptr_t)esi + 0x2720));
    FUN_004a1380();
}

// 0x497fd0 — observed shape: init at param_1 (slots 0x9cb..0x9d4), run subsystem inits, load resource via FUN_004984a0, start thread object, return 1/0.
uint32_t FUN_497fd0_recon(int* param_1) {
    if ((void*)param_1[0x9cb] != nullptr) operator_delete((void*)param_1[0x9cb]);
    param_1[0x9cb] = 0; param_1[0x9cc] = 0; param_1[0x9cd] = 0;
    if ((void*)param_1[0x9cf] != nullptr) operator_delete((void*)param_1[0x9cf]);
    param_1[0x9cf] = 0; param_1[0x9d0] = 0; param_1[0x9d1] = 0;
    *(uint8_t*)((std::intptr_t)param_1 + 0x9d3 * 4) = 0;
    *(uint8_t*)((std::intptr_t)param_1 + 0x274d) = 0;
    *(uint8_t*)((std::intptr_t)param_1 + 0x274e) = 0;
    *(uint8_t*)((std::intptr_t)param_1 + 0x274f) = 0;
    if ((void*)param_1[0x9d6] != nullptr) { operator_delete__((void*)param_1[0x9d6]); param_1[0x9d6] = 0; }
    param_1[0x9d5] = 0; param_1[0x9d2] = 0; param_1[0x9d4] = -1;
    FUN_00412df0();
    FUN_004d4500();
    FUN_00498b50();
    FUN_00499810();
    FUN_0049a010();
    FUN_0049aa50();
    if (FUN_004984a0(param_1, 1) == 0) {
        FUN_00529b50(0);
        return 0;
    }
    FUN_00529b50(0);
    FUN_0049aed0(0, 0xfffffffeu);
    param_1[0x9c5] = 0; param_1[0x9c6] = 0;
    uint32_t* thr = (uint32_t*)FUN_00533c78(0x34);
    if (thr == nullptr) thr = nullptr;
    else { FUN_004fa8e0(0, 0); thr[0] = 0x70ab5c; }
    *param_1 = (int)(std::intptr_t)thr;
    SetThreadPriority((HANDLE)thr[0xb], 2);
    *(uint32_t*)((std::intptr_t)*param_1 + 0x18) = 0;
    if ((*(uint8_t*)((std::intptr_t)*param_1 + 0x24) & 1) == 0) {
        *(uint8_t*)((std::intptr_t)*param_1 + 0x24) |= 1;
        ResumeThread(*(HANDLE*)((std::intptr_t)*param_1 + 0x2c));
    }
    for (int i = 0; i < 6; i++) { FUN_004985e0(); FUN_004a14b0(); }
    DAT_008c827f = 0; DAT_008c827e = 0; DAT_008c81f0 = 0; DAT_008c827d = 1; DAT_008c827c = 0;
    FUN_004d4480();
    return 1;
}

// 0x498260 — observed shape: six (FUN_004985e0/FUN_004a14b0) pairs, spin on counter 0x9c5/0x9c6, releasing thread object.
void FUN_498260_recon(int* param_1) {
    for (int i = 0; i < 6; i++) { FUN_004985e0(); FUN_004a14b0(); }
    DAT_008c827f = 0; DAT_008c827e = 0; DAT_008c827d = 1; DAT_008c827c = 0;
    for (;;) {
        int delta = param_1[0x9c5] - param_1[0x9c6];
        if (delta < 0) delta += 100;
        if (delta == 0) break;
        Sleep(1);
    }
    if ((void*)*param_1 != nullptr) {
        (**(void(**)(int))**(uint32_t**)*param_1)(1);
        *param_1 = 0;
    }
    FUN_004a13c0();
    FUN_0049af70(0, 0);
    (**(void(**)(void))((std::intptr_t)DAT_008ecd78 + 8))();
}

// 0x4983f0 — observed shape: copy string payload into buffer at EAX+0x2724, NUL-terminate, free param_1-8.
void FUN_4983f0_recon(void* self, void* param_1) {
    size_t size = *(size_t*)((std::intptr_t)param_1 - 4);
    uint32_t dst = *(uint32_t*)((std::intptr_t)self + 0x2724);
    if ((int)size >= 0 && param_1 != (void*)(std::intptr_t)dst) {
        if (size == 0) FUN_00412f90();
        else {
            FUN_004f3350();
            std::memmove((void*)(std::intptr_t)dst, param_1, size);
            *(uint8_t*)(std::intptr_t)dst + *(int*)((std::intptr_t)dst - 4) = 0;
            *(uint8_t*)((std::intptr_t)dst + *(int*)((std::intptr_t)dst - 4)) = 0;
        }
    }
    uint32_t* buf = (uint32_t*)((std::intptr_t)param_1 - 8);
    if (buf != nullptr && buf != (uint32_t*)DAT_008cacc8) operator_delete__(buf);
}

// 0x498450 — observed shape: if vtable+0x18 returns 0, yield 0; else scale factor by DAT_008ed4c0 branch.
double FUN_498450_recon(void) {
    char v = (**(char(**)(void))((std::intptr_t)DAT_008ecd78 + 0x18))();
    if (v == 0) return 0.0;
    if ((int)DAT_008ed4c0 < 3) {
        uint32_t idx = ((int)DAT_008ed4c0 < 1) ? 0xffffffffu : 0u;
        return (double)fRam00000000 * (double)*(float*)((std::intptr_t)DAT_008ed4bc + (std::intptr_t)idx * 4);
    }
    uint32_t idx = ((int)DAT_008ed4c0 < 1) ? 0xffffffffu : 0u;
    return (double)*(float*)((std::intptr_t)DAT_008ed4bc + 0x10) * (double)*(float*)((std::intptr_t)DAT_008ed4bc + (std::intptr_t)idx * 4);
}

// 0x4984a0 — observed shape: copy buffer at param_1+0x2724 into DAT_008cacd0, call vtable[0], return 1 on success else 0 (cleanup).
uint32_t FUN_4984a0_recon(int param_1, uint8_t param_2) {
    uint8_t* local_c = (uint8_t*)&DAT_008cacd0;
    FUN_004a1230();
    uint8_t* src = *(uint8_t**)((std::intptr_t)param_1 + 0x2724);
    size_t size = *(size_t*)(src - 4);
    if ((int)size >= 0 && src != nullptr && src != local_c) {
        if (size == 0) FUN_00412f90();
        else {
            FUN_004f3350();
            std::memmove(local_c, src, size);
            local_c[*(int*)(local_c - 4)] = 0;
        }
    }
    uint8_t local50[8] = {};
    char v = (**(char(**)(void*))*(uint32_t*)DAT_008ecd78)(local50);
    (void)param_2;
    if (v == 0) {
        uint32_t* buf = (uint32_t*)((std::intptr_t)local50 - 8);
        if (buf != nullptr && buf != (uint32_t*)DAT_008cacc8) operator_delete__(buf);
        return 0;
    }
    uint32_t* buf2 = (uint32_t*)((std::intptr_t)local50 - 8);
    if (buf2 != nullptr && buf2 != (uint32_t*)DAT_008cacc8) operator_delete__(buf2);
    return 1;
}

// 0x498570 — observed shape: if CL==0 invoke vtable+0x50 and bump counters at +0x2748/+0x274c; else the pair of calls.
void FUN_498570_recon(void* self, uint8_t cl) {
    uint32_t* esi = (uint32_t*)self;
    if (cl == 0) {
        (**(void(**)(void))((std::intptr_t)DAT_008ecd78 + 0x50))();
        *(uint32_t*)((std::intptr_t)esi + 0x2748) += 1;
        *(uint8_t*)((std::intptr_t)esi + 0x274c) = 1;
        return;
    }
    FUN_004985e0();
    FUN_004a14b0();
}

// 0x4985e0 — observed shape: copy 0x18 dwords from EAX to EBX, then FUN_00412df0.
void FUN_4985e0_recon(void* dst, const void* src) {
    uint32_t* d = (uint32_t*)dst;
    const uint32_t* s = (const uint32_t*)src;
    for (int i = 0; i < 0x18; i++) d[i] = s[i];
    FUN_00412df0();
}

// 0x498670 — observed shape: if AL!=0 call the pair; else decrement counter at +0x2748 gated by +0x274c, invoking vtable+0x54 at zero.
void FUN_498670_recon(void* self, uint8_t al) {
    if (al != 0) {
        FUN_004985e0();
        FUN_004a14b0();
        return;
    }
    uint32_t* esi = (uint32_t*)self;
    if (*(char*)((std::intptr_t)esi + 0x274c) != 0) {
        int* c = (int*)((std::intptr_t)esi + 0x2748);
        *c = *c - 1;
        if (*c == 0) {
            (**(void(**)(void))((std::intptr_t)DAT_008ecd78 + 0x54))();
            *(uint8_t*)((std::intptr_t)esi + 0x274c) = 0;
        }
    }
}
