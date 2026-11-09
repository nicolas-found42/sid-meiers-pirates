// Reconstruction batch mass_0245 — Sid Meier's Pirates! (2004)
// Translated per-function from Ghidra 12.2 pseudocode in analysis/pseudocode/functions/.
// Receiver registers (in_ECX) are explicit `void* self` parameters; `this` is never
// used inside a free function. Globals/helpers used below are declared extern and
// were observed in the supplied listings (no invented addresses).

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

// ---- Observed globals (used by the listings below) ----
extern void* ExceptionList;
extern char LAB_006b99ab;
extern char LAB_006b99cb;
extern char LAB_006b99e8;
extern uint32_t DAT_0072925c;
extern uint32_t DAT_00729260;
extern uint8_t DAT_006c9a9c[];
extern void* PTR_LAB_006c9b24;
extern void* PTR_FUN_006c9b30;
extern void* PTR_FUN_006c9b4c;
extern void* PTR_FUN_006c9b68;
extern void* PTR_FUN_006c9b20;

// ---- Observed helpers ----
extern void* FUN_00533c78(uint32_t size);
extern void* FUN_005e8450(void* alloc);
extern int FUN_005e8510(char* param_1, char* param_2, uint32_t param_3, uint32_t param_4);
extern char FUN_005e8380(char* param_1, char* param_2, uint32_t param_3);
extern char FUN_005e8220(uint32_t param_1);
extern char FUN_006b5090(uint32_t param_1, int* param_2);
extern int* FUN_005ebdf0();
extern void* FUN_005ea550();
extern char FUN_005ea450(uint32_t param_1);
extern void FUN_005ea3c0();
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void FUN_00497420(const char* fmt, ...);
extern void FUN_005c9a50(const char* fmt, ...);
extern void FUN_005e1490();
extern int FUN_005e5b50(uint32_t addr);
extern uint32_t FUN_005dc0e0();
extern int FUN_005ec780(uint32_t idx, uint32_t unk);
extern uint32_t FUN_005ed430();
extern int FUN_005ed440(uint32_t idx, uint32_t unk);
extern void FUN_006b3d40(void** pp);
extern uint32_t FUN_005dbe20(uint32_t size, void* buf);
extern void FUN_005be160(uint32_t val);
extern void FUN_005be1e0(uint32_t val);
extern void FUN_005ec420();
extern uint32_t FUN_005ece60();
extern uint32_t FUN_005d5fd0();
extern uint32_t FUN_005dbd60();
extern int FUN_005dbd70();

// 0x5e84a0 — observed shape: lazy singleton init with SEH frame; alloc 0x14, construct.
void FUN_005e84a0() {
    void* local_c = nullptr;
    uint32_t local_4 = 0xffffffffu;
    void* puStack_8 = &LAB_006b99ab;
    (void)puStack_8;
    local_c = ExceptionList;
    if (DAT_0072925c == 0) {
        ExceptionList = &local_c;
        void* alloc = FUN_00533c78(0x14);
        local_4 = 0;
        if (alloc != nullptr) {
            DAT_0072925c = (uint32_t)(uintptr_t)FUN_005e8450(alloc);
            ExceptionList = local_c;
            return;
        }
        DAT_0072925c = 0;
    }
    ExceptionList = local_c;
    (void)local_4;
}

// 0x5e8510 — observed shape: recursive directory walker returning match count.
int FUN_005e8510(char* param_1, char* param_2, uint32_t param_3, uint32_t param_4) {
    if (param_1 == nullptr) return 0;
    // Non-empty check for param_1 (length-limited compare against "").
    {
        int i = 1;
        bool eq = true;
        const char* a = param_1;
        const char* b = "";
        do {
            if (i == 0) break;
            i--;
            eq = (*a == *b);
            a++; b++;
        } while (eq);
        if (eq) return 0;
    }
    if (param_2 == nullptr) return 0;
    {
        int i = 1;
        bool eq = true;
        const char* a = param_2;
        const char* b = "";
        do {
            if (i == 0) break;
            i--;
            eq = (*a == *b);
            a++; b++;
        } while (eq);
        if (eq) return 0;
    }
    int matchCount = 0;
    char dirPath[260];          // local_348
    char fullPath[260];         // local_44c
    char pattern[259 + 1];      // local_243 (+ uStack_245)
    std::memset(dirPath, 0, sizeof(dirPath));
    std::strncpy(dirPath, param_1, 0x104);
    // Append '\\' if dirPath doesn't end with '\\' or '/'.
    {
        const char* p = dirPath;
        while (*p) p++;
        if (p == dirPath || (*(p - 1) != '\\' && *(p - 1) != '/')) {
            *p++ = '\\';
            *p = '\0';
        }
    }
    FUN_00497420(dirPath);
    _WIN32_FIND_DATAA fd;
    std::memset(&fd, 0, sizeof(fd));
    // Copy param_1 into pattern buffer.
    std::strcpy(pattern, param_1);
    {
        char* p = pattern;
        while (*p) p++;
        if (p == pattern || (*(p - 1) != '\\' && *(p - 1) != '/')) {
            *p++ = '\\';
            *p = '\0';
        }
    }
    {
        char* p = pattern;
        while (*p) p++;
        *p++ = '*';
        *p = '\0';
    }
    FUN_00497420(pattern);
    HANDLE hFind = ::FindFirstFileA(pattern, &fd);
    if (hFind == INVALID_HANDLE_VALUE) {
        return matchCount;
    }
    do {
        // fullPath = dirPath + fd.cFileName
        std::strcpy(fullPath, dirPath);
        std::strcat(fullPath, fd.cFileName);
        FUN_00497420(fullPath);
        DWORD attrs = ::GetFileAttributesA(fullPath);
        if ((attrs & 0x10) == 0) {
            // Regular file.
            char hit = FUN_005e8380(fullPath, param_2, param_4);
            if (hit != '\0') matchCount++;
        } else {
            // Directory: skip "." and "..".
            bool isDot = (std::strcmp(fd.cFileName, ".") == 0);
            bool isDotDot = (std::strcmp(fd.cFileName, "..") == 0);
            if (!isDot && !isDotDot && ((char)param_3 != '\0')) {
                // fullPath with trailing '\\' for recursion.
                std::strcat(fullPath, "\\");
                FUN_005c9a50("    Recurse directory %s\n", fullPath);
                int sub = FUN_005e8510(fullPath, param_2, param_3, param_4);
                matchCount += sub;
            }
        }
    } while (::FindNextFileA(hFind, &fd) != 0);
    ::FindClose(hFind);
    return matchCount;
}

// 0x5e8830 — observed shape: enumerate param_2 dir with filter string at 0x6c9a9c, then probe param_1.
bool FUN_005e8830(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    FUN_005e8510((char*)param_2, (char*)&DAT_006c9a9c, param_3, (uint32_t)(uintptr_t)self + 4);
    char ok = FUN_005e8220(param_1);
    return ok != '\0';
}

// 0x5e8870 — observed shape: global setter.
void FUN_005e8870(uint32_t param_1) {
    DAT_00729260 = param_1;
}

// 0x5e8880 — observed shape: resolve interface via 0x6b5090, alloc 0x5c, construct, vtbl[6] init.
int* FUN_005e8880(uint32_t param_1, int** param_2) {
    void* local_c = nullptr;
    uint32_t local_4 = 0xffffffffu;
    void* puStack_8 = &LAB_006b99cb;
    (void)puStack_8;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    int local_14 = 0;
    char ok = FUN_006b5090(param_1, &local_14);
    if (ok == '\0') {
        ExceptionList = local_c;
        return nullptr;
    }
    if (local_14 == 0) {
        *param_2 = nullptr;
        ExceptionList = local_c;
        return nullptr;
    }
    void* local_10 = FUN_00533c78(0x5c);
    local_4 = 0;
    int* obj = nullptr;
    if (local_10 != nullptr) {
        obj = FUN_005ebdf0();
    }
    *param_2 = obj;
    local_4 = 0xffffffffu;
    // (**(code**)(*obj + 0x18))(param_1) — vtbl[6] thiscall.
    void** vtbl = *(void***)obj;
    using InitFn = char(__thiscall*)(void*, uint32_t);
    char initOk = ((InitFn)vtbl[6])(obj, param_1);
    if (initOk != '\0') {
        ExceptionList = local_10;
        return obj;
    }
    if (*param_2 != nullptr) {
        // (*(code*)**obj)(1) — vtbl[0] release thiscall(1).
        void** v2 = *(void***)obj;
        using ReleaseFn = void(__thiscall*)(void*, int);
        ((ReleaseFn)v2[0])(obj, 1);
    }
    *param_2 = nullptr;
    ExceptionList = local_10;
    return nullptr;
}

// 0x5e8960 — observed shape: resolve interface, alloc 0x14, construct, init, cleanup on fail.
int* FUN_005e8960(uint32_t param_1, uint32_t** param_2) {
    void* local_c = nullptr;
    uint32_t local_4 = 0xffffffffu;
    void* puStack_8 = &LAB_006b99cb;
    (void)puStack_8;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    int local_14 = 0;
    char ok = FUN_006b5090(param_1, &local_14);
    if (ok == '\0') {
        ExceptionList = local_c;
        return nullptr;
    }
    if (local_14 == 0) {
        ExceptionList = local_c;
        return nullptr;
    }
    void* alloc = FUN_00533c78(0x14);
    local_4 = 0;
    uint32_t* obj = nullptr;
    if (alloc != nullptr) {
        obj = (uint32_t*)FUN_005ea550();
    }
    local_4 = 0xffffffffu;
    *param_2 = obj;
    char initOk = FUN_005ea450(param_1);
    if (initOk != '\0') {
        ExceptionList = local_c;
        return obj;
    }
    void* victim = *param_2;
    if (victim != nullptr) {
        FUN_005ea3c0();
        operator_delete(victim);
    }
    *param_2 = nullptr;
    ExceptionList = local_c;
    return nullptr;
}

// 0x5e8a40 — observed shape: warn on non-empty class name, always returns 0.
uint32_t FUN_005e8a40(const char* param_1) {
    if (param_1 != nullptr) {
        // Non-empty check: length-limited compare against "".
        int i = 1;
        bool eq = true;
        const char* a = param_1;
        const char* b = "";
        do {
            if (i == 0) break;
            i--;
            eq = (*a == *b);
            a++; b++;
        } while (eq);
        if (!eq) {
            FUN_00497420("NSBShader::DefaultCreateNiBinaryShader called for class name %s\n   Did you intend to have a callback set for this???\n", param_1);
        }
    }
    return 0;
}

// 0x5e8a70 — observed shape: build-id filter; returns 0/1/2 mask-class.
uint32_t FUN_005e8a70(uint32_t param_1, uint32_t* param_2) {
    if (param_1 == 0) {
        return 0;
    }
    FUN_005ec420();
    param_1 = FUN_005ece60();
    if (param_1 == 0) {
        param_1 = 0xffff0000u;
    }
    uint32_t uVar1 = FUN_005d5fd0();
    if (uVar1 == 0) {
        uVar1 = 0xfffe0000u;
    }
    uint32_t uVar2 = FUN_005dbd60();
    if (uVar2 == 0) {
        uVar2 = 0xfffe0000u;
    }
    int mode = FUN_005dbd70();
    if (mode != 0) {
        uint32_t bits = (uint32_t)FUN_005dbd70();
        if ((param_2[9] & bits) == 0) {
            return 0;
        }
    }
    if (((param_2[0] < param_1) || (param_2[3] < uVar1)) || (param_1 < param_2[1]) ||
        ((uVar1 < param_2[4] || (param_2[6] < uVar2))) || (uVar2 < param_2[7])) {
        return 0;
    }
    if ((param_1 == param_2[2]) && (uVar1 == param_2[5]) && (uVar2 == param_2[8])) {
        return 2;
    }
    return 1;
}

// 0x5e8b30 — observed shape: vtable store (single dwords).
void FUN_005e8b30(void* self) {
    *(void**)self = PTR_LAB_006c9b24;
}

// 0x5e8b60 — observed shape: vtable store + base dtor + indexed free.
void FUN_005e8b60(void* self) {
    uint32_t* obj = (uint32_t*)self;
    *(void**)obj = PTR_FUN_006c9b30;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)obj[2]);
}

// 0x5e8b80 — observed shape: chain destructure with vtable stores.
void FUN_005e8b80(void* self) {
    uint32_t* obj = (uint32_t*)self;
    void* local_c = nullptr;
    void* puStack_8 = &LAB_006b99e8;
    (void)puStack_8;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    *(void**)obj = PTR_FUN_006c9b4c;
    uint32_t local_4 = 0;
    FUN_005e1490();
    local_4 = 0xffffffffu;
    *(void**)obj = PTR_FUN_006c9b30;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)obj[2]);
    ExceptionList = local_c;
    (void)local_4;
}

// 0x5e8bf0 — observed shape: 2-D node sweep then chain destructure.
void FUN_005e8bf0(void* self) {
    uint32_t* obj = (uint32_t*)self;
    void* local_c = nullptr;
    uint32_t local_4 = 0xffffffffu;
    void* puStack_8 = &LAB_006b99e8;
    (void)puStack_8;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    *(void**)obj = PTR_FUN_006c9b68;
    // Sweep obj[2] rows x obj[1]; flag at obj+4 (byte).
    if ((*(char*)(obj + 4) != '\0') && (obj[1] != 0)) {
        uint32_t row = 0;
        do {
            uint32_t* node = *(uint32_t**)(obj[2] + row * 4);
            while (node != nullptr) {
                uint32_t* next = node + 1;
                node = (uint32_t*)*node;
                operator_delete__((void*)(uintptr_t)*next);
            }
            row++;
        } while (row < obj[1]);
    }
    *(void**)obj = PTR_FUN_006c9b4c;
    local_4 = 0;
    FUN_005e1490();
    local_4 = 0xffffffffu;
    *(void**)obj = PTR_FUN_006c9b30;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)obj[2]);
    ExceptionList = local_c;
    (void)local_4;
}

// 0x5e8ca0 — observed shape: vtable store + indexed free.
void FUN_005e8ca0(void* self) {
    uint32_t* obj = (uint32_t*)self;
    *(void**)obj = PTR_FUN_006c9b20;
    operator_delete__((void*)(uintptr_t)obj[1]);
}

// 0x5e8cc0 — observed shape: deleting-destructor, frees payload at 8 then self if flag&1.
void FUN_005e8cc0(void* self, uint8_t param_1) {
    uint32_t* obj = (uint32_t*)self;
    *(void**)obj = PTR_FUN_006c9b30;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)obj[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e8d00 — observed shape: deleting-destructor wrapper over 0x5e8b80.
void FUN_005e8d00(void* self, uint8_t param_1) {
    FUN_005e8b80(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e8d20 — observed shape: deleting-destructor wrapper over 0x5e8bf0.
void FUN_005e8d20(void* self, uint8_t param_1) {
    FUN_005e8bf0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e8d40 — observed shape: deleting-destructor: vtable store, indexed free, self free if flag&1.
void FUN_005e8d40(void* self, uint8_t param_1) {
    uint32_t* obj = (uint32_t*)self;
    *(void**)obj = PTR_FUN_006c9b20;
    operator_delete__((void*)(uintptr_t)obj[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e8d70 — observed shape: 2-D node sweep then chain destructure (identical body to 0x5e8bf0).
void FUN_005e8d70(void* self) {
    uint32_t* obj = (uint32_t*)self;
    void* pvStack_c = nullptr;
    uint32_t uStack_4 = 0xffffffffu;
    void* puStack_8 = &LAB_006b99e8;
    (void)puStack_8;
    pvStack_c = ExceptionList;
    ExceptionList = &pvStack_c;
    *(void**)obj = PTR_FUN_006c9b68;
    if ((*(char*)(obj + 4) != '\0') && (obj[1] != 0)) {
        uint32_t row = 0;
        do {
            uint32_t* node = *(uint32_t**)(obj[2] + row * 4);
            while (node != nullptr) {
                uint32_t* next = node + 1;
                node = (uint32_t*)*node;
                operator_delete__((void*)(uintptr_t)*next);
            }
            row++;
        } while (row < obj[1]);
    }
    *(void**)obj = PTR_FUN_006c9b4c;
    uStack_4 = 0;
    FUN_005e1490();
    uStack_4 = 0xffffffffu;
    *(void**)obj = PTR_FUN_006c9b30;
    FUN_005e1490();
    operator_delete__((void*)(uintptr_t)obj[2]);
    ExceptionList = pvStack_c;
    (void)uStack_4;
}

// 0x5e8d80 — observed shape: outer/inner sweep over 0x5dc0e0/0x5ec780/0x5ed430; kind check 0x10000000; vtbl[1] dispatch.
uint8_t FUN_005e8d80() {
    uint8_t result = 1;
    uint32_t outer = FUN_005dc0e0();
    uint32_t oi = 0;
    if (outer == 0) {
        return 1;
    }
    do {
        int o = FUN_005ec780(oi, 0);
        if (o != 0) {
            uint32_t inner = FUN_005ed430();
            uint32_t ii = 0;
            if (inner != 0) {
                do {
                    int item = FUN_005ed440(ii, 0);
                    if ((item != 0) && ((*(uint32_t*)(item + 0x58) & 0xf0000000u) == 0x10000000u)) {
                        int* holder = (int*)FUN_005e5b50(*(uint32_t*)(item + 0x5c));
                        if (holder == nullptr) {
                            result = 0;
                        } else {
                            uint8_t buf[64];          // local_40
                            void* p = buf;
                            FUN_006b3d40(&p);
                            uint32_t packed = FUN_005dbe20(0x40, buf);
                            void** vtbl = *(void***)holder;
                            using Fn = uint32_t(__thiscall*)(void*, uint32_t);
                            uint32_t v = ((Fn)vtbl[1])(holder, packed);
                            FUN_005be160(v);
                        }
                    }
                    ii++;
                } while (ii < inner);
            }
        }
        oi++;
    } while (oi < outer);
    return result;
}

// 0x5e8e80 — observed shape: outer/inner sweep as above; no pack buffer; vtbl[1]() dispatch.
uint8_t FUN_005e8e80() {
    uint8_t result = 1;
    uint32_t outer = FUN_005dc0e0();
    uint32_t oi = 0;
    if (outer != 0) {
        do {
            int o = FUN_005ec780(oi, 0);
            if (o != 0) {
                uint32_t inner = FUN_005ed430();
                uint32_t ii = 0;
                if (inner != 0) {
                    do {
                        int item = FUN_005ed440(ii, 0);
                        if ((item != 0) && ((*(uint32_t*)(item + 0x58) & 0xf0000000u) == 0x10000000u)) {
                            int* holder = (int*)FUN_005e5b50(*(uint32_t*)(item + 0x5c));
                            if (holder == nullptr) {
                                result = 0;
                            } else {
                                void** vtbl = *(void***)holder;
                                using Fn = uint32_t(__thiscall*)(void*);
                                uint32_t v = ((Fn)vtbl[1])(holder);
                                FUN_005be1e0(v);
                            }
                        }
                        ii++;
                    } while (ii < inner);
                }
            }
            oi++;
        } while (oi < outer);
    }
    return result;
}
