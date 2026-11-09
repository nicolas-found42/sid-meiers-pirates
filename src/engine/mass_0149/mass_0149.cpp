#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern void FUN_00538630(int p1);
extern void FUN_00557ab0(int p1);
extern uint32_t thunk_FUN_00533c78(uint32_t size);
extern void FUN_00545cc0();
extern void FUN_0059ab10(int p1);
extern void FUN_00538430(int *p1);
extern void FUN_00557ae0(int *p1);
extern void FUN_0059ab40(int *p1);
extern void operator_delete(void *p);

extern void *DAT_00727cd8;
extern int DAT_00727444;
extern void *PTR_FUN_006c0ba8;
extern void *PTR_LAB_006fd148;

// 0x556f90 — observed shape
void FUN_00556f90(void *self, int param_1) {
    uint8_t *base = (uint8_t *)self;
    int *countPtr = (int *)(base + 0x44);
    FUN_00538630(param_1);
    FUN_00557ab0(param_1);
    int *vt = *(int **)(param_1 + 0x15c);
    ((void (*)(int*, int))vt[2])(countPtr, 4);
    uint32_t alloc = thunk_FUN_00533c78((uint32_t)(*countPtr) * 0x4c);
    *(uint32_t *)(base + 0x48) = alloc;
    if (0x4000000u < *(uint32_t *)(param_1 + 0x1c)) {
        FUN_00545cc0();
    }
    char flag;
    if (*(uint32_t *)(param_1 + 0x1c) < 0x401000du) {
        flag = 1;
    } else {
        ((void (*)(char*, int))vt[2])(&flag, 1);
    }
    uint32_t idx = 0;
    if (*countPtr != 0) {
        int off = 0;
        do {
            int item = *(int *)(base + 0x48) + off;
            FUN_00557ab0(param_1);
            FUN_0059ab10(param_1);
            ushort *c = (ushort *)(item + 0x48);
            ((void (*)(ushort*, int))vt[2])(c, 2);
            if (flag == 0) {
                *(uint32_t *)(item + 0x44) = 0;
            } else {
                uint32_t a = thunk_FUN_00533c78((uint32_t)(*c) << 3);
                *(uint32_t *)(item + 0x44) = a;
                if (*c != 0) {
                    uint32_t j = 0;
                    do {
                        int e = *(int *)(item + 0x44) + j * 8;
                        ((void (*)(int, int))vt[2])(e, 2);
                        ((void (*)(int, int))vt[2])(e + 4, 4);
                        j++;
                    } while (j < *c);
                }
            }
            idx++;
            off += 0x4c;
        } while (idx < *(uint32_t *)(base + 0x44));
    }
    if (*(int *)(param_1 + 0x1c) == 0x4010009) {
        ((void (*)(char*, int))vt[2])(&flag - 0x11, 1);
    }
}

// 0x557100 — observed shape
void FUN_00557100(void *self, int *param_1) {
    uint8_t *base = (uint8_t *)self;
    FUN_00538430(param_1);
    FUN_00557ae0(param_1);
    int v = *(int *)(param_1[0x58]);
    ((void (*)(int*, int))(*(void *(*)(int*,int))v + 0xc))( (int*)(base + 0x44), 4);
    ((void (*)(uint32_t))(*(void **)param_1 + 0x2c))(*(uint32_t *)(base + 0xc));
    char b = (*(int *)(*(int *)(base + 0x48) + 0x44) != 0) ? 1 : 0;
    ((void (*)(char*, int))(*(void *(*)(char*,int))v + 0xc))(&b, 1);
    uint32_t idx = 0;
    if (*(int *)(base + 0x44) != 0) {
        int off = 0;
        do {
            int item = *(int *)(base + 0x48) + off;
            FUN_00557ae0(param_1);
            FUN_0059ab40(param_1);
            ((void (*)(int, int))(*(void *(*)(int,int))v + 0xc))(item + 0x48, 2);
            if (b != 0) {
                uint32_t j = 0;
                if (*(short *)(item + 0x48) != 0) {
                    do {
                        int e = *(int *)(item + 0x44) + j * 8;
                        ((void (*)(int, int))(*(void *(*)(int,int))v + 0xc))(e, 2);
                        ((void (*)(int, int))(*(void *(*)(int,int))v + 0xc))(e + 4, 4);
                        j++;
                    } while (j < *(ushort *)(item + 0x48));
                }
            }
            idx++;
            off += 0x4c;
        } while (idx < *(uint32_t *)(base + 0x44));
    }
}

// 0x557210 — observed shape
bool FUN_00557210(uint32_t *a, uint32_t *b) {
    while (true) {
        if (a == nullptr) return b == nullptr;
        if (b == nullptr || a[1] != b[1]) return false;
        a = (uint32_t *)a[0];
        b = (uint32_t *)b[0];
    }
}

// 0x557240 — observed shape
void FUN_00557240(int *param_1, int *param_2) {
    if (param_1 != nullptr) {
        int n = (int)thunk_FUN_00533c78(8);
        *param_2 = n;
        *(int *)(n + 4) = param_1[1];
        int cur = *param_1;
        uint32_t *prev = (uint32_t *)*param_2;
        while (cur != 0) {
            uint32_t *nn = (uint32_t *)thunk_FUN_00533c78(8);
            *prev = (uint32_t)nn;
            param_1 = (int *)*param_1;
            nn[1] = (uint32_t)param_1[1];
            prev = nn;
            cur = *param_1;
        }
        *prev = 0;
    }
}

// 0x557290 — observed shape
void FUN_00557290(void) {
    uint32_t **p = (uint32_t **)&DAT_00727cd8;
    if (*p != nullptr) {
        int cnt = (int)(*p)[1];
        (*p)[1] = cnt - 1;
        if (cnt - 1 == 0) {
            ((void (*)(int))(*p)[0])(1);
        }
        *p = nullptr;
    }
}

extern void *PTR_FUN_006c2b94;
extern void *DAT_007275ac;
extern void *DAT_00727d2c;
extern void *DAT_00727980;
extern void *DAT_007275fc;
extern void *DAT_00727cb0;
extern void *DAT_00727c9c;
extern void *DAT_00727d38;
extern void *DAT_00727594;
extern void *DAT_007275f0;
extern void *DAT_007275c4;
extern void *DAT_00727618;
extern void *DAT_007275b8;

// 0x5572c0 — observed shape
void FUN_005572c0(void *self) {
    uint32_t **p = (uint32_t **)self;
    p[0] = (uint32_t *)PTR_FUN_006c0ba8;
    int i = (int)p[3];
    while (i != 0) {
        uint32_t *n = p[3];
        p[3] = (uint32_t *)n[0];
        operator_delete(n);
        i = (int)p[3];
    }
    i = (int)p[4];
    while (i != 0) {
        uint32_t *n = p[4];
        p[4] = (uint32_t *)n[0];
        operator_delete(n);
        i = (int)p[4];
    }
    i = (int)p[5];
    while (i != 0) {
        uint32_t *n = p[5];
        p[5] = (uint32_t *)n[0];
        operator_delete(n);
        i = (int)p[5];
    }
    p[0] = (uint32_t *)PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
}

// 0x557340 — observed shape
uint32_t * FUN_00557340(void *self) {
    uint8_t *s = (uint8_t *)self;
    uint32_t *np = (uint32_t *)thunk_FUN_00533c78(0x20);
    if (np != nullptr) {
        np[0] = (uint32_t)PTR_LAB_006fd148;
        np[1] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        np[0] = (uint32_t)PTR_FUN_006c0ba8;
        *(uint8_t *)(np + 2) = 0;
        np[3] = 0; np[4] = 0; np[5] = 0; np[6] = 0; np[7] = 0;
    }
    *(uint8_t *)(np + 2) = *(uint8_t *)(s + 8);
    FUN_00557240(*(int *)(s + 0xc), (int *)(np + 3));
    FUN_00557240(*(int *)(s + 0x10), (int *)(np + 4));
    FUN_00557240(*(int *)(s + 0x14), (int *)(np + 5));
    np[6] = *(uint32_t *)(s + 0x18);
    np[7] = *(uint32_t *)(s + 0x1c);
    return np;
}

// 0x5573d0 — observed shape
bool FUN_005573d0(void *self, int param_1) {
    uint8_t *s = (uint8_t *)self;
    if (param_1 != 0 &&
        *(int *)(s + 0x18) == *(int *)(param_1 + 0x18) &&
        *(int *)(s + 0x1c) == *(int *)(param_1 + 0x1c)) {
        if (FUN_00557210(*(uint32_t **)(s + 0xc), *(uint32_t **)(param_1 + 0xc))) {
            if (FUN_00557210(*(uint32_t **)(s + 0x10), *(uint32_t **)(param_1 + 0x10))) {
                return FUN_00557210(*(uint32_t **)(s + 0x14), *(uint32_t **)(param_1 + 0x14));
            }
        }
    }
    return false;
}

// 0x557440 — observed shape
void FUN_00557440(int *param_1, int param_2) {
    int key = *(int *)(param_2 + 0xb8);
    uint32_t *node = (uint32_t *)*param_1;
    if (node == nullptr || (uint32_t)key < (uint32_t)*(int *)(node[1] + 0xb8)) {
        int *nn = (int *)thunk_FUN_00533c78(8);
        nn[1] = param_2;
        *nn = *param_1;
        *param_1 = (int)nn;
        return;
    }
    if (key != *(int *)(node[1] + 0xb8)) {
        uint32_t *nx = (uint32_t *)*node;
        if (nx != nullptr) {
            uint32_t *prev = node;
            do {
                node = nx;
                if ((uint32_t)key <= (uint32_t)*(int *)(node[1] + 0xb8)) {
                    int *payload = (int *)(node + 1);
                    nx = node;
                    node = prev;
                    if (key == *(int *)(*payload + 0xb8)) return;
                    break;
                }
                nx = (uint32_t *)*node;
                prev = node;
            } while (nx != nullptr);
        }
        int *nn = (int *)thunk_FUN_00533c78(8);
        nn[1] = param_2;
        *nn = (int)nx;
        *(int *)node = (int)nn;
    }
}

// 0x5574c0 — observed shape
void FUN_005574c0(uint32_t **param_1, int param_2) {
    int key = *(int *)(param_2 + 0xb8);
    uint32_t *node = *param_1;
    if (node != nullptr && (uint32_t)*(int *)(node[1] + 0xb8) <= (uint32_t)key) {
        if (key == *(int *)(node[1] + 0xb8)) {
            *param_1 = (uint32_t *)*node;
            operator_delete(node);
            return;
        }
        uint32_t *nx = (uint32_t *)*node;
        if (nx != nullptr) {
            uint32_t *cur;
            while ((cur = nx, (uint32_t)*(int *)(cur[1] + 0xb8) < (uint32_t)key)) {
                nx = (uint32_t *)*cur;
                node = cur;
                if (nx == nullptr) return;
            }
            if (key == *(int *)(cur[1] + 0xb8)) {
                *node = *cur;
                operator_delete(cur);
            }
        }
    }
}

// 0x557530 — observed shape
void FUN_00557530(void *self, int *param_1) {
    uint8_t *s = (uint8_t *)self;
    if (param_1 != nullptr) {
        int kind = ((int (*)(void))*(void **)param_1)() ;
        // Observed: (*(code **)(*param_1 + 0x70))()
        // Reproduce via vtable offset 0x70 (28th entry).
        // The call above is inlined form; actual offset call:
        {
            void **vt = *(void ***)param_1;
            int (*fn)() = (int (*)())vt[0x70 / 4];
            kind = fn();
        }
        if (kind < 4) {
            FUN_00557440((int *)(s + 0xc), (int)param_1);
            return;
        }
        switch (param_1[0x54]) {
        case 0:
            FUN_00557440((int *)(s + 0x10), (int)param_1);
            *(uint8_t *)(s + 8) = 1;
            return;
        case 1:
            FUN_00557440((int *)(s + 0x14), (int)param_1);
            *(uint8_t *)(s + 8) = 1;
            return;
        case 2:
            *(int **)(s + 0x18) = param_1;
            *(uint8_t *)(s + 8) = 1;
            return;
        case 3:
            *(int **)(s + 0x1c) = param_1;
            break;
        }
        *(uint8_t *)(s + 8) = 1;
    }
}

// 0x5575c0 — observed shape
void FUN_005575c0(void *self, int *param_1) {
    uint8_t *s = (uint8_t *)self;
    if (param_1 != nullptr) {
        void **vt = *(void ***)param_1;
        int (*fn)() = (int (*)())vt[0x70 / 4];
        int kind = fn();
        if (kind < 4) {
            FUN_005574c0((uint32_t **)(s + 0xc), (int)param_1);
            return;
        }
        switch (param_1[0x54]) {
        case 0:
            FUN_005574c0((uint32_t **)(s + 0x10), (int)param_1);
            break;
        case 1:
            FUN_005574c0((uint32_t **)(s + 0x14), (int)param_1);
            break;
        case 2:
            if (param_1 == *(int **)(s + 0x18)) {
                *(uint32_t *)(s + 0x18) = 0;
            }
            break;
        case 3:
            if (param_1 == *(int **)(s + 0x1c)) {
                *(uint32_t *)(s + 0x1c) = 0;
            }
            break;
        }
        if (*(int *)(s + 0x10) == 0 && *(int *)(s + 0x14) == 0 &&
            *(int *)(s + 0x18) == 0 && *(int *)(s + 0x1c) == 0) {
            *(uint8_t *)(s + 8) = 0;
            return;
        }
        *(uint8_t *)(s + 8) = 1;
    }
}

// 0x557680 — observed shape
void FUN_00557680(void *self, int param_1) {
    uint32_t **p = (uint32_t **)self;
    p[0] = (uint32_t *)PTR_LAB_006fd148;
    p[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    p[0] = (uint32_t *)PTR_FUN_006c2b94;
    uint32_t **slot = p + 2;
    *slot = 0;
    for (int i = 3; i <= 0xd; i++) p[i] = 0;
    int remaining = 0xc;
    uint8_t *base = (uint8_t *)self;
    do {
        uint32_t *old = *slot;
        uint32_t *src = *(uint32_t **)(param_1 - (int)base + (int)slot);
        if (old != src) {
            if (old != nullptr) {
                int *cnt = (int *)(old + 1);
                *cnt = *cnt + -1;
                if (*cnt == 0) {
                    ((void (*)(int))old[0])(1);
                }
            }
            *slot = (uint32_t *)*(uint32_t *)((uint8_t *)param_1 - base + (uint8_t *)slot);
            int nv = *(int *)((uint8_t *)param_1 - base + (uint8_t *)slot);
            if (nv != 0) {
                *(int *)(nv + 4) = *(int *)(nv + 4) + 1;
            }
        }
        slot++;
        remaining--;
    } while (remaining != 0);
}

// 0x557710 — observed shape
void FUN_00557710(void *self) {
    uint32_t **p = (uint32_t **)self;
    p[0] = (uint32_t *)PTR_FUN_006c2b94;
    uint32_t **cur = p + 0xe;
    int remaining = 0xc;
    do {
        uint32_t *old = cur[-1];
        cur--;
        if (old != nullptr) {
            int *cnt = (int *)(old + 1);
            *cnt = *cnt + -1;
            if (*cnt == 0) {
                ((void (*)(int))old[0])(1);
            }
        }
        remaining--;
    } while (remaining != 0);
    p[0] = (uint32_t *)PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
}

// 0x557750 — observed shape
void FUN_00557750(void *self, uint8_t param_1) {
    FUN_00557710(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x557770 — observed shape
// Repeated refcounted-assign pattern over 12 slots at offsets
// 0x08,0x0c,0x10,0x14,0x18,0x1c,0x20,0x24,0x28,0x2c,0x30,0x34
// from globals DAT_007275ac, DAT_00727d2c, DAT_00727980, DAT_007275fc,
// DAT_00727cb0, DAT_00727c9c, DAT_00727d38, DAT_00727594, DAT_007275f0,
// DAT_007275c4, DAT_00727618, DAT_007275b8.
void FUN_00557770(void *self) {
    uint8_t *s = (uint8_t *)self;
    void *globals[12] = {
        DAT_007275ac, DAT_00727d2c, DAT_00727980, DAT_007275fc,
        DAT_00727cb0, DAT_00727c9c, DAT_00727d38, DAT_00727594,
        DAT_007275f0, DAT_007275c4, DAT_00727618, DAT_007275b8
    };
    for (int i = 0; i < 12; i++) {
        uint32_t *nw = (uint32_t *)globals[i];
        uint32_t *old = *(uint32_t **)(s + 8 + i * 4);
        if (old != nw) {
            if (old != nullptr) {
                int *cnt = (int *)(old + 1);
                *cnt = *cnt + -1;
                if (*cnt == 0) {
                    ((void (*)(int))old[0])(1);
                }
            }
            *(uint32_t **)(s + 8 + i * 4) = nw;
            if (nw != nullptr) {
                nw[1] = nw[1] + 1;
            }
        }
    }
}

// 0x557940 — observed shape
void FUN_00557940(void *self) {
    uint32_t **p = (uint32_t **)self;
    p[0] = (uint32_t *)PTR_LAB_006fd148;
    p[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    p[0] = (uint32_t *)PTR_FUN_006c2b94;
    for (int i = 2; i <= 0xd; i++) p[i] = 0;
    FUN_00557770(self);
}

extern void FUN_0053c420();
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern void *FUN_0053cc20(void *out);
extern void *FUN_0053ca60(void *out, void *v);
extern bool FUN_0053c450(int p1);
extern bool FUN_00428470(int p1);

// 0x557990 — observed shape
void FUN_00557990(void *self) {
    uint8_t *s = (uint8_t *)self;
    FUN_0053c420();
    *(uint32_t *)(s + 0x24) = DAT_00727430;
    *(uint32_t *)(s + 0x28) = DAT_00727434;
    uint32_t v = DAT_00727438;
    *(uint32_t *)(s + 0x30) = 0x3f800000;
    *(uint32_t *)(s + 0x2c) = v;
}

// 0x5579c0 — observed shape
void FUN_005579c0(void *self, uint32_t *param_1) {
    uint8_t *s = (uint8_t *)self;
    uint8_t local_24[36];
    uint8_t local_30[12];
    uint32_t *src = (uint32_t *)FUN_0053cc20(local_24);
    for (int i = 0; i < 9; i++) {
        param_1[i] = src[i];
    }
    param_1[0xc] = (uint32_t)(1.0f / *(float *)(s + 0x30));
    float v[3];
    v[0] = -*(float *)(s + 0x24);
    v[1] = -*(float *)(s + 0x28);
    v[2] = -*(float *)(s + 0x2c);
    float *r = (float *)FUN_0053ca60(local_30, v);
    float scale = *(float *)&param_1[0xc];
    param_1[9] = *(uint32_t *)&(scale * r[0]);
    param_1[10] = *(uint32_t *)&(scale * r[1]);
    param_1[0xb] = *(uint32_t *)&(scale * r[2]);
}

// 0x557a60 — observed shape
uint32_t FUN_00557a60(void *self, int param_1) {
    uint8_t *s = (uint8_t *)self;
    if (FUN_0053c450(param_1)) {
        if (!FUN_00428470(param_1 + 0x24) &&
            *(float *)(s + 0x30) == *(float *)(param_1 + 0x30)) {
            return 0;
        }
    }
    return 1;
}
