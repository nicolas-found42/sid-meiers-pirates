#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Reconstruction batch mass_0351 — Sid Meier's Pirates! (2004), PE32 i386.
// Provider: Ghidra 12.2 pseudocode, one listing per function. Register
// receivers (`in_ECX`) are modelled as an explicit `self` parameter.
// ---------------------------------------------------------------------------

// --- CRT / x87 helpers referenced by the listings --------------------------
extern "C" char*  strchr(const char* text, int ch);
extern "C" char*  strtok(char* text, const char* delim);
extern "C" int    atoi(const char* text);
extern "C" int    isdigit(int ch);
extern "C" int    _stricmp(const char* lhs, const char* rhs);
extern "C" double fsin(double value);
extern "C" double fcos(double value);
extern "C" double fptan(double value);

// --- allocator and deleting-destructor thunks ------------------------------
extern "C" void* thunk_FUN_00533c78(int size);
extern "C" void  operator_delete__(void* ptr);
extern           void operator_delete(void* ptr);

// --- globals (addresses taken verbatim from the supplied listings) ---------
extern uint8_t    DAT_007224d0[];                    // 0x7224d0 name/value table
extern int        DAT_00727444;                      // 0x727444 instance counter
extern const char PTR_s_NDL_UpdateTime_007187c8[];   // 0x7187c8 "NDL_UpdateTime"
extern float      DAT_00728f60[16];                  // 0x728f60..0x728f9c operand matrix
extern float      DAT_00728fa0[16];                  // 0x728fa0..0x728fdc operand matrix
extern float      DAT_00728fe0[4];                   // 0x728fe0..0x728fec result vector
extern float      DAT_00728ff0[4];                   // 0x728ff0..0x728ffc scale vector
extern float      DAT_00729000[16];                  // 0x729000 scratch matrix
extern float      DAT_00729040[4];                   // 0x729040 scratch vector
extern int        DAT_00729060[256];                 // 0x729060 low-byte lookup table
extern uint8_t    DAT_00729098;                      // 0x729098 lazy-init flag
extern uint8_t    PTR_LAB_006fd148;                  // 0x6fd148 base vtable
extern uint8_t    PTR_FUN_006f53f8;                  // 0x6f53f8 vtable
extern uint8_t    PTR_FUN_006f5418;                  // 0x6f5418 vtable

// --- helpers referenced by the listings ------------------------------------
extern char      FUN_006b4f80(int param_1, int param_2);
extern "C" void  FUN_005dffd0();
extern "C" int   FUN_005dfaf0(uint32_t param_1);
extern "C" void  FUN_005477c0(int level, int code, const char* message);
extern "C" int   FUN_00540540(const char* name);
extern "C" void  FUN_005e0120();
extern "C" void  thunk_FUN_005f266e(void* dst, int arg, void* src);
extern "C" void  thunk_FUN_005f2399(void* dst, void* src);
extern "C" void  thunk_FUN_005f1ec2(void* dst, void* a, void* b);
extern "C" void  thunk_FUN_005f2148(void* dst, void* a, void* b);
extern "C" void  FUN_006b8940(int side, int operand, uint32_t param_6);
extern "C" void  FUN_006b8c10(int side, int operand, uint32_t p1, int p2, int p3,
                              int p4, int p5, int p6);

// --- vtable dispatch helpers -----------------------------------------------
static void* vfn(void* object, uintptr_t slot)
{
    void** vtbl = *reinterpret_cast<void***>(object);
    return *reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(vtbl) + slot);
}

typedef int (*vt_read_fn)(void* self, void* dst, int size);
static int vread(void* object, void* dst, int size)
{
    return reinterpret_cast<vt_read_fn>(vfn(object, 8))(object, dst, size);
}

typedef void (*vt_store_fn)(void* self, uintptr_t a, uintptr_t b, int c);
static void vstore(void* object, uintptr_t a, uintptr_t b)
{
    reinterpret_cast<vt_store_fn>(vfn(object, 0x20))(object, a, b, 0);
}

typedef int (*vt_lookup_fn)(void* self, uint32_t index);
static int vlookup(void* object, uint32_t index)
{
    return reinterpret_cast<vt_lookup_fn>(vfn(object, 0x24))(object, index);
}

// 16-dword block copy used by the matrix listings.
static void copy16(void* dst, const void* src)
{
    int* d = reinterpret_cast<int*>(dst);
    const int* s = reinterpret_cast<const int*>(src);
    for (int i = 16; i != 0; --i) {
        *d++ = *s++;
    }
}

// --- forward declarations of the batch's own functions ---------------------
bool         FUN_006b5020(int* stream, char** bufferSlot, int length);
unsigned int FUN_006b5200(char* src, char* dst, int size, int* out);
char         FUN_006b52e0(uint32_t name, int* out, int* mode);
char         FUN_006b5370(int kind, int mode);
unsigned int FUN_006b5400(uint32_t name);
unsigned int FUN_006b55c0(int* param_1, uint32_t param_2, int param_3,
                          uint32_t param_4, char param_5, char param_6);
unsigned int FUN_006b5910(int* param_1, uint32_t param_2, int param_3,
                          int param_4, char param_5, char param_6);
unsigned int FUN_006b5b60(int* param_1, uint32_t param_2, uint32_t param_3,
                          uint32_t param_4);
unsigned int FUN_006b5d80(int* param_1, uint32_t param_2, uint32_t param_3,
                          uint32_t param_4);
unsigned int FUN_006b5fa0(void* self, int* param_1, int param_2,
                          uint32_t param_3, int param_4, int param_5,
                          uint32_t param_6, int param_7);
unsigned int FUN_006b6a00(void* self, int param_1, int param_2,
                          uint32_t param_3, int param_4, int param_5, ...);
unsigned int FUN_006b7220(void* self, uint32_t param_1, int param_2,
                          uint32_t param_3, uint32_t param_4,
                          uint32_t param_5, uint32_t param_6);

// 0x6b5020 — observed shape
// NEEDS_MANUAL: the payload length arrives in EDI and the destination pointer
// slot is the caller's second stack argument, so both are modelled
// explicitly. The listing compares the transfer result against the local
// destination address where the intended comparison is the read count
// against the requested length.
bool FUN_006b5020(int* stream, char** bufferSlot, int length)
{
    int scratch = 0;
    if (vread(stream, &scratch, 4) != 4) {
        return false;
    }
    if (length != 0) {
        operator_delete__(*bufferSlot);
        char* buffer = reinterpret_cast<char*>(thunk_FUN_00533c78(length + 1));
        *bufferSlot = buffer;
        int got = vread(stream, buffer, length);
        buffer[length] = 0;
        if (got != length) {
            return false;
        }
    }
    return true;
}

// 0x6b50b0 — observed shape
// Reads `param_3` dwords and reports whether the transfer was complete.
bool FUN_006b50b0(int* param_1, void* param_2, int param_3)
{
    int transferred = vread(param_1, param_2, param_3 * 4);
    return transferred == param_3 * 4;
}

// 0x6b50d0 — observed shape
// Two-stage base/derived constructor: installs the base vtable, bumps the
// instance counter, then installs the derived vtable and clears +8 and +0xc.
void FUN_006b50d0(void* self)
{
    uintptr_t* object = reinterpret_cast<uintptr_t*>(self);
    object[0] = reinterpret_cast<uintptr_t>(&PTR_LAB_006fd148);
    object[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    object[0] = reinterpret_cast<uintptr_t>(&PTR_FUN_006f53f8);
    object[2] = 0;
    object[3] = 0;
}

// 0x6b50f0 — observed shape
// Releasing destructor: reinstalls the derived vtable, deletes the two owned
// pointers at +8 and +0xc, restores the base vtable and drops the counter.
void FUN_006b50f0(void* self)
{
    uintptr_t* object = reinterpret_cast<uintptr_t*>(self);
    object[0] = reinterpret_cast<uintptr_t>(&PTR_FUN_006f53f8);
    operator_delete__(reinterpret_cast<void*>(object[2]));
    operator_delete__(reinterpret_cast<void*>(object[3]));
    object[0] = reinterpret_cast<uintptr_t>(&PTR_LAB_006fd148);
    DAT_00727444 = DAT_00727444 - 1;
}

// 0x6b5130 — observed shape
// Compares the key against the values held at +8 and +0xc, short-circuiting
// on the first mismatch.
bool FUN_006b5130(void* self, int param_1)
{
    int* object = reinterpret_cast<int*>(self);
    char matched = FUN_006b4f80(param_1, object[2]);
    if (matched == '\0') {
        return false;
    }
    return FUN_006b4f80(param_1, object[3]) != '\0';
}

// 0x6b5170 — observed shape
// NEEDS_MANUAL: the length forwarded to FUN_006b5020 arrives in EDI and is
// modelled as an explicit trailing parameter. Each member at +8 and +0xc is
// passed by address so FUN_006b5020 can reallocate it in place.
bool FUN_006b5170(void* self, int stream, int length)
{
    char* base = reinterpret_cast<char*>(self);
    if (!FUN_006b5020(reinterpret_cast<int*>(stream),
                      reinterpret_cast<char**>(base + 8), length)) {
        return false;
    }
    return FUN_006b5020(reinterpret_cast<int*>(stream),
                        reinterpret_cast<char**>(base + 0xc), length);
}

// 0x6b51b0 — observed shape
// Deleting destructor: derived vtable, release both owned pointers, base
// vtable, drop the counter, then conditionally free the object itself.
void FUN_006b51b0(void* self, uint8_t param_1)
{
    uintptr_t* object = reinterpret_cast<uintptr_t*>(self);
    object[0] = reinterpret_cast<uintptr_t>(&PTR_FUN_006f53f8);
    operator_delete__(reinterpret_cast<void*>(object[2]));
    operator_delete__(reinterpret_cast<void*>(object[3]));
    object[0] = reinterpret_cast<uintptr_t>(&PTR_LAB_006fd148);
    DAT_00727444 = DAT_00727444 - 1;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x6b5200 — observed shape
// `src` is copied into a 260-byte scratch, then written back at `dst` (the
// provider renders the second argument as an int and rebases with pointer
// subtraction). If the scratch ends in "_<digit>" the trailing token is
// parsed with atoi into `out` and the head of the token list is written to
// `dst` as well.
unsigned int FUN_006b5200(char* src, char* dst, int size, int* out)
{
    char local_104[260];

    if (static_cast<unsigned int>(size) + 1U < 0x104) {
        return 0;
    }
    {
        char* scan = src;
        char ch;
        do {
            ch = *scan;
            local_104[scan - src] = ch;
            ++scan;
        } while (ch != '\0');
    }
    {
        intptr_t delta = reinterpret_cast<intptr_t>(dst) - reinterpret_cast<intptr_t>(src);
        char ch;
        do {
            ch = *src;
            src[delta] = ch;
            ++src;
        } while (ch != '\0');
    }
    {
        char* underscore = strchr(local_104, 0x5f);
        if (underscore != nullptr) {
            int digit = isdigit(static_cast<unsigned char>(underscore[1]));
            if ((digit != 0) && (underscore[2] == '\0')) {
                char* head = strtok(local_104, "_");
                char* tail = strtok(nullptr, "_");
                if (tail != nullptr) {
                    int value = atoi(tail);
                    *out = value;
                    intptr_t delta = reinterpret_cast<intptr_t>(dst) -
                                     reinterpret_cast<intptr_t>(head);
                    char ch;
                    do {
                        ch = *head;
                        head[delta] = ch;
                        ++head;
                    } while (ch != '\0');
                }
            }
        }
    }
    return 1;
}

// 0x6b52e0 — observed shape
// Converts the name, then scans the 0x7224d0 table of {value, name} pairs
// (2 dwords per entry, 0x1b8 bytes total) with a case-insensitive compare.
char FUN_006b52e0(uint32_t param_1, int* param_2, int* param_3)
{
    char local_104[260];

    if (FUN_006b5200(reinterpret_cast<char*>(param_1), local_104, 0x104, param_3) == 0) {
        return 0;
    }
    {
        uint32_t* entry = reinterpret_cast<uint32_t*>(DAT_007224d0);
        uint32_t offset = 0;
        do {
            if (_stricmp(local_104, reinterpret_cast<char*>(entry[1])) == 0) {
                *param_2 = static_cast<int>(entry[0]);
                return 1;
            }
            offset = offset + 8;
            entry = entry + 2;
        } while (offset < 0x1b8);
    }
    return 0;
}

// 0x6b5370 — observed shape
// Maps an entry kind and its mode operand onto a shape code: kinds 1..0x18
// yield 8 or 9 depending on mode 3, 0x19..0x20/0x22/0x24 yield 9, 0x21/0x23
// yield 8, 0x25..0x36 yield 7, everything else 0.
char FUN_006b5370(int param_1, int param_2)
{
    switch (param_1) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
        return static_cast<char>((param_2 != 3) + 8);
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x22:
    case 0x24:
        return 9;
    case 0x21:
    case 0x23:
        return 8;
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        return 7;
    default:
        return 0;
    }
}

// 0x6b5400 — observed shape
// Resolves the name to a {kind, mode} pair and folds it through FUN_006b5370.
unsigned int FUN_006b5400(uint32_t param_1)
{
    int local_8 = 0;
    int local_4 = 0;
    char resolved = FUN_006b52e0(param_1, &local_8, &local_4);
    if ((resolved == '\0') || (local_8 == 0)) {
        return 0;
    }
    return static_cast<unsigned int>(
        static_cast<uint8_t>(FUN_006b5370(local_8, local_4)));
}

// 0x6b5440 — observed shape
// Looks the operand up and hands it to the receiver's store slot (+0x20);
// returns 1 when the lookup failed, 0 after a successful store.
unsigned int FUN_006b5440(int* param_1, uint32_t param_2)
{
    int resolved = FUN_005dfaf0(param_2);
    if (resolved == 0) {
        return 1;
    }
    {
        typedef void (*StoreFn)(void* self, uint32_t a, int b, int c);
        reinterpret_cast<StoreFn>(vfn(param_1, 0x20))(param_1, param_2, resolved, 0);
    }
    return 0;
}

// 0x6b5470 — observed shape
// Deleting destructor: installs its vtable, runs the shared cleanup at
// 0x5dffd0, then conditionally frees the object.
void FUN_006b5470(void* self, uint8_t param_1)
{
    uintptr_t* object = reinterpret_cast<uintptr_t*>(self);
    object[0] = reinterpret_cast<uintptr_t>(&PTR_FUN_006f5418);
    FUN_005dffd0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x6b55c0 — observed shape
// NEEDS_MANUAL: the provider splits the 16-float workspace over several
// overlapping locals (local_40/local_30/.../local_4); they are modelled as one
// array here. The param_6 branch of the param_3==9 / mode 9 case dispatches
// through the pointer held in the last slot (rendered `local_4`) using the
// return-address pseudo-argument as first operand.
unsigned int FUN_006b55c0(int* param_1, uint32_t param_2, int param_3,
                          uint32_t param_4, char param_5, char param_6)
{
    float local_40[16];   // [0..3] local_40, [4] local_30, [5] local_2c,
                          // [6] local_28, [7] local_24, [8] local_20,
                          // [9] local_1c, [10] local_18, [11] local_14,
                          // [12] local_10, [13] local_c, [14] local_8,
                          // [15] local_4

    if (param_3 != 7) {
        if (param_3 == 9) {
            switch (param_4) {
            case 3:
            case 4:
                local_40[0] = DAT_00728f60[0] * DAT_00728ff0[0];
                local_40[1] = DAT_00728f60[1] * DAT_00728ff0[0];
                local_40[2] = DAT_00728f60[2] * DAT_00728ff0[0];
                local_40[3] = DAT_00728f60[3] * DAT_00728ff0[0];
                local_40[4] = DAT_00728f60[4] * DAT_00728ff0[0];
                local_40[5] = DAT_00728f60[5] * DAT_00728ff0[0];
                local_40[6] = DAT_00728f60[6] * DAT_00728ff0[0];
                local_40[7] = DAT_00728f60[7] * DAT_00728ff0[0];
                local_40[8] = DAT_00728f60[8] * DAT_00728ff0[0];
                local_40[9] = DAT_00728f60[9] * DAT_00728ff0[0];
                local_40[10] = DAT_00728f60[10] * DAT_00728ff0[0];
                local_40[11] = DAT_00728f60[11] * DAT_00728ff0[0];
                local_40[12] = DAT_00728f60[12] * DAT_00728ff0[0];
                local_40[13] = DAT_00728f60[13] * DAT_00728ff0[0];
                local_40[14] = DAT_00728f60[14] * DAT_00728ff0[0];
                local_40[15] = DAT_00728f60[15] * DAT_00728ff0[0];
                copy16(DAT_00729000, local_40);
                if (param_5 != '\0') {
                    thunk_FUN_005f266e(DAT_00729000, 0, DAT_00729000);
                }
                if (param_6 != '\0') {
                    thunk_FUN_005f2399(DAT_00729000, DAT_00729000);
                }
                break;
            default:
                return 1;
            case 7:
            case 10:
                thunk_FUN_005f1ec2(DAT_00729040, DAT_00728ff0, DAT_00728f60);
                goto LAB_006b58b3;
            case 9:
                thunk_FUN_005f2148(DAT_00729000, DAT_00728f60, DAT_00728fa0);
                if (param_5 != '\0') {
                    thunk_FUN_005f266e(DAT_00729000, 0, DAT_00729000);
                }
                if (param_6 != '\0') {
                    thunk_FUN_005f2399(DAT_00729000, DAT_00729000);
                    int* local_4 = reinterpret_cast<int*>(
                        static_cast<intptr_t>(local_40[15] * DAT_00728ff0[0]));
                    typedef void (*StoreFn)(void* self, uint32_t a, uint32_t b, int c);
                    reinterpret_cast<StoreFn>(vfn(local_4, 0x20))(
                        local_4, 0, reinterpret_cast<uintptr_t>(DAT_00729000), 0);
                    return 0;
                }
            }
            vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729000));
            return 0;
        }
        if (param_3 != 10) {
            return 1;
        }
    }
    switch (param_4) {
    case 3:
    case 4:
        DAT_00729040[0] = DAT_00728fe0[0] * DAT_00728ff0[0];
        DAT_00729040[1] = DAT_00728fe0[1] * DAT_00728ff0[0];
        DAT_00729040[2] = DAT_00728fe0[2] * DAT_00728ff0[0];
        DAT_00729040[3] = DAT_00728fe0[3] * DAT_00728ff0[0];
        break;
    default:
        return 1;
    case 7:
    case 10:
        DAT_00729040[0] = DAT_00728fe0[0] * DAT_00728ff0[0];
        DAT_00729040[1] = DAT_00728ff0[1] * DAT_00728fe0[1];
        DAT_00729040[2] = DAT_00728ff0[2] * DAT_00728fe0[2];
        DAT_00729040[3] = DAT_00728ff0[3] * DAT_00728fe0[3];
LAB_006b58b3:
        vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729040));
        return 0;
    case 9:
        thunk_FUN_005f1ec2(DAT_00729040, DAT_00728fe0, DAT_00728fa0);
    }
    vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729040));
    return 0;
}

// 0x6b5910 — observed shape
// Reciprocal/multiply variant of the operand builder: mode 9 scales the
// 0x728f60 matrix by 1/scale, modes 3/4 scale the 0x728fe0 vector by
// 1/scale, modes 7/10 divide component-wise by the 0x728ff0 scale vector.
unsigned int FUN_006b5910(int* param_1, uint32_t param_2, int param_3,
                          int param_4, char param_5, char param_6)
{
    float local_40[16];

    if (param_3 != 7) {
        if (param_3 == 9) {
            if (param_4 < 3) {
                return 1;
            }
            if (param_4 > 4) {
                return 1;
            }
            {
                float scale = 1.0f / DAT_00728ff0[0];
                local_40[0] = DAT_00728f60[0] * scale;
                local_40[1] = DAT_00728f60[1] * scale;
                local_40[2] = DAT_00728f60[2] * scale;
                local_40[3] = DAT_00728f60[3] * scale;
                local_40[4] = DAT_00728f60[4] * scale;
                local_40[5] = DAT_00728f60[5] * scale;
                local_40[6] = DAT_00728f60[6] * scale;
                local_40[7] = DAT_00728f60[7] * scale;
                local_40[8] = DAT_00728f60[8] * scale;
                local_40[9] = DAT_00728f60[9] * scale;
                local_40[10] = DAT_00728f60[10] * scale;
                local_40[11] = DAT_00728f60[11] * scale;
                local_40[12] = DAT_00728f60[12] * scale;
                local_40[13] = DAT_00728f60[13] * scale;
                local_40[14] = DAT_00728f60[14] * scale;
                local_40[15] = DAT_00728f60[15] * scale;
            }
            copy16(DAT_00729000, local_40);
            if (param_5 != '\0') {
                thunk_FUN_005f266e(DAT_00729000, 0, DAT_00729000);
            }
            if (param_6 != '\0') {
                thunk_FUN_005f2399(DAT_00729000, DAT_00729000);
            }
            vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729000));
            return 0;
        }
        if (param_3 != 10) {
            return 1;
        }
    }
    switch (param_4) {
    case 3:
    case 4:
        DAT_00729040[3] = 1.0f / DAT_00728ff0[0];
        DAT_00729040[0] = DAT_00728fe0[0] * DAT_00729040[3];
        DAT_00729040[1] = DAT_00728fe0[1] * DAT_00729040[3];
        DAT_00729040[2] = DAT_00728fe0[2] * DAT_00729040[3];
        DAT_00729040[3] = DAT_00728fe0[3] * DAT_00729040[3];
        break;
    default:
        return 1;
    case 7:
    case 10:
        DAT_00729040[0] = DAT_00728fe0[0] / DAT_00728ff0[0];
        DAT_00729040[1] = DAT_00728fe0[1] / DAT_00728ff0[1];
        DAT_00729040[2] = DAT_00728fe0[2] / DAT_00728ff0[2];
        DAT_00729040[3] = DAT_00728fe0[3] / DAT_00728ff0[3];
    }
    vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729040));
    return 0;
}

// 0x6b5b60 — observed shape
// Builds a 4-float vector from the 0x728fe0 result and the 0x728ff0 scale
// vector; modes 3/4 take the scalar scale slot, modes 7/10 the per-component
// scale. The kind switch accepts only 3/4 or 7/10 and returns 1 otherwise.
unsigned int FUN_006b5b60(int* param_1, uint32_t param_2, uint32_t param_3,
                          uint32_t param_4)
{
    switch (param_3) {
    case 3:
    case 4:
        break;
    default:
        return 1;
    case 7:
    case 10:
        switch (param_4) {
        case 3:
        case 4:
            DAT_00729040[3] = DAT_00728ff0[0];
            DAT_00729040[1] = DAT_00728ff0[0];
            DAT_00729040[2] = DAT_00728ff0[0];
            break;
        default:
            return 1;
        case 7:
        case 10:
            DAT_00729040[3] = DAT_00728ff0[3];
            DAT_00729040[1] = DAT_00728ff0[1];
            DAT_00729040[2] = DAT_00728ff0[2];
        }
        DAT_00729040[2] = DAT_00728fe0[2] + DAT_00729040[2];
        DAT_00729040[1] = DAT_00728fe0[1] + DAT_00729040[1];
        DAT_00729040[3] = DAT_00728fe0[3] + DAT_00729040[3];
        DAT_00729040[0] = DAT_00728fe0[0] + DAT_00728ff0[0];
        vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729040));
        return 0;
    }
    switch (param_4) {
    case 3:
    case 4:
        DAT_00729040[1] = DAT_00728fe0[1];
        DAT_00729040[2] = DAT_00728fe0[2];
        DAT_00729040[3] = DAT_00728fe0[3];
        break;
    default:
        return 1;
    case 7:
    case 10:
        DAT_00729040[1] = DAT_00728fe0[0];
        DAT_00729040[2] = DAT_00728fe0[0];
        DAT_00729040[3] = DAT_00728fe0[0];
    }
    DAT_00729040[3] = DAT_00728ff0[3] + DAT_00729040[3];
    DAT_00729040[2] = DAT_00728ff0[2] + DAT_00729040[2];
    DAT_00729040[1] = DAT_00728ff0[1] + DAT_00729040[1];
    DAT_00729040[0] = DAT_00728fe0[0] + DAT_00728ff0[0];
    vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729040));
    return 0;
}

// 0x6b5d80 — observed shape
// Subtraction counterpart of FUN_006b5b60: the scale vector is subtracted
// from the 0x728fe0 result with the same kind/mode acceptance.
unsigned int FUN_006b5d80(int* param_1, uint32_t param_2, uint32_t param_3,
                          uint32_t param_4)
{
    switch (param_3) {
    case 3:
    case 4:
        break;
    default:
        return 1;
    case 7:
    case 10:
        switch (param_4) {
        case 3:
        case 4:
            DAT_00729040[3] = DAT_00728ff0[0];
            DAT_00729040[1] = DAT_00728ff0[0];
            DAT_00729040[2] = DAT_00728ff0[0];
            break;
        default:
            return 1;
        case 7:
        case 10:
            DAT_00729040[3] = DAT_00728ff0[3];
            DAT_00729040[1] = DAT_00728ff0[1];
            DAT_00729040[2] = DAT_00728ff0[2];
        }
        DAT_00729040[2] = DAT_00728fe0[2] - DAT_00729040[2];
        DAT_00729040[1] = DAT_00728fe0[1] - DAT_00729040[1];
        DAT_00729040[3] = DAT_00728fe0[3] - DAT_00729040[3];
        DAT_00729040[0] = DAT_00728fe0[0] - DAT_00728ff0[0];
        vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729040));
        return 0;
    }
    switch (param_4) {
    case 3:
    case 4:
        DAT_00729040[1] = DAT_00728fe0[1];
        DAT_00729040[2] = DAT_00728fe0[2];
        DAT_00729040[3] = DAT_00728fe0[3];
        break;
    default:
        return 1;
    case 7:
    case 10:
        DAT_00729040[1] = DAT_00728fe0[0];
        DAT_00729040[2] = DAT_00728fe0[0];
        DAT_00729040[3] = DAT_00728fe0[0];
    }
    DAT_00729040[3] = DAT_00729040[3] - DAT_00728ff0[3];
    DAT_00729040[2] = DAT_00729040[2] - DAT_00728ff0[2];
    DAT_00729040[1] = DAT_00729040[1] - DAT_00728ff0[1];
    DAT_00729040[0] = DAT_00728fe0[0] - DAT_00728ff0[0];
    vstore(param_1, param_2, reinterpret_cast<uintptr_t>(DAT_00729040));
    return 0;
}

// 0x6b5fa0 — observed shape
// NEEDS_MANUAL: the provider splits the 16-float workspaces into overlapping
// locals (afStack_90/auStack_5c/afStack_50 and the fStack_1a0 quad); they are
// modelled as separate scratch arrays here, and the alias-based second
// multiply of the 0x1d..0x20 case is kept as the observed call against the
// a5c scratch. param_3 and param_6 are present but unused in the listing.
unsigned int FUN_006b5fa0(void* self, int* param_1, int param_2,
                          uint32_t param_3, int param_4, int param_5,
                          uint32_t param_6, int param_7)
{
    float a190[16];   // afStack_190
    float a150[16];   // afStack_150
    float a110[16];   // afStack_110
    float ad0[16];    // afStack_d0
    float a90[16];    // afStack_90
    float a5c[16];    // auStack_5c
    float a50[16];    // afStack_50
    float quad[4];    // fStack_1a0, fStack_19c, fStack_198, fStack_194
    bool bVar1;
    bool bVar2;
    float* pfVar3;
    float* pfVar6;
    int iVar4;
    int iVar5;
    int matrixBase = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x34);

    iVar5 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_2) + 0xc);
    switch (iVar5) {
    case 1:
    case 2:
    case 0xd:
    case 0xe:
        bVar1 = false;
        bVar2 = false;
        if ((iVar5 == 2) || (iVar5 == 0xe)) {
            bVar1 = true;
        }
        if ((iVar5 == 0xd) || (iVar5 == 0xe)) {
            bVar2 = true;
        }
        copy16(a190, reinterpret_cast<void*>(matrixBase + 0x800));
        if (bVar1) {
            thunk_FUN_005f266e(a190, 0, a190);
        }
        if (bVar2) {
            thunk_FUN_005f2399(a190, a190);
        }
        vstore(param_1, param_2, reinterpret_cast<uintptr_t>(a190));
        return 0;
    case 3:
    case 4:
    case 0xf:
    case 0x10:
        bVar1 = false;
        bVar2 = false;
        if ((iVar5 == 4) || (iVar5 == 0x10)) {
            bVar1 = true;
        }
        if ((iVar5 == 0xf) || (iVar5 == 0x10)) {
            bVar2 = true;
        }
        copy16(a190, reinterpret_cast<void*>(matrixBase + 0x7c0));
        if (bVar1) {
            thunk_FUN_005f266e(a190, 0, a190);
        }
        if (bVar2) {
            goto LAB_006b6229;
        }
        goto LAB_006b622e;
    case 5:
    case 6:
    case 0x11:
    case 0x12:
        bVar1 = false;
        bVar2 = false;
        if ((iVar5 == 6) || (iVar5 == 0x12)) {
            bVar1 = true;
        }
        if ((iVar5 == 0x11) || (iVar5 == 0x12)) {
            bVar2 = true;
        }
        copy16(a190, reinterpret_cast<void*>(matrixBase + 0x780));
        goto LAB_006b6206;
    case 7:
    case 8:
    case 0x13:
    case 0x14:
        bVar1 = false;
        bVar2 = false;
        if ((iVar5 == 8) || (iVar5 == 0x14)) {
            bVar1 = true;
        }
        if ((iVar5 == 0x13) || (iVar5 == 0x14)) {
            bVar2 = true;
        }
        {
            int matrix = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x34);
            copy16(a90, reinterpret_cast<void*>(matrix + 0x780));
            copy16(a150, reinterpret_cast<void*>(matrix + 0x7c0));
        }
        thunk_FUN_005f2148(a110, a90, a150);
        copy16(a190, a110);
        if (bVar1) {
            thunk_FUN_005f266e(a190, 0, a190);
        }
        goto LAB_006b621d;
    case 9:
    case 10:
    case 0x15:
    case 0x16:
        bVar1 = false;
        bVar2 = false;
        if ((iVar5 == 10) || (iVar5 == 0x16)) {
            bVar1 = true;
        }
        if ((iVar5 == 0x15) || (iVar5 == 0x16)) {
            bVar2 = true;
        }
        {
            int matrix = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x34);
            copy16(a90, reinterpret_cast<void*>(matrix + 0x7c0));
            copy16(a110, reinterpret_cast<void*>(matrix + 0x800));
        }
        pfVar3 = a110;
        pfVar6 = a90;
        goto LAB_006b61e7;
    case 0xb:
    case 0xc:
    case 0x17:
    case 0x18:
        bVar1 = false;
        bVar2 = false;
        if ((iVar5 == 0xc) || (iVar5 == 0x18)) {
            bVar1 = true;
        }
        if ((iVar5 == 0x17) || (iVar5 == 0x18)) {
            bVar2 = true;
        }
        {
            int matrix = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x34);
            copy16(a90, reinterpret_cast<void*>(matrix + 0x780));
            copy16(a110, reinterpret_cast<void*>(matrix + 0x7c0));
            copy16(a50, reinterpret_cast<void*>(matrix + 0x800));
        }
        thunk_FUN_005f2148(a150, a90, a110);
        copy16(ad0, a150);
        pfVar3 = a50;
        pfVar6 = ad0;
LAB_006b61e7:
        thunk_FUN_005f2148(a150, pfVar6, pfVar3);
        copy16(a190, a150);
        goto LAB_006b6206;
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
        if (param_4 == 0) {
            return 0;
        }
        copy16(a190, *reinterpret_cast<void**>(reinterpret_cast<char*>(param_4) + 0x28));
        bVar1 = false;
        bVar2 = false;
        if ((iVar5 == 0x1a) || (iVar5 == 0x1c)) {
            bVar1 = true;
        }
        if ((iVar5 == 0x1b) || (iVar5 == 0x1c)) {
            bVar2 = true;
        }
        copy16(ad0, reinterpret_cast<void*>(
            *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x34) + 0x7c0));
        thunk_FUN_005f2148(a190, a190, ad0);
        goto LAB_006b6206;
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
        if (param_4 == 0) {
            return 0;
        }
        copy16(a190, *reinterpret_cast<void**>(reinterpret_cast<char*>(param_4) + 0x28));
        bVar1 = false;
        bVar2 = false;
        if ((iVar5 == 0x1e) || (iVar5 == 0x20)) {
            bVar1 = true;
        }
        if ((iVar5 == 0x1f) || (iVar5 == 0x20)) {
            bVar2 = true;
        }
        {
            int matrix = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x34);
            copy16(ad0, reinterpret_cast<void*>(matrix + 0x7c0));
            copy16(a50, reinterpret_cast<void*>(matrix + 0x800));
        }
        thunk_FUN_005f2148(a190, a190, ad0);
        thunk_FUN_005f2148(&a190[1], &a190[1], a5c);
        goto LAB_006b6206;
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
        if (param_4 != 0) {
            typedef void (*StoreFn5)(void* self, uint32_t a, uint16_t b,
                                     uint32_t c, uint32_t d);
            reinterpret_cast<StoreFn5>(vfn(param_1, 0x24))(
                param_1,
                *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_4) + 0x20),
                *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(param_5) + 0x20),
                *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_4) + 0x24),
                *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_5) + 4));
            return 0;
        }
        break;
    case 0x29:
        iVar5 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_7) + 0x14);
        if (iVar5 != 0) {
            quad[0] = *reinterpret_cast<float*>(iVar5 + 0x30);
            quad[1] = *reinterpret_cast<float*>(iVar5 + 0x34);
            quad[2] = *reinterpret_cast<float*>(iVar5 + 0x38);
            quad[3] = *reinterpret_cast<float*>(iVar5 + 0x58);
            goto LAB_006b64e3;
        }
        break;
    case 0x2a:
        iVar5 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_7) + 0x14);
        if (iVar5 != 0) {
            quad[0] = *reinterpret_cast<float*>(iVar5 + 0x24);
            quad[1] = *reinterpret_cast<float*>(iVar5 + 0x28);
            quad[2] = *reinterpret_cast<float*>(iVar5 + 0x2c);
            quad[3] = *reinterpret_cast<float*>(iVar5 + 0x58);
            goto LAB_006b64e3;
        }
        break;
    case 0x2b:
        iVar5 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_7) + 0x14);
        if (iVar5 != 0) {
            quad[0] = *reinterpret_cast<float*>(iVar5 + 0x3c);
            quad[1] = *reinterpret_cast<float*>(iVar5 + 0x40);
            quad[2] = *reinterpret_cast<float*>(iVar5 + 0x44);
            quad[3] = *reinterpret_cast<float*>(iVar5 + 0x58);
            goto LAB_006b64e3;
        }
        break;
    case 0x2c:
        iVar5 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_7) + 0x14);
        if (iVar5 != 0) {
            quad[0] = *reinterpret_cast<float*>(iVar5 + 0x48);
            quad[1] = *reinterpret_cast<float*>(iVar5 + 0x4c);
            quad[2] = *reinterpret_cast<float*>(iVar5 + 0x50);
            quad[3] = *reinterpret_cast<float*>(iVar5 + 0x58);
            goto LAB_006b64e3;
        }
        break;
    case 0x2d:
        if (*reinterpret_cast<int*>(reinterpret_cast<char*>(param_7) + 0x14) != 0) {
            quad[2] = *reinterpret_cast<float*>(
                *reinterpret_cast<int*>(reinterpret_cast<char*>(param_7) + 0x14) + 0x54);
            quad[3] = quad[2];
            quad[0] = quad[2];
            quad[1] = quad[2];
            goto LAB_006b64e3;
        }
        break;
    case 0x30:
    case 0x31:
        vstore(param_1, param_2, 0);
        return 0;
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        iVar4 = FUN_00540540(PTR_s_NDL_UpdateTime_007187c8);
        if (iVar4 == 0) {
            return 0x80000010;
        }
        quad[0] = *reinterpret_cast<float*>(iVar4 + 0x10);
        {
            double t = static_cast<double>(quad[0]);
            switch (iVar5) {
            case 0x33:
                t = fsin(t);
                pfVar3 = quad;
                quad[0] = static_cast<float>(t);
                quad[1] = static_cast<float>(t);
                quad[2] = static_cast<float>(t);
                quad[3] = static_cast<float>(t);
                break;
            case 0x34:
                t = fcos(t);
                pfVar3 = quad;
                quad[0] = static_cast<float>(t);
                quad[1] = static_cast<float>(t);
                quad[2] = static_cast<float>(t);
                quad[3] = static_cast<float>(t);
                break;
            case 0x35:
                t = fptan(t);
                /* falls through */
            case 0x32:
                quad[0] = static_cast<float>(t);
                pfVar3 = quad;
                quad[1] = static_cast<float>(t);
                quad[2] = static_cast<float>(t);
                quad[3] = static_cast<float>(t);
                break;
            case 0x36:
                pfVar3 = quad;
                quad[1] = static_cast<float>(fsin(t));
                quad[2] = static_cast<float>(fcos(t));
                quad[3] = static_cast<float>(fptan(t));
                break;
            default:
                return 0x80000010;
            }
        }
        goto LAB_006b6232;
    }
    return 0;

LAB_006b64e3:
    vstore(param_1, param_2, reinterpret_cast<uintptr_t>(quad));
    return 0;

LAB_006b6206:
    if (bVar1) {
        thunk_FUN_005f266e(a190, 0, a190);
    }
LAB_006b621d:
    if (bVar2) {
LAB_006b6229:
        thunk_FUN_005f2399(a190, a190);
    }
LAB_006b622e:
    pfVar3 = a190;
LAB_006b6232:
    vstore(param_1, param_2, reinterpret_cast<uintptr_t>(pfVar3));
    return 0;
}

// 0x6b6a00 — observed shape
// NEEDS_MANUAL: the listing passes two extra stack words that its own
// prototype does not name (modelled with a variadic tail), and the two flag
// bits arrive in EDI (byte aliases cStack_162/cStack_161/cVar10/cVar9 are
// used for the same pair); the flag semantics of FUN_006b5fa0 are applied
// per case group. Overlapping 16-dword provider locals are modelled as one
// scratch array each. Returns 9 for the vector cases, 10 for the 0x29..0x2d
// operand cases, 7 for the trig cases and 0 otherwise.
unsigned int FUN_006b6a00(void* self, int param_1, int param_2, uint32_t param_3,
                          int param_4, int param_5, ...)
{
    float a190[16];   // local_150 / auStack_160 region
    float a150[16];
    float a110[16];   // auStack_11c + 3
    float ad0[16];    // local_d0
    float a90[16];    // local_90
    float a5c[16];    // auStack_5c
    float adc[16];    // auStack_dc
    bool bVar1;
    bool bVar2;
    int iVar2;
    int iVar3;
    int matrixBase = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x34);
    float* slot = &DAT_00728f60[16 * param_1];

    iVar3 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_2) + 0xc);
    switch (iVar3) {
    case 1:
    case 2:
    case 0xd:
    case 0xe:
        bVar1 = false;
        bVar2 = false;
        if ((iVar3 == 2) || (iVar3 == 0xe)) {
            bVar1 = true;
        }
        if ((iVar3 == 0xd) || (iVar3 == 0xe)) {
            bVar2 = true;
        }
        copy16(a190, reinterpret_cast<void*>(matrixBase + 0x800));
        copy16(slot, a190);
        if (bVar1) {
            thunk_FUN_005f266e(slot, 0, slot);
        }
        if (bVar2 == false) {
            return 9;
        }
        thunk_FUN_005f2399(slot, slot);
        return 9;
    case 3:
    case 4:
    case 0xf:
    case 0x10:
        bVar1 = false;
        bVar2 = false;
        if ((iVar3 == 4) || (iVar3 == 0x10)) {
            bVar1 = true;
        }
        if ((iVar3 == 0xf) || (iVar3 == 0x10)) {
            bVar2 = true;
        }
        copy16(a190, reinterpret_cast<void*>(matrixBase + 0x7c0));
        copy16(slot, a190);
        if (bVar1) {
            thunk_FUN_005f266e(slot, 0, slot);
        }
        if (bVar2 == false) {
            return 9;
        }
        thunk_FUN_005f2399(slot, slot);
        return 9;
    case 5:
    case 6:
    case 0x11:
    case 0x12:
        bVar1 = false;
        bVar2 = false;
        if ((iVar3 == 6) || (iVar3 == 0x12)) {
            bVar1 = true;
        }
        if ((iVar3 == 0x11) || (iVar3 == 0x12)) {
            bVar2 = true;
        }
        copy16(slot, reinterpret_cast<void*>(matrixBase + 0x780));
        if (bVar1) {
            thunk_FUN_005f266e(slot, 0, slot);
        }
        if (bVar2 == false) {
            return 9;
        }
        thunk_FUN_005f2399(slot, slot);
        return 9;
    case 7:
    case 8:
    case 0x13:
    case 0x14:
        bVar1 = false;
        bVar2 = false;
        if ((iVar3 == 8) || (iVar3 == 0x14)) {
            bVar1 = true;
        }
        if ((iVar3 == 0x13) || (iVar3 == 0x14)) {
            bVar2 = true;
        }
        copy16(a90, reinterpret_cast<void*>(matrixBase + 0x780));
        copy16(a150, reinterpret_cast<void*>(matrixBase + 0x7c0));
        thunk_FUN_005f2148(a110, a90, a150);
        copy16(slot, a110);
        if (bVar1) {
            thunk_FUN_005f266e(slot, 0, slot);
        }
        if (bVar2 == false) {
            return 9;
        }
        thunk_FUN_005f2399(slot, slot);
        return 9;
    case 9:
    case 10:
    case 0x15:
    case 0x16:
        bVar1 = false;
        bVar2 = false;
        if ((iVar3 == 10) || (iVar3 == 0x16)) {
            bVar1 = true;
        }
        if ((iVar3 == 0x15) || (iVar3 == 0x16)) {
            bVar2 = true;
        }
        copy16(a90, reinterpret_cast<void*>(matrixBase + 0x7c0));
        copy16(a110, reinterpret_cast<void*>(matrixBase + 0x800));
        thunk_FUN_005f2148(a150, a90, a110);
        copy16(slot, a150);
        if (bVar1) {
            thunk_FUN_005f266e(slot, 0, slot);
        }
        if (bVar2 == false) {
            return 9;
        }
        thunk_FUN_005f2399(slot, slot);
        return 9;
    case 0xb:
    case 0xc:
    case 0x17:
    case 0x18:
        bVar1 = false;
        bVar2 = false;
        if ((iVar3 == 0xc) || (iVar3 == 0x18)) {
            bVar1 = true;
        }
        if ((iVar3 == 0x17) || (iVar3 == 0x18)) {
            bVar2 = true;
        }
        copy16(a90, reinterpret_cast<void*>(matrixBase + 0x780));
        copy16(a110, reinterpret_cast<void*>(matrixBase + 0x7c0));
        copy16(ad0, reinterpret_cast<void*>(matrixBase + 0x800));
        thunk_FUN_005f2148(a150, a90, a110);
        copy16(a5c, a150);
        thunk_FUN_005f2148(&a150[1], a5c, adc);
        copy16(slot, a150);
        if (bVar1) {
            thunk_FUN_005f266e(slot, 0, slot);
        }
        if (bVar2) {
            thunk_FUN_005f2399(slot, slot);
        }
        return 9;
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
        if (param_4 != 0) {
            copy16(a5c, *reinterpret_cast<void**>(reinterpret_cast<char*>(param_4) + 0x28));
            copy16(slot, a5c);
            bVar1 = false;
            bVar2 = false;
            if ((iVar3 == 0x1a) || (iVar3 == 0x1c)) {
                bVar1 = true;
            }
            if ((iVar3 == 0x1b) || (iVar3 == 0x1c)) {
                bVar2 = true;
            }
            copy16(ad0, reinterpret_cast<void*>(matrixBase + 0x7c0));
            thunk_FUN_005f2148(slot, slot, ad0);
            if (bVar1) {
                thunk_FUN_005f266e(slot, 0, slot);
            }
            if (bVar2 == false) {
                return 9;
            }
            thunk_FUN_005f2399(slot, slot);
            return 9;
        }
        break;
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
        if (param_4 != 0) {
            copy16(a5c, *reinterpret_cast<void**>(reinterpret_cast<char*>(param_4) + 0x28));
            copy16(slot, a5c);
            bVar1 = false;
            bVar2 = false;
            if ((iVar3 == 0x1e) || (iVar3 == 0x20)) {
                bVar1 = true;
            }
            if ((iVar3 == 0x1f) || (iVar3 == 0x20)) {
                bVar2 = true;
            }
            copy16(ad0, reinterpret_cast<void*>(matrixBase + 0x7c0));
            copy16(a110, reinterpret_cast<void*>(matrixBase + 0x800));
            thunk_FUN_005f2148(slot, slot, ad0);
            thunk_FUN_005f2148(slot, slot, a110);
            if (bVar1) {
                thunk_FUN_005f266e(slot, 0, slot);
            }
            if (bVar2 == false) {
                return 9;
            }
            thunk_FUN_005f2399(slot, slot);
            return 9;
        }
        break;
    case 0x29:
        iVar3 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_5) + 0x14);
        if (iVar3 != 0) {
            float* out = &DAT_00728fe0[4 * param_1];
            out[0] = *reinterpret_cast<float*>(iVar3 + 0x30);
            out[1] = *reinterpret_cast<float*>(iVar3 + 0x34);
            out[2] = *reinterpret_cast<float*>(iVar3 + 0x38);
            out[3] = *reinterpret_cast<float*>(iVar3 + 0x58);
            return 10;
        }
        break;
    case 0x2a:
        iVar3 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_5) + 0x14);
        if (iVar3 != 0) {
            float* out = &DAT_00728fe0[4 * param_1];
            out[0] = *reinterpret_cast<float*>(iVar3 + 0x24);
            out[1] = *reinterpret_cast<float*>(iVar3 + 0x28);
            out[2] = *reinterpret_cast<float*>(iVar3 + 0x2c);
            out[3] = *reinterpret_cast<float*>(iVar3 + 0x58);
            return 10;
        }
        break;
    case 0x2b:
        iVar3 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_5) + 0x14);
        if (iVar3 != 0) {
            float* out = &DAT_00728fe0[4 * param_1];
            out[0] = *reinterpret_cast<float*>(iVar3 + 0x3c);
            out[1] = *reinterpret_cast<float*>(iVar3 + 0x40);
            out[2] = *reinterpret_cast<float*>(iVar3 + 0x44);
            out[3] = *reinterpret_cast<float*>(iVar3 + 0x58);
            return 10;
        }
        break;
    case 0x2c:
        iVar3 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_5) + 0x14);
        if (iVar3 != 0) {
            float* out = &DAT_00728fe0[4 * param_1];
            out[0] = *reinterpret_cast<float*>(iVar3 + 0x48);
            out[1] = *reinterpret_cast<float*>(iVar3 + 0x4c);
            out[2] = *reinterpret_cast<float*>(iVar3 + 0x50);
            out[3] = *reinterpret_cast<float*>(iVar3 + 0x58);
            return 10;
        }
        break;
    case 0x2d:
        iVar3 = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_5) + 0x14);
        if (iVar3 != 0) {
            float* out = &DAT_00728fe0[4 * param_1];
            out[0] = *reinterpret_cast<float*>(iVar3 + 0x54);
            out[1] = *reinterpret_cast<float*>(iVar3 + 0x54);
            out[2] = *reinterpret_cast<float*>(iVar3 + 0x54);
            out[3] = *reinterpret_cast<float*>(iVar3 + 0x54);
            return 10;
        }
        break;
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    {
        iVar2 = FUN_00540540(PTR_s_NDL_UpdateTime_007187c8);
        if (iVar2 == 0) {
            return 0x80000010;
        }
        float t = *reinterpret_cast<float*>(iVar2 + 0x10);
        float* out = &DAT_00728fe0[4 * param_1];
        switch (iVar3) {
        case 0x32:
            break;
        case 0x33:
            t = static_cast<float>(fsin(static_cast<double>(t)));
            break;
        case 0x34:
            t = static_cast<float>(fcos(static_cast<double>(t)));
            break;
        case 0x35:
            t = static_cast<float>(fptan(static_cast<double>(t)));
            break;
        case 0x36:
            out[0] = *reinterpret_cast<float*>(iVar2 + 0x10);
            out[1] = static_cast<float>(fsin(static_cast<double>(t)));
            out[2] = static_cast<float>(fcos(static_cast<double>(t)));
            out[3] = static_cast<float>(fptan(static_cast<double>(t)));
            return 7;
        default:
            return 0;
        }
        out[0] = t;
        out[1] = t;
        out[2] = t;
        out[3] = t;
        return 7;
    }
    }
    return 0;
}

// 0x6b7220 — observed shape
// NEEDS_MANUAL: `uStack_c` selects the binary operator but is never assigned
// in the listing (kept as a zero-initialised selector); the unaff_EBX /
// unaff_EBP / unaff_retaddr registers are inherited values and are modelled
// as explicit locals. The four vector builders are invoked through a
// 6-argument function-pointer shape because the provider call sequence does
// not match their own 4/6-parameter prototypes.
unsigned int FUN_006b7220(void* self, uint32_t param_1, int param_2,
                          uint32_t param_3, uint32_t param_4,
                          uint32_t param_5, uint32_t param_6)
{
    typedef unsigned int (*BinOp6Fn)(uint32_t receiver, uint32_t retaddr,
                                     int lhs, int rhs, uint32_t ebx,
                                     uint32_t ebp);
    int* object = reinterpret_cast<int*>(self);
    uint32_t unaff_EBX = 0;
    uint32_t unaff_EBP = 0;
    uint32_t unaff_retaddr = 0;
    uint32_t uStack_c = 0;
    int local_18;
    int local_14;

    uint32_t packed = *reinterpret_cast<uint32_t*>(
        reinterpret_cast<char*>(param_2) + 0x14);
    uint32_t kind = packed & 0xf0000000u;
    int lhs = vlookup(object, packed & 0xfff);
    int rhs = vlookup(object, (packed >> 0xc) & 0xfff);
    if ((lhs == 0) || (rhs == 0)) {
        FUN_005477c0(1, 0, "Invalid entries in OperatorConstant\n");
        return 1;
    }
    {
        uint32_t field = *reinterpret_cast<uint32_t*>(lhs + 0x10);
        if (DAT_00729098 == 0) {
            FUN_005e0120();
        }
        local_18 = DAT_00729060[field & 0xff];
        field = *reinterpret_cast<uint32_t*>(rhs + 0x10);
        if (DAT_00729098 == 0) {
            FUN_005e0120();
        }
        local_14 = DAT_00729060[field & 0xff];
    }
    {
        uint32_t lhsKind = *reinterpret_cast<uint32_t*>(lhs + 0x10) & 0xf0000000u;
        if (lhsKind == 0x20000000u) {
            local_18 = static_cast<int>(
                FUN_006b5400(*reinterpret_cast<uint32_t*>(lhs + 8)));
            FUN_006b6a00(object, 0, lhs, param_1, param_2, param_3,
                         static_cast<int>(param_4), param_5);
        } else if (lhsKind == 0x40000000u) {
            FUN_006b8940(0, lhs, param_6);
        } else if ((lhsKind == 0x30000000u) || (lhsKind == 0x10000000u)) {
            FUN_006b8c10(0, lhs, param_1, param_2, static_cast<int>(param_3),
                         static_cast<int>(param_4), static_cast<int>(param_5),
                         static_cast<int>(param_6));
        }
        uint32_t rhsKind = *reinterpret_cast<uint32_t*>(rhs + 0x10) & 0xf0000000u;
        if (rhsKind == 0x20000000u) {
            local_14 = static_cast<int>(
                FUN_006b5400(*reinterpret_cast<uint32_t*>(rhs + 8)));
            FUN_006b6a00(object, 1, rhs, param_1, param_2, param_3,
                         static_cast<int>(param_4), param_5);
        } else if (rhsKind == 0x30000000u) {
            FUN_006b8c10(1, rhs, param_1, param_2, static_cast<int>(param_3),
                         static_cast<int>(param_4), static_cast<int>(param_5),
                         static_cast<int>(param_6));
        } else if ((rhsKind == 0x40000000u) || (rhsKind == 0x10000000u)) {
            FUN_006b8940(1, rhs, param_6);
        }
    }
    if ((local_18 != 0) && (local_14 != 0)) {
        if (uStack_c > 0x30000000u) {
            if (uStack_c == 0x40000000u) {
                return reinterpret_cast<BinOp6Fn>(&FUN_006b5d80)(
                    kind, unaff_retaddr, local_18, local_14,
                    unaff_EBX, unaff_EBP);
            }
            return 1;
        }
        if (uStack_c == 0x30000000u) {
            return reinterpret_cast<BinOp6Fn>(&FUN_006b5b60)(
                kind, unaff_retaddr, local_18, local_14,
                unaff_EBX, unaff_EBP);
        }
        if (uStack_c == 0x10000000u) {
            return reinterpret_cast<BinOp6Fn>(&FUN_006b55c0)(
                kind, unaff_retaddr, local_18, local_14,
                unaff_EBX, unaff_EBP);
        }
        if (uStack_c == 0x20000000u) {
            return reinterpret_cast<BinOp6Fn>(&FUN_006b5910)(
                kind, unaff_retaddr, local_18, local_14,
                unaff_EBX, unaff_EBP);
        }
        return 1;
    }
    FUN_005477c0(1, 0, "Invalid operands in OperatorConstant\n");
    return 1;
}
