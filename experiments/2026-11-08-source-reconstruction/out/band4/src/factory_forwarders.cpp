// Band4 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Record-allocator factory + its two this-injecting forwarders. Corpus:
// analysis/pseudocode/functions/0x591300.c, 0x591380.c, 0x5913a0.c;
// deep dossier analysis/team/band4/deep/0x00591380.md (REA ev_71d5b4d4... etc.)
#include <stddef.h>

extern void* __cdecl FUN_00533c78(int nbytes);
extern void  __cdecl FUN_005606f0(unsigned index, void** slot);
extern void  __cdecl FUN_006b34a0(void* growTarget);
extern void  __cdecl FUN_00595000(void* a, int b); // observed pre-call

// 0x18-byte record: [0]=0 (byte), [4]=2 (refcount seed), [8..]=payload.
struct Record_591300 {
    unsigned char flag_00;
    unsigned char pad_01[3];
    int           refcnt_04;
    void*         f_08;
    void*         f_0c;
    void*         f_10;
    void*         f_14;
};

struct AppendArray {
    void*     pad[2];       // +0x00, +0x04
    unsigned  capacity_08;  // +0x08  (observed compare against index)
    unsigned  count_0c;     // +0x0c  (observed index source)
    void*     pad2;         // +0x10
    void*     base_14;      // +0x14  (grow target base)
};

// 0x00591300 — allocate a record, seed it, append to `array`.
// Note: stores at [8] and [0xc] are both param_1 (duplicated store as
// observed); [0x10] = param_4, [0x14] = param_5; [0]=0, [4]=2.
void __thiscall FUN_00591300(void* param_1, AppendArray* array,
                              unsigned char flag, void* param_4, void* param_5)
{
    if (flag != 0) {
        FUN_00595000(param_1, 0);
    }
    Record_591300* rec = (Record_591300*)FUN_00533c78(0x18);
    if (rec != NULL) {
        rec->f_08 = param_1;
        rec->f_0c = param_1;
        rec->f_10 = param_4;
        rec->f_14 = param_5;
        rec->flag_00 = 0;
        rec->refcnt_04 = 2;
    }
    unsigned index = array->count_0c;
    if (array->capacity_08 <= index) {
        FUN_006b34a0((char*)array->base_14 + index);
    }
    FUN_005606f0(index, (void**)&rec);
}

// 0x00591380 — forwarder: inject `this` as the callee's second argument.
// Evidence: REA ev_71d5b4d4b9569f55efa5aab16442f64706ec72c89335f91de56872c6fdedf9e0.
void __thiscall FUN_00591380(void* self, void* a1, void* a2, void* a3, void* a4)
{
    FUN_00591300(a1, (AppendArray*)self, (unsigned char)a2, a3, a4);
}

// 0x005913a0 — sibling forwarder: injects `this+0x18` instead.
void __thiscall FUN_005913a0(void* self, void* a1, void* a2, void* a3, void* a4)
{
    FUN_00591300(a1, (AppendArray*)((char*)self + 0x18), (unsigned char)a2, a3, a4);
}
