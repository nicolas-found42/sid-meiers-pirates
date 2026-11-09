#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Shared shapes observed in this batch.
//
// Every listing in this batch works on intrusive reference-counted objects:
//   +0x00 vtable pointer (slot 0 is the scalar deleting destructor)
//   +0x04 reference count
// Release is: if (obj != null) { if (--obj->refcount == 0) obj->vtbl->dtor(obj, 1) }
// The provider spells that as `(**(code **)*obj)(1)`.
// ---------------------------------------------------------------------------
struct ReconVtbl
{
    void (*destroy)(void* self, int32_t flags);   // vtable slot 0
};

struct ReconRefCounted
{
    ReconVtbl* vtbl;      // +0x00
    int32_t    refcount;  // +0x04
};

static void recon_release(ReconRefCounted* obj)
{
    if (obj != nullptr) {
        if (--obj->refcount == 0) {
            obj->vtbl->destroy(obj, 1);
        }
    }
}

extern void operator_delete__(void* param_1);

extern void FUN_004e6420(void);
extern void FUN_004d4cb0(void);

// Reference-counted globals released one-by-one by the listings below.
extern ReconRefCounted* DAT_008e67a8;
extern ReconRefCounted* DAT_008e671c;

// Base addresses of the reference-counted arrays walked downward.
extern ReconRefCounted* DAT_008e6730;
extern ReconRefCounted* DAT_008e8fb0;
extern ReconRefCounted* DAT_008e8fd8;
extern ReconRefCounted* DAT_008e9ed8;
extern ReconRefCounted* DAT_008e9f58;

// Static empty-object sentinels used by the raw-block deallocators.
extern uint32_t DAT_008cacc8;   // sentinel "not owned" block start
extern uint8_t  DAT_008cacd0;   // sentinel value stored back into the slot
extern int32_t  DAT_008cacd4;

// ---------------------------------------------------------------------------
// 0x6beca0 — release one global reference-counted object.
// ---------------------------------------------------------------------------
// 0x6beca0 — observed shape
void FUN_6beca0(void)
{
    ReconRefCounted* puVar2 = DAT_008e67a8;

    if ((DAT_008e67a8 != nullptr) &&
        (puVar2->refcount = puVar2->refcount - 1, puVar2->refcount == 0)) {
        puVar2->vtbl->destroy(puVar2, 1);
    }
}

// ---------------------------------------------------------------------------
// 0x6becc0 — release 0x1e slots of the array ending at DAT_008e67a8.
// ---------------------------------------------------------------------------
// 0x6becc0 — observed shape
void FUN_6becc0(void)
{
    ReconRefCounted** puVar3 = &DAT_008e67a8;
    int32_t iVar4 = 0x1e;

    do {
        ReconRefCounted** current = puVar3 - 1;

        puVar3 = current;
        recon_release(*current);
        iVar4 = iVar4 - 1;
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6becf0 — release 4 slots of the array ending at DAT_008e6730.
// ---------------------------------------------------------------------------
// 0x6becf0 — observed shape
void FUN_6becf0(void)
{
    ReconRefCounted** puVar3 = &DAT_008e6730;
    int32_t iVar4 = 4;

    do {
        ReconRefCounted** current = puVar3 - 1;

        puVar3 = current;
        recon_release(*current);
        iVar4 = iVar4 - 1;
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6bed20 — release one global reference-counted object.
// ---------------------------------------------------------------------------
// 0x6bed20 — observed shape
void FUN_6bed20(void)
{
    ReconRefCounted* puVar2 = DAT_008e671c;

    if ((DAT_008e671c != nullptr) &&
        (puVar2->refcount = puVar2->refcount - 1, puVar2->refcount == 0)) {
        puVar2->vtbl->destroy(puVar2, 1);
    }
}

// ---------------------------------------------------------------------------
// 0x6bed70 — release 10 slots of the array ending at DAT_008e8fb0.
// ---------------------------------------------------------------------------
// 0x6bed70 — observed shape
void FUN_6bed70(void)
{
    ReconRefCounted** puVar3 = &DAT_008e8fb0;
    int32_t iVar4 = 10;

    do {
        ReconRefCounted** current = puVar3 - 1;

        puVar3 = current;
        recon_release(*current);
        iVar4 = iVar4 - 1;
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6bedc0 / 0x6bedf0 / 0x6bf0a0 — reset one PTR container slot back to the
// static sentinel, deallocating the owning block that starts 8 bytes before
// the stored pointer. The block is skipped when null or already the sentinel.
// ---------------------------------------------------------------------------
extern uint8_t* PTR_DAT_00726a88;
extern uint8_t* PTR_DAT_00726a8c;
extern uint8_t* PTR_DAT_00726b30;

// 0x6bedc0 — observed shape
void FUN_6bedc0(void)
{
    void* puVar1 = reinterpret_cast<void*>(reinterpret_cast<intptr_t>(PTR_DAT_00726a88) - 8);

    if ((puVar1 != nullptr) && (puVar1 != static_cast<void*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    PTR_DAT_00726a88 = &DAT_008cacd0;
}

// 0x6bedf0 — observed shape
void FUN_6bedf0(void)
{
    void* puVar1 = reinterpret_cast<void*>(reinterpret_cast<intptr_t>(PTR_DAT_00726a8c) - 8);

    if ((puVar1 != nullptr) && (puVar1 != static_cast<void*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    PTR_DAT_00726a8c = &DAT_008cacd0;
}

// ---------------------------------------------------------------------------
// 0x6bee20 .. 0x6beea0 — release one global reference-counted object
// (consecutive slots of the array released by 0x6bed70).
// ---------------------------------------------------------------------------
extern ReconRefCounted* DAT_008e8fb4;
extern ReconRefCounted* DAT_008e8fb8;
extern ReconRefCounted* DAT_008e8fbc;
extern ReconRefCounted* DAT_008e8fc0;
extern ReconRefCounted* DAT_008e8fe0;

// 0x6bee20 — observed shape
void FUN_6bee20(void)
{
    ReconRefCounted* puVar2 = DAT_008e8fb0;

    if ((DAT_008e8fb0 != nullptr) &&
        (puVar2->refcount = puVar2->refcount - 1, puVar2->refcount == 0)) {
        puVar2->vtbl->destroy(puVar2, 1);
    }
}

// 0x6bee40 — observed shape
void FUN_6bee40(void)
{
    ReconRefCounted* puVar2 = DAT_008e8fb4;

    if ((DAT_008e8fb4 != nullptr) &&
        (puVar2->refcount = puVar2->refcount - 1, puVar2->refcount == 0)) {
        puVar2->vtbl->destroy(puVar2, 1);
    }
}

// 0x6bee60 — observed shape
void FUN_6bee60(void)
{
    ReconRefCounted* puVar2 = DAT_008e8fb8;

    if ((DAT_008e8fb8 != nullptr) &&
        (puVar2->refcount = puVar2->refcount - 1, puVar2->refcount == 0)) {
        puVar2->vtbl->destroy(puVar2, 1);
    }
}

// 0x6bee80 — observed shape
void FUN_6bee80(void)
{
    ReconRefCounted* puVar2 = DAT_008e8fbc;

    if ((DAT_008e8fbc != nullptr) &&
        (puVar2->refcount = puVar2->refcount - 1, puVar2->refcount == 0)) {
        puVar2->vtbl->destroy(puVar2, 1);
    }
}

// 0x6beea0 — observed shape
void FUN_6beea0(void)
{
    ReconRefCounted* puVar2 = DAT_008e8fc0;

    if ((DAT_008e8fc0 != nullptr) &&
        (puVar2->refcount = puVar2->refcount - 1, puVar2->refcount == 0)) {
        puVar2->vtbl->destroy(puVar2, 1);
    }
}

// ---------------------------------------------------------------------------
// 0x6beec0 — walk 5 PTR slots downward from DAT_008e8fd8: free each owning
// block (pointer - 8, unless null/sentinel) and then reset the slot to the
// static sentinel. The reset store happens at the end of each iteration.
// ---------------------------------------------------------------------------
// 0x6beec0 — observed shape
void FUN_6beec0(void)
{
    uint8_t** puVar3 = reinterpret_cast<uint8_t**>(&DAT_008e8fd8);
    int32_t iVar4 = 5;

    do {
        uint8_t** piVar1 = puVar3 - 1;
        void* puVar2;

        puVar3 = piVar1;
        puVar2 = reinterpret_cast<void*>(reinterpret_cast<intptr_t>(*piVar1) - 8);
        if ((puVar2 != nullptr) && (puVar2 != static_cast<void*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
        }
        iVar4 = iVar4 - 1;
        *puVar3 = &DAT_008cacd0;
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6bef40 — install two successive vtables on the same object, tearing down
// each previous subobject in between, then delete the owned payload pointer.
// ---------------------------------------------------------------------------
extern void* PTR_PTR_00726ad8;
extern uint8_t PTR_FUN_0070d000;
extern uint8_t PTR_FUN_0070d04c;
extern void* DAT_00726ae0;

// 0x6bef40 — observed shape
void FUN_6bef40(void)
{
    PTR_PTR_00726ad8 = static_cast<void*>(&PTR_FUN_0070d000);
    FUN_004e6420();
    PTR_PTR_00726ad8 = static_cast<void*>(&PTR_FUN_0070d04c);
    FUN_004e6420();
    operator_delete__(DAT_00726ae0);
}

// ---------------------------------------------------------------------------
// 0x6befb0 — release one global reference-counted object.
// ---------------------------------------------------------------------------
// 0x6befb0 — observed shape
void FUN_6befb0(void)
{
    ReconRefCounted* puVar2 = DAT_008e8fe0;

    if ((DAT_008e8fe0 != nullptr) &&
        (puVar2->refcount = puVar2->refcount - 1, puVar2->refcount == 0)) {
        puVar2->vtbl->destroy(puVar2, 1);
    }
}

// ---------------------------------------------------------------------------
// 0x6befe0 / 0x6bf020 — walk 0x20 PTR slots downward from the given base:
// free each owning block (pointer - 8, unless null/sentinel) and reset the
// slot to the static sentinel at the end of the iteration.
// ---------------------------------------------------------------------------
// 0x6befe0 — observed shape
void FUN_6befe0(void)
{
    uint8_t** puVar3 = reinterpret_cast<uint8_t**>(&DAT_008e9ed8);
    int32_t iVar4 = 0x20;

    do {
        uint8_t** piVar1 = puVar3 - 1;
        void* puVar2;

        puVar3 = piVar1;
        puVar2 = reinterpret_cast<void*>(reinterpret_cast<intptr_t>(*piVar1) - 8);
        if ((puVar2 != nullptr) && (puVar2 != static_cast<void*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
        }
        iVar4 = iVar4 - 1;
        *puVar3 = &DAT_008cacd0;
    } while (iVar4 != 0);
}

// 0x6bf020 — observed shape
void FUN_6bf020(void)
{
    uint8_t** puVar3 = reinterpret_cast<uint8_t**>(&DAT_008e9f58);
    int32_t iVar4 = 0x20;

    do {
        uint8_t** piVar1 = puVar3 - 1;
        void* puVar2;

        puVar3 = piVar1;
        puVar2 = reinterpret_cast<void*>(reinterpret_cast<intptr_t>(*piVar1) - 8);
        if ((puVar2 != nullptr) && (puVar2 != static_cast<void*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
        }
        iVar4 = iVar4 - 1;
        *puVar3 = &DAT_008cacd0;
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6bf070 — install a vtable, invoke virtual slot at vtable+0xc, then invoke
// slot 0 with flag 1 and clear the global owner pointer.
// ---------------------------------------------------------------------------
extern void* PTR_PTR_00726b10;
extern uint8_t PTR_FUN_00710a38;
extern ReconRefCounted* DAT_00726b14;

// 0x6bf070 — observed shape
void FUN_6bf070(void)
{
    void (*method)(void*);

    PTR_PTR_00726b10 = static_cast<void*>(&PTR_FUN_00710a38);
    method = *reinterpret_cast<void (**)(void*)>(
        reinterpret_cast<uint8_t*>(DAT_00726b14->vtbl) + 0xc);
    method(DAT_00726b14);
    if (DAT_00726b14 != nullptr) {
        DAT_00726b14->vtbl->destroy(DAT_00726b14, 1);
        DAT_00726b14 = nullptr;
    }
}

// ---------------------------------------------------------------------------
// 0x6bf0a0 — reset the PTR container slot to the static sentinel, deleting
// the owning block that starts 8 bytes before the stored pointer.
// ---------------------------------------------------------------------------
// 0x6bf0a0 — observed shape
void FUN_6bf0a0(void)
{
    void* puVar1 = reinterpret_cast<void*>(reinterpret_cast<intptr_t>(PTR_DAT_00726b30) - 8);

    if ((puVar1 != nullptr) && (puVar1 != static_cast<void*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    PTR_DAT_00726b30 = &DAT_008cacd0;
}

// ---------------------------------------------------------------------------
// 0x6bf0d0 — install a vtable, then (once only) tear the window down: the
// one-shot flag guards DestroyWindow + PostQuitMessage; then clear the state
// word and run the remaining global cleanup.
// ---------------------------------------------------------------------------
extern void* PTR_PTR_00726b38;
extern uint8_t PTR_FUN_0070de80;
extern char DAT_00726b3d;    // one-shot shutdown flag
extern HWND DAT_00726b8c;

// 0x6bf0d0 — observed shape
void FUN_6bf0d0(void)
{
    PTR_PTR_00726b38 = static_cast<void*>(&PTR_FUN_0070de80);
    if (DAT_00726b3d == '\0') {
        DAT_00726b3d = '\x01';
        DestroyWindow(DAT_00726b8c);
        PostQuitMessage(0);
    }
    DAT_008cacd4 = 0;
    FUN_004d4cb0();
}
