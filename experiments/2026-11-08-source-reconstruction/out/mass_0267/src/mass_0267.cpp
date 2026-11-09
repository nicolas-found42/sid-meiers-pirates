// Reconstruction batch mass_0267 — Sid Meier's Pirates! (2004) PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_006011da(void* param_1, uint32_t param_2, uint32_t param_3);
extern void* FUN_00600136(void* p);
extern void* FUN_0060164a(void* p);
extern void FUN_00601966(void* p);
extern void* PTR_FUN_006ddeec;
extern void* PTR_FUN_006ddefc;
extern void* PTR_FUN_006ddf0c;
extern void* PTR_FUN_006ddf1c;
extern void* PTR_FUN_006ddf2c;
extern void* PTR_FUN_006ddf3c;
extern void* PTR_FUN_006ddf4c;
extern void* PTR_FUN_006ddf5c;
extern void* PTR_FUN_006ddf6c;
extern void* PTR_FUN_006ddf7c;
extern void* PTR_FUN_006ddf8c;
extern void* PTR_FUN_006ddf9c;
extern void* PTR_FUN_006ddfac;
extern void* PTR_FUN_006ddfbc;
extern void* PTR_FUN_006ddfcc;
extern void* PTR_FUN_006ddfe0;
extern void* PTR_FUN_006ddff0;

// 0x606368 — observed shape: alloc(vtable init 0x10, flag 1), set vptr
void FUN_00606368(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x10, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddeec;
}

// 0x606389 — observed shape: DPCM renderer, 3-channel (RGB-ish), bayer dither, serpentine
void FUN_00606389(void* self, uint32_t param_1, uint32_t param_2, float* param_3) {
    char* obj = static_cast<char*>(self);
    auto get32 = [&](int off) -> int32_t {
        int32_t v; __builtin_memcpy(&v, obj + off, 4); return v;
    };
    auto set32 = [&](int off, uint32_t v) {
        __builtin_memcpy(obj + off, &v, 4);
    };
    float* p3 = param_3;
    if (get32(0x54) != 0) {
        p3 = static_cast<float*>(FUN_00600136(p3));
    }
    if (get32(0x10) != 0) {
        p3 = static_cast<float*>(FUN_0060164a(p3));
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_48 = 0.0f;
    uint32_t uVar7 = param_1 & 3;
    uint32_t uVar9 = param_2 & 3;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>(
        static_cast<intptr_t>(get32(0x60)) * static_cast<intptr_t>(param_1) +
        (static_cast<intptr_t>(get32(0x68)) - 1) * static_cast<intptr_t>(param_1 & 1) * 4 +
        static_cast<intptr_t>(get32(100)) * static_cast<intptr_t>(param_2) +
        static_cast<intptr_t>(get32(0x20)));
    int32_t iVar3 = get32(0x34);
    int32_t iVar13, iVar14;
    int32_t dirParam2;
    if ((param_1 & 1) == 0) {
        iVar13 = 0;
        iVar14 = 1;
        dirParam2 = 1;
    } else {
        iVar13 = get32(0x68) - 1;
        dirParam2 = -1;
        iVar14 = -1;
    }
    // FPU control word
    uint16_t* fpuCW = reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(0));
    (void)fpuCW;
    *(obj + 0x7c) = 0; // placeholder for in_FPUControlWord; preserved field offset
    if (get32(0x5c) != 0) {
        FUN_00601966(p3);
    }
    uint32_t counter = 0;
    if (get32(0x68) != 0) {
        int32_t iVar10 = iVar14 * 0x10;
        int32_t iVar8 = iVar13 * 0x10;
        float* src = reinterpret_cast<float*>(static_cast<intptr_t>(iVar8) + 0x0c + reinterpret_cast<intptr_t>(p3));
        int32_t iVar15 = (iVar14 + iVar13) * 0x10;
        iVar13 = (iVar13 - dirParam2) * 0x10;
        do {
            float fVar2 = *reinterpret_cast<float*>(
                static_cast<intptr_t>(iVar3) +
                static_cast<intptr_t>(uVar9 + uVar7 * 8) * 4 +
                static_cast<intptr_t>(counter & 3) * 4);
            float fVar4 = (local_54 + src[-3]) * 127.0f;
            float fVar5 = (local_50 + src[-2]) * 127.0f;
            float fVar6 = (local_48 + src[0]) * 255.0f;
            uint32_t local_34 = static_cast<uint32_t>(ROUND(fVar4 + fVar2));
            uint32_t local_30 = static_cast<uint32_t>(ROUND(fVar5 + fVar2));
            int32_t local_28 = static_cast<int32_t>(ROUND(fVar6 + fVar2));
            if (get32(0x5c) != 0) {
                float* pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x10 + iVar13);
                local_54 = (fVar4 - static_cast<float>(static_cast<int32_t>(local_34))) * 0.007874016f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x10 + iVar15);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x14 + iVar13);
                local_50 = (fVar5 - static_cast<float>(static_cast<int32_t>(local_30))) * 0.007874016f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x14 + iVar15);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x1c + iVar13);
                local_48 = (fVar6 - static_cast<float>(local_28)) * 0.003921569f;
                *pfVar1 = local_48 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x1c + iVar8);
                *pfVar1 = local_48 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(static_cast<intptr_t>(get32(0x5c)) + 0x1c + iVar15);
                *pfVar1 = local_48 * 0.0625f + *pfVar1;
                local_48 = local_48 * 0.4375f;
            }
            uint32_t uVar11 = local_34;
            if (0x7e < static_cast<int32_t>(local_34)) uVar11 = 0x7f;
            if (static_cast<int32_t>(uVar11) < -0x7e) local_34 = 0xffffff81;
            else if (0x7e < static_cast<int32_t>(local_34)) local_34 = 0x7f;
            uVar11 = local_30;
            if (0x7e < static_cast<int32_t>(local_30)) uVar11 = 0x7f;
            if (static_cast<int32_t>(uVar11) < -0x7e) local_30 = 0xffffff81;
            else if (0x7e < static_cast<int32_t>(local_30)) local_30 = 0x7f;
            int32_t iVar12 = local_28;
            if (0xfe < local_28) iVar12 = 0xff;
            if (iVar12 < -0xfe) local_28 = -0xff;
            else if (0xfe < local_28) local_28 = 0xff;
            *local_8 = (static_cast<uint32_t>(static_cast<uint8_t>(local_28)) << 16 |
                        static_cast<uint32_t>(static_cast<uint8_t>(local_30)) << 8) |
                       (local_34 & 0xff);
            local_8 += iVar14;
            src += iVar14 * 4;
            iVar8 += iVar10;
            iVar13 += iVar10;
            iVar15 += iVar10;
            counter++;
        } while (counter < static_cast<uint32_t>(get32(0x68)));
    }
}

// 0x6066a2 — observed shape: alloc(vtable init 0x20, flag 1), set vptr
void FUN_006066a2(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x20, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddefc;
}

// 0x6066c3 — observed shape: alloc(vtable init 0x20, flag 1), set vptr
void FUN_006066c3(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x20, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf0c;
}

// 0x6066e4 — observed shape: alloc(vtable init 0x20, flag 1), set vptr
void FUN_006066e4(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x20, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf1c;
}
// 0x606705 — observed shape: alloc(vtable init 0x20, flag 1), set vptr
void FUN_00606705(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x20, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf2c;
}

// 0x606726 — observed shape: alloc(vtable init 0x20, flag 1), set vptr
void FUN_00606726(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x20, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf3c;
}

// 0x606747 — observed shape: alloc(vtable init 0x40, flag 1), set vptr
void FUN_00606747(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x40, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf4c;
}

// 0x606768 — observed shape: alloc(vtable init 0x10, flag 1), set vptr
void FUN_00606768(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x10, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf5c;
}

// 0x606789 — observed shape: DPCM renderer, 4-channel (RGBA-ish), bayer dither, serpentine
void FUN_00606789(void* self, uint32_t param_1, float* param_2, int32_t param_3) {
    char* obj = static_cast<char*>(self);
    auto get32 = [&](int off) -> int32_t {
        int32_t v; __builtin_memcpy(&v, obj + off, 4); return v;
    };
    int32_t p3 = param_3;
    if (get32(0x54) != 0) p3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00600136(reinterpret_cast<void*>(static_cast<intptr_t>(p3)))));
    if (get32(0x10) != 0) p3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_0060164a(reinterpret_cast<void*>(static_cast<intptr_t>(p3)))));
    float local_58 = 0.0f, local_54 = 0.0f, local_50 = 0.0f, local_4c = 0.0f;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>((intptr_t)get32(0x60) * (intptr_t)param_1 + ((intptr_t)get32(0x68) - 1) * (intptr_t)(param_1 & 1) * 4 + (intptr_t)get32(100) * (intptr_t)(intptr_t)param_2 + (intptr_t)get32(0x20));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar12 = (uint32_t)(intptr_t)param_2 & 3;
    int32_t iVar3 = get32(0x34);
    int32_t iVar16, iVar13;
    if ((param_1 & 1) == 0) { iVar16 = 0; iVar13 = 1; }
    else { iVar16 = get32(0x68) - 1; iVar13 = -1; }
    *(obj + 0x7c) = 0;
    if (get32(0x5c) != 0) FUN_00601966(reinterpret_cast<void*>(static_cast<intptr_t>(p3)));
    uint32_t counter = 0;
    if (get32(0x68) != 0) {
        int32_t iVar10 = iVar13 * 0x10;
        int32_t iVar9 = iVar16 * 0x10;
        float* src = reinterpret_cast<float*>(static_cast<intptr_t>(iVar9) + 8 + p3);
        int32_t iVar11 = (iVar13 + iVar16) * 0x10;
        iVar16 = (iVar16 - iVar13) * 0x10;
        do {
            float fVar2 = *reinterpret_cast<float*>((intptr_t)iVar3 + (intptr_t)(uVar12 + uVar8 * 8) * 4 + (intptr_t)(counter & 3) * 4);
            float fVar4 = (local_58 + src[-2]) * 127.0f;
            float fVar5 = (local_54 + src[-1]) * 127.0f;
            float fVar6 = (local_50 + src[0]) * 127.0f;
            float fVar7 = (local_4c + src[1]) * 127.0f;
            uint32_t local_38 = (uint32_t)ROUND(fVar4 + fVar2);
            uint32_t local_34 = (uint32_t)ROUND(fVar5 + fVar2);
            uint32_t uVar17 = (uint32_t)ROUND(fVar6 + fVar2);
            int32_t iVar18 = (int32_t)ROUND(fVar7 + fVar2);
            if (get32(0x5c) != 0) {
                float* pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x10 + iVar16);
                local_58 = (fVar4 - (float)(int32_t)local_38) * 0.007874016f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x10 + iVar9);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x10 + iVar11);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x14 + iVar16);
                local_54 = (fVar5 - (float)(int32_t)local_34) * 0.007874016f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x14 + iVar9);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x14 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x18 + iVar16);
                local_50 = (fVar6 - (float)(int32_t)uVar17) * 0.007874016f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x18 + iVar9);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x18 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x1c + iVar16);
                local_4c = (fVar7 - (float)iVar18) * 0.007874016f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x1c + iVar9);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>((intptr_t)get32(0x5c) + 0x1c + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t uVar14 = local_38;
            if (0x7e < (int32_t)local_38) uVar14 = 0x7f;
            if ((int32_t)uVar14 < -0x7e) local_38 = 0xffffff81;
            else if (0x7e < (int32_t)local_38) local_38 = 0x7f;
            uVar14 = local_34;
            if (0x7e < (int32_t)local_34) uVar14 = 0x7f;
            if ((int32_t)uVar14 < -0x7e) local_34 = 0xffffff81;
            else if (0x7e < (int32_t)local_34) local_34 = 0x7f;
            if ((int32_t)uVar17 < 0x7f) uVar14 = uVar17; else uVar14 = 0x7f;
            if ((int32_t)uVar14 < -0x7e) uVar17 = 0xffffff81;
            else if (0x7e < (int32_t)uVar17) uVar17 = 0x7f;
            int32_t iVar15 = iVar18;
            if (0x7e < iVar18) iVar15 = 0x7f;
            if (iVar15 < -0x7e) iVar18 = -0x7f;
            else if (0x7e < iVar18) iVar18 = 0x7f;
            *local_8 = (((uVar17 & 0xff) | ((uint32_t)iVar18 << 8)) << 8 | (local_34 & 0xff)) << 8 | (local_38 & 0xff);
            local_8 += iVar13;
            src += iVar13 * 4;
            iVar9 += iVar10; iVar16 += iVar10; iVar11 += iVar10;
            counter++;
        } while (counter < (uint32_t)get32(0x68));
    }
}

// 0x606b35 — observed shape: alloc(vtable init 8, flag 1), set vptr
void FUN_00606b35(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 8, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf6c;
}

// 0x606b56 — observed shape: alloc(vtable init 8, flag 1), set vptr
void FUN_00606b56(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 8, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf7c;
}

// 0x606b77 — observed shape: alloc(vtable init 0x10, flag 1), set vptr
void FUN_00606b77(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x10, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf8c;
}

// 0x606b98 — observed shape: alloc(vtable init 8, flag 1), set vptr
void FUN_00606b98(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 8, 1);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddf9c;
}
// 0x606bb9 — observed shape: alloc(vtable init 0x10, flag 2), set vptr
void FUN_00606bb9(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x10, 2);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddfac;
}

// 0x606bda — observed shape: alloc(vtable init 0x10, flag 2), set vptr
void FUN_00606bda(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x10, 2);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddfbc;
}

// 0x606bfb — observed shape: alloc(vtable init 0x20, flag 2), set vptr
void FUN_00606bfb(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x20, 2);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddfcc;
}

// 0x606c1c — observed shape: DPCM renderer, 2-channel (16-bit PCM), bayer dither, serpentine
void FUN_00606c1c(void* self, uint32_t param_1, uint32_t param_2, int32_t param_3) {
    char* obj = static_cast<char*>(self);
    auto get32 = [&](int off) -> int32_t {
        int32_t v; __builtin_memcpy(&v, obj + off, 4); return v;
    };
    int32_t p3 = param_3;
    if (get32(0x54) != 0) p3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00600136(reinterpret_cast<void*>(static_cast<intptr_t>(p3)))));
    if (get32(0x10) != 0) p3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_0060164a(reinterpret_cast<void*>(static_cast<intptr_t>(p3)))));
    float local_44 = 0.0f, local_40 = 0.0f;
    uint32_t uVar6 = param_1 & 3;
    uint32_t uVar8 = param_2 & 3;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>((intptr_t)get32(0x60) * (intptr_t)param_1 + ((intptr_t)get32(0x68) - 1) * (intptr_t)(param_1 & 1) * 4 + (intptr_t)get32(100) * (intptr_t)param_2 + (intptr_t)get32(0x20));
    int32_t iVar3 = get32(0x34);
    int32_t iVar14, iVar11;
    if ((param_1 & 1) == 0) { iVar14 = 0; iVar11 = 1; }
    else { iVar14 = get32(0x68) - 1; iVar11 = -1; }
    *(obj + 0x7c) = 0;
    if (get32(0x5c) != 0) FUN_00601966(reinterpret_cast<void*>(static_cast<intptr_t>(p3)));
    uint32_t counter = 0;
    if (get32(0x68) != 0) {
        int32_t iVar9 = iVar11 * 0x10;
        int32_t iVar7 = iVar14 << 4;
        int32_t iVar10 = (iVar11 + iVar14) * 0x10;
        int32_t p2off = (iVar14 - iVar11) * 0x10;
        do {
            float fVar2 = *reinterpret_cast<float*>((intptr_t)iVar3 + (intptr_t)(uVar8 + uVar6 * 8) * 4 + (intptr_t)(counter & 3) * 4);
            float fVar4 = (local_44 + *reinterpret_cast<float*>(p3 + iVar7)) * 32767.0f;
            float fVar5 = (local_40 + reinterpret_cast<float*>(p3 + iVar7)[1]) * 32767.0f;
            uint32_t uVar15 = (uint32_t)ROUND(fVar4 + fVar2);
            int32_t iVar14b = (int32_t)ROUND(fVar5 + fVar2);
            if (get32(0x5c) != 0) {
                float* pfVar1;
                pfVar1 = reinterpret_cast<float*>(p2off + 0x10 + get32(0x5c));
                local_44 = (fVar4 - (float)(int32_t)uVar15) * 3.051851e-05f;
                *pfVar1 = local_44 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(iVar7 + 0x10 + get32(0x5c));
                *pfVar1 = local_44 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(iVar10 + 0x10 + get32(0x5c));
                *pfVar1 = local_44 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(p2off + 0x14 + get32(0x5c));
                local_40 = (fVar5 - (float)iVar14b) * 3.051851e-05f;
                *pfVar1 = local_40 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(iVar7 + 0x14 + get32(0x5c));
                *pfVar1 = local_40 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(iVar10 + 0x14 + get32(0x5c));
                *pfVar1 = local_40 * 0.0625f + *pfVar1;
                local_40 = local_40 * 0.4375f;
            }
            uint32_t uVar12 = uVar15;
            if (0x7ffe < (int32_t)uVar15) uVar12 = 0x7fff;
            if ((int32_t)uVar12 < -0x7ffe) uVar15 = 0xffff8001;
            else if (0x7ffe < (int32_t)uVar15) uVar15 = 0x7fff;
            int32_t iVar13 = iVar14b;
            if (0x7ffe < iVar14b) iVar13 = 0x7fff;
            if (iVar13 < -0x7ffe) iVar14b = -0x7fff;
            else if (0x7ffe < iVar14b) iVar14b = 0x7fff;
            *local_8 = ((uint32_t)iVar14b << 0x10) | (uVar15 & 0xffff);
            local_8 += iVar11;
            p2off += iVar9; iVar7 += iVar9; iVar10 += iVar9;
            counter++;
        } while (counter < (uint32_t)get32(0x68));
    }
}

// 0x606e93 — observed shape: alloc(vtable init 0x20, flag 3), set vptr
void FUN_00606e93(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x20, 3);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddfe0;
}

// 0x606eb4 — observed shape: alloc(vtable init 0x20, flag 2), set vptr
void FUN_00606eb4(void* self, uint32_t param_1) {
    FUN_006011da(reinterpret_cast<void*>(param_1), 0x20, 2);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006ddff0;
}
