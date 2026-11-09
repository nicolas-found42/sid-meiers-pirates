// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
// Band 8 wave2 zlib/inflate entry + IDAT decompression tail.
#include <stddef.h>
#include <stdint.h>
extern void FUN_006af9ad(void* bits, void* strm, void* crc);
extern void FUN_006565dd(void* dec, const char* msg);
extern void FUN_00693ebc(void* dec, unsigned rem);
extern void FUN_00692570(void* dec, void* data, int a, int b);
extern void FUN_00658adc(void* dec, void* dst, int len);
extern int FUN_0069323b(void* strm, int flush);
extern void FUN_006935e2(void* dec, void* dst, int len);
extern unsigned FUN_0069359e(const void* p);
extern void FUN_00656711(void* dec);
extern void FUN_006930ca(void* strm);
extern void FUN_006565fe(void* dec, const char* msg);

// 0x0069323b zlib header/inflate dispatcher (state machine; full body in pseudocode 0x69323b.c).
// Structure: strm[0]=next_in, strm[1]=avail_in, strm[2]=total_in, strm[6]=msg, strm[7]=state, state[0]=state id.
int FUN_0069323b(int* s, int flush) {
    if (!s || s[7] == 0 || *s == 0) return -2;
    struct St { int state; int cmf; int flg; int chk; int window; int btype; int msg; };
    St* st = (St*)(intptr_t)s[7];
    int inflate_ret = -5;
    int done_ret = (flush == 4) ? -5 : 0;
    for (;;) {
        if (inflate_ret == 0) inflate_ret = done_ret;
        switch (st->state) {
        case 0: { // HEAD
            if (s[1] == 0) return inflate_ret;
            ++s[2]; --s[1];
            st->cmf = *(unsigned char*)*s;
            ++*s;
            if ((st->cmf & 0xf) != 8) { st->state = 0xd; s[6] = (int)"unknown compression method"; goto bad; }
            if ((st->cmf >> 4) + 8 > (unsigned)st->window) { st->state = 0xd; s[6] = (int)"invalid window size"; goto bad; }
            st->state = 1; inflate_ret = done_ret; continue;
        }
        case 1: { // FLAGS
            if (s[1] == 0) return inflate_ret;
            ++s[2]; --s[1];
            unsigned char b = *(unsigned char*)*s; ++*s;
            if ((st->cmf * 0x100 + b) % 0x1f != 0) { st->state = 0xd; s[6] = (int)"incorrect header check"; goto bad; }
            if (b & 0x20) { st->state = 2; inflate_ret = done_ret; continue; }
            st->state = 7; inflate_ret = done_ret; break;
        }
        case 2: case 3: case 4: case 5: { // DICT (copied big-endian word)
            if (s[1] == 0) return inflate_ret;
            ++s[2]; --s[1];
            unsigned char b = *(unsigned char*)*s; ++*s;
            if (st->state == 2) st->chk = ((unsigned)b) << 24;
            else if (st->state == 3) st->chk += (unsigned)b * 0x10000u;
            else if (st->state == 4) st->chk += (unsigned)b * 0x100u;
            else st->chk += b;
            // simplified: fall through to state+1; exact stepping in decomp
            st->state += 1;
            if (st->state == 6) { s[0xc] = ((int*)s[7])[2]; return 2; }
            inflate_ret = done_ret; break;
        }
        case 6:
            st->state = 0xd; s[6] = (int)"need dictionary"; ((int*)s[7])[1] = 0; return -2;
        case 7: {
            inflate_ret = FUN_006afa91(*(void**)((char*)s[7] + 0x14), s, inflate_ret);
            if (inflate_ret == -3) { st->state = 0xd; ((int*)s[7])[1] = 0; inflate_ret = -3; }
            else { if (inflate_ret == 0) inflate_ret = done_ret; }
            if (inflate_ret != 1) return inflate_ret;
            FUN_006af9ad(*(void**)((char*)s[7] + 0x14), s, (void*)((char*)s[7] + 4));
            if (((int*)s[7])[3] == 0) { st->state = 8; inflate_ret = done_ret; continue; }
            st->state = 0xc; inflate_ret = done_ret; break;
        }
        case 8: case 9: case 10: case 11: { // CHECK
            if (s[1] == 0) return inflate_ret;
            ++s[2]; --s[1];
            unsigned char b = *(unsigned char*)*s; ++*s;
            if (st->state == 8) st->chk = ((unsigned)b) << 24;
            else if (st->state == 9) st->chk += (unsigned)b * 0x10000u;
            else if (st->state == 10) st->chk += (unsigned)b * 0x100u;
            else {
                st->chk += b;
                if (st->cmf != st->flg) { st->state = 0xd; s[6] = (int)"incorrect data check"; goto bad; }
                st->state = 0xc; return 1;
            }
            st->state += 1; inflate_ret = done_ret; break;
        }
        case 0xc:
            return 1;
        default:
            return inflate_ret;
        }
bad:
        ((int*)s[7])[1] = 5; return done_ret;
    }
}

// 0x0069464e IDAT tail: advances decoder, feeds zlib, checks IDAT presence.
// Uses observed offsets; interlace-table constants referenced by ID not inlined here.
void FUN_0069464e(int dec) {
    unsigned* counter = (unsigned*)(dec + 0xd4);
    *counter = *counter + 1;
    if (*(unsigned*)(dec + 0xc0) > *counter) return;
    if (*(char*)(dec + 0x113) == 0) {
        // non-interlaced path falls through to inflate setup
    } else {
        *counter = 0;
        FUN_00692570((void*)dec, *(void**)(dec + 0xd8), 0, *(int*)(dec + 200) + 1);
        // interlace sweep loop simplified: full per-pass arithmetic in pseudocode 0x69464e.c
    }
    if ((*(unsigned char*)(dec + 0x5c) & 0x20) == 0) {
        *(int*)(dec + 0x70) = dec + 4;
        *(int*)(dec + 0x74) = 1;
        for (;;) {
            if (*(int*)(dec + 0x68) == 0) {
                if (*(int*)(dec + 0xfc) == 0) {
                    for (;;) {
                        FUN_00693ebc((void*)dec, 0);
                        unsigned char chunkType[4] = {0};
                        FUN_00658adc((void*)dec, chunkType, 4);
                        unsigned n = FUN_0069359e(chunkType);
                        *(unsigned*)(dec + 0xfc) = n;
                        FUN_00656711((void*)dec);
                        FUN_006935e2((void*)dec, (void*)(dec + 0x10c), 4);
                        if (*(int*)(dec + 0x10c) != 0x54414449) FUN_006565dd((void*)dec, "Not enough image data");
                        if (n != 0) break;
                    }
                }
                *(unsigned*)(dec + 0x68) = *(unsigned*)(dec + 0xa0);
                *(void**)(dec + 100) = *(void**)(dec + 0x9c);
                if (*(unsigned*)(dec + 0xfc) < *(unsigned*)(dec + 0xa0)) *(unsigned*)(dec + 0x68) = *(unsigned*)(dec + 0xfc);
                FUN_006935e2((void*)dec, *(void**)(dec + 0x9c), *(int*)(dec + 0x68));
                *(int*)(dec + 0xfc) = *(int*)(dec + 0xfc) - *(int*)(dec + 0x68);
            }
            int r = FUN_0069323b((void*)(dec + 100), 1);
            if (r == 1) break;
            if (r != 0) {
                const char* m = *(const char**)(dec + 0x7c);
                if (!m) m = "Decompression Error";
                FUN_006565dd((void*)dec, m);
            }
            if (*(int*)(dec + 0x74) == 0) FUN_006565dd((void*)dec, "Extra compressed data");
        }
        if ((*(int*)(dec + 0x74) == 0) || (*(int*)(dec + 0x68) != 0) || (*(int*)(dec + 0xfc) != 0)) FUN_006565dd((void*)dec, "Extra compressed data");
        *(unsigned*)(dec + 0x58) |= 8;
        *(unsigned*)(dec + 0x5c) |= 0x20;
        *(int*)(dec + 0x74) = 0;
    }
    if ((*(int*)(dec + 0xfc) != 0) || (*(int*)(dec + 0x68) != 0)) FUN_006565dd((void*)dec, "Extra compression data");
    FUN_006930ca((void*)(dec + 100));
    *(unsigned*)(dec + 0x58) |= 8;
}
