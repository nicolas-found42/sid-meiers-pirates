// Band 1 wave 3 — small leaf helpers (UNVERIFIED; no cl 13.10.3077).
// Clean-room from shipped bytes (Ghidra 12.2 corpus) + band1 triage spans.
// Spans 16..32 with 0..2 callees and no strings; preserved constants and
// byte offsets where the corpus exposes them.
#include <cstdint>

extern void FUN_004b20f0(void);
extern void FUN_004a1100(void);
extern void FUN_004e8770(float x, float y);
extern void FUN_005bf480(void);
extern void FUN_0058f6e0(uint32_t target, uint32_t value);
// Win32 cursor handle passed through EAX; declared (not defined) per STYLE.md.
void SetCursor(void* handle);
extern uint32_t DAT_007263bc;
extern int DAT_00726a84;
extern uint32_t DAT_007268f4[];

// 0x004b2160 — three-iteration helper loop; calls FUN_004b20f0 exactly 3 times.
void FUN_004b2160_recon(void)
{
    int i = 0;
    do {
        FUN_004b20f0();
        i = i + 1;
    } while (i < 3);
}

// 0x00412da0 — cursor setter; handle arrives in EAX register only, no stack slot.
// Pseudocode: SetCursor((HCURSOR)*in_EAX). Recorded as comment per STYLE.md:
// register-only input, so no invented signature; body observed as SetCursor(*EAX).
// Observed body: SetCursor(*reinterpret_cast<void**>(eax)); reproduced below with
// the register value taken as an explicit argument for recon purposes.
void FUN_00412da0_recon(void* eax_handle)
{
    void* handle = *reinterpret_cast<void**>(eax_handle);
    SetCursor(handle);
}

// 0x004aaef0 — constant-zero leaf; returns 0.
uint32_t FUN_004aaef0_recon(void)
{
    return 0;
}

// 0x004a1050 — single-call forwarder; tail-calls FUN_004a1100 and returns.
void FUN_004a1050_recon(void)
{
    FUN_004a1100();
}

// 0x004c2d70 — int-to-float pair forwarder; converts (param_1, param_2) to floats
// and forwards to FUN_004e8770 in call order.
void FUN_004c2d70_recon(int param_1, int param_2)
{
    FUN_004e8770((float)param_1, (float)param_2);
}

// 0x004c2df0 — two-field setter with notify. this in ECX register only; byte
// offsets +0x2c (value) and +0x0c (target) preserved from the corpus.
void FUN_004c2df0_recon(void* ecx_this, uint32_t param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(ecx_this);
    *reinterpret_cast<uint32_t*>(base + 0x2c) = param_1;
    FUN_0058f6e0(*reinterpret_cast<uint32_t*>(base + 0x0c), param_1);
}

// 0x004abb30 — refcount release with terminal call. ecx refcount holder in ECX.
// Observed: if (*ECX != 0) { piVar1 = *ECX + 0x68; *piVar1 -= 1; if (*piVar1 == 0)
// FUN_005bf480(); } Byte offset +0x68 preserved; terminal call at 0x4abb3b in corpus.
void FUN_004abb30_recon(int* ecx_ref)
{
    if (*ecx_ref != 0) {
        int* counter = reinterpret_cast<int*>(*reinterpret_cast<uint8_t**>(ecx_ref) + 0x68);
        *counter = *counter + -1;
        if (*counter == 0) {
            FUN_005bf480();
        }
    }
}
