// Band 1 wave 3 — push/pop save-stack pair (UNVERIFIED; no cl 13.10.3077).
// Clean-room from shipped bytes (Ghidra 12.2 corpus) + band1 triage spans.
// Preserves the DAT_007268f4/DAT_00726a84/DAT_007263bc save/restore idiom
// and the EDX/ESI register inputs as explicit arguments.
#include <cstdint>

extern uint32_t DAT_007263bc;
extern int DAT_00726a84;
extern uint32_t DAT_007268f4[];

// 0x004ae700 — push: save DAT_007263bc into slot DAT_00726a84, increment index,
// then take the EDX register value as the new DAT_007263bc.
void FUN_004ae700_recon(uint32_t edx_reg)
{
    DAT_007268f4[DAT_00726a84] = DAT_007263bc;
    DAT_00726a84 = DAT_00726a84 + 1;
    DAT_007263bc = edx_reg;
}

// 0x004ae720 — pop: decrement index, restore DAT_007263bc from the slot.
void FUN_004ae720_recon(void)
{
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = DAT_007268f4[DAT_00726a84];
}
