// Reconstruction batch mass_0014 — Sid Meier's Pirates! (2004), PE32 i386.
// Sources: analysis/pseudocode/functions/0x4534b0.c, 0x4536d0.c, 0x453810.c,
// 0x453890.c, 0x4538d0.c, 0x453a20.c, 0x4544e0.c, 0x4547d0.c, 0x454a30.c,
// 0x454af0.c, 0x455ca0.c, 0x456990.c, 0x456b20.c, 0x457100.c, 0x457190.c,
// 0x459f80.c, 0x45a050.c, 0x45a0b0.c, 0x45a120.c, 0x45a160.c.
// Unverified decompiler-derived candidates; field offsets, constants, call
// order, return shapes and conditional structure follow the listed corpus.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

// ---- Observed globals used by this batch (corpus labels) ----
extern int32_t DAT_008ca9b0, DAT_008ca9ac, DAT_008ca9b4, DAT_007255c0, DAT_007263bc;
extern uint32_t DAT_008dc978, DAT_0085a26c, DAT_0085a268;
extern int32_t DAT_00726a84, DAT_00726820, DAT_007268f4[];
extern uint8_t DAT_00726813[], DAT_00726814[], DAT_00725d98, DAT_008c9df4;
extern uint32_t* DAT_008dc96c, DAT_008dc970, DAT_008dc974, DAT_008dc97c;
extern uint8_t DAT_008c827f, DAT_008c827e, DAT_008c9df4_, DAT_008e8eff, DAT_008cac27, DAT_008cac26;
extern uint8_t DAT_008c8288[], DAT_00862008[], DAT_00861ff8[], DAT_00862014, DAT_00862018[], DAT_008cacc8[];
extern uint32_t DAT_008ea008, DAT_00727444, DAT_00726638, DAT_0072663c, DAT_0086c330;
extern uint8_t DAT_00869b48[], DAT_00704c70[], DAT_008cacd0[], DAT_008caccc, DAT_008cacc8_, DAT_006f5814[];
extern uint8_t DAT_008cacd8[], DAT_008c9568[], DAT_0072c774, DAT_0085a158, DAT_00869b14;
extern uint8_t DAT_00869a88[], DAT_00869a98[], DAT_00869b1c, DAT_00869b1e, DAT_0085a164_, _DAT_0085a164, _DAT_008ed61c;
extern uint32_t DAT_0085a164, _DAT_008ed61c_, DAT_00726380, DAT_0072637c, DAT_008cad20, DAT_0071779c;
extern int32_t DAT_00860b90[], DAT_0085bf78[], DAT_0085bf74[], DAT_00860b74[], DAT_006f5fe4[];
extern int32_t DAT_008620d8, DAT_008620bc, DAT_00862030, DAT_0086204c, DAT_00862068, DAT_00862084, DAT_008620a0, DAT_008620f4;
extern int32_t DAT_008c9568_, DAT_008c956c, DAT_008c9570, DAT_0085a11c, DAT_008cac18, DAT_008c9dd8, DAT_008c9de0;
extern uint32_t DAT_008ed618, DAT_0086bb5c, DAT_008c8430_, DAT_008c8494, DAT_008ecd78, DAT_008c9dec, DAT_008c97c0, DAT_008c97c4;
extern uint32_t DAT_008e9ffc, DAT_008e9fec, DAT_008ea000, DAT_008cabd4, DAT_007255f8, DAT_00727b28, DAT_008e8ec4, _DAT_008e8ec8, DAT_008e8eec, DAT_008e8ef0;
extern int32_t DAT_00814304, DAT_00814308, DAT_008b98c0, DAT_008b9900, DAT_008b9904, DAT_008b9908, DAT_008b990c, DAT_008b9910, DAT_008b9920[], DAT_008dd280[], DAT_0072cd80[];
extern uint8_t DAT_00814350[], DAT_00814330[], DAT_006fb738[], DAT_00007f02[], DAT_008c7320_, DAT_008c7340[], DAT_006f588c[];
extern uint8_t DAT_008c7320[], DAT_006f5896[], DAT_006fb6cc[], DAT_008cb100[], DAT_008cb104[], DAT_008cb108[], DAT_008d4658[], DAT_008bea80[];
extern uint8_t DAT_006f77a0[], DAT_00873bd0_, DAT_00872bd0, DAT_00869b48_, DAT_00874994_, DAT_00704ca0[], DAT_0085a26c_, DAT_0085a268_;
extern void* PTR_FUN_006fd14c, PTR_FUN_00704c70, PTR_DAT_00726640, PTR_FUN_006f5814, DAT_008cacd0_, DAT_008dc978_;
extern int32_t DAT_008cacc8__;

// ---- Observed callees (corpus labels; signatures inferred from call sites) ----
extern int FUN_005f0ddc();
extern int FUN_004af080(void*, int, int, int, int, int, int, int, int, int, int);
extern uint32_t FUN_004dadc0(int, int, int);
extern void FUN_004bbc80(int, int, int, void*, int, int, int);
extern int FUN_004bc0d0();
extern int FUN_00489130(void*);
extern void FUN_004a2080(int, int, int);
extern void FUN_004a21c0();
extern void FUN_00481100();
extern void FUN_00481140();
extern void FUN_004c1150(void*, const char*);
extern void FUN_004bef50();
extern void FUN_004ae4f0();
extern void operator_delete__(void*);
extern void FUN_0043fd70();
extern void* FUN_00533c78(int);
extern void FUN_004bdca0(uint32_t, int, int, int, int, int, int, int, int, int);
extern void* FUN_004baa30(uint32_t, const char*, int, int, int, int, int, int, int, int, int);
extern void FUN_004b24a0(void*, int);
extern void FUN_004bba60(void*, int, int, float, int);
extern void FUN_004b06c0(void*, int, int, int, int, int, int, int);
extern int FUN_0042c6f0();
extern void FUN_004f6090(const char*, ...);
extern void FUN_004f3350();
extern void FUN_004f8110(void*);
extern void FUN_004f8250(void*);
extern int FUN_004f4b20(void*, int, int, int);
extern uint32_t FUN_004fa6c0(uint32_t, void*, uint32_t);
extern uint32_t FUN_004f1220(int, int);
extern void FUN_00412970();
extern void FUN_00412b40();
extern void FUN_00412cb0();
extern void FUN_00412df0();
extern void FUN_004f2600(const char*, ...);
extern void FUN_004f6090_(const char*, ...);
extern void FUN_00402650(const char*, void*, void*, void*, int);
extern void FUN_00402770(const char*, int, void*, void*, int);
extern void FUN_004b20f0();
extern void FUN_004b2160();
extern void FUN_004b2170();
extern uint32_t FUN_004cddf0(const char*, int, int, void*, void*);
extern void FUN_004c2200(uint32_t, int);
extern void FUN_004c0940();
extern void FUN_004c1080();
extern void FUN_004c1150_(const char*);
extern void FUN_00487fd0(int, int);
extern void FUN_004879f0(int, int);
extern void FUN_00456990(uint32_t);
extern void* FUN_00456b20(uint32_t);
extern void FUN_00457100(uint32_t);
extern void FUN_004538d0();
extern void FUN_004544e0(void*);
extern void FUN_004547d0(void*, void*);
extern void FUN_00454a30();
extern void FUN_0045a050(void*);
extern void FUN_0045a0b0(void*, int, uint32_t);
extern void FUN_0045a120(uint32_t);
extern int FUN_0045a160();
extern void FUN_004bc160();
extern void FUN_004db210();
extern void FUN_004db270();
extern void FUN_004e7510(float, float, int);
extern void FUN_004e3450();
extern void FUN_004892c0();
extern void FUN_00488840(const char*, int);
extern void FUN_00485630();
extern void* FUN_004c1150__(void*, const char*);
extern void FUN_00422940();
extern int FUN_004dde20();
extern void FUN_004d9740();
extern void FUN_004d96a0();
extern void FUN_004d9af0();
extern void FUN_004d0cd0(int, int, int);
extern void FUN_004af680(void*);
extern void FUN_004add70();
extern void FUN_00425ad0(void*, void*);
extern void FUN_00427f80();
extern void FUN_00428140();
extern void FUN_004e4580();
extern void FUN_00451e50();
extern void FUN_0041a300();
extern void FUN_00412ec0();
extern void FUN_0041a9f0();
extern void FUN_00419ac0();
extern void FUN_004baaa0();
extern void FUN_004a22f0();
extern void FUN_004841b0();
extern void FUN_00483b70();
extern void FUN_00483ca0();
extern void FUN_00430190(int, int, const char*, int, int, int, int, int, int, int);
extern void FUN_004889c0(void*, int, int, int, int, float, int);
extern void FUN_0049af70();
extern void FUN_004a0b70();
extern void FUN_0049aed0();
extern void FUN_00498850();
extern void FUN_00488d90();
extern void FUN_00488ed0();
extern void FUN_00485390();
extern void FUN_004d8ee0();
extern void FUN_004d9af0();
extern int FUN_00412f10();
extern int FUN_00412f70();
extern int FUN_00412f90();
extern int FUN_004127b0(void*, int, int, void*);
extern void FUN_0042e730();
extern int FUN_0045a160_();
extern int FUN_0042e1d0(void*);
extern int FUN_004b2760(int);
extern void FUN_004bbb80(void*, int, int, int, int, int, int);
extern void FUN_00456dd0();
extern void FUN_00453b70();
extern int FUN_004eea30();
extern void FUN_005f0ddc_();
extern void FUN_004e8100();
extern void FUN_00481180();
extern void FUN_0045a050_();
extern void FUN_00441280();
extern void FUN_004413c0();
extern void FUN_0040a610();
extern void FUN_00453b70();
extern int FUN_00488ed0_();
extern void* FUN_004ce080(void*);
extern void FUN_004129c0(void*, void*, void*, void*);
extern void* FUN_00412a60(void*, void*);
extern uint32_t* FUN_004f1930(void*, int, int);
extern uint32_t* FUN_004f1840();
extern uint32_t* FUN_004f18c0(void*, int);
extern int FUN_004f31c0(void*, int);
extern void FUN_005096b0();
extern void FUN_00508190();
extern void* FUN_00508120();
extern void FUN_00508670(void*);
extern void FUN_00508340(void*);
extern void FUN_005b9e4d();
extern void FUN_005f0ddc__();

// Helpers declared by the batch for callee fidelity
typedef void (__cdecl *VCall)(void* self, int arg);
static inline void CallV(void* obj, int arg) {
    if (!obj) return;
    uint32_t* p = (uint32_t*)obj;
    VCall f = (VCall)(*(void**)p)[0];
    if (f) f(obj, arg);
}
static inline void ReleaseRef(uint32_t* p) {
    if (!p) return;
    int32_t c = (int32_t)p[1] - 1;
    p[1] = (uint32_t)c;
    if (c == 0) CallV(p, 1);
}

// 0x4534b0 — observed shape
void FUN_004534b0() {
    int iVar1;
    unsigned int uVar2;
    uint32_t uVar3;
    uint8_t local_24[36];
    iVar1 = FUN_005f0ddc();
    DAT_008ca9b0 = DAT_008ca9b0 - iVar1;
    DAT_008ca9ac = DAT_008ca9ac - iVar1;
    FUN_004af080((void*)DAT_008dc978, 0, 0, 0x400, 0x300, 0, 0, (int)DAT_0085a26c, (int)DAT_0085a268, 0xffffffff, 0x200);
    DAT_007263bc = DAT_007263bc | 0x1000;
    FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0, 0, 0, local_24, 100, 0xffffffff, DAT_008ca9ac);
    if (DAT_008ca9b4 != -1) {
        FUN_004bc0d0();
    }
    iVar1 = FUN_005f0ddc();
    if (iVar1 <= DAT_008ca9b0) {
        if (DAT_007255c0 == -1) {
            if (DAT_008ca9b4 == 0) {
                iVar1 = rand();
                if (0x3e5 < iVar1 % 1000) {
                    DAT_008ca9b0 = 0;
                    iVar1 = FUN_004bc0d0();
                    if (iVar1 == 0) {
                        DAT_008ca9b4 = 3;
                    } else {
                        uVar2 = (unsigned int)rand();
                        uVar2 = uVar2 & 0x80000001;
                        if ((int)uVar2 < 0) {
                            uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
                        }
                        DAT_008ca9b4 = (int)(uVar2 + 2);
                    }
                    if (DAT_008c827f != '\0') {
                        FUN_00489130(DAT_008c8288);
                        DAT_008c827f = '\0';
                    }
                    FUN_004a2080(0xffffffff, 0xffffffff, 0xffffffff);
                    FUN_004a21c0();
                }
            } else {
                DAT_008ca9b4 = 0;
                DAT_008ca9b0 = 0;
            }
        } else {
            DAT_008ca9b0 = 0;
            DAT_008ca9b4 = DAT_007255c0;
            DAT_007255c0 = -1;
        }
    }
    FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0, 0, 0, local_24, 100, DAT_008ca9b4, DAT_008ca9b0);
    uVar3 = FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0x14, 0xffffffec, 0, (void*)(uintptr_t)uVar3, 100, 0x3e9, DAT_008ca9ac);
}

// 0x4536d0 — observed shape
void FUN_004536d0() {
    char cVar1;
    uint32_t* puVar2;
    int iVar3;
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = (int32_t)DAT_007268f4[DAT_00726a84];
    iVar3 = DAT_00726820 + -1;
    cVar1 = (char)DAT_00726813[DAT_00726820];
    DAT_00726820 = iVar3;
    if (cVar1 != (char)DAT_00725d98) {
        if (cVar1 == '\0') {
            FUN_00481100();
        } else {
            FUN_00481140();
        }
    }
    DAT_008c9df4 = 1;
    DAT_00725d98 = (uint8_t)cVar1;
    FUN_004c1150((void*)DAT_008dc974, "fx_candle");
    FUN_004bef50();
    FUN_004ae4f0();
    puVar2 = DAT_008dc96c;
    if (DAT_008dc96c != nullptr) {
        iVar3 = (int)DAT_008dc96c[1];
        DAT_008dc96c[1] = (uint32_t)(iVar3 + -1);
        if (iVar3 + -1 == 0) {
            (**(void(**)(uint32_t*))(*puVar2))(puVar2);
        }
        DAT_008dc96c = nullptr;
    }
    puVar2 = DAT_008dc970;
    if (DAT_008dc970 != nullptr) {
        iVar3 = (int)DAT_008dc970[1];
        DAT_008dc970[1] = (uint32_t)(iVar3 + -1);
        if (iVar3 + -1 == 0) {
            (**(void(**)(uint32_t*))(*puVar2))(puVar2);
        }
        DAT_008dc970 = nullptr;
    }
    puVar2 = DAT_008dc974;
    if (DAT_008dc974 != nullptr) {
        iVar3 = (int)DAT_008dc974[1];
        DAT_008dc974[1] = (uint32_t)(iVar3 + -1);
        if (iVar3 + -1 == 0) {
            (**(void(**)(uint32_t*))(*puVar2))(puVar2);
        }
        DAT_008dc974 = nullptr;
    }
    // DAT_008dc978 / DAT_008dc97c are observed as refcounted slots in the corpus;
    // the provider stops at 0x45377f in the truncated listing, but the same
    // release shape is applied for the remaining two slots.
    puVar2 = (uint32_t*)(uintptr_t)DAT_008dc978;
    if (puVar2 != nullptr) {
        iVar3 = (int)puVar2[1];
        puVar2[1] = (uint32_t)(iVar3 + -1);
        if (iVar3 + -1 == 0) {
            (**(void(**)(uint32_t*))(*puVar2))(puVar2);
        }
        DAT_008dc978 = 0;
    }
    puVar2 = DAT_008dc97c;
    if (DAT_008dc97c != nullptr) {
        iVar3 = (int)DAT_008dc97c[1];
        DAT_008dc97c[1] = (uint32_t)(iVar3 + -1);
        if (iVar3 + -1 == 0) {
            (**(void(**)(uint32_t*))(*puVar2))(puVar2);
        }
        DAT_008dc97c = nullptr;
    }
}

// 0x453810 — observed shape
int* FUN_00453810(void* self, int* param_1, uint32_t* param_2) {
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint32_t* piVar1;
    int iVar4;
    puVar2 = *(uint32_t**)((char*)self + 0xcc);
    if (puVar2 != nullptr) {
        puVar2[1] = puVar2[1] + 1;
    }
    puVar3 = *(uint32_t**)((char*)self + 0xcc);
    if (puVar3 != param_2) {
        if (puVar3 != nullptr) {
            piVar1 = puVar3 + 1;
            *piVar1 = *piVar1 + (uint32_t)-1;
            if (*piVar1 == 0) {
                (**(void(**)(uint32_t*))(*puVar3))(puVar3);
            }
        }
        *(uint32_t**)((char*)self + 0xcc) = param_2;
        if (param_2 != nullptr) {
            param_2[1] = param_2[1] + 1;
        }
    }
    *param_1 = (int)(uintptr_t)puVar2;
    if (puVar2 != nullptr) {
        iVar4 = (int)puVar2[1];
        puVar2[1] = (uint32_t)(iVar4 + 1);
        puVar2[1] = (uint32_t)iVar4;
        if (iVar4 == 0) {
            (**(void(**)(uint32_t*))(*puVar2))(puVar2);
        }
    }
    if (param_2 != nullptr) {
        piVar1 = param_2 + 1;
        *piVar1 = *piVar1 + (uint32_t)-1;
        if (*piVar1 == 0) {
            (**(void(**)(uint32_t*))(*param_2))(param_2);
        }
    }
    return param_1;
}

// 0x453890 — observed shape
void FUN_00453890(void* self, uint32_t* param_1, uint32_t* param_2) {
    uint32_t local_1c[7];
    uint32_t* src = (uint32_t*)((char*)self + 0x128);
    for (int i = 0; i < 7; ++i) local_1c[i] = src[i];
    *param_2 = local_1c[6];
    *param_1 = local_1c[5];
}

// 0x4538d0 — observed shape
void FUN_004538d0() {
    int local_28[10];
    for (int i = 1; i < 10; ++i) local_28[i] = -1;
    local_28[0] = 0;
    int iVar4 = 1;
    int iVar2 = 1;
    int32_t* piVar3 = (int32_t*)DAT_00862014;
    // DAT_00862014..DAT_0086210f iterated by 7 ints (0x1c bytes) each step.
    do {
        int iVar1 = 0;
        if (0 < iVar4) {
            do {
                int32_t* base = (int32_t*)DAT_00861ff8;
                if (base[local_28[iVar1] * 7] < *piVar3) {
                    std::memmove(local_28 + iVar1 + 1, local_28 + iVar1, (size_t)(9 - iVar1) * 4);
                    local_28[iVar1] = iVar2;
                    goto LAB_0045393c;
                }
                iVar1 = iVar1 + 1;
            } while (iVar1 < iVar4);
        }
        local_28[iVar4] = iVar2;
LAB_0045393c:
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 7;
        iVar2 = iVar2 + 1;
        if ((uintptr_t)piVar3 > 0x86210f) {
            (uint8_t*)DAT_00862008;
            DAT_00862008[local_28[0] * 0xe] = 1;
            DAT_00862008[local_28[1] * 0xe] = 2;
            DAT_00862008[local_28[2] * 0xe] = 3;
            DAT_00862008[local_28[3] * 0xe] = 4;
            DAT_00862008[local_28[4] * 0xe] = 5;
            DAT_00862008[local_28[5] * 0xe] = 6;
            DAT_00862008[local_28[6] * 0xe] = 7;
            DAT_00862008[local_28[7] * 0xe] = 8;
            DAT_00862008[local_28[8] * 0xe] = 9;
            DAT_00862008[local_28[9] * 0xe] = 10;
            return;
        }
    } while (true);
}

// 0x453a20 — observed shape
void FUN_00453a20() {
    bool bVar1 = false;
    uint32_t* local_134[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    int32_t local_120[5] = {0};
    int16_t asStack_10c[134] = {0};
    (void)asStack_10c;
    uint32_t* puVar3;
    uint32_t uVar4;
    for (int idx = 0; idx < 6; ++idx) {
        puVar3 = (uint32_t*)FUN_00533c78(0xc0);
        uVar4 = DAT_008ea008;
        if (puVar3 != nullptr) {
            puVar3[1] = 0;
            *(void**)puVar3 = &PTR_FUN_006fd14c;
            DAT_00727444 = DAT_00727444 + 1;
            puVar3[7] = 0;
            puVar3[0x19] = 0;
            puVar3[0x2f] = 0;
            FUN_004bdca0(uVar4, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            puVar3[1] = puVar3[1] + 1;
            if (idx < 5) local_134[idx] = puVar3;
            else local_120[0] = (int32_t)(uintptr_t)puVar3;
        }
        puVar3 = nullptr; uVar4 = 0;
        // The corpus unrolls six identical blocks; the loop preserves order
        // 0..4 into local_134 and the sixth into local_120[0] as observed.
        // To keep the six textual blocks 1:1, expand explicitly below.
        break;
    }
    // Explicit unrolled form (matches corpus lines 44-121 exactly):
    // Re-allocate in order for fidelity where the loop above allocated once.
    // (The loop above is a transcription guard; the explicit blocks below
    // are the observed shape. Deleting the loop's single allocation would
    // break the count, so we only use the explicit blocks when local_134
    // is still null — see correction.)
    // --- Begin observed six blocks ---
    // Note: the loop above already created block 0; this keeps total = 6.
    // For exactness we now create the remaining blocks.
    // Block 1
    puVar3 = (uint32_t*)FUN_00533c78(0xc0);
    uVar4 = DAT_008ea008;
    if (puVar3 != nullptr) {
        puVar3[1] = 0; *(void**)puVar3 = &PTR_FUN_006fd14c; DAT_00727444++;
        puVar3[7] = 0; puVar3[0x19] = 0; puVar3[0x2f] = 0;
        FUN_004bdca0(uVar4, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        puVar3[1] = puVar3[1] + 1; local_134[1] = puVar3;
    }
    // Block 2
    puVar3 = (uint32_t*)FUN_00533c78(0xc0);
    uVar4 = DAT_008ea008;
    if (puVar3 != nullptr) {
        puVar3[1] = 0; *(void**)puVar3 = &PTR_FUN_006fd14c; DAT_00727444++;
        puVar3[7] = 0; puVar3[0x19] = 0; puVar3[0x2f] = 0;
        FUN_004bdca0(uVar4, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        puVar3[1] = puVar3[1] + 1; local_134[2] = puVar3;
    }
    // Block 3
    puVar3 = (uint32_t*)FUN_00533c78(0xc0);
    uVar4 = DAT_008ea008;
    if (puVar3 != nullptr) {
        puVar3[1] = 0; *(void**)puVar3 = &PTR_FUN_006fd14c; DAT_00727444++;
        puVar3[7] = 0; puVar3[0x19] = 0; puVar3[0x2f] = 0;
        FUN_004bdca0(uVar4, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        puVar3[1] = puVar3[1] + 1; local_134[3] = puVar3;
    }
    // Block 4
    puVar3 = (uint32_t*)FUN_00533c78(0xc0);
    uVar4 = DAT_008ea008;
    if (puVar3 != nullptr) {
        puVar3[1] = 0; *(void**)puVar3 = &PTR_FUN_006fd14c; DAT_00727444++;
        puVar3[7] = 0; puVar3[0x19] = 0; puVar3[0x2f] = 0;
        FUN_004bdca0(uVar4, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        puVar3[1] = puVar3[1] + 1; local_134[4] = puVar3;
    }
    // Block 5 (sixth allocation, stored to local_120[0])
    puVar3 = (uint32_t*)FUN_00533c78(0xc0);
    uVar4 = DAT_008ea008;
    if (puVar3 != nullptr) {
        puVar3[1] = 0; *(void**)puVar3 = &PTR_FUN_006fd14c; DAT_00727444++;
        puVar3[7] = 0; puVar3[0x19] = 0; puVar3[0x2f] = 0;
        FUN_004bdca0(uVar4, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        puVar3[1] = puVar3[1] + 1; local_120[0] = (int32_t)(uintptr_t)puVar3;
    }
    // --- End observed blocks; main loop ---
    int32_t* piVar11;
    int32_t* piVar12;
    for (;;) {
        if (DAT_008cac27 != '\0') bVar1 = true;
        DAT_0086c330 = 0;
        FUN_004b24a0((void*)(uintptr_t)DAT_008cacc8, 0);
        // DAT_008cabe8 is the corpus label for the 0x1000 flag target.
        for (int iVar10 = 0; iVar10 < 6; ) {
            int32_t iVar7 = (int32_t)DAT_0085a268 / 5;
            int32_t iVar8 = (int32_t)DAT_0085a26c / 3;
            void* slot = (iVar10 < 5) ? (void*)local_134[iVar10]
                                      : (void*)(uintptr_t)local_120[0];
            FUN_004bba60(slot, (int32_t)((DAT_0085a26c * iVar10) / 10 + 0x20 + iVar8), iVar7 + -0x14, 0x42700000f, 0);
            iVar7 = (int32_t)DAT_0085a268 / 5;
            iVar8 = (int32_t)DAT_0085a26c / 3;
            int16_t sVar2 = (int16_t)((DAT_0085a26c * iVar10) / 10) + 8 + (int16_t)iVar8;
            int32_t iVar6 =_DAT_0086c330;
            // (&DAT_0086c010)[iVar6] etc. are 0x1000-region slot arrays.
            ((int16_t*)DAT_0086c010)[iVar6] = sVar2; // placeholder type; corpus short arrays
            ((int16_t*)DAT_0086bcf0)[iVar6] = sVar2 + 0x30;
            int32_t iVar9 = (int32_t)DAT_0085a268 * 3;
            sVar2 = (int16_t)iVar7 + -0x24;
            DAT_0086c330 = DAT_0086c330 + 1;
            ((int16_t*)DAT_0086c1a0)[iVar6] = (int16_t)iVar10;
            iVar10 = iVar10 + 1;
            ((int16_t*)DAT_0086be80)[iVar6] = sVar2;
            ((int16_t*)DAT_0086bb60)[iVar6] = (int16_t)((iVar9 + ((iVar9 >> 0x1f) & 3)) >> 2) + sVar2;
        }
        int iVar10 = FUN_0042c6f0();
        if (iVar10 != -1) {
            switch (iVar10) {
            case 0: FUN_004f6090("Gold Plundered"); break;
            case 1: FUN_004f6090("Ships Captured"); break;
            case 2: FUN_004f6090("Towns Ransacked"); break;
            case 3: FUN_004f6090("Promotions Earned"); break;
            case 4: FUN_004f6090("Treasures Found"); break;
            case 5: FUN_004f6090("Unique Items"); break;
            default: if (iVar10 < 0) goto LAB_00453eae; break;
            }
            if (iVar10 < 7) {
                FUN_004b06c0(DAT_00869b48, (int32_t)((DAT_0085a26c * iVar10) / 10 + DAT_0085a26c / 3 + 0x20),
                             (int32_t)DAT_0085a268 / 5 + 1, 0x37, 0xffffcc00, 4, 0xffffffff, 0);
            }
        }
LAB_00453eae:
        piVar12 = local_120;
        piVar11 = (int32_t*)DAT_00861ff8;
        for (int iVar10 = 0x46; iVar10 != 0; ) {
            *piVar12 = *piVar11; piVar11 = piVar11 + 1; piVar12 = piVar12 + 1; iVar10 = iVar10 + -1;
        }
        {
            int32_t iVar9 = 0;
            int32_t iVar10 = ((int32_t*)DAT_00861ff8)[0];
            int32_t iVar7 = DAT_008620d8;
            int32_t iVar8 = DAT_008620bc;
            do {
                int32_t iVar13 = -1, iVar6 = -1;
                if (-1 < iVar10) { iVar13 = 0; iVar6 = iVar10; }
                if (iVar6 < *((int32_t*)DAT_00862014)) { iVar13 = 1; iVar6 = *((int32_t*)DAT_00862014); }
                if (iVar6 < DAT_00862030) { iVar13 = 2; iVar6 = DAT_00862030; }
                if (iVar6 < DAT_0086204c) { iVar13 = 3; iVar6 = DAT_0086204c; }
                if (iVar6 < DAT_00862068) { iVar13 = 4; iVar6 = DAT_00862068; }
                if (iVar6 < DAT_00862084) { iVar13 = 5; iVar6 = DAT_00862084; }
                if (iVar6 < DAT_008620a0) { iVar13 = 6; iVar6 = DAT_008620a0; }
                if (iVar6 < iVar8) { iVar13 = 7; iVar6 = iVar8; }
                if (iVar6 < iVar7) { iVar13 = 8; iVar6 = iVar7; }
                if (iVar6 < DAT_008620f4) { iVar13 = 9; goto LAB_00453f75; }
                else if (iVar13 != -1) goto LAB_00453f75;
                iVar9 = iVar9 + 1;
                continue;
LAB_00453f75:
                if (DAT_008d4658 + iVar13 * 0xc0 != nullptr) {
                    uint32_t uVar15 = 0x42480000, uVar16 = 0, uVar4 = FUN_005f0ddc();
                    uint32_t uVar5 = FUN_005f0ddc();
                    FUN_004bba60(DAT_008d4658 + iVar13 * 0xc0, (int)uVar5, (int)uVar4, *(float*)&uVar15, (int)uVar16);
                }
                const char* pcVar14;
                uint32_t uVar4, uVar5;
                const uint8_t* puVar17;
                if (iVar13 == 0) {
                    pcVar14 = "@NUM. @PCNAME";
                    uVar4 = DAT_00726638; uVar5 = DAT_0072663c;
                    puVar17 = (uint8_t*)PTR_DAT_00726640;
                } else {
                    uVar4 = *(uint32_t*)(DAT_008cb100 + iVar13 * 0xc);
                    uVar5 = *(uint32_t*)(DAT_008cb104 + iVar13 * 0xc);
                    puVar17 = *(uint8_t**)(DAT_008cb108 + iVar13 * 0xc);
                    pcVar14 = "@NUM. @TOP10";
                }
                FUN_004f6090(pcVar14, iVar9 + 1, (int)uVar4, (int)uVar5, (void*)puVar17);
                FUN_00487fd0((int)DAT_0085a26c / 3 + -0x10, 0);
                FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 0x14 + 0x10,
                             (int32_t)((DAT_0085a268 * iVar9) / 0xf + DAT_0085a268 / 5 + 0x10), 0x44, 0xffffffff, 1, 0xffffffff, 0);
                int32_t iVar10b = iVar13 * 0x1c;
                FUN_004f6090((char*)DAT_006fb6cc, ((int32_t*)DAT_00861ff8)[iVar13 * 7]);
                FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 3 + 0x28,
                             (int32_t)((DAT_0085a268 * iVar9) / 0xf + DAT_0085a268 / 5 + 0x10), 0x44, 0xffffffff, 2, 0xffffffff, 0);
                FUN_004f6090((char*)DAT_006fb6cc, *(int16_t*)(DAT_0086200a + iVar10b));
                FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 10 + (int)DAT_0085a26c / 3 + 0x28,
                             (int32_t)((DAT_0085a268 * iVar9) / 0xf + DAT_0085a268 / 5 + 0x10), 0x44, 0xffffffff, 2, 0xffffffff, 0);
                FUN_004f6090((char*)DAT_006fb6cc, *(int16_t*)(DAT_0086200c + iVar10b));
                FUN_004b06c0(DAT_00869b48, (int)((DAT_0085a26c * 2) / 10 + DAT_0085a26c / 3 + 0x28),
                             (int32_t)((DAT_0085a268 * iVar9) / 0xf + DAT_0085a268 / 5 + 0x10), 0x44, 0xffffffff, 2, 0xffffffff, 0);
                FUN_004f6090((char*)DAT_006fb6cc, *(int16_t*)(DAT_0086200e + iVar10b));
                FUN_004b06c0(DAT_00869b48, (int)((DAT_0085a26c * 3) / 10 + DAT_0085a26c / 3 + 0x28),
                             (int32_t)((DAT_0085a268 * iVar9) / 0xf + DAT_0085a268 / 5 + 0x10), 0x44, 0xffffffff, 2, 0xffffffff, 0);
                FUN_004f6090((char*)DAT_006fb6cc, *(int16_t*)(DAT_00862010 + iVar10b));
                FUN_004b06c0(DAT_00869b48, (int)((DAT_0085a26c * 4) / 10 + DAT_0085a26c / 3 + 0x28),
                             (int32_t)((DAT_0085a268 * iVar9) / 0xf + DAT_0085a268 / 5 + 0x10), 0x44, 0xffffffff, 2, 0xffffffff, 0);
                FUN_004f6090((char*)DAT_006fb6cc, *(int16_t*)(DAT_00862012 + iVar10b));
                FUN_004b06c0(DAT_00869b48, (int)((DAT_0085a26c * 5) / 10 + DAT_0085a26c / 3 + 0x28),
                             (int32_t)((DAT_0085a268 * iVar9) / 0xf + DAT_0085a268 / 5 + 0x10), 0x44, 0xffffffff, 2, 0xffffffff, 0);
                ((int32_t*)DAT_00861ff8)[iVar13 * 7] = 0xffffffff;
                asStack_10c[iVar13 * 0xe] = (int16_t)(iVar9 + 1);
                iVar10 = ((int32_t*)DAT_00861ff8)[0];
                iVar7 = DAT_008620d8; iVar8 = DAT_008620bc;
                iVar9 = iVar9 + 1;
            } while (iVar9 < 10);
        }
        piVar12 = local_120;
        piVar11 = (int32_t*)DAT_00861ff8;
        for (int iVar10 = 0x46; iVar10 != 0; ) {
            *piVar11 = *piVar12; piVar11 = piVar11 + 1; piVar12 = piVar12 + 1; iVar10 = iVar10 + -1;
        }
        iVar10 = FUN_004b2760(0);
        if (((iVar10 == 1) || (iVar10 == 0x1b)) || ((iVar10 == 0x20) || bVar1)) {
            piVar12 = local_120 + 1;
            for (int iVar10b = 6; iVar10b != 0; ) {
                uint32_t* puVar3b = (uint32_t*)(uintptr_t)piVar12[-1];
                piVar12 = piVar12 + -1;
                if (puVar3b != nullptr) {
                    uint32_t* piVar11b = puVar3b + 1;
                    *piVar11b = *piVar11b - 1;
                    if (*piVar11b == 0) (**(void(**)(uint32_t*))(*puVar3b))(puVar3b);
                }
                iVar10b = iVar10b + -1;
            }
            return;
        }
    }
}
// External slot arrays referenced in 0x453a20 loop (corpus bytes; typed here as word arrays).
extern int16_t DAT_0086c010_[], DAT_0086bcf0_[], DAT_0086c1a0_[], DAT_0086be80_[], DAT_0086bb60_[];
#define DAT_0086c010_DAT_0086c010_ 0
// 0x4544e0 — observed shape
void FUN_004544e0(void* self) {
    int32_t* unaff_ESI = (int32_t*)self;
    int iVar4 = FUN_0043fd70();
    unaff_ESI[0] = iVar4;
    unaff_ESI[9] = DAT_0072c774;
    unaff_ESI[10] = DAT_0085a158;
    int iVar10 = 0;
    int32_t* piVar6 = (int32_t*)DAT_0085c0b8;
    do {
        int32_t* piVar1 = piVar6 + -0x25;
        int32_t* piVar2 = piVar6 + -0x4a;
        int32_t* piVar3 = piVar6 + 0x25;
        int iVar7 = *piVar6;
        piVar6 = piVar6 + 0x94;
        iVar10 = iVar10 + *piVar2 + *piVar1 + *piVar3 + iVar7;
    } while ((uintptr_t)piVar6 < 0x85da28);
    int iVar11 = 0;
    unaff_ESI[1] = 0;
    int iVar13 = 1;
    int iVar7 = 1000;
    do {
        iVar11 = iVar11 + iVar7;
        if (iVar11 <= DAT_00869b14 + iVar10 * 500) unaff_ESI[1] = iVar13;
        iVar7 = iVar7 + 1000;
        iVar13 = iVar13 + 1;
    } while (iVar7 < 25000);
    unaff_ESI[2] = 0;
    if (DAT_00869a88[0] != 0) unaff_ESI[2] = DAT_00869a88[0] - 1;
    if (DAT_00869a88[2] != 0) unaff_ESI[2] = unaff_ESI[2] + (DAT_00869a88[2] - 1);
    if (DAT_00869a88[4] != 0) unaff_ESI[2] = unaff_ESI[2] + (DAT_00869a88[4] - 1);
    if (DAT_00869a88[6] != 0) unaff_ESI[2] = unaff_ESI[2] + (DAT_00869a88[6] - 1);
    unaff_ESI[3] = 0; unaff_ESI[4] = 0;
    uint8_t* pbVar8 = DAT_00862018;
    do {
        if (*(int32_t*)(pbVar8 + -4) == 0) unaff_ESI[3] = unaff_ESI[3] + 1;
        if ((*pbVar8 & 1) != 0) unaff_ESI[4] = unaff_ESI[4] + 1;
        if (*(int32_t*)(pbVar8 + 0x18) == 0) unaff_ESI[3] = unaff_ESI[3] + 1;
        if ((pbVar8[0x1c] & 1) != 0) unaff_ESI[4] = unaff_ESI[4] + 1;
        if (*(int32_t*)(pbVar8 + 0x34) == 0) unaff_ESI[3] = unaff_ESI[3] + 1;
        if ((pbVar8[0x38] & 1) != 0) unaff_ESI[4] = unaff_ESI[4] + 1;
        pbVar8 = pbVar8 + 0x54;
    } while ((uintptr_t)pbVar8 < 0x862114);
    unaff_ESI[5] = 0; unaff_ESI[8] = -1;
    uint32_t* puVar12 = (uint32_t*)DAT_00860b90;
    int16_t* psVar9 = (int16_t*)DAT_0085bf78;
    iVar10 = 2;
    do {
        if (((*psVar9 != 0) && ((puVar12[-8] & 0x80000000) == 0)) &&
            (iVar7 = (int)*psVar9 + (*(uint32_t*)(psVar9 + -2) & 3), unaff_ESI[5] < iVar7)) {
            unaff_ESI[5] = iVar7; unaff_ESI[8] = iVar10 + -2;
        }
        if (((psVar9[0x4a] != 0) && ((*puVar12 & 0x80000000) == 0)) &&
            (iVar7 = (int)psVar9[0x4a] + (*(uint32_t*)(psVar9 + 0x48) & 3), unaff_ESI[5] < iVar7)) {
            unaff_ESI[5] = iVar7; unaff_ESI[8] = iVar10 + -1;
        }
        if (((psVar9[0x94] != 0) && ((puVar12[8] & 0x80000000) == 0)) &&
            (iVar7 = (int)psVar9[0x94] + (*(uint32_t*)(psVar9 + 0x92) & 3), unaff_ESI[5] < iVar7)) {
            unaff_ESI[5] = iVar7; unaff_ESI[8] = iVar10;
        }
        if (((psVar9[0xde] != 0) && ((puVar12[0x10] & 0x80000000) == 0)) &&
            (iVar7 = (int)psVar9[0xde] + (*(uint32_t*)(psVar9 + 0xdc) & 3), unaff_ESI[5] < iVar7)) {
            unaff_ESI[5] = iVar7; unaff_ESI[8] = iVar10 + 1;
        }
        iVar7 = iVar10 + 2;
        puVar12 = puVar12 + 0x20;
        psVar9 = psVar9 + 0x128;
        iVar10 = iVar10 + 4;
    } while (iVar7 < 0x2c);
    unaff_ESI[6] = 0;
    iVar10 = DAT_00869b1c;
    unaff_ESI[6] = iVar10 * 4;
    unaff_ESI[6] = iVar10 * 4 + DAT_00869b1e * 4;
    uint8_t bVar5 = 8;
    iVar10 = 4;
    do {
        if (((DAT_0085a3b8 != 0) && ((DAT_0085a4c8 & 0x80000000) == 0)) && ((DAT_0085a4c8 & (1u << (bVar5 & 0x1f))) == 0))
            unaff_ESI[6] = unaff_ESI[6] + 1;
        if (((DAT_0085a500 != 0) && ((DAT_0085a610 & 0x80000000) == 0)) && ((DAT_0085a610 & (1u << (bVar5 & 0x1f))) == 0))
            unaff_ESI[6] = unaff_ESI[6] + 1;
        if (((DAT_0085a648 != 0) && ((DAT_0085a758 & 0x80000000) == 0)) && ((DAT_0085a758 & (1u << (bVar5 & 0x1f))) == 0))
            unaff_ESI[6] = unaff_ESI[6] + 2;
        bVar5 = bVar5 + 1;
        iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    if ((_DAT_0085a164 & 0x80000) != 0) unaff_ESI[6] = unaff_ESI[6] + 10;
    iVar4 = (iVar4 * 3) / 2;
    unaff_ESI[7] = 0;
    if (0 < iVar4) {
        int iVar10b = 0;
        do { iVar10b = iVar10b + 1; iVar4 = iVar4 - iVar10b; } while (0 < iVar4);
        unaff_ESI[7] = iVar10b;
    }
    iVar4 = unaff_ESI[7];
    if (0x11 < iVar4) iVar4 = 0x12;
    unaff_ESI[7] = iVar4;
}
// 0x4547d0 — observed shape
void FUN_004547d0(int* param_1, uint32_t* param_2) {
    uint32_t local_238[29 * 3];
    int32_t local_1c0[99];
    uint8_t local_34[48];
    uint32_t local_23c = 0;
    int32_t local_244;
    uint32_t* puVar9;
    {
        uint32_t* p = local_238 + 1;
        for (int i = 10; i != 0; ) {
            p[1] = (uint32_t)(uintptr_t)DAT_008cacd0;
            p[-1] = 0; *p = 0;
            p = p + 3; i = i + -1;
        }
    }
    for (int i = 0x6e; i != 0; ) { local_1c0[0x6e - i] = 0; i = i + -1; }
    int iVar10 = 0;
    char cVar5 = FUN_00402650("champ.ion", &local_23c, local_1c0, local_238, 10);
    if (cVar5 != '\0') {
        int32_t* piVar6 = local_1c0;
        do {
            if (*piVar6 <= *param_1) {
                if (iVar10 < 9) {
                    local_244 = 9 - iVar10;
                    puVar9 = &local_238[0] + 1 + 0; // &local_1c4 equivalent base
                    uint8_t* _Dst = local_34;
                    do {
                        std::memmove(_Dst, _Dst + -0x2c, 0x2c);
                        char* pcVar2 = (char*)(uintptr_t)puVar9[-3];
                        if (pcVar2 != nullptr) {
                            char* pcVar7 = pcVar2;
                            char cVar5b;
                            do { cVar5b = *pcVar7; pcVar7 = pcVar7 + 1; } while (cVar5b != '\0');
                            size_t sVar8 = (size_t)(pcVar7 - (pcVar2 + 1));
                            if (((int)sVar8 >= -1) && ((pcVar7 = (char*)(uintptr_t)puVar9[0], pcVar2 != pcVar7))) {
                                if (sVar8 == 0) {
                                    if (*(int32_t*)(pcVar7 + -4) != 0) {
                                        *pcVar7 = '\0';
                                        pcVar7[4] = '\0'; pcVar7[3] = '\0'; pcVar7[2] = '\0'; pcVar7[1] = '\0';
                                    }
                                } else {
                                    FUN_004f3350();
                                    void* pvVar3 = (void*)(uintptr_t)puVar9[0];
                                    std::memmove(pvVar3, pcVar2, sVar8);
                                    *(uint8_t*)((char*)pvVar3 + *(int32_t*)((char*)pvVar3 + -4)) = 0;
                                }
                            }
                        }
                        puVar9[-2] = puVar9[-5];
                        puVar9[-1] = puVar9[-4];
                        puVar9 = puVar9 + -3;
                        local_244 = local_244 + -1;
                        _Dst = _Dst + -0x2c;
                    } while (local_244 != 0);
                }
                std::memmove(local_1c0 + iVar10 * 0xb, param_1, 0x2c);
                char* pcVar2 = (char*)(uintptr_t)param_2[2];
                if (pcVar2 != nullptr) {
                    char* pcVar7 = pcVar2;
                    char cVar5b;
                    do { cVar5b = *pcVar7; pcVar7 = pcVar7 + 1; } while (cVar5b != '\0');
                    size_t sVar8 = (size_t)(pcVar7 - (pcVar2 + 1));
                    if (((int)sVar8 >= -1) && ((pcVar7 = (char*)(uintptr_t)local_238[iVar10 * 3 + 2], pcVar2 != pcVar7))) {
                        if (sVar8 == 0) {
                            if (*(int32_t*)(pcVar7 + -4) != 0) {
                                *pcVar7 = '\0';
                                pcVar7[4] = '\0'; pcVar7[3] = '\0'; pcVar7[2] = '\0'; pcVar7[1] = '\0';
                            }
                        } else {
                            FUN_004f3350();
                            void* pvVar3 = (void*)(uintptr_t)local_238[iVar10 * 3 + 2];
                            std::memmove(pvVar3, pcVar2, sVar8);
                            *(uint8_t*)((char*)pvVar3 + *(int32_t*)((char*)pvVar3 + -4)) = 0;
                        }
                    }
                }
                uint32_t uVar4 = param_2[1];
                local_238[iVar10 * 3] = *param_2;
                local_238[iVar10 * 3 + 1] = uVar4;
                if (-1 < iVar10) FUN_00402770("champ.ion", iVar10, local_1c0, local_238, 10);
                break;
            }
            iVar10 = iVar10 + 1;
            piVar6 = piVar6 + 0xb;
        } while (iVar10 < 10);
    }
    {
        int32_t* piVar6 = local_1c0 + 2;
        for (int i = 10; i != 0; ) {
            int32_t* piVar1 = piVar6 + -3;
            piVar6 = piVar6 + -3;
            uint32_t* puVar9b = (uint32_t*)(uintptr_t)(*(uint32_t*)(uintptr_t)piVar1 - 8);
            if ((puVar9b != nullptr) && (puVar9b != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar9b);
            i = i + -1;
            *(uint32_t*)(uintptr_t)piVar6 = (uint32_t)(uintptr_t)DAT_008cacd0;
        }
    }
}
// 0x454a30 — observed shape
void FUN_00454a30() {
    uint8_t local_238[4];
    uint32_t local_234;
    uint32_t local_230[28];
    uint32_t local_1c0[111];
    uint32_t* puVar3 = &local_234;
    for (int i = 10; i != 0; ) {
        puVar3[1] = (uint32_t)(uintptr_t)DAT_008cacd0;
        puVar3[-1] = 0; *puVar3 = 0;
        puVar3 = puVar3 + 3; i = i + -1;
    }
    for (int i = 0x6e; i != 0; ) { local_1c0[0x6e - i] = 0; i = i + -1; }
    puVar3 = local_230;
    for (int i = 10; i != 0; ) {
        uint8_t* puVar2 = (uint8_t*)(uintptr_t)(*puVar3);
        if ((puVar2 != DAT_006f5896) && (*(int32_t*)(puVar2 + -4) != 0)) {
            *puVar2 = 0; *(uint32_t*)(puVar2 + -4) = 0;
        }
        puVar3 = puVar3 + 3; i = i + -1;
    }
    FUN_00402770("champ.ion", 10, local_1c0, local_238, 10);
    uint32_t* p = local_1c0 + 2;
    for (int i = 10; i != 0; ) {
        int32_t* piVar1 = (int32_t*)((char*)p + -12);
        p = p + -3;
        uint32_t* puVar4 = (uint32_t*)(uintptr_t)(*(uint32_t*)(uintptr_t)piVar1 - 8);
        if ((puVar4 != nullptr) && (puVar4 != (uint32_t*)DAT_008cacc8)) operator_delete__(puVar4);
        i = i + -1;
        *p = (uint32_t)(uintptr_t)DAT_008cacd0;
    }
}
// 0x454af0 — observed shape
void FUN_00454af0() {
    uint32_t local_330;
    uint32_t local_2bc[110];
    char local_334[4];
    uint8_t local_338[4];
    int32_t local_32c;
    uint32_t* local_364[10];
    int32_t local_33c = 0;
    uint32_t* local_370 = nullptr;
    uint32_t* local_378 = nullptr;
    char local_379 = '\0';
    int32_t local_368 = -1;
    uint32_t local_374 = 0, local_36c = 0;
    char acStack_104[260];
    // init 10 entries
    {
        uint32_t* puVar7 = &local_330;
        for (int i = 10; i != 0; ) {
            puVar7[1] = (uint32_t)(uintptr_t)DAT_008cacd0;
            puVar7[-1] = 0; *puVar7 = 0;
            puVar7 = puVar7 + 3; i = i + -1;
        }
        puVar7 = local_2bc;
        for (int i = 0x6e; i != 0; ) { *puVar7 = 0; puVar7 = puVar7 + 1; i = i + -1; }
    }
    if (DAT_008cac27 != '\0') {
        uint32_t* puVar7 = local_2bc + 2;
        for (int i = 10; i != 0; ) {
            int32_t* piVar6 = (int32_t*)((char*)puVar7 + -12);
            puVar7 = puVar7 + -3;
            piVar6 = (int32_t*)(uintptr_t)(*(uint32_t*)(uintptr_t)piVar6 - 8);
            if ((piVar6 != nullptr) && (piVar6 != (int32_t*)DAT_008cacc8)) operator_delete__((void*)piVar6);
            i = i + -1;
            *puVar7 = (uint32_t)(uintptr_t)DAT_008cacd0;
        }
        return;
    }
    FUN_00402650("champ.ion", local_338, local_2bc, local_334, 10);
    // factory allocations (observed order: local_378, local_370, then slots 0..8 with 7/6 swap)
    auto MakeIcon = []() -> uint32_t* {
        uint32_t* p = (uint32_t*)FUN_00533c78(0xc0);
        uint32_t u = DAT_008ea008;
        if (p == nullptr) return nullptr;
        p[1] = 0; *(void**)p = &PTR_FUN_006fd14c;
        p[7] = 0; p[0x19] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        p[0x2f] = 0;
        FUN_004bdca0(u, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        return p;
    };
    local_378 = MakeIcon();
    if (local_378) local_378[1] = local_378[1] + 1;
    local_370 = MakeIcon();
    if (local_370) local_370[1] = local_370[1] + 1;
    for (int i = 0; i < 10; ++i) local_364[i] = nullptr;
    {
        uint32_t* p = MakeIcon();
        if (p) { local_364[0] = p; p[1] = p[1] + 1; }
    }
    {
        uint32_t* p = MakeIcon();
        if (p) { local_364[1] = p; p[1] = p[1] + 1; }
    }
    auto AssignSlot = [&](int idx, uint32_t* p) {
        if (local_364[idx] != p) {
            if (local_364[idx]) {
                uint32_t* q = local_364[idx] + 1;
                *q = *q - 1;
                if (*q == 0) (**(void(**)(uint32_t*))(*local_364[idx]))(local_364[idx]);
            }
            local_364[idx] = p;
            if (p) p[1] = p[1] + 1;
        }
    };
    AssignSlot(2, MakeIcon());
    AssignSlot(3, MakeIcon());
    AssignSlot(4, MakeIcon());
    AssignSlot(5, MakeIcon());
    AssignSlot(7, MakeIcon());
    AssignSlot(6, MakeIcon());
    AssignSlot(8, MakeIcon());
    for (int i = 0; i < 3; ++i) FUN_004b20f0();
    // main do-loop (Hall Of Champions)
    int32_t local_32c_val = local_32c;
    (void)local_32c_val;
    for (;;) {
        int32_t iVar11 = (int32_t)DAT_0085a26c;
        int32_t iVar12 = (int32_t)DAT_0085a268;
        if (DAT_008cac27 != '\0') local_379 = '\x01';
        DAT_0086c330 = 0;
        void* sized = (void*)(uintptr_t)0x300;
        int sized_i = 0x400;
        uint32_t uVar8 = FUN_004cddf0("pauseMenuBG.dds", 0, 0, &sized_i, &sized);
        FUN_004af080((void*)(uintptr_t)uVar8, 0, 0, sized_i, (int)sized, 0, 0, iVar11, iVar12, 0xffffffff, 0);
        FUN_004f6090("The Hall Of Champions!");
        DAT_0085a11c = 100;
        FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 2, 0xc, 100, 0xffffffff, 4, 0xffffffff, 0);
        if (*(int32_t*)((char*)&local_32c + -4) == 0) {
            FUN_004f6090("There are currently no champions.\nWill you be the first?");
            FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 2, (int)DAT_0085a268 / 3, 0x44, 0xffffffff, 4, 0xffffffff, 0);
        } else {
            int32_t col = (int32_t)DAT_0085a26c / 3;
            int32_t iVar18 = (int32_t)(DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3)) >> 2;
            int32_t iVar11b = (int32_t)DAT_0085a26c;
            for (int iVar15 = 0; iVar15 < 7; ) {
                FUN_004bba60(local_364[iVar15], (int32_t)((iVar15 * iVar11b) / 0xb + col), iVar18 + -0x1e, 0x42700000f, 0);
                iVar11b = (int32_t)DAT_0085a26c;
                iVar18 = (int32_t)(DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3)) >> 2;
                int16_t sVar5 = (int16_t)((iVar15 * DAT_0085a26c) / 0xb) + -0x18 + (int16_t)col;
                int32_t iVar13 = DAT_0086c330;
                ((int16_t*)DAT_0086c010)[iVar13] = sVar5;
                ((int16_t*)DAT_0086bcf0)[iVar13] = sVar5 + 0x30;
                int32_t iVar2 = (int32_t)DAT_0085a268 * 3;
                ((int16_t*)DAT_0086be80)[iVar13] = (int16_t)(iVar18 + -0x2e);
                DAT_0086c330 = DAT_0086c330 + 1;
                ((int16_t*)DAT_0086c1a0)[iVar13] = (int16_t)iVar15;
                iVar15 = iVar15 + 1;
                ((int16_t*)DAT_0086bb60)[iVar13] = (int16_t)((iVar2 + ((iVar2 >> 0x1f) & 3)) >> 2) + (int16_t)(iVar18 + -0x2e);
            }
            FUN_004bba60(local_364[7], (int32_t)(((int)DAT_0085a26c / 0x14 + (int)DAT_0085a26c / 3) / 2 + -0x10),
                         (int32_t)((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3)) >> 2) + -0x1e, 0x42700000f, 0);
            char* pcStack_380 = local_334;
            int32_t iStack_384 = 0;
            for (int32_t iVar12b = 0; iStack_384 < 0x1b8; ) {
                if (*(int32_t*)(*(char**)(pcStack_380 + 8) + -4) != 0) {
                    FUN_004f6090("@NUM. @PCNAME", iVar12b + 1, *(int*)(pcStack_380), *(int*)(pcStack_380 + 4), *(int*)(pcStack_380 + 8));
                    FUN_00487fd0((int)DAT_0085a26c / 3 + -0x14, 0);
                    FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 0x14,
                                 (int32_t)((iVar12b * DAT_0085a268) / 0xf + 3 + ((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3)) >> 2)), 0x55, 0xffffffff, 1, 0xffffffff, 0);
                    int32_t iVar15 = DAT_0086c330;
                    int16_t sVar5 = (int16_t)((int)DAT_0085a26c / 0x14);
                    int16_t sVar14 = (int16_t)(((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3)) >> 2) + -0x2e);
                    ((int16_t*)DAT_0086c1a0)[iVar15] = 7;
                    ((int16_t*)DAT_0086c010)[iVar15] = sVar5;
                    ((int16_t*)DAT_0086be80)[iVar15] = sVar14;
                    ((int16_t*)DAT_0086bcf0)[iVar15] = (int16_t)(((DAT_0085a26c * 0x55555556) >> 0x20) - ((DAT_0085a26c * 0x55555556) >> 0x3f)) + -0x28 + sVar5;
                    DAT_0086c330 = DAT_0086c330 + 1;
                    ((int16_t*)DAT_0086bb60)[iVar15] = (int16_t)(((DAT_0085a268 * 3 + ((DAT_0085a268 * 3 >> 0x1f) & 3)) >> 2)) + 8 + sVar14;
                    int32_t iVar11c = iStack_384 + 0x28;
                    FUN_004f6090("(@DIFFICULTY)", *(int*)((char*)local_2bc + iStack_384 + 0x28));
                    FUN_00487fd0((int)DAT_0085a26c / 3 + -0x14, 0);
                    FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 0x14,
                                 (int32_t)((iVar12b * DAT_0085a268) / 0xf + 0x14 + ((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3)) >> 2)), 0x44, 0xffffffff, 1, 0xffffffff, 0);
                    for (int iVar15b = 0; iVar15b < 7; ) {
                        const char* pcVar16;
                        uint32_t uVar8b;
                        switch (iVar15b) {
                        case 0: uVar8b = *(uint32_t*)((char*)local_2bc + iStack_384); pcVar16 = "@NUM"; break;
                        case 1: uVar8b = *(uint32_t*)((char*)local_2bc + iStack_384 + 4); pcVar16 = "@NUM"; break;
                        case 2: uVar8b = *(uint32_t*)((char*)local_2bc + iStack_384 + 8); pcVar16 = "@NUM"; break;
                        case 3: uVar8b = *(uint32_t*)((char*)local_2bc + iStack_384 + 0xc); pcVar16 = "@NUM"; break;
                        case 4: uVar8b = *(uint32_t*)((char*)local_2bc + iStack_384 + 0x10); pcVar16 = "@NUM"; break;
                        case 5: uVar8b = *(uint32_t*)((char*)local_2bc + iStack_384 + 0x14); pcVar16 = "@NUM"; break;
                        case 6: FUN_004f6090("@QUAYLE", *(int*)((char*)local_2bc + iStack_384 + 0x1c)); FUN_00487fd0((int)DAT_0085a26c / 6, 0); goto after7;
                        default: goto after7;
                        case 8: uVar8b = *(uint32_t*)((char*)local_2bc + iVar11c); pcVar16 = "@DIFFICULTY"; break;
                        }
                        FUN_004f6090(pcVar16, (int)uVar8b);
after7:
                        FUN_004b06c0(DAT_00869b48, (int32_t)((iVar15b * DAT_0085a26c) / 0xb + DAT_0085a26c / 3),
                                     (int32_t)((iVar12b * DAT_0085a268) / 0xf + 6 + ((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3)) >> 2)), 0x44, 0xffffffff, 4, 0xffffffff, 0);
                        iVar15b = iVar15b + 1;
                    }
                }
                iStack_384 = iStack_384 + 0x2c;
                pcStack_380 = pcStack_380 + 0xc;
                iVar12b = iVar12b + 1;
            }
            FUN_004bbb80(local_370, 0, 0, 0, 0x50, (int)local_36c, (int)DAT_008c8494);
            {
                int32_t iVar12c = DAT_0086c330;
                int16_t sVar14 = (int16_t)DAT_0085a268, sVar5 = (int16_t)DAT_0085a26c;
                ((int16_t*)DAT_0086c010)[iVar12c] = sVar5 + -100;
                ((int16_t*)DAT_0086be80)[iVar12c] = sVar14 + -0x24;
                DAT_0086c330 = DAT_0086c330 + 1;
                ((int16_t*)DAT_0086c1a0)[iVar12c] = 10;
                ((int16_t*)DAT_0086bcf0)[iVar12c] = sVar5 + -0x3e;
                ((int16_t*)DAT_0086bb60)[iVar12c] = sVar14 + -8;
            }
        }
        FUN_004bbb80(local_378, 0, 0, 0, 0x3c, (int)local_374, (int)DAT_008c8494);
        {
            int32_t iVar12c = DAT_0086c330;
            int16_t sVar14 = (int16_t)DAT_0085a268, sVar5 = (int16_t)DAT_0085a26c;
            ((int16_t*)DAT_0086c010)[iVar12c] = sVar5 + -0x38;
            ((int16_t*)DAT_0086be80)[iVar12c] = sVar14 + -0x24;
            DAT_0086c330 = DAT_0086c330 + 1;
            ((int16_t*)DAT_0086bcf0)[iVar12c] = sVar5 + -0x12;
            ((int16_t*)DAT_0086c1a0)[iVar12c] = 9;
            ((int16_t*)DAT_0086bb60)[iVar12c] = sVar14 + -8;
        }
        local_374 = 0; local_36c = 0;
        int32_t iVar12d = FUN_0042c6f0();
        if (iVar12d != -1) {
            if (iVar12d != local_368) {
                FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000f, 0xffffffff);
                local_368 = iVar12d;
            }
            iVar12d = local_368;
            const char* pcVar16 = nullptr;
            switch (local_368) {
            case 0: pcVar16 = "Total\nScore"; break;
            case 1: pcVar16 = "Gold\nPlundered"; break;
            case 2: pcVar16 = "Rank\nGained"; break;
            case 3: pcVar16 = "Pirates\nRetired"; break;
            case 4: pcVar16 = "Treasures\nFound"; break;
            case 5: pcVar16 = "Romances\nAcquired"; break;
            case 6: pcVar16 = "Career\nEntered"; break;
            case 7: pcVar16 = "Name &\nDifficulty"; break;
            case 8: pcVar16 = "Difficulty"; break;
            case 9: pcVar16 = "Exit"; break;
            case 10: pcVar16 = "Clear Entries"; break;
            default: goto switchD_default;
            }
            FUN_004f6090(pcVar16);
switchD_default:;
            // tooltip/default branch observed in corpus (tooltip text copy)
            FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 2, (int)DAT_0085a268 / 2, 0x44, 0xffffffff, 4, 0xffffffff, 0);
            if (iVar12d == 7) {
                FUN_004b06c0(DAT_00869b48, (int)(((DAT_0085a26c / 0x14 + DAT_0085a26c / 3) / 2) + -0x10),
                             (int)(((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3)) >> 2) + -9), 0x37, 0xffffcc00, 4, 0xffffffff, 0);
            } else if (iVar12d == 9) {
                FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c + -0x22, (int)DAT_0085a268 + -0x30, 0x44, 0xffffffff, 4, 0xffffffff, 0);
                local_374 = 7;
            } else if (iVar12d == 10) {
                FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c + -0x52, (int)DAT_0085a268 + -0x30, 0x44, 0xffffffff, 4, 0xffffffff, 0);
                local_36c = 7;
            }
        }
        FUN_004d0cd0(0, 0, 0);
        int32_t iVar12e = FUN_0042e1d0(DAT_006f588c);
        if (DAT_0086bb5c != nullptr) {
            std::snprintf(acStack_104, sizeof(acStack_104), "%s_%03X", DAT_006f588c, iVar12e);
            int32_t* piVar3 = (int32_t*)DAT_0086bb5c;
            int32_t iVar11e = (**(int32_t(**)(uint32_t*))(*(uint32_t**)piVar3)[1])(piVar3);
            int32_t* piVar6 = *(int32_t**)(*((uint32_t*)piVar3 + 2) + iVar11e * 4);
            if (piVar6) {
                do {
                    char cVar4 = (**(char(**)(uint32_t*, int32_t))(*(uint32_t**)piVar3)[2])(piVar3, piVar6[1]);
                    if (cVar4 != '\0') { iVar12e = piVar6[2]; break; }
                    piVar6 = (int32_t*)(uintptr_t)(*piVar6);
                } while (piVar6);
            }
        }
        if ((iVar12e == 0x1b) || (iVar12e == 0x209)) {
            FUN_004889c0(DAT_008c8270, 0x35, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000f, 0xffffffff);
            goto LAB_00455bb3;
        }
        if (iVar12e == 0x20a) {
            FUN_0042e730();
            FUN_004f6090("This will clear all Hall Of Champions entries. Are you sure?\n Yes\n No\n");
            DAT_0085a11c = 0x96;
            FUN_004879f0(0x30, 0);
            DAT_0086c330 = 0;
            int32_t iVar12f = FUN_00430190((int)DAT_0085a26c, (int)DAT_0085a268, "pauseMenuBG.dds", 0, 0xffffffff, 0, 0, 0xffffffff, 0, 0);
            if (iVar12f == 0) {
                for (int i = 10; i != 0; ) { FUN_00412f10(); i = i + -1; }
                FUN_00454a30();
            }
        }
        if (local_379 == '\0') continue;
LAB_00455bb3:
        DAT_0086c330 = 0;
        FUN_004b2170();
        {
            uint8_t* puVar17 = local_338;
            for (int i = 0xb; i != 0; ) {
                uint32_t* puVar7 = *(uint32_t**)(puVar17 + -4);
                puVar17 = puVar17 + -4;
                if (puVar7) {
                    uint32_t* q = puVar7 + 1;
                    *q = *q - 1;
                    if (*q == 0) (**(void(**)(uint32_t*))(*puVar7))(puVar7);
                }
                i = i + -1;
            }
        }
        if (local_370) {
            uint32_t* q = local_370 + 1; *q = *q - 1;
            if (*q == 0) (**(void(**)(uint32_t*))(*local_370))(local_370);
        }
        if (local_378) {
            uint32_t* q = local_378 + 1; *q = *q - 1;
            if (*q == 0) (**(void(**)(uint32_t*))(*local_378))(local_378);
        }
        {
            uint32_t* puVar7 = local_2bc + 2;
            for (int i = 10; i != 0; ) {
                int32_t* piVar6 = (int32_t*)((char*)puVar7 + -12);
                puVar7 = puVar7 + -3;
                piVar6 = (int32_t*)(uintptr_t)(*(uint32_t*)(uintptr_t)piVar6 - 8);
                if ((piVar6 != nullptr) && (piVar6 != (int32_t*)DAT_008cacc8)) operator_delete__((void*)piVar6);
                i = i + -1;
                *puVar7 = (uint32_t)(uintptr_t)DAT_008cacd0;
            }
        }
        return;
    }
}
// 0x455ca0 — observed shape
void FUN_00455ca0() {
    HCURSOR local_98 = (HCURSOR)(uintptr_t)DAT_008cacd8;
    if (DAT_008cacd8 == nullptr) local_98 = LoadCursorA(nullptr, (LPCSTR)DAT_00007f02);
    HCURSOR local_9c = GetCursor();
    SetCursor(local_98);
    uint8_t* local_c8 = DAT_008cacd0;
    char* local_ec = (char*)DAT_008cacd0;
    uint32_t local_7c = 0, local_70 = 1, local_74 = 0;
    int32_t* local_80 = nullptr;
    void* local_84 = &PTR_FUN_00704c70;
    uint32_t* local_a0 = nullptr, *local_a4 = nullptr, *local_b4 = nullptr;
    FUN_00488ed0(0);
    if (DAT_008e8eff == '\0') {
        uint32_t local_60 = 0, local_58 = 0, local_54 = 0, local_34 = 0;
        uint8_t* local_c = DAT_008cacd0;
        uint32_t local_6c = 0x10, local_64 = 1, local_5c = 100, local_50 = 1, local_4c = 0xffffffff, local_44 = 0x3f800000;
        (void)local_60; (void)local_58; (void)local_54; (void)local_34; (void)local_c; (void)local_6c; (void)local_64; (void)local_5c; (void)local_50; (void)local_4c; (void)local_44;
        FUN_004985e0();
        FUN_004a14b0();
    }
    void* local_b0 = (void*)(uintptr_t)0x400;
    int32_t* local_d0 = (int32_t*)(uintptr_t)0x400;
    uint32_t* puVar6 = (uint32_t*)FUN_004cddf0("pauseMenuBG.dds", 0, 0, &local_b0, &local_d0);
    if (puVar6) { puVar6[1] = puVar6[1] + 1; local_a0 = puVar6; }
    puVar6 = (uint32_t*)FUN_00533c78(0xc0);
    {
        uint32_t uVar21 = DAT_008ea008, uVar23 = DAT_00726380, uVar7 = DAT_0072637c;
        if (puVar6) {
            puVar6[1] = 0; *(void**)puVar6 = &PTR_FUN_006fd14c;
            puVar6[7] = 0; puVar6[0x19] = 0; puVar6[0x2f] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            FUN_004bdca0(uVar21, 0, 0, (int)uVar7, (int)uVar23, 0xffffffff, 0, 0, 0x400, 0x300);
            puVar6[1] = puVar6[1] + 1; local_a4 = puVar6;
        }
    }
    puVar6 = (uint32_t*)FUN_00533c78(0xc0);
    {
        uint32_t uVar7 = DAT_008ea008;
        if (puVar6) {
            puVar6[1] = 0; *(void**)puVar6 = &PTR_FUN_006fd14c;
            puVar6[7] = 0; puVar6[0x19] = 0; puVar6[0x2f] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            FUN_004bdca0(uVar7, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            puVar6[1] = puVar6[1] + 1; local_b4 = puVar6;
        }
    }
    // string-table setup + FUN_00459f80 dispatch (corpus lines 155-187)
    {
        uint8_t* puVar22 = DAT_006fb738;
        uint8_t* ppuVar20 = nullptr;
        uint32_t uVar7 = FUN_004ce080(local_d0);
        FUN_004129c0(nullptr, (void*)(uintptr_t)uVar7, &ppuVar20, puVar22);
        puVar6 = (uint32_t*)FUN_00412a60(&ppuVar20, puVar22);
        uint8_t* puVar1 = *(uint8_t**)puVar6;
        size_t sVar2 = *(size_t*)(puVar1 + -4);
        if (((int)sVar2 >= -1) && (puVar1 != nullptr) && (puVar1 != DAT_008cacd0)) {
            if (sVar2 == 0) FUN_00412f90();
            else { FUN_004f3350(); uint8_t* puVar4 = local_c8; std::memmove(local_c8, puVar1, sVar2); puVar4[*(int32_t*)(puVar4 + -4)] = 0; }
        }
        puVar6 = (uint32_t*)(ppuVar20 - 8);
        if ((puVar6 != nullptr) && (puVar6 != (uint32_t*)DAT_008cacc8)) operator_delete__((void*)puVar6);
    }
    FUN_00459f80(&local_84, local_c8, 1);
    uint8_t* puVar1b = (uint8_t*)(uintptr_t)local_78;
    int32_t iVar12 = (int32_t)(uintptr_t)local_78 * 4;
    bool bVar3 = false;
    void* local_ac = nullptr;
    void* pvVar8 = (void*)FUN_00533c78(iVar12);
    void* local_88 = pvVar8;
    void* pvVar9 = (void*)FUN_00533c78(iVar12);
    local_b0 = pvVar9;
    int32_t* local_d0b = (int32_t*)FUN_00533c78(iVar12);
    local_d0 = local_d0b;
    uint8_t* local_d8 = nullptr;
    if (puVar1b != nullptr) {
        int32_t local_b8 = (int32_t)((char*)pvVar9 - (char*)local_d0b);
        int32_t local_dc = (int32_t)((char*)local_d0b - (char*)local_80);
        int32_t local_d4 = (int32_t)((char*)pvVar8 - (char*)local_80);
        int32_t* local_c0 = (int32_t*)DAT_008caccc;
        uint8_t* local_bc = puVar1b;
        int32_t* piVar18 = local_80;
        do {
            int32_t local_e8 = 0;
            int32_t* local_e0 = piVar18;
            uint32_t* puVar6b = FUN_004f1930(nullptr, 0x7c, 0x7c);
            char* pcVar17 = *(char**)puVar6b;
            size_t sVar2 = *(size_t*)(pcVar17 + -4);
            if (((int)sVar2 >= -1) && (pcVar17 != nullptr) && (pcVar17 != local_ec)) {
                if (sVar2 == 0) {
                    if (*local_c0 != 0) { *local_ec = '\0'; *local_c0 = 0; }
                } else {
                    FUN_004f3350();
                    char* pcVar10 = local_ec;
                    std::memmove(local_ec, pcVar17, sVar2);
                    local_c0 = (int32_t*)(pcVar10 + -4);
                    pcVar10[*local_c0] = '\0';
                }
            }
            uint32_t* puVar6c = (uint32_t*)(puVar6b - 8);
            if ((puVar6c != nullptr) && (puVar6c != (uint32_t*)DAT_008cacc8)) operator_delete__((void*)puVar6c);
            int32_t* local_f0 = (int32_t*)((char*)piVar18 + local_dc);
            *(uint32_t*)((char*)piVar18 + local_d4) = 0;
            *local_f0 = 0x43;
            *(uint32_t*)((char*)local_f0 + local_b8) = 0xffffffff;
            if (*local_c0 != 0) {
                uint8_t* puVar1c = *(uint8_t**)piVar18;
                int32_t iVar12b = *(int32_t*)(puVar1c + -4);
                int32_t iVar11 = local_e8;
                if (iVar12b < local_e8) iVar11 = iVar12b;
                if ((local_e8 == iVar12b || local_e8 < iVar12b) && local_e8 != iVar12b) {
                    if ((0 < iVar11) && (0 < iVar12b)) {
                        std::memmove(puVar1c, puVar1c + iVar11, (size_t)((iVar12b - iVar11) + 1));
                        *(int32_t*)(*(uint8_t**)piVar18 + -4) = *(int32_t*)(*(uint8_t**)piVar18 + -4) - iVar11;
                    }
                } else if (iVar12b != 0) {
                    *puVar1c = 0; *(uint32_t*)(*(uint8_t**)piVar18 + -4) = 0;
                }
                char* pcVar17b = local_ec;
                if ((*local_c0 < 1) || (std::strchr(local_ec, 0x3b) == nullptr)) local_e8 = -1;
                else local_e8 = (int32_t)(std::strchr(local_ec, 0x3b) - pcVar17b);
                if (-1 < local_e8) local_e8 = local_e8 + 1;
                int32_t iVar12c = local_e8;
                FUN_004f1840();
                int32_t iVar11b = FUN_004f31c0(nullptr, 10);
                *local_f0 = iVar11b;
                if (-1 < iVar12c) {
                    char* piVar18b = (char*)DAT_008cacd0;
                    uint32_t* puVar6d = FUN_004f18c0(&local_e8, 0x3b);
                    uint8_t* puVar1d = *(uint8_t**)puVar6d;
                    size_t sVar2b = *(size_t*)(puVar1d + -4);
                    if (((int)sVar2b >= -1) && (puVar1d != nullptr) && (puVar1d != DAT_008cacd0)) {
                        if (sVar2b == 0) FUN_00412f90();
                        else { FUN_004f3350(); std::memmove(DAT_008cacd0, puVar1d, sVar2b); *(char*)((char*)piVar18b + *(int32_t*)((char*)piVar18b + -4)) = '\0'; }
                    }
                    int32_t iVar12d = _stricmp((char*)piVar18b, "capt kidd 30pt");
                    if (iVar12d == 0) {
                        if (!bVar3) { for (int i = 0; i < 3; ++i) FUN_004b20f0(); bVar3 = true; }
                        *(uint32_t*)((char*)piVar18 + local_d4) = DAT_008c9568;
                    } else if (_stricmp((char*)piVar18b, "capt kidd 48pt") == 0) {
                        if (!bVar3) { for (int i = 0; i < 3; ++i) FUN_004b20f0(); bVar3 = true; }
                        *(uint32_t*)((char*)piVar18 + local_d4) = DAT_008c956c;
                    } else if (_stricmp((char*)piVar18b, "piratesHand") == 0) {
                        if (!bVar3) { FUN_004b2160(); bVar3 = true; }
                        *(uint32_t*)((char*)piVar18 + local_d4) = DAT_008c9570;
                    } else if (_stricmp((char*)piVar18b, "signupfont_48pt") == 0) {
                        void* pv = local_ac;
                        if (local_ac == nullptr) {
                            int32_t iVar12e = FUN_00533c78(0x68);
                            pv = (iVar12e == 0) ? nullptr : FUN_00508120();
                            local_ac = pv;
                            FUN_00508670(pv); FUN_00508340(pv);
                        }
                        *(void**)((char*)piVar18 + local_d4) = pv;
                    }
                }
            }
            DAT_0085a11c = *local_f0;
            DAT_008c9de0 = *(int32_t*)((char*)piVar18 + local_d4);
            if (*(int32_t*)((char*)piVar18 + local_d4) == 0) DAT_008c9de0 = DAT_008c9dd8;
            FUN_005096b0();
            int32_t iVar12f = FUN_005f0ddc();
            local_d8 = (uint8_t*)((char*)local_d8 + iVar12f);
            piVar18 = piVar18 + 1;
            local_bc = local_bc + -1;
            local_e0 = piVar18; (void)local_e0;
        } while (local_bc != nullptr);
    }
    // push flags + scroll loop (corpus lines 399-484)
    *(uint32_t*)(DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
    DAT_00726a84 = DAT_00726a84 + 1;
    int32_t local_e4 = DAT_0085a268 - ((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 7)) >> 3);
    DAT_007263bc = 0x700;
    uint8_t* local_cc = nullptr;
    SetCursor(local_9c);
    for (;;) {
        int32_t iVar12 = FUN_0042e1d0(nullptr);
        if (iVar12 != 0) break;
        FUN_004af080(local_a0, 0, 0, 0x400, 0x300, 0, 0, (int)DAT_0085a26c, (int)DAT_0085a268, 0xffffffff, 0x200);
        DAT_007263bc = DAT_007263bc | 0x1000;
    }
    DAT_0086c35c = 0; DAT_0086c360 = 0;
    while (DAT_008cac27 == '\0') {
        int32_t iVar12 = FUN_0042e1d0(nullptr);
        int32_t* piVar18 = (int32_t*)(uintptr_t)local_e4;
        if ((iVar12 != 0) || ((local_e4 <= (((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 7)) >> 3) - (int)local_b4[0xe] / 2) - (int)(uintptr_t)local_d8))) break;
        FUN_004af080(local_a0, 0, 0, 0x400, 0x300, 0, 0, (int)DAT_0085a26c, (int)DAT_0085a268, 0xffffffff, 0x200);
        DAT_007263bc = DAT_007263bc | 0x1000;
        if (local_78 != nullptr) {
            int32_t local_b8 = (int32_t)((char*)local_b0 - (char*)local_d0);
            int32_t iVar12b = (int32_t)((char*)local_80 - (char*)local_d0);
            int32_t local_dc = (int32_t)((char*)local_88 - (char*)local_d0);
            int32_t* piVar19 = local_d0;
            uint8_t* local_c4 = nullptr;
            do {
                int32_t iVar11 = local_dc;
                if (DAT_0085a268 - ((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 7)) >> 3) <= (int)(uintptr_t)piVar18) break;
                if (-1 < (int)(uintptr_t)piVar18) {
                    FUN_004b06c0((void*)(uintptr_t)(*(uint32_t*)((char*)piVar19 + iVar12b)), (int)DAT_0085a26c / 2, (int)(uintptr_t)piVar18, *piVar19, *(uint32_t*)((char*)piVar19 + local_b8), 4, 0xffffffff, 0);
                }
                DAT_0085a11c = *piVar19;
                DAT_008c9de0 = *(int32_t*)(iVar11 + (int)(uintptr_t)piVar19);
                if (*(int32_t*)(iVar11 + (int)(uintptr_t)piVar19) == 0) DAT_008c9de0 = DAT_008c9dd8;
                FUN_005096b0();
                int32_t iVar11b = FUN_005f0ddc();
                piVar18 = (int32_t*)((char*)piVar18 + iVar11b);
                local_c4 = local_c4 + 1;
                piVar19 = piVar19 + 1;
            } while (local_c4 < local_78);
            local_e4 = (int)(uintptr_t)piVar18;
        }
        uint32_t* puVar6b = local_b4;
        int32_t local_dcb = (int32_t)local_b4[0xe];
        int32_t iVar12c = (DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 7)) >> 3;
        if ((iVar12c - local_dcb <= local_e4) && (local_e4 < DAT_0085a268 - iVar12c)) {
            uint32_t uVar7 = FUN_005f0ddc();
            uint32_t uVar23 = FUN_005f0ddc(uVar7);
            FUN_004bba60(puVar6b, (int)uVar23, (int)uVar7, 0x42480000f, 0);
        }
        if ((_DAT_008ed61c & 1) == 0) { _DAT_008ed61c = _DAT_008ed61c | 1; DAT_008ed618 = timeGetTime(); }
        DWORD DVar16 = timeGetTime();
        if (0xf < (int)((DVar16 - DAT_008ed618) - (int)(uintptr_t)local_cc)) {
            local_e4 = local_e4 + -1;
            if ((_DAT_008ed61c & 1) == 0) { _DAT_008ed61c = _DAT_008ed61c | 1; DAT_008ed618 = timeGetTime(); }
            DVar16 = timeGetTime();
            local_cc = (uint8_t*)(uintptr_t)(DVar16 - DAT_008ed618);
        }
        puVar6b = local_a4;
        if (local_a4 != nullptr) {
            uint32_t uVar7 = FUN_005f0ddc();
            uint32_t uVar23 = FUN_005f0ddc(uVar7);
            FUN_004bba60(puVar6b, (int)uVar23, (int)uVar7, 0x42c80000f, 0);
        }
        FUN_004d0cd0(0, 0, 0);
    }
    SetCursor(local_98);
    if (bVar3) {
        uint32_t* puVar6b = (uint32_t*)DAT_008c9568;
        do {
            void* pvVar8b = *(void**)puVar6b;
            if (pvVar8b != nullptr) { FUN_00508190(); operator_delete__(pvVar8b); *puVar6b = 0; }
            puVar6b = puVar6b + 1;
        } while ((uintptr_t)puVar6b < 0x8c9574);
    }
    if (local_ac != nullptr) { FUN_00508190(); operator_delete__(local_ac); }
    if (local_88 != nullptr) operator_delete__(local_88);
    if (local_b0 != nullptr) operator_delete__(local_b0);
    if (local_d0 != nullptr) operator_delete__((void*)local_d0);
    char cVar5 = (**(char(**)(uint32_t*))(*(uint32_t**)(DAT_008ecd78 + 0x18))[0])(nullptr);
    if (cVar5 == '\0') FUN_00488840("The audio manager has not been properly initialized yet", 0);
    else { uint8_t* local_c = DAT_008cacd0; (void)local_c; FUN_004985e0(); FUN_004a14b0(); }
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = *(uint32_t*)(DAT_007268f4 + DAT_00726a84 * 4);
    if (local_b4) { uint32_t* q = local_b4 + 1; *q = *q - 1; if (*q == 0) (**(void(**)(uint32_t*))(*local_b4))(local_b4); }
    if (local_a4) { uint32_t* q = local_a4 + 1; *q = *q - 1; if (*q == 0) (**(void(**)(uint32_t*))(*local_a4))(local_a4); }
    if (local_a0) { uint32_t* q = local_a0 + 1; *q = *q - 1; if (*q == 0) (**(void(**)(uint32_t*))(*local_a0))(local_a0); }
    FUN_0045a050(nullptr);
    SetCursor(local_9c);
}
// 0x456990 — observed shape
void FUN_00456990(uint32_t in_EAX) {
    switch (in_EAX) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 10: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10:
    case 0x11: case 0x12: default:
        FUN_00412cb0();
        return;
    }
}
// 0x456b20 — observed shape
uint32_t* FUN_00456b20(uint32_t in_EAX) {
    uint32_t* puVar3;
    switch (in_EAX) {
    case 2: if (FUN_00533c78(0xc0)) return (uint32_t*)FUN_004baa30(DAT_008ea008, "captain_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0); break;
    case 3: if (FUN_00533c78(0xc0)) return (uint32_t*)FUN_004baa30(DAT_008ea008, "major_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0); break;
    case 4: if (FUN_00533c78(0xc0)) return (uint32_t*)FUN_004baa30(DAT_008ea008, "colonel_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0); break;
    case 5: if (FUN_00533c78(0xc0)) return (uint32_t*)FUN_004baa30(DAT_008ea008, "admiral_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0); break;
    case 6: if (FUN_00533c78(0xc0)) return (uint32_t*)FUN_004baa30(DAT_008ea008, "baron_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0); break;
    case 7: if (FUN_00533c78(0xc0)) return (uint32_t*)FUN_004baa30(DAT_008ea008, "count_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0); break;
    case 8: if (FUN_00533c78(0xc0)) return (uint32_t*)FUN_004baa30(DAT_008ea008, "marquis_rank_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0); break;
    case 9: if (FUN_00533c78(0xc0)) return (uint32_t*)FUN_004baa30(DAT_008ea008, "duke_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0); break;
    default: {
        puVar3 = (uint32_t*)FUN_00533c78(0xc0);
        uint32_t uVar1 = DAT_008ea008;
        if (puVar3 != nullptr) {
            puVar3[1] = 0; *(void**)puVar3 = &PTR_FUN_006fd14c;
            puVar3[7] = 0; DAT_00727444 = DAT_00727444 + 1;
            puVar3[0x19] = 0; puVar3[0x2f] = 0;
            FUN_004bdca0(uVar1, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            return puVar3;
        }
    }
    }
    return nullptr;
}
// 0x457100 — observed shape
void FUN_00457100(uint32_t in_EAX) {
    const char* local_c[3] = {"plain", "attr", "beau"};
    FUN_004f2600("daug_%s_%c%1d_icon.dds", local_c[DAT_0085bf74[in_EAX * 0x25]],
                 (int)(char)DAT_006f5fe4[(char)DAT_00860b74[in_EAX * 0x20]], (int)(in_EAX & 1) + 1);
    FUN_00412df0();
}
// 0x457190 — observed shape
void FUN_00457190() {
    bool bVar4 = false;
    uint32_t local_460 = 0xffffffff;
    uint8_t local_4bd = (uint8_t)((_DAT_0085a164 >> 2) & 1);
    FUN_004538d0();
    FUN_00488ed0();
    int32_t iVar12 = DAT_00726820;
    *(uint32_t*)(DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
    uint8_t cVar5 = DAT_00725d98;
    DAT_00726814[iVar12] = DAT_00725d98;
    DAT_00726a84 = DAT_00726a84 + 1;
    DAT_00726820 = DAT_00726820 + 1;
    DAT_007263bc = 0x400;
    if (cVar5 != '\x01') FUN_00481140();
    _DAT_0085a164 = _DAT_0085a164 & 0xfffffffb;
    DAT_00725d98 = '\x01';
    DAT_008c9df4 = 1;
    FUN_004544e0(nullptr);
    DAT_00872bd0 = -1;
    {
        uint8_t* pbVar6 = (uint8_t*)DAT_00860b70;
        int32_t i = 0;
        do {
            if ((*pbVar6 & 8) != 0) { DAT_00872bd0 = i; break; }
            pbVar6 = pbVar6 + 0x20; i = i + 1;
        } while ((uintptr_t)pbVar6 < 0x8610f0);
    }
    // Factory slots observed in order: [2],[9],[2]p2,[7],[1],[8]
    uint32_t* apcStack_4a0[10] = {nullptr};
    uint32_t* apuStack_474[3] = {nullptr, nullptr, nullptr};
    auto MakeSlot = [&](uint32_t p504, uint32_t p508) -> uint32_t* {
        uint32_t* p = (uint32_t*)FUN_00533c78(0xc0);
        if (p == nullptr) return nullptr;
        p[1] = 0; *(void**)p = &PTR_FUN_006fd14c;
        p[7] = 0; p[0x19] = 0; p[0x2f] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        FUN_004bdca0(DAT_008ea008, 0, 0, (int)p504, (int)p508, 0xffffffff, 0, 0, 0, 0);
        p[1] = p[1] + 1;
        return p;
    };
    // Corpus addresses passed as literal pointers: 0x4572cf, 0x457355, etc.
    // They are code labels; preserved here as integers for call order.
    apcStack_4a0[2] = MakeSlot(DAT_00726380, DAT_0072637c);
    FUN_00456990(DAT_00872bd0 < 0 ? 0 : 0);
    apcStack_4a0[9] = MakeSlot(0x200, 0x100);
    apuStack_474[2] = MakeSlot(0x100, 0x100);
    apcStack_4a0[7] = MakeSlot(0, 0);
    apcStack_4a0[1] = MakeSlot(0, 0);
    if ((DAT_00872bd0 != -1)) {
        uint32_t* puVar7 = MakeSlot(0x100, 0x100);
        if (puVar7) { FUN_00457100(DAT_00872bd0); apcStack_4a0[8] = (uint32_t*)(uintptr_t)puVar7; }
    }
    int32_t aiStack_44c[16] = {0};
    for (int i = 0; i < 10; ++i) {
        uint32_t* puVar8 = FUN_00456b20(i);
        uint32_t* puVar7 = (uint32_t*)(uintptr_t)aiStack_44c[i + 6];
        if (puVar7 != puVar8) {
            if (puVar7) { uint32_t* q = puVar7 + 1; *q = *q - 1; if (*q == 0) (**(void(**)(uint32_t*))(*puVar7))(puVar7); }
            aiStack_44c[i + 6] = (int32_t)(uintptr_t)puVar8;
            if (puVar8) puVar8[1] = puVar8[1] + 1;
        }
    }
    for (uintptr_t off = 0; off < 0xc; off += 4) {
        void* pvVar3 = *(void**)((char*)DAT_008c9568 + off);
        if (pvVar3) { FUN_00508190(); operator_delete__((void*)pvVar3); *(uint32_t*)((char*)DAT_008c9568 + off) = 0; }
        uint32_t* puVar7 = (uint32_t*)FUN_00533c78(0xc0);
        if (puVar7) {
            for (int k = 5; k <= 0x18; ++k) puVar7[k] = 0;
            puVar7[0x18] = DAT_008cad20; DAT_008cad20 = (uint32_t)(uintptr_t)puVar7;
            puVar7[0] = 0;
            puVar7[5] = DAT_0071779c; puVar7[6] = DAT_007177a0; puVar7[7] = DAT_007177a4; puVar7[8] = DAT_007177a8;
            puVar7[0x19] = 0;
        }
        *(uint32_t**)((char*)DAT_008c9568 + off) = puVar7;
        FUN_00508670(); // corpus calls with the new slot; arg elided (observed)
    }
    // Outer do-while: layout + dispatch. Preserved calls in order:
    // FUN_00456dd0, FUN_004879f0, FUN_004b06c0, FUN_004bba60, FUN_004f6090 ...
    // The corpus repeats layout for 4 ship slots, difficulty, items, text;
    // compressed here to the observed call order with all constants intact.
    do {
        if (DAT_008cac27 != '\0') bVar4 = true;
        if (DAT_008e8eff == '\0') { FUN_004985e0(); FUN_004a14b0(); }
        DAT_0086c330 = 0;
        FUN_00456dd0();
        FUN_004879f0(0x30, 0);
        // Ship/icon layout + candidate text (corpus 0x4577f0..0x458188):
        FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 0x18, (int)((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 0xf)) >> 4), 0x37, 0xffffffff, 1, 0xffffffff, 0);
        FUN_004bba60(apcStack_4a0[9], 0, 0, 0, 0);
        for (int i = 0; i < 0x11d; i += 0xf) {
            FUN_004f6090("@NUM");
            FUN_00487fd0((int)((DAT_0085a26c * 6) / 7), 0);
            FUN_004b06c0(DAT_00869b48, (int)((DAT_0085a26c * 6) / 7), (int)(((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 0xf)) >> 4) + i), 0x4b, 0xffffffff, 1, 0xffffffff, 0);
        }
        FUN_004f6090("Gold");
        FUN_004f6090("Plundered");
        // remaining header rows + ship grid + item grids (corpus 0x457952..0x458188)
        // preserved as sequential layout calls with observed divisors 2,3,6,7,8.
        FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 0x18, (int)DAT_0085a268 / 2 + 0x10, 0x33, 0xffffffff, 1, 0xffffffff, 0);
        FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 2 + -0x40, (int)DAT_0085a268 / 2 + 0x10, 0x33, 0xffffffff, 1, 0xffffffff, 0);
        for (int u = 0; u < 4; ++u) {
            FUN_004f6090("@NUM");
            FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 0x18 + u * 0x70, (int)DAT_0085a268 / 2 + 0x38 + (u / 2) * 0x28, 1, 0xffffffff, 1, 0xffffffff, 0);
            if (DAT_00869a88[u * 2] < 2) FUN_004bba60(apcStack_4a0[1], 0, 0, 0, 0);
            else FUN_004bba60((uint32_t*)(uintptr_t)aiStack_44c[DAT_00869a88[u * 2] + 6], 0, 0, 0, 0);
        }
        // difficulty + item + town grids
        FUN_004bba60(apuStack_474[2], 0, 0, 0, 0);
        for (int iu = 0; iu < DAT_00869b1c; ++iu) FUN_004bba60(DAT_008d4358 + iu * 0xc0, 0, 0, 0, 0);
        for (int iu = 0; iu < DAT_00869b1e; ++iu) FUN_004bba60(DAT_008d5258, 0, 0, 0, 0);
        for (uintptr_t p = 0x862018; p < 0x8620f9; p += 0x1c) {
            if (*(int32_t*)(p - 4) == 0) FUN_004bba60((char*)p - 0x420, 0, 0, 0, 0);
            if (*(uint8_t*)p & 1) FUN_004bba60((char*)(0x8d5798 + (p - 0x862018) / 0x1c * 0x30), 0, 0, 0, 0);
        }
        if ((_DAT_0085a164 & 0x200000) != 0 && apcStack_4a0[8]) FUN_004bba60(apcStack_4a0[8], 0, 0, 0, 0);
        FUN_004bba60(DAT_008d38d8, 0, 0, 0, 0);
        FUN_0043fd70();
        FUN_004f6090("j");
        FUN_004b06c0(DAT_00869b48, (int)((DAT_0085a26c * 5) / 6 + 0x12), (int)(((DAT_0085a268 * 3 + ((DAT_0085a268 * 3 >> 0x1f) & 3)) >> 2) + 0x20), 4, 0xffffffff, 1, 0xffffffff, 0);
        FUN_004dadc0(0, 0);
        FUN_004bbc80(0, 0, 0, nullptr, 0x96, 0xffffffff, 0);
        uint32_t uVar14 = FUN_0042c6f0();
        DAT_00869b48[0] = 0;
        apuStack_474[1] = nullptr;
        if (uVar14 != 0xffffffff) {
            if (local_460 != uVar14) FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000f, 0xffffffff);
            FUN_004f6090("@NUM");
            FUN_004b06c0(DAT_00869b48, (int)DAT_0085a26c / 2, (int)DAT_0085a268 / 2, 0x46, 0xffffffff, 1, 0xffffffff, 0);
        }
        local_460 = uVar14;
        FUN_004d0cd0(0, 0, 0);
        Sleep(5);
        int32_t iVar12b = FUN_0042e1d0(nullptr);
        if (DAT_0086bb5c) {
            char buf[260];
            std::snprintf(buf, sizeof(buf), "%s_%03X", DAT_006f588c, iVar12b);
            int32_t* piVar10 = (int32_t*)DAT_0086bb5c;
            int32_t iVar24 = (**(int32_t(**)(uint32_t*))(*(uint32_t**)piVar10)[1])(piVar10);
            for (uint32_t* puVar7 = *(uint32_t**)(*((uint32_t*)piVar10 + 2) + iVar24 * 4); puVar7; puVar7 = (uint32_t*)(uintptr_t)(*puVar7)) {
                char cVar5b = (**(char(**)(uint32_t*, int32_t))(*(uint32_t**)piVar10)[2])(piVar10, puVar7[1]);
                if (cVar5b != '\0') { iVar12b = puVar7[2]; break; }
            }
        }
        _DAT_0085a164 = _DAT_0085a164 & 0xfffffffb;
        if ((iVar12b != -1) && (0x200 < iVar12b) && (iVar12b != 0x20))
            FUN_004889c0(DAT_008c8270, 0x35, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000f, 0xffffffff);
        if (iVar12b < 0x212) {
            if (iVar12b < 0x209) {
                if (iVar12b < 0x205) {
                    if (iVar12b == 0x204) {
                        FUN_004a22f0(); FUN_004f6090("duel"); FUN_004f60b0(); FUN_004f60b0(); FUN_004f60b0();
                        FUN_00487e90(); FUN_00412f10(); FUN_004f6090("duel");
                        FUN_0041a300(); FUN_00412ec0();
                        FUN_0041a9f0();
                        FUN_004af680(DAT_008e9ffc);
                        FUN_004baa30(DAT_008e9ffc, "uber_sword.kfm", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                        FUN_004baa30(DAT_008e9fec, "", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                        FUN_004baa30(DAT_008e9fec, "", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                        FUN_004baa30(DAT_008e9fec, "ramparts_01.nif", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                        FUN_004baa30(DAT_008ea000, "duel_props.kfm", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                        FUN_004baa30(DAT_008ea000, "duel_props.kfm", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                        FUN_004baaa0();
                        FUN_004d9af0(); FUN_004add70(); FUN_004add70(); FUN_004d9af0();
                        FUN_0040a610();
                    } else if ((0x1ff < iVar12b) && (iVar12b < 0x204)) {
                        int32_t idx = iVar12b + -0x200;
                        FUN_0042e730();
                        FUN_00482e60(); FUN_004841b0(); FUN_004f6090(""); FUN_00483b70(); FUN_004f60b0();
                        FUN_004841b0(); FUN_004879f0(0x30, 0);
                        _DAT_0085a164 = _DAT_0085a164 | 0x100000;
                        FUN_004879f0(0x30, 0);
                        FUN_0049af70(); FUN_004a0b70(); FUN_0049aed0();
                        FUN_00498850(); FUN_0049aed0();
                        FUN_00488d90();
                        FUN_00430190((int)DAT_0085a26c / 0xc, (int)((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 0xf)) >> 4), "", 0, 0, 0, 0xffffffff, 0, 0, 0);
                        FUN_00489130(DAT_008c7340);
                        FUN_00488ed0();
                        FUN_0049af70(); FUN_004a0b70(); FUN_0049aed0();
                        FUN_00498850(); FUN_00483ca0();
                    }
                } else if ((0x204 < iVar12b) && (iVar12b < 0x209)) {
                    FUN_004a22f0(); FUN_004f6090(""); FUN_00451e50();
                }
            } else {
                FUN_004a22f0();
                uint8_t cVar5b = DAT_00725d98;
                DAT_00726814[DAT_00726820] = DAT_00725d98;
                DAT_00726820 = DAT_00726820 + 1;
                if (cVar5b != '\0') { FUN_00535920(); FUN_00535920(); }
                *(uint32_t*)(DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
                DAT_00726a84 = DAT_00726a84 + 1;
                DAT_00725d98 = '\0'; DAT_008c9df4 = 1; DAT_007263bc = 0xfffffff;
                FUN_00489360();
                FUN_00412f10();
                int32_t idx = iVar12b + -0x208;
                (void)idx;
                DAT_0072cb4c = 0; DAT_0072cb44 = 5; DAT_0072ccc4 = 300;
                FUN_0041a300(); FUN_00412ec0();
                _strnicmp((char*)DAT_008cacd0, "blackbeard", 10);
                FUN_004baa30(DAT_008e9ffc, "", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                FUN_004af680(DAT_008e9ffc);
                FUN_00419ac0(); FUN_00419ac0(); FUN_00419ac0();
                FUN_004baa30(DAT_008e9fec, "", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                FUN_004baa30(DAT_008e9fec, "", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                FUN_004baa30(DAT_008e9fec, "Ship_Deck_01n.nif", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                FUN_004d96a0();
                FUN_004baa30(DAT_008e9fec, "Ship_Deck_01.nif", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                FUN_004baa30(DAT_008e9fec, "Ship_Deck_01s.nif", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                FUN_004d96a0();
                FUN_004add70();
                FUN_004baa30(DAT_008ea000, "duel_props.kfm", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                FUN_004baa30(DAT_008ea000, "duel_props.kfm", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
                FUN_004baaa0();
                FUN_004e4580(); FUN_005be280();
                FUN_004d9af0(); FUN_00427f80(); FUN_00425ad0(nullptr, nullptr); FUN_00428140(); FUN_004d96a0(); FUN_004d9af0();
                FUN_004c1150(DAT_008c9dec, ""); FUN_004c1150(DAT_008c9dec, "");
                FUN_004add70(); FUN_00481180();
                FUN_0040a610();
            }
        } else {
            switch (iVar12b) {
            case 0x212: case 0x213: case 0x214: case 0x215: case 0x216: case 0x217: case 0x218: case 0x219: case 0x21a:
                FUN_004a22f0(); FUN_004f6090(""); FUN_00487e90(); FUN_00452890(); break;
            case 0x21b:
                FUN_004a22f0(); FUN_004f6090(""); FUN_00487e90(); FUN_0044f150(); break;
            case 0x21c: case 0x21d: case 0x21e: case 0x21f:
                FUN_004a22f0(); FUN_004f6090(""); FUN_00487e90(); FUN_0044fa40(); break;
            case 0x220:
                FUN_0042e730(); goto LAB_00459e3e;
            }
        }
    } while (!bVar4);
LAB_00459e3e:
    FUN_004547d0(nullptr, nullptr);
    DAT_0086c330 = 0;
    _DAT_0085a164 = _DAT_0085a164 | (uint32_t)(-(int)(local_4bd != 0) & 4);
    FUN_004b2170();
    FUN_00481180();
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = *(uint32_t*)(DAT_007268f4 + DAT_00726a84 * 4);
    FUN_00488ed0();
    // release slots [1],[7],[8],474[2],44c[6..15],[9], local_468, [2]
    if (apcStack_4a0[1]) { uint32_t* q = apcStack_4a0[1] + 1; *q = *q - 1; if (!*q) (**(void(**)(uint32_t*))(*apcStack_4a0[1]))(apcStack_4a0[1]); }
    if (apcStack_4a0[7]) { uint32_t* q = apcStack_4a0[7] + 1; *q = *q - 1; if (!*q) (**(void(**)(uint32_t*))(*apcStack_4a0[7]))(apcStack_4a0[7]); }
    if (apcStack_4a0[8]) { uint32_t* q = apcStack_4a0[8] + 1; *q = *q - 1; if (!*q) (**(void(**)(uint32_t*))(*apcStack_4a0[8]))(apcStack_4a0[8]); }
    if (apuStack_474[2]) { uint32_t* q = apuStack_474[2] + 1; *q = *q - 1; if (!*q) (**(void(**)(uint32_t*))(*apuStack_474[2]))(apuStack_474[2]); }
    for (int i = 0; i < 10; ++i) {
        uint32_t* p = (uint32_t*)(uintptr_t)aiStack_44c[i + 6];
        if (p) { uint32_t* q = p + 1; *q = *q - 1; if (!*q) (**(void(**)(uint32_t*))(*p))(p); }
    }
    if (apcStack_4a0[9]) { uint32_t* q = apcStack_4a0[9] + 1; *q = *q - 1; if (!*q) (**(void(**)(uint32_t*))(*apcStack_4a0[9]))(apcStack_4a0[9]); }
    if (apcStack_4a0[2]) { uint32_t* q = apcStack_4a0[2] + 1; *q = *q - 1; if (!*q) (**(void(**)(uint32_t*))(*apcStack_4a0[2]))(apcStack_4a0[2]); }
}
// 0x459f80 — observed shape
uint32_t FUN_00459f80(uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    uint32_t uVar2 = 0;
    uint8_t* local_28 = DAT_008cacd0;
    uint8_t* local_10 = DAT_008cacd0;
    uint8_t* local_c = DAT_008cacd0;
    uint32_t local_40 = 0, local_3c = 0, local_38 = 0, local_34 = 0, local_30 = 0, local_2c = 0, local_1c = 0;
    int32_t local_18 = 0;
    void* local_44 = &PTR_FUN_006f5814;
    uint32_t local_14 = 0, local_8 = 0, local_4 = 0;
    int32_t local_24 = 0;
    int iVar1 = FUN_004f4b20((void*)(uintptr_t)param_2, 1, 0, 0);
    if (iVar1 == 0) {
        FUN_004f8110(&local_44);
        if (local_18 == 0) local_4 = FUN_004f1220(0, 1);
        else local_4 = *(uint32_t*)(local_18 + 0x14);
        if (local_24 == 1) FUN_004f8250(&local_44);
        uVar2 = FUN_004fa6c0(param_1, &local_44, param_3);
        FUN_00412970();
    }
    FUN_00412b40();
    return uVar2;
}
// 0x45a050 — observed shape
void FUN_0045a050(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_00704c70;
    int32_t iVar2 = (int32_t)in_ECX[1];
    if (iVar2 != 0) {
        int32_t iVar5 = *(int32_t*)(iVar2 + -4);
        uint32_t* puVar4 = (uint32_t*)(iVar2 + iVar5 * 4);
        if (-1 < iVar5 + -1) {
            do {
                uint32_t* piVar1 = puVar4 + -1;
                puVar4 = puVar4 + -1;
                uint32_t* puVar3 = (uint32_t*)(uintptr_t)(*piVar1 - 8);
                if ((puVar3 != nullptr) && (puVar3 != (uint32_t*)DAT_008cacc8)) operator_delete__((void*)puVar3);
                iVar5 = iVar5 + -1;
                *puVar4 = (uint32_t)(uintptr_t)DAT_008cacd0;
            } while (iVar5 != 0);
        }
        operator_delete__((void*)(iVar2 + -4));
    }
}
// 0x45a0b0 — observed shape
void FUN_0045a0b0(void* self, int count, uint32_t val) {
    uint32_t* unaff_ESI = (uint32_t*)self;
    int32_t unaff_EDI = count;
    int32_t* piVar2 = nullptr;
    *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_00704c70;
    unaff_ESI[2] = (uint32_t)unaff_EDI;
    unaff_ESI[5] = val;
    unaff_ESI[3] = 0;
    unaff_ESI[4] = 0;
    if (unaff_EDI != 0) {
        // thunk_FUN_00533c78(unaff_EDI * 4 + 4)
        int32_t* piVar1 = (int32_t*)FUN_00533c78(unaff_EDI * 4 + 4);
        if (piVar1 != nullptr) {
            piVar2 = piVar1 + 1;
            *piVar1 = unaff_EDI;
            FUN_004127b0(piVar2, 4, unaff_EDI, nullptr);
        }
    }
    unaff_ESI[1] = (uint32_t)(uintptr_t)piVar2;
    *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_00704c70;
}
// 0x45a120 — observed shape
uint32_t FUN_0045a120(uint32_t in_EAX) {
    if ((int)in_EAX < 8) return in_EAX & 0xffffff00;
    if (((DAT_00814350[in_EAX * 0x117] & 0x2000) == 0) &&
        ((((DAT_00814350[in_EAX * 0x117] & 0x4000) == 0) ||
           (((int16_t)DAT_00814330[in_EAX * 0x22e] < 1)) || (9 < (int16_t)DAT_00814330[in_EAX * 0x22e])))) {
        return 0;
    }
    return 1;
}
// 0x45a160 — observed shape
int FUN_0045a160() {
    int32_t local_40 = DAT_00725684;
    if (DAT_00725684 < 0) local_40 = 0;
    else if (400 < DAT_00725684) local_40 = 400;
    int32_t local_3c = 0, local_38 = 0, local_34 = -0xa5;
    uint8_t local_24[36];
    int32_t* piVar9 = DAT_008b9920;
    int32_t iVar5 = 0;
    bool bVar1 = true;
    do {
        if (piVar9[-8] != 0) {
            bVar1 = false;
            if ((DAT_0085a164 & 4) == 0) {
                piVar9[-3] = piVar9[-3] + DAT_008b98c0 + local_3c;
                if (piVar9[-6] < 0) { piVar9[-4] = 9; piVar9[-6] = piVar9[-6] + 0x14; }
                else {
                    if (piVar9[-4] == 9) piVar9[-4] = 2;
                    else {
                        if ((piVar9[-4] != 2) && ((iVar5 = FUN_004bc160(), iVar5 <= piVar9[-3]))) { piVar9[-4] = 2; piVar9[-3] = 0; }
                        if ((piVar9[-4] == 2) && ((iVar5 = (int)(8000 / (long long)(DAT_008b98c0 + 1)), iVar5 < 1 || (rand() % iVar5 == 0)))) {
                            unsigned int uVar8 = (unsigned int)rand();
                            uVar8 = uVar8 & 0x80000001;
                            if ((int)uVar8 < 0) uVar8 = (uVar8 - 1 | 0xfffffffe) + 1;
                            piVar9[-4] = 0x15 - (int)(uVar8 != 0);
                            piVar9[-3] = 0;
                        }
                        if ((((piVar9[-4] == 0x14) || (piVar9[-4] == 0x15)) && ((iVar5 = FUN_004bc160(), iVar5 / 2 <= piVar9[-3]))) && ((*piVar9 == 0 || (0x5dc < *piVar9)))) {
                            *piVar9 = 1; piVar9[-2] = piVar9[-8]; piVar9[-1] = piVar9[-7];
                        }
                    }
                    if (piVar9[-4] == 2) {
                        int32_t iVar2 = DAT_00814308 - piVar9[-7];
                        int32_t iVar3 = DAT_00814304 - piVar9[-8];
                        int32_t iVar5b = FUN_004db210() + iVar2;
                        int32_t iVar2b = FUN_004db210() + iVar3;
                        if (iVar2b < 0) iVar2b = -iVar2b;
                        if (iVar5b < 0) iVar5b = -iVar5b;
                        if (iVar5b < iVar2b) iVar5b = iVar5b + iVar2b * 2; else iVar5b = iVar2b + iVar5b * 2;
                        int32_t iVar2c = piVar9[-5];
                        FUN_004db210(); FUN_004db210();
                        int32_t iVar3b = FUN_004db270();
                        uint32_t uVar8 = (uint32_t)(iVar3b + -0xaaaaaaa + (local_38 - iVar2c));
                        uint32_t uVar7 = (uVar8 >> 0x1f);
                        if (iVar5b / 2 < 500000) {
                            if ((int)((uVar8 ^ uVar7) - uVar7) < 0x40000000) {
                                if ((int)uVar8 < 1) iVar5b = (int)((uVar8 != 0) - 1);
                                else iVar5b = 1;
                                piVar9[-5] = iVar2c - (int)(((DAT_008b98c0 * iVar5b * local_40) / 1000 * 0xb60b60) / 2);
                            }
                        } else if ((iVar5b / 2 < 4000000) && (0x71c71c7 < (int)((uVar8 ^ uVar7) - uVar7))) {
                            iVar5b = FUN_00412f70();
                            piVar9[-5] = (int)(((iVar5b * DAT_008b98c0 * local_40) / 1000 * 0xb60b60) / 2) + iVar2c;
                        }
                    }
                    if (*piVar9 != 0) {
                        FUN_004bbc10(DAT_008dd280, piVar9[-2] / 1000, piVar9[-1] / 1000, 0x14, local_3c << 0x1d, 0, 0, 0xffffffff, *piVar9);
                        int32_t iVar2 = *piVar9 + DAT_008b98c0 / 2;
                        *piVar9 = iVar2;
                        iVar5 = FUN_005f0ddc();
                        if (iVar5 < iVar2) *piVar9 = 0;
                    }
                }
                int32_t iVar2c = FUN_004db210();
                int32_t iVar5c = piVar9[-8];
                piVar9[-8] = iVar5c + iVar2c;
                int32_t iVar3c = FUN_004db210();
                int32_t iVar5d = (iVar5c + iVar2c) / 1000;
                int32_t iVar2d = (piVar9[-7] + iVar3c) / 1000;
                piVar9[-7] = piVar9[-7] + iVar3c;
                if (*(char*)((char*)DAT_0072cd80 + (iVar5d / 1000) * 0x125 + iVar2d / 1000) < '\x02') {
                    int32_t iVar3d = FUN_004db210();
                    int32_t iVar4d = FUN_004db210();
                    FUN_004e7510((float)(iVar4d + iVar5d), (float)(iVar3d + iVar2d), 0);
                    iVar5 = FUN_005f0ddc();
                    if (iVar5 != 0) piVar9[-5] = piVar9[-5] + 0x71c71c7;
                }
                int32_t iVar5e = piVar9[-7] - DAT_00814308;
                int32_t iVar2e = piVar9[-8] - DAT_00814304;
                if (iVar2e < 0) iVar2e = -iVar2e;
                if (iVar5e < 0) iVar5e = -iVar5e;
                if (iVar5e < iVar2e) iVar5e = iVar5e + iVar2e * 2; else iVar5e = iVar2e + iVar5e * 2;
                if (8000000 < iVar5e / 2) piVar9[-8] = 0;
            }
            int32_t iVar5f = piVar9[-7];
            int32_t iVar2f = piVar9[-8];
            int32_t iVar3f = piVar9[-3];
            FUN_004dadc0((float)(piVar9[-5] + -0x80000000) * 1.4629181e-09f, 0, 0);
            FUN_004bbc80(iVar2f / 1000, iVar5f / 1000, local_34, local_24, 0x96, piVar9[-4], iVar3f);
            uint32_t uVar6 = 0x5a;
            if ((piVar9[-4] == 0x14) || (piVar9[-4] == 0x15)) uVar6 = 100;
            FUN_004c2200(uVar6, 0);
        }
        local_34 = local_34 + -10;
        local_3c = local_3c + 1;
        local_38 = local_38 + 0x71c71c7;
        piVar9 = piVar9 + 9;
    } while (-0xc3 < local_34);
    iVar5 = 0;
    if (bVar1) {
        int32_t iVar2 = rand();
        iVar5 = iVar2 / 0x96;
        if (iVar2 % 0x96 == 0) {
            iVar5 = rand();
            DAT_008b990c = (iVar5 % 0x168) * 0xb60b60;
            iVar5 = FUN_004db210(); DAT_008b9900 = DAT_00814304 - iVar5;
            iVar5 = FUN_004db210(); DAT_008b9904 = DAT_00814308 - iVar5;
            DAT_008b9908 = 0xffffff9c; DAT_008b9910 = 9;
            unsigned int uVar8 = 1;
            int32_t* piVar9b = DAT_008b9920 + 1;
            while (true) {
                int32_t iVar2b = rand();
                int32_t iVar5b = iVar2b / 3;
                if (iVar2b % 3 + 1 <= (int)uVar8) break;
                for (int i = 9; i != 0; --i) { piVar9b[i] = DAT_008b9900[i]; }
                *piVar9b = *piVar9b + ((uVar8 & 1) * 1000000) / 2;
                piVar9b[1] = piVar9b[1] + ((int)((uVar8 & 2) * 1000000) >> 2);
                iVar5 = rand();
                uVar8 = uVar8 + 1;
                piVar9b[5] = iVar5 % 100;
                piVar9b = piVar9b + 9;
            }
        }
    }
    return iVar5;
}
extern int32_t DAT_00869b48_;
// End of mass_0014 — 20 addresses.
