// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
// Band 8 D3DX9 ps_1.x shader-compiler support (validator contains bundled third-party code).
#include <stddef.h>
extern void FUN_006a0152(void*);
extern int FUN_00673e38(const int*, const int*);
extern unsigned FUN_00672e90(void);
extern void FUN_006626da(void*, int, unsigned, const char*);
extern void FUN_00656619(void*, const char*);

// 0x0067e9a7 ctor/init
void __thiscall FUN_0067e9a7(void* self, int v) {
    FUN_006a0152();
    char* b = reinterpret_cast<char*>(self);
    *reinterpret_cast<void**>(b) = reinterpret_cast<void*>(0x6f0668);
    *reinterpret_cast<int*>(b + 0x8a * 4) = 0;
    *reinterpret_cast<int*>(b + 0x56 * 4) = v;
    *reinterpret_cast<void**>(b + 0x3d * 4) = reinterpret_cast<void*>(0x720428);
    *reinterpret_cast<void**>(b + 0x3e * 4) = reinterpret_cast<void*>(0x720548);
}
// 0x0067c8e9 swizzle mapper
int FUN_0067c8e9(void* self, unsigned a, unsigned b, unsigned* /*c*/) {
    int vec[8] = {-1, -1, -1, -1, 0, 0, 0, 0};
    char* s = reinterpret_cast<char*>(self);
    unsigned flags = *reinterpret_cast<unsigned*>(s + 200);
    if ((flags & 0xffff) == 0x104) {
        for (unsigned i = 0; i < 4; ++i)
            if (FUN_00673e38(vec, reinterpret_cast<const int*>(0x720370 + i * 4)) != 0) return (int)i;
    }
    (void)a; (void)b;
    return 0;
}
// 0x00675ec3 InputRemap matcher (approximate; low confidence)
int FUN_00675ec3(void* self, int /*a*/, unsigned, unsigned, unsigned, int) {
    char* s = reinterpret_cast<char*>(self);
    if (*reinterpret_cast<int*>(s + 0x14) == 0) return 0;
    return FUN_006626da(self, 0, 0, "internal error: InputRemap component matchup failed") , 0;
}
// 0x0067327b Clip validator (approximate)
int __thiscall FUN_0067327b(void* self) {
    unsigned* w = *reinterpret_cast<unsigned**>(reinterpret_cast<char*>(self) + 0x100);
    if ((w[0] & 0xfffff) == 4 && w[1] == 4) return 0;
    FUN_006626da(self, 0, 0, "Clip must be from a 3 vector in ps_1_%i");
    return 0;
}
// 0x006752d1 w-component check (approximate)
int __thiscall FUN_006752d1(void* self) {
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0xc) == 0) return 0;
    FUN_006626da(self, 0, 0x11a0, "cannot access w component from texcoord in general expression");
    return 0;
}
