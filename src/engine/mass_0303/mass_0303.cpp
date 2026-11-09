#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals observed in the supplied corpus listings.
// ---------------------------------------------------------------------------
extern "C" unsigned int _controlfp(unsigned int newValue, unsigned int mask);
extern "C" int atoi(const char* text);
extern "C" int _stricmp(const char* lhs, const char* rhs);
extern "C" long ftol();  // x87 ST0 -> long; the listing shows the implicit ST0 operand

extern void* FUN_00533c78(int size);
extern int   FUN_004127b0(void* dst, int elementSize, int count, void* ctor);
extern int   FUN_0060afb7(void* src, void* out1, void* out2);
extern int   FUN_006294f9(uint32_t size, void* out);
extern int   FUN_0063da83(uint16_t id, int a, int b);
extern int   FUN_0063e306(int flag);
extern int   FUN_0063e44e();
extern int   FUN_0063e8bc(uint32_t value);
extern int   FUN_0063ea6b(uint32_t value, int base);
extern int   FUN_0063eb76(int object, void* out1, void* out2);
extern uint32_t FUN_0063ed81(int node, uint32_t index, int param);
extern int   FUN_0063e97c(int a, int b, int c, void* obj, int d);
extern int   FUN_0063f27d(int object, int flag);
extern int   FUN_0064115d();
extern int   FUN_006431b5(uint32_t handle);
extern int   FUN_006439a7(int a, int b, void* record);
extern int   FUN_006440ac(int flag);
extern int   FUN_006442a6(uint16_t id, uint32_t index, int* stream, uint32_t* pos);
extern int   FUN_00644897(int node, uint32_t count);
extern int   FUN_00644c1f(uint32_t handle, uint32_t param);
extern int   FUN_0064668b(uint32_t group, uint32_t index);
extern int   FUN_00646c28();
extern int   FUN_00647b28();
extern int   FUN_00647b53();
extern int   FUN_00647b9b(int flag);
extern int   FUN_00647c0a(uint32_t count);
extern int   FUN_00647df7(int flag);
extern int   FUN_00647e18(int flag);
extern int   FUN_006480e4(void* a, void* b, int c);
extern uint32_t FUN_0064866e(int node, const char* text, int param);
extern int   FUN_006498da(uint32_t a, uint32_t b, uint32_t c);
extern int   FUN_00649a50(int id);
extern int   FUN_0064a9aa(int id);
extern int   FUN_0064bdfa(uint16_t id, uint16_t flag);
extern int   FUN_0064bedf(uint16_t a, uint16_t b, uint16_t c);
extern int   FUN_0064ceb8(int group, int* entry);
extern int   FUN_0064d12e(int flag);
extern int   FUN_0064d17c(int flag);
extern int   FUN_0064d1cd(int object, int* stream, uint32_t* pos);
extern uint32_t FUN_0064e847(void* self, char* param_1, uint32_t param_2, int param_3);
extern void  operator_delete(void* ptr);
extern uint8_t DAT_006eac9c[];
extern uint8_t DAT_006eacac[];
extern uint8_t PTR_FUN_006ec450;
extern void LAB_00646ba7();
extern void LAB_0063e2de();

// Common stream virtuals: +0x10 returns the element count, +0xc the data base.
static int vtbl_count(int* obj)
{
    return (*reinterpret_cast<int(*)(int*)>(
        *reinterpret_cast<void**>(static_cast<uintptr_t>(*obj) + 0x10)))(obj);
}

static int vtbl_data(int* obj)
{
    return (*reinterpret_cast<int(*)(int*)>(
        *reinterpret_cast<void**>(static_cast<uintptr_t>(*obj) + 0xc)))(obj);
}

static void vtbl_release(int* obj)
{
    (*reinterpret_cast<int(*)(int*)>(
        *reinterpret_cast<void**>(static_cast<uintptr_t>(*obj) + 8)))(obj);
}

// 0x64d308 — observed shape
// Streams three dwords out of param_2 (vtable +0x10 count, +0xc data) into
// self+0x28, self+0x2c and a local element count, validates the stream
// position, then builds a chain of 0x50-byte records linked at +0x3c and
// rooted at self+0x30, finally walking the count-parameterized loop.
int FUN_0064d308(uint32_t param_1, int* param_2, uint32_t* param_3)
{
    uint32_t* puVar2 = param_3;
    uint32_t uVar1 = param_1;
    int iVar4;
    int local_10;
    int local_8;

    if (param_2 != nullptr && static_cast<uint32_t>(vtbl_count(param_2)) >= *param_3 + 1) {
        iVar4 = vtbl_data(param_2);
        *reinterpret_cast<uint32_t*>(uVar1 + 0x28) =
            *reinterpret_cast<uint32_t*>(iVar4 + *param_3 * 4);
    }
    *param_3 = *param_3 + 1;
    if (param_2 != nullptr && static_cast<uint32_t>(vtbl_count(param_2)) >= *param_3 + 1) {
        iVar4 = vtbl_data(param_2);
        *reinterpret_cast<uint32_t*>(uVar1 + 0x2c) =
            *reinterpret_cast<uint32_t*>(iVar4 + *param_3 * 4);
    }
    *param_3 = *param_3 + 1;
    if (param_2 != nullptr && static_cast<uint32_t>(vtbl_count(param_2)) >= *param_3 + 1) {
        iVar4 = vtbl_data(param_2);
        param_1 = *reinterpret_cast<uint32_t*>(iVar4 + *param_3 * 4);
    }
    *param_3 = *param_3 + 1;
    if (param_2 == nullptr || static_cast<uint32_t>(vtbl_count(param_2)) < *param_3) {
        return -0x7fffbffb;
    }
    iVar4 = FUN_0063e8bc(*reinterpret_cast<uint32_t*>(uVar1 + 0x28));
    if (iVar4 < 0) {
        return iVar4;
    }
    local_10 = 0;
    param_3 = nullptr;
    if (*reinterpret_cast<int*>(uVar1 + 0x2c) != 0) {
        uint32_t idx = 0;
        do {
            void* allocated = FUN_00533c78(0x50);
            if (allocated == nullptr) {
                local_8 = 0;
            } else {
                local_8 = FUN_00647b28();
            }
            if (local_8 == 0) {
                return -0x7ff8fff2;
            }
            iVar4 = FUN_0064d1cd(local_8, param_2, puVar2);
            if (iVar4 < 0) goto LAB_0064d474;
            if (local_10 == 0) {
                *reinterpret_cast<int*>(uVar1 + 0x30) = local_8;
            } else {
                *reinterpret_cast<int*>(local_10 + 0x3c) = local_8;
            }
            idx = idx + 1;
            local_10 = local_8;
        } while (idx < *reinterpret_cast<uint32_t*>(uVar1 + 0x2c));
    }
    local_8 = 0;
    iVar4 = FUN_00647c0a(param_1);
    if (iVar4 < 0) {
        return iVar4;
    }
    param_3 = nullptr;
    if (param_1 == 0) {
        return iVar4;
    }
    {
        uint32_t idx = 0;
        do {
            iVar4 = FUN_006442a6(*reinterpret_cast<uint16_t*>(uVar1 + 0x34), idx, param_2, puVar2);
            if (iVar4 < 0) {
                return iVar4;
            }
            idx = idx + 1;
        } while ((idx & 0xffffu) < param_1);
    }
LAB_0064d474:
    if (local_8 == 0) {
        return iVar4;
    }
    FUN_00647b9b(1);
    return iVar4;
}

// 0x64d495 — observed shape
// Resolves a dotted / indexed / '[' n ']' / '@' path against the namespace
// held in the receiver: each +0x50 entry's +0x20 name array is compared
// byte-wise, '[' bounds-checks an index against the entry's +0x10 count,
// and '@' recurses through FUN_0064866e. Returned handles are complemented.
uint32_t FUN_0064d495(void* self, uint32_t param_1, char* param_2, int param_3)
{
    int ecx = static_cast<int>(reinterpret_cast<intptr_t>(self));
    int iVar1;
    int8_t cVar2;
    int iVar3;
    uint32_t uVar4 = 0;
    uint32_t uVar5 = 0;
    int iVar6;
    char* pcVar7;
    int iVar8;
    char* pcVar9 = nullptr;
    uint32_t uVar10;

LAB_0064d613:
    if (param_1 == 0) {
        if (param_2 == nullptr ||
            (uVar5 = FUN_0064e847(self, param_2, param_3 + 1, 0), uVar5 == 0)) {
LAB_0064d5bc:
            uVar5 = 0;
        } else {
LAB_0064d634:
            uVar5 = ~uVar5;
        }
        return uVar5;
    }
    uVar10 = 0;
    uVar5 = FUN_0064e847(self, reinterpret_cast<char*>(static_cast<intptr_t>(param_1)), param_3 + 1, 0);
    if (uVar5 != 0) {
        if (param_2 != nullptr) {
            iVar3 = *reinterpret_cast<int*>(uVar5 + 4);
            if ((*reinterpret_cast<int*>(iVar3 + 4) == 5) &&
                ((*reinterpret_cast<int*>(uVar5 + 8) != -1 ||
                  *reinterpret_cast<int*>(iVar3 + 0x10) == 0)) &&
                ((uVar4 = *reinterpret_cast<uint32_t*>(iVar3 + 0x14),
                  *reinterpret_cast<int*>(uVar5 + 0x20) != 0 ||
                  (iVar3 = FUN_00644897(uVar5, uVar4), -1 < iVar3)))) {
                param_1 = 0;
                do {
                    if (uVar4 <= uVar10) break;
                    iVar3 = *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(uVar5 + 0x20) + 4 + param_1);
                    iVar8 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(ecx + 0xb0) +
                        *reinterpret_cast<int*>(uVar5 + 0x14) * 4) + 0x40);
                    if (iVar8 == 0) {
                        iVar6 = *reinterpret_cast<int*>(ecx + 0x20);
                    } else {
                        iVar6 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 0x38) + 0x10);
                    }
                    iVar1 = *reinterpret_cast<int*>(iVar3 + 8);
                    if (*reinterpret_cast<int*>(iVar1 + iVar6) == 0) {
                        pcVar7 = nullptr;
                    } else {
                        if (iVar8 == 0) {
                            iVar8 = *reinterpret_cast<int*>(ecx + 0x20);
                        } else {
                            iVar8 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 0x38) + 0x10);
                        }
                        pcVar7 = reinterpret_cast<char*>(iVar1 + 4 + iVar8);
                    }
                    cVar2 = *param_2;
                    pcVar9 = param_2;
                    while (cVar2 == *pcVar7 && cVar2 != '\0') {
                        pcVar9 = pcVar9 + 1;
                        pcVar7 = pcVar7 + 1;
                        cVar2 = *pcVar9;
                    }
                    cVar2 = *pcVar9;
                    if (cVar2 == *pcVar7) {
                        uVar5 = *reinterpret_cast<int*>(uVar5 + 0x20) + uVar10 * 0x28;
                        goto LAB_0064d634;
                    }
                    if (*pcVar7 == '\0') {
                        if (cVar2 == '.') {
                            param_1 = ~(*reinterpret_cast<int*>(uVar5 + 0x20) + uVar10 * 0x28);
                            goto LAB_0064d60c;
                        }
                        if (cVar2 == '@') {
                            uVar5 = FUN_0064866e(
                                ~(*reinterpret_cast<int*>(uVar5 + 0x20) + uVar10 * 0x28),
                                pcVar9 + 1, param_3);
                            return uVar5;
                        }
                        if (cVar2 == '[') goto LAB_0064d5a2;
                    }
                    uVar10 = uVar10 + 1;
                    param_1 = param_1 + 0x28;
                } while (true);
            }
            goto LAB_0064d5bc;
        }
        goto LAB_0064d634;
    }
    goto LAB_0064d5bc;

LAB_0064d5a2:
    pcVar9 = pcVar9 + 1;
    if ((*pcVar9 < '0' || '9' < *pcVar9) ||
        (uVar4 = static_cast<uint32_t>(atoi(pcVar9)),
         *reinterpret_cast<uint32_t*>(iVar3 + 0x10) <= uVar4)) {
        goto LAB_0064d5bc;
    }
    for (; '/' < *pcVar9 && *pcVar9 < ':'; pcVar9 = pcVar9 + 1) {
    }
    if (*pcVar9 != ']') goto LAB_0064d5bc;
    pcVar9 = pcVar9 + 1;
    param_1 = FUN_0063ed81(~(*reinterpret_cast<int*>(uVar5 + 0x20) + uVar10 * 0x28), uVar4, param_3);
    if (param_1 == 0) goto LAB_0064d5bc;
    if (*pcVar9 == '\0') {
        return param_1;
    }
    if (*pcVar9 != '.') goto LAB_0064d5bc;
LAB_0064d60c:
    param_2 = pcVar9 + 1;
    goto LAB_0064d613;
}

// 0x64d665 — observed shape
// Forwards the text to FUN_0064866e unless the handle is null.
uint32_t FUN_0064d665(uint32_t param_1, int param_2, uint32_t param_3)
{
    if (param_2 == 0) {
        return 0;
    }
    return FUN_0064866e(param_2, reinterpret_cast<char*>(static_cast<intptr_t>(param_3)), 0);
}

// 0x64d688 — observed shape
// Recursive layout pass over one 100-byte group record: resolves the group
// through the entry table at self+0x2c, validates both the 0xa000000 and
// 0xb000000 record classes, refreshes sub-records via FUN_0064668b, rounds
// the vtable-normalized float with ftol, then recurses over each child.
int FUN_0064d688(void* self, int param_1, int param_2)
{
    int ecx = static_cast<int>(reinterpret_cast<intptr_t>(self));
    uint16_t* puVar1;
    uint16_t uVar2;
    int iVar3;
    int iVar4;
    uint16_t uVar5;
    int* piVar6 = nullptr;
    uint32_t uVar7;
    uint16_t* puVar8;
    uint32_t uVar10;
    uint32_t local_c = 0;
    int local_8 = 0;
    bool ok;

    int* piVar9 = reinterpret_cast<int*>(param_1 * 100 + *reinterpret_cast<int*>(ecx + 0x2c));

    // 0xa000000 record class, prefix side.
    ok = (*reinterpret_cast<uint16_t*>(piVar9 + 6) == 0xffff);
    if (!ok) {
        piVar6 = reinterpret_cast<int*>(
            static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(piVar9 + 6)) * 100 + piVar9[1]);
        ok = (*piVar6 == 0);
    }
    if (!ok) {
        ok = (piVar6[0x16] != 0xa000000);
    }
    if (!ok) {
        local_8 = FUN_0063da83(param_1, -static_cast<int>(param_2 != 0), 0xffffffff);
        ok = (local_8 > -1);
        if (ok) {
            local_8 = FUN_00649a50(param_1);
            ok = (local_8 > -1);
        }
        if (ok) {
            local_8 = FUN_0063da83(param_1, param_2 != 0, 1);
            ok = (local_8 > -1);
        }
    }
    if (ok) {
        // 0xb000000 record class, prefix side.
        bool ok2 = (*reinterpret_cast<uint16_t*>(
                        reinterpret_cast<intptr_t>(piVar9) + 0x1a) == 0xffff);
        if (!ok2) {
            piVar6 = reinterpret_cast<int*>(
                static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(
                    reinterpret_cast<intptr_t>(piVar9) + 0x1a)) * 100 + piVar9[1]);
            ok2 = (*piVar6 == 0);
        }
        if (!ok2) {
            ok2 = (piVar6[0x16] != 0xb000000);
            if (!ok2) {
                local_8 = FUN_0063da83(param_1, -static_cast<int>(param_2 != 0), 0xffffffff);
                ok2 = (local_8 > -1);
                if (ok2) {
                    local_8 = FUN_0064a9aa(param_1);
                    ok2 = (local_8 > -1);
                }
                if (ok2) {
                    local_8 = FUN_0063da83(param_1, param_2 != 0, 1);
                    ok2 = (local_8 > -1);
                }
            }
        }
        ok = ok && ok2;
    }

    if (ok) {
        iVar3 = piVar9[5];
        iVar4 = *piVar9;
        uVar2 = 0;
        if (static_cast<int16_t>(piVar9[0xd]) != 0) {
            do {
                puVar1 = reinterpret_cast<uint16_t*>(iVar3 + iVar4 + static_cast<uint32_t>(uVar2) * 2);
                piVar6 = reinterpret_cast<int*>(
                    static_cast<uint32_t>(*puVar1) * 100 + piVar9[1]);
                puVar8 = reinterpret_cast<uint16_t*>(piVar6[0x12] + *piVar9);
                if (*puVar8 != 0) {
                    local_c = *reinterpret_cast<uint32_t*>(piVar6[3] + 0x10);
                    if (local_c == 0) {
                        local_c = 1;
                    }
                    if (*piVar6 != 0) {
                        *piVar6 = piVar6[1];
                        local_8 = FUN_0064668b(param_1, *puVar1);
                        if (local_8 < 0) {
                            return local_8;
                        }
                        {
                            int* obj = reinterpret_cast<int*>(static_cast<intptr_t>(piVar6[0xe]));
                            (*reinterpret_cast<int(*)(int*)>(
                                *reinterpret_cast<void**>(static_cast<uintptr_t>(*obj) + 0xc)))(obj);
                        }
                        uVar5 = static_cast<uint16_t>(ftol());
                        if (puVar8[1] != uVar5) {
                            if (local_c <= uVar5) {
                                return -0x7fffbffb;
                            }
                            puVar8[1] = uVar5;
                        }
                    }
                    uVar7 = 0;
                    uVar10 = 0;
                    if (local_c != 0) {
                        do {
                            local_8 = FUN_0064d688(self, (*puVar8 - 1) + uVar7, param_2);
                            if (local_8 < 0) {
                                return local_8;
                            }
                            uVar10 = uVar10 + 1;
                            uVar7 = uVar10 & 0xffff;
                        } while (uVar7 < local_c);
                    }
                }
                uVar2 = uVar2 + 1;
            } while (uVar2 < *reinterpret_cast<uint16_t*>(piVar9 + 0xd));
        }
    }
    return local_8;
}

// 0x64d870 — observed shape
// Flushes the pending draw list held at self+0x108/self+0x10c: clears bit 1
// of each entry's +0xc flags, re-issues or rebinds the entry's geometry,
// restores the FP control word when bit 0 of +0x118 is set, then clears the
// list count and bits 1/2.
uint32_t FUN_0064d870(int param_1)
{
    uint16_t* puVar1;
    uint16_t* puVar2;
    int* piVar3;
    int iVar4;
    uint32_t uVar5;

    *reinterpret_cast<uint32_t*>(param_1 + 0x118) |= 4;
    uVar5 = 0;
    if (*reinterpret_cast<int*>(param_1 + 0x10c) != 0) {
        do {
            puVar1 = reinterpret_cast<uint16_t*>(*reinterpret_cast<int*>(param_1 + 0x108) + uVar5 * 4);
            iVar4 = static_cast<uint32_t>(*puVar1) * 100 + *reinterpret_cast<int*>(param_1 + 0x2c);
            piVar3 = reinterpret_cast<int*>(
                static_cast<uint32_t>(puVar1[1]) * 100 + *reinterpret_cast<int*>(iVar4 + 4));
            piVar3[0xc] = piVar3[0xc] & 0xfffffffd;
            if (static_cast<int16_t>(*reinterpret_cast<uint16_t*>(iVar4 + 0x3c)) != 0 && *piVar3 != 0) {
                if ((piVar3[0xc] & 8u) == 0) {
                    puVar2 = reinterpret_cast<uint16_t*>(*reinterpret_cast<int*>(param_1 + 0x108) + uVar5 * 4);
                    FUN_0064bedf(*puVar2, puVar2[1], 0xffff);
                } else {
                    FUN_0064ceb8(iVar4, piVar3);
                }
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < *reinterpret_cast<uint32_t*>(param_1 + 0x10c));
    }
    if ((*reinterpret_cast<uint8_t*>(param_1 + 0x118) & 1) != 0) {
        _controlfp(*reinterpret_cast<uint32_t*>(param_1 + 0x114), 0x30000);
        *reinterpret_cast<uint32_t*>(param_1 + 0x118) &= 0xfffffffe;
    }
    *reinterpret_cast<uint32_t*>(param_1 + 0x10c) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0x118) &= 0xfffffffb;
    return 0;
}

// 0x64d92b — observed shape
// Switches the active sub-layout at self+0x44: deactivates the previous entry
// through FUN_0063da83 with (-1, 0), activates the new one with (1, bool),
// optionally binds the geometry at self+0x38 (bit 0x100), and always restores
// the FP control word when bit 0 of self+0x118 is set.
int FUN_0064d92b(int param_1, uint32_t param_2)
{
    int iVar3 = param_1;
    int iVar4;
    int iVar5;

    if (*reinterpret_cast<int*>(param_1 + 0x3c) == 0) {
        iVar4 = -0x7789f794;
        goto LAB_0064da1c;
    }
    iVar5 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x42)) * 0xb4 +
            *reinterpret_cast<int*>(param_1 + 0xa4);
    if (param_2 < *reinterpret_cast<uint32_t*>(iVar5 + 0x34)) {
        uint16_t uVar2 = *reinterpret_cast<uint16_t*>(param_1 + 0x44);
        if (static_cast<uint16_t>(param_2) != uVar2) {
            if (uVar2 != 0xffff &&
                (iVar4 = FUN_0063da83(
                     *reinterpret_cast<uint16_t*>(
                         static_cast<uint32_t>(uVar2) * 0x38 + 0x34 +
                         *reinterpret_cast<int*>(iVar5 + 0x38)),
                     0xffffffff,
                     static_cast<int>(*reinterpret_cast<uint16_t*>(param_1 + 0x40) !=
                                      *reinterpret_cast<uint16_t*>(param_1 + 0x42)) - 1),
                 iVar4 < 0)) {
                goto LAB_0064da1c;
            }
            *reinterpret_cast<uint16_t*>(param_1 + 0x44) = static_cast<uint16_t>(param_2);
            iVar4 = FUN_0063da83(
                *reinterpret_cast<uint16_t*>(
                    (param_2 & 0xffff) * 0x38 + 0x34 + *reinterpret_cast<int*>(iVar5 + 0x38)),
                1,
                static_cast<int>(static_cast<int16_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x40)) ==
                                 static_cast<int16_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x42))));
            if (iVar4 < 0) {
                goto LAB_0064da1c;
            }
        }
        iVar4 = *reinterpret_cast<int*>(iVar5 + 0x38);
        *reinterpret_cast<uint8_t*>(param_1 + 0x118) &= 0x7f;
        if ((*reinterpret_cast<uint32_t*>(param_1 + 0x118) & 0x100) == 0) {
            iVar4 = FUN_0064bdfa(*reinterpret_cast<uint16_t*>(param_2 * 0x38 + iVar4 + 0x34), 0xffff);
            if (-1 < iVar4) {
                *reinterpret_cast<uint32_t*>(param_1 + 0x118) |= 0x100;
            }
            goto LAB_0064da1c;
        }
    }
    iVar4 = -0x7789f794;
LAB_0064da1c:
    {
        uint32_t* puVar1 = reinterpret_cast<uint32_t*>(iVar3 + 0x118);
        if ((*reinterpret_cast<uint8_t*>(puVar1) & 1) != 0) {
            _controlfp(*reinterpret_cast<uint32_t*>(iVar3 + 0x114), 0x30000);
            *puVar1 = *puVar1 & 0xfffffffe;
        }
    }
    return iVar4;
}

// 0x64da45 — observed shape
// Destructor: reinstalls the vtable at PTR_FUN_006ec450, releases the
// self+0x37 / self+0x36 array (count self+0x34), frees the scalar buffers at
// +0x2f, +0x31, +0x2c, +0x33, +0x42, releases the object arrays at +0x47
// (count +0x48), tears down the subsystems at +0xb, +0x27, +0x29, +6, and
// finally releases four vtable-owned objects through vtable slot +8.
void FUN_0064da45(void* self)
{
    int* ecx = static_cast<int*>(self);
    void* pvVar1;
    int* piVar2;
    uint32_t uVar3;

    *ecx = static_cast<int>(reinterpret_cast<intptr_t>(&PTR_FUN_006ec450));
    if (ecx[0x37] != 0) {
        FUN_0063e306(1);
        ecx[0x37] = 0;
    }
    if (ecx[0x36] != 0 && (uVar3 = 0, ecx[0x34] != 0)) {
        do {
            if (*reinterpret_cast<int*>(static_cast<intptr_t>(ecx[0x36]) + uVar3 * 4) != 0) {
                FUN_00647df7(1);
                *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(ecx[0x36]) + uVar3 * 4) = 0;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < static_cast<uint32_t>(ecx[0x34]));
    }
    FUN_0063e44e();
    operator_delete(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x2f])));
    uVar3 = 0;
    if (ecx[0x48] != 0) {
        do {
            pvVar1 = *reinterpret_cast<void**>(static_cast<intptr_t>(ecx[0x47]) + uVar3 * 4);
            if (pvVar1 != nullptr) {
                operator_delete(pvVar1);
                *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(ecx[0x47]) + uVar3 * 4) = 0;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < static_cast<uint32_t>(ecx[0x48]));
    }
    pvVar1 = reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x47]));
    if (pvVar1 != nullptr) {
        operator_delete(pvVar1);
        ecx[0x47] = 0;
    }
    if (reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x36])) != nullptr) {
        operator_delete(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x36])));
        ecx[0x36] = 0;
    }
    if (ecx[0xb] != 0) {
        FUN_0064d12e(3);
        ecx[0xb] = 0;
    }
    pvVar1 = reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x31]));
    if (pvVar1 != nullptr) {
        operator_delete(pvVar1);
        ecx[0x31] = 0;
    }
    if (ecx[0x27] != 0) {
        FUN_00647e18(3);
        ecx[0x27] = 0;
    }
    if (ecx[0x29] != 0) {
        FUN_0064d17c(3);
        ecx[0x29] = 0;
    }
    if (ecx[6] != 0) {
        FUN_006440ac(3);
        ecx[6] = 0;
    }
    if (reinterpret_cast<void*>(static_cast<intptr_t>(ecx[8])) != nullptr) {
        operator_delete(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[8])));
        ecx[8] = 0;
    }
    pvVar1 = reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x2c]));
    if (pvVar1 != nullptr) {
        operator_delete(pvVar1);
        ecx[0x2c] = 0;
    }
    pvVar1 = reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x33]));
    if (pvVar1 != nullptr) {
        operator_delete(pvVar1);
        ecx[0x33] = 0;
    }
    piVar2 = reinterpret_cast<int*>(static_cast<intptr_t>(ecx[0x40]));
    if (piVar2 != nullptr) {
        vtbl_release(piVar2);
        ecx[0x40] = 0;
    }
    piVar2 = reinterpret_cast<int*>(static_cast<intptr_t>(ecx[0x41]));
    if (piVar2 != nullptr) {
        vtbl_release(piVar2);
        ecx[0x41] = 0;
    }
    piVar2 = reinterpret_cast<int*>(static_cast<intptr_t>(ecx[10]));
    if (piVar2 != nullptr) {
        vtbl_release(piVar2);
        ecx[10] = 0;
    }
    piVar2 = reinterpret_cast<int*>(static_cast<intptr_t>(ecx[0xe]));
    if (piVar2 != nullptr) {
        vtbl_release(piVar2);
        ecx[0xe] = 0;
    }
    operator_delete(reinterpret_cast<void*>(static_cast<intptr_t>(ecx[0x42])));
    FUN_00646c28();
    FUN_00647b53();
    FUN_0064115d();
}

// 0x64dc1e — observed shape
// Destructor thunk: runs the base teardown, then frees the object when the
// caller's delete flag has bit 0 set.
void FUN_0064dc1e(void* self, uint8_t param_1)
{
    FUN_0064da45(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x64dc3f — observed shape
// Builds the two per-row tables at self+0xb4 / self+0xc0 and the row record
// array at self+0xbc (self+0xa0 rows x self+0xac columns), seeds each row's
// source entries through FUN_0063da83 / FUN_0064d688, then walks every row
// list at self+0xb0 collecting entries into growable arrays split by the
// record +8 flag bit 3, emitting the sorted pointer tables back into the row
// storage. Returns 0x8007000e on allocation failure and 0x8007000e as the
// generic OOM code the listing uses (local_14).
uint32_t FUN_0064dc3f(void* self)
{
    int ecx = static_cast<int>(reinterpret_cast<intptr_t>(self));
    int* piVar1;
    uint32_t uVar2;
    uint32_t* puVar3 = nullptr;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar7;
    int iVar9;
    uint32_t* puVar8;
    uint32_t* puVar10;
    uint32_t local_2c = 0;
    uint32_t local_28 = 0;
    uint32_t local_1c = 0;
    uint32_t local_18 = 0;
    uint32_t local_14 = 0;
    uint32_t* local_10 = nullptr;
    uint32_t* local_c = nullptr;
    uint32_t local_8 = 0;

    *reinterpret_cast<uint8_t*>(ecx + 0x119) |= 8;
    local_14 = 0;
    local_c = nullptr;
    local_10 = nullptr;
    local_2c = 0;
    local_28 = 0;
    uVar2 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_00533c78(
        *reinterpret_cast<int*>(ecx + 0xa0) * *reinterpret_cast<int*>(ecx + 0xac) * 4)));
    *reinterpret_cast<uint32_t*>(ecx + 0xb4) = uVar2;
    uVar2 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_00533c78(
        *reinterpret_cast<int*>(ecx + 0xa0) * *reinterpret_cast<int*>(ecx + 0xac) * 4)));
    *reinterpret_cast<uint32_t*>(ecx + 0xc0) = uVar2;
    puVar3 = reinterpret_cast<uint32_t*>(FUN_00533c78(*reinterpret_cast<int*>(ecx + 0xac)));
    *reinterpret_cast<uint32_t**>(ecx + 0xbc) = puVar3;
    if (*reinterpret_cast<int*>(ecx + 0xb4) == 0 || *reinterpret_cast<int*>(ecx + 0xc0) == 0 ||
        puVar3 == nullptr) {
        local_14 = 0x8007000e;
    } else {
        uVar6 = *reinterpret_cast<uint32_t*>(ecx + 0xac);
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar3 = 0;
            puVar3 = puVar3 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *reinterpret_cast<uint8_t*>(puVar3) = 0;
            puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar3) + 1);
        }
        *reinterpret_cast<uint16_t*>(ecx + 0x40) = 0;
        if (*reinterpret_cast<int*>(ecx + 0xa0) != 0) {
            do {
                iVar4 = *reinterpret_cast<int*>(ecx + 0xac) *
                        static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 4;
                *reinterpret_cast<int*>(ecx + 0xb8) = *reinterpret_cast<int*>(ecx + 0xb4) + iVar4;
                iVar4 = *reinterpret_cast<int*>(ecx + 0xc0) + iVar4;
                local_18 = 0;
                if (*reinterpret_cast<int*>(
                        static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x34 +
                        *reinterpret_cast<int*>(ecx + 0xa4)) != 0) {
                    local_1c = 0;
                    do {
                        iVar9 = *reinterpret_cast<int*>(
                                    static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x38 +
                                    *reinterpret_cast<int*>(ecx + 0xa4)) + local_1c;
                        FUN_0063da83(*reinterpret_cast<uint16_t*>(iVar9 + 0x34), 0, 1);
                        FUN_0064d688(self, *reinterpret_cast<uint16_t*>(iVar9 + 0x34), 0);
                        local_18 = local_18 + 1;
                        local_1c = local_1c + 0x38;
                    } while (local_18 < *reinterpret_cast<uint32_t*>(
                                 static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x34 +
                                 *reinterpret_cast<int*>(ecx + 0xa4)));
                }
                local_18 = 0;
                if (*reinterpret_cast<int*>(ecx + 0xac) != 0) {
                    do {
                        iVar9 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(
                                    *reinterpret_cast<int*>(ecx + 0xb0) + local_18 * 4) + 0x34);
                        uVar6 = 0;
                        local_1c = 0;
                        local_8 = 0;
                        if (iVar9 != 0) {
                            iVar9 = *reinterpret_cast<int*>(iVar9 + 0x18);
                            do {
                                iVar9 = *reinterpret_cast<int*>(iVar9 + 0x1c);
                                iVar7 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(iVar9 + 0x14)) * 100 +
                                        *reinterpret_cast<int*>(ecx + 0x2c);
                                if (static_cast<int16_t>(*reinterpret_cast<uint16_t*>(iVar7 + 0x3a)) != 0) {
                                    if ((*reinterpret_cast<uint8_t*>(iVar7 + 8) & 8) == 0) {
                                        if (local_2c <= uVar6) {
                                            local_2c = local_2c * 2 + 1;
                                            puVar3 = reinterpret_cast<uint32_t*>(
                                                FUN_00533c78(static_cast<int>(local_2c * 4)));
                                            if (puVar3 == nullptr) goto LAB_0064dfe9;
                                            if (uVar6 != 0) {
                                                puVar8 = local_c;
                                                puVar10 = puVar3;
                                                for (; uVar6 != 0; uVar6 = uVar6 - 1) {
                                                    *puVar10 = *puVar8;
                                                    puVar8 = puVar8 + 1;
                                                    puVar10 = puVar10 + 1;
                                                }
                                                uVar6 = local_1c;
                                            }
                                            operator_delete(local_c);
                                            local_c = puVar3;
                                        }
                                        local_c[uVar6] = static_cast<uint32_t>(iVar9);
                                        uVar6 = uVar6 + 1;
                                        local_1c = uVar6;
                                    } else {
                                        if (local_28 <= local_8) {
                                            local_28 = local_28 * 2 + 1;
                                            puVar3 = reinterpret_cast<uint32_t*>(
                                                FUN_00533c78(static_cast<int>(local_28 * 4)));
                                            if (puVar3 == nullptr) goto LAB_0064dfe9;
                                            if (local_8 != 0) {
                                                puVar8 = local_10;
                                                puVar10 = puVar3;
                                                for (uVar6 = local_8; uVar6 != 0; uVar6 = uVar6 - 1) {
                                                    *puVar10 = *puVar8;
                                                    puVar8 = puVar8 + 1;
                                                    puVar10 = puVar10 + 1;
                                                }
                                                uVar6 = local_1c;
                                            }
                                            operator_delete(local_10);
                                            local_10 = puVar3;
                                        }
                                        local_10[local_8] = static_cast<uint32_t>(iVar9);
                                        local_8 = local_8 + 1;
                                    }
                                }
                            } while (*reinterpret_cast<int*>(iVar9 + 0x1c) !=
                                     *reinterpret_cast<int*>(*reinterpret_cast<int*>(
                                         *reinterpret_cast<int*>(ecx + 0xb0) + local_18 * 4) + 0x34));
                        }
                        if (local_8 + uVar6 == 0) {
                            *reinterpret_cast<uint32_t*>(
                                *reinterpret_cast<int*>(ecx + 0xb8) + local_18 * 4) = 0;
LAB_0064df63:
                            *reinterpret_cast<uint32_t*>(iVar4 + local_18 * 4) = 0;
                        } else {
                            uVar2 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(
                                FUN_00533c78(static_cast<int>((local_8 + uVar6) * 4 + 4))));
                            *reinterpret_cast<uint32_t*>(
                                *reinterpret_cast<int*>(ecx + 0xb8) + local_18 * 4) = uVar2;
                            puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                                *reinterpret_cast<uint32_t*>(
                                    *reinterpret_cast<int*>(ecx + 0xb8) + local_18 * 4)));
                            if (puVar3 == nullptr) {
LAB_0064dfe9:
                                iVar4 = 0;
                                uVar6 = 0;
                                local_14 = 0x8007000e;
                                if (*reinterpret_cast<int*>(
                                        static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x34 +
                                        *reinterpret_cast<int*>(ecx + 0xa4)) != 0) {
                                    do {
                                        FUN_0063da83(
                                            *reinterpret_cast<uint16_t*>(
                                                *reinterpret_cast<int*>(
                                                    static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x38 +
                                                    *reinterpret_cast<int*>(ecx + 0xa4)) + 0x34 + iVar4),
                                            0, 0xffffffff);
                                        uVar6 = uVar6 + 1;
                                        iVar4 = iVar4 + 0x38;
                                    } while (uVar6 < *reinterpret_cast<uint32_t*>(
                                                 static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x34 +
                                                 *reinterpret_cast<int*>(ecx + 0xa4)));
                                }
                                goto LAB_0064e049;
                            }
                            uVar5 = 0;
                            if (uVar6 != 0) {
                                puVar8 = local_c;
                                for (; uVar6 != 0; uVar6 = uVar6 - 1) {
                                    *puVar3 = *puVar8;
                                    puVar8 = puVar8 + 1;
                                    puVar3 = puVar3 + 1;
                                }
                                uVar5 = local_1c;
                            }
                            iVar9 = static_cast<int>(local_8 * 4);
                            puVar3 = reinterpret_cast<uint32_t*>(
                                *reinterpret_cast<int*>(
                                    *reinterpret_cast<int*>(ecx + 0xb8) + local_18 * 4) + uVar5 * 4);
                            for (uVar6 = static_cast<uint32_t>(iVar9 + 4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                                *puVar3 = 0;
                                puVar3 = puVar3 + 1;
                            }
                            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                                *reinterpret_cast<uint8_t*>(puVar3) = 0;
                                puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar3) + 1);
                            }
                            if (local_8 == 0) goto LAB_0064df63;
                            puVar3 = reinterpret_cast<uint32_t*>(FUN_00533c78(iVar9 + 4));
                            piVar1 = reinterpret_cast<int*>(iVar4 + local_18 * 4);
                            *piVar1 = static_cast<int>(reinterpret_cast<intptr_t>(puVar3));
                            if (puVar3 == nullptr) goto LAB_0064dfe9;
                            puVar8 = local_10;
                            for (local_8 = local_8 & 0x3fffffff; local_8 != 0; local_8 = local_8 - 1) {
                                *puVar3 = *puVar8;
                                puVar8 = puVar8 + 1;
                                puVar3 = puVar3 + 1;
                            }
                            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                                *reinterpret_cast<uint8_t*>(puVar3) = *reinterpret_cast<uint8_t*>(puVar8);
                                puVar8 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar8) + 1);
                                puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar3) + 1);
                            }
                            *reinterpret_cast<uint32_t*>(*piVar1 + iVar9) = 0;
                        }
                        local_18 = local_18 + 1;
                    } while (local_18 < *reinterpret_cast<uint32_t*>(ecx + 0xac));
                }
                iVar4 = 0;
                uVar6 = 0;
                if (*reinterpret_cast<int*>(
                        static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x34 +
                        *reinterpret_cast<int*>(ecx + 0xa4)) != 0) {
                    do {
                        FUN_0063da83(*reinterpret_cast<uint16_t*>(
                            *reinterpret_cast<int*>(
                                static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x38 +
                                *reinterpret_cast<int*>(ecx + 0xa4)) + 0x34 + iVar4), 0, 0xffffffff);
                        uVar6 = uVar6 + 1;
                        iVar4 = iVar4 + 0x38;
                    } while (uVar6 < *reinterpret_cast<uint32_t*>(
                                 static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) * 0xb4 + 0x34 +
                                 *reinterpret_cast<int*>(ecx + 0xa4)));
                }
                *reinterpret_cast<uint16_t*>(ecx + 0x40) =
                    *reinterpret_cast<uint16_t*>(ecx + 0x40) + 1;
            } while (static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x40)) <
                     *reinterpret_cast<uint32_t*>(ecx + 0xa0));
        }
LAB_0064e049:
        *reinterpret_cast<uint16_t*>(ecx + 0x40) = 0xffff;
    }
    operator_delete(local_c);
    operator_delete(local_10);
    *reinterpret_cast<uint8_t*>(ecx + 0x119) &= 0xf7;
    return local_14;
}

// 0x64e079 — observed shape
// Streams four dwords (self+0x2c, +0x30, +0x28, +0x38) from param_2, builds
// the same 0x50-byte record chain as FUN_0064d308 rooted at param_1+0x3c,
// then classifies the record at param_1+0x2c by its +4 kind: kinds 2/3 scale
// the counter at local_c+0x124, kind 5 resolves a sub-table and accumulates
// into local_c+300, other kinds scale local_c+0x128.
int FUN_0064e079(void* self, int param_1, int* param_2, uint32_t* param_3)
{
    // NEEDS_MANUAL: the listing reads `local_c` before assigning it. Its value
    // is the ECX receiver (the manager object owning +0x1c/+0x20/+0xa8/+0x124),
    // so it is bound to `self` here.
    int local_c = static_cast<int>(reinterpret_cast<intptr_t>(self));
    uint32_t* puVar5 = param_3;
    int* piVar2 = param_2;
    int iVar9 = param_1;
    int local_8 = 0;
    int iVar3;
    int iVar8;
    int iVar6;
    uint32_t uVar4;
    uint32_t uVar7;
    uint32_t* pdest;

    *reinterpret_cast<uint32_t*>(param_1 + 0x1c) = 0;
    *reinterpret_cast<uint32_t*>(param_1 + 0x18) = 0;
    if (param_2 != nullptr && static_cast<uint32_t>(vtbl_count(param_2)) >= *puVar5 + 1) {
        iVar8 = vtbl_data(piVar2);
        *reinterpret_cast<uint32_t*>(param_1 + 0x2c) =
            *reinterpret_cast<uint32_t*>(iVar8 + *puVar5 * 4);
    }
    *puVar5 = *puVar5 + 1;
    if (piVar2 != nullptr && static_cast<uint32_t>(vtbl_count(piVar2)) >= *puVar5 + 1) {
        iVar8 = vtbl_data(piVar2);
        *reinterpret_cast<uint32_t*>(param_1 + 0x30) =
            *reinterpret_cast<uint32_t*>(iVar8 + *puVar5 * 4);
    }
    *puVar5 = *puVar5 + 1;
    if (piVar2 != nullptr && static_cast<uint32_t>(vtbl_count(piVar2)) >= *puVar5 + 1) {
        iVar8 = vtbl_data(piVar2);
        *reinterpret_cast<uint32_t*>(param_1 + 0x28) =
            *reinterpret_cast<uint32_t*>(iVar8 + *puVar5 * 4);
    }
    *puVar5 = *puVar5 + 1;
    if (piVar2 != nullptr && static_cast<uint32_t>(vtbl_count(piVar2)) >= *puVar5 + 1) {
        iVar8 = vtbl_data(piVar2);
        *reinterpret_cast<uint32_t*>(param_1 + 0x38) =
            *reinterpret_cast<uint32_t*>(iVar8 + *puVar5 * 4);
    }
    *puVar5 = *puVar5 + 1;
    if (piVar2 == nullptr || static_cast<uint32_t>(vtbl_count(piVar2)) < *puVar5) {
        return -0x7fffbffb;
    }
    int* piVar1 = reinterpret_cast<int*>(param_1 + 0x38);
    param_1 = 0;
    pdest = reinterpret_cast<uint32_t*>(iVar9);
    param_2 = nullptr;
    if (*piVar1 != 0) {
        do {
            void* allocated = FUN_00533c78(0x50);
            if (allocated == nullptr) {
                local_8 = 0;
            } else {
                local_8 = FUN_00647b28();
            }
            if (local_8 == 0) {
                return -0x7ff8fff2;
            }
            param_1 = FUN_0064d1cd(local_8, piVar2, puVar5);
            int iVar8b = local_8;
            if (param_1 < 0) goto LAB_0064e24e;
            local_8 = 0;
            param_2 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_2) + 1);
            *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(pdest) + 0x3c) = iVar8b;
            pdest = reinterpret_cast<uint32_t*>(iVar8b);
        } while (reinterpret_cast<uintptr_t>(param_2) <
                 static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(iVar9 + 0x38)));
    }
    iVar6 = local_c;
    *reinterpret_cast<int*>(local_c + 0xa8) = *reinterpret_cast<int*>(local_c + 0xa8) + 1;
    iVar8 = *reinterpret_cast<int*>(local_c + 0x20);
    iVar3 = *reinterpret_cast<int*>(iVar9 + 0x2c);
    if (static_cast<uint32_t>(*reinterpret_cast<int*>(local_c + 0x1c) + iVar8) <
        static_cast<uint32_t>(iVar8 + 0x14 + iVar3)) {
        return param_1;
    }
    uVar7 = *reinterpret_cast<uint32_t*>(iVar8 + 4 + iVar3);
    uVar4 = *reinterpret_cast<uint32_t*>(iVar8 + 0x10 + iVar3);
    if (1 < uVar7) {
        if (uVar7 < 4) {
            uVar7 = 1;
            if (1 < uVar4) {
                uVar7 = uVar4;
            }
            *reinterpret_cast<int*>(local_c + 0x124) =
                *reinterpret_cast<int*>(local_c + 0x124) + static_cast<int>(uVar7 * 0x40);
            return param_1;
        }
        if (uVar7 != 5) {
            return param_1;
        }
        local_c = *reinterpret_cast<int*>(iVar9 + 0x30);
        pdest = reinterpret_cast<uint32_t*>(iVar3 + iVar8);
        param_2 = reinterpret_cast<int*>(iVar8 + local_c);
        local_8 = iVar3;
        iVar9 = FUN_006480e4(&pdest, &param_2, 0);
        if (iVar9 < 0) {
            return iVar9;
        }
        iVar8 = FUN_0063eb76(*reinterpret_cast<int*>(iVar6 + 0x20), &local_8, &local_c);
        int* piVar2b = reinterpret_cast<int*>(iVar6 + 300);
        *piVar2b = *piVar2b + iVar8;
        return iVar9;
    }
    uVar7 = 1;
    if (1 < uVar4) {
        uVar7 = uVar4;
    }
    *reinterpret_cast<int*>(local_c + 0x128) =
        *reinterpret_cast<int*>(local_c + 0x128) + static_cast<int>(uVar7 * 0x10);
LAB_0064e24e:
    if (local_8 == 0) {
        return param_1;
    }
    FUN_00647b9b(1);
    return param_1;
}

// 0x64e266 — observed shape
// Streams self+0x28, self+0x2c and self+0x34 from param_2, builds the
// linked record chain rooted at self+0x30, allocates the self+0x38 record
// array (self+0x34 entries of 0x38 bytes) and streams a record into each,
// collects the referenced ids up to the max seen in DAT_006eacac, assigns
// deduplicated slot numbers into self+0x3c, allocates the 0x68-byte per-slot
// table at self+0x40, then classifies every child record by the high byte of
// its DAT_006eacac class word, accumulating the per-class counters at
// self+0xa4..self+0xb0.
int FUN_0064e266(void* self, int param_1, int* param_2, uint32_t* param_3)
{
    int ecx = static_cast<int>(reinterpret_cast<intptr_t>(self));
    uint32_t* puVar4 = param_3;
    int iVar3 = param_1;
    uint16_t* local_c = nullptr;
    uint32_t* local_10 = nullptr;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar6;
    int iVar8;
    uint32_t uVar9;
    uint16_t uVar10;
    uint16_t* puVar11;
    uint32_t uVar12;
    uint32_t local_18;
    uint32_t local_14;
    bool bVar1;
    bool bVar2;
    int iVar7;
    int local_8 = 0;
    uint32_t uMax = 0;
    uint32_t counter1 = 0;
    uint32_t counter2 = 0;

    if (param_2 != nullptr && static_cast<uint32_t>(vtbl_count(param_2)) >= *param_3 + 1) {
        iVar6 = vtbl_data(param_2);
        *reinterpret_cast<uint32_t*>(param_1 + 0x28) =
            *reinterpret_cast<uint32_t*>(iVar6 + *param_3 * 4);
    }
    *param_3 = *param_3 + 1;
    if (param_2 != nullptr && static_cast<uint32_t>(vtbl_count(param_2)) >= *param_3 + 1) {
        iVar6 = vtbl_data(param_2);
        *reinterpret_cast<uint32_t*>(param_1 + 0x2c) =
            *reinterpret_cast<uint32_t*>(iVar6 + *param_3 * 4);
    }
    *param_3 = *param_3 + 1;
    if (param_2 != nullptr && static_cast<uint32_t>(vtbl_count(param_2)) >= *param_3 + 1) {
        iVar6 = vtbl_data(param_2);
        *reinterpret_cast<uint32_t*>(param_1 + 0x34) =
            *reinterpret_cast<uint32_t*>(iVar6 + *param_3 * 4);
    }
    *param_3 = *param_3 + 1;
    if (param_2 == nullptr || static_cast<uint32_t>(vtbl_count(param_2)) < *param_3) {
        return -0x7fffbffb;
    }
    iVar6 = FUN_0063e8bc(*reinterpret_cast<uint32_t*>(param_1 + 0x28));
    if (iVar6 < 0) {
        return iVar6;
    }
    local_14 = 0;
    {
        uint32_t idx = 0;
        if (*reinterpret_cast<int*>(param_1 + 0x2c) != 0) {
            do {
                void* allocated = FUN_00533c78(0x50);
                if (allocated == nullptr) {
                    local_8 = 0;
                } else {
                    local_8 = FUN_00647b28();
                }
                if (local_8 == 0) {
                    return -0x7ff8fff2;
                }
                iVar6 = FUN_0064d1cd(local_8, param_2, puVar4);
                if (iVar6 < 0) goto LAB_0064e811;
                if (local_14 == 0) {
                    *reinterpret_cast<int*>(param_1 + 0x30) = local_8;
                } else {
                    *reinterpret_cast<int*>(local_14 + 0x3c) = local_8;
                }
                idx = idx + 1;
                local_14 = local_8;
            } while (idx < *reinterpret_cast<uint32_t*>(param_1 + 0x2c));
        }
    }
    param_1 = iVar6;
    local_8 = 0;
    iVar6 = *reinterpret_cast<int*>(iVar3 + 0x34);
    if (iVar6 != 0) {
        int* piVar7 = reinterpret_cast<int*>(FUN_00533c78(iVar6 * 0x38 + 4));
        if (piVar7 == nullptr) {
            piVar7 = nullptr;
        } else {
            *piVar7 = iVar6;
            piVar7 = piVar7 + 1;
            FUN_004127b0(piVar7, 0x38, iVar6, reinterpret_cast<void*>(&LAB_00646ba7));
        }
        *reinterpret_cast<int**>(iVar3 + 0x38) = piVar7;
        if (piVar7 == nullptr) {
            return -0x7ff8fff2;
        }
    }
    uVar10 = 0;
    if (*reinterpret_cast<int*>(iVar3 + 0x34) != 0) {
        do {
            if (*reinterpret_cast<uint32_t*>(ecx + 0x34) <=
                static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(ecx + 0x30))) {
                return -0x7fffbffb;
            }
            iVar6 = static_cast<int>(uVar10) * 0x38;
            *reinterpret_cast<uint16_t*>(iVar6 + 0x34 + *reinterpret_cast<int*>(iVar3 + 0x38)) =
                *reinterpret_cast<uint16_t*>(ecx + 0x30);
            *reinterpret_cast<uint16_t*>(ecx + 0x30) =
                *reinterpret_cast<uint16_t*>(ecx + 0x30) + 1;
            *reinterpret_cast<uint16_t*>(iVar6 + 0x14 + *reinterpret_cast<int*>(iVar3 + 0x38)) =
                *reinterpret_cast<uint16_t*>(iVar3 + 0x14);
            *reinterpret_cast<uint16_t*>(iVar6 + 0x18 + *reinterpret_cast<int*>(iVar3 + 0x38)) = uVar10;
            param_1 = FUN_0064d308(*reinterpret_cast<int*>(iVar3 + 0x38) + iVar6, param_2, puVar4);
            if (param_1 < 0) {
                return param_1;
            }
            uVar10 = uVar10 + 1;
        } while (static_cast<uint32_t>(uVar10) < *reinterpret_cast<uint32_t*>(iVar3 + 0x34));
    }
    {
        uMax = 0;
        counter1 = 0;
        if (*reinterpret_cast<int*>(iVar3 + 0x34) != 0) {
            do {
                iVar6 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(
                            counter1 * 0x38 + *reinterpret_cast<int*>(iVar3 + 0x38) + 0x34)) * 100;
                if (*reinterpret_cast<int16_t*>(
                        *reinterpret_cast<int*>(ecx + 0x2c) + 0x36 + iVar6) != 0) {
                    local_14 = *reinterpret_cast<uint16_t*>(
                        iVar6 + 0x36 + *reinterpret_cast<int*>(ecx + 0x2c));
                    puVar11 = reinterpret_cast<uint16_t*>(
                        *reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 0x2c) + 4 + iVar6) + 0x54);
                    do {
                        if ((*reinterpret_cast<uint32_t*>(
                                 DAT_006eacac + static_cast<uint32_t>(puVar11[-1]) * 0x1c) &
                             0xff000000u) == 0x8000000u &&
                            uMax < static_cast<uint32_t>(*puVar11)) {
                            uMax = *puVar11;
                        }
                        puVar11 = puVar11 + 0x32;
                        local_14 = local_14 - 1;
                    } while (local_14 != 0);
                }
                counter1 = counter1 + 1;
            } while ((counter1 & 0xffffu) < *reinterpret_cast<uint32_t*>(iVar3 + 0x34));
        }
        uVar5 = uMax * 2 + 2;
        local_c = reinterpret_cast<uint16_t*>(FUN_00533c78(static_cast<int>(uVar5)));
        if (local_c == nullptr) {
LAB_0064e5cc:
            param_1 = -0x7ff8fff2;
        } else {
            {
                uint8_t* pz = reinterpret_cast<uint8_t*>(local_c);
                for (uVar12 = uVar5 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                    *reinterpret_cast<uint32_t*>(pz) = 0;
                    pz = pz + 4;
                }
                for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *pz = 0;
                    pz = pz + 1;
                }
            }
            *reinterpret_cast<uint16_t*>(iVar3 + 0x3c) = 0;
            {
                uint32_t counter = 0;
                if (*reinterpret_cast<int*>(iVar3 + 0x34) != 0) {
                    uVar5 = 0;
                    do {
                        iVar6 = uVar5 * 0x38 + *reinterpret_cast<int*>(iVar3 + 0x38);
                        iVar8 = static_cast<uint32_t>(
                                    *reinterpret_cast<uint16_t*>(iVar6 + 0x34)) * 100;
                        local_14 = 0;
                        if (*reinterpret_cast<int16_t*>(
                                iVar8 + 0x36 + *reinterpret_cast<int*>(ecx + 0x2c)) != 0) {
                            int offset = 0;
                            do {
                                iVar8 = *reinterpret_cast<int*>(
                                            iVar8 + 4 + *reinterpret_cast<int*>(ecx + 0x2c)) + offset;
                                if ((*reinterpret_cast<uint32_t*>(
                                         DAT_006eacac +
                                         static_cast<uint32_t>(
                                             *reinterpret_cast<uint16_t*>(iVar8 + 0x52)) * 0x1c) &
                                     0xff000000u) == 0x8000000u &&
                                    local_c[*reinterpret_cast<uint16_t*>(iVar8 + 0x54)] == 0) {
                                    *reinterpret_cast<uint16_t*>(iVar3 + 0x3c) =
                                        *reinterpret_cast<uint16_t*>(iVar3 + 0x3c) + 1;
                                    local_c[*reinterpret_cast<uint16_t*>(iVar8 + 0x54)] =
                                        *reinterpret_cast<uint16_t*>(iVar3 + 0x3c);
                                }
                                iVar8 = static_cast<uint32_t>(
                                            *reinterpret_cast<uint16_t*>(iVar6 + 0x34)) * 100;
                                local_14 = local_14 + 1;
                                offset = offset + 100;
                            } while (local_14 < *reinterpret_cast<uint16_t*>(
                                         iVar8 + 0x36 + *reinterpret_cast<int*>(ecx + 0x2c)));
                        }
                        counter = counter + 1;
                        uVar5 = counter & 0xffff;
                    } while (uVar5 < *reinterpret_cast<uint32_t*>(iVar3 + 0x34));
                }
            }
            if (*reinterpret_cast<uint16_t*>(iVar3 + 0x3c) != 0) {
                uVar9 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_00533c78(
                    static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(iVar3 + 0x3c)) * 0x68)));
                *reinterpret_cast<uint32_t*>(iVar3 + 0x40) = uVar9;
                local_10 = reinterpret_cast<uint32_t*>(FUN_00533c78(
                    static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(iVar3 + 0x3c)) << 2));
                if (*reinterpret_cast<int*>(iVar3 + 0x40) == 0 || local_10 == nullptr) {
                    goto LAB_0064e5cc;
                }
            }
            *reinterpret_cast<uint32_t*>(iVar3 + 0xa4) = 0;
            *reinterpret_cast<uint32_t*>(iVar3 + 0xa8) = 0;
            *reinterpret_cast<uint32_t*>(iVar3 + 0xac) = 0;
            *reinterpret_cast<uint32_t*>(iVar3 + 0xb0) = 0;
            {
                counter2 = 0;
                if (*reinterpret_cast<int*>(iVar3 + 0x34) != 0) {
                    uVar5 = 0;
                    do {
                        iVar6 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(
                                    uVar5 * 0x38 + 0x34 + *reinterpret_cast<int*>(iVar3 + 0x38))) * 100 +
                                *reinterpret_cast<int*>(ecx + 0x2c);
                        bVar1 = false;
                        {
                            uint32_t* puVar13 = local_10;
                            for (uVar6 = static_cast<uint32_t>(
                                     *reinterpret_cast<uint16_t*>(iVar3 + 0x3c)); uVar6 != 0;
                                 uVar6 = uVar6 - 1) {
                                *puVar13 = 0;
                                puVar13 = puVar13 + 1;
                            }
                            for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                                *reinterpret_cast<uint8_t*>(puVar13) = 0;
                                puVar13 = reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<intptr_t>(puVar13) + 1);
                            }
                        }
                        uVar10 = *reinterpret_cast<uint16_t*>(iVar6 + 0x36);
                        if (uVar10 != 0) {
                            local_18 = static_cast<uint32_t>(uVar10);
                            int offset2 = static_cast<int>(local_18 * 100);
                            do {
                                offset2 = offset2 - 100;
                                iVar8 = *reinterpret_cast<int*>(iVar6 + 4) + offset2;
                                uVar5 = *reinterpret_cast<uint32_t*>(
                                    DAT_006eacac +
                                    static_cast<uint32_t>(
                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x52)) * 0x1c);
                                uVar12 = uVar5 >> 0x18;
                                if (uVar12 == 3) goto LAB_0064e69a;
                                if (uVar12 == 7) {
                                    bVar2 = !bVar1;
                                    bVar1 = true;
                                    *reinterpret_cast<uint32_t*>(iVar8 + 0x30) =
                                        *reinterpret_cast<uint32_t*>(iVar8 + 0x30) ^
                                        ((static_cast<uint32_t>(bVar2) ^
                                          *reinterpret_cast<uint32_t*>(iVar8 + 0x30)) & 1u);
                                } else if (uVar12 == 8) {
                                    uVar10 = static_cast<uint16_t>(
                                        local_c[*reinterpret_cast<uint16_t*>(iVar8 + 0x54)] - 1);
                                    *reinterpret_cast<uint16_t*>(iVar8 + 0x4c) = uVar10;
                                    if (*reinterpret_cast<int*>(iVar8 + 0x58) == 0x800000d) {
                                        *reinterpret_cast<uint32_t*>(iVar8 + 0x30) |= 1u;
                                    } else {
                                        *reinterpret_cast<uint32_t*>(iVar8 + 0x30) =
                                            *reinterpret_cast<uint32_t*>(iVar8 + 0x30) ^
                                            ((static_cast<uint32_t>(
                                                  local_10[uVar10] == 0) ^
                                              *reinterpret_cast<uint32_t*>(iVar8 + 0x30)) & 1u);
                                        local_10[*reinterpret_cast<uint16_t*>(iVar8 + 0x4c)] = 1;
                                    }
                                } else {
                                    if (uVar12 == 9) {
LAB_0064e69a:
                                        uVar10 = *reinterpret_cast<uint16_t*>(iVar8 + 0x54);
                                        if (uVar10 < 0x100) {
                                            uVar5 = static_cast<uint32_t>(uVar10) +
                                                    static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x56));
                                            puVar11 = reinterpret_cast<uint16_t*>(iVar3 + 0xb2);
                                        } else {
                                            if (uVar10 < 0x101) goto LAB_0064e7f8;
                                            uVar5 = (static_cast<uint32_t>(
                                                         *reinterpret_cast<uint16_t*>(iVar8 + 0x56)) -
                                                     0x101) + uVar10;
                                            puVar11 = reinterpret_cast<uint16_t*>(iVar3 + 0xaa);
                                        }
                                    } else if (uVar12 == 0xc) {
                                        if (uVar5 == 0xc000000) {
                                            uVar5 = static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x56)) +
                                                    static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x54));
                                            puVar11 = reinterpret_cast<uint16_t*>(iVar3 + 0xa4);
                                        } else if (uVar5 == 0xc010000) {
                                            uVar5 = static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x56)) +
                                                    static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x54));
                                            puVar11 = reinterpret_cast<uint16_t*>(iVar3 + 0xa6);
                                        } else {
                                            if (uVar5 != 0xc020000) goto LAB_0064e7f8;
                                            uVar5 = static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x56)) +
                                                    static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x54));
                                            puVar11 = reinterpret_cast<uint16_t*>(iVar3 + 0xa8);
                                        }
                                    } else {
                                        if (uVar12 != 0xd) {
                                            if (uVar12 != 0xf) goto LAB_0064e7f8;
                                            goto LAB_0064e69a;
                                        }
                                        if (uVar5 == 0xd000000) {
                                            uVar5 = static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x56)) +
                                                    static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x54));
                                            puVar11 = reinterpret_cast<uint16_t*>(iVar3 + 0xac);
                                        } else if (uVar5 == 0xd010000) {
                                            uVar5 = static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x56)) +
                                                    static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x54));
                                            puVar11 = reinterpret_cast<uint16_t*>(iVar3 + 0xae);
                                        } else {
                                            if (uVar5 != 0xd020000) goto LAB_0064e7f8;
                                            uVar5 = static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x56)) +
                                                    static_cast<uint32_t>(
                                                        *reinterpret_cast<uint16_t*>(iVar8 + 0x54));
                                            puVar11 = reinterpret_cast<uint16_t*>(iVar3 + 0xb0);
                                        }
                                    }
                                    if (static_cast<int>(uVar5) <
                                        static_cast<int>(static_cast<uint32_t>(*puVar11))) {
                                        uVar5 = *puVar11;
                                    }
                                    *puVar11 = static_cast<uint16_t>(uVar5);
                                }
LAB_0064e7f8:
                                local_18 = local_18 - 1;
                            } while (local_18 != 0);
                        }
                        counter2 = counter2 + 1;
                        uVar5 = counter2 & 0xffff;
                        iVar6 = param_1;
                    } while (uVar5 < *reinterpret_cast<uint32_t*>(iVar3 + 0x34));
LAB_0064e811:
                    param_1 = iVar6;
                    if (local_8 != 0) {
                        FUN_00647b9b(1);
                    }
                }
            }
        }
    }
    if (local_c != nullptr) {
        operator_delete(local_c);
    }
    if (local_10 != nullptr) {
        operator_delete(local_10);
    }
    return param_1;
}

// 0x64e847 — observed shape
// Resolves a namespace path against the receiver: either a complemented
// handle (when the low 16 bits are already set), or a linear scan of the
// self+0x98 entries at self+0x9c (0x50 bytes each). Supports '.', '@',
// and '[n]' suffixes; '[n]' bounds-checks n against the entry's +0x10 count
// and recurses with FUN_0064d495.
uint32_t FUN_0064e847(void* self, char* param_1, uint32_t param_2, int param_3)
{
    int ecx = static_cast<int>(reinterpret_cast<intptr_t>(self));
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    char* pcVar4;
    uint32_t uVar5;
    int8_t cVar6;
    int iVar7;
    int iVar8;
    char* pcVar9;
    uint32_t local_c;

    if ((reinterpret_cast<uintptr_t>(param_1) & 0xffff) !=
        reinterpret_cast<uintptr_t>(param_1)) {
        if (0 < reinterpret_cast<intptr_t>(param_1)) {
            local_c = 0;
            if (*reinterpret_cast<int*>(ecx + 0x98) == 0) {
                return 0;
            }
            uVar3 = *reinterpret_cast<uint32_t*>(ecx + 0x9c);
            do {
                iVar8 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(ecx + 0xb0) +
                            *reinterpret_cast<int*>(uVar3 + 0x14) * 4) + 0x40);
                iVar1 = *reinterpret_cast<int*>(uVar3 + 4);
                if (iVar8 == 0) {
                    iVar7 = *reinterpret_cast<int*>(ecx + 0x20);
                } else {
                    iVar7 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 0x38) + 0x10);
                }
                iVar2 = *reinterpret_cast<int*>(iVar1 + 8);
                if (*reinterpret_cast<int*>(iVar2 + iVar7) == 0) {
                    pcVar4 = nullptr;
                } else {
                    if (iVar8 == 0) {
                        iVar8 = *reinterpret_cast<int*>(ecx + 0x20);
                    } else {
                        iVar8 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 0x38) + 0x10);
                    }
                    pcVar4 = reinterpret_cast<char*>(iVar2 + 4 + iVar8);
                }
                pcVar9 = param_1;
                cVar6 = *param_1;
                while (cVar6 == *pcVar4 && cVar6 != '\0') {
                    pcVar9 = pcVar9 + 1;
                    pcVar4 = pcVar4 + 1;
                    cVar6 = *pcVar9;
                }
                cVar6 = *pcVar9;
                if (cVar6 == *pcVar4) {
                    return uVar3;
                }
                if (*pcVar4 == '\0') {
                    if (cVar6 == '.') {
                        pcVar9 = pcVar9 + 1;
                        uVar3 = ~uVar3;
                        goto LAB_0064e9c2;
                    }
                    if (cVar6 == '@') {
                        *reinterpret_cast<uint32_t*>(ecx + 0x118) =
                            *reinterpret_cast<uint32_t*>(ecx + 0x118) ^
                            ((static_cast<uint32_t>(param_3) * 2 ^
                              *reinterpret_cast<uint32_t*>(ecx + 0x118)) & 2u);
                        uVar3 = FUN_0064866e(~uVar3, pcVar9 + 1, static_cast<int>(param_2));
                        *reinterpret_cast<uint32_t*>(ecx + 0x118) &= 0xfffffffd;
                        goto LAB_0064e9c9;
                    }
                    if (cVar6 == '[') {
                        pcVar9 = pcVar9 + 1;
                        if (*pcVar9 < '0') {
                            return 0;
                        }
                        if ('9' < *pcVar9) {
                            return 0;
                        }
                        uVar5 = static_cast<uint32_t>(atoi(pcVar9));
                        if (*reinterpret_cast<uint32_t*>(iVar1 + 0x10) <= uVar5) {
                            return 0;
                        }
                        for (; '/' < *pcVar9 && *pcVar9 < ':'; pcVar9 = pcVar9 + 1) {
                        }
                        if (*pcVar9 == ']') {
                            uVar3 = FUN_0063ed81(~uVar3, uVar5, static_cast<int>(param_2));
                            if (uVar3 != 0) {
                                if (pcVar9[1] == '\0') {
LAB_0064e9d1:
                                    return ~uVar3;
                                }
                                if (pcVar9[1] == '.') {
                                    pcVar9 = pcVar9 + 2;
LAB_0064e9c2:
                                    uVar3 = FUN_0064d495(self, uVar3, pcVar9, static_cast<int>(param_2));
LAB_0064e9c9:
                                    if (uVar3 != 0) goto LAB_0064e9d1;
                                }
                            }
                        }
                        return 0;
                    }
                }
                local_c = local_c + 1;
                uVar3 = uVar3 + 0x50;
                if (*reinterpret_cast<uint32_t*>(ecx + 0x98) <= local_c) {
                    return 0;
                }
            } while (true);
        }
        uVar3 = ~static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
        if (*reinterpret_cast<int*>(uVar3 + 0x10) == 3 &&
            *reinterpret_cast<uint32_t*>(uVar3 + 0x14) <
                *reinterpret_cast<uint32_t*>(ecx + 0xa8)) {
            return uVar3;
        }
    }
    return 0;
}

// 0x64e9d8 — observed shape
// Resolves either a complemented table handle (param_2 == 0) or a name path
// through FUN_0064e847, then complements the selected child handle.
uint32_t FUN_0064e9d8(int param_1, int param_2, uint32_t param_3)
{
    uint32_t uVar1;
    int iVar2;
    int iVar3;

    if (param_2 == 0) {
        if (param_3 < *reinterpret_cast<uint32_t*>(param_1 + 0x98)) {
            uVar1 = ~(*reinterpret_cast<int*>(param_1 + 0x9c) + param_3 * 0x50);
        } else {
            uVar1 = 0;
        }
    } else {
        iVar2 = FUN_0064e847(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)),
                             reinterpret_cast<char*>(static_cast<intptr_t>(param_2)), 1, 0);
        if (((iVar2 == 0) ||
             (iVar3 = *reinterpret_cast<int*>(iVar2 + 4),
              *reinterpret_cast<int*>(iVar3 + 4) != 5)) ||
            ((*reinterpret_cast<int*>(iVar2 + 8) == -1 &&
              *reinterpret_cast<int*>(iVar3 + 0x10) != 0))) {
            uVar1 = 0;
        } else if ((param_3 < *reinterpret_cast<uint32_t*>(iVar3 + 0x14)) &&
                   (*reinterpret_cast<int*>(iVar2 + 0x20) != 0 ||
                    (iVar3 = FUN_00644897(iVar2, *reinterpret_cast<uint32_t*>(iVar3 + 0x14)),
                     -1 < iVar3))) {
            uVar1 = ~(*reinterpret_cast<int*>(iVar2 + 0x20) + param_3 * 0x28);
        } else {
            uVar1 = 0;
        }
    }
    return uVar1;
}

// 0x64ea80 — observed shape
// Case-insensitive namespace lookup returning a complemented element
// handle: scans the self+0x98 entries at self+0x9c (stride 0x50), or, when
// param_2 names a container, walks that container's +0x14 children at
// +0x20 with stride 0x28.
uint32_t FUN_0064ea80(int param_1, uint32_t param_2, char* param_3)
{
    int iVar8 = 0;
    uint32_t uCount = 0;
    uint32_t uVar4 = 0;
    uint32_t uVar6 = 0;

    if (param_2 == 0) {
        uCount = 0;
        uVar4 = 0;
        if (*reinterpret_cast<int*>(param_1 + 0x98) != 0) {
            do {
                int iVar2 = *reinterpret_cast<int*>(param_1 + 0x9c) + iVar8;
                int iVar5;
                if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(param_1 + 0xb0) +
                        *reinterpret_cast<int*>(iVar2 + 0x14) * 4) + 0x40) == 0) {
                    iVar5 = *reinterpret_cast<int*>(param_1 + 0x20);
                } else {
                    iVar5 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x38) + 0x10);
                }
                iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + 0xc);
                char* pcVar3;
                if (*reinterpret_cast<int*>(iVar2 + iVar5) == 0) {
LAB_0064eb12:
                    pcVar3 = param_3;
LAB_0064eb15:
                    if (pcVar3 == nullptr) break;
                } else {
                    if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(param_1 + 0xb0) +
                            *reinterpret_cast<int*>(iVar8 + 0x14 +
                                *reinterpret_cast<int*>(param_1 + 0x9c)) * 4) + 0x40) == 0) {
                        iVar5 = *reinterpret_cast<int*>(param_1 + 0x20);
                    } else {
                        iVar5 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x38) + 0x10);
                    }
                    pcVar3 = reinterpret_cast<char*>(iVar2 + 4 + iVar5);
                    if (pcVar3 == nullptr) goto LAB_0064eb12;
                    if (param_3 != nullptr) {
                        pcVar3 = reinterpret_cast<char*>(
                            static_cast<intptr_t>(_stricmp(pcVar3, param_3)));
                        goto LAB_0064eb15;
                    }
                }
                uCount = uCount + 1;
                iVar8 = iVar8 + 0x50;
            } while (uCount < *reinterpret_cast<uint32_t*>(param_1 + 0x98));
            uVar4 = uCount;
        }
        if (uVar4 != *reinterpret_cast<uint32_t*>(param_1 + 0x98)) {
            uVar4 = *reinterpret_cast<int*>(param_1 + 0x9c) + uVar4 * 0x50;
LAB_0064ec2d:
            return ~uVar4;
        }
    } else {
        int iVar5;
        int iVar2 = FUN_0064e847(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)),
                                 reinterpret_cast<char*>(static_cast<intptr_t>(param_2)), 2, 0);
        if (iVar2 != 0 &&
            (iVar5 = *reinterpret_cast<int*>(iVar2 + 4),
             *reinterpret_cast<int*>(iVar5 + 4) == 5) &&
            (*reinterpret_cast<int*>(iVar2 + 8) != -1 ||
             *reinterpret_cast<int*>(iVar5 + 0x10) == 0)) {
            uVar4 = *reinterpret_cast<uint32_t*>(iVar5 + 0x14);
            if (*reinterpret_cast<int*>(iVar2 + 0x20) != 0 ||
                (iVar5 = FUN_00644897(iVar2, uVar4), -1 < iVar5)) {
                uCount = 0;
                uVar6 = 0;
                if (uVar4 != 0) {
                    do {
                        int iVar5b = *reinterpret_cast<int*>(*reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(param_1 + 0xb0) +
                            *reinterpret_cast<int*>(iVar2 + 0x14) * 4) + 0x40);
                        int iVar7;
                        if (iVar5b == 0) {
                            iVar7 = *reinterpret_cast<int*>(param_1 + 0x20);
                        } else {
                            iVar7 = *reinterpret_cast<int*>(
                                *reinterpret_cast<int*>(param_1 + 0x38) + 0x10);
                        }
                        int iVar1 = *reinterpret_cast<int*>(
                            *reinterpret_cast<int*>(
                                iVar8 + 4 + *reinterpret_cast<int*>(iVar2 + 0x20)) + 0xc);
                        char* pcVar3;
                        if (*reinterpret_cast<int*>(iVar1 + iVar7) == 0) {
LAB_0064ec04:
                            pcVar3 = param_3;
LAB_0064ec08:
                            if (pcVar3 == nullptr) break;
                        } else {
                            if (iVar5b == 0) {
                                iVar5b = *reinterpret_cast<int*>(param_1 + 0x20);
                            } else {
                                iVar5b = *reinterpret_cast<int*>(
                                    *reinterpret_cast<int*>(param_1 + 0x38) + 0x10);
                            }
                            pcVar3 = reinterpret_cast<char*>(iVar1 + 4 + iVar5b);
                            if (pcVar3 == nullptr) goto LAB_0064ec04;
                            if (param_3 != nullptr) {
                                pcVar3 = reinterpret_cast<char*>(
                                    static_cast<intptr_t>(_stricmp(pcVar3, param_3)));
                                goto LAB_0064ec08;
                            }
                        }
                        uCount = uCount + 1;
                        iVar8 = iVar8 + 0x28;
                    } while (uCount < uVar4);
                    uVar6 = uCount;
                }
                if (uVar6 != uVar4) {
                    uVar4 = *reinterpret_cast<int*>(iVar2 + 0x20) + uVar6 * 0x28;
                    goto LAB_0064ec2d;
                }
            }
        }
    }
    return 0;
}

// 0x64ec36 — observed shape
// Activates layout entry param_3 (or the current entry when param_3 is 0):
// deactivates the previous self+0x40 row through FUN_0063da83 with (-1) and
// activates the new one with 1, marks self+0x118 bits 0x40 / 0x800, replays
// FUN_0064d688 over the row, restores the FP control word, then reports
// whether any entry in the FUN_0063ea6b container has a non-zero +0x3a.
uint32_t FUN_0064ec36(int param_1, uint32_t param_2, int param_3)
{
    uint16_t uVar1 = *reinterpret_cast<uint16_t*>(param_1 + 0x42);
    uint32_t uVar6 = 0;
    int iVar3;
    int iVar5;

    if (param_3 != 0) {
        iVar3 = FUN_0063f27d(param_3, 1);
        if (iVar3 == 0) {
            return 0;
        }
        uVar1 = *reinterpret_cast<uint16_t*>(iVar3 + 0x14);
    }
    iVar3 = FUN_0063ea6b(param_2, 10);
    if (iVar3 != 0) {
        uint16_t uVar2 = *reinterpret_cast<uint16_t*>(param_1 + 0x40);
        if (uVar1 != uVar2) {
            if (uVar2 != 0xffff &&
                *reinterpret_cast<int*>(static_cast<uint32_t>(uVar2) * 0xb4 + 0x34 +
                                        *reinterpret_cast<int*>(param_1 + 0xa4)) != 0) {
                int offset = 0;
                do {
                    uint32_t uVar4;
                    if (*reinterpret_cast<uint16_t*>(param_1 + 0x42) ==
                            *reinterpret_cast<uint16_t*>(param_1 + 0x40) &&
                        *reinterpret_cast<uint16_t*>(param_1 + 0x44) == uVar6) {
                        uVar4 = 0xffffffff;
                    } else {
                        uVar4 = 0;
                    }
                    FUN_0063da83(*reinterpret_cast<uint16_t*>(
                        *reinterpret_cast<int*>(
                            static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x40)) * 0xb4 + 0x38 +
                            *reinterpret_cast<int*>(param_1 + 0xa4)) + offset + 0x34),
                        static_cast<int>(uVar4), 0xffffffff);
                    offset = offset + 0x38;
                    uVar6 = uVar6 + 1;
                } while (uVar6 < *reinterpret_cast<uint32_t*>(
                             static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x40)) * 0xb4 + 0x34 +
                             *reinterpret_cast<int*>(param_1 + 0xa4)));
            }
            *reinterpret_cast<uint16_t*>(param_1 + 0x40) = uVar1;
            iVar5 = 0;
            uVar6 = 0;
            if (*reinterpret_cast<int*>(
                    static_cast<uint32_t>(uVar1) * 0xb4 + 0x34 +
                    *reinterpret_cast<int*>(param_1 + 0xa4)) != 0) {
                do {
                    uint32_t uVar4;
                    if (*reinterpret_cast<uint16_t*>(param_1 + 0x42) ==
                            *reinterpret_cast<uint16_t*>(param_1 + 0x40) &&
                        *reinterpret_cast<uint16_t*>(param_1 + 0x44) == uVar6) {
                        uVar4 = 1;
                    } else {
                        uVar4 = 0;
                    }
                    FUN_0063da83(*reinterpret_cast<uint16_t*>(
                        *reinterpret_cast<int*>(
                            static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x40)) * 0xb4 + 0x38 +
                            *reinterpret_cast<int*>(param_1 + 0xa4)) + iVar5 + 0x34),
                        static_cast<int>(uVar4), 1);
                    uVar6 = uVar6 + 1;
                    iVar5 = iVar5 + 0x38;
                } while (uVar6 < *reinterpret_cast<uint32_t*>(
                             static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x40)) * 0xb4 + 0x34 +
                             *reinterpret_cast<int*>(param_1 + 0xa4)));
            }
            *reinterpret_cast<uint32_t*>(param_1 + 0x118) |= 0x40;
        }
        if ((*reinterpret_cast<uint32_t*>(param_1 + 0x118) & 0x40) != 0) {
            *reinterpret_cast<uint32_t*>(param_1 + 0x118) |= 0x800;
            iVar5 = 0;
            uVar6 = 0;
            if (*reinterpret_cast<int*>(
                    static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x40)) * 0xb4 + 0x34 +
                    *reinterpret_cast<int*>(param_1 + 0xa4)) != 0) {
                do {
                    uint32_t uVar4;
                    if (*reinterpret_cast<uint16_t*>(param_1 + 0x42) ==
                            *reinterpret_cast<uint16_t*>(param_1 + 0x40) &&
                        *reinterpret_cast<uint16_t*>(param_1 + 0x44) == uVar6) {
                        uVar4 = 1;
                    } else {
                        uVar4 = 0;
                    }
                    FUN_0064d688(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)),
                                 *reinterpret_cast<uint16_t*>(
                                     *reinterpret_cast<int*>(
                                         static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x40)) * 0xb4 + 0x38 +
                                         *reinterpret_cast<int*>(param_1 + 0xa4)) + iVar5 + 0x34),
                                 static_cast<int>(uVar4));
                    uVar6 = uVar6 + 1;
                    iVar5 = iVar5 + 0x38;
                } while (uVar6 < *reinterpret_cast<uint32_t*>(
                             static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(param_1 + 0x40)) * 0xb4 + 0x34 +
                             *reinterpret_cast<int*>(param_1 + 0xa4)));
            }
            *reinterpret_cast<uint16_t*>(param_1 + 0x118) &= 0xf7bf;
        }
        if ((*reinterpret_cast<uint8_t*>(param_1 + 0x118) & 1) != 0) {
            _controlfp(*reinterpret_cast<uint32_t*>(param_1 + 0x114), 0x30000);
            *reinterpret_cast<uint32_t*>(param_1 + 0x118) &= 0xfffffffe;
        }
        iVar3 = *reinterpret_cast<int*>(iVar3 + 0x34);
        if (iVar3 != 0) {
            iVar5 = *reinterpret_cast<int*>(iVar3 + 0x18);
            do {
                iVar5 = *reinterpret_cast<int*>(iVar5 + 0x1c);
                if (*reinterpret_cast<int16_t*>(
                        static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(iVar5 + 0x14)) * 100 + 0x3a +
                        *reinterpret_cast<int*>(param_1 + 0x2c)) != 0) {
                    return 1;
                }
            } while (*reinterpret_cast<int*>(iVar5 + 0x1c) != iVar3);
        }
    }
    return 0;
}

// 0x64ee64 — observed shape
// Resolves param_2 (a complemented handle when negative, else a name path
// through FUN_0064e847) and fills the 11-dword descriptor at param_3:
// kinds/ids from the +0xc record, names via the self+0xb0/+0x38 string
// tables, the +0x28 and +0x38 metadata words, and the kind-dependent pair at
// param_3[4]/[5]. Unknown kinds or a null descriptor return 0x8876086c.
uint32_t FUN_0064ee64(int param_1, uint32_t param_2, uint32_t* param_3)
{
    uint32_t uVar5;
    uint32_t uVar3;
    uint32_t* piVar6;
    uint32_t* puVar2;
    uint32_t* puVar7;
    int iVar1;
    int iVar4;

    if (param_3 == nullptr) {
        return 0x8876086c;
    }
    if (static_cast<int>(param_2) < 0) {
        param_2 = ~param_2;
    } else {
        param_2 = FUN_0064e847(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)),
                               reinterpret_cast<char*>(static_cast<intptr_t>(param_2)), 1, 0);
        if (param_2 == 0) {
            return 0x8876086c;
        }
    }
    iVar1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0xb0) +
                                    *reinterpret_cast<int*>(param_2 + 0x14) * 4);
    puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(param_2 + 4));
    puVar7 = param_3;
    for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }
    uVar3 = *reinterpret_cast<uint32_t*>(param_2 + 0x14);
    iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0xb0) + uVar3 * 4);
    if ((*reinterpret_cast<uint32_t*>(iVar4 + 0x28) & 1) == 0 &&
        *reinterpret_cast<uint32_t*>(param_1 + 0xac) <= uVar3) {
        iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x11c) +
                                        (uVar3 - *reinterpret_cast<uint32_t*>(param_1 + 0xac)) * 4);
    } else if (*reinterpret_cast<int*>(iVar4 + 0x40) == 0) {
        iVar4 = *reinterpret_cast<int*>(param_1 + 0x20);
    } else {
        iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x38) + 0x10);
    }
    param_3[2] = puVar2[1];
    param_3[3] = puVar2[0];
    if (*reinterpret_cast<int*>(param_2 + 8) == -1) {
        uVar5 = puVar2[4];
    } else {
        uVar5 = 0;
    }
    param_3[6] = uVar5;
    if (*reinterpret_cast<int*>(puVar2[2] + iVar4) == 0) {
        piVar6 = nullptr;
    } else {
        piVar6 = reinterpret_cast<uint32_t*>(
            static_cast<intptr_t>(puVar2[2] + iVar4) + 4);
    }
    *param_3 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar6));
    if (*reinterpret_cast<int*>(iVar4 + puVar2[3]) == 0) {
        piVar6 = nullptr;
    } else {
        piVar6 = reinterpret_cast<uint32_t*>(
            static_cast<intptr_t>(iVar4 + puVar2[3]) + 4);
    }
    param_3[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar6));
    param_3[10] = *reinterpret_cast<uint32_t*>(param_2 + 0xc);
    param_3[9] = *reinterpret_cast<uint32_t*>(iVar1 + 0x28);
    if (*reinterpret_cast<int*>(param_2 + 0x18) == 0 &&
        *reinterpret_cast<int*>(param_2 + 0x1c) == 0 &&
        *reinterpret_cast<int*>(param_2 + 8) == -1) {
        param_3[7] = *reinterpret_cast<uint32_t*>(iVar1 + 0x38);
    } else {
        param_3[7] = 0;
    }
    iVar1 = static_cast<int>(param_3[2]);
    if (iVar1 == 1) {
        param_3[8] = 0;
        param_3[4] = puVar2[6];
        uVar5 = puVar2[5];
LAB_0064efad:
        param_3[5] = uVar5;
    } else {
        if (iVar1 == 4) {
            param_3[8] = 0;
        } else {
            if (iVar1 != 5) {
                param_3[8] = 0;
                param_3[4] = puVar2[5];
                uVar5 = puVar2[6];
                goto LAB_0064efad;
            }
            param_3[8] = puVar2[5];
        }
        param_3[4] = 0;
        param_3[5] = 0;
    }
    return 0;
}

// 0x64efba — observed shape
// Reference-count release on self+0x24; when the count reaches zero the
// object destroys itself through FUN_0064dc1e(delete = 1) and reports 0.
uint32_t FUN_0064efba(int param_1)
{
    int* piVar1 = reinterpret_cast<int*>(param_1 + 0x24);
    uint32_t uVar2;

    *piVar1 = *piVar1 + -1;
    uVar2 = static_cast<uint32_t>(*reinterpret_cast<int*>(param_1 + 0x24));
    if (*piVar1 == 0) {
        // NEEDS_MANUAL: the listing does not expose the ECX receiver of
        // FUN_0064dc1e; the object being released is forwarded.
        FUN_0064dc1e(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)), 1);
        uVar2 = 0;
    }
    return uVar2;
}

// 0x64efd7 — observed shape
// Imports one record into the row at self+0x2c + param_1*100 and the column
// at its +4 table + param_2*100: rejects class words outside
// {0x10, 0xf, 5, 10}, reads a blob (local_8 bytes) from param_3/param_4,
// resolves the blob name through FUN_0064e847, validates the container kind
// against the record's DAT_006eac9c class, copies the 10-dword record, and
// either patches the existing 0x8000000-derived entry or allocates the
// self+0x?? 0x24-byte descriptor before calling FUN_0063e97c.
int FUN_0064efd7(void* self, int param_1, int param_2, int* param_3, uint32_t* param_4)
{
    int ecx = static_cast<int>(reinterpret_cast<intptr_t>(self));
    uint32_t* puVar4 = nullptr;
    uint32_t* puVar6 = nullptr;
    uint32_t* puVar7;
    uint32_t* puVar9;
    int iVar1;
    int iVar3;
    int iVar5;
    uint32_t uVar2;
    uint32_t local_8 = 0;
    int status = 0;
    uint32_t* puVar8;

    iVar1 = param_1 * 100 + *reinterpret_cast<int*>(ecx + 0x2c);
    puVar8 = reinterpret_cast<uint32_t*>(param_2 * 100 + *reinterpret_cast<int*>(iVar1 + 4));
    iVar3 = *reinterpret_cast<int*>(
        DAT_006eac9c +
        static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(
            reinterpret_cast<intptr_t>(puVar8) + 0x52)) * 0x1c);
    if (iVar3 != 0x10 && iVar3 != 0xf && iVar3 != 5 && iVar3 != 10) {
        return -0x7fffbffb;
    }
    if (param_3 != nullptr &&
        static_cast<uint32_t>(vtbl_count(param_3)) >= *param_4 + 1) {
        iVar3 = vtbl_data(param_3);
        local_8 = *reinterpret_cast<uint32_t*>(iVar3 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    if (param_3 == nullptr || static_cast<uint32_t>(vtbl_count(param_3)) < *param_4 ||
        local_8 < 2) {
        return -0x7fffbffb;
    }
    puVar4 = reinterpret_cast<uint32_t*>(FUN_00533c78(static_cast<int>(local_8)));
    if (puVar4 != nullptr) {
        if (local_8 != 0) {
            iVar3 = static_cast<int>((local_8 & 3) != 0) + static_cast<int>(local_8 >> 2);
            uVar2 = static_cast<uint32_t>(vtbl_count(param_3));
            if (*param_4 + iVar3 <= uVar2) {
                iVar5 = vtbl_data(param_3);
                puVar6 = reinterpret_cast<uint32_t*>(iVar5 + *param_4 * 4);
                puVar7 = puVar4;
                for (uVar2 = local_8 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
                    *puVar7 = *puVar6;
                    puVar6 = puVar6 + 1;
                    puVar7 = puVar7 + 1;
                }
                for (uVar2 = local_8 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
                    *reinterpret_cast<uint8_t*>(puVar7) = *reinterpret_cast<uint8_t*>(puVar6);
                    puVar6 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar6) + 1);
                    puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar7) + 1);
                }
            }
            *param_4 = *param_4 + iVar3;
        }
        uVar2 = static_cast<uint32_t>(vtbl_count(param_3));
        if (uVar2 < *param_4) {
            status = static_cast<int>(0x80004005u);
            goto LAB_0064f285;
        }
        if (*reinterpret_cast<char*>(reinterpret_cast<intptr_t>(puVar4) + (local_8 - 1)) != '\0') {
            status = static_cast<int>(0x80004005u);
            goto LAB_0064f285;
        }
        puVar6 = reinterpret_cast<uint32_t*>(FUN_0064e847(
            self, reinterpret_cast<char*>(puVar4), 2, 0));
        if (puVar6 == nullptr) {
LAB_0064f174:
            status = static_cast<int>(0x80004005u);
            goto LAB_0064f285;
        }
        iVar3 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 0xb0) +
                                        static_cast<int>(puVar6[5]) * 4);
        if (*reinterpret_cast<int*>(iVar3 + 0x40) == 0) {
            iVar5 = *reinterpret_cast<int*>(ecx + 0x20);
        } else {
            iVar5 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 0x38) + 0x10);
        }
        iVar3 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar3 + 0x2c) +
                                        static_cast<int>(puVar6[6]) + iVar5);
        puVar8[0xc] = puVar8[0xc] & 0xfffffffd;
        iVar5 = *reinterpret_cast<int*>(
            DAT_006eac9c +
            static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(
                reinterpret_cast<intptr_t>(puVar8) + 0x52)) * 0x1c);
        if (iVar5 == 5) {
            if (iVar3 != 5 && iVar3 != 6 && iVar3 != 7 && iVar3 != 8 && iVar3 != 9) {
                status = static_cast<int>(0x80004005u);
            }
            *puVar8 = 1;
LAB_0064f21b:
            if (status < 0) goto LAB_0064f285;
        } else if (iVar5 == 10) {
            if (iVar3 != 10 && iVar3 != 0xb && iVar3 != 0xc && iVar3 != 0xd && iVar3 != 0xe) {
                status = static_cast<int>(0x80004005u);
            }
            *puVar8 = 0;
            goto LAB_0064f21b;
        } else if (0xe < iVar5 && iVar5 < 0x11) {
            if (iVar5 == iVar3) {
                puVar7 = puVar8 + 2;
                for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *puVar7 = *puVar6;
                    puVar6 = puVar6 + 1;
                    puVar7 = puVar7 + 1;
                }
                *reinterpret_cast<uint16_t*>(puVar8 + 0x15) = 0xffff;
                puVar8[10] = 0;
                puVar8[0xb] = 0;
                *puVar8 = 0;
                *reinterpret_cast<uint16_t*>(
                    reinterpret_cast<intptr_t>(puVar8) + 0x52) = 0xb3;
                puVar8[0x16] = 0xe000000;
                *reinterpret_cast<uint16_t*>(
                    reinterpret_cast<intptr_t>(puVar8) + 0x56) = 1;
                *reinterpret_cast<int16_t*>(iVar1 + 0x34) =
                    *reinterpret_cast<int16_t*>(iVar1 + 0x34) + 1;
                iVar3 = static_cast<int>(*reinterpret_cast<uint32_t*>(iVar1 + 0xc) & 3) +
                        static_cast<int>(*reinterpret_cast<uint32_t*>(iVar1 + 0xc) & 0xfffffffc);
                *reinterpret_cast<int*>(iVar1 + 0xc) = iVar3;
                puVar8[0x12] = static_cast<uint32_t>(iVar3);
                *reinterpret_cast<int*>(iVar1 + 0xc) =
                    *reinterpret_cast<int*>(iVar1 + 0xc) + 4;
                goto LAB_0064f285;
            }
            goto LAB_0064f174;
        }
        puVar7 = puVar6;
        puVar9 = puVar8 + 2;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
        }
        puVar8[10] = 0;
        puVar8[0xb] = 0;
        puVar7 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x24));
        if (puVar7 == nullptr) {
            puVar9 = nullptr;
        } else {
            puVar9 = puVar7 + 1;
            *puVar7 = 1;
            FUN_004127b0(puVar9, 0x20, 1, reinterpret_cast<void*>(&LAB_0063e2de));
        }
        puVar8[0xd] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar9));
        if (puVar9 != nullptr) {
            *reinterpret_cast<uint16_t*>(puVar8 + 0x14) = 1;
            *reinterpret_cast<uint16_t*>(
                reinterpret_cast<intptr_t>(puVar8) + 0x4e) = 1;
            status = FUN_0063e97c(param_1, param_2, 0, puVar6, 0);
            goto LAB_0064f285;
        }
    }
    status = static_cast<int>(0x8007000eu);
LAB_0064f285:
    if (puVar4 != nullptr) {
        operator_delete(puVar4);
    }
    return status;
}

// 0x64f29e — observed shape
// Variant of FUN_0064efd7 for records that also carry an embedded blob:
// reads two dwords from the stream (local_c, local_8), copies local_8 bytes,
// resolves the name, fills the 10-dword record, builds the 0x20 dword
// descriptor at self+0xe through FUN_006294f9, writes the vtable-backed
// payload, copies the trailing blob, and finishes through FUN_0060afb7 /
// FUN_006439a7. Returns 0x8007000e / 0x80004005 / 0x8876086c codes on failure.
int FUN_0064f29e(void* self, int param_1, int param_2, int* param_3, uint32_t* param_4)
{
    int ecx = static_cast<int>(reinterpret_cast<intptr_t>(self));
    int* piVar1;
    uint32_t uVar3;
    uint32_t uVar8;
    int iVar2;
    int iVar4;
    int iVar6;
    uint32_t* puVar5 = nullptr;
    uint32_t* puVar7;
    uint32_t* puVar9;
    uint32_t* puVar10;
    uint32_t* puVar11;
    int local_c = 0;
    uint32_t local_8 = 0;

    iVar2 = param_1 * 100 + *reinterpret_cast<int*>(ecx + 0x2c);
    puVar9 = reinterpret_cast<uint32_t*>(param_2 * 100 + *reinterpret_cast<int*>(iVar2 + 4));
    if (param_3 != nullptr && static_cast<uint32_t>(vtbl_count(param_3)) >= *param_4 + 1) {
        iVar4 = vtbl_data(param_3);
        local_c = *reinterpret_cast<int*>(iVar4 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    if (param_3 != nullptr && static_cast<uint32_t>(vtbl_count(param_3)) >= *param_4 + 1) {
        iVar4 = vtbl_data(param_3);
        local_8 = *reinterpret_cast<uint32_t*>(iVar4 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    if (param_3 == nullptr || static_cast<uint32_t>(vtbl_count(param_3)) < *param_4 ||
        local_8 < 2) {
        return -0x7fffbffb;
    }
    puVar5 = reinterpret_cast<uint32_t*>(FUN_00533c78(static_cast<int>(local_8)));
    if (puVar5 == nullptr) {
        local_8 = static_cast<uint32_t>(-0x7ff8fff2);
        goto LAB_0064f535;
    }
    if (local_8 != 0) {
        iVar4 = static_cast<int>((local_8 & 3) != 0) + static_cast<int>(local_8 >> 2);
        uVar3 = static_cast<uint32_t>(vtbl_count(param_3));
        if (*param_4 + iVar4 <= uVar3) {
            iVar6 = vtbl_data(param_3);
            puVar7 = reinterpret_cast<uint32_t*>(iVar6 + *param_4 * 4);
            puVar10 = puVar5;
            for (uVar3 = local_8 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar10 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar10 = puVar10 + 1;
            }
            for (uVar3 = local_8 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *reinterpret_cast<uint8_t*>(puVar10) = *reinterpret_cast<uint8_t*>(puVar7);
                puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar7) + 1);
                puVar10 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar10) + 1);
            }
        }
        *param_4 = *param_4 + iVar4;
    }
    uVar3 = static_cast<uint32_t>(vtbl_count(param_3));
    if (*param_4 <= uVar3 &&
        *reinterpret_cast<char*>(reinterpret_cast<intptr_t>(puVar5) + (local_8 - 1)) == '\0' &&
        (puVar7 = reinterpret_cast<uint32_t*>(FUN_0064e847(
             self, reinterpret_cast<char*>(puVar5), 2, 0)), puVar7 != nullptr)) {
        puVar10 = puVar9 + 2;
        for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar10 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar10 = puVar10 + 1;
        }
        puVar9[10] = 0;
        puVar9[0xb] = 0;
        *reinterpret_cast<uint16_t*>(puVar9 + 0x15) = 0xffff;
        puVar9[0xc] = puVar9[0xc] & 0xfffffffd;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<intptr_t>(puVar9) + 0x56) = 1;
        *puVar9 = 1;
        uVar3 = static_cast<uint32_t>(local_c + (-4 - static_cast<int>(local_8)));
        *reinterpret_cast<uint16_t*>(reinterpret_cast<intptr_t>(puVar9) + 0x52) = 0xb3;
        puVar9[0x16] = 0xe000000;
        *reinterpret_cast<int16_t*>(iVar2 + 0x34) =
            *reinterpret_cast<int16_t*>(iVar2 + 0x34) + 1;
        local_8 = static_cast<uint32_t>(FUN_006294f9(uVar3 + 0x20, puVar9 + 0xe));
        if (static_cast<int>(local_8) < 0) goto LAB_0064f535;
        piVar1 = reinterpret_cast<int*>(static_cast<intptr_t>(puVar9[0xe]));
        puVar7 = reinterpret_cast<uint32_t*>(
            (*reinterpret_cast<int(*)(int*)>(
                *reinterpret_cast<void**>(static_cast<uintptr_t>(*piVar1) + 0xc)))(piVar1));
        puVar7[2] = 0;
        *puVar7 = 1;
        puVar7[1] = 3;
        iVar4 = static_cast<int>(*reinterpret_cast<uint32_t*>(iVar2 + 0xc) & 7) +
                static_cast<int>(*reinterpret_cast<uint32_t*>(iVar2 + 0xc) & 0xfffffff8);
        *reinterpret_cast<int*>(iVar2 + 0xc) = iVar4;
        puVar7[3] = static_cast<uint32_t>(iVar4);
        uVar8 = static_cast<uint32_t>(*reinterpret_cast<int*>(iVar2 + 0xc) + 0x20);
        iVar4 = static_cast<int>(uVar8 & 3) + static_cast<int>(uVar8 & 0xfffffffc);
        *reinterpret_cast<int*>(iVar2 + 0xc) = iVar4;
        puVar9[0x12] = static_cast<uint32_t>(iVar4);
        *reinterpret_cast<int*>(iVar2 + 0xc) =
            *reinterpret_cast<int*>(iVar2 + 0xc) + 4;
        if (uVar3 == 0) goto LAB_0064f535;
        iVar2 = static_cast<int>((uVar3 & 3) != 0) + static_cast<int>(uVar3 >> 2);
        uVar8 = static_cast<uint32_t>(vtbl_count(param_3));
        if (*param_4 + iVar2 <= uVar8) {
            iVar4 = vtbl_data(param_3);
            puVar10 = reinterpret_cast<uint32_t*>(iVar4 + *param_4 * 4);
            puVar11 = puVar7 + 8;
            for (uVar8 = uVar3 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar11 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar11 = puVar11 + 1;
            }
            for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *reinterpret_cast<uint8_t*>(puVar11) = *reinterpret_cast<uint8_t*>(puVar10);
                puVar10 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar10) + 1);
                puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar11) + 1);
            }
        }
        *param_4 = *param_4 + iVar2;
        local_8 = static_cast<uint32_t>(FUN_0060afb7(puVar7 + 8, puVar9 + 0x10, puVar9 + 0x11));
        if (static_cast<int>(local_8) < 0) goto LAB_0064f535;
        uVar3 = static_cast<uint32_t>(vtbl_count(param_3));
        if (*param_4 <= uVar3) {
            local_8 = static_cast<uint32_t>(FUN_0060afb7(puVar7 + 8, puVar9 + 0x10, puVar9 + 0x11));
            if (static_cast<int>(local_8) > -1) {
                local_8 = static_cast<uint32_t>(FUN_006439a7(param_1, param_2, puVar7));
            }
            goto LAB_0064f535;
        }
    }
    local_8 = static_cast<uint32_t>(-0x7fffbffb);
LAB_0064f535:
    if (puVar5 != nullptr) {
        operator_delete(puVar5);
    }
    return static_cast<int>(local_8);
}

// 0x64f54e — observed shape
// Resolves param_2 (complemented handle when negative, else a name path),
// validates param_4 against the record's +0xc dword, then either dispatches
// to FUN_006498da when self+0x3c == 3 or binds through FUN_00644c1f and
// finishes with FUN_006431b5.
int FUN_0064f54e(void* self, int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    // NEEDS_MANUAL: the listing does not surface the ECX receiver that
    // FUN_0064e847 requires; it is captured as `self`.
    int iVar1;

    if (static_cast<int>(param_2) < 0) {
        param_2 = ~param_2;
    } else {
        param_2 = FUN_0064e847(reinterpret_cast<void*>(static_cast<intptr_t>(self)),
                               reinterpret_cast<char*>(static_cast<intptr_t>(param_2)), 1, 0);
        if (param_2 == 0) {
            return -0x7789f794;
        }
    }
    if (param_4 != 0xffffffff && param_4 < *reinterpret_cast<uint32_t*>(param_2 + 0xc)) {
        return -0x7789f794;
    }
    if (*reinterpret_cast<int*>(param_1 + 0x3c) == 3) {
        iVar1 = FUN_006498da(~param_2, param_3, param_4);
        return iVar1;
    }
    iVar1 = FUN_00644c1f(param_2, param_3);
    if (iVar1 < 0) {
        return iVar1;
    }
    iVar1 = FUN_006431b5(param_2);
    return iVar1;
}
