// Reconstruction batch mass_0028 — Sid Meier's Pirates! (2004), PE32 i386.
// Each definition below corresponds to one assigned Ghidra address.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern helpers referenced by the assigned listings.
// ---------------------------------------------------------------------------
extern void FUN_004891a0(...);
extern void FUN_004890c0(...);
extern void FUN_00489130(...);
extern void FUN_00489210(...);
extern void FUN_00489040(...);
extern void FUN_00488fc0(...);
extern void FUN_00488b00(...);
extern void FUN_00488a80(...);
extern void FUN_004888e0(...);
extern void FUN_00488840(...);
extern void FUN_004888b0(...);
extern void FUN_00488d90(...);
extern void FUN_00488e50(...);
extern void FUN_00488ed0(...);
extern void FUN_004889c0(...);
extern void FUN_004985e0(...);
extern void FUN_004a14b0(...);
extern void FUN_004986e0(...);
extern void FUN_004987a0(...);
extern void FUN_00498850(...);
extern void FUN_004a0d90(...);
extern void FUN_004a0df0(...);
extern void FUN_004a1090(...);
extern void FUN_004a0b70(...);
extern void FUN_0049af70(...);
extern void FUN_0049aed0(...);
extern void FUN_0049f930(...);
extern void FUN_004a0100(...);
extern void FUN_004a0430(...);
extern void FUN_00491640(...);
extern void FUN_004bbc10(...);
extern void FUN_004baaa0(...);
extern void FUN_00475810(...);
extern void FUN_004e85c0(...);
extern uint32_t FUN_005f0ddc(...);

// ---------------------------------------------------------------------------
// Globals used by the assigned listings (observed DAT_ addresses).
// ---------------------------------------------------------------------------
extern uint32_t DAT_008ecd78;
extern char DAT_008cac27;
extern char DAT_008cac26;
extern int DAT_008e8ec4;
extern int DAT_008e8ec8;
extern int DAT_008e8eec;
extern int DAT_008e8ef0;
extern int DAT_008e8ef4;
extern char DAT_008e8eff;
extern int* DAT_008ed2c8;
extern int _DAT_008ed61c;
extern int DAT_008ed618;
extern int32_t DAT_0085a164;
extern int DAT_0085a7f0;
extern int DAT_0085a7b0;
extern int DAT_0085a7d0;
extern int DAT_0085a830;
extern char DAT_0085a164_lo;
extern int DAT_008c81f0;
extern int DAT_008c81f1;
extern int DAT_008c81f2;
extern int DAT_008c81f3;
extern int DAT_008c81f4;
extern int DAT_008c8208;
extern int DAT_008c8204;
extern int DAT_008c8214;
extern int DAT_008c8218;
extern int DAT_008c8228;
extern int DAT_008c822c;
extern int DAT_008c8230;
extern int DAT_008c8234;
extern int DAT_008c8238;
extern int DAT_008c823c;
extern int DAT_008c8240;
extern int DAT_008c8248;
extern int DAT_008c824c;
extern int DAT_008c8250;
extern int DAT_008c8254;
extern int DAT_008c8258;
extern int DAT_008c825c;
extern int DAT_008c8260;
extern int DAT_008c8264;
extern int DAT_008c826c;
extern int DAT_008c827d;
extern int DAT_008c8200;
extern int DAT_008c81fc;
extern int DAT_008c81f4_raw;
extern int DAT_008c78a0;
extern int DAT_008c78a4;
extern int DAT_008c78ac;
extern int DAT_008c78b0;
extern int DAT_008c7888;
extern int DAT_008c78b0_arr[0x100];
extern int DAT_008c78b8_arr[0x100];
extern int DAT_008c78bc_arr[0x100];
extern int DAT_008c7890;
extern int DAT_008c7894;
extern int DAT_008c7898;
extern int DAT_008c789c;
extern int DAT_008c78a4_arr[0x100];
extern int DAT_008c78a0_arr[0x100];
extern int DAT_008c2330_arr[0x100];
extern int DAT_008c2334_arr[0x100];
extern int DAT_008c240c_arr[0x100];
extern int DAT_008c63a0_arr[0x100];
extern byte DAT_008c78f0_arr[0x1000];
extern int DAT_008cc618;
extern int DAT_008ed4e8;
extern int DAT_008e9fd8;
extern int DAT_008e67b0;
extern int DAT_0072cd78;
extern int DAT_00814304;
extern int DAT_00814308;
extern int DAT_008bd728;
extern int DAT_008bd72c;
extern int DAT_008ed4e8_arr[0x100];
extern int DAT_008ed4ec_arr[0x100];
extern int DAT_008ed4f0_arr[0x100];
extern int DAT_008ed4f4_arr[0x100];
extern int DAT_008ed4f8_arr[0x100];
extern int DAT_008ed4fc_arr[0x100];
extern int DAT_008ed500_arr[0x100];
extern int DAT_008ed504_arr[0x100];
extern int DAT_008ed508_arr[0x100];
extern int DAT_008ed50c_arr[0x100];
extern int DAT_008c73ba;
extern int DAT_008c73b9;
extern int DAT_008c73b8;
extern int DAT_008c73c4;
extern int DAT_008c73c8;
extern int DAT_008c73bc;
extern int DAT_008c73c0;
extern int DAT_008c73dc;
extern int DAT_008c84b0;
extern int DAT_008142fa;
extern int DAT_008c740c_arr[0x200];
extern int DAT_008b9a14_arr[0x200];
extern int DAT_008c73cc_arr[0x100];
extern int DAT_008c73f4_arr[0x100];
extern int DAT_008c73a8_arr[0x100];
extern int _DAT_008c825c;
extern int _DAT_008ed4ec;
extern int _DAT_008ed4f0;
extern int _DAT_008ed4f4;
extern int _DAT_008ed4f8;
extern int _DAT_008ed4fc;
extern int _DAT_008ed500;
extern int _DAT_008ed504;
extern int _DAT_008ed508;
extern int _DAT_008ed50c;
extern int _DAT_008c739c;
extern int _DAT_008c73bc;
extern int _DAT_008c73c0;
extern int DAT_008c8248_f;
extern int DAT_008c8234_f;
extern int DAT_0085a164_b;
extern int DAT_008c78f0_base;
extern int DAT_008c78b8_base;
extern int DAT_008c78bc_base;
extern int DAT_008c2334_base;

// Forward declarations for intra-batch calls (defined below).
extern void FUN_004a39e0();
extern void FUN_004a4910();
extern void FUN_004a49c0();
extern void FUN_004a3b20();
extern void FUN_004a3db0();
extern void FUN_004a3f10();
extern void FUN_004a2c20();
extern void FUN_004a14b0();

// 0x4a24b0 — observed shape
// Boot sequence: gated spin/Sleep poll, then resets globals, runs a table of
// init helpers, loops a table from 0x8c78bc stepping 3 ints while < 0x8c78f8,
// and conditionally triggers audio-ish init paths.
void FUN_004a24b0() {
    char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0 && (DAT_008cac27 == 0 || DAT_008cac26 != 0)) {
        while (true) {
            int iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
            if (iVar2 < 0) iVar2 += 100;
            if (iVar2 == 0) break;
            Sleep(0x28);
        }
        FUN_004a0d90();
        FUN_0049af70();
        FUN_0049aed0();
    }
    _DAT_008c825c = 0;
    DAT_008c8208 = 0xffffffff;
    DAT_008c8204 = 0;
    DAT_008c8200 = 0xffffffff;
    DAT_008c81fc = 0xffffffff;
    DAT_008c81f4 = 0;
    DAT_008c81f3 = 0;
    DAT_008c81f2 = 0;
    DAT_008c81f1 = 0;
    FUN_004891a0();
    FUN_004891a0();
    FUN_004891a0();
    FUN_004891a0();
    FUN_004890c0();
    FUN_004890c0();
    FUN_004890c0();
    FUN_004890c0();
    FUN_004890c0();
    FUN_004891a0();
    FUN_004891a0(&DAT_008c8250);
    FUN_004891a0(&DAT_008c8258);
    FUN_004890c0(&DAT_008c8234);
    FUN_004890c0(&DAT_008c8230);
    FUN_004890c0(&DAT_008c822c);
    FUN_004891a0(&DAT_008c824c);
    FUN_004890c0();
    int32_t* puVar3 = reinterpret_cast<int32_t*>(&DAT_008c78bc_arr[0]);
    do {
        FUN_004891a0();
        puVar3[-1] = static_cast<int32_t>(0xffffffff);
        puVar3[0] = static_cast<int32_t>(0xffffffff);
        puVar3 = puVar3 + 3;
    } while (reinterpret_cast<intptr_t>(puVar3) < 0x8c78f8);
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004888e0();
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
    FUN_004888e0();
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
    if (DAT_008e8eff == 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_0049f930(&DAT_008e67b0, 0x19, 0);
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_0049f930(&DAT_008e67b0, 0x1e, 0);
    }
    if (DAT_0085a164 < 0) {
        FUN_004a3db0(0);
        DAT_008c81f1 = 1;
    }
    if (DAT_008c81f0 != 0) {
        FUN_004888e0();
        DAT_008c81f0 = 0;
        DAT_008c827d = 0;
    }
}

// 0x4a29c0 — observed shape
// Resets a table of 0x008c78bc with stride 3, zeroes a block of DAT_008ed4xx
// globals, gated spin poll then queue manipulation.
void FUN_004a29c0() {
    if (DAT_0085a164 < 0) {
        FUN_004a3f10();
    }
    FUN_004a2c20();
    DAT_008c81f1 = 0;
    DAT_008c827d = 1;
    FUN_00489130(&DAT_008c8228);
    FUN_00489130(&DAT_008c8248);
    FUN_00489210(&DAT_008c826c);
    FUN_00489210(&DAT_008c8264);
    FUN_00489210(&DAT_008c8260);
    FUN_00489210(&DAT_008c825c);
    FUN_00489130(&DAT_008c8240);
    FUN_00489130(&DAT_008c823c);
    FUN_00489130(&DAT_008c8238);
    FUN_00489210(&DAT_008c8254);
    FUN_00489210(&DAT_008c8258);
    FUN_00489130(&DAT_008c8234);
    FUN_00489130(&DAT_008c822c);
    FUN_00489210(&DAT_008c824c);
    FUN_00489040(&DAT_008c8250, 0x1e, 0x3e800000);
    FUN_00488fc0(&DAT_008c8230, 0x69, 0x3e800000);
    int32_t* puVar4 = reinterpret_cast<int32_t*>(&DAT_008c78bc_arr[0]);
    do {
        FUN_00489210(puVar4 - 2);
        puVar4[-1] = static_cast<int32_t>(0xffffffff);
        puVar4[0] = static_cast<int32_t>(0xffffffff);
        puVar4 = puVar4 + 3;
    } while (reinterpret_cast<intptr_t>(puVar4) < 0x8c78f8);
    FUN_004986e0(&DAT_008e67b0, 0);
    _DAT_008ed4ec = 0;
    _DAT_008ed4f0 = 0;
    _DAT_008ed4f4 = 0;
    _DAT_008ed4f8 = 0;
    _DAT_008ed4fc = 0;
    _DAT_008ed500 = 0;
    _DAT_008ed504 = 0;
    _DAT_008ed508 = 0;
    DAT_008ed4e8 = 0;
    _DAT_008ed50c = 0;
    char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0 && (DAT_008cac27 == 0 || DAT_008cac26 != 0)) {
        while (true) {
            int iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
            if (iVar2 < 0) iVar2 += 100;
            if (iVar2 == 0) break;
            Sleep(0x28);
        }
        if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec) >> 2 != 0)) {
            DAT_008e8ef0 = DAT_008e8ef0 - 4;
        }
        FUN_0049af70(*DAT_008ed2c8, 0);
        uint32_t uVar3 = (uint32_t)FUN_004a0b70(0xfffffffe);
        FUN_0049aed0(uVar3, 0xfffffffe);
    }
}

// 0x4a2c20 — observed shape
void FUN_004a2c20() {
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_00488fc0(&DAT_008c8248, 0x5e, 0x3f000000);
    FUN_00488fc0(&DAT_008c8240, 0x61, 0xbf800000);
    FUN_00488fc0(&DAT_008c8238, 100, 0xbf800000);
    FUN_00489040(&DAT_008c8254, 0x19, 0xbf800000);
    FUN_00489040(&DAT_008c825c, 0x18, 0xbf800000);
    FUN_00489040(&DAT_008c8258, 0x16, 0xbf800000);
}

// 0x4a2d50 — observed shape
// Two ints; uses DAT_0085a164 sign branch, position math at +0x5c/+0x60/+0x64,
// calls FUN_004baaa0, timeGetTime accumulation gated at 0xfb, audio branch.
void FUN_004a2d50(int param_1, int param_2) {
    float local_8c = 0.0f, local_88 = 0.0f, local_84 = 0.0f;
    float local_80 = 0.0f, local_7c = 0.0f, local_78 = 0.0f;
    int local_ac = 0;
    if (param_1 != 0 && DAT_008e9fd8 != 0) {
        if (DAT_0085a164 < 0) {
            local_ac = DAT_0085a7f0;
            if (DAT_0085a7f0 == 0) local_ac = -10;
            local_8c = static_cast<float>(DAT_0085a7b0 / 1000);
            local_88 = static_cast<float>(DAT_0085a7d0 / 1000);
            local_84 = static_cast<float>(local_ac);
        } else {
            int iVar6 = FUN_004baaa0();
            local_8c = *reinterpret_cast<float*>(iVar6 + 0x5c);
            local_88 = *reinterpret_cast<float*>(iVar6 + 0x60);
            local_84 = *reinterpret_cast<float*>(iVar6 + 100);
        }
        local_80 = local_8c - *reinterpret_cast<float*>(DAT_008e9fd8 + 0x5c);
        local_7c = local_88 - *reinterpret_cast<float*>(DAT_008e9fd8 + 0x60);
        local_78 = 0.0f;
        FUN_00491640();
        FUN_004985e0();
        FUN_004a14b0();
        FUN_004987a0(&DAT_008e67b0, local_80, local_7c, 0.0f, 0x80000000, 0x80000000, 0xbf800000);
        FUN_004a39e0();
        if (DAT_008ed4e8 != 0) {
            uint32_t uVar2 = FUN_005f0ddc();
            uint32_t uVar3 = FUN_005f0ddc(uVar2, 0, 0, 0, 0xffffffff, 0);
            uint32_t uVar4 = FUN_005f0ddc(uVar3);
            FUN_004bbc10(&DAT_008cc618, uVar4, uVar3, uVar2, 0, 0, 0, 0xffffffff, 0);
            uVar3 = FUN_005f0ddc(uVar2, 0, 0, 0, 0xffffffff, 0);
            uVar4 = FUN_005f0ddc(uVar3);
            FUN_004bbc10(&DAT_008cc618, uVar4, uVar3, uVar2, 0, 0, 0, 0xffffffff, 0);
            uint32_t uVar5 = FUN_005f0ddc(0, 0, 0, 0xffffffff, 0);
            uVar3 = FUN_005f0ddc(uVar5);
            uVar4 = FUN_005f0ddc(uVar3);
            FUN_004bbc10(&DAT_008cc618, uVar4, uVar3, uVar5, 0, 0, 0, 0xffffffff, 0);
            int iVar6 = FUN_004baaa0();
            local_80 = *reinterpret_cast<float*>(iVar6 + 0x6c);
            local_7c = *reinterpret_cast<float*>(iVar6 + 0x78);
            local_78 = *reinterpret_cast<float*>(iVar6 + 0x84);
            uint32_t uVar5b = FUN_005f0ddc(uVar2, 0, 0, 0, 0xffffffff, 0);
            uint32_t uVar3b = FUN_005f0ddc(uVar5b);
            FUN_004bbc10(&DAT_008cc618, uVar3b, uVar5b, uVar2, 0, 0, 0, 0xffffffff, 0);
        }
    }
    if (DAT_0085a164 < 0) {
        if (DAT_008c8208 == DAT_0085a830) {
            if (DAT_008c8208 == 1) {
                local_ac = DAT_0085a7f0;
                if (DAT_0085a7f0 == 0) local_ac = -10;
                FUN_004a0100(&DAT_008e67b0, static_cast<float>(DAT_0085a7b0 / 1000),
                             static_cast<float>(DAT_0085a7d0 / 1000),
                             static_cast<float>(local_ac), 1);
            }
        } else if (DAT_008c8208 == 1) {
            FUN_00489040(&DAT_008c825c, 0x18, 0x3f800000);
        } else if (DAT_0085a830 == 1) {
            local_ac = DAT_0085a7f0;
            if (DAT_0085a7f0 == 0) local_ac = -10;
            FUN_00488b00(&DAT_008c825c, 0x18, static_cast<float>(DAT_0085a7b0 / 1000),
                         static_cast<float>(DAT_0085a7d0 / 1000),
                         static_cast<float>(local_ac), 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        }
        DAT_008c8208 = DAT_0085a830;
        DAT_008c81f1 = 1;
    } else if (DAT_008c81f1 != 0) {
        FUN_00489040(&DAT_008c825c, 0x18, 0xbf800000);
        DAT_008c81f1 = 0;
    }
    if (DAT_008c8204 < 0xfb) {
        if ((_DAT_008ed61c & 1) == 0) {
            _DAT_008ed61c = _DAT_008ed61c | 1;
            DAT_008ed618 = static_cast<int>(timeGetTime());
        }
        DWORD DVar7 = timeGetTime();
        DAT_008c8204 = DAT_008c8204 + static_cast<int>(DVar7 - DAT_008ed618);
    } else {
        DAT_008c8204 = 0;
        float local_74 = 2000.0f;
        if ((DAT_0085a164 & 0x80) == 0) local_74 = 3000.0f;
        float local_a8 = 750.0f;
        if ((DAT_0085a164 & 0x80) == 0) local_a8 = 300.0f;
        float fVar8 = static_cast<float>(FUN_004e85c0(DAT_0072cd78, local_8c, local_88, local_74));
        if ((local_a8 <= fVar8) && (fVar8 <= local_74)) {
            FUN_005f0ddc();
        }
        FUN_004985e0();
        FUN_004a14b0();
        char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
        if (cVar1 != 0) {
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
    if (param_2 != -1) {
        FUN_005f0ddc();
        FUN_005f0ddc();
        char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
        if (cVar1 != 0) {
            FUN_004985e0();
            FUN_004a14b0();
        }
        cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
        if (cVar1 != 0) {
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
    if (DAT_008c81f4 == 0) {
        if (DAT_008c81f3 != 0) {
            FUN_00489040(&DAT_008c8258, 0x16, 0xbf800000);
        }
    } else if (DAT_008c81f3 == 0) {
        FUN_00488a80(0x16, local_80 * 1000.0f + local_8c, local_88 + local_7c * 1000.0f,
                     local_84 + local_78 * 1000.0f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                     &DAT_008c8258, 0xbf800000, 0xffffffff);
    } else {
        char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
        if (cVar1 != 0) {
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
    DAT_008c81f3 = DAT_008c81f4;
    int iVar6 = FUN_00475810();
    if (iVar6 == -1) {
        if (DAT_008c81f2 != 0) {
            FUN_00488e50(0x67, 0x40400000);
            DAT_008c81f2 = 0;
        }
    } else if (DAT_008c81f2 == 0) {
        FUN_004a3b20();
        DAT_008c81f2 = 1;
    }
}

// 0x4a3790 — observed shape
// Register-receiver function (in_ECX/in_EAX); branches on signed ranges,
// DAT_0085a164 & 0x40 selects 0x12/0x13 audio ids.
void FUN_004a3790(void* /*self*/, int in_ECX, int in_EAX) {
    if (in_ECX < 1) {
        if (in_ECX < 0) {
            if (0 < in_EAX) {
                if ((DAT_0085a164 & 0x40) == 0) {
                    FUN_00488a80(0x12, 0xbf800000, 0xbf800000, 0xbf800000, 0x14, 0xffffff38, 0xffffffff, 0xffffffff, &DAT_008c8264, 0xbf800000, 0xffffffff);
                    return;
                }
                FUN_00488a80(0x13, 0xbf800000, 0xbf800000, 0xbf800000, 0x28, 0xffffff38, 0xffffffff, 0xffffffff, &DAT_008c8264, 0xbf800000, 0xffffffff);
                return;
            }
            if (in_EAX == 0) {
                if ((DAT_0085a164 & 0x40) != 0) {
                    FUN_00488b00(&DAT_008c8264, 0x13, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
                    return;
                }
                FUN_00488b00(&DAT_008c8264, 0x12, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            }
        }
    } else {
        if (in_EAX < 0) {
            if ((DAT_0085a164 & 0x40) == 0) {
                FUN_00488a80(0x12, 0xbf800000, 0xbf800000, 0xbf800000, 0x14, 0xffffff38, 0xffffffff, 0xffffffff, &DAT_008c8264, 0xbf800000, 0xffffffff);
                return;
            }
            FUN_00488a80(0x13, 0xbf800000, 0xbf800000, 0xbf800000, 0x28, 0xffffff38, 0xffffffff, 0xffffffff, &DAT_008c8264, 0xbf800000, 0xffffffff);
            return;
        }
        if (in_EAX == 0) {
            if ((DAT_0085a164 & 0x40) == 0) {
                FUN_00488b00(&DAT_008c8264, 0x12, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
                return;
            }
            FUN_00488b00(&DAT_008c8264, 0x13, 0xbf800000, 0xbf800000, 0xbf800000, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            return;
        }
    }
}

// 0x4a39e0 — observed shape
// Switch on DAT_008c8218 with audio transitions keyed on DAT_008c8214.
void FUN_004a39e0() {
    switch (DAT_008c8218) {
    case 1:
        if ((DAT_008c8214 == 2) && (DAT_008c8248 != 0)) {
            FUN_00488fc0(&DAT_008c8248, 0x5e, 0x3f000000);
            DAT_008c8214 = DAT_008c8218;
            return;
        }
        break;
    case 2:
        if (DAT_008c8214 == 3) {
            FUN_004a0430(&DAT_008e67b0, 0x40000000);
        }
        if (DAT_008c8214 != 2) {
            FUN_004889c0(&DAT_008c8248, 0x5e, 0xffffffff, 0xffffffff, 0xffffffff, 0x3f000000, 0xffffffff);
            DAT_008c8214 = DAT_008c8218;
            return;
        }
        break;
    case 3:
        if ((DAT_008c8214 != 3) && (DAT_008e8eff == 0)) {
            FUN_004985e0();
            FUN_004a14b0();
        }
        break;
    default:
        break;
    }
    DAT_008c8214 = DAT_008c8218;
}

// 0x4a3b20 — observed shape
// Register-receiver (in_EAX at +0xc/+0x10) audio cue keyed on vtable dispatch.
void FUN_004a3b20(void* self, int in_EAX) {
    (void)self;
    FUN_00488fc0(&DAT_008c8234, 0x68, 0);
    DAT_008c827d = 1;
    FUN_00488a80(0x1a, static_cast<float>(*reinterpret_cast<int*>(in_EAX + 0xc)),
                 static_cast<float>(*reinterpret_cast<int*>(in_EAX + 0x10)), 0.0f,
                 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
    char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840("The audio manager has not been properly initialized yet", 0);
        return;
    }
    if (DAT_008e8eff == 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
}

// 0x4a3c40 — observed shape
// Searches the 0x008c78bc table (stride 3) for a matching slot, then may
// insert into a free slot; insertion gated on iVar5/2 < 0x1389, triggers
// FUN_0049f930(0x1d) or FUN_00488840.
void FUN_004a3c40(void* self, int param_1, int in_EAX, int unaff_EBX) {
    (void)self;
    int iVar1 = DAT_008ecd78;
    int iVar5 = *reinterpret_cast<int*>(in_EAX + 0x10) / 1000 + param_1 * -1000;
    int iVar3 = *reinterpret_cast<int*>(in_EAX + 0xc) / 1000 + unaff_EBX * -1000;
    if (iVar3 < 0) iVar3 = -iVar3;
    if (iVar5 < 0) iVar5 = -iVar5;
    if (iVar5 < iVar3) {
        iVar5 = iVar5 + iVar3 * 2;
    } else {
        iVar5 = iVar3 + iVar5 * 2;
    }
    int iVar3b = 0;
    int32_t* piVar4 = reinterpret_cast<int32_t*>(&DAT_008c78bc_arr[0]);
    while ((piVar4[-1] != unaff_EBX || piVar4[0] != param_1)) {
        piVar4 = piVar4 + 3;
        iVar3b = iVar3b + 1;
        if (reinterpret_cast<intptr_t>(piVar4) > 0x8c78f7) {
            goto LAB_004a3cd4;
        }
    }
    if (iVar3b != -1) {
        return;
    }
LAB_004a3cd4:
    if (iVar5 / 2 < 0x1389) {
        iVar5 = 0;
        int32_t* piVar4b = reinterpret_cast<int32_t*>(&DAT_008c78b8_arr[0]);
        while (piVar4b[0] != -1) {
            piVar4b = piVar4b + 3;
            iVar5 = iVar5 + 1;
            if (reinterpret_cast<intptr_t>(piVar4b) > 0x8c78f3) {
                return;
            }
        }
        if (iVar5 != -1) {
            reinterpret_cast<int32_t*>(&DAT_008c78b8_arr[0])[iVar5 * 3] = unaff_EBX;
            reinterpret_cast<int32_t*>(&DAT_008c78bc_arr[0])[iVar5 * 3] = param_1;
            char cVar2 = (char)(**(int (**)(void))(iVar1 + 0x18))();
            if (cVar2 == 0) {
                FUN_00488840();
                return;
            }
            FUN_0049f930(&DAT_008e67b0, 0x1d, 0);
        }
    }
}

// 0x4a3db0 — observed shape
void FUN_004a3db0(char param_1) {
    if (DAT_008e8eff == 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
    FUN_00488fc0(&DAT_008c8238, 100, 0xbf800000);
    FUN_00489040(&DAT_008c8254, 0x19, 0xbf800000);
    FUN_004888e0(0x65, 0xffffffff, 0xffffffff, 0xbf800000);
    char cVar1;
    if (param_1 == 0) {
        cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
        if (cVar1 == 0) return;
    } else {
        cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
        if (cVar1 != 0) {
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
    FUN_004985e0();
    FUN_004a14b0();
}

// 0x4a3f10 — observed shape
// Register AL guard; uses DAT_00814304/00814308 meter distances.
void FUN_004a3f10(char in_AL) {
    if ((in_AL != 0) && (DAT_008e8eff == 0)) {
        FUN_004985e0();
        FUN_004a14b0();
    }
    FUN_004985e0();
    FUN_004a14b0();
    FUN_00488fc0(&DAT_008c8238, 0x65, 0xbf800000);
    FUN_004888e0(100, 0xffffffff, 0xffffffff, 0xbf800000);
    FUN_00488a80(0x19, static_cast<float>(DAT_00814304) * 0.001f,
                 static_cast<float>(DAT_00814308) * 0.001f, 0.0f, 0xffffffff, 0xffffffff,
                 0xffffffff, 0xffffffff, &DAT_008c8254, 0xbf800000, 0xffffffff);
    char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
}

// 0x4a40a0 — observed shape
// Sweeps the 0x008c78bc table, clearing entries whose distance exceeds 5000.
void FUN_004a40a0(void* self, int unaff_EBX) {
    (void)self;
    int32_t* piVar3 = reinterpret_cast<int32_t*>(&DAT_008c78bc_arr[0]);
    do {
        if (piVar3[-1] != -1) {
            int iVar2 = *reinterpret_cast<int*>(unaff_EBX + 0x10) / 1000 + piVar3[0] * -1000;
            int iVar1 = *reinterpret_cast<int*>(unaff_EBX + 0xc) / 1000 + piVar3[-1] * -1000;
            if (iVar1 < 0) iVar1 = -iVar1;
            if (iVar2 < 0) iVar2 = -iVar2;
            if (iVar2 < iVar1) {
                iVar2 = iVar2 + iVar1 * 2;
            } else {
                iVar2 = iVar1 + iVar2 * 2;
            }
            if (5000 < iVar2 / 2) {
                FUN_00489210(piVar3 - 2);
                piVar3[-1] = -1;
                piVar3[0] = -1;
            }
        }
        piVar3 = piVar3 + 3;
    } while (reinterpret_cast<intptr_t>(piVar3) < 0x8c78f8);
}

// 0x4a4140 — observed shape
void FUN_004a4140() {
    DAT_008c78b0 = 0;
    DAT_008c78a4 = 0;
    DAT_008c78a0 = 0;
    FUN_004891a0(&DAT_008c789c);
    FUN_004891a0(&DAT_008c7898);
    FUN_004891a0(&DAT_008c7894);
    FUN_004891a0(&DAT_008c7890);
    FUN_004891a0(&DAT_008c788c);
    DAT_008c7888 = 1;
    FUN_00498850(0);
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840("The audio manager has not been properly initialized yet", 0);
    } else {
        if (DAT_008e8eff != 0) return;
        FUN_004985e0();
        FUN_004a14b0();
    }
    if (DAT_008e8eff == 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
}

// 0x4a4340 — observed shape
// Resets five 0x008c789x slots, rises power, gated spin poll then queue ops.
void FUN_004a4340() {
    FUN_00489040(&DAT_008c789c, 0xffffffff, 0xbf800000);
    FUN_00489040(&DAT_008c7898, 0xffffffff, 0xbf800000);
    FUN_00489040(&DAT_008c7894, 0xffffffff, 0xbf800000);
    FUN_00489040(&DAT_008c7890, 0xffffffff, 0xbf800000);
    FUN_00489040(&DAT_008c788c, 0xffffffff, 0xbf800000);
    FUN_00489210(&DAT_008c789c);
    FUN_00489210(&DAT_008c7898);
    FUN_00489210(&DAT_008c7894);
    FUN_00489210(&DAT_008c7890);
    FUN_00489210(&DAT_008c788c);
    FUN_00488ed0(0x3f800000);
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0 && (DAT_008cac27 == 0 || DAT_008cac26 != 0)) {
        while (true) {
            int iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
            if (iVar2 < 0) iVar2 += 100;
            if (iVar2 == 0) break;
            Sleep(0x28);
        }
        if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec) >> 2 != 0)) {
            DAT_008e8ef0 = DAT_008e8ef0 - 4;
        }
        FUN_0049af70(*DAT_008ed2c8, 0);
        uint32_t uVar3 = (uint32_t)FUN_004a0b70(0xfffffffe);
        FUN_0049aed0(uVar3, 0xfffffffe);
    }
}

// 0x4a44e0 — observed shape
// Time-gated accumulator (0x1389) then oriented delta between FUN_004baaa0
// and DAT_008e9fd8 positions at +0x90/+0x94/+0x98.
void FUN_004a44e0(void* self, int in_EAX) {
    (void)self;
    (void)in_EAX;
    if (DAT_008c78a4 < 0x1389) {
        if ((_DAT_008ed61c & 1) == 0) {
            _DAT_008ed61c = _DAT_008ed61c | 1;
            DAT_008ed618 = static_cast<int>(timeGetTime());
        }
        DWORD DVar7 = timeGetTime();
        DAT_008c78a4 = DAT_008c78a4 + static_cast<int>(DVar7 - DAT_008ed618);
    } else {
        FUN_004a4910();
    }
    FUN_004a46f0();
    if (in_EAX != 0) {
        int iVar8 = FUN_004baaa0();
        float fVar1 = *reinterpret_cast<float*>(iVar8 + 0x90);
        float fVar2 = *reinterpret_cast<float*>(iVar8 + 0x94);
        float fVar3 = *reinterpret_cast<float*>(iVar8 + 0x98);
        float fVar4 = *reinterpret_cast<float*>(DAT_008e9fd8 + 0x90);
        float fVar5 = *reinterpret_cast<float*>(DAT_008e9fd8 + 0x94);
        float fVar6 = *reinterpret_cast<float*>(DAT_008e9fd8 + 0x98);
        FUN_00491640();
        FUN_004985e0();
        FUN_004a14b0();
        FUN_004987a0(&DAT_008e67b0, fVar1 - fVar4, fVar2 - fVar5, fVar3 - fVar6,
                     0x80000000, 0x80000000, 0xbf800000);
    }
}

// 0x4a46f0 — observed shape
// State machine on DAT_008c78b0 (0/1/2): 5000 ms timer OR state checks, uses
// FUN_004a49c0 result, pow ramp table (0x40a00000/0x3f800000) via
// FUN_00488d90; direct call to FUN_004888e0(3,...).
void FUN_004a46f0() {
    int iVar3 = DAT_008c78b0;
    if (DAT_008c78a0 < 5000 || (DAT_008c78b0 != 0 && DAT_008c78b0 != 2)) {
        if ((_DAT_008ed61c & 1) == 0) {
            _DAT_008ed61c = _DAT_008ed61c | 1;
            DAT_008ed618 = static_cast<int>(timeGetTime());
        }
        DWORD DVar2 = timeGetTime();
        DAT_008c78a0 = DAT_008c78a0 + static_cast<int>(DVar2 - DAT_008ed618);
        iVar3 = DAT_008c78b0;
    } else {
        char cVar1 = FUN_004a49c0();
        if (cVar1 == 0) {
            if (iVar3 == 2) {
                DAT_008c78b0 = 0;
                iVar3 = 0;
            }
        } else if (iVar3 == 0) {
            DAT_008c78b0 = 2;
            iVar3 = 2;
        }
    }
    if (iVar3 == 0) {
        uint32_t local_4;
        if (DAT_008c78ac == 1) {
            local_4 = 0x40a00000;
        } else {
            local_4 = 0x3f800000;
            if (DAT_008c78ac == 0) return;
        }
        FUN_00488d90(0, 1, local_4, 1, 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xffffffff);
        DAT_008c78ac = DAT_008c78b0;
        DAT_008c78a0 = 0;
        return;
    }
    if (iVar3 == 1) {
        if (DAT_008c78ac == 1) return;
        FUN_00488d90(2, 1, 0x3f800000, 1, 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xffffffff);
        FUN_004888e0(3, 0xffffffff, 0xffffffff, 0xbf800000);
        DAT_008c78a0 = 0;
        DAT_008c78ac = DAT_008c78b0;
        return;
    }
    if (iVar3 != 2) {
        DAT_008c78b0 = 0;
        return;
    }
    uint32_t local_4;
    uint32_t uVar4;
    if (DAT_008c78ac == 1) {
        local_4 = 0x40a00000;
        uVar4 = 1;
    } else {
        local_4 = 0x3f800000;
        if (DAT_008c78ac == 2) return;
        uVar4 = 1;
    }
    FUN_00488d90(uVar4, 1, local_4, 1, 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xffffffff);
    DAT_008c78ac = DAT_008c78b0;
    DAT_008c78a0 = 0;
}

// 0x4a4880 — observed shape
// Recursive fill: bounds 0..0x2f, DAT_008c63a0 walkable flag == 1, writes
// DAT_008c78f0 bytes; recurses with param_1-1 and param_4+1.
void FUN_004a4880(int param_1, int param_2, int param_3, int param_4) {
    if (param_1 != -1) {
        do {
            if (param_2 < 0) return;
            if (0x2f < param_2) return;
            if (param_3 < 0) return;
            if (0x2f < param_3) return;
            int iVar1 = param_2 * 0x30;
            if (reinterpret_cast<char*>(&DAT_008c63a0_arr[0])[param_3 + iVar1] != 0x01) return;
            if (static_cast<int>(reinterpret_cast<byte*>(&DAT_008c78f0_arr[0])[param_3 + iVar1]) < param_4) return;
            reinterpret_cast<byte*>(&DAT_008c78f0_arr[0])[param_3 + iVar1] = static_cast<byte>(param_4);
            param_1 = param_1 - 1;
            param_4 = param_4 + 1;
            FUN_004a4880(param_1, param_2 - 1, param_3, param_4);
            FUN_004a4880(param_1, param_2, param_3 + 1, param_4);
            FUN_004a4880(param_1, param_2 + 1, param_3, param_4);
            param_3 = param_3 - 1;
        } while (param_1 != -1);
    }
}

// 0x4a4910 — observed shape
// Clears 0x240 dwords at 0x008c78f0 and 0x20 at 0x008c2330, seeds
// FUN_004a4880(), then walks 0x008c240c stride 0x11 sampling bytes at
// +500/1000 offsets.
void FUN_004a4910() {
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(&DAT_008c78f0_arr[0]);
    for (int iVar2 = 0x240; iVar2 != 0; iVar2--) {
        *puVar4 = 0xffffffff;
        puVar4 = puVar4 + 1;
    }
    puVar4 = reinterpret_cast<uint32_t*>(&DAT_008c2330_arr[0]);
    for (int iVar2 = 0x20; iVar2 != 0; iVar2--) {
        *puVar4 = 0xffffffff;
        puVar4 = puVar4 + 1;
    }
    DAT_008c78a4 = 0;
    FUN_004a4880(0, 0, 0, 0);
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(&DAT_008c2334_arr[0]);
    int32_t* piVar3 = reinterpret_cast<int32_t*>(&DAT_008c240c_arr[0]);
    do {
        byte bVar1 = reinterpret_cast<byte*>(&DAT_008c78f0_arr[0])[
            (piVar3[0] + 500) / 1000 + ((piVar3[-1] + 500) / 1000) * 0x30];
        if (bVar1 != 0xff) {
            *puVar5 = static_cast<uint32_t>(bVar1);
        }
        piVar3 = piVar3 + 0x11;
        puVar5 = puVar5 + 1;
    } while (reinterpret_cast<intptr_t>(piVar3) < 0x8c2c48);
}

// 0x4a49c0 — observed shape
// Counts DAT_008c2334 values below 4, then <7, then <10; returns uint with
// masks (0xffffff00 / CONCAT31) — preserved as observed shape.
uint32_t FUN_004a49c0() {
    int* piVar1 = reinterpret_cast<int*>(&DAT_008c2334_arr[0]);
    int iVar2 = 0;
    do {
        if (*piVar1 < 4 && *piVar1 != -1) iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 1;
    } while (reinterpret_cast<intptr_t>(piVar1) < 0x8c23b0);
    if (iVar2 < 2) {
        iVar2 = 0;
        piVar1 = reinterpret_cast<int*>(&DAT_008c2334_arr[0]);
        do {
            if (*piVar1 < 7 && *piVar1 != -1) iVar2 = iVar2 + 1;
            piVar1 = piVar1 + 1;
        } while (reinterpret_cast<intptr_t>(piVar1) < 0x8c23b0);
        if (iVar2 < 4) {
            iVar2 = 0;
            piVar1 = reinterpret_cast<int*>(&DAT_008c2334_arr[0]);
            do {
                if (*piVar1 < 10 && *piVar1 != -1) iVar2 = iVar2 + 1;
                piVar1 = piVar1 + 1;
            } while (reinterpret_cast<intptr_t>(piVar1) < 0x8c23b0);
            if (iVar2 < 5) {
                return static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar1)) & 0xffffff00;
            }
        }
    }
    return 1;
}

// 0x4a4a40 — observed shape
// Multi-range init: zeroes DAT_008c73xx block, clears tables 0x008c73a8 and
// 0x008c740c/0x008b9a14 with vtable probes, sleep loops, spin poll.
// Branch at end on DAT_008c73ba.
void FUN_004a4a40() {
    _DAT_008c739c = static_cast<int>(_DAT_008c84b0);
    DAT_008c73c8 = 0;
    DAT_008c81f4 = 0;
    DAT_008c81f3 = 0;
    DAT_008c73b9 = 0;
    DAT_008c73b8 = 0;
    DAT_008c73c4 = 0xffffffff;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(&DAT_008c73a8_arr[0]);
    do {
        puVar2[-2] = 0xbf800000;
        puVar2[-1] = 0xbf800000;
        puVar2[0] = 0;
        puVar2 = puVar2 + 3;
    } while (reinterpret_cast<intptr_t>(puVar2) < 0x8c73c0);
    if ((*(short*)(reinterpret_cast<intptr_t>(&DAT_008142fa) + DAT_008bd72c * 0x45c) == 1) ||
        (DAT_008c73ba = 0, 2 < DAT_008bd728)) {
        DAT_008c73ba = 1;
    }
    int iVar3 = 0;
    puVar2 = reinterpret_cast<uint32_t*>(&DAT_008c740c_arr[0]);
    do {
        for (int local_dc = 2; local_dc != 0; local_dc--) {
            int iVar4 = DAT_008ecd78;
            reinterpret_cast<uint32_t*>(&DAT_008c73cc_arr[0])[iVar3] = 0xffffffff;
            char cVar1 = (char)(**(int (**)(void))(iVar4 + 0x18))();
            if (cVar1 == 0) {
                FUN_00488840();
            } else {
                FUN_004985e0();
                FUN_004a14b0();
            }
            for (int iStack_d8 = 0x18; iStack_d8 != 0; iStack_d8--) {
                cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
                if (cVar1 == 0) {
                    FUN_00488840();
                } else {
                    FUN_004985e0();
                    FUN_004a14b0();
                }
                puVar2[0] = 0xffffffff;
                puVar2 = puVar2 + 3;
            }
            Sleep(0x28);
            iVar3 = iVar3 + 4;
        }
    } while (reinterpret_cast<intptr_t>(puVar2) < 0x8c788c);
    puVar2 = reinterpret_cast<uint32_t*>(&DAT_008b9a14_arr[0]);
    do {
        char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
        if (cVar1 == 0) {
            FUN_00488840();
        } else {
            FUN_004985e0();
            FUN_004a14b0();
        }
        puVar2 = puVar2 + 0x10;
    } while (reinterpret_cast<intptr_t>(puVar2) < 0x8ba414);
    char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_004985e0();
        FUN_004a14b0();
    }
    _DAT_008c73bc = static_cast<int>(_DAT_008c84b0);
    _DAT_008c73c0 = _DAT_008c73bc;
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0 && (DAT_008cac27 == 0 || DAT_008cac26 != 0)) {
        while (true) {
            int iVar3b = DAT_008e8ef0;
            int iVar4b = DAT_008e8ec4 - DAT_008e8ec8;
            if (iVar4b < 0) iVar4b += 100;
            if (iVar4b == 0) break;
            Sleep(0x28);
        }
        if ((DAT_008e8eec == 0) ||
            (static_cast<uint32_t>((DAT_008e8ef4 - DAT_008e8eec) >> 2) <= static_cast<uint32_t>((DAT_008e8ef0 - DAT_008e8eec) >> 2))) {
            FUN_004a0df0();
        } else {
            FUN_004a1090();
            DAT_008e8ef0 = DAT_008e8ef0 + 4;
        }
        FUN_0049af70();
        FUN_0049aed0();
    }
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    if (DAT_008c73ba == 0) {
        cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    } else {
        cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    }
    if (cVar1 == 0) {
        FUN_00488840();
    } else if (DAT_008e8eff == 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840();
    } else {
        FUN_0049f930(&DAT_008e67b0, 0x42, 0);
    }
    cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }
}

// 0x4a5270 — observed shape
// Teardown counterpart to 0x4a4a40: conditional 0x2e resets, clears tables,
// drains audio/USB tables, spin poll then queue ops.
void FUN_004a5270() {
    int local_6c = 0;
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(&DAT_008c740c_arr[0]);
    do {
        for (int local_68 = 2; local_68 != 0; local_68--) {
            if ((reinterpret_cast<int*>(&DAT_008c73f4_arr[0])[local_6c] != 0) &&
                (0x18 < reinterpret_cast<int*>(&DAT_008c73cc_arr[0])[local_6c])) {
                FUN_00489040(reinterpret_cast<intptr_t>(&DAT_008c73f4_arr[0]) + local_6c, 0x2e, 0xbf800000);
                FUN_00489210(reinterpret_cast<intptr_t>(&DAT_008c73f4_arr[0]) + local_6c);
            }
            for (int iVar3 = 0x18; iVar3 != 0; iVar3--) {
                FUN_00489040(puVar4 - 1, puVar4[0], 0xbf800000);
                char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
                if (cVar1 == 0) {
                    FUN_00488840("The audio manager has not been properly initialized yet", 0);
                } else {
                    FUN_004985e0();
                    FUN_004a14b0();
                }
                puVar4[0] = 0xffffffff;
                puVar4 = puVar4 + 3;
            }
            while (true) {
                int iVar3b = DAT_008e8ec4 - DAT_008e8ec8;
                if (iVar3b < 0) iVar3b += 100;
                if (iVar3b == 0) break;
                Sleep(1);
            }
            local_6c = local_6c + 4;
        }
    } while (reinterpret_cast<intptr_t>(puVar4) < 0x8c788c);
    puVar4 = reinterpret_cast<uint32_t*>(&DAT_008b9a14_arr[0]);
    do {
        FUN_00489210(puVar4);
        puVar4 = puVar4 + 0x10;
    } while (reinterpret_cast<intptr_t>(puVar4) < 0x8ba414);
    FUN_00488fc0(&DAT_008c73dc, 0xffffffff, 0xbf800000);
    for (int k = 0; k < 6; k++) {
        char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
        if (cVar1 == 0) {
            FUN_00488840("The audio manager has not been properly initialized yet", 0);
        } else {
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004986e0(&DAT_008e67b0, 0);
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    char cVar1 = (char)(**(int (**)(void))(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0 && (DAT_008cac27 == 0 || DAT_008cac26 != 0)) {
        while (true) {
            int iVar3 = DAT_008e8ec4 - DAT_008e8ec8;
            if (iVar3 < 0) iVar3 += 100;
            if (iVar3 == 0) break;
            Sleep(0x28);
        }
        if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec) >> 2 != 0)) {
            DAT_008e8ef0 = DAT_008e8ef0 - 4;
        }
        FUN_0049af70(*DAT_008ed2c8, 0);
        uint32_t uVar2 = (uint32_t)FUN_004a0b70(0xfffffffe);
        FUN_0049aed0(uVar2, 0xfffffffe);
    }
}
