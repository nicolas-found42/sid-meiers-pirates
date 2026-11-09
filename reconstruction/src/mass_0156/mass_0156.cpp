// Reconstruction batch mass_0156: Sid Meier's Pirates! (2004) PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern void operator_delete(void*);
extern void operator_delete__(void*);
extern void FUN_005603d0(void*);
extern void FUN_00547d10(void*);
extern void FUN_00548050(uint32_t);
extern uint32_t FUN_00557b10(uint32_t);
extern void FUN_006b34a0(int);
extern void FUN_005606f0(uint32_t, int*);
extern uint32_t FUN_00557cb0(const char*, uint32_t);
extern uint32_t FUN_00557d80(const char*, uint32_t);
extern uint32_t FUN_00557c70(const char*, uint32_t);
extern void FUN_0053adc0(int, uint32_t);
extern uint32_t FUN_0053bb30(uint32_t);
extern uint32_t thunk_FUN_00533c78(uint32_t);
extern void FUN_0053bc20(uint32_t**, uint32_t*);
extern void FUN_00533e70(uint32_t);
extern void FUN_005579c0(uint8_t*);
extern void FUN_00548720(void*, uint8_t*);
extern uint32_t FUN_0053b8d0(int);
extern void FUN_00560760(void*);
extern void FUN_0053c1d0(void*);
extern void FUN_0053b100(uint32_t);
extern void FUN_00533fa0(uint32_t, int);
extern void FUN_0053a940(int);
extern void FUN_0053b820(int);
extern void FUN_0053c060(int);
extern uint32_t FUN_00557b50(const char*, uint32_t);
extern void FUN_00547db0(int, uint32_t);
extern uint32_t DAT_00727d50;
extern uint32_t DAT_00727d58;
extern uint32_t DAT_007273f8;
extern void* PTR_FUN_006c32b4;
extern void* PTR_FUN_006c3304;
extern void* PTR_FUN_006c3308;

// 0x560230 — observed shape
uint32_t FUN_00560230(void* self, int param_1)
{
    uint32_t in_EAX = 0;
    if (param_1 == 0) {
        return in_EAX & 0xffffff00u;
    }
    uint32_t uVar7 = *(uint32_t*)((uint8_t*)self + 0x10);
    uint32_t uVar2 = *(uint32_t*)(param_1 + 0x10);
    if (uVar2 == uVar7) {
        // Check +0x18 equality as observed in original
        uint32_t self_18 = *(uint32_t*)((uint8_t*)self + 0x18);
        uint32_t other_18 = *(uint32_t*)(param_1 + 0x18);
        if (self_18 == other_18) {
            int iVar3 = *(int*)((uint8_t*)self + 0x14);
            if (iVar3 != 0) {
                int iVar5 = *(int*)(param_1 + 0x14);
                uVar7 = 0;
                if (iVar5 != 0) {
                    // Both non-null: element-wise string compare loop
                    if (uVar2 != 0) {
                        uint32_t idx = 0;
                        do {
                            uint8_t* pbVar4 = *(uint8_t**)(iVar3 + idx * 4);
                            int other_entry = *(int*)(*(int*)(param_1 + 0x14) + idx * 4);
                            if (pbVar4 == nullptr) {
                                if (other_entry != 0) {
                                    return (uint32_t)pbVar4 & 0xffffff00u;
                                }
                            } else if (other_entry == 0) {
                                return (uint32_t)pbVar4 & 0xffffff00u;
                            } else {
                                uint8_t* pbVar6 = *(uint8_t**)(*(int*)(param_1 + 0x14) + idx * 4);
                                uint8_t *p4 = pbVar4, *p6 = pbVar6;
                                int cmp = 0;
                                // Two-byte unrolled compare with terminator at even index
                                while (true) {
                                    uint8_t b1 = p4[0];
                                    uint8_t b2 = p6[0];
                                    if (b1 != b2) { int d = (int)b1 - (int)b2; cmp = d; break; }
                                    if (b1 == 0) break;
                                    b1 = p4[1]; b2 = p6[1];
                                    if (b1 != b2) { int d = (int)b1 - (int)b2; cmp = d; break; }
                                    p4 += 2; p6 += 2;
                                    if (b1 == 0) break;
                                }
                                if (cmp != 0) {
                                    return (uint32_t)pbVar4 & 0xffffff00u;
                                }
                            }
                            idx++;
                        } while (idx < uVar2);
                    }
                    return (uint32_t)((0u << 8) | 1u);
                    // CONCAT31((int3)(0>>8),1) == 1
                }
            }
            // iVar3==0 or iVar5==0 but not both handled above: return uVar7 masked
            // Original: uVar7 = *(uint*)(param_1+0x14); if zero goto compare-all-null check
            uVar7 = *(uint32_t*)(param_1 + 0x14);
            if (uVar7 == 0) {
                // Falls to LAB_00560276 with iVar3==0: inner guard fails, return CONCAT31
                return 1u;
            }
            return uVar7 & 0xffffff00u;
        }
    }
    return uVar7 & 0xffffff00u;
}

// 0x5603b0 — observed shape
void FUN_005603b0(void* self, uint8_t param_1)
{
    FUN_005603d0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5603d0 — observed shape
void FUN_005603d0(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t uVar1 = 0;
    *(void**)in_ECX = &PTR_FUN_006c32b4;
    if (in_ECX[4] != 0) {
        do {
            operator_delete__(*(void**)(in_ECX[5] + uVar1 * 4));
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[4]);
    }
    operator_delete__((void*)in_ECX[5]);
    in_ECX[5] = 0;
    FUN_00547d10();
}

// 0x560500 — observed shape
void FUN_00560500(void* self, uint32_t param_1)
{
    int iVar2 = (int)param_1;
    FUN_00548050(param_1);
    uint32_t pval = FUN_00557b10(DAT_00727d50);
    uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (int*)&pval);
    pval = FUN_00557cb0("m_uiSize", *(uint32_t*)((uint8_t*)self + 0x10));
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (int*)&pval);
    uint32_t loc = 0;
    if (*(int*)((uint8_t*)self + 0x10) != 0) {
        do {
            uint32_t entry = *(uint32_t*)(*(int*)((uint8_t*)self + 0x14) + loc * 4);
            int iVar3 = (int)FUN_00557d80("m_ppcValue[i]", entry);
            uVar1 = *(uint32_t*)(iVar2 + 0xc);
            if (uVar1 < *(uint32_t*)(iVar2 + 8) || (FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1), uVar1 < *(uint32_t*)(iVar2 + 8))) {
                if (uVar1 < *(uint32_t*)(iVar2 + 0xc)) {
                    if (iVar3 == 0) {
                        if (*(int*)(*(int*)(iVar2 + 4) + uVar1 * 4) != 0) {
                            *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) + -1;
                        }
                    } else if (*(int*)(*(int*)(iVar2 + 4) + uVar1 * 4) == 0) {
                        *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) + 1;
                    }
                } else {
                    *(uint32_t*)(iVar2 + 0xc) = uVar1 + 1;
                    if (iVar3 != 0) {
                        *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) + 1;
                    }
                }
                *(int*)(*(int*)(iVar2 + 4) + uVar1 * 4) = iVar3;
            }
            loc = loc + 1;
        } while (loc < *(uint32_t*)((uint8_t*)self + 0x10));
    }
    int iVar3b = (int)FUN_00557c70("m_iIndex", *(uint32_t*)((uint8_t*)self + 0x18));
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1 && (FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1), *(uint32_t*)(iVar2 + 8) <= uVar1)) {
        return;
    }
    if (uVar1 < *(uint32_t*)(iVar2 + 0xc)) {
        if (iVar3b == 0) {
            if (*(int*)(*(int*)(iVar2 + 4) + uVar1 * 4) != 0) {
                *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) + -1;
            }
        } else if (*(int*)(*(int*)(iVar2 + 4) + uVar1 * 4) == 0) {
            *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) + 1;
            *(int*)(*(int*)(iVar2 + 4) + uVar1 * 4) = iVar3b;
            return;
        }
    } else {
        *(uint32_t*)(iVar2 + 0xc) = uVar1 + 1;
        if (iVar3b != 0) {
            *(int*)(iVar2 + 0x10) = *(int*)(iVar2 + 0x10) + 1;
            *(int*)(*(int*)(iVar2 + 4) + uVar1 * 4) = iVar3b;
            return;
        }
    }
    *(int*)(*(int*)(iVar2 + 4) + uVar1 * 4) = iVar3b;
}

// 0x5606b0 — observed shape
void FUN_005606b0(void* self, int param_1, uint32_t param_2)
{
    FUN_0053adc0(param_1, param_2);
    *(uint16_t*)(param_1 + 0xec) = *(uint16_t*)((uint8_t*)self + 0xec);
    *(uint32_t*)(param_1 + 0xf0) = *(uint32_t*)((uint8_t*)self + 0xf0);
}
// 0x5606f0 — observed shape
void FUN_005606f0(void* self, uint32_t param_1, int* param_2)
{
    if (param_1 < *(uint32_t*)((uint8_t*)self + 8)) {
        if (param_1 < *(uint32_t*)((uint8_t*)self + 0xc)) {
            int iVar1 = *(int*)(*(int*)((uint8_t*)self + 4) + param_1 * 4);
            if (*param_2 == 0) {
                if (iVar1 != 0) {
                    *(int*)((uint8_t*)self + 0x10) = *(int*)((uint8_t*)self + 0x10) + -1;
                }
            } else if (iVar1 == 0) {
                *(int*)((uint8_t*)self + 0x10) = *(int*)((uint8_t*)self + 0x10) + 1;
                *(int*)(*(int*)((uint8_t*)self + 4) + param_1 * 4) = *param_2;
                return;
            }
        } else {
            *(uint32_t*)((uint8_t*)self + 0xc) = param_1 + 1;
            if (*param_2 != 0) {
                *(int*)((uint8_t*)self + 0x10) = *(int*)((uint8_t*)self + 0x10) + 1;
                *(int*)(*(int*)((uint8_t*)self + 4) + param_1 * 4) = *param_2;
                return;
            }
        }
        *(int*)(*(int*)((uint8_t*)self + 4) + param_1 * 4) = *param_2;
    }
}

// 0x560760 — observed shape
void FUN_00560760(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    *(void**)in_ECX = &PTR_FUN_006c3304;
    operator_delete__((void*)in_ECX[1]);
}

// 0x560780 — observed shape
void FUN_00560780(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    *(void**)in_ECX = &PTR_FUN_006c3304;
    operator_delete__((void*)in_ECX[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5607b0 — observed shape
void FUN_005607b0(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_0053bb30(0);
    *(void**)in_ECX = &PTR_FUN_006c3308;
    in_ECX[0x3f] = (uint32_t)(uint64_t)&PTR_FUN_006c3304;
    in_ECX[0x41] = 1;
    in_ECX[0x44] = 1;
    in_ECX[0x42] = 0;
    in_ECX[0x43] = 0;
    uint32_t uVar1 = thunk_FUN_00533c78(4);
    in_ECX[0x40] = uVar1;
    *(uint16_t*)(in_ECX + 0x3b) = 1;
    in_ECX[0x3e] = 1;
    *(uint8_t*)(in_ECX + 0x45) = 1;
    in_ECX[0x3c] = 0xffffffffu;
    in_ECX[0x3d] = 0;
}

// 0x560840 — observed shape
uint32_t* FUN_00560840(void* self, uint32_t* param_1, uint32_t* param_2)
{
    uint32_t uVar2 = 0;
    *(uint32_t*)((uint8_t*)self + 0xf8) = 1;
    if (*(int*)((uint8_t*)self + 0xc0) != 0) {
        int* piVar3 = *(int**)((uint8_t*)self + 0xb8);
        do {
            if (param_2 == (uint32_t*)*piVar3) {
                if (uVar2 < *(uint32_t*)((uint8_t*)self + 0x108)) {
                    int iVar1 = *(int*)(*(int*)((uint8_t*)self + 0x100) + uVar2 * 4);
                    *(uint32_t*)(*(int*)((uint8_t*)self + 0x100) + uVar2 * 4) = 0;
                    if (iVar1 != 0) {
                        *(int*)((uint8_t*)self + 0x10c) = *(int*)((uint8_t*)self + 0x10c) + -1;
                    }
                    uint32_t uVar4 = (uint32_t)(*(int*)((uint8_t*)self + 0x108) - 1);
                    if (uVar2 == uVar4) {
                        *(uint32_t*)((uint8_t*)self + 0x108) = uVar4;
                    }
                }
                break;
            }
            uVar2 = uVar2 + 1;
            piVar3 = piVar3 + 1;
        } while (uVar2 < *(uint32_t*)((uint8_t*)self + 0xc0));
    }
    FUN_0053bc20((uint32_t**)&param_2, param_2);
    int iVar1b = *(int*)((uint8_t*)self + 0xf0);
    if (iVar1b >= 0 && (*(int*)((uint8_t*)self + 0xc0) <= iVar1b || *(int*)(*(int*)((uint8_t*)self + 0xb8) + iVar1b * 4) == 0)) {
        *(uint32_t*)((uint8_t*)self + 0xf0) = 0xffffffffu;
    }
    *param_1 = (uint32_t)(uint64_t)param_2;
    if (param_2 != nullptr) {
        param_2[1] = param_2[1] + 1;
        int c = (int)param_2[1];
        param_2[1] = (uint32_t)(c + -1);
        if (c + -1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn f = *(Fn*)*param_2;
            f(1);
        }
    }
    return param_1;
}
// 0x5609e0 — observed shape
void FUN_005609e0(void* self, uint32_t param_1)
{
    int iVar1 = *(int*)((uint8_t*)self + 0xf0);
    if (iVar1 >= 0) {
        int* piVar2 = *(int**)(*(int*)((uint8_t*)self + 0xb8) + iVar1 * 4);
        if (piVar2 != nullptr) {
            if (*(int*)(*(int*)((uint8_t*)self + 0x100) + iVar1 * 4) != *(int*)((uint8_t*)self + 0xf8)) {
                FUN_005606f0(self, (uint32_t)iVar1, (int*)((uint8_t*)self + 0xf8));
                using Fn = void(__cdecl*)(uint32_t, uint8_t);
                Fn f = *(Fn*)(*piVar2 + 0x48);
                f(*(uint32_t*)((uint8_t*)self + 0xf4), *(uint8_t*)((uint8_t*)self + 0x114));
            }
            FUN_00533e70(param_1);
        }
    }
}

// 0x560aa0 — observed shape
void FUN_00560aa0(void* self)
{
    uint32_t uVar2 = 0;
    if (*(int*)((uint8_t*)self + 0xc0) != 0) {
        do {
            int* piVar1 = *(int**)(*(int*)((uint8_t*)self + 0xb8) + uVar2 * 4);
            if (piVar1 != nullptr) {
                if (*(int*)(*(int*)((uint8_t*)self + 0x100) + uVar2 * 4) != *(int*)((uint8_t*)self + 0xf8)) {
                    FUN_005606f0(self, uVar2, (int*)((uint8_t*)self + 0xf8));
                    using Fn = void(__cdecl*)(uint32_t, uint8_t);
                    Fn f = *(Fn*)(*piVar1 + 0x48);
                    f(*(uint32_t*)((uint8_t*)self + 0xf4), *(uint8_t*)((uint8_t*)self + 0x114));
                }
                using Fn2 = void(__cdecl*)();
                Fn2 f2 = *(Fn2*)(*piVar1 + 0x38);
                f2();
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)((uint8_t*)self + 0xc0));
    }
    uint8_t local_34[52];
    FUN_005579c0(local_34);
    FUN_00548720((uint8_t*)self + 0x28, local_34);
}

// 0x560bb0 — observed shape
uint32_t FUN_00560bb0(void* self, int param_1)
{
    uint32_t uVar1 = FUN_0053b8d0(param_1);
    if (((char)uVar1 == '\0') || (uVar1 = *(uint32_t*)((uint8_t*)self + 0xf0), uVar1 != *(uint32_t*)(param_1 + 0xf0)) || (((*(uint8_t*)(param_1 + 0xec) ^ *(uint8_t*)((uint8_t*)self + 0xec)) & 1) != 0)) {
        return uVar1 & 0xffffff00u;
    }
    return (uint32_t)(((uint32_t)(uVar1 >> 8) << 8) | 1u);
}

// 0x560bf0 — observed shape
void FUN_00560bf0(void* self, uint8_t param_1)
{
    FUN_00560760(self);
    FUN_0053c1d0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x561000 — observed shape
void FUN_00561000(void* self, uint32_t param_1)
{
    if ((*(uint8_t*)((uint8_t*)self + 0xec) & 1) == 0) {
        FUN_0053b100(param_1);
        return;
    }
    if (*(int*)((uint8_t*)self + 0xf0) >= 0) {
        FUN_00533fa0(param_1, 1);
        int* piVar1 = *(int**)(*(int*)((uint8_t*)self + 0xb8) + *(int*)((uint8_t*)self + 0xf0) * 4);
        if (piVar1 != nullptr) {
            using Fn = void(__cdecl*)(uint32_t);
            Fn f = *(Fn*)(*piVar1 + 0x34);
            f(param_1);
        }
    }
}

// 0x561060 — observed shape
void FUN_00561060(void* self, int param_1)
{
    uint8_t* s = (uint8_t*)self;
    uint8_t* p = (uint8_t*)param_1;
    FUN_0053a940(param_1);
    if (*(uint32_t*)(p + 0x1c) < 0xa000102u) {
        *(uint16_t*)(s + 0xec) = (uint16_t)DAT_007273f8;
        *(uint16_t*)(s + 0xec) = (uint16_t)*(uint8_t*)(s + 0xed);
    } else {
        auto fn = *reinterpret_cast<void(**)(void*, uint32_t)>(
            *reinterpret_cast<int32_t*>(p + 0x15c) + 8);
        fn(s + 0xec, 2);
    }
    auto fn4 = *reinterpret_cast<void(**)(void*, uint32_t)>(
        *reinterpret_cast<int32_t*>(p + 0x15c) + 8);
    fn4(s + 0xf0, 4);
}

// 0x5610d0 — observed shape
void FUN_005610d0(void* self, int param_1)
{
    uint8_t* s = (uint8_t*)self;
    uint8_t* p = (uint8_t*)param_1;
    FUN_0053b820(param_1);
    auto fn = *reinterpret_cast<void(**)(void*, uint32_t)>(
        *reinterpret_cast<int32_t*>(p + 0x160) + 0xc);
    fn(s + 0xec, 2);
    fn(s + 0xf0, 4);
}

// 0x561110 — observed shape
void FUN_00561110(void* self, int param_1)
{
    uint8_t* s = (uint8_t*)self;
    int iVar2 = param_1;
    uint32_t uVar1;
    uint32_t value;
    FUN_0053c060(param_1);
    value = FUN_00557b10(DAT_00727d58);
    uVar1 = *(uint32_t*)((uint8_t*)iVar2 + 0xc);
    if (*(uint32_t*)((uint8_t*)iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)((uint8_t*)iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (int*)&value);
    value = FUN_00557c70("m_iIndex", *(uint32_t*)(s + 0xf0));
    uVar1 = *(uint32_t*)((uint8_t*)iVar2 + 0xc);
    if (*(uint32_t*)((uint8_t*)iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)((uint8_t*)iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (int*)&value);
    value = FUN_00557b50("m_bUpdateOnlyActive", *(uint8_t*)(s + 0xec) & 1);
    uVar1 = *(uint32_t*)((uint8_t*)iVar2 + 0xc);
    if (*(uint32_t*)((uint8_t*)iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)((uint8_t*)iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (int*)&value);
}

// 0x5611e0 — observed shape
// String-vector deep copy for the m_ppcValue table. Runs FUN_00547db0(first),
// then if either receiver+0x14 (table) or receiver+0x10 (count) is zero it
// zeroes param_1+0x14/+0x10 and returns. Otherwise copies the count,
// allocates count*4 bytes at param_1+0x14, and duplicates each counted string
// (null stays null) using thunk_FUN_00533c78 sized to the measured length.
void FUN_005611e0(void* self, int param_1, uint32_t param_2)
{
    uint8_t* s = (uint8_t*)self;
    uint8_t* d = (uint8_t*)param_1;
    FUN_00547db0(param_1, param_2);
    if ((*(int*)(s + 0x14) == 0) || (*(int*)(s + 0x10) == 0)) {
        *(uint32_t*)(d + 0x14) = 0;
        *(uint32_t*)(d + 0x10) = 0;
        return;
    }
    *(int*)(d + 0x10) = *(int*)(s + 0x10);
    uint32_t uVar2 = thunk_FUN_00533c78(*(int*)(s + 0x10) << 2);
    *(uint32_t*)(d + 0x14) = uVar2;
    uint32_t uVar5 = 0;
    if (*(int*)(s + 0x10) != 0) {
        do {
            char* pcVar3 = *(char**)(*(int*)(s + 0x14) + uVar5 * 4);
            if (pcVar3 == nullptr) {
                *(uint32_t*)(*(int*)(d + 0x14) + uVar5 * 4) = 0;
            } else {
                char* pcVar4 = pcVar3 + 1;
                char cVar1;
                do {
                    cVar1 = *pcVar3;
                    pcVar3 = pcVar3 + 1;
                } while (cVar1 != '\0');
                uint32_t len = (uint32_t)(uintptr_t)(pcVar3 + (1 - (int)(intptr_t)pcVar4));
                uVar2 = thunk_FUN_00533c78(len);
                *(uint32_t*)(*(int*)(d + 0x14) + uVar5 * 4) = uVar2;
                pcVar3 = *(char**)(*(int*)(s + 0x14) + uVar5 * 4);
                pcVar4 = *(char**)(*(int*)(d + 0x14) + uVar5 * 4);
                do {
                    cVar1 = *pcVar3;
                    pcVar3 = pcVar3 + 1;
                    *pcVar4 = cVar1;
                    pcVar4 = pcVar4 + 1;
                } while (cVar1 != '\0');
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint32_t*)(s + 0x10));
    }
}

// 0x561290 — observed shape
uint32_t FUN_00561290(void* self, int param_1)
{
    uint8_t* s = (uint8_t*)self;
    uint8_t* p = (uint8_t*)param_1;
    uint32_t in_EAX = 0;
    uint8_t bVar1;
    uint32_t uVar2;
    int iVar3;
    uint8_t* pbVar4;
    int iVar5;
    uint8_t* pbVar6;
    uint32_t uVar7;
    bool bVar8;
    if (param_1 == 0) {
        return in_EAX & 0xffffff00u;
    }
    uVar7 = *(uint32_t*)(p + 0x10);
    uVar2 = *(uint32_t*)(s + 0x10);
    if (uVar2 == uVar7) {
        iVar3 = *(int*)(s + 0x14);
        if (iVar3 != 0) {
            iVar5 = *(int*)(p + 0x14);
            uVar7 = 0;
            if (iVar5 == 0) goto LAB_005612ae;
            if (iVar3 != 0) goto LAB_005612ce;
        }
        uVar7 = *(uint32_t*)(p + 0x14);
        iVar5 = 0;
        if (uVar7 == 0) {
        LAB_005612ce:
            if ((iVar3 != 0) && (uVar7 = 0, uVar2 != 0)) {
                do {
                    pbVar4 = *(uint8_t**)(iVar3 + uVar7 * 4);
                    if (pbVar4 == nullptr) {
                    LAB_005612f4:
                        if (*(int*)(*(int*)(p + 0x14) + uVar7 * 4) != 0) goto LAB_00561346;
                        if (pbVar4 != nullptr) goto LAB_00561301;
                    } else {
                        if (*(int*)(*(int*)(p + 0x14) + uVar7 * 4) == 0) goto LAB_00561346;
                        if (pbVar4 == nullptr) goto LAB_005612f4;
                    LAB_00561301:
                        pbVar6 = *(uint8_t**)(*(int*)(p + 0x14) + uVar7 * 4);
                        do {
                            bVar1 = *pbVar4;
                            bVar8 = bVar1 < *pbVar6;
                            if (bVar1 != *pbVar6) {
                            LAB_0056132b:
                                pbVar4 = (uint8_t*)(uintptr_t)((1u - (uint32_t)bVar8) - (uint32_t)(bVar8 != 0));
                                goto LAB_00561330;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = pbVar4[1];
                            bVar8 = bVar1 < pbVar6[1];
                            if (bVar1 != pbVar6[1]) goto LAB_0056132b;
                            pbVar4 = pbVar4 + 2;
                            pbVar6 = pbVar6 + 2;
                        } while (bVar1 != 0);
                        pbVar4 = nullptr;
                    LAB_00561330:
                        if (pbVar4 != nullptr) {
                        LAB_00561346:
                            return (uint32_t)pbVar4 & 0xffffff00u;
                        }
                    }
                    iVar5 = 0;
                    uVar7 = uVar7 + 1;
                } while (uVar7 < uVar2);
            }
            return (uint32_t)((((uint32_t)iVar5 >> 8) << 8) | 1u);
        }
    }
LAB_005612ae:
    return uVar7 & 0xffffff00u;
}
