// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room reconstruction from
// Ghidra 12.2 pseudocode of Sid Meier's Pirates! (2004) PE32 i386.
// Batch mass_0307: 0x654a60-0x656380.
#include <cstdint>
#include <cstddef>
#include <cstdlib>

// Byte source shared by the packet readers below: buffer pointer at +0x00,
// remaining count at +0x04, refill callback at +0x0c.
struct ByteStream {
    unsigned char* cur;      // +0x00
    int avail;               // +0x04
    int unk_08;              // +0x08
    int (*refill)(void);     // +0x0c
};

extern int FUN_006549a0(int* self);
extern void FUN_006922e0(void* self);
extern int FUN_00692350(int* self);
extern int FUN_00692380(int* self);
extern void FUN_00692320(int* self);
// 0x6551e0 is defined later in this file; the call sites below precede it.
extern int FUN_006551e0(int* self);

// 0x654a60 — observed shape
int FUN_00654a60(int* self) {
    int state = self[5];
    if ((state == 0xcd || state == 0xce) && self[0x10] == 0) {
        if ((unsigned)self[0x23] < (unsigned)self[0x1d]) {
            int* obj = (int*)(intptr_t)self[0];
            obj[5] = 0x43;
            ((void (*)(int*))(intptr_t)obj[0])(self);
        }
        ((void (*)(int*))(intptr_t)(*(int*)((intptr_t)self[0x6a] + 4)))(self);
        self[5] = 0xd2;
    } else if (state == 0xcf) {
        self[5] = 0xd2;
    } else if (state != 0xd2) {
        int* obj = (int*)(intptr_t)self[0];
        obj[5] = 0x14;
        obj[6] = state;
        ((void (*)(int*))(intptr_t)obj[0])(self);
    }
    int iVar2 = *(int*)((intptr_t)self[0x6e] + 0x14);
    for (;;) {
        if (iVar2 != 0) {
            ((void (*)(int*))(intptr_t)(*(int*)((intptr_t)self[6] + 0x18)))(self);
            FUN_006922e0(self);
            return 1;
        }
        iVar2 = ((int (*)(int*))(intptr_t)(*(int*)(intptr_t)self[0x6e]))(self);
        if (iVar2 == 0) break;
        iVar2 = *(int*)((intptr_t)self[0x6e] + 0x14);
    }
    return 0;
}

// 0x654b20 — observed shape
int FUN_00654b20(int* self, int param_2) {
    int state = self[5];
    if (state != 200 && state != 0xc9) {
        int* obj = (int*)(intptr_t)self[0];
        obj[5] = 0x14;
        obj[6] = state;
        ((void (*)(int*))(intptr_t)obj[0])(self);
    }
    int r = FUN_006549a0(self);
    if (r == 1) {
        r = 1;
    } else if (r == 2) {
        if (param_2 != 0) {
            int* obj = (int*)(intptr_t)self[0];
            obj[5] = 0x33;
            ((void (*)(int*))(intptr_t)obj[0])(self);
        }
        FUN_006922e0(self);
        return 2;
    }
    return r;
}

// 0x654b90 — observed shape (receiver arrives in ESI)
int FUN_00654b90(void* self_ = nullptr) {
    int* self = (int*)self_;
    int obj = self[0];
    *(int*)(intptr_t)(obj + 0x14) = 0x66;
    ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(obj + 4)))();
    if (*(int*)((intptr_t)self[0x6f] + 0xc) != 0) {
        int* ev = (int*)(intptr_t)self[0];
        ev[5] = 0x3d;
        ((void (*)(void))(intptr_t)ev[0])();
    }
    unsigned char* q = (unsigned char*)self + 0xf8;
    for (int n = 0x10; n != 0; --n) {
        q[-0x10] = 0;
        q[0] = 1;
        q[0x10] = 5;
        ++q;
    }
    self[0x46] = 0;
    self[10] = 0;
    self[0x4c] = 0;
    self[0x47] = 0;
    *((unsigned char*)self + 0x122) = 0;
    self[0x4a] = 0;
    *((unsigned char*)self + 0x12c) = 0;
    *((unsigned char*)self + 0x120) = 1;
    *((unsigned char*)self + 0x121) = 1;
    *(unsigned short*)((unsigned char*)self + 0x124) = 1;
    *(unsigned short*)((unsigned char*)self + 0x126) = 1;
    *(int*)((intptr_t)self[0x6f] + 0xc) = 1;
    return 1;
}

// 0x654c40 — observed shape (receiver ESI, first args in ECX/EDX)
int FUN_00654c40(void* self_, int in_ECX = 0, int in_EDX = 0) {
    int* self = (int*)self_;
    ByteStream* bs = (ByteStream*)(intptr_t)self[6];
    int avail = bs->avail;
    unsigned char* p = bs->cur;
    self[0x38] = in_ECX;
    self[0x39] = in_EDX;
    bool failed = false;
    auto rd = [&]() -> int {
        if (avail == 0) {
            avail = bs->refill();
            if (avail == 0) { failed = true; return 0; }
            p = bs->cur;
            avail = bs->avail;
        }
        int v = *p;
        --avail;
        ++p;
        return v;
    };
    int uVar1 = rd(); if (failed) return 0;
    int uVar2 = rd(); if (failed) return 0;
    self[0x36] = rd(); if (failed) return 0;
    self[8] = rd() << 8; if (failed) return 0;
    self[8] = self[8] + rd(); if (failed) return 0;
    self[7] = rd() << 8; if (failed) return 0;
    self[7] = self[7] + rd(); if (failed) return 0;
    self[9] = rd(); if (failed) return 0;

    int obj = *self;
    *(int*)(intptr_t)(obj + 0x18) = self[0x69];
    *(int*)(intptr_t)(obj + 0x1c) = self[7];
    *(int*)(intptr_t)(obj + 0x20) = self[8];
    *(int*)(intptr_t)(obj + 0x24) = self[9];
    *(int*)(intptr_t)(obj + 0x14) = 100;
    ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(obj + 4)))();

    if (*(int*)((intptr_t)self[0x6f] + 0x10) != 0) {
        int* ev = (int*)(intptr_t)*self;
        ev[5] = 0x3a;
        ((void (*)(void))(intptr_t)ev[0])();
    }
    if (self[8] == 0 || self[7] == 0 || self[9] < 1) {
        int* ev = (int*)(intptr_t)*self;
        ev[5] = 0x20;
        ((void (*)(void))(intptr_t)ev[0])();
    }
    if ((uVar1 << 8 | uVar2) - 8 != self[9] * 3) {
        int* ev = (int*)(intptr_t)*self;
        ev[5] = 0xb;
        ((void (*)(void))(intptr_t)ev[0])();
    }
    if (self[0x37] == 0) {
        self[0x37] = ((int (*)(void))(intptr_t)(*(int*)(intptr_t)self[1]))();
    }
    int* local_c = (int*)(intptr_t)self[0x37];
    for (unsigned i = 0; (int)i < self[9]; ++i) {
        local_c[1] = (int)i;
        local_c[0] = rd(); if (failed) return 0;
        int bVar3 = rd(); if (failed) return 0;
        local_c[2] = bVar3 >> 4;
        local_c[3] = bVar3 & 0xf;
        local_c[4] = rd(); if (failed) return 0;
        int o2 = *self;
        *(int*)(intptr_t)(o2 + 0x18) = local_c[0];
        *(int*)(intptr_t)(o2 + 0x1c) = local_c[2];
        *(int*)(intptr_t)(o2 + 0x20) = local_c[3];
        *(int*)(intptr_t)(o2 + 0x24) = local_c[4];
        *(int*)(intptr_t)(o2 + 0x14) = 0x65;
        ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(o2 + 4)))();
        local_c += 0x15;
    }
    *(int*)((intptr_t)self[0x6f] + 0x10) = 1;
    bs->cur = p;
    bs->avail = avail;
    return 1;
}

// 0x654f20 — observed shape (receiver ESI)
int FUN_00654f20(void* self_ = nullptr) {
    int* self = (int*)self_;
    ByteStream* bs = (ByteStream*)(intptr_t)self[6];
    int avail = bs->avail;
    unsigned char* p = bs->cur;
    if (*(int*)((intptr_t)self[0x6f] + 0x10) == 0) {
        int* ev = (int*)(intptr_t)*self;
        ev[5] = 0x3e;
        ((void (*)(void))(intptr_t)ev[0])();
    }
    bool failed = false;
    auto rd = [&]() -> int {
        if (avail == 0) {
            avail = bs->refill();
            if (avail == 0) { failed = true; return 0; }
            p = bs->cur;
            avail = bs->avail;
        }
        int v = *p;
        --avail;
        ++p;
        return v;
    };
    int uVar1 = rd(); if (failed) return 0;
    int uVar2 = rd(); if (failed) return 0;
    int uVar8 = rd(); if (failed) return 0;

    int obj = *self;
    *(int*)(intptr_t)(obj + 0x14) = 0x67;
    *(int*)(intptr_t)(obj + 0x18) = uVar8;
    ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(obj + 4)))();

    if ((uVar1 << 8 | uVar2) != uVar8 * 2 + 6 || uVar8 == 0 || 4 < uVar8) {
        int* ev = (int*)(intptr_t)*self;
        ev[5] = 0xb;
        ((void (*)(void))(intptr_t)ev[0])();
    }
    self[0x53] = uVar8;
    int local_18 = 0;
    int* local_10 = self + 0x54;
    if (uVar8 != 0) {
        do {
            int uVar9 = rd(); if (failed) return 0;
            int bVar3 = rd(); if (failed) return 0;
            int* puVar14 = (int*)(intptr_t)self[0x37];
            bool found = false;
            int iVar7 = 0;
            if (0 < self[9]) {
                do {
                    if (uVar9 == puVar14[0]) { found = true; break; }
                    iVar7 = iVar7 + 1;
                    puVar14 += 0x15;
                } while (iVar7 < self[9]);
            }
            if (!found) {
                int* ev = (int*)(intptr_t)*self;
                ev[5] = 5;
                ev[6] = uVar9;
                ((void (*)(void))(intptr_t)ev[0])();
            }
            puVar14[6] = bVar3 & 0xf;
            *local_10 = (int)(intptr_t)puVar14;
            int iVar6 = *self;
            puVar14[5] = (int)((unsigned)bVar3 >> 4);
            *(unsigned*)(intptr_t)(iVar6 + 0x18) = (unsigned)uVar9;
            *(int*)(intptr_t)(iVar6 + 0x1c) = puVar14[5];
            *(int*)(intptr_t)(iVar6 + 0x20) = puVar14[6];
            *(int*)(intptr_t)(iVar6 + 0x14) = 0x68;
            ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar6 + 4)))();
            local_18 = local_18 + 1;
            local_10 = local_10 + 1;
        } while (local_18 < (int)uVar8);
    }
    self[0x65] = rd(); if (failed) return 0;
    self[0x66] = rd(); if (failed) return 0;
    int tail = rd(); if (failed) return 0;
    unsigned uLow = (unsigned)tail & 0xf;
    int iHigh = tail >> 4;
    self[0x68] = (int)uLow;
    int obj2 = *self;
    *(int*)(intptr_t)(obj2 + 0x18) = self[0x65];
    *(int*)(intptr_t)(obj2 + 0x1c) = self[0x66];
    *(int*)(intptr_t)(obj2 + 0x20) = iHigh;
    self[0x67] = iHigh;
    *(unsigned*)(intptr_t)(obj2 + 0x24) = uLow;
    *(int*)(intptr_t)(obj2 + 0x14) = 0x69;
    ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(obj2 + 4)))();
    self[0x25] = self[0x25] + 1;
    *(int*)((intptr_t)self[0x6f] + 0x14) = 0;
    bs->cur = p;
    bs->avail = avail;
    return 1;
}

// 0x6554b0 — observed shape
int FUN_006554b0(int* param_1) {
    ByteStream* puVar3 = (ByteStream*)(intptr_t)param_1[6];
    int iVar5 = puVar3->avail;
    unsigned char* puVar11 = puVar3->cur;
    if (iVar5 == 0) {
        iVar5 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
        if (iVar5 == 0) return 0;
        puVar11 = puVar3->cur;
        iVar5 = puVar3->avail;
    }
    unsigned char uVar1 = *puVar11;
    iVar5 = iVar5 - 1;
    puVar11 = puVar11 + 1;
    if (iVar5 == 0) {
        iVar5 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
        if (iVar5 == 0) return 0;
        puVar11 = puVar3->cur;
        iVar5 = puVar3->avail;
    }
    iVar5 = iVar5 - 1;
    int local_8 = ((uVar1 << 8) | *puVar11) - 2;
    unsigned char* pbVar12 = puVar11 + 1;
    if (0 < local_8) {
        do {
            if (iVar5 == 0) {
                iVar5 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
                if (iVar5 == 0) return 0;
                pbVar12 = puVar3->cur;
                iVar5 = puVar3->avail;
            }
            unsigned char bVar2 = *pbVar12;
            int iVar6 = *param_1;
            int iVar7 = (int)((unsigned)bVar2 >> 4);
            *(int*)(intptr_t)(iVar6 + 0x14) = 0x51;
            unsigned uVar9 = bVar2 & 0xf;
            *(unsigned*)(intptr_t)(iVar6 + 0x18) = uVar9;
            iVar5 = iVar5 - 1;
            pbVar12 = pbVar12 + 1;
            *(int*)(intptr_t)(iVar6 + 0x1c) = iVar7;
            ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar6 + 4)))(param_1, 1);
            if (3 < uVar9) {
                int* ev = (int*)(intptr_t)*param_1;
                ev[5] = 0x1f;
                ev[6] = (int)uVar9;
                ((void (*)(int*))(intptr_t)ev[0])(param_1);
            }
            if (param_1[uVar9 + 0x2a] == 0) {
                param_1[uVar9 + 0x2a] = FUN_00692350(param_1);
            }
            iVar6 = param_1[uVar9 + 0x2a];
            int* local_14 = (int*)0x006f0b38;
            do {
                unsigned short uVar8;
                if (iVar7 == 0) {
                    if (iVar5 == 0) {
                        iVar5 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
                        if (iVar5 == 0) return 0;
                        pbVar12 = puVar3->cur;
                        iVar5 = puVar3->avail;
                    }
                    uVar8 = (unsigned short)*pbVar12;
                } else {
                    if (iVar5 == 0) {
                        iVar5 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
                        if (iVar5 == 0) return 0;
                        pbVar12 = puVar3->cur;
                        iVar5 = puVar3->avail;
                    }
                    unsigned char bVar2b = *pbVar12;
                    iVar5 = iVar5 - 1;
                    pbVar12 = pbVar12 + 1;
                    if (iVar5 == 0) {
                        iVar5 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
                        if (iVar5 == 0) return 0;
                        pbVar12 = puVar3->cur;
                        iVar5 = puVar3->avail;
                    }
                    uVar8 = (unsigned short)((bVar2b << 8) | *pbVar12);
                }
                *(unsigned short*)(intptr_t)(iVar6 + *local_14 * 2) = uVar8;
                iVar5 = iVar5 - 1;
                local_14 = local_14 + 1;
                pbVar12 = pbVar12 + 1;
            } while ((intptr_t)local_14 < 0x6f0c38);
            if (1 < *(int*)(intptr_t)(*param_1 + 0x68)) {
                unsigned short* puVar10 = (unsigned short*)(intptr_t)(iVar6 + 4);
                int n = 8;
                do {
                    int o = *param_1;
                    *(unsigned*)(intptr_t)(o + 0x18) = (unsigned)puVar10[-2];
                    *(unsigned*)(intptr_t)(o + 0x1c) = (unsigned)puVar10[-1];
                    *(unsigned*)(intptr_t)(o + 0x20) = (unsigned)puVar10[0];
                    *(unsigned*)(intptr_t)(o + 0x24) = (unsigned)puVar10[1];
                    *(unsigned*)(intptr_t)(o + 0x28) = (unsigned)puVar10[2];
                    *(unsigned*)(intptr_t)(o + 0x2c) = (unsigned)puVar10[3];
                    *(unsigned*)(intptr_t)(o + 0x30) = (unsigned)puVar10[4];
                    *(unsigned*)(intptr_t)(o + 0x34) = (unsigned)puVar10[5];
                    *(int*)(intptr_t)(o + 0x14) = 0x5d;
                    ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(o + 4)))(param_1, 2);
                    puVar10 = puVar10 + 8;
                    --n;
                } while (n != 0);
            }
            iVar6 = local_8 - 0x41;
            if (iVar7 != 0) {
                iVar6 = local_8 - 0x81;
            }
            local_8 = iVar6;
        } while (0 < local_8);
    }
    if (local_8 != 0) {
        int* ev = (int*)(intptr_t)*param_1;
        ev[5] = 0xb;
        ((void (*)(int*))(intptr_t)ev[0])(param_1);
    }
    puVar3->cur = pbVar12;
    puVar3->avail = iVar5;
    return 1;
}

// 0x655700 — observed shape
int FUN_00655700(int* param_1) {
    ByteStream* puVar3 = (ByteStream*)(intptr_t)param_1[6];
    int iVar6 = puVar3->avail;
    unsigned char* puVar7 = puVar3->cur;
    if (iVar6 == 0) {
        iVar6 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
        if (iVar6 == 0) return 0;
        puVar7 = puVar3->cur;
        iVar6 = puVar3->avail;
    }
    unsigned char uVar1 = *puVar7;
    iVar6 = iVar6 - 1;
    puVar7 = puVar7 + 1;
    if (iVar6 == 0) {
        iVar6 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
        if (iVar6 == 0) return 0;
        puVar7 = puVar3->cur;
        iVar6 = puVar3->avail;
    }
    iVar6 = iVar6 - 1;
    unsigned char* puVar8 = puVar7 + 1;
    if (((uVar1 << 8) | *puVar7) != 4) {
        int* ev = (int*)(intptr_t)*param_1;
        ev[5] = 0xb;
        ((void (*)(int*))(intptr_t)ev[0])(param_1);
    }
    if (iVar6 == 0) {
        iVar6 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
        if (iVar6 == 0) return 0;
        puVar8 = puVar3->cur;
        iVar6 = puVar3->avail;
    }
    uVar1 = *puVar8;
    iVar6 = iVar6 - 1;
    puVar8 = puVar8 + 1;
    if (iVar6 == 0) {
        iVar6 = ((int (*)(int*))(intptr_t)puVar3->refill)(param_1);
        if (iVar6 == 0) return 0;
        puVar8 = puVar3->cur;
        iVar6 = puVar3->avail;
    }
    unsigned char uVar2 = *puVar8;
    int iVar5 = *param_1;
    *(int*)(intptr_t)(iVar5 + 0x14) = 0x52;
    *(unsigned*)(intptr_t)(iVar5 + 0x18) = (unsigned)((uVar1 << 8) | uVar2);
    ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar5 + 4)))(param_1, 1);
    puVar3->cur = puVar8 + 1;
    puVar3->avail = iVar6 - 1;
    param_1[0x46] = (uVar1 << 8) | uVar2;
    return 1;
}

// 0x6557e0 — observed shape (receiver ESI, operands in EAX/ECX/EDI)
void FUN_006557e0(void* self_ = nullptr, unsigned in_EAX = 0, int in_ECX = 0,
                  char* in_EDI = nullptr) {
    int* self = (int*)self_;
    char* unaff_EDI = in_EDI;
    int iVar1 = (int)(in_EAX + (unsigned)in_ECX);
    if (in_EAX < 0xe || unaff_EDI[0] != 'J' || unaff_EDI[1] != 'F' ||
        unaff_EDI[2] != 'I' || unaff_EDI[3] != 'F' || unaff_EDI[4] != '\0') {
        if (5 < in_EAX && unaff_EDI[0] == 'J' && unaff_EDI[1] == 'F' &&
            unaff_EDI[2] == 'X' && unaff_EDI[3] == 'X' && unaff_EDI[4] == '\0') {
            unsigned uVar10 = (unsigned)(unsigned char)unaff_EDI[5];
            int iVar9;
            if (uVar10 == 0x10) {
                iVar9 = *self;
                *(int*)(intptr_t)(iVar9 + 0x14) = 0x6c;
                *(int*)(intptr_t)(iVar9 + 0x18) = iVar1;
                ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
                return;
            }
            if (uVar10 == 0x11) {
                iVar9 = *self;
                *(int*)(intptr_t)(iVar9 + 0x14) = 0x6d;
                *(int*)(intptr_t)(iVar9 + 0x18) = iVar1;
                ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
                return;
            }
            iVar9 = *self;
            if (uVar10 == 0x13) {
                *(int*)(intptr_t)(iVar9 + 0x14) = 0x6e;
                *(int*)(intptr_t)(iVar9 + 0x18) = iVar1;
                ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
                return;
            }
            *(int*)(intptr_t)(iVar9 + 0x14) = 0x59;
            *(unsigned*)(intptr_t)(iVar9 + 0x18) = uVar10;
            *(int*)(intptr_t)(iVar9 + 0x1c) = iVar1;
            ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
            return;
        }
        int iVar9 = *self;
        *(int*)(intptr_t)(iVar9 + 0x14) = 0x4d;
        *(int*)(intptr_t)(iVar9 + 0x18) = iVar1;
        ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
        return;
    }
    char cVar2 = unaff_EDI[7];
    unsigned char bVar3 = (unsigned char)unaff_EDI[5];
    *((char*)self + 0x121) = unaff_EDI[6];
    char cVar4 = unaff_EDI[8];
    *((char*)self + 0x122) = cVar2;
    char cVar2b = unaff_EDI[9];
    self[0x47] = 1;
    *((unsigned char*)self + 0x120) = bVar3;
    char cVar5 = unaff_EDI[0xb];
    *(unsigned short*)((unsigned char*)self + 0x124) =
        (unsigned short)(((unsigned char)cVar4 << 8) | (unsigned char)cVar2b);
    *(unsigned short*)((unsigned char*)self + 0x126) =
        (unsigned short)(((unsigned char)unaff_EDI[10] << 8) | (unsigned char)cVar5);
    if (bVar3 != 1) {
        int iVar9 = *self;
        unsigned char bVar6 = (unsigned char)unaff_EDI[6];
        *(int*)(intptr_t)(iVar9 + 0x14) = 0x77;
        *(unsigned*)(intptr_t)(iVar9 + 0x18) = bVar3;
        *(unsigned*)(intptr_t)(iVar9 + 0x1c) = bVar6;
        ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
    }
    {
        int iVar9 = *self;
        unsigned char b121 = *((unsigned char*)self + 0x121);
        *(unsigned*)(intptr_t)(iVar9 + 0x18) = *((unsigned char*)self + 0x120);
        unsigned short uVar7 = *(unsigned short*)((unsigned char*)self + 0x124);
        *(unsigned*)(intptr_t)(iVar9 + 0x1c) = b121;
        unsigned short uVar8 = *(unsigned short*)((unsigned char*)self + 0x126);
        *(unsigned*)(intptr_t)(iVar9 + 0x20) = uVar7;
        unsigned char b122 = *((unsigned char*)self + 0x122);
        *(unsigned*)(intptr_t)(iVar9 + 0x24) = uVar8;
        *(unsigned*)(intptr_t)(iVar9 + 0x28) = b122;
        *(int*)(intptr_t)(iVar9 + 0x14) = 0x57;
        ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
    }
    {
        unsigned char bVar3b = (unsigned char)unaff_EDI[0xc];
        unsigned char bVar6 = (unsigned char)unaff_EDI[0xd];
        if (bVar3b != 0 || bVar6 != 0) {
            int iVar9 = *self;
            *(int*)(intptr_t)(iVar9 + 0x14) = 0x5a;
            *(unsigned*)(intptr_t)(iVar9 + 0x18) = bVar3b;
            *(unsigned*)(intptr_t)(iVar9 + 0x1c) = bVar6;
            ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
        }
        if (iVar1 - 0xe != (unsigned)bVar3b * (unsigned)bVar6 * 3) {
            int iVar9 = *self;
            *(int*)(intptr_t)(iVar9 + 0x14) = 0x58;
            *(int*)(intptr_t)(iVar9 + 0x18) = iVar1 - 0xe;
            ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar9 + 4)))();
            return;
        }
    }
    return;
}

// 0x6559c0 — observed shape (receiver ESI, header in EAX, length in ECX)
// Register operands arrive in ESI/EAX/ECX; only the stack parameter is explicit.
void FUN_006559c0(int param_1, void* self_ = nullptr, char* in_EAX = nullptr,
                  unsigned in_ECX = 0) {
    int* self = (int*)self_;
    char* unaff_EAX = in_EAX;
    if (in_ECX < 0xc || unaff_EAX[0] != 'A' || unaff_EAX[1] != 'd' ||
        unaff_EAX[2] != 'o' || unaff_EAX[3] != 'b' || unaff_EAX[4] != 'e') {
        int iVar3 = *self;
        *(int*)(intptr_t)(iVar3 + 0x14) = 0x4e;
        *(unsigned*)(intptr_t)(iVar3 + 0x18) = in_ECX + (unsigned)param_1;
        ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar3 + 4)))();
        return;
    }
    int iVar3 = *self;
    unsigned char bVar1 = (unsigned char)unaff_EAX[0xb];
    char cVar2 = unaff_EAX[8];
    *(unsigned*)(intptr_t)(iVar3 + 0x18) =
        (unsigned)((unsigned char)unaff_EAX[5] << 8 | (unsigned char)unaff_EAX[6]);
    *(unsigned*)(intptr_t)(iVar3 + 0x1c) =
        (unsigned)((unsigned char)unaff_EAX[7] << 8 | (unsigned char)cVar2);
    *(unsigned*)(intptr_t)(iVar3 + 0x20) =
        (unsigned)((unsigned char)unaff_EAX[9] << 8 | (unsigned char)unaff_EAX[10]);
    *(unsigned*)(intptr_t)(iVar3 + 0x24) = bVar1;
    *(int*)(intptr_t)(iVar3 + 0x14) = 0x4c;
    ((void (*)(void))(intptr_t)(*(int*)(intptr_t)(iVar3 + 4)))();
    *((unsigned char*)self + 0x12c) = bVar1;
    self[0x4a] = 1;
    return;
}

// 0x655a60 — observed shape
int FUN_00655a60(int* param_1) {
    ByteStream* puVar7 = (ByteStream*)(intptr_t)param_1[6];
    int iVar3 = puVar7->avail;
    unsigned char* pbVar6 = puVar7->cur;
    ByteStream* local_18 = puVar7;
    int local_8 = 0;
    unsigned uVar5 = 0;
    if (iVar3 == 0) {
        iVar3 = ((int (*)(int*))(intptr_t)puVar7->refill)(param_1);
        if (iVar3 == 0) return 0;
        iVar3 = puVar7->avail;
        pbVar6 = puVar7->cur;
        local_8 = iVar3;
    }
    unsigned local_10 = (unsigned)*pbVar6 << 8;
    iVar3 = iVar3 - 1;
    pbVar6 = pbVar6 + 1;
    if (iVar3 == 0) {
        iVar3 = ((int (*)(int*))(intptr_t)puVar7->refill)(param_1);
        if (iVar3 == 0) return 0;
        iVar3 = puVar7->avail;
        pbVar6 = puVar7->cur;
    }
    uVar5 = (local_10 + *pbVar6) - 2;
    pbVar6 = pbVar6 + 1;
    unsigned local_c;
    if ((int)uVar5 < 0xe) {
        local_c = (((int)uVar5 < 1) - 1) & uVar5;
    } else {
        local_c = 0xe;
    }
    unsigned local_14 = 0;
    local_10 = uVar5;
    local_8 = iVar3 - 1;
    unsigned char local_28[16];
    if (local_c != 0) {
        do {
            unsigned uVar4 = local_14;
            if (local_8 == 0) {
                iVar3 = ((int (*)(int*))(intptr_t)puVar7->refill)(param_1);
                if (iVar3 == 0) return 0;
                local_8 = puVar7->avail;
                pbVar6 = puVar7->cur;
                uVar4 = local_14;
                uVar5 = local_10;
            }
            iVar3 = local_8 - 1;
            local_28[uVar4] = *pbVar6;
            pbVar6 = pbVar6 + 1;
            local_14 = uVar4 + 1;
            local_8 = iVar3;
        } while (local_14 < local_c);
    }
    iVar3 = local_8;
    local_10 = uVar5 - local_c;
    if (param_1[0x69] == 0xe0) {
        FUN_006557e0(param_1);
        puVar7 = local_18;
    } else {
        if (param_1[0x69] != 0xee) {
            int* ev = (int*)(intptr_t)*param_1;
            int iVar2 = param_1[0x69];
            ev[5] = 0x44;
            ev[6] = iVar2;
            ((void (*)(int*))(intptr_t)ev[0])(param_1);
            goto LAB_00655b86;
        }
        FUN_006559c0((int)local_10, param_1);
    }
    iVar3 = local_8;
LAB_00655b86:
    puVar7->cur = pbVar6;
    puVar7->avail = iVar3;
    if (0 < (int)local_10) {
        ((void (*)(int*, unsigned))(intptr_t)(*(int*)((intptr_t)param_1[6] + 0x10)))(
            param_1, local_10);
    }
    return 1;
}

// 0x655bb0 — observed shape
int FUN_00655bb0(int* param_1) {
    int* piVar5 = param_1;
    ByteStream* puVar2 = (ByteStream*)(intptr_t)param_1[6];
    int iVar6 = puVar2->avail;
    unsigned char* pbVar7 = puVar2->cur;
    if (iVar6 == 0) {
        iVar6 = ((int (*)(int*))(intptr_t)puVar2->refill)(param_1);
        if (iVar6 == 0) return 0;
        iVar6 = puVar2->avail;
        pbVar7 = puVar2->cur;
    }
    unsigned char bVar1 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    int iVar3 = iVar6 - 1;
    if (iVar6 - 1 == 0) {
        iVar6 = ((int (*)(int*))(intptr_t)puVar2->refill)(param_1);
        if (iVar6 == 0) return 0;
        pbVar7 = puVar2->cur;
        iVar3 = puVar2->avail;
    }
    int count = iVar3;
    iVar3 = piVar5[0x69];
    int iVar6b = (int)((unsigned)bVar1 * 0x100 - 2 + (unsigned)*pbVar7);
    int iVar4 = *piVar5;
    *(int*)(intptr_t)(iVar4 + 0x14) = 0x5b;
    *(int*)(intptr_t)(iVar4 + 0x18) = iVar3;
    *(int*)(intptr_t)(iVar4 + 0x1c) = iVar6b;
    ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar4 + 4)))(piVar5, 1);
    puVar2->avail = count - 1;
    puVar2->cur = pbVar7 + 1;
    if (0 < iVar6b) {
        ((void (*)(int*, int))(intptr_t)(*(int*)((intptr_t)piVar5[6] + 0x10)))(
            piVar5, iVar6b);
    }
    return 1;
}

// 0x655c60 — observed shape
int FUN_00655c60(int* param_1) {
    ByteStream* puVar2 = (ByteStream*)(intptr_t)param_1[6];
    int iVar5 = puVar2->avail;
    unsigned char* pbVar7 = puVar2->cur;
    unsigned char bVar1;
    unsigned uVar6;
    for (;;) {
        if (iVar5 == 0) {
            iVar5 = ((int (*)(int*))(intptr_t)puVar2->refill)(param_1);
            if (iVar5 == 0) return 0;
            pbVar7 = puVar2->cur;
            iVar5 = puVar2->avail;
        }
        bVar1 = *pbVar7;
        for (;;) {
            pbVar7 = pbVar7 + 1;
            iVar5 = iVar5 - 1;
            if (bVar1 == 0xff) break;
            *(int*)((intptr_t)param_1[0x6f] + 0x18) =
                *(int*)((intptr_t)param_1[0x6f] + 0x18) + 1;
            puVar2->cur = pbVar7;
            puVar2->avail = iVar5;
            if (iVar5 == 0) {
                iVar5 = ((int (*)(int*))(intptr_t)puVar2->refill)(param_1);
                if (iVar5 == 0) return 0;
                pbVar7 = puVar2->cur;
                iVar5 = puVar2->avail;
            }
            bVar1 = *pbVar7;
        }
        do {
            if (iVar5 == 0) {
                iVar5 = ((int (*)(int*))(intptr_t)puVar2->refill)(param_1);
                if (iVar5 == 0) return 0;
                pbVar7 = puVar2->cur;
                iVar5 = puVar2->avail;
            }
            uVar6 = (unsigned)*pbVar7;
            iVar5 = iVar5 - 1;
            pbVar7 = pbVar7 + 1;
        } while (uVar6 == 0xff);
        if (uVar6 != 0) break;
        *(int*)((intptr_t)param_1[0x6f] + 0x18) =
            *(int*)((intptr_t)param_1[0x6f] + 0x18) + 2;
        puVar2->cur = pbVar7;
        puVar2->avail = iVar5;
    }
    int iVar3 = *(int*)((intptr_t)param_1[0x6f] + 0x18);
    if (iVar3 != 0) {
        int iVar4 = *param_1;
        *(int*)(intptr_t)(iVar4 + 0x14) = 0x74;
        *(int*)(intptr_t)(iVar4 + 0x18) = iVar3;
        *(unsigned*)(intptr_t)(iVar4 + 0x1c) = uVar6;
        ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar4 + 4)))(param_1, 0xffffffff);
        *(int*)((intptr_t)param_1[0x6f] + 0x18) = 0;
    }
    puVar2->cur = pbVar7;
    puVar2->avail = iVar5;
    param_1[0x69] = (int)uVar6;
    return 1;
}

// 0x655d70 — observed shape
int FUN_00655d70(int* param_1) {
    ByteStream* puVar2 = (ByteStream*)(intptr_t)param_1[6];
    unsigned char* pbVar6 = puVar2->cur;
    int iVar4 = puVar2->avail;
    if (iVar4 == 0) {
        iVar4 = ((int (*)(int*))(intptr_t)puVar2->refill)(param_1);
        if (iVar4 == 0) return 0;
        pbVar6 = puVar2->cur;
        iVar4 = puVar2->avail;
    }
    unsigned char bVar1 = *pbVar6;
    iVar4 = iVar4 - 1;
    pbVar6 = pbVar6 + 1;
    if (iVar4 == 0) {
        iVar4 = ((int (*)(int*))(intptr_t)puVar2->refill)(param_1);
        if (iVar4 == 0) return 0;
        pbVar6 = puVar2->cur;
        iVar4 = puVar2->avail;
    }
    unsigned uVar5 = (unsigned)*pbVar6;
    if (bVar1 != 0xff || uVar5 != 0xd8) {
        int* ev = (int*)(intptr_t)*param_1;
        ev[5] = 0x35;
        ev[6] = (int)bVar1;
        ev[7] = (int)uVar5;
        ((void (*)(int*))(intptr_t)ev[0])(param_1);
    }
    puVar2->avail = iVar4 - 1;
    puVar2->cur = pbVar6 + 1;
    param_1[0x69] = (int)uVar5;
    return 1;
}

// 0x655e10 — observed shape
int FUN_00655e10(int* param_1) {
    int iVar3;
LAB_00655e20:
    if (param_1[0x69] == 0) {
        if (*(int*)((intptr_t)param_1[0x6f] + 0xc) == 0) {
            iVar3 = FUN_00655d70(param_1);
        } else {
            iVar3 = FUN_00655c60(param_1);
        }
        if (iVar3 == 0) {
            return 0;
        }
    }
    iVar3 = param_1[0x69];
    switch (iVar3) {
    case 1:
    case 0xd0:
    case 0xd1:
    case 0xd2:
    case 0xd3:
    case 0xd4:
    case 0xd5:
    case 0xd6:
    case 0xd7: {
        int iVar1 = *param_1;
        *(int*)(intptr_t)(iVar1 + 0x14) = 0x5c;
        *(int*)(intptr_t)(iVar1 + 0x18) = iVar3;
        ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar1 + 4)))(param_1, 1);
        param_1[0x69] = 0;
        goto LAB_00655e20;
    }
    default: {
        int* ev = (int*)(intptr_t)*param_1;
        ev[5] = 0x44;
        ev[6] = iVar3;
        ((void (*)(int*))(intptr_t)ev[0])(param_1);
        goto LAB_00655f8e;
    }
    case 0xc0:
    case 0xc1:
        break;
    case 0xc2:
        break;
    case 0xc3:
    case 0xc5:
    case 0xc6:
    case 199:
    case 200:
    case 0xcb:
    case 0xcd:
    case 0xce:
    case 0xcf: {
        int* ev = (int*)(intptr_t)*param_1;
        ev[5] = 0x3c;
        ev[6] = iVar3;
        ((void (*)(int*))(intptr_t)ev[0])(param_1);
        param_1[0x69] = 0;
        goto LAB_00655e20;
    }
    case 0xc4: {
        iVar3 = FUN_006551e0(param_1);
        if (iVar3 == 0) {
            return 0;
        }
        param_1[0x69] = 0;
        goto LAB_00655e20;
    }
    case 0xc9: {
        iVar3 = FUN_00654c40(param_1);
        if (iVar3 == 0) {
            return 0;
        }
        goto LAB_00655f8e;
    }
    case 0xca:
        break;
    case 0xcc:
    case 0xdc: {
        iVar3 = FUN_00655bb0(param_1);
        if (iVar3 == 0) {
            return 0;
        }
        param_1[0x69] = 0;
        goto LAB_00655e20;
    }
    case 0xd8:
        iVar3 = FUN_00654b90(param_1);
        goto LAB_00655ea3;
    case 0xd9: {
        int iVar1 = *param_1;
        *(int*)(intptr_t)(iVar1 + 0x14) = 0x55;
        ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar1 + 4)))(param_1, 1);
        param_1[0x69] = 0;
        return 2;
    }
    case 0xda:
        iVar3 = FUN_00654f20(param_1);
        if (iVar3 == 0) {
            return 0;
        }
        param_1[0x69] = 0;
        return 1;
    case 0xdb: {
        iVar3 = FUN_006554b0(param_1);
        if (iVar3 == 0) {
            return 0;
        }
        param_1[0x69] = 0;
        goto LAB_00655e20;
    }
    case 0xdd: {
        iVar3 = FUN_00655700(param_1);
        if (iVar3 == 0) {
            return 0;
        }
        param_1[0x69] = 0;
        goto LAB_00655e20;
    }
    case 0xe0:
    case 0xe1:
    case 0xe2:
    case 0xe3:
    case 0xe4:
    case 0xe5:
    case 0xe6:
    case 0xe7:
    case 0xe8:
    case 0xe9:
    case 0xea:
    case 0xeb:
    case 0xec:
    case 0xed:
    case 0xee:
    case 0xef: {
        int fn = *(int*)((intptr_t)param_1[0x6f] - 0x360 + iVar3 * 4);
        iVar3 = ((int (*)(int*))(intptr_t)fn)(param_1);
        if (iVar3 == 0) {
            return 0;
        }
        param_1[0x69] = 0;
        goto LAB_00655e20;
    }
    case 0xfe:
        goto LAB_00655f2c;
    }
    iVar3 = FUN_00654c40(param_1);
LAB_00655ea3:
    if (iVar3 == 0) {
        return 0;
    }
    param_1[0x69] = 0;
    goto LAB_00655e20;
LAB_00655f8e:
    param_1[0x69] = 0;
    goto LAB_00655e20;
LAB_00655f2c:
    iVar3 = ((int (*)(int*))(intptr_t)(*(int*)((intptr_t)param_1[0x6f] + 0x1c)))(param_1);
    if (iVar3 == 0) {
        return 0;
    }
    param_1[0x69] = 0;
    goto LAB_00655e20;
}

// 0x6551e0 — observed shape (DHT table reader; stack frame aliases the 16
// table bytes onto local_2c/local_28/local_24/local_20/local_1c)
int FUN_006551e0(int* param_1) {
    ByteStream* local_c = (ByteStream*)(intptr_t)param_1[6];
    unsigned char* pbVar7 = local_c->cur;
    int iVar3 = local_c->avail;
    int local_8 = 0;
    if (iVar3 == 0) {
        iVar3 = ((int (*)(int*))(intptr_t)local_c->refill)(param_1);
        if (iVar3 == 0) return 0;
        pbVar7 = local_c->cur;
        iVar3 = local_c->avail;
        local_8 = iVar3;
    }
    unsigned local_10 = (unsigned)*pbVar7 << 8;
    iVar3 = iVar3 - 1;
    pbVar7 = pbVar7 + 1;
    if (iVar3 == 0) {
        iVar3 = ((int (*)(int*))(intptr_t)local_c->refill)(param_1);
        if (iVar3 == 0) return 0;
        iVar3 = local_c->avail;
        pbVar7 = local_c->cur;
        local_8 = iVar3;
    }
    iVar3 = iVar3 - 1;
    local_10 = local_10 + (unsigned)*pbVar7 + -2;
    pbVar7 = pbVar7 + 1;
    unsigned char local_130[0x130];
    if (0x10 < local_10) {
        do {
            if (iVar3 == 0) {
                iVar3 = ((int (*)(int*))(intptr_t)local_c->refill)(param_1);
                if (iVar3 == 0) return 0;
                pbVar7 = local_c->cur;
                iVar3 = local_c->avail;
                local_8 = iVar3;
            }
            unsigned local_30 = (unsigned)*pbVar7;
            int iVar4 = *param_1;
            iVar3 = iVar3 - 1;
            *(int*)(intptr_t)(iVar4 + 0x14) = 0x50;
            pbVar7 = pbVar7 + 1;
            *(unsigned*)(intptr_t)(iVar4 + 0x18) = local_30;
            ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar4 + 4)))(param_1, 1);
            *(unsigned*)(local_130 + 0x104) &= 0xffffff00u;
            int local_14 = 0;
            int local_18 = 1;
            do {
                ByteStream* puVar10 = local_c;
                iVar4 = local_18;
                if (iVar3 == 0) {
                    iVar3 = ((int (*)(int*))(intptr_t)local_c->refill)(param_1);
                    if (iVar3 == 0) return 0;
                    iVar3 = puVar10->avail;
                    pbVar7 = puVar10->cur;
                    iVar4 = local_18;
                }
                unsigned char bVar1 = *pbVar7;
                local_130[iVar4 + 0x104] = bVar1;
                iVar3 = iVar3 - 1;
                local_14 = local_14 + (unsigned)bVar1;
                pbVar7 = pbVar7 + 1;
                local_18 = iVar4 + 1;
                local_8 = iVar3;
            } while (local_18 < 0x11);
            local_10 = local_10 - 0x11;
            unsigned local_2c = *(unsigned*)(local_130 + 0x104);
            unsigned local_28 = *(unsigned*)(local_130 + 0x108);
            unsigned local_24 = *(unsigned*)(local_130 + 0x10c);
            unsigned local_20 = *(unsigned*)(local_130 + 0x110);
            unsigned char local_1c = local_130[0x114];
            iVar4 = *param_1;
            *(unsigned*)(intptr_t)(iVar4 + 0x18) = local_2c >> 8 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x1c) = local_2c >> 0x10 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x20) = local_2c >> 0x18;
            *(unsigned*)(intptr_t)(iVar4 + 0x24) = local_28 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x28) = local_28 >> 8 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x2c) = local_28 >> 0x10 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x30) = local_28 >> 0x18;
            *(unsigned*)(intptr_t)(iVar4 + 0x34) = local_24 & 0xff;
            *(int*)(intptr_t)(iVar4 + 0x14) = 0x56;
            ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar4 + 4)))(param_1, 2);
            iVar4 = *param_1;
            *(unsigned*)(intptr_t)(iVar4 + 0x18) = local_24 >> 8 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x1c) = local_24 >> 0x10 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x20) = local_24 >> 0x18;
            *(unsigned*)(intptr_t)(iVar4 + 0x24) = local_20 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x28) = local_20 >> 8 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x2c) = local_20 >> 0x10 & 0xff;
            *(unsigned*)(intptr_t)(iVar4 + 0x30) = local_20 >> 0x18;
            *(unsigned*)(intptr_t)(iVar4 + 0x34) = local_1c;
            *(int*)(intptr_t)(iVar4 + 0x14) = 0x56;
            ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar4 + 4)))(param_1, 2);
            if (0x100 < local_14 || local_10 < (unsigned)local_14) {
                int* ev = (int*)(intptr_t)*param_1;
                ev[5] = 8;
                ((void (*)(int*))(intptr_t)ev[0])(param_1);
            }
            local_18 = 0;
            iVar4 = local_14;
            if (0 < local_14) {
                do {
                    ByteStream* puVar10 = local_c;
                    int iVar5 = local_18;
                    if (iVar3 == 0) {
                        iVar3 = ((int (*)(int*))(intptr_t)local_c->refill)(param_1);
                        if (iVar3 == 0) return 0;
                        iVar3 = puVar10->avail;
                        pbVar7 = puVar10->cur;
                        iVar5 = local_18;
                        iVar4 = local_14;
                    }
                    unsigned char bVar1 = *pbVar7;
                    iVar3 = iVar3 - 1;
                    pbVar7 = pbVar7 + 1;
                    local_130[iVar5] = bVar1;
                    local_8 = iVar3;
                    local_18 = iVar5 + 1;
                } while (iVar5 + 1 < iVar4);
            }
            local_10 = local_10 - (unsigned)iVar4;
            unsigned uVar6;
            int iVar3b;
            if ((local_30 & 0x10) == 0) {
                iVar3b = (int)local_30 + 0x2e;
                uVar6 = local_30;
            } else {
                iVar3b = (int)local_30 + 0x22;
                uVar6 = local_30 - 0x10;
            }
            int* piVar9 = param_1 + iVar3b;
            if ((int)uVar6 < 0 || 3 < (int)uVar6) {
                int* ev = (int*)(intptr_t)*param_1;
                ev[5] = 0x1e;
                ev[6] = (int)uVar6;
                ((void (*)(int*))(intptr_t)ev[0])(param_1);
            }
            if (*piVar9 == 0) {
                *piVar9 = FUN_00692380(param_1);
            }
            unsigned* puVar2 = (unsigned*)(intptr_t)*piVar9;
            puVar2[0] = local_2c;
            puVar2[1] = local_28;
            puVar2[2] = local_24;
            puVar2[3] = local_20;
            *(unsigned char*)((intptr_t)puVar2 + 0x10) = local_1c;
            unsigned char* pbVar8 = local_130;
            int* puVar10b = (int*)((intptr_t)puVar2 + 0x11);
            for (int n = 0x40; n != 0; --n) {
                *puVar10b = *(int*)(intptr_t)pbVar8;
                pbVar8 = pbVar8 + 4;
                puVar10b = puVar10b + 1;
            }
            iVar3 = local_8;
        } while (0x10 < local_10);
    }
    if (local_10 != 0) {
        int* ev = (int*)(intptr_t)*param_1;
        ev[5] = 0xb;
        ((void (*)(int*))(intptr_t)ev[0])(param_1);
    }
    local_c->avail = iVar3;
    local_c->cur = pbVar7;
    return 1;
}

// 0x6562b0 — observed shape
void FUN_006562b0(int param_1) {
    int iVar1 = *(int*)(intptr_t)(param_1 + 0x1bc);
    *(int*)(intptr_t)(param_1 + 0xdc) = 0;
    *(int*)(intptr_t)(param_1 + 0x94) = 0;
    *(int*)(intptr_t)(param_1 + 0x1a4) = 0;
    *(int*)(intptr_t)(iVar1 + 0xc) = 0;
    *(int*)(intptr_t)(iVar1 + 0x10) = 0;
    *(int*)(intptr_t)(iVar1 + 0x18) = 0;
    *(int*)(intptr_t)(iVar1 + 0xa4) = 0;
    return;
}

// 0x6562f0 — observed shape (installs the packet-reader dispatch table)
void FUN_006562f0(int param_1) {
    int vtbl = *(int*)(intptr_t)(param_1 + 4);
    int fn = *(int*)(intptr_t)vtbl;
    int* puVar1 = (int*)(intptr_t)(((int (*)(int, int, int))(intptr_t)fn)(param_1, 0, 0xac));
    *(int**)(intptr_t)(param_1 + 0x1bc) = puVar1;
    puVar1[0] = (int)(intptr_t)FUN_006562b0;
    puVar1[1] = (int)(intptr_t)FUN_00655e10;
    puVar1[2] = (int)(intptr_t)FUN_00656120;
    puVar1[7] = (int)(intptr_t)FUN_00655bb0;
    puVar1[0x18] = 0;
    int* puVar2 = puVar1 + 0x19;
    for (int n = 0x10; n != 0; --n) {
        puVar2[-0x11] = (int)(intptr_t)FUN_00655bb0;
        *puVar2 = 0;
        ++puVar2;
    }
    puVar1[8] = (int)(intptr_t)FUN_00655a60;
    puVar1[0x16] = (int)(intptr_t)FUN_00655a60;
    *(int*)(intptr_t)(param_1 + 0xdc) = 0;
    *(int*)(intptr_t)(param_1 + 0x94) = 0;
    *(int*)(intptr_t)(param_1 + 0x1a4) = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[6] = 0;
    puVar1[0x29] = 0;
    return;
}

// 0x656380 — observed shape (destructor tail; never returns)
void FUN_00656380(int* param_1) {
    ((void (*)(int*))(intptr_t)(*(int*)((intptr_t)(*param_1) + 8)))(param_1);
    FUN_00692320(param_1);
    std::exit(1);
}

// 0x656120 — observed shape
int FUN_00656120(int* param_1) {
    if (param_1[0x69] == 0) {
        int iVar2 = FUN_00655c60(param_1);
        if (iVar2 == 0) {
            return 0;
        }
    }
    int iVar2 = param_1[0x6f];
    int iVar1 = *(int*)(intptr_t)(iVar2 + 0x14);
    if (param_1[0x69] == iVar1 + 0xd0) {
        int iVar1b = *param_1;
        *(int*)(intptr_t)(iVar1b + 0x14) = 0x62;
        *(int*)(intptr_t)(iVar1b + 0x18) = *(int*)(intptr_t)(iVar2 + 0x14);
        ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar1b + 4)))(param_1, 3);
        param_1[0x69] = 0;
    } else {
        iVar2 = ((int (*)(int*, int))(intptr_t)(*(int*)((intptr_t)param_1[6] + 0x14)))(
            param_1, iVar1);
        if (iVar2 == 0) {
            return 0;
        }
    }
    *(unsigned*)((intptr_t)param_1[0x6f] + 0x14) =
        (*(unsigned*)((intptr_t)param_1[0x6f] + 0x14) + 1u) & 7;
    return 1;
}

// 0x6561b0 — observed shape
int FUN_006561b0(int* param_1, int param_2) {
    int iVar3 = *param_1;
    int iVar2 = param_1[0x69];
    *(int*)(intptr_t)(iVar3 + 0x14) = 0x79;
    *(int*)(intptr_t)(iVar3 + 0x18) = iVar2;
    *(int*)(intptr_t)(iVar3 + 0x1c) = param_2;
    ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar3 + 4)))(param_1, 0xffffffff);
    for (;;) {
        if (iVar2 < 0xc0) {
            iVar3 = 2;
        } else if (iVar2 < 0xd0 || 0xd7 < iVar2 ||
                   iVar2 == (int)(((unsigned)param_2 + 1u) & 7) + 0xd0 ||
                   iVar2 == (int)(((unsigned)param_2 + 2u) & 7) + 0xd0) {
            iVar3 = 3;
        } else {
            if (iVar2 == (int)(((unsigned)param_2 - 1u) & 7) + 0xd0 ||
                iVar2 == (int)(((unsigned)param_2 - 2u) & 7) + 0xd0) {
                iVar3 = 2;
            } else {
                iVar3 = 1;
            }
        }
        int iVar1 = *param_1;
        *(int*)(intptr_t)(iVar1 + 0x14) = 0x61;
        *(int*)(intptr_t)(iVar1 + 0x18) = iVar2;
        *(int*)(intptr_t)(iVar1 + 0x1c) = iVar3;
        ((void (*)(int*, int))(intptr_t)(*(int*)(intptr_t)(iVar1 + 4)))(param_1, 4);
        if (iVar3 == 1) {
            param_1[0x69] = 0;
            return 1;
        }
        if (iVar3 == 2) {
            iVar3 = FUN_00655c60(param_1);
            if (iVar3 == 0) {
                return 0;
            }
            iVar2 = param_1[0x69];
        } else if (iVar3 == 3) {
            return 1;
        }
    }
}
