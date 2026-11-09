// Sid Meier's Pirates! (2004) — reconstruction batch mass_0271
// Provider: Ghidra 12.2 pseudocode; PE32 i386 image
//   6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
// Candidates only; provider pseudocode is not original source.

#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>
#include <new>

// ---------------------------------------------------------------- helpers ---
extern "C" {
void FUN_006015d0(void *pixels);                       // transform hook
void FUN_0060183d(void *pixels);                       // pack hook
void FUN_006011da(void *desc, int a, int b);           // base surface init
void *FUN_00533c78(int bytes);                         // allocate
void FUN_004127b0(void *mem, int elem, int count, void *ctor);
void FUN_0060064e(void);                               // base surface destroy
void FUN_0060010b(void);                               // base surface release
void *FUN_00600136(void *pixels);
void *FUN_0060164a(void *pixels);
int  FUN_00600951(int x, int y, int clip);
void FUN_00600fd8(void);                               // complete destructor
void FUN_005f6015(void);
void FUN_005f7ad0(uint32_t *stream, uint32_t fourcc, int *out, int flags);
int  FUN_00601429(void *desc);
float __cdecl FUN_005f465d(void);                      // float dot helper
}

// Surface constructors reached from the descriptor factory (0x60a6fc).
extern "C" {
void *FUN_00605f03(void *self, void *p); void *FUN_00605f24(void *self, void *p); void *FUN_00605f45(void *self, void *p);
void *FUN_00606281(void *self, void *p); void *FUN_006062a2(void *self, void *p); void *FUN_006062c3(void *self, void *p);
void *FUN_006062e4(void *self, void *p); void *FUN_00606305(void *self, void *p); void *FUN_00606326(void *self, void *p);
void *FUN_00606347(void *self, void *p); void *FUN_00606368(void *self, void *p); void *FUN_006066a2(void *self, void *p);
void *FUN_006066c3(void *self, void *p); void *FUN_006066e4(void *self, void *p); void *FUN_00606705(void *self, void *p);
void *FUN_00606726(void *self, void *p); void *FUN_00606747(void *self, void *p); void *FUN_00606768(void *self, void *p);
void *FUN_00606b35(void *self, void *p); void *FUN_00606b56(void *self, void *p); void *FUN_00606b77(void *self, void *p);
void *FUN_00606b98(void *self, void *p); void *FUN_00606bb9(void *self, void *p); void *FUN_00606bda(void *self, void *p);
void *FUN_00606bfb(void *self, void *p); void *FUN_00606e93(void *self, void *p); void *FUN_00606eb4(void *self, void *p);
void *FUN_00606ed5(void *self, void *p); void *FUN_00606ef6(void *self, void *p); void *FUN_00606f38(void *self, void *p);
void *FUN_00607333(void *self, void *p); void *FUN_00607354(void *self, void *p); void *FUN_00607375(void *self, void *p);
void *FUN_00607396(void *self, void *p); void *FUN_006073b7(void *self, void *p); void *FUN_006073d8(void *self, void *p);
void *FUN_006073f9(void *self, void *p); void *FUN_006077f2(void *self, void *p); void *FUN_00607813(void *self, void *p);

// DXT block decode/encode callbacks installed by 0x609dec.
void FUN_00659f48(void); void FUN_0065a08a(void); void FUN_0065a10f(void);
void FUN_0065a24d(void); void FUN_0065a371(void); void FUN_0065a4a0(void);
void FUN_0065a974(void); void FUN_0065a99a(void); void FUN_0065a9c0(void);
void FUN_0065a9f9(void);
}

// vtable pointers observed in the listings
extern void *PTR_FUN_006de0c8;
extern void *PTR_FUN_006de0d8;

// ---------------------------------------------------------- surface bases ---
// 0x609a45 — observed shape: pixel fetch with pitch stride, dword copy of
// (width & 0xfffffff) << 2, optional transform then pack hooks.
void FUN_00609a45(void *self, int param_1, int param_2, uint32_t *param_3)
{
    auto *s = static_cast<uint8_t *>(self);
    int stride_x = *reinterpret_cast<int *>(s + 0x60);
    int stride_y = *reinterpret_cast<int *>(s + 0x64);
    uint32_t base = *reinterpret_cast<uint32_t *>(s + 0x20);

    uint32_t *src = reinterpret_cast<uint32_t *>(
        stride_x * param_1 + stride_y * param_2 + base);
    uint32_t *dst = param_3;

    for (int n = (*reinterpret_cast<uint32_t *>(s + 0x68) & 0x0fffffff) << 2; n != 0; n--)
        *dst++ = *src++;
    for (int n = 0; n != 0; n--) {
        *reinterpret_cast<uint8_t *>(dst) = *reinterpret_cast<uint8_t *>(src);
        src = reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(src) + 1);
        dst = reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(dst) + 1);
    }
    if (*reinterpret_cast<int *>(s + 0x18) != 0)
        FUN_006015d0(param_3);
    if (*reinterpret_cast<int *>(s + 0x10) != 0)
        FUN_0060183d(param_3);
}

// 0x609aa0 — observed shape: 16-bit packed pixel expansion to normalized
// floats (x 1.5259022e-05 = 1/65535), four floats per texel.
void FUN_00609aa0(void *self, int param_1, int param_2, float *param_3)
{
    auto *s = static_cast<uint8_t *>(self);
    int stride_x = *reinterpret_cast<int *>(s + 0x60);
    int stride_y = *reinterpret_cast<int *>(s + 0x64);
    uint32_t base = *reinterpret_cast<uint32_t *>(s + 0x20);

    uint32_t *src = reinterpret_cast<uint32_t *>(
        stride_x * param_1 + stride_y * param_2 + base);
    uint32_t *end = src + *reinterpret_cast<int *>(s + 0x68);
    float *out = param_3;
    float *tail = param_3;
    if (src < end) {
        do {
            float f = static_cast<float>(*src & 0xffff) * 1.5259022e-05f;
            uint32_t *next = src + 1;
            out[2] = f;
            out[1] = f;
            *out = f;
            tail = out + 4;
            out[3] = static_cast<float>(*reinterpret_cast<uint16_t *>(
                         reinterpret_cast<uint8_t *>(src) + 2)) * 1.5259022e-05f;
            src = next;
            out = tail;
        } while (src < end);
    }
    if (*reinterpret_cast<int *>(s + 0x18) != 0)
        FUN_006015d0(tail + *reinterpret_cast<int *>(s + 0x68) * -4);
    if (*reinterpret_cast<int *>(s + 0x10) != 0)
        FUN_0060183d(tail + *reinterpret_cast<int *>(s + 0x68) * -4);
}

// 0x609b3a — observed shape: 3x16-bit RGB source expanded to RGBA floats,
// alpha forced to 1.0, stride from field 0x74.
void FUN_00609b3a(void *self, int param_1, int param_2, float *param_3)
{
    auto *s = static_cast<uint8_t *>(self);
    int stride_x = *reinterpret_cast<int *>(s + 0x60);
    int stride_y = *reinterpret_cast<int *>(s + 0x64);
    uint32_t base = *reinterpret_cast<uint32_t *>(s + 0x20);

    uint16_t *src = reinterpret_cast<uint16_t *>(
        stride_x * param_1 + stride_y * param_2 + base);
    uint16_t *end = reinterpret_cast<uint16_t *>(
        *reinterpret_cast<int *>(s + 0x74) + reinterpret_cast<intptr_t>(src));
    float *out = param_3;
    float *tail = param_3;
    if (src < end) {
        do {
            *out = static_cast<float>(src[2]) * 1.5259022e-05f;
            tail = out + 4;
            out[1] = static_cast<float>(src[1]) * 1.5259022e-05f;
            uint16_t r = *src;
            src += 3;
            out[2] = static_cast<float>(r) * 1.5259022e-05f;
            out[3] = 1.0f;
            out = tail;
        } while (src < end);
    }
    if (*reinterpret_cast<int *>(s + 0x18) != 0)
        FUN_006015d0(tail + *reinterpret_cast<int *>(s + 0x68) * -4);
    if (*reinterpret_cast<int *>(s + 0x10) != 0)
        FUN_0060183d(tail + *reinterpret_cast<int *>(s + 0x68) * -4);
}

// 0x609bd2 — observed shape: eight bit-field allocator; row count derived
// from fields 0x44/0x3c; 16-byte cells allocated and constructed; pixel
// format tag selects 8/0 vs 0/8 channel swapping.
void FUN_00609bd2(void *self, int param_1)
{
    auto *s = reinterpret_cast<uint32_t *>(self);

    FUN_006011da(reinterpret_cast<void *>(param_1), 0, 1);
    uint32_t uVar1 = (s[0x11] + 1) & 0xfffffffe;
    int iVar3 = static_cast<int>(uVar1 - (s[0xf] & 0xfffffffe));
    s[0x23] = uVar1;
    *s = reinterpret_cast<uint32_t>(&PTR_FUN_006de0c8);
    s[0x21] = s[0xf] & 0xfffffffe;
    s[0x22] = 0;
    s[0x25] = 0;
    s[0x24] = 0;
    s[0x26] = 0;
    s[0x27] = static_cast<uint32_t>(iVar3);
    s[0x28] = 0;
    s[0x29] = 1;

    void *cells = FUN_00533c78(iVar3 * 0x10);
    if (cells == nullptr) {
        cells = nullptr;
    } else {
        FUN_004127b0(cells, 0x10, iVar3, reinterpret_cast<void *>(&FUN_005f6015));
    }
    s[0x20] = reinterpret_cast<uint32_t>(cells);
    if (cells == nullptr)
        s[0x29] = 0;

    int fmt = *reinterpret_cast<int *>(param_1 + 4);
    if (fmt == 0x32595559) {                    // 'YUY2'
    lab_set_a:
        s[0x2a] = 0;
        s[0x2b] = 8;
    } else {
        if (fmt != 0x42475247) {                // 'BGRG'
            if (fmt == 0x47424752) goto lab_set_a;   // 'RGBG'
            if (fmt != 0x59565955)               // 'UYVY'
                return;
        }
        s[0x2a] = 8;
        s[0x2b] = 0;
    }
}

// 0x609cc0 — observed shape: restore vtable, base destroy, free cell array,
// terminal release call.
void FUN_00609cc0(void *self)
{
    auto *s = reinterpret_cast<uint32_t *>(self);

    *s = reinterpret_cast<uint32_t>(&PTR_FUN_006de0c8);
    FUN_0060064e();
    if (s[0x20] != 0)
        operator delete(reinterpret_cast<void *>(s[0x20]));
    FUN_0060010b();
}

// 0x609ce9 — observed shape: optional source transform/pack, block visibility
// test through helper 0x600951, then cell copy and dirty flag at 0xa0.
void FUN_00609ce9(void *self, int param_1, int param_2, uint32_t *param_3)
{
    auto *s = static_cast<uint8_t *>(self);
    uint32_t *src = param_3;

    if (*reinterpret_cast<int *>(s + 0x54) != 0)
        src = static_cast<uint32_t *>(FUN_00600136(src));
    if (*reinterpret_cast<int *>(s + 0x10) != 0)
        src = static_cast<uint32_t *>(FUN_0060164a(src));

    int visible = FUN_00600951(
        param_1 + *reinterpret_cast<int *>(s + 0x40),
        param_2 + *reinterpret_cast<int *>(s + 0x4c),
        *reinterpret_cast<int *>(s + 0x9c) != *reinterpret_cast<int *>(s + 0x68));
    if (-1 < visible) {
        uint32_t *dst = reinterpret_cast<uint32_t *>(
            (*reinterpret_cast<int *>(s + 0x3c) - *reinterpret_cast<int *>(s + 0x84)) * 0x10 +
            *reinterpret_cast<int *>(s + 0x80));
        for (int n = (*reinterpret_cast<uint32_t *>(s + 0x68) & 0x0fffffff) << 2; n != 0; n--)
            *dst++ = *src++;
        for (int n = 0; n != 0; n--) {
            *reinterpret_cast<uint8_t *>(dst) = *reinterpret_cast<uint8_t *>(src);
            src = reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(src) + 1);
            dst = reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(dst) + 1);
        }
        *reinterpret_cast<uint32_t *>(s + 0xa0) = 1;
    }
}

// 0x609d77 — observed shape: clip test with clip flag 1, cell copy out of the
// locked block, then transform/pack hooks on the caller buffer.
void FUN_00609d77(void *self, int param_1, int param_2, uint32_t *param_3)
{
    auto *s = static_cast<uint8_t *>(self);

    int visible = FUN_00600951(
        param_1 + *reinterpret_cast<int *>(s + 0x40),
        param_2 + *reinterpret_cast<int *>(s + 0x4c), 1);
    if (-1 < visible) {
        uint32_t *block = reinterpret_cast<uint32_t *>(
            (*reinterpret_cast<int *>(s + 0x3c) - *reinterpret_cast<int *>(s + 0x84)) * 0x10 +
            *reinterpret_cast<int *>(s + 0x80));
        uint32_t *dst = param_3;
        for (int n = (*reinterpret_cast<uint32_t *>(s + 0x68) & 0x0fffffff) << 2; n != 0; n--)
            *dst++ = *block++;
        for (int n = 0; n != 0; n--) {
            *reinterpret_cast<uint8_t *>(dst) = *reinterpret_cast<uint8_t *>(block);
            block = reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(block) + 1);
            dst = reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(dst) + 1);
        }
        if (*reinterpret_cast<int *>(s + 0x18) != 0)
            FUN_006015d0(param_3);
        if (*reinterpret_cast<int *>(s + 0x10) != 0)
            FUN_0060183d(param_3);
    }
}

// 0x609dec — observed shape: DXT1/2/3/4/5 texture object; per-format decode
// and encode callbacks, six dwords of descriptor copied from param_1 + 0x10,
// then size/pitch fields rounded to 4.
void FUN_00609dec(void *self, int param_1)
{
    auto *s = reinterpret_cast<uint32_t *>(self);

    FUN_006011da(reinterpret_cast<void *>(param_1), 0, 1);
    int fmt = static_cast<int>(s[1]);
    *s = reinterpret_cast<uint32_t>(&PTR_FUN_006de0d8);

    if (fmt == 0x31545844) {                    // 'DXT1'
        s[0x22] = 8;
        s[0x24] = reinterpret_cast<uint32_t>(&FUN_0065a24d);
        s[0x23] = reinterpret_cast<uint32_t>(&FUN_00659f48);
    } else if (fmt == 0x32545844) {             // 'DXT2'
        s[0x22] = 0x10;
        s[0x24] = reinterpret_cast<uint32_t>(&FUN_0065a9c0);
        s[0x23] = reinterpret_cast<uint32_t>(&FUN_0065a974);
    } else if (fmt == 0x33545844) {             // 'DXT3'
        s[0x22] = 0x10;
        s[0x24] = reinterpret_cast<uint32_t>(&FUN_0065a371);
        s[0x23] = reinterpret_cast<uint32_t>(&FUN_0065a08a);
    } else if (fmt == 0x34545844) {             // 'DXT4'
        s[0x22] = 0x10;
        s[0x24] = reinterpret_cast<uint32_t>(&FUN_0065a9f9);
        s[0x23] = reinterpret_cast<uint32_t>(&FUN_0065a99a);
    } else if (fmt == 0x35545844) {             // 'DXT5'
        s[0x22] = 0x10;
        s[0x24] = reinterpret_cast<uint32_t>(&FUN_0065a4a0);
        s[0x23] = reinterpret_cast<uint32_t>(&FUN_0065a10f);
    }

    uint32_t *src = reinterpret_cast<uint32_t *>(param_1 + 0x10);
    uint32_t *dst = s + 0x25;
    for (int n = 6; n != 0; n--)
        *dst++ = *src++;

    s[0x2b] = s[0x25] & 0xfffffffc;
    s[0x2c] = s[0x26] & 0xfffffffc;
    s[0x2f] = s[0x29];
    s[0x2d] = (s[0x27] + 3) & 0xfffffffc;
    s[0x3a] = 0xffffffff;
    s[0x3b] = 0xffffffff;
    s[0x2e] = (s[0x28] + 3) & 0xfffffffc;
    s[0x30] = s[0x2a];
    s[0x35] = s[0x13];

    uint32_t uVar1 = (s[0x11] + 3) & 0xfffffffc;
    s[0x33] = uVar1;
    uint32_t uVar3 = (s[0x12] + 3) & 0xfffffffc;
    s[0x34] = uVar3;
    s[0x37] = (uVar1 - (s[0xf] & 0xfffffffc)) >> 2;
    s[0x36] = s[0x14];
    s[0x3c] = 0;
    s[0x3d] = 0;
    s[0x3e] = 0;
    s[0x31] = s[0xf] & 0xfffffffc;
    s[0x32] = s[0x10] & 0xfffffffc;
    s[0x38] = (uVar3 - (s[0x10] & 0xfffffffc)) >> 2;
    s[0x39] = s[0x14] - s[0x13];
    s[0x3f] = *reinterpret_cast<uint32_t *>(param_1 + 0x40);
}

// 0x609fd4 — observed shape: scalar deleting destructor; frees self when the
// low bit of the flag is set.
void FUN_00609fd4(void *self, uint8_t param_1)
{
    FUN_00600fd8();
    if ((param_1 & 1) != 0)
        operator delete(self);
}

// 0x609ff5 — observed shape: per-4x4-block decode cache; lazily allocates the
// block table (field 0xf8) and a 4-row scratch buffer, decodes the surrounding
// texels, writes the four rows of the block, marks the block present, and on a
// full block (mask 0xf) emits the block through the codec callback or defers
// it to the next block.
void FUN_00609ff5(void *self, uint32_t param_1, int param_2, uint32_t *param_3)
{
    auto *s = static_cast<uint8_t *>(self);
    param_1 = param_1 + *reinterpret_cast<uint32_t *>(s + 0x40);
    param_2 = param_2 + *reinterpret_cast<int *>(s + 0x4c);

    uint32_t local_24[5];
    uint32_t local_10;
    uint32_t local_c;
    uint32_t *local_8;

    if (*reinterpret_cast<int *>(s + 0xf8) == 0) {
        uint32_t *table = static_cast<uint32_t *>(FUN_00533c78(
            *reinterpret_cast<int *>(s + 0xe0) * *reinterpret_cast<int *>(s + 0xe4) * 8));
        *reinterpret_cast<uint32_t **>(s + 0xf8) = table;
        if (table == nullptr)
            return;
        for (int n = (*reinterpret_cast<int *>(s + 0xe0) *
                      *reinterpret_cast<int *>(s + 0xe4) & 0x1fffffff) << 1; n != 0; n--)
            *table++ = 0;
        for (int n = 0; n != 0; n--) {
            *reinterpret_cast<uint8_t *>(table) = 0;
            table = reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(table) + 1);
        }
    }

    uint32_t *block = reinterpret_cast<uint32_t *>(
        *reinterpret_cast<int *>(s + 0xf8) +
        ((param_2 - *reinterpret_cast<int *>(s + 0xd4)) * *reinterpret_cast<int *>(s + 0xe0) +
         (param_1 - *reinterpret_cast<uint32_t *>(s + 200) >> 2)) * 8);
    local_8 = block;

    if (block[1] == 0) {
        int rows = *reinterpret_cast<int *>(s + 0xdc);
        local_24[4] = reinterpret_cast<uint32_t>(FUN_00533c78(rows << 8));
        uint32_t scratch;
        if (local_24[4] == 0) {
            scratch = 0;
        } else {
            FUN_004127b0(reinterpret_cast<void *>(local_24[4]), 0x10, rows << 4,
                         reinterpret_cast<void *>(&FUN_005f6015));
            scratch = local_24[4];
        }
        block[1] = scratch;
        if (scratch == 0)
            return;
        *block = 0;
        *reinterpret_cast<int *>(s + 0xf4) = *reinterpret_cast<int *>(s + 0xf4) + 1;
    }

    if (*block == 0) {
        local_24[4] = param_1 & 0xfffffffc;
        if ((local_24[4] < *reinterpret_cast<uint32_t *>(s + 0x40) &&
             *reinterpret_cast<uint32_t *>(s + 0x98) < *reinterpret_cast<uint32_t *>(s + 0x40)) ||
            (*reinterpret_cast<uint32_t *>(s + 0x48) < local_24[4] + 4 &&
             *reinterpret_cast<uint32_t *>(s + 0x48) < *reinterpret_cast<uint32_t *>(s + 0xa0))) {
            local_10 = *reinterpret_cast<uint32_t *>(s + 0xc4);
            int src = static_cast<int>(param_1 >> 2) * *reinterpret_cast<int *>(s + 0x60) +
                      (local_10 >> 2) * *reinterpret_cast<int *>(s + 0x88) +
                      *reinterpret_cast<int *>(s + 0x64) * param_2 +
                      *reinterpret_cast<int *>(s + 0x20);
            local_c = block[1];
            if (local_10 < *reinterpret_cast<uint32_t *>(s + 0xcc)) {
                do {
                    (*reinterpret_cast<void (**)(uint32_t, int)>(s + 0x8c))(local_c, src);
                    local_10 = local_10 + 4;
                    src = src + *reinterpret_cast<int *>(s + 0x88);
                    local_c = local_c + 0x100;
                } while (local_10 < *reinterpret_cast<uint32_t *>(s + 0xcc));
            }
        } else {
            if (*reinterpret_cast<uint32_t *>(s + 0xc4) < *reinterpret_cast<uint32_t *>(s + 0x3c) &&
                *reinterpret_cast<uint32_t *>(s + 0x94) < *reinterpret_cast<uint32_t *>(s + 0x3c)) {
                (*reinterpret_cast<void (**)(uint32_t, int)>(s + 0x8c))(
                    block[1],
                    (*reinterpret_cast<uint32_t *>(s + 0xc4) >> 2) * *reinterpret_cast<int *>(s + 0x88) +
                    (param_1 >> 2) * *reinterpret_cast<int *>(s + 0x60) +
                    *reinterpret_cast<int *>(s + 0x64) * param_2 +
                    *reinterpret_cast<int *>(s + 0x20));
            }
            if (*reinterpret_cast<uint32_t *>(s + 0x44) < *reinterpret_cast<uint32_t *>(s + 0xcc) &&
                *reinterpret_cast<uint32_t *>(s + 0x44) < *reinterpret_cast<uint32_t *>(s + 0x9c)) {
                (*reinterpret_cast<void (**)(uint32_t, int)>(s + 0x8c))(
                    block[1],
                    (*reinterpret_cast<uint32_t *>(s + 0xcc) - 4 >> 2) * *reinterpret_cast<int *>(s + 0x88) +
                    (param_1 >> 2) * *reinterpret_cast<int *>(s + 0x60) +
                    *reinterpret_cast<int *>(s + 0x64) * param_2 +
                    *reinterpret_cast<int *>(s + 0x20));
            }
        }
        uint32_t uVar4 = 0;
        do {
            if (uVar4 + local_24[4] < *reinterpret_cast<uint32_t *>(s + 0x40) ||
                *reinterpret_cast<uint32_t *>(s + 0x48) <= uVar4 + local_24[4]) {
                *block = *block | (1u << (uVar4 & 0x1f));
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < 4);
    }

    if (*reinterpret_cast<int *>(s + 0x54) != 0)
        param_3 = static_cast<uint32_t *>(FUN_00600136(param_3));
    if (*reinterpret_cast<int *>(s + 0x10) != 0)
        param_3 = static_cast<uint32_t *>(FUN_0060164a(param_3));

    uint32_t row = *reinterpret_cast<uint32_t *>(s + 0x3c) - *reinterpret_cast<uint32_t *>(s + 0xc4);
    int base = *reinterpret_cast<int *>(s + 200);
    local_24[4] = *reinterpret_cast<uint32_t *>(s + 0x68) + row;
    for (; row < local_24[4]; row = row + 1) {
        uint32_t *texel = reinterpret_cast<uint32_t *>(
            (((row & 0xfffffffc | (param_1 - base) & 3) << 2 | row & 3) * 0x10 + block[1]));
        texel[0] = param_3[0];
        texel[1] = param_3[1];
        texel[2] = param_3[2];
        texel[3] = param_3[3];
        block = local_8;
        param_3 = param_3 + 4;
    }

    *block = *block | (1u << (param_1 & 3));
    if (*block == 0xf) {
        local_c = *reinterpret_cast<uint32_t *>(s + 0xc4);
        param_2 = static_cast<int>(
            (param_1 >> 2) * *reinterpret_cast<int *>(s + 0x60) +
            (local_c >> 2) * *reinterpret_cast<int *>(s + 0x88) +
            *reinterpret_cast<int *>(s + 0x64) * param_2 +
            *reinterpret_cast<int *>(s + 0x20));
        uint32_t *scratch = reinterpret_cast<uint32_t *>(block[1]);
        if (local_c < *reinterpret_cast<uint32_t *>(s + 0xcc)) {
            local_24[0] = 0;
            local_24[1] = 0;
            local_24[2] = 0;
            local_24[4] = param_1 & 0xfffffffc;
            local_24[3] = 1;
            do {
                uint32_t uVar4 = *reinterpret_cast<uint32_t *>(s + 0x9c) - local_c;
                uint32_t uVar5 = *reinterpret_cast<uint32_t *>(s + 0xa0) - local_24[4];
                if (uVar4 < 4) {
                    uint32_t p1 = 0;
                    if (uVar5 != 0) {
                        do {
                            if (3 < p1)
                                break;
                            uint32_t uVar6 = uVar4;
                            do {
                                uint32_t *src = reinterpret_cast<uint32_t *>(
                                    (local_24[uVar6] | p1 << 2) * 0x10 + reinterpret_cast<intptr_t>(scratch));
                                uint32_t *dst = reinterpret_cast<uint32_t *>(
                                    (p1 << 2 | uVar6) * 0x10 + reinterpret_cast<intptr_t>(scratch));
                                uVar6 = uVar6 + 1;
                                dst[0] = src[0];
                                dst[1] = src[1];
                                dst[2] = src[2];
                                dst[3] = src[3];
                            } while (uVar6 < 4);
                            p1 = p1 + 1;
                            block = local_8;
                        } while (p1 < uVar5);
                    }
                }
                if (uVar5 < 4) {
                    do {
                        uint32_t uVar4b = local_24[uVar5];
                        uint32_t uVar6 = 0;
                        do {
                            uint32_t *dst = reinterpret_cast<uint32_t *>(
                                (uVar5 << 2 | uVar6) * 0x10 + reinterpret_cast<intptr_t>(scratch));
                            uint32_t *src = reinterpret_cast<uint32_t *>(
                                (uVar4b << 2 | uVar6) * 0x10 + reinterpret_cast<intptr_t>(scratch));
                            uVar6 = uVar6 + 1;
                            dst[0] = src[0];
                            dst[1] = src[1];
                            dst[2] = src[2];
                            dst[3] = src[3];
                        } while (uVar6 < 4);
                        uVar5 = uVar5 + 1;
                    } while (uVar5 < 4);
                    block = local_8;
                }
                uint32_t flags = 0;
                if (*reinterpret_cast<int *>(s + 0xfc) != 0 ||
                    *reinterpret_cast<int *>(s + 0x5c) != 0)
                    flags = 1;
                (*reinterpret_cast<void (**)(int, void *, uint32_t)>(s + 0x90))(
                    param_2, scratch, flags);
                local_c = local_c + 4;
                param_2 = param_2 + *reinterpret_cast<int *>(s + 0x88);
                scratch = reinterpret_cast<uint32_t *>(
                    reinterpret_cast<uint8_t *>(scratch) + 0x100);
            } while (local_c < *reinterpret_cast<uint32_t *>(s + 0xcc));
        }
        if (block + 2 < reinterpret_cast<uint32_t *>(
                              *reinterpret_cast<int *>(s + 0xf8) +
                              *reinterpret_cast<int *>(s + 0xe4) * *reinterpret_cast<int *>(s + 0xe0) * 8) &&
            block[2] == 0 && block[3] == 0) {
            block[3] = block[1];
            block[1] = 0;
        } else {
            operator delete(reinterpret_cast<void *>(block[1]));
            *reinterpret_cast<int *>(s + 0xf4) = *reinterpret_cast<int *>(s + 0xf4) - 1;
        }
        block[1] = 0;
    }
}

// 0x60a416 — observed shape: rolling four-row window; lazily allocates the
// window (field 0xf0) on first use, refills the rows when the block column or
// row changed, then applies a squash-to-palette filter over the copied texels.
void FUN_0060a416(void *self, int param_1, int param_2, float *param_3)
{
    auto *s = static_cast<uint8_t *>(self);
    uint32_t uVar7 = param_1 + *reinterpret_cast<uint32_t *>(s + 0x40);
    param_2 = param_2 + *reinterpret_cast<int *>(s + 0x4c);

    if (*reinterpret_cast<int *>(s + 0xf0) == 0) {
        int rows = *reinterpret_cast<int *>(s + 0xdc);
        void *window = FUN_00533c78(rows << 8);
        if (window == nullptr) {
            window = nullptr;
        } else {
            FUN_004127b0(window, 0x10, rows << 4, reinterpret_cast<void *>(&FUN_005f6015));
        }
        *reinterpret_cast<void **>(s + 0xf0) = window;
        if (window == nullptr)
            return;
    }

    if ((uVar7 & 0xfffffffc) != *reinterpret_cast<uint32_t *>(s + 0xe8) ||
        param_2 != *reinterpret_cast<int *>(s + 0xec)) {
        *reinterpret_cast<uint32_t *>(s + 0xe8) = uVar7 & 0xfffffffc;
        uint32_t row = *reinterpret_cast<uint32_t *>(s + 0xc4);
        param_1 = static_cast<int>(
            (uVar7 >> 2) * *reinterpret_cast<int *>(s + 0x60) +
            (row >> 2) * *reinterpret_cast<int *>(s + 0x88) +
            *reinterpret_cast<int *>(s + 0x64) * param_2 +
            *reinterpret_cast<int *>(s + 0x20));
        *reinterpret_cast<int *>(s + 0xec) = param_2;
        param_2 = *reinterpret_cast<int *>(s + 0xf0);
        for (; row < *reinterpret_cast<uint32_t *>(s + 0xcc); row = row + 4) {
            (*reinterpret_cast<void (**)(int, int)>(s + 0x8c))(param_2, param_1);
            param_1 = param_1 + *reinterpret_cast<int *>(s + 0x88);
            param_2 = param_2 + 0x100;
        }
    }

    int base = *reinterpret_cast<int *>(s + 200);
    uint32_t row = *reinterpret_cast<uint32_t *>(s + 0x3c) - *reinterpret_cast<uint32_t *>(s + 0xc4);
    uint32_t rowEnd = *reinterpret_cast<uint32_t *>(s + 0x68) + row;
    float *dst = param_3;
    for (; row < rowEnd; row = row + 1) {
        float *texel = reinterpret_cast<float *>(
            ((row & 0xfffffffc | (uVar7 - base) & 3) << 2 | row & 3) * 0x10 +
            *reinterpret_cast<int *>(s + 0xf0));
        *dst = texel[0];
        dst[1] = texel[1];
        float *a = dst + 3;
        dst[2] = texel[2];
        dst = dst + 4;
        *a = texel[3];
    }

    float *cursor = dst;
    if (*reinterpret_cast<int *>(s + 0x18) != 0) {
        *reinterpret_cast<float **>(s + 0x7c) = dst;
        for (cursor = dst + *reinterpret_cast<int *>(s + 0x68) * -4; cursor < dst; cursor = cursor + 4) {
            if (static_cast<float>(static_cast<int>(cursor[0] * 31.0f + 0.5f)) * 0.032258064f ==
                    *reinterpret_cast<float *>(s + 0x24) &&
                static_cast<float>(static_cast<int>(cursor[1] * 63.0f + 0.5f)) * 0.015873017f ==
                    *reinterpret_cast<float *>(s + 0x28) &&
                static_cast<float>(static_cast<int>(cursor[2] * 31.0f + 0.5f)) * 0.032258064f ==
                    *reinterpret_cast<float *>(s + 0x2c) &&
                static_cast<float>(static_cast<int>(cursor[3] * *reinterpret_cast<float *>(s + 0x80) + 0.5f)) *
                        *reinterpret_cast<float *>(s + 0x84) ==
                    *reinterpret_cast<float *>(s + 0x30)) {
                cursor[0] = 0.0f;
                cursor[1] = 0.0f;
                cursor[2] = 0.0f;
                cursor[3] = 0.0f;
            }
        }
    }
    if (*reinterpret_cast<int *>(s + 0x10) != 0)
        FUN_0060183d(cursor + *reinterpret_cast<int *>(s + 0x68) * -4);
}

// 0x60a6a1 — observed shape: subclass constructor; base init then vtable
// restored to the YUV-family table.
void FUN_0060a6a1(void *self, void *param_1)
{
    auto *s = reinterpret_cast<uint32_t *>(self);
    FUN_00609bd2(self, reinterpret_cast<int>(param_1));
    *s = reinterpret_cast<uint32_t>(&PTR_FUN_006de0c8);
}

// 0x60a6be — observed shape: subclass constructor; base init then vtable
// restored to the DXT-family table.
void FUN_0060a6be(void *self, void *param_1)
{
    auto *s = reinterpret_cast<uint32_t *>(self);
    FUN_00609dec(self, reinterpret_cast<int>(param_1));
    *s = reinterpret_cast<uint32_t>(&PTR_FUN_006de0d8);
}

// 0x60a6db — observed shape: scalar deleting destructor for the DXT surface.
void FUN_0060a6db(void *self, uint8_t param_1)
{
    FUN_00609cc0(self);
    if ((param_1 & 1) != 0)
        operator delete(self);
}

// 0x60a6fc — observed shape: descriptor-to-surface factory. The fourcc at
// param_1 + 4 selects an object size (0x80 / 0x100 / 0xb0) and a constructor;
// on success the object's virtual init (slot 3) runs, and a failed init frees
// it through slot 0 with argument 1.
int *FUN_0060a6fc(int param_1)
{
    int fourcc = *reinterpret_cast<int *>(param_1 + 4);
    int *obj;
    void *mem = nullptr;

    if (fourcc < 0x31545845) {
        if (fourcc == 0x31545844) {                 // 'DXT1'
            mem = FUN_00533c78(0x100);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_0060a6be(mem, reinterpret_cast<void *>(param_1)));
        } else if (fourcc < 0x33) {
            if (fourcc == 0x32) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00606b56(mem, reinterpret_cast<void *>(param_1)));
            } else {
                switch (fourcc) {
                case 0x14: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00605f03(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x15: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00605f24(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x16: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00605f45(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x17: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606281(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x18: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_006062a2(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x19: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_006062c3(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x1a: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_006062e4(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x1b: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606305(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x1c: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606326(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x1d: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606347(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x1e: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606368(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x1f: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_006066a2(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x20: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_006066c3(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x21: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_006066e4(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x22: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606705(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x23: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606726(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x24: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606747(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x28: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606768(mem, reinterpret_cast<void *>(param_1))); break;
                case 0x29: mem = FUN_00533c78(0x80); if (mem == nullptr) goto lab_ae3f; obj = static_cast<int *>(FUN_00606b35(mem, reinterpret_cast<void *>(param_1))); break;
                default: goto lab_ae72;
                }
            }
        } else if (fourcc < 0x52) {
            if (fourcc == 0x51) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00607333(mem, reinterpret_cast<void *>(param_1)));
            } else if (fourcc < 0x3f) {
                if (fourcc == 0x3e) {
                    mem = FUN_00533c78(0x80);
                    if (mem == nullptr) goto lab_ae3f;
                    obj = static_cast<int *>(FUN_00606bfb(mem, reinterpret_cast<void *>(param_1)));
                } else if (fourcc == 0x33) {
                    mem = FUN_00533c78(0x80);
                    if (mem == nullptr) goto lab_ae3f;
                    obj = static_cast<int *>(FUN_00606b77(mem, reinterpret_cast<void *>(param_1)));
                } else if (fourcc == 0x34) {
                    mem = FUN_00533c78(0x80);
                    if (mem == nullptr) goto lab_ae3f;
                    obj = static_cast<int *>(FUN_00606b98(mem, reinterpret_cast<void *>(param_1)));
                } else if (fourcc == 0x3c) {
                    mem = FUN_00533c78(0x80);
                    if (mem == nullptr) goto lab_ae3f;
                    obj = static_cast<int *>(FUN_00606bb9(mem, reinterpret_cast<void *>(param_1)));
                } else {
                    if (fourcc != 0x3d)
                        return nullptr;
                    mem = FUN_00533c78(0x80);
                    if (mem == nullptr) goto lab_ae3f;
                    obj = static_cast<int *>(FUN_00606bda(mem, reinterpret_cast<void *>(param_1)));
                }
            } else if (fourcc == 0x3f) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00606e93(mem, reinterpret_cast<void *>(param_1)));
            } else if (fourcc == 0x40) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00606eb4(mem, reinterpret_cast<void *>(param_1)));
            } else if (fourcc == 0x43) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00606ed5(mem, reinterpret_cast<void *>(param_1)));
            } else {
                if (fourcc != 0x46)
                    return nullptr;
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00607333(mem, reinterpret_cast<void *>(param_1)));
            }
        } else if (fourcc < 0x72) {
            if (fourcc == 0x71) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_006073b7(mem, reinterpret_cast<void *>(param_1)));
            } else if (fourcc == 0x52) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00607354(mem, reinterpret_cast<void *>(param_1)));
            } else if (fourcc == 0x6e) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00606ef6(mem, reinterpret_cast<void *>(param_1)));
            } else if (fourcc == 0x6f) {
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00607375(mem, reinterpret_cast<void *>(param_1)));
            } else {
                if (fourcc != 0x70)
                    return nullptr;
                mem = FUN_00533c78(0x80);
                if (mem == nullptr) goto lab_ae3f;
                obj = static_cast<int *>(FUN_00607396(mem, reinterpret_cast<void *>(param_1)));
            }
        } else if (fourcc == 0x72) {
            mem = FUN_00533c78(0x80);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_00607354(mem, reinterpret_cast<void *>(param_1)));
        } else if (fourcc == 0x73) {
            mem = FUN_00533c78(0x80);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_006073d8(mem, reinterpret_cast<void *>(param_1)));
        } else if (fourcc == 0x74) {
            mem = FUN_00533c78(0x80);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_006073f9(mem, reinterpret_cast<void *>(param_1)));
        } else {
            if (fourcc != 0x75)
                return nullptr;
            mem = FUN_00533c78(0x80);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_00606f38(mem, reinterpret_cast<void *>(param_1)));
        }
    } else if (fourcc < 0x36314c42) {
        if (fourcc == 0x36314c41) {                 // 'A1L6'
            mem = FUN_00533c78(0x80);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_006077f2(mem, reinterpret_cast<void *>(param_1)));
        } else if (fourcc == 0x32545844) {          // 'DXT2'
            mem = FUN_00533c78(0x100);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_0060a6be(mem, reinterpret_cast<void *>(param_1)));
        } else if (fourcc == 0x32595559) {          // 'YUY2'
            mem = FUN_00533c78(0xb0);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_0060a6a1(mem, reinterpret_cast<void *>(param_1)));
        } else if (fourcc == 0x33545844) {          // 'DXT3'
            mem = FUN_00533c78(0x100);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_0060a6be(mem, reinterpret_cast<void *>(param_1)));
        } else if (fourcc == 0x34545844) {          // 'DXT4'
            mem = FUN_00533c78(0x100);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_0060a6be(mem, reinterpret_cast<void *>(param_1)));
        } else {
            if (fourcc != 0x35545844)               // 'DXT5'
                return nullptr;
            mem = FUN_00533c78(0x100);
            if (mem == nullptr) goto lab_ae3f;
            obj = static_cast<int *>(FUN_0060a6be(mem, reinterpret_cast<void *>(param_1)));
        }
    } else if (fourcc == 0x36315220) {              // 'R1L6' little-endian form
        mem = FUN_00533c78(0x80);
        if (mem == nullptr) goto lab_ae3f;
        obj = static_cast<int *>(FUN_00607813(mem, reinterpret_cast<void *>(param_1)));
    } else if (fourcc == 0x42475247) {              // 'BGRG'
        mem = FUN_00533c78(0xb0);
        if (mem == nullptr) goto lab_ae3f;
        obj = static_cast<int *>(FUN_0060a6a1(mem, reinterpret_cast<void *>(param_1)));
    } else if (fourcc == 0x47424752) {              // 'RGBG'
        mem = FUN_00533c78(0xb0);
        if (mem == nullptr) goto lab_ae3f;
        obj = static_cast<int *>(FUN_0060a6a1(mem, reinterpret_cast<void *>(param_1)));
    } else {
        if (fourcc != 0x59565955)                   // 'UYVY'
            return nullptr;
        mem = FUN_00533c78(0xb0);
        if (mem == nullptr) goto lab_ae3f;
        obj = static_cast<int *>(FUN_0060a6a1(mem, reinterpret_cast<void *>(param_1)));
    }

    if (obj != nullptr) {
        if (obj[7] == 0 || FUN_00601429(reinterpret_cast<void *>(param_1)) >= 0) {
            if (obj[6] != 0)
                (*reinterpret_cast<void (**)()>(*reinterpret_cast<intptr_t *>(obj) + 0xc))();
            return obj;
        }
        (*reinterpret_cast<void (**)(int)>(*reinterpret_cast<intptr_t *>(obj)))(1);
    }
    goto lab_ae72;
lab_ae3f:
    obj = nullptr;
    (void)obj;
lab_ae72:
    return nullptr;
}

// 0x60aed0 — observed shape: gather up to three doubles through the pointer
// table, zero-fill the remainder, store the float result of helper 0x5f465d.
void FUN_0060aed0(uint32_t param_1, int **param_2, double *param_3)
{
    float rows[128];
    float local_10[3];

    uint32_t uVar1 = 0;
    uint32_t uVar2 = 0;
    if (param_1 != 0) {
        do {
            if (2 < uVar2)
                goto lab_af08;
            uVar1 = uVar2 + 1;
            rows[uVar2 + 0x81] = static_cast<float>(*reinterpret_cast<double *>(*param_2 + uVar2 * 8));
            uVar2 = uVar1;
        } while (uVar1 < param_1);
        if (2 < uVar1)
            goto lab_af08;
    }
    {
        float *fill = local_10 + uVar1;
        for (int n = 3 - static_cast<int>(uVar1); n != 0; n--)
            *fill++ = 0.0f;
    }
lab_af08:
    *param_3 = static_cast<double>(FUN_005f465d());
}

// 0x60af1a — observed shape: validate a two-level table: each row lists
// `count` entries of 8 bytes whose second dword must not be 9, and each row
// terminator must be non-zero and at most 9.
uint32_t FUN_0060af1a(uint32_t param_1, int *param_2)
{
    uint32_t uVar3 = 0;
    if (param_1 != 0) {
        do {
            uint32_t rows = *reinterpret_cast<uint32_t *>(*param_2);
            *param_2 = reinterpret_cast<int>(reinterpret_cast<uint32_t *>(*param_2) + 1);
            if (rows != 0) {
                uint32_t uVar4 = 0;
                do {
                    int entry = *reinterpret_cast<int *>(*param_2);
                    *param_2 = reinterpret_cast<int>(reinterpret_cast<int *>(*param_2) + 2);
                    if (entry == 9)
                        return 0x80004005;
                    uVar4 = uVar4 + 1;
                } while (uVar4 < rows);
            }
            uint32_t term = *reinterpret_cast<uint32_t *>(*param_2);
            *param_2 = reinterpret_cast<int>(reinterpret_cast<uint32_t *>(*param_2) + 2);
            if (term == 0 || 9 < term)
                return 0x80004005;
            uVar3 = uVar3 + 1;
        } while (uVar3 < param_1);
    }
    return 0;
}

// 0x60af7a — observed shape: single-entry validation; a leading zero followed
// by a tag in {4,5,6,7} succeeds, anything else reports E_FAIL.
uint32_t FUN_0060af7a(int *param_1)
{
    int *entry = reinterpret_cast<int *>(*param_1);
    int head = *entry;
    *param_1 = reinterpret_cast<int>(entry + 1);
    if (head == 0) {
        int tag = entry[1];
        *param_1 = reinterpret_cast<int>(entry + 3);
        if (tag == 7 || tag == 4 || tag == 5 || tag == 6)
            return 0;
    }
    return 0x80004005;
}

// 0x60afb7 — observed shape: parse the 'FXCL'/'CLIT' shader section; requires
// a version in 0x465801ff..0x46580202 or 0x54580100, then validates each
// program table pair through helpers 0x60af1a and 0x60af7a.
int FUN_0060afb7(uint32_t *param_1, int *param_2, int *param_3)
{
    int *const entry = param_2;
    uint32_t *cursor = param_1;
    uint32_t version = *param_1;
    int result;

    if (version > 0x465801ff && (version < 0x46580202 || version == 0x54580100)) {
        int r = FUN_005f7ad0(param_1, 0x434c5846, param_2, 0);   // 'FXCL'
        if (r >= 0) {
            r = FUN_005f7ad0(cursor, 0x54494c43, param_3, 0);    // 'CLIT'
            if (r >= 0 && r != 1) {
                uint32_t *prog = reinterpret_cast<uint32_t *>(*entry);
                if (prog != nullptr && *param_3 != 0) {
                    uint32_t count = *prog++;
                    uint32_t uVar6 = 0;
                    if (count != 0) {
                        do {
                            uint32_t *tableCount = prog + 1;
                            prog = prog + 2;
                            int v = FUN_0060af1a(*tableCount, reinterpret_cast<int *>(&prog));
                            if (v < 0)
                                goto lab_b060_fail;
                            v = FUN_0060af7a(reinterpret_cast<int *>(&prog));
                            if (v < 0)
                                goto lab_b060_fail;
                            uVar6 = uVar6 + 1;
                        } while (uVar6 < count);
                    }
                    return 0;
                }
            }
        }
    }
    return -0x7fffbffb;
lab_b060_fail:
    return -0x7fffbffb;
}

// 0x60b067 — observed shape: shader program interpreter. Each record carries a
// control word (bit 31 = packed sign / opcode group in bits 20-30, low 20 bits
// = element count), a source count with per-source operand descriptors, and a
// destination descriptor; operands are resolved against the stack scratch
// array (tag 7) or the four register banks (tags 1..6, 9) with their masks.
uint32_t
FUN_0060b067(uint32_t *param_1, uint32_t *param_2, int param_3, int param_4, int param_5,
             int param_6, int param_7, int param_8, uint32_t param_9, uint32_t param_10,
             uint32_t param_11, uint32_t param_12, uint32_t param_13, uint32_t param_14)
{
    double scratch[256];
    double *sources[2];
    double *selectBank = nullptr;
    uint32_t count;
    uint32_t control;
    uint32_t local_18;
    uint32_t inputCount;
    uint32_t innerCount;
    uint32_t elementCount;
    uint32_t index;
    double *dst;

    uint32_t pc = 0;
    inputCount = *param_2;
    uint32_t *word = param_1 + 1;
    count = *param_1;
    if (*param_1 == 0)
        return 0;

    do {
        control = *word;
        uint32_t *next = word + 2;
        elementCount = *word & 0xfffff;
        index = 0;
        innerCount = word[1];
        if (word[1] != 0) {
            do {
                word = next + 1;
                int depth = 0;
                if (*next != 0) {
                    local_18 = *next;
                    do {
                        uint32_t tag = *word;
                        next = word + 1;
                        word = word + 2;
                        depth = static_cast<int>(*next) + depth * 4;
                        // NEEDS_MANUAL: the listing truncates these two sites
                        // as a bare ftol(); only the dword-scaled accumulation
                        // above survives decoding.
                        if (tag == 7)
                            depth = static_cast<int>(depth);
                        if (tag == 1 || tag == 2 || tag == 3 || tag == 4 || tag == 5 || tag == 6)
                            depth = static_cast<int>(depth);
                        local_18 = local_18 - 1;
                    } while (local_18 != 0);
                }
                uint32_t kind = *word;
                next = word + 2;
                uint32_t off = word[1] + static_cast<uint32_t>(depth * 4);
                double *op;
                if (kind == 7) {
                    op = scratch + (off & 0xff);
                } else if (kind == 2) {
                    op = reinterpret_cast<double *>(param_4 + (off & param_10) * 8);
                } else if (kind == 3) {
                    op = reinterpret_cast<double *>(param_3 + (off & param_9) * 8);
                } else if (kind == 1) {
                    op = reinterpret_cast<double *>(param_2 + (off % inputCount) * 2 + 1);
                } else if (kind == 9) {
                    op = reinterpret_cast<double *>(param_5 + (off & param_11) * 4);
                } else if (kind == 4) {
                    op = reinterpret_cast<double *>(param_6 + (off & param_12) * 8);
                } else if (kind == 5) {
                    op = reinterpret_cast<double *>(param_8 + (off & param_14) * 8);
                } else if (kind == 6) {
                    op = reinterpret_cast<double *>(param_7 + (off & param_13) * 8);
                } else {
                    op = nullptr;
                }
                sources[index] = op;
                index = index + 1;
            } while (index < innerCount);
        }

        uint32_t dstKind = next[1];
        uint32_t dstOff = next[2];
        word = next + 3;
        if (dstKind == 7) {
            dst = scratch + (dstOff & 0xff);
        } else if (dstKind == 4) {
            dst = reinterpret_cast<double *>(param_6 + (dstOff & param_12) * 8);
        } else if (dstKind == 5) {
            dst = reinterpret_cast<double *>(param_8 + (dstOff & param_14) * 8);
        } else if (dstKind == 6) {
            dst = reinterpret_cast<double *>(param_7 + (dstOff & param_13) * 8);
        } else {
            dst = nullptr;
        }

        if (static_cast<int32_t>(control) < 0) {
            uint32_t group = control & 0x7ff00000;
            if (group < 0x20400001) {
                if (group == 0x20400000) {
                    for (; elementCount != 0; elementCount--) {
                        *dst = *(double *)((intptr_t)sources[1] - (intptr_t)dst + (intptr_t)dst) +
                               *sources[0];
                        dst = dst + 1;
                    }
                } else if (group == 0x20000000) {
                    for (double *s = sources[1]; elementCount != 0; elementCount--) {
                        double v = (*s <= *sources[0]) ? *s : *sources[0];
                        *(double *)((intptr_t)s + ((intptr_t)dst - (intptr_t)sources[1])) = v;
                        s = s + 1;
                    }
                } else if (group == 0x20100000) {
                    for (double *s = sources[1]; elementCount != 0; elementCount--) {
                        double v = (*sources[0] <= *s) ? *s : *sources[0];
                        *(double *)(((intptr_t)dst - (intptr_t)sources[1]) + (intptr_t)s) = v;
                        s = s + 1;
                    }
                } else if (group == 0x20200000) {
                    for (; elementCount != 0; elementCount--) {
                        double v = (*(double *)((intptr_t)sources[1] - (intptr_t)dst + (intptr_t)dst)
                                    <= *sources[0]) ? 0.0 : 1.0;
                        *dst = v;
                        dst = dst + 1;
                    }
                } else if (group == 0x20300000) {
                    for (; elementCount != 0; elementCount--) {
                        double v = (*sources[0] <
                                    *(double *)((intptr_t)sources[1] - (intptr_t)dst + (intptr_t)dst))
                                       ? 0.0 : 1.0;
                        *dst = v;
                        dst = dst + 1;
                    }
                }
            } else if (group == 0x20500000) {
                for (; elementCount != 0; elementCount--) {
                    *dst = *(double *)((intptr_t)sources[1] - (intptr_t)dst + (intptr_t)dst) *
                           *sources[0];
                    dst = dst + 1;
                }
            } else if (group == 0x20600000) {
                for (; elementCount != 0; elementCount--) {
                    *dst = atan2(*sources[0],
                                 *(double *)((intptr_t)sources[1] - (intptr_t)dst + (intptr_t)dst));
                    dst = dst + 1;
                }
            } else if (group == 0x50000000) {
                uint32_t i = 0;
                *dst = 0.0;
                for (; i < elementCount; i++) {
                    double *s = sources[1] + i;
                    *dst = *s * *sources[0] + *dst;
                }
            }
        } else {
            uint32_t group = control & 0x7ff00000;
            if (group < 0x10c00001) {
                if (group == 0x10c00000) {
                    for (; elementCount != 0; elementCount--) {
                        *dst = atan(*(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst)));
                        dst = dst + 1;
                    }
                } else if (group < 0x10600001) {
                    if (group == 0x10600000) {
                        for (uint32_t i = 0; i < elementCount; i++) {
                            double v;
                            if (*sources[i] < 0.0) {
                                v = 0.0;
                            } else {
                                v = 0.6931471805599453 *
                                    log2(*(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst))) *
                                    1.4426950408889634;
                            }
                            *dst = v;
                            dst = dst + 1;
                        }
                    } else if (group == 0x10000000) {
                        double *s = sources[0];
                        double *d = dst;
                        for (int n = static_cast<int>(elementCount * 2); n != 0; n--) {
                            *reinterpret_cast<uint32_t *>(d) = *reinterpret_cast<uint32_t *>(s);
                            s = reinterpret_cast<double *>(reinterpret_cast<uint8_t *>(s) + 4);
                            d = reinterpret_cast<double *>(reinterpret_cast<uint8_t *>(d) + 4);
                        }
                    } else if (group == 0x10100000) {
                        for (; elementCount != 0; elementCount--) {
                            *dst = -*(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst));
                            dst = dst + 1;
                        }
                    } else if (group == 0x10300000) {
                        for (; elementCount != 0; elementCount--) {
                            *dst = 1.0 / *(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst));
                            dst = dst + 1;
                        }
                    } else if (group == 0x10400000) {
                        intptr_t delta = (intptr_t)dst - (intptr_t)sources[0];
                        double *s = sources[0];
                        for (; elementCount != 0; elementCount--) {
                            double frac = *s - floor(*s);
                            *(double *)(delta + (intptr_t)s) = frac;
                            s = s + 1;
                        }
                    } else if (group == 0x10500000) {
                        for (; elementCount != 0; elementCount--) {
                            *dst = pow(*(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst)),
                                       *sources[0]);
                            dst = dst + 1;
                        }
                    }
                } else if (group == 0x10700000) {
                    for (; elementCount != 0; elementCount--) {
                        *dst = 1.0 / sqrt(fabs(*(double *)((intptr_t)dst +
                                                          ((intptr_t)sources[0] - (intptr_t)dst))));
                        dst = dst + 1;
                    }
                } else if (group == 0x10800000) {
                    for (; elementCount != 0; elementCount--) {
                        *dst = sin(*(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst)));
                        dst = dst + 1;
                    }
                } else if (group == 0x10900000) {
                    for (; elementCount != 0; elementCount--) {
                        *dst = cos(*(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst)));
                        dst = dst + 1;
                    }
                } else if (group == 0x10a00000) {
                    for (; elementCount != 0; elementCount--) {
                        *dst = asin(*(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst)));
                        dst = dst + 1;
                    }
                } else if (group == 0x10b00000) {
                    for (; elementCount != 0; elementCount--) {
                        *dst = acos(*(double *)((intptr_t)dst + ((intptr_t)sources[0] - (intptr_t)dst)));
                        dst = dst + 1;
                    }
                }
            } else if (group < 0x20500001) {
                if (group == 0x20500000) {
                    for (double *s = sources[1]; elementCount != 0; elementCount--) {
                        *(double *)(((intptr_t)dst - (intptr_t)sources[1]) + (intptr_t)s) =
                            *(double *)(((intptr_t)sources[0] - (intptr_t)sources[1]) + (intptr_t)s) * *s;
                        s = s + 1;
                    }
                } else if (group == 0x20000000) {
                    for (double *s = sources[1]; elementCount != 0; elementCount--) {
                        double other = *(double *)((intptr_t)s + ((intptr_t)sources[0] - (intptr_t)sources[1]));
                        double v = (*s <= other) ? *s : other;
                        *(double *)((intptr_t)s + ((intptr_t)dst - (intptr_t)sources[1])) = v;
                        s = s + 1;
                    }
                } else if (group == 0x20100000) {
                    for (double *s = sources[1]; elementCount != 0; elementCount--) {
                        double other = *(double *)((intptr_t)s + ((intptr_t)sources[0] - (intptr_t)sources[1]));
                        double v = (other <= *s) ? *s : other;
                        *(double *)((intptr_t)s + ((intptr_t)dst - (intptr_t)sources[1])) = v;
                        s = s + 1;
                    }
                } else if (group == 0x20200000) {
                    for (double *s = sources[1]; elementCount != 0; elementCount--) {
                        double other = *(double *)((intptr_t)s + ((intptr_t)sources[0] - (intptr_t)sources[1]));
                        uint64_t bits = (*s <= other) ? 0u : 0x3ff0000000000000ull;
                        *reinterpret_cast<uint64_t *>(
                            (intptr_t)s + ((intptr_t)dst - (intptr_t)sources[1])) = bits;
                        s = s + 1;
                    }
                } else if (group == 0x20300000) {
                    for (double *s = sources[1]; elementCount != 0; elementCount--) {
                        double other = *(double *)((intptr_t)s + ((intptr_t)sources[0] - (intptr_t)sources[1]));
                        uint64_t bits = (other < *s) ? 0u : 0x3ff0000000000000ull;
                        *reinterpret_cast<uint64_t *>(
                            (intptr_t)s + ((intptr_t)dst - (intptr_t)sources[1])) = bits;
                        s = s + 1;
                    }
                } else if (group == 0x20400000) {
                    for (double *s = sources[1]; elementCount != 0; elementCount--) {
                        *(double *)((intptr_t)s + ((intptr_t)dst - (intptr_t)sources[1])) =
                            *(double *)(((intptr_t)sources[0] - (intptr_t)sources[1]) + (intptr_t)s) + *s;
                        s = s + 1;
                    }
                }
            } else if (group == 0x20600000) {
                for (double *s = sources[1]; elementCount != 0; elementCount--) {
                    *(double *)((intptr_t)s + ((intptr_t)dst - (intptr_t)sources[1])) =
                        atan2(*(double *)(((intptr_t)sources[0] - (intptr_t)sources[1]) + (intptr_t)s), *s);
                    s = s + 1;
                }
            } else if (group == 0x30000000) {
                // NEEDS_MANUAL: the second bank base (local_418) is a caller
                // stack slot not present in the recovered parameter list.
                for (double *s = sources[1]; elementCount != 0; elementCount--) {
                    double v;
                    if (*(double *)(((intptr_t)sources[0] - (intptr_t)sources[1]) + (intptr_t)s) < 0.0)
                        v = *(double *)((intptr_t)selectBank - (intptr_t)sources[1] + (intptr_t)s);
                    else
                        v = *s;
                    *(double *)((intptr_t)s + ((intptr_t)dst - (intptr_t)sources[1])) = v;
                    s = s + 1;
                }
            } else if (group == 0x50000000) {
                *dst = 0.0;
                if (elementCount != 0) {
                    intptr_t delta = (intptr_t)sources[0] - (intptr_t)sources[1];
                    double *s = sources[1];
                    for (; elementCount != 0; elementCount--) {
                        double *a = reinterpret_cast<double *>(delta + (intptr_t)s);
                        double v = *s;
                        s = s + 1;
                        *dst = *a * v + *dst;
                    }
                }
            } else if (group == 0x50200000) {
                FUN_0060aed0(elementCount, reinterpret_cast<int **>(sources), dst);
            } else if (group == 0x70e00000) {
                *dst = 0.0;
                innerCount = innerCount >> 1;
                for (uint32_t i = 0; i < innerCount; i++)
                    *dst = *sources[i] * *sources[innerCount + i] + *dst;
            }
        }

        pc = pc + 1;
        if (count <= pc)
            return 0;
    } while (true);
}
