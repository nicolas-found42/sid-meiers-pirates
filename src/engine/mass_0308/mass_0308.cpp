// Reconstruction batch mass_0308.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Candidate definitions for 0x6563a0-0x6568bc (PNG error/chunk/CRC/IHDR helpers
// plus the inline-dispatch message object they embed).
// Translated only from analysis/pseudocode/functions/0x6563a0.c .. 0x6568bc.c.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <csetjmp>

// ---------------------------------------------------------------------------
// Referenced helpers (not part of this batch) and globals.
// ---------------------------------------------------------------------------

// 0x006924f1: allocation helper (png_malloc-shaped: (owner, size) -> memory).
extern void* FUN_006924f1(void* owner, uint32_t size);
// 0x00692491: allocation helper taking a structure kind (0x00692491(2)).
extern void* FUN_00692491(int32_t kind);
// 0x006925a6: CRC accumulator (crc32-shaped: (crc, data, length) -> crc).
extern uint32_t FUN_006925a6(uint32_t crc, const void* data, uint32_t length);

// 0x006edb58: lowercase two-nibble hex digit table used by the chunk-name
// escaper.
extern const char DAT_006edb58[];
// 0x006edb68: eight-byte reference signature compared by FUN_00656662.
extern const uint8_t DAT_006edb68[];
// 0x006ec6d0: table of message format strings; entry 0 is
// "Bogus message code %d".
extern const char* const PTR_s_Bogus_message_code__d_006ec6d0[];

// ---------------------------------------------------------------------------
// Message object used by 0x6563a0/0x6563d0/0x656410/0x6564e0.
//
// The object body carries its own dispatch table in its first five dwords
// (written by FUN_006564e0), and every virtual entry receives a pointer to a
// handle whose first dword points at that body.  Field offsets follow the
// observed accesses.
// ---------------------------------------------------------------------------

struct ReconMessageHandle;

struct ReconMessageArgs {
    int32_t dword[8];    // +0x18: eight sprintf argument slots
    char    text[0x20];  // same bytes; the "%s" path passes their address
};

struct ReconMessageImpl {
    void (*fn_00)(void* self);                     // +0x00  FUN_00656380
    void (*fn_04)(ReconMessageHandle*, int32_t);   // +0x04  FUN_006563d0
    void (*fn_08)(ReconMessageHandle*);            // +0x08  FUN_006563a0
    void (*fn_0c)(ReconMessageHandle*, char*);     // +0x0c  FUN_00656410
    void (*fn_10)(void* self);                     // +0x10  FUN_006564c0
    int32_t  code;                                 // +0x14
    ReconMessageArgs args;                         // +0x18..+0x37
    uint8_t  pad_38[0x30];                         // +0x38..+0x67
    int32_t  limit;                                // +0x68
    int32_t  repeat_count;                         // +0x6c
    const char* const* messages;                   // +0x70
    int32_t  messages_max;                         // +0x74
    const char* const* extra_messages;             // +0x78
    int32_t  extra_low;                            // +0x7c
    int32_t  extra_high;                           // +0x80
};

struct ReconMessageHandle {
    ReconMessageImpl* impl;                        // +0x00
};

extern void FUN_00656380(ReconMessageHandle* self);  // 0x656380
extern void FUN_006564c0(ReconMessageHandle* self);  // 0x6564c0

// ---------------------------------------------------------------------------
// PNG-side types (field offsets are the observed ones; everything not touched
// by this batch is padding).
// ---------------------------------------------------------------------------

struct ReconPngStruct {
    uint8_t  jmpbuf[0x40];                             // +0x000 target jmp_buf
    void (*error_fn)(ReconPngStruct*, const char*);    // +0x040
    void (*warning_fn)(ReconPngStruct*, const char*);  // +0x044
    void*    error_ptr;                                // +0x048
    uint8_t  pad_4c[0x10];                             // +0x04c..+0x05b
    uint32_t flags;                                    // +0x05c
    uint8_t  pad_60[0xa0];                             // +0x060..+0x0ff
    uint32_t crc;                                      // +0x100
    uint8_t  pad_104[0x08];                            // +0x104..+0x10b
    uint8_t  chunk_name[5];                            // +0x10c
};

struct ReconPngInfo {
    uint32_t width;                 // +0x00
    uint32_t height;                // +0x04
    uint32_t valid;                 // +0x08
    uint32_t rowbytes;              // +0x0c
    uint32_t field_10;              // +0x10
    uint16_t field_14;              // +0x14
    uint8_t  pad_16[2];             // +0x16..+0x17
    uint8_t  bit_depth;             // +0x18
    uint8_t  color_type;            // +0x19
    uint8_t  compression_type;      // +0x1a
    uint8_t  filter_type;           // +0x1b
    uint8_t  interlace_type;        // +0x1c
    uint8_t  channels;              // +0x1d
    uint8_t  pixel_depth;           // +0x1e
    uint8_t  pad_1f;                // +0x1f
    uint8_t  pad_20[8];             // +0x20..+0x27
    float    gamma;                 // +0x28
    uint8_t  field_2c;              // +0x2c
    uint8_t  pad_2d[3];             // +0x2d..+0x2f
};

// 0x6563a0 — observed shape: one virtual call through slot +0x0c with a
// 200-byte stack buffer and the handle as argument.
void FUN_006563a0_recon(ReconMessageHandle* self)
{
    uint8_t local_cc[200];

    self->impl->fn_0c(self, reinterpret_cast<char*>(local_cc));
}

// 0x6563d0 — observed shape: range-check the message code against +0x68, emit
// through slot +0x08, and keep a repeat counter at +0x6c for negative codes.
void FUN_006563d0_recon(ReconMessageHandle* self, int32_t param_2)
{
    ReconMessageImpl* impl = self->impl;

    if (param_2 >= 0) {
        if (param_2 <= impl->limit) {
            impl->fn_08(self);
        }
        return;
    }
    if ((impl->repeat_count == 0) || (2 < impl->limit)) {
        impl->fn_08(self);
    }
    impl->repeat_count = impl->repeat_count + 1;
}

// 0x656410 — observed shape: pick a format string for impl->code, falling back
// to table entry 0 when nothing matches, then sprintf either the eight argument
// slots or the "%s" buffer at +0x18.
void FUN_00656410_recon(ReconMessageHandle* self, char* param_2)
{
    ReconMessageImpl* impl = self->impl;
    int32_t code = impl->code;
    const char* fmt;
    bool use_text_arg = false;

    if ((code < 1) || (impl->messages_max < code)) {
        if ((impl->extra_messages != nullptr) &&
            ((impl->extra_low <= code) && (code <= impl->extra_high))) {
            fmt = impl->extra_messages[code - impl->extra_low];
            if (fmt != nullptr) {
                goto have_format;
            }
        }
    }
    else {
        fmt = impl->messages[code];
        if (fmt != nullptr) {
            goto have_format;
        }
    }
    impl->args.dword[0] = code;
    fmt = impl->messages[0];

have_format:
    {
        const char* p = fmt;
        char c = *p;

        for (;;) {
            if (c == '\0') {
                break;
            }
            ++p;
            if (c == '%') {
                if (*p == 's') {
                    use_text_arg = true;
                }
                break;
            }
            c = *p;
        }
    }

    if (use_text_arg) {
        std::sprintf(param_2, fmt, impl->args.text);
    }
    else {
        std::sprintf(param_2, fmt,
                     impl->args.dword[0], impl->args.dword[1],
                     impl->args.dword[2], impl->args.dword[3],
                     impl->args.dword[4], impl->args.dword[5],
                     impl->args.dword[6], impl->args.dword[7]);
    }
}

// 0x6564e0 — observed shape: initialize the dispatch table and every field the
// sibling entries read.
void FUN_006564e0_recon(ReconMessageImpl* self)
{
    self->fn_00 = FUN_00656380;
    self->fn_04 = FUN_006563d0_recon;
    self->fn_08 = FUN_006563a0_recon;
    self->fn_0c = FUN_00656410_recon;
    self->fn_10 = FUN_006564c0;
    self->limit = 0;
    self->repeat_count = 0;
    self->code = 0;
    self->messages = PTR_s_Bogus_message_code__d_006ec6d0;
    self->messages_max = 0x7b;
    self->extra_messages = nullptr;
    self->extra_low = 0;
    self->extra_high = 0;
}

// 0x656533 — observed shape: render the four-byte chunk name at +0x10c into the
// buffer passed in ECX, escaping anything outside [')'..'z'] minus
// ('Z'..'a') as "[xx]", then append ": " and 64 bytes of the message,
// truncated to 63 characters.
void FUN_00656533_recon(char* self, ReconPngStruct* param_1, const void* param_2)
{
    int32_t out = 0;
    int32_t i = 0;
    int32_t last = 0;

    do {
        uint8_t bVar2 = param_1->chunk_name[i];
        uint32_t uVar5 = static_cast<uint32_t>(bVar2);
        ++i;
        if ((uVar5 < 0x29) || (0x7a < uVar5) || ((0x5a < uVar5) && (uVar5 < 0x61))) {
            self[out] = '[';
            self[out + 1] = DAT_006edb58[uVar5 >> 4];
            self[out + 2] = DAT_006edb58[uVar5 & 0xf];
            last = out + 3;
            self[last] = ']';
        }
        else {
            self[out] = static_cast<char>(bVar2);
            last = out;
        }
        out = last + 1;
    } while (i < 4);

    if (param_2 == nullptr) {
        self[out] = '\0';
    }
    else {
        self[out] = ':';
        self[last + 2] = ' ';
        char* dst = self + last + 3;
        std::memcpy(dst, param_2, 0x40);
        dst[0x3f] = '\0';
    }
}

// 0x6565bf — observed shape: install the error pointer plus the error and
// warning callbacks at +0x48, +0x40 and +0x44.
void FUN_006565bf_recon(ReconPngStruct* param_1,
                        void* param_2,
                        void (*param_3)(ReconPngStruct*, const char*),
                        void (*param_4)(ReconPngStruct*, const char*))
{
    param_1->error_ptr = param_2;
    param_1->error_fn = param_3;
    param_1->warning_fn = param_4;
}

// 0x6565dd — observed shape: report through the callback at +0x40 when set,
// then longjmp through the jmp_buf that begins the structure.
void FUN_006565dd_recon(ReconPngStruct* param_1, const char* param_2)
{
    if (param_1->error_fn != nullptr) {
        param_1->error_fn(param_1, param_2);
    }
    longjmp(*reinterpret_cast<jmp_buf*>(param_1->jmpbuf), 1);
}

// 0x6565fe — observed shape: report through the callback at +0x44 when set.
void FUN_006565fe_recon(ReconPngStruct* param_1, const char* param_2)
{
    if (param_1->warning_fn != nullptr) {
        param_1->warning_fn(param_1, param_2);
    }
}

// 0x656619 — observed shape: format the chunk name plus message into an
// 80-byte local and pass it to the non-returning error path.
void FUN_00656619_recon(ReconPngStruct* param_1, const char* param_2)
{
    char local_54[0x50];

    FUN_00656533_recon(local_54, param_1, param_2);
    FUN_006565dd_recon(param_1, local_54);
}

// 0x65663c — observed shape: same formatting, delivered to the warning path.
void FUN_0065663c_recon(ReconPngStruct* param_1, const char* param_2)
{
    char local_54[0x50];

    FUN_00656533_recon(local_54, param_1, param_2);
    FUN_006565fe_recon(param_1, local_54);
}

// 0x656662 — observed shape: compare up to eight bytes at param_2 against the
// signature at 0x006edb68, with memcmp-style result (negative/zero/positive).
int32_t FUN_00656662_recon(const void* param_1, uint32_t param_2, uint32_t param_3)
{
    bool bVar3;
    bool bVar4;
    const uint8_t* pbVar1;
    const uint8_t* pbVar2;

    if (param_3 < 9) {
        if (param_3 == 0) {
            return 0;
        }
    }
    else {
        param_3 = 8;
    }
    if (7 < param_2) {
        return 0;
    }
    if (8 < param_2 + param_3) {
        param_3 = 8 - param_2;
    }
    bVar3 = false;
    bVar4 = true;
    pbVar1 = static_cast<const uint8_t*>(param_1) + param_2;
    pbVar2 = DAT_006edb68 + param_2;
    do {
        if (param_3 == 0) break;
        param_3 = param_3 - 1;
        bVar3 = *pbVar1 < *pbVar2;
        bVar4 = *pbVar1 == *pbVar2;
        pbVar1 = pbVar1 + 1;
        pbVar2 = pbVar2 + 1;
    } while (bVar4);
    if (bVar4) {
        return 0;
    }
    return (1 - static_cast<int32_t>(bVar3)) - static_cast<int32_t>(bVar3 != 0);
}

// 0x6566b0 — observed shape: allocate param_2*param_3 bytes, zero the whole
// block in a 0x8000-byte head plus dword/tail loops, and return the block base.
void* FUN_006566b0_recon(void* param_1, int32_t param_2, int32_t param_3)
{
    uint32_t uVar5 = static_cast<uint32_t>(param_2 * param_3);
    uint32_t* puVar1 = static_cast<uint32_t*>(FUN_006924f1(param_1, uVar5));
    uint32_t* puVar2 = nullptr;

    if (puVar1 != nullptr) {
        if (uVar5 < 0x8001) {
            puVar2 = puVar1;
        }
        else {
            puVar2 = puVar1;
            for (int32_t iVar3 = 0x2000; iVar3 != 0; iVar3 = iVar3 - 1) {
                *puVar2 = 0;
                puVar2 = puVar2 + 1;
            }
            uVar5 = uVar5 - 0x8000;
            puVar2 = puVar1 + 0x2000;
        }
        {
            uint32_t uVar4;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar2 = 0;
                puVar2 = puVar2 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *reinterpret_cast<uint8_t*>(puVar2) = 0;
                puVar2 = reinterpret_cast<uint32_t*>(
                    reinterpret_cast<uint8_t*>(puVar2) + 1);
            }
        }
        puVar2 = puVar1;
    }
    return puVar2;
}

// 0x656711 — observed shape: seed the running CRC at +0x100.
void FUN_00656711_recon(ReconPngStruct* param_1)
{
    param_1->crc = FUN_006925a6(0, nullptr, 0);
}

// 0x65672d — observed shape: leave the CRC alone for chunk kinds excluded by
// the flags at +0x5c/+0x5d, otherwise fold param_2/param_3 into +0x100.
void FUN_0065672d_recon(ReconPngStruct* param_1, const void* param_2, uint32_t param_3)
{
    uint8_t* flag_bytes = reinterpret_cast<uint8_t*>(&param_1->flags);

    if ((param_1->chunk_name[0] & 0x20) == 0) {
        if ((flag_bytes[1] & 8) != 0) {
            return;
        }
    }
    else if ((param_1->flags & 0x300) == 0x300) {
        return;
    }
    param_1->crc = FUN_006925a6(param_1->crc, param_2, param_3);
}

// 0x656784 — observed shape: kind-2 allocation of a 64-byte block, zeroed when
// the allocation succeeds; a null owner yields null.
void* FUN_00656784_recon(void* param_1)
{
    void* puVar1;
    uint32_t* puVar3;

    if (param_1 == nullptr) {
        puVar1 = nullptr;
    }
    else {
        puVar1 = FUN_00692491(2);
        if (puVar1 != nullptr) {
            puVar3 = static_cast<uint32_t*>(puVar1);
            for (int32_t iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 - 1) {
                *puVar3 = 0;
                puVar3 = puVar3 + 1;
            }
        }
    }
    return puVar1;
}

// 0x6567b1 — observed shape: set valid bit 0 at +0x08 and store the gamma as a
// float at +0x28.
void FUN_006567b1_recon(void* param_1, ReconPngInfo* param_2, double param_3)
{
    if ((param_1 != nullptr) && (param_2 != nullptr)) {
        param_2->valid = param_2->valid | 1;
        param_2->gamma = static_cast<float>(param_3);
    }
}

// 0x6567d1 — observed shape: store width/height/bit-depth/colour facts in the
// observed order, derive channels and pixel depth, then compute rowbytes (or
// warn and zero it when the multiplication would overflow 0x7fffffff).
void FUN_006567d1_recon(ReconPngStruct* param_1, ReconPngInfo* param_2,
                        uint32_t param_3, uint32_t param_4,
                        char param_5, uint8_t param_6,
                        uint8_t param_7, uint8_t param_8, uint8_t param_9)
{
    uint8_t bVar1;

    if ((param_1 == nullptr) || (param_2 == nullptr)) {
        return;
    }

    param_2->compression_type = param_8;                     // +0x1a
    param_2->height = param_4;                               // +0x04
    param_2->filter_type = param_9;                          // +0x1b
    param_2->width = param_3;                                // +0x00
    param_2->bit_depth = static_cast<uint8_t>(param_5);      // +0x18 (observed char)
    param_2->color_type = param_6;                           // +0x19
    param_2->interlace_type = param_7;                       // +0x1c

    if ((param_6 == 3) || ((param_6 & 2) == 0)) {
        param_2->channels = 1;                               // +0x1d
    }
    else {
        param_2->channels = 3;
    }
    if ((param_6 & 4) != 0) {
        param_2->channels = static_cast<uint8_t>(param_2->channels + 1);
    }

    bVar1 = static_cast<uint8_t>(static_cast<int32_t>(param_2->channels) *
                                  static_cast<int32_t>(param_5));
    param_2->pixel_depth = bVar1;                            // +0x1e

    if (static_cast<uint32_t>(0x7fffffffull /
            static_cast<uint32_t>((static_cast<int32_t>(bVar1) + 7) >> 3)) < param_3) {
        FUN_006565fe_recon(param_1,
            "Width too large to process image data; rowbytes will overflow.");
        param_2->rowbytes = 0;                               // +0x0c
    }
    else {
        param_2->rowbytes = (static_cast<uint32_t>(bVar1) * param_3 + 7u) >> 3;
    }
}

// 0x656874 — observed shape: set valid bit 3 and store a 32-bit value at +0x10
// and a 16-bit value at +0x14.
void FUN_00656874_recon(void* param_1, ReconPngInfo* param_2,
                        uint32_t param_3, uint16_t param_4)
{
    if ((param_1 != nullptr) && (param_2 != nullptr)) {
        param_2->valid = param_2->valid | 8;
        param_2->field_10 = param_3;
        param_2->field_14 = param_4;
    }
}

// 0x65689c — observed shape: set bit 3 of the second valid byte (+0x09) and
// store the one-byte value at +0x2c.
void FUN_0065689c_recon(void* param_1, ReconPngInfo* param_2, uint8_t param_3)
{
    if ((param_1 != nullptr) && (param_2 != nullptr)) {
        uint8_t* valid_bytes = reinterpret_cast<uint8_t*>(&param_2->valid);
        valid_bytes[1] = static_cast<uint8_t>(valid_bytes[1] | 8);
        param_2->field_2c = param_3;
    }
}

// 0x6568bc — observed shape: apply the sRGB fields, then the fixed gamma whose
// double bits are 0x3fdd1758e0000000 (0x1.d1758e0p-2).
void FUN_006568bc_recon(void* param_1, ReconPngInfo* param_2, uint32_t param_3)
{
    if ((param_1 != nullptr) && (param_2 != nullptr)) {
        FUN_0065689c_recon(param_1, param_2, static_cast<uint8_t>(param_3));
        FUN_006567b1_recon(param_1, param_2, 0x1.d1758e0p-2);
    }
}
