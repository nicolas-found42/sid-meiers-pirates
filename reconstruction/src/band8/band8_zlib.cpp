// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
// Band 8 zlib/inflate leaves.
#include <stddef.h>
extern int FUN_006b2a2b(void*, int, int, void*, void*, void*, void*, int*, unsigned);
typedef void (__stdcall* CB)(void*, int);
struct Strm { char pad[0x20]; void* zalloc; void* zfree; void* dummy; CB cb; void* ctx; };
extern void FUN_006565fe_dummy(void*);

// 0x006b2a1a indirect callback dispatch
void __stdcall FUN_006b2a1a(int value, Strm* s) { s->cb(s->ctx, value); }

// 0x006b3da0 store to +0x10
void __thiscall FUN_006b3da0(void* self, int value) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x10) = value;
}

// 0x006b2daa dynamic bit-lengths tree (0x13)
int FUN_006b2daa(void* st, int* out, void*, void*, void* strm) {
    Strm* s = reinterpret_cast<Strm*>(strm);
    void* mem = s->zalloc(reinterpret_cast<void*>(s), 0x13, 4);
    if (!mem) return -4;
    int r = FUN_006b2a2b(st, 0x13, 0x13, 0, 0, 0, 0, reinterpret_cast<int*>(&mem), 0);
    if (r == -3) *reinterpret_cast<char**>(reinterpret_cast<char*>(strm) + 0x18) = reinterpret_cast<char*>(const_cast<char*>("oversubscribed dynamic bit lengths tree"));
    else if (r == -5 || *out == 0) { *reinterpret_cast<char**>(reinterpret_cast<char*>(strm) + 0x18) = reinterpret_cast<char*>(const_cast<char*>("incomplete dynamic bit lengths tree")); r = -3; }
    s->zfree(s->ctx, mem);
    return r;
}
// 0x006b2e23 literal/distance tree builder
int FUN_006b2e23(unsigned n, void* a, int b, int* c, int* d, void* e, void* f, void* g, void* strm) {
    Strm* s = reinterpret_cast<Strm*>(strm);
    void* mem = s->zalloc(s->ctx, 0x120, 4);
    if (!mem) return -4;
    int r = FUN_006b2a2b(a, n, 0x101, reinterpret_cast<void*>(0x6f4f20), reinterpret_cast<void*>(0x6f4fa0), e, g, reinterpret_cast<int*>(&mem), 0);
    if (r != 0) {
        if (r == -3) { *reinterpret_cast<char**>(reinterpret_cast<char*>(strm) + 0x18) = reinterpret_cast<char*>(const_cast<char*>("oversubscribed literal/length tree")); return r; }
        if (r == -5) { *reinterpret_cast<char**>(reinterpret_cast<char*>(strm) + 0x18) = reinterpret_cast<char*>(const_cast<char*>("incomplete distance tree")); return r; }
    }
    if (*c != 0)
        r = FUN_006b2a2b(reinterpret_cast<char*>(a) + n * 4, b < 0 ? 0 : b, 0, reinterpret_cast<void*>(0x6f5020), reinterpret_cast<void*>(0x6f5098), f, g, reinterpret_cast<int*>(&mem), 0);
    if (r != 0) {
        if (r == -3) *reinterpret_cast<char**>(reinterpret_cast<char*>(strm) + 0x18) = reinterpret_cast<char*>(const_cast<char*>("oversubscribed distance tree"));
        else if (r == -5) *reinterpret_cast<char**>(reinterpret_cast<char*>(strm) + 0x18) = reinterpret_cast<char*>(const_cast<char*>("incomplete distance tree"));
        else *reinterpret_cast<char**>(reinterpret_cast<char*>(strm) + 0x18) = reinterpret_cast<char*>(const_cast<char*>("empty distance tree with lengths"));
        s->zfree(s->ctx, mem);
        return r;
    }
    if (*d == 0 && n < 0x102) { *reinterpret_cast<char**>(reinterpret_cast<char*>(strm) + 0x18) = reinterpret_cast<char*>(const_cast<char*>("empty distance tree with lengths")); s->zfree(s->ctx, mem); return r; }
    s->zfree(s->ctx, mem);
    return 0;
}
