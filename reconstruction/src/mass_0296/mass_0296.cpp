// Reconstruction batch mass_0296
// Sid Meier's Pirates! (2004), PE32 i386
// Derived from Ghidra 12.2 pseudocode, analysis profile 59fe0f4e...
// All offsets/constants preserved from the provider listing.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern "C" void* __cdecl FUN_00533c78(uint32_t size);
extern "C" uint32_t __cdecl FUN_0064e847(uint32_t param_1, uint32_t param_2, int32_t param_3);
extern "C" int32_t __cdecl FUN_006294f9(uint32_t size, int32_t** out);
extern "C" void __cdecl operator_delete(void* p);

extern const char* PTR_s_D3DX_Effect_Compiler_0071ed7c; // 0x71ed7c

// 0x63ea6b — observed shape
uint32_t FUN_0063ea6b(uint8_t* param_1, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    if (reinterpret_cast<uintptr_t>(param_1) > 0xffff) {
        if (reinterpret_cast<intptr_t>(param_1) < 1) {
            // Negative "pointer" is really a tagged handle: bitwise complement.
            uint32_t rec = ~static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
            if (*(int32_t*)(rec + 0x10) == 3 &&
                *(uint32_t*)(rec + 0x14) < *(uint32_t*)(base + 0xa8) &&
                *(int32_t*)(rec + 0x18) == 0 &&
                *(int32_t*)(rec + 0x1c) == 0 &&
                *(int32_t*)(rec + 8) == -1) {
                uint32_t idx = *(uint32_t*)(rec + 0x14);
                uint32_t obj = *(uint32_t*)(*(int32_t*)(base + 0xb0) + idx * 4);
                if ((*(uint8_t*)(obj + 0x28) & 4) != 0) {
                    return 0;
                }
                return obj;
            }
        }
        else {
            // Small positive value: name lookup in the 0x50-byte entry table.
            uint32_t found = 0;
            uint32_t count = *(uint32_t*)(base + 0x98);
            if (count != 0) {
                int32_t* entry = reinterpret_cast<int32_t*>(base + 0x9c + 0x2c);
                do {
                    int32_t table;
                    if (entry[5] == 0) {
                        table = *(int32_t*)(base + 0x20);
                    }
                    else {
                        table = *(int32_t*)(*(int32_t*)(base + 0x38) + 0x10);
                    }
                    int32_t* hdr =
                        reinterpret_cast<int32_t*>(table + *(int32_t*)(table + 8 + *entry));
                    const uint8_t* name = param_1;
                    bool equal = false;
                    if (*hdr != 0) {
                        const uint8_t* s = reinterpret_cast<const uint8_t*>(hdr + 1);
                        if (param_1 != nullptr) {
                            // Inlined byte compare (2 bytes per iteration).
                            while (true) {
                                uint8_t c = *s;
                                if (c != *name) break;
                                if (c == 0) { equal = true; break; }
                                uint8_t c2 = s[1];
                                if (c2 != name[1]) break;
                                s += 2;
                                name += 2;
                                if (c2 == 0) { equal = true; break; }
                            }
                        }
                    }
                    if (equal) break;
                    found++;
                    entry += 0x14;
                } while (found < count);
            }
            if (found != count) {
                return found * 0x50 + *(int32_t*)(base + 0x9c);
            }
        }
    }
    return 0;
}

// 0x63eb76 — observed shape
int FUN_0063eb76(int param_1, int* param_2, int* param_3)
{
    int iVar1 = *param_2;
    int32_t* piVar4 = reinterpret_cast<int32_t*>(param_1 + iVar1);
    int iVar7 = piVar4[4];
    int iVar5 = piVar4[1];
    int desc;
    int returned;
    int advanced;

    if (iVar7 == 0) {
        iVar7 = 1;
    }
    if (-1 < iVar5) {
        if (iVar5 < 2) {
            desc = *piVar4;
            if (desc == 1 || desc == 2 || desc == 3) {
                returned = 4;
                advanced = 4;
            }
            else {
                returned = 0;
                advanced = 0;
            }
            *param_2 = iVar1 + 0x1c;
            *param_3 = *param_3 + advanced * iVar7 * 4;
            return returned * iVar7 * 4;
        }
        if (iVar5 < 4) {
            desc = *piVar4;
            if (desc == 1 || desc == 2 || desc == 3) {
                returned = 4;
                advanced = 4;
            }
            else {
                returned = 0;
                advanced = 0;
            }
            *param_2 = iVar1 + 0x1c;
            *param_3 = *param_3 + advanced * iVar7 * 0x10;
            return returned * iVar7 * 0x10;
        }
        if (iVar5 == 4) {
            if ((*piVar4 < 10) || (0xe < *piVar4)) {
                returned = 4;
            }
            else {
                returned = 0;
            }
            *param_2 = iVar1 + 0x14;
            *param_3 = *param_3 + iVar7 * 4;
            return returned * iVar7;
        }
        if (iVar5 == 5) {
            int n = piVar4[5];
            int total = 0;
            int saved;
            *param_2 = iVar1 + 0x18;
            saved = *param_3;
            while (n != 0) {
                total += FUN_0063eb76(param_1, param_2, param_3);
                n--;
            }
            *param_3 = (*param_3 - saved) * (iVar7 - 1) + *param_3;
            return total * iVar7;
        }
    }
    return 0;
}

// 0x63ec91 — observed shape
int FUN_0063ec91(int param_1, int* param_2, int* param_3)
{
    int iVar2 = *param_2;
    int32_t* piVar1 = reinterpret_cast<int32_t*>(iVar2 + param_1);
    int iVar9 = piVar1[4];
    int iVar6 = piVar1[1];
    int iVar7;
    int desc;
    int per;
    int advanced;

    if (iVar9 == 0) {
        iVar9 = 1;
    }
    if (iVar6 < 0) {
        iVar7 = 0;
    }
    else {
        if (iVar6 < 4) {
            int a = piVar1[5];
            int b = piVar1[6];
            desc = *piVar1;
            if (desc == 1 || desc == 2 || desc == 3) {
                per = 4;
                advanced = 4;
            }
            else {
                per = 0;
                advanced = 0;
            }
            *param_2 = iVar2 + 0x1c;
            *param_3 = *param_3 + advanced * b * a * iVar9;
            iVar7 = b * a * per;
        }
        else if (iVar6 == 4) {
            if ((*piVar1 < 10) || (0xe < *piVar1)) {
                iVar7 = 4;
            }
            else {
                iVar7 = 0;
            }
            *param_2 = iVar2 + 0x14;
            *param_3 = *param_3 + iVar9 * 4;
        }
        else {
            int n;
            int total;
            int saved;
            if (iVar6 != 5) {
                return 0;
            }
            n = piVar1[5];
            total = 0;
            *param_2 = iVar2 + 0x18;
            saved = *param_3;
            while (n != 0) {
                total += FUN_0063ec91(param_1, param_2, param_3);
                n--;
            }
            *param_3 = (*param_3 - saved) * (iVar9 - 1) + *param_3;
            iVar7 = total;
        }
        iVar7 = iVar7 * iVar9;
    }
    return iVar7;
}

// 0x63ed81 — observed shape
uint32_t FUN_0063ed81(uint32_t param_1, uint32_t param_2, uint32_t param_3, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t uVar6;
    uint32_t span;
    int32_t* local_8;
    int32_t* node;

    if (param_1 == 0) {
        return 0;
    }
    if (static_cast<int32_t>(param_1) < 0) {
        uVar6 = ~param_1;
    }
    else {
        uVar6 = FUN_0064e847(param_1, param_3, 0);
        if (uVar6 == 0) {
            return 0;
        }
    }
    span = *(uint32_t*)(*(int32_t*)(uVar6 + 4) + 0x10);
    if (*(int32_t*)(uVar6 + 8) != -1) {
        return 0;
    }
    if (span == 0) {
        return 0;
    }
    if (span <= param_2) {
        return 0;
    }
    local_8 = nullptr;
    node = *(int32_t**)(uVar6 + 0x24);
    if (node != nullptr) {
        do {
            int32_t* cur = node;
            node = cur;
            if (param_2 <= static_cast<uint32_t>(cur[2])) break;
            node = reinterpret_cast<int32_t*>(cur[9]);
            local_8 = cur;
        } while (node != nullptr);
        if (node != nullptr && static_cast<uint32_t>(node[2]) <= param_2) {
            return static_cast<uint32_t>(~reinterpret_cast<uintptr_t>(node));
        }
    }
    node = reinterpret_cast<int32_t*>(FUN_00533c78(0x28));
    if (node == nullptr) {
        node = nullptr;
    }
    else {
        node[2] = -1;
        node[9] = 0;
        node[8] = 0;
        node[0] = 0;
        node[1] = 0;
    }
    if (node != nullptr) {
        uint32_t obj = *(uint32_t*)(*(int32_t*)(base + 0xb0) + *(int32_t*)(uVar6 + 0x14) * 4);
        int32_t cx = *(int32_t*)(obj + 0x2c) + *(int32_t*)(uVar6 + 0x18);
        int32_t cy = *(int32_t*)(obj + 0x30) + *(int32_t*)(uVar6 + 0x1c);
        uint32_t uVar3;
        uint32_t uVar2;
        int32_t ax;
        int32_t ay;
        int32_t bx;
        int32_t by;
        uint32_t obj3;
        int32_t iVar4;

        if (*(int32_t*)(obj + 0x40) == 0) {
            uVar3 = *(uint32_t*)(base + 0x20);
        }
        else {
            uVar3 = *(uint32_t*)(*(int32_t*)(base + 0x38) + 0x10);
        }
        ax = cx;
        ay = cy;
        uVar2 = FUN_0063ec91(uVar3, &ax, &ay);

        obj = *(uint32_t*)(*(int32_t*)(base + 0xb0) + *(int32_t*)(uVar6 + 0x14) * 4);
        if (*(int32_t*)(obj + 0x40) == 0) {
            uVar3 = *(uint32_t*)(base + 0x20);
        }
        else {
            uVar3 = *(uint32_t*)(*(int32_t*)(base + 0x38) + 0x10);
        }
        bx = cx;
        by = cy;
        FUN_0063eb76(uVar3, &bx, &by);

        node[4] = 3;
        node[5] = *(int32_t*)(uVar6 + 0x14);
        node[6] = *(int32_t*)(uVar6 + 0x18);
        node[7] = (static_cast<int32_t>(
                       (static_cast<uint32_t>(by) -
                        *(uint32_t*)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                 *(int32_t*)(uVar6 + 0x14) * 4) + 0x30) -
                        *(uint32_t*)(uVar6 + 0x1c)) /
                       span) *
                   static_cast<int32_t>(param_2)) +
                  *(int32_t*)(uVar6 + 0x1c);
        node[3] = static_cast<int32_t>(uVar2 / span);
        node[2] = static_cast<int32_t>(param_2);
        node[1] = *(int32_t*)(uVar6 + 4);

        obj3 = *(uint32_t*)(*(int32_t*)(base + 0xb0) + node[5] * 4);
        if (*(int32_t*)(obj3 + 0x40) == 0) {
            iVar4 = *(int32_t*)(base + 0x20);
        }
        else {
            iVar4 = *(int32_t*)(*(int32_t*)(base + 0x38) + 0x10);
        }
        node[0] = *(int32_t*)(obj3 + 0x30) + iVar4 + node[7];

        if (local_8 == nullptr) {
            node[9] = *(int32_t*)(uVar6 + 0x24);
            *(int32_t**)(uVar6 + 0x24) = node;
        }
        else {
            node[9] = local_8[9];
            local_8[9] = static_cast<int32_t>(reinterpret_cast<intptr_t>(node));
        }
        return static_cast<uint32_t>(~reinterpret_cast<uintptr_t>(node));
    }
    return 0;
}

// 0x63ef70 — observed shape
uint32_t FUN_0063ef70(char* param_1, int* param_2, void* param_3, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t* piVar4 = *reinterpret_cast<int32_t**>(reinterpret_cast<uint8_t*>(param_2) + 4);
    uint8_t* scratch;
    uint32_t uVar2;
    uint32_t local_10;
    uint32_t local_14;
    uint32_t local_c;
    uint32_t uVar10;
    size_t len1;
    size_t len2;
    int32_t* local_8;

    param_2 = reinterpret_cast<int32_t*>(
        *reinterpret_cast<int32_t*>(
            *reinterpret_cast<int32_t*>(base + 0x11c) +
            (*(int32_t*)(reinterpret_cast<uint8_t*>(param_2) + 0x14) - *(int32_t*)(base + 0xac)) * 4) +
        piVar4[2]);

    scratch = nullptr;
    local_8 = nullptr;
    if (*param_2 == 0) {
        param_2 = nullptr;
    }
    else {
        param_2 = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(param_2) + 1);
    }
    local_10 = static_cast<uint32_t>(*piVar4);
    local_14 = static_cast<uint32_t>(piVar4[1]);
    local_c = static_cast<uint32_t>(piVar4[4]);

    if (param_1 == nullptr || param_2 == nullptr) {
        uVar10 = 0x80004005;
        goto done;
    }

    len1 = std::strlen(param_1);
    len2 = std::strlen(reinterpret_cast<char*>(param_2));
    scratch = static_cast<uint8_t*>(FUN_00533c78(static_cast<uint32_t>(len1 + len2 + 2)));
    uVar2 = local_c;
    if (scratch == nullptr) {
        uVar10 = 0x8007000e;
        goto done;
    }
    // Build "name1@name2".
    scratch[0] = 0;
    std::memcpy(scratch, param_1, len1 + 1);
    scratch[len1] = '@';
    std::memcpy(scratch + len1 + 1, param_2, len2 + 1);

    if (local_c != 0) {
        local_8 = static_cast<int32_t*>(FUN_00533c78(local_c << 6));
        if (local_8 == nullptr) {
            uVar10 = 0x8007000e;
            goto cleanup;
        }
        {
            uint8_t* p = reinterpret_cast<uint8_t*>(local_8);
            for (uint32_t i = local_c * 16; i != 0; i--) {
                *reinterpret_cast<uint32_t*>(p) = 0;
                p += 4;
            }
        }
    }

    if (local_10 == 1) {
        if (local_c == 0) {
            uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*)>(
                *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x58))(
                param_3, reinterpret_cast<char*>(scratch), nullptr);
        }
        else {
            uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*, uint32_t)>(
                *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x60))(
                param_3, reinterpret_cast<char*>(scratch), local_8, local_c);
        }
    }
    else if (local_10 == 2) {
        if (local_c == 0) {
            uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*)>(
                *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x68))(
                param_3, reinterpret_cast<char*>(scratch), nullptr);
        }
        else {
            uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*, uint32_t)>(
                *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x70))(
                param_3, reinterpret_cast<char*>(scratch), local_8, local_c);
        }
    }
    else if (local_10 == 3) {
        if (local_14 == 0) {
            if (local_c == 0) {
                uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*)>(
                    *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x78))(
                    param_3, reinterpret_cast<char*>(scratch), nullptr);
            }
            else {
                uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*, uint32_t)>(
                    *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x80))(
                    param_3, reinterpret_cast<char*>(scratch), local_8, local_c);
            }
        }
        else if (local_14 == 1) {
            if (local_c == 0) {
                uint32_t local_24[4] = { 0, 0, 0, 0 };
                uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*)>(
                    *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x88))(
                    param_3, reinterpret_cast<char*>(scratch), local_24);
            }
            else {
                uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*, uint32_t)>(
                    *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x90))(
                    param_3, reinterpret_cast<char*>(scratch), local_8, local_c);
            }
        }
        else {
            if (local_14 != 2) {
                uVar10 = 0x80004005;
                goto cleanup;
            }
            if (local_c == 0) {
                uint32_t local_64[16] = { 0, 0, 0, 0, 0, 0, 0, 0,
                                          0, 0, 0, 0, 0, 0, 0, 0 };
                uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*)>(
                    *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0x98))(
                    param_3, reinterpret_cast<char*>(scratch), local_64);
            }
            else {
                uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*, uint32_t)>(
                    *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 0xa0))(
                    param_3, reinterpret_cast<char*>(scratch), local_8, local_c);
            }
        }
    }
    else if (local_10 == 4 && local_c == 0) {
        uVar10 = reinterpret_cast<uint32_t(__stdcall*)(void*, char*, void*)>(
            *reinterpret_cast<void**>(*reinterpret_cast<uint8_t**>(param_3) + 200))(
            param_3, reinterpret_cast<char*>(scratch), nullptr);
    }
    else {
        uVar10 = 0x80004005;
    }

cleanup:
    if (local_8 != nullptr) {
        operator_delete(local_8);
    }
done:
    if (scratch != nullptr) {
        operator_delete(scratch);
    }
    return uVar10;
}

// Inlined byte-compare used by the name lookup paths below (strcmp semantics,
// with the listing's rule that an empty stored name never matches).
static bool recon_str_equal(const uint8_t* a, const uint8_t* b)
{
    if (a == nullptr || b == nullptr || *a == 0) {
        return false;
    }
    while (*a != 0 && *a == *b) {
        ++a;
        ++b;
    }
    return *a == *b;
}

// 0x63f23c — observed shape
int FUN_0063f23c(uint32_t param_1, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t rec = ~param_1;

    if (*(int32_t*)(rec + 0x10) == 1 &&
        *(uint16_t*)(rec + 0x14) < *(uint32_t*)(base + 0xa0)) {
        int32_t entry = *(int32_t*)(base + 0xa4) + *(uint16_t*)(rec + 0x14) * 0xb4;
        if (*(uint16_t*)(rec + 0x18) < *(uint32_t*)(entry + 0x34)) {
            return *(uint16_t*)(rec + 0x18) * 0x38 + *(int32_t*)(entry + 0x38);
        }
    }
    return 0;
}

// 0x63f27d — observed shape
int FUN_0063f27d(uint8_t* param_1, int32_t param_reserved, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    (void)param_reserved;

    if (reinterpret_cast<uintptr_t>(param_1) <= 0xffff) {
        return 0;
    }
    if (reinterpret_cast<intptr_t>(param_1) < 1) {
        uint32_t rec = ~static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
        uint32_t idx;
        if (*(int32_t*)(rec + 0x10) != 0) {
            return 0;
        }
        idx = *(uint16_t*)(rec + 0x14);
        if (*(uint32_t*)(base + 0xa0) <= idx) {
            return 0;
        }
        return static_cast<int32_t>(idx * 0xb4 + *reinterpret_cast<int32_t*>(base + 0xa4));
    }
    {
        uint32_t found = 0;
        uint32_t count = *(uint32_t*)(base + 0xa0);
        if (count != 0) {
            int32_t* entry =
                reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(base + 0xa4) + 0x28);
            do {
                int32_t* hdr =
                    reinterpret_cast<int32_t*>(*(int32_t*)(base + 0x20) + *entry);
                if (recon_str_equal(reinterpret_cast<const uint8_t*>(hdr + 1), param_1)) {
                    break;
                }
                found++;
                entry += 0x2d;
            } while (found < count);
        }
        if (count == found) {
            return 0;
        }
        return static_cast<int32_t>(found * 0xb4 + *reinterpret_cast<int32_t*>(base + 0xa4));
    }
}

// 0x63f34c — observed shape
uint32_t FUN_0063f34c(int param_1, uint32_t param_2)
{
    if (param_2 < *(uint32_t*)(param_1 + 0xa0)) {
        return ~(param_2 * 0xb4 + *(int32_t*)(param_1 + 0xa4));
    }
    return 0;
}

// 0x63f375 — observed shape
uint32_t FUN_0063f375(int param_1, uint8_t* param_2)
{
    uint32_t local_8 = 0;
    uint32_t count = *(uint32_t*)(param_1 + 0xa0);

    if (count != 0) {
        int32_t* entry = reinterpret_cast<int32_t*>(*(int32_t*)(param_1 + 0xa4) + 0x28);
        do {
            int32_t* hdr =
                reinterpret_cast<int32_t*>(*entry + *(int32_t*)(param_1 + 0x20));
            if (recon_str_equal(reinterpret_cast<const uint8_t*>(hdr + 1), param_2)) {
                break;
            }
            local_8++;
            entry += 0x2d;
        } while (local_8 < count);
    }
    if (count == local_8) {
        return 0;
    }
    return ~(local_8 * 0xb4 + *(int32_t*)(param_1 + 0xa4));
}

// 0x63f418 — observed shape
uint32_t FUN_0063f418(uint32_t param_1, uint8_t* param_2, uint32_t param_3, void* self)
{
    int iVar1;
    (void)param_1;
    iVar1 = FUN_0063f27d(param_2, 1, self);
    if (iVar1 == 0 || *(uint32_t*)(iVar1 + 0x34) <= param_3) {
        return 0;
    }
    return ~(*(int32_t*)(iVar1 + 0x38) + param_3 * 0x38);
}

// 0x63f448 — observed shape
uint32_t FUN_0063f448(uint32_t param_1, uint32_t param_2, uint8_t* param_3, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t iVar2;
    (void)param_1;

    iVar2 = FUN_0063f27d(reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_2)), 1, self);
    if (iVar2 != 0) {
        uint32_t idx = 0;
        uint32_t count = *(uint32_t*)(iVar2 + 0x34);
        if (count != 0) {
            int32_t* entry = reinterpret_cast<int32_t*>(*(int32_t*)(iVar2 + 0x38) + 0x28);
            do {
                int32_t* hdr =
                    reinterpret_cast<int32_t*>(*(int32_t*)(base + 0x20) + *entry);
                if (recon_str_equal(reinterpret_cast<const uint8_t*>(hdr + 1), param_3)) {
                    break;
                }
                idx++;
                entry += 0xe;
            } while (idx < count);
        }
        if (*(uint32_t*)(iVar2 + 0x34) != idx) {
            return ~(idx * 0x38 + *(int32_t*)(iVar2 + 0x38));
        }
    }
    return 0;
}

// 0x63f4eb — observed shape
uint32_t FUN_0063f4eb(uint32_t param_1)
{
    struct ResultDesc {
        uint8_t pad[12];
        int32_t field; // local_20 in the listing
    };

    uint8_t* ctx = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_1));
    int32_t* piVar2;
    uint32_t iVar4 = param_1;
    ResultDesc desc = {};
    uint32_t local_8;
    uint32_t i;
    int32_t iVar5;
    int32_t iVar6;
    int32_t local_c;

    piVar2 = *reinterpret_cast<int32_t**>(ctx + 0x104);
    if (piVar2 != nullptr) {
        reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar2) + 8))(piVar2);
        *reinterpret_cast<int32_t*>(ctx + 0x104) = 0;
    }

    i = 0;
    if (*(int32_t*)(ctx + 0xa0) != 0) {
        local_8 = 0;
        while (true) {
            uint32_t uVar1 = local_8;
            uint32_t arrayBase = *(uint32_t*)(iVar4 + 0xa4);
            piVar2 = reinterpret_cast<int32_t*>(arrayBase + 0x88 + local_8);
            if (*piVar2 != 0) {
                int32_t* obj = reinterpret_cast<int32_t*>(*piVar2);
                reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                    *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj) + 8))(obj);
                *reinterpret_cast<uint32_t*>(*(int32_t*)(iVar4 + 0xa4) + 0x88 + uVar1) = 0;
            }
            iVar5 = static_cast<int32_t>(uVar1 + 0x8c);
            local_c = 2;
            do {
                piVar2 = reinterpret_cast<int32_t*>(iVar5 + 8 + *(int32_t*)(iVar4 + 0xa4));
                if (*piVar2 != 0) {
                    int32_t* obj = reinterpret_cast<int32_t*>(*piVar2);
                    reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj) + 8))(obj);
                    *reinterpret_cast<uint32_t*>(iVar5 + 8 + *(int32_t*)(iVar4 + 0xa4)) = 0;
                }
                piVar2 = reinterpret_cast<int32_t*>(*(int32_t*)(iVar4 + 0xa4) + iVar5);
                if (*piVar2 != 0) {
                    int32_t* obj = reinterpret_cast<int32_t*>(*piVar2);
                    reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj) + 8))(obj);
                    *reinterpret_cast<uint32_t*>(iVar5 + *(int32_t*)(iVar4 + 0xa4)) = 0;
                }
                iVar5 += 4;
                local_c--;
            } while (local_c != 0);
            i++;
            local_8 += 0xb4;
            if (*(uint32_t*)(iVar4 + 0xa0) <= i) {
                break;
            }
        }
    }

    i = 0;
    if (*(int32_t*)(ctx + 0x14) != 0) {
        iVar5 = 0;
        do {
            piVar2 = reinterpret_cast<int32_t*>(*(int32_t*)(ctx + 0x18) + iVar5);
            iVar6 = *piVar2;
            if ((((iVar6 == 5 || iVar6 == 6) || iVar6 == 7) || iVar6 == 8 || iVar6 == 9) &&
                piVar2[1] != 0) {
                int32_t* obj = reinterpret_cast<int32_t*>(piVar2[1]);
                reinterpret_cast<uint32_t(__stdcall*)(int32_t*, int32_t, void*)>(
                    *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj) + 0x44))(
                    obj, 0, &desc);
                if (desc.field == 0) {
                    piVar2 = reinterpret_cast<int32_t*>(*(int32_t*)(ctx + 0x18) + 4 + iVar5);
                    if (*piVar2 != 0) {
                        int32_t* obj2 = reinterpret_cast<int32_t*>(*piVar2);
                        reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj2) + 8))(obj2);
                        *reinterpret_cast<uint32_t*>(*(int32_t*)(ctx + 0x18) + 4 + iVar5) = 0;
                    }
                }
            }
            i++;
            iVar5 += 0x18;
        } while (i < *(uint32_t*)(ctx + 0x14));
    }

    i = 0;
    if (*(int32_t*)(ctx + 0xd0) != 0) {
        do {
            int32_t node = *(int32_t*)(*(int32_t*)(ctx + 0xd8) + i * 4);
            for (; node != 0; node = *(int32_t*)(node + 0x18)) {
                local_8 = 0;
                if (*(int32_t*)(node + 0x10) != 0) {
                    do {
                        uint32_t iVar3 = local_8 * 8;
                        piVar2 = reinterpret_cast<int32_t*>(*(int32_t*)(node + 0x14) + iVar3);
                        iVar6 = *piVar2;
                        if ((((iVar6 == 5 || iVar6 == 6) || iVar6 == 7) ||
                             iVar6 == 8 || iVar6 == 9) &&
                            piVar2[1] != 0) {
                            int32_t* obj =
                                *reinterpret_cast<int32_t**>(iVar3 + 4 + *(int32_t*)(node + 0x14));
                            reinterpret_cast<uint32_t(__stdcall*)(int32_t*, int32_t, void*)>(
                                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj) + 0x44))(
                                obj, 0, &desc);
                            if (desc.field == 0 &&
                                *reinterpret_cast<int32_t*>(iVar3 + 4 + *(int32_t*)(node + 0x14)) != 0) {
                                int32_t* obj2 =
                                    *reinterpret_cast<int32_t**>(iVar3 + 4 + *(int32_t*)(node + 0x14));
                                reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                                    *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj2) + 8))(obj2);
                                *reinterpret_cast<uint32_t*>(
                                    iVar3 + 4 + *(int32_t*)(node + 0x14)) = 0;
                            }
                        }
                        local_8++;
                    } while (local_8 < *(uint32_t*)(node + 0x10));
                }
            }
            i++;
        } while (i < *(uint32_t*)(ctx + 0xd0));
    }

    {
        int32_t node = *(int32_t*)(ctx + 0xf8);
        for (; node != 0; node = *(int32_t*)(node + 0x18)) {
            uint32_t idx = 0;
            if (*(int32_t*)(node + 0x10) != 0) {
                do {
                    uint32_t iVar6 = idx * 8;
                    piVar2 = reinterpret_cast<int32_t*>(*(int32_t*)(node + 0x14) + iVar6);
                    int32_t type = *piVar2;
                    if ((((type == 5 || type == 6) || type == 7) || type == 8 || type == 9) &&
                        piVar2[1] != 0) {
                        int32_t* obj =
                            *reinterpret_cast<int32_t**>(iVar6 + 4 + *(int32_t*)(node + 0x14));
                        reinterpret_cast<uint32_t(__stdcall*)(int32_t*, int32_t, void*)>(
                            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj) + 0x44))(
                            obj, 0, &desc);
                        if (desc.field == 0 &&
                            *reinterpret_cast<int32_t*>(iVar6 + 4 + *(int32_t*)(node + 0x14)) != 0) {
                            int32_t* obj2 =
                                *reinterpret_cast<int32_t**>(iVar6 + 4 + *(int32_t*)(node + 0x14));
                            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj2) + 8))(obj2);
                            *reinterpret_cast<uint32_t*>(
                                iVar6 + 4 + *(int32_t*)(node + 0x14)) = 0;
                        }
                    }
                    idx++;
                } while (idx < *(uint32_t*)(node + 0x10));
            }
        }
    }
    return 0;
}

// 0x63f756 — observed shape
uint32_t FUN_0063f756(int param_1, int32_t* param_2)
{
    uint32_t uVar2 = 0;
    if (param_2 == nullptr) {
        return 0x8876086c;
    }
    {
        int32_t* piVar1 = *reinterpret_cast<int32_t**>(param_1 + 0x38);
        *param_2 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1));
        if (piVar1 != nullptr) {
            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar1) + 4))(piVar1);
        }
    }
    return uVar2;
}

// 0x63f785 — observed shape
uint32_t FUN_0063f785(int param_1, int32_t* param_2)
{
    uint32_t uVar2 = 0;
    if (param_2 == nullptr) {
        return 0x8876086c;
    }
    {
        int32_t* piVar1 = *reinterpret_cast<int32_t**>(param_1 + 0xc);
        *param_2 = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar1));
        if (piVar1 != nullptr) {
            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar1) + 4))(piVar1);
        }
    }
    return uVar2;
}

// 0x63f7b4 — observed shape
uint32_t FUN_0063f7b4(int param_1, uint32_t* param_2)
{
    uint32_t uVar1 = 0;
    if (param_2 == nullptr) {
        return 0x8876086c;
    }
    param_2[0] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_s_D3DX_Effect_Compiler_0071ed7c));
    param_2[1] = *reinterpret_cast<uint32_t*>(param_1 + 0x98);
    param_2[2] = *reinterpret_cast<uint32_t*>(param_1 + 0xa0);
    param_2[3] = 0;
    return uVar1;
}

// 0x63f7fa — observed shape
uint32_t FUN_0063f7fa(int param_1, int param_2, uint32_t* param_3, void* self)
{
    uint8_t* ctx;
    int32_t iVar2;
    int32_t* piVar1;

    if (param_3 == nullptr) {
        return 0x8876086c;
    }
    if (param_2 == 0) {
        ctx = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)));
        iVar2 = *(uint16_t*)(ctx + 0x42) * 0xb4 + *(int32_t*)(ctx + 0xa4);
    }
    else {
        iVar2 = FUN_0063f27d(reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_2))), 1, self);
        ctx = reinterpret_cast<uint8_t*>(self);
        if (iVar2 == 0) {
            return 0x8876086c;
        }
    }
    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    piVar1 = reinterpret_cast<int32_t*>(*(int32_t*)(iVar2 + 0x28) + *(int32_t*)(ctx + 0x20));
    if (*piVar1 == 0) {
        piVar1 = nullptr;
    }
    else {
        piVar1 = piVar1 + 1;
    }
    param_3[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar1));
    param_3[1] = *reinterpret_cast<uint32_t*>(iVar2 + 0x34);
    param_3[2] = *reinterpret_cast<uint32_t*>(iVar2 + 0x2c);
    return 0;
}

// 0x63f86e — observed shape
uint32_t FUN_0063f86e(int32_t* param_1, int param_2, int32_t* param_3, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t iVar5;
    int32_t* piVar2;
    int32_t* piVar3;
    uint32_t uVar4;
    int32_t iVar1;

    if (param_3 == nullptr) {
        iVar5 = param_2;
    }
    else {
        iVar5 = *(int32_t*)(param_3[2] + param_2 * 4);
    }
    iVar5 = *(int32_t*)(base + 0x18) + iVar5 * 0x18;
    if (param_1 != *reinterpret_cast<int32_t**>(iVar5 + 4)) {
        if (param_1 != nullptr) {
            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(param_1) + 4))(param_1);
        }
        piVar2 = *reinterpret_cast<int32_t**>(iVar5 + 4);
        if (piVar2 != nullptr) {
            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar2) + 8))(piVar2);
            *reinterpret_cast<uint32_t*>(iVar5 + 4) = 0;
        }
        *reinterpret_cast<uint32_t*>(iVar5 + 0x14) |= 1;
        *reinterpret_cast<int32_t**>(iVar5 + 4) = param_1;
        *reinterpret_cast<uint32_t*>(base + 0x118) |= 0x40;
        if (param_3 != nullptr) {
            for (piVar2 = reinterpret_cast<int32_t*>(param_3[4]); piVar2 != param_3;
                 piVar2 = reinterpret_cast<int32_t*>(piVar2[4])) {
                if (*piVar2 != 0) {
                    iVar1 = *reinterpret_cast<int32_t*>(*piVar2 + 0x18) +
                            *(int32_t*)(piVar2[2] + param_2 * 4) * 0x18;
                    piVar3 = *reinterpret_cast<int32_t**>(iVar5 + 4);
                    if (piVar3 != nullptr) {
                        reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar3) + 4))(piVar3);
                    }
                    piVar3 = *reinterpret_cast<int32_t**>(iVar1 + 4);
                    if (piVar3 != nullptr) {
                        reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar3) + 8))(piVar3);
                        *reinterpret_cast<uint32_t*>(iVar1 + 4) = 0;
                    }
                    uVar4 = *reinterpret_cast<uint32_t*>(iVar5 + 4);
                    *reinterpret_cast<uint32_t*>(iVar1 + 0x14) |= 1;
                    *reinterpret_cast<uint32_t*>(iVar1 + 4) = uVar4;
                }
            }
        }
    }
    return 0;
}

// 0x63f926 — observed shape
uint32_t FUN_0063f926(int32_t* param_1, int param_2, int32_t* param_3, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t iVar3;
    int32_t* piVar4;
    int32_t iVar1;
    int32_t* piVar2;

    if (param_3 == nullptr) {
        iVar3 = param_2;
    }
    else {
        iVar3 = *(int32_t*)(param_3[2] + param_2 * 4);
    }
    iVar3 = *(int32_t*)(base + 0x18) + iVar3 * 0x18;
    if (param_1 != *reinterpret_cast<int32_t**>(iVar3 + 4)) {
        if (param_1 != nullptr) {
            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(param_1) + 4))(param_1);
        }
        piVar4 = *reinterpret_cast<int32_t**>(iVar3 + 4);
        if (piVar4 != nullptr) {
            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar4) + 8))(piVar4);
            *reinterpret_cast<uint32_t*>(iVar3 + 4) = 0;
        }
        *reinterpret_cast<int32_t**>(iVar3 + 4) = param_1;
        if (param_3 != nullptr) {
            for (piVar4 = reinterpret_cast<int32_t*>(param_3[4]); piVar4 != param_3;
                 piVar4 = reinterpret_cast<int32_t*>(piVar4[4])) {
                if (*piVar4 != 0) {
                    iVar1 = *reinterpret_cast<int32_t*>(*piVar4 + 0x18) +
                            *(int32_t*)(piVar4[2] + param_2 * 4) * 0x18;
                    piVar2 = *reinterpret_cast<int32_t**>(iVar3 + 4);
                    if (piVar2 != nullptr) {
                        reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar2) + 4))(piVar2);
                    }
                    piVar2 = *reinterpret_cast<int32_t**>(iVar1 + 4);
                    if (piVar2 != nullptr) {
                        reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar2) + 8))(piVar2);
                        *reinterpret_cast<uint32_t*>(iVar1 + 4) = 0;
                    }
                    *reinterpret_cast<uint32_t*>(iVar1 + 4) =
                        *reinterpret_cast<uint32_t*>(iVar3 + 4);
                }
            }
        }
    }
    return 0;
}

// 0x63f9ca — observed shape
int FUN_0063f9ca(char* param_1, int param_2, int32_t* param_3, void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t iVar1;
    int32_t* piVar3;
    int32_t* piVar4;
    int32_t iVar5;
    char* pcVar7;
    int local_c = 0;
    int32_t* local_8 = nullptr;

    if (param_3 == nullptr) {
        iVar5 = param_2;
    }
    else {
        iVar5 = *(int32_t*)(param_3[2] + param_2 * 4);
    }
    iVar5 = *(int32_t*)(base + 0x18) + iVar5 * 0x18;
    if (param_1 != nullptr) {
        uint32_t need = static_cast<uint32_t>(std::strlen(param_1)) + 1;
        piVar3 = *reinterpret_cast<int32_t**>(iVar5 + 4);
        if (piVar3 == nullptr ||
            reinterpret_cast<uintptr_t>(
                reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                    *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar3) + 0x10))(piVar3)) <
                need) {
            local_c = FUN_006294f9(need, &local_8);
            if (local_c < 0) {
                goto done;
            }
        }
        else {
            local_8 = *reinterpret_cast<int32_t**>(iVar5 + 4);
            if (local_8 != nullptr) {
                reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                    *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(local_8) + 4))(local_8);
            }
        }
        pcVar7 = reinterpret_cast<char*>(
            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(local_8) + 0xc))(local_8));
        std::memcpy(pcVar7, param_1, need);
        if (local_8 != nullptr) {
            reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(local_8) + 4))(local_8);
        }
    }
    piVar3 = *reinterpret_cast<int32_t**>(iVar5 + 4);
    if (piVar3 != nullptr) {
        reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar3) + 8))(piVar3);
        *reinterpret_cast<uint32_t*>(iVar5 + 4) = 0;
    }
    *reinterpret_cast<int32_t**>(iVar5 + 4) = local_8;
    if (param_3 != nullptr) {
        for (piVar3 = reinterpret_cast<int32_t*>(param_3[4]); piVar3 != param_3;
             piVar3 = reinterpret_cast<int32_t*>(piVar3[4])) {
            if (*piVar3 != 0) {
                iVar1 = *reinterpret_cast<int32_t*>(*piVar3 + 0x18) +
                        *(int32_t*)(piVar3[2] + param_2 * 4) * 0x18;
                piVar4 = *reinterpret_cast<int32_t**>(iVar5 + 4);
                if (piVar4 != nullptr) {
                    reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar4) + 4))(piVar4);
                }
                piVar4 = *reinterpret_cast<int32_t**>(iVar1 + 4);
                if (piVar4 != nullptr) {
                    reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
                        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(piVar4) + 8))(piVar4);
                    *reinterpret_cast<uint32_t*>(iVar1 + 4) = 0;
                }
                *reinterpret_cast<uint32_t*>(iVar1 + 4) =
                    *reinterpret_cast<uint32_t*>(iVar5 + 4);
            }
        }
    }
done:
    if (local_8 != nullptr) {
        reinterpret_cast<uint32_t(__stdcall*)(int32_t*)>(
            *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(local_8) + 8))(local_8);
    }
    return local_c;
}

// 0x63faf9 — observed shape
uint32_t FUN_0063faf9(int32_t* param_1, float* param_2, float* param_3, uint32_t param_4)
{
    int32_t iVar2 = *param_1;

    if (iVar2 == 1) {
        // ftoi: destination dwords are (source != 0.0)
        uint32_t n = param_4 << 4;
        uint32_t* dst = reinterpret_cast<uint32_t*>(param_2);
        for (uint32_t k = 0; k < n; ++k) {
            dst[k] = (*param_3 != 0.0f) ? 1u : 0u;
            param_3 = param_3 + 1;
        }
    }
    else if (iVar2 == 2) {
        // ftol then back to float (the FPU operand is the current source float)
        uint32_t n = param_4 << 4;
        for (uint32_t k = 0; k < n; ++k) {
            *param_2 = static_cast<float>(static_cast<int32_t>(*param_3));
            param_2 = param_2 + 1;
            param_3 = param_3 + 1;
        }
    }
    else {
        if (iVar2 != 3) {
            return 0x8876086c;
        }
        uint32_t n = (param_4 & 0x3ffffff) << 4;
        for (uint32_t k = 0; k < n; ++k) {
            param_2[k] = param_3[k];
        }
    }
    return 0;
}
