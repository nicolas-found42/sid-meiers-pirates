// Band 6 decompiler-derived candidates — effect-file helpers + shader version tables.
// UNVERIFIED. Strings observed verbatim; helpers are externals by address.

#include <stddef.h>
#include <stdint.h>

extern void Band6Fatal(int, int, const char*, ...);
extern void* operator new(size_t);

// 0x005e0b40 — effect-file loader: ".fx" check (stricmp vs 0x006c95d0), then
// resolve (0x005e09d0), compile on temp device (0x005e2d20), register (0x005e25c0).
// Strings: "Invalid D3D Effect file %s\n", "Failed to find D3D Effect file %s\n",
// "Failed to compile D3D Effect using Temp Device:\n %s\n",
// "Missing D3D Effect file name\n".
extern "C" unsigned long __cdecl Band6EffectLoad(const char* filename, int* outFlag) {
    if (!filename || !*filename) {
        Band6Fatal(1, 0, "Missing D3D Effect file name\n");
        return 0;
    }
    extern int Band6StripExt(const char*, char*, int);
    extern int Band6StrICmp(const char*, const char*);
    extern unsigned long Band6FindEffectFile(const char*, char*);
    char stem[256]; char resolved[260];
    Band6StripExt(filename, stem, 0x100);
    extern char gEffectExt[];  // 0x006c95d0 (".fx")
    if (Band6StrICmp(stem, gEffectExt) != 0) {
        *outFlag = 0;
        Band6Fatal(1, 0, "Invalid D3D Effect file %s\n", filename);
        return 0;
    }
    unsigned long ok = Band6FindEffectFile(filename, resolved);
    if (!ok) {
        Band6Fatal(1, 0, "Failed to find D3D Effect file %s\n", filename);
        return 0;
    }
    extern unsigned long Band6CompileEffect(const char*, void*, void**, const char**);
    const char* err = 0;
    unsigned long h = Band6CompileEffect(resolved, 0, (void**)&err, 0);
    if (!h) {
        Band6Fatal(1, 0, "Failed to compile D3D Effect using Temp Device:\n %s\n",
            err ? err : "");
        *outFlag = 0;
        return 0;
    }
    if (*outFlag == 0) {
        *outFlag = (int)(h ? 1 : 0);
    }
    return 1;
}

// 0x005e09d0 — resolve effect file against D3D effect directory.
// Strings: "No valid D3D Effect factory\n",
// "Invalid or no D3D Effect directory\n", "D3D Effect file not found %s\n".
extern "C" unsigned long __cdecl Band6FindEffectFile(const char* filename, char* outPath) {
    extern int Band6FileExists(const char*);
    extern void Band6SplitPath(const char*, void*, char*, char*, char*, char*);
    if (Band6FileExists(filename)) {
        const char* s = filename; char* d = outPath;
        do { *d++ = *s; } while (*s++);  // hmm: copy incl. NUL below
        outPath[0] = 0;  // placeholder, real copy follows
        s = filename; d = outPath; while ((*d++ = *s++) != 0) {}
        return 1;
    }
    extern char* gEffectDir;   // 0x007290a0
    extern char* gEffectFactory; // 0x0072909c
    if (!gEffectFactory) {
        Band6Fatal(1, 0, "No valid D3D Effect factory\n");
        return 0;
    }
    char a[260], b[260], c[260], d2[260];
    Band6SplitPath(filename, 0, a, b, c, d2);
    if (!gEffectDir) {
        Band6Fatal(1, 0, "Invalid or no D3D Effect directory\n");
        return 0;
    }
    extern void Band6JoinPath(char*, const char*, const char*, const char*, const char*);
    Band6JoinPath(outPath, gEffectDir, b, d2, 0);
    if (!Band6FileExists(outPath)) {
        Band6Fatal(1, 0, "D3D Effect file not found %s\n", filename);
        return 0;
    }
    return 1;
}

// 0x005f79a8 — pixel-shader profile selector from caps blob.
// Observed returns: "ps_1_1"/"ps_1_2"/"ps_1_3"/"ps_2_0"/"ps_2_a"/"ps_3_0".
extern "C" const char* __cdecl Band6PixelShaderProfile(void* caps) {
    if (!caps) return 0;
    extern int Band6GetCapsBlob(void*, char*);
    char blob[204];
    if (Band6GetCapsBlob(caps, blob) < 0) return 0;
    unsigned long v = ((unsigned long*)blob)[0x1a];  // offset observed (~0x68)
    v &= 0xffff;
    if (v < 0x200) {
        if (v == 0x101) return "ps_1_1";
        if (v == 0x102) return "ps_1_2";
        if (v == 0x103 || v == 0x104) return "ps_1_3";
        return 0;
    }
    if (v > 0x2ff) return "ps_3_0";
    return "ps_2_a";
}

// 0x005f7a58 — vertex twin. Strings: "vs_2_0"/"vs_2_a"/"vs_3_0".
extern "C" const char* __cdecl Band6VertexShaderProfile(void* caps) {
    if (!caps) return 0;
    extern int Band6GetCapsBlob(void*, char*);
    char blob[196];
    if (Band6GetCapsBlob(caps, blob) < 0) return 0;
    unsigned long v = ((unsigned long*)blob)[0x1c] & 0xffff;
    if (v < 0x200) {
        if (v == 0x101) return "vs_3_0";  // observed select arm
        return 0;
    }
    if (v > 0x2ff) return "vs_3_0";
    return "vs_2_a";
}

// 0x005f8042 — scan 0x2c-entry version table for matching bits; on match copy
// triple to out (if non-null). Returns 0 or 0x80004005.
extern "C" long __cdecl Band6MatchShaderVersion(unsigned long a, unsigned long b, void* out) {
    extern const unsigned long gVsVersionTable[];
    for (int i = 0x2c; i; --i) {
        const unsigned long* e = gVsVersionTable + (0x2c - i) * 3;
        if (e[0 - 1] == a && ((e[0] & b) == b)) {  // layout observed; see unknowns
            if (out) {
                unsigned long* o = (unsigned long*)out;
                o[0] = e[1]; o[1] = e[2]; o[2] = e[3];
            }
            return 0;
        }
    }
    return (long)0x80004005;
}
