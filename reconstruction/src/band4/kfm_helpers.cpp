// Band4 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Small KFM-file family helpers. Corpus:
// analysis/pseudocode/functions/0x5713c0.c, 0x571a60.c, 0x571aa0.c, 0x571ae0.c
// NOTE: the KFM writer itself (0x00572020, ~4.8kB / ~6 strings) is a
// machine-output section (mov-scan loops) that resists decompiler-derived
// reconstruction from pseudocode alone; it is queued, not faked here.
#include <stddef.h>

extern bool __cdecl FUN_005bd960(int key, int* outResolved); // keyed lookup

// 0x005713c0 — trivial equality predicate (int vs int; probably a type- or
// enum-comparison helper shared by KFM readers).
bool __cdecl FUN_005713c0(int a, int b)
{
    return a == b;
}

// 0x00571a60 — resolve key; on success *out = entry[1]; returns 0 ok, 2 fail.
int __cdecl FUN_00571a60(int key, int* out)
{
    int resolved = key;
    if (!FUN_005bd960(key, &resolved) || resolved == 0) {
        return 2;
    }
    *out = *(int*)(resolved + 4);
    return 0;
}

// 0x00571aa0 — resolve one key, read two fields (+8/+0xc); 0 ok, 2 fail.
int __cdecl FUN_00571aa0(int key, int* out1, int* out2)
{
    int resolved = key;
    if (!FUN_005bd960(key, &resolved) || resolved == 0) {
        return 2;
    }
    *out1 = *(int*)(resolved + 8);
    *out2 = *(int*)(resolved + 0xc);
    return 0;
}

// 0x00571ae0 — resolve two keys; on success read a byte from the second
// entry; returns 0 ok, 2 or 3 fail.
int __cdecl FUN_00571ae0(int key1, int key2, unsigned char* out)
{
    int resolved = key1;
    if (!FUN_005bd960(key1, &resolved) || resolved == 0) {
        return 2;
    }
    if (!FUN_005bd960(key2, &resolved) || resolved == 0) {
        return 3;
    }
    *out = *(unsigned char*)(resolved + 8);
    return 0;
}
