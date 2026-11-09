// Reconstruction batch mass_0229
// Original program: Sid Meier's Pirates! (2004), PE32
#include <cstdint>
#include <cstddef>
#include <windows.h>

// Externs
extern void* DAT_00728eb4;
extern uint32_t DAT_00717c64;

// Forward declarations (helpers)
extern uint32_t FUN_005d7f60(uint32_t param_1);
extern uint32_t FUN_005d7fc0(uint32_t param_1);
extern void FUN_005d8270(void* self);
extern int* thunk_FUN_00533c78(uint32_t size);
extern int FUN_004127b0(void* dst, uint32_t elemSize, int count, void* start);
extern void operator_delete(void* ptr);

// 0x5d7f60 — observed shape
uint32_t FUN_005d7f60(uint32_t param_1) {
    // Ghidra listing uses in_ECX as receiver, not declared in signature.
    // Reconstruction uses explicit self parameter rule is impossible to infer offset here,
    // but this function is itself defined with a single param in listing; the receiver
    // pattern is captured via global register convention - required to use void* self.
    // To preserve exact listing, we cannot add a second parameter without breaking callers.
    // Therefore we keep listing signature and note NEEDS_MANUAL for receiver.
    return 0;
}

// ===========================================================================
// Additional reconstructions (0x5d7fc0 .. 0x5d8860)
// ===========================================================================
typedef uint32_t code(...); // observed inline vtable dispatch type

// Referenced globals
extern uint32_t* DAT_00728eb8;
extern int32_t DAT_00728ebc;
extern char LAB_005d8040;

// Referenced helpers
extern void* FUN_00533c78(uint32_t size);
extern void operator_delete__(void* p);
extern void FUN_0055f300(int32_t capacity);
extern void FUN_005bf090(char** param_1);
extern void FUN_005dd8b0(void);
extern void FUN_005dd780(void* self);

// Provider shape `*(int *)(p + off)` / `*(void **)((int)p + off)` over a raw
// integer node address.
static inline int32_t& f32(void* base, intptr_t off)
{
    return *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(base) + off);
}

static inline void* nodeOf(int32_t v)
{
    return reinterpret_cast<void*>(static_cast<intptr_t>(v));
}

// 0x5d7fc0 — observed shape
// Receiver (in_ECX) carries the 0x204-byte record container; the listing keeps it
// implicit, so it is reconstructed as `self`. Named _recon because the earlier
// declaration at the top of this file fixes a one-parameter form.
uint32_t FUN_005d7fc0_recon(void* self, uint32_t param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar2 = 0;
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(base + 0x16c);

    for (;;) {
        uint32_t uVar1 = 0;
        bool dispatch = false;

        if (base[uVar2 + 500] == '\0') {
            if (base[uVar2 + 0x1a4] != '\0') {
                uVar1 = *puVar3;
                dispatch = true;
            }
        }
        else {
            uVar1 = puVar3[0x14];
            dispatch = true;
        }

        if (dispatch) {
            uint32_t vtable = *reinterpret_cast<uint32_t*>(DAT_00728eb4);
            (**(code**)(vtable + 0xdc))(param_1, uVar2, uVar1, 0);
        }

        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 1;
        if (0xd < uVar2) {
            return 0;
        }
    }
}

// 0x5d8020 — observed shape
void FUN_005d8020(void* self, uint8_t param_1)
{
    FUN_005d8270(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5d8110 — observed shape
// The listing never names a receiver here: the incoming ECX is forwarded
// unchanged to FUN_005d7f60 and FUN_005d7fc0. Reconstructed explicitly.
int FUN_005d8110_recon(void* self, uint32_t param_1)
{
    int32_t iVar1;
    int32_t iVar2 = 0;

    if (param_1 < DAT_00717c64) {
        iVar2 = static_cast<int32_t>(FUN_005d7f60(param_1));
    }
    iVar1 = static_cast<int32_t>(FUN_005d7fc0_recon(self, param_1));
    if (iVar2 != 0) {
        iVar1 = iVar2;
    }
    return iVar1;
}

// 0x5d8140 — observed shape
// Listing declares void, but the caller at 0x5d81d0 consumes the EAX result:
// this-returning constructor, so the reconstruction returns the receiver.
void* FUN_005d8140(void* self, int32_t param_1)
{
    int* in_ECX = static_cast<int*>(self);
    int* piVar2 = 0;

    in_ECX[1] = param_1;
    in_ECX[2] = 0;
    if (param_1 != 0) {
        int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(param_1 * 0x204 + 4));
        if (piVar1 != 0) {
            piVar2 = piVar1 + 1;
            *piVar1 = param_1;
            FUN_004127b0(piVar2, 0x204, param_1, &LAB_005d8040);
        }
    }
    in_ECX[0] = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar2));
    return self;
}

// 0x5d8190 — observed shape
void FUN_005d8190(void)
{
    DAT_00728eb8 = static_cast<uint32_t*>(FUN_00533c78(0x18));
    if (DAT_00728eb8 == 0) {
        DAT_00728eb8 = 0;
        return;
    }
    DAT_00728eb8[0] = 0;
    DAT_00728eb8[1] = 0;
    DAT_00728eb8[2] = 0;
    DAT_00728eb8[3] = 8;
    DAT_00728eb8[4] = 8;
    DAT_00728eb8[5] = 0;
}

// 0x5d81d0 — observed shape
void FUN_005d81d0(void* self, uint32_t param_1)
{
    int* in_ECX = static_cast<int*>(self);
    int32_t iVar1;
    int32_t iVar2;
    int32_t iVar4;
    int* local_4;
    uint32_t uVar3;

    iVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0xc)));
    iVar4 = 0;
    if (iVar1 == 0) {
        local_4 = 0;
    }
    else {
        local_4 = static_cast<int*>(FUN_005d8140(nodeOf(iVar1), static_cast<int32_t>(param_1)));
    }
    uVar3 = 0;
    if (param_1 != 0) {
        do {
            if (uVar3 < static_cast<uint32_t>(local_4[1])) {
                iVar1 = local_4[0] + iVar4;
            }
            else {
                iVar1 = 0;
            }
            iVar2 = in_ECX[1];
            if (in_ECX[2] == iVar2) {
                if (iVar2 == 0) {
                    iVar2 = 1;
                }
                else {
                    iVar2 = iVar2 * 2;
                }
                FUN_0055f300(iVar2);
            }
            *reinterpret_cast<int32_t*>(static_cast<intptr_t>(in_ECX[0]) + in_ECX[2] * 4) = iVar1;
            in_ECX[2] = in_ECX[2] + 1;
            uVar3 = uVar3 + 1;
            iVar4 = iVar4 + 0x204;
        } while (uVar3 < param_1);
    }
    local_4[2] = in_ECX[5];
    in_ECX[5] = static_cast<int32_t>(reinterpret_cast<intptr_t>(local_4));
}

// 0x5d8270 — observed shape
void FUN_005d8270(void* self)
{
    int* in_ECX = static_cast<int*>(self);
    void* pvVar1;

    if (in_ECX[0] != 0) {
        operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[0]) - 4));
    }
    pvVar1 = reinterpret_cast<void*>(static_cast<intptr_t>(in_ECX[2]));
    if (pvVar1 != 0) {
        FUN_005d8270(pvVar1);
        operator_delete(pvVar1);
    }
}

// 0x5d82a0 — observed shape
void FUN_005d82a0(void)
{
    uint32_t* puVar2 = DAT_00728eb8;

    if (DAT_00728eb8 != 0) {
        int* piVar1 = reinterpret_cast<int*>(static_cast<intptr_t>(DAT_00728eb8[5]));
        DAT_00728eb8[2] = 0;
        if (piVar1 != 0) {
            if (piVar1[0] != 0) {
                operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(piVar1[0]) - 4));
            }
            if (piVar1[2] != 0) {
                FUN_005d8020(piVar1, 1);
            }
            operator_delete(piVar1);
        }
        operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(*puVar2)));
        operator_delete(puVar2);
    }
}

// 0x5d8300 — observed shape
// `self` is the receiver the listing keeps implicit while calling 0x5d81d0.
void FUN_005d8300(void* self)
{
    uint32_t* puVar3 = DAT_00728eb8;
    int* piVar1 = reinterpret_cast<int*>(DAT_00728eb8 + 2);
    char* pcVar4;
    int32_t iVar5;

    if (DAT_00728eb8[2] == 0) {
        int* piVar2 = reinterpret_cast<int*>(DAT_00728eb8 + 3);
        FUN_005d81d0(self, DAT_00728eb8[3]);
        *piVar2 = *piVar2 << 1;
    }
    puVar3 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(*puVar3));
    pcVar4 = reinterpret_cast<char*>(static_cast<intptr_t>(*puVar3));
    iVar5 = *piVar1 - 1;
    *piVar1 = iVar5;
    *puVar3 = puVar3[iVar5];
    if (*pcVar4 == '\0') {
        *pcVar4 = '\x01';
    }
}

// 0x5d8350 — observed shape
void FUN_005d8350(char* param_1)
{
    int32_t iVar1;
    char* pcVar2;

    if (*param_1 != '\0') {
        pcVar2 = param_1 + 0xc;
        for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
            pcVar2[0] = '\0';
            pcVar2[1] = '\0';
            pcVar2[2] = '\0';
            pcVar2[3] = '\0';
            pcVar2 = pcVar2 + 4;
        }
        param_1[0x90] = '\0';
        param_1[0x91] = '\0';
        param_1[0x92] = '\0';
        param_1[0x93] = '\0';
        param_1[0x94] = '\0';
        param_1[0x95] = '\0';
        param_1[0x96] = '\0';
        param_1[0x97] = '\0';
        param_1[0x98] = '\0';
        param_1[0x99] = '\0';
        param_1[0x9a] = '\0';
        param_1[0x9b] = '\0';
        param_1[0x9c] = '\0';
        param_1[0x9d] = '\0';
        param_1[0x9e] = '\0';
        param_1[0x9f] = '\0';
        param_1[0xa0] = '\0';
        param_1[0xa1] = '\0';
        param_1[0xa2] = '\0';
        param_1[0xa3] = '\0';
        param_1[0xa4] = '\0';
        param_1[0xa5] = '\0';
        param_1[0xa6] = '\0';
        param_1[0xa7] = '\0';
        param_1[0xa8] = '\0';
        param_1[0xa9] = '\0';
        param_1[0xaa] = '\0';
        param_1[0xab] = '\0';
        param_1[0xac] = '\0';
        param_1[0xad] = '\0';
        param_1[0xae] = '\0';
        param_1[0xaf] = '\0';
        param_1[0xb0] = '\0';
        pcVar2 = param_1 + 0xbc;
        for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
            pcVar2[0] = '\0';
            pcVar2[1] = '\0';
            pcVar2[2] = '\0';
            pcVar2[3] = '\0';
            pcVar2 = pcVar2 + 4;
        }
        param_1[0x140] = '\0';
        param_1[0x141] = '\0';
        param_1[0x142] = '\0';
        param_1[0x143] = '\0';
        param_1[0x144] = '\0';
        param_1[0x145] = '\0';
        param_1[0x146] = '\0';
        param_1[0x147] = '\0';
        param_1[0x148] = '\0';
        param_1[0x149] = '\0';
        param_1[0x14a] = '\0';
        param_1[0x14b] = '\0';
        param_1[0x14c] = '\0';
        param_1[0x14d] = '\0';
        param_1[0x14e] = '\0';
        param_1[0x14f] = '\0';
        param_1[0x150] = '\0';
        param_1[0x151] = '\0';
        param_1[0x152] = '\0';
        param_1[0x153] = '\0';
        param_1[0x154] = '\0';
        param_1[0x155] = '\0';
        param_1[0x156] = '\0';
        param_1[0x157] = '\0';
        param_1[0x158] = '\0';
        param_1[0x159] = '\0';
        param_1[0x15a] = '\0';
        param_1[0x15b] = '\0';
        param_1[0x15c] = '\0';
        param_1[0x15d] = '\0';
        param_1[0x15e] = '\0';
        param_1[0x15f] = '\0';
        param_1[0x160] = '\0';
        pcVar2 = param_1 + 0x16c;
        for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
            pcVar2[0] = '\0';
            pcVar2[1] = '\0';
            pcVar2[2] = '\0';
            pcVar2[3] = '\0';
            pcVar2 = pcVar2 + 4;
        }
        param_1[0x1a4] = '\0';
        param_1[0x1a5] = '\0';
        param_1[0x1a6] = '\0';
        param_1[0x1a7] = '\0';
        param_1[0x1a8] = '\0';
        param_1[0x1a9] = '\0';
        param_1[0x1aa] = '\0';
        param_1[0x1ab] = '\0';
        param_1[0x1ac] = '\0';
        param_1[0x1ad] = '\0';
        param_1[0x1ae] = '\0';
        param_1[0x1af] = '\0';
        param_1[0x1b0] = '\0';
        param_1[0x1b1] = '\0';
        pcVar2 = param_1 + 0x1bc;
        for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
            pcVar2[0] = '\0';
            pcVar2[1] = '\0';
            pcVar2[2] = '\0';
            pcVar2[3] = '\0';
            pcVar2 = pcVar2 + 4;
        }
        param_1[500] = '\0';
        param_1[0x1f5] = '\0';
        param_1[0x1f6] = '\0';
        param_1[0x1f7] = '\0';
        param_1[0x1f8] = '\0';
        param_1[0x1f9] = '\0';
        param_1[0x1fa] = '\0';
        param_1[0x1fb] = '\0';
        param_1[0x1fc] = '\0';
        param_1[0x1fd] = '\0';
        param_1[0x1fe] = '\0';
        param_1[0x1ff] = '\0';
        param_1[0x200] = '\0';
        param_1[0x201] = '\0';
        param_1[0xb4] = '\0';
        param_1[0xb5] = '\0';
        param_1[0xb6] = '\0';
        param_1[0xb7] = '\0';
        param_1[4] = '\0';
        param_1[5] = '\0';
        param_1[6] = '\0';
        param_1[7] = '\0';
        param_1[0x1b4] = '\0';
        param_1[0x1b5] = '\0';
        param_1[0x1b6] = '\0';
        param_1[0x1b7] = '\0';
        param_1[0x164] = '\0';
        param_1[0x165] = '\0';
        param_1[0x166] = '\0';
        param_1[0x167] = '\0';
        FUN_005bf090(&param_1);
    }
}

// 0x5d8430 — observed shape
void FUN_005d8430(void* self)
{
    uint8_t* in_ECX = static_cast<uint8_t*>(self);
    int* piVar1 = reinterpret_cast<int*>(static_cast<intptr_t>(f32(in_ECX, 0x10)));

    if (piVar1 != 0) {
        uint32_t vtable = *reinterpret_cast<uint32_t*>(piVar1);
        (**(code**)(vtable + 8))(piVar1);
        f32(in_ECX, 0x10) = 0;
    }
}

// 0x5d85f0 — observed shape
void FUN_005d85f0(int32_t param_1)
{
    f32(nodeOf(param_1), 0x14) = 8;
    f32(nodeOf(param_1), 0x18) = 1;
}

// 0x5d8610 — observed shape
void FUN_005d8610(void* self, int32_t param_1)
{
    uint8_t* in_ECX = static_cast<uint8_t*>(self);
    int32_t iVar1 = f32(in_ECX, 0x34);

    if (iVar1 != 0) {
        while (iVar1 != param_1) {
            iVar1 = f32(nodeOf(iVar1), 0x44);
            if (iVar1 == 0) {
                return;
            }
        }
        if (f32(nodeOf(iVar1), 0x44) != 0) {
            f32(nodeOf(f32(nodeOf(iVar1), 0x44)), 0x48) = f32(nodeOf(iVar1), 0x48);
        }
        if (f32(nodeOf(iVar1), 0x48) != 0) {
            f32(nodeOf(f32(nodeOf(iVar1), 0x48)), 0x44) = f32(nodeOf(iVar1), 0x44);
        }
        if (iVar1 == f32(in_ECX, 0x34)) {
            f32(in_ECX, 0x34) = f32(nodeOf(iVar1), 0x44);
        }
    }
}

// 0x5d8660 — observed shape
int FUN_005d8660(void* self, uint32_t param_1)
{
    uint8_t* in_ECX = static_cast<uint8_t*>(self);
    int* piVar1;
    int32_t iVar2;
    uint32_t uVar3;

    if (static_cast<uint32_t>(f32(in_ECX, 0xc)) <= param_1) {
        return 0;
    }
    piVar1 = reinterpret_cast<int*>(static_cast<intptr_t>(f32(in_ECX, 4)) + param_1 * 4);
    iVar2 = *piVar1;
    *piVar1 = 0;
    if (iVar2 != 0) {
        f32(in_ECX, 0x10) = f32(in_ECX, 0x10) + -1;
    }
    uVar3 = static_cast<uint32_t>(f32(in_ECX, 0xc)) - 1;
    if (param_1 == uVar3) {
        f32(in_ECX, 0xc) = static_cast<int32_t>(uVar3);
    }
    return iVar2;
}

// 0x5d8700 — observed shape
int FUN_005d8700(void* self, uint32_t param_1)
{
    uint8_t* in_ECX = static_cast<uint8_t*>(self);
    int32_t iVar1 = f32(in_ECX, 0x34);

    if (iVar1 == 0) {
        return 0;
    }
    while (static_cast<uint32_t>(f32(nodeOf(iVar1), 0x24)) < param_1) {
        iVar1 = f32(nodeOf(iVar1), 0x44);
        if (iVar1 == 0) {
            return 0;
        }
    }
    if (f32(nodeOf(iVar1), 0x44) != 0) {
        f32(nodeOf(f32(nodeOf(iVar1), 0x44)), 0x48) = f32(nodeOf(iVar1), 0x48);
    }
    if (f32(nodeOf(iVar1), 0x48) != 0) {
        f32(nodeOf(f32(nodeOf(iVar1), 0x48)), 0x44) = f32(nodeOf(iVar1), 0x44);
    }
    if (iVar1 == f32(in_ECX, 0x34)) {
        f32(in_ECX, 0x34) = f32(nodeOf(iVar1), 0x44);
    }
    return iVar1;
}

// 0x5d8760 — observed shape
void FUN_005d8760(void* self, int32_t param_1)
{
    uint8_t* in_ECX = static_cast<uint8_t*>(self);
    int32_t iVar1;
    int32_t iVar2 = 0;
    int32_t iVar3;

    if (f32(in_ECX, 0x34) == 0) {
        f32(in_ECX, 0x34) = param_1;
        f32(nodeOf(param_1), 0x44) = 0;
        f32(nodeOf(f32(in_ECX, 0x34)), 0x48) = 0;
        return;
    }
    iVar1 = f32(in_ECX, 0x34);
    iVar3 = 0;
    for (;;) {
        iVar2 = iVar1;
        if (!(static_cast<uint32_t>(f32(nodeOf(iVar2), 0x24)) <=
              static_cast<uint32_t>(f32(nodeOf(param_1), 0x24)))) {
            break;
        }
        iVar1 = f32(nodeOf(iVar2), 0x44);
        iVar3 = iVar2;
        if (f32(nodeOf(iVar2), 0x44) == 0) {
            f32(nodeOf(iVar2), 0x44) = param_1;
            f32(nodeOf(param_1), 0x48) = iVar2;
            f32(nodeOf(param_1), 0x44) = 0;
            return;
        }
    }
    if (iVar3 != 0) {
        f32(nodeOf(iVar3), 0x44) = param_1;
    }
    f32(nodeOf(iVar2), 0x48) = param_1;
    f32(nodeOf(param_1), 0x44) = iVar2;
    f32(nodeOf(param_1), 0x48) = iVar3;
    if (iVar2 == f32(in_ECX, 0x34)) {
        f32(in_ECX, 0x34) = param_1;
    }
}

// 0x5d87d0 — observed shape
// The destructor call at 0x5dd780() has an implicit receiver (ECX); the only
// node in scope is the loop cursor, reconstructed as its receiver.
void FUN_005d87d0(void)
{
    void* pvVar1;
    void* pvVar2;

    FUN_005dd8b0();
    pvVar2 = reinterpret_cast<void*>(static_cast<intptr_t>(DAT_00728ebc));
    while (pvVar2 != 0) {
        pvVar1 = reinterpret_cast<void*>(static_cast<intptr_t>(f32(pvVar2, 0x44)));
        FUN_005dd780(pvVar2);
        operator_delete(pvVar2);
        pvVar2 = pvVar1;
    }
    DAT_00728ebc = 0;
}

// 0x5d8810 — observed shape
void FUN_005d8810(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    uint32_t uVar1 = 0;

    in_ECX[0] = 0;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[1] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    if (in_ECX[0xe] != 0) {
        do {
            *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(in_ECX[0xc]) + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[0xe]);
    }
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
}

// 0x5d8860 — observed shape
// The reset call at 0x5d8810() has an implicit receiver; the node being
// recycled is `param_1` (its +0x44/+0x48 fields are the list links it uses).
void FUN_005d8860(int32_t param_1)
{
    void* node = nodeOf(param_1);
    int* piVar1;
    int32_t iVar2;
    int32_t iVar3;

    if (param_1 != 0) {
        piVar1 = reinterpret_cast<int*>(static_cast<intptr_t>(f32(node, 8)));
        if (piVar1 != 0) {
            uint32_t vtable = *reinterpret_cast<uint32_t*>(piVar1);
            (**(code**)(vtable + 8))(piVar1);
            f32(node, 8) = 0;
        }
        FUN_005d8810(node);
        iVar2 = f32(node, 0x44);
        iVar3 = f32(node, 0x48);
        if (iVar2 != 0) {
            f32(nodeOf(iVar2), 0x48) = iVar3;
        }
        if (iVar3 != 0) {
            f32(nodeOf(iVar3), 0x44) = iVar2;
        }
        if (DAT_00728ebc != 0) {
            f32(nodeOf(DAT_00728ebc), 0x48) = param_1;
        }
        f32(node, 0x44) = DAT_00728ebc;
        f32(node, 0x48) = 0;
        DAT_00728ebc = param_1;
    }
}
