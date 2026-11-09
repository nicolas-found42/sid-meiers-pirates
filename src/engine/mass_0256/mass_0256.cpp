// Reconstruction batch mass_0256 — Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
// Source corpus: Ghidra 12.2 pseudocode, one file per function.
#include <cstdint>
#include <cstddef>
#include <cmath>

extern void FUN_005f8d40(int arg);

// 0x5f1d23 — observed shape
// Weighted cubic blend of five 4-component vectors parameterized by t (param_6).
// Weights are polynomial in t: w0 = (t^2*2 - t^3) - t2, etc., all scaled by 0.5.
// Preserves the exact arithmetic order of the decompile.
void FUN_005f1d23(float *out, float *p2, float *p3, float *p4, float *p5, float t)
{
    float t2 = t * t;
    float t3 = t * t2;
    float w2 = (t2 * 2.0f - t3) - t;
    float w3 = (t3 * 3.0f - t2 * 5.0f) + 2.0f;
    float w4 = (t2 * 4.0f - t3 * 3.0f) + t;
    float w5 = t3 - t2;
    out[0] = (w5 * *p5 + w4 * *p4 + w3 * *p3 + w2 * *p2) * 0.5f;
    out[1] = (w2 * p2[1] + w3 * p3[1] + w4 * p4[1] + w5 * p5[1]) * 0.5f;
    out[2] = (w2 * p2[2] + w3 * p3[2] + w4 * p4[2] + w5 * p5[2]) * 0.5f;
    out[3] = (w2 * p2[3] + w3 * p3[3] + w4 * p4[3] + w5 * p5[3]) * 0.5f;
}

// 0x5f1e18 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (6 params) via PTR_FUN_007188e4.
extern void PTR_FUN_007188e4(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5);
void FUN_005f1e18(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5)
{
    FUN_005f8d40(1);
    PTR_FUN_007188e4(a0, a1, a2, a3, a4, a5);
}

// 0x5f1e49 — observed shape
// Bilinear blend of four 4-component vectors (a + (c-a)*u + (b-a)*v).
// Out = p2 + (p4 - p2)*param_6 + (p3 - p2)*param_5, per component.
void FUN_005f1e49(float *out, float *p2, float *p3, float *p4, float u, float v)
{
    out[0] = (*p4 - *p2) * v + (*p3 - *p2) * u + *p2;
    out[1] = (p4[1] - p2[1]) * v + (p3[1] - p2[1]) * u + p2[1];
    out[2] = (p4[2] - p2[2]) * v + (p3[2] - p2[2]) * u + p2[2];
    out[3] = (p4[3] - p2[3]) * v + (p3[3] - p2[3]) * u + p2[3];
}

// 0x5f1ec2 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (0 params) via _DAT_00718810.
extern void _DAT_00718810(void);
void FUN_005f1ec2(void)
{
    FUN_005f8d40(1);
    _DAT_00718810();
}

// 0x5f1f7c — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (0 params) via _DAT_00718910.
extern void _DAT_00718910(void);
void FUN_005f1f7c(void)
{
    FUN_005f8d40(1);
    _DAT_00718910();
}

// 0x5f2050 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (0 params) via _DAT_00718834.
extern void _DAT_00718834(void);
void FUN_005f2050(void)
{
    FUN_005f8d40(1);
    _DAT_00718834();
}

// 0x5f2135 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (0 params) via _DAT_00718838.
extern void _DAT_00718838(void);
void FUN_005f2135(void)
{
    FUN_005f8d40(1);
    _DAT_00718838();
}

// 0x5f2148 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (0 params) via _DAT_00718814.
extern void _DAT_00718814(void);
void FUN_005f2148(void)
{
    FUN_005f8d40(1);
    _DAT_00718814();
}

// 0x5f2399 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (0 params) via _DAT_007188a0.
extern void _DAT_007188a0(void);
void FUN_005f2399(void)
{
    FUN_005f8d40(1);
    _DAT_007188a0();
}

// 0x5f2423 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (0 params) via _DAT_00718818.
extern void _DAT_00718818(void);
void FUN_005f2423(void)
{
    FUN_005f8d40(1);
    _DAT_00718818();
}

// 0x5f266e — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (0 params) via _DAT_00718854.
extern void _DAT_00718854(void);
void FUN_005f266e(void)
{
    FUN_005f8d40(1);
    _DAT_00718854();
}

// 0x5f2a2e — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (4 params) via PTR_FUN_00718890.
extern void PTR_FUN_00718890(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3);
void FUN_005f2a2e(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    FUN_005f8d40(1);
    PTR_FUN_00718890(a0, a1, a2, a3);
}

// 0x5f2a5e — observed shape
// Initialize a 4x4 float matrix (16 words): zeros except
// [0]=param_2, [5]=param_3, [10]=param_4, [15]=0x3f800000 (1.0f).
void FUN_005f2a5e(uint32_t *m, uint32_t p2, uint32_t p3, uint32_t p4)
{
    m[14] = 0;
    m[0] = p2;
    m[13] = 0;
    m[5] = p3;
    m[12] = 0;
    m[10] = p4;
    m[11] = 0;
    m[9] = 0;
    m[8] = 0;
    m[7] = 0;
    m[6] = 0;
    m[4] = 0;
    m[3] = 0;
    m[2] = 0;
    m[1] = 0;
    m[15] = 0x3f800000;
}

// 0x5f2abc — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (4 params) via PTR_FUN_00718874.
extern void PTR_FUN_00718874(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3);
void FUN_005f2abc(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    FUN_005f8d40(1);
    PTR_FUN_00718874(a0, a1, a2, a3);
}

// 0x5f2b50 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (2 params) via PTR_FUN_00718884.
extern void PTR_FUN_00718884(uint32_t a0, uint32_t a1);
void FUN_005f2b50(uint32_t a0, uint32_t a1)
{
    FUN_005f8d40(1);
    PTR_FUN_00718884(a0, a1);
}

// 0x5f2b70 — observed shape
// Build a 2D Z-rotation 4x4 matrix from angle param_2:
// [cos,-sin,0,0; sin,cos,0,0; 0,0,1,0; 0,0,0,1] stored column/row-interleaved.
// Decompile writes: [0]=0x3f800000, [5]=cos, [6]=sin, [9]=-sin, [10]=cos, [15]=0x3f800000, rest 0.
void FUN_005f2b70(uint32_t *m, float angle)
{
    float c = cosf(angle);
    float s = sinf(angle);
    m[0] = 0x3f800000;
    m[1] = 0;
    m[6] = *reinterpret_cast<uint32_t*>(&s);
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = *reinterpret_cast<uint32_t*>(&c);
    m[7] = 0;
    m[8] = 0;
    m[9] = *reinterpret_cast<uint32_t*>(&s) ^ 0x80000000u;
    m[10] = *reinterpret_cast<uint32_t*>(&c);
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[15] = 0x3f800000;
}

// 0x5f2bec — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (2 params) via PTR_FUN_00718888.
extern void PTR_FUN_00718888(uint32_t a0, uint32_t a1);
void FUN_005f2bec(uint32_t a0, uint32_t a1)
{
    FUN_005f8d40(1);
    PTR_FUN_00718888(a0, a1);
}

// 0x5f2c0c — observed shape
// Build a 2D Y-rotation 4x4 matrix from angle param_2:
// [cos,0,-sin,0; 0,1,0,0; sin,0,cos,0; 0,0,0,1].
void FUN_005f2c0c(float *m, float angle)
{
    float c = cosf(angle);
    float s = sinf(angle);
    m[0] = c;
    m[1] = 0.0f;
    m[2] = -s;
    m[3] = 0.0f;
    m[4] = 0.0f;
    m[5] = 1.0f;
    m[6] = 0.0f;
    m[7] = 0.0f;
    m[8] = s;
    m[9] = 0.0f;
    m[10] = c;
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
}

// 0x5f2c89 — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (2 params) via PTR_FUN_0071888c.
extern void PTR_FUN_0071888c(uint32_t a0, uint32_t a1);
void FUN_005f2c89(uint32_t a0, uint32_t a1)
{
    FUN_005f8d40(1);
    PTR_FUN_0071888c(a0, a1);
}

// 0x5f2d2d — observed shape
// Trampoline: call FUN_005f8d40(1), then tail-call (3 params) via PTR_FUN_007188b4.
extern void PTR_FUN_007188b4(uint32_t a0, uint32_t a1, uint32_t a2);
void FUN_005f2d2d(uint32_t a0, uint32_t a1, uint32_t a2)
{
    FUN_005f8d40(1);
    PTR_FUN_007188b4(a0, a1, a2);
}
