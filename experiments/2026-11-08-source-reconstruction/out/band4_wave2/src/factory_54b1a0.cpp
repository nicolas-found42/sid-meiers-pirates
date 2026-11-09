// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b1a0: allocate 0x24-byte object, set vtable, clear fields, push-list,
// swap a refcounted peer pointer, validate against 0x727c30 via vcall +0x114.
// Corpus: analysis/pseudocode/functions/0x54b1a0.c
// Observed: FUN_00533c78(0x24) alloc, FUN_005383d0 init, vtable 0x6c1fc8,
// zero dwords at +0x0c,+0x10,+0x14,+0x18,+0x1c,+0x20 (indices 3..8),
// FUN_0054b030 push, peer at +0x14 (index 5); vcall (*0x727c30 + 0x114).
#include <stddef.h>
#include <stdint.h>

extern void* __cdecl FUN_00533c78(int nbytes);
extern void  __cdecl FUN_005383d0(void* self);
extern void  __thiscall FUN_0054b030(void* self);

extern void* g_vtable_6c1fc8;
extern void* g_validator_727c30;

struct Obj54b1a0 {
    void*    vtable_00;
    uint32_t w_04;
    uint32_t w_08;
    uint32_t w_0c;
    uint32_t w_10;
    void*    peer_14;
    uint32_t w_18;
    uint32_t w_1c;
    uint32_t w_20;
};

static void ReleasePeer(void* peer)
{
    if (peer != nullptr) {
        uint32_t* rc = (uint32_t*)peer + 1; // +4
        *rc -= 1;
        if (*rc == 0) {
            typedef void (__cdecl *VCall)(void*, int);
            VCall v = *(VCall*)peer;
            v(peer, 1);
        }
    }
}

// 0x0054b1a0
Obj54b1a0* __cdecl FUN_0054b1a0(void* peer)
{
    Obj54b1a0* obj = (Obj54b1a0*)FUN_00533c78(0x24);
    if (obj != nullptr) {
        FUN_005383d0(obj);
        obj->vtable_00 = &g_vtable_6c1fc8;
        obj->w_0c = 0;
        obj->w_10 = 0;
        obj->peer_14 = nullptr;
        obj->w_18 = 0;
        obj->w_1c = 0;
        obj->w_20 = 0;
        FUN_0054b030(obj);
    }
    if (obj->peer_14 != peer) {
        ReleasePeer(obj->peer_14);
        obj->peer_14 = peer;
        if (peer != nullptr) {
            ((uint32_t*)peer)[1] += 1; // +4
        }
    }
    if (g_validator_727c30 != nullptr) {
        typedef int (__cdecl *ValidateFn)(void*, Obj54b1a0*);
        void** vt = *(void***)g_validator_727c30;
        ValidateFn vf = (ValidateFn)vt[0x114 / 4]; // +0x114
        int ok = vf(g_validator_727c30, obj);
        if (ok == 0) {
            if (obj != nullptr) {
                typedef void (__cdecl *VCall)(Obj54b1a0*, int);
                VCall v = *(VCall*)obj;
                v(obj, 1);
            }
            return nullptr;
        }
    }
    return obj;
}
