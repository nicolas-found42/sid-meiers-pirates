// Band 1 wave 3 — scalar-deleting-destructor tails (UNVERIFIED; no cl 13.10.3077).
// Shape: "run body, then if (flags & 1) operator delete(this)" (MSVC deleting-
// destructor convention). Body callees are external here (defined elsewhere).
// Clean-room from shipped bytes (Ghidra 12.2 corpus) + band1 triage spans.
#include <stddef.h>

struct DtorHost_42c110 {
    void __thiscall FUN_0042c110(unsigned char flags);
    void __thiscall FUN_004baef0(void); // destructor body; defined elsewhere
};

// 0x0042c110 — scalar-deleting destructor; body = FUN_004baef0.
void __thiscall DtorHost_42c110::FUN_0042c110(unsigned char flags)
{
    FUN_004baef0();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_4313a0 {
    void __thiscall FUN_004313a0(unsigned char flags);
    void __thiscall FUN_00431210(void); // destructor body; defined elsewhere
};

// 0x004313a0 — scalar-deleting destructor; body = FUN_00431210.
void __thiscall DtorHost_4313a0::FUN_004313a0(unsigned char flags)
{
    FUN_00431210();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_45a100 {
    void __thiscall FUN_0045a100(unsigned char flags);
    void __thiscall FUN_0045a050(void); // destructor body; defined elsewhere
};

// 0x0045a100 — scalar-deleting destructor; body = FUN_0045a050.
void __thiscall DtorHost_45a100::FUN_0045a100(unsigned char flags)
{
    FUN_0045a050();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_4ab0b0 {
    void __thiscall FUN_004ab0b0(unsigned char flags);
    void __thiscall FUN_004ab7c0(void); // destructor body; defined elsewhere
};

// 0x004ab0b0 — scalar-deleting destructor; body = FUN_004ab7c0.
void __thiscall DtorHost_4ab0b0::FUN_004ab0b0(unsigned char flags)
{
    FUN_004ab7c0();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_4b1030 {
    void __thiscall FUN_004b1030(unsigned char flags);
    void __thiscall FUN_004b1050(void); // destructor body; defined elsewhere
};

// 0x004b1030 — scalar-deleting destructor; body = FUN_004b1050.
void __thiscall DtorHost_4b1030::FUN_004b1030(unsigned char flags)
{
    FUN_004b1050();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_4ba8c0 {
    void __thiscall FUN_004ba8c0(unsigned char flags);
    void __thiscall FUN_004ba2c0(void); // destructor body; defined elsewhere
};

// 0x004ba8c0 — scalar-deleting destructor; body = FUN_004ba2c0.
void __thiscall DtorHost_4ba8c0::FUN_004ba8c0(unsigned char flags)
{
    FUN_004ba2c0();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_4c2930 {
    void __thiscall FUN_004c2930(unsigned char flags);
    void __thiscall FUN_004c2600(void); // destructor body; defined elsewhere
};

// 0x004c2930 — scalar-deleting destructor; body = FUN_004c2600.
void __thiscall DtorHost_4c2930::FUN_004c2930(unsigned char flags)
{
    FUN_004c2600();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}

struct DtorHost_4c2af0 {
    void __thiscall FUN_004c2af0(unsigned char flags);
    void __thiscall FUN_004c2b10(void); // destructor body; defined elsewhere
};

// 0x004c2af0 — scalar-deleting destructor; body = FUN_004c2b10.
void __thiscall DtorHost_4c2af0::FUN_004c2af0(unsigned char flags)
{
    FUN_004c2b10();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
}
