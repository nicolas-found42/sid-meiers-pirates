// Band4 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Property-dump formatting family (see analysis/team/band4/REPORT.md §2).
// Shared shape: copy strlen(name)+K bytes into a fresh buffer
// (FUN_00533c78) and sprintf a fixed format. Corpus:
// analysis/pseudocode/functions/0x557b10.c etc.
#include <stdio.h>  // sprintf
#include <string.h> // strlen

extern void* __cdecl FUN_00533c78(int nbytes);

// 0x00557b10 — "--- %s ---" header line.
char* __cdecl FUN_00557b10(char* name)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 9);
    sprintf(buf, "--- %s ---", name);
    return buf;
}

// 0x00557b50 — bool value.
char* __cdecl FUN_00557b50(char* name, char value)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 9);
    if (value == 0) {
        sprintf(buf, "%s = false", name);
    } else {
        sprintf(buf, "%s = true", name);
    }
    return buf;
}

// 0x00557bb0 — unsigned char value.
char* __cdecl FUN_00557bb0(char* name, unsigned char value)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 7);
    sprintf(buf, "%s = %u", name, (unsigned)value);
    return buf;
}

// 0x00557bf0 — signed short value.
char* __cdecl FUN_00557bf0(char* name, short value)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 10);
    sprintf(buf, "%s = %hd", name, (int)value);
    return buf;
}

// 0x00557c30 — unsigned short value.
char* __cdecl FUN_00557c30(char* name, unsigned short value)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 9);
    sprintf(buf, "%s = %hu", name, (unsigned)value);
    return buf;
}

// 0x00557c70 — signed int value.
char* __cdecl FUN_00557c70(char* name, int value)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 15);
    sprintf(buf, "%s = %d", name, value);
    return buf;
}

// 0x00557cb0 — unsigned int value.
char* __cdecl FUN_00557cb0(char* name, unsigned value)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 14);
    sprintf(buf, "%s = %u", name, value);
    return buf;
}

// 0x00557cf0 — float value (Ghidra shows a no-arg allocator call; the
// allocation size may be length-independent or misdecompiled).
char* __cdecl FUN_00557cf0(char* name, float value)
{
    char* buf = (char*)FUN_00533c78();
    sprintf(buf, "%s = %g", name, (double)value);
    return buf;
}

// 0x00557d40 — pointer value.
char* __cdecl FUN_00557d40(char* name, void* value)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 16);
    sprintf(buf, "%s = %p", name, value);
    return buf;
}

// 0x00557d80 — string-or-NULL value. Two format paths: "%s = NULL" when
// value is null, "%s = %s" otherwise.
char* __cdecl FUN_00557d80(char* name, char* value)
{
    if (value == NULL) {
        int len = (int)strlen(name);
        char* buf = (char*)FUN_00533c78(len + 8);
        sprintf(buf, "%s = NULL", name);
        return buf;
    }
    int len = (int)strlen(name);
    int vlen = (int)strlen(value);
    char* buf = (char*)FUN_00533c78(len + vlen + 4);
    sprintf(buf, "%s = %s", name, value);
    return buf;
}

// 0x00557e10 — thiscall: formats `this` as "(%g, %g, %g) , %g" where this
// points at four floats (note the space before the comma).
struct Vec4Fmt_e10 {
    float v[4];
    char* __thiscall FUN_00557e10(char* name);
};
char* __thiscall Vec4Fmt_e10::FUN_00557e10(char* name)
{
    char* buf = (char*)FUN_00533c78();
    sprintf(buf, "%s = (%g, %g, %g) , %g", name,
            (double)v[0], (double)v[1], (double)v[2], (double)v[3]);
    return buf;
}

// 0x00557ff0 — thiscall: formats `this` as "(%g,%g,%g), %g" (no %s = prefix).
struct Vec4Fmt_ff0 {
    float v[4];
    char* __thiscall FUN_00557ff0(void);
};
char* __thiscall Vec4Fmt_ff0::FUN_00557ff0(void)
{
    char* buf = (char*)FUN_00533c78();
    sprintf(buf, "(%g,%g,%g), %g", (double)v[0], (double)v[1],
            (double)v[2], (double)v[3]);
    return buf;
}
