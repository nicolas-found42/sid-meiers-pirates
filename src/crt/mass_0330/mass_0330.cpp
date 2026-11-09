// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// Batch mass_0330. No byte-match claim; original source names are NOT invented.
// Shared observed facts: DAT_*/FUN_* names are corpus labels, types are inferred.
// Provider register receivers (in_ECX/in_ESI/...) are modelled as explicit
// parameters; `this` is never used in these free functions.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <xmmintrin.h>

// ---- Observed globals (corpus labels; layouts inferred) ----
// Cubic Hermite/spline basis coefficients, four lanes each.
extern float DAT_007209e0, DAT_007209e4, DAT_007209e8, DAT_007209ec; // cubic terms
extern float DAT_007209f0, DAT_007209f4, DAT_007209f8, DAT_007209fc; // quadratic terms
extern float DAT_00720a00, DAT_00720a04, DAT_00720a08, DAT_00720a0c; // linear terms
extern float DAT_00720a10;                                           // constant term
// Compared for exact equality in 0x685cf8 (observed zero constant / epsilon slot).
extern float DAT_0072c638;
// Eight 16-bit lane masks tested lane-wise in 0x688391.
extern uint16_t DAT_00720c40, DAT_00720c42, DAT_00720c44, DAT_00720c46;
extern uint16_t DAT_00720c48, DAT_00720c4a, DAT_00720c4c, DAT_00720c4e;
// Three-entry next-index permutation table used by the quaternion extraction.
extern int32_t DAT_006f0b14[];

// ---- Observed SSE primitives ----
// rcpss/rsqrtss estimates: the listings refine these with one Newton step, so
// the estimate instruction (not a 1.0f/x division) is what must be preserved.
static inline float rcpss_estimate(float x)
{
    return _mm_cvtss_f32(_mm_rcp_ss(_mm_set_ss(x)));
}

static inline float rsqrtss_estimate(float x)
{
    return _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(x)));
}

// 32-bit load used by the "matrix not 16-byte aligned" fallback paths, which
// the corpus expresses as 64-bit (qword) loads split into two float lanes.
static inline float load_f32(const void* p)
{
    float v;
    std::memcpy(&v, p, 4);
    return v;
}

// Observed SSE half -> float bit trick, textually identical in the scalar tails
// of 0x687743 and 0x688484.
static inline float half_to_float(uint16_t h)
{
    uint32_t u    = static_cast<uint32_t>(h);
    uint32_t ex   = u & 0x7c00u;
    if (ex < 0x401u)
        ex = 0x400u;
    uint32_t mant = ((0u - static_cast<uint32_t>((h & 0x7c00u) != 0)) & 0x400u) | (u & 0x3ffu);
    uint32_t expo = (ex + 0x19800u) * 0x2000u | ((u & 0xffff8000u) << 0x10);
    return static_cast<float>(mant) * static_cast<float>(expo);
}

// ===== 0x685a2a =====
// Cubic basis blend of four 3-component control points. Each control point is
// read as a float pair at offsets 0/4 plus a third float at offset 8 (corpus
// packs the first two into one qword). Basis weights are polynomials in t.
// 0x685a2a — observed shape
float* FUN_00685a2a(float* out, const float* a, const float* b, const float* c,
                    const float* d, float t)
{
    float t2 = t * t;
    float t3 = t * t2;

    float w0 = t * DAT_00720a00 + DAT_00720a10 + t2 * DAT_007209f0 + t3 * DAT_007209e0;
    float w1 = t * DAT_00720a04 + t2 * DAT_007209f4 + t3 * DAT_007209e4;
    float w2 = t * DAT_00720a08 + t2 * DAT_007209f8 + t3 * DAT_007209e8;
    float w3 = t * DAT_00720a0c + t2 * DAT_007209fc + t3 * DAT_007209ec;

    out[0] = a[0] * w0 + b[0] * w1 + c[0] * w2 + d[0] * w3;
    out[1] = a[1] * w0 + b[1] * w1 + c[1] * w2 + d[1] * w3;
    out[2] = a[2] * w0 + b[2] * w1 + c[2] * w2 + d[2] * w3;
    return out;
}

// ===== 0x685adf =====
// Same four cubic basis weights as 0x685a2a, applied to full 4-component
// control points; output is four floats.
// 0x685adf — observed shape
float* FUN_00685adf(float* out, const float* a, const float* b, const float* c,
                    const float* d, float t)
{
    float t2 = t * t;
    float t3 = t * t2;

    float w0 = t * DAT_00720a00 + DAT_00720a10 + t2 * DAT_007209f0 + t3 * DAT_007209e0;
    float w1 = t * DAT_00720a04 + t2 * DAT_007209f4 + t3 * DAT_007209e4;
    float w2 = t * DAT_00720a08 + t2 * DAT_007209f8 + t3 * DAT_007209e8;
    float w3 = t * DAT_00720a0c + t2 * DAT_007209fc + t3 * DAT_007209ec;

    out[0] = a[0] * w0 + b[0] * w1 + c[0] * w2 + d[0] * w3;
    out[1] = a[1] * w0 + b[1] * w1 + c[1] * w2 + d[1] * w3;
    out[2] = a[2] * w0 + b[2] * w1 + c[2] * w2 + d[2] * w3;
    out[3] = a[3] * w0 + b[3] * w1 + c[3] * w2 + d[3] * w3;
    return out;
}

// ===== 0x685b7b =====
// Two-component (XY) basis blend. The corpus accumulates the third control
// point before the second (a*w0 + c*w2 + b*w1 + d*w3); that order is kept.
// 0x685b7b — observed shape
float* FUN_00685b7b(float* out, const float* a, const float* b, const float* c,
                    const float* d, float t)
{
    float t2 = t * t;
    float t3 = t * t2;

    float w0 = t * DAT_00720a00 + DAT_00720a10 + t2 * DAT_007209f0 + t3 * DAT_007209e0;
    float w1 = t * DAT_00720a04 + t2 * DAT_007209f4 + t3 * DAT_007209e4;
    float w2 = t * DAT_00720a08 + t2 * DAT_007209f8 + t3 * DAT_007209e8;
    float w3 = t * DAT_00720a0c + t2 * DAT_007209fc + t3 * DAT_007209ec;

    out[0] = a[0] * w0 + c[0] * w2 + b[0] * w1 + d[0] * w3;
    out[1] = a[1] * w0 + c[1] * w2 + b[1] * w1 + d[1] * w3;
    return out;
}

// ===== 0x685c03 =====
// Bilinear (two scalar weights) blend of three 3-component points, anchored at
// the first point: p + (q - p)*s + (r - p)*t. Component offsets 0/4/8.
// 0x685c03 — observed shape
float* FUN_00685c03(float* out, const float* p, const float* q, const float* r,
                    float s, float t)
{
    out[0] = (q[0] - p[0]) * s + p[0] + (r[0] - p[0]) * t;
    out[1] = (q[1] - p[1]) * s + p[1] + (r[1] - p[1]) * t;
    out[2] = (q[2] - p[2]) * s + p[2] + (r[2] - p[2]) * t;
    return out;
}

// ===== 0x685c5f =====
// Four-component form of the same bilinear blend.
// 0x685c5f — observed shape
float* FUN_00685c5f(float* out, const float* p, const float* q, const float* r,
                    float s, float t)
{
    out[0] = (q[0] - p[0]) * s + p[0] + (r[0] - p[0]) * t;
    out[1] = (q[1] - p[1]) * s + p[1] + (r[1] - p[1]) * t;
    out[2] = (q[2] - p[2]) * s + p[2] + (r[2] - p[2]) * t;
    out[3] = (q[3] - p[3]) * s + p[3] + (r[3] - p[3]) * t;
    return out;
}

// ===== 0x685ca7 =====
// Two-component form of the bilinear blend; only one output qword is written.
// 0x685ca7 — observed shape
float* FUN_00685ca7(float* out, const float* p, const float* q, const float* r,
                    float s, float t)
{
    out[0] = (q[0] - p[0]) * s + p[0] + (r[0] - p[0]) * t;
    out[1] = (q[1] - p[1]) * s + p[1] + (r[1] - p[1]) * t;
    return out;
}

// ===== 0x685cf8 =====
// Plane/segment intersection: denominator is dot(dir, p3) - dot(dir, p4); an
// exact-zero denominator returns NULL. t uses an rcpss estimate plus one Newton
// step, then the point is lerped from p3 towards p4. `dir` carries a fourth
// float (offset 12) that is added to the p3 dot product.
// NEEDS_MANUAL: the corpus reads the two dots through partially undefined XMM6
// lanes; reconstructed as the exact dot products the arithmetic implies.
// 0x685cf8 — observed shape
float* FUN_00685cf8(float* out, const float* dir, const float* p3, const float* p4)
{
    float w  = dir[3];
    float s3 = p3[0] * dir[0] + p3[1] * dir[1] + p3[2] * dir[2];
    float s4 = p4[0] * dir[0] + p4[1] * dir[1] + p4[2] * dir[2];
    float denom = s3 - s4;

    if (denom == DAT_0072c638)
        return nullptr;

    float r = rcpss_estimate(denom);
    float t = (s3 + w) * ((r + r) - denom * r * r);

    out[0] = p3[0] + t * (p4[0] - p3[0]);
    out[1] = p3[1] + t * (p4[1] - p3[1]);
    out[2] = p3[2] + t * (p4[2] - p3[2]);
    return out;
}

// ===== 0x6866b4 =====
// Row-vector transform of a 3-component point by a 4x4 matrix (translation
// column ignored). The listing branches on the matrix address' 16-byte
// alignment; both branches compute the same products, the fallback only issues
// 64-bit loads.
// 0x6866b4 — observed shape
void FUN_006866b4(float* out, const float* v, const float* m)
{
    float x = v[0];
    float y = v[1];
    float z = v[2];
    float rx, ry, rz;

    if ((reinterpret_cast<uintptr_t>(m) & 0xf) == 0) {
        rx = x * m[0] + y * m[4] + z * m[8];
        ry = x * m[1] + y * m[5] + z * m[9];
        rz = x * m[2] + y * m[6] + z * m[10];
    } else {
        rx = x * load_f32(m + 0) + y * load_f32(m + 4) + z * load_f32(m + 8);
        ry = x * load_f32(m + 1) + y * load_f32(m + 5) + z * load_f32(m + 9);
        rz = x * load_f32(m + 2) + y * load_f32(m + 6) + z * load_f32(m + 10);
    }

    out[0] = rx;
    out[1] = ry;
    out[2] = rz;
}

// ===== 0x686780 =====
// Row-vector transform of a 3-component point by a 4x4 matrix including the
// translation column (m[12..14]); four floats written.
// 0x686780 — observed shape
void FUN_00686780(float* out, const float* v, const float* m)
{
    float x = v[0];
    float y = v[1];
    float z = v[2];
    float c0, c1, c2, c3, r0, r1, r2, r3;

    if ((reinterpret_cast<uintptr_t>(m) & 0xf) == 0) {
        c0 = m[0];  c1 = m[1];  c2 = m[2];  c3 = m[3];
        r0 = m[4];  r1 = m[5];  r2 = m[6];  r3 = m[7];
        float t0 = m[8] * z + m[12];
        float t1 = m[9] * z + m[13];
        float t2 = m[10] * z + m[14];
        float t3 = m[11] * z + m[15];
        out[0] = c0 * x + r0 * y + t0;
        out[1] = c1 * x + r1 * y + t1;
        out[2] = c2 * x + r2 * y + t2;
        out[3] = c3 * x + r3 * y + t3;
    } else {
        c0 = load_f32(m + 0);  c1 = load_f32(m + 1);
        c2 = load_f32(m + 2);  c3 = load_f32(m + 3);
        r0 = load_f32(m + 4);  r1 = load_f32(m + 5);
        r2 = load_f32(m + 6);  r3 = load_f32(m + 7);
        float t0 = load_f32(m + 8) * z + load_f32(m + 12);
        float t1 = load_f32(m + 9) * z + load_f32(m + 13);
        float t2 = load_f32(m + 10) * z + load_f32(m + 14);
        float t3 = load_f32(m + 11) * z + load_f32(m + 15);
        out[0] = c0 * x + r0 * y + t0;
        out[1] = c1 * x + r1 * y + t1;
        out[2] = c2 * x + r2 * y + t2;
        out[3] = c3 * x + r3 * y + t3;
    }
}

// ===== 0x686847 =====
// Same transform as 0x686780 followed by a perspective divide: all four
// components are scaled by a reciprocal estimate of the resulting w with one
// Newton refinement. The alignment branch is the same 16-byte test. Only three
// floats are written back (the divided fourth component is not stored).
// 0x686847 — observed shape
void FUN_00686847(float* out, const float* v, const float* m)
{
    float x = v[0];
    float y = v[1];
    float z = v[2];
    float c0, c1, c2, c3, r0, r1, r2, r3, t0, t1, t2, t3;

    if ((reinterpret_cast<uintptr_t>(m) & 0xf) == 0) {
        c0 = m[0];  c1 = m[1];  c2 = m[2];  c3 = m[3];
        r0 = m[4];  r1 = m[5];  r2 = m[6];  r3 = m[7];
        t0 = m[8] * z + m[12];
        t1 = m[9] * z + m[13];
        t2 = m[10] * z + m[14];
        t3 = m[11] * z + m[15];
    } else {
        c0 = load_f32(m + 0);  c1 = load_f32(m + 1);
        c2 = load_f32(m + 2);  c3 = load_f32(m + 3);
        r0 = load_f32(m + 4);  r1 = load_f32(m + 5);
        r2 = load_f32(m + 6);  r3 = load_f32(m + 7);
        t0 = load_f32(m + 8) * z + load_f32(m + 12);
        t1 = load_f32(m + 9) * z + load_f32(m + 13);
        t2 = load_f32(m + 10) * z + load_f32(m + 14);
        t3 = load_f32(m + 11) * z + load_f32(m + 15);
    }

    r0 = c0 * x + r0 * y + t0;
    r1 = c1 * x + r1 * y + t1;
    r2 = c2 * x + r2 * y + t2;
    r3 = c3 * x + r3 * y + t3;

    float w  = rcpss_estimate(r3);
    float iw = (w + w) - w * r3 * w;

    out[0] = r0 * iw;
    out[1] = r1 * iw;
    out[2] = r2 * iw;
    return;
}

// ===== 0x68693b =====
// Receiver arrives in ECX (explicit `self` here). Each of the 16 source dwords
// is broadcast into four consecutive dwords of the destination; the destination
// stride between source columns is 0x10 dwords. Write order in the listing is
// column-major over the source (c = 0, 4, 8, 0xc) with rows ascending.
// 0x68693b — observed shape
void FUN_0068693b(void* self, const uint32_t* src)
{
    uint32_t* dst = static_cast<uint32_t*>(self);

    for (int c = 0; c < 4; ++c) {
        for (int r = 0; r < 4; ++r) {
            uint32_t v = src[c * 4 + r];
            uint32_t* row = dst + c * 0x10 + r * 4;
            row[0] = v;
            row[1] = v;
            row[2] = v;
            row[3] = v;
        }
    }
}

// ===== 0x687619 =====
// The listing contains no reads, writes or calls: an immediate return. Nothing
// is invented here; the empty body is what the provider reports.
// 0x687619 — observed shape
void FUN_00687619(void)
{
}

// ===== 0x687743 =====
// Half-float (16-bit) to float (32-bit) conversion of `count` elements.
// NEEDS_MANUAL: the 8-element-per-iteration head is a hand-vectorised loop whose
// intermediate XMM0/XMM3 result registers are not recoverable from the listing
// (its callee FUN_00687619 is an empty stub). The head is expressed with the
// same scalar conversion the exact tail uses, keeping the observed call and the
// 8/remainder split.
// 0x687743 — observed shape
float* FUN_00687743(float* dst, const uint16_t* src, uint32_t count)
{
    float* out = dst;

    if (count > 7) {
        uint32_t blocks = count & 0xfffffff8u;
        uint32_t done = 0;
        do {
            FUN_00687619();
            for (uint32_t k = 0; k < 8; ++k)
                out[done + k] = half_to_float(src[done + k]);
            done += 8;
        } while (done != blocks);

        count -= blocks;
        src   += blocks;
        out   += blocks;
    }

    for (uint32_t i = 0; i < count; ++i)
        out[i] = half_to_float(src[i]);

    return dst;
}

// ===== 0x688391 =====
// NEEDS_MANUAL: the body consumes eight 16-bit lanes that arrive only in XMM0
// (corpus names them in_XMM0_Wa..Wh) and produces no memory or register result;
// both outcomes of the final test are `return`. The register input is made an
// explicit parameter so the eight mask tests are preserved.
// 0x688391 — observed shape
void FUN_00688391(const uint16_t* xmm0)
{
    uint16_t m[8];
    m[0] = static_cast<uint16_t>(0u - static_cast<uint32_t>((DAT_00720c40 & xmm0[0]) == 0));
    m[1] = static_cast<uint16_t>(0u - static_cast<uint32_t>((DAT_00720c42 & xmm0[1]) == 0));
    m[2] = static_cast<uint16_t>(0u - static_cast<uint32_t>((DAT_00720c44 & xmm0[2]) == 0));
    m[3] = static_cast<uint16_t>(0u - static_cast<uint32_t>((DAT_00720c46 & xmm0[3]) == 0));
    m[4] = static_cast<uint16_t>(0u - static_cast<uint32_t>((DAT_00720c48 & xmm0[4]) == 0));
    m[5] = static_cast<uint16_t>(0u - static_cast<uint32_t>((DAT_00720c4a & xmm0[5]) == 0));
    m[6] = static_cast<uint16_t>(0u - static_cast<uint32_t>((DAT_00720c4c & xmm0[6]) == 0));
    m[7] = static_cast<uint16_t>(0u - static_cast<uint32_t>((DAT_00720c4e & xmm0[7]) == 0));

    // The listing expands this to bit 7 of each byte of the packed result; for
    // 0x0000/0xffff lanes that is bit 7 of every lane.
    if (((m[0] >> 7) & 1) == 0 && ((m[1] >> 7) & 1) == 0 &&
        ((m[2] >> 7) & 1) == 0 && ((m[3] >> 7) & 1) == 0 &&
        ((m[4] >> 7) & 1) == 0 && ((m[5] >> 7) & 1) == 0 &&
        ((m[6] >> 7) & 1) == 0 && ((m[7] >> 7) & 1) == 0) {
        return;
    }
    return;
}

// ===== 0x688484 =====
// Same half -> float contract as 0x687743, but the head loads the source in
// 64-bit units and calls FUN_00688391 (which takes the eight lanes in XMM0).
// NEEDS_MANUAL: the head's XMM3/XMM0 result registers are not recoverable; the
// block is realised with the exact scalar tail conversion while preserving the
// observed call and the 8/remainder split.
// 0x688484 — observed shape
float* FUN_00688484(float* dst, const uint16_t* src, uint32_t count)
{
    float* out = dst;

    if (count > 7) {
        uint32_t blocks = count & 0xfffffff8u;
        uint32_t done = 0;
        do {
            FUN_00688391(src + done);   // corpus: eight lanes passed in XMM0
            for (uint32_t k = 0; k < 8; ++k)
                out[done + k] = half_to_float(src[done + k]);
            done += 8;
        } while (done != blocks);

        count -= blocks;
        src   += blocks;
        out   += blocks;
    }

    for (uint32_t i = 0; i < count; ++i)
        out[i] = half_to_float(src[i]);

    return dst;
}

// ===== 0x688558 =====
// Row-vector transform of a 4-component vector by a 4x4 matrix, translation
// included. Same 16-byte alignment branch as the 0x686780 family.
// 0x688558 — observed shape
void FUN_00688558(float* out, const float* v, const float* m)
{
    float x = v[0];
    float y = v[1];
    float z = v[2];
    float w = v[3];
    float c0, c1, c2, c3, r0, r1, r2, r3, t0, t1, t2, t3;

    if ((reinterpret_cast<uintptr_t>(m) & 0xf) == 0) {
        c0 = m[0];  c1 = m[1];  c2 = m[2];  c3 = m[3];
        r0 = m[4];  r1 = m[5];  r2 = m[6];  r3 = m[7];
        t0 = m[8] * z + m[12] * w;
        t1 = m[9] * z + m[13] * w;
        t2 = m[10] * z + m[14] * w;
        t3 = m[11] * z + m[15] * w;
    } else {
        c0 = load_f32(m + 0);  c1 = load_f32(m + 1);
        c2 = load_f32(m + 2);  c3 = load_f32(m + 3);
        r0 = load_f32(m + 4);  r1 = load_f32(m + 5);
        r2 = load_f32(m + 6);  r3 = load_f32(m + 7);
        t0 = load_f32(m + 8) * z + load_f32(m + 12) * w;
        t1 = load_f32(m + 9) * z + load_f32(m + 13) * w;
        t2 = load_f32(m + 10) * z + load_f32(m + 14) * w;
        t3 = load_f32(m + 11) * z + load_f32(m + 15) * w;
    }

    out[0] = c0 * x + r0 * y + t0;
    out[1] = c1 * x + r1 * y + t1;
    out[2] = c2 * x + r2 * y + t2;
    out[3] = c3 * x + r3 * y + t3;
}

// ===== 0x688618 =====
// 4x4 row-vector concatenation: out = a * m. The listing walks the source in
// float pairs (one qword per pair) and writes the product as eight qword pairs;
// the flattened layout is float index row*4 + col.
// 0x688618 — observed shape
float* FUN_00688618(float* out, const float* a, const float* m)
{
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            out[row * 4 + col] =
                a[row * 4 + 0] * m[col + 0]  +
                a[row * 4 + 1] * m[col + 4]  +
                a[row * 4 + 2] * m[col + 8]  +
                a[row * 4 + 3] * m[col + 12];
        }
    }
    return out;
}

// ===== 0x68874e =====
// Normalise a 3-component vector. Squared length below the observed threshold
// constant 1.4210855e-14f (2^-46) yields the zero vector; otherwise the scale
// comes from an rsqrtss estimate with one Newton step.
// 0x68874e — observed shape
float* FUN_0068874e(float* out, const float* v)
{
    float x = v[0];
    float y = v[1];
    float z = v[2];
    float len2 = x * x + y * y + z * z;

    if (1.4210855e-14f <= len2) {
        float r = rsqrtss_estimate(len2);
        float inv = (3.0f - r * len2 * r) * r * 0.5f;
        out[0] = x * inv;
        out[1] = y * inv;
        out[2] = z * inv;
    } else {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[2] = 0.0f;
    }
    return out;
}

// ===== 0x6887e2 =====
// 4-component form of 0x68874e: the squared length still uses only x/y/z, but
// the fourth component is scaled by the same inverse and stored separately.
// 0x6887e2 — observed shape
float* FUN_006887e2(float* out, const float* v)
{
    float x = v[0];
    float y = v[1];
    float z = v[2];
    float len2 = x * x + y * y + z * z;

    if (1.4210855e-14f <= len2) {
        float r = rsqrtss_estimate(len2);
        float inv = (3.0f - r * len2 * r) * r * 0.5f;
        float w = v[3];
        out[0] = x * inv;
        out[1] = y * inv;
        out[2] = z * inv;
        out[3] = inv * w;
    } else {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[2] = 0.0f;
        out[3] = 0.0f;
    }
    return out;
}

// ===== 0x6890b4 =====
// Rotation part (rows at stride 4: m[0..2], m[4..6], m[8..10]) to quaternion.
// Positive trace uses the diagonal-3 path; otherwise the largest diagonal
// element is selected, advanced through the 3-entry permutation table
// DAT_006f0b14 for the two off-diagonal lanes, and the quarter-scale factor is
// 0.25/s.
// 0x6890b4 — observed shape
void FUN_006890b4(float* q, const float* m)
{
    float trace = m[5] + m[0] + m[10];

    if (trace <= 0.0f) {
        float diag[3];
        diag[0] = m[0];
        diag[1] = m[5];
        diag[2] = m[10];

        int i = (m[0] < m[5]) ? 1 : 0;
        if (diag[i] < m[10])
            i = 2;

        int n1 = DAT_006f0b14[i];
        int n2 = DAT_006f0b14[n1];

        float s = sqrtf((diag[i] - diag[n1] - diag[n2]) + 1.0f) * 0.5f;
        q[i] = s;

        float inv = 0.25f / s;
        q[n1] = (m[i + n1 * 4] + m[n1 + i * 4]) * inv;
        q[n2] = (m[i + n2 * 4] + m[n2 + i * 4]) * inv;
        q[3]  = (m[n1 * 4 + n2] - m[n2 * 4 + n1]) * inv;
    } else {
        float s = sqrtf(trace + 1.0f) * 0.5f;
        q[3] = s;

        float inv = 0.25f / s;
        q[0] = (m[6] - m[9]) * inv;
        q[1] = (m[8] - m[2]) * inv;
        q[2] = (m[1] - m[4]) * inv;
    }
}
