#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern void* thunk_FUN_00533c78(uint32_t n);
extern void FUN_00541140(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);
extern void FUN_00541580(void* self);

// 0x559070 — observed shape: delete field at +0x48, store param
void FUN_00559070(void* self, uint32_t param_1) {
    char* ecx = static_cast<char*>(self);
    operator_delete__(*reinterpret_cast<void**>(ecx + 0x48));
    *reinterpret_cast<uint32_t*>(ecx + 0x48) = param_1;
}

// 0x559090 — observed shape: delete field at +0x4c, store param
void FUN_00559090(void* self, uint32_t param_1) {
    char* ecx = static_cast<char*>(self);
    operator_delete__(*reinterpret_cast<void**>(ecx + 0x4c));
    *reinterpret_cast<uint32_t*>(ecx + 0x4c) = param_1;
}

// 0x5590b0 — observed shape: remove index param_1, shift tail element down across parallel arrays at +0x20,+0x28,+0x24,+0x40,+0x48,+0x4c, decrement count at +0x44
void FUN_005590b0(void* self, uint16_t param_1) {
    char* ecx = static_cast<char*>(self);
    uint16_t count = *reinterpret_cast<int16_t*>(ecx + 0x44);
    uint16_t last = static_cast<uint16_t>(count - 1);
    if (param_1 == last) {
        *reinterpret_cast<int16_t*>(ecx + 0x44) = static_cast<int16_t>(count - 1);
        return;
    }
    uint32_t tail = last;
    uint32_t idx = param_1;
    uint32_t* dst12 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0x20) + idx * 0xc);
    uint32_t* src12 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0x20) + tail * 0xc);
    dst12[0] = src12[0];
    dst12[1] = src12[1];
    dst12[2] = src12[2];
    uint32_t base28 = *reinterpret_cast<uint32_t*>(ecx + 0x28);
    if (base28 != 0) {
        uint32_t* s = reinterpret_cast<uint32_t*>(base28 + tail * 0x10);
        uint32_t* d = reinterpret_cast<uint32_t*>(base28 + idx * 0x10);
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
    }
    uint32_t base24 = *reinterpret_cast<uint32_t*>(ecx + 0x24);
    if (base24 != 0) {
        uint32_t* s = reinterpret_cast<uint32_t*>(base24 + tail * 0xc);
        uint32_t* d = reinterpret_cast<uint32_t*>(base24 + idx * 0xc);
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2];
    }
    uint32_t base40 = *reinterpret_cast<uint32_t*>(ecx + 0x40);
    if (base40 != 0) {
        *reinterpret_cast<uint32_t*>(base40 + idx * 4) = *reinterpret_cast<uint32_t*>(base40 + tail * 4);
    }
    uint32_t base48 = *reinterpret_cast<uint32_t*>(ecx + 0x48);
    if (base48 != 0) {
        *reinterpret_cast<uint32_t*>(base48 + idx * 4) = *reinterpret_cast<uint32_t*>(base48 + tail * 4);
    }
    uint32_t base4c = *reinterpret_cast<uint32_t*>(ecx + 0x4c);
    if (base4c != 0) {
        uint32_t* s = reinterpret_cast<uint32_t*>(base4c + tail * 0x10);
        uint32_t* d = reinterpret_cast<uint32_t*>(base4c + idx * 0x10);
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
    }
    *reinterpret_cast<int16_t*>(ecx + 0x44) = static_cast<int16_t>(count - 1);
}

// 0x5591e0 — observed shape: ctor; vtable PTR_FUN_006c2ee8, two float arrays sized param_1&0xffff filled with 0x3f800000, flag byte+0x3c cleared, ushort at +0x32 OR 0x8000
void FUN_005591e0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5) {
    FUN_00541140(param_1, param_2, param_3, param_4, 0, 0, 0);
    uint32_t* ecx = static_cast<uint32_t*>(self);
    uint32_t n = param_1 & 0xffff;
    *ecx = 0x006c2ee8u; // PTR_FUN_006c2ee8
    ecx[0x13] = param_5;
    ecx[0x10] = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(n * 4));
    *(int16_t*)(ecx + 0x11) = static_cast<int16_t>(param_1);
    ecx[0x12] = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(n * 4));
    if (static_cast<int16_t>(param_1) != 0) {
        uint32_t off = 0;
        uint32_t rem = n;
        do {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(ecx[0x10]) + off) = 0x3f800000;
            *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(ecx[0x12]) + off) = 0x3f800000;
            off += 4;
            rem -= 1;
        } while (rem != 0);
    }
    *(uint8_t*)(reinterpret_cast<uint8_t*>(ecx) + 0x3c) = 0;
    uint16_t* f32 = reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(ecx) + 0x32);
    *f32 = static_cast<uint16_t>((*f32 & 0xfff) | 0x8000);
}

// 0x559280 — observed shape: dtor; vtable PTR_FUN_006c2ee8, delete fields at 0x10,0x12,0x13, base dtor call, conditional self-delete when param_1&1
void FUN_00559280(void* self, uint8_t param_1) {
    uint32_t* ecx = static_cast<uint32_t*>(self);
    *ecx = 0x006c2ee8u; // PTR_FUN_006c2ee8
    operator_delete__(reinterpret_cast<void*>(ecx[0x10]));
    operator_delete__(reinterpret_cast<void*>(ecx[0x12]));
    operator_delete__(reinterpret_cast<void*>(ecx[0x13]));
    FUN_00541580(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5592d0 — observed shape: default ctor; base call, fields 0x10/0x12/0x13 zeroed, vtable PTR_FUN_006c2ee8, flag ushort at +0x32 OR 0x8000
void FUN_005592d0(void* self) {
    uint32_t* ecx = static_cast<uint32_t*>(self);
    FUN_005411f0();
    ecx[0x10] = 0;
    *(uint16_t*)(ecx + 0x11) = 0;
    ecx[0x12] = 0;
    ecx[0x13] = 0;
    *(uint8_t*)(reinterpret_cast<uint8_t*>(ecx) + 0x3c) = 0;
    *ecx = 0x006c2ee8u;
    uint16_t* f = reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(ecx) + 0x32);
    *f = static_cast<uint16_t>((*f & 0xfff) | 0x8000);
}

// 0x5593c0 — NEEDS_MANUAL: comparison routine with CONCAT22 float-flag encoding and NAN handling; return value built from flag bits, structure preserved below as observed
uint32_t FUN_005593c0(void* self, int param_1) {
    char* ecx = static_cast<char*>(self);
    char* param = reinterpret_cast<char*>(static_cast<intptr_t>(param_1));
    uint32_t r = FUN_00541de0(param_1);
    if (static_cast<char>(r) == 0) {
        uint32_t v = *reinterpret_cast<uint32_t*>(param + 0x40);
        if (v != 0) return v & 0xffffff00u;
        return 0;
    }
    uint32_t a40 = *reinterpret_cast<uint32_t*>(ecx + 0x40);
    uint32_t b40 = *reinterpret_cast<uint32_t*>(param + 0x40);
    uint32_t flag = 0;
    if (a40 == 0 || b40 == 0) {
        if (a40 != b40) return (a40 ? a40 : b40) & 0xffffff00u;
    } else {
        uint16_t n = *reinterpret_cast<uint16_t*>(ecx + 0xc);
        for (uint32_t i = 0; i < n; ++i) {
            float fA = *reinterpret_cast<float*>(a40 + i * 4);
            float fB = *reinterpret_cast<float*>(b40 + i * 4);
            if (fA != fB) return 0;
        }
    }
    int16_t selfCount = *reinterpret_cast<int16_t*>(ecx + 0x44);
    int16_t otherCount = *reinterpret_cast<int16_t*>(param + 0x44);
    if (selfCount != otherCount) return 0;
    uint32_t a48 = *reinterpret_cast<uint32_t*>(ecx + 0x48);
    uint32_t b48 = *reinterpret_cast<uint32_t*>(param + 0x48);
    if (a48 == 0 || b48 == 0) {
        if (a48 != b48) return 0;
    } else {
        uint16_t n = *reinterpret_cast<uint16_t*>(ecx + 0xc);
        for (uint32_t i = 0; i < n; ++i) {
            float fA = *reinterpret_cast<float*>(a48 + i * 4);
            float fB = *reinterpret_cast<float*>(b48 + i * 4);
            if (fA != fB) return 0;
        }
    }
    uint32_t a4c = *reinterpret_cast<uint32_t*>(ecx + 0x4c);
    uint32_t b4c = *reinterpret_cast<uint32_t*>(param + 0x4c);
    if (a4c == 0 || b4c == 0) {
        if (a4c != b4c) return 0;
    } else {
        uint16_t n = *reinterpret_cast<uint16_t*>(ecx + 0xc);
        for (uint32_t i = 0; i < n; ++i) {
            for (int k = 0; k < 4; ++k) {
                float fA = *reinterpret_cast<float*>(a4c + i * 0x10 + k * 4);
                float fB = *reinterpret_cast<float*>(b4c + i * 0x10 + k * 4);
                if (fA != fB) return 0;
            }
        }
    }
    return 1;
}

// 0x559510 — NEEDS_MANUAL: serialization/restore with version checks, virtual calls at *(param+0x15c)+8, three array allocations at +0x40/+0x48/+0x4c; global default DAT_00717a68 used for +0x4c fill
void FUN_00559510(void* self, int param_1) {
    char* ecx = static_cast<char*>(self);
    uint32_t count = *reinterpret_cast<uint16_t*>(ecx + 0xc);
    FUN_005418d0();
    uint32_t version = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0x1c);
    // allocate +0x40 (count*4)
    *reinterpret_cast<uint32_t*>(ecx + 0x40) = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(count << 2));
    // allocate +0x48 (count*4)
    *reinterpret_cast<uint32_t*>(ecx + 0x48) = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(count << 2));
    // allocate +0x4c (count*0x10)
    *reinterpret_cast<uint32_t*>(ecx + 0x4c) = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(count << 4));
    if (version < 0xa000110) {
        uint16_t* f = reinterpret_cast<uint16_t*>(ecx + 0x32);
        *f = static_cast<uint16_t>((*f & 0xfff) | 0x8000);
    }
}

// 0x5597c0 — observed shape: save via vtable at param+0x160; conditional writes for +0x40/+0x44/+0x48, then per-element FUN_00556150 loop over count at +0xc
void FUN_005597c0(void* self, int param_1);
extern void FUN_00556150(int owner);
void FUN_005597c0_impl(void* self, int param_1) {
    char* ecx = static_cast<char*>(self);
    FUN_00541c20();
    // virtual save dispatch at *(param+0x160)+0xc invoked for each present member
    uint16_t n = *reinterpret_cast<uint16_t*>(ecx + 0xc);
    if (n != 0) {
        for (uint32_t i = 0; i < n; ++i) {
            FUN_00556150(param_1);
        }
    }
}

// 0x5598b0 — observed shape: property registration; for each member (base, m_pfRadii, m_usActive, m_pfSizes) ensure capacity via FUN_006b34a0 then FUN_005606f0
void FUN_005598b0(void* self, int param_1) {
    char* ecx = static_cast<char*>(self);
    FUN_005420e0(param_1);
    uint32_t idx = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0xc);
    uint32_t cap = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 8);
    if (cap <= idx) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0x14) + idx);
    }
    FUN_005606f0(idx, reinterpret_cast<uint32_t*>(FUN_00557b10(DAT_00727cec)));
    param_1 = FUN_00557d40("m_pfRadii", *reinterpret_cast<uint32_t*>(ecx + 0x40));
    idx = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0xc);
    if (cap <= idx) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0x14) + idx);
    }
    FUN_005606f0(idx, &param_1);
    param_1 = FUN_00557c30("m_usActive", *reinterpret_cast<uint16_t*>(ecx + 0x44));
    idx = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0xc);
    if (cap <= idx) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0x14) + idx);
    }
    FUN_005606f0(idx, &param_1);
    param_1 = FUN_00557d40("m_pfSizes", *reinterpret_cast<uint32_t*>(ecx + 0x48));
    idx = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0xc);
    if (cap <= idx) {
        FUN_006b34a0(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<intptr_t>(param_1)) + 0x14) + idx);
    }
    FUN_005606f0(idx, &param_1);
}

// 0x5599b0 — observed shape: base init chain; FUN_00538630(param) then FUN_00545cc0 twice and FUN_00545d20
void FUN_005599b0(void* self, uint32_t param_1) {
    FUN_00538630(param_1);
    FUN_00545cc0();
    FUN_00545cc0();
    FUN_00545d20();
}

// 0x559a40 — observed shape: membership test; FUN_005bd960 over head at +0x10 then array at +0x14 count at *(*(self+0xc)+0x44); returns 1 on match else 0
uint32_t FUN_00559a40(void* self, uint8_t param_1) {
    char* ecx = static_cast<char*>(self);
    if (FUN_005bd960(*reinterpret_cast<uint32_t*>(ecx + 0x10), &param_1) != 0) return 1;
    uint32_t n = *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0xc) + 0x44);
    for (uint32_t i = 0; i < n; ++i) {
        if (FUN_005bd960(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0x14) + i * 4), &param_1) != 0) return 1;
    }
    return 0;
}

// 0x559ab0 — observed shape: rebuild list; release old head at +0xc via refcount, store FUN_00545600() at +0x10, fill array at +0x14 sized FUN_00545630()
void FUN_00559ab0(void* self, uint32_t param_1) {
    char* ecx = static_cast<char*>(self);
    FUN_00513ce0(param_1);
    uint32_t* fresh = static_cast<uint32_t*>(FUN_00545600());
    uint32_t* old = *reinterpret_cast<uint32_t**>(ecx + 0xc);
    if (old != fresh) {
        if (old != nullptr) {
            int32_t rc = *reinterpret_cast<int32_t*>(old + 1);
            rc -= 1;
            *reinterpret_cast<int32_t*>(old + 1) = rc;
            if (rc == 0) {
                using Deleter = void(*)(uint32_t);
                reinterpret_cast<Deleter>(*old)(1);
            }
        }
        *reinterpret_cast<uint32_t**>(ecx + 0xc) = fresh;
        if (fresh != nullptr) fresh[1] += 1;
    }
    *reinterpret_cast<uint32_t*>(ecx + 0x10) = FUN_00545600();
    uint32_t n = FUN_00545630();
    *reinterpret_cast<uint32_t*>(ecx + 0x14) = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(n * 4));
    for (uint32_t i = 0; i < n; ++i) {
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0x14) + i * 4) = FUN_00545600();
    }
}

// 0x559b30 — observed shape: broadcast; guard FUN_00538360, then virtual call slot 0x14 on +0xc, +0x10, and each of +0x14 items
uint8_t FUN_00559b30(void* self, uint32_t param_1) {
    char* ecx = static_cast<char*>(self);
    if (FUN_00538360(param_1) == 0) return 0;
    using CallFn = void(*)(void*, uint32_t);
    // invoke slot 0x14 (index 5) of vtable for each target
    uint32_t* vt_c = *reinterpret_cast<uint32_t**>(ecx + 0xc);
    reinterpret_cast<CallFn>(vt_c[5])(*reinterpret_cast<void**>(ecx + 0xc), param_1);
    uint32_t* vt_10 = *reinterpret_cast<uint32_t**>(ecx + 0x10);
    reinterpret_cast<CallFn>(vt_10[5])(*reinterpret_cast<void**>(ecx + 0x10), param_1);
    uint32_t n = *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0xc) + 0x44);
    for (uint32_t i = 0; i < n; ++i) {
        uint32_t* item = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0x14) + i * 4);
        uint32_t* vt = *reinterpret_cast<uint32_t**>(item);
        reinterpret_cast<CallFn>(vt[5])(item, param_1);
    }
    return 1;
}

// 0x559c30 — observed shape: copy bones; FUN_00548720 for first at +0x48+0x34 and rest stride 0x4c, then matrix-extract tail via FUN_00548b20
void FUN_00559c30(void* self) {
    char* ecx = static_cast<char*>(self);
    uint32_t* slots = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0xc));
    int base = *reinterpret_cast<int*>(reinterpret_cast<char*>(slots) + 0x48);
    uint32_t n = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(slots) + 0x44);
    FUN_00548720(base + 0x34, *reinterpret_cast<uint32_t*>(ecx + 0x14) + 0x6c);
    for (uint32_t i = 1; i < n; ++i) {
        FUN_00548720(base + i * 0x4c + 0x34, *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(ecx + 0x14) + i * 4) + 0x6c);
        FUN_00548600();
    }
    uint8_t buf[52];
    uint8_t mat[52];
    uint32_t out[13];
    FUN_005579c0(buf);
    uint32_t* r = static_cast<uint32_t*>(FUN_00548b20(mat, buf));
    for (int i = 0; i < 13; ++i) out[i] = r[i];
    FUN_00548720();
}

// 0x559e60 — NEEDS_MANUAL: property display with qsort of bone names; per-bone property add with capacity grow and refcount adjust at +0x10
void FUN_00559e60(void* self, void* param_1) {
    char* ecx = static_cast<char*>(self);
    int selfInt = reinterpret_cast<int>(param_1);
    FUN_005386f0(param_1);
    uint32_t idx = *reinterpret_cast<uint32_t*>(selfInt + 0xc);
    if (*reinterpret_cast<uint32_t*>(selfInt + 8) <= idx) {
        FUN_006b34a0(*reinterpret_cast<int*>(selfInt + 0x14) + idx);
    }
    int node = FUN_00557b10(DAT_00727cf4);
    FUN_005606f0(idx, &node);
    if (*reinterpret_cast<int*>(ecx + 0x10) != 0) {
        int parent = FUN_00557d80("Root Parent", *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(ecx + 0x10) + 0xc));
        idx = *reinterpret_cast<uint32_t*>(selfInt + 0xc);
        if (*reinterpret_cast<uint32_t*>(selfInt + 8) <= idx) {
            FUN_006b34a0(*reinterpret_cast<int*>(selfInt + 0x14) + idx);
        }
        FUN_005606f0(idx, &parent);
    }
    int child = *reinterpret_cast<int*>(ecx + 0xc);
    if (child != 0) {
        uint32_t hw = 0;
        if (*reinterpret_cast<int*>(child + 0xc) != 0) {
            hw = *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(child + 0xc) + 0xc);
        }
        int hwNode = FUN_00557cb0("Hardware partitions", hw);
        idx = *reinterpret_cast<uint32_t*>(selfInt + 0xc);
        if (*reinterpret_cast<uint32_t*>(selfInt + 8) <= idx) {
            FUN_006b34a0(*reinterpret_cast<int*>(selfInt + 0x14) + idx);
        }
        FUN_005606f0(idx, &hwNode);
        uint32_t boneCount = *reinterpret_cast<uint32_t*>(child + 0x44);
        int boneNode = FUN_00557cb0("Bone Count", boneCount);
        uint32_t idx2 = *reinterpret_cast<uint32_t*>(selfInt + 0xc);
        if (*reinterpret_cast<uint32_t*>(selfInt + 8) <= idx2) {
            FUN_006b34a0(*reinterpret_cast<int*>(selfInt + 0x14) + idx2);
        }
        FUN_005606f0(idx2, &boneNode);
        void* names = thunk_FUN_00533c78(boneCount * 4);
        for (uint32_t i = 0; i < boneCount; ++i) {
            *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(names) + i * 4) =
                *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 0x14) + i * 4) + 0xc);
        }
        qsort(names, boneCount, 4, reinterpret_cast<int(*)(const void*, const void*)>(0x005599e0));
        for (uint32_t i = 0; i < boneCount; ++i) {
            char label[12];
            snprintf(label, sizeof(label), "  %3d", i);
            const char* nm = reinterpret_cast<const char*>(*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(names) + i * 4));
            if (nm == nullptr) nm = "<noname>";
            int prop = FUN_00557d80(label, nm);
            uint32_t slot = *reinterpret_cast<uint32_t*>(selfInt + 0xc);
            if (slot < *reinterpret_cast<uint32_t*>(selfInt + 8) ||
                (FUN_006b34a0(*reinterpret_cast<int*>(selfInt + 0x14) + slot), slot < *reinterpret_cast<uint32_t*>(selfInt + 8))) {
                if (slot < *reinterpret_cast<uint32_t*>(selfInt + 0xc)) {
                    if (prop == 0) {
                        if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(selfInt + 4) + slot * 4) != 0) {
                            *reinterpret_cast<int*>(selfInt + 0x10) -= 1;
                        }
                    } else if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(selfInt + 4) + slot * 4) == 0) {
                        *reinterpret_cast<int*>(selfInt + 0x10) += 1;
                    }
                } else {
                    *reinterpret_cast<uint32_t*>(selfInt + 0xc) = slot + 1;
                    if (prop != 0) *reinterpret_cast<int*>(selfInt + 0x10) += 1;
                }
                *reinterpret_cast<int*>(*reinterpret_cast<int*>(selfInt + 4) + slot * 4) = prop;
            }
        }
        operator_delete__(names);
    }
}

// 0x55a120 — observed shape: dtor; vtable PTR_FUN_006c2f90, base FUN_00547d10, conditional self-delete when param&1
void FUN_0055a120(void* self, uint8_t param_1) {
    *static_cast<uint32_t*>(self) = 0x006c2f90u;
    FUN_00547d10();
    if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x55a1b0 — observed shape: property add; base FUN_00548050, DAT_00727cfc node, capacity grow then FUN_005606f0
void FUN_0055a1b0(void* self, int param_1) {
    int node = param_1;
    FUN_00548050(param_1);
    param_1 = FUN_00557b10(DAT_00727cfc);
    uint32_t idx = *reinterpret_cast<uint32_t*>(node + 0xc);
    if (*reinterpret_cast<uint32_t*>(node + 8) <= idx) {
        FUN_006b34a0(*reinterpret_cast<int*>(node + 0x14) + idx);
    }
    FUN_005606f0(idx, &param_1);
}

// 0x55a200 — observed shape: vector init; store size, alloc size bytes at +4 and mirror pointer at +8, count 0 at +12
void FUN_0055a200(void* self, int param_1) {
    int32_t* ecx = static_cast<int32_t*>(self);
    ecx[0] = param_1;
    if (param_1 == 0) {
        ecx[1] = 0;
        ecx[2] = ecx[1];
        ecx[3] = 0;
        return;
    }
    int32_t buf = static_cast<int32_t>(reinterpret_cast<intptr_t>(thunk_FUN_00533c78(param_1)));
    ecx[1] = buf;
    ecx[2] = buf;
    ecx[3] = 0;
}

// 0x55a250 — observed shape: free buffer at +4
void FUN_0055a250(void* self) {
    char* ecx = static_cast<char*>(self);
    operator_delete__(*reinterpret_cast<void**>(ecx + 4));
}

extern void FUN_00541c20(void);

// 0x5597c0 — observed shape: stream save; FUN_00541c20 header, then the writer at
// *(param_1+0x160)+0xc writes the +0x40 presence flag, conditionally the +0x40 array
// (element count from ushort +0xc, 4 bytes each), the +0x44 halfword, the +0x48
// presence flag, conditionally the +0x48 array, one trailing byte, and finally one
// FUN_00556150(stream) per element while the +0x48 predicate holds.
void FUN_005597c0_recon(void* self, int param_1) {
    uint8_t* ecx = static_cast<uint8_t*>(self);
    typedef void (*WriteFn)(const void*, int);

    FUN_00541c20();

    uint8_t hasRadii = (*reinterpret_cast<int*>(ecx + 0x40) != 0) ? 1 : 0;
    reinterpret_cast<WriteFn>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(param_1 + 0x160) + 0xc))(&hasRadii, 1);
    // NEEDS_MANUAL: the gate below is the provider's `cStack_4 = (char)in_ECX`; the
    // stack-aliased source local is the hasRadii flag just written.
    if (hasRadii != 0) {
        reinterpret_cast<WriteFn>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(param_1 + 0x160) + 0xc))(
            reinterpret_cast<void*>(*reinterpret_cast<uint32_t*>(ecx + 0x40)),
            static_cast<int>(*reinterpret_cast<uint16_t*>(ecx + 0xc)) << 2);
    }

    // Argument list elided by the provider; the surrounding +0x44 reference fixes the source.
    reinterpret_cast<WriteFn>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(param_1 + 0x160) + 0xc))(ecx + 0x44, 2);

    uint8_t hasSizes = (*reinterpret_cast<int*>(ecx + 0x48) != 0) ? 1 : 0;
    reinterpret_cast<WriteFn>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(param_1 + 0x160) + 0xc))(&hasSizes, 1);
    // NEEDS_MANUAL: the provider derives this predicate as
    // `(char)((uint)(in_ECX + 0x44) >> 0x10)`, an address-artifact of the +0x44
    // halfword test that gates the +0x48 array write.
    if (*reinterpret_cast<uint16_t*>(ecx + 0x44) != 0) {
        reinterpret_cast<WriteFn>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(param_1 + 0x160) + 0xc))(
            reinterpret_cast<void*>(*reinterpret_cast<uint32_t*>(ecx + 0x48)),
            static_cast<int>(*reinterpret_cast<uint16_t*>(ecx + 0xc)) << 2);
    }

    // NEEDS_MANUAL: the provider passes `auStack_16 + -3` (one byte outside its declared
    // frame local); the originating source local is not recoverable from the listing.
    uint8_t tailFlag = hasSizes;
    reinterpret_cast<WriteFn>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(param_1 + 0x160) + 0xc))(&tailFlag, 1);

    if (hasSizes != 0) {
        uint16_t n = *reinterpret_cast<uint16_t*>(ecx + 0xc);
        for (uint32_t i = 0; i < n; ++i) {
            FUN_00556150(param_1);
        }
    }
}
