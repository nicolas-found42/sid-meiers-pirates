#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <windows.h>

// ---------------------------------------------------------------------------
// Reconstructed candidates for the mass_0047 batch.
// Every definition below is a translation of the corresponding Ghidra 12.2
// pseudocode listing in analysis/pseudocode/functions/. Registers that the
// decompiler kept implicit become explicit parameters named `..._in_REG`.
// ---------------------------------------------------------------------------

using float10 = long double;  // x87 80-bit return artifact from the listings

// --- external helpers observed in the listings -----------------------------
extern "C" DWORD timeGetTime(void);

extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);

extern uint32_t FUN_004b97c0(const char* format, ...);
extern uint8_t* FUN_00449390(void* table, uint32_t key);
extern void FUN_00510a60();
extern void FUN_004f5670();
extern void FUN_004f5720();
extern void FUN_005606f0(int mode, void** out);
extern void FUN_00542690(void* obj);
extern void FUN_004c3a50(void* obj);
extern void FUN_004f6090(const char* text);
extern void FUN_00412f10();
extern void FUN_00412df0(...);
extern void FUN_004cd0a0(uint8_t value);
extern void FUN_004cd170();
extern void FUN_004cd250();
extern void FUN_004cd2a0();
extern void FUN_004cd100(int flag);
extern void FUN_0045a050();
extern void FUN_00412b40();
extern void FUN_004b0b90(void* obj);
extern void FUN_00412840(uint32_t a, uint32_t b);
extern void FUN_004ae4f0();
extern void FUN_004b9650();
extern void FUN_004c8440();
extern void FUN_004c8a10();
extern void FUN_004c8070();
extern void FUN_004c8aa0(void* self);
extern void FUN_004c82b0();
extern void FUN_004c5770();
extern void FUN_004c8580();
extern void FUN_004c79c0(void* self, uint32_t value);
extern void FUN_004c84b0();
extern void FUN_0042c610();
extern void FUN_004b24a0(uint8_t* self, int flag);
extern void FUN_004d0cd0(int a, int b, int c);
extern void FUN_0051bfc0(void* out);
extern void FUN_004f32e0();
extern void FUN_004f3350();
extern void FUN_004f1840();
extern void FUN_00412f90();
extern int32_t FUN_004c73d0(uint32_t extra);
extern void FUN_004c7520(uint32_t value, uint32_t* self);
extern void FUN_004c78b0(uint32_t value, uint8_t** self);
extern void FUN_004ccb10();
extern void FUN_004ccf60();
extern void FUN_004c4640();
extern void FUN_00509500(uint8_t* dst, uint8_t* src, int mode);
extern void FUN_004b06c0(uint8_t* text, int x, int y, int a, int b, int c, int d, int e);
extern void FUN_004bbc80(int a, uint32_t b, int c, int d, uint32_t e, int f, int g);
extern void FUN_004bba60(int obj, uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern void FUN_004bdca0(uint32_t a, int b, int c, uint32_t d, int e, int f, int g, int h, int i);

extern uint32_t FUN_005f0ddc(...);
extern uintptr_t FUN_004c7fd0();
extern uint32_t FUN_00503840();
extern uint32_t FUN_0042e1d0(void* name);
extern uint32_t FUN_004b2760(int mode);
extern void* FUN_00533c78(...);
extern void* thunk_FUN_00533c78(size_t size);
extern void* FUN_004c3eb0(uint32_t param_1, int* out, uint32_t extra);
extern void* FUN_004c42e0(uint32_t param_1, void** out);
extern char FUN_004c6e90(uint32_t self, uint8_t* text, char** cursor, char** next,
                         int* flag, int* position);

// --- translated functions used before their definitions --------------------
void FUN_004c3000(void* self_in_EAX = nullptr, uint32_t* param_in_EBX = nullptr,
                  uint32_t* obj_in_EDI = nullptr);
void FUN_004c5fa0(void* self_in_EAX = nullptr);

// --- globals / statics observed in the listings ----------------------------
extern uint8_t PTR_FUN_0070d01c;
extern uint8_t PTR_FUN_0070d02c;
extern uint8_t PTR_FUN_0070d030;
extern uint8_t PTR_FUN_006f5814;
extern uint8_t PTR_FUN_0070d8e0;
extern uint8_t PTR_FUN_0070d918;
extern uint8_t PTR_FUN_00704c70;
extern uint8_t PTR_FUN_0070d8dc;
extern uint8_t PTR_FUN_006fd14c;

extern uint8_t DAT_008cacd0;
extern int32_t DAT_008caccc;
extern uint8_t DAT_008cacc8;
extern volatile LONG DAT_008cabfc;
extern uint8_t DAT_007278d4;
extern uint32_t DAT_00727444;
extern uint32_t DAT_008c95a0[];
extern uint32_t DAT_008c95b0[];
extern uint8_t DAT_008c9578[];
extern uint8_t* PTR_DAT_00726640;
extern uint32_t _DAT_008cac10;
extern int32_t DAT_008cac18;
extern int32_t DAT_008cac1c;
extern uint8_t* DAT_008cabe8;
extern uint32_t DAT_008dc310;
extern uint32_t DAT_008dc30c;
extern uint32_t DAT_0086bb5c;
extern char DAT_006f588c[];
extern uint8_t DAT_008cac27;
extern uint8_t* DAT_008c9dd8;
extern uint8_t* DAT_008c9de0;
extern uint32_t DAT_0085a11c;
extern int32_t DAT_00726380;
extern uint32_t DAT_0072637c;
extern uint32_t DAT_007263bc;
extern uint8_t DAT_007268f4[];
extern int32_t DAT_00726a84;
extern uint32_t DAT_008ea008;
extern int32_t DAT_0086c330;
extern uint32_t DAT_008c95dc;
extern uint32_t DAT_008c95d8;
extern uint32_t DAT_008ed61c;
extern int32_t DAT_008ed618;

// Observed ref-counted-object virtual dispatch `(**(code **)*obj)(arg)`.
static void call_vtbl0(uint32_t* obj, uint32_t arg)
{
    void* vtbl = *reinterpret_cast<void**>(obj);
    reinterpret_cast<void (*)(uint32_t*, uint32_t)>(
        *reinterpret_cast<void**>(vtbl))(obj, arg);
}

// Observed release pattern: decrement the counter at obj[1]; at zero invoke
// the first virtual slot with the listing's argument.
static void release_refcounted(uint32_t* obj, uint32_t arg)
{
    int32_t* refcount = reinterpret_cast<int32_t*>(obj + 1);
    *refcount = *refcount + -1;
    if (*refcount == 0) {
        call_vtbl0(obj, arg);
    }
}

// Observed string-buffer release: the allocated block precedes the stored
// character pointer by 8 bytes; the shifted static empty-buffer sentinel is
// skipped rather than freed.
static void release_shifted_buffer(void* stored)
{
    uint8_t* shifted = reinterpret_cast<uint8_t*>(stored) - 8;
    if (shifted != nullptr && shifted != &DAT_008cacc8) {
        operator_delete__(shifted);
    }
}

// ---------------------------------------------------------------------------
// 0x4c2e40 — observed shape
// Scalar deleting destructor: installs the vtable pointer marker, releases the
// ref-counted object referenced from +0x8, and deletes the receiver when bit 0
// of param_1 is set.
// ---------------------------------------------------------------------------
void FUN_004c2e40(void* self_in_ECX, uint8_t param_1)
{
    uint32_t* self = reinterpret_cast<uint32_t*>(self_in_ECX);

    self[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_0070d01c));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self[2]);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
    }
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x4c2e80 — observed shape
// Destroys the object referenced from +0x10 through its first virtual slot and
// clears the field.
// ---------------------------------------------------------------------------
void FUN_004c2e80(void* self_in_ECX)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self_in_ECX);

    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 0x10);
    if (puVar2 != nullptr) {
        call_vtbl0(puVar2, 1);
        *reinterpret_cast<uint32_t*>(base + 0x10) = 0;
    }
}

// ---------------------------------------------------------------------------
// 0x4c2ea0 — observed shape
// Scalar deleting destructor for a background-load object: swaps the vtable
// marker, decrements/reports the global loaded-object counter, restores the
// base marker, then releases +0x8 and deletes on bit 0 of param_1.
// ---------------------------------------------------------------------------
void FUN_004c2ea0(void* self_in_ECX, uint8_t param_1)
{
    uint32_t* self = reinterpret_cast<uint32_t*>(self_in_ECX);

    self[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_0070d030));
    InterlockedDecrement(&DAT_008cabfc);
    FUN_004b97c0("Num Background Loaded Objects Remaining = %u", DAT_008cabfc);
    self[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_0070d01c));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self[2]);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
    }
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x4c2f00 — observed shape
// Reads the count pair at the container root (count +8, capacity +0xc),
// initialises the stream helpers, attaches param_2's object through virtual
// slot +0x70 with the argument 1, then releases the temporary reference.
// ---------------------------------------------------------------------------
void FUN_004c2f00(int* param_1, int* param_2)
{
    // NEEDS_MANUAL: FUN_004c3000 consumes ambient EAX/EBX/EDI registers that
    // the listing does not expose at this call site.
    FUN_004c3000();

    uint32_t* root = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*param_1));
    if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(root) + 8) <=
        *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(root) + 0xc)) {
        FUN_004f5670();
    }
    FUN_004f5720();

    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*param_2));
    uint32_t* piVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1[1]));
    if (puVar1 != nullptr) {
        puVar1[1] = puVar1[1] + 1;
    }
    void* vtbl = *reinterpret_cast<void**>(piVar2);
    reinterpret_cast<void (*)(uint32_t*, uint32_t*, uint32_t)>(
        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtbl) + 0x70))(piVar2, puVar1, 1);
    if (puVar1 != nullptr) {
        release_refcounted(puVar1, 1);
    }
}

// ---------------------------------------------------------------------------
// 0x4c2f70 — observed shape
// One-shot initialiser on the receiver-in-EAX block: lazily obtains the
// backing object, looks up a record through FUN_00449390 and clears its +0x3c
// word while setting bit 0 at object+0x20.
// ---------------------------------------------------------------------------
void FUN_004c2f70(void* self_in_EAX)
{
    uint32_t* self = reinterpret_cast<uint32_t*>(self_in_EAX);

    if (static_cast<char>(self[6]) == '\0') {
        uint32_t iVar1 = self[0];
        *reinterpret_cast<uint8_t*>(self + 6) = 1;
        if (iVar1 == 0) {
            FUN_00510a60();
            iVar1 = self[0];
            if (iVar1 == 0) {
                return;
            }
        }
        uint8_t* found = FUN_00449390(
            &DAT_007278d4,
            *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(
                static_cast<uintptr_t>(iVar1)) + 0xbc));
        if (found != nullptr) {
            *reinterpret_cast<uint16_t*>(found + 0x3c) = 0;
            *reinterpret_cast<uint8_t*>(
                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(self[0])) + 0x20) |= 1;
        }
    }
}

// ---------------------------------------------------------------------------
// 0x4c2fc0 — observed shape
// Replaces the element at receiver(+0x2c)->+0x8 with param_1: destroys the old
// element, hands the new pointer to FUN_005606f0 under slot 2, and keeps the
// local copy alive through FUN_00542690.
// ---------------------------------------------------------------------------
void FUN_004c2fc0(void* param_1, void* self_in_ESI)
{
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(param_1);
    uint8_t* holder = *reinterpret_cast<uint8_t**>(
        reinterpret_cast<uint8_t*>(self_in_ESI) + 0x2c);
    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(holder + 8);

    if (puVar2 != puVar1) {
        if (puVar1 != nullptr) {
            call_vtbl0(puVar1, 1);
        }
        void* local = param_1;
        FUN_005606f0(2, &local);
    }
    FUN_00542690(puVar2);
}

// ---------------------------------------------------------------------------
// 0x4c3000 — observed shape
// Detaches an element through the container's virtual slot +0x74, releases the
// element's temporary reference, then removes the element from the vector
// rooted at *EAX by scanning [data+0, count) for EBX, swapping it with the last
// live slot and decrementing the reference count at +0x10.
// ---------------------------------------------------------------------------
void FUN_004c3000(void* self_in_EAX, uint32_t* param_in_EBX, uint32_t* obj_in_EDI)
{
    uint32_t* in_EAX = reinterpret_cast<uint32_t*>(self_in_EAX);
    uint32_t* unaff_EBX = param_in_EBX;
    uint32_t* unaff_EDI = obj_in_EDI;
    uint8_t local_4[4];

    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*unaff_EBX));
    uint32_t* piVar6 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_EAX[1]));
    if (puVar2 != nullptr) {
        puVar2[1] = puVar2[1] + 1;
    }
    void* vtbl = *reinterpret_cast<void**>(piVar6);
    reinterpret_cast<void (*)(uint32_t*, uint8_t*, uint32_t*)>(
        *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtbl) + 0x74))(
        piVar6, local_4, puVar2);
    if (unaff_EDI != nullptr) {
        int32_t iVar3 = static_cast<int32_t>(unaff_EDI[1]);
        unaff_EDI[1] = static_cast<uint32_t>(iVar3 + -1);
        if (iVar3 + -1 == 0) {
            call_vtbl0(unaff_EDI, 1);
        }
    }
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
    }

    uint8_t* iVar3base = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(in_EAX[0]));
    uint32_t uVar7 = 0;
    uint32_t count = *reinterpret_cast<uint32_t*>(iVar3base + 8);
    if (count != 0) {
        uint32_t* piVar6scan = *reinterpret_cast<uint32_t**>(iVar3base + 4);
        do {
            if (reinterpret_cast<uint32_t*>(
                    static_cast<uintptr_t>(*piVar6scan)) == unaff_EBX) {
                goto LAB_004c3067;
            }
            uVar7 = uVar7 + 1;
            piVar6scan = piVar6scan + 1;
        } while (uVar7 < count);
    }
    uVar7 = 0xffffffff;
LAB_004c3067:
    if (uVar7 < *reinterpret_cast<uint32_t*>(iVar3base + 0xc)) {
        uint32_t iVar1 = *reinterpret_cast<uint32_t*>(iVar3base + 0xc) - 1;
        uint32_t* iVar4 = *reinterpret_cast<uint32_t**>(iVar3base + 4);
        *reinterpret_cast<uint32_t*>(iVar3base + 0xc) = iVar1;
        uint32_t iVar5 = iVar4[uVar7];
        iVar4[uVar7] = iVar4[iVar1];
        iVar4[*reinterpret_cast<uint32_t*>(iVar3base + 0xc)] = 0;
        if (iVar5 != 0) {
            uint32_t* refs = reinterpret_cast<uint32_t*>(iVar3base + 0x10);
            *refs = *refs + static_cast<uint32_t>(-1);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x4c30a0 — observed shape
// Removes the container element matching the ECX key from the vector at
// receiver+0x20: linear scan, swap with the last live slot, clear the trailing
// entry, and drop the reference counter when a non-null element was removed.
// ---------------------------------------------------------------------------
void FUN_004c30a0(void* self_in_EAX, int key_in_ECX)
{
    uint8_t* in_EAX = reinterpret_cast<uint8_t*>(self_in_EAX);

    uint8_t* iVar2 = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(in_EAX + 0x20)));
    uint32_t uVar5 = 0;
    uint32_t count = *reinterpret_cast<uint32_t*>(iVar2 + 8);
    if (count != 0) {
        int32_t* piVar6 = *reinterpret_cast<int32_t**>(iVar2 + 4);
        do {
            if (key_in_ECX == *piVar6) {
                goto LAB_004c30c2;
            }
            uVar5 = uVar5 + 1;
            piVar6 = piVar6 + 1;
        } while (uVar5 < count);
    }
    uVar5 = 0xffffffff;
LAB_004c30c2:
    if (uVar5 < *reinterpret_cast<uint32_t*>(iVar2 + 0xc)) {
        uint32_t iVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc) - 1;
        uint32_t iVar3 = *reinterpret_cast<uint32_t*>(iVar2 + 4);
        *reinterpret_cast<uint32_t*>(iVar2 + 0xc) = iVar1;
        int32_t iVar4 = *reinterpret_cast<int32_t*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar3)) + uVar5 * 4);
        *reinterpret_cast<int32_t*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar3)) + uVar5 * 4) =
            *reinterpret_cast<int32_t*>(
                reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar3)) + iVar1 * 4);
        *reinterpret_cast<int32_t*>(
            reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
                *reinterpret_cast<uint32_t*>(iVar2 + 4))) +
            *reinterpret_cast<uint32_t*>(iVar2 + 0xc) * 4) = 0;
        if (iVar4 != 0) {
            uint32_t* refs = reinterpret_cast<uint32_t*>(iVar2 + 0x10);
            *refs = *refs + static_cast<uint32_t>(-1);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x4c3100 — observed shape
// Scans the array at receiver+0x30 (count +0x38) for the first non-null entry
// whose +0x1c float differs from its +0x18 float and returns it; otherwise
// returns the +0x1c float of the entry indexed by receiver+0x9c.
// ---------------------------------------------------------------------------
float10 FUN_004c3100(void* self_in_ECX)
{
    uint8_t* in_ECX = reinterpret_cast<uint8_t*>(self_in_ECX);

    uint32_t uVar2 = 0;
    uint32_t count = *reinterpret_cast<uint32_t*>(in_ECX + 0x38);
    if (count != 0) {
        int32_t* piVar3 = *reinterpret_cast<int32_t**>(in_ECX + 0x30);
        do {
            int32_t iVar1 = *piVar3;
            if ((iVar1 != 0) &&
                (static_cast<float10>(*reinterpret_cast<float*>(
                     reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar1)) + 0x1c)) !=
                 static_cast<float10>(*reinterpret_cast<float*>(
                     reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar1)) + 0x18)))) {
                return static_cast<float10>(*reinterpret_cast<float*>(
                    reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar1)) + 0x1c));
            }
            uVar2 = uVar2 + 1;
            piVar3 = piVar3 + 1;
        } while (uVar2 < count);
    }
    int32_t base = *reinterpret_cast<int32_t*>(
        reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(in_ECX + 0x30))) +
        *reinterpret_cast<uint32_t*>(in_ECX + 0x9c) * 4);
    return static_cast<float10>(*reinterpret_cast<float*>(
        reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(base)) + 0x1c));
}

// ---------------------------------------------------------------------------
// 0x4c3150 — observed shape
// Constructor: increments the global instance counter, installs the
// PTR_FUN_0070d02c marker, allocates strlen(param)+1 bytes through the thunk
// and copies the C string into the new block stored at +0x8.
// ---------------------------------------------------------------------------
void FUN_004c3150(void* self_in_EDI, char* param_in_EAX)
{
    uint32_t* unaff_EDI = reinterpret_cast<uint32_t*>(self_in_EDI);
    char* in_EAX = param_in_EAX;

    DAT_00727444 = DAT_00727444 + 1;
    unaff_EDI[1] = 0;
    unaff_EDI[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_0070d02c));

    char* pcVar2 = in_EAX;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');

    intptr_t length = 1 - static_cast<intptr_t>(in_EAX + 1);
    char* pcVar3 = reinterpret_cast<char*>(thunk_FUN_00533c78(pcVar2 + length));
    char* pcVar2copy = pcVar3;
    do {
        cVar1 = *in_EAX;
        in_EAX = in_EAX + 1;
        *pcVar2copy = cVar1;
        pcVar2copy = pcVar2copy + 1;
    } while (cVar1 != '\0');
    *reinterpret_cast<void**>(unaff_EDI + 2) = pcVar3;
}

// ---------------------------------------------------------------------------
// 0x4c31e0 — observed shape
// Seeds two global RNG-derived arrays (4 and 10 dwords), copies the static
// PTR_DAT_00726640 string into DAT_008c9578, and records its length in
// _DAT_008cac10.
// ---------------------------------------------------------------------------
void FUN_004c31e0(void)
{
    int32_t iVar5 = 0;
    do {
        uint32_t uVar2 = FUN_005f0ddc();
        (&DAT_008c95a0)[iVar5] = uVar2;
        iVar5 = iVar5 + 1;
    } while (iVar5 < 4);

    iVar5 = 0;
    do {
        uint32_t uVar2 = FUN_005f0ddc();
        (&DAT_008c95b0)[iVar5] = uVar2;
        iVar5 = iVar5 + 1;
    } while (iVar5 < 10);

    int32_t offset = static_cast<int32_t>(
        reinterpret_cast<intptr_t>(&DAT_008c9578) -
        reinterpret_cast<intptr_t>(PTR_DAT_00726640));
    uint8_t* pcVar3 = PTR_DAT_00726640;
    char cVar1;
    do {
        cVar1 = static_cast<char>(*pcVar3);
        pcVar3[offset] = static_cast<uint8_t>(cVar1);
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');

    pcVar3 = &DAT_008c9578;
    uint8_t* pcVar4;
    do {
        pcVar4 = pcVar3;
        pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    _DAT_008cac10 = static_cast<uint32_t>(
        reinterpret_cast<intptr_t>(pcVar4) - 0x8c9578);
}

// ---------------------------------------------------------------------------
// 0x4c3280 — observed shape
// Large constructor: zeroes the scalar/pointer fields, installs the marker
// tables, allocates 0x94 bytes for the 0x25-dword array, installs the
// secondary markers, clears the two 200-entry string tables and initialises
// the trailing path/string fields.
// ---------------------------------------------------------------------------
void FUN_004c3280(void* self_in_ESI)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self_in_ESI);

    *reinterpret_cast<uint8_t**>(base + 0x20) = &DAT_008cacd0;
    *reinterpret_cast<uint32_t*>(base + 8) = 0;
    *reinterpret_cast<uint32_t*>(base + 0xc) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x10) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x14) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x18) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x1c) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x2c) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x30) = 0;
    *reinterpret_cast<void**>(base + 4) = &PTR_FUN_006f5814;
    *reinterpret_cast<uint8_t**>(base + 0x38) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0x3c) = &DAT_008cacd0;
    *reinterpret_cast<uint32_t*>(base + 0x34) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x40) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x44) = 0;
    *reinterpret_cast<void**>(base + 0x48) = &PTR_FUN_0070d8e0;
    *reinterpret_cast<uint32_t*>(base + 0x4c) = 0x25;
    *reinterpret_cast<uint32_t*>(base + 0x54) = 0;
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
    *reinterpret_cast<uint32_t**>(base + 0x50) = puVar1;
    for (uint32_t uVar2 = *reinterpret_cast<uint32_t*>(base + 0x4c) & 0x3fffffff;
         uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar1) + 1);
    }
    *reinterpret_cast<void**>(base + 0x48) = &PTR_FUN_0070d918;
    base[0x59] = 1;
    base[0x58] = 1;
    *reinterpret_cast<uint32_t*>(base + 100) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x70) = 1;
    *reinterpret_cast<uint32_t*>(base + 0x68) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x6c) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x60) = 0;
    *reinterpret_cast<void**>(base + 0x5c) = &PTR_FUN_00704c70;
    *reinterpret_cast<uint32_t*>(base + 0x78) = 0;
    *reinterpret_cast<uint8_t**>(base + 0x80) = &DAT_008cacd0;

    uint32_t* puVar1b = reinterpret_cast<uint32_t*>(base + 0x90);
    int32_t iVar3b = 200;
    do {
        *reinterpret_cast<uint8_t**>(puVar1b) = &DAT_008cacd0;
        puVar1b = puVar1b + 2;
        iVar3b = iVar3b + -1;
    } while (iVar3b != 0);

    puVar1b = reinterpret_cast<uint32_t*>(base + 0x6e8);
    iVar3b = 200;
    do {
        *reinterpret_cast<uint8_t**>(puVar1b) = &DAT_008cacd0;
        puVar1b = puVar1b + 2;
        iVar3b = iVar3b + -1;
    } while (iVar3b != 0);

    *reinterpret_cast<uint8_t**>(base + 0xd28) = &DAT_008cacd0;
    *reinterpret_cast<uint32_t*>(base + 0xd30) = 0;
    *reinterpret_cast<uint32_t*>(base + 0xd34) = 0;
    *reinterpret_cast<uint32_t*>(base + 0xd7c) = 0;
    *reinterpret_cast<uint8_t**>(base + 0xda8) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xdac) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xdc8) = &DAT_008cacd0;
    *reinterpret_cast<uint32_t*>(base + 0xdd4) = 0;
    *reinterpret_cast<uint32_t*>(base + 0xdd8) = 0;
    *reinterpret_cast<uint32_t*>(base + 0xddc) = 0;
    *reinterpret_cast<uint32_t*>(base + 0xdd0) = 0;
    *reinterpret_cast<void**>(base + 0xdcc) = &PTR_FUN_00704c70;
    *reinterpret_cast<uint32_t*>(base + 0xde0) = 1;
    *reinterpret_cast<uint32_t*>(base + 0xdec) = 0;
    *reinterpret_cast<void**>(base + 0xdf0) = &PTR_FUN_0070d8dc;
    *reinterpret_cast<uint8_t**>(base + 0xdfc) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe08) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe14) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe20) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe2c) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe38) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe44) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe50) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe5c) = &DAT_008cacd0;
    *reinterpret_cast<uint8_t**>(base + 0xe68) = &DAT_008cacd0;
    *reinterpret_cast<uint32_t*>(base + 0xe6c) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x74) = 0;
    *reinterpret_cast<uint32_t*>(base + 0xdbc) = 0;
    *reinterpret_cast<uint32_t*>(base + 0xdc0) = 0;
    *reinterpret_cast<uint8_t*>(base) = 0;
    base[0x84] = 0;
}

// ---------------------------------------------------------------------------
// 0x4c3410 — observed shape
// Full destructor: releases the +0x78 and +0xd34 references, resets the
// controller/stream helpers, clears the string buffers at +0xd28/+0xda8/
// +0xdac, destroys the +0x74 owner, releases +0xdec, then frees the shifted
// buffers at +0xdc8/+0xdac/+0xda8/+0xd28/+0x80, clears the two 200-entry
// tables and finishes with the controller teardown calls.
// ---------------------------------------------------------------------------
void FUN_004c3410(void* self_in_ESI)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self_in_ESI);

    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 0x78);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
        *reinterpret_cast<uint32_t*>(base + 0x78) = 0;
    }
    *reinterpret_cast<uint32_t*>(base + 0xde4) = 0;
    puVar2 = *reinterpret_cast<uint32_t**>(base + 0xd34);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
        *reinterpret_cast<uint32_t*>(base + 0xd34) = 0;
    }
    *reinterpret_cast<uint32_t*>(base + 0xd38) = 0;
    FUN_004cd170();
    *reinterpret_cast<uint8_t*>(base) = 0;
    base[0xdc4] = 0;
    *reinterpret_cast<uint32_t*>(base + 0x6e4) = 0;

    uint8_t* pVar = *reinterpret_cast<uint8_t**>(base + 0xd28);
    if (*reinterpret_cast<int32_t*>(pVar - 4) != 0) {
        *pVar = 0;
        *reinterpret_cast<uint32_t*>(pVar - 4) = 0;
    }
    *reinterpret_cast<uint32_t*>(base + 0xd2c) = 0xffffffff;

    pVar = *reinterpret_cast<uint8_t**>(base + 0xda8);
    if (*reinterpret_cast<int32_t*>(pVar - 4) != 0) {
        *pVar = 0;
        *reinterpret_cast<uint32_t*>(pVar - 4) = 0;
    }
    pVar = *reinterpret_cast<uint8_t**>(base + 0xdac);
    if (*reinterpret_cast<int32_t*>(pVar - 4) != 0) {
        *pVar = 0;
        *reinterpret_cast<uint32_t*>(pVar - 4) = 0;
    }

    uint32_t* piVar1 = *reinterpret_cast<uint32_t**>(base + 0x74);
    if (piVar1 != nullptr) {
        if (piVar1[1] != 0) {
            FUN_004cd100(1);
            piVar1[1] = 0;
        }
        uint8_t* q = reinterpret_cast<uint8_t*>(
            static_cast<uintptr_t>(*piVar1)) - 8;
        if (q != nullptr && q != &DAT_008cacc8) {
            operator_delete__(q);
        }
        *piVar1 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
        operator_delete(piVar1);
        *reinterpret_cast<uint32_t*>(base + 0x74) = 0;
    }

    FUN_004cd250();
    puVar2 = *reinterpret_cast<uint32_t**>(base + 0xdec);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
    }
    FUN_0045a050();

    release_shifted_buffer(*reinterpret_cast<void**>(base + 0xdc8));
    *reinterpret_cast<uint8_t**>(base + 0xdc8) = &DAT_008cacd0;
    release_shifted_buffer(*reinterpret_cast<void**>(base + 0xdac));
    *reinterpret_cast<uint8_t**>(base + 0xdac) = &DAT_008cacd0;
    release_shifted_buffer(*reinterpret_cast<void**>(base + 0xda8));
    *reinterpret_cast<uint8_t**>(base + 0xda8) = &DAT_008cacd0;

    puVar2 = *reinterpret_cast<uint32_t**>(base + 0xd7c);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
    }
    puVar2 = *reinterpret_cast<uint32_t**>(base + 0xd34);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
    }
    puVar2 = *reinterpret_cast<uint32_t**>(base + 0xd30);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
    }

    release_shifted_buffer(*reinterpret_cast<void**>(base + 0xd28));
    *reinterpret_cast<uint8_t**>(base + 0xd28) = &DAT_008cacd0;

    uint32_t* puVar2loop = reinterpret_cast<uint32_t*>(base + 0xd28);
    int32_t iVar4 = 200;
    do {
        uint32_t* piVar1loop = puVar2loop - 2;
        puVar2loop = puVar2loop - 2;
        release_shifted_buffer(reinterpret_cast<void*>(
            static_cast<uintptr_t>(*piVar1loop)));
        iVar4 = iVar4 + -1;
        *puVar2loop = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    } while (iVar4 != 0);

    puVar2loop = reinterpret_cast<uint32_t*>(base + 0x6d0);
    iVar4 = 200;
    do {
        uint32_t* piVar1loop = puVar2loop - 2;
        puVar2loop = puVar2loop - 2;
        release_shifted_buffer(reinterpret_cast<void*>(
            static_cast<uintptr_t>(*piVar1loop)));
        iVar4 = iVar4 + -1;
        *puVar2loop = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    } while (iVar4 != 0);

    release_shifted_buffer(*reinterpret_cast<void**>(base + 0x80));
    *reinterpret_cast<uint8_t**>(base + 0x80) = &DAT_008cacd0;

    puVar2 = *reinterpret_cast<uint32_t**>(base + 0x78);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
    }
    FUN_0045a050();
    FUN_004cd2a0();
    FUN_00412b40();
}

// ---------------------------------------------------------------------------
// 0x4c3690 — observed shape
// Destructor for the render/controller object: releases +0x78, clears +0xde4,
// tears down the embedded +0xdcc block, releases +0xd34, resets helpers and
// the string buffer at +0xd28, rebinds the alphabet strings and rereads the
// stored two-letter table through FUN_004cd0a0.
// ---------------------------------------------------------------------------
void FUN_004c3690(void* self_in_EDI)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self_in_EDI);

    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 0x78);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
        *reinterpret_cast<uint32_t*>(base + 0x78) = 0;
    }
    *reinterpret_cast<uint32_t*>(base + 0xde4) = 0;
    FUN_004b0b90(base + 0xdcc);
    *reinterpret_cast<uint32_t*>(base + 0xd38) = 0;
    puVar2 = *reinterpret_cast<uint32_t**>(base + 0xd34);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
        *reinterpret_cast<uint32_t*>(base + 0xd34) = 0;
    }
    FUN_004cd170();
    *reinterpret_cast<uint8_t*>(base) = 0;
    base[0xdc4] = 0;
    *reinterpret_cast<uint32_t*>(base + 0x6e4) = 0;

    uint8_t* pVar = *reinterpret_cast<uint8_t**>(base + 0xd28);
    if (*reinterpret_cast<int32_t*>(pVar - 4) != 0) {
        *pVar = 0;
        *reinterpret_cast<uint32_t*>(pVar - 4) = 0;
    }
    *reinterpret_cast<uint32_t*>(base + 0xd2c) = 0xffffffff;
    *reinterpret_cast<uint32_t*>(base + 0x88) = 0xffffffff;
    *reinterpret_cast<uint32_t*>(base + 0x8c) = 0xffffffff;

    FUN_004c3a50(base);
    FUN_004f6090("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    FUN_00412f10();
    pVar = *reinterpret_cast<uint8_t**>(base + 0xda8);
    FUN_004cd0a0(*pVar);
    *reinterpret_cast<uint32_t*>(base + 0xdb0) =
        *reinterpret_cast<uint32_t*>(pVar - 4);
    FUN_004f6090("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    FUN_00412f10();
}

// ---------------------------------------------------------------------------
// 0x4c5b10 — observed shape
// Frame driver: opens the run through FUN_004c5d60, then while the +0xdc4
// flag stays set renders a frame, advances the clock pair at +0x88/+0x8c,
// selects a path/seed or a cached value, submits it through FUN_004c79c0 and
// honours the +0x8cac27 abort flag by tearing the run down.
// ---------------------------------------------------------------------------
void FUN_004c5b10(int param_1, void* self_in_ESI)
{
    bool bVar1 = false;
    uint8_t* unaff_ESI = reinterpret_cast<uint8_t*>(self_in_ESI);
    uint32_t extraout_var = 0;  // listing declares an uninitialised extraout value
    char local_100[256];

    FUN_00412df0();
    FUN_004c5d60(unaff_ESI, static_cast<int>(extraout_var));

    if (unaff_ESI[0xdc4] != 0) {
        do {
            FUN_004c6070(unaff_ESI);
            uint32_t uVar3 = DAT_008dc310;
            uint8_t* iVar2 = DAT_008cabe8;
            *reinterpret_cast<uint32_t*>(unaff_ESI + 0x88) = DAT_008dc30c;
            *reinterpret_cast<uint32_t*>(unaff_ESI + 0x8c) = uVar3;

            if (iVar2[0xc] == 0) {
                FUN_004d0cd0(0, 0, 0);
                uint32_t local_104 = FUN_0042e1d0(&DAT_006f588c);
                uVar3 = local_104;
                if (DAT_0086bb5c != 0) {
                    sprintf(local_100, "%s_%03X", &DAT_006f588c, local_104);
                    FUN_0051bfc0(&local_104);
                    uVar3 = local_104;
                }
            } else {
                uVar3 = FUN_004b2760(0);
            }
            FUN_004c79c0(unaff_ESI, uVar3);
            if (DAT_008cabe8 == nullptr) {
                Sleep(10);
            }
            if (DAT_008cac27 != 0) {
                FUN_004c5fa0();
                bVar1 = true;
                unaff_ESI[0xdc4] = 0;
            }
        } while (unaff_ESI[0xdc4] != 0);
        if (bVar1) {
            goto LAB_004c5c1f;
        }
    }
    FUN_004c5fa0();
LAB_004c5c1f:
    release_shifted_buffer(reinterpret_cast<void*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(param_1))));
}

// ---------------------------------------------------------------------------
// 0x4c5c50 — observed shape
// Copies the string produced by FUN_004c3eb0 into the shared DAT_008cacd0
// buffer when it is non-empty, frees the temporary buffers and reports whether
// the global length counter ended up non-zero.
// ---------------------------------------------------------------------------
int32_t FUN_004c5c50(uint32_t param_1, int param_2)
{
    int32_t local_4 = 0;
    uint32_t extraout_var = 0;

    FUN_00412df0();
    void** puVar1 = reinterpret_cast<void**>(
        FUN_004c3eb0(param_1, &local_4, extraout_var));
    uint8_t* _Src = reinterpret_cast<uint8_t*>(*puVar1);
    size_t _Size = *reinterpret_cast<size_t*>(_Src - 4);

    if ((static_cast<int32_t>(_Size) >= 0) && (_Src != nullptr) &&
        (_Src != &DAT_008cacd0)) {
        if (_Size == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            memmove(&DAT_008cacd0, _Src, _Size);
            (&DAT_008cacd0)[DAT_008caccc] = 0;
        }
    }

    release_shifted_buffer(reinterpret_cast<void*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(local_4))));

    if (DAT_008caccc == 0) {
        release_shifted_buffer(reinterpret_cast<void*>(
            static_cast<uintptr_t>(static_cast<uint32_t>(param_2))));
        return 0;
    }
    release_shifted_buffer(reinterpret_cast<void*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(param_2))));
    return 1;
}

// ---------------------------------------------------------------------------
// 0x4c5d60 — observed shape
// Starts a run on the receiver: adopts the string returned by FUN_004c42e0
// into the +0xdc8 buffer, sets the +0xdc4 run flag, resets the frame counter
// and string state, computes the +0xde8 frame-rate scale, initialises the
// controller stack entries and installs a new PTR_FUN_006fd14c object at
// +0xdec, then runs the remaining setup helpers.
// ---------------------------------------------------------------------------
void FUN_004c5d60(void* param_1, int param_2)
{
    uint8_t* iVar5 = reinterpret_cast<uint8_t*>(param_1);
    uint8_t auStack_2[2];

    FUN_00412df0();
    void** puVar6 = reinterpret_cast<void**>(FUN_004c42e0(
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(iVar5)), &param_1));
    uint8_t* _Src = reinterpret_cast<uint8_t*>(*puVar6);
    size_t _Size = *reinterpret_cast<size_t*>(_Src - 4);

    if ((static_cast<int32_t>(_Size) >= 0) && (_Src != nullptr) &&
        (_Src != *reinterpret_cast<uint8_t**>(iVar5 + 0xdc8))) {
        if (_Size == 0) {
            FUN_00412f90();
        } else {
            FUN_004f3350();
            uint8_t* dst = *reinterpret_cast<uint8_t**>(iVar5 + 0xdc8);
            memmove(dst, _Src, _Size);
            dst[*reinterpret_cast<int32_t*>(dst - 4)] = 0;
        }
    }

    release_shifted_buffer(reinterpret_cast<void*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(
            reinterpret_cast<intptr_t>(param_1)))));

    iVar5[0xdc4] = 1;
    *reinterpret_cast<uint32_t*>(iVar5 + 0x6e4) = 0;
    param_1 = &DAT_008cacd0;

    uint8_t* pVar = *reinterpret_cast<uint8_t**>(iVar5 + 0xd28);
    if (*reinterpret_cast<int32_t*>(pVar - 4) != 0) {
        *pVar = 0;
        *reinterpret_cast<uint32_t*>(pVar - 4) = 0;
    }
    *reinterpret_cast<uint32_t*>(iVar5 + 0xd2c) = 0xffffffff;

    uint8_t* iVar3 = DAT_008cabe8;
    DAT_0085a11c = 0x43;
    DAT_008c9de0 = DAT_008c9dd8;
    *reinterpret_cast<float*>(iVar5 + 0xde8) =
        ((static_cast<float>(DAT_00726380) *
              *reinterpret_cast<float*>(DAT_008c9dd8 + 4)) /
             static_cast<float>(DAT_008cac1c) +
         2.0) *
        static_cast<float>((static_cast<int32_t>(
                                DAT_008cac18 * 0x43 +
                                ((DAT_008cac18 * 0x43) >> 0x1f & 0x3ffU))) >>
                           10) *
        0.01;
    *reinterpret_cast<uint32_t*>(iVar3 + 8) = 0xffffffff;

    FUN_004c8070();
    DAT_0086c330 = 0;
    uint32_t uVar7 = 0;  // listing reuses an uninitialised extraout_ECX value
    FUN_00412df0();
    FUN_004c3eb0(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(iVar5)),
                 reinterpret_cast<int*>(auStack_2 - 0x16), uVar7);
    FUN_004c8aa0(iVar5);
    FUN_004c82b0();

    *reinterpret_cast<uint32_t*>(&DAT_007268f4[DAT_00726a84 * 4]) = DAT_007263bc;
    DAT_00726a84 = DAT_00726a84 + 1;
    DAT_007263bc = 0x81440;

    uint32_t* puVar6b = reinterpret_cast<uint32_t*>(FUN_00533c78());
    uint32_t uVar4 = DAT_008ea008;
    int32_t iVar3b = DAT_00726380;
    uint32_t uVar7b = DAT_0072637c;
    if (puVar6b == nullptr) {
        puVar6b = nullptr;
    } else {
        DAT_00727444 = DAT_00727444 + 1;
        puVar6b[1] = 0;
        puVar6b[0] = static_cast<uint32_t>(
            reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar6b[7] = 0;
        puVar6b[0x19] = 0;
        puVar6b[0x2f] = 0;
        FUN_004bdca0(uVar4, 0, 0, uVar7b, iVar3b, 0xffffffff, 0, 0, 0x400);
    }

    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(iVar5 + 0xdec);
    if (puVar2 != puVar6b) {
        if (puVar2 != nullptr) {
            int32_t* refcount = reinterpret_cast<int32_t*>(puVar2 + 1);
            *refcount = *refcount + -1;
            if (*refcount == 0) {
                void* vtbl = *reinterpret_cast<void**>(puVar2);
                reinterpret_cast<void (*)(uint32_t*)>(
                    *reinterpret_cast<void**>(vtbl))(puVar2);
            }
        }
        *reinterpret_cast<uint32_t**>(iVar5 + 0xdec) = puVar6b;
        if (puVar6b != nullptr) {
            puVar6b[1] = puVar6b[1] + 1;
        }
    }

    FUN_00412df0();
    FUN_004c5770();
    FUN_004c8580();
    release_shifted_buffer(reinterpret_cast<void*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(param_2))));
}

// ---------------------------------------------------------------------------
// 0x4c5fa0 — observed shape
// Ends a run: clears the +0xdc4 flag, pops the frame-stack pointer, tears down
// the render helpers, releases +0xd34/+0x78/+0xdec, resets the string buffer
// at +0xd28 and clears the counters.
// ---------------------------------------------------------------------------
void FUN_004c5fa0(void* self_in_EAX)
{
    uint8_t* in_EAX = reinterpret_cast<uint8_t*>(self_in_EAX);

    in_EAX[0xdc4] = 0;
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = *reinterpret_cast<uint32_t*>(&DAT_007268f4[DAT_00726a84 * 4]);
    FUN_004c8440();
    FUN_004c8a10();
    FUN_004b9650();

    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(in_EAX + 0xd34);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
        *reinterpret_cast<uint32_t*>(in_EAX + 0xd34) = 0;
    }
    FUN_004ae4f0();
    FUN_00412840(DAT_008c95dc, DAT_008c95d8);

    puVar2 = *reinterpret_cast<uint32_t**>(in_EAX + 0x78);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
        *reinterpret_cast<uint32_t*>(in_EAX + 0x78) = 0;
    }
    puVar2 = *reinterpret_cast<uint32_t**>(in_EAX + 0xdec);
    if (puVar2 != nullptr) {
        release_refcounted(puVar2, 1);
        *reinterpret_cast<uint32_t*>(in_EAX + 0xdec) = 0;
    }
    *reinterpret_cast<uint32_t*>(in_EAX + 0x6e4) = 0;
    DAT_0086c330 = 0;

    uint8_t* pVar = *reinterpret_cast<uint8_t**>(in_EAX + 0xd28);
    if (*reinterpret_cast<int32_t*>(pVar - 4) != 0) {
        *pVar = 0;
        *reinterpret_cast<uint32_t*>(pVar - 4) = 0;
    }
    *reinterpret_cast<uint32_t*>(in_EAX + 0xd2c) = 0xffffffff;
}

// ---------------------------------------------------------------------------
// 0x4c6070 — observed shape
// Per-frame UI update. Draws the +0xde4-bounded wrapped status text lines into
// the +0xd34 dialogue surface (with the +0xd80 scroll offset), then refreshes
// the +0xdec surface and finally draws the +0xdc8 string at the fixed
// (0x140, 0xc, 100) position. The listing keeps the several string temporaries
// in the shared DAT_008cacd0 buffer, so the code below mirrors that aliasing.
// ---------------------------------------------------------------------------
void FUN_004c6070(void* param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(param_1);
    int32_t param_1i = static_cast<int32_t>(reinterpret_cast<intptr_t>(base));

    uint8_t* _Dst = &DAT_008cacd0;
    uint8_t* local_18 = &DAT_008cacd0;
    int32_t local_10 = static_cast<int32_t>(FUN_005f0ddc());
    uint8_t* puStack_8 = &DAT_008cacd0;
    uint8_t* puStack_c = &DAT_008cacd0;
    uint8_t* puVar5;
    float fStack_4;

    if (*reinterpret_cast<int32_t*>(base + 0xd30) != 0) {
        FUN_004c84b0();
        uint32_t uVar3 = FUN_00503840();
        uVar3 = uVar3 & 0x80000001;
        if (static_cast<int32_t>(uVar3) < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
        }
        if (uVar3 == 1) {
            int32_t iVar4 = static_cast<int32_t>(FUN_005f0ddc());
            local_10 = local_10 + iVar4;
        }
    }

    int32_t local_20 = local_10 + 0x60;
    puVar5 = reinterpret_cast<uint8_t*>(FUN_004c7fd0());
    int32_t iVar4 = 5;
    fStack_4 = static_cast<float>(reinterpret_cast<intptr_t>(puVar5));
    if (5 < *reinterpret_cast<int32_t*>(base + 0x6e4) + 5) {
        do {
            FUN_0042c610();
            iVar4 = iVar4 + 1;
        } while (iVar4 < *reinterpret_cast<int32_t*>(base + 0x6e4) + 5);
    }

    iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(DAT_008cabe8));
    *reinterpret_cast<uint32_t*>(base + 0x6e4) = 0;
    if (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar4))[0xc] != 0) {
        FUN_004b24a0(reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(iVar4)), 0);
    }

    char cStack_29 = '\x01';
    puStack_c = puVar5;
    {
        int32_t iVar4ratio = static_cast<int32_t>(FUN_005f0ddc());
        int32_t limit = (iVar4ratio != 0)
                            ? static_cast<int32_t>(
                                  static_cast<int64_t>(0x26c) / iVar4ratio) / 2 +
                                  static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar5))
                            : static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar5));
        if (static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar5)) < limit) {
            while (static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar5)) <=
                   *reinterpret_cast<int32_t*>(base + 0xde4)) {
                if (*reinterpret_cast<int32_t*>(_Dst - 4) != 0) {
                    *_Dst = 0;
                    *reinterpret_cast<int32_t*>(_Dst - 4) = 0;
                }
                uint8_t* entry = *reinterpret_cast<uint8_t**>(
                    base + 0xdd0 + static_cast<intptr_t>(puVar5) * 4);
                puVar5 = entry;
                size_t sVar2 = *reinterpret_cast<size_t*>(puVar5 - 4);
                int32_t iStack_14 = 0x2a;
                if ((static_cast<int32_t>(sVar2) >= 0) && (puVar5 != nullptr) &&
                    (puVar5 != &DAT_008cacd0)) {
                    if (sVar2 == 0) {
                        if (DAT_008caccc != 0) {
                            DAT_008cacd0 = 0;
                            DAT_008caccc = 0;
                        }
                    } else {
                        if (static_cast<int32_t>(sVar2) > 0) {
                            if (DAT_008cacc8 < static_cast<int32_t>(sVar2)) {
                                FUN_004f32e0();
                            }
                            DAT_008caccc = static_cast<int32_t>(sVar2);
                        }
                        memmove(&DAT_008cacd0, puVar5, sVar2);
                        (&DAT_008cacd0)[DAT_008caccc] = 0;
                    }
                }
                if (DAT_008caccc != 0) {
                    char* pcStack_1c;
                    char* pcStack_24;
                    if (cStack_29 == '\0') {
                        pcStack_1c = nullptr;
                    } else {
                        char* found = strchr(reinterpret_cast<char*>(&DAT_008cacd0), 0x3c);
                        if ((DAT_008caccc < 1) || (found == nullptr)) {
                            pcStack_1c = reinterpret_cast<char*>(static_cast<intptr_t>(-1));
                        } else {
                            pcStack_1c = reinterpret_cast<char*>(
                                reinterpret_cast<intptr_t>(found) - 0x8cacd0);
                        }
                    }
                    int32_t iVar4loop;
                    while (iVar4loop = DAT_008caccc,
                           pcStack_1c != reinterpret_cast<char*>(static_cast<intptr_t>(-1))) {
                        pcStack_24 = reinterpret_cast<char*>(&DAT_008cacd0);
                        if ((DAT_008caccc >= 0) && (_Dst != &DAT_008cacd0)) {
                            if (DAT_008caccc == 0) {
                                if (*reinterpret_cast<int32_t*>(_Dst - 4) != 0) {
                                    *_Dst = 0;
                                    *reinterpret_cast<int32_t*>(_Dst - 4) = 0;
                                }
                            } else {
                                if (DAT_008caccc > 0) {
                                    if (*reinterpret_cast<int32_t*>(_Dst - 8) <
                                        DAT_008caccc) {
                                        FUN_004f32e0();
                                        _Dst = local_18;
                                    }
                                    *reinterpret_cast<int32_t*>(_Dst - 4) = iVar4loop;
                                }
                                memmove(_Dst, &DAT_008cacd0,
                                        static_cast<size_t>(iVar4loop));
                                _Dst[*reinterpret_cast<int32_t*>(_Dst - 4)] = 0;
                            }
                        }

                        iVar4loop = iStack_14;
                        if (*reinterpret_cast<int32_t*>(_Dst - 4) != 0) {
                            DAT_0085a11c = 0x43;
                            FUN_004b06c0(_Dst, iStack_14, local_20, 0x43, 0xffffffff, 1,
                                         0xffffffff, 0);
                            iStack_14 = static_cast<int32_t>(
                                static_cast<int64_t>(
                                    DAT_008cac18 * 0x43 +
                                    ((DAT_008cac18 * 0x43) >> 0x1f & 0x3ffU)) >>
                                10);
                            DAT_0085a11c = 0x43;
                            DAT_008c9de0 = DAT_008c9dd8;
                            FUN_00509500(DAT_008c9dd8, _Dst, 0);
                            iStack_14 = static_cast<int32_t>(FUN_005f0ddc());
                            iStack_14 = iVar4loop + iStack_14;
                            if (*reinterpret_cast<int32_t*>(_Dst - 4) != 0) {
                                *_Dst = 0;
                                *reinterpret_cast<int32_t*>(_Dst - 4) = 0;
                            }
                        }
                        pcStack_24 = pcStack_1c;
                        cStack_29 = FUN_004c6e90(
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(base)),
                            &DAT_008cacd0, &pcStack_24, &pcStack_1c, &iStack_14,
                            &local_20);
                        char* found;
                        if ((static_cast<int32_t>(reinterpret_cast<intptr_t>(pcStack_24)) <
                             DAT_008caccc) &&
                            (static_cast<int32_t>(
                                 reinterpret_cast<intptr_t>(pcStack_24)) >= 0)) {
                            found = strchr(reinterpret_cast<char*>(
                                               reinterpret_cast<intptr_t>(pcStack_24) +
                                               0x8cacd0),
                                           0x3c);
                        } else {
                            found = nullptr;
                        }
                        if (found != nullptr) {
                            pcStack_1c = reinterpret_cast<char*>(
                                reinterpret_cast<intptr_t>(found) - 0x8cacd0);
                        } else {
                            pcStack_1c =
                                reinterpret_cast<char*>(static_cast<intptr_t>(-1));
                        }
                    }

                    FUN_004f1840();
                    puVar5 = puStack_8;
                    size_t sVar2b = *reinterpret_cast<size_t*>(puStack_8 - 4);
                    if ((static_cast<int32_t>(sVar2b) >= 0) && (puStack_8 != _Dst)) {
                        if (sVar2b == 0) {
                            if (*reinterpret_cast<int32_t*>(_Dst - 4) != 0) {
                                *_Dst = 0;
                                *reinterpret_cast<int32_t*>(_Dst - 4) = 0;
                            }
                        } else {
                            if (static_cast<int32_t>(sVar2b) > 0) {
                                if (*reinterpret_cast<int32_t*>(_Dst - 8) <
                                    static_cast<int32_t>(sVar2b)) {
                                    FUN_004f32e0();
                                    _Dst = local_18;
                                }
                                *reinterpret_cast<size_t*>(_Dst - 4) = sVar2b;
                            }
                            memmove(_Dst, puVar5, sVar2b);
                            _Dst[*reinterpret_cast<int32_t*>(_Dst - 4)] = 0;
                        }
                    }
                    uint8_t* del = puVar5 - 8;
                    if (del != nullptr && del != &DAT_008cacc8) {
                        operator_delete__(del);
                    }
                    puStack_8 = &DAT_008cacd0;

                    if (*reinterpret_cast<int32_t*>(_Dst - 4) != 0) {
                        DAT_0085a11c = 0x43;
                        FUN_004b06c0(_Dst, iStack_14, local_20, 0x43, 0xffffffff, 1,
                                     0xffffffff, 0);
                        DAT_0085a11c = 0x43;
                        DAT_008c9de0 = DAT_008c9dd8;
                        FUN_00509500(DAT_008c9dd8, _Dst, 0);
                        if (*reinterpret_cast<int32_t*>(_Dst - 4) != 0) {
                            *_Dst = 0;
                            *reinterpret_cast<int32_t*>(_Dst - 4) = 0;
                        }
                    }
                }

                int32_t step = static_cast<int32_t>(FUN_005f0ddc());
                local_20 = local_20 + step;
                float fVar13 = static_cast<float>(static_cast<int32_t>(
                    reinterpret_cast<intptr_t>(puStack_c)) + 1);
                puStack_c = reinterpret_cast<uint8_t*>(
                    static_cast<intptr_t>(fVar13));
                int32_t iVar4break = static_cast<int32_t>(FUN_005f0ddc());
                if (static_cast<int32_t>(reinterpret_cast<intptr_t>(puStack_c)) >=
                    (static_cast<int32_t>(static_cast<int64_t>(0x26c) / iVar4break) / 2 +
                     static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar5)))) {
                    break;
                }
                puVar5 = puStack_c;
            }
        }
    }

    iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(*reinterpret_cast<void**>(
        base + 0xd34)));
    *reinterpret_cast<uint32_t*>(base + 0xe6c) = 0;
    if (iVar4 != 0) {
        if (*reinterpret_cast<int32_t*>(base + 0xd38) == 1) {
            int32_t iVar4dialog = *reinterpret_cast<int32_t*>(base + 0xd68);
            int32_t iVar6 = 0;
            int32_t iVar11 = -1;
            if (iVar4dialog != -1) {
                if ((DAT_008ed61c & 1) == 0) {
                    DAT_008ed61c = DAT_008ed61c | 1;
                    DAT_008ed618 = static_cast<int32_t>(timeGetTime());
                }
                DWORD DVar7 = timeGetTime();
                iVar6 = static_cast<int32_t>(DVar7) -
                        *reinterpret_cast<int32_t*>(base + 0xd6c) - DAT_008ed618;
                iVar11 = iVar4dialog;
            }
            uint32_t uVar8 = FUN_005f0ddc(iVar11, iVar6);
            int32_t iVar4off = param_1i + 0xd80;
            int32_t iVar9 = static_cast<int32_t>(FUN_005f0ddc(iVar4off, uVar8));
            int32_t iVar12 = (*reinterpret_cast<int32_t*>(base + 0xd54) - iVar9) +
                             *reinterpret_cast<int32_t*>(base + 0xd40);
            uint32_t uVar10 = FUN_005f0ddc(iVar12);
            iVar9 = static_cast<int32_t>(FUN_005f0ddc(uVar10));
            FUN_004bbc80((*reinterpret_cast<int32_t*>(base + 0xd50) - iVar9) +
                             *reinterpret_cast<int32_t*>(base + 0xd3c),
                         uVar10, iVar12, iVar4off, uVar8, iVar11, iVar6);
        } else {
            int32_t iVar11 = static_cast<int32_t>(FUN_005f0ddc());
            float fVar13 = static_cast<float>(iVar11);
            fStack_4 = static_cast<float>(
                *reinterpret_cast<int32_t*>(base + 0xd40) + local_10);
            uint32_t uVar15 = 0;
            puStack_c = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(fVar13));
            uint32_t uVar8 = FUN_005f0ddc(fVar13, 0);
            uint32_t uVar10 = FUN_005f0ddc(uVar8);
            FUN_004bba60(iVar4, uVar10, uVar8,
                         static_cast<uint32_t>(static_cast<int32_t>(fVar13)), uVar15);
        }
    }

    iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(
        *reinterpret_cast<void**>(base + 0xdec)));
    if (iVar4 != 0) {
        uint32_t uVar16 = 0;
        uint32_t uVar15 = 0x42c80000;
        uint32_t uVar8 = FUN_005f0ddc(0x42c80000, 0);
        uint32_t uVar10 = FUN_005f0ddc(uVar8);
        FUN_004bba60(iVar4, uVar10, uVar8, uVar15, uVar16);
    }

    uint8_t* puVar5b = *reinterpret_cast<uint8_t**>(base + 0xdc8);
    size_t sVar2c = *reinterpret_cast<size_t*>(puVar5b - 4);
    uint8_t* puVar14 = &DAT_008cacd0;
    puStack_c = &DAT_008cacd0;
    if ((static_cast<int32_t>(sVar2c) >= 0) && (puVar5b != nullptr) &&
        (puVar5b != &DAT_008cacd0)) {
        if (sVar2c == 0) {
            if (DAT_008caccc != 0) {
                DAT_008cacd0 = 0;
                DAT_008caccc = 0;
            }
        } else {
            if (static_cast<int32_t>(sVar2c) > 0) {
                if (DAT_008cacc8 < static_cast<int32_t>(sVar2c)) {
                    FUN_004f32e0();
                }
                *reinterpret_cast<size_t*>(puStack_c - 4) = sVar2c;
            }
            puVar14 = puStack_c;
            memmove(puVar14, puVar5b, sVar2c);
            puVar14[*reinterpret_cast<int32_t*>(puVar14 - 4)] = 0;
        }
    }
    FUN_004ccf60();
    FUN_004b06c0(puVar14, 0x140, 0xc, 100, 0xffffffff, 4, 0xffffffff, 0);
    FUN_004c4640();

    uint8_t* del = puVar14 - 8;
    if (del != nullptr && del != &DAT_008cacc8) {
        operator_delete__(del);
    }
    del = _Dst - 8;
    if (del != nullptr && del != &DAT_008cacc8) {
        operator_delete__(del);
    }
}

// ---------------------------------------------------------------------------
// 0x4c6950 — observed shape
// Constructor tail: runs the setup probe FUN_004c73d0; on result 2 adopts the
// EAX/ECX pair through FUN_004c7520, on result 1 adopts the local string
// through FUN_004c78b0 and marks the receiver with 0xffffcc00, then bumps the
// +0xe6c counter and invokes FUN_004ccb10.
// ---------------------------------------------------------------------------
void FUN_004c6950(void* self_in_EAX, void* self_in_ESI)
{
    uint8_t* unaff_ESI = reinterpret_cast<uint8_t*>(self_in_ESI);
    uint32_t* in_EAX = reinterpret_cast<uint32_t*>(self_in_EAX);
    uint8_t* local_4 = &DAT_008cacd0;
    uint32_t extraout_ECX = 0;
    uint32_t extraout_var = 0;

    FUN_00412df0();
    int32_t iVar1 = static_cast<int32_t>(FUN_004c73d0(extraout_var));
    if (iVar1 == 2) {
        uint32_t uVar3 = extraout_ECX;
        FUN_00412df0();
        FUN_004c7520(uVar3, in_EAX);
    } else if (iVar1 == 1) {
        uint8_t** ppuVar4 = &local_4;
        uint32_t uVar3 = extraout_ECX;
        FUN_00412df0();
        FUN_004c78b0(uVar3, ppuVar4);
        *in_EAX = 0xffffcc00;
    }
    *reinterpret_cast<int32_t*>(unaff_ESI + 0xe6c) =
        *reinterpret_cast<int32_t*>(unaff_ESI + 0xe6c) + 1;
    FUN_004ccb10();
    release_shifted_buffer(local_4);
}
