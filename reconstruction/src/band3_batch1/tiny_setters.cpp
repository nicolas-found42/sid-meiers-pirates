// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Sources: analysis/pseudocode/functions/*.c
// plus analysis/team/band3/triage.json spans/offsets/call/data_refs.
// Deep dives: analysis/team/band3/deep/0x00514ac0.md, 0x005366b0.md,
// 0x0054aae0.md (see those dossiers for REA evidence ids).
#include <cstdint>

extern int DAT_00727444;
extern char PTR_LAB_006fd148[];
extern char PTR_FUN_006c1fb4[];
extern void FUN_0055adf0(void);
extern struct CRITICAL_SECTION;
extern void DeleteCriticalSection(CRITICAL_SECTION*);
struct HINSTANCE__ {};
template <typename T, typename Helper>
struct SimpleArrayStub;

// Linked RemoveAll target observed at 0x533b80 (corpus/library signature).
extern void CSimpleArray_RemoveAll_533b80(void* self);

// 0x00547610 — store dword param at this+0x0c
void __thiscall FUN_00547610(void* self, uint32_t value) {
    *(uint32_t*)((char*)self + 0x0c) = value;
}

// 0x0054a9f0 — store byte param at this+0x18
void __thiscall FUN_0054a9f0(void* self, uint8_t value) {
    *(uint8_t*)((char*)self + 0x18) = value;
}

// 0x00514ac0 — iface at obj+0x15c, vtbl slot +8, args (p, 4)
void __stdcall FUN_00514ac0(void* obj, void* p) {
    void* iface = *(void**)((char*)obj + 0x15c);
    auto fn = *(void(__stdcall**)(void*, int))(*(void**)iface + 8);
    fn(p, 4);
}

// 0x005366b0 — copy [this+0x90..0x98] (3 dwords) to [this+0x28..0x30]
void __thiscall FUN_005366b0(void* self) {
    char* base = (char*)self;
    *(uint32_t*)(base + 0x28) = *(uint32_t*)(base + 0x90);
    *(uint32_t*)(base + 0x2c) = *(uint32_t*)(base + 0x94);
    *(uint32_t*)(base + 0x30) = *(uint32_t*)(base + 0x98);
}

// 0x0054aae0 — vtbl sequence + counter +8 subobject base ctor call
void* __thiscall FUN_0054aae0(void* self) {
    *(void**)self = (void*)&PTR_LAB_006fd148;
    *(int*)((char*)self + 4) = 0;
    DAT_00727444 = DAT_00727444 + 1;
    *(void**)self = (void*)&PTR_FUN_006c1fb4;
    FUN_0055adf0((char*)self + 8);
    return self;
}

// 0x00533bb7 — ATL::CAtlBaseModule::~CAtlBaseModule (library single-match)
// this+0x18 -> DeleteCriticalSection; this+0x30 -> RemoveAll (0x533b80).
struct AtlBaseModule_533bb7 {
    char pad_0x00[0x18];
    CRITICAL_SECTION crit;
    char pad_0x30[0x30 - 0x18 - sizeof(CRITICAL_SECTION)];
    SimpleArrayStub<HINSTANCE__*, void> modules;
};

void __thiscall AtlBaseModule_raises_533bb7(AtlBaseModule_533bb7* self) {
    DeleteCriticalSection((CRITICAL_SECTION*)((char*)self + 0x18));
    CSimpleArray_RemoveAll_533b80((void*)((char*)self + 0x30));
}
