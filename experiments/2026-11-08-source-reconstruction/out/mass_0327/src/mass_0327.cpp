//
// mass_0327.cpp — reconstruction batch mass_0327
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Every definition below is a candidate translation of one Ghidra 12.2
// pseudocode listing under analysis/pseudocode/functions/. Field offsets,
// constants, call order, return shapes and conditional structure follow the
// listing. Register receivers (in_ECX) are modeled as an explicit `self`.
//
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <windows.h>

// ---------------------------------------------------------------------------
// Layout helpers: every field access keeps the observed byte offset.
// ---------------------------------------------------------------------------
template <class T>
static inline T& at(void* self, std::size_t offset)
{
    return *reinterpret_cast<T*>(static_cast<std::uint8_t*>(self) + offset);
}

template <class T>
static inline T* atp(void* self, std::size_t offset)
{
    return reinterpret_cast<T*>(static_cast<std::uint8_t*>(self) + offset);
}

// Reinterpret a 32-bit value observed in memory as an address.
static inline void* pv(std::uintptr_t value)
{
    return reinterpret_cast<void*>(value);
}

// Load the function pointer installed in the receiver's vtable at `slot`.
static inline void* vtbl_slot(void* self, std::size_t slot)
{
    const std::uint32_t vtbl = at<std::uint32_t>(self, 0);
    return static_cast<std::uint8_t*>(pv(vtbl)) + slot;
}

// ---------------------------------------------------------------------------
// Extern declarations: only helpers and globals named by the assigned
// listings are introduced.
// ---------------------------------------------------------------------------
int32_t  FUN_0067ada6(int32_t* a, int32_t b, int32_t* c, int32_t d);
int32_t  FUN_0067a8d2(int32_t* a, int32_t b, int32_t* c);
void     FUN_006626da(void);
void     operator_delete(void* p);

uint32_t FUN_0065d97c(void* a, uint32_t b, uint32_t c, uint32_t d);
int32_t  FUN_0065d9d5(uint32_t handle, uint32_t a, uint32_t b, double value);
int32_t  FUN_0065d0ff(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
uint32_t FUN_0065d0b4(uint32_t size = 0);
uint32_t FUN_0065cc1a(void);
int32_t  FUN_0065cc50(uint32_t a = 0);
int32_t  FUN_0065d8c2(void);
int32_t  FUN_0065db2e(void);
int32_t  FUN_0065e4f2(void);
int32_t  FUN_00664b28(void);
int32_t  FUN_0066be13(void);

void     FUN_006959c5(void);
int32_t  FUN_006634e9(void);
int32_t  FUN_0067311b(void);
int32_t  FUN_00697497(void);
int32_t  FUN_0067357d(void);
int32_t  FUN_006736a9(void);
int32_t  FUN_006758fc(void);
int32_t  FUN_00674e44(void);
int32_t  FUN_00675520(void);
int32_t  FUN_00674889(void);
int32_t  FUN_0069d701(void);
int32_t  FUN_006752d1(void);
int32_t  FUN_00673c98(void);
int32_t  FUN_00677223(void);
int32_t  FUN_00677783(void);
int32_t  FUN_006778eb(void);
uint32_t FUN_00677811(void);
void     FUN_0067707d(void);
int32_t  FUN_00677b94(uint32_t candidate, uint32_t enable);
void     FUN_00677176(void);
int32_t  FUN_0067c441(uint32_t a, uint32_t b, uint32_t c, void* d);
void     FUN_00614343(void);
int32_t  FUN_0067d4e6(void);
int32_t  FUN_00677f73(void);
int32_t  FUN_006796fd(uint32_t a, uint32_t b);
int32_t  FUN_00676ac7(void);
int32_t  FUN_00673ae5(void);
int32_t  FUN_00673f3c(void);
int32_t  FUN_0067cbd8(void);
int32_t  FUN_00674311(void);
int32_t  FUN_00678c07(void);
int32_t  FUN_006738a3(void);
int32_t  FUN_0067303c(void);
int32_t  FUN_0067d8c9(void* self);

int32_t  FUN_006a114f(int32_t a = 1);
int32_t  FUN_006a247c(void);
void     FUN_006a251c(void);
void     FUN_006a1e95(void);
void     FUN_006a22f4(void);
int32_t  FUN_006a2192(void);
int32_t  FUN_006992d0(void);
void     FUN_006a26b9(void);
int32_t  FUN_0069cb30(int32_t a = 0);
void     FUN_00696ab9(void);
void     FUN_0066254f(void);
void     FUN_00662568(void);
int32_t  FUN_00696b3c(uint32_t a, uint32_t b, uint32_t c);
int32_t  FUN_00697138(uint32_t a, uint32_t b, uint32_t c);
int32_t  FUN_00696630(void);
int32_t  FUN_006999b4(void);
int32_t  FUN_0069be37(void);
int32_t  FUN_006a1209(int32_t a = 1);
int32_t  FUN_0069c4b5(void);
int32_t  FUN_0069c587(void);
int32_t  FUN_0069b834(void);
int32_t  FUN_0069c0f7(void);
int32_t  FUN_00699cf5(void);
int32_t  FUN_00699fa5(void);
int32_t  FUN_0069606d(void);
int32_t  FUN_006a5fac(void);
int32_t  FUN_006a5deb(void);
int32_t  FUN_006a5c6c(void);
int32_t  FUN_006a5478(void);
int32_t  FUN_006a6662(void);
int32_t  FUN_006a6859(void);
int32_t  FUN_006a6863(void);
int32_t  FUN_006a6877(void);
int32_t  FUN_006a6934(void);
int32_t  FUN_006a693e(void);
int32_t  FUN_0067b559(void);
int32_t  FUN_0067b998(void);
int32_t  FUN_0067b8c6(void);
int32_t  FUN_0067bae9(void);
int32_t  FUN_0067b7eb(void);
int32_t  FUN_0067b6a6(uint32_t code);

void     FUN_006a3d1c(void);
int32_t  FUN_006a4aab(int32_t a, void* b, uint32_t c, void* d, void* e, void* f,
                     uint32_t g, uint32_t h, uint32_t i, uint32_t j, uint32_t k);
int32_t  FUN_006a48dd(uint32_t a);
int32_t  FUN_006a2b66(uint32_t a);
int32_t  FUN_0069fcf5(void);
uint32_t* FUN_006a3cac(int32_t code);
int32_t  FUN_0061273f(const char* name, uint32_t b, int32_t c);
int32_t  FUN_00533c78(int32_t size = 0);
int32_t  FUN_00673e38(const void* a, const void* b);
int32_t  FUN_0069ec6d(void* dest, uint32_t rows, uint32_t cols);
int32_t  FUN_0067fbed(int32_t* a, uint32_t b, uint32_t c);
int32_t  FUN_0067fd95(int32_t* a, uint32_t b);
uint32_t FUN_0067fb97(const void* a, const void* b);

extern uint8_t DAT_006c3b94;
extern int32_t DAT_007205b8[];

// ---------------------------------------------------------------------------
// 0x67d8c9 — observed shape
// Reject unless the receiver's entry count is 4, partition both 512-entry
// pointer tables by type, then resolve the four named classes through
// FUN_0067ada6/FUN_0067a8d2 and reinstall the surviving entries.
// ---------------------------------------------------------------------------
int32_t FUN_0067d8c9(void* self)
{
    int32_t  local_30[11];
    int32_t  iVar4 = 0;
    int32_t  iVar5;
    int32_t* piVar1;
    uint32_t uVar3;
    uint32_t uVar6;
    uint32_t* puVar2;

    local_30[8] = 0;
    if (at<int32_t>(self, 0x4c) != 4) {
        return -0x7fffbffb;
    }
    local_30[4] = 0;
    local_30[5] = 0;
    local_30[6] = 0;
    local_30[7] = 0;
    local_30[0] = 0;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[10] = 0;
    local_30[3] = 0;
    local_30[9] = 0;
    do {
        iVar4 = local_30[10];
        piVar1 = reinterpret_cast<int32_t*>(
            static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x230))) + local_30[9] * 4);
        puVar2 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(*piVar1));
        if ((puVar2 != nullptr) && (*puVar2 != 0)) {
            if ((*puVar2 & 0xfff00000) == 0x72100000) {
                iVar5 = *piVar1;
                goto LAB_0067d96e;
            }
            else {
                uVar6 = 0;
                if ((*puVar2 & 0xfff00000) != 0x11000000) {
                    uVar6 = *puVar2 & 0xfffff;
                }
                iVar5 = *piVar1;
                {
                    const int32_t childType = *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(puVar2[2])) + uVar6 * 4);
                    const int32_t tableBase = at<int32_t>(self, 0x14);
                    const int32_t entry = *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(tableBase)) + childType * 4);
                    if (at<int32_t>(pv(entry), 4) != at<int32_t>(self, 0x88)) {
                        goto LAB_0067d96e;
                    }
                }
                local_30[10] = local_30[10] + 1;
                local_30[iVar4] = iVar5;
            }
        LAB_0067d96e:
            *piVar1 = 0;
        }
        local_30[9] = local_30[9] + 1;
    } while (static_cast<uint32_t>(local_30[9]) <
             static_cast<uint32_t>(at<int32_t>(self, 0x4c)));

    uVar6 = 0;
    if (at<int32_t>(self, 0x4c) != 0) {
        do {
            piVar1 = reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x22c))) + uVar6 * 4);
            if ((*piVar1 != 0) &&
                ((uVar3 = *reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(*piVar1))) != 0) &&
                ((uVar3 & 0xfff00000) != 0x72100000)) {
                if (local_30[uVar6 + 4] != 0) {
                    iVar4 = -0x7fffbffb;
                    goto LAB_0067dae0;
                }
                local_30[uVar6 + 4] = *piVar1;
                *piVar1 = 0;
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < static_cast<uint32_t>(at<int32_t>(self, 0x4c)));
    }
    if (((static_cast<uint32_t>(at<int32_t>(self, 200)) & 0xffff) < 0x102) ||
        (iVar4 = FUN_0067ada6(local_30, local_30[10], local_30 + 4, 1), -1 < iVar4)) {
        if ((iVar4 = FUN_0067ada6(local_30, local_30[10], local_30 + 4, 2), -1 < iVar4) &&
            ((iVar4 = FUN_0067ada6(local_30, local_30[10], local_30 + 4, 3), -1 < iVar4) &&
             (iVar4 = FUN_0067a8d2(local_30, local_30[10], local_30 + 4), -1 < iVar4))) {
            local_30[9] = 0;
            if (at<int32_t>(self, 0x4c) != 0) {
                do {
                    if (local_30[local_30[9]] != 0) {
                        iVar4 = -0x7fffbffb;
                        FUN_006626da();
                        local_30[8] = 1;
                    }
                    local_30[9] = local_30[9] + 1;
                } while (static_cast<uint32_t>(local_30[9]) <
                         static_cast<uint32_t>(at<int32_t>(self, 0x4c)));
            }
            if (iVar4 != -0x7fffbffb) {
                uVar6 = 0;
                if (at<int32_t>(self, 0x4c) != 0) {
                    do {
                        *reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x230))) + uVar6 * 4) =
                            local_30[uVar6 + 4];
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < static_cast<uint32_t>(at<int32_t>(self, 0x4c)));
                }
                operator_delete(pv(at<uint32_t>(self, 0x22c)));
                at<uint32_t>(self, 0x22c) = 0;
                at<uint32_t>(self, 0x220) = 0;
                iVar4 = 0;
            }
            if (-1 < iVar4) {
                return iVar4;
            }
        }
    }
LAB_0067dae0:
    if (local_30[8] == 0) {
        FUN_006626da();
    }
    return iVar4;
}

// ---------------------------------------------------------------------------
// 0x67db13 — observed shape
// For each incoming object: publish its slot in the receiver, latch the
// dispatcher table entry (+0x3c) when it is kind 0xd, then dispatch on the
// top 12 bits of the object header to the matching per-type finalizer.
// ---------------------------------------------------------------------------
int32_t FUN_0067db13(void* self, int32_t* param_1, uint32_t param_2)
{
    uint32_t  uVar5 = 0;
    uint32_t  uVar7 = 0;
    uint32_t  uVar8 = 0;
    uint32_t  uVar10 = 0;
    int32_t   iVar2;
    int32_t   iVar3;
    int32_t   iVar4;
    int32_t   iVar6 = 0;
    bool      bVar9 = false;
    uint32_t* puVar1;

    if (param_2 != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            iVar6 = param_1[uVar8];
            at<int32_t>(self, 0x100) = iVar6;
            if (iVar6 != 0) {
                iVar6 = at<int32_t>(pv(iVar6), 0x3c);
                if ((iVar6 != 0) && (at<int32_t>(pv(iVar6), 4) == 0xd)) {
                    at<int32_t>(self, 0x104) = iVar6 + 0x30;
                }
                puVar1 = reinterpret_cast<uint32_t*>(
                    static_cast<std::uintptr_t>(at<int32_t>(self, 0x100)));
                uVar7 = *puVar1;
                if (uVar7 != 0) {
                    const int32_t tableBase = at<int32_t>(self, 0x14);
                    const int32_t firstSlot = *reinterpret_cast<int32_t*>(
                        static_cast<std::uintptr_t>(puVar1[2]));
                    const int32_t firstObj = *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(tableBase)) + firstSlot * 4);
                    if (at<int32_t>(pv(firstObj), 8) != -1) {
                        FUN_006626da();
                        return -0x7fffbffb;
                    }
                    uVar5 = uVar7 & 0xfff00000;
                    if (uVar5 < 0x70300001) {
                        if (uVar5 == 0x70300000) {
                            iVar6 = FUN_006a5fac();
                        }
                        else if (uVar5 < 0x50000001) {
                            if (uVar5 == 0x50000000) {
                                bool useB559 = false;
                                uVar7 = uVar7 & 0xfffff;
                                if (uVar7 == 2) goto LAB_0067de53;
                                if ((uVar7 == 4) &&
                                    ((at<uint32_t>(self, 200) & 0xffff) == 0x101)) {
                                    useB559 = true;
                                }
                                else {
                                    uVar5 = at<uint32_t>(self, 200) & 0xffff;
                                    if (((uVar5 == 0x102) || (uVar5 == 0x103)) && (uVar7 == 4)) {
                                        iVar2 = *reinterpret_cast<int32_t*>(
                                            static_cast<std::uint8_t*>(pv(tableBase)) +
                                            *reinterpret_cast<int32_t*>(
                                                static_cast<std::uintptr_t>(puVar1[4])) * 4);
                                        iVar3 = *reinterpret_cast<int32_t*>(
                                            static_cast<std::uint8_t*>(pv(tableBase)) +
                                            *reinterpret_cast<int32_t*>(
                                                static_cast<std::uintptr_t>(puVar1[2])) * 4);
                                        const int32_t iVar6b = *reinterpret_cast<int32_t*>(
                                            static_cast<std::uint8_t*>(pv(tableBase)) +
                                            at<int32_t>(pv(puVar1[2]), 0x10) * 4);
                                        iVar4 = at<int32_t>(pv(iVar2), 4);
                                        if (iVar4 == at<int32_t>(self, 0x84)) {
                                            if (((at<int32_t>(pv(iVar3), 4) ==
                                                  at<int32_t>(self, 0x88)) &&
                                                 (at<int32_t>(pv(iVar3), 0xc) == 0)) ||
                                                ((at<int32_t>(pv(iVar6b), 4) ==
                                                  at<int32_t>(self, 0x88)) &&
                                                 (at<int32_t>(pv(iVar6b), 0xc) == 0))) {
                                                bVar9 =
                                                    (at<uint32_t>(pv(iVar2), 0x6c) & 0xff) == 1;
                                                if (bVar9) {
                                                    useB559 = true;
                                                }
                                            }
                                        }
                                        else {
                                            if ((at<int32_t>(pv(iVar3), 4) == iVar4) &&
                                                (at<int32_t>(pv(iVar3), 0xc) ==
                                                 at<int32_t>(pv(iVar2), 0xc))) {
                                                useB559 = true;
                                            }
                                            else if (at<int32_t>(pv(iVar6b), 4) == iVar4) {
                                                bVar9 = at<int32_t>(pv(iVar6b), 0xc) ==
                                                        at<int32_t>(pv(iVar2), 0xc);
                                                if (bVar9) {
                                                    useB559 = true;
                                                }
                                            }
                                        }
                                    }
                                    if (!useB559) {
                                        iVar6 = FUN_006a6877();
                                    }
                                }
                                if (useB559) {
                                    iVar6 = FUN_0067b559();
                                }
                            }
                            else {
                                if (uVar5 == 0) goto LAB_0067de1d;
                                if (uVar5 == 0x10000000) {
                                    iVar6 = FUN_006a6662();
                                }
                                else if (uVar5 == 0x10100000) {
                                    iVar6 = FUN_006a5c6c();
                                }
                                else if (uVar5 == 0x11000000) {
                                    iVar6 = FUN_006a5478();
                                }
                                else if (uVar5 == 0x20400000) {
                                    iVar6 = FUN_006a6859();
                                }
                                else if (uVar5 == 0x20500000) {
                                    iVar6 = FUN_006a6863();
                                }
                                else {
                                    if (uVar5 != 0x30000000) goto LAB_0067de53;
                                    if ((at<uint32_t>(self, 200) & 0xffff) == 0x104) {
                                        iVar6 = FUN_006a6934();
                                    }
                                    else {
                                        iVar6 = -0x7fffbfff;
                                    }
                                }
                            }
                        }
                        else if ((uVar5 == 0x60000000) || (uVar5 == 0x60500000) ||
                                 (uVar5 == 0x60a00000) || (uVar5 == 0x60f00000)) {
                            iVar6 = FUN_0067b998();
                        }
                        else if (uVar5 == 0x60700000) {
                            iVar6 = FUN_0067b8c6();
                        }
                        else if (uVar5 != 0x70100000) {
                            goto LAB_0067de53;
                        }
                        else {
                            iVar6 = FUN_006a5deb();
                        }
                    }
                    else {
                        bool numeric = false;
                        if (uVar5 < 0x72600001) {
                            if (uVar5 != 0x72600000) {
                                if (uVar5 == 0x70400000) {
                                    iVar6 = FUN_006a5fac();
                                }
                                else if (uVar5 == 0x70f00000) {
                                    iVar6 = FUN_006a693e();
                                }
                                else if (uVar5 == 0x72100000) {
                                    iVar6 = FUN_0067bae9();
                                }
                                else {
                                    if (uVar5 == 0x72200000) {
                                        uVar10 = 0x47;
                                    }
                                    else if (uVar5 == 0x72300000) {
                                        uVar10 = 0x48;
                                    }
                                    else if (uVar5 == 0x72400000) {
                                        uVar10 = 0x49;
                                    }
                                    else {
                                        if (uVar5 != 0x72500000) goto LAB_0067de53;
                                        uVar10 = 0x4a;
                                    }
                                    numeric = true;
                                }
                            }
                            else {
                                uVar10 = 0x52;
                                numeric = true;
                            }
                        }
                        else if (uVar5 == 0x72700000) {
                            uVar10 = 0x45;
                            numeric = true;
                        }
                        else if (uVar5 == 0x72800000) {
                            uVar10 = 0x46;
                            numeric = true;
                        }
                        else if (uVar5 == 0x72900000) {
                            uVar10 = 0x4d;
                            numeric = true;
                        }
                        else if (uVar5 == 0x72a00000) {
                            uVar10 = 0x4c;
                            numeric = true;
                        }
                        else if (uVar5 == 0x72b00000) {
                            uVar10 = 0x53;
                            numeric = true;
                        }
                        else if (uVar5 == 0x72e00000) {
                            iVar6 = FUN_0067b7eb();
                        }
                        else {
                            goto LAB_0067de53;
                        }
                        if (numeric) {
                            iVar6 = FUN_0067b6a6(uVar10);
                        }
                    }
                    if (iVar6 == -0x7fffbfff) goto LAB_0067de53;
                    if (iVar6 < 0) {
                        return iVar6;
                    }
                }
            }
        LAB_0067de1d:
            uVar8 = uVar8 + 1;
        } while (uVar8 < param_2);
    }
    return 0;

LAB_0067de53:
    FUN_006626da();
    return -0x7fffbfff;
}

// ---------------------------------------------------------------------------
// 0x67df04 — observed shape
// Full frame prep: create the two state blocks at +0x440/+0x444, run a
// validation sweep over the object array for the 0x104 interface version,
// clear per-object link fields, then run the twelve ordered resolution
// passes before the version-specific candidate selection.
// ---------------------------------------------------------------------------
int32_t FUN_0067df04(void* self)
{
    uint32_t  uVar2 = 0;
    uint32_t  uVar3 = 0;
    uint32_t  uVar6 = 0;
    uint32_t  uVar8 = 0;
    int32_t   iVar4 = 0;
    int32_t   iVar7;
    int32_t*  piVar5;
    uint32_t* puVar1;
    uint32_t* puVar9;
    int32_t   local_24;
    uint32_t  local_20;
    uint32_t  local_1c;
    uint32_t  local_18;
    uint32_t  local_14;
    uint32_t  local_10;
    uint32_t  local_c;
    uint32_t  local_8;
    const bool version104 = (at<uint32_t>(self, 200) & 0xffff) == 0x104;

    uVar2 = FUN_0065d97c(&DAT_006c3b94, 0x311, 1, 4);
    uVar3 = static_cast<uint32_t>(FUN_0065d9d5(uVar2, 0, 0, 0.0));
    at<uint32_t>(self, 0x440) = uVar3;
    uVar2 = static_cast<uint32_t>(FUN_0065d9d5(uVar2, 0, 1, 1.0));
    at<uint32_t>(self, 0x444) = uVar2;
    at<uint32_t>(self, 0x44c) = 0;
    if (version104) {
        uVar8 = 0;
        if (at<int32_t>(self, 0xc) != 0) {
            do {
                at<uint32_t>(self, 0xfc) = uVar8;
                puVar1 = reinterpret_cast<uint32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
                at<uint32_t>(self, 0x100) =
                    static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
                if (((*puVar1 & 0xfff00000) == 0x60700000) &&
                    (iVar4 = FUN_0067311b(), iVar4 < 0)) {
                    return iVar4;
                }
                uVar8 = uVar8 + 1;
            } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
        }
        FUN_006959c5();
        FUN_006634e9();
    }
    local_10 = 0;
    local_c = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + local_c * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            local_8 = 0;
            if (puVar1[1] != 0) {
                piVar5 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(puVar1[2]));
                do {
                    const int32_t tableBase = at<int32_t>(self, 0x14);
                    iVar4 = *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(tableBase)) + *piVar5 * 4);
                    const uint32_t typeTable = at<uint32_t>(self, 0x10);
                    const int32_t typeIndex = at<int32_t>(pv(iVar4), 4);
                    const int32_t typeEntry = *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(typeTable)) + typeIndex * 4);
                    uVar8 = at<uint32_t>(pv(typeEntry), 4);
                    if (((((uVar8 & 0x10) != 0) && ((uVar8 & 0x200) == 0)) &&
                         (at<int32_t>(pv(iVar4), 0x10) == 3)) &&
                        ((at<uint8_t>(pv(iVar4), 0x6c) == 0x03) &&
                         (((*puVar1 & 0xfff00000) != 0x60700000 || (local_8 != 7))))) {
                        local_10 = 1;
                        FUN_006626da();
                        break;
                    }
                    local_8 = local_8 + 1;
                    piVar5 = piVar5 + 1;
                } while (local_8 < static_cast<uint32_t>(
                                      at<int32_t>(pv(at<uint32_t>(self, 0x100)), 4)));
            }
            uVar8 = *reinterpret_cast<uint32_t*>(
                        static_cast<std::uintptr_t>(at<uint32_t>(self, 0x100))) &
                    0xfff00000;
            if (((uVar8 == 0x60600000) || (uVar8 == 0x60b00000)) ||
                ((uVar8 == 0x60100000 || (uVar8 == 0x61000000)))) {
                FUN_006626da();
                local_10 = 1;
            }
            local_c = local_c + 1;
        } while (local_c < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
        if (local_10 != 0) {
            return -0x7fffbffb;
        }
    }
    uVar8 = 0;
    if (at<int32_t>(self, 8) != 0) {
        do {
            int32_t obj = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) + uVar8 * 4);
            at<int32_t>(pv(obj), 0x38) = -1;
            puVar9 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(obj));
            if (at<int32_t>(pv(obj), 4) == at<int32_t>(self, 0x80)) {
                if (at<uint8_t>(pv(obj), 0x6c) == 0x01) {
                    at<uint32_t>(pv(obj), 0) = 0x14;
                }
                if ((at<uint32_t>(self, 200) & 0xffff) < 0x104) {
                    puVar9 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(
                        *reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) +
                            uVar8 * 4)));
                    if (reinterpret_cast<uint8_t*>(puVar9)[0x6c] == 0x03) {
                        *puVar9 = 0x14;
                    }
                }
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 8)));
    }
    uVar8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar6 = *puVar1 & 0xfff00000;
            if (((((uVar6 == 0x60000000) || (uVar6 == 0x60500000)) || (uVar6 == 0x60a00000)) ||
                 (uVar6 == 0x60f00000)) &&
                (uVar6 = 0, puVar1[3] != 0)) {
                do {
                    const uint32_t obj = at<uint32_t>(self, 0x100);
                    const uint32_t indexArray = at<uint32_t>(pv(obj), 0x10);
                    const int32_t index = *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(indexArray)) + uVar6 * 4);
                    const int32_t slot = *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) + index * 4);
                    at<uint32_t>(pv(slot), 0) = 0x14;
                    uVar6 = uVar6 + 1;
                } while (uVar6 < static_cast<uint32_t>(at<int32_t>(pv(at<uint32_t>(self, 0x100)), 0xc)));
            }
            uVar8 = uVar8 + 1;
            at<uint32_t>(pv(at<uint32_t>(self, 0x100)), 0x24) = 0;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    uVar8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar6 = *puVar1 & 0xfff00000;
            if ((((uVar6 == 0x20000000) || (uVar6 == 0x20100000)) ||
                 (uVar6 == 0x30000000)) &&
                (iVar4 = FUN_00697497(), iVar4 < 0)) {
                return iVar4;
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    uVar8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar6 = *puVar1 & 0xfff00000;
            if (uVar6 == 0x10000000) {
                iVar4 = FUN_0067357d();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else if (uVar6 == 0x10100000) {
                iVar4 = FUN_006736a9();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    FUN_006959c5();
    uVar8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar6 = *puVar1 & 0xfff00000;
            if (uVar6 == 0x10100000) {
                FUN_006a114f();
                iVar4 = FUN_006a247c();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else {
                if (uVar6 == 0x20400000) {
                    FUN_006a251c();
                    FUN_006a1e95();
                    FUN_006a22f4();
                    iVar4 = FUN_006a2192();
                    if (iVar4 < 0) {
                        return iVar4;
                    }
                }
                else if (uVar6 == 0x20500000) {
                    FUN_006a2192();
                    iVar4 = FUN_006a247c();
                    if (iVar4 < 0) {
                        return iVar4;
                    }
                }
                else if (uVar6 == 0x50000000) {
                    iVar4 = FUN_006992d0();
                    if (iVar4 < 0) {
                        return iVar4;
                    }
                }
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    FUN_006959c5();
    uVar8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar6 = *puVar1 & 0xfff00000;
            if (((uVar6 == 0x20400000) || (uVar6 == 0x20500000)) &&
                (iVar4 = FUN_006758fc(), iVar4 < 0)) {
                return iVar4;
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    FUN_006959c5();
    uVar8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            if ((*puVar1 & 0xfff00000) == 0x60f00000) {
                iVar4 = FUN_00674e44();
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = FUN_00674e44();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    FUN_006959c5();
    uVar8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            if (((*puVar1 & 0xfff00000) == 0x20400000) &&
                (iVar4 = FUN_00675520(), iVar4 < 0)) {
                return iVar4;
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    FUN_006959c5();
    uVar8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            if ((*puVar1 & 0xfff00000) == 0x70300000) {
                FUN_006a26b9();
                iVar4 = FUN_0069cb30();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    uVar8 = static_cast<uint32_t>(at<int32_t>(self, 0xc));
    uVar6 = 0;
    if (uVar8 != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar6;
            at<uint32_t>(self, 0x100) =
                *reinterpret_cast<uint32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar6 * 4);
            iVar4 = FUN_00674889();
            if (iVar4 < 0) {
                return iVar4;
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < uVar8);
    }
    FUN_006959c5();
    iVar4 = FUN_0069d701();
    if (iVar4 < 0) {
        return iVar4;
    }
    iVar4 = FUN_006752d1();
    if (iVar4 < 0) {
        return iVar4;
    }
    iVar4 = FUN_00673c98();
    if (iVar4 < 0) {
        return iVar4;
    }
    if (version104) {
        iVar4 = FUN_00533c78();
        at<int32_t>(self, 0x22c) = iVar4;
        if (iVar4 == 0) {
            return -0x7ff8fff2;
        }
        iVar4 = FUN_00533c78();
        at<int32_t>(self, 0x230) = iVar4;
        if (iVar4 == 0) {
            return -0x7ff8fff2;
        }
        at<uint32_t>(self, 0x224) = 0;
        at<uint32_t>(self, 0x220) = 0;
        puVar9 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(at<uint32_t>(self, 0x22c)));
        for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
        }
        puVar9 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(at<uint32_t>(self, 0x230)));
        for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
        }
        iVar4 = FUN_00677223();
        if (iVar4 < 0) {
            return iVar4;
        }
        iVar4 = FUN_00677783();
        if (iVar4 < 0) {
            return iVar4;
        }
        if (FUN_006778eb() == 0) {
            uVar8 = FUN_00677811();
            if (uVar8 != 0xffffffff) {
                FUN_0067707d();
                local_10 = 0;
                piVar5 = reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(self) + 0x304);
                do {
                    iVar4 = static_cast<int32_t>(FUN_0065d9d5(at<uint32_t>(self, 0x88), 0, 0, 0.0));
                    *piVar5 = iVar4;
                    if (iVar4 == -1) {
                        return -0x7ff8fff2;
                    }
                    local_10 = local_10 + 1;
                    piVar5 = piVar5 + 1;
                    {
                        const int32_t obj = *reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) + iVar4 * 4);
                        at<uint32_t>(pv(obj), 0x3c) = 0;
                    }
                } while (local_10 < 0x40);
                local_14 = 0xffffffff;
                local_20 = 0xffffffff;
                puVar9 = reinterpret_cast<uint32_t*>(static_cast<std::uint8_t*>(self) + 0x2c4);
                for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar9 = 0;
                    puVar9 = puVar9 + 1;
                }
                local_8 = 0;
                if (uVar8 != 0) {
                    do {
                        puVar9 = reinterpret_cast<uint32_t*>(
                            static_cast<std::uintptr_t>(at<uint32_t>(self, 0x22c)));
                        for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
                            *puVar9 = 0;
                            puVar9 = puVar9 + 1;
                        }
                        puVar9 = reinterpret_cast<uint32_t*>(
                            static_cast<std::uintptr_t>(at<uint32_t>(self, 0x230)));
                        for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
                            *puVar9 = 0;
                            puVar9 = puVar9 + 1;
                        }
                        at<uint32_t>(self, 0x220) = 0;
                        at<uint32_t>(self, 0x224) = 0;
                        iVar4 = FUN_00677b94(local_8, 1);
                        if (iVar4 != 0) {
                            at<uint32_t>(self, 0x408) = 0;
                            at<uint32_t>(self, 0x404) = 0;
                            FUN_00677176();
                            FUN_0067c441(at<uint32_t>(self, 0x22c), 6,
                                         at<uint32_t>(self, 0x220), &local_1c);
                            FUN_0067c441(at<uint32_t>(self, 0x230), 6,
                                         at<uint32_t>(self, 0x224), &local_10);
                            piVar5 = reinterpret_cast<int32_t*>(
                                static_cast<std::uint8_t*>(self) + 0x2c4);
                            local_c = 0x10;
                            do {
                                if (*piVar5 != 0) {
                                    FUN_00614343();
                                }
                                *piVar5 = 0;
                                piVar5 = piVar5 + 1;
                                local_c = local_c - 1;
                            } while (local_c != 0);
                            iVar4 = FUN_0067d4e6();
                            if (iVar4 < 0) {
                                return iVar4;
                            }
                            if (((iVar4 != 1) && (iVar4 = FUN_00677f73(), -1 < iVar4)) &&
                                (iVar4 = FUN_006796fd(1, 1), -1 < iVar4)) {
                                FUN_0067c441(at<uint32_t>(self, 0x22c), 6,
                                             at<uint32_t>(self, 0x220), &local_1c);
                                FUN_0067c441(at<uint32_t>(self, 0x230), 6,
                                             at<uint32_t>(self, 0x224), &local_10);
                                const int32_t* first = reinterpret_cast<const int32_t*>(
                                    static_cast<std::uintptr_t>(at<uint32_t>(self, 0x22c)));
                                const int32_t* second = reinterpret_cast<const int32_t*>(
                                    static_cast<std::uintptr_t>(at<uint32_t>(self, 0x230)));
                                iVar7 = 0;
                                local_c = 0;
                                local_18 = 6;
                                for (std::uint32_t k = 0; k < 6; ++k) {
                                    if (first[k] != 0) {
                                        iVar7 = iVar7 + 1;
                                    }
                                    if (second[k] != 0) {
                                        local_c = local_c + 1;
                                    }
                                }
                                local_18 = local_1c;
                                if (local_1c <= static_cast<uint32_t>(iVar7 * 2)) {
                                    local_18 = static_cast<uint32_t>(iVar7 * 2);
                                }
                                uVar6 = local_10;
                                if (local_10 <= local_c * 2) {
                                    uVar6 = local_c * 2;
                                }
                                uVar6 = (-static_cast<uint32_t>(iVar7 + local_1c != 0) & 10) +
                                        uVar6 + local_18;
                                if (8 < local_1c) {
                                    uVar6 = uVar6 + 0x14;
                                }
                                if (8 < local_10) {
                                    uVar6 = uVar6 + 0x14;
                                }
                                if (uVar6 < local_20) {
                                    local_14 = local_8;
                                    local_20 = uVar6;
                                }
                                at<uint32_t>(self, 0x404) = 0;
                            }
                        }
                        local_8 = local_8 + 1;
                    } while (local_8 < uVar8);
                }
                puVar9 = reinterpret_cast<uint32_t*>(
                    static_cast<std::uintptr_t>(at<uint32_t>(self, 0x22c)));
                for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar9 = 0;
                    puVar9 = puVar9 + 1;
                }
                puVar9 = reinterpret_cast<uint32_t*>(
                    static_cast<std::uintptr_t>(at<uint32_t>(self, 0x230)));
                for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar9 = 0;
                    puVar9 = puVar9 + 1;
                }
                at<uint32_t>(self, 0x220) = 0;
                at<uint32_t>(self, 0x224) = 0;
                piVar5 = reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(self) + 0x2c4);
                local_24 = 0xc;
                do {
                    if (*piVar5 != 0) {
                        FUN_00614343();
                    }
                    *piVar5 = 0;
                    piVar5 = piVar5 + 1;
                    local_24 = local_24 + -1;
                } while (local_24 != 0);
                if (local_14 != 0xffffffff) {
                    FUN_00677b94(local_14, 0);
                    FUN_00677176();
                    FUN_0067d4e6();
                    iVar4 = FUN_00677f73();
                    if (iVar4 < 0) {
                        return iVar4;
                    }
                    iVar4 = FUN_006796fd(0, 0);
                    if (iVar4 < 0) {
                        return iVar4;
                    }
                    piVar5 = reinterpret_cast<int32_t*>(
                        static_cast<std::uintptr_t>(at<uint32_t>(self, 0x22c)));
                    uVar8 = 0;
                    do {
                        if (*piVar5 != 0) break;
                        uVar8 = uVar8 + 1;
                        piVar5 = piVar5 + 1;
                    } while (uVar8 < 6);
                    if ((at<int32_t>(self, 0x220) == 6) && (uVar8 == 6)) {
                        at<uint32_t>(self, 0x220) = 0;
                    }
                    goto LAB_0067e91f;
                }
            }
        }
        FUN_006626da();
        return -0x7fffbffb;
    }
    if (at<uint32_t>(self, 0xc) >= 0x81) {
        FUN_006626da();
        return -0x7fffbffb;
    }
    iVar4 = FUN_00676ac7();
    if (iVar4 < 0) {
        return iVar4;
    }
    if (at<int32_t>(self, 0x22c) != 0) {
        iVar4 = FUN_00673ae5();
        if (iVar4 < 0) {
            return iVar4;
        }
        if (((at<int32_t>(self, 0x22c) != 0) &&
             ((at<uint32_t>(self, 200) & 0xffff) != 0x104)) &&
            (iVar4 = FUN_0067d8c9(self), iVar4 < 0)) {
            return iVar4;
        }
    }
    if ((at<int32_t>(self, 0x230) != 0) &&
        ((at<uint32_t>(self, 200) & 0xffff) != 0x104)) {
        iVar4 = FUN_00673f3c();
        if (iVar4 < 0) {
            return iVar4;
        }
        iVar4 = FUN_0067cbd8();
        if (iVar4 < 0) {
            return iVar4;
        }
        iVar4 = FUN_00674311();
        if (iVar4 < 0) {
            return iVar4;
        }
    }
    at<uint32_t>(self, 0xdc) = 0;
    iVar4 = FUN_006796fd(0, 0);
    if (iVar4 < 0) {
        return iVar4;
    }
LAB_0067e91f:
    at<uint32_t>(self, 0xdc) = 1;
    iVar4 = FUN_00678c07();
    if (iVar4 < 0) {
        return iVar4;
    }
    iVar4 = FUN_0067c441(at<uint32_t>(self, 0x22c), 0, at<uint32_t>(self, 0x220), nullptr);
    if (iVar4 < 0) {
        return iVar4;
    }
    iVar4 = FUN_0067c441(at<uint32_t>(self, 0x230), 0, at<uint32_t>(self, 0x224), nullptr);
    if (iVar4 < 0) {
        return iVar4;
    }
    iVar4 = FUN_006738a3();
    if (iVar4 < 0) {
        return iVar4;
    }
    if (((at<int32_t>(self, 0x230) == 0) || ((at<uint32_t>(self, 200) & 0xffff) == 0x104)) ||
        (iVar4 = FUN_0067303c(), -1 < iVar4)) {
        return 0;
    }
    return iVar4;
}

// ---------------------------------------------------------------------------
// 0x67e9e5 — observed shape
// Clear the eight-dword table at +0x1f8, the two counters at +0x218/+0x21c,
// then enter the shared reset routine.
// ---------------------------------------------------------------------------
void FUN_0067e9e5(void* self)
{
    int32_t  iVar1;
    uint32_t* puVar2;

    puVar2 = reinterpret_cast<uint32_t*>(static_cast<std::uint8_t*>(self) + 0x1f8);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    at<uint32_t>(self, 0x218) = 0;
    at<uint32_t>(self, 0x21c) = 0;
    FUN_006a3d1c();
}

// ---------------------------------------------------------------------------
// 0x67eaf8 — observed shape
// Ordered per-type update passes over the object array; the first pass runs
// only when the "dirty" bit (+0xcc & 4) is set, and pass 2 re-enters the
// shared tail when the bit is still set afterwards.
// ---------------------------------------------------------------------------
int32_t FUN_0067eaf8(void* self)
{
    uint32_t  uVar2;
    uint32_t  uVar3 = 0;
    int32_t   iVar4 = 1;
    uint32_t* puVar1;
    const auto objectCount = [self]() -> uint32_t {
        return static_cast<uint32_t>(at<int32_t>(self, 0xc));
    };

    if ((at<uint8_t>(self, 0xcc) & 4) != 0) {
        FUN_0066254f();
        if (at<int32_t>(self, 0xc) != 0) {
            do {
                at<uint32_t>(self, 0xfc) = uVar3;
                puVar1 = reinterpret_cast<uint32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
                at<uint32_t>(self, 0x100) =
                    static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
                if ((*puVar1 & 0xfff00000) == 0x10000000) {
                    FUN_00696ab9();
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < objectCount());
        }
        FUN_00662568();
        if ((at<uint8_t>(self, 0xcc) & 4) != 0) goto LAB_0067ee58;
    }
    uVar3 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar3;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar2 = *puVar1 & 0xfff00000;
            if (uVar2 == 0x10100000) {
                iVar4 = FUN_006a114f(1);
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else {
                if (((uVar2 == 0x20000000) || (uVar2 == 0x20100000)) ||
                    (uVar2 == 0x30000000)) {
                    iVar4 = FUN_00697497();
                    FUN_006959c5();
                    if (iVar4 < 0) {
                        return iVar4;
                    }
                }
                else {
                    iVar4 = 1;
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < objectCount());
    }
    uVar3 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar3;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            if ((*puVar1 & 0xfff00000) == 0x30000000) {
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = FUN_00696b3c(0, 0, 0);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = FUN_00697138(0, 0, 0);
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else {
                iVar4 = 1;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < objectCount());
    }
    iVar4 = FUN_006634e9();
    if (iVar4 < 0) {
        return iVar4;
    }
    FUN_006959c5();
    uVar3 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar3;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar2 = *puVar1 & 0xfff00000;
            if ((uVar2 == 0x20000000) || (uVar2 == 0x70b00000)) {
                iVar4 = FUN_00697497();
                FUN_006959c5();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < objectCount());
    }
    uVar3 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar3;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar2 = *puVar1 & 0xfff00000;
            if (uVar2 == 0x10500000) {
                iVar4 = FUN_00696630();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else if (uVar2 == 0x10f00000) {
                iVar4 = FUN_006999b4();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else if (uVar2 == 0x20400000) {
                iVar4 = FUN_0069be37();
                if (iVar4 != 0) {
                    iVar4 = FUN_006a1209(1);
                    if (iVar4 < 0) {
                        return iVar4;
                    }
                }
            }
            else if ((uVar2 == 0x30000000) &&
                     (iVar4 = FUN_0069c4b5(), iVar4 != 0)) {
                iVar4 = FUN_0069c587();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < objectCount());
    }
    iVar4 = FUN_006634e9();
    if (iVar4 < 0) {
        return iVar4;
    }
    FUN_006959c5();
    uVar3 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar3;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar2 = *puVar1 & 0xfff00000;
            if (uVar2 == 0x20500000) {
                iVar4 = FUN_0069b834();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else if (uVar2 == 0x50000000) {
                iVar4 = FUN_0069c0f7();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else if (uVar2 == 0x70300000) {
                iVar4 = FUN_0069cb30(0);
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else if ((uVar2 == 0x73500000) || (uVar2 == 0x73600000)) {
                iVar4 = FUN_00699cf5();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < objectCount());
    }
    FUN_006959c5();
    uVar3 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar3;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            if ((*puVar1 & 0xfff00000) == 0x70300000) {
                FUN_006a26b9();
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < objectCount());
    }
    FUN_006959c5();
    uVar3 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar3;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            uVar2 = *puVar1 & 0xfff00000;
            if (uVar2 == 0x70300000) {
                iVar4 = FUN_0069cb30(0);
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            else if ((((uVar2 == 0x73500000) || (uVar2 == 0x73600000)) ||
                      (uVar2 == 0x73700000)) ||
                     (uVar2 == 0x73800000)) {
                iVar4 = FUN_00699fa5();
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < objectCount());
    }
LAB_0067ee58:
    uVar3 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            at<uint32_t>(self, 0xfc) = uVar3;
            puVar1 = reinterpret_cast<uint32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar3 * 4);
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar1));
            if (((*puVar1 & 0xfff00000) == 0x50300000) &&
                (iVar4 = FUN_0069606d(), iVar4 < 0)) {
                return iVar4;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < objectCount());
    }
    iVar4 = FUN_006634e9();
    if (((-1 < iVar4) && (iVar4 = FUN_0066be13(), -1 < iVar4)) &&
        ((iVar4 = FUN_0065e4f2(), -1 < iVar4 && (iVar4 = FUN_00664b28(), -1 < iVar4)))) {
        FUN_006959c5();
        iVar4 = 0;
    }
    return iVar4;
}

// ---------------------------------------------------------------------------
// 0x67eed6 — observed shape
// Lazily create the two state blocks when a type-0x202/0x203 object appears
// and the slot is still unset, run the conditional 0x103..0x107/0x50000000
// pass, then re-home every object whose +0x54 link is -1 and whose type
// entry marks it, excluding the two state indices.
// ---------------------------------------------------------------------------
int32_t FUN_0067eed6(void* self)
{
    uint32_t  uVar4;
    uint32_t  uVar5;
    uint32_t  uVar6;
    uint32_t  uVar7;
    uint32_t  uVar8 = 0;
    int32_t   iVar3;
    int32_t   local_8;
    uint32_t* puVar2;

    at<uint32_t>(self, 0x220) = 0xffffffff;
    at<uint32_t>(self, 0x224) = 0xffffffff;
    local_8 = 0;
    if (at<int32_t>(self, 0xc) != 0) {
        do {
            void* puVar1 = static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) + uVar8 * 4;
            at<uint32_t>(self, 0xfc) = uVar8;
            at<uint32_t>(self, 0x100) = *reinterpret_cast<uint32_t*>(puVar1);
            at<uint32_t>(self, 0xfc) = uVar8;
            puVar2 = reinterpret_cast<uint32_t*>(
                static_cast<std::uintptr_t>(*reinterpret_cast<uint32_t*>(puVar1)));
            at<uint32_t>(self, 0x100) =
                static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar2));
            uVar4 = *puVar2 & 0xfff00000;
            if (((uVar4 == 0x20300000) || (uVar4 == 0x20200000)) &&
                (at<int32_t>(self, 0x220) == -1)) {
                uVar5 = FUN_0065d97c(&DAT_006c3b94, 0x311, 1, 4);
                uVar6 = static_cast<uint32_t>(FUN_0065d9d5(uVar5, 0, 0, 0.0));
                at<uint32_t>(self, 0x220) = uVar6;
                uVar5 = static_cast<uint32_t>(FUN_0065d9d5(uVar5, 0, 1, 1.0));
                at<uint32_t>(self, 0x224) = uVar5;
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
    }
    FUN_006959c5();
    if ((at<uint8_t>(self, 0xcc) & 4) == 0) {
        uVar8 = 0;
        if (at<int32_t>(self, 0xc) != 0) {
            do {
                at<uint32_t>(self, 0xfc) = uVar8;
                puVar2 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(
                    *reinterpret_cast<uint32_t*>(
                        static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x18))) +
                        uVar8 * 4)));
                at<uint32_t>(self, 0x100) =
                    static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(puVar2));
                uVar4 = *puVar2;
                uVar7 = uVar4 & 0xfff00000;
                if (((uVar7 == 0x10300000) ||
                     ((uVar7 == 0x10500000 || (uVar7 == 0x10600000)))) ||
                    (uVar7 == 0x10700000)) {
                    local_8 = FUN_006992d0();
                    if (local_8 < 0) {
                        return local_8;
                    }
                }
                else if (uVar7 == 0x50000000) {
                    if (2 < (uVar4 & 0xfffff)) {
                        local_8 = FUN_006992d0();
                    }
                    if (local_8 < 0) {
                        return local_8;
                    }
                }
                else {
                    local_8 = 1;
                }
                uVar8 = uVar8 + 1;
            } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 0xc)));
        }
    }
    FUN_006959c5();
    uVar8 = 0;
    if (at<int32_t>(self, 8) != 0) {
        do {
            iVar3 = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) + uVar8 * 4);
            const int32_t typeIndex = at<int32_t>(pv(iVar3), 4);
            const int32_t typeEntry = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x10))) + typeIndex * 4);
            if ((((at<int32_t>(pv(iVar3), 0x54) == -1) &&
                  ((at<uint8_t>(pv(typeEntry), 5) & 1) != 0)) &&
                 (at<uint32_t>(self, 0x224) != uVar8)) &&
                (at<uint32_t>(self, 0x220) != uVar8)) {
                at<int32_t>(pv(iVar3), 4) = at<int32_t>(self, 0x74);
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < static_cast<uint32_t>(at<int32_t>(self, 8)));
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x67f067 — observed shape
// Build the class-presence mask for the incoming object array, add the
// "single class only" bit when the receiver is not in the alternate mode,
// then optionally scatter the indices into the selection buffer.
// ---------------------------------------------------------------------------
uint32_t FUN_0067f067(void* self, int32_t* param_1, uint32_t param_2,
                      uint32_t* param_3, int32_t param_4)
{
    uint32_t  uVar3;
    uint32_t  uVar4 = 0;
    uint32_t  local_8 = 0;
    int32_t   iVar2;
    int32_t*  piVar1;
    bool      bVar5;

    if (param_4 == 0) {
        iVar2 = *reinterpret_cast<int32_t*>(
            static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) + *param_1 * 4);
        if ((at<uint8_t>(pv(iVar2), 0x3d) & 2) != 0) {
            local_8 = 0x100000;
        }
        if (param_2 != 0) {
            do {
                iVar2 = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) +
                    param_1[uVar4] * 4);
                iVar2 = at<int32_t>(pv(iVar2), 0x10);
                uVar3 = 0;
                if (iVar2 == 0) {
                    uVar3 = 0x10000;
                }
                else if (iVar2 == 1) {
                    uVar3 = 0x20000;
                }
                else if (iVar2 == 2) {
                    uVar3 = 0x40000;
                }
                else if (iVar2 == 3) {
                    uVar3 = 0x80000;
                }
                if ((local_8 & uVar3) != 0) {
                    FUN_006626da();
                }
                local_8 = local_8 | uVar3;
                uVar4 = uVar4 + 1;
            } while (uVar4 < param_2);
        }
    }
    else {
        local_8 = 0xf0000;
    }
    if ((at<uint32_t>(self, 0xcc) & 0x20) == 0) {
        uVar4 = 0;
        bVar5 = param_2 == 0;
        if (param_2 != 0) {
            do {
                iVar2 = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) +
                    param_1[uVar4] * 4);
                const int32_t typeIndex = at<int32_t>(pv(iVar2), 4);
                const int32_t typeEntry = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x10))) +
                    typeIndex * 4);
                if (((at<uint8_t>(pv(iVar2), 3) & 2) == 0) &&
                    ((((at<uint8_t>(pv(typeEntry), 4) & 1) == 0 ||
                       (at<int32_t>(pv(iVar2), 0x48) == -1)) ||
                      (at<int32_t>(pv(iVar2), 0x54) != -1)))) {
                    break;
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < param_2);
            bVar5 = uVar4 == param_2;
        }
        if (!bVar5) {
            goto LAB_0067f156;
        }
    }
    local_8 = local_8 | 0x200000;
LAB_0067f156:
    if ((at<uint8_t>(self, 0xcc) & 1) != 0) {
        uVar4 = 0;
        if ((at<int32_t>(self, 0x124) != 0) && (param_2 != 0)) {
            do {
                piVar1 = param_1 + uVar4;
                iVar2 = static_cast<int32_t>(uVar4) + at<int32_t>(self, 0x128) * 6;
                uVar4 = uVar4 + 1;
                *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x124))) +
                    (-0x10 + iVar2 * 4)) = *piVar1;
            } while (uVar4 < param_2);
        }
    }
    *param_3 = local_8;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x67f1a1 — observed shape
// Validate the receiver's 4x4 class occupancy grid: fill the grid and its
// link fields from the object array, then report 0x80004005 when any row is
// empty or ragged, or when the receiver's own class turns up empty.
// ---------------------------------------------------------------------------
uint32_t FUN_0067f1a1(void* self)
{
    uint32_t  uVar1 = 0;
    int32_t   iVar2;
    int32_t   iVar4;
    int32_t*  piVar3;
    int32_t   local_64[16];
    int32_t   local_24[8];

    if (at<int32_t>(self, 0x158) == 0) {
        piVar3 = local_64;
        for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar3 = 0;
            piVar3 = piVar3 + 1;
        }
        local_24[0] = 0;
        local_24[1] = 0;
        local_24[2] = 0;
        local_24[3] = 0;
        at<int32_t>(self, 0x218) = 0;
        at<int32_t>(self, 0x21c) = 0;
        piVar3 = reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(self) + 0x1f8);
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar3 = 0;
            piVar3 = piVar3 + 1;
        }
        local_24[7] = 0;
        local_24[5] = 0;
        local_24[6] = 0;
        if (at<int32_t>(self, 8) != 0) {
            do {
                iVar4 = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) +
                    local_24[6] * 4);
                const int32_t typeIndex = at<int32_t>(pv(iVar4), 4);
                const int32_t typeEntry = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x10))) +
                    typeIndex * 4);
                uVar1 = at<uint32_t>(pv(typeEntry), 4);
                if ((uVar1 & 0x20) == 0) {
                    if (((uVar1 & 0x10) != 0) && ((uVar1 & 0x200) == 0)) {
                        auto getKind = reinterpret_cast<int32_t (*)(uint32_t)>(
                            vtbl_slot(self, 0x54));
                        auto getIndex = reinterpret_cast<uint32_t (*)(uint32_t)>(
                            vtbl_slot(self, 0x58));
                        iVar2 = getKind(at<uint32_t>(pv(iVar4), 0x6c));
                        uVar1 = getIndex(at<uint32_t>(pv(iVar4), 0x6c));
                        if (iVar2 == 6) {
                            if (uVar1 < 8) {
                                iVar2 = static_cast<int32_t>(uVar1) + 0x7e;
                                goto LAB_0067f2d0;
                            }
                        }
                        else if ((iVar2 == 0xb) && (uVar1 < 2)) {
                            iVar2 = static_cast<int32_t>(uVar1) + 0x86;
                        LAB_0067f2d0:
                            uVar1 = at<int32_t>(pv(iVar4), 0x10) + 1;
                            if (at<uint32_t>(self,
                                             static_cast<std::size_t>(iVar2) * 4) < uVar1) {
                                at<uint32_t>(self,
                                             static_cast<std::size_t>(iVar2) * 4) = uVar1;
                            }
                        }
                    }
                }
                else {
                    auto getKind = reinterpret_cast<int32_t (*)(uint32_t)>(
                        vtbl_slot(self, 0x54));
                    auto getIndex = reinterpret_cast<uint32_t (*)(uint32_t)>(
                        vtbl_slot(self, 0x58));
                    iVar2 = getKind(at<uint32_t>(pv(iVar4), 0x6c));
                    uVar1 = getIndex(at<uint32_t>(pv(iVar4), 0x6c));
                    if (iVar2 == 0xb) {
                        if (uVar1 < 4) {
                            local_64[at<int32_t>(pv(iVar4), 0x10) + uVar1 * 4] = 1;
                            local_24[uVar1] = at<int32_t>(pv(iVar4), 0x60);
                        }
                    }
                    else if ((((iVar2 == 0xd) && (uVar1 == 0)) &&
                              (at<int32_t>(pv(iVar4), 0x10) != 0)) &&
                             (local_24[5] == 0)) {
                        FUN_006626da();
                        local_24[5] = 1;
                        local_24[7] = 1;
                    }
                }
                local_24[6] = local_24[6] + 1;
            } while (static_cast<uint32_t>(local_24[6]) <
                     static_cast<uint32_t>(at<int32_t>(self, 8)));
        }
        local_24[6] = 0;
        local_24[4] = 1;
        uVar1 = 0;
        do {
            iVar4 = 0;
            piVar3 = local_64 + uVar1 * 4;
            local_24[5] = 4;
            do {
                iVar2 = *piVar3;
                piVar3 = piVar3 + 1;
                iVar4 = iVar4 + static_cast<int32_t>(iVar2 != 0);
                local_24[5] = local_24[5] + -1;
            } while (local_24[5] != 0);
            if (iVar4 == 0) {
                if (uVar1 == 0) {
                    FUN_006626da();
                    local_24[7] = 1;
                }
                local_24[6] = 1;
            }
            else {
                if (iVar4 != 4) {
                    FUN_006626da();
                    local_24[7] = 1;
                }
                if (local_24[6] != 0) {
                    local_24[4] = 0;
                }
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < 4);
        if (local_24[4] == 0) {
            FUN_006626da();
            local_24[7] = 1;
        }
        uVar1 = -static_cast<uint32_t>(local_24[7] != 0) & 0x80004005;
    }
    return uVar1;
}

// ---------------------------------------------------------------------------
// 0x67f3a0 — observed shape
// Fetch the four class indices for the current descriptor, map them through
// the object table to per-class values, then issue the two descriptor
// updates (mode 2 with source/destination split, then mode 0x58).
// ---------------------------------------------------------------------------
void FUN_0067f3a0(void* self)
{
    uint32_t* puVar1;
    int32_t   iVar2;
    uint32_t  uVar3;
    int32_t   local_54[4];
    int32_t   local_44[4];
    uint32_t  local_34[4];
    uint32_t  local_24[4];
    uint32_t  local_14;
    uint32_t  local_10;
    uint32_t  local_c;
    uint32_t  local_8;

    puVar1 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(at<uint32_t>(self, 0x100)));
    local_c = puVar1[3];
    local_14 = puVar1[4];
    local_10 = puVar1[2];
    uVar3 = *puVar1 & 0xfffff;
    iVar2 = reinterpret_cast<int32_t (*)(uint32_t, void*, uint32_t, uint32_t, uint32_t)>(
                vtbl_slot(self, 0x80))(at<uint32_t>(self, 0xfc), local_34, 4, 0, 0);
    if (-1 < iVar2) {
        local_8 = 0;
        do {
            local_44[local_8] = at<int32_t>(self, 0x220);
            local_54[local_8] = at<int32_t>(self, 0x224);
            if (local_8 < local_c) {
                const uint32_t tableBase = at<uint32_t>(self, 0x14);
                const int32_t index = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(local_14)) + local_8 * 4);
                const int32_t entry = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(tableBase)) + index * 4);
                local_24[local_8] = local_34[at<int32_t>(pv(entry), 0x10)];
            }
            local_8 = local_8 + 1;
        } while (local_8 < 4);
        FUN_006a4aab(2, local_24, local_c, pv(local_10),
                     pv(local_10 + uVar3 * 4), nullptr, uVar3, 0, 0x1000000, 0, 0);
        FUN_006a4aab(0x58, pv(local_14), local_c, local_24, local_54, local_44,
                     uVar3, 0, 0, 0, 0);
    }
}

// ---------------------------------------------------------------------------
// 0x67f47c — observed shape
// Same descriptor update as 0x67f3a0, with the two per-class arrays filled
// in the opposite order (+0x88 into local_54, +0x89 into local_44).
// ---------------------------------------------------------------------------
void FUN_0067f47c(void* self)
{
    uint32_t* puVar1;
    int32_t   iVar2;
    uint32_t  uVar3;
    int32_t   local_54[4];
    int32_t   local_44[4];
    uint32_t  local_34[4];
    uint32_t  local_24[4];
    uint32_t  local_14;
    uint32_t  local_10;
    uint32_t  local_c;
    uint32_t  local_8;

    puVar1 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(at<uint32_t>(self, 0x100)));
    local_c = puVar1[3];
    local_14 = puVar1[4];
    local_10 = puVar1[2];
    uVar3 = *puVar1 & 0xfffff;
    iVar2 = reinterpret_cast<int32_t (*)(uint32_t, void*, uint32_t, uint32_t, uint32_t)>(
                vtbl_slot(self, 0x80))(at<uint32_t>(self, 0xfc), local_34, 4, 0, 0);
    if (-1 < iVar2) {
        local_8 = 0;
        do {
            local_54[local_8] = at<int32_t>(self, 0x220);
            local_44[local_8] = at<int32_t>(self, 0x224);
            if (local_8 < local_c) {
                const uint32_t tableBase = at<uint32_t>(self, 0x14);
                const int32_t index = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(local_14)) + local_8 * 4);
                const int32_t entry = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(tableBase)) + index * 4);
                local_24[local_8] = local_34[at<int32_t>(pv(entry), 0x10)];
            }
            local_8 = local_8 + 1;
        } while (local_8 < 4);
        FUN_006a4aab(2, local_24, local_c, pv(local_10),
                     pv(local_10 + uVar3 * 4), nullptr, uVar3, 0, 0x1000000, 0, 0);
        FUN_006a4aab(0x58, pv(local_14), local_c, local_24, local_54, local_44,
                     uVar3, 0, 0, 0, 0);
    }
}

// ---------------------------------------------------------------------------
// 0x67f558 — observed shape
// Emit a mode-2 pairing when the first surface shares the shared-type slot
// (+4/+0xc) with either of the two other surfaces, then always emit the
// mode-0x58 (or mode 0xb fallback) descriptor update.
// ---------------------------------------------------------------------------
void FUN_0067f558(void* self)
{
    uint32_t* puVar1;
    int32_t*  piVar2;
    int32_t*  piVar8;
    int32_t*  piVar9;
    int32_t*  piVar10;
    uint32_t  uVar3;
    uint32_t  uVar6;
    uint32_t  uVar7;
    uint32_t  local_8;
    uint32_t  local_c;
    int32_t   local_18;
    int32_t*  local_14;
    int32_t*  local_10;
    int32_t   local_38[4];
    int32_t   local_28[4];

    puVar1 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(at<uint32_t>(self, 0x100)));
    local_8 = puVar1[3];
    piVar2 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(puVar1[2]));
    local_14 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(puVar1[4]));
    uVar6 = *puVar1 & 0xfffff;
    piVar9 = piVar2 + uVar6;
    {
        const uint32_t tableBase = at<uint32_t>(self, 0x14);
        local_c = *reinterpret_cast<uint32_t*>(
            static_cast<std::uint8_t*>(pv(tableBase)) + *piVar2 * 4);
        const int32_t third = *reinterpret_cast<int32_t*>(
            static_cast<std::uint8_t*>(pv(tableBase)) + *local_14 * 4);
        local_18 = *reinterpret_cast<int32_t*>(
            static_cast<std::uint8_t*>(pv(tableBase)) + *piVar9 * 4);
        local_10 = piVar9;
        if (((at<int32_t>(pv(third), 4) == at<int32_t>(pv(local_c), 4)) &&
             (at<int32_t>(pv(third), 0xc) == at<int32_t>(pv(local_c), 0xc))) ||
            ((at<int32_t>(pv(third), 4) == at<int32_t>(pv(local_18), 4)) &&
             (at<int32_t>(pv(third), 0xc) == at<int32_t>(pv(local_18), 0xc)))) {
            int32_t iVar4 = reinterpret_cast<int32_t (*)(uint32_t, void*, uint32_t,
                                                         uint32_t, uint32_t)>(
                                vtbl_slot(self, 0x80))(
                at<uint32_t>(self, 0xfc), local_38, 4, 0, 0);
            if (iVar4 < 0) {
                return;
            }
            local_c = 0;
            if (local_8 != 0) {
                do {
                    uVar3 = local_c;
                    local_c = local_c + 1;
                    {
                        const uint32_t tbl = at<uint32_t>(self, 0x14);
                        const int32_t index = local_14[uVar3];
                        const int32_t entry = *reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(pv(tbl)) + index * 4);
                        local_28[uVar3] = local_38[at<int32_t>(pv(entry), 0x10)];
                    }
                } while (local_c < local_8);
            }
            FUN_006a4aab(2, local_28, local_8, piVar2, local_10, nullptr, uVar6, 0,
                         0x1000000, 0, 0);
            uVar7 = 0x58;
            piVar8 = local_28;
            piVar9 = piVar2;
            piVar10 = local_10;
        }
        else {
            piVar10 = nullptr;
            uVar7 = 0xb;
            piVar8 = piVar2;
        }
        FUN_006a4aab(uVar7, local_14, local_8, piVar8, piVar9, piVar10, uVar6, 0,
                     0, 0, 0);
    }
}

// ---------------------------------------------------------------------------
// 0x67f68e — observed shape
// Same test as 0x67f558 but the second surface is probed at +uVar6 and the
// fallback descriptor mode is 0xa with a null fifth argument.
// ---------------------------------------------------------------------------
void FUN_0067f68e(void* self)
{
    uint32_t* puVar1;
    int32_t*  piVar2;
    int32_t*  piVar8;
    int32_t*  piVar9;
    uint32_t  uVar3;
    uint32_t  uVar6;
    uint32_t  uVar7;
    uint32_t  local_8;
    uint32_t  local_c;
    int32_t   local_18;
    int32_t*  local_14;
    int32_t*  local_10;
    int32_t   local_38[4];
    int32_t   local_28[4];

    puVar1 = reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(at<uint32_t>(self, 0x100)));
    local_8 = puVar1[3];
    piVar2 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(puVar1[2]));
    local_14 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(puVar1[4]));
    uVar6 = *puVar1 & 0xfffff;
    local_10 = piVar2 + uVar6;
    {
        const uint32_t tableBase = at<uint32_t>(self, 0x14);
        local_c = *reinterpret_cast<uint32_t*>(
            static_cast<std::uint8_t*>(pv(tableBase)) + *piVar2 * 4);
        const int32_t third = *reinterpret_cast<int32_t*>(
            static_cast<std::uint8_t*>(pv(tableBase)) + *local_14 * 4);
        local_18 = *reinterpret_cast<int32_t*>(
            static_cast<std::uint8_t*>(pv(tableBase)) + *local_10 * 4);
        if (((at<int32_t>(pv(third), 4) == at<int32_t>(pv(local_c), 4)) &&
             (at<int32_t>(pv(third), 0xc) == at<int32_t>(pv(local_c), 0xc))) ||
            ((at<int32_t>(pv(third), 4) == at<int32_t>(pv(local_18), 4)) &&
             (at<int32_t>(pv(third), 0xc) == at<int32_t>(pv(local_18), 0xc)))) {
            int32_t iVar4 = reinterpret_cast<int32_t (*)(uint32_t, void*, uint32_t,
                                                         uint32_t, uint32_t)>(
                                vtbl_slot(self, 0x80))(
                at<uint32_t>(self, 0xfc), local_38, 4, 0, 0);
            if (iVar4 < 0) {
                return;
            }
            local_c = 0;
            if (local_8 != 0) {
                do {
                    uVar3 = local_c;
                    local_c = local_c + 1;
                    {
                        const uint32_t tbl = at<uint32_t>(self, 0x14);
                        const int32_t index = local_14[uVar3];
                        const int32_t entry = *reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(pv(tbl)) + index * 4);
                        local_28[uVar3] = local_38[at<int32_t>(pv(entry), 0x10)];
                    }
                } while (local_c < local_8);
            }
            FUN_006a4aab(2, local_28, local_8, piVar2, local_10, nullptr, uVar6, 0,
                         0x1000000, 0, 0);
            uVar7 = 0x58;
            piVar8 = local_28;
            piVar9 = piVar2;
        }
        else {
            piVar9 = nullptr;
            uVar7 = 10;
            piVar8 = piVar2;
        }
        FUN_006a4aab(uVar7, local_14, local_8, piVar8, local_10, piVar9, uVar6, 0,
                     0, 0, 0);
    }
}

// ---------------------------------------------------------------------------
// 0x67f7c4 — observed shape
// Register one object with the resource layer: build the class mask from the
// receiver's occupancy counters, optionally map the object's four surface
// indices through the receiver's vtable slot 0x70, then call slot 0x64 with
// the packed descriptor and finally name the resource through the CRT.
// ---------------------------------------------------------------------------
int32_t FUN_0067f7c4(void* self, uint8_t* param_1, uint32_t* param_2)
{
    char      local_34[0x20];      // provider declares a 16-byte slot; write is bounded at 0x20
    uint32_t  local_24[5];
    int32_t   local_10;
    uint32_t  local_c;
    uint32_t  local_8;
    int32_t   iVar3;
    int32_t   iVar6;
    int32_t   iVar11;
    int32_t*  piVar9;
    uint32_t  uVar4;
    uint32_t  uVar8;
    uint32_t  uVar10 = 0;
    char      cVar2;
    char*     pcVar1;
    char*     pcVar7;

    auto getKind = reinterpret_cast<int32_t (*)(uint32_t)>(vtbl_slot(self, 0x54));
    auto getIndex = reinterpret_cast<uint32_t (*)(uint32_t)>(vtbl_slot(self, 0x58));
    const int32_t kind = getKind(at<uint32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 0x6c));
    uVar4 = getIndex(at<uint32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 0x6c));
    local_24[4] = uVar4;
    if (at<int32_t>(self, 0x158) == 0) {
        uint32_t flags = 0;
        if (kind == 0xb) {
            if (static_cast<uint32_t>(at<int32_t>(self, 0x28)) <= uVar4) {
                return -0x7fffbffb;
            }
            *param_2 = uVar4;
            uVar8 = static_cast<uint32_t>(at<int32_t>(self, 0x218 + uVar4 * 4));
            local_8 = 1;
        }
        else {
            if (kind != 6) {
                return -0x7fffbffb;
            }
            if (7 < uVar4) {
                return -0x7fffbffb;
            }
            *param_2 = uVar4 + 2;
            uVar8 = static_cast<uint32_t>(at<int32_t>(self, 0x1f8 + uVar4 * 4));
            local_8 = 3;
        }
        if (uVar8 != 0) {
            do {
                if (uVar10 == 0) {
                    flags = flags | 0x10000;
                }
                else if (uVar10 == 1) {
                    flags = flags | 0x20000;
                }
                else if (uVar10 == 2) {
                    flags = flags | 0x40000;
                }
                else if (uVar10 == 3) {
                    flags = flags | 0x80000;
                }
                uVar10 = uVar10 + 1;
            } while (uVar10 < uVar8);
        }
        if ((local_8 != 1) &&
            (((at<uint8_t>(self, 0xcc) & 0x20) != 0) ||
             ((kind == 6) &&
              ((at<uint8_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 3) & 2) != 0)))) {
            flags = flags | 0x200000;
        }
        local_c = 0;
        if ((at<uint8_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 3) & 1) != 0) {
            local_c = 0x400000;
        }
        iVar6 = FUN_006a48dd(0x200001f);
        if (iVar6 < 0) {
            return iVar6;
        }
        iVar6 = FUN_006a2b66(0x80000000);
        if (iVar6 < 0) {
            return iVar6;
        }
        if ((at<uint8_t>(self, 0xcc) & 1) != 0) {
            int32_t  count = 0;
            uint32_t localIndex = 0;
            local_24[0] = 0xffffffff;
            local_24[1] = 0xffffffff;
            local_24[2] = 0xffffffff;
            local_24[3] = 0xffffffff;
            if (at<int32_t>(self, 8) != 0) {
                const int32_t shared = at<int32_t>(
                    pv(reinterpret_cast<std::uintptr_t>(param_1)), 4);
                piVar9 = reinterpret_cast<int32_t*>(
                    static_cast<std::uintptr_t>(at<uint32_t>(self, 0x14)));
                do {
                    iVar3 = *piVar9;
                    if (((shared == at<int32_t>(pv(iVar3), 4)) &&
                         (at<int32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 8) ==
                          at<int32_t>(pv(iVar3), 8))) &&
                        (at<int32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 0xc) ==
                         at<int32_t>(pv(iVar3), 0xc))) {
                        local_24[at<int32_t>(pv(iVar3), 0x10)] = localIndex;
                    }
                    localIndex = localIndex + 1;
                    piVar9 = piVar9 + 1;
                } while (localIndex < static_cast<uint32_t>(at<int32_t>(self, 8)));
            }
            uVar4 = 0;
            iVar11 = count;
            do {
                if (local_24[uVar4] != 0xffffffff) {
                    local_24[iVar11] = local_24[uVar4];
                    iVar11 = iVar11 + 1;
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < 4);
            iVar11 = reinterpret_cast<int32_t (*)(void*, int32_t, void*, uint32_t)>(
                        vtbl_slot(self, 0x70))(local_24, iVar11, &param_1, 1);
            if (iVar11 < 0) {
                return iVar11;
            }
            uVar4 = local_24[4];
        }
        iVar11 = reinterpret_cast<int32_t (*)(uint32_t, uint32_t, uint32_t)>(
                    vtbl_slot(self, 0x64))(
            (static_cast<uint32_t>(
                 ((local_8 | 0xfffffff8u) << 0x14) | (local_8 & 0x18)) << 8) |
                (uVar4 & 0x7ff) | local_c,
            flags, 0);
        if (iVar11 < 0) {
            return iVar11;
        }
        iVar11 = FUN_0069fcf5();
        if (iVar11 < 0) {
            return iVar11;
        }
    }
    else if (at<int32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 0x6c) != -1) {
        if (kind != 0xffff) {
            uint32_t* puVar5 = FUN_006a3cac(kind);
            _snprintf(local_34, 0x20, "v_%s%d",
                      reinterpret_cast<char*>(static_cast<std::uintptr_t>(*puVar5)), uVar4);
            local_24[3] = local_24[3] & 0xffffff;
            iVar6 = FUN_0061273f(
                local_34, at<uint32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 0xc), 1);
            if (iVar6 < 0) {
                return iVar6;
            }
            at<int32_t>(self, 0x1f0) = at<int32_t>(self, 0x1f0) + 1;
            if (((at<uint8_t>(self, 0xcc) & 1) != 0) &&
                (iVar6 = at<int32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 0x60),
                 iVar6 != 0) &&
                ((at<int32_t>(pv(iVar6), 4) == 6 &&
                  (iVar6 = at<int32_t>(pv(iVar6), 0x14), at<int32_t>(pv(iVar6), 4) == 3)))) {
                pcVar7 = reinterpret_cast<char*>(static_cast<std::uintptr_t>(
                    at<uint32_t>(pv(iVar6), 0x18)));
                pcVar1 = pcVar7 + 1;
                do {
                    cVar2 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                } while (cVar2 != '\0');
                {
                    char* nameBuf = reinterpret_cast<char*>(static_cast<std::uintptr_t>(
                        static_cast<uint32_t>(FUN_00533c78(
                            static_cast<int32_t>(pcVar7 + (3 - pcVar1))))));
                    if (nameBuf == nullptr) {
                        return -0x7ff8fff2;
                    }
                    sprintf(nameBuf, "n_%s",
                            reinterpret_cast<char*>(static_cast<std::uintptr_t>(
                                at<uint32_t>(pv(iVar6), 0x18))));
                    iVar6 = FUN_0061273f(
                        nameBuf,
                        at<uint32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 0xc), 1);
                    operator_delete(nameBuf);
                    if (iVar6 < 0) {
                        return iVar6;
                    }
                    at<int32_t>(self, 0x1f0) = at<int32_t>(self, 0x1f0) + 1;
                }
            }
        }
        if (param_2 != nullptr) {
            *param_2 = at<uint32_t>(pv(reinterpret_cast<std::uintptr_t>(param_1)), 0x6c);
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x67faa4 — observed shape
// Validate the object's class/index pair against the receiver's counter:
// class 0xb uses the 10-entry range, class 6 the 8-entry range, 0xffff is
// unconstrained; anything else is E_FAIL.
// ---------------------------------------------------------------------------
uint32_t FUN_0067faa4(void* self, int32_t param_1, uint32_t* param_2,
                      uint32_t* param_3)
{
    auto getKind = reinterpret_cast<int32_t (*)(uint32_t)>(vtbl_slot(self, 0x54));
    auto getIndex = reinterpret_cast<uint32_t (*)(uint32_t)>(vtbl_slot(self, 0x58));
    const std::uintptr_t obj = static_cast<std::uintptr_t>(param_1);
    const int32_t iVar1 = getKind(at<uint32_t>(pv(obj), 0x6c));
    const uint32_t uVar2 = getIndex(at<uint32_t>(pv(obj), 0x6c));
    *param_2 = uVar2;
    if (iVar1 == 0xb) {
        if (static_cast<uint32_t>(at<int32_t>(self, 0x28)) <= uVar2) {
            return 0x80004005;
        }
        *param_3 = 1;
    }
    else if (iVar1 == 6) {
        if (7 < uVar2) {
            return 0x80004005;
        }
        *param_3 = 3;
    }
    else {
        if (iVar1 != 0xffff) {
            return 0x80004005;
        }
        *param_3 = 0;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x67fb12 — observed shape
// Same class/index validation with the 4-entry class-0xb range and the
// class-0xd single index, reporting whether the "unconstrained" class was
// taken through the optional out parameter.
// ---------------------------------------------------------------------------
uint32_t FUN_0067fb12(void* self, int32_t param_1, uint32_t* param_2,
                      uint32_t* param_3, uint32_t* param_4)
{
    uint32_t local_8 = 1;
    auto getKind = reinterpret_cast<int32_t (*)(uint32_t)>(vtbl_slot(self, 0x54));
    auto getIndex = reinterpret_cast<uint32_t (*)(uint32_t)>(vtbl_slot(self, 0x58));
    const std::uintptr_t obj = static_cast<std::uintptr_t>(param_1);
    const int32_t iVar1 = getKind(at<uint32_t>(pv(obj), 0x6c));
    const uint32_t uVar2 = getIndex(at<uint32_t>(pv(obj), 0x6c));
    *param_2 = uVar2;
    if (iVar1 == 0xb) {
        if (3 < uVar2) {
            return 0x80004005;
        }
        *param_3 = 8;
    }
    else if (iVar1 == 0xd) {
        if (uVar2 != 0) {
            return 0x80004005;
        }
        *param_3 = 9;
    }
    else {
        if (iVar1 != 0xffff) {
            return 0x80004005;
        }
        *param_3 = 0;
        local_8 = 0;
    }
    if (param_4 != nullptr) {
        *param_4 = local_8;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x67fb97 — observed shape
// Compare a four-entry surface-index pattern against the 128-entry signature
// table, treating -1 in the probe as a wildcard; report 1 on a table match.
// ---------------------------------------------------------------------------
uint32_t FUN_0067fb97(const void* param_1, const void* param_2)
{
    const int32_t* probe = static_cast<const int32_t*>(param_1);
    const int32_t* keys = static_cast<const int32_t*>(param_2);
    const int32_t* table = DAT_007205b8;
    uint32_t offset = 0;

    for (;;) {
        bool match = true;
        for (int32_t i = 0; i < 4; ++i) {
            if ((probe[i] != table[i]) && (keys[i] != -1)) {
                match = false;
            }
        }
        if (match) {
            break;
        }
        offset = offset + 0x10;
        if (0x7f < offset) {
            return 0;
        }
        table = table + 4;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x67fbed — observed shape
// Materialise one surface group from the receiver descriptor: look for an
// existing entry with the same shared-type pair, otherwise allocate and fill
// a four-slot surface set, then rewrite the group's indices.
// ---------------------------------------------------------------------------
int32_t FUN_0067fbed(void* self, int32_t* param_1, uint32_t param_2,
                     uint32_t param_3)
{
    int32_t   iVar1;
    int32_t   iVar3;
    int32_t*  piVar2;
    uint32_t  uVar4 = 0;
    uint32_t  uVar5;
    bool      bVar6 = param_3 == 0;
    int32_t   local_30[4];
    int32_t   local_20[5];
    int32_t   local_c;
    int32_t   local_8;
    const uint32_t descriptor = at<uint32_t>(self, 0x100);

    if (param_3 != 0) {
        local_c = at<int32_t>(pv(descriptor), 8);
        const int32_t* second = reinterpret_cast<const int32_t*>(static_cast<std::uintptr_t>(
            at<uint32_t>(pv(descriptor), 0x10)));
        local_20[4] = second[0];
        local_8 = 0;
        do {
            const uint32_t tableBase = at<uint32_t>(self, 0x14);
            const int32_t firstIdx = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(local_c)) + local_8);
            const int32_t firstObj = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(tableBase)) + firstIdx * 4);
            const int32_t secondObj = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(tableBase)) + second[0] * 4);
            if ((local_20[4] == at<int32_t>(pv(firstObj), 4)) &&
                (at<int32_t>(pv(secondObj), 0xc) == at<int32_t>(pv(firstObj), 0xc))) {
                break;
            }
            local_8 = local_8 + static_cast<int32_t>(param_2) * 4;
            uVar4 = uVar4 + 1;
        } while (uVar4 < param_3);
        bVar6 = uVar4 == param_3;
    }
    if (!bVar6) {
        iVar1 = local_c + static_cast<int32_t>(uVar4 * param_2 * 4);
        local_20[0] = -1;
        local_20[1] = 0xffffffff;
        local_20[2] = 0xffffffff;
        uVar4 = 0;
        uVar5 = 0;
        local_20[3] = 0xffffffff;
        if (param_2 != 0) {
            do {
                iVar3 = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(iVar1)) + uVar4 * 4);
                uVar4 = uVar4 + 1;
                iVar3 = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) + iVar3 * 4);
                local_20[at<int32_t>(pv(iVar3), 0x10)] = iVar3;
            } while (uVar4 < param_2);
        }
        uVar4 = 0;
        do {
            uVar5 = uVar5 + static_cast<uint32_t>(local_20[uVar4] != -1);
            uVar4 = uVar4 + 1;
        } while (uVar4 < 4);
        iVar3 = reinterpret_cast<int32_t (*)(uint32_t, void*, uint32_t, uint32_t,
                                             uint32_t)>(vtbl_slot(self, 0x80))(
            at<uint32_t>(self, 0xfc), local_30, 4, 0, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = static_cast<int32_t>(FUN_0065d0b4(0x74));
        if (iVar3 == 0) {
            iVar3 = 0;
        }
        else {
            iVar3 = static_cast<int32_t>(FUN_0065cc1a());
        }
        *param_1 = iVar3;
        if (iVar3 == 0) {
            return -0x7ff8fff2;
        }
        iVar3 = FUN_0065d0ff((uVar5 & 0xfffff) | 0x10000000, uVar5, uVar5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = FUN_0065cc50(at<uint32_t>(self, 0x100));
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = 0;
        uVar4 = 0;
        do {
            if (*reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(static_cast<void*>(local_20)) + uVar4) != -1) {
                const int32_t outObj = *param_1;
                const int32_t base10 = at<int32_t>(pv(outObj), 0x10);
                const int32_t base8 = at<int32_t>(pv(outObj), 8);
                *reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(pv(base10)) + iVar3) =
                    *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(static_cast<void*>(local_30)) + uVar4);
                *reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(pv(base8)) + iVar3) =
                    *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(static_cast<void*>(local_20)) + uVar4);
                iVar3 = iVar3 + 4;
            }
            uVar4 = uVar4 + 4;
        } while (uVar4 < 0x10);
        uVar4 = 0;
        if (param_2 != 0) {
            do {
                piVar2 = reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(iVar1)) + uVar4 * 4);
                uVar4 = uVar4 + 1;
                {
                    const int32_t obj = *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) +
                        *piVar2 * 4);
                    *piVar2 = local_30[at<int32_t>(pv(obj), 0x10)];
                }
            } while (uVar4 < param_2);
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x67fd95 — observed shape
// Create a surface group for the receiver's current shared type: size it one
// past the highest observed +0xc index, add the four class indices, and lift
// the group's own indices into the receiver's active object.
// ---------------------------------------------------------------------------
int32_t* FUN_0067fd95(void* self, int32_t* param_1, uint32_t param_2)
{
    int32_t*  piVar1 = param_1;
    int32_t*  piVar3;
    int32_t   iVar2 = 0;
    int32_t   iVar5;
    uint32_t  uVar4 = 0;
    uint32_t  uVar6;
    int32_t   aiStack_14[4];

    iVar5 = at<int32_t>(self, 8);
    if (iVar5 != 0) {
        piVar3 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(at<uint32_t>(self, 0x14)));
        do {
            if ((at<int32_t>(self, 0x88) == at<int32_t>(pv(*piVar3), 4)) &&
                (uVar6 = at<uint32_t>(pv(*piVar3), 0xc), uVar4 <= uVar6)) {
                uVar4 = uVar6 + 1;
            }
            piVar3 = piVar3 + 1;
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
    }
    uVar6 = 0;
    do {
        iVar5 = static_cast<int32_t>(FUN_0065d9d5(at<uint32_t>(self, 0x88), uVar4, uVar6, 0.0));
        aiStack_14[uVar6] = iVar5;
        if (iVar5 == -1) goto LAB_0067fe13;
        uVar6 = uVar6 + 1;
    } while (uVar6 < 4);
    iVar5 = static_cast<int32_t>(FUN_0065d0b4());
    if (iVar5 == 0) {
        iVar5 = 0;
    }
    else {
        iVar5 = static_cast<int32_t>(FUN_0065cc1a());
    }
    *param_1 = iVar5;
    if (iVar5 == 0) {
LAB_0067fe13:
        param_1 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(0x8007000e));
    }
    else {
        iVar2 = FUN_0065d0ff((param_2 & 0xfffff) | 0x10000000, param_2, param_2, 0);
        iVar5 = *param_1;
        if (-1 < iVar2) {
            iVar2 = FUN_0065cc50();
            if (-1 < iVar2) {
                uint32_t index = 0;
                while (index < param_2) {
                    const int32_t obj = *piVar1;
                    const int32_t base8 = at<int32_t>(pv(obj), 8);
                    const int32_t base10 = at<int32_t>(pv(obj), 0x10);
                    const int32_t current = at<int32_t>(self, 0x100);
                    const int32_t currentBase10 = at<int32_t>(pv(current), 0x10);
                    *reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(pv(base8)) +
                                                index * 4) = aiStack_14[index];
                    *reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(pv(base10)) +
                                                index * 4) =
                        *reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(
                                                        pv(currentBase10)) +
                                                    index * 4);
                    *reinterpret_cast<int32_t*>(static_cast<std::uint8_t*>(pv(currentBase10)) +
                                                index * 4) = aiStack_14[index];
                    index = index + 1;
                }
                return reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(0));
            }
            iVar5 = *param_1;
        }
        param_1 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(iVar2));
        if (iVar5 != 0) {
            FUN_00614343();
        }
    }
    return param_1;
}

// ---------------------------------------------------------------------------
// 0x67feb4 — observed shape
// Retire/realise one receiver descriptor: decompose the stored index grid,
// rebuild the surface groups from the recorded patterns (4x4, 3x3, 2x2 and
// the single-row fallback), and copy the packed result back when the
// descriptor carries the 0x10d/0x10e header.
// ---------------------------------------------------------------------------
int32_t FUN_0067feb4(void* self)
{
    int32_t   local_d4[16];
    int32_t   local_94[4];
    uint32_t  local_84[9];
    uint32_t  uStack_60 = 0;
    uint32_t  uStack_5c = 0;
    uint32_t  uStack_58 = 0;
    uint32_t  local_54[9];
    int32_t   local_30 = 0;
    int32_t   local_28 = 0;
    int32_t*  local_2c = nullptr;
    int32_t*  local_1c = nullptr;
    int32_t*  local_18 = nullptr;
    int32_t*  local_14 = nullptr;
    int32_t*  local_8 = nullptr;
    int32_t*  local_20 = nullptr;
    int32_t   local_24 = 0;
    int32_t*  piVar5;
    int32_t*  piVar8;
    int32_t*  piVar9;
    int32_t*  piVar13;
    uint32_t* puVar3;
    uint32_t* puVar6;
    uint32_t* puVar10;
    uint32_t* puVar12;
    int32_t   iVar1;
    int32_t   iVar2;
    int32_t   iVar4 = 0;
    int32_t   iVar5;
    int32_t   iVar6;
    int32_t   iVar8;
    uint32_t  uVar4;
    uint32_t  uVar7;
    uint32_t  uVar9;
    uint32_t  uVar11;
    uint32_t  uVar16;
    bool      bVar14;

    const std::uint32_t descriptorValue = at<uint32_t>(self, 0x100);
    uint32_t* const desc =
        reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(descriptorValue));

    local_14 = reinterpret_cast<int32_t*>(*desc & 0xfff00000u);
    if (local_14 == nullptr) {
        return 0;
    }
    uVar7 = *desc;
    uVar11 = desc[1];
    const int32_t cols = static_cast<int32_t>(uVar7 & 0xfffff);
    const int32_t rows = static_cast<int32_t>(uVar11 / static_cast<uint32_t>(cols));
    local_54[8] = uVar11 % static_cast<uint32_t>(cols);
    local_24 = cols;
    {
        const uint32_t typeMask = uVar7 & 0xfff00000u;
        bVar14 = (typeMask == 0x50000000) || (typeMask == 0x50200000) ||
                 (typeMask == 0x70800000);
        local_8 = nullptr;
        if ((typeMask == 0x60500000) || (typeMask == 0x60a00000) ||
            (typeMask == 0x60f00000) || (typeMask == 0x11000000)) {
            iVar4 = FUN_0065db2e();
            if (iVar4 < 0) {
                return iVar4;
            }
            desc[0] = 0;
            goto LAB_00680ab8;
        }
    }
    if (bVar14) {
        const uint32_t typeMask = *desc & 0xfff00000u;
        if ((typeMask == 0x50200000) || (typeMask == 0x70800000)) {
            iVar4 = FUN_0065db2e();
            if (iVar4 < 0) {
                return iVar4;
            }
            desc[0] = 0;
            return iVar4;
        }
        {
            const int32_t firstSlot = *reinterpret_cast<int32_t*>(
                static_cast<std::uintptr_t>(desc[4]));
            const int32_t firstObj = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) + firstSlot * 4);
            if (at<int32_t>(pv(firstObj), 4) == at<int32_t>(self, 0x84)) {
                FUN_006626da();
                return -0x7fffbffb;
            }
        }
        {
            int32_t rowIndex = 0;
            if (rows != 0) {
                intptr_t rowByteOffset = 0;
                local_2c = nullptr;
                local_8 = local_d4;
                local_14 = reinterpret_cast<int32_t*>(
                    static_cast<std::uintptr_t>(static_cast<uint32_t>(cols) << 2));
                do {
                    piVar8 = local_8;
                    piVar5 = local_8 + 1;
                    *local_8 = -1;
                    *piVar5 = -1;
                    piVar8[2] = -1;
                    piVar8[3] = -1;
                    if (cols != 0) {
                        piVar5 = reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(pv(desc[2])) + rowByteOffset);
                        int32_t remaining = cols;
                        do {
                            *piVar8 = at<int32_t>(pv(*reinterpret_cast<int32_t*>(piVar5)), 0x10);
                            piVar5 = piVar5 + 1;
                            piVar8 = piVar8 + 1;
                            remaining = remaining - 1;
                        } while (remaining != 0);
                    }
                    local_18 = nullptr;
                    puVar10 = reinterpret_cast<uint32_t*>(DAT_007205b8);
                    while ((iVar4 = FUN_00673e38(local_8, puVar10)) == 0) {
                        local_18 = local_18 + 4;
                        puVar10 = puVar10 + 4;
                        if (reinterpret_cast<int32_t*>(0x7f) < local_18) {
                            if ((at<uint8_t>(self, 0x6c) & 2) == 0) {
                                goto LAB_00680870;
                            }
                            iVar4 = FUN_0067fbed(&local_28, static_cast<uint32_t>(cols),
                                                 static_cast<uint32_t>(rows));
                            if (iVar4 < 0) {
                                goto LAB_00680ac8;
                            }
                            if (local_28 != 0) {
                                iVar4 = FUN_0065d8c2();
                                if (iVar4 < 0) {
                                    goto LAB_00680ac8;
                                }
                                local_28 = 0;
                            }
                            iVar6 = (FUN_0065d0b4() == 0)
                                        ? 0
                                        : static_cast<int32_t>(FUN_0065cc1a());
                            if (iVar6 != 0) {
                                local_8 = nullptr;
                                if (at<int32_t>(self, 8) != 0) {
                                    piVar9 = reinterpret_cast<int32_t*>(
                                        static_cast<std::uintptr_t>(at<uint32_t>(self, 0x14)));
                                    int32_t objectCount = at<int32_t>(self, 8);
                                    do {
                                        const int32_t typeIndex = at<int32_t>(pv(*piVar9), 4);
                                        const int32_t typeEntry = *reinterpret_cast<int32_t*>(
                                            static_cast<std::uint8_t*>(
                                                pv(at<uint32_t>(self, 0x10))) +
                                            typeIndex * 4);
                                        uVar7 = at<uint32_t>(pv(typeEntry), 4);
                                        if (((uVar7 & 1) != 0) && ((uVar7 & 2) != 0)) {
                                            const int32_t candidate =
                                                at<int32_t>(pv(*piVar9), 0xc) + 1;
                                            if (static_cast<int32_t>(
                                                    reinterpret_cast<std::uintptr_t>(
                                                        local_8)) < candidate) {
                                                local_8 = reinterpret_cast<int32_t*>(
                                                    static_cast<std::uintptr_t>(candidate));
                                            }
                                        }
                                        piVar9 = piVar9 + 1;
                                        objectCount = objectCount - 1;
                                    } while (objectCount != 0);
                                }
                                iVar4 = FUN_0065d0ff(0x20500001, 2, 1, 0);
                                if ((iVar4 < 0) ||
                                    (iVar4 = FUN_0065cc50(), iVar4 < 0)) {
                                    goto LAB_00680ac8;
                                }
                                local_20 = reinterpret_cast<int32_t*>(
                                    static_cast<std::uintptr_t>(static_cast<uint32_t>(
                                        FUN_0065d9d5(at<uint32_t>(self, 0x88),
                                                     static_cast<uint32_t>(
                                                         reinterpret_cast<std::uintptr_t>(
                                                             local_8)),
                                                     0, 0.0))));
                                local_8 = reinterpret_cast<int32_t*>(
                                    reinterpret_cast<std::uintptr_t>(local_8) + 1);
                                if (local_20 != reinterpret_cast<int32_t*>(0xffffffff)) {
                                    *reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(
                                        at<int32_t>(pv(iVar6), 0x10))) =
                                        static_cast<uint32_t>(
                                            reinterpret_cast<std::uintptr_t>(local_20));
                                    *reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(
                                        at<int32_t>(pv(iVar6), 8))) =
                                        *reinterpret_cast<uint32_t*>(
                                            static_cast<std::uintptr_t>(desc[2]));
                                    *reinterpret_cast<uint32_t*>(
                                        static_cast<std::uint8_t*>(
                                            pv(at<int32_t>(pv(iVar6), 8))) + 4) =
                                        *reinterpret_cast<uint32_t*>(
                                            static_cast<std::uint8_t*>(pv(desc[2])) +
                                            reinterpret_cast<std::uintptr_t>(local_14));
                                    iVar4 = FUN_0065d8c2();
                                    if (iVar4 < 0) {
                                        goto LAB_00680ac8;
                                    }
                                    int32_t surfaceIndex = 1;
                                    if (surfaceIndex < cols) {
                                        local_14 = local_14 + 1;
                                        do {
                                            iVar6 = (FUN_0065d0b4() == 0)
                                                        ? 0
                                                        : static_cast<int32_t>(FUN_0065cc1a());
                                            if (iVar6 == 0) {
                                                goto LAB_00680a3e;
                                            }
                                            iVar4 = FUN_0065d0ff(0x70300001, 3, 1, 0);
                                            if ((iVar4 < 0) ||
                                                (iVar4 = FUN_0065cc50(), iVar4 < 0)) {
                                                goto LAB_00680ac8;
                                            }
                                            *reinterpret_cast<uint32_t*>(
                                                static_cast<std::uintptr_t>(
                                                    at<int32_t>(pv(iVar6), 8))) =
                                                *reinterpret_cast<uint32_t*>(
                                                    static_cast<std::uint8_t*>(pv(desc[2])) +
                                                    surfaceIndex * 4);
                                            *reinterpret_cast<uint32_t*>(
                                                static_cast<std::uint8_t*>(
                                                    pv(at<int32_t>(pv(iVar6), 8))) + 4) =
                                                *reinterpret_cast<uint32_t*>(
                                                    static_cast<std::uint8_t*>(pv(desc[2])) +
                                                    reinterpret_cast<std::uintptr_t>(local_14));
                                            *reinterpret_cast<int32_t*>(
                                                static_cast<std::uint8_t*>(
                                                    pv(at<int32_t>(pv(iVar6), 8))) + 8) =
                                                static_cast<int32_t>(
                                                    reinterpret_cast<std::uintptr_t>(local_20));
                                            if (surfaceIndex == cols - 1) {
                                                piVar9 = reinterpret_cast<int32_t*>(
                                                    static_cast<std::uintptr_t>(
                                                        *reinterpret_cast<int32_t*>(
                                                            static_cast<std::uintptr_t>(
                                                                desc[4]))));
                                            }
                                            else {
                                                piVar9 = reinterpret_cast<int32_t*>(
                                                    static_cast<std::uintptr_t>(
                                                        static_cast<uint32_t>(FUN_0065d9d5(
                                                            at<uint32_t>(self, 0x88),
                                                            static_cast<uint32_t>(
                                                                reinterpret_cast<std::uintptr_t>(
                                                                    local_8)),
                                                            0, 0.0))));
                                                local_8 = reinterpret_cast<int32_t*>(
                                                    reinterpret_cast<std::uintptr_t>(local_8) +
                                                    1);
                                                local_20 = piVar9;
                                                if (piVar9 ==
                                                    reinterpret_cast<int32_t*>(0xffffffff)) {
                                                    goto LAB_00680a3e;
                                                }
                                            }
                                            *reinterpret_cast<int32_t*>(
                                                static_cast<std::uintptr_t>(
                                                    at<int32_t>(pv(iVar6), 0x10))) =
                                                static_cast<int32_t>(
                                                    reinterpret_cast<std::uintptr_t>(piVar9));
                                            iVar4 = FUN_0065d8c2();
                                            if (iVar4 < 0) {
                                                goto LAB_00680ac8;
                                            }
                                            surfaceIndex = surfaceIndex + 1;
                                            local_14 = local_14 + 1;
                                        } while (surfaceIndex < cols);
                                    }
                                    goto LAB_00680887;
                                }
                            }
                        LAB_00680a3e:
                            iVar4 = -0x7ff8fff2;
                            goto LAB_00680ac8;
                        }
                    }
                    rowIndex = rowIndex + 1;
                    local_2c = local_2c + 4;
                    local_8 = local_8 + 4;
                    rowByteOffset = rowByteOffset +
                                    static_cast<intptr_t>(
                                        reinterpret_cast<std::uintptr_t>(local_14));
                } while (rowIndex < rows);
            }
        }
    LAB_00680870:
        iVar4 = FUN_0065db2e();
        if (iVar4 < 0) {
            return iVar4;
        }
    }
    else {
        int32_t rowIndex = 0;
        if (rows != 0) {
            intptr_t rowByteOffset = 0;
            local_18 = nullptr;
            local_2c = local_d4;
            do {
                piVar5 = local_2c;
                bVar14 = cols != 0;
                piVar9 = local_2c + 1;
                *local_2c = -1;
                *piVar9 = -1;
                piVar5[2] = -1;
                piVar5[3] = -1;
                if (bVar14) {
                    local_1c = reinterpret_cast<int32_t*>(
                        static_cast<std::uintptr_t>(desc[4]));
                    const int32_t tableBase = at<int32_t>(self, 0x14);
                    const int32_t rowSlotBase = rowIndex * 4;
                    piVar9 = reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(desc[2])) + rowByteOffset);
                    int32_t remaining = cols;
                    do {
                        iVar1 = *local_1c;
                        iVar2 = *piVar9;
                        local_1c = local_1c + 1;
                        piVar9 = piVar9 + 1;
                        remaining = remaining - 1;
                        {
                            const int32_t left = *reinterpret_cast<int32_t*>(
                                static_cast<std::uint8_t*>(pv(tableBase)) + iVar1 * 4);
                            const int32_t right = *reinterpret_cast<int32_t*>(
                                static_cast<std::uint8_t*>(pv(tableBase)) + iVar2 * 4);
                            local_d4[at<int32_t>(pv(left), 0x10) + rowSlotBase] =
                                at<int32_t>(pv(right), 0x10);
                        }
                    } while (remaining != 0);
                }
                rowIndex = rowIndex + 1;
                local_2c = local_2c + 4;
                rowByteOffset = rowByteOffset + static_cast<intptr_t>(cols) * 4;
            } while (rowIndex < rows);
        }
        {
            const int32_t firstSlot = *reinterpret_cast<int32_t*>(
                static_cast<std::uintptr_t>(desc[4]));
            const int32_t firstObj = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) + firstSlot * 4);
            const int32_t typeIndex = at<int32_t>(pv(firstObj), 4);
            const int32_t typeEntry = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x10))) + typeIndex * 4);
            if ((at<uint8_t>(pv(typeEntry), 4) & 0x20) == 0) {
                int32_t checked = 0;
                if (rows != 0) {
                    local_18 = local_d4;
                    do {
                        puVar10 = reinterpret_cast<uint32_t*>(DAT_007205b8);
                        uVar7 = 0;
                        while ((iVar4 = FUN_00673e38(local_18, puVar10)) == 0) {
                            uVar7 = uVar7 + 0x10;
                            puVar10 = puVar10 + 4;
                            if (0x7f < uVar7) {
                                local_8 = reinterpret_cast<int32_t*>(1);
                                goto LAB_00680186;
                            }
                        }
                        checked = checked + 1;
                        local_18 = local_18 + 4;
                    } while (checked < rows);
                }
            }
            else {
                local_20 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(
                    *reinterpret_cast<int32_t*>(
                        static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) +
                        *reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(pv(desc[2]))) * 4)));
                const int32_t kind =
                    reinterpret_cast<int32_t (*)()>(vtbl_slot(self, 0x54))();
                if (kind != 0xffff) {
                    bool takeA9 = false;
                    if (kind == 0xb) {
                        piVar9 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(
                            static_cast<uint32_t>(
                                FUN_00673e38(local_d4, &DAT_007205b8[0x10]))));
                        local_8 = (piVar9 == nullptr)
                                      ? nullptr
                                      : reinterpret_cast<int32_t*>(1);
                        if (local_8 == nullptr) {
                            takeA9 = true;
                        }
                    }
                    else if (kind == 0xd) {
                        uVar7 = 0;
                        local_14 = nullptr;
                        puVar10 = reinterpret_cast<uint32_t*>(DAT_007205b8);
                        do {
                            iVar4 = FUN_00673e38(local_d4, puVar10);
                            if (iVar4 != 0) {
                                local_14 = reinterpret_cast<int32_t*>(1);
                                piVar9 = local_14;
                                break;
                            }
                            uVar7 = uVar7 + 0x10;
                            puVar10 = puVar10 + 4;
                            piVar9 = local_14;
                        } while (uVar7 < 0x40);
                        local_8 = (piVar9 == nullptr)
                                      ? nullptr
                                      : reinterpret_cast<int32_t*>(1);
                        if (local_8 == nullptr) {
                            takeA9 = true;
                        }
                    }
                    else {
                        takeA9 = true;
                    }
                    if ((!takeA9) ||
                        ((at<uint8_t>(pv(reinterpret_cast<std::uintptr_t>(local_20)), 0x3e) &
                          0x1f) != 0)) {
                        iVar4 = FUN_0067fd95(&local_30, static_cast<uint32_t>(local_24));
                        if (iVar4 < 0) {
                            goto LAB_00680ab8;
                        }
                    }
                    local_84[0] = 0;
                    local_84[1] = 0;
                    local_84[2] = 0;
                    local_84[3] = 0;
                    iVar4 = static_cast<int32_t>(FUN_0067fb97(local_d4, local_84));
                    if ((iVar4 != 0) ||
                        ((kind == 0xd) && (local_d4[0] == 0))) {
                        iVar4 = FUN_0069ec6d(local_84, static_cast<uint32_t>(rows),
                                             static_cast<uint32_t>(local_24));
                        if (-1 < iVar4) {
                            desc[0] = 0;
                            if (local_30 == 0) {
                                return iVar4;
                            }
                            iVar4 = FUN_0065d8c2();
                            if (-1 < iVar4) {
                                return iVar4;
                            }
                        }
                        goto LAB_00680ab8;
                    }
                }
            }
        }
    LAB_00680186:
        {
            uint32_t* head =
                reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(descriptorValue));
            if (((*head & 0xfff00000) == 0x10d00000) ||
                ((*head & 0xfff00000) == 0x10e00000)) {
                uVar7 = head[1];
                bVar14 = false;
                int32_t* table = reinterpret_cast<int32_t*>(
                    static_cast<std::uintptr_t>(at<uint32_t>(self, 0x14)));
                if (uVar7 != 0) {
                    piVar9 = table;
                    piVar5 = reinterpret_cast<int32_t*>(
                        static_cast<std::uintptr_t>(head[2]));
                    do {
                        if ((at<uint8_t>(pv(piVar9[*piVar5]), 0x3e) & 0x1f) != 0) {
                            bVar14 = true;
                        }
                        piVar5 = piVar5 + 1;
                        uVar7 = uVar7 - 1;
                    } while (uVar7 != 0);
                    if (bVar14) {
                        int32_t objectCount = at<int32_t>(self, 8);
                        uVar7 = 0;
                        piVar9 = table;
                        if (objectCount != 0) {
                            do {
                                if ((at<int32_t>(self, 0x88) ==
                                     at<int32_t>(pv(*piVar9), 4)) &&
                                    (uVar11 = at<uint32_t>(pv(*piVar9), 0xc),
                                     uVar7 <= uVar11)) {
                                    uVar7 = uVar11 + 1;
                                }
                                piVar9 = piVar9 + 1;
                                objectCount = objectCount - 1;
                            } while (objectCount != 0);
                        }
                        uVar11 = 0;
                        do {
                            iVar4 = static_cast<int32_t>(
                                FUN_0065d9d5(at<uint32_t>(self, 0x88), uVar7, uVar11, 0.0));
                            local_94[uVar11] = iVar4;
                            if (iVar4 == -1) goto LAB_0068025a;
                            uVar11 = uVar11 + 1;
                        } while (uVar11 < 4);
                        iVar4 = static_cast<int32_t>(FUN_0065d0b4());
                        local_28 = (iVar4 == 0)
                                       ? 0
                                       : static_cast<int32_t>(FUN_0065cc1a());
                        if (local_28 == 0) {
                        LAB_0068025a:
                            iVar4 = -0x7ff8fff2;
                            goto LAB_00680ab8;
                        }
                        uVar7 = head[1];
                        iVar4 = FUN_0065d0ff((uVar7 & 0xfffff) | 0x10000000, uVar7,
                                             head[3], 0);
                        if ((iVar4 < 0) ||
                            (iVar4 = FUN_0065cc50(), iVar4 < 0)) {
                            goto LAB_00680ab8;
                        }
                        {
                            int32_t* src = local_94;
                            int32_t* dst = reinterpret_cast<int32_t*>(
                                static_cast<std::uintptr_t>(
                                    at<int32_t>(pv(local_28), 0x10)));
                            for (uVar7 = head[3] & 0x3fffffff; uVar7 != 0;
                                 uVar7 = uVar7 - 1) {
                                *dst = *src;
                                src = src + 1;
                                dst = dst + 1;
                            }
                            for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                                *reinterpret_cast<char*>(dst) =
                                    static_cast<char>(*src);
                                src = reinterpret_cast<int32_t*>(
                                    reinterpret_cast<std::uint8_t*>(src) + 1);
                                dst = reinterpret_cast<int32_t*>(
                                    reinterpret_cast<std::uint8_t*>(dst) + 1);
                            }
                            puVar10 = reinterpret_cast<uint32_t*>(
                                static_cast<std::uintptr_t>(head[2]));
                            puVar12 = reinterpret_cast<uint32_t*>(
                                static_cast<std::uintptr_t>(
                                    at<int32_t>(pv(local_28), 8)));
                            for (uVar7 = head[1] & 0x3fffffff; uVar7 != 0;
                                 uVar7 = uVar7 - 1) {
                                *puVar12 = *puVar10;
                                puVar10 = puVar10 + 1;
                                puVar12 = puVar12 + 1;
                            }
                            for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                                *reinterpret_cast<uint8_t*>(puVar12) =
                                    *reinterpret_cast<uint8_t*>(puVar10);
                                puVar10 = reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<std::uint8_t*>(puVar10) + 1);
                                puVar12 = reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<std::uint8_t*>(puVar12) + 1);
                            }
                            src = local_94;
                            dst = reinterpret_cast<int32_t*>(
                                static_cast<std::uintptr_t>(head[2]));
                            for (uVar7 = head[1] & 0x3fffffff; uVar7 != 0;
                                 uVar7 = uVar7 - 1) {
                                *dst = *src;
                                src = src + 1;
                                dst = dst + 1;
                            }
                            for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                                *reinterpret_cast<char*>(dst) =
                                    static_cast<char>(*src);
                                src = reinterpret_cast<int32_t*>(
                                    reinterpret_cast<std::uint8_t*>(src) + 1);
                                dst = reinterpret_cast<int32_t*>(
                                    reinterpret_cast<std::uint8_t*>(dst) + 1);
                            }
                        }
                        iVar4 = FUN_0065d8c2();
                        if (iVar4 < 0) {
                            goto LAB_00680ab8;
                        }
                        local_28 = 0;
                    }
                }
            }
        }
        if ((local_8 == nullptr) || ((at<uint8_t>(self, 0x6c) & 2) == 0)) {
            iVar4 = FUN_0065db2e();
            if (iVar4 < 0) {
                goto LAB_00680ab8;
            }
        }
        else {
            bool runPerRow = false;
            local_8 = nullptr;
            local_20 = nullptr;
            if (local_24 == 4) {
                int32_t status = 1;
                uVar7 = 0;
                do {
                    if (status == 0) break;
                    local_84[0] = 0;
                    local_84[1] = 0;
                    local_84[2] = 0;
                    local_84[3] = 0;
                    local_84[4] = 0xffffffff;
                    local_84[5] = 0xffffffff;
                    local_84[6] = 0xffffffff;
                    local_84[7] = 0xffffffff;
                    local_84[uVar7] = 0xffffffff;
                    local_84[uVar7 + 4] = 0;
                    status = 0;
                    if (rows == 0) {
                    LAB_006803e7:
                        iVar4 = FUN_0069ec6d(local_84, static_cast<uint32_t>(rows), 4);
                        if ((iVar4 < 0) ||
                            (iVar4 = FUN_0069ec6d(local_84 + 4, static_cast<uint32_t>(rows),
                                                  4),
                             iVar4 < 0)) {
                            goto LAB_00680ab8;
                        }
                        goto LAB_006806ee;
                    }
                    piVar9 = local_d4;
                    {
                        int32_t remaining = rows;
                        do {
                            iVar4 = static_cast<int32_t>(FUN_0067fb97(piVar9, local_84));
                            if ((iVar4 == 0) ||
                                (iVar4 = static_cast<int32_t>(
                                     FUN_0067fb97(piVar9, local_84)),
                                 iVar4 == 0)) {
                                status = 1;
                            }
                            piVar9 = piVar9 + 4;
                            remaining = remaining - 1;
                        } while (remaining != 0);
                    }
                    local_14 = nullptr;
                    if (status == 0) goto LAB_006803e7;
                    uVar7 = uVar7 + 1;
                } while (uVar7 < 4);
                {
                    int32_t i = 0;
                    status = 1;
                    do {
                        if (status == 0) break;
                        int32_t j = 0;
                        do {
                            piVar5 = reinterpret_cast<int32_t*>(
                                static_cast<std::uintptr_t>(j));
                            piVar9 = reinterpret_cast<int32_t*>(
                                static_cast<std::uintptr_t>(i));
                            if (j != i) {
                                local_84[0] = 0;
                                local_84[1] = 0;
                                local_84[2] = 0;
                                local_84[3] = 0;
                                local_84[4] = 0xffffffff;
                                local_84[5] = 0xffffffff;
                                local_84[6] = 0xffffffff;
                                local_84[7] = 0xffffffff;
                                local_84[i] = 0xffffffff;
                                local_84[j] = 0xffffffff;
                                bVar14 = rows != 0;
                                local_84[i + 1] = 0;
                                local_84[j + 1] = 0;
                                status = 0;
                                local_2c = nullptr;
                                bool firstHit = false;
                                if (bVar14) {
                                    piVar9 = local_d4;
                                    int32_t remaining = rows;
                                    do {
                                        local_54[8] = static_cast<uint32_t>(
                                            FUN_0067fb97(piVar9, local_84));
                                        iVar4 = static_cast<int32_t>(
                                            FUN_0067fb97(piVar9, local_84 + 4));
                                        if (local_54[8] == 0) {
                                            local_2c = reinterpret_cast<int32_t*>(1);
                                            status = 1;
                                            firstHit = true;
                                        }
                                        else if (iVar4 == 0) {
                                            status = 1;
                                        }
                                        piVar9 = piVar9 + 4;
                                        remaining = remaining - 1;
                                    } while (remaining != 0);
                                    if (status != 0) {
                                        if (!firstHit) {
                                            local_84[8] = local_84[0];
                                            uStack_60 = local_84[1];
                                            uStack_5c = local_84[2];
                                            uStack_58 = local_84[3];
                                            local_54[0] = 0xffffffff;
                                            local_54[1] = 0xffffffff;
                                            local_54[2] = 0xffffffff;
                                            local_54[3] = 0xffffffff;
                                            local_54[4] = 0xffffffff;
                                            local_54[5] = 0xffffffff;
                                            local_54[6] = 0xffffffff;
                                            local_54[7] = 0xffffffff;
                                            local_54[i] = 0;
                                            local_54[j + 1] = 0;
                                            local_20 = reinterpret_cast<int32_t*>(1);
                                            piVar5 = reinterpret_cast<int32_t*>(
                                                static_cast<std::uintptr_t>(j));
                                        }
                                        goto LAB_006804ea;
                                    }
                                }
                                local_8 = reinterpret_cast<int32_t*>(1);
                                break;
                            }
                        LAB_006804ea:
                            j = static_cast<int32_t>(
                                    reinterpret_cast<std::uintptr_t>(piVar5)) + 1;
                        } while (j < 4);
                        i = static_cast<int32_t>(
                                reinterpret_cast<std::uintptr_t>(piVar9)) + 1;
                    } while (i < 4);
                }
                if (local_8 == nullptr) {
                    if (local_20 == nullptr) {
                        runPerRow = true;
                    }
                    else {
                        local_8 = reinterpret_cast<int32_t*>(1);
                        iVar4 = FUN_0069ec6d(local_84 + 8, static_cast<uint32_t>(rows), 4);
                        if ((iVar4 < 0) ||
                            (iVar4 = FUN_0069ec6d(local_54, static_cast<uint32_t>(rows),
                                                  4),
                             iVar4 < 0)) {
                            goto LAB_00680ab8;
                        }
                        uVar16 = 4;
                        iVar4 = FUN_0069ec6d(local_54 + 4, static_cast<uint32_t>(rows),
                                             uVar16);
                        if (iVar4 < 0) {
                            goto LAB_00680ab8;
                        }
                    }
                }
                else {
                    iVar4 = FUN_0069ec6d(local_84, static_cast<uint32_t>(rows), 4);
                    if (iVar4 < 0) {
                        goto LAB_00680ab8;
                    }
                    uVar16 = 4;
                    iVar4 = FUN_0069ec6d(local_84 + 4, static_cast<uint32_t>(rows),
                                         uVar16);
                    if (iVar4 < 0) {
                        goto LAB_00680ab8;
                    }
                }
            }
            else {
                bool havePattern = false;
                if (local_24 == 3) {
                    int32_t spare = -1;
                    local_20 = reinterpret_cast<int32_t*>(static_cast<std::uintptr_t>(
                        0xffffffffu));
                    for (int32_t k = 0; k < 4; ++k) {
                        if (local_d4[k] == -1) {
                            local_20 = reinterpret_cast<int32_t*>(
                                static_cast<std::uintptr_t>(k));
                        }
                    }
                    spare = static_cast<int32_t>(
                        reinterpret_cast<std::uintptr_t>(local_20));
                    int32_t i = 0;
                    int32_t status = 1;
                    do {
                        if (status == 0) break;
                        int32_t j = 0;
                        do {
                            int32_t savedI = i;
                            int32_t savedJ = j;
                            if (local_8 != nullptr) break;
                            if ((j != i) && (j != spare) && (i != spare)) {
                                local_84[0] = 0xffffffff;
                                local_84[1] = 0xffffffff;
                                local_84[2] = 0xffffffff;
                                local_84[3] = 0xffffffff;
                                local_84[4] = 0;
                                local_84[5] = 0;
                                local_84[6] = 0;
                                local_84[7] = 0;
                                local_84[savedI] = 0;
                                local_84[j] = 0;
                                local_84[savedI + 1] = 0xffffffff;
                                local_84[j + 1] = 0xffffffff;
                                local_84[spare + 1] = 0xffffffff;
                                status = 0;
                                bool matched = false;
                                {
                                    int32_t n = 0;
                                    local_18 = local_d4;
                                    do {
                                        if (status != 0) break;
                                        iVar4 = static_cast<int32_t>(
                                            FUN_0067fb97(local_18, local_84));
                                        if (iVar4 == 0) {
                                            status = 1;
                                            matched = true;
                                        }
                                        local_18 = local_18 + 4;
                                        n = n + 1;
                                    } while (n < rows);
                                    if (matched) {
                                        j = savedJ + 1;
                                        continue;
                                    }
                                }
                                local_8 = reinterpret_cast<int32_t*>(1);
                            }
                            j = savedJ + 1;
                        } while (j < 4);
                        i = i + 1;
                    } while (i < 4);
                    if (local_8 != nullptr) {
                        havePattern = true;
                        iVar4 = FUN_0069ec6d(local_84, static_cast<uint32_t>(rows), 3);
                        if (iVar4 < 0) {
                            goto LAB_00680ab8;
                        }
                        iVar4 = FUN_0069ec6d(local_84 + 4, static_cast<uint32_t>(rows), 3);
                        if (iVar4 < 0) {
                            goto LAB_00680ab8;
                        }
                    }
                }
                if (!havePattern) {
                    runPerRow = true;
                }
            }
            if (runPerRow) {
                for (int32_t k = 0; k < local_24; ++k) {
                    local_84[0] = 0xffffffff;
                    local_84[1] = 0xffffffff;
                    local_84[2] = 0xffffffff;
                    local_84[3] = 0xffffffff;
                    {
                        const int32_t secondSlot = *reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(
                                pv(at<uint32_t>(pv(at<uint32_t>(self, 0x100)), 0x10))) +
                            k * 4);
                        const int32_t obj = *reinterpret_cast<int32_t*>(
                            static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x14))) +
                            secondSlot * 4);
                        local_84[at<int32_t>(pv(obj), 0x10)] = 0;
                    }
                    iVar4 = FUN_0069ec6d(local_84, static_cast<uint32_t>(rows),
                                         static_cast<uint32_t>(local_24));
                    if (iVar4 < 0) {
                        goto LAB_00680ab8;
                    }
                }
            }
        }
    LAB_006806ee:
        if (local_30 != 0) {
            iVar4 = FUN_0065d8c2();
            if (iVar4 < 0) {
                goto LAB_00680ab8;
            }
            local_30 = 0;
        }
    }
LAB_00680887:
    *reinterpret_cast<uint32_t*>(static_cast<std::uintptr_t>(descriptorValue)) = 0;
    iVar4 = 0;
LAB_00680ab8:
    if (local_30 != 0) {
        FUN_00614343();
    }
LAB_00680ac8:
    if (local_28 != 0) {
        FUN_00614343();
    }
    return iVar4;
}

// ---------------------------------------------------------------------------
// 0x680add — observed shape
// Encode the per-class slots of the selected surfaces: reject the flagged
// type entry, intersect the requested class set, and return either the
// direct 2-bit packing or the 8-entry table encoding, E_FAIL otherwise.
// ---------------------------------------------------------------------------
uint32_t FUN_00680add(void* self, int32_t* param_1, uint32_t param_2,
                      uint32_t param_3, uint32_t* param_4)
{
    const int32_t iVar5 = *param_1;
    const int32_t tableBase = at<int32_t>(self, 0x14);
    const int32_t local_8 = *reinterpret_cast<int32_t*>(
        static_cast<std::uint8_t*>(pv(tableBase)) + iVar5 * 4);
    int32_t   iVar3;
    int32_t   iVar8;
    int32_t   local_18[4];
    uint32_t  local_28[4];
    uint32_t  uVar4;
    uint32_t  uVar7;
    uint32_t  uVar9;
    bool      bVar10;

    {
        const int32_t typeIndex = at<int32_t>(pv(local_8), 4);
        const int32_t typeEntry = *reinterpret_cast<int32_t*>(
            static_cast<std::uint8_t*>(pv(at<uint32_t>(self, 0x10))) + typeIndex * 4);
        if ((at<uint8_t>(pv(typeEntry), 4) & 0x80) != 0) {
            *param_4 = 0xe40000;
            return 0;
        }
    }
    bVar10 = (param_3 & 0x10000) != 0;
    if (bVar10) {
        local_18[0] = 0;
    }
    uVar7 = bVar10 ? 1u : 0u;
    if ((param_3 & 0x20000) != 0) {
        local_18[uVar7] = 1;
        uVar7 = uVar7 + 1;
    }
    if ((param_3 & 0x40000) != 0) {
        local_18[uVar7] = 2;
        uVar7 = uVar7 + 1;
    }
    if ((param_3 & 0x80000) != 0) {
        local_18[uVar7] = 3;
        uVar7 = uVar7 + 1;
    }
    if (uVar7 < param_2) {
        param_2 = uVar7;
    }
    iVar8 = at<int32_t>(self, 0x6c) << 0x1e;
    if (iVar8 < 0) {
        local_28[0] = 0xffffffff;
    }
    else {
        uVar7 = 0;
        if (param_2 != 0) {
            do {
                const int32_t a = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(tableBase)) + iVar5 * 4);
                const int32_t b = *reinterpret_cast<int32_t*>(
                    static_cast<std::uint8_t*>(pv(tableBase)) + param_1[uVar7] * 4);
                if (at<int32_t>(pv(a), 0x10) != at<int32_t>(pv(b), 0x10)) {
                    break;
                }
                uVar7 = uVar7 + 1;
            } while (uVar7 < param_2);
            if (uVar7 < param_2) {
                uVar7 = 0;
                do {
                    local_28[uVar7] = uVar7;
                    uVar7 = uVar7 + 1;
                } while (uVar7 < 4);
                goto LAB_00680bbc;
            }
        }
        local_28[0] = static_cast<uint32_t>(at<int32_t>(pv(local_8), 0x10));
    }
    local_28[1] = local_28[0];
    local_28[2] = local_28[0];
    local_28[3] = local_28[0];
LAB_00680bbc:
    uVar7 = 0;
    if (param_2 != 0) {
        do {
            const int32_t cls = local_18[uVar7];
            const int32_t obj = *reinterpret_cast<int32_t*>(
                static_cast<std::uint8_t*>(pv(tableBase)) + param_1[uVar7] * 4);
            local_28[cls] = static_cast<uint32_t>(at<int32_t>(pv(obj), 0x10));
            uVar7 = uVar7 + 1;
        } while (uVar7 < param_2);
    }
    {
        const uint32_t* packSrc = nullptr;
        if (-1 < iVar8) {
            packSrc = local_28;
        }
        else {
            uVar7 = 0;
            const uint32_t* entry = reinterpret_cast<const uint32_t*>(DAT_007205b8);
            for (;;) {
                if (uVar7 >= 8) {
                    FUN_006626da();
                    return 0x80004005;
                }
                iVar3 = FUN_00673e38(local_28, entry);
                if (iVar3 != 0) {
                    packSrc = reinterpret_cast<const uint32_t*>(&DAT_007205b8[uVar7 * 4]);
                    break;
                }
                entry = entry + 4;
                uVar7 = uVar7 + 1;
            }
        }
        uVar9 = 0;
        uVar7 = 0x10;
        do {
            uVar4 = *packSrc;
            packSrc = packSrc + 1;
            uVar9 = uVar9 | (uVar4 << (uVar7 & 0x1f));
            uVar7 = uVar7 + 2;
        } while (uVar7 < 0x18);
        *param_4 = uVar9;
    }
    return 0;
}

// END OF BATCH
