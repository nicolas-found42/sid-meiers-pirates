// UNVERIFIED: no cl 13.10.3077 available. No PASS claim. Clean-room translation of the
// Ghidra 12.2 pseudocode corpus for batch mass_0059 (ocean/water scene helpers,
// 0x004e2970-0x004e4580, PE32 i386).
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern "C" double atan2(double y, double x);
extern "C" double sqrt(double x);
extern "C" float fabsf(float x);
extern "C" long double _CIfmod();

// ---- referenced helpers -----------------------------------------------------
extern uint32_t FUN_00533c78(uintptr_t size);
extern uint32_t thunk_FUN_00533c78(uintptr_t size);
extern uint32_t FUN_0053bb30(uint32_t arg = 0);
extern void FUN_00534350();
extern void FUN_00534130();
extern int32_t FUN_00500ce0(const char* name, uint32_t owner);
extern void FUN_00540c50();
extern uint32_t FUN_005be280(const char* name, uint32_t size, const void* data);
extern uint8_t FUN_005be240(const char* name, void* sizeOut, void** dataOut);
extern void FUN_00500ea0();
extern void operator_delete(void* ptr);
extern int32_t FUN_00501140(void* object, const void* key);
extern void FUN_004aad70(uint32_t value);
extern void FUN_004e59f0(void* slot);
extern void FUN_004e55f0(void* slot, uint32_t arg);
extern uint32_t* FUN_004dadc0(float x, float y, float z);
extern void FUN_00533d10(uint32_t a, uint32_t b);
extern void FUN_004ff890();
extern void FUN_004ff360(uint32_t bits);
extern void FUN_00412840(uint32_t a, uint32_t b);
extern void FUN_004ff6b0(uint32_t value);
extern void FUN_005002f0();
extern uint32_t FUN_00500600();
extern uint32_t FUN_00538680();
extern uint32_t FUN_00533db0(...);
extern void FUN_00535670(uint32_t object);
extern void FUN_0053d400(float* a, float* b, void* out);
extern void FUN_0053d720(float a, float b, uint32_t object);
extern void FUN_00535de0(uint32_t value);
extern void FUN_00535e10();
extern void FUN_004ff510(float value, uint32_t scale);
extern void FUN_00501040(uint32_t object);
extern void FUN_00535920(uint32_t object);
extern void FUN_00542700(uint32_t object, uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern void FUN_00542cb0(uint32_t a, uint32_t b);
extern void FUN_00547720();
extern void FUN_00547730(uint32_t value = 0);
extern const char* FUN_005dbd60();
extern uint32_t FUN_0054c210(uint32_t w, uint32_t h, uint32_t owner, void* out);
extern void FUN_004ff9a0(...);
extern void FUN_004ff930(...);
extern void thunk_FUN_005f2abc(...);
extern void thunk_FUN_005f2148(...);

// ---- referenced globals -----------------------------------------------------
extern uintptr_t DAT_008ea08c;
extern uintptr_t DAT_008c9dec;
extern uintptr_t DAT_0072cd78;
extern uintptr_t DAT_00727c30;
extern uintptr_t DAT_008c97c0;
extern uint32_t DAT_00727598;
extern uint32_t DAT_00727560;
extern uint32_t DAT_00727310;
extern uint8_t DAT_007263bc;
extern uint8_t DAT_008cac36;
extern uint32_t DAT_007264b8;
extern uint8_t DAT_007264bc;
extern uint32_t PTR_FUN_0070e93c;
extern uint32_t PTR_FUN_0070d868;
extern uint32_t PTR_FUN_0070bed4;
extern uint32_t PTR_FUN_0070d038;
extern const char PTR_s_rm_dds_00706f2c_0x28_0070f888;
// Unresolved singleton refcount the decompiler rendered as absolute slot 0x00000005.
extern int32_t iRam00000005;
extern uint32_t* puRam00000001;

// ---- shared primitives ------------------------------------------------------
static uint32_t addr32(const void* p)
{
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p));
}

// *(object) is a vtable pointer; returns the entry at vtable+offset.
static void* vtslot(uintptr_t object, uint32_t offset)
{
    void* vtbl = *reinterpret_cast<void**>(object);
    return *reinterpret_cast<void**>(static_cast<uint8_t*>(vtbl) + offset);
}

template <typename Fn>
static Fn vslot(uintptr_t object, uint32_t offset)
{
    return reinterpret_cast<Fn>(vtslot(object, offset));
}

// Refcounted object layout: [0] = vtable, [1] = strong count.
static void release_object(uint32_t* obj, uint32_t deleting)
{
    if (obj == nullptr) {
        return;
    }
    int32_t* ref = reinterpret_cast<int32_t*>(obj + 1);
    *ref = *ref - 1;
    if (*ref == 0) {
        vslot<void (*)(uint32_t)>(*obj, 0)(deleting);
    }
}

static void assign_object(uint32_t** slot, uint32_t* value, uint32_t deleting)
{
    uint32_t* old = *slot;
    if (old == value) {
        return;
    }
    release_object(old, deleting);
    *slot = value;
    if (value != nullptr) {
        value[1] = value[1] + 1;
    }
}

static void clear_slot(uint32_t* slot)
{
    uint32_t* obj = reinterpret_cast<uint32_t*>(*slot);
    if (obj != nullptr) {
        release_object(obj, 1);
        *slot = 0;
    }
}

static void copy_dwords(uint32_t* dst, const uint32_t* src, int32_t count)
{
    for (int32_t i = 0; i != count; ++i) {
        dst[i] = src[i];
    }
}

// ---- definitions in this batch (forward declarations) ----------------------
void FUN_004e2970(void* self, uint32_t* param_1, uint32_t* param_2, uint32_t* param_3,
                  uint32_t* param_4);
void FUN_004e2c10(void* self, uint32_t* param_4);
void FUN_004e2df0(void* self);
void FUN_004e2e40(void* self);
void FUN_004e2ec0(int32_t* param_1, uint32_t param_2);
void FUN_004e3330(int32_t param_1, bool shortMode = false);
void FUN_004e3490(int32_t param_1, uint32_t param_2 = 0);
uint32_t FUN_004e3800(void* self);
void FUN_004e38f0(void* self);
void FUN_004e39f0(void* self);
void FUN_004e3a60(void* self, void* out);
void FUN_004e3c70(int32_t param_1);
void FUN_004e3e70(void* self, const char* param_1);
void FUN_004e3ee0(void* self, uint32_t* param_EDI = nullptr);
void FUN_004e4100(void* self, int32_t param_1);
void FUN_004e4190(void* self, uint32_t* param_1 = nullptr);
void FUN_004e4370(void* self, uint8_t flag);
void FUN_004e43c0(void* self, uint32_t param_1);
long double FUN_004e4550(void);
void FUN_004e4580(void* self, int32_t param_1);

// 0x4e2970 — observed shape
// Ocean scene initialiser. Rebinds the three material/NIF handles at self+0xcc,
// self+0x0c and self+0x10, then the pipeline object at self+0x8 / self+0xd8,
// loads the mid-day sky box, builds the water material object and pushes
// fWaterTexScale. Receivers: ESI = self, EDI = an extra refcounted handle that is
// released on exit.
void FUN_004e2970(void* self, uint32_t* param_1, uint32_t* param_2, uint32_t* param_3,
                  uint32_t* param_4 /* in EDI */)
{
    char* base = static_cast<char*>(self);
    assign_object(reinterpret_cast<uint32_t**>(base + 0xcc), param_1, 0);
    assign_object(reinterpret_cast<uint32_t**>(base + 0x0c), param_2, 0);
    assign_object(reinterpret_cast<uint32_t**>(base + 0x10), param_3, 0);

    FUN_004e4190(self);

    uint32_t* puVar4 = nullptr;
    if (FUN_00533c78(0) != 0) {
        puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_0053bb30()));
    }
    assign_object(reinterpret_cast<uint32_t**>(base + 8), puVar4, 0);

    if (*(int32_t*)(base + 0xd8) == 0) {
        puVar4 = nullptr;
        if (FUN_00533c78(0) != 0) {
            puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_0053bb30()));
        }
        assign_object(reinterpret_cast<uint32_t**>(base + 0xd8), puVar4, 0);
    }

    *(int32_t*)(base + 0xf4) = -1;
    FUN_004e3ee0(self);
    FUN_004e3c70(static_cast<int32_t>(reinterpret_cast<uintptr_t>(self)));

    uint32_t* puStack_14 = *reinterpret_cast<uint32_t**>(base + 0x1c);
    // The listing also shows a stray xmm constant (7.178472e-39) supplied to this
    // slot-0x70 call; the typed call shape matches FUN_004e3c70's identical site.
    vslot<void (*)(uint32_t, uint32_t)>(*(uint32_t*)(base + 0x10), 0x70)(
        *(uint32_t*)(base + 0x1c), 1);
    FUN_00534350();
    FUN_00534130();

    int32_t iVar3 = 0;
    if (FUN_00533c78(0) != 0) {
        iVar3 = FUN_00500ce0("SkyBoxMidDayREF_FLAT.nif", *(uint32_t*)(base + 0xcc));
    }
    *(int32_t*)(base + 0xd4) = iVar3;
    // The listing also prepares (float)(self+0x2c) + 350.0 in xmm0 for these two
    // calls; the typed argument list shows only the integer 0.
    vslot<void (*)(uint32_t)>(*(uint32_t*)(iVar3 + 0x14), 0x10)(0);
    vslot<void (*)(uint32_t)>(*(uint32_t*)(iVar3 + 0x14), 0x0c)(0);

    puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00533c78(0x40)));
    if (puVar4 == nullptr) {
        puVar4 = nullptr;
    } else {
        FUN_00540c50();
        *puVar4 = addr32(&PTR_FUN_0070e93c);
        *(uint8_t*)(puVar4 + 8) = 0;
        puVar4[9] = 4;
        puVar4[10] = 0;
        puVar4[0xb] = 0xffffffffu;
        puVar4[0xc] = 0;
        puVar4[0xd] = 0;
        puVar4[0xe] = 3;
        puVar4[0xf] = 0;
    }
    assign_object(reinterpret_cast<uint32_t**>(base + 0xdc), puVar4, 1);
    *(int32_t*)(*(int32_t*)(base + 0xdc) + 0x3c) = 1;

    FUN_004e43c0(self, 0);
    uint32_t uStack_1c = 0x3f800000u;
    FUN_005be280("fWaterTexScale", 4, &uStack_1c);
    FUN_00534350();
    FUN_00534130();

    if (puStack_14 != nullptr) {
        release_object(puStack_14, 1);
    }
    iRam00000005 = iRam00000005 - 1;
    if (iRam00000005 == 0) {
        vslot<void (*)(uint32_t)>(reinterpret_cast<uintptr_t>(puRam00000001), 0)(1);
    }
    release_object(param_4, 1);
}

// 0x4e2c10 — observed shape
// Destructor body: unlocks the two scene graph bindings (vtable slot 0x74), drops
// the nine mesh slots at self+0xa8, then the remaining refcounted members and the
// heap buffer at self+0xd4 (offset 0x35 dwords). Receivers: ESI = self, EDI = an
// extra refcounted handle released early.
void FUN_004e2c10(void* self, uint32_t* param_4 /* in EDI */)
{
    uint32_t* s = static_cast<uint32_t*>(self);
    uint32_t local_4 = 0;
    uint32_t* puVar5 = &local_4;

    vslot<void (*)(uint32_t*, uint32_t)>(s[2], 0x74)(puVar5, s[5]);
    release_object(param_4, 1);

    uint32_t local_8 = 0;
    vslot<void (*)(uint32_t*, uint32_t)>(s[4], 0x74)(&local_8, s[7]);
    if (puVar5 != nullptr) {
        release_object(puVar5, 1);
    }

    uint32_t* piVar4 = s + 0x2a;
    for (int32_t iVar3 = 9; iVar3 != 0; --iVar3) {
        uint32_t* puVar5b = reinterpret_cast<uint32_t*>(*piVar4);
        if (puVar5b != nullptr) {
            release_object(puVar5b, 1);
            *piVar4 = 0;
        }
        piVar4 = piVar4 + 1;
    }

    clear_slot(s + 7);
    clear_slot(s + 2);
    clear_slot(s + 5);
    clear_slot(s + 6);
    clear_slot(s + 0x36);
    clear_slot(s + 0x34);
    clear_slot(s + 0x38);
    clear_slot(s + 0x37);
    clear_slot(s + 0x33);
    clear_slot(s + 3);
    clear_slot(s + 4);
    clear_slot(s + 1);

    void* pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(s[0x35]));
    if (pvVar2 != nullptr) {
        FUN_00500ea0();
        operator_delete(pvVar2);
        s[0x35] = 0;
    }
    clear_slot(s);
}

// 0x4e2df0 — observed shape
// Enables the water pass once: binds the two scene objects (slot 0x70) and flushes
// the pipeline twice. Idempotent through the byte flag at self+0xf0.
void FUN_004e2df0(void* self)
{
    char* base = static_cast<char*>(self);
    if (*(uint8_t*)(base + 0xf0) != 0) {
        return;
    }
    *(uint8_t*)(base + 0xf0) = 1;
    vslot<void (*)(uint32_t, uint32_t)>(*(uint32_t*)(base + 0x0c), 0x70)(
        *(uint32_t*)(base + 8), 1);
    vslot<void (*)(uint32_t, uint32_t)>(*(uint32_t*)(base + 0x10), 0x70)(
        *(uint32_t*)(base + 0x1c), 1);
    FUN_00534130();
    FUN_00534350();
    FUN_00534130();
    FUN_00534350();
}

// 0x4e2e40 — observed shape
// Inverse of 0x4e2df0: unbinds both scene objects through vtable slot 0x74 and
// clears the enable flag. Receiver arrives in EAX.
void FUN_004e2e40(void* self)
{
    char* base = static_cast<char*>(self);
    if (*(uint8_t*)(base + 0xf0) == 0) {
        return;
    }
    uint32_t* puStack_c = *reinterpret_cast<uint32_t**>(base + 8);
    *(uint8_t*)(base + 0xf0) = 0;

    uint32_t local_4 = 0;
    vslot<void (*)(uint32_t*)>(*(uint32_t*)(base + 0x0c), 0x74)(&local_4);
    release_object(puStack_c, 1);

    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 0x1c);
    vslot<void (*)(uint32_t**)>(*(uint32_t*)(base + 0x10), 0x74)(&puStack_c);
    release_object(puVar2, 1);
}

// 0x4e2ec0 — observed shape
// Per-frame ocean update. Rebinds the cylinder material when the renderer exposes
// one, toggles the two sea patches according to the global quality level, resolves
// the accumulated wind offset against the 360-degree wrap, then writes the position
// and matrix of the active water object (self[0] / self[5]) plus its reflection
// twin and the wave matrix when self[0x3d] selects the open-water path.
void FUN_004e2ec0(int32_t* param_1, uint32_t param_2)
{
    FUN_004ff890();

    if (DAT_008c9dec != 0) {
        int32_t* piVar5;
        if (*(int32_t*)(DAT_008c9dec + 0x14) == 0) {
            piVar5 = nullptr;
        } else {
            piVar5 = *reinterpret_cast<int32_t**>(*(int32_t*)(DAT_008c9dec + 0x14) + 0x44);
            if (piVar5 != nullptr) {
                int32_t iVar2 = piVar5[1];
                piVar5[1] = iVar2 + 1;
                piVar5[1] = iVar2;
                if (iVar2 == 0) {
                    vslot<void (*)(uint32_t)>(static_cast<uintptr_t>(piVar5[0]), 0)(1);
                }
            }
        }
        vslot<void (*)(const char*)>(static_cast<uintptr_t>(piVar5[0]), 0x40)("Cylinder01:1");

        int32_t iVar2 = static_cast<int32_t>(FUN_00533db0(8));
        if (iVar2 != 0 && *(int32_t*)(param_1[0x35] + 0x14) != 0) {
            uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(*(int32_t*)(param_1[0x35] + 0x14) + 0x44);
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
            int32_t iVar3 = FUN_00501140(puVar4, &DAT_00727598);
            if (puVar4 != nullptr) {
                release_object(puVar4, 1);
            }
            if (iVar3 != 0) {
                iVar3 = static_cast<int32_t>(FUN_00533db0(8));
                if (iVar3 != 0) {
                    FUN_00533db0(8);
                    uint32_t uVar6;
                    if (*reinterpret_cast<int32_t*>(iVar2 + 0x2c) == 0) {
                        uVar6 = 0;
                    } else {
                        uVar6 = *reinterpret_cast<uint32_t*>(
                            *reinterpret_cast<int32_t*>(iVar2 + 0x2c) + 4);
                    }
                    FUN_004aad70(uVar6);
                }
            }
        }
    }

    int32_t* piVar5 = param_1 + 0xc;
    int32_t iVar2 = 2;
    do {
        if (*(int32_t*)(DAT_0072cd78 + 0x0c) < 5) {
            if (*(int8_t*)piVar5 != 0) {
                FUN_004e59f0(piVar5);
                *(uint16_t*)(piVar5[1] + 0x20) =
                    static_cast<uint16_t>(*(uint16_t*)(piVar5[1] + 0x20) & 0xfffe);
                *(int8_t*)piVar5 = 0;
                if (piVar5[1] != 0) {
                    uint16_t* puVar1 = reinterpret_cast<uint16_t*>(piVar5[1] + 0x20);
                    *puVar1 = static_cast<uint16_t>(*puVar1 | 1);
                    *(uint16_t*)(piVar5[0xd] + 0x20) =
                        static_cast<uint16_t>(*(uint16_t*)(piVar5[0xd] + 0x20) | 1);
                }
            }
        } else {
            FUN_004e55f0(piVar5, param_2);
        }
        piVar5 = piVar5 + 0xf;
        iVar2 = iVar2 - 1;
    } while (iVar2 != 0);

    iVar2 = param_1[0x3e];
    if (param_1[0x3f] == 0 && param_1[0x40] == 0 && param_1[0x41] == 0) {
        *(uint8_t*)(param_1 + 0x3e) = 0;
    }

    // local_30 / fStack_2c are read before their first visible assignment; Ghidra
    // elided the x87 operands of _CIfmod, so they are seeded as zero here.
    float local_30 = 0.0f;
    float fStack_2c = 0.0f;
    float fStack_28;
    if (static_cast<int8_t>(param_1[0x3e]) == 0) {
        long double fVar9 = _CIfmod();
        local_30 = static_cast<float>(static_cast<long double>(local_30) - fVar9);
        fVar9 = _CIfmod();
        fStack_28 = static_cast<float>(param_1[0x0b]);
        fStack_2c = static_cast<float>(static_cast<long double>(fStack_2c) - fVar9);
    } else {
        fStack_28 = static_cast<float>(param_1[0x0b]);
        local_30 = 0.0f;
        fStack_2c = 0.0f;
    }

    if (param_1[0x3d] != 0) {
        if (local_30 != static_cast<float>(param_1[0x39]) ||
            fStack_2c != static_cast<float>(param_1[0x3a]) ||
            fStack_28 != static_cast<float>(param_1[0x3b])) {
            int32_t iVar3 = *param_1;
            param_1[0x39] = static_cast<int32_t>(local_30);
            param_1[0x3a] = static_cast<int32_t>(fStack_2c);
            param_1[0x3b] = static_cast<int32_t>(fStack_28);
            *(float*)(iVar3 + 0x5c) = local_30;
            *(float*)(iVar3 + 0x60) = fStack_2c;
            *(float*)(iVar3 + 100) = fStack_28;
            *(float*)(*param_1 + 0x68) = fabsf(static_cast<float>(param_1[10]) * 0.01f);
            FUN_00534350();
            iVar3 = param_1[7];
            *(float*)(iVar3 + 0x5c) = local_30;
            *(float*)(iVar3 + 0x60) = fStack_2c;
            *(float*)(iVar3 + 100) = fStack_28 - 161.0f;
            *(float*)(param_1[7] + 0x68) = fabsf(static_cast<float>(param_1[10]) * 0.01f);
        }
        if (static_cast<int8_t>(iVar2) != 0) {
            uint32_t* puVar4 = FUN_004dadc0(
                static_cast<float>(param_1[0x3f]) * 1.4629181e-09f,
                static_cast<float>(param_1[0x40]) * 1.4629181e-09f,
                static_cast<float>(param_1[0x41]) * 1.4629181e-09f);
            copy_dwords(reinterpret_cast<uint32_t*>(param_1[2] + 0x38), puVar4, 9);
            copy_dwords(reinterpret_cast<uint32_t*>(param_1[7] + 0x38), puVar4 + 9, 9);
        }
        FUN_00533d10(param_2, 1);
        FUN_00533d10(param_2, 1);
        if (1 < param_1[0x3d]) {
            FUN_004e3490(static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_1)));
        }
        if ((DAT_007263bc & 4) != 0) {
            FUN_004e39f0(param_1);
        }
        return;
    }

    FUN_00533d10(param_2, 1);
    if (local_30 != static_cast<float>(param_1[0x39]) ||
        fStack_2c != static_cast<float>(param_1[0x3a]) ||
        fStack_28 != static_cast<float>(param_1[0x3b])) {
        int32_t iVar3 = param_1[5];
        param_1[0x39] = static_cast<int32_t>(local_30);
        param_1[0x3a] = static_cast<int32_t>(fStack_2c);
        param_1[0x3b] = static_cast<int32_t>(fStack_28);
        *(float*)(iVar3 + 0x5c) = local_30;
        *(float*)(iVar3 + 0x60) = fStack_2c;
        *(float*)(iVar3 + 100) = fStack_28;
        *(float*)(param_1[5] + 0x68) = fabsf(static_cast<float>(param_1[10]) * 0.01f);
        FUN_00534350();
        iVar3 = param_1[7];
        *(float*)(iVar3 + 0x5c) = local_30;
        *(float*)(iVar3 + 0x60) = fStack_2c;
        *(float*)(iVar3 + 100) = fStack_28 - 161.0f;
        *(float*)(param_1[7] + 0x68) = fabsf(static_cast<float>(param_1[10]) * 0.01f);
    }
    if (static_cast<int8_t>(iVar2) != 0) {
        uint32_t* puVar4 = FUN_004dadc0(
            static_cast<float>(param_1[0x3f]) * 1.4629181e-09f,
            static_cast<float>(param_1[0x40]) * 1.4629181e-09f,
            static_cast<float>(param_1[0x41]) * 1.4629181e-09f);
        copy_dwords(reinterpret_cast<uint32_t*>(param_1[2] + 0x38), puVar4, 9);
        copy_dwords(reinterpret_cast<uint32_t*>(param_1[7] + 0x38), puVar4 + 9, 9);
    }
    FUN_00533d10(param_2, 1);
    FUN_00533d10(param_2, 1);
}

// 0x4e3330 — observed shape
// Rescales every mesh found under the scene container at self+0xd8. Walks the
// container list, keeps elements that expose the 0x00727560 marker, then scales
// the ninth matrix entry of each mesh by -0.5 (short mode) or -2.0.
void FUN_004e3330(int32_t param_1, bool shortMode)
{
    float local_30 = shortMode ? -0.5f : -2.0f;
    int32_t iVar4 = *(int32_t*)(param_1 + 0xd8);
    uint32_t local_28 = 0;

    if (*(int32_t*)(iVar4 + 0xc0) != 0) {
        uint32_t uVar11 = 0;
        do {
            int32_t* piVar1 = *reinterpret_cast<int32_t**>(*(int32_t*)(iVar4 + 0xb8) + local_28 * 4);
            uVar11 = local_28;
            if (piVar1 != nullptr) {
                piVar1[1] = piVar1[1] + 1;

                uint8_t bVar3;
                uint32_t* puVar5 = reinterpret_cast<uint32_t*>(
                    vslot<uint32_t* (*)()>(static_cast<uintptr_t>(piVar1[0]), 4)());
                while (puVar5 != nullptr) {
                    if (puVar5 == &DAT_00727560) {
                        bVar3 = 1;
                        break;
                    }
                    puVar5 = reinterpret_cast<uint32_t*>(puVar5[1]);
                }
                if (puVar5 == nullptr) {
                    bVar3 = 0;
                }

                int32_t* piVar6 = bVar3 != 0 ? piVar1 : nullptr;
                if (piVar6 != nullptr) {
                    piVar6[1] = piVar6[1] + 1;
                    uint32_t uStack_34 = 0;
                    if (piVar6[0x30] != 0) {
                        uint32_t uVar7 = 0;
                        do {
                            int32_t* piVar2 =
                                *reinterpret_cast<int32_t**>(piVar6[0x2e] + uStack_34 * 4);
                            uVar7 = uStack_34;
                            if (piVar2 != nullptr) {
                                piVar2[1] = piVar2[1] + 1;
                                int32_t iVar5 = *piVar2;
                                uint32_t aiStack_24[9];
                                copy_dwords(aiStack_24, reinterpret_cast<uint32_t*>(piVar2 + 0xe), 9);
                                reinterpret_cast<float&>(aiStack_24[8]) =
                                    reinterpret_cast<float&>(aiStack_24[8]) * local_30;
                                copy_dwords(reinterpret_cast<uint32_t*>(piVar2 + 0xe), aiStack_24, 9);
                                vslot<void (*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(iVar5), 0x4c)(0, 0);
                                release_object(reinterpret_cast<uint32_t*>(piVar2), 1);
                            }
                            uStack_34 = uVar7 + 1;
                        } while (uStack_34 < static_cast<uint32_t>(piVar6[0x30]));
                    }
                    vslot<void (*)()>(static_cast<uintptr_t>(piVar6[0]), 0x80)();
                    release_object(reinterpret_cast<uint32_t*>(piVar6), 1);
                }
                release_object(reinterpret_cast<uint32_t*>(piVar1), 1);
            }
            iVar4 = *(int32_t*)(param_1 + 0xd8);
            local_28 = uVar11 + 1;
        } while (local_28 < static_cast<uint32_t>(*(int32_t*)(iVar4 + 0xc0)));
    }
}

// 0x4e3490 — observed shape
// Reflection/refraction pass. Saves the f4Depths tuning block, rebinds the
// reflection camera object (self+0xd0) from the scene camera (self+0xcc), measures
// the sun-to-camera angle, applies the platform-dependent far-plane scale, renders
// the reflection map and restores the saved tuning block.
void FUN_004e3490(int32_t param_1, uint32_t param_2)
{
    uint32_t cfgSize = 0;
    void* buffers[2] = {nullptr, nullptr};
    FUN_005be240("f4Depths", &cfgSize, buffers);

    uint32_t* cfgBuf = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(thunk_FUN_00533c78(cfgSize)));
    {
        uint32_t* src = reinterpret_cast<uint32_t*>(buffers[0]);
        uint8_t* dst = reinterpret_cast<uint8_t*>(cfgBuf);
        for (uint32_t uVar4 = cfgSize >> 2; uVar4 != 0; --uVar4) {
            *reinterpret_cast<uint32_t*>(dst) = *src++;
            dst += 4;
        }
        for (uint32_t uVar4 = cfgSize & 3; uVar4 != 0; --uVar4) {
            *dst++ = *reinterpret_cast<uint8_t*>(src);
            src = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(src) + 1);
        }
    }
    FUN_005be280("f4Depths", 0x10, &DAT_00727310);

    int32_t* piVar1 = reinterpret_cast<int32_t*>(DAT_008ea08c);
    // apiStack_58[0] is the same renderer object as piVar1 in the shipped code; the
    // decompiler left the slot uninitialised.
    int32_t* apiStack_58[9] = {piVar1, nullptr, piVar1, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    FUN_00535670(*(uint32_t*)(param_1 + 0xd8));
    FUN_00535670(*(uint32_t*)(param_1 + 0xd8));

    uint32_t local_48[9];
    copy_dwords(local_48, reinterpret_cast<uint32_t*>(DAT_008c97c0 + 0x38), 9);

    float local_78 = 0.0f;
    float local_70 = 0.0f;
    FUN_0053d400(&local_78, &local_70, &apiStack_58[3]);
    FUN_0053d720(local_78 - 3.1415927f, local_70,
                  static_cast<uint32_t>(reinterpret_cast<uintptr_t>(apiStack_58[3])));

    // local_24 is only read here: the decompiler never renders its writes.
    uint32_t local_24[9] = {};
    copy_dwords(reinterpret_cast<uint32_t*>(DAT_008c97c0 + 0x38), local_24, 9);
    FUN_00533d10(0, 0);

    float local_6c = 0.0f;
    float local_68 = 0.0f;
    uint32_t local_64 = 0;
    uint32_t local_60 = 0x3f800000u;
    vslot<void (*)(float*)>(static_cast<uintptr_t>(piVar1[0]), 0x70)(&local_6c);
    vslot<void (*)(uint32_t)>(static_cast<uintptr_t>(piVar1[0]), 0x40)(*(uint32_t*)(param_1 + 0xe0));
    FUN_00535de0(5);

    int32_t iVar5 = *(int32_t*)(param_1 + 0xcc);
    int32_t iVar2 = *(int32_t*)(param_1 + 0xd0);
    *(uint32_t*)(iVar2 + 0x5c) = *(uint32_t*)(iVar5 + 0x5c);
    *(uint32_t*)(iVar2 + 0x60) = *(uint32_t*)(iVar5 + 0x60);
    *(uint32_t*)(iVar2 + 100) = *(uint32_t*)(iVar5 + 100);
    copy_dwords(reinterpret_cast<uint32_t*>(*(int32_t*)(param_1 + 0xd0) + 0x38),
                reinterpret_cast<uint32_t*>(*(int32_t*)(param_1 + 0xcc) + 0x38), 9);

    // Seven dwords copied over the stack block starting at local_74.
    float copied[7];
    {
        uint32_t* src = reinterpret_cast<uint32_t*>(*(int32_t*)(param_1 + 0xcc) + 0x128);
        for (int32_t i = 0; i < 7; ++i) {
            copied[i] = *reinterpret_cast<float*>(src + i);
        }
    }
    float dx = copied[1] - copied[0];
    float dy = copied[2] - copied[3];
    float fVar10 = static_cast<float>(
        atan2(static_cast<double>(sqrt(static_cast<double>(dx * dx + dy * dy))) * 0.5, 1.0));
    float arcAngle = (fVar10 + fVar10) * 57.29577951308232f;
    uint32_t uVar11 = (DAT_008cac36 == 0) ? 0x3faaaaabu : 0x3fe38e39u;
    FUN_004ff510(arcAngle, uVar11);
    FUN_004ff6b0(0);
    FUN_00501040(*(uint32_t*)(param_1 + 0xd4));
    FUN_004e3330(param_1);
    FUN_00534350();
    FUN_00534130();

    iVar5 = *(int32_t*)(param_1 + 0xd0);
    uint32_t* puVar6 = *reinterpret_cast<uint32_t**>(param_1 + 0xd8);
    {
        uint32_t* puVar8 = *reinterpret_cast<uint32_t**>(iVar5 + 0x154);
        if (puVar8 != puVar6) {
            release_object(puVar8, 1);
            *reinterpret_cast<uint32_t**>(iVar5 + 0x154) = puVar6;
            if (puVar6 != nullptr) {
                puVar6[1] = puVar6[1] + 1;
            }
        }
    }
    vslot<void (*)()>(*(uint32_t*)(param_1 + 0xd0), 0x70)();
    FUN_00535e10();

    iVar5 = *(int32_t*)(param_1 + 0xd0);
    {
        uint32_t* puVar8 = *reinterpret_cast<uint32_t**>(iVar5 + 0x154);
        if (puVar8 != nullptr) {
            release_object(puVar8, 1);
            *(uint32_t*)(iVar5 + 0x154) = 0;
        }
    }
    vslot<void (*)(uint32_t)>(static_cast<uintptr_t>(apiStack_58[0][0]), 0x40)(0);

    // local_78/local_74/local_70 form the RGB triplet handed to vtable slot 0x74;
    // the middle word is the raw float constant 0x3f24a4a5.
    float colour[3];
    colour[0] = 0.36862746f;
    *reinterpret_cast<uint32_t*>(&colour[1]) = 0x3f24a4a5u;
    colour[2] = 0.8862745f;
    vslot<void (*)(void*)>(static_cast<uintptr_t>(apiStack_58[0][0]), 0x74)(colour);

    FUN_00535920(*(uint32_t*)(param_1 + 0xd8));
    FUN_00535920(*(uint32_t*)(param_1 + 0xd8));

    copy_dwords(reinterpret_cast<uint32_t*>(DAT_008c97c0 + 0x38),
                reinterpret_cast<uint32_t*>(apiStack_58), 9);
    FUN_00533d10(0, 0);
    FUN_004e3330(param_1);
    FUN_00534350();
    FUN_00534130();

    FUN_005be280("f4Depths", param_2, cfgBuf);
    if (cfgBuf != nullptr) {
        operator_delete(cfgBuf);
    }
}

// 0x4e3800 — observed shape
// Lazily creates (and caches at self+0xe0) the 0x200x0x200 scratch surface.
// A second creation attempt follows a device-method call when the first fails.
uint32_t FUN_004e3800(void* self)
{
    char* base = static_cast<char*>(self);
    if (*(int32_t*)(base + 0xe0) != 0) {
        return *(uint32_t*)(base + 0xe0);
    }

    int32_t local_c = 1;
    int32_t local_8 = 2;
    int32_t local_4 = 0;
    (void)local_8;

    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(FUN_0054c210(0x200, 0x200, static_cast<uint32_t>(DAT_008ea08c), &local_c)));
    assign_object(reinterpret_cast<uint32_t**>(base + 0xe0), puVar2, 1);

    if (*(int32_t*)(base + 0xe0) == 0) {
        int32_t* piVar3 = nullptr;
        if (DAT_008ea08c != 0) {
            piVar3 = *reinterpret_cast<int32_t**>(DAT_00727c30 + 0x60);
        }
        vslot<void (*)(int32_t*)>(static_cast<uintptr_t>(piVar3[0]), 0x14)(piVar3);
        puVar2 = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(FUN_0054c210(0x200, 0x200,
                                                static_cast<uint32_t>(DAT_008ea08c), &local_4)));
        assign_object(reinterpret_cast<uint32_t**>(base + 0xe0), puVar2, 1);
    }
    return *(uint32_t*)(base + 0xe0);
}

// 0x4e38f0 — observed shape
// Rebuilds the reflection render target (self+0xd0) on first use, shares the
// global renderer into target+0x188, copies the scene camera transform and
// re-applies the reflection camera parameters.
void FUN_004e38f0(void* self)
{
    char* base = static_cast<char*>(self);
    if (*(int32_t*)(base + 0xd0) == 0) {
        uint32_t* puVar3 = nullptr;
        void* alloc = reinterpret_cast<void*>(static_cast<uintptr_t>(FUN_00533c78(0x238)));
        if (alloc == nullptr) {
            puVar3 = nullptr;
        } else {
            FUN_004ff360(0x42340000);
            *reinterpret_cast<uint32_t*>(alloc) = addr32(&PTR_FUN_0070d868);
            puVar3 = static_cast<uint32_t*>(alloc);
        }
        assign_object(reinterpret_cast<uint32_t**>(base + 0xd0), puVar3, 1);

        int32_t target = *(int32_t*)(base + 0xd0);
        assign_object(reinterpret_cast<uint32_t**>(target + 0x188),
                      reinterpret_cast<uint32_t*>(DAT_008ea08c), 1);
    }

    int32_t iVar4 = *(int32_t*)(base + 0xcc);
    int32_t iVar2 = *(int32_t*)(base + 0xd0);
    *(uint32_t*)(iVar2 + 0x5c) = *(uint32_t*)(iVar4 + 0x5c);
    *(uint32_t*)(iVar2 + 0x60) = *(uint32_t*)(iVar4 + 0x60);
    *(uint32_t*)(iVar2 + 100) = *(uint32_t*)(iVar4 + 100);
    copy_dwords(reinterpret_cast<uint32_t*>(*(int32_t*)(base + 0xd0) + 0x38),
                reinterpret_cast<uint32_t*>(*(int32_t*)(base + 0xcc) + 0x38), 9);

    FUN_00412840(0x41200000, 0x47c35000);
    FUN_004ff6b0(0);
}

// 0x4e39f0 — observed shape
// Uploads the reflection matrix and the bump-offset derived from the camera
// height (local_44 at camera+100): offset = -50 / height. Receiver in ESI.
void FUN_004e39f0(void* self)
{
    char* base = static_cast<char*>(self);
    FUN_00547720();

    int32_t iVar1 = *(int32_t*)(base + 0xcc);
    uint32_t local_4c = *(uint32_t*)(iVar1 + 0x5c);
    uint32_t local_48 = *(uint32_t*)(iVar1 + 0x60);
    float local_44 = *(float*)(iVar1 + 100);
    (void)local_4c;
    (void)local_48;
    float local_50 = -50.0f / local_44;

    uint8_t local_40[64];
    FUN_004e3a60(self, local_40);
    FUN_005be280("mtxReflect", 0x40, local_40);
    FUN_005be280("fBumpOffset", 4, &local_50);
}

// 0x4e3a60 — observed shape
// Builds the reflection matrix stack: a 0.1-scaled basis from self[0x34], the
// object matrix from self[0]+0x38, three multiplies through the matrix helpers
// and a 16-dword result written to the caller's out slot. Receiver in EAX.
void FUN_004e3a60(void* self, void* out)
{
    int32_t* self_words = static_cast<int32_t*>(self);
    uintptr_t puStack_250 = static_cast<uintptr_t>(self_words[0x34]);

    float local_180[5] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    uint32_t local_20c[16] = {};
    float local_16c = 0.0f;
    float local_140[10] = {};
    uint32_t local_1c0[11] = {};
    uint32_t auStack_8c[16] = {};
    uint32_t auStack_10c[16] = {};
    uint32_t auStack_d8[16] = {};
    uint32_t auStack_58[16] = {};
    uint32_t* puStack_20 = static_cast<uint32_t*>(out);

    local_20c[0] = 0x3f000000u;
    local_20c[1] = 0;
    local_20c[2] = 0x3f800000u;
    FUN_004ff9a0(puStack_250, local_180);

    local_180[0] = local_180[0] * 0.1f;
    local_16c = local_16c * 0.1f;
    // local_148 sits inside the local_140 buffer (0x140 + 8).
    local_140[2] = local_140[2] * 0.1f;
    FUN_004ff930(local_140);

    copy_dwords(local_20c + 3, reinterpret_cast<uint32_t*>(*self_words + 0x38), 9);
    thunk_FUN_005f2abc();

    local_1c0[0] = local_20c[3];
    local_1c0[1] = local_20c[4];
    local_1c0[2] = local_20c[5];
    local_1c0[4] = local_20c[6];
    local_1c0[5] = local_20c[7];
    local_1c0[6] = local_20c[8];
    local_1c0[8] = local_20c[9];
    local_1c0[9] = local_20c[10];
    local_1c0[10] = local_20c[11];
    thunk_FUN_005f2148(local_140, local_1c0, local_20c + 3);

    copy_dwords(auStack_8c, local_20c, 16);
    thunk_FUN_005f2148(auStack_10c, auStack_8c);

    // auStack_118 is a view three dwords into auStack_10c.
    copy_dwords(auStack_d8, auStack_10c + 3, 16);
    thunk_FUN_005f2148(auStack_58, auStack_d8, &puStack_250);

    // auStack_64 is a view three dwords into auStack_58.
    copy_dwords(puStack_20, auStack_58 + 3, 16);
}

// 0x4e3c70 — observed shape
// Populates the 3x3 grid of sea tiles at 100000-unit spacing around self+0x1c,
// attaching each freshly created mesh to the container and to its list links.
void FUN_004e3c70(int32_t param_1)
{
    uint32_t* puVar4;
    {
        void* alloc = reinterpret_cast<void*>(static_cast<uintptr_t>(FUN_00533c78(0xec)));
        puVar4 = alloc == nullptr ? nullptr : reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_0053bb30(0)));
    }
    assign_object(reinterpret_cast<uint32_t**>(param_1 + 0x1c), puVar4, 1);
    vslot<void (*)(uint32_t, uint32_t)>(*(uint32_t*)(param_1 + 0x10), 0x70)(
        *(uint32_t*)(param_1 + 0x1c), 1);

    puVar4 = nullptr;
    {
        void* alloc = reinterpret_cast<void*>(static_cast<uintptr_t>(FUN_00533c78(0x28)));
        if (alloc != nullptr) {
            FUN_00540c50();
            *reinterpret_cast<uint16_t*>(reinterpret_cast<uint32_t*>(alloc) + 8) = 3;
            puVar4 = static_cast<uint32_t*>(alloc);
            puVar4[9] = 3;
            *puVar4 = addr32(&PTR_FUN_0070bed4);
            puVar4[1] = puVar4[1] + 1;
        }
    }
    *reinterpret_cast<uint8_t*>(puVar4 + 8) =
        static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(puVar4 + 8) & 0xfc);

    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00500600()));
    if (puVar5 != nullptr) {
        puVar5[1] = puVar5[1] + 1;
    }

    for (int32_t iVar3 = -1; iVar3 < 2; ++iVar3) {
        for (int32_t iVar9 = -1; iVar9 < 2; ++iVar9) {
            uint8_t* iVar6 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(FUN_00538680()));
            *(float*)(iVar6 + 0x5c) = static_cast<float>(iVar3) * 100000.0f;
            *(float*)(iVar6 + 0x60) = static_cast<float>(iVar9) * 100000.0f;
            *(uint32_t*)(iVar6 + 100) = 0;

            int32_t iVar7 = static_cast<int32_t>(FUN_00533db0(0x0b));
            if (iVar7 == 0) {
                puVar4[1] = puVar4[1] + 1;
                uint32_t* puVar8 = reinterpret_cast<uint32_t*>(
                    vslot<uint32_t* (*)()>(*reinterpret_cast<uint32_t*>(iVar6 + 0xa0), 4)());
                uint32_t* puVar2 = reinterpret_cast<uint32_t*>(puVar8[2]);
                if (puVar2 != puVar4) {
                    release_object(puVar2, 1);
                    puVar8[2] = addr32(puVar4);
                    puVar4[1] = puVar4[1] + 1;
                }
                puVar8[1] = 0;
                *puVar8 = *(uint32_t*)(iVar6 + 0xa4);
                if (*(int32_t*)(iVar6 + 0xa4) == 0) {
                    *reinterpret_cast<uint32_t**>(iVar6 + 0xa8) = puVar8;
                } else {
                    *reinterpret_cast<uint32_t**>(*(int32_t*)(iVar6 + 0xa4) + 4) = puVar8;
                }
                *reinterpret_cast<uint32_t**>(iVar6 + 0xa4) = puVar8;
                *(int32_t*)(iVar6 + 0xac) = *(int32_t*)(iVar6 + 0xac) + 1;
                release_object(puVar4, 1);
                // The listing restores param_1 from a stack spill (iStack_4); the
                // parameter is untouched in the reconstruction.
            } else {
                *reinterpret_cast<uint8_t*>(iVar7 + 0x20) =
                    static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(iVar7 + 0x20) & 0xfc);
            }
            vslot<void (*)(uint32_t, uint32_t)>(*(uint32_t*)(param_1 + 0x1c), 0x70)(
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(iVar6)), 1);
        }
    }

    FUN_00534130();
    FUN_00534350();
    if (puVar5 != nullptr) {
        release_object(puVar5, 1);
    }
    release_object(puVar4, 1);
}

// 0x4e3e70 — observed shape
// Compares the engine-provided texture name (FUN_005dbd60) with the requested
// one; on mismatch switches the texture through vtable slot 100. Receiver in EDI.
void FUN_004e3e70(void* self, const char* param_1)
{
    char* base = static_cast<char*>(self);
    if (*(int32_t*)(base + 0xc8) != 0) {
        const uint8_t* pbVar2 = reinterpret_cast<const uint8_t*>(FUN_005dbd60());
        const uint8_t* target = reinterpret_cast<const uint8_t*>(param_1);

        int32_t iVar3 = 0;
        bool bVar4;
        for (;;) {
            uint8_t bVar1 = *pbVar2;
            bVar4 = bVar1 < *target;
            if (bVar1 != *target) {
                iVar3 = (1 - static_cast<uint32_t>(bVar4)) - static_cast<uint32_t>(bVar4 != 0);
                break;
            }
            if (bVar1 == 0) {
                iVar3 = 0;
                break;
            }
            bVar1 = pbVar2[1];
            bVar4 = bVar1 < target[1];
            if (bVar1 != target[1]) {
                iVar3 = (1 - static_cast<uint32_t>(bVar4)) - static_cast<uint32_t>(bVar4 != 0);
                break;
            }
            pbVar2 = pbVar2 + 2;
            target = target + 2;
            if (bVar1 == 0) {
                iVar3 = 0;
                break;
            }
        }

        if (iVar3 == 0) {
            return;
        }
    }
    vslot<void (*)(void*)>(*reinterpret_cast<uint32_t*>(self), 100)(
        reinterpret_cast<void*>(DAT_008ea08c));
    FUN_00547730();
}

// 0x4e3ee0 — observed shape
// Rebuilds the ocean water surface: scene node at self[0], texture object at
// self+8, the Plane01 material with TOceanWaterSparkle_11, the 0x0070d038
// surface wrapper, and the nine mesh slots at self+0xa8. Receiver in EAX, with
// an extra refcounted handle in EDI released at exit.
void FUN_004e3ee0(void* self, uint32_t* param_EDI /* in EDI */)
{
    int32_t* s = static_cast<int32_t*>(self);
    uint32_t* puVar3;
    {
        void* alloc = reinterpret_cast<void*>(static_cast<uintptr_t>(FUN_00533c78(0xec)));
        puVar3 = alloc == nullptr ? nullptr : reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_0053bb30(0)));
    }
    assign_object(reinterpret_cast<uint32_t**>(s), puVar3, 1);

    uint32_t* piVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00500600()));
    if (piVar4 != nullptr) {
        piVar4[1] = piVar4[1] + 1;
    }
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00500600()));
    assign_object(reinterpret_cast<uint32_t**>(s + 8), puVar5, 1);

    vslot<void (*)(uint32_t, uint32_t)>(piVar4[0], 0x70)(static_cast<uint32_t>(s[8]), 1);
    uint32_t uVar6 = vslot<uint32_t (*)(const char*, const char*, uint32_t)>(s[8], 0x40)(
        "Plane01", "TOceanWaterSparkle_11", 0);
    FUN_00547730(uVar6);
    vslot<void (*)(const char*, uint32_t)>(piVar4[0], 0x40)(
        &PTR_s_rm_dds_00706f2c_0x28_0070f888, 8);
    FUN_00533db0(&PTR_s_rm_dds_00706f2c_0x28_0070f888);

    puVar3 = nullptr;
    {
        uint32_t* alloc = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00533c78(0x20)));
        if (alloc != nullptr) {
            uVar6 = FUN_004e3800(self);
            FUN_00542700(uVar6, 0, 3, 1, 0);
            alloc[0] = addr32(&PTR_FUN_0070d038);
            alloc[7] = 0;
            puVar3 = alloc;
        }
    }
    FUN_00542cb0(0, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)));

    uint32_t uVar7 = 0;
    uint32_t* piVar4b = reinterpret_cast<uint32_t*>(s + 0x2a);
    do {
        puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00538680()));
        assign_object(reinterpret_cast<uint32_t**>(piVar4b), puVar5, 1);
        int32_t iVar2 = static_cast<int32_t>(*piVar4b);
        *(float*)(iVar2 + 0x5c) = static_cast<float>(static_cast<int32_t>(uVar7 / 3) - 1) * 100000.0f;
        *(float*)(iVar2 + 0x60) = static_cast<float>(static_cast<int32_t>(uVar7 % 3) - 1) * 100000.0f;
        *(uint32_t*)(iVar2 + 100) = 0;
        vslot<void (*)(uint32_t, uint32_t)>(static_cast<uint32_t>(s[0]), 0x70)(*piVar4b, 1);
        uVar7 = uVar7 + 1;
        piVar4b = piVar4b + 1;
    } while (static_cast<int32_t>(uVar7) < 9);

    FUN_00533d10(0, 1);
    FUN_00534130();
    FUN_00534350();
    s[0x39] = static_cast<int32_t>(0xc0800000u);
    s[0x3a] = static_cast<int32_t>(0xc0800000u);
    s[0x3b] = static_cast<int32_t>(0xc0800000u);
    FUN_004e38f0(self);
    release_object(param_EDI, 1);
}

// 0x4e4100 — observed shape
// Picks the EMBM water texture per GPU: GeForce3 range 0x200..0x203 gets the
// GF3 variant, otherwise XB for mode < 2 and the generic 11 variant. Receiver in
// ECX, mode in the stack argument.
void FUN_004e4100(void* self, int32_t param_1)
{
    char* base = static_cast<char*>(self);
    int32_t iVar1 = *reinterpret_cast<int32_t*>(DAT_008ea08c + 0x280);
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(base + 0xa8);

    for (int32_t iVar4 = 9; iVar4 != 0; --iVar4) {
        int32_t iVar2 = static_cast<int32_t>(vslot<uint32_t (*)(const void*)>(*puVar3, 0x40)(
            &PTR_s_rm_dds_00706f2c_0x28_0070f888));
        if (iVar2 != 0) {
            const char* pcVar5;
            if (*(int32_t*)(iVar1 + 0x42c) == 0x10de &&
                (iVar2 = *(int32_t*)(iVar1 + 0x430), 0x1ff < iVar2) && iVar2 < 0x204) {
                pcVar5 = "TOceanWaterEMBM_GF3_11";
            } else if (param_1 < 2) {
                pcVar5 = "TOceanWaterEMBM_XB";
            } else {
                pcVar5 = "TOceanWaterEMBM_11";
            }
            FUN_004e3e70(self, pcVar5);
        }
        puVar3 = puVar3 + 1;
    }
}

// 0x4e4190 — observed shape
// Collects the container at self+0x14, drops every child through vtable slot
// 0x74, rebuilds the 3x3 grid of sea tiles and resets the cached wave origin at
// self+0xe4/0xe8/0xec to -1. Receiver in EAX; param_1 may be null.
void FUN_004e4190(void* self, uint32_t* param_1)
{
    char* base = static_cast<char*>(self);
    if (param_1 == nullptr) {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_00500600()));
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
            param_1 = puVar3;
        }
    }

    if (*(int32_t*)(base + 0x14) == 0) {
        uint32_t* puVar3;
        void* alloc = reinterpret_cast<void*>(static_cast<uintptr_t>(FUN_00533c78(0xec)));
        puVar3 = alloc == nullptr ? nullptr
                                  : reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(FUN_0053bb30(0)));
        assign_object(reinterpret_cast<uint32_t**>(base + 0x14), puVar3, 1);
    }

    uint32_t uVar5 = 0;
    if (*(int32_t*)(*(int32_t*)(base + 0x14) + 0xc0) != 0) {
        do {
            if (uVar5 < static_cast<uint32_t>(*(int32_t*)(*(int32_t*)(base + 0x14) + 0xc0))) {
                uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(
                    *(int32_t*)(*(int32_t*)(base + 0x14) + 0xb8) + uVar5 * 4);
                if (puVar3 != nullptr) {
                    puVar3[1] = puVar3[1] + 1;
                    uint32_t* localOut = nullptr;
                    vslot<void (*)(uint32_t**, uint32_t*)>(*(uint32_t*)(base + 0x14), 0x74)(
                        &localOut, puVar3);
                    release_object(localOut, 1);
                    release_object(puVar3, 1);
                }
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < static_cast<uint32_t>(*(int32_t*)(*(int32_t*)(base + 0x14) + 0xc0)));
    }

    for (int32_t iStack_14 = -1; iStack_14 < 2; ++iStack_14) {
        int32_t local_10 = -1;
        do {
            uint8_t* iVar4 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(FUN_00538680()));
            *(float*)(iVar4 + 0x5c) = static_cast<float>(iStack_14) * 100000.0f;
            *(float*)(iVar4 + 0x60) = static_cast<float>(local_10) * 100000.0f;
            *(uint32_t*)(iVar4 + 100) = 0x4050c155u;
            vslot<void (*)(uint32_t, uint32_t)>(*(uint32_t*)(base + 0x14), 0x70)(
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(iVar4)), 1);
            local_10 = local_10 + 1;
        } while (local_10 < 2);
    }

    FUN_00533d10(0, 1);
    FUN_00534350();
    FUN_00534130();
    *(uint32_t*)(base + 0xe4) = 0xbf800000u;
    *(uint32_t*)(base + 0xe8) = 0xbf800000u;
    *(uint32_t*)(base + 0xec) = 0xbf800000u;
    release_object(param_1, 1);
}

// 0x4e4370 — observed shape
// Toggles the two sea patches at self+0x54 and self+0x90: stores the flag at
// +0x64, selects the visibility scalar (1.0 or DAT_007264b8) and updates the
// render bit of each patch. Receiver in ECX, flag in DL.
void FUN_004e4370(void* self, uint8_t flag)
{
    char* base = static_cast<char*>(self);
    int32_t* piVar3 = reinterpret_cast<int32_t*>(base + 100);
    for (int32_t iVar4 = 2; iVar4 != 0; --iVar4) {
        *reinterpret_cast<uint8_t*>(piVar3 + 1) = flag;
        uint32_t iVar2 = (flag == 0) ? 0x3f800000u : DAT_007264b8;
        int32_t iVar1 = *piVar3;
        piVar3[-4] = static_cast<int32_t>(iVar2);
        if (iVar1 != 0) {
            if (flag == 0) {
                *reinterpret_cast<uint8_t*>(iVar1 + 0x20) =
                    static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(iVar1 + 0x20) & 0xfe);
            } else if (DAT_007264bc != 0) {
                *reinterpret_cast<uint8_t*>(iVar1 + 0x20) =
                    static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(iVar1 + 0x20) | 1);
            }
        }
        piVar3 = piVar3 + 0xf;
    }
}

// 0x4e43c0 — observed shape
// Selects the water rendering mode (0..3, or 11 disables it), swapping the two
// scene objects at self[0] / self[5] through vtable slot 0x74 when crossing the
// off/on boundary and re-applying the EMBM textures. Receiver in EBX.
void FUN_004e43c0(void* self, uint32_t param_1)
{
    int32_t* s = static_cast<int32_t*>(self);
    uint32_t uVar2 = param_1;
    if (3 < static_cast<int32_t>(param_1)) {
        uVar2 = 0;
    }
    FUN_005002f0();
    if (param_1 < 0xb) {
        uVar2 = 0;
    }

    if (uVar2 != static_cast<uint32_t>(s[0x3d])) {
        if (uVar2 == 0) {
            uint32_t* puStack_4 = nullptr;
            // The listing passes &param_1 as the out slot; modeled as a local.
            vslot<void (*)(uint32_t**, uint32_t)>(static_cast<uint32_t>(s[2]), 0x74)(
                &puStack_4, static_cast<uint32_t>(s[0]));
            release_object(puStack_4, 1);
            vslot<void (*)(uint32_t, uint32_t)>(static_cast<uint32_t>(s[2]), 0x70)(
                static_cast<uint32_t>(s[5]), 1);
            FUN_00534350();
            FUN_00534130();
            s[0x39] = static_cast<int32_t>(0xbf800000u);
            s[0x3a] = static_cast<int32_t>(0xbf800000u);
            s[0x3d] = 0;
            s[0x3b] = static_cast<int32_t>(0xbf800000u);
            return;
        }
        if (s[0x3d] == 0) {
            uint32_t* puStack_4 = nullptr;
            vslot<void (*)(uint32_t**, uint32_t)>(static_cast<uint32_t>(s[2]), 0x74)(
                &puStack_4, static_cast<uint32_t>(s[5]));
            release_object(puStack_4, 1);
            vslot<void (*)(uint32_t, uint32_t)>(static_cast<uint32_t>(s[2]), 0x70)(
                static_cast<uint32_t>(s[0]), 1);
            s[0x39] = static_cast<int32_t>(0xbf800000u);
            s[0x3a] = static_cast<int32_t>(0xbf800000u);
            s[0x3b] = static_cast<int32_t>(0xbf800000u);
        }
        if (0 < static_cast<int32_t>(uVar2)) {
            FUN_004e4100(self, static_cast<int32_t>(uVar2));
            FUN_00534130();
            FUN_00534350();
        }
    }
    s[0x3d] = static_cast<int32_t>(uVar2);
}

// 0x4e4550 — observed shape
// Reads the fWaterTexScale tuning value; returns 0 when the key is absent.
long double FUN_004e4550(void)
{
    uint32_t local_4 = 0;
    float* local_8 = nullptr;
    uint8_t cVar1 = FUN_005be240("fWaterTexScale", &local_4, reinterpret_cast<void**>(&local_8));
    if (cVar1 == 0) {
        return 0.0;
    }
    return static_cast<long double>(*local_8);
}

// 0x4e4580 — observed shape
// Sets the water level (self+0x2c) and pushes it into the Y position of the scene
// object at self+0x8, then flushes. Receiver in ECX.
void FUN_004e4580(void* self, int32_t param_1)
{
    char* base = static_cast<char*>(self);
    float fVar2 = static_cast<float>(param_1);
    if (fVar2 == *(float*)(base + 0x2c)) {
        return;
    }
    int32_t iVar1 = *(int32_t*)(base + 8);
    *(float*)(base + 0x2c) = fVar2;
    *(uint32_t*)(iVar1 + 0x5c) = *(uint32_t*)(iVar1 + 0x5c);
    *(uint32_t*)(iVar1 + 0x60) = *(uint32_t*)(iVar1 + 0x60);
    *(float*)(iVar1 + 100) = fVar2;
    FUN_00533d10(0, 0);
}
