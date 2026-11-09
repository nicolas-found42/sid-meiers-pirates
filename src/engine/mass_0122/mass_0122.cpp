#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00534660(int);
extern uint32_t* FUN_00545600();
extern int FUN_00545630();
extern void FUN_0057a3f0(int);
extern void FUN_00581300(uint32_t, uint32_t**);
extern void FUN_00534d60(int);
extern int FUN_00557b10(int);
extern void FUN_006b34a0(int);
extern void FUN_005606f0(uint32_t, int*);
extern int FUN_0054aa40(const char*);
extern int FUN_00535d80(const char*);
extern int FUN_00535230(const char*);
extern void FUN_00537af0(void*);
extern void FUN_005e1490(void*);
extern void* PTR_FUN_006c0980;
extern void* PTR_LAB_006fd148;
extern void* PTR_LAB_006c099c;
extern int DAT_00727444;
extern int DAT_00727448;

struct RefObj {
    void* vtbl;
    int refs;
};

static inline void ref_release(RefObj* o) {
    if (o && --o->refs == 0) {
        auto fn = (void(__thiscall*)(void*, int))(*(void***)o->vtbl)[0];
        fn((void*)o, 1);
    }
}
static inline RefObj* as_ref(uint32_t* p) { return (RefObj*)p; }

// 0x538020 — observed shape
void FUN_00538020(void* self, int param_1) {
    FUN_00534660(param_1);
    uint8_t* b = (uint8_t*)self;
    RefObj* cur = *(RefObj**)(b + 0x154);
    RefObj* nxt = as_ref(FUN_00545600());
    if (cur != nxt) {
        if (cur) ref_release(cur);
        *(RefObj**)(b + 0x154) = nxt;
        if (nxt) nxt->refs++;
    }
    int count = FUN_00545630();
    while (count != 0) {
        RefObj* item = as_ref(FUN_00545600());
        if (item) item->refs++;
        uint32_t idx = *(uint32_t*)(b + 0x164);
        uint32_t* slot = (uint32_t*)item;
        if (*(uint32_t*)(b + 0x160) <= idx) {
            FUN_0057a3f0(*(int*)(b + 0x16c) + (int)idx);
        }
        FUN_00581300(idx, &slot);
        if (item) ref_release(item);
        count--;
    }
    if (0x4010003u < *(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x1c)) {
        int c2 = FUN_00545630();
        while (c2 != 0) {
            RefObj* item = as_ref(FUN_00545600());
            if (item) item->refs++;
            uint32_t idx = *(uint32_t*)(b + 0x17c);
            uint32_t* slot = (uint32_t*)item;
            if (*(uint32_t*)(b + 0x178) <= idx) {
                FUN_0057a3f0(*(int*)(b + 0x184) + (int)idx);
            }
            FUN_00581300(idx, &slot);
            if (item) ref_release(item);
            c2--;
        }
        uint32_t kind = *(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x1c);
        if (0xa000106u < kind && kind < 0xa00010fu && (c2 = FUN_00545630()) != 0) {
            do {
                FUN_00545600();
                c2--;
            } while (c2 != 0);
        }
    }
}

// 0x538180 — observed shape
void FUN_00538180(void* self, int param_1) {
    (void)self;
    int obj = param_1;
    FUN_00534d60(param_1);
    uint8_t* b = (uint8_t*)(uintptr_t)obj;
    int err = FUN_00557b10(DAT_00727448);
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &err);
    }
    err = FUN_0054aa40("m_kViewFrustum");
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &err);
    }
    err = FUN_00535d80("m_kPort");
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &err);
    }
    err = FUN_00535230("m_kWorldDir");
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &err);
    }
    err = FUN_00535230("m_kWorldUp");
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &err);
    }
    err = FUN_00535230("m_kWorldRight");
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &err);
    }
}

// 0x5382e0 — observed shape
void FUN_005382e0(void* self, uint8_t param_1) {
    FUN_00537af0(self);
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x538390 — observed shape
void FUN_00538390(void* self, uint8_t param_1) {
    ((void**)self)[0] = PTR_FUN_006c0980;
    FUN_005e1490(self);
    operator_delete(((void**)self)[2]);
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x5383d0 — observed shape
void FUN_005383d0(void* self) {
    ((void**)self)[0] = PTR_LAB_006fd148;
    ((void**)self)[1] = nullptr;
    DAT_00727444++;
    ((void**)self)[0] = PTR_LAB_006c099c;
    ((void**)self)[2] = nullptr;
}
extern int FUN_005456c0(int);
extern void* thunk_FUN_00533c78(int);
extern void FUN_00538370(void*);
extern void FUN_00546930(void*);
extern void FUN_00546bc0(void*);
extern void FUN_00545900(void**, uint32_t*);
extern void FUN_00545120(void*, uint32_t);
extern void FUN_00546ad0(void*);
extern void* PTR_FUN_006c09d0;

// 0x538430 — observed shape
void FUN_00538430(void* self, int param_1) {
    uint8_t* b = (uint8_t*)self;
    int val = FUN_005456c0(*(int*)(b + 8));
    int* iface = *(int**)((uint8_t*)(uintptr_t)param_1 + 0x160);
    auto fn = (void(__thiscall*)(int*, int))(*(void***)iface)[3];
    fn(iface, val);
}

// 0x538460 — observed shape
// NEEDS_MANUAL: in_EAX fallback when param_1 null is register-defined; preserve compare shape with zero return.
uint32_t FUN_00538460(void* self_in_ecx, int* param_1) {
    if (!param_1) return 0;
    auto call_v4 = [](void* obj) -> uint8_t* {
        void** vtbl = *(void***)obj;
        auto fn = (uint8_t*(__thiscall*)(void*))vtbl[1];
        void* res = (void*)fn(obj);
        return *(uint8_t**)res;
    };
    uint8_t* a = call_v4((void*)param_1);
    uint8_t* b = call_v4(self_in_ecx);
    for (;;) {
        uint8_t ca = *a;
        uint8_t cb = *b;
        if (ca != cb) {
            int cmp = (ca < cb) ? -1 : 1;
            if (ca < cb) cmp = -1; else cmp = 1;
            if (ca < cb) return 0xFFFFFFFFu;
            return 1;
        }
        if (ca == 0) return 1;
        uint8_t da = a[1];
        uint8_t db = b[1];
        if (da != db) {
            return (da < db) ? 0xFFFFFFFFu : 1;
        }
        a += 2; b += 2;
        if (da == 0) return 1;
    }
}

// 0x5384d0 — observed shape
void FUN_005384d0(void* self, int param_1) {
    uint32_t* slots = (uint32_t*)self;
    slots[1] = (uint32_t)param_1;
    ((void**)self)[0] = PTR_FUN_006c0980;
    slots[3] = 0;
    uint32_t* buf = (uint32_t*)thunk_FUN_00533c78(param_1 << 2);
    slots[2] = (uint32_t)(uintptr_t)buf;
    for (uint32_t n = slots[1] & 0x3fffffff; n != 0; n--) {
        *buf = 0;
        buf++;
    }
    for (int i = 0; i != 0; i = i - 1) {
        *(uint8_t*)buf = 0;
        buf = (uint32_t*)((uint8_t*)buf + 1);
    }
    ((void**)self)[0] = PTR_FUN_006c09d0;
}

// 0x538520 — observed shape
void FUN_00538520(void* self, uint8_t param_1) {
    ((void**)self)[0] = PTR_FUN_006c09d0;
    FUN_005e1490(self);
    FUN_00538370(self);
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x538580 — observed shape
int* FUN_00538580(void* self_in_ecx, int* param_1) {
    FUN_00546930(self_in_ecx);
    FUN_00546bc0(self_in_ecx);
    void* local_1b8 = nullptr;
    uint32_t local_1b4[83] = {0};
    FUN_00545900(&local_1b8, local_1b4);
    FUN_00545120(local_1b8, local_1b4[0]);
    extern int* local_68_ref;
    uint32_t* puVar1 = (uint32_t*)local_68_ref;
    if (puVar1) puVar1[1]++;
    operator_delete(local_1b8);
    *param_1 = (int)(uintptr_t)puVar1;
    if (puVar1) {
        int old = (int)puVar1[1];
        puVar1[1] = (uint32_t)(old + 1);
        puVar1[1] = (uint32_t)old;
        if (old == 0) {
            auto fn = (void(__thiscall*)(void*, int))(*(void***)puVar1)[0];
            fn((void*)puVar1, 1);
        }
    }
    FUN_00546ad0(self_in_ecx);
    return param_1;
}
extern uint32_t FUN_005456b0(uint32_t);
extern void FUN_00557d40(void*);
extern void FUN_00557cb0(const char*, uint32_t);
extern int DAT_00727454;
extern int DAT_006c09fc;
extern uint32_t DAT_00717834;
extern uint32_t DAT_00717838;
extern uint8_t DAT_0071783c;
extern uint8_t DAT_0072745c;
extern int DAT_00727460;
extern int DAT_00727484;
extern int DAT_007178c8;
extern int DAT_007178ec;
extern int DAT_007274a8;
extern int DAT_00717910;

// 0x538630 — observed shape
void FUN_00538630(void* self, int param_1) {
    uint8_t* b = (uint8_t*)self;
    if (*(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x1c) < 0x5000006u) {
        *(uint32_t*)(b + 8) = 0;
        return;
    }
    int* iface = *(int**)((uint8_t*)(uintptr_t)param_1 + 0x15c);
    auto fn = (void(__thiscall*)(int*, int*))(*(void***)iface)[2];
    int local = param_1;
    fn(iface, &local);
    *(uint32_t*)(b + 8) = FUN_005456b0(0);
}

// 0x538680 — observed shape
uint32_t FUN_00538680(void* self) {
    int* piVar1 = (int*)FUN_00533c78(4);
    if (!piVar1) {
        piVar1 = nullptr;
    } else {
        int inner = FUN_00533c78(0x10);
        if (inner == 0) {
            *piVar1 = 0;
        } else {
            int obj = FUN_005384d0(0x25);
            *piVar1 = obj;
        }
    }
    void** vtbl = *(void***)self;
    auto get = (uint32_t(__thiscall*)(void*, int*))vtbl[2];
    uint32_t ret = get(self, piVar1);
    auto destroy = (void(__thiscall*)(void*, int*))vtbl[10];
    destroy(self, piVar1);
    if (piVar1) {
        if (*piVar1) {
            auto dtor = (void(__thiscall*)(void*, int))(*(void***)(uintptr_t)*piVar1)[0];
            dtor((void*)(uintptr_t)*piVar1, 1);
        }
        operator_delete(piVar1);
    }
    return ret;
}

// 0x5386f0 — observed shape
void FUN_005386f0(void* self, int param_1) {
    (void)self;
    int local_4 = FUN_00557b10(DAT_00727454);
    int obj = param_1;
    uint8_t* b = (uint8_t*)(uintptr_t)obj;
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &local_4);
    }
    int v = FUN_00557d40(&DAT_006c09fc);
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &v);
    }
    uint32_t ecx4 = *(uint32_t*)((uint8_t*)self + 4);
    int w = FUN_00557cb0("m_uiRefCount", ecx4);
    {
        uint32_t idx = *(uint32_t*)(b + 0xc);
        if (*(uint32_t*)(b + 8) <= idx) FUN_006b34a0(*(int*)(b + 0x14) + (int)idx);
        FUN_005606f0(idx, &w);
    }
}

// 0x5387b0 — observed shape
void FUN_005387b0(void* self, char param_1, int param_2) {
    uint32_t* s = (uint32_t*)self;
    if (param_2 != 4) param_2 = 8;
    s[6] = (uint32_t)param_2;
    s[5] = 0;
    s[4] = 0;
    s[3] = 0;
    s[2] = 0;
    int tag;
    if (param_1 == 0) {
        s[0] = 2;
        tag = 2;
    } else {
        s[0] = 3;
        tag = 3;
    }
    uint32_t uVar1 = DAT_00717834;
    uint32_t uVar2 = ((uint32_t)(param_2 == 4 ? 1 : 0) * 4 + 1) << (uint8_t)(DAT_0071783c & 0x1f);
    uVar2 &= DAT_00717838;
    s[8] = 0;
    s[7] = uVar2 | (((uint32_t)tag << ((uint8_t)DAT_0072745c & 0x1f)) & uVar1);
}

// 0x538830 — observed shape
void FUN_00538830(void* self, int param_1) {
    uint32_t* s = (uint32_t*)self;
    auto copy9 = [&](int* src) {
        uint32_t* dst = s;
        int* p = src;
        for (int i = 9; i != 0; i--) {
            *dst = (uint32_t)(uintptr_t)p;
            p++;
            dst++;
        }
    };
    switch (param_1) {
    case 0: copy9(&DAT_00727460); return;
    case 1: copy9(&DAT_00727484); return;
    case 2: copy9(&DAT_007178c8); return;
    case 3: copy9(&DAT_007178ec); return;
    case 4: case 5: case 6: {
        s[0] = (uint32_t)param_1;
        s[5] = 0; s[4] = 0; s[3] = 0; s[2] = 0; s[6] = 0;
        uint32_t u1 = DAT_00717834;
        s[8] = 0;
        s[7] = ((uint32_t)param_1 << ((uint8_t)DAT_0072745c & 0x1f)) & u1;
        return;
    }
    case 7: {
        s[0] = 7;
        s[5] = 0; s[4] = 0; s[3] = 0; s[2] = 0; s[6] = 0x18;
        uint32_t u1 = DAT_00717834;
        uint32_t u2 = (3u << ((uint8_t)DAT_0071783c & 0x1f)) & DAT_00717838;
        s[8] = 0;
        s[7] = u2 | ((7u << ((uint8_t)DAT_0072745c & 0x1f)) & u1);
        return;
    }
    case 8: copy9(&DAT_007274a8); return;
    case 9: copy9(&DAT_00717910); return;
    }
}
extern uint32_t DAT_00717840;
extern uint32_t DAT_00717850;
extern uint32_t DAT_00717860;
extern uint32_t DAT_00717870;

// 0x538960 — observed shape
void FUN_00538960(uint32_t param_1, int param_2, uint32_t* param_3, uint32_t* param_4) {
    int tz = 0;
    uint32_t v = param_1;
    if (param_1 != 0) {
        while ((v & 1) == 0) {
            tz++;
            v >>= 1;
        }
    }
    int ones = 0;
    uint32_t rest = param_1 >> (uint8_t)(tz & 0x1f);
    while ((rest & 1) != 0) {
        ones++;
        rest >>= 1;
    }
    uint32_t shiftTab[4];
    uint32_t maskTab[4];
    shiftTab[0] = DAT_00717850; shiftTab[1] = DAT_00717850; shiftTab[2] = DAT_00717850; shiftTab[3] = DAT_00717850;
    maskTab[0] = DAT_00717840; maskTab[1] = DAT_00717840; maskTab[2] = DAT_00717840; maskTab[3] = DAT_00717840;
    uint32_t shift2[4];
    uint32_t mask2[4];
    shift2[0] = DAT_00717870; shift2[1] = DAT_00717870; shift2[2] = DAT_00717870; shift2[3] = DAT_00717870;
    mask2[0] = DAT_00717860; mask2[1] = DAT_00717860; mask2[2] = DAT_00717860; mask2[3] = DAT_00717860;
    (void)shift2; (void)mask2;
    *param_3 = ((uint32_t)ones << (uint8_t)(DAT_00717850 & 0x1f)) & DAT_00717840;
    *param_4 = ((uint32_t)tz << (uint8_t)(DAT_00717870 & 0x1f)) & DAT_00717860;
}

// 0x5389d0 — observed shape
void FUN_005389d0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, int param_4, uint32_t param_5) {
    uint32_t* s = (uint32_t*)self;
    s[6] = param_5;
    s[2] = param_1;
    s[3] = param_2;
    s[4] = param_3;
    s[5] = (uint32_t)param_4;
    s[8] = 0;
    s[7] = 0;
    uint32_t a = param_1, b = param_2;
    FUN_00538960(param_1, 0, &a, &b);
    s[7] = a; s[8] = b;
    FUN_00538960(param_2, 1, &a, &b);
    s[7] |= a; s[8] |= b;
    FUN_00538960(param_3, 2, &a, &b);
    uint32_t acc = s[7] | a;
    s[7] = acc; s[8] |= b;
    if (param_4 == 0) {
        s[0] = 0;
    } else {
        FUN_00538960((uint32_t)param_4, 3, &a, &b);
        acc |= a;
        s[7] = acc; s[8] |= b;
        s[0] = 1;
    }
    s[7] = (uint32_t)(uint32_t)((param_4 != 0) ? 1 : 0) << (uint8_t)(DAT_0072745c & 0x1f);
    s[7] = (s[7] & DAT_00717834) | acc;
    int code = -1;
    switch (param_5) {
    case 4: code = 5; break;
    case 0x10: code = 2; break;
    case 0x18: code = 3; break;
    case 0x20: code = 4; break;
    default: return;
    }
    s[7] |= ((uint32_t)code << (uint8_t)(DAT_0071783c & 0x1f)) & DAT_00717838;
}

// 0x538b80 — observed shape
void FUN_00538b80(void* self, uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4) {
    uint32_t* s = (uint32_t*)self;
    s[6] = param_4;
    s[2] = param_1;
    s[3] = param_2;
    s[4] = 0;
    s[5] = (uint32_t)param_3;
    s[8] = 0;
    s[7] = 0;
    uint32_t a = param_1, b = param_2;
    FUN_00538960(param_1, 0, &a, &b);
    s[7] = a; s[8] = b;
    FUN_00538960(param_2, 1, &a, &b);
    uint32_t acc = s[7] | a;
    s[7] = acc; s[8] |= b;
    int tag;
    if (param_3 == 0) {
        s[0] = 8; tag = 8;
    } else {
        FUN_00538960((uint32_t)param_3, 3, &a, &b);
        acc |= a;
        s[7] = acc; s[8] |= b;
        s[0] = 9; tag = 9;
    }
    s[7] = ((uint32_t)tag << (uint8_t)(DAT_0072745c & 0x1f)) & DAT_00717834 | acc;
    int code = -1;
    switch (param_4) {
    case 4: code = 5; break;
    case 0x10: code = 2; break;
    case 0x18: code = 3; break;
    case 0x20: code = 4; break;
    default: return;
    }
    s[7] |= ((uint32_t)code << (uint8_t)(DAT_0071783c & 0x1f)) & DAT_00717838;
}

// 0x538d10 — observed shape
void FUN_00538d10(void* self, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5) {
    FUN_005389d0(self, p1, p2, p3, (int)p4, p5);
    ((uint32_t*)self)[1] = 0;
}

// 0x538d40 — observed shape
void FUN_00538d40(void* self, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4) {
    FUN_00538b80(self, p1, p2, (int)p3, p4);
    ((uint32_t*)self)[1] = 0;
}
