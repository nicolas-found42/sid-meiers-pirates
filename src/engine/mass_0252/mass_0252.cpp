#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers referenced by the assigned listings.
extern bool FUN_006b5090(int param_1, void* param_2);
extern bool FUN_006b50b0(int param_1, void* param_2, int param_3);
extern bool FUN_006b5020(int param_1, void* param_2);
extern void FUN_005ea3c0();
// operator delete variants used by the listings.
extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern bool FUN_005e8960(int param_1, void* param_2);
extern bool FUN_006b4f80(int param_1, void* param_2);
extern void FUN_005ea660(int param_1);
extern void FUN_005ea690(int param_1);

// 0x5eef30 — bool reader with receiver ECX; field chain +0x14/+0x18/+0x58/+0x5c
bool FUN_005eef30(void* self, int param_1)
{
    int iVar1 = param_1;
    char cVar2 = FUN_006b5090(param_1, &param_1) ? 1 : 0;
    if (cVar2 != '\0') {
        *(bool*)((char*)self + 0x14) = (param_1 == 1);
        cVar2 = FUN_006b50b0(iVar1, (char*)self + 0x18, 0x10) ? 1 : 0;
        if (cVar2 != '\0') {
            cVar2 = FUN_006b5090(iVar1, (char*)self + 0x58) ? 1 : 0;
            if (cVar2 != '\0') {
                cVar2 = FUN_006b5020(iVar1, (char*)self + 0x5c) ? 1 : 0;
                return cVar2 != '\0';
            }
        }
    }
    return false;
}

// 0x5eefa0 — void cleanup with receiver ECX as undefined4*; frees fields [0x17], [0], [3], [4]
void FUN_005eefa0(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    operator_delete__((void*)in_ECX[0x17]);
    operator_delete__((void*)in_ECX[0]);
    void* pvVar1 = (void*)in_ECX[3];
    if (pvVar1 != nullptr) {
        FUN_005ea3c0();
        operator_delete(pvVar1);
    }
    pvVar1 = (void*)in_ECX[4];
    if (pvVar1 != nullptr) {
        FUN_005ea3c0();
        operator_delete(pvVar1);
    }
}

// 0x5eeff0 — bool nested-reader chain with receiver ECX; fields +4/+8/+0xc/+0x10, tail FUN_005eef30
bool FUN_005eeff0(void* self, uint32_t param_1)
{
    char cVar1 = FUN_006b5020((int)param_1, nullptr) ? 1 : 0;
    if (cVar1 != '\0') {
        cVar1 = FUN_006b5090((int)param_1, (char*)self + 4) ? 1 : 0;
        if (cVar1 != '\0') {
            cVar1 = FUN_006b5090((int)param_1, (char*)self + 8) ? 1 : 0;
            if (cVar1 != '\0') {
                cVar1 = FUN_005e8960((int)param_1, (char*)self + 0xc) ? 1 : 0;
                if (cVar1 != '\0') {
                    cVar1 = FUN_005e8960((int)param_1, (char*)self + 0x10) ? 1 : 0;
                    if (cVar1 != '\0') {
                        cVar1 = FUN_005eef30(self, (int)param_1) ? 1 : 0;
                        return cVar1 != '\0';
                    }
                }
            }
        }
    }
    return false;
}

// 0x5ef080 — void early-return wrapper with receiver ECX; checks field +0x5c then FUN_005ea660
void FUN_005ef080(void* self, uint32_t param_1)
{
    char cVar1 = FUN_006b4f80((int)param_1, *(void**)((char*)self + 0x5c)) ? 1 : 0;
    if (cVar1 == '\0') {
        return;
    }
    FUN_005ea660((int)param_1);
}

// 0x5ef0b0 — void early-return wrapper with receiver ECX; reads field +0x5c then FUN_005ea690
void FUN_005ef0b0(void* self, uint32_t param_1)
{
    char cVar1 = FUN_006b5020((int)param_1, (char*)self + 0x5c) ? 1 : 0;
    if (cVar1 == '\0') {
        return;
    }
    FUN_005ea690((int)param_1);
}
// 0x5ef190 — uint32 id-remap switch(param_1) writing *param_2; default path returns 0 mid-switch
uint32_t FUN_005ef190(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 0x17; return 1;
    case 1: *param_2 = 0x19; return 1;
    case 2: *param_2 = 0x1b; return 1;
    case 3: *param_2 = 0xf; return 1;
    case 4: *param_2 = 0x18; return 1;
    case 5: *param_2 = 0x13; return 1;
    case 6: *param_2 = 0x14; return 1;
    case 7: *param_2 = 0xe; return 1;
    case 8: *param_2 = 0x1a; return 1;
    case 9: *param_2 = 9; return 1;
    case 10: *param_2 = 0xa8; return 1;
    case 0xb: *param_2 = 0x36; return 1;
    case 0xc: *param_2 = 0x37; return 1;
    case 0xd: *param_2 = 0x38; return 1;
    case 0xe: *param_2 = 0x39; return 1;
    case 0xf: *param_2 = 0x3a; return 1;
    case 0x10: *param_2 = 0x3b; return 1;
    case 0x11: *param_2 = 0xab; return 1;
    default: return 0;
    case 0x1b: *param_2 = 0x1c; return 1;
    case 0x1c: *param_2 = 0x23; return 1;
    case 0x1d: *param_2 = 0x24; return 1;
    case 0x1e: *param_2 = 0x25; return 1;
    case 0x1f: *param_2 = 0x26; return 1;
    case 0x20: *param_2 = 0x30; return 1;
    case 0x21: *param_2 = 0x80; return 1;
    case 0x22: *param_2 = 0x81; return 1;
    case 0x23: *param_2 = 0x82; return 1;
    case 0x24: *param_2 = 0x83; return 1;
    case 0x25: *param_2 = 0x84; return 1;
    case 0x26: *param_2 = 0x85; return 1;
    case 0x27: *param_2 = 0x86; return 1;
    case 0x28: *param_2 = 0x87; return 1;
    case 0x29: *param_2 = 0x89; return 1;
    case 0x2a: *param_2 = 0x1d; return 1;
    case 0x2b: *param_2 = 0x8e; return 1;
    case 0x2c: *param_2 = 0x8d; return 1;
    case 0x31: *param_2 = 0x92; return 1;
    case 0x32: *param_2 = 0x91; return 1;
    case 0x33: *param_2 = 0x93; return 1;
    case 0x34: *param_2 = 0x94; return 1;
    case 0x36: *param_2 = 0x8b; return 1;
    case 0x37: *param_2 = 0x9a; return 1;
    case 0x38: *param_2 = 0x9b; return 1;
    case 0x39: *param_2 = 0x9c; return 1;
    case 0x3a: *param_2 = 0x9d; return 1;
    case 0x3b: *param_2 = 0x9e; return 1;
    case 0x3c: *param_2 = 0x9f; return 1;
    case 0x3d: *param_2 = 0xa0; return 1;
    case 0x3e: *param_2 = 0xa6; return 1;
    case 0x3f: *param_2 = 0xa3; return 1;
    case 0x43: *param_2 = 0x97; return 1;
    case 0x44: *param_2 = 0x22; return 1;
    case 0x45: *param_2 = 8; return 1;
    case 0x48: *param_2 = 0x8f; return 1;
    case 0x49: *param_2 = 7; return 1;
    case 0x4a: *param_2 = 0x34; return 1;
    case 0x4b: *param_2 = 0x35; return 1;
    case 0x4d: *param_2 = 0x16; return 1;
    case 0x4e: *param_2 = 0x3c; return 1;
    case 0x52: *param_2 = 0xa1; return 1;
    case 0x53: *param_2 = 0xa2; return 1;
    case 0x61: *param_2 = 0x10; return 1;
    case 0x62: *param_2 = 0x88; return 1;
    case 99: *param_2 = 0x8c; return 1;
    case 100: *param_2 = 0x98; return 1;
    case 0x66: *param_2 = 0xa5; return 1;
    case 0x67: *param_2 = 0xa7; return 1;
    case 0x68: *param_2 = 0xaa; return 1;
    case 0x6b: *param_2 = 0xac; return 1;
    case 0x6c: *param_2 = 0xad; return 1;
    case 0x6d: *param_2 = 0xae; return 1;
    case 0x6e: *param_2 = 0xaf; return 1;
    case 0x6f: *param_2 = 0xb0; return 1;
    case 0x70: *param_2 = 0xb2; return 1;
    case 0x71: *param_2 = 0xb3; return 1;
    case 0x72: *param_2 = 0xb4; return 1;
    case 0x73: *param_2 = 0xb5; return 1;
    case 0x74: *param_2 = 0xb6; return 1;
    case 0x75: *param_2 = 0xb7; return 1;
    case 0x77: *param_2 = 0xb9; return 1;
    case 0x78: *param_2 = 0xba; return 1;
    case 0x79: *param_2 = 0xbb; return 1;
    case 0x7a: *param_2 = 0xbc; return 1;
    case 0x7b: *param_2 = 0xbd; return 1;
    case 0x7c: *param_2 = 0xbe; return 1;
    case 0x7d: *param_2 = 0xbf; return 1;
    case 0x7e: *param_2 = 0xc0; return 1;
    case 0x7f: *param_2 = 0xc1; return 1;
    case 0x80: *param_2 = 0xc2; return 1;
    case 0x81: *param_2 = 0xc3; return 1;
    case 0x82: *param_2 = 0xc6; return 1;
    case 0x83: *param_2 = 199; return 1;
    case 0x84: *param_2 = 200; return 1;
    case 0x85: *param_2 = 0xc9; return 1;
    case 0x86: *param_2 = 0xca; return 1;
    case 0x87: *param_2 = 0xcb; return 1;
    case 0x88: *param_2 = 0xcc; return 1;
    case 0x89: *param_2 = 0xcd; return 1;
    case 0x8a: *param_2 = 0xce; return 1;
    case 0x8b: *param_2 = 0xcf; return 1;
    case 0x8c: *param_2 = 0xd0; return 1;
    case 0x8d: *param_2 = 0xd1; return 1;
    }
}

// 0x5ef910 — uint32 identity map 0/1/2 -> *param_2, else 0
uint32_t FUN_005ef910(int param_1, uint32_t* param_2)
{
    if (param_1 == 0) { *param_2 = 0; return 1; }
    if (param_1 == 1) { *param_2 = 1; return 1; }
    if (param_1 == 2) { *param_2 = 2; return 1; }
    return 0;
}

// 0x5ef950 — uint32 +1 map 0/1/2 -> 1/2/3, else 0
uint32_t FUN_005ef950(int param_1, uint32_t* param_2)
{
    if (param_1 == 0) { *param_2 = 1; return 1; }
    if (param_1 == 1) { *param_2 = 2; return 1; }
    if (param_1 == 2) { *param_2 = 3; return 1; }
    return 0;
}

// 0x5ef990 — uint32 +1 switch 0..0xc -> 1..0xd, default 0
uint32_t FUN_005ef990(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 1; return 1;
    case 1: *param_2 = 2; return 1;
    case 2: *param_2 = 3; return 1;
    case 3: *param_2 = 4; return 1;
    case 4: *param_2 = 5; return 1;
    case 5: *param_2 = 6; return 1;
    case 6: *param_2 = 7; return 1;
    case 7: *param_2 = 8; return 1;
    case 8: *param_2 = 9; return 1;
    case 9: *param_2 = 10; return 1;
    case 10: *param_2 = 0xb; return 1;
    case 0xb: *param_2 = 0xc; return 1;
    case 0xc: *param_2 = 0xd; return 1;
    default: return 0;
    }
}

// 0x5efa90 — uint32 identity switch 0..3, default 0
uint32_t FUN_005efa90(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 0; return 1;
    case 1: *param_2 = 1; return 1;
    case 2: *param_2 = 2; return 1;
    case 3: *param_2 = 3; return 1;
    default: return 0;
    }
}
// 0x5efaf0 — uint32 +1 switch 0..7 -> 1..8, default 0
uint32_t FUN_005efaf0(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 1; return 1;
    case 1: *param_2 = 2; return 1;
    case 2: *param_2 = 3; return 1;
    case 3: *param_2 = 4; return 1;
    case 4: *param_2 = 5; return 1;
    case 5: *param_2 = 6; return 1;
    case 6: *param_2 = 7; return 1;
    case 7: *param_2 = 8; return 1;
    default: return 0;
    }
}

// 0x5efb90 — uint32 identity with 3<->4 swap, 0..7, default 0
uint32_t FUN_005efb90(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 0; return 1;
    case 1: *param_2 = 1; return 1;
    case 2: *param_2 = 2; return 1;
    case 3: *param_2 = 4; return 1;
    case 4: *param_2 = 3; return 1;
    case 5: *param_2 = 5; return 1;
    case 6: *param_2 = 6; return 1;
    case 7: *param_2 = 7; return 1;
    default: return 0;
    }
}

// 0x5efc30 — uint32 identity 0..3 and 7->0xff, 8->0x100, default 0 mid-switch
uint32_t FUN_005efc30(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 0; return 1;
    case 1: *param_2 = 1; return 1;
    case 2: *param_2 = 2; return 1;
    case 3: *param_2 = 3; return 1;
    default: return 0;
    case 7: *param_2 = 0xff; return 1;
    case 8: *param_2 = 0x100; return 1;
    }
}

// 0x5efcc0 — uint32 identity 0/1, else 0
uint32_t FUN_005efcc0(int param_1, uint32_t* param_2)
{
    if (param_1 == 0) { *param_2 = 0; return 1; }
    if (param_1 == 1) { *param_2 = 1; return 1; }
    return 0;
}

// 0x5efcf0 — uint32 bit map 0->0x80000000, 1->1, 3->2, 5->4, 7->8, default 0 mid-switch
uint32_t FUN_005efcf0(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 0x80000000; return 1;
    case 1: *param_2 = 1; return 1;
    default: return 0;
    case 3: *param_2 = 2; return 1;
    case 5: *param_2 = 4; return 1;
    case 7: *param_2 = 8; return 1;
    }
}
// 0x5efd70 — uint32 identity 1/2/3/5, default 0 mid-switch
uint32_t FUN_005efd70(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 1: *param_2 = 1; return 1;
    case 2: *param_2 = 2; return 1;
    case 3: *param_2 = 3; return 1;
    default: return 0;
    case 5: *param_2 = 5; return 1;
    }
}

// Extern helper referenced by the 0x5efdd0 dispatcher (not in assignment).
extern uint32_t FUN_005f04c0(uint32_t param_1, uint32_t* param_2);

// 0x5efdd0 — uint32 dispatch by param_1 to converter helpers; default store-and-return-1
uint32_t FUN_005efdd0(uint32_t param_1, uint32_t param_2, uint32_t* param_3)
{
    uint32_t uVar1;
    switch (param_1) {
    case 0:
    case 1:
    case 0xd:
    case 0x56:
        uVar1 = FUN_005efaf0(param_2, param_3);
        return uVar1;
    default:
        *param_3 = param_2;
        return 1;
    case 5:
    case 6:
        uVar1 = FUN_005ef990(param_2, param_3);
        return uVar1;
    case 9:
        uVar1 = FUN_005ef950(param_2, param_3);
        return uVar1;
    case 0xb:
    case 0xc:
    case 0x4b:
        uVar1 = FUN_005efaf0(param_2, param_3);
        return uVar1;
    case 0x11:
        uVar1 = FUN_005f04c0(param_2, param_3);
        return uVar1;
    case 0x13:
    case 0x19:
    case 0x4c:
    case 0x50:
    case 0x54:
    case 0x55:
    case 0x58:
    case 0x69:
    case 0x6a:
        return 0;
    case 0x1c:
    case 99:
        uVar1 = FUN_005efa90(param_2, param_3);
        return uVar1;
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
        uVar1 = FUN_005efb90(param_2, param_3);
        return uVar1;
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
        uVar1 = FUN_005ef910(param_2, param_3);
        return uVar1;
    case 0x3f:
        uVar1 = FUN_005efcc0(param_2, param_3);
        return uVar1;
    case 0x41:
        uVar1 = FUN_005efa90(param_2, param_3);
        return uVar1;
    case 0x42:
        uVar1 = FUN_005efcf0(param_2, param_3);
        return uVar1;
    case 0x43:
        uVar1 = FUN_005efc30(param_2, param_3);
        return uVar1;
    case 0x45:
    case 0x46:
        uVar1 = FUN_005ef950(param_2, param_3);
        return uVar1;
    case 0x49:
        uVar1 = FUN_005ef910(param_2, param_3);
        return uVar1;
    case 0x4d:
        uVar1 = FUN_005ef950(param_2, param_3);
        return uVar1;
    case 0x66:
        uVar1 = FUN_005efcc0(param_2, param_3);
        return uVar1;
    case 0x6b:
    case 0x6c:
        uVar1 = FUN_005efd70(param_2, param_3);
        return uVar1;
    }
}

// 0x5f0020 — uint32 remap with injected 0x1a/0x1b/0x1c and 0x16/0x17/0x18 slots, default 0 mid-switch
uint32_t FUN_005f0020(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 1; return 1;
    case 1: *param_2 = 0x1a; return 1;
    case 2: *param_2 = 2; return 1;
    case 3: *param_2 = 3; return 1;
    case 4: *param_2 = 4; return 1;
    case 5: *param_2 = 0x1b; return 1;
    case 6: *param_2 = 5; return 1;
    case 7: *param_2 = 6; return 1;
    case 8: *param_2 = 0x1c; return 1;
    default: return 0;
    case 10: *param_2 = 7; return 1;
    case 0xb: *param_2 = 8; return 1;
    case 0xc: *param_2 = 9; return 1;
    case 0xd: *param_2 = 10; return 1;
    case 0xe: *param_2 = 0x16; return 1;
    case 0xf: *param_2 = 0x17; return 1;
    case 0x10: *param_2 = 0xb; return 1;
    case 0x11: *param_2 = 0x18; return 1;
    }
}

// 0x5f0160 — uint32 +1 switch 0..0x19 -> 1..0x1a, default 0
uint32_t FUN_005f0160(uint32_t param_1, uint32_t* param_2)
{
    switch (param_1) {
    case 0: *param_2 = 1; return 1;
    case 1: *param_2 = 2; return 1;
    case 2: *param_2 = 3; return 1;
    case 3: *param_2 = 4; return 1;
    case 4: *param_2 = 5; return 1;
    case 5: *param_2 = 6; return 1;
    case 6: *param_2 = 7; return 1;
    case 7: *param_2 = 8; return 1;
    case 8: *param_2 = 9; return 1;
    case 9: *param_2 = 10; return 1;
    case 10: *param_2 = 0xb; return 1;
    case 0xb: *param_2 = 0xc; return 1;
    case 0xc: *param_2 = 0xd; return 1;
    case 0xd: *param_2 = 0xe; return 1;
    case 0xe: *param_2 = 0xf; return 1;
    case 0xf: *param_2 = 0x10; return 1;
    case 0x10: *param_2 = 0x11; return 1;
    case 0x11: *param_2 = 0x12; return 1;
    case 0x12: *param_2 = 0x13; return 1;
    case 0x13: *param_2 = 0x14; return 1;
    case 0x14: *param_2 = 0x15; return 1;
    case 0x15: *param_2 = 0x16; return 1;
    case 0x16: *param_2 = 0x17; return 1;
    case 0x17: *param_2 = 0x18; return 1;
    case 0x18: *param_2 = 0x19; return 1;
    case 0x19: *param_2 = 0x1a; return 1;
    default: return 0;
    }
}

// 0x5f0340 — uint packed-flag decode with receiver EAX; bit 0x40000000 and sign extend result flags
uint32_t FUN_005f0340(uint32_t param_1, uint32_t* param_2)
{
    uint32_t in_EAX = 0;
    if (param_1 == 0x7fffffff) {
        return in_EAX & 0xffffff00;
    }
    switch (param_1 & 0xfffffff) {
    case 0: *param_2 = 1; break;
    case 1: *param_2 = 0; break;
    case 2: *param_2 = 0xf; break;
    case 3: *param_2 = 4; break;
    case 4: *param_2 = 5; break;
    case 5: *param_2 = 2; break;
    case 6: *param_2 = 3; break;
    }
    if ((param_1 & 0x40000000) != 0) {
        *param_2 = *param_2 | 0x20;
    }
    if ((int32_t)param_1 < 0) {
        *param_2 = *param_2 | 0x10;
    }
    return (((param_1 & 0xfffffff) >> 8) << 8) | 1;
}
