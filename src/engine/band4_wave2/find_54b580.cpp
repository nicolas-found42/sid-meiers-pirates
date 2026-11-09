// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b580: linear probe of a bucket table +0x0c-count iterator; removes
// entry at index +0x58, splices the chain (+0x08/+0x0c links), pushes to
// freelist +0x44, returns head value.
// Corpus: analysis/pseudocode/functions/0x54b580.c
#include <stddef.h>
#include <stdint.h>

struct Entry {
    uint32_t w_00;
    uint32_t w_04;
    void*    next_08;
    void*    aux_0c;
    uint32_t value_10;
};

struct Map54b580 {
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
    Entry**  buckets_38;
    uint32_t bucketCount_3c;
    uint32_t w_40;
    Entry*   freelist_44;
    uint32_t w_48;
    uint32_t w_4c;
    uint32_t w_50;
    uint32_t w_54;
    uint32_t index_58;
};

// 0x0054b580
uint32_t __thiscall FUN_0054b580(Map54b580* self)
{
    while (self->index_58 < self->bucketCount_3c) {
        Entry* e = self->buckets_38[self->index_58];
        if (e != nullptr) {
            if (e->aux_0c == nullptr) {
                self->buckets_38[self->index_58] = (Entry*)e->next_08;
                e->next_08 = self->freelist_44;
                self->freelist_44 = e;
                return e->value_10;
            }
            self->buckets_38[self->index_58] = (Entry*)e->aux_0c;
            Entry* aux = (Entry*)e->aux_0c;
            aux->next_08 = e->next_08;
            e->next_08 = self->freelist_44;
            self->freelist_44 = e;
            return e->value_10;
        }
        self->index_58 += 1;
    }
    return 0;
}
