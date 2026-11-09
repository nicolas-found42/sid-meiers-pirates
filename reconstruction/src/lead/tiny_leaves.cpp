// UNVERIFIED decompiler-derived reconstruction — no cl 13.10.3077 on this host.
// Lead-owned unique addresses not claimed by a band wave.
// These are candidates, not matches, and are not part of src/ or build/units.json.

// 0x00497420 — body: C3 (single RET). No stack cleanup observed.
// Callers: 56 in the inventory (earlier pass). Likely an empty virtual/thunk target.
void __cdecl FUN_00497420() {}

// 0x005456b0 — body: MOV EAX,[ECX+8]; MOV ECX,[ESP+4];
// MOV EAX,[EAX+ECX*4]; RET 4. ECX receiver, one stack index, int result.
struct Vec_005456b0 {
    unsigned char pad[8];
    int* data;
    int get(int index) { return data[index]; }
};
