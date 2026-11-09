// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
// Band 8 wave2 PNG chunk handlers (lodepng-style, third-party bundled; see REPORT.md).
#include <stddef.h>
#include <stdint.h>
extern void FUN_006565dd(void* dec, const char* msg);
extern void FUN_006565fe(void* dec, const char* msg);
extern void FUN_006935e2(void* dec, void* dst, int len);
extern int FUN_00693ebc(void* dec, unsigned rem);
extern unsigned FUN_0069359e(const void* p);
extern unsigned FUN_006935c8(const unsigned char* p);
extern void* FUN_006924f1(void* dec, unsigned size);
extern void FUN_006568bc(void* dec, void* chunk, unsigned intent);
extern void FUN_006567b1(void* dec, void* chunk, double value);
extern void FUN_00656874(void* dec, void* chunk, void* pal, int count);
extern void FUN_006568f5(void* dec, void* chunk, void* trns, unsigned short len, void* dst);
extern void FUN_006567d1(void* dec, void* chunk, unsigned w, unsigned h, unsigned depth, unsigned color, unsigned interlace, int a, int b);
extern void* FUN_006566b0(void* dec, int n, int stride);

static unsigned state(void* dec) { return *(unsigned*)((char*)dec + 0x58); }

// 0x00693f45 IHDR handler
void FUN_00693f45(int dec, void* chunk, int len) {
    if (*(int*)((char*)dec + 0x58) != 0) FUN_006565dd((void*)dec, "Out of place IHDR");
    if (len != 0xd) FUN_006565dd((void*)dec, "Invalid IHDR chunk");
    *(unsigned*)((char*)dec + 0x58) |= 1;
    unsigned char buf[0xd];
    FUN_006935e2((void*)dec, buf, 0xd);
    FUN_00693ebc((void*)dec, 0);
    unsigned w = FUN_0069359e(buf);
    unsigned h = FUN_0069359e(buf + 4);
    unsigned depth = buf[8], color = buf[9], comp = buf[10], filt = buf[11], inter = buf[12];
    if (w == 0 || w > 0x7fffffffu || h == 0 || h > 0x7fffffffu) FUN_006565dd((void*)dec, "Invalid image size in IHDR");
    if (depth != 1 && depth != 2 && depth != 4 && depth != 8 && depth != 0x10) FUN_006565dd((void*)dec, "Invalid bit depth in IHDR");
    if (color == 1 || color == 5 || color > 6) FUN_006565dd((void*)dec, "Invalid color type in IHDR");
    if ((color == 3 && depth > 8) || ((color == 2 || color == 4 || color == 6) && depth < 8)) FUN_006565dd((void*)dec, "Invalid color type/bit depth combination in IHDR");
    if (inter > 1) FUN_006565dd((void*)dec, "Unknown interlace method in IHDR");
    if (comp != 0) FUN_006565dd((void*)dec, "Unknown compression method in IHDR");
    if (filt != 0) FUN_006565dd((void*)dec, "Unknown filter method in IHDR");
    *(unsigned char*)((char*)dec + 0x113) = (unsigned char)inter;
    *(unsigned*)((char*)dec + 0xb8) = w;
    *(unsigned*)((char*)dec + 0xbc) = h;
    *(unsigned char*)((char*)dec + 0x117) = (unsigned char)depth;
    *(unsigned char*)((char*)dec + 0x116) = (unsigned char)color;
    unsigned channels;
    if (color == 0) channels = 1;
    else if (color == 2) channels = 3;
    else if (color == 4) channels = 2;
    else if (color == 6) channels = 4;
    else channels = 1;
    unsigned bpp = (unsigned char)(channels * depth);
    *(unsigned char*)((char*)dec + 0x11a) = (unsigned char)channels;
    *(unsigned char*)((char*)dec + 0x119) = (unsigned char)bpp;
    *(unsigned*)((char*)dec + 200) = (bpp * w + 7) >> 3;
    FUN_006567d1((void*)dec, chunk, w, h, depth, color, inter, 0, 0);
}

// 0x00694127 PLTE handler
void FUN_00694127(int dec, int chunk, unsigned len) {
    unsigned st = state((void*)dec);
    if ((st & 1) == 0) FUN_006565dd((void*)dec, "Missing IHDR before PLTE");
    if (st & 4) { FUN_006565fe((void*)dec, "Invalid PLTE after IDAT"); FUN_00693ebc((void*)dec, len); return; }
    if (st & 2) { FUN_006565dd((void*)dec, "Duplicate PLTE chunk"); }
    *(unsigned*)((char*)dec + 0x58) |= 2;
    if (len % 3 != 0) {
        if (*(char*)((char*)dec + 0x116) == 3) FUN_006565dd((void*)dec, "Invalid palette chunk");
        FUN_006565fe((void*)dec, "Invalid palette chunk"); FUN_00693ebc((void*)dec, len); return;
    }
    int n = (int)len / 3;
    void* pal = FUN_006566b0((void*)dec, n, 3);
    *(unsigned char*)((char*)dec + 0x5d) |= 0x10;
    unsigned char* out = (unsigned char*)pal + 2;
    for (int i = 0; i < n; ++i) {
        unsigned char rgb[3] = {0};
        FUN_006935e2((void*)dec, rgb, 3);
        out[-2] = rgb[0]; out[-1] = rgb[1]; *out = rgb[2];
        out += 3;
    }
    FUN_00693ebc((void*)dec, 0);
    *(void**)((char*)dec + 0x104) = pal;
    *(unsigned short*)((char*)dec + 0x108) = (unsigned short)n;
    FUN_00656874((void*)dec, (void*)chunk, pal, n);
    if (*(char*)((char*)dec + 0x116) != 3) return;
    if (chunk == 0) return;
    if (((*(unsigned char*)((char*)chunk + 8) & 0x10) == 0)) return;
    if (*(unsigned short*)((char*)dec + 0x108) < *(unsigned short*)((char*)dec + 0x10a)) {
        FUN_006565fe((void*)dec, "Truncating incorrect tRNS chunk length");
        *(unsigned short*)((char*)dec + 0x10a) = *(unsigned short*)((char*)dec + 0x108);
    }
}

// 0x0069428a gAMA handler
void FUN_0069428a(int dec, int chunk, int len) {
    unsigned st = state((void*)dec);
    if ((st & 1) == 0) FUN_006565dd((void*)dec, "Missing IHDR before gAMA");
    const char* err = nullptr;
    if (st & 4) err = "Invalid gAMA after IDAT";
    else {
        if ((st & 2) == 0) {
            if (chunk != 0 && (*(unsigned*)((char*)chunk + 8) & 1) != 0 && ((*(unsigned*)((char*)chunk + 8) & 0x800) == 0)) err = "Duplicate gAMA chunk";
        } else FUN_006565fe((void*)dec, "Out of place gAMA chunk");
        if (!err) {
            if (len == 4) {
                unsigned char buf[4] = {0};
                FUN_006935e2((void*)dec, buf, 4);
                if (FUN_00693ebc((void*)dec, 0) != 0) return;
                unsigned raw = FUN_0069359e(buf);
                if (raw == 0) return;
                float f = (float)raw; if ((int)raw < 0) f += 4.2949673e+09f;
                if (chunk != 0 && (*(unsigned*)((char*)chunk + 8) & 0x800) != 0) {
                    if (500.0f < ((f > 45455.0f) ? (f - 45455.0f) : (45455.0f - f))) { FUN_006565fe((void*)dec, "Ignoring incorrect gAMA value when sRGB is also present"); return; }
                }
                float gamma = f * 1e-05f;
                *(float*)((char*)dec + 0x130) = gamma;
                FUN_006567b1((void*)dec, (void*)chunk, (double)gamma);
                return;
            }
            err = "Incorrect gAMA chunk length";
        }
    }
    FUN_006565fe((void*)dec, err);
    FUN_00693ebc((void*)dec, (unsigned)len);
}

// 0x0069438d sRGB handler
void FUN_0069438d(unsigned dec, int chunk, int len) {
    unsigned st = *(unsigned*)(dec + 0x58);
    if ((st & 1) == 0) FUN_006565dd((void*)dec, "Missing IHDR before sRGB");
    const char* err = nullptr;
    if (st & 4) err = "Invalid sRGB after IDAT";
    else {
        if ((st & 2) == 0) {
            if (chunk != 0 && (*(unsigned char*)(chunk + 9) & 8) != 0) err = "Duplicate sRGB chunk";
        } else FUN_006565fe((void*)dec, "Out of place sRGB chunk");
        if (!err) {
            if (len == 1) {
                unsigned char intent = 0;
                FUN_006935e2((void*)dec, &intent, 1);
                if (FUN_00693ebc((void*)dec, 0) != 0) return;
                unsigned u = intent >> 0; // intent byte is low byte of first long in decomp (observed as param_1>>0x18 high byte); keep simple
                // Pseudocode reads intent as high byte shift; equivalent here is the single byte.
                u = intent;
                if (u > 3) { FUN_006565fe((void*)dec, "Unknown sRGB intent"); return; }
                if (chunk != 0 && (*(unsigned char*)(chunk + 8) & 1) != 0) {
                    float g = *(float*)(dec + 0x130);
                    float d = g * 100000.0f + 0.5f - 45455.0f;
                    if (d < 0) d = -d;
                    if (d > 500.0f) FUN_006565fe((void*)dec, "Ignoring incorrect gAMA value when sRGB is also present");
                }
                FUN_006568bc((void*)dec, (void*)chunk, u);
                return;
            }
            err = "Incorrect sRGB chunk length";
        }
    }
    FUN_006565fe((void*)dec, err);
    FUN_00693ebc((void*)dec, (unsigned)len);
}

// 0x00694471 tRNS handler
void FUN_00694471(int dec, int chunk, unsigned len) {
    if ((*(unsigned*)((char*)dec + 0x58) & 1) == 0) FUN_006565dd((void*)dec, "Missing IHDR before tRNS");
    if ((*(unsigned*)((char*)dec + 0x58) & 4) != 0) { FUN_006565fe((void*)dec, "Invalid tRNS after IDAT"); FUN_00693ebc((void*)dec, len); return; }
    if (chunk != 0 && (*(unsigned char*)((char*)chunk + 8) & 0x10) != 0) { FUN_006565fe((void*)dec, "Duplicate tRNS chunk"); FUN_00693ebc((void*)dec, len); return; }
    char color = *(char*)((char*)dec + 0x116);
    if (color == 3) {
        if ((*(unsigned char*)((char*)dec + 0x58) & 2) == 0) FUN_006565fe((void*)dec, "Missing PLTE before tRNS");
        else if (*(unsigned short*)((char*)dec + 0x108) < len) { FUN_006565fe((void*)dec, "Incorrect tRNS chunk length"); FUN_00693ebc((void*)dec, len); return; }
        if (len == 0) { FUN_006565fe((void*)dec, "Zero length tRNS chunk"); FUN_00693ebc((void*)dec, len); return; }
        void* buf = FUN_006924f1((void*)dec, len);
        *(unsigned char*)((char*)dec + 0x5d) |= 0x20;
        *(void**)((char*)dec + 0x15c) = buf;
        FUN_006935e2((void*)dec, buf, (int)len);
        *(unsigned short*)((char*)dec + 0x10a) = (unsigned short)len;
        if (FUN_00693ebc((void*)dec, 0) == 0) FUN_006568f5((void*)dec, (void*)chunk, *(void**)((char*)dec + 0x15c), *(unsigned short*)((char*)dec + 0x10a), (void*)((char*)dec + 0x160));
        return;
    }
    if (color == 2) {
        if (len != 6) { FUN_006565fe((void*)dec, "Incorrect tRNS chunk length"); FUN_00693ebc((void*)dec, len); return; }
        unsigned char buf[6] = {0};
        FUN_006935e2((void*)dec, buf, 6);
        *(unsigned short*)((char*)dec + 0x10a) = 1;
        *(unsigned short*)((char*)dec + 0x162) = (unsigned short)FUN_006935c8(buf);
        *(unsigned short*)((char*)dec + 0x164) = (unsigned short)FUN_006935c8(buf + 2);
        *(unsigned short*)((char*)dec + 0x166) = (unsigned short)FUN_006935c8(buf + 4);
        if (FUN_00693ebc((void*)dec, 0) == 0) FUN_006568f5((void*)dec, (void*)chunk, *(void**)((char*)dec + 0x15c), *(unsigned short*)((char*)dec + 0x10a), (void*)((char*)dec + 0x160));
        return;
    }
    if (color == 0) {
        if (len != 2) { FUN_006565fe((void*)dec, "Incorrect tRNS chunk length"); FUN_00693ebc((void*)dec, len); return; }
        unsigned char buf[2] = {0};
        FUN_006935e2((void*)dec, buf, 2);
        *(unsigned short*)((char*)dec + 0x10a) = 1;
        *(unsigned short*)((char*)dec + 0x168) = (unsigned short)FUN_006935c8(buf);
        if (FUN_00693ebc((void*)dec, 0) == 0) FUN_006568f5((void*)dec, (void*)chunk, *(void**)((char*)dec + 0x15c), *(unsigned short*)((char*)dec + 0x10a), (void*)((char*)dec + 0x160));
        return;
    }
    FUN_006565fe((void*)dec, "tRNS chunk not allowed with alpha channel");
    FUN_00693ebc((void*)dec, len);
}
