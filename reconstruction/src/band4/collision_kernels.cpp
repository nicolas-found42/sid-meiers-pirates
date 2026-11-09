// Band4 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Collision-object kernels, small first. Corpus:
// analysis/pseudocode/functions/0x5832a0.c, 0x58b8e0.c, 0x589b60.c,
// 0x58ec00.c, 0x585940.c, 0x5859a0.c
#include <stddef.h>

extern const void* g_vtable_6c4ee4; // vtable at 0x006c4ee4
extern float       g_origin_727430, g_origin_727434, g_origin_727438;
extern float       __cdecl FUN_00599230(const void* a, const void* b,
                                       const void* c, const void* d, const void* e);
extern void        __cdecl FUN_00491640(void); // observed empty call in 0x005859a0

// 0x005832a0 — provider loop increments both pointers before the copy, so it
// copies src[1..15] to self[1..15]; slot 0 is never written.
void __thiscall FUN_005832a0(void* self, const unsigned* src)
{
    unsigned* dst = (unsigned*)self;
    for (int i = 1; i < 16; ++i) {
        dst[i] = src[i];
    }
}

// 0x0058b8e0 — install vtable 0x006c4ee4, then the same 15-dword copy.
void __thiscall FUN_0058b8e0(void* self, const unsigned* src)
{
    *(const void**)self = &g_vtable_6c4ee4;
    unsigned* dst = (unsigned*)self;
    for (int i = 1; i < 16; ++i) {
        dst[i] = src[i];
    }
}

// 0x00589b60 — fill slots 1..3 from param_2, 0xd..0xf from param_1,
// 4..6 from param_3, 7..9 from param_4, 0xa..0xc from param_5; vptr first.
void __thiscall FUN_00589b60(void* self_raw, const float* p1, const float* p2,
                             const float* p3, const float* p4, const float* p5)
{
    float* self = (float*)self_raw;
    *(const void**)self = &g_vtable_6c4ee4;
    self[1] = p2[0]; self[2] = p2[1]; self[3] = p2[2];
    self[0xd] = p1[0]; self[0xe] = p1[1]; self[0xf] = p1[2];
    self[4] = p3[0]; self[5] = p3[1]; self[6] = p3[2];
    self[7] = p4[0]; self[8] = p4[1]; self[9] = p4[2];
    self[0xa] = p5[0]; self[0xb] = p5[1]; self[0xc] = p5[2];
}

// 0x0058ec00 — return (byte flag at this+0x52) == 0 && (a in {0,1} ||
// b in {0,1}) ? 0 : 1. Observed predicate, kept exact.
int __thiscall FUN_0058ec00(void* self, int a, int b)
{
    char flag = *(char*)((char*)self + 0x52);
    if (flag == 0 && (a == 0 || a == 1 || b == 0 || b == 1)) {
        return 0;
    }
    return 1;
}

// 0x00585940 — point = t*dir + origin; return kern(point, ...) - r0x12.
float __cdecl FUN_00585940(float t, const float* q)
{
    float point[3];
    point[0] = t * q[3] + q[0];
    point[1] = t * q[4] + q[1];
    point[2] = t * q[5] + q[2];
    float r = FUN_00599230(point, q + 6, q + 0x13, q + 0x14, q + 0x15);
    return r - q[0x12];
}

// 0x005859a0 — sum three fixed vectors with per-vector sign args
// (+1 add / -1 subtract / other no-op), base = DAT_00727430/34/38.
void __thiscall FUN_005859a0(void* self_raw, float* out, int s1, int s2, int s3)
{
    float x = g_origin_727430, y = g_origin_727434, z = g_origin_727438;
    const float* self = (const float*)self_raw;
    if (s1 == 1)      { x += self[4]; y += self[5]; z += self[6]; }
    else if (s1 == -1){ x -= self[4]; y -= self[5]; z -= self[6]; }
    if (s2 == 1)      { x += self[7]; y += self[8]; z += self[9]; }
    else if (s2 == -1){ x -= self[7]; y -= self[8]; z -= self[9]; }
    if (s3 == 1)      { x += self[0xa]; y += self[0xb]; z += self[0xc]; }
    else if (s3 == -1){ x -= self[0xa]; y -= self[0xb]; z -= self[0xc]; }
    FUN_00491640();
    out[0] = x; out[1] = y; out[2] = z;
}
