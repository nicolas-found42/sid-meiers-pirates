// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
// Band 8 PNG/zlib (lodepng-style) + small leaves. Third-party bundling: see REPORT.md.
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
extern void FUN_006935e2(void*, void*, unsigned);
extern int FUN_006935fb(void*);
extern void FUN_00656619(void*, const char*);
extern void FUN_0065663c(void*, const char*);
extern void FUN_006565dd(void*, const char*);
extern void FUN_00693659(void*, const unsigned char*);
extern int FUN_00693ebc(void*, unsigned);
extern void* __cdecl malloc(size_t);

// 0x006923b0 ceil-div
int __stdcall FUN_006923b0(int a, int b) { return (a + b - 1) / b; }
// 0x006924d9 safe-free
void __stdcall FUN_006924d9(void* p) { if (p) free(p); }
// 0x006935c8 big-endian u16
unsigned __stdcall FUN_006935c8(const unsigned char* p) { return (unsigned)(p[0] * 256 + p[1]); }
// 0x0069499f flag test
unsigned __thiscall FUN_0069499f(void* self, unsigned mask) {
    return *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(self) + 0xe4) & mask;
}
// 0x00693659 chunk-type validator
void FUN_00693659(void* dec, const unsigned char* type) {
    for (int i = 0; i < 4; ++i) {
        unsigned char c = type[i];
        if (c < 0x29 || c > 0x7a || (c > 0x5a && c < 0x61)) {
            FUN_00656619(dec, "invalid chunk type");
            return;
        }
    }
}
// 0x00694242 IEND handler
void FUN_00694242(void* dec, void*, int len) {
    unsigned* st = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(dec) + 0x58);
    if ((*st & 1) == 0 || (*st & 4) == 0) FUN_006565dd(dec, "No image in file");
    *st |= 0x18;
    if (len != 0) FUN_006565fe_dummy(dec);
    FUN_00693ebc(dec, (unsigned)len);
}
// 0x00694605 unknown chunk dispatcher
void FUN_00694605(void* dec, int param, int crc) {
    FUN_00693659(dec, reinterpret_cast<const unsigned char*>(reinterpret_cast<char*>(dec) + 0x10c));
    unsigned char flag = *(reinterpret_cast<unsigned char*>(dec) + 0x10c);
    if ((flag & 0x20) == 0 && param == 0) return;
    unsigned* st = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(dec) + 0x58);
    if (*st & 4) *st |= 8;
    FUN_00693ebc(dec, (unsigned)crc);
}
// 0x00693ebc CRC tail
int FUN_00693ebc(void* dec, unsigned rem) {
    unsigned off = *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(dec) + 0xa0);
    while (off < rem) {
        FUN_006935e2(dec, *reinterpret_cast<void**>(reinterpret_cast<char*>(dec) + 0x9c), reinterpret_cast<void*>(reinterpret_cast<char*>(dec) + 0xa0));
        rem -= off; off = *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(dec) + 0xa0);
    }
    if (rem) FUN_006935e2(dec, *reinterpret_cast<void**>(reinterpret_cast<char*>(dec) + 0x9c), (void*)(uintptr_t)rem);
    if (FUN_006935fb(dec) == 0) return 0;
    unsigned char b2 = *(reinterpret_cast<unsigned char*>(dec) + 0x10c) & 0x20;
    unsigned char b5d = *(reinterpret_cast<unsigned char*>(dec) + 0x5d);
    if ((b2 == 0 || (b5d & 2)) && (b2 != 0 || ((b5d & 4) == 0))) FUN_00656619(dec, "CRC error");
    else FUN_0065663c(dec, "CRC error");
    return 1;
}
// 0x006924f1 OOM path
void* FUN_006924f1(void* dec) {
    FUN_006565dd(dec, "Out of Memory");
    return nullptr;
}
// 0x00693ba4 adaptive filter warning
void FUN_00693ba4(void* dec) { FUN_00656619(dec, "Ignoring bad adaptive filter type"); }
