#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005e0f80(void);
extern void FUN_005e0e70(void);
extern void FUN_005e1490(void);
extern void thunk_FUN_005e0f80(void);
extern void operator_delete(void*);
extern int DAT_0072909c;
extern int DAT_007290a4;
extern void* DAT_007290a8;
extern void* PTR_FUN_006c960c;

// 0x5e1090 — observed shape: vectoring-deleting-destructor stub; calls FUN_005e0f80 then conditionally deletes receiver (in_ECX) when low bit set.
void FUN_005e1090(void* self, uint8_t param_1)
{
    FUN_005e0f80();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e10b0 — observed shape: singleton swap with vtable release/addref; if param differs from DAT_007290a8, releases old (vtable+0x8) and addrefs new (vtable+0x4); if DAT_0072909c != 0, tail-calls FUN_005e0e70.
void FUN_005e10b0(int* param_1)
{
    if (param_1 != static_cast<int*>(DAT_007290a8)) {
        if (DAT_007290a8 != nullptr) {
            using Func = void(*)(void*);
            Func* vtable = *reinterpret_cast<Func**>(DAT_007290a8);
            vtable[1](DAT_007290a8);
        }
        DAT_007290a8 = param_1;
        if (param_1 != nullptr) {
            using Func = void(*)(void*);
            Func* vtable = *reinterpret_cast<Func**>(param_1);
            vtable[0](param_1);
        }
        if (DAT_0072909c != 0) {
            FUN_005e0e70();
            return;
        }
    }
}

// 0x5e10f0 — observed shape: DAT_007290a4 change guard; nonzero param delegates to FUN_005e10b0(*(param+0x60)) and stores; zero param releases DAT_007290a8 (vtable+0x8) and tail-calls FUN_005e0e70 when DAT_0072909c != 0.
void FUN_005e10f0(int param_1)
{
    if (DAT_007290a4 != param_1) {
        if (param_1 != 0) {
            FUN_005e10b0(reinterpret_cast<int*>(*(int*)(param_1 + 0x60)));
            DAT_007290a4 = param_1;
            return;
        }
        if (DAT_007290a8 != nullptr) {
            using Func = void(*)(void*);
            Func* vtable = *reinterpret_cast<Func**>(DAT_007290a8);
            vtable[1](DAT_007290a8);
            DAT_007290a8 = nullptr;
            if (DAT_0072909c != 0) {
                FUN_005e0e70();
            }
        }
        DAT_007290a4 = param_1;
    }
}

// 0x5e1150 — observed shape: destructor; installs vptr PTR_FUN_006c960c, calls FUN_005e0e70, then FUN_005e1490 if field+4 nonzero, then indirect call through field+4 with arg 1, conditional operator_delete on low bit.
void FUN_005e1150(void* self, uint8_t param_1)
{
    *(void**)self = PTR_FUN_006c960c;
    FUN_005e0e70();
    uint32_t* fields = static_cast<uint32_t*>(self);
    if (fields[1] != 0) {
        FUN_005e1490();
    }
    if (fields[1] != 0) {
        using Func = void(*)(int);
        Func fn = *(Func*)fields[1];
        fn(1);
    }
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e1200 — observed shape: vectoring-deleting-destructor stub; calls thunk_FUN_005e0f80 then conditionally deletes receiver when low bit set.
void FUN_005e1200(void* self, uint8_t param_1)
{
    thunk_FUN_005e0f80();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
extern void* FUN_00533c78(uint32_t);
extern void* thunk_FUN_00533c78(uint32_t);
extern void FUN_005e12f0(void);
extern void FUN_005e1230(void*);
extern void FUN_005e0b40(void*, void*);
extern void FUN_005e1ca0(void);
extern void FUN_005c9b90(void);
extern void* PTR_FUN_006c9554;
extern void* PTR_FUN_006c961c;
extern int DAT_007290a4;
extern int _DAT_00000004;
extern char cRam00000050;
extern int iRam0000004c;

// 0x5e1230 — observed shape: constructor-helper; installs vptr PTR_FUN_006c960c, allocates 0x14 object via FUN_00533c78, zeroes 0xec buffer via thunk_FUN_00533c78, sets vptrs PTR_FUN_006c9554 then PTR_FUN_006c961c, stores pointer at self+4.
void FUN_005e1230(void* self)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    fields[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c960c);
    uint32_t* puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x14));
    if (puVar1 == nullptr) {
        fields[1] = 0;
        return;
    }
    uint32_t* puVar2 = static_cast<uint32_t*>(thunk_FUN_00533c78(0xec));
    puVar1[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c9554);
    puVar1[1] = 0x3b;
    puVar1[3] = 0;
    puVar1[2] = reinterpret_cast<uint32_t>(puVar2);
    uint32_t uVar3 = puVar1[1] & 0x3fffffff;
    while (uVar3 != 0) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
        uVar3 = uVar3 - 1;
    }
    puVar1[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c961c);
    *(uint8_t*)(reinterpret_cast<uint8_t*>(puVar1) + 0x10) = 0;
    fields[1] = reinterpret_cast<uint32_t>(puVar1);
}

// 0x5e12f0 — observed shape: lazy singleton init; if DAT_0072909c == 0, allocates 0x10 via FUN_00533c78 and constructs via FUN_005e1230, else no-op.
void FUN_005e12f0(void)
{
    if (DAT_0072909c == 0) {
        int iVar1 = reinterpret_cast<int>(FUN_00533c78(0x10));
        if (iVar1 != 0) {
            DAT_0072909c = reinterpret_cast<int>(FUN_005e1230(reinterpret_cast<void*>(iVar1)));
            return;
        }
        DAT_0072909c = 0;
    }
}

// 0x5e1360 — observed shape: lookup with fallback; ensures singleton via FUN_005e12f0, nonempty-string loop, vtable call on DAT_0072909c, returns nonzero result subject to +0x50/+0x4c checks or DAT_007290a4==0, else FUN_005e0b40 fallback with _DAT_00000004=2 and FUN_005e1ca0 path.
int FUN_005e1360(const char* param_1)
{
    if (DAT_0072909c == 0) {
        FUN_005e12f0();
    }
    if (param_1 != nullptr) {
        int iVar2 = 1;
        bool bVar5 = true;
        const char* pcVar3 = param_1;
        const char* pcVar4 = "";
        while (iVar2 != 0) {
            iVar2 = iVar2 - 1;
            bVar5 = (*pcVar3 == *pcVar4);
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
            if (!bVar5) break;
        }
        if (!bVar5) {
            using Func = int(*)(const char*);
            Func fn = *(Func*)DAT_0072909c;
            int res = fn(param_1);
            if (res != 0) {
                if ((*(char*)(res + 0x50) != '\0') && (*(int*)(res + 0x4c) != 0)) {
                    return res;
                }
                if (DAT_007290a4 == 0) {
                    return res;
                }
                uint8_t tmp = 0;
                FUN_005e0b40(const_cast<char*>(param_1), &tmp);
                return res;
            }
            uint8_t tmp = 0;
            char cVar1 = static_cast<char>(reinterpret_cast<int>(FUN_005e0b40(const_cast<char*>(param_1), &tmp)));
            if (cVar1 != '\0') {
                _DAT_00000004 = 2;
                if ((cRam00000050 == '\0') || (iRam0000004c == 0)) {
                    FUN_005e1ca0();
                }
                using Func = void(*)(int);
                Func fn = *(Func*)(DAT_0072909c + 4);
                fn(0);
                return 0;
            }
        }
    }
    return 0;
}

// 0x5e1430 — observed shape: trivial tail-call; forwards to FUN_005c9b90.
void FUN_005e1430(void)
{
    FUN_005c9b90();
}

// 0x5e1450 — observed shape: conditional virtual dispatch; if self+0x4c != 0 and self+0x50 != 0, calls vtable offset 0x11c on the self+0x4c object.
void FUN_005e1450(void* self)
{
    int base = reinterpret_cast<int>(self);
    if ((*(int*)(base + 0x4c) != 0) && (*(char*)(base + 0x50) != '\0')) {
        using Func = void(*)(void*);
        void* obj = *(void**)(base + 0x4c);
        Func fn = *(Func*)((char*)obj + 0x11c);
        fn(obj);
    }
}
extern void FUN_005edba0(void);
extern void* PTR_LAB_006c9638;
extern void* PTR_FUN_006c9660;
extern void* PTR_FUN_006c9644;

// 0x5e1470 — observed shape: conditional virtual dispatch; identical guard to FUN_005e1450 but calls vtable offset 0x120 on the self+0x4c object.
void FUN_005e1470(void* self)
{
    int base = reinterpret_cast<int>(self);
    if ((*(int*)(base + 0x4c) != 0) && (*(char*)(base + 0x50) != '\0')) {
        using Func = void(*)(void*);
        void* obj = *(void**)(base + 0x4c);
        Func fn = *(Func*)((char*)obj + 0x120);
        fn(obj);
    }
}

// 0x5e1490 — observed shape: vector clear; iterates in_ECX[1] slots at in_ECX[2], while slot head nonzero, advance head via linked *head and call self vtable +0x10 and +0x18 on each node, then zero in_ECX[3].
void FUN_005e1490(void* self)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    uint32_t uVar3 = 0;
    if (fields[1] != 0) {
        do {
            int iVar1 = *(int*)(fields[2] + uVar3 * 4);
            while (iVar1 != 0) {
                uint32_t* puVar2 = *(uint32_t**)(fields[2] + uVar3 * 4);
                *(uint32_t*)(fields[2] + uVar3 * 4) = *puVar2;
                using Func = void(*)(uint32_t*);
                Func fn10 = *(Func*)((char*)*(void**)self + 0x10);
                fn10(puVar2);
                Func fn18 = *(Func*)((char*)*(void**)self + 0x18);
                fn18(puVar2);
                iVar1 = *(int*)(fields[2] + uVar3 * 4);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < fields[1]);
    }
    fields[3] = 0;
}

// 0x5e14f0 — observed shape: vptr install; writes PTR_LAB_006c9638 to *self.
void FUN_005e14f0(void* self)
{
    *(void**)self = PTR_LAB_006c9638;
}

// 0x5e1500 — observed shape: scoped vptr swap; installs PTR_FUN_006c9660, calls FUN_005edba0, restores PTR_LAB_006c9638.
void FUN_005e1500(void* self)
{
    *(void**)self = PTR_FUN_006c9660;
    FUN_005edba0();
    *(void**)self = PTR_LAB_006c9638;
}

// 0x5e1550 — observed shape: destructor-tail; installs PTR_FUN_006c9644, calls FUN_005e1490, then operator_delete on field+8 (in_ECX[2]).
void FUN_005e1550(void* self)
{
    *(void**)self = PTR_FUN_006c9644;
    FUN_005e1490(self);
    uint32_t* fields = static_cast<uint32_t*>(self);
    operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[2])));
}
extern void FUN_005e1580(void);
extern void FUN_005e15f0(void);
extern void* PTR_FUN_006c966c;
extern void* PTR_FUN_006c9688;

// 0x5e1580 — observed shape: chained cleanup; installs PTR_FUN_006c966c, calls FUN_005e1490, installs PTR_FUN_006c9644, calls FUN_005e1490 again, then operator_delete on field+8.
void FUN_005e1580(void* self)
{
    *(void**)self = PTR_FUN_006c966c;
    FUN_005e1490(self);
    *(void**)self = PTR_FUN_006c9644;
    FUN_005e1490(self);
    uint32_t* fields = static_cast<uint32_t*>(self);
    operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[2])));
}

// 0x5e15f0 — observed shape: deep bucket cleanup; installs PTR_FUN_006c9688, if self+0x10 nonzero iterates slots at self+8 deleting *(node+1) payloads, then PTR_FUN_006c966c/FUN_005e1490/PTR_FUN_006c9644/FUN_005e1490/operator_delete chain.
void FUN_005e15f0(void* self)
{
    *(void**)self = PTR_FUN_006c9688;
    uint32_t* fields = static_cast<uint32_t*>(self);
    if ((*(uint8_t*)reinterpret_cast<uint8_t*>(self) + 0x10) != 0 && fields[1] != 0) {
        uint32_t uVar3 = 0;
        do {
            uint32_t* puVar2 = *(uint32_t**)(fields[2] + uVar3 * 4);
            while (puVar2 != nullptr) {
                uint32_t* puVar1 = puVar2 + 1;
                puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
                operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(*puVar1)));
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < fields[1]);
    }
    *(void**)self = PTR_FUN_006c966c;
    FUN_005e1490(self);
    *(void**)self = PTR_FUN_006c9644;
    FUN_005e1490(self);
    operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[2])));
}

// 0x5e16c0 — observed shape: vectoring-deleting-destructor; installs PTR_FUN_006c9644, calls FUN_005e1490, operator_delete on field+8, conditional operator_delete self on low bit.
void FUN_005e16c0(void* self, uint8_t param_1)
{
    *(void**)self = PTR_FUN_006c9644;
    FUN_005e1490(self);
    uint32_t* fields = static_cast<uint32_t*>(self);
    operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(fields[2])));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e1700 — observed shape: vectoring-deleting-destructor stub; calls FUN_005e1580 then conditionally deletes receiver when low bit set.
void FUN_005e1700(void* self, uint8_t param_1)
{
    FUN_005e1580();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e1720 — observed shape: vectoring-deleting-destructor stub; calls FUN_005e15f0 then conditionally deletes receiver when low bit set.
void FUN_005e1720(void* self, uint8_t param_1)
{
    FUN_005e15f0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
