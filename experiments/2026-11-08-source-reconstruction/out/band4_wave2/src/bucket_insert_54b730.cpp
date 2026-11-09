// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b730: insert param_1 (obj ref at +0xb4) into bucket table keyed by
// key at (**(peer+0x2c))+4; bucket = key % count(+0x3c); allocates pool from
// freelist +0x44 (+0x40 chunks, linked +0x08), token array +0x48; node links
// +0x00/+0x04/+0x08/+0x0c.
// Corpus: analysis/pseudocode/functions/0x54b730.c
#include <stddef.h>
#include <stdint.h>

extern void* __cdecl thunk_FUN_00533c78(int nbytes);

struct Node {
    void*    obj_00;
    uint32_t key_04;
    void*    next_08;
    void*    aux_0c;
};

struct Map54b730 {
    uint32_t w_00;
    uint32_t w_04;
    uint32_t w_08;
    uint32_t w_0c;
    uint32_t w_10;
    uint32_t w_14;
    uint32_t w_18;
    uint32_t w_1c;
    uint32_t w_20;
    uint32_t w_24;
    uint32_t w_28;
    uint32_t w_2c;
    uint32_t w_30;
    uint32_t w_34;
    Node**   buckets_38;
    uint32_t bucketCount_3c;
    uint32_t poolSize_40;
    Node*    freelist_44;
    void*    poolFn_48;
    void*    tokHead_4c;
    void*    tokTail_50;
    uint32_t tokCount_54;
    uint32_t index_58;
};

// 0x0054b730
void __thiscall FUN_0054b730(Map54b730* self, void* param_1)
{
    void* peer = *(void**)((uint8_t*)param_1 + 0xb4);
    if (peer != nullptr) {
        ((uint32_t*)peer)[1] += 1; // +4
    }
    uint32_t key = 0;
    void* inner = *(void**)((uint8_t*)peer + 0x2c * 0); // placeholder, refined below
    // observed: **(peer[10] + 0x2c) then +4
    void* slot = *(void**)((uint8_t*)peer + 0x28 + 0x2c); // +0x54 == index 0x15*4... kept symbolic
    (void)inner; (void)slot;
    {
        uint8_t* p = (uint8_t*)peer;
        void* p10 = *(void**)(p + 10 * 4); // peer[10]
        void* q = *(void**)((uint8_t*)p10 + 0x2c);
        if (q != nullptr) {
            key = *(uint32_t*)((uint8_t*)q + 4);
        }
    }
    if (peer != nullptr && ((uint32_t*)peer)[1] == 0) {
        typedef void (__cdecl *VCall)(void*, int);
        VCall v = *(VCall*)peer;
        v(peer, 1);
    }
    // NOTE: refcount decrement ordering is approximate; observed releases
    // the temporary at pseudocode *piVar1--.
    uint32_t bucket = self->bucketCount_3c ? (key % self->bucketCount_3c) : 0;
    if (self->freelist_44 == nullptr) {
        void* pool = thunk_FUN_00533c78((int)(self->poolSize_40 << 4));
        self->freelist_44 = (Node*)pool;
        Node* tok = (Node*)((uint32_t(*)(void*))self->poolFn_48)(self->poolFn_48);
        tok->next_08 = self->freelist_44;
        tok->key_04 = 0;
        tok->obj_00 = self->tokHead_4c;
        if (self->tokHead_4c == nullptr) {
            self->tokTail_50 = tok;
        } else {
            *(void**)((uint8_t*)self->tokHead_4c + 4) = tok;
        }
        self->tokCount_54 += 1;
        self->tokHead_4c = tok;
        Node* cur = self->freelist_44;
        uint32_t n = 1;
        Node* prev = cur;
        if (1 < self->poolSize_40) {
            do {
                prev = (Node*)((uint8_t*)cur + 0x10);
                cur->next_08 = prev;
                n += 1;
                cur = prev;
            } while (n < self->poolSize_40);
        }
        cur->next_08 = nullptr;
        self->poolSize_40 <<= 1;
    }
    Node* node = self->freelist_44;
    self->index_58 = 0;
    self->freelist_44 = (Node*)node->next_08;
    node->obj_00 = param_1;
    node->key_04 = key;
    Node* bucketHead = self->buckets_38[bucket];
    Node* cur = bucketHead;
    while (true) {
        if (cur == nullptr) {
            node->next_08 = bucketHead;
            self->buckets_38[bucket] = node;
            node->aux_0c = nullptr;
            return;
        }
        if (cur->key_04 == key) {
            break;
        }
        cur = (Node*)cur->next_08;
    }
    node->aux_0c = cur->aux_0c;
    cur->aux_0c = node;
}
