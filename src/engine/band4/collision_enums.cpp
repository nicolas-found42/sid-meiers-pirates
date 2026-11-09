// Band4 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Collision-mode enum stringifiers. Corpus:
// analysis/pseudocode/functions/0x58eb90.c, 0x58ec30.c, 0x58ed10.c
#include <stdio.h>  // sprintf
#include <string.h> // strlen

extern void* __cdecl FUN_00533c78(int nbytes);
extern void  __cdecl FUN_005606f0(unsigned index, void** slot); // array append
extern void  __cdecl FUN_006b34a0(void* growTarget); // grow helper

// Shipped array header layout seen at 0x0058eb90: +8 count/capacity pair,
// +0xc index, +0x14 base. Descriptive hypotheses only.
struct GrowArray {
    void*     pad[2];       // +0x00, +0x04
    unsigned  capacity_08;  // +0x08
    unsigned  count_0c;     // +0x0c
    void*     pad2;         // +0x10
    void*     base_14;      // +0x14
};

// 0x0058eb90 — emit "%s = BOX_BV" into a growable array.
// Note the unusual control flow: it always calls the append (FUN_005606f0),
// with a conditional grow (FUN_006b34a0) when count (at +0x0c) is >= (+0x08)?
// Actually observed: uVar2 = arr[0xc]; if (arr[0x8] <= uVar2) grow(...);
// append(uVar2, &buf). The comparison direction is kept as observed.
void __cdecl FUN_0058eb90(char* name, GrowArray* array)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 10);
    sprintf(buf, "%s = BOX_BV", name);
    unsigned index = array->count_0c;
    if (array->capacity_08 <= index) {
        FUN_006b34a0((char*)array->base_14 + index);
    }
    FUN_005606f0(index, (void**)&buf);
}

// 0x0058ec30 — collision test-mode: 0=USE_OBB, 1=USE_TRI, 2=USE_ABV,
// 3=NOTEST, 4=USE_NIBOUND, else UNKNOWN!!!.
char* __cdecl FUN_0058ec30(char* name, unsigned mode)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 0x11);
    switch (mode) {
    case 0: sprintf(buf, "%s = USE_OBB", name); return buf;
    case 1: sprintf(buf, "%s = USE_TRI", name); return buf;
    case 2: sprintf(buf, "%s = USE_ABV", name); return buf;
    case 3: sprintf(buf, "%s = NOTEST", name); return buf;
    case 4: sprintf(buf, "%s = USE_NIBOUND", name); return buf;
    default: sprintf(buf, "%s = UNKNOWN!!!", name); return buf;
    }
}

// 0x0058ed10 — propagate mode: 0=PROPAGATE_ON_SUCCESS,
// 1=PROPAGATE_ON_FAILURE, 2=PROPAGATE_ALWAYS, 3=PROPAGATE_NEVER,
// else UNKNOWN!!!.
char* __cdecl FUN_0058ed10(char* name, unsigned mode)
{
    int len = (int)strlen(name);
    char* buf = (char*)FUN_00533c78(len + 0x20);
    switch (mode) {
    case 0: sprintf(buf, "%s = PROPAGATE_ON_SUCCESS", name); return buf;
    case 1: sprintf(buf, "%s = PROPAGATE_ON_FAILURE", name); return buf;
    case 2: sprintf(buf, "%s = PROPAGATE_ALWAYS", name); return buf;
    case 3: sprintf(buf, "%s = PROPAGATE_NEVER", name); return buf;
    default: sprintf(buf, "%s = UNKNOWN!!!", name); return buf;
    }
}
