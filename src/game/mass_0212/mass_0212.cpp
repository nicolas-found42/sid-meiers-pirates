#include <cstdint>
#include <cstddef>
#include <windows.h>

extern int32_t DAT_00728d84;
extern uint32_t DAT_00717844;
extern uint32_t DAT_00717854;
extern char LAB_00544d20;

// 0x5bf8c0 — observed shape
void FUN_005bf8c0(void* self)
{
    int32_t iVar1;
    int32_t iVar2;
    uint8_t* selfBytes = static_cast<uint8_t*>(self);

    iVar1 = *reinterpret_cast<int32_t*>(selfBytes + 0x2c8);
    iVar2 = DAT_00728d84;
    while ((DAT_00728d84 = iVar1) != 0) {
        int32_t cur = DAT_00728d84;
        iVar1 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(cur)) + 0xc);
        *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(cur)) + 0xc) = iVar2;
        iVar2 = cur;
    }
    DAT_00728d84 = iVar2;
    *reinterpret_cast<uint32_t*>(selfBytes + 0x2c8) = 0;
    *reinterpret_cast<uint32_t*>(selfBytes + 0x2cc) = 0;
}

// 0x5bfa50 — observed shape
uint32_t FUN_005bfa50(void* self, uint32_t param_1)
{
    using Func3 = uint32_t(__cdecl*)(uint32_t);
    using Func4 = uint32_t(__cdecl*)(uint32_t, uint32_t);
    using Func5 = uint32_t(__cdecl*)(uint32_t);

    uint32_t* ecxWords = static_cast<uint32_t*>(self);
    int32_t* base = reinterpret_cast<int32_t*>(self);
    uint32_t vtable = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x0);
    // *in_ECX is vtable base pointer
    uint32_t vptr = *ecxWords;
    uint32_t uVar3 = (**(code**)(*ecxWords + 4))(param_1);
    uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(ecxWords[2])) + uVar3 * 4);
    uint32_t uVar4 = uVar3;
    if (puVar5 != nullptr) {
        uVar4 = (**(code **)(*ecxWords + 8))(param_1, puVar5[1]);
        if ((int8_t)uVar4 != 0) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(ecxWords[2])) + uVar3 * 4) = *puVar5;
            (**(code **)(*ecxWords + 0x10))(reinterpret_cast<uint32_t>(puVar5));
            (**(code **)(*ecxWords + 0x18))(reinterpret_cast<uint32_t>(puVar5));
            int32_t iVar1 = ecxWords[3];
            ecxWords[3] = static_cast<uint32_t>(iVar1 + -1);
            return (static_cast<uint32_t>(iVar1 + -1) & 0xffffff00u) | 1u;
        }
        if (reinterpret_cast<uint32_t*>(*puVar5) != nullptr) {
            uint32_t* puVar6 = reinterpret_cast<uint32_t*>(*puVar5);
            do {
                uVar4 = (**(code **)(*ecxWords + 8))(param_1, puVar6[1]);
                if ((int8_t)uVar4 != 0) {
                    *puVar5 = *puVar6;
                    (**(code **)(*ecxWords + 0x10))(reinterpret_cast<uint32_t>(puVar6));
                    (**(code **)(*ecxWords + 0x18))(reinterpret_cast<uint32_t>(puVar6));
                    int32_t iVar1 = ecxWords[3];
                    ecxWords[3] = static_cast<uint32_t>(iVar1 + -1);
                    return (static_cast<uint32_t>(iVar1 + -1) & 0xffffff00u) | 1u;
                }
                uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*puVar6);
                puVar5 = puVar6;
                puVar6 = puVar2;
            } while (puVar2 != nullptr);
        }
    }
    (void)vtable; (void)base; (void)vptr;
    return uVar4 & 0xffffff00u;
}

// 0x5bfb00 — observed shape
uint32_t FUN_005bfb00(void* self, int32_t param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t field_0x20 = *reinterpret_cast<uint32_t*>(b + 0x20);
    if (field_0x20 != 0) {
        int32_t iVar1 = (**(code**)(field_0x20 + 4))();
        if (iVar1 == param_1) {
            return field_0x20;
        }
    }
    return 0;
}

// 0x5bfb50 — observed shape
int32_t FUN_005bfb50(uint32_t* param_1)
{
    int8_t cVar1 = static_cast<int8_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(param_1) + 0x18));
    int32_t iVar2 = 0;
    switch (*param_1) {
    case 0:
        switch (cVar1) {
        default:
            return 0;
        case 0x10:
            return (static_cast<int8_t>((param_1[7] & DAT_00717844) >> (DAT_00717854 & 0x1f)) != 0x06) + 0x17;
        case 0x18:
            return 0x14;
        case 0x20:
            return 0x16;
        }
        break;
    case 1:
        switch (cVar1) {
        default:
            return 0;
        case 0x10:
            {
                int8_t c = static_cast<int8_t>((param_1[7] & DAT_00717844) >> (DAT_00717854 & 0x1f));
                if (c == 0x06) return 0x17;
                return (c == 0x04) + 0x19;
            }
        case 0x18:
            return 0x14;
        case 0x20:
            return 0x15;
        }
        break;
    case 2:
    case 3:
        return 0x29;
    case 4:
        return static_cast<int32_t>(0x31545844u);
    case 5:
        return static_cast<int32_t>(0x33545844u);
    case 6:
        return static_cast<int32_t>(0x35545844u);
    case 8:
        if (cVar1 == 0x10) return 0x3c;
        break;
    case 9:
        if (cVar1 == 0x10) return 0x3d;
        if (cVar1 == 0x20) iVar2 = 0x3e;
        break;
    }
    return iVar2;
}

// 0x5bfcd0 — observed shape
void FUN_005bfcd0(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    *reinterpret_cast<uint8_t*>(b + 0x298) = 0;
    uint8_t flags = *(b + 0x274);
    if ((flags & 0x10) != 0) {
        uint8_t* p = b + 0x297;
        uint8_t* q;
        do {
            q = p;
            p = p + 1;
        } while (*(p + 1) != 0);
        *reinterpret_cast<uint32_t*>(q + 1) = 0x45525550u;
        *(q + 5) = 0;
    }
    if ((flags & 4) != 0) {
        uint8_t* p = b + 0x297;
        uint8_t* r;
        do {
            r = p + 1;
            p = p + 1;
        } while (*r != 0);
        *reinterpret_cast<void**>(p) = &LAB_00544d20;
    }
    if ((flags & 0x40) != 0) {
        uint8_t* p = b + 0x297;
        uint8_t* q;
        do {
            q = p;
            p = p + 1;
        } while (*(q + 1) != 0);
        *reinterpret_cast<uint32_t*>(q + 1) = 0x56574820u;
        *reinterpret_cast<uint16_t*>(q + 5) = 0x50;
    }
    if (static_cast<int8_t>(flags) < 0) {
        uint8_t* p = b + 0x297;
        uint8_t* q;
        do {
            q = p;
            p = p + 1;
        } while (*(q + 1) != 0);
        *reinterpret_cast<uint32_t*>(q + 1) = 0x58494d20u;
        *reinterpret_cast<uint16_t*>(q + 5) = 0x5056;
        *(q + 7) = 0;
    }
    if ((flags & 0x20) != 0) {
        uint8_t* p = b + 0x297;
        uint8_t* q;
        do {
            q = p;
            p = p + 1;
        } while (*(q + 1) != 0);
        *reinterpret_cast<uint32_t*>(q + 1) = 0x56575320u;
        *reinterpret_cast<uint16_t*>(q + 5) = 0x50;
    }
}

extern uint32_t DAT_007177ac;
extern uint32_t DAT_007177b0;
extern uint32_t DAT_007177b4;
extern uint32_t DAT_007177b8;
extern uint32_t DAT_007177bc;
extern uint32_t DAT_007177c0;
extern char DAT_00727b30;
extern uint32_t DAT_00728d74;
extern int32_t _DAT_00728d64;
extern int32_t _DAT_00728d58;
extern int32_t _DAT_00728d50;
extern int32_t _DAT_00728d54;
extern int32_t _DAT_00728d68;
extern int32_t _DAT_00728d6c;
extern int32_t _DAT_00728d60;
extern int32_t _DAT_00728d5c;
extern int32_t _DAT_00728d0c;
extern int32_t _DAT_00728d08;
extern int32_t _DAT_00728d10;
extern int32_t _DAT_00728d18;
extern int32_t _DAT_00728d14;
extern int32_t _DAT_00728d1c;
extern int32_t _DAT_00728d24;
extern int32_t _DAT_00728d20;
extern int32_t _DAT_00728d28;
extern int32_t _DAT_00728d30;
extern int32_t _DAT_00728d2c;
extern int32_t _DAT_00728d34;
extern int32_t _DAT_00728d3c;
extern int32_t _DAT_00728d38;
extern int32_t _DAT_00728d40;
extern int32_t _DAT_00728d48;
extern int32_t _DAT_00728d44;
extern int32_t _DAT_00728d4c;
extern uint32_t DAT_00728d80;
extern char* strncpy(char*, const char*, size_t);
extern uint32_t FUN_005cc1b0(uint32_t, uint32_t);
extern uint32_t FUN_005cc240(uint32_t, uint32_t, uint32_t, uint32_t);
extern uint32_t FUN_005bfe80(int32_t);
extern uint32_t FUN_005bff40(uint32_t);
extern int32_t FUN_005cc410(uint32_t, uint32_t, uint32_t, uint32_t*);
extern void FUN_005bfa20(const char*);
extern void FUN_005be900(uint32_t);
extern void FUN_005be910(uint32_t);
extern void FUN_005be920(uint32_t);
extern int32_t FUN_00533c78(int32_t);
extern void* FUN_00539210(int32_t, int32_t, int32_t, int32_t);

// 0x5bfdb0 — observed shape
uint32_t FUN_005bfdb0(uint32_t param_1)
{
    switch (param_1) {
    default: return 0;
    case 1: return 0x14;
    case 2: return 0x15;
    case 3: return 0x16;
    case 4: return 0x17;
    case 5: return 0x18;
    case 6: return 0x19;
    case 7: return 0x1a;
    case 8: return 0x1b;
    case 9: return 0x1c;
    case 10: return 0x1d;
    case 0xb: return 0x1e;
    }
}

// 0x5c0210 — observed shape
void FUN_005c0210(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    auto W = [b](size_t off, uint32_t v) { *reinterpret_cast<uint32_t*>(b + off) = v; };
    auto B = [b](size_t off, uint8_t v) { *(b + off) = v; };
    W(0x60, 0); W(100, 0); B(0x68, 0); W(0x268, 0); W(0x26c, 1); W(0x270, 0);
    W(0x274, 0); B(0x278, 0); B(0x279, 0); W(0x27c, 0);
    W(0x450, 0); W(0x454, 0); W(0x458, 0); W(0x45c, 0); B(0x460, 0); W(0x464, 0);
    W(0x288, 0xff808080u); W(0x28c, 0x3f800000u); W(0x290, 0); W(0x294, 0); B(0x298, 0);
    W(0x2dc, DAT_007177ac); W(0x2e0, DAT_007177b0); W(0x2e4, DAT_007177b4);
    W(0x2e8, DAT_007177b8); W(0x2ec, DAT_007177bc); W(0x2f0, DAT_007177c0);
    W(0x2f4, DAT_007177ac); W(0x2f8, DAT_007177b0); W(0x2fc, DAT_007177b4);
    W(0x300, DAT_007177b8); W(0x304, DAT_007177bc); W(0x308, DAT_007177c0);
    W(0x32c, 0x3dcccccd); W(0x330, 0x42c80000u); W(0x334, 0x3f800000u); W(0x344, 0);
    W(0x354, 0); W(0x338, 0); W(0x348, 0x3f800000u); W(0x358, 0); W(0x33c, 0);
    W(0x34c, 0); W(0x35c, 0x3f800000u); W(0x364, 0); W(0x368, 0); W(0x36c, 0);
    W(0x340, 0); W(0x350, 0); W(0x360, 0); W(0x370, 0x3f800000u); W(0x374, 0x3f800000u);
    W(900, 0); W(0x394, 0); W(0x378, 0); W(0x388, 0x3f800000u); W(0x398, 0);
    W(0x37c, 0); W(0x38c, 0); W(0x39c, 0x3f800000u); W(0x3a4, 0); W(0x3a8, 0);
    W(0x3ac, 0); W(0x380, 0); W(0x390, 0); W(0x3a0, 0); W(0x3b0, 0x3f800000u);
    W(0x3b4, 0x40000000u); W(0x3c8, 0x40000000u); W(0x3c4, 0);
    W(0x3d4, 0xbf800000u); W(0x3d8, 0xbf800000u); W(0x3e4, 0); W(0x3b8, 0);
    W(1000, 0); W(0x3bc, 0); W(0x3cc, 0); W(0x3dc, 0x3f800000u); W(0x3ec, 0);
    W(0x3c0, 0); W(0x3d0, 0); W(0x3e0, 0x3f800000u); W(0x3f0, 0);
    {
        uint32_t* p = reinterpret_cast<uint32_t*>(b + 0x3f4);
        for (int i = 0x10; i != 0; i--) { *p = 0; p = p + 1; }
    }
    W(0x3f4, 0x3f800000u); W(0x430, 0x3f800000u); W(0x41c, 0x3f800000u);
    W(0x408, 0x3f800000u); W(0x2c8, 0); W(0x2cc, 0); W(0x434, 0); W(0x438, 0);
    W(0x43c, 0); W(0x440, 0); W(0x444, 0); W(0x448, 0); W(0x434, 0);
    uint32_t* local_8 = reinterpret_cast<uint32_t*>(b + 0x468);
    W(0x438, 0); W(0x43c, 1); W(0x440, 1); W(0x444, 0); W(0x448, 0x3f800000u); B(0x44c, 0);
    int32_t* piVar3 = reinterpret_cast<int32_t*>(b + 0x558);
    int local_4 = 4;
    do {
        for (int i = 0; i < 0xe; i++) local_8[i] = 0;
        piVar3[-4] = 0;
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(*piVar3);
        if (puVar4 != nullptr) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(code**)*puVar4)(1);
            *piVar3 = 0;
        }
        local_8 = local_8 + 0xe;
        piVar3 = piVar3 + 1;
        local_4 = local_4 + -1;
    } while (local_4 != 0);
    W(0x5a0, 0xe);
    W(0x568, 0); W(0x56c, 0); W(0x570, 0); W(0x574, 0); W(0x578, 0);
    W(0x57c, 0); W(0x580, 0); W(0x584, 0); W(0x588, 0); W(0x58c, 0);
    W(0x590, 0); W(0x594, 0); W(0x598, 0); W(0x59c, 0); W(0x5a4, 0);
    W(0x5a8, 0); W(0x5d0, 0); W(0x5d4, 0); W(0x5d8, 0); W(0x5cc, 0);
    W(0x5dc, 0); W(0x5c0, 0); W(0x5c4, 0); W(0x5c8, 0);
    W(0x880, 0); W(0x884, 0); W(0x888, 0); W(0x88c, 0);
    *reinterpret_cast<uint16_t*>(b + 0x890) = 0; W(0x894, 0);
    {
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(b + 0x898));
        if (puVar4 != nullptr) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(code**)*puVar4)(1);
            W(0x898, 0);
        }
    }
    W(0x78c, 0); W(0x79c, 0); W(0x7ac, 0); W(0x7bc, 0x3f800000u);
    {
        uint32_t* p = reinterpret_cast<uint32_t*>(b + 0x644);
        for (int i = 0x4c; i != 0; i--) { *p = 0; p = p + 1; }
    }
}

// 0x5c06f0 — observed shape
uint32_t FUN_005c06f0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, int32_t param_5, int32_t param_6, int32_t param_7, uint32_t param_8, int32_t param_9, uint32_t param_10, uint32_t param_11, uint32_t* param_12)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint8_t bVar2 = static_cast<uint8_t>(~(param_4 >> 2));
    uint8_t bVar6 = static_cast<uint8_t>(param_4);
    uint32_t uVar7 = param_4 & 0x10;
    param_4 = (param_4 & 0xffffff01u) ^ (static_cast<uint32_t>(bVar2) & 0xfffffffeu);
    uint32_t uVar8 = 0x20;
    if (uVar7 != 0) uVar8 = 0x10;
    if (param_6 == 0) {
        param_6 = static_cast<int32_t>(FUN_005cc1b0(param_4, uVar8));
        if (param_6 == 0) {
            strncpy(&DAT_00727b30, "Creation failed: Could not find desired framebuffer format", 0xff);
            return 0;
        }
    }
    uint32_t uVar3 = FUN_005bfdb0(static_cast<uint32_t>(param_6));
    if (param_7 == 0) {
        param_7 = static_cast<int32_t>(FUN_005cc240(uVar3, uVar3, uVar8, param_4 & 8));
        if (param_7 == 0) {
            strncpy(&DAT_00727b30, "Creation failed: Could not find desired depth/stencil format", 0xff);
            return 0;
        }
    }
    uint32_t* puVar9 = param_12;
    for (int i = 0xe; i != 0; i--) { *puVar9 = 0; puVar9 = puVar9 + 1; }
    param_12[0] = param_2;
    param_12[1] = param_3;
    param_12[2] = uVar3;
    int32_t iVar5 = static_cast<int32_t>(FUN_005bfe80(param_5));
    param_12[4] = static_cast<uint32_t>(iVar5);
    param_12[10] = static_cast<uint32_t>(param_7);
    param_12[3] = param_8;
    param_12[9] = (static_cast<uint8_t>(~bVar6) & 1u);
    uVar7 = bVar2 & 1;
    param_12[8] = uVar7;
    uVar8 = 1;
    if (((param_5 == 0) || (param_5 == 1)) && (param_9 != 1)) {
        if (param_9 == 2) uVar8 = 2;
        else if (param_9 == 3) uVar8 = 3;
        else uVar8 = 1;
    } else {
        uVar8 = 1;
    }
    param_12[6] = uVar8;
    puVar9 = param_12 + 0xc;
    param_12[7] = param_1;
    param_12[0xb] = static_cast<uint32_t>(param_5 == 1);
    *puVar9 = param_10;
    uVar8 = FUN_005bff40(param_11);
    param_12[0xd] = uVar8;
    int32_t iVar4 = (**(code**)(DAT_00728d74 + 0x2c))(DAT_00728d74, *reinterpret_cast<uint32_t*>(b + 0x268), *reinterpret_cast<uint32_t*>(b + 0x26c), uVar3, uVar7, static_cast<uint32_t>(iVar5), 0);
    if (iVar4 < 0) param_12[4] = 0;
    if (param_12[3] == 0) param_12[3] = 1;
    else if (3 < param_12[3]) param_12[3] = 3;
    if (param_12[8] == 0) {
        iVar4 = FUN_005cc410(param_12[2], *param_12, param_12[1], puVar9);
        if (iVar4 == 0) {
            FUN_005bfa20("Creation failed: Could not match desired fullscreen mode");
            return 0;
        }
    } else {
        *puVar9 = 0;
    }
    if (param_12[8] != 0) {
        param_12[0xd] = 0x80000000u;
        return 1;
    }
    if ((param_12[0xd] & *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x18)) == 0) {
        param_12[0xd] = 1;
    }
    return 1;
}

// 0x5c0930 — observed shape
uint32_t FUN_005c0930(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t* base = reinterpret_cast<uint32_t*>(self);
    uint32_t f60 = *reinterpret_cast<uint32_t*>(b + 0x60);
    int32_t iVar2 = static_cast<int32_t>((**(code**)(f60 + 0x1c))(f60, reinterpret_cast<uint32_t>(b + 0x644)));
    if (iVar2 < 0) {
        char* pc = strncpy(&DAT_00727b30, "Creation failed: Could not query device caps", 0xff);
        return reinterpret_cast<uint32_t>(pc) & 0xffffff00u;
    }
    if ((*reinterpret_cast<uint32_t*>(b + 0x6d8) < 2) || (*reinterpret_cast<uint32_t*>(b + 0x6dc) < 2)) {
        char* pc = strncpy(&DAT_00727b30, "Creation failed: Device does not support single-pass multi-texture", 0xff);
        return reinterpret_cast<uint32_t>(pc) & 0xffffff00u;
    }
    *reinterpret_cast<uint32_t*>(b + 0x294) = 0x6d;
    uint32_t f5a8 = *reinterpret_cast<uint32_t*>(b + 0x5a8);
    if ((*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(f5a8)) + 0x3c) != 0) && (((iVar2 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(f5a8)) + 0x40), iVar2 == 0x49 || iVar2 == 0x4f) || iVar2 == 0x4b)) {
        *reinterpret_cast<uint32_t*>(b + 0x294) = 0xed;
    }
    if ((*reinterpret_cast<uint32_t*>(b + 0x668) & 0x40000u) != 0) *reinterpret_cast<uint32_t*>(b + 0x294) |= 0x100;
    if ((*reinterpret_cast<uint32_t*>(b + 0x680) & 0x20u) != 0) *reinterpret_cast<uint32_t*>(b + 0x294) |= 2;
    *reinterpret_cast<uint32_t*>(b + 0x450) = *reinterpret_cast<uint32_t*>(b + 0x6ec);
    if (3 < *reinterpret_cast<uint32_t*>(b + 0x6ec)) *reinterpret_cast<uint32_t*>(b + 0x294) |= 0x200;
    uint32_t uVar4 = *reinterpret_cast<uint32_t*>(b + 0x708);
    *reinterpret_cast<uint32_t*>(b + 0x454) = *reinterpret_cast<uint32_t*>(b + 0x700);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(b + 0x710);
    *(b + 0x460) = static_cast<uint8_t>(((*reinterpret_cast<uint32_t*>(b + 0x680) >> 0x10) & 1));
    *reinterpret_cast<uint32_t*>(b + 0x458) = uVar1;
    *reinterpret_cast<uint32_t*>(b + 0x45c) = uVar4;
    *reinterpret_cast<uint32_t*>(b + 0x61c) = uVar1;
    *reinterpret_cast<uint32_t*>(b + 0x620) = 0xffff0000u;
    *reinterpret_cast<uint32_t*>(b + 0x624) = uVar1;
    *reinterpret_cast<uint32_t*>(b + 0x628) = uVar4;
    *reinterpret_cast<uint32_t*>(b + 0x62c) = 0xfffe0000u;
    *reinterpret_cast<uint32_t*>(b + 0x630) = uVar4;
    *reinterpret_cast<uint32_t*>(b + 0x634) = 0xfffe0000u;
    *reinterpret_cast<uint32_t*>(b + 0x638) = 0xfffe0000u;
    *reinterpret_cast<uint32_t*>(b + 0x63c) = 0xfffe0000u;
    *reinterpret_cast<uint32_t*>(b + 0x640) = 2;
    FUN_005be900(*reinterpret_cast<uint32_t*>(b + 0x6d8));
    FUN_005be910(*reinterpret_cast<uint32_t*>(b + 0x6dc));
    uint32_t u5 = *reinterpret_cast<uint32_t*>(b + 0x458) < 0xffff0200u ? *reinterpret_cast<uint32_t*>(b + 0x6d8) : 0x10;
    FUN_005be920(u5);
    _DAT_00728d64 = 3; _DAT_00728d58 = 3; _DAT_00728d50 = 3; _DAT_00728d54 = 3;
    _DAT_00728d68 = 1; _DAT_00728d6c = 1; _DAT_00728d60 = 1; _DAT_00728d5c = 1;
    _DAT_00728d0c = 1; _DAT_00728d08 = 1; _DAT_00728d10 = 0; _DAT_00728d18 = 2;
    _DAT_00728d14 = 2; _DAT_00728d1c = 0; _DAT_00728d24 = 2; _DAT_00728d20 = 2;
    _DAT_00728d28 = 2; _DAT_00728d30 = 1; _DAT_00728d2c = 1; _DAT_00728d34 = 1;
    _DAT_00728d3c = 1; _DAT_00728d38 = 1; _DAT_00728d40 = 2; _DAT_00728d48 = 2;
    _DAT_00728d44 = 2; _DAT_00728d4c = 1;
    DAT_00728d80 = ((static_cast<int32_t>(-static_cast<int32_t>((*reinterpret_cast<uint32_t*>(b + 0x680) & 0x400u) != 0)) & 0x101) + 2);
    return 1;
}

// 0x5c0b90 — observed shape
uint32_t FUN_005c0b90(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    int32_t local_18[6] = {1, 0, 2, 4, 3, 5};
    uint32_t uVar6 = 0;
    int32_t* piVar7 = reinterpret_cast<int32_t*>(b + 0x558);
    for (;;) {
        uint32_t* puVar8 = nullptr;
        piVar7[-4] = 0;
        uint32_t uVar4 = 0;
        do {
            size_t idx = static_cast<size_t>(uVar6 + 0x11a + local_18[uVar4]);
            if (*reinterpret_cast<int32_t*>(b + idx * 4) != 0) {
                piVar7[-4] = *reinterpret_cast<int32_t*>(b + 0x468 + (local_18[uVar4] + uVar6) * 4);
                break;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < 6);
        if (piVar7[-4] != 0) {
            int32_t iVar3 = FUN_00533c78(0x50);
            if (iVar3 != 0) puVar8 = static_cast<uint32_t*>(FUN_00539210(4, 4, piVar7[-4], 1));
            uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*piVar7);
            if (puVar2 != puVar8) {
                if (puVar2 != nullptr) {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) (**(code**)*puVar2)(1);
                }
                *piVar7 = reinterpret_cast<int32_t>(puVar8);
                if (puVar8 != nullptr) puVar8[1] = puVar8[1] + 1;
            }
            int32_t iVar3b = *piVar7;
            uint32_t* pu8 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3b)) + 0x40) + *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3b)) + 0x34));
            int32_t iVar5 = static_cast<int32_t>((*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3b)) + 0x48) & 0xfffffffu) << 2);
            while (iVar5 != 0) { *pu8 = 0xffffffffu; pu8 = pu8 + 1; iVar5 = iVar5 + -1; }
            for (int32_t i = 0; i != 0; i = i + -1) { *(reinterpret_cast<uint8_t*>(pu8)) = 0xff; pu8 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(pu8) + 1); }
        }
        uVar6 = uVar6 + 0xe;
        piVar7 = piVar7 + 1;
        if (0x37 < uVar6) {
            uint32_t v = *reinterpret_cast<uint32_t*>(b + 0x548);
            return (v & 0xffffff00u) | static_cast<uint32_t>(v != 0);
        }
    }
}

extern char DAT_006c7244;
extern char DAT_006c7248;
extern char DAT_006c724c;
extern char DAT_006c7250;
extern uint32_t DAT_0072741c;
extern uint32_t DAT_00727420;
extern uint32_t DAT_00727404;
extern uint32_t DAT_007278a8;
extern int32_t sprintf(char*, const char*, ...);
extern char* FUN_005bfcd0(void);
extern void FUN_005c10f0(void*, int32_t);
extern void FUN_0053c9e0(void*, uint32_t);
extern void* FUN_0053cac0(void*, void*, void*);
extern int8_t FUN_005bd960(uint32_t, int32_t**);
extern void FUN_00545310(uint32_t, int32_t);
extern void operator_delete(void*);
extern void FUN_005d0030(uint32_t);

// 0x5c0c90 — observed shape
char* FUN_005c0c90(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(b + 0x268);
    char* dest = reinterpret_cast<char*>(b + 0x68);
    *dest = '\0';
    uint32_t local_458[0x113];
    for (int i = 0x113; i != 0; i--) local_458[0x113 - i] = 0;
    uint8_t auStack_268[612];
    for (size_t i = 0; i < sizeof(auStack_268); i++) auStack_268[i] = 0;
    int32_t iVar2 = static_cast<int32_t>((**(code**)(DAT_00728d74 + 0x14))(DAT_00728d74, uVar1, 0, reinterpret_cast<uint32_t>(local_458)));
    if (-1 < iVar2) {
        int32_t k = static_cast<int32_t>(*reinterpret_cast<uint32_t*>(b + 0x26c));
        char* puVar4;
        if (k == 1) puVar4 = &DAT_006c7244;
        else if (k == 2) puVar4 = &DAT_006c7248;
        else if (k == 3) puVar4 = &DAT_006c724c;
        else puVar4 = &DAT_006c7250;
        uint32_t u = static_cast<uint32_t>(reinterpret_cast<intptr_t>(FUN_005bfcd0()));
        (void)u;
        sprintf(dest, "%s (%s-%s)", reinterpret_cast<char*>(auStack_268), puVar4, reinterpret_cast<char*>(static_cast<intptr_t>(u)));
    }
    return dest;
}

// 0x5c0dc0 — observed shape
int32_t FUN_005c0dc0(void* self, uint32_t* param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t f5a8 = *reinterpret_cast<uint32_t*>(b + 0x5a8);
    uint32_t uVar6 = 0;
    int32_t iVar10 = 0;
    int32_t iVar8 = 0;
    if (param_1 == nullptr) {
        iVar10 = static_cast<int32_t>(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(f5a8)) + 4));
        iVar8 = static_cast<int32_t>(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(f5a8)) + 8));
    } else {
        uint32_t uVar5 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(f5a8)) + 4);
        uVar6 = *param_1;
        uint32_t uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(f5a8)) + 8);
        if (uVar5 <= uVar6) return 0;
        uint32_t uVar2 = param_1[2];
        if (uVar1 <= uVar2) return 0;
        iVar10 = static_cast<int32_t>((param_1[1] - uVar6) + 1);
        if (uVar5 < static_cast<uint32_t>(iVar10) + uVar6) iVar10 = static_cast<int32_t>(uVar5 - uVar6);
        iVar8 = static_cast<int32_t>((param_1[3] - uVar2) + 1);
        if (uVar1 < static_cast<uint32_t>(iVar8) + uVar2) iVar8 = static_cast<int32_t>(uVar1 - uVar2);
    }
    int32_t* piVar7 = reinterpret_cast<int32_t*>(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(f5a8)) + 0xc));
    int32_t* local_3c = piVar7;
    (**(code**)(*piVar7 + 0x30))();
    uint32_t uStack_38 = uVar6;
    int32_t iStack_30 = iVar10;
    int32_t iStack_2c = iVar8;
    int32_t iVar3 = static_cast<int32_t>((**(code**)(*piVar7 + 0x34))(reinterpret_cast<uint32_t>(piVar7), 0, reinterpret_cast<uint32_t>(&uStack_38), 0x10));
    (void)local_3c; (void)iStack_30; (void)iStack_2c;
    // NEEDS_MANUAL: unaff_ESI/unaff_EDI and on-stack capture buffer shape are not fully recovered; preserved observed operations below.
    if (iVar3 == 0) {
        iVar3 = FUN_00533c78(0x50);
        if (iVar3 != 0) {
            uint32_t piMode = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(reinterpret_cast<uint32_t>(piVar7))) + 0x16a * 4 + 0x14);
            iVar3 = reinterpret_cast<int32_t>(FUN_00539210(iVar10, iVar8, piMode, 1));
            if (iVar3 != 0) {
                uint32_t uVar6b = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x38) * *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x48);
                uint32_t* puVar4 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x40) + *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x34));
                if (iVar8 != 0) {
                    int32_t iStack_14 = iVar8;
                    uint32_t* src = nullptr;
                    uint32_t stride = 0;
                    do {
                        uint32_t* s = src;
                        uint32_t* d = puVar4;
                        for (uint32_t n = uVar6b >> 2; n != 0; n--) { *d = *s; s++; d++; }
                        for (uint32_t n = uVar6b & 3; n != 0; n--) { *(reinterpret_cast<uint8_t*>(d)) = *(reinterpret_cast<uint8_t*>(s)); s = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(s) + 1); d = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(d) + 1); }
                        puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar4) + uVar6b);
                        src = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(src) + stride);
                        iStack_14 = iStack_14 + -1;
                    } while (iStack_14 != 0);
                }
                (**(code**)(*piVar7 + 0x38))(reinterpret_cast<uint32_t>(piVar7));
                return iVar3;
            }
        }
        (**(code**)(*piVar7 + 0x38))(reinterpret_cast<uint32_t>(piVar7));
    }
    return 0;
}

// 0x5c0f20 — observed shape
void FUN_005c0f20(void* self, int32_t* param_1, uint32_t* param_2, int32_t param_3, int32_t param_4)
{
    if (param_1 == nullptr) return;
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t* ecxWords = static_cast<uint32_t*>(self);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(ecxWords[0x16a])) + 0xc);
    int32_t iVar2 = param_1[6];
    if (iVar2 == 0) {
        (**(code**)(*ecxWords + 0x114))(reinterpret_cast<uint32_t>(param_1));
        iVar2 = param_1[6];
    }
    iVar2 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0xc);
    if (iVar2 == 0) return;
    uint32_t local_10, local_c, local_8, local_4;
    uint32_t uVar3, uVar4;
    if (param_2 == nullptr) {
        local_c = 0; local_10 = 0;
        local_8 = (**(code**)(*param_1 + 0x34))(reinterpret_cast<uint32_t>(param_1));
        uVar4 = (**(code**)(*param_1 + 0x38))(reinterpret_cast<uint32_t>(param_1));
    } else {
        local_10 = *param_2; local_8 = param_2[1]; local_c = param_2[2]; local_4 = param_2[3];
        uVar3 = (**(code**)(*param_1 + 0x34))(reinterpret_cast<uint32_t>(param_1));
        uVar4 = (**(code**)(*param_1 + 0x38))(reinterpret_cast<uint32_t>(param_1));
        if (uVar3 < local_10) local_10 = uVar3;
        if (uVar3 < local_8) local_8 = uVar3;
        if (uVar4 < local_c) local_c = uVar4;
        if (local_4 <= uVar4) goto done_min;
        local_4 = uVar4;
    }
    local_4 = uVar4;
done_min:
    int32_t iStack_18 = param_3;
    int32_t iStack_14 = param_4;
    int32_t p3 = static_cast<int32_t>((static_cast<int32_t>(local_8) - *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(ecxWords[0x16a])) + 4)) - static_cast<int32_t>(local_10)) + param_3;
    if (0 < p3) local_8 = static_cast<uint32_t>(static_cast<int32_t>(local_8) - p3);
    int32_t p4 = static_cast<int32_t>((static_cast<int32_t>(local_4) - *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(ecxWords[0x16a])) + 8)) - static_cast<int32_t>(local_c)) + param_4;
    if (0 < p4) local_4 = static_cast<uint32_t>(static_cast<int32_t>(local_4) - p4);
    uint32_t rect[4] = {local_10, local_8, local_c, local_4};
    (void)rect;
    uint32_t target = ecxWords[0x18];
    (void)uVar1;
    (void)iStack_14; (void)iStack_18;
    (void)b;
    (**(code**)(target + 0x78))(target, static_cast<uint32_t>(iVar2), reinterpret_cast<uint32_t>(rect), uVar1, reinterpret_cast<uint32_t>(&iStack_18));
}

// 0x5c1090 — observed shape
void FUN_005c1090(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    DWORD tid = GetCurrentThreadId();
    if (DAT_0072741c == tid) {
        if ((DAT_00727420 = DAT_00727420 - 1) == 0) {
            DAT_0072741c = 0;
            LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_00727404));
        }
    }
    if (*(b + 0x44c) != 0) {
        uint32_t f60 = *reinterpret_cast<uint32_t*>(b + 0x60);
        int32_t r = static_cast<int32_t>((**(code**)(f60 + 0xa8))(f60));
        if (-1 < r) *(b + 0x44c) = 0;
    }
}

// 0x5c10f0 — observed shape
void FUN_005c10f0(float* param_1, float* param_2)
{
    float s = param_2[0xc];
    param_1[0] = param_2[0] * s;
    param_1[1] = param_2[3] * s;
    param_1[2] = param_2[6] * s;
    param_1[4] = param_2[1] * s;
    param_1[5] = param_2[4] * s;
    param_1[6] = param_2[7] * s;
    param_1[8] = param_2[2] * s;
    param_1[9] = param_2[5] * s;
    param_1[10] = param_2[8] * s;
    param_1[0xc] = param_2[9];
    param_1[0xd] = param_2[10];
    param_1[0xe] = param_2[0xb];
}

// 0x5c1160 — observed shape
void FUN_005c1160(float* param_1, float* param_2)
{
    float s = param_2[0xc];
    param_1[0] = param_2[0] * s;
    param_1[1] = param_2[1] * s;
    param_1[2] = param_2[2] * s;
    param_1[4] = param_2[3] * s;
    param_1[5] = param_2[4] * s;
    param_1[6] = param_2[5] * s;
    param_1[8] = param_2[6] * s;
    param_1[9] = param_2[7] * s;
    param_1[10] = param_2[8] * s;
    param_1[3] = param_2[9];
    param_1[7] = param_2[10];
    param_1[0xb] = param_2[0xb];
}

// 0x5c11d0 — observed shape
void FUN_005c11d0(void* self, int32_t param_1, int8_t param_2)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    FUN_005c10f0(b + 0x780, reinterpret_cast<float*>(static_cast<intptr_t>(param_1)));
    if (param_2 != 0) {
        uint32_t f60 = *reinterpret_cast<uint32_t*>(b + 0x60);
        (**(code**)(f60 + 0xb0))(f60, 0x100, reinterpret_cast<uint32_t>(b + 0x780));
    }
    uint32_t f5cc = *reinterpret_cast<uint32_t*>(b + 0x5cc);
    (**(code**)(f5cc + 0x34))(static_cast<uint32_t>(param_1));
    uint32_t stack28[10];
    FUN_0053c9e0(stack28, *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x30));
    uint32_t* puVar1 = static_cast<uint32_t*>(FUN_0053cac0(nullptr, b + 0x2dc, stack28));
    *reinterpret_cast<uint32_t*>(b + 0x2f4) = puVar1[0];
    *reinterpret_cast<uint32_t*>(b + 0x2f8) = puVar1[1];
    *reinterpret_cast<uint32_t*>(b + 0x2fc) = puVar1[2];
    puVar1 = static_cast<uint32_t*>(FUN_0053cac0(nullptr, b + 0x2e8, stack28));
    *reinterpret_cast<uint32_t*>(b + 0x300) = puVar1[0];
    *reinterpret_cast<uint32_t*>(b + 0x304) = puVar1[1];
    *reinterpret_cast<uint32_t*>(b + 0x308) = puVar1[2];
}

// 0x5c1290 — observed shape
// NEEDS_MANUAL: unaff_retaddr (+0x20) is a caller-provided base whose provenance is not recovered in the listing; preserved as an explicit parameter.
void FUN_005c1290(void* self, int32_t param_1, uint32_t param_2, uint32_t param_3, int32_t retaddr_base)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t f5cc = *reinterpret_cast<uint32_t*>(b + 0x5cc);
    (**(code**)(f5cc + 0x34))(param_3);
    FUN_005c10f0(b + 0x780, reinterpret_cast<float*>(static_cast<intptr_t>(param_3)));
    int32_t iVar1 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(retaddr_base)) + 0x20);
    uint32_t uVar2 = 0;
    uint32_t f60 = *reinterpret_cast<uint32_t*>(b + 0x60);
    do {
        uint16_t idx = *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 4)) + uVar2 * 2);
        uint32_t addr = static_cast<uint32_t>(idx) * 0x40 + static_cast<uint32_t>(iVar1);
        (**(code**)(f60 + 0xb0))(f60, uVar2 + 0x100, addr);
        (void)param_2;
        uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
}

// 0x5c12f0 — observed shape
void FUN_005c12f0(int32_t* param_1)
{
    if (param_1 != nullptr) {
        uint32_t* puVar2 = static_cast<uint32_t*>((**(code**)(*param_1 + 4))());
        uint8_t found = 0;
        while (puVar2 != nullptr) {
            if (puVar2 == &DAT_007278a8) { found = 1; break; }
            puVar2 = reinterpret_cast<uint32_t*>(puVar2[1]);
        }
        uint32_t v = static_cast<uint32_t>(-found) & reinterpret_cast<uint32_t>(param_1);
        if (v != 0) FUN_005d0030(v);
    }
}

// 0x5c1340 — observed shape
void FUN_005c1340(void* self, int32_t param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    if (param_1 != 0) {
        int32_t iVar7 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x38);
        if (iVar7 != 0) {
            int32_t local_8 = iVar7;
            if ((*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar7)) + 0x14) != 0) && (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar7)) + 0x1c) != 0)) {
                DWORD tid = GetCurrentThreadId();
                if (*reinterpret_cast<DWORD*>(b + 0x30) != tid) {
                    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(b + 0x18));
                    *reinterpret_cast<DWORD*>(b + 0x30) = GetCurrentThreadId();
                }
                *reinterpret_cast<int32_t*>(b + 0x34) = *reinterpret_cast<int32_t*>(b + 0x34) + 1;
                uint32_t local_4 = 0;
                if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar7)) + 0x14) != 0) {
                    int32_t* list = reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar7)) + 0x1c));
                    while (true) {
                        int32_t iVar6;
                        if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar7)) + 0x14) == 0) { iVar6 = 0; }
                        else { iVar6 = *(list + local_4); }
                        uint32_t uVar10 = local_4;
                        uint32_t uVar2 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar6)) + 4);
                        int32_t* local_c = nullptr;
                        int8_t c = FUN_005bd960(uVar2, &local_c);
                        if (c != 0) {
                            int32_t* piVar1 = nullptr;
                            int32_t* piVar3 = local_c;
                            iVar7 = local_8;
                            while ((local_8 = iVar7, piVar3 != nullptr)) {
                                if (*piVar3 == param_1) {
                                    int32_t* piVar9 = nullptr;
                                    if (piVar1 == nullptr) {
                                        if (piVar3[0xb] == 0) FUN_005bfa50(nullptr, uVar2);
                                        else { FUN_00545310(uVar2, piVar3[0xb]); piVar9 = reinterpret_cast<int32_t*>(piVar3[0xb]); }
                                    } else {
                                        piVar1[0xb] = piVar3[0xb];
                                        piVar9 = reinterpret_cast<int32_t*>(piVar3[0xb]);
                                    }
                                    piVar3[0xb] = 0;
                                    operator_delete(piVar3);
                                    piVar3 = piVar9;
                                    iVar7 = local_8;
                                    uVar10 = local_4;
                                } else {
                                    piVar1 = piVar3;
                                    piVar3 = reinterpret_cast<int32_t*>(piVar3[0xb]);
                                }
                            }
                        }
                        local_4 = uVar10 + 1;
                        if (!(local_4 < *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar7)) + 0x14))) break;
                    }
                }
                DWORD now = GetCurrentThreadId();
                if (*reinterpret_cast<int32_t*>(b + 0x30) == static_cast<int32_t>(now)) {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(b + 0x34);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        *reinterpret_cast<uint32_t*>(b + 0x30) = 0;
                        LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(b + 0x18));
                    }
                }
            }
            uint32_t f5c0 = *reinterpret_cast<uint32_t*>(b + 0x5c0);
            (**(code**)(f5c0 + 0x24))(static_cast<uint32_t>(param_1), 0);
        }
    }
}
