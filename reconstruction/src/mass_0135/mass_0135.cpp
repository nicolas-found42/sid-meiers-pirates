#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* PTR_FUN_006c17bc;
extern void* PTR_FUN_006c182c;
extern void FUN_005e1490(void* self);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern uint8_t FUN_005bd960(uint32_t param, void** out_cb);

// 0x545580 — observed shape: destructor-like free function, vtable reset then conditional free
void FUN_00545580(void* self, uint8_t param_1) {
    uint32_t* v = static_cast<uint32_t*>(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c17bc);
    FUN_005e1490(self);
    operator_delete__(reinterpret_cast<void*>(v[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5455c0 — observed shape: destructor-like, two vtable resets then conditional free
void FUN_005455c0(void* self, uint8_t param_1) {
    uint32_t* v = static_cast<uint32_t*>(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c182c);
    FUN_005e1490(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c17bc);
    FUN_005e1490(self);
    operator_delete__(reinterpret_cast<void*>(v[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x545600 — observed shape: indexed lookup with sentinel, counter at +0x170
uint32_t FUN_00545600(void* self) {
    uint8_t* b = static_cast<uint8_t*>(self);
    int idx = *reinterpret_cast<int*>(b + 0x170);
    *reinterpret_cast<int*>(b + 0x170) = idx + 1;
    int inner = *reinterpret_cast<int*>(*reinterpret_cast<int*>(b + 0x164) + idx * 4);
    if (inner == -1) {
        return 0;
    }
    return static_cast<uint32_t>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(b + 0x130) + inner * 4));
}

// 0x545630 — observed shape: post-increment counter at +0x180, indexed load via +0x174
uint32_t FUN_00545630(void* self) {
    uint8_t* b = static_cast<uint8_t*>(self);
    int idx = *reinterpret_cast<int*>(b + 0x180);
    *reinterpret_cast<int*>(b + 0x180) = idx + 1;
    return static_cast<uint32_t>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(b + 0x174) + idx * 4));
}

// 0x545680 — observed shape: indirect call through registered callback
uint32_t FUN_00545680(uint32_t param_1) {
    void* local_4 = nullptr;
    uint8_t ok = FUN_005bd960(param_1, &local_4);
    if (ok == 0) {
        return 0;
    }
    using CbFn = uint32_t (*)();
    CbFn fn = reinterpret_cast<CbFn>(local_4);
    return fn();
}
extern uint32_t FUN_00545310(uint32_t a, uint32_t b);
extern void FUN_005bfa50(uint32_t a);

// 0x5456c0 — observed shape: linear search in int array at +8, count at +0x10
uint32_t FUN_005456c0(void* self, int param_1) {
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t idx = 0;
    if (*reinterpret_cast<uint32_t*>(b + 0x10) != 0) {
        int* arr = reinterpret_cast<int*>(*reinterpret_cast<int*>(b + 8));
        do {
            if (param_1 == *arr) {
                return idx;
            }
            idx = idx + 1;
            arr = arr + 1;
        } while (idx < *reinterpret_cast<uint32_t*>(b + 0x10));
    }
    return 0;
}

// 0x5456f0 — observed shape: two float ratio outputs, zero pair when field +0x1a0 is -1
void FUN_005456f0(void* self, float* param_1) {
    uint8_t* b = static_cast<uint8_t*>(self);
    int iVar4 = *reinterpret_cast<int*>(b + 0x1a0);
    if (iVar4 == -1) {
        param_1[1] = 0.0f;
        param_1[0] = 0.0f;
        return;
    }
    int iVar1 = *reinterpret_cast<int*>(b + 0x134);
    float fVar2 = static_cast<float>(iVar4);
    if (iVar4 < 0) {
        fVar2 = fVar2 + 4.2949673e+09f;
    }
    float fVar3 = static_cast<float>(iVar1);
    if (iVar1 < 0) {
        fVar3 = fVar3 + 4.2949673e+09f;
    }
    param_1[0] = fVar2 / fVar3;
    iVar4 = *reinterpret_cast<int*>(b + 0x1a8) + *reinterpret_cast<int*>(b + 0x1a4);
    fVar2 = static_cast<float>(iVar4);
    if (iVar4 < 0) {
        fVar2 = fVar2 + 4.2949673e+09f;
    }
    fVar3 = static_cast<float>(iVar1 * 2);
    if (iVar1 * 2 < 0) {
        fVar3 = fVar3 + 4.2949673e+09f;
    }
    param_1[1] = fVar2 / fVar3;
}

// 0x545780 — observed shape: forward two args then return 0
uint32_t FUN_00545780(uint32_t param_1, uint32_t param_2) {
    FUN_00545310(param_1, param_2);
    return 0;
}

// 0x5457a0 — observed shape: forward one arg then return
void FUN_005457a0(uint32_t param_1) {
    FUN_005bfa50(param_1);
}

// 0x545870 — observed shape: virtual call offset +0xc repeated for each element; slot pointer advanced by -4 each iteration
void FUN_00545870(void* self) {
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t count = *reinterpret_cast<uint32_t*>(b + 0x10);
    int32_t local_4 = static_cast<int32_t>(count) - 1;
    using SlotFn = void (*)(void*, int);
    auto* table = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(b + 0x160));
    SlotFn slot0 = reinterpret_cast<SlotFn>(table[3]);
    slot0(&local_4, 4);
    uint32_t uVar1 = 1;
    if (1 < count) {
        do {
            // register0x00000010 - 0xc == &local_4 - 4 after first call; successive calls step the 4-byte value
            SlotFn slot = reinterpret_cast<SlotFn>(table[3]);
            int32_t decremented = local_4 - 1;
            slot(&decremented, 4);
            local_4 = decremented;
            uVar1 = uVar1 + 1;
        } while (uVar1 < count);
    }
}

extern void* PTR_FUN_006c18a8;
extern void* PTR_FUN_006c188c;
extern void* PTR_FUN_006c17d8;
extern void* PTR_FUN_006c197c;
extern void* PTR_FUN_006c18c4;
extern void* PTR_FUN_006c17f4;
extern void* DAT_00727868;
extern void FUN_00567d90(void);
extern uint32_t FUN_00567cf0(void);
extern void FUN_00567be0(void);
extern void FUN_004b1100(void);
extern void FUN_004b10d0(void);

// 0x5458d0 — observed shape: loop over vector at +0x148 (count +0x150), dispatch virtual slot +0x14 per element
void FUN_005458d0(void* self) {
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t i = 0;
    using Vfn = void (*)(void*);
    if (*reinterpret_cast<int*>(b + 0x150) != 0) {
        do {
            uint32_t obj = *reinterpret_cast<uint32_t*>(
                *reinterpret_cast<uint32_t*>(b + 0x148) + i * 4);
            Vfn fn = reinterpret_cast<Vfn>(
                *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(obj) + 0x14));
            fn(reinterpret_cast<void*>(obj));
            i = i + 1;
        } while (i < *reinterpret_cast<uint32_t*>(b + 0x150));
    }
}

// 0x545900 — observed shape: begin/end transaction around a virtual call writing a 12-byte record;
// `unaff_retaddr` is the hidden return slot provided by the caller, modeled as an explicit pointer.
uint8_t FUN_00545900(void* self, uint32_t* param_1, uint32_t* ret_slot) {
    uint8_t local_18[12] = {0};
    using Vfn = uint8_t (*)(void*, void*);
    FUN_00567d90();
    Vfn fn = reinterpret_cast<Vfn>(
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(self) + 0x10));
    uint8_t uVar1 = fn(self, local_18);
    *param_1 = *reinterpret_cast<uint32_t*>(local_18 + 8);
    *ret_slot = FUN_00567cf0();
    FUN_00567be0();
    return uVar1;
}

// 0x545950 — observed shape: write measured string length then string bytes through virtual slot +0xc
void FUN_00545950(void* self, char* param_1, int32_t unaff_ESI) {
    char* pcVar3 = param_1;
    uint32_t length = 0;
    if (param_1 != nullptr) {
        char* pcVar1 = param_1 + 1;
        char cVar2;
        do {
            cVar2 = *param_1;
            param_1 = param_1 + 1;
        } while (cVar2 != '\0');
        length = static_cast<uint32_t>(param_1 - pcVar1);
    }
    using WriteFn = void (*)(void*, void*, int32_t);
    WriteFn write = reinterpret_cast<WriteFn>(
        *reinterpret_cast<uint32_t*>(
            *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x160) + 0xc));
    write(self, &length, 4);
    if (unaff_ESI != 0) {
        write(self, pcVar3, unaff_ESI);
    }
}

// 0x5459d0 — observed shape: null-check object at +0x194 then dispatch virtual slot +4
uint32_t FUN_005459d0(void* self) {
    uint32_t obj = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x194);
    if (obj == 0) {
        return 0;
    }
    using Vfn = uint32_t (*)(void*);
    Vfn fn = reinterpret_cast<Vfn>(
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(obj) + 4));
    return fn(reinterpret_cast<void*>(obj));
}

// 0x5459f0 — observed shape: destroy hash bucket chains (next at [0], value at [1]), then two base vtable resets
void FUN_005459f0(void* self) {
    uint32_t* v = static_cast<uint32_t*>(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c18a8);
    if (*reinterpret_cast<uint8_t*>(v + 4) != 0 && v[1] != 0) {
        uint32_t i = 0;
        do {
            uint32_t* node = reinterpret_cast<uint32_t*>(v[2] + i * 4);
            while (node != nullptr) {
                uint32_t* value_slot = node + 1;
                node = reinterpret_cast<uint32_t*>(*node);
                operator_delete__(reinterpret_cast<void*>(*value_slot));
            }
            i = i + 1;
        } while (i < v[1]);
    }
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c188c);
    FUN_005e1490(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c17d8);
    FUN_005e1490(self);
    operator_delete__(reinterpret_cast<void*>(v[2]));
}

// 0x545a70 — observed shape: intrusive single-linked list push at DAT_00727868 guarded by lock helpers
void FUN_00545a70(uint32_t* param_1) {
    *reinterpret_cast<uint16_t*>(param_1 + 2) = 0;
    FUN_004b1100();
    param_1[1] = 0;
    param_1[0] = reinterpret_cast<uint32_t>(DAT_00727868);
    DAT_00727868 = param_1;
    FUN_004b10d0();
}

// 0x545ab0 — observed shape: destroy hash bucket chains, then two base vtable resets (alternate layout)
void FUN_00545ab0(void* self) {
    uint32_t* v = static_cast<uint32_t*>(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c197c);
    if (*reinterpret_cast<uint8_t*>(v + 4) != 0 && v[1] != 0) {
        uint32_t i = 0;
        do {
            uint32_t* node = reinterpret_cast<uint32_t*>(v[2] + i * 4);
            while (node != nullptr) {
                uint32_t* value_slot = node + 1;
                node = reinterpret_cast<uint32_t*>(*node);
                operator_delete__(reinterpret_cast<void*>(*value_slot));
            }
            i = i + 1;
        } while (i < v[1]);
    }
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c18c4);
    FUN_005e1490(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c17f4);
    FUN_005e1490(self);
    operator_delete__(reinterpret_cast<void*>(v[2]));
}

// 0x545b90 — observed shape: vtable reset, base destructor, delete +2, conditional free
void FUN_00545b90(void* self, uint8_t param_1) {
    uint32_t* v = static_cast<uint32_t*>(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c17d8);
    FUN_005e1490(self);
    operator_delete__(reinterpret_cast<void*>(v[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x545bd0 — observed shape: two vtable resets, base destructor, delete +2, conditional free
void FUN_00545bd0(void* self, uint8_t param_1) {
    uint32_t* v = static_cast<uint32_t*>(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c188c);
    FUN_005e1490(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c17d8);
    FUN_005e1490(self);
    operator_delete__(reinterpret_cast<void*>(v[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x545c10 — observed shape: vtable reset, base destructor, delete +2, conditional free
void FUN_00545c10(void* self, uint8_t param_1) {
    uint32_t* v = static_cast<uint32_t*>(self);
    v[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c17f4);
    FUN_005e1490(self);
    operator_delete__(reinterpret_cast<void*>(v[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
