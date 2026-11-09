#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers (declared extern; addresses taken from the listings)
// ---------------------------------------------------------------------------
extern uint32_t DAT_00728c30;
extern uint32_t DAT_00728c38;
extern uint32_t DAT_00728c40;
extern uint32_t DAT_00728c48;
extern uint32_t DAT_00728c50;

extern uint32_t DAT_007177ac;
extern uint32_t DAT_007177b0;
extern uint32_t DAT_007177b4;

extern uint32_t PTR_FUN_006c66b4;
extern uint32_t PTR_FUN_006c6740;
extern uint32_t PTR_FUN_006c6830;

// Dispatch tables of function pointers used by the class methods below.
extern uint32_t (*DAT_007286c8[])(void*, void*);
extern void (*DAT_00728650[])(void*, uint32_t, int32_t);
extern uint32_t (*DAT_00728920[])(void*, uint32_t);
extern void (*DAT_007283f8[])(uint32_t, uint32_t);

extern void FUN_005383d0();
extern void FUN_00538410(void*, void*);
extern void FUN_00538430(void*);
extern uint32_t FUN_00538460(void*);
extern void FUN_00538630(void*);
extern void FUN_004127b0(void* dst, uint32_t elemSize, uint32_t count, void* ctor);
extern void FUN_005416e0(uint16_t count, void* a, void* b, void* c, uint32_t d, uint32_t e, uint32_t f);
extern void FUN_00548b20(void* dst, void* src);
extern void FUN_005579c0(void* dst);
extern void FUN_00557b10(uint32_t id);
extern void FUN_00559020();
extern void FUN_00559050(void* ptr);
extern void FUN_00559070(void* ptr);
extern void FUN_00559090(void* ptr);
extern void FUN_005590b0(uint32_t index);
extern void FUN_005592d0();
extern uint32_t FUN_005593c0(void*);
extern void FUN_005606f0(uint32_t index, void* out);
extern void FUN_00576640(int a, uint32_t b, uint32_t* c, void* d, uint32_t e, uint32_t f);
extern void FUN_00577d90(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_00582800(void*);
extern void FUN_00582840(void*);
extern void FUN_00582880(void* dst, void* src, uint32_t a, uint32_t b);
extern uint32_t FUN_005bbd20();
extern void FUN_005bbee0(void*);
extern uint32_t FUN_005bd490(void*);
extern uint32_t FUN_005bd640(int32_t record);
extern uint8_t FUN_005bd960(void*, void*);
extern void FUN_005bd4f0();
extern void FUN_006b34a0(int32_t value);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void operator_delete__(void* ptr);

typedef void (*StreamReadFn)(void* buf, uint32_t size);
typedef void (*VSlotU32Fn)(uint32_t value);

extern void LAB_005cea70();
extern void LAB_004b1250();

namespace {

void copy_dwords(void* dst, const void* src, uint32_t dwords)
{
    uint32_t* d = static_cast<uint32_t*>(dst);
    const uint32_t* s = static_cast<const uint32_t*>(src);
    for (uint32_t i = 0; i < dwords; ++i) {
        d[i] = s[i];
    }
}

} // namespace

// 0x5b7b70 — observed shape
// Serializes one value: base-class serialize on param_1, fetch the id from
// DAT_00728c30, then store the current element count and the slot at +0x14.
void FUN_005b7b70(void* param_1)
{
    uint8_t* p = static_cast<uint8_t*>(param_1);
    uint32_t local = 0;

    FUN_005bd490(param_1);
    local = FUN_00557b10(DAT_00728c30);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(p + 0xc);
    if (*reinterpret_cast<uint32_t*>(p + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(p + 0x14) + static_cast<int32_t>(uVar1));
    }
    FUN_005606f0(uVar1, &local);
}

// 0x5b7c80 — observed shape
// Same serializer shape as FUN_005b7b70, using the id from DAT_00728c38.
void FUN_005b7c80(void* param_1)
{
    uint8_t* p = static_cast<uint8_t*>(param_1);
    uint32_t local = 0;

    FUN_005bd490(param_1);
    local = FUN_00557b10(DAT_00728c38);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(p + 0xc);
    if (*reinterpret_cast<uint32_t*>(p + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(p + 0x14) + static_cast<int32_t>(uVar1));
    }
    FUN_005606f0(uVar1, &local);
}

// 0x5b7d80 — observed shape
// Same serializer shape as FUN_005b7b70, using the id from DAT_00728c40.
void FUN_005b7d80(void* param_1)
{
    uint8_t* p = static_cast<uint8_t*>(param_1);
    uint32_t local = 0;

    FUN_005bd490(param_1);
    local = FUN_00557b10(DAT_00728c40);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(p + 0xc);
    if (*reinterpret_cast<uint32_t*>(p + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(p + 0x14) + static_cast<int32_t>(uVar1));
    }
    FUN_005606f0(uVar1, &local);
}

// 0x5b7ee0 — observed shape
// Same serializer shape as FUN_005b7b70, using the id from DAT_00728c48.
void FUN_005b7ee0(void* param_1)
{
    uint8_t* p = static_cast<uint8_t*>(param_1);
    uint32_t local = 0;

    FUN_005bd490(param_1);
    local = FUN_00557b10(DAT_00728c48);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(p + 0xc);
    if (*reinterpret_cast<uint32_t*>(p + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(p + 0x14) + static_cast<int32_t>(uVar1));
    }
    FUN_005606f0(uVar1, &local);
}

// 0x5b7fe0 — observed shape
// Same serializer shape as FUN_005b7b70, using the id from DAT_00728c50.
void FUN_005b7fe0(void* param_1)
{
    uint8_t* p = static_cast<uint8_t*>(param_1);
    uint32_t local = 0;

    FUN_005bd490(param_1);
    local = FUN_00557b10(DAT_00728c50);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(p + 0xc);
    if (*reinterpret_cast<uint32_t*>(p + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(p + 0x14) + static_cast<int32_t>(uVar1));
    }
    FUN_005606f0(uVar1, &local);
}

// 0x5b8030 — observed shape
// Constructor: runs the base initializer, then installs the vtable at
// PTR_FUN_006c66b4 and stores the five arguments into the +0xc..+0x1c block.
void FUN_005b8030(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5)
{
    uint32_t* s = static_cast<uint32_t*>(self);

    FUN_005383d0(); // base constructor; the receiver is passed implicitly in ECX
    s[3] = param_1;
    s[4] = param_2;
    s[6] = param_4;
    *s = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c66b4));
    s[5] = param_3;
    s[7] = param_5;
}

// 0x5b8070 — observed shape
// If the element count at +0xc is non-zero, hands the buffer at +0x14 and the
// capacity at +0x10 to FUN_00576640; then forwards to FUN_00582880 when the
// trailer block at +0x18 is populated.
void FUN_005b8070(void* self, uint32_t param_1, uint32_t param_2)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint32_t uVar1 = param_2;

    if (*reinterpret_cast<int32_t*>(s + 0xc) != 0) {
        param_2 = *reinterpret_cast<uint32_t*>(s + 0x10);
        FUN_00576640(0, *reinterpret_cast<uint32_t*>(s + 0x14), &param_2, s + 0xc,
                     param_1, uVar1);
        *reinterpret_cast<uint32_t*>(s + 0x10) = param_2;
    }
    if (*reinterpret_cast<int32_t*>(s + 0x18) != 0) {
        FUN_00582880(s + 0x1c, s + 0x18, param_1, uVar1);
    }
}

// 0x5b8120 — observed shape
// Equality test against param_1: base compare first, then header fields at
// +0xc/+0x14/+0x18, then per-element compare through the DAT_007286c8 table
// and a stride-8 {float key, char tag} compare. Returns (mask | 1) on match
// and (value & 0xffffff00) on the first mismatch.
uint32_t FUN_005b8120(void* self, void* param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint8_t* p = static_cast<uint8_t*>(param_1);

    uint32_t uVar4 = FUN_00538460(param_1);
    if (static_cast<int8_t>(uVar4) == '\0') {
        return uVar4;
    }
    // Short-circuit shape preserved: the value masked into a failure return is
    // the one produced by whichever clause failed.
    if (*reinterpret_cast<int32_t*>(p + 0xc) != *reinterpret_cast<int32_t*>(s + 0xc)) {
        return uVar4 & 0xffffff00u;
    }
    uVar4 = *reinterpret_cast<uint32_t*>(s + 0x14);
    if (*reinterpret_cast<uint32_t*>(p + 0x14) != uVar4) {
        return uVar4 & 0xffffff00u;
    }
    if (*reinterpret_cast<int32_t*>(p + 0x18) != *reinterpret_cast<int32_t*>(s + 0x18)) {
        return uVar4 & 0xffffff00u;
    }

    uint32_t (*cmpFn)(void*, void*) = DAT_007286c8[uVar4];
    if (*reinterpret_cast<int32_t*>(s + 0xc) != 0) {
        uint32_t idx = 0;
        for (;;) {
            int32_t baseA = *reinterpret_cast<int32_t*>(p + 0x10);
            int32_t baseB = *reinterpret_cast<int32_t*>(s + 0x10);
            uint8_t strideA = *reinterpret_cast<uint8_t*>(baseA + 4);
            uint8_t strideB = *reinterpret_cast<uint8_t*>(baseB + 4);
            void* elemA = reinterpret_cast<void*>(baseA + strideA * idx);
            void* elemB = reinterpret_cast<void*>(baseB + strideB * idx);

            uint32_t cmpRes = cmpFn(elemA, elemB);
            if (static_cast<int8_t>(cmpRes) == '\0') {
                return cmpRes & 0xffffff00u;
            }
            ++idx;
            if (!(idx < *reinterpret_cast<uint32_t*>(s + 0xc))) {
                break;
            }
        }
    }

    uint32_t idx2 = 0;
    if (*reinterpret_cast<uint32_t*>(s + 0x18) != 0) {
        int32_t baseP = *reinterpret_cast<int32_t*>(p + 0x1c);
        int32_t baseS = *reinterpret_cast<int32_t*>(s + 0x1c);
        do {
            float fSelf = *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(baseS) + idx2 * 8);
            float fOther =
                *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(baseP) + idx2 * 8);
            if (fOther != fSelf) {
                return uVar4 & 0xffffff00u;
            }
            uint8_t tagSelf = reinterpret_cast<uint8_t*>(baseS)[idx2 * 8 + 4];
            uint8_t tagOther = reinterpret_cast<uint8_t*>(baseP)[idx2 * 8 + 4];
            if (tagOther != tagSelf) {
                return uVar4 & 0xffffff00u;
            }
            ++idx2;
        } while (idx2 < *reinterpret_cast<uint32_t*>(s + 0x18));
    }
    return (uVar4 & 0xffffff00u) | 1u;
}

// 0x5b81f0 — observed shape
// Stream deserializer. Reads a dword; when non-zero, reads one more dword,
// dispatches through DAT_00728920/DAT_007283f8 indexed by in_ESI, then calls
// FUN_00577d90. A second dword controls a count of records that are read into
// a freshly allocated block of count*8 bytes, replacing the +0x18/+0x1c pair.
// The listing aliases these three stack dwords onto overlapping slots
// (param_1, iStack_4, auStack_6 and unaff_EDI), so they are modelled here as
// three distinct locals; the register inputs remain explicit parameters.
void FUN_005b81f0(void* self, void* param_1, uint32_t in_ESI, uint32_t in_EBX,
                  uint32_t in_EDI)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint8_t* obj = static_cast<uint8_t*>(param_1);

    FUN_00538630(param_1);

    void** vtbl = *reinterpret_cast<void***>(*reinterpret_cast<void**>(obj + 0x15c));
    StreamReadFn read = reinterpret_cast<StreamReadFn>(vtbl[0x8 / 4]);

    uint32_t sizeA = 0;
    read(&sizeA, 4);

    if (sizeA != 0) {
        uint32_t skipped = 0;
        read(&skipped, 4);
        uint32_t uVar2 = DAT_00728920[in_ESI](obj, in_EBX);
        DAT_007283f8[in_ESI](uVar2, in_EBX);
        FUN_00577d90(uVar2, sizeA, in_ESI);
    }

    uint32_t count = 0;
    read(&count, 4);

    if (count != 0) {
        void* iVar3 = thunk_FUN_00533c78(count * 8);
        if (iVar3 == 0) {
            iVar3 = 0;
        } else {
            FUN_004127b0(iVar3, 8, count, reinterpret_cast<void*>(&LAB_005cea70));
        }
        uint32_t uVar4 = 0;
        if (count != 0) {
            do {
                FUN_00582800(obj);
                ++uVar4;
            } while (uVar4 < count);
        }
        operator_delete__(*reinterpret_cast<void**>(s + 0x1c));
        if (iVar3 != 0 && count != 0) {
            *reinterpret_cast<uint32_t*>(s + 0x18) = count;
            *reinterpret_cast<void**>(s + 0x1c) = iVar3;
            return;
        }
        *reinterpret_cast<uint32_t*>(s + 0x18) = 0;
        *reinterpret_cast<uint32_t*>(s + 0x1c) = 0;
    }
}

// 0x5b8320 — observed shape
// Stream loader for the +0xc/+0x14/+0x10 block and the +0x18;
// elements are rebuilt through FUN_00582840.
void FUN_005b8320(void* self, void* param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint8_t* p = static_cast<uint8_t*>(param_1);

    FUN_00538430(param_1);

    int32_t* piVar1 = reinterpret_cast<int32_t*>(s + 0xc);
    void** vtbl = *reinterpret_cast<void***>(*reinterpret_cast<void**>(p + 0x160));
    StreamReadFn read = reinterpret_cast<StreamReadFn>(vtbl[0xc / 4]);

    read(piVar1, 4);
    if (*piVar1 != 0) {
        read(s + 0x14, 4);
        DAT_00728650[*reinterpret_cast<int32_t*>(s + 0x14)](
            p, *reinterpret_cast<uint32_t*>(s + 0x10), *piVar1);
    }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(s + 0x18);
    read(puVar2, 4);
    uint32_t uVar3 = 0;
    if (*puVar2 != 0) {
        do {
            FUN_00582840(p);
            ++uVar3;
        } while (uVar3 < *puVar2);
    }
}

// 0x5b8520 — observed shape
// Constructor: base initializer at FUN_005bbd20, vtable PTR_FUN_006c6740, then
// zero/limit defaults (0x3d4ccccd == 0.05f, 0x7f7fffff == FLT_MAX) and the three
// globals at DAT_007177ac/b0/b4.
void FUN_005b8520(void* self)
{
    uint32_t* s = static_cast<uint32_t*>(self);

    FUN_005bbd20(); // base constructor; the receiver is passed implicitly in ECX
    *s = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c6740));
    s[7] = 0;
    s[8] = DAT_007177ac;
    s[9] = DAT_007177b0;
    s[10] = DAT_007177b4;
    s[0xb] = 0x3d4ccccdu; // 0.05f
    s[0xc] = 0x7f7fffffu; // FLT_MAX
    s[0xd] = 0x7f7fffffu; // FLT_MAX
}

// 0x5b8b50 — observed shape
// Decays every 0x28-byte record's leading vector by
// 1 - (param_1 - record->interval) * self->decay, for the record count at
// param_2 + 0x44 (the record array lives at param_2 + 0x50).
void FUN_005b8b50(void* self, float param_1, void* param_2)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint8_t* p = static_cast<uint8_t*>(param_2);

    uint16_t uVar3 = 0;
    if (*reinterpret_cast<int16_t*>(p + 0x44) != 0) {
        do {
            float* pfVar1 = reinterpret_cast<float*>(
                *reinterpret_cast<int32_t*>(p + 0x50) + static_cast<uint32_t>(uVar3) * 0x28);
            ++uVar3;
            float fVar2 =
                1.0f - (param_1 - pfVar1[8]) * *reinterpret_cast<float*>(s + 0x20);
            pfVar1[0] = fVar2 * pfVar1[0];
            pfVar1[1] = fVar2 * pfVar1[1];
            pfVar1[2] = fVar2 * pfVar1[2];
        } while (uVar3 < *reinterpret_cast<uint16_t*>(p + 0x44));
    }
}

// 0x5b8c20 — observed shape
// Copies the +0x1c pointer of the source when the nested serializer accepts it,
// otherwise keeps the receiver's value.
void FUN_005b8c20(void* self, void* param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);

    FUN_005bbee0(param_1);
    FUN_005bd960(s, &param_1);
    uint8_t* iVar1 = static_cast<uint8_t*>(param_1);

    if (*reinterpret_cast<int32_t*>(s + 0x1c) != 0) {
        uint8_t cVar2 =
            FUN_005bd960(*reinterpret_cast<int32_t*>(s + 0x1c), &param_1);
        if (cVar2 != '\0') {
            *reinterpret_cast<uint32_t*>(iVar1 + 0x1c) =
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
            return;
        }
        *reinterpret_cast<uint32_t*>(iVar1 + 0x1c) =
            *reinterpret_cast<uint32_t*>(s + 0x1c);
    }
}

// 0x5b8c80 — observed shape
// Distance-falloff pass: snapshots the two 13-dword transform blocks at
// self->[0x1c]+0x6c and self->[0x14]+0x6c, builds the local transforms, then
// scales each record's leading vector when its interval differs from param_1
// and the record position lies within self->radius_sq.
void FUN_005b8c80(void* self, float param_1, void* param_2)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint8_t* p = static_cast<uint8_t*>(param_2);

    // 0x30-byte transform output; the listing splits it as local_d0[36] plus
    // the three trailing floats local_ac/local_a8/local_a4.
    uint8_t local_d0[48];
    uint32_t local_9c[13];
    uint32_t local_68[13];
    uint8_t local_34[52];

    uint32_t* puVar6 = reinterpret_cast<uint32_t*>(
        *reinterpret_cast<int32_t*>(s + 0x1c) + 0x6c);
    for (int32_t iVar5 = 0xd; iVar5 != 0; --iVar5) {
        local_9c[0xd - iVar5] = *puVar6++;
    }
    puVar6 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(s + 0x14) + 0x6c);
    for (int32_t iVar5 = 0xd; iVar5 != 0; --iVar5) {
        local_68[0xd - iVar5] = *puVar6++;
    }

    FUN_005579c0(local_34);
    FUN_00548b20(local_d0, local_9c);

    float* transform = reinterpret_cast<float*>(local_d0);
    float local_ac = transform[9];
    float local_a8 = transform[10];
    float local_a4 = transform[11];

    uint16_t uVar7 = 0;
    if (*reinterpret_cast<int16_t*>(p + 0x44) != 0) {
        do {
            float* pfVar1 = reinterpret_cast<float*>(
                *reinterpret_cast<int32_t*>(p + 0x50) + static_cast<uint32_t>(uVar7) * 0x28);
            if (param_1 - pfVar1[8] != 0.0f) {
                float* pfVar2 = reinterpret_cast<float*>(
                    *reinterpret_cast<int32_t*>(p + 0x20) +
                    static_cast<uint32_t>(uVar7) * 0xc);
                float fVar4 = (*pfVar2 - local_ac) * (*pfVar2 - local_ac) +
                              (pfVar2[1] - local_a8) * (pfVar2[1] - local_a8) +
                              (pfVar2[2] - local_a4) * (pfVar2[2] - local_a4);
                float fVar3 = *reinterpret_cast<float*>(s + 0x30);
                if (fVar4 < fVar3) {
                    fVar3 = 1.0f - (param_1 - pfVar1[8]) *
                                       *reinterpret_cast<float*>(s + 0x20);
                    pfVar1[0] = fVar3 * pfVar1[0];
                    pfVar1[1] = fVar3 * pfVar1[1];
                    pfVar1[2] = fVar3 * pfVar1[2];
                }
            }
            ++uVar7;
        } while (uVar7 < *reinterpret_cast<uint16_t*>(p + 0x44));
    }
}

// 0x5b9200 — observed shape
// Constructor: base initializer at FUN_005592d0, vtable PTR_FUN_006c6830, then
// clears the +0x50 dword and the +0x54/+0x56 words.
void FUN_005b9200(void* self)
{
    uint8_t* s = static_cast<uint8_t*>(self);

    FUN_005592d0(); // base constructor; the receiver is passed implicitly in ECX
    *reinterpret_cast<uint32_t*>(s + 0x50) = 0;
    *reinterpret_cast<uint16_t*>(s + 0x54) = 0;
    *reinterpret_cast<uint16_t*>(s + 0x56) = 0;
    *reinterpret_cast<uint32_t*>(s) =
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c6830));
}

// 0x5b9220 — observed shape
// Destructor: installs vtable PTR_FUN_006c6830, frees the +0x50 pointer and
// runs the base teardown at FUN_00559020.
void FUN_005b9220(void* self)
{
    uint32_t* s = static_cast<uint32_t*>(self);

    *s = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c6830));
    operator_delete__(reinterpret_cast<void*>(s[0x14]));
    FUN_00559020(); // base destructor; the receiver is passed implicitly in ECX
}

// 0x5b9240 — observed shape
// Copies the last 0x28-byte record onto slot param_1 after FUN_005590b0
// adjusts the record count.
void FUN_005b9240(void* self, uint32_t param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);

    int16_t sVar1 = *reinterpret_cast<int16_t*>(s + 0x44);
    FUN_005590b0(param_1);
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(
        *reinterpret_cast<int32_t*>(s + 0x50) +
        static_cast<uint32_t>(static_cast<uint16_t>(sVar1 - 1)) * 0x28);
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(
        *reinterpret_cast<int32_t*>(s + 0x50) + (param_1 & 0xffffu) * 0x28);
    for (int iVar2 = 10; iVar2 != 0; --iVar2) {
        *puVar4 = *puVar3;
        ++puVar3;
        ++puVar4;
    }
}

// 0x5b9280 — observed shape
// Normalizes the +0x44 count against the pending count at +0x56, growing the
// count by the +0x54 delta and invoking vtable slot 0x40 for every element not
// yet materialized; ends by collapsing +0x54 to zero and syncing +0x56.
void FUN_005b9280(void* self)
{
    uint8_t* s = static_cast<uint8_t*>(self);

    uint16_t uVar2 = *reinterpret_cast<uint16_t*>(s + 0x56);
    uint16_t uVar1 = *reinterpret_cast<uint16_t*>(s + 0x44);
    uint32_t uVar3 = uVar1;

    if (uVar1 < uVar2) {
        *reinterpret_cast<uint16_t*>(s + 0x44) = static_cast<uint16_t>(
            *reinterpret_cast<uint16_t*>(s + 0x54) + uVar2);
        if (uVar1 < uVar2) {
            do {
                if (*reinterpret_cast<uint16_t*>(s + 0x44) <=
                    *reinterpret_cast<uint16_t*>(s + 0x56)) {
                    break;
                }
                void** vtbl = *reinterpret_cast<void***>(s);
                reinterpret_cast<VSlotU32Fn>(vtbl[0x40 / 4])(uVar3);
                ++uVar3;
            } while (static_cast<uint16_t>(uVar3) <
                     *reinterpret_cast<uint16_t*>(s + 0x56));
        }
        uVar2 = static_cast<uint16_t>(uVar3);
        if (uVar2 < *reinterpret_cast<uint16_t*>(s + 0x56)) {
            *reinterpret_cast<uint16_t*>(s + 0x44) = uVar2;
            *reinterpret_cast<uint16_t*>(s + 0x54) = 0;
            *reinterpret_cast<uint16_t*>(s + 0x56) = uVar2;
            return;
        }
    } else {
        *reinterpret_cast<uint16_t*>(s + 0x44) = static_cast<uint16_t>(
            *reinterpret_cast<uint16_t*>(s + 0x54) + uVar1);
    }
    *reinterpret_cast<uint16_t*>(s + 0x54) = 0;
    *reinterpret_cast<int16_t*>(s + 0x56) = *reinterpret_cast<int16_t*>(s + 0x44);
}

// 0x5b9340 — observed shape
// Equality test: base compare, then every record at param_1+0x50 through
// FUN_005bd640, then the +0x54/+0x56 words. Returns (value & 0xffffff00) | 1
// on full match.
uint32_t FUN_005b9340(void* self, void* param_1)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint8_t* p = static_cast<uint8_t*>(param_1);

    uint32_t uVar1 = FUN_005593c0(param_1);
    if (static_cast<int8_t>(uVar1) == '\0') {
        return uVar1;
    }

    uint16_t uVar2 = 0;
    if (*reinterpret_cast<int16_t*>(s + 0x44) != 0) {
        do {
            uVar1 = FUN_005bd640(*reinterpret_cast<int32_t*>(p + 0x50) +
                                 static_cast<uint32_t>(uVar2) * 0x28);
            if (static_cast<int8_t>(uVar1) == '\0') {
                return uVar1 & 0xffffff00u;
            }
            ++uVar2;
        } while (uVar2 < *reinterpret_cast<uint16_t*>(s + 0x44));
    }
    if (*reinterpret_cast<int16_t*>(s + 0x54) ==
            *reinterpret_cast<int16_t*>(p + 0x54) &&
        *reinterpret_cast<int16_t*>(s + 0x56) ==
            *reinterpret_cast<int16_t*>(p + 0x56)) {
        return (uVar1 & 0xffffff00u) | 1u;
    }
    return uVar1 & 0xffffff00u;
}

// 0x5b9400 — observed shape
// Deep copy into param_1: clones the +0x20, +0x24 and +0x28 blocks (0xc, 0xc
// and 0x10 bytes per element), forwards them to FUN_005416e0, then installs
// clones of +0x4c, +0x48 and +0x40 and finally replaces the target's +0x50
// record array (0x28 bytes per element) with a copy of the receiver's, also
// copying the +0x44/+0x54/+0x56 header words.
void FUN_005b9400(void* self, void* param_1, void* param_2)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    uint8_t* p = static_cast<uint8_t*>(param_1);

    FUN_00538410(param_1, param_2);

    uint16_t n = *reinterpret_cast<uint16_t*>(s + 0xc);

    void* blockA = thunk_FUN_00533c78(static_cast<uint32_t>(n) * 0xc);
    copy_dwords(blockA, *reinterpret_cast<void**>(s + 0x20),
                (static_cast<uint32_t>(n) * 0xc) >> 2);

    void* blockB = 0;
    if (*reinterpret_cast<int32_t*>(s + 0x24) != 0) {
        blockB = thunk_FUN_00533c78(static_cast<uint32_t>(n) * 0xc);
        if (blockB == 0) {
            blockB = 0;
        } else {
            FUN_004127b0(blockB, 0xc, static_cast<uint32_t>(n),
                         reinterpret_cast<void*>(&LAB_005cea70));
        }
        copy_dwords(blockB, *reinterpret_cast<void**>(s + 0x24),
                    (static_cast<uint32_t>(n) * 0xc) >> 2);
    }

    void* blockC = 0;
    if (*reinterpret_cast<int32_t*>(s + 0x28) != 0) {
        blockC = thunk_FUN_00533c78(static_cast<uint32_t>(n) << 4);
        if (blockC == 0) {
            blockC = 0;
        } else {
            FUN_004127b0(blockC, 0x10, static_cast<uint32_t>(n),
                         reinterpret_cast<void*>(&LAB_004b1250));
        }
        copy_dwords(blockC, *reinterpret_cast<void**>(s + 0x28),
                    static_cast<uint32_t>(n) << 2);
    }

    FUN_005416e0(n, blockA, blockB, blockC, 0, 0, 0);

    void* blockD = 0;
    if (*reinterpret_cast<int32_t*>(s + 0x4c) != 0) {
        blockD = thunk_FUN_00533c78(static_cast<uint32_t>(n) << 4);
        if (blockD == 0) {
            blockD = 0;
        } else {
            FUN_004127b0(blockD, 0x10, static_cast<uint32_t>(n),
                         reinterpret_cast<void*>(&LAB_005cea70));
        }
        copy_dwords(blockD, *reinterpret_cast<void**>(s + 0x4c),
                    static_cast<uint32_t>(n) << 2);
    }
    FUN_00559090(blockD);

    void* blockE = thunk_FUN_00533c78(static_cast<uint32_t>(n) << 2);
    copy_dwords(blockE, *reinterpret_cast<void**>(s + 0x48), static_cast<uint32_t>(n));
    FUN_00559070(blockE);

    void* blockF = thunk_FUN_00533c78(static_cast<uint32_t>(n) << 2);
    copy_dwords(blockF, *reinterpret_cast<void**>(s + 0x40), static_cast<uint32_t>(n));
    FUN_00559050(blockF);

    *reinterpret_cast<uint16_t*>(p + 0x44) = *reinterpret_cast<uint16_t*>(s + 0x44);

    void* blockG = 0;
    if (*reinterpret_cast<int32_t*>(s + 0x50) != 0) {
        blockG = thunk_FUN_00533c78(static_cast<uint32_t>(n) * 0x28);
        if (blockG == 0) {
            blockG = 0;
        } else {
            FUN_004127b0(blockG, 0x28, static_cast<uint32_t>(n),
                         reinterpret_cast<void*>(&FUN_005bd4f0));
        }
        copy_dwords(blockG, *reinterpret_cast<void**>(s + 0x50),
                    (static_cast<uint32_t>(n) * 0x28) >> 2);
    }

    operator_delete__(*reinterpret_cast<void**>(p + 0x50));
    *reinterpret_cast<void**>(p + 0x50) = blockG;
    *reinterpret_cast<uint16_t*>(p + 0x54) = *reinterpret_cast<uint16_t*>(s + 0x54);
    *reinterpret_cast<uint16_t*>(p + 0x56) = *reinterpret_cast<uint16_t*>(s + 0x56);
}
