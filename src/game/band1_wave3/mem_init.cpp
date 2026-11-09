// Band 1 wave 3 — tiny object initialisers (UNVERIFIED; no cl 13.10.3077).
// Clean-room from shipped bytes (Ghidra 12.2 corpus) + band1 triage spans.
// Preserves vtable pointers, constant writes (0xec, 0xef-flag), and offsets.
#include <cstdint>

extern void* PTR_FUN_0070bf4c;
extern void* PTR_FUN_0070c4d0;
extern void FUN_00540c50(void);
extern void FUN_005044d0(uint32_t value);

// 0x004aaea0 — object init with constant field writes. this in ECX register only.
// Call order observed: FUN_00540c50 first, then vtable/store sequence.
// Offsets: word at +0x20 (in_ECX+8 as undefined2* -> +0x20 bytes) = 0xec;
// byte at +0x22 = 0. Vtable slot 0 set to &PTR_FUN_0070bf4c.
void FUN_004aaea0_recon(void* ecx_this)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(ecx_this);
    FUN_00540c50();
    *reinterpret_cast<void**>(base) = PTR_FUN_0070bf4c;
    *reinterpret_cast<uint16_t*>(base + 0x20) = 0xec;
    *(base + 0x22) = 0;
}

// 0x004b9780 — vtable install with conditional deleting-destructor tail.
// this in ECX register only; vtable slot 0 = &PTR_FUN_0070c4d0.
void FUN_004b9780_recon(void* ecx_this, uint8_t flags)
{
    *reinterpret_cast<void**>(ecx_this) = PTR_FUN_0070c4d0;
    if ((flags & 1) != 0) {
        ::operator delete(ecx_this);
    }
}

// 0x004b97a0 — register-mediated field copy with flag set. EDI (unaff_EDI) and
// EAX (in_EAX) arrive in registers only; corpus stores *EDI = EAX, calls
// FUN_005044d0(EDI[4]), then sets byte at +0xef = 1. Signature below takes the
// register values explicitly; original register convention flagged unknown.
void FUN_004b97a0_recon(uint32_t* edi_reg, uint32_t eax_reg)
{
    *edi_reg = eax_reg;
    FUN_005044d0(edi_reg[4]);
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(edi_reg) + 0xef) = 1;
}
