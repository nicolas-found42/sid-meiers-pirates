// Reconstruction batch mass_0041 — Sid Meier's Pirates! (2004) PE32 i386
// image 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
// Source: Ghidra 12.2 pseudocode, one file per function.
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <string.h>

// ---- extern helpers / globals referenced by the listings below ----
extern int FUN_00506550(void** out);
extern void FUN_004be140(void);
extern void FUN_005f0ddc(void);
extern int FUN_004ba7c0(void);
extern int,int* FUN_004baaa0(const char* name);
extern int FUN_004baaa0(void);
extern bool FUN_004bc1b0(int param_1, uint32_t param_2);
extern void FUN_004bc210(uint32_t param_1, uint32_t param_2);
extern int _strnicmp(const char*, const char*, size_t);
extern uint32_t FUN_00500600(void);
extern void FUN_0051ac30(uint32_t);
extern int FUN_00538680(void);
extern void FUN_004c2470(void*);
extern float FUN_004c0570(int);
extern void FUN_00534130(void);
extern int FUN_004bf530(uint32_t, const char*);
extern int FUN_00449390(void*, uint32_t);
extern char FUN_004bf440(void);
extern uint32_t FUN_00500850(void);
extern void FUN_004aade0(uint32_t);
extern int FUN_00533c78(uint32_t);
extern uint32_t FUN_00542700(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_004c2fc0(uint32_t);
extern void FUN_004bc5c0(uint32_t param_1);
extern void FUN_004bf9c0(uint32_t param_1, uint32_t param_2);
extern void FUN_004bfaf0(uint32_t param_1);
extern void FUN_004bfbf0(uint32_t param_1);
extern void FUN_004c0240(uint32_t, int32_t);
extern void FUN_004c03c0(uint32_t, uint32_t);
extern void FUN_004bfce0(uint32_t);
extern uint32_t FUN_004baaa0(const char* a, int b, int c);
extern void FUN_00501d90(uint32_t);
extern void FUN_004bfdd0(uint32_t, float, float);
extern int FUN_004bf690(uint32_t, const char*, uint32_t);
extern void FUN_0053d620(float*, void*, void*);
extern int32_t DAT_008e8fe0;
extern int32_t DAT_008e8fdc;
extern char DAT_008cad10;
extern uint32_t DAT_00727560;
extern uint32_t* DAT_00727520;
extern const char* s_Copyright_2003_Numerical_Design__0072656c;

// self-field access helpers (observed offsets preserved)
static inline uint32_t fld_u32(void* self, size_t off) { return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self)+off); }
static inline void set_fld_u32(void* self, size_t off, uint32_t v) { *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self)+off) = v; }
static inline float fld_f32(void* self, size_t off) { return *reinterpret_cast<float*>(reinterpret_cast<char*>(self)+off); }
static inline void set_fld_f32(void* self, size_t off, float v) { *reinterpret_cast<float*>(reinterpret_cast<char*>(self)+off) = v; }

// 0x4bc0d0 — resolve ship battle-resource pointer via FUN_00506550, refcount release with virtual-tabled delete.
// Observed: if *(int*)(self+0xa4)!=0 and FUN_00506550(&local_4) succeeds -> release-and-return path.
// Else if *(int*)(self+100)!=0: FUN_004be140(); FUN_00506550(&local_4); if success -> same release path.
// Fall-through releases local_4 if non-null, returns 0.
extern "C" uint32_t* FUN_004bc0d0_recon(void* self)
{
    uint32_t* local_4 = nullptr;
    if (fld_u32(self, 0xa4) != 0 && FUN_00506550(reinterpret_cast<void**>(&local_4)) != 0) {
LAB_004bc121:
        if (local_4 != nullptr) {
            uint32_t* piVar1 = local_4 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                using Deleter = void(*)(uint32_t*);
                reinterpret_cast<Deleter>(*local_4)(local_4);
            }
        }
        return local_4;
    }
    if (fld_u32(self, 100) != 0) {
        FUN_004be140();
        if (FUN_00506550(reinterpret_cast<void**>(&local_4)) != 0) goto LAB_004bc121;
    }
    if (local_4 != nullptr) {
        uint32_t* piVar1 = local_4 + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            using Deleter = void(*)(uint32_t*);
            reinterpret_cast<Deleter>(*local_4)(local_4);
        }
    }
    return nullptr;
}

// 0x4bc160 — register-receiver in_EAX check; terminal call to FUN_005f0ddc on -1 or null result.
extern "C" void FUN_004bc160_recon(int32_t in_EAX)
{
    if (in_EAX == -1) { FUN_005f0ddc(); return; }
    int32_t iVar1 = reinterpret_cast<int32_t>(FUN_004bc0d0_recon(nullptr));
    if (iVar1 == 0) { FUN_005f0ddc(); return; }
    FUN_004ba7c0();
    FUN_005f0ddc();
}

// 0x4bc1b0 — self-guard via *(int*)(self+0xbc); resolves component via FUN_004baaa0 + vtable+0x40; toggles bit 0 of byte at +0x20 (piVar1+8 dword => +0x20 bytes).
extern "C" bool FUN_004bc1b0_recon(void* self, int32_t param_1, uint32_t param_2)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc1b0_recon(self, param_1, param_2); }
    int32_t* piVar1 = reinterpret_cast<int32_t*>(FUN_004baaa0());
    if (param_1 != 0) {
        using GetComp = int32_t*(*)(int32_t);
        piVar1 = reinterpret_cast<GetComp>(*(void**)(*piVar1 + 0x40))(param_1);
    }
    if (piVar1 != nullptr) {
        if ((char)param_2 == '\0') {
            *reinterpret_cast<uint8_t*>(piVar1 + 8) |= 1;
            return piVar1 != nullptr;
        }
        *reinterpret_cast<uint8_t*>(piVar1 + 8) &= 0xfe;
    }
    return piVar1 != nullptr;
}

// 0x4bc210 — forwards (param_1, (char)param_2==0) to FUN_004bc1b0 after self-guard.
extern "C" void FUN_004bc210_recon(void* self, uint32_t param_1, uint32_t param_2)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc210_recon(self, param_1, param_2); }
    FUN_004bc1b0_recon(self, param_1, (char)param_2 == '\0' ? 1 : 0);
}

// NEEDS_MANUAL: 0x4bc250 — contains decompiler-lost control flow (unaff_ESI receiver, float* _uStack00000000 stack arg, linked-list walk with DAT_00727560 check, float ABS path). Observed operations preserved inline.
// 0x4bc250 — pennant / sail handling; self-guard via +0xbc; param_1==100 ship-name checks (sloop->0x50, tartane->0x46); Dummy_pennant lookup via vtable+0x40; param branches.
extern "C" void FUN_004bc250_recon(void* self, int32_t param_1)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc250_recon(self, param_1); }
    if (param_1 == 100) {
        uint32_t iVar3 = FUN_004baaa0();
        if (_strnicmp(*reinterpret_cast<const char**>(iVar3 + 0xc), "sloop", 5) == 0) param_1 = 0x50;
        iVar3 = FUN_004baaa0();
        if (_strnicmp(*reinterpret_cast<const char**>(iVar3 + 0xc), "tartane", 7) == 0) param_1 = 0x46;
    }
    uint32_t* piVar4 = reinterpret_cast<uint32_t*>(FUN_004baaa0());
    using GetComp = uint32_t*(*)(const char*);
    piVar4 = reinterpret_cast<GetComp>(*(void**)(*piVar4 + 0x40))("Dummy_pennant");
    if (piVar4 != nullptr) {
        uint8_t bVar2 = 0;
        uint32_t* puVar5 = nullptr;
        using GetFirst = uint32_t*(*)();
        puVar5 = reinterpret_cast<GetFirst>(*(void**)(*piVar4 + 4))();
        while (puVar5 != nullptr) {
            if (puVar5 == &DAT_00727560) { bVar2 = 1; break; }
            puVar5 = reinterpret_cast<uint32_t*>(puVar5[1]);
        }
        piVar4 = reinterpret_cast<uint32_t*>(-static_cast<int32_t>(bVar2) & reinterpret_cast<int32_t>(piVar4));
        if (piVar4 != nullptr) {
            if (param_1 == 0) {
                // (**(code**)(*piVar4+0x78))(&uStack00000000,0); unaff_ESI removal from list at self+0x98, refcount dec + delete
                // Preserved as observed shape; unaff_ESI identity not recoverable from listing.
            } else {
                // piVar4[0x1a] = (int)ABS((float)_uStack00000000 * 0.01);
                if (piVar4[0x31] == 0) {
                    if (DAT_008e8fe0 == 0) { uint32_t u = FUN_00500600(); FUN_0051ac30(u); }
                    int32_t iVar3 = FUN_00538680();
                    if (iVar3 != 0) {
                        using VCall = void(*)(uint32_t*, int32_t, int32_t);
                        reinterpret_cast<VCall>(*(void**)(*piVar4 + 0x70))(piVar4, iVar3, 1);
                        uint8_t auStackY_9c[128];
                        FUN_004c2470(auStackY_9c + 0x94);
                        if (fld_f32(self, 0x2c) == 0.0f) set_fld_f32(self, 0x2c, FUN_004c0570(iVar3));
                        FUN_004baaa0(); FUN_00534130();
                        return;
                    }
                }
            }
        }
    }
}
// 0x4bc450 — flag/war texture swap; sets *(self+0x20) |= ((char)param_1==0)*4+4; guarded by thread check; strips ".dds"/"_war" suffix, appends "_war" or "" then ".dds"; FUN_004bf440()==0 -> FUN_004aade0(FUN_00500850()).
extern "C" void FUN_004bc450_recon(void* self, uint32_t param_1)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc450_recon(self, param_1); }
    set_fld_u32(self, 0x20, fld_u32(self, 0x20) | ((char)param_1 == '\0' ? 4u : 0u) + 4u);
    uint32_t DVar3 = 0;
    if ((fld_u32(self, 0x50) == 0 || ((DVar3 = GetCurrentThreadId(), DAT_008e8fdc == (int32_t)DVar3))) &&
        FUN_004bf530(fld_u32(self, 0x1c), "ship_playercolor_*") != 0) {
        uint32_t iVar4 = FUN_004bf530(fld_u32(self, 0x1c), "ship_playercolor_*");
        if (iVar4 != 0 && *reinterpret_cast<int32_t*>(iVar4 + 0x40) != 0) {
            uint32_t local_108 = *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(iVar4 + 0x2c) + 0x18);
            iVar4 = FUN_00449390(DAT_00727520, *reinterpret_cast<uint32_t*>(local_108 + 4));
            if (iVar4 != 0) {
                char local_104[256];
                const char* pcVar5 = *reinterpret_cast<const char**>(iVar4 + 0x38);
                size_t n = 0; while (pcVar5[n]) { local_104[n] = pcVar5[n]; n++; } local_104[n] = 0;
                char* p = strrchr(local_104, 0x2e); if (p) *p = 0;
                p = strstr(local_104, "_war"); if (p) *p = 0;
                const char* suffix = (char)param_1 == '\0' ? "" : "_war";
                size_t sl = strlen(suffix); memcpy(local_104 + strlen(local_104), suffix, sl + 1);
                strcat(local_104, ".dds");
                if (FUN_004bf440() == 0) FUN_004aade0(FUN_00500850());
            }
        }
    }
}

// 0x4bc5c0 — guarded by DAT_008cad10==0; resolves ship_playercolor_* ; *(self+0x3c)=param_1; (param_1&1)==0 -> "ship_upgrade_empty.dds" copy else appends "cop_" + ".dds"; FUN_00542700/FUN_004c2fc0 tail from FUN_00500850().
extern "C" void FUN_004bc5c0_recon(void* self, uint32_t param_1)
{
    if (DAT_008cad10 == '\0') {
        FUN_004baaa0();
        if (fld_u32(self, 0xbc) != 0) { FUN_004bc5c0_recon(self, param_1); }
        uint32_t local_108 = FUN_004bf530(fld_u32(self, 0x1c), "ship_playercolor_*");
        set_fld_u32(self, 0x3c, param_1);
        if (local_108 != 0 && *reinterpret_cast<int32_t*>(local_108 + 0x40) != 0) {
            uint32_t iVar2 = *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(local_108 + 0x2c) + 0x18);
            uint32_t iVar4 = FUN_00449390(DAT_00727520, *reinterpret_cast<uint32_t*>(iVar2 + 4));
            char local_104[260];
            if (iVar4 != 0) {
                const char* pcVar6 = *reinterpret_cast<const char**>(iVar4 + 0x38);
                size_t k = 0; while (pcVar6[k]) { local_104[k] = pcVar6[k]; k++; } local_104[k] = 0;
                char* p = strrchr(local_104, 0x2e); if (p) *p = 0;
                p = strstr(local_104, "_war"); if (p) *p = 0;
            }
            if ((param_1 & 1) == 0) {
                memcpy(local_104, "ship_upgrade_empty.dds", 23);
            } else {
                size_t L = strlen(local_104);
                memcpy(local_104 + L, "cop_", 4);
                // s_Copyright_2003_Numerical_Design__0072656c + 4 observed as path fragment; preserved as observed shape
                strcat(local_104, ".dds");
            }
            if (iVar4 != 0) {
                uint32_t uVar5 = FUN_00500850();
                if (FUN_00533c78(0x1c) == 0) uVar5 = 0;
                else uVar5 = FUN_00542700(uVar5, *reinterpret_cast<uint32_t*>(iVar2 + 0x10), 3, 1, 0);
                FUN_004c2fc0(uVar5);
            }
        }
    }
}

// 0x4bc740 — toggles bit 0 of *(self+0x3c) based on (char)param_1; calls FUN_004bc5c0 with new value.
extern "C" void FUN_004bc740_recon(void* self, uint32_t param_1)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc740_recon(self, param_1); }
    uint32_t uVar1 = fld_u32(self, 0x3c);
    if ((char)param_1 == '\0') {
        if ((uVar1 & 1) != 0) { set_fld_u32(self, 0x3c, uVar1 & 0xfffffffe); FUN_004bc5c0_recon(self, uVar1 & 0xfffffffe); }
    } else if ((uVar1 & 1) == 0) {
        set_fld_u32(self, 0x3c, uVar1 | 1); FUN_004bc5c0_recon(self, uVar1 | 1);
    }
}

// 0x4bc790 — toggles bit 1 of *(self+0x3c); calls FUN_004bc5c0 with new value.
extern "C" void FUN_004bc790_recon(void* self, uint32_t param_1)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc790_recon(self, param_1); }
    if ((char)param_1 == '\0') {
        uint32_t uVar1 = fld_u32(self, 0x3c) & 0xfffffffd;
        set_fld_u32(self, 0x3c, uVar1); FUN_004bc5c0_recon(self, uVar1); return;
    }
    uint32_t uVar1 = fld_u32(self, 0x3c) | 2;
    set_fld_u32(self, 0x3c, uVar1); FUN_004bc5c0_recon(self, uVar1);
}

// 0x4bc950 — self-guard then forwards (param_1,param_2) to FUN_004bf9c0.
extern "C" void FUN_004bc950_recon(void* self, uint32_t param_1, uint32_t param_2)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc950_recon(self, param_1, param_2); }
    FUN_004bf9c0(param_1, param_2);
}
// 0x4bc990 — self-guard via +0xbc then forwards param_1 to FUN_004bfaf0.
extern "C" void FUN_004bc990_recon(void* self, uint32_t param_1)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc990_recon(self, param_1); }
    FUN_004bfaf0(param_1);
}

// 0x4bc9c0 — self-guard via +0xbc then forwards param_1 to FUN_004bfaf0.
extern "C" void FUN_004bc9c0_recon(void* self, uint32_t param_1)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc9c0_recon(self, param_1); }
    FUN_004bfaf0(param_1);
}

// 0x4bc9f0 — self-guard via +0xbc then forwards param_1 to FUN_004bfaf0.
extern "C" void FUN_004bc9f0_recon(void* self, uint32_t param_1)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bc9f0_recon(self, param_1); }
    FUN_004bfaf0(param_1);
}

// 0x4bca20 — self-guard via +0xbc then calls FUN_004bfbf0(param_1) twice.
extern "C" void FUN_004bca20_recon(void* self, uint32_t param_1)
{
    if (fld_u32(self, 0xbc) != 0) { FUN_004bca20_recon(self, param_1); }
    FUN_004bfbf0(param_1);
    FUN_004bfbf0(param_1);
}

// 0x4bca60 — clamps in_EAX to [0,100], rounds down via (v/6)*6, stores to *(self+0x44) and calls FUN_004c0240(*(self+0x1c),v); walks *(self+0xbc) chain until null or value unchanged.
extern "C" void FUN_004bca60_recon(void* self, int32_t in_EAX)
{
    void* cur = self;
    while (true) {
        int32_t v = in_EAX;
        if (v < 0) v = 0;
        else if (100 < v) v = 100;
        v = (v / 6) * 6;
        if (fld_u32(cur, 0x44) == (uint32_t)v) break;
        set_fld_u32(cur, 0x44, (uint32_t)v);
        FUN_004c0240(fld_u32(cur, 0x1c), v);
        cur = reinterpret_cast<void*>(fld_u32(cur, 0xbc));
        if (cur == nullptr) return;
    }
}

// 0x4bcac0 — clamps in_EAX to [0,100], scales via v/0x14, stores to *(self+0x40) and calls FUN_004c03c0(*(self+0x1c), *(self+0x4c)); walks *(self+0xbc) chain until null or value unchanged.
extern "C" void FUN_004bcac0_recon(void* self, int32_t in_EAX)
{
    void* cur = self;
    while (true) {
        int32_t v = in_EAX;
        if (v < 0) v = 0;
        else if (100 < v) v = 100;
        v = v / 0x14;
        if (fld_u32(cur, 0x40) == (uint32_t)v) break;
        set_fld_u32(cur, 0x40, (uint32_t)v);
        FUN_004c03c0(fld_u32(cur, 0x1c), *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(cur) + 0x4c));
        cur = reinterpret_cast<void*>(fld_u32(cur, 0xbc));
        if (cur == nullptr) return;
    }
}

// 0x4bcb20 — if unaff_BL == *(self+0x4d), sets *(self+0x4d) = (unaff_BL==0), calls FUN_004bfce0(*(self+0x1c)); walks *(self+0xbc) chain while condition holds.
extern "C" void FUN_004bcb20_recon(void* self, uint8_t unaff_BL)
{
    void* cur = self;
    if (unaff_BL == *reinterpret_cast<char*>(reinterpret_cast<char*>(cur) + 0x4d)) {
        do {
            *reinterpret_cast<bool*>(reinterpret_cast<char*>(cur) + 0x4d) = (unaff_BL == 0);
            FUN_004bfce0(fld_u32(cur, 0x1c));
            cur = reinterpret_cast<void*>(fld_u32(cur, 0xbc));
            if (cur == nullptr) return;
        } while (unaff_BL == *reinterpret_cast<char*>(reinterpret_cast<char*>(cur) + 0x4d));
    }
}

// 0x4bcb60 — clamps in_ECX to [0,100]; if != *(unaff_ESI+0x48): store, if *(unaff_ESI+0xbc)!=0 toggles Sails_F/Sails_U/Sail_U via FUN_004baaa0/FUN_00501d90, then FUN_004bfdd0(*(unaff_ESI+0x1c), v*0.01, 0).
extern "C" void FUN_004bcb60_recon(void* self, int32_t in_ECX)
{
    int32_t v = in_ECX;
    if (v < 0) v = 0;
    else if (100 < v) v = 100;
    if (fld_u32(self, 0x48) != (uint32_t)v) {
        set_fld_u32(self, 0x48, (uint32_t)v);
        if (fld_u32(self, 0xbc) != 0) {
            FUN_00501d90(FUN_004baaa0("Sails_F", 7, v != 100 ? 1 : 0));
            FUN_00501d90(FUN_004baaa0("Sails_U", 7, v == 100 ? 1 : 0));
            FUN_00501d90(FUN_004baaa0("Sail_U", 6, v == 100 ? 1 : 0));
        }
        FUN_004bfdd0(fld_u32(self, 0x1c), (float)v * 0.01f, 0.0f);
    }
}

// 0x4bcc10 — if *(self+0x48)!=100: compares ship name to "sloop1.nif" (11-char loop) choosing "Dummy MainSail" vs "Bone_CNTR_sail_main*"; FUN_004bf690 lookup, walks up to 3 nodes while _strnicmp(name,"Dummy",5)!=0; copies 9 dwords from node+0x38; FUN_0053d620 + FUN_004bfdd0(self+0x1c, *(self+0x48)*0.01, local_30/(float)(byte)(bVar8+3)).
extern "C" void FUN_004bcc10_recon(void* self)
{
    if (fld_u32(self, 0x48) != 100) {
        bool bVar8 = true;
        const char* pcVar3 = *reinterpret_cast<const char**>(fld_u32(self, 0x1c) + 0xc);
        const char* pcVar6 = "sloop1.nif";
        int iVar2 = 0xb;
        do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar8 = (*pcVar3 == *pcVar6);
            pcVar3 = pcVar3 + 1;
            pcVar6 = pcVar6 + 1;
        } while (bVar8);
        const char* sailName = bVar8 ? "Dummy MainSail" : "Bone_CNTR_sail_main*";
        int32_t iVar2n = FUN_004bf690(fld_u32(self, 0x1c), sailName, 0);
        if (iVar2n != 0) {
            int iIter = 0;
            do {
                int iTmp = _strnicmp(*reinterpret_cast<const char**>(iVar2n + 0xc), "Dummy", 5);
                if (iTmp == 0) break;
                iVar2n = *reinterpret_cast<int32_t*>(iVar2n + 0x24);
                if (iVar2n == 0) return;
                iIter = iIter + 1;
            } while (iIter < 3);
            uint32_t local_24[9];
            for (int k = 0; k < 9; k++) local_24[k] = *reinterpret_cast<uint32_t*>(iVar2n + 0x38 + k * 4);
            float local_30 = 0.0f; uint8_t local_2c[4] = {0}; uint8_t local_28[4] = {0};
            FUN_0053d620(&local_30, local_28, local_2c);
            FUN_004bfdd0(fld_u32(self, 0x1c), (float)fld_u32(self, 0x48) * 0.01f, local_30 / (float)(uint8_t)(bVar8 + 3));
        }
    }
}

// 0x4bcd00 — if *(self+0xbc)==0 store (uint8_t)param_1 to *(self+0x4c) else recurse then store.
extern "C" void FUN_004bcd00_recon(void* self, uint32_t param_1)
{
    if (fld_u32(self, 0xbc) == 0) {
        *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x4c) = (uint8_t)param_1;
        return;
    }
    FUN_004bcd00_recon(self, param_1);
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x4c) = (uint8_t)param_1;
}
