// Reconstruction batch mass_0106 — Sid Meier's Pirates! (2004), PE32 i386.
// Ghidra 12.2 pseudocode translated to C++ candidate definitions.
// Field offsets, constants, call order, and control flow preserved as observed.

#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005077f0(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_00507d20(int param_1);
extern void FUN_005561b0(int param_1, int param_2);
extern void* FUN_00533c78(int param_1);
extern void FUN_0054b990();
extern void operator_delete(void* p) noexcept;
extern void operator_delete__(void* p);
// ---------------------------------------------------------------------------
// 0x5244b0 — vtable/list dispatch with fallback to FUN_005077f0
// Observed: self+0x24 vtable pointer; walk self-chain via (+4) link;
// if node == DAT_008ea510 and self[0xa7] == self (0x24+0xa3) then indirect
// call through vtable+0xac; otherwise fall through to FUN_005077f0.
// Register receiver in_ECX -> self.
// ---------------------------------------------------------------------------
// 0x5244b0 — observed shape
void FUN_005244b0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    extern void* DAT_008ea510;
    uint32_t** vtbl = *reinterpret_cast<uint32_t***>(reinterpret_cast<uint8_t*>(self) + 0x24);
    if (vtbl != nullptr) {
        auto* node = reinterpret_cast<void* (*)()>(*reinterpret_cast<void**>(*vtbl)[1])();
        while (node != nullptr) {
            if (node == &DAT_008ea510) {
                int* selfSlots = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x24);
                if (reinterpret_cast<void*>(static_cast<intptr_t>(selfSlots[0xa7])) == self) {
                    // WARNING: indirect jump recovered as call through vtable slot 0xac/4
                    auto fn = reinterpret_cast<void (*)()>(*reinterpret_cast<void**>(*vtbl)[0xac / 4]);
                    fn();
                    return;
                }
                break;
            }
            node = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(node) + 4);
        }
    }
    FUN_005077f0(param_1, param_2, param_3);
}

// ---------------------------------------------------------------------------
// 0x524500 — call FUN_00507d20, then vtable call with float 0x3f800000 (1.0f)
// Observed: saves param_1 in iVar1; calls FUN_00507d20(param_1); sets
// float 0x3f800000; calls (*(self+0x160) + 0xc) with &param_1, 4.
// ---------------------------------------------------------------------------
// 0x524500 — observed shape
void FUN_00524500(int param_1)
{
    int saved = param_1;
    FUN_00507d20(param_1);
    uint32_t one = 0x3f800000;
    using Fn = void (*)(void*, uint32_t*, int);
    auto** vtbl = *reinterpret_cast<Fn**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(saved)) + 0x160);
    auto fn = reinterpret_cast<Fn>(vtbl[0xc / 4]);
    fn(nullptr, &one, 4);
}

// ---------------------------------------------------------------------------
// 0x524540 — destructor: set PTR_FUN_00712bf8, delete slots 0x14/0xf, swap
// vtable to PTR_FUN_00712bf4, call FUN_0054b990, optionally operator_delete.
// Register receiver in_ECX -> self.
// ---------------------------------------------------------------------------
// 0x524540 — observed shape
void FUN_00524540(void* self, uint8_t flags)
{
    extern void* PTR_FUN_00712bf8;
    extern void* PTR_FUN_00712bf4;
    auto* dv = reinterpret_cast<uint32_t*>(self);
    dv[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00712bf8);
    if (reinterpret_cast<void*>(dv[0x14]) != nullptr) {
        operator_delete__(reinterpret_cast<void*>(dv[0x14]));
    }
    dv[0xe] = reinterpret_cast<uint32_t>(&PTR_FUN_00712bf4);
    operator_delete__(reinterpret_cast<void*>(dv[0xf]));
    FUN_0054b990();
    if (flags & 1) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x524590 — list teardown: decrement counter, walk cache entries, dispatch
// cleanup, delete pointer arrays, then FUN_0054bcd0. (Non-contiguous body.)
// Register receiver in_ECX -> self.
// ---------------------------------------------------------------------------
// 0x524590 — observed shape
void FUN_00524590(void* self)
{
    extern int DAT_008cad0c;
    extern void* DAT_00727c30;
    extern int DAT_008ea08c;
    auto* s = reinterpret_cast<uint32_t*>(self);
    if (s[3] == 0) {
        return;
    }
    {
        using Fn = void (*)();
        auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(self)[0x40 / 4]);
        fn();
    }
    int idx = static_cast<int>(s[8]) - 1;
    s[0xc] = idx;
    int* piVar5 = nullptr;
    if (idx >= 0) {
        piVar5 = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(s[10])) + idx * 4);
    }
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(s[3])) + 0x188);
    if (piVar5 != nullptr) {
        do {
            if (*reinterpret_cast<int*>(s[0xc] * 0x10 + 8 + s[0x14]) == 0) {
                if (DAT_008cad0c == 0) {
                    DAT_008cad0c = reinterpret_cast<int>(FUN_00533c78(1));
                }
                int* pi = nullptr;
                if (DAT_008ea08c != 0) {
                    pi = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(DAT_00727c30) + 0x60);
                }
                {
                    using Fn = void (*)(int*, int, int);
                    auto fn = reinterpret_cast<Fn>((*reinterpret_cast<void**>(pi))[0xe4 / 4]);
                    fn(pi, 0xae, 0);
                }
            } else {
                if (DAT_008cad0c == 0) {
                    DAT_008cad0c = reinterpret_cast<int>(FUN_00533c78(1));
                }
                int* pi = nullptr;
                if (DAT_008ea08c != 0) {
                    pi = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(DAT_00727c30) + 0x60);
                }
                {
                    using Fn = void (*)(int*, int, int);
                    auto fn = reinterpret_cast<Fn>((*reinterpret_cast<void**>(pi))[0xe4 / 4]);
                    fn(pi, 0xae, 1);
                }
                if (DAT_008cad0c == 0) {
                    DAT_008cad0c = reinterpret_cast<int>(FUN_00533c78(1));
                }
                if (DAT_008ea08c == 0) {
                    pi = nullptr;
                } else {
                    pi = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(DAT_00727c30) + 0x60);
                }
                {
                    using Fn = void (*)(int*, uint32_t);
                    auto fn = reinterpret_cast<Fn>((*reinterpret_cast<void**>(pi))[300 / 4]);
                    fn(pi, s[0xc] * 0x10 + s[0x14]);
                }
            }
            {
                using Fn = void (*)(int*, uint32_t);
                auto fn = reinterpret_cast<Fn>((*reinterpret_cast<void**>(piVar5))[0x70 / 4]);
                fn(piVar5, uVar1);
            }
            idx = static_cast<int>(s[0xc]) - 1;
            s[0xc] = idx;
        } while (idx >= 0 && (piVar5 = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(s[10])) + idx * 4), piVar5 != nullptr));
    }
    if (DAT_008cad0c == 0) {
        DAT_008cad0c = reinterpret_cast<int>(FUN_00533c78(1));
    }
    {
        int* pi = nullptr;
        if (DAT_008ea08c != 0) {
            pi = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(DAT_00727c30) + 0x60);
        }
        using Fn = void (*)(int*, int, int);
        auto fn = reinterpret_cast<Fn>((*reinterpret_cast<void**>(pi))[0xe4 / 4]);
        fn(pi, 0xae, 0);
    }
    if (s[7] != 0) {
        do {
            int* node = reinterpret_cast<int*>(static_cast<intptr_t>(s[5]));
            int nxt = *node;
            s[5] = nxt;
            if (nxt == 0) {
                s[6] = 0;
            } else {
                *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(nxt) + 4) = 0;
            }
            {
                using Fn = void (*)(int*);
                auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(static_cast<intptr_t>(s[4]))[2]);
                fn(node);
            }
            s[7] = s[7] - 1;
        } while (s[7] != 0);
    }
    uint32_t i = 0;
    if (s[0x11] != 0) {
        do {
            void* pv = *reinterpret_cast<void**>(static_cast<intptr_t>(s[0xf]) + i * 4);
            if (pv != nullptr) {
                operator_delete(pv);
            }
            i = i + 1;
        } while (i < s[0x11]);
    }
    i = 0;
    if (s[0x11] != 0) {
        do {
            *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(s[0xf]) + i * 4) = 0;
            i = i + 1;
        } while (i < s[0x11]);
    }
    s[0x11] = 0;
    s[0x12] = 0;
    extern void FUN_0054bcd0();
    FUN_0054bcd0();
}

// ---------------------------------------------------------------------------
// 0x524890 — quicksort over three parallel arrays (0x28 index, 0x2c key,
// 0x50 16-byte records). Uses FUN_005561b0 for pivot key. Recursive.
// Register receiver in_ECX -> self.
// ---------------------------------------------------------------------------
// 0x524890 — observed shape
void FUN_00524890(void* self, int param_1, int param_2)
{
    int lo = param_1;
    if (param_1 < param_2) {
        do {
            int iVar9 = lo - 1;
            int iVar12 = param_2 + 1;
            float pivot = static_cast<float>(FUN_005561b0(lo, param_2));
            int iVar10 = lo;
            while (true) {
                int iVar7 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x2c) + iVar12 * 4;
                do {
                    lo = iVar12;
                    float* pf = reinterpret_cast<float*>(static_cast<intptr_t>(iVar7) - 4);
                    iVar7 = iVar7 - 4;
                    iVar12 = lo - 1;
                } while (pivot < *pf);
                iVar7 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x2c) + iVar9 * 4;
                do {
                    float* pf = reinterpret_cast<float*>(static_cast<intptr_t>(iVar7) + 4);
                    iVar7 = iVar7 + 4;
                    iVar9 = iVar9 + 1;
                } while (*pf < pivot);
                if (iVar12 <= iVar9) break;
                {
                    int base = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x28);
                    uint32_t tmp = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(base) + iVar9 * 4);
                    *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(base) + iVar9 * 4) =
                        *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(base) + iVar12 * 4);
                    *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(base) + iVar12 * 4) = tmp;
                    auto* p6 = reinterpret_cast<uint32_t*>(iVar9 * 0x10 + *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x50));
                    uint32_t t0 = p6[0], t1 = p6[1], t2 = p6[2], t3 = p6[3];
                    auto* p8 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x50) + iVar12 * 0x10);
                    p6[0] = p8[0]; p6[1] = p8[1]; p6[2] = p8[2]; p6[3] = p8[3];
                    auto* p6b = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x50) + iVar12 * 0x10);
                    p6b[0] = t0; p6b[1] = t1; p6b[2] = t2; p6b[3] = t3;
                    int base2 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x2c);
                    uint32_t tmp2 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(base2) + iVar9 * 4);
                    *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(base2) + iVar9 * 4) =
                        *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(base2) + iVar12 * 4);
                    *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(base2) + iVar12 * 4) = tmp2;
                }
                iVar10 = param_1;
            }
            if (iVar12 == param_2) {
                param_2 = lo - 2;
                lo = iVar10;
            } else {
                FUN_00524890(self, iVar10, iVar12);
                param_1 = lo;
            }
        } while (lo < param_2);
    }
}
// ---------------------------------------------------------------------------
// 0x524a60 — push node onto doubly-linked list (head/tail/count at +4/+8/+0xc)
// Observed: *param_1 = 0; param_1[1] = self+8; if empty set head=tail=param_1
// else **(self+8)=param_1, *(self+8)=param_1; count++.
// Register receiver in_ECX -> self.
// ---------------------------------------------------------------------------
// 0x524a60 — observed shape
void FUN_00524a60(void* self, uint32_t* param_1)
{
    param_1[0] = 0;
    param_1[1] = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 8);
    if (param_1[1] == 0) {
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 4) = reinterpret_cast<uint32_t>(param_1);
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 8) = reinterpret_cast<uint32_t>(param_1);
        *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0xc) += 1;
        return;
    }
    **reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(self) + 8) = reinterpret_cast<uint32_t>(param_1);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 8) = reinterpret_cast<uint32_t>(param_1);
    *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0xc) += 1;
}

// ---------------------------------------------------------------------------
// 0x524aa0 — destructor: set PTR_FUN_00712bf4, delete slot 1, optional delete.
// Register receiver in_ECX -> self.
// ---------------------------------------------------------------------------
// 0x524aa0 — observed shape
void FUN_00524aa0(void* self, uint8_t flags)
{
    extern void* PTR_FUN_00712bf4;
    auto* dv = reinterpret_cast<uint32_t*>(self);
    dv[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00712bf4);
    operator_delete__(reinterpret_cast<void*>(dv[1]));
    if (flags & 1) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x524ad0 — return 0 if cache invalid, else FUN_004f8e40(&param_2).
// Register receiver in_EAX (caller-supplied handle) preserved as param.
// ---------------------------------------------------------------------------
// 0x524ad0 — observed shape
uint32_t FUN_00524ad0(uint32_t param_1, uint8_t param_2, void* eaxHandle)
{
    extern uint32_t DAT_008cacf0;
    extern uint32_t DAT_008cace8;
    extern uint32_t DAT_008cacec;
    extern uint32_t FUN_004f8e40(void*);
    if ((DAT_008cacf0 == 0) || ((eaxHandle != nullptr && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
        return 0;
    }
    return FUN_004f8e40(&param_2);
}

// ---------------------------------------------------------------------------
// 0x524b10 — per-animation timeline search and cache update.
// Walks entries at param_2+0x38; per entry locates cache node via param_1
// vtable; if missing creates via FUN_00524de0; updates time [0]/flags[5];
// handles string copy to DAT_008cacd0 and reverse-animation warnings.
// ---------------------------------------------------------------------------
// 0x524b10 — observed shape
void FUN_00524b10(int* param_1, int param_2, float param_3)
{
    extern void FUN_00524ad0(const char* fmt, ...);
    extern float* FUN_00524de0();
    extern void FUN_004f32e0();
    extern void FUN_004ed8f0();
    extern char DAT_008cacd0[];
    extern int DAT_008caccc;
    extern int DAT_008cacc8;
    int* piVar8 = *reinterpret_cast<int**>(static_cast<intptr_t>(param_2) + 0x38);
    if (piVar8 == nullptr) {
        return;
    }
    do {
        int iVar3 = piVar8[2];
        float fVar6 = param_3 - *reinterpret_cast<float*>(static_cast<intptr_t>(iVar3) + 8);
        piVar8 = reinterpret_cast<int*>(*piVar8);
        int* piVar1 = param_1 + 1;
        int iVar9 = (reinterpret_cast<int (*)()>(*reinterpret_cast<void**>(param_1[1]))[1])();
        for (uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(param_1[3]) + iVar9 * 4);
             puVar4 != nullptr; puVar4 = reinterpret_cast<uint32_t*>(*puVar4)) {
            char c = reinterpret_cast<char (*) (int)>(*reinterpret_cast<void**>(*piVar1))[2](iVar3);
            if (c != '\0') {
                goto haveNode;
            }
        }
        if (fVar6 <= *reinterpret_cast<float*>(static_cast<intptr_t>(iVar3) + 0xc)) {
            goto createNode;
        }
        goto nextIter;
    createNode: {
                float* node = FUN_00524de0();
                // fall through to haveNode with node
                float* pfStack_c = node;
                goto checkNode;
            }
    haveNode: {
                // reached via found chain: node is puVar4[2]
                // (kept simple; full goto structure preserved below via helper)
                float* pfStack_c = nullptr;
                goto checkNode;
            }
    checkNode: {
                if (pfStack_c == nullptr) goto nextIter;
                float fVar2;
                (void)fVar2;
                if (*pfStack_c <= fVar6) {
                    if ((*pfStack_c != fVar6) || (((uint32_t)pfStack_c[5] & 1) != 0)) {
                        *pfStack_c = fVar6;
                        pfStack_c[5] = reinterpret_cast<float>((uint32_t)pfStack_c[5] & 0xfffffffe);
                        if ((pfStack_c[4] != 0.0f) &&
                            (fVar2 = **reinterpret_cast<float**>(static_cast<intptr_t>(pfStack_c[2]) + 8),
                            (!fVar2 || !fVar6) && fVar2 < fVar6 != (fVar2 == fVar6))) {
                            do {
                                float* pv = reinterpret_cast<float*>(static_cast<intptr_t>(pfStack_c[2]));
                                float v = *pv;
                                pfStack_c[2] = reinterpret_cast<float>(v);
                                if (v == 0.0f) {
                                    pfStack_c[3] = 0.0f;
                                } else {
                                    *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(v) + 4) = 0;
                                }
                                float s = pv[2];
                                (reinterpret_cast<void (*)()>(*reinterpret_cast<void**>(static_cast<intptr_t>(pfStack_c[1]))))[2]();
                                pfStack_c[4] = reinterpret_cast<float>((uint32_t)pfStack_c[4] - 1);
                                char* _Src = *reinterpret_cast<char**>(static_cast<intptr_t>(s) + 4);
                                if (_Src != nullptr) {
                                    char* pc = _Src;
                                    char c;
                                    do { c = *pc; pc = pc + 1; } while (c != '\0');
                                    size_t _Size = static_cast<size_t>(pc - (_Src + 1));
                                    if (static_cast<long>(_Size) >= -1 && _Src != &DAT_008cacd0[0]) {
                                        if (_Size == 0) {
                                            if (DAT_008caccc != 0) { DAT_008cacd0[0]=0; DAT_008caccc=0; }
                                        } else if (static_cast<long>(_Size) > 0) {
                                            if (DAT_008cacc8 < static_cast<int>(_Size)) {
                                                FUN_004f32e0();
                                            }
                                            *reinterpret_cast<size_t*>(reinterpret_cast<uint8_t*>(&DAT_008cacd0[0]) - 4) = _Size;
                                            memmove(&DAT_008cacd0[0], _Src, _Size);
                                            DAT_008cacd0[*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(&DAT_008cacd0[0]) - 4)] = 0;
                                        }
                                    }
                                }
                                // tail call via unaff_retaddr preserved as vtable dispatch
                                (reinterpret_cast<void (*)()>(*reinterpret_cast<void**>(pfStack_c[0])))[0]();
                            } while ((pfStack_c[4] != 0.0f) &&
                                (fVar2 = **reinterpret_cast<float**>(static_cast<intptr_t>(pfStack_c[2]) + 8),
                                (!fVar2 || !fVar6) && fVar2 < fVar6 != (fVar2 == fVar6)));
                        }
                    }
                } else {
                    FUN_00524ad0("Attempt to reverse animation! (anim=0x%x, oldtime=%f, newtime=%f)\n", param_2, static_cast<double>(*pfStack_c), static_cast<double>(fVar6));
                    iVar9 = (reinterpret_cast<int (*)()>(*reinterpret_cast<void**>(param_1[1]))[1])();
                    for (int* piVar11 = *reinterpret_cast<int**>(static_cast<intptr_t>(param_1[3]) + iVar9 * 4);
                         piVar11 != nullptr; piVar11 = reinterpret_cast<int*>(*piVar11)) {
                        char c = reinterpret_cast<char (*) (int)>(*reinterpret_cast<void**>(*piVar1))[2](iVar3);
                        if (c != '\0') {
                            FUN_004ed8f0();
                            (reinterpret_cast<void (*)()>(*reinterpret_cast<void**>(param_1[0])))[2]();
                            goto nextIter;
                        }
                    }
                    FUN_00524ad0("Attempt to invalidate cache for uncached animation (anim=0x%x)");
                }
            }
    nextIter:
        if (piVar8 == nullptr) {
            return;
        }
    } while (true);
}

// ---------------------------------------------------------------------------
// 0x524d90 — if FUN_0051bfc0 fails, log "Attempt to invalidate..." and return;
// else FUN_004ed8f0 + vtable(*param_1 + 8).
// ---------------------------------------------------------------------------
// 0x524d90 — observed shape
void FUN_00524d90(int* param_1)
{
    extern char FUN_0051bfc0(int** p);
    extern void FUN_00524ad0(const char* fmt, ...);
    extern void FUN_004ed8f0(void* r);
    int* saved = param_1;
    char r = FUN_0051bfc0(&param_1);
    if (r == '\0') {
        FUN_00524ad0("Attempt to invalidate cache for uncached animation (anim=0x%x)");
        return;
    }
    FUN_004ed8f0(nullptr);
    (reinterpret_cast<void (*)()>(*reinterpret_cast<void**>(*saved))[2])(saved);
}
 
 // ---------------------------------------------------------------------------
 // 0x524de0 — allocate cache node via vtable(*param_1+4), clear existing chain
 // at node+2, build new slots from *param_2+0x10 range, mark valid, FUN_00524e90.
 // ---------------------------------------------------------------------------
 // 0x524de0 — observed shape
 uint32_t* FUN_00524de0(int* param_1, int* param_2, uint32_t param_3)
 {
     extern void FUN_00524e90(uint32_t*);
     uint32_t* node = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t (*)()>(*reinterpret_cast<void**>(*param_1))[1]());
     node[0] = param_3;
     uint32_t* chain = reinterpret_cast<uint32_t*>(node[2]);
     while (chain != nullptr) {
         uint32_t* nxt = reinterpret_cast<uint32_t*>(*chain);
         reinterpret_cast<void (*)(uint32_t*)>(*reinterpret_cast<void**>(node[1]))[2](chain);
         chain = nxt;
     }
     node[4] = 0; node[2] = 0; node[3] = 0;
     int count = *reinterpret_cast<int*>(*reinterpret_cast<int*>(*param_2 + 0x10) + 0x10);
     int start = *reinterpret_cast<int*>(*reinterpret_cast<int*>(*param_2 + 0x10) + 0x14);
     if (count != 0) {
         int remaining = count;
         int cur = start;
         do {
             uint32_t* slot = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t (*)()>(*reinterpret_cast<void**>(node[1]))[1]());
             slot[2] = cur;
             slot[0] = 0;
             slot[1] = node[3];
             if (reinterpret_cast<uint32_t*>(node[3]) == nullptr) {
                 node[2] = reinterpret_cast<uint32_t>(slot);
             } else {
                 *reinterpret_cast<uint32_t*>(node[3]) = reinterpret_cast<uint32_t>(slot);
             }
             cur += 8;
             remaining -= 1;
             node[3] = reinterpret_cast<uint32_t>(slot);
             node[4] += 1;
         } while (remaining != 0);
     }
     node[5] = 1;
     FUN_00524e90(node);
     return node;
 }

 // ---------------------------------------------------------------------------
 // 0x524e90 — insert into bucketed list: find matching slot via vtable,
 // release stale node, insert new node at unaff_ESI[2]+idx*4.
 // ---------------------------------------------------------------------------
 // 0x524e90 — observed shape
 void FUN_00524e90(void* self)
 {
     auto* s = reinterpret_cast<uint32_t*>(self);
     int idx = reinterpret_cast<int (*)()>(*reinterpret_cast<void**>(*s))[1]();
     uint32_t* node = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(s[2]) + idx * 4);
     while (true) {
         if (node == nullptr) {
             node = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t (*)()>(*reinterpret_cast<void**>(*s))[0x14/4]());
             reinterpret_cast<void (*)(uint32_t*)>(*reinterpret_cast<void**>(*s))[0xc/4](node);
             node[0] = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(s[2]) + idx * 4);
             *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(s[2]) + idx * 4) = reinterpret_cast<uint32_t>(node);
             s[3] += 1;
             return;
         }
         char c = reinterpret_cast<char (*)()>(*reinterpret_cast<void**>(*s))[2]();
         if (c != '\0') break;
         node = reinterpret_cast<uint32_t*>(*node);
     }
     reinterpret_cast<void (*)(uint32_t*)>(*reinterpret_cast<void**>(*s))[0x10/4](node);
     reinterpret_cast<void (*)(uint32_t*)>(*reinterpret_cast<void**>(*s))[0xc/4](node);
 }

 // ---------------------------------------------------------------------------
 // 0x524f10 — drain list at (in+0x1c)/(in+0x10) releasing refs, then vtables
 // swap sequence with FUN_005edba0 and terminal FUN_00538400.
 // Register receiver in_ECX -> self.
 // ---------------------------------------------------------------------------
 // 0x524f10 — observed shape
 void FUN_00524f10(void* self)
 {
     extern void* PTR_FUN_007117c8;
     extern void* PTR_FUN_00711770;
     extern void* PTR_LAB_0071177c;
     extern void* PTR_FUN_00711808;
     extern void* PTR_LAB_00711814;
     extern void* PTR_FUN_00711788;
     extern void FUN_005edba0();
     extern void FUN_00538400();
     auto* s = reinterpret_cast<uint32_t*>(self);
     s[0] = reinterpret_cast<uint32_t>(&PTR_FUN_007117c8);
     if (s[7] != 0) {
         do {
             int* node = reinterpret_cast<int*>(static_cast<intptr_t>(s[5]));
             int nxt = *node;
             s[5] = nxt;
             if (nxt == 0) s[6] = 0;
             else *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(nxt) + 4) = 0;
             uint32_t* ref = reinterpret_cast<uint32_t*>(node[2]);
             if (ref != nullptr) ref[1] += 1;
             reinterpret_cast<void (*)(int*)>(*reinterpret_cast<void**>(static_cast<intptr_t>(s[4])))[2](node);
             s[7] -= 1;
             if (ref != nullptr) {
                 int old = ref[1];
                 ref[1] = old + 1;
                 ref[1] = old;
                 if (old == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*ref))[0](1);
                 int* p = reinterpret_cast<int*>(ref) + 1;
                 *p -= 1;
                 if (*p == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*ref))[0](1);
             }
         } while (s[7] != 0);
     }
     s[8] = reinterpret_cast<uint32_t>(&PTR_FUN_00711770);
     FUN_005edba0();
     s[8] = reinterpret_cast<uint32_t>(&PTR_LAB_0071177c);
     s[4] = reinterpret_cast<uint32_t>(&PTR_FUN_00711808);
     FUN_005edba0();
     s[4] = reinterpret_cast<uint32_t>(&PTR_LAB_00711814);
     s[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711788);
     FUN_00538400();
 }

 // ---------------------------------------------------------------------------
 // 0x525010 — drain list at *(self+0x2c), dispatch per-node ref manipulations
 // via FUN_005251b0 around self+0x10 and vtable+0x70, then FUN_0054bcd0.
 // Register receiver in_ECX -> self.
 // ---------------------------------------------------------------------------
 // 0x525010 — observed shape
 void FUN_00525010(void* self)
 {
     extern void FUN_005251b0(uint32_t* a, void* b);
     extern void FUN_0054bcd0();
     if (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x2c) != 0) {
         do {
             int* node = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(self) + 0x24);
             int nxt = *node;
             *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x24) = nxt;
             if (nxt == 0) *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x28) = 0;
             else *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(nxt) + 4) = 0;
             int* item = reinterpret_cast<int*>(node[2]);
             reinterpret_cast<void (*)(int*)>(*reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x20)))[2](node);
             *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x2c) -= 1;
             auto* ref = reinterpret_cast<uint32_t*>(item[0x2d]);
             if (ref != nullptr) ref[1] += 1;
             FUN_005251b0(ref, reinterpret_cast<uint8_t*>(self) + 0x10 + 0x800000);
             if (ref != nullptr) { ref[1] -= 1; if (ref[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*ref))[0](1); }
             auto* ref2 = reinterpret_cast<uint32_t*>(item[0x2e]);
             if (ref2 != nullptr) ref2[1] += 1;
             auto* tmp = reinterpret_cast<uint32_t*>(item[0x2e]);
             if (tmp != nullptr) { tmp[1] -= 1; if (tmp[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*tmp))[0](1); item[0x2e] = 0; }
             reinterpret_cast<void (*)(void*)>(*reinterpret_cast<void**>(*item))[0x70/4](self);
             auto* cur = reinterpret_cast<uint32_t*>(item[0x2e]);
             if (cur != ref2) {
                 if (cur != nullptr) { cur[1] -= 1; if (cur[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*cur))[0](1); }
                 item[0x2e] = reinterpret_cast<int>(ref2);
                 if (ref2 != nullptr) ref2[1] += 1;
             }
             auto* ref3 = reinterpret_cast<uint32_t*>(item[0x2d]);
             if (ref3 != nullptr) ref3[1] += 1;
             FUN_005251b0(ref3, reinterpret_cast<uint8_t*>(self) + 0x10);
             if (ref3 != nullptr) { ref3[1] -= 1; if (ref3[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*ref3))[0](1); }
             if (ref2 != nullptr) { ref2[1] -= 1; if (ref2[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*ref2))[0](1); }
         } while (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x2c) != 0);
     }
     FUN_0054bcd0();
 }

 // ---------------------------------------------------------------------------
 // 0x525140 — factory: allocate 0x30 via FUN_00533c78, init list/vtables,
 // thunk_FUN_00538410(puVar1, param_1); on alloc failure thunk(0, param_1).
 // ---------------------------------------------------------------------------
 // 0x525140 — observed shape
 uint32_t* FUN_00525140(uint32_t param_1)
 {
     extern void thunk_FUN_00538410(uint32_t*, uint32_t);
     uint32_t* p = reinterpret_cast<uint32_t*>(FUN_00533c78(0x30));
     if (p == nullptr) {
         thunk_FUN_00538410(nullptr, param_1);
         return nullptr;
     }
     extern void FUN_0054bc90();
     FUN_0054bc90();
     extern void* PTR_FUN_007117c8;
     extern void* PTR_FUN_00711808;
     extern void* PTR_FUN_00711770;
     p[0] = reinterpret_cast<uint32_t>(&PTR_FUN_007117c8);
     p[7] = 0; p[5] = 0; p[6] = 0;
     p[4] = reinterpret_cast<uint32_t>(&PTR_FUN_00711808);
     p[0xb] = 0; p[9] = 0; p[10] = 0;
     p[8] = reinterpret_cast<uint32_t>(&PTR_FUN_00711770);
     thunk_FUN_00538410(p, param_1);
     return p;
 }

 // ---------------------------------------------------------------------------
 // 0x5251b0 — iterate param_2 list slots [1]/[3], resolve bucket via
 // vtable(*piVar2+0x34), reinsert into param_1+8 bucket, refcount dance.
 // ---------------------------------------------------------------------------
 // 0x5251b0 — observed shape
 void FUN_005251b0(uint32_t param_1, uint32_t* param_2)
 {
     extern void FUN_004283d0(void*, void*);
     if (param_2[3] != 0) {
         uint32_t* walk = reinterpret_cast<uint32_t*>(param_2[1]);
         if (walk != nullptr) {
             while (true) {
                 uint32_t* piVar2 = reinterpret_cast<uint32_t*>(walk[2]);
                 uint32_t* piVar3 = reinterpret_cast<uint32_t*>(walk[0]);
                 if (piVar2 != nullptr) piVar2[1] += 1;
                 uint32_t* local_8 = walk;
                 int idx = reinterpret_cast<int (*)()>(*reinterpret_cast<void**>(*piVar2))[0x34/4]();
                 uint32_t* fresh = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t (*)()>(*reinterpret_cast<void**>(*param_2))[1]());
                 uint32_t* slot = reinterpret_cast<uint32_t*>(fresh[2]);
                 uint32_t* curBucket = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(param_1) + 8 + idx * 4);
                 if (slot != curBucket) {
                     if (slot != nullptr) { slot[1] -= 1; if (slot[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*slot))[0](1); }
                     uint32_t old = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(param_1) + 8 + idx * 4);
                     fresh[2] = old;
                     if (old != 0) *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(old) + 4) += 1;
                 }
                 fresh[0] = reinterpret_cast<uint32_t>(walk);
                 fresh[1] = walk[1];
                 if (reinterpret_cast<uint32_t*>(walk[1]) == nullptr) param_2[1] = reinterpret_cast<int>(fresh);
                 else *reinterpret_cast<uint32_t*>(walk[1]) = reinterpret_cast<uint32_t>(fresh);
                 walk[1] = reinterpret_cast<int>(fresh);
                 param_2[3] += 1;
                 void* tmp = nullptr;
                 FUN_004283d0(&tmp, &local_8);
                 if (tmp != nullptr) { reinterpret_cast<uint32_t*>(tmp)[1] -= 1; if (reinterpret_cast<uint32_t*>(tmp)[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(tmp))[0](1); }
                 uint32_t* bucketNow = *reinterpret_cast<uint32_t**>(static_cast<intptr_t>(param_1) + 8 + idx * 4);
                 if (bucketNow != piVar2) {
                     if (bucketNow != nullptr) { bucketNow[1] -= 1; if (bucketNow[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(bucketNow))[0](1); }
                     *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(param_1) + 8 + idx * 4) = reinterpret_cast<uint32_t>(piVar2);
                     piVar2[1] += 1;
                 }
                 piVar2[1] -= 1;
                 if (piVar2[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*piVar2))[0](1);
                 if (piVar3 == nullptr) break;
                 walk = piVar3;
             }
         }
     }
 }

 // ---------------------------------------------------------------------------
 // 0x5252c0 — size-class allocation: ensure global DAT_008ca4f4 pool exists,
 // compute stride selectors at param_1[0x15..0x17] by mode *(param_1[1]+0x10).
 // ---------------------------------------------------------------------------
 // 0x5252c0 — observed shape
 uint32_t* FUN_005252c0(uint32_t* param_1, uint32_t param_2, int param_3)
 {
     extern uint32_t* DAT_008ca4f4;
     extern void FUN_00518960();
     FUN_00518960();
     param_1[0] = reinterpret_cast<uint32_t>(&param_2);
     extern void* PTR_FUN_00712d20;
     param_1[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00712d20);
     if (DAT_008ca4f4 == nullptr) {
         uint32_t* pool = reinterpret_cast<uint32_t*>(FUN_00533c78(0x18));
         if (pool == nullptr) pool = nullptr;
         else {
             extern void* PTR_FUN_00712d5c;
             pool[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00712d5c);
             pool[2] = 0; pool[5] = 1; pool[3] = 0; pool[4] = 0; pool[1] = 0;
         }
         DAT_008ca4f4 = pool;
         uint32_t i = 0;
         if (DAT_008ca4f4[3] != 0) {
             do { *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(DAT_008ca4f4[1]) + i * 4) = 0; i += 1; } while (i < DAT_008ca4f4[3]);
         }
         DAT_008ca4f4[3] = 0; DAT_008ca4f4[4] = 0;
     }
     param_1[0x15] = param_3 * param_3;
     int mode = *reinterpret_cast<int*>(static_cast<intptr_t>(param_1[1]) + 0x10);
     if (mode == 0) {
         int v = (param_1[6] - 1) * (param_1[5] - 1);
         param_1[0x16] = v * 2; param_1[0x17] = v * 6; return param_1;
     }
     if (mode == 2) {
         int v = (param_1[6] - 1) * (param_1[5] - 1);
         param_1[0x16] = v * 4; param_1[0x17] = v * 0xc; return param_1;
     }
     int v = ((param_1[6] - 1) * (param_1[5] - 1) - 4 + param_1[5] * 2) * 2;
     param_1[0x16] = v; param_1[0x17] = v + 2; return param_1;
 }

 // ---------------------------------------------------------------------------
 // 0x5253c0 — destructor: release ref at self[2] twice (second is dead), then
 // optional operator_delete. Register receiver in_ECX -> self.
 // ---------------------------------------------------------------------------
 // 0x5253c0 — observed shape
 void FUN_005253c0(void* self, uint8_t flags)
 {
     extern void* PTR_FUN_00711fbc;
     auto* s = reinterpret_cast<uint32_t*>(self);
     s[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711fbc);
     uint32_t* ref = reinterpret_cast<uint32_t*>(s[2]);
     if (ref != nullptr) { ref[1] -= 1; if (ref[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*ref))[0](1); s[2] = 0; }
     ref = reinterpret_cast<uint32_t*>(s[2]);
     if (ref != nullptr) { ref[1] -= 1; if (ref[1] == 0) reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*ref))[0](1); }
     if (flags & 1) operator_delete(self);
 }

 // ---------------------------------------------------------------------------
 // 0x5254f0 — teardown DAT_008ca4f4 pool entries (delete +0xc/+0x10), release
 // pool, free DAT_008cad34/DAT_008cad38.
 // ---------------------------------------------------------------------------
 // 0x5254f0 — observed shape
 void FUN_005254f0()
 {
     extern uint32_t* DAT_008ca4f4;
     extern void* DAT_008cad34;
     extern void* DAT_008cad38;
     if (DAT_008ca4f4 != nullptr) {
         uint32_t i = 0;
         uint32_t* pool = DAT_008ca4f4;
         if (pool[3] != 0) {
             do {
                 int entry = *reinterpret_cast<int*>(static_cast<intptr_t>(pool[1]) + i * 4);
                 if (entry != 0) {
                     if (*reinterpret_cast<void**>(static_cast<intptr_t>(entry) + 0xc) != nullptr) {
                         operator_delete__(*reinterpret_cast<void**>(static_cast<intptr_t>(entry) + 0xc));
                         pool = DAT_008ca4f4;
                         *reinterpret_cast<void**>(static_cast<intptr_t>(entry) + 0xc) = nullptr;
                     }
                     if (*reinterpret_cast<void**>(static_cast<intptr_t>(entry) + 0x10) != nullptr) {
                         operator_delete__(*reinterpret_cast<void**>(static_cast<intptr_t>(entry) + 0x10));
                         pool = DAT_008ca4f4;
                         *reinterpret_cast<void**>(static_cast<intptr_t>(entry) + 0x10) = nullptr;
                     }
                 }
                 i += 1;
             } while (i < pool[3]);
         }
         reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(*pool))[0](1);
         DAT_008ca4f4 = nullptr;
     }
     if (DAT_008cad34 != nullptr) { free(DAT_008cad34); DAT_008cad34 = nullptr; }
     if (DAT_008cad38 != nullptr) { free(DAT_008cad38); DAT_008cad38 = nullptr; }
 }

 // ---------------------------------------------------------------------------
 // 0x525f50 — large fill: modes 1/2/other generate index quads; then either
 // copy from cache or allocate 0x14 record and insert into DAT_008ca4f4 bucket.
 // Register receiver in_ECX -> self.
 // ---------------------------------------------------------------------------
 // 0x525f50 — observed shape
 void FUN_00525f50(void* self, uint32_t* param_1, char param_2)
 {
     extern uint32_t* DAT_008ca4f4;
     extern void* FUN_0054b990();
     uint32_t* out = param_1;
     uint32_t* dst = param_1;
     int outIdx = 0;
     if (param_2 != '\0' && DAT_008ca4f4 != nullptr) {
         uint32_t i = 0;
         uint32_t count = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 0xc);
         if (count != 0) {
             do {
                 uint32_t* entry = *reinterpret_cast<uint32_t**>(*reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 4) + i * 4);
                 if (entry != nullptr) {
                     if (entry[1] == *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x14) &&
                         entry[2] == *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18) &&
                         entry[4] != 0) {
                         entry[0] = 0;
                         uint32_t n = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x5c);
                         uint32_t* src = reinterpret_cast<uint32_t*>(entry[4]);
                         for (uint32_t k = (n & 0x7fffffffu) >> 1; k != 0; k--) { *out++ = *src++; }
                         for (int k = (n & 1) << 1; k != 0; k--) { *reinterpret_cast<uint8_t*>(out) = *reinterpret_cast<uint8_t*>(src); src = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(src) + 1); out = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(out) + 1); }
                         return;
                     }
                     entry[0] += 1;
                 }
                 i += 1;
             } while (i < count);
         }
     }
     int mode = *reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 4) + 0x10);
     if (mode == 1) {
         *reinterpret_cast<uint16_t*>(dst) = *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(self) + 0x18);
         *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(dst) + 2) = 0;
         int o = 2;
         if (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x14) != 1) {
             for (uint32_t row = 0; row < *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x14) - 1U; row++) {
                 if (row != 0) {
                     *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(dst) + o * 2) = *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(dst) + o * 2 - 2);
                     *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + o * 2 + 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * (static_cast<short>(row) + 1);
                     *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (o + 2) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * (static_cast<short>(row) + 1);
                     *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (o + 3) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * static_cast<short>(row);
                     o += 4;
                 }
                 for (uint32_t c = 1; c < *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18); c++) {
                     *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + o * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * (static_cast<short>(row) + 1) + static_cast<short>(c);
                     *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (o + 1) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * static_cast<short>(row) + static_cast<short>(c);
                     o += 2;
                 }
             }
         }
     } else if (mode == 2) {
         uint32_t limit = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x14);
         if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18) < limit) limit = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18);
         for (uint32_t step = 1; step <= limit - 1; step *= 2) {
             uint32_t col = 0;
             if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x14) != step) {
                 uint32_t rem = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18) - step;
                 do {
                     if (rem != 0) {
                         for (uint32_t k = 0; k < rem; k += step) {
                             *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + outIdx * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * static_cast<short>(k) + static_cast<short>(col);
                             *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (outIdx + 1) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * static_cast<short>(k) + static_cast<short>(col) + static_cast<short>(step);
                             *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (outIdx + 2) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * (static_cast<short>(k) + static_cast<short>(step)) + static_cast<short>(col) + static_cast<short>(step);
                             *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (outIdx + 3) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * static_cast<short>(k) + static_cast<short>(col);
                             *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (outIdx + 4) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * (static_cast<short>(k) + static_cast<short>(step)) + static_cast<short>(col) + static_cast<short>(step);
                             *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (outIdx + 5) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * (static_cast<short>(k) + static_cast<short>(step)) + static_cast<short>(col);
                             rem = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18) - step;
                             outIdx += 6;
                         }
                     }
                     col += step;
                 } while (col < *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x14) - step);
             }
             if (step > limit - 1) break;
         }
     } else {
         uint32_t r = 0;
         if (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x14) != 1) {
             do {
                 for (uint32_t c2 = 0; c2 < *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18) - 1U; c2++) {
                     short a = static_cast<short>(r);
                     short b = static_cast<short>(c2);
                     *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + outIdx * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * b + a;
                     *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(dst) + (outIdx + 1) * 2) = *reinterpret_cast<short*>(reinterpret_cast<uint8_t*>(self) + 0x18) * b + 1 + a;
                     short c3 = static_cast<short>(b + 1);
                     outIdx += 6;
                 }
                 r += 1;
             } while (r < *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x14) - 1U);
         }
     }
     if (param_2 == '\0') return;
     uint32_t scan = 0;
     if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 0xc) != 0) {
         uint32_t* list = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 4);
         do {
             uint32_t* e = reinterpret_cast<uint32_t*>(*list);
             if (e != nullptr && e[1] == *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x14) && e[2] == *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18)) {
                 e[0] = 0;
                 uint32_t* nb = reinterpret_cast<uint32_t*>(FUN_00533c78(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x5c) << 1));
                 e[4] = reinterpret_cast<uint32_t>(nb);
                 uint32_t n = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x5c);
                 for (uint32_t k = (n & 0x7fffffffu) >> 1; k != 0; k--) { *nb++ = *dst++; }
                 for (int k = (n & 1) << 1; k != 0; k--) { *reinterpret_cast<uint8_t*>(nb) = *reinterpret_cast<uint8_t*>(dst); dst = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(dst) + 1); nb = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(nb) + 1); }
                 return;
             }
             scan += 1; list += 1;
         } while (scan < *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 0xc));
     }
     uint32_t* rec = reinterpret_cast<uint32_t*>(FUN_00533c78(0x14));
     rec[3] = 0;
     uint32_t* buf = reinterpret_cast<uint32_t*>(FUN_00533c78(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x5c) << 1));
     rec[4] = reinterpret_cast<uint32_t>(buf);
     uint32_t n2 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x5c);
     for (uint32_t k = (n2 & 0x7fffffffu) >> 1; k != 0; k--) { *buf++ = *dst++; }
     for (int k = (n2 & 1) << 1; k != 0; k--) { *reinterpret_cast<uint8_t*>(buf) = *reinterpret_cast<uint8_t*>(dst); dst = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(dst) + 1); buf = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(buf) + 1); }
     rec[1] = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x14);
     rec[2] = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18);
     rec[0] = 0;
     uint32_t cnt = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 0xc);
     if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 8) <= cnt) { extern void FUN_004f5670(); FUN_004f5670(); }
     if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 8) <= cnt) return;
     if (cnt < *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 0xc)) {
         if (*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 4) + cnt * 4) != 0) goto store;
     } else {
         *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 0xc) = cnt + 1;
     }
     *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 0x10) += 1;
 store:
     *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(DAT_008ca4f4) + 4) + cnt * 4) = rec;
 }
