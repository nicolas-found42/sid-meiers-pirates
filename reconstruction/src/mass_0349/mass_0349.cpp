//
// mass_0349.cpp — reconstruction batch mass_0349
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants, call
// order, return shape, and conditional structure of the Ghidra 12.2
// pseudocode in analysis/pseudocode/functions/*.c.
//
// Register receivers (in_ECX) are modeled as an explicit `void* self`.
// The tag/count word lives at self+0x10, the flags word at self+0x14, the
// inline payload words at self+0x18..self+0x24, and the owned string
// pointer at self+0x18 (tag 2) or self+0xd8 (tag 0xb).
//
#include <cstdint>
#include <cstddef>

// ---------------------------------------------------------------------------
// External helpers referenced by the assigned corpus listings only.
// ---------------------------------------------------------------------------
void* FUN_00533c78(int size);
void  operator_delete(void* ptr);

// ---------------------------------------------------------------------------
// Offset accessors. Every observed field access goes through these so the
// original byte offsets stay visible in each definition.
// ---------------------------------------------------------------------------
static inline uint32_t& u32_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(base) + off);
}

static inline uint32_t& u32_at(std::uintptr_t base, std::size_t off)
{
    return *reinterpret_cast<uint32_t*>(base + off);
}

static inline uint8_t& u8_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(base) + off);
}

static inline char*& str_at(void* base, std::size_t off)
{
    return *reinterpret_cast<char**>(static_cast<uint8_t*>(base) + off);
}

// Length of a NUL-terminated string, mirroring the observed scan loop.
static std::size_t text_length(const char* text)
{
    const char* p = text;
    char c;
    do {
        c = *p++;
    } while (c != '\0');
    return static_cast<std::size_t>(p - (text + 1));
}

// ---------------------------------------------------------------------------
// 0x6b3c90 — reads the single-word payload when the tag is 4.
// ---------------------------------------------------------------------------
// 0x6b3c90 — observed shape
uint32_t FUN_006b3c90(void* self, uint32_t* param_1, uint32_t eax_in)
{
    if (u32_at(self, 0x10) == 4) {
        uint32_t value = u32_at(self, 0x18);
        *param_1 = value;
        return (value & 0xffffff00u) | 1u;
    }
    return eax_in & 0xffffff00u;
}

// 0x6b3cb0 — observed shape
uint32_t FUN_006b3cb0(void* self, uint32_t* param_1)
{
    if (u32_at(self, 0x10) == 5) {
        param_1[0] = u32_at(self, 0x18);
        param_1[1] = u32_at(self, 0x1c);
        return 1;
    }
    return 0;
}

// 0x6b3cd0 — observed shape
uint32_t FUN_006b3cd0(void* self, uint32_t* param_1)
{
    if (u32_at(self, 0x10) == 6) {
        param_1[0] = u32_at(self, 0x18);
        param_1[1] = u32_at(self, 0x1c);
        param_1[2] = u32_at(self, 0x20);
        return 1;
    }
    return 0;
}

// 0x6b3d00 — observed shape
uint32_t FUN_006b3d00(void* self, uint32_t* param_1, uint32_t eax_in)
{
    if (u32_at(self, 0x10) == 7) {
        uint32_t dest = *param_1;
        u32_at(dest, 0x0) = u32_at(self, 0x18);
        u32_at(dest, 0x4) = u32_at(self, 0x1c);
        u32_at(dest, 0x8) = u32_at(self, 0x20);
        u32_at(dest, 0xc) = u32_at(self, 0x24);
        return (dest & 0xffffff00u) | 1u;
    }
    return eax_in & 0xffffff00u;
}

// 0x6b3d40 — observed shape
uint32_t FUN_006b3d40(void* self, uint32_t* param_1)
{
    if (u32_at(self, 0x10) != 9) {
        return 0;
    }
    uint32_t* src = &u32_at(self, 0x18);
    uint32_t* dst = reinterpret_cast<uint32_t*>(*param_1);
    for (int i = 0x10; i != 0; --i) {
        *dst = *src;
        ++src;
        ++dst;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x6b3d70 — reads the four-word payload when the tag is 10.
// ---------------------------------------------------------------------------
// 0x6b3d70 — observed shape
uint32_t FUN_006b3d70(void* self, uint32_t* param_1)
{
    if (u32_at(self, 0x10) == 10) {
        param_1[0] = u32_at(self, 0x18);
        param_1[1] = u32_at(self, 0x1c);
        param_1[2] = u32_at(self, 0x20);
        param_1[3] = u32_at(self, 0x24);
        return 1;
    }
    return 0;
}

// 0x6b3db0 — observed shape
void FUN_006b3db0(void* self, uint8_t param_1)
{
    u32_at(self, 0x10) = 1;
    u8_at(self, 0x18) = param_1;
}

// 0x6b3dd0 — observed shape
void FUN_006b3dd0(void* self, char* param_1)
{
    u32_at(self, 0x10) = 2;
    if (param_1 != nullptr) {
        // Inline one-character compare of param_1 against the empty string.
        if (*param_1 != '\0') {
            char* existing = str_at(self, 0x18);
            if (existing != nullptr) {
                std::size_t existing_len = text_length(existing);
                std::size_t new_len = text_length(param_1);
                if (existing_len <= new_len) {
                    operator_delete(existing);
                    str_at(self, 0x18) = nullptr;
                }
            }
            if (str_at(self, 0x18) == nullptr) {
                std::size_t len = text_length(param_1);
                str_at(self, 0x18) =
                    static_cast<char*>(FUN_00533c78(static_cast<int>(len + 1)));
            }
            char* dst = str_at(self, 0x18);
            char c;
            do {
                c = *param_1++;
                *dst = c;
                ++dst;
            } while (c != '\0');
            return;
        }
    }
    operator_delete(str_at(self, 0x18));
    str_at(self, 0x18) = nullptr;
}

// 0x6b3e90 — observed shape
void FUN_006b3e90(void* self, uint32_t param_1)
{
    u32_at(self, 0x10) = 3;
    u32_at(self, 0x18) = param_1;
}

// 0x6b3eb0 — observed shape
void FUN_006b3eb0(void* self, uint32_t param_1)
{
    u32_at(self, 0x10) = 4;
    u32_at(self, 0x18) = param_1;
}

// ---------------------------------------------------------------------------
// 0x6b3ed0..0x6b3f90 — setters for tags 5, 6, 7, 9 and 10.
// ---------------------------------------------------------------------------
// 0x6b3ed0 — observed shape
void FUN_006b3ed0(void* self, const uint32_t* param_1)
{
    u32_at(self, 0x10) = 5;
    u32_at(self, 0x18) = param_1[0];
    u32_at(self, 0x1c) = param_1[1];
}

// 0x6b3ef0 — observed shape
void FUN_006b3ef0(void* self, const uint32_t* param_1)
{
    u32_at(self, 0x10) = 6;
    u32_at(self, 0x18) = param_1[0];
    u32_at(self, 0x1c) = param_1[1];
    u32_at(self, 0x20) = param_1[2];
}

// 0x6b3f10 — observed shape
void FUN_006b3f10(void* self, const uint32_t* param_1)
{
    u32_at(self, 0x10) = 7;
    u32_at(self, 0x18) = param_1[0];
    u32_at(self, 0x1c) = param_1[1];
    u32_at(self, 0x20) = param_1[2];
    u32_at(self, 0x24) = param_1[3];
}

// 0x6b3f40 — observed shape
void FUN_006b3f40(void* self, const uint32_t* param_1)
{
    u32_at(self, 0x10) = 9;
    uint32_t* dst = &u32_at(self, 0x18);
    for (int i = 0x10; i != 0; --i) {
        *dst = *param_1;
        ++param_1;
        ++dst;
    }
}

// 0x6b3f60 — observed shape
void FUN_006b3f60(void* self, const uint32_t* param_1)
{
    u32_at(self, 0x10) = 10;
    u32_at(self, 0x18) = param_1[0];
    u32_at(self, 0x1c) = param_1[1];
    u32_at(self, 0x20) = param_1[2];
    u32_at(self, 0x24) = 0x3f800000u;  // 1.0f
}

// ---------------------------------------------------------------------------
// 0x6b3f90 — tag 10 with the fourth payload word supplied by the caller.
// ---------------------------------------------------------------------------
// 0x6b3f90 — observed shape
void FUN_006b3f90(void* self, const uint32_t* param_1)
{
    u32_at(self, 0x10) = 10;
    u32_at(self, 0x18) = param_1[0];
    u32_at(self, 0x1c) = param_1[1];
    u32_at(self, 0x20) = param_1[2];
    u32_at(self, 0x24) = param_1[3];
}

// 0x6b3fc0 — observed shape
void FUN_006b3fc0(void* self, uint32_t param_1, char* param_2)
{
    u32_at(self, 0x10) = 0xb;
    if (param_2 != nullptr) {
        // Inline one-character compare of param_2 against the empty string.
        if (*param_2 != '\0') {
            char* existing = str_at(self, 0xd8);
            if (existing != nullptr) {
                std::size_t existing_len = text_length(existing);
                std::size_t new_len = text_length(param_2);
                if (existing_len <= new_len) {
                    operator_delete(existing);
                    str_at(self, 0xd8) = nullptr;
                }
            }
            if (str_at(self, 0xd8) == nullptr) {
                std::size_t len = text_length(param_2);
                str_at(self, 0xd8) =
                    static_cast<char*>(FUN_00533c78(static_cast<int>(len + 1)));
            }
            char* dst = str_at(self, 0xd8);
            char c;
            do {
                c = *param_2++;
                *dst = c;
                ++dst;
            } while (c != '\0');
            u32_at(self, 0x18) = param_1;
            return;
        }
    }
    operator_delete(str_at(self, 0xd8));
    str_at(self, 0xd8) = nullptr;
    u32_at(self, 0x18) = param_1;
}

// 0x6b40a0 — observed shape
void FUN_006b40a0(void* self, char param_1)
{
    if (param_1 == '\0') {
        u32_at(self, 0x14) = u32_at(self, 0x14) & 0xfffffffd;
        return;
    }
    u32_at(self, 0x14) = u32_at(self, 0x14) | 2;
}

// 0x6b40c0 — observed shape
void FUN_006b40c0(void* self, char param_1)
{
    if (param_1 == '\0') {
        u32_at(self, 0x14) = u32_at(self, 0x14) & 0xfffffffe;
        return;
    }
    u32_at(self, 0x14) = u32_at(self, 0x14) | 1;
}

// 0x6b40e0 — observed shape
uint32_t FUN_006b40e0(void* self, uint32_t param_1, uint32_t param_2)
{
    if ((u32_at(self, 0x10) == 3) || (u32_at(self, 0x10) == 2)) {
        u32_at(self, 0x58) = param_1;
        u32_at(self, 0x98) = param_2;
        return 1;
    }
    return 0;
}
