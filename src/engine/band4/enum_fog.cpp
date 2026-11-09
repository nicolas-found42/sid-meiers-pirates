// Band4 reconstruction candidate (UNVERIFIED; no cl 13.10.3077).
// Fog-mode enum name builder. Corpus:
// analysis/pseudocode/functions/0x54bd10.c
#include <stdio.h>  // sprintf
#include <string.h> // strlen

extern void* __cdecl FUN_00533c78(int nbytes); // fresh-buffer allocator

// 0x0054bd10 — observed: allocate strlen(name)+20, then format one of
// "%s = FOG_Z_LINEAR" / "%s = FOG_RANGE_SQ" / "%s = FOG_VERTEX_ALPHA"
// by mode 0/1/2. Other modes return the buffer unformatted (observed).
char* __cdecl FUN_0054bd10(char* name, int fogMode)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 20);
    if (fogMode == 0) {
        sprintf(buf, "%s = FOG_Z_LINEAR", name);
    } else if (fogMode == 1) {
        sprintf(buf, "%s = FOG_RANGE_SQ", name);
    } else if (fogMode == 2) {
        sprintf(buf, "%s = FOG_VERTEX_ALPHA", name);
    }
    return buf;
}
