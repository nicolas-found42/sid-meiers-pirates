// mass_0248 — Sid Meier's Pirates! (2004), PE32 i386.
// Reconstructions from Ghidra 12.2 pseudocode corpus (0x5eb580..0x5ec47a).
// NSB constant-map family: stream-driven constant lists split into per-stage
// linked lists (pixel/vertex shader constants), with a parallel name lookup
// list, stream readers, destructors and allocation helpers.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// Referenced helpers (declared from their corpus call sites).
extern void* ExceptionList;
extern void operator_delete(void* p);
extern void operator_delete__(void* p);

extern void FUN_005ea870(void);
extern uint32_t FUN_00533c78(uint32_t size);
extern int FUN_006b91f0(int param_1);
extern int FUN_006b7590(int param_1);
extern uint8_t FUN_005eabe0(int param_1, uint32_t param_2, int entry, int data);
extern uint8_t FUN_005eafa0(int param_1, uint32_t param_2, int entry, int data);
extern void FUN_005477c0(int param_1, int param_2, const char* format, ...);
extern int FUN_005eaa80(int mode, uintptr_t param_1);
extern uintptr_t FUN_005eab20(uintptr_t param_1, uintptr_t param_2, uintptr_t param_3,
                              uintptr_t param_4, uintptr_t param_5, uintptr_t param_6,
                              uintptr_t param_7, uintptr_t param_8, uintptr_t param_9,
                              uintptr_t param_10);
extern void FUN_005e0560(void* p);
extern uint8_t FUN_006b5090(uintptr_t param_1, void* param_2 = nullptr);
extern uint8_t FUN_006b5020(uint32_t param_1);
extern uint8_t FUN_005ea750(uint32_t param_1);
extern void FUN_005defc0(void);
extern void FUN_005edba0(void);
extern void FUN_005eede0(uint32_t param_1);
extern uint32_t FUN_005ece40(void);

// Referenced data.
extern void* PTR_FUN_006c9e8c;
extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006c9e90;
extern void* PTR_FUN_006c9eb4;
extern void* PTR_FUN_006c9fc4;
extern void* PTR_LAB_006c9fb8;
extern int DAT_00727444;
extern uint32_t DAT_007187cc;

// Node allocator reached through the second slot of each per-stage vtable.
typedef uint32_t* (*VtblAllocFn)(void);

// Defined below; called by the destroying destructor at 0x5ec0a0.
void FUN_5ec0c0(void* self);

// 0x5eb580 — observed shape: destroying destructor; releases the base object and
// conditionally deletes the receiver when the low flag bit is set.
void FUN_5eb580(void* self, uint8_t param_1)
{
    FUN_005ea870();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5eb620 — observed shape: pixel-shader constant lookup; requires stage 1 with a
// populated list, walks the +0x14 list and the +0x3c name list through the parser
// callback and reports failing entries.
int FUN_5eb620(void* self, int param_1, uint32_t param_2)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    void* local_c = ExceptionList;

    if (((param_1 != 0) && (*reinterpret_cast<int*>(selfBytes + 8) == 1)) &&
        (*reinterpret_cast<int*>(selfBytes + 0x1c) != 0)) {
        ExceptionList = &local_c;
        int iVar5 = static_cast<int>(FUN_00533c78(0x3c));
        int local_10;
        if (iVar5 == 0) {
            local_10 = 0;
        } else {
            local_10 = FUN_006b91f0(param_1);
        }
        if (local_10 != 0) {
            uint32_t** cursorField = reinterpret_cast<uint32_t**>(selfBytes + 0xc);
            uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(selfBytes + 0x14);
            iVar5 = 0;
            *cursorField = puVar2;
            if (puVar2 != nullptr) {
                *cursorField = reinterpret_cast<uint32_t*>(*puVar2);
                iVar5 = static_cast<int>(puVar2[2]);
            }
            while (iVar5 != 0) {
                uint8_t cVar4 = FUN_005eabe0(param_1, param_2, iVar5, local_10);
                if (cVar4 == 0) {
                    FUN_005477c0(1, 1,
                                 "* ERROR: NSBConstantMap::GetD3DSCM_Pixel\n    Failed processing of entry %s\n",
                                 *reinterpret_cast<uint32_t*>(
                                     reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar5)) + 8));
                }
                puVar2 = *cursorField;
                iVar5 = 0;
                if (puVar2 != nullptr) {
                    *cursorField = reinterpret_cast<uint32_t*>(*puVar2);
                    iVar5 = static_cast<int>(puVar2[2]);
                }
            }
            int* piVar1 = reinterpret_cast<int*>(selfBytes + 0x34);
            iVar5 = 0;
            if ((piVar1 != nullptr) && (reinterpret_cast<void*>(selfBytes + 0x38) != nullptr)) {
                int* piVar3 = *reinterpret_cast<int**>(selfBytes + 0x3c);
                *piVar1 = reinterpret_cast<int>(piVar3);
                if (piVar3 != nullptr) {
                    *piVar1 = *piVar3;
                    iVar5 = piVar3[2];
                }
                while (iVar5 != 0) {
                    uint8_t cVar4 = FUN_005eabe0(param_1, param_2, iVar5, local_10);
                    if (cVar4 == 0) {
                        FUN_005477c0(1, 1,
                                     "* ERROR: NSBConstantMap::GetD3DSCM_Pixel\n    Failed processing of entry %s\n",
                                     *reinterpret_cast<uint32_t*>(
                                         reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar5)) + 8));
                    }
                    iVar5 = 0;
                    if (piVar1 == nullptr) {
                        ExceptionList = local_c;
                        return local_10;
                    }
                    if (reinterpret_cast<void*>(selfBytes + 0x38) == nullptr) {
                        ExceptionList = local_c;
                        return local_10;
                    }
                    piVar3 = reinterpret_cast<int*>(*piVar1);
                    if (piVar3 != nullptr) {
                        *piVar1 = *piVar3;
                        iVar5 = piVar3[2];
                    }
                }
            }
            ExceptionList = local_c;
            return local_10;
        }
    }
    ExceptionList = local_c;
    return 0;
}

// 0x5eb790 — observed shape: vertex-shader constant lookup; stage 2 twin of
// 0x5eb620 using the vertex parser entry points.
int FUN_5eb790(void* self, int param_1, uint32_t param_2)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    void* local_c = ExceptionList;

    if (((param_1 != 0) && (*reinterpret_cast<int*>(selfBytes + 8) == 2)) &&
        (*reinterpret_cast<int*>(selfBytes + 0x1c) != 0)) {
        ExceptionList = &local_c;
        int iVar5 = static_cast<int>(FUN_00533c78(0x3c));
        int local_10;
        if (iVar5 == 0) {
            local_10 = 0;
        } else {
            local_10 = FUN_006b7590(param_1);
        }
        if (local_10 != 0) {
            uint32_t** cursorField = reinterpret_cast<uint32_t**>(selfBytes + 0xc);
            uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(selfBytes + 0x14);
            iVar5 = 0;
            *cursorField = puVar2;
            if (puVar2 != nullptr) {
                *cursorField = reinterpret_cast<uint32_t*>(*puVar2);
                iVar5 = static_cast<int>(puVar2[2]);
            }
            while (iVar5 != 0) {
                uint8_t cVar4 = FUN_005eafa0(param_1, param_2, iVar5, local_10);
                if (cVar4 == 0) {
                    FUN_005477c0(1, 1,
                                 "* ERROR: NSBConstantMap::GetD3DSCM_Vertex\n    Failed processing of entry %s\n",
                                 *reinterpret_cast<uint32_t*>(
                                     reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar5)) + 8));
                }
                puVar2 = *cursorField;
                iVar5 = 0;
                if (puVar2 != nullptr) {
                    *cursorField = reinterpret_cast<uint32_t*>(*puVar2);
                    iVar5 = static_cast<int>(puVar2[2]);
                }
            }
            int* piVar1 = reinterpret_cast<int*>(selfBytes + 0x34);
            iVar5 = 0;
            if ((piVar1 != nullptr) && (reinterpret_cast<void*>(selfBytes + 0x38) != nullptr)) {
                int* piVar3 = *reinterpret_cast<int**>(selfBytes + 0x3c);
                *piVar1 = reinterpret_cast<int>(piVar3);
                if (piVar3 != nullptr) {
                    *piVar1 = *piVar3;
                    iVar5 = piVar3[2];
                }
                while (iVar5 != 0) {
                    uint8_t cVar4 = FUN_005eafa0(param_1, param_2, iVar5, local_10);
                    if (cVar4 == 0) {
                        FUN_005477c0(1, 1,
                                     "* ERROR: NSBConstantMap::GetD3DSCM_Vertex\n    Failed processing of entry %s\n",
                                     *reinterpret_cast<uint32_t*>(
                                         reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar5)) + 8));
                    }
                    iVar5 = 0;
                    if (piVar1 == nullptr) {
                        ExceptionList = local_c;
                        return local_10;
                    }
                    if (reinterpret_cast<void*>(selfBytes + 0x38) == nullptr) {
                        ExceptionList = local_c;
                        return local_10;
                    }
                    piVar3 = reinterpret_cast<int*>(*piVar1);
                    if (piVar3 != nullptr) {
                        *piVar1 = *piVar3;
                        iVar5 = piVar3[2];
                    }
                }
            }
            ExceptionList = local_c;
            return local_10;
        }
    }
    ExceptionList = local_c;
    return 0;
}

// 0x5eb900 — observed shape: register a 10-field descriptor as pixel-shader
// constant (mode 1) when no entry exists yet, then hand it to the commit helper.
uint32_t FUN_5eb900(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                    uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8,
                    uint32_t param_9, uint32_t param_10)
{
    uint32_t uVar1 = param_1;
    int iVar2 = FUN_005eaa80(1, uVar1);
    if (iVar2 == 0) {
        param_1 = static_cast<uint32_t>(FUN_005eab20(uVar1, param_2, param_3, param_4, param_5,
                                                     param_6, param_7, param_8, param_9, param_10));
        if (param_1 != 0) {
            FUN_005e0560(&param_1);
            return 1;
        }
    }
    return 0;
}

// 0x5eb970 — observed shape: vertex-shader constant (mode 2) twin of 0x5eb900.
uint32_t FUN_5eb970(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                    uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8,
                    uint32_t param_9, uint32_t param_10)
{
    uint32_t uVar1 = param_1;
    int iVar2 = FUN_005eaa80(2, uVar1);
    if (iVar2 == 0) {
        param_1 = static_cast<uint32_t>(FUN_005eab20(uVar1, param_2, param_3, param_4, param_5,
                                                     param_6, param_7, param_8, param_9, param_10));
        if (param_1 != 0) {
            FUN_005e0560(&param_1);
            return 1;
        }
    }
    return 0;
}

// 0x5eb9e0 — observed shape: name lookup over the +0x48 list; a name match with a
// non-null payload aborts, otherwise the descriptor is created and committed.
uint32_t FUN_5eb9e0(void* self, uint8_t* param_1, uint32_t param_2, uint32_t param_3,
                    uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7,
                    uint32_t param_8, uint32_t param_9, uint32_t param_10)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int* piVar1 = reinterpret_cast<int*>(selfBytes + 0x48);
    if ((piVar1 != nullptr) && (reinterpret_cast<void*>(selfBytes + 0x4c) != nullptr)) {
        int iVar3 = *reinterpret_cast<int*>(selfBytes + 0x50);
        *piVar1 = iVar3;
        while (iVar3 != 0) {
            int* piVar4 = reinterpret_cast<int*>(*piVar1);
            *piVar1 = *piVar4;
            iVar3 = piVar4[2];
            if (iVar3 != 0) {
                const uint8_t* pbVar5 =
                    *reinterpret_cast<const uint8_t**>(
                        reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar3)) + 8);
                const uint8_t* pbVar7 = param_1;
                int iVar6;
                for (;;) {
                    uint8_t bVar2 = *pbVar5;
                    bool bVar8 = bVar2 < *pbVar7;
                    if (bVar2 != *pbVar7) {
                        iVar6 = static_cast<int>((1u - static_cast<uint32_t>(bVar8)) -
                                                 static_cast<uint32_t>(bVar8 != 0));
                        break;
                    }
                    if (bVar2 == 0) {
                        iVar6 = 0;
                        break;
                    }
                    bVar2 = pbVar5[1];
                    bVar8 = bVar2 < pbVar7[1];
                    if (bVar2 != pbVar7[1]) {
                        iVar6 = static_cast<int>((1u - static_cast<uint32_t>(bVar8)) -
                                                 static_cast<uint32_t>(bVar8 != 0));
                        break;
                    }
                    pbVar5 = pbVar5 + 2;
                    pbVar7 = pbVar7 + 2;
                    if (bVar2 == 0) {
                        iVar6 = 0;
                        break;
                    }
                }
                if (iVar6 == 0) {
                    if (iVar3 != 0) {
                        return 0;
                    }
                    break;
                }
            }
            iVar3 = *piVar1;
        }
    }
    param_1 = reinterpret_cast<uint8_t*>(
        FUN_005eab20(reinterpret_cast<uintptr_t>(param_1), param_2, param_3, param_4, param_5,
                     param_6, param_7, param_8, param_9, param_10));
    if (param_1 == nullptr) {
        return 0;
    }
    FUN_005e0560(&param_1);
    return 1;
}

// Shared list-rebuild block for 0x5ebab0: stream-driven node append into the
// four per-stage lists whose slot bases are 0x10, 0x24, 0x38 and 0x4c.
static uint8_t AppendConstantListSection(uint8_t* selfBytes, uint32_t stream, uint32_t base,
                                        uint32_t count)
{
    uint32_t index = 0;
    if (count != 0) {
        do {
            uint32_t* object = reinterpret_cast<uint32_t*>(FUN_00533c78(0x34));
            uint32_t* entry = nullptr;
            if (object != nullptr) {
                FUN_005defc0();
                *object = reinterpret_cast<uint32_t>(&PTR_FUN_006c9e8c);
                entry = object;
            }
            if (FUN_005ea750(stream) == 0) {
                return 0;
            }
            void* vtbl = *reinterpret_cast<void**>(selfBytes + base);
            VtblAllocFn alloc = reinterpret_cast<VtblAllocFn>(
                *reinterpret_cast<void**>(static_cast<uint8_t*>(vtbl) + 4));
            uint32_t* link = alloc();
            link[2] = reinterpret_cast<uint32_t>(entry);
            *link = 0;
            link[1] = *reinterpret_cast<uint32_t*>(selfBytes + base + 8);
            uint32_t** tailSlot = reinterpret_cast<uint32_t**>(selfBytes + base + 8);
            if (*tailSlot == nullptr) {
                *reinterpret_cast<uint32_t*>(selfBytes + base + 4) =
                    reinterpret_cast<uint32_t>(link);
            } else {
                **tailSlot = reinterpret_cast<uint32_t>(link);
            }
            *reinterpret_cast<uint32_t*>(selfBytes + base + 8) =
                reinterpret_cast<uint32_t>(link);
            index = index + 1;
            *reinterpret_cast<uint32_t*>(selfBytes + base + 0xc) += 1;
        } while (index < count);
    }
    return 1;
}

// 0x5ebab0 — observed shape: rebuild the four per-stage constant lists from the
// stream: stage 1 always, stages 2..4 only when DAT_007187cc >= 0x10004.
uint8_t FUN_5ebab0(void* self, uint32_t param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint32_t local_18 = 0;
    void* local_c = ExceptionList;
    ExceptionList = &local_c;

    if (FUN_006b5090(param_1, &local_18) == 0) {
        ExceptionList = local_c;
        return 0;
    }
    if (AppendConstantListSection(selfBytes, param_1, 0x10, local_18) == 0) {
        ExceptionList = local_c;
        return 0;
    }
    if (DAT_007187cc < 0x10004) {
        ExceptionList = local_c;
        return 1;
    }
    if (FUN_006b5090(param_1, &local_18) == 0) {
        ExceptionList = local_c;
        return 0;
    }
    if (AppendConstantListSection(selfBytes, param_1, 0x24, local_18) == 0) {
        ExceptionList = local_c;
        return 0;
    }
    if (FUN_006b5090(param_1, &local_18) == 0) {
        ExceptionList = local_c;
        return 0;
    }
    if (AppendConstantListSection(selfBytes, param_1, 0x38, local_18) == 0) {
        ExceptionList = local_c;
        return 0;
    }
    if (FUN_006b5090(param_1, &local_18) == 0) {
        ExceptionList = local_c;
        return 0;
    }
    if (AppendConstantListSection(selfBytes, param_1, 0x4c, local_18) == 0) {
        ExceptionList = local_c;
        return 0;
    }
    ExceptionList = local_c;
    return 1;
}

// 0x5ebdf0 — observed shape: default constructor; installs the two-stage vtable,
// resets the three embedded constant sub-objects and bumps the live counter.
void FUN_5ebdf0(void* self)
{
    uint32_t* selfWords = static_cast<uint32_t*>(self);
    void* local_c = ExceptionList;
    ExceptionList = &local_c;

    *selfWords = reinterpret_cast<uint32_t>(&PTR_LAB_006fd148);
    selfWords[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    *selfWords = reinterpret_cast<uint32_t>(&PTR_FUN_006c9e90);
    selfWords[2] = 0;
    selfWords[7] = 0;
    selfWords[5] = 0;
    selfWords[6] = 0;
    selfWords[4] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9eb4);
    selfWords[0xc] = 0;
    selfWords[10] = 0;
    selfWords[0xb] = 0;
    selfWords[9] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9eb4);
    selfWords[0x11] = 0;
    selfWords[0xf] = 0;
    selfWords[0x10] = 0;
    selfWords[0xe] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9eb4);
    selfWords[0x16] = 0;
    selfWords[0x14] = 0;
    selfWords[0x15] = 0;
    selfWords[0x13] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9eb4);
    FUN_005edba0();
    selfWords[8] = 0;
    FUN_005edba0();
    selfWords[0xd] = 0;
    FUN_005edba0();
    selfWords[0x12] = 0;
    FUN_005edba0();
    ExceptionList = local_c;
}

// 0x5ebfa0 — observed shape: read one embedded constant record from the stream
// field by field; aborts at the first failed read.
bool FUN_5ebfa0(void* self, uint32_t param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint32_t uVar1 = param_1;
    if (FUN_006b5090(param_1) == 0) {
        return false;
    }
    if (FUN_006b5090(uVar1, selfBytes + 4) == 0) {
        return false;
    }
    if (FUN_006b5090(uVar1, selfBytes + 8) == 0) {
        return false;
    }
    if (FUN_006b5090(uVar1, &param_1) == 0) {
        return false;
    }
    *reinterpret_cast<uint32_t*>(selfBytes + 0xc) = param_1;
    if (FUN_006b5090(uVar1, &param_1) == 0) {
        return false;
    }
    *reinterpret_cast<uint32_t*>(selfBytes + 0x10) = param_1;
    if (FUN_006b5090(uVar1, &param_1) == 0) {
        return false;
    }
    *reinterpret_cast<uint32_t*>(selfBytes + 0x14) = param_1;
    return FUN_006b5090(uVar1, selfBytes + 0x18) != 0;
}

// 0x5ec050 — observed shape: thin forwarder discarding the first argument.
void FUN_5ec050(uint32_t param_1, uint32_t param_2)
{
    (void)param_1;
    FUN_005eede0(param_2);
}

// 0x5ec070 — observed shape: installs the terminal vtable; no other state change.
void FUN_5ec070(void* self)
{
    *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(&PTR_LAB_006c9fb8);
}

// 0x5ec0a0 — observed shape: destroying destructor over the base teardown.
void FUN_5ec0a0(void* self, uint8_t param_1)
{
    FUN_5ec0c0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5ec0c0 — observed shape: base destructor; runs the member teardown then
// degrades the vtable to the terminal slot.
void FUN_5ec0c0(void* self)
{
    uint32_t* selfWords = static_cast<uint32_t*>(self);
    void* local_c = ExceptionList;
    ExceptionList = &local_c;

    *selfWords = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fc4);
    FUN_005edba0();
    *selfWords = reinterpret_cast<uint32_t>(&PTR_LAB_006c9fb8);
    ExceptionList = local_c;
}

// 0x5ec110 — observed shape: reset the +0x8 cursor from the +0x10 list head and
// return the first payload.
uint32_t FUN_5ec110(void* self)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(selfBytes + 0x10);
    uint32_t uVar2 = 0;
    *reinterpret_cast<uint32_t**>(selfBytes + 8) = puVar1;
    if (puVar1 != nullptr) {
        *reinterpret_cast<uint32_t**>(selfBytes + 8) = reinterpret_cast<uint32_t*>(*puVar1);
        uVar2 = puVar1[2];
    }
    return uVar2;
}

// 0x5ec130 — observed shape: advance the +0x8 cursor and return its payload.
uint32_t FUN_5ec130(void* self)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(selfBytes + 8);
    uint32_t uVar2 = 0;
    if (puVar1 != nullptr) {
        *reinterpret_cast<uint32_t**>(selfBytes + 8) = reinterpret_cast<uint32_t*>(*puVar1);
        uVar2 = puVar1[2];
    }
    return uVar2;
}

// 0x5ec150 — observed shape: histogram over the +0x10 list keyed by each node's
// first word; reports distinct key count and the highest bucket count.
void FUN_5ec150(void* self, int* param_1, uint32_t* param_2)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    *param_1 = 0;
    *param_2 = 0;
    uint32_t local_108[65];
    uint32_t* puVar6 = local_108;
    for (int iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
    }
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(selfBytes + 0x10);
    int* piVar4 = nullptr;
    *reinterpret_cast<uint32_t**>(selfBytes + 8) = puVar1;
    if (puVar1 != nullptr) {
        *reinterpret_cast<uint32_t**>(selfBytes + 8) = reinterpret_cast<uint32_t*>(*puVar1);
        piVar4 = reinterpret_cast<int*>(puVar1[2]);
    }
    while (piVar4 != nullptr) {
        int iVar3 = *piVar4;
        uint32_t uVar2 = local_108[iVar3];
        if (uVar2 == 0) {
            *param_1 = *param_1 + 1;
        }
        local_108[iVar3] = uVar2 + 1;
        puVar1 = *reinterpret_cast<uint32_t**>(selfBytes + 8);
        piVar4 = nullptr;
        if (puVar1 != nullptr) {
            *reinterpret_cast<uint32_t**>(selfBytes + 8) = reinterpret_cast<uint32_t*>(*puVar1);
            piVar4 = reinterpret_cast<int*>(puVar1[2]);
        }
    }
    uint32_t uVar2 = *param_2;
    uint32_t uVar5 = 0;
    do {
        if (uVar2 < local_108[uVar5]) {
            uVar2 = local_108[uVar5];
        }
        if (uVar2 < local_108[uVar5 + 1]) {
            uVar2 = local_108[uVar5 + 1];
        }
        if (uVar2 < local_108[uVar5 + 2]) {
            uVar2 = local_108[uVar5 + 2];
        }
        if (uVar2 < local_108[uVar5 + 3]) {
            uVar2 = local_108[uVar5 + 3];
        }
        uVar5 = uVar5 + 4;
    } while (uVar5 < 0x40);
    *param_2 = uVar2;
}

// 0x5ec210 — observed shape: full teardown; frees each payload of the +0x10 list,
// then the list owner and finally runs the base destructor and terminal vtable.
void FUN_5ec210(void* self)
{
    uint32_t* selfWords = static_cast<uint32_t*>(self);
    void* local_c = ExceptionList;
    ExceptionList = &local_c;

    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(selfWords[4]);
    while (puVar2 != nullptr) {
        uint32_t* puVar1 = puVar2 + 2;
        puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
        if (*puVar1 != 0) {
            operator_delete(reinterpret_cast<void*>(*puVar1));
        }
    }
    FUN_005edba0();
    operator_delete__(reinterpret_cast<void*>(*selfWords));
    selfWords[3] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fc4);
    FUN_005edba0();
    selfWords[3] = reinterpret_cast<uint32_t>(&PTR_LAB_006c9fb8);
    ExceptionList = local_c;
}

// 0x5ec2a0 — observed shape: stream-deserialise the flag byte and the list of
// constants, appending each parsed record to the +0x10 list.
uint8_t FUN_5ec2a0(void* self, uint32_t param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    if (FUN_006b5020(param_1) == 0) {
        return 0;
    }
    uint32_t local_c = (*reinterpret_cast<uint8_t*>(selfBytes + 4) != 0) ? 1u : 0u;
    if (FUN_006b5090(param_1, &local_c) == 0) {
        return 0;
    }
    *reinterpret_cast<uint8_t*>(selfBytes + 4) = static_cast<uint8_t>(local_c != 0);
    uint32_t local_4 = 0;
    if (FUN_006b5090(param_1, &local_4) == 0) {
        return 0;
    }
    uint32_t local_8 = 0;
    if (local_4 == 0) {
        return 1;
    }
    do {
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x1c));
        if (puVar2 == nullptr) {
            puVar2 = nullptr;
        } else {
            puVar2[0] = 0;
            puVar2[1] = 0;
            puVar2[2] = 0xffffffff;
            puVar2[3] = 0x7fffffff;
            puVar2[4] = 0;
            puVar2[5] = 0;
            puVar2[6] = 0;
        }
        if (FUN_005ebfa0(self, param_1) == 0) {
            return 0;
        }
        void* vtbl = *reinterpret_cast<void**>(selfBytes + 0xc);
        VtblAllocFn alloc = reinterpret_cast<VtblAllocFn>(
            *reinterpret_cast<void**>(static_cast<uint8_t*>(vtbl) + 4));
        uint32_t* puVar3 = alloc();
        puVar3[2] = reinterpret_cast<uint32_t>(puVar2);
        *puVar3 = 0;
        puVar3[1] = *reinterpret_cast<uint32_t*>(selfBytes + 0x14);
        uint32_t** tailSlot = reinterpret_cast<uint32_t**>(selfBytes + 0x14);
        if (*tailSlot == nullptr) {
            *reinterpret_cast<uint32_t*>(selfBytes + 0x10) = reinterpret_cast<uint32_t>(puVar3);
        } else {
            **tailSlot = reinterpret_cast<uint32_t>(puVar3);
        }
        *reinterpret_cast<uint32_t*>(selfBytes + 0x14) = reinterpret_cast<uint32_t>(puVar3);
        local_8 = local_8 + 1;
        *reinterpret_cast<uint32_t*>(selfBytes + 0x18) += 1;
    } while (local_8 < local_4);
    return 1;
}

// 0x5ec3c0 — observed shape: sub-object constructor; clears the fields up to
// +0x18, installs the base vtable at +0xc and runs the member init helper.
void FUN_5ec3c0(void* self)
{
    uint32_t* selfWords = static_cast<uint32_t*>(self);
    void* local_c = ExceptionList;
    ExceptionList = &local_c;

    *selfWords = 0;
    *(reinterpret_cast<uint8_t*>(selfWords) + 4) = 0;
    selfWords[6] = 0;
    selfWords[4] = 0;
    selfWords[5] = 0;
    selfWords[3] = reinterpret_cast<uint32_t>(&PTR_FUN_006c9fc4);
    FUN_005edba0();
    ExceptionList = local_c;
}

// 0x5ec420 — observed shape: lazily create the +0x10 helper object and return it.
uint32_t FUN_5ec420(void* self)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    void* local_c = ExceptionList;

    if (*reinterpret_cast<uint32_t*>(selfBytes + 0x10) == 0) {
        ExceptionList = &local_c;
        int iVar1 = static_cast<int>(FUN_00533c78(0x24));
        uint32_t uVar2;
        if (iVar1 == 0) {
            uVar2 = 0;
        } else {
            uVar2 = FUN_005ece40();
        }
        *reinterpret_cast<uint32_t*>(selfBytes + 0x10) = uVar2;
        ExceptionList = local_c;
    }
    return *reinterpret_cast<uint32_t*>(selfBytes + 0x10);
}
