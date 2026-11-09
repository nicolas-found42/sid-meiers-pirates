// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent; no PASS.
// Sources: analysis/pseudocode/functions/*.c (Ghidra 12.2, PE32 i386).
// Batch mass_0344: 0x6ab570..0x6ac9f0. Decoder/colour-conversion object cluster.
#include <cstdint>
#include <cstddef>

// ---- referenced helpers (declared from the listings only) ----
extern void __cdecl FUN_006ab210(void);                 // stored at +0x1c4[0]
extern void __cdecl FUN_006ab890(void);                 // inline-copy converter
extern void __cdecl FUN_006923f0(int32_t dst_base, int32_t dst_index, int32_t src_base,
                                 int32_t src_index, int32_t rows, uint32_t stride);
extern int32_t __cdecl FUN_006923d0(int32_t a, int32_t b);
extern void __cdecl FUN_006b2350(uint32_t count, int32_t a, int32_t b, int32_t c, int32_t dst);
extern uint8_t LAB_005b6900[];                          // ramp table anchor (data label)

// 0x6ab570 — allocates a 0x54-byte context, then one 0x100-byte table per plane/count.
void __cdecl FUN_006ab570(void* self_raw)
{
    int32_t self = (int32_t)(intptr_t)self_raw;
    // allocator vtable: *(void***)(self+4), slot 0 = alloc(self, 1, size)
    void* ctx = ((void* (__cdecl*)(int32_t, int32_t, int32_t))
                     (*(void***)(self + 4))[0])(self, 1, 0x54);
    int32_t count = *(int32_t*)(self + 0x24);
    int32_t base  = *(int32_t*)(self + 0xdc);
    *(void**)(self + 0x1c4) = ctx;
    *(void**)ctx = (void*)&FUN_006ab210;

    int32_t i = 0;
    if (0 < count) {
        uint32_t* slot_ptr = (uint32_t*)(base + 0x50);          // +0x50 of each 0x54 entry
        uint32_t* ctx_field = (uint32_t*)((int32_t)ctx + 0x2c); // ctx + 0xb dwords
        do {
            uint32_t* table = (uint32_t*)((void* (__cdecl*)(int32_t, int32_t, int32_t))
                                             (*(void***)(self + 4))[0])(self, 1, 0x100);
            *slot_ptr = (uint32_t)(uintptr_t)table;
            for (int32_t n = 0x40; n != 0; --n) {
                *table++ = 0;                    // clear 0x100 bytes
            }
            *ctx_field = 0xffffffffu;
            ++ctx_field;
            ++i;
            slot_ptr += 0x15;                    // 0x54 bytes per entry
        } while (i < *(int32_t*)(self + 0x24));
    }
    return;
}

// 0x6ab600 — bounded two-stage copy: source->temp via +0x1c8, temp->dest via +0x1d0.
void __cdecl FUN_006ab600(int32_t self, uint32_t a2, uint32_t a3, uint32_t a4,
                          int32_t a5, int32_t* a6, int32_t a7)
{
    int32_t* cursor = a6;
    int32_t  src    = *(int32_t*)(self + 0x1b4);
    uint32_t n = (uint32_t)(a7 - *a6);
    if (*(uint32_t*)(src + 0x10) < n) {
        n = *(uint32_t*)(src + 0x10);
    }
    int32_t* stage = (int32_t*)(self + 0x1c8);
    int32_t  produced = 0;
    ((void (__cdecl*)(int32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t*, uint32_t))
         (*(void***)stage)[1])(self, a2, a3, a4, *(uint32_t*)(src + 0xc), &produced, n);
    ((void (__cdecl*)(int32_t, uint32_t, int32_t, int32_t))
         (*(void***)(self + 0x1d0))[1])(self, *(uint32_t*)(src + 0xc),
                                        a5 + *cursor * 4, produced);
    *cursor = *cursor + produced;
    return;
}

// 0x6ab680 — flush/prime hook: emits a fault code when flagged, else installs the copier.
void __cdecl FUN_006ab680(int32_t* self, int32_t flag)
{
    int32_t state = self[0x6d];                  // +0x1b4
    if (flag != 0) {
        uint32_t* vt = (uint32_t*)*self;
        vt[5] = 4;
        ((void (__cdecl*)(int32_t*))(void*)*vt)(self);
        *(uint32_t*)(state + 0x18) = 0;
        *(uint32_t*)(state + 0x14) = 0;
        return;
    }
    if (self[0x15] == 0) {                       // +0x54
        *(uint32_t*)(state + 4) = *(uint32_t*)(self[0x72] + 4);
    } else {
        *(void**)(state + 4) = (void*)&FUN_006ab600;
        if (*(int32_t*)(state + 0xc) == 0) {
            uint32_t bufp = ((uint32_t (__cdecl*)(int32_t*, uint32_t, int32_t, uint32_t, int32_t))
                                 (*(void***)(self[1]))[7])(self,
                                                             *(uint32_t*)(state + 8), 0,
                                                             *(uint32_t*)(state + 0x10), 1);
            *(uint32_t*)(state + 0x18) = 0;
            *(uint32_t*)(state + 0x14) = 0;
            *(uint32_t*)(state + 0xc) = bufp;
            return;
        }
    }
    *(uint32_t*)(state + 0x18) = 0;
    *(uint32_t*)(state + 0x14) = 0;
    return;
}

// 0x6ab700 — allocates the 0x1c-byte state block and optionally its plane buffers.
void __cdecl FUN_006ab700(int32_t* self, int32_t flag)
{
    uint32_t* state = (uint32_t*)((void* (__cdecl*)(int32_t*, int32_t, int32_t))
                                      (*(void***)self[1])[0])(self, 1, 0x1c);
    int32_t present = self[0x15];
    self[0x6d] = (int32_t)(uintptr_t)state;
    state[0] = (uint32_t)(uintptr_t)&FUN_006ab680;
    state[2] = 0;
    state[3] = 0;
    if (present != 0) {
        int32_t stride = self[0x4f];
        state[4] = (uint32_t)stride;
        if (flag != 0) {
            uint32_t* vt = (uint32_t*)*self;
            vt[5] = 4;
            ((void (__cdecl*)(int32_t*))(void*)*vt)(self);
            return;
        }
        uint32_t buf = ((uint32_t (__cdecl*)(int32_t*, int32_t, int32_t, int32_t))
                            (*(void***)(self[1]))[2])(self, 1, self[0x1e] * self[0x1c], stride);
        state[3] = buf;
    }
    return;
}

// 0x6ab770 — vtable slot 0 of the +0x1c8 object: latches width/height.
void __cdecl FUN_006ab770(int32_t self)
{
    int32_t ctx = *(int32_t*)(self + 0x1c8);
    uint32_t h  = *(uint32_t*)(self + 0x74);
    *(uint32_t*)(ctx + 0x5c) = *(uint32_t*)(self + 0x13c);
    *(uint32_t*)(ctx + 0x60) = h;
    return;
}

// 0x6ab7a0 — vtable slot 1 of +0x1c8: per-plane emit, then bounded bulk copy via +0x1cc.
void __cdecl FUN_006ab7a0(int32_t self, int32_t a2, int32_t* a3, int32_t a4,
                          int32_t a5, int32_t* a6, int32_t a7)
{
    int32_t ctx = *(int32_t*)(self + 0x1c8);
    if (*(int32_t*)(self + 0x13c) <= *(int32_t*)(ctx + 0x5c)) {
        int32_t plane = 0;
        int32_t row   = *(int32_t*)(self + 0xdc);
        int32_t count = *(int32_t*)(self + 0x24);
        if (0 < count) {
            int32_t entry = ctx + 0xc;
            do {
                // per-plane function pointer at entry+0x28(self, row, a2[plane] + entry[0x58]* *a3 *4, entry)
                ((void (__cdecl*)(int32_t, int32_t, int32_t, int32_t))
                     *(void**)(entry + 0x28))(self, row,
                                              *(int32_t*)(a2 + plane * 4) +
                                                  *(int32_t*)(entry + 0x58) * *a3 * 4,
                                              entry);
                ++plane;
                row += 0x54;
                entry += 4;
            } while (plane < *(int32_t*)(self + 0x24));
        }
        *(uint32_t*)(ctx + 0x5c) = 0;
    }

    uint32_t avail = (uint32_t)(*(int32_t*)(self + 0x13c) - *(int32_t*)(ctx + 0x5c));
    if (*(uint32_t*)(ctx + 0x60) < avail) {
        avail = *(uint32_t*)(ctx + 0x60);
    }
    uint32_t room = (uint32_t)(a7 - *a6);
    if (room < avail) {
        avail = room;
    }
    ((void (__cdecl*)(int32_t, int32_t, uint32_t, int32_t, uint32_t))
         (*(void***)(self + 0x1cc))[1])(self, ctx + 0xc,
                                        *(uint32_t*)(ctx + 0x5c),
                                        a5 + *a6 * 4, avail);
    int32_t remaining = *(int32_t*)(ctx + 0x60);
    *a6 += (int32_t)avail;
    int32_t total = *(int32_t*)(self + 0x13c);
    int32_t pos = *(int32_t*)(ctx + 0x5c) + (int32_t)avail;
    *(uint32_t*)(ctx + 0x60) = (uint32_t)(remaining - (int32_t)avail);
    *(int32_t*)(ctx + 0x5c) = pos;
    if (total <= pos) {
        ++*a3;
    }
    return;
}

// 0x6ab8b0 — truncating converter: writes a zero pixel count through the stack slot at +0x10.
// NEEDS_MANUAL: listing declares void(void); the only observed operation targets the 4th
// stack argument (provider recovery lost the parameter list).
void __cdecl FUN_006ab8b0(int32_t self, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t* out)
{
    (void)self; (void)a2; (void)a3; (void)a4;
    *out = 0;
    return;
}

// 0x6ab8d0 — horizontal/vertical pixel duplication using the +0x8c copy width and +0x96 step.
void __cdecl FUN_006ab8d0(int32_t self, int32_t a2, uint32_t* a3, int32_t* a4)
{
    int32_t dst_rows = *a4;
    int32_t entry    = *(int32_t*)(self + 0x1c8) + *(int32_t*)(a2 + 4);
    uint8_t xstep    = *(uint8_t*)(entry + 0x8c);
    uint32_t ystep   = (uint32_t)*(uint8_t*)(entry + 0x96);
    uint32_t width   = (uint32_t)xstep;

    int32_t col = 0;
    if (0 < *(int32_t*)(self + 0x13c)) {
        uint32_t** srcp = a3;
        do {
            uint8_t* src = (uint8_t*)*srcp;
            uint32_t* dst = *(uint32_t**)(dst_rows + col * 4);
            uint32_t* end = (uint32_t*)(*(int32_t*)(self + 0x70) + (int32_t)dst);
            while (dst < end) {
                uint8_t value = *src++;
                if (width != 0) {
                    // dword-wide fill of `width` identical bytes, then advance `width`
                    uint32_t* p = dst;
                    for (uint32_t n = width >> 2; n != 0; --n) {
                        *p++ = ((uint32_t)value << 24) | ((uint32_t)value << 16) |
                               ((uint32_t)value << 8) | value;
                    }
                    for (uint32_t n = width & 3; n != 0; --n) {
                        *(uint8_t*)p = value;
                        p = (uint32_t*)((int32_t)p + 1);
                    }
                    dst = (uint32_t*)((int32_t)dst + width);
                }
            }
            if (1 < ystep) {
                FUN_006923f0(dst_rows, col, dst_rows, col + 1,
                             (int32_t)(ystep - 1), *(uint32_t*)(self + 0x70));
            }
            col += (int32_t)ystep;
            ++srcp;
        } while (col < *(int32_t*)(self + 0x13c));
    }
    return;
}

// 0x6ab9c0 — 1x2 horizontal expansion: each source byte becomes two identical bytes.
void __cdecl FUN_006ab9c0(int32_t self, int32_t a2, int32_t a3, uint32_t* a4)
{
    (void)a2;
    uint32_t* rows = a4;
    int32_t count  = *(int32_t*)(self + 0x13c);
    if (0 < count) {
        int32_t stride = *(int32_t*)(self + 0x70);
        int32_t src_delta = a3 - (int32_t)rows;
        do {
            uint8_t* dst = (uint8_t*)*rows;
            uint8_t* src = (uint8_t*)*(uint32_t*)(src_delta + (int32_t)rows);
            uint8_t* end = dst + stride;
            for (; dst < end; dst += 2) {
                uint8_t v = *src++;
                *dst = v;
                dst[1] = v;
            }
            ++rows;
            --count;
        } while (count != 0);
    }
    return;
}

// 0x6aba20 — 2x2 vertical/horizontal expansion: one source byte per two dest rows, fed by +0x923f0.
void __cdecl FUN_006aba20(int32_t self, int32_t a2, uint32_t* a3, int32_t* a4)
{
    (void)a2;
    int32_t dst_rows = *a4;
    int32_t i = 0;
    if (0 < *(int32_t*)(self + 0x13c)) {
        uint32_t** srcp = a3;
        do {
            uint8_t* src = (uint8_t*)*srcp;
            uint8_t* dst = *(uint8_t**)(dst_rows + i * 4);
            uint8_t* end = dst + *(int32_t*)(self + 0x70);
            for (; dst < end; dst += 2) {
                uint8_t v = *src++;
                *dst = v;
                dst[1] = v;
            }
            FUN_006923f0(dst_rows, i, dst_rows, i + 1, 1, *(uint32_t*)(self + 0x70));
            ++srcp;
            i += 2;
        } while (i < *(int32_t*)(self + 0x13c));
    }
    return;
}

// 0x6abaa0 — 2x horizontal chroma upsample: out[2i] = (s[i-1] + 1 + 3*s[i]) >> 2 style pairs.
// Receiver arrives in ECX, the row-pointer array in EAX, the plane context in EDX.
void __cdecl FUN_006abaa0(int32_t self, int32_t ctx, uint32_t* out_rows, uint32_t* in_rows)
{
    int32_t count = *(int32_t*)(self + 0x13c);
    if (0 < count) {
        int32_t width = *(int32_t*)(ctx + 0x28);
        int32_t k = 0;
        do {
            uint8_t* src = (uint8_t*)in_rows[k];
            uint8_t* dst = (uint8_t*)out_rows[k];
            uint8_t  b0   = src[0];
            uint32_t prev = src[1];

            dst[0] = b0;
            dst[1] = (uint8_t)(((uint32_t)b0 * 3 + 2 + prev) >> 2);
            ++src;
            dst += 2;

            for (int32_t n = width - 2; n != 0; --n) {
                uint32_t cur = prev * 3;
                prev = src[1];
                dst[0] = (uint8_t)(((uint32_t)src[-1] + 1 + cur) >> 2);
                dst[1] = (uint8_t)((prev + 2 + cur) >> 2);
                ++src;
                dst += 2;
            }

            uint8_t last = *src;
            dst[0] = (uint8_t)(((uint32_t)src[-1] + 1 + (uint32_t)last * 3) >> 2);
            dst[1] = last;
            ++k;
            --count;
        } while (count != 0);
    }
    return;
}

// 0x6abb60 — 1:1 horizontal 3:1 resample, 8 samples per 64-bit word with a one-sample look-ahead.
// NEEDS_MANUAL: Ghidra emits packed 16-bit CONCAT/carry chains per lane; the per-byte blends
// below reproduce the observed coefficient pattern (3/1, alternating with +2/+1 rounding).
namespace {
inline uint64_t blend_word_1to1(const uint8_t* s, uint8_t lookahead)
{
    const uint8_t s0 = s[0], s1 = s[1], s2 = s[2], s3 = s[3];
    uint64_t w = 0;
    const uint8_t out[8] = {
        s0,
        (uint8_t)((3u * s0 + s1 + 2u) >> 2),
        (uint8_t)((s0 + 3u * s1 + 1u) >> 2),
        (uint8_t)((3u * s1 + s2 + 2u) >> 2),
        (uint8_t)((s1 + 3u * s2 + 1u) >> 2),
        (uint8_t)((3u * s2 + s3 + 2u) >> 2),
        (uint8_t)((s2 + 3u * s3 + 1u) >> 2),
        (uint8_t)((3u * s3 + lookahead + 2u) >> 2),
    };
    for (int i = 0; i < 8; ++i) {
        w |= (uint64_t)out[i] << (8 * i);
    }
    return w;
}
} // namespace

// Call-site form (0x6ac4f0/0x6ac570): FUN_006abb60(self, src_rows) with the destination
// row-pointer array supplied in EAX; both are modelled here as explicit parameters.
void __cdecl FUN_006abb60(int32_t self, uint32_t* src_rows, uint32_t** dst_handle)
{
    int32_t  stride   = *(int32_t*)(self + 0x28);
    uint32_t* dst_rows = *dst_handle;
    int32_t n = 0;
    if (0 < *(int32_t*)(self + 0x13c)) {
        do {
            uint8_t*  src = (uint8_t*)src_rows[n];
            uint64_t* dst = (uint64_t*)dst_rows[n];
            const int32_t words = stride >> 3;
            for (int32_t w = 0; w < words; ++w) {
                dst[w] = blend_word_1to1(src + w * 8, src[w * 8 + 8]);
            }
            ++n;
        } while (n < *(int32_t*)(self + 0x13c));
    }
    return;
}

// 0x6abdf0 — 2x vertical + 2x horizontal upsample between neighbouring source rows.
// Register model: EAX -> destination row-pointer array, EDX -> plane context, ESI/EDI free.
// For each source row two destination rows are emitted: one blended with param_2[-1], one
// with param_2[1]; blends use (3*cur + 1*nbr) with >>4 and +8/+7 rounding.
void __cdecl FUN_006abdf0(int32_t ctx, uint32_t** src_rows, uint32_t** dst_handle)
{
    int32_t base = (int32_t)(intptr_t)*dst_handle;
    int32_t rows = *(int32_t*)(ctx + 0x13c);
    int32_t dst_index = 0;
    if (0 < rows) {
        int32_t last_pair = *(int32_t*)(ctx + 0x28) - 2;   // width - 2
        do {
            const uint8_t* cur = (const uint8_t*)src_rows[0];
            int32_t half = 0;
            do {
                // half 0 blends against the preceding row, half 1 against the following row
                const uint8_t* nbr = (half == 0) ? (const uint8_t*)src_rows[-1]
                                                 : (const uint8_t*)src_rows[1];
                uint8_t* dst = *(uint8_t**)(base + dst_index * 4);
                ++dst_index;

                int32_t a = (int32_t)cur[0] * 3 + (int32_t)nbr[0];
                int32_t b = (int32_t)cur[1] * 3 + (int32_t)nbr[1];
                dst[0] = (uint8_t)((a * 4 + 8) >> 4);
                dst[1] = (uint8_t)((a * 3 + 7 + b) >> 4);
                dst += 2;
                nbr += 2;
                const uint8_t* src2 = cur + 2;

                if (last_pair != 0) {
                    int32_t n = last_pair;
                    int32_t prev = b;
                    do {
                        int32_t next = (int32_t)src2[0] * 3 + (int32_t)nbr[0];
                        dst[0] = (uint8_t)((prev * 3 + 8 + a) >> 4);
                        ++nbr;
                        ++src2;
                        a = prev;
                        dst[1] = (uint8_t)((prev * 3 + 7 + next) >> 4);
                        dst += 2;
                        --n;
                        prev = next;
                    } while (n != 0);
                }
                dst[0] = (uint8_t)((b * 3 + 8 + a) >> 4);
                dst[1] = (uint8_t)((b * 4 + 7) >> 4);
                ++half;
            } while (half < 2);
            ++src_rows;
        } while (dst_index < rows);
    }
    return;
}

// 0x6abf20 — 2x2 upsample emitting two destination rows per source row (prev/cur, then cur/next).
// NEEDS_MANUAL: the provider expands the filter as packed 16-bit CONCAT chains; the loop,
// offsets and 3/9-vs-3/1 coefficient split with +7/+8 and >>4 rounding are preserved, exact
// per-lane constants are not recoverable from the CONCAT form.
namespace {
inline uint8_t blend4(uint32_t v3, uint32_t v9, uint32_t hA, uint32_t hB, uint32_t round)
{
    return (uint8_t)((v3 + v9 + hA + hB + round) >> 4);
}
} // namespace

void __cdecl FUN_006abf20(int32_t self, int32_t ctx, uint32_t** src_rows, uint32_t** dst_handle)
{
    int32_t base = (int32_t)(intptr_t)*dst_handle;
    int32_t width = *(int32_t*)(ctx + 0x28);
    int32_t row_pair = 0;
    if (0 < *(int32_t*)(self + 0x13c)) {
        uint32_t** rows = src_rows;
        do {
            const uint8_t* prev = (const uint8_t*)rows[-1];
            const uint8_t* cur  = (const uint8_t*)rows[0];
            const uint8_t* next = (const uint8_t*)rows[1];
            uint8_t* top = *(uint8_t**)(base + row_pair * 4);          // (prev, cur)
            uint8_t* bot = *(uint8_t**)(base + (row_pair + 1) * 4);    // (cur, next)
            row_pair += 2;

            for (int32_t i = 0; i < width; ++i) {
                uint32_t v3 = (uint32_t)prev[i] * 3;
                uint32_t v9 = (uint32_t)cur[i] * 9;
                uint32_t um = (uint32_t)cur[i] * 9;
                uint32_t un = (uint32_t)next[i] * 3;
                uint32_t hcur = (i + 1 < width) ? (uint32_t)cur[i + 1] : (uint32_t)cur[i];
                uint32_t hnext = (i + 1 < width) ? (uint32_t)next[i + 1] : (uint32_t)next[i];
                top[2 * i]     = blend4(v3, v9, hcur, hcur * 3, 8);
                top[2 * i + 1] = blend4(v3, v9, hcur * 3, hcur, 7);
                bot[2 * i]     = blend4(um, un, hnext, hnext * 3, 8);
                bot[2 * i + 1] = blend4(um, un, hnext * 3, hnext, 7);
            }
            ++rows;
        } while (row_pair < *(int32_t*)(self + 0x13c));
    }
    return;
}

// 0x6ac4f0 — side-effect-free fast path: rejects odd-aligned plane pointers, then picks the
// packed 1:1 resampler for YUV formats 5/6, else the generic 2x converter.
void __cdecl FUN_006ac4f0(int32_t self, int32_t ctx, uint32_t** dst_handle, uint32_t* rows)
{
    if (0x10 < *(uint32_t*)(ctx + 0x28)) {
        int32_t i = 0;
        if (0 < *(int32_t*)(self + 0x4f * 4)) {
            do {
                if ((*(uint8_t*)(rows + i) & 7) != 0) {
                    uint32_t* vt = (uint32_t*)*(uint32_t*)self;
                    vt[5] = 2;
                    ((void (__cdecl*)(int32_t, int32_t))(void*)*vt)(self, -1);
                    break;
                }
                ++i;
            } while (i < *(int32_t*)(self + 0x4f * 4));
        }
        if (i == *(int32_t*)(self + 0x4f * 4) &&
            (*(int32_t*)(self + 0x12 * 4) == 5 || *(int32_t*)(self + 0x12 * 4) == 6)) {
            FUN_006abb60(self, rows, dst_handle);
            return;
        }
    }
    FUN_006abaa0(self, ctx, dst_handle, rows);
    return;
}

// 0x6ac570 — mirror of 0x6ac4f0 selecting the two-row 2x2 resampler (0x6abf20).
void __cdecl FUN_006ac570(int32_t self, int32_t ctx, uint32_t** dst_handle, uint32_t* rows)
{
    if (0x10 < *(uint32_t*)(ctx + 0x28)) {
        int32_t i = 0;
        if (0 < *(int32_t*)(self + 0x4f * 4)) {
            do {
                if ((*(uint8_t*)(rows + i) & 7) != 0) {
                    uint32_t* vt = (uint32_t*)*(uint32_t*)self;
                    vt[5] = 2;
                    ((void (__cdecl*)(int32_t, int32_t))(void*)*vt)(self, -1);
                    break;
                }
                ++i;
            } while (i < *(int32_t*)(self + 0x4f * 4));
        }
        if (i == *(int32_t*)(self + 0x4f * 4) &&
            (*(int32_t*)(self + 0x12 * 4) == 5 || *(int32_t*)(self + 0x12 * 4) == 6)) {
            FUN_006abf20(self, ctx, (uint32_t**)rows, dst_handle);
            return;
        }
    }
    FUN_006abdf0(ctx, (uint32_t**)rows, dst_handle);
    return;
}

// 0x6ac5f0 — allocates the 0xa0-byte scaler and installs per-plane conversion entry points.
void __cdecl FUN_006ac5f0(int32_t* self)
{
    uint32_t* vt = (uint32_t*)((void* (__cdecl*)(int32_t*, int32_t, int32_t))
                                   (*(void***)self[1])[0])(self, 1, 0xa0);
    int32_t mode = self[0x4c];
    self[0x72] = (int32_t)(uintptr_t)vt;
    vt[0] = (uint32_t)(uintptr_t)&FUN_006ab770;
    vt[1] = (uint32_t)(uintptr_t)&FUN_006ab7a0;
    vt[2] = 0;
    if (mode != 0) {
        uint32_t* outer = (uint32_t*)*self;
        outer[5] = 0x19;
        ((void (__cdecl*)(int32_t*))(void*)*outer)(self);
    }

    bool wide = (self[0x13] != 0) && (self[0x50] >= 2);

    int32_t plane = 0;
    if (self[9] < 1) {
        return;
    }
    int32_t* entry = (int32_t*)(self[0x37] + 0x24);
    uint32_t* slot = vt + 0xd;
    do {
        int32_t scaled_w = (entry[-7] * *entry) / self[0x50];
        int32_t scaled_h = (entry[-6] * *entry) / self[0x50];
        int32_t kind     = entry[3];
        int32_t full_w   = self[0x4f];
        int32_t full_h   = self[0x4e];
        slot[0xc] = (uint32_t)scaled_h;

        if (kind == 0) {
            slot[0] = (uint32_t)(uintptr_t)&FUN_006ab8b0;
        } else if (scaled_w == full_h && scaled_h == full_w) {
            slot[0] = (uint32_t)(uintptr_t)&FUN_006ab890;
        } else {
            bool picked = true;
            if (scaled_w * 2 == full_h) {
                if (scaled_h == full_w) {
                    if (!wide || (uint32_t)entry[1] < 3) {
                        slot[0] = (uint32_t)(uintptr_t)&FUN_006ab9c0;
                    } else {
                        slot[0] = (uint32_t)(uintptr_t)&FUN_006ac4f0;
                    }
                } else {
                    if ((scaled_w * 2 != full_h) || (scaled_h * 2 != full_w)) {
                        picked = false;                 // -> LAB_006ac743
                    } else if (!wide || (uint32_t)entry[1] < 3) {
                        slot[0] = (uint32_t)(uintptr_t)&FUN_006aba20;
                    } else {
                        slot[0] = (uint32_t)(uintptr_t)&FUN_006ac570;
                        vt[2] = 1;
                    }
                }
            } else {
                picked = false;
            }

            if (!picked) {
                if ((full_h % scaled_w == 0) && (full_w % scaled_h == 0)) {
                    int32_t xstep = full_h / scaled_w;
                    slot[0] = (uint32_t)(uintptr_t)&FUN_006ab8d0;
                    *(uint8_t*)((int32_t)vt + 0x8c) = (uint8_t)xstep;
                    *(int8_t*)((int32_t)vt + 0x96) = (int8_t)(full_w / scaled_h);
                } else {
                    uint32_t* outer = (uint32_t*)*self;
                    outer[5] = 0x26;
                    ((void (__cdecl*)(int32_t*))(void*)*outer)(self);
                }
            }

            int32_t plane_stride = self[0x4f] * ((vt[2] == 1 ? 1 : 0) * 2 + 1);
            uint32_t bytes = (uint32_t)FUN_006923d0(self[0x1c], self[0x4e]);
            uint32_t buf = ((uint32_t (__cdecl*)(int32_t*, int32_t, uint32_t, int32_t))
                                (*(void***)self[1])[2])(self, 1, bytes, plane_stride);
            slot[-10] = buf;
        }

        ++plane;
        entry += 0x15;
        ++slot;
        if (self[9] <= plane) {
            return;
        }
    } while (true);
}

// 0x6ac7f0 — builds the four colour-table buffers of the +0x1cc block with linear ramps;
// table C receives a descending sequence of 16-bit table pointers (LAB_005b6900 - n*0xb6d2).
void __cdecl FUN_006ac7f0(int32_t self)
{
    typedef void* (__cdecl* AllocFn)(void);
    int32_t block = *(int32_t*)(self + 0x1cc);

    *(uint32_t*)(block + 8)    = ((AllocFn)(*(void***)(self + 4))[0])();
    *(uint32_t*)(block + 0xc)  = ((AllocFn)(*(void***)(self + 4))[0])();
    uint32_t third_buf         = ((AllocFn)(*(void***)(self + 4))[0])();
    *(uint32_t*)(block + 0x10) = third_buf;
    int32_t  fourth_buf        = (int32_t)(intptr_t)((AllocFn)(*(void***)(self + 4))[0])();
    *(int32_t*)(block + 0x14)  = fourth_buf;

    int32_t* base = *(int32_t**)(block + 0xc);
    int32_t  d_third  = (int32_t)third_buf - (int32_t)base;      // third table offset
    int32_t  d_first  = *(int32_t*)(block + 8) - (int32_t)base;  // first table offset
    int32_t  d_fourth = fourth_buf - (int32_t)base;              // fourth table offset

    const void* seq = (const void*)LAB_005b6900;
    int32_t v_first  = -0xe25100;
    int32_t v_second = -0xb2f480;
    int32_t v_fourth = 0x2c8d00;

    do {
        *(int32_t*)(d_first + (int32_t)base)  = v_second >> 0x10;
        *base                                 = v_first >> 0x10;
        *(const void**)(d_third + (int32_t)base) = seq;
        *(int32_t*)(d_fourth + (int32_t)base) = v_fourth;
        seq = (const uint8_t*)seq - 0xb6d2;
        v_fourth += -0x581a;
        v_second += 0x166e9;
        v_first  += 0x1c5a2;
        ++base;
    } while (-0x2b34e7 < v_fourth);
    return;
}

// 0x6ac8d0 — planar YUV->BGR: three table lookups per pixel (block+8/+0xc/+0x10/+0x14) added to
// the Y sample and the +0x148 palette offset. rows[0]/rows[2] supply chroma, rows[1] luma.
void __cdecl FUN_006ac8d0(int32_t self, int32_t* rows, int32_t row_offset,
                          uint32_t* dst_rows, int32_t height)
{
    int32_t  width  = *(int32_t*)(self + 0x70);
    int32_t  block  = *(int32_t*)(self + 0x1cc);
    int32_t  pal    = *(int32_t*)(self + 0x148);
    int32_t  tab0   = *(int32_t*)(block + 8);
    int32_t  tab1   = *(int32_t*)(block + 0xc);
    int32_t  tab2   = *(int32_t*)(block + 0x10);
    int32_t  tab3   = *(int32_t*)(block + 0x14);

    if (-1 < height - 1) {
        int32_t chroma0 = rows[0];
        int32_t luma    = rows[1];
        int32_t chroma2 = rows[2];
        int32_t* cursor = (int32_t*)(luma + row_offset * 4);
        do {
            int32_t* v0_ptr = (int32_t*)((chroma0 - luma) + (int32_t)cursor);
            int32_t* v2_ptr = (int32_t*)((chroma2 - luma) + (int32_t)cursor);
            uint8_t* u_row  = (uint8_t*)*cursor;
            uint8_t* dst    = (uint8_t*)*dst_rows;
            ++dst_rows;
            ++cursor;
            if (width != 0) {
                int32_t v0_ofs = *v0_ptr - (int32_t)u_row;
                int32_t v2_ofs = *v2_ptr - (int32_t)u_row;
                int32_t n = width;
                do {
                    uint8_t v2 = u_row[v2_ofs];
                    uint32_t y = (uint32_t)u_row[v0_ofs];
                    dst[0] = *(uint8_t*)(*(int32_t*)(tab0 + (uint32_t)v2 * 4) + y + pal);
                    uint8_t u = *u_row;
                    dst[1] = *(uint8_t*)((*(int32_t*)(tab3 + (uint32_t)u * 4) +
                                          *(int32_t*)(tab2 + (uint32_t)v2 * 4) >> 0x10) +
                                         y + pal);
                    dst[2] = *(uint8_t*)(*(int32_t*)(tab1 + (uint32_t)u * 4) + y + pal);
                    dst += 3;
                    ++u_row;
                    --n;
                } while (n != 0);
            }
            --height;
        } while (height != 0);
    }
    return;
}

// 0x6ac9f0 — same conversion as 0x6ac8d0 but the multiple-of-eight prefix is handed to the
// vector kernel (FUN_006b2350); the tail is converted with the scalar table path.
void __cdecl FUN_006ac9f0(int32_t self, int32_t* rows, int32_t row_offset,
                          int32_t* dst_rows, int32_t height)
{
    int32_t block  = *(int32_t*)(self + 0x1cc);
    int32_t tab1   = *(int32_t*)(block + 0xc);
    int32_t pal    = *(int32_t*)(self + 0x148);
    uint32_t width = *(uint32_t*)(self + 0x70);
    int32_t tab0   = *(int32_t*)(block + 8);
    int32_t tab2   = *(int32_t*)(block + 0x10);
    int32_t tab3   = *(int32_t*)(block + 0x14);
    uint32_t vec_width = width & 0xfffffff8u;

    if (-1 < height - 1) {
        row_offset <<= 2;
        int32_t remaining_rows = height;
        do {
            int32_t v0_row = *(int32_t*)(row_offset + *rows);
            int32_t v2_row = *(int32_t*)(row_offset + rows[2]);
            int32_t u_row  = *(int32_t*)(row_offset + rows[1]);
            int32_t dst    = *dst_rows;
            row_offset += 4;
            ++dst_rows;

            if (vec_width != 0) {
                FUN_006b2350(vec_width, v0_row, u_row, v2_row, dst);
            }

            uint8_t* out = (uint8_t*)(dst + vec_width * 3);
            if (vec_width < width) {
                uint8_t* u = (uint8_t*)(u_row + vec_width);
                int32_t n = (int32_t)(width - vec_width);
                do {
                    uint8_t v2 = u[v2_row - u_row];
                    uint32_t y = (uint32_t)u[v0_row - u_row];
                    out[0] = *(uint8_t*)(*(int32_t*)(tab0 + (uint32_t)v2 * 4) + y + pal);
                    out[1] = *(uint8_t*)((*(int32_t*)(tab3 + (uint32_t)*u * 4) +
                                          *(int32_t*)(tab2 + (uint32_t)v2 * 4) >> 0x10) +
                                         y + pal);
                    out[2] = *(uint8_t*)(*(int32_t*)(tab1 + (uint32_t)*u * 4) + y + pal);
                    out += 3;
                    ++u;
                    --n;
                } while (n != 0);
            }
            --remaining_rows;
        } while (remaining_rows != 0);
    }
    return;
}
