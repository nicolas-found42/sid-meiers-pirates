//
// mass_0194.cpp — reconstruction batch mass_0194
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants,
// call order, return shape, and conditional structure of the Ghidra
// 12.2 pseudocode (analysis/pseudocode/functions/*.c).
//
// Register receivers (in_ECX) are modeled as an explicit `void* self`.
// Unrecovered registers (unaff_EBX/ESI/EDI/EBP/retaddr) are explicit
// parameters, following the corpus meaning of those names.
//
#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals observed in the supplied corpus listings.
// `self` is appended where the callee listing shows an in_ECX receiver.
// ---------------------------------------------------------------------------
extern uint32_t FUN_005a1150(void* param_1, void* param_2, float* param_3,
                             uint32_t param_4, float* param_5, float* param_6);
// The listing of 0x5a14f0 shows this call with no recovered arguments
// (`FUN_005a1280()`); defaults keep that call site literal.
extern uint32_t FUN_005a1280(void* param_1 = nullptr, void* param_2 = nullptr,
                             float* param_3 = nullptr, float* param_4 = nullptr);
extern void FUN_005a8560(float* param_1, float* param_2, void* self);
extern uint32_t FUN_005a2990(int* param_1);
extern void FUN_005a4b20(int param_1, void* self);
extern uint32_t FUN_005a4c20(int param_1, void* self);
extern uint32_t FUN_005a2ad0(void* self, int param_1, uint32_t param_2,
                             uint32_t param_3, uint32_t param_4, uint32_t param_5,
                             uint8_t* param_6);
extern char FUN_0059ebe0(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                         uint32_t param_4, uint32_t param_5, uint32_t param_6,
                         uint32_t* param_7, int* param_8, void* param_9, void* param_10);
extern void* FUN_00533c78(int size);
extern int FUN_00594fa0(int param_1, void* self);
extern void FUN_00491640(void);
extern void FUN_00571ce0(void* p);
extern int FUN_0059fcc0(void* self);
extern int FUN_005a86a0(uint32_t param_1, uint32_t param_2, void* self);
extern void FUN_0053d8a0(void* param_1, float* param_2, void* self);
extern void FUN_005a19f0(void* self, float* param_1, int param_2, int param_3,
                         int param_4, int param_5, uint32_t param_6, int param_7, int param_8);
extern void FUN_00557990(void* self);
extern uint32_t FUN_005a57f0(int param_1, void* param_2, void* param_3, void* self);
extern uint32_t FUN_0059fce0(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                             uint32_t param_4, uint32_t param_5, void* self);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void operator_delete__(void* ptr);
extern uint32_t PTR_FUN_006c51e8;
extern float DAT_00727430;
extern float DAT_00727434;
extern float DAT_00727438;

// ---------------------------------------------------------------------------
// 0x5a1280
// ---------------------------------------------------------------------------
// Closest-point query between two objects' +0x7c sub-structures: builds the
// edge frame at +0x8c of both, tests both directions through FUN_005a1150,
// keeps the smaller parameter and returns the contact point in param_4.
// The listing leaves local_14/local_10 unassigned on the non-label path.
// 0x5a1280 — observed shape
uint32_t FUN_005a1280(void* param_1, void* param_2, float* param_3, float* param_4)
{
    float local_24, local_20, local_1c, local_18, local_14, local_10;
    float local_c, local_8, local_4;
    float fVar2, fVar3, fVar4;
    uintptr_t a = reinterpret_cast<uintptr_t>(param_1);
    uintptr_t b = reinterpret_cast<uintptr_t>(param_2);

    int iVar5 = *reinterpret_cast<int*>(a + 0x7c);
    uint32_t uVar6 = *reinterpret_cast<uint32_t*>(iVar5 + 4);
    int iVar7 = *reinterpret_cast<int*>(b + 0x7c);
    local_24 = *reinterpret_cast<float*>(iVar5 + 0x10) - *reinterpret_cast<float*>(iVar7 + 0x10);
    float* pfVar10 = reinterpret_cast<float*>(iVar7 + 0x10);
    uintptr_t iVar9 = a + 0x8c;
    uintptr_t iVar1 = b + 0x8c;
    local_20 = *reinterpret_cast<float*>(iVar5 + 0x14) - *reinterpret_cast<float*>(iVar7 + 0x14);
    local_1c = *reinterpret_cast<float*>(iVar5 + 0x18) - *reinterpret_cast<float*>(iVar7 + 0x18);
    float t1 = 3.4028235e+38f;
    local_c = local_24;
    local_8 = local_20;
    local_4 = local_1c;
    int iVar8 = static_cast<int>(FUN_005a1150(reinterpret_cast<void*>(iVar9),
                                              reinterpret_cast<void*>(iVar1),
                                              &local_24, uVar6, &t1, &local_18));
    local_24 = *pfVar10 - *reinterpret_cast<float*>(iVar5 + 0x10);
    float t2 = 3.4028235e+38f;
    local_20 = *reinterpret_cast<float*>(iVar7 + 0x14) - *reinterpret_cast<float*>(iVar5 + 0x14);
    local_1c = *reinterpret_cast<float*>(iVar7 + 0x18) - *reinterpret_cast<float*>(iVar5 + 0x18);
    local_c = local_24;
    local_8 = local_20;
    local_4 = local_1c;
    iVar9 = FUN_005a1150(reinterpret_cast<void*>(iVar1), reinterpret_cast<void*>(iVar9),
                         &local_24, uVar6, &t2, &local_c);

    bool useSecond = false;
    if (iVar8 == 0) {
        if (iVar9 == 0) {
            return 0;
        }
        *param_3 = t2;
        fVar2 = *reinterpret_cast<float*>(iVar5 + 0x10);
        fVar3 = *reinterpret_cast<float*>(iVar5 + 0x14);
        fVar4 = *reinterpret_cast<float*>(iVar5 + 0x18);
        useSecond = true;
    } else if (iVar9 == 0) {
        *param_3 = t1;
        fVar2 = *pfVar10;
        fVar3 = *reinterpret_cast<float*>(iVar7 + 0x14);
        fVar4 = *reinterpret_cast<float*>(iVar7 + 0x18);
    } else {
        if (std::isnan(t1) || std::isnan(t2) || (t1 < t2) == (t1 == t2)) {
            *param_3 = t2;
            fVar2 = *reinterpret_cast<float*>(iVar5 + 0x10);
            fVar3 = *reinterpret_cast<float*>(iVar5 + 0x14);
            fVar4 = *reinterpret_cast<float*>(iVar5 + 0x18);
            useSecond = true;
        } else {
            *param_3 = t1;
            fVar2 = *pfVar10;
            fVar3 = *reinterpret_cast<float*>(iVar7 + 0x14);
            fVar4 = *reinterpret_cast<float*>(iVar7 + 0x18);
        }
    }
    if (useSecond) {
        local_14 = local_8 + t2 * fVar3;
        local_c = local_18 + t2 * fVar2;
        *param_4 = local_c;
        param_4[1] = local_14;
        param_4[2] = local_4 + t2 * fVar4;
        return 1;
    }
    local_8 = local_14 + t1 * fVar3;
    local_c = local_18 + t1 * fVar2;
    *param_4 = local_c;
    param_4[1] = local_8;
    param_4[2] = local_10 + t1 * fVar4;
    return 1;
}

// ---------------------------------------------------------------------------
// 0x5a14f0
// ---------------------------------------------------------------------------
// Wraps the 0x5a1280 query with a stack-resident 5-dword descriptor
// (local_40..local_34), fills two 12-byte frames through FUN_005a8560, and
// forwards the descriptor to FUN_005a2990.
// 0x5a14f0 — observed shape
uint32_t FUN_005a14f0(void* self, int param_1, uint32_t param_2, uint32_t param_3,
                      uint32_t param_4, uint32_t param_5, uint8_t* param_6)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    uint32_t local_40;
    uint32_t local_3c;
    uint32_t local_38;
    uint32_t local_34;
    uint8_t local_2c[12];
    uint8_t local_20[12];
    uint8_t local_14[12];
    int local_8;
    int local_4;

    local_3c = param_3;
    local_38 = param_4;
    local_8 = 0;
    local_4 = 0;
    local_40 = param_2;
    local_34 = param_5;
    // NEEDS_MANUAL: the supplied listing shows this call as `FUN_005a1280()`
    // with no recovered stack arguments; the call site is preserved literally.
    int iVar1 = static_cast<int>(FUN_005a1280());
    if (iVar1 == 0) {
        return 0;
    }
    *param_6 = 1;
    local_8 = static_cast<int>(base + 0x8c);
    local_4 = param_1 + 0x8c;
    FUN_005a8560(reinterpret_cast<float*>(local_2c), reinterpret_cast<float*>(local_20), self);
    FUN_005a8560(reinterpret_cast<float*>(local_2c), reinterpret_cast<float*>(local_14), self);
    uint32_t uVar2 = FUN_005a2990(reinterpret_cast<int*>(&local_40));
    return uVar2;
}

// ---------------------------------------------------------------------------
// 0x5a15a0
// ---------------------------------------------------------------------------
// Refreshes both objects' cached frame reference (index 0x22), validates the
// pair via FUN_005a4c20, then walks the two children at +0x80/+0x84 through
// vtable slot +8, one level deeper, keeping slot +4 as the "already done" test.
// 0x5a15a0 — observed shape
int FUN_005a15a0(void* self, int* param_1, int param_2, int param_3, uint32_t param_4,
                 int param_5, int param_6, int param_7, uint32_t unaff_EBX,
                 uint32_t unaff_ESI, uint32_t unaff_EDI)
{
    typedef char (*VSlot4)(void*);
    typedef char (*VSlot8)(void*, int, int, uint32_t, int, int, int);
    int* s = reinterpret_cast<int*>(self);
    int* p = param_1;

    if (param_6 != s[0x22]) {
        FUN_005a4b20(param_2 + 0x6c, self);
        s[0x22] = param_6;
    }
    if (param_7 != p[0x22]) {
        FUN_005a4b20(param_3 + 0x6c, p);
        p[0x22] = param_7;
    }
    int iVar2 = static_cast<int>(FUN_005a4c20(reinterpret_cast<int>(p + 1), self));
    if (iVar2 == 0) {
        return 0;
    }
    void** vtblOther = *reinterpret_cast<void***>(p);
    VSlot4 slot4 = reinterpret_cast<VSlot4>(vtblOther[1]);
    char cVar1 = slot4(p);
    if ((cVar1 != '\0') || (param_5 == 0) || ((p[0x20] == 0) && (p[0x21] == 0))) {
        return 1;
    }
    iVar2 = param_7;
    void** vtblSelf = *reinterpret_cast<void***>(s);
    VSlot8 slot8 = reinterpret_cast<VSlot8>(vtblSelf[2]);
    cVar1 = slot8(s, p[0x20], param_2, param_3, param_4, param_5 - 1, param_6, param_7);
    if (cVar1 == '\0') {
        cVar1 = slot8(s, p[0x21], iVar2, static_cast<int>(unaff_EDI),
                      static_cast<int>(unaff_ESI), param_5 - 1, static_cast<int>(unaff_EBX), param_7);
        if (cVar1 == '\0') {
            return 0;
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x5a16a0
// ---------------------------------------------------------------------------
// Same pair refresh/validation as 0x5a15a0, then descends through vtable
// slot +0xc: either the two children directly, or the 0x5a2ad0 primitive, or
// 0x5a14f0 when both depth counters are negative.
// 0x5a16a0 — observed shape
uint32_t FUN_005a16a0(void* self, int* param_1, uint32_t param_2, uint32_t param_3,
                      int param_4, int param_5, int param_6, int param_7, int param_8,
                      int param_9, uint32_t param_10, uint32_t unaff_EBX,
                      uint32_t unaff_EBP, uint32_t unaff_EDI, uint32_t unaff_retaddr)
{
    typedef char (*VSlot4)(void*);
    typedef char (*VSlotC)(void*, int, uint32_t, uint32_t, uint32_t, uint32_t, int, int, int, int, uint32_t);
    int* s = reinterpret_cast<int*>(self);
    int* p = param_1;
    (void)unaff_EBP;
    (void)unaff_retaddr;

    if (param_8 != s[0x22]) {
        FUN_005a4b20(param_4 + 0x6c, self);
        s[0x22] = param_8;
    }
    if (param_9 != p[0x22]) {
        FUN_005a4b20(param_5 + 0x6c, p);
        p[0x22] = param_9;
    }
    int iVar2 = static_cast<int>(FUN_005a4c20(reinterpret_cast<int>(p + 1), self));
    if (iVar2 == 0) {
        return 0;
    }
    void** vtblOther = *reinterpret_cast<void***>(p);
    VSlot4 slot4 = reinterpret_cast<VSlot4>(vtblOther[1]);
    char cVar1 = slot4(p);
    uint32_t uVar3;
    if (cVar1 == '\0') {
        if ((param_7 == 0) || ((p[0x20] == 0) && (p[0x21] == 0))) {
            uVar3 = FUN_005a2ad0(self, reinterpret_cast<int>(p), param_2, param_3,
                                 static_cast<uint32_t>(param_4), static_cast<uint32_t>(param_5),
                                 reinterpret_cast<uint8_t*>(param_10));
            return uVar3;
        }
        param_7 = param_7 - 1;
        iVar2 = param_7;
        void** vtblSelf = *reinterpret_cast<void***>(s);
        VSlotC slotC = reinterpret_cast<VSlotC>(vtblSelf[3]);
        uVar3 = static_cast<uint32_t>(slotC(s, p[0x20], param_2, param_3,
                                            static_cast<uint32_t>(param_4),
                                            static_cast<uint32_t>(param_5), param_6, param_7,
                                            param_8, param_9, param_10));
        if (static_cast<int>(uVar3) < 1) {
            uVar3 = static_cast<uint32_t>(slotC(s, p[0x21], static_cast<uint32_t>(iVar2),
                                                static_cast<uint32_t>(param_8),
                                                static_cast<uint32_t>(param_9),
                                                static_cast<uint32_t>(param_5),
                                                static_cast<int>(unaff_EDI), param_7,
                                                static_cast<int>(unaff_EBP),
                                                static_cast<int>(unaff_EBX),
                                                unaff_retaddr));
            return uVar3 & (static_cast<uint32_t>(static_cast<int>(uVar3) < 1) - 1u);
        }
    } else {
        if ((param_6 < 0) && (param_7 < 0)) {
            uVar3 = FUN_005a14f0(self, reinterpret_cast<int>(p), param_2, param_3,
                                 static_cast<uint32_t>(param_4),
                                 static_cast<uint32_t>(param_5),
                                 reinterpret_cast<uint8_t*>(param_10));
            return uVar3;
        }
        uVar3 = FUN_005a2ad0(self, reinterpret_cast<int>(p), param_2, param_3,
                             static_cast<uint32_t>(param_4), static_cast<uint32_t>(param_5),
                             reinterpret_cast<uint8_t*>(param_10));
    }
    return uVar3;
}

// ---------------------------------------------------------------------------
// 0x5a1840
// ---------------------------------------------------------------------------
// Refreshes the cached frame reference at +0x88, evaluates FUN_0059ebe0 with
// the object's three +0x8c/+0x90/+0x94 vectors, stores the returned point into
// a fresh 0x44-byte object (plus the plane normal at +0x28..+0x30 when
// param_3+0x35 is set), and finally links the object at param_3+0x30.
// 0x5a1840 — observed shape
int FUN_005a1840(void* self, uint32_t param_1, uint32_t param_2, int param_3,
                 char* param_4, int param_5, uint32_t param_6)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    uint8_t local_2c[4];
    uint8_t local_28[4];
    float local_24, local_20, local_1c, local_18, local_14;
    uint32_t local_c, local_8, local_4;

    int iVar5 = static_cast<int>(param_6);
    int iVar6 = param_5;
    if (static_cast<int>(param_6) != *reinterpret_cast<int*>(base + 0x88)) {
        FUN_005a4b20(param_5 + 0x6c, self);
        *reinterpret_cast<int*>(base + 0x88) = iVar5;
    }
    param_6 = (param_6 & 0xffffff00u) | static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(param_3 + 0x10));
    char cVar4 = FUN_0059ebe0(param_1, param_2, *reinterpret_cast<uint32_t*>(base + 0x8c),
                              *reinterpret_cast<uint32_t*>(base + 0x90),
                              *reinterpret_cast<uint32_t*>(base + 0x94), param_6,
                              &local_c, &param_5, local_28, local_2c);
    *param_4 = cVar4;
    if (cVar4 != '\0') {
        iVar5 = static_cast<int>(reinterpret_cast<uintptr_t>(FUN_00533c78(0x44)));
        if (iVar5 == 0) {
            iVar6 = 0;
        } else {
            iVar6 = FUN_00594fa0(iVar6, self);
        }
        *reinterpret_cast<uint32_t*>(iVar6 + 8) = local_c;
        // The listing reads local_8/local_4 without assigning them.
        *reinterpret_cast<uint32_t*>(iVar6 + 0xc) = local_8;
        *reinterpret_cast<uint32_t*>(iVar6 + 0x10) = local_4;
        *reinterpret_cast<int*>(iVar6 + 0x14) = param_5;
        if (*reinterpret_cast<char*>(param_3 + 0x35) != '\0') {
            float* pfVar1 = *reinterpret_cast<float**>(base + 0x8c);
            float* pfVar2 = *reinterpret_cast<float**>(base + 0x90);
            float* pfVar3 = *reinterpret_cast<float**>(base + 0x94);
            local_18 = *pfVar3 - *pfVar1;
            local_14 = pfVar3[1] - pfVar1[1];
            local_24 = (pfVar3[2] - pfVar1[2]) * (pfVar2[1] - pfVar1[1]) -
                       local_14 * (pfVar2[2] - pfVar1[2]);
            local_20 = (pfVar2[2] - pfVar1[2]) * local_18 -
                       (pfVar3[2] - pfVar1[2]) * (*pfVar2 - *pfVar1);
            local_1c = local_14 * (*pfVar2 - *pfVar1) - local_18 * (pfVar2[1] - pfVar1[1]);
            FUN_00491640();
            *reinterpret_cast<float*>(iVar6 + 0x28) = local_24;
            *reinterpret_cast<float*>(iVar6 + 0x2c) = local_20;
            *reinterpret_cast<float*>(iVar6 + 0x30) = local_1c;
        }
        *reinterpret_cast<int*>(param_3 + 0x30) = iVar6;
        param_6 = static_cast<uint32_t>(iVar6);
        FUN_00571ce0(&param_6);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x5a19c0
// ---------------------------------------------------------------------------
// Destructor-style reset: installs the vtable at 0x6c51e8 and releases the two
// child objects at +0x80/+0x84 through their vtable slot 0 with argument 1.
// 0x5a19c0 — observed shape
void FUN_005a19c0(void* self)
{
    uint32_t* s = reinterpret_cast<uint32_t*>(self);
    *s = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c51e8));
    if (reinterpret_cast<void*>(s[0x20]) != nullptr) {
        void** obj20 = reinterpret_cast<void**>(static_cast<uintptr_t>(s[0x20]));
        void** vtbl20 = reinterpret_cast<void**>(*obj20);
        reinterpret_cast<void (*)(uint32_t)>(vtbl20[0])(1u);
        if (reinterpret_cast<void*>(s[0x21]) != nullptr) {
            void** obj21 = reinterpret_cast<void**>(static_cast<uintptr_t>(s[0x21]));
            void** vtbl21 = reinterpret_cast<void**>(*obj21);
            reinterpret_cast<void (*)(uint32_t)>(vtbl21[0])(1u);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x5a19f0
// ---------------------------------------------------------------------------
// Weighted centroid and 3x3 covariance accumulation over the triangle range
// param_6..param_7 of the index list param_8, written to self+4..+0xc and then
// expanded into the 9-float symmetric matrix copied to param_1.
// 0x5a19f0 — observed shape
void FUN_005a19f0(void* self, float* param_1, int param_2, int param_3, int param_4,
                  int param_5, uint32_t param_6, int param_7, int param_8)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    float* pfVar1;
    float* pfVar2;
    float* pfVar3;
    float* pfVar8;
    float fVar4, fVar5, fVar6, fVar7;
    int iVar9;
    float local_40 = 0.0f;
    float local_3c = 0.0f;
    float local_38 = 0.0f;
    float local_34 = 0.0f;
    float local_30 = 0.0f;
    float local_2c = 0.0f;
    float local_28 = 0.0f;
    float out[9];

    fVar5 = 0.0f;
    fVar7 = 0.0f;
    fVar6 = 0.0f;
    for (; static_cast<int>(param_6 & 0xffff) <= param_7; param_6 = param_6 + 1) {
        iVar9 = *reinterpret_cast<int*>(param_8 + static_cast<uintptr_t>(param_6 & 0xffff) * 4);
        pfVar1 = reinterpret_cast<float*>(param_3 +
                 static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(param_2 + 2 + (iVar9 * 3 + 1) * 2)) * 0xc);
        pfVar8 = reinterpret_cast<float*>(param_5 + static_cast<uintptr_t>(iVar9) * 0xc);
        pfVar2 = reinterpret_cast<float*>(param_3 +
                 static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(param_2 + 2 + iVar9 * 6)) * 0xc);
        fVar4 = *reinterpret_cast<float*>(param_4 + static_cast<uintptr_t>(iVar9) * 4);
        fVar6 = fVar4 + fVar6;
        pfVar3 = reinterpret_cast<float*>(param_3 +
                 static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(param_2 + iVar9 * 6)) * 0xc);
        fVar5 = fVar4 * *pfVar8 + fVar5;
        fVar7 = fVar4 * pfVar8[1] + fVar7;
        local_40 = fVar4 * pfVar8[2] + local_40;
        local_3c = (*pfVar8 * *pfVar8 + *pfVar3 * *pfVar3 + *pfVar1 * *pfVar1 + *pfVar2 * *pfVar2) *
                   fVar4 + local_3c;
        local_38 = (pfVar3[1] * *pfVar3 +
                    *pfVar2 * pfVar2[1] + pfVar8[1] * *pfVar8 + *pfVar1 * pfVar1[1]) * fVar4 + local_38;
        local_34 = (pfVar2[2] * *pfVar2 +
                    *pfVar1 * pfVar1[2] + *pfVar3 * pfVar3[2] + pfVar8[2] * *pfVar8) * fVar4 + local_34;
        local_30 = (pfVar1[1] * pfVar1[1] +
                    pfVar2[1] * pfVar2[1] + pfVar3[1] * pfVar3[1] + pfVar8[1] * pfVar8[1]) * fVar4 +
                    local_30;
        local_2c = (pfVar8[2] * pfVar8[1] +
                    pfVar3[1] * pfVar3[2] + pfVar2[2] * pfVar2[1] + pfVar1[2] * pfVar1[1]) * fVar4 +
                    local_2c;
        local_28 = (pfVar1[2] * pfVar1[2] +
                    pfVar2[2] * pfVar2[2] + pfVar3[2] * pfVar3[2] + pfVar8[2] * pfVar8[2]) * fVar4 +
                    local_28;
    }
    fVar6 = 1.0f / fVar6;
    float* pfS4 = reinterpret_cast<float*>(base + 4);
    fVar4 = fVar6 * 0.25f;
    *pfS4 = fVar5 * fVar6;
    *reinterpret_cast<float*>(base + 8) = fVar7 * fVar6;
    *reinterpret_cast<float*>(base + 0xc) = local_40 * fVar6;
    float m01 = fVar4 * local_38 - *pfS4 * *reinterpret_cast<float*>(base + 8);
    float m02 = fVar4 * local_34 - *reinterpret_cast<float*>(base + 0xc) * *pfS4;
    float m11 = fVar4 * local_30 - *reinterpret_cast<float*>(base + 8) * *reinterpret_cast<float*>(base + 8);
    float m12 = fVar4 * local_2c - *reinterpret_cast<float*>(base + 0xc) * *reinterpret_cast<float*>(base + 8);
    float m22 = fVar4 * local_28 - *reinterpret_cast<float*>(base + 0xc) * *reinterpret_cast<float*>(base + 0xc);
    // Stack order of the 9 copied floats (local_24[0..3], local_14, local_10,
    // local_c, local_8, local_4), with local_24[3] = local_24[1],
    // local_c = local_24[2], local_8 = local_10.
    out[0] = fVar4 * local_3c - *pfS4 * *pfS4;
    out[1] = m01;
    out[2] = m02;
    out[3] = m01;
    out[4] = m11;
    out[5] = m12;
    out[6] = m02;
    out[7] = m12;
    out[8] = m22;
    for (iVar9 = 0; iVar9 < 9; ++iVar9) {
        param_1[iVar9] = out[iVar9];
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x5a1d50
// ---------------------------------------------------------------------------
// Three-pass, four-way-unrolled plane partition of the index range
// param_2..param_3 against the three axes at self+0x14 (stride 3 floats) and
// the centroid at self+4. Front/back counters are left in *param_5/*param_6
// and the reordered indices are written through param_7 (int cast).
// 0x5a1d50 — observed shape
void FUN_005a1d50(void* self, int param_1, int param_2, int param_3, int param_4,
                  int* param_5, int* param_6, int* param_7)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    int iVar1;
    float fVar2;
    int* piVar3 = param_6;
    int iVar5 = (param_3 + param_2) / 2;
    int iVar6;
    int iVar4 = reinterpret_cast<int>(param_7);
    int local_8;
    int local_4 = 0;
    float* pfVar8 = reinterpret_cast<float*>(base + 0x14);

    *param_5 = param_2 - 1;
    *param_6 = param_3 + 1;
    do {
        if ((param_2 <= *param_5) && (*piVar3 <= param_3)) {
            break;
        }
        *param_5 = param_2 - 1;
        *piVar3 = param_3 + 1;
        param_6 = reinterpret_cast<int*>(static_cast<uintptr_t>(param_2));
        if (3 < (param_3 - param_2) + 1) {
            local_8 = param_2 + 2;
            param_7 = reinterpret_cast<int*>(static_cast<uintptr_t>(param_4) + static_cast<uintptr_t>(local_8) * 4);
            do {
                iVar1 = param_7[-2];
                iVar6 = param_1 + iVar1 * 0xc;
                fVar2 = (*reinterpret_cast<float*>(iVar6 + 4) - *reinterpret_cast<float*>(base + 8)) * *pfVar8 +
                        (*reinterpret_cast<float*>(param_1 + iVar1 * 0xc) - *reinterpret_cast<float*>(base + 4)) * pfVar8[-1] +
                        (*reinterpret_cast<float*>(iVar6 + 8) - *reinterpret_cast<float*>(base + 0xc)) * pfVar8[1];
                if (fVar2 <= 0.0f) {
                    if ((fVar2 < 0.0f) || (iVar5 < static_cast<int>(reinterpret_cast<uintptr_t>(param_6)))) {
                        iVar6 = *piVar3 - 1;
                        *piVar3 = iVar6;
                    } else {
                        iVar6 = *param_5 + 1;
                        *param_5 = iVar6;
                    }
                } else {
                    iVar6 = *param_5 + 1;
                    *param_5 = iVar6;
                }
                *reinterpret_cast<int*>(iVar4 + iVar6 * 4) = iVar1;

                iVar1 = param_7[-1];
                iVar6 = param_1 + iVar1 * 0xc;
                fVar2 = (*reinterpret_cast<float*>(iVar6 + 4) - *reinterpret_cast<float*>(base + 8)) * *pfVar8 +
                        (*reinterpret_cast<float*>(param_1 + iVar1 * 0xc) - *reinterpret_cast<float*>(base + 4)) * pfVar8[-1] +
                        (*reinterpret_cast<float*>(iVar6 + 8) - *reinterpret_cast<float*>(base + 0xc)) * pfVar8[1];
                if (fVar2 <= 0.0f) {
                    if ((fVar2 < 0.0f) || (iVar5 < local_8 - 1)) {
                        iVar6 = *piVar3 - 1;
                        *piVar3 = iVar6;
                    } else {
                        iVar6 = *param_5 + 1;
                        *param_5 = iVar6;
                    }
                } else {
                    iVar6 = *param_5 + 1;
                    *param_5 = iVar6;
                }
                *reinterpret_cast<int*>(iVar4 + iVar6 * 4) = iVar1;

                iVar1 = *param_7;
                iVar6 = param_1 + iVar1 * 0xc;
                fVar2 = (*reinterpret_cast<float*>(iVar6 + 4) - *reinterpret_cast<float*>(base + 8)) * *pfVar8 +
                        (*reinterpret_cast<float*>(param_1 + iVar1 * 0xc) - *reinterpret_cast<float*>(base + 4)) * pfVar8[-1] +
                        (*reinterpret_cast<float*>(iVar6 + 8) - *reinterpret_cast<float*>(base + 0xc)) * pfVar8[1];
                if (fVar2 <= 0.0f) {
                    if ((fVar2 < 0.0f) || (iVar5 < local_8)) {
                        iVar6 = *piVar3 - 1;
                        *piVar3 = iVar6;
                    } else {
                        iVar6 = *param_5 + 1;
                        *param_5 = iVar6;
                    }
                } else {
                    iVar6 = *param_5 + 1;
                    *param_5 = iVar6;
                }
                *reinterpret_cast<int*>(iVar4 + iVar6 * 4) = iVar1;

                iVar1 = param_7[1];
                iVar6 = param_1 + iVar1 * 0xc;
                fVar2 = (*reinterpret_cast<float*>(iVar6 + 4) - *reinterpret_cast<float*>(base + 8)) * *pfVar8 +
                        (*reinterpret_cast<float*>(param_1 + iVar1 * 0xc) - *reinterpret_cast<float*>(base + 4)) * pfVar8[-1] +
                        (*reinterpret_cast<float*>(iVar6 + 8) - *reinterpret_cast<float*>(base + 0xc)) * pfVar8[1];
                if (fVar2 <= 0.0f) {
                    if ((fVar2 < 0.0f) || (iVar5 < local_8 + 1)) {
                        iVar6 = *piVar3 - 1;
                        *piVar3 = iVar6;
                    } else {
                        iVar6 = *param_5 + 1;
                        *param_5 = iVar6;
                    }
                } else {
                    iVar6 = *param_5 + 1;
                    *param_5 = iVar6;
                }
                *reinterpret_cast<int*>(iVar4 + iVar6 * 4) = iVar1;

                param_7 = param_7 + 4;
                local_8 = local_8 + 4;
                param_6 = reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(param_6) + 4);
            } while (static_cast<int>(reinterpret_cast<uintptr_t>(param_6)) <= param_3 - 3);
        }
        for (; static_cast<int>(reinterpret_cast<uintptr_t>(param_6)) <= param_3;
             param_6 = reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(param_6) + 1)) {
            iVar1 = *reinterpret_cast<int*>(param_4 +
                     static_cast<uintptr_t>(static_cast<int>(reinterpret_cast<uintptr_t>(param_6))) * 4);
            iVar6 = param_1 + iVar1 * 0xc;
            fVar2 = (*reinterpret_cast<float*>(iVar6 + 4) - *reinterpret_cast<float*>(base + 8)) * *pfVar8 +
                    (*reinterpret_cast<float*>(param_1 + iVar1 * 0xc) - *reinterpret_cast<float*>(base + 4)) * pfVar8[-1] +
                    (*reinterpret_cast<float*>(iVar6 + 8) - *reinterpret_cast<float*>(base + 0xc)) * pfVar8[1];
            if (fVar2 <= 0.0f) {
                if ((fVar2 < 0.0f) || (iVar5 < static_cast<int>(reinterpret_cast<uintptr_t>(param_6)))) {
                    iVar6 = *piVar3 - 1;
                    *piVar3 = iVar6;
                } else {
                    iVar6 = *param_5 + 1;
                    *param_5 = iVar6;
                }
            } else {
                iVar6 = *param_5 + 1;
                *param_5 = iVar6;
            }
            *reinterpret_cast<int*>(iVar4 + iVar6 * 4) = iVar1;
        }
        local_4 = local_4 + 1;
        pfVar8 = pfVar8 + 3;
    } while (local_4 < 3);

    if ((local_4 == 3) && ((*param_5 < param_2) || (param_3 < *piVar3))) {
        *param_5 = iVar5;
        *piVar3 = iVar5 + 1;
        if (param_2 <= param_3) {
            uint32_t* puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar4) +
                                                           static_cast<uintptr_t>(param_2) * 4);
            iVar5 = (param_3 - param_2) + 1;
            do {
                *puVar7 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_4 - iVar4) +
                                                       static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(puVar7)));
                puVar7 = puVar7 + 1;
                iVar5 = iVar5 - 1;
            } while (iVar5 != 0);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x5a20e0
// ---------------------------------------------------------------------------
// Null-checked pair dispatch: refreshes both cached frame references,
// validates through FUN_005a4c20 and the two vtable slot +4 predicates, then
// tries four slot +8 combinations of the two child objects, or FUN_0059fcc0
// followed by two more slot +8 calls of self.
// 0x5a20e0 — observed shape
uint32_t FUN_005a20e0(void* self, int* param_1, int param_2, int param_3, int param_4,
                      int param_5, int param_6, int param_7, uint32_t unaff_EBX,
                      uint32_t unaff_ESI, uint32_t unaff_EDI)
{
    typedef char (*VSlot4)(void*);
    typedef char (*VSlot8)(void*, int, int, int, int, int, int, int);
    int* s = reinterpret_cast<int*>(self);
    int* p = param_1;

    if (p == nullptr) {
        return 0;
    }
    if (param_6 != s[0x22]) {
        FUN_005a4b20(param_2 + 0x6c, self);
        s[0x22] = param_6;
    }
    if (param_7 != p[0x22]) {
        FUN_005a4b20(param_3 + 0x6c, p);
        p[0x22] = param_7;
    }
    int iVar3 = static_cast<int>(FUN_005a4c20(reinterpret_cast<int>(p + 1), self));
    if (iVar3 == 0) {
        return 0;
    }
    if ((param_4 != 0) && (param_5 != 0)) {
        void** vtblSelf = *reinterpret_cast<void***>(s);
        void** vtblOther = *reinterpret_cast<void***>(p);
        VSlot4 selfSlot4 = reinterpret_cast<VSlot4>(vtblSelf[1]);
        char cVar2 = selfSlot4(s);
        if (cVar2 == '\0') {
            VSlot4 otherSlot4 = reinterpret_cast<VSlot4>(vtblOther[1]);
            cVar2 = otherSlot4(p);
            int* piVar1 = reinterpret_cast<int*>(static_cast<uintptr_t>(s[0x20]));
            if (cVar2 == '\0') {
                if (piVar1 == nullptr) {
                    return 1;
                }
                if (s[0x21] == 0) {
                    return 1;
                }
                param_4 = param_4 - 1;
                iVar3 = param_7;
                void** vtblChild20 = *reinterpret_cast<void***>(piVar1);
                VSlot8 slot8Child20 = reinterpret_cast<VSlot8>(vtblChild20[2]);
                cVar2 = slot8Child20(piVar1, p[0x20], param_2, param_3, param_4, param_5 - 1,
                                     param_6, param_7);
                if (cVar2 == '\0') {
                    int iVar5 = param_7;
                    VSlot8 slot8Child20b = reinterpret_cast<VSlot8>(vtblChild20[2]);
                    cVar2 = slot8Child20b(piVar1, p[0x21], iVar3, param_3, param_6,
                                          static_cast<int>(unaff_EBX), static_cast<int>(unaff_ESI),
                                          param_7);
                    if (cVar2 == '\0') {
                        int iVar4 = param_7;
                        int* child21 = reinterpret_cast<int*>(static_cast<uintptr_t>(s[0x21]));
                        void** vtblChild21 = *reinterpret_cast<void***>(child21);
                        VSlot8 slot8Child21a = reinterpret_cast<VSlot8>(vtblChild21[2]);
                        cVar2 = slot8Child21a(child21, p[0x20], iVar5, param_3,
                                              static_cast<int>(unaff_ESI), param_2, param_4, param_7);
                        if (cVar2 == '\0') {
                            VSlot8 slot8Child21b = reinterpret_cast<VSlot8>(vtblChild21[2]);
                            cVar2 = slot8Child21b(child21, p[0x21], iVar4, param_3, param_4, iVar3,
                                                  param_6, param_7);
                            if (cVar2 == '\0') {
                                return 0;
                            }
                        }
                    }
                }
            } else {
                if (piVar1 == nullptr) {
                    return 1;
                }
                if (s[0x21] == 0) {
                    return 1;
                }
                iVar3 = param_7;
                void** vtblChild20b = *reinterpret_cast<void***>(piVar1);
                VSlot8 slot8Child20c = reinterpret_cast<VSlot8>(vtblChild20b[2]);
                cVar2 = slot8Child20c(piVar1, static_cast<int>(reinterpret_cast<intptr_t>(p)),
                                      param_2, param_3, param_4 - 1, param_5, param_6, param_7);
                if (cVar2 == '\0') {
                    int* child21 = reinterpret_cast<int*>(static_cast<uintptr_t>(s[0x21]));
                    void** vtblChild21b = *reinterpret_cast<void***>(child21);
                    VSlot8 slot8Child21c = reinterpret_cast<VSlot8>(vtblChild21b[2]);
                    cVar2 = slot8Child21c(child21, static_cast<int>(reinterpret_cast<intptr_t>(p)),
                                          iVar3, param_3, static_cast<int>(unaff_EBX),
                                          static_cast<int>(unaff_EDI), static_cast<int>(unaff_ESI),
                                          param_7);
                    if (cVar2 == '\0') {
                        return 0;
                    }
                }
            }
            return 1;
        }
        VSlot4 otherSlot4b = reinterpret_cast<VSlot4>(vtblOther[1]);
        cVar2 = otherSlot4b(p);
        if ((cVar2 == '\0') && (cVar2 = static_cast<char>(FUN_0059fcc0(self)), cVar2 != '\0')) {
            iVar3 = param_7;
            VSlot8 slot8Self20 = reinterpret_cast<VSlot8>(vtblSelf[2]);
            cVar2 = slot8Self20(s, p[0x20], param_2, param_3, param_4, param_5 - 1, param_6, param_7);
            if (cVar2 != '\0') {
                return 1;
            }
            VSlot8 slot8Self21 = reinterpret_cast<VSlot8>(vtblSelf[2]);
            cVar2 = slot8Self21(s, p[0x21], iVar3, param_3, static_cast<int>(unaff_EBX),
                                static_cast<int>(unaff_EDI), static_cast<int>(unaff_ESI), param_7);
            if (cVar2 == '\0') {
                return 0;
            }
            return 1;
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x5a2380
// ---------------------------------------------------------------------------
// Refreshes the cached frame reference at +0x88, validates via FUN_005a86a0,
// then queries the optional children at +0x80 and +0x84 through vtable slot
// +0x10, returning the first positive result.
// 0x5a2380 — observed shape
int FUN_005a2380(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                 uint32_t param_4, int param_5, int param_6)
{
    typedef int (*VSlot10)(void*, uint32_t, uint32_t, uint32_t, uint32_t, int, int);
    uintptr_t base = reinterpret_cast<uintptr_t>(self);

    if (param_6 != *reinterpret_cast<int*>(base + 0x88)) {
        FUN_005a4b20(param_5 + 0x6c, self);
        *reinterpret_cast<int*>(base + 0x88) = param_6;
    }
    int iVar1 = FUN_005a86a0(param_1, param_2, self);
    if (iVar1 == 0) {
        return 0;
    }
    int* p80 = *reinterpret_cast<int**>(base + 0x80);
    if (p80 != nullptr) {
        void** vtbl80 = *reinterpret_cast<void***>(p80);
        VSlot10 slot10a = reinterpret_cast<VSlot10>(vtbl80[4]);
        iVar1 = slot10a(p80, param_1, param_2, param_3, param_4, param_5, param_6);
        if (0 < iVar1) {
            return iVar1;
        }
    }
    int* p84 = *reinterpret_cast<int**>(base + 0x84);
    if (p84 == nullptr) {
        return 0;
    }
    void** vtbl84 = *reinterpret_cast<void***>(p84);
    VSlot10 slot10b = reinterpret_cast<VSlot10>(vtbl84[4]);
    iVar1 = slot10b(p84, param_1, param_2, param_3, param_4, param_5, param_6);
    if (iVar1 < 1) {
        return 0;
    }
    return iVar1;
}

// ---------------------------------------------------------------------------
// 0x5a2430
// ---------------------------------------------------------------------------
// Builds the triangle-range statistics for param_6..param_7: computes the
// weighted centroid/covariance through 0x5a19f0, the basis through
// FUN_0053d8a0, then min/max over the three projection axes and writes the
// half-extents at +0x34/+0x38/+0x3c and the shifted center at +4/+8/+0xc.
// Ends by linking the source object at +0x7c and refreshing the frame.
// 0x5a2430 — observed shape
void FUN_005a2430(void* self, uint32_t param_1, int param_2, int param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, int param_7, int param_8)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    float* pfVar1 = reinterpret_cast<float*>(base + 4);
    float* pfVar2 = reinterpret_cast<float*>(base + 0x10);
    float* pfVar3;
    float* pfVar4;
    int iVar5;
    float fVar6, fVar7, fVar8, fVar9, fVar10, fVar11;
    float local_b0 = 0.0f;
    float local_ac = 0.0f;
    float local_a8 = 0.0f;
    float local_94 = 0.0f;
    float local_90 = 0.0f;
    uint8_t local_64[12];
    uint8_t local_58[36];
    uint8_t local_34[52];

    FUN_005a19f0(self, reinterpret_cast<float*>(local_58), param_2, param_3, param_4,
                 param_5, param_6, param_7, param_8);
    FUN_0053d8a0(local_64, pfVar2, self);
    fVar6 = 0.0f;
    for (; static_cast<int>(param_6 & 0xffff) <= param_7; param_6 = param_6 + 1) {
        iVar5 = *reinterpret_cast<int*>(param_8 + static_cast<uintptr_t>(param_6 & 0xffff) * 4);
        pfVar3 = reinterpret_cast<float*>(param_3 +
                 static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(param_2 + iVar5 * 6)) * 0xc);
        fVar7 = *pfVar3 - *pfVar1;
        fVar8 = pfVar3[1] - *reinterpret_cast<float*>(base + 8);
        pfVar4 = reinterpret_cast<float*>(param_3 +
                 static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(param_2 + 2 + (iVar5 * 3 + 1) * 2)) * 0xc);
        fVar9 = pfVar3[2] - *reinterpret_cast<float*>(base + 0xc);
        pfVar3 = reinterpret_cast<float*>(param_3 +
                 static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(param_2 + 2 + iVar5 * 6)) * 0xc);
        fVar10 = fVar9 * *reinterpret_cast<float*>(base + 0x18) +
                 fVar8 * *reinterpret_cast<float*>(base + 0x14) + fVar7 * *pfVar2;
        fVar11 = fVar7 * *reinterpret_cast<float*>(base + 0x1c) +
                 fVar9 * *reinterpret_cast<float*>(base + 0x24) +
                 fVar8 * *reinterpret_cast<float*>(base + 0x20);
        fVar7 = fVar7 * *reinterpret_cast<float*>(base + 0x28) +
                fVar9 * *reinterpret_cast<float*>(base + 0x30) +
                fVar8 * *reinterpret_cast<float*>(base + 0x2c);
        if (local_b0 <= fVar10) {
            if (local_94 < fVar10) {
                local_94 = fVar10;
            }
        } else {
            local_b0 = fVar10;
        }
        if (local_ac <= fVar11) {
            if (local_90 < fVar11) {
                local_90 = fVar11;
            }
        } else {
            local_ac = fVar11;
        }
        if (local_a8 <= fVar7) {
            if (fVar6 < fVar7) {
                fVar6 = fVar7;
            }
        } else {
            local_a8 = fVar7;
        }

        fVar7 = *pfVar3 - *pfVar1;
        fVar8 = pfVar3[1] - *reinterpret_cast<float*>(base + 8);
        fVar9 = pfVar3[2] - *reinterpret_cast<float*>(base + 0xc);
        fVar10 = fVar9 * *reinterpret_cast<float*>(base + 0x18) +
                 fVar8 * *reinterpret_cast<float*>(base + 0x14) + fVar7 * *pfVar2;
        fVar11 = fVar7 * *reinterpret_cast<float*>(base + 0x1c) +
                 fVar9 * *reinterpret_cast<float*>(base + 0x24) +
                 fVar8 * *reinterpret_cast<float*>(base + 0x20);
        fVar7 = fVar7 * *reinterpret_cast<float*>(base + 0x28) +
                fVar9 * *reinterpret_cast<float*>(base + 0x30) +
                fVar8 * *reinterpret_cast<float*>(base + 0x2c);
        if (local_b0 <= fVar10) {
            if (local_94 < fVar10) {
                local_94 = fVar10;
            }
        } else {
            local_b0 = fVar10;
        }
        if (local_ac <= fVar11) {
            if (local_90 < fVar11) {
                local_90 = fVar11;
            }
        } else {
            local_ac = fVar11;
        }
        if (local_a8 <= fVar7) {
            if (fVar6 < fVar7) {
                fVar6 = fVar7;
            }
        } else {
            local_a8 = fVar7;
        }

        fVar7 = *pfVar4 - *pfVar1;
        fVar8 = pfVar4[1] - *reinterpret_cast<float*>(base + 8);
        fVar9 = pfVar4[2] - *reinterpret_cast<float*>(base + 0xc);
        fVar10 = fVar9 * *reinterpret_cast<float*>(base + 0x18) +
                 fVar8 * *reinterpret_cast<float*>(base + 0x14) + fVar7 * *pfVar2;
        fVar11 = fVar7 * *reinterpret_cast<float*>(base + 0x1c) +
                 fVar9 * *reinterpret_cast<float*>(base + 0x24) +
                 fVar8 * *reinterpret_cast<float*>(base + 0x20);
        fVar7 = fVar7 * *reinterpret_cast<float*>(base + 0x28) +
                fVar9 * *reinterpret_cast<float*>(base + 0x30) +
                fVar8 * *reinterpret_cast<float*>(base + 0x2c);
        if (local_b0 <= fVar10) {
            if (local_94 < fVar10) {
                local_94 = fVar10;
            }
        } else {
            local_b0 = fVar10;
        }
        if (local_ac <= fVar11) {
            if (local_90 < fVar11) {
                local_90 = fVar11;
            }
        } else {
            local_ac = fVar11;
        }
        if (local_a8 <= fVar7) {
            if (fVar6 < fVar7) {
                fVar6 = fVar7;
            }
        } else {
            local_a8 = fVar7;
        }
    }
    *reinterpret_cast<float*>(base + 0x3c) = (fVar6 - local_a8) * 0.5f;
    *reinterpret_cast<float*>(base + 0x34) = (local_94 - local_b0) * 0.5f;
    *reinterpret_cast<float*>(base + 0x38) = (local_90 - local_ac) * 0.5f;
    fVar7 = (local_94 + local_b0) * 0.5f;
    fVar8 = (local_90 + local_ac) * 0.5f;
    fVar6 = (fVar6 + local_a8) * 0.5f;
    *pfVar1 = fVar7 * *pfVar2 + fVar8 * *reinterpret_cast<float*>(base + 0x1c) +
              fVar6 * *reinterpret_cast<float*>(base + 0x28) + *pfVar1;
    *reinterpret_cast<float*>(base + 8) =
        fVar7 * *reinterpret_cast<float*>(base + 0x14) + fVar8 * *reinterpret_cast<float*>(base + 0x20) +
        fVar6 * *reinterpret_cast<float*>(base + 0x2c) + *reinterpret_cast<float*>(base + 8);
    *reinterpret_cast<float*>(base + 0xc) =
        fVar7 * *reinterpret_cast<float*>(base + 0x18) + fVar8 * *reinterpret_cast<float*>(base + 0x24) +
        fVar6 * *reinterpret_cast<float*>(base + 0x30) + *reinterpret_cast<float*>(base + 0xc);
    FUN_00557990(self);
    FUN_005a4b20(static_cast<int>(reinterpret_cast<uintptr_t>(local_34)), self);
    *reinterpret_cast<uint32_t*>(base + 0x7c) = param_1;
    return;
}

// ---------------------------------------------------------------------------
// 0x5a2990
// ---------------------------------------------------------------------------
// Two-pass refcount/dispatch helper over the 14-dword descriptor param_1:
// each pass fetches the +0xb0 payload (possibly through the sibling at
// param_1[2]/param_1[3]), decrements its refcount, runs slot +0x3c, and the
// second pass swaps the first six descriptor dword pairs before the same call.
// 0x5a2990 — observed shape
uint32_t FUN_005a2990(int* param_1)
{
    int iVar3, iVar4, iVar5 = 0;
    int local_10 = 0;
    uint32_t* puVar6;

    if (*param_1 != 0) {
        puVar6 = *reinterpret_cast<uint32_t**>(static_cast<uintptr_t>(*param_1) + 0xb0);
        if (puVar6 == nullptr) {
            puVar6 = *reinterpret_cast<uint32_t**>(static_cast<uintptr_t>(param_1[2]) + 0xb0);
        }
        if (puVar6 != nullptr) {
            puVar6[1] = puVar6[1] + 1;
            uint32_t* piVar1 = puVar6 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                void** vtbl = *reinterpret_cast<void***>(puVar6);
                reinterpret_cast<void (*)(uint32_t)>(vtbl[0])(1u);
            }
            void* slot3c = reinterpret_cast<void*>(static_cast<uintptr_t>(puVar6[0xf]));
            if (slot3c != nullptr) {
                local_10 = reinterpret_cast<int (*)(int*)>(slot3c)(param_1);
            }
        }
    }
    if (param_1[1] != 0) {
        puVar6 = *reinterpret_cast<uint32_t**>(static_cast<uintptr_t>(param_1[1]) + 0xb0);
        if (puVar6 == nullptr) {
            puVar6 = *reinterpret_cast<uint32_t**>(static_cast<uintptr_t>(param_1[3]) + 0xb0);
        }
        if (puVar6 != nullptr) {
            puVar6[1] = puVar6[1] + 1;
            uint32_t* piVar1 = puVar6 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                void** vtbl = *reinterpret_cast<void***>(puVar6);
                reinterpret_cast<void (*)(uint32_t)>(vtbl[0])(1u);
            }
            int (*pcVar2)(int*) = reinterpret_cast<int (*)(int*)>(
                reinterpret_cast<void*>(static_cast<uintptr_t>(puVar6[0xf])));
            if (pcVar2 != nullptr) {
                iVar5 = *param_1;
                *param_1 = param_1[1];
                param_1[1] = iVar5;
                iVar5 = param_1[8];
                iVar3 = param_1[9];
                iVar4 = param_1[10];
                param_1[8] = param_1[0xb];
                param_1[0xb] = iVar5;
                param_1[9] = param_1[0xc];
                param_1[0xc] = iVar3;
                param_1[10] = param_1[0xd];
                param_1[0xd] = iVar4;
                iVar5 = pcVar2(param_1);
            }
        }
    }
    if (local_10 == 0) {
        if (iVar5 == 0) {
            return 0;
        }
    } else if (local_10 == 2) {
        return 2;
    }
    if (iVar5 == 2) {
        return 2;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x5a2ad0
// ---------------------------------------------------------------------------
// Distance primitive between two objects: when both +0x7c sub-structures sit
// at the 0x727430 sentinel triple it uses the midpoint of the two +0x40
// vectors, otherwise it asks FUN_005a57f0 for the closest pair. Results are
// handed to the 0x5a2990 dispatcher through a 5-dword descriptor.
// 0x5a2ad0 — observed shape
uint32_t FUN_005a2ad0(void* self, int param_1, uint32_t param_2, uint32_t param_3,
                      uint32_t param_4, uint32_t param_5, uint8_t* param_6)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    uint32_t local_40;
    uint32_t local_3c;
    uint32_t local_38;
    uint32_t local_34;
    uint32_t local_30;
    float local_2c, local_28, local_24;
    uint8_t local_20[12];
    uint8_t local_14[12];
    int local_8;
    int local_4;

    local_40 = param_2;
    local_34 = param_5;
    local_8 = 0;
    local_4 = 0;
    local_3c = param_3;
    local_38 = param_4;
    int iVar2 = *reinterpret_cast<int*>(base + 0x7c);
    int iVar1 = *reinterpret_cast<int*>(static_cast<uintptr_t>(param_1) + 0x7c);
    if ((((*reinterpret_cast<float*>(iVar2 + 0x10) == DAT_00727430) &&
          (*reinterpret_cast<float*>(iVar2 + 0x14) == DAT_00727434)) &&
         (*reinterpret_cast<float*>(iVar2 + 0x18) == DAT_00727438)) &&
        (((*reinterpret_cast<float*>(iVar1 + 0x10) == DAT_00727430) &&
          (*reinterpret_cast<float*>(iVar1 + 0x14) == DAT_00727434)) &&
         (*reinterpret_cast<float*>(iVar1 + 0x18) == DAT_00727438))) {
        local_30 = 0;
        local_2c = (*reinterpret_cast<float*>(static_cast<uintptr_t>(param_1) + 0x40) +
                    *reinterpret_cast<float*>(base + 0x40)) * 0.5f;
        local_28 = (*reinterpret_cast<float*>(static_cast<uintptr_t>(param_1) + 0x44) +
                    *reinterpret_cast<float*>(base + 0x44)) * 0.5f;
        local_24 = (*reinterpret_cast<float*>(static_cast<uintptr_t>(param_1) + 0x48) +
                    *reinterpret_cast<float*>(base + 0x48)) * 0.5f;
    } else {
        iVar2 = static_cast<int>(FUN_005a57f0(param_1 + 4, &local_30, &local_2c, self));
        if (iVar2 == 0) {
            return 0;
        }
    }
    *param_6 = 1;
    FUN_005a8560(&local_2c, reinterpret_cast<float*>(local_20), self);
    FUN_005a8560(&local_2c, reinterpret_cast<float*>(local_14), self);
    uint32_t uVar3 = FUN_005a2990(reinterpret_cast<int*>(&local_40));
    return uVar3;
}

// ---------------------------------------------------------------------------
// 0x5a2f40
// ---------------------------------------------------------------------------
// Recursive BVH builder: seeds the current node with 0x5a2430, partitions the
// index range through 0x5a1d50, and either recurses into the +0x80 child,
// creates a leaf at +0x80 when the split lands on the boundary, or links the
// +0x84 child and continues iteratively down the left branch.
// 0x5a2f40 — observed shape
void FUN_005a2f40(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5, uint32_t param_6, int param_7,
                  int param_8, int param_9, int param_10, int param_11)
{
    uint32_t* cur = reinterpret_cast<uint32_t*>(self);
    uint32_t* puVar8 = cur;
    int iVar2 = param_9;
    int iVar7 = param_8;
    int iVar3 = param_7;
    uint32_t uVar4;
    int iVar6;

    FUN_005a2430(self, param_1, static_cast<int>(param_2), static_cast<int>(param_3),
                 param_5, param_6, param_7, param_8, param_9);
    if (param_11 <= iVar7 - iVar3) {
        iVar7 = param_10;
        puVar8 = cur;
        do {
            iVar6 = iVar2;
            FUN_005a1d50(puVar8, static_cast<int>(param_6), iVar3, param_8, iVar6,
                         &param_9, &param_7, reinterpret_cast<int*>(static_cast<uintptr_t>(iVar7)));
            if (iVar3 < param_9) {
                uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x8c));
                uint32_t* puVar5 = nullptr;
                if (puVar1 != nullptr) {
                    *puVar1 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c51e8));
                    puVar1[0x1f] = 0;
                    puVar1[0x20] = 0;
                    puVar1[0x21] = 0;
                    puVar1[0x22] = 0;
                    puVar5 = puVar1;
                }
                puVar8[0x20] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar5));
                FUN_005a2f40(puVar5, param_1, param_2, param_3, param_4, param_5, param_6,
                             iVar3, param_9, iVar7, iVar6, param_11);
            } else if (iVar3 == param_9) {
                iVar2 = static_cast<int>(reinterpret_cast<uintptr_t>(FUN_00533c78(0x98)));
                if (iVar2 == 0) {
                    uVar4 = 0;
                } else {
                    uVar4 = FUN_0059fce0(param_1, param_2, param_3, param_4,
                                         *reinterpret_cast<uint16_t*>(
                                             static_cast<uintptr_t>(iVar7) +
                                             static_cast<uintptr_t>(iVar3) * 4),
                                         puVar8);
                }
                puVar8[0x20] = uVar4;
            }
            iVar3 = param_7;
            if (param_8 <= param_7) {
                if (param_7 == param_8) {
                    iVar3 = static_cast<int>(reinterpret_cast<uintptr_t>(FUN_00533c78(0x98)));
                    if (iVar3 != 0) {
                        uVar4 = FUN_0059fce0(param_1, param_2, param_3, param_4,
                                             *reinterpret_cast<uint16_t*>(
                                                 static_cast<uintptr_t>(iVar7) +
                                                 static_cast<uintptr_t>(param_8) * 4),
                                             puVar8);
                        puVar8[0x21] = uVar4;
                        return;
                    }
                    puVar8[0x21] = 0;
                }
                return;
            }
            cur = reinterpret_cast<uint32_t*>(FUN_00533c78(0x8c));
            if (cur == nullptr) {
                cur = nullptr;
            } else {
                *cur = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c51e8));
                cur[0x1f] = 0;
                cur[0x20] = 0;
                cur[0x21] = 0;
                cur[0x22] = 0;
            }
            puVar8[0x21] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(cur));
            FUN_005a2430(cur, param_1, static_cast<int>(param_2), static_cast<int>(param_3),
                         param_5, param_6, static_cast<uint32_t>(iVar3), param_8, iVar7);
            iVar2 = iVar7;
            iVar7 = iVar6;
            puVar8 = cur;
        } while (param_11 <= param_8 - param_7);
    }
    cur[0x20] = 0;
    cur[0x21] = 0;
    return;
}

// ---------------------------------------------------------------------------
// 0x5a3150
// ---------------------------------------------------------------------------
// Builds the BVH root for param_2 triangles: allocates the per-triangle area
// and centroid arrays, fills them from the index and vertex arrays, builds the
// identity index list plus the scratch order buffer, and calls 0x5a2f40.
// 0x5a3150 — observed shape
uint32_t* FUN_005a3150(void* self, uint32_t param_1, uint16_t param_2, uint32_t param_3,
                       float* param_4, uint32_t param_5, uint32_t param_6)
{
    uint32_t* s = reinterpret_cast<uint32_t*>(self);
    float *pfVar1, *pfVar2, *pfVar3;
    float fVar4, fVar5, fVar6, fVar7, fVar8, fVar9;
    int iVar11 = reinterpret_cast<int>(param_4);
    int iVar10 = static_cast<int>(param_3);
    uint32_t uVar17 = static_cast<uint32_t>(param_2);
    uint32_t uVar18 = 0;
    int iVar15;
    void* pvVar14;
    void* pvVar16;

    *s = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c51e8));
    s[0x1f] = 0;
    float* pfVar12 = reinterpret_cast<float*>(thunk_FUN_00533c78(uVar17 * 4));
    float* pfVar13 = reinterpret_cast<float*>(thunk_FUN_00533c78(uVar17 * 0xc));
    if (param_2 != 0) {
        float* pTriArea = pfVar12;
        uint32_t count = uVar17;
        float* pCentroid = pfVar13;
        do {
            pfVar1 = reinterpret_cast<float*>(iVar11 +
                     static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(iVar10 + ((uVar18 + 1) & 0xffff) * 2)) * 0xc);
            pfVar2 = reinterpret_cast<float*>(iVar11 +
                     static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(iVar10 + (uVar18 & 0xffff) * 2)) * 0xc);
            pfVar3 = reinterpret_cast<float*>(iVar11 +
                     static_cast<uintptr_t>(*reinterpret_cast<uint16_t*>(iVar10 + ((uVar18 + 2) & 0xffff) * 2)) * 0xc);
            uVar18 = uVar18 + 3;
            fVar5 = (pfVar3[2] - pfVar2[2]) * (pfVar1[1] - pfVar2[1]) -
                    (pfVar3[1] - pfVar2[1]) * (pfVar1[2] - pfVar2[2]);
            fVar6 = (pfVar1[2] - pfVar2[2]) * (*pfVar3 - *pfVar2) -
                    (pfVar3[2] - pfVar2[2]) * (*pfVar1 - *pfVar2);
            fVar4 = (pfVar3[1] - pfVar2[1]) * (*pfVar1 - *pfVar2) -
                    (pfVar1[1] - pfVar2[1]) * (*pfVar3 - *pfVar2);
            *pTriArea = std::sqrt(fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4) * 0.5f;
            fVar4 = pfVar1[1];
            fVar5 = pfVar2[1];
            fVar6 = pfVar1[2];
            fVar7 = pfVar2[2];
            fVar8 = pfVar3[1];
            fVar9 = pfVar3[2];
            *pCentroid = (*pfVar1 + *pfVar2 + *pfVar3) * 0.33333334f;
            pCentroid[1] = (fVar4 + fVar5 + fVar8) * 0.33333334f;
            pTriArea = pTriArea + 1;
            count = count - 1;
            pCentroid[2] = (fVar6 + fVar7 + fVar9) * 0.33333334f;
            pCentroid = pCentroid + 3;
        } while (count != 0);
    }
    pvVar14 = thunk_FUN_00533c78(uVar17 * 4);
    iVar15 = 0;
    if (uVar17 != 0) {
        do {
            *reinterpret_cast<int*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(pvVar14)) +
                                    static_cast<uintptr_t>(iVar15) * 4) = iVar15;
            iVar15 = iVar15 + 1;
        } while (iVar15 < static_cast<int>(uVar17));
    }
    pvVar16 = thunk_FUN_00533c78(uVar17 * 4);
    FUN_005a2f40(s, param_1, iVar10, iVar11, param_5,
                 static_cast<uint32_t>(reinterpret_cast<uintptr_t>(pfVar12)),
                 static_cast<uint32_t>(reinterpret_cast<uintptr_t>(pfVar13)),
                 0, static_cast<int>(uVar17 - 1),
                 static_cast<int>(reinterpret_cast<uintptr_t>(pvVar14)),
                 static_cast<int>(reinterpret_cast<uintptr_t>(pvVar16)), param_6);
    operator_delete__(pvVar16);
    operator_delete__(pvVar14);
    operator_delete__(pfVar13);
    operator_delete__(pfVar12);
    s[0x22] = 0;
    return s;
}

// ---------------------------------------------------------------------------
// 0x5a3390
// ---------------------------------------------------------------------------
// Ordered min/max of param_1 against the pair (param_2, param_3) without any
// comparison branches on NaNs beyond the listing's shape.
// 0x5a3390 — observed shape
void FUN_005a3390(float param_1, float param_2, float param_3, float* param_4, float* param_5)
{
    float fVar1;

    if (param_3 < param_2) {
        if (param_1 <= param_3) {
            *param_4 = param_1;
            *param_5 = param_2;
            return;
        }
        fVar1 = param_3;
        if (param_1 <= param_2) {
            *param_4 = param_3;
            *param_5 = param_2;
            return;
        }
    } else {
        if (param_1 <= param_2) {
            *param_4 = param_1;
            *param_5 = param_3;
            return;
        }
        fVar1 = param_2;
        if (param_1 <= param_3) {
            *param_4 = param_2;
            *param_5 = param_3;
            return;
        }
    }
    *param_4 = fVar1;
    *param_5 = param_1;
    return;
}

// ---------------------------------------------------------------------------
// 0x5a3450
// ---------------------------------------------------------------------------
// Interval predicate: compares the pair (param_3, param_2) or the half-open
// window against param_1, advancing param_4/param_3 by param_5 times the
// threshold at +0x22c, and packs the three comparison flags plus a low byte 1.
// 0x5a3450 — observed shape
uint16_t FUN_005a3450(void* self, float param_1, float param_2, float param_3,
                      float param_4, float param_5)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    uint16_t uVar1;

    if (param_3 <= param_2) {
        uVar1 = static_cast<uint16_t>(
                    static_cast<uint16_t>(param_4 < param_1) << 8 |
                    static_cast<uint16_t>(std::isnan(param_4) || std::isnan(param_1)) << 10 |
                    static_cast<uint16_t>(param_4 == param_1) << 0xe);
        if (param_4 < param_1) {
            param_4 = param_5 * *reinterpret_cast<float*>(base + 0x22c) + param_4;
            uVar1 = static_cast<uint16_t>(
                        static_cast<uint16_t>(param_4 < param_1) << 8 |
                        static_cast<uint16_t>(std::isnan(param_4) || std::isnan(param_1)) << 10 |
                        static_cast<uint16_t>(param_4 == param_1) << 0xe);
            if (param_4 < param_1) {
                return uVar1;
            }
        }
    } else {
        param_3 = param_5 * *reinterpret_cast<float*>(base + 0x22c) + param_3;
        uVar1 = static_cast<uint16_t>(
                    static_cast<uint16_t>(param_3 < param_2) << 8 |
                    static_cast<uint16_t>(std::isnan(param_3) || std::isnan(param_2)) << 10 |
                    static_cast<uint16_t>(param_3 == param_2) << 0xe);
        if (param_3 >= param_2 && (param_3 == param_2) == 0) {
            return uVar1;
        }
    }
    return static_cast<uint16_t>((static_cast<uint16_t>(uVar1 >> 8) << 8) | 1u);
}

// ---------------------------------------------------------------------------
// 0x5a34b0
// ---------------------------------------------------------------------------
// Recomputes the +0x80/+0xa4/+0x114 spans from the +0x7c/-0x78,
// +0xa0/-0x9c and +0x110/-0x10c pairs, folds the negated +0x114 span and the
// +0x1a8 threshold into the ordered pair, and forwards both to 0x5a3450.
// 0x5a34b0 — observed shape
void FUN_005a34b0(void* self)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    float local_14, local_10, local_c, local_8;

    float fVar1 = *reinterpret_cast<float*>(base + 0x7c) - *reinterpret_cast<float*>(base + 0x78);
    float fVar2 = *reinterpret_cast<float*>(base + 0xa0) - *reinterpret_cast<float*>(base + 0x9c);
    *reinterpret_cast<float*>(base + 0x80) = fVar1;
    *reinterpret_cast<float*>(base + 0xa4) = fVar2;
    float fVar3 = *reinterpret_cast<float*>(base + 0x110) - *reinterpret_cast<float*>(base + 0x10c);
    *reinterpret_cast<float*>(base + 0x114) = fVar3;
    fVar3 = -fVar3;
    if (fVar3 < 0.0f) {
        local_c = 0.0f;
        local_8 = fVar3;
    } else {
        local_8 = 0.0f;
        local_c = fVar3;
    }
    local_10 = fVar1 - *reinterpret_cast<float*>(base + 0x1a8);
    if (local_10 < fVar1) {
        local_14 = fVar1;
    } else {
        local_14 = local_10;
        local_10 = fVar1;
    }
    FUN_005a3450(self, local_8, local_c, local_10, local_14, fVar2);
    return;
}

// ---------------------------------------------------------------------------
// 0x5a3570
// ---------------------------------------------------------------------------
// Same span refresh as 0x5a34b0 for the +0x88/-0x84, +0xac/-0xa8 and +0x114
// fields, folding the +0x1ac threshold before forwarding to 0x5a3450.
// 0x5a3570 — observed shape
void FUN_005a3570(void* self)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    float local_14, local_10, local_c, local_8;

    float fVar2 = *reinterpret_cast<float*>(base + 0x88) - *reinterpret_cast<float*>(base + 0x84);
    float fVar3 = *reinterpret_cast<float*>(base + 0xac) - *reinterpret_cast<float*>(base + 0xa8);
    *reinterpret_cast<float*>(base + 0x8c) = fVar2;
    *reinterpret_cast<float*>(base + 0xb0) = fVar3;
    float fVar1 = *reinterpret_cast<float*>(base + 0x114);
    if (fVar1 < 0.0f) {
        local_c = 0.0f;
        local_8 = fVar1;
    } else {
        local_8 = 0.0f;
        local_c = fVar1;
    }
    local_10 = fVar2 - *reinterpret_cast<float*>(base + 0x1ac);
    if (local_10 < fVar2) {
        local_14 = fVar2;
    } else {
        local_14 = local_10;
        local_10 = fVar2;
    }
    FUN_005a3450(self, local_8, local_c, local_10, local_14, fVar3);
    return;
}

// ---------------------------------------------------------------------------
// 0x5a3620
// ---------------------------------------------------------------------------
// Recomputes the +0x90/+0xb4/+0x1b0 spans from +0x84/-0x78, +0xa8/-0x9c and
// +0x1ac/-0x1a8, then forwards the +0x10c value and the folded span to
// 0x5a3450.
// 0x5a3620 — observed shape
void FUN_005a3620(void* self)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    float local_14, local_10, local_c, local_8;

    float fVar2 = *reinterpret_cast<float*>(base + 0x84) - *reinterpret_cast<float*>(base + 0x78);
    float fVar3 = *reinterpret_cast<float*>(base + 0xa8) - *reinterpret_cast<float*>(base + 0x9c);
    *reinterpret_cast<float*>(base + 0x90) = fVar2;
    *reinterpret_cast<float*>(base + 0xb4) = fVar3;
    local_10 = *reinterpret_cast<float*>(base + 0x1ac) - *reinterpret_cast<float*>(base + 0x1a8);
    *reinterpret_cast<float*>(base + 0x1b0) = local_10;
    float fVar1 = *reinterpret_cast<float*>(base + 0x10c);
    if (fVar1 < 0.0f) {
        local_c = 0.0f;
        local_8 = fVar1;
    } else {
        local_8 = 0.0f;
        local_c = fVar1;
    }
    local_10 = local_10 + fVar2;
    if (local_10 < fVar2) {
        local_14 = fVar2;
    } else {
        local_14 = local_10;
        local_10 = fVar2;
    }
    FUN_005a3450(self, local_8, local_c, local_10, local_14, fVar3);
    return;
}
