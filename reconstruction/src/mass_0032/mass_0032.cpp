// Reconstruction batch mass_0032 — Sid Meier's Pirates! (2004) PE32 i386
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern void operator_delete(void *p);
extern void FUN_00540c50();
extern void FUN_00540c90();
extern void* FUN_00533c78(size_t n);
extern int FUN_005f0ddc();
extern double FUN_004accc0();
extern void FUN_00489210(void *p);
extern void FUN_00500b50();
extern int FUN_004baaa0();
extern void FUN_004ab3c0(void *container, void *entry);
extern void FUN_004ab290(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4,
    uint32_t a5, uint32_t a6, uint32_t a7, uint32_t a8, uint32_t a9,
    int a10, int a11, uint32_t a12);
extern void FUN_0053cac0(void *out, void *dst, void *src);
extern void FUN_0053c8d0(void *out, void *src);
extern int FUN_004bbc10(int obj, int a, int b, int c, int d, int e,
    int f, int g);
extern void FUN_00488a80(int x, uint32_t a, uint32_t b, uint32_t c,
    uint32_t d, uint32_t e, uint32_t f, uint32_t g, void *p,
    uint32_t h, uint32_t i);
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern void FUN_0050baf0(void *fn, int size);
extern int FUN_004baae0(uint32_t t);
extern void FUN_004baca0();
extern void FUN_004be3f0(void *obj, int a, int b, int c, uint32_t d,
    uint32_t e, uint32_t f, int g, int h, int i, int j, int k);
extern void FUN_004bd640(void *p);
extern void FUN_0050bbc0(int);
extern void FUN_004d1240();
extern void FUN_004bd600();
extern void FUN_00412900(int a, int b, int c);
extern void FUN_0050ba80();
extern void *PTR_FUN_0070bf10;
extern void *PTR_FUN_0070bed4;
extern void *PTR_FUN_0070bffc;
extern void *PTR_LAB_0070bff0;
extern void *PTR_FUN_006fd14c;
extern uint8_t DAT_007271c5;
extern uint64_t DAT_008ed610;
extern uint64_t DAT_008ed608;
extern double _DAT_008c84b0;
extern double _DAT_008c84a8;
extern double _DAT_008c8498;
extern double _DAT_008c84a0;
extern double _DAT_007260c0;
extern int DAT_008c8494;
extern int DAT_008c8490;
extern int DAT_008c84b8;
extern int DAT_008cab68;
extern int DAT_008cab64;
extern double DAT_008c8290;
extern int DAT_008c9df4;
extern int DAT_008e8ec4;
extern int _DAT_008e8ec8;
extern int DAT_007263bc;
extern uint32_t DAT_007268f4;
extern int DAT_00726a84;
extern uint32_t DAT_00726380;
extern uint32_t DAT_0072637c;
extern uint32_t DAT_008ea008;
extern int DAT_00727444;
extern int DAT_008ecd78;

// 0x4aade0 — observed shape
void FUN_004aade0(void *param_1) {
    void *self;
    __asm { mov self, ecx }
    uint32_t *fields = static_cast<uint32_t *>(self);
    uint32_t *old = *reinterpret_cast<uint32_t **>(
        reinterpret_cast<uint8_t *>(self) + 4);
    if (old != param_1) {
        if (old != nullptr) {
            int *ref = reinterpret_cast<int *>(old) + 1;
            *ref = *ref - 1;
            if (*ref == 0) {
                void **vt = *reinterpret_cast<void ***>(old);
                auto fn = reinterpret_cast<void (*)(int)>(vt[0]);
                fn(1);
            }
        }
        *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(self) + 4) = param_1;
        if (param_1 != nullptr) {
            reinterpret_cast<uint32_t *>(param_1)[1]++;
        }
    }
    (void)fields;
}

// 0x4aae10 — observed shape
void FUN_004aae10(void *self) {
    FUN_00540c50();
    uint32_t *f = static_cast<uint32_t *>(self);
    *reinterpret_cast<uint16_t *>(reinterpret_cast<uint8_t *>(self) + 8) = 0;
    f[9] = 0;
    f[0] = reinterpret_cast<uint32_t>(PTR_FUN_0070bf10);
    f[10] = 1;
}

// 0x4aae60 — observed shape
void FUN_004aae60(void *self) {
    FUN_00540c50();
    uint32_t *f = static_cast<uint32_t *>(self);
    *reinterpret_cast<uint16_t *>(reinterpret_cast<uint8_t *>(self) + 8) = 3;
    f[9] = 3;
    f[0] = reinterpret_cast<uint32_t>(PTR_FUN_0070bed4);
}

// 0x4aaec0 — observed shape
void FUN_004aaec0(void *self, uint8_t param_1) {
    FUN_00540c90();
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x4aaf00 — observed shape
double FUN_004aaf00() {
    if (DAT_007271c5 != 0) {
        DAT_007271c5 = 0;
        QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER *>(&DAT_008ed610));
        QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&DAT_008ed608));
    }
    LARGE_INTEGER local_8;
    QueryPerformanceCounter(&local_8);
    uint64_t now = (static_cast<uint64_t>(local_8.HighPart) << 32) | local_8.LowPart;
    uint64_t base = DAT_008ed608;
    return static_cast<double>(now - base) / static_cast<double>(DAT_008ed610);
}
// 0x4aaf70 — observed shape
void FUN_004aaf70(double param_1) {
    _DAT_008c84b0 = param_1;
    _DAT_008c84a8 = 0;
    _DAT_008c8498 = 0;
    _DAT_008c84a0 = 0;
    _DAT_007260c0 = 1.0;
    DAT_008c8494 = FUN_005f0ddc();
    DAT_008c8490 = 0;
    DAT_008c84b8 = 0;
}

// 0x4aafd0 — observed shape
// NEEDS_MANUAL: extraout_ST0 source is implicit x87 stack value.
void FUN_004aafd0(char param_1) {
    double fVar1 = FUN_004accc0();
    double fVar2 = (_DAT_008c84a8 == 0.0) ? 0.0 : (fVar1 - _DAT_008c84a8);
    _DAT_008c84a0 = fVar2;
    _DAT_008c84a8 = fVar1;
    if (param_1 == 0) {
        _DAT_008c8498 = _DAT_007260c0 * _DAT_008c84a0;
        if (0.2 < _DAT_008c8498) _DAT_008c8498 = 0.2;
    } else {
        _DAT_008c8498 = 0.0;
    }
    _DAT_008c84b0 += _DAT_008c8498;
    DAT_008c8494 = FUN_005f0ddc();
    DAT_008c8490 = FUN_005f0ddc();
    DAT_008cab68++;
    double *ring = &DAT_008c8290 + DAT_008cab64;
    *ring = 0.0;
    DAT_008cab64++;
    DAT_008c84b8++;
    if (0x3f < DAT_008cab64) DAT_008cab64 = 0;
}

// 0x4ab0d0 — observed shape
int FUN_004ab0d0(void *self, uint32_t param_1, int param_2) {
    uint8_t *b = static_cast<uint8_t *>(self);
    int count = *reinterpret_cast<int *>(b + 0x40);
    int idx = count;
    if (*reinterpret_cast<int *>(b + 0x4c + count * 4) == static_cast<int>(-0x40800000)) {
        idx = count - 1;
    }
    if (idx == 3) {
        if (count != 0) {
            memmove(b + 0x44, b + 0x48, 8);
            memmove(b + 0x50, b + 0x54, 8);
            *reinterpret_cast<uint32_t *>(b + 0x28) = 0;
            *reinterpret_cast<int *>(b + 0x40) = *reinterpret_cast<int *>(b + 0x40) - 1;
        }
        idx = *reinterpret_cast<int *>(b + 0x40) - 1;
    }
    if (idx < 3) {
        *reinterpret_cast<float *>(b + 0x50 + idx * 4) = static_cast<float>(param_2);
        *reinterpret_cast<uint32_t *>(b + 0x44 + idx * 4) = param_1;
        *reinterpret_cast<int *>(b + 0x40) = idx + 1;
        if (idx == 0) {
            if (param_2 == -1) {
                int r = rand();
                *reinterpret_cast<float *>(b + 0x28) = static_cast<float>(r % 1000) * 10.0f;
                return r / 1000;
            }
            *reinterpret_cast<uint32_t *>(b + 0x28) = 0;
        }
    }
    return idx;
}

// 0x4ab180 — observed shape
void FUN_004ab180(void *self, int param_1, int match_id) {
    void *container = self;
    uint8_t *b = static_cast<uint8_t *>(self);
    if (*reinterpret_cast<int *>(b + 0xc) != 0) {
        uint32_t *node = *reinterpret_cast<uint32_t **>(b + 4);
        while (node != nullptr) {
            int *entry = reinterpret_cast<int *>(node[2]);
            node = reinterpret_cast<uint32_t *>(node[0]);
            if (entry[0] == match_id &&
                (param_1 == 0 || param_1 == entry[2])) {
                FUN_004ab3c0(container, entry);
                DAT_008c9df4 = 1;
            }
        }
    }
}

// 0x4ab1c0 — observed shape
void FUN_004ab1c0(void *self, int param_1) {
    uint8_t *b = static_cast<uint8_t *>(self);
    if (param_1 != 0 && *reinterpret_cast<int *>(b + 0xc) != 0) {
        uint32_t *node = *reinterpret_cast<uint32_t **>(b + 4);
        while (node != nullptr) {
            int *entry = reinterpret_cast<int *>(node + 2);
            node = reinterpret_cast<uint32_t *>(node[0]);
            if (param_1 == *reinterpret_cast<int *>(entry[0] + 8)) {
                FUN_004ab3c0(self, reinterpret_cast<void *>(entry[0]));
                DAT_008c9df4 = 1;
            }
        }
    }
}
// 0x4ab200 — observed shape
int *FUN_004ab200(void *self, int match_id, int subtype) {
    uint8_t *b = static_cast<uint8_t *>(self);
    if (*reinterpret_cast<int *>(b + 0xc) == 0) return nullptr;
    uint32_t *node = *reinterpret_cast<uint32_t **>(b + 4);
    while (node != nullptr) {
        int *entry = reinterpret_cast<int *>(node[2]);
        node = reinterpret_cast<uint32_t *>(node[0]);
        if (entry[0] == match_id && (subtype == 0 || subtype == entry[2])) {
            return entry;
        }
    }
    return nullptr;
}

// 0x4ab230 — observed shape
void FUN_004ab230(void *self) {
    int *f = static_cast<int *>(self);
    while (f[3] != 0) {
        FUN_004ab3c0(self, reinterpret_cast<void *>(*reinterpret_cast<int *>(f[1] + 8)));
    }
    uint32_t *node = reinterpret_cast<uint32_t *>(f[1]);
    while (node != nullptr) {
        uint32_t *next = reinterpret_cast<uint32_t *>(node[0]);
        void **vt = *reinterpret_cast<void ***>(self);
        auto fn = reinterpret_cast<void (*)(void *)>(vt[2]);
        fn(node);
        node = next;
    }
    f[3] = 0;
    f[1] = 0;
    f[2] = 0;
    DAT_008c9df4 = 1;
}

// 0x4ab290 — observed shape
uint32_t *FUN_004ab290(void *self, uint32_t p1, uint32_t p2, uint32_t p3,
    uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8,
    uint32_t p9, int p10, int p11, uint32_t p12) {
    uint32_t *obj = static_cast<uint32_t *>(FUN_00533c78(0x5c));
    if (obj == nullptr) return nullptr;
    obj[2] = p2;
    obj[0x14] = static_cast<uint32_t>(static_cast<float>(p10));
    obj[4] = p4;
    obj[6] = p6;
    obj[3] = p3;
    obj[0xb] = static_cast<uint32_t>(static_cast<float>(p11) * 0.01f);
    obj[8] = p8;
    obj[5] = p5;
    obj[0] = p1;
    obj[0xe] = p12;
    obj[7] = p7;
    obj[1] = 0;
    obj[10] = 0;
    obj[0x10] = 1;
    obj[0x11] = 0xffffffffu;
    obj[9] = p9;
    obj[0xc] = 0;
    obj[0xd] = 0;
    reinterpret_cast<uint8_t *>(obj + 0xf)[0] = 0;
    if (p10 == -1) {
        int r = rand();
        obj[10] = static_cast<uint32_t>(static_cast<float>(r % 1000) * 10.0f);
    }
    void **vt = *reinterpret_cast<void ***>(self);
    auto allocNode = reinterpret_cast<uint32_t * (*)()>(vt[1]);
    uint32_t *node = allocNode();
    node[2] = reinterpret_cast<uint32_t>(obj);
    node[0] = 0;
    int *f = static_cast<int *>(self);
    node[1] = static_cast<uint32_t>(f[2]);
    if (reinterpret_cast<void *>(f[2]) != nullptr) {
        *reinterpret_cast<uint32_t *>(f[2]) = reinterpret_cast<uint32_t>(node);
        f[2] = reinterpret_cast<int>(node);
        f[3]++;
        return obj;
    }
    f[1] = reinterpret_cast<int>(node);
    f[2] = reinterpret_cast<int>(node);
    f[3]++;
    return obj;
}

// 0x4ab380 — observed shape
void FUN_004ab380(void *self, uint32_t p1, uint32_t p2, uint32_t p3,
    uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8,
    uint32_t p9, uint32_t p10) {
    uint32_t in_EDX;
    __asm { mov in_EDX, edx }
    FUN_004ab290(self, p1, 0, p2, p3, p4, p5, p6, p7, p8,
        static_cast<int>(in_EDX), static_cast<int>(p9), p10);
}

// 0x4ab3c0 — observed shape
void FUN_004ab3c0(void *container, int *entry) {
    (void)container;
    if (entry == nullptr) return;
    if (reinterpret_cast<uint8_t *>(entry)[0xf * 4] != 0 && entry[0xe] != -1) {
        if (entry[0xd] != 0) FUN_00489210(entry + 0xd);
        entry[0xe] = -1;
        reinterpret_cast<uint8_t *>(entry + 0xf)[0] = 0;
        while (true) {
            int delta = DAT_008e8ec4 - _DAT_008e8ec8;
            if (delta < 0) delta += 100;
            if (delta == 0) break;
            Sleep(1);
        }
    }
    FUN_00500b50();
    uint32_t *vt = *reinterpret_cast<uint32_t **>(entry);
    *reinterpret_cast<uint32_t *>(vt[0] + 0x58) = 0;
    operator_delete(entry);
}
// 0x4ab440 — observed shape
void FUN_004ab440(void *self) {
    uint8_t *b = static_cast<uint8_t *>(self);
    if (*reinterpret_cast<int *>(b + 0xc) == 0) return;
    int *node = *reinterpret_cast<int **>(b + 4);
    if (node == nullptr) return;
    uint8_t local_30[12];
    uint8_t local_24[36];
    while (true) {
        int entry = node[2];
        node = reinterpret_cast<int *>(node[0]);
        int target = 0;
        if (*reinterpret_cast<int *>(entry + 8) == 0) {
            int *r = reinterpret_cast<int *>(FUN_004baaa0());
            target = r[0];
        } else {
            int *cam = reinterpret_cast<int *>(FUN_004baaa0());
            int ent = *reinterpret_cast<int *>(entry + 8);
            float *pos = reinterpret_cast<float *>(local_30);
            FUN_0053cac0(local_30, cam + 0x17, reinterpret_cast<void *>(ent + 0x6c));
            float x = *reinterpret_cast<float *>(ent + 0x90) + pos[0];
            float y = *reinterpret_cast<float *>(ent + 0x94) + pos[1];
            float z = *reinterpret_cast<float *>(ent + 0x98) + pos[2];
            cam[0x17] = static_cast<int>(x);
            cam[0x18] = static_cast<int>(y);
            cam[0x19] = static_cast<int>(z);
            int *rot = reinterpret_cast<int *>(local_24);
            FUN_0053c8d0(local_24, reinterpret_cast<void *>(ent + 0x6c));
            int *dst = cam + 0xe;
            for (int i = 9; i != 0; i--) { *dst++ = *rot++; }
            target = cam[0];
        }
        void **vt = *reinterpret_cast<void ***>(target);
        auto fn = reinterpret_cast<void (*)(float, int)>(vt[0x4c / 4]);
        fn(*reinterpret_cast<float *>(entry + 0x28) * 0.001f, 1);
        if (node == nullptr) return;
    }
}

// 0x4ab530 — observed shape
// NEEDS_MANUAL: LAB_004ab60a control flow flattened.
void FUN_004ab530(int base, int param_1, float param_2) {
    (void)base;
    float local_84 = param_2;
    int remaining = *reinterpret_cast<int *>(param_1 + 0x10);
    if (remaining != -1) {
        *reinterpret_cast<int *>(param_1 + 0x10) = 0xffffffff;
        local_84 = static_cast<float>(remaining) * 0.001f;
    }
    if (*reinterpret_cast<int *>(param_1 + 0xc) == 0) return;
    int *node = *reinterpret_cast<int **>(param_1 + 4);
    if (node == nullptr) return;
    while (true) {
        int *entry = reinterpret_cast<int *>(node[2]);
        node = reinterpret_cast<int *>(node[0]);
        float f = (reinterpret_cast<uint8_t *>(entry)[0xc * 4] & 1) == 0
            ? local_84 : param_2;
        entry[10] = static_cast<int>(f * static_cast<float>(entry[0xb]) * 1000.0f
            + static_cast<float>(entry[10]));
        if (entry[0x14] == static_cast<int>(-0x40800000) ||
            static_cast<float>(entry[10]) <= static_cast<float>(entry[0x14])) {
            uint32_t stamp = static_cast<uint32_t>(FUN_005f0ddc());
            int *spawned;
            if (entry[0] == 0) {
                spawned = nullptr;
            } else {
                reinterpret_cast<uint8_t *>(entry[0])[0x25] = 1;
                spawned = reinterpret_cast<int *>(FUN_004bbc10(entry[0],
                    entry[3], entry[4], entry[5], entry[6], entry[7],
                    entry[8], entry[0x11]));
            }
            entry[1] = reinterpret_cast<int>(spawned);
            if (spawned != nullptr) {
                *reinterpret_cast<uint32_t *>(spawned + 0x20) &= 0xffffdfffu;
            }
            if (reinterpret_cast<uint8_t *>(entry)[0xf * 4] == 0) {
                if (entry[0xe] != -1) {
                    int *r = reinterpret_cast<int *>(FUN_004baaa0());
                    FUN_00488a80(entry[0xe],
                        *reinterpret_cast<uint32_t *>(r + 0x90),
                        *reinterpret_cast<uint32_t *>(r + 0x94),
                        *reinterpret_cast<uint32_t *>(r + 0x98),
                        0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu,
                        entry + 0xd, 0xbf800000u, 0xffffffffu);
                    reinterpret_cast<uint8_t *>(entry + 0xf)[0] = 1;
                }
            } else {
                FUN_004baaa0();
                auto check = *reinterpret_cast<void (**)(void *)>(DAT_008ecd78 + 0x18);
                if (reinterpret_cast<char (*)(void *)>(*reinterpret_cast<void **>(
                    check))(nullptr) != 0) {
                    FUN_004985e0();
                    FUN_004a14b0();
                }
            }
        } else {
            if (entry[0x10] != 0) {
                memmove(entry + 0x11, entry + 0x12, 8);
                memmove(entry + 0x14, entry + 0x15, 8);
                entry[10] = 0;
                entry[0x10]--;
                uint32_t stamp2 = static_cast<uint32_t>(FUN_005f0ddc());
                (void)stamp2;
                int *spawned2 = nullptr;
                if (entry[0] != 0) {
                    reinterpret_cast<uint8_t *>(entry[0])[0x25] = 1;
                    spawned2 = reinterpret_cast<int *>(FUN_004bbc10(entry[0],
                        entry[3], entry[4], entry[5], entry[6], entry[7],
                        entry[8], entry[0x11]));
                }
                entry[1] = reinterpret_cast<int>(spawned2);
                if (spawned2 != nullptr) {
                    *reinterpret_cast<uint32_t *>(spawned2 + 0x20) &= 0xffffdfffu;
                }
            } else {
                FUN_004ab3c0(reinterpret_cast<void *>(param_1), entry);
            }
        }
        if (node == nullptr) return;
    }
}

// 0x4ab7c0 — observed shape
void FUN_004ab7c0(void *self) {
    int *f = static_cast<int *>(self);
    f[0] = reinterpret_cast<int>(PTR_FUN_0070bffc);
    uint32_t *node = reinterpret_cast<uint32_t *>(f[1]);
    while (node != nullptr) {
        uint32_t *next = reinterpret_cast<uint32_t *>(node[0]);
        void **vt = *reinterpret_cast<void ***>(self);
        auto fn = reinterpret_cast<void (*)(void *)>(vt[2]);
        fn(node);
        node = next;
    }
    f[3] = 0;
    f[1] = 0;
    f[2] = 0;
    f[0] = reinterpret_cast<int>(PTR_LAB_0070bff0);
}

// 0x4ab800 — observed shape
void FUN_004ab800(uint32_t *param_1, uint32_t param_2) {
    param_1[0] = param_2;
    param_1[1] = 0;
    if (param_1[3] == 0) {
        uint32_t *slot = static_cast<uint32_t *>(FUN_00533c78(0x14));
        if (slot == nullptr) {
            param_1[3] = 0;
        } else {
            slot[0] = 0;
            slot[1] = 0;
            param_1[3] = reinterpret_cast<uint32_t>(slot);
        }
        FUN_0050baf0(FUN_004d1240, 0x400);
        uint32_t *obj1 = static_cast<uint32_t *>(FUN_00533c78(0xc0));
        uint32_t t1 = DAT_008ea008, s1 = DAT_00726380, w1 = DAT_0072637c;
        if (obj1 != nullptr) {
            obj1[1] = 0;
            obj1[0] = reinterpret_cast<uint32_t>(PTR_FUN_006fd14c);
            obj1[7] = 0;
            DAT_00727444++;
            obj1[0x19] = 0;
            obj1[0x2f] = 0;
            GetCurrentThreadId();
            FUN_004baae0(t1);
            obj1[8] = 0;
            FUN_004be3f0(obj1, 0, 0, 0, w1, s1, 0x80ffffffu, 0, 0, 0, 0, 0);
            if ((reinterpret_cast<uint8_t *>(obj1)[8 * 4] & 1) == 0) FUN_004baca0();
        }
        param_1[4] = reinterpret_cast<uint32_t>(obj1);
        uint32_t *shared = *reinterpret_cast<uint32_t **>(param_1[3]);
        if (shared != nullptr) shared[1]++;
        FUN_004bd640(shared);
        if (shared != nullptr) {
            int *ref = reinterpret_cast<int *>(shared) + 1;
            *ref = *ref - 1;
            if (*ref == 0) {
                void **vt = *reinterpret_cast<void ***>(shared);
                reinterpret_cast<void (*)(int)>(vt[0])(1);
            }
        }
        uint32_t *obj2 = static_cast<uint32_t *>(FUN_00533c78(0xc0));
        uint32_t t2 = DAT_008ea008, s2 = DAT_00726380, w2 = DAT_0072637c;
        if (obj2 != nullptr) {
            obj2[1] = 0;
            obj2[0] = reinterpret_cast<uint32_t>(PTR_FUN_006fd14c);
            obj2[7] = 0;
            DAT_00727444++;
            obj2[0x19] = 0;
            obj2[0x2f] = 0;
            GetCurrentThreadId();
            FUN_004baae0(t2);
            obj2[8] = 0;
            FUN_004be3f0(obj2, 0, 0, 0, w2, s2, 0x80ffffffu, 0, 0, 0, 0, 0);
            if ((reinterpret_cast<uint8_t *>(obj2)[8 * 4] & 1) == 0) FUN_004baca0();
        }
        param_1[5] = reinterpret_cast<uint32_t>(obj2);
    }
    *reinterpret_cast<uint32_t *>(&DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
    DAT_007263bc |= 0x1000;
    DAT_00726a84++;
    FUN_0050bbc0(0);
    DAT_00726a84--;
    DAT_007263bc = *reinterpret_cast<uint32_t *>(&DAT_007268f4 + DAT_00726a84 * 4);
}

// 0x4ab9e0 — observed shape
void FUN_004ab9e0(void *self, float param_1) {
    float *f = static_cast<float *>(self);
    void *blob = reinterpret_cast<void *>(static_cast<uintptr_t>(f[3]));
    if (blob != nullptr && reinterpret_cast<uint8_t *>(f)[2] == 0) {
        float acc = param_1 + f[1];
        f[1] = acc;
        if (acc < f[0]) {
            FUN_005f0ddc();
            FUN_004bd600();
            FUN_004bd600();
            FUN_00412900(0, 0, 100);
            FUN_00412900(0, 0, 100);
        } else {
            FUN_0050ba80();
            operator_delete(blob);
            f[3] = 0.0f;
            uint32_t *cb = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(f[4]));
            if (cb != nullptr) {
                void **vt = reinterpret_cast<void **>(cb[0]);
                reinterpret_cast<void (*)(int)>(vt[0])(1);
                f[4] = 0.0f;
            }
        }
    }
}
