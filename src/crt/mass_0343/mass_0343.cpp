// UNVERIFIED: clean-room reconstruction from Ghidra 12.2 pseudocode (batch mass_0343).
// Target: Sid Meier's Pirates! (2004), PE32 i386. No build or test was run.
#include <cstdint>
#include <cstddef>

// Referenced helpers / globals (declared only; addresses are those named by the listings).
extern void FUN_006a8cb0(void* self);
extern void FUN_006a8cd0(void* self);
extern void FUN_006a8f40(void* self);
extern int  FUN_006923d0(int a, int b);
extern void FUN_00692440(const void* src, void* coefs, int count);
extern void LAB_00520cc0(void);
extern int  FUN_006a9df0(void* bits, unsigned value, int haveBits, int need);
extern unsigned FUN_006a9f10(void* bits, int value, int haveBits, void* table, int need);
extern int  FUN_006aa000(void* self);
extern int  FUN_006aa5f0(void* self);
extern int  FUN_006aa660(void* self, int* planes);
extern int  FUN_006aa890(void* self, int* planes);
extern int  FUN_006aaac0(void* self, int* planes);
extern int  FUN_006aabb0(int* param_1, int* param_2);
extern void FUN_006aa440(int* param_1);
extern int  FUN_006aa070(void* self, int* planes);
extern void FUN_006aaf50(int* param_1);
extern void FUN_006b2300(void);
extern void FUN_006b1e50(void);
extern void FUN_006b1b40(void);
extern void FUN_006b0a20(void);
extern void FUN_006b05e0(void);
extern void FUN_006b0210(void);
extern void FUN_006b13a0(void);
extern void FUN_006b1b00(void);
extern int  DAT_006f3f80[];   // base-of-range table for length codes
extern int  DAT_006f3fc0[];   // offset added below the base of range
extern int  DAT_006f4000[];   // base-of-range table (second decoder bank)
extern int  DAT_006f4040[];   // offset added below the base of range (second bank)
extern int  DAT_006f0b38[];   // zig-zag / natural-order symbol map
extern const short DAT_006f4080[];
extern const double DAT_006f4130[];

// 0x6a9160 — observed shape: tile-row emitter that pumps a virtual row fetch,
// then walks every band and calls the per-band callback table entry 4 + index*4.
int FUN_006a9160(void* self, int* rowBase)
{
    unsigned char* p = (unsigned char*)self;
    int bandBase = *(int*)(intptr_t)(p + 0x1b0);
    int height = *(int*)(intptr_t)(p + 0x144);

    while (*(int*)(intptr_t)(p + 0x94) < *(int*)(intptr_t)(p + 0x9c) ||
           (*(int*)(intptr_t)(p + 0x94) == *(int*)(intptr_t)(p + 0x9c) &&
            *(unsigned*)(intptr_t)(p + 0x98) <= *(unsigned*)(intptr_t)(p + 0xa0))) {
        int* vt = *(int**)(intptr_t)(p + 0x1b8);
        if (((int(*)(void*))(intptr_t)(*vt))(self) == 0)
            return 0;
    }

    int band = *(int*)(intptr_t)(p + 0xdc);
    int index = 0;
    if (0 < *(int*)(intptr_t)(p + 0x24)) {
        unsigned char* rowSrc = (unsigned char*)(intptr_t)(bandBase + 0x48);
        do {
            if (*(int*)(intptr_t)(band + 0x30) != 0) {
                int* api = *(int**)(intptr_t)(p + 4);
                int pitch = *(int*)(intptr_t)(band + 0xc);
                int plane = ((int(*)(void*, int, int, int, int))(intptr_t)api[0x20])(
                    self, *(int*)rowSrc, *(int*)(intptr_t)(p + 0xa0) * pitch, pitch, 0);

                unsigned rows;
                if (*(unsigned*)(intptr_t)(p + 0xa0) < (unsigned)(height - 1) ||
                    (rows = *(unsigned*)(intptr_t)(band + 0x20) % (unsigned)pitch, rows == 0))
                    rows = (unsigned)pitch;

                unsigned char* cbTable = (unsigned char*)*(int*)(intptr_t)(p + 0x1c4);
                void (**cb)(void*, int, int, int, int) =
                    *(void(***)(void*, int, int, int, int))(cbTable + 4 + index * 4);
                int dst = rowBase[index];
                int r = 0;
                if (0 < (int)rows) {
                    unsigned cols = *(unsigned*)(intptr_t)(band + 0x1c);
                    do {
                        int px = *(int*)(intptr_t)(plane + r * 4);
                        int off = 0;
                        unsigned c = 0;
                        if (cols != 0) {
                            do {
                                (*cb)(self, band, px, dst, off);
                                cols = *(unsigned*)(intptr_t)(band + 0x1c);
                                off += *(int*)(intptr_t)(band + 0x24);
                                px += 0x80;
                                c++;
                            } while (c < cols);
                        }
                        dst += *(int*)(intptr_t)(band + 0x24) * 4;
                        r++;
                    } while (r < (int)rows);
                }
            }
            index++;
            rowSrc += 4;
            band += 0x54;
        } while (index < *(int*)(intptr_t)(p + 0x24));
    }

    unsigned v = *(int*)(intptr_t)(p + 0xa0) + 1;
    *(unsigned*)(intptr_t)(p + 0xa0) = v;
    return 4 - (unsigned)(v < *(unsigned*)(intptr_t)(p + 0x144));
}

// 0x6a92e0 — observed shape: lazily allocates a 0x18-stride table and copies five
// words out of each eligible band record; returns 1 only if some word was non-zero.
int FUN_006a92e0(void* self)
{
    unsigned char* p = (unsigned char*)self;
    int state = *(int*)(intptr_t)(p + 0x1b0);
    int copied = 0;
    int any = 0;

    if (*(int*)(intptr_t)(p + 0xe0) != 0 && *(int*)(intptr_t)(p + 0xa4) != 0) {
        if (*(int*)(intptr_t)(state + 0x70) == 0) {
            int* api = *(int**)(intptr_t)(p + 4);
            void* mem = ((void*(*)(void*, int, int))(intptr_t)api[0])(self, 1, *(int*)(intptr_t)(p + 0x24) * 0x18);
            *(void**)(intptr_t)(state + 0x70) = mem;
        }
        int n = *(int*)(intptr_t)(p + 0x24);
        int dst = *(int*)(intptr_t)(state + 0x70);
        if (n < 1)
            return 0;
        int* bandEntry = (int*)(intptr_t)(*(int*)(intptr_t)(p + 0xdc) + 0x4c);
        int idx = 0;
        while (true) {
            short* ps = (short*)(intptr_t)(*bandEntry);
            if (!(ps != 0 && ps[0] != 0 && ps[1] != 0 && ps[8] != 0 && ps[0x10] != 0 &&
                  ps[9] != 0 && ps[2] != 0))
                break;
            int* src = (int*)(intptr_t)(*(int*)(intptr_t)(p + 0xa4) + idx);
            if (*(int*)(intptr_t)(*(int*)(intptr_t)(p + 0xa4) + idx) < 0)
                break;
            intptr_t delta = (intptr_t)dst - (intptr_t)src;
            int k = 5;
            do {
                src++;
                int v = *src;
                *(int*)(intptr_t)(delta + (intptr_t)src) = v;
                if (v != 0)
                    any = 1;
                k--;
            } while (k != 0);
            dst += 0x18;
            copied++;
            idx += 0x100;
            bandEntry += 0x15;
            if (n <= copied)
                return any;
        }
    }
    return 0;
}

// 0x6a9410 — observed shape: two-row interpolating tile emitter. Five optional
// gradient coefficients are produced per pixel from a coefficient block filled by
// FUN_00692440; every write goes through the band callback at 4 + index*4.
int FUN_006a9410(void* self, int* rowBase)
{
    struct CoefBlock {
        uint8_t pad[2];
        int16_t dx;      // +0x02 (local_10a)
        int16_t dy;      // +0x04 (local_108)
        uint8_t gap0[10];
        int16_t d2;      // +0x10 (local_ec)
        int16_t dxy;     // +0x12 (local_fa)
        uint8_t gap1[12];
        int16_t dx2;     // +0x20 (local_108)
    };

    unsigned char* p = (unsigned char*)self;
    unsigned char* bands = (unsigned char*)*(int*)(intptr_t)(p + 0x1b0);
    unsigned last = *(int*)(intptr_t)(p + 0x144) - 1;

    if (*(int*)(intptr_t)(p + 0x94) <= *(int*)(intptr_t)(p + 0x9c)) {
        do {
            int* fetchVt = (int*)*(int*)(intptr_t)(p + 0x1b8);
            if (fetchVt[5] != 0 ||
                (*(int*)(intptr_t)(p + 0x94) == *(int*)(intptr_t)(p + 0x9c) &&
                 (unsigned)(*(int*)(intptr_t)(p + 0x194) == 0) + *(int*)(intptr_t)(p + 0xa0) <
                     *(unsigned*)(intptr_t)(p + 0x98)))
                break;
            if (((int(*)(void*))(intptr_t)(*fetchVt))(self) == 0)
                return 0;
        } while (*(int*)(intptr_t)(p + 0x94) <= *(int*)(intptr_t)(p + 0x9c));
    }

    unsigned char* band = (unsigned char*)*(int*)(intptr_t)(p + 0xdc);
    int bandIndex = 0;
    if (0 < *(int*)(intptr_t)(p + 0x24)) {
        unsigned char* rowSrc = bands + 0x48;
        int slot = 0;
        do {
            if (*(int*)(intptr_t)(band + 0x30) != 0) {
                unsigned rowState = *(unsigned*)(intptr_t)(p + 0xa0);
                unsigned pitch = *(unsigned*)(intptr_t)(band + 0xc);
                int partial;
                unsigned span;
                unsigned nRows;
                if (rowState < last) {
                    partial = 0;
                    span = pitch * 2;
                    nRows = pitch;
                } else {
                    nRows = *(unsigned*)(intptr_t)(band + 0x20) % pitch;
                    if (nRows == 0)
                        nRows = pitch;
                    partial = 1;
                    span = nRows;
                }

                int* api = *(int**)(intptr_t)(p + 4);
                int plane;
                if (rowState == 0) {
                    plane = ((int(*)(void*, int, int, unsigned, int))(intptr_t)api[0x20])(
                        self, *(int*)rowSrc, 0, span, 0);
                } else {
                    plane = ((int(*)(void*, int, int, unsigned, int))(intptr_t)api[0x20])(
                        self, *(int*)rowSrc, (int)((rowState - 1) * pitch), span + pitch);
                    plane += *(int*)(intptr_t)(band + 0xc) * 4;
                }
                unsigned firstRow = (unsigned)(rowState == 0);
                unsigned char* coefBase =
                    (unsigned char*)(intptr_t)(*(int*)(intptr_t)(bands + 0x70) + slot);
                unsigned short* info = *(unsigned short**)(intptr_t)(band + 0x4c);
                unsigned mul = info[0];
                unsigned mulDx = info[1];
                unsigned mulDy = info[8];
                unsigned mulD2 = info[0x10];
                unsigned mulDxy = info[9];
                unsigned mulDx2 = info[2];

                unsigned char* cbTable = (unsigned char*)*(int*)(intptr_t)(p + 0x1c4);
                void (**cb)(void*, void*, void*, int, int) =
                    *(void(***)(void*, void*, void*, int, int))(cbTable + 4 + bandIndex * 4);

                int dst = rowBase[bandIndex];
                int col = 0;
                if (0 < (int)nRows) {
                    do {
                        short* cur = *(short**)(plane + col * 4);
                        short* above = cur;
                        short* nxt = cur;
                        if (firstRow == 0)
                            above = *(short**)(plane - 4 + col * 4);
                        else if (col != 0)
                            above = *(short**)(plane - 4 + col * 4);
                        if (partial == 0)
                            nxt = *(short**)(plane + 4 + col * 4);
                        else if (col != (int)nRows - 1)
                            nxt = *(short**)(plane + 4 + col * 4);

                        int curV0 = (int)*cur;
                        int nextV0 = (int)*nxt;
                        int aboveV0 = (int)*above;
                        unsigned inner = (unsigned)(*(int*)(intptr_t)(band + 0x1c) - 1);
                        nxt += 0x40;
                        above += 0x40;

                        int rowOff = 0;
                        unsigned r = 0;
                        int v38 = curV0;      // previous current-row sample
                        int v20 = curV0;      // current-row sample
                        int v1c = nextV0;     // next-row sample
                        int v18 = aboveV0;    // previous-row sample
                        int v68 = nextV0;     // previous next-row sample
                        int t10 = aboveV0;    // the listing reuses its iVar10 across the last two gradients
                        CoefBlock coef = {};
                        do {
                            int curN = v20;
                            int aboveN = v18;
                            int nextN = v1c;
                            FUN_00692440(cur, &coef, 1);
                            if (r < inner) {
                                aboveN = (int)*above;
                                curN = (int)cur[0x40];
                                nextN = (int)*nxt;
                            }

                            int sel;
                            int prod;
                            int v;

                            sel = *(int*)(intptr_t)(coefBase + 4);
                            if (sel != 0 && coef.dx == 0) {
                                prod = (v38 - curN) * (int)mul * 0x24;
                                if (prod < 0) {
                                    v = (int)((int)mulDx * 0x80 + (-prod)) / (int)(mulDx << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                    v = -v;
                                } else {
                                    v = (int)((int)mulDx * 0x80 + prod) / (int)(mulDx << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                }
                                coef.dx = (int16_t)v;
                            }

                            sel = *(int*)(intptr_t)(coefBase + 8);
                            if (sel != 0 && coef.dy == 0) {
                                prod = (v18 - v1c) * (int)mul * 0x24;
                                if (prod < 0) {
                                    v = (int)((int)mulDy * 0x80 + (-prod)) / (int)(mulDy << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                    v = -v;
                                } else {
                                    v = (int)((int)mulDy * 0x80 + prod) / (int)(mulDy << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                }
                                coef.dy = (int16_t)v;
                            }

                            sel = *(int*)(intptr_t)(coefBase + 0xc);
                            if (sel != 0 && coef.d2 == 0) {
                                int t = (v1c + v20 * -2 + v18) * (int)mul;
                                prod = t * 9;
                                if (prod < 0) {
                                    v = (int)((int)mulD2 * 0x80 + (-prod)) / (int)(mulD2 << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                    v = -v;
                                } else {
                                    v = (int)((int)mulD2 * 0x80 + prod) / (int)(mulD2 << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                }
                                coef.d2 = (int16_t)v;
                            }

                            sel = *(int*)(intptr_t)(coefBase + 0x10);
                            if (sel != 0 && coef.dxy == 0) {
                                int t = (((nextN - v68) - aboveN) + t10) * (int)mul;
                                t10 = t * 5;
                                if (t10 < 0) {
                                    v = (int)((int)mulDxy * 0x80 + (-t10)) / (int)(mulDxy << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                    v = -v;
                                } else {
                                    v = (int)((int)mulDxy * 0x80 + t10) / (int)(mulDxy << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                }
                                coef.dxy = (int16_t)v;
                            }

                            t10 = *(int*)(intptr_t)(coefBase + 0x14);
                            sel = t10;
                            if (sel != 0 && coef.dx2 == 0) {
                                int t = (curN + v20 * -2 + v38) * (int)mul;
                                prod = t * 9;
                                if (prod < 0) {
                                    v = (int)((int)mulDx2 * 0x80 + (-prod)) / (int)(mulDx2 << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                    v = -v;
                                } else {
                                    v = (int)((int)mulDx2 * 0x80 + prod) / (int)(mulDx2 << 8);
                                    if (0 < sel) {
                                        int m = 1 << (sel & 0x1f);
                                        if (m <= v)
                                            v = m - 1;
                                    }
                                }
                                coef.dx2 = (int16_t)v;
                            }

                            (*cb)(self, band, &coef, dst, rowOff);

                            v18 = aboveN;
                            v68 = v1c;
                            v1c = nextN;
                            cur += 0x40;
                            v38 = v20;
                            above += 0x40;
                            nxt += 0x40;
                            rowOff += *(int*)(intptr_t)(band + 0x24);
                            r++;
                            v20 = curN;
                        } while (r <= inner);

                        dst += *(int*)(intptr_t)(band + 0x24) * 4;
                        col++;
                    } while (col < (int)nRows);
                }
            }
            slot += 0x18;
            bandIndex++;
            rowSrc += 4;
            band += 0x54;
        } while (bandIndex < *(int*)(intptr_t)(p + 0x24));
    }

    unsigned v = *(int*)(intptr_t)(p + 0xa0) + 1;
    *(unsigned*)(intptr_t)(p + 0xa0) = v;
    return 4 - (unsigned)(v < *(unsigned*)(intptr_t)(p + 0x144));
}

// 0x6a99b0 — observed shape: selects the row emitter variant and resets the row counter.
void FUN_006a99b0(void* self)
{
    unsigned char* p = (unsigned char*)self;
    int state = *(int*)(intptr_t)(p + 0x1b0);
    if (*(int*)(intptr_t)(state + 0x10) != 0) {
        if (*(int*)(intptr_t)(p + 0x50) != 0) {
            if (FUN_006a92e0(self) != 0) {
                *(void**)(intptr_t)(state + 0xc) = (void*)(intptr_t)FUN_006a9410;
                *(unsigned*)(intptr_t)(p + 0xa0) = 0;
                return;
            }
        }
        *(void**)(intptr_t)(state + 0xc) = (void*)(intptr_t)FUN_006a9160;
    }
    *(unsigned*)(intptr_t)(p + 0xa0) = 0;
}

// 0x6a9a10 — observed shape: allocates the 0x74-byte band state, installs the two
// virtual entries, then either hands out 11 fixed 0x80-byte rows or one surface per band.
void FUN_006a9a10(int param_1, int* param_2)
{
    unsigned char* p = (unsigned char*)param_1;
    int obj = param_1;
    int* api = *(int**)(intptr_t)(p + 4);
    int* state = (int*)(intptr_t)((void*(*)(void*, int, int))(intptr_t)api[0])(p, 1, 0x74);
    *(void**)(intptr_t)(p + 0x1b0) = state;

    state[0] = (int)(intptr_t)FUN_006a8cb0;
    state[2] = (int)(intptr_t)FUN_006a99b0;
    state[0x1c] = 0;

    if (param_2 == 0) {
        int rows = ((int(*)(void*, int, int))(intptr_t)api[1])(p, 1, 0x500);
        state[9] = rows + 0x80;
        state[10] = rows + 0x100;
        state[0xb] = rows + 0x180;
        state[0xc] = rows + 0x200;
        state[0xd] = rows + 0x280;
        state[0xe] = rows + 0x300;
        state[8] = rows;
        state[0xf] = rows + 0x380;
        state[0x10] = rows + 0x400;
        state[0x11] = rows + 0x480;
        state[4] = 0;
        state[1] = (int)(intptr_t)LAB_00520cc0;
        state[3] = (int)(intptr_t)FUN_006a8cd0;
        return;
    }

    int* count = (int*)(intptr_t)(p + 0x24);
    int* bandList = (int*)(intptr_t)(p + 0xdc);
    int index = 0;
    if (0 < *count) {
        int* out = state + 0x12;
        int* band = (int*)(intptr_t)(*bandList + 0xc);
        do {
            int width = *band;
            int stride = width;
            if (*(int*)(intptr_t)(obj + 0xe0) != 0)
                stride = width * 3;
            int a2 = FUN_006923d0(band[5], width);
            int a1 = FUN_006923d0(band[4], band[-1]);
            int plane = ((int(*)(void*, int, int, int, int, int))(intptr_t)api[5])(
                obj, 1, 1, a1, a2, stride);
            *out = plane;
            out++;
            index++;
            band += 0x15;
        } while (index < *(int*)(intptr_t)(obj + 0x24));
    }

    state[1] = (int)(intptr_t)FUN_006a8f40;
    state[3] = (int)(intptr_t)FUN_006a9160;
    state[4] = (int)(intptr_t)(state + 0x12);
}

// 0x6a9b60 — observed shape: builds one 0x590-byte canonical Huffman table from a
// 16-entry code-length run table (mode 0 = literal/length, mode 1 = distance).
void FUN_006a9b60(int* obj, int mode, int slot, int* tableSlot)
{
    int16_t aiStack_520[257];
    char local_11c[260];

    int slotIndex = slot;
    if (slot < 0 || 3 < slot) {
        int* err = (int*)(intptr_t)(*obj);
        err[5] = 0x32;
        err[6] = slot;
         (*(void(**)(int*))(intptr_t)(*err))(obj);
    }

    int src;
    if (mode == 0)
        src = obj[slot + 0x32];
    else
        src = obj[slot + 0x2e];
    if (src == 0) {
        int* err = (int*)(intptr_t)(*obj);
        err[5] = 0x32;
        err[6] = slotIndex;
         (*(void(**)(int*))(intptr_t)(*err))(obj);
    }

    if (*tableSlot == 0) {
        int built = ((int(*)(int*, int, int))(intptr_t)obj[1])(obj, 1, 0x590);
        *tableSlot = built;
    }

    int* tbl = (int*)(intptr_t)(*tableSlot);
    int total = 0;
    for (unsigned char* lenIdx = (unsigned char*)(intptr_t)1; (intptr_t)lenIdx <= 0x10; lenIdx++) {
        unsigned n = lenIdx[src];
        if (0x100 < (int)(n + total)) {
            int* err = (int*)(intptr_t)(*obj);
            err[5] = 8;
             (*(void(**)(int*))(intptr_t)(*err))(obj);
        }
        if (n != 0) {
            char fill = (char)(intptr_t)lenIdx;
            char* dst = local_11c + total;
            for (unsigned q = n >> 2; q != 0; q--) {
                *(uint32_t*)dst = (uint32_t)(unsigned char)fill * 0x01010101u;
                dst += 4;
            }
            for (unsigned q = n & 3; q != 0; q--)
                *dst++ = fill;
            total = total + (int)n;
        }
    }
    local_11c[total] = '\0';
    int savedTotal = total;

    int nextCode = 0;
    int j = 0;
    int curLen = (int)local_11c[0];
    if (local_11c[0] != '\0') {
        char* cp = local_11c;
        do {
            char c = *cp;
            while ((int)c == curLen) {
                c = local_11c[j + 1];
                aiStack_520[j] = (int16_t)nextCode;
                j++;
                nextCode++;
            }
            if (1 << (curLen & 0x1f) <= nextCode) {
                int* err = (int*)(intptr_t)(*obj);
                err[5] = 8;
                 (*(void(**)(int*))(intptr_t)(*err))(obj);
            }
            cp = local_11c + j;
            nextCode <<= 1;
            curLen++;
        } while (local_11c[j] != '\0');
    }

    int codeCount = 0;
    for (int k = 1; k < 0x11; k++) {
        unsigned char b = *(unsigned char*)(intptr_t)(k + src);
        if (b == 0) {
            *(int*)(intptr_t)((unsigned char*)tbl + k * 4) = -1;
        } else {
            *(int*)(intptr_t)((unsigned char*)tbl + 0x48 + k * 4) =
                codeCount - (int)aiStack_520[codeCount];
            codeCount += (int)b;
            *(int*)(intptr_t)((unsigned char*)tbl + k * 4) = (int)aiStack_520[codeCount - 1];
        }
    }
    *(int*)(intptr_t)((unsigned char*)tbl + 0x44) = 0xfffff;
    for (int z = 0; z < 0x100; z++)
        *(int*)(intptr_t)((unsigned char*)tbl + 0x90 + z * 4) = 0;

    int counter = 0;
    int stepIdx = 7;
    for (int sym = 1; sym < 0x11; sym++, stepIdx--) {
        unsigned char bl = *(unsigned char*)(intptr_t)(sym + src);
        if (bl != 0) {
            unsigned char* byteAt = (unsigned char*)(intptr_t)(counter + 0x11 + src);
            int step = 1 << (stepIdx & 0x1f);
            unsigned rem = bl;
            do {
                int off = (int)aiStack_520[counter] << (stepIdx & 0x1f);
                if (0 < step) {
                    unsigned char val = *byteAt;
                    unsigned char* outB = (unsigned char*)(intptr_t)(tbl + 0x490 + off);
                    int* outI = (int*)(intptr_t)((unsigned char*)tbl + 0x90 + off * 4);
                    int n = step;
                    do {
                        *outI++ = sym;
                        *outB++ = val;
                    } while (--n != 0);
                }
                counter++;
                byteAt++;
                rem--;
            } while (rem != 0);
        }
    }

    if (mode != 0) {
        for (int i = 0; i < savedTotal; i++) {
            if (0xf < *(unsigned char*)(intptr_t)(src + 0x11 + i)) {
                int* err = (int*)(intptr_t)(*obj);
                err[5] = 8;
                 (*(void(**)(int*))(intptr_t)(*err))(obj);
            }
        }
    }
}

// 0x6a9df0 — observed shape: byte-wise bit reservoir refill (0xff stuffing aware)
// that tops the reservoir up to 0x19 bits and reports end-of-stream as 0.
int FUN_006a9df0(void* bits, unsigned value, int haveBits, int need)
{
    unsigned* ctx = (unsigned*)bits;
    int* state = (int*)(intptr_t)ctx[4];
    unsigned char* cur = (unsigned char*)(intptr_t)(*ctx);
    int avail = (int)ctx[1];

    int haveSymbol = (state[0x69] != 0);
    if (!haveSymbol) {
        while (haveBits < 0x19) {
            if (avail == 0) {
                avail =  (*(int(**)(int*))(intptr_t)(state[6] + 0xc))(state);
                if (avail == 0)
                    return 0;
                cur = *(unsigned char**)(intptr_t)(state[6]);
                avail = ((unsigned*)(intptr_t)state[6])[1];
            }
            unsigned b = *cur;
            avail--;
            cur++;
            if (b == 0xff) {
                do {
                    if (avail == 0) {
                        avail =  (*(int(**)(int*))(intptr_t)(state[6] + 0xc))(state);
                        if (avail == 0)
                            return 0;
                        cur = *(unsigned char**)(intptr_t)(state[6]);
                        avail = ((unsigned*)(intptr_t)state[6])[1];
                    }
                    b = *cur;
                    avail--;
                    cur++;
                } while (b == 0xff);
                if (b != 0) {
                    state[0x69] = (int)b;
                    haveSymbol = 1;
                    break;
                }
                b = 0xff;
            }
            value = (value << 8) | b;
            haveBits += 8;
        }
    }

    if (haveSymbol) {
        if (haveBits < need) {
            if (*(int*)(intptr_t)(state[0x70] + 8) == 0) {
                int errObj = *state;
                *(unsigned*)(intptr_t)(errObj + 0x14) = 0x75;
                 (*(void(**)(int*, int))(intptr_t)(errObj + 4))(state, -1);
                *(unsigned*)(intptr_t)(state[0x70] + 8) = 1;
            }
            value = value << ((0x19 - haveBits) & 0x1f);
            haveBits = 0x19;
        }
    }

    ctx[1] = (unsigned)avail;
    *ctx = (unsigned)(intptr_t)cur;
    ctx[2] = value;
    ctx[3] = (unsigned)haveBits;
    return 1;
}

// 0x6a9f10 — observed shape: canonical Huffman symbol decode with one extra-bit
// extension for over-long codes; returns 0xffffffff on stream failure.
unsigned FUN_006a9f10(void* bits, int value, int haveBits, void* table, int need)
{
    unsigned char* ctx = (unsigned char*)bits;
    int local_need = need;

    if (haveBits < need) {
        if (FUN_006a9df0(bits, (unsigned)value, haveBits, need) == 0)
            return 0xffffffffu;
        value = *(int*)(intptr_t)(ctx + 8);
        haveBits = *(int*)(intptr_t)(ctx + 0xc);
    }
    haveBits -= need;
    unsigned code = ((unsigned)value >> (haveBits & 0x1f)) & ((1u << (need & 0x1f)) - 1u);

    if (*(int*)(intptr_t)((unsigned char*)table + need * 4) < (int)code) {
        do {
            if (haveBits < 1) {
                if (FUN_006a9df0(bits, (unsigned)value, haveBits, 1) == 0)
                    return 0xffffffffu;
                value = *(int*)(intptr_t)(ctx + 8);
                haveBits = *(int*)(intptr_t)(ctx + 0xc);
            }
            haveBits--;
            code = (code << 1) | (((unsigned)value >> (haveBits & 0x1f)) & 1u);
            need = local_need + 1;
            local_need = need;
        } while (*(int*)(intptr_t)((unsigned char*)table + need * 4) < (int)code);
    }

    *(int*)(intptr_t)(ctx + 8) = value;
    *(int*)(intptr_t)(ctx + 0xc) = haveBits;
    if (need < 0x11) {
        int base = *(int*)(intptr_t)((unsigned char*)table + 0x48 + need * 4);
        int bias = *(int*)(intptr_t)((unsigned char*)table + 0x8c);
        return *(unsigned char*)(intptr_t)(base + bias + 0x11 + (int)code);
    }

    int* state = *(int**)(intptr_t)(ctx + 0x10);
    int errObj = *state;
    *(unsigned*)(intptr_t)(errObj + 0x14) = 0x76;
     (*(void(**)(int*, int))(intptr_t)(errObj + 4))(state, -1);
    return 0;
}

// 0x6aa000 — observed shape: commits the pending fractional-byte count into the
// output position, re-enters the block decoder, then resets the per-symbol accumulators.
// Receiver arrives in ESI in the listing, so it is an explicit parameter here.
int FUN_006aa000(void* self)
{
    unsigned char* s = (unsigned char*)self;
    int window = *(int*)(intptr_t)(s + 0x1bc);
    int dec = *(int*)(intptr_t)(s + 0x1c0);

    *(int*)(intptr_t)(window + 0x18) = *(int*)(intptr_t)(window + 0x18) +
        ((*(int*)(intptr_t)(dec + 0x10) + (*(int*)(intptr_t)(dec + 0x10) >> 0x1f & 7U)) >> 3);
    *(unsigned*)(intptr_t)(dec + 0x10) = 0;

    if ( (*(int(**)(void))(intptr_t)(window + 8))() == 0)
        return 0;

    int count = *(int*)(intptr_t)(s + 0x14c);
    if (0 < count) {
        int* pu = (int*)(intptr_t)(dec + 0x14);
        for (; count != 0; count--)
            *pu++ = 0;
    }
    *(unsigned*)(intptr_t)(dec + 0x24) = *(unsigned*)(intptr_t)(s + 0x118);
    if (*(int*)(intptr_t)(s + 0x1a4) == 0)
        *(unsigned*)(intptr_t)(dec + 8) = 0;
    return 1;
}

// 0x6aa070 — observed shape: literal/length + distance decode of one block into the
// plane array; table-driven with the 0x90/0x490 lookup pair and the 0xf0 run markers.
int FUN_006aa070(void* self, int* planes)
{
    unsigned char* p = (unsigned char*)self;
    int state = *(int*)(intptr_t)(p + 0x1c0);

    if (*(int*)(intptr_t)(p + 0x118) != 0 && *(int*)(intptr_t)(state + 0x24) == 0) {
        if (FUN_006aa000(p) == 0)
            return 0;
    }

    if (*(int*)(intptr_t)(state + 8) == 0) {
        unsigned br[4];
        int acc[4];

        br[0] = **(unsigned**)(intptr_t)(p + 0x18);
        br[1] = (*(unsigned**)(intptr_t)(p + 0x18))[1];
        br[3] = *(unsigned*)(intptr_t)(state + 0x10);
        acc[0] = *(int*)(intptr_t)(state + 0x14);
        acc[1] = *(int*)(intptr_t)(state + 0x18);
        acc[3] = *(int*)(intptr_t)(state + 0x20);
        acc[2] = *(int*)(intptr_t)(state + 0x1c);
        br[2] = *(unsigned*)(intptr_t)(state + 0xc);

        auto decodeSym = [&](int tblBase) -> int {
            if ((int)br[3] < 8) {
                if (FUN_006a9df0(br, br[2], (int)br[3], 0) == 0)
                    return -1;
                if ((int)br[3] < 8)
                    return (int)FUN_006a9f10(br, (int)br[2], (int)br[3],
                                             (void*)(intptr_t)tblBase, 1);
            }
            unsigned code = (br[2] >> (((int)br[3] - 8) & 0x1f)) & 0xffu;
            int nbits = *(int*)(intptr_t)(tblBase + 0x90 + code * 4);
            if (nbits == 0)
                return (int)FUN_006a9f10(br, (int)br[2], (int)br[3],
                                         (void*)(intptr_t)tblBase, 9);
            br[3] -= (unsigned)nbits;
            return *(unsigned char*)(intptr_t)(code + 0x490 + tblBase);
        };

        int idx = 0;
        if (0 < *(int*)(intptr_t)(p + 0x168)) {
            int* order = (int*)(intptr_t)(p + 0x16c);
            int* entry = (int*)(intptr_t)(state + 0x70);
            do {
                int tbl = *entry;
                short* out = *(short**)(planes + idx * 4);
                int tblBase = entry[-10];

                int len = decodeSym(tblBase);
                if (len < 0)
                    return 0;
                unsigned extra = 0;
                if (len != 0) {
                    if ((int)br[3] < len) {
                        if (FUN_006a9df0(br, br[2], (int)br[3], len) == 0)
                            return 0;
                    }
                    br[3] -= (unsigned)len;
                    extra = ((1u << (len & 0x1f)) - 1u) &
                            (br[2] >> (br[3] & 0x1f));
                    if ((int)extra < DAT_006f3f80[len])
                        extra = (unsigned)(DAT_006f3fc0[len] + (int)extra);
                }
                if (entry[10] != 0) {
                    int slot = *order;
                    acc[slot] = acc[slot] + (int)extra;
                    *out = (short)acc[slot];
                }

                int run = 1;
                if (entry[0x14] == 0) {
                    do {
                        int sym = decodeSym(tbl);
                        if (sym < 0)
                            return 0;
                        unsigned nxs = (unsigned)sym & 0xf;
                        if (nxs == 0) {
                            if (sym >> 4 != 0xf)
                                break;
                        } else {
                            if ((int)br[3] < (int)nxs) {
                                if (FUN_006a9df0(br, br[2], (int)br[3], (int)nxs) == 0)
                                    return 0;
                            }
                            br[3] -= nxs;
                        }
                        run = run + (sym >> 4) + 1;
                    } while (run < 0x40);
                } else {
                    do {
                        int sym = decodeSym(tbl);
                        if (sym < 0)
                            return 0;
                        unsigned nxs = (unsigned)sym & 0xf;
                        if (nxs == 0) {
                            if (sym >> 4 != 0xf)
                                break;
                            run += 0xf;
                        } else {
                            int pos = run + (sym >> 4);
                            if ((int)br[3] < (int)nxs) {
                                if (FUN_006a9df0(br, br[2], (int)br[3], (int)nxs) == 0)
                                    return 0;
                            }
                            br[3] -= nxs;
                            unsigned val = ((1u << (nxs & 0x1f)) - 1u) &
                                           (br[2] >> (br[3] & 0x1f));
                            if ((int)val < DAT_006f3f80[nxs])
                                val = (unsigned)(DAT_006f3fc0[nxs] + (int)val);
                            out[DAT_006f0b38[pos]] = (short)val;
                            run = pos;
                        }
                        run++;
                    } while (run < 0x40);
                }

                idx++;
                order++;
                entry++;
            } while (idx < *(int*)(intptr_t)(p + 0x168));
        }

        *(unsigned*)(intptr_t)(*(int*)(intptr_t)(p + 0x18)) = br[0];
        *(unsigned*)(intptr_t)(*(int*)(intptr_t)(p + 0x18) + 4) = br[1];
        *(int*)(intptr_t)(state + 0xc) = (int)br[2];
        *(unsigned*)(intptr_t)(state + 0x10) = br[3];
        *(int*)(intptr_t)(state + 0x14) = acc[0];
        *(int*)(intptr_t)(state + 0x18) = acc[1];
        *(int*)(intptr_t)(state + 0x1c) = acc[2];
        *(int*)(intptr_t)(state + 0x20) = acc[3];
    }

    *(int*)(intptr_t)(state + 0x24) = *(int*)(intptr_t)(state + 0x24) - 1;
    return 1;
}

// 0x6aa440 — observed shape: validates the configured distance/length code windows,
// rebuilds one Huffman table per span, then fills the per-span descriptor arrays.
void FUN_006aa440(int* param_1)
{
    int* obj = param_1;
    int state = param_1[0x70];

    if (param_1[0x65] != 0 || param_1[0x66] != 0x3f ||
        param_1[0x67] != 0 || param_1[0x68] != 0) {
        int errObj = *param_1;
        *(unsigned*)(intptr_t)(errObj + 0x14) = 0x7a;
         (*(void(**)(int*, int))(intptr_t)(errObj + 4))(param_1, -1);
    }

    int i = 0;
    if (0 < param_1[0x53]) {
        int* clear = (int*)(intptr_t)(state + 0x14);
        int* span = param_1 + 0x54;
        do {
            int lit = *(int*)(intptr_t)(*span + 0x14);
            int dist = *(int*)(intptr_t)(*span + 0x18);
            FUN_006a9b60(obj, 1, lit, (int*)(intptr_t)(state + 0x28 + lit * 4));
            FUN_006a9b60(obj, 0, dist, (int*)(intptr_t)(state + 0x38 + dist * 4));
            *clear = 0;
            clear++;
            i++;
            span++;
        } while (i < obj[0x53]);
    }

    int n = obj[0x5a];
    if (0 < n) {
        unsigned* out = (unsigned*)(intptr_t)(state + 0xc0);
        int* sel = obj + 0x5b;
        do {
            int span = obj[*sel + 0x54];
            out[-0x1e] = *(unsigned*)(intptr_t)(state + 0x28 + *(int*)(intptr_t)(span + 0x14) * 4);
            out[-0x14] = *(unsigned*)(intptr_t)(state + 0x38 + *(int*)(intptr_t)(span + 0x18) * 4);
            if (*(int*)(intptr_t)(span + 0x30) == 0) {
                *out = 0;
                out[-10] = 0;
            } else {
                out[-10] = 1;
                *out = (unsigned)(1 < *(int*)(intptr_t)(span + 0x24));
            }
            sel++;
            out++;
            n--;
        } while (n != 0);
    }

    *(unsigned*)(intptr_t)(state + 0x10) = 0;
    *(unsigned*)(intptr_t)(state + 0xc) = 0;
    *(unsigned*)(intptr_t)(state + 8) = 0;
    *(int*)(intptr_t)(state + 0x24) = obj[0x46];
}

// 0x6aa5a0 — observed shape: allocates the 0xe8-byte decoder state and installs
// the reset entry plus the literal/length block decoder.
void FUN_006aa5a0(void* self)
{
    unsigned char* p = (unsigned char*)self;
    int* api = *(int**)(intptr_t)(p + 4);
    int* st = (int*)(intptr_t)((void*(*)(void*, int, int))(intptr_t)api[0])(p, 1, 0xe8);
    st[0] = (int)(intptr_t)FUN_006aa440;
    st[1] = (int)(intptr_t)FUN_006aa070;
    *(void**)(intptr_t)(p + 0x1c0) = st;
    st[0xe] = 0;
    st[10] = 0;
    st[0xf] = 0;
    st[0xb] = 0;
    st[0x10] = 0;
    st[0xc] = 0;
    st[0x11] = 0;
    st[0xd] = 0;
}

// 0x6aa5f0 — observed shape: same pending-fraction commit as 0x6aa000 but for the
// second (distance) decoder state; receiver arrives in EBX in the listing.
int FUN_006aa5f0(void* self)
{
    unsigned char* s = (unsigned char*)self;
    int window = *(int*)(intptr_t)(s + 0x1bc);
    int dec = *(int*)(intptr_t)(s + 0x1c0);

    *(int*)(intptr_t)(window + 0x18) = *(int*)(intptr_t)(window + 0x18) +
        ((*(int*)(intptr_t)(dec + 0x10) + (*(int*)(intptr_t)(dec + 0x10) >> 0x1f & 7U)) >> 3);
    *(unsigned*)(intptr_t)(dec + 0x10) = 0;

    if ( (*(int(**)(void))(intptr_t)(window + 8))() == 0)
        return 0;

    int count = *(int*)(intptr_t)(s + 0x14c);
    if (0 < count) {
        int* pu = (int*)(intptr_t)(dec + 0x18);
        for (; count != 0; count--)
            *pu++ = 0;
    }
    *(unsigned*)(intptr_t)(dec + 0x28) = *(unsigned*)(intptr_t)(s + 0x118);
    *(unsigned*)(intptr_t)(dec + 0x14) = 0;
    if (*(int*)(intptr_t)(s + 0x1a4) == 0)
        *(unsigned*)(intptr_t)(dec + 8) = 0;
    return 1;
}

// 0x6aa660 — observed shape: distance-code decode of one block; each symbol index
// is shifted by the observed 0x1a0 shift and accumulated per span.
int FUN_006aa660(void* self, int* planes)
{
    unsigned char* p = (unsigned char*)self;
    unsigned shift = *(unsigned*)(intptr_t)(p + 0x1a0);
    int state = *(int*)(intptr_t)(p + 0x1c0);

    if (*(int*)(intptr_t)(p + 0x118) != 0 && *(int*)(intptr_t)(state + 0x28) == 0) {
        if (FUN_006aa5f0(p) == 0)
            return 0;
    }

    if (*(int*)(intptr_t)(state + 8) == 0) {
        unsigned br[4];
        int acc[4];

        br[0] = **(unsigned**)(intptr_t)(p + 0x18);
        br[1] = (*(unsigned**)(intptr_t)(p + 0x18))[1];
        unsigned saved = *(unsigned*)(intptr_t)(state + 0x14);
        acc[0] = *(int*)(intptr_t)(state + 0x18);
        acc[1] = *(int*)(intptr_t)(state + 0x1c);
        acc[3] = *(int*)(intptr_t)(state + 0x24);
        br[3] = *(unsigned*)(intptr_t)(state + 0x10);
        acc[2] = *(int*)(intptr_t)(state + 0x20);
        br[2] = *(unsigned*)(intptr_t)(state + 0xc);

        auto decodeSym = [&](int tblBase) -> int {
            if ((int)br[3] < 8) {
                if (FUN_006a9df0(br, br[2], (int)br[3], 0) == 0)
                    return -1;
                if ((int)br[3] < 8)
                    return (int)FUN_006a9f10(br, (int)br[2], (int)br[3],
                                             (void*)(intptr_t)tblBase, 1);
            }
            unsigned code = (br[2] >> (((int)br[3] - 8) & 0x1f)) & 0xffu;
            int nbits = *(int*)(intptr_t)(tblBase + 0x90 + code * 4);
            if (nbits == 0)
                return (int)FUN_006a9f10(br, (int)br[2], (int)br[3],
                                         (void*)(intptr_t)tblBase, 9);
            br[3] -= (unsigned)nbits;
            return *(unsigned char*)(intptr_t)(code + 0x490 + tblBase);
        };

        int idx = 0;
        if (0 < *(int*)(intptr_t)(p + 0x168)) {
            int* order = (int*)(intptr_t)(p + 0x16c);
            do {
                short* out = *(short**)(planes + idx * 4);
                int bandIndex = *order;
                int tblBase = *(int*)(intptr_t)(state + 0x2c +
                    *(int*)(intptr_t)(*(int*)(intptr_t)(p + 0x150 + bandIndex * 4) + 0x14) * 4);

                int sym = decodeSym(tblBase);
                if (sym < 0)
                    return 0;

                unsigned extra = 0;
                if (sym != 0) {
                    if ((int)br[3] < sym) {
                        if (FUN_006a9df0(br, br[2], (int)br[3], sym) == 0)
                            return 0;
                    }
                    br[3] -= (unsigned)sym;
                    extra = ((1u << (sym & 0x1f)) - 1u) &
                            (br[2] >> (br[3] & 0x1f));
                    if ((int)extra < DAT_006f4000[sym])
                        extra = (unsigned)(DAT_006f4040[sym] + (int)extra);
                }

                int prev = acc[bandIndex];
                acc[bandIndex] = prev + (int)extra;
                order++;
                *out = (short)((prev + (int)extra) << (shift & 0x1f));
                idx++;
            } while (idx < *(int*)(intptr_t)(p + 0x168));
        }

        *(unsigned*)(intptr_t)(*(int*)(intptr_t)(p + 0x18)) = br[0];
        *(unsigned*)(intptr_t)(*(int*)(intptr_t)(p + 0x18) + 4) = br[1];
        *(unsigned*)(intptr_t)(state + 0x10) = br[3];
        *(unsigned*)(intptr_t)(state + 0x14) = saved;
        *(int*)(intptr_t)(state + 0x18) = acc[0];
        *(int*)(intptr_t)(state + 0xc) = (int)br[2];
        *(int*)(intptr_t)(state + 0x1c) = acc[1];
        *(int*)(intptr_t)(state + 0x20) = acc[2];
        *(int*)(intptr_t)(state + 0x24) = acc[3];
    }

    *(int*)(intptr_t)(state + 0x28) = *(int*)(intptr_t)(state + 0x28) - 1;
    return 1;
}

// 0x6aa890 — observed shape: alternating zero-run extension inside a span; the
// 0xf0 marker drives (1<<n) runs and each following item is written zig-zag decoded.
int FUN_006aa890(void* self, int* planes)
{
    unsigned char* p = (unsigned char*)self;
    int runLimit = *(int*)(intptr_t)(p + 0x198);
    int state = *(int*)(intptr_t)(p + 0x1c0);
    unsigned shift = *(unsigned*)(intptr_t)(p + 0x1a0);

    if (*(int*)(intptr_t)(p + 0x118) != 0 && *(int*)(intptr_t)(state + 0x28) == 0) {
        if (FUN_006aa5f0(p) == 0)
            return 0;
    }

    if (*(int*)(intptr_t)(state + 8) == 0) {
        int runStart;
        if (*(int*)(intptr_t)(state + 0x14) == 0) {
            unsigned br[4];

            br[0] = **(unsigned**)(intptr_t)(p + 0x18);
            int base = *planes;
            br[1] = (*(unsigned**)(intptr_t)(p + 0x18))[1];
            br[2] = *(unsigned*)(intptr_t)(state + 0xc);
            br[3] = *(unsigned*)(intptr_t)(state + 0x10);
            int tblBase = *(int*)(intptr_t)(state + 0x3c);
            int pos = *(int*)(intptr_t)(p + 0x194);
            runStart = 0;

            auto decodeSym = [&](int tbl) -> int {
                if ((int)br[3] < 8) {
                    if (FUN_006a9df0(br, br[2], (int)br[3], 0) == 0)
                        return -1;
                    if ((int)br[3] < 8)
                        return (int)FUN_006a9f10(br, (int)br[2], (int)br[3],
                                                 (void*)(intptr_t)tbl, 1);
                }
                unsigned code = (br[2] >> (((int)br[3] - 8) & 0x1f)) & 0xffu;
                int nbits = *(int*)(intptr_t)(tbl + 0x90 + code * 4);
                if (nbits == 0)
                    return (int)FUN_006a9f10(br, (int)br[2], (int)br[3],
                                             (void*)(intptr_t)tbl, 9);
                br[3] -= (unsigned)nbits;
                return *(unsigned char*)(intptr_t)(code + 0x490 + tbl);
            };

            if (pos <= runLimit) {
                do {
                    int sym = decodeSym(tblBase);
                    if (sym < 0)
                        return 0;
                    int high = sym >> 4;
                    unsigned n = (unsigned)sym & 0xf;
                    if (n == 0) {
                        if (high != 0xf) {
                            int v = 1 << (high & 0x1f);
                            if (high != 0) {
                                if ((int)br[3] < high) {
                                    if (FUN_006a9df0(br, br[2], (int)br[3], high) == 0)
                                        return 0;
                                }
                                br[3] -= (unsigned)high;
                                v = v + (int)((br[2] >> (br[3] & 0x1f)) &
                                              (unsigned)(v - 1));
                            }
                            runStart = v - 1;
                            break;
                        }
                        pos += 0xf;
                    } else {
                        pos += high;
                        if ((int)br[3] < (int)n) {
                            if (FUN_006a9df0(br, br[2], (int)br[3], (int)n) == 0)
                                return 0;
                        }
                        br[3] -= n;
                        unsigned val = ((1u << (n & 0x1f)) - 1u) &
                                       (br[2] >> (br[3] & 0x1f));
                        if ((int)val < DAT_006f4000[n])
                            val = (unsigned)(DAT_006f4040[n] + (int)val);
                        *(short*)(intptr_t)(base + DAT_006f0b38[pos] * 2) =
                            (short)(val << (shift & 0x1f));
                    }
                    pos++;
                } while (pos <= runLimit);
            }

            *(unsigned*)(intptr_t)(*(int*)(intptr_t)(p + 0x18)) = br[0];
            *(unsigned*)(intptr_t)(*(int*)(intptr_t)(p + 0x18) + 4) = br[1];
            *(int*)(intptr_t)(state + 0xc) = (int)br[2];
            *(unsigned*)(intptr_t)(state + 0x10) = br[3];
        } else {
            runStart = *(int*)(intptr_t)(state + 0x14) - 1;
        }
        *(int*)(intptr_t)(state + 0x14) = runStart;
    }

    *(int*)(intptr_t)(state + 0x28) = *(int*)(intptr_t)(state + 0x28) - 1;
    return 1;
}

// 0x6aaac0 — observed shape: single extra bit per span entry, OR-ed in as the
// low flag bit (mask 1 << shift from 0x1a0).
int FUN_006aaac0(void* self, int* planes)
{
    unsigned char* p = (unsigned char*)self;
    unsigned flag = 1u << (*(unsigned*)(intptr_t)(p + 0x1a0) & 0x1f);
    int state = *(int*)(intptr_t)(p + 0x1c0);

    if (*(int*)(intptr_t)(p + 0x118) != 0 && *(int*)(intptr_t)(state + 0x28) == 0) {
        if (FUN_006aa5f0(p) == 0)
            return 0;
    }

    unsigned br[4];
    br[0] = **(unsigned**)(intptr_t)(p + 0x18);
    br[1] = (*(unsigned**)(intptr_t)(p + 0x18))[1];
    br[2] = *(unsigned*)(intptr_t)(state + 0xc);
    br[3] = *(unsigned*)(intptr_t)(state + 0x10);

    int idx = 0;
    if (0 < *(int*)(intptr_t)(p + 0x168)) {
        do {
            unsigned short* cell = *(unsigned short**)(intptr_t)(planes + idx * 4);
            if ((int)br[3] < 1) {
                if (FUN_006a9df0(br, br[2], (int)br[3], 1) == 0)
                    return 0;
            }
            br[3] -= 1;
            if (((br[2] >> (br[3] & 0x1f)) & 1u) != 0)
                *cell = (unsigned short)(*cell | flag);
            idx++;
        } while (idx < *(int*)(intptr_t)(p + 0x168));
    }

    *(unsigned*)(intptr_t)(*(int*)(intptr_t)(p + 0x18)) = br[0];
    *(unsigned*)(intptr_t)(*(int*)(intptr_t)(p + 0x18) + 4) = br[1];
    *(int*)(intptr_t)(state + 0xc) = (int)br[2];
    *(int*)(intptr_t)(state + 0x28) = *(int*)(intptr_t)(state + 0x28) - 1;
    *(unsigned*)(intptr_t)(state + 0x10) = br[3];
    return 1;
}

// 0x6aabb0 — observed shape: sign/zero-run extension over the symbol window; the
// 0xf0 marker expands to a 1<<n run and a per-entry bit selects +step or -step.
int FUN_006aabb0(int* param_1, int* param_2)
{
    int last = param_1[0x66];
    int plus = 1 << (param_1[0x68] & 0x1f);
    int state = param_1[0x70];
    int minus = -1 << (param_1[0x68] & 0x1f);

    if (param_1[0x46] != 0 && *(int*)(intptr_t)(state + 0x28) == 0) {
        if (FUN_006aa5f0(param_1) == 0)
            return 0;
    }

    if (*(int*)(intptr_t)(state + 8) == 0) {
        int saved0 = *(int*)(intptr_t)param_1[6];
        int saved1 = ((int*)(intptr_t)param_1[6])[1];
        unsigned br[4];
        int changed[64];

        int base = *param_2;
        int repCount = *(int*)(intptr_t)(state + 0x14);
        int tbl = *(int*)(intptr_t)(state + 0x3c);
        br[2] = *(unsigned*)(intptr_t)(state + 0xc);
        br[3] = *(unsigned*)(intptr_t)(state + 0x10);
        int pos = param_1[0x65];
        int nChanged = 0;

        auto decodeSym = [&](int tblBase) -> int {
            if ((int)br[3] < 8) {
                if (FUN_006a9df0(br, br[2], (int)br[3], 0) == 0)
                    return -1;
                if ((int)br[3] < 8)
                    return (int)FUN_006a9f10(br, (int)br[2], (int)br[3],
                                             (void*)(intptr_t)tblBase, 1);
            }
            unsigned code = (br[2] >> (((int)br[3] - 8) & 0x1f)) & 0xffu;
            int nbits = *(int*)(intptr_t)(tblBase + 0x90 + code * 4);
            if (nbits == 0)
                return (int)FUN_006a9f10(br, (int)br[2], (int)br[3],
                                         (void*)(intptr_t)tblBase, 9);
            br[3] -= (unsigned)nbits;
            return *(unsigned char*)(intptr_t)(code + 0x490 + tblBase);
        };

        int tail = (repCount != 0);
        if (!tail) {
            if (pos <= last) {
                do {
                    int sym = decodeSym(tbl);
                    if (sym < 0)
                        return 0;
                    int high = sym >> 4;
                    unsigned n = (unsigned)sym & 0xf;
                    int reps = high;
                    int value = 0;

                    if (n == 0) {
                        if (high != 0xf) {
                            int v = 1 << (high & 0x1f);
                            repCount = v;
                            if (high != 0) {
                                if ((int)br[3] < high) {
                                    if (FUN_006a9df0(br, br[2], (int)br[3], high) == 0)
                                        return 0;
                                }
                                br[3] -= (unsigned)high;
                                repCount = v + (int)((br[2] >> (br[3] & 0x1f)) &
                                                     (unsigned)(v - 1));
                            }
                            tail = 1;
                            break;
                        }
                        value = 0;
                    } else {
                        if (n != 1) {
                            int errObj = *param_1;
                            *(unsigned*)(intptr_t)(errObj + 0x14) = 0x76;
                             (*(void(**)(int*, int))(intptr_t)(errObj + 4))(param_1, -1);
                        }
                        if ((int)br[3] < 1) {
                            if (FUN_006a9df0(br, br[2], (int)br[3], 1) == 0)
                                return 0;
                        }
                        br[3] -= 1;
                        value = ((br[2] >> (br[3] & 0x1f)) & 1u) == 0 ? minus : plus;
                    }

                    do {
                        short* cell = (short*)(intptr_t)(base + DAT_006f0b38[pos] * 2);
                        if (*(short*)(intptr_t)(base + DAT_006f0b38[pos] * 2) == 0) {
                            reps--;
                            if (reps < 0)
                                break;
                        } else {
                            if ((int)br[3] < 1) {
                                if (FUN_006a9df0(br, br[2], (int)br[3], 1) == 0)
                                    return 0;
                            }
                            br[3] -= 1;
                            if (((br[2] >> (br[3] & 0x1f)) & 1u) != 0 &&
                                (plus & (int)*cell) == 0) {
                                short s = *cell;
                                if (s < 0)
                                    *cell = (short)(s + (short)minus);
                                else
                                    *cell = (short)(s + (short)plus);
                            }
                        }
                        pos++;
                    } while (pos <= last);

                    if (value != 0) {
                        int mapped = DAT_006f0b38[pos];
                        *(short*)(intptr_t)(base + mapped * 2) = (short)value;
                        changed[nChanged] = mapped;
                        nChanged++;
                    }
                    pos++;
                } while (pos <= last);
            }
        }

        if (tail) {
            if (repCount != 0) {
                if (pos <= last) {
                    do {
                        short* cell = (short*)(intptr_t)(base + DAT_006f0b38[pos] * 2);
                        if (*(short*)(intptr_t)(base + DAT_006f0b38[pos] * 2) != 0) {
                            if ((int)br[3] < 1) {
                                if (FUN_006a9df0(br, br[2], (int)br[3], 1) == 0) {
                                    for (; 0 < nChanged; nChanged--)
                                        *(short*)(intptr_t)(base +
                                            changed[nChanged - 1] * 2) = 0;
                                    return 0;
                                }
                            }
                            br[3] -= 1;
                            if (((br[2] >> (br[3] & 0x1f)) & 1u) != 0 &&
                                (plus & (int)*cell) == 0) {
                                int step = plus;
                                if (*cell < 0)
                                    step = minus;
                                *cell = (short)(*cell + (short)step);
                            }
                        }
                        pos++;
                    } while (pos <= last);
                }
                repCount--;
            }
        }

        *(int*)(intptr_t)param_1[6] = saved0;
        *(int*)(intptr_t)(param_1[6] + 4) = saved1;
        *(int*)(intptr_t)(state + 0xc) = (int)br[2];
        *(unsigned*)(intptr_t)(state + 0x10) = br[3];
        *(int*)(intptr_t)(state + 0x14) = repCount;
    }

    *(int*)(intptr_t)(state + 0x28) = *(int*)(intptr_t)(state + 0x28) - 1;
    return 1;
}

// 0x6aaf50 — observed shape: validates the code windows, stamps the per-span
// selector into the 0x29 window, then (re)builds tables and picks the block decoder.
void FUN_006aaf50(int* param_1)
{
    int first = param_1[0x65];
    int last = param_1[0x66];
    int haveFirst = first != 0;
    int state = param_1[0x70];
    int bad = 0;

    if (haveFirst) {
        if (last < first || 0x3f < last)
            bad = 1;
    }
    if (!(haveFirst ? (param_1[0x53] == 1) : (last == 0)))
        bad = 1;

    int sel = param_1[0x67];
    if (sel != 0 && param_1[0x68] != sel - 1)
        bad = 1;

    if (0xd < param_1[0x68] || bad) {
        int errObj = *param_1;
        *(unsigned*)(intptr_t)(errObj + 0x14) = 0x10;
        *(int*)(intptr_t)(errObj + 0x18) = first;
        *(int*)(intptr_t)(errObj + 0x1c) = last;
        *(int*)(intptr_t)(errObj + 0x20) = sel;
        *(int*)(intptr_t)(errObj + 0x24) = param_1[0x68];
         (*(void(**)(int*))(intptr_t)errObj)(param_1);
    }

    int n = param_1[0x53];
    int i = 0;
    if (0 < n) {
        int* span = param_1 + 0x54;
        do {
            int dist = *(int*)(intptr_t)(*span + 4);
            int* window = (int*)(intptr_t)(dist * 0x100 + param_1[0x29]);
            if (haveFirst && *window < 0) {
                int errObj = *param_1;
                *(unsigned*)(intptr_t)(errObj + 0x14) = 0x73;
                *(int*)(intptr_t)(errObj + 0x18) = dist;
                *(int*)(intptr_t)(errObj + 0x1c) = 0;
                 (*(void(**)(int*, int))(intptr_t)(errObj + 4))(param_1, -1);
            }
            int k = param_1[0x65];
            if (k <= param_1[0x66]) {
                do {
                    int cur = window[k];
                    if (param_1[0x67] != (cur & ((cur < 0) - 1))) {
                        int errObj = *param_1;
                        *(unsigned*)(intptr_t)(errObj + 0x14) = 0x73;
                        *(int*)(intptr_t)(errObj + 0x18) = dist;
                        *(int*)(intptr_t)(errObj + 0x1c) = k;
                         (*(void(**)(int*, int))(intptr_t)(errObj + 4))(param_1, -1);
                    }
                    window[k] = param_1[0x68];
                    k++;
                } while (k <= param_1[0x66]);
            }
            i++;
            span++;
        } while (i < param_1[0x53]);
    }

    if (param_1[0x67] == 0) {
        if (haveFirst)
            *(void**)(intptr_t)(state + 4) = (void*)(intptr_t)FUN_006aa890;
        else
            *(void**)(intptr_t)(state + 4) = (void*)(intptr_t)FUN_006aa660;
    } else if (haveFirst) {
        *(void**)(intptr_t)(state + 4) = (void*)(intptr_t)FUN_006aabb0;
    } else {
        *(void**)(intptr_t)(state + 4) = (void*)(intptr_t)FUN_006aaac0;
    }

    i = 0;
    if (0 < param_1[0x53]) {
        int* clear = (int*)(intptr_t)(state + 0x18);
        int* span = param_1 + 0x54;
        do {
            if (haveFirst) {
                int dist = *(int*)(intptr_t)(*span + 0x18);
                int* dst = (int*)(intptr_t)(state + 0x2c + dist * 4);
                FUN_006a9b60(param_1, 0, dist, dst);
                *(int*)(intptr_t)(state + 0x3c) = *dst;
            } else if (param_1[0x67] == 0) {
                int lit = *(int*)(intptr_t)(*span + 0x14);
                FUN_006a9b60(param_1, 1, lit, (int*)(intptr_t)(state + 0x2c + lit * 4));
            }
            *clear = 0;
            clear++;
            i++;
            span++;
        } while (i < param_1[0x53]);
    }

    *(unsigned*)(intptr_t)(state + 0x10) = 0;
    *(unsigned*)(intptr_t)(state + 0xc) = 0;
    *(unsigned*)(intptr_t)(state + 8) = 0;
    *(unsigned*)(intptr_t)(state + 0x14) = 0;
    *(int*)(intptr_t)(state + 0x28) = param_1[0x46];
}

// 0x6ab1a0 — observed shape: allocates the 0x40-byte transform state and the
// per-band 0x100-int selector window (filled with -1), then installs the reset entry.
void FUN_006ab1a0(void* self)
{
    unsigned char* p = (unsigned char*)self;
    int* api = *(int**)(intptr_t)(p + 4);
    int count = *(int*)(intptr_t)(p + 0x24);
    int* st = (int*)(intptr_t)((void*(*)(void*, int, int))(intptr_t)api[0])(p, 1, 0x40);
    *st = (int)(intptr_t)FUN_006aaf50;
    *(void**)(intptr_t)(p + 0x1c0) = st;
    st[0xb] = 0;
    st[0xc] = 0;
    st[0xd] = 0;
    st[0xe] = 0;

    int* window = (int*)(intptr_t)((void*(*)(void*, int, int))(intptr_t)api[0])(p, 1, count << 8);
    *(void**)(intptr_t)(p + 0xa4) = window;
    if (0 < (int)*(unsigned*)(intptr_t)(p + 0x24)) {
        for (unsigned k = (*(unsigned*)(intptr_t)(p + 0x24) & 0xffffffu) << 6; k != 0; k--) {
            *window = -1;
            window++;
        }
    }
}

// 0x6ab210 — observed shape: per-span frequency-domain setup. The gain code picks
// the block transform and the cached variant is rebuilt when it changes.
void FUN_006ab210(int* param_1)
{
    int idx = 0;

    if (0 < param_1[9]) {
        int* g = (int*)(intptr_t)(param_1[0x37] + 0x24);
        int* cache = (int*)(intptr_t)(param_1[0x71] + 0x2c);
        do {
            int errCode = -1;
            int errArg = 0;
            void (*fn)(void) = 0;
            int variant = 0;
            int seen = 0;

            switch (g[0]) {
            case 1:
                variant = 0;
                fn = FUN_006b2300;
                seen = 0;
                break;
            case 2:
                variant = 0;
                fn = FUN_006b1e50;
                seen = 0;
                break;
            case 4:
                variant = 0;
                fn = FUN_006b1b40;
                seen = 0;
                break;
            case 8:
                switch (param_1[0x12]) {
                case 0:
                    variant = 0;
                    fn = FUN_006b0a20;
                    seen = 0;
                    break;
                case 1:
                case 4:
                case 6:
                    variant = 1;
                    fn = FUN_006b05e0;
                    seen = 1;
                    break;
                case 2:
                    variant = 2;
                    fn = FUN_006b0210;
                    seen = 2;
                    break;
                case 3:
                    variant = 0;
                    fn = FUN_006b13a0;
                    seen = 0;
                    break;
                case 5:
                    variant = 0;
                    fn = FUN_006b1b00;
                    seen = 0;
                    break;
                default:
                    errCode = 0x30;
                    break;
                }
                break;
            default:
                errCode = 7;
                errArg = g[0];
                break;
            }

            if (errCode >= 0) {
                int errObj = *param_1;
                *(unsigned*)(intptr_t)(errObj + 0x14) = (unsigned)errCode;
                *(int*)(intptr_t)(errObj + 0x18) = errArg;
                 (*(void(**)(int*))(intptr_t)errObj)(param_1);
            }

            cache[-10] = (int)(intptr_t)fn;

            unsigned short* src = (unsigned short*)(intptr_t)g[10];
            if (g[3] != 0 && *cache != variant && src != 0) {
                *cache = variant;
                if (variant == 0) {
                    unsigned short* dstS = (unsigned short*)(intptr_t)g[0xb];
                    for (int k = 0; k < 0x40; k++)
                        dstS[k] = src[k];
                } else if (variant == 1) {
                    // dest[k] = (coef[k] * (unsigned short)src[k] + 0x800) >> 12; 0x40 taps.
                    short* dstS = (short*)(intptr_t)g[0xb];
                    for (int k = 0; k < 0x40; k++) {
                        int prod = (int)DAT_006f4080[k] * (int)src[k] + 0x800;
                        dstS[k] = (short)(prod >> 0xc);
                    }
                } else if (variant == 2) {
                    float* dstF = (float*)(intptr_t)g[0xb];
                    for (int k = 0; k < 8; k++) {
                        double scale = DAT_006f4130[k];
                        dstF[0] = (float)src[0] * (float)scale;
                        dstF[1] = (float)src[1] * (float)scale * 1.3870399;
                        dstF[2] = (float)src[2] * (float)scale * 1.306563;
                        dstF[3] = (float)src[3] * (float)scale * 1.1758755;
                        dstF[4] = (float)src[4] * (float)scale;
                        dstF[5] = (float)src[5] * (float)scale * 0.78569496;
                        dstF[6] = (float)src[6] * (float)scale * 0.5411961;
                        dstF[7] = (float)src[7] * (float)scale * 0.27589938;
                        src += 8;
                        dstF += 8;
                    }
                } else {
                    int errObj = *param_1;
                    *(unsigned*)(intptr_t)(errObj + 0x14) = 0x30;
                     (*(void(**)(int*))(intptr_t)errObj)(param_1);
                }
            }

            cache++;
            idx++;
            g += 0x15;
        } while (idx < param_1[9]);
    }
}
