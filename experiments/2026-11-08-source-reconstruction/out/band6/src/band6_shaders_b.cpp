// Band 6 decompiler-derived candidates — shader compile/create wrappers.
// Assembly-profile assemblers: 0x005dc360/0x005dc640/0x005dc900 + context variants.
// UNVERIFIED. Uses observed COM-ish vtable calls and error strings only;
// unverified D3DX entry names are kept as addresses.

#include <stddef.h>
#include <stdint.h>

typedef void* (*VtblFn)(void*);
struct ShaderObjHdr { void* vtable; };  // +0 only; rest unknown

extern void* operator new(size_t);  // 0x00533c78 class new (size param)
extern void Band6Fatal(int, int, const char*, ...);  // 0x005477c0

// 0x005dc190 — shader-program loader (file path resolve, compile, copy out).
// ECX=this (shader wrapper), 6 stacked params. Strings observed:
// "Invalid shader file name\n", "Failed to find shader program file %s\n",
// "Failed to compile shader %s in file %s\nError: NONE REPORTED\n" / "...Error: %s\n".
extern "C" unsigned long __thiscall Band6ShaderWrapper_Load(void* self,
    const char* filename, unsigned long a, unsigned long b,
    void** outBuf, unsigned long* outSize, void* opts) {
    (void)opts;
    *outBuf = 0; *outSize = 0;
    if (!filename || !*filename) {
        Band6Fatal(1, 0, "Invalid shader file name\n");
        return 0;
    }
    extern char Band6ResolveShaderPath(const char*, char*);
    char path[260];
    if (!Band6ResolveShaderPath(filename, path)) {
        Band6Fatal(1, 0, "Failed to find shader program file %s\n", filename);
        return 0;
    }
    // Compile + assemble via 0x005f7745; handle via vtable+0x10; copy via
    // 0x00533c78 buffer; error text via vtable+0xc. Helpers are externals.
    extern int Band6CompileShader(const char*, unsigned long, unsigned long,
        void*, void*, unsigned long, void**, void**, void*);
    extern unsigned long Band6BlobSize(void*);
    extern void* Band6BlobData(void*);
    void *blobA = 0, *blobErr = 0;
    int rc = Band6CompileShader(path, a, b, self, 0,
        *(unsigned long*)((unsigned char*)self + 4), &blobA, &blobErr, 0);
    if (rc >= 0) {
        unsigned long sz = Band6BlobSize(blobA);
        *outSize = sz;
        *outBuf = operator new(sz);
        unsigned char* d = (unsigned char*)*outBuf;
        unsigned char* s = (unsigned char*)Band6BlobData(blobErr);
        for (unsigned long i = 0; i < sz; ++i) d[i] = s[i];
        return 1;
    }
    if (!blobErr) {
        Band6Fatal(1, 0,
            "Failed to compile shader %s in file %s\nError: NONE REPORTED\n",
            a ? (const char*)a : "", filename);
    } else {
        Band6Fatal(1, 0,
            "Failed to compile shader %s in file %s\nError: %s\n",
            a ? (const char*)a : "", filename, (const char*)blobErr);
    }
    return 0;
}

// 0x005dc360 — assemble shader from memory buffer (sibling of loader).
// Strings: "Invalid shader buffer\n",
// "Failed to assemble shader %s from memory\nError: NONE REPORTED\n" / "...Error: %s\n".
extern "C" unsigned long __thiscall Band6ShaderAssemble(void* self,
    void* buf, unsigned long len, void* a, void* b,
    void** outBuf, unsigned long* outSize, void* opts) {
    (void)opts;
    *outBuf = 0; *outSize = 0;
    if (!buf || !len) {
        Band6Fatal(1, 0, "Invalid shader buffer\n");
        return 0;
    }
    extern int Band6AssembleMem(void*, unsigned long, void*, void*,
        void*, void*, unsigned long, void**, void**, void*);
    extern unsigned long Band6BlobSize(void*);
    extern void* Band6BlobData(void*);
    void *blobA = 0, *blobErr = 0;
    int rc = Band6AssembleMem(buf, len, a, b, self, 0,
        *(unsigned long*)((unsigned char*)self + 4), &blobA, &blobErr, 0);
    if (rc >= 0) {
        unsigned long sz = Band6BlobSize(blobA);
        *outSize = sz;
        *outBuf = operator new(sz);
        unsigned char* d = (unsigned char*)*outBuf;
        unsigned char* s = (unsigned char*)Band6BlobData(blobErr);
        for (unsigned long i = 0; i < sz; ++i) d[i] = s[i];
        return 1;
    }
    if (!blobErr) {
        Band6Fatal(1, 0, "Failed to assemble shader %s from memory\nError: NONE REPORTED\n",
            a ? (const char*)a : "");
    } else {
        Band6Fatal(1, 0, "Failed to assemble shader %s from memory\nError: %s\n",
            a ? (const char*)a : "", (const char*)blobErr);
    }
    return 0;
}

// Common vertex-shader creation pattern (0x005dc640/0x005dce40/0x005dcf80):
// allocate 0x34/0x40 bytes via 0x00533c78, set vtable (0x006c8f88 pocket),
// call assembler 0x005dc360, then 0x005de010 (CreateVertexShader), on failure
// "Failed CreateVertexShader call on %s\n" + release via vtable+0 (destructor).
// The four entry points differ only in operand routing; each is kept whole.

extern "C" void* __thiscall Band6CreateVertexShader(void* self,
    void* buf, unsigned long len, const char* name, void* profile,
    unsigned long a, unsigned char b, unsigned long c, unsigned long d) {
    (void)self;
    ShaderObjHdr* obj = (ShaderObjHdr*)operator new(0x40);
    if (!obj) return 0;
    extern void Band6ShaderInitCommon(void*, void*);
    Band6ShaderInitCommon(obj, 0);
    unsigned char ok = (unsigned char)Band6ShaderAssemble(self, buf, len,
        (void*)name, profile, (void**)&c, (unsigned long*)&d, 0);
    extern unsigned long Band6NativeCreateVS(void*, unsigned char*, unsigned long, unsigned long);
    if (ok) {
        unsigned long rc = Band6NativeCreateVS(obj, &b, c, d);
        if (!rc) {
            Band6Fatal(1, 0, "Failed CreateVertexShader call on %s\n", name);
            return 0;
        }
    }
    return obj;
}

// 0x005dc900 — pixel twin of the above; same pattern with CreatePixelShader.
extern "C" void* __thiscall Band6CreatePixelShader(void* self,
    void* buf, unsigned long len, const char* name, void* profile) {
    (void)self;
    ShaderObjHdr* obj = (ShaderObjHdr*)operator new(0x34);
    if (!obj) return 0;
    extern void Band6ShaderInitCommon(void*, void*);
    Band6ShaderInitCommon(obj, 0);
    unsigned long c = 0, d = 0;
    unsigned char ok = (unsigned char)Band6ShaderAssemble(self, buf, len,
        (void*)name, profile, (void**)&c, (unsigned long*)&d, 0);
    extern unsigned long Band6NativeCreatePS(void*);
    if (ok) {
        if (!Band6NativeCreatePS(obj)) {
            Band6Fatal(1, 0, "Failed CreatePixelShader call on %s\n", name);
            return 0;
        }
    }
    return obj;
}
