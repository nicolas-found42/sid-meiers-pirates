#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdarg>
#include <windows.h>

extern uint32_t FUN_0062f194(uint32_t param_2, int param_3);
extern uint32_t ftol(double v);

extern void FUN_0062eef0(void* self);
extern void FUN_00630efb(void* self, uint8_t param_1);
extern void operator_delete(void* p);

extern void FUN_0060dc0d(void* self);
extern void FUN_006321e1(void* self);
extern void FUN_0060dcfa(void);
extern void FUN_0060fcd3(uint32_t handle, void* field, uint32_t code, const char* fmt, ...);
extern void FUN_006338c7(void);

extern uint32_t FUN_00533c78(uint32_t size);
extern uint32_t FUN_0062a5d2(void);
extern uint32_t FUN_0062a4e6(uint32_t param);
extern uint32_t FUN_0062a551(void);
extern uint32_t FUN_0062a5b1(uint32_t param);
extern uint32_t FUN_0062a62d(uint32_t param);
extern uint32_t FUN_0062a64e(void* buffer, uint32_t size, void* extra);
extern uint32_t FUN_0062a705(int32_t handle, void* out);
extern uint32_t FUN_0062a757(uint32_t handle, uint32_t flags);
extern uint32_t FUN_0062a7e2(uint32_t handle);
extern uint32_t FUN_0062a802(uint32_t handle, void* out);
extern uint32_t FUN_0062a866(uint32_t variable, void* typeOut, void* outA, void* outB,
                              void* outC, void* outD, void* outE);
extern uint32_t FUN_0062aed7(uint32_t variable, void* out);
extern uint32_t FUN_0062afd1(uint32_t variable, void* typeOut, uint32_t flags, uint32_t unused,
                              uint32_t param5, uint32_t param6, void* out, uint32_t param8);
extern uint32_t FUN_0062b4f8(void* spec, uint32_t index, uint32_t count, uint32_t count2,
                              void* out, uint32_t param6, uint32_t param7, uint32_t param8);
extern uint32_t FUN_0062e4a9(void);
extern uint32_t FUN_0062e4c9(void);
extern uint32_t FUN_0062e53e(uint32_t param);
extern uint32_t FUN_0062e55f(void);
extern uint32_t FUN_0062e6b7(uint32_t handle, void* item);
extern uint32_t FUN_0062e802(void* node);
extern uint32_t FUN_0062e88d(void* node, void* cursors, uint32_t limit);
extern uint32_t FUN_0062eecf(uint32_t param);
extern uint32_t FUN_0062ef38(void* node, uint32_t handle, uint32_t param, void* out);
extern uint32_t FUN_0062e426(void);

extern void FUN_006318c5(void* self);
extern void FUN_0063191e(void* self, uint8_t param_1);
extern void FUN_0063193f(void* self);
extern void FUN_00631a03(void* self, uint8_t param_1);
extern int32_t FUN_00630f77(int32_t* node, uint32_t param_2, uint32_t param_3);
extern int32_t FUN_0063164c(int32_t* node, uint32_t param_2, uint32_t param_3, uint32_t param_4, int32_t* param_5);
extern int32_t FUN_00631a24(void* self, int32_t* node, uint32_t param_2, uint32_t param_3);

extern uint32_t PTR_FUN_006e4e10[];
extern int32_t DAT_006c7974;

static constexpr uint32_t kErr = 0x8876086cu;

// 0x630860 — observed shape
uint32_t FUN_00630860(void* self, uint32_t param_2, float param_3) {
    uint32_t result = 0;
    uint32_t a = FUN_0062f194(param_2, 1);
    char* obj = reinterpret_cast<char*>(static_cast<uintptr_t>(a));
    if (a == 0) {
        result = kErr;
    } else {
        uint32_t* base = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(a)) + 4) + 0x40 +
            *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x344) +
            *reinterpret_cast<int32_t*>(obj + 0x18)));
        if (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 0x10) != 0 &&
            *reinterpret_cast<int32_t*>(obj + 0x10) == -1) {
            result = kErr;
        } else if (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 4) < 0) {
            result = kErr;
        } else if (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 4) > 3 ||
                   *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 0x14) != 1) {
            result = kErr;
        } else if (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 0x18) != 1) {
            result = kErr;
        } else {
            uint32_t inner = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x1c))) + 8);
            char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(inner));
            int32_t type = *reinterpret_cast<int32_t*>(e + 0x10);
            if (type == 0) {
                uint32_t v = (param_3 == 0.0f) ? 0u : 1u;
                *reinterpret_cast<uint32_t*>(e + 0x18) = v;
            } else if (type == 1 || type == 2) {
                uint32_t v = ftol(static_cast<double>(param_3));
                *reinterpret_cast<uint32_t*>(e + 0x18) = v;
            } else if (type == 3) {
                *reinterpret_cast<double*>(e + 0x18) = static_cast<double>(param_3);
                return 0;
            } else {
                result = kErr;
            }
        }
    }
    return result;
}

// 0x630902 — observed shape
uint32_t FUN_00630902(void* self, uint32_t param_2, float* param_3) {
    uint32_t result = 0;
    if (param_3 == nullptr) return kErr;
    uint32_t a = FUN_0062f194(param_2, 1);
    char* obj = reinterpret_cast<char*>(static_cast<uintptr_t>(a));
    if (a == 0) {
        result = kErr;
    } else {
        uint32_t* base = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(a)) + 4) + 0x40 +
            *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x344) +
            *reinterpret_cast<int32_t*>(obj + 0x18)));
        if (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 0x10) != 0 &&
            *reinterpret_cast<int32_t*>(obj + 0x10) == -1) {
            result = kErr;
        } else if (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 4) < 0) {
            result = kErr;
        } else if (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 4) > 3 ||
                   *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 0x14) != 1) {
            result = kErr;
        } else if (*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(base) + 0x18) != 1) {
            result = kErr;
        } else {
            uint32_t inner = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x1c))) + 8);
            char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(inner));
            int32_t type = *reinterpret_cast<int32_t*>(e + 0x10);
            float f = 0.0f;
            if (type == 0) {
                f = static_cast<float>(*reinterpret_cast<int32_t*>(e + 0x18) != 0);
            } else if (type == 1) {
                f = static_cast<float>(*reinterpret_cast<int32_t*>(e + 0x18));
            } else if (type == 2) {
                f = static_cast<float>(*reinterpret_cast<int32_t*>(e + 0x18));
                if (*reinterpret_cast<int32_t*>(e + 0x18) < 0) f += 4294967296.0f;
            } else if (type == 3) {
                f = static_cast<float>(*reinterpret_cast<double*>(e + 0x18));
            } else {
                result = kErr;
                return result;
            }
            *param_3 = f;
        }
    }
    return result;
}

// 0x6309bf — observed shape
uint32_t FUN_006309bf(void* self, uint32_t param_2, float* param_3, uint32_t param_4) {
    if (!((param_4 == 0) || (param_3 != nullptr))) return kErr;
    uint32_t a = FUN_0062f194(param_2, 1);
    if (a == 0) return kErr;
    char* obj = reinterpret_cast<char*>(static_cast<uintptr_t>(a));
    char* base = reinterpret_cast<char*>(static_cast<uintptr_t>(
        *reinterpret_cast<uint32_t*>(obj + 4) + 0x40 +
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x344) +
        *reinterpret_cast<int32_t*>(obj + 0x18)));
    if (*reinterpret_cast<int32_t*>(base + 4) < 0 || *reinterpret_cast<int32_t*>(base + 4) >= 4) return kErr;
    int32_t mult = *reinterpret_cast<int32_t*>(base + 0x10);
    if (mult == 0 || *reinterpret_cast<int32_t*>(obj + 0x10) != -1) mult = 1;
    uint32_t total = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0x18) * *reinterpret_cast<int32_t*>(base + 0x14) * mult);
    if (total <= param_4) param_4 = total;
    char* list = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x1c)));
    if (param_4 == 0) return 0;
    uint32_t idx = 0;
    char* node = list;
    do {
        if (node == nullptr) return 0;
        char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(node)) + 8)));
        int32_t type = *reinterpret_cast<int32_t*>(e + 0x10);
        if (type == 0) {
            uint32_t v = (param_3[idx] == 0.0f) ? 0u : 1u;
            *reinterpret_cast<uint32_t*>(e + 0x18) = v;
        } else if (type == 1 || type == 2) {
            uint32_t v = ftol(static_cast<double>(*reinterpret_cast<float*>(reinterpret_cast<char*>(param_3) + idx * 4)));
            *reinterpret_cast<uint32_t*>(e + 0x18) = v;
        } else if (type == 3) {
            *reinterpret_cast<double*>(e + 0x18) = static_cast<double>(*reinterpret_cast<float*>(reinterpret_cast<char*>(param_3) + idx * 4));
        } else {
            return kErr;
        }
        node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(node)) + 0xc)));
        idx++;
        if (param_4 <= idx) return 0;
    } while (true);
}

// 0x630ab3 — observed shape
uint32_t FUN_00630ab3(void* self, uint32_t param_2, float* param_3, uint32_t param_4) {
    uint32_t result = 0;
    if (param_4 != 0) {
        if (param_3 == nullptr) {
            result = kErr;
        } else {
            uint32_t a = FUN_0062f194(param_2, 1);
            if (a != 0) {
                char* obj = reinterpret_cast<char*>(static_cast<uintptr_t>(a));
                char* base = reinterpret_cast<char*>(static_cast<uintptr_t>(
                    *reinterpret_cast<uint32_t*>(obj + 4) + 0x40 +
                    *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x344) +
                    *reinterpret_cast<int32_t*>(obj + 0x18)));
                if (*reinterpret_cast<int32_t*>(base + 4) >= 0 && *reinterpret_cast<int32_t*>(base + 4) < 4) {
                    int32_t mult = *reinterpret_cast<int32_t*>(base + 0x10);
                    if (mult == 0 || *reinterpret_cast<int32_t*>(obj + 0x10) != -1) mult = 1;
                    uint32_t total = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0x18) * *reinterpret_cast<int32_t*>(base + 0x14) * mult);
                    if (total <= param_4) param_4 = total;
                    char* node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x1c)));
                    uint32_t idx = 0;
                    if (param_4 == 0) return 0;
                    do {
                        if (node == nullptr) return 0;
                        char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(node)) + 8)));
                        int32_t type = *reinterpret_cast<int32_t*>(e + 0x10);
                        float f = 0.0f;
                        if (type == 0) {
                            f = static_cast<float>(*reinterpret_cast<int32_t*>(e + 0x18) != 0);
                        } else if (type == 1) {
                            f = static_cast<float>(*reinterpret_cast<int32_t*>(e + 0x18));
                        } else if (type == 2) {
                            f = static_cast<float>(*reinterpret_cast<int32_t*>(e + 0x18));
                            if (*reinterpret_cast<int32_t*>(e + 0x18) < 0) f += 4294967296.0f;
                        } else if (type == 3) {
                            f = static_cast<float>(*reinterpret_cast<double*>(e + 0x18));
                        } else {
                            break;
                        }
                        param_3[idx] = f;
                        node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(node)) + 0xc)));
                        idx++;
                        if (param_4 <= idx) return 0;
                    } while (true);
                }
            }
            result = kErr;
        }
    }
    return result;
}

// 0x630ba0 — observed shape
uint32_t FUN_00630ba0(void* self, uint32_t param_2, int32_t* param_3, uint32_t param_4) {
    if (!((param_4 == 0) || (param_3 != nullptr))) return kErr;
    uint32_t a = FUN_0062f194(param_2, 1);
    if (a == 0) return kErr;
    char* obj = reinterpret_cast<char*>(static_cast<uintptr_t>(a));
    char* base = reinterpret_cast<char*>(static_cast<uintptr_t>(
        *reinterpret_cast<uint32_t*>(obj + 4) + 0x40 +
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x344) +
        *reinterpret_cast<int32_t*>(obj + 0x18)));
    if (*reinterpret_cast<int32_t*>(base + 4) < 0 || *reinterpret_cast<int32_t*>(base + 4) >= 4) return kErr;
    int32_t mult = *reinterpret_cast<int32_t*>(base + 0x10);
    if (mult == 0 || *reinterpret_cast<int32_t*>(obj + 0x10) != -1) mult = 1;
    uint32_t total = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0x18) * *reinterpret_cast<int32_t*>(base + 0x14) * mult);
    if (total <= param_4) param_4 = total;
    char* node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x1c)));
    uint32_t idx = 0;
    if (param_4 == 0) return 0;
    do {
        if (node == nullptr) return 0;
        char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(node)) + 8)));
        int32_t type = *reinterpret_cast<int32_t*>(e + 0x10);
        if (type == 0 || type == 1 || type == 2) {
            *reinterpret_cast<uint32_t*>(e + 0x18) = static_cast<uint32_t>(param_3[idx] != 0);
        } else {
            if (type != 3) return kErr;
            *reinterpret_cast<double*>(e + 0x18) = static_cast<double>(param_3[idx] != 0);
        }
        node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(node)) + 0xc)));
        idx++;
    } while (idx < param_4);
    return 0;
}

// 0x630c75 — observed shape
uint32_t FUN_00630c75(void* self, uint32_t param_2, void* param_3, uint32_t param_4) {
    uint32_t result = 0;
    if (param_4 != 0) {
        if (param_3 == nullptr) {
            result = kErr;
        } else {
            uint32_t a = FUN_0062f194(param_2, 1);
            if (a != 0) {
                char* obj = reinterpret_cast<char*>(static_cast<uintptr_t>(a));
                char* base = reinterpret_cast<char*>(static_cast<uintptr_t>(
                    *reinterpret_cast<uint32_t*>(obj + 4) + 0x40 +
                    *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x344) +
                    *reinterpret_cast<int32_t*>(obj + 0x18)));
                if (*reinterpret_cast<int32_t*>(base + 4) >= 0 && *reinterpret_cast<int32_t*>(base + 4) < 4) {
                    int32_t mult = *reinterpret_cast<int32_t*>(base + 0x10);
                    if (mult == 0 || *reinterpret_cast<int32_t*>(obj + 0x10) != -1) mult = 1;
                    uint32_t total = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0x18) * *reinterpret_cast<int32_t*>(base + 0x14) * mult);
                    if (total <= param_4) param_4 = total;
                    char* node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x1c)));
                    uint32_t idx = 0;
                    if (param_4 == 0) return 0;
                    do {
                        if (node == nullptr) return 0;
                        char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(node + 8)));
                        int32_t type = *reinterpret_cast<int32_t*>(e + 0x10);
                        uint32_t* out = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                            reinterpret_cast<uintptr_t>(param_3) + idx * 4));
                        if (type == 0 || type == 1 || type == 2) {
                            *out = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(e + 0x18) != 0);
                        } else {
                            if (type != 3) break;
                            *out = static_cast<uint32_t>(*reinterpret_cast<double*>(e + 0x18) != 0.0);
                        }
                        node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(node + 0xc)));
                        idx++;
                        if (param_4 <= idx) return 0;
                    } while (true);
                }
            }
            result = kErr;
        }
    }
    return result;
}

// 0x630d59 — observed shape
uint32_t FUN_00630d59(void* self, uint32_t param_2, char* param_3, uint32_t param_4) {
    if (!((param_4 == 0) || (param_3 != nullptr))) return kErr;
    uint32_t a = FUN_0062f194(param_2, 1);
    if (a == 0) return kErr;
    char* obj = reinterpret_cast<char*>(static_cast<uintptr_t>(a));
    char* base = reinterpret_cast<char*>(static_cast<uintptr_t>(
        *reinterpret_cast<uint32_t*>(obj + 4) + 0x40 +
        *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x344) +
        *reinterpret_cast<int32_t*>(obj + 0x18)));
    if (*reinterpret_cast<int32_t*>(base + 4) < 0 || *reinterpret_cast<int32_t*>(base + 4) >= 4) return kErr;
    int32_t mult = *reinterpret_cast<int32_t*>(base + 0x10);
    if (mult == 0 || *reinterpret_cast<int32_t*>(obj + 0x10) != -1) mult = 1;
    uint32_t total = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0x18) * *reinterpret_cast<int32_t*>(base + 0x14) * mult);
    if (total <= param_4) param_4 = total;
    char* node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x1c)));
    uint32_t idx = 0;
    if (param_4 == 0) return 0;
    do {
        if (node == nullptr) return 0;
        char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(node + 8)));
        int32_t type = *reinterpret_cast<int32_t*>(e + 0x10);
        int32_t* slot = reinterpret_cast<int32_t*>(param_3 + idx * 4);
        if (type == 0) {
            *reinterpret_cast<uint32_t*>(e + 0x18) = static_cast<uint32_t>(*slot != 0);
        } else if (type == 1 || type == 2) {
            *reinterpret_cast<uint32_t*>(e + 0x18) = static_cast<uint32_t>(*slot);
        } else {
            if (type != 3) return kErr;
            *reinterpret_cast<double*>(e + 0x18) = static_cast<double>(*slot);
        }
        node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(node + 0xc)));
        idx++;
        if (param_4 <= idx) return 0;
    } while (true);
}

// 0x630e22 — observed shape
uint32_t FUN_00630e22(void* self, uint32_t param_2, char* param_3, uint32_t param_4) {
    uint32_t result = 0;
    if (param_4 != 0) {
        if (param_3 == nullptr) {
            result = kErr;
        } else {
            uint32_t a = FUN_0062f194(param_2, 1);
            if (a != 0) {
                char* obj = reinterpret_cast<char*>(static_cast<uintptr_t>(a));
                char* base = reinterpret_cast<char*>(static_cast<uintptr_t>(
                    *reinterpret_cast<uint32_t*>(obj + 4) + 0x40 +
                    *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x344) +
                    *reinterpret_cast<int32_t*>(obj + 0x18)));
                if (*reinterpret_cast<int32_t*>(base + 4) >= 0 && *reinterpret_cast<int32_t*>(base + 4) < 4) {
                    int32_t mult = *reinterpret_cast<int32_t*>(base + 0x10);
                    if (mult == 0 || *reinterpret_cast<int32_t*>(obj + 0x10) != -1) mult = 1;
                    uint32_t total = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0x18) * *reinterpret_cast<int32_t*>(base + 0x14) * mult);
                    if (total <= param_4) param_4 = total;
                    char* node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x1c)));
                    uint32_t idx = 0;
                    if (param_4 == 0) return 0;
                    do {
                        if (node == nullptr) return 0;
                        char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(node + 8)));
                        int32_t type = *reinterpret_cast<int32_t*>(e + 0x10);
                        int32_t* out = reinterpret_cast<int32_t*>(param_3 + idx * 4);
                        if (type == 0) {
                            *out = static_cast<int32_t>(*reinterpret_cast<int32_t*>(e + 0x18) != 0);
                        } else {
                            if (type == 1 || type == 2) {
                                *reinterpret_cast<uint32_t*>(out) = *reinterpret_cast<uint32_t*>(e + 0x18);
                            } else {
                                if (type != 3) break;
                                *reinterpret_cast<uint32_t*>(out) = ftol(*reinterpret_cast<double*>(e + 0x18));
                            }
                        }
                        node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(node + 0xc)));
                        idx++;
                        if (param_4 <= idx) return 0;
                    } while (true);
                }
            }
            result = kErr;
        }
    }
    return result;
}

// 0x630efb — observed shape
void FUN_00630efb(void* self, uint8_t param_1) {
    FUN_0062eef0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x630f1c — observed shape
void FUN_00630f1c(void* self) {
    uint32_t* obj = reinterpret_cast<uint32_t*>(self);
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006e4e10));
    FUN_0060dc0d(self);
    FUN_006321e1(self);
    obj[200] = 0;
    obj[0xd2] = 0;
    obj[0xd3] = 0;
    obj[0xd4] = 0;
    obj[0xd5] = 0;
    obj[0xd6] = 0;
    obj[0xcf] = 0;
    obj[0xd1] = 0;
    obj[2] = 1;
}


// 0x630f77 — observed shape
int32_t FUN_00630f77(int32_t* node, uint32_t param_2, uint32_t param_3) {
    int32_t result = 0;
    char* local_1c = nullptr;
    char* local_18 = nullptr;
    char* local_14 = nullptr;
    char* local_10 = nullptr;
    char* var = nullptr;
    int32_t* block = nullptr;
    int32_t local_30 = 0, local_54 = 0, local_4c = 0, local_34 = 0, local_8 = 0;
    int32_t* local_20 = nullptr;
    uint32_t local_5c = 0, local_40 = 0, local_48 = 0, local_44 = 0;
    uint32_t local_50 = 0;
    uint8_t local_64[4], local_68[4], local_60[4];
    uint8_t local_94[40];
    uint8_t* local_6c = nullptr;
    int32_t local_c = 0;
    int32_t ann_err = 0;

    uint32_t t = FUN_00533c78(0x1c);
    local_1c = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
    if (local_1c == nullptr) {
        result = -0x7ff8fff2;
    } else {
        t = FUN_00533c78(0x1c);
        local_18 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
        if (local_18 == nullptr) goto LAB_006315ea;
        t = FUN_00533c78(0x1c);
        local_14 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
        if (local_14 == nullptr) goto LAB_006315ea;
        t = FUN_00533c78(0x1c);
        local_10 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
        if (local_10 == nullptr) goto LAB_006315ea;
        t = FUN_00533c78(0x48);
        var = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062e55f()));
        local_c = static_cast<int32_t>(reinterpret_cast<uintptr_t>(local_1c));
        if (var == nullptr) goto LAB_006315ea;
        {
            char* ann = reinterpret_cast<char*>(static_cast<uintptr_t>(node[6]));
            if (ann == nullptr || *reinterpret_cast<int32_t*>(ann + 4) != 0xb) goto LAB_006315e3;
            char* typeNode = reinterpret_cast<char*>(static_cast<uintptr_t>(node[5]));
            if (typeNode == nullptr || *reinterpret_cast<int32_t*>(typeNode + 4) != 3) goto LAB_006315e3;

            uint32_t flags = *reinterpret_cast<uint32_t*>(ann + 0x1c);
            if ((flags & 2) != 0) goto LAB_006315ef;

            local_20 = reinterpret_cast<int32_t*>(typeNode + 0x10);
            if (*local_20 != 9) goto LAB_006315e3;
            local_54 = *reinterpret_cast<int32_t*>(typeNode + 0x18);
            if (local_54 == 0) goto LAB_006315e3;
            local_4c = 0;
            local_5c = ((flags >> 3 & 0x10) | (flags & 8)) >> 3;
            {
                char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(ann + 0x2c)));
                if (e != nullptr) {
                    if (*reinterpret_cast<int32_t*>(e + 4) != 3) goto LAB_006315e3;
                    if (*reinterpret_cast<int32_t*>(e + 0x10) != 9) goto LAB_006315e3;
                    local_4c = *reinterpret_cast<int32_t*>(e + 0x18);
                }
            }
            result = static_cast<int32_t>(FUN_0062a866(*reinterpret_cast<uint32_t*>(ann + 0x20),
                                                       reinterpret_cast<uint32_t*>(&local_30),
                                                       local_64, local_68, &local_40, local_60, &local_48));
            if (result < 0) {
                FUN_0060fcd3(static_cast<uint32_t>(local_c) + 0x28, reinterpret_cast<int32_t*>(local_20), 0,
                             "ID3DXEffectCompiler: There was a problem getting variable type");
                goto LAB_006315ef;
            }
            if (local_30 == 0x12 || local_30 == 0x11) goto LAB_006315ef;
            if (local_30 == 0xf30000) {
                char* v = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(ann + 0x28)));
                if (v != nullptr) {
                    if (*reinterpret_cast<int32_t*>(v + 0x1c) != 0) goto LAB_006315e3;
                    char* w = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(v + 0x20)));
                    if (w == nullptr) goto LAB_006315e3;
                    if (*reinterpret_cast<int32_t*>(w + 4) != 1) goto LAB_006315e3;
                    char* x = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(w + 8)));
                    if (x == nullptr || *reinterpret_cast<int32_t*>(x + 4) != 0xe) goto LAB_006315e3;
                    int32_t* rec = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(FUN_00533c78(0xc)));
                    if (rec != nullptr) rec[2] = 0;
                    if (rec == nullptr) goto LAB_006315ea;
                    rec[0] = local_54;
                    rec[1] = *reinterpret_cast<int32_t*>(x + 0x18);
                    rec[2] = *reinterpret_cast<int32_t*>(local_c + 0x358);
                    *reinterpret_cast<int32_t*>(local_c + 0x358) = static_cast<int32_t>(reinterpret_cast<uintptr_t>(rec));
                }
                goto LAB_006315ef;
            }
            result = static_cast<int32_t>(FUN_0062afd1(*reinterpret_cast<uint32_t*>(ann + 0x20),
                                                       reinterpret_cast<int32_t*>(local_20),
                                                       static_cast<uint32_t>(local_4c), 0, param_3,
                                                       static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_18)),
                                                       &local_50, 0));
            if (result < 0) {
                FUN_0060fcd3(static_cast<uint32_t>(local_c) + 0x28, reinterpret_cast<int32_t*>(local_20), 0,
                             "ID3DXEffectCompiler: Error initializing variable type");
                goto LAB_006315ef;
            }
            if (local_30 >= 10 && local_30 <= 0xe) {
                char* spec = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(typeNode + 0x28)));
                local_8 = 0;
                if (spec == nullptr) {
                    local_34 = 0;
                    for (;;) {
                        uint32_t n = (local_40 == 0) ? 1u : local_40;
                        if (n <= static_cast<uint32_t>(local_8)) break;
                        int32_t rc = static_cast<int32_t>(FUN_0062a64e(
                            reinterpret_cast<uint32_t*>(&local_34), 4,
                            (local_8 != 0) ? &local_44 : static_cast<uint32_t*>(nullptr)));
                        if (rc < 0) break;
                        local_8++;
                    }
                } else {
                    char* it = spec;
                    do {
                        uint32_t n = (local_40 == 0) ? 1u : local_40;
                        if (n <= static_cast<uint32_t>(local_8)) break;
                        local_6c = nullptr;
                        uint8_t* pathTail = local_94;
                        for (char* e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 8)));
                             e != nullptr;
                             e = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(e + 0xc)))) {
                            int32_t rc = static_cast<int32_t>(FUN_0062e88d(e, &pathTail, 0x100));
                            if (rc < 0) goto LAB_006313c8;
                        }
                        local_34 = 0;
                        for (uint8_t* p = local_6c; p != nullptr;
                             p = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x28)))) {
                            int32_t rc = static_cast<int32_t>(FUN_0062b4f8(
                                p, 0xffffffff,
                                static_cast<uint32_t>(*reinterpret_cast<int32_t*>(local_c + 0x328)),
                                static_cast<uint32_t>(local_8), &local_34,
                                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_14)), param_3, 0x100));
                            if (rc < 0) goto LAB_006313c8;
                        }
                        int32_t rc = static_cast<int32_t>(FUN_0062a64e(
                            reinterpret_cast<uint32_t*>(&local_34), 4,
                            (local_8 != 0) ? &local_44 : static_cast<uint32_t*>(nullptr)));
                        if (rc < 0) goto LAB_006313c8;
                        rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_14))));
                        if (rc < 0) goto LAB_006313c8;
                        uint32_t q = FUN_00533c78(0x1c);
                        local_14 = (q == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
                        if (local_14 == nullptr) { result = -0x7ff8fff2; goto LAB_006313c8; }
                        FUN_0062a551();
                        it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0xc)));
                        local_8++;
                    } while (it != nullptr);
                    int32_t rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_10))));
                    if (rc < 0) goto LAB_006315ef;
                    local_10 = nullptr;
                    if (local_40 != 0 && local_40 < static_cast<uint32_t>(local_8)) {
                        FUN_0060fcd3(static_cast<uint32_t>(local_c) + 0x28, reinterpret_cast<int32_t*>(local_20), 0,
                                     "ID3DXEffectCompiler: There was a problem in the parse tree");
                        result = -0x7fffbffb;
                        goto LAB_006315fd;
                    }
                    *reinterpret_cast<int32_t*>(local_c + 0x334) += local_8;
                }
            } else {
                block = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(FUN_00533c78(local_48)));
                if (block == nullptr) goto LAB_006315ea;
                {
                    char* p = reinterpret_cast<char*>(block);
                    for (uint32_t i = 0; i < local_48; ++i) p[i] = 0;
                }
                int32_t rc = static_cast<int32_t>(FUN_0062aed7(*reinterpret_cast<uint32_t*>(ann + 0x20),
                                                                reinterpret_cast<uint32_t*>(&block)));
                if (rc >= 0) {
                    rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(block), local_48, &local_44));
                }
                if (rc < 0) goto LAB_006315ef;
            }

            *reinterpret_cast<int32_t*>(var + 0x28) = 0;
            {
                char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(node[7]));
                if (it != nullptr) {
                    do {
                        if (*reinterpret_cast<int32_t*>(it + 4) != 1) goto LAB_006315e3;
                        char* body = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 8)));
                        if (body == nullptr || *reinterpret_cast<int32_t*>(body + 4) != 6) goto LAB_006315e3;
                        if (*reinterpret_cast<int32_t*>(body + 0x10) != 1) {
                            FUN_0060fcd3(static_cast<uint32_t>(local_c) + 0x28, reinterpret_cast<int32_t*>(local_20), 0,
                                         "ID3DXEffectCompiler: There was a problem getting annotations");
                            goto LAB_006315e3;
                        }
                        int32_t rc = static_cast<int32_t>(FUN_0062ef38(
                            reinterpret_cast<uint32_t*>(body),
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_1c)), param_3,
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(var + 0x30))));
                        if (rc < 0 && ann_err > -1) ann_err = rc;
                        *reinterpret_cast<int32_t*>(var + 0x28) += 1;
                        it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0xc)));
                    } while (it != nullptr);
                    if (ann_err < 0) goto LAB_006315ef;
                }
            }
            {
                int32_t rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_18))));
                if (rc < 0) goto LAB_006315ef;
                local_18 = nullptr;
                rc = static_cast<int32_t>(FUN_0062a757(local_50, 0));
                if (rc < 0) goto LAB_006315ef;
                rc = static_cast<int32_t>(FUN_0062a757(local_44, 0));
                if (rc < 0) goto LAB_006315ef;
                rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(&local_5c), 4, &param_3));
                if (rc < 0) goto LAB_006315ef;
                rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(var + 0x28), 4, nullptr));
                if (rc < 0) goto LAB_006315ef;
                rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_1c))));
                if (rc < 0) goto LAB_006315ef;
                *reinterpret_cast<int32_t*>(var + 0x20) = local_54;
                local_1c = nullptr;
                *reinterpret_cast<int32_t*>(var + 0x24) = local_4c;
                *reinterpret_cast<uint32_t*>(var + 0x40) = local_50;
                *reinterpret_cast<uint32_t*>(var + 0x44) = param_3;
                *reinterpret_cast<int32_t*>(var + 0x2c) = static_cast<int32_t>(reinterpret_cast<uintptr_t>(ann));
                *reinterpret_cast<uint32_t*>(var + 0x3c) = local_44;
                *reinterpret_cast<int32_t*>(var + 0x34) = *reinterpret_cast<int32_t*>(local_c + 0x34c);
                *reinterpret_cast<int32_t*>(var + 0x38) = node[5] + 0x10;
                *reinterpret_cast<int32_t*>(local_c + 0x34c) = static_cast<int32_t>(reinterpret_cast<uintptr_t>(var));
                var = nullptr;
                *reinterpret_cast<int32_t*>(local_c + 0x328) += 1;
                result = 0;
            }
        }
    }
    goto LAB_006315ef;
LAB_006313c8:
    FUN_0062a551();
    goto LAB_006315ef;
LAB_006315e3:
    result = -0x7fffbffb;
LAB_006315ea:
    if (result == 0) result = -0x7ff8fff2;
LAB_006315ef:
    if (local_10 != nullptr) FUN_0062a62d(1);
LAB_006315fd:
    if (local_14 != nullptr) FUN_0062a62d(1);
    if (local_1c != nullptr) FUN_0062a62d(1);
    if (local_18 != nullptr) FUN_0062a62d(1);
    if (var != nullptr) FUN_0062eecf(1);
    if (block != nullptr) operator_delete(block);
    return result;
}

// 0x63164c — observed shape
int32_t FUN_0063164c(int32_t* node, uint32_t param_2, uint32_t param_3, uint32_t param_4, int32_t* param_5) {
    int32_t result = 0;
    char* local_10 = nullptr;
    char* local_8 = nullptr;
    char* local_18 = nullptr;
    uint8_t local_4c[40];
    uint8_t* local_24 = nullptr;
    int32_t local_20 = 0;
    int32_t local_c = 0;
    uint8_t* local_14 = nullptr;

    uint32_t t = FUN_00533c78(0x1c);
    local_18 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
    if (local_18 == nullptr) {
        result = -0x7ff8fff2;
    } else {
        t = FUN_00533c78(0x1c);
        local_10 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
        if (local_10 == nullptr) goto LAB_00631885;
        t = FUN_00533c78(0x30);
        local_8 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062e4c9()));
        if (local_8 == nullptr) goto LAB_00631885;
        {
            char* iVar3 = reinterpret_cast<char*>(static_cast<uintptr_t>(node[5]));
            local_20 = 0;
            if (iVar3 != nullptr) {
                if (*reinterpret_cast<int32_t*>(iVar3 + 4) != 3) goto LAB_0063176f;
                if (*reinterpret_cast<int32_t*>(iVar3 + 0x10) != 9) goto LAB_0063176f;
                local_20 = *reinterpret_cast<int32_t*>(iVar3 + 0x18);
            }
        }
        *reinterpret_cast<int32_t*>(local_8 + 0x24) = 0;
        for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(node[7])); it != nullptr;
             it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0xc)))) {
            if (*reinterpret_cast<int32_t*>(it + 4) != 1) goto LAB_0063176f;
            char* body = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 8)));
            if (body == nullptr || *reinterpret_cast<int32_t*>(body + 4) != 6) goto LAB_0063176f;
            if (*reinterpret_cast<int32_t*>(body + 0x10) != 1) {
                FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_18)) + 0x28, 0, 0,
                             "ID3DXEffectCompiler: There was a problem getting annotations");
                goto LAB_0063176f;
            }
            int32_t rc = static_cast<int32_t>(FUN_0062ef38(
                reinterpret_cast<uint32_t*>(body),
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_10)), param_4,
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_8 + 0x28))));
            if (rc < 0 && local_c > -1) local_c = rc;
            *reinterpret_cast<int32_t*>(local_8 + 0x24) += 1;
        }
        local_14 = local_4c;
        for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(node[6])); it != nullptr;
             it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0xc)))) {
            int32_t rc = static_cast<int32_t>(FUN_0062e88d(it, &local_14, 0xffffffff));
            if (rc < 0 && local_c > -1) local_c = rc;
        }
        if (local_c > -1) {
            int32_t local_6c = 0;
            for (uint8_t* p = local_24; p != nullptr;
                 p = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x28)))) {
                int32_t rc = static_cast<int32_t>(FUN_0062b4f8(
                    p, static_cast<uint32_t>(*reinterpret_cast<int32_t*>(local_10 + 0x324)), param_2,
                    0xffffffff, reinterpret_cast<uint32_t*>(&local_6c),
                    static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_18)), param_4, 0xffffffff));
                if (rc < 0 && local_c > -1) local_c = rc;
            }
            if (local_c > -1) {
                int32_t rc = static_cast<int32_t>(FUN_0062a705(local_20, &param_4));
                if (rc > -1) rc = static_cast<int32_t>(FUN_0062a757(param_4, 0));
                if (rc > -1) rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(local_8 + 0x24), 4, nullptr));
                if (rc > -1) rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(&local_6c), 4, nullptr));
                if (rc > -1) rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_10))));
                if (rc > -1) {
                    local_10 = nullptr;
                    rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_18))));
                    if (rc > -1) {
                        *reinterpret_cast<int32_t*>(local_8 + 0x20) = local_20;
                        *reinterpret_cast<int32_t*>(local_8 + 0x2c) = *param_5;
                        *param_5 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(local_8));
                        goto LAB_006318b4;
                    }
                }
            }
        }
LAB_0063176f:
        result = -0x7fffbffb;
    }
LAB_00631885:
    if (local_8 != nullptr) FUN_00630efb(local_8, 1);
    if (local_18 != nullptr) FUN_0062a62d(1);
    if (local_10 != nullptr) FUN_0062a62d(1);
LAB_006318b4:
    FUN_0062a551();
    return result;
}

// 0x6318c5 — observed shape
void FUN_006318c5(void* self) {
    char* obj = reinterpret_cast<char*>(self);
    if (*reinterpret_cast<int32_t*>(obj + 0x30) != 0) {
        FUN_0062eecf(1);
        *reinterpret_cast<int32_t*>(obj + 0x30) = 0;
    }
    if (*reinterpret_cast<int32_t*>(obj + 0x2c) != 0) {
        FUN_00630efb(obj, 1);
        *reinterpret_cast<int32_t*>(obj + 0x2c) = 0;
    }
    char* node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x34)));
    while (node != nullptr) {
        char* pv = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x34)));
        *reinterpret_cast<uint32_t*>(obj + 0x34) = *reinterpret_cast<uint32_t*>(pv + 0x34);
        *reinterpret_cast<uint32_t*>(pv + 0x34) = 0;
        FUN_006318c5(pv);
        operator_delete(pv);
        node = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0x34)));
    }
    FUN_0062e426();
}

// 0x63191e — observed shape
void FUN_0063191e(void* self, uint8_t param_1) {
    FUN_006318c5(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x63193f — observed shape
void FUN_0063193f(void* self) {
    uint32_t* obj = reinterpret_cast<uint32_t*>(self);
    obj[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006e4e10));
    if (obj[200] != 0) obj[200] = 0;
    if (obj[0xd2] != 0) {
        FUN_0063191e(reinterpret_cast<void*>(static_cast<uintptr_t>(obj[0xd2])), 1);
        obj[0xd2] = 0;
    }
    if (obj[0xd3] != 0) {
        FUN_0062eecf(1);
        obj[0xd3] = 0;
    }
    if (obj[0xd4] != 0) {
        FUN_0062e53e(1);
        obj[0xd4] = 0;
    }
    if (obj[0xd5] != 0) {
        FUN_0062a5b1(1);
        obj[0xd5] = 0;
    }
    if (obj[0xd6] != 0) {
        FUN_0062a4e6(1);
        obj[0xd6] = 0;
    }
    void* pv = reinterpret_cast<void*>(static_cast<uintptr_t>(obj[0xcf]));
    if (pv != nullptr) {
        operator_delete(pv);
        obj[0xcf] = 0;
    }
    pv = reinterpret_cast<void*>(static_cast<uintptr_t>(obj[0xd1]));
    if (pv != nullptr) {
        operator_delete(pv);
        obj[0xd1] = 0;
    }
    FUN_006338c7();
    FUN_0060dcfa();
}

// 0x631a03 — observed shape
void FUN_00631a03(void* self, uint8_t param_1) {
    FUN_0063193f(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x631a24 — observed shape
int32_t FUN_00631a24(void* self, int32_t* node, uint32_t param_2, uint32_t param_3) {
    char* own = reinterpret_cast<char*>(self);
    int32_t result = 0;
    char* local_c = nullptr;
    char* local_10 = nullptr;
    char* var = nullptr;
    int32_t local_18 = 0;
    bool alloc_failed = false;

    uint32_t t = FUN_00533c78(0x1c);
    local_c = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
    if (local_c == nullptr) alloc_failed = true;
    if (local_c != nullptr) {
        t = FUN_00533c78(0x1c);
        local_10 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
        if (local_10 == nullptr) alloc_failed = true;
        if (local_10 != nullptr) {
            t = FUN_00533c78(0x38);
            var = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062e4a9()));
            if (var == nullptr) alloc_failed = true;
            if (var != nullptr) {
                bool ok = true;
                char* typeNode = reinterpret_cast<char*>(static_cast<uintptr_t>(node[5]));
                if (typeNode != nullptr) {
                    if (*reinterpret_cast<int32_t*>(typeNode + 4) != 3) ok = false;
                    else if (*reinterpret_cast<int32_t*>(typeNode + 0x10) != 9) ok = false;
                    else local_18 = *reinterpret_cast<int32_t*>(typeNode + 0x18);
                }
                if (!ok) {
                    result = -0x7fffbffb;
                } else {
                    *reinterpret_cast<int32_t*>(var + 0x24) = 0;
                    for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(node[7])); it != nullptr;
                         it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0xc)))) {
                        if (*reinterpret_cast<int32_t*>(it + 4) != 1) { ok = false; break; }
                        char* body = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 8)));
                        if (body == nullptr || *reinterpret_cast<int32_t*>(body + 4) != 6) { ok = false; break; }
                        if (*reinterpret_cast<int32_t*>(body + 0x10) != 1) {
                            FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                                         "ID3DXEffectCompiler: There was a problem getting annotations");
                            ok = false;
                            break;
                        }
                        int32_t rc = static_cast<int32_t>(FUN_0062ef38(
                            reinterpret_cast<uint32_t*>(body),
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_c)), param_3,
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(var + 0x30))));
                        if (rc < 0 && result > -1) result = rc;
                        *reinterpret_cast<int32_t*>(var + 0x24) += 1;
                    }
                    if (!ok) {
                        result = -0x7fffbffb;
                    } else {
                        int32_t* count = reinterpret_cast<int32_t*>(var + 0x28);
                        *count = 0;
                        for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(node[6])); it != nullptr;
                             it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0xc)))) {
                            if (*reinterpret_cast<int32_t*>(it + 4) != 1) { ok = false; break; }
                            char* body = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 8)));
                            if (body == nullptr || *reinterpret_cast<int32_t*>(body + 4) != 6) { ok = false; break; }
                            if (*reinterpret_cast<int32_t*>(body + 0x10) != 4) {
                                FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                                             "ID3DXEffectCompiler: Only pass allowed within a technique");
                                ok = false;
                                break;
                            }
                            int32_t rc = static_cast<int32_t>(FUN_0063164c(
                                reinterpret_cast<int32_t*>(body), static_cast<uint32_t>(*count),
                                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_10)), param_3,
                                reinterpret_cast<int32_t*>(var + 0x2c)));
                            if (rc < 0 && result > -1) result = rc;
                            *count += 1;
                        }
                        if (!ok) {
                            result = -0x7fffbffb;
                        } else {
                            *reinterpret_cast<int32_t*>(own + 0x334) += *count;
                            int32_t rc = static_cast<int32_t>(FUN_0062a705(local_18, &param_3));
                            if (rc > -1) rc = static_cast<int32_t>(FUN_0062a757(param_3, 0));
                            if (rc > -1) rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(var + 0x24), 4, nullptr));
                            if (rc > -1) rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(count), 4, nullptr));
                            if (rc > -1) rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_c))));
                            if (rc > -1) {
                                local_c = nullptr;
                                rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_10))));
                                if (rc > -1) {
                                    *reinterpret_cast<int32_t*>(var + 0x20) = local_18;
                                    *reinterpret_cast<int32_t*>(var + 0x34) = *reinterpret_cast<int32_t*>(own + 0x348);
                                    *reinterpret_cast<int32_t*>(own + 0x324) += 1;
                                    *reinterpret_cast<int32_t*>(own + 0x348) = static_cast<int32_t>(reinterpret_cast<uintptr_t>(var));
                                    result = rc;
                                    var = nullptr;
                                    local_10 = nullptr;
                                    local_c = nullptr;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (result == 0 && alloc_failed) result = -0x7ff8fff2;
    if (var != nullptr) FUN_0063191e(var, 1);
    if (local_c != nullptr) FUN_0062a62d(1);
    if (local_10 != nullptr) FUN_0062a62d(1);
    return result;
}

// 0x631c92 — observed shape
uint32_t FUN_00631c92(void* self) {
    char* obj = reinterpret_cast<char*>(self);
    int32_t* ref = reinterpret_cast<int32_t*>(obj + 8);
    *ref = *ref - 1;
    uint32_t value = static_cast<uint32_t>(*ref);
    if (*ref == 0) {
        FUN_00631a03(self, 1);
        value = 0;
    }
    return value;
}

// 0x631caf — observed shape
int32_t FUN_00631caf(void* self, int32_t* node) {
    char* own = reinterpret_cast<char*>(self);
    int32_t result = 0;
    char* local_8 = nullptr;
    char* local_c = nullptr;
    char* local_14 = nullptr;
    char* local_18 = nullptr;
    uint32_t local_1c = 0;

    uint32_t t = FUN_00533c78(0x1c);
    local_8 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
    if (local_8 == nullptr) {
        result = -0x7ff8fff2;
        goto LAB_00632185;
    }
    t = FUN_00533c78(0x1c);
    local_c = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
    if (local_c == nullptr) goto LAB_00632180;
    t = FUN_00533c78(0x1c);
    local_14 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
    if (local_14 == nullptr) goto LAB_00632180;
    t = FUN_00533c78(0x1c);
    local_18 = (t == 0) ? nullptr : reinterpret_cast<char*>(static_cast<uintptr_t>(FUN_0062a5d2()));
    if (local_18 == nullptr) goto LAB_00632180;

    result = static_cast<int32_t>(FUN_0062a64e(&local_1c, 4, nullptr));
    if (result < 0) goto LAB_00632189;
    if (node == nullptr || node[1] != 4) {
        result = -0x7fffbffb;
        goto LAB_00632189;
    }
    *reinterpret_cast<int32_t*>(own + 4) = 0;
    *reinterpret_cast<int32_t*>(own + 0x328) = 0;
    *reinterpret_cast<int32_t*>(own + 0x324) = 0;
    *reinterpret_cast<int32_t*>(own + 0x32c) = 0;
    *reinterpret_cast<int32_t*>(own + 0x330) = 1;
    *reinterpret_cast<int32_t*>(own + 0x334) = 0;
    {
        int32_t* local_10_state = nullptr;
        int32_t local_10 = 0;
        for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(node[7])); it != nullptr;
             it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0xc)))) {
            if (*reinterpret_cast<int32_t*>(it + 4) != 1) {
                FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                             "ID3DXEffectCompiler: There was an unexpected error in the parse tree");
                result = -0x7fffbffb;
                goto LAB_00632189;
            }
            char* body = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 8)));
            if (body == nullptr) {
                FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                             "ID3DXEffectCompiler: There was an unexpected error in the parse tree");
                result = -0x7fffbffb;
                goto LAB_00632189;
            }
            if (*reinterpret_cast<int32_t*>(body + 4) == 0xc) continue;
            if (*reinterpret_cast<int32_t*>(body + 4) != 6) {
                FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                             "ID3DXEffectCompiler: There was an unexpected error in the parse tree");
                result = -0x7fffbffb;
                goto LAB_00632189;
            }
            int32_t kind = *reinterpret_cast<int32_t*>(body + 0x10);
            if (kind == 0) continue;
            int32_t rc;
            if (kind == 1) {
                rc = FUN_00630f77(reinterpret_cast<int32_t*>(body),
                                  static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_14)),
                                  static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_c)));
            } else if (kind == 2) {
                rc = static_cast<int32_t>(FUN_0062e802(reinterpret_cast<uint32_t*>(body)));
            } else if (kind == 3) {
                rc = FUN_00631a24(self, reinterpret_cast<int32_t*>(body),
                                  static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_18)),
                                  static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_c)));
            } else {
                result = -0x7fffbffb;
                goto LAB_00632189;
            }
            if (rc < 0 && local_10 > -1) local_10 = rc;
        }
        (void)local_10_state;
        if (local_10 < 0) {
            result = local_10;
            goto LAB_00632185;
        }
    }
    if (*reinterpret_cast<int32_t*>(own + 0x358) != 0) {
        FUN_0062a4e6(1);
        *reinterpret_cast<int32_t*>(own + 0x358) = 0;
    }
    {
        int32_t rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(own + 0x328), 4, nullptr));
        if (rc > -1) rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(own + 0x324), 4, nullptr));
        if (rc > -1) rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(own + 0x334), 4, nullptr));
        if (rc > -1) rc = static_cast<int32_t>(FUN_0062a64e(reinterpret_cast<uint32_t*>(own + 0x330), 4, nullptr));
        if (rc > -1) rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_14))));
        if (rc < 0) goto LAB_00632189;
        local_14 = nullptr;
        rc = static_cast<int32_t>(FUN_0062a7e2(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_18))));
        if (rc < 0) goto LAB_00632189;
        local_18 = nullptr;
        *reinterpret_cast<int32_t*>(own + 0x338) = 0;
        *reinterpret_cast<int32_t*>(own + 0x340) = 0;
        rc = static_cast<int32_t>(FUN_0062a802(0, reinterpret_cast<uint32_t*>(own + 0x338)));
        if (rc < 0) goto LAB_00632189;
        rc = static_cast<int32_t>(FUN_0062a802(0, reinterpret_cast<uint32_t*>(own + 0x340)));
        if (rc < 0) goto LAB_00632189;

        for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(own + 0x34c)));
             it != nullptr;
             it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x34)))) {
            *reinterpret_cast<int32_t*>(it + 0x40) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x40)) + 0x18);
            *reinterpret_cast<int32_t*>(it + 0x3c) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x3c)) + 0x18);
            *reinterpret_cast<int32_t*>(it + 0x44) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x44)) + 0x18);
            for (char* p = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x30)));
                 p != nullptr;
                 p = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x34)))) {
                *reinterpret_cast<int32_t*>(p + 0x40) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x40)) + 0x18);
                *reinterpret_cast<int32_t*>(p + 0x3c) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x3c)) + 0x18);
                *reinterpret_cast<int32_t*>(p + 0x44) = 0;
            }
        }
        for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(own + 0x348)));
             it != nullptr;
             it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x34)))) {
            for (char* p = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x30)));
                 p != nullptr;
                 p = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x34)))) {
                *reinterpret_cast<int32_t*>(p + 0x40) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x40)) + 0x18);
                *reinterpret_cast<int32_t*>(p + 0x3c) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x3c)) + 0x18);
                *reinterpret_cast<int32_t*>(p + 0x44) = 0;
            }
            for (char* q = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x2c)));
                 q != nullptr;
                 q = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(q + 0x2c)))) {
                for (char* r = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(q + 0x28)));
                     r != nullptr;
                     r = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(r + 0x34)))) {
                    *reinterpret_cast<int32_t*>(r + 0x40) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(r + 0x40)) + 0x18);
                    *reinterpret_cast<int32_t*>(r + 0x3c) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(r + 0x3c)) + 0x18);
                    *reinterpret_cast<int32_t*>(r + 0x44) = 0;
                }
            }
        }
        for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(own + 0x354)));
             it != nullptr;
             it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x18)))) {
            *reinterpret_cast<int32_t*>(it + 0x20) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x20)) + 0x18);
            *reinterpret_cast<int32_t*>(it + 0x1c) = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x1c)) + 0x18);
        }
        t = FUN_00533c78(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(own + 0x338)));
        *reinterpret_cast<int32_t*>(own + 0x33c) = static_cast<int32_t>(t);
        if (t == 0) goto LAB_00632189;
        t = FUN_00533c78(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(own + 0x340)));
        *reinterpret_cast<int32_t*>(own + 0x344) = static_cast<int32_t>(t);
        if (t == 0) goto LAB_00632189;
        rc = static_cast<int32_t>(FUN_0062a802(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(own + 0x33c)), 0));
        if (rc < 0) goto LAB_00632189;
        rc = static_cast<int32_t>(FUN_0062a802(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(own + 0x344)), 0));
        if (rc < 0) goto LAB_00632189;

        for (char* it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(own + 0x34c)));
             it != nullptr;
             it = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(it + 0x34)))) {
            rc = static_cast<int32_t>(FUN_0062e6b7(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(own + 0x344)), it));
            if (rc < 0) {
                FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                             "ID3DXEffectCompiler: There was an error initializing parameter handles");
                goto LAB_00632185;
            }
        }
        for (char* tech = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(own + 0x348)));
             tech != nullptr;
             tech = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(tech + 0x34)))) {
            for (char* p = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(tech + 0x30)));
                 p != nullptr;
                 p = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p + 0x34)))) {
                rc = static_cast<int32_t>(FUN_0062e6b7(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(own + 0x344)), p));
                if (rc < 0) {
                    FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                                 "ID3DXEffectCompiler: There was an error initializing technique annotation handles");
                    goto LAB_00632185;
                }
            }
            for (char* q = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(tech + 0x2c)));
                 q != nullptr;
                 q = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(q + 0x2c)))) {
                for (char* r = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(q + 0x28)));
                     r != nullptr;
                     r = reinterpret_cast<char*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(r + 0x34)))) {
                    rc = static_cast<int32_t>(FUN_0062e6b7(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(own + 0x344)), r));
                    if (rc < 0) {
                        FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                                     "ID3DXEffectCompiler: There was an error initializing pass annotation handles");
                        goto LAB_00632185;
                    }
                }
            }
        }
        *reinterpret_cast<int32_t*>(own + 800) = static_cast<int32_t>(reinterpret_cast<uintptr_t>(node));
    }
    goto LAB_0063219c;
LAB_00632180:
    result = -0x7ff8fff2;
LAB_00632185:
    if (result < 0) goto LAB_0063219c;
LAB_00632189:
    FUN_0060fcd3(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(own)) + 0x28, 0, 0,
                 "ID3DXEffectCompiler: There was an error initializing the compiler");
LAB_0063219c:
    if (local_14 != nullptr) FUN_0062a62d(1);
    if (local_18 != nullptr) FUN_0062a62d(1);
    if (local_8 != nullptr) FUN_0062a62d(1);
    if (local_c != nullptr) FUN_0062a62d(1);
    return result;
}

// 0x6321f5 — observed shape
void FUN_006321f5(void* self, char* param_2, char param_3) {
    char* obj = reinterpret_cast<char*>(self);
    char local_104[256];
    int32_t iVar1 = 0xd;
    bool equal = true;
    char* pcVar4 = param_2;
    const char* pcVar2 = "syntax error";
    do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 - 1;
        equal = (*pcVar4 == *pcVar2);
        pcVar4 = pcVar4 + 1;
        pcVar2 = pcVar2 + 1;
    } while (equal);
    if (!equal) {
        va_list ap;
        va_start(ap, param_3);
        _vsnprintf(local_104, 0x100, param_2, ap);
        va_end(ap);
        local_104[255] = 0;
        FUN_0060fcd3(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(obj + 4)) + 0x18,
                     reinterpret_cast<int32_t*>(obj + 0x20), 0, reinterpret_cast<const char*>(&DAT_006c7974), local_104);
        goto LAB_0063231a;
    }
    if (*reinterpret_cast<int32_t*>(obj + 0x40) != 0) goto LAB_0063231a;
    iVar1 = *reinterpret_cast<int32_t*>(obj + 0x20);
    if (iVar1 < 10) {
        if (iVar1 != 9) {
            if (iVar1 == 0) {
                pcVar2 = "version token";
                goto LAB_006322e5_str;
            }
            if (iVar1 == 1) {
                int32_t tok = *reinterpret_cast<int32_t*>(obj + 0x28);
                _snprintf(local_104, 0x100, "token \'%s\'", reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(tok))));
                goto LAB_006322e5_done;
            }
            if (iVar1 < 2) {
                pcVar2 = "token";
            } else if (iVar1 < 5) {
                pcVar2 = "integer constant";
            } else {
                if (iVar1 > 8) {
                    pcVar2 = "token";
                } else {
                    pcVar2 = "float constant";
                }
            }
            goto LAB_006322e5_str;
        }
        {
            int32_t tok = *reinterpret_cast<int32_t*>(obj + 0x28);
            _snprintf(local_104, 0x100, "token \'%s\'", reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(tok))));
        }
        goto LAB_006322e5_done;
    }
    if (iVar1 == 10) {
        pcVar2 = "string constant";
    } else if (iVar1 == 0xc) {
        pcVar2 = "end of line";
    } else {
        if (iVar1 != 0xd) {
            pcVar2 = "token";
        } else {
            pcVar2 = "end of file";
        }
    }
LAB_006322e5_str:
    _snprintf(local_104, 0x100, pcVar2);
LAB_006322e5_done:
    FUN_0060fcd3(static_cast<uint32_t>(*reinterpret_cast<int32_t*>(obj + 4)) + 0x18,
                 reinterpret_cast<int32_t*>(obj + 0x20), 3000,
                 "syntax error: unexpected %s", local_104);
LAB_0063231a:
    *reinterpret_cast<int32_t*>(obj + 0x40) = 1;
}
