#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_0053d980(int param_1);
extern void FUN_00535110(int param_1);
extern void FUN_0053d9c0(int param_1);
extern void FUN_00535150(int param_1);
extern void FUN_00548600(uint32_t param_1);
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;

// 0x557ab0 — observed shape
void FUN_00557ab0(void* self, int param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int* vtablePtr = *reinterpret_cast<int**>(reinterpret_cast<intptr_t>(param_1) + 0x15c);
    FUN_0053d980(param_1);
    FUN_00535110(param_1);
    auto func = reinterpret_cast<void(*)(void*, int)>(*reinterpret_cast<void**>(reinterpret_cast<intptr_t>(vtablePtr) + 8));
    func(selfBytes + 0x30, 4);
}

// 0x557ae0 — observed shape
void FUN_00557ae0(void* self, int param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    int* vtablePtr = *reinterpret_cast<int**>(reinterpret_cast<intptr_t>(param_1) + 0x160);
    FUN_0053d9c0(param_1);
    FUN_00535150(param_1);
    auto func = reinterpret_cast<void(*)(void*, int)>(*reinterpret_cast<void**>(reinterpret_cast<intptr_t>(vtablePtr) + 0xc));
    func(selfBytes + 0x30, 4);
}

// 0x557e70 — observed shape
void FUN_00557e70(uint32_t* self, int param_1)
{
    uint32_t* src = *reinterpret_cast<uint32_t**>(reinterpret_cast<intptr_t>(param_1) + 4);
    self[0] = src[0];
    self[1] = src[1];
    self[2] = src[2];
    self[3] = src[3];
    uint32_t count = *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(param_1) + 0xc);
    uint32_t idx = 1;
    if (1 < count) {
        do {
            uint32_t elemPtr = *reinterpret_cast<uint32_t*>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1) + 4) + idx * 4);
            FUN_00548600(elemPtr);
            idx = idx + 1;
        } while (idx < count);
    }
}

// 0x557ec0 — observed shape
uint32_t FUN_00557ec0(float param_1, float* param_2, float* param_3, float* param_4, float* param_5)
{
    float fVar1 = param_5[0] - param_3[0];
    float fVar2 = param_5[1] - param_3[1];
    float fVar3 = param_5[2] - param_3[2];
    float fVar4 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
    float fVar5 = param_4[0] - param_2[0];
    float fVar6 = param_4[1] - param_2[1];
    float fVar7 = param_4[2] - param_2[2];
    float fVar8 = fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7;
    float fVar9 = (param_2[3] + param_4[3]) * (param_2[3] + param_4[3]);
    uint8_t bVar10;
    float dot;
    if ((fVar4 <= 0.0f) || ((dot = fVar6 * fVar2 + fVar5 * fVar1 + fVar7 * fVar3, dot != dot || (dot < 0.0f) == (dot == 0.0f)))) {
        int cmpLess = (fVar8 < fVar9) ? 1 : 0;
        int cmpEq = (fVar8 == fVar9) ? 1 : 0;
        bVar10 = static_cast<uint8_t>(cmpLess | ((cmpEq << 0xe) >> 8));
    } else {
        float fVar2b = -(fVar4 * param_1);
        if ((fVar2b == fVar2b && dot == dot) && ((fVar2b < dot) != (fVar2b == dot))) {
            if (fVar9 * fVar4 < fVar8 * fVar4 - dot * dot) {
                return 0;
            }
            return 1;
        }
        fVar8 = (dot + dot + fVar4 * param_1) * param_1 + fVar8;
        int cmpLess = (fVar8 < fVar9) ? 1 : 0;
        int cmpEq = (fVar8 == fVar9) ? 1 : 0;
        bVar10 = static_cast<uint8_t>(cmpLess | ((cmpEq << 0xe) >> 8));
    }
    int pop = __builtin_popcount(static_cast<unsigned int>(bVar10));
    if ((pop & 1U) == 0) {
        return 0;
    }
    return 1;
}

// 0x558050 — observed shape
void FUN_00558050(uint32_t* self)
{
    self[0] = DAT_00727430;
    self[1] = DAT_00727434;
    self[2] = DAT_00727438;
    self[3] = 0;
}

extern int thunk_FUN_00533c78(int param_1);
extern void FUN_004127b0(int param_1, int param_2, int param_3, void* param_4);
extern void FUN_00513ce0(uint32_t param_1);
extern void* FUN_00545600();

// 0x558080 — observed shape
void FUN_00558080(uint32_t* self, uint32_t* param_1, uint32_t param_2)
{
    self[0] = param_1[0];
    self[1] = param_1[1];
    self[2] = param_1[2];
    self[3] = param_2;
}

// 0x5580b0 — observed shape
void FUN_005580b0(float* self, float* param_1, float* param_2)
{
    self[0] = param_1[0];
    self[1] = param_1[1];
    self[2] = param_1[2];
    self[3] = param_1[0] * param_2[0] + param_1[1] * param_2[1] + param_1[2] * param_2[2];
}

// 0x5580f0 — observed shape
void FUN_005580f0(int* param_1)
{
    auto func = reinterpret_cast<void(*)()>(*reinterpret_cast<void**>(static_cast<intptr_t>(*param_1) + 0xdc));
    func();
}

// 0x558170 — observed shape
void FUN_00558170(int* self, int param_1)
{
    if (param_1 != self[1]) {
        int newBuf = 0;
        if (param_1 != 0) {
            newBuf = thunk_FUN_00533c78(param_1 * 0x1c);
            if (newBuf != 0) {
                FUN_004127b0(newBuf, 0x1c, param_1, reinterpret_cast<void*>(0x558120));
            }
            uint32_t copied = 0;
            if (self[2] != 0) {
                int offset = 0;
                do {
                    uint32_t* src = reinterpret_cast<uint32_t*>(*reinterpret_cast<intptr_t*>(self) + offset);
                    uint32_t* dst = reinterpret_cast<uint32_t*>(offset + newBuf);
                    for (int i = 7; i != 0; i = i - 1) {
                        *dst = *src;
                        src = src + 1;
                        dst = dst + 1;
                    }
                    copied = copied + 1;
                    offset = offset + 0x1c;
                } while (copied < static_cast<uint32_t>(self[2]));
            }
        }
        operator delete(reinterpret_cast<void*>(*reinterpret_cast<intptr_t*>(self)));
        *reinterpret_cast<intptr_t*>(self) = newBuf;
        self[1] = param_1;
    }
}

// 0x558240 — observed shape
void FUN_00558240(uint8_t* self, uint32_t param_1)
{
    FUN_00513ce0(param_1);
    uint32_t* newRef = static_cast<uint32_t*>(FUN_00545600());
    uint32_t** slot = reinterpret_cast<uint32_t**>(self + 0x18);
    uint32_t* oldRef = *slot;
    if (oldRef != newRef) {
        if (oldRef != nullptr) {
            int* refCount = reinterpret_cast<int*>(oldRef + 1);
            *refCount = *refCount - 1;
            if (*refCount == 0) {
                auto deleteFn = reinterpret_cast<void(*)(int)>(*reinterpret_cast<void**>(oldRef));
                deleteFn(1);
            }
        }
        *slot = newRef;
        if (newRef != nullptr) {
            newRef[1] = newRef[1] + 1;
        }
    }
}

extern void FUN_00538430(int* param_1);
extern void FUN_005351e0(int* param_1);
extern int FUN_00538460(int param_1);
extern int FUN_0050b0f0(short* param_1);
extern void FUN_00538400();
extern void FUN_00538410(int param_1, int param_2);
extern void FUN_00538630();
extern void FUN_00535190();
extern void FUN_00545cc0();

// 0x558280 — observed shape
void FUN_00558280(uint8_t* self, int* param_1)
{
    FUN_00538430(param_1);
    int count = *reinterpret_cast<int*>(self + 0x14);
    int* vtable = *reinterpret_cast<int**>(*reinterpret_cast<intptr_t*>(reinterpret_cast<intptr_t>(param_1) + 0x58 * 4));
    auto writeFn = reinterpret_cast<void(*)(void*, int)>(*reinterpret_cast<void**>(*reinterpret_cast<intptr_t*>(vtable) + 0xc));
    writeFn(&count, 4);
    uint32_t idx = 0;
    if (count != 0) {
        int offset = 0;
        do {
            int elemAddr = *reinterpret_cast<int*>(self + 0xc) + offset;
            auto f = reinterpret_cast<void(*)(int, int)>(*reinterpret_cast<void**>(*reinterpret_cast<intptr_t*>(vtable) + 0xc));
            f(elemAddr, 2);
            f(elemAddr + 2, 2);
            f(elemAddr + 4, 2);
            f(elemAddr + 6, 2);
            f(elemAddr + 8, 2);
            f(elemAddr + 10, 2);
            FUN_005351e0(param_1);
            idx = idx + 1;
            offset = offset + 0x1c;
        } while (idx < static_cast<uint32_t>(count));
    }
    auto finalFn = reinterpret_cast<void(*)(uint32_t)>(*reinterpret_cast<void**>(*reinterpret_cast<intptr_t*>(param_1) + 0x2c));
    finalFn(*reinterpret_cast<uint32_t*>(self + 0x18));
}

// 0x558380 — observed shape
bool FUN_00558380(uint8_t* self, int param_1)
{
    int eq = FUN_00538460(param_1);
    if (eq == 0) {
        return false;
    }
    uint32_t selfCount = *reinterpret_cast<uint32_t*>(self + 0x14);
    if (selfCount != *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(param_1) + 0x14)) {
        return false;
    }
    uint32_t idx = 0;
    if (selfCount != 0) {
        int16_t* a = *reinterpret_cast<int16_t**>(reinterpret_cast<intptr_t>(param_1) + 0xc);
        int16_t* b = reinterpret_cast<int16_t*>(*reinterpret_cast<intptr_t*>(self + 0xc) + 4);
        int baseDiff = *reinterpret_cast<int*>(self + 0xc) - reinterpret_cast<intptr_t>(a);
        do {
            int16_t* curA = reinterpret_cast<int16_t*>(baseDiff + reinterpret_cast<intptr_t>(a));
            if (curA[0] != a[0] && b[-1] != a[1] && b[0] != a[2] && b[1] != a[3] && b[2] != a[4] && b[3] != a[5] && FUN_0050b0f0(a + 6) != 0) {
                return false;
            }
            idx = idx + 1;
            b = b + 0xe;
            a = a + 0xe;
        } while (idx < selfCount);
    }
    int refObj = *reinterpret_cast<int*>(self + 0x18);
    auto cmpFn = reinterpret_cast<int(*)(int)>(*reinterpret_cast<void**>(*reinterpret_cast<intptr_t*>(refObj) + 0x1c));
    int otherRef = *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_1) + 0x18);
    return cmpFn(otherRef) != 0;
}

// 0x558460 — observed shape
void FUN_00558460(uint8_t* self, uint8_t param_1)
{
    *reinterpret_cast<void**>(self) = reinterpret_cast<void*>(0x6c2c28);
    FUN_00551170();
    uint32_t* refObj = *reinterpret_cast<uint32_t**>(self + 6 * 4);
    if (refObj != nullptr) {
        int* refCount = reinterpret_cast<int*>(refObj + 1);
        *refCount = *refCount - 1;
        if (*refCount == 0) {
            auto deleteFn = reinterpret_cast<void(*)(int)>(*reinterpret_cast<void**>(refObj));
            deleteFn(1);
        }
    }
    operator delete(*reinterpret_cast<void**>(self + 3 * 4));
    FUN_00538400();
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x5584b0 — observed shape
void FUN_005584b0(uint8_t* self, int param_1, int param_2)
{
    (void)param_2;
    FUN_00538410(param_1, param_2);
    uint32_t idx = 0;
    if (*reinterpret_cast<int*>(self + 0x14) != 0) {
        int offset = 0;
        do {
            int elemAddr = *reinterpret_cast<int*>(self + 0xc) + offset;
            uint32_t tmp[8];
            tmp[0] = *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(self + 0xc) + offset);
            tmp[1] = *reinterpret_cast<uint32_t*>(elemAddr + 4);
            tmp[2] = *reinterpret_cast<uint32_t*>(elemAddr + 8);
            tmp[3] = *reinterpret_cast<uint32_t*>(elemAddr + 0xc);
            tmp[4] = *reinterpret_cast<uint32_t*>(elemAddr + 0x10);
            tmp[5] = *reinterpret_cast<uint32_t*>(elemAddr + 0x14);
            tmp[6] = *reinterpret_cast<uint32_t*>(elemAddr + 0x18);
            tmp[7] = *reinterpret_cast<uint32_t*>(elemAddr + 0x1c);
            int cap = *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_1) + 0x10);
            int cnt = *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_1) + 0x14);
            if (cnt == cap) {
                int newCap = (cap == 0) ? 1 : cap * 2;
                FUN_00558170(static_cast<int*>(self), newCap);
            }
            uint32_t* dst = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_1) + 0x14) * 0x1c + *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_1) + 0xc));
            uint32_t* src = tmp;
            for (int i = 7; i != 0; i = i - 1) {
                *dst = *src;
                src = src + 1;
                dst = dst + 1;
            }
            *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_1) + 0x14) = *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_1) + 0x14) + 1;
            idx = idx + 1;
            offset = offset + 0x1c;
        } while (idx < *reinterpret_cast<uint32_t*>(self + 0x14));
    }
    uint32_t* selfRef = *reinterpret_cast<uint32_t**>(reinterpret_cast<intptr_t>(param_1) + 0x18);
    uint32_t* otherRef = *reinterpret_cast<uint32_t**>(self + 0x18);
    if (selfRef == otherRef) {
        *reinterpret_cast<uint16_t*>(reinterpret_cast<intptr_t>(param_1) + 0x1c) = *reinterpret_cast<uint16_t*>(self + 0x1c);
        return;
    }
    if (selfRef != nullptr) {
        int* refCount = reinterpret_cast<int*>(selfRef + 1);
        *refCount = *refCount - 1;
        if (*refCount == 0) {
            auto deleteFn = reinterpret_cast<void(*)(int)>(*reinterpret_cast<void**>(selfRef));
            deleteFn(1);
        }
    }
    int newRef = *reinterpret_cast<int*>(self + 0x18);
    *reinterpret_cast<int*>(reinterpret_cast<intptr_t>(param_1) + 0x18) = newRef;
    if (newRef == 0) {
        *reinterpret_cast<uint16_t*>(reinterpret_cast<intptr_t>(param_1) + 0x1c) = *reinterpret_cast<uint16_t*>(self + 0x1c);
        return;
    }
    *reinterpret_cast<int*>(static_cast<intptr_t>(newRef) + 4) = *reinterpret_cast<int*>(static_cast<intptr_t>(newRef) + 4) + 1;
    *reinterpret_cast<uint16_t*>(reinterpret_cast<intptr_t>(param_1) + 0x1c) = *reinterpret_cast<uint16_t*>(self + 0x1c);
}

// 0x5585f0 — observed shape
void FUN_005585f0(uint8_t* self, int param_1)
{
    FUN_00538630();
    int* vtable = *reinterpret_cast<int**>(reinterpret_cast<intptr_t>(param_1) + 0x15c);
    auto writeFn = reinterpret_cast<void(*)()>(*reinterpret_cast<void**>(*reinterpret_cast<intptr_t*>(vtable) + 8));
    writeFn();
    uint32_t idx = 0;
    uint32_t total = *reinterpret_cast<uint32_t*>(self + 0x14);
    if (total != 0) {
        do {
            auto f = reinterpret_cast<void(*)()>(*reinterpret_cast<void**>(*reinterpret_cast<intptr_t*>(vtable) + 8));
            f();
            auto f2 = reinterpret_cast<void(*)(void*, int)>(*reinterpret_cast<void**>(*reinterpret_cast<intptr_t*>(vtable) + 8));
            uint32_t dummy = 4;
            f2(&dummy, 2);
            f2(&dummy, 2);
            uint32_t dummy2 = 0;
            f2(&dummy2, 2);
            f2(&dummy2, 2);
            FUN_00535190();
            int cap = *reinterpret_cast<int*>(self + 0x10);
            int cnt = *reinterpret_cast<int*>(self + 0x14);
            if (cnt == cap) {
                int newCap = (cap == 0) ? 1 : cap * 2;
                FUN_00558170(reinterpret_cast<int*>(self), newCap);
            }
            uint32_t* dst = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(self + 0x14) * 0x1c + *reinterpret_cast<int*>(self + 0xc));
            uint32_t* src = reinterpret_cast<uint32_t*>(self + 0xc + idx * 0x1c);
            *dst = dummy;
            dst[1] = dummy2;
            dst[2] = 0;
            dst[3] = 0;
            dst[4] = 0;
            dst[5] = 0;
            dst[6] = param_1;
            idx = idx + 1;
            *reinterpret_cast<int*>(self + 0x14) = *reinterpret_cast<int*>(self + 0x14) + 1;
        } while (idx < total);
    }
    FUN_00545cc0();
}

extern void* FUN_00533c78(int param_1);
extern void FUN_005383d0();
extern void FUN_00541580();
extern void operator_delete__(void* param_1);
extern uint8_t PTR_FUN_006c2c28;
extern uint8_t PTR_FUN_006c2ee8;

// 0x558730 — observed shape
uint32_t* FUN_00558730(int param_1)
{
    uint32_t* puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x24));
    if (puVar1 == nullptr) {
        FUN_005584b0(nullptr, param_1, 0);
        return nullptr;
    }
    FUN_005383d0();
    *puVar1 = reinterpret_cast<uint32_t>(&PTR_FUN_006c2c28);
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    *reinterpret_cast<uint16_t*>(puVar1 + 7) = 0;
    puVar1[8] = 0;
    FUN_005584b0(reinterpret_cast<uint8_t*>(puVar1), param_1, 0);
    return puVar1;
}

// 0x558fc0 — observed shape
void FUN_00558fc0(void* self, int param_1, int param_2)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    uint32_t uVar2 = static_cast<uint32_t>(param_2 + 3) & 0xfffffffcU;
    int iVar1 = thunk_FUN_00533c78(static_cast<int>(uVar2 + 4 + param_1 * 0xc));
    *reinterpret_cast<int*>(selfBytes + 0x34) = iVar1;
    iVar1 = iVar1 + static_cast<int>(uVar2);
    *reinterpret_cast<int*>(selfBytes + 0x38) = iVar1;
    iVar1 = iVar1 + param_1 * 4;
    *reinterpret_cast<int*>(selfBytes + 0x3c) = iVar1;
    *reinterpret_cast<int*>(selfBytes + 0x40) = iVar1 + param_1 * 4;
}

// 0x559000 — observed shape
void FUN_00559000(void* self)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    operator_delete__(*reinterpret_cast<void**>(selfBytes + 0x34));
    *reinterpret_cast<uint32_t*>(selfBytes + 0x40) = 0;
    *reinterpret_cast<uint32_t*>(selfBytes + 0x3c) = 0;
    *reinterpret_cast<uint32_t*>(selfBytes + 0x38) = 0;
    *reinterpret_cast<uint32_t*>(selfBytes + 0x34) = 0;
}

// 0x559020 — observed shape
void FUN_00559020(uint32_t* self)
{
    *self = reinterpret_cast<uint32_t>(&PTR_FUN_006c2ee8);
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(self[0x10])));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(self[0x12])));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(self[0x13])));
    FUN_00541580();
}

// 0x559050 — observed shape
void FUN_00559050(void* self, void* param_1)
{
    uint8_t* selfBytes = static_cast<uint8_t*>(self);
    operator_delete__(*reinterpret_cast<void**>(selfBytes + 0x40));
    *reinterpret_cast<void**>(selfBytes + 0x40) = param_1;
}
