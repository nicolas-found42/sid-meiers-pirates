#include <cstdint>
#include <cstddef>
#include <windows.h>

// 0x5d5880 — observed shape
// Receiver: in_ECX. Params: int param_1. If *(int*)(self+0x226c)==param_1
// clears it and calls vtable at *(int**)(self+0x2284) offset 0x170 with (obj,0);
// if *(int*)(self+0x2270)==param_1 clears it. Void.
extern "C" void FUN_005d5880(void* self, int param_1) {
    // Ghidra ECX receiver modeled as explicit self.
    uint8_t* s = static_cast<uint8_t*>(self);
    int* p_226c = reinterpret_cast<int*>(s + 0x226c);
    if (*p_226c == param_1) {
        *p_226c = 0;
        int** p_2284 = reinterpret_cast<int**>(s + 0x2284);
        int* obj = *p_2284;
        // vtable call offset 0x170: (**(code**)(*obj + 0x170))(obj, 0)
        using Fn = void (__cdecl*)(void*, int);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<int*>((char*)obj + 0x170));
        fn(obj, 0);
    }
    int* p_2270 = reinterpret_cast<int*>(s + 0x2270);
    if (*p_2270 == param_1) {
        *p_2270 = 0;
    }
}

// 0x5d5b90 — observed shape
// Receiver: in_ECX. Param: char param_1. If param_1 != *(char*)(self+0x22a0)
// and *(char*)(*(int*)(self+0x2288)+0x279)!='\0', stores param_1, calls
// vtable *(int**)(self+0x2284) offset 0x134 (obj,param_1), clears self+0x226c.
extern "C" void FUN_005d5b90(void* self, char param_1) {
    uint8_t* s = static_cast<uint8_t*>(self);
    int* p_2288 = reinterpret_cast<int*>(s + 0x2288);
    int obj2288 = *p_2288;
    char flag = *(char*)((char*)obj2288 + 0x279);
    if ((param_1 != *(char*)(s + 0x22a0)) && (flag != '\0')) {
        *(char*)(s + 0x22a0) = param_1;
        int** p_2284 = reinterpret_cast<int**>(s + 0x2284);
        int* obj = *p_2284;
        using Fn = void (__cdecl*)(void*, char);
        Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<int*>((char*)obj + 0x134));
        fn(obj, param_1);
        *(uint32_t*)(s + 0x226c) = 0;
    }
}

// 0x5d5be0 — observed shape
// Receiver: in_ECX (int*, address >>2 fields). Void().
// Calls vtable offsets 0x60,0x78,0xc4,0xe8, calls FUN_005db810, then repeated
// vtable 0x70(id,value,0) sequence, stores DAT_00727424/28/2c into [0x24..0x26].
extern "C" void FUN_005db810(void);
extern uint32_t DAT_00727424;
extern uint32_t DAT_00727428;
extern uint32_t DAT_0072742c;
extern "C" void FUN_005d5be0(int* self) {
    // vtable calls via *self
    vtable_call:;
    using Fn0 = void (__cdecl*)();
    auto call0 = [&](int off) {
        Fn0 fn = *reinterpret_cast<Fn0*>(reinterpret_cast<char*>(*self) + off);
        // NOTE: pseudocode calls with implicit ECX = *self; fn() preserves order.
        fn();
    };
    // For faithful pseudocode: (**(code**)(*in_ECX+off))() — no explicit args.
    call0(0x60);
    call0(0x78);
    call0(0xc4);
    call0(0xe8);
    FUN_005db810();
    using Fn3 = void (__cdecl*)(int, int, int);
    auto call3 = [&](int id, int val, int c) {
        Fn3 fn = *reinterpret_cast<Fn3*>(reinterpret_cast<char*>(*self) + 0x70);
        fn(id, val, c);
    };
    call3(0x16, 2, 0);
    call3(8, 3, 0);
    call3(9, 2, 0);
    call3(0x1b, 0, 0);
    call3(0x13, self[0xf], 0);
    call3(0x14, self[0x10], 0);
    call3(0xf, 0, 0);
    call3(0x19, 8, 0);
    call3(0x18, 0, 0);
    call3(0x17, 8, 0);
    call3(0xe, 0, 0);
    call3(0x1a, 0, 0);
    call3(0x1d, 0, 0);
    call3(0x1c, 0, 0);
    {
        uint8_t byte2 = *(reinterpret_cast<uint8_t*>(self) + 2);
        int v = -((byte2 & 1) != 0) & 3;
        call3(0x23, v, 0);
    }
    call3(0x8c, 3, 0);
    call3(0x30, 0, 0);
    call3(0x22, 0, 0);
    call3(0x8f, 1, 0);
    uint32_t uVar1;
    if (((char)self[3] == '\0') || (uVar1 = 2, ((static_cast<uint32_t>(self[2]) >> 4) & 1) == 0)) {
        uVar1 = 1;
    }
    call3(7, static_cast<int>(uVar1), 0);
    call3(0x8d, 1, 0);
    self[0x24] = static_cast<int>(DAT_00727424);
    self[0x25] = static_cast<int>(DAT_00727428);
    self[0x26] = static_cast<int>(DAT_0072742c);
}

// 0x5d5d80 — observed shape
// Receiver: in_ECX. Void. Flag tests on self+0x22c8/0x22f0/self+8 bit0/5/4,
// 11-iteration mask loop from self+0x24 vs masks 0x22d0/0x22d4 building
// bitmasks at 0x70/0x74, and 0x22a0 byte from object at 0x2288 +0x278/0x279.
extern "C" void FUN_005d5d80(void* self) {
    uint8_t* s = static_cast<uint8_t*>(self);
    uint32_t f22c8 = *(uint32_t*)(s + 0x22c8);
    uint32_t uVar1;
    if (((f22c8 & 0x100) == 0) || ((f22c8 & 0x100000) == 0)) {
        uVar1 = *(uint32_t*)(s + 8) & 0xfffffffeu;
    } else {
        uVar1 = *(uint32_t*)(s + 8) | 1u;
    }
    *(uint32_t*)(s + 8) = uVar1;
    *(uint32_t*)(s + 0x74) = 0;
    *(uint32_t*)(s + 0x70) = 0;
    uint32_t idx = 0;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(s + 0x24);
    uint32_t maskD0 = *(uint32_t*)(s + 0x22d0);
    uint32_t maskD4 = *(uint32_t*)(s + 0x22d4);
    do {
        if ((*puVar2 & maskD0) != 0) {
            *(uint32_t*)(s + 0x70) = *(uint32_t*)(s + 0x70) | (1u << ((uint8_t)idx & 0x1f));
        }
        if ((*puVar2 & maskD4) != 0) {
            *(uint32_t*)(s + 0x74) = *(uint32_t*)(s + 0x74) | (1u << ((uint8_t)idx & 0x1f));
        }
        idx = idx + 1;
        puVar2 = puVar2 + 1;
    } while (idx < 0xb);
    if ((*(uint8_t*)(s + 0x22f0) & 0x10) == 0) {
        uVar1 = *(uint32_t*)(s + 8) & 0xffffffdfu;
    } else {
        uVar1 = *(uint32_t*)(s + 8) | 0x20u;
    }
    *(uint32_t*)(s + 8) = uVar1;
    if ((f22c8 & 0x40000) == 0) {
        *(uint32_t*)(s + 8) = *(uint32_t*)(s + 8) & 0xffffffefu;
    } else {
        *(uint32_t*)(s + 8) = *(uint32_t*)(s + 8) | 0x10u;
    }
    int obj2288 = *(int*)(s + 0x2288);
    char c278 = *(char*)((char*)obj2288 + 0x278);
    char c279 = *(char*)((char*)obj2288 + 0x279);
    if ((c278 == '\0') || (c279 != '\0')) {
        *(uint8_t*)(s + 0x22a0) = 0;
        return;
    }
    *(uint8_t*)(s + 0x22a0) = 1;
}

// 0x5d5e70 — observed shape
// Allocates 0x23d4 bytes via FUN_00533c78; runs FUN_005db220(param_1), sets
// vtable PTR_FUN_006c8798, copies 0x4c ints from param_2 to piVar1+0x8a9, sets
// flag bits [2] from param_3/6/4, calls vtable 0x110, scans DAT_00717ce8 table
// stride 0x20 for value 7 sets, copies param_5 byte, refcounts FUN_005dbaf0 result
// at slot 0x89f. Returns constructed object or null.
extern "C" void* FUN_00533c78(uint32_t size);
extern "C" void FUN_005db220(uint32_t param_1);
extern "C" void* FUN_005dbaf0(uint32_t param_1, int* param_2);
extern int* PTR_FUN_006c8798;
extern "C" int* FUN_005d5e70(uint32_t param_1, int* param_2, char param_3, char param_4, uint8_t param_5, char param_6) {
    int* piVar1 = static_cast<int*>(FUN_00533c78(0x23d4));
    if (piVar1 == nullptr) {
        // Ghidra: if alloc fails, piVar1 stays 0x0, but the rest below still
        // runs on piVar1 (param_3 flag, vtable 0x110 call, table scan).
        // Preserve observed fall-through: continue with null base guarded same
        // as Ghidra body (the flag/table stores would fault in real binary;
        // keep faithful structure below, dereferencing piVar1 as in listing).
    } else {
        FUN_005db220(param_1);
        *piVar1 = reinterpret_cast<int>(&PTR_FUN_006c8798);
        *(uint8_t*)(piVar1 + 0x8a8) = 0;
        int* piVar6 = param_2;
        int* piVar7 = piVar1 + 0x8a9;
        for (int iVar5 = 0x4c; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar7 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
        }
    }
    if (param_3 != '\0') {
        piVar1[2] = piVar1[2] | 2;
    }
    {
        using Fn = void (__cdecl*)();
        Fn fn = *reinterpret_cast<Fn*>(reinterpret_cast<char*>(*piVar1) + 0x110);
        fn();
    }
    // Table scan: DAT_00717ce8 as int array, stride 0x20 bytes per entry.
    // Ghidra quads DAT_00717ce8/ec/f0/f4/f8/fc/d00/d04 at +0/+4/+8/+0xc/+10/+14/+18/+1c.
    // Entry accessed as (int*)&DAT_00717ce8 + uVar2 where uVar2 counts bytes.
    extern int DAT_00717ce8;
    uint32_t uVar2 = 0;
    // Helper lambdas for int/uint at table offsets.
    auto t_int = [&](uint32_t off) -> int {
        return *reinterpret_cast<int*>(reinterpret_cast<char*>(&DAT_00717ce8) + uVar2 + off);
    };
    auto t_set = [&](uint32_t off, uint32_t v) {
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(&DAT_00717ce8) + uVar2 + off) = v;
    };
    do {
        if (t_int(0) == -1) break;
        if (t_int(0) == 7) {
            t_set(4, static_cast<uint32_t>(param_4 != '\0'));
        }
        if (t_int(8) == -1) break;
        if (t_int(8) == 7) {
            t_set(12, static_cast<uint32_t>(param_4 != '\0'));
        }
        if (t_int(16) == -1) break;
        if (t_int(16) == 7) {
            t_set(20, static_cast<uint32_t>(param_4 != '\0'));
        }
        if (t_int(24) == -1) break;
        if (t_int(24) == 7) {
            t_set(28, static_cast<uint32_t>(param_4 != '\0'));
        }
        uVar2 = uVar2 + 0x20;
    } while (uVar2 < 0x800);
    if (param_6 != '\0') {
        piVar1[2] = piVar1[2] | 4;
        // Walk pairs: while (*p != 7) p += 2 (uint32_t* steps of 4 bytes).
        // Ghidra: puVar3=&DAT_00717ce8; iVar5=DAT_00717ce8; while(iVar5!=7){...}
        // piVar6=puVar3+2; puVar3=puVar3+2; iVar5=*piVar6;
        // then puVar3[1]=1.
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(&DAT_00717ce8);
        int iVar5 = DAT_00717ce8;
        while (iVar5 != 7) {
            uint32_t* piVar6 = puVar3 + 2;
            puVar3 = puVar3 + 2;
            iVar5 = static_cast<int>(*piVar6);
        }
        puVar3[1] = 1;
    }
    if (param_4 != '\0') {
        piVar1[2] = piVar1[2] | 8;
    }
    *(uint8_t*)(piVar1 + 3) = param_5;
    uint32_t* puVar4 = static_cast<uint32_t*>(FUN_005dbaf0(param_1, param_2));
    uint32_t* puVar3b = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(piVar1[0x89f]));
    if (puVar3b != puVar4) {
        if (puVar3b != nullptr) {
            uint32_t* piVar6 = puVar3b + 1;
            *piVar6 = *piVar6 - 1;
            if (*piVar6 == 0) {
                using Fn = void (__cdecl*)(int);
                Fn fn = *reinterpret_cast<Fn*>(*puVar3b);
                fn(1);
            }
        }
        piVar1[0x89f] = static_cast<int>(reinterpret_cast<uintptr_t>(puVar4));
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
        }
    }
    return piVar1;
}
// 0x5d5fd0 — observed shape
// Receiver: in_ECX. Returns undefined4 *(self + 4).
extern "C" uint32_t FUN_005d5fd0(void* self) {
    return *(uint32_t*)(static_cast<uint8_t*>(self) + 4);
}

// 0x5d6040 — observed shape
// Receiver: in_ECX (undefined4*). Sets *self = &PTR_FUN_006c88fc,
// operator_delete__((void*)self[2]), then *self = &PTR_LAB_006c88ac.
extern void* PTR_FUN_006c88fc;
extern void* PTR_LAB_006c88ac;
extern "C" void operator_delete__(void* ptr);
extern "C" void FUN_005d6040(uint32_t* self) {
    *self = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c88fc));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(self[2])));
    *self = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_LAB_006c88ac));
}

// 0x5d6060 — observed shape
// Allocates 0x10 bytes into DAT_00728ed4, inits vtable PTR_FUN_006c88fc and
// zeroes [1..3], then FUN_005c9280 on PTR_DAT_006c892c and PTR_LAB_006c8928
// with the new object.
extern "C" void* FUN_00533c78(uint32_t size);
extern "C" void FUN_005c9280(void* a, void* b);
extern uint32_t* DAT_00728ed4;
extern void* PTR_FUN_006c88fc;
extern void* PTR_DAT_006c892c;
extern void* PTR_LAB_006c8928;
extern "C" void FUN_005d6060(void) {
    DAT_00728ed4 = static_cast<uint32_t*>(FUN_00533c78(0x10));
    if (DAT_00728ed4 == nullptr) {
        DAT_00728ed4 = nullptr;
    } else {
        DAT_00728ed4[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c88fc));
        DAT_00728ed4[1] = 0;
        DAT_00728ed4[2] = 0;
        DAT_00728ed4[3] = 0;
    }
    FUN_005c9280(&PTR_DAT_006c892c, DAT_00728ed4);
    FUN_005c9280(&PTR_LAB_006c8928, DAT_00728ed4);
}

// 0x5d60b0 — observed shape
// Allocates 0x10 bytes into DAT_00728ed8, zeroes [1..3] then sets vtable
// PTR_FUN_006c8930, then FUN_005c9280 on the two string-descriptor globals
// "are quite a handsome young ruffi..." and "...you are quite a handsome young".
extern "C" void* FUN_00533c78(uint32_t size);
extern "C" void FUN_005c9280(void* a, void* b);
extern uint32_t* DAT_00728ed8;
extern void* PTR_FUN_006c8930;
extern void* PTR_s_are_quite_a_handsome_young_ruffi_006f7330_0x46_006c8960;
extern void* PTR_s___you_are_quite_a_handsome_young_006f7330_0x40_006c895c;
extern "C" void FUN_005d60b0(void) {
    DAT_00728ed8 = static_cast<uint32_t*>(FUN_00533c78(0x10));
    if (DAT_00728ed8 == nullptr) {
        DAT_00728ed8 = nullptr;
    } else {
        DAT_00728ed8[1] = 0;
        DAT_00728ed8[2] = 0;
        DAT_00728ed8[3] = 0;
        DAT_00728ed8[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c8930));
    }
    FUN_005c9280(&PTR_s_are_quite_a_handsome_young_ruffi_006f7330_0x46_006c8960, DAT_00728ed8);
    FUN_005c9280(&PTR_s___you_are_quite_a_handsome_young_006f7330_0x40_006c895c, DAT_00728ed8);
}

// 0x5d6100 — observed shape
// Param: int param_1. Walks linked list DAT_00717cbc matching node[2]==param_1
// via *node next pointers. On miss, allocates via indirect call through
// PTR_PTR_00717cb8+4, sets [2]=param_1, [0]=0, [1]=DAT_00717cc0, links into
// list at DAT_00717cc0 and bumps DAT_00717cc4 count.
extern uint32_t* DAT_00717cbc;
extern uint32_t* DAT_00717cc0;
extern uint32_t DAT_00717cc4;
extern void* PTR_PTR_00717cb8;
extern "C" void FUN_005d6100(int param_1) {
    uint32_t* puVar2 = DAT_00717cbc;
    uint32_t* puVar1 = nullptr;
    bool found = false;
    do {
        puVar1 = puVar2;
        if (puVar1 == nullptr) {
            goto allocate;
        }
        puVar2 = *reinterpret_cast<uint32_t**>(static_cast<uintptr_t>(*puVar1));
        if (param_1 == static_cast<int>(puVar1[2])) {
            found = true;
            break;
        }
    } while (true);
    if (found) {
        return;
    }
allocate:
    {
        using AllocFn = uint32_t* (__cdecl*)();
        AllocFn alloc = *reinterpret_cast<AllocFn*>(reinterpret_cast<uint8_t*>(&PTR_PTR_00717cb8) + 4);
        uint32_t* puVar2b = alloc();
        puVar2b[2] = static_cast<uint32_t>(param_1);
        puVar2b[0] = 0;
        puVar2b[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(DAT_00717cc0));
        if (DAT_00717cc0 != nullptr) {
            *DAT_00717cc0 = reinterpret_cast<uint32_t*>(puVar2b);
            DAT_00717cc0 = puVar2b;
            DAT_00717cc4 = DAT_00717cc4 + 1;
            return;
        }
        DAT_00717cc4 = DAT_00717cc4 + 1;
        DAT_00717cbc = puVar2b;
        DAT_00717cc0 = puVar2b;
    }
    return;
// 0x5d6350 — observed shape
// Increments DAT_00728ea4; if old value was 0 calls FUN_005677b0 with
// &LAB_005d6210 and &LAB_005d6280. Void.
extern int DAT_00728ea4;
extern void* LAB_005d6210;
extern void* LAB_005d6280;
extern "C" void FUN_005677b0(void* a, void* b);
extern "C" void FUN_005d6350(void) {
    int iVar1 = DAT_00728ea4 + 1;
    bool bVar2 = DAT_00728ea4 == 0;
    DAT_00728ea4 = iVar1;
    if (bVar2) {
        FUN_005677b0(&LAB_005d6210, &LAB_005d6280);
    }
    return;
}

// 0x5d6380 — observed shape
// Receiver: in_ECX (undefined4*). Writes: [0]=0, [1]=0, [2]=0xffffffff,
// [3]=0x11, [4]=0, [5]=0, [6]=0. Void.
extern "C" void FUN_005d6380(uint32_t* self) {
    self[0] = 0;
    self[1] = 0;
    self[2] = 0xffffffffu;
    self[3] = 0x11;
    self[4] = 0;
    self[5] = 0;
    self[6] = 0;
}

// 0x5d63b0 — observed shape
// Receiver: in_ECX (int* vtable obj) and in_EAX. Params param_1..param_5;
// param_3 switch maps to (uVar1,uVar3) pairs: 0->(0),1->(1),2->(2),3->(3),
// 4->(10),5->(5),6->(5,1),7->(5,2),8->(5,3),9->(5,4),10->(5,5),0xb->(5,6),
// 0xc->(5,7),0xd->(6),0xe->(7), default returns (in_EAX & 0xffffff00).
// Otherwise calls vtable offset 0x34 with (param_5,param_1,param_2,param_3,
// param_4,uVar1,uVar3,0) and returns its uint result.
extern "C" uint32_t FUN_005d63b0(int* self, uint32_t in_EAX, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5) {
    uint32_t uVar3 = 0;
    uint32_t uVar1 = 0;
    switch (param_3) {
    case 0:
        uVar1 = 0;
        break;
    case 1:
        uVar1 = 1;
        break;
    case 2:
        uVar1 = 2;
        break;
    case 3:
        uVar1 = 3;
        break;
    case 4:
        uVar1 = 10;
        break;
    case 5:
        uVar1 = 5;
        break;
    case 6:
        uVar1 = 5;
        uVar3 = 1;
        break;
    case 7:
        uVar1 = 5;
        uVar3 = 2;
        break;
    case 8:
        uVar1 = 5;
        uVar3 = 3;
        break;
    case 9:
        uVar1 = 5;
        uVar3 = 4;
        break;
    case 10:
        uVar1 = 5;
        uVar3 = 5;
        break;
    case 0xb:
        uVar1 = 5;
        uVar3 = 6;
        break;
    case 0xc:
        uVar1 = 5;
        uVar3 = 7;
        break;
    case 0xd:
        uVar1 = 6;
        break;
    case 0xe:
        uVar1 = 7;
        break;
    default:
        return in_EAX & 0xffffff00u;
    }
    using Fn = uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int);
    Fn fn = *reinterpret_cast<Fn*>(reinterpret_cast<char*>(*self) + 0x34);
    return fn(param_5, param_1, param_2, param_3, param_4, uVar1, uVar3, 0);
}

// 0x5d6630 — observed shape
// Receiver: in_ECX (int*). Param: uint param_1. If param_1 < (uint)self[9],
// calls vtable self+0x54 with no args and returns *(undefined4*)(self[10]+0xc+param_1*0x10).
// Else returns 0.
extern "C" uint32_t FUN_005d6630(int* self, uint32_t param_1) {
    if (param_1 < static_cast<uint32_t>(self[9])) {
        using Fn = void (__cdecl*)();
        Fn fn = *reinterpret_cast<Fn*>(reinterpret_cast<char*>(*self) + 0x54);
        fn();
        return *(uint32_t*)(self[10] + 0xc + param_1 * 0x10);
    }
    return 0;
}

// 0x5d6660 — observed shape
// Receiver: in_ECX (int*). Params: int* param_1, int* param_2.
// Calls vtable self+0x54, stores result to *param_1, stores self[9] to *param_2,
// returns (*param_1 != 0).
extern "C" bool FUN_005d6660(int* self, int* param_1, int* param_2) {
    using Fn = int (__cdecl*)();
    Fn fn = *reinterpret_cast<Fn*>(reinterpret_cast<char*>(*self) + 0x54);
    int iVar1 = fn();
    *param_1 = iVar1;
    *param_2 = self[9];
    return *param_1 != 0;
// 0x5d6690 — observed shape
// Receiver: in_ECX. Params: int param_1 (pointer), undefined2 param_2.
// Writes 8-byte stride record at *(int*)(self+0x30)+*(int*)(self+0x1c)*8:
// [0:2]=param_2, [2:2]=*(undefined2*)(param_1+4), [4]=DAT_007186f8[idx0*4],
// [5]=DAT_00718740[idx1*4], [6]=DAT_0071875c[idx2*4], [7]=*(byte*)(param_1+0x18),
// bumps *(int*)(self+0x1c)++, returns DAT_00728d98[idx0*4] if idx0<0x12 else 0.
extern uint32_t DAT_007186f8;
extern uint32_t DAT_00718740;
extern uint32_t DAT_0071875c;
extern uint32_t DAT_00728d98;
extern "C" uint32_t FUN_005d6690(void* self, int param_1, uint16_t param_2) {
    uint8_t* s = static_cast<uint8_t*>(self);
    int idx = *(int*)(s + 0x1c);
    int base = *(int*)(s + 0x30);
    *(uint16_t*)(base + idx * 8) = param_2;
    *(uint16_t*)(base + 2 + idx * 8) = *(uint16_t*)(param_1 + 4);
    *(uint8_t*)(base + 4 + idx * 8) = reinterpret_cast<uint8_t*>(&DAT_007186f8)[*(int*)(param_1 + 0xc) * 4];
    *(uint8_t*)(base + 5 + idx * 8) = reinterpret_cast<uint8_t*>(&DAT_00718740)[*(int*)(param_1 + 0x10) * 4];
    *(uint8_t*)(base + 6 + idx * 8) = reinterpret_cast<uint8_t*>(&DAT_0071875c)[*(int*)(param_1 + 0x14) * 4];
    *(uint8_t*)(base + 7 + idx * 8) = *(uint8_t*)(param_1 + 0x18);
    *(int*)(s + 0x1c) = idx + 1;
    if (*(int*)(param_1 + 0xc) < 0x12) {
        return *(uint32_t*)(reinterpret_cast<uint8_t*>(&DAT_00728d98) + *(int*)(param_1 + 0xc) * 4);
    }
    return 0;
}

// 0x5d6720 — observed shape
// Params: param_1 (switch key), uint param_2, int* param_3, out1/2/3.
// Switch sets (*param_3,*param_4,*param_5,*param_6) and returns 1; case 5 also
// requires param_2<8 (*param_3=param_2+5). Cases absent / fall-through return 0.
extern "C" int FUN_005d6720(uint32_t param_1, uint32_t param_2, int* param_3, uint32_t* param_4, uint32_t* param_5, uint32_t* param_6) {
    switch (param_1) {
    case 0:
        *param_3 = 0;
        *param_4 = 2;
        *param_5 = 0;
        *param_6 = 0;
        return 1;
    case 1:
        *param_3 = 1;
        *param_4 = 2;
        *param_5 = 1;
        *param_6 = 0;
        return 1;
    case 2:
        *param_3 = 2;
        *param_4 = 4;
        *param_5 = 2;
        *param_6 = 0;
        return 1;
    case 3:
        *param_3 = 3;
        *param_4 = 2;
        *param_5 = 3;
        *param_6 = 0;
        return 1;
    case 5:
        if (param_2 < 8) {
            *param_3 = static_cast<int>(param_2 + 5);
            *param_4 = 1;
            *param_5 = 5;
            *param_6 = 0;
            return 1;
        }
        break;
    case 6:
        *param_3 = 0xd;
        *param_4 = 2;
        *param_5 = 6;
        *param_6 = 0;
        return 1;
    case 7:
        *param_3 = 0xe;
        *param_4 = 2;
        *param_5 = 7;
        *param_6 = 0;
        return 1;
    case 10:
        *param_3 = 4;
        *param_4 = 4;
        *param_5 = 10;
        *param_6 = 0;
        return 1;
    }
    return 0;
}

// 0x5d68d0 — observed shape
// Param: uint param_1 (struct pointer). Copies random ushorts from FUN_005f0ddc
// into buffer *(param_1+0x28) over rows *(short*)(param_1+0xc), each row width
// clamped to [2 | (* (param_1+4)!=6)*2] vs *(ushort*)(param_1+8), padding with
// zero ushorts/uints; returns accumulated height at +0x20 over rows.
extern "C" uint16_t FUN_005f0ddc(void);
extern "C" int FUN_005d68d0(uint32_t param_1) {
    int iVar4 = param_1;
    int* piVar1 = reinterpret_cast<int*>(param_1 + 4);
    uint32_t* local_14 = *reinterpret_cast<uint32_t**>(param_1 + 0x28);
    uint16_t* puVar2 = reinterpret_cast<uint16_t*>(param_1 + 8);
    uint32_t param_1b = *puVar2;
    int iVar8 = 0;
    int local_10 = 0;
    uint32_t uVar3 = static_cast<uint32_t>(*piVar1 != 6) * 2 + 2;
    if (0 < static_cast<int16_t>(*puVar2 - static_cast<uint16_t>(uVar3))) {
        param_1b = uVar3;
    }
    uint16_t uVar6 = 0;
    if (static_cast<int16_t>(*reinterpret_cast<short*>(iVar4 + 0xc)) != 0) {
        do {
            uint32_t uVar9 = 0;
            uint32_t* puVar10 = local_14;
            if (static_cast<int16_t>(param_1b) != 0) {
                uVar9 = param_1b;
                do {
                    uint16_t uVar5 = FUN_005f0ddc();
                    *reinterpret_cast<uint16_t*>(puVar10) = uVar5;
                    puVar10 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar10) + 2);
                    uVar9 = uVar9 - 1;
                } while (uVar9 != 0);
                uVar9 = param_1b;
            }
            if (static_cast<uint16_t>(uVar9) < static_cast<uint16_t>(uVar3)) {
                for (uint32_t uVar7 = (uVar3 - uVar9 & 0xffffu) >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *puVar10 = 0;
                    puVar10 = puVar10 + 1;
                }
                for (uVar9 = static_cast<uint32_t>(((uVar3 - uVar9 & 1u) != 0)); uVar9 != 0; uVar9 = uVar9 - 1) {
                    *reinterpret_cast<uint16_t*>(puVar10) = 0;
                    puVar10 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar10) + 2);
                }
            }
            iVar8 = local_10 + *reinterpret_cast<int*>(iVar4 + 0x20);
            local_14 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(local_14) + *reinterpret_cast<int*>(iVar4 + 0x24));
            uVar6 = uVar6 + 1;
            local_10 = iVar8;
        } while (uVar6 < *reinterpret_cast<uint16_t*>(iVar4 + 0xc));
    }
    return iVar8;
}

// 0x5d69c0 — observed shape
// Param: int param_1 (struct pointer). Copies buffer *(param_1+0x14) ushorts
// into buffer *(param_1+0x28) over rows *(short*)(param_1+0xc), width clamped
// to [*(short*)(param_1+8)-4] vs [*(param_1+4)!=6]*2+2, zero-padding; returns
// accumulated height at +0x20 over rows. Strides: +0x1c src, +0x24 dst.
extern "C" int FUN_005d69c0(int param_1) {
    int iVar3 = param_1;
    uint32_t* puVar9 = *reinterpret_cast<uint32_t**>(param_1 + 0x28);
    uint16_t* puVar10 = *reinterpret_cast<uint16_t**>(param_1 + 0x14);
    int iVar8 = 0;
    uint16_t uVar4 = static_cast<uint16_t>(static_cast<int16_t>(*reinterpret_cast<short*>(param_1 + 8)) - 4);
    int local_10 = 0;
    int iVar1 = static_cast<int>(static_cast<uint32_t>(*reinterpret_cast<int*>(param_1 + 4) != 6) * 2 + 2);
    uint16_t uVar2 = static_cast<uint16_t>(iVar1);
    uint16_t param_1w = uVar2;
    if (static_cast<int16_t>(uVar4 - uVar2) < 1) {
        param_1w = uVar4;
    }
    uVar4 = 0;
    if (static_cast<int16_t>(*reinterpret_cast<short*>(iVar3 + 0xc)) != 0) {
        do {
            uint32_t uVar6 = 0;
            uint32_t* puVar11 = puVar9;
            if (param_1w != 0) {
                uVar6 = static_cast<uint32_t>(param_1w);
                uint16_t* puVar5 = puVar10;
                uint32_t uVar7 = uVar6;
                do {
                    *reinterpret_cast<uint16_t*>(puVar11) = *puVar5;
                    puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar11) + 2);
                    puVar5 = puVar5 + 2;
                    uVar7 = uVar7 - 1;
                } while (uVar7 != 0);
            }
            if (static_cast<uint16_t>(uVar6) < uVar2) {
                uVar6 = static_cast<uint32_t>(iVar1) - uVar6;
                for (uint32_t uVar7 = (uVar6 & 0xffffu) >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *puVar11 = 0;
                    puVar11 = puVar11 + 1;
                }
                for (uVar6 = static_cast<uint32_t>(((uVar6 & 1u) != 0)); uVar6 != 0; uVar6 = uVar6 - 1) {
                    *reinterpret_cast<uint16_t*>(puVar11) = 0;
                    puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar11) + 2);
                }
            }
            iVar8 = local_10 + *reinterpret_cast<int*>(iVar3 + 0x20);
            puVar10 = reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(puVar10) + *reinterpret_cast<int*>(iVar3 + 0x1c));
            puVar9 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar9) + *reinterpret_cast<int*>(iVar3 + 0x24));
            uVar4 = uVar4 + 1;
            local_10 = iVar8;
        } while (uVar4 < *reinterpret_cast<uint16_t*>(iVar3 + 0xc));
    }
    return iVar8;
}

// 0x5d6a90 — observed shape
// Param: uint param_1 (struct pointer). Copies buffer *(param_1+0x14) ushorts
// into buffer *(param_1+0x28) over rows *(short*)(param_1+0xc), width clamped
// to [*(short*)(param_1+8)-8] vs [*(param_1+4)!=6]*2+2, zero-padding; returns
// accumulated height at +0x20 over rows. Strides: +0x1c src, +0x24 dst.
extern "C" int FUN_005d6a90(uint32_t param_1) {
    int iVar2 = param_1;
    uint32_t* local_c = *reinterpret_cast<uint32_t**>(param_1 + 0x28);
    uint16_t* puVar7 = *reinterpret_cast<uint16_t**>(param_1 + 0x14);
    uint16_t uVar3 = static_cast<uint16_t>(static_cast<int16_t>(*reinterpret_cast<short*>(param_1 + 8)) - 8);
    int local_10 = 0;
    uint32_t uVar1 = static_cast<uint32_t>(*reinterpret_cast<int*>(param_1 + 4) != 6) * 2 + 2;
    uint32_t param_1b = uVar1;
    if (static_cast<int16_t>(uVar3 - static_cast<uint16_t>(uVar1)) < 1) {
        param_1b = static_cast<uint32_t>(uVar3);
    }
    uVar3 = 0;
    if (static_cast<int16_t>(*reinterpret_cast<short*>(iVar2 + 0xc)) != 0) {
        do {
            uint32_t uVar5 = 0;
            uint32_t* puVar8 = local_c;
            if (static_cast<int16_t>(param_1b) != 0) {
                uint16_t* puVar4 = puVar7;
                uVar5 = param_1b;
                do {
                    *reinterpret_cast<uint16_t*>(puVar8) = *puVar4;
                    puVar8 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar8) + 2);
                    puVar4 = puVar4 + 2;
                    uVar5 = uVar5 - 1;
                } while (uVar5 != 0);
                uVar5 = param_1b;
            }
            if (static_cast<uint16_t>(uVar5) < static_cast<uint16_t>(uVar1)) {
                for (uint32_t uVar6 = (uVar1 - uVar5 & 0xffffu) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *puVar8 = 0;
                    puVar8 = puVar8 + 1;
                }
                for (uVar5 = static_cast<uint32_t>(((uVar1 - uVar5 & 1u) != 0)); uVar5 != 0; uVar5 = uVar5 - 1) {
                    *reinterpret_cast<uint16_t*>(puVar8) = 0;
                    puVar8 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar8) + 2);
                }
            }
            local_c = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(local_c) + *reinterpret_cast<int*>(iVar2 + 0x24));
            local_10 = local_10 + *reinterpret_cast<int*>(iVar2 + 0x20);
            puVar7 = reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(puVar7) + *reinterpret_cast<int*>(iVar2 + 0x1c));
            uVar3 = uVar3 + 1;
        } while (uVar3 < *reinterpret_cast<uint16_t*>(iVar2 + 0xc));
    }
    return local_10;
}
