#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals observed in the supplied corpus listings.
// Every global below is a refcounted object pointer whose second dword is the
// reference count; the destructor sits in vtable slot 0 and is invoked with the
// deletion flag 1.
// ---------------------------------------------------------------------------
extern void operator_delete__(void* ptr);

extern uint32_t* DAT_00726bc8;
extern uint32_t* DAT_00726bd4;
extern uint32_t* DAT_00726be0;
extern uint32_t* DAT_008ea064;
extern uint32_t* DAT_008ea068;
extern uint32_t* DAT_008ea06c;
extern uint32_t* DAT_008ea08c;
extern uint32_t* DAT_008ea090;
extern uint32_t* DAT_008ea524;
extern uint32_t* DAT_008ea52c;

// Owned-block pointers that are reset to the empty sentinel by their dtors.
extern uint8_t*  PTR_DAT_00726c04;
extern uint8_t*  PTR_DAT_00726c08;
extern uint8_t*  PTR_DAT_00726c0c;
extern uint8_t*  PTR_DAT_00726c10;
extern uint8_t*  PTR_DAT_00726c14;
extern uint8_t*  PTR_DAT_00726c20;
extern uintptr_t DAT_008ea528;

// Static sentinel blocks: 0x008cacd0 is the empty representation,
// 0x008cacc8 guards the small-block singleton that must not be freed.
extern uint8_t DAT_008cacd0;
extern uint8_t DAT_008cacc8;

// TLS teardown state.
extern void*    PTR_PTR_00726c24;
extern uint8_t  PTR_FUN_007109ac;
extern uint32_t DAT_00726c28;

// ---------------------------------------------------------------------------
// Shared refcount release, exactly the shape repeated by the listings:
//   piVar1 = puVar2 + 1;  *piVar1 += -1;  if (*piVar1 == 0) (**(*puVar2))(1);
// ---------------------------------------------------------------------------
static void release_refcounted(uint32_t* obj)
{
    int32_t* refs = reinterpret_cast<int32_t*>(obj + 1);
    *refs = *refs - 1;
    if (*refs == 0) {
        using Destructor = void (*)(uint32_t*, int);
        Destructor dtor = *reinterpret_cast<Destructor*>(
            reinterpret_cast<void*>(*obj));
        dtor(obj, 1);
    }
}

// 0x6bf470 — observed shape: walk the two-entry, 12-byte-stride table ending at
// 0x008ea064 downwards and release the object pointer held by each entry.
void FUN_006bf470(void)
{
    uint32_t* slot = reinterpret_cast<uint32_t*>(&DAT_008ea064);
    for (int i = 2; i != 0; --i) {
        slot = slot - 3;                       // three dwords per entry
        uint32_t* obj = reinterpret_cast<uint32_t*>(*slot);
        if (obj != nullptr) {
            release_refcounted(obj);
        }
    }
}

// 0x6bf4a0 — observed shape: release the global object at 0x00726bc8.
void FUN_006bf4a0(void)
{
    if (DAT_00726bc8 != nullptr) {
        release_refcounted(DAT_00726bc8);
    }
}

// 0x6bf4c0 — observed shape: release the global object at 0x00726bd4.
void FUN_006bf4c0(void)
{
    if (DAT_00726bd4 != nullptr) {
        release_refcounted(DAT_00726bd4);
    }
}

// 0x6bf4e0 — observed shape: release the global object at 0x00726be0.
void FUN_006bf4e0(void)
{
    if (DAT_00726be0 != nullptr) {
        release_refcounted(DAT_00726be0);
    }
}

// 0x6bf500 — observed shape: release the global object at 0x008ea064.
void FUN_006bf500(void)
{
    if (DAT_008ea064 != nullptr) {
        release_refcounted(DAT_008ea064);
    }
}

// 0x6bf520 — observed shape: release the global object at 0x008ea068.
void FUN_006bf520(void)
{
    if (DAT_008ea068 != nullptr) {
        release_refcounted(DAT_008ea068);
    }
}

// 0x6bf540 — observed shape: release the global object at 0x008ea06c.
void FUN_006bf540(void)
{
    if (DAT_008ea06c != nullptr) {
        release_refcounted(DAT_008ea06c);
    }
}

// 0x6bf560 — observed shape: free the block eight bytes before the current
// pointer unless it is the static 0x008cacc8 sentinel, then reset the global to
// the empty representation at 0x008cacd0.
void FUN_006bf560(void)
{
    uint8_t* owned = PTR_DAT_00726c04 - 8;
    if (owned != nullptr && owned != &DAT_008cacc8) {
        operator_delete__(owned);
    }
    PTR_DAT_00726c04 = &DAT_008cacd0;
}

// 0x6bf590 — observed shape: free the block eight bytes before the current
// pointer unless it is the static 0x008cacc8 sentinel, then reset the global to
// the empty representation at 0x008cacd0.
void FUN_006bf590(void)
{
    uint8_t* owned = PTR_DAT_00726c08 - 8;
    if (owned != nullptr && owned != &DAT_008cacc8) {
        operator_delete__(owned);
    }
    PTR_DAT_00726c08 = &DAT_008cacd0;
}

// 0x6bf5c0 — observed shape: free the block eight bytes before the current
// pointer unless it is the static 0x008cacc8 sentinel, then reset the global to
// the empty representation at 0x008cacd0.
void FUN_006bf5c0(void)
{
    uint8_t* owned = PTR_DAT_00726c0c - 8;
    if (owned != nullptr && owned != &DAT_008cacc8) {
        operator_delete__(owned);
    }
    PTR_DAT_00726c0c = &DAT_008cacd0;
}

// 0x6bf5f0 — observed shape: free the block eight bytes before the current
// pointer unless it is the static 0x008cacc8 sentinel, then reset the global to
// the empty representation at 0x008cacd0.
void FUN_006bf5f0(void)
{
    uint8_t* owned = PTR_DAT_00726c10 - 8;
    if (owned != nullptr && owned != &DAT_008cacc8) {
        operator_delete__(owned);
    }
    PTR_DAT_00726c10 = &DAT_008cacd0;
}

// 0x6bf620 — observed shape: free the block eight bytes before the current
// pointer unless it is the static 0x008cacc8 sentinel, then reset the global to
// the empty representation at 0x008cacd0.
void FUN_006bf620(void)
{
    uint8_t* owned = PTR_DAT_00726c14 - 8;
    if (owned != nullptr && owned != &DAT_008cacc8) {
        operator_delete__(owned);
    }
    PTR_DAT_00726c14 = &DAT_008cacd0;
}

// 0x6bf670 — observed shape: free the block eight bytes before the current
// pointer unless it is the static 0x008cacc8 sentinel, then reset the global to
// the empty representation at 0x008cacd0.
void FUN_006bf670(void)
{
    uint8_t* owned = PTR_DAT_00726c20 - 8;
    if (owned != nullptr && owned != &DAT_008cacc8) {
        operator_delete__(owned);
    }
    PTR_DAT_00726c20 = &DAT_008cacd0;
}

// 0x6bf6a0 — observed shape: reinstall the TLS callback table pointer at
// 0x007109ac and free the TLS slot index when it is not -1.
void FUN_006bf6a0(void)
{
    PTR_PTR_00726c24 = &PTR_FUN_007109ac;
    if (DAT_00726c28 != 0xffffffffu) {
        TlsFree(static_cast<DWORD>(DAT_00726c28));
    }
}

// 0x6bf6f0 — observed shape: release the global object at 0x008ea08c.
void FUN_006bf6f0(void)
{
    if (DAT_008ea08c != nullptr) {
        release_refcounted(DAT_008ea08c);
    }
}

// 0x6bf710 — observed shape: release the global object at 0x008ea090.
void FUN_006bf710(void)
{
    if (DAT_008ea090 != nullptr) {
        release_refcounted(DAT_008ea090);
    }
}

// 0x6bf750 — observed shape: walk the 0x100 contiguous object-pointer slots
// descending from 0x008ea50c and release each non-null object.
void FUN_006bf750(void)
{
    uint8_t* slot = reinterpret_cast<uint8_t*>(&DAT_008ea510);
    for (int i = 0x100; i != 0; --i) {
        slot = slot - 4;
        uint32_t* obj = *reinterpret_cast<uint32_t**>(slot);
        if (obj != nullptr) {
            release_refcounted(obj);
        }
    }
}

// 0x6bf7c0 — observed shape: release the global object at 0x008ea524.
void FUN_006bf7c0(void)
{
    if (DAT_008ea524 != nullptr) {
        release_refcounted(DAT_008ea524);
    }
}

// 0x6bf7e0 — observed shape: free the block eight bytes before the raw pointer
// stored at 0x008ea528 unless it is the static 0x008cacc8 sentinel, then store
// the empty representation at 0x008cacd0.
void FUN_006bf7e0(void)
{
    uint8_t* owned = reinterpret_cast<uint8_t*>(DAT_008ea528 - 8);
    if (owned != nullptr && owned != &DAT_008cacc8) {
        operator_delete__(owned);
    }
    DAT_008ea528 = reinterpret_cast<uintptr_t>(&DAT_008cacd0);
}

// 0x6bf810 — observed shape: release the global object at 0x008ea52c.
void FUN_006bf810(void)
{
    if (DAT_008ea52c != nullptr) {
        release_refcounted(DAT_008ea52c);
    }
}
