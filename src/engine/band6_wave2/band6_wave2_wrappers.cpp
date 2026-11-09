// UNVERIFIED: no cl 13.10.3077 on this host. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 6 wave 2 NiD3D shader-wrapper cluster (0x5dbxxx). Layouts are address-tagged hypotheses.

#include <stddef.h>
#include <stdint.h>

extern void* FUN_00533c78(unsigned int size);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);

// 0x005db0a0 — shader-state init: fixed vtable slots + SetParameter-style (0x70) argument table.
extern "C" void __thiscall Band6Wave2_StateInit(void* self_) {
    int* self = (int*)self_;
    typedef void (__thiscall *VFixed)(void*);
    typedef void (__thiscall *VSet)(void*, unsigned int, int, unsigned int);
    ((VFixed)(*(int**)self)[0x60 / 4])(self);
    ((VFixed)(*(int**)self)[0x78 / 4])(self);
    ((VFixed)(*(int**)self)[0xc4 / 4])(self);
    ((VFixed)(*(int**)self)[0xe8 / 4])(self);
    // FUN_005db810() — sibling init (reconstructed as external)
    extern void __thiscall Band6Wave2_SubInit(void*);
    Band6Wave2_SubInit(self);
    VSet set = (VSet)(*(int**)self)[0x70 / 4];
    set(self, 0x16, 2, 0); set(self, 0xa1, 0, 0); set(self, 8, 3, 0);
    set(self, 9, 2, 0); set(self, 0x1b, 0, 0);
    set(self, 0x13, self[0xf], 0); set(self, 0x14, self[0x10], 0);
    set(self, 0xf, 0, 0); set(self, 0x19, 8, 0); set(self, 0x18, 0, 0);
    set(self, 0x17, 8, 0); set(self, 0xe, 0, 0); set(self, 0x1a, 0, 0);
    set(self, 0x1d, 0, 0); set(self, 0x1c, 0, 0);
    set(self, 0x23, -((*(unsigned char*)((char*)self + 8) & 1) != 0) & 3, 0);
    set(self, 0x30, 0, 0); set(self, 0x22, 0, 0); set(self, 0x8f, 1, 0);
    unsigned int v = 1;
    if (((char)self[3] != 0) && (((unsigned int)self[2] >> 4 & 1) != 0)) v = 2;
    set(self, 7, v, 0);
    set(self, 0x8d, 1, 0);
}

// 0x005db500 — release helper: ref-dec at +0x78 (word 0x1e), slot call at +0x8a1*4, then FUN_005db710.
extern "C" void __thiscall Band6Wave2_Release(void* self_) {
    int* self = (int*)self_;
    extern void __thiscall Band6Wave2_DtorBody(void*);
    *(int**)self = (int**)0x006c8d78; // PTR_FUN_006c8d78 (observed)
    int* p1 = (int*)self[0x1e];
    if (p1) {
        if (--p1[1] == 0) ((void (__thiscall *)(int*, int))(*(int**)p1))(p1, 1);
        self[0x1e] = 0;
    }
    int* p2 = (int*)self[0x8a1];
    self[0x8a2] = 0;
    if (p2) ((void (__thiscall *)(int*))(*(int**)p2 + 2))(p2);
    self[0x8a1] = 0;
    int* p3 = (int*)self[0x89f];
    if (p3) {
        if (--p3[1] == 0) ((void (__thiscall *)(int*, int))(*(int**)p3))(p3, 1);
    }
    Band6Wave2_DtorBody(self);
    int* p4 = (int*)self[0x1e];
    if (p4) {
        if (--p4[1] == 0) ((void (__thiscall *)(int*, int))(*(int**)p4))(p4, 1);
    }
    *(int**)self = (int**)0x006fd148; // PTR_LAB_006fd148 (observed)
    --(*(int*)0x00727444); // DAT_00727444 refcount (observed)
}

// 0x005db620 — cached shader-desc copy: 0x11-word cache key at +0x5c; 36-byte field shuffle; returns low byte 1.
extern "C" unsigned int __thiscall Band6Wave2_CopyDesc(void* self_, unsigned char* desc) {
    int* self = (int*)self_;
    int* d = (int*)desc;
    if (self[0x11] == d[0x5c / 4]) return (unsigned int)(desc - (desc & 0xffffff00ULL));
    self[0x11] = d[0x5c / 4];
    int v58 = d[0x58 / 4];
    self[0xc] = d[0x48 / 4]; self[0xd] = d[0x4c / 4];
    self[0xf] = v58; self[0xe] = d[0x50 / 4];
    self[4] = d[0x24 / 4]; self[5] = d[0x28 / 4];
    self[7] = v58; self[6] = d[0x2c / 4];
    self[0] = d[0x30 / 4]; self[1] = d[0x34 / 4];
    self[3] = v58; self[2] = d[0x38 / 4];
    self[8] = d[0x3c / 4]; self[9] = d[0x40 / 4];
    self[0xb] = v58; self[10] = d[0x44 / 4];
    int v54 = d[0x54 / 4];
    self[0x10] = v54;
    return (unsigned char)1;
}

// 0x005db6c0 — dirty-flag clear + virtual notify at +0xc4 with field at +8.
extern "C" void __thiscall Band6Wave2_MarkDirty(void* self_, int* ctx) {
    if (*(char*)((char*)self_ + 0xc) != 0) {
        *(unsigned char*)((char*)self_ + 0xc) = 0;
        ((void (__thiscall *)(int*, int))(*(int**)ctx + 0xc4 / 4))(ctx, *(int*)((char*)self_ + 8));
    }
}

// 0x005db710 — dtor core: vtable 0x6c8e8c, clear global slot 0x7275fc+0x60, swap 0x6fd148, dec 0x727444.
extern "C" void __thiscall Band6Wave2_DtorBody(void* self_) {
    int* self = (int*)self_;
    *(int**)self = (int**)0x006c8e8c; // PTR_FUN_006c8e8c (observed)
    int g = *(int*)0x007275fc; // DAT_007275fc
    if (g != 0) {
        void* slot = *(void**)(g + 0x60);
        if (slot != 0) {
            *(void**)(g + 0x60) = 0;
            if (slot == (void*)self[2]) self[2] = 0;
            operator_delete(slot);
        }
    }
    *(int**)self = (int**)0x006fd148;
    --(*(int*)0x00727444);
}

// 0x005db750 — lazily allocate 0x48-byte desc, copy into cache, set dirty (+0xc) when CopyDesc reports changed.
extern "C" void __thiscall Band6Wave2_EnsureDesc(void* self_, int kind) {
    int* self = (int*)self_;
    unsigned int cached = 0;
    if (*(int*)((char*)self_ + 0x60) == 0) {
        void* p = FUN_00533c78(0x48);
        if (p) { *(int*)((char*)p + 0x44) = 0; cached = Band6Wave2_CopyDesc(self_, (unsigned char*)(long)kind); }
        *(int*)((char*)self_ + 0x60) = (int)(long)p;
    }
    if (Band6Wave2_CopyDesc(self_, (unsigned char*)(long)kind) != 0)
        *(unsigned char*)((char*)self_ + 0xc) = 1;
    (void)cached;
}

// 0x005db7b0 — deleting dtor: same body as Band6Wave2_DtorBody, then operator_delete(self) if flag&1.
extern "C" void* __thiscall Band6Wave2_DeletingDtor(void* self_, unsigned char flag) {
    Band6Wave2_DtorBody(self_);
    if (flag & 1) operator_delete(self_);
    return self_;
}

// 0x005db830 — buffer init: vtable 0x6c8e90, channel counts from descriptor bytes +0xc5/+0xcd, 6 zeroed arrays.
extern "C" void __thiscall Band6Wave2_BufferInit(void* self_, unsigned int a, int* b) {
    int* self = (int*)self_;
    extern void __thiscall Band6Wave2_BaseInit(unsigned int);
    Band6Wave2_BaseInit(a);
    *(int**)self = (int**)0x006c8e90; // PTR_FUN_006c8e90 (observed)
    self[10] = *(int*)((char*)b + 200);
    unsigned char mode = *(unsigned char*)((char*)b + 0xc5);
    int countA = 0, flagsA = 0, capA = 0;
    if (mode == 1) { self[0x1e] = 0; self[0x14] = 0; }
    else if (mode == 2) { self[0x1f] = (*(int*)((char*)b + 0xfc) != 0) ? 0x10 : 0; self[0x14] = 0x10; }
    else if (mode == 3) { self[0x1e] = 0x10; self[0x14] = 0x10; }
    unsigned char mode2 = *(unsigned char*)((char*)b + 0xcd);
    if (mode2 == 1) { self[0xb] = 8; self[0x1f] = 0; self[0x15] = 0; }
    else if (mode2 == 2) { self[0xb] = 0x20; self[0x1f] = (*(int*)((char*)b + 0x10c) != 0) ? 0x10 : 0; self[0x15] = 0x10; }
    else if (mode2 == 3) { self[0xb] = 0xe0; self[0x1f] = 0x10; self[0x15] = 0x10; }
    self[8] = self[0xb]; self[0x10] = self[0x14]; self[0x12] = self[0x15];
    self[6] = self[10]; self[0x1a] = self[0x1e]; self[0x1c] = self[0x1f];
    // Six zeroed (count*0x10 and count*4) channel arrays at slots 2/3, 4/5, 0x16/0x17, 0x18/0x19, 0xc/0xd, 0xe/0xf.
    struct Slot { int slot; int count; };
    Slot slots[] = {{2, self[10]}, {3, self[10]}, {4, self[0xb]}, {5, self[0xb]},
                    {0x16, self[0x1e]}, {0x17, self[0x1e]}, {0x18, self[0x1f]}, {0x19, self[0x1f]},
                    {0xc, self[0x14]}, {0xd, self[0x14]}, {0xe, self[0x15]}, {0xf, self[0x15]}};
    for (int i = 0; i < 12; i++) {
        int cnt = slots[i].count;
        int small = (i & 1) || i < 4; // 0x0x10- vs 0x4-byte arrays per observed stride pairs
        (void)small;
        if (cnt != 0) {
            int* buf = (int*)FUN_00533c78(cnt * 0x10);
            self[slots[i].slot] = (int)(long)buf;
            for (int j = 0; j < cnt * 4; j++) buf[j] = 0;
            buf = (int*)FUN_00533c78(cnt * 0x10);
            self[slots[i].slot + 1 == 0x10 ? 0xf : slots[i].slot + 1] = (int)(long)buf; // paired slot (approx, see unknowns)
            for (int j = 0; j < cnt * 4; j++) buf[j] = 0;
        }
    }
    (void)countA; (void)flagsA; (void)capA;
}

// 0x005dbaf0 — allocator: FUN_00533c78(0x88) then BufferInit; null on failure.
extern "C" void* Band6Wave2_Create(unsigned int a, int* b) {
    int* p = (int*)FUN_00533c78(0x88);
    if (!p) return 0;
    Band6Wave2_BufferInit(p, a, b);
    return p;
}

// 0x005dbb20 — flush unsent ranges (virtuals 0x178/0x1b4/0x188/0x1c4/0x180/0x1bc), advance bases, zero caps.
extern "C" void __thiscall Band6Wave2_Flush(void* self_) {
    int* self = (int*)self_;
    int* dev = *(int**)((char*)self_ + 0x80);
    typedef void (__thiscall *Fl)(int*, unsigned int, int, unsigned int);
    Fl* v = (Fl*)*(int**)dev;
    unsigned int a, b;
    a = *(unsigned int*)((char*)self_ + 0x18); b = *(unsigned int*)((char*)self_ + 0x1c);
    if (a < b) v[0x178/4](dev, a, a * 16 + *(int*)((char*)self_ + 8), b - a);
    a = *(unsigned int*)((char*)self_ + 0x20); b = *(unsigned int*)((char*)self_ + 0x24);
    if (a < b) v[0x1b4/4](dev, a, a * 16 + *(int*)((char*)self_ + 0x10), b - a);
    a = *(unsigned int*)((char*)self_ + 0x68); b = *(unsigned int*)((char*)self_ + 0x6c);
    if (a < b) v[0x188/4](dev, a, *(int*)((char*)self_ + 0x58) + a * 4, b - a);
    a = *(unsigned int*)((char*)self_ + 0x70); b = *(unsigned int*)((char*)self_ + 0x74);
    if (a < b) v[0x1c4/4](dev, a, *(int*)((char*)self_ + 0x60) + a * 4, b - a);
    a = *(unsigned int*)((char*)self_ + 0x40); b = *(unsigned int*)((char*)self_ + 0x44);
    if (a < b) v[0x180/4](dev, a, a * 16 + *(int*)((char*)self_ + 0x30), b - a);
    a = *(unsigned int*)((char*)self_ + 0x48); b = *(unsigned int*)((char*)self_ + 0x4c);
    if (a < b) v[0x1bc/4](dev, a, a * 16 + *(int*)((char*)self_ + 0x38), b - a);
    *(unsigned int*)((char*)self_ + 0x20) = *(unsigned int*)((char*)self_ + 0x2c);
    *(unsigned int*)((char*)self_ + 0x18) = *(unsigned int*)((char*)self_ + 0x28);
    *(unsigned int*)((char*)self_ + 0x40) = *(unsigned int*)((char*)self_ + 0x50);
    *(unsigned int*)((char*)self_ + 0x68) = *(unsigned int*)((char*)self_ + 0x78);
    *(unsigned int*)((char*)self_ + 0x48) = *(unsigned int*)((char*)self_ + 0x54);
    *(unsigned int*)((char*)self_ + 0x70) = *(unsigned int*)((char*)self_ + 0x7c);
    *(unsigned int*)((char*)self_ + 0x1c) = 0; *(unsigned int*)((char*)self_ + 0x24) = 0;
    *(unsigned int*)((char*)self_ + 0x44) = 0; *(unsigned int*)((char*)self_ + 0x4c) = 0;
    *(unsigned int*)((char*)self_ + 0x6c) = 0; *(unsigned int*)((char*)self_ + 0x74) = 0;
}

// 0x005dbc50 — second deleting dtor: vtable 0x6c8e90 then FUN_005ddf50; conditional operator_delete.
extern "C" void* __thiscall Band6Wave2_DeletingDtor2(void* self_, unsigned char flag) {
    *(int**)self_ = (int**)0x006c8e90;
    extern void __thiscall Band6Wave2_Tail(void*);
    Band6Wave2_Tail(self_);
    if (flag & 1) operator_delete(self_);
    return self_;
}

// 0x005dbd00 — fetch: virtual +0x18 -> FUN_005de050 -> virtual +0x34 -> FUN_005f8091 -> virtual +0x54.
extern "C" int __thiscall Band6Wave2_Fetch(void* self_) {
    typedef int (__thiscall *V0)(void*);
    typedef void (__thiscall *V1)(void*, void*);
    typedef void (__thiscall *V2)(void*, unsigned char*);
    int h = ((V0)(*(int**)self_)[0x18/4])(self_);
    if (h == 0) return 0;
    extern int FUN_005de050(int);
    int w = FUN_005de050(h);
    if (w == 0) return 0;
    ((V1)(*(int**)self_)[0x34/4])(self_, (void*)(long)w);
    unsigned char buf;
    extern int FUN_005f8091(int, unsigned char*);
    if (FUN_005f8091(h, &buf) >= 0)
        ((V2)(*(int**)self_)[0x54/4])(self_, &buf);
    return 1;
}

// 0x005dbd70 — return *(void**)(self+0xc).
extern "C" void* __thiscall Band6Wave2_GetFieldC(void* self_) {
    return *(void**)((char*)self_ + 0xc);
}

// 0x005dbd80 — set owned name at +0xc: free when longer, alloc len+1, strcpy; clear on null/empty.
extern "C" void __thiscall Band6Wave2_SetName(void* self_, char* s) {
    char** slot = (char**)((char*)self_ + 0xc);
    if (s && s[0] != 0) {
        size_t need = strlen(s) + 1;
        if (*slot && need > strlen(*slot) + 1) { operator_delete__(*slot); *slot = 0; }
        if (!*slot) *slot = (char*)FUN_00533c78((unsigned int)need);
        strcpy(*slot, s);
        return;
    }
    operator_delete__(*slot);
    *slot = 0;
}

// 0x005dbe20 — return *(void**)(self+0x10).
extern "C" void* __thiscall Band6Wave2_GetField10(void* self_) {
    return *(void**)((char*)self_ + 0x10);
}
