// Reconstruction batch mass_0224 — unverified decompiler-derived candidates.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Source: analysis/pseudocode/functions/*.c (Ghidra 12.2 via REA decompile_all).
// No compiler/test run. Register receivers (in_ECX) became explicit `void* self`;
// register leftovers (unaff_EDI / unaff_EBP / unaff_EBX) became explicit params.
// Vtable calls reproduce the argument list printed by the listing (receiver shown
// only where Ghidra printed it).
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

// ---- globals / vtable pointers referenced by these listings ----
extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006c83c4;
extern void* PTR_FUN_006c83c8;
extern void* PTR_FUN_006c824c;
extern void* PTR_FUN_006c8268;
extern void* PTR_FUN_006c8448;
extern void* PTR_FUN_006c84c8;
extern uint32_t DAT_00727444;
extern char DAT_0072799c;

// ---- helpers referenced by these listings ----
extern void FUN_00497420(const char* fmt, ...);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void* FUN_00533c78(size_t size);
extern void* thunk_FUN_00533c78(size_t size);
extern void FUN_00513dc0(void);
extern void FUN_005aead0(int* a, void* b, void** c);
extern void* FUN_0054aad0(void);
extern void* FUN_0054c9c0(uint32_t fmt, uint32_t extra);
extern void FUN_005c20f0(int handle);
extern void FUN_005c2110(int handle);
extern void FUN_005ccdd0(void* self, uint32_t param_1, uint32_t param_2);
extern void FUN_005cce50(void);
extern void* FUN_005cce60(void* a, void* b, void* c);
extern void FUN_005ce8a0(void* self, uint32_t param_1, uint32_t param_2, int* surface);
extern bool FUN_005ce9c0(void* self, void* param_1);
extern void FUN_005cea10(void* self, uint32_t param_1, uint32_t param_2);
extern uint32_t* FUN_005cf2c0(int* param_1);
extern uint32_t* FUN_005cf3d0(int* param_1);
extern void FUN_005d8430(void);
extern char* FUN_005d8450(uint32_t hr);
extern void FUN_005e1490(void);

// ---- vtable plumbing ------------------------------------------------------
static inline void* vtbl_entry(void* obj, uintptr_t offset)
{
    return *reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(obj) + offset);
}

template <typename Fn>
static inline Fn VT(void* obj, uintptr_t offset)
{
    return reinterpret_cast<Fn>(vtbl_entry(obj, offset));
}

// NetImmerse reference counting: count in the second dword, destroying release
// through vtable slot 0 with the delete flag.
static inline void release_ni_ref(void* obj)
{
    if (obj == nullptr) return;
    int32_t* refcount = reinterpret_cast<int32_t*>(static_cast<uint32_t*>(obj) + 1);
    *refcount = *refcount - 1;
    if (*refcount == 0) {
        reinterpret_cast<void(__cdecl*)(int)>(*reinterpret_cast<void**>(obj))(1);
    }
}

static inline void release_ni_object(void* obj)
{
    if (obj != nullptr) {
        reinterpret_cast<void(__cdecl*)(int)>(*reinterpret_cast<void**>(obj))(1);
    }
}

static inline void assign_ni_ref(uint32_t** slot, uint32_t* obj)
{
    uint32_t* old = *slot;
    if (old == obj) return;
    release_ni_ref(old);
    *slot = obj;
    if (obj != nullptr) obj[1] = obj[1] + 1;
}

static inline void reset_ni_ref(uint32_t** slot)
{
    uint32_t* obj = *slot;
    if (obj == nullptr) return;
    int32_t* refcount = reinterpret_cast<int32_t*>(obj + 1);
    *refcount = *refcount - 1;
    if (*refcount == 0) {
        reinterpret_cast<void(__cdecl*)(int)>(*reinterpret_cast<void**>(obj))(1);
    }
    *slot = nullptr;
}

static inline void zero_dwords(uint32_t* p, uint32_t count)
{
    for (; count != 0; --count) { *p = 0; ++p; }
}

// Descriptor used by the NiDX9 buffer-manager paths: the listing reads it back
// with a vtable +0x34 call and compares five dwords.
struct Dx9BufDesc {
    uint32_t format;
    int32_t type;
    int32_t arg0;
    int32_t arg1;
    uint32_t size;
};

// 0x5d09a0 — observed shape
// NiDX9IndexBufferManager::ResizeTempPointConnectivity (log strings preserved).
int* FUN_005d09a0(void* self, int param_1, char param_2, int param_3, int16_t* param_4)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    Dx9BufDesc desc = {0, 0, 0, 0, 0};
    if (*reinterpret_cast<int*>(selfBytes + 8) == 0) return nullptr;
    if (param_1 == 0) return nullptr;
    int* piVar4 = *reinterpret_cast<int**>(selfBytes + 0xc);
    uint32_t uVar5 = static_cast<uint32_t>(param_1) * 0xc;
    if (piVar4 != nullptr) {
        int iVar1 = VT(piVar4, 0x34, int(__cdecl*)(void*, Dx9BufDesc*))(piVar4, &desc);
        if (-1 < iVar1) {
            if (desc.format == 0x65 && desc.type == 7 && desc.arg0 == param_3 &&
                desc.arg1 == static_cast<int32_t>(reinterpret_cast<intptr_t>(param_4)) && uVar5 <= desc.size) {
                if (param_2 == '\0') return piVar4;
                goto LAB_005d0a44;
            }
            VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
        }
    }
    {
        int* created = nullptr;
        void* device = *reinterpret_cast<void**>(selfBytes + 8);
        int iVar1 = VT(device, 0x6c,
                       int(__cdecl*)(void*, uint32_t, int, uint32_t, int16_t*, int**, int))
                    (device, uVar5, param_3, 0x65, param_4, &created, 0);
        if (iVar1 < 0) {
            FUN_00497420("NiDX9IndexBufferManager::CreateIndexBuffer FAILED");
            created = nullptr;
        }
        piVar4 = created;
        if (created == nullptr) {
            FUN_00497420("NiDX9IndexBufferManager::ResizeTempPointConnectivity> "
                         "Failed to create index buffer\n");
            return nullptr;
        }
    }
LAB_005d0a44:
    {
        // Lock writes the writable pointer into the descriptor data slot (the
        // listing passes &param_3, which aliases the descriptor slot).
        int iVar1 = VT(piVar4, 0x2c,
                       int(__cdecl*)(void*, uint32_t, uint32_t, int32_t*, uint32_t))
                    (piVar4, 0, uVar5, &desc.arg1, 0);
        if (iVar1 < 0) {
            FUN_00497420("NiDX9IndexBufferManager::PackBuffer> Failed to lock index buffer\n");
            VT(piVar4, 0x30, int(__cdecl*)(void*))(piVar4);
            VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
            piVar4 = nullptr;
        } else {
            int16_t sVar3 = 0;
            int16_t* dst = reinterpret_cast<int16_t*>(static_cast<intptr_t>(desc.arg1));
            for (; param_1 != 0; param_1 = param_1 + -1) {
                dst[0] = sVar3;
                dst[1] = static_cast<int16_t>(sVar3 + 1);
                dst[2] = static_cast<int16_t>(sVar3 + 2);
                dst[3] = sVar3;
                dst[4] = static_cast<int16_t>(sVar3 + 2);
                dst[5] = static_cast<int16_t>(sVar3 + 3);
                dst = dst + 6;
                sVar3 = static_cast<int16_t>(sVar3 + 4);
            }
            VT(piVar4, 0x30, int(__cdecl*)(void*))(piVar4);
        }
    }
    // Listing stores the buffer and byte size back through the aliased
    // descriptor slots (puVar6[3]/[4]); kept as descriptor updates.
    desc.arg0 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar4));
    desc.arg1 = static_cast<int32_t>(uVar5);
    return piVar4;
}

// 0x5d0b50 — observed shape
// NiDX9IndexBufferManager::ResizeTempLineConnectivity (log strings preserved).
int* FUN_005d0b50(void* self, int param_1, int param_2, int* param_3, char* param_4, int* param_5)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    Dx9BufDesc desc = {0, 0, 0, 0, 0};
    if (*reinterpret_cast<int*>(selfBytes + 8) == 0) return nullptr;
    if ((param_1 == 0) || (param_2 == 0)) return nullptr;
    int* piVar7 = *reinterpret_cast<int**>(selfBytes + 0x14);
    uint32_t uVar5 = static_cast<uint32_t>(param_1) * 4 + 4;   // listing: (short *)(param_1*4+4)
    if (piVar7 != nullptr) {
        int iVar4 = VT(piVar7, 0x34, int(__cdecl*)(void*, Dx9BufDesc*))(piVar7, &desc);
        if (-1 < iVar4) {
            if (desc.format == 0x65 && desc.type == 7 &&
                desc.arg0 == static_cast<int32_t>(reinterpret_cast<intptr_t>(param_4)) &&
                desc.arg1 == static_cast<int32_t>(reinterpret_cast<intptr_t>(param_3)) && uVar5 <= desc.size) {
                goto LAB_005d0bff;
            }
            VT(piVar7, 8, int(__cdecl*)(void*))(piVar7);
        }
    }
    {
        int* created = nullptr;
        void* device = *reinterpret_cast<void**>(selfBytes + 8);
        int iVar4 = VT(device, 0x6c,
                       int(__cdecl*)(void*, uint32_t, char*, uint32_t, int*, int**, int))
                    (device, uVar5, param_4, 0x65, param_3, &created, 0);
        if (iVar4 < 0) {
            FUN_00497420("NiDX9IndexBufferManager::CreateIndexBuffer FAILED");
            created = nullptr;
        }
        piVar7 = created;
        if (created == nullptr) {
            FUN_00497420("NiDX9IndexBufferManager::ResizeTempLineConnectivity> "
                         "Failed to create index buffer\n");
            return nullptr;
        }
    }
LAB_005d0bff:
    {
        const char* pcFlags = reinterpret_cast<const char*>(static_cast<intptr_t>(desc.arg0));
        int16_t* dst;
        *param_3 = 0;
        // Lock writes the writable pointer into the size slot of this descriptor
        // variant (listing passes &param_4 and later reads local_4).
        int iVar4 = VT(piVar7, 0x2c,
                       int(__cdecl*)(void*, uint32_t, uint32_t, uint32_t*, uint32_t))
                    (piVar7, 0, uVar5, &desc.size, 0);
        if (iVar4 < 0) {
            FUN_00497420("NiDX9IndexBufferManager::PackBuffer> Failed to lock index buffer\n");
            VT(piVar7, 0x30, int(__cdecl*)(void*))(piVar7);
            VT(piVar7, 8, int(__cdecl*)(void*))(piVar7);
            piVar7 = nullptr;
        } else {
            uint32_t uVar1 = static_cast<uint32_t>(param_1) - 1;
            uint32_t uVar6 = 0;
            dst = reinterpret_cast<int16_t*>(static_cast<intptr_t>(desc.size));
            if (uVar1 != 0) {
                do {
                    if (*pcFlags != '\0') {
                        dst[1] = static_cast<int16_t>(uVar6 + 1);
                        dst[0] = static_cast<int16_t>(uVar6);
                        dst = dst + 2;
                        *param_3 = *param_3 + 2;
                    }
                    pcFlags = pcFlags + 1;
                    uVar6 = uVar6 + 1;
                } while (uVar6 < uVar1);
            }
            if (*pcFlags != '\0') {
                dst[0] = static_cast<int16_t>(uVar1);
                dst[1] = 0;
                *param_3 = *param_3 + 2;
            }
            VT(piVar7, 0x30, int(__cdecl*)(void*))(piVar7);
        }
    }
    // Listing stores through the aliased argument save area (puVar8[5]/[6]);
    // reconstructed as descriptor updates.
    desc.arg0 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar7));
    desc.arg1 = static_cast<int32_t>(desc.format);
    return piVar7;
}

// 0x5d0d20 — observed shape
void FUN_005d0d20(void* self)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint32_t uVar3 = 0;
    int local_10 = 0;
    if (*reinterpret_cast<uint32_t*>(selfBytes + 0x20) != 0) {
        int* piVar4 = *reinterpret_cast<int**>(selfBytes + 0x24);
        do {
            if (*piVar4 != 0) {
                local_10 = (*reinterpret_cast<int**>(selfBytes + 0x24))[uVar3];
                goto joined_r0x005d0d59;
            }
            uVar3 = uVar3 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar3 < *reinterpret_cast<uint32_t*>(selfBytes + 0x20));
    }
    local_10 = 0;
joined_r0x005d0d59:
    while (local_10 != 0) {
        uint8_t local_4[4];
        void* local_c = nullptr;
        FUN_005aead0(&local_10, local_4, &local_c);
        void* pvVar2 = local_c;
        if (local_c != nullptr) {
            uint32_t* puVar6 =
                reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(local_c) + 8);
            for (int iVar5 = 5; iVar5 != 0; --iVar5) {
                void* pvVar1 = reinterpret_cast<void*>(*puVar6);
                if (pvVar1 != nullptr) {
                    int* piVar4 =
                        *reinterpret_cast<int**>(static_cast<uint8_t*>(pvVar1) + 0x20);
                    if (piVar4 != nullptr) {
                        VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
                    }
                    FUN_005d8430();
                    operator_delete(pvVar1);
                }
                puVar6 = puVar6 + 1;
            }
            operator_delete(pvVar2);
        }
    }
    FUN_005e1490();
    {
        int* piVar4 = *reinterpret_cast<int**>(selfBytes + 0xc);
        if (piVar4 != nullptr) {
            VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
            *reinterpret_cast<uint32_t*>(selfBytes + 0xc) = 0;
        }
        piVar4 = *reinterpret_cast<int**>(selfBytes + 0x14);
        if (piVar4 != nullptr) {
            VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
            *reinterpret_cast<uint32_t*>(selfBytes + 0x14) = 0;
        }
    }
}

// 0x5d0e10 — observed shape
// Constructor: installs PTR_LAB_006fd148, then PTR_FUN_006c83c4 with three
// 0x25-dword sub-object vtable pairs and their 0x94-byte buffers.
void FUN_005d0e10(void* self, int* param_1)
{
    uint32_t* selfD = static_cast<uint32_t*>(self);
    selfD[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_LAB_006fd148));
    selfD[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    selfD[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c83c4));
    {
        selfD[7] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c824c));
        selfD[8] = 0x25;
        selfD[10] = 0;
        uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
        selfD[9] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
        zero_dwords(puVar1, selfD[8] & 0x3fffffff);
        // listing follows with a byte loop whose counter starts at 0 (no iterations)
        selfD[7] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8268));
    }
    {
        selfD[0xb] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c824c));
        selfD[0xc] = 0x25;
        selfD[0xe] = 0;
        uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
        selfD[0xd] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
        zero_dwords(puVar1, selfD[0xc] & 0x3fffffff);
        selfD[0xb] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8268));
    }
    {
        selfD[0xf] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c824c));
        selfD[0x10] = 0x25;
        selfD[0x12] = 0;
        uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
        selfD[0x11] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
        zero_dwords(puVar1, selfD[0x10] & 0x3fffffff);
        selfD[0xf] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8268));
    }
    selfD[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
    VT(param_1, 4, int(__cdecl*)(void*))(param_1);
    selfD[3] = 0;
    selfD[4] = 0;
    selfD[5] = 0;
    selfD[6] = 0;
    FUN_005e1490();
    FUN_005e1490();
    FUN_005e1490();
}

// 0x5d0f30 — observed shape
// Destructor of the 0x5d0e10 object: drains the three bucket tables at
// self+0x1c/+0x2c/+0x3c, then tears down device, buffers and sub-objects.
void FUN_005d0f30(void* self)
{
    uint32_t* selfD = static_cast<uint32_t*>(self);
    selfD[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c83c4));
    for (uint32_t local_c = 0; local_c < 3; ++local_c) {
        uint32_t* local_10 = selfD + 7 + local_c * 4;
        uint32_t uVar3 = 0;
        int* piVar4 = nullptr;
        if (local_10[1] != 0) {
            piVar4 = reinterpret_cast<int*>(local_10[2]);
            do {
                if (*piVar4 != 0) {
                    piVar4 = reinterpret_cast<int**>(static_cast<intptr_t>(local_10[2]))[uVar3];
                    goto joined_r0x005d0fa3;
                }
                uVar3 = uVar3 + 1;
                piVar4 = piVar4 + 1;
            } while (uVar3 < local_10[1]);
        }
        piVar4 = nullptr;
    joined_r0x005d0fa3:
        while (piVar4 != nullptr) {
            int* piVar6 = reinterpret_cast<int*>(*piVar4);
            void* pvVar1 = reinterpret_cast<void*>(static_cast<intptr_t>(piVar4[2]));
            if (piVar6 == nullptr) {
                void* bucket = reinterpret_cast<void*>(static_cast<intptr_t>(*local_10));
                int iVar7 = VT(bucket, 4, int(__cdecl*)(void*, uint32_t))(
                    bucket, static_cast<uint32_t>(piVar4[1]));
                uVar3 = static_cast<uint32_t>(iVar7 + 1);
                if (uVar3 < local_10[1]) {
                    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(local_10[2]) + uVar3 * 4);
                    do {
                        piVar6 = reinterpret_cast<int*>(*puVar5);
                        if (piVar6 != nullptr) goto LAB_005d0ff4;
                        uVar3 = uVar3 + 1;
                        puVar5 = puVar5 + 1;
                    } while (uVar3 < local_10[1]);
                }
                piVar6 = nullptr;
            }
        LAB_005d0ff4:
            piVar4 = piVar6;
            if (pvVar1 != nullptr) {
                uint32_t* puVar5 =
                    reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pvVar1) + 8);
                for (int iVar7 = 5; iVar7 != 0; --iVar7) {
                    void* pvVar2 = reinterpret_cast<void*>(*puVar5);
                    if (pvVar2 != nullptr) {
                        int* piObj =
                            *reinterpret_cast<int**>(static_cast<uint8_t*>(pvVar2) + 0x20);
                        if (piObj != nullptr) {
                            VT(piObj, 8, int(__cdecl*)(void*))(piObj);
                        }
                        FUN_005d8430();
                        operator_delete(pvVar2);
                    }
                    puVar5 = puVar5 + 1;
                }
                operator_delete(pvVar1);
            }
        }
    }
    FUN_005e1490();
    FUN_005e1490();
    FUN_005e1490();
    {
        void* device = reinterpret_cast<void*>(static_cast<intptr_t>(selfD[2]));
        // listing: vtable slot 0x1a0 of self[2] with argument 0
        VT(device, 0x1a0, int(__cdecl*)(void*, int))(device, 0);
    }
    {
        int* piVar4 = reinterpret_cast<int*>(static_cast<intptr_t>(selfD[3]));
        if (piVar4 != nullptr) VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
        piVar4 = reinterpret_cast<int*>(static_cast<intptr_t>(selfD[5]));
        if (piVar4 != nullptr) VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
        piVar4 = reinterpret_cast<int*>(static_cast<intptr_t>(selfD[2]));
        if (piVar4 != nullptr) {
            VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
            selfD[2] = 0;
        }
    }
    selfD[0xf] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8268));
    FUN_005e1490();
    selfD[0xf] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c824c));
    FUN_005e1490();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(selfD[0x11])));
    selfD[0xb] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8268));
    FUN_005e1490();
    selfD[0xb] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c824c));
    FUN_005e1490();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(selfD[0xd])));
    selfD[7] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8268));
    FUN_005e1490();
    selfD[7] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c824c));
    FUN_005e1490();
    operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(selfD[9])));
    selfD[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_LAB_006fd148));
    DAT_00727444 = DAT_00727444 - 1;
}

// 0x5d1150 — observed shape
void FUN_005d1150(void* self, uint8_t param_1)
{
    FUN_005d0f30(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5d1170 — observed shape
void FUN_005d1170(void* self)
{
    uint32_t* selfD = static_cast<uint32_t*>(self);
    int* piVar1 = reinterpret_cast<int*>(static_cast<intptr_t>(selfD[0x1e]));
    selfD[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c83c8));
    if (piVar1 != nullptr) {
        VT(piVar1, 8, int(__cdecl*)(void*))(piVar1);
        selfD[0x1e] = 0;
    }
    if (selfD[0x1f] != 0) {
        void* device = reinterpret_cast<void*>(static_cast<intptr_t>(selfD[2]));
        // listing: vtable slot 0x40 of self[2] with argument 0
        VT(device, 0x40, int(__cdecl*)(void*, int))(device, 0);
    }
    if (selfD[0x1f] != 0) {
        release_ni_object(reinterpret_cast<void*>(static_cast<intptr_t>(selfD[0x1f])));
    }
    selfD[0x1f] = 0;
    FUN_005c2110(static_cast<int>(selfD[1]));
    FUN_005cce50();
}

// 0x5d11d0 — observed shape
uint32_t FUN_005d11d0(void* self)
{
    return *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x78);
}

// 0x5d1220 — observed shape
void FUN_005d1220(void* self, uint32_t param_1, uint32_t param_2)
{
    uint32_t* selfD = static_cast<uint32_t*>(self);
    FUN_005ccdd0(self, param_1, param_2);
    selfD[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c83c8));
    FUN_00513dc0();
    selfD[0x1c] = 0;
    selfD[0x1d] = 0;
    selfD[0x1e] = 0;
    selfD[0x1f] = 0;
}

// 0x5d1260 — observed shape
void FUN_005d1260(void* self, uint8_t param_1)
{
    FUN_005d1170(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5d1280 — observed shape
// NiDX9RenderedTextureData::CreateSurf (log string preserved).
int FUN_005d1280(void* self, int* param_1, int* param_2)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int iVar1;
    int iVar5;
    intptr_t iVar2;
    int* piVar4;
    if (param_1 == nullptr) {
        return 0;
    }
    uint32_t uVar3 = VT(param_1, 0x34, uint32_t(__cdecl*)(void*))(param_1);
    *reinterpret_cast<uint32_t*>(selfBytes + 0x40) = uVar3;
    uVar3 = VT(param_1, 0x38, uint32_t(__cdecl*)(void*))(param_1);
    *reinterpret_cast<uint32_t*>(selfBytes + 0x44) = uVar3;
    *reinterpret_cast<uint32_t*>(selfBytes + 0x48) = 1;
    iVar1 = param_1[8];
    iVar5 = param_1[10];
    iVar2 = *reinterpret_cast<int*>(selfBytes + 8);
    piVar4 = reinterpret_cast<int*>(iVar2 + 0x4a0);
    *param_2 = 0xe;
    if ((iVar5 == 1) || (iVar5 == 2)) {
        if (iVar1 == 1) {
            if (*(int*)(iVar2 + 0x4a4) != 0) {
                *param_2 = 1;
                goto LAB_005d13d4;
            }
            if (*piVar4 != 0) goto LAB_005d13ce;
        }
        if (*(int*)(iVar2 + 0x4b4) != 0) {
            *param_2 = 5;
            goto LAB_005d13d4;
        }
        if (*(int*)(iVar2 + 0x4b0) != 0) {
            *param_2 = 4;
            goto LAB_005d13d4;
        }
        if (*(int*)(iVar2 + 0x4ac) != 0) {
            *param_2 = 3;
            goto LAB_005d13d4;
        }
        if (*(int*)(iVar2 + 0x4a8) != 0) {
            *param_2 = 2;
            goto LAB_005d13d4;
        }
        if (*(int*)(iVar2 + 0x4a4) != 0) {
            *param_2 = 1;
            goto LAB_005d13d4;
        }
        if (*piVar4 == 0) {
            return 0;
        }
    } else {
        if (iVar1 == 1) {
            if (*(int*)(iVar2 + 0x4a4) != 0) {
                *param_2 = 1;
                goto LAB_005d13d4;
            }
            if (*piVar4 != 0) goto LAB_005d13ce;
        }
        if (*(int*)(iVar2 + 0x4a8) != 0) {
            *param_2 = 2;
            goto LAB_005d13d4;
        }
        if (*(int*)(iVar2 + 0x4b4) != 0) {
            *param_2 = 5;
            goto LAB_005d13d4;
        }
        if (*(int*)(iVar2 + 0x4a4) != 0) {
            *param_2 = 1;
            goto LAB_005d13d4;
        }
        if (*piVar4 == 0) {
            if (*(int*)(iVar2 + 0x4b0) == 0) {
                if (*(int*)(iVar2 + 0x4ac) == 0) {
                    return 0;
                }
                *param_2 = 3;
            } else {
                *param_2 = 4;
            }
            goto LAB_005d13d4;
        }
    }
LAB_005d13ce:
    *param_2 = 0;
LAB_005d13d4:
    {
        intptr_t iVar1b = piVar4[*param_2];
        int* piVar4b = *reinterpret_cast<int**>(iVar2 + 0x60);
        int iVar5b = VT(piVar4b, 0x5c,
                        int(__cdecl*)(void*, uint32_t, uint32_t, int, int, uint32_t, int,
                                      void*, int))
                     (piVar4b, *reinterpret_cast<uint32_t*>(selfBytes + 0x40),
                      *reinterpret_cast<uint32_t*>(selfBytes + 0x44), 1, 1,
                      *reinterpret_cast<uint32_t*>(iVar1b + 0x28), 0,
                      selfBytes + 0x78, 0);
        if (iVar5b < 0) {
            char* uVar3b = FUN_005d8450(static_cast<uint32_t>(iVar5b));
            FUN_00497420("NiDX9RenderedTextureData::CreateSurf> Failed CreateImageSurface - %s",
                         uVar3b);
            *reinterpret_cast<uint32_t*>(selfBytes + 0x78) = 0;
            return 0;
        }
        return static_cast<int>(iVar1b);
    }
}

// 0x5d1440 — observed shape
// Factory: allocate 0x80, construct the rendered-texture object, create its
// surface, then build the image object (unaff_EBX/unaff_EBP are register
// inputs of the listing: face index / optional mip source object).
int* FUN_005d1440(int* param_1, int param_2, int unaff_EBX, int* unaff_EBP)
{
    int* piVar1 = static_cast<int*>(FUN_00533c78(0x80));
    if (piVar1 == nullptr) {
        piVar1 = nullptr;
    } else {
        FUN_005ccdd0(piVar1, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1)),
                     static_cast<uint32_t>(param_2));
        piVar1[0] = static_cast<int>(reinterpret_cast<intptr_t>(&PTR_FUN_006c83c8));
        FUN_00513dc0();
        piVar1[0x1c] = 0;
        piVar1[0x1d] = 0;
        piVar1[0x1e] = 0;
        piVar1[0x1f] = 0;
    }
    int local_28[10] = {0};
    local_28[1] = 0xe;
    int iVar2 = FUN_005d1280(piVar1, param_1, local_28 + 1);
    if (iVar2 == 0) {
        if (piVar1 != nullptr) {
            release_ni_object(piVar1);
        }
        return nullptr;
    }
    {
        int* piVar4 = local_28;
        void* device = *reinterpret_cast<void**>(param_2 + 0x60);
        VT(device, 0xa0, int(__cdecl*)(void*))(device);
        if (unaff_EBP == nullptr) {
            local_28[0] = *reinterpret_cast<int*>(param_2 + 0x568 + unaff_EBX * 4);
        } else {
            VT(unaff_EBP, 0x30, int(__cdecl*)(void*, int*))(unaff_EBP, local_28);
            VT(piVar4, 8, int(__cdecl*)(void*))(piVar4);
        }
        uint32_t uVar3 = VT(piVar1, 0x18,
                            uint32_t(__cdecl*)(uint32_t, uint32_t))
                         (static_cast<uint32_t>(local_28[0]),
                          *reinterpret_cast<uint32_t*>(param_2 + 0x60));
        uint32_t* pSurf = FUN_005cf2c0(reinterpret_cast<int*>(static_cast<intptr_t>(uVar3)));
        iVar2 = static_cast<int>(reinterpret_cast<intptr_t>(pSurf));
        piVar1[0x1f] = iVar2;
        if (iVar2 == 0) {
            release_ni_object(piVar1);
            return nullptr;
        }
        *reinterpret_cast<int**>(piVar1[1] + 0x2c) = piVar1;
        return piVar1;
    }
}

// 0x5d1540 — observed shape
void FUN_005d1540(void* self, uint32_t param_1, uint32_t param_2)
{
    uint32_t* selfD = static_cast<uint32_t*>(self);
    FUN_005d1220(self, param_1, param_2);
    selfD[0x20] = 0;
    selfD[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8448));
    selfD[0x21] = 0;
    selfD[0x22] = 0;
    selfD[0x23] = 0;
    selfD[0x24] = 0;
    selfD[0x25] = 0;
    selfD[0x26] = 0;
}

// 0x5d1590 — observed shape
void FUN_005d1590(void* self)
{
    uint32_t* selfD = static_cast<uint32_t*>(self);
    int* piVar2 = reinterpret_cast<int*>(static_cast<intptr_t>(selfD[0x20]));
    selfD[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8448));
    if (piVar2 != nullptr) {
        VT(piVar2, 8, int(__cdecl*)(void*))(piVar2);
        selfD[0x20] = 0;
    }
    uint32_t* slot = selfD + 0x21;
    for (int iVar1 = 6; iVar1 != 0; --iVar1) {
        if (*slot != 0) {
            release_ni_object(reinterpret_cast<void*>(static_cast<intptr_t>(*slot)));
        }
        *slot = 0;
        slot = slot + 1;
    }
    FUN_005c20f0(static_cast<int>(selfD[1]));
    FUN_005d1170(self);
}

// 0x5d1610 — observed shape
void FUN_005d1610(void* self, uint8_t param_1)
{
    FUN_005d1590(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

int FUN_005d1640(void* self, int* param_1);

// 0x5d1640 — observed shape
// NiDX9RenderedCubeMapData::CreateSurf (log string preserved). iVar3 keeps the
// format-block pointer probed by the last condition evaluated.
int FUN_005d1640(void* self, int* param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    if (param_1 != nullptr) {
        uint32_t uVar1 = VT(param_1, 0x34, uint32_t(__cdecl*)(void*))(param_1);
        *reinterpret_cast<uint32_t*>(selfBytes + 0x44) = uVar1;
        *reinterpret_cast<uint32_t*>(selfBytes + 0x40) = uVar1;
        *reinterpret_cast<uint32_t*>(selfBytes + 0x48) = 1;
        intptr_t iVar2 = *reinterpret_cast<int*>(selfBytes + 8);
        int iVar3 = 0;
        if ((param_1[10] == 1) || (param_1[10] == 2)) {
            bool a = (param_1[8] != 1) ||
                     ((iVar3 = *reinterpret_cast<int*>(iVar2 + 0x514), iVar3 == 0) &&
                      (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x510), iVar3 == 0));
            if (a) {
                bool b = (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x524), iVar3 == 0) &&
                         (((iVar3 = *reinterpret_cast<int*>(iVar2 + 0x520), iVar3 == 0) &&
                           (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x51c), iVar3 == 0)) &&
                          (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x518), iVar3 == 0)) &&
                         ((iVar3 = *reinterpret_cast<int*>(iVar2 + 0x514), iVar3 == 0) &&
                          (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x510), iVar3 == 0));
                if (b) return 0;
            }
        } else {
            bool c = (param_1[8] != 1) ||
                     ((iVar3 = *reinterpret_cast<int*>(iVar2 + 0x514), iVar3 == 0) &&
                      (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x510), iVar3 == 0));
            if (c) {
                if ((iVar3 = *reinterpret_cast<int*>(iVar2 + 0x518), iVar3 == 0)) {
                    bool d = (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x524), iVar3 == 0) &&
                             (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x514), iVar3 == 0) &&
                             (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x510), iVar3 == 0) &&
                             ((iVar3 = *reinterpret_cast<int*>(iVar2 + 0x520), iVar3 == 0) &&
                              (iVar3 = *reinterpret_cast<int*>(iVar2 + 0x51c), iVar3 == 0));
                    if (d) return 0;
                }
            }
        }
        int* device = *reinterpret_cast<int**>(iVar2 + 0x60);
        int iVar2b = VT(device, 100,
                        int(__cdecl*)(void*, uint32_t, int, int, uint32_t, int, void*, int))
                     (device, uVar1, 1, 1,
                      *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(iVar3) + 0x28), 0,
                      selfBytes + 0x80, 0);
        if (-1 < iVar2b) {
            return iVar3;
        }
        char* uVar1b = FUN_005d8450(static_cast<uint32_t>(iVar2b));
        FUN_00497420("NiDX9RenderedCubeMapData::CreateSurf> Failed CreateImageSurface - %s",
                     uVar1b);
        *reinterpret_cast<uint32_t*>(selfBytes + 0x80) = 0;
    }
    return 0;
}

// 0x5d17a0 — observed shape
int* FUN_005d17a0(uint32_t param_1, int param_2)
{
    int* piVar2;
    intptr_t iVar1 = reinterpret_cast<intptr_t>(FUN_00533c78(0x9c));
    if (iVar1 == 0) {
        piVar2 = nullptr;
    } else {
        FUN_005d1540(reinterpret_cast<void*>(iVar1), param_1,
                     static_cast<uint32_t>(param_2));
        piVar2 = reinterpret_cast<int*>(iVar1);
    }
    int iVar1b = FUN_005d1640(piVar2, reinterpret_cast<int*>(static_cast<intptr_t>(param_1)));
    if (iVar1b == 0) {
        if (piVar2 != nullptr) {
            release_ni_object(piVar2);
        }
        return nullptr;
    }
    uint32_t uVar3 = VT(piVar2, 0x18, uint32_t(__cdecl*)(uint32_t, uint32_t, uint32_t))
                     (0, 0, *reinterpret_cast<uint32_t*>(param_2 + 0x60));
    uint32_t* puFace = FUN_005cf3d0(reinterpret_cast<int*>(static_cast<intptr_t>(uVar3)));
    int iVar1c = static_cast<int>(reinterpret_cast<intptr_t>(puFace));
    piVar2[0x21] = iVar1c;
    if (puFace == nullptr) {
        release_ni_object(piVar2);
        return nullptr;
    }
    uint32_t uVar6 = 1;
    int* piVar5 = piVar2 + 0x22;
    do {
        uVar3 = VT(piVar2, 0x18, uint32_t(__cdecl*)(uint32_t, uint32_t, uint32_t))
                (uVar6, static_cast<uint32_t>(iVar1c),
                 *reinterpret_cast<uint32_t*>(param_2 + 0x60));
        uint32_t* iVar4 = FUN_005cf3d0(reinterpret_cast<int*>(static_cast<intptr_t>(uVar3)));
        *piVar5 = reinterpret_cast<int>(iVar4);
        if (iVar4 == nullptr) {
            release_ni_object(piVar2);
            return nullptr;
        }
        uVar6 = uVar6 + 1;
        piVar5 = piVar5 + 1;
    } while (uVar6 < 6);
    *reinterpret_cast<int**>(piVar2[1] + 0x2c) = piVar2;
    return piVar2;
}

// 0x5d18e0 — observed shape
// Copies one face level into the destination surface.
// NEEDS_MANUAL: the destination surface arrives in unaff_EDI in the listing; it
// is not visible at either call site and is taken as an explicit parameter.
void FUN_005d18e0(void* self, uint32_t param_1, uint32_t param_2, int* surface)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint32_t uVar3 = 0;
    if (*reinterpret_cast<int*>(selfBytes + 0x48) != 0) {
        while (true) {
            int* obj = *reinterpret_cast<int**>(selfBytes + 0x68);
            int iVar1 = VT(obj, 0x48,
                           int(__cdecl*)(void*, uint32_t, uint32_t, uint32_t*))
                        (obj, param_2, uVar3, &param_2);
            if (iVar1 < 0) break;
            FUN_005ce8a0(self, param_1, uVar3, surface);
            VT(surface, 8, int(__cdecl*)(void*))(surface);
            uVar3 = uVar3 + 1;
            if (*reinterpret_cast<uint32_t*>(selfBytes + 0x48) <= uVar3) {
                return;
            }
        }
        char* uVar2 = FUN_005d8450(static_cast<uint32_t>(iVar1));
        FUN_00497420("NiDX9SourceCubeMapData::CopyDataToSurface> Failed GetSurfaceLevel (%d)- %s",
                     uVar3, uVar2);
        int* obj = *reinterpret_cast<int**>(selfBytes + 0x68);
        VT(obj, 8, int(__cdecl*)(void*))(obj);
    }
}

// 0x5d1960 — observed shape (non-contiguous: 0x5d1960-0x5d1c88 and
// 0x5d1c90-0x5d1fc6; the 0x5d1c88-0x5d1c90 gap is not in the listing).
// NiDX9SourceCubeMapData::Create (log strings preserved).
uint32_t* FUN_005d1960(uint32_t param_1, uint32_t param_2)
{
    intptr_t arg1 = static_cast<intptr_t>(param_1);
    intptr_t arg2 = static_cast<intptr_t>(param_2);
    intptr_t local_40_1 = arg2 + 0x4d8;   // format list; later reused as vtable slot
    uint32_t uVar4 = 0;
    do {
        if (*reinterpret_cast<int*>(local_40_1 + uVar4 * 4) != 0) break;
        if (*reinterpret_cast<int*>(arg2 + 0x4dc + uVar4 * 4) != 0) {
            uVar4 = uVar4 + 1;
            break;
        }
        uVar4 = uVar4 + 2;
    } while (uVar4 < 0xe);
    if (uVar4 == 0xe) {
        FUN_00497420("NiDX9SourceCubeMapData::Create> No Cube Map texture formats supported\n");
        return nullptr;
    }
    uint32_t* puVar5 = static_cast<uint32_t*>(FUN_00533c78(0x84));
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    } else {
        FUN_005cea10(puVar5, param_1, param_2);
        *puVar5 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c84c8));
        puVar5[0x1a] = 0;
        puVar5[0x1b] = 0;
        puVar5[0x1c] = 0;
        puVar5[0x1d] = 0;
        puVar5[0x1e] = 0;
        puVar5[0x1f] = 0;
        puVar5[0x20] = 0;
    }
    int iVar12 = 0;
    uint32_t* local_48 = puVar5 + 0x1b;
    intptr_t local_4c = arg1 + 0x7c;
    uint32_t local_30[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    intptr_t local_40_0 = 0;   // first face record base
    int local_44 = 0;
    bool bVar3 = false;
    char acStack_38[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (uVar4 = 0; ; ) {
        // ---- reset slot uVar4 ----
        acStack_38[uVar4] = '\0';
        reset_ni_ref(reinterpret_cast<uint32_t**>(&local_30[uVar4]));
        {
            int iVar11 = *reinterpret_cast<int*>(local_4c - 6 * 4);
            uint32_t* puVar7;
            bool assignNew;
            if (iVar11 == 0) {
                puVar7 = *reinterpret_cast<uint32_t**>(local_4c);
                assignNew = local_30[uVar4] != static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar7));
            } else {
                int* piVar6 = static_cast<int*>(FUN_0054aad0());
                puVar7 = static_cast<uint32_t*>(
                    VT(piVar6, 8, void*(__cdecl*)(void*, uint32_t, uint32_t))(
                        piVar6, static_cast<uint32_t>(iVar11), 0));
                assignNew = local_30[uVar4] != static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar7));
            }
            if (assignNew) {
                release_ni_ref(reinterpret_cast<void*>(static_cast<intptr_t>(local_30[uVar4])));
                local_30[uVar4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar7));
                if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
            }
        }
        // ---- fall back to the default format when nothing was resolved ----
        if (local_30[uVar4] == 0) {
            uint32_t* puVar8 = static_cast<uint32_t*>(FUN_0054c9c0(0x80000005, 1));
            uint32_t* puVar7 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(local_30[uVar4]));
            if (puVar7 != puVar8) {
                release_ni_ref(puVar7);
                local_30[uVar4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar8));
                if (puVar8 != nullptr) puVar8[1] = puVar8[1] + 1;
            }
            acStack_38[uVar4] = '\x01';
            bVar3 = true;
        }
        {
            intptr_t iVar11 = static_cast<intptr_t>(local_30[uVar4]);
            *local_48 = *reinterpret_cast<uint32_t*>(iVar11 + 0x4c);
            if (iVar12 == 0) {
                uint32_t uVar2 = 0;
                bool bad = (**reinterpret_cast<int**>(iVar11 + 0x38) !=
                            **reinterpret_cast<int**>(iVar11 + 0x3c));
                if (!bad) {
                    uVar2 = **reinterpret_cast<uint32_t**>(iVar11 + 0x38);
                    bad = (uVar2 == 0);
                }
                if (!bad) {
                    bad = (((uVar2 - 1) & uVar2) != 0);
                }
                if (bad) {
                    uint32_t* puVar8 = static_cast<uint32_t*>(FUN_0054c9c0(0x80000006, 1));
                    uint32_t* puVar7 = reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(local_30[uVar4]));
                    if (puVar7 != puVar8) {
                        release_ni_ref(puVar7);
                        local_30[uVar4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar8));
                        if (puVar8 != nullptr) puVar8[1] = puVar8[1] + 1;
                    }
                    acStack_38[uVar4] = '\x01';
                    bVar3 = true;
                }
                local_44 = *reinterpret_cast<int*>(static_cast<intptr_t>(local_30[uVar4]) + 0x44);
                iVar12 = **reinterpret_cast<int**>(static_cast<intptr_t>(local_30[uVar4]) + 0x38);
            } else if ((iVar12 != **reinterpret_cast<int**>(iVar11 + 0x38)) ||
                       (iVar12 != **reinterpret_cast<int**>(iVar11 + 0x3c)) ||
                       (local_44 != *reinterpret_cast<int*>(iVar11 + 0x44))) {
                uint32_t* puVar8 = static_cast<uint32_t*>(FUN_0054c9c0(0x80000006, 1));
                uint32_t* puVar7 = reinterpret_cast<uint32_t*>(
                    static_cast<intptr_t>(local_30[uVar4]));
                if (puVar7 != puVar8) {
                    release_ni_ref(puVar7);
                    local_30[uVar4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar8));
                    if (puVar8 != nullptr) puVar8[1] = puVar8[1] + 1;
                }
                acStack_38[uVar4] = '\x01';
                bVar3 = true;
            }
        }
        {
            intptr_t iVar11 = static_cast<intptr_t>(local_30[uVar4]);
            if (local_40_0 == 0) {
                local_40_0 = iVar11 + 0xc;
            } else if ((*reinterpret_cast<int*>(local_40_0 + 0x1c) !=
                        *reinterpret_cast<int*>(iVar11 + 0x28)) ||
                       (*reinterpret_cast<int*>(local_40_0 + 0x20) !=
                        *reinterpret_cast<int*>(iVar11 + 0x2c))) {
                uint32_t* puVar8 = static_cast<uint32_t*>(FUN_0054c9c0(0x80000002, 1));
                uint32_t* puVar7 = reinterpret_cast<uint32_t*>(
                    static_cast<intptr_t>(local_30[uVar4]));
                if (puVar7 != puVar8) {
                    release_ni_ref(puVar7);
                    local_30[uVar4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar8));
                    if (puVar8 != nullptr) puVar8[1] = puVar8[1] + 1;
                }
                acStack_38[uVar4] = '\x01';
                bVar3 = true;
            }
        }
        uVar4 = uVar4 + 1;
        local_4c = local_4c + 4;
        local_48 = local_48 + 1;
        if (5 < uVar4) {
            // ---- all six faces inspected: build the cube map object ----
            uint32_t* puVar7 = static_cast<uint32_t*>(
                FUN_005cce60(reinterpret_cast<void*>(static_cast<intptr_t>(local_30[0]) + 0xc),
                             reinterpret_cast<void*>(arg1 + 0x20),
                             reinterpret_cast<void*>(local_40_1)));
            if (puVar7 == nullptr) {
                memcpy(acStack_38, "\x01\x01\x01\x01\x01\x01", 6);
                uVar4 = 0;
                bVar3 = true;
                do {
                    uint32_t* puVar8 = static_cast<uint32_t*>(FUN_0054c9c0(0x80000002, 1));
                    uint32_t* puVar7b = reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(local_30[uVar4]));
                    if (puVar7b != puVar8) {
                        release_ni_ref(puVar7b);
                        local_30[uVar4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar8));
                        if (puVar8 != nullptr) puVar8[1] = puVar8[1] + 1;
                    }
                    uVar4 = uVar4 + 1;
                } while (uVar4 < 6);
                puVar7 = *reinterpret_cast<uint32_t**>(
                    arg2 + 0x468 + *reinterpret_cast<int*>(arg2 + 0x5a0) * 4);
            }
            if ((*reinterpret_cast<int*>(arg1 + 0x24) == 1) ||
                (((*reinterpret_cast<int*>(arg1 + 0x24) == 2) && (DAT_0072799c != '\0')) &&
                 (*reinterpret_cast<char*>(arg2 + 0x460) != '\0'))) {
                *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(puVar5) + 0x4c) = 1;
            } else {
                *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(puVar5) + 0x4c) = 0;
            }
            puVar5[0xd] = puVar7[10];
            {
                uint32_t* puVar8 = puVar7;
                uint32_t* puVar9 = puVar5 + 3;
                for (int iVar11 = 9; iVar11 != 0; --iVar11) {
                    *puVar9 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar9 = puVar9 + 1;
                }
            }
            puVar5[0x11] = static_cast<uint32_t>(iVar12);
            puVar5[0x10] = static_cast<uint32_t>(iVar12);
            local_30[6] = 0;
            local_30[7] = 0;
            local_30[8] = 0;
            local_30[9] = 0;
            local_30[10] = 0;
            local_30[11] = 0;
            uVar4 = 0;
            do {
                if (acStack_38[uVar4] == '\0') {
                    int* piVar6 = static_cast<int*>(FUN_0054aad0());
                    void* vtable = *reinterpret_cast<void**>(piVar6);
                    void* createFn = *reinterpret_cast<void**>(
                        static_cast<uint8_t*>(vtable) + 0x10);
                    uint32_t* puVar9 = static_cast<uint32_t*>(
                        reinterpret_cast<void*(__cdecl*)(uint32_t, void*, uint32_t, uint8_t)>(
                            createFn))(
                            local_30[uVar4], puVar7, local_30[uVar4],
                            *reinterpret_cast<uint8_t*>(
                                reinterpret_cast<uint8_t*>(puVar5) + 0x4c));
                    uint32_t* puVar8 = reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(local_30[uVar4 + 6]));
                    if (puVar8 != puVar9) {
                        release_ni_ref(puVar8);
                        local_30[uVar4 + 6] =
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar9));
                        if (puVar9 != nullptr) puVar9[1] = puVar9[1] + 1;
                    }
                    if (local_30[uVar4 + 6] == 0) {
                        uint32_t* puVar9b = static_cast<uint32_t*>(FUN_0054c9c0(0x80000004, 1));
                        uint32_t* puVar8b = reinterpret_cast<uint32_t*>(
                            static_cast<intptr_t>(local_30[uVar4 + 6]));
                        if (puVar8b != puVar9b) {
                            release_ni_ref(puVar8b);
                            local_30[uVar4 + 6] =
                                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar9b));
                            if (puVar9b != nullptr) puVar9b[1] = puVar9b[1] + 1;
                        }
                        acStack_38[uVar4] = '\x01';
                        bVar3 = true;
                    }
                    puVar5[0x14] =
                        puVar5[0x14] +
                        *reinterpret_cast<int*>(
                            static_cast<intptr_t>(*reinterpret_cast<int*>(
                                static_cast<intptr_t>(local_30[uVar4 + 6]) + 0x40)) +
                            *reinterpret_cast<int*>(
                                static_cast<intptr_t>(local_30[uVar4 + 6]) + 0x44) * 4);
                } else {
                    uint32_t* puVar8 = reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(local_30[uVar4 + 6]));
                    uint32_t* puVar9 = reinterpret_cast<uint32_t*>(
                        static_cast<intptr_t>(local_30[uVar4]));
                    if (puVar8 != puVar9) {
                        release_ni_ref(puVar8);
                        local_30[uVar4 + 6] =
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar9));
                        if (puVar9 != nullptr) puVar9[1] = puVar9[1] + 1;
                    }
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < 6);
            if (bVar3) {
                uVar4 = 0;
                do {
                    if (acStack_38[uVar4] == '\0') {
                        uint32_t* puVar8 = static_cast<uint32_t*>(FUN_0054c9c0(0x80000002, 1));
                        uint32_t* puVar7c = reinterpret_cast<uint32_t*>(
                            static_cast<intptr_t>(local_30[uVar4 + 6]));
                        if (puVar7c != puVar8) {
                            release_ni_ref(puVar7c);
                            local_30[uVar4 + 6] =
                                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar8));
                            if (puVar8 != nullptr) puVar8[1] = puVar8[1] + 1;
                        }
                    }
                    uVar4 = uVar4 + 1;
                } while (uVar4 < 6);
                puVar5[0x14] =
                    *reinterpret_cast<int*>(
                        static_cast<intptr_t>(*reinterpret_cast<int*>(
                            static_cast<intptr_t>(local_30[6]) + 0x40)) +
                        *reinterpret_cast<int*>(static_cast<intptr_t>(local_30[6]) + 0x44) * 4) * 6;
            }
            uint32_t uVar10;
            if (*reinterpret_cast<char*>(arg2 + 0x460) == '\0') {
                uVar10 = 1;
            } else {
                uVar10 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(local_30[6]) + 0x44);
            }
            uint32_t* piVar6 = puVar5 + 0x1a;
            puVar5[0x12] = uVar10;
            {
                void* device = *reinterpret_cast<void**>(static_cast<intptr_t>(puVar5[2]) + 0x60);
                int iVar12b = VT(device, 100,
                                 int(__cdecl*)(void*, uint32_t, uint32_t, int, uint32_t, int,
                                               uint32_t*, int))
                              (device, puVar5[0x10], uVar10, 0, puVar5[0xd], 1, piVar6, 0);
                if (iVar12b < 0) {
                    char* uVar10b = FUN_005d8450(static_cast<uint32_t>(iVar12b));
                    FUN_00497420(
                        "NiDX9SourceCubeMapData::CreateSurf> Failed CreateImageSurface - %s\n",
                        uVar10b);
                    *piVar6 = 0;
                }
            }
            if (*piVar6 != 0) {
                uVar4 = 0;
                do {
                    // listing reads the face source through the aliased flags
                    // slot (acStack_38 + uVar4*4); it is the per-face surface.
                    // NEEDS_MANUAL: in_EDI destination surface is not visible here.
                    FUN_005d18e0(puVar5, local_30[uVar4 + 6], uVar4, nullptr);
                    uVar4 = uVar4 + 1;
                } while (uVar4 < 6);
                FUN_005ce9c0(puVar5, reinterpret_cast<void*>(
                                         static_cast<intptr_t>(puVar5[0xc])));
                *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(puVar5[1]) + 0x2c) = puVar5;
                // Two six-slot release loops; the listing's pointer arithmetic
                // aliases local_30[0..5] and local_30[6..11].
                for (int i = 5; i >= 0; --i) {
                    reset_ni_ref(reinterpret_cast<uint32_t**>(&local_30[i]));
                }
                for (int i = 11; i >= 6; --i) {
                    reset_ni_ref(reinterpret_cast<uint32_t**>(&local_30[i]));
                }
                return puVar5;
            }
            release_ni_object(puVar5);
            for (int i = 5; i >= 0; --i) {
                reset_ni_ref(reinterpret_cast<uint32_t**>(&local_30[i]));
            }
            for (int i = 11; i >= 6; --i) {
                reset_ni_ref(reinterpret_cast<uint32_t**>(&local_30[i]));
            }
            return nullptr;
        }
    }
}

// 0x5d1fd0 — observed shape
// Refreshes the six face surfaces when their format no longer matches.
void FUN_005d1fd0(void* self)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int* local_4 = reinterpret_cast<int*>(
        static_cast<intptr_t>(*reinterpret_cast<int*>(selfBytes + 4)) + 0x7c);
    bool bVar2 = false;
    uint32_t uVar7 = 0;
    int* piVar4 = local_4;
    do {
        if (*piVar4 != 0) {
            char cVar3 = FUN_005ce9c0(
                self, reinterpret_cast<void*>(static_cast<intptr_t>(
                          *reinterpret_cast<int*>(static_cast<intptr_t>(*piVar4) + 0x30))));
            if (cVar3 != '\0') {
                bVar2 = true;
            }
            break;
        }
        uVar7 = uVar7 + 1;
        piVar4 = piVar4 + 1;
    } while (uVar7 < 6);
    uint32_t local_8 = 0;
    piVar4 = reinterpret_cast<int*>(selfBytes + 0x6c);
    do {
        intptr_t iVar1 = static_cast<intptr_t>(*local_4);
        if ((iVar1 != 0) &&
            ((*reinterpret_cast<int*>(iVar1 + 0x4c) != *piVar4) || bVar2)) {
            int* piVar5 = static_cast<int*>(FUN_0054aad0());
            void* puVar6 = VT(piVar5, 0x10,
                              void*(__cdecl*)(int, void*, int, uint8_t))(
                               static_cast<int>(iVar1),
                               reinterpret_cast<void*>(selfBytes + 0xc),
                               static_cast<int>(iVar1),
                               *reinterpret_cast<uint8_t*>(selfBytes + 0x4c));
            *piVar4 = *reinterpret_cast<int*>(iVar1 + 0x4c);
            if (*reinterpret_cast<int*>(selfBytes + 0x68) != 0) {
                // NEEDS_MANUAL: in_EDI destination surface is not visible here.
                FUN_005d18e0(self, reinterpret_cast<uint32_t>(
                                       reinterpret_cast<uintptr_t>(puVar6)),
                             local_8, nullptr);
            }
            if (puVar6 != nullptr) {
                // Temporary reference bump/drop observed in the listing.
                int iVar1b = reinterpret_cast<int*>(puVar6)[1];
                reinterpret_cast<int*>(puVar6)[1] = iVar1b + 1;
                reinterpret_cast<int*>(puVar6)[1] = iVar1b;
                if (iVar1b == 0) {
                    release_ni_object(puVar6);
                }
            }
        }
        local_8 = local_8 + 1;
        local_4 = local_4 + 1;
        piVar4 = piVar4 + 1;
    } while (local_8 < 6);
}
