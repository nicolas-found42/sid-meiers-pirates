#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cfloat>
#include <new>
#include <windows.h>

extern uint32_t DAT_0072be24;
extern unsigned char DAT_006de3c8[];
extern void FUN_0060bb7c();
extern int32_t FUN_0060cdd8(unsigned char *param_1);
extern void FUN_0060d270(int32_t param_1);
extern int32_t FUN_00610755(uint32_t param_1, void *param_2);
extern int32_t FUN_0060c598();
extern int32_t FUN_0060c6d7();
extern int32_t FUN_0060cabf();
extern void FUN_0060f81e(void *self);
extern int32_t FUN_0060d19b(int32_t size);
extern int32_t FUN_0065ae50(void *param_1);
extern int32_t FUN_0065ac49(int32_t param_1, int32_t param_2, void *param_3);
extern void FUN_0060fcd3(void *param_1, void *param_2, int32_t param_3, const char *fmt, ...);
extern int32_t FUN_0060d1b4(uint32_t param_1, uint32_t param_2, void *param_3);
extern void *FUN_0065aaac(size_t size, size_t count);
extern void FUN_0060f79a();
extern uint32_t FUN_0060f7b4(void *self, char *param_1, int32_t param_2, uint32_t param_3, uint32_t param_4, int32_t param_5, int32_t param_6);
extern void FUN_006338c7();
extern void FUN_0065aa32(int32_t param_1, int32_t param_2);
extern void FUN_0060d291();
extern void FUN_005f8f77();
extern void FUN_0065aa8a();
extern void FUN_0060bf55(int32_t param_1);
extern void FUN_0060bf1a(int32_t param_1);
extern void FUN_0060bcd8(int32_t param_1);
extern int32_t FUN_0060d114(char *param_1, int32_t *param_2, uint32_t *param_3);
extern void FUN_0060f517(void *self);
extern int32_t FUN_0060bbcd(int32_t param_1, int32_t param_2, int32_t param_3);
extern int32_t FUN_00533c78(int32_t size);
extern int32_t FUN_0060bc4a();
extern int32_t FUN_0060bcf9(uint32_t param_1, uint32_t param_2, void *param_3, void *param_4, void *param_5, uint32_t param_6, int32_t param_7, int32_t param_8);
extern int32_t FUN_0060beaa(uint32_t param_1, uint32_t param_2, void *param_3, void *param_4);
extern int32_t FUN_0060e4ea(uint32_t param_1);
extern void FUN_0060fef7(int32_t param_1, void *param_2);
extern int32_t FUN_0060d3ea(int32_t param_1);
extern int32_t FUN_0060f155(void *param_1);
extern int32_t FUN_00629497(uint32_t param_1, uint32_t *param_2);
extern void FUN_0060f4f7(void *self);

// 0x60d2b8 — observed shape
void FUN_0060d2b8(void *self)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    DAT_0072be24 = *reinterpret_cast<uint32_t *>(base + 0x2a8);
    *reinterpret_cast<uint32_t *>(base + 0x2a4) = 0;
    FUN_0060bb7c();
}

// 0x60d2cf — observed shape
uint32_t FUN_0060d2cf(void *self, unsigned char *param_1)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    int32_t index = FUN_0060cdd8(param_1);
    int32_t **slot = reinterpret_cast<int32_t **>(base + 0x6c + index * 4);
    int32_t node = *slot;
    for (;;) {
        if (node == 0) {
            return 0;
        }
        unsigned char *name = *reinterpret_cast<unsigned char **>(node);
        int cmp = std::strcmp(reinterpret_cast<char *>(param_1), reinterpret_cast<char *>(name));
        if (cmp < 0) {
            return 0;
        }
        if (cmp == 0) {
            *slot = *reinterpret_cast<int32_t *>(node + 0xc);
            *reinterpret_cast<uint32_t *>(node + 0xc) = 0;
            FUN_0060d270(1);
            return 0;
        }
        slot = reinterpret_cast<int32_t **>(node + 12);
        node = *slot;
    }
}

// 0x60d343 — observed shape
int32_t FUN_0060d343(void *self)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    int32_t result = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), base + 0x278);
    if (result >= 0) {
        result = *reinterpret_cast<int32_t *>(base + 0x278);
        if (result == 9) {
            char *token = *reinterpret_cast<char **>(base + 0x280);
            if (std::strcmp(token, "pack_matrix") == 0) {
                return FUN_0060c598();
            }
            if (std::strcmp(token, "warning") == 0) {
                return FUN_0060c6d7();
            }
            if (std::strcmp(token, "def") == 0) {
                return FUN_0060cabf();
            }
        }
        if (result != 0xc && result != 0xd) {
            FUN_0060f81e(self);
        }
        result = 0;
    }
    *reinterpret_cast<uint32_t *>(base + 0x40) = 1;
    return result;
}

// 0x60d548 — observed shape
uint32_t FUN_0060d548(void *self, int32_t *param_1, int32_t param_2, int32_t param_3)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    int32_t local_20 = 0;
    int32_t local_10 = 0;
    intptr_t self_int = reinterpret_cast<intptr_t>(self);
    int32_t *local_18 = nullptr;
    int32_t *local_24 = nullptr;
    int32_t *local_14 = nullptr;
    int32_t *local_1c = nullptr;
    int32_t local_c = 0;
    unsigned char local_44[32];

    if (param_2 == 0) {
        int32_t *link = &local_10;
        if (param_3 != 0) {
            int32_t cur = param_3;
            do {
                int32_t alloc = FUN_0060d19b(0x30);
                int32_t node = 0;
                if (alloc != 0) {
                    node = FUN_0065ae50(reinterpret_cast<void *>(cur + 0x10));
                }
                *link = node;
                if (node == 0) {
                    return 0;
                }
                cur = *reinterpret_cast<int32_t *>(cur + 0xc);
                link = reinterpret_cast<int32_t *>(node + 0xc);
            } while (cur != 0);
            self_int = reinterpret_cast<intptr_t>(self);
        }
        *link = *reinterpret_cast<int32_t *>(base + 100);
        *reinterpret_cast<int32_t *>(base + 100) = local_10;
    } else {
        int32_t head = *reinterpret_cast<int32_t *>(base + 100);
        if (head == 0) {
            char **range = *reinterpret_cast<char ***>(base + 0x26c);
            char *p = range[0];
            char *end = range[1];
            if (p < end) {
                while (p < end) {
                    char c = *p;
                    if (c != ' ' && (c < '\t' || '\r' < c)) {
                        break;
                    }
                    ++p;
                }
                if (p < end && *p != '(') {
                    return 0;
                }
            }
            int32_t *tok = reinterpret_cast<int32_t *>(base + 0x278);
            local_14 = tok;
            int32_t rc = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), tok);
            if (rc < 0) {
                return 0;
            }
            if (*reinterpret_cast<int32_t *>(base + 0x278) != 1) {
                return 0;
            }
            local_1c = reinterpret_cast<int32_t *>(base + 0x280);
            if (std::strcmp(reinterpret_cast<char *>(local_1c), "(") != 0) {
                return 0;
            }
        } else {
            local_14 = reinterpret_cast<int32_t *>(base + 0x278);
            int32_t *src = reinterpret_cast<int32_t *>(head + 0x10);
            int32_t *dst = local_14;
            for (int i = 8; i != 0; --i) {
                *dst = *src;
                ++src;
                ++dst;
            }
            if (*local_14 != 1) {
                return 0;
            }
            local_1c = reinterpret_cast<int32_t *>(base + 0x280);
            if (std::strcmp(reinterpret_cast<char *>(local_1c), "(") != 0) {
                return 0;
            }
            *reinterpret_cast<uint32_t *>(base + 100) = *reinterpret_cast<uint32_t *>(head + 0xc);
            *reinterpret_cast<uint32_t *>(head + 0xc) = 0;
        }
        local_18 = nullptr;
        local_24 = &local_20;
        local_c = 1;
        intptr_t cur_self = self_int;
        for (;;) {
            int32_t *tok = local_14;
            int32_t pending = *reinterpret_cast<int32_t *>(reinterpret_cast<unsigned char *>(cur_self) + 100);
            if (pending == 0) {
                int32_t rc = FUN_00610755(*reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(cur_self) + 0x298), local_14);
                if (rc < 0) {
                    return 0;
                }
                cur_self = self_int;
            } else {
                int32_t *src = reinterpret_cast<int32_t *>(pending + 0x10);
                int32_t *dst = local_14;
                for (int i = 8; i != 0; --i) {
                    *dst = *src;
                    ++src;
                    ++dst;
                }
                *reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(cur_self) + 100) = *reinterpret_cast<uint32_t *>(pending + 0xc);
                *reinterpret_cast<uint32_t *>(pending + 0xc) = 0;
            }
            int32_t *link = local_24;
            if (*tok == 0xd) {
                FUN_0060fcd3(reinterpret_cast<unsigned char *>(cur_self) + 0x18, param_1, 0x5eb, "unexpected end of file in macro expansion");
                return 0;
            }
            if (*local_24 == 0) {
                int32_t alloc = FUN_0060d19b(0x14);
                int32_t node = 0;
                if (alloc != 0) {
                    node = FUN_0065ac49(0, 0, DAT_006de3c8);
                }
                *link = node;
                if (node == 0) {
                    return 0;
                }
                local_18 = reinterpret_cast<int32_t *>(node + 8);
                cur_self = self_int;
            }
            if ((local_c == 1 && *tok == 1 && (reinterpret_cast<char *>(local_1c)[0] == ',' || reinterpret_cast<char *>(local_1c)[0] == ')')) && reinterpret_cast<unsigned char *>(cur_self)[0x281] == '\0') {
                local_24 = reinterpret_cast<int32_t *>(*link + 0xc);
            } else {
                int32_t alloc = FUN_0060d19b(0x30);
                int32_t node = 0;
                if (alloc != 0) {
                    node = FUN_0065ae50(tok);
                }
                *local_18 = node;
                if (node == 0) {
                    return 0;
                }
                local_18 = reinterpret_cast<int32_t *>(node + 0xc);
                cur_self = self_int;
            }
            if (*tok == 1 && reinterpret_cast<unsigned char *>(cur_self)[0x281] == '\0') {
                char c = reinterpret_cast<char *>(local_1c)[0];
                if (c == '(' || c == '[' || c == '{') {
                    ++local_c;
                } else if (c == ')' || c == ']' || c == '}') {
                    --local_c;
                }
            }
            if (local_c == 0) {
                break;
            }
        }
        int32_t formals = local_20;
        int32_t actuals = param_2;
        while (formals != 0 && *reinterpret_cast<int32_t *>(formals + 8) != 0) {
            actuals = *reinterpret_cast<int32_t *>(actuals + 0xc);
            formals = *reinterpret_cast<int32_t *>(formals + 0xc);
            if (actuals == 0) {
                break;
            }
        }
        if (actuals != 0 || formals != 0) {
            FUN_0060fcd3(base + 0x18, param_1, 0x5ec, "not enough actual parameters for macro '%s'", *reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(param_1) + 8));
            return 0;
        }
        int32_t *tail = reinterpret_cast<int32_t *>(&local_10);
        local_c = 0;
        local_14 = nullptr;
        local_1c = nullptr;
        local_24 = reinterpret_cast<int32_t *>(param_3);
        while (local_24 != nullptr) {
            int32_t *tok = reinterpret_cast<int32_t *>(reinterpret_cast<intptr_t>(local_24) + 0x10);
            char *marker = reinterpret_cast<char *>(reinterpret_cast<intptr_t>(local_24) + 0x18);
            int32_t *sub = tail;
            bool skip_body = false;

            if (local_c == 0 && local_14 == nullptr && *tok == 1) {
                if (std::strcmp(marker, "#") == 0) {
                    local_c = 1;
                    local_1c = tok;
                    skip_body = true;
                } else if (std::strcmp(marker, "#@") == 0) {
                    local_14 = reinterpret_cast<int32_t *>(1);
                    local_1c = tok;
                    skip_body = true;
                }
            }

            if (!skip_body) {
                if (*tok == 9) {
                    int32_t formal = local_20;
                    int32_t actual = param_2;
                    while (actual != 0) {
                        int cmp = std::strcmp(*reinterpret_cast<char **>(actual + 0x18), marker);
                        if (cmp == 0) {
                            break;
                        }
                        actual = *reinterpret_cast<int32_t *>(actual + 0xc);
                        formal = *reinterpret_cast<int32_t *>(formal + 0xc);
                    }
                    if (actual == 0) {
                        int32_t alloc = FUN_0060d19b(0x30);
                        int32_t node = 0;
                        if (alloc != 0) {
                            node = FUN_0065ae50(tok);
                        }
                        *tail = node;
                        if (node == 0) {
                            return 0;
                        }
                        tail = reinterpret_cast<int32_t *>(node + 0xc);
                    } else {
                        for (int32_t n = *reinterpret_cast<int32_t *>(formal + 8); n != 0; n = *reinterpret_cast<int32_t *>(n + 0xc)) {
                            int32_t alloc = FUN_0060d19b(0x30);
                            int32_t node = 0;
                            if (alloc != 0) {
                                node = FUN_0065ae50(reinterpret_cast<void *>(n + 0x10));
                            }
                            *tail = node;
                            if (node == 0) {
                                return 0;
                            }
                            tail = reinterpret_cast<int32_t *>(node + 0xc);
                        }
                    }
                } else {
                    int32_t alloc = FUN_0060d19b(0x30);
                    int32_t node = 0;
                    if (alloc != 0) {
                        node = FUN_0065ae50(tok);
                    }
                    *tail = node;
                    if (node == 0) {
                        return 0;
                    }
                    tail = reinterpret_cast<int32_t *>(node + 0xc);
                }

                if (local_c != 0 || local_14 != nullptr) {
                    int32_t count = 1;
                    int32_t prev = 0;
                    for (int32_t n = *sub; n != 0; n = *reinterpret_cast<int32_t *>(n + 0xc)) {
                        if (prev != 0 && prev != *reinterpret_cast<int32_t *>(n + 0x28)) {
                            ++count;
                        }
                        int32_t len = FUN_0060d1b4(*reinterpret_cast<uint32_t *>(n + 0x28), *reinterpret_cast<uint32_t *>(n + 0x2c), nullptr);
                        count += len;
                        prev = *reinterpret_cast<int32_t *>(n + 0x28) + *reinterpret_cast<int32_t *>(n + 0x2c);
                    }
                    char *text = reinterpret_cast<char *>(FUN_0065aaac(count + 1, 1));
                    if (text == nullptr) {
                        return 0;
                    }
                    int32_t written = 1;
                    char delim = static_cast<char>(((local_c == 0) - 1U & 0xfb) + 0x27);
                    text[0] = delim;
                    int32_t prev2 = 0;
                    for (int32_t n = *sub; n != 0; n = *reinterpret_cast<int32_t *>(n + 0xc)) {
                        int32_t at = written;
                        if (prev2 != 0 && prev2 != *reinterpret_cast<int32_t *>(n + 0x28)) {
                            at = written + 1;
                            text[written] = ' ';
                        }
                        int32_t adv = FUN_0060d1b4(*reinterpret_cast<uint32_t *>(n + 0x28), *reinterpret_cast<uint32_t *>(n + 0x2c), text + at);
                        written = at + adv;
                        prev2 = *reinterpret_cast<int32_t *>(n + 0x2c) + *reinterpret_cast<int32_t *>(n + 0x28);
                    }
                    text[written] = delim;
                    FUN_0060f79a();
                    int32_t rc = static_cast<int32_t>(FUN_0060f7b4(reinterpret_cast<void *>(self_int), text, written + 1, static_cast<uint32_t>(local_1c[4]), static_cast<uint32_t>(local_1c[5]), static_cast<int32_t>(self_int), static_cast<int32_t>(self_int + 0x18)));
                    if (rc < 0) {
                        FUN_006338c7();
                        return 0;
                    }
                    rc = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), local_44);
                    if (rc < 0) {
                        FUN_006338c7();
                        return 0;
                    }
                    {
                        int32_t alloc = FUN_0060d19b(0x30);
                        int32_t node = 0;
                        if (alloc != 0) {
                            node = FUN_0065ae50(local_44);
                        }
                        *sub = node;
                        if (node == 0) {
                            FUN_006338c7();
                            return 0;
                        }
                        local_14 = nullptr;
                        local_c = 0;
                        tail = reinterpret_cast<int32_t *>(node + 0xc);
                        FUN_006338c7();
                    }
                }
            }
            local_24 = *reinterpret_cast<int32_t **>(reinterpret_cast<intptr_t>(local_24) + 0xc);
        }

        tail = reinterpret_cast<int32_t *>(&local_10);
        while (*tail != 0) {
            int32_t entry = *tail;
            int32_t second = *reinterpret_cast<int32_t *>(entry + 0xc);
            int32_t third = 0;
            if (second != 0) {
                third = *reinterpret_cast<int32_t *>(second + 0xc);
            }
            int32_t *second_tok = reinterpret_cast<int32_t *>(static_cast<uint32_t>(-static_cast<int32_t>(second != 0)) & static_cast<uint32_t>(second + 0x10));
            uint32_t third_tok = static_cast<uint32_t>(-static_cast<int32_t>(third != 0)) & static_cast<uint32_t>(third + 0x10);
            if (second != 0 && third != 0 && *second_tok == 1 && std::strcmp(reinterpret_cast<char *>(second_tok + 2), "##") == 0) {
                int32_t total = *reinterpret_cast<int32_t *>(entry + 0x2c) + *reinterpret_cast<int32_t *>(third_tok + 0x1c);
                uint32_t *joined = reinterpret_cast<uint32_t *>(FUN_0065aaac(static_cast<size_t>(total), 1));
                if (joined == nullptr) {
                    return 0;
                }
                uint32_t *dst = joined;
                uint32_t *src = *reinterpret_cast<uint32_t **>(entry + 0x28);
                uint32_t len = *reinterpret_cast<uint32_t *>(entry + 0x2c);
                for (uint32_t n = len >> 2; n != 0; --n) {
                    *dst = *src;
                    ++src;
                    ++dst;
                }
                for (uint32_t n = len & 3; n != 0; --n) {
                    *reinterpret_cast<unsigned char *>(dst) = *reinterpret_cast<unsigned char *>(src);
                    src = reinterpret_cast<uint32_t *>(reinterpret_cast<int32_t>(src) + 1);
                    dst = reinterpret_cast<uint32_t *>(reinterpret_cast<int32_t>(dst) + 1);
                }
                uint32_t len2 = *reinterpret_cast<uint32_t *>(third_tok + 0x1c);
                src = *reinterpret_cast<uint32_t **>(third_tok + 0x18);
                dst = reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(entry + 0x2c) + reinterpret_cast<int32_t>(joined));
                for (uint32_t n = len2 >> 2; n != 0; --n) {
                    *dst = *src;
                    ++src;
                    ++dst;
                }
                for (uint32_t n = len2 & 3; n != 0; --n) {
                    *reinterpret_cast<unsigned char *>(dst) = *reinterpret_cast<unsigned char *>(src);
                    src = reinterpret_cast<uint32_t *>(reinterpret_cast<int32_t>(src) + 1);
                    dst = reinterpret_cast<uint32_t *>(reinterpret_cast<int32_t>(dst) + 1);
                }
                FUN_0060f79a();
                int32_t rc = static_cast<int32_t>(FUN_0060f7b4(reinterpret_cast<void *>(self_int), reinterpret_cast<char *>(joined), total, *reinterpret_cast<uint32_t *>(entry + 0x20), *reinterpret_cast<uint32_t *>(entry + 0x24), static_cast<int32_t>(self_int), static_cast<int32_t>(self_int + 0x18)));
                if (rc < 0) {
                    FUN_006338c7();
                    return 0;
                }
                rc = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), reinterpret_cast<void *>(entry + 0x10));
                if (rc < 0) {
                    FUN_006338c7();
                    return 0;
                }
                *reinterpret_cast<uint32_t *>(entry + 0xc) = *reinterpret_cast<uint32_t *>(third + 0xc);
                *reinterpret_cast<uint32_t *>(third + 0xc) = 0;
                FUN_006338c7();
            }
            tail = reinterpret_cast<int32_t *>(*tail + 0xc);
        }
        *tail = *reinterpret_cast<int32_t *>(base + 100);
        *reinterpret_cast<int32_t *>(base + 100) = local_10;
    }
    return 1;
}

// 0x60dc0d — observed shape
void FUN_0060dc0d(void *self)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    FUN_0065aa32(0x100000, 0x10000);
    FUN_0060f4f7(self);
    *reinterpret_cast<uint32_t *>(base + 0x2a4) = 0;
    FUN_0060d291();
    *reinterpret_cast<uint32_t *>(base + 0x38) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x3c) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x40) = 1;
    *reinterpret_cast<uint32_t *>(base + 0x44) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x48) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x4c) = 1;
    *reinterpret_cast<uint32_t *>(base + 0x50) = 1;
    *reinterpret_cast<uint32_t *>(base + 0x54) = 1;
    *reinterpret_cast<uint32_t *>(base + 0x58) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x5c) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x60) = 0;
    *reinterpret_cast<uint32_t *>(base + 100) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x68) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x268) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x26c) = 0;
    uint32_t *slots = reinterpret_cast<uint32_t *>(base + 0x6c);
    for (int i = 0x7f; i != 0; --i) {
        *slots = 0;
        ++slots;
    }
    uint32_t *tok = reinterpret_cast<uint32_t *>(base + 0x278);
    for (int i = 8; i != 0; --i) {
        *tok = 0;
        ++tok;
    }
    *reinterpret_cast<uint32_t *>(base + 0x298) = 1;
    char *locale = setlocale(4, nullptr);
    locale = _strdup(locale);
    *reinterpret_cast<char **>(base + 0x29c) = locale;
    if (locale != nullptr && std::strcmp(locale, "C") != 0) {
        setlocale(4, "C");
    }
    uint32_t fp = _controlfp(0, 0);
    *reinterpret_cast<uint32_t *>(base + 0x2a0) = fp;
    _controlfp(0xffffffff, 0x8001f);
    _controlfp(0, 0x30000);
    FUN_005f8f77();
}

// 0x60dcfa — observed shape
void FUN_0060dcfa(void *self)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    if (*reinterpret_cast<int32_t *>(base + 0x3c) != 0) {
        FUN_0060bf55(1);
    }
    if (*reinterpret_cast<int32_t *>(base + 0x68) != 0) {
        FUN_0060bf1a(1);
    }
    if (*reinterpret_cast<int32_t *>(base + 0x268) != 0) {
        FUN_0060bcd8(1);
    }
    int32_t *slot = reinterpret_cast<int32_t *>(base + 0x6c);
    for (int i = 0x7f; i != 0; --i) {
        if (*slot != 0) {
            FUN_0060d270(1);
        }
        ++slot;
    }
    char *locale = *reinterpret_cast<char **>(base + 0x29c);
    if (locale != nullptr && std::strcmp(locale, "C") != 0) {
        setlocale(4, locale);
    }
    if (*reinterpret_cast<void **>(base + 0x29c) != nullptr) {
        free(*reinterpret_cast<void **>(base + 0x29c));
    }
    _controlfp(*reinterpret_cast<uint32_t *>(base + 0x2a0), 0xb001f);
    if (*reinterpret_cast<int32_t *>(base + 0x2a4) != 0) {
        FUN_0060d2b8(self);
    }
    FUN_0060f517(self);
    FUN_0065aa8a();
}

// 0x60ddb0 — observed shape
int32_t FUN_0060ddb0(void *self)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    uint32_t local_2c[8];
    int32_t local_c = 0;
    uint32_t local_8 = 0;
    char *tok_text = reinterpret_cast<char *>(base + 0x280);
    int32_t *tok = reinterpret_cast<int32_t *>(base + 0x278);

    if (*reinterpret_cast<int32_t *>(base + 0x40) != 0 || *reinterpret_cast<int32_t *>(base + 0x48) != 0) {
        *reinterpret_cast<uint32_t *>(base + 0x278) = 0xc;
        return -1;
    }
    int32_t pending = *reinterpret_cast<int32_t *>(base + 100);
    if (pending == 0) {
        int32_t rc = FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298) | 4, tok);
        if (rc < 0) {
            return -1;
        }
    } else {
        uint32_t *src = reinterpret_cast<uint32_t *>(pending + 0x10);
        uint32_t *dst = tok;
        for (int i = 8; i != 0; --i) {
            *dst = *src;
            ++src;
            ++dst;
        }
        *reinterpret_cast<uint32_t *>(base + 100) = *reinterpret_cast<uint32_t *>(pending + 0xc);
        *reinterpret_cast<uint32_t *>(pending + 0xc) = 0;
    }
    int32_t kind = *tok;
    if (kind == 1) {
        char c1 = reinterpret_cast<char *>(base + 0x281)[0];
        if (c1 == '\0') {
            return static_cast<int32_t>(tok_text[0]);
        }
        if (reinterpret_cast<char *>(base + 0x282)[0] == '\0') {
            if (c1 == '=') {
                char c0 = tok_text[0];
                if (c0 == '!') {
                    return 0x113;
                }
                if (c0 == '<') {
                    return 0x110;
                }
                if (c0 == '=') {
                    return 0x112;
                }
                if (c0 == '>') {
                    return 0x111;
                }
            } else {
                char c0 = tok_text[0];
                if (c0 == c1) {
                    if (c0 == '&') {
                        return 0x114;
                    }
                    if (c0 == '|') {
                        return 0x115;
                    }
                }
            }
        }
        return 0x119;
    }
    if (kind < 2) {
        return 0x119;
    }
    if (kind < 5) {
        return 0x117;
    }
    if (kind != 9) {
        if (kind == 10) {
            return 0x118;
        }
        if (kind == 0xc || kind == 0xd) {
            *reinterpret_cast<uint32_t *>(base + 0x40) = 1;
            return -1;
        }
        return 0x119;
    }
    if (*reinterpret_cast<int32_t *>(base + 0x4c) == 0) {
        if (std::strcmp(tok_text, "defined") == 0) {
            *reinterpret_cast<uint32_t *>(base + 0x58) = 0;
            return 0x10f;
        }
        if (*reinterpret_cast<int32_t *>(base + 0x58) == 0) {
            return 0x116;
        }
        if (FUN_0060d114(tok_text, &local_c, &local_8) == 0) {
            return 0x116;
        }
        int32_t state = *reinterpret_cast<int32_t *>(base + 0x44);
        uint32_t *src = tok;
        uint32_t *dst = local_2c;
        for (int i = 8; i != 0; --i) {
            *dst = *src;
            ++src;
            ++dst;
        }
        if (state == 0 && FUN_0060d548(self, local_2c, local_c, static_cast<int32_t>(local_8)) != 0) {
            state = 0;
        } else {
            state = 1;
        }
        *reinterpret_cast<int32_t *>(base + 0x44) = state;
        if (state == 0 && (local_c = FUN_0060ddb0(self), local_c != -1)) {
            state = 0;
        } else {
            state = 1;
        }
        *reinterpret_cast<int32_t *>(base + 0x44) = state;
        if (state == 0) {
            return local_c;
        }
        *reinterpret_cast<uint32_t *>(base + 0x48) = 1;
        src = local_2c;
        dst = tok;
        for (int i = 8; i != 0; --i) {
            *dst = *src;
            ++src;
            ++dst;
        }
        FUN_0060fcd3(base + 0x18, tok, 0x5ee, "invalid or unsupported integer constant expression");
        return 0x116;
    }
    *reinterpret_cast<uint32_t *>(base + 0x4c) = 0;
    *reinterpret_cast<uint32_t *>(base + 0x58) = 0;
    if (*reinterpret_cast<int32_t *>(base + 0x50) == 0) {
        if (tok_text[0] != 'e') {
            if (tok_text[0] == 'i') {
                if (std::strcmp(tok_text, "if") == 0) {
                    return 0x10c;
                }
                if (std::strcmp(tok_text, "ifdef") == 0) {
                    return 0x10c;
                }
                if (std::strcmp(tok_text, "ifndef") == 0) {
                    return 0x10c;
                }
            }
            *reinterpret_cast<uint32_t *>(base + 0x4c) = 1;
            return 0x116;
        }
        if (std::strcmp(tok_text, "else") == 0) {
            return 0x10a;
        }
        if (std::strcmp(tok_text, "endif") == 0) {
            return 0x10b;
        }
        if (std::strcmp(tok_text, "elif") != 0) {
            *reinterpret_cast<uint32_t *>(base + 0x4c) = 1;
            return 0x116;
        }
        int32_t *cond = *reinterpret_cast<int32_t **>(*reinterpret_cast<int32_t *>(base + 0x268) + 0x38);
        if (cond != nullptr) {
            if (cond[1] == 0 || *cond != 0) {
                return 0x10d;
            }
            *reinterpret_cast<int32_t *>(base + 0x50) = cond[1];
            *reinterpret_cast<uint32_t *>(base + 0x58) = 1;
            return 0x109;
        }
        *reinterpret_cast<uint32_t *>(base + 0x50) = 1;
    } else {
        char c0 = tok_text[0];
        if (c0 == 'd') {
            if (std::strcmp(tok_text, "define") == 0) {
                return 0x101;
            }
            *reinterpret_cast<uint32_t *>(base + 0x4c) = 1;
            return 0x116;
        }
        if (c0 != 'e') {
            if (c0 != 'i') {
                if (c0 == 'l') {
                    if (std::strcmp(tok_text, "line") == 0) {
                        return 0x103;
                    }
                } else if (c0 == 'p') {
                    if (std::strcmp(tok_text, "pragma") == 0) {
                        return 0x10e;
                    }
                } else if (c0 == 'u') {
                    if (std::strcmp(tok_text, "undef") == 0) {
                        return 0x102;
                    }
                }
            } else {
                if (std::strcmp(tok_text, "if") == 0) {
                    *reinterpret_cast<uint32_t *>(base + 0x58) = 1;
                    return 0x106;
                }
                if (std::strcmp(tok_text, "ifdef") == 0) {
                    return 0x107;
                }
                if (std::strcmp(tok_text, "ifndef") == 0) {
                    return 0x108;
                }
                if (std::strcmp(tok_text, "include") == 0) {
                    return 0x104;
                }
            }
            *reinterpret_cast<uint32_t *>(base + 0x4c) = 1;
            return 0x116;
        }
        if (std::strcmp(tok_text, "elif") == 0) {
            *reinterpret_cast<uint32_t *>(base + 0x58) = 1;
            return 0x109;
        }
        if (std::strcmp(tok_text, "else") == 0) {
            return 0x10a;
        }
        if (std::strcmp(tok_text, "endif") == 0) {
            return 0x10b;
        }
        if (std::strcmp(tok_text, "error") == 0) {
            return 0x105;
        }
        *reinterpret_cast<uint32_t *>(base + 0x4c) = 1;
        return 0x116;
    }
    *reinterpret_cast<uint32_t *>(base + 0x58) = 1;
    return 0x109;
}

// 0x60e245 — observed shape
int32_t FUN_0060e245(void *self, int32_t param_1, int32_t *param_2)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    int32_t iVar2 = FUN_00533c78(0x14);
    if (iVar2 == 0) {
        param_1 = 0;
    } else {
        param_1 = FUN_0060bbcd(param_1, 0, 0);
    }
    if (param_1 != 0) {
        if (param_2 != nullptr) {
            char *p = *reinterpret_cast<char **>(*reinterpret_cast<int32_t *>(base + 0x26c));
            char *end = reinterpret_cast<char *>(*reinterpret_cast<int32_t *>(*reinterpret_cast<int32_t *>(base + 0x26c) + 4));
            if (p < end && *p == '(') {
                param_2 = reinterpret_cast<int32_t *>(param_1 + 4);
                if (FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), base + 0x278) < 0) {
                    goto cleanup;
                }
                for (;;) {
                    if (FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), base + 0x278) < 0) {
                        goto cleanup;
                    }
                    if (*reinterpret_cast<int32_t *>(base + 0x278) != 9) {
                        goto bad_token;
                    }
                    for (int32_t n = *reinterpret_cast<int32_t *>(param_1 + 4); n != 0; n = *reinterpret_cast<int32_t *>(n + 0xc)) {
                        if (std::strcmp(reinterpret_cast<char *>(base + 0x280), *reinterpret_cast<char **>(n + 0x18)) == 0) {
                            FUN_0060fcd3(base + 0x18, base + 0x278, 0x5e7, "duplicate macro parameter '%s'", *reinterpret_cast<uint32_t *>(base + 0x280));
                            break;
                        }
                    }
                    {
                        int32_t alloc = FUN_0060d19b(0x30);
                        int32_t node = 0;
                        if (alloc != 0) {
                            node = FUN_0065ae50(base + 0x278);
                        }
                        *param_2 = node;
                        if (node == 0) {
                            goto oom;
                        }
                        param_2 = reinterpret_cast<int32_t *>(node + 0xc);
                    }
                    if (FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), base + 0x278) < 0) {
                        goto cleanup;
                    }
                    if (*reinterpret_cast<int32_t *>(base + 0x278) != 1) {
                        goto bad_token;
                    }
                    if (std::strcmp(reinterpret_cast<char *>(base + 0x280), ",") != 0) {
                        break;
                    }
                }
                if (std::strcmp(reinterpret_cast<char *>(base + 0x280), ")") != 0) {
                bad_token:
                    {
                        int32_t k = *reinterpret_cast<int32_t *>(base + 0x278);
                        if (k == 0xc || k == 0xd) {
                            *reinterpret_cast<uint32_t *>(base + 0x40) = 1;
                        }
                        FUN_0060fef7(0x5dc, base + 0x278);
                        *reinterpret_cast<uint32_t *>(base + 0x44) = 1;
                        iVar2 = -0x7fffbffb;
                        goto cleanup;
                    }
                }
            }
        }
        int32_t *link = reinterpret_cast<int32_t *>(param_1 + 8);
        for (;;) {
            int32_t pending = *reinterpret_cast<int32_t *>(base + 100);
            if (pending == 0) {
                if (FUN_00610755(*reinterpret_cast<uint32_t *>(base + 0x298), base + 0x278) < 0) {
                    goto cleanup;
                }
            } else {
                uint32_t *src = reinterpret_cast<uint32_t *>(pending + 0x10);
                uint32_t *dst = reinterpret_cast<uint32_t *>(base + 0x278);
                for (int i = 8; i != 0; --i) {
                    *dst = *src;
                    ++src;
                    ++dst;
                }
                *reinterpret_cast<uint32_t *>(base + 100) = *reinterpret_cast<uint32_t *>(pending + 0xc);
                *reinterpret_cast<uint32_t *>(pending + 0xc) = 0;
                *reinterpret_cast<uint32_t *>(base + 0x288) = *reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(base + 0x26c) + 0x18);
                *reinterpret_cast<uint32_t *>(base + 0x28c) = *reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(base + 0x26c) + 0x1c);
            }
            int32_t k = *reinterpret_cast<int32_t *>(base + 0x278);
            if (k == 0xc || k == 0xd) {
                *reinterpret_cast<uint32_t *>(base + 0x40) = 1;
                iVar2 = FUN_0060d3ea(param_1);
                if (iVar2 >= 0) {
                    param_1 = 0;
                    iVar2 = 0;
                }
                goto cleanup;
            }
            {
                int32_t alloc = FUN_0060d19b(0x30);
                int32_t node = 0;
                if (alloc != 0) {
                    node = FUN_0065ae50(base + 0x278);
                }
                *link = node;
                if (node == 0) {
                    break;
                }
                link = reinterpret_cast<int32_t *>(node + 0xc);
            }
        }
    }
oom:
    iVar2 = -0x7ff8fff2;
cleanup:
    if (param_1 != 0) {
        FUN_0060d270(1);
    }
    return iVar2;
}

// 0x60f067 — observed shape
int32_t FUN_0060f067(void *self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    int32_t iVar1 = FUN_00533c78(0x70);
    if (iVar1 == 0) {
        iVar1 = 0;
    } else {
        iVar1 = FUN_0060bc4a();
    }
    *reinterpret_cast<int32_t *>(base + 0x268) = iVar1;
    if (iVar1 == 0) {
        iVar1 = -0x7ff8fff2;
    } else {
        iVar1 = FUN_0060bcf9(param_1, param_2, self, base + 0x278, base + 0x18, param_4, 0, 0);
        if (iVar1 >= 0 && (iVar1 = FUN_0060e4ea(param_3), iVar1 >= 0)) {
            *reinterpret_cast<uint32_t *>(base + 0x26c) = *reinterpret_cast<uint32_t *>(base + 0x268);
            *reinterpret_cast<uint32_t *>(base + 0x270) = param_4;
            iVar1 = 0;
        }
    }
    return iVar1;
}

// 0x60f0e5 — observed shape
int32_t FUN_0060f0e5(void *self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    int32_t iVar1 = FUN_00533c78(0x70);
    if (iVar1 == 0) {
        iVar1 = 0;
    } else {
        iVar1 = FUN_0060bc4a();
    }
    *reinterpret_cast<int32_t *>(base + 0x268) = iVar1;
    if (iVar1 == 0) {
        iVar1 = -0x7ff8fff2;
    } else {
        iVar1 = FUN_0060beaa(param_1, param_2, self, base + 0x18);
        if (iVar1 >= 0) {
            iVar1 = FUN_0060e4ea(param_3);
            if (iVar1 >= 0) {
                *reinterpret_cast<uint32_t *>(base + 0x26c) = *reinterpret_cast<uint32_t *>(base + 0x268);
                *reinterpret_cast<uint32_t *>(base + 0x270) = param_4;
                iVar1 = 0;
            }
        }
    }
    return iVar1;
}

// 0x60f49b — observed shape
int32_t FUN_0060f49b(void *self)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    int32_t local_24[8];
    if (*reinterpret_cast<int32_t *>(base + 0x68) == 0) {
        return -0x7789f794;
    }
    int32_t rc;
    do {
        rc = FUN_0060f155(local_24);
        if (rc < 0) {
            return rc;
        }
    } while (local_24[0] != 0xd);
    int32_t node = *reinterpret_cast<int32_t *>(base + 0x68);
    *reinterpret_cast<uint32_t *>(base + 0x68) = *reinterpret_cast<uint32_t *>(node + 4);
    *reinterpret_cast<uint32_t *>(node + 4) = 0;
    FUN_0060bf1a(1);
    uint32_t value;
    if (*reinterpret_cast<uint32_t **>(base + 0x68) == nullptr) {
        value = 1;
    } else {
        value = **reinterpret_cast<uint32_t **>(base + 0x68);
    }
    *reinterpret_cast<uint32_t *>(base + 0x298) = value;
    return 0;
}

// 0x60f4f7 — observed shape
void FUN_0060f4f7(void *self)
{
    uint32_t *p = reinterpret_cast<uint32_t *>(self);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 1;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
}

// 0x60f517 — observed shape
void FUN_0060f517(void *self)
{
    int32_t *p = reinterpret_cast<int32_t *>(self);
    int32_t node = *p;
    while (node != 0) {
        node = *reinterpret_cast<int32_t *>(*p);
        operator delete(reinterpret_cast<void *>(static_cast<intptr_t>(*p)));
        *p = node;
    }
    operator delete(reinterpret_cast<void *>(static_cast<intptr_t>(p[6])));
    operator delete(reinterpret_cast<void *>(static_cast<intptr_t>(p[7])));
}

// 0x60f548 — observed shape
uint32_t FUN_0060f548(void *self, uint32_t param_1, uint32_t *param_2)
{
    unsigned char *base = reinterpret_cast<unsigned char *>(self);
    uint32_t count = *reinterpret_cast<uint32_t *>(base + 0x14);
    uint32_t half = count >> 1;
    uint32_t upper = count;
    uint32_t lo = 0;
    uint32_t result = 0;
    bool do_insert;

    if (count == 0) {
        do_insert = true;
    } else {
        do_insert = false;
        for (;;) {
            uint32_t cur = *reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(base + 0x18) + half * 4);
            if (cur < param_1) {
                lo = half + 1;
                half = upper;
            } else if (cur <= param_1) {
                break;
            }
            uint32_t mid = (half + lo) >> 1;
            bool more = lo < half;
            upper = half;
            half = mid;
            if (!more) {
                break;
            }
        }
        if (upper <= lo) {
            do_insert = true;
        }
    }

    if (do_insert) {
        if ((count & (~count + 1)) == count) {
            int32_t newcap = (count == 0) ? 1 : static_cast<int32_t>(count) * 2;
            uint32_t *fresh_flags = reinterpret_cast<uint32_t *>(FUN_00533c78(newcap << 2));
            if (fresh_flags == nullptr) {
                result = 0x8007000e;
                goto done;
            }
            {
                uint32_t *src = *reinterpret_cast<uint32_t **>(base + 0x1c);
                uint32_t *dst = fresh_flags;
                uint32_t n = *reinterpret_cast<uint32_t *>(base + 0x14) & 0x3fffffff;
                for (; n != 0; --n) {
                    *dst = *src;
                    ++src;
                    ++dst;
                }
                operator delete(*reinterpret_cast<void **>(base + 0x1c));
                *reinterpret_cast<uint32_t **>(base + 0x1c) = fresh_flags;
            }
            int32_t newcap2 = (*reinterpret_cast<int32_t *>(base + 0x14) == 0) ? 1 : *reinterpret_cast<int32_t *>(base + 0x14) * 2;
            uint32_t *fresh_keys = reinterpret_cast<uint32_t *>(FUN_00533c78(newcap2 << 2));
            if (fresh_keys == nullptr) {
                result = 0x8007000e;
                goto done;
            }
            {
                uint32_t *src = *reinterpret_cast<uint32_t **>(base + 0x18);
                uint32_t *dst = fresh_keys;
                uint32_t n = *reinterpret_cast<uint32_t *>(base + 0x14) & 0x3fffffff;
                for (; n != 0; --n) {
                    *dst = *src;
                    ++src;
                    ++dst;
                }
                operator delete(*reinterpret_cast<void **>(base + 0x18));
                *reinterpret_cast<uint32_t **>(base + 0x18) = fresh_keys;
            }
        }
        for (uint32_t n = *reinterpret_cast<uint32_t *>(base + 0x14); half < n; --n) {
            uint32_t *keyslot = reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(base + 0x18) + n * 4);
            *keyslot = keyslot[-1];
            uint32_t *flagslot = reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(base + 0x1c) + n * 4);
            *flagslot = flagslot[-1];
        }
        *reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(base + 0x18) + half * 4) = param_1;
        *reinterpret_cast<uint32_t *>(*reinterpret_cast<int32_t *>(base + 0x1c) + half * 4) = 1;
        *reinterpret_cast<int32_t *>(base + 0x14) = *reinterpret_cast<int32_t *>(base + 0x14) + 1;
    }
    if (param_2 != nullptr) {
        *param_2 = half;
    }
done:
    operator delete(nullptr);
    return result;
}

// 0x60f68b — observed shape
uint32_t FUN_0060f68b(void *self)
{
    uint32_t *p = reinterpret_cast<uint32_t *>(self);
    int32_t node = *reinterpret_cast<int32_t *>(p);
    while (node != 0) {
        node = *reinterpret_cast<int32_t *>(*p);
        operator delete(reinterpret_cast<void *>(static_cast<intptr_t>(*p)));
        *p = static_cast<uint32_t>(node);
    }
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    uint32_t index = 0;
    if (p[5] != 0) {
        do {
            uint32_t *flag = reinterpret_cast<uint32_t *>(p[7] + index * 4);
            *flag = *flag & 0xffffffdf;
            ++index;
        } while (index < p[5]);
    }
    return 0;
}

// 0x60f6ce — observed shape
uint32_t FUN_0060f6ce(void *self, char *param_1)
{
    uint32_t *p = reinterpret_cast<uint32_t *>(self);
    char *end = param_1;
    do {
        char c = *end;
        ++end;
    } while (c != '\0');

    int32_t text_len = static_cast<int32_t>(end - param_1) - 1;
    int32_t size = static_cast<int32_t>(end - param_1) + 4;
    char *node = reinterpret_cast<char *>(FUN_00533c78(size));
    if (node == nullptr) {
        return 0x8007000e;
    }
    *reinterpret_cast<uint32_t *>(node) = *p;
    p[1] = static_cast<uint32_t>(static_cast<int32_t>(p[1]) + text_len);
    *p = static_cast<uint32_t>(reinterpret_cast<intptr_t>(node));

    char *dst = node;
    for (uint32_t words = static_cast<uint32_t>(text_len) >> 2; words != 0; --words) {
        *reinterpret_cast<uint32_t *>(dst) = *reinterpret_cast<uint32_t *>(param_1);
        param_1 += 4;
        dst += 4;
    }
    for (uint32_t rest = static_cast<uint32_t>(text_len) & 3; rest != 0; --rest) {
        *dst = *param_1;
        ++param_1;
        ++dst;
    }
    return 0;
}

// 0x60f728 — observed shape
int32_t FUN_0060f728(void *self, uint32_t *param_1)
{
    uint32_t *p = reinterpret_cast<uint32_t *>(self);
    if (param_1 != nullptr) {
        if (p[1] == 0) {
            *param_1 = 0;
        } else {
            int32_t rc = FUN_00629497(p[1] + 1, param_1);
            if (rc < 0) {
                return rc;
            }
            intptr_t obj = static_cast<intptr_t>(*param_1);
            void **vtbl = *reinterpret_cast<void ***>(obj);
            typedef int32_t (*GetTextFn)(intptr_t);
            GetTextFn get_text = reinterpret_cast<GetTextFn>(vtbl[3]);
            int32_t raw = get_text(obj);
            char *cursor = reinterpret_cast<char *>(raw + p[1]);
            *cursor = '\0';
            for (uint32_t *node = reinterpret_cast<uint32_t *>(*p); node != nullptr; node = reinterpret_cast<uint32_t *>(*node)) {
                char *text = reinterpret_cast<char *>(node + 1);
                char *scan = text;
                char c;
                do {
                    c = *scan;
                    ++scan;
                } while (c != '\0');
                uint32_t len = static_cast<uint32_t>(scan - (reinterpret_cast<char *>(node) + 5));
                cursor -= len;
                char *src = text;
                char *dst = cursor;
                for (uint32_t n = len >> 2; n != 0; --n) {
                    *reinterpret_cast<uint32_t *>(dst) = *reinterpret_cast<uint32_t *>(src);
                    src += 4;
                    dst += 4;
                }
                for (uint32_t n = len & 3; n != 0; --n) {
                    *dst = *src;
                    ++src;
                    ++dst;
                }
            }
        }
    }
    return 0;
}

// 0x60f796 — observed shape
uint32_t FUN_0060f796(void *self)
{
    return *reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(self) + 8);
}

// 0x60f7b4 — observed shape
uint32_t FUN_0060f7b4(void *self, char *param_1, int32_t param_2, uint32_t param_3, uint32_t param_4, int32_t param_5, int32_t param_6)
{
    uint32_t *p = reinterpret_cast<uint32_t *>(self);
    if (param_5 != 0 && param_6 != 0) {
        if (param_2 == -1) {
            if (param_1 == nullptr) {
                param_2 = 0;
            } else {
                char *scan = param_1;
                char c;
                do {
                    c = *scan;
                    ++scan;
                } while (c != '\0');
                param_2 = static_cast<int32_t>(scan - (param_1 + 1));
            }
        }
        if (param_1 != nullptr || param_2 == 0) {
            p[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_1));
            p[6] = param_3;
            p[7] = param_4;
            p[0xb] = static_cast<uint32_t>(param_5);
            p[1] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_1 + param_2));
            p[0xc] = static_cast<uint32_t>(param_6);
            return 0;
        }
    }
    return 0x80004005;
}

// 0x60f81e — observed shape
uint32_t FUN_0060f81e(void *self)
{
    uint32_t *p = reinterpret_cast<uint32_t *>(self);
    char *end = reinterpret_cast<char *>(p[1]);
    if (reinterpret_cast<char *>(p[0]) < end) {
        char *cursor;
        do {
            cursor = reinterpret_cast<char *>(p[0]);
            if (*cursor == '\n') {
                return 1;
            }
            if (*cursor == '\\') {
                if (cursor + 1 < end && cursor[1] == '\n') {
                    cursor += 2;
                } else {
                    if (end <= cursor + 2 || cursor[1] != '\r' || cursor[2] != '\n') {
                        cursor += 1;
                        p[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(cursor));
                        continue;
                    }
                    cursor += 3;
                }
                p[7] = p[7] + 1;
            } else {
                cursor += 1;
            }
            p[0] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(cursor));
        } while (cursor < reinterpret_cast<char *>(p[1]));
    }
    return 0;
}
