// Band4 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Scalar-deleting-destructor tails: "run body, then if (flags & 1)
// operator delete(this)" (MSVC deleting-destructor convention; class-system
// census in analysis/team/band4/REPORT.md). Body callees are external here.
#include <stddef.h>

struct DtorHost_b420 {
    void __thiscall FUN_0054b420(unsigned char flags);
    void __thiscall FUN_0054b440(void); // destructor body; defined elsewhere
};

// 0x0054b420 — scalar-deleting destructor; body = FUN_0054b440.
void __thiscall DtorHost_b420::FUN_0054b420(unsigned char flags)
{
    FUN_0054b440();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_b6a0 {
    void __thiscall FUN_0054b6a0(unsigned char flags);
    void __thiscall FUN_0054b650(void); // destructor body; defined elsewhere
};

// 0x0054b6a0 — same shape; body = FUN_0054b650.
void __thiscall DtorHost_b6a0::FUN_0054b6a0(unsigned char flags)
{
    FUN_0054b650();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_c2c0 {
    void __thiscall FUN_0054c2c0(unsigned char flags);
    void __thiscall FUN_00539b70(void); // destructor body (0x00539b70)
};

// 0x0054c2c0 — same shape; body = FUN_00539b70 (outside band4).
void __thiscall DtorHost_c2c0::FUN_0054c2c0(unsigned char flags)
{
    FUN_00539b70();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}
