// Sid Meier's Pirates! (2004) — PE32 i386
// Source-reconstruction batch mass_0031.
//
// Every definition below is a candidate translation of the Ghidra 12.2
// pseudocode listed under analysis/pseudocode/functions/ for the matching
// address. Register receivers (ECX/EDX/ESI/EDI/EBX/EAX) are lifted to explicit
// parameters. Where a call target is entered with its receiver already loaded
// in ECX and the listing therefore shows no argument, the reconstructed call
// passes the surrounding construction target explicitly.
//
// Layout notes for the two large state objects are taken verbatim from the
// listings: self+0x4c48.. is the per-layer texture array, self+0x3424.. the
// layer parameters, self+0x3224/0x3024 the walk/blocked bitmaps,
// self+0x343c.. the per-layer grid extent, self+0xc89/0xd12/0xc09 the grid
// scratch bitmaps.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals observed in the supplied corpus listings.
// ---------------------------------------------------------------------------
extern "C" int sprintf(char* buffer, const char* format, ...);

extern void  operator_delete(void* ptr);
extern void  operator_delete__(void* ptr);

extern void* FUN_00533c78(int size);
extern void* thunk_FUN_00533c78(uint32_t size);
extern int   FUN_00533db0(int kind);
extern int   FUN_005426d0(void* self);
extern void* FUN_005428c0(void* self);
extern void* FUN_005446d0(void* self);
extern void  FUN_00540c50(void* self);
extern void  FUN_00540460(const char* name);
extern void  FUN_00541650(int value);
extern void  FUN_005017e0(void* object);
extern void  FUN_0050bf50(int value);
extern void  FUN_00533d10(int a, int b);
extern void  FUN_00534130(void);
extern void  FUN_00534350(void);
extern void  FUN_005606f0(int a, void* out);
extern void  FUN_005f0ddc(int value);
extern long double FUN_004e7510(float x, float y, int mode);
extern void* FUN_004a9020(uint32_t param);
extern void  FUN_00488a80(uint32_t id, uint32_t a, uint32_t b, uint32_t c,
                          uint32_t d, uint32_t e, uint32_t f, uint32_t g,
                          uint32_t h, uint32_t i, uint32_t j);
extern void  FUN_004888e0(uint32_t id, uint32_t a, uint32_t b, uint32_t c);
extern void  FUN_00488840(const char* message, int code);
extern void  FUN_004985e0(void);
extern void  FUN_004a14b0(void);
extern void* FUN_00500850(const char* name);

// Definitions later in the file that are referenced before their bodies.
void FUN_004aa560(uint16_t param_1, uint16_t param_2, void** param_3, void** param_4,
                  uint32_t* self, uint32_t layer);
void FUN_004aa7b0(uint16_t param_1, uint32_t param_2, float** param_3,
                  uint32_t* self, uint32_t layer);
void FUN_004aac50(uint32_t* self, uint32_t** param_1);
void FUN_004aacc0(uint32_t* self, uint32_t param_1);
void FUN_004aad20(uint32_t* self, uint32_t value);
void FUN_004aad70(uint32_t* self, uint32_t* param_1);

// Globals are addressed directly; DAT_ names are the addresses the listing uses.
extern uint8_t  DAT_008c718c;
extern uint8_t  DAT_008c7191;
extern uint8_t  DAT_008e8eff;
extern uint32_t DAT_008ecd78;
extern uint32_t DAT_007275a0[];
extern uint32_t DAT_0072cd78;
extern uint32_t DAT_008ca984;
extern uint8_t  DAT_00871978[];
extern uint32_t DAT_008e9ffc;
extern uint32_t DAT_00717780;
extern uint32_t DAT_00717784;
extern uint32_t DAT_00717788;
extern uint32_t DAT_0071779c;
extern uint32_t DAT_007177a0;
extern uint32_t DAT_007177a4;
extern uint32_t DAT_007177a8;
extern uint32_t DAT_00727424;
extern uint32_t DAT_00727428;
extern uint32_t DAT_0072742c;
extern uint8_t  PTR_FUN_0070bed4;
extern uint8_t  PTR_FUN_0070bf10;
extern uint8_t  PTR_FUN_0070bf4c;
extern uint8_t  PTR_FUN_0071169c;

// ---------------------------------------------------------------------------
// Small idioms the listings repeat inline.
// ---------------------------------------------------------------------------
static uint32_t fbits(float value)
{
    uint32_t bits;
    __builtin_memcpy(&bits, &value, sizeof(bits));
    return bits;
}

static float ffrom(uint32_t bits)
{
    float value;
    __builtin_memcpy(&value, &bits, sizeof(value));
    return value;
}

// Reference count lives in the second dword of every reference-counted object;
// slot zero is the vtable and slot zero of the vtable releases the object.
static void addref_obj(uint32_t* obj)
{
    if (obj != nullptr) {
        obj[1] = obj[1] + 1;
    }
}

static void release_obj(uint32_t* obj)
{
    if (obj == nullptr) {
        return;
    }
    int* refs = reinterpret_cast<int*>(obj + 1);
    *refs = *refs - 1;
    if (*refs == 0) {
        auto destroy = *reinterpret_cast<void (**)(int)>(obj);
        destroy(1);
    }
}

// (**(code **)(parent[0x28] + 4))() — allocate the next child-list node.
static uint32_t* list_node(uint32_t* parent)
{
    auto allocate = *reinterpret_cast<uint32_t* (*)(void)>(parent[0x28] + 4);
    return reinterpret_cast<uint32_t*>(allocate());
}

// The child-list append sequence the listing repeats for every child object.
static void link_child(uint32_t* parent, uint32_t* obj)
{
    uint32_t* node = list_node(parent);
    uint32_t* current = reinterpret_cast<uint32_t*>(node[2]);
    if (current != obj) {
        if (current != nullptr) {
            release_obj(current);
        }
        node[2] = reinterpret_cast<uint32_t>(obj);
        addref_obj(obj);
    }
    node[1] = 0;
    node[0] = parent[0x29];
    if (parent[0x29] == 0) {
        parent[0x2a] = reinterpret_cast<uint32_t>(node);
    }
    else {
        *reinterpret_cast<uint32_t**>(parent[0x29] + 4) = node;
    }
    parent[0x29] = reinterpret_cast<uint32_t>(node);
    parent[0x2b] = parent[0x2b] + 1;
}

// The lazy field initialiser the listing inlines three times in FUN_004a97f0:
// obj[0xb] holds a pointer to the slot; create it through 0x1c/0x426d0 and
// keep obj[0xe] as a refcount-style adjustment counter.
static void* lazy_slot(uint32_t* obj)
{
    int slot = *reinterpret_cast<int*>(obj[0xb]);
    if (slot != 0) {
        return reinterpret_cast<void*>(slot);
    }
    int created = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
    if (created == 0) {
        created = 0;
    }
    else {
        created = FUN_005426d0(reinterpret_cast<void*>(created));
    }
    if (obj[0xc] != 0) {
        if (obj[0xd] == 0) {
            obj[0xd] = 1;
            if (created != 0) {
                obj[0xe] = obj[0xe] + 1;
            }
        }
        else if (created == 0) {
            if (*reinterpret_cast<int*>(obj[0xb]) != 0) {
                obj[0xe] = obj[0xe] - 1;
            }
        }
        else if (*reinterpret_cast<int*>(obj[0xb]) == 0) {
            obj[0xe] = obj[0xe] + 1;
        }
        *reinterpret_cast<int*>(obj[0xb]) = created;
    }
    return reinterpret_cast<void*>(created);
}

// ---------------------------------------------------------------------------
// 0x4a91e0 — observed shape
// Picks the artwork id for the current map cell kind and submits it to the
// sprite drawer with the cell's stored position.
// ---------------------------------------------------------------------------
void FUN_004a91e0(uint32_t param_1, uint16_t* self)
{
    if (self == nullptr) {
        return;
    }
    uint32_t art_id;
    switch (*self) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        art_id = 0xd7;
        break;
    case 3:
        art_id = 0xd8;
        break;
    default:
        art_id = 0xffffffff;
        break;
    }
    uint32_t* position = reinterpret_cast<uint32_t*>(FUN_004a9020(param_1));
    FUN_00488a80(art_id, position[0], position[1], position[2], 0xffffffff,
                 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
}

// ---------------------------------------------------------------------------
// 0x4a9270 — observed shape
// Same submission path, with the art id selected by a boolean.
// ---------------------------------------------------------------------------
void FUN_004a9270(char param_1, void* self)
{
    if (self == nullptr) {
        return;
    }
    uint32_t* position = reinterpret_cast<uint32_t*>(FUN_004a9020(0));
    FUN_00488a80(0xda - (uint32_t)(param_1 != '\0'), position[0], position[1],
                 position[2], 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0,
                 0xbf800000, 0xffffffff);
}

// ---------------------------------------------------------------------------
// 0x4a92d0 — observed shape
// Brings the terrain renderer up once the audio manager reports ready.
// ---------------------------------------------------------------------------
void FUN_004a92d0(void)
{
    if (DAT_008c718c != 0) {
        DAT_008c7191 = 0;
        return;
    }
    if (DAT_008c7191 != '\0') {
        auto is_ready = *reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18);
        char ready = is_ready();
        if (ready == '\0') {
            FUN_00488840("The audio manager has not been properly initialized yet", 0);
            return;
        }
        if (DAT_008e8eff == '\0') {
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
}

// ---------------------------------------------------------------------------
// 0x4a93b0 — observed shape
// Submits the full terrain sprite set in one go.
// ---------------------------------------------------------------------------
void FUN_004a93b0(void)
{
    FUN_004888e0(0xac, 0xffffffff, 0xffffffff, 0xbf800000);
    FUN_004985e0();
    FUN_004a14b0();
    FUN_00488a80(0xe0, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff,
                 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
    FUN_00488a80(0xdc, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff,
                 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
    FUN_00488a80(0xdd, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff,
                 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
    FUN_00488a80(0xde, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff,
                 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
    FUN_00488a80(0xdf, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff,
                 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
}

// ---------------------------------------------------------------------------
// 0x4a95b0 — observed shape
// Advances the MSVC LCG state and forwards the new value.
// ---------------------------------------------------------------------------
void FUN_004a95b0(int* self)
{
    int value = *self * 0x343fd + 0x269ec3;
    *self = value;
    FUN_005f0ddc(value);
}

// ---------------------------------------------------------------------------
// 0x4a9600 — observed shape
// MSVC LCG advanced on the same state, returned as a unit float.
// ---------------------------------------------------------------------------
long double FUN_004a9600(int* self)
{
    int value = *self * 0x343fd + 0x269ec3;
    *self = value;
    long double scaled = static_cast<long double>(value);
    if (value < 0) {
        scaled = scaled + static_cast<long double>(4294967296.0);
    }
    return scaled * static_cast<long double>(2.3283064365386963e-10);
}

// ---------------------------------------------------------------------------
// 0x4a9630 — observed shape
// Squared length of a 3-vector with the fast reciprocal-square-root style
// mantissa table lookup at DAT_007275a0 preserved bit for bit.
// ---------------------------------------------------------------------------
long double FUN_004a9630(const float* self)
{
    float squared = self[2] * self[2] + self[1] * self[1] + self[0] * self[0];
    if (squared == 0.0f) {
        return static_cast<long double>(0.0);
    }
    uint32_t bits = fbits(squared);
    uint32_t exponent = (bits >> 0x17) - 0x7f;
    uint32_t mantissa = bits & 0x7fffff;
    if ((exponent & 1) != 0) {
        mantissa = mantissa | 0x800000;
    }
    uint32_t table = DAT_007275a0[mantissa >> 0x10];
    uint32_t biased =
        static_cast<uint32_t>((static_cast<int16_t>(static_cast<int16_t>(exponent) >> 1)
                               + 0x7f) * 0x800000);
    return static_cast<long double>(ffrom(biased | table));
}

// ---------------------------------------------------------------------------
// 0x4a96a0 — observed shape
// Clears the terrain state: per-layer handles, the 0x80/0x600 entry scratch
// bitmaps, and the six layer descriptors.
// ---------------------------------------------------------------------------
void FUN_004a96a0(uint32_t* self)
{
    self[0x131a] = 0;
    self[0x131b] = 0;
    self[0x131c] = 0;
    self[0x131d] = 0;
    self[0x131e] = 0;
    self[0x131f] = 0;
    *reinterpret_cast<uint8_t*>(self + 1) = 0;
    self[0] = 0;

    uint32_t* cursor = self + 0xc89;
    for (int remaining = 0x80; remaining != 0; remaining = remaining - 1) {
        *cursor = 0;
        cursor = cursor + 1;
    }

    cursor = self + 0xd12;
    for (int remaining = 0x600; remaining != 0; remaining = remaining - 1) {
        *cursor = 0;
        cursor = cursor + 1;
    }

    cursor = self + 0xc09;
    for (int remaining = 0x80; remaining != 0; remaining = remaining - 1) {
        *cursor = 0;
        cursor = cursor + 1;
    }

    int layer = 0;
    uint32_t* cell = self + 0x609;
    uint32_t* extent = self + 0x603;
    uint32_t* parameters = self + 0xd0c;
    do {
        extent[0xd0f] = 0;
        *reinterpret_cast<uint16_t*>(parameters - 3) = 100;
        *reinterpret_cast<uint16_t*>(parameters) = 100;
        *reinterpret_cast<uint16_t*>(parameters + 3) = 5;
        *reinterpret_cast<uint16_t*>(extent) = 1;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(extent) + 2) = 1;
        *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(self) + layer + 5) = 0;
        int rows = 0x10;
        do {
            int columns = 0x10;
            do {
                *reinterpret_cast<uint16_t*>(cell) = 0;
                *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(cell) + 2) = 0;
                cell = cell + 1;
                columns = columns - 1;
            } while (columns != 0);
            rows = rows - 1;
        } while (rows != 0);
        layer = layer + 1;
        parameters = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(parameters) + 2);
        extent = extent + 1;
    } while (layer < 6);
}

// ---------------------------------------------------------------------------
// 0x4a9770 — observed shape
// Drops the six layer texture objects and then the six cached buffers.
// ---------------------------------------------------------------------------
void FUN_004a9770(void* self, uintptr_t owner)
{
    int* slot = reinterpret_cast<int*>(owner + 0x4c48);
    int remaining = 6;
    uint32_t* temporary = reinterpret_cast<uint32_t*>(self);
    do {
        int object = *slot;
        if ((object != 0) && (*reinterpret_cast<int**>(object + 0x24) != nullptr)) {
            auto detach = *reinterpret_cast<void (**)(uint32_t**, int)>(
                *reinterpret_cast<int*>(object + 0x24) + 0x74);
            detach(&temporary, object);
            if (temporary != nullptr) {
                int refs = static_cast<int>(temporary[1]);
                temporary[1] = static_cast<uint32_t>(refs - 1);
                if (refs - 1 == 0) {
                    auto destroy = *reinterpret_cast<void (**)(int)>(temporary);
                    destroy(1);
                }
            }
        }
        *slot = 0;
        slot = slot + 1;
        remaining = remaining - 1;
    } while (remaining != 0);

    int cursor = static_cast<int>(owner + 0x4c80);
    int count = 6;
    do {
        uint32_t* object = *reinterpret_cast<uint32_t**>(cursor - 4);
        cursor = cursor - 4;
        if (object != nullptr) {
            int* refs = reinterpret_cast<int*>(object + 1);
            *refs = *refs - 1;
            if (*refs == 0) {
                auto destroy = *reinterpret_cast<void (**)(int)>(object);
                destroy(1);
            }
        }
        count = count - 1;
    } while (count != 0);
}

// ---------------------------------------------------------------------------
// 0x4a97f0 — observed shape
// Builds the six level-of-detail terrain meshes: for every layer it allocates
// the mesh, tessellates the cells that are not blocked, uploads the vertex
// streams, and hangs the resulting render objects off the layer node.
// ---------------------------------------------------------------------------
void FUN_004a97f0(uint32_t* self)
{
    int iVar2;
    void* pvVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    int iVar6;
    uint32_t uVar7;
    uint32_t* puVar8;
    int iVar9;
    uint32_t uVar11;
    uint32_t* local_4b0;
    int local_4ac;
    int* local_4a8;
    int local_4a4;
    uint16_t* local_4a0;
    uint16_t* local_498;
    void* local_494;
    int local_490;
    intptr_t local_48c;
    uint32_t* local_488;
    uint32_t* local_484;
    uint32_t* local_480;
    float* local_47c;
    uint32_t* local_478;
    int16_t local_474;
    int16_t local_472;
    int16_t local_470;
    int16_t local_46e;
    uint32_t local_46c;
    float local_468;
    float local_464;
    uint32_t local_460;
    uint32_t local_45c;
    uint32_t uStack_458;
    uint32_t uStack_454;
    uint32_t uStack_450;
    uint32_t local_44c;
    uint32_t local_448;
    char acStack_444[64];
    int local_404[257];

    *reinterpret_cast<uint8_t*>(self + 1) = 1;

    puVar4 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x24));
    if (puVar4 == nullptr) {
        puVar4 = nullptr;
    }
    else {
        FUN_00540c50(puVar4);
        *puVar4 = reinterpret_cast<uint32_t>(&PTR_FUN_0070bf4c);
        *reinterpret_cast<uint16_t*>(puVar4 + 8) = 0xec;
        *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(puVar4) + 0x22) = 0;
    }
    local_478 = puVar4;

    puVar5 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x28));
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    }
    else {
        FUN_00540c50(puVar5);
        *reinterpret_cast<uint16_t*>(puVar5 + 8) = 3;
        puVar5[9] = 3;
        *puVar5 = reinterpret_cast<uint32_t>(&PTR_FUN_0070bed4);
    }
    local_480 = puVar5;

    local_484 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x2c));
    if (local_484 == nullptr) {
        local_484 = nullptr;
    }
    else {
        FUN_00540c50(local_484);
        *local_484 = reinterpret_cast<uint32_t>(&PTR_FUN_0070bf10);
        *reinterpret_cast<uint16_t*>(local_484 + 8) = 0;
        local_484[9] = 0;
        local_484[10] = 1;
    }

    *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(puVar4) + 0x22) = 0;
    *reinterpret_cast<uint16_t*>(puVar4 + 8) =
        static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(puVar4 + 8) & 0xf2ed) | 0x32ed);
    *reinterpret_cast<uint8_t*>(puVar5 + 8) =
        static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(puVar5 + 8) & 0xfc);
    local_484[10] = 1;
    local_484[9] = 2;

    local_4ac = 0;
    do {
        uVar11 = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + local_4ac * 2 + 0x343c);
        uVar11 = uVar11 * uVar11;
        local_448 = uVar11;

        puVar4 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x34));
        if (puVar4 == nullptr) {
            puVar4 = nullptr;
        }
        else {
            iVar6 = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + local_4ac * 2 + 0x343c) - 1;
            puVar4[2] = static_cast<uint32_t>(iVar6 * iVar6 * 2);
            *puVar4 = reinterpret_cast<uint32_t>(&PTR_FUN_0071169c);
            puVar4[0xb] = 1;
            *reinterpret_cast<int16_t*>(puVar4 + 1) = static_cast<int16_t>(uVar11);
            *reinterpret_cast<uint16_t*>(puVar4 + 6) = 0;
            *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(puVar4) + 0x1a) = 0;
            *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(puVar4) + 0x1e) = 0;
            *reinterpret_cast<uint16_t*>(puVar4 + 7) = 0;
            puVar4[0xc] = 0;

            puVar5 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78((uVar11 & 0xffff) << 2));
            puVar4[3] = reinterpret_cast<uint32_t>(puVar5);
            for (uVar11 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(puVar4 + 1));
                 uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar5 = 0xffffffff;
                puVar5 = puVar5 + 1;
            }
            // Zero-trip copy loop as recovered by the decompiler.
            for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 - 1) {
                *reinterpret_cast<uint8_t*>(puVar5) = 0xff;
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(puVar5) + 1);
            }
            uVar7 = reinterpret_cast<uint32_t>(
                thunk_FUN_00533c78(static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(puVar4 + 1)) << 1));
            puVar4[4] = uVar7;
            uVar7 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(puVar4[2] << 2));
            puVar4[5] = uVar7;
            uVar7 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(puVar4[2] & 0xfffffffe));
            puVar4[8] = uVar7;
        }
        *self = reinterpret_cast<uint32_t>(puVar4);

        iVar6 = 0;
        if (0 < static_cast<int>(
                     *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + local_4ac * 2 + 0x343c) - 1)) {
            do {
                iVar9 = 0;
                if (0 < static_cast<int>(
                             *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + local_4ac * 2 + 0x343c) - 1)) {
                    do {
                        local_470 = *reinterpret_cast<int16_t*>(
                            reinterpret_cast<uintptr_t>(self) + local_4ac * 2 + 0x343c);
                        local_474 = static_cast<int16_t>(local_470 * static_cast<int16_t>(iVar6)
                                                         + static_cast<int16_t>(iVar9));
                        local_472 = static_cast<int16_t>(local_474 + 1);
                        local_470 = static_cast<int16_t>(local_474 + local_470);
                        local_46e = static_cast<int16_t>(local_470 + 1);
                        FUN_0050bf50(0);
                        iVar9 = iVar9 + 1;
                    } while (iVar9 < static_cast<int>(
                                        *reinterpret_cast<uint16_t*>(
                                            reinterpret_cast<uintptr_t>(self) + local_4ac * 2 + 0x343c) - 1));
                }
                iVar6 = iVar6 + 1;
            } while (iVar6 < static_cast<int>(
                                *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + local_4ac * 2 + 0x343c) - 1));
        }

        local_46c = 1u << (local_4ac & 0x1f);
        local_4b0 = nullptr;
        local_4a4 = 0;
        local_45c = ~local_46c;
        local_44c = 1u << (local_4ac & 0x1f);
        local_4a0 = reinterpret_cast<uint16_t*>(self + 0xc89);
        local_490 = 0;
        local_4a8 = local_404;
        local_498 = local_4a0;
        do {
            iVar6 = 0;
            local_48c = 0;
            do {
                *local_498 = static_cast<uint16_t>(*local_498 & static_cast<uint16_t>(local_45c));
                *local_4a8 = 0;
                if ((local_44c & local_4a0[-0x100]) == 0) {
                    *local_4a0 = static_cast<uint16_t>(*local_4a0 | static_cast<uint16_t>(local_46c));
                    FUN_004aa560(static_cast<uint16_t>(local_4a4), static_cast<uint16_t>(iVar6),
                                 reinterpret_cast<void**>(&local_47c),
                                 reinterpret_cast<void**>(&local_488), self,
                                 static_cast<uint32_t>(local_4ac));
                    FUN_004aa7b0(static_cast<uint16_t>(local_4a4), static_cast<uint32_t>(iVar6),
                                 reinterpret_cast<float**>(&local_494), self,
                                 static_cast<uint32_t>(local_4ac));
                    pvVar3 = local_47c;
                    auto build = *reinterpret_cast<void* (*)(uint32_t, float*, uint32_t*, void*,
                                                             int, int)>(*self);
                    puVar4 = reinterpret_cast<uint32_t*>(
                        build(local_448 & 0xffff, local_47c, local_488, local_494, 1, 0));
                    *local_4a8 = static_cast<int>(reinterpret_cast<intptr_t>(puVar4));
                    if (pvVar3 != nullptr) {
                        operator_delete(pvVar3);
                        local_47c = nullptr;
                    }
                    if (local_488 != nullptr) {
                        operator_delete(local_488);
                        local_488 = nullptr;
                    }
                    if (local_494 != nullptr) {
                        operator_delete(local_494);
                        local_494 = nullptr;
                    }
                    FUN_00541650(0);

                    puVar5 = *reinterpret_cast<uint32_t**>(puVar4[0x2f] + 0x28);
                    iVar9 = 0;
                    if (*reinterpret_cast<int16_t*>(puVar4[0x2f] + 0xc) != 0) {
                        iVar2 = *local_4a8;
                        do {
                            puVar5[0] = DAT_0071779c;
                            puVar5[1] = DAT_007177a0;
                            puVar5[2] = DAT_007177a4;
                            puVar5[3] = DAT_007177a8;
                            iVar9 = iVar9 + 1;
                            puVar5 = puVar5 + 4;
                        } while (iVar9 < static_cast<int>(
                                            static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(
                                                *reinterpret_cast<int*>(iVar2 + 0xbc) + 0xc))));
                    }

                    local_468 = static_cast<float>(local_490);
                    local_460 = 0;
                    local_464 = static_cast<float>(local_48c);
                    puVar4[0x17] = fbits(local_468);
                    puVar4[0x18] = fbits(local_464);
                    puVar4[0x19] = 0;

                    if (local_4b0 == nullptr) {
                        iVar9 = (local_4ac * 0x10 + local_4a4) * 0x10 + iVar6;
                        *reinterpret_cast<uint16_t*>(self + iVar9 + 3) = 0;
                        *reinterpret_cast<int16_t*>(reinterpret_cast<uintptr_t>(self) + iVar9 * 4 + 0xe) =
                            static_cast<int16_t>(*reinterpret_cast<int16_t*>(puVar4[0x2f] + 0x40) * 2
                                                 + *reinterpret_cast<int16_t*>(puVar4[0x2f] + 0x3c));
                        local_4b0 = puVar4;
                    }
                    else {
                        FUN_00533d10(0, 1);
                        FUN_00533d10(0, 1);
                        iVar9 = (local_4ac * 0x10 + local_4a4) * 0x10 + iVar6;
                        *reinterpret_cast<int16_t*>(self + iVar9 + 3) =
                            static_cast<int16_t>((*reinterpret_cast<int16_t*>(local_4b0[0x2f] + 0x40) + 1) * 2
                                                 + *reinterpret_cast<int16_t*>(local_4b0[0x2f] + 0x3c));
                        puVar5 = reinterpret_cast<uint32_t*>(FUN_005017e0(puVar4));
                        *reinterpret_cast<int16_t*>(reinterpret_cast<uintptr_t>(self) + iVar9 * 4 + 0xe) =
                            static_cast<int16_t>(*reinterpret_cast<int16_t*>(puVar4[0x2f] + 0x40) * 2
                                                 + *reinterpret_cast<int16_t*>(puVar4[0x2f] + 0x3c)
                                                 + *reinterpret_cast<int16_t*>(self + iVar9 + 3));
                        if (local_4b0 != nullptr) {
                            auto destroy = *reinterpret_cast<void (**)(int)>(local_4b0);
                            destroy(1);
                        }
                        local_4b0 = puVar5;
                        if (puVar4 != nullptr) {
                            auto destroy = *reinterpret_cast<void (**)(int)>(puVar4);
                            destroy(1);
                            *local_4a8 = 0;
                        }
                    }
                }
                local_48c = local_48c + 0x3e8;  // listing: 0xfa undefined4 steps
                local_4a0 = local_4a0 + 1;
                local_4a8 = local_4a8 + 1;
                iVar6 = iVar6 + 1;
            } while (local_48c < 16000);
            local_4a4 = local_4a4 + 1;
            local_490 = local_490 + 1000;
            local_498 = local_498 + 0x11;
        } while (local_490 < 16000);

        puVar4 = reinterpret_cast<uint32_t*>(*self);
        if (puVar4 != nullptr) {
            *puVar4 = reinterpret_cast<uint32_t>(&PTR_FUN_0071169c);
            if (reinterpret_cast<void*>(puVar4[4]) != nullptr) {
                operator_delete__(reinterpret_cast<void*>(puVar4[4]));
                puVar4[4] = 0;
            }
            if (reinterpret_cast<void*>(puVar4[3]) != nullptr) {
                operator_delete__(reinterpret_cast<void*>(puVar4[3]));
                puVar4[3] = 0;
            }
            if (reinterpret_cast<void*>(puVar4[5]) != nullptr) {
                operator_delete__(reinterpret_cast<void*>(puVar4[5]));
                puVar4[5] = 0;
            }
            if (reinterpret_cast<void*>(puVar4[8]) != nullptr) {
                operator_delete__(reinterpret_cast<void*>(puVar4[8]));
                puVar4[8] = 0;
            }
            operator_delete(puVar4);
            *self = 0;
        }

        self[local_4ac + 0x1312] = reinterpret_cast<uint32_t>(local_4b0);
        if (local_4b0 != nullptr) {
            if (self[local_4ac + 0x131a] != 0) {
                iVar6 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x48)));
                if (iVar6 == 0) {
                    puVar4 = nullptr;
                }
                else {
                    puVar4 = reinterpret_cast<uint32_t*>(FUN_005428c0(reinterpret_cast<void*>(iVar6)));
                }
                puVar5 = reinterpret_cast<uint32_t*>(self[local_4ac + 0x131a]);

                iVar6 = static_cast<int>(reinterpret_cast<intptr_t>(lazy_slot(puVar4)));
                puVar8 = *reinterpret_cast<uint32_t**>(iVar6 + 4);
                if (puVar8 != puVar5) {
                    if (puVar8 != nullptr) {
                        release_obj(puVar8);
                    }
                    *reinterpret_cast<uint32_t**>(iVar6 + 4) = puVar5;
                    addref_obj(puVar5);
                }

                iVar6 = static_cast<int>(reinterpret_cast<intptr_t>(lazy_slot(puVar4)));
                *reinterpret_cast<uint32_t*>(iVar6 + 0xc) = 2;

                iVar6 = static_cast<int>(reinterpret_cast<intptr_t>(lazy_slot(puVar4)));
                *reinterpret_cast<uint32_t*>(iVar6 + 8) = 0;

                puVar4[1] = puVar4[1] + 1;
                link_child(local_4b0, puVar4);
                release_obj(puVar4);
            }

            iVar6 = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(100)));
            if (iVar6 == 0) {
                puVar4 = nullptr;
            }
            else {
                puVar4 = reinterpret_cast<uint32_t*>(FUN_005446d0(reinterpret_cast<void*>(iVar6)));
            }
            iVar6 = static_cast<int>(puVar4[0x17]);
            puVar4[0x17] = static_cast<uint32_t>(iVar6 + 1);
            puVar4[0x16] = 0x3f800000;
            puVar4[9] = DAT_00717780;
            puVar4[10] = DAT_00717784;
            puVar4[0xb] = DAT_00717788;
            puVar4[0x17] = static_cast<uint32_t>(iVar6 + 2);
            puVar4[0xc] = DAT_00717780;
            puVar4[0xd] = DAT_00717784;
            puVar4[0xe] = DAT_00717788;
            puVar4[0x17] = static_cast<uint32_t>(iVar6 + 3);
            puVar4[0x12] = DAT_00727424;
            puVar4[0x13] = DAT_00727428;
            puVar4[0x14] = DAT_0072742c;
            puVar4[0x17] = static_cast<uint32_t>(iVar6 + 4);
            puVar4[1] = puVar4[1] + 1;
            link_child(local_4b0, puVar4);
            release_obj(puVar4);

            sprintf(acStack_444, "LBGridL%d", local_4ac);
            (*reinterpret_cast<void (**)(uint32_t*, int)>(
                *reinterpret_cast<uint32_t*>(DAT_008e9ffc) + 0x70))(local_4b0, 1);

            // Re-link the three per-layer resource objects (each AddRef'd first).
            local_480[1] = local_480[1] + 1;
            puVar5 = local_480;
            link_child(local_4b0, puVar5);
            release_obj(puVar5);

            local_488[1] = local_488[1] + 1;
            puVar5 = local_488;
            link_child(local_4b0, puVar5);
            release_obj(puVar5);

            puVar5 = reinterpret_cast<uint32_t*>(local_48c);
            puVar5[1] = puVar5[1] + 1;
            link_child(local_4b0, puVar5);
            release_obj(puVar5);

            uStack_458 = self[0x1318];
            uStack_454 = self[0x1319];
            local_4b0[0x17] = uStack_458;
            local_4b0[0x18] = uStack_454;
            uStack_450 = 0;
            local_4b0[0x19] = 0;
            FUN_00540460(acStack_444);
            FUN_00533d10(0, 1);
            FUN_00534130();
            FUN_00534350();
        }
        local_4ac = local_4ac + 1;
        if (5 < local_4ac) {
            return;
        }
    } while (true);
}

// ---------------------------------------------------------------------------
// 0x4aa230 — observed shape
// Mirrors the six "layer enabled" flags onto the low bit of each layer
// texture's flags word.
// ---------------------------------------------------------------------------
static void set_layer_enabled(uint32_t* self, uint32_t slot, uintptr_t flagOffset, char enabled)
{
    int object = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(self) + slot);
    if (object == 0) {
        return;
    }
    bool on = (enabled == '\0') || (*reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(self) + flagOffset) != '\0');
    uint16_t* flags = reinterpret_cast<uint16_t*>(object + 0x20);
    if (on) {
        *flags = static_cast<uint16_t>(*flags | 1);
    }
    else {
        *flags = static_cast<uint16_t>(*flags & 0xfffe);
    }
}

void FUN_004aa230(uint32_t* self, char flag)
{
    set_layer_enabled(self, 0x4c48, 5, flag);
    set_layer_enabled(self, 0x4c4c, 6, flag);
    set_layer_enabled(self, 0x4c50, 7, flag);
    set_layer_enabled(self, 0x4c54, 8, flag);
    set_layer_enabled(self, 0x4c58, 9, flag);
    set_layer_enabled(self, 0x4c5c, 10, flag);
}

// ---------------------------------------------------------------------------
// 0x4aa340 — observed shape
// Sets or clears one cell's bit in a layer's walk bitmap, then rewrites the
// cell's walk-cost entries in the layer's index buffer.
// ---------------------------------------------------------------------------
void FUN_004aa340(uint16_t param_1, uint16_t param_2, char param_3, uint32_t param_4,
                  uint32_t* self, uint32_t layer)
{
    uint32_t layerIndex = layer & 0xffff;
    int cell = static_cast<uint32_t>(param_1) * 0x10 + static_cast<uint32_t>(param_2);
    uint16_t bits = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x3224 + cell * 2);
    uint8_t bitIndex = static_cast<uint8_t>(layerIndex);
    uint32_t mask = 1u << (bitIndex & 0x1f);
    if ((((mask & bits) != 0) != (param_3 != '\0')) &&
        ((mask & *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x3024 + cell * 2)) == 0)) {
        if (param_3 == '\0') {
            bits = static_cast<uint16_t>(~(1u << (bitIndex & 0x1f)) & bits);
        }
        else {
            bits = static_cast<uint16_t>((1u << (bitIndex & 0x1f)) | bits);
        }
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x3224 + cell * 2) = bits;

        int layerObject = *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(self) + 0x4c48 + layerIndex * 4) + 0xbc);
        int vertices = *reinterpret_cast<int*>(layerObject + 0x28);
        int indices = *reinterpret_cast<int*>(layerObject + 0x48);
        uint32_t value = 0x3f800000;
        if (param_3 == '\0') {
            value = 0;
        }
        int handle = FUN_00533db0(3);
        *reinterpret_cast<int*>(handle + 0x5c) = *reinterpret_cast<int*>(handle + 0x5c) + 1;
        *reinterpret_cast<uint32_t*>(handle + 0x58) = value;

        int cellIndex = (layerIndex * 0x10 + static_cast<uint32_t>(param_1)) * 0x10
                        + static_cast<uint32_t>(param_2);
        uint32_t first = static_cast<uint32_t>(
            *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0xc + cellIndex * 4));
        if (first < *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0xe + cellIndex * 4)) {
            do {
                uint32_t cost;
                if (param_3 == '\0') {
                    cost = 0;
                }
                else {
                    cost = param_4;
                }
                int offset = static_cast<int>(first * 2);
                first = first + 1;
                *reinterpret_cast<uint32_t*>(
                    static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(indices + offset)) * 0x10
                    + 0xc + vertices) = cost;
            } while (static_cast<int>(first)
                     < static_cast<int>(static_cast<uint32_t>(
                         *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0xe + cellIndex * 4))));
        }

        uint8_t* flags = reinterpret_cast<uint8_t*>(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(self) + 0x4c48 + layerIndex * 4) + 0xbc)
            + 0x32);
        *flags = static_cast<uint8_t>(*flags | 4);
    }
}

// ---------------------------------------------------------------------------
// 0x4aa460 — observed shape
// Reloads one named layer texture and, when the layer object exists, builds
// and installs a fresh render object for it.
// ---------------------------------------------------------------------------
void FUN_004aa460(uint32_t* self, uint32_t slot, const char* name)
{
    uint32_t index = slot & 0xffff;
    uint32_t* object = *reinterpret_cast<uint32_t**>(reinterpret_cast<uintptr_t>(self) + 0x4c68 + index * 4);
    if (object != nullptr) {
        release_obj(object);
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(self) + 0x4c68 + index * 4) = 0;
    }

    // The listing loses the loader's name argument; every caller in the corpus
    // passes the resource name in the same position.
    uint32_t* loaded = reinterpret_cast<uint32_t*>(FUN_00500850(name));
    object = *reinterpret_cast<uint32_t**>(reinterpret_cast<uintptr_t>(self) + 0x4c68 + index * 4);
    if (object != loaded) {
        if (object != nullptr) {
            release_obj(object);
        }
        *reinterpret_cast<uint32_t**>(reinterpret_cast<uintptr_t>(self) + 0x4c68 + index * 4) = loaded;
        addref_obj(loaded);
    }

    if (*reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(self) + 0x4c48 + index * 4) != 0) {
        int created = FUN_00533db0(8);
        if (created == 0) {
            int storage = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x48)));
            uint32_t* built;
            if (storage == 0) {
                built = nullptr;
            }
            else {
                built = reinterpret_cast<uint32_t*>(FUN_005428c0(reinterpret_cast<void*>(storage)));
            }
            // The three helpers below work on the object just constructed.
            FUN_004aad20(built, 0);
            FUN_004aacc0(built, 0);
            addref_obj(built);
            uint32_t* attach = built;
            FUN_004aac50(built, &attach);
            release_obj(built);
        }
        FUN_004aad70(self, *reinterpret_cast<uint32_t**>(
            reinterpret_cast<uintptr_t>(self) + 0x4c68 + index * 4));
    }
}

// ---------------------------------------------------------------------------
// 0x4aa560 — observed shape
// Fills the position and normal streams of one terrain cell block.
// ---------------------------------------------------------------------------
void FUN_004aa560(uint16_t param_1, uint16_t param_2, void** param_3, void** param_4,
                  uint32_t* self, uint32_t layer)
{
    uint32_t layerIndex = layer & 0xffff;
    uint16_t extent = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2);
    float step = static_cast<float>(
                     *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x3424 + layerIndex * 2))
                 * 0.01f * (1.0f / static_cast<float>(static_cast<int>(extent - 1))) * 1000.0f;

    float* positions = reinterpret_cast<float*>(
        thunk_FUN_00533c78(static_cast<uint32_t>(static_cast<uint16_t>(extent * extent)) * 0xc));
    *param_3 = positions;
    float* normals = reinterpret_cast<float*>(
        thunk_FUN_00533c78(static_cast<uint32_t>(static_cast<uint16_t>(extent * extent)) * 0xc));
    *param_4 = normals;

    uint32_t count = static_cast<uint32_t>(
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2));
    int row = 0;
    if (count != 0) {
        do {
            int column = 0;
            if (count != 0) {
                uint32_t baseX = param_1;
                uint32_t baseY = param_2;
                int cell = (layerIndex * 0x10 + baseX) * 0x10 + baseY;
                do {
                    float x = static_cast<float>(
                                  static_cast<int>(
                                      static_cast<int>(*reinterpret_cast<int16_t*>(
                                          reinterpret_cast<uintptr_t>(self) + 0x3448 + cell * 4))
                                      + baseX * 1000))
                              + static_cast<float>(row) * step;
                    float y = static_cast<float>(column) * step
                              + static_cast<float>(
                                  static_cast<int>(
                                      static_cast<int>(*reinterpret_cast<int16_t*>(
                                          reinterpret_cast<uintptr_t>(self) + 0x344a + cell * 4))
                                      + baseY * 1000));
                    long double height = FUN_004e7510(
                        x + *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(self) + 0x4c60),
                        y + *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(self) + 0x4c64), 1);

                    float* vertex = reinterpret_cast<float*>(
                        reinterpret_cast<uintptr_t>(*param_3)
                        + (static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(
                               reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2))
                               * static_cast<uint32_t>(column) + static_cast<uint32_t>(row))
                              * 0xc);
                    vertex[0] = x - static_cast<float>(baseX) * 1000.0f;
                    vertex[1] = y - static_cast<float>(baseY) * 1000.0f;
                    int constants = static_cast<int>(DAT_0072cd78);
                    vertex[2] = static_cast<float>(height);

                    uint32_t* normal = reinterpret_cast<uint32_t*>(
                        reinterpret_cast<uintptr_t>(*param_4)
                        + (static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(
                               reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2))
                               * static_cast<uint32_t>(column) + static_cast<uint32_t>(row))
                              * 0xc);
                    normal[0] = *reinterpret_cast<uint32_t*>(constants + 0x6c);
                    normal[1] = *reinterpret_cast<uint32_t*>(constants + 0x70);
                    normal[2] = *reinterpret_cast<uint32_t*>(constants + 0x74);
                    column = column + 1;
                } while (column < static_cast<int>(static_cast<uint32_t>(
                             *reinterpret_cast<uint16_t*>(
                                 reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2))));
            }
            count = static_cast<uint32_t>(
                *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2));
            row = row + 1;
        } while (row < static_cast<int>(count));
    }
}

// ---------------------------------------------------------------------------
// 0x4aa7b0 — observed shape
// Fills the texture-coordinate stream of one terrain cell block from the
// layer's tile mapping.
// ---------------------------------------------------------------------------
void FUN_004aa7b0(uint16_t param_1, uint32_t param_2, float** param_3,
                  uint32_t* self, uint32_t layer)
{
    uint32_t layerIndex = layer & 0xffff;
    uint16_t extent = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2);
    float tiling = static_cast<float>(
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x3430 + layerIndex * 2));
    float cellStep = tiling / (static_cast<float>(static_cast<int>(extent - 1)) * 100.0f);
    float originU = static_cast<float>(
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x180c + layerIndex * 4));
    int cell = (param_2 & 0xffff) + (layerIndex * 0x10 + static_cast<uint32_t>(param_1)) * 0x10;
    uint16_t tileU = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x1824 + cell * 4);
    uint16_t tileV = *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x1826 + cell * 4);
    float extentV = static_cast<float>(
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x180e + layerIndex * 4));
    float centre = (1.0f - tiling * 0.01f) * 0.5f;

    int count = static_cast<int>(reinterpret_cast<intptr_t>(
        thunk_FUN_00533c78(static_cast<uint32_t>(static_cast<uint16_t>(extent * extent)) << 3)));
    *param_3 = reinterpret_cast<float*>(static_cast<intptr_t>(count));

    uint32_t size = static_cast<uint32_t>(
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2));
    int row = 0;
    if (size != 0) {
        do {
            uint32_t column = 0;
            if (size != 0) {
                int offset = 0;
                do {
                    size = static_cast<uint32_t>(
                        *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2));
                    int base = static_cast<int>(reinterpret_cast<intptr_t>(*param_3));
                    int target = (static_cast<int>(size) - row) * static_cast<int>(size) * 8 - offset;
                    *reinterpret_cast<float*>(target - 8 + base) =
                        static_cast<float>(row) * (cellStep / originU)
                        + static_cast<float>(tileU) / originU + centre;
                    *reinterpret_cast<float*>(target - 4 + base) =
                        static_cast<float>(static_cast<int>(column)) * (cellStep / extentV)
                        + static_cast<float>(tileV) / extentV + centre;
                    column = column + 1;
                    offset = offset + 8;
                } while (static_cast<int>(column) < static_cast<int>(static_cast<uint32_t>(
                             *reinterpret_cast<uint16_t*>(
                                 reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2))));
            }
            size = static_cast<uint32_t>(
                *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x343c + layerIndex * 2));
            row = row + 1;
        } while (row < static_cast<int>(size));
    }
}

// ---------------------------------------------------------------------------
// 0x4aa950 — observed shape
// Loads the seabed layer textures, marks the initial walkable cells from the
// map bitmap, then builds the grids and enables the first two layers.
// ---------------------------------------------------------------------------
void FUN_004aa950(void)
{
    uint8_t* pbVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    int iVar5;
    long double fVar6;
    int local_30;
    int local_2c;
    uint32_t local_28;
    const uint8_t* local_24;

    FUN_004aa460(reinterpret_cast<uint32_t*>(DAT_008ca984), 0, "lb_treeshadows.dds");
    FUN_004aa460(reinterpret_cast<uint32_t*>(DAT_008ca984), 1, "lb_rockground.dds");
    FUN_004aa460(reinterpret_cast<uint32_t*>(DAT_008ca984), 4, "lb_grid.dds");
    FUN_004aa460(reinterpret_cast<uint32_t*>(DAT_008ca984), 5, "lb_target.dds");
    FUN_004aa460(reinterpret_cast<uint32_t*>(DAT_008ca984), 2, "lb_movesquare.dds");
    FUN_004aa460(reinterpret_cast<uint32_t*>(DAT_008ca984), 3, "lb_attksquare.dds");

    iVar4 = static_cast<int>(DAT_008ca984);
    *reinterpret_cast<uint16_t*>(DAT_008ca984 + 0x3424) = 0x96;
    local_28 = 0;
    local_2c = 500;
    local_24 = DAT_00871978;
    do {
        uVar3 = 0;
        local_30 = 500;
        do {
            iVar5 = static_cast<int>(((uVar3 & 0xf) + (local_28 & 0xf) * 0x10) * 2) + 0x3024;
            *reinterpret_cast<uint8_t*>(iVar5 + iVar4) =
                static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(iVar5 + iVar4) | 3);
            if (local_24[uVar3] == '\x01') {
                fVar6 = FUN_004e7510(
                    static_cast<float>(local_2c) + *reinterpret_cast<float*>(iVar4 + 0x4c60),
                    static_cast<float>(local_30) + *reinterpret_cast<float*>(iVar4 + 0x4c64), 1);
                iVar4 = static_cast<int>(DAT_008ca984);
                if (fVar6 <= static_cast<long double>(0.0)) {
                    iVar4 = static_cast<int>(DAT_008ca984);
                }
                else {
                    *reinterpret_cast<uint8_t*>(iVar5 + DAT_008ca984) =
                        static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(iVar5 + DAT_008ca984) & 0xfe);
                }
            }
            else if (local_24[uVar3] == '\x02') {
                fVar6 = FUN_004e7510(
                    static_cast<float>(local_2c) + *reinterpret_cast<float*>(iVar4 + 0x4c60),
                    static_cast<float>(local_30) + *reinterpret_cast<float*>(iVar4 + 0x4c64), 1);
                iVar4 = static_cast<int>(DAT_008ca984);
                if (fVar6 <= static_cast<long double>(0.0)) {
                    iVar4 = static_cast<int>(DAT_008ca984);
                }
                else {
                    *reinterpret_cast<uint8_t*>(iVar5 + DAT_008ca984) =
                        static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(iVar5 + DAT_008ca984) & 0xfd);
                    pbVar1 = reinterpret_cast<uint8_t*>(iVar5 + iVar4);
                    *pbVar1 = static_cast<uint8_t>(*pbVar1 | 0x2c);
                }
            }
            local_30 = local_30 + 1000;
            uVar3 = uVar3 + 1;
        } while (local_30 < 0x4074);
        local_24 = local_24 + 0x10;
        local_28 = local_28 + 1;
        local_2c = local_2c + 1000;
        if (0x871a77 < static_cast<int>(reinterpret_cast<intptr_t>(local_24))) {
            FUN_004a97f0(reinterpret_cast<uint32_t*>(DAT_008ca984));
            iVar4 = 0;
            do {
                iVar5 = 0;
                do {
                    // Layer selector arrives in EDI and is not exposed by the listing.
                    FUN_004aa340(static_cast<uint16_t>(iVar4), static_cast<uint16_t>(iVar5), 1,
                                 0x3f800000, reinterpret_cast<uint32_t*>(DAT_008ca984), 0);
                    FUN_004aa340(static_cast<uint16_t>(iVar4), static_cast<uint16_t>(iVar5), 1,
                                 0x3f800000, reinterpret_cast<uint32_t*>(DAT_008ca984), 0);
                    FUN_004aa340(static_cast<uint16_t>(iVar4), static_cast<uint16_t>(iVar5), 0,
                                 0x3f800000, reinterpret_cast<uint32_t*>(DAT_008ca984), 0);
                    FUN_004aa340(static_cast<uint16_t>(iVar4), static_cast<uint16_t>(iVar5), 0,
                                 0x3f800000, reinterpret_cast<uint32_t*>(DAT_008ca984), 0);
                    iVar2 = static_cast<int>(DAT_008ca984);
                    iVar5 = iVar5 + 1;
                } while (iVar5 < 0x10);
                iVar4 = iVar4 + 1;
            } while (iVar4 < 0x10);

            if (*reinterpret_cast<int*>(DAT_008ca984 + 0x4c5c) != 0) {
                pbVar1 = reinterpret_cast<uint8_t*>(
                    *reinterpret_cast<int*>(DAT_008ca984 + 0x4c5c) + 0x20);
                *pbVar1 = static_cast<uint8_t>(*pbVar1 | 1);
            }
            *reinterpret_cast<uint8_t*>(iVar2 + 10) = 1;
            if (*reinterpret_cast<int*>(iVar2 + 0x4c58) != 0) {
                pbVar1 = reinterpret_cast<uint8_t*>(
                    *reinterpret_cast<int*>(iVar2 + 0x4c58) + 0x20);
                *pbVar1 = static_cast<uint8_t>(*pbVar1 | 1);
            }
            *reinterpret_cast<uint8_t*>(iVar2 + 9) = 1;
            return;
        }
    } while (true);
}

// ---------------------------------------------------------------------------
// 0x4aac50 — observed shape
// Appends one entry, holding a reference to param_1's object, to the list
// owned by self.
// ---------------------------------------------------------------------------
void FUN_004aac50(uint32_t* self, uint32_t** param_1)
{
    auto allocate = *reinterpret_cast<void* (*)(uint32_t*)>(*self + 4);
    int* node = reinterpret_cast<int*>(allocate(self));
    uint32_t* current = reinterpret_cast<uint32_t*>(node[2]);
    if (current != *param_1) {
        if (current != nullptr) {
            release_obj(current);
        }
        uint32_t* value = *param_1;
        node[2] = static_cast<int>(reinterpret_cast<intptr_t>(value));
        if (value != nullptr) {
            *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(value) + 4) =
                *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(value) + 4) + 1;
        }
    }
    node[1] = 0;
    node[0] = static_cast<int>(self[1]);
    if (self[1] == 0) {
        self[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));
        self[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));
        self[3] = self[3] + 1;
        return;
    }
    *reinterpret_cast<int**>(self[1] + 4) = node;
    self[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));
    self[3] = self[3] + 1;
}

// ---------------------------------------------------------------------------
// 0x4aacc0 — observed shape
// Stores param_1 in the object's +8 field, creating the holder on demand.
// ---------------------------------------------------------------------------
void FUN_004aacc0(uint32_t* self, uint32_t param_1)
{
    int holder = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(self) + 0x2c);
    if (*reinterpret_cast<int*>(holder) != 0) {
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(holder) + 8) = param_1;
        return;
    }
    int created = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
    if (created == 0) {
        created = 0;
    }
    else {
        created = FUN_005426d0(reinterpret_cast<void*>(created));
    }
    int local_4 = created;
    FUN_005606f0(0, &local_4);
    *reinterpret_cast<uint32_t*>(created + 8) = param_1;
}

// ---------------------------------------------------------------------------
// 0x4aad20 — observed shape
// Stores the live-in EBX payload in the object's +0xc field, creating the
// holder on demand.
// ---------------------------------------------------------------------------
void FUN_004aad20(uint32_t* self, uint32_t value)
{
    int holder = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(self) + 0x2c);
    if (*reinterpret_cast<int*>(holder) != 0) {
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(holder) + 0xc) = value;
        return;
    }
    int created = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
    if (created == 0) {
        created = 0;
    }
    else {
        created = FUN_005426d0(reinterpret_cast<void*>(created));
    }
    int local_4 = created;
    FUN_005606f0(0, &local_4);
    *reinterpret_cast<uint32_t*>(created + 0xc) = value;
}

// ---------------------------------------------------------------------------
// 0x4aad70 — observed shape
// Installs param_1 as the holder's +4 object, releasing the previous one.
// ---------------------------------------------------------------------------
void FUN_004aad70(uint32_t* self, uint32_t* param_1)
{
    int holder = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(self) + 0x2c);
    holder = *reinterpret_cast<int*>(holder);
    int local_4 = static_cast<int>(reinterpret_cast<intptr_t>(self));
    if (holder == 0) {
        int created = static_cast<int>(reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
        if (created == 0) {
            created = 0;
        }
        else {
            created = FUN_005426d0(reinterpret_cast<void*>(created));
        }
        holder = created;
        local_4 = created;
        FUN_005606f0(0, &local_4);
    }
    uint32_t* current = *reinterpret_cast<uint32_t**>(holder + 4);
    if (current != param_1) {
        if (current != nullptr) {
            release_obj(current);
        }
        *reinterpret_cast<uint32_t**>(holder + 4) = param_1;
        addref_obj(param_1);
    }
}
