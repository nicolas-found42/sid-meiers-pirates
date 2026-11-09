// Reconstruction batch mass_0064 — Sid Meier's Pirates! (2004), PE32 i386
// Ghidra 12.2 pseudocode corpus translations (analysis/pseudocode/functions/).
// Register receivers (in_ECX / in_ESI / in_EDI / in_EBX / in_EAX) rendered as
// explicit pointer parameters; no `this` in free functions. Unverified candidate:
// no compiler/test run. Field offsets are kept exactly as observed.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- globals referenced by the assigned listings ----
extern std::int32_t DAT_0085a164;
extern std::int32_t DAT_008610e8[];   // then walked as 8-dword stride records
extern std::int16_t DAT_007d2168[];
extern std::uint8_t DAT_0076ef10[];
extern std::int32_t DAT_0072cd78;
extern std::int32_t DAT_0085a7b0, DAT_0085a7d0;
extern std::int32_t DAT_00814304, DAT_00814308;
extern std::uint8_t DAT_00727560[];
extern std::uint8_t PTR_FUN_0070fd0c[], PTR_FUN_0070fd48[], PTR_FUN_0070fd28[];
extern std::uint8_t PTR_FUN_0070fd64[], PTR_FUN_0070fe10[], PTR_FUN_0070fce8[];
extern std::uint8_t PTR_LAB_0070fe14[];

// ---- helpers ----
extern void FUN_004e8500(void);
extern void FUN_004e8ea0(std::int32_t self);
extern void FUN_004e9740(void);
extern void FUN_004ec270(void);
extern void FUN_004e7950(std::int32_t self, std::int32_t a, std::int32_t b);
extern void* FUN_00533c78(std::uint32_t size);
extern void* thunk_FUN_00533c78(std::uint32_t size);
extern void* FUN_00538680(void);
extern void FUN_004e6420(void* self);
extern void FUN_004b0650(void);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);

// Virtual entries are dispatched through the objects' vtable dwords with
// per-call signature casts at each observed offset (+4 = index 1, etc.).

// 0x004ed490 — observed shape
// Two object-placement passes: an 8-dword stride coordinate table at
// DAT_008610e8 fills (x*1000, y*1000, 5.0, 500.0) quads into a singly linked
// list, then the byte map at DAT_0076ef10 with per-cell heights at
// DAT_007d2168 emits (col, row, height, 500.0) quads for cells equal to 0x12.
void FUN_004ed490(std::int32_t param_1, char param_2) {
    std::int16_t sVar1;
    std::int32_t iVar2;
    float* pfVar3;
    std::uint32_t* puVar4;
    std::uint8_t* pcVar5;
    std::int32_t* piVar6;
    std::int16_t* psVar7;
    std::int32_t iVar8;
    std::int32_t local_20;
    std::int32_t local_1c;
    void** vt;

    if (-1 < DAT_0085a164) {
        if (param_2 != '\0') {
            FUN_004e8ea0(param_1);
        }
        iVar8 = 0;
        if (0 < *(std::int32_t*)(param_1 + 0x58)) {
            do {
                FUN_004e9740();
                iVar8 = iVar8 + 1;
            } while (iVar8 < *(std::int32_t*)(param_1 + 0x58));
        }
    }
    FUN_004e8500();
    piVar6 = DAT_008610e8;
    do {
        iVar8 = piVar6[1];
        iVar2 = *piVar6;
        pfVar3 = (float*)FUN_00533c78(0x10);
        *pfVar3 = 0.0f;
        pfVar3[1] = 0.0f;
        pfVar3[2] = 0.0f;
        pfVar3[3] = 0.0f;
        *pfVar3 = (float)(iVar2 * 1000);
        pfVar3[1] = (float)(iVar8 * 1000);
        pfVar3[2] = 5.0f;
        pfVar3[3] = 500.0f;
        vt = *(void***)(param_1 + 0xac);
        puVar4 = (std::uint32_t*)reinterpret_cast<void* (*)(void)>(vt[1])();
        puVar4[2] = (std::uint32_t)(std::uintptr_t)pfVar3;
        *puVar4 = 0;
        puVar4[1] = *(std::uint32_t*)(param_1 + 0xb4);
        if (*(std::uint32_t**)(param_1 + 0xb4) == (std::uint32_t*)0x0) {
            *(std::uint32_t**)(param_1 + 0xb0) = puVar4;
        } else {
            **(std::uint32_t**)(param_1 + 0xb4) = (std::uint32_t)(std::uintptr_t)puVar4;
        }
        piVar6 = piVar6 + 8;
        *(std::uint32_t**)(param_1 + 0xb4) = puVar4;
        *(std::int32_t*)(param_1 + 0xb8) = *(std::int32_t*)(param_1 + 0xb8) + 1;
    } while ((std::intptr_t)piVar6 < 0x861b68);

    local_1c = 0;
    psVar7 = DAT_007d2168;
    pcVar5 = DAT_0076ef10;
    do {
        local_20 = 0;
        do {
            iVar8 = DAT_0072cd78;
            if (*pcVar5 == '\x12') {
                sVar1 = *psVar7;
                pfVar3 = (float*)FUN_00533c78(0x10);
                *pfVar3 = 0.0f;
                pfVar3[1] = 0.0f;
                pfVar3[2] = 0.0f;
                pfVar3[3] = 0.0f;
                *pfVar3 = (float)local_1c;
                pfVar3[1] = (float)local_20;
                pfVar3[3] = 500.0f;
                pfVar3[2] = (float)(std::int32_t)sVar1;
                vt = *(void***)(iVar8 + 0xac);
                puVar4 = (std::uint32_t*)reinterpret_cast<void* (*)(void)>(vt[1])();
                puVar4[2] = (std::uint32_t)(std::uintptr_t)pfVar3;
                *puVar4 = 0;
                puVar4[1] = *(std::uint32_t*)(iVar8 + 0xb4);
                if (*(std::uint32_t**)(iVar8 + 0xb4) == (std::uint32_t*)0x0) {
                    *(std::uint32_t**)(iVar8 + 0xb0) = puVar4;
                } else {
                    **(std::uint32_t**)(iVar8 + 0xb4) = (std::uint32_t)(std::uintptr_t)puVar4;
                }
                *(std::uint32_t**)(iVar8 + 0xb4) = puVar4;
                *(std::int32_t*)(iVar8 + 0xb8) = *(std::int32_t*)(iVar8 + 0xb8) + 1;
            }
            psVar7 = psVar7 + 1;
            local_20 = local_20 + 1000;
            pcVar5 = pcVar5 + 1;
        } while (local_20 < 0x47888);
        local_1c = local_1c + 1000;
    } while ((std::intptr_t)pcVar5 < 0x78ffd6);

    iVar8 = 0;
    if (0 < *(std::int32_t*)(param_1 + 0x58)) {
        do {
            FUN_004ec270();
            iVar8 = iVar8 + 1;
        } while (iVar8 < *(std::int32_t*)(param_1 + 0x58));
    }
    *(std::uint32_t*)(param_1 + 0x5c) = 10;
    *(std::uint8_t*)(param_1 + 0x80) = 1;
    if (param_2 == '\0') {
        FUN_004e7950(param_1, DAT_0085a7b0, DAT_0085a7d0);
        return;
    }
    FUN_004e7950(param_1, DAT_00814304 / 1000, DAT_00814308 / 1000);
    return;
}

// 0x004ed7b0 — observed shape
// Hash-map insert-or-update: self = in_ESI (int* container: [0]=vtable,
// [1]=count, [2]=bucket array, [3]=size), index = in_EDI (bucket index).
// vtable[1]=hash(param), vtable[2]=equal, vtable[3]=assign(dst,a,b),
// vtable[4]=free, vtable[5]=alloc, vtable[6] unused here.
void FUN_004ed7b0(std::uint32_t* param_1, std::int32_t* self, std::int32_t index) {
    std::int32_t* piVar1;
    char cVar2;
    std::uint32_t* puVar3;
    std::uint32_t* puVar4;
    void** vt;

    vt = *(void***)self;
    puVar3 = (std::uint32_t*)reinterpret_cast<std::uint32_t (*)(void*)>(vt[1])(param_1);
    puVar4 = *(std::uint32_t**)(self[2] + (std::int32_t)puVar3 * 4);
    do {
        if (puVar4 == (std::uint32_t*)0x0) {
            puVar4 = (std::uint32_t*)reinterpret_cast<void* (*)(void)>(vt[5])();
            if (param_1 != (std::uint32_t*)0x0) {
                param_1[1] = param_1[1] + 1;
            }
            reinterpret_cast<void (*)(void*, void*, void*)>(vt[3])(puVar4, param_1, param_1);
            *puVar4 = *(std::uint32_t*)(self[2] + index * 4);
            *(std::uint32_t**)(self[2] + index * 4) = puVar4;
            self[3] = self[3] + 1;
            puVar3 = param_1;
        LAB_004ed81f:
            if (puVar3 != (std::uint32_t*)0x0) {
                piVar1 = (std::int32_t*)(puVar3 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar3)(1);
                }
            }
            return;
        }
        cVar2 = reinterpret_cast<char (*)(void*, void*)>(vt[2])(
            param_1, (void*)(std::intptr_t)*(std::uint8_t*)((std::uint8_t*)puVar4 + 4));
        if (cVar2 != '\0') {
            reinterpret_cast<void (*)(void*)>(vt[4])(puVar4);
            if (puVar3 != (std::uint32_t*)0x0) {
                puVar3[1] = puVar3[1] + 1;
            }
            reinterpret_cast<void (*)(void*, void*, void*)>(vt[3])(puVar4, param_1, puVar3);
            goto LAB_004ed81f;
        }
        puVar4 = (std::uint32_t*)*puVar4;
    } while (true);
}

// 0x004ed860 — observed shape
// Advances a bucket-iterator `param_1` (int** holding the current node) to the
// next populated bucket, publishing the node's stored key byte via `out`
// (in_ECX) and refreshing the retained node in `slot` (in_EDI, int**).
// table = in_EBX: [0]=vtable, [1]=bucket count, [2]=bucket array.
void FUN_004ed860(std::int32_t** param_1, std::uint8_t* out, std::int32_t* table,
                  std::int32_t** slot) {
    std::int32_t* piVar1;
    std::uint32_t* puVar2;
    std::int32_t iVar3;
    std::uint32_t uVar4;
    std::int32_t* piVar5;

    piVar5 = *param_1;
    *out = (std::uint8_t)piVar5[1];
    puVar2 = (std::uint32_t*)*slot;
    if (puVar2 != (std::uint32_t*)piVar5[2]) {
        if (puVar2 != (std::uint32_t*)0x0) {
            piVar1 = (std::int32_t*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar2)(1);
            }
        }
        iVar3 = piVar5[2];
        *slot = (std::int32_t*)iVar3;
        if (iVar3 != 0) {
            *(std::int32_t*)(iVar3 + 4) = *(std::int32_t*)(iVar3 + 4) + 1;
        }
    }
    if (*piVar5 != 0) {
        *param_1 = (std::int32_t*)*piVar5;
        return;
    }
    iVar3 = (std::int32_t)reinterpret_cast<std::uint32_t (*)(void*)>(
        (*(void***)table)[1])((void*)(std::intptr_t)(char)piVar5[1]);
    uVar4 = iVar3 + 1;
    if (uVar4 < (std::uint32_t)table[1]) {
        piVar5 = (std::int32_t*)(table[2] + (std::int32_t)uVar4 * 4);
        do {
            if (*piVar5 != 0) {
                *param_1 = (std::int32_t*)*piVar5;
                return;
            }
            uVar4 = uVar4 + 1;
            piVar5 = piVar5 + 1;
        } while (uVar4 < (std::uint32_t)table[1]);
    }
    *param_1 = 0;
    return;
}

// 0x004ed8f0 — observed shape
// Hash-map erase by key. self = in_ESI (int* container, same layout as
// 0x4ed7b0). Returns 0 (low byte clear) when absent; on removal returns
// ((newCount - 1) & 0xffffff00) | 1 as the decompiler rendered the eax join.
std::uint32_t FUN_004ed8f0(std::uint32_t param_1, std::int32_t* self) {
    std::int32_t iVar1;
    std::uint32_t* puVar2;
    std::uint32_t uVar3;
    std::uint32_t uVar4;
    std::uint32_t* puVar5;
    std::uint32_t* puVar6;
    void** vt;

    vt = *(void***)self;
    uVar3 = reinterpret_cast<std::uint32_t (*)(void*)>(vt[1])((void*)(std::uintptr_t)param_1);
    puVar5 = *(std::uint32_t**)(self[2] + uVar3 * 4);
    uVar4 = uVar3;
    if (puVar5 != (std::uint32_t*)0x0) {
        uVar4 = (std::uint32_t)reinterpret_cast<char (*)(void*, void*)>(vt[2])(
            (void*)(std::uintptr_t)param_1, (void*)(std::uintptr_t)puVar5[1]);
        if ((char)uVar4 != '\0') {
            *(std::uint32_t*)(self[2] + uVar3 * 4) = *puVar5;
            reinterpret_cast<void (*)(void*)>(vt[4])(puVar5);
            reinterpret_cast<void (*)(void*)>(vt[6])(puVar5);
            iVar1 = self[3];
            self[3] = iVar1 + -1;
            return ((std::uint32_t)(iVar1 - 1) & 0xffffff00u) | 1u;
        }
        if ((std::uint32_t*)*puVar5 != (std::uint32_t*)0x0) {
            puVar6 = (std::uint32_t*)*puVar5;
            do {
                uVar4 = (std::uint32_t)reinterpret_cast<char (*)(void*, void*)>(vt[2])(
                    (void*)(std::uintptr_t)param_1, (void*)(std::uintptr_t)puVar6[1]);
                if ((char)uVar4 != '\0') {
                    *puVar5 = *puVar6;
                    reinterpret_cast<void (*)(void*)>(vt[4])(puVar6);
                    reinterpret_cast<void (*)(void*)>(vt[6])(puVar6);
                    iVar1 = self[3];
                    self[3] = iVar1 + -1;
                    return ((std::uint32_t)(iVar1 - 1) & 0xffffff00u) | 1u;
                }
                puVar2 = (std::uint32_t*)*puVar6;
                puVar5 = puVar6;
                puVar6 = puVar2;
            } while (puVar2 != (std::uint32_t*)0x0);
        }
    }
    return uVar4 & 0xffffff00u;
}

// 0x004ed9a0 — observed shape
// Resizes a sparse float-vector's backing store. self = in_ESI (int*:
// [1]=data, [2]=capacity/allocated size, [3]=used, [4]=nonzero count),
// newSize = in_EDI. Dropped slots below newSize are cleared and uncounted.
void FUN_004ed9a0(std::uint32_t* self, std::uint32_t newSize) {
    void* pvVar1;
    std::uint32_t uVar2;
    std::uint32_t uVar3;

    if (newSize != self[2]) {
        if (newSize < self[3]) {
            uVar3 = newSize;
            do {
                if (*(float*)(self[1] + uVar3 * 4) != 0.0f) {
                    *(std::uint32_t*)(self[1] + uVar3 * 4) = 0;
                    self[4] = self[4] - 1;
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < self[3]);
            self[3] = newSize;
        }
        pvVar1 = (void*)self[1];
        self[2] = newSize;
        if (newSize == 0) {
            self[1] = 0;
        } else {
            uVar2 = (std::uint32_t)(std::uintptr_t)thunk_FUN_00533c78(newSize * 4);
            self[1] = uVar2;
            uVar3 = 0;
            if ((std::int32_t)self[3] != 0) {
                do {
                    *(std::uint32_t*)(self[1] + uVar3 * 4) =
                        *(std::uint32_t*)((std::uint8_t*)pvVar1 + uVar3 * 4);
                    uVar3 = uVar3 + 1;
                } while (uVar3 < self[3]);
            }
            uVar3 = self[3];
            if (uVar3 < self[2]) {
                do {
                    *(std::uint32_t*)(self[1] + uVar3 * 4) = 0;
                    uVar3 = uVar3 + 1;
                } while (uVar3 < self[2]);
                operator_delete__(pvVar1);
                return;
            }
        }
        operator_delete__(pvVar1);
    }
    return;
}

// 0x004eda50 — observed shape
// Sparse float-vector write. self = in_ECX (same [1]=data,[2]=capacity,
// [3]=used,[4]=nonzero layout as 0x4ed9a0), index = in_EDX, value = in_ESI.
// Maintains the nonzero counter across transitions to/from 0.0f.
void FUN_004eda50(std::uint32_t* self, std::uint32_t index, float* value) {
    bool bVar1;
    float* data;

    if (index < self[2]) {
        data = (float*)self[1];
        if (index < self[3]) {
            bVar1 = data[index] == 0.0f;
            if (*value == 0.0f) {
                if (!bVar1) {
                    self[4] = self[4] - 1;
                }
            } else if (bVar1) {
                self[4] = self[4] + 1;
                data[index] = *value;
                return;
            }
        } else {
            self[3] = index + 1;
            if (*value != 0.0f) {
                self[4] = self[4] + 1;
                data[index] = *value;
                return;
            }
        }
        data[index] = *value;
    }
    return;
}

// 0x004edc40 — observed shape
// Deleting destructor (scalar-delete flag in param_1). self = in_ECX.
void FUN_004edc40(std::uint8_t param_1, std::uint32_t* self) {
    *self = (std::uint32_t)(std::uintptr_t)PTR_FUN_0070fd0c;
    FUN_004e6420(self);
    operator_delete__((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x004edcc0 — observed shape
// Deleting destructor; self = in_ECX.
void FUN_004edcc0(std::uint8_t param_1, std::uint32_t* self) {
    *self = (std::uint32_t)(std::uintptr_t)PTR_FUN_0070fd48;
    FUN_004e6420(self);
    operator_delete__((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x004edd60 — observed shape
// Deleting destructor releasing field +4; self = in_ECX.
void FUN_004edd60(std::uint8_t param_1, std::uint32_t* self) {
    *self = (std::uint32_t)(std::uintptr_t)PTR_FUN_0070fe10;
    operator_delete__((void*)self[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x004edd90 — observed shape
// Deleting destructor with two vtable stores (0x70fd28 then 0x70fd0c);
// self = in_ECX.
void FUN_004edd90(std::uint8_t param_1, std::uint32_t* self) {
    *self = (std::uint32_t)(std::uintptr_t)PTR_FUN_0070fd28;
    FUN_004e6420(self);
    *self = (std::uint32_t)(std::uintptr_t)PTR_FUN_0070fd0c;
    FUN_004e6420(self);
    operator_delete__((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x004eddd0 — observed shape
// Deleting destructor with two vtable stores (0x70fd64 then 0x70fd48);
// self = in_ECX.
void FUN_004eddd0(std::uint8_t param_1, std::uint32_t* self) {
    *self = (std::uint32_t)(std::uintptr_t)PTR_FUN_0070fd64;
    FUN_004e6420(self);
    *self = (std::uint32_t)(std::uintptr_t)PTR_FUN_0070fd48;
    FUN_004e6420(self);
    operator_delete__((void*)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x004ede10 — observed shape
// Releases the refcounted object at param_1+8 (vtable slot 0 with arg 1, then
// clears the slot) and tail-calls the base destructor FUN_004b0650 (no
// explicit arguments in the listing; receiver implicit in ECX).
void FUN_004ede10(std::int32_t param_1) {
    std::int32_t* piVar1;
    std::uint32_t* puVar2;

    puVar2 = *(std::uint32_t**)(param_1 + 8);
    if (puVar2 != (std::uint32_t*)0x0) {
        piVar1 = (std::int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar2)(1);
        }
        *(std::uint32_t*)(param_1 + 8) = 0;
    }
    FUN_004b0650();
    return;
}

// 0x004edf70 — observed shape
// Pops the head node of a container (self = in_ESI, int*: [0]=vtable,
// [1]=tail, [2]=head, [3]=count), publishes its retained payload to *out
// (in_EBX), and releases the popped node through vtable[2].
void FUN_004edf70(std::int32_t* self, std::int32_t* out) {
    std::int32_t iVar1;
    std::uint32_t* puVar2;

    iVar1 = self[2];
    puVar2 = *(std::uint32_t**)(iVar1 + 4);
    self[2] = (std::int32_t)(std::uintptr_t)puVar2;
    if (puVar2 == (std::uint32_t*)0x0) {
        self[1] = 0;
    } else {
        *puVar2 = 0;
    }
    puVar2 = *(std::uint32_t**)(iVar1 + 8);
    if (puVar2 != (std::uint32_t*)0x0) {
        puVar2[1] = puVar2[1] + 1;
    }
    reinterpret_cast<void (*)(void*)>((*(void***)self)[2])((void*)(std::uintptr_t)iVar1);
    self[3] = self[3] + -1;
    *out = (std::int32_t)(std::uintptr_t)puVar2;
    if (puVar2 != (std::uint32_t*)0x0) {
        iVar1 = puVar2[1];
        puVar2[1] = iVar1 + 1;
        puVar2[1] = iVar1;
        if (iVar1 == 0) {
            reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar2)(1);
        }
    }
    return;
}

// 0x004edfd0 — observed shape
// Returns the retained interface pointer at self+8 when its first virtual
// call's result walks to &DAT_00727560 (traversing +4 links); else null.
// self = in_EAX.
std::int32_t* FUN_004edfd0(std::uint32_t* self) {
    std::int32_t* piVar1;
    std::uint32_t* puVar2;

    piVar1 = *(std::int32_t**)((std::uint8_t*)self + 8);
    if (piVar1 == (std::int32_t*)0x0) {
        return (std::int32_t*)0x0;
    }
    puVar2 = (std::uint32_t*)reinterpret_cast<void* (*)(void)>((*(void***)piVar1)[1])();
    while (true) {
        if (puVar2 == (std::uint32_t*)0x0) {
            return (std::int32_t*)0x0;
        }
        if (puVar2 == (std::uint32_t*)DAT_00727560) break;
        puVar2 = (std::uint32_t*)puVar2[1];
    }
    return piVar1;
}

// 0x004ee010 — observed shape
// Appends a newly allocated node holding *value (in_EBX) to the list at
// self (in_EDI, [0]=vtable, [1]=tail, [2]=head, [3]=count).
void FUN_004ee010(std::int32_t* self, std::int32_t* value) {
    std::int32_t* piVar1;
    std::uint32_t* puVar2;
    std::int32_t iVar3;
    std::int32_t* piVar4;

    piVar4 = (std::int32_t*)reinterpret_cast<void* (*)(void)>((*(void***)self)[1])();
    puVar2 = (std::uint32_t*)piVar4[2];
    if (puVar2 != (std::uint32_t*)*value) {
        if (puVar2 != (std::uint32_t*)0x0) {
            piVar1 = (std::int32_t*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar2)(1);
            }
        }
        iVar3 = *value;
        piVar4[2] = iVar3;
        if (iVar3 != 0) {
            *(std::int32_t*)(iVar3 + 4) = *(std::int32_t*)(iVar3 + 4) + 1;
        }
    }
    piVar4[1] = 0;
    *piVar4 = self[1];
    if (self[1] == 0) {
        self[2] = (std::int32_t)(std::uintptr_t)piVar4;
        self[1] = (std::int32_t)(std::uintptr_t)piVar4;
        self[3] = self[3] + 1;
        return;
    }
    *(std::int32_t**)(self[1] + 4) = piVar4;
    self[1] = (std::int32_t)(std::uintptr_t)piVar4;
    self[3] = self[3] + 1;
    return;
}

// 0x004ee070 — observed shape
// Plane classify: dot(*param_1.xyz, self.xyz) - param_1.w against -self.w and
// self.w. Returns 2 (below), 1 (above-or-on), 0 (inside); NaN compares are
// guarded exactly as the decompiler emitted them. self = in_ECX.
std::uint32_t FUN_004ee070(float* param_1, float* self) {
    float fVar1;
    float fVar2;

    fVar1 = (*param_1 * self[0] + param_1[1] * self[1] + param_1[2] * self[2]) - param_1[3];
    fVar2 = -self[3];
    if ((fVar1 == fVar1) && (fVar2 == fVar2) && ((fVar1 < fVar2) != (fVar1 == fVar2))) {
        return 2;
    }
    if (self[3] <= fVar1) {
        return 1;
    }
    return 0;
}

// 0x004ee0c0 — observed shape
// Retained-object assignment: drop *self, adopt *param_1 with addref.
// self = in_ECX.
void FUN_004ee0c0(std::int32_t* param_1, std::uint32_t* self) {
    std::int32_t* piVar1;
    std::uint32_t* puVar2;
    std::int32_t iVar3;

    puVar2 = (std::uint32_t*)*self;
    if (puVar2 != (std::uint32_t*)*param_1) {
        if (puVar2 != (std::uint32_t*)0x0) {
            piVar1 = (std::int32_t*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar2)(1);
            }
        }
        iVar3 = *param_1;
        *self = (std::uint32_t)iVar3;
        if (iVar3 != 0) {
            *(std::int32_t*)(iVar3 + 4) = *(std::int32_t*)(iVar3 + 4) + 1;
        }
    }
    return;
}

// 0x004ee100 — observed shape
// Grows the vector at param_1 to at least param_2 elements, appending nodes
// built by a fresh FUN_00538680 object and the node allocator at self+8
// (vtable[1]); returns the number of appended entries.
std::int32_t FUN_004ee100(std::int32_t param_1, std::uint32_t param_2) {
    std::int32_t* piVar1;
    std::int32_t iVar2;
    std::uint32_t* puVar3;
    std::int32_t iVar4;
    std::uint32_t uVar5;
    std::uint32_t* puVar6;
    std::uint32_t* puVar7;

    iVar4 = param_1;
    iVar2 = *(std::int32_t*)(param_1 + 0x14);
    param_1 = iVar2;
    while (true) {
        uVar5 = *(std::uint32_t*)(iVar4 + 4);
        if (param_2 <= *(std::uint32_t*)(iVar4 + 4)) {
            uVar5 = param_2;
        }
        if ((std::int32_t)uVar5 <= param_1) break;
        puVar6 = (std::uint32_t*)FUN_00538680();
        if (puVar6 != (std::uint32_t*)0x0) {
            puVar6[1] = puVar6[1] + 1;
        }
        puVar7 = (std::uint32_t*)reinterpret_cast<void* (*)(void)>(
            (*(void***)(iVar4 + 8))[1])();
        puVar3 = (std::uint32_t*)puVar7[2];
        if (puVar3 != puVar6) {
            if (puVar3 != (std::uint32_t*)0x0) {
                piVar1 = (std::int32_t*)(puVar3 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar3)(1);
                }
            }
            puVar7[2] = (std::uint32_t)(std::uintptr_t)puVar6;
            if (puVar6 != (std::uint32_t*)0x0) {
                puVar6[1] = puVar6[1] + 1;
            }
        }
        puVar7[1] = 0;
        *puVar7 = *(std::uint32_t*)(iVar4 + 0xc);
        if (*(std::int32_t*)(iVar4 + 0xc) == 0) {
            *(std::uint32_t**)(iVar4 + 0x10) = puVar7;
        } else {
            *(std::uint32_t**)(*(std::int32_t*)(iVar4 + 0xc) + 4) = puVar7;
        }
        *(std::uint32_t**)(iVar4 + 0xc) = puVar7;
        *(std::int32_t*)(iVar4 + 0x14) = *(std::int32_t*)(iVar4 + 0x14) + 1;
        if (puVar6 != (std::uint32_t*)0x0) {
            piVar1 = (std::int32_t*)(puVar6 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar6)(1);
            }
        }
        param_1 = param_1 + 1;
    }
    return param_1 - iVar2;
}

// 0x004ee1c0 — observed shape
// Constructor: self = in_ESI (int*: [0]=retained object, [1]=value,
// [2]=vtable 0x70fce8, [3..5]=0) adopting param_1 (undefined4*) and storing
// param_2, then releasing the caller's reference.
void FUN_004ee1c0(std::uint32_t* param_1, std::int32_t param_2, std::int32_t* self) {
    std::int32_t* piVar1;
    std::uint32_t* puVar2;

    *self = 0;
    self[5] = 0;
    self[3] = 0;
    self[4] = 0;
    self[2] = (std::int32_t)(std::uintptr_t)PTR_FUN_0070fce8;
    puVar2 = (std::uint32_t*)*self;
    if (puVar2 != param_1) {
        if (puVar2 != (std::uint32_t*)0x0) {
            piVar1 = (std::int32_t*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                reinterpret_cast<void (*)(std::int32_t)>(*(void**)puVar2)(1);
            }
        }
        *self = (std::int32_t)(std::uintptr_t)param_1;
        if (param_1 != (std::uint32_t*)0x0) {
            param_1[1] = param_1[1] + 1;
        }
    }
    self[1] = param_2;
    if (param_1 != (std::uint32_t*)0x0) {
        piVar1 = (std::int32_t*)(param_1 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            reinterpret_cast<void (*)(std::int32_t)>(*(void**)param_1)(1);
        }
    }
    return;
}

// 0x004ee250 — observed shape
// Clears the list at self (in_ECX: [0]=vtable, [1]=tail, [2]=head, [3]=count),
// freeing every node through vtable[2], then installs the tail vtable
// 0x70fe14. Nodes are walked through their first dword link.
void FUN_004ee250(std::uint32_t* self) {
    std::uint32_t* puVar1;
    std::uint32_t* puVar2;

    *self = (std::uint32_t)(std::uintptr_t)PTR_FUN_0070fce8;
    puVar2 = (std::uint32_t*)self[1];
    while (puVar2 != (std::uint32_t*)0x0) {
        puVar1 = (std::uint32_t*)*puVar2;
        reinterpret_cast<void (*)(void*)>((*(void***)*self)[2])(puVar2);
        puVar2 = puVar1;
    }
    self[3] = 0;
    self[1] = 0;
    self[2] = 0;
    *self = (std::uint32_t)(std::uintptr_t)PTR_LAB_0070fe14;
    return;
}
