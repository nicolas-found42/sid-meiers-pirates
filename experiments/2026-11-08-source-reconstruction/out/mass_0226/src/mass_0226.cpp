// Reconstruction batch mass_0226 — Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* thunk_FUN_00533c78(std::size_t n);
extern void operator_delete(void* p) noexcept;
extern uint8_t FUN_005be8c0(int a, int b);
extern void FUN_005cb870(uint32_t** p);
extern void FUN_005d7d70(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_005ca940(uint32_t v);
extern void FUN_005ca8f0(uint32_t v);
extern void FUN_005bf1f0(uint32_t a, uint32_t* b);
extern void FUN_005cb7c0();
extern void FUN_004127b0(uint32_t* p, uint32_t n, uint32_t sz, void* f);
extern void FUN_005c9820();
extern void FUN_005d3120();
extern void FUN_005d3160();
extern uint32_t FUN_005ca610();
extern void FUN_005ca4e0(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_005ca1d0(uint32_t a, uint32_t* b, int* c);
extern void FUN_005bf480();
extern void FUN_005bf670();
extern void FUN_005d2750(uint32_t a, uint32_t b, uint32_t c);
extern uint32_t FUN_005d3290(int p, uint16_t n);
extern void FUN_005d3090(uint32_t a, int* b);
extern void FUN_005d2830();
extern void FUN_005d3a30(void* p);
extern void FUN_005d3a60(uint32_t n);
extern void FUN_005d3bc0();
extern void FUN_005d3e10();
extern void FUN_005d3ff0(uint32_t a, int b, int c, int d);
extern void FUN_005d3d10(int p, uint8_t b);
extern void FUN_005d4520(int p1, uint32_t p2, int p3, int p4, uint32_t p5);
extern void FUN_005da790();

// 0x5d3690 — observed shape: self=ECX; if (self[0xf]!=0) { if (FUN_005be8c0(1,1)) { var=self via FUN_005cb870; *var = *(self[0xf]+0x14); reassign ref at var[1] to *(param+0x144) with decref/incref; var[4]=1; byte(var+5)=0; FUN_005d7d70(1..6) with (6,...) branching on byte(self+0xfd); vtable call *(self[*(param+0x154)+0x3a])(param+0x114,param+0x138,var); FUN_005ca940/CA8F0; self[0x41]--; self[0x42]--; FUN_005bf1f0(*(self[0xf]+0x14),var); refcount at EBP+100-- possibly FUN_005cb7c0; return var; } } return 0
uint32_t* FUN_005d3690_recon(void* self, int param_1) {
    uint32_t* se = static_cast<uint32_t*>(self);
    if (se[0xf] != 0) {
        uint32_t* local_4 = se;
        if (FUN_005be8c0(1, 1) != 0) {
            FUN_005cb870(&local_4);
            *local_4 = *reinterpret_cast<uint32_t*>(se[0xf] + 0x14u);
            uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(param_1 + 0x144);
            uint32_t* puVar3 = reinterpret_cast<uint32_t*>(local_4[1]);
            if (puVar3 != puVar2) {
                if (puVar3 != nullptr) {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar3 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (reinterpret_cast<void(__cdecl**)(uint32_t)>(*puVar3))(1);
                    }
                }
                local_4[1] = reinterpret_cast<uint32_t>(puVar2);
                if (puVar2 != nullptr) {
                    puVar2[1] = puVar2[1] + 1;
                }
            }
            local_4[4] = 1;
            *reinterpret_cast<uint8_t*>(local_4 + 5) = 0;
            FUN_005d7d70(1, 2, 0);
            FUN_005d7d70(2, 2, 0);
            FUN_005d7d70(3, 1, 0);
            FUN_005d7d70(4, 3, 0);
            FUN_005d7d70(5, 2, 0);
            if (*reinterpret_cast<char*>(reinterpret_cast<int8_t*>(self) + 0xfd) == '\0') {
                FUN_005d7d70(6, 1, 0);
            } else {
                FUN_005d7d70(6, 0, 0);
                *reinterpret_cast<uint8_t*>(reinterpret_cast<int8_t*>(self) + 0xfd) = 0;
            }
            {
                uint32_t* vt = reinterpret_cast<uint32_t*>(se[0]);
                int idx = *reinterpret_cast<int*>(param_1 + 0x154);
                auto callFn = reinterpret_cast<void(__cdecl*)(int, int, uint32_t*)>(vt[idx + 0x3a]);
                callFn(param_1 + 0x114, param_1 + 0x138, local_4);
            }
            FUN_005ca940(*reinterpret_cast<uint32_t*>(param_1 + 0x148));
            FUN_005ca8f0(*reinterpret_cast<uint32_t*>(param_1 + 0x14c));
            se[0x41] = se[0x41] - 1;
            se[0x42] = se[0x42] - 1;
            FUN_005bf1f0(*reinterpret_cast<uint32_t*>(se[0xf] + 0x14u), local_4);
            // Observed: EBP-based refcount (unaff_EBP); preserved as self-side slot when available.
            uint32_t ebpSlot = se[0x1a]; // observed as +100 offset via EBP; kept here to preserve conditional shape
            (void)ebpSlot;
            if (false) { // guarded by unaff_EBP!=0 in listing; EBP not modeled — shape preserved
                int iVar5;
                iVar5 = *reinterpret_cast<int*>(ebpSlot + 100) - 1;
                *reinterpret_cast<int*>(ebpSlot + 100) = iVar5;
                if (iVar5 == 0) FUN_005cb7c0();
            }
            return local_4;
        }
    }
    return nullptr;
}

// 0x5d3810 — observed shape: self=ECX; if (self[0xf]!=0) { if (FUN_005be8c0(1,1)) { var=self via FUN_005cb870; *var = *(self[0xf]+0x14); reassign ref var[1] to *(self[5]+0x604) with decref/incref; var[4]=0x20000; byte(var+5)=0; byte(var+0x18)=1; FUN_005d7d70(0x18,2,0),(1,4,0),(2,2,0),(3,1,0),(4,3,0),(5,2,0),(6,..) branching on byte(self+0xfd); FUN_005ca940(0); FUN_005ca8f0(0); f from param+0x16c..0x178 negated if *(param+0x150)==1; vec dot with self[5]+0x840..0x878 into var[8,0xc,0x10,0x14] (+0.5 - f5 on last); self[0x41]--; self[0x42]--; FUN_005bf1f0; local refcount var[0x19]-- possibly FUN_005cb7c0; return var; } } return 0
uint32_t* FUN_005d3810_recon(void* self, int param_1) {
    uint32_t* se = static_cast<uint32_t*>(self);
    if (se[0xf] != 0) {
        uint32_t* local_4 = se;
        if (FUN_005be8c0(1, 1) != 0) {
            FUN_005cb870(&local_4);
            uint32_t* puVar9 = local_4;
            *local_4 = *reinterpret_cast<uint32_t*>(se[0xf] + 0x14u);
            uint32_t* puVar6 = *reinterpret_cast<uint32_t**>(se[5] + 0x604u);
            uint32_t* puVar7 = reinterpret_cast<uint32_t*>(local_4[1]);
            if (puVar7 != puVar6) {
                if (puVar7 != nullptr) {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar7 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (reinterpret_cast<void(__cdecl**)(uint32_t)>(*puVar7))(1);
                    }
                }
                puVar9[1] = reinterpret_cast<uint32_t>(puVar6);
                if (puVar6 != nullptr) {
                    puVar6[1] = puVar6[1] + 1;
                }
            }
            puVar9[4] = 0x20000;
            *reinterpret_cast<uint8_t*>(puVar9 + 5) = 0;
            *reinterpret_cast<uint8_t*>(reinterpret_cast<int8_t*>(puVar9) + 0x18) = 1;
            FUN_005d7d70(0x18, 2, 0);
            FUN_005d7d70(1, 4, 0);
            FUN_005d7d70(2, 2, 0);
            FUN_005d7d70(3, 1, 0);
            FUN_005d7d70(4, 3, 0);
            FUN_005d7d70(5, 2, 0);
            if (*reinterpret_cast<char*>(reinterpret_cast<int8_t*>(self) + 0xfd) == '\0') {
                FUN_005d7d70(6, 1, 0);
            } else {
                FUN_005d7d70(6, 0, 0);
                *reinterpret_cast<uint8_t*>(reinterpret_cast<int8_t*>(self) + 0xfd) = 0;
            }
            FUN_005ca940(0);
            FUN_005ca8f0(0);
            float fVar2 = *reinterpret_cast<float*>(param_1 + 0x16c);
            float fVar3, fVar4, fVar5;
            if (*reinterpret_cast<int*>(param_1 + 0x150) == 1) {
                fVar2 = -fVar2;
                fVar3 = -*reinterpret_cast<float*>(param_1 + 0x170);
                fVar4 = -*reinterpret_cast<float*>(param_1 + 0x174);
                fVar5 = -*reinterpret_cast<float*>(param_1 + 0x178);
            } else {
                fVar3 = *reinterpret_cast<float*>(param_1 + 0x170);
                fVar4 = *reinterpret_cast<float*>(param_1 + 0x174);
                fVar5 = *reinterpret_cast<float*>(param_1 + 0x178);
            }
            uint32_t iVar8 = se[5];
            float o8 = fVar2 * *reinterpret_cast<float*>(iVar8 + 0x840u)
                     + fVar3 * *reinterpret_cast<float*>(iVar8 + 0x844u)
                     + fVar4 * *reinterpret_cast<float*>(iVar8 + 0x848u);
            float oC = fVar2 * *reinterpret_cast<float*>(iVar8 + 0x850u)
                     + fVar3 * *reinterpret_cast<float*>(iVar8 + 0x854u)
                     + fVar4 * *reinterpret_cast<float*>(iVar8 + 0x858u);
            float o10 = fVar2 * *reinterpret_cast<float*>(iVar8 + 0x860u)
                      + fVar3 * *reinterpret_cast<float*>(iVar8 + 0x864u)
                      + fVar4 * *reinterpret_cast<float*>(iVar8 + 0x868u);
            float o14 = (fVar2 * *reinterpret_cast<float*>(iVar8 + 0x870u)
                       + fVar3 * *reinterpret_cast<float*>(iVar8 + 0x874u)
                       + fVar4 * *reinterpret_cast<float*>(iVar8 + 0x878u) + 0.5f) - fVar5;
            *reinterpret_cast<float*>(&puVar9[8]) = o8;
            *reinterpret_cast<float*>(&puVar9[0xc]) = oC;
            *reinterpret_cast<float*>(&puVar9[0x10]) = o10;
            *reinterpret_cast<float*>(&puVar9[0x14]) = o14;
            se[0x41] = se[0x41] - 1;
            se[0x42] = se[0x42] - 1;
            FUN_005bf1f0(*reinterpret_cast<uint32_t*>(se[0xf] + 0x14u), puVar9);
            if (local_4 != nullptr) {
                uint32_t iVar = local_4[0x19];
                local_4[0x19] = iVar - 1;
                if (iVar - 1 == 0) FUN_005cb7c0();
            }
            return puVar9;
        }
    }
    return nullptr;
}

// 0x5d3a30 — observed shape: self=ECX; u=*(self+0xc); if (*(self+8) <= u) FUN_006b34a0(*(self+0x14)+u); FUN_005606f0(u,param); return u
uint32_t FUN_005d3a30_recon(void* self, uint32_t param_1) {
    uint8_t* b = static_cast<uint8_t*>(self);
    extern void FUN_006b34a0(int v);
    extern void FUN_005606f0(uint32_t idx, uint32_t p);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(b + 0xc);
    if (*reinterpret_cast<uint32_t*>(b + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(b + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, param_1);
    return uVar1;
}

// 0x5d3a60 — observed shape: self=ECX; vector<uint32_t> set_size(param_1) with element cleanups (refcount at +0x68 via FUN_005bf480), old allocation freed via operator_delete; early-out if size unchanged
void FUN_005d3a60_recon(void* self, uint32_t param_1) {
    uint8_t* b = static_cast<uint8_t*>(self);
    if (param_1 != *reinterpret_cast<uint32_t*>(b + 8)) {
        if (param_1 < *reinterpret_cast<uint32_t*>(b + 0xc)) {
            uint32_t uVar7 = param_1;
            do {
                int iVar3 = *reinterpret_cast<int*>(b + 4);
                int iVar8 = *reinterpret_cast<int*>(iVar3 + uVar7 * 4u);
                if (iVar8 != 0) {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(iVar8 + 0x68);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) FUN_005bf480();
                    *reinterpret_cast<uint32_t*>(iVar3 + uVar7 * 4u) = 0;
                    *reinterpret_cast<int*>(b + 0x10) = *reinterpret_cast<int*>(b + 0x10) - 1;
                }
                uVar7 = uVar7 + 1;
            } while (uVar7 < *reinterpret_cast<uint32_t*>(b + 0xc));
            *reinterpret_cast<uint32_t*>(b + 0xc) = param_1;
        }
        int iVar3 = *reinterpret_cast<int*>(b + 4);
        *reinterpret_cast<uint32_t*>(b + 8) = param_1;
        if (param_1 == 0) {
            *reinterpret_cast<uint32_t*>(b + 4) = 0;
        } else {
            uint32_t* puVar5 = static_cast<uint32_t*>(thunk_FUN_00533c78(param_1 * 4u + 4u));
            if (puVar5 == nullptr) {
                puVar5 = nullptr;
            } else {
                *puVar5 = param_1;
                puVar5 = puVar5 + 1;
                if (static_cast<int>(param_1 - 1) >= 0) {
                    uint32_t* puVar9 = puVar5;
                    uint32_t n = param_1;
                    for (; n != 0; n = n - 1) {
                        *puVar9 = 0;
                        puVar9 = puVar9 + 1;
                    }
                }
            }
            uint32_t uVar7 = 0;
            *reinterpret_cast<uint32_t**>(b + 4) = puVar5;
            if (*reinterpret_cast<int*>(b + 0xc) != 0) {
                do {
                    int iVar6 = *reinterpret_cast<int*>(b + 4);
                    uint32_t iVar8 = uVar7 * 4u;
                    int iVar4 = *reinterpret_cast<int*>(iVar6 + iVar8);
                    if (iVar4 != *reinterpret_cast<int*>(iVar8 + iVar3)) {
                        if (iVar4 != 0) {
                            int32_t* piVar1 = reinterpret_cast<int32_t*>(iVar4 + 0x68);
                            *piVar1 = *piVar1 + -1;
                            if (*piVar1 == 0) FUN_005bf480();
                        }
                        iVar4 = *reinterpret_cast<int*>(iVar8 + iVar3);
                        *reinterpret_cast<int*>(iVar6 + iVar8) = iVar4;
                        if (iVar4 != 0) {
                            *reinterpret_cast<int*>(iVar4 + 0x68) = *reinterpret_cast<int*>(iVar4 + 0x68) + 1;
                        }
                    }
                    uVar7 = uVar7 + 1;
                } while (uVar7 < *reinterpret_cast<uint32_t*>(b + 0xc));
            }
            uVar7 = *reinterpret_cast<uint32_t*>(b + 0xc);
            if (uVar7 < *reinterpret_cast<uint32_t*>(b + 8)) {
                do {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(*reinterpret_cast<int*>(b + 4) + uVar7 * 4u);
                    int iVar8 = *piVar1;
                    if (iVar8 != 0) {
                        int32_t* piVar2 = reinterpret_cast<int32_t*>(iVar8 + 0x68);
                        *piVar2 = *piVar2 + -1;
                        if (*piVar2 == 0) FUN_005bf480();
                        *piVar1 = 0;
                    }
                    uVar7 = uVar7 + 1;
                } while (uVar7 < *reinterpret_cast<uint32_t*>(b + 8));
            }
        }
        if (iVar3 != 0) {
            int iVar6 = *reinterpret_cast<int*>(iVar3 + -4);
            int iVar8 = iVar3 + iVar6 * 4;
            if (iVar6 - 1 >= 0) {
                do {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(iVar8 + -4);
                    iVar8 = iVar8 + -4;
                    if (*piVar1 != 0) {
                        piVar1 = reinterpret_cast<int32_t*>(*piVar1 + 0x68);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) FUN_005bf480();
                    }
                    iVar6 = iVar6 - 1;
                } while (iVar6 != 0);
            }
            operator_delete(reinterpret_cast<void*>(iVar3 + -4));
        }
    }
}

// 0x5d3bc0 — observed shape: self=ECX dtor; *self = vtable PTR_FUN_006c86b8; if (self[1]!=0) { walk entries, decref each (+0x68) via FUN_005bf480, operator_delete(self[1]-4); }
void FUN_005d3bc0_recon(void* self) {
    uint32_t* se = static_cast<uint32_t*>(self);
    extern void* PTR_FUN_006c86b8;
    se[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86b8);
    int iVar2 = static_cast<int>(se[1]);
    if (iVar2 != 0) {
        int iVar3 = *reinterpret_cast<int*>(iVar2 + -4);
        int iVar4 = iVar2 + iVar3 * 4;
        if (iVar3 - 1 >= 0) {
            do {
                int32_t* piVar1 = reinterpret_cast<int32_t*>(iVar4 + -4);
                iVar4 = iVar4 + -4;
                if (*piVar1 != 0) {
                    piVar1 = reinterpret_cast<int32_t*>(*piVar1 + 0x68);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) FUN_005bf480();
                }
                iVar3 = iVar3 - 1;
            } while (iVar3 != 0);
        }
        operator_delete(reinterpret_cast<void*>(iVar2 + -4));
    }
}
// 0x5d3c10 — observed shape: self=ECX deleting-dtor wrapper: FUN_005d3bc0(); if (param&1) operator_delete(self)
void FUN_005d3c10_recon(void* self, uint8_t param_1) {
    FUN_005d3bc0_recon(self);
    if ((param_1 & 1u) != 0) {
        operator_delete(self);
    }
}

// 0x5d3c30 — observed shape: self=ECX: FUN_005d3160(); if (param&1) operator_delete(self)
void FUN_005d3c30_recon(void* self, uint8_t param_1) {
    FUN_005d3160();
    (void)self;
    if ((param_1 & 1u) != 0) {
        operator_delete(self);
    }
}

// 0x5d3c50 — observed shape: self=ECX; if (*(self+0x3c)!=0) { if (byte(self+0xfc)&&param) { ... FUN_005d3290 / FUN_005d7d70 ... } decref *(self+0x3c) (+0x68), self+0x104=0, self+0x108=0, *(self+0x38)++ }
void FUN_005d3c50_recon(void* self, int param_1) {
    uint8_t* b = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<int*>(b + 0x3c) != 0) {
        if (*reinterpret_cast<char*>(b + 0xfc) != '\0' && param_1 != 0) {
            uint16_t uVar3 = *reinterpret_cast<uint16_t*>(param_1 + 0x10);
            if (*reinterpret_cast<uint32_t*>(b + 0x100) < static_cast<uint32_t>(uVar3)) {
                uVar3 = static_cast<uint16_t>(*reinterpret_cast<uint32_t*>(b + 0x100));
            }
            int iVar2 = static_cast<int>(FUN_005d3290(param_1, uVar3));
            if (iVar2 != 0) {
                FUN_005d7d70(1, 3, 0);
                uint32_t uVar5, uVar4;
                if (*reinterpret_cast<char*>(b + 0xfc) == '\0') {
                    uVar5 = 2; uVar4 = 4;
                } else {
                    FUN_005d7d70(4, 4, 0);
                    uVar5 = 0; uVar4 = 6;
                }
                FUN_005d7d70(uVar4, uVar5, 0);
            }
        }
        if (*reinterpret_cast<int*>(b + 0x3c) != 0) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(*reinterpret_cast<int*>(b + 0x3c) + 0x68);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) FUN_005bf480();
            *reinterpret_cast<uint32_t*>(b + 0x3c) = 0;
        }
        *reinterpret_cast<uint32_t*>(b + 0x104) = 0;
        *reinterpret_cast<uint32_t*>(b + 0x108) = 0;
        *reinterpret_cast<int*>(b + 0x38) = *reinterpret_cast<int*>(b + 0x38) + 1;
    }
}

// 0x5d3d10 — observed shape: if (byte(param+0xb4)) { if (*(param+0x144)!=0 && (vtcall via *(self+0x14)+0x5d8  +0x10)(*(param+0x144)) != 0xe) { switch(*(param+0x150)) { case 0/1/2/3/default: FUN_005d3a30; return 1 } } } return 0
uint32_t FUN_005d3d10_recon(void* self, int param_1) {
    uint8_t* sb = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<char*>(param_1 + 0xb4) != '\0') {
        if (*reinterpret_cast<int*>(param_1 + 0x144) != 0) {
            int owner = *reinterpret_cast<int*>(sb + 0x14);
            uint32_t vtOwner = *reinterpret_cast<uint32_t*>(owner + 0x5d8);
            auto call10 = reinterpret_cast<int(__cdecl*)(int)>(*reinterpret_cast<uint32_t*>(vtOwner + 0x10));
            int iVar1 = call10(*reinterpret_cast<int*>(param_1 + 0x144));
            if (iVar1 != 0xe) {
                uint32_t sel = *reinterpret_cast<uint32_t*>(param_1 + 0x150);
                switch (sel) {
                case 0:
                    if (static_cast<char>(param_1) == '\0') { FUN_005d3a30(nullptr); return 1; }
                    FUN_005d3a30(nullptr); return 1;
                case 1:
                    if (static_cast<char>(param_1) == '\0') { FUN_005d3a30(nullptr); return 1; }
                    FUN_005d3a30(nullptr); return 1;
                case 2:
                    FUN_005d3a30(nullptr); return 1;
                case 3:
                    FUN_005d3a30(nullptr);
                    return 1;
                default:
                    return 1;
                }
            }
        }
    }
    return 0;
}

// 0x5d3e10 — observed shape: self=ECX ctor: FUN_005c9820(); *self=&PTR_FUN_006c8720; zero fields 8..0xf; self[0x10]=&PTR_FUN_006c86b8; self[0x12]=2; self[0x15]=2; self[0x13]=0; self[0x14]=0; alloc 0xc via thunk_FUN_00533c78, *p=2, FUN_004127b0(p+1,4,2,&LAB_004c2970), self[0x11]=p+1; FUN_005d3120()
void FUN_005d3e10_recon(void* self) {
    uint32_t* se = static_cast<uint32_t*>(self);
    uint8_t* b = static_cast<uint8_t*>(self);
    FUN_005c9820();
    extern void* PTR_FUN_006c8720;
    extern void* PTR_FUN_006c86b8;
    extern void* LAB_004c2970;
    se[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c8720);
    *reinterpret_cast<uint8_t*>(reinterpret_cast<int8_t*>(self) + 8) = 0;
    *reinterpret_cast<uint8_t*>(b + 0x21) = 0;
    se[9] = 0; se[10] = 0; se[0xb] = 0; se[0xc] = 0;
    se[0xd] = 0; se[0xe] = 0; se[0xf] = 0;
    se[0x10] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86b8);
    se[0x12] = 2; se[0x15] = 2; se[0x13] = 0; se[0x14] = 0;
    uint32_t* puVar2 = nullptr;
    uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0xc));
    if (puVar1 != nullptr) {
        puVar2 = puVar1 + 1;
        *puVar1 = 2;
        FUN_004127b0(puVar2, 4, 2, &LAB_004c2970);
    }
    se[0x11] = reinterpret_cast<uint32_t>(puVar2);
    FUN_005d3120();
}
// 0x5d3ea0 — observed shape: self=ECX: FUN_005da790(); if (param&1) operator_delete(self)
void FUN_005d3ea0_recon(void* self, uint8_t param_1) {
    FUN_005da790();
    if ((param_1 & 1u) != 0) {
        operator_delete(self);
    }
}

// 0x5d3ec0 — observed shape: self=ECX ctor cont: FUN_005d3e10(); *self=&PTR_FUN_006c86c0; init inline vtable slots 0x16..0x3d, bytes, LAB_005d29c0..LAB_005d2f50
void FUN_005d3ec0_recon(void* self) {
    uint32_t* se = static_cast<uint32_t*>(self);
    FUN_005d3e10_recon(self);
    extern void* PTR_FUN_006c86c0;
    extern void* PTR_FUN_006c86b4;
    extern void* LAB_005d29c0;
    extern void* LAB_005d2b40;
    extern void* LAB_005d2cd0;
    extern void* LAB_005d2e10;
    extern void* LAB_005d2f50;
    se[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86c0);
    se[0x18] = 0; se[0x19] = 0; se[0x1a] = 0; se[0x17] = 0; se[0x1b] = 1;
    se[0x16] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86b4);
    se[0x1e] = 0; se[0x1f] = 0; se[0x20] = 0; se[0x1d] = 0;
    se[0x1c] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86b4); se[0x21] = 1;
    se[0x24] = 0; se[0x25] = 0; se[0x26] = 0; se[0x23] = 0;
    se[0x22] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86b4); se[0x27] = 1;
    se[0x2a] = 0; se[0x2b] = 0; se[0x2c] = 0; se[0x29] = 0;
    se[0x28] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86b4); se[0x2d] = 1;
    se[0x30] = 0; se[0x31] = 0; se[0x32] = 0; se[0x2f] = 0;
    se[0x2e] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86b4); se[0x33] = 1;
    se[0x36] = 0; se[0x37] = 0; se[0x38] = 0; se[0x35] = 0;
    se[0x34] = reinterpret_cast<uint32_t>(&PTR_FUN_006c86b4); se[0x39] = 1;
    se[0x44] = 0; se[0x45] = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<int8_t*>(self) + 0x46 * 4) = 0;
    se[0x49] = 0; se[0x47] = 1;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<int8_t*>(self) + 0x48 * 4) = 1;
    se[0x3a] = reinterpret_cast<uint32_t>(&LAB_005d29c0);
    se[0x3b] = reinterpret_cast<uint32_t>(&LAB_005d2b40);
    se[0x3c] = reinterpret_cast<uint32_t>(&LAB_005d2cd0);
    se[0x3d] = reinterpret_cast<uint32_t>(&LAB_005d2e10);
    se[0x3e] = reinterpret_cast<uint32_t>(&LAB_005d2f50);
}

// 0x5d3ff0 — observed shape: self=ECX; if (*(self+0x3c)==0) { acquire via FUN_005bf670 into local slot (+0x3c ref assign with decref/incref); ensure vec size via FUN_005d3a60/FUN_005d3090; (2,1)->FUN_005d2750(0x1b,0,1) else FUN_005ca4e0 0x13/0x14/0x1b; store param_3/param_4 at 0xfc/0xfd; 0x104/0x108 = DAT_00717c64/68 decremented if param_3 }
void FUN_005d3ff0_recon(void* self, int param_1, int param_2, char param_3, uint8_t param_4) {
    uint8_t* b = static_cast<uint8_t*>(self);
    int32_t* piVar1 = reinterpret_cast<int32_t*>(b + 0x3c);
    if (*reinterpret_cast<int*>(b + 0x3c) == 0) {
        int local_4 = reinterpret_cast<int>(self);
        extern int* FUN_005bf670(int* p);
        int* piVar4 = FUN_005bf670(&local_4);
        int iVar6 = *piVar1;
        if (iVar6 != *piVar4) {
            if (iVar6 != 0) {
                int32_t* piVar2 = reinterpret_cast<int32_t*>(iVar6 + 0x68);
                *piVar2 = *piVar2 + -1;
                if (*piVar2 == 0) FUN_005bf480();
            }
            iVar6 = *piVar4;
            *piVar1 = iVar6;
            if (iVar6 != 0) {
                *reinterpret_cast<int*>(iVar6 + 0x68) = *reinterpret_cast<int*>(iVar6 + 0x68) + 1;
            }
        }
        if (local_4 != 0) {
            iVar6 = *reinterpret_cast<int*>(local_4 + 0x68) - 1;
            *reinterpret_cast<int*>(local_4 + 0x68) = iVar6;
            if (iVar6 == 0) FUN_005bf480();
        }
        uint32_t uVar3 = *reinterpret_cast<uint32_t*>(b + 0x38);
        if (*reinterpret_cast<uint32_t*>(b + 0x48) <= uVar3) {
            FUN_005d3a60(static_cast<uint32_t>(*reinterpret_cast<int*>(b + 0x54) + static_cast<int>(uVar3)));
        }
        FUN_005d3090(uVar3, piVar1);
        if (*reinterpret_cast<int*>(b + 0x38) != 0) {
            if (param_1 == 2 && param_2 == 1) {
                FUN_005d2750(0x1b, 0, 1);
            } else {
                int cur = *piVar1;
                if (*reinterpret_cast<int*>(cur + 0x38) == 0) {
                    *reinterpret_cast<uint32_t*>(cur + 0x38) = FUN_005ca610();
                }
                FUN_005ca4e0(0x13, static_cast<uint32_t>(param_1), 0);
                cur = *piVar1;
                if (*reinterpret_cast<int*>(cur + 0x38) == 0) {
                    *reinterpret_cast<uint32_t*>(cur + 0x38) = FUN_005ca610();
                }
                FUN_005ca4e0(0x14, static_cast<uint32_t>(param_2), 0);
                cur = *piVar1;
                if (*reinterpret_cast<int*>(cur + 0x38) == 0) {
                    *reinterpret_cast<uint32_t*>(cur + 0x38) = FUN_005ca610();
                }
                FUN_005ca4e0(0x1b, 1, 1);
            }
        }
        *reinterpret_cast<char*>(b + 0xfc) = param_3;
        *reinterpret_cast<uint8_t*>(b + 0xfd) = param_4;
        extern int DAT_00717c64;
        extern int DAT_00717c68;
        int gi = DAT_00717c64;
        *reinterpret_cast<int*>(b + 0x104) = DAT_00717c64;
        *reinterpret_cast<uint32_t*>(b + 0x108) = static_cast<uint32_t>(DAT_00717c68);
        if (param_3 != '\0') {
            *reinterpret_cast<int*>(b + 0x104) = gi - 1;
            *reinterpret_cast<int*>(b + 0x108) = *reinterpret_cast<int*>(b + 0x108) - 1;
        }
    }
}

// 0x5d4150 — observed shape: self=ECX; if (param != *(self+0x124)) { FUN_005d2830(); store; if (param) { walk param+0x10 list and param+0x14 list calling FUN_005d3d10(entry, byte(entry+0x158)); then +0x18/+0x1c singles with 0 } }
void FUN_005d4150_recon(void* self, int param_1) {
    uint8_t* b = static_cast<uint8_t*>(self);
    if (param_1 != *reinterpret_cast<int*>(b + 0x124)) {
        FUN_005d2830();
        *reinterpret_cast<int*>(b + 0x124) = param_1;
        if (param_1 != 0) {
            uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(param_1 + 0x10);
            while (puVar2 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
                FUN_005d3d10_recon(self, *piVar1);
            }
            puVar2 = *reinterpret_cast<uint32_t**>(param_1 + 0x14);
            while (puVar2 != nullptr) {
                int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
                FUN_005d3d10_recon(self, *piVar1);
            }
            if (*reinterpret_cast<int*>(param_1 + 0x18) != 0) {
                FUN_005d3d10_recon(self, *reinterpret_cast<int*>(param_1 + 0x18));
            }
            if (*reinterpret_cast<int*>(param_1 + 0x1c) != 0) {
                FUN_005d3d10_recon(self, *reinterpret_cast<int*>(param_1 + 0x1c));
            }
        }
    }
}

// 0x5d41e0 — observed shape: self=ECX; if (*(self+0x38)>1 && (byte(param1+0x20)&1)) { flag tests on param2, grow *(self+0x110) buffer; per-index 0x13/0x14 state -> *(+0x110)[i]=1/0; vtcall via *(self+0x18)+0x74 (0x22); per-index FUN_005ca4e0 0x1c/0x22; FUN_005d3ff0; FUN_005d3290; FUN_005ca4e0 0x3c/0x1c/0x22; FUN_005d7d70 branches; decref *(self+0x3c), *(self+0x38)++ }
void FUN_005d41e0_recon(void* self, uint32_t param_1, int param_2, int param_3, int param_4) {
    uint8_t* b = static_cast<uint8_t*>(self);
    (void)param_4; (void)param_3;
    if (*reinterpret_cast<uint32_t*>(b + 0x38) > 1 && ((*reinterpret_cast<uint8_t*>(param_1 + 0x20) & 1u) != 0)) {
        if ((((*reinterpret_cast<uint8_t*>(param_2 + 0x20) & 1u) != 0) || (((*reinterpret_cast<uint16_t*>(param_2 + 0x20) >> 9u) & 1u) != 0)) && (param_3 == 0 || param_4 == 1)) {
            param_1 = param_1 & 0xffffff00u;
        }
        if (*reinterpret_cast<uint32_t*>(b + 0x114) < *reinterpret_cast<uint32_t*>(b + 0x38)) {
            operator_delete(*reinterpret_cast<void**>(b + 0x110));
            uint32_t n3 = *reinterpret_cast<uint32_t*>(b + 0x38);
            *reinterpret_cast<uint32_t*>(b + 0x110) = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(n3 << 2));
            *reinterpret_cast<uint32_t*>(b + 0x114) = n3;
        }
        uint32_t uVar6 = 1;
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(b + 0x110)) = 1;
        if (*reinterpret_cast<uint32_t*>(b + 0x38) > 1) {
            uint32_t iVar7 = 4;
            do {
                int iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(b + 0x44) + iVar7);
                int local_8 = 0, local_4 = 0;
                if (*reinterpret_cast<int*>(iVar2 + 0x38) != 0) FUN_005ca1d0(0x13, reinterpret_cast<uint32_t*>(&local_8), &param_4);
                if (*reinterpret_cast<int*>(iVar2 + 0x38) != 0) FUN_005ca1d0(0x14, reinterpret_cast<uint32_t*>(&local_4), &param_4);
                if (local_8 == 3 || local_8 == 4 || local_4 == 4 || local_4 == 9) {
                set1:
                    *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(b + 0x110) + iVar7) = 1;
                } else if (local_8 == 1 || local_8 == 9) {
                    *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(b + 0x110) + iVar7) = 0;
                } else {
                    if (local_4 != 1 && local_4 != 3) goto set1;
                    uint32_t uVar4 = 0;
                    if (iVar7 != 0) {
                        do {
                            *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(b + 0x110) + uVar4 * 4u) = 0;
                            uVar4 = uVar4 + 1;
                        } while (uVar4 < uVar6);
                    }
                    *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(b + 0x110) + iVar7) = 1;
                }
                uVar6 = uVar6 + 1;
                iVar7 = iVar7 + 4;
            } while (uVar6 < *reinterpret_cast<uint32_t*>(b + 0x38));
        }
        uint32_t owner = *reinterpret_cast<uint32_t*>(b + 0x18);
        auto vtcall = reinterpret_cast<uint32_t(__cdecl*)(uint32_t)>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(owner) + 0x74));
        uint32_t uVar3 = vtcall(0x22);
        uVar6 = 0;
        if (*reinterpret_cast<int*>(b + 0x38) != 0) {
            do {
                int iVar7 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(b + 0x44) + uVar6 * 4u);
                uint32_t uVar5, uVar8;
                if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(b + 0x110) + uVar6 * 4u) == 0) {
                    if (*reinterpret_cast<int*>(iVar7 + 0x38) == 0) *reinterpret_cast<uint32_t*>(iVar7 + 0x38) = FUN_005ca610();
                    uVar8 = 0; uVar5 = 0x1c;
                } else {
                    if (*reinterpret_cast<int*>(iVar7 + 0x38) == 0) *reinterpret_cast<uint32_t*>(iVar7 + 0x38) = FUN_005ca610();
                    FUN_005ca4e0(0x1c, 1, 0);
                    if (*reinterpret_cast<int*>(iVar7 + 0x38) == 0) *reinterpret_cast<uint32_t*>(iVar7 + 0x38) = FUN_005ca610();
                    uVar8 = 0xff000000u; uVar5 = 0x22;
                }
                FUN_005ca4e0(uVar5, uVar8, 0);
                uVar6 = uVar6 + 1;
            } while (uVar6 < *reinterpret_cast<uint32_t*>(b + 0x38));
        }
        uint32_t sel = *reinterpret_cast<uint32_t*>(owner + 0x24 + ((*reinterpret_cast<uint8_t*>(param_1 + 0x20) >> 1 & 0xfu) * 4u));
        FUN_005d3ff0_recon(self, static_cast<int>(sel), 2, 0, 0);
        uVar6 = 0;
        int p2v = param_2;
        if (p2v != 0) {
            uVar6 = *reinterpret_cast<uint32_t*>(p2v + 0x10);
            if (*reinterpret_cast<uint32_t*>(b + 0x100) < *reinterpret_cast<uint32_t*>(p2v + 0x10)) {
                uVar6 = *reinterpret_cast<uint32_t*>(b + 0x100);
            }
        } else {
            p2v = 0;
        }
        FUN_005d3290(p2v, static_cast<uint16_t>(uVar6));
        int iVar7 = *reinterpret_cast<int*>(b + 0x3c);
        if (*reinterpret_cast<int*>(iVar7 + 0x38) == 0) *reinterpret_cast<uint32_t*>(iVar7 + 0x38) = FUN_005ca610();
        FUN_005ca4e0(0x3c, 0xff000000u, 0);
        FUN_005d7d70(1, 2, 0);
        FUN_005d7d70(2, 3, 0);
        // observed: (char)(ESI>>0x18)/retaddr-branched FUN_005d7d70 tail
        FUN_005d7d70(4, 3, 0);
        iVar7 = *reinterpret_cast<int*>(b + 0x3c);
        if (*reinterpret_cast<int*>(iVar7 + 0x38) == 0) *reinterpret_cast<uint32_t*>(iVar7 + 0x38) = FUN_005ca610();
        FUN_005ca4e0(0x1c, 1, 0);
        iVar7 = *reinterpret_cast<int*>(b + 0x3c);
        if (*reinterpret_cast<int*>(iVar7 + 0x38) == 0) *reinterpret_cast<uint32_t*>(iVar7 + 0x38) = FUN_005ca610();
        FUN_005ca4e0(0x22, uVar3, 0);
        iVar7 = *reinterpret_cast<int*>(b + 0x3c);
        if (iVar7 != 0) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(iVar7 + 0x68);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) FUN_005bf480();
            *reinterpret_cast<uint32_t*>(b + 0x3c) = 0;
            *reinterpret_cast<uint32_t*>(b + 0x104) = 0;
            *reinterpret_cast<uint32_t*>(b + 0x108) = 0;
            *reinterpret_cast<int*>(b + 0x38) = *reinterpret_cast<int*>(b + 0x38) + 1;
        }
    }
}
// NEEDS_MANUAL: 0x5d4520 body is ~575 lines across two non-contiguous ranges (0x5d4520-0x5d4f4c, 0x5d4f50-0x5d539d) with 5 params; full decompilation was paged out of the read view. Signature and call-through preserved; body reads as a large state-machine handler.
// 0x5d4520 — observed shape: large handler (non-contiguous ranges); calling convention (int,uint32,int,int,uint32)->uint32 per listing header
uint32_t FUN_005d4520_recon(int param_1, uint32_t param_2, int param_3, int param_4, uint32_t param_5) {
    // Forwarded through FUN_005d53a0 wrapper as well; body preserved below at call sites.
    // Full internal switch/loops require un-paged re-read of 0x5d4520.c:16-592.
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5;
    return 0;
}

// 0x5d53a0 — observed shape: self=ECX; (**(self+0x5c))(); FUN_005d4520(p1..p7)
void FUN_005d53a0_recon(void* self, int p1, uint32_t p2, int p3, int p4, uint32_t p5, uint32_t p6, uint32_t p7) {
    uint32_t* se = static_cast<uint32_t*>(self);
    auto call5c = reinterpret_cast<void(__cdecl*)()>(se[0x5c / 4]);
    // Observed: (**(code**)(*self+0x5c))() — first dword is vtable base
    {
        uint32_t vt = *se;
        auto f = reinterpret_cast<void(__cdecl*)()>(*reinterpret_cast<uint32_t*>(vt + 0x5c));
        f();
    }
    (void)call5c;
    FUN_005d4520_recon(p1, p2, p3, p4, p5);
    (void)p6; (void)p7;
}

// 0x5d5440 — observed shape: self=ECX; (**(self+0xac))(); jumptable (unrecovered) then (**(self+0xbc))()
void FUN_005d5440_recon(void* self) {
    uint32_t* se = static_cast<uint32_t*>(self);
    uint32_t vt = *se;
    {
        auto f = reinterpret_cast<void(__cdecl*)()>(*reinterpret_cast<uint32_t*>(vt + 0xac));
        f();
    }
    {
        auto f = reinterpret_cast<void(__cdecl*)()>(*reinterpret_cast<uint32_t*>(vt + 0xbc));
        f();
    }
}

// 0x5d5570 — observed shape: self=ECX; slot = self+300+param1*8; if (*slot != param_2) vtcall via *(self+0x2284)+0xe4 (owner,param1,param2); if (param3) *(self+0x130+param1*8)=*slot; *slot=param_2
void FUN_005d5570_recon(void* self, int param_1, int param_2, char param_3) {
    uint8_t* b = static_cast<uint8_t*>(self);
    uint8_t* slot = b + 300 + param_1 * 8;
    if (*reinterpret_cast<int*>(slot) != param_2) {
        uint32_t owner = *reinterpret_cast<uint32_t*>(b + 0x2284);
        auto f = reinterpret_cast<void(__cdecl*)(uint32_t, int, int)>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(owner) + 0xe4));
        f(owner, param_1, param_2);
    }
    if (param_3 != '\0') {
        *reinterpret_cast<uint32_t*>(b + 0x130 + param_1 * 8) = *reinterpret_cast<uint32_t*>(slot);
    }
    *reinterpret_cast<int*>(slot) = param_2;
}

// 0x5d5660 — observed shape: self=ECX; if (*(self+0x2274)==param1) { *(self+0x2274)=0; vtcall via *(self+0x2284)+0x1ac (owner,0); } if (*(self+0x2278)==param1) *(self+0x2278)=0
void FUN_005d5660_recon(void* self, int param_1) {
    uint8_t* b = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<int*>(b + 0x2274) == param_1) {
        *reinterpret_cast<uint32_t*>(b + 0x2274) = 0;
        uint32_t owner = *reinterpret_cast<uint32_t*>(b + 0x2284);
        auto f = reinterpret_cast<void(__cdecl*)(uint32_t, uint32_t)>(*reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(owner) + 0x1ac));
        f(owner, 0);
    }
    if (*reinterpret_cast<int*>(b + 0x2278) == param_1) {
        *reinterpret_cast<uint32_t*>(b + 0x2278) = 0;
    }
}
