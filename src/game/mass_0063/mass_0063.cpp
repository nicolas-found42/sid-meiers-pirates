// Sid Meier's Pirates! (2004) — reconstruction batch mass_0063
// Target: PE32 i386, image 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
// Addresses: 0x4ea8f0, 0x4ea9a0, 0x4eaae0, 0x4eaf80, 0x4eb1d0, 0x4eb5b0,
//            0x4ebe80, 0x4ebf70, 0x4ec000, 0x4ec0a0, 0x4ec1c0, 0x4ec270,
//            0x4ec790, 0x4ece40, 0x4ed110, 0x4ed130, 0x4ed1a0, 0x4ed240,
//            0x4ed270, 0x4ed370
// Source: Ghidra 12.2 pseudocode, one corpus file per function.
// Register receivers (ECX/ESI/EDI/EBX/EAX) are written as explicit parameters.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers observed in the supplied corpus listings.
// ---------------------------------------------------------------------------
extern void*    FUN_00533c78(uint32_t size);
extern void*    thunk_FUN_00533c78(uint32_t size);
extern void*    FUN_00540540(const char* name);
extern int      FUN_00501140(uint32_t object, void* type);
extern void     FUN_004ed8f0(uint32_t value);
extern uint32_t FUN_0054c4a0(int32_t count, void* data);
extern void     FUN_005407d0(const char* name, uint32_t handle);
extern void     FUN_0054c2e0(int32_t count, void* data);
extern void     FUN_005be280(const char* name, int32_t size, void* data);
extern uint32_t FUN_005f0ddc(void);
extern void*    FUN_0053bb30(int32_t arg);
extern void     FUN_004ee010(void);
extern void     FUN_004e6420(void);
extern void     FUN_004ed7b0(uint32_t index, int32_t object);
extern void     FUN_004ed860(int32_t* value);
extern void     FUN_005120c0(int32_t arg);
extern void     FUN_00511f10(void);
extern void     FUN_00533e70(int32_t object);
extern void     FUN_00512f70(int32_t arg);
extern void     FUN_00540970(void* name);
extern void     FUN_00547730(uint32_t object, const char* name, int32_t arg);
extern void     FUN_00540460(const char* name);
extern void     FUN_00534130(void);
extern void*    FUN_00538680(void);
extern void     FUN_004edf70(void);
extern void     FUN_00533d10(int32_t a, int32_t b);
extern void*    FUN_00500850(void);
extern void     FUN_00547d10(void);
extern void     FUN_00547ca0(void* object);
extern void     operator_delete__(void* ptr);
extern void     operator_delete(void* ptr);
extern uint32_t FUN_00513540(void* out);
extern char     FUN_0051bfc0(void** out);

// Intra-batch forward declarations (definitions appear below).
void    FUN_004eaf80(void* self, uint32_t cellSpan);
int32_t FUN_004eb1d0(void* param_1, void* param_2, int32_t param_3);

// ---------------------------------------------------------------------------
// Globals referenced by the listings.
// ---------------------------------------------------------------------------
extern uint32_t DAT_00727560;
extern uint32_t DAT_00727598;
extern uint32_t DAT_0071000c;
extern uint8_t  PTR_FUN_0070fe5c;                     // vtable image stored in patch objects
extern void     (*PTR_FUN_00717a84)(const char*, const char*, int);
extern uint32_t DAT_008ea110[256];
extern uint8_t  DAT_0072cd78[];                       // landscape/world manager base
extern uint8_t  DAT_008cacac[];                       // renderer/collection state
extern int32_t  DAT_008cacb8;
extern char     DAT_008caca8;
extern uint32_t* DAT_008cacb0;                        // canopy object table (count at [-1])
extern uint32_t DAT_008cacb4;
extern float    DAT_008caca4;
extern float    DAT_008caca0;
extern float    DAT_008cac9c;

// ---------------------------------------------------------------------------
// Virtual-call and refcount shapes shared by this batch.
// ---------------------------------------------------------------------------
static void* vtable_entry(void* object, uint32_t byteOffset)
{
    void** vtable = *reinterpret_cast<void***>(object);
    return *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtable) + byteOffset);
}

static void vcall_void_int(void* object, uint32_t byteOffset, int32_t argument)
{
    typedef void (__thiscall* Fn)(void*, int32_t);
    reinterpret_cast<Fn>(vtable_entry(object, byteOffset))(object, argument);
}

static void* vcall_ret_ptr(void* object, uint32_t byteOffset)
{
    typedef void* (__thiscall* Fn)(void*);
    return reinterpret_cast<Fn>(vtable_entry(object, byteOffset))(object);
}

static int32_t& object_refcount(void* object)
{
    return *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(object) + 4);
}

static void object_addref(void* object)
{
    if (object != nullptr) {
        object_refcount(object) = object_refcount(object) + 1;
    }
}

static void object_release(void* object)
{
    if (object == nullptr) {
        return;
    }
    int32_t* count = reinterpret_cast<int32_t*>(static_cast<uint8_t*>(object) + 4);
    *count = *count - 1;
    if (*count == 0) {
        typedef void (__thiscall* DtorFn)(void*, int32_t);
        (*reinterpret_cast<DtorFn*>(*reinterpret_cast<void**>(object)))(object, 1);
    }
}

static void object_destroy(void* object)
{
    typedef void (__thiscall* DtorFn)(void*, int32_t);
    (*reinterpret_cast<DtorFn*>(*reinterpret_cast<void**>(object)))(object, 1);
}

// Refcounted slot assignment: release the old object, store, addref the new one.
static void assign_object(void** slot, void* value)
{
    void* old = *slot;
    if (old == value) {
        return;
    }
    object_release(old);
    *slot = value;
    object_addref(value);
}

// Terrain height sample used by the canopy builders (+0xc8 height plane).
static float sample_height(uint8_t* self, int32_t index)
{
    uint8_t* heights = *reinterpret_cast<uint8_t**>(self + 0xc8);
    return (static_cast<float>(static_cast<int32_t>(heights[index]) - 0x80) / DAT_008caca4) *
           *reinterpret_cast<float*>(self + 0x8c);
}

// Interleaved canopy record pointed to by the landscape patch lists.
struct PatchRecord {
    float   x;          // +0x00
    float   y;          // +0x04
    float   z;          // +0x08
    float   radius;     // +0x0c
    int16_t tileX;      // +0x10
    int16_t spanW;      // +0x12
    int16_t tileY;      // +0x14
    int16_t spanH;      // +0x16
    uint8_t flag;       // +0x18
    uint8_t pad[3];     // +0x19
    uint8_t* heights;   // +0x1c
    uint8_t* colors;    // +0x20
};

// 0x4ea8f0 — observed shape
// Stops the canopy material animation for the active landscape patch and
// advances the frame counter.
void FUN_004ea8f0(void* self, void* param_1)
{
    uint8_t* const base = static_cast<uint8_t*>(param_1);
    uint8_t* const s = static_cast<uint8_t*>(self);
    int32_t* piVar1 = *reinterpret_cast<int32_t**>(base + 8);
    uint32_t uVar3;

    if (piVar1 == nullptr) {
        uVar3 = 0;
    }
    else {
        typedef void* (__thiscall* IterFn)(void*);
        int32_t* vtable = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*piVar1));
        IterFn iterFn = *reinterpret_cast<IterFn*>(reinterpret_cast<uint8_t*>(vtable) + 4);
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(iterFn(piVar1));
        uint32_t bVar2;
        for (; puVar4 != nullptr; puVar4 = reinterpret_cast<uint32_t*>(puVar4[1])) {
            if (puVar4 == &DAT_00727560) {
                bVar2 = 1;
                goto LAB_004ea920;
            }
        }
        bVar2 = 0;
    LAB_004ea920:
        uVar3 = (0u - bVar2) & static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar1));
    }

    int32_t iVar5 = FUN_00501140(uVar3, &DAT_00727598);
    if ((iVar5 != 0) && (DAT_008cacb8 != 0)) {
        uint8_t* found = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar5));
        FUN_004ed8f0(*reinterpret_cast<uint32_t*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<int32_t*>(found + 0xbc))) + 0x20));
    }

    FUN_004eaf80(self,
                 *reinterpret_cast<uint32_t*>(base + 0x28) /
                     (*reinterpret_cast<uint32_t*>(s + 0x80) - 1u));

    int32_t* count = reinterpret_cast<int32_t*>(s + 0xc4);
    *count = *count - static_cast<int32_t>(*count != 0);
}

// 0x4ea9a0 — observed shape
// Uploads the landscape shader parameter/value blocks.
struct LandscapeParams {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    float    scale;
};

struct LandscapeValues {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
};

void FUN_004ea9a0(void* self)
{
    uint8_t* const s = static_cast<uint8_t*>(self);

    if (*reinterpret_cast<int32_t*>(s + 4) == 0) {
        return;
    }

    LandscapeParams local_20;
    local_20.a = *reinterpret_cast<uint32_t*>(s + 0x98);
    local_20.b = *reinterpret_cast<uint32_t*>(s + 0x9c);
    local_20.c = *reinterpret_cast<uint32_t*>(s + 0x90);
    if (DAT_0072cd78 == nullptr) {
        local_20.scale = 1.0f;
    }
    else {
        local_20.scale = *reinterpret_cast<float*>(DAT_0072cd78 + 0x28) * 0.4f;
    }

    void* iVar1 = FUN_00540540("LM_SHADER");
    if (iVar1 == nullptr) {
        iVar1 = FUN_00533c78(0x18);
        uint32_t uVar2;
        if (iVar1 == nullptr) {
            uVar2 = 0;
        }
        else {
            uVar2 = FUN_0054c4a0(4, &local_20);
        }
        FUN_005407d0("LM_SHADER", uVar2);
    }
    FUN_0054c2e0(4, &local_20);
    FUN_005be280("f4LandscapeParams", 0x10, &local_20);

    LandscapeValues local_10;
    local_10.c = *reinterpret_cast<uint32_t*>(s + 0x84);
    local_10.d = *reinterpret_cast<uint32_t*>(s + 0x8c);
    local_10.a = 0x40800000;
    local_10.b = 0x437f0000;

    iVar1 = FUN_00540540("LM_SHADER2");
    if (iVar1 == nullptr) {
        iVar1 = FUN_00533c78(0x18);
        uint32_t uVar2;
        if (iVar1 == nullptr) {
            uVar2 = 0;
        }
        else {
            uVar2 = FUN_0054c4a0(4, &local_10);
        }
        FUN_005407d0("LM_SHADER2", uVar2);
    }
    FUN_0054c2e0(4, &local_10);
    FUN_005be280("f4LandscapeValues", 0x10, &local_10);
}

// 0x4eaae0 — observed shape
// Builds (or refreshes) the per-tile canopy object grid: one 8x8 patch object
// per 8x8 tile block, then a second pass that grows the visible canopy level.
void FUN_004eaae0(void* self)
{
    uint8_t* const s = static_cast<uint8_t*>(self);

    if (*reinterpret_cast<int32_t*>(s + 0xac) == 0) {
        uint32_t uVar6 = FUN_005f0ddc();
        *reinterpret_cast<uint32_t*>(s + 0xb8) = uVar6;
        uVar6 = FUN_005f0ddc();
        *reinterpret_cast<uint32_t*>(s + 0xbc) = uVar6;
        if (DAT_008caca8 == '\0') {
            return;
        }

        void* iVar7 = FUN_00533c78(0xec);
        void** puVar8;
        if (iVar7 == nullptr) {
            puVar8 = nullptr;
        }
        else {
            puVar8 = static_cast<void**>(FUN_0053bb30(0));
        }

        void** puVar1 = *reinterpret_cast<void***>(s + 0xac);
        if (puVar1 != puVar8) {
            object_release(puVar1);
            *reinterpret_cast<void***>(s + 0xac) = puVar8;
            object_addref(puVar8);
        }

        int32_t iVar7v = *reinterpret_cast<int32_t*>(s + 0xac);
        uint8_t* patchManager = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar7v));
        *reinterpret_cast<uint32_t*>(patchManager + 0x5c) = 0;
        *reinterpret_cast<uint32_t*>(patchManager + 0x60) = 0;
        *reinterpret_cast<uint32_t*>(patchManager + 100) = 0;
        *reinterpret_cast<uint32_t*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<int32_t*>(s + 0xac))) + 0x68) = 0x3f800000u;

        vcall_void_int(*reinterpret_cast<void**>(s + 4),
                       0x70,
                       *reinterpret_cast<int32_t*>(s + 0xac));

        void* uVar6p = thunk_FUN_00533c78(*reinterpret_cast<int32_t*>(s + 0xb8) << 2);
        *reinterpret_cast<void**>(s + 0xb4) = uVar6p;
        uVar6p = thunk_FUN_00533c78(*reinterpret_cast<int32_t*>(s + 0xb8) << 2);
        *reinterpret_cast<void**>(s + 0xb0) = uVar6p;

        uint32_t uVar13 = *reinterpret_cast<uint32_t*>(s + 0xb8);
        int32_t iVar7i = 0;
        float fVar3 = static_cast<float>(static_cast<int32_t>(uVar13));
        if (static_cast<int32_t>(uVar13) < 0) {
            fVar3 = fVar3 + 4.2949673e+09f;
        }
        if (0.0f < fVar3 * 0.125f + static_cast<float>((uVar13 & 7) != 0)) {
            void** rowHeights = *reinterpret_cast<void***>(s + 0xb4);
            void** rowObjects = *reinterpret_cast<void***>(s + 0xb0);
            do {
                rowHeights[iVar7i] = thunk_FUN_00533c78(*reinterpret_cast<uint32_t*>(s + 0xbc));

                int32_t iVar14 = *reinterpret_cast<int32_t*>(s + 0xbc);
                int32_t* piVar9 = static_cast<int32_t*>(thunk_FUN_00533c78(
                    static_cast<uint32_t>(iVar14) * 4 + 4));
                if (piVar9 == nullptr) {
                    piVar9 = nullptr;
                }
                else {
                    *piVar9 = iVar14;
                    piVar9 = piVar9 + 1;
                    if (-1 < iVar14 - 1) {
                        int32_t* piVar15 = piVar9;
                        for (; iVar14 != 0; iVar14 = iVar14 - 1) {
                            *piVar15 = 0;
                            piVar15 = piVar15 + 1;
                        }
                    }
                }
                rowObjects[iVar7i] = piVar9;

                uVar13 = *reinterpret_cast<uint32_t*>(s + 0xbc);
                int32_t iVar14b = 0;
                fVar3 = static_cast<float>(static_cast<int32_t>(uVar13));
                if (static_cast<int32_t>(uVar13) < 0) {
                    fVar3 = fVar3 + 4.2949673e+09f;
                }
                if (0.0f < fVar3 * 0.125f + static_cast<float>((uVar13 & 7) != 0)) {
                    do {
                        reinterpret_cast<uint8_t*>(
                            rowHeights[iVar7i])[iVar14b] = 0;

                        int32_t iVar2 = reinterpret_cast<int32_t>(rowObjects[iVar7i]);
                        void** puVar8b = reinterpret_cast<void**>(
                            *reinterpret_cast<int32_t*>(
                                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar2)) +
                                iVar14b * 4));
                        if (puVar8b != nullptr) {
                            object_release(puVar8b);
                            *reinterpret_cast<uint32_t*>(
                                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar2)) +
                                iVar14b * 4) = 0;
                        }

                        uVar13 = *reinterpret_cast<uint32_t*>(s + 0xbc);
                        iVar14b = iVar14b + 1;
                        fVar3 = static_cast<float>(iVar14b);
                        if (iVar14b < 0) {
                            fVar3 = fVar3 + 4.2949673e+09f;
                        }
                        float fVar4 = static_cast<float>(static_cast<int32_t>(uVar13));
                        if (static_cast<int32_t>(uVar13) < 0) {
                            fVar4 = fVar4 + 4.2949673e+09f;
                        }
                    } while (fVar3 < fVar4 * 0.125f + static_cast<float>((uVar13 & 7) != 0));
                }

                uVar13 = *reinterpret_cast<uint32_t*>(s + 0xb8);
                iVar7i = iVar7i + 1;
                fVar3 = static_cast<float>(iVar7i);
                if (iVar7i < 0) {
                    fVar3 = fVar3 + 4.2949673e+09f;
                }
                float fVar4 = static_cast<float>(static_cast<int32_t>(uVar13));
                if (static_cast<int32_t>(uVar13) < 0) {
                    fVar4 = fVar4 + 4.2949673e+09f;
                }
                if (fVar3 < fVar4 * 0.125f + static_cast<float>((uVar13 & 7) != 0)) {
                    continue;
                }
                break;
            } while (true);
        }
    }

    if (DAT_008caca8 != '\0') {
        uint32_t uVar10 = FUN_005f0ddc();
        uint32_t uVar11 = FUN_005f0ddc();
        uint32_t uVar12 = FUN_005f0ddc();
        for (uint32_t uVar13 = FUN_005f0ddc(); uVar13 <= uVar10; uVar13 = uVar13 + 1) {
            for (uint32_t uVar16 = uVar11; uVar16 <= uVar12; uVar16 = uVar16 + 1) {
                void** rowHeights = *reinterpret_cast<void***>(s + 0xb4);
                int32_t iVar7c = reinterpret_cast<int32_t>(rowHeights[uVar13]);
                uint8_t* row = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar7c));
                if (-1 < static_cast<char>(row[uVar16])) {
                    if (row[uVar16] == '\0') {
                        char cVar5 = static_cast<char>(FUN_004eb1d0(
                            self, reinterpret_cast<void*>(static_cast<uintptr_t>(uVar13)),
                            static_cast<int32_t>(uVar16)));
                        if (cVar5 == '\0') {
                            goto LAB_004eaf65;
                        }
                        iVar7c = reinterpret_cast<int32_t>(rowHeights[uVar13]);
                        row = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar7c));
                    }
                    row[uVar16] = static_cast<uint8_t>(row[uVar16] + 1);
                }
            LAB_004eaf65:
                ;
            }
        }
    }
}

// 0x4eaf80 — observed shape
// Shrinks the visible canopy level for every tile in the camera span, freeing
// patch objects that reach level 0. The call site also pushes a span argument
// that this body never reads; it is kept in the signature for fidelity.
void FUN_004eaf80(void* self, uint32_t cellSpan)
{
    uint8_t* const s = static_cast<uint8_t*>(self);
    (void)cellSpan;

    if (DAT_008caca8 == '\0') {
        return;
    }

    uint32_t uVar6 = FUN_005f0ddc();
    uint32_t uStack00000008 = FUN_005f0ddc();
    uint32_t local_4 = uStack00000008;

    for (uint32_t uVar7 = FUN_005f0ddc(); uVar7 <= uVar6; uVar7 = uVar7 + 1) {
        do {
            if (*reinterpret_cast<int32_t*>(s + 0xb4) != 0) {
                void** rowHeights = *reinterpret_cast<void***>(s + 0xb4);
                int32_t iVar3 = reinterpret_cast<int32_t>(rowHeights[uVar7]);
                uint8_t* row = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar3));
                char cVar2 = static_cast<char>(row[uStack00000008]);
                if (-1 < cVar2) {
                    if (cVar2 != '\0') {
                        row[uStack00000008] = static_cast<uint8_t>(row[uStack00000008] - 1);
                    }
                    if (row[uStack00000008] == '\0') {
                        void** rowObjects = *reinterpret_cast<void***>(s + 0xb0);
                        int32_t iVar4 = reinterpret_cast<int32_t>(rowObjects[uVar7]);
                        int32_t iVar3b = static_cast<int32_t>(uStack00000008) * 4;
                        uint8_t* slotBase = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar4));
                        if (*reinterpret_cast<int32_t*>(slotBase + iVar3b) != 0) {
                            uint8_t* object = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                                *reinterpret_cast<int32_t*>(slotBase + iVar3b)));
                            void* receiver = *reinterpret_cast<void**>(object + 0x24);
                            void* local_8 = nullptr;
                            typedef void (__thiscall* GetFn)(void*, void** out, void* obj);
                            reinterpret_cast<GetFn>(vtable_entry(receiver, 0x74))(
                                receiver, &local_8, object);
                            if (local_8 != nullptr) {
                                object_release(local_8);
                            }

                            void* puVar5 = reinterpret_cast<void*>(static_cast<uintptr_t>(
                                *reinterpret_cast<int32_t*>(slotBase + iVar3b)));
                            object_addref(puVar5);
                            if ((*reinterpret_cast<uint32_t*>(DAT_008cacac + 0x14) <
                                 *reinterpret_cast<uint32_t*>(DAT_008cacac + 4)) ||
                                (*reinterpret_cast<uint32_t*>(DAT_008cacac + 4) == 0)) {
                                FUN_004ee010();
                            }
                            object_release(puVar5);

                            uint8_t* slotBase2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                                reinterpret_cast<int32_t>(rowObjects[uVar7])));
                            void* puVar5b = reinterpret_cast<void*>(static_cast<uintptr_t>(
                                *reinterpret_cast<int32_t*>(slotBase2 + iVar3b)));
                            if (puVar5b != nullptr) {
                                object_release(puVar5b);
                                *reinterpret_cast<uint32_t*>(slotBase2 + iVar3b) = 0;
                            }
                        }
                    }
                }
            }
            uStack00000008 = uStack00000008 + 1;
        } while (uStack00000008 <= local_4);
        uStack00000008 = local_4;
    }
}

// 0x4eb1d0 — observed shape
// Builds the 8x8 canopy patch for tile (rowIndex, colIndex) and binds it to the
// 'TCanopy' material. Returns 0 when the patch is flat (no canopy), 1 on build.
int32_t FUN_004eb1d0(void* param_1, void* param_2, int32_t param_3)
{
    int32_t iVar9 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_2));
    int32_t iVar8 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_1));
    uint8_t* const s = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar8));
    uint32_t flag = (static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1)) & 0xffffff00u) | 1u;

    float* local_20 = static_cast<float*>(FUN_00533c78(0x410));
    if (local_20 == nullptr) {
        local_20 = nullptr;
    }
    else {
        FUN_00547ca0(&DAT_0071000c);
        *reinterpret_cast<void**>(local_20) = &PTR_FUN_0070fe5c;
        float* pfVar15 = local_20 + 4;
        for (int32_t iVar12 = 0x100; iVar12 != 0; iVar12 = iVar12 + -1) {
            *pfVar15 = 0.0f;
            pfVar15 = pfVar15 + 1;
        }
    }

    uint32_t uVar13 = 0;
    int32_t iVar12 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_2)) * 8;
    float* local_1c = local_20;
    do {
        local_1c = local_1c + 0x20;
        uint32_t uVar14 = 0;
        float* param_2f = local_1c;
        do {
            float local_10;
            float local_c;
            float local_8;
            uint32_t uVar3 = uVar14 + static_cast<uint32_t>(param_3) * 8;
            if ((static_cast<uint32_t>(iVar12) + uVar13 < *reinterpret_cast<uint32_t*>(s + 0xb8)) &&
                (uVar3 < *reinterpret_cast<uint32_t*>(s + 0xbc))) {
                int32_t iVar10 = static_cast<int32_t>(
                    uVar3 * *reinterpret_cast<uint32_t*>(s + 0xb8));
                int32_t sampleIndex = iVar10 + iVar12 + static_cast<int32_t>(uVar13);
                uint8_t* heightPlane = *reinterpret_cast<uint8_t**>(s + 0xc8);
                uint8_t* colorPlane = *reinterpret_cast<uint8_t**>(s + 0xcc);
                uint8_t* colorPlane2 = *reinterpret_cast<uint8_t**>(s + 0xd0);
                local_10 = (static_cast<float>(static_cast<int32_t>(heightPlane[sampleIndex]) - 0x80) /
                            DAT_008caca4) * *reinterpret_cast<float*>(s + 0x8c);
                local_c = static_cast<float>(colorPlane[sampleIndex]) * 0.003921569f;
                local_8 = static_cast<float>(colorPlane2[sampleIndex]) * 0.003921569f;
                if (0.5f < local_c) {
                    flag = flag & 0xffffff00u;
                }
            }
            else {
                local_10 = 0.0f;
                local_c = 0.0f;
                local_8 = 0.0f;
            }
            *param_2f = local_10;
            param_2f[1] = local_c;
            param_2f[2] = local_8;
            param_2f[3] = 0.0f;
            uVar14 = uVar14 + 1;
            param_2f = param_2f + -4;
        } while (uVar14 < 8);
        uVar13 = uVar13 + 1;
    } while (uVar13 < 8);

    if (static_cast<char>(flag) != '\0') {
        if (local_20 != nullptr) {
            object_destroy(local_20);
        }
        void** rowHeights = *reinterpret_cast<void***>(s + 0xb4);
        reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(reinterpret_cast<int32_t>(rowHeights[iVar9])))[param_3] = 0x80;
        return 0;
    }

    int32_t* param_1b;
    bool bVar5;
    if (*reinterpret_cast<int32_t*>(DAT_008cacac + 0x14) == 0) {
        param_1b = static_cast<int32_t*>(FUN_00538680());
        if (param_1b != nullptr) {
            param_1b[1] = param_1b[1] + 1;
            goto LAB_004eb397;
        }
    }
    else {
        FUN_004edf70();
    LAB_004eb397:
        if (param_1b != nullptr) {
            int32_t iVar12b = param_1b[1];
            param_1b[1] = iVar12b + 1;
            param_1b[1] = iVar12b;
            if (iVar12b == 0) {
                object_destroy(param_1b);
            }
            uint32_t* puVar11 = static_cast<uint32_t*>(vcall_ret_ptr(param_1b, 4));
            for (; puVar11 != nullptr; puVar11 = reinterpret_cast<uint32_t*>(puVar11[1])) {
                if (puVar11 == &DAT_00727598) {
                    bVar5 = true;
                    goto LAB_004eb3d9;
                }
            }
            bVar5 = false;
        LAB_004eb3d9:
            param_1b = reinterpret_cast<int32_t*>(
                (0u - static_cast<uint32_t>(bVar5)) &
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1b)));
            goto LAB_004eb3e3;
        }
    }
    param_1b = nullptr;

LAB_004eb3e3:
    {
        void** rowObjects = *reinterpret_cast<void***>(s + 0xb0);
        int32_t iVar12c = reinterpret_cast<int32_t>(rowObjects[iVar9]);
        int32_t iVar10 = param_3 * 4;
        void** slot = reinterpret_cast<void**>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar12c)) + iVar10);
        assign_object(slot, param_1b);
    }

    FUN_00540970(&DAT_0071000c);
    FUN_005407d0(reinterpret_cast<const char*>(&DAT_0071000c), reinterpret_cast<uint32_t>(local_20));

    void** rowObjects2 = *reinterpret_cast<void***>(s + 0xb0);
    int32_t iVar12d = reinterpret_cast<int32_t>(rowObjects2[iVar9]);
    int32_t iVar10b = param_3 * 4;
    uint8_t* object = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
        *reinterpret_cast<int32_t*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar12d)) + iVar10b)));

    *reinterpret_cast<float*>(object + 0x68) = static_cast<float>(std::fabs(DAT_008caca4));

    float fVar6 = static_cast<float>(iVar9);
    if (iVar9 < 0) {
        fVar6 = fVar6 + 4.2949673e+09f;
    }
    float fVar4 = static_cast<float>(param_3);
    if (param_3 < 0) {
        fVar4 = fVar4 + 4.2949673e+09f;
    }
    float fVar7 = fVar4 * DAT_008caca0 * DAT_008caca4;
    float fVar4b = *reinterpret_cast<float*>(s + 0x8c);
    *reinterpret_cast<float*>(object + 0x5c) = fVar6 * DAT_008cac9c * DAT_008caca4;
    *reinterpret_cast<float*>(object + 0x60) = -fVar7;
    *reinterpret_cast<float*>(object + 100) = fVar4b * 127.9f;

    FUN_00547730(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(object)), "TCanopy", 0);
    FUN_00540460("Canopy");
    vcall_void_int(*reinterpret_cast<void**>(s + 0xac), 0x70,
                   static_cast<int32_t>(reinterpret_cast<uintptr_t>(object)));
    FUN_00534130();

    uint8_t* pbVar2 = reinterpret_cast<uint8_t*>(
        reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
            *reinterpret_cast<int32_t*>(
                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar12d)) + iVar10b))) + 0x20);
    *pbVar2 = static_cast<uint8_t>(*pbVar2 | 1);
    *reinterpret_cast<uint8_t*>(s + 0xc0) = 1;

    if (local_20 != nullptr) {
        int32_t* ref = reinterpret_cast<int32_t*>(local_20) + 1;
        *ref = *ref + -1;
        if (*ref == 0) {
            object_destroy(local_20);
        }
    }
    return 1;
}

// 0x4eb5b0 — observed shape
// Refreshes the height component of every vertex of every live canopy patch
// across the 8x8 tile grid, then repositions the patch object.
void FUN_004eb5b0(void* self)
{
    uint8_t* const s = static_cast<uint8_t*>(self);
    uint32_t uVar6 = *reinterpret_cast<uint32_t*>(s + 0xb8);
    int32_t local_28 = 0;
    float local_4 = 0.0f;
    float fVar2 = static_cast<float>(static_cast<int32_t>(uVar6));
    if (static_cast<int32_t>(uVar6) < 0) {
        fVar2 = fVar2 + 4.2949673e+09f;
    }

    if (0.0f < fVar2 * 0.125f + static_cast<float>((uVar6 & 7) != 0)) {
        float local_24 = 0.0f;
        do {
            uVar6 = *reinterpret_cast<uint32_t*>(s + 0xbc);
            int32_t local_30 = 0;
            fVar2 = static_cast<float>(static_cast<int32_t>(uVar6));
            if (static_cast<int32_t>(uVar6) < 0) {
                fVar2 = fVar2 + 4.2949673e+09f;
            }
            if (0.0f < fVar2 * 0.125f + static_cast<float>((uVar6 & 7) != 0)) {
                float local_2c = 0.0f;
                int32_t local_34 = 2;
                do {
                    void** rowObjects = *reinterpret_cast<void***>(s + 0xb0);
                    if ((*reinterpret_cast<int32_t*>(s + 0xb0) != 0) &&
                        (*reinterpret_cast<int32_t*>(
                             reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                                 reinterpret_cast<int32_t>(rowObjects[local_28]))) +
                             local_30 * 4) != 0)) {
                        void* iVar4p = FUN_00540540(
                            reinterpret_cast<const char*>(&DAT_0071000c));
                        if (iVar4p != nullptr) {
                            uint32_t uVar6b = 0;
                            int32_t iVar1 = local_28 * 8;
                            float* pfVar7 = reinterpret_cast<float*>(
                                reinterpret_cast<uint8_t*>(iVar4p) + 0x70);
                            do {
                                int32_t iVar4 = *reinterpret_cast<int32_t*>(s + 0xb8) * (local_34 + -2);
                                int32_t iVar5 = iVar4 + iVar1 + static_cast<int32_t>(uVar6b);
                                int32_t iVar5b;
                                if ((iVar5 < 0) ||
                                    (*reinterpret_cast<int32_t*>(s + 0xbc) *
                                         *reinterpret_cast<int32_t*>(s + 0xb8) < iVar5)) {
                                    pfVar7[4] = 0.0f;
                                    pfVar7[5] = 0.0f;
                                    local_4 = 0.0f;
                                    pfVar7[6] = 0.0f;
                                }
                                else {
                                    local_4 = pfVar7[7];
                                    pfVar7[4] = sample_height(s, iVar1 + iVar4 + static_cast<int32_t>(uVar6b));
                                    pfVar7[5] = pfVar7[5];
                                    pfVar7[6] = pfVar7[6];
                                }
                                pfVar7[7] = local_4;

                                iVar5 = *reinterpret_cast<int32_t*>(s + 0xb8) * (local_34 + -1);
                                iVar5b = iVar1 + iVar5 + static_cast<int32_t>(uVar6b);
                                if ((iVar5b < 0) ||
                                    (*reinterpret_cast<int32_t*>(s + 0xbc) *
                                         *reinterpret_cast<int32_t*>(s + 0xb8) < iVar5b)) {
                                    pfVar7[0] = 0.0f;
                                    pfVar7[1] = 0.0f;
                                    pfVar7[2] = 0.0f;
                                    pfVar7[3] = 0.0f;
                                }
                                else {
                                    pfVar7[0] = sample_height(s, iVar1 + iVar5 + static_cast<int32_t>(uVar6b));
                                    pfVar7[1] = pfVar7[1];
                                    pfVar7[2] = pfVar7[2];
                                    pfVar7[3] = pfVar7[3];
                                }

                                iVar4 = *reinterpret_cast<int32_t*>(s + 0xb8) * local_34;
                                iVar5 = iVar4 + iVar1 + static_cast<int32_t>(uVar6b);
                                if ((iVar5 < 0) ||
                                    (*reinterpret_cast<int32_t*>(s + 0xbc) *
                                         *reinterpret_cast<int32_t*>(s + 0xb8) < iVar5)) {
                                    pfVar7[-4] = 0.0f;
                                    pfVar7[-3] = 0.0f;
                                    local_4 = 0.0f;
                                    pfVar7[-2] = 0.0f;
                                }
                                else {
                                    local_4 = pfVar7[-1];
                                    pfVar7[-4] = sample_height(s, iVar1 + iVar4 + static_cast<int32_t>(uVar6b));
                                    pfVar7[-3] = pfVar7[-3];
                                    pfVar7[-2] = pfVar7[-2];
                                }
                                pfVar7[-1] = local_4;

                                iVar4 = *reinterpret_cast<int32_t*>(s + 0xb8) * (local_34 + 1);
                                iVar5 = iVar4 + iVar1 + static_cast<int32_t>(uVar6b);
                                if ((iVar5 < 0) ||
                                    (*reinterpret_cast<int32_t*>(s + 0xbc) *
                                         *reinterpret_cast<int32_t*>(s + 0xb8) < iVar5)) {
                                    pfVar7[-8] = 0.0f;
                                    pfVar7[-7] = 0.0f;
                                    local_4 = 0.0f;
                                    pfVar7[-6] = 0.0f;
                                }
                                else {
                                    local_4 = pfVar7[-5];
                                    pfVar7[-8] = sample_height(s, iVar4 + iVar1 + static_cast<int32_t>(uVar6b));
                                    pfVar7[-7] = pfVar7[-7];
                                    pfVar7[-6] = pfVar7[-6];
                                }
                                pfVar7[-5] = local_4;

                                iVar4 = *reinterpret_cast<int32_t*>(s + 0xb8) * (local_34 + 2);
                                iVar5 = iVar4 + iVar1 + static_cast<int32_t>(uVar6b);
                                if ((iVar5 < 0) ||
                                    (*reinterpret_cast<int32_t*>(s + 0xbc) *
                                         *reinterpret_cast<int32_t*>(s + 0xb8) < iVar5)) {
                                    pfVar7[-0xc] = 0.0f;
                                    pfVar7[-0xb] = 0.0f;
                                    local_4 = 0.0f;
                                    pfVar7[-0xa] = 0.0f;
                                }
                                else {
                                    local_4 = pfVar7[-9];
                                    pfVar7[-0xc] = sample_height(s, iVar4 + iVar1 + static_cast<int32_t>(uVar6b));
                                    pfVar7[-0xb] = pfVar7[-0xb];
                                    pfVar7[-0xa] = pfVar7[-0xa];
                                }
                                pfVar7[-9] = local_4;

                                iVar4 = *reinterpret_cast<int32_t*>(s + 0xb8) * (local_34 + 3);
                                iVar5 = iVar4 + iVar1 + static_cast<int32_t>(uVar6b);
                                if ((iVar5 < 0) ||
                                    (*reinterpret_cast<int32_t*>(s + 0xbc) *
                                         *reinterpret_cast<int32_t*>(s + 0xb8) < iVar5)) {
                                    pfVar7[-0x10] = 0.0f;
                                    pfVar7[-0xf] = 0.0f;
                                    local_4 = 0.0f;
                                    pfVar7[-0xe] = 0.0f;
                                }
                                else {
                                    local_4 = pfVar7[-0xd];
                                    pfVar7[-0x10] = sample_height(s, iVar4 + iVar1 + static_cast<int32_t>(uVar6b));
                                    pfVar7[-0xf] = pfVar7[-0xf];
                                    pfVar7[-0xe] = pfVar7[-0xe];
                                }
                                pfVar7[-0xd] = local_4;

                                iVar4 = *reinterpret_cast<int32_t*>(s + 0xb8) * (local_34 + 4);
                                iVar5 = iVar4 + iVar1 + static_cast<int32_t>(uVar6b);
                                if ((iVar5 < 0) ||
                                    (*reinterpret_cast<int32_t*>(s + 0xbc) *
                                         *reinterpret_cast<int32_t*>(s + 0xb8) < iVar5)) {
                                    pfVar7[-0x14] = 0.0f;
                                    pfVar7[-0x13] = 0.0f;
                                    local_4 = 0.0f;
                                    pfVar7[-0x12] = 0.0f;
                                }
                                else {
                                    local_4 = pfVar7[-0x11];
                                    pfVar7[-0x14] = sample_height(s, iVar4 + iVar1 + static_cast<int32_t>(uVar6b));
                                    pfVar7[-0x13] = pfVar7[-0x13];
                                    pfVar7[-0x12] = pfVar7[-0x12];
                                }
                                pfVar7[-0x11] = local_4;

                                iVar4 = *reinterpret_cast<int32_t*>(s + 0xb8) * (local_34 + 5);
                                iVar5 = iVar4 + iVar1 + static_cast<int32_t>(uVar6b);
                                if ((iVar5 < 0) ||
                                    (*reinterpret_cast<int32_t*>(s + 0xbc) *
                                         *reinterpret_cast<int32_t*>(s + 0xb8) < iVar5)) {
                                    pfVar7[-0x18] = 0.0f;
                                    pfVar7[-0x17] = 0.0f;
                                    local_4 = 0.0f;
                                    pfVar7[-0x16] = 0.0f;
                                }
                                else {
                                    local_4 = pfVar7[-0x15];
                                    pfVar7[-0x18] = sample_height(s, iVar4 + iVar1 + static_cast<int32_t>(uVar6b));
                                    pfVar7[-0x17] = pfVar7[-0x17];
                                    pfVar7[-0x16] = pfVar7[-0x16];
                                }
                                uVar6b = uVar6b + 1;
                                pfVar7[-0x15] = local_4;
                                pfVar7 = pfVar7 + 0x20;
                            } while (uVar6b < 8);
                        }

                        int32_t iVar4b = reinterpret_cast<int32_t>(
                            (*reinterpret_cast<void***>(s + 0xb0))[local_28]);
                        iVar4b = *reinterpret_cast<int32_t*>(
                            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar4b)) + local_30 * 4);
                        float fVar3 = local_2c * DAT_008caca0 * DAT_008caca4;
                        fVar2 = *reinterpret_cast<float*>(s + 0x8c);
                        uint8_t* object = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar4b));
                        *reinterpret_cast<float*>(object + 0x5c) = local_24 * DAT_008cac9c * DAT_008caca4;
                        *reinterpret_cast<float*>(object + 0x60) = -fVar3;
                        *reinterpret_cast<float*>(object + 100) = fVar2 * 127.9f;
                        FUN_00533d10(0, 1);
                    }
                    local_30 = local_30 + 1;
                    local_34 = local_34 + 8;
                    local_2c = static_cast<float>(local_30);
                    if (local_30 < 0) {
                        local_2c = local_2c + 4.2949673e+09f;
                    }
                    uVar6 = *reinterpret_cast<uint32_t*>(s + 0xbc);
                    fVar2 = static_cast<float>(static_cast<int32_t>(uVar6));
                    if (static_cast<int32_t>(uVar6) < 0) {
                        fVar2 = fVar2 + 4.2949673e+09f;
                    }
                } while (local_2c < fVar2 * 0.125f + static_cast<float>((uVar6 & 7) != 0));
            }
            local_28 = local_28 + 1;
            local_24 = static_cast<float>(local_28);
            if (local_28 < 0) {
                local_24 = local_24 + 4.2949673e+09f;
            }
            uVar6 = *reinterpret_cast<uint32_t*>(s + 0xb8);
            fVar2 = static_cast<float>(static_cast<int32_t>(uVar6));
            if (static_cast<int32_t>(uVar6) < 0) {
                fVar2 = fVar2 + 4.2949673e+09f;
            }
        } while (local_24 < fVar2 * 0.125f + static_cast<float>((uVar6 & 7) != 0));
    }
}

// 0x4ebe80 — observed shape
// Allocates the count-prefixed canopy object table and loads every entry from
// the formatted name. Returns 0 if any entry fails to load.
int32_t FUN_004ebe80(char* param_1, uint32_t param_2)
{
    uint32_t* puVar3 = static_cast<uint32_t*>(thunk_FUN_00533c78(param_2 * 4 + 4));
    if (puVar3 == nullptr) {
        DAT_008cacb0 = nullptr;
    }
    else {
        *puVar3 = param_2;
        DAT_008cacb0 = puVar3 + 1;
        if (-1 < static_cast<int32_t>(param_2 - 1)) {
            uint32_t* puVar3b = DAT_008cacb0;
            for (uint32_t uVar5 = param_2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar3b = 0;
                puVar3b = puVar3b + 1;
            }
        }
    }

    uint32_t uVar5 = 0;
    DAT_008cacb4 = param_2;
    if (param_2 != 0) {
        char local_100[256];
        do {
            sprintf(local_100, param_1, uVar5);
            void** puVar4 = static_cast<void**>(FUN_00500850());
            void** puVar2 = reinterpret_cast<void**>(
                static_cast<uintptr_t>(DAT_008cacb0[uVar5]));
            uint32_t* puVar3c = DAT_008cacb0 + uVar5;
            if (puVar2 != puVar4) {
                object_release(puVar2);
                *puVar3c = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar4));
                object_addref(puVar4);
            }
            if (DAT_008cacb0[uVar5] == 0) {
                if (PTR_FUN_00717a84 != nullptr) {
                    PTR_FUN_00717a84(local_100, "File not found", 0);
                }
                return 0;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < param_2);
    }
    return 1;
}

// 0x4ebf70 — observed shape
// Releases the first 32 canopy table entries, then frees the whole table.
int32_t FUN_004ebf70(void)
{
    int32_t iVar6 = 0;
    int32_t iVar4 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(DAT_008cacb0));
    do {
        void** puVar3 = *reinterpret_cast<void***>(static_cast<uintptr_t>(iVar6 + iVar4));
        void** puVar2 = reinterpret_cast<void**>(static_cast<uintptr_t>(iVar6 + iVar4));
        if (puVar3 != nullptr) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                typedef void (__thiscall* DtorFn)(void*, int32_t);
                (*reinterpret_cast<DtorFn*>(*reinterpret_cast<void**>(puVar3)))(puVar3, 1);
                iVar4 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(DAT_008cacb0));
            }
            *puVar2 = nullptr;
        }
        iVar6 = iVar6 + 4;
    } while (iVar6 < 0x80);

    if (iVar4 != 0) {
        int32_t iVar5 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar4 - 4));
        iVar6 = iVar4 + iVar5 * 4;
        if (-1 < iVar5 - 1) {
            do {
                void** puVar2 = *reinterpret_cast<void***>(static_cast<uintptr_t>(iVar6 - 4));
                iVar6 = iVar6 + -4;
                object_release(puVar2);
                iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
        }
        operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar4 - 4)));
        DAT_008cacb0 = nullptr;
    }
    return 0;
}

// 0x4ec000 — observed shape
// Synchronises every landscape object slot with the object it currently
// exposes through its +0x2c handle.
void FUN_004ec000(void)
{
    FUN_004e6420();
    uint32_t uVar4 = 0;
    do {
        void* puVar3;
        bool bVar5;
        int32_t iVar2;

        if (DAT_008ea110[uVar4] == 0) {
            puVar3 = nullptr;
            bVar5 = true;
        }
        else {
            int32_t** slot = reinterpret_cast<int32_t**>(
                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(DAT_008ea110[uVar4])) + 0x2c);
            iVar2 = **slot;
            if (iVar2 == 0) {
                puVar3 = nullptr;
            }
            else {
                puVar3 = *reinterpret_cast<void**>(
                    reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar2)) + 4);
            }
            bVar5 = puVar3 == nullptr;
            if (!bVar5) {
                object_addref(puVar3);
            }
        }

        // LAB_004ec038
        bVar5 = puVar3 == nullptr;
        object_release(puVar3);

        if (!bVar5) {
            if (DAT_008ea110[uVar4] == 0) {
                iVar2 = 0;
            }
            else {
                int32_t** slot = reinterpret_cast<int32_t**>(
                    reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(DAT_008ea110[uVar4])) + 0x2c);
                iVar2 = **slot;
                if (iVar2 == 0) {
                    iVar2 = 0;
                }
                else {
                    iVar2 = *reinterpret_cast<int32_t*>(
                        reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar2)) + 4);
                }
                if (iVar2 != 0) {
                    int32_t* ref = reinterpret_cast<int32_t*>(
                        reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar2)) + 4);
                    *ref = *ref + 1;
                }
            }
            FUN_004ed7b0(uVar4, iVar2);
        }

        uVar4 = uVar4 + 1;
        if (0xff < uVar4) {
            return;
        }
    } while (true);
}

// 0x4ec0a0 — observed shape
// Drains the pending object list held at +0x11c, one entry per frame service
// call, then flushes the renderer.
void FUN_004ec0a0(void* param_1)
{
    uint8_t* const p = static_cast<uint8_t*>(param_1);
    uint32_t uVar1 = 0;
    int32_t local_4;

    if (*reinterpret_cast<uint32_t*>(p + 0x118) != 0) {
        int32_t* piVar2 = *reinterpret_cast<int32_t**>(p + 0x11c);
        do {
            if (*piVar2 != 0) {
                local_4 = (*reinterpret_cast<int32_t**>(p + 0x11c))[uVar1];
                goto LAB_004ec0d0;
            }
            uVar1 = uVar1 + 1;
            piVar2 = piVar2 + 1;
        } while (uVar1 < *reinterpret_cast<uint32_t*>(p + 0x118));
    }
    local_4 = 0;

LAB_004ec0d0:
    if (local_4 != 0) {
        do {
            FUN_004ed860(&local_4);
            FUN_005120c0(0);
        } while (local_4 != 0);
    }
    FUN_00511f10();
}

// 0x4ec1c0 — observed shape
// Toggles the texture present in three object slots according to the camera
// distance thresholds at +0xc of the world manager. The enabled flag arrives
// in CL and the texture argument in EDI.
void FUN_004ec1c0(void* self, char enabled, int32_t arg)
{
    uint8_t* const s = static_cast<uint8_t*>(self);

    if ((*reinterpret_cast<int32_t*>(s + 0xe8) != 0) && (enabled != '\0') &&
        (1 < *reinterpret_cast<int32_t*>(DAT_0072cd78 + 0xc)) &&
        (*reinterpret_cast<int32_t*>(s + 0xc4) != 0)) {
        uint8_t* pbVar1 = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(s + 0xe8)) + 0x20);
        *pbVar1 = static_cast<uint8_t>(*pbVar1 & 0xfe);
        FUN_00533e70(arg);
        uint16_t* puVar2 = reinterpret_cast<uint16_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(s + 0xe8)) + 0x20);
        *puVar2 = static_cast<uint16_t>(*puVar2 | 1);
    }
    if ((*reinterpret_cast<int32_t*>(s + 0xf4) != 0) &&
        (3 < *reinterpret_cast<int32_t*>(DAT_0072cd78 + 0xc))) {
        uint8_t* pbVar1 = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(s + 0xf4)) + 0x20);
        *pbVar1 = static_cast<uint8_t>(*pbVar1 & 0xfe);
        FUN_00533e70(arg);
        uint16_t* puVar2 = reinterpret_cast<uint16_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(s + 0xf4)) + 0x20);
        *puVar2 = static_cast<uint16_t>(*puVar2 | 1);
    }
    if ((*reinterpret_cast<int32_t*>(s + 0xec) != 0) &&
        (0 < *reinterpret_cast<int32_t*>(DAT_0072cd78 + 0xc))) {
        uint8_t* pbVar1 = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(s + 0xec)) + 0x20);
        *pbVar1 = static_cast<uint8_t>(*pbVar1 & 0xfe);
        FUN_00533e70(arg);
        uint16_t* puVar2 = reinterpret_cast<uint16_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(s + 0xec)) + 0x20);
        *puVar2 = static_cast<uint16_t>(*puVar2 | 1);
    }
}

// 0x4ec270 — observed shape
// Stamps the canopy height levels of every patch that intersects the visible
// world rectangle.
void FUN_004ec270(void* self)
{
    uint8_t* const s = static_cast<uint8_t*>(self);

    if ((*reinterpret_cast<int32_t*>(s + 0x54) == 0) ||
        (*reinterpret_cast<char*>(s + 0xa0) == '\0')) {
        return;
    }
    int32_t* piVar12 = *reinterpret_cast<int32_t**>(DAT_0072cd78 + 0xb0);
    if (piVar12 == nullptr) {
        return;
    }

    while (true) {
        int32_t* piVar2 = *reinterpret_cast<int32_t**>(piVar12);
        float fVar9 = static_cast<float>(*reinterpret_cast<int32_t*>(s + 0x6c));
        float* pfVar3 = reinterpret_cast<float*>(static_cast<uintptr_t>(piVar12[2]));
        float fVar4 = *reinterpret_cast<float*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<int32_t*>(s + 4))) + 0x94);
        float fVar5 = *reinterpret_cast<float*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<int32_t*>(s + 4))) + 0x90);

        if (*reinterpret_cast<int32_t*>(s + 0x6c) < 0) {
            fVar9 = fVar9 + 4.2949673e+09f;
        }
        fVar9 = (fVar9 - 1.0f) * *reinterpret_cast<float*>(s + 0x84) + fVar5;

        float fVar10 = static_cast<float>(*reinterpret_cast<int32_t*>(s + 0x70));
        if (*reinterpret_cast<int32_t*>(s + 0x70) < 0) {
            fVar10 = fVar10 + 4.2949673e+09f;
        }
        float fVar6 = pfVar3[1];
        float fVar7 = pfVar3[0];
        float fVar1 = *reinterpret_cast<float*>(s + 0x88);
        if (pfVar3[2] < 0.0f) {
            FUN_00512f70(0);
        }

        if (((fVar4 - (fVar10 - 1.0f) * fVar1 <= fVar6) &&
             (!std::isnan(fVar6) && !std::isnan(fVar4)) &&
             ((fVar6 < fVar4) != (fVar6 == fVar4))) &&
            ((fVar5 <= fVar7) &&
             ((!std::isnan(fVar7) && !std::isnan(fVar9)) &&
              ((fVar7 < fVar9) != (fVar7 == fVar9))))) {
            double local_24;
            double local_1c;
            double local_14;
            double local_c;
            uint32_t local_40;
            int32_t local_60;
            int32_t local_5c;
            int32_t local_58;
            int32_t local_54;

            double dVar18 = modf(((fVar7 - fVar5) - pfVar3[3] * 1.41) /
                                     *reinterpret_cast<float*>(s + 0x84),
                                 &local_24);
            if (0.0 <= dVar18) {
                local_40 = static_cast<uint32_t>(0.5 < dVar18);
                local_24 = static_cast<double>(local_40) + local_24;
            }
            else {
                local_40 = static_cast<uint32_t>(dVar18 < -0.5);
                local_24 = local_24 - static_cast<double>(local_40);
            }
            local_60 = static_cast<int32_t>(FUN_005f0ddc());

            dVar18 = modf(((fVar4 - fVar6) - pfVar3[3] * 1.41) /
                              *reinterpret_cast<float*>(s + 0x88),
                          &local_1c);
            if (0.0 <= dVar18) {
                local_40 = static_cast<uint32_t>(0.5 < dVar18);
                local_1c = static_cast<double>(local_40) + local_1c;
            }
            else {
                local_40 = static_cast<uint32_t>(dVar18 < -0.5);
                local_1c = local_1c - static_cast<double>(local_40);
            }
            local_5c = static_cast<int32_t>(FUN_005f0ddc());

            dVar18 = modf((pfVar3[3] * 2.82) / *reinterpret_cast<float*>(s + 0x84),
                          &local_14);
            if (0.0 <= dVar18) {
                local_40 = static_cast<uint32_t>(0.5 < dVar18);
                local_14 = static_cast<double>(local_40) + local_14;
            }
            else {
                local_40 = static_cast<uint32_t>(dVar18 < -0.5);
                local_14 = local_14 - static_cast<double>(local_40);
            }
            local_58 = static_cast<int32_t>(FUN_005f0ddc());

            dVar18 = modf((pfVar3[3] * 2.82) / *reinterpret_cast<float*>(s + 0x88),
                          &local_c);
            if (0.0 <= dVar18) {
                local_40 = static_cast<uint32_t>(0.5 < dVar18);
                local_c = static_cast<double>(local_40) + local_c;
            }
            else {
                local_40 = static_cast<uint32_t>(dVar18 < -0.5);
                local_c = local_c - static_cast<double>(local_40);
            }
            local_54 = static_cast<int32_t>(FUN_005f0ddc());

            if (local_60 < 0) {
                local_60 = 0;
            }
            else if (*reinterpret_cast<int32_t*>(s + 0x6c) < local_60) {
                local_60 = *reinterpret_cast<int32_t*>(s + 0x6c);
            }
            if (local_5c < 0) {
                local_5c = 0;
            }
            else if (*reinterpret_cast<int32_t*>(s + 0x70) < local_5c) {
                local_5c = *reinterpret_cast<int32_t*>(s + 0x70);
            }
            if (local_58 < 0) {
                local_58 = 0;
            }
            else {
                int32_t iVar13 = (*reinterpret_cast<int32_t*>(s + 0x6c) - local_60) + -1;
                if (iVar13 < local_58) {
                    local_58 = iVar13;
                }
            }
            if (local_54 < 0) {
                local_54 = 0;
            }
            else {
                int32_t iVar13 = (*reinterpret_cast<int32_t*>(s + 0x70) - local_5c) + -1;
                if (iVar13 < local_54) {
                    local_54 = iVar13;
                }
            }

            if (local_60 < local_58 + local_60) {
                int32_t iVar13 = local_5c;
                int32_t iVar17 = local_60;
                do {
                    for (; iVar13 < local_54 + local_5c; iVar13 = iVar13 + 1) {
                        int32_t plane = *reinterpret_cast<int32_t*>(s + 0x54);
                        int32_t width = *reinterpret_cast<int32_t*>(s + 0x6c);
                        int32_t cell = width * iVar13 + iVar17;
                        uint8_t* heightPlane = reinterpret_cast<uint8_t*>(
                            static_cast<uintptr_t>(plane));
                        if (*reinterpret_cast<float*>(DAT_0072cd78 + 0x44) <
                            static_cast<float>(heightPlane[cell])) {
                            int32_t iVar16 = (iVar13 - local_54 / 2) - local_5c;
                            int32_t iVar15 = (iVar17 - local_58 / 2) - local_60;
                            if (iVar15 < 0) {
                                iVar15 = -iVar15;
                            }
                            if (iVar16 < 0) {
                                iVar16 = -iVar16;
                            }
                            if (iVar16 < iVar15) {
                                iVar16 = iVar16 + iVar15 * 2;
                            }
                            else {
                                iVar16 = iVar15 + iVar16 * 2;
                            }
                            fVar4 = static_cast<float>(iVar16 / 2) *
                                    *reinterpret_cast<float*>(s + 0x84);
                            if (fVar4 <= pfVar3[3] + pfVar3[3]) {
                                uint8_t uVar11 = static_cast<uint8_t>(FUN_005f0ddc());
                                if (pfVar3[3] <= fVar4) {
                                    int32_t width2 = *reinterpret_cast<int32_t*>(s + 0x6c);
                                    uVar11 = static_cast<uint8_t>(FUN_005f0ddc());
                                    heightPlane[width2 * iVar13 + iVar17] = uVar11;
                                }
                                else {
                                    heightPlane[cell] = uVar11;
                                }
                            }
                        }
                    }
                    iVar17 = iVar17 + 1;
                    iVar13 = local_5c;
                } while (iVar17 < local_58 + local_60);
            }
        }

        if (piVar2 == nullptr) {
            break;
        }
        piVar12 = piVar2;
    }
}

// 0x4ec790 — observed shape
// Caches a rectangular canopy patch into a height/colour buffer and restamps
// the underlying terrain for the patches crossed by the camera.
void FUN_004ec790(void* self)
{
    uint8_t* const s = static_cast<uint8_t*>(self);

    if ((*reinterpret_cast<int32_t*>(s + 0x54) == 0) ||
        (*reinterpret_cast<char*>(s + 0xa0) == '\0')) {
        return;
    }
    int32_t* piVar10 = *reinterpret_cast<int32_t**>(DAT_0072cd78 + 0xc0);
    if (piVar10 == nullptr) {
        return;
    }

    while (true) {
        int32_t* piVar2 = *reinterpret_cast<int32_t**>(piVar10);
        PatchRecord* pfVar3 = reinterpret_cast<PatchRecord*>(
            static_cast<uintptr_t>(piVar10[2]));
        float fVar7 = static_cast<float>(*reinterpret_cast<int32_t*>(s + 0x6c));
        float fVar11 = *reinterpret_cast<float*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<int32_t*>(s + 4))) + 0x94);
        float fVar4 = *reinterpret_cast<float*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<int32_t*>(s + 4))) + 0x90);

        if (*reinterpret_cast<int32_t*>(s + 0x6c) < 0) {
            fVar7 = fVar7 + 4.2949673e+09f;
        }
        fVar7 = (fVar7 - 1.0f) * *reinterpret_cast<float*>(s + 0x84) + fVar4;

        float fVar8 = static_cast<float>(*reinterpret_cast<int32_t*>(s + 0x70));
        if (*reinterpret_cast<int32_t*>(s + 0x70) < 0) {
            fVar8 = fVar8 + 4.2949673e+09f;
        }
        float fVar5 = pfVar3->y;
        float fVar6 = pfVar3->x;
        float fVar1 = *reinterpret_cast<float*>(s + 0x88);
        if (pfVar3->z < 0.0f) {
            FUN_00512f70(0);
        }

        if (((fVar11 - (fVar8 - 1.0f) * fVar1 <= fVar5) &&
             (!std::isnan(fVar5) && !std::isnan(fVar11)) &&
             ((fVar5 < fVar11) != (fVar5 == fVar11))) &&
            ((fVar4 <= fVar6) &&
             ((!std::isnan(fVar6) && !std::isnan(fVar7)) &&
              ((fVar6 < fVar7) != (fVar6 == fVar7)) && (pfVar3->flag == 0)))) {
            double local_24;
            double local_1c;
            double local_14;
            double local_c;
            uint32_t local_48;
            int32_t local_74;
            int32_t local_70;
            int32_t local_6c;
            int32_t local_68;

            double dVar16 = modf(((fVar6 - fVar4) - pfVar3->radius * 1.41) /
                                     *reinterpret_cast<float*>(s + 0x84),
                                 &local_24);
            if (0.0 <= dVar16) {
                local_48 = static_cast<uint32_t>(0.5 < dVar16);
                local_24 = static_cast<double>(local_48) + local_24;
            }
            else if (-0.5 <= dVar16) {
                local_24 = local_24 - 0.0;
            }
            else {
                local_24 = local_24 - 1.0;
            }
            local_6c = static_cast<int32_t>(FUN_005f0ddc());

            dVar16 = modf(((fVar11 - fVar5) - pfVar3->radius * 1.41) /
                              *reinterpret_cast<float*>(s + 0x88),
                          &local_1c);
            if (0.0 <= dVar16) {
                local_48 = static_cast<uint32_t>(0.5 < dVar16);
                local_1c = static_cast<double>(local_48) + local_1c;
            }
            else {
                local_48 = static_cast<uint32_t>(dVar16 < -0.5);
                local_1c = local_1c - static_cast<double>(local_48);
            }
            local_70 = static_cast<int32_t>(FUN_005f0ddc());

            dVar16 = modf((pfVar3->radius * 2.82) / *reinterpret_cast<float*>(s + 0x84),
                          &local_14);
            if (0.0 <= dVar16) {
                local_48 = static_cast<uint32_t>(0.5 < dVar16);
                local_14 = static_cast<double>(local_48) + local_14;
            }
            else {
                local_48 = static_cast<uint32_t>(dVar16 < -0.5);
                local_14 = local_14 - static_cast<double>(local_48);
            }
            local_74 = static_cast<int32_t>(FUN_005f0ddc());

            dVar16 = modf((pfVar3->radius * 2.82) / *reinterpret_cast<float*>(s + 0x88),
                          &local_c);
            if (0.0 <= dVar16) {
                local_48 = static_cast<uint32_t>(0.5 < dVar16);
                local_c = static_cast<double>(local_48) + local_c;
            }
            else {
                local_48 = static_cast<uint32_t>(dVar16 < -0.5);
                local_c = local_c - static_cast<double>(local_48);
            }
            local_68 = static_cast<int32_t>(FUN_005f0ddc());

            if (local_6c < 1) {
                local_6c = 1;
            }
            else if (*reinterpret_cast<int32_t*>(s + 0x6c) < local_6c) {
                local_6c = *reinterpret_cast<int32_t*>(s + 0x6c);
            }
            if (local_70 < 1) {
                local_70 = 1;
            }
            else if (*reinterpret_cast<int32_t*>(s + 0x70) < local_70) {
                local_70 = *reinterpret_cast<int32_t*>(s + 0x70);
            }
            if (local_74 < 0) {
                local_74 = 0;
            }
            else {
                int32_t iVar14 = (*reinterpret_cast<int32_t*>(s + 0x6c) - local_6c) + -2;
                if (iVar14 < local_74) {
                    local_74 = iVar14;
                }
            }
            if (local_68 < 0) {
                local_68 = 0;
            }
            else {
                int32_t iVar14 = (*reinterpret_cast<int32_t*>(s + 0x70) - local_70) + -2;
                if (iVar14 < local_68) {
                    local_68 = iVar14;
                }
            }

            if ((local_74 != 0) && (local_68 != 0)) {
                pfVar3->spanW = static_cast<int16_t>(local_74);
                pfVar3->flag = 1;
                pfVar3->tileX = static_cast<int16_t>(local_6c);
                pfVar3->tileY = static_cast<int16_t>(local_70);
                pfVar3->spanH = static_cast<int16_t>(local_68);
                pfVar3->heights = static_cast<uint8_t*>(
                    thunk_FUN_00533c78(static_cast<uint32_t>(local_68) *
                                       static_cast<uint32_t>(local_74)));
                pfVar3->colors = static_cast<uint8_t*>(
                    thunk_FUN_00533c78(static_cast<uint32_t>(local_68) *
                                       static_cast<uint32_t>(local_74) * 3u));

                if (local_6c < local_74 + local_6c) {
                    uint32_t local_48b = 0;
                    int32_t iVar14 = local_6c;
                    do {
                        if (local_70 < local_68 + local_70) {
                            int32_t local_4c = 0;
                            int32_t local_64 = static_cast<int32_t>(local_48b);
                            int32_t iVar15 = local_70;
                            do {
                                int32_t width = *reinterpret_cast<int32_t*>(s + 0x6c);
                                int32_t cell = width * iVar15 + iVar14;
                                uint8_t* heightPlane = reinterpret_cast<uint8_t*>(
                                    static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(s + 0x54)));
                                uint8_t* colorPlane = reinterpret_cast<uint8_t*>(
                                    static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(s + 0x5c)));

                                pfVar3->heights[(local_4c - local_6c) + iVar14] =
                                    heightPlane[cell];
                                pfVar3->colors[local_64] = colorPlane[cell * 3];
                                pfVar3->colors[local_64 + 1] = colorPlane[cell * 3 + 1];
                                pfVar3->colors[local_64 + 2] = colorPlane[cell * 3 + 2];

                                if (*reinterpret_cast<float*>(DAT_0072cd78 + 0x44) <
                                    static_cast<float>(heightPlane[cell])) {
                                    int32_t iVar13 = (iVar15 - local_68 / 2) - local_70;
                                    int32_t iVar12 = (iVar14 - local_74 / 2) - local_6c;
                                    if (iVar12 < 0) {
                                        iVar12 = -iVar12;
                                    }
                                    if (iVar13 < 0) {
                                        iVar13 = -iVar13;
                                    }
                                    if (iVar13 < iVar12) {
                                        iVar13 = iVar13 + iVar12 * 2;
                                    }
                                    else {
                                        iVar13 = iVar12 + iVar13 * 2;
                                    }
                                    float fVar11b = static_cast<float>(iVar13 / 2) *
                                                    *reinterpret_cast<float*>(s + 0x84);
                                    if (fVar11b <= pfVar3->radius + pfVar3->radius) {
                                        uint8_t uVar9 = static_cast<uint8_t>(FUN_005f0ddc());
                                        if (pfVar3->radius <= fVar11b) {
                                            uVar9 = static_cast<uint8_t>(FUN_005f0ddc());
                                            heightPlane[cell] = uVar9;
                                        }
                                        else {
                                            heightPlane[cell] = uVar9;
                                        }
                                        colorPlane[cell * 3] = 0x80;
                                        colorPlane[cell * 3 + 1] = 0x80;
                                        colorPlane[cell * 3 + 2] = 0xff;
                                    }
                                }
                                local_64 = local_64 + local_74 * 3;
                                local_4c = local_4c + local_74;
                                iVar15 = iVar15 + 1;
                            } while (iVar15 < local_68 + local_70);
                        }
                        iVar14 = iVar14 + 1;
                        local_48b = local_48b + 3;
                    } while (iVar14 < local_74 + local_6c);
                }
            }
        }

        if (piVar2 == nullptr) {
            break;
        }
        piVar10 = piVar2;
    }
}

// 0x4ece40 — observed shape
// Restores every cached canopy patch that intersects the visible rectangle
// back into the terrain planes and frees its cached buffers.
void FUN_004ece40(void* self)
{
    uint8_t* const s = static_cast<uint8_t*>(self);

    if ((*reinterpret_cast<int32_t*>(s + 0x54) == 0) ||
        (*reinterpret_cast<char*>(s + 0xa0) == '\0')) {
        return;
    }
    int32_t iVar6 = *reinterpret_cast<int32_t*>(DAT_0072cd78 + 0xc4);
    if (iVar6 == 0) {
        return;
    }

    do {
        PatchRecord* pfVar3 = reinterpret_cast<PatchRecord*>(
            static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(
                static_cast<uintptr_t>(iVar6 + 8))));
        iVar6 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar6 + 4));

        if (pfVar3->flag != '\0') {
            float fVar1 = *reinterpret_cast<float*>(
                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                    *reinterpret_cast<int32_t*>(s + 4))) + 0x94);
            float fVar4 = *reinterpret_cast<float*>(
                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                    *reinterpret_cast<int32_t*>(s + 4))) + 0x90);
            float fVar2 = pfVar3->y;
            uint32_t uVar8 = *reinterpret_cast<uint32_t*>(s + 0x70);
            float fVar5 = static_cast<float>(*reinterpret_cast<int32_t*>(s + 0x70));
            if (static_cast<int32_t>(uVar8) < 0) {
                fVar5 = fVar5 + 4.2949673e+09f;
            }

            if (((fVar1 - (fVar5 - 1.0f) * *reinterpret_cast<float*>(s + 0x88) <= fVar2) &&
                 (!std::isnan(fVar2) && !std::isnan(fVar1)) &&
                 ((fVar2 < fVar1) != (fVar2 == fVar1))) &&
                (fVar4 <= pfVar3->x)) {
                uint32_t uVar7 = *reinterpret_cast<uint32_t*>(s + 0x6c);
                float fVar1b = static_cast<float>(*reinterpret_cast<int32_t*>(s + 0x6c));
                if (static_cast<int32_t>(uVar7) < 0) {
                    fVar1b = fVar1b + 4.2949673e+09f;
                }
                if (pfVar3->x <= (fVar1b - 1.0f) * *reinterpret_cast<float*>(s + 0x84) + fVar4) {
                    uint32_t local_30 = pfVar3->tileY;
                    uint32_t local_28 = pfVar3->tileX;
                    uint32_t uVar9 = pfVar3->spanH;
                    uint32_t local_24 = pfVar3->spanW;

                    if (static_cast<int32_t>(uVar7) < static_cast<int32_t>(local_28)) {
                        local_28 = uVar7;
                    }
                    if (static_cast<int32_t>(local_30) < 0) {
                        local_30 = 0;
                    }
                    else if (static_cast<int32_t>(uVar8) < static_cast<int32_t>(local_30)) {
                        local_30 = uVar8;
                    }
                    uVar7 = (uVar7 - local_28) - 1;
                    if (static_cast<int32_t>(uVar7) < static_cast<int32_t>(local_24)) {
                        local_24 = uVar7;
                    }
                    if (static_cast<int32_t>(uVar9) < 0) {
                        uVar9 = 0;
                    }
                    else {
                        uVar8 = (uVar8 - local_30) - 1;
                        if (static_cast<int32_t>(uVar8) < static_cast<int32_t>(uVar9)) {
                            uVar9 = uVar8;
                        }
                    }

                    if ((local_24 != 0) && (uVar9 != 0)) {
                        pfVar3->flag = 0;
                        if (static_cast<int32_t>(local_28) <
                            static_cast<int32_t>(local_24 + local_28)) {
                            int32_t local_1c = 0;
                            uint32_t uVar8b = local_28;
                            do {
                                if (static_cast<int32_t>(local_30) <
                                    static_cast<int32_t>(uVar9 + local_30)) {
                                    int32_t local_20 = 0;
                                    uint32_t uVar7b = local_30;
                                    int32_t iVar10 = local_1c;
                                    do {
                                        int32_t width = *reinterpret_cast<int32_t*>(s + 0x6c);
                                        int32_t cell = width * uVar7b + uVar8b;
                                        uint8_t* heightPlane = reinterpret_cast<uint8_t*>(
                                            static_cast<uintptr_t>(
                                                *reinterpret_cast<int32_t*>(s + 0x54)));
                                        uint8_t* colorPlane = reinterpret_cast<uint8_t*>(
                                            static_cast<uintptr_t>(
                                                *reinterpret_cast<int32_t*>(s + 0x5c)));

                                        heightPlane[cell] =
                                            pfVar3->heights[(local_20 - local_28) + uVar8b];
                                        colorPlane[cell * 3] = pfVar3->colors[iVar10];
                                        colorPlane[cell * 3 + 1] = pfVar3->colors[iVar10 + 1];
                                        colorPlane[cell * 3 + 2] = pfVar3->colors[iVar10 + 2];

                                        iVar10 = iVar10 + static_cast<int32_t>(local_24) * 3;
                                        local_20 = local_20 + static_cast<int32_t>(local_24);
                                        uVar7b = uVar7b + 1;
                                    } while (static_cast<int32_t>(uVar7b) <
                                             static_cast<int32_t>(uVar9 + local_30));
                                }
                                uVar8b = uVar8b + 1;
                                local_1c = local_1c + 3;
                            } while (static_cast<int32_t>(uVar8b) <
                                     static_cast<int32_t>(local_24 + local_28));
                        }
                        if (pfVar3->heights != nullptr) {
                            operator_delete__(pfVar3->heights);
                            pfVar3->heights = nullptr;
                        }
                        if (pfVar3->colors != nullptr) {
                            operator_delete__(pfVar3->colors);
                            pfVar3->colors = nullptr;
                        }
                    }
                }
            }
        }
    } while (iVar6 != 0);
}

// 0x4ed110 — observed shape
// Deleting destructor: tears down the base and optionally frees the object.
void FUN_004ed110(void* self, uint8_t param_1)
{
    // The destructor chain is entered with the receiver still in ECX; Ghidra
    // prints no arguments for the call.
    FUN_00547d10();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4ed130 — observed shape
// Uploads the eight f4CanopyXY shader constants per row.
void FUN_004ed130(void* self)
{
    int32_t in_EAX = static_cast<int32_t>(reinterpret_cast<uintptr_t>(self));
    uint32_t uVar1 = 0;
    int32_t local_104;
    char local_100[256];

    do {
        local_104 = in_EAX + 0x10;
        uint32_t uVar2 = 0;
        int32_t iVar3 = local_104;
        do {
            sprintf(local_100, "f4Canopy%d%d", uVar1, uVar2);
            FUN_005be280(local_100, 0x10, reinterpret_cast<void*>(static_cast<uintptr_t>(iVar3)));
            uVar2 = uVar2 + 1;
            iVar3 = iVar3 + 0x80;
        } while (uVar2 < 8);
        uVar1 = uVar1 + 1;
        in_EAX = local_104;
    } while (uVar1 < 8);
}

// 0x4ed1a0 — observed shape
// Re-uploads the landscape shader blocks of every object that reports a live
// landscape shader at +0xc4. The texture argument arrives in EBX.
void FUN_004ed1a0(int32_t* param_1, int32_t arg)
{
    if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(param_1) + 0x7e) == '\0') {
        return;
    }

    int32_t iVar1 = *param_1;
    uint32_t uVar2 = 0;
    if (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar1) + 0xc0) != 0) {
        if (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar1) + 0xc0) == 0) {
            goto LAB_004ed222;
        }
        do {
            int32_t rowBase = *reinterpret_cast<int32_t*>(
                static_cast<uintptr_t>(iVar1) + 0xb8);
            iVar1 = *reinterpret_cast<int32_t*>(
                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(rowBase)) + uVar2 * 4);
            if ((iVar1 != 0) &&
                (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar1) + 0xc4) != 0)) {
                iVar1 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(
                    FUN_00540540("LM_SHADER")));
                FUN_005be280(
                    "f4LandscapeParams", 0x10,
                    reinterpret_cast<void*>(static_cast<uintptr_t>(
                        *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar1) + 0x14))));
                iVar1 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(
                    FUN_00540540("LM_SHADER2")));
                FUN_005be280(
                    "f4LandscapeValues", 0x10,
                    reinterpret_cast<void*>(static_cast<uintptr_t>(
                        *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar1) + 0x14))));
                FUN_00533e70(arg);
            }
        LAB_004ed222:
            iVar1 = *param_1;
            uVar2 = uVar2 + 1;
        } while (uVar2 < *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar1) + 0xc0));
    }
}

// 0x4ed240 — observed shape
// Re-runs the per-canopy visibility update for every canopy slot.
void FUN_004ed240(void* self)
{
    uint8_t* const s = static_cast<uint8_t*>(self);
    int32_t iVar1 = 0;

    if (0 < *reinterpret_cast<int32_t*>(s + 0x58)) {
        do {
            // NEEDS_MANUAL: 0x4ec1c0 reads the enabled flag from CL and the
            // texture argument from EDI; this call site leaves both live in
            // registers and the listing does not recover their values.
            reinterpret_cast<void (*)()>(&FUN_004ec1c0)();
            iVar1 = iVar1 + 1;
        } while (iVar1 < *reinterpret_cast<int32_t*>(s + 0x58));
    }
}

// 0x4ed270 — observed shape
// Tests whether every character of param_3 is present in the current keyboard
// state (five bytes at local_100), honouring the empty-string acceptance flag.
uint32_t FUN_004ed270(uint32_t param_1, uint32_t param_2, char* param_3, char param_4)
{
    struct KeyState {
        uint8_t  prefix[4];   // -0x110
        uint32_t a;           // -0x10c
        uint32_t b;           // -0x108
        uint32_t c;           // -0x104
        uint32_t text;        // -0x100
        uint8_t  tail;        // -0x0fc
        uint8_t  scanPad;     // the scan reads one byte past tail
    } local;

    local.a = param_1;
    local.b = param_2;
    local.c = 0;

    uint32_t uVar3 = FUN_00513540(&local.prefix);
    if (static_cast<char>(uVar3) == '\0') {
        return uVar3 & 0xffffff00u;
    }

    void* local_114 = nullptr;
    char cVar2 = FUN_0051bfc0(&local_114);
    if (cVar2 != '\0') {
        local.text = *static_cast<uint32_t*>(local_114);
        local.tail = reinterpret_cast<uint8_t*>(local_114)[4];
    }

    if (*param_3 != '\0') {
        do {
            cVar2 = static_cast<char>(local.text);
            char* bytes = reinterpret_cast<char*>(&local.text);
            for (int32_t iVar4 = 0; (cVar2 != '\0') && (iVar4 < 5); iVar4 = iVar4 + 1) {
                if (bytes[iVar4] == *param_3) {
                    return (static_cast<uint32_t>(iVar4) & 0xffffff00u) | 1u;
                }
                cVar2 = bytes[iVar4 + 1];
            }
            char* pcVar1 = param_3 + 1;
            param_3 = param_3 + 1;
            if (*pcVar1 == '\0') {
                break;
            }
        } while (true);
    }

    if ((param_4 == '\0') || (static_cast<char>(local.text) != '\0')) {
        return 0;
    }
    return 1;
}

// 0x4ed370 — observed shape
// Appends one parameter record to the patch list at +0xac (small record) or
// +0xbc (full record), depending on the flag left in AL.
void FUN_004ed370(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, char smallFlag)
{
    uint8_t* const s = static_cast<uint8_t*>(self);
    uint32_t* puVar1;
    int32_t* piVar3;

    if (smallFlag == '\0') {
        puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x24));
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar1[4] = 0;
        puVar1[5] = 0;
        puVar1[6] = 0;
        puVar1[7] = 0;
        puVar1[8] = 0;
        *puVar1 = param_1;
        puVar1[1] = param_2;
        puVar1[2] = param_3;
        puVar1[3] = param_4;
        piVar3 = reinterpret_cast<int32_t*>(s + 0xbc);
    }
    else {
        puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x10));
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        *puVar1 = param_1;
        puVar1[1] = param_2;
        puVar1[2] = param_3;
        puVar1[3] = param_4;
        piVar3 = reinterpret_cast<int32_t*>(s + 0xac);
    }

    uint32_t* puVar2 = static_cast<uint32_t*>(vcall_ret_ptr(
        reinterpret_cast<void*>(static_cast<uintptr_t>(piVar3[0])), 4));
    puVar2[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    puVar2[0] = 0;
    puVar2[1] = static_cast<uint32_t>(piVar3[2]);

    if (piVar3[2] == 0) {
        piVar3[1] = static_cast<int32_t>(reinterpret_cast<uintptr_t>(puVar2));
        piVar3[2] = static_cast<int32_t>(reinterpret_cast<uintptr_t>(puVar2));
        piVar3[3] = piVar3[3] + 1;
        return;
    }
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(piVar3[2])) =
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar2));
    piVar3[2] = static_cast<int32_t>(reinterpret_cast<uintptr_t>(puVar2));
    piVar3[3] = piVar3[3] + 1;
}
