// Band 1 wave 4 — small leaf helpers (UNVERIFIED; no cl 13.10.3077).
// Clean-room from shipped bytes (Ghidra 12.2 corpus) + band1 triage spans.
// Spans 32 with 0 callees; preserved constants, byte offsets, and call order.
#include <cstdint>
extern void operator_delete__(void* ptr);
extern void* DAT_008cacc8;
extern uint32_t DAT_008cacd0;
extern uint8_t DAT_008ca928;
extern uint32_t DAT_007252f0[];
extern uint32_t DAT_00725350[];
extern int DAT_007271d0[];
extern char DAT_008bea80;
extern uint32_t DAT_008be9f4;

// 0x00412c90 — guarded delete plus vtable store; ESI register only.
void FUN_00412c90_recon(int* esi_ptr) {
    void* victim = reinterpret_cast<uint8_t*>(*esi_ptr) - 8;
    if (victim != nullptr && victim != DAT_008cacc8) operator_delete__(victim);
    *esi_ptr = static_cast<int>(DAT_008cacd0);
}

// 0x00419dc0 — one-shot vtable call guarded by DAT_008ca928; ECX register only.
void FUN_00419dc0_recon(void* ecx_this) {
    if (DAT_008ca928 != 0) {
        DAT_008ca928 = 0;
        if (ecx_this != nullptr) {
            void* vtable = *reinterpret_cast<void**>(ecx_this);
            void (*fn)(void*, int) = reinterpret_cast<void (*)(void*, int)>(*reinterpret_cast<void**>(vtable));
            fn(ecx_this, 1);
        }
    }
}

// 0x00431910 — pair-table index search over 9 entries; ECX/EDX register only.
int FUN_00431910_recon(int ecx_val, int edx_val) {
    int i = 0;
    while (DAT_007252f0[i] != static_cast<uint32_t>(edx_val) || DAT_00725350[i] != static_cast<uint32_t>(ecx_val)) {
        i = i + 1;
        if (8 < i) return -1;
    }
    return i;
}

// 0x004842d0 — NUL-terminated copy from EAX src to DAT_008bea80 dst, then store.
void FUN_004842d0_recon(void* eax_src, uint32_t param_1) {
    char* p = reinterpret_cast<char*>(eax_src);
    char* dst = &DAT_008bea80;
    int offset = static_cast<int>(dst - p);
    char c;
    do { c = *p; p[offset] = c; p = p + 1; } while (c != '\0');
    DAT_008be9f4 = param_1;
}

// 0x004bf420 — first table entry greater than ECX over 0x35 slots; ECX register only.
uint32_t FUN_004bf420_recon(int ecx_val) {
    uint32_t u = 0;
    do {
        if (ecx_val < DAT_007271d0[u]) break;
        u = u + 1;
    } while (u < 0x35);
    return static_cast<uint32_t>(DAT_007271d0[u]);
}
