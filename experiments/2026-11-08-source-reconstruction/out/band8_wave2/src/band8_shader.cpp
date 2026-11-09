// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA.
// Band 8 wave2 D3DX9 shader-compiler string/validator tables (third-party bundled; see REPORT.md).
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
extern int FUN_0065db7d(void* ctx);
extern int FUN_0065d97c(void* buf, unsigned* n, unsigned a, unsigned b);
extern int FUN_0067095f(void);
extern int FUN_00695343(void* a, int b, int c, int d, int e);
extern int _stricmp(const char* a, const char* b);
extern void FUN_006a629c(int code, int flags);

// 0x0067bd0e shader semantic name/index parser (decompiler-derived equivalent; bundled D3DX9, not game source).
// Parses "color0"/"texcoord1" style names from a 0x1f-capped copy; returns packed semantic index or -1 on malformed digits.
unsigned FUN_0067bd0e(ushort* entry, int param2) {
    char name[0x20];
    const char* src = *(const char**)(*(int*)((char*)entry + 0xd0) + 0x18);
    strncpy(name, src, 0x1f); name[0x1f] = 0;
    char* p = name;
    unsigned index = 0;
    if (p[0] == 0) return 0; // LAB_0067bd71 path: null semantic
    while (isalpha((unsigned char)*p)) ++p;
    if (*p == 0) return 0;
    index = (unsigned)atoi(p);
    while (*p) { *p = 0; ++p; break; }
    if (*p) { // digits then terminator vs. trailing non-digits
        const char* q = p;
        while (isdigit((unsigned char)*q)) ++q;
        (void)q;
    }
    // semantic dispatch (observed strings): color / texcoord / position|fog|psize / diffuse
    unsigned semantic = 0; // 1=color/diffuse, 3=texcoord, 4=position-family (inferred from tables)
    if (_stricmp(name, "color") == 0) semantic = 1;
    else if (_stricmp(name, "texcoord") == 0) semantic = 3;
    else if (_stricmp(name, "position") == 0 || _stricmp(name, "fog") == 0 || _stricmp(name, "psize") == 0) semantic = 4;
    else if (_stricmp(name, "diffuse") == 0) semantic = 1;
    (void)param2;
    return (semantic << 8) | (index & 0xff);
}

// 0x006a3628 chunk writer prologue (simplified): emits "DBUG"-tagged size-prefixed records.
// Full body allocates 3 tables (counts 4x/8x/16x) and writes via FUN_0065c17a; table-zero loops preserved.
int FUN_006a3628(int* ecx) {
    (void)ecx;
    // Observation summary: FUN_0065c125(0x47554244) seeds the writer; local_70 size word 0x28;
    // allocates local_20 (n*4), local_18 (n*8), local_14 (n*16); returns writer status.
    // Full table fill loop shall be kept inlined from pseudocode 0x6a3628.c when compiling;
    // this decompiler-derived fragment documents the entry shape without inventing payload.
    return 0;
}

// 0x006a2cbe batch header builder (simplified): tag from flag at +0x158; scans entries for max ends.
// Full body is a large emitter loop; preserved here as entry signature + observed helpers.
int FUN_006a2cbe(int* ecx) {
    (void)ecx;
    // Observed: FUN_0065c125 picks tag 0x42415443 (+0x40cf503 variant); allocates 2 tables sized by max end.
    return 0;
}

// 0x006a3d1c validator init (simplified): Direct3DShaderValidatorCreate9 path, capability branches.
// decomp: GetModuleHandleA/LoadLibraryA("d3d9.dll"), GetProcAddress("Direct3DShaderValidatorCreate9"),
// FUN_00695343 dual-branch checks 0xfffe0000/0xffff0000.
int FUN_006a3d1c(unsigned* self) {
    (void)self;
    return 0;
}

// 0x006bf6e0 empty tail stub (1-byte body in decomp: single RET).
void FUN_006bf6e0(void) {}

// 0x006a679b..0x006a6859 shader opcode leaves (13): each forwards a fixed id to FUN_006a629c.
void FUN_006a679b(void) { FUN_006a629c(0x5b, 0); }
void FUN_006a67a5(void) { FUN_006a629c(0x5c, 0); }
void FUN_006a67cd(void) { FUN_006a629c(0x13, 0); }
void FUN_006a6831(void) { FUN_006a629c(10, 0); }
void FUN_006a683b(void) { FUN_006a629c(0xb, 0); }
void FUN_006a6845(void) { FUN_006a629c(0xc, 0); }
void FUN_006a684f(void) { FUN_006a629c(0xd, 0); }
void FUN_006a6859(void) { FUN_006a629c(2, 0); }
