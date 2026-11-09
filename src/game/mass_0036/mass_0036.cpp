// Reconstruction batch mass_0036
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Source: Ghidra 12.2 pseudocode in analysis/pseudocode/functions/
//         0x4af8c0.c .. 0x4b0df0.c (all listings read completely).
// Candidate C++ only: shapes, offsets and constants follow the decompiler
// output; names are FUN_<address> so they can be matched back to the corpus.

#include <cstdint>
#include <cstddef>
#include <string.h>
#include <windows.h>

// ---------------------------------------------------------------------------
// Decompiler scalar aliases
// ---------------------------------------------------------------------------
typedef std::uint32_t undefined4;
typedef std::uint8_t  undefined1;
typedef std::uint16_t undefined2;
typedef unsigned int  uint;

// ---------------------------------------------------------------------------
// Helper objects
// ---------------------------------------------------------------------------
struct ListEntry {
    undefined4 payload;   // +0x00
    ListEntry* next;      // +0x04
};

struct RefCounted {
    void**       vtable;   // +0x00
    std::int32_t refcount; // +0x04
};

// Engine container: +0x04 element array, +0x08 size, +0x0c capacity,
// +0x10 element count, +0x2e..+0x32 nested-node bookkeeping.
struct Container {
    std::int32_t  field_00;
    std::int32_t* elements;   // +0x04
    std::uint32_t size;       // +0x08
    std::uint32_t capacity;   // +0x0c
    std::int32_t  count;      // +0x10
};

// ---------------------------------------------------------------------------
// Externals: engine helpers referenced by the listings
// ---------------------------------------------------------------------------
extern void FUN_004f5330(void);
extern void FUN_004f2600(const char* fmt, const char* value);
extern void FUN_004baf50(void);
extern void FUN_004bdca0(void* first, ...);
extern std::int32_t FUN_004b1230(std::int32_t index);
extern undefined4 FUN_00542700(undefined4 a, undefined4 b, undefined4 c, undefined4 d,
                               std::int32_t e);
extern void FUN_004b1200(undefined4 value);
extern void FUN_00542cb0(std::int32_t a, std::int32_t b);
extern void FUN_00547760(void* object);
extern std::int32_t FUN_00533db0(std::int32_t kind);
extern std::int32_t FUN_00533c78(std::int32_t size);
extern std::int32_t FUN_005dbd60(void);
extern std::int32_t FUN_00449390(void* object);
extern void FUN_00501f40(undefined4 object, ...);
extern void FUN_00502220(std::int32_t value);
extern void FUN_004f6090(const char* fmt, ...);
extern void FUN_004baae0(void* object);
extern void FUN_004be3f0(void* object, ...);
extern void FUN_004baca0(void);
extern undefined4 FUN_005f0ddc(std::int32_t first = 0, ...);
extern void FUN_004bba60(void* self, undefined4 a, undefined4 b, undefined4 c, undefined4 d);
extern void FUN_005096b0(void);
extern void FUN_004af080(std::int32_t a, ...);
extern void FUN_004f14a0(undefined1** out_a, undefined1** out_b, const char* text);
extern undefined4* FUN_00412a60(undefined1** slot, const char* text);
extern void FUN_004f3350(void);
extern void FUN_004f32e0(void);
extern void FUN_004f1840(void);
extern void FUN_00412f90(void);
extern undefined4* FUN_004b1130(undefined1** out_a, undefined1** out_b);
extern std::int32_t FUN_004b0ea0(void);
extern std::int32_t FUN_004f6040(const char* name);
extern char FUN_004022e0(void* self, std::int32_t a, std::int32_t b, std::int32_t c);
extern std::int32_t FUN_00509720(std::int32_t mode, float value, char* text, char* out);
extern std::int32_t FUN_004aeb20(std::int32_t mode, std::int32_t x, std::int32_t y,
                                 std::uint32_t flags, std::int32_t angle);
extern std::int32_t FUN_00508e20(std::int32_t mode, float x, float y, float z, char* text,
                                 std::uint32_t flags, undefined4 out1, undefined4 out2,
                                 undefined4 out3, undefined4 out4);
extern void FUN_00524e90(void* entry);
extern void FUN_0050a3b0(undefined4 a, undefined4 b, undefined4 c, undefined4 d);
extern void FUN_0053c800(float angle, float a, float b, float c);
extern undefined4 FUN_004aae60(void);
extern void FUN_004aac10(undefined4 value);
extern void FUN_00534130(void);
extern void FUN_004af5f0(void);
extern void FUN_004127b0(void* memory, std::int32_t element_size, std::uint32_t count,
                          void* ctor);
extern void FUN_00412ec0(void);
extern char FUN_004b0f10(void);
extern char FUN_004b0fa0(void);
extern void FUN_004b1260(undefined4 mode);
extern void FUN_004b0a90(std::int32_t* self, undefined4 param_2);
extern std::int32_t thunk_FUN_00533c78(std::int32_t size);
extern void operator_delete__(void* memory);
extern "C" void LAB_00412fe0(void);

// ---------------------------------------------------------------------------
// Forward declarations of reconstructed functions used before their bodies
// ---------------------------------------------------------------------------
void FUN_004b06c0(char* param_1, std::int32_t param_2, std::int32_t param_3,
                  std::int32_t param_4, undefined4 param_5, uint param_6,
                  std::int32_t param_7, std::int32_t param_8, std::int32_t in_EAX);
void FUN_004b0b90(std::int32_t param_1, uint in_EAX);
void FUN_004b0df0(undefined1** out_string, void* self_esi, uint index_edi);

// ---------------------------------------------------------------------------
// Externals: globals used by the listings
// ---------------------------------------------------------------------------
extern std::int32_t DAT_008cabd8;                    // 0x008cabd8
extern RefCounted* DAT_008e8fb0;                     // 0x008e8fb0
extern RefCounted* DAT_008e8fb4;                     // 0x008e8fb4
extern RefCounted* DAT_008e8fb8;                     // 0x008e8fb8
extern RefCounted* DAT_008e8fbc;                     // 0x008e8fbc
extern RefCounted* DAT_008e8fc0;                     // 0x008e8fc0
extern undefined4 DAT_008cf618[];                    // 0x008cf618 (keypad slot array)
extern char* PTR_s_blank_07_007260e0[];              // 0x007260e0 (name table)
extern undefined1 DAT_008ea008[];                    // 0x008ea008 (render device)
extern undefined4 DAT_00727560;                      // 0x00727560 (node sentinel)
extern undefined4 DAT_00727598;                      // 0x00727598 (node sentinel)
extern undefined1 DAT_008c97c8[];                    // 0x008c97c8 (engine singleton)
extern std::int32_t DAT_008cac29;                    // 0x008cac29
extern std::int32_t DAT_0085a26c;                    // 0x0085a26c (screen width)
extern std::int32_t DAT_0085a268;                    // 0x0085a268 (screen height)
extern std::int32_t DAT_0085a11c;                    // 0x0085a11c
extern undefined1 DAT_00814328[];                    // 0x00814328 (slot table base)
extern undefined1 DAT_00869b48[];                    // 0x00869b48
extern std::int32_t DAT_008c9dd8;                    // 0x008c9dd8 (default layer)
extern std::int32_t DAT_008c9de0;                    // 0x008c9de0 (active layer)
extern std::int32_t DAT_00727444;                    // 0x00727444
extern undefined1 PTR_FUN_006fd14c[];                // 0x006fd14c (vtable block)
extern std::int32_t DAT_008cac00;                    // 0x008cac00
extern char         DAT_008cac04;                    // 0x008cac04
extern std::int32_t DAT_008cac18;                    // 0x008cac18 (fixed-point scale)
extern std::int32_t DAT_0072637c;                    // 0x0072637c (viewport width)
extern std::int32_t DAT_00726380;                    // 0x00726380 (viewport height)
extern std::int32_t DAT_008caccc;                    // 0x008caccc (string length)
extern std::int32_t DAT_008cacc8;                    // 0x008cacc8 (string capacity)
extern char         DAT_008cacd0[];                  // 0x008cacd0 (shared string buffer)
extern char         DAT_0070c164[];                  // 0x0070c164
extern undefined1 DAT_008e9f94[];                    // 0x008e9f94 (named-object table)
extern std::uint32_t DAT_00727888;                   // 0x00727888 (lock owner thread)
extern std::int32_t DAT_0072788c;                    // 0x0072788c (lock recursion)
extern std::int32_t* DAT_00727868;                   // 0x00727868 (free list head)
extern std::int32_t* DAT_0072786c;                   // 0x0072786c (block list head)
extern CRITICAL_SECTION DAT_00727870;                // 0x00727870
extern std::int32_t DAT_007179e8;                    // 0x007179e8 (block count)

// ---------------------------------------------------------------------------
// Local helpers reproducing the observed dispatch idioms
// ---------------------------------------------------------------------------

// (**(code **)(*object + 4))() : second vtable slot, thiscall receiver.
static inline ListEntry* scene_first_child(void* object)
{
    void** vtable = *reinterpret_cast<void***>(object);
    return reinterpret_cast<ListEntry*>(
        reinterpret_cast<void* (*)(void*)>(vtable[1])(object));
}

// (**(code **)(*object + 0x70))(a, b) : function pointer stored in the object.
static inline void invoke_field_fn(void* object, std::size_t offset, void* a,
                                   std::int32_t b)
{
    void* fn = *reinterpret_cast<void**>(static_cast<char*>(object) + offset);
    reinterpret_cast<void (*)(void*, std::int32_t)>(fn)(a, b);
}

// (**(code **)**(undefined4 **)(global + offset))(a, b)
static inline void invoke_global_double_deref(void* global_base, std::size_t offset,
                                              void* a, std::int32_t b)
{
    void*  q  = *reinterpret_cast<void**>(static_cast<char*>(global_base) + offset);
    void** pp = *reinterpret_cast<void***>(q);
    reinterpret_cast<void (*)(void*, std::int32_t)>(pp[0])(a, b);
}

// Sign comparison the listings inline (byte-wise, two bytes per iteration).
static inline std::int32_t byte_string_compare(const unsigned char* left,
                                               const unsigned char* right)
{
    for (;;) {
        unsigned char a = *left;
        unsigned char b = *right;
        if (a != b) {
            return (a < b) ? -1 : 1;
        }
        if (a == 0) {
            return 0;
        }
        ++left;
        ++right;
    }
}

static inline float ABS(float value)
{
    return (value < 0.0f) ? -value : value;
}

// ---------------------------------------------------------------------------
// 0x4af8c0
// ---------------------------------------------------------------------------
// 0x4af8c0 — observed shape
void FUN_004af8c0(void)
{
    std::int32_t iVar1;
    undefined4* puVar2;

    if (DAT_008cabd8 != 0) {
        FUN_004f5330();
        DAT_008cabd8 = 0;
    }
    puVar2 = reinterpret_cast<undefined4*>(DAT_008e8fb0);
    if (DAT_008e8fb0 != nullptr) {
        iVar1 = DAT_008e8fb0->refcount;
        DAT_008e8fb0->refcount = iVar1 - 1;
        if (iVar1 - 1 == 0) {
            void** vtable = *reinterpret_cast<void***>(puVar2);
            reinterpret_cast<void (*)(void*, std::int32_t)>(vtable[0])(puVar2, 1);
        }
        DAT_008e8fb0 = nullptr;
    }
    puVar2 = reinterpret_cast<undefined4*>(DAT_008e8fb4);
    if (DAT_008e8fb4 != nullptr) {
        iVar1 = DAT_008e8fb4->refcount;
        DAT_008e8fb4->refcount = iVar1 - 1;
        if (iVar1 - 1 == 0) {
            void** vtable = *reinterpret_cast<void***>(puVar2);
            reinterpret_cast<void (*)(void*, std::int32_t)>(vtable[0])(puVar2, 1);
        }
        DAT_008e8fb4 = nullptr;
    }
    puVar2 = reinterpret_cast<undefined4*>(DAT_008e8fb8);
    if (DAT_008e8fb8 != nullptr) {
        iVar1 = DAT_008e8fb8->refcount;
        DAT_008e8fb8->refcount = iVar1 - 1;
        if (iVar1 - 1 == 0) {
            void** vtable = *reinterpret_cast<void***>(puVar2);
            reinterpret_cast<void (*)(void*, std::int32_t)>(vtable[0])(puVar2, 1);
        }
        DAT_008e8fb8 = nullptr;
    }
    puVar2 = reinterpret_cast<undefined4*>(DAT_008e8fbc);
    if (DAT_008e8fbc != nullptr) {
        iVar1 = DAT_008e8fbc->refcount;
        DAT_008e8fbc->refcount = iVar1 - 1;
        if (iVar1 - 1 == 0) {
            void** vtable = *reinterpret_cast<void***>(puVar2);
            reinterpret_cast<void (*)(void*, std::int32_t)>(vtable[0])(puVar2, 1);
        }
        DAT_008e8fbc = nullptr;
    }
    puVar2 = reinterpret_cast<undefined4*>(DAT_008e8fc0);
    if (DAT_008e8fc0 != nullptr) {
        iVar1 = DAT_008e8fc0->refcount;
        DAT_008e8fc0->refcount = iVar1 - 1;
        if (iVar1 - 1 == 0) {
            void** vtable = *reinterpret_cast<void***>(puVar2);
            reinterpret_cast<void (*)(void*, std::int32_t)>(vtable[0])(puVar2, 1);
        }
        DAT_008e8fc0 = nullptr;
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4af990
// ---------------------------------------------------------------------------
// 0x4af990 — observed shape
void FUN_004af990(std::int32_t in_EAX)
{
    undefined4* puVar1 = &DAT_008cf618[0];
    char**      ppuVar2 = &PTR_s_blank_07_007260e0[0] + in_EAX * 9;

    do {
        FUN_004f2600("keypad_%s_dimmed.dds", *ppuVar2);
        FUN_004baf50();
        FUN_004bdca0(DAT_008ea008, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        FUN_004f2600("keypad_%s_normal.dds", *ppuVar2);
        FUN_004baf50();
        FUN_004bdca0(DAT_008ea008, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        FUN_004f2600("keypad_%s_highlight.dds", *ppuVar2);
        FUN_004baf50();
        FUN_004bdca0(DAT_008ea008, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        puVar1 = puVar1 + 0x90;
        ppuVar2 = ppuVar2 + 1;
    } while (reinterpret_cast<std::uintptr_t>(puVar1) < 0x8d0a58u);
    return;
}

// ---------------------------------------------------------------------------
// 0x4afaa0
// ---------------------------------------------------------------------------
// 0x4afaa0 — observed shape
void FUN_004afaa0(void)
{
    undefined4* puVar1 = &DAT_008cf618[0];

    do {
        FUN_004baf50();
        FUN_004baf50();
        FUN_004baf50();
        puVar1 = puVar1 + 0x90;
    } while (reinterpret_cast<std::uintptr_t>(puVar1) < 0x8d0a58u);
    return;
}

// ---------------------------------------------------------------------------
// 0x4afae0
// ---------------------------------------------------------------------------
// 0x4afae0 — observed shape
void FUN_004afae0(std::int32_t* param_1)
{
    ListEntry* puVar1;
    char*      _Str1;
    const char* _Str2;
    std::int32_t iVar2;
    uint       uVar3;

    if (param_1 != nullptr) {
        for (puVar1 = scene_first_child(param_1); puVar1 != nullptr;
             puVar1 = puVar1->next) {
            if (puVar1 == reinterpret_cast<ListEntry*>(&DAT_00727560)) {
                uVar3 = 0;
                if (param_1[0x30] == 0) {
                    return;
                }
                if (param_1[0x30] == 0) goto LAB_004afb47;
                do {
                    iVar2 = *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(param_1[0x2e] + uVar3 * 4));
                    if (iVar2 != 0) {
                        FUN_004afae0(reinterpret_cast<std::int32_t*>(
                            static_cast<std::uintptr_t>(iVar2)));
                    }
LAB_004afb47:
                    uVar3 = uVar3 + 1;
                } while (uVar3 < static_cast<uint>(param_1[0x30]));
                return;
            }
        }
        puVar1 = scene_first_child(param_1);
        if (puVar1 != nullptr) {
            while (puVar1 != reinterpret_cast<ListEntry*>(&DAT_00727598)) {
                puVar1 = puVar1->next;
                if (puVar1 == nullptr) {
                    return;
                }
            }
            if (param_1[0x32] != 0) {
                _Str2 = "EnvironmentMapNSF";
                _Str1 = reinterpret_cast<char*>(
                    static_cast<std::uintptr_t>(FUN_005dbd60()));
                iVar2 = _stricmp(_Str1, _Str2);
                if (iVar2 == 0) {
                    invoke_global_double_deref(DAT_008c97c8, 0xc, param_1, -1);
                    return;
                }
            }
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4afb90
// ---------------------------------------------------------------------------
// 0x4afb90 — observed shape
void FUN_004afb90(std::int32_t* param_1)
{
    undefined4 uVar1;
    undefined4 uVar2;
    ListEntry* puVar3;
    char*      pcVar4;
    std::int32_t iVar5;
    undefined4 uVar6;
    uint       uVar7;
    const char* pcVar8;

    if (param_1 != nullptr) {
        for (puVar3 = scene_first_child(param_1); puVar3 != nullptr;
             puVar3 = puVar3->next) {
            if (puVar3 == reinterpret_cast<ListEntry*>(&DAT_00727560)) {
                uVar7 = 0;
                if (param_1[0x30] == 0) {
                    return;
                }
                if (param_1[0x30] == 0) goto LAB_004afc0b;
                do {
                    iVar5 = *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(param_1[0x2e] + uVar7 * 4));
                    if (iVar5 != 0) {
                        FUN_004afb90(reinterpret_cast<std::int32_t*>(
                            static_cast<std::uintptr_t>(iVar5)));
                    }
LAB_004afc0b:
                    uVar7 = uVar7 + 1;
                } while (uVar7 < static_cast<uint>(param_1[0x30]));
                return;
            }
        }
        puVar3 = scene_first_child(param_1);
        if (puVar3 != nullptr) {
            while (puVar3 != reinterpret_cast<ListEntry*>(&DAT_00727598)) {
                puVar3 = puVar3->next;
                if (puVar3 == nullptr) {
                    return;
                }
            }
            if (param_1[0x32] != 0) {
                pcVar8 = "EnvironmentMapNSF";
                pcVar4 = reinterpret_cast<char*>(
                    static_cast<std::uintptr_t>(FUN_005dbd60()));
                iVar5 = _stricmp(pcVar4, pcVar8);
                if (iVar5 != 0) {
                    pcVar8 = "EnvMapMultiPassNSF";
                    pcVar4 = reinterpret_cast<char*>(
                        static_cast<std::uintptr_t>(FUN_005dbd60()));
                    iVar5 = _stricmp(pcVar4, pcVar8);
                    if (iVar5 != 0) {
                        return;
                    }
                }
                FUN_00547760(param_1);
                iVar5 = FUN_00533db0(8);
                iVar5 = *reinterpret_cast<std::int32_t*>(
                    static_cast<std::uintptr_t>(iVar5) + 0x44);
                if (((iVar5 != 0) &&
                     (2 < *reinterpret_cast<uint*>(
                              static_cast<std::uintptr_t>(iVar5) + 0xc))) &&
                    (*reinterpret_cast<std::int32_t*>(
                         static_cast<std::uintptr_t>(
                             *reinterpret_cast<std::int32_t*>(
                                 static_cast<std::uintptr_t>(iVar5) + 4)) +
                         8) != 0)) {
                    iVar5 = FUN_00533c78(0x1c);
                    if (iVar5 != 0) {
                        iVar5 = FUN_004b1230(2);
                        uVar6 = *reinterpret_cast<undefined4*>(
                            static_cast<std::uintptr_t>(iVar5) + 0xc);
                        iVar5 = FUN_004b1230(2);
                        uVar1 = *reinterpret_cast<undefined4*>(
                            static_cast<std::uintptr_t>(iVar5) + 8);
                        iVar5 = FUN_004b1230(2);
                        uVar2 = *reinterpret_cast<undefined4*>(
                            static_cast<std::uintptr_t>(iVar5) + 0x10);
                        iVar5 = FUN_004b1230(2);
                        uVar6 = FUN_00542700(
                            *reinterpret_cast<undefined4*>(
                                static_cast<std::uintptr_t>(iVar5) + 4),
                            uVar2, uVar1, uVar6, 0);
                        FUN_004b1200(uVar6);
                        FUN_00542cb0(2, 0);
                        return;
                    }
                    FUN_004b1200(0);
                    FUN_00542cb0(2, 0);
                }
            }
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4afd20
// ---------------------------------------------------------------------------
// 0x4afd20 — observed shape
// receiver: EBX (self)
void FUN_004afd20(void* self_ebx)
{
    uint       uVar1;
    std::int32_t iVar2;
    ListEntry* puVar3;
    std::int32_t iVar4;
    std::int32_t* unaff_EBX = reinterpret_cast<std::int32_t*>(self_ebx);

    if (DAT_008cac29 != 0) {
        FUN_004afb90(unaff_EBX);   // ECX receiver supplied by the caller
        if ((unaff_EBX != nullptr) &&
            (puVar3 = scene_first_child(unaff_EBX), puVar3 != nullptr)) {
LAB_004afd46:
            if (puVar3 != reinterpret_cast<ListEntry*>(&DAT_00727560)) {
                puVar3 = puVar3->next;
                if (puVar3 == nullptr) goto LAB_004afd94;
                goto LAB_004afd46;
            }
            iVar4 = FUN_00449390(&DAT_00727560);
            uVar1 = *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(iVar4) + 0xc0);
            while (uVar1 = uVar1 - 1, static_cast<std::int32_t>(uVar1) >= 0) {
                if ((uVar1 < *reinterpret_cast<uint*>(
                                 static_cast<std::uintptr_t>(iVar4) + 0xc0)) &&
                    (iVar2 = *reinterpret_cast<std::int32_t*>(
                         static_cast<std::uintptr_t>(
                             *reinterpret_cast<std::int32_t*>(
                                 static_cast<std::uintptr_t>(iVar4) + 0xb8)) +
                         uVar1 * 4),
                     iVar2 != 0)) {
                    FUN_00501f40(static_cast<undefined4>(
                                     static_cast<std::uintptr_t>(iVar2)), 3);
                }
            }
        }
LAB_004afd94:
        iVar4 = FUN_00533db0(8);
        if (iVar4 != 0) {
            FUN_00502220(0);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4afdb0
// ---------------------------------------------------------------------------
// 0x4afdb0 — observed shape
void FUN_004afdb0(undefined4 param_1)
{
    FUN_004f6090("Paused");
    FUN_004b06c0(reinterpret_cast<char*>(DAT_00869b48), DAT_0085a26c / 2,
                 DAT_0085a268 / 2 + -0xc, DAT_0085a11c, param_1, 4, 0xffffffff, 0);
    return;
}

// ---------------------------------------------------------------------------
// 0x4afe00
// ---------------------------------------------------------------------------
// 0x4afe00 — observed shape
// receiver: EAX (slot index)
undefined4 FUN_004afe00(std::int32_t in_EAX)
{
    std::int32_t iValue;

    if (in_EAX == -1) {
        return 0xffffff00u;
    }
    iValue = static_cast<std::int32_t>(
                 *reinterpret_cast<std::int16_t*>(DAT_00814328 + in_EAX * 0x45c)) /
             500;
    return (static_cast<undefined4>(iValue) & 0xffffff00u) |
           ((1 < iValue) ? 1u : 0u);
}

// ---------------------------------------------------------------------------
// 0x4afe30
// ---------------------------------------------------------------------------
// 0x4afe30 — observed shape
undefined4* FUN_004afe30(void)
{
    std::int32_t iVar1;
    undefined4   uVar2;
    undefined4*  puVar3;
    std::int32_t iVar4;

    puVar3 = reinterpret_cast<undefined4*>(static_cast<std::uintptr_t>(FUN_00533c78(0xc0)));
    uVar2 = static_cast<undefined4>(reinterpret_cast<std::uintptr_t>(DAT_008ea008));
    iVar1 = DAT_0085a26c;
    if (puVar3 == nullptr) {
        return nullptr;
    }
    iVar4 = DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7U);
    puVar3[1] = 0;
    *reinterpret_cast<void**>(puVar3) =
        reinterpret_cast<void*>(PTR_FUN_006fd14c);
    puVar3[7] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    puVar3[0x19] = 0;
    puVar3[0x2f] = 0;
    GetCurrentThreadId();
    FUN_004baae0(DAT_008ea008);
    puVar3[8] = 0;
    FUN_004be3f0(puVar3, 0, 0, 0, iVar1 + 2, (iVar4 >> 3) + 1, 0xff000000, 0, 0, 0, 0, 0);
    if ((*reinterpret_cast<unsigned char*>(puVar3 + 8) & 1) == 0) {
        FUN_004baca0();
    }
    return puVar3;
}

// ---------------------------------------------------------------------------
// 0x4afee0
// ---------------------------------------------------------------------------
// 0x4afee0 — observed shape
// receiver: ESI (self)
void FUN_004afee0(void* self_esi)
{
    undefined4 uVar1;
    undefined4 uVar2;
    undefined4 uVar3;
    undefined4 uVar4;

    if (self_esi != nullptr) {
        uVar4 = 0;
        uVar3 = 0x42c80000;
        uVar1 = FUN_005f0ddc(0x42c80000, 0);
        uVar2 = FUN_005f0ddc(uVar1);
        FUN_004bba60(self_esi, uVar2, uVar1, uVar3, uVar4);
        uVar4 = 0;
        uVar3 = 0x42c80000;
        uVar1 = FUN_005f0ddc(
            0x42c80000, 0,
            DAT_0085a268 - ((static_cast<std::int32_t>(
                                 DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7U))) >> 3));
        uVar2 = FUN_005f0ddc(uVar1);
        FUN_004bba60(self_esi, uVar2, uVar1, uVar3, uVar4);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4aff70
// ---------------------------------------------------------------------------
// 0x4aff70 — observed shape
void FUN_004aff70(char* param_1)
{
    std::int32_t iVar1;
    std::int32_t iVar2;
    uint         uVar3;

    DAT_008c9de0 = DAT_008c9dd8;
    FUN_005096b0();
    iVar2 = FUN_005f0ddc();
    uVar3 = (DAT_0085a268 -
             (static_cast<std::int32_t>(DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0x1fU)) >> 5)) -
            iVar2 &
            0xfffffffe;
    iVar2 = iVar2 + 0x12;
    iVar1 = static_cast<std::int32_t>(uVar3) - 0x10;
    FUN_004af080(0, 0, 0, 0, 0, 0xffffffff, iVar1, DAT_0085a26c + 2, iVar2, 0xff000000, 0xc0);
    FUN_004af080(0, 0, 0, 0, 0, 0xffffffff, iVar1, DAT_0085a26c + 2, iVar2, 0xff000000, 0xc0);
    FUN_004af080(0, 0, 0, 0, 0, 0xffffffff, iVar1, DAT_0085a26c + 2, iVar2, 0xff000000, 0xc0);
    FUN_004af080(0, 0, 0, 0, 0, 0xffffffff, iVar1, DAT_0085a26c + 2, iVar2, 0xff000000, 0xc0);
    FUN_004af080(0, 0, 0, 0, 0, 0xffffffff, iVar1, DAT_0085a26c + 2, iVar2, 0xff000000, 0xc0);
    FUN_004b06c0(param_1, DAT_0085a26c / 2, static_cast<std::int32_t>(uVar3), DAT_0085a11c,
                 0xffffffff, 4, 0xffffffff, 0);
    return;
}

// ---------------------------------------------------------------------------
// 0x4b00e0
// ---------------------------------------------------------------------------
// 0x4b00e0 — observed shape
std::int32_t FUN_004b00e0(std::int32_t param_1, std::int32_t param_2)
{
    char        cVar1;
    bool        bVar2;
    undefined4* puVar3;
    std::int32_t* piVar4;
    HANDLE      hFindFile;
    CHAR*       pCVar5;
    std::size_t sVar6;
    std::int32_t iVar7;
    BOOL        BVar8;
    undefined1* puVar9;
    std::int32_t iVar10;
    undefined1* local_15c;
    undefined1* local_158;
    std::int32_t local_154;
    std::int32_t local_150;
    undefined1* local_14c;
    undefined1* local_148;
    undefined1* local_144;
    WIN32_FIND_DATAA local_140;
    std::int32_t local_160;

    local_160 = 0;
    local_150 = 0;
    local_14c = reinterpret_cast<undefined1*>(DAT_008cacd0);
    local_148 = reinterpret_cast<undefined1*>(DAT_008cacd0);
    local_144 = reinterpret_cast<undefined1*>(DAT_008cacd0);
    local_158 = reinterpret_cast<undefined1*>(DAT_008cacd0);
    local_15c = reinterpret_cast<undefined1*>(DAT_008cacd0);
    do {
        if (local_150 == 0) {
            const char* pcVar12 = "custom";
            undefined1** ppuVar11 = &local_14c;
            FUN_004f14a0(&local_144, ppuVar11, "custom");
            puVar3 = FUN_00412a60(ppuVar11, pcVar12);
            puVar9 = reinterpret_cast<undefined1*>(static_cast<std::uintptr_t>(*puVar3));
            sVar6 = *reinterpret_cast<std::size_t*>(puVar9 - 4);
            if (((static_cast<std::int32_t>(sVar6) > -1) && (puVar9 != nullptr)) &&
                (puVar9 != reinterpret_cast<undefined1*>(DAT_008cacd0))) {
                if (sVar6 == 0) {
                    if (DAT_008caccc != 0) {
                        DAT_008cacd0[0] = 0;
                        DAT_008caccc = 0;
                    }
                } else {
                    FUN_004f3350();
                    memmove(DAT_008cacd0, puVar9, sVar6);
                    DAT_008cacd0[DAT_008caccc] = 0;
                }
            }
            piVar4 = reinterpret_cast<std::int32_t*>(local_14c - 8);
            if ((piVar4 != nullptr) &&
                (piVar4 != reinterpret_cast<std::int32_t*>(&DAT_008cacc8))) {
                operator_delete__(piVar4);
            }
            piVar4 = reinterpret_cast<std::int32_t*>(local_144 - 8);
            local_14c = reinterpret_cast<undefined1*>(DAT_008cacd0);
            if ((piVar4 != nullptr) &&
                (piVar4 != reinterpret_cast<std::int32_t*>(&DAT_008cacc8))) {
                operator_delete__(piVar4);
            }
            local_144 = reinterpret_cast<undefined1*>(DAT_008cacd0);
        } else {
            FUN_004f3350();
            memmove(DAT_008cacd0, "custom", 6);
            DAT_008cacd0[DAT_008caccc] = 0;
        }
        iVar7 = DAT_008caccc;
        iVar10 = 0;
        if (-1 < DAT_008caccc) {
            if (DAT_008caccc < DAT_008caccc + 1) {
                FUN_004f3350();
                DAT_008cacd0[DAT_008caccc] = 0;
            }
            memmove(DAT_008cacd0 + iVar7, DAT_0070c164, 1);
        }
        while (true) {
            if (((iVar10 < *reinterpret_cast<std::int32_t*>(
                                static_cast<std::uintptr_t>(param_1) - 4)) &&
                 (-1 < iVar10)) &&
                (pCVar5 = strchr(reinterpret_cast<char*>(static_cast<std::uintptr_t>(param_1) +
                                                        iVar10),
                                 0x3b),
                 pCVar5 != nullptr)) {
                local_154 = static_cast<std::int32_t>(
                    reinterpret_cast<std::uintptr_t>(pCVar5) -
                    static_cast<std::uintptr_t>(param_1));
            } else {
                local_154 = -1;
            }
            if (-1 < local_154) {
                local_154 = local_154 + 1;
            }
            FUN_004f1840();
            puVar3 = FUN_004b1130(&local_148, &local_158);
            puVar9 = reinterpret_cast<undefined1*>(static_cast<std::uintptr_t>(*puVar3));
            sVar6 = *reinterpret_cast<std::size_t*>(puVar9 - 4);
            if (((static_cast<std::int32_t>(sVar6) > -1) && (puVar9 != nullptr)) &&
                (puVar9 != reinterpret_cast<undefined1*>(DAT_008cacd0))) {
                if (sVar6 == 0) {
                    if (DAT_008caccc != 0) {
                        DAT_008cacd0[0] = 0;
                        DAT_008caccc = 0;
                    }
                } else {
                    if (0 < static_cast<std::int32_t>(sVar6)) {
                        if (DAT_008cacc8 < static_cast<std::int32_t>(sVar6)) {
                            FUN_004f32e0();
                        }
                        DAT_008caccc = static_cast<std::int32_t>(sVar6);
                    }
                    memmove(DAT_008cacd0, puVar9, sVar6);
                    DAT_008cacd0[DAT_008caccc] = 0;
                }
            }
            piVar4 = reinterpret_cast<std::int32_t*>(local_148 - 8);
            if ((piVar4 != nullptr) &&
                (piVar4 != reinterpret_cast<std::int32_t*>(&DAT_008cacc8))) {
                operator_delete__(piVar4);
            }
            piVar4 = reinterpret_cast<std::int32_t*>(local_158 - 8);
            local_148 = reinterpret_cast<undefined1*>(DAT_008cacd0);
            if ((piVar4 != nullptr) &&
                (piVar4 != reinterpret_cast<std::int32_t*>(&DAT_008cacc8))) {
                operator_delete__(piVar4);
            }
            local_158 = reinterpret_cast<undefined1*>(DAT_008cacd0);
            hFindFile = FindFirstFileA(DAT_008cacd0, &local_140);
            if (hFindFile != INVALID_HANDLE_VALUE) {
                do {
                    puVar9 = reinterpret_cast<undefined1*>(DAT_008cacd0);
                    pCVar5 = local_140.cFileName;
                    local_15c = reinterpret_cast<undefined1*>(DAT_008cacd0);
                    do {
                        cVar1 = *pCVar5;
                        pCVar5 = pCVar5 + 1;
                    } while (cVar1 != '\0');
                    sVar6 = static_cast<std::size_t>(
                        pCVar5 - (local_140.cFileName + 1));
                    if (-1 < static_cast<std::int32_t>(sVar6)) {
                        if (sVar6 == 0) {
                            if (DAT_008caccc != 0) {
                                DAT_008cacd0[0] = 0;
                                DAT_008caccc = 0;
                            }
                        } else {
                            if (0 < static_cast<std::int32_t>(sVar6)) {
                                if (DAT_008cacc8 < static_cast<std::int32_t>(sVar6)) {
                                    FUN_004f32e0();
                                }
                                *reinterpret_cast<std::size_t*>(local_15c - 4) = sVar6;
                            }
                            puVar9 = local_15c;
                            memmove(local_15c, local_140.cFileName, sVar6);
                            puVar9[*reinterpret_cast<std::int32_t*>(puVar9 - 4)] = 0;
                        }
                    }
                    iVar7 = FUN_004b0ea0();
                    if (iVar7 == -1) {
                        if (*reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_2) + 8) <=
                            *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_2) + 0xc)) {
                            // EAX argument reconstructed from the container size compared above.
                            FUN_004b0b90(param_2,
                                         *reinterpret_cast<uint*>(
                                             static_cast<std::uintptr_t>(param_2) + 0xc));
                        }
                        // ESI/EDI register inputs: container and its current element count.
                        FUN_004b0df0(&local_15c,
                                     reinterpret_cast<void*>(static_cast<std::uintptr_t>(param_2)),
                                     *reinterpret_cast<uint*>(
                                         static_cast<std::uintptr_t>(param_2) + 0xc));
                        bVar2 = true;
                    } else {
                        bVar2 = false;
                    }
                    piVar4 = reinterpret_cast<std::int32_t*>(puVar9 - 8);
                    if ((piVar4 != nullptr) &&
                        (piVar4 != reinterpret_cast<std::int32_t*>(&DAT_008cacc8))) {
                        operator_delete__(piVar4);
                    }
                    if (bVar2) {
                        local_160 = local_160 + 1;
                    }
                    BVar8 = FindNextFileA(hFindFile, &local_140);
                } while (BVar8 != 0);
                FindClose(hFindFile);
            }
            if (local_154 < 0) break;
            iVar10 = local_154;
        }
        local_150 = local_150 + 1;
    } while (local_150 < 2);
    piVar4 = reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(param_1) - 8);
    if ((piVar4 != nullptr) &&
        (piVar4 != reinterpret_cast<std::int32_t*>(&DAT_008cacc8))) {
        operator_delete__(piVar4);
    }
    return local_160;
}

// ---------------------------------------------------------------------------
// 0x4b04e0
// ---------------------------------------------------------------------------
// 0x4b04e0 — observed shape
undefined4 FUN_004b04e0(void)
{
    char         cVar1;
    std::int32_t iVar2;
    std::int32_t iVar3;

    iVar3 = 0;
    while (true) {
        iVar2 = FUN_004f6040("SAVEGAME_SLOT");
        if ((iVar2 < 0) ||
            (iVar2 = *reinterpret_cast<std::int32_t*>(
                 static_cast<std::uintptr_t>(
                     *reinterpret_cast<std::int32_t*>(DAT_008e9f94 + iVar2 * 4)) +
                 8),
             iVar2 == 0)) {
            iVar2 = 0;
        } else {
            iVar2 = *reinterpret_cast<std::int32_t*>(
                static_cast<std::uintptr_t>(iVar2) + 0xc);
        }
        if (iVar2 <= iVar3) break;
        FUN_004f6090("@SAVEGAME_SLOT", iVar3);
        cVar1 = FUN_004022e0(static_cast<void*>(DAT_00869b48), 1, 1, 0);
        if (cVar1 != '\0') {
            return 1;
        }
        iVar3 = iVar3 + 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x4b0560
// ---------------------------------------------------------------------------
// 0x4b0560 — observed shape
// receiver: BL (input flag)
void FUN_004b0560(char unaff_BL)
{
    std::int32_t   iVar1;
    OSVERSIONINFOA* p_Var2;
    INPUT          local_1d8;
    undefined4     local_1bc;
    undefined2     local_1b8;
    undefined2     local_1b6;
    undefined4     local_1b4;
    OSVERSIONINFOA local_1a0;
    BYTE           local_108[144];
    BYTE           local_78;

    p_Var2 = &local_1a0;
    for (iVar1 = 0x25; iVar1 != 0; iVar1 = iVar1 + -1) {
        p_Var2->dwOSVersionInfoSize = 0;
        p_Var2 = reinterpret_cast<OSVERSIONINFOA*>(&p_Var2->dwMajorVersion);
    }
    local_1a0.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_1a0);
    if (local_1a0.dwPlatformId != 1) {
        local_1bc = 1;
        local_1d8.type = 1;
        local_1b8 = 0x90;
        local_1d8.u.ki.wVk = 0x90;
        local_1b6 = 0;
        local_1d8.u.ki.wScan = 0;
        local_1d8.u.mi.dy = 0;
        local_1b4 = 2;
        SendInput((unaff_BL == '\0') + 1, &local_1d8, 0x1c);
        return;
    }
    GetKeyboardState(local_108);
    if (unaff_BL == '\0') {
        local_78 = local_78 & 1;
    } else {
        local_78 = local_78 | 1;
    }
    SetKeyboardState(local_108);
    return;
}

// ---------------------------------------------------------------------------
// 0x4b0650
// ---------------------------------------------------------------------------
// 0x4b0650 — observed shape
// receiver: EDI (node to push)
void FUN_004b0650(undefined4* unaff_EDI)
{
    DWORD DVar1;

    DVar1 = GetCurrentThreadId();
    if (DAT_00727888 != DVar1) {
        EnterCriticalSection(&DAT_00727870);
        DAT_00727888 = GetCurrentThreadId();
    }
    DAT_0072788c = DAT_0072788c + 1;
    unaff_EDI[1] = 0;
    *unaff_EDI = static_cast<undefined4>(
        reinterpret_cast<std::uintptr_t>(DAT_00727868));
    DAT_00727868 = reinterpret_cast<std::int32_t*>(unaff_EDI);
    DVar1 = GetCurrentThreadId();
    if ((DAT_00727888 == DVar1) &&
        (DAT_0072788c = DAT_0072788c + -1, DAT_0072788c == 0)) {
        DAT_00727888 = 0;
        LeaveCriticalSection(&DAT_00727870);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4b06c0
// ---------------------------------------------------------------------------
// 0x4b06c0 — observed shape
// receiver: EAX (layer handle, 0 selects DAT_008c9dd8)
void FUN_004b06c0(char* param_1, std::int32_t param_2, std::int32_t param_3,
                  std::int32_t param_4, undefined4 param_5, uint param_6,
                  std::int32_t param_7, std::int32_t param_8, std::int32_t in_EAX)
{
    char         cVar1;
    float        fVar2;
    float        fVar3;
    float        fVar4;
    float        fVar5;
    char*        pcVar6;
    std::int32_t iVar7;
    std::int32_t iVar8;
    std::int32_t iVar9;
    undefined4   uVar10;
    std::int32_t* piVar12;
    std::int32_t* piVar13;
    bool         bVar14;
    // NEEDS_MANUAL: the listing reads the stack slot at ebp-0x434 as a
    // pointer base but never writes it (inlined temp-string destructor
    // bookkeeping); its true value is not exposed by the pseudocode.
    std::int32_t iStack_434;
    undefined4   local_418;
    undefined4   local_414;
    undefined4   local_410;
    undefined4   local_40c;
    char         local_404[1028];

    iStack_434 = 0;
    local_404[0] = '\0';
    pcVar6 = param_1;
    do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (pcVar6 == param_1 + 1) {
        DAT_0085a11c = 100;
        return;
    }
    bVar14 = (param_6 & 0x40000000) == 0x40000000;
    fVar2 = static_cast<float>(param_2) - static_cast<float>(DAT_0072637c / 2);
    iVar7 = DAT_00726380 / 2;
    param_6 = param_6 & 0xbfffffff;
    if (DAT_008cac04 == '\0') {
        fVar4 = 100.0f;
    } else {
        fVar4 = -100.0f;
    }
    fVar5 = static_cast<float>(DAT_008cac00);
    if (DAT_008cac00 < 0) {
        fVar5 = fVar5 + 4.2949673e+09f;
    }
    DAT_008cac00 = DAT_008cac00 + 1;
    FUN_004b1260(param_5);
    fVar3 = -(static_cast<float>(param_3) - static_cast<float>(iVar7));
    iVar7 = (static_cast<std::int32_t>(DAT_008cac18 * param_4 +
                                       ((DAT_008cac18 * param_4) >> 0x1f & 0x3ffU))) >>
            10;
    if (in_EAX == 0) {
        in_EAX = DAT_008c9dd8;
    }
    DAT_008c9de0 = in_EAX;
    if (bVar14) {
        FUN_00509720(
            in_EAX,
            static_cast<float>(
                (((static_cast<std::int32_t>(
                       DAT_008cac18 * param_7 +
                       ((DAT_008cac18 * param_7) >> 0x1f & 0x3ffU))) >>
                  10) *
                 100) /
                iVar7),
            param_1, local_404);
    }
    iVar8 = FUN_004aeb20(DAT_008c9de0, param_2, param_3, param_6, param_8);
    if (iVar8 == 0) {
        pcVar6 = local_404;
        if (!bVar14) {
            pcVar6 = param_1;
        }
        iVar9 = FUN_00508e20(DAT_008c9de0, fVar2, -(fVar5 / fVar4), fVar3, pcVar6, param_6,
                             local_418, local_414, local_410, local_40c);
        piVar12 = reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(FUN_00533c78(0x14)));
        iVar8 = DAT_008c9de0;
        *piVar12 = iVar9;
        piVar12[1] = iVar8;
        *reinterpret_cast<undefined1*>(piVar12 + 2) = 1;
        piVar12[3] = static_cast<std::int32_t>(param_6);
        *reinterpret_cast<undefined2*>(piVar12 + 4) = static_cast<undefined2>(param_8);
        piVar13 = reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(iVar9) + 0x34);
        iVar8 = FUN_00533db0(0xb);
        if (iVar8 == 0) {
            iVar8 = FUN_00533c78(0x28);
            if (iVar8 == 0) {
                uVar10 = 0;
            } else {
                uVar10 = FUN_004aae60();
            }
            FUN_004aac10(uVar10);
            FUN_00534130();
        }
        FUN_00524e90(piVar12);
    } else {
        FUN_0050a3b0(local_418, local_414, local_410, local_40c);
        iVar9 = *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(iVar8) + 0x34);
        piVar13 = reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(iVar8) + 0x34);
        *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar9) + 0x5c) = fVar2;
        *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar9) + 0x60) = -(fVar5 / fVar4);
        *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar9) + 100) = fVar3;
        if (param_8 != 0) {
            FUN_0053c800(static_cast<float>(param_8) * 0.017453292f, 0.0f, 1.0f, 0.0f);
        }
    }
    iVar8 = *piVar13;
    *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar8) + 0x68) =
        ABS((static_cast<float>(iVar7) * 0.01f * static_cast<float>(DAT_0072637c)) /
            static_cast<float>(DAT_008cac18));
    if (param_8 != 0) {
        FUN_0053c800(static_cast<float>(param_8) * 0.017453292f, 0.0f, 1.0f, 0.0f);
    }
    iVar7 = FUN_00533db0(0xb);
    if (iVar7 != 0) {
        *reinterpret_cast<unsigned char*>(static_cast<std::uintptr_t>(iVar7) + 0x20) &=
            0xfc;
    }
    if (*reinterpret_cast<std::int32_t*>(
            reinterpret_cast<std::uintptr_t>(DAT_008ea008) + 0xc0) == 0) {
        piVar12 = nullptr;
    } else {
        undefined4** pp =
            reinterpret_cast<undefined4**>(DAT_008ea008 + 0xb8);
        piVar12 = reinterpret_cast<std::int32_t*>(
            static_cast<std::uintptr_t>(**pp));
    }
    invoke_field_fn(
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(*piVar12)), 0x70,
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(iVar8)), 1);
    {
        undefined4* puVar11 = reinterpret_cast<undefined4*>(
            static_cast<std::uintptr_t>(iStack_434) - 8);
        DAT_0085a11c = 100;
        if ((puVar11 != nullptr) &&
            (puVar11 != reinterpret_cast<undefined4*>(&DAT_008cacc8))) {
            operator_delete__(puVar11);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4b0a90
// ---------------------------------------------------------------------------
// 0x4b0a90 — observed shape
void FUN_004b0a90(std::int32_t* param_1, undefined4 param_2)
{
    ListEntry*  puVar1;
    undefined4  uVar2;
    uint        uVar3;

    if (param_1 != nullptr) {
        for (puVar1 = scene_first_child(param_1); puVar1 != nullptr;
             puVar1 = puVar1->next) {
            if (puVar1 == reinterpret_cast<ListEntry*>(&DAT_00727598)) {
                FUN_004af5f0();
                break;
            }
        }
        puVar1 = scene_first_child(param_1);
        if (puVar1 != nullptr) {
            while (puVar1 != reinterpret_cast<ListEntry*>(&DAT_00727560)) {
                puVar1 = puVar1->next;
                if (puVar1 == nullptr) {
                    return;
                }
            }
            uVar3 = 0;
            if (param_1[0x30] != 0) {
                if (param_1[0x30] != 0) goto LAB_004b0afe;
                uVar2 = 0;
                while (true) {
                    FUN_004b0a90(
                        reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(uVar2)),
                        param_2);
                    uVar3 = uVar3 + 1;
                    if (static_cast<uint>(param_1[0x30]) <= uVar3) break;
LAB_004b0afe:
                    uVar2 = *reinterpret_cast<undefined4*>(static_cast<std::uintptr_t>(param_1[0x2e] + uVar3 * 4));
                }
            }
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4b0b20
// ---------------------------------------------------------------------------
// 0x4b0b20 — observed shape
void FUN_004b0b20(void)
{
    std::int32_t  iVar1;
    std::int32_t* piVar2;
    std::int32_t* piVar3;
    uint          uVar4;
    bool          bVar5;

    piVar2 = reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(thunk_FUN_00533c78(DAT_007179e8 * 0xc)));
    iVar1 = DAT_007179e8;
    DAT_00727868 = piVar2 + 3;
    piVar2[DAT_007179e8 * 3 + -3] = 0;
    piVar3 = DAT_00727868;
    uVar4 = 1;
    do {
        *piVar3 = static_cast<std::int32_t>(
            reinterpret_cast<std::uintptr_t>(piVar3 + 3));
        piVar3 = piVar3 + 3;
        bVar5 = uVar4 < static_cast<uint>(iVar1) - 2U;
        uVar4 = uVar4 + 1;
    } while (bVar5);
    if (DAT_0072786c == nullptr) {
        DAT_0072786c = piVar2;
        *piVar2 = 0;
        return;
    }
    *piVar2 = static_cast<std::int32_t>(
        reinterpret_cast<std::uintptr_t>(DAT_0072786c));
    DAT_0072786c = piVar2;
    return;
}

// ---------------------------------------------------------------------------
// 0x4b0b90
// ---------------------------------------------------------------------------
// 0x4b0b90 — observed shape
// receiver: EAX (requested element count)
void FUN_004b0b90(std::int32_t param_1, uint in_EAX)
{
    std::int32_t  iVar2;
    undefined1*   puVar3;
    undefined1*   puVar4;
    unsigned char* pbVar5;
    std::int32_t  iVar6;
    uint*         puVar7;
    std::size_t   sVar8;
    undefined4*   puVar9;
    uint          uVar10;
    unsigned char* pbVar11;
    uint*         puVar12;
    undefined4*   puVar13;
    std::int32_t* piVar14;
    uint          local_4;

    if (in_EAX != *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 8)) {
        if (in_EAX < *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 0xc)) {
            local_4 = in_EAX;
            do {
                iVar2 = DAT_008caccc;
                piVar14 = reinterpret_cast<std::int32_t*>(
                    static_cast<std::uintptr_t>(
                        *reinterpret_cast<std::int32_t*>(
                            static_cast<std::uintptr_t>(param_1) + 4)) +
                    local_4 * 4);
                pbVar5 = reinterpret_cast<unsigned char*>(static_cast<std::uintptr_t>(*piVar14));
                pbVar11 = reinterpret_cast<unsigned char*>(DAT_008cacd0);
                iVar6 = byte_string_compare(pbVar5, pbVar11);
                if (iVar6 != 0) {
                    if ((-1 < DAT_008caccc) &&
                        (reinterpret_cast<undefined1*>(static_cast<std::uintptr_t>(*piVar14)) !=
                         reinterpret_cast<undefined1*>(DAT_008cacd0))) {
                        if (DAT_008caccc == 0) {
                            FUN_00412f90();
                        } else {
                            FUN_004f3350();
                            memmove(reinterpret_cast<void*>(static_cast<std::uintptr_t>(*piVar14)), DAT_008cacd0,
                                    static_cast<std::size_t>(iVar2));
                            *reinterpret_cast<undefined1*>(
                                static_cast<std::uintptr_t>(*piVar14) +
                                *reinterpret_cast<std::int32_t*>(
                                    static_cast<std::uintptr_t>(*piVar14) - 4)) = 0;
                        }
                    }
                    *reinterpret_cast<std::int32_t*>(
                        static_cast<std::uintptr_t>(param_1) + 0x10) =
                        *reinterpret_cast<std::int32_t*>(
                            static_cast<std::uintptr_t>(param_1) + 0x10) -
                        1;
                }
                local_4 = local_4 + 1;
            } while (local_4 <
                     *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 0xc));
            *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 0xc) = in_EAX;
        }
        iVar2 = *reinterpret_cast<std::int32_t*>(static_cast<std::uintptr_t>(param_1) + 4);
        puVar12 = nullptr;
        *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 8) = in_EAX;
        if (in_EAX == 0) {
            *reinterpret_cast<undefined4*>(static_cast<std::uintptr_t>(param_1) + 4) = 0;
        } else {
            puVar7 = reinterpret_cast<uint*>(static_cast<std::uintptr_t>(thunk_FUN_00533c78(in_EAX * 4 + 4)));
            if (puVar7 != nullptr) {
                puVar12 = puVar7 + 1;
                *puVar7 = in_EAX;
                FUN_004127b0(puVar12, 4, in_EAX,
                             reinterpret_cast<void*>(&LAB_00412fe0));
            }
            uVar10 = 0;
            *reinterpret_cast<uint**>(static_cast<std::uintptr_t>(param_1) + 4) = puVar12;
            if (*reinterpret_cast<std::int32_t*>(
                    static_cast<std::uintptr_t>(param_1) + 0xc) != 0) {
                do {
                    puVar3 = *reinterpret_cast<undefined1**>(static_cast<std::uintptr_t>(uVar10 * 4 + iVar2));
                    sVar8 = *reinterpret_cast<std::size_t*>(puVar3 - 4);
                    piVar14 = reinterpret_cast<std::int32_t*>(
                        static_cast<std::uintptr_t>(
                            *reinterpret_cast<std::int32_t*>(
                                static_cast<std::uintptr_t>(param_1) + 4)) +
                        uVar10 * 4);
                    if (((static_cast<std::int32_t>(sVar8) > -1) && (puVar3 != nullptr)) &&
                        (puVar4 = reinterpret_cast<undefined1*>(static_cast<std::uintptr_t>(*piVar14)),
                         puVar3 != puVar4)) {
                        if (sVar8 == 0) {
                            if (*reinterpret_cast<std::int32_t*>(puVar4 - 4) != 0) {
                                *puVar4 = 0;
                                *reinterpret_cast<undefined4*>(static_cast<std::uintptr_t>(*piVar14) - 4) = 0;
                            }
                        } else {
                            FUN_004f3350();
                            memmove(reinterpret_cast<void*>(static_cast<std::uintptr_t>(*piVar14)), puVar3, sVar8);
                            *reinterpret_cast<undefined1*>(
                                static_cast<std::uintptr_t>(*piVar14) +
                                *reinterpret_cast<std::int32_t*>(
                                    static_cast<std::uintptr_t>(*piVar14) - 4)) = 0;
                        }
                    }
                    uVar10 = uVar10 + 1;
                } while (uVar10 <
                         *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 0xc));
            }
            uVar10 = *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 0xc);
            if (uVar10 < *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 8)) {
                sVar8 = static_cast<std::size_t>(DAT_008caccc);
                do {
                    piVar14 = reinterpret_cast<std::int32_t*>(
                        static_cast<std::uintptr_t>(
                            *reinterpret_cast<std::int32_t*>(
                                static_cast<std::uintptr_t>(param_1) + 4)) +
                        uVar10 * 4);
                    if (-1 < static_cast<std::int32_t>(sVar8)) {
                        puVar3 = reinterpret_cast<undefined1*>(static_cast<std::uintptr_t>(*piVar14));
                        if (puVar3 != reinterpret_cast<undefined1*>(DAT_008cacd0)) {
                            if (sVar8 == 0) {
                                if (*reinterpret_cast<std::int32_t*>(puVar3 - 4) == 0) {
                                    goto LAB_004b0d89;
                                }
                                *puVar3 = 0;
                                *reinterpret_cast<undefined4*>(static_cast<std::uintptr_t>(*piVar14) - 4) = 0;
                            } else {
                                if (0 < static_cast<std::int32_t>(sVar8)) {
                                    if (*reinterpret_cast<std::int32_t*>(puVar3 - 8) <
                                        static_cast<std::int32_t>(sVar8)) {
                                        FUN_004f32e0();
                                    }
                                    *reinterpret_cast<std::size_t*>(static_cast<std::uintptr_t>(*piVar14) - 4) = sVar8;
                                }
                                memmove(reinterpret_cast<void*>(static_cast<std::uintptr_t>(*piVar14)), DAT_008cacd0,
                                        sVar8);
                                *reinterpret_cast<undefined1*>(
                                    static_cast<std::uintptr_t>(*piVar14) +
                                    *reinterpret_cast<std::int32_t*>(
                                        static_cast<std::uintptr_t>(*piVar14) - 4)) = 0;
                            }
                            sVar8 = static_cast<std::size_t>(DAT_008caccc);
                        }
                    }
LAB_004b0d89:
                    uVar10 = uVar10 + 1;
                } while (uVar10 <
                         *reinterpret_cast<uint*>(static_cast<std::uintptr_t>(param_1) + 8));
            }
        }
        if (iVar2 != 0) {
            iVar6 = *reinterpret_cast<std::int32_t*>(
                static_cast<std::uintptr_t>(iVar2) - 4);
            puVar13 = reinterpret_cast<undefined4*>(static_cast<std::uintptr_t>(iVar2 + iVar6 * 4));
            if (-1 < iVar6 - 1) {
                do {
                    piVar14 = reinterpret_cast<std::int32_t*>(puVar13 - 1);
                    puVar13 = puVar13 - 1;
                    puVar9 = reinterpret_cast<undefined4*>(
                        static_cast<std::uintptr_t>(*piVar14) - 8);
                    if ((puVar9 != nullptr) &&
                        (puVar9 != reinterpret_cast<undefined4*>(&DAT_008cacc8))) {
                        operator_delete__(puVar9);
                    }
                    iVar6 = iVar6 + -1;
                    *puVar13 = static_cast<undefined4>(
                        reinterpret_cast<std::uintptr_t>(DAT_008cacd0));
                } while (iVar6 != 0);
            }
            operator_delete__(reinterpret_cast<void*>(
                static_cast<std::uintptr_t>(iVar2) - 4));
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4b0df0
// ---------------------------------------------------------------------------
// 0x4b0df0 — observed shape
// receiver: ESI (container), EDI (index); out slot is the stack parameter.
void FUN_004b0df0(undefined1** out_string, void* self_esi, uint index_edi)
{
    char          cVar1;
    std::int32_t* unaff_ESI = reinterpret_cast<std::int32_t*>(self_esi);

    if (index_edi < *reinterpret_cast<uint*>(reinterpret_cast<char*>(unaff_ESI) + 8)) {
        *out_string = reinterpret_cast<undefined1*>(DAT_008cacd0);
        if (index_edi < *reinterpret_cast<uint*>(reinterpret_cast<char*>(unaff_ESI) + 0xc)) {
            cVar1 = FUN_004b0f10();
            *out_string = reinterpret_cast<undefined1*>(DAT_008cacd0);
            if (cVar1 == '\0') {
                cVar1 = FUN_004b0f10();
                if (cVar1 != '\0') {
                    *reinterpret_cast<std::int32_t*>(
                        reinterpret_cast<char*>(unaff_ESI) + 0x10) =
                        *reinterpret_cast<std::int32_t*>(
                            reinterpret_cast<char*>(unaff_ESI) + 0x10) -
                        1;
                }
            } else {
                cVar1 = FUN_004b0fa0();
                if (cVar1 != '\0') {
                    *reinterpret_cast<std::int32_t*>(
                        reinterpret_cast<char*>(unaff_ESI) + 0x10) =
                        *reinterpret_cast<std::int32_t*>(
                            reinterpret_cast<char*>(unaff_ESI) + 0x10) +
                        1;
                    FUN_00412ec0();
                    return;
                }
            }
        } else {
            *reinterpret_cast<uint*>(reinterpret_cast<char*>(unaff_ESI) + 0xc) =
                index_edi + 1;
            cVar1 = FUN_004b0f10();
            if (cVar1 != '\0') {
                *reinterpret_cast<std::int32_t*>(
                    reinterpret_cast<char*>(unaff_ESI) + 0x10) =
                    *reinterpret_cast<std::int32_t*>(
                        reinterpret_cast<char*>(unaff_ESI) + 0x10) +
                    1;
                FUN_00412ec0();
                return;
            }
        }
        FUN_00412ec0();
    }
    return;
}
