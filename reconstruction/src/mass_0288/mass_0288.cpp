// Reconstruction batch mass_0288
// Sid Meier's Pirates! (2004), PE32 i386
// image 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Candidate C++ definitions reconstructed from Ghidra 12.2 pseudocode.
// Provider register receivers are modelled as explicit `self` parameters.
//
// The provider exposes PE32/i386 addressing as 32-bit integers, so the bodies
// below keep that idiom: field access is `*(T*)(base + offset)` where `base`
// is a 32-bit address value. This is the 32-bit model of the original image,
// not a claim about host pointer width.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers (declared, not defined here).
// ---------------------------------------------------------------------------

// Recursive list teardown used by the two list heads at self+0x30 / self+0x34.
extern void FUN_0062e426();
// Container teardown used after the per-node recursion.
extern void FUN_0062e53e(int flag);
extern int FUN_0062e4ea();
extern int FUN_0062e55f();
extern int FUN_0062a507(uint32_t stateId, uint32_t index, uint32_t p3, int p4, uint32_t p5,
                        uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, int p10);
extern void FUN_0060fcd3(int sink, int location, int zero, const char* fmt, ...);

extern int FUN_0060d19b(size_t size);
extern int FUN_0065b4f3();
extern int FUN_0065ac33();
extern int FUN_0065b5fa();
extern int FUN_00533c78(size_t size);

extern uint32_t FUN_0062aba8(uint32_t param_1, uint32_t* param_2, uint32_t* param_3);
extern int FUN_0062ace1(uint32_t* param_1, uint32_t param_2, int param_3, int param_4);
extern uint32_t FUN_0062c50d(uint32_t param_2);

extern void operator_delete(void* p);

// ---------------------------------------------------------------------------
// 0x62e583
// ---------------------------------------------------------------------------

// 0x62e583 — observed shape: recursive teardown of two intrusive lists at
// self+0x30 and self+0x34; each popped node is unlinked from its own tail
// offset, recursed into, then freed; finally the base container is released.
void FUN_0062e583(void* self)
{
    char* base = static_cast<char*>(self);
    void* node;

    while (*reinterpret_cast<int*>(base + 0x30) != 0) {
        node = *reinterpret_cast<void**>(base + 0x30);
        *reinterpret_cast<uint32_t*>(base + 0x30) =
            *reinterpret_cast<uint32_t*>(static_cast<char*>(node) + 0x30);
        *reinterpret_cast<uint32_t*>(static_cast<char*>(node) + 0x30) = 0;
        FUN_0062e583(node);
        operator_delete(node);
    }
    while (*reinterpret_cast<int*>(base + 0x34) != 0) {
        node = *reinterpret_cast<void**>(base + 0x34);
        *reinterpret_cast<uint32_t*>(base + 0x34) =
            *reinterpret_cast<uint32_t*>(static_cast<char*>(node) + 0x34);
        *reinterpret_cast<uint32_t*>(static_cast<char*>(node) + 0x34) = 0;
        FUN_0062e583(node);
        operator_delete(node);
    }
    FUN_0062e426();
}

// ---------------------------------------------------------------------------
// 0x62e5d8
// ---------------------------------------------------------------------------

// 0x62e5d8 — observed shape: resolve handle, then toggle render-state bits.
// On the enable path: set bit0 of the region word, clear bit7 of the state
// byte and clear bit1 of the region word. On the disable path: clear bit0,
// set bit7 and set bit1. Returns 0x8876086c when resolution fails.
uint32_t FUN_0062e5d8(int param_1, uint32_t param_2, int param_3)
{
    uint32_t result = 0;
    int handle = FUN_0062c50d(param_2);

    if (handle == 0) {
        return 0x8876086c;
    }

    int state = *reinterpret_cast<int*>(*reinterpret_cast<int*>(handle + 4) + 0x2c);

    if (param_3 == 0) {
        if ((*reinterpret_cast<uint32_t*>(state + 0x1c) & 8) != 0) {
            uint32_t* word = reinterpret_cast<uint32_t*>(
                *reinterpret_cast<int*>(*reinterpret_cast<int*>(handle + 4) + 0x44) +
                *reinterpret_cast<int*>(param_1 + 0x33c));
            *word = *word | 1;
        }
        uint8_t* flags = reinterpret_cast<uint8_t*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(handle + 4) + 0x2c) + 0x1c);
        *flags = static_cast<uint8_t>(*flags & 0x7f);
        uint32_t* word = reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(handle + 4) + 0x44) +
            *reinterpret_cast<int*>(param_1 + 0x33c));
        *word = *word & 0xfffffffd;
    } else {
        if ((*reinterpret_cast<uint32_t*>(state + 0x1c) & 8) != 0) {
            uint32_t* word = reinterpret_cast<uint32_t*>(
                *reinterpret_cast<int*>(*reinterpret_cast<int*>(handle + 4) + 0x44) +
                *reinterpret_cast<int*>(param_1 + 0x33c));
            *word = *word & 0xfffffffe;
        }
        uint8_t* flags = reinterpret_cast<uint8_t*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(handle + 4) + 0x2c) + 0x1c);
        *flags = static_cast<uint8_t>(*flags | 0x80);
        uint32_t* word = reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(handle + 4) + 0x44) +
            *reinterpret_cast<int*>(param_1 + 0x33c));
        *word = *word | 2;
    }

    return result;
}

// ---------------------------------------------------------------------------
// 0x62e678
// ---------------------------------------------------------------------------

// 0x62e678 — observed shape: null output or failed handle resolution yields
// 0x80004005; otherwise store the state byte's bit 7 and return 0.
uint32_t FUN_0062e678(uint32_t param_1, uint32_t param_2, uint32_t* param_3)
{
    (void)param_1;

    if (param_3 == 0) {
        return 0x80004005;
    }
    int handle = FUN_0062c50d(param_2);
    if (handle == 0) {
        return 0x80004005;
    }
    *param_3 = (*reinterpret_cast<uint32_t*>(
                    *reinterpret_cast<int*>(*reinterpret_cast<int*>(handle + 4) + 0x2c) + 0x1c) >>
                7) &
               1;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x62e6b7
// ---------------------------------------------------------------------------

// 0x62e6b7 — observed shape: resolve a list from param_2+0x40 into a count,
// lazily build the +0x2c container's node chain (0x50-byte owner, 0x20-byte
// linked records each owning a 0x40-byte object), then walk the chain of
// type-0xd nodes through type-1 wrappers to locate a type-1 child and store
// it at param_2+0x1c.
int FUN_0062e6b7(uint32_t param_1, int param_2)
{
    int ivar3 = param_2;
    uint32_t local_8 = *reinterpret_cast<uint32_t*>(param_2 + 0x40);
    int ivar1 = 0;
    int ivar4 = 0;
    int ivar6 = 0;

    uint32_t uvar2 = FUN_0062aba8(param_1, &local_8, &param_1);
    *reinterpret_cast<uint32_t*>(ivar3 + 0x14) = uvar2;

    if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(ivar3 + 0x2c) + 0x28) == 0) {
        ivar6 = FUN_0060d19b(0x50);
        if (ivar6 != 0) {
            ivar4 = FUN_0065b4f3();
        }
        if (ivar4 != 0) {
            int* obj = *reinterpret_cast<int**>(
                *reinterpret_cast<int*>(ivar3 + 0x2c) + 0x20);
            int* vtable = *reinterpret_cast<int**>(obj);
            typedef int (*VirtualFn)();
            VirtualFn fn = reinterpret_cast<VirtualFn>(
                *reinterpret_cast<void**>(reinterpret_cast<char*>(vtable) + 4));
            ivar6 = fn();
            *reinterpret_cast<int*>(ivar4 + 0x10) = ivar6;
            if (ivar6 != 0) {
                uint32_t* src = *reinterpret_cast<uint32_t**>(ivar3 + 0x38);
                uint32_t* dst = reinterpret_cast<uint32_t*>(ivar4 + 0x30);
                for (ivar6 = 8; ivar6 != 0; ivar6 = ivar6 - 1) {
                    *dst = *src;
                    src = src + 1;
                    dst = dst + 1;
                }
                uint32_t uvar8 = 0;
                if (param_1 != 0) {
                    do {
                        ivar3 = FUN_0060d19b(0x14);
                        if (ivar3 == 0) {
                            ivar3 = 0;
                        } else {
                            ivar3 = FUN_0065ac33();
                        }
                        if (ivar3 == 0) goto LAB_0062e7b5;
                        ivar6 = FUN_0060d19b(0x40);
                        if (ivar6 == 0) {
                            ivar6 = 0;
                        } else {
                            ivar6 = FUN_0065b5fa();
                        }
                        if (ivar6 == 0) goto LAB_0062e7b5;
                        *reinterpret_cast<int*>(ivar3 + 8) = ivar6;
                        uvar8 = uvar8 + 1;
                        *reinterpret_cast<uint32_t*>(ivar3 + 0xc) =
                            *reinterpret_cast<uint32_t*>(ivar4 + 0x20);
                        *reinterpret_cast<int*>(ivar4 + 0x20) = ivar3;
                    } while (uvar8 < param_1);
                }
                ivar3 = param_2;
                uint32_t local_c = *reinterpret_cast<uint32_t*>(ivar4 + 0x20);
                ivar6 = FUN_0062ace1(&local_c,
                                     *reinterpret_cast<uint32_t*>(
                                         *reinterpret_cast<int*>(param_2 + 0x2c) + 0x20),
                                     ivar4 + 0x14, ivar4 + 0x18);
                if (ivar6 < 0) {
                    return ivar6;
                }
                *reinterpret_cast<int*>(*reinterpret_cast<int*>(ivar3 + 0x2c) + 0x28) = ivar4;
                goto LAB_0062e7a5;
            }
        }
    LAB_0062e7b5:
        ivar3 = -0x7ff8fff2;
    } else {
    LAB_0062e7a5:
        ivar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(ivar3 + 0x2c) + 0x28);
        if (*reinterpret_cast<int*>(ivar4 + 4) == 0xd) {
            while (((*reinterpret_cast<int*>(ivar4 + 0x1c) == 0) &&
                    (ivar1 = *reinterpret_cast<int*>(ivar4 + 0x20), ivar1 != 0)) &&
                   (*reinterpret_cast<int*>(ivar1 + 4) == 1) &&
                   ((ivar1 = *reinterpret_cast<int*>(ivar1 + 8), ivar1 != 0) &&
                    (*reinterpret_cast<int*>(ivar1 + 4) == 0xd))) {
                ivar4 = ivar1;
            }
            if ((*reinterpret_cast<int*>(ivar4 + 0x1c) == 0) &&
                (ivar4 = *reinterpret_cast<int*>(ivar4 + 0x20), ivar4 != 0) &&
                (*reinterpret_cast<int*>(ivar4 + 4) == 1)) {
                *reinterpret_cast<int*>(ivar3 + 0x1c) = ivar4;
                return ivar6;
            }
        }
        ivar3 = -0x7fffbffb;
    }
    return ivar3;
}

// ---------------------------------------------------------------------------
// 0x62e802
// ---------------------------------------------------------------------------

// 0x62e802 — observed shape: allocate a 0x2c-byte node, validate that
// param_1+0x18 is a type-10 node and param_1+0x14 a type-3 node whose +0x10
// tag is 9 and whose +0x18 payload exists; on success link the node into the
// self+0x350 stack and bump self+0x32c.
uint32_t FUN_0062e802(void* self, int param_1)
{
    uint32_t uVar3 = 0;
    int ivar2 = FUN_00533c78(0x2c);

    if (ivar2 == 0) {
        ivar2 = 0;
    } else {
        ivar2 = FUN_0062e4ea();
    }

    if (ivar2 == 0) {
        return 0x8007000e;
    }

    {
        int node18 = *reinterpret_cast<int*>(param_1 + 0x18);
        int ivar1;
        if ((node18 == 0) || (*reinterpret_cast<int*>(node18 + 4) != 10)) {
            goto invalid;
        }
        ivar1 = *reinterpret_cast<int*>(param_1 + 0x14);
        if ((ivar1 == 0) || (*reinterpret_cast<int*>(ivar1 + 4) != 3) ||
            (*reinterpret_cast<int*>(ivar1 + 0x10) != 9) ||
            (*reinterpret_cast<int*>(ivar1 + 0x18) == 0)) {
            goto invalid;
        }
        {
            char* base = static_cast<char*>(self);
            *reinterpret_cast<int*>(ivar2 + 0x20) = *reinterpret_cast<int*>(ivar1 + 0x18);
            *reinterpret_cast<uint32_t*>(ivar2 + 0x24) =
                *reinterpret_cast<uint32_t*>(param_1 + 0x18);
            *reinterpret_cast<int*>(ivar2 + 0x28) = *reinterpret_cast<int*>(base + 0x350);
            *reinterpret_cast<int*>(base + 0x32c) = *reinterpret_cast<int*>(base + 0x32c) + 1;
            *reinterpret_cast<int*>(base + 0x350) = ivar2;
            return 0;
        }
    }
invalid:
    FUN_0062e53e(1);
    uVar3 = 0x80004005;
    return uVar3;
}

// ---------------------------------------------------------------------------
// 0x62e88d
// ---------------------------------------------------------------------------

// 0x62e88d — observed shape: compile one state assignment. Selects the
// ZENABLE or TEXTURE state descriptor table (by param_3 == ~0), finds the
// state record by case-insensitive name, validates index usage, rejects
// out-of-range/sampler-specific indices, emits the state through
// FUN_0062c043 / FUN_0062c211, then either builds a 0x2c-byte assignment node
// (FUN_0062a507) or recurses over the type-0xe expression's children.
extern uint32_t g_stateTable[];    // PTR_s_ZENABLE_006e2128 (stride 0x1c)
extern uint32_t g_textureTable[];  // PTR_s_TEXTURE_006e3540  (stride 0x1c)

extern int FUN_0062c043(uint32_t a, const void* stateRec, int* p3, uint32_t* p4, uint32_t* p5,
                        uint32_t* p6, uint32_t* p7, uint32_t* p8, int p9);
extern int FUN_0062c211(const void* stateRec, int a, uint32_t b, uint32_t c, uint32_t d, uint32_t e,
                        int f);
extern int _stricmp(const char* a, const char* b);
extern int atoi(const char* s);

// 0x62e88d — observed shape (continued in body).
int FUN_0062e88d(void* self, int param_1, int* param_2, uint32_t param_3)
{
    char* self_ = static_cast<char*>(self);
    uint32_t* table = g_stateTable;
    if (param_3 != 0xffffffffu) {
        table = g_textureTable;
    }

    int local_14 = *reinterpret_cast<int*>(param_1 + 8);
    int stateIndex = 0;
    int iVar7 = *reinterpret_cast<int*>(local_14 + 0x10);
    int local_c = static_cast<int>(reinterpret_cast<uintptr_t>(self_));

    if (*table != 0) {
        uint32_t* cur = table;
        do {
            int cmp = _stricmp(reinterpret_cast<const char*>(*cur),
                               *reinterpret_cast<char**>(iVar7 + 0x18));
            if (cmp == 0) break;
            stateIndex = stateIndex + 1;
            cur = cur + 7;
        } while (*cur != 0);
    }
    table = table + stateIndex * 7;

    const char* stateName = reinterpret_cast<const char*>(*table);
    if (stateName == 0) {
        FUN_0060fcd3(local_c + 0x28, iVar7 + 0x10, 0,
                     "ID3DXEffectCompiler: Unrecognized state '%s'",
                     *reinterpret_cast<void**>(iVar7 + 0x18));
        return -0x7fffbffb;
    }

    uint32_t local_8 = 0;
    if (*reinterpret_cast<int*>(local_14 + 0x14) == 0) {
        if (table[4] != 1) {
            FUN_0060fcd3(local_c + 0x28, iVar7 + 0x10, 0,
                         "ID3DXEffectCompiler: Index is required for state '%s'", stateName);
            return -0x7fffbffb;
        }
    } else {
        uint32_t maxIndex = table[4];
        if (maxIndex == 1) {
            FUN_0060fcd3(local_c + 0x28, iVar7 + 0x10, 0,
                         "ID3DXEffectCompiler: State '%s' is not indexed", stateName);
            return -0x7fffbffb;
        }
        local_8 = *reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int*>(local_14 + 0x14) + 0x18);
        if ((maxIndex != 0) && (maxIndex <= local_8)) {
            FUN_0060fcd3(local_c + 0x28, iVar7 + 0x10, 0,
                         "ID3DXEffectCompiler: Max index for effect state '%s' is %d", stateName,
                         maxIndex - 1);
            return -0x7fffbffb;
        }
    }

    if (param_3 != 0xffffffffu) {
        stateIndex = 0;
        uint32_t* cur = g_stateTable;
        do {
            int cmp = _stricmp(reinterpret_cast<const char*>(*cur),
                               *reinterpret_cast<char**>(iVar7 + 0x18));
            if (cmp == 0) break;
            stateIndex = stateIndex + 1;
            cur = cur + 7;
        } while (*cur != 0);
        local_8 = param_3;
    }

    if (g_stateTable[stateIndex * 7 + 4] == 0x105) {
        if ((local_8 < 0x10) || (local_8 == 0x101) || (local_8 == 0x102) ||
            (local_8 == 0x103) || (local_8 == 0x104)) {
            if (g_stateTable[stateIndex * 7 + 5] == 0x300000d) {
                FUN_0060fcd3(local_c + 0x28, iVar7 + 0x10, 0,
                             "ID3DXEffectCompiler: DMAPOFFSET sampler state can only be used "
                             "with D3DDMAPSAMPLER (i.e. sampler index 256)");
                return -0x7fffbffb;
            }
        } else if (local_8 != 0x100) {
            FUN_0060fcd3(local_c + 0x28, iVar7 + 0x10, 0,
                         "ID3DXEffectCompiler: Invalid sampler index %d", local_8);
            return -0x7fffbffb;
        }
    }

    iVar7 = iVar7 + 0x10;
    int local_28 = iVar7;
    int local_10 = 0;
    uint32_t local_24 = 0, local_20 = 0, local_1c = 0, local_18 = 0, local_2c = 0;

    int iVar5 = FUN_0062c043(*reinterpret_cast<uint32_t*>(local_14 + 0x18),
                             g_stateTable + stateIndex * 7, &local_10, &local_24, &local_20,
                             &local_1c, &local_18, &local_2c, iVar7);
    if (iVar5 < 0) {
        return iVar5;
    }
    iVar5 = FUN_0062c211(g_stateTable + stateIndex * 7, local_10, local_24, local_20, local_1c,
                         local_18, iVar7);
    if (iVar5 < 0) {
        return iVar5;
    }

    int iVar3 = *reinterpret_cast<int*>(local_14 + 0x18);
    if (((local_10 < 10) || ((0xe < local_10 && (local_10 != 0xf30000)))) ||
        (*reinterpret_cast<int*>(iVar3 + 4) != 0xd)) {
    LAB_0062eb9c:
        iVar5 = FUN_00533c78(0x2c);
        if (iVar5 == 0) {
            iVar7 = 0;
        } else {
            iVar7 = FUN_0062a507(stateIndex, local_8, *reinterpret_cast<uint32_t*>(local_14 + 0x18),
                                 local_10, local_24, local_20, local_1c, local_18, local_2c,
                                 iVar7);
        }
        if (iVar7 == 0) {
            return -0x7ff8fff2;
        }
        *reinterpret_cast<int*>(*param_2 + 0x28) = iVar7;
        *param_2 = iVar7;
        return iVar5;
    }

    if (((*reinterpret_cast<int*>(iVar3 + 0x1c) == 0) &&
         (iVar3 = *reinterpret_cast<int*>(iVar3 + 0x20), iVar3 != 0)) &&
        (*reinterpret_cast<int*>(iVar3 + 4) == 1) &&
        ((iVar3 = *reinterpret_cast<int*>(iVar3 + 8), iVar3 != 0) &&
         (*reinterpret_cast<int*>(iVar3 + 4) == 0xe))) {
        if (*reinterpret_cast<int*>(iVar3 + 0x10) != 6) {
            iVar7 = *reinterpret_cast<int*>(iVar3 + 0x18);
        LAB_0062eb7b:
            while (true) {
                if (iVar7 == 0) {
                    return iVar5;
                }
                uint32_t recurseIndex;
                if (local_10 == 0xf30000) {
                    recurseIndex = 0xffffffffu;
                } else {
                    recurseIndex = local_8;
                }
                iVar5 = FUN_0062e88d(self, iVar7, param_2, recurseIndex);
                if (iVar5 < 0) break;
                iVar7 = *reinterpret_cast<int*>(iVar7 + 0xc);
            }
            return iVar5;
        }
        if (local_10 != 0xf30000) goto LAB_0062eb9c;

        uint32_t* puVar12 = *reinterpret_cast<uint32_t**>(local_c + 0x358);
        if (puVar12 != 0) {
            do {
                const unsigned char* pbVar6 = *reinterpret_cast<unsigned char**>(puVar12);
                const unsigned char* pbVar10 =
                    *reinterpret_cast<unsigned char**>(iVar3 + 0x28);
                int cmp;
                do {
                    unsigned char bVar1 = *pbVar10;
                    if (bVar1 != *pbVar6) {
                        // byte-wise comparison result, negative/positive
                        cmp = (static_cast<int>(bVar1) < static_cast<int>(*pbVar6)) ? -1 : 1;
                        break;
                    }
                    if (bVar1 == 0) {
                        cmp = 0;
                        break;
                    }
                    bVar1 = pbVar10[1];
                    if (bVar1 != pbVar6[1]) {
                        cmp = (static_cast<int>(bVar1) < static_cast<int>(pbVar6[1])) ? -1 : 1;
                        break;
                    }
                    pbVar10 = pbVar10 + 2;
                    pbVar6 = pbVar6 + 2;
                } while (true);
                iVar7 = cmp;
            } while ((iVar7 != 0) &&
                     (puVar12 = reinterpret_cast<uint32_t*>(puVar12[2]), puVar12 != 0));
            if (puVar12 != 0) {
                iVar7 = puVar12[1];
                goto LAB_0062eb7b;
            }
        }
        FUN_0060fcd3(local_c + 0x28, local_28, 0,
                     "ID3DXEffectCompiler: Unsupported sampler or stateblock expression "
                     "(static usage not supported).");
        return -0x7fffbffb;
    }

    FUN_0060fcd3(local_c + 0x28, iVar3 + 0x10, 0,
                 "ID3DXEffectCompiler: Unsupported sampler or stateblock expression "
                 "(static usage not supported).");
    return -0x7fffbffb;
}

// ---------------------------------------------------------------------------
// 0x62ebf0
// ---------------------------------------------------------------------------

extern void FUN_0062e45b(int mode);
extern void FUN_004127b0(void* array, int stride, int count, void* ctor);
extern void LAB_0062a483();

// 0x62ebf0 — observed shape: drop any existing +0x8 vector, allocate
// count*0x20+4 bytes (leading count dword), construct the records with
// FUN_004127b0, then fill each 0x20-byte record: type 3, owner pointer
// from +0x4, relative offset at +0x18, resolved index at +0x14, and the
// record's +0x1c pointer advanced through the +0xc chain.
uint32_t FUN_0062ebf0(void* self, int param_1, int param_2)
{
    char* self_ = static_cast<char*>(self);
    int ivar1 = param_1;
    int* pivec = 0;

    if (*reinterpret_cast<int*>(param_1 + 8) != 0) {
        FUN_0062e45b(3);
        *reinterpret_cast<uint32_t*>(ivar1 + 8) = 0;
    }

    int count = param_2;
    int* block = reinterpret_cast<int*>(FUN_00533c78(static_cast<size_t>(count) * 0x20 + 4));
    if (block != 0) {
        pivec = block + 1;
        *block = count;
        FUN_004127b0(pivec, 0x20, count, reinterpret_cast<void*>(&LAB_0062a483));
    }
    *reinterpret_cast<int**>(ivar1 + 8) = pivec;

    if (pivec == 0) {
        return 0x8007000e;
    }

    int ivar6 = *reinterpret_cast<int*>(ivar1 + 0x1c);
    uint32_t cursor = static_cast<uint32_t>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(ivar1 + 4) + 0x40) +
                                            0x18 + *reinterpret_cast<int*>(ivar1 + 0x18));
    uint32_t uVar3 = 0;

    if (count != 0) {
        int offset = 0;
        do {
            char* rec = reinterpret_cast<char*>(*reinterpret_cast<int*>(ivar1 + 8)) + offset;
            uint32_t local_c = 0;
            *reinterpret_cast<uint32_t*>(rec) = 3;
            *reinterpret_cast<uint32_t*>(rec + 4) = *reinterpret_cast<uint32_t*>(ivar1 + 4);
            *reinterpret_cast<int*>(rec + 0x18) =
                static_cast<int>(cursor - *reinterpret_cast<int*>(*reinterpret_cast<int*>(ivar1 + 4) + 0x40));
            uVar3 = FUN_0062aba8(*reinterpret_cast<uint32_t*>(self_ + 0x344), &cursor, &local_c);
            *reinterpret_cast<uint32_t*>(rec + 0x14) = uVar3;
            *reinterpret_cast<int*>(rec + 0x1c) = ivar6;
            for (int iVar4 = static_cast<int>(local_c); iVar4 != 0; iVar4 = iVar4 - 1) {
                ivar6 = *reinterpret_cast<int*>(ivar6 + 0xc);
            }
            offset = offset + 0x20;
            count = count - 1;
        } while (count != 0);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x62eccf
// ---------------------------------------------------------------------------

extern uint32_t FUN_0062f194(void* self, uint32_t name, uint32_t depth);
extern uint32_t FUN_0062d4a2(uint32_t record, char* path, int depth);
extern uint32_t FUN_0062d2ee(uint32_t record, uint32_t index, int depth);

// 0x62eccf — observed shape: resolve a dotted/bracketed/@-terminated path
// against the effect-variable list at self+0x34c, descending into the
// 0x20-byte child records of type-5 nodes; '.' restarts the scan from the
// negated record pointer, '@' delegates to FUN_0062d4a2, and '[n]' indexes
// through FUN_0062d2ee. Returns the negated record pointer on success.
uint32_t FUN_0062eccf(void* self, uint32_t param_1, char* param_2, int param_3)
{
    char* self_ = static_cast<char*>(self);
    const int tableBase = *reinterpret_cast<int*>(self_ + 0x344);
    uint32_t uVar4 = 0;

    for (;;) {  // LAB_0062ee40
        if (param_1 == 0) {
            if (param_2 == 0) {
                return 0;
            }
            uVar4 = FUN_0062f194(self,
                                 static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_2)),
                                 static_cast<uint32_t>(param_3 + 1));
            if (uVar4 == 0) {
                return 0;
            }
            return ~uVar4;
        }

        uVar4 = FUN_0062f194(self, param_1, static_cast<uint32_t>(param_3 + 1));
        uint32_t uVar7 = 0;
        if (uVar4 == 0) {
            return 0;
        }
        if (param_2 == 0) {
            return ~uVar4;
        }

        int iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(uVar4 + 4) + 0x40) +
                    *reinterpret_cast<int*>(uVar4 + 0x18) + tableBase;
        if (*reinterpret_cast<int*>(iVar2 + 4) != 5) {
            return 0;
        }
        if ((*reinterpret_cast<int*>(uVar4 + 0x10) == -1) &&
            (*reinterpret_cast<int*>(iVar2 + 0x10) != 0)) {
            return 0;
        }
        uint32_t uVar3 = *reinterpret_cast<uint32_t*>(iVar2 + 0x14);
        if ((*reinterpret_cast<int*>(uVar4 + 8) == 0) &&
            (iVar2 = FUN_0062ebf0(self, static_cast<int>(uVar4), static_cast<int>(uVar3)),
             iVar2 < 0)) {
            return 0;
        }

        int local_c = 0;
        int iVar8 = 0;
        bool restart = false;

        for (;;) {
            if (uVar3 <= uVar7) {
                return 0;
            }
            int rec = *reinterpret_cast<int*>(uVar4 + 8) + local_c;
            iVar8 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(rec + 4) + 0x40) +
                    *reinterpret_cast<int*>(rec + 0x18) + tableBase;
            int nameBlob = *reinterpret_cast<int*>(iVar8 + 8);
            char* pcVar5;
            if (*reinterpret_cast<int*>(nameBlob + tableBase) == 0) {
                pcVar5 = 0;
            } else {
                pcVar5 = reinterpret_cast<char*>(nameBlob + 4 + tableBase);
            }
            char cVar1 = *param_2;
            char* pcVar6 = param_2;
            while ((cVar1 == *pcVar5 && (cVar1 != '\0'))) {
                pcVar6 = pcVar6 + 1;
                pcVar5 = pcVar5 + 1;
                cVar1 = *pcVar6;
            }
            cVar1 = *pcVar6;
            if (cVar1 == *pcVar5) {
                return ~(uVar7 * 0x20 + *reinterpret_cast<uint32_t*>(uVar4 + 8));
            }
            if (*pcVar5 == '\0') {
                if (cVar1 == '.') {
                    param_2 = pcVar6 + 1;
                    param_1 = ~(uVar7 * 0x20 + *reinterpret_cast<uint32_t*>(uVar4 + 8));
                    restart = true;
                    break;
                }
                if (cVar1 == '@') {
                    return FUN_0062d4a2(~(uVar7 * 0x20 + *(uVar4 + 8)),
                                        pcVar6 + 1, param_3);
                }
                if (cVar1 == '[') {
                    // LAB_0062edcf: parse a decimal index inside brackets.
                    pcVar6 = pcVar6 + 1;
                    if (*pcVar6 < '0') {
                        return 0;
                    }
                    if ('9' < *pcVar6) {
                        return 0;
                    }
                    uint32_t index = static_cast<uint32_t>(atoi(pcVar6));
                    if (*reinterpret_cast<uint32_t*>(iVar8 + 0x10) <= index) {
                        return 0;
                    }
                    for (; ('/' < *pcVar6 && (*pcVar6 < ':')); pcVar6 = pcVar6 + 1) {
                    }
                    if (*pcVar6 != ']') {
                        return 0;
                    }
                    uint32_t indexed =
                        FUN_0062d2ee(~(uVar7 * 0x20 + *(uVar4 + 8)),
                                     index, param_3);
                    if (indexed == 0) {
                        return 0;
                    }
                    if (pcVar6[1] == '\0') {
                        return indexed;
                    }
                    if (pcVar6[1] != '.') {
                        return 0;
                    }
                    param_2 = pcVar6 + 2;
                    restart = true;
                    break;
                }
            }
            uVar7 = uVar7 + 1;
            local_c = local_c + 0x20;
        }

        if (!restart) {
            return ~uVar4;
        }
    }
}

// ---------------------------------------------------------------------------
// 0x62eeac
// ---------------------------------------------------------------------------

// 0x62eeac — observed shape: thin wrapper; a null path yields 0, otherwise
// forward to FUN_0062d4a2 with a zero depth. param_1 is unused.
uint32_t FUN_0062eeac(uint32_t param_1, int param_2, uint32_t param_3)
{
    (void)param_1;
    if (param_2 == 0) {
        return 0;
    }
    return FUN_0062d4a2(static_cast<uint32_t>(param_2),
                        reinterpret_cast<char*>(static_cast<uintptr_t>(param_3)), 0);
}

// ---------------------------------------------------------------------------
// 0x62eecf
// ---------------------------------------------------------------------------

// 0x62eecf — observed shape: deleting destructor; always runs the list/base
// teardown, then frees the object when bit 0 of the delete flag is set.
void FUN_0062eecf(void* self, uint8_t param_1)
{
    FUN_0062e583(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x62eef0
// ---------------------------------------------------------------------------

// 0x62eef0 — observed shape: detach the +0x28 sub-object through its deleting
// destructor, then recursively tear down the intrusive list at +0x2c before
// releasing the base container.
void FUN_0062eef0(void* self)
{
    char* base = static_cast<char*>(self);

    if (*reinterpret_cast<int*>(base + 0x28) != 0) {
        FUN_0062eecf(*reinterpret_cast<void**>(base + 0x28), 1);
        *reinterpret_cast<uint32_t*>(base + 0x28) = 0;
    }

    int node = *reinterpret_cast<int*>(base + 0x2c);
    while (node != 0) {
        void* pv = *reinterpret_cast<void**>(base + 0x2c);
        *reinterpret_cast<uint32_t*>(base + 0x2c) =
            *reinterpret_cast<uint32_t*>(static_cast<char*>(pv) + 0x2c);
        *reinterpret_cast<uint32_t*>(static_cast<char*>(pv) + 0x2c) = 0;
        FUN_0062eef0(pv);
        operator_delete(pv);
        node = *reinterpret_cast<int*>(base + 0x2c);
    }
    FUN_0062e426();
}

// ---------------------------------------------------------------------------
// 0x62ef38
// ---------------------------------------------------------------------------

extern int FUN_0062a5d2();
extern int FUN_0062a866(int var, int* pType, void* p1, void* p2, void* p3, void* p4, uint32_t* pSize);
extern int FUN_0062aed7(uint32_t var, void* pValue);
extern int FUN_0062a64e(void* buffer, uint32_t size, uint32_t* outSize);
extern int FUN_0062afd1(uint32_t var, void* pTypeTag, int z1, int z2, uint32_t p5, int annot,
                        uint32_t* pOut, int z3);
extern int FUN_0062a7e2(int annot);
extern int FUN_0062a757(uint32_t value, int flag);
extern void FUN_0062a62d(int mode);

// 0x62ef38 — observed shape: build an annotation node from the expression at
// param_1+0x18 (type 0xb, flag bit 1 clear) whose +0x20 variable is typed
// (0/1/2/3/4 only); copy the default value into a zeroed buffer, initialise
// an annotation type object, and link the new 0x48-byte node into *param_4.
int FUN_0062ef38(void* self, int param_1, uint32_t param_2, uint32_t param_3, int* param_4)
{
    char* self_ = static_cast<char*>(self);
    (void)param_2;

    int iVar4 = 0;
    uint32_t* local_10 = 0;
    uint32_t local_18 = 0;
    int local_2c = 0;
    uint32_t local_20 = 0, local_1c = 0;
    int local_24 = 0;
    uint32_t local_3c = 0, local_38 = 0, local_34 = 0, local_30 = 0;

    int iVar1 = FUN_00533c78(0x1c);
    int local_c;
    if (iVar1 == 0) {
        local_c = 0;
    } else {
        local_c = FUN_0062a5d2();
    }
    if (local_c == 0) {
        return -0x7ff8fff2;
    }

    iVar1 = *reinterpret_cast<int*>(param_1 + 0x18);
    int iVar2;
    if (((iVar1 == 0) || (*reinterpret_cast<int*>(iVar1 + 4) != 0xb)) ||
        (iVar2 = *reinterpret_cast<int*>(param_1 + 0x14), iVar2 == 0) ||
        (*reinterpret_cast<int*>(iVar2 + 4) != 3)) {
        iVar4 = -0x7fffbffb;
        goto cleanup;
    }

    if ((*reinterpret_cast<uint32_t*>(iVar1 + 0x1c) & 2) != 0) {
        // no annotation work when the expression is flagged static
        goto cleanup;
    }

    {
        int* local_14 = reinterpret_cast<int*>(iVar2 + 0x10);
        if ((*local_14 != 9) ||
            (local_2c = *reinterpret_cast<int*>(iVar2 + 0x18), local_2c == 0) ||
            (*reinterpret_cast<int*>(iVar1 + 0x20) == 0)) {
            iVar4 = -0x7fffbffb;
            goto cleanup;
        }

        iVar4 = FUN_0062a866(*reinterpret_cast<int*>(iVar1 + 0x20), &local_24,
                             &local_3c, &local_38, &local_34, &local_30, &local_18);
        if (iVar4 < 0) {
            FUN_0060fcd3(static_cast<int>(reinterpret_cast<uintptr_t>(self_)) + 0x28, static_cast<int>(reinterpret_cast<uintptr_t>(local_14)), 0,
                         "ID3DXEffectCompiler: There was a problem getting variable type");
            goto cleanup;
        }

        if ((local_24 != 0) && (local_24 != 4) && (local_24 != 3) && (local_24 != 1) &&
            (local_24 != 2)) {
            FUN_0060fcd3(static_cast<int>(reinterpret_cast<uintptr_t>(self_)) + 0x28, static_cast<int>(reinterpret_cast<uintptr_t>(local_14)), 0,
                         "ID3DXEffectCompiler: Only numeric types and strings are allowed as "
                         "annotations");
            iVar4 = -0x7fffbffb;
            goto cleanup;
        }

        local_10 = reinterpret_cast<uint32_t*>(FUN_00533c78(local_18));
        if (local_10 == 0) {
            iVar4 = -0x7ff8fff2;
            goto cleanup;
        }

        {
            uint32_t* puVar5 = local_10;
            uint32_t uVar3;
            for (uVar3 = local_18 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar5 = 0;
                puVar5 = puVar5 + 1;
            }
            for (uVar3 = local_18 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *reinterpret_cast<uint8_t*>(puVar5) = 0;
                puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar5) + 1);
            }
        }

        {
            uint32_t* local_28 = local_10;
            iVar4 = FUN_0062aed7(*reinterpret_cast<uint32_t*>(iVar1 + 0x20),
                                 reinterpret_cast<void*>(&local_28));
            if ((-1 < iVar4) &&
                (iVar4 = FUN_0062a64e(local_10, local_18, &local_20), -1 < iVar4)) {
                iVar4 = FUN_0062afd1(*reinterpret_cast<uint32_t*>(iVar1 + 0x20),
                                     reinterpret_cast<void*>(local_14), 0, 0, param_3, local_c,
                                     &local_1c, 0);
                if (iVar4 < 0) {
                    FUN_0060fcd3(static_cast<int>(reinterpret_cast<uintptr_t>(self_)) + 0x28,
                                 static_cast<int>(reinterpret_cast<uintptr_t>(local_14)), 0,
                                 "ID3DXEffectCompiler: Error initializing annotation type");
                    goto cleanup;
                }
                iVar4 = FUN_0062a7e2(local_c);
                if (-1 < iVar4) {
                    iVar4 = FUN_0062a757(local_1c, 0);
                    if ((-1 < iVar4) && (iVar4 = FUN_0062a757(local_20, 0), -1 < iVar4)) {
                        iVar2 = FUN_00533c78(0x48);
                        if (iVar2 == 0) {
                            iVar2 = 0;
                        } else {
                            iVar2 = FUN_0062e55f();
                        }
                        if (iVar2 == 0) {
                            iVar4 = -0x7ff8fff2;
                        } else {
                            *reinterpret_cast<int*>(iVar2 + 0x20) = local_2c;
                            *reinterpret_cast<uint32_t*>(iVar2 + 0x24) = 0;
                            *reinterpret_cast<uint32_t*>(iVar2 + 0x28) = 0;
                            *reinterpret_cast<uint32_t*>(iVar2 + 0x40) = local_1c;
                            *reinterpret_cast<uint32_t*>(iVar2 + 0x3c) = local_20;
                            *reinterpret_cast<uint32_t*>(iVar2 + 0x44) = 0;
                            *reinterpret_cast<int*>(iVar2 + 0x2c) = iVar1;
                            *reinterpret_cast<int*>(iVar2 + 0x34) = *param_4;
                            *reinterpret_cast<int*>(iVar2 + 0x38) =
                                *reinterpret_cast<int*>(param_1 + 0x14) + 0x10;
                            *param_4 = iVar2;
                        }
                    }
                    goto cleanup;
                }
            }
        }
    }

cleanup:
    FUN_0062a62d(1);
    if (local_10 != 0) {
        operator_delete(local_10);
    }
    return iVar4;
}

// ---------------------------------------------------------------------------
// 0x62f194
// ---------------------------------------------------------------------------

extern int atoi(const char* s);

// 0x62f194 — observed shape: resolve a name (or a negated record pointer, or
// an already-negated tag) against the variable list at self+0x34c; descends
// with '.' into FUN_0062eccf, resolves '@' through FUN_0062d4a2 and indexes
// '[n]' through FUN_0062d2ee. Low-16-bit values and failed type checks
// return 0.
uint32_t FUN_0062f194(void* self, uint32_t param_1u, uint32_t param_2)
{
    char* self_ = static_cast<char*>(self);
    const int tableBase = *reinterpret_cast<int*>(self_ + 0x344);
    char* param_1 = reinterpret_cast<char*>(param_1u);

    if ((param_1u & 0xffffu) == param_1u) {
        return 0;
    }
    if ((param_1u & 0x7fffffffu) != param_1u) {
        uint32_t record = ~param_1u;
        return (*reinterpret_cast<int*>(static_cast<uintptr_t>(record)) == 3) ? record : 0u;
    }

    uint32_t uVar4 = *reinterpret_cast<uint32_t*>(self_ + 0x34c);
    while (uVar4 != 0) {
        int iVar6 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(uVar4 + 4) + 0x40) +
                    *reinterpret_cast<int*>(uVar4 + 0x18) + tableBase;
        int iVar1 = *reinterpret_cast<int*>(iVar6 + 8);
        char* pcVar2;
        if (*reinterpret_cast<int*>(iVar1 + tableBase) == 0) {
            pcVar2 = 0;
        } else {
            pcVar2 = reinterpret_cast<char*>(iVar1 + 4 + tableBase);
        }

        char* pcVar7 = param_1;
        char cVar5 = *param_1;
        while ((cVar5 == *pcVar2 && (cVar5 != '\0'))) {
            pcVar7 = pcVar7 + 1;
            pcVar2 = pcVar2 + 1;
            cVar5 = *pcVar7;
        }
        cVar5 = *pcVar7;
        if (cVar5 == *pcVar2) {
            return uVar4;
        }
        if (*pcVar2 == '\0') {
            if (cVar5 == '.') {
                pcVar7 = pcVar7 + 1;
                uVar4 = ~uVar4;
            LAB_0062f2c5:
                uVar4 = FUN_0062eccf(self, uVar4, pcVar7, static_cast<int>(param_2));
            LAB_0062f2cd:
                if (uVar4 == 0) {
                    return 0;
                }
                return ~uVar4;
            }
            if (cVar5 == '@') {
                uVar4 = FUN_0062d4a2(~uVar4, pcVar7 + 1, static_cast<int>(param_2));
                goto LAB_0062f2cd;
            }
            if (cVar5 == '[') {
                pcVar7 = pcVar7 + 1;
                if (*pcVar7 < '0') {
                    return 0;
                }
                if ('9' < *pcVar7) {
                    return 0;
                }
                uint32_t uVar3 = static_cast<uint32_t>(atoi(pcVar7));
                if (*reinterpret_cast<uint32_t*>(iVar6 + 0x10) <= uVar3) {
                    return 0;
                }
                for (; ('/' < *pcVar7 && (*pcVar7 < ':')); pcVar7 = pcVar7 + 1) {
                }
                if (*pcVar7 != ']') {
                    return 0;
                }
                uVar4 = FUN_0062d2ee(~uVar4, uVar3, static_cast<int>(param_2));
                if (uVar4 == 0) {
                    return 0;
                }
                if (pcVar7[1] != '\0') {
                    if (pcVar7[1] != '.') {
                        return 0;
                    }
                    pcVar7 = pcVar7 + 2;
                    goto LAB_0062f2c5;
                }
                return ~uVar4;
            }
        }
        uVar4 = *reinterpret_cast<uint32_t*>(uVar4 + 0x34);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x62f2dc
// ---------------------------------------------------------------------------

// 0x62f2dc — observed shape: fill an 11-dword state description for a
// resolved variable: name handles from the parameter info, type, sampler
// index from self+0x33c, default value when unindexed, and the per-type
// value/vector fields.
uint32_t FUN_0062f2dc(int param_1, uint32_t param_2, uint32_t* param_3)
{
    if (param_3 == 0) {
        return 0x8876086c;
    }
    int iVar1 = FUN_0062f194(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), param_2, 1);
    if (iVar1 == 0) {
        return 0x8876086c;
    }

    const int tableBase = *reinterpret_cast<int*>(param_1 + 0x344);
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar1 + 4) + 0x40) +
        *reinterpret_cast<int*>(iVar1 + 0x18) + tableBase);

    {
        uint32_t* puVar6 = param_3;
        for (int iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 - 1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
        }
    }

    int* piVar2 = reinterpret_cast<int*>(puVar5[2] + tableBase);
    if (*piVar2 == 0) {
        piVar2 = 0;
    } else {
        piVar2 = piVar2 + 1;
    }
    param_3[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar2));

    piVar2 = reinterpret_cast<int*>(puVar5[3] + tableBase);
    if (*piVar2 == 0) {
        piVar2 = 0;
    } else {
        piVar2 = piVar2 + 1;
    }
    param_3[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar2));

    param_3[10] = *reinterpret_cast<uint32_t*>(iVar1 + 0x14);

    int iVar4b = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar1 + 4) + 0x44);
    uint32_t uVar3;
    if (iVar4b == 0) {
        uVar3 = 4;
    } else {
        uVar3 = *reinterpret_cast<uint32_t*>(iVar4b + *reinterpret_cast<int*>(param_1 + 0x33c));
    }
    param_3[9] = uVar3;

    param_3[3] = *puVar5;
    param_3[2] = puVar5[1];

    if (*reinterpret_cast<int*>(iVar1 + 0x10) == -1) {
        uVar3 = puVar5[4];
    } else {
        uVar3 = 0;
    }
    param_3[6] = uVar3;
    param_3[7] = 0;
    if ((*reinterpret_cast<int*>(iVar1 + 0x18) == 0) &&
        (*reinterpret_cast<int*>(iVar1 + 0x10) == -1)) {
        param_3[7] = *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(iVar1 + 4) + 0x28);
    }

    int iVar1b = static_cast<int>(param_3[2]);
    if (iVar1b == 1) {
        param_3[8] = 0;
        param_3[4] = 1;
        param_3[5] = puVar5[5];
    } else {
        if (iVar1b == 4) {
            param_3[8] = 0;
        } else {
            if (iVar1b != 5) {
                param_3[8] = 0;
                param_3[4] = puVar5[5];
                param_3[5] = puVar5[6];
                return 0;
            }
            param_3[8] = puVar5[5];
        }
        param_3[4] = 0;
        param_3[5] = 0;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x62f408
// ---------------------------------------------------------------------------

// 0x62f408 — observed shape: map a name or an ordinal to a negated record
// pointer. With a null name the ordinal walks the self+0x34c list; otherwise
// the resolved type-5 variable's +0x8 record array is bounds-checked (built
// lazily via FUN_0062ebf0).
uint32_t FUN_0062f408(int param_1, int param_2, uint32_t param_3)
{
    uint32_t uVar1;

    if (param_2 == 0) {
        if (param_3 < *reinterpret_cast<uint32_t*>(param_1 + 0x328)) {
            uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0x34c);
            while (param_3 = param_3 + 1, param_3 < *reinterpret_cast<uint32_t*>(param_1 + 0x328)) {
                uVar1 = *reinterpret_cast<uint32_t*>(uVar1 + 0x34);
            }
            uVar1 = ~uVar1;
        } else {
            uVar1 = 0;
        }
        return uVar1;
    }

    int iVar2 = FUN_0062f194(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)),
                             static_cast<uint32_t>(param_2), 1);
    if (iVar2 == 0) {
        return 0;
    }

    int iVar3 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + 0x40) +
                *reinterpret_cast<int*>(param_1 + 0x344) +
                *reinterpret_cast<int*>(iVar2 + 0x18);

    if ((*reinterpret_cast<int*>(iVar3 + 4) != 5) ||
        ((*reinterpret_cast<int*>(iVar2 + 0x10) == -1) &&
         (*reinterpret_cast<int*>(iVar3 + 0x10) != 0)) ||
        (*reinterpret_cast<uint32_t*>(iVar3 + 0x14) <= param_3)) {
        return 0;
    }

    if ((*reinterpret_cast<int*>(iVar2 + 8) == 0) &&
        (iVar3 = FUN_0062ebf0(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), iVar2,
                              static_cast<int>(*reinterpret_cast<uint32_t*>(iVar3 + 0x14))),
         iVar3 < 0)) {
        return 0;
    }

    return ~(param_3 * 0x20 + *reinterpret_cast<uint32_t*>(iVar2 + 8));
}

// ---------------------------------------------------------------------------
// 0x62f4a3
// ---------------------------------------------------------------------------

// 0x62f4a3 — observed shape: find an array element record by name. With a
// null name it scans the top-level list at self+0x34c; otherwise it scans the
// resolved type-5 variable's +0x8 records. Returns the negated record.
uint32_t FUN_0062f4a3(int param_1, uint32_t param_2, char* param_3)
{
    int iVar6 = 0;
    int iVar1, iVar3, iVar4;
    uint32_t uVar5;

    if (param_2 == 0) {
        uVar5 = *reinterpret_cast<uint32_t*>(param_1 + 0x34c);
        if (uVar5 != 0) {
            do {
                iVar1 = *reinterpret_cast<int*>(param_1 + 0x344);
                iVar3 = *reinterpret_cast<int*>(
                    *reinterpret_cast<int*>(*reinterpret_cast<int*>(uVar5 + 4) + 0x40) +
                    *reinterpret_cast<int*>(uVar5 + 0x18) + iVar1 + 0xc);
                if (*reinterpret_cast<int*>(iVar3 + iVar1) == 0) {
                    // unnamed record: matches an empty filter
                    if (param_3 == 0) {
                        break;
                    }
                } else {
                    char* name = reinterpret_cast<char*>(iVar3 + 4 + iVar1);
                    if (param_3 != 0 && _stricmp(name, param_3) == 0) {
                        break;
                    }
                }
                uVar5 = *reinterpret_cast<uint32_t*>(uVar5 + 0x34);
            } while (uVar5 != 0);
            if (uVar5 != 0) {
                return ~uVar5;
            }
        }
        return 0;
    }

    iVar3 = FUN_0062f194(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), param_2, 1);
    if (iVar3 == 0) {
        return 0;
    }
    iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar3 + 4) + 0x40) +
            *reinterpret_cast<int*>(iVar3 + 0x18) + *reinterpret_cast<int*>(param_1 + 0x344);
    if ((*reinterpret_cast<int*>(iVar4 + 4) != 5) ||
        !((*reinterpret_cast<int*>(iVar3 + 0x10) != -1) ||
          (*reinterpret_cast<int*>(iVar4 + 0x10) == 0))) {
        return 0;
    }
    uVar5 = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
    if ((*reinterpret_cast<int*>(iVar3 + 8) == 0) &&
        (iVar4 = FUN_0062ebf0(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), iVar3,
                              static_cast<int>(uVar5)),
         iVar4 < 0)) {
        return 0;
    }

    uint32_t index = 0;
    if (uVar5 != 0) {
        do {
            iVar1 = *reinterpret_cast<int*>(param_1 + 0x344);
            iVar4 = *reinterpret_cast<int*>(iVar3 + 8) + iVar6;
            iVar4 = *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar4 + 4) + 0x40) +
                *reinterpret_cast<int*>(iVar4 + 0x18) + iVar1 + 0xc);
            if ((*reinterpret_cast<int*>(iVar1 + iVar4) == 0)) {
                if (param_3 == 0) {
                    break;
                }
            } else {
                char* name = reinterpret_cast<char*>(iVar4 + 4 + iVar1);
                if (param_3 != 0 && _stricmp(name, param_3) == 0) {
                    break;
                }
            }
            index = index + 1;
            iVar6 = iVar6 + 0x20;
        } while (index < uVar5);
    }
    if (index != uVar5) {
        return ~(index * 0x20 + *reinterpret_cast<uint32_t*>(iVar3 + 8));
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x62f5f1
// ---------------------------------------------------------------------------

extern uint32_t FUN_0062e228(int info, uint32_t count, int value, int flagged);

// 0x62f5f1 — observed shape: set one state value through FUN_0062e228; the
// value must be non-null with no index, the variable must resolve and the
// requested index must be within the resolved count (or ~0).
uint32_t FUN_0062f5f1(int param_1, uint32_t param_2, int param_3, uint32_t param_4)
{
    if ((param_4 == 0) || (param_3 != 0)) {
        int iVar2 = FUN_0062f194(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), param_2, 1);
        if ((iVar2 == 0) ||
            ((param_4 != 0xffffffffu) && (param_4 < *reinterpret_cast<uint32_t*>(iVar2 + 0x14)))) {
            return 0x8876086c;
        }
        return FUN_0062e228(*reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + 0x40) +
                                *reinterpret_cast<int*>(param_1 + 0x344) +
                                *reinterpret_cast<int*>(iVar2 + 0x18),
                            *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3,
                            *reinterpret_cast<int*>(iVar2 + 0x10) != -1);
    }
    return 0x8876086c;
}

// ---------------------------------------------------------------------------
// 0x62f65d
// ---------------------------------------------------------------------------

extern uint32_t FUN_0062e401(int info, uint32_t count, int value, int flagged);

// 0x62f65d — observed shape: identical guard/lookup as 0x62f5f1 but stores
// through FUN_0062e401.
uint32_t FUN_0062f65d(int param_1, uint32_t param_2, int param_3, uint32_t param_4)
{
    if ((param_4 == 0) || (param_3 != 0)) {
        int iVar2 = FUN_0062f194(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), param_2, 1);
        if ((iVar2 == 0) ||
            ((param_4 != 0xffffffffu) && (param_4 < *reinterpret_cast<uint32_t*>(iVar2 + 0x14)))) {
            return 0x8876086c;
        }
        return FUN_0062e401(*reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + 0x40) +
                                *reinterpret_cast<int*>(param_1 + 0x344) +
                                *reinterpret_cast<int*>(iVar2 + 0x18),
                            *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3,
                            *reinterpret_cast<int*>(iVar2 + 0x10) != -1);
    }
    return 0x8876086c;
}

// ---------------------------------------------------------------------------
// 0x62f6c7
// ---------------------------------------------------------------------------

extern int FUN_0062d704(int node, uint32_t value);

// 0x62f6c7 — observed shape: copy a row-major matrix value of a resolved
// type-2/3 variable into a 4x4 staging area. Each element is stored through
// FUN_0062d704; unwritten trailing rows/columns are skipped by walking the
// +0xc chain. Type 2 uses a 1-dword input stride, type 3 a 4-dword stride.
int FUN_0062f6c7(uint32_t* param_1, uint32_t param_2, uint32_t* param_3)
{
    if (param_3 == 0) {
        return -0x7789f794;
    }

    int iVar3 = FUN_0062f194(reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(param_1)),
                             param_2, 1);
    if (iVar3 == 0) {
        return -0x7789f794;
    }

    int iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar3 + 4) + 0x40) +
                *reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x344) +
                *reinterpret_cast<int*>(iVar3 + 0x18);
    if (!((*reinterpret_cast<int*>(iVar4 + 0x10) == 0) ||
          (*reinterpret_cast<int*>(iVar3 + 0x10) != -1))) {
        return -0x7789f794;
    }

    const int kind = *reinterpret_cast<int*>(iVar4 + 4);
    if ((kind != 2) && (kind != 3)) {
        return -0x7789f794;
    }

    uint32_t rows = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
    uint32_t cols = *reinterpret_cast<uint32_t*>(iVar4 + 0x18);
    int node = *reinterpret_cast<int*>(iVar3 + 0x1c);
    uint32_t* cursor = param_3;

    uint32_t outer = 1;
    uint32_t rowLimit = 4;
    if (rows < 5) {
        rowLimit = rows;
    }
    uint32_t colLimit = 4;
    if (cols < 5) {
        colLimit = cols;
    }

    const int innerStride = (kind == 2) ? 1 : 4;   // dword stride within a row
    const int cursorStep = (kind == 2) ? 4 : 1;    // dword step between rows

    int result = 0;
    do {
        uint32_t r = 0;
        if (rowLimit != 0) {
            uint32_t* rowStart = cursor;
            do {
                uint32_t c = 0;
                if (colLimit != 0) {
                    uint32_t* cell = rowStart;
                    do {
                        result = FUN_0062d704(node, *cell);
                        if (result < 0) {
                            return result;
                        }
                        node = *reinterpret_cast<int*>(node + 0xc);
                        c = c + 1;
                        cell = cell + innerStride;
                    } while (c < colLimit);
                }
                if (c < cols) {
                    int skip = static_cast<int>(cols - c);
                    do {
                        skip = skip - 1;
                        node = *reinterpret_cast<int*>(node + 0xc);
                    } while (skip != 0);
                }
                r = r + 1;
                rowStart = rowStart + cursorStep;
            } while (r < rowLimit);
        }
        if (r < rows) {
            int skipRows = static_cast<int>(rows - r);
            do {
                if (cols != 0) {
                    uint32_t c = cols;
                    do {
                        c = c - 1;
                        node = *reinterpret_cast<int*>(node + 0xc);
                    } while (c != 0);
                }
                skipRows = skipRows - 1;
            } while (skipRows != 0);
        }
        outer = outer - 1;
        cursor = cursor + 0x10;
    } while (outer != 0);

    return result;
}

// ---------------------------------------------------------------------------
// 0x62f899
// ---------------------------------------------------------------------------

extern int FUN_0062d760(int node, uint32_t* value);

// 0x62f899 — observed shape: same traversal as 0x62f6c7 but clears the
// 0x10-dword staging area first and stores through FUN_0062d760, which
// receives the element address directly.
int FUN_0062f899(uint32_t* param_1, uint32_t param_2, uint32_t* param_3)
{
    if (param_3 == 0) {
        return -0x7789f794;
    }

    int iVar3 = FUN_0062f194(reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(param_1)),
                             param_2, 1);
    if (iVar3 == 0) {
        return -0x7789f794;
    }

    int iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar3 + 4) + 0x40) +
                *reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 0x344) +
                *reinterpret_cast<int*>(iVar3 + 0x18);
    if (!((*reinterpret_cast<int*>(iVar4 + 0x10) == 0) ||
          (*reinterpret_cast<int*>(iVar3 + 0x10) != -1))) {
        return -0x7789f794;
    }

    const int kind = *reinterpret_cast<int*>(iVar4 + 4);
    if ((kind != 2) && (kind != 3)) {
        return -0x7789f794;
    }

    int node = *reinterpret_cast<int*>(iVar3 + 0x1c);
    uint32_t cols = *reinterpret_cast<uint32_t*>(iVar4 + 0x18);
    uint32_t rows = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
    int result = 0;
    uint32_t outer = 1;
    uint32_t* cursor = param_3;
    uint32_t rowLimit = 4;
    if (rows < 5) {
        rowLimit = rows;
    }
    uint32_t colLimit = 4;
    if (cols < 5) {
        colLimit = cols;
    }

    for (int i = 0x10; i != 0; i = i - 1) {
        *param_3 = 0;
        param_3 = param_3 + 1;
    }

    const int innerStride = (kind == 2) ? 1 : 4;
    const int cursorStep = (kind == 2) ? 4 : 1;

    do {
        uint32_t r = 0;
        if (rowLimit != 0) {
            uint32_t* rowStart = cursor;
            do {
                uint32_t c = 0;
                if (colLimit != 0) {
                    uint32_t* cell = rowStart;
                    do {
                        result = FUN_0062d760(node, cell);
                        if (result < 0) {
                            return result;
                        }
                        node = *reinterpret_cast<int*>(node + 0xc);
                        c = c + 1;
                        cell = cell + innerStride;
                    } while (c < colLimit);
                }
                if (c < cols) {
                    int skip = static_cast<int>(cols - c);
                    do {
                        skip = skip - 1;
                        node = *reinterpret_cast<int*>(node + 0xc);
                    } while (skip != 0);
                }
                r = r + 1;
                rowStart = rowStart + cursorStep;
            } while (r < rowLimit);
        }
        if (r < rows) {
            int skipRows = static_cast<int>(rows - r);
            do {
                if (cols != 0) {
                    uint32_t c = cols;
                    do {
                        c = c - 1;
                        node = *reinterpret_cast<int*>(node + 0xc);
                    } while (c != 0);
                }
                skipRows = skipRows - 1;
            } while (skipRows != 0);
        }
        outer = outer - 1;
        cursor = cursor + 0x10;
    } while (outer != 0);

    return result;
}
