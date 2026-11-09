#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals observed in the supplied corpus listings.
// ---------------------------------------------------------------------------
extern "C" void* malloc(std::size_t size);

extern uint32_t DAT_006f0c88[];
extern int32_t  DAT_006f1244[];
extern int32_t  DAT_006f1260[];

typedef void* (*PiratesAllocFn)(uint32_t user, int flag, int size);
typedef void  (*PiratesFreeFn)(uint32_t user, void* block);

extern int32_t  FUN_00658adc(int context, void* value, int size);
extern int32_t  FUN_00658825(int context);
extern int32_t  FUN_0069359e(void* value);
extern int32_t  FUN_006ae438(int a, int b, int count);
extern int32_t  FUN_006af7c4(void* context, int src, int count, int flag);
extern int32_t  FUN_006b01dd(uint32_t handle, int context);
extern int32_t  FUN_006af9ad(uint32_t handle, int context, int flag);
extern uint32_t FUN_006afa13(int context, uint32_t table, uint32_t mask);
extern void*    FUN_006924f1(int context, int size);
// Default allocator installed into context+0x20 by FUN_00693146.
extern void*    FUN_006af97b(uint32_t user, int flag, int size);
// Default release callback installed into context+0x24 by FUN_00693146.
extern void     LAB_006af997(uint32_t user, void* block);

extern void  FUN_0069269b(void* self);
extern void  FUN_00692839(uint32_t* self);
extern void* FUN_00692570(uint32_t param_1, void* param_2, uint8_t param_3, uint32_t param_4);

// Dword-then-byte copy of ((bits >> 5) dwords + ((bits >> 3) & 3) bytes).
static inline void copy_words_then_bytes(uint8_t* dst, const uint8_t* src, uint32_t bits)
{
    for (uint32_t words = bits >> 5; words != 0; --words) {
        *reinterpret_cast<uint32_t*>(dst) = *reinterpret_cast<uint32_t*>(src);
        dst += 4;
        src += 4;
    }
    for (uint32_t bytes = (bits >> 3) & 3; bytes != 0; --bytes) {
        *dst++ = *src++;
    }
}

// ~-(uint16_t)(v < d) & (v - d): the provider's saturating subtract used for
// the 16-bit ring counters.
static inline uint16_t sub_saturate16(uint16_t v, uint16_t d)
{
    return v < d ? static_cast<uint16_t>(0) : static_cast<uint16_t>(v - d);
}

// 0x692380 — observed shape
// Allocates 0x118 bytes through the callbacks table whose first entry is the
// pointer stored at self+0x4, then clears the new block's +0x114 field.
void FUN_00692380(int param_1)
{
    typedef void* (*AllocProc)(int self, int zero, uint32_t size);
    void* table = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 4);
    AllocProc alloc = *reinterpret_cast<AllocProc*>(table);
    uint8_t* iVar1 = reinterpret_cast<uint8_t*>(alloc(param_1, 0, 0x118));
    *reinterpret_cast<uint32_t*>(iVar1 + 0x114) = 0;
}

// 0x6923f0 — observed shape
// Copies param_5 objects of param_6 bytes each: source pointer array rooted at
// byte offset param_2*4 inside param_1, destination pointer array rooted at
// byte offset param_4*4 inside param_3.
void FUN_006923f0(int param_1, int param_2, int param_3, int param_4, int param_5, uint32_t param_6)
{
    uint8_t** src = reinterpret_cast<uint8_t**>(static_cast<intptr_t>(param_1) + param_2 * 4);
    uint8_t** dst = reinterpret_cast<uint8_t**>(static_cast<intptr_t>(param_3) + param_4 * 4);
    if (0 < param_5) {
        int count = param_5;
        do {
            uint8_t* s = *src;
            uint8_t* d = *dst;
            for (uint32_t words = param_6 >> 2; words != 0; --words) {
                *reinterpret_cast<uint32_t*>(d) = *reinterpret_cast<uint32_t*>(s);
                s += 4;
                d += 4;
            }
            for (uint32_t bytes = param_6 & 3; bytes != 0; --bytes) {
                *d++ = *s++;
            }
            ++src;
            ++dst;
            --count;
        } while (count != 0);
    }
}

// 0x692440 — observed shape
// Dword copy of (param_3 & 0x1ffffff) << 5 elements. The listing's trailing
// byte loop is driven by a literal zero count, so it never executes.
void FUN_00692440(uint32_t* param_1, uint32_t* param_2, uint32_t param_3)
{
    for (uint32_t iVar1 = (param_3 & 0x1ffffffu) << 5; iVar1 != 0; --iVar1) {
        *param_2 = *param_1;
        ++param_1;
        ++param_2;
    }
}

// 0x692470 — observed shape
// Zero fill of param_2 bytes as (param_2 >> 2) dwords plus the remaining bytes.
void FUN_00692470(uint32_t* param_1, uint32_t param_2)
{
    for (uint32_t uVar1 = param_2 >> 2; uVar1 != 0; --uVar1) {
        *param_1 = 0;
        ++param_1;
    }
    for (param_2 = param_2 & 3; param_2 != 0; --param_2) {
        *reinterpret_cast<uint8_t*>(param_1) = 0;
        param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(param_1) + 1);
    }
}

// 0x692491 — observed shape
// Size-selects a block (0x19c for kind 1, 0x40 for kind 2, null otherwise),
// mallocs it and zeroes the dword prefix. The listing's trailing byte loop is
// driven by a literal zero count, so it never executes.
void* FUN_00692491(int param_1)
{
    uint32_t size;
    if (param_1 == 2) {
        size = 0x40;
    } else if (param_1 == 1) {
        size = 0x19c;
    } else {
        return nullptr;
    }
    uint8_t* puVar1 = static_cast<uint8_t*>(malloc(size));
    if (puVar1 != nullptr) {
        uint8_t* p = puVar1;
        for (uint32_t uVar2 = size >> 2; uVar2 != 0; --uVar2) {
            *reinterpret_cast<uint32_t*>(p) = 0;
            p += 4;
        }
    }
    return puVar1;
}

// 0x692548 — observed shape
// Copies param_4 bytes from param_3 into param_2 and returns param_2. The first
// argument is never read by the listing.
void* FUN_00692548(uint32_t /*param_1*/, void* param_2, const void* param_3, uint32_t param_4)
{
    uint8_t* puVar2 = static_cast<uint8_t*>(param_2);
    const uint8_t* src = static_cast<const uint8_t*>(param_3);
    for (uint32_t uVar1 = param_4 >> 2; uVar1 != 0; --uVar1) {
        *reinterpret_cast<uint32_t*>(puVar2) = *reinterpret_cast<const uint32_t*>(src);
        src += 4;
        puVar2 += 4;
    }
    for (param_4 = param_4 & 3; param_4 != 0; --param_4) {
        *puVar2 = *src;
        ++src;
        ++puVar2;
    }
    return param_2;
}

// 0x692570 — observed shape
// Fills param_4 bytes at param_2 with byte param_3 (the dword loop replicates
// the byte four times) and returns param_2. The first argument is never read.
void* FUN_00692570(uint32_t /*param_1*/, void* param_2, uint8_t param_3, uint32_t param_4)
{
    uint8_t* puVar2 = static_cast<uint8_t*>(param_2);
    const uint32_t spread = static_cast<uint32_t>(param_3) * 0x01010101u;
    for (uint32_t uVar1 = param_4 >> 2; uVar1 != 0; --uVar1) {
        *reinterpret_cast<uint32_t*>(puVar2) = spread;
        puVar2 += 4;
    }
    for (param_4 = param_4 & 3; param_4 != 0; --param_4) {
        *puVar2 = param_3;
        ++puVar2;
    }
    return param_2;
}

// 0x6925a6 — observed shape
// Table-driven CRC-32 over param_3 bytes: complemented seed, eight unrolled
// index steps per block of eight, then a byte-tail loop, complemented result.
// A null buffer short-circuits to zero.
uint32_t FUN_006925a6(uint32_t param_1, const uint8_t* param_2, uint32_t param_3)
{
    if (param_2 == nullptr) {
        return 0;
    }
    uint32_t crc = ~param_1;
    if (7 < param_3) {
        uint32_t uVar2 = param_3 >> 3;
        do {
            param_3 = param_3 - 8;
            uint32_t uVar1 = (crc >> 8) ^ DAT_006f0c88[(param_2[0] ^ crc) & 0xff];
            uVar1 = (uVar1 >> 8) ^ DAT_006f0c88[(param_2[1] ^ uVar1) & 0xff];
            uVar1 = (uVar1 >> 8) ^ DAT_006f0c88[(param_2[2] ^ uVar1) & 0xff];
            uVar1 = (uVar1 >> 8) ^ DAT_006f0c88[(param_2[3] ^ uVar1) & 0xff];
            uVar1 = (uVar1 >> 8) ^ DAT_006f0c88[(param_2[4] ^ uVar1) & 0xff];
            uVar1 = (uVar1 >> 8) ^ DAT_006f0c88[(param_2[5] ^ uVar1) & 0xff];
            uVar1 = (uVar1 >> 8) ^ DAT_006f0c88[(param_2[6] ^ uVar1) & 0xff];
            crc = (uVar1 >> 8) ^ DAT_006f0c88[(param_2[7] ^ uVar1) & 0xff];
            param_2 += 8;
            --uVar2;
        } while (uVar2 != 0);
    }
    for (; param_3 != 0; --param_3) {
        crc = (crc >> 8) ^ DAT_006f0c88[(*param_2 ^ crc) & 0xff];
        ++param_2;
    }
    return ~crc;
}

// 0x69269b — observed shape
// Drains min(self+0x10, packet+0x14) bytes from packet+0x10 into self+0xc,
// advances the four cursors, and rewinds packet+0x10 to packet+0x8 when the
// packet becomes empty. The receiver arrives in EAX in the listing.
void FUN_0069269b(void* self)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint8_t* pkt = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(s + 0x1c)));
    uint32_t uVar4 = *reinterpret_cast<uint32_t*>(pkt + 0x14);
    if (*reinterpret_cast<uint32_t*>(s + 0x10) < uVar4) {
        uVar4 = *reinterpret_cast<uint32_t*>(s + 0x10);
    }
    if (uVar4 != 0) {
        const uint8_t* puVar5 = reinterpret_cast<const uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(pkt + 0x10)));
        uint8_t* puVar6 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(s + 0xc)));
        for (uint32_t uVar3 = uVar4 >> 2; uVar3 != 0; --uVar3) {
            *reinterpret_cast<uint32_t*>(puVar6) = *reinterpret_cast<const uint32_t*>(puVar5);
            puVar5 += 4;
            puVar6 += 4;
        }
        for (uint32_t uVar3 = uVar4 & 3; uVar3 != 0; --uVar3) {
            *puVar6 = *puVar5;
            ++puVar5;
            ++puVar6;
        }
        *reinterpret_cast<uint32_t*>(s + 0xc) = *reinterpret_cast<uint32_t*>(s + 0xc) + uVar4;
        *reinterpret_cast<uint32_t*>(pkt + 0x10) = *reinterpret_cast<uint32_t*>(pkt + 0x10) + uVar4;
        *reinterpret_cast<uint32_t*>(s + 0x14) = *reinterpret_cast<uint32_t*>(s + 0x14) + uVar4;
        *reinterpret_cast<uint32_t*>(s + 0x10) = *reinterpret_cast<uint32_t*>(s + 0x10) - uVar4;
        *reinterpret_cast<uint32_t*>(pkt + 0x14) = *reinterpret_cast<uint32_t*>(pkt + 0x14) - uVar4;
        if (*reinterpret_cast<uint32_t*>(pkt + 0x14) == 0) {
            *reinterpret_cast<uint32_t*>(pkt + 0x10) = *reinterpret_cast<uint32_t*>(pkt + 0x8);
        }
    }
}

// 0x6926ef — observed shape
// Backward LZ-style match search over a window: compares candidate runs at
// self+0x30 + param_1 against the run at self+0x30 + self+0x64, walking both
// the probe positions (self+0x70, step from the ushort table at self+0x38
// indexed by (self+0x2c & probe)) and a shrinking count (self+0x74).
// Returns min(best pointer, self+0x6c).
char* FUN_006926ef(void* self, uint32_t param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint32_t local_c = *reinterpret_cast<uint32_t*>(s + 0x74);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(s + 0x64);
    char* pcVar3 = reinterpret_cast<char*>(
        static_cast<intptr_t>(*reinterpret_cast<int32_t*>(s + 0x30)) + uVar1);
    char* pcVar7 = *reinterpret_cast<char**>(s + 0x70);
    uint32_t local_14;
    if (static_cast<uint32_t>(*reinterpret_cast<int32_t*>(s + 0x24)) - 0x106u < uVar1) {
        local_14 = (uVar1 - static_cast<uint32_t>(*reinterpret_cast<int32_t*>(s + 0x24))) + 0x106u;
    } else {
        local_14 = 0;
    }
    char local_5 = pcVar3[reinterpret_cast<intptr_t>(pcVar7) - 1];
    char local_6 = pcVar3[reinterpret_cast<intptr_t>(pcVar7)];
    if (*reinterpret_cast<char**>(s + 0x84) <= pcVar7) {
        local_c = local_c >> 2;
    }
    char* pcVar2 = *reinterpret_cast<char**>(s + 0x6c);
    char* local_10 = *reinterpret_cast<char**>(s + 0x88);
    if (pcVar2 < local_10) {
        local_10 = pcVar2;
    }
    char* pcVar4 = pcVar7;
    do {
        char* pcVar6 = reinterpret_cast<char*>(
            static_cast<intptr_t>(*reinterpret_cast<int32_t*>(s + 0x30)) + param_1);
        if (pcVar6[reinterpret_cast<intptr_t>(pcVar7)] == local_6 &&
            pcVar6[reinterpret_cast<intptr_t>(pcVar7) - 1] == local_5 &&
            *pcVar6 == *pcVar3 &&
            pcVar6[1] == pcVar3[1]) {
            pcVar6 = pcVar6 + 2;
            char* pcVar5 = pcVar3 + 2;
            while (true) {
                pcVar4 = pcVar5 + 1;
                if (*pcVar4 != pcVar6[1]) break;
                pcVar4 = pcVar5 + 2;
                if (*pcVar4 != pcVar6[2]) break;
                pcVar4 = pcVar5 + 3;
                if (*pcVar4 != pcVar6[3]) break;
                pcVar4 = pcVar5 + 4;
                if (*pcVar4 != pcVar6[4]) break;
                pcVar4 = pcVar5 + 5;
                if (*pcVar4 != pcVar6[5]) break;
                pcVar4 = pcVar5 + 6;
                if (*pcVar4 != pcVar6[6]) break;
                pcVar4 = pcVar5 + 7;
                if (*pcVar4 != pcVar6[7]) break;
                pcVar4 = pcVar5 + 8;
                pcVar6 = pcVar6 + 8;
                if (*pcVar4 != *pcVar6) break;
                pcVar5 = pcVar4;
                if (pcVar3 + 0x102 <= pcVar4) break;
            }
            pcVar4 = pcVar4 + (0x102 - reinterpret_cast<intptr_t>(pcVar3 + 0x102));
            if (reinterpret_cast<intptr_t>(pcVar7) < reinterpret_cast<intptr_t>(pcVar4)) {
                *reinterpret_cast<uint32_t*>(s + 0x68) = param_1;
                if (reinterpret_cast<intptr_t>(local_10) <= reinterpret_cast<intptr_t>(pcVar4)) break;
                local_5 = (pcVar3 + reinterpret_cast<intptr_t>(pcVar4))[-1];
                local_6 = pcVar3[reinterpret_cast<intptr_t>(pcVar4)];
                pcVar7 = pcVar4;
            }
        }
        pcVar4 = pcVar7;
        param_1 = *reinterpret_cast<uint16_t*>(
            static_cast<intptr_t>(*reinterpret_cast<int32_t*>(s + 0x38)) +
            (*reinterpret_cast<uint32_t*>(s + 0x2c) & param_1) * 2);
        if (param_1 <= local_14) break;
        local_c = local_c - 1;
        pcVar7 = pcVar4;
    } while (local_c != 0);
    if (pcVar4 <= pcVar2) {
        pcVar2 = pcVar4;
    }
    return pcVar2;
}

// 0x692839 — observed shape
// Bit-buffer refill loop. Optionally slides the pending region down by
// self[9] bytes and saturating-subtracts both ushort ring counters, then pulls
// min(stream[1], self[0xd]-self[0x19]-self[0x1b]) bytes from the stream object
// at self[0] into self[0xc]+self[0x1b]+self[0x19], updates the partial-code
// accumulator self[0x10] once self[0x1b] exceeds 2, and loops while the stream
// still has data and the 0x105 pending-byte cap is not exceeded. The receiver
// arrives in EBX in the listing.
void FUN_00692839(uint32_t* self)
{
    uint32_t uVar1 = self[9];
    do {
        uint32_t uVar8 = self[0x19];
        uint32_t uVar5 = (self[0xd] - uVar8) - self[0x1b];
        // LAB_0069286f: shift the pending window down by uVar1 bytes, then
        // saturating-subtract uVar1 from the two ushort counters.
        auto shift_down = [&]() {
            if ((uVar1 - 0x106u) + self[9] <= uVar8) {
                uint8_t* base = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(self[0xc]));
                uint8_t* puVar10 = base + uVar1;
                uint8_t* puVar11 = base;
                for (uint32_t uVar8w = uVar1 >> 2; uVar8w != 0; --uVar8w) {
                    *reinterpret_cast<uint32_t*>(puVar11) = *reinterpret_cast<uint32_t*>(puVar10);
                    puVar10 += 4;
                    puVar11 += 4;
                }
                for (uint32_t uVar8b = uVar1 & 3; uVar8b != 0; --uVar8b) {
                    *puVar11 = *puVar10;
                    ++puVar10;
                    ++puVar11;
                }
                int32_t iVar9 = static_cast<int32_t>(self[0x11]);
                self[0x1a] = self[0x1a] - uVar1;
                self[0x19] = self[0x19] - uVar1;
                self[0x15] = self[0x15] - uVar1;
                uint16_t* puVar6 = reinterpret_cast<uint16_t*>(
                    static_cast<uintptr_t>(self[0xf]) + iVar9 * 2);
                do {
                    --puVar6;
                    --iVar9;
                    *puVar6 = sub_saturate16(*puVar6, static_cast<uint16_t>(uVar1));
                } while (iVar9 != 0);
                puVar6 = reinterpret_cast<uint16_t*>(
                    static_cast<uintptr_t>(self[0xe]) + uVar1 * 2);
                uint32_t uVar8n = uVar1;
                do {
                    --puVar6;
                    --uVar8n;
                    *puVar6 = sub_saturate16(*puVar6, static_cast<uint16_t>(uVar1));
                } while (uVar8n != 0);
                uVar5 = uVar5 + uVar1;
            }
        };
        if (uVar5 == 0) {
            if (uVar8 == 0 && self[0x1b] == 0) {
                uVar5 = uVar1;
            } else {
                shift_down();
            }
        } else if (uVar5 != 0xffffffffu) {
            shift_down();
        } else {
            uVar5 = 0xfffffffeu;
        }
        int32_t* piVar2 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(self[0]));
        if (piVar2[1] == 0) {
            return;
        }
        int32_t iVar9 = static_cast<int32_t>(self[0x1b]);
        int32_t iVar3 = static_cast<int32_t>(self[0x19]);
        uint32_t uVar8s = static_cast<uint32_t>(piVar2[1]);
        int32_t iVar4 = static_cast<int32_t>(self[0xc]);
        uint32_t local_8 = uVar8s;
        if (uVar5 < uVar8s) {
            local_8 = uVar5;
        }
        if (local_8 == 0) {
            local_8 = 0;
        } else {
            piVar2[1] = static_cast<int32_t>(uVar8s - local_8);
            if (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(piVar2[7]) + 0x18) == 0) {
                piVar2[0xc] = FUN_006ae438(piVar2[0xc], piVar2[0], static_cast<int32_t>(local_8));
            }
            const uint8_t* puVar10 = reinterpret_cast<const uint8_t*>(
                static_cast<uintptr_t>(piVar2[0]));
            uint8_t* puVar11 = reinterpret_cast<uint8_t*>(
                static_cast<uintptr_t>(static_cast<uint32_t>(iVar9 + iVar3 + iVar4)));
            for (uint32_t uVar8w = local_8 >> 2; uVar8w != 0; --uVar8w) {
                *reinterpret_cast<uint32_t*>(puVar11) = *reinterpret_cast<const uint32_t*>(puVar10);
                puVar10 += 4;
                puVar11 += 4;
            }
            for (uint32_t uVar8b = local_8 & 3; uVar8b != 0; --uVar8b) {
                *puVar11 = *puVar10;
                ++puVar10;
                ++puVar11;
            }
            piVar2[0] = piVar2[0] + static_cast<int32_t>(local_8);
            piVar2[2] = piVar2[2] + static_cast<int32_t>(local_8);
        }
        self[0x1b] = self[0x1b] + local_8;
        if (2 < self[0x1b]) {
            uint32_t uVar8c = *reinterpret_cast<uint8_t*>(
                static_cast<uintptr_t>(self[0x19] + self[0xc]));
            self[0x10] = uVar8c;  // dead store in the listing; recomputed below
            self[0x10] = (uVar8c << (self[0x14] & 0x1f) ^
                          static_cast<uint32_t>(reinterpret_cast<uint8_t*>(
                              static_cast<uintptr_t>(self[0x19] + self[0xc]))[1])) & self[0x13];
        }
        if (0x105 < self[0x1b]) {
            return;
        }
        if (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(self[0]) + 4) == 0) {
            return;
        }
    } while (true);
}

// 0x692991 — observed shape
// Pulls decoded bytes for the pending region: refills via FUN_00692839 while
// fewer than two bytes are pending, flushes the ready span through
// FUN_006af7c4 and FUN_0069269b, and returns 0 (drained), 1/2 (output present,
// 2 when param_2 == 4) according to the stream state.
char FUN_00692991(int* param_1, int param_2)
{
    uint32_t uVar5 = 0xffff;
    if (static_cast<uint32_t>(param_1[3] - 5) < 0xffffu) {
        uVar5 = static_cast<uint32_t>(param_1[3] - 5);
    }
    do {
        uint32_t uVar3 = static_cast<uint32_t>(param_1[0x1b]);
        if (uVar3 < 2) {
            FUN_00692839(reinterpret_cast<uint32_t*>(param_1));
            uVar3 = static_cast<uint32_t>(param_1[0x1b]);
            if (uVar3 == 0) {
                if (param_2 == 0) {
                    return '\0';
                }
                int32_t iVar2 = param_1[0x15];
                int32_t iVar4 = iVar2 < 0 ? 0 : param_1[0xc] + iVar2;
                FUN_006af7c4(param_1, iVar4, param_1[0x19] - iVar2, param_2 == 4);
                param_1[0x15] = param_1[0x19];
                FUN_0069269b(param_1);
                if (*reinterpret_cast<int32_t*>(*param_1 + 0x10) != 0) {
                    return static_cast<char>((param_2 == 4) * '\x02' + '\x01');
                }
                if (param_2 == 4) {
                    return '\x02';
                }
                return '\0';
            }
        }
        param_1[0x19] = param_1[0x19] + static_cast<int32_t>(uVar3);
        int32_t iVar2 = param_1[0x15];
        param_1[0x1b] = 0;
        uVar3 = static_cast<uint32_t>(iVar2) + uVar5;
        if (param_1[0x19] == 0 || uVar3 <= static_cast<uint32_t>(param_1[0x19])) {
            param_1[0x1b] = param_1[0x19] - static_cast<int32_t>(uVar3);
            param_1[0x19] = static_cast<int32_t>(uVar3);
            int32_t iVar4 = iVar2 < 0 ? 0 : param_1[0xc] + iVar2;
            FUN_006af7c4(param_1, iVar4, static_cast<int32_t>(uVar3) - iVar2, 0);
            param_1[0x15] = param_1[0x19];
            FUN_0069269b(param_1);
            if (*reinterpret_cast<int32_t*>(*param_1 + 0x10) == 0) {
                return '\0';
            }
        }
        iVar2 = param_1[0x15];
        if (static_cast<uint32_t>(param_1[9]) - 0x106u <= static_cast<uint32_t>(param_1[0x19] - iVar2)) {
            int32_t iVar4 = iVar2 < 0 ? 0 : param_1[0xc] + iVar2;
            FUN_006af7c4(param_1, iVar4, param_1[0x19] - iVar2, 0);
            param_1[0x15] = param_1[0x19];
            FUN_0069269b(param_1);
            if (*reinterpret_cast<int32_t*>(*param_1 + 0x10) == 0) {
                return '\0';
            }
        }
    } while (true);
}

// 0x6930ca — observed shape
// Resets the decoder cursors at +0x14, +0x8 and +0x18, seeds the state word at
// *self[0x1c] with 7 when its +0xc field is zero, and re-enters FUN_006af9ad
// with the block at self[0x1c]+0x14. Returns -2 when the receiver or its
// block is null.
int32_t FUN_006930ca(int param_1)
{
    if (param_1 == 0) {
        return -2;
    }
    uint8_t* obj = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(obj + 0x1c);
    if (puVar1 == nullptr) {
        return -2;
    }
    *reinterpret_cast<uint32_t*>(obj + 0x14) = 0;
    *reinterpret_cast<uint32_t*>(obj + 8) = 0;
    *reinterpret_cast<uint32_t*>(obj + 0x18) = 0;
    // ~-(uint)(puVar1[3] != 0) & 7
    *puVar1 = (puVar1[3] == 0) ? 7u : 0u;
    FUN_006af9ad(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar1) + 0x14), param_1, 0);
    return 0;
}

// 0x693109 — observed shape
// Releases the decoder: calls FUN_006b01dd on the block field at +0x14 when
// present, then invokes the release callback stored at +0x24 with the context
// at +0x28 and the block at +0x1c, and clears +0x1c. Returns -2 for a null
// receiver, block or callback.
int32_t FUN_00693109(int param_1)
{
    if (param_1 == 0) {
        return -2;
    }
    uint8_t* obj = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    int32_t iVar1 = *reinterpret_cast<int32_t*>(obj + 0x1c);
    if (iVar1 == 0) {
        return -2;
    }
    if (*reinterpret_cast<int32_t*>(obj + 0x24) == 0) {
        return -2;
    }
    uint8_t* block = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1));
    if (*reinterpret_cast<int32_t*>(block + 0x14) != 0) {
        FUN_006b01dd(*reinterpret_cast<uint32_t*>(block + 0x14), param_1);
    }
    PiratesFreeFn fn = *reinterpret_cast<PiratesFreeFn*>(obj + 0x24);
    fn(*reinterpret_cast<uint32_t*>(obj + 0x28),
       reinterpret_cast<void*>(static_cast<intptr_t>(iVar1)));
    *reinterpret_cast<int32_t*>(obj + 0x1c) = 0;
    return 0;
}

// 0x693146 — observed shape
// Initializes a deflate-style stream context. Requires param_3 to start with
// '1' and param_4 == 0x38, installs default allocator/release callbacks when
// absent, allocates the 0x18-byte block sized by |param_2| (valid 8..15), and
// allocates the window through FUN_006afa13 with table 0x6ae438 for positive
// sizes and 0 for negative ones.
int32_t FUN_00693146(int param_1, int param_2, char* param_3, int param_4)
{
    if (param_3 == nullptr || *param_3 != '1' || param_4 != 0x38) {
        return -6;
    }
    if (param_1 == 0) {
        return -2;
    }
    uint8_t* obj = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    int32_t uVar2;
    *reinterpret_cast<uint32_t*>(obj + 0x18) = 0;
    if (*reinterpret_cast<int32_t*>(obj + 0x20) == 0) {
        *reinterpret_cast<PiratesAllocFn*>(obj + 0x20) = &FUN_006af97b;
        *reinterpret_cast<uint32_t*>(obj + 0x28) = 0;
    }
    if (*reinterpret_cast<int32_t*>(obj + 0x24) == 0) {
        *reinterpret_cast<PiratesFreeFn*>(obj + 0x24) = &LAB_006af997;
    }
    PiratesAllocFn alloc = *reinterpret_cast<PiratesAllocFn*>(obj + 0x20);
    int32_t iVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(
        alloc(*reinterpret_cast<uint32_t*>(obj + 0x28), 1, 0x18)));
    *reinterpret_cast<int32_t*>(obj + 0x1c) = iVar1;
    if (iVar1 == 0) {
        return -4;
    }
    uint8_t* block = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1));
    *reinterpret_cast<uint32_t*>(block + 0x14) = 0;
    *reinterpret_cast<uint32_t*>(block + 0xc) = 0;
    if (param_2 < 0) {
        param_2 = -param_2;
        *reinterpret_cast<uint32_t*>(block + 0xc) = 1;
    }
    if (param_2 < 8 || 0xf < param_2) {
        uVar2 = -2;
    } else {
        *reinterpret_cast<int32_t*>(block + 0x10) = param_2;
        // ~-(uint)(block[0xc] != 0) & 0x6ae438
        uint32_t table = (*reinterpret_cast<int32_t*>(block + 0xc) != 0) ? 0u : 0x6ae438u;
        uVar2 = static_cast<int32_t>(FUN_006afa13(param_1, table, 1u << (param_2 & 0x1f)));
        *reinterpret_cast<uint32_t*>(block + 0x14) = static_cast<uint32_t>(uVar2);
        if (*reinterpret_cast<int32_t*>(block + 0x14) != 0) {
            FUN_006930ca(param_1);
            return 0;
        }
        uVar2 = -4;
    }
    FUN_00693109(param_1);
    return uVar2;
}

// 0x6935fb — observed shape
// Reads four bytes from the stream via FUN_00658adc, then (when the context
// flags at +0x10c/+0x5c do not short-circuit) compares FUN_0069359e's result
// with the code word at +0x100. Returns true when they differ.
bool FUN_006935fb(int param_1)
{
    uint8_t* obj = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    int32_t iVar1 = param_1;
    bool bVar3 = true;
    if ((*(obj + 0x10c) & 0x20) == 0) {
        if ((*(obj + 0x5d) & 8) != 0) {
            bVar3 = false;
        }
    } else if ((*reinterpret_cast<uint32_t*>(obj + 0x5c) & 0x300) == 0x300) {
        bVar3 = false;
    }
    FUN_00658adc(param_1, &param_1, 4);
    if (bVar3) {
        int32_t iVar2 = FUN_0069359e(&param_1);
        bVar3 = iVar2 != *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x100);
    } else {
        bVar3 = false;
    }
    return bVar3;
}

// 0x6936bf — observed shape
// Expands one bit-packed row at *(self+0xdc)+1 into param_2 according to the
// depth byte at self+0xfb: 0xff requests a raw master copy, 1/2/4 unpack
// sub-byte pixels (with param_3 acting as an 8-column write mask), any other
// depth copies whole pixels of depth/8 bytes.
void FUN_006936bf(int param_1, uint8_t* param_2, uint32_t param_3)
{
    uint8_t* obj = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    uint8_t* pbVar6 = param_2;
    uint8_t depth = *reinterpret_cast<uint8_t*>(obj + 0xfb);
    uint32_t uVar4 = depth;
    if (param_3 == 0xff) {
        uVar4 = uVar4 * static_cast<uint32_t>(*reinterpret_cast<int32_t*>(obj + 0xb8)) + 7;
        uint8_t* pbVar8 = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0xdc))) + 1;
        copy_words_then_bytes(pbVar6, pbVar8, uVar4);
    } else if (depth == 1) {
        uint8_t* pbVar8 = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0xdc))) + 1;
        int32_t count = *reinterpret_cast<int32_t*>(obj + 0xb8);
        uint8_t colMask = 0x80;
        int iVar7 = 7;
        while (count != 0) {
            if ((colMask & static_cast<uint8_t>(param_3)) != 0) {
                *pbVar6 = static_cast<uint8_t>(
                    (static_cast<uint8_t>(0x7f7fu >> ((7 - iVar7) & 0x1f)) & *pbVar6) |
                    static_cast<uint8_t>((((*pbVar8 >> (iVar7 & 0x1f)) & 1u) << (iVar7 & 0x1f))));
            }
            if (iVar7 == 0) {
                ++pbVar8;
                iVar7 = 7;
                ++pbVar6;
            } else {
                --iVar7;
            }
            colMask = (colMask == 1) ? static_cast<uint8_t>(0x80) : static_cast<uint8_t>(colMask >> 1);
            --count;
        }
    } else if (depth == 2) {
        uint8_t* pbVar8 = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0xdc))) + 1;
        int32_t count = *reinterpret_cast<int32_t*>(obj + 0xb8);
        uint8_t colMask = 0x80;
        int iVar7 = 6;
        while (count != 0) {
            if ((colMask & static_cast<uint8_t>(param_3)) != 0) {
                *pbVar6 = static_cast<uint8_t>(
                    (static_cast<uint8_t>(0x3f3fu >> ((6 - iVar7) & 0x1f)) & *pbVar6) |
                    static_cast<uint8_t>((((*pbVar8 >> (iVar7 & 0x1f)) & 3u) << (iVar7 & 0x1f))));
            }
            if (iVar7 == 0) {
                ++pbVar8;
                iVar7 = 6;
                ++pbVar6;
            } else {
                iVar7 = iVar7 - 2;
            }
            colMask = (colMask == 1) ? static_cast<uint8_t>(0x80) : static_cast<uint8_t>(colMask >> 1);
            --count;
        }
    } else if (depth == 4) {
        uint8_t* pbVar8 = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0xdc))) + 1;
        int32_t count = *reinterpret_cast<int32_t*>(obj + 0xb8);
        uint8_t colMask = 0x80;
        int iVar7 = 4;
        while (count != 0) {
            if ((colMask & static_cast<uint8_t>(param_3)) != 0) {
                *pbVar6 = static_cast<uint8_t>(
                    (static_cast<uint8_t>(0xf0fu >> ((4 - iVar7) & 0x1f)) & *pbVar6) |
                    static_cast<uint8_t>((((*pbVar8 >> (iVar7 & 0x1f)) & 0xfu) << (iVar7 & 0x1f))));
            }
            if (iVar7 == 0) {
                ++pbVar8;
                iVar7 = 4;
                ++pbVar6;
            } else {
                iVar7 = iVar7 - 4;
            }
            colMask = (colMask == 1) ? static_cast<uint8_t>(0x80) : static_cast<uint8_t>(colMask >> 1);
            --count;
        }
    } else {
        int32_t count = *reinterpret_cast<int32_t*>(obj + 0xb8);
        uint32_t uVar4b = static_cast<uint32_t>(depth >> 3);
        uint8_t* pbVar8 = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0xdc))) + 1;
        uint8_t bVar3 = 0x80;
        if (count != 0) {
            do {
                if ((bVar3 & static_cast<uint8_t>(param_3)) != 0) {
                    copy_words_then_bytes(pbVar6, pbVar8, depth);
                }
                pbVar8 += uVar4b;
                pbVar6 += uVar4b;
                bVar3 = (bVar3 == 1) ? static_cast<uint8_t>(0x80) : static_cast<uint8_t>(bVar3 >> 1);
                --count;
            } while (count != 0);
        }
    }
}

// 0x6938d7 — observed shape
// Expands the packed pixel matrix starting at param_2 into depth-strided rows
// (1/2/4-bit unpacking or whole-pixel copies for other depths), with the
// destination scanned bottom-up. param_1 holds the source pixel width at
// [0]; the row-multiplier table DAT_006f1260[param_3] supplies the row count.
// On exit [0] becomes width*rows and [1] the byte size (depth*width+7)/8.
void FUN_006938d7(uint32_t* param_1, int* param_2, int param_3)
{
    if (param_2 == nullptr || param_1 == nullptr) {
        return;
    }
    int32_t local_18[4];
    local_18[3] = DAT_006f1260[param_3];
    uint32_t uVar3 = *param_1;
    uint32_t uVar4 = uVar3 * static_cast<uint32_t>(local_18[3]);
    uint8_t bVar1 = reinterpret_cast<uint8_t*>(param_1)[0xb];
    uint8_t* base = reinterpret_cast<uint8_t*>(param_2);
    if (bVar1 == 1) {
        uint8_t* pbVar10 = base + ((uVar3 - 1) >> 3);
        uint8_t* pbVar9 = base + ((uVar4 - 1) >> 3);
        uint32_t local_8 = 7 - ((uVar3 - 1) & 7);
        uint32_t dstShift = 7 - ((uVar4 - 1) & 7);
        if (uVar3 != 0) {
            uint32_t n = 0;
            do {
                uint8_t bVar1b = *pbVar10;
                if (0 < local_18[3]) {
                    int32_t k = local_18[3];
                    do {
                        *pbVar9 = static_cast<uint8_t>(
                            (static_cast<uint8_t>(0x7f7fu >> ((7 - dstShift) & 0x1f)) & *pbVar9) |
                            static_cast<uint8_t>((((bVar1b >> (local_8 & 0x1f)) & 1u) << (dstShift & 0x1f))));
                        if (dstShift == 7) {
                            dstShift = 0;
                            --pbVar9;
                        } else {
                            ++dstShift;
                        }
                        --k;
                    } while (k != 0);
                }
                if (local_8 == 7) {
                    local_8 = 0;
                    --pbVar10;
                } else {
                    ++local_8;
                }
                ++n;
            } while (n < *param_1);
        }
    } else if (bVar1 == 2) {
        uint8_t* pbVar10 = base + ((uVar3 - 1) >> 2);
        uint8_t* pbVar9 = base + ((uVar4 - 1) >> 2);
        uint32_t local_8 = (3 - ((uVar3 - 1) & 3)) * 2;
        uint32_t dstShift = (3 - ((uVar4 - 1) & 3)) * 2;
        if (uVar3 != 0) {
            uint32_t n = 0;
            do {
                uint8_t bVar1b = *pbVar10;
                if (0 < local_18[3]) {
                    int32_t k = local_18[3];
                    do {
                        *pbVar9 = static_cast<uint8_t>(
                            (static_cast<uint8_t>(0x3f3fu >> ((6 - dstShift) & 0x1f)) & *pbVar9) |
                            static_cast<uint8_t>((((bVar1b >> (local_8 & 0x1f)) & 3u) << (dstShift & 0x1f))));
                        if (dstShift == 6) {
                            dstShift = 0;
                            --pbVar9;
                        } else {
                            dstShift = dstShift + 2;
                        }
                        --k;
                    } while (k != 0);
                }
                if (local_8 == 6) {
                    local_8 = 0;
                    --pbVar10;
                } else {
                    local_8 = local_8 + 2;
                }
                ++n;
            } while (n < *param_1);
        }
    } else if (bVar1 == 4) {
        uint8_t* pbVar10 = base + ((uVar3 - 1) >> 1);
        uint8_t* pbVar9 = base + ((uVar4 - 1) >> 1);
        // (x & 1) * -4 + 4
        uint32_t local_8 = ((uVar3 - 1) & 1) ? 0u : 4u;
        uint32_t dstShift = ((uVar4 - 1) & 1) ? 0u : 4u;
        if (uVar3 != 0) {
            uint32_t n = 0;
            do {
                uint8_t bVar1b = *pbVar10;
                if (0 < local_18[3]) {
                    int32_t k = local_18[3];
                    do {
                        *pbVar9 = static_cast<uint8_t>(
                            (static_cast<uint8_t>(0xf0fu >> ((4 - dstShift) & 0x1f)) & *pbVar9) |
                            static_cast<uint8_t>((((bVar1b >> (local_8 & 0x1f)) & 0xfu) << (dstShift & 0x1f))));
                        if (dstShift == 4) {
                            dstShift = 0;
                            --pbVar9;
                        } else {
                            dstShift = dstShift + 4;
                        }
                        --k;
                    } while (k != 0);
                }
                if (local_8 == 4) {
                    local_8 = 0;
                    --pbVar10;
                } else {
                    local_8 = local_8 + 4;
                }
                ++n;
            } while (n < *param_1);
        }
    } else {
        uint32_t uVar6 = static_cast<uint32_t>(bVar1 >> 3);
        int* piVar5 = reinterpret_cast<int*>(base + (uVar3 - 1) * uVar6);
        int* piVar2 = reinterpret_cast<int*>(base + (uVar4 - 1) * uVar6);
        uint32_t n = 0;
        if (uVar3 != 0) {
            do {
                int* piVar7 = piVar5;
                int* piVar8 = local_18;
                for (uint32_t w = static_cast<uint32_t>(bVar1 >> 5); w != 0; --w) {
                    *piVar8 = *piVar7;
                    ++piVar7;
                    ++piVar8;
                }
                for (uint32_t b = uVar6 & 3; b != 0; --b) {
                    *reinterpret_cast<char*>(piVar8) = static_cast<char>(*piVar7);
                    piVar7 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(piVar7) + 1);
                    piVar8 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(piVar8) + 1);
                }
                int32_t iVar2 = local_18[3];
                if (0 < iVar2) {
                    int32_t k = iVar2;
                    do {
                        int* piVar7b = reinterpret_cast<int*>(
                            reinterpret_cast<uint8_t*>(piVar2) - uVar6);
                        int* piVar8b = local_18;
                        for (uint32_t w = static_cast<uint32_t>(bVar1 >> 5); w != 0; --w) {
                            *piVar2 = *piVar8b;
                            ++piVar8b;
                            ++piVar2;
                        }
                        --k;
                        for (uint32_t b = uVar6 & 3; b != 0; --b) {
                            *reinterpret_cast<char*>(piVar2) = static_cast<char>(*piVar8b);
                            piVar8b = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(piVar8b) + 1);
                            piVar2 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(piVar2) + 1);
                        }
                        piVar2 = piVar7b;
                    } while (k != 0);
                }
                piVar5 = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(piVar5) - uVar6);
                ++n;
            } while (n < *param_1);
        }
    }
    *param_1 = uVar4;
    param_1[1] = (static_cast<uint32_t>(reinterpret_cast<uint8_t*>(param_1)[0xb]) * uVar4 + 7) >> 3;
}

// 0x693d1d — observed shape
// Allocates the two working buffers of a streaming decoder: derives the
// per-row stride/window size from the flags at +0x60, the sample byte at
// +0x114 and the DAT_006f1244/DAT_006f1260 tables, sizes the scratch buffer
// through FUN_006924f1 and zero-fills the row buffer with FUN_00692570, then
// sets bit 0x40 in the flags at +0x5c.
void FUN_00693d1d(int param_1)
{
    uint8_t* obj = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    *reinterpret_cast<uint32_t*>(obj + 0x68) = 0;
    FUN_00658825(param_1);
    uint32_t uVar3 = *reinterpret_cast<uint32_t*>(obj + 0xbc);
    int32_t iVar6;
    if (*reinterpret_cast<uint8_t*>(obj + 0x113) == 0) {
        iVar6 = *reinterpret_cast<int32_t*>(obj + 0xb8);
        *reinterpret_cast<uint32_t*>(obj + 0xc0) = uVar3;
        *reinterpret_cast<int32_t*>(obj + 0xd0) = iVar6;
        *reinterpret_cast<int32_t*>(obj + 0xcc) = *reinterpret_cast<int32_t*>(obj + 0xc8) + 1;
    } else {
        if ((*reinterpret_cast<uint8_t*>(obj + 0x60) & 2) == 0) {
            uVar3 = (uVar3 + 7) >> 3;
        }
        iVar6 = *reinterpret_cast<int32_t*>(obj + 0xb8);
        *reinterpret_cast<uint32_t*>(obj + 0xc0) = uVar3;
        // &DAT_006f1244 + (byte at +0x114) * 4, same element index for both tables.
        uint32_t idx = *reinterpret_cast<uint8_t*>(obj + 0x114);
        int32_t base = DAT_006f1244[idx];
        uint32_t step = static_cast<uint32_t>(DAT_006f1260[idx]);
        uVar3 = (static_cast<uint32_t>(iVar6 - base) + 0xffffffffu + step) / step;
        *reinterpret_cast<uint32_t*>(obj + 0xd0) = uVar3;
        *reinterpret_cast<uint32_t*>(obj + 0xcc) =
            ((static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(obj + 0x119)) * uVar3 + 7) >> 3) + 1;
    }
    uVar3 = *reinterpret_cast<uint8_t*>(obj + 0x119);
    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(obj + 0x60);
    if ((uVar2 & 4) != 0 && *reinterpret_cast<uint8_t*>(obj + 0x117) < 8) {
        uVar3 = 8;
    }
    if ((uVar2 & 0x1000) != 0) {
        char cVar1 = *reinterpret_cast<char*>(obj + 0x116);
        if (cVar1 == '\x03') {
            uVar3 = (static_cast<uint32_t>(*reinterpret_cast<int16_t*>(obj + 0x10a) != 0) * 8) + 0x18;
        } else if (cVar1 == '\0') {
            if (uVar3 < 8) {
                uVar3 = 8;
            }
            if (*reinterpret_cast<int16_t*>(obj + 0x10a) != 0) {
                uVar3 = uVar3 * 2;
            }
        } else if (cVar1 == '\x02' && *reinterpret_cast<int16_t*>(obj + 0x10a) != 0) {
            uVar3 = (uVar3 << 2) / 3;
        }
    }
    if (static_cast<char>(uVar2 >> 8) < '\0') {
        char cVar1 = *reinterpret_cast<char*>(obj + 0x116);
        if (cVar1 == '\x03') {
            uVar3 = 0x20;
        } else if (cVar1 == '\0') {
            // ((8 < uVar3) - 1) & 0xfffffff0, plus 0x20
            uVar3 = ((static_cast<uint32_t>(8 < uVar3) - 1) & 0xfffffff0u) + 0x20;
        } else if (cVar1 == '\x02') {
            // ((0x20 < uVar3) - 1) & 0xffffffe0, plus 0x40
            uVar3 = ((static_cast<uint32_t>(0x20 < uVar3) - 1) & 0xffffffe0u) + 0x40;
        }
    }
    void* uVar5 = FUN_006924f1(
        param_1,
        static_cast<int32_t>(((((static_cast<uint32_t>(iVar6) + 7u) & 0xfffffff8u) * uVar3 + 7) >> 3) +
                             1 + ((static_cast<int32_t>(uVar3 + 7)) >> 3)));
    *reinterpret_cast<void**>(obj + 0xdc) = uVar5;
    uVar5 = FUN_006924f1(param_1, *reinterpret_cast<int32_t*>(obj + 0xc8) + 1);
    *reinterpret_cast<void**>(obj + 0xd8) = uVar5;
    FUN_00692570(param_1, uVar5, 0, static_cast<uint32_t>(*reinterpret_cast<int32_t*>(obj + 0xc8)) + 1);
    *reinterpret_cast<uint32_t*>(obj + 0x5c) = *reinterpret_cast<uint32_t*>(obj + 0x5c) | 0x40;
}

// 0x694868 — observed shape
// qsort-style comparator over the entry array at param_3+0x10: compares the
// dword at each entry+0x8, descending on that key and ascending on the index
// when the keys are equal.
int FUN_00694868(uint32_t param_1, uint32_t param_2, int param_3)
{
    uint8_t* entries = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_3));
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(entries + 0x10)) + param_1 * 4);
    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(entries + 0x10)) + param_2 * 4);
    uVar1 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(uVar1) + 8);
    uVar2 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(uVar2) + 8);
    if (uVar2 <= uVar1) {
        if (uVar2 < uVar1) {
            return -1;
        }
        if (param_1 <= param_2) {
            return -static_cast<int>(param_1 < param_2);
        }
    }
    return 1;
}
